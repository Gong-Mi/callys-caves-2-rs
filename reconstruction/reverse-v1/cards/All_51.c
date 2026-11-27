/* cally 逆向卡：All_51 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 119 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/119 F_D3DModelVertexNormalTextureColor(RValue&, CInstance*, CInstance*, int, RValue*)  0x145964  size 264  66 条（0x145964..0x145a6c）
 * @func 0x145964 0x145a6c  size 264  66 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×9 / YYGetInt32(RValue const*, int)×2 / GR_3DM_Vertex_N_Texture_Color(int, float, float, float, float, float, float, float, float, unsigned int, float)
 * 字段偏移 top8: 0x24×2 / 0x28×2 / 0x2c×2 / 0x58×1 / 0x4×1 / 0x8×1 / 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x145964 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x145968 sub sp, sp, #52
 *   @0x14596c mov r1, #0
 *   @0x145970 ldr r4, [sp, #0x58]
 *   @0x145974 mov r0, r4
 *   @0x145978 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14597c mov r1, #1
 *   @0x145980 mov r5, r0
 *   @0x145984 mov r0, r4
 *   @0x145988 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14598c mov r1, #2
 *   @0x145990 mov r8, r0
 *   @0x145994 mov r0, r4
 *   @0x145998 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14599c mov r1, #3
 *   @0x1459a0 mov r7, r0
 *   @0x1459a4 mov r0, r4
 *   @0x1459a8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1459ac mov r1, #4
 *   @0x1459b0 mov r6, r0
 *   @0x1459b4 mov r0, r4
 *   @0x1459b8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1459bc mov r1, #5
 *   @0x1459c0 mov r12, r0
 *   @0x1459c4 mov r0, r4
 *   @0x1459c8 str r12, [sp, #0x24]
 *   @0x1459cc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1459d0 mov r1, #6
 *   @0x1459d4 mov r2, r0
 *   @0x1459d8 mov r0, r4
 *   @0x1459dc str r2, [sp, #0x28]
 *   @0x1459e0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1459e4 mov r1, #7
 *   @0x1459e8 mov r3, r0
 *   @0x1459ec mov r0, r4
 *   @0x1459f0 str r3, [sp, #0x2c]
 *   @0x1459f4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1459f8 mov r1, #8
 *   @0x1459fc mov r11, r0
 *   @0x145a00 mov r0, r4
 *   @0x145a04 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145a08 mov r1, #9
 *   @0x145a0c mov r10, r0
 *   @0x145a10 mov r0, r4
 *   @0x145a14 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x145a18 mov r1, #10
 *   @0x145a1c mov r9, r0
 *   @0x145a20 mov r0, r4
 *   @0x145a24 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145a28 ldr r2, [sp, #0x28]
 *   @0x145a2c ldr r3, [sp, #0x2c]
 *   @0x145a30 mov r1, r8
 *   @0x145a34 ldr r12, [sp, #0x24]
 *   @0x145a38 str r2, [sp, #0x4]
 *   @0x145a3c mov r2, r7
 *   @0x145a40 str r3, [sp, #0x8]
 *   @0x145a44 mov r3, r6
 *   @0x145a48 str r12, [sp]
 *   @0x145a4c str r11, [sp, #0xc]
 *   @0x145a50 str r10, [sp, #0x10]
 *   @0x145a54 str r9, [sp, #0x14]
 *   @0x145a58 str r0, [sp, #0x18]
 *   @0x145a5c mov r0, r5
 *   @0x145a60 bl 0x165834 <_Z29GR_3DM_Vertex_N_Texture_Coloriffffffffjf>
 *   @0x145a64 add sp, sp, #52
 *   @0x145a68 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §2/119 F_D3DModelCylinder(RValue&, CInstance*, CInstance*, int, RValue*)  0x145b3c  size 264  66 条（0x145b3c..0x145c44）
 * @func 0x145b3c 0x145c58  size 284  71 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×8 / YYGetInt32(RValue const*, int)×2 / YYGetBool(RValue const*, int) / GR_3DM_Cylinder(int, float, float, float, float, float, float, float, float, bool, int)
 * 字段偏移 top8: 0x24×2 / 0x28×2 / 0x2c×2 / 0x58×1 / 0x4×1 / 0x8×1 / 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x145b3c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x145b40 sub sp, sp, #52
 *   @0x145b44 mov r1, #0
 *   @0x145b48 ldr r4, [sp, #0x58]
 *   @0x145b4c mov r0, r4
 *   @0x145b50 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x145b54 mov r1, #1
 *   @0x145b58 mov r5, r0
 *   @0x145b5c mov r0, r4
 *   @0x145b60 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145b64 mov r1, #2
 *   @0x145b68 mov r8, r0
 *   @0x145b6c mov r0, r4
 *   @0x145b70 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145b74 mov r1, #3
 *   @0x145b78 mov r7, r0
 *   @0x145b7c mov r0, r4
 *   @0x145b80 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145b84 mov r1, #4
 *   @0x145b88 mov r6, r0
 *   @0x145b8c mov r0, r4
 *   @0x145b90 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145b94 mov r1, #5
 *   @0x145b98 mov r12, r0
 *   @0x145b9c mov r0, r4
 *   @0x145ba0 str r12, [sp, #0x24]
 *   @0x145ba4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145ba8 mov r1, #6
 *   @0x145bac mov r2, r0
 *   @0x145bb0 mov r0, r4
 *   @0x145bb4 str r2, [sp, #0x28]
 *   @0x145bb8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145bbc mov r1, #7
 *   @0x145bc0 mov r3, r0
 *   @0x145bc4 mov r0, r4
 *   @0x145bc8 str r3, [sp, #0x2c]
 *   @0x145bcc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145bd0 mov r1, #8
 *   @0x145bd4 mov r11, r0
 *   @0x145bd8 mov r0, r4
 *   @0x145bdc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145be0 mov r1, #9
 *   @0x145be4 mov r10, r0
 *   @0x145be8 mov r0, r4
 *   @0x145bec bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x145bf0 mov r1, #10
 *   @0x145bf4 mov r9, r0
 *   @0x145bf8 mov r0, r4
 *   @0x145bfc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x145c00 ldr r2, [sp, #0x28]
 *   @0x145c04 ldr r3, [sp, #0x2c]
 *   @0x145c08 mov r1, r8
 *   @0x145c0c ldr r12, [sp, #0x24]
 *   @0x145c10 str r2, [sp, #0x4]
 *   @0x145c14 mov r2, r7
 *   @0x145c18 str r3, [sp, #0x8]
 *   @0x145c1c mov r3, r6
 *   @0x145c20 str r12, [sp]
 *   @0x145c24 str r11, [sp, #0xc]
 *   @0x145c28 str r10, [sp, #0x10]
 *   @0x145c2c str r9, [sp, #0x14]
 *   @0x145c30 str r0, [sp, #0x18]
 *   @0x145c34 mov r0, r5
 *   @0x145c38 bl 0x1659e4 <_Z15GR_3DM_Cylinderiffffffffbi>
 *   @0x145c3c add sp, sp, #52
 *   @0x145c40 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §3/119 F_D3DModelCone(RValue&, CInstance*, CInstance*, int, RValue*)  0x145c44  size 264  66 条（0x145c44..0x145d4c）
 * @func 0x145c44 0x145d4c  size 264  66 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×8 / YYGetInt32(RValue const*, int)×2 / YYGetBool(RValue const*, int) / GR_3DM_Cone(int, float, float, float, float, float, float, float, float, bool, int)
 * 字段偏移 top8: 0x24×2 / 0x28×2 / 0x2c×2 / 0x58×1 / 0x4×1 / 0x8×1 / 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x145c44 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x145c48 sub sp, sp, #52
 *   @0x145c4c mov r1, #0
 *   @0x145c50 ldr r4, [sp, #0x58]
 *   @0x145c54 mov r0, r4
 *   @0x145c58 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x145c5c mov r1, #1
 *   @0x145c60 mov r5, r0
 *   @0x145c64 mov r0, r4
 *   @0x145c68 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145c6c mov r1, #2
 *   @0x145c70 mov r8, r0
 *   @0x145c74 mov r0, r4
 *   @0x145c78 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145c7c mov r1, #3
 *   @0x145c80 mov r7, r0
 *   @0x145c84 mov r0, r4
 *   @0x145c88 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145c8c mov r1, #4
 *   @0x145c90 mov r6, r0
 *   @0x145c94 mov r0, r4
 *   @0x145c98 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145c9c mov r1, #5
 *   @0x145ca0 mov r12, r0
 *   @0x145ca4 mov r0, r4
 *   @0x145ca8 str r12, [sp, #0x24]
 *   @0x145cac bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145cb0 mov r1, #6
 *   @0x145cb4 mov r2, r0
 *   @0x145cb8 mov r0, r4
 *   @0x145cbc str r2, [sp, #0x28]
 *   @0x145cc0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145cc4 mov r1, #7
 *   @0x145cc8 mov r3, r0
 *   @0x145ccc mov r0, r4
 *   @0x145cd0 str r3, [sp, #0x2c]
 *   @0x145cd4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145cd8 mov r1, #8
 *   @0x145cdc mov r11, r0
 *   @0x145ce0 mov r0, r4
 *   @0x145ce4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145ce8 mov r1, #9
 *   @0x145cec mov r10, r0
 *   @0x145cf0 mov r0, r4
 *   @0x145cf4 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x145cf8 mov r1, #10
 *   @0x145cfc mov r9, r0
 *   @0x145d00 mov r0, r4
 *   @0x145d04 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x145d08 ldr r2, [sp, #0x28]
 *   @0x145d0c ldr r3, [sp, #0x2c]
 *   @0x145d10 mov r1, r8
 *   @0x145d14 ldr r12, [sp, #0x24]
 *   @0x145d18 str r2, [sp, #0x4]
 *   @0x145d1c mov r2, r7
 *   @0x145d20 str r3, [sp, #0x8]
 *   @0x145d24 mov r3, r6
 *   @0x145d28 str r12, [sp]
 *   @0x145d2c str r11, [sp, #0xc]
 *   @0x145d30 str r10, [sp, #0x10]
 *   @0x145d34 str r9, [sp, #0x14]
 *   @0x145d38 str r0, [sp, #0x18]
 *   @0x145d3c mov r0, r5
 *   @0x145d40 bl 0x165a80 <_Z11GR_3DM_Coneiffffffffbi>
 *   @0x145d44 add sp, sp, #52
 *   @0x145d48 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §4/119 CBitmap32::SmoothEdges()  0x1661fc  size 264  66 条（0x1661fc..0x166304）
 * @func 0x1661fc 0x166318  size 284  71 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CBitmap32::SmoothEdges()+0xfc / CBitmap32::SmoothEdges()+0xec / CBitmap32::SmoothEdges()+0xa4 / CBitmap32::SmoothEdges()+0x64 / CBitmap32::SmoothEdges()+0x38
 * 字段偏移 top8: 0x4×3 / 0xc×2 / 0x2×2 / 0x8×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1661fc ldrb r3, [r0, #0x4]
 *   @0x166200 push {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x166204 cmp r3, #0
 *   @0x166208 sub sp, sp, #8
 *   @0x16620c beq 0x1662f8 <_ZN9CBitmap3211SmoothEdgesEv+0xfc>
 *   @0x166210 ldr r3, [r0, #0xc]
 *   @0x166214 cmp r3, #0
 *   @0x166218 beq 0x1662f8 <_ZN9CBitmap3211SmoothEdgesEv+0xfc>
 *   @0x16621c ldr r2, [r0, #0x8]
 *   @0x166220 cmp r2, #0
 *   @0x166224 beq 0x1662f8 <_ZN9CBitmap3211SmoothEdgesEv+0xfc>
 *   @0x166228 cmp r3, #0
 *   @0x16622c ble 0x1662f8 <_ZN9CBitmap3211SmoothEdgesEv+0xfc>
 *   @0x166230 mov r8, #1
 *   @0x166234 cmp r2, #0
 *   @0x166238 sub r10, r8, #1
 *   @0x16623c strle r8, [sp, #0x4]
 *   @0x166240 ble 0x1662e8 <_ZN9CBitmap3211SmoothEdgesEv+0xec>
 *   @0x166244 cmp r10, #0
 *   @0x166248 ldr r5, [r0, #0x14]
 *   @0x16624c mov r9, #0
 *   @0x166250 subgt r11, r8, #2
 *   @0x166254 movle r11, #0
 *   @0x166258 mov r7, r9
 *   @0x16625c str r8, [sp, #0x4]
 *   @0x166260 mla r1, r2, r10, r7
 *   @0x166264 add r4, r7, #1
 *   @0x166268 ldr r1, [r5, r1, lsl #2]
 *   @0x16626c tst r1, #-16777216
 *   @0x166270 bne 0x1662dc <_ZN9CBitmap3211SmoothEdgesEv+0xe0>
 *   @0x166274 cmp r7, #0
 *   @0x166278 mov r6, r11
 *   @0x16627c subne r7, r7, #1
 *   @0x166280 moveq r7, #0
 *   @0x166284 cmp r3, r8
 *   @0x166288 suble r1, r3, #1
 *   @0x16628c movgt r1, r8
 *   @0x166290 cmp r6, r1
 *   @0x166294 bgt 0x1662dc <_ZN9CBitmap3211SmoothEdgesEv+0xe0>
 *   @0x166298 mov r3, r7
 *   @0x16629c b 0x1662b4 <_ZN9CBitmap3211SmoothEdgesEv+0xb8>
 *   @0x1662a0 ldr r1, [r5, r12, lsl #2]
 *   @0x1662a4 cmn r1, #-536870911
 *   @0x1662a8 add r9, r1, #-536870912
 *   @0x1662ac strhi r9, [r5, r12, lsl #2]
 *   @0x1662b0 ldrhi r2, [r0, #0x8]
 *   @0x1662b4 cmp r4, r2
 *   @0x1662b8 sub r1, r2, #1
 *   @0x1662bc mla r12, r2, r6, r3
 *   @0x1662c0 movlt r1, r4
 *   @0x1662c4 cmp r3, r1
 *   @0x1662c8 add r3, r3, #1
 *   @0x1662cc ble 0x1662a0 <_ZN9CBitmap3211SmoothEdgesEv+0xa4>
 *   @0x1662d0 ldr r3, [r0, #0xc]
 *   @0x1662d4 add r6, r6, #1
 *   @0x1662d8 b 0x166284 <_ZN9CBitmap3211SmoothEdgesEv+0x88>
 *   @0x1662dc cmp r4, r2
 *   @0x1662e0 mov r7, r4
 *   @0x1662e4 blt 0x166260 <_ZN9CBitmap3211SmoothEdgesEv+0x64>
 *   @0x1662e8 ldr r1, [sp, #0x4]
 *   @0x1662ec add r8, r8, #1
 *   @0x1662f0 cmp r1, r3
 *   @0x1662f4 blt 0x166234 <_ZN9CBitmap3211SmoothEdgesEv+0x38>
 *   @0x1662f8 add sp, sp, #8
 *   @0x1662fc pop {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x166300 bx lr
 *
 * ══ §5/119 CInstance::Compute_Speed2()  0x192aa0  size 264  66 条（0x192aa0..0x192ba8）
 * @func 0x192aa0 0x192ba8  size 264  66 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8×4 / 0xb658c / 0xb6580
 * 字段偏移 top8: 0x64×1
 * VFP 指令 47 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x192aa0 push {r4, lr}
 *   @0x192aa4 vldr s15, [pc, #240]
 *   @0x192aa8 vpush {d8, d9}
 *   @0x192aac vldr s18, [r0, #204]
 *   @0x192ab0 vmul.f32 s18, s18, s15
 *   @0x192ab4 vldr s15, [pc, #228]
 *   @0x192ab8 vldr s17, [r0, #208]
 *   @0x192abc mov r4, r0
 *   @0x192ac0 vdiv.f32 s18, s18, s15
 *   @0x192ac4 vmov r0, s18
 *   @0x192ac8 bl 0xb658c <cosf@plt>
 *   @0x192acc vmov s12, r0
 *   @0x192ad0 vmov r0, s18
 *   @0x192ad4 vmul.f32 s16, s17, s12
 *   @0x192ad8 vstr s16, [r4, #224]
 *   @0x192adc bl 0xb6580 <sinf@plt>
 *   @0x192ae0 vcvt.f64.f32 d7, s16
 *   @0x192ae4 vmov s13, r0
 *   @0x192ae8 vmov r0, r1, d7
 *   @0x192aec vnmul.f32 s17, s17, s13
 *   @0x192af0 vstr s17, [r4, #228]
 *   @0x192af4 bl 0xb66e8 <lrint@plt>
 *   @0x192af8 vldr s15, [pc, #164]
 *   @0x192afc vmov s12, r0
 *   @0x192b00 vcvt.f32.s32 s14, s12
 *   @0x192b04 vsub.f32 s16, s16, s14
 *   @0x192b08 vabs.f32 s16, s16
 *   @0x192b0c vcmpe.f32 s16, s15
 *   @0x192b10 vmrs APSR_nzcv, fpscr
 *   @0x192b14 bmi 0x192b7c <_ZN9CInstance14Compute_Speed2Ev+0xdc>
 *   @0x192b18 vldr s16, [r4, #228]
 *   @0x192b1c vcvt.f64.f32 d7, s16
 *   @0x192b20 vmov r0, r1, d7
 *   @0x192b24 bl 0xb66e8 <lrint@plt>
 *   @0x192b28 vldr s15, [pc, #116]
 *   @0x192b2c vmov s12, r0
 *   @0x192b30 vcvt.f32.s32 s14, s12
 *   @0x192b34 vsub.f32 s16, s16, s14
 *   @0x192b38 vabs.f32 s16, s16
 *   @0x192b3c vcmpe.f32 s16, s15
 *   @0x192b40 vmrs APSR_nzcv, fpscr
 *   @0x192b44 bpl 0x192b64 <_ZN9CInstance14Compute_Speed2Ev+0xc4>
 *   @0x192b48 vldr s15, [r4, #228]
 *   @0x192b4c vcvt.f64.f32 d6, s15
 *   @0x192b50 vmov r0, r1, d6
 *   @0x192b54 bl 0xb66e8 <lrint@plt>
 *   @0x192b58 vmov s13, r0
 *   @0x192b5c vcvt.f32.s32 s15, s13
 *   @0x192b60 vstr s15, [r4, #228]
 *   @0x192b64 vpop {d8, d9}
 *   @0x192b68 mov r3, #1
 *   @0x192b6c mov r0, r4
 *   @0x192b70 strb r3, [r4, #0x64]
 *   @0x192b74 pop {r4, lr}
 *   @0x192b78 b 0x1cc1d0 <_Z18CollisionMarkDirtyP9CInstance>
 *   @0x192b7c vldr s15, [r4, #224]
 *   @0x192b80 vcvt.f64.f32 d6, s15
 *   @0x192b84 vmov r0, r1, d6
 *   @0x192b88 bl 0xb66e8 <lrint@plt>
 *   @0x192b8c vmov s13, r0
 *   @0x192b90 vcvt.f32.s32 s15, s13
 *   @0x192b94 vstr s15, [r4, #224]
 *   @0x192b98 b 0x192b18 <_ZN9CInstance14Compute_Speed2Ev+0x78>
 *   @0x192b9c ldrdmi r0, r1, [r9], #-251
 *   @0x192ba0 teqmi r4, #0
 *   @0x192ba4 ldmlo r1, {r0, r1, r2, r4, r8, r9, r10, r12, sp, pc} ^
 *
 * ══ §6/119 CPath::LoadFromStream(CStream*)  0x1a7018  size 264  66 条（0x1a7018..0x1a7120）
 * @func 0x1a7018 0x1a7120  size 264  66 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::ReadInteger()×4 / CStream::ReadReal()×3 / CStream::ReadBoolean() / MemoryManager::SetLength(void**, unsigned int, char const*, int) / CPath::LoadFromStream(CStream*)+0xf4 / CPath::ComputeInternal()
 * 字段偏移 top8: 0x10×3 / 0x4×3 / 0x14×1 / 0x18×1 / 0x1c×1 / 0xa8×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a7018 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x1a701c mov r4, r0
 *   @0x1a7020 mov r0, r1
 *   @0x1a7024 mov r6, r1
 *   @0x1a7028 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x1a702c movw r3, #0x212
 *   @0x1a7030 cmp r0, r3
 *   @0x1a7034 beq 0x1a7040 <_ZN5CPath14LoadFromStreamEP7CStream+0x28>
 *   @0x1a7038 mov r0, #0
 *   @0x1a703c pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1a7040 mov r0, r6
 *   @0x1a7044 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x1a7048 str r0, [r4, #0x14]
 *   @0x1a704c mov r0, r6
 *   @0x1a7050 bl 0x2019b0 <_ZN7CStream11ReadBooleanEv>
 *   @0x1a7054 strb r0, [r4, #0x18]
 *   @0x1a7058 mov r0, r6
 *   @0x1a705c bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x1a7060 str r0, [r4, #0x1c]
 *   @0x1a7064 mov r0, r6
 *   @0x1a7068 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x1a706c ldr r2, [pc, #0xa8]
 *   @0x1a7070 movw r3, #0x1ab
 *   @0x1a7074 add r2, pc, r2
 *   @0x1a7078 add r1, r0, r0, lsl #1
 *   @0x1a707c str r0, [r4, #0x10]
 *   @0x1a7080 add r0, r4, #4
 *   @0x1a7084 lsl r1, r1, #2
 *   @0x1a7088 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1a708c ldr r3, [r4, #0x10]
 *   @0x1a7090 cmp r3, #0
 *   @0x1a7094 str r3, [r4]
 *   @0x1a7098 movgt r5, #0
 *   @0x1a709c movgt r7, r5
 *   @0x1a70a0 ble 0x1a710c <_ZN5CPath14LoadFromStreamEP7CStream+0xf4>
 *   @0x1a70a4 mov r0, r6
 *   @0x1a70a8 ldr r8, [r4, #0x4]
 *   @0x1a70ac bl 0x20187c <_ZN7CStream8ReadRealEv>
 *   @0x1a70b0 ldr r9, [r4, #0x4]
 *   @0x1a70b4 add r8, r8, r5
 *   @0x1a70b8 add r7, r7, #1
 *   @0x1a70bc add r9, r9, r5
 *   @0x1a70c0 vmov d6, r0, r1
 *   @0x1a70c4 mov r0, r6
 *   @0x1a70c8 vcvt.f32.f64 s15, d6
 *   @0x1a70cc vstr s15, [r8]
 *   @0x1a70d0 bl 0x20187c <_ZN7CStream8ReadRealEv>
 *   @0x1a70d4 ldr r8, [r4, #0x4]
 *   @0x1a70d8 add r8, r8, r5
 *   @0x1a70dc add r5, r5, #12
 *   @0x1a70e0 vmov d6, r0, r1
 *   @0x1a70e4 mov r0, r6
 *   @0x1a70e8 vcvt.f32.f64 s15, d6
 *   @0x1a70ec vstr s15, [r9, #4]
 *   @0x1a70f0 bl 0x20187c <_ZN7CStream8ReadRealEv>
 *   @0x1a70f4 ldr r3, [r4, #0x10]
 *   @0x1a70f8 cmp r3, r7
 *   @0x1a70fc vmov d6, r0, r1
 *   @0x1a7100 vcvt.f32.f64 s15, d6
 *   @0x1a7104 vstr s15, [r8, #8]
 *   @0x1a7108 bgt 0x1a70a4 <_ZN5CPath14LoadFromStreamEP7CStream+0x8c>
 *   @0x1a710c mov r0, r4
 *   @0x1a7110 bl 0x1a6e30 <_ZN5CPath15ComputeInternalEv>
 *   @0x1a7114 mov r0, #1
 *   @0x1a7118 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1a711c andseq r6, r10, r4, rrx
 *
 * ══ §7/119 DrawHardwareCursor(float, float, float)  0x1b2ab0  size 264  66 条（0x1b2ab0..0x1b2bb8）
 * @func 0x1b2ab0 0x1b2bb8  size 264  66 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics::AllocVerts(ePrimType, void*, int, int)
 * 字段偏移 top8: 0xfc×1 / 0x8c×1 / 0x88×1 / 0x70×1 / 0x2c×1 / 0x14×1 / 0x10×1 / 0x80×1
 * VFP 指令 26 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b2ab0 ldr r12, [pc, #0xfc]
 *   @0x1b2ab4 push {r3, lr}
 *   @0x1b2ab8 vpush {d8, d9}
 *   @0x1b2abc ldr r12, [pc, r12]
 *   @0x1b2ac0 vmov s16, r1
 *   @0x1b2ac4 mov r3, #6
 *   @0x1b2ac8 vmov s17, r0
 *   @0x1b2acc ldr r1, [r12]
 *   @0x1b2ad0 vmov s18, r2
 *   @0x1b2ad4 mov r0, #4
 *   @0x1b2ad8 mov r2, #24
 *   @0x1b2adc bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x1b2ae0 vldr s15, [pc, #196]
 *   @0x1b2ae4 vmul.f32 s18, s18, s15
 *   @0x1b2ae8 vldr s15, [pc, #192]
 *   @0x1b2aec mov r3, #0
 *   @0x1b2af0 mvn r1, #-16777216
 *   @0x1b2af4 vcvt.u32.f32 s18, s18
 *   @0x1b2af8 vsub.f32 s14, s17, s15
 *   @0x1b2afc vmov r12, s18
 *   @0x1b2b00 vadd.f32 s13, s17, s15
 *   @0x1b2b04 vstr s14, [r0, #120]
 *   @0x1b2b08 vstr s14, [r0, #96]
 *   @0x1b2b0c vstr s14, [r0]
 *   @0x1b2b10 str r3, [r0, #0x8c]
 *   @0x1b2b14 str r3, [r0, #0x88]
 *   @0x1b2b18 str r3, [r0, #0x70]
 *   @0x1b2b1c str r3, [r0, #0x2c]
 *   @0x1b2b20 str r3, [r0, #0x14]
 *   @0x1b2b24 str r3, [r0, #0x10]
 *   @0x1b2b28 mov r3, #1065353216
 *   @0x1b2b2c str r3, [r0, #0x80]
 *   @0x1b2b30 vsub.f32 s14, s16, s15
 *   @0x1b2b34 vstr s13, [r0, #72]
 *   @0x1b2b38 orr r2, r1, r12, lsl #24
 *   @0x1b2b3c vstr s13, [r0, #48]
 *   @0x1b2b40 vstr s13, [r0, #24]
 *   @0x1b2b44 str r3, [r0, #0x68]
 *   @0x1b2b48 str r3, [r0, #0x50]
 *   @0x1b2b4c str r3, [r0, #0x38]
 *   @0x1b2b50 str r3, [r0, #0x20]
 *   @0x1b2b54 str r3, [r0, #0x8]
 *   @0x1b2b58 str r3, [r0, #0x74]
 *   @0x1b2b5c str r3, [r0, #0x5c]
 *   @0x1b2b60 str r3, [r0, #0x58]
 *   @0x1b2b64 vadd.f32 s15, s16, s15
 *   @0x1b2b68 vstr s14, [r0, #124]
 *   @0x1b2b6c vstr s14, [r0, #28]
 *   @0x1b2b70 vstr s14, [r0, #4]
 *   @0x1b2b74 str r2, [r0, #0x84]
 *   @0x1b2b78 str r2, [r0, #0x6c]
 *   @0x1b2b7c str r2, [r0, #0x54]
 *   @0x1b2b80 str r2, [r0, #0x3c]
 *   @0x1b2b84 str r2, [r0, #0x24]
 *   @0x1b2b88 str r2, [r0, #0xc]
 *   @0x1b2b8c vstr s15, [r0, #100]
 *   @0x1b2b90 vstr s15, [r0, #52]
 *   @0x1b2b94 vstr s15, [r0, #76]
 *   @0x1b2b98 str r3, [r0, #0x44]
 *   @0x1b2b9c str r3, [r0, #0x40]
 *   @0x1b2ba0 str r3, [r0, #0x28]
 *   @0x1b2ba4 vpop {d8, d9}
 *   @0x1b2ba8 pop {r3, pc}
 *   @0x1b2bac cmnmi pc, #0
 *   @0x1b2bb0 andmi r0, r0, #0
 *   @0x1b2bb4 eoreq sp, r3, r0, ror #26
 *
 * ══ §8/119 CLayerManager::GetNewInstanceElement()  0x1c0cdc  size 264  66 条（0x1c0cdc..0x1c0de4）
 * @func 0x1c0cdc 0x1c0de4  size 264  66 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetNewInstanceElement()+0xc0 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / CLayerManager::GetNewInstanceElement()+0x34
 * 字段偏移 top8: 0x8×6 / 0x10×4 / 0x14×2 / 0x18×2 / 0xf4×1 / 0xd8×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1c0cdc push {r4, r5, r6, r7, r8, lr}
 *   @0x1c0ce0 ldr r4, [pc, #0xf4]
 *   @0x1c0ce4 ldr r4, [pc, r4]
 *   @0x1c0ce8 ldr r6, [r4, #0x8]
 *   @0x1c0cec cmp r6, #0
 *   @0x1c0cf0 bne 0x1c0da4 <_ZN13CLayerManager21GetNewInstanceElementEv+0xc8>
 *   @0x1c0cf4 ldr r3, [r4, #0x10]
 *   @0x1c0cf8 cmp r3, #0
 *   @0x1c0cfc ble 0x1c0d9c <_ZN13CLayerManager21GetNewInstanceElementEv+0xc0>
 *   @0x1c0d00 ldr r8, [pc, #0xd8]
 *   @0x1c0d04 mov r5, r6
 *   @0x1c0d08 mvn r7, #0
 *   @0x1c0d0c add r8, pc, r8
 *   @0x1c0d10 mov r3, #1
 *   @0x1c0d14 mov r0, #36
 *   @0x1c0d18 mov r1, r8
 *   @0x1c0d1c mov r2, #63
 *   @0x1c0d20 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1c0d24 mov r3, #2
 *   @0x1c0d28 cmp r0, #0
 *   @0x1c0d2c beq 0x1c0d54 <_ZN13CLayerManager21GetNewInstanceElementEv+0x78>
 *   @0x1c0d30 strb r5, [r0, #0x8]
 *   @0x1c0d34 str r5, [r0, #0xc]
 *   @0x1c0d38 str r5, [r0, #0x10]
 *   @0x1c0d3c str r5, [r0, #0x14]
 *   @0x1c0d40 str r5, [r0, #0x18]
 *   @0x1c0d44 str r7, [r0, #0x4]
 *   @0x1c0d48 str r7, [r0, #0x1c]
 *   @0x1c0d4c str r5, [r0, #0x20]
 *   @0x1c0d50 str r3, [r0]
 *   @0x1c0d54 ldr r3, [r4]
 *   @0x1c0d58 add r6, r6, #1
 *   @0x1c0d5c ldr r2, [r4, #0x8]
 *   @0x1c0d60 cmp r3, #0
 *   @0x1c0d64 streq r0, [r4, #0x4]
 *   @0x1c0d68 strne r0, [r3, #0x18]
 *   @0x1c0d6c add r2, r2, #1
 *   @0x1c0d70 streq r3, [r0, #0x18]
 *   @0x1c0d74 streq r3, [r0, #0x14]
 *   @0x1c0d78 strne r3, [r0, #0x14]
 *   @0x1c0d7c ldr r3, [r4, #0x10]
 *   @0x1c0d80 streq r0, [r4]
 *   @0x1c0d84 strne r0, [r4]
 *   @0x1c0d88 strne r5, [r0, #0x18]
 *   @0x1c0d8c cmp r6, r3
 *   @0x1c0d90 str r2, [r4, #0x8]
 *   @0x1c0d94 blt 0x1c0d10 <_ZN13CLayerManager21GetNewInstanceElementEv+0x34>
 *   @0x1c0d98 ldr r6, [r4, #0x8]
 *   @0x1c0d9c lsl r3, r3, #1
 *   @0x1c0da0 str r3, [r4, #0x10]
 *   @0x1c0da4 ldr r0, [r4]
 *   @0x1c0da8 sub r6, r6, #1
 *   @0x1c0dac str r6, [r4, #0x8]
 *   @0x1c0db0 ldr r3, [r0, #0x18]
 *   @0x1c0db4 ldr r2, [r0, #0x14]
 *   @0x1c0db8 cmp r3, #0
 *   @0x1c0dbc strne r2, [r3, #0x14]
 *   @0x1c0dc0 ldrne r2, [r0, #0x14]
 *   @0x1c0dc4 ldrne r3, [r0, #0x18]
 *   @0x1c0dc8 streq r2, [r4]
 *   @0x1c0dcc cmp r2, #0
 *   @0x1c0dd0 streq r3, [r4, #0x4]
 *   @0x1c0dd4 strne r3, [r2, #0x18]
 *   @0x1c0dd8 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1c0ddc eoreq pc, r2, r0, lsl #23
 *   @0x1c0de0 andseq r12, r8, r8, lsl #19
 *
 * ══ §9/119 CTimeLine::~CTimeLine()  0x1f1890  size 264  66 条（0x1f1890..0x1f1998）
 * @func 0x1f1890 0x1f1998  size 264  66 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×4 / CTimeLine::Clear() / CTimeLine::~CTimeLine()+0xc8 / CTimeLine::~CTimeLine()+0x60
 * 字段偏移 top8: 0xc×5 / 0x14×3 / 0x8×3 / 0xfc×1 / 0x10×1 / 0x2×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f1890 ldr r3, [pc, #0xfc]
 *   @0x1f1894 push {r4, r5, r6, r7, r8, lr}
 *   @0x1f1898 ldr r3, [pc, r3]
 *   @0x1f189c mov r6, r0
 *   @0x1f18a0 add r3, r3, #8
 *   @0x1f18a4 str r3, [r0]
 *   @0x1f18a8 bl 0x1f1768 <_ZN9CTimeLine5ClearEv>
 *   @0x1f18ac ldr r4, [r6, #0x14]
 *   @0x1f18b0 subs r0, r4, #0
 *   @0x1f18b4 beq 0x1f1978 <_ZN9CTimeLineD2Ev+0xe8>
 *   @0x1f18b8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f18bc mov r3, #0
 *   @0x1f18c0 str r3, [r6, #0x14]
 *   @0x1f18c4 ldr r12, [r6, #0x8]
 *   @0x1f18c8 mov r4, #0
 *   @0x1f18cc str r4, [r6, #0x10]
 *   @0x1f18d0 cmp r12, r4
 *   @0x1f18d4 beq 0x1f1970 <_ZN9CTimeLineD2Ev+0xe0>
 *   @0x1f18d8 ldr r5, [r6, #0xc]
 *   @0x1f18dc cmp r5, r4
 *   @0x1f18e0 beq 0x1f1984 <_ZN9CTimeLineD2Ev+0xf4>
 *   @0x1f18e4 cmp r12, r4
 *   @0x1f18e8 ble 0x1f1958 <_ZN9CTimeLineD2Ev+0xc8>
 *   @0x1f18ec mov r8, r4
 *   @0x1f18f0 ldr r1, [r5]
 *   @0x1f18f4 movw r3, #0xfeee
 *   @0x1f18f8 movt r3, #0xfeee
 *   @0x1f18fc movw r2, #0xfeee
 *   @0x1f1900 cmp r1, r3
 *   @0x1f1904 movt r2, #0xfeee
 *   @0x1f1908 lsl r7, r4, #2
 *   @0x1f190c beq 0x1f194c <_ZN9CTimeLineD2Ev+0xbc>
 *   @0x1f1910 ldr r3, [r5, r4, lsl #2]
 *   @0x1f1914 add r1, r5, r7
 *   @0x1f1918 cmp r3, #0
 *   @0x1f191c mov r0, r3
 *   @0x1f1920 beq 0x1f194c <_ZN9CTimeLineD2Ev+0xbc>
 *   @0x1f1924 ldr r3, [r3]
 *   @0x1f1928 cmp r3, r2
 *   @0x1f192c beq 0x1f1944 <_ZN9CTimeLineD2Ev+0xb4>
 *   @0x1f1930 ldr r3, [r3, #0x4]
 *   @0x1f1934 blx r3
 *   @0x1f1938 ldr r1, [r6, #0xc]
 *   @0x1f193c ldr r12, [r6, #0x8]
 *   @0x1f1940 add r1, r1, r7
 *   @0x1f1944 str r8, [r1]
 *   @0x1f1948 ldr r5, [r6, #0xc]
 *   @0x1f194c add r4, r4, #1
 *   @0x1f1950 cmp r4, r12
 *   @0x1f1954 blt 0x1f18f0 <_ZN9CTimeLineD2Ev+0x60>
 *   @0x1f1958 mov r0, r5
 *   @0x1f195c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f1960 mov r3, #0
 *   @0x1f1964 str r3, [r6, #0xc]
 *   @0x1f1968 mov r3, #0
 *   @0x1f196c str r3, [r6, #0x8]
 *   @0x1f1970 mov r0, r6
 *   @0x1f1974 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1f1978 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f197c str r4, [r6, #0x14]
 *   @0x1f1980 b 0x1f18c4 <_ZN9CTimeLineD2Ev+0x34>
 *   @0x1f1984 mov r0, r5
 *   @0x1f1988 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f198c str r5, [r6, #0xc]
 *   @0x1f1990 b 0x1f1968 <_ZN9CTimeLineD2Ev+0xd8>
 *   @0x1f1994 andseq pc, pc, r12, lsl #11
 *
 * ══ §10/119 CDS_Stack::ReadFromString(char const*, bool)  0x20f860  size 264  66 条（0x20f860..0x20f968）
 * @func 0x20f860 0x20f968  size 264  66 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::ReadInteger()×2 / CStream::~CStream()×2 / operator delete(void*)×2 / operator new(unsigned int) / CStream::CStream(int) / CStream::ConvertFromString(char const*) / CDS_Stack::ReadFromString(char const*, bool)+0x60 / CDS_Stack::Clear()
 * 字段偏移 top8: 0x4×3 / 0x80×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20f860 push {r3, r4, r5, r6, r7, lr}
 *   @0x20f864 mov r6, r0
 *   @0x20f868 mov r0, #32
 *   @0x20f86c mov r7, r2
 *   @0x20f870 mov r4, r1
 *   @0x20f874 bl 0x27c524 <_Znwj>
 *   @0x20f878 mov r1, #0
 *   @0x20f87c mov r5, r0
 *   @0x20f880 bl 0x2010ec <_ZN7CStreamC2Ei>
 *   @0x20f884 mov r0, r5
 *   @0x20f888 mov r1, r4
 *   @0x20f88c bl 0x2025b0 <_ZN7CStream17ConvertFromStringEPKc>
 *   @0x20f890 mov r0, r5
 *   @0x20f894 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x20f898 sub r3, r0, #101
 *   @0x20f89c cmp r3, #1
 *   @0x20f8a0 bls 0x20f8c0 <_ZN9CDS_Stack14ReadFromStringEPKcb+0x60>
 *   @0x20f8a4 subs r0, r5, #0
 *   @0x20f8a8 beq 0x20f950 <_ZN9CDS_Stack14ReadFromStringEPKcb+0xf0>
 *   @0x20f8ac bl 0x201328 <_ZN7CStreamD2Ev>
 *   @0x20f8b0 mov r0, r5
 *   @0x20f8b4 bl 0x27d1d0 <_ZdlPv>
 *   @0x20f8b8 mov r0, #0
 *   @0x20f8bc pop {r3, r4, r5, r6, r7, pc}
 *   @0x20f8c0 cmp r7, #0
 *   @0x20f8c4 movne r7, #1
 *   @0x20f8c8 beq 0x20f954 <_ZN9CDS_Stack14ReadFromStringEPKcb+0xf4>
 *   @0x20f8cc mov r0, r6
 *   @0x20f8d0 bl 0x20f270 <_ZN9CDS_Stack5ClearEv>
 *   @0x20f8d4 mov r0, r5
 *   @0x20f8d8 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x20f8dc ldr r2, [pc, #0x80]
 *   @0x20f8e0 movw r3, #0x22d
 *   @0x20f8e4 add r2, pc, r2
 *   @0x20f8e8 lsl r1, r0, #4
 *   @0x20f8ec str r0, [r6, #0x4]
 *   @0x20f8f0 add r0, r6, #12
 *   @0x20f8f4 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x20f8f8 ldr r3, [r6, #0x4]
 *   @0x20f8fc cmp r3, #0
 *   @0x20f900 str r3, [r6, #0x8]
 *   @0x20f904 movgt r4, #0
 *   @0x20f908 ble 0x20f930 <_ZN9CDS_Stack14ReadFromStringEPKcb+0xd0>
 *   @0x20f90c ldr r0, [r6, #0xc]
 *   @0x20f910 mov r1, r5
 *   @0x20f914 mov r2, r7
 *   @0x20f918 add r0, r0, r4, lsl #4
 *   @0x20f91c add r4, r4, #1
 *   @0x20f920 bl 0x208638 <_Z9ReadValueR6RValueR7CStreami>
 *   @0x20f924 ldr r3, [r6, #0x4]
 *   @0x20f928 cmp r3, r4
 *   @0x20f92c bgt 0x20f90c <_ZN9CDS_Stack14ReadFromStringEPKcb+0xac>
 *   @0x20f930 cmp r5, #0
 *   @0x20f934 beq 0x20f948 <_ZN9CDS_Stack14ReadFromStringEPKcb+0xe8>
 *   @0x20f938 mov r0, r5
 *   @0x20f93c bl 0x201328 <_ZN7CStreamD2Ev>
 *   @0x20f940 mov r0, r5
 *   @0x20f944 bl 0x27d1d0 <_ZdlPv>
 *   @0x20f948 mov r0, #1
 *   @0x20f94c pop {r3, r4, r5, r6, r7, pc}
 *   @0x20f950 pop {r3, r4, r5, r6, r7, pc}
 *   @0x20f954 cmp r0, #101
 *   @0x20f958 moveq r7, #2
 *   @0x20f95c movne r7, #0
 *   @0x20f960 b 0x20f8cc <_ZN9CDS_Stack14ReadFromStringEPKcb+0x6c>
 *   @0x20f964 andseq r3, r4, r8, lsl #30
 *
 * ══ §11/119 SoundHardware::Playing(void*)  0x220ee0  size 264  59 条（0x220ee0..0x220fe8）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x220ee0 0x220fe8  size 264  59 条
 * 部分覆盖: 本节 59/66 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x220ef0→0x755361, 0x220f08→0x755363, 0x220f1c→0x755362, 0x220f30→0x755360, 0x220f90→0x3eb70c
 * 调用序列: 0xb6a9c / CheckALError()
 * 字段偏移 top8: 0x44×3 / 0x4×2 / 0xd8×1 / 0xd4×1 / 0xc0×1 / 0xb0×1 / 0xa0×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x220ee0 push {r4, r5, r6, r7, lr}
 *   @0x220ee4 mov r5, r1
 *   @0x220ee8 ldr r4, [pc, #0xd8]
 *   @0x220eec sub sp, sp, #12
 *   @0x220ef0 ldr r3, [pc, #0xd4]
 *   @0x220ef4 add r4, pc, r4
 *   @0x220ef8 ldr r3, [r4, r3]
 *   @0x220efc ldrb r3, [r3]
 *   @0x220f1c ldr r3, [pc, #0xb0]
 *   @0x220f20 ldr r3, [r4, r3]
 *   @0x220f24 ldrb r3, [r3]
 *   @0x220f28 cmp r3, #0
 *   @0x220f2c bne 0x220f84 <_ZN13SoundHardware7PlayingEPv+0xa4>
 *   @0x220f30 ldr r3, [pc, #0xa0]
 *   @0x220f34 ldr r3, [r4, r3]
 *   @0x220f38 ldrb r4, [r3]
 *   @0x220f3c cmp r4, #0
 *   @0x220f40 bne 0x220f84 <_ZN13SoundHardware7PlayingEPv+0xa4>
 *   @0x220f44 cmp r5, #0
 *   @0x220f48 beq 0x220f84 <_ZN13SoundHardware7PlayingEPv+0xa4>
 *   @0x220f4c add r7, sp, #4
 *   @0x220f50 movw r6, #0x1012
 *   @0x220f54 add r3, r5, r4
 *   @0x220f58 movw r1, #0x1010
 *   @0x220f5c mov r2, r7
 *   @0x220f60 add r4, r4, #4
 *   @0x220f64 ldr r0, [r3, #0x4]
 *   @0x220f68 bl 0xb6a9c <alGetSourcei@plt>
 *   @0x220f6c bl 0x220198 <_Z12CheckALErrorv>
 *   @0x220f70 ldr r3, [sp, #0x4]
 *   @0x220f74 cmp r3, r6
 *   @0x220f78 beq 0x220fc0 <_ZN13SoundHardware7PlayingEPv+0xe0>
 *   @0x220f7c cmp r4, #16
 *   @0x220f80 bne 0x220f54 <_ZN13SoundHardware7PlayingEPv+0x74>
 *   @0x220f84 mov r0, #0
 *   @0x220f88 add sp, sp, #12
 *   @0x220f8c pop {r4, r5, r6, r7, pc}
 *   @0x220f90 ldr r3, [pc, #0x44]
 *   @0x220f94 ldr r2, [pc, #0x44]
 *   @0x220f98 ldr r1, [pc, #0x44]
 *   @0x220f9c ldr r3, [r4, r3]
 *   @0x220fa0 add r2, pc, r2
 *   @0x220fa4 add r1, pc, r1
 *   @0x220fa8 add r2, r2, #152
 *   @0x220fac ldr r0, [r3]
 *   @0x220fb0 ldr r3, [r0]
 *   @0x220fb4 ldr r3, [r3, #0xc]
 *   @0x220fb8 blx r3
 *   @0x220fbc b 0x220f08 <_ZN13SoundHardware7PlayingEPv+0x28>
 *   @0x220fc0 mov r0, #1
 *   @0x220fc4 b 0x220f88 <_ZN13SoundHardware7PlayingEPv+0xa8>
 *   @0x220fc8 andseq r0, sp, r12, asr sp
 *   @0x220fcc .word 0xfffff7d8
 *   @0x220fd0 .word 0xffffd3fc
 *   @0x220fd4 .word 0xfffff7e0
 *   @0x220fd8 .word 0xfffff7e4
 *   @0x220fdc .word 0xffffbac4
 *   @0x220fe0 andseq sp, r3, r8, lsr #32
 *   @0x220fe4 mulseq r3, r8, r8
 *
 * ══ §12/119 F_JSTypeof(RValue&, CInstance*, CInstance*, int, RValue*)  0x23c904  size 264  66 条（0x23c904..0x23ca0c）
 * @func 0x23c904 0x23ca0c  size 264  66 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_JSTypeof(RValue&, CInstance*, CInstance*, int, RValue*)+0xa4 / F_JSTypeof(RValue&, CInstance*, CInstance*, int, RValue*)+0xb8
 * 字段偏移 top8: 0xc×1 / 0x48×1 / 0x90×1 / 0x7c×1 / 0x64×1 / 0x5c×1 / 0x54×1 / 0x44×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23c904 ldr r2, [sp]
 *   @0x23c908 ldr r3, [r2, #0xc]
 *   @0x23c90c bic r3, r3, #-16777216
 *   @0x23c910 cmp r3, #7
 *   @0x23c914 beq 0x23c9b0 <_Z10F_JSTypeofR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0x23c918 bgt 0x23c95c <_Z10F_JSTypeofR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x23c91c cmp r3, #1
 *   @0x23c920 beq 0x23c990 <_Z10F_JSTypeofR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x23c924 ble 0x23c9a8 <_Z10F_JSTypeofR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0x23c928 cmp r3, #5
 *   @0x23c92c beq 0x23c984 <_Z10F_JSTypeofR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x23c930 cmp r3, #6
 *   @0x23c934 bne 0x23c9c4 <_Z10F_JSTypeofR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x23c938 ldr r3, [r2]
 *   @0x23c93c cmp r3, #0
 *   @0x23c940 beq 0x23c9dc <_Z10F_JSTypeofR6RValueP9CInstanceS2_iPS_+0xd8>
 *   @0x23c944 ldr r3, [r3, #0x48]
 *   @0x23c948 cmp r3, #3
 *   @0x23c94c beq 0x23c9d0 <_Z10F_JSTypeofR6RValueP9CInstanceS2_iPS_+0xcc>
 *   @0x23c950 ldr r1, [pc, #0x90]
 *   @0x23c954 add r1, pc, r1
 *   @0x23c958 b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x23c95c cmp r3, #12
 *   @0x23c960 beq 0x23c99c <_Z10F_JSTypeofR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0x23c964 ble 0x23c9bc <_Z10F_JSTypeofR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0x23c968 ldr r1, [pc, #0x7c]
 *   @0x23c96c cmp r3, #13
 *   @0x23c970 add r1, pc, r1
 *   @0x23c974 beq 0x23c958 <_Z10F_JSTypeofR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x23c978 mvn r2, #-16777216
 *   @0x23c97c cmp r3, r2
 *   @0x23c980 bne 0x23c9c4 <_Z10F_JSTypeofR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x23c984 ldr r1, [pc, #0x64]
 *   @0x23c988 add r1, pc, r1
 *   @0x23c98c b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x23c990 ldr r1, [pc, #0x5c]
 *   @0x23c994 add r1, pc, r1
 *   @0x23c998 b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x23c99c ldr r1, [pc, #0x54]
 *   @0x23c9a0 add r1, pc, r1
 *   @0x23c9a4 b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x23c9a8 cmp r3, #0
 *   @0x23c9ac bne 0x23c9c4 <_Z10F_JSTypeofR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x23c9b0 ldr r1, [pc, #0x44]
 *   @0x23c9b4 add r1, pc, r1
 *   @0x23c9b8 b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x23c9bc cmp r3, #10
 *   @0x23c9c0 beq 0x23c9b0 <_Z10F_JSTypeofR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0x23c9c4 ldr r1, [pc, #0x34]
 *   @0x23c9c8 add r1, pc, r1
 *   @0x23c9cc b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x23c9d0 ldr r1, [pc, #0x2c]
 *   @0x23c9d4 add r1, pc, r1
 *   @0x23c9d8 b 0x23c958 <_Z10F_JSTypeofR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x23c9dc ldr r1, [pc, #0x24]
 *   @0x23c9e0 add r1, pc, r1
 *   @0x23c9e4 b 0x23c958 <_Z10F_JSTypeofR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x23c9e8 andeq r5, pc, r4, ror #17
 *   @0x23c9ec andseq r8, r1, r0, asr r10
 *   @0x23c9f0 ldrdeq r5, r6, [pc], -r8
 *   @0x23c9f4 muleq pc, r4, lr
 *   @0x23c9f8 muleq pc, r8, r8
 *   @0x23c9fc muleq pc, r4, r8
 *   @0x23ca00 andseq r8, r1, r12, ror #19
 *   @0x23ca04 ldrsheq r8, [r1], -r4
 *   @0x23ca08 andeq r5, pc, r8, asr r8
 *
 * ══ §13/119 JS_DefaultGetOwnProperty(YYObjectBase*, RValue*, char const*)  0x23d0f0  size 264  66 条（0x23d0f0..0x23d1f8）
 * @func 0x23d0f0 0x23d1f8  size 264  66 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Code_Variable_FindAlloc_Slot_From_Name(YYObjectBase*, char const*) / unsigned int CHashMapCalculateHash<int>(int)
 * 字段偏移 top8: 0x8×5 / 0xc×3 / 0x4×3 / 0x60×2 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23d0f0 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x23d0f4 mvn r12, #-16777216
 *   @0x23d0f8 ldr r3, [r0, #0x60]
 *   @0x23d0fc mov r4, r0
 *   @0x23d100 mov r8, r1
 *   @0x23d104 str r12, [r1, #0xc]
 *   @0x23d108 cmp r3, #0
 *   @0x23d10c popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x23d110 mov r1, r2
 *   @0x23d114 bl 0xd2c84 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc>
 *   @0x23d118 ldr r4, [r4, #0x60]
 *   @0x23d11c bl 0x190f40 <_Z21CHashMapCalculateHashIiEjT_>
 *   @0x23d120 ldr r12, [r4, #0x8]
 *   @0x23d124 ldr r1, [r4, #0x10]
 *   @0x23d128 bic r0, r0, #-2147483648
 *   @0x23d12c and r3, r0, r12
 *   @0x23d130 lsl r5, r3, #1
 *   @0x23d134 add r2, r5, r3
 *   @0x23d138 add r2, r1, r2, lsl #2
 *   @0x23d13c ldr r2, [r2, #0x8]
 *   @0x23d140 cmp r2, #0
 *   @0x23d144 popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x23d148 cmp r0, r2
 *   @0x23d14c beq 0x23d1c0 <_Z24JS_DefaultGetOwnPropertyP12YYObjectBaseP6RValuePKc+0xd0>
 *   @0x23d150 ldr r9, [r4]
 *   @0x23d154 and r2, r12, r2
 *   @0x23d158 add r4, r3, r9
 *   @0x23d15c rsb r2, r2, r4
 *   @0x23d160 tst r2, r12
 *   @0x23d164 popmi {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x23d168 mov r4, #0
 *   @0x23d16c b 0x23d180 <_Z24JS_DefaultGetOwnPropertyP12YYObjectBaseP6RValuePKc+0x90>
 *   @0x23d170 cmp r0, r2
 *   @0x23d174 beq 0x23d1b8 <_Z24JS_DefaultGetOwnPropertyP12YYObjectBaseP6RValuePKc+0xc8>
 *   @0x23d178 cmp r6, r4
 *   @0x23d17c poplt {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x23d180 add r3, r3, #1
 *   @0x23d184 add r4, r4, #1
 *   @0x23d188 and r3, r12, r3
 *   @0x23d18c add r7, r3, r9
 *   @0x23d190 lsl r5, r3, #1
 *   @0x23d194 add r2, r5, r3
 *   @0x23d198 add r2, r1, r2, lsl #2
 *   @0x23d19c ldr r2, [r2, #0x8]
 *   @0x23d1a0 and r6, r12, r2
 *   @0x23d1a4 cmp r2, #0
 *   @0x23d1a8 rsb r6, r6, r7
 *   @0x23d1ac and r6, r6, r12
 *   @0x23d1b0 bne 0x23d170 <_Z24JS_DefaultGetOwnPropertyP12YYObjectBaseP6RValuePKc+0x80>
 *   @0x23d1b4 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x23d1b8 cmn r3, #1
 *   @0x23d1bc popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x23d1c0 add r3, r5, r3
 *   @0x23d1c4 add r1, r1, r3, lsl #2
 *   @0x23d1c8 cmn r1, #4
 *   @0x23d1cc popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x23d1d0 ldr r3, [r1, #0x4]
 *   @0x23d1d4 ldr r0, [r3]
 *   @0x23d1d8 ldr r1, [r3, #0x4]
 *   @0x23d1dc ldr r2, [r3, #0x8]
 *   @0x23d1e0 ldr r3, [r3, #0xc]
 *   @0x23d1e4 str r0, [r8]
 *   @0x23d1e8 str r1, [r8, #0x4]
 *   @0x23d1ec str r2, [r8, #0x8]
 *   @0x23d1f0 str r3, [r8, #0xc]
 *   @0x23d1f4 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §14/119 spCurveTimeline_setCurve  0x2817d8  size 264  66 条（0x2817d8..0x2818e0）
 * @func 0x2817d8 0x2818e0  size 264  66 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xff3a8778
 * 字段偏移 top8: 0x8×2
 * VFP 指令 48 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2817d8 vmov s14, r2
 *   @0x2817dc vldr s6, [sp]
 *   @0x2817e0 vmov s15, r3
 *   @0x2817e4 vldr s9, [sp, #4]
 *   @0x2817e8 vneg.f32 s12, s14
 *   @0x2817ec vldr s8, [pc, #220]
 *   @0x2817f0 vldr s7, [pc, #220]
 *   @0x2817f4 vldr s10, [pc, #220]
 *   @0x2817f8 vldr s11, [pc, #220]
 *   @0x2817fc add r2, r1, r1, lsl #3
 *   @0x281800 ldr r3, [r0, #0x8]
 *   @0x281804 vadd.f32 s12, s12, s12
 *   @0x281808 add r1, r1, r2, lsl #1
 *   @0x28180c add r12, r1, #2
 *   @0x281810 add r2, r1, #1
 *   @0x281814 add r0, r1, #19
 *   @0x281818 add r1, r3, r1, lsl #2
 *   @0x28181c add r3, r3, r12, lsl #2
 *   @0x281820 mov r12, #1073741824
 *   @0x281824 str r12, [r1]
 *   @0x281828 vneg.f32 s13, s15
 *   @0x28182c vadd.f32 s13, s13, s13
 *   @0x281830 vadd.f32 s12, s12, s6
 *   @0x281834 vsub.f32 s5, s15, s9
 *   @0x281838 vadd.f32 s13, s13, s9
 *   @0x28183c vmov.f32 s9, #1.000000e+00
 *   @0x281840 vmul.f32 s12, s12, s8
 *   @0x281844 vsub.f32 s4, s14, s6
 *   @0x281848 vmov.f32 s6, #3.000000e+00
 *   @0x28184c vmul.f32 s13, s13, s8
 *   @0x281850 vmov.f32 s8, s9
 *   @0x281854 vmla.f32 s9, s5, s6
 *   @0x281858 vmla.f32 s8, s4, s6
 *   @0x28185c vmov.f32 s6, s12
 *   @0x281860 vmla.f32 s6, s14, s7
 *   @0x281864 vmov.f32 s14, s6
 *   @0x281868 vmov.f32 s6, s13
 *   @0x28186c vmla.f32 s6, s15, s7
 *   @0x281870 vmul.f32 s8, s8, s10
 *   @0x281874 vmul.f32 s9, s9, s10
 *   @0x281878 vmov.f32 s15, s6
 *   @0x28187c vmla.f32 s14, s8, s11
 *   @0x281880 vmla.f32 s15, s9, s11
 *   @0x281884 vadd.f32 s12, s12, s12
 *   @0x281888 vadd.f32 s13, s13, s13
 *   @0x28188c vadd.f32 s12, s12, s8
 *   @0x281890 vadd.f32 s13, s13, s9
 *   @0x281894 vmov.f32 s10, s14
 *   @0x281898 vmov.f32 s11, s15
 *   @0x28189c vmov r1, s11
 *   @0x2818a0 add r2, r2, #2
 *   @0x2818a4 cmp r2, r0
 *   @0x2818a8 vstr s10, [r3, #-4]
 *   @0x2818ac vadd.f32 s14, s14, s12
 *   @0x2818b0 vadd.f32 s15, s15, s13
 *   @0x2818b4 str r1, [r3], #8
 *   @0x2818b8 vadd.f32 s10, s10, s14
 *   @0x2818bc vadd.f32 s11, s11, s15
 *   @0x2818c0 vadd.f32 s12, s12, s8
 *   @0x2818c4 vadd.f32 s13, s13, s9
 *   @0x2818c8 bne 0x28189c <spCurveTimeline_setCurve+0xc4>
 *   @0x2818cc bx lr
 *   @0x2818d0 ldcllo p2, c12, [r5], #572
 *   @0x2818d4 mrclo p9, #0x4, r9, c9, c10, #0x4
 *   @0x2818d8 bllo 0xff3a8778 <b2_toiTime+0xfffffffffec4f2d4>
 *   @0x2818dc vmullo.f32 s20, s21, s23
 *
 * ══ §15/119 png_set_cHRM  0x2ae6d8  size 264  66 条（0x2ae6d8..0x2ae7e0）
 * @func 0x2ae6d8 0x2ae7e0  size 264  66 条
 * 部分覆盖: 本节 66/73 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1 / 0x20×1
 * VFP 指令 59 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ae6d8 vpush {d8, d9, d10}
 *   @0x2ae6dc vmov d9, r2, r3
 *   @0x2ae6e0 vldr d8, [sp, #24]
 *   @0x2ae6e4 vldr d0, [sp, #32]
 *   @0x2ae6e8 vldr d1, [sp, #40]
 *   @0x2ae6ec vldr d2, [sp, #48]
 *   @0x2ae6f0 vldr d3, [sp, #56]
 *   @0x2ae6f4 vldr d4, [sp, #64]
 *   @0x2ae6f8 vldr d5, [sp, #72]
 *   @0x2ae6fc cmp r0, #0x0
 *   @0x2ae700 cmp r1, #0x0
 *   @0x2ae704 vcvt.f32.f64 s15, d9
 *   @0x2ae708 vldr d6, [pc, #204]
 *   @0x2ae70c ldr r3, [r1, #0x8]
 *   @0x2ae710 addvs r0, r11, r4, lsl #6
 *   @0x2ae714 vstr s15, [r1, #128]
 *   @0x2ae718 vcvt.f32.f64 s15, d8
 *   @0x2ae71c vstr s15, [r1, #132]
 *   @0x2ae720 vcvt.f32.f64 s15, d0
 *   @0x2ae724 vstr s15, [r1, #136]
 *   @0x2ae728 vcvt.f32.f64 s15, d1
 *   @0x2ae72c vstr s15, [r1, #140]
 *   @0x2ae730 vcvt.f32.f64 s15, d2
 *   @0x2ae734 vstr s15, [r1, #144]
 *   @0x2ae738 vcvt.f32.f64 s15, d3
 *   @0x2ae73c vstr s15, [r1, #148]
 *   @0x2ae740 vcvt.f32.f64 s15, d4
 *   @0x2ae744 vstr s15, [r1, #152]
 *   @0x2ae748 vcvt.f32.f64 s15, d5
 *   @0x2ae74c vstr s15, [r1, #156]
 *   @0x2ae750 vmov.f64 d7, #5.000000e-01
 *   @0x2ae754 vmov.f64 d10, d7
 *   @0x2ae758 vmla.f64 d10, d9, d6
 *   @0x2ae75c vcvt.s32.f64 s18, d10
 *   @0x2ae760 vmov.f64 d10, d7
 *   @0x2ae764 vstr s18, [r1, #256]
 *   @0x2ae768 vmla.f64 d10, d0, d6
 *   @0x2ae76c vcvt.s32.f64 s0, d10
 *   @0x2ae770 vstr s0, [r1, #264]
 *   @0x2ae774 vmov.f64 d0, d7
 *   @0x2ae778 vmla.f64 d0, d1, d6
 *   @0x2ae77c vcvt.s32.f64 s2, d0
 *   @0x2ae780 vstr s2, [r1, #268]
 *   @0x2ae784 vmov.f64 d1, d7
 *   @0x2ae788 vmla.f64 d1, d2, d6
 *   @0x2ae78c vcvt.s32.f64 s4, d1
 *   @0x2ae790 vstr s4, [r1, #272]
 *   @0x2ae794 vmov.f64 d2, d7
 *   @0x2ae798 vmla.f64 d2, d3, d6
 *   @0x2ae79c vcvt.s32.f64 s6, d2
 *   @0x2ae7a0 vmov.f64 d9, d7
 *   @0x2ae7a4 vstr s6, [r1, #276]
 *   @0x2ae7a8 vmov.f64 d3, d7
 *   @0x2ae7ac vmla.f64 d9, d8, d6
 *   @0x2ae7b0 vmla.f64 d3, d4, d6
 *   @0x2ae7b4 vmla.f64 d7, d5, d6
 *   @0x2ae7b8 vcvt.s32.f64 s16, d9
 *   @0x2ae7bc vcvt.s32.f64 s8, d3
 *   @0x2ae7c0 vstr s16, [r1, #260]
 *   @0x2ae7c4 vcvt.s32.f64 s14, d7
 *   @0x2ae7c8 vstr s8, [r1, #280]
 *   @0x2ae7cc vstr s14, [r1, #284]
 *   @0x2ae7d0 vpop {d8, d9, d10}
 *   @0x2ae7d4 bx lr
 *   @0x2ae7d8 movs r0, r0
 *   @0x2ae7dc ldr r0, [r0, #0x20]
 *
 * ══ §16/119 jpeg_huff_decode  0x2beb8c  size 264  66 条（0x2beb8c..0x2bec94）
 * @func 0x2beb8c 0x2bec94  size 264  66 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: jpeg_fill_bit_buffer×2 / jpeg_huff_decode+0x94
 * 字段偏移 top8: 0x8×3 / 0xc×3 / 0x2×2 / 0x4×2 / 0x20×1 / 0x8c×1 / 0x11×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2beb8c push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x2beb90 mov r12, r2
 *   @0x2beb94 ldr r4, [sp, #0x20]
 *   @0x2beb98 mov r8, r3
 *   @0x2beb9c mov r9, r0
 *   @0x2beba0 mov r3, r1
 *   @0x2beba4 cmp r4, r2
 *   @0x2beba8 bgt 0x2bec4c <jpeg_huff_decode+0xc0>
 *   @0x2bebac rsb r2, r4, r12
 *   @0x2bebb0 ldr r1, [r8, r4, lsl #2]
 *   @0x2bebb4 mvn r12, #0
 *   @0x2bebb8 mvn r12, r12, lsl r4
 *   @0x2bebbc and r12, r12, r3, asr r2
 *   @0x2bebc0 cmp r12, r1
 *   @0x2bebc4 ble 0x2bec20 <jpeg_huff_decode+0x94>
 *   @0x2bebc8 add r5, r8, r4, lsl #2
 *   @0x2bebcc b 0x2bebec <jpeg_huff_decode+0x60>
 *   @0x2bebd0 sub r2, r2, #1
 *   @0x2bebd4 ldr r7, [r5, #0x4]!
 *   @0x2bebd8 asr r12, r3, r2
 *   @0x2bebdc and r12, r12, #1
 *   @0x2bebe0 orr r12, r12, r6
 *   @0x2bebe4 cmp r7, r12
 *   @0x2bebe8 bge 0x2bec20 <jpeg_huff_decode+0x94>
 *   @0x2bebec cmp r2, #0
 *   @0x2bebf0 lsl r6, r12, #1
 *   @0x2bebf4 add r4, r4, #1
 *   @0x2bebf8 bgt 0x2bebd0 <jpeg_huff_decode+0x44>
 *   @0x2bebfc mov r1, r3
 *   @0x2bec00 mov r0, r9
 *   @0x2bec04 mov r3, #1
 *   @0x2bec08 bl 0x2bea2c <jpeg_fill_bit_buffer>
 *   @0x2bec0c cmp r0, #0
 *   @0x2bec10 beq 0x2bec8c <jpeg_huff_decode+0x100>
 *   @0x2bec14 ldr r3, [r9, #0x8]
 *   @0x2bec18 ldr r2, [r9, #0xc]
 *   @0x2bec1c b 0x2bebd0 <jpeg_huff_decode+0x44>
 *   @0x2bec20 cmp r4, #16
 *   @0x2bec24 str r3, [r9, #0x8]
 *   @0x2bec28 str r2, [r9, #0xc]
 *   @0x2bec2c bgt 0x2bec68 <jpeg_huff_decode+0xdc>
 *   @0x2bec30 add r4, r4, #18
 *   @0x2bec34 ldr r2, [r8, #0x8c]
 *   @0x2bec38 ldr r3, [r8, r4, lsl #2]
 *   @0x2bec3c add r12, r2, r12
 *   @0x2bec40 add r12, r12, r3
 *   @0x2bec44 ldrb r0, [r12, #0x11]
 *   @0x2bec48 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2bec4c mov r3, r4
 *   @0x2bec50 bl 0x2bea2c <jpeg_fill_bit_buffer>
 *   @0x2bec54 cmp r0, #0
 *   @0x2bec58 beq 0x2bec8c <jpeg_huff_decode+0x100>
 *   @0x2bec5c ldr r3, [r9, #0x8]
 *   @0x2bec60 ldr r12, [r9, #0xc]
 *   @0x2bec64 b 0x2bebac <jpeg_huff_decode+0x20>
 *   @0x2bec68 ldr r0, [r9, #0x10]
 *   @0x2bec6c mov r2, #118
 *   @0x2bec70 mvn r1, #0
 *   @0x2bec74 ldr r3, [r0]
 *   @0x2bec78 str r2, [r3, #0x14]
 *   @0x2bec7c ldr r3, [r3, #0x4]
 *   @0x2bec80 blx r3
 *   @0x2bec84 mov r0, #0
 *   @0x2bec88 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2bec8c mvn r0, #0
 *   @0x2bec90 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §17/119 b2PrismaticJoint::GetJointSpeed() const  0x2d020c  size 264  66 条（0x2d020c..0x2d0314）
 * @func 0x2d020c 0x2d0314  size 264  66 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1 / 0x30×1
 * VFP 指令 63 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d020c ldr r2, [r0, #0x34]
 *   @0x2d0210 vldr s10, [r0, #80]
 *   @0x2d0214 vldr s15, [r2, #48]
 *   @0x2d0218 vsub.f32 s10, s10, s15
 *   @0x2d021c vldr s15, [r2, #20]
 *   @0x2d0220 vpush {d8, d9, d10, d11}
 *   @0x2d0224 vldr s1, [r2, #44]
 *   @0x2d0228 vldr s23, [r0, #76]
 *   @0x2d022c vldr s0, [r2, #24]
 *   @0x2d0230 ldr r3, [r0, #0x30]
 *   @0x2d0234 vldr s11, [r0, #72]
 *   @0x2d0238 vldr s13, [r3, #48]
 *   @0x2d023c vldr s9, [r3, #20]
 *   @0x2d0240 vldr s8, [r3, #24]
 *   @0x2d0244 vldr s22, [r0, #68]
 *   @0x2d0248 vldr s3, [r2, #88]
 *   @0x2d024c vldr s5, [r2, #84]
 *   @0x2d0250 vldr s2, [r3, #44]
 *   @0x2d0254 vldr s14, [r0, #88]
 *   @0x2d0258 vldr s6, [r2, #80]
 *   @0x2d025c vldr s4, [r0, #84]
 *   @0x2d0260 vldr s21, [r3, #84]
 *   @0x2d0264 vmul.f32 s12, s10, s15
 *   @0x2d0268 vldr s7, [r3, #88]
 *   @0x2d026c vldr s20, [r2, #64]
 *   @0x2d0270 vldr s19, [r3, #64]
 *   @0x2d0274 vldr s18, [r3, #80]
 *   @0x2d0278 vldr s17, [r2, #60]
 *   @0x2d027c vldr s16, [r3, #60]
 *   @0x2d0280 vsub.f32 s1, s23, s1
 *   @0x2d0284 vmul.f32 s10, s10, s0
 *   @0x2d0288 vnmls.f32 s12, s1, s0
 *   @0x2d028c vsub.f32 s11, s11, s13
 *   @0x2d0290 vmla.f32 s10, s1, s15
 *   @0x2d0294 vmul.f32 s13, s11, s9
 *   @0x2d0298 vmul.f32 s11, s11, s8
 *   @0x2d029c vmla.f32 s5, s3, s12
 *   @0x2d02a0 vsub.f32 s2, s22, s2
 *   @0x2d02a4 vmul.f32 s15, s9, s14
 *   @0x2d02a8 vnmls.f32 s13, s2, s8
 *   @0x2d02ac vmla.f32 s11, s2, s9
 *   @0x2d02b0 vmls.f32 s6, s3, s10
 *   @0x2d02b4 vnmls.f32 s15, s8, s4
 *   @0x2d02b8 vmul.f32 s14, s8, s14
 *   @0x2d02bc vsub.f32 s8, s5, s21
 *   @0x2d02c0 vmla.f32 s14, s9, s4
 *   @0x2d02c4 vmls.f32 s8, s7, s13
 *   @0x2d02c8 vadd.f32 s5, s11, s19
 *   @0x2d02cc vadd.f32 s10, s10, s20
 *   @0x2d02d0 vsub.f32 s9, s6, s18
 *   @0x2d02d4 vneg.f32 s6, s7
 *   @0x2d02d8 vmul.f32 s7, s7, s15
 *   @0x2d02dc vsub.f32 s10, s10, s5
 *   @0x2d02e0 vmls.f32 s9, s11, s6
 *   @0x2d02e4 vadd.f32 s12, s12, s17
 *   @0x2d02e8 vadd.f32 s13, s13, s16
 *   @0x2d02ec vpop {d8, d9, d10, d11}
 *   @0x2d02f0 vmul.f32 s11, s14, s8
 *   @0x2d02f4 vmul.f32 s10, s10, s7
 *   @0x2d02f8 vmul.f32 s14, s14, s6
 *   @0x2d02fc vsub.f32 s13, s12, s13
 *   @0x2d0300 vmla.f32 s11, s15, s9
 *   @0x2d0304 vmla.f32 s10, s13, s14
 *   @0x2d0308 vadd.f32 s11, s10, s11
 *   @0x2d030c vmov r0, s11
 *   @0x2d0310 bx lr
 *
 * ══ §18/119 CSkeletonInstance::SetImageIndex(int, float)  0xbe3e8  size 260  65 条（0xbe3e8..0xbe4ec）
 * @func 0xbe3e8 0xbe4ec  size 260  65 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CSkeletonInstance::SetImageIndex(int, float)+0xc0×2 / fwrap(float, float) / CTimingSource::GetFPS()
 * 字段偏移 top8: 0x28×3 / 0xc×3 / 0x10×3 / 0x2×3 / 0x4×2 / 0xb0×1 / 0xa0×1 / 0x5×1
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xbe3e8 push {r4, r5, lr}
 *   @0xbe3ec vpush {d8}
 *   @0xbe3f0 subs r4, r1, #0
 *   @0xbe3f4 sub sp, sp, #12
 *   @0xbe3f8 mov r5, r0
 *   @0xbe3fc blt 0xbe4a8 <_ZN17CSkeletonInstance13SetImageIndexEif+0xc0>
 *   @0xbe400 ldr r3, [r0, #0x28]
 *   @0xbe404 cmp r3, #0
 *   @0xbe408 beq 0xbe4a8 <_ZN17CSkeletonInstance13SetImageIndexEif+0xc0>
 *   @0xbe40c ldr r1, [r3, #0xc]
 *   @0xbe410 cmp r4, r1
 *   @0xbe414 bge 0xbe4a8 <_ZN17CSkeletonInstance13SetImageIndexEif+0xc0>
 *   @0xbe418 ldr r3, [r3, #0x10]
 *   @0xbe41c ldr r1, [r3, r4, lsl #2]
 *   @0xbe420 cmp r1, #0
 *   @0xbe424 beq 0xbe4a8 <_ZN17CSkeletonInstance13SetImageIndexEif+0xc0>
 *   @0xbe428 ldr r3, [pc, #0xb0]
 *   @0xbe42c ldr r3, [pc, r3]
 *   @0xbe430 ldrb r3, [r3]
 *   @0xbe434 cmp r3, #0
 *   @0xbe438 bne 0xbe4b4 <_ZN17CSkeletonInstance13SetImageIndexEif+0xcc>
 *   @0xbe43c ldr r3, [pc, #0xa0]
 *   @0xbe440 ldr r3, [pc, r3]
 *   @0xbe444 ldr r3, [r3]
 *   @0xbe448 cmp r3, #0
 *   @0xbe44c beq 0xbe4d8 <_ZN17CSkeletonInstance13SetImageIndexEif+0xf0>
 *   @0xbe450 ldr r0, [r3, #0xc]
 *   @0xbe454 cmp r0, #0
 *   @0xbe458 ble 0xbe4a8 <_ZN17CSkeletonInstance13SetImageIndexEif+0xc0>
 *   @0xbe45c ldr r3, [r5, #0x28]
 *   @0xbe460 vmov s14, r0
 *   @0xbe464 vcvt.f32.s32 s16, s14
 *   @0xbe468 ldr r3, [r3, #0x10]
 *   @0xbe46c ldr r1, [r3, r4, lsl #2]
 *   @0xbe470 ldr r3, [r1, #0xc]
 *   @0xbe474 vldr s15, [r3, #4]
 *   @0xbe478 vmul.f32 s15, s16, s15
 *   @0xbe47c mov r0, r2
 *   @0xbe480 vmov r1, s15
 *   @0xbe484 bl 0x1e62fc <_Z5fwrapff>
 *   @0xbe488 ldr r2, [r5, #0x28]
 *   @0xbe48c mov r3, #1
 *   @0xbe490 ldr r2, [r2, #0x10]
 *   @0xbe494 ldr r2, [r2, r4, lsl #2]
 *   @0xbe498 vmov s15, r0
 *   @0xbe49c vdiv.f32 s16, s15, s16
 *   @0xbe4a0 vstr s16, [r2, #24]
 *   @0xbe4a4 strb r3, [r5, #0x5]
 *   @0xbe4a8 add sp, sp, #12
 *   @0xbe4ac vpop {d8}
 *   @0xbe4b0 pop {r4, r5, pc}
 *   @0xbe4b4 ldr r0, [pc, #0x2c]
 *   @0xbe4b8 str r2, [sp, #0x4]
 *   @0xbe4bc ldr r0, [pc, r0]
 *   @0xbe4c0 bl 0x214808 <_ZN13CTimingSource6GetFPSEv>
 *   @0xbe4c4 ldr r2, [sp, #0x4]
 *   @0xbe4c8 vmov d7, r0, r1
 *   @0xbe4cc vcvt.s32.f64 s15, d7
 *   @0xbe4d0 vmov r0, s15
 *   @0xbe4d4 b 0xbe454 <_ZN17CSkeletonInstance13SetImageIndexEif+0x6c>
 *   @0xbe4d8 vmov.f32 s16, #3.000000e+01
 *   @0xbe4dc b 0xbe470 <_ZN17CSkeletonInstance13SetImageIndexEif+0x88>
 *   @0xbe4e0 ldrshteq pc, [r2], -r8
 *   @0xbe4e4 eorseq pc, r2, r8, ror #9
 *   @0xbe4e8 eorseq pc, r2, r0, ror r4
 *
 * ══ §19/119 CBackground::LoadFromChunk(YYBackground*, unsigned char*)  0xc2c44  size 260  65 条（0xc2c44..0xc2d48）
 * @func 0xc2c44 0xc2d48  size 260  65 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CBackground::Clear() / CBackground::LoadFromChunk(YYBackground*, unsigned char*)+0xd0
 * 字段偏移 top8: 0x20×3 / 0x10×2 / 0x4×2 / 0x8×2 / 0x14×2 / 0x1c×2 / 0x24×2 / 0x28×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc2c44 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xc2c48 mov r5, r1
 *   @0xc2c4c mov r4, r0
 *   @0xc2c50 bl 0xc23c0 <_ZN11CBackground5ClearEv>
 *   @0xc2c54 ldr r3, [r5, #0x10]
 *   @0xc2c58 cmp r3, #0
 *   @0xc2c5c bne 0xc2d1c <_ZN11CBackground13LoadFromChunkEP12YYBackgroundPh+0xd8>
 *   @0xc2c60 mov r3, #0
 *   @0xc2c64 str r3, [r4]
 *   @0xc2c68 mov r2, r3
 *   @0xc2c6c str r3, [r4, #0x4]
 *   @0xc2c70 ldr r6, [r5, #0x4]
 *   @0xc2c74 mov r1, #0
 *   @0xc2c78 ldr r0, [r5, #0x8]
 *   @0xc2c7c subs r6, r6, r1
 *   @0xc2c80 ldr r3, [pc, #0xb8]
 *   @0xc2c84 ldr r7, [r5, #0xc]
 *   @0xc2c88 ldr r3, [pc, r3]
 *   @0xc2c8c movne r6, #1
 *   @0xc2c90 subs r0, r0, r1
 *   @0xc2c94 strb r6, [r4, #0x8]
 *   @0xc2c98 ldrb r12, [r3]
 *   @0xc2c9c movne r0, #1
 *   @0xc2ca0 subs r3, r7, r1
 *   @0xc2ca4 strb r0, [r4, #0x9]
 *   @0xc2ca8 movne r3, #1
 *   @0xc2cac cmp r12, r1
 *   @0xc2cb0 strb r3, [r4, #0xa]
 *   @0xc2cb4 str r2, [r4, #0x14]
 *   @0xc2cb8 str r1, [r4, #0x10]
 *   @0xc2cbc beq 0xc2d14 <_ZN11CBackground13LoadFromChunkEP12YYBackgroundPh+0xd0>
 *   @0xc2cc0 ldr r3, [r5, #0x14]
 *   @0xc2cc4 cmp r3, #1
 *   @0xc2cc8 ble 0xc2d14 <_ZN11CBackground13LoadFromChunkEP12YYBackgroundPh+0xd0>
 *   @0xc2ccc ldr r10, [r5, #0x18]
 *   @0xc2cd0 add r1, r5, #64
 *   @0xc2cd4 ldr r9, [r5, #0x1c]
 *   @0xc2cd8 ldr r8, [r5, #0x20]
 *   @0xc2cdc ldr r7, [r5, #0x24]
 *   @0xc2ce0 ldr r6, [r5, #0x28]
 *   @0xc2ce4 ldr r12, [r5, #0x2c]
 *   @0xc2ce8 ldr r0, [r5, #0x30]
 *   @0xc2cec ldrd r2, r3, [r5, #56]
 *   @0xc2cf0 str r10, [r4, #0x1c]
 *   @0xc2cf4 str r9, [r4, #0x20]
 *   @0xc2cf8 str r8, [r4, #0x24]
 *   @0xc2cfc str r7, [r4, #0x28]
 *   @0xc2d00 str r6, [r4, #0x2c]
 *   @0xc2d04 str r12, [r4, #0x30]
 *   @0xc2d08 str r0, [r4, #0x34]
 *   @0xc2d0c strd r2, r3, [r4, #56]
 *   @0xc2d10 str r1, [r4, #0x40]
 *   @0xc2d14 mov r0, #1
 *   @0xc2d18 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xc2d1c ldr r2, [pc, #0x20]
 *   @0xc2d20 ldr r2, [pc, r2]
 *   @0xc2d24 ldr r2, [r2]
 *   @0xc2d28 adds r2, r2, r3
 *   @0xc2d2c beq 0xc2c60 <_ZN11CBackground13LoadFromChunkEP12YYBackgroundPh+0x1c>
 *   @0xc2d30 ldrsh r1, [r2, #16]
 *   @0xc2d34 ldrsh r3, [r2, #18]
 *   @0xc2d38 stm r4, {r1, r3}
 *   @0xc2d3c b 0xc2c70 <_ZN11CBackground13LoadFromChunkEP12YYBackgroundPh+0x2c>
 *   @0xc2d40 mlaseq r2, r12, r12, r10
 *   @0xc2d44 eorseq r10, r2, r4, lsr #24
 *
 * ══ §20/119 Background_AddEmpty()  0xc41f0  size 260  65 条（0xc41f0..0xc42f4）
 * @func 0xc41f0 0xc42f4  size 260  65 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::SetLength(void**, unsigned int, char const*, int)×2 / 0xb65c8 / YYStrDup(char const*) / operator new(unsigned int) / CBackground::CBackground() / 0xb65d4
 * 字段偏移 top8: 0x104×2 / 0x2×2 / 0xdc×1 / 0xd8×1 / 0xd4×1 / 0xd0×1 / 0xb4×1 / 0x7c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc41f0 push {r4, r5, r6, r7, r8, lr}
 *   @0xc41f4 sub sp, sp, #264
 *   @0xc41f8 ldr r4, [pc, #0xdc]
 *   @0xc41fc movw r3, #0x2b9
 *   @0xc4200 ldr r5, [pc, #0xd8]
 *   @0xc4204 ldr r4, [pc, r4]
 *   @0xc4208 ldr r8, [pc, #0xd4]
 *   @0xc420c ldr r5, [pc, r5]
 *   @0xc4210 ldr r7, [pc, #0xd0]
 *   @0xc4214 ldr r12, [r4]
 *   @0xc4218 add r8, pc, r8
 *   @0xc421c ldr lr, [r5]
 *   @0xc4220 add r7, pc, r7
 *   @0xc4224 add r12, r12, #1
 *   @0xc4228 mov r2, r8
 *   @0xc422c add r0, r7, #4
 *   @0xc4230 ldr r6, [pc, #0xb4]
 *   @0xc4234 lsl r1, r12, #2
 *   @0xc4238 str lr, [sp, #0x104]
 *   @0xc423c str r12, [r4]
 *   @0xc4240 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0xc4244 ldr r12, [r4]
 *   @0xc4248 ldr r6, [pc, r6]
 *   @0xc424c mov r2, r8
 *   @0xc4250 movw r3, #0x2bb
 *   @0xc4254 mov r0, r6
 *   @0xc4258 add r8, sp, #4
 *   @0xc425c lsl r1, r12, #2
 *   @0xc4260 str r12, [r7]
 *   @0xc4264 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0xc4268 ldr r3, [r4]
 *   @0xc426c ldr r2, [pc, #0x7c]
 *   @0xc4270 mov r1, #256
 *   @0xc4274 mov r0, r8
 *   @0xc4278 sub r3, r3, #1
 *   @0xc427c add r2, pc, r2
 *   @0xc4280 bl 0xb65c8 <snprintf@plt>
 *   @0xc4284 ldr r3, [r4]
 *   @0xc4288 mov r0, r8
 *   @0xc428c ldr r6, [r6]
 *   @0xc4290 sub r8, r3, #-1073741823
 *   @0xc4294 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xc4298 str r0, [r6, r8, lsl #2]
 *   @0xc429c mov r0, #72
 *   @0xc42a0 bl 0x27c524 <_Znwj>
 *   @0xc42a4 mov r6, r0
 *   @0xc42a8 bl 0xc2b58 <_ZN11CBackgroundC2Ev>
 *   @0xc42ac ldr r0, [r4]
 *   @0xc42b0 ldr r1, [r7, #0x4]
 *   @0xc42b4 sub r12, r0, #-1073741823
 *   @0xc42b8 ldr r2, [sp, #0x104]
 *   @0xc42bc sub r0, r0, #1
 *   @0xc42c0 str r6, [r1, r12, lsl #2]
 *   @0xc42c4 ldr r3, [r5]
 *   @0xc42c8 cmp r2, r3
 *   @0xc42cc bne 0xc42d8 <_Z19Background_AddEmptyv+0xe8>
 *   @0xc42d0 add sp, sp, #264
 *   @0xc42d4 pop {r4, r5, r6, r7, r8, pc}
 *   @0xc42d8 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0xc42dc eorseq r9, r2, r4, asr #14
 *   @0xc42e0 eorseq r9, r2, r4, asr #14
 *   @0xc42e4 eoreq r12, r6, r8, ror #16
 *   @0xc42e8 eorseq r5, r11, r8, lsl #21
 *   @0xc42ec eorseq r9, r2, r4, lsl #14
 *   @0xc42f0 eoreq r12, r6, r0, asr r8
 *
 * ══ §21/119 Buffer_Vertex::FindNextType(yyVertexType)  0xc875c  size 260  65 条（0xc875c..0xc8860）
 * @func 0xc875c 0xc8860  size 260  65 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Error_Show_Action(char const*, bool)×3 / GetVertexFormat(int) / Buffer_Vertex::FindNextType(yyVertexType)+0xc8
 * 字段偏移 top8: 0x18×4 / 0xc×3 / 0x4×2 / 0x1c×2 / 0x24×1 / 0x8×1 / 0x10×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc875c push {r4, r5, r6, r7, r8, lr}
 *   @0xc8760 mov r6, r0
 *   @0xc8764 ldr r0, [r0, #0x24]
 *   @0xc8768 mov r5, r1
 *   @0xc876c bl 0x1e2cd0 <_Z15GetVertexFormati>
 *   @0xc8770 subs r8, r0, #0
 *   @0xc8774 beq 0xc883c <_ZN13Buffer_Vertex12FindNextTypeE12yyVertexType+0xe0>
 *   @0xc8778 ldr r4, [r8, #0x4]
 *   @0xc877c ldr r3, [r8, #0x8]
 *   @0xc8780 cmp r4, #0
 *   @0xc8784 ble 0xc8824 <_ZN13Buffer_Vertex12FindNextTypeE12yyVertexType+0xc8>
 *   @0xc8788 mov r12, #0
 *   @0xc878c b 0xc879c <_ZN13Buffer_Vertex12FindNextTypeE12yyVertexType+0x40>
 *   @0xc8790 subs r4, r4, #1
 *   @0xc8794 add r3, r3, #16
 *   @0xc8798 beq 0xc8804 <_ZN13Buffer_Vertex12FindNextTypeE12yyVertexType+0xa8>
 *   @0xc879c ldr r2, [r3, #0x4]
 *   @0xc87a0 cmp r2, r5
 *   @0xc87a4 bne 0xc8790 <_ZN13Buffer_Vertex12FindNextTypeE12yyVertexType+0x34>
 *   @0xc87a8 ldr r1, [r3, #0xc]
 *   @0xc87ac mov r12, #1
 *   @0xc87b0 ldr r2, [r6, #0x18]
 *   @0xc87b4 ands r7, r1, r2
 *   @0xc87b8 bne 0xc8790 <_ZN13Buffer_Vertex12FindNextTypeE12yyVertexType+0x34>
 *   @0xc87bc ldr r0, [r8, #0x10]
 *   @0xc87c0 orr r2, r1, r2
 *   @0xc87c4 ldr r1, [r3]
 *   @0xc87c8 ldr r3, [r6, #0xc]
 *   @0xc87cc cmp r2, r0
 *   @0xc87d0 ldr r0, [r6]
 *   @0xc87d4 add r1, r3, r1
 *   @0xc87d8 str r2, [r6, #0x18]
 *   @0xc87dc add r0, r0, r1
 *   @0xc87e0 popne {r4, r5, r6, r7, r8, pc}
 *   @0xc87e4 ldr r1, [r8, #0x14]
 *   @0xc87e8 ldr r2, [r6, #0x1c]
 *   @0xc87ec add r3, r1, r3
 *   @0xc87f0 str r7, [r6, #0x18]
 *   @0xc87f4 str r3, [r6, #0xc]
 *   @0xc87f8 add r3, r2, r12
 *   @0xc87fc str r3, [r6, #0x1c]
 *   @0xc8800 pop {r4, r5, r6, r7, r8, pc}
 *   @0xc8804 cmp r12, #0
 *   @0xc8808 beq 0xc8824 <_ZN13Buffer_Vertex12FindNextTypeE12yyVertexType+0xc8>
 *   @0xc880c ldr r0, [pc, #0x40]
 *   @0xc8810 mov r1, #1
 *   @0xc8814 add r0, pc, r0
 *   @0xc8818 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc881c mov r0, r4
 *   @0xc8820 pop {r4, r5, r6, r7, r8, pc}
 *   @0xc8824 ldr r0, [pc, #0x2c]
 *   @0xc8828 mov r1, #1
 *   @0xc882c add r0, pc, r0
 *   @0xc8830 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc8834 mov r0, #0
 *   @0xc8838 pop {r4, r5, r6, r7, r8, pc}
 *   @0xc883c ldr r0, [pc, #0x18]
 *   @0xc8840 mov r1, #1
 *   @0xc8844 add r0, pc, r0
 *   @0xc8848 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc884c mov r0, r8
 *   @0xc8850 pop {r4, r5, r6, r7, r8, pc}
 *   @0xc8854 eoreq r9, r6, r12, lsr #1
 *   @0xc8858 eoreq r9, r6, r4, ror #1
 *   @0xc885c eoreq r9, r6, r4, asr r0
 *
 * ══ §22/119 VM::GetDSPriority(Buffer_Standard*, int, int)  0xdb3b0  size 260  65 条（0xdb3b0..0xdb4b4）
 * @func 0xdb3b0 0xdb4b4  size 260  65 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GetThePriorityQueues(int&) / VM::GetDSPriority(Buffer_Standard*, int, int)+0xc4 / VM::WriteDSSizeCount(Buffer_Standard*, int, int&) / VM::GetDSPriority(Buffer_Standard*, int, int)+0xbc / VM::WriteRValueToBuffer(RValue*, Buffer_Standard*)
 * 字段偏移 top8: 0x4×5 / 0x2c×3 / 0xc×2 / 0x38×2 / 0x30×2 / 0x8×2 / 0x2×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xdb3b0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xdb3b4 sub sp, sp, #20
 *   @0xdb3b8 mov r4, r0
 *   @0xdb3bc add r0, sp, #12
 *   @0xdb3c0 mov r5, r1
 *   @0xdb3c4 str r2, [sp, #0x4]
 *   @0xdb3c8 bl 0x100244 <_Z20GetThePriorityQueuesRi>
 *   @0xdb3cc cmp r5, #0
 *   @0xdb3d0 blt 0xdb474 <_ZN2VM13GetDSPriorityEP15Buffer_Standardii+0xc4>
 *   @0xdb3d4 ldr r3, [sp, #0xc]
 *   @0xdb3d8 cmp r5, r3
 *   @0xdb3dc bge 0xdb474 <_ZN2VM13GetDSPriorityEP15Buffer_Standardii+0xc4>
 *   @0xdb3e0 ldr r8, [r0, r5, lsl #2]
 *   @0xdb3e4 cmp r8, #0
 *   @0xdb3e8 beq 0xdb474 <_ZN2VM13GetDSPriorityEP15Buffer_Standardii+0xc4>
 *   @0xdb3ec mov r0, r4
 *   @0xdb3f0 ldr r1, [r8, #0x4]
 *   @0xdb3f4 add r2, sp, #4
 *   @0xdb3f8 bl 0xdb080 <_ZN2VM16WriteDSSizeCountEP15Buffer_StandardiRi>
 *   @0xdb3fc subs r9, r0, #0
 *   @0xdb400 ble 0xdb46c <_ZN2VM13GetDSPriorityEP15Buffer_Standardii+0xbc>
 *   @0xdb404 mov r5, #0
 *   @0xdb408 add r11, r4, #44
 *   @0xdb40c mov r10, r5
 *   @0xdb410 ldr r6, [sp, #0x4]
 *   @0xdb414 mov r1, r4
 *   @0xdb418 ldr r0, [r8, #0xc]
 *   @0xdb41c add r6, r5, r6
 *   @0xdb420 add r5, r5, #1
 *   @0xdb424 lsl r7, r6, #4
 *   @0xdb428 add r0, r0, r7
 *   @0xdb42c bl 0xd8a88 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard>
 *   @0xdb430 ldr r3, [r8, #0x14]
 *   @0xdb434 ldr r12, [r4]
 *   @0xdb438 mov r0, r4
 *   @0xdb43c add r7, r3, r7
 *   @0xdb440 mov r1, #9
 *   @0xdb444 ldr lr, [r3, r6, lsl #4]
 *   @0xdb448 mov r2, r11
 *   @0xdb44c ldr r3, [r7, #0x4]
 *   @0xdb450 str r10, [r4, #0x38]
 *   @0xdb454 str lr, [r4, #0x2c]
 *   @0xdb458 str r3, [r4, #0x30]
 *   @0xdb45c ldr r3, [r12, #0x8]
 *   @0xdb460 blx r3
 *   @0xdb464 cmp r5, r9
 *   @0xdb468 bne 0xdb410 <_ZN2VM13GetDSPriorityEP15Buffer_Standardii+0x60>
 *   @0xdb46c add sp, sp, #20
 *   @0xdb470 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xdb474 mov r2, r4
 *   @0xdb478 mov r1, #0
 *   @0xdb47c ldr r0, [r2], #44
 *   @0xdb480 movt r1, #0xffe0
 *   @0xdb484 movw r3, #0xffff
 *   @0xdb488 str r1, [r4, #0x2c]
 *   @0xdb48c movt r3, #0x41ef
 *   @0xdb490 mov r1, #0
 *   @0xdb494 str r3, [r4, #0x30]
 *   @0xdb498 ldr r3, [r0, #0x8]
 *   @0xdb49c mov r0, r4
 *   @0xdb4a0 str r1, [r4, #0x38]
 *   @0xdb4a4 mov r1, #5
 *   @0xdb4a8 blx r3
 *   @0xdb4ac add sp, sp, #20
 *   @0xdb4b0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §23/119 YYGML_ds_grid_get(int, int, int)  0x1003e8  size 260  65 条（0x1003e8..0x1004ec）
 * @func 0x1003e8 0x1004ec  size 260  65 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1003ec→0x479a24, 0x100418→0x483694, 0x10042c→0x483698, 0x100458→0x3eb708, 0x100490→0x483698
 * 调用序列: YYGML_ds_grid_get(int, int, int)+0xd0 / YYGML_ds_grid_get(int, int, int)+0xb0 / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x4×3 / 0xe0×2 / 0x2×2 / 0xb8×1 / 0xa8×1 / 0x80×1 / 0x78×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1003e8 ldr r12, [pc, #0xe0]
 *   @0x1003ec ldr r3, [pc, #0xe0]
 *   @0x1003f0 add r12, pc, r12
 *   @0x1003f4 push {r4, r5, r6, r7, lr}
 *   @0x1003f8 mov r5, r2
 *   @0x1003fc ldr r3, [r12, r3]
 *   @0x100400 sub sp, sp, #20
 *   @0x100404 ldrb r3, [r3]
 *   @0x100408 cmp r3, #0
 *   @0x10040c beq 0x100490 <_Z17YYGML_ds_grid_getiii+0xa8>
 *   @0x100410 cmp r0, #0
 *   @0x100414 blt 0x1004b8 <_Z17YYGML_ds_grid_getiii+0xd0>
 *   @0x100418 ldr r3, [pc, #0xb8]
 *   @0x10041c ldr r3, [r12, r3]
 *   @0x100420 ldr r3, [r3]
 *   @0x100424 cmp r0, r3
 *   @0x100428 bge 0x1004b8 <_Z17YYGML_ds_grid_getiii+0xd0>
 *   @0x10042c ldr r3, [pc, #0xa8]
 *   @0x100430 ldr r3, [r12, r3]
 *   @0x100434 ldr r2, [r3, #0x4]
 *   @0x100438 ldr r4, [r2, r0, lsl #2]
 *   @0x10043c cmp r4, #0
 *   @0x100440 beq 0x1004b8 <_Z17YYGML_ds_grid_getiii+0xd0>
 *   @0x100444 ldmib r4, {r6, r7}
 *   @0x100448 cmp r1, r6
 *   @0x10044c bhs 0x100458 <_Z17YYGML_ds_grid_getiii+0x70>
 *   @0x100450 cmp r5, r7
 *   @0x100454 blo 0x100498 <_Z17YYGML_ds_grid_getiii+0xb0>
 *   @0x100458 ldr lr, [pc, #0x80]
 *   @0x10045c mov r2, r0
 *   @0x100460 mov r3, r1
 *   @0x100464 ldr r1, [pc, #0x78]
 *   @0x100468 ldr r0, [r12, lr]
 *   @0x10046c add r1, pc, r1
 *   @0x100470 ldr r0, [r0]
 *   @0x100474 ldr r12, [r0]
 *   @0x100478 stm sp, {r5, r6, r7}
 *   @0x10047c ldr r12, [r12, #0xc]
 *   @0x100480 blx r12
 *   @0x100484 ldr r0, [r4]
 *   @0x100488 add sp, sp, #20
 *   @0x10048c pop {r4, r5, r6, r7, pc}
 *   @0x100490 ldr r3, [pc, #0x44]
 *   @0x100494 ldr r3, [r12, r3]
 *   @0x100498 ldr r3, [r3, #0x4]
 *   @0x10049c ldr r3, [r3, r0, lsl #2]
 *   @0x1004a0 ldr r0, [r3, #0x4]
 *   @0x1004a4 ldr r3, [r3]
 *   @0x1004a8 mla r1, r0, r5, r1
 *   @0x1004ac add r0, r3, r1, lsl #4
 *   @0x1004b0 add sp, sp, #20
 *   @0x1004b4 pop {r4, r5, r6, r7, pc}
 *   @0x1004b8 ldr r0, [pc, #0x28]
 *   @0x1004bc mov r1, #0
 *   @0x1004c0 add r0, pc, r0
 *   @0x1004c4 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1004c8 mov r0, #0
 *   @0x1004cc b 0x100488 <_Z17YYGML_ds_grid_getiii+0xa0>
 *   @0x1004d0 eoreq r1, pc, r0, ror #16
 *   @0x1004d4 .word 0xffffc240
 *   @0x1004d8 .word 0xffffc234
 *   @0x1004dc .word 0xffffc238
 *   @0x1004e0 .word 0xffffbcf0
 *   @0x1004e4 eoreq r7, r3, r12, lsl #17
 *   @0x1004e8 eoreq r7, r3, r12, lsr r7
 *
 * ══ §24/119 F_ExternalDefine2(RValue&, CInstance*, CInstance*, int, RValue*)  0x116034  size 260  65 条（0x116034..0x116138）
 * @func 0x116034 0x116138  size 260  65 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / YYGetString(RValue const*, int)×2 / 0xb65b0 / DLL_Define(char const*, char const*, int, int, int*, int) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x70×1 / 0x4×1 / 0xc×1 / 0x10×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x116034 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x116038 sub sp, sp, #80
 *   @0x11603c add r5, sp, #12
 *   @0x116040 mov r2, #68
 *   @0x116044 ldr r4, [sp, #0x70]
 *   @0x116048 mov r6, r0
 *   @0x11604c mov r1, #0
 *   @0x116050 mov r0, r5
 *   @0x116054 bl 0xb65b0 <memset@plt>
 *   @0x116058 mov r1, #0
 *   @0x11605c mov r0, r4
 *   @0x116060 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x116064 mov r1, #1
 *   @0x116068 mov r10, r0
 *   @0x11606c mov r0, r4
 *   @0x116070 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x116074 mov r1, #2
 *   @0x116078 mov r9, r0
 *   @0x11607c mov r0, r4
 *   @0x116080 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x116084 mov r1, #3
 *   @0x116088 mov r8, r0
 *   @0x11608c mov r0, r4
 *   @0x116090 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x116094 mov r1, #4
 *   @0x116098 mov r7, r0
 *   @0x11609c mov r0, r4
 *   @0x1160a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1160a4 cmp r8, #1
 *   @0x1160a8 streq r8, [sp, #0xc]
 *   @0x1160ac mov r1, r9
 *   @0x1160b0 movne r3, #0
 *   @0x1160b4 str r5, [sp]
 *   @0x1160b8 strne r3, [sp, #0xc]
 *   @0x1160bc cmp r7, #1
 *   @0x1160c0 streq r7, [sp, #0x10]
 *   @0x1160c4 mov r7, #0
 *   @0x1160c8 movne r3, #0
 *   @0x1160cc strne r3, [sp, #0x10]
 *   @0x1160d0 subs r2, r0, #1
 *   @0x1160d4 mov r0, r10
 *   @0x1160d8 rsbs r3, r2, #0
 *   @0x1160dc adcs r3, r3, r2
 *   @0x1160e0 mov r2, r7
 *   @0x1160e4 str r3, [sp, #0x4]
 *   @0x1160e8 mov r3, #2
 *   @0x1160ec str r7, [r6, #0xc]
 *   @0x1160f0 bl 0x2148fc <_Z10DLL_DefinePKcS0_iiPii>
 *   @0x1160f4 vmov.f64 d7, #-1.000000e+00
 *   @0x1160f8 vmov s13, r0
 *   @0x1160fc vcvt.f64.s32 d6, s13
 *   @0x116100 vmov r0, r1, d6
 *   @0x116104 vmov r2, s12
 *   @0x116108 vcmp.f64 d6, d7
 *   @0x11610c vmrs APSR_nzcv, fpscr
 *   @0x116110 mov r3, r1
 *   @0x116114 stm r6, {r2, r3}
 *   @0x116118 bne 0x11612c <_Z17F_ExternalDefine2R6RValueP9CInstanceS2_iPS_+0xf8>
 *   @0x11611c ldr r0, [pc, #0x10]
 *   @0x116120 mov r1, r7
 *   @0x116124 add r0, pc, r0
 *   @0x116128 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x11612c add sp, sp, #80
 *   @0x116130 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x116134 eoreq r3, r2, r12, ror r5
 *
 * ══ §25/119 F_DateGetSecondOfYear(RValue&, CInstance*, CInstance*, int, RValue*)  0x118618  size 260  65 条（0x118618..0x11871c）
 * @func 0x118618 0x11871c  size 260  65 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int) / __fixdfdi / 0xb6820 / GetSecondOfYear(int, int, int, int, int, int) / 0xb682c / 0x8293c4
 * 字段偏移 top8: 0x4×3 / 0xc×2 / 0x18×1 / 0x9c×1 / 0x14×1 / 0x10×1 / 0x8×1
 * VFP 指令 15 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x118618 push {r4, lr}
 *   @0x11861c sub sp, sp, #16
 *   @0x118620 mov r3, #0
 *   @0x118624 mov r4, r0
 *   @0x118628 str r3, [r0, #0xc]
 *   @0x11862c mov r1, r3
 *   @0x118630 str r3, [r0]
 *   @0x118634 str r3, [r0, #0x4]
 *   @0x118638 ldr r0, [sp, #0x18]
 *   @0x11863c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x118640 vldr d7, [pc, #184]
 *   @0x118644 vldr d5, [pc, #188]
 *   @0x118648 vmov d6, r0, r1
 *   @0x11864c vsub.f64 d7, d6, d7
 *   @0x118650 vabs.f64 d4, d7
 *   @0x118654 vcmpe.f64 d4, d5
 *   @0x118658 vmrs APSR_nzcv, fpscr
 *   @0x11865c vldrls d7, [pc, #172]
 *   @0x118660 vldrhi d6, [pc, #168]
 *   @0x118664 vmul.f64 d5, d7, d6
 *   @0x118668 vmov r0, r1, d5
 *   @0x11866c bl 0x3194a0 <__fixdfdi>
 *   @0x118670 mov r3, r1
 *   @0x118674 ldr r1, [pc, #0x9c]
 *   @0x118678 mov r2, r0
 *   @0x11867c strd r2, r3, [sp, #8]
 *   @0x118680 add r1, pc, r1
 *   @0x118684 add r0, sp, #8
 *   @0x118688 ldrb r3, [r1]
 *   @0x11868c cmp r3, #0
 *   @0x118690 bne 0x1186f4 <_Z21F_DateGetSecondOfYearR6RValueP9CInstanceS2_iPS_+0xdc>
 *   @0x118694 bl 0xb6820 <gmtime64@plt>
 *   @0x118698 mov r12, r0
 *   @0x11869c cmp r12, #0
 *   @0x1186a0 beq 0x1186ec <_Z21F_DateGetSecondOfYearR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0x1186a4 ldr lr, [r12, #0x4]
 *   @0x1186a8 ldr r0, [r12, #0x14]
 *   @0x1186ac ldr r1, [r12, #0x10]
 *   @0x1186b0 ldr r2, [r12, #0xc]
 *   @0x1186b4 add r0, r0, #1888
 *   @0x1186b8 ldr r3, [r12, #0x8]
 *   @0x1186bc add r1, r1, #1
 *   @0x1186c0 str lr, [sp]
 *   @0x1186c4 add r0, r0, #12
 *   @0x1186c8 ldr r12, [r12]
 *   @0x1186cc str r12, [sp, #0x4]
 *   @0x1186d0 bl 0x1180c0 <_Z15GetSecondOfYeariiiiii>
 *   @0x1186d4 vmov s15, r0
 *   @0x1186d8 vcvt.f64.s32 d7, s15
 *   @0x1186dc vmov r0, r1, d7
 *   @0x1186e0 vmov r2, s14
 *   @0x1186e4 mov r3, r1
 *   @0x1186e8 stm r4, {r2, r3}
 *   @0x1186ec add sp, sp, #16
 *   @0x1186f0 pop {r4, pc}
 *   @0x1186f4 bl 0xb682c <localtime64@plt>
 *   @0x1186f8 mov r12, r0
 *   @0x1186fc b 0x11869c <_Z21F_DateGetSecondOfYearR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x118700 andeq r0, r0, r0
 *   @0x118704 sbcsmi pc, r8, r0, asr #16
 *   @0x118708 bl 0x8293c4 <b2_toiTime+0xcff20>
 *   @0x11870c svclo #0x1a36e2
 *   @0x118710 andeq r0, r0, r0
 *   @0x118714 rscsmi r1, r5, r0, lsl #16
 *   @0x118718 .word 0x002d9ab8
 *
 * ══ §26/119 F_SoundEffectEcho(RValue&, CInstance*, CInstance*, int, RValue*)  0x1340bc  size 260  65 条（0x1340bc..0x1341c0）
 * @func 0x1340bc 0x1341c0  size 260  65 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×4 / YYGetInt32(RValue const*, int)×2 / Sound_Data(int) / CSound::GetSoundId() / SND_Set_Effect_Echo(int, double, double, double, double, int)
 * 字段偏移 top8: 0x24×2 / 0x20×2 / 0xf0×1 / 0x50×1 / 0xd4×1 / 0x18×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1340bc ldr r3, [pc, #0xf0]
 *   @0x1340c0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1340c4 ldr r3, [pc, r3]
 *   @0x1340c8 sub sp, sp, #44
 *   @0x1340cc ldrb r3, [r3]
 *   @0x1340d0 ldr r10, [sp, #0x50]
 *   @0x1340d4 cmp r3, #0
 *   @0x1340d8 bne 0x1340f0 <_Z17F_SoundEffectEchoR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x1340dc ldr r3, [pc, #0xd4]
 *   @0x1340e0 ldr r3, [pc, r3]
 *   @0x1340e4 ldrb r1, [r3]
 *   @0x1340e8 cmp r1, #0
 *   @0x1340ec beq 0x1340f8 <_Z17F_SoundEffectEchoR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1340f0 add sp, sp, #44
 *   @0x1340f4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1340f8 mov r0, r10
 *   @0x1340fc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x134100 bl 0x21fcd4 <_Z10Sound_Datai>
 *   @0x134104 subs r1, r0, #0
 *   @0x134108 beq 0x1341a0 <_Z17F_SoundEffectEchoR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0x13410c bl 0x215748 <_ZN6CSound10GetSoundIdEv>
 *   @0x134110 mov r1, #1
 *   @0x134114 mov r11, r0
 *   @0x134118 mov r0, r10
 *   @0x13411c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x134120 mov r2, r0
 *   @0x134124 mov r3, r1
 *   @0x134128 mov r0, r10
 *   @0x13412c mov r1, #2
 *   @0x134130 str r2, [sp, #0x24]
 *   @0x134134 str r3, [sp, #0x20]
 *   @0x134138 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x13413c mov r8, r0
 *   @0x134140 mov r9, r1
 *   @0x134144 mov r0, r10
 *   @0x134148 mov r1, #3
 *   @0x13414c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x134150 mov r6, r0
 *   @0x134154 mov r7, r1
 *   @0x134158 mov r0, r10
 *   @0x13415c mov r1, #4
 *   @0x134160 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x134164 mov r4, r0
 *   @0x134168 mov r5, r1
 *   @0x13416c mov r0, r10
 *   @0x134170 mov r1, #5
 *   @0x134174 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x134178 strd r8, r9, [sp]
 *   @0x13417c strd r6, r7, [sp, #8]
 *   @0x134180 strd r4, r5, [sp, #16]
 *   @0x134184 ldr r2, [sp, #0x24]
 *   @0x134188 ldr r3, [sp, #0x20]
 *   @0x13418c str r0, [sp, #0x18]
 *   @0x134190 mov r0, r11
 *   @0x134194 bl 0x21f134 <_Z19SND_Set_Effect_Echoiddddi>
 *   @0x134198 add sp, sp, #44
 *   @0x13419c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1341a0 ldr r0, [pc, #0x14]
 *   @0x1341a4 add r0, pc, r0
 *   @0x1341a8 add sp, sp, #44
 *   @0x1341ac pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1341b0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1341b4 eoreq r10, r11, r12, ror #24
 *   @0x1341b8 eoreq r10, r11, r12, ror #30
 *   @0x1341bc eoreq r11, r0, r8, ror #5
 *
 * ══ §27/119 F_Sound3DSetSoundCone(RValue&, CInstance*, CInstance*, int, RValue*)  0x136338  size 260  65 条（0x136338..0x13643c）
 * @func 0x136338 0x13643c  size 260  65 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×4 / YYGetInt32(RValue const*, int)×3 / Sound_Data(int) / CSound::GetSoundId() / SND_3D_Set_Sound_Cone(int, double, double, double, int, int, double)
 * 字段偏移 top8: 0x20×2 / 0x24×2 / 0x10×2 / 0xf4×1 / 0x50×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x136338 ldr r3, [pc, #0xf4]
 *   @0x13633c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x136340 ldr r3, [pc, r3]
 *   @0x136344 sub sp, sp, #44
 *   @0x136348 ldrb r1, [r3]
 *   @0x13634c ldr r10, [sp, #0x50]
 *   @0x136350 cmp r1, #0
 *   @0x136354 beq 0x136360 <_Z21F_Sound3DSetSoundConeR6RValueP9CInstanceS2_iPS_+0x28>
 *   @0x136358 add sp, sp, #44
 *   @0x13635c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x136360 mov r0, r10
 *   @0x136364 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x136368 bl 0x21fcd4 <_Z10Sound_Datai>
 *   @0x13636c subs r1, r0, #0
 *   @0x136370 beq 0x136420 <_Z21F_Sound3DSetSoundConeR6RValueP9CInstanceS2_iPS_+0xe8>
 *   @0x136374 bl 0x215748 <_ZN6CSound10GetSoundIdEv>
 *   @0x136378 mov r1, #1
 *   @0x13637c mov r11, r0
 *   @0x136380 mov r0, r10
 *   @0x136384 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x136388 mov r4, r0
 *   @0x13638c mov r5, r1
 *   @0x136390 mov r0, r10
 *   @0x136394 mov r1, #2
 *   @0x136398 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x13639c mov r8, r0
 *   @0x1363a0 mov r9, r1
 *   @0x1363a4 mov r0, r10
 *   @0x1363a8 mov r1, #3
 *   @0x1363ac bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x1363b0 mov r6, r0
 *   @0x1363b4 mov r7, r1
 *   @0x1363b8 mov r0, r10
 *   @0x1363bc mov r1, #4
 *   @0x1363c0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1363c4 mov r1, #5
 *   @0x1363c8 mov r2, r0
 *   @0x1363cc mov r0, r10
 *   @0x1363d0 str r2, [sp, #0x20]
 *   @0x1363d4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1363d8 mov r1, #6
 *   @0x1363dc mov r3, r0
 *   @0x1363e0 mov r0, r10
 *   @0x1363e4 str r3, [sp, #0x24]
 *   @0x1363e8 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x1363ec ldr r2, [sp, #0x20]
 *   @0x1363f0 ldr r3, [sp, #0x24]
 *   @0x1363f4 strd r8, r9, [sp]
 *   @0x1363f8 str r2, [sp, #0x10]
 *   @0x1363fc mov r2, r4
 *   @0x136400 str r3, [sp, #0x14]
 *   @0x136404 mov r3, r5
 *   @0x136408 strd r6, r7, [sp, #8]
 *   @0x13640c strd r0, r1, [sp, #24]
 *   @0x136410 mov r0, r11
 *   @0x136414 bl 0x21f178 <_Z21SND_3D_Set_Sound_Coneidddiid>
 *   @0x136418 add sp, sp, #44
 *   @0x13641c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x136420 ldr r0, [pc, #0x10]
 *   @0x136424 add r0, pc, r0
 *   @0x136428 add sp, sp, #44
 *   @0x13642c pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x136430 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x136434 eoreq r8, r11, r12, lsl #26
 *   @0x136438 eoreq r9, r0, r8, rrx
 *
 * ══ §28/119 GR_Texture_Create_Bytes(int, int, DynamicArrayOfByte*)  0x173fdc  size 260  65 条（0x173fdc..0x1740e0）
 * @func 0x173fdc 0x1740e0  size 260  65 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool) / GR_Texture_Create_Bytes(int, int, DynamicArrayOfByte*)+0xac / GR_Texture_Create_Bytes(int, int, DynamicArrayOfByte*)+0x98 / GR_Texture_Create_Empty(int, int, bool, bool, int) / GR_Texture_Fill(int, TDWordArray*) / MemoryManager::Free(void const*) / GR_Texture_Free(int)
 * 字段偏移 top8: 0xc×3 / 0x8×2 / 0x4×2 / 0xec×1 / 0x1×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x173fdc push {r4, r5, r6, r7, r8, lr}
 *   @0x173fe0 mov r6, r1
 *   @0x173fe4 mul r8, r1, r0
 *   @0x173fe8 ldr r1, [pc, #0xec]
 *   @0x173fec sub sp, sp, #16
 *   @0x173ff0 mov r5, r0
 *   @0x173ff4 mov r7, r2
 *   @0x173ff8 add r1, pc, r1
 *   @0x173ffc movw r2, #0x1dd
 *   @0x174000 mov r3, #1
 *   @0x174004 mov r4, #0
 *   @0x174008 str r4, [sp, #0x8]
 *   @0x17400c lsl r8, r8, #2
 *   @0x174010 str r4, [sp, #0xc]
 *   @0x174014 mov r0, r8
 *   @0x174018 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x17401c cmp r6, r4
 *   @0x174020 str r8, [sp, #0x8]
 *   @0x174024 str r0, [sp, #0xc]
 *   @0x174028 ble 0x174088 <_Z23GR_Texture_Create_BytesiiP18DynamicArrayOfByte+0xac>
 *   @0x17402c sub r0, r0, #4
 *   @0x174030 lsl r8, r5, #2
 *   @0x174034 mov r2, r4
 *   @0x174038 mov r1, r4
 *   @0x17403c cmp r5, #0
 *   @0x174040 ble 0x174074 <_Z23GR_Texture_Create_BytesiiP18DynamicArrayOfByte+0x98>
 *   @0x174044 ldr r12, [r7, #0x4]
 *   @0x174048 mov lr, r0
 *   @0x17404c add r4, r12, r5
 *   @0x174050 add r12, r12, r2
 *   @0x174054 add r4, r4, r2
 *   @0x174058 ldrb r3, [r12], #1
 *   @0x17405c cmp r12, r4
 *   @0x174060 lsl r3, r3, #24
 *   @0x174064 add r3, r3, #16777216
 *   @0x174068 sub r3, r3, #1
 *   @0x17406c str r3, [lr, #0x4]!
 *   @0x174070 bne 0x174058 <_Z23GR_Texture_Create_BytesiiP18DynamicArrayOfByte+0x7c>
 *   @0x174074 add r1, r1, #1
 *   @0x174078 add r0, r0, r8
 *   @0x17407c cmp r1, r6
 *   @0x174080 add r2, r2, r5
 *   @0x174084 bne 0x17403c <_Z23GR_Texture_Create_BytesiiP18DynamicArrayOfByte+0x60>
 *   @0x174088 mov r2, #0
 *   @0x17408c mov r12, #4
 *   @0x174090 mov r1, r6
 *   @0x174094 mov r3, r2
 *   @0x174098 str r12, [sp]
 *   @0x17409c mov r0, r5
 *   @0x1740a0 bl 0x173a24 <_Z23GR_Texture_Create_Emptyiibbi>
 *   @0x1740a4 add r1, sp, #8
 *   @0x1740a8 mov r4, r0
 *   @0x1740ac bl 0x173d70 <_Z15GR_Texture_FilliP11TDWordArray>
 *   @0x1740b0 cmp r0, #0
 *   @0x1740b4 beq 0x1740cc <_Z23GR_Texture_Create_BytesiiP18DynamicArrayOfByte+0xf0>
 *   @0x1740b8 ldr r0, [sp, #0xc]
 *   @0x1740bc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1740c0 mov r0, r4
 *   @0x1740c4 add sp, sp, #16
 *   @0x1740c8 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1740cc mov r0, r4
 *   @0x1740d0 mvn r4, #0
 *   @0x1740d4 bl 0x173f84 <_Z15GR_Texture_Freei>
 *   @0x1740d8 b 0x1740b8 <_Z23GR_Texture_Create_BytesiiP18DynamicArrayOfByte+0xdc>
 *   @0x1740dc andseq r7, sp, r12, lsl r5
 *
 * ══ §29/119 iCadeSetButtonState(int, bool)  0x1908f0  size 260  65 条（0x1908f0..0x1909f4）
 * @func 0x1908f0 0x1909f4  size 260  65 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xac×1 / 0x88×1 / 0x64×1 / 0x40×1 / 0x28×1
 * VFP 指令 20 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1908f0 vmov.f32 s15, #1.000000e+00
 *   @0x1908f4 cmp r1, #0
 *   @0x1908f8 sub r3, r0, #8
 *   @0x1908fc vldr s14, [pc, #216]
 *   @0x190900 vmoveq.f32 s15, s14
 *   @0x190904 cmp r3, #3
 *   @0x190908 addls pc, pc, r3, lsl #2
 *   @0x19090c b 0x1909c0 <_Z19iCadeSetButtonStateib+0xd0>
 *   @0x190910 b 0x190970 <_Z19iCadeSetButtonStateib+0x80>
 *   @0x190914 b 0x190998 <_Z19iCadeSetButtonStateib+0xa8>
 *   @0x190918 b 0x190948 <_Z19iCadeSetButtonStateib+0x58>
 *   @0x19091c b 0x190920 <_Z19iCadeSetButtonStateib+0x30>
 *   @0x190920 cmp r1, #0
 *   @0x190924 bne 0x190950 <_Z19iCadeSetButtonStateib+0x60>
 *   @0x190928 vmov.f32 s15, #1.000000e+00
 *   @0x19092c ldr r3, [pc, #0xac]
 *   @0x190930 add r3, pc, r3
 *   @0x190934 sub r3, r3, #2736
 *   @0x190938 vldr s14, [r3, #-8]
 *   @0x19093c vadd.f32 s15, s14, s15
 *   @0x190940 vstr s15, [r3, #-8]
 *   @0x190944 bx lr
 *   @0x190948 cmp r1, #0
 *   @0x19094c bne 0x190928 <_Z19iCadeSetButtonStateib+0x38>
 *   @0x190950 vmov.f32 s15, #1.000000e+00
 *   @0x190954 ldr r3, [pc, #0x88]
 *   @0x190958 add r3, pc, r3
 *   @0x19095c sub r3, r3, #2736
 *   @0x190960 vldr s14, [r3, #-8]
 *   @0x190964 vsub.f32 s15, s14, s15
 *   @0x190968 vstr s15, [r3, #-8]
 *   @0x19096c bx lr
 *   @0x190970 cmp r1, #0
 *   @0x190974 beq 0x1909a0 <_Z19iCadeSetButtonStateib+0xb0>
 *   @0x190978 vmov.f32 s15, #1.000000e+00
 *   @0x19097c ldr r3, [pc, #0x64]
 *   @0x190980 add r3, pc, r3
 *   @0x190984 sub r3, r3, #2736
 *   @0x190988 vldr s14, [r3, #-12]
 *   @0x19098c vsub.f32 s15, s14, s15
 *   @0x190990 vstr s15, [r3, #-12]
 *   @0x190994 bx lr
 *   @0x190998 cmp r1, #0
 *   @0x19099c beq 0x190978 <_Z19iCadeSetButtonStateib+0x88>
 *   @0x1909a0 vmov.f32 s15, #1.000000e+00
 *   @0x1909a4 ldr r3, [pc, #0x40]
 *   @0x1909a8 add r3, pc, r3
 *   @0x1909ac sub r3, r3, #2736
 *   @0x1909b0 vldr s14, [r3, #-12]
 *   @0x1909b4 vadd.f32 s15, s14, s15
 *   @0x1909b8 vstr s15, [r3, #-12]
 *   @0x1909bc bx lr
 *   @0x1909c0 ldr r3, [pc, #0x28]
 *   @0x1909c4 add r3, pc, r3
 *   @0x1909c8 sub r3, r3, #2768
 *   @0x1909cc sub r3, r3, #12
 *   @0x1909d0 add r0, r3, r0, lsl #2
 *   @0x1909d4 vstr s15, [r0]
 *   @0x1909d8 bx lr
 *   @0x1909dc andeq r0, r0, r0
 *   @0x1909e0 ldrshteq r6, [r10], -r0
 *   @0x1909e4 eorseq r6, r10, r8, asr #29
 *   @0x1909e8 eorseq r6, r10, r0, lsr #29
 *   @0x1909ec eorseq r6, r10, r8, ror lr
 *   @0x1909f0 eorseq r6, r10, r12, asr lr
 *
 * ══ §30/119 Path_Add()  0x1a819c  size 260  65 条（0x1a819c..0x1a82a0）
 * @func 0x1a819c 0x1a82a0  size 260  65 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::SetLength(void**, unsigned int, char const*, int)×2 / 0xb65c8 / YYStrDup(char const*) / operator new(unsigned int) / CPath::CPath() / 0xb65d4
 * 字段偏移 top8: 0x104×2 / 0x2×2 / 0xdc×1 / 0xd8×1 / 0xd4×1 / 0xd0×1 / 0xb4×1 / 0x7c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a819c push {r4, r5, r6, r7, r8, lr}
 *   @0x1a81a0 sub sp, sp, #264
 *   @0x1a81a4 ldr r4, [pc, #0xdc]
 *   @0x1a81a8 movw r3, #0x112
 *   @0x1a81ac ldr r5, [pc, #0xd8]
 *   @0x1a81b0 ldr r4, [pc, r4]
 *   @0x1a81b4 ldr r8, [pc, #0xd4]
 *   @0x1a81b8 ldr r5, [pc, r5]
 *   @0x1a81bc ldr r7, [pc, #0xd0]
 *   @0x1a81c0 ldr r12, [r4]
 *   @0x1a81c4 add r8, pc, r8
 *   @0x1a81c8 ldr lr, [r5]
 *   @0x1a81cc add r7, pc, r7
 *   @0x1a81d0 add r12, r12, #1
 *   @0x1a81d4 mov r2, r8
 *   @0x1a81d8 add r0, r7, #4
 *   @0x1a81dc ldr r6, [pc, #0xb4]
 *   @0x1a81e0 lsl r1, r12, #2
 *   @0x1a81e4 str lr, [sp, #0x104]
 *   @0x1a81e8 str r12, [r4]
 *   @0x1a81ec bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1a81f0 ldr r12, [r4]
 *   @0x1a81f4 ldr r6, [pc, r6]
 *   @0x1a81f8 mov r2, r8
 *   @0x1a81fc mov r3, #276
 *   @0x1a8200 mov r0, r6
 *   @0x1a8204 add r8, sp, #4
 *   @0x1a8208 lsl r1, r12, #2
 *   @0x1a820c str r12, [r7]
 *   @0x1a8210 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1a8214 ldr r3, [r4]
 *   @0x1a8218 ldr r2, [pc, #0x7c]
 *   @0x1a821c mov r1, #256
 *   @0x1a8220 mov r0, r8
 *   @0x1a8224 sub r3, r3, #1
 *   @0x1a8228 add r2, pc, r2
 *   @0x1a822c bl 0xb65c8 <snprintf@plt>
 *   @0x1a8230 ldr r3, [r4]
 *   @0x1a8234 mov r0, r8
 *   @0x1a8238 ldr r6, [r6]
 *   @0x1a823c sub r8, r3, #-1073741823
 *   @0x1a8240 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x1a8244 str r0, [r6, r8, lsl #2]
 *   @0x1a8248 mov r0, #44
 *   @0x1a824c bl 0x27c524 <_Znwj>
 *   @0x1a8250 mov r6, r0
 *   @0x1a8254 bl 0x1a6e9c <_ZN5CPathC2Ev>
 *   @0x1a8258 ldr r0, [r4]
 *   @0x1a825c ldr r1, [r7, #0x4]
 *   @0x1a8260 sub r12, r0, #-1073741823
 *   @0x1a8264 ldr r2, [sp, #0x104]
 *   @0x1a8268 sub r0, r0, #1
 *   @0x1a826c str r6, [r1, r12, lsl #2]
 *   @0x1a8270 ldr r3, [r5]
 *   @0x1a8274 cmp r2, r3
 *   @0x1a8278 bne 0x1a8284 <_Z8Path_Addv+0xe8>
 *   @0x1a827c add sp, sp, #264
 *   @0x1a8280 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1a8284 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x1a8288 eoreq r8, r4, r12, lsl r6
 *   @0x1a828c mlaeq r4, r8, r7, r5
 *   @0x1a8290 andseq r4, r10, r8, asr #30
 *   @0x1a8294 eorseq r10, r9, r12, asr r3
 *   @0x1a8298 .word 0x002485dc
 *   @0x1a829c andseq r4, r10, r8, lsl pc
 *
 * ══ §31/119 F_Shader_Set_Uniform_I(RValue&, CInstance*, CInstance*, int, RValue*)  0x1e1740  size 260  63 条（0x1e1740..0x1e1844）
 * @func 0x1e1740 0x1e1844  size 260  63 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×4 / Graphics::Flush() / F_Shader_Set_Uniform_I(RValue&, CInstance*, CInstance*, int, RValue*)+0xa0 / YYGetInt32(RValue const*, int) / Shader_Set_Uniform_I(int, int, double, double, double, double) / FlushShader()
 * 字段偏移 top8: 0x48×1 / 0xe4×1
 * VFP 指令 2 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e1740 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1e1744 sub sp, sp, #36
 *   @0x1e1748 mov r10, r3
 *   @0x1e174c ldr r11, [sp, #0x48]
 *   @0x1e1750 bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x1e1754 ldr r3, [pc, #0xe4]
 *   @0x1e1758 ldr r3, [pc, r3]
 *   @0x1e175c ldrb r3, [r3]
 *   @0x1e1760 cmp r3, #0
 *   @0x1e1764 bne 0x1e182c <_Z22F_Shader_Set_Uniform_IR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0x1e1768 cmp r10, #1
 *   @0x1e176c ble 0x1e17e0 <_Z22F_Shader_Set_Uniform_IR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x1e1770 mov r0, r11
 *   @0x1e1774 mov r1, #1
 *   @0x1e1778 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x1e177c cmp r10, #2
 *   @0x1e1780 strd r0, r1, [sp, #24]
 *   @0x1e1784 beq 0x1e17e8 <_Z22F_Shader_Set_Uniform_IR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0x1e1788 mov r0, r11
 *   @0x1e178c mov r1, #2
 *   @0x1e1790 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x1e1794 cmp r10, #3
 *   @0x1e1798 mov r8, r0
 *   @0x1e179c mov r9, r1
 *   @0x1e17a0 beq 0x1e17f0 <_Z22F_Shader_Set_Uniform_IR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0x1e17a4 mov r0, r11
 *   @0x1e17a8 mov r1, #3
 *   @0x1e17ac bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x1e17b0 cmp r10, #4
 *   @0x1e17b4 moveq r6, #0
 *   @0x1e17b8 moveq r7, #0
 *   @0x1e17bc mov r4, r0
 *   @0x1e17c0 mov r5, r1
 *   @0x1e17c4 beq 0x1e1800 <_Z22F_Shader_Set_Uniform_IR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x1e17c8 mov r0, r11
 *   @0x1e17cc mov r1, #4
 *   @0x1e17d0 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x1e17d4 mov r6, r0
 *   @0x1e17d8 mov r7, r1
 *   @0x1e17dc b 0x1e1800 <_Z22F_Shader_Set_Uniform_IR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x1e17e0 vldr d7, [pc, #80]
 *   @0x1e17e4 vstr d7, [sp, #24]
 *   @0x1e17e8 mov r8, #0
 *   @0x1e17ec mov r9, #0
 *   @0x1e17f0 mov r4, #0
 *   @0x1e17f4 mov r5, #0
 *   @0x1e17f8 mov r6, r4
 *   @0x1e17fc mov r7, r5
 *   @0x1e1800 mov r0, r11
 *   @0x1e1804 mov r1, #0
 *   @0x1e1808 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1e180c strd r8, r9, [sp]
 *   @0x1e1810 strd r4, r5, [sp, #8]
 *   @0x1e1814 sub r1, r10, #1
 *   @0x1e1818 strd r6, r7, [sp, #16]
 *   @0x1e181c ldrd r2, r3, [sp, #24]
 *   @0x1e1820 bl 0x188680 <_Z20Shader_Set_Uniform_Iiidddd>
 *   @0x1e1824 add sp, sp, #36
 *   @0x1e1828 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1e182c bl 0x1e1520 <_Z11FlushShaderv>
 *   @0x1e1830 b 0x1e1768 <_Z22F_Shader_Set_Uniform_IR6RValueP9CInstanceS2_iPS_+0x28>
 *   @0x1e1834 nop
 *   @0x1e1840 .word 0x0020f5f4
 *
 * ══ §32/119 F_Shader_Set_Uniform_F(RValue&, CInstance*, CInstance*, int, RValue*)  0x1e1958  size 260  63 条（0x1e1958..0x1e1a5c）
 * @func 0x1e1958 0x1e1a5c  size 260  63 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×4 / Graphics::Flush() / F_Shader_Set_Uniform_F(RValue&, CInstance*, CInstance*, int, RValue*)+0xa0 / YYGetInt32(RValue const*, int) / Shader_Set_Uniform_F(int, int, double, double, double, double) / FlushShader()
 * 字段偏移 top8: 0x48×1 / 0xe4×1
 * VFP 指令 2 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e1958 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1e195c sub sp, sp, #36
 *   @0x1e1960 mov r10, r3
 *   @0x1e1964 ldr r11, [sp, #0x48]
 *   @0x1e1968 bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x1e196c ldr r3, [pc, #0xe4]
 *   @0x1e1970 ldr r3, [pc, r3]
 *   @0x1e1974 ldrb r3, [r3]
 *   @0x1e1978 cmp r3, #0
 *   @0x1e197c bne 0x1e1a44 <_Z22F_Shader_Set_Uniform_FR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0x1e1980 cmp r10, #1
 *   @0x1e1984 ble 0x1e19f8 <_Z22F_Shader_Set_Uniform_FR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x1e1988 mov r0, r11
 *   @0x1e198c mov r1, #1
 *   @0x1e1990 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x1e1994 cmp r10, #2
 *   @0x1e1998 strd r0, r1, [sp, #24]
 *   @0x1e199c beq 0x1e1a00 <_Z22F_Shader_Set_Uniform_FR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0x1e19a0 mov r0, r11
 *   @0x1e19a4 mov r1, #2
 *   @0x1e19a8 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x1e19ac cmp r10, #3
 *   @0x1e19b0 mov r8, r0
 *   @0x1e19b4 mov r9, r1
 *   @0x1e19b8 beq 0x1e1a08 <_Z22F_Shader_Set_Uniform_FR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0x1e19bc mov r0, r11
 *   @0x1e19c0 mov r1, #3
 *   @0x1e19c4 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x1e19c8 cmp r10, #4
 *   @0x1e19cc moveq r6, #0
 *   @0x1e19d0 moveq r7, #0
 *   @0x1e19d4 mov r4, r0
 *   @0x1e19d8 mov r5, r1
 *   @0x1e19dc beq 0x1e1a18 <_Z22F_Shader_Set_Uniform_FR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x1e19e0 mov r0, r11
 *   @0x1e19e4 mov r1, #4
 *   @0x1e19e8 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x1e19ec mov r6, r0
 *   @0x1e19f0 mov r7, r1
 *   @0x1e19f4 b 0x1e1a18 <_Z22F_Shader_Set_Uniform_FR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x1e19f8 vldr d7, [pc, #80]
 *   @0x1e19fc vstr d7, [sp, #24]
 *   @0x1e1a00 mov r8, #0
 *   @0x1e1a04 mov r9, #0
 *   @0x1e1a08 mov r4, #0
 *   @0x1e1a0c mov r5, #0
 *   @0x1e1a10 mov r6, r4
 *   @0x1e1a14 mov r7, r5
 *   @0x1e1a18 mov r0, r11
 *   @0x1e1a1c mov r1, #0
 *   @0x1e1a20 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1e1a24 strd r8, r9, [sp]
 *   @0x1e1a28 strd r4, r5, [sp, #8]
 *   @0x1e1a2c sub r1, r10, #1
 *   @0x1e1a30 strd r6, r7, [sp, #16]
 *   @0x1e1a34 ldrd r2, r3, [sp, #24]
 *   @0x1e1a38 bl 0x1888f0 <_Z20Shader_Set_Uniform_Fiidddd>
 *   @0x1e1a3c add sp, sp, #36
 *   @0x1e1a40 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1e1a44 bl 0x1e1520 <_Z11FlushShaderv>
 *   @0x1e1a48 b 0x1e1980 <_Z22F_Shader_Set_Uniform_FR6RValueP9CInstanceS2_iPS_+0x28>
 *   @0x1e1a4c nop
 *   @0x1e1a58 .word 0x0020f3dc
 *
 * ══ §33/119 murmurhash(char const*, unsigned int, unsigned int)  0x1eea84  size 260  65 条（0x1eea84..0x1eeb88）
 * @func 0x1eea84 0x1eeb88  size 260  65 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x2×2 / 0x1×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1eea84 push {r4, r5, r6, r7, r8, r9}
 *   @0x1eea88 lsr r8, r1, #2
 *   @0x1eea8c rsb r7, r8, #0
 *   @0x1eea90 cmp r7, #0
 *   @0x1eea94 add r9, r0, r8, lsl #2
 *   @0x1eea98 beq 0x1eeaf0 <_Z10murmurhashPKcjj+0x6c>
 *   @0x1eea9c rsb r6, r7, r7, lsl #30
 *   @0x1eeaa0 movw r5, #0x2d51
 *   @0x1eeaa4 movw r4, #0x3593
 *   @0x1eeaa8 add r7, r9, r7, lsl #2
 *   @0x1eeaac lsl r6, r6, #2
 *   @0x1eeab0 movt r5, #0xcc9e
 *   @0x1eeab4 movt r4, #0x1b87
 *   @0x1eeab8 mov r3, #0
 *   @0x1eeabc ldr r12, [r7, r3]
 *   @0x1eeac0 add r3, r3, #4
 *   @0x1eeac4 cmp r3, r6
 *   @0x1eeac8 mul r12, r5, r12
 *   @0x1eeacc ror r12, r12, #17
 *   @0x1eead0 mul r12, r4, r12
 *   @0x1eead4 eor r12, r2, r12
 *   @0x1eead8 movw r2, #0x6b64
 *   @0x1eeadc movt r2, #0xe654
 *   @0x1eeae0 ror r12, r12, #19
 *   @0x1eeae4 add r12, r12, r12, lsl #2
 *   @0x1eeae8 add r2, r12, r2
 *   @0x1eeaec bne 0x1eeabc <_Z10murmurhashPKcjj+0x38>
 *   @0x1eeaf0 and r3, r1, #3
 *   @0x1eeaf4 cmp r3, #2
 *   @0x1eeaf8 beq 0x1eeb80 <_Z10murmurhashPKcjj+0xfc>
 *   @0x1eeafc cmp r3, #3
 *   @0x1eeb00 beq 0x1eeb6c <_Z10murmurhashPKcjj+0xe8>
 *   @0x1eeb04 cmp r3, #1
 *   @0x1eeb08 beq 0x1eeb3c <_Z10murmurhashPKcjj+0xb8>
 *   @0x1eeb0c eor r2, r2, r1
 *   @0x1eeb10 movw r12, #0xca6b
 *   @0x1eeb14 movt r12, #0x85eb
 *   @0x1eeb18 movw r3, #0xae35
 *   @0x1eeb1c eor r2, r2, r2, lsr #16
 *   @0x1eeb20 movt r3, #0xc2b2
 *   @0x1eeb24 pop {r4, r5, r6, r7, r8, r9}
 *   @0x1eeb28 mul r0, r12, r2
 *   @0x1eeb2c eor r0, r0, r0, lsr #13
 *   @0x1eeb30 mul r0, r3, r0
 *   @0x1eeb34 eor r0, r0, r0, lsr #16
 *   @0x1eeb38 bx lr
 *   @0x1eeb3c mov r4, #0
 *   @0x1eeb40 ldrb r12, [r0, r8, lsl #2]
 *   @0x1eeb44 movw r0, #0x2d51
 *   @0x1eeb48 movt r0, #0xcc9e
 *   @0x1eeb4c movw r3, #0x3593
 *   @0x1eeb50 eor r12, r4, r12
 *   @0x1eeb54 movt r3, #0x1b87
 *   @0x1eeb58 mul r0, r0, r12
 *   @0x1eeb5c ror r0, r0, #17
 *   @0x1eeb60 mul r3, r3, r0
 *   @0x1eeb64 eor r2, r2, r3
 *   @0x1eeb68 b 0x1eeb0c <_Z10murmurhashPKcjj+0x88>
 *   @0x1eeb6c ldrb r4, [r9, #0x2]
 *   @0x1eeb70 lsl r4, r4, #16
 *   @0x1eeb74 ldrb r3, [r9, #0x1]
 *   @0x1eeb78 orr r4, r4, r3, lsl #8
 *   @0x1eeb7c b 0x1eeb40 <_Z10murmurhashPKcjj+0xbc>
 *   @0x1eeb80 mov r4, #0
 *   @0x1eeb84 b 0x1eeb74 <_Z10murmurhashPKcjj+0xf0>
 *
 * ══ §34/119 LoadCSV(char*)  0x213528  size 260  65 条（0x213528..0x21362c）
 * @func 0x213528 0x21362c  size 260  65 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / LoadSave::SaveFileExists(char const*) / LoadSave::ReadSaveFile(char const*, int*) / _CountLinesInText(char*) / _BuildLineList(char*, int) / _GetNumEntriesInLine(char*) / LoadCSV(char*)+0xec / YYGML_ds_grid_create(int, int)
 * 字段偏移 top8: 0x2×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x213528 push {r4, r5, r6, r7, r8, lr}
 *   @0x21352c sub sp, sp, #8
 *   @0x213530 mov r3, #0
 *   @0x213534 mov r4, r0
 *   @0x213538 str r3, [sp]
 *   @0x21353c bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc>
 *   @0x213540 cmp r0, #0
 *   @0x213544 mov r0, r4
 *   @0x213548 beq 0x2135c4 <_Z7LoadCSVPc+0x9c>
 *   @0x21354c mov r1, sp
 *   @0x213550 bl 0x18fb08 <_ZN8LoadSave12ReadSaveFileEPKcPi>
 *   @0x213554 mov r4, r0
 *   @0x213558 mov r0, r4
 *   @0x21355c bl 0x212ea0 <_Z17_CountLinesInTextPc>
 *   @0x213560 mov r5, r0
 *   @0x213564 mov r0, r4
 *   @0x213568 mov r1, r5
 *   @0x21356c bl 0x212f10 <_Z14_BuildLineListPci>
 *   @0x213570 subs r6, r0, #0
 *   @0x213574 beq 0x213614 <_Z7LoadCSVPc+0xec>
 *   @0x213578 ldr r0, [r6]
 *   @0x21357c bl 0x212fec <_Z20_GetNumEntriesInLinePc>
 *   @0x213580 subs r8, r0, #0
 *   @0x213584 ble 0x213614 <_Z7LoadCSVPc+0xec>
 *   @0x213588 mov r1, r5
 *   @0x21358c bl 0x100294 <_Z20YYGML_ds_grid_createii>
 *   @0x213590 mov r1, r5
 *   @0x213594 mov r2, r8
 *   @0x213598 mov r7, r0
 *   @0x21359c mov r0, r6
 *   @0x2135a0 mov r3, r7
 *   @0x2135a4 bl 0x213360 <_Z15_PopulateDSGridPPciii>
 *   @0x2135a8 cmp r0, #0
 *   @0x2135ac beq 0x2135e4 <_Z7LoadCSVPc+0xbc>
 *   @0x2135b0 mov r0, r4
 *   @0x2135b4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x2135b8 mov r0, r7
 *   @0x2135bc add sp, sp, #8
 *   @0x2135c0 pop {r4, r5, r6, r7, r8, pc}
 *   @0x2135c4 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc>
 *   @0x2135c8 cmp r0, #0
 *   @0x2135cc beq 0x213624 <_Z7LoadCSVPc+0xfc>
 *   @0x2135d0 mov r0, r4
 *   @0x2135d4 mov r1, sp
 *   @0x2135d8 bl 0x18f848 <_ZN8LoadSave14ReadBundleFileEPKcPi>
 *   @0x2135dc mov r4, r0
 *   @0x2135e0 b 0x213558 <_Z7LoadCSVPc+0x30>
 *   @0x2135e4 add r0, sp, #4
 *   @0x2135e8 bl 0x10026c <_Z11GetTheGridsRi>
 *   @0x2135ec ldr r5, [r0, r7, lsl #2]
 *   @0x2135f0 mov r6, r0
 *   @0x2135f4 cmp r5, #0
 *   @0x2135f8 beq 0x21360c <_Z7LoadCSVPc+0xe4>
 *   @0x2135fc mov r0, r5
 *   @0x213600 bl 0x20b260 <_ZN8CDS_GridD2Ev>
 *   @0x213604 mov r0, r5
 *   @0x213608 bl 0x27d1d0 <_ZdlPv>
 *   @0x21360c mov r3, #0
 *   @0x213610 str r3, [r6, r7, lsl #2]
 *   @0x213614 mov r0, r4
 *   @0x213618 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x21361c mvn r0, #0
 *   @0x213620 b 0x2135bc <_Z7LoadCSVPc+0x94>
 *   @0x213624 mvn r0, #0
 *   @0x213628 b 0x2135bc <_Z7LoadCSVPc+0x94>
 *
 * ══ §35/119 Audio_PauseSoundNoise(CNoise*)  0x217b44  size 260  65 条（0x217b44..0x217c48）
 * @func 0x217b44 0x217c48  size 260  65 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Audio_GetSound(int) / 0xb6a9c / 0xb6ab4 / 0xb6a54 / COggAudio::Pause_Sound(int)
 * 字段偏移 top8: 0x10×3 / 0x18×2 / 0x2×2 / 0x40×2 / 0xe8×1 / 0x5×1 / 0x24×1 / 0x25×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x217b44 ldr r3, [pc, #0xe8]
 *   @0x217b48 push {r4, r5, lr}
 *   @0x217b4c ldr r3, [pc, r3]
 *   @0x217b50 sub sp, sp, #12
 *   @0x217b54 mov r4, r0
 *   @0x217b58 ldrb r3, [r3]
 *   @0x217b5c cmp r3, #0
 *   @0x217b60 bne 0x217b78 <_Z21Audio_PauseSoundNoiseP6CNoise+0x34>
 *   @0x217b64 cmp r0, #0
 *   @0x217b68 beq 0x217b78 <_Z21Audio_PauseSoundNoiseP6CNoise+0x34>
 *   @0x217b6c ldrb r3, [r0, #0x5]
 *   @0x217b70 cmp r3, #0
 *   @0x217b74 bne 0x217b80 <_Z21Audio_PauseSoundNoiseP6CNoise+0x3c>
 *   @0x217b78 add sp, sp, #12
 *   @0x217b7c pop {r4, r5, pc}
 *   @0x217b80 ldr r0, [r0, #0x18]
 *   @0x217b84 bl 0x21632c <_Z14Audio_GetSoundi>
 *   @0x217b88 cmp r0, #0
 *   @0x217b8c beq 0x217b78 <_Z21Audio_PauseSoundNoiseP6CNoise+0x34>
 *   @0x217b90 ldrb r3, [r0, #0x24]
 *   @0x217b94 cmp r3, #0
 *   @0x217b98 bne 0x217c1c <_Z21Audio_PauseSoundNoiseP6CNoise+0xd8>
 *   @0x217b9c ldrb r3, [r0, #0x25]
 *   @0x217ba0 cmp r3, #0
 *   @0x217ba4 bne 0x217c1c <_Z21Audio_PauseSoundNoiseP6CNoise+0xd8>
 *   @0x217ba8 ldr r5, [pc, #0x88]
 *   @0x217bac add r2, sp, #4
 *   @0x217bb0 ldr r0, [r4, #0x10]
 *   @0x217bb4 movw r1, #0x1010
 *   @0x217bb8 ldr r5, [pc, r5]
 *   @0x217bbc ldr r3, [r5]
 *   @0x217bc0 ldr r0, [r3, r0, lsl #2]
 *   @0x217bc4 bl 0xb6a9c <alGetSourcei@plt>
 *   @0x217bc8 ldr r2, [sp, #0x4]
 *   @0x217bcc movw r3, #0x1012
 *   @0x217bd0 cmp r2, r3
 *   @0x217bd4 bne 0x217b78 <_Z21Audio_PauseSoundNoiseP6CNoise+0x34>
 *   @0x217bd8 ldr r3, [r5]
 *   @0x217bdc ldr r2, [r4, #0x10]
 *   @0x217be0 ldr r0, [r3, r2, lsl #2]
 *   @0x217be4 bl 0xb6ab4 <alSourcePause@plt>
 *   @0x217be8 bl 0xb6a54 <alGetError@plt>
 *   @0x217bec subs r3, r0, #0
 *   @0x217bf0 beq 0x217b78 <_Z21Audio_PauseSoundNoiseP6CNoise+0x34>
 *   @0x217bf4 ldr r0, [pc, #0x40]
 *   @0x217bf8 ldr r1, [pc, #0x40]
 *   @0x217bfc ldr r0, [pc, r0]
 *   @0x217c00 ldr r2, [r4, #0x18]
 *   @0x217c04 add r1, pc, r1
 *   @0x217c08 ldr r0, [r0]
 *   @0x217c0c ldr r12, [r0]
 *   @0x217c10 ldr r12, [r12, #0xc]
 *   @0x217c14 blx r12
 *   @0x217c18 b 0x217b78 <_Z21Audio_PauseSoundNoiseP6CNoise+0x34>
 *   @0x217c1c ldr r0, [pc, #0x20]
 *   @0x217c20 ldr r1, [r4, #0x10]
 *   @0x217c24 add r0, pc, r0
 *   @0x217c28 bl 0x226470 <_ZN9COggAudio11Pause_SoundEi>
 *   @0x217c2c add sp, sp, #12
 *   @0x217c30 pop {r4, r5, pc}
 *   @0x217c34 andseq r7, sp, r0, lsl #10
 *   @0x217c38 andseq r9, sp, r4, lsl r8
 *   @0x217c3c andseq r5, sp, r8, lsl r11
 *   @0x217c40 andseq r12, r3, r12, asr r0
 *   @0x217c44 subseq sp, r3, r0, ror r6
 *
 * ══ §36/119 Audio_ResumeSoundNoise(CNoise*)  0x217cf0  size 260  65 条（0x217cf0..0x217df4）
 * @func 0x217cf0 0x217df4  size 260  65 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Audio_GetSound(int) / 0xb6a9c / 0xb6a84 / 0xb6a54 / COggAudio::Resume_Sound(int)
 * 字段偏移 top8: 0x10×3 / 0x18×2 / 0x2×2 / 0x40×2 / 0xe8×1 / 0x5×1 / 0x24×1 / 0x25×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x217cf0 ldr r3, [pc, #0xe8]
 *   @0x217cf4 push {r4, r5, lr}
 *   @0x217cf8 ldr r3, [pc, r3]
 *   @0x217cfc sub sp, sp, #12
 *   @0x217d00 mov r4, r0
 *   @0x217d04 ldrb r3, [r3]
 *   @0x217d08 cmp r3, #0
 *   @0x217d0c bne 0x217d24 <_Z22Audio_ResumeSoundNoiseP6CNoise+0x34>
 *   @0x217d10 cmp r0, #0
 *   @0x217d14 beq 0x217d24 <_Z22Audio_ResumeSoundNoiseP6CNoise+0x34>
 *   @0x217d18 ldrb r3, [r0, #0x5]
 *   @0x217d1c cmp r3, #0
 *   @0x217d20 bne 0x217d2c <_Z22Audio_ResumeSoundNoiseP6CNoise+0x3c>
 *   @0x217d24 add sp, sp, #12
 *   @0x217d28 pop {r4, r5, pc}
 *   @0x217d2c ldr r0, [r0, #0x18]
 *   @0x217d30 bl 0x21632c <_Z14Audio_GetSoundi>
 *   @0x217d34 cmp r0, #0
 *   @0x217d38 beq 0x217d24 <_Z22Audio_ResumeSoundNoiseP6CNoise+0x34>
 *   @0x217d3c ldrb r3, [r0, #0x24]
 *   @0x217d40 cmp r3, #0
 *   @0x217d44 bne 0x217dc8 <_Z22Audio_ResumeSoundNoiseP6CNoise+0xd8>
 *   @0x217d48 ldrb r3, [r0, #0x25]
 *   @0x217d4c cmp r3, #0
 *   @0x217d50 bne 0x217dc8 <_Z22Audio_ResumeSoundNoiseP6CNoise+0xd8>
 *   @0x217d54 ldr r5, [pc, #0x88]
 *   @0x217d58 add r2, sp, #4
 *   @0x217d5c ldr r0, [r4, #0x10]
 *   @0x217d60 movw r1, #0x1010
 *   @0x217d64 ldr r5, [pc, r5]
 *   @0x217d68 ldr r3, [r5]
 *   @0x217d6c ldr r0, [r3, r0, lsl #2]
 *   @0x217d70 bl 0xb6a9c <alGetSourcei@plt>
 *   @0x217d74 ldr r2, [sp, #0x4]
 *   @0x217d78 movw r3, #0x1013
 *   @0x217d7c cmp r2, r3
 *   @0x217d80 bne 0x217d24 <_Z22Audio_ResumeSoundNoiseP6CNoise+0x34>
 *   @0x217d84 ldr r3, [r5]
 *   @0x217d88 ldr r2, [r4, #0x10]
 *   @0x217d8c ldr r0, [r3, r2, lsl #2]
 *   @0x217d90 bl 0xb6a84 <alSourcePlay@plt>
 *   @0x217d94 bl 0xb6a54 <alGetError@plt>
 *   @0x217d98 subs r3, r0, #0
 *   @0x217d9c beq 0x217d24 <_Z22Audio_ResumeSoundNoiseP6CNoise+0x34>
 *   @0x217da0 ldr r0, [pc, #0x40]
 *   @0x217da4 ldr r1, [pc, #0x40]
 *   @0x217da8 ldr r0, [pc, r0]
 *   @0x217dac ldr r2, [r4, #0x18]
 *   @0x217db0 add r1, pc, r1
 *   @0x217db4 ldr r0, [r0]
 *   @0x217db8 ldr r12, [r0]
 *   @0x217dbc ldr r12, [r12, #0xc]
 *   @0x217dc0 blx r12
 *   @0x217dc4 b 0x217d24 <_Z22Audio_ResumeSoundNoiseP6CNoise+0x34>
 *   @0x217dc8 ldr r0, [pc, #0x20]
 *   @0x217dcc ldr r1, [r4, #0x10]
 *   @0x217dd0 add r0, pc, r0
 *   @0x217dd4 bl 0x226500 <_ZN9COggAudio12Resume_SoundEi>
 *   @0x217dd8 add sp, sp, #12
 *   @0x217ddc pop {r4, r5, pc}
 *   @0x217de0 andseq r7, sp, r4, asr r3
 *   @0x217de4 andseq r9, sp, r8, ror #12
 *   @0x217de8 andseq r5, sp, r12, ror #18
 *   @0x217dec ldrsbeq r11, [r3], -r8
 *   @0x217df0 subseq sp, r3, r4, asr #9
 *
 * ══ §37/119 SoundHardware::PlayMIDI(char const*, bool)  0x220adc  size 260  58 条（0x220adc..0x220be0）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x220adc 0x220be0  size 260  58 条
 * 部分覆盖: 本节 58/65 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x220aec→0x755361, 0x220b08→0x755363, 0x220b1c→0x755362, 0x220b30→0x75536c, 0x220b84→0x3eb70c
 * 调用序列: 0xb65a4 / 0xb6538 / SoundHardware::StopMusic()
 * 字段偏移 top8: 0x48×3 / 0xd4×1 / 0xd0×1 / 0xb8×1 / 0xa8×1 / 0x98×1 / 0x-3×1 / 0x-2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x220adc push {r3, r4, r5, r6, r7, lr}
 *   @0x220ae0 mov r7, r0
 *   @0x220ae4 ldr r4, [pc, #0xd4]
 *   @0x220ae8 mov r6, r1
 *   @0x220aec ldr r3, [pc, #0xd0]
 *   @0x220af0 mov r5, r2
 *   @0x220af4 add r4, pc, r4
 *   @0x220af8 ldr r3, [r4, r3]
 *   @0x220afc ldrb r3, [r3]
 *   @0x220b1c ldr r3, [pc, #0xa8]
 *   @0x220b20 ldr r3, [r4, r3]
 *   @0x220b24 ldrb r3, [r3]
 *   @0x220b28 cmp r3, #0
 *   @0x220b2c popne {r3, r4, r5, r6, r7, pc}
 *   @0x220b30 ldr r3, [pc, #0x98]
 *   @0x220b34 ldr r4, [r4, r3]
 *   @0x220b38 ldrb r3, [r4]
 *   @0x220b3c cmp r3, #0
 *   @0x220b40 bne 0x220bb4 <_ZN13SoundHardware8PlayMIDIEPKcb+0xd8>
 *   @0x220b44 mov r1, r6
 *   @0x220b48 mov r0, r4
 *   @0x220b4c bl 0xb65a4 <strcpy@plt>
 *   @0x220b50 mov r0, r4
 *   @0x220b54 bl 0xb6538 <strlen@plt>
 *   @0x220b58 mov r1, r5
 *   @0x220b5c mov r12, #112
 *   @0x220b60 mov r5, #109
 *   @0x220b64 mov r2, #51
 *   @0x220b68 add r3, r4, r0
 *   @0x220b6c mov r0, r4
 *   @0x220b70 strb r5, [r3, #-0x3]
 *   @0x220b74 strb r12, [r3, #-0x2]
 *   @0x220b78 strb r2, [r3, #-0x1]
 *   @0x220b7c pop {r3, r4, r5, r6, r7, lr}
 *   @0x220b80 b 0x223098 <_Z14OpenAL_PlayMP3PKcb>
 *   @0x220b84 ldr r3, [pc, #0x48]
 *   @0x220b88 ldr r2, [pc, #0x48]
 *   @0x220b8c ldr r1, [pc, #0x48]
 *   @0x220b90 ldr r3, [r4, r3]
 *   @0x220b94 add r2, pc, r2
 *   @0x220b98 add r1, pc, r1
 *   @0x220b9c add r2, r2, #120
 *   @0x220ba0 ldr r0, [r3]
 *   @0x220ba4 ldr r3, [r0]
 *   @0x220ba8 ldr r3, [r3, #0xc]
 *   @0x220bac blx r3
 *   @0x220bb0 b 0x220b08 <_ZN13SoundHardware8PlayMIDIEPKcb+0x2c>
 *   @0x220bb4 mov r0, r7
 *   @0x220bb8 bl 0x220950 <_ZN13SoundHardware9StopMusicEv>
 *   @0x220bbc b 0x220b44 <_ZN13SoundHardware8PlayMIDIEPKcb+0x68>
 *   @0x220bc0 andseq r1, sp, r12, asr r1
 *   @0x220bc4 .word 0xfffff7d8
 *   @0x220bc8 .word 0xffffd3fc
 *   @0x220bcc .word 0xfffff7e0
 *   @0x220bd0 .word 0xfffff7dc
 *   @0x220bd4 .word 0xffffbac4
 *   @0x220bd8 andseq sp, r3, r4, lsr r4
 *   @0x220bdc andseq r3, r3, r4, lsr #25
 *
 * ══ §38/119 CPhysicsWorld::CreateWeldJoint(CPhysicsObject*, CPhysicsObject*, float, float, float, float, float, bool)  0x239570  size 260  65 条（0x239570..0x239674）
 * @func 0x239570 0x239674  size 260  65 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2WeldJointDef::Initialize(b2Body*, b2Body*, b2Vec2 const&) / CPhysicsJointFactory::CreateJoint(CPhysicsWorld*, b2JointDef const&)
 * 字段偏移 top8: 0x4×2 / 0x18×2 / 0x30×2 / 0x34×2 / 0x8×2 / 0x68×1 / 0x6c×1 / 0x70×1
 * VFP 指令 15 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x239570 vmov s14, r3
 *   @0x239574 ldr r1, [r1]
 *   @0x239578 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x23957c vpush {d8}
 *   @0x239580 mov r4, r0
 *   @0x239584 vldr s15, [r4, #96]
 *   @0x239588 sub sp, sp, #60
 *   @0x23958c vmul.f32 s14, s15, s14
 *   @0x239590 vldr s13, [sp, #96]
 *   @0x239594 ldrh r3, [r1, #4]
 *   @0x239598 ldr r2, [r2]
 *   @0x23959c add r5, sp, #8
 *   @0x2395a0 tst r3, #2
 *   @0x2395a4 mov r12, #0
 *   @0x2395a8 orreq r3, r3, #2
 *   @0x2395ac strheq r3, [r1, #4]
 *   @0x2395b0 ldrh r3, [r2, #4]
 *   @0x2395b4 moveq r0, #0
 *   @0x2395b8 streq r0, [r1, #0xa0]
 *   @0x2395bc mov lr, #0
 *   @0x2395c0 tst r3, #2
 *   @0x2395c4 vldr s16, [sp, #100]
 *   @0x2395c8 orreq r3, r3, #2
 *   @0x2395cc strheq r3, [r2, #4]
 *   @0x2395d0 moveq r0, #0
 *   @0x2395d4 mov r3, sp
 *   @0x2395d8 streq r0, [r2, #0xa0]
 *   @0x2395dc mov r0, r5
 *   @0x2395e0 ldr r9, [sp, #0x68]
 *   @0x2395e4 mov r7, #8
 *   @0x2395e8 vmul.f32 s15, s15, s13
 *   @0x2395ec ldr r8, [sp, #0x6c]
 *   @0x2395f0 ldrb r6, [sp, #0x70]
 *   @0x2395f4 vstr s14, [sp]
 *   @0x2395f8 str lr, [sp, #0xc]
 *   @0x2395fc str lr, [sp, #0x10]
 *   @0x239600 str lr, [sp, #0x14]
 *   @0x239604 strb lr, [sp, #0x18]
 *   @0x239608 str r12, [sp, #0x1c]
 *   @0x23960c str r12, [sp, #0x20]
 *   @0x239610 str r12, [sp, #0x24]
 *   @0x239614 str r12, [sp, #0x28]
 *   @0x239618 str r12, [sp, #0x2c]
 *   @0x23961c str r12, [sp, #0x30]
 *   @0x239620 str r12, [sp, #0x34]
 *   @0x239624 vstr s15, [sp, #4]
 *   @0x239628 str r7, [sp, #0x8]
 *   @0x23962c bl 0x2d3698 <_ZN14b2WeldJointDef10InitializeEP6b2BodyS1_RK6b2Vec2>
 *   @0x239630 vldr s15, [pc, #52]
 *   @0x239634 vnmul.f32 s16, s16, s15
 *   @0x239638 vldr s15, [pc, #48]
 *   @0x23963c mov r1, r5
 *   @0x239640 mov r0, r4
 *   @0x239644 str r9, [sp, #0x30]
 *   @0x239648 str r8, [sp, #0x34]
 *   @0x23964c strb r6, [sp, #0x18]
 *   @0x239650 vdiv.f32 s16, s16, s15
 *   @0x239654 vstr s16, [sp, #44]
 *   @0x239658 bl 0x23b2a8 <_ZN20CPhysicsJointFactory11CreateJointEP13CPhysicsWorldRK10b2JointDef>
 *   @0x23965c ldr r0, [r0, #0x8]
 *   @0x239660 add sp, sp, #60
 *   @0x239664 vpop {d8}
 *   @0x239668 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x23966c teqmi r4, #0
 *   @0x239670 ldrdmi r0, r1, [r9], #-251
 *
 * ══ §39/119 F_JS_Object_freeze(RValue&, CInstance*, CInstance*, int, RValue*)  0x2508c8  size 260  65 条（0x2508c8..0x2509cc）
 * @func 0x2508c8 0x2509e0  size 280  70 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JSThrowTypeError(char const*)×2 / YYObject_PropertyNameIterator::YYObject_PropertyNameIterator(YYObjectBase*, int) / JS_GetOwnProperty(YYObjectBase*, RValue*, char const*) / JS_DefineOwnProperty_Internal(YYObjectBase*, char const*, RValue*, bool) / YYObject_PropertyNameIterator::Next(RValue*)
 * 字段偏移 top8: 0xc×4 / 0x4×4 / 0x1c×2 / 0x28×2 / 0x8×2 / 0x60×1 / 0xcc×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2508c8 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2508cc cmp r3, #0
 *   @0x2508d0 sub sp, sp, #64
 *   @0x2508d4 mov r9, r0
 *   @0x2508d8 ldr r6, [sp, #0x60]
 *   @0x2508dc beq 0x2508f0 <_Z18F_JS_Object_freezeR6RValueP9CInstanceS2_iPS_+0x28>
 *   @0x2508e0 ldr r3, [r6, #0xc]
 *   @0x2508e4 bic r3, r3, #-16777216
 *   @0x2508e8 cmp r3, #6
 *   @0x2508ec beq 0x250904 <_Z18F_JS_Object_freezeR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x2508f0 ldr r0, [pc, #0xcc]
 *   @0x2508f4 add r0, pc, r0
 *   @0x2508f8 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x2508fc add sp, sp, #64
 *   @0x250900 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x250904 ldr r4, [r6]
 *   @0x250908 add r7, sp, #36
 *   @0x25090c mov r2, #0
 *   @0x250910 add r8, sp, #4
 *   @0x250914 mov r0, r7
 *   @0x250918 mov r10, #5
 *   @0x25091c mov r1, r4
 *   @0x250920 add r5, sp, #20
 *   @0x250924 bl 0x2400ec <_ZN29YYObject_PropertyNameIteratorC2EP12YYObjectBasei>
 *   @0x250928 b 0x250968 <_Z18F_JS_Object_freezeR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x25092c ldr r3, [sp, #0x4]
 *   @0x250930 str r10, [sp, #0x20]
 *   @0x250934 ldr r2, [r3]
 *   @0x250938 bl 0x241890 <_Z17JS_GetOwnPropertyP12YYObjectBaseP6RValuePKc>
 *   @0x25093c ldr r1, [sp, #0x4]
 *   @0x250940 ldr r12, [sp, #0x1c]
 *   @0x250944 mov r0, r4
 *   @0x250948 mov r2, r5
 *   @0x25094c mov r3, #1
 *   @0x250950 ldr r1, [r1]
 *   @0x250954 bic r12, r12, #6
 *   @0x250958 str r12, [sp, #0x1c]
 *   @0x25095c bl 0x247d44 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb>
 *   @0x250960 cmp r0, #2
 *   @0x250964 beq 0x2509b4 <_Z18F_JS_Object_freezeR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0x250968 mov r1, r8
 *   @0x25096c mov r0, r7
 *   @0x250970 bl 0x24a1fc <_ZN29YYObject_PropertyNameIterator4NextEP6RValue>
 *   @0x250974 mov r1, r5
 *   @0x250978 cmp r0, #0
 *   @0x25097c mov r0, r4
 *   @0x250980 bne 0x25092c <_Z18F_JS_Object_freezeR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x250984 ldr r3, [r4, #0x28]
 *   @0x250988 bic r3, r3, #1
 *   @0x25098c str r3, [r4, #0x28]
 *   @0x250990 ldr r0, [r6]
 *   @0x250994 ldr r1, [r6, #0x4]
 *   @0x250998 ldr r2, [r6, #0x8]
 *   @0x25099c ldr r3, [r6, #0xc]
 *   @0x2509a0 str r0, [r9]
 *   @0x2509a4 str r1, [r9, #0x4]
 *   @0x2509a8 str r2, [r9, #0x8]
 *   @0x2509ac str r3, [r9, #0xc]
 *   @0x2509b0 b 0x2508fc <_Z18F_JS_Object_freezeR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x2509b4 ldr r0, [pc, #0xc]
 *   @0x2509b8 add r0, pc, r0
 *   @0x2509bc bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x2509c0 b 0x2508fc <_Z18F_JS_Object_freezeR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x2509c4 andseq r5, r0, r4, asr r6
 *   @0x2509c8 mulseq r0, r0, r5
 *
 * ══ §40/119 F_JS_Object_seal(RValue&, CInstance*, CInstance*, int, RValue*)  0x2509cc  size 260  65 条（0x2509cc..0x250ad0）
 * @func 0x2509cc 0x250ad0  size 260  65 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JSThrowTypeError(char const*)×2 / YYObject_PropertyNameIterator::YYObject_PropertyNameIterator(YYObjectBase*, int) / JS_GetOwnProperty(YYObjectBase*, RValue*, char const*) / JS_DefineOwnProperty_Internal(YYObjectBase*, char const*, RValue*, bool) / YYObject_PropertyNameIterator::Next(RValue*)
 * 字段偏移 top8: 0xc×4 / 0x4×4 / 0x1c×2 / 0x28×2 / 0x8×2 / 0x60×1 / 0xcc×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2509cc push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2509d0 cmp r3, #0
 *   @0x2509d4 sub sp, sp, #64
 *   @0x2509d8 mov r9, r0
 *   @0x2509dc ldr r6, [sp, #0x60]
 *   @0x2509e0 beq 0x2509f4 <_Z16F_JS_Object_sealR6RValueP9CInstanceS2_iPS_+0x28>
 *   @0x2509e4 ldr r3, [r6, #0xc]
 *   @0x2509e8 bic r3, r3, #-16777216
 *   @0x2509ec cmp r3, #6
 *   @0x2509f0 beq 0x250a08 <_Z16F_JS_Object_sealR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x2509f4 ldr r0, [pc, #0xcc]
 *   @0x2509f8 add r0, pc, r0
 *   @0x2509fc bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x250a00 add sp, sp, #64
 *   @0x250a04 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x250a08 ldr r4, [r6]
 *   @0x250a0c add r7, sp, #36
 *   @0x250a10 mov r2, #0
 *   @0x250a14 add r8, sp, #4
 *   @0x250a18 mov r0, r7
 *   @0x250a1c mov r10, #5
 *   @0x250a20 mov r1, r4
 *   @0x250a24 add r5, sp, #20
 *   @0x250a28 bl 0x2400ec <_ZN29YYObject_PropertyNameIteratorC2EP12YYObjectBasei>
 *   @0x250a2c b 0x250a6c <_Z16F_JS_Object_sealR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x250a30 ldr r3, [sp, #0x4]
 *   @0x250a34 str r10, [sp, #0x20]
 *   @0x250a38 ldr r2, [r3]
 *   @0x250a3c bl 0x241890 <_Z17JS_GetOwnPropertyP12YYObjectBaseP6RValuePKc>
 *   @0x250a40 ldr r1, [sp, #0x4]
 *   @0x250a44 ldr r12, [sp, #0x1c]
 *   @0x250a48 mov r0, r4
 *   @0x250a4c mov r2, r5
 *   @0x250a50 mov r3, #1
 *   @0x250a54 ldr r1, [r1]
 *   @0x250a58 bic r12, r12, #2
 *   @0x250a5c str r12, [sp, #0x1c]
 *   @0x250a60 bl 0x247d44 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb>
 *   @0x250a64 cmp r0, #2
 *   @0x250a68 beq 0x250ab8 <_Z16F_JS_Object_sealR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0x250a6c mov r1, r8
 *   @0x250a70 mov r0, r7
 *   @0x250a74 bl 0x24a1fc <_ZN29YYObject_PropertyNameIterator4NextEP6RValue>
 *   @0x250a78 mov r1, r5
 *   @0x250a7c cmp r0, #0
 *   @0x250a80 mov r0, r4
 *   @0x250a84 bne 0x250a30 <_Z16F_JS_Object_sealR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x250a88 ldr r3, [r4, #0x28]
 *   @0x250a8c bic r3, r3, #1
 *   @0x250a90 str r3, [r4, #0x28]
 *   @0x250a94 ldr r0, [r6]
 *   @0x250a98 ldr r1, [r6, #0x4]
 *   @0x250a9c ldr r2, [r6, #0x8]
 *   @0x250aa0 ldr r3, [r6, #0xc]
 *   @0x250aa4 str r0, [r9]
 *   @0x250aa8 str r1, [r9, #0x4]
 *   @0x250aac str r2, [r9, #0x8]
 *   @0x250ab0 str r3, [r9, #0xc]
 *   @0x250ab4 b 0x250a00 <_Z16F_JS_Object_sealR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x250ab8 ldr r0, [pc, #0xc]
 *   @0x250abc add r0, pc, r0
 *   @0x250ac0 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x250ac4 b 0x250a00 <_Z16F_JS_Object_sealR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x250ac8 andseq r5, r0, r0, asr r5
 *   @0x250acc andseq r5, r0, r12, lsl #9
 *
 * ══ §41/119 Java_com_yoyogames_runner_RunnerJNILib_HttpResultString  0x293174  size 260  65 条（0x293174..0x293278）
 * @func 0x293174 0x29328c  size 280  70 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: setJNIEnv / 0xb65a4 / 0xb6538
 * 字段偏移 top8: 0x28×2 / 0xbc×2 / 0xc×2 / 0x24×2 / 0x34×2 / 0x2a4×1 / 0x94×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x293174 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x293178 sub sp, sp, #12
 *   @0x29317c mov r6, r0
 *   @0x293180 mov r7, r2
 *   @0x293184 mov r8, r3
 *   @0x293188 ldr r5, [sp, #0x28]
 *   @0x29318c bl 0x290614 <setJNIEnv>
 *   @0x293190 ldr r3, [r6]
 *   @0x293194 mov r1, r7
 *   @0x293198 mov r2, #0
 *   @0x29319c mov r0, r6
 *   @0x2931a0 ldr r3, [r3, #0x2a4]
 *   @0x2931a4 blx r3
 *   @0x2931a8 ldr r12, [pc, #0xbc]
 *   @0x2931ac ldr r1, [pc, #0xbc]
 *   @0x2931b0 mov r3, r8
 *   @0x2931b4 ldr r12, [pc, r12]
 *   @0x2931b8 add r1, pc, r1
 *   @0x2931bc mov r2, r0
 *   @0x2931c0 mov r9, r0
 *   @0x2931c4 ldr r0, [r12]
 *   @0x2931c8 ldr r12, [r0]
 *   @0x2931cc str r5, [sp]
 *   @0x2931d0 ldr r12, [r12, #0xc]
 *   @0x2931d4 blx r12
 *   @0x2931d8 ldr r12, [pc, #0x94]
 *   @0x2931dc ldr r12, [pc, r12]
 *   @0x2931e0 ldr r4, [r12]
 *   @0x2931e4 cmp r4, #0
 *   @0x2931e8 beq 0x293214 <Java_com_yoyogames_runner_RunnerJNILib_HttpResultString+0xa0>
 *   @0x2931ec ldr r3, [r4, #0x24]
 *   @0x2931f0 cmp r3, r5
 *   @0x2931f4 bne 0x293208 <Java_com_yoyogames_runner_RunnerJNILib_HttpResultString+0x94>
 *   @0x2931f8 b 0x293240 <Java_com_yoyogames_runner_RunnerJNILib_HttpResultString+0xcc>
 *   @0x2931fc ldr r12, [r4, #0x24]
 *   @0x293200 cmp r12, r5
 *   @0x293204 beq 0x293240 <Java_com_yoyogames_runner_RunnerJNILib_HttpResultString+0xcc>
 *   @0x293208 ldr r4, [r4, #0x4]
 *   @0x29320c cmp r4, #0
 *   @0x293210 bne 0x2931fc <Java_com_yoyogames_runner_RunnerJNILib_HttpResultString+0x88>
 *   @0x293214 cmp r9, #0
 *   @0x293218 cmpne r7, #0
 *   @0x29321c beq 0x293238 <Java_com_yoyogames_runner_RunnerJNILib_HttpResultString+0xc4>
 *   @0x293220 ldr r3, [r6]
 *   @0x293224 mov r1, r7
 *   @0x293228 mov r2, r9
 *   @0x29322c mov r0, r6
 *   @0x293230 ldr r3, [r3, #0x2a8]
 *   @0x293234 blx r3
 *   @0x293238 add sp, sp, #12
 *   @0x29323c pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x293240 mov r3, #7
 *   @0x293244 mov r1, r9
 *   @0x293248 str r3, [r4, #0xc]
 *   @0x29324c str r8, [r4, #0x28]
 *   @0x293250 ldr r0, [r4, #0x34]
 *   @0x293254 bl 0xb65a4 <strcpy@plt>
 *   @0x293258 ldr r0, [r4, #0x34]
 *   @0x29325c bl 0xb6538 <strlen@plt>
 *   @0x293260 add r0, r0, #1
 *   @0x293264 str r0, [r4, #0x3c]
 *   @0x293268 b 0x293214 <Java_com_yoyogames_runner_RunnerJNILib_HttpResultString+0xa0>
 *   @0x29326c andseq r10, r5, r0, ror #10
 *   @0x293270 andeq r5, r12, r0, lsr #30
 *   @0x293274 andseq r10, r5, r12, lsl r12
 *
 * ══ §42/119 jpeg_CreateDecompress  0x2b2dfc  size 260  65 条（0x2b2dfc..0x2b2f00）
 * @func 0x2b2dfc 0x2b2f00  size 260  65 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65b0 / jinit_memory_mgr / jinit_marker_reader / jinit_input_controller
 * 字段偏移 top8: 0x18×3 / 0x14×3 / 0x1c×2 / 0xc×2 / 0x4×1 / 0x10×1 / 0x8×1 / 0x90×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b2dfc cmp r1, #62
 *   @0x2b2e00 mov r3, #0
 *   @0x2b2e04 push {r4, r5, r6, lr}
 *   @0x2b2e08 mov r4, r0
 *   @0x2b2e0c mov r5, r2
 *   @0x2b2e10 str r3, [r0, #0x4]
 *   @0x2b2e14 beq 0x2b2e40 <jpeg_CreateDecompress+0x44>
 *   @0x2b2e18 ldr r3, [r0]
 *   @0x2b2e1c mov r2, #62
 *   @0x2b2e20 mov r12, #12
 *   @0x2b2e24 str r2, [r3, #0x18]
 *   @0x2b2e28 ldr r2, [r0]
 *   @0x2b2e2c str r12, [r3, #0x14]
 *   @0x2b2e30 str r1, [r2, #0x1c]
 *   @0x2b2e34 ldr r3, [r0]
 *   @0x2b2e38 ldr r3, [r3]
 *   @0x2b2e3c blx r3
 *   @0x2b2e40 cmp r5, #432
 *   @0x2b2e44 beq 0x2b2e74 <jpeg_CreateDecompress+0x78>
 *   @0x2b2e48 ldr r3, [r4]
 *   @0x2b2e4c mov r2, #432
 *   @0x2b2e50 mov r1, #21
 *   @0x2b2e54 mov r0, r4
 *   @0x2b2e58 str r2, [r3, #0x18]
 *   @0x2b2e5c ldr r2, [r4]
 *   @0x2b2e60 str r1, [r3, #0x14]
 *   @0x2b2e64 str r5, [r2, #0x1c]
 *   @0x2b2e68 ldr r3, [r4]
 *   @0x2b2e6c ldr r3, [r3]
 *   @0x2b2e70 blx r3
 *   @0x2b2e74 ldr r6, [r4]
 *   @0x2b2e78 mov r1, #0
 *   @0x2b2e7c ldr r5, [r4, #0xc]
 *   @0x2b2e80 mov r2, #432
 *   @0x2b2e84 mov r0, r4
 *   @0x2b2e88 bl 0xb65b0 <memset@plt>
 *   @0x2b2e8c mov r3, #1
 *   @0x2b2e90 mov r0, r4
 *   @0x2b2e94 strb r3, [r4, #0x10]
 *   @0x2b2e98 str r6, [r4]
 *   @0x2b2e9c str r5, [r4, #0xc]
 *   @0x2b2ea0 bl 0x2ba0b4 <jinit_memory_mgr>
 *   @0x2b2ea4 mov r3, #0
 *   @0x2b2ea8 mov r0, r4
 *   @0x2b2eac str r3, [r4, #0x8]
 *   @0x2b2eb0 str r3, [r4, #0x18]
 *   @0x2b2eb4 str r3, [r4, #0x90]
 *   @0x2b2eb8 str r3, [r4, #0x94]
 *   @0x2b2ebc str r3, [r4, #0x98]
 *   @0x2b2ec0 str r3, [r4, #0x9c]
 *   @0x2b2ec4 str r3, [r4, #0xa0]
 *   @0x2b2ec8 str r3, [r4, #0xb0]
 *   @0x2b2ecc str r3, [r4, #0xa4]
 *   @0x2b2ed0 str r3, [r4, #0xb4]
 *   @0x2b2ed4 str r3, [r4, #0xa8]
 *   @0x2b2ed8 str r3, [r4, #0xb8]
 *   @0x2b2edc str r3, [r4, #0xac]
 *   @0x2b2ee0 str r3, [r4, #0xbc]
 *   @0x2b2ee4 str r3, [r4, #0x10c]
 *   @0x2b2ee8 bl 0x2b5efc <jinit_marker_reader>
 *   @0x2b2eec mov r0, r4
 *   @0x2b2ef0 bl 0x2b3ee0 <jinit_input_controller>
 *   @0x2b2ef4 mov r3, #200
 *   @0x2b2ef8 str r3, [r4, #0x14]
 *   @0x2b2efc pop {r4, r5, r6, pc}
 *
 * ══ §43/119 anon_2c1274  0x2c1274  size 260  65 条（0x2c1274..0x2c1378）
 * @func 0x2c1274 0x2c1378  size 260  65 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb68d4×2 / 0xb68bc / 0xb68c8
 * 字段偏移 top8: 0xc×5 / 0x14×4 / 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c1274 ldr r0, [r1, #0xc]
 *   @0x2c1278 b 0xb6850 <fclose@plt>
 *   @0x2c127c push {r3, r4, r5, r6, r7, lr}
 *   @0x2c1280 mov r5, r1
 *   @0x2c1284 mov r6, r0
 *   @0x2c1288 mov r7, r2
 *   @0x2c128c mov r1, r3
 *   @0x2c1290 ldr r0, [r5, #0xc]
 *   @0x2c1294 mov r2, #0
 *   @0x2c1298 ldr r4, [sp, #0x18]
 *   @0x2c129c bl 0xb68d4 <fseek@plt>
 *   @0x2c12a0 cmp r0, #0
 *   @0x2c12a4 bne 0x2c12e0 <jpeg_idct_1x1+0xa0>
 *   @0x2c12a8 mov r0, r7
 *   @0x2c12ac ldr r3, [r5, #0xc]
 *   @0x2c12b0 mov r1, #1
 *   @0x2c12b4 mov r2, r4
 *   @0x2c12b8 bl 0xb68bc <fwrite@plt>
 *   @0x2c12bc cmp r4, r0
 *   @0x2c12c0 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x2c12c4 ldr r3, [r6]
 *   @0x2c12c8 mov r1, #66
 *   @0x2c12cc mov r0, r6
 *   @0x2c12d0 ldr r2, [r3]
 *   @0x2c12d4 str r1, [r3, #0x14]
 *   @0x2c12d8 blx r2
 *   @0x2c12dc pop {r3, r4, r5, r6, r7, pc}
 *   @0x2c12e0 ldr r3, [r6]
 *   @0x2c12e4 mov r2, #65
 *   @0x2c12e8 mov r0, r6
 *   @0x2c12ec str r2, [r3, #0x14]
 *   @0x2c12f0 ldr r3, [r3]
 *   @0x2c12f4 blx r3
 *   @0x2c12f8 b 0x2c12a8 <jpeg_idct_1x1+0x68>
 *   @0x2c12fc push {r3, r4, r5, r6, r7, lr}
 *   @0x2c1300 mov r5, r1
 *   @0x2c1304 mov r6, r0
 *   @0x2c1308 mov r7, r2
 *   @0x2c130c mov r1, r3
 *   @0x2c1310 ldr r0, [r5, #0xc]
 *   @0x2c1314 mov r2, #0
 *   @0x2c1318 ldr r4, [sp, #0x18]
 *   @0x2c131c bl 0xb68d4 <fseek@plt>
 *   @0x2c1320 cmp r0, #0
 *   @0x2c1324 bne 0x2c1360 <jpeg_idct_1x1+0x120>
 *   @0x2c1328 mov r0, r7
 *   @0x2c132c ldr r3, [r5, #0xc]
 *   @0x2c1330 mov r1, #1
 *   @0x2c1334 mov r2, r4
 *   @0x2c1338 bl 0xb68c8 <fread@plt>
 *   @0x2c133c cmp r4, r0
 *   @0x2c1340 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x2c1344 ldr r3, [r6]
 *   @0x2c1348 mov r1, #64
 *   @0x2c134c mov r0, r6
 *   @0x2c1350 ldr r2, [r3]
 *   @0x2c1354 str r1, [r3, #0x14]
 *   @0x2c1358 blx r2
 *   @0x2c135c pop {r3, r4, r5, r6, r7, pc}
 *   @0x2c1360 ldr r3, [r6]
 *   @0x2c1364 mov r2, #65
 *   @0x2c1368 mov r0, r6
 *   @0x2c136c str r2, [r3, #0x14]
 *   @0x2c1370 ldr r3, [r3]
 *   @0x2c1374 blx r3
 *
 * ══ §44/119 b2DistanceJoint::SolveVelocityConstraints(b2SolverData const&)  0x2cc8dc  size 260  65 条（0x2cc8dc..0x2cc9e0）
 * @func 0x2cc8dc 0x2cc9e0  size 260  65 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x6c×1 / 0x70×1 / 0x1c×1
 * VFP 指令 57 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cc8dc ldr r2, [r0, #0x6c]
 *   @0x2cc8e0 vpush {d8, d9, d10, d11}
 *   @0x2cc8e4 ldr r3, [r0, #0x70]
 *   @0x2cc8e8 vldr s16, [r0, #124]
 *   @0x2cc8ec ldr r1, [r1, #0x1c]
 *   @0x2cc8f0 vldr s0, [r0, #132]
 *   @0x2cc8f4 add r2, r2, r2, lsl #1
 *   @0x2cc8f8 vldr s11, [r0, #136]
 *   @0x2cc8fc add r3, r3, r3, lsl #1
 *   @0x2cc900 vldr s10, [r0, #128]
 *   @0x2cc904 add r2, r1, r2, lsl #2
 *   @0x2cc908 vldr s2, [r2, #4]
 *   @0x2cc90c add r3, r1, r3, lsl #2
 *   @0x2cc910 vmov.f32 s8, s2
 *   @0x2cc914 vldr s6, [r3, #4]
 *   @0x2cc918 vldr s9, [r2, #8]
 *   @0x2cc91c vldr s12, [r3, #8]
 *   @0x2cc920 vldr s4, [r3]
 *   @0x2cc924 vldr s1, [r2]
 *   @0x2cc928 vldr s15, [r0, #120]
 *   @0x2cc92c vmov.f32 s23, s6
 *   @0x2cc930 vldr s14, [r0, #116]
 *   @0x2cc934 vldr s20, [r0, #76]
 *   @0x2cc938 vldr s7, [r0, #100]
 *   @0x2cc93c vldr s19, [r0, #96]
 *   @0x2cc940 vldr s13, [r0, #172]
 *   @0x2cc944 vldr s18, [r0, #164]
 *   @0x2cc948 vldr s3, [r0, #156]
 *   @0x2cc94c vmla.f32 s8, s9, s16
 *   @0x2cc950 vldr s5, [r0, #160]
 *   @0x2cc954 vldr s17, [r0, #168]
 *   @0x2cc958 vmla.f32 s23, s12, s0
 *   @0x2cc95c vmov.f32 s22, s4
 *   @0x2cc960 vmov.f32 s21, s1
 *   @0x2cc964 vmls.f32 s22, s12, s11
 *   @0x2cc968 vmls.f32 s21, s9, s10
 *   @0x2cc96c vsub.f32 s8, s23, s8
 *   @0x2cc970 vmul.f32 s8, s8, s15
 *   @0x2cc974 vsub.f32 s21, s22, s21
 *   @0x2cc978 vmla.f32 s8, s21, s14
 *   @0x2cc97c vadd.f32 s8, s8, s20
 *   @0x2cc980 vmla.f32 s8, s7, s19
 *   @0x2cc984 vnmul.f32 s13, s13, s8
 *   @0x2cc988 vmul.f32 s14, s13, s14
 *   @0x2cc98c vmul.f32 s15, s13, s15
 *   @0x2cc990 vmul.f32 s10, s10, s14
 *   @0x2cc994 vmul.f32 s11, s11, s14
 *   @0x2cc998 vnmls.f32 s10, s16, s15
 *   @0x2cc99c vnmls.f32 s11, s0, s15
 *   @0x2cc9a0 vmls.f32 s9, s10, s18
 *   @0x2cc9a4 vmla.f32 s12, s11, s17
 *   @0x2cc9a8 vpop {d8, d9, d10, d11}
 *   @0x2cc9ac vmls.f32 s1, s3, s14
 *   @0x2cc9b0 vmls.f32 s2, s3, s15
 *   @0x2cc9b4 vmla.f32 s4, s5, s14
 *   @0x2cc9b8 vmla.f32 s6, s5, s15
 *   @0x2cc9bc vadd.f32 s13, s7, s13
 *   @0x2cc9c0 vstr s13, [r0, #100]
 *   @0x2cc9c4 vstr s9, [r2, #8]
 *   @0x2cc9c8 vstr s1, [r2]
 *   @0x2cc9cc vstr s2, [r2, #4]
 *   @0x2cc9d0 vstr s12, [r3, #8]
 *   @0x2cc9d4 vstr s4, [r3]
 *   @0x2cc9d8 vstr s6, [r3, #4]
 *   @0x2cc9dc bx lr
 *
 * ══ §45/119 __cxa_call_unexpected  0x3186c8  size 260  65 条（0x3186c8..0x3187cc）
 * @func 0x3186c8 0x3187cc  size 260  65 条
 * 部分覆盖: 本节 65/106 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_3180e8+0x168×2 / anon_317210+0x510×2 / anonT_317798×2 / anon_3180e8+0x4bc×2 / 0xc7879c / anon_317a44+0x100 / anon_317210+0x4c8 / anon_317210+0x414
 * 字段偏移 top8: 0x34×1 / 0x7c×1 / 0x4×1 / 0x8×1 / 0x2c×1 / 0x-28×1 / 0x1c0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x3186c8 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x3186cc mov r4, r0
 *   @0x3186d0 ldrd r2, r3, [r3]
 *   @0x3186d4 sub sp, #0xc
 *   @0x3186d8 cdpmi p1, #0x3, c0, c9, c0, #0x0
 *   @0x3186dc eors r2, r0
 *   @0x3186e0 orrs.w r1, r2, r3
 *   @0x3186e4 add r6, pc
 *   @0x3186e8 beq 0x3186f2 <__cxa_call_unexpected+0x2a>
 *   @0x3186ec .word 0xf7fff819
 *   @0x3186f0 .word 0xf8d4fde7
 *   @0x3186f4 blvs 0xc7879c <b2_toiTime+0x51f2f8>
 *   @0x3186f8 ldr r7, [r4, #0x34]
 *   @0x3186fc .word 0xf854f811
 *   @0x318700 ldrmi r3, [r8, r12, lsr #24]
 *   @0x318704 bl 0x318250 <__gxx_personality_v0+0x2d0>
 *   @0x318708 bl 0x317720 <ft_lzwstate_io+0x76c>
 *   @0x31870c bl 0x318250 <__gxx_personality_v0+0x2d0>
 *   @0x318710 bl 0x317720 <ft_lzwstate_io+0x76c>
 *   @0x318714 mov.w r9, #0x0
 *   @0x318718 bic r11, r5, #0x3
 *   @0x31871c mov r10, r9
 *   @0x318720 beq 0x318778 <__cxa_call_unexpected+0xb0>
 *   @0x318724 bl 0x317b44 <ft_lzwstate_io+0xb90>
 *   @0x318728 mov r5, r0
 *   @0x31872c .word 0x4629fed9
 *   @0x318730 movs r2, #0x0
 *   @0x318734 add.w r0, r3, #0x38
 *   @0x318738 adds r3, #0x90
 *   @0x31873c mov r3, sp
 *   @0x318740 ldmiblt r8, {r0, r3, r4, r5, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x318744 ldr r2, [pc, #0x7c]
 *   @0x318748 str r0, [sp, #0x4]
 *   @0x31874c ldr r1, [r6, r2]
 *   @0x318750 ldr r3, [r3, #0x8]
 *   @0x318754 add.w r9, r9, #0x1
 *   @0x318758 cmp r0, #0x0
 *   @0x31875c movne.w r10, #0x1
 *   @0x318760 add r7, r11
 *   @0x318764 bl 0x317798 <ft_lzwstate_io+0x7e4>
 *   @0x318768 bl 0x3185a4 <__cxa_end_cleanup>
 *   @0x31876c bl 0x3176d8 <ft_lzwstate_io+0x724>
 *   @0x318770 bl 0x317798 <ft_lzwstate_io+0x7e4>
 *   @0x318774 bl 0x3185a4 <__cxa_end_cleanup>
 *   @0x318778 cmp.w r10, #0x0
 *   @0x31877c beq 0x3187a0 <__cxa_call_unexpected+0xd8>
 *   @0x318780 .word 0xf7fff80b
 *   @0x318784 andhs pc, r4, r9, lsl #16
 *   @0x318788 bl 0x317624 <ft_lzwstate_io+0x670>
 *   @0x31878c mov r4, r0
 *   @0x318790 blmi 0x656d04 <g_SWFlinevertbuff+0x3c3c>
 *   @0x318794 mov r0, r4
 *   @0x318798 ldr r3, [pc, #0x2c]
 *   @0x31879c bl 0x3176a0 <ft_lzwstate_io+0x6ec>
 *   @0x3187a0 ldr r3, [r4, #-40]
 *   @0x3187a4 blx r3
 *   @0x3187a8 .word 0xf7feea70
 *   @0x3187ac .word 0xf59effb9
 *   @0x3187b0 .word 0xf7feea6c
 *   @0x3187b4 .word 0xe7dbfff1
 *   @0x3187b8 cmp r3, #0x0
 *   @0x3187bc strb r3, [r0, r5]
 *   @0x3187c0 str r5, [sp, #0x1c0]
 *   @0x3187c4 .word 0xffc8 ffff
 *   @0x3187c8 .word 0xffcc ffff
 *
 * ══ §46/119 Background_CreateNew()  0xc37d4  size 256  64 条（0xc37d4..0xc38d4）
 * @func 0xc37d4 0xc38d4  size 256  64 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::SetLength(void**, unsigned int, char const*, int)×2 / 0xb65c8 / YYStrDup(char const*) / operator new(unsigned int) / CBackground::CBackground() / 0xb65d4
 * 字段偏移 top8: 0x104×2 / 0x2×2 / 0xd8×1 / 0xd4×1 / 0xd0×1 / 0xcc×1 / 0xb0×1 / 0x78×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc37d4 push {r4, r5, r6, r7, r8, lr}
 *   @0xc37d8 sub sp, sp, #264
 *   @0xc37dc ldr r4, [pc, #0xd8]
 *   @0xc37e0 movw r3, #0x16f
 *   @0xc37e4 ldr r5, [pc, #0xd4]
 *   @0xc37e8 ldr r4, [pc, r4]
 *   @0xc37ec ldr r8, [pc, #0xd0]
 *   @0xc37f0 ldr r5, [pc, r5]
 *   @0xc37f4 ldr r7, [pc, #0xcc]
 *   @0xc37f8 ldr r12, [r4]
 *   @0xc37fc add r8, pc, r8
 *   @0xc3800 ldr lr, [r5]
 *   @0xc3804 add r7, pc, r7
 *   @0xc3808 add r12, r12, #1
 *   @0xc380c mov r2, r8
 *   @0xc3810 add r0, r7, #4
 *   @0xc3814 ldr r6, [pc, #0xb0]
 *   @0xc3818 lsl r1, r12, #2
 *   @0xc381c str lr, [sp, #0x104]
 *   @0xc3820 str r12, [r4]
 *   @0xc3824 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0xc3828 ldr r12, [r4]
 *   @0xc382c ldr r6, [pc, r6]
 *   @0xc3830 mov r2, r8
 *   @0xc3834 movw r3, #0x171
 *   @0xc3838 mov r0, r6
 *   @0xc383c add r8, sp, #4
 *   @0xc3840 lsl r1, r12, #2
 *   @0xc3844 str r12, [r7]
 *   @0xc3848 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0xc384c ldr r3, [r4]
 *   @0xc3850 ldr r2, [pc, #0x78]
 *   @0xc3854 mov r1, #256
 *   @0xc3858 mov r0, r8
 *   @0xc385c sub r3, r3, #1
 *   @0xc3860 add r2, pc, r2
 *   @0xc3864 bl 0xb65c8 <snprintf@plt>
 *   @0xc3868 ldr r3, [r4]
 *   @0xc386c mov r0, r8
 *   @0xc3870 ldr r6, [r6]
 *   @0xc3874 sub r8, r3, #-1073741823
 *   @0xc3878 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xc387c str r0, [r6, r8, lsl #2]
 *   @0xc3880 mov r0, #72
 *   @0xc3884 bl 0x27c524 <_Znwj>
 *   @0xc3888 mov r6, r0
 *   @0xc388c bl 0xc2b58 <_ZN11CBackgroundC2Ev>
 *   @0xc3890 ldr r1, [r4]
 *   @0xc3894 ldr r3, [r7, #0x4]
 *   @0xc3898 sub r1, r1, #-1073741823
 *   @0xc389c ldr r2, [sp, #0x104]
 *   @0xc38a0 str r6, [r3, r1, lsl #2]
 *   @0xc38a4 ldr r3, [r5]
 *   @0xc38a8 cmp r2, r3
 *   @0xc38ac bne 0xc38b8 <_Z20Background_CreateNewv+0xe4>
 *   @0xc38b0 add sp, sp, #264
 *   @0xc38b4 pop {r4, r5, r6, r7, r8, pc}
 *   @0xc38b8 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0xc38bc eorseq r10, r2, r0, ror #2
 *   @0xc38c0 eorseq r10, r2, r0, ror #2
 *   @0xc38c4 eoreq sp, r6, r4, lsl #5
 *   @0xc38c8 eorseq r6, r11, r4, lsr #9
 *   @0xc38cc eorseq r10, r2, r0, lsr #2
 *   @0xc38d0 eoreq sp, r6, r12, ror #4
 *
 * ══ §47/119 F_Vertex_Normal_release(RValue&, CInstance*, CInstance*, int, RValue*)  0xc8440  size 256  64 条（0xc8440..0xc8540）
 * @func 0xc8440 0xc8540  size 256  64 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×3 / YYGetInt32(RValue const*, int) / F_Vertex_Normal_release(RValue&, CInstance*, CInstance*, int, RValue*)+0xc0 / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0xc×4 / 0x4×3 / 0x18×2 / 0x14×2 / 0x10×2 / 0xe8×1 / 0x2×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc8440 push {r4, r5, r6, lr}
 *   @0xc8444 sub sp, sp, #8
 *   @0xc8448 ldr r3, [pc, #0xe8]
 *   @0xc844c mov r1, #0
 *   @0xc8450 ldr r5, [sp, #0x18]
 *   @0xc8454 add r3, pc, r3
 *   @0xc8458 mov r0, r5
 *   @0xc845c ldr r4, [r3]
 *   @0xc8460 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc8464 ldr r4, [r4, r0, lsl #2]
 *   @0xc8468 cmp r4, #0
 *   @0xc846c beq 0xc84f8 <_Z23F_Vertex_Normal_releaseR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0xc8470 ldr r1, [r4, #0x2c]
 *   @0xc8474 ldr r3, [r4, #0xc]
 *   @0xc8478 ldr r2, [r4, #0x4]
 *   @0xc847c ldr r1, [r1, #0x14]
 *   @0xc8480 add r0, r1, r3
 *   @0xc8484 cmp r2, r0
 *   @0xc8488 blo 0xc8500 <_Z23F_Vertex_Normal_releaseR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0xc848c ldr r6, [r4]
 *   @0xc8490 mov r1, #1
 *   @0xc8494 mov r0, r5
 *   @0xc8498 add r6, r6, r3
 *   @0xc849c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0xc84a0 mov r1, #2
 *   @0xc84a4 str r0, [r6]
 *   @0xc84a8 mov r0, r5
 *   @0xc84ac bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0xc84b0 mov r1, #3
 *   @0xc84b4 str r0, [r6, #0x4]
 *   @0xc84b8 mov r0, r5
 *   @0xc84bc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0xc84c0 ldr r3, [r4, #0x10]
 *   @0xc84c4 ldr r1, [r4, #0x14]
 *   @0xc84c8 add r3, r3, #1
 *   @0xc84cc ldr r2, [r4, #0xc]
 *   @0xc84d0 cmp r3, r1
 *   @0xc84d4 add r2, r2, #12
 *   @0xc84d8 str r0, [r6, #0x8]
 *   @0xc84dc str r3, [r4, #0x10]
 *   @0xc84e0 ldrhs r3, [r4, #0x1c]
 *   @0xc84e4 str r2, [r4, #0xc]
 *   @0xc84e8 movhs r2, #0
 *   @0xc84ec addhs r3, r3, #1
 *   @0xc84f0 strhs r2, [r4, #0x10]
 *   @0xc84f4 strhs r3, [r4, #0x1c]
 *   @0xc84f8 add sp, sp, #8
 *   @0xc84fc pop {r4, r5, r6, pc}
 *   @0xc8500 add r1, r1, r2
 *   @0xc8504 ldr r0, [r4]
 *   @0xc8508 add r1, r1, r2, lsr #1
 *   @0xc850c mov r2, #0
 *   @0xc8510 str r1, [r4, #0x4]
 *   @0xc8514 mov r3, #74
 *   @0xc8518 str r2, [sp]
 *   @0xc851c ldr r2, [pc, #0x18]
 *   @0xc8520 add r2, pc, r2
 *   @0xc8524 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0xc8528 ldr r3, [r4, #0xc]
 *   @0xc852c mov r6, r0
 *   @0xc8530 str r0, [r4]
 *   @0xc8534 b 0xc8490 <_Z23F_Vertex_Normal_releaseR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0xc8538 eorseq r1, r11, r0, ror #25
 *   @0xc853c eoreq r8, r6, r0, lsl r11
 *
 * ══ §48/119 YYGML_vertex_ubyte4(int, int, int, int, int)  0xca0a0  size 256  64 条（0xca0a0..0xca1a0）
 * @func 0xca0a0 0xca1a0  size 256  64 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGML_vertex_ubyte4(int, int, int, int, int)+0xd8 / YYGML_vertex_ubyte4(int, int, int, int, int)+0xa0 / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool) / YYGML_vertex_ubyte4(int, int, int, int, int)+0x1c
 * 字段偏移 top8: 0xc×4 / 0x4×3 / 0x2×2 / 0x14×2 / 0x10×2 / 0xd0×1 / 0x2c×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xca0a0 cmp r0, #0
 *   @0xca0a4 push {r4, r5, r6, r7, r8, lr}
 *   @0xca0a8 mov r8, r1
 *   @0xca0ac sub sp, sp, #8
 *   @0xca0b0 mov r7, r2
 *   @0xca0b4 mov r6, r3
 *   @0xca0b8 blt 0xca178 <_Z19YYGML_vertex_ubyte4iiiii+0xd8>
 *   @0xca0bc ldr r3, [pc, #0xd0]
 *   @0xca0c0 add r3, pc, r3
 *   @0xca0c4 ldr r3, [r3]
 *   @0xca0c8 ldr r4, [r3, r0, lsl #2]
 *   @0xca0cc ldr r3, [r4, #0x2c]
 *   @0xca0d0 ldr r12, [r4, #0xc]
 *   @0xca0d4 ldr r5, [r4, #0x4]
 *   @0xca0d8 ldr r3, [r3, #0x14]
 *   @0xca0dc add r2, r3, r12
 *   @0xca0e0 cmp r5, r2
 *   @0xca0e4 blo 0xca140 <_Z19YYGML_vertex_ubyte4iiiii+0xa0>
 *   @0xca0e8 ldr r5, [r4]
 *   @0xca0ec ldr r3, [sp, #0x20]
 *   @0xca0f0 add r0, r5, r12
 *   @0xca0f4 strb r8, [r5, r12]
 *   @0xca0f8 strb r7, [r0, #0x1]
 *   @0xca0fc strb r6, [r0, #0x2]
 *   @0xca100 strb r3, [r0, #0x3]
 *   @0xca104 ldr r3, [r4, #0x10]
 *   @0xca108 ldr r1, [r4, #0x14]
 *   @0xca10c add r3, r3, #1
 *   @0xca110 ldr r2, [r4, #0xc]
 *   @0xca114 cmp r3, r1
 *   @0xca118 str r3, [r4, #0x10]
 *   @0xca11c add r3, r2, #4
 *   @0xca120 str r3, [r4, #0xc]
 *   @0xca124 ldrhs r3, [r4, #0x1c]
 *   @0xca128 movhs r2, #0
 *   @0xca12c strhs r2, [r4, #0x10]
 *   @0xca130 addhs r3, r3, #1
 *   @0xca134 strhs r3, [r4, #0x1c]
 *   @0xca138 add sp, sp, #8
 *   @0xca13c pop {r4, r5, r6, r7, r8, pc}
 *   @0xca140 add r3, r3, r5
 *   @0xca144 ldr r0, [r4]
 *   @0xca148 add r1, r3, r5, lsr #1
 *   @0xca14c mov r2, #0
 *   @0xca150 str r1, [r4, #0x4]
 *   @0xca154 mov r3, #74
 *   @0xca158 str r2, [sp]
 *   @0xca15c ldr r2, [pc, #0x34]
 *   @0xca160 add r2, pc, r2
 *   @0xca164 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0xca168 ldr r12, [r4, #0xc]
 *   @0xca16c mov r5, r0
 *   @0xca170 str r0, [r4]
 *   @0xca174 b 0xca0ec <_Z19YYGML_vertex_ubyte4iiiii+0x4c>
 *   @0xca178 ldr r3, [pc, #0x1c]
 *   @0xca17c add r3, pc, r3
 *   @0xca180 ldr r3, [r3, #0x4]
 *   @0xca184 cmp r0, r3
 *   @0xca188 blt 0xca0bc <_Z19YYGML_vertex_ubyte4iiiii+0x1c>
 *   @0xca18c add sp, sp, #8
 *   @0xca190 pop {r4, r5, r6, r7, r8, pc}
 *   @0xca194 eorseq r0, r11, r4, ror r0
 *   @0xca198 .word 0x00266ed0
 *   @0xca19c ldrhteq pc, [r10], -r8
 *
 * ══ §49/119 YYGML_ds_grid_create(int, int)  0x100294  size 256  64 条（0x100294..0x100394）
 * @func 0x100294 0x100394  size 256  64 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x100298→0x483694, 0x1002b0→0x483698
 * 调用序列: YYGML_ds_grid_create(int, int)+0x64 / operator new(unsigned int) / CDS_Grid::CDS_Grid(int, int) / MemoryManager::SetLength(void**, unsigned int, char const*, int)
 * 字段偏移 top8: 0x4×3 / 0xe8×2 / 0xd4×1 / 0x44×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x100294 ldr r3, [pc, #0xe8]
 *   @0x100298 ldr r2, [pc, #0xe8]
 *   @0x10029c add r3, pc, r3
 *   @0x1002a0 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1002a4 mov r7, r0
 *   @0x1002a8 ldr r9, [r3, r2]
 *   @0x1002ac mov r8, r1
 *   @0x1002b0 ldr r2, [pc, #0xd4]
 *   @0x1002b4 ldr r5, [r9]
 *   @0x1002b8 ldr r10, [r3, r2]
 *   @0x1002bc cmp r5, #0
 *   @0x1002c0 ble 0x1002f8 <_Z20YYGML_ds_grid_createii+0x64>
 *   @0x1002c4 ldr r3, [r10, #0x4]
 *   @0x1002c8 ldr r6, [r3]
 *   @0x1002cc cmp r6, #0
 *   @0x1002d0 beq 0x10037c <_Z20YYGML_ds_grid_createii+0xe8>
 *   @0x1002d4 mov r4, #0
 *   @0x1002d8 b 0x1002e8 <_Z20YYGML_ds_grid_createii+0x54>
 *   @0x1002dc ldr r12, [r3, #0x4]!
 *   @0x1002e0 cmp r12, #0
 *   @0x1002e4 beq 0x100318 <_Z20YYGML_ds_grid_createii+0x84>
 *   @0x1002e8 add r4, r4, #1
 *   @0x1002ec cmp r4, r5
 *   @0x1002f0 lsl r6, r4, #2
 *   @0x1002f4 bne 0x1002dc <_Z20YYGML_ds_grid_createii+0x48>
 *   @0x1002f8 ldr r3, [r10]
 *   @0x1002fc cmp r5, r3
 *   @0x100300 movlt r3, r5
 *   @0x100304 bge 0x100340 <_Z20YYGML_ds_grid_createii+0xac>
 *   @0x100308 lsl r6, r5, #2
 *   @0x10030c mov r4, r5
 *   @0x100310 add r3, r3, #1
 *   @0x100314 str r3, [r9]
 *   @0x100318 mov r0, #12
 *   @0x10031c bl 0x27c524 <_Znwj>
 *   @0x100320 mov r1, r7
 *   @0x100324 mov r2, r8
 *   @0x100328 mov r5, r0
 *   @0x10032c bl 0x20b10c <_ZN8CDS_GridC2Eii>
 *   @0x100330 ldr r3, [r10, #0x4]
 *   @0x100334 mov r0, r4
 *   @0x100338 str r5, [r3, r6]
 *   @0x10033c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x100340 add r1, r5, #16
 *   @0x100344 ldr r2, [pc, #0x44]
 *   @0x100348 mov r3, #2304
 *   @0x10034c add r0, r10, #4
 *   @0x100350 add r2, pc, r2
 *   @0x100354 lsl r1, r1, #2
 *   @0x100358 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x10035c ldr r3, [r9]
 *   @0x100360 lsl r6, r5, #2
 *   @0x100364 mov r4, r5
 *   @0x100368 add r2, r3, #16
 *   @0x10036c add r3, r3, #1
 *   @0x100370 str r2, [r10]
 *   @0x100374 str r3, [r9]
 *   @0x100378 b 0x100318 <_Z20YYGML_ds_grid_createii+0x84>
 *   @0x10037c mov r4, r6
 *   @0x100380 b 0x100318 <_Z20YYGML_ds_grid_createii+0x84>
 *   @0x100384 .word 0x002f19b4
 *   @0x100388 .word 0xffffc234
 *   @0x10038c .word 0xffffc238
 *   @0x100390 eoreq r7, r3, r12, asr #16
 *
 * ══ §50/119 YYGML_position_meeting(CInstance*, CInstance*, float, float, int)  0x10d8f8  size 256  64 条（0x10d8f8..0x10d9f8）
 * @func 0x10d8f8 0x10d9f8  size 256  64 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ShouldUseFastCollision(int, CObjectGM**) / Command_ObjectAt(float, float, int) / UpdateTree() / RTree<CInstance*, int, float, 6, 2>::Search(int const*, int const*, bool (*)(CInstance*, void*), void*)
 * 字段偏移 top8: 0x38×1 / 0x-14×1 / 0x58×1 / 0x50×1 / 0x4c×1 / 0x4×1 / 0x10×1 / 0x18×1
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10d8f8 push {r4, r5, r6, r7, r8, lr}
 *   @0x10d8fc sub sp, sp, #32
 *   @0x10d900 mov r7, r2
 *   @0x10d904 adds r2, r0, #0
 *   @0x10d908 ldr r4, [sp, #0x38]
 *   @0x10d90c mov r6, r3
 *   @0x10d910 movne r2, #1
 *   @0x10d914 mov r5, #0
 *   @0x10d918 cmn r4, #1
 *   @0x10d91c movne r2, #0
 *   @0x10d920 cmp r2, #0
 *   @0x10d924 ldrne r4, [r0, #0x78]
 *   @0x10d928 adds r3, r1, #0
 *   @0x10d92c movne r3, #1
 *   @0x10d930 cmn r4, #2
 *   @0x10d934 movne r3, #0
 *   @0x10d938 cmp r3, #0
 *   @0x10d93c ldrne r4, [r1, #0x78]
 *   @0x10d940 add r1, sp, #32
 *   @0x10d944 str r5, [r1, #-0x14]!
 *   @0x10d948 mov r0, r4
 *   @0x10d94c bl 0x1c8df8 <_Z22ShouldUseFastCollisioniPP9CObjectGM>
 *   @0x10d950 cmp r0, #1
 *   @0x10d954 beq 0x10d984 <_Z22YYGML_position_meetingP9CInstanceS0_ffi+0x8c>
 *   @0x10d958 cmp r0, #2
 *   @0x10d95c movne r0, r5
 *   @0x10d960 beq 0x10d96c <_Z22YYGML_position_meetingP9CInstanceS0_ffi+0x74>
 *   @0x10d964 add sp, sp, #32
 *   @0x10d968 pop {r4, r5, r6, r7, r8, pc}
 *   @0x10d96c mov r0, r7
 *   @0x10d970 mov r2, r4
 *   @0x10d974 mov r1, r6
 *   @0x10d978 bl 0x1c9da8 <_Z16Command_ObjectAtffi>
 *   @0x10d97c add sp, sp, #32
 *   @0x10d980 pop {r4, r5, r6, r7, r8, pc}
 *   @0x10d984 bl 0x1cc24c <_Z10UpdateTreev>
 *   @0x10d988 vmov s15, r7
 *   @0x10d98c ldr r2, [pc, #0x58]
 *   @0x10d990 add r1, sp, #16
 *   @0x10d994 vcvt.s32.f32 s15, s15
 *   @0x10d998 ldr r8, [pc, #0x50]
 *   @0x10d99c ldr r2, [pc, r2]
 *   @0x10d9a0 ldr r3, [pc, #0x4c]
 *   @0x10d9a4 add r8, pc, r8
 *   @0x10d9a8 ldr r0, [r2]
 *   @0x10d9ac ldr r3, [pc, r3]
 *   @0x10d9b0 str r4, [sp]
 *   @0x10d9b4 add r2, sp, #24
 *   @0x10d9b8 strb r5, [r8]
 *   @0x10d9bc vmov r7, s15
 *   @0x10d9c0 vmov s15, r6
 *   @0x10d9c4 vcvt.s32.f32 s15, s15
 *   @0x10d9c8 vstr s15, [r8, #8]
 *   @0x10d9cc vstr s15, [sp, #20]
 *   @0x10d9d0 vstr s15, [sp, #28]
 *   @0x10d9d4 str r7, [r8, #0x4]
 *   @0x10d9d8 str r7, [sp, #0x10]
 *   @0x10d9dc str r7, [sp, #0x18]
 *   @0x10d9e0 bl 0x10d720 <_ZN5RTreeIP9CInstanceifLi6ELi2EE6SearchEPKiS4_PFbS1_PvES5_>
 *   @0x10d9e4 ldrb r0, [r8]
 *   @0x10d9e8 b 0x10d964 <_Z22YYGML_position_meetingP9CInstanceS0_ffi+0x6c>
 *   @0x10d9ec eoreq r0, lr, r8, lsr #17
 *   @0x10d9f0 eorseq r5, r7, r4, lsr sp
 *   @0x10d9f4 mlaeq lr, r4, r8, r0
 *
 * ══ §51/119 F_SkeletonDrawCollision(RValue&, CInstance*, CInstance*, int, RValue*)  0x11d8c0  size 256  64 条（0x11d8c0..0x11d9c0）
 * @func 0x11d8c0 0x11d9c0  size 256  64 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×5 / YYGetInt32(RValue const*, int)×3 / Sprite_Data(int) / YYGetString(RValue const*, int) / CSkeletonSprite::DrawCollision(char const*, int, float, float, float, float, float, unsigned int)
 * 字段偏移 top8: 0xc×2 / 0x1c×2 / 0x48×1 / 0x74×1 / 0x58×1 / 0x4×1 / 0x8×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11d8c0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x11d8c4 sub sp, sp, #36
 *   @0x11d8c8 mov r1, #0
 *   @0x11d8cc str r1, [r0, #0xc]
 *   @0x11d8d0 ldr r4, [sp, #0x48]
 *   @0x11d8d4 mov r2, r1
 *   @0x11d8d8 movt r2, #0xbff0
 *   @0x11d8dc stm r0, {r1, r2}
 *   @0x11d8e0 mov r0, r4
 *   @0x11d8e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11d8e8 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x11d8ec subs r3, r0, #0
 *   @0x11d8f0 beq 0x11d900 <_Z23F_SkeletonDrawCollisionR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x11d8f4 ldr r5, [r3, #0x74]
 *   @0x11d8f8 cmp r5, #2
 *   @0x11d8fc beq 0x11d908 <_Z23F_SkeletonDrawCollisionR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x11d900 add sp, sp, #36
 *   @0x11d904 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x11d908 mov r0, r4
 *   @0x11d90c mov r1, #1
 *   @0x11d910 ldr r6, [r3, #0x58]
 *   @0x11d914 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x11d918 mov r1, r5
 *   @0x11d91c mov r8, r0
 *   @0x11d920 mov r0, r4
 *   @0x11d924 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11d928 mov r1, #3
 *   @0x11d92c mov r7, r0
 *   @0x11d930 mov r0, r4
 *   @0x11d934 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11d938 mov r1, #4
 *   @0x11d93c mov r5, r0
 *   @0x11d940 mov r0, r4
 *   @0x11d944 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11d948 mov r1, #5
 *   @0x11d94c mov r3, r0
 *   @0x11d950 mov r0, r4
 *   @0x11d954 str r3, [sp, #0x1c]
 *   @0x11d958 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11d95c mov r1, #6
 *   @0x11d960 mov r11, r0
 *   @0x11d964 mov r0, r4
 *   @0x11d968 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11d96c mov r1, #7
 *   @0x11d970 mov r10, r0
 *   @0x11d974 mov r0, r4
 *   @0x11d978 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11d97c mov r1, #8
 *   @0x11d980 mov r9, r0
 *   @0x11d984 mov r0, r4
 *   @0x11d988 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11d98c ldr r3, [sp, #0x1c]
 *   @0x11d990 str r11, [sp, #0x4]
 *   @0x11d994 mov r1, r8
 *   @0x11d998 str r10, [sp, #0x8]
 *   @0x11d99c mov r2, r7
 *   @0x11d9a0 str r3, [sp]
 *   @0x11d9a4 mov r3, r5
 *   @0x11d9a8 str r9, [sp, #0xc]
 *   @0x11d9ac str r0, [sp, #0x10]
 *   @0x11d9b0 mov r0, r6
 *   @0x11d9b4 bl 0xbe9fc <_ZN15CSkeletonSprite13DrawCollisionEPKcifffffj>
 *   @0x11d9b8 add sp, sp, #36
 *   @0x11d9bc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §52/119 F_DrawTextExtColor(RValue&, CInstance*, CInstance*, int, RValue*)  0x1221d0  size 256  64 条（0x1221d0..0x1222d0）
 * @func 0x1221d0 0x1222d0  size 256  64 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×6 / YYGetFloat(RValue const*, int)×3 / GetTextFromArg(RValue const*, int, char**) / GR_Text_Draw_Color(float, float, char const*, int, int, unsigned int, unsigned int, unsigned int, unsigned int, float) / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x24×2 / 0x18×2 / 0x1c×2 / 0x50×1 / 0x-4×1 / 0x8×1 / 0x4×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1221d0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1221d4 sub sp, sp, #44
 *   @0x1221d8 add r2, sp, #40
 *   @0x1221dc mov r5, #0
 *   @0x1221e0 ldr r4, [sp, #0x50]
 *   @0x1221e4 mov r1, #1024
 *   @0x1221e8 str r5, [r2, #-0x4]!
 *   @0x1221ec add r0, r4, #32
 *   @0x1221f0 bl 0x121ce0 <_Z14GetTextFromArgPK6RValueiPPc>
 *   @0x1221f4 mov r1, r5
 *   @0x1221f8 mov r0, r4
 *   @0x1221fc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x122200 mov r1, #1
 *   @0x122204 mov r5, r0
 *   @0x122208 mov r0, r4
 *   @0x12220c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x122210 mov r1, #3
 *   @0x122214 ldr r11, [sp, #0x24]
 *   @0x122218 mov r6, r0
 *   @0x12221c mov r0, r4
 *   @0x122220 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x122224 mov r1, #4
 *   @0x122228 mov r9, r0
 *   @0x12222c mov r0, r4
 *   @0x122230 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x122234 mov r1, #5
 *   @0x122238 mov r2, r0
 *   @0x12223c mov r0, r4
 *   @0x122240 str r2, [sp, #0x18]
 *   @0x122244 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x122248 mov r1, #6
 *   @0x12224c mov r3, r0
 *   @0x122250 mov r0, r4
 *   @0x122254 str r3, [sp, #0x1c]
 *   @0x122258 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12225c mov r1, #7
 *   @0x122260 mov r10, r0
 *   @0x122264 mov r0, r4
 *   @0x122268 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12226c mov r1, #8
 *   @0x122270 mov r8, r0
 *   @0x122274 mov r0, r4
 *   @0x122278 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12227c mov r1, #9
 *   @0x122280 mov r7, r0
 *   @0x122284 mov r0, r4
 *   @0x122288 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x12228c ldr r2, [sp, #0x18]
 *   @0x122290 ldr r3, [sp, #0x1c]
 *   @0x122294 mov r1, r6
 *   @0x122298 str r10, [sp, #0x8]
 *   @0x12229c str r2, [sp]
 *   @0x1222a0 mov r2, r11
 *   @0x1222a4 str r3, [sp, #0x4]
 *   @0x1222a8 mov r3, r9
 *   @0x1222ac str r8, [sp, #0xc]
 *   @0x1222b0 str r7, [sp, #0x10]
 *   @0x1222b4 str r0, [sp, #0x14]
 *   @0x1222b8 mov r0, r5
 *   @0x1222bc bl 0x173338 <_Z18GR_Text_Draw_ColorffPKciijjjjf>
 *   @0x1222c0 ldr r0, [sp, #0x24]
 *   @0x1222c4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1222c8 add sp, sp, #44
 *   @0x1222cc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §53/119 F_FontReplaceSprite(RValue&, CInstance*, CInstance*, int, RValue*)  0x12d11c  size 256  64 条（0x12d11c..0x12d21c）
 * @func 0x12d11c 0x12d230  size 276  69 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×4 / Error_Show_Action(char const*, bool)×2 / Font_Exists(int) / Sprite_Exists(int) / YYGetBool(RValue const*, int) / Font_ReplaceSprite(int, int, int, bool, int)
 * 字段偏移 top8: 0xc×3 / 0x4×2 / 0x28×1 / 0xa0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12d11c push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x12d120 sub sp, sp, #12
 *   @0x12d124 mov r1, #0
 *   @0x12d128 mov r5, r0
 *   @0x12d12c ldr r4, [sp, #0x28]
 *   @0x12d130 mov r0, r4
 *   @0x12d134 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12d138 mov r1, #1
 *   @0x12d13c mov r6, r0
 *   @0x12d140 mov r0, r4
 *   @0x12d144 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12d148 mov r8, r0
 *   @0x12d14c mov r0, r6
 *   @0x12d150 bl 0xfa2a8 <_Z11Font_Existsi>
 *   @0x12d154 subs r1, r0, #0
 *   @0x12d158 beq 0x12d204 <_Z19F_FontReplaceSpriteR6RValueP9CInstanceS2_iPS_+0xe8>
 *   @0x12d15c mov r0, r6
 *   @0x12d160 bl 0x1eee98 <_Z13Sprite_Existsi>
 *   @0x12d164 subs r7, r0, #0
 *   @0x12d168 bne 0x12d198 <_Z19F_FontReplaceSpriteR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0x12d16c ldr r0, [pc, #0xa0]
 *   @0x12d170 mov r1, r7
 *   @0x12d174 add r0, pc, r0
 *   @0x12d178 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x12d17c str r7, [r5, #0xc]
 *   @0x12d180 mov r3, #0
 *   @0x12d184 str r3, [r5]
 *   @0x12d188 mov r2, r3
 *   @0x12d18c str r2, [r5, #0x4]
 *   @0x12d190 add sp, sp, #12
 *   @0x12d194 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x12d198 mov r1, #2
 *   @0x12d19c mov r0, r4
 *   @0x12d1a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12d1a4 mov r1, #3
 *   @0x12d1a8 mov r9, r0
 *   @0x12d1ac mov r0, r4
 *   @0x12d1b0 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x12d1b4 mov r1, #4
 *   @0x12d1b8 mov r7, r0
 *   @0x12d1bc mov r0, r4
 *   @0x12d1c0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12d1c4 mov r2, r9
 *   @0x12d1c8 mov r3, r7
 *   @0x12d1cc mov r1, r8
 *   @0x12d1d0 str r0, [sp]
 *   @0x12d1d4 mov r0, r6
 *   @0x12d1d8 bl 0xfa9c4 <_Z18Font_ReplaceSpriteiiibi>
 *   @0x12d1dc mov r3, #0
 *   @0x12d1e0 str r3, [r5, #0xc]
 *   @0x12d1e4 cmp r0, r3
 *   @0x12d1e8 movne r2, #0
 *   @0x12d1ec movtne r2, #0x3ff0
 *   @0x12d1f0 beq 0x12d180 <_Z19F_FontReplaceSpriteR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x12d1f4 str r3, [r5]
 *   @0x12d1f8 str r2, [r5, #0x4]
 *   @0x12d1fc add sp, sp, #12
 *   @0x12d200 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x12d204 ldr r0, [pc, #0xc]
 *   @0x12d208 add r0, pc, r0
 *   @0x12d20c bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x12d210 b 0x12d15c <_Z19F_FontReplaceSpriteR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x12d214 eoreq r0, r1, r4, lsr #8
 *   @0x12d218 eoreq r0, r1, r8, ror #6
 *
 * ══ §54/119 F_FontReplaceSpriteExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x12d21c  size 256  64 条（0x12d21c..0x12d31c）
 * @func 0x12d21c 0x12d31c  size 256  64 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / Error_Show_Action(char const*, bool)×2 / Font_Exists(int) / Sprite_Exists(int) / YYGetString(RValue const*, int) / YYGetBool(RValue const*, int) / Font_ReplaceSpriteExt(int, int, char const*, bool, int)
 * 字段偏移 top8: 0xc×3 / 0x4×2 / 0x28×1 / 0xa0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12d21c push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x12d220 sub sp, sp, #12
 *   @0x12d224 mov r1, #0
 *   @0x12d228 mov r5, r0
 *   @0x12d22c ldr r4, [sp, #0x28]
 *   @0x12d230 mov r0, r4
 *   @0x12d234 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12d238 mov r1, #1
 *   @0x12d23c mov r6, r0
 *   @0x12d240 mov r0, r4
 *   @0x12d244 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12d248 mov r8, r0
 *   @0x12d24c mov r0, r6
 *   @0x12d250 bl 0xfa2a8 <_Z11Font_Existsi>
 *   @0x12d254 subs r1, r0, #0
 *   @0x12d258 beq 0x12d304 <_Z22F_FontReplaceSpriteExtR6RValueP9CInstanceS2_iPS_+0xe8>
 *   @0x12d25c mov r0, r6
 *   @0x12d260 bl 0x1eee98 <_Z13Sprite_Existsi>
 *   @0x12d264 subs r7, r0, #0
 *   @0x12d268 bne 0x12d298 <_Z22F_FontReplaceSpriteExtR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0x12d26c ldr r0, [pc, #0xa0]
 *   @0x12d270 mov r1, r7
 *   @0x12d274 add r0, pc, r0
 *   @0x12d278 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x12d27c str r7, [r5, #0xc]
 *   @0x12d280 mov r3, #0
 *   @0x12d284 str r3, [r5]
 *   @0x12d288 mov r2, r3
 *   @0x12d28c str r2, [r5, #0x4]
 *   @0x12d290 add sp, sp, #12
 *   @0x12d294 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x12d298 mov r1, #2
 *   @0x12d29c mov r0, r4
 *   @0x12d2a0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x12d2a4 mov r1, #3
 *   @0x12d2a8 mov r9, r0
 *   @0x12d2ac mov r0, r4
 *   @0x12d2b0 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x12d2b4 mov r1, #4
 *   @0x12d2b8 mov r7, r0
 *   @0x12d2bc mov r0, r4
 *   @0x12d2c0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12d2c4 mov r2, r9
 *   @0x12d2c8 mov r3, r7
 *   @0x12d2cc mov r1, r8
 *   @0x12d2d0 str r0, [sp]
 *   @0x12d2d4 mov r0, r6
 *   @0x12d2d8 bl 0xfab0c <_Z21Font_ReplaceSpriteExtiiPKcbi>
 *   @0x12d2dc mov r3, #0
 *   @0x12d2e0 str r3, [r5, #0xc]
 *   @0x12d2e4 cmp r0, r3
 *   @0x12d2e8 movne r2, #0
 *   @0x12d2ec movtne r2, #0x3ff0
 *   @0x12d2f0 beq 0x12d280 <_Z22F_FontReplaceSpriteExtR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x12d2f4 str r3, [r5]
 *   @0x12d2f8 str r2, [r5, #0x4]
 *   @0x12d2fc add sp, sp, #12
 *   @0x12d300 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x12d304 ldr r0, [pc, #0xc]
 *   @0x12d308 add r0, pc, r0
 *   @0x12d30c bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x12d310 b 0x12d25c <_Z22F_FontReplaceSpriteExtR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x12d314 eoreq r0, r1, r4, lsr #6
 *   @0x12d318 eoreq r0, r1, r8, ror #4
 *
 * ══ §55/119 F_RoomSetBackground(RValue&, CInstance*, CInstance*, int, RValue*)  0x12e5a8  size 256  64 条（0x12e5a8..0x12e6a8）
 * @func 0x12e5a8 0x12e6a8  size 256  64 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×5 / YYGetBool(RValue const*, int)×4 / YYGetInt32(RValue const*, int)×3 / Room_Data(int)
 * 字段偏移 top8: 0x10×2 / 0x24×1 / 0x1×1 / 0x4×1 / 0x8×1 / 0xc×1 / 0x1c×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12e5a8 push {r4, r5, r6, lr}
 *   @0x12e5ac mov r1, #0
 *   @0x12e5b0 ldr r4, [sp, #0x10]
 *   @0x12e5b4 mov r0, r4
 *   @0x12e5b8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e5bc mov r1, #1
 *   @0x12e5c0 mov r6, r0
 *   @0x12e5c4 mov r0, r4
 *   @0x12e5c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e5cc mov r5, r0
 *   @0x12e5d0 mov r0, r6
 *   @0x12e5d4 bl 0x1b52c4 <_Z9Room_Datai>
 *   @0x12e5d8 cmp r0, #0
 *   @0x12e5dc popeq {r4, r5, r6, pc}
 *   @0x12e5e0 cmp r5, #7
 *   @0x12e5e4 pophi {r4, r5, r6, pc}
 *   @0x12e5e8 add r5, r0, r5, lsl #2
 *   @0x12e5ec ldr r5, [r5, #0x24]
 *   @0x12e5f0 cmp r5, #0
 *   @0x12e5f4 popeq {r4, r5, r6, pc}
 *   @0x12e5f8 mov r1, #2
 *   @0x12e5fc mov r0, r4
 *   @0x12e600 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x12e604 mov r1, #3
 *   @0x12e608 strb r0, [r5]
 *   @0x12e60c mov r0, r4
 *   @0x12e610 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x12e614 mov r1, #4
 *   @0x12e618 strb r0, [r5, #0x1]
 *   @0x12e61c mov r0, r4
 *   @0x12e620 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e624 mov r1, #5
 *   @0x12e628 str r0, [r5, #0x4]
 *   @0x12e62c mov r0, r4
 *   @0x12e630 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x12e634 mov r1, #6
 *   @0x12e638 str r0, [r5, #0x8]
 *   @0x12e63c mov r0, r4
 *   @0x12e640 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x12e644 mov r1, #7
 *   @0x12e648 str r0, [r5, #0xc]
 *   @0x12e64c mov r0, r4
 *   @0x12e650 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x12e654 mov r1, #8
 *   @0x12e658 strb r0, [r5, #0x10]
 *   @0x12e65c mov r0, r4
 *   @0x12e660 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x12e664 mov r3, #1065353216
 *   @0x12e668 mov r1, #9
 *   @0x12e66c str r3, [r5, #0x1c]
 *   @0x12e670 str r3, [r5, #0x20]
 *   @0x12e674 strb r0, [r5, #0x11]
 *   @0x12e678 mov r0, r4
 *   @0x12e67c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x12e680 mov r1, #10
 *   @0x12e684 str r0, [r5, #0x14]
 *   @0x12e688 mov r0, r4
 *   @0x12e68c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x12e690 mov r1, #11
 *   @0x12e694 str r0, [r5, #0x18]
 *   @0x12e698 mov r0, r4
 *   @0x12e69c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x12e6a0 str r0, [r5, #0x28]
 *   @0x12e6a4 pop {r4, r5, r6, pc}
 *
 * ══ §56/119 F_SpriteMerge(RValue&, CInstance*, CInstance*, int, RValue*)  0x1301cc  size 256  64 条（0x1301cc..0x1302cc）
 * @func 0x1301cc 0x1302cc  size 256  64 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / Sprite_Data(int)×2
 * 字段偏移 top8: 0x74×2 / 0x10×1 / 0x5c×1 / 0x4c×1 / 0x3c×1 / 0x2c×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1301cc push {r4, r5, r6, lr}
 *   @0x1301d0 mov r1, #0
 *   @0x1301d4 ldr r4, [sp, #0x10]
 *   @0x1301d8 mov r0, r4
 *   @0x1301dc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1301e0 mov r1, #1
 *   @0x1301e4 mov r5, r0
 *   @0x1301e8 mov r0, r4
 *   @0x1301ec bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1301f0 mov r6, r0
 *   @0x1301f4 mov r0, r5
 *   @0x1301f8 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x1301fc mov r4, r0
 *   @0x130200 mov r0, r6
 *   @0x130204 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x130208 cmp r0, #0
 *   @0x13020c cmpne r4, #0
 *   @0x130210 mov r1, r0
 *   @0x130214 moveq r3, #0
 *   @0x130218 movne r3, #1
 *   @0x13021c beq 0x130254 <_Z13F_SpriteMergeR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x130220 ldr r3, [r4, #0x74]
 *   @0x130224 cmp r3, #1
 *   @0x130228 beq 0x13027c <_Z13F_SpriteMergeR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0x13022c ldr r2, [r0, #0x74]
 *   @0x130230 cmp r2, #1
 *   @0x130234 beq 0x130290 <_Z13F_SpriteMergeR6RValueP9CInstanceS2_iPS_+0xc4>
 *   @0x130238 cmp r3, #2
 *   @0x13023c beq 0x1302a4 <_Z13F_SpriteMergeR6RValueP9CInstanceS2_iPS_+0xd8>
 *   @0x130240 cmp r2, #2
 *   @0x130244 beq 0x130268 <_Z13F_SpriteMergeR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x130248 mov r0, r4
 *   @0x13024c pop {r4, r5, r6, lr}
 *   @0x130250 b 0x1e5b2c <_ZN7CSprite13AddFromSpriteEPS_>
 *   @0x130254 ldr r0, [pc, #0x5c]
 *   @0x130258 mov r1, r3
 *   @0x13025c pop {r4, r5, r6, lr}
 *   @0x130260 add r0, pc, r0
 *   @0x130264 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x130268 ldr r0, [pc, #0x4c]
 *   @0x13026c mov r1, #0
 *   @0x130270 pop {r4, r5, r6, lr}
 *   @0x130274 add r0, pc, r0
 *   @0x130278 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x13027c ldr r0, [pc, #0x3c]
 *   @0x130280 mov r1, #0
 *   @0x130284 pop {r4, r5, r6, lr}
 *   @0x130288 add r0, pc, r0
 *   @0x13028c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x130290 ldr r0, [pc, #0x2c]
 *   @0x130294 mov r1, #0
 *   @0x130298 pop {r4, r5, r6, lr}
 *   @0x13029c add r0, pc, r0
 *   @0x1302a0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1302a4 ldr r0, [pc, #0x1c]
 *   @0x1302a8 mov r1, #0
 *   @0x1302ac pop {r4, r5, r6, lr}
 *   @0x1302b0 add r0, pc, r0
 *   @0x1302b4 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1302b8 eoreq sp, r0, r0, asr sp
 *   @0x1302bc eoreq sp, r0, r0, ror #25
 *   @0x1302c0 .word 0x0020dbbc
 *   @0x1302c4 eoreq sp, r0, r0, lsl #24
 *   @0x1302c8 eoreq sp, r0, r0, asr #24
 *
 * ══ §57/119 F_FontReplace(RValue&, CInstance*, CInstance*, int, RValue*)  0x130ef8  size 256  64 条（0x130ef8..0x130ff8）
 * @func 0x130ef8 0x130ff8  size 256  64 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×4 / YYGetBool(RValue const*, int)×2 / Font_Exists(int) / Error_Show_Action(char const*, bool) / YYGetString(RValue const*, int) / Font_Replace(int, char const*, int, bool, bool, int, int)
 * 字段偏移 top8: 0x4×3 / 0xc×2 / 0x38×1 / 0xc8×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x130ef8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x130efc sub sp, sp, #20
 *   @0x130f00 mov r1, #0
 *   @0x130f04 mov r5, r0
 *   @0x130f08 ldr r4, [sp, #0x38]
 *   @0x130f0c mov r0, r4
 *   @0x130f10 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x130f14 mov r7, r0
 *   @0x130f18 bl 0xfa2a8 <_Z11Font_Existsi>
 *   @0x130f1c subs r6, r0, #0
 *   @0x130f20 bne 0x130f50 <_Z13F_FontReplaceR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x130f24 ldr r0, [pc, #0xc8]
 *   @0x130f28 mov r1, r6
 *   @0x130f2c add r0, pc, r0
 *   @0x130f30 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x130f34 str r6, [r5, #0xc]
 *   @0x130f38 mov r3, #0
 *   @0x130f3c str r3, [r5]
 *   @0x130f40 mov r2, r3
 *   @0x130f44 str r2, [r5, #0x4]
 *   @0x130f48 add sp, sp, #20
 *   @0x130f4c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x130f50 mov r1, #1
 *   @0x130f54 mov r0, r4
 *   @0x130f58 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x130f5c mov r1, #2
 *   @0x130f60 mov r9, r0
 *   @0x130f64 mov r0, r4
 *   @0x130f68 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x130f6c mov r1, #3
 *   @0x130f70 mov r8, r0
 *   @0x130f74 mov r0, r4
 *   @0x130f78 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x130f7c mov r1, #4
 *   @0x130f80 mov r6, r0
 *   @0x130f84 mov r0, r4
 *   @0x130f88 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x130f8c mov r1, #5
 *   @0x130f90 mov r11, r0
 *   @0x130f94 mov r0, r4
 *   @0x130f98 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x130f9c mov r1, #6
 *   @0x130fa0 mov r10, r0
 *   @0x130fa4 mov r0, r4
 *   @0x130fa8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x130fac mov r2, r8
 *   @0x130fb0 mov r3, r6
 *   @0x130fb4 str r11, [sp]
 *   @0x130fb8 str r10, [sp, #0x4]
 *   @0x130fbc mov r1, r9
 *   @0x130fc0 str r0, [sp, #0x8]
 *   @0x130fc4 mov r0, r7
 *   @0x130fc8 bl 0xfa908 <_Z12Font_ReplaceiPKcibbii>
 *   @0x130fcc mov r3, #0
 *   @0x130fd0 str r3, [r5, #0xc]
 *   @0x130fd4 cmp r0, r3
 *   @0x130fd8 movne r2, #0
 *   @0x130fdc movtne r2, #0x3ff0
 *   @0x130fe0 beq 0x130f38 <_Z13F_FontReplaceR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x130fe4 str r3, [r5]
 *   @0x130fe8 str r2, [r5, #0x4]
 *   @0x130fec add sp, sp, #20
 *   @0x130ff0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x130ff4 eoreq r12, r0, r4, asr #12
 *
 * ══ §58/119 CBitmap32::ImproveBoundary()  0x166304  size 256  64 条（0x166304..0x166404）
 * @func 0x166304 0x166404  size 256  64 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CBitmap32::ImproveBoundary()+0xf8 / CBitmap32::ImproveBoundary()+0xe8 / CBitmap32::ImproveBoundary()+0x94 / CBitmap32::ImproveBoundary()+0xac / CBitmap32::ImproveBoundary()+0xd8
 * 字段偏移 top8: 0x2×4 / 0xc×3 / 0x4×2 / 0x8×2 / 0x14×1 / 0x-4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x166304 ldrb r3, [r0, #0x4]
 *   @0x166308 push {r4, r5, r6, r7, r8, r9}
 *   @0x16630c cmp r3, #0
 *   @0x166310 beq 0x1663fc <_ZN9CBitmap3215ImproveBoundaryEv+0xf8>
 *   @0x166314 ldr r4, [r0, #0xc]
 *   @0x166318 cmp r4, #0
 *   @0x16631c beq 0x1663fc <_ZN9CBitmap3215ImproveBoundaryEv+0xf8>
 *   @0x166320 ldr r1, [r0, #0x8]
 *   @0x166324 cmp r1, #0
 *   @0x166328 beq 0x1663fc <_ZN9CBitmap3215ImproveBoundaryEv+0xf8>
 *   @0x16632c cmp r4, #0
 *   @0x166330 ble 0x1663fc <_ZN9CBitmap3215ImproveBoundaryEv+0xf8>
 *   @0x166334 mov r7, #1
 *   @0x166338 mov r5, #0
 *   @0x16633c cmp r1, #0
 *   @0x166340 movle r9, r7
 *   @0x166344 ble 0x1663ec <_ZN9CBitmap3215ImproveBoundaryEv+0xe8>
 *   @0x166348 ldr r12, [r0, #0x14]
 *   @0x16634c sub r8, r5, #1
 *   @0x166350 mov r9, r7
 *   @0x166354 mov r3, #0
 *   @0x166358 mla r2, r1, r5, r3
 *   @0x16635c ldr r4, [r12, r2, lsl #2]
 *   @0x166360 add r6, r12, r2, lsl #2
 *   @0x166364 tst r4, #-16777216
 *   @0x166368 bne 0x1663dc <_ZN9CBitmap3215ImproveBoundaryEv+0xd8>
 *   @0x16636c cmp r3, #0
 *   @0x166370 beq 0x166380 <_ZN9CBitmap3215ImproveBoundaryEv+0x7c>
 *   @0x166374 ldr r4, [r6, #-0x4]
 *   @0x166378 tst r4, #-16777216
 *   @0x16637c bne 0x1663d0 <_ZN9CBitmap3215ImproveBoundaryEv+0xcc>
 *   @0x166380 sub r4, r1, #1
 *   @0x166384 cmp r4, r3
 *   @0x166388 ble 0x166398 <_ZN9CBitmap3215ImproveBoundaryEv+0x94>
 *   @0x16638c ldr r4, [r6, #0x4]
 *   @0x166390 tst r4, #-16777216
 *   @0x166394 bne 0x1663d0 <_ZN9CBitmap3215ImproveBoundaryEv+0xcc>
 *   @0x166398 cmp r5, #0
 *   @0x16639c ble 0x1663b0 <_ZN9CBitmap3215ImproveBoundaryEv+0xac>
 *   @0x1663a0 mla r4, r1, r8, r3
 *   @0x1663a4 ldr r4, [r12, r4, lsl #2]
 *   @0x1663a8 tst r4, #-16777216
 *   @0x1663ac bne 0x1663d0 <_ZN9CBitmap3215ImproveBoundaryEv+0xcc>
 *   @0x1663b0 ldr r4, [r0, #0xc]
 *   @0x1663b4 sub r4, r4, #1
 *   @0x1663b8 cmp r4, r5
 *   @0x1663bc ble 0x1663dc <_ZN9CBitmap3215ImproveBoundaryEv+0xd8>
 *   @0x1663c0 mla r4, r7, r1, r3
 *   @0x1663c4 ldr r4, [r12, r4, lsl #2]
 *   @0x1663c8 tst r4, #-16777216
 *   @0x1663cc beq 0x1663dc <_ZN9CBitmap3215ImproveBoundaryEv+0xd8>
 *   @0x1663d0 bic r4, r4, #-16777216
 *   @0x1663d4 str r4, [r12, r2, lsl #2]
 *   @0x1663d8 ldr r1, [r0, #0x8]
 *   @0x1663dc add r3, r3, #1
 *   @0x1663e0 cmp r1, r3
 *   @0x1663e4 bgt 0x166358 <_ZN9CBitmap3215ImproveBoundaryEv+0x54>
 *   @0x1663e8 ldr r4, [r0, #0xc]
 *   @0x1663ec cmp r4, r9
 *   @0x1663f0 add r5, r5, #1
 *   @0x1663f4 add r7, r7, #1
 *   @0x1663f8 bgt 0x16633c <_ZN9CBitmap3215ImproveBoundaryEv+0x38>
 *   @0x1663fc pop {r4, r5, r6, r7, r8, r9}
 *   @0x166400 bx lr
 *
 * ══ §59/119 GR_Draw_RoundRect_Ext(float, float, float, float, float, float, unsigned int, unsigned int, bool)  0x16b864  size 256  64 条（0x16b864..0x16b964）
 * @func 0x16b864 0x16b964  size 256  64 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6598×2 / GR_Color_To_D3DColor(unsigned int, unsigned int)×2
 * 字段偏移 top8: 0x38×2 / 0x30×2 / 0x34×2 / 0x3c×2 / 0x40×2 / 0xe4×1
 * VFP 指令 38 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16b864 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x16b868 vpush {d8, d9}
 *   @0x16b86c vmov s17, r2
 *   @0x16b870 vmov s18, r0
 *   @0x16b874 ldr r4, [pc, #0xe4]
 *   @0x16b878 vmov s16, r3
 *   @0x16b87c ldr r7, [sp, #0x38]
 *   @0x16b880 vcmpe.f32 s17, s18
 *   @0x16b884 ldr r9, [sp, #0x30]
 *   @0x16b888 vmov s19, r1
 *   @0x16b88c ldr r8, [sp, #0x34]
 *   @0x16b890 ldr r6, [sp, #0x3c]
 *   @0x16b894 ldrb r5, [sp, #0x40]
 *   @0x16b898 vmrs APSR_nzcv, fpscr
 *   @0x16b89c vmovmi.f32 s15, s18
 *   @0x16b8a0 vmovmi.f32 s18, s17
 *   @0x16b8a4 vmovmi.f32 s17, s15
 *   @0x16b8a8 vcmpe.f32 s16, s19
 *   @0x16b8ac vcvt.f64.f32 d6, s17
 *   @0x16b8b0 vmrs APSR_nzcv, fpscr
 *   @0x16b8b4 vmovmi.f32 s15, s19
 *   @0x16b8b8 vmov r0, r1, d6
 *   @0x16b8bc vmovmi.f32 s19, s16
 *   @0x16b8c0 vmovmi.f32 s16, s15
 *   @0x16b8c4 bl 0xb6598 <floor@plt>
 *   @0x16b8c8 vmov d6, r0, r1
 *   @0x16b8cc vcvt.s32.f64 s15, d6
 *   @0x16b8d0 vcvt.f32.s32 s15, s15
 *   @0x16b8d4 vcmp.f32 s15, s17
 *   @0x16b8d8 vmrs APSR_nzcv, fpscr
 *   @0x16b8dc vldreq s15, [pc, #120]
 *   @0x16b8e0 vaddeq.f32 s17, s17, s15
 *   @0x16b8e4 vcvt.f64.f32 d7, s16
 *   @0x16b8e8 vmov r0, r1, d7
 *   @0x16b8ec bl 0xb6598 <floor@plt>
 *   @0x16b8f0 ldr r4, [pc, r4]
 *   @0x16b8f4 vmov d6, r0, r1
 *   @0x16b8f8 ldr r1, [r4]
 *   @0x16b8fc mov r0, r7
 *   @0x16b900 vcvt.s32.f64 s15, d6
 *   @0x16b904 vcvt.f32.s32 s15, s15
 *   @0x16b908 vcmp.f32 s15, s16
 *   @0x16b90c vmrs APSR_nzcv, fpscr
 *   @0x16b910 vldreq s15, [pc, #68]
 *   @0x16b914 vaddeq.f32 s16, s16, s15
 *   @0x16b918 bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj>
 *   @0x16b91c ldr r1, [r4]
 *   @0x16b920 mov r7, r0
 *   @0x16b924 mov r0, r6
 *   @0x16b928 bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj>
 *   @0x16b92c str r7, [sp, #0x38]
 *   @0x16b930 str r9, [sp, #0x30]
 *   @0x16b934 str r8, [sp, #0x34]
 *   @0x16b938 str r5, [sp, #0x40]
 *   @0x16b93c vmov r1, s19
 *   @0x16b940 vmov r2, s17
 *   @0x16b944 vmov r3, s16
 *   @0x16b948 str r0, [sp, #0x3c]
 *   @0x16b94c vmov r0, s18
 *   @0x16b950 vpop {d8, d9}
 *   @0x16b954 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x16b958 b 0x16b31c <_Z15_Draw_RoundRectffffffjjb>
 *   @0x16b95c stclo p7, c13, [r3], #-40
 *   @0x16b960 eoreq r2, r8, r0, lsl r4
 *
 * ══ §60/119 CheckSequence(int*, int*, int)  0x17b4cc  size 256  64 条（0x17b4cc..0x17b5cc）
 * @func 0x17b4cc 0x17b5cc  size 256  64 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Window_Get_Region_Width() / GR_Window_Get_Region_Height() / CheckSequence(int*, int*, int)+0xec
 * 字段偏移 top8: 0xe0×1 / 0xc8×1 / 0x70×1 / 0x2×1
 * VFP 指令 19 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17b4cc push {r3, r4, r5, r6, r7, lr}
 *   @0x17b4d0 vpush {d8, d9}
 *   @0x17b4d4 mov r6, r1
 *   @0x17b4d8 ldr r3, [pc, #0xe0]
 *   @0x17b4dc mov r7, r2
 *   @0x17b4e0 mov r5, r0
 *   @0x17b4e4 vmov.f32 s16, #1.000000e+01
 *   @0x17b4e8 ldr r3, [pc, r3]
 *   @0x17b4ec vldr s18, [r3]
 *   @0x17b4f0 bl 0x179988 <_Z26GR_Window_Get_Region_Widthv>
 *   @0x17b4f4 ldr r3, [pc, #0xc8]
 *   @0x17b4f8 ldr r3, [pc, r3]
 *   @0x17b4fc vldr s17, [r3]
 *   @0x17b500 vcvt.f32.s32 s18, s18
 *   @0x17b504 vcvt.f32.s32 s17, s17
 *   @0x17b508 vmov s14, r0
 *   @0x17b50c vcvt.f32.s32 s15, s14
 *   @0x17b510 vdiv.f32 s18, s18, s15
 *   @0x17b514 bl 0x17999c <_Z27GR_Window_Get_Region_Heightv>
 *   @0x17b518 vmov s14, r0
 *   @0x17b51c vcvt.f32.s32 s15, s14
 *   @0x17b520 vdiv.f32 s17, s17, s15
 *   @0x17b524 vmul.f32 s18, s18, s16
 *   @0x17b528 vmul.f32 s16, s17, s16
 *   @0x17b52c vcvt.s32.f32 s18, s18
 *   @0x17b530 vcvt.s32.f32 s16, s16
 *   @0x17b534 vmov r4, s18
 *   @0x17b538 vmov r3, s16
 *   @0x17b53c cmp r3, #9
 *   @0x17b540 cmpls r4, #9
 *   @0x17b544 movhi r0, #0
 *   @0x17b548 movls r0, #1
 *   @0x17b54c bhi 0x17b5b8 <_Z13CheckSequencePiS_i+0xec>
 *   @0x17b550 ldr r2, [pc, #0x70]
 *   @0x17b554 ldr r2, [pc, r2]
 *   @0x17b558 ldr r2, [r2]
 *   @0x17b55c ldr r1, [r6, r2, lsl #2]
 *   @0x17b560 ubfx r0, r1, #0x8, #0x8
 *   @0x17b564 ubfx r2, r1, #0x10, #0x8
 *   @0x17b568 uxtb r1, r1
 *   @0x17b56c rsb r3, r0, r3
 *   @0x17b570 rsb r4, r1, r4
 *   @0x17b574 cmp r3, #0
 *   @0x17b578 rsblt r3, r3, #0
 *   @0x17b57c cmp r4, #0
 *   @0x17b580 rsblt r4, r4, #0
 *   @0x17b584 cmp r2, r3
 *   @0x17b588 cmpge r2, r4
 *   @0x17b58c movlt r0, #0
 *   @0x17b590 movge r0, #1
 *   @0x17b594 strlt r0, [r5]
 *   @0x17b598 blt 0x17b5b8 <_Z13CheckSequencePiS_i+0xec>
 *   @0x17b59c ldr r3, [r5]
 *   @0x17b5a0 add r3, r3, #1
 *   @0x17b5a4 cmp r7, r3
 *   @0x17b5a8 movne r0, #0
 *   @0x17b5ac moveq r0, #1
 *   @0x17b5b0 moveq r3, #0
 *   @0x17b5b4 str r3, [r5]
 *   @0x17b5b8 vpop {d8, d9}
 *   @0x17b5bc pop {r3, r4, r5, r6, r7, pc}
 *   @0x17b5c0 eoreq r4, r7, r12, ror lr
 *   @0x17b5c4 eoreq r4, r7, r0, ror lr
 *   @0x17b5c8 eoreq r4, r7, r8, lsl lr
 *
 * ══ §61/119 CGCGeneration::Reset()  0x19140c  size 256  64 条（0x19140c..0x19150c）
 * @func 0x19140c 0x19150c  size 256  64 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CGCGeneration::ResetDynamicRoots() / MemoryManager::Free(void const*) / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb65b0 / CGCGeneration::Reset()+0xb0
 * 字段偏移 top8: 0x10×4 / 0x8×2 / 0xc0×1 / 0x4×1 / 0x44×1 / 0x18×1 / 0x14×1 / 0x1c×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19140c push {r3, r4, r5, r6, r7, lr}
 *   @0x191410 mov r4, r0
 *   @0x191414 bl 0x191400 <_ZN13CGCGeneration17ResetDynamicRootsEv>
 *   @0x191418 ldr r5, [r4]
 *   @0x19141c ldr r0, [r5, #0x10]
 *   @0x191420 cmp r0, #0
 *   @0x191424 beq 0x19142c <_ZN13CGCGeneration5ResetEv+0x20>
 *   @0x191428 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x19142c mov r6, #0
 *   @0x191430 str r6, [r5, #0x10]
 *   @0x191434 ldr r5, [r4]
 *   @0x191438 mov r2, #70
 *   @0x19143c ldr r1, [pc, #0xc0]
 *   @0x191440 mov r3, #1
 *   @0x191444 ldr r0, [r5]
 *   @0x191448 add r1, pc, r1
 *   @0x19144c sub r12, r0, #1
 *   @0x191450 str r12, [r5, #0x8]
 *   @0x191454 add r0, r0, r0, lsl #1
 *   @0x191458 lsl r7, r0, #2
 *   @0x19145c mov r0, r7
 *   @0x191460 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x191464 mov r2, r7
 *   @0x191468 mov r1, r6
 *   @0x19146c str r0, [r5, #0x10]
 *   @0x191470 bl 0xb65b0 <memset@plt>
 *   @0x191474 ldr r2, [r5]
 *   @0x191478 vldr s15, [pc, #128]
 *   @0x19147c str r6, [r5, #0x4]
 *   @0x191480 cmp r2, r6
 *   @0x191484 vmov s13, r2
 *   @0x191488 vcvt.f32.s32 s14, s13
 *   @0x19148c vmul.f32 s15, s14, s15
 *   @0x191490 vcvt.s32.f32 s15, s15
 *   @0x191494 vstr s15, [r5, #12]
 *   @0x191498 ble 0x1914bc <_ZN13CGCGeneration5ResetEv+0xb0>
 *   @0x19149c ldr r3, [r5, #0x10]
 *   @0x1914a0 add r2, r2, r2, lsl #1
 *   @0x1914a4 mov r1, r6
 *   @0x1914a8 add r2, r3, r2, lsl #2
 *   @0x1914ac str r1, [r3, #0x8]
 *   @0x1914b0 add r3, r3, #12
 *   @0x1914b4 cmp r3, r2
 *   @0x1914b8 bne 0x1914ac <_ZN13CGCGeneration5ResetEv+0xa0>
 *   @0x1914bc ldr r3, [pc, #0x44]
 *   @0x1914c0 mvn r2, #0
 *   @0x1914c4 mvn r1, #-2147483648
 *   @0x1914c8 str r2, [r4, #0x18]
 *   @0x1914cc ldr r3, [pc, r3]
 *   @0x1914d0 str r1, [r4, #0x14]
 *   @0x1914d4 str r2, [r4, #0x1c]
 *   @0x1914d8 ldr r3, [r3]
 *   @0x1914dc str r3, [r4, #0x2c]
 *   @0x1914e0 mov r3, #0
 *   @0x1914e4 str r3, [r4, #0x20]
 *   @0x1914e8 str r3, [r4, #0x24]
 *   @0x1914ec str r3, [r4, #0x28]
 *   @0x1914f0 str r3, [r4, #0x30]
 *   @0x1914f4 str r3, [r4, #0x34]
 *   @0x1914f8 str r3, [r4, #0x38]
 *   @0x1914fc pop {r3, r4, r5, r6, r7, pc}
 *   @0x191500 svclo #0x19999a
 *   @0x191504 andseq pc, r9, r8, ror #23
 *   @0x191508 eoreq r12, r5, r4, asr #15
 *
 * ══ §62/119 CPath::Draw(float, float, bool)  0x1a7ac0  size 256  64 条（0x1a7ac0..0x1a7bc0）
 * @func 0x1a7ac0 0x1a7bc0  size 256  64 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPath::GetPosition(float, float&, float&, float&)×2 / CPath::GetPathLength() / 0xb66e8 / GR_Draw_Primitive_Begin(int, int) / CPath::Draw(float, float, bool)+0xf0 / GR_Draw_Vertex(float, float) / GR_Draw_Primitive_End()
 * 字段偏移 top8: 无
 * VFP 指令 26 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a7ac0 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x1a7ac4 vpush {d8, d9}
 *   @0x1a7ac8 sub sp, sp, #28
 *   @0x1a7acc add r6, sp, #12
 *   @0x1a7ad0 add r7, sp, #16
 *   @0x1a7ad4 mov r4, r3
 *   @0x1a7ad8 vmov s17, r2
 *   @0x1a7adc mov r3, r7
 *   @0x1a7ae0 mov r2, r6
 *   @0x1a7ae4 vmov s16, r1
 *   @0x1a7ae8 add r8, sp, #20
 *   @0x1a7aec mov r1, #0
 *   @0x1a7af0 str r8, [sp]
 *   @0x1a7af4 mov r5, r0
 *   @0x1a7af8 bl 0x1a73bc <_ZN5CPath11GetPositionEfRfS0_S0_>
 *   @0x1a7afc cmp r4, #0
 *   @0x1a7b00 mov r0, r5
 *   @0x1a7b04 vldreq s15, [sp, #16]
 *   @0x1a7b08 vldreq s14, [sp, #12]
 *   @0x1a7b0c vsubeq.f32 s17, s17, s15
 *   @0x1a7b10 vsubeq.f32 s16, s16, s14
 *   @0x1a7b14 bl 0x1a7ab8 <_ZN5CPath13GetPathLengthEv>
 *   @0x1a7b18 vmov.f32 s15, #2.500000e-01
 *   @0x1a7b1c vmov s12, r0
 *   @0x1a7b20 vmul.f32 s15, s12, s15
 *   @0x1a7b24 vcvt.f64.f32 d6, s15
 *   @0x1a7b28 vmov r0, r1, d6
 *   @0x1a7b2c bl 0xb66e8 <lrint@plt>
 *   @0x1a7b30 subs r9, r0, #0
 *   @0x1a7b34 bne 0x1a7b44 <_ZN5CPath4DrawEffb+0x84>
 *   @0x1a7b38 add sp, sp, #28
 *   @0x1a7b3c vpop {d8, d9}
 *   @0x1a7b40 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x1a7b44 mov r0, #3
 *   @0x1a7b48 mvn r1, #0
 *   @0x1a7b4c bl 0x16b964 <_Z23GR_Draw_Primitive_Beginii>
 *   @0x1a7b50 cmp r9, #0
 *   @0x1a7b54 blt 0x1a7bb0 <_ZN5CPath4DrawEffb+0xf0>
 *   @0x1a7b58 vmov s13, r9
 *   @0x1a7b5c mov r4, #0
 *   @0x1a7b60 vcvt.f32.s32 s18, s13
 *   @0x1a7b64 vmov s14, r4
 *   @0x1a7b68 mov r0, r5
 *   @0x1a7b6c mov r2, r6
 *   @0x1a7b70 mov r3, r7
 *   @0x1a7b74 str r8, [sp]
 *   @0x1a7b78 add r4, r4, #1
 *   @0x1a7b7c vcvt.f32.s32 s15, s14
 *   @0x1a7b80 vdiv.f32 s15, s15, s18
 *   @0x1a7b84 vmov r1, s15
 *   @0x1a7b88 bl 0x1a73bc <_ZN5CPath11GetPositionEfRfS0_S0_>
 *   @0x1a7b8c vldr s14, [sp, #12]
 *   @0x1a7b90 vldr s15, [sp, #16]
 *   @0x1a7b94 vadd.f32 s14, s16, s14
 *   @0x1a7b98 vadd.f32 s15, s17, s15
 *   @0x1a7b9c vmov r0, s14
 *   @0x1a7ba0 vmov r1, s15
 *   @0x1a7ba4 bl 0x16ba58 <_Z14GR_Draw_Vertexff>
 *   @0x1a7ba8 cmp r9, r4
 *   @0x1a7bac bge 0x1a7b64 <_ZN5CPath4DrawEffb+0xa4>
 *   @0x1a7bb0 bl 0x16bdb0 <_Z21GR_Draw_Primitive_Endv>
 *   @0x1a7bb4 add sp, sp, #28
 *   @0x1a7bb8 vpop {d8, d9}
 *   @0x1a7bbc pop {r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §63/119 CStream::Write(void*, int)  0x2014c8  size 256  64 条（0x2014c8..0x2015c8）
 * @func 0x2014c8 0x2015c8  size 256  64 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::Write(void*, int)+0xd0 / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool) / 0xb65bc
 * 字段偏移 top8: 0x18×3 / 0xc×2 / 0x84×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2014c8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2014cc subs r11, r2, #0
 *   @0x2014d0 mov r10, r0
 *   @0x2014d4 sub sp, sp, #20
 *   @0x2014d8 mov r12, r1
 *   @0x2014dc movle r0, #0
 *   @0x2014e0 ble 0x201598 <_ZN7CStream5WriteEPvi+0xd0>
 *   @0x2014e4 cmp r1, #0
 *   @0x2014e8 beq 0x2015b0 <_ZN7CStream5WriteEPvi+0xe8>
 *   @0x2014ec ldrd r6, r7, [r10, #8]
 *   @0x2014f0 asr r5, r11, #31
 *   @0x2014f4 ldrd r0, r1, [r10, #16]
 *   @0x2014f8 mov r4, r11
 *   @0x2014fc mov r8, r6
 *   @0x201500 mov r9, r7
 *   @0x201504 subs r8, r8, r0
 *   @0x201508 sbc r9, r9, r1
 *   @0x20150c cmp r8, r4
 *   @0x201510 sbcs r3, r9, r5
 *   @0x201514 bge 0x2015b8 <_ZN7CStream5WriteEPvi+0xf0>
 *   @0x201518 adds r2, r11, r0
 *   @0x20151c lsl r6, r6, #1
 *   @0x201520 adc r3, r5, r1
 *   @0x201524 mov r9, #0
 *   @0x201528 mov r8, r6
 *   @0x20152c cmp r2, r8
 *   @0x201530 sbcs lr, r3, r9
 *   @0x201534 bge 0x2015a0 <_ZN7CStream5WriteEPvi+0xd8>
 *   @0x201538 ldr r2, [pc, #0x84]
 *   @0x20153c mov r3, #0
 *   @0x201540 ldr r0, [r10, #0x18]
 *   @0x201544 mov r1, r6
 *   @0x201548 str r3, [sp]
 *   @0x20154c add r2, pc, r2
 *   @0x201550 movw r3, #0x1ad
 *   @0x201554 str r12, [sp, #0xc]
 *   @0x201558 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x20155c strd r8, r9, [r10, #8]
 *   @0x201560 ldr r12, [sp, #0xc]
 *   @0x201564 cmp r0, #0
 *   @0x201568 str r0, [r10, #0x18]
 *   @0x20156c beq 0x201598 <_ZN7CStream5WriteEPvi+0xd0>
 *   @0x201570 ldr r3, [r10, #0x10]
 *   @0x201574 add r0, r0, r3
 *   @0x201578 mov r2, r11
 *   @0x20157c mov r1, r12
 *   @0x201580 bl 0xb65bc <memcpy@plt>
 *   @0x201584 ldrd r2, r3, [r10, #16]
 *   @0x201588 mov r0, r11
 *   @0x20158c adds r4, r4, r2
 *   @0x201590 adc r5, r5, r3
 *   @0x201594 strd r4, r5, [r10, #16]
 *   @0x201598 add sp, sp, #20
 *   @0x20159c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2015a0 add r6, r11, r0
 *   @0x2015a4 mov r9, #0
 *   @0x2015a8 mov r8, r6
 *   @0x2015ac b 0x201538 <_ZN7CStream5WriteEPvi+0x70>
 *   @0x2015b0 mov r0, r1
 *   @0x2015b4 b 0x201598 <_ZN7CStream5WriteEPvi+0xd0>
 *   @0x2015b8 mov r3, r0
 *   @0x2015bc ldr r0, [r10, #0x18]
 *   @0x2015c0 b 0x201574 <_ZN7CStream5WriteEPvi+0xac>
 *   @0x2015c4 ldrsbeq r2, [r5], -r12
 *
 * ══ §64/119 CDS_Grid::Get_Sum(RValue&, int, int, int, int)  0x2041c8  size 256  64 条（0x2041c8..0x2042c8）
 * @func 0x2041c8 0x2042c8  size 256  64 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int) / CDS_Grid::Get_Sum(RValue&, int, int, int, int)+0xa0
 * 字段偏移 top8: 0x4×3 / 0x20×1 / 0xc×1 / 0x24×1 / 0x8×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2041c8 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2041cc mov r8, r1
 *   @0x2041d0 ldr r12, [sp, #0x20]
 *   @0x2041d4 mov r9, r0
 *   @0x2041d8 mov r0, #0
 *   @0x2041dc str r0, [r8]
 *   @0x2041e0 cmp r2, r12
 *   @0x2041e4 str r0, [r8, #0x4]
 *   @0x2041e8 str r0, [r8, #0xc]
 *   @0x2041ec lsrge r0, r12, #31
 *   @0x2041f0 lsrlt r0, r2, #31
 *   @0x2041f4 ldr r1, [sp, #0x24]
 *   @0x2041f8 cmp r2, r12
 *   @0x2041fc movlt r5, r2
 *   @0x204200 movge r5, r12
 *   @0x204204 cmp r0, #0
 *   @0x204208 movne r5, #0
 *   @0x20420c cmp r3, r1
 *   @0x204210 movlt r0, r3
 *   @0x204214 movge r0, r1
 *   @0x204218 cmp r3, r1
 *   @0x20421c lsrlt r7, r3, #31
 *   @0x204220 lsrge r7, r1, #31
 *   @0x204224 cmp r2, r12
 *   @0x204228 movge r6, r2
 *   @0x20422c movlt r6, r12
 *   @0x204230 cmp r7, #0
 *   @0x204234 ldr r12, [r9, #0x4]
 *   @0x204238 moveq r7, r0
 *   @0x20423c movne r7, #0
 *   @0x204240 cmp r3, r1
 *   @0x204244 movge r10, r3
 *   @0x204248 movlt r10, r1
 *   @0x20424c cmp r6, r12
 *   @0x204250 subge r3, r12, #1
 *   @0x204254 movlt r3, r6
 *   @0x204258 cmp r5, r3
 *   @0x20425c bgt 0x2042c4 <_ZN8CDS_Grid7Get_SumER6RValueiiii+0xfc>
 *   @0x204260 mov r4, r7
 *   @0x204264 b 0x204298 <_ZN8CDS_Grid7Get_SumER6RValueiiii+0xd0>
 *   @0x204268 ldr r0, [r9]
 *   @0x20426c add r0, r0, r3, lsl #4
 *   @0x204270 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x204274 ldm r8, {r2, r3}
 *   @0x204278 vmov d6, r2, r3
 *   @0x20427c vmov d7, r0, r1
 *   @0x204280 vadd.f64 d6, d6, d7
 *   @0x204284 vmov r0, r1, d6
 *   @0x204288 vmov r2, s12
 *   @0x20428c mov r3, r1
 *   @0x204290 stm r8, {r2, r3}
 *   @0x204294 ldr r12, [r9, #0x4]
 *   @0x204298 ldr r2, [r9, #0x8]
 *   @0x20429c mov r3, r10
 *   @0x2042a0 mov r1, #0
 *   @0x2042a4 cmp r10, r2
 *   @0x2042a8 subge r3, r2, #1
 *   @0x2042ac cmp r4, r3
 *   @0x2042b0 mla r3, r12, r4, r5
 *   @0x2042b4 add r4, r4, #1
 *   @0x2042b8 ble 0x204268 <_ZN8CDS_Grid7Get_SumER6RValueiiii+0xa0>
 *   @0x2042bc add r5, r5, #1
 *   @0x2042c0 b 0x20424c <_ZN8CDS_Grid7Get_SumER6RValueiiii+0x84>
 *   @0x2042c4 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *
 * ══ §65/119 CSound::LoadFromStream(CStream*)  0x215398  size 256  64 条（0x215398..0x215498）
 * @func 0x215398 0x215498  size 256  64 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::ReadInteger()×3 / MemoryManager::Free(void const*)×2 / CStream::ReadString(char const*&)×2 / CStream::ReadBoolean()×2 / CStream::ReadReal()×2 / CSound::Clear() / CStream::ReadStream() / CStream::SkipCompressedStream()
 * 字段偏移 top8: 0x8×2 / 0xc×2 / 0x10×2 / 0x4×1 / 0x18×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x215398 push {r3, r4, r5, r6, r7, lr}
 *   @0x21539c mov r4, r1
 *   @0x2153a0 mov r5, r0
 *   @0x2153a4 bl 0x21529c <_ZN6CSound5ClearEv>
 *   @0x2153a8 mov r0, r4
 *   @0x2153ac bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x2153b0 cmp r0, #800
 *   @0x2153b4 cmpne r0, #600
 *   @0x2153b8 mov r6, r0
 *   @0x2153bc moveq r7, #0
 *   @0x2153c0 movne r7, #1
 *   @0x2153c4 movne r3, #0
 *   @0x2153c8 beq 0x2153d4 <_ZN6CSound14LoadFromStreamEP7CStream+0x3c>
 *   @0x2153cc mov r0, r3
 *   @0x2153d0 pop {r3, r4, r5, r6, r7, pc}
 *   @0x2153d4 mov r0, r4
 *   @0x2153d8 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x2153dc ldr r3, [r5, #0x8]
 *   @0x2153e0 cmp r3, #0
 *   @0x2153e4 str r0, [r5, #0x4]
 *   @0x2153e8 beq 0x2153f8 <_ZN6CSound14LoadFromStreamEP7CStream+0x60>
 *   @0x2153ec mov r0, r3
 *   @0x2153f0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x2153f4 str r7, [r5, #0x8]
 *   @0x2153f8 mov r0, r4
 *   @0x2153fc add r1, r5, #8
 *   @0x215400 bl 0x2018e8 <_ZN7CStream10ReadStringERPKc>
 *   @0x215404 ldr r0, [r5, #0xc]
 *   @0x215408 cmp r0, #0
 *   @0x21540c beq 0x21541c <_ZN6CSound14LoadFromStreamEP7CStream+0x84>
 *   @0x215410 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x215414 mov r3, #0
 *   @0x215418 str r3, [r5, #0xc]
 *   @0x21541c mov r0, r4
 *   @0x215420 add r1, r5, #12
 *   @0x215424 bl 0x2018e8 <_ZN7CStream10ReadStringERPKc>
 *   @0x215428 mov r0, r4
 *   @0x21542c bl 0x2019b0 <_ZN7CStream11ReadBooleanEv>
 *   @0x215430 cmp r0, #0
 *   @0x215434 beq 0x21544c <_ZN6CSound14LoadFromStreamEP7CStream+0xb4>
 *   @0x215438 cmp r6, #600
 *   @0x21543c mov r0, r4
 *   @0x215440 beq 0x215488 <_ZN6CSound14LoadFromStreamEP7CStream+0xf0>
 *   @0x215444 bl 0x2019c4 <_ZN7CStream10ReadStreamEv>
 *   @0x215448 str r0, [r5, #0x10]
 *   @0x21544c mov r0, r4
 *   @0x215450 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x215454 str r0, [r5, #0x18]
 *   @0x215458 mov r0, r4
 *   @0x21545c bl 0x20187c <_ZN7CStream8ReadRealEv>
 *   @0x215460 strd r0, r1, [r5, #32]
 *   @0x215464 mov r0, r4
 *   @0x215468 bl 0x20187c <_ZN7CStream8ReadRealEv>
 *   @0x21546c strd r0, r1, [r5, #40]
 *   @0x215470 mov r0, r4
 *   @0x215474 bl 0x2019b0 <_ZN7CStream11ReadBooleanEv>
 *   @0x215478 mov r3, #1
 *   @0x21547c strb r0, [r5, #0x14]
 *   @0x215480 mov r0, r3
 *   @0x215484 pop {r3, r4, r5, r6, r7, pc}
 *   @0x215488 bl 0x201d88 <_ZN7CStream20SkipCompressedStreamEv>
 *   @0x21548c mov r3, #0
 *   @0x215490 str r3, [r5, #0x10]
 *   @0x215494 b 0x21544c <_ZN6CSound14LoadFromStreamEP7CStream+0xb4>
 *
 * ══ §66/119 Sound_End()  0x21fa6c  size 256  64 条（0x21fa6c..0x21fb6c）
 * @func 0x21fa6c 0x21fb6c  size 256  64 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / Sound_End()+0xb0 / CSound::~CSound() / operator delete(void*) / Sound_End()+0x44
 * 字段偏移 top8: 0x4×5 / 0xe0×1 / 0xbc×1 / 0xb8×1 / 0x2×1 / 0x38×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21fa6c push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x21fa70 ldr r8, [pc, #0xe0]
 *   @0x21fa74 add r8, pc, r8
 *   @0x21fa78 ldr r3, [r8]
 *   @0x21fa7c cmp r3, #0
 *   @0x21fa80 popeq {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x21fa84 ldr r5, [r8, #0x4]
 *   @0x21fa88 cmp r5, #0
 *   @0x21fa8c beq 0x21fb48 <_Z9Sound_Endv+0xdc>
 *   @0x21fa90 cmp r3, #0
 *   @0x21fa94 ble 0x21fb1c <_Z9Sound_Endv+0xb0>
 *   @0x21fa98 ldr r10, [pc, #0xbc]
 *   @0x21fa9c mov r4, #0
 *   @0x21faa0 ldr r11, [pc, #0xb8]
 *   @0x21faa4 mov r9, r4
 *   @0x21faa8 add r10, pc, r10
 *   @0x21faac add r11, pc, r11
 *   @0x21fab0 ldr r1, [r5]
 *   @0x21fab4 movw r3, #0xfeee
 *   @0x21fab8 movt r3, #0xfeee
 *   @0x21fabc movw r2, #0xfeee
 *   @0x21fac0 cmp r1, r3
 *   @0x21fac4 movt r2, #0xfeee
 *   @0x21fac8 lsl r7, r4, #2
 *   @0x21facc beq 0x21fb0c <_Z9Sound_Endv+0xa0>
 *   @0x21fad0 ldr r6, [r5, r4, lsl #2]
 *   @0x21fad4 add r3, r5, r7
 *   @0x21fad8 cmp r6, #0
 *   @0x21fadc mov r0, r6
 *   @0x21fae0 beq 0x21fb0c <_Z9Sound_Endv+0xa0>
 *   @0x21fae4 ldr r1, [r6]
 *   @0x21fae8 cmp r1, r2
 *   @0x21faec beq 0x21fb04 <_Z9Sound_Endv+0x98>
 *   @0x21faf0 bl 0x215384 <_ZN6CSoundD2Ev>
 *   @0x21faf4 mov r0, r6
 *   @0x21faf8 bl 0x27d1d0 <_ZdlPv>
 *   @0x21fafc ldr r3, [r11, #0x4]
 *   @0x21fb00 add r3, r3, r7
 *   @0x21fb04 str r9, [r3]
 *   @0x21fb08 ldr r5, [r10, #0x4]
 *   @0x21fb0c ldr r3, [r8]
 *   @0x21fb10 add r4, r4, #1
 *   @0x21fb14 cmp r4, r3
 *   @0x21fb18 blt 0x21fab0 <_Z9Sound_Endv+0x44>
 *   @0x21fb1c mov r0, r5
 *   @0x21fb20 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x21fb24 ldr r3, [pc, #0x38]
 *   @0x21fb28 mov r2, #0
 *   @0x21fb2c add r3, pc, r3
 *   @0x21fb30 str r2, [r3, #0x4]
 *   @0x21fb34 ldr r3, [pc, #0x2c]
 *   @0x21fb38 mov r2, #0
 *   @0x21fb3c add r3, pc, r3
 *   @0x21fb40 str r2, [r3]
 *   @0x21fb44 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x21fb48 mov r0, r5
 *   @0x21fb4c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x21fb50 str r5, [r8, #0x4]
 *   @0x21fb54 b 0x21fb34 <_Z9Sound_Endv+0xc8>
 *   @0x21fb58 subseq r5, r3, r4, asr #17
 *   @0x21fb5c .word 0x00535890
 *   @0x21fb60 subseq r5, r3, r12, lsl #17
 *   @0x21fb64 subseq r5, r3, r12, lsl #16
 *   @0x21fb68 ldrsheq r5, [r3], #-124
 *
 * ══ §67/119 d2b_D2A  0x23da24  size 256  64 条（0x23da24..0x23db24）
 * @func 0x23da24 0x23db24  size 256  64 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: lo0bits_D2A×2 / Balloc_D2A / hi0bits_D2A
 * 字段偏移 top8: 0x10×3 / 0x4×2 / 0x14×2 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23da24 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x23da28 mov r4, r0
 *   @0x23da2c sub sp, sp, #12
 *   @0x23da30 mov r0, #1
 *   @0x23da34 mov r5, r1
 *   @0x23da38 mov r8, r3
 *   @0x23da3c ubfx r7, r1, #0x14, #0xb
 *   @0x23da40 mov r9, r2
 *   @0x23da44 bl 0x23d1f8 <Balloc_D2A>
 *   @0x23da48 cmp r7, #0
 *   @0x23da4c ubfx r3, r5, #0x0, #0x14
 *   @0x23da50 str r4, [sp]
 *   @0x23da54 orrne r3, r3, #1048576
 *   @0x23da58 cmp r4, #0
 *   @0x23da5c str r3, [sp, #0x4]
 *   @0x23da60 mov r6, r0
 *   @0x23da64 beq 0x23dad4 <d2b_D2A+0xb0>
 *   @0x23da68 mov r0, sp
 *   @0x23da6c bl 0x23d2d4 <lo0bits_D2A>
 *   @0x23da70 cmp r0, #0
 *   @0x23da74 rsbne r1, r0, #32
 *   @0x23da78 ldrne r3, [sp, #0x4]
 *   @0x23da7c ldmeq sp, {r3, r4}
 *   @0x23da80 ldrne r2, [sp]
 *   @0x23da84 lsrne r4, r3, r0
 *   @0x23da88 strne r4, [sp, #0x4]
 *   @0x23da8c orrne r3, r2, r3, lsl r1
 *   @0x23da90 cmp r4, #0
 *   @0x23da94 str r4, [r6, #0x18]
 *   @0x23da98 moveq r4, #1
 *   @0x23da9c movne r4, #2
 *   @0x23daa0 cmp r7, #0
 *   @0x23daa4 str r3, [r6, #0x14]
 *   @0x23daa8 str r4, [r6, #0x10]
 *   @0x23daac beq 0x23daf8 <d2b_D2A+0xd4>
 *   @0x23dab0 sub r7, r7, #1072
 *   @0x23dab4 rsb r3, r0, #53
 *   @0x23dab8 sub r7, r7, #3
 *   @0x23dabc add r0, r7, r0
 *   @0x23dac0 str r0, [r9]
 *   @0x23dac4 mov r0, r6
 *   @0x23dac8 str r3, [r8]
 *   @0x23dacc add sp, sp, #12
 *   @0x23dad0 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x23dad4 add r0, sp, #4
 *   @0x23dad8 mov r4, #1
 *   @0x23dadc bl 0x23d2d4 <lo0bits_D2A>
 *   @0x23dae0 ldr r3, [sp, #0x4]
 *   @0x23dae4 cmp r7, #0
 *   @0x23dae8 str r4, [r6, #0x10]
 *   @0x23daec str r3, [r6, #0x14]
 *   @0x23daf0 add r0, r0, #32
 *   @0x23daf4 bne 0x23dab0 <d2b_D2A+0x8c>
 *   @0x23daf8 add r3, r6, r4, lsl #2
 *   @0x23dafc sub r0, r0, #1072
 *   @0x23db00 sub r0, r0, #2
 *   @0x23db04 str r0, [r9]
 *   @0x23db08 ldr r0, [r3, #0x10]
 *   @0x23db0c bl 0x23d41c <hi0bits_D2A>
 *   @0x23db10 rsb r0, r0, r4, lsl #5
 *   @0x23db14 str r0, [r8]
 *   @0x23db18 mov r0, r6
 *   @0x23db1c add sp, sp, #12
 *   @0x23db20 pop {r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §68/119 JS_Array_prototype_indexOf(RValue&, CInstance*, CInstance*, int, RValue*)  0x240b24  size 256  64 条（0x240b24..0x240c24）
 * @func 0x240b24 0x240c38  size 276  69 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JS_Array_prototype_indexOf(RValue&, CInstance*, CInstance*, int, RValue*)+0xe0×2 / YYObjectBase::InternalGetYYVar(int)×2 / JS_Array_prototype_indexOf(RValue&, CInstance*, CInstance*, int, RValue*)+0xe8 / YYGetInt32(RValue const*, int) / JS_Global_abstractStrictEqualityComparison(RValue&, RValue&)
 * 字段偏移 top8: 0x4×2 / 0xc×2 / 0x30×2 / 0x24×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x240b24 mov r12, #0
 *   @0x240b28 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x240b2c mov r2, r12
 *   @0x240b30 movt r12, #0xbff0
 *   @0x240b34 stm r0, {r2, r12}
 *   @0x240b38 ldr r12, [r1, #0x4]
 *   @0x240b3c sub sp, sp, #20
 *   @0x240b40 mov r7, r0
 *   @0x240b44 mov r4, r3
 *   @0x240b48 cmp r12, r2
 *   @0x240b4c str r2, [r0, #0xc]
 *   @0x240b50 beq 0x240c14 <_Z26JS_Array_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0xf0>
 *   @0x240b54 add r0, r12, #16
 *   @0x240b58 ldr r6, [r0]
 *   @0x240b5c ldr r8, [r6, #0x24]
 *   @0x240b60 cmp r8, #0
 *   @0x240b64 beq 0x240c04 <_Z26JS_Array_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x240b68 cmp r4, #0
 *   @0x240b6c mov r3, #5
 *   @0x240b70 str r3, [sp, #0xc]
 *   @0x240b74 ble 0x240c0c <_Z26JS_Array_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0xe8>
 *   @0x240b78 ldr r12, [sp, #0x30]
 *   @0x240b7c cmp r4, #1
 *   @0x240b80 ldm r12, {r0, r1, r2, r3}
 *   @0x240b84 add r12, sp, #16
 *   @0x240b88 stmdb r12, {r0, r1, r2, r3}
 *   @0x240b8c beq 0x240c0c <_Z26JS_Array_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0xe8>
 *   @0x240b90 ldr r0, [sp, #0x30]
 *   @0x240b94 mov r1, #1
 *   @0x240b98 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x240b9c mov r4, r0
 *   @0x240ba0 cmp r8, r4
 *   @0x240ba4 bls 0x240c04 <_Z26JS_Array_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x240ba8 lsl r5, r4, #4
 *   @0x240bac b 0x240bd0 <_Z26JS_Array_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0x240bb0 mov r0, sp
 *   @0x240bb4 add r5, r5, #16
 *   @0x240bb8 bl 0x240a08 <_Z42JS_Global_abstractStrictEqualityComparisonR6RValueS0_>
 *   @0x240bbc cmp r0, #0
 *   @0x240bc0 bne 0x240bf4 <_Z26JS_Array_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0xd0>
 *   @0x240bc4 add r4, r4, #1
 *   @0x240bc8 cmp r8, r4
 *   @0x240bcc bls 0x240c04 <_Z26JS_Array_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x240bd0 ldr r1, [r6, #0x4]
 *   @0x240bd4 cmp r1, #0
 *   @0x240bd8 add r1, r1, r5
 *   @0x240bdc bne 0x240bb0 <_Z26JS_Array_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x240be0 mov r1, r4
 *   @0x240be4 mov r0, r6
 *   @0x240be8 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x240bec mov r1, r0
 *   @0x240bf0 b 0x240bb0 <_Z26JS_Array_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x240bf4 vmov s15, r4
 *   @0x240bf8 vcvt.f64.u32 d7, s15
 *   @0x240bfc vmov r2, r3, d7
 *   @0x240c00 stm r7, {r2, r3}
 *   @0x240c04 add sp, sp, #20
 *   @0x240c08 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x240c0c mov r4, #0
 *   @0x240c10 b 0x240ba0 <_Z26JS_Array_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0x240c14 mov r0, r1
 *   @0x240c18 mov r1, #1
 *   @0x240c1c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x240c20 b 0x240b58 <_Z26JS_Array_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x34>
 *
 * ══ §69/119 png_do_gray_to_rgb  0x2a90ac  size 256  64 条（0x2a90ac..0x2a91ac）
 * @func 0x2a90ac 0x2a91ac  size 256  64 条
 * 部分覆盖: 本节 64/123 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_do_gray_to_rgb+0xfe / png_do_gray_to_rgb+0xf6
 * 字段偏移 top8: 0x1×9 / 0x2×7 / 0x8×2 / 0x4×2 / 0x3×2 / 0x9×1 / 0xb×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a90ac ldrb r2, [r0, #0x9]
 *   @0x2a90b0 cmp r2, #0x7
 *   @0x2a90b4 bls 0x2a91aa <png_do_gray_to_rgb+0xfe>
 *   @0x2a90b8 and r6, r4, #0x2
 *   @0x2a90bc and r5, r6, #0xff
 *   @0x2a90c0 cmp r6, #0x0
 *   @0x2a90c4 cbnz r4, 0x2a90ee <png_do_gray_to_rgb+0x42>
 *   @0x2a90c8 lsl.w r2, r3, #0x1
 *   @0x2a90cc bne 0x2a9114 <png_do_gray_to_rgb+0x68>
 *   @0x2a90d0 add r1, r4
 *   @0x2a90d4 add r2, r1
 *   @0x2a90d8 subs r1, #0x1
 *   @0x2a90dc beq 0x2a90f2 <png_do_gray_to_rgb+0x46>
 *   @0x2a90e0 subs r2, #0x3
 *   @0x2a90e4 ldrb r5, [r1, #0x1]
 *   @0x2a90e8 ldrb r5, [r1, #0x1]
 *   @0x2a90ec b 0x2a90d8 <png_do_gray_to_rgb+0x2c>
 *   @0x2a90f0 beq 0x2a9142 <png_do_gray_to_rgb+0x96>
 *   @0x2a90f4 ldrb r1, [r0, #0x8]
 *   @0x2a90f8 orr r1, r1, #0x2
 *   @0x2a90fc strb r1, [r0, #0x8]
 *   @0x2a9100 uxtb r2, r2
 *   @0x2a9104 muls r2, r1, r2
 *   @0x2a9108 strb r2, [r0, #0xb]
 *   @0x2a910c bls 0x2a91a2 <png_do_gray_to_rgb+0xf6>
 *   @0x2a9110 muls r3, r2, r3
 *   @0x2a9114 subs r2, #0x1
 *   @0x2a9118 add.w r2, r1, r3, lsl #2
 *   @0x2a911c cmp r4, r3
 *   @0x2a9120 rscle r0, r6, r2, lsl #2
 *   @0x2a9124 ldrb r5, [r1, #0x2]
 *   @0x2a9128 subs r2, #0x6
 *   @0x2a912c ldrb r5, [r1, #0x1]
 *   @0x2a9130 ldrb r5, [r1, #0x2]
 *   @0x2a9134 ldrb r5, [r1, #0x1]
 *   @0x2a9138 ldrb r5, [r1, #0x2]
 *   @0x2a913c ldrb r5, [r1, #0x1]
 *   @0x2a9140 b 0x2a911c <png_do_gray_to_rgb+0x70>
 *   @0x2a9144 bne 0x2a916c <png_do_gray_to_rgb+0xc0>
 *   @0x2a9148 subs r4, r2, #0x1
 *   @0x2a914c mov r4, r5
 *   @0x2a9150 cmp r4, r3
 *   @0x2a9154 ldrb r5, [r1]
 *   @0x2a9158 subs r1, #0x2
 *   @0x2a915c strb r5, [r2, #0x4]
 *   @0x2a9160 strb r5, [r2, #0x3]
 *   @0x2a9164 strb r5, [r2, #0x2]
 *   @0x2a9168 strb r5, [r2, #0x1]
 *   @0x2a916c lsls r2, r3, #0x2
 *   @0x2a9170 add r1, r4
 *   @0x2a9174 add r2, r1
 *   @0x2a9178 beq 0x2a90f2 <png_do_gray_to_rgb+0x46>
 *   @0x2a917c adds r4, #0x1
 *   @0x2a9180 subs r2, #0x8
 *   @0x2a9184 ldrb r5, [r1, #0x3]
 *   @0x2a9188 ldrb r5, [r1, #0x2]
 *   @0x2a918c ldrb r5, [r1, #0x1]
 *   @0x2a9190 ldrb r5, [r1, #0x2]
 *   @0x2a9194 ldrb r5, [r1, #0x1]
 *   @0x2a9198 ldrb r5, [r1, #0x2]
 *   @0x2a919c ldrb r5, [r1, #0x1]
 *   @0x2a91a0 b 0x2a9176 <png_do_gray_to_rgb+0xca>
 *   @0x2a91a4 adds r3, #0x7
 *   @0x2a91a8 str r3, [r0, #0x4]
 *
 * ══ §70/119 png_set_sRGB_gAMA_and_cHRM  0x2aed48  size 256  64 条（0x2aed48..0x2aee48）
 * @func 0x2aed48 0x2aee48  size 256  64 条
 * 部分覆盖: 本节 64/117 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_set_sRGB
 * 字段偏移 top8: 0x10×1 / 0x14×1 / 0xb×1
 * VFP 指令 1 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2aed48 push {r4, r5, lr}
 *   @0x2aed4c sub sp, #0x3c
 *   @0x2aed50 cmp r0, #0x0
 *   @0x2aed54 cmp r1, #0x0
 *   @0x2aed58 bl 0x2aed34 <png_set_sRGB>
 *   @0x2aed5c adr r3, #160 <png_set_sRGB_gAMA_and_cHRM+0x40>
 *   @0x2aed60 strtmi r2, [r8], -r0, lsl #6
 *   @0x2aed64 mov r1, r4
 *   @0x2aed68 strtmi pc, [r8], -r7, asr #27
 *   @0x2aed6c mov r1, r4
 *   @0x2aed70 .word 0xf7ff128f
 *   @0x2aed74 .word 0xf44ffe09
 *   @0x2aed78 vqadd.s8 q10, q4, q13
 *   @0x2aed7c .word 0xf24701e8
 *   @0x2aed80 .word 0xf64e5230
 *   @0x2aed84 stm sp, {r5, r6, r8, r9, sp}
 *   @0x2aed88 .word 0xf643000f
 *   @0x2aed8c qadd8mi r2, r8, r8
 *   @0x2aed90 str r3, [sp, #0x10]
 *   @0x2aed94 movw r3, #0x1770
 *   @0x2aed98 movw r2, #0x7a26
 *   @0x2aed9c str r3, [sp, #0x14]
 *   @0x2aeda0 .word 0xf7ff0384
 *   @0x2aeda4 tstge r8, #1856
 *   @0x2aeda8 ldrd r2, r3, [r3]
 *   @0x2aedac mov r0, r5
 *   @0x2aedb0 strd r2, r3, [sp]
 *   @0x2aedb4 adr r3, #88 <png_set_sRGB_gAMA_and_cHRM+0x86>
 *   @0x2aedb8 stmib sp, {r8, r9, sp} ^
 *   @0x2aedbc tstge r6, #134217728
 *   @0x2aedc0 ldrd r2, r3, [r3]
 *   @0x2aedc4 strd r2, r3, [sp, #16]
 *   @0x2aedc8 adr r3, #84 <png_set_sRGB_gAMA_and_cHRM+0x99>
 *   @0x2aedcc stmib sp, {r8, r9, sp} ^
 *   @0x2aedd0 tstge r5, #402653184
 *   @0x2aedd4 ldrd r2, r3, [r3]
 *   @0x2aedd8 strd r2, r3, [sp, #32]
 *   @0x2aeddc adr r3, #80 <png_set_sRGB_gAMA_and_cHRM+0xac>
 *   @0x2aede0 stmib sp, {r8, r9, sp} ^
 *   @0x2aede4 tstge r4, #671088640
 *   @0x2aede8 ldrd r2, r3, [r3]
 *   @0x2aedec strd r2, r3, [sp, #48]
 *   @0x2aedf0 adr r3, #76 <png_set_sRGB_gAMA_and_cHRM+0xbf>
 *   @0x2aedf4 .word 0xf7ff2300
 *   @0x2aedf8 andlt pc, pc, pc, ror #24
 *   @0x2aedfc pop {r4, r5, pc}
 *   @0x2aee00 movs r0, r0
 *   @0x2aee04 asrs r0, r3, #0x1d
 *   @0x2aee08 movs r0, r0
 *   @0x2aee0c lsrs r6, r2, #0x19
 *   @0x2aee10 movs r0, r0
 *   @0x2aee14 ldrb r1, [r4, #0xb]
 *   @0x2aee18 movs r0, r0
 *   @0x2aee1c subs r0, r7, #0x2
 *   @0x2aee20 movs r0, r0
 *   @0x2aee24 adds r3, #0x33
 *   @0x2aee28 movs r0, r0
 *   @0x2aee2c adds r3, #0x33
 *   @0x2aee30 movs r0, r0
 *   @0x2aee34 adds r3, #0x33
 *   @0x2aee38 movs r0, r0
 *   @0x2aee3c .word 0xb851
 *   @0x2aee40 movs r0, r0
 *   @0x2aee44 lsls r6, r0, #0xd
 *
 * ══ §71/119 anon_2b33a4  0x2b33a4  size 256  64 条（0x2b33a4..0x2b34a4）
 * @func 0x2b33a4 0x2b34a4  size 256  64 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x180×5 / 0x78×5 / 0x8×4 / 0x14×3 / 0x4×3 / 0x184×1 / 0x60×1 / 0x41×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b33a4 push {r3, r4, r5, r6, r7, lr}
 *   @0x2b33a8 mov r4, r0
 *   @0x2b33ac ldr r3, [r0, #0x14]
 *   @0x2b33b0 cmp r3, #204
 *   @0x2b33b4 beq 0x2b33d4 <jpeg_finish_decompress+0x114>
 *   @0x2b33b8 ldr r3, [r0, #0x180]
 *   @0x2b33bc ldr r3, [r3]
 *   @0x2b33c0 blx r3
 *   @0x2b33c4 mov r2, #0
 *   @0x2b33c8 mov r3, #204
 *   @0x2b33cc str r2, [r4, #0x78]
 *   @0x2b33d0 str r3, [r4, #0x14]
 *   @0x2b33d4 ldr r3, [r4, #0x180]
 *   @0x2b33d8 ldrb r3, [r3, #0x8]
 *   @0x2b33dc cmp r3, #0
 *   @0x2b33e0 beq 0x2b3484 <jpeg_finish_decompress+0x1c4>
 *   @0x2b33e4 mov r6, r4
 *   @0x2b33e8 mov r7, #0
 *   @0x2b33ec ldr r5, [r6, #0x78]!
 *   @0x2b33f0 b 0x2b3440 <jpeg_finish_decompress+0x180>
 *   @0x2b33f4 ldr r3, [r4, #0x8]
 *   @0x2b33f8 cmp r3, #0
 *   @0x2b33fc beq 0x2b3414 <jpeg_finish_decompress+0x154>
 *   @0x2b3400 str r5, [r3, #0x4]
 *   @0x2b3404 str r1, [r3, #0x8]
 *   @0x2b3408 ldr r3, [r3]
 *   @0x2b340c blx r3
 *   @0x2b3410 ldr r5, [r4, #0x78]
 *   @0x2b3414 ldr r12, [r4, #0x184]
 *   @0x2b3418 mov r1, #0
 *   @0x2b341c mov r3, r1
 *   @0x2b3420 mov r0, r4
 *   @0x2b3424 mov r2, r6
 *   @0x2b3428 ldr r12, [r12, #0x4]
 *   @0x2b342c blx r12
 *   @0x2b3430 ldr r3, [r4, #0x78]
 *   @0x2b3434 cmp r3, r5
 *   @0x2b3438 mov r5, r3
 *   @0x2b343c beq 0x2b34a0 <jpeg_finish_decompress+0x1e0>
 *   @0x2b3440 ldr r1, [r4, #0x60]
 *   @0x2b3444 mov r0, r4
 *   @0x2b3448 cmp r1, r5
 *   @0x2b344c bhi 0x2b33f4 <jpeg_finish_decompress+0x134>
 *   @0x2b3450 ldr r3, [r4, #0x180]
 *   @0x2b3454 mov r5, #0
 *   @0x2b3458 ldr r3, [r3, #0x4]
 *   @0x2b345c blx r3
 *   @0x2b3460 ldr r3, [r4, #0x180]
 *   @0x2b3464 mov r0, r4
 *   @0x2b3468 ldr r3, [r3]
 *   @0x2b346c blx r3
 *   @0x2b3470 ldr r3, [r4, #0x180]
 *   @0x2b3474 str r7, [r4, #0x78]
 *   @0x2b3478 ldrb r3, [r3, #0x8]
 *   @0x2b347c cmp r3, r5
 *   @0x2b3480 bne 0x2b3440 <jpeg_finish_decompress+0x180>
 *   @0x2b3484 ldrb r3, [r4, #0x41]
 *   @0x2b3488 mov r0, #1
 *   @0x2b348c cmp r3, #0
 *   @0x2b3490 movne r3, #206
 *   @0x2b3494 moveq r3, #205
 *   @0x2b3498 str r3, [r4, #0x14]
 *   @0x2b349c pop {r3, r4, r5, r6, r7, pc}
 *   @0x2b34a0 mov r0, #0
 *
 * ══ §72/119 YYGML_vertex_argb(int, unsigned int)  0xc9a04  size 252  63 条（0xc9a04..0xc9b00）
 * @func 0xc9a04 0xc9b00  size 252  63 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGML_vertex_argb(int, unsigned int)+0xd4 / YYGML_vertex_argb(int, unsigned int)+0x9c / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool) / YYGML_vertex_argb(int, unsigned int)+0x14
 * 字段偏移 top8: 0xc×4 / 0x4×3 / 0x14×2 / 0x10×2 / 0xd4×1 / 0x2×1 / 0x2c×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc9a04 cmp r0, #0
 *   @0xc9a08 push {r4, r5, lr}
 *   @0xc9a0c mov r5, r1
 *   @0xc9a10 sub sp, sp, #12
 *   @0xc9a14 blt 0xc9ad8 <_Z17YYGML_vertex_argbij+0xd4>
 *   @0xc9a18 ldr r3, [pc, #0xd4]
 *   @0xc9a1c add r3, pc, r3
 *   @0xc9a20 ldr r3, [r3]
 *   @0xc9a24 ldr r4, [r3, r0, lsl #2]
 *   @0xc9a28 ldr r1, [r4, #0x2c]
 *   @0xc9a2c ldr r2, [r4, #0xc]
 *   @0xc9a30 ldr r3, [r4, #0x4]
 *   @0xc9a34 ldr r1, [r1, #0x14]
 *   @0xc9a38 add r0, r1, r2
 *   @0xc9a3c cmp r3, r0
 *   @0xc9a40 blo 0xc9aa0 <_Z17YYGML_vertex_argbij+0x9c>
 *   @0xc9a44 ldr r1, [r4]
 *   @0xc9a48 bic r3, r5, #16711680
 *   @0xc9a4c ubfx r0, r5, #0x10, #0x8
 *   @0xc9a50 bic r3, r3, #255
 *   @0xc9a54 uxtb r5, r5
 *   @0xc9a58 orr r3, r3, r0
 *   @0xc9a5c orr r3, r3, r5, lsl #16
 *   @0xc9a60 str r3, [r1, r2]
 *   @0xc9a64 ldr r3, [r4, #0x10]
 *   @0xc9a68 ldr r1, [r4, #0x14]
 *   @0xc9a6c add r3, r3, #1
 *   @0xc9a70 ldr r2, [r4, #0xc]
 *   @0xc9a74 cmp r3, r1
 *   @0xc9a78 str r3, [r4, #0x10]
 *   @0xc9a7c add r3, r2, #4
 *   @0xc9a80 str r3, [r4, #0xc]
 *   @0xc9a84 ldrhs r3, [r4, #0x1c]
 *   @0xc9a88 movhs r2, #0
 *   @0xc9a8c strhs r2, [r4, #0x10]
 *   @0xc9a90 addhs r3, r3, #1
 *   @0xc9a94 strhs r3, [r4, #0x1c]
 *   @0xc9a98 add sp, sp, #12
 *   @0xc9a9c pop {r4, r5, pc}
 *   @0xc9aa0 add r1, r1, r3
 *   @0xc9aa4 ldr r0, [r4]
 *   @0xc9aa8 add r1, r1, r3, lsr #1
 *   @0xc9aac mov r2, #0
 *   @0xc9ab0 str r1, [r4, #0x4]
 *   @0xc9ab4 mov r3, #74
 *   @0xc9ab8 str r2, [sp]
 *   @0xc9abc ldr r2, [pc, #0x34]
 *   @0xc9ac0 add r2, pc, r2
 *   @0xc9ac4 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0xc9ac8 ldr r2, [r4, #0xc]
 *   @0xc9acc mov r1, r0
 *   @0xc9ad0 str r0, [r4]
 *   @0xc9ad4 b 0xc9a48 <_Z17YYGML_vertex_argbij+0x44>
 *   @0xc9ad8 ldr r3, [pc, #0x1c]
 *   @0xc9adc add r3, pc, r3
 *   @0xc9ae0 ldr r3, [r3, #0x4]
 *   @0xc9ae4 cmp r0, r3
 *   @0xc9ae8 blt 0xc9a18 <_Z17YYGML_vertex_argbij+0x14>
 *   @0xc9aec add sp, sp, #12
 *   @0xc9af0 pop {r4, r5, pc}
 *   @0xc9af4 eorseq r0, r11, r8, lsl r7
 *   @0xc9af8 eoreq r7, r6, r0, ror r5
 *   @0xc9afc eorseq r0, r11, r8, asr r6
 *
 * ══ §73/119 YYGML_vertex_float4(int, float, float, float, float)  0xc9fa4  size 252  63 条（0xc9fa4..0xca0a0）
 * @func 0xc9fa4 0xca0b4  size 272  68 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGML_vertex_float4(int, float, float, float, float)+0xd4 / YYGML_vertex_float4(int, float, float, float, float)+0x9c / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool) / YYGML_vertex_float4(int, float, float, float, float)+0x1c
 * 字段偏移 top8: 0x4×4 / 0xc×3 / 0x14×2 / 0x10×2 / 0xcc×1 / 0x2×1 / 0x2c×1 / 0x8×1
 * VFP 指令 2 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc9fa4 cmp r0, #0
 *   @0xc9fa8 push {r4, r5, r6, r7, r8, lr}
 *   @0xc9fac mov r8, r1
 *   @0xc9fb0 sub sp, sp, #8
 *   @0xc9fb4 mov r7, r2
 *   @0xc9fb8 mov r6, r3
 *   @0xc9fbc blt 0xca078 <_Z19YYGML_vertex_float4iffff+0xd4>
 *   @0xc9fc0 ldr r3, [pc, #0xcc]
 *   @0xc9fc4 add r3, pc, r3
 *   @0xc9fc8 ldr r3, [r3]
 *   @0xc9fcc ldr r4, [r3, r0, lsl #2]
 *   @0xc9fd0 ldr r3, [r4, #0x2c]
 *   @0xc9fd4 ldr r12, [r4, #0xc]
 *   @0xc9fd8 ldr r5, [r4, #0x4]
 *   @0xc9fdc ldr r0, [r3, #0x14]
 *   @0xc9fe0 add r3, r0, r12
 *   @0xc9fe4 cmp r5, r3
 *   @0xc9fe8 blo 0xca040 <_Z19YYGML_vertex_float4iffff+0x9c>
 *   @0xc9fec ldr r3, [r4]
 *   @0xc9ff0 ldr r1, [r4, #0x10]
 *   @0xc9ff4 add r0, r3, r12
 *   @0xc9ff8 ldr r3, [r4, #0x14]
 *   @0xc9ffc vldr s15, [sp, #32]
 *   @0xca000 add r1, r1, #1
 *   @0xca004 str r8, [r0]
 *   @0xca008 cmp r1, r3
 *   @0xca00c str r7, [r0, #0x4]
 *   @0xca010 str r6, [r0, #0x8]
 *   @0xca014 vstr s15, [r0, #12]
 *   @0xca018 ldrhs r3, [r4, #0x1c]
 *   @0xca01c add r12, r12, #16
 *   @0xca020 str r1, [r4, #0x10]
 *   @0xca024 movhs r2, #0
 *   @0xca028 addhs r3, r3, #1
 *   @0xca02c str r12, [r4, #0xc]
 *   @0xca030 strhs r2, [r4, #0x10]
 *   @0xca034 strhs r3, [r4, #0x1c]
 *   @0xca038 add sp, sp, #8
 *   @0xca03c pop {r4, r5, r6, r7, r8, pc}
 *   @0xca040 add r1, r0, r5
 *   @0xca044 mov r2, #0
 *   @0xca048 ldr r0, [r4]
 *   @0xca04c add r1, r1, r5, lsr #1
 *   @0xca050 str r1, [r4, #0x4]
 *   @0xca054 mov r3, #74
 *   @0xca058 str r2, [sp]
 *   @0xca05c ldr r2, [pc, #0x34]
 *   @0xca060 add r2, pc, r2
 *   @0xca064 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0xca068 ldr r12, [r4, #0xc]
 *   @0xca06c mov r3, r0
 *   @0xca070 str r0, [r4]
 *   @0xca074 b 0xc9ff0 <_Z19YYGML_vertex_float4iffff+0x4c>
 *   @0xca078 ldr r3, [pc, #0x1c]
 *   @0xca07c add r3, pc, r3
 *   @0xca080 ldr r3, [r3, #0x4]
 *   @0xca084 cmp r0, r3
 *   @0xca088 blt 0xc9fc0 <_Z19YYGML_vertex_float4iffff+0x1c>
 *   @0xca08c add sp, sp, #8
 *   @0xca090 pop {r4, r5, r6, r7, r8, pc}
 *   @0xca094 eorseq r0, r11, r0, ror r1
 *   @0xca098 .word 0x00266fd0
 *   @0xca09c ldrhteq r0, [r11], -r8
 *
 * ══ §74/119 F_Vertex_Submit_debug(RValue&, CInstance*, CInstance*, int, RValue*)  0xca4ac  size 252  63 条（0xca4ac..0xca5a8）
 * @func 0xca4ac 0xca5a8  size 252  63 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / GetBufferVertex(int) / F_Vertex_Submit_debug(RValue&, CInstance*, CInstance*, int, RValue*)+0xb0
 * 字段偏移 top8: 0x20×3 / 0x28×2 / 0xc×1 / 0x4×1 / 0xac×1 / 0x38×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xca4ac cmp r3, #3
 *   @0xca4b0 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xca4b4 mov r4, r0
 *   @0xca4b8 mov r0, #0
 *   @0xca4bc mov r7, r1
 *   @0xca4c0 mov r5, r3
 *   @0xca4c4 mov r1, r0
 *   @0xca4c8 mov r8, r2
 *   @0xca4cc movt r0, #0xbff0
 *   @0xca4d0 str r1, [r4, #0xc]
 *   @0xca4d4 str r0, [r4, #0x4]
 *   @0xca4d8 str r1, [r4]
 *   @0xca4dc ldr r6, [sp, #0x20]
 *   @0xca4e0 beq 0xca4f8 <_Z21F_Vertex_Submit_debugR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0xca4e4 ldr r0, [pc, #0xac]
 *   @0xca4e8 mov r1, #1
 *   @0xca4ec pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xca4f0 add r0, pc, r0
 *   @0xca4f4 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xca4f8 mov r0, r6
 *   @0xca4fc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xca500 bl 0xc8860 <_Z15GetBufferVertexi>
 *   @0xca504 subs r9, r0, #0
 *   @0xca508 beq 0xca584 <_Z21F_Vertex_Submit_debugR6RValueP9CInstanceS2_iPS_+0xd8>
 *   @0xca50c ldr r3, [r9, #0x28]
 *   @0xca510 cmn r3, #1
 *   @0xca514 beq 0xca570 <_Z21F_Vertex_Submit_debugR6RValueP9CInstanceS2_iPS_+0xc4>
 *   @0xca518 mov r0, r6
 *   @0xca51c mov r1, #1
 *   @0xca520 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xca524 ldrb r3, [r9, #0x20]
 *   @0xca528 cmp r3, #0
 *   @0xca52c moveq r3, #7
 *   @0xca530 movne r3, #6
 *   @0xca534 cmp r0, #0
 *   @0xca538 cmpgt r3, r0
 *   @0xca53c ble 0xca55c <_Z21F_Vertex_Submit_debugR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0xca540 str r6, [sp, #0x20]
 *   @0xca544 mov r0, r4
 *   @0xca548 mov r1, r7
 *   @0xca54c mov r2, r8
 *   @0xca550 mov r3, r5
 *   @0xca554 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xca558 b 0xca24c <_Z23F_Vertex_Submit_releaseR6RValueP9CInstanceS2_iPS_>
 *   @0xca55c ldr r0, [pc, #0x38]
 *   @0xca560 mov r1, #1
 *   @0xca564 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xca568 add r0, pc, r0
 *   @0xca56c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xca570 ldr r0, [pc, #0x28]
 *   @0xca574 mov r1, #1
 *   @0xca578 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xca57c add r0, pc, r0
 *   @0xca580 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xca584 ldr r0, [pc, #0x18]
 *   @0xca588 mov r1, #1
 *   @0xca58c pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xca590 add r0, pc, r0
 *   @0xca594 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xca598 eoreq r7, r6, r8, lsr r9
 *   @0xca59c eoreq r7, r6, r8, asr r9
 *   @0xca5a0 eoreq r7, r6, r4, lsl #18
 *   @0xca5a4 eoreq r7, r6, r0, asr #17
 *
 * ══ §75/119 IBuffer::Load(char const*, int, int, int)  0xcd91c  size 252  63 条（0xcd91c..0xcda18）
 * @func 0xcd91c 0xcda18  size 252  63 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65e0×2 / LoadSave::SaveFileExists(char const*) / LoadSave::ReadSaveFile(char const*, int*) / IBuffer::LoadFromFileInMemory(char*, int, int, int, int) / MemoryManager::Free(void const*) / LoadSave::BundleFileExists(char const*) / LoadSave::ReadBundleFile(char const*, int*)
 * 字段偏移 top8: 0xc×2 / 0xe4×1 / 0xc0×1 / 0x28×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcd91c push {r4, r5, r6, r7, r8, lr}
 *   @0xcd920 mov r7, r0
 *   @0xcd924 ldr r0, [pc, #0xe4]
 *   @0xcd928 sub sp, sp, #16
 *   @0xcd92c mov r5, r2
 *   @0xcd930 mov r2, #7
 *   @0xcd934 add r0, pc, r0
 *   @0xcd938 mov r6, r3
 *   @0xcd93c mov r4, r1
 *   @0xcd940 bl 0xb65e0 <strncmp@plt>
 *   @0xcd944 cmp r0, #0
 *   @0xcd948 beq 0xcd9ec <_ZN7IBuffer4LoadEPKciii+0xd0>
 *   @0xcd94c ldr r0, [pc, #0xc0]
 *   @0xcd950 mov r1, r4
 *   @0xcd954 mov r2, #8
 *   @0xcd958 add r0, pc, r0
 *   @0xcd95c bl 0xb65e0 <strncmp@plt>
 *   @0xcd960 cmp r0, #0
 *   @0xcd964 moveq r4, r0
 *   @0xcd968 bne 0xcd978 <_ZN7IBuffer4LoadEPKciii+0x5c>
 *   @0xcd96c mov r0, r4
 *   @0xcd970 add sp, sp, #16
 *   @0xcd974 pop {r4, r5, r6, r7, r8, pc}
 *   @0xcd978 mov r0, r4
 *   @0xcd97c mov r3, #0
 *   @0xcd980 str r3, [sp, #0xc]
 *   @0xcd984 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc>
 *   @0xcd988 cmp r0, #0
 *   @0xcd98c mov r0, r4
 *   @0xcd990 beq 0xcd9e0 <_ZN7IBuffer4LoadEPKciii+0xc4>
 *   @0xcd994 add r1, sp, #12
 *   @0xcd998 bl 0x18fb08 <_ZN8LoadSave12ReadSaveFileEPKcPi>
 *   @0xcd99c mov r8, r0
 *   @0xcd9a0 cmp r8, #0
 *   @0xcd9a4 beq 0xcd9ec <_ZN7IBuffer4LoadEPKciii+0xd0>
 *   @0xcd9a8 ldr r1, [sp, #0x28]
 *   @0xcd9ac mov r3, r5
 *   @0xcd9b0 ldr r2, [sp, #0xc]
 *   @0xcd9b4 mov r0, r7
 *   @0xcd9b8 str r6, [sp]
 *   @0xcd9bc str r1, [sp, #0x4]
 *   @0xcd9c0 mov r1, r8
 *   @0xcd9c4 bl 0xcd8a0 <_ZN7IBuffer20LoadFromFileInMemoryEPciiii>
 *   @0xcd9c8 mov r4, r0
 *   @0xcd9cc mov r0, r8
 *   @0xcd9d0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xcd9d4 mov r0, r4
 *   @0xcd9d8 add sp, sp, #16
 *   @0xcd9dc pop {r4, r5, r6, r7, r8, pc}
 *   @0xcd9e0 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc>
 *   @0xcd9e4 cmp r0, #0
 *   @0xcd9e8 bne 0xcd9fc <_ZN7IBuffer4LoadEPKciii+0xe0>
 *   @0xcd9ec mov r4, #0
 *   @0xcd9f0 mov r0, r4
 *   @0xcd9f4 add sp, sp, #16
 *   @0xcd9f8 pop {r4, r5, r6, r7, r8, pc}
 *   @0xcd9fc mov r0, r4
 *   @0xcda00 add r1, sp, #12
 *   @0xcda04 bl 0x18f848 <_ZN8LoadSave14ReadBundleFileEPKcPi>
 *   @0xcda08 mov r8, r0
 *   @0xcda0c b 0xcd9a0 <_ZN7IBuffer4LoadEPKciii+0x84>
 *   @0xcda10 eoreq r3, r6, r12, lsr #3
 *   @0xcda14 mlaeq r6, r0, r1, r3
 *
 * ══ §76/119 InputDialogASync(HTTP_REQ_CONTEXT*, void*, int*)  0xf1e7c  size 252  63 条（0xf1e7c..0xf1f78）
 * @func 0xf1e7c 0xf1f8c  size 272  68 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb65bc / 0xb6658 / CreateDsMap(int, ...) / MemoryManager::Free(void const*) / RemoveDialogAndKick(HTTP_REQ_CONTEXT*)
 * 字段偏移 top8: 0x3c×3 / 0x74×2 / 0xd4×1 / 0x34×1 / 0xa8×1 / 0x14×1 / 0x24×1 / 0x10×1
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf1e7c push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xf1e80 vpush {d8}
 *   @0xf1e84 mov r6, r0
 *   @0xf1e88 ldr r1, [pc, #0xd4]
 *   @0xf1e8c sub sp, sp, #56
 *   @0xf1e90 ldr r0, [r0, #0x3c]
 *   @0xf1e94 mov r3, #1
 *   @0xf1e98 mov r9, r2
 *   @0xf1e9c add r1, pc, r1
 *   @0xf1ea0 add r0, r0, r3
 *   @0xf1ea4 mov r2, #130
 *   @0xf1ea8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xf1eac ldr r2, [r6, #0x3c]
 *   @0xf1eb0 ldr r1, [r6, #0x34]
 *   @0xf1eb4 mov r7, #0
 *   @0xf1eb8 ldr r10, [pc, #0xa8]
 *   @0xf1ebc mov r4, #0
 *   @0xf1ec0 mov r5, #0
 *   @0xf1ec4 add r10, pc, r10
 *   @0xf1ec8 mov r8, r0
 *   @0xf1ecc bl 0xb65bc <memcpy@plt>
 *   @0xf1ed0 ldr r3, [r6, #0x3c]
 *   @0xf1ed4 mov r0, r8
 *   @0xf1ed8 mov r1, r7
 *   @0xf1edc strb r7, [r8, r3]
 *   @0xf1ee0 vldr s15, [r6, #36]
 *   @0xf1ee4 vcvt.f64.s32 d8, s15
 *   @0xf1ee8 bl 0xb6658 <strtod@plt>
 *   @0xf1eec vldr s14, [r6, #40]
 *   @0xf1ef0 ldr lr, [pc, #0x74]
 *   @0xf1ef4 ldr r12, [pc, #0x74]
 *   @0xf1ef8 add lr, pc, lr
 *   @0xf1efc strd r4, r5, [sp, #8]
 *   @0xf1f00 add r12, pc, r12
 *   @0xf1f04 str lr, [sp, #0x14]
 *   @0xf1f08 str r12, [sp, #0x24]
 *   @0xf1f0c str r7, [sp]
 *   @0xf1f10 vcvt.f64.s32 d7, s14
 *   @0xf1f14 str r8, [sp, #0x10]
 *   @0xf1f18 vmov r2, r3, d8
 *   @0xf1f1c str r7, [sp, #0x20]
 *   @0xf1f20 str r7, [sp, #0x30]
 *   @0xf1f24 str r10, [sp, #0x4]
 *   @0xf1f28 vstr d7, [sp, #40]
 *   @0xf1f2c strd r0, r1, [sp, #24]
 *   @0xf1f30 mov r0, #4
 *   @0xf1f34 ldr r1, [pc, #0x38]
 *   @0xf1f38 add r1, pc, r1
 *   @0xf1f3c bl 0x20bdc0 <_Z11CreateDsMapiz>
 *   @0xf1f40 str r0, [r9]
 *   @0xf1f44 mov r0, r8
 *   @0xf1f48 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xf1f4c mov r0, r6
 *   @0xf1f50 bl 0xf1d98 <_Z19RemoveDialogAndKickP16HTTP_REQ_CONTEXT>
 *   @0xf1f54 mov r0, #63
 *   @0xf1f58 add sp, sp, #56
 *   @0xf1f5c vpop {d8}
 *   @0xf1f60 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xf1f64 eoreq r5, r4, r8, lsl #1
 *   @0xf1f68 mlaeq r4, r4, r0, r5
 *   @0xf1f6c eoreq r5, r4, r8, rrx
 *   @0xf1f70 eoreq lr, r3, r0, asr r11
 *   @0xf1f74 eoreq lr, r3, r8, lsl #22
 *
 * ══ §77/119 QuestionDialogASync(HTTP_REQ_CONTEXT*, void*, int*)  0xf1f78  size 252  63 条（0xf1f78..0xf2074）
 * @func 0xf1f78 0xf2074  size 252  63 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb65bc / 0xb6658 / CreateDsMap(int, ...) / MemoryManager::Free(void const*) / RemoveDialogAndKick(HTTP_REQ_CONTEXT*)
 * 字段偏移 top8: 0x3c×3 / 0x74×2 / 0xd4×1 / 0x34×1 / 0xa8×1 / 0x14×1 / 0x24×1 / 0x10×1
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf1f78 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xf1f7c vpush {d8}
 *   @0xf1f80 mov r6, r0
 *   @0xf1f84 ldr r1, [pc, #0xd4]
 *   @0xf1f88 sub sp, sp, #56
 *   @0xf1f8c ldr r0, [r0, #0x3c]
 *   @0xf1f90 mov r3, #1
 *   @0xf1f94 mov r9, r2
 *   @0xf1f98 add r1, pc, r1
 *   @0xf1f9c add r0, r0, r3
 *   @0xf1fa0 mov r2, #148
 *   @0xf1fa4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xf1fa8 ldr r2, [r6, #0x3c]
 *   @0xf1fac ldr r1, [r6, #0x34]
 *   @0xf1fb0 mov r7, #0
 *   @0xf1fb4 ldr r10, [pc, #0xa8]
 *   @0xf1fb8 mov r4, #0
 *   @0xf1fbc mov r5, #0
 *   @0xf1fc0 add r10, pc, r10
 *   @0xf1fc4 mov r8, r0
 *   @0xf1fc8 bl 0xb65bc <memcpy@plt>
 *   @0xf1fcc ldr r3, [r6, #0x3c]
 *   @0xf1fd0 mov r0, r8
 *   @0xf1fd4 mov r1, r7
 *   @0xf1fd8 strb r7, [r8, r3]
 *   @0xf1fdc vldr s15, [r6, #36]
 *   @0xf1fe0 vcvt.f64.s32 d8, s15
 *   @0xf1fe4 bl 0xb6658 <strtod@plt>
 *   @0xf1fe8 vldr s14, [r6, #40]
 *   @0xf1fec ldr lr, [pc, #0x74]
 *   @0xf1ff0 ldr r12, [pc, #0x74]
 *   @0xf1ff4 add lr, pc, lr
 *   @0xf1ff8 strd r4, r5, [sp, #8]
 *   @0xf1ffc add r12, pc, r12
 *   @0xf2000 str lr, [sp, #0x14]
 *   @0xf2004 str r12, [sp, #0x24]
 *   @0xf2008 str r7, [sp]
 *   @0xf200c vcvt.f64.s32 d7, s14
 *   @0xf2010 str r8, [sp, #0x10]
 *   @0xf2014 vmov r2, r3, d8
 *   @0xf2018 str r7, [sp, #0x20]
 *   @0xf201c str r7, [sp, #0x30]
 *   @0xf2020 str r10, [sp, #0x4]
 *   @0xf2024 vstr d7, [sp, #40]
 *   @0xf2028 strd r0, r1, [sp, #24]
 *   @0xf202c mov r0, #4
 *   @0xf2030 ldr r1, [pc, #0x38]
 *   @0xf2034 add r1, pc, r1
 *   @0xf2038 bl 0x20bdc0 <_Z11CreateDsMapiz>
 *   @0xf203c str r0, [r9]
 *   @0xf2040 mov r0, r8
 *   @0xf2044 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xf2048 mov r0, r6
 *   @0xf204c bl 0xf1d98 <_Z19RemoveDialogAndKickP16HTTP_REQ_CONTEXT>
 *   @0xf2050 mov r0, #63
 *   @0xf2054 add sp, sp, #56
 *   @0xf2058 vpop {d8}
 *   @0xf205c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xf2060 eoreq r4, r4, r12, lsl #31
 *   @0xf2064 mlaeq r4, r8, pc, r4
 *   @0xf2068 eoreq r4, r4, r12, ror #30
 *   @0xf206c eoreq lr, r3, r4, asr r10
 *   @0xf2070 eoreq lr, r3, r12, lsl #20
 *
 * ══ §78/119 F_MpPotentialPath(RValue&, CInstance*, CInstance*, int, RValue*)  0x109e44  size 252  63 条（0x109e44..0x109f40）
 * @func 0x109e44 0x109f54  size 272  68 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×4 / YYGetInt32(RValue const*, int) / Path_Exists(int) / Path_Data(int) / YYGetBool(RValue const*, int) / Motion_Potential_Path(CInstance*, CPath*, float, float, float, float, int, bool)
 * 字段偏移 top8: 0xc×3 / 0x14×2 / 0x4×2 / 0x40×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x109e44 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x109e48 sub sp, sp, #28
 *   @0x109e4c mov r5, r0
 *   @0x109e50 mov r6, r1
 *   @0x109e54 ldr r4, [sp, #0x40]
 *   @0x109e58 mov r1, #0
 *   @0x109e5c mov r0, r4
 *   @0x109e60 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x109e64 mov r7, r0
 *   @0x109e68 bl 0x1a8008 <_Z11Path_Existsi>
 *   @0x109e6c subs r1, r0, #0
 *   @0x109e70 beq 0x109f28 <_Z17F_MpPotentialPathR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0x109e74 mov r0, r7
 *   @0x109e78 mov r7, #0
 *   @0x109e7c str r7, [r5, #0xc]
 *   @0x109e80 bl 0x1a815c <_Z9Path_Datai>
 *   @0x109e84 mov r1, #1
 *   @0x109e88 mov r10, r0
 *   @0x109e8c mov r0, r4
 *   @0x109e90 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x109e94 mov r1, #2
 *   @0x109e98 mov r9, r0
 *   @0x109e9c mov r0, r4
 *   @0x109ea0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x109ea4 mov r1, #3
 *   @0x109ea8 mov r8, r0
 *   @0x109eac mov r0, r4
 *   @0x109eb0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x109eb4 mov r1, #4
 *   @0x109eb8 mov r3, r0
 *   @0x109ebc mov r0, r4
 *   @0x109ec0 str r3, [sp, #0x14]
 *   @0x109ec4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x109ec8 mov r1, #5
 *   @0x109ecc mov r11, r0
 *   @0x109ed0 mov r0, r4
 *   @0x109ed4 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x109ed8 ldr r3, [sp, #0x14]
 *   @0x109edc mvn r12, #2
 *   @0x109ee0 str r11, [sp, #0x4]
 *   @0x109ee4 mov r1, r10
 *   @0x109ee8 mov r2, r9
 *   @0x109eec str r3, [sp]
 *   @0x109ef0 mov r3, r8
 *   @0x109ef4 str r12, [sp, #0x8]
 *   @0x109ef8 str r0, [sp, #0xc]
 *   @0x109efc mov r0, r6
 *   @0x109f00 bl 0x19ce94 <_Z21Motion_Potential_PathP9CInstanceP5CPathffffib>
 *   @0x109f04 cmp r0, #0
 *   @0x109f08 moveq r7, r0
 *   @0x109f0c movne r3, r7
 *   @0x109f10 moveq r3, r7
 *   @0x109f14 movtne r3, #0x3ff0
 *   @0x109f18 str r7, [r5]
 *   @0x109f1c str r3, [r5, #0x4]
 *   @0x109f20 add sp, sp, #28
 *   @0x109f24 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x109f28 ldr r0, [pc, #0xc]
 *   @0x109f2c add r0, pc, r0
 *   @0x109f30 add sp, sp, #28
 *   @0x109f34 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x109f38 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x109f3c eoreq lr, r2, r0, lsr #15
 *
 * ══ §79/119 F_MpPotentialPathObject(RValue&, CInstance*, CInstance*, int, RValue*)  0x109f40  size 252  63 条（0x109f40..0x10a03c）
 * @func 0x109f40 0x10a050  size 272  68 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×4 / YYGetInt32(RValue const*, int)×2 / Path_Exists(int) / Path_Data(int) / Motion_Potential_Path(CInstance*, CPath*, float, float, float, float, int, bool)
 * 字段偏移 top8: 0xc×3 / 0x14×2 / 0x4×2 / 0x40×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x109f40 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x109f44 sub sp, sp, #28
 *   @0x109f48 mov r5, r0
 *   @0x109f4c mov r6, r1
 *   @0x109f50 ldr r4, [sp, #0x40]
 *   @0x109f54 mov r1, #0
 *   @0x109f58 mov r0, r4
 *   @0x109f5c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x109f60 mov r7, r0
 *   @0x109f64 bl 0x1a8008 <_Z11Path_Existsi>
 *   @0x109f68 subs r1, r0, #0
 *   @0x109f6c beq 0x10a024 <_Z23F_MpPotentialPathObjectR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0x109f70 mov r0, r7
 *   @0x109f74 mov r7, #0
 *   @0x109f78 str r7, [r5, #0xc]
 *   @0x109f7c bl 0x1a815c <_Z9Path_Datai>
 *   @0x109f80 mov r1, #1
 *   @0x109f84 mov r10, r0
 *   @0x109f88 mov r0, r4
 *   @0x109f8c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x109f90 mov r1, #2
 *   @0x109f94 mov r9, r0
 *   @0x109f98 mov r0, r4
 *   @0x109f9c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x109fa0 mov r1, #3
 *   @0x109fa4 mov r8, r0
 *   @0x109fa8 mov r0, r4
 *   @0x109fac bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x109fb0 mov r1, #4
 *   @0x109fb4 mov r3, r0
 *   @0x109fb8 mov r0, r4
 *   @0x109fbc str r3, [sp, #0x14]
 *   @0x109fc0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x109fc4 mov r1, #5
 *   @0x109fc8 mov r11, r0
 *   @0x109fcc mov r0, r4
 *   @0x109fd0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x109fd4 ldr r3, [sp, #0x14]
 *   @0x109fd8 mov r12, #1
 *   @0x109fdc str r11, [sp, #0x4]
 *   @0x109fe0 mov r1, r10
 *   @0x109fe4 mov r2, r9
 *   @0x109fe8 str r3, [sp]
 *   @0x109fec mov r3, r8
 *   @0x109ff0 str r12, [sp, #0xc]
 *   @0x109ff4 str r0, [sp, #0x8]
 *   @0x109ff8 mov r0, r6
 *   @0x109ffc bl 0x19ce94 <_Z21Motion_Potential_PathP9CInstanceP5CPathffffib>
 *   @0x10a000 cmp r0, #0
 *   @0x10a004 moveq r7, r0
 *   @0x10a008 movne r3, r7
 *   @0x10a00c moveq r3, r7
 *   @0x10a010 movtne r3, #0x3ff0
 *   @0x10a014 str r7, [r5]
 *   @0x10a018 str r3, [r5, #0x4]
 *   @0x10a01c add sp, sp, #28
 *   @0x10a020 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x10a024 ldr r0, [pc, #0xc]
 *   @0x10a028 add r0, pc, r0
 *   @0x10a02c add sp, sp, #28
 *   @0x10a030 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x10a034 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x10a038 eoreq lr, r2, r4, lsr #13
 *
 * ══ §80/119 F_MpGridPath(RValue&, CInstance*, CInstance*, int, RValue*)  0x10a03c  size 252  63 条（0x10a03c..0x10a138）
 * @func 0x10a03c 0x10a138  size 252  63 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×6 / Path_Exists(int) / Path_Data(int) / YYGetBool(RValue const*, int) / Motion_Grid_Path(int, CPath*, int, int, int, int, bool)
 * 字段偏移 top8: 0xc×2 / 0x14×2 / 0x40×1 / 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10a03c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x10a040 sub sp, sp, #28
 *   @0x10a044 mov r1, #1
 *   @0x10a048 mov r5, r0
 *   @0x10a04c ldr r4, [sp, #0x40]
 *   @0x10a050 mov r0, r4
 *   @0x10a054 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x10a058 mov r7, r0
 *   @0x10a05c bl 0x1a8008 <_Z11Path_Existsi>
 *   @0x10a060 subs r1, r0, #0
 *   @0x10a064 beq 0x10a120 <_Z12F_MpGridPathR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0x10a068 mov r6, #0
 *   @0x10a06c mov r0, r4
 *   @0x10a070 mov r1, r6
 *   @0x10a074 str r6, [r5, #0xc]
 *   @0x10a078 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x10a07c mov r8, r0
 *   @0x10a080 mov r0, r7
 *   @0x10a084 bl 0x1a815c <_Z9Path_Datai>
 *   @0x10a088 mov r1, #2
 *   @0x10a08c mov r10, r0
 *   @0x10a090 mov r0, r4
 *   @0x10a094 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x10a098 mov r1, #3
 *   @0x10a09c mov r9, r0
 *   @0x10a0a0 mov r0, r4
 *   @0x10a0a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x10a0a8 mov r1, #4
 *   @0x10a0ac mov r7, r0
 *   @0x10a0b0 mov r0, r4
 *   @0x10a0b4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x10a0b8 mov r1, #5
 *   @0x10a0bc mov r3, r0
 *   @0x10a0c0 mov r0, r4
 *   @0x10a0c4 str r3, [sp, #0x14]
 *   @0x10a0c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x10a0cc mov r1, #6
 *   @0x10a0d0 mov r11, r0
 *   @0x10a0d4 mov r0, r4
 *   @0x10a0d8 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x10a0dc ldr r3, [sp, #0x14]
 *   @0x10a0e0 mov r1, r10
 *   @0x10a0e4 mov r2, r9
 *   @0x10a0e8 stm sp, {r3, r11}
 *   @0x10a0ec mov r3, r7
 *   @0x10a0f0 str r0, [sp, #0x8]
 *   @0x10a0f4 mov r0, r8
 *   @0x10a0f8 bl 0x19a8f8 <_Z16Motion_Grid_PathiP5CPathiiiib>
 *   @0x10a0fc cmp r0, #0
 *   @0x10a100 moveq r6, r0
 *   @0x10a104 movne r3, r6
 *   @0x10a108 moveq r3, r6
 *   @0x10a10c movtne r3, #0x3ff0
 *   @0x10a110 str r6, [r5]
 *   @0x10a114 str r3, [r5, #0x4]
 *   @0x10a118 add sp, sp, #28
 *   @0x10a11c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x10a120 ldr r0, [pc, #0xc]
 *   @0x10a124 add r0, pc, r0
 *   @0x10a128 add sp, sp, #28
 *   @0x10a12c pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x10a130 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x10a134 eoreq lr, r2, r8, lsr #11
 *
 * ══ §81/119 F_ActionPartTypeCreateOld(RValue&, CInstance*, CInstance*, int, RValue*)  0x13f9a4  size 252  63 条（0x13f9a4..0x13faa0）
 * @func 0x13f9a4 0x13faa0  size 252  63 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×4 / YYGetFloat(RValue const*, int)×2 / F_ActionPartTypeCreateOld(RValue&, CInstance*, CInstance*, int, RValue*)+0xe0 / F_ActionPartTypeCreateOld(RValue&, CInstance*, CInstance*, int, RValue*)+0xd0 / ParticleType_Shape(int, int) / ParticleType_Size(int, float, float, float, float) / ParticleType_Create() / ParticleSystem_Create(int, bool)
 * 字段偏移 top8: 0x2×2 / 0xe0×1 / 0x30×1 / 0x70×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13f9a4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x13f9a8 sub sp, sp, #12
 *   @0x13f9ac mov r1, #0
 *   @0x13f9b0 ldr r5, [pc, #0xe0]
 *   @0x13f9b4 ldr r4, [sp, #0x30]
 *   @0x13f9b8 mov r0, r4
 *   @0x13f9bc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13f9c0 mov r1, #1
 *   @0x13f9c4 mov r6, r0
 *   @0x13f9c8 mov r0, r4
 *   @0x13f9cc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13f9d0 mov r1, #2
 *   @0x13f9d4 mov r10, r0
 *   @0x13f9d8 mov r0, r4
 *   @0x13f9dc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13f9e0 mov r1, #3
 *   @0x13f9e4 mov r9, r0
 *   @0x13f9e8 mov r0, r4
 *   @0x13f9ec bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13f9f0 mov r1, #4
 *   @0x13f9f4 mov r8, r0
 *   @0x13f9f8 mov r0, r4
 *   @0x13f9fc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13fa00 mov r1, #5
 *   @0x13fa04 mov r7, r0
 *   @0x13fa08 mov r0, r4
 *   @0x13fa0c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13fa10 ldr r5, [pc, r5]
 *   @0x13fa14 ldr r3, [r5]
 *   @0x13fa18 cmp r3, #0
 *   @0x13fa1c mov r11, r0
 *   @0x13fa20 blt 0x13fa84 <_Z25F_ActionPartTypeCreateOldR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x13fa24 ldr r5, [pc, #0x70]
 *   @0x13fa28 ldr r5, [pc, r5]
 *   @0x13fa2c ldr r4, [r5, r6, lsl #2]
 *   @0x13fa30 cmp r4, #0
 *   @0x13fa34 blt 0x13fa74 <_Z25F_ActionPartTypeCreateOldR6RValueP9CInstanceS2_iPS_+0xd0>
 *   @0x13fa38 mov r1, r10
 *   @0x13fa3c mov r0, r4
 *   @0x13fa40 bl 0x1a31a4 <_Z18ParticleType_Shapeii>
 *   @0x13fa44 mov r1, r9
 *   @0x13fa48 mov r2, r8
 *   @0x13fa4c mov r3, #0
 *   @0x13fa50 mov r0, r4
 *   @0x13fa54 str r3, [sp]
 *   @0x13fa58 bl 0x1a322c <_Z17ParticleType_Sizeiffff>
 *   @0x13fa5c mov r0, r4
 *   @0x13fa60 mov r1, r7
 *   @0x13fa64 mov r2, r11
 *   @0x13fa68 add sp, sp, #12
 *   @0x13fa6c pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x13fa70 b 0x1a35d8 <_Z19ParticleType_Color2ijj>
 *   @0x13fa74 bl 0x1a3068 <_Z19ParticleType_Createv>
 *   @0x13fa78 mov r4, r0
 *   @0x13fa7c str r0, [r5, r6, lsl #2]
 *   @0x13fa80 b 0x13fa38 <_Z25F_ActionPartTypeCreateOldR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0x13fa84 mvn r0, #0
 *   @0x13fa88 mov r1, #1
 *   @0x13fa8c bl 0x1a42dc <_Z21ParticleSystem_Createib>
 *   @0x13fa90 str r0, [r5]
 *   @0x13fa94 b 0x13fa24 <_Z25F_ActionPartTypeCreateOldR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x13fa98 eoreq pc, r10, r12, asr #19
 *   @0x13fa9c .word 0x002af9b8
 *
 * ══ §82/119 F_ActionPartTypeSpeed(RValue&, CInstance*, CInstance*, int, RValue*)  0x13fd3c  size 252  63 条（0x13fd3c..0x13fe38）
 * @func 0x13fd3c 0x13fe38  size 252  63 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×5 / YYGetInt32(RValue const*, int) / F_ActionPartTypeSpeed(RValue&, CInstance*, CInstance*, int, RValue*)+0xe0 / F_ActionPartTypeSpeed(RValue&, CInstance*, CInstance*, int, RValue*)+0xd0 / ParticleType_Speed(int, float, float, float, float) / ParticleType_Create() / ParticleSystem_Create(int, bool)
 * 字段偏移 top8: 0x30×2 / 0x2×2 / 0xe0×1 / 0x70×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13fd3c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x13fd40 sub sp, sp, #12
 *   @0x13fd44 mov r1, #0
 *   @0x13fd48 ldr r5, [pc, #0xe0]
 *   @0x13fd4c ldr r4, [sp, #0x30]
 *   @0x13fd50 mov r0, r4
 *   @0x13fd54 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13fd58 mov r1, #1
 *   @0x13fd5c mov r6, r0
 *   @0x13fd60 mov r0, r4
 *   @0x13fd64 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13fd68 mov r1, #2
 *   @0x13fd6c mov r10, r0
 *   @0x13fd70 mov r0, r4
 *   @0x13fd74 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13fd78 mov r1, #5
 *   @0x13fd7c mov r9, r0
 *   @0x13fd80 mov r0, r4
 *   @0x13fd84 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13fd88 mov r1, #3
 *   @0x13fd8c mov r8, r0
 *   @0x13fd90 mov r0, r4
 *   @0x13fd94 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13fd98 mov r1, #4
 *   @0x13fd9c mov r7, r0
 *   @0x13fda0 mov r0, r4
 *   @0x13fda4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13fda8 ldr r5, [pc, r5]
 *   @0x13fdac ldr r3, [r5]
 *   @0x13fdb0 cmp r3, #0
 *   @0x13fdb4 mov r11, r0
 *   @0x13fdb8 blt 0x13fe1c <_Z21F_ActionPartTypeSpeedR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x13fdbc ldr r5, [pc, #0x70]
 *   @0x13fdc0 ldr r5, [pc, r5]
 *   @0x13fdc4 ldr r4, [r5, r6, lsl #2]
 *   @0x13fdc8 cmp r4, #0
 *   @0x13fdcc blt 0x13fe0c <_Z21F_ActionPartTypeSpeedR6RValueP9CInstanceS2_iPS_+0xd0>
 *   @0x13fdd0 mov r5, #0
 *   @0x13fdd4 mov r1, r10
 *   @0x13fdd8 mov r2, r9
 *   @0x13fddc eor r3, r8, #-2147483648
 *   @0x13fde0 mov r0, r4
 *   @0x13fde4 str r5, [sp]
 *   @0x13fde8 bl 0x1a3368 <_Z18ParticleType_Speediffff>
 *   @0x13fdec str r5, [sp, #0x30]
 *   @0x13fdf0 mov r3, r5
 *   @0x13fdf4 mov r0, r4
 *   @0x13fdf8 mov r1, r7
 *   @0x13fdfc mov r2, r11
 *   @0x13fe00 add sp, sp, #12
 *   @0x13fe04 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x13fe08 b 0x1a33b4 <_Z22ParticleType_Directioniffff>
 *   @0x13fe0c bl 0x1a3068 <_Z19ParticleType_Createv>
 *   @0x13fe10 mov r4, r0
 *   @0x13fe14 str r0, [r5, r6, lsl #2]
 *   @0x13fe18 b 0x13fdd0 <_Z21F_ActionPartTypeSpeedR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0x13fe1c mvn r0, #0
 *   @0x13fe20 mov r1, #1
 *   @0x13fe24 bl 0x1a42dc <_Z21ParticleSystem_Createib>
 *   @0x13fe28 str r0, [r5]
 *   @0x13fe2c b 0x13fdbc <_Z21F_ActionPartTypeSpeedR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x13fe30 eoreq pc, r10, r4, lsr r6
 *   @0x13fe34 eoreq pc, r10, r0, lsr #12
 *
 * ══ §83/119 F_D3DModelLoad(RValue&, CInstance*, CInstance*, int, RValue*)  0x145238  size 252  63 条（0x145238..0x145334）
 * @func 0x145238 0x145334  size 252  63 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int) / LoadSave::SaveFileExists(char const*) / LoadSave::_GetSaveFileName(char*, int, char const*) / YYGetInt32(RValue const*, int) / GR_3DM_LoadFromFile(int, char const*) / LoadSave::BundleFileExists(char const*) / LoadSave::_GetBundleFileName(char*, int, char const*) / 0xb65d4
 * 字段偏移 top8: 0x404×2 / 0x4×2 / 0xe0×1 / 0x420×1 / 0x48×1 / 0x38×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x145238 push {r4, r5, r6, r7, lr}
 *   @0x14523c sub sp, sp, #1024
 *   @0x145240 ldr r4, [pc, #0xe0]
 *   @0x145244 sub sp, sp, #12
 *   @0x145248 mov r1, #1
 *   @0x14524c mov r5, r0
 *   @0x145250 ldr r4, [pc, r4]
 *   @0x145254 ldr r6, [sp, #0x420]
 *   @0x145258 ldr r3, [r4]
 *   @0x14525c mov r0, r6
 *   @0x145260 str r3, [sp, #0x404]
 *   @0x145264 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x145268 mov r7, r0
 *   @0x14526c bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc>
 *   @0x145270 cmp r0, #0
 *   @0x145274 beq 0x1452cc <_Z14F_D3DModelLoadR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0x145278 mov r2, r7
 *   @0x14527c add r7, sp, #4
 *   @0x145280 mov r1, #1024
 *   @0x145284 mov r0, r7
 *   @0x145288 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0x14528c mov r1, #0
 *   @0x145290 mov r0, r6
 *   @0x145294 mov r3, r1
 *   @0x145298 str r1, [r5]
 *   @0x14529c movt r3, #0x3ff0
 *   @0x1452a0 str r3, [r5, #0x4]
 *   @0x1452a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1452a8 mov r1, r7
 *   @0x1452ac bl 0x165250 <_Z19GR_3DM_LoadFromFileiPKc>
 *   @0x1452b0 ldr r2, [sp, #0x404]
 *   @0x1452b4 ldr r3, [r4]
 *   @0x1452b8 cmp r2, r3
 *   @0x1452bc bne 0x145324 <_Z14F_D3DModelLoadR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0x1452c0 add sp, sp, #1024
 *   @0x1452c4 add sp, sp, #12
 *   @0x1452c8 pop {r4, r5, r6, r7, pc}
 *   @0x1452cc mov r0, r7
 *   @0x1452d0 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc>
 *   @0x1452d4 cmp r0, #0
 *   @0x1452d8 bne 0x14530c <_Z14F_D3DModelLoadR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0x1452dc ldr r3, [pc, #0x48]
 *   @0x1452e0 mov r2, r7
 *   @0x1452e4 str r0, [r5]
 *   @0x1452e8 ldr r3, [pc, r3]
 *   @0x1452ec str r0, [r5, #0x4]
 *   @0x1452f0 ldr r1, [pc, #0x38]
 *   @0x1452f4 ldr r0, [r3]
 *   @0x1452f8 add r1, pc, r1
 *   @0x1452fc ldr r3, [r0]
 *   @0x145300 ldr r3, [r3, #0xc]
 *   @0x145304 blx r3
 *   @0x145308 b 0x1452b0 <_Z14F_D3DModelLoadR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x14530c mov r2, r7
 *   @0x145310 add r7, sp, #4
 *   @0x145314 mov r1, #1024
 *   @0x145318 mov r0, r7
 *   @0x14531c bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc>
 *   @0x145320 b 0x14528c <_Z14F_D3DModelLoadR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x145324 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x145328 eoreq r8, r10, r0, lsl #14
 *   @0x14532c eoreq r8, r10, r12, lsr #8
 *   @0x145330 ldrheq r12, [pc], -r0
 *
 * ══ §84/119 F_CameraSetViewMat(RValue&, CInstance*, CInstance*, int, RValue*)  0x16f584  size 252  63 条（0x16f584..0x16f680）
 * @func 0x16f584 0x16f694  size 272  68 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Error_Show_Action(char const*, bool)×2 / Error_Show(char const*, bool) / YYGetInt32(RValue const*, int) / CCameraManager::GetCamera(int) / YYGetFloat(RValue const*, int) / CCamera::SetViewMat(yyMatrix&)
 * 字段偏移 top8: 0x4×5 / 0x10×2 / 0xc×1 / 0x58×1 / 0xb8×1 / 0x98×1 / 0x68×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16f584 push {r4, r5, r6, r7, r8, lr}
 *   @0x16f588 cmp r3, #2
 *   @0x16f58c sub sp, sp, #64
 *   @0x16f590 mov r3, #0
 *   @0x16f594 mov r4, r3
 *   @0x16f598 movt r3, #0xbff0
 *   @0x16f59c str r4, [r0, #0xc]
 *   @0x16f5a0 str r3, [r0, #0x4]
 *   @0x16f5a4 str r4, [r0]
 *   @0x16f5a8 ldr r6, [sp, #0x58]
 *   @0x16f5ac beq 0x16f5c8 <_Z18F_CameraSetViewMatR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x16f5b0 ldr r0, [pc, #0xb8]
 *   @0x16f5b4 mov r1, r4
 *   @0x16f5b8 add r0, pc, r0
 *   @0x16f5bc bl 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x16f5c0 add sp, sp, #64
 *   @0x16f5c4 pop {r4, r5, r6, r7, r8, pc}
 *   @0x16f5c8 mov r1, r4
 *   @0x16f5cc mov r0, r6
 *   @0x16f5d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x16f5d4 ldr r3, [pc, #0x98]
 *   @0x16f5d8 mov r1, r0
 *   @0x16f5dc ldr r0, [pc, r3]
 *   @0x16f5e0 bl 0x16f45c <_ZN14CCameraManager9GetCameraEi>
 *   @0x16f5e4 subs r7, r0, #0
 *   @0x16f5e8 beq 0x16f5c0 <_Z18F_CameraSetViewMatR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x16f5ec ldr r1, [r6, #0x10]
 *   @0x16f5f0 cmp r1, #0
 *   @0x16f5f4 beq 0x16f660 <_Z18F_CameraSetViewMatR6RValueP9CInstanceS2_iPS_+0xdc>
 *   @0x16f5f8 ldr r3, [r1, #0x4]
 *   @0x16f5fc ldr r2, [r3]
 *   @0x16f600 cmp r2, #16
 *   @0x16f604 beq 0x16f620 <_Z18F_CameraSetViewMatR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x16f608 ldr r0, [pc, #0x68]
 *   @0x16f60c mov r1, r4
 *   @0x16f610 add r0, pc, r0
 *   @0x16f614 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x16f618 add sp, sp, #64
 *   @0x16f61c pop {r4, r5, r6, r7, r8, pc}
 *   @0x16f620 mov r5, sp
 *   @0x16f624 b 0x16f630 <_Z18F_CameraSetViewMatR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0x16f628 ldr r3, [r6, #0x10]
 *   @0x16f62c ldr r3, [r3, #0x4]
 *   @0x16f630 mov r1, r4
 *   @0x16f634 ldr r0, [r3, #0x4]
 *   @0x16f638 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x16f63c add r4, r4, #1
 *   @0x16f640 cmp r4, #16
 *   @0x16f644 str r0, [r5], #4
 *   @0x16f648 bne 0x16f628 <_Z18F_CameraSetViewMatR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0x16f64c mov r0, r7
 *   @0x16f650 mov r1, sp
 *   @0x16f654 bl 0x16da94 <_ZN7CCamera10SetViewMatER8yyMatrix>
 *   @0x16f658 add sp, sp, #64
 *   @0x16f65c pop {r4, r5, r6, r7, r8, pc}
 *   @0x16f660 ldr r0, [pc, #0x14]
 *   @0x16f664 add r0, pc, r0
 *   @0x16f668 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x16f66c b 0x16f5c0 <_Z18F_CameraSetViewMatR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x16f670 andseq r11, sp, r0, lsr #15
 *   @0x16f674 mlaeq r7, r8, r6, lr
 *   @0x16f678 andseq r11, sp, r4, asr #15
 *   @0x16f67c andseq r11, sp, r8, lsr #14
 *
 * ══ §85/119 F_CameraSetProjMat(RValue&, CInstance*, CInstance*, int, RValue*)  0x16f680  size 252  63 条（0x16f680..0x16f77c）
 * @func 0x16f680 0x16f77c  size 252  63 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Error_Show_Action(char const*, bool)×2 / Error_Show(char const*, bool) / YYGetInt32(RValue const*, int) / CCameraManager::GetCamera(int) / YYGetFloat(RValue const*, int) / CCamera::SetProjMat(yyMatrix&)
 * 字段偏移 top8: 0x4×5 / 0x10×2 / 0xc×1 / 0x58×1 / 0xb8×1 / 0x98×1 / 0x68×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16f680 push {r4, r5, r6, r7, r8, lr}
 *   @0x16f684 cmp r3, #2
 *   @0x16f688 sub sp, sp, #64
 *   @0x16f68c mov r3, #0
 *   @0x16f690 mov r4, r3
 *   @0x16f694 movt r3, #0xbff0
 *   @0x16f698 str r4, [r0, #0xc]
 *   @0x16f69c str r3, [r0, #0x4]
 *   @0x16f6a0 str r4, [r0]
 *   @0x16f6a4 ldr r6, [sp, #0x58]
 *   @0x16f6a8 beq 0x16f6c4 <_Z18F_CameraSetProjMatR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x16f6ac ldr r0, [pc, #0xb8]
 *   @0x16f6b0 mov r1, r4
 *   @0x16f6b4 add r0, pc, r0
 *   @0x16f6b8 bl 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x16f6bc add sp, sp, #64
 *   @0x16f6c0 pop {r4, r5, r6, r7, r8, pc}
 *   @0x16f6c4 mov r1, r4
 *   @0x16f6c8 mov r0, r6
 *   @0x16f6cc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x16f6d0 ldr r3, [pc, #0x98]
 *   @0x16f6d4 mov r1, r0
 *   @0x16f6d8 ldr r0, [pc, r3]
 *   @0x16f6dc bl 0x16f45c <_ZN14CCameraManager9GetCameraEi>
 *   @0x16f6e0 subs r7, r0, #0
 *   @0x16f6e4 beq 0x16f6bc <_Z18F_CameraSetProjMatR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x16f6e8 ldr r1, [r6, #0x10]
 *   @0x16f6ec cmp r1, #0
 *   @0x16f6f0 beq 0x16f75c <_Z18F_CameraSetProjMatR6RValueP9CInstanceS2_iPS_+0xdc>
 *   @0x16f6f4 ldr r3, [r1, #0x4]
 *   @0x16f6f8 ldr r2, [r3]
 *   @0x16f6fc cmp r2, #16
 *   @0x16f700 beq 0x16f71c <_Z18F_CameraSetProjMatR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x16f704 ldr r0, [pc, #0x68]
 *   @0x16f708 mov r1, r4
 *   @0x16f70c add r0, pc, r0
 *   @0x16f710 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x16f714 add sp, sp, #64
 *   @0x16f718 pop {r4, r5, r6, r7, r8, pc}
 *   @0x16f71c mov r5, sp
 *   @0x16f720 b 0x16f72c <_Z18F_CameraSetProjMatR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0x16f724 ldr r3, [r6, #0x10]
 *   @0x16f728 ldr r3, [r3, #0x4]
 *   @0x16f72c mov r1, r4
 *   @0x16f730 ldr r0, [r3, #0x4]
 *   @0x16f734 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x16f738 add r4, r4, #1
 *   @0x16f73c cmp r4, #16
 *   @0x16f740 str r0, [r5], #4
 *   @0x16f744 bne 0x16f724 <_Z18F_CameraSetProjMatR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0x16f748 mov r0, r7
 *   @0x16f74c mov r1, sp
 *   @0x16f750 bl 0x16d9e4 <_ZN7CCamera10SetProjMatER8yyMatrix>
 *   @0x16f754 add sp, sp, #64
 *   @0x16f758 pop {r4, r5, r6, r7, r8, pc}
 *   @0x16f75c ldr r0, [pc, #0x14]
 *   @0x16f760 add r0, pc, r0
 *   @0x16f764 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x16f768 b 0x16f6bc <_Z18F_CameraSetProjMatR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x16f76c andseq r11, sp, r4, asr r7
 *   @0x16f770 mlaeq r7, r12, r5, lr
 *   @0x16f774 andseq r11, sp, r8, asr #13
 *   @0x16f778 andseq r11, sp, r12, lsr #12
 *
 * ══ §86/119 GMGamePad::GMGamePad(int, int)  0x18e9d4  size 252  63 条（0x18e9d4..0x18ead0）
 * @func 0x18e9d4 0x18ead0  size 252  63 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool)×4 / GMGamePad::Clear() / GMGamePad::SetDeviceId(char const*)
 * 字段偏移 top8: 0xc×2 / 0x50×2 / 0x24×2 / 0xdc×1 / 0x4×1 / 0x1c×1 / 0x8×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18e9d4 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x18e9d8 lsl r9, r1, #2
 *   @0x18e9dc ldr r5, [pc, #0xdc]
 *   @0x18e9e0 mov r4, r0
 *   @0x18e9e4 str r1, [r0, #0x4]
 *   @0x18e9e8 mov r12, #1056964608
 *   @0x18e9ec add r5, pc, r5
 *   @0x18e9f0 str r12, [r4, #0x1c]
 *   @0x18e9f4 mov r6, r2
 *   @0x18e9f8 mov r7, #0
 *   @0x18e9fc str r2, [r4, #0x8]
 *   @0x18ea00 mov r1, r5
 *   @0x18ea04 mov r3, #0
 *   @0x18ea08 mov r0, r9
 *   @0x18ea0c strb r3, [r4]
 *   @0x18ea10 mov r2, #91
 *   @0x18ea14 str r7, [r4, #0x20]
 *   @0x18ea18 mov r3, #1
 *   @0x18ea1c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x18ea20 mov r1, r5
 *   @0x18ea24 mov r2, #92
 *   @0x18ea28 mov r3, #1
 *   @0x18ea2c lsl r8, r6, #2
 *   @0x18ea30 str r0, [r4, #0xc]
 *   @0x18ea34 mov r0, r9
 *   @0x18ea38 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x18ea3c mov r1, r5
 *   @0x18ea40 mov r2, #93
 *   @0x18ea44 mov r3, #1
 *   @0x18ea48 str r0, [r4, #0x10]
 *   @0x18ea4c mov r0, r8
 *   @0x18ea50 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x18ea54 mov r1, r5
 *   @0x18ea58 mov r2, #94
 *   @0x18ea5c mov r3, #1
 *   @0x18ea60 str r0, [r4, #0x14]
 *   @0x18ea64 mov r0, r8
 *   @0x18ea68 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x18ea6c ldr r12, [pc, #0x50]
 *   @0x18ea70 ldr r1, [pc, #0x50]
 *   @0x18ea74 mov r2, r6
 *   @0x18ea78 ldr r12, [pc, r12]
 *   @0x18ea7c add r1, pc, r1
 *   @0x18ea80 mov r3, r0
 *   @0x18ea84 str r0, [r4, #0x18]
 *   @0x18ea88 ldr r0, [r12]
 *   @0x18ea8c ldr r12, [r0]
 *   @0x18ea90 ldr r12, [r12, #0xc]
 *   @0x18ea94 blx r12
 *   @0x18ea98 mov r0, r4
 *   @0x18ea9c bl 0x18e778 <_ZN9GMGamePad5ClearEv>
 *   @0x18eaa0 ldr r1, [pc, #0x24]
 *   @0x18eaa4 mov r0, r4
 *   @0x18eaa8 str r7, [r4, #0x28]
 *   @0x18eaac str r7, [r4, #0x24]
 *   @0x18eab0 add r1, pc, r1
 *   @0x18eab4 bl 0x18e944 <_ZN9GMGamePad11SetDeviceIdEPKc>
 *   @0x18eab8 mov r0, r4
 *   @0x18eabc pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x18eac0 ldrsbeq sp, [r11], -r4
 *   @0x18eac4 eoreq r1, r6, r4, lsr #1
 *   @0x18eac8 andseq sp, r11, r8, ror r9
 *   @0x18eacc andseq r0, r10, r6, lsl #1
 *
 * ══ §87/119 CDS_Priority::Clear()  0x209768  size 252  63 条（0x209768..0x209864）
 * @func 0x209768 0x209864  size 252  63 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FREE_RValue__Pre(RValue*)×2 / MemoryManager::Free(void const*)×2 / CDS_Priority::Clear()+0x74 / CDS_Priority::Clear()+0xe8
 * 字段偏移 top8: 0xc×7 / 0x8×5 / 0x10×3 / 0x14×3 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x209768 ldr r3, [r0, #0x8]
 *   @0x20976c push {r4, r5, r6, r7, r8, lr}
 *   @0x209770 mov r5, #0
 *   @0x209774 cmp r3, r5
 *   @0x209778 mov r6, r0
 *   @0x20977c str r5, [r0, #0x4]
 *   @0x209780 movgt r7, r5
 *   @0x209784 ldr r0, [r0, #0xc]
 *   @0x209788 movgt r8, #5
 *   @0x20978c bgt 0x2097ac <_ZN12CDS_Priority5ClearEv+0x44>
 *   @0x209790 b 0x2097dc <_ZN12CDS_Priority5ClearEv+0x74>
 *   @0x209794 str r7, [r4]
 *   @0x209798 ldr r3, [r6, #0x8]
 *   @0x20979c str r7, [r4, #0x8]
 *   @0x2097a0 cmp r3, r5
 *   @0x2097a4 str r8, [r4, #0xc]
 *   @0x2097a8 ble 0x2097dc <_ZN12CDS_Priority5ClearEv+0x74>
 *   @0x2097ac add r4, r0, r5, lsl #4
 *   @0x2097b0 add r5, r5, #1
 *   @0x2097b4 ldr r3, [r4, #0xc]
 *   @0x2097b8 sub r3, r3, #1
 *   @0x2097bc bic r3, r3, #-16777216
 *   @0x2097c0 bic r3, r3, #3
 *   @0x2097c4 cmp r3, #0
 *   @0x2097c8 bne 0x209794 <_ZN12CDS_Priority5ClearEv+0x2c>
 *   @0x2097cc mov r0, r4
 *   @0x2097d0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x2097d4 ldr r0, [r6, #0xc]
 *   @0x2097d8 b 0x209794 <_ZN12CDS_Priority5ClearEv+0x2c>
 *   @0x2097dc mov r5, #0
 *   @0x2097e0 str r5, [r6, #0x8]
 *   @0x2097e4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x2097e8 ldr r3, [r6, #0x10]
 *   @0x2097ec str r5, [r6, #0xc]
 *   @0x2097f0 cmp r3, r5
 *   @0x2097f4 ldr r0, [r6, #0x14]
 *   @0x2097f8 movgt r7, r5
 *   @0x2097fc movgt r8, #5
 *   @0x209800 bgt 0x209820 <_ZN12CDS_Priority5ClearEv+0xb8>
 *   @0x209804 b 0x209850 <_ZN12CDS_Priority5ClearEv+0xe8>
 *   @0x209808 str r7, [r4]
 *   @0x20980c ldr r3, [r6, #0x10]
 *   @0x209810 str r7, [r4, #0x8]
 *   @0x209814 cmp r3, r5
 *   @0x209818 str r8, [r4, #0xc]
 *   @0x20981c ble 0x209850 <_ZN12CDS_Priority5ClearEv+0xe8>
 *   @0x209820 add r4, r0, r5, lsl #4
 *   @0x209824 add r5, r5, #1
 *   @0x209828 ldr r3, [r4, #0xc]
 *   @0x20982c sub r3, r3, #1
 *   @0x209830 bic r3, r3, #-16777216
 *   @0x209834 bic r3, r3, #3
 *   @0x209838 cmp r3, #0
 *   @0x20983c bne 0x209808 <_ZN12CDS_Priority5ClearEv+0xa0>
 *   @0x209840 mov r0, r4
 *   @0x209844 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x209848 ldr r0, [r6, #0x14]
 *   @0x20984c b 0x209808 <_ZN12CDS_Priority5ClearEv+0xa0>
 *   @0x209850 mov r4, #0
 *   @0x209854 str r4, [r6, #0x10]
 *   @0x209858 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x20985c str r4, [r6, #0x14]
 *   @0x209860 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §88/119 SHA1PadMessage(SHA1Context*)  0x2145e8  size 252  63 条（0x2145e8..0x2146e4）
 * @func 0x2145e8 0x2146e4  size 252  63 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: SHA1PadMessage(SHA1Context*)+0xc8 / SHA1ProcessMessageBlock(SHA1Context*)
 * 字段偏移 top8: 0x5c×6 / 0x1c×4 / 0x18×1 / 0x14×1 / 0x57×1 / 0x55×1 / 0x5b×1 / 0x56×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2145e8 ldr r2, [r0, #0x5c]
 *   @0x2145ec push {r4, lr}
 *   @0x2145f0 cmp r2, #55
 *   @0x2145f4 mov r4, r0
 *   @0x2145f8 add r3, r2, #1
 *   @0x2145fc ble 0x2146b0 <_Z14SHA1PadMessageP11SHA1Context+0xc8>
 *   @0x214600 add r2, r0, r2
 *   @0x214604 cmp r3, #63
 *   @0x214608 mvn r1, #127
 *   @0x21460c str r3, [r0, #0x5c]
 *   @0x214610 strb r1, [r2, #0x1c]
 *   @0x214614 movle r1, #0
 *   @0x214618 bgt 0x214634 <_Z14SHA1PadMessageP11SHA1Context+0x4c>
 *   @0x21461c add r2, r4, r3
 *   @0x214620 add r3, r3, #1
 *   @0x214624 cmp r3, #64
 *   @0x214628 strb r1, [r2, #0x1c]
 *   @0x21462c bne 0x21461c <_Z14SHA1PadMessageP11SHA1Context+0x34>
 *   @0x214630 str r3, [r4, #0x5c]
 *   @0x214634 mov r0, r4
 *   @0x214638 bl 0x2142e8 <_Z23SHA1ProcessMessageBlockP11SHA1Context>
 *   @0x21463c ldr r3, [r4, #0x5c]
 *   @0x214640 cmp r3, #55
 *   @0x214644 movle r1, #0
 *   @0x214648 bgt 0x214664 <_Z14SHA1PadMessageP11SHA1Context+0x7c>
 *   @0x21464c add r2, r4, r3
 *   @0x214650 add r3, r3, #1
 *   @0x214654 cmp r3, #56
 *   @0x214658 strb r1, [r2, #0x1c]
 *   @0x21465c bne 0x21464c <_Z14SHA1PadMessageP11SHA1Context+0x64>
 *   @0x214660 str r3, [r4, #0x5c]
 *   @0x214664 ldr r2, [r4, #0x18]
 *   @0x214668 mov r0, r4
 *   @0x21466c ldr r3, [r4, #0x14]
 *   @0x214670 lsr r1, r2, #16
 *   @0x214674 strb r2, [r4, #0x57]
 *   @0x214678 lsr r12, r2, #24
 *   @0x21467c strb r1, [r4, #0x55]
 *   @0x214680 lsr r2, r2, #8
 *   @0x214684 strb r3, [r4, #0x5b]
 *   @0x214688 lsr r1, r3, #24
 *   @0x21468c strb r2, [r4, #0x56]
 *   @0x214690 strb r12, [r4, #0x54]
 *   @0x214694 lsr r2, r3, #16
 *   @0x214698 strb r1, [r4, #0x58]
 *   @0x21469c lsr r3, r3, #8
 *   @0x2146a0 strb r2, [r4, #0x59]
 *   @0x2146a4 strb r3, [r4, #0x5a]
 *   @0x2146a8 pop {r4, lr}
 *   @0x2146ac b 0x2142e8 <_Z23SHA1ProcessMessageBlockP11SHA1Context>
 *   @0x2146b0 add r1, r0, r2
 *   @0x2146b4 cmp r3, #56
 *   @0x2146b8 str r3, [r0, #0x5c]
 *   @0x2146bc mvn r0, #127
 *   @0x2146c0 strb r0, [r1, #0x1c]
 *   @0x2146c4 beq 0x214664 <_Z14SHA1PadMessageP11SHA1Context+0x7c>
 *   @0x2146c8 add r2, r1, #28
 *   @0x2146cc mov r1, #0
 *   @0x2146d0 add r3, r3, #1
 *   @0x2146d4 strb r1, [r2, #0x1]!
 *   @0x2146d8 cmp r3, #56
 *   @0x2146dc bne 0x2146d0 <_Z14SHA1PadMessageP11SHA1Context+0xe8>
 *   @0x2146e0 b 0x214660 <_Z14SHA1PadMessageP11SHA1Context+0x78>
 *
 * ══ §89/119 JS_Array_prototype_lastIndexOf(RValue&, CInstance*, CInstance*, int, RValue*)  0x240c24  size 252  63 条（0x240c24..0x240d20）
 * @func 0x240c24 0x240d20  size 252  63 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JS_Array_prototype_lastIndexOf(RValue&, CInstance*, CInstance*, int, RValue*)+0xdc×2 / YYObjectBase::InternalGetYYVar(int)×2 / JS_Array_prototype_lastIndexOf(RValue&, CInstance*, CInstance*, int, RValue*)+0xe4 / YYGetInt32(RValue const*, int) / JS_Global_abstractStrictEqualityComparison(RValue&, RValue&)
 * 字段偏移 top8: 0x4×2 / 0xc×2 / 0x28×2 / 0x24×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x240c24 mov r12, #0
 *   @0x240c28 push {r4, r5, r6, r7, r8, lr}
 *   @0x240c2c mov r2, r12
 *   @0x240c30 movt r12, #0xbff0
 *   @0x240c34 stm r0, {r2, r12}
 *   @0x240c38 ldr r12, [r1, #0x4]
 *   @0x240c3c sub sp, sp, #16
 *   @0x240c40 mov r7, r0
 *   @0x240c44 mov r5, r3
 *   @0x240c48 cmp r12, r2
 *   @0x240c4c str r2, [r0, #0xc]
 *   @0x240c50 beq 0x240d10 <_Z30JS_Array_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0x240c54 add r0, r12, #16
 *   @0x240c58 ldr r6, [r0]
 *   @0x240c5c ldr r4, [r6, #0x24]
 *   @0x240c60 cmp r4, #0
 *   @0x240c64 beq 0x240d00 <_Z30JS_Array_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0xdc>
 *   @0x240c68 cmp r5, #0
 *   @0x240c6c mov r3, #5
 *   @0x240c70 str r3, [sp, #0xc]
 *   @0x240c74 ble 0x240d08 <_Z30JS_Array_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0x240c78 ldr r12, [sp, #0x28]
 *   @0x240c7c cmp r5, #1
 *   @0x240c80 ldm r12, {r0, r1, r2, r3}
 *   @0x240c84 add r12, sp, #16
 *   @0x240c88 stmdb r12, {r0, r1, r2, r3}
 *   @0x240c8c beq 0x240d08 <_Z30JS_Array_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0x240c90 ldr r0, [sp, #0x28]
 *   @0x240c94 mov r1, #1
 *   @0x240c98 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x240c9c mov r4, r0
 *   @0x240ca0 cmp r4, #0
 *   @0x240ca4 blt 0x240d00 <_Z30JS_Array_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0xdc>
 *   @0x240ca8 lsl r5, r4, #4
 *   @0x240cac b 0x240ccc <_Z30JS_Array_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0x240cb0 mov r0, sp
 *   @0x240cb4 sub r5, r5, #16
 *   @0x240cb8 bl 0x240a08 <_Z42JS_Global_abstractStrictEqualityComparisonR6RValueS0_>
 *   @0x240cbc cmp r0, #0
 *   @0x240cc0 bne 0x240cf0 <_Z30JS_Array_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0xcc>
 *   @0x240cc4 subs r4, r4, #1
 *   @0x240cc8 blo 0x240d00 <_Z30JS_Array_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0xdc>
 *   @0x240ccc ldr r1, [r6, #0x4]
 *   @0x240cd0 cmp r1, #0
 *   @0x240cd4 add r1, r1, r5
 *   @0x240cd8 bne 0x240cb0 <_Z30JS_Array_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x240cdc mov r1, r4
 *   @0x240ce0 mov r0, r6
 *   @0x240ce4 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x240ce8 mov r1, r0
 *   @0x240cec b 0x240cb0 <_Z30JS_Array_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x240cf0 vmov s15, r4
 *   @0x240cf4 vcvt.f64.s32 d7, s15
 *   @0x240cf8 vmov r2, r3, d7
 *   @0x240cfc stm r7, {r2, r3}
 *   @0x240d00 add sp, sp, #16
 *   @0x240d04 pop {r4, r5, r6, r7, r8, pc}
 *   @0x240d08 sub r4, r4, #1
 *   @0x240d0c b 0x240ca0 <_Z30JS_Array_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0x240d10 mov r0, r1
 *   @0x240d14 mov r1, #1
 *   @0x240d18 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x240d1c b 0x240c58 <_Z30JS_Array_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0x34>
 *
 * ══ §90/119 F_JS_Object_isFrozen(RValue&, CInstance*, CInstance*, int, RValue*)  0x2507cc  size 252  63 条（0x2507cc..0x2508c8）
 * @func 0x2507cc 0x2508dc  size 272  68 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JSThrowTypeError(char const*) / YYObject_PropertyNameIterator::YYObject_PropertyNameIterator(YYObjectBase*, int) / YYObject_PropertyNameIterator::Next(RValue*) / JS_GetOwnProperty(YYObjectBase*, RValue*, char const*) / JS_IsDataDescriptor(RValue*) / YYObjectBase::IsExtensible()
 * 字段偏移 top8: 0xc×2 / 0x4×2 / 0x68×1 / 0xc8×1 / 0x20×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2507cc push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2507d0 cmp r3, #0
 *   @0x2507d4 sub sp, sp, #68
 *   @0x2507d8 mov r10, r0
 *   @0x2507dc ldr r7, [sp, #0x68]
 *   @0x2507e0 beq 0x2507f4 <_Z20F_JS_Object_isFrozenR6RValueP9CInstanceS2_iPS_+0x28>
 *   @0x2507e4 ldr r3, [r7, #0xc]
 *   @0x2507e8 bic r3, r3, #-16777216
 *   @0x2507ec cmp r3, #6
 *   @0x2507f0 beq 0x250808 <_Z20F_JS_Object_isFrozenR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x2507f4 ldr r0, [pc, #0xc8]
 *   @0x2507f8 add r0, pc, r0
 *   @0x2507fc bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x250800 add sp, sp, #68
 *   @0x250804 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x250808 ldr r5, [r7]
 *   @0x25080c add r6, sp, #36
 *   @0x250810 mov r3, #13
 *   @0x250814 mov r2, #1
 *   @0x250818 mov r0, r6
 *   @0x25081c str r3, [r10, #0xc]
 *   @0x250820 mov r1, r5
 *   @0x250824 add r8, sp, #4
 *   @0x250828 bl 0x2400ec <_ZN29YYObject_PropertyNameIteratorC2EP12YYObjectBasei>
 *   @0x25082c mov r9, #5
 *   @0x250830 add r4, sp, #20
 *   @0x250834 b 0x250840 <_Z20F_JS_Object_isFrozenR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x250838 tst r3, #2
 *   @0x25083c bne 0x250888 <_Z20F_JS_Object_isFrozenR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x250840 mov r1, r8
 *   @0x250844 mov r0, r6
 *   @0x250848 bl 0x24a1fc <_ZN29YYObject_PropertyNameIterator4NextEP6RValue>
 *   @0x25084c mov r1, r4
 *   @0x250850 subs r11, r0, #0
 *   @0x250854 mov r0, r5
 *   @0x250858 beq 0x25089c <_Z20F_JS_Object_isFrozenR6RValueP9CInstanceS2_iPS_+0xd0>
 *   @0x25085c ldr r3, [sp, #0x4]
 *   @0x250860 str r9, [sp, #0x20]
 *   @0x250864 ldr r2, [r3]
 *   @0x250868 bl 0x241890 <_Z17JS_GetOwnPropertyP12YYObjectBaseP6RValuePKc>
 *   @0x25086c mov r0, r4
 *   @0x250870 bl 0x2407e8 <_Z19JS_IsDataDescriptorP6RValue>
 *   @0x250874 ldr r3, [sp, #0x1c]
 *   @0x250878 cmp r0, #0
 *   @0x25087c beq 0x250838 <_Z20F_JS_Object_isFrozenR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x250880 tst r3, #4
 *   @0x250884 beq 0x250838 <_Z20F_JS_Object_isFrozenR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x250888 mov r3, #0
 *   @0x25088c str r3, [r10]
 *   @0x250890 str r3, [r10, #0x4]
 *   @0x250894 add sp, sp, #68
 *   @0x250898 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x25089c ldr r0, [r7]
 *   @0x2508a0 bl 0x19220c <_ZN12YYObjectBase12IsExtensibleEv>
 *   @0x2508a4 cmp r0, #0
 *   @0x2508a8 streq r0, [r10]
 *   @0x2508ac strne r11, [r10]
 *   @0x2508b0 moveq r3, #0
 *   @0x2508b4 strne r11, [r10, #0x4]
 *   @0x2508b8 movteq r3, #0x3ff0
 *   @0x2508bc streq r3, [r10, #0x4]
 *   @0x2508c0 b 0x250800 <_Z20F_JS_Object_isFrozenR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x2508c4 andseq r5, r0, r0, asr r7
 *
 * ══ §91/119 pcre_get_substring_list  0x25f4d0  size 252  63 条（0x25f4d0..0x25f5cc）
 * @func 0x25f4d0 0x25f5cc  size 252  63 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: pcre_get_substring_list+0xe8 / pcre_get_substring_list+0xdc / 0xb65bc
 * 字段偏移 top8: 0x-4×2 / 0x98×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x25f4d0 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x25f4d4 lsl r6, r2, #1
 *   @0x25f4d8 cmp r6, #0
 *   @0x25f4dc mov r10, r2
 *   @0x25f4e0 mov r7, r0
 *   @0x25f4e4 mov r4, r1
 *   @0x25f4e8 mov r8, r3
 *   @0x25f4ec ble 0x25f5b8 <pcre_get_substring_list+0xe8>
 *   @0x25f4f0 add r2, r1, r6, lsl #2
 *   @0x25f4f4 add r12, r1, #4
 *   @0x25f4f8 add r2, r2, #4
 *   @0x25f4fc mov lr, #4
 *   @0x25f500 ldr r5, [r12]
 *   @0x25f504 add lr, lr, #5
 *   @0x25f508 ldr r0, [r12, #-0x4]
 *   @0x25f50c add r12, r12, #8
 *   @0x25f510 cmp r5, r0
 *   @0x25f514 rsb r3, r0, r5
 *   @0x25f518 addgt lr, lr, r3
 *   @0x25f51c cmp r12, r2
 *   @0x25f520 bne 0x25f500 <pcre_get_substring_list+0x30>
 *   @0x25f524 mov r0, lr
 *   @0x25f528 ldr r3, [pc, #0x98]
 *   @0x25f52c ldr r3, [pc, r3]
 *   @0x25f530 ldr r3, [r3]
 *   @0x25f534 blx r3
 *   @0x25f538 subs r9, r0, #0
 *   @0x25f53c beq 0x25f5c0 <pcre_get_substring_list+0xf0>
 *   @0x25f540 add r3, r10, #1
 *   @0x25f544 cmp r6, #0
 *   @0x25f548 str r9, [r8]
 *   @0x25f54c add r3, r9, r3, lsl #2
 *   @0x25f550 ble 0x25f5ac <pcre_get_substring_list+0xdc>
 *   @0x25f554 mov r10, #0
 *   @0x25f558 add r4, r4, #4
 *   @0x25f55c mov r8, r10
 *   @0x25f560 mov r11, r9
 *   @0x25f564 ldr r2, [r4]
 *   @0x25f568 mov r5, #0
 *   @0x25f56c ldr r1, [r4, #-0x4]
 *   @0x25f570 mov r0, r3
 *   @0x25f574 add r10, r10, #2
 *   @0x25f578 add r4, r4, #8
 *   @0x25f57c cmp r2, r1
 *   @0x25f580 rsbgt r5, r1, r2
 *   @0x25f584 add r1, r7, r1
 *   @0x25f588 mov r2, r5
 *   @0x25f58c bl 0xb65bc <memcpy@plt>
 *   @0x25f590 cmp r6, r10
 *   @0x25f594 add r5, r0, r5
 *   @0x25f598 str r0, [r11], #4
 *   @0x25f59c add r3, r5, #1
 *   @0x25f5a0 strb r8, [r5]
 *   @0x25f5a4 bgt 0x25f564 <pcre_get_substring_list+0x94>
 *   @0x25f5a8 add r9, r9, r6, lsl #1
 *   @0x25f5ac mov r0, #0
 *   @0x25f5b0 str r0, [r9]
 *   @0x25f5b4 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x25f5b8 mov r0, #4
 *   @0x25f5bc b 0x25f528 <pcre_get_substring_list+0x58>
 *   @0x25f5c0 mvn r0, #5
 *   @0x25f5c4 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x25f5c8 ldrheq r2, [r9], -r8
 *
 * ══ §92/119 Java_com_yoyogames_runner_RunnerJNILib_onItemPurchase  0x293278  size 252  63 条（0x293278..0x293374）
 * @func 0x293278 0x293374  size 252  63 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: setJNIEnv / MemoryManager::Alloc(unsigned int, char const*, int, bool) / YYStrDup(char const*) / operator new(unsigned int) / HTTP_REQ_CONTEXT::HTTP_REQ_CONTEXT(char const*, int, int (*)(HTTP_REQ_CONTEXT*, void*, int*), void (*)(HTTP_REQ_CONTEXT*), void*, bool)
 * 字段偏移 top8: 0x8c×2 / 0x4×2 / 0xc×2 / 0x2a4×1 / 0xb4×1 / 0x60×1 / 0x8×1 / 0x2a8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x293278 push {r4, r5, r6, r7, r8, lr}
 *   @0x29327c mov r5, r0
 *   @0x293280 sub sp, sp, #16
 *   @0x293284 mov r7, r2
 *   @0x293288 mov r8, r3
 *   @0x29328c bl 0x290614 <setJNIEnv>
 *   @0x293290 ldr r3, [r5]
 *   @0x293294 mov r1, r7
 *   @0x293298 mov r2, #0
 *   @0x29329c mov r0, r5
 *   @0x2932a0 ldr r3, [r3, #0x2a4]
 *   @0x2932a4 blx r3
 *   @0x2932a8 ldr r1, [pc, #0xb4]
 *   @0x2932ac movw r2, #0x89d
 *   @0x2932b0 mov r3, #1
 *   @0x2932b4 add r1, pc, r1
 *   @0x2932b8 mov r6, r0
 *   @0x2932bc mov r0, #8
 *   @0x2932c0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x2932c4 mov r4, r0
 *   @0x2932c8 str r8, [r0]
 *   @0x2932cc mov r0, r6
 *   @0x2932d0 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x2932d4 ldr r12, [pc, #0x8c]
 *   @0x2932d8 ldr r1, [pc, #0x8c]
 *   @0x2932dc mov r3, r4
 *   @0x2932e0 ldr r12, [pc, r12]
 *   @0x2932e4 add r1, pc, r1
 *   @0x2932e8 mov r2, r0
 *   @0x2932ec str r0, [r4, #0x4]
 *   @0x2932f0 ldr r0, [r12]
 *   @0x2932f4 ldr r12, [r0]
 *   @0x2932f8 ldr r12, [r12, #0xc]
 *   @0x2932fc blx r12
 *   @0x293300 mov r0, #68
 *   @0x293304 bl 0x27c524 <_Znwj>
 *   @0x293308 ldr r3, [pc, #0x60]
 *   @0x29330c mov r12, #0
 *   @0x293310 str r4, [sp, #0x4]
 *   @0x293314 ldr r3, [pc, r3]
 *   @0x293318 mov r1, r12
 *   @0x29331c str r12, [sp]
 *   @0x293320 mov r2, r12
 *   @0x293324 str r12, [sp, #0x8]
 *   @0x293328 mov r8, r0
 *   @0x29332c bl 0x18d834 <_ZN16HTTP_REQ_CONTEXTC2EPKciPFiPS_PvPiEPFvS2_ES3_b>
 *   @0x293330 cmp r6, #0
 *   @0x293334 cmpne r7, #0
 *   @0x293338 mov r3, #7
 *   @0x29333c str r3, [r8, #0xc]
 *   @0x293340 beq 0x29335c <Java_com_yoyogames_runner_RunnerJNILib_onItemPurchase+0xe4>
 *   @0x293344 ldr r3, [r5]
 *   @0x293348 mov r1, r7
 *   @0x29334c mov r2, r6
 *   @0x293350 mov r0, r5
 *   @0x293354 ldr r3, [r3, #0x2a8]
 *   @0x293358 blx r3
 *   @0x29335c add sp, sp, #16
 *   @0x293360 pop {r4, r5, r6, r7, r8, pc}
 *   @0x293364 andeq r4, r12, r0, lsl #29
 *   @0x293368 andseq r10, r5, r0, ror #12
 *   @0x29336c andeq r5, r12, r8, lsl lr
 *   @0x293370 andseq lr, r5, r8, asr r6
 *
 * ══ §93/119 png_write_iCCP  0x2b1890  size 252  63 条（0x2b1890..0x2b198c）
 * @func 0x2b1890 0x2b198c  size 252  63 条
 * 部分覆盖: 本节 63/114 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_warning / png_write_iCCP+0x74 / png_write_iCCP+0x96 / 0x2b0f3c / 0x370a00 / png_write_chunk_data / png_write_chunk_end / png_free
 * 字段偏移 top8: 0x26×1 / 0x4×1 / 0x1c×1 / 0x24×1 / 0x18×1 / 0x3×1 / 0x74×1 / 0x1×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b1890 push.w {r4, r5, r6, r7, r8, lr}
 *   @0x2b1894 mov r6, r3
 *   @0x2b1898 mov r4, r0
 *   @0x2b189c mov r8, r2
 *   @0x2b18a0 add r2, sp, #0x8
 *   @0x2b18a4 ldr r0, [r3, #38]!
 *   @0x2b18a8 ldrb r3, [r3, #0x4]
 *   @0x2b18ac mov r0, r4
 *   @0x2b18b0 movwhs r3, #0x10
 *   @0x2b18b4 str r3, [sp, #0x1c]
 *   @0x2b18b8 str r3, [sp, #0x24]
 *   @0x2b18bc str r3, [sp, #0x18]
 *   @0x2b18c0 .word 0x4607fe77
 *   @0x2b18c4 cmp r0, #0x0
 *   @0x2b18c8 cmp.w r8, #0x0
 *   @0x2b18cc beq 0x2b18d8 <png_write_iCCP+0x48>
 *   @0x2b18d0 mov r0, r4
 *   @0x2b18d4 bl 0x2a6474 <png_warning>
 *   @0x2b18d8 cbz r6, 0x2b1902 <png_write_iCCP+0x72>
 *   @0x2b18dc ble 0x2b1904 <png_write_iCCP+0x74>
 *   @0x2b18e0 ldmdavc r3!, {r0, pc}
 *   @0x2b18e4 lsl.w r8, r8, #0x10
 *   @0x2b18e8 orr.w r8, r8, r3, lsl #24
 *   @0x2b18ec ldrb r3, [r6, #0x3]
 *   @0x2b18f0 ldmvc r3!, {r0, r1, r11}
 *   @0x2b18f4 orrs.w r8, r8, r3, lsl #8
 *   @0x2b18f8 bpl 0x2b1908 <png_write_iCCP+0x78>
 *   @0x2b18fc mov r0, r4
 *   @0x2b1900 b 0x2b1912 <png_write_iCCP+0x82>
 *   @0x2b1904 mov.w r8, #0x0
 *   @0x2b1908 cmp r5, r8
 *   @0x2b190c ldr r1, [pc, #0x74]
 *   @0x2b1910 add r1, pc
 *   @0x2b1914 eor pc, r7, pc, lsr #27
 *   @0x2b1918 ble 0x2b1926 <png_write_iCCP+0x96>
 *   @0x2b191c mov r0, r4
 *   @0x2b1920 add r1, pc
 *   @0x2b1924 smlaltblt pc, r5, r7, sp
 *   @0x2b1928 add r3, sp, #0x14
 *   @0x2b192c str r3, [sp]
 *   @0x2b1930 mov r1, r6
 *   @0x2b1934 bl 0x2b0f3c <png_do_write_intrapixel+0x86>
 *   @0x2b1938 mov r5, r0
 *   @0x2b193c mov r0, r4
 *   @0x2b1940 adds r2, r5, r6
 *   @0x2b1944 blls 0x370a00 <_ZTS13C_UTF16String+0x7aac>
 *   @0x2b1948 mov r0, r4
 *   @0x2b194c add r7, r3
 *   @0x2b1950 strb r3, [r7, #0x1]
 *   @0x2b1954 bl 0x2b1204 <png_write_chunk_data>
 *   @0x2b1958 cbz r5, 0x2b1962 <png_write_iCCP+0xd2>
 *   @0x2b195c add r1, sp, #0x14
 *   @0x2b1960 strtmi pc, [r0], -r2, ror #24
 *   @0x2b1964 bl 0x2b1296 <png_write_chunk_end>
 *   @0x2b1968 mov r0, r4
 *   @0x2b196c bl 0x2a6cfc <png_free>
 *   @0x2b1970 add sp, #0x28
 *   @0x2b1974 svclt #0x81f0
 *   @0x2b1978 b 0x2b1300 <png_write_IHDR+0x1c>
 *   @0x2b197c ldm r2, {r0, r2, r3, r5, r6, r7}
 *   @0x2b1980 ldm r2!, {r3, r5, r6, r7}
 *   @0x2b1984 ldm r3, {r3}
 *   @0x2b1988 ldm r3, {r3, r5}
 *
 * ══ §94/119 png_write_start_row  0x2b2510  size 252  63 条（0x2b2510..0x2b260c）
 * @func 0x2b2510 0x2b260c  size 252  63 条
 * 部分覆盖: 本节 63/110 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_malloc×2 / anon_2bec94+0xcc
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b2510 push {r3, r4, r5, lr}
 *   @0x2b2514 ldrb.w r5, [r0, #0x1ef]
 *   @0x2b2518 ldrb.w r3, [r0, #0x1ec]
 *   @0x2b251c ldr.w r2, [r0, #0x18c]
 *   @0x2b2520 smulbb r3, r5, r3
 *   @0x2b2524 cmp r3, #0x7
 *   @0x2b2528 lsrs r5, r3, #0x3
 *   @0x2b252c b 0x2b2536 <png_write_start_row+0x26>
 *   @0x2b2530 strlo pc, [r7, #-0x503]
 *   @0x2b2534 lsrs r5, r5, #0x3
 *   @0x2b2538 mov r0, r4
 *   @0x2b253c bl 0x2a6ca0 <png_malloc>
 *   @0x2b2540 movs r3, #0x0
 *   @0x2b2544 strhvc r0, [r3], -r0
 *   @0x2b2548 ldrb.w r3, [r4, #0x1e9]
 *   @0x2b254c lsls r3, r3, #0x1b
 *   @0x2b2550 ldr.w r1, [r4, #0x19c]
 *   @0x2b2554 mov r0, r4
 *   @0x2b2558 bl 0x2a6ca0 <png_malloc>
 *   @0x2b255c movs r3, #0x1
 *   @0x2b2560 strhvc r0, [r3], -r4
 *   @0x2b2564 ldrb.w r3, [r4, #0x1e9]
 *   @0x2b2568 tst.w r3, #0xe0
 *   @0x2b256c beq 0x2b25ce <png_write_start_row+0xbe>
 *   @0x2b2570 mov r0, r4
 *   @0x2b2574 .word 0xf894fbb1
 *   @0x2b2578 ldreq r3, [sp], r9, ror #3
 *   @0x2b257c str.w r0, [r4, #0x1ac]
 *   @0x2b2580 bpl 0x2b2596 <png_write_start_row+0x86>
 *   @0x2b2584 qadd8mi r1, r0, r12
 *   @0x2b2588 adds r1, #0x1
 *   @0x2b258c movwhs pc, #0x2b89
 *   @0x2b2590 str.w r0, [r4, #0x1b8]
 *   @0x2b2594 strb r3, [r0]
 *   @0x2b2598 ldrbeq r3, [r8], -r9, ror #3
 *   @0x2b259c bpl 0x2b25b2 <png_write_start_row+0xa2>
 *   @0x2b25a0 qadd8mi r1, r0, r12
 *   @0x2b25a4 adds r1, #0x1
 *   @0x2b25a8 movwhs pc, #0x3b7b
 *   @0x2b25ac str.w r0, [r4, #0x1bc]
 *   @0x2b25b0 strb r3, [r0]
 *   @0x2b25b4 blhs 0x2bed60 <jpeg_huff_decode+0x1d4>
 *   @0x2b25b8 bge 0x2b25ce <png_write_start_row+0xbe>
 *   @0x2b25bc qadd8mi r1, r0, r12
 *   @0x2b25c0 adds r1, #0x1
 *   @0x2b25c4 movwhs pc, #0x4b6d
 *   @0x2b25c8 str.w r0, [r4, #0x1c0]
 *   @0x2b25cc strb r3, [r0]
 *   @0x2b25d0 .word 0xf8d411e7
 *   @0x2b25d4 .word 0xf8d4318c
 *   @0x2b25d8 .word 0xb1512190
 *   @0x2b25dc ldr.w r1, [r4, #0x134]
 *   @0x2b25e0 lsls r1, r1, #0x1e
 *   @0x2b25e4 adds r2, #0x7
 *   @0x2b25e8 lsrs r2, r2, #0x3
 *   @0x2b25ec str.w r2, [r4, #0x194]
 *   @0x2b25f0 b 0x2b25f6 <png_write_start_row+0xe6>
 *   @0x2b25f4 .word 0xf8c42194
 *   @0x2b25f8 .word 0xf8d43198
 *   @0x2b25fc .word 0xf8c43174
 *   @0x2b2600 .word 0xf8d43148
 *   @0x2b2604 .word 0xf8c43170
 *   @0x2b2608 ldclt p1, c3, [r8, #-272]!
 *
 * ══ §95/119 anon_31ba7c  0x31ba7c  size 252  63 条（0x31ba7c..0x31bb78）
 * @func 0x31ba7c 0x31bb78  size 252  63 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x31ba7c ldr r12, [pc, #0x4]
 *   @0x31ba80 add r12, pc, r12
 *   @0x31ba84 bx r12
 *   @0x31ba88 .word 0xfff88ce5
 *   @0x31ba8c ldr r12, [pc, #0x4]
 *   @0x31ba90 add r12, pc, r12
 *   @0x31ba94 bx r12
 *   @0x31ba98 .word 0xfff888f1
 *   @0x31ba9c uxtab16mi r4, r0, r8, ror #8
 *   @0x31baa0 ldr r12, [pc]
 *   @0x31baa4 add pc, r12, pc
 *   @0x31baa8 .word 0xffd9ac24
 *   @0x31baac uxtab16mi r4, r0, r8, ror #8
 *   @0x31bab0 ldr r12, [pc]
 *   @0x31bab4 add pc, r12, pc
 *   @0x31bab8 .word 0xffd9b430
 *   @0x31babc uxtab16mi r4, r0, r8, ror #8
 *   @0x31bac0 ldr r12, [pc]
 *   @0x31bac4 add pc, r12, pc
 *   @0x31bac8 .word 0xffd9aa90
 *   @0x31bacc uxtab16mi r4, r0, r8, ror #8
 *   @0x31bad0 ldr r12, [pc]
 *   @0x31bad4 add pc, r12, pc
 *   @0x31bad8 .word 0xffd9aad4
 *   @0x31badc uxtab16mi r4, r0, r8, ror #8
 *   @0x31bae0 ldr r12, [pc]
 *   @0x31bae4 add pc, r12, pc
 *   @0x31bae8 .word 0xffd9b454
 *   @0x31baec uxtab16mi r4, r0, r8, ror #8
 *   @0x31baf0 ldr r12, [pc]
 *   @0x31baf4 add pc, r12, pc
 *   @0x31baf8 .word 0xffd9adb4
 *   @0x31bafc uxtab16mi r4, r0, r8, ror #8
 *   @0x31bb00 ldr r12, [pc]
 *   @0x31bb04 add pc, r12, pc
 *   @0x31bb08 .word 0xffd9aa38
 *   @0x31bb0c uxtab16mi r4, r0, r8, ror #8
 *   @0x31bb10 ldr r12, [pc]
 *   @0x31bb14 add pc, r12, pc
 *   @0x31bb18 .word 0xffd9aaa0
 *   @0x31bb1c uxtab16mi r4, r0, r8, ror #8
 *   @0x31bb20 ldr r12, [pc]
 *   @0x31bb24 add pc, r12, pc
 *   @0x31bb28 .word 0xffd9adf0
 *   @0x31bb2c uxtab16mi r4, r0, r8, ror #8
 *   @0x31bb30 ldr r12, [pc]
 *   @0x31bb34 add pc, r12, pc
 *   @0x31bb38 .word 0xffd9ad8c
 *   @0x31bb3c uxtab16mi r4, r0, r8, ror #8
 *   @0x31bb40 ldr r12, [pc]
 *   @0x31bb44 add pc, r12, pc
 *   @0x31bb48 .word 0xffd9b0dc
 *   @0x31bb4c uxtab16mi r4, r0, r8, ror #8
 *   @0x31bb50 ldr r12, [pc]
 *   @0x31bb54 add pc, r12, pc
 *   @0x31bb58 .word 0xffd9ab14
 *   @0x31bb5c uxtab16mi r4, r0, r8, ror #8
 *   @0x31bb60 ldr r12, [pc]
 *   @0x31bb64 add pc, r12, pc
 *   @0x31bb68 .word 0xffd9b164
 *   @0x31bb6c uxtab16mi r4, r0, r8, ror #8
 *   @0x31bb70 ldr r12, [pc]
 *   @0x31bb74 add pc, r12, pc
 *
 * ══ §96/119 png_do_write_transformations  0x2b0dbc  size 250  63 条（0x2b0dbc..0x2b0eb6）
 * @func 0x2b0dbc 0x2b0eb8  size 252  63 条
 * 部分覆盖: 本节 63/107 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_do_strip_filler / png_do_pack / png_do_shift / png_do_write_invert_alpha
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b0dbc push {r4, lr}
 *   @0x2b0dc0 cmp r0, #0x0
 *   @0x2b0dc4 ldr.w r3, [r0, #0x134]
 *   @0x2b0dc8 lsls r2, r3, #0xb
 *   @0x2b0dcc ldr.w r3, [r0, #0x120]
 *   @0x2b0dd0 cbz r3, 0x2b0dde <png_do_write_transformations+0x22>
 *   @0x2b0dd4 .word 0xf50021b0
 *   @0x2b0dd8 andlo r7, r1, #-2147483592
 *   @0x2b0ddc blx r3
 *   @0x2b0de0 ldreq r3, [r11], #-308
 *   @0x2b0de4 bpl 0x2b0df8 <png_do_write_transformations+0x3c>
 *   @0x2b0de8 .word 0xf50411b0
 *   @0x2b0dec .word 0xf8d470e2
 *   @0x2b0df0 .word 0x31012130
 *   @0x2b0df4 bl 0x2af930 <png_do_strip_filler>
 *   @0x2b0df8 ldr.w r3, [r4, #0x134]
 *   @0x2b0dfc lsls r0, r3, #0xf
 *   @0x2b0e00 ldr.w r1, [r4, #0x1b0]
 *   @0x2b0e04 add.w r0, r4, #0x1c4
 *   @0x2b0e08 adds r1, #0x1
 *   @0x2b0e0c .word 0xf8d4fd6b
 *   @0x2b0e10 smmlareq r9, r4, r1, r3
 *   @0x2b0e14 bpl 0x2b0e28 <png_do_write_transformations+0x6c>
 *   @0x2b0e18 .word 0xf50411b0
 *   @0x2b0e1c .word 0xf89470e2
 *   @0x2b0e20 smlattlo r1, r11, r1, r2
 *   @0x2b0e24 bl 0x2b09fe <png_do_pack>
 *   @0x2b0e28 ldr.w r3, [r4, #0x134]
 *   @0x2b0e2c lsls r2, r3, #0x1b
 *   @0x2b0e30 ldr.w r1, [r4, #0x1b0]
 *   @0x2b0e34 add.w r0, r4, #0x1c4
 *   @0x2b0e38 adds r1, #0x1
 *   @0x2b0e3c .word 0xf8d4fd3c
 *   @0x2b0e40 .word 0x071b3134
 *   @0x2b0e44 bpl 0x2b0e58 <png_do_write_transformations+0x9c>
 *   @0x2b0e48 .word 0xf50411b0
 *   @0x2b0e4c .word 0xf20470e2
 *   @0x2b0e50 .word 0x31012245
 *   @0x2b0e54 bl 0x2b0ad4 <png_do_shift>
 *   @0x2b0e58 ldr.w r3, [r4, #0x134]
 *   @0x2b0e5c lsls r0, r3, #0xe
 *   @0x2b0e60 ldr.w r1, [r4, #0x1b0]
 *   @0x2b0e64 add.w r0, r4, #0x1c4
 *   @0x2b0e68 adds r1, #0x1
 *   @0x2b0e6c .word 0xf8d4fef5
 *   @0x2b0e70 tsteq r9, #52, #2
 *   @0x2b0e74 bpl 0x2b0e84 <png_do_write_transformations+0xc8>
 *   @0x2b0e78 .word 0xf50411b0
 *   @0x2b0e7c smlattlo r1, r2, r0, r7
 *   @0x2b0e80 bl 0x2b0d32 <png_do_write_invert_alpha>
 *   @0x2b0e84 ldr.w r3, [r4, #0x134]
 *   @0x2b0e88 lsls r2, r3, #0x1f
 *   @0x2b0e8c ldr.w r1, [r4, #0x1b0]
 *   @0x2b0e90 add.w r0, r4, #0x1c4
 *   @0x2b0e94 adds r1, #0x1
 *   @0x2b0e98 .word 0xf8d4fe27
 *   @0x2b0e9c .word 0x069b3134
 *   @0x2b0ea0 bpl 0x2b0eb4 <png_do_write_transformations+0xf8>
 *   @0x2b0ea4 .word 0xf50411b0
 *   @0x2b0ea8 pop {r1, r5, r6, r7, r12, sp, lr}
 *   @0x2b0eac .word 0x31014010
 *   @0x2b0eb0 b.w 0x2af85a <png_do_invert>
 *   @0x2b0eb4 pop {r4, pc}
 *
 * ══ §97/119 F_Vertex_Float3_release(RValue&, CInstance*, CInstance*, int, RValue*)  0xc8250  size 248  62 条（0xc8250..0xc8348）
 * @func 0xc8250 0xc835c  size 268  67 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×3 / YYGetInt32(RValue const*, int) / F_Vertex_Float3_release(RValue&, CInstance*, CInstance*, int, RValue*)+0xb8 / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0xc×4 / 0x4×3 / 0x18×2 / 0x14×2 / 0x10×2 / 0xe0×1 / 0x2×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc8250 push {r4, r5, r6, lr}
 *   @0xc8254 sub sp, sp, #8
 *   @0xc8258 ldr r3, [pc, #0xe0]
 *   @0xc825c mov r1, #0
 *   @0xc8260 ldr r5, [sp, #0x18]
 *   @0xc8264 add r3, pc, r3
 *   @0xc8268 mov r0, r5
 *   @0xc826c ldr r4, [r3]
 *   @0xc8270 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc8274 ldr r4, [r4, r0, lsl #2]
 *   @0xc8278 ldr r1, [r4, #0x2c]
 *   @0xc827c ldr r3, [r4, #0xc]
 *   @0xc8280 ldr r2, [r4, #0x4]
 *   @0xc8284 ldr r1, [r1, #0x14]
 *   @0xc8288 add r0, r1, r3
 *   @0xc828c cmp r2, r0
 *   @0xc8290 blo 0xc8308 <_Z23F_Vertex_Float3_releaseR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0xc8294 ldr r6, [r4]
 *   @0xc8298 mov r0, r5
 *   @0xc829c mov r1, #1
 *   @0xc82a0 add r6, r6, r3
 *   @0xc82a4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0xc82a8 mov r1, #2
 *   @0xc82ac str r0, [r6]
 *   @0xc82b0 mov r0, r5
 *   @0xc82b4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0xc82b8 mov r1, #3
 *   @0xc82bc str r0, [r6, #0x4]
 *   @0xc82c0 mov r0, r5
 *   @0xc82c4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0xc82c8 ldr r3, [r4, #0x10]
 *   @0xc82cc ldr r1, [r4, #0x14]
 *   @0xc82d0 add r3, r3, #1
 *   @0xc82d4 ldr r2, [r4, #0xc]
 *   @0xc82d8 cmp r3, r1
 *   @0xc82dc add r2, r2, #12
 *   @0xc82e0 str r0, [r6, #0x8]
 *   @0xc82e4 str r3, [r4, #0x10]
 *   @0xc82e8 ldrhs r3, [r4, #0x1c]
 *   @0xc82ec str r2, [r4, #0xc]
 *   @0xc82f0 movhs r2, #0
 *   @0xc82f4 addhs r3, r3, #1
 *   @0xc82f8 strhs r2, [r4, #0x10]
 *   @0xc82fc strhs r3, [r4, #0x1c]
 *   @0xc8300 add sp, sp, #8
 *   @0xc8304 pop {r4, r5, r6, pc}
 *   @0xc8308 add r1, r1, r2
 *   @0xc830c ldr r0, [r4]
 *   @0xc8310 add r1, r1, r2, lsr #1
 *   @0xc8314 mov r2, #0
 *   @0xc8318 str r1, [r4, #0x4]
 *   @0xc831c mov r3, #74
 *   @0xc8320 str r2, [sp]
 *   @0xc8324 ldr r2, [pc, #0x18]
 *   @0xc8328 add r2, pc, r2
 *   @0xc832c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0xc8330 ldr r3, [r4, #0xc]
 *   @0xc8334 mov r6, r0
 *   @0xc8338 str r0, [r4]
 *   @0xc833c b 0xc8298 <_Z23F_Vertex_Float3_releaseR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0xc8340 ldrsbteq r1, [r11], -r0
 *   @0xc8344 eoreq r8, r6, r8, lsl #26
 *
 * ══ §98/119 F_Vertex_Position_3d_release(RValue&, CInstance*, CInstance*, int, RValue*)  0xc8348  size 248  62 条（0xc8348..0xc8440）
 * @func 0xc8348 0xc8454  size 268  67 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×3 / YYGetInt32(RValue const*, int) / F_Vertex_Position_3d_release(RValue&, CInstance*, CInstance*, int, RValue*)+0xb8 / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0xc×4 / 0x4×3 / 0x18×2 / 0x14×2 / 0x10×2 / 0xe0×1 / 0x2×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc8348 push {r4, r5, r6, lr}
 *   @0xc834c sub sp, sp, #8
 *   @0xc8350 ldr r3, [pc, #0xe0]
 *   @0xc8354 mov r1, #0
 *   @0xc8358 ldr r5, [sp, #0x18]
 *   @0xc835c add r3, pc, r3
 *   @0xc8360 mov r0, r5
 *   @0xc8364 ldr r4, [r3]
 *   @0xc8368 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc836c ldr r4, [r4, r0, lsl #2]
 *   @0xc8370 ldr r1, [r4, #0x2c]
 *   @0xc8374 ldr r3, [r4, #0xc]
 *   @0xc8378 ldr r2, [r4, #0x4]
 *   @0xc837c ldr r1, [r1, #0x14]
 *   @0xc8380 add r0, r1, r3
 *   @0xc8384 cmp r2, r0
 *   @0xc8388 blo 0xc8400 <_Z28F_Vertex_Position_3d_releaseR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0xc838c ldr r6, [r4]
 *   @0xc8390 mov r0, r5
 *   @0xc8394 mov r1, #1
 *   @0xc8398 add r6, r6, r3
 *   @0xc839c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0xc83a0 mov r1, #2
 *   @0xc83a4 str r0, [r6]
 *   @0xc83a8 mov r0, r5
 *   @0xc83ac bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0xc83b0 mov r1, #3
 *   @0xc83b4 str r0, [r6, #0x4]
 *   @0xc83b8 mov r0, r5
 *   @0xc83bc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0xc83c0 ldr r3, [r4, #0x10]
 *   @0xc83c4 ldr r1, [r4, #0x14]
 *   @0xc83c8 add r3, r3, #1
 *   @0xc83cc ldr r2, [r4, #0xc]
 *   @0xc83d0 cmp r3, r1
 *   @0xc83d4 add r2, r2, #12
 *   @0xc83d8 str r0, [r6, #0x8]
 *   @0xc83dc str r3, [r4, #0x10]
 *   @0xc83e0 ldrhs r3, [r4, #0x1c]
 *   @0xc83e4 str r2, [r4, #0xc]
 *   @0xc83e8 movhs r2, #0
 *   @0xc83ec addhs r3, r3, #1
 *   @0xc83f0 strhs r2, [r4, #0x10]
 *   @0xc83f4 strhs r3, [r4, #0x1c]
 *   @0xc83f8 add sp, sp, #8
 *   @0xc83fc pop {r4, r5, r6, pc}
 *   @0xc8400 add r1, r1, r2
 *   @0xc8404 ldr r0, [r4]
 *   @0xc8408 add r1, r1, r2, lsr #1
 *   @0xc840c mov r2, #0
 *   @0xc8410 str r1, [r4, #0x4]
 *   @0xc8414 mov r3, #74
 *   @0xc8418 str r2, [sp]
 *   @0xc841c ldr r2, [pc, #0x18]
 *   @0xc8420 add r2, pc, r2
 *   @0xc8424 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0xc8428 ldr r3, [r4, #0xc]
 *   @0xc842c mov r6, r0
 *   @0xc8430 str r0, [r4]
 *   @0xc8434 b 0xc8390 <_Z28F_Vertex_Position_3d_releaseR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0xc8438 ldrsbteq r1, [r11], -r8
 *   @0xc843c eoreq r8, r6, r0, lsl r12
 *
 * ══ §99/119 F_DistanceToPoint(RValue&, CInstance*, CInstance*, int, RValue*)  0x1085a0  size 248  60 条（0x1085a0..0x108698）
 * @func 0x1085a0 0x108690  size 240  60 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×2 / CInstance::Compute_BoundingBox(bool) / 0xb66f4
 * 字段偏移 top8: 0x20×1 / 0x64×1 / 0xc×1
 * VFP 指令 35 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1085a0 push {r4, r5, r6, lr}
 *   @0x1085a4 vpush {d8, d9}
 *   @0x1085a8 mov r4, r1
 *   @0x1085ac ldr r6, [sp, #0x20]
 *   @0x1085b0 mov r5, r0
 *   @0x1085b4 mov r1, #0
 *   @0x1085b8 mov r0, r6
 *   @0x1085bc bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x1085c0 vmov d9, r0, r1
 *   @0x1085c4 mov r0, r6
 *   @0x1085c8 mov r1, #1
 *   @0x1085cc bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x1085d0 ldrb r3, [r4, #0x64]
 *   @0x1085d4 cmp r3, #0
 *   @0x1085d8 vmov d8, r0, r1
 *   @0x1085dc bne 0x10866c <_Z17F_DistanceToPointR6RValueP9CInstanceS2_iPS_+0xcc>
 *   @0x1085e0 vldr s14, [r4, #240]
 *   @0x1085e4 vcvt.f64.s32 d7, s14
 *   @0x1085e8 vldr s11, [r4, #232]
 *   @0x1085ec vldr s10, [r4, #236]
 *   @0x1085f0 mov r3, #0
 *   @0x1085f4 str r3, [r5, #0xc]
 *   @0x1085f8 vcvt.f64.s32 d6, s11
 *   @0x1085fc vldr s11, [r4, #244]
 *   @0x108600 vcmpe.f64 d9, d7
 *   @0x108604 vmrs APSR_nzcv, fpscr
 *   @0x108608 vcmpe.f64 d9, d6
 *   @0x10860c vldrle d7, [pc, #124]
 *   @0x108610 vsubgt.f64 d7, d9, d7
 *   @0x108614 vmrs APSR_nzcv, fpscr
 *   @0x108618 vsubmi.f64 d7, d9, d6
 *   @0x10861c vcvt.f64.s32 d6, s11
 *   @0x108620 vcvt.f64.s32 d5, s10
 *   @0x108624 vcmpe.f64 d8, d6
 *   @0x108628 vmrs APSR_nzcv, fpscr
 *   @0x10862c vcmpe.f64 d8, d5
 *   @0x108630 vldrle d6, [pc, #88]
 *   @0x108634 vsubgt.f64 d6, d8, d6
 *   @0x108638 vmrs APSR_nzcv, fpscr
 *   @0x10863c vsubmi.f64 d6, d8, d5
 *   @0x108640 vmul.f64 d6, d6, d6
 *   @0x108644 vmla.f64 d6, d7, d7
 *   @0x108648 vsqrt.f64 d7, d6
 *   @0x10864c vcmp.f64 d7, d7
 *   @0x108650 vmrs APSR_nzcv, fpscr
 *   @0x108654 bne 0x10867c <_Z17F_DistanceToPointR6RValueP9CInstanceS2_iPS_+0xdc>
 *   @0x108658 vmov r2, s14
 *   @0x10865c vmov r3, s15
 *   @0x108660 stm r5, {r2, r3}
 *   @0x108664 vpop {d8, d9}
 *   @0x108668 pop {r4, r5, r6, pc}
 *   @0x10866c mov r0, r4
 *   @0x108670 mov r1, #1
 *   @0x108674 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb>
 *   @0x108678 b 0x1085e0 <_Z17F_DistanceToPointR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x10867c vmov r0, r1, d6
 *   @0x108680 bl 0xb66f4 <sqrt@plt>
 *   @0x108684 vmov d7, r0, r1
 *   @0x108688 b 0x108658 <_Z17F_DistanceToPointR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0x10868c nop
 *
 * ══ §100/119 F_DateIncYear(RValue&, CInstance*, CInstance*, int, RValue*)  0x1156b0  size 248  62 条（0x1156b0..0x1157a8）
 * @func 0x1156b0 0x1157a8  size 248  62 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int) / __fixdfdi / 0xb6820 / YYGetInt32(RValue const*, int) / 0xb6814 / __floatdidf / 0x826454
 * 字段偏移 top8: 0x14×2 / 0x18×1 / 0xc×1 / 0x4×1
 * VFP 指令 21 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1156b0 push {r4, r5, r6, lr}
 *   @0x1156b4 sub sp, sp, #8
 *   @0x1156b8 mov r1, #0
 *   @0x1156bc mov r4, r0
 *   @0x1156c0 ldr r6, [sp, #0x18]
 *   @0x1156c4 str r1, [r0, #0xc]
 *   @0x1156c8 mov r0, r6
 *   @0x1156cc bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x1156d0 vldr d7, [pc, #184]
 *   @0x1156d4 vldr d5, [pc, #188]
 *   @0x1156d8 vmov d6, r0, r1
 *   @0x1156dc vsub.f64 d7, d6, d7
 *   @0x1156e0 vabs.f64 d4, d7
 *   @0x1156e4 vcmpe.f64 d4, d5
 *   @0x1156e8 vmrs APSR_nzcv, fpscr
 *   @0x1156ec vldrls d7, [pc, #172]
 *   @0x1156f0 vldrhi d6, [pc, #168]
 *   @0x1156f4 vmulls.f64 d4, d6, d7
 *   @0x1156f8 vmulhi.f64 d5, d7, d6
 *   @0x1156fc vmovls r0, r1, d4
 *   @0x115700 vmovhi r0, r1, d5
 *   @0x115704 bl 0x3194a0 <__fixdfdi>
 *   @0x115708 mov r2, r0
 *   @0x11570c add r0, sp, #8
 *   @0x115710 mov r3, r1
 *   @0x115714 strd r2, r3, [r0, #-8]!
 *   @0x115718 mov r0, sp
 *   @0x11571c bl 0xb6820 <gmtime64@plt>
 *   @0x115720 subs r5, r0, #0
 *   @0x115724 beq 0x115778 <_Z13F_DateIncYearR6RValueP9CInstanceS2_iPS_+0xc8>
 *   @0x115728 mov r0, r6
 *   @0x11572c mov r1, #1
 *   @0x115730 ldr r6, [r5, #0x14]
 *   @0x115734 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x115738 add r6, r6, r0
 *   @0x11573c mov r0, r5
 *   @0x115740 str r6, [r5, #0x14]
 *   @0x115744 bl 0xb6814 <timegm64@plt>
 *   @0x115748 bl 0x319164 <__floatdidf>
 *   @0x11574c vmov.f64 d6, #5.000000e-01
 *   @0x115750 vldr d5, [pc, #72]
 *   @0x115754 vldr d7, [pc, #52]
 *   @0x115758 vmov d4, r0, r1
 *   @0x11575c vadd.f64 d6, d4, d6
 *   @0x115760 vdiv.f64 d6, d6, d5
 *   @0x115764 vadd.f64 d5, d6, d7
 *   @0x115768 vmov r2, r3, d5
 *   @0x11576c stm r4, {r2, r3}
 *   @0x115770 add sp, sp, #8
 *   @0x115774 pop {r4, r5, r6, pc}
 *   @0x115778 str r5, [r4]
 *   @0x11577c mov r3, #0
 *   @0x115780 movt r3, #0xbff0
 *   @0x115784 str r3, [r4, #0x4]
 *   @0x115788 add sp, sp, #8
 *   @0x11578c pop {r4, r5, r6, pc}
 *   @0x115790 andeq r0, r0, r0
 *   @0x115794 sbcsmi pc, r8, r0, asr #16
 *   @0x115798 bl 0x826454 <b2_toiTime+0xccfb0>
 *   @0x11579c svclo #0x1a36e2
 *   @0x1157a0 andeq r0, r0, r0
 *   @0x1157a4 rscsmi r1, r5, r0, lsl #16
 *
 * ══ §101/119 F_D3DMatrixStackTop(RValue&, CInstance*, CInstance*, int, RValue*)  0x144980  size 248  62 条（0x144980..0x144a78）
 * @func 0x144980 0x144a78  size 248  62 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CreateArray(RValue*, int, ...)
 * 字段偏移 top8: 0xe8×1 / 0xe4×1 / 0x-4×1 / 0x4×1
 * VFP 指令 48 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x144980 ldr r2, [pc, #0xe8]
 *   @0x144984 mov r1, #16
 *   @0x144988 ldr r3, [pc, #0xe4]
 *   @0x14498c ldr r2, [pc, r2]
 *   @0x144990 ldr r3, [pc, r3]
 *   @0x144994 ldr r2, [r2]
 *   @0x144998 str lr, [sp, #-0x4]!
 *   @0x14499c sub sp, sp, #124
 *   @0x1449a0 add r3, r3, r2, lsl #6
 *   @0x1449a4 vldr s14, [r3, #4]
 *   @0x1449a8 vcvt.f64.f32 d7, s14
 *   @0x1449ac vldr s13, [r3]
 *   @0x1449b0 vstr d7, [sp]
 *   @0x1449b4 vldr s14, [r3, #8]
 *   @0x1449b8 vcvt.f64.f32 d7, s14
 *   @0x1449bc vstr d7, [sp, #8]
 *   @0x1449c0 vldr s14, [r3, #12]
 *   @0x1449c4 vcvt.f64.f32 d7, s14
 *   @0x1449c8 vstr d7, [sp, #16]
 *   @0x1449cc vldr s14, [r3, #16]
 *   @0x1449d0 vcvt.f64.f32 d7, s14
 *   @0x1449d4 vstr d7, [sp, #24]
 *   @0x1449d8 vldr s14, [r3, #20]
 *   @0x1449dc vcvt.f64.f32 d7, s14
 *   @0x1449e0 vstr d7, [sp, #32]
 *   @0x1449e4 vldr s14, [r3, #24]
 *   @0x1449e8 vcvt.f64.f32 d7, s14
 *   @0x1449ec vstr d7, [sp, #40]
 *   @0x1449f0 vldr s14, [r3, #28]
 *   @0x1449f4 vcvt.f64.f32 d7, s14
 *   @0x1449f8 vstr d7, [sp, #48]
 *   @0x1449fc vldr s14, [r3, #32]
 *   @0x144a00 vcvt.f64.f32 d7, s14
 *   @0x144a04 vstr d7, [sp, #56]
 *   @0x144a08 vldr s14, [r3, #36]
 *   @0x144a0c vcvt.f64.f32 d7, s14
 *   @0x144a10 vstr d7, [sp, #64]
 *   @0x144a14 vldr s14, [r3, #40]
 *   @0x144a18 vcvt.f64.f32 d7, s14
 *   @0x144a1c vstr d7, [sp, #72]
 *   @0x144a20 vldr s14, [r3, #44]
 *   @0x144a24 vcvt.f64.f32 d7, s14
 *   @0x144a28 vstr d7, [sp, #80]
 *   @0x144a2c vldr s14, [r3, #48]
 *   @0x144a30 vcvt.f64.f32 d7, s14
 *   @0x144a34 vstr d7, [sp, #88]
 *   @0x144a38 vldr s14, [r3, #52]
 *   @0x144a3c vcvt.f64.f32 d7, s14
 *   @0x144a40 vstr d7, [sp, #96]
 *   @0x144a44 vldr s14, [r3, #56]
 *   @0x144a48 vcvt.f64.f32 d7, s14
 *   @0x144a4c vcvt.f64.f32 d5, s13
 *   @0x144a50 vstr d7, [sp, #104]
 *   @0x144a54 vldr s14, [r3, #60]
 *   @0x144a58 vcvt.f64.f32 d7, s14
 *   @0x144a5c vmov r2, r3, d5
 *   @0x144a60 vstr d7, [sp, #112]
 *   @0x144a64 bl 0x120eb4 <_Z11CreateArrayP6RValueiz>
 *   @0x144a68 add sp, sp, #124
 *   @0x144a6c ldr pc, [sp], #4
 *   @0x144a70 eoreq r10, r10, r8, ror r12
 *   @0x144a74 eoreq r10, r10, r8, ror r12
 *
 * ══ §102/119 F_PhysicsFixtureSetEdgeShape(RValue&, CInstance*, CInstance*, int, RValue*)  0x14c3a4  size 248  62 条（0x14c3a4..0x14c49c）
 * @func 0x14c3a4 0x14c49c  size 248  62 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×4 / YYGetInt32(RValue const*, int) / CPhysicsFixtureFactory::FindFixture(unsigned int)
 * 字段偏移 top8: 0x20×1 / 0xc0×1 / 0xb4×1 / 0x24×1 / 0x10×1
 * VFP 指令 20 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14c3a4 push {r4, r5, r6, lr}
 *   @0x14c3a8 vpush {d8, d9}
 *   @0x14c3ac mov r1, #0
 *   @0x14c3b0 ldr r5, [sp, #0x20]
 *   @0x14c3b4 mov r0, r5
 *   @0x14c3b8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14c3bc bl 0x236404 <_ZN22CPhysicsFixtureFactory11FindFixtureEj>
 *   @0x14c3c0 subs r6, r0, #0
 *   @0x14c3c4 beq 0x14c478 <_Z28F_PhysicsFixtureSetEdgeShapeR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0x14c3c8 ldr r3, [pc, #0xc0]
 *   @0x14c3cc ldr r3, [pc, r3]
 *   @0x14c3d0 ldr r3, [r3]
 *   @0x14c3d4 ldr r4, [r3, #0xb4]
 *   @0x14c3d8 cmp r4, #0
 *   @0x14c3dc beq 0x14c460 <_Z28F_PhysicsFixtureSetEdgeShapeR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x14c3e0 mov r0, r5
 *   @0x14c3e4 mov r1, #1
 *   @0x14c3e8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14c3ec mov r1, #2
 *   @0x14c3f0 vldr s18, [r4, #96]
 *   @0x14c3f4 vmov s14, r0
 *   @0x14c3f8 mov r0, r5
 *   @0x14c3fc vmul.f32 s18, s14, s18
 *   @0x14c400 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14c404 mov r1, #3
 *   @0x14c408 vldr s17, [r4, #96]
 *   @0x14c40c vmov s15, r0
 *   @0x14c410 mov r0, r5
 *   @0x14c414 vmul.f32 s17, s15, s17
 *   @0x14c418 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14c41c mov r1, #4
 *   @0x14c420 vldr s16, [r4, #96]
 *   @0x14c424 vmov s14, r0
 *   @0x14c428 mov r0, r5
 *   @0x14c42c vmul.f32 s16, s14, s16
 *   @0x14c430 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14c434 vldr s15, [r4, #96]
 *   @0x14c438 vmov r1, s18
 *   @0x14c43c vmov r2, s17
 *   @0x14c440 vmov r3, s16
 *   @0x14c444 vmov s14, r0
 *   @0x14c448 mov r0, r6
 *   @0x14c44c vmul.f32 s15, s14, s15
 *   @0x14c450 vstr s15, [sp, #32]
 *   @0x14c454 vpop {d8, d9}
 *   @0x14c458 pop {r4, r5, r6, lr}
 *   @0x14c45c b 0x236848 <_ZN15CPhysicsFixture12SetEdgeShapeEffff>
 *   @0x14c460 vpop {d8, d9}
 *   @0x14c464 mov r1, r4
 *   @0x14c468 ldr r0, [pc, #0x24]
 *   @0x14c46c add r0, pc, r0
 *   @0x14c470 pop {r4, r5, r6, lr}
 *   @0x14c474 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14c478 vpop {d8, d9}
 *   @0x14c47c mov r1, r6
 *   @0x14c480 ldr r0, [pc, #0x10]
 *   @0x14c484 add r0, pc, r0
 *   @0x14c488 pop {r4, r5, r6, lr}
 *   @0x14c48c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14c490 eoreq r1, r10, r12, asr r5
 *   @0x14c494 ldrheq r7, [pc], -r8
 *   @0x14c498 andseq r7, pc, r4, lsr #18
 *
 * ══ §103/119 GR_3D_Projection_LookAt_Ext(float, float, float, float, float, float, float, float, float, float, float, float, float)  0x1632f0  size 248  62 条（0x1632f0..0x1633e8）
 * @func 0x1632f0 0x1633e8  size 248  62 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_3D_Projection_LookAt(float, float, float, float, float, float, float, float, float) / yyMatrix::PerspectiveFovLH(yyMatrix*, float, float, float, float) / Graphics::SetMatrix(eMatrix, float*) / DirtyRoomExtents()
 * 字段偏移 top8: 0x84×3 / 0x80×2 / 0xc8×1 / 0x78×1 / 0x94×1 / 0x98×1 / 0x7c×1 / 0x4×1
 * VFP 指令 13 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1632f0 push {r4, r5, r6, r7, r8, lr}
 *   @0x1632f4 vpush {d8}
 *   @0x1632f8 sub sp, sp, #88
 *   @0x1632fc vldr s17, [sp, #140]
 *   @0x163300 ldr r4, [pc, #0xc8]
 *   @0x163304 vldr s16, [sp, #144]
 *   @0x163308 ldr r12, [sp, #0x78]
 *   @0x16330c mov r5, #0
 *   @0x163310 ldr r6, [sp, #0x94]
 *   @0x163314 add r4, pc, r4
 *   @0x163318 ldr r8, [sp, #0x98]
 *   @0x16331c add r7, sp, #24
 *   @0x163320 str r12, [sp]
 *   @0x163324 ldr r12, [sp, #0x7c]
 *   @0x163328 str r12, [sp, #0x4]
 *   @0x16332c ldr r12, [sp, #0x80]
 *   @0x163330 str r12, [sp, #0x8]
 *   @0x163334 ldr r12, [sp, #0x84]
 *   @0x163338 str r12, [sp, #0xc]
 *   @0x16333c ldr r12, [sp, #0x88]
 *   @0x163340 str r12, [sp, #0x10]
 *   @0x163344 bl 0x163280 <_Z23GR_3D_Projection_LookAtfffffffff>
 *   @0x163348 ldr r3, [pc, #0x84]
 *   @0x16334c ldr r12, [pc, #0x84]
 *   @0x163350 vldr s15, [pc, #116]
 *   @0x163354 ldr r1, [pc, #0x80]
 *   @0x163358 vmul.f32 s17, s17, s15
 *   @0x16335c ldr lr, [r4, r3]
 *   @0x163360 mov r0, r7
 *   @0x163364 ldr r2, [pc, #0x74]
 *   @0x163368 mov r3, r6
 *   @0x16336c strb r5, [lr]
 *   @0x163370 ldr r12, [r4, r12]
 *   @0x163374 str r6, [r12]
 *   @0x163378 ldr r1, [r4, r1]
 *   @0x16337c str r8, [r1]
 *   @0x163380 ldr r2, [r4, r2]
 *   @0x163384 str r8, [sp]
 *   @0x163388 vldr s15, [r2]
 *   @0x16338c vcvt.f32.s32 s15, s15
 *   @0x163390 vmul.f32 s17, s17, s15
 *   @0x163394 vmul.f32 s16, s15, s16
 *   @0x163398 vmov r1, s17
 *   @0x16339c vmov r2, s16
 *   @0x1633a0 bl 0x27b068 <_ZN8yyMatrix16PerspectiveFovLHEPS_ffff>
 *   @0x1633a4 mov r1, r7
 *   @0x1633a8 mov r0, #1
 *   @0x1633ac bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf>
 *   @0x1633b0 bl 0x168d7c <_Z16DirtyRoomExtentsv>
 *   @0x1633b4 ldr r3, [pc, #0x28]
 *   @0x1633b8 ldr r3, [r4, r3]
 *   @0x1633bc strb r5, [r3]
 *   @0x1633c0 add sp, sp, #88
 *   @0x1633c4 vpop {d8}
 *   @0x1633c8 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1633cc vstmialo lr, {s30, s31}
 *   @0x1633d0 eoreq lr, r8, r12, lsr r9
 *   @0x1633d4 .word 0xffffe480
 *   @0x1633d8 .word 0xffffe484
 *   @0x1633dc .word 0xffffe488
 *   @0x1633e0 .word 0xffffe48c
 *   @0x1633e4 .word 0xffffe490
 *
 * ══ §104/119 GMGamePad::SetConnected(bool)  0x18e7f4  size 248  62 条（0x18e7f4..0x18e8ec）
 * @func 0x18e7f4 0x18e8ec  size 248  62 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GMGamePad::SetConnected(bool)+0x5c / CreateDsMap(int, ...) / CreateAsynEventWithDSMap(int, int)
 * 字段偏移 top8: 0x4×2 / 0xbc×1 / 0xac×1 / 0x80×1 / 0x74×1 / 0x70×1 / 0x10×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18e7f4 ldrb r3, [r0]
 *   @0x18e7f8 push {r4, lr}
 *   @0x18e7fc cmp r3, r1
 *   @0x18e800 sub sp, sp, #24
 *   @0x18e804 mov r4, r0
 *   @0x18e808 strb r1, [r0]
 *   @0x18e80c beq 0x18e8a8 <_ZN9GMGamePad12SetConnectedEb+0xb4>
 *   @0x18e810 ldr r3, [pc, #0xbc]
 *   @0x18e814 ldr r3, [pc, r3]
 *   @0x18e818 ldr r0, [r3]
 *   @0x18e81c cmp r0, #0
 *   @0x18e820 ble 0x18e850 <_ZN9GMGamePad12SetConnectedEb+0x5c>
 *   @0x18e824 ldr r2, [pc, #0xac]
 *   @0x18e828 mov r3, #0
 *   @0x18e82c ldr r2, [pc, r2]
 *   @0x18e830 ldr r2, [r2]
 *   @0x18e834 sub r2, r2, #4
 *   @0x18e838 ldr r12, [r2, #0x4]!
 *   @0x18e83c cmp r12, r4
 *   @0x18e840 beq 0x18e8c8 <_ZN9GMGamePad12SetConnectedEb+0xd4>
 *   @0x18e844 add r3, r3, #1
 *   @0x18e848 cmp r3, r0
 *   @0x18e84c bne 0x18e838 <_ZN9GMGamePad12SetConnectedEb+0x44>
 *   @0x18e850 vmov.f64 d7, #-1.000000e+00
 *   @0x18e854 ldr r2, [pc, #0x80]
 *   @0x18e858 cmp r1, #0
 *   @0x18e85c add r2, pc, r2
 *   @0x18e860 ldrne r2, [pc, #0x78]
 *   @0x18e864 addne r2, pc, r2
 *   @0x18e868 ldr r3, [pc, #0x74]
 *   @0x18e86c vstr d7, [sp, #8]
 *   @0x18e870 ldr r1, [pc, #0x70]
 *   @0x18e874 mov r0, #2
 *   @0x18e878 add r3, pc, r3
 *   @0x18e87c str r2, [sp]
 *   @0x18e880 str r3, [sp, #0x4]
 *   @0x18e884 mov r2, #0
 *   @0x18e888 mov r3, #0
 *   @0x18e88c str r2, [sp, #0x10]
 *   @0x18e890 add r1, pc, r1
 *   @0x18e894 mov r2, #0
 *   @0x18e898 bl 0x20bdc0 <_Z11CreateDsMapiz>
 *   @0x18e89c mov r1, #75
 *   @0x18e8a0 bl 0x18da04 <_Z24CreateAsynEventWithDSMapii>
 *   @0x18e8a4 ldrb r3, [r4]
 *   @0x18e8a8 cmp r3, #0
 *   @0x18e8ac beq 0x18e8b8 <_ZN9GMGamePad12SetConnectedEb+0xc4>
 *   @0x18e8b0 add sp, sp, #24
 *   @0x18e8b4 pop {r4, pc}
 *   @0x18e8b8 mov r0, r4
 *   @0x18e8bc add sp, sp, #24
 *   @0x18e8c0 pop {r4, lr}
 *   @0x18e8c4 b 0x18e778 <_ZN9GMGamePad5ClearEv>
 *   @0x18e8c8 vmov s13, r3
 *   @0x18e8cc vcvt.f64.s32 d7, s13
 *   @0x18e8d0 b 0x18e854 <_ZN9GMGamePad12SetConnectedEb+0x60>
 *   @0x18e8d4 eoreq r1, r6, r12, asr #4
 *   @0x18e8d8 eoreq r1, r6, r8, lsr r2
 *   @0x18e8dc andseq sp, r11, r4, asr r11
 *   @0x18e8e0 andseq sp, r11, r12, lsr #22
 *   @0x18e8e4 andseq sp, r11, r12, lsr #22
 *   @0x18e8e8 ldrsheq sp, [r11], -r4
 *
 * ══ §105/119 ParticleType_Create()  0x1a3068  size 248  62 条（0x1a3068..0x1a3160）
 * @func 0x1a3068 0x1a3160  size 248  62 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1a3070→0x542468, 0x1a307c→0x54246c
 * 调用序列: ParticleType_Create()+0xc4 / MemoryManager::SetLength(void**, unsigned int, char const*, int) / MemoryManager::Alloc(unsigned int, char const*, int, bool) / ParticleType_Clear(int)
 * 字段偏移 top8: 0xd8×2 / 0x4×2 / 0xd0×1 / 0x7c×1 / 0x54×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a3068 push {r3, r4, r5, r6, r7, lr}
 *   @0x1a306c ldr r3, [pc, #0xd8]
 *   @0x1a3070 ldr r2, [pc, #0xd8]
 *   @0x1a3074 add r3, pc, r3
 *   @0x1a3078 ldr r7, [r3, r2]
 *   @0x1a307c ldr r2, [pc, #0xd0]
 *   @0x1a3080 ldr r1, [r7]
 *   @0x1a3084 cmp r1, #0
 *   @0x1a3088 ble 0x1a312c <_Z19ParticleType_Createv+0xc4>
 *   @0x1a308c ldr r6, [r3, r2]
 *   @0x1a3090 ldr r5, [r6, #0x4]
 *   @0x1a3094 ldr r4, [r5]
 *   @0x1a3098 cmp r4, #0
 *   @0x1a309c beq 0x1a3100 <_Z19ParticleType_Createv+0x98>
 *   @0x1a30a0 add r3, r5, #4
 *   @0x1a30a4 mov r4, #0
 *   @0x1a30a8 b 0x1a30b8 <_Z19ParticleType_Createv+0x50>
 *   @0x1a30ac ldr r2, [r5]
 *   @0x1a30b0 cmp r2, #0
 *   @0x1a30b4 beq 0x1a3100 <_Z19ParticleType_Createv+0x98>
 *   @0x1a30b8 add r4, r4, #1
 *   @0x1a30bc mov r5, r3
 *   @0x1a30c0 cmp r4, r1
 *   @0x1a30c4 add r3, r3, #4
 *   @0x1a30c8 bne 0x1a30ac <_Z19ParticleType_Createv+0x44>
 *   @0x1a30cc lsl r5, r4, #2
 *   @0x1a30d0 add r12, r4, #1
 *   @0x1a30d4 ldr r2, [pc, #0x7c]
 *   @0x1a30d8 movw r3, #0x1b5
 *   @0x1a30dc add r0, r6, #4
 *   @0x1a30e0 add r2, pc, r2
 *   @0x1a30e4 lsl r1, r12, #2
 *   @0x1a30e8 str r12, [r7]
 *   @0x1a30ec bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1a30f0 ldr r2, [r6, #0x4]
 *   @0x1a30f4 ldr r3, [r7]
 *   @0x1a30f8 add r5, r2, r5
 *   @0x1a30fc str r3, [r6]
 *   @0x1a3100 ldr r1, [pc, #0x54]
 *   @0x1a3104 movw r2, #0x1b9
 *   @0x1a3108 mov r3, #1
 *   @0x1a310c mov r0, #164
 *   @0x1a3110 add r1, pc, r1
 *   @0x1a3114 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1a3118 str r0, [r5]
 *   @0x1a311c mov r0, r4
 *   @0x1a3120 bl 0x1a2f7c <_Z18ParticleType_Cleari>
 *   @0x1a3124 mov r0, r4
 *   @0x1a3128 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1a312c ldrne r3, [r3, r2]
 *   @0x1a3130 movne r4, #0
 *   @0x1a3134 ldrne r5, [r3, #0x4]
 *   @0x1a3138 bne 0x1a3100 <_Z19ParticleType_Createv+0x98>
 *   @0x1a313c mov r5, r1
 *   @0x1a3140 mov r4, r1
 *   @0x1a3144 ldr r6, [r3, r2]
 *   @0x1a3148 b 0x1a30d0 <_Z19ParticleType_Createv+0x68>
 *   @0x1a314c .word 0x0024ebdc
 *   @0x1a3150 .word 0xffffeb60
 *   @0x1a3154 .word 0xffffeb5c
 *   @0x1a3158 andseq r9, r10, r0, lsr #29
 *   @0x1a315c andseq r9, r10, r0, ror lr
 *
 * ══ §106/119 F_LayerGetElementLayer(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bf2dc  size 248  62 条（0x1bf2dc..0x1bf3d4）
 * @func 0x1bf2dc 0x1bf3d4  size 248  62 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**)
 * 字段偏移 top8: 0xc×2 / 0x10×2 / 0x44×2 / 0xd0×1 / 0x4×1 / 0x18×1 / 0xa8×1 / 0x28×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bf2dc push {r4, r5, r6, r7, r8, lr}
 *   @0x1bf2e0 cmp r3, #1
 *   @0x1bf2e4 ldr r6, [pc, #0xd0]
 *   @0x1bf2e8 mov r3, #0
 *   @0x1bf2ec mov r5, r3
 *   @0x1bf2f0 mov r4, r0
 *   @0x1bf2f4 movt r3, #0xbff0
 *   @0x1bf2f8 add r6, pc, r6
 *   @0x1bf2fc str r5, [r0, #0xc]
 *   @0x1bf300 str r3, [r0, #0x4]
 *   @0x1bf304 str r5, [r0]
 *   @0x1bf308 ldr r7, [sp, #0x18]
 *   @0x1bf30c beq 0x1bf324 <_Z22F_LayerGetElementLayerR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x1bf310 ldr r0, [pc, #0xa8]
 *   @0x1bf314 mov r1, r5
 *   @0x1bf318 pop {r4, r5, r6, r7, r8, lr}
 *   @0x1bf31c add r0, pc, r0
 *   @0x1bf320 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bf324 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bf328 subs r8, r0, #0
 *   @0x1bf32c beq 0x1bf378 <_Z22F_LayerGetElementLayerR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x1bf330 mov r1, r5
 *   @0x1bf334 mov r0, r7
 *   @0x1bf338 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bf33c mov r2, r5
 *   @0x1bf340 mov r1, r0
 *   @0x1bf344 mov r0, r8
 *   @0x1bf348 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bf34c cmp r0, #0
 *   @0x1bf350 beq 0x1bf3ac <_Z22F_LayerGetElementLayerR6RValueP9CInstanceS2_iPS_+0xd0>
 *   @0x1bf354 ldr r3, [r0, #0x10]
 *   @0x1bf358 cmp r3, #0
 *   @0x1bf35c beq 0x1bf39c <_Z22F_LayerGetElementLayerR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x1bf360 ldr r2, [r3]
 *   @0x1bf364 vmov s15, r2
 *   @0x1bf368 vcvt.f64.s32 d7, s15
 *   @0x1bf36c vmov r2, r3, d7
 *   @0x1bf370 stm r4, {r2, r3}
 *   @0x1bf374 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1bf378 ldr r1, [pc, #0x44]
 *   @0x1bf37c ldr r3, [pc, #0x44]
 *   @0x1bf380 add r1, pc, r1
 *   @0x1bf384 ldr r3, [r6, r3]
 *   @0x1bf388 ldr r0, [r3]
 *   @0x1bf38c ldr r3, [r0]
 *   @0x1bf390 ldr r3, [r3, #0xc]
 *   @0x1bf394 blx r3
 *   @0x1bf398 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1bf39c ldr r1, [pc, #0x28]
 *   @0x1bf3a0 ldr r3, [pc, #0x20]
 *   @0x1bf3a4 add r1, pc, r1
 *   @0x1bf3a8 b 0x1bf384 <_Z22F_LayerGetElementLayerR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0x1bf3ac ldr r1, [pc, #0x1c]
 *   @0x1bf3b0 ldr r3, [pc, #0x10]
 *   @0x1bf3b4 add r1, pc, r1
 *   @0x1bf3b8 b 0x1bf384 <_Z22F_LayerGetElementLayerR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0x1bf3bc eoreq r2, r3, r8, asr r9
 *   @0x1bf3c0 andseq pc, r8, r0, lsl #28
 *   @0x1bf3c4 andseq pc, r8, r0, asr lr
 *   @0x1bf3c8 .word 0xffffbac4
 *   @0x1bf3cc ldrheq pc, [r8], -r0
 *   @0x1bf3d0 andseq pc, r8, r0, ror #27
 *
 * ══ §107/119 F_LayerTilemapExists(RValue&, CInstance*, CInstance*, int, RValue*)  0x1c09d0  size 248  62 条（0x1c09d0..0x1c0ac8）
 * @func 0x1c09d0 0x1c0ac8  size 248  62 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / CLayerManager::GetTargetRoomObj() / CLayerManager::GetLayerFromID(CRoom*, int) / CLayerManager::GetElementFromID(CLayer*, int) / YYGetString(RValue const*, int) / CLayerManager::GetLayerFromName(CRoom*, char const*)
 * 字段偏移 top8: 0xc×3 / 0x20×2 / 0x18×1 / 0x4×1 / 0xc0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1c09d0 cmp r3, #2
 *   @0x1c09d4 push {r3, r4, r5, r6, r7, lr}
 *   @0x1c09d8 mov r4, #0
 *   @0x1c09dc mov r5, r0
 *   @0x1c09e0 ldr r6, [sp, #0x18]
 *   @0x1c09e4 str r4, [r0, #0xc]
 *   @0x1c09e8 str r4, [r0]
 *   @0x1c09ec str r4, [r0, #0x4]
 *   @0x1c09f0 beq 0x1c0a08 <_Z20F_LayerTilemapExistsR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x1c09f4 ldr r0, [pc, #0xc0]
 *   @0x1c09f8 mov r1, r4
 *   @0x1c09fc pop {r3, r4, r5, r6, r7, lr}
 *   @0x1c0a00 add r0, pc, r0
 *   @0x1c0a04 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1c0a08 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1c0a0c ldr r3, [r6, #0xc]
 *   @0x1c0a10 mov r1, r4
 *   @0x1c0a14 bic r3, r3, #-16777216
 *   @0x1c0a18 cmp r3, #1
 *   @0x1c0a1c mov r7, r0
 *   @0x1c0a20 mov r0, r6
 *   @0x1c0a24 beq 0x1c0a80 <_Z20F_LayerTilemapExistsR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0x1c0a28 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1c0a2c mov r1, r0
 *   @0x1c0a30 mov r0, r7
 *   @0x1c0a34 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1c0a38 mov r4, r0
 *   @0x1c0a3c cmp r4, #0
 *   @0x1c0a40 beq 0x1c0a98 <_Z20F_LayerTilemapExistsR6RValueP9CInstanceS2_iPS_+0xc8>
 *   @0x1c0a44 mov r1, #1
 *   @0x1c0a48 mov r0, r6
 *   @0x1c0a4c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1c0a50 mov r1, r0
 *   @0x1c0a54 mov r0, r4
 *   @0x1c0a58 bl 0x1c07e4 <_ZN13CLayerManager16GetElementFromIDEP6CLayeri>
 *   @0x1c0a5c cmp r0, #0
 *   @0x1c0a60 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1c0a64 ldr r3, [r0]
 *   @0x1c0a68 cmp r3, #5
 *   @0x1c0a6c moveq r3, #0
 *   @0x1c0a70 moveq r2, r3
 *   @0x1c0a74 movteq r3, #0x3ff0
 *   @0x1c0a78 stmeq r5, {r2, r3}
 *   @0x1c0a7c pop {r3, r4, r5, r6, r7, pc}
 *   @0x1c0a80 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1c0a84 mov r1, r0
 *   @0x1c0a88 mov r0, r7
 *   @0x1c0a8c bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc>
 *   @0x1c0a90 mov r4, r0
 *   @0x1c0a94 b 0x1c0a3c <_Z20F_LayerTilemapExistsR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x1c0a98 ldr r3, [pc, #0x20]
 *   @0x1c0a9c ldr r1, [pc, #0x20]
 *   @0x1c0aa0 ldr r3, [pc, r3]
 *   @0x1c0aa4 add r1, pc, r1
 *   @0x1c0aa8 ldr r0, [r3]
 *   @0x1c0aac ldr r3, [r0]
 *   @0x1c0ab0 ldr r3, [r3, #0xc]
 *   @0x1c0ab4 blx r3
 *   @0x1c0ab8 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1c0abc andseq lr, r8, r8, asr #31
 *   @0x1c0ac0 eoreq r12, r2, r4, ror r12
 *   @0x1c0ac4 andseq lr, r8, r8, asr pc
 *
 * ══ §108/119 CSprite::GetBoundingBoxImg(int)  0x1e63d4  size 248  62 条（0x1e63d4..0x1e64cc）
 * @func 0x1e63d4 0x1e64cc  size 248  62 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int) / 0xb65b0 / CSprite::GetBoundingBoxImg(int)+0x84 / operator delete(void*)
 * 字段偏移 top8: 0x4×2 / 0x8×2 / 0xc×2 / 0x2×2 / 0x18×1 / 0x54×1 / 0x74×1 / 0x48×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e63d4 push {r4, r5, r6, lr}
 *   @0x1e63d8 mov r6, r0
 *   @0x1e63dc mov r0, #16
 *   @0x1e63e0 mov r5, r1
 *   @0x1e63e4 bl 0x27c524 <_Znwj>
 *   @0x1e63e8 mov r3, #0
 *   @0x1e63ec mov r2, #16
 *   @0x1e63f0 mov r1, r3
 *   @0x1e63f4 str r3, [r0]
 *   @0x1e63f8 mov r4, r0
 *   @0x1e63fc str r3, [r0, #0x4]
 *   @0x1e6400 str r3, [r0, #0x8]
 *   @0x1e6404 str r3, [r0, #0xc]
 *   @0x1e6408 bl 0xb65b0 <memset@plt>
 *   @0x1e640c cmp r5, #0
 *   @0x1e6410 blt 0x1e6458 <_ZN7CSprite17GetBoundingBoxImgEi+0x84>
 *   @0x1e6414 ldr r3, [r6, #0x18]
 *   @0x1e6418 cmp r5, r3
 *   @0x1e641c bge 0x1e6458 <_ZN7CSprite17GetBoundingBoxImgEi+0x84>
 *   @0x1e6420 ldr r3, [r6, #0x54]
 *   @0x1e6424 cmp r3, #0
 *   @0x1e6428 beq 0x1e6460 <_ZN7CSprite17GetBoundingBoxImgEi+0x8c>
 *   @0x1e642c ldr r3, [r3, r5, lsl #2]
 *   @0x1e6430 ldrsh r1, [r3, #8]
 *   @0x1e6434 ldrsh r2, [r3, #10]
 *   @0x1e6438 ldrsh r0, [r3, #4]
 *   @0x1e643c ldrsh r3, [r3, #6]
 *   @0x1e6440 str r1, [r4]
 *   @0x1e6444 add r1, r1, r0
 *   @0x1e6448 add r3, r2, r3
 *   @0x1e644c str r1, [r4, #0x8]
 *   @0x1e6450 str r3, [r4, #0xc]
 *   @0x1e6454 str r2, [r4, #0x4]
 *   @0x1e6458 mov r0, r4
 *   @0x1e645c pop {r4, r5, r6, pc}
 *   @0x1e6460 ldr r3, [r6, #0x74]
 *   @0x1e6464 cmp r3, #1
 *   @0x1e6468 beq 0x1e6484 <_ZN7CSprite17GetBoundingBoxImgEi+0xb0>
 *   @0x1e646c mov r0, r4
 *   @0x1e6470 bl 0x27d1d0 <_ZdlPv>
 *   @0x1e6474 ldr r3, [r6, #0x48]
 *   @0x1e6478 ldr r0, [r3, r5, lsl #2]
 *   @0x1e647c pop {r4, r5, r6, lr}
 *   @0x1e6480 b 0x167508 <_ZN9CBitmap3211BoundingBoxEv>
 *   @0x1e6484 ldr r3, [r6, #0x84]
 *   @0x1e6488 add r5, r5, r5, lsl #1
 *   @0x1e648c ldr r3, [r3]
 *   @0x1e6490 add r5, r3, r5, lsl #3
 *   @0x1e6494 vldr s15, [r5, #4]
 *   @0x1e6498 vcvt.s32.f32 s15, s15
 *   @0x1e649c vldr s13, [r5, #8]
 *   @0x1e64a0 vldr s14, [r5, #12]
 *   @0x1e64a4 vmov r3, s15
 *   @0x1e64a8 vldr s15, [r5, #16]
 *   @0x1e64ac vcvt.s32.f32 s13, s13
 *   @0x1e64b0 vcvt.s32.f32 s14, s14
 *   @0x1e64b4 vstr s13, [r4, #8]
 *   @0x1e64b8 vcvt.s32.f32 s15, s15
 *   @0x1e64bc vstr s14, [r4, #4]
 *   @0x1e64c0 str r3, [r4]
 *   @0x1e64c4 vstr s15, [r4, #12]
 *   @0x1e64c8 b 0x1e6458 <_ZN7CSprite17GetBoundingBoxImgEi+0x84>
 *
 * ══ §109/119 CVariableList::Remove(RVariable*)  0x1f625c  size 248  62 条（0x1f625c..0x1f6354）
 * @func 0x1f625c 0x1f6354  size 248  62 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FREE_RValue__Pre(RValue*)×2
 * 字段偏移 top8: 0x4×3 / 0x14×2 / 0x24×2 / 0x28×1 / 0xa4×1 / 0x10×1 / 0x8×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f625c ldr r3, [r1, #0x28]
 *   @0x1f6260 push {r4, lr}
 *   @0x1f6264 and r3, r3, #3
 *   @0x1f6268 mov r4, r1
 *   @0x1f626c add r0, r0, r3, lsl #2
 *   @0x1f6270 ldr r2, [r0, #0x4]
 *   @0x1f6274 cmp r1, r2
 *   @0x1f6278 cmpne r2, #0
 *   @0x1f627c bne 0x1f6288 <_ZN13CVariableList6RemoveEP9RVariable+0x2c>
 *   @0x1f6280 b 0x1f6344 <_ZN13CVariableList6RemoveEP9RVariable+0xe8>
 *   @0x1f6284 mov r2, r3
 *   @0x1f6288 add r3, r2, #44
 *   @0x1f628c cmp r4, r3
 *   @0x1f6290 cmpne r3, #0
 *   @0x1f6294 bne 0x1f6284 <_ZN13CVariableList6RemoveEP9RVariable+0x28>
 *   @0x1f6298 cmp r4, r3
 *   @0x1f629c beq 0x1f6324 <_ZN13CVariableList6RemoveEP9RVariable+0xc8>
 *   @0x1f62a0 ldr r1, [r4, #0x14]
 *   @0x1f62a4 ldr r3, [pc, #0xa4]
 *   @0x1f62a8 sub r1, r1, #1
 *   @0x1f62ac ldr r3, [pc, r3]
 *   @0x1f62b0 bic r1, r1, #-16777216
 *   @0x1f62b4 bic r1, r1, #3
 *   @0x1f62b8 ldr r2, [r3]
 *   @0x1f62bc cmp r1, #0
 *   @0x1f62c0 str r4, [r3]
 *   @0x1f62c4 str r2, [r4, #0x4]
 *   @0x1f62c8 beq 0x1f6318 <_ZN13CVariableList6RemoveEP9RVariable+0xbc>
 *   @0x1f62cc ldr r1, [r4, #0x24]
 *   @0x1f62d0 mov r3, #0
 *   @0x1f62d4 str r3, [r4, #0x10]
 *   @0x1f62d8 mov r2, #5
 *   @0x1f62dc sub r1, r1, #1
 *   @0x1f62e0 str r3, [r4, #0x8]
 *   @0x1f62e4 bic r3, r1, #-16777216
 *   @0x1f62e8 str r2, [r4, #0x14]
 *   @0x1f62ec bic r3, r3, #3
 *   @0x1f62f0 cmp r3, #0
 *   @0x1f62f4 bne 0x1f6300 <_ZN13CVariableList6RemoveEP9RVariable+0xa4>
 *   @0x1f62f8 add r0, r4, #24
 *   @0x1f62fc bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x1f6300 mov r3, #0
 *   @0x1f6304 mov r2, #5
 *   @0x1f6308 str r3, [r4, #0x20]
 *   @0x1f630c str r3, [r4, #0x18]
 *   @0x1f6310 str r2, [r4, #0x24]
 *   @0x1f6314 pop {r4, pc}
 *   @0x1f6318 add r0, r4, #8
 *   @0x1f631c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x1f6320 b 0x1f62cc <_ZN13CVariableList6RemoveEP9RVariable+0x70>
 *   @0x1f6324 cmp r2, #0
 *   @0x1f6328 ldrne r3, [r4]
 *   @0x1f632c strne r3, [r2]
 *   @0x1f6330 bne 0x1f62a0 <_ZN13CVariableList6RemoveEP9RVariable+0x44>
 *   @0x1f6334 mov r2, r4
 *   @0x1f6338 ldr r3, [r2]
 *   @0x1f633c str r3, [r0, #0x4]
 *   @0x1f6340 b 0x1f62a0 <_ZN13CVariableList6RemoveEP9RVariable+0x44>
 *   @0x1f6344 cmp r1, r2
 *   @0x1f6348 bne 0x1f62a0 <_ZN13CVariableList6RemoveEP9RVariable+0x44>
 *   @0x1f634c b 0x1f6338 <_ZN13CVariableList6RemoveEP9RVariable+0xdc>
 *   @0x1f6350 andseq r10, pc, r8, lsl #23
 *
 * ══ §110/119 CStream::ReadInteger64()  0x201784  size 248  62 条（0x201784..0x20187c）
 * @func 0x201784 0x20187c  size 248  62 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::ReadInteger64()+0xec
 * 字段偏移 top8: 0x8×2 / 0x18×1 / 0x1×1 / 0x2×1 / 0x3×1 / 0x4×1 / 0x5×1 / 0x6×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x201784 push {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x201788 sub sp, sp, #24
 *   @0x20178c ldrd r4, r5, [r0, #16]
 *   @0x201790 ldr r3, [r0, #0x8]
 *   @0x201794 ldr r12, [r0, #0x18]
 *   @0x201798 cmp r3, r4
 *   @0x20179c movle r0, #0
 *   @0x2017a0 movle r1, #0
 *   @0x2017a4 ble 0x201870 <_ZN7CStream13ReadInteger64Ev+0xec>
 *   @0x2017a8 add r1, r12, r4
 *   @0x2017ac mov r7, #0
 *   @0x2017b0 ldrb r2, [r1, #0x1]
 *   @0x2017b4 ldrb r10, [r1, #0x2]
 *   @0x2017b8 ldrb r6, [r1, #0x3]
 *   @0x2017bc lsl r8, r2, #8
 *   @0x2017c0 lsr r9, r2, #24
 *   @0x2017c4 ldrb r3, [r1, #0x4]
 *   @0x2017c8 mov r2, #0
 *   @0x2017cc strd r6, r7, [sp]
 *   @0x2017d0 lsl r6, r10, #16
 *   @0x2017d4 lsr r7, r10, #16
 *   @0x2017d8 orr r10, r8, r6
 *   @0x2017dc ldrb r6, [r12, r4]
 *   @0x2017e0 orr r11, r9, r7
 *   @0x2017e4 ldr r7, [sp]
 *   @0x2017e8 adds r4, r4, #8
 *   @0x2017ec orr r6, r6, r10
 *   @0x2017f0 ldrb r10, [r1, #0x5]
 *   @0x2017f4 adc r5, r5, #0
 *   @0x2017f8 lsr r9, r7, #8
 *   @0x2017fc mov r7, #0
 *   @0x201800 orr r7, r7, r11
 *   @0x201804 mov r11, #0
 *   @0x201808 strd r10, r11, [sp, #8]
 *   @0x20180c orr r9, r9, r7
 *   @0x201810 ldr r11, [sp]
 *   @0x201814 mov r7, #0
 *   @0x201818 ldrb r10, [r1, #0x6]
 *   @0x20181c orr r9, r9, r3
 *   @0x201820 lsl r8, r11, #24
 *   @0x201824 mov r11, #0
 *   @0x201828 orr r8, r8, r6
 *   @0x20182c ldrb r6, [r1, #0x7]
 *   @0x201830 strd r10, r11, [sp]
 *   @0x201834 orr r8, r8, r2
 *   @0x201838 ldr r12, [sp]
 *   @0x20183c orr r8, r8, r2
 *   @0x201840 strd r6, r7, [sp, #16]
 *   @0x201844 orr r8, r8, r2
 *   @0x201848 ldr r7, [sp, #0x8]
 *   @0x20184c ldr r1, [sp, #0x10]
 *   @0x201850 strd r4, r5, [r0, #16]
 *   @0x201854 orr r0, r8, r2
 *   @0x201858 lsl r11, r7, #8
 *   @0x20185c lsl r7, r12, #16
 *   @0x201860 orr r9, r9, r11
 *   @0x201864 lsl r11, r1, #24
 *   @0x201868 orr r9, r9, r7
 *   @0x20186c orr r1, r9, r11
 *   @0x201870 add sp, sp, #24
 *   @0x201874 pop {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x201878 bx lr
 *
 * ══ §111/119 CStream::ConvertFromString(char const*)  0x2025b0  size 248  62 条（0x2025b0..0x2026a8）
 * @func 0x2025b0 0x2026a8  size 248  62 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: isHexdigit(char)×2 / Hex2Int(char)×2 / 0xb6538 / CStream::ConvertFromString(char const*)+0x70 / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool) / CStream::ConvertFromString(char const*)+0xbc
 * 字段偏移 top8: 0x18×3 / 0x1×2 / 0x7c×1 / 0xc×1 / 0x8×1 / 0x-1×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2025b0 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2025b4 mov r8, r0
 *   @0x2025b8 sub sp, sp, #8
 *   @0x2025bc mov r0, r1
 *   @0x2025c0 mov r6, r1
 *   @0x2025c4 bl 0xb6538 <strlen@plt>
 *   @0x2025c8 subs r9, r0, #0
 *   @0x2025cc beq 0x20269c <_ZN7CStream17ConvertFromStringEPKc+0xec>
 *   @0x2025d0 mov r4, #0
 *   @0x2025d4 mov r5, r6
 *   @0x2025d8 mov r7, r4
 *   @0x2025dc b 0x2025f0 <_ZN7CStream17ConvertFromStringEPKc+0x40>
 *   @0x2025e0 add r4, r4, #2
 *   @0x2025e4 add r5, r5, #2
 *   @0x2025e8 cmp r9, r4
 *   @0x2025ec bls 0x202620 <_ZN7CStream17ConvertFromStringEPKc+0x70>
 *   @0x2025f0 ldrb r0, [r6, r4]
 *   @0x2025f4 bl 0x202580 <_Z10isHexdigitc>
 *   @0x2025f8 cmp r0, #0
 *   @0x2025fc beq 0x2025e0 <_ZN7CStream17ConvertFromStringEPKc+0x30>
 *   @0x202600 ldrb r0, [r5, #0x1]
 *   @0x202604 add r4, r4, #2
 *   @0x202608 bl 0x202580 <_Z10isHexdigitc>
 *   @0x20260c add r5, r5, #2
 *   @0x202610 cmp r0, #0
 *   @0x202614 addne r7, r7, #2
 *   @0x202618 cmp r9, r4
 *   @0x20261c bhi 0x2025f0 <_ZN7CStream17ConvertFromStringEPKc+0x40>
 *   @0x202620 ldr r2, [pc, #0x7c]
 *   @0x202624 mov r4, #0
 *   @0x202628 ldr r0, [r8, #0x18]
 *   @0x20262c asr r1, r7, #1
 *   @0x202630 str r4, [r8, #0xc]
 *   @0x202634 add r2, pc, r2
 *   @0x202638 str r1, [r8, #0x8]
 *   @0x20263c movw r3, #0x534
 *   @0x202640 str r4, [sp]
 *   @0x202644 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x202648 cmp r7, r4
 *   @0x20264c mov r2, #0
 *   @0x202650 mov r3, #0
 *   @0x202654 strd r2, r3, [r8, #16]
 *   @0x202658 mov r9, r0
 *   @0x20265c str r0, [r8, #0x18]
 *   @0x202660 beq 0x20269c <_ZN7CStream17ConvertFromStringEPKc+0xec>
 *   @0x202664 mov r5, r6
 *   @0x202668 b 0x202670 <_ZN7CStream17ConvertFromStringEPKc+0xc0>
 *   @0x20266c ldr r9, [r8, #0x18]
 *   @0x202670 ldrb r0, [r6, r4]
 *   @0x202674 add r5, r5, #2
 *   @0x202678 bl 0x20256c <_Z7Hex2Intc>
 *   @0x20267c mov r10, r0
 *   @0x202680 ldrb r0, [r5, #-0x1]
 *   @0x202684 bl 0x20256c <_Z7Hex2Intc>
 *   @0x202688 add r0, r0, r10, lsl #4
 *   @0x20268c strb r0, [r9, r4, asr #1]
 *   @0x202690 add r4, r4, #2
 *   @0x202694 cmp r4, r7
 *   @0x202698 blt 0x20266c <_ZN7CStream17ConvertFromStringEPKc+0xbc>
 *   @0x20269c add sp, sp, #8
 *   @0x2026a0 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2026a4 ldrsheq r1, [r5], -r4
 *
 * ══ §112/119 CDS_Map::FindNext(RValue*)  0x203b94  size 248  62 条（0x203b94..0x203c8c）
 * @func 0x203b94 0x203c8c  size 248  62 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYCompareVal(RValue const&, RValue const&, double) / CDS_Map::FindNext(RValue*)+0xbc
 * 字段偏移 top8: 0x4×4 / 0xc×3 / 0x8×2 / 0x3×1 / 0x74×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x203b94 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x203b98 mov r8, r1
 *   @0x203b9c ldr r9, [r0]
 *   @0x203ba0 sub sp, sp, #16
 *   @0x203ba4 mov r5, #0
 *   @0x203ba8 ldr r2, [r9]
 *   @0x203bac b 0x203bc0 <_ZN7CDS_Map8FindNextEP6RValue+0x2c>
 *   @0x203bb0 ldr r3, [r9, #0x4]
 *   @0x203bb4 add r5, r5, #1
 *   @0x203bb8 cmp r5, r3
 *   @0x203bbc bgt 0x203c80 <_ZN7CDS_Map8FindNextEP6RValue+0xec>
 *   @0x203bc0 ldr r4, [r2, r5, lsl #3]
 *   @0x203bc4 cmp r4, #0
 *   @0x203bc8 beq 0x203bb0 <_ZN7CDS_Map8FindNextEP6RValue+0x1c>
 *   @0x203bcc mov r10, #0
 *   @0x203bd0 cmp r4, #0
 *   @0x203bd4 beq 0x203c70 <_ZN7CDS_Map8FindNextEP6RValue+0xdc>
 *   @0x203bd8 ldr r6, [r4, #0xc]
 *   @0x203bdc cmp r6, #0
 *   @0x203be0 beq 0x203c74 <_ZN7CDS_Map8FindNextEP6RValue+0xe0>
 *   @0x203be4 ldr r3, [r6, #0xc]
 *   @0x203be8 cmp r10, #0
 *   @0x203bec ldr r0, [r6]
 *   @0x203bf0 mov r12, sp
 *   @0x203bf4 ldr r1, [r6, #0x4]
 *   @0x203bf8 ldr r2, [r6, #0x8]
 *   @0x203bfc stm r12!, {r0, r1, r2, r3}
 *   @0x203c00 bic r3, r3, #-16777216
 *   @0x203c04 str r3, [sp, #0xc]
 *   @0x203c08 bne 0x203c74 <_ZN7CDS_Map8FindNextEP6RValue+0xe0>
 *   @0x203c0c ldr r3, [pc, #0x74]
 *   @0x203c10 mov r0, r8
 *   @0x203c14 mov r1, sp
 *   @0x203c18 ldr r3, [pc, r3]
 *   @0x203c1c ldrd r2, r3, [r3]
 *   @0x203c20 bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d>
 *   @0x203c24 ldr r4, [r4, #0x4]
 *   @0x203c28 rsbs r10, r0, #1
 *   @0x203c2c movlo r10, #0
 *   @0x203c30 cmp r4, #0
 *   @0x203c34 bne 0x203bd0 <_ZN7CDS_Map8FindNextEP6RValue+0x3c>
 *   @0x203c38 ldr r1, [r9, #0x4]
 *   @0x203c3c add r3, r5, #1
 *   @0x203c40 cmp r3, r1
 *   @0x203c44 bgt 0x203c70 <_ZN7CDS_Map8FindNextEP6RValue+0xdc>
 *   @0x203c48 ldr r2, [r9]
 *   @0x203c4c add r2, r2, r5, lsl #3
 *   @0x203c50 ldr r4, [r2, #0x8]
 *   @0x203c54 mov r5, r3
 *   @0x203c58 add r2, r2, #8
 *   @0x203c5c add r3, r3, #1
 *   @0x203c60 cmp r4, #0
 *   @0x203c64 bne 0x203bd0 <_ZN7CDS_Map8FindNextEP6RValue+0x3c>
 *   @0x203c68 cmp r3, r1
 *   @0x203c6c ble 0x203c50 <_ZN7CDS_Map8FindNextEP6RValue+0xbc>
 *   @0x203c70 mov r6, #0
 *   @0x203c74 mov r0, r6
 *   @0x203c78 add sp, sp, #16
 *   @0x203c7c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x203c80 mvn r5, #0
 *   @0x203c84 b 0x203bcc <_ZN7CDS_Map8FindNextEP6RValue+0x38>
 *   @0x203c88 andseq sp, lr, r12, ror #14
 *
 * ══ §113/119 Audio_FreeBufferSound(int)  0x219d70  size 248  62 条（0x219d70..0x219e68）
 * @func 0x219d70 0x219e68  size 248  62 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Audio_FreeBufferSound(int)+0x9c / Audio_StopSoundNoise(CNoise*, bool) / GetIBuffer(int) / cAudio_Sound::~cAudio_Sound() / operator delete(void*)
 * 字段偏移 top8: 0x28×2 / 0x2c×2 / 0x2×2 / 0x38×2 / 0xcc×1 / 0xa0×1 / 0x9c×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x219d70 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x219d74 sub r7, r0, #99328
 *   @0x219d78 subs r7, r7, #672
 *   @0x219d7c mov r5, r0
 *   @0x219d80 bmi 0x219e50 <_Z21Audio_FreeBufferSoundi+0xe0>
 *   @0x219d84 ldr r3, [pc, #0xcc]
 *   @0x219d88 add r3, pc, r3
 *   @0x219d8c ldr r2, [r3, #0x28]
 *   @0x219d90 cmp r7, r2
 *   @0x219d94 bge 0x219e50 <_Z21Audio_FreeBufferSoundi+0xe0>
 *   @0x219d98 ldr r2, [r3, #0x2c]
 *   @0x219d9c ldr r8, [r2, r7, lsl #2]
 *   @0x219da0 cmp r8, #0
 *   @0x219da4 beq 0x219e50 <_Z21Audio_FreeBufferSoundi+0xe0>
 *   @0x219da8 ldr r6, [r3, #0x38]
 *   @0x219dac cmp r6, #0
 *   @0x219db0 ble 0x219e0c <_Z21Audio_FreeBufferSoundi+0x9c>
 *   @0x219db4 ldr r10, [pc, #0xa0]
 *   @0x219db8 mov r3, r6
 *   @0x219dbc ldr r9, [pc, #0x9c]
 *   @0x219dc0 mov r4, #0
 *   @0x219dc4 add r10, pc, r10
 *   @0x219dc8 add r9, pc, r9
 *   @0x219dcc b 0x219ddc <_Z21Audio_FreeBufferSoundi+0x6c>
 *   @0x219dd0 cmp r4, r6
 *   @0x219dd4 beq 0x219e0c <_Z21Audio_FreeBufferSoundi+0x9c>
 *   @0x219dd8 ldr r3, [r9, #0x38]
 *   @0x219ddc cmp r3, r4
 *   @0x219de0 mov r0, #0
 *   @0x219de4 ldrgt r3, [r10, #0x3c]
 *   @0x219de8 ldrgt r0, [r3, r4, lsl #2]
 *   @0x219dec add r4, r4, #1
 *   @0x219df0 ldr r2, [r0, #0x18]
 *   @0x219df4 cmp r2, r5
 *   @0x219df8 bne 0x219dd0 <_Z21Audio_FreeBufferSoundi+0x60>
 *   @0x219dfc mov r1, #1
 *   @0x219e00 bl 0x21a0b0 <_Z20Audio_StopSoundNoiseP6CNoiseb>
 *   @0x219e04 cmp r4, r6
 *   @0x219e08 bne 0x219dd8 <_Z21Audio_FreeBufferSoundi+0x68>
 *   @0x219e0c ldr r0, [r8, #0x10]
 *   @0x219e10 bl 0xc6720 <_Z10GetIBufferi>
 *   @0x219e14 cmp r0, #0
 *   @0x219e18 ldrne r3, [r0, #0x28]
 *   @0x219e1c subne r3, r3, #1
 *   @0x219e20 strne r3, [r0, #0x28]
 *   @0x219e24 mov r0, r8
 *   @0x219e28 bl 0x218f24 <_ZN12cAudio_SoundD2Ev>
 *   @0x219e2c mov r0, r8
 *   @0x219e30 bl 0x27d1d0 <_ZdlPv>
 *   @0x219e34 ldr r3, [pc, #0x28]
 *   @0x219e38 mov r2, #0
 *   @0x219e3c mov r0, #1
 *   @0x219e40 add r3, pc, r3
 *   @0x219e44 ldr r3, [r3, #0x2c]
 *   @0x219e48 str r2, [r3, r7, lsl #2]
 *   @0x219e4c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x219e50 mov r0, #0
 *   @0x219e54 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x219e58 subseq r11, r3, r12, lsl #10
 *   @0x219e5c ldrsbeq r11, [r3], #-64
 *   @0x219e60 subseq r11, r3, r12, asr #9
 *   @0x219e64 subseq r11, r3, r4, asr r4
 *
 * ══ §114/119 COggAudio::Quit()  0x225fa4  size 248  62 条（0x225fa4..0x22609c）
 * @func 0x225fa4 0x22609c  size 248  62 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: COggAudio::Quit()+0x54 / COggThread::Quit() / Mutex::~Mutex() / operator delete(void*) / operator delete[](void*) / COggAudio::Delete_SyncThread(int)
 * 字段偏移 top8: 0x14×4 / 0x4×2 / 0x-4×1 / 0x10×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x225fa4 ldr r3, [r0]
 *   @0x225fa8 push {r4, r5, r6, r7, r8, lr}
 *   @0x225fac cmp r3, #0
 *   @0x225fb0 mov r4, r0
 *   @0x225fb4 beq 0x22605c <_ZN9COggAudio4QuitEv+0xb8>
 *   @0x225fb8 ldr r2, [r0, #0x14]
 *   @0x225fbc cmp r2, #0
 *   @0x225fc0 ble 0x225ff8 <_ZN9COggAudio4QuitEv+0x54>
 *   @0x225fc4 mov r5, #0
 *   @0x225fc8 mov r6, r5
 *   @0x225fcc add r0, r3, r5
 *   @0x225fd0 add r6, r6, #1
 *   @0x225fd4 bl 0x223bdc <_ZN10COggThread4QuitEv>
 *   @0x225fd8 ldr r3, [r4, #0x14]
 *   @0x225fdc add r5, r5, #2096
 *   @0x225fe0 cmp r3, r6
 *   @0x225fe4 add r5, r5, #4
 *   @0x225fe8 ldr r3, [r4]
 *   @0x225fec bgt 0x225fcc <_ZN9COggAudio4QuitEv+0x28>
 *   @0x225ff0 cmp r3, #0
 *   @0x225ff4 beq 0x226050 <_ZN9COggAudio4QuitEv+0xac>
 *   @0x225ff8 ldr r2, [r3, #-0x4]
 *   @0x225ffc movw r7, #0x834
 *   @0x226000 mla r7, r7, r2, r3
 *   @0x226004 sub r8, r7, #28
 *   @0x226008 mov r5, r7
 *   @0x22600c b 0x226038 <_ZN9COggAudio4QuitEv+0x94>
 *   @0x226010 ldr r6, [r2, #0x14]
 *   @0x226014 cmp r6, #0
 *   @0x226018 mov r0, r6
 *   @0x22601c beq 0x226030 <_ZN9COggAudio4QuitEv+0x8c>
 *   @0x226020 bl 0x27e020 <_ZN5MutexD2Ev>
 *   @0x226024 mov r0, r6
 *   @0x226028 bl 0x27d1d0 <_ZdlPv>
 *   @0x22602c ldr r3, [r4]
 *   @0x226030 sub r5, r5, #2096
 *   @0x226034 sub r5, r5, #4
 *   @0x226038 cmp r3, r5
 *   @0x22603c rsb r2, r7, r5
 *   @0x226040 add r2, r2, r8
 *   @0x226044 bne 0x226010 <_ZN9COggAudio4QuitEv+0x6c>
 *   @0x226048 sub r0, r3, #8
 *   @0x22604c bl 0x27d1d4 <_ZdaPv>
 *   @0x226050 mov r3, #0
 *   @0x226054 str r3, [r4]
 *   @0x226058 str r3, [r4, #0x14]
 *   @0x22605c ldr r3, [r4, #0x4]
 *   @0x226060 cmp r3, #0
 *   @0x226064 pople {r4, r5, r6, r7, r8, pc}
 *   @0x226068 mov r5, #0
 *   @0x22606c ldr r2, [r4, #0x10]
 *   @0x226070 mov r1, r5
 *   @0x226074 mov r0, r4
 *   @0x226078 ldr r2, [r2, r5, lsl #2]
 *   @0x22607c add r5, r5, #1
 *   @0x226080 cmp r2, #0
 *   @0x226084 beq 0x226090 <_ZN9COggAudio4QuitEv+0xec>
 *   @0x226088 bl 0x225f2c <_ZN9COggAudio17Delete_SyncThreadEi>
 *   @0x22608c ldr r3, [r4, #0x4]
 *   @0x226090 cmp r3, r5
 *   @0x226094 bgt 0x22606c <_ZN9COggAudio4QuitEv+0xc8>
 *   @0x226098 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §115/119 COggAudio::Play_Sound(int, cAudio_Sound*, bool, float, int, int)  0x22630c  size 248  62 条（0x22630c..0x226404）
 * @func 0x22630c 0x226404  size 248  62 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: COggSyncThread::Play_Sound(int&, cAudio_Sound*, bool, float, int) / COggAudio::GetThreadForChannel(int, int&) / COggThread::Play_Sound(int, cAudio_Sound*, bool, float, int)
 * 字段偏移 top8: 0x14×4 / 0x24×3 / 0x4×3 / 0xc×3 / 0x30×2 / 0x2c×2 / 0x10×1 / 0x2×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x22630c push {r4, r5, lr}
 *   @0x226310 mov r4, r2
 *   @0x226314 ldrb r2, [r2, #0x24]
 *   @0x226318 sub sp, sp, #28
 *   @0x22631c cmp r2, #0
 *   @0x226320 ldr r12, [sp, #0x30]
 *   @0x226324 beq 0x226334 <_ZN9COggAudio10Play_SoundEiP12cAudio_Soundbfii+0x28>
 *   @0x226328 ldr r2, [r4, #0x30]
 *   @0x22632c cmp r2, #0
 *   @0x226330 beq 0x2263d0 <_ZN9COggAudio10Play_SoundEiP12cAudio_Soundbfii+0xc4>
 *   @0x226334 cmn r12, #1
 *   @0x226338 mov r2, #0
 *   @0x22633c str r2, [sp, #0x14]
 *   @0x226340 beq 0x226394 <_ZN9COggAudio10Play_SoundEiP12cAudio_Soundbfii+0x88>
 *   @0x226344 ldr r5, [r0, #0x4]
 *   @0x226348 cmp r12, r5
 *   @0x22634c movge r0, r2
 *   @0x226350 bge 0x22638c <_ZN9COggAudio10Play_SoundEiP12cAudio_Soundbfii+0x80>
 *   @0x226354 ldr r2, [r0, #0x10]
 *   @0x226358 ldr r0, [r2, r12, lsl #2]
 *   @0x22635c cmp r0, #0
 *   @0x226360 beq 0x22638c <_ZN9COggAudio10Play_SoundEiP12cAudio_Soundbfii+0x80>
 *   @0x226364 ldr r2, [sp, #0x2c]
 *   @0x226368 add r12, sp, #24
 *   @0x22636c vldr s15, [sp, #40]
 *   @0x226370 vstr s15, [sp]
 *   @0x226374 str r2, [sp, #0x4]
 *   @0x226378 mov r2, r4
 *   @0x22637c str r1, [r12, #-0x4]!
 *   @0x226380 mov r1, r12
 *   @0x226384 bl 0x224e48 <_ZN14COggSyncThread10Play_SoundERiP12cAudio_Soundbfi>
 *   @0x226388 ldr r0, [sp, #0x14]
 *   @0x22638c add sp, sp, #28
 *   @0x226390 pop {r4, r5, pc}
 *   @0x226394 add r2, sp, #20
 *   @0x226398 str r3, [sp, #0xc]
 *   @0x22639c bl 0x226284 <_ZN9COggAudio19GetThreadForChannelEiRi>
 *   @0x2263a0 ldr r3, [sp, #0xc]
 *   @0x2263a4 cmp r0, #0
 *   @0x2263a8 beq 0x226388 <_ZN9COggAudio10Play_SoundEiP12cAudio_Soundbfii+0x7c>
 *   @0x2263ac ldr r2, [sp, #0x2c]
 *   @0x2263b0 vldr s15, [sp, #40]
 *   @0x2263b4 ldr r1, [sp, #0x14]
 *   @0x2263b8 vstr s15, [sp]
 *   @0x2263bc str r2, [sp, #0x4]
 *   @0x2263c0 mov r2, r4
 *   @0x2263c4 bl 0x223aac <_ZN10COggThread10Play_SoundEiP12cAudio_Soundbfi>
 *   @0x2263c8 ldr r0, [sp, #0x14]
 *   @0x2263cc b 0x22638c <_ZN9COggAudio10Play_SoundEiP12cAudio_Soundbfii+0x80>
 *   @0x2263d0 ldr r3, [pc, #0x24]
 *   @0x2263d4 ldr r1, [pc, #0x24]
 *   @0x2263d8 ldr r3, [pc, r3]
 *   @0x2263dc ldr r2, [r4]
 *   @0x2263e0 add r1, pc, r1
 *   @0x2263e4 ldr r0, [r3]
 *   @0x2263e8 ldr r3, [r0]
 *   @0x2263ec ldr r3, [r3, #0xc]
 *   @0x2263f0 blx r3
 *   @0x2263f4 mvn r0, #0
 *   @0x2263f8 b 0x22638c <_ZN9COggAudio10Play_SoundEiP12cAudio_Soundbfii+0x80>
 *   @0x2263fc andseq r7, r12, r12, lsr r3
 *   @0x226400 andseq lr, r2, r8, lsl #22
 *
 * ══ §116/119 _spPathConstraintPositionTimeline_apply  0x2826ec  size 248  62 条（0x2826ec..0x2827e4）
 * @func 0x2826ec 0x2827f8  size 268  67 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _spPathConstraintPositionTimeline_apply+0x6c / anon_280ed0 / spCurveTimeline_getCurvePercent
 * 字段偏移 top8: 0x10×2 / 0xc×1 / 0x34×1 / 0x14×1 / 0x2×1
 * VFP 指令 35 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2826ec push {r3, r4, r5, r6, r7, lr}
 *   @0x2826f0 vpush {d8}
 *   @0x2826f4 vmov s16, r3
 *   @0x2826f8 ldr r5, [r0, #0x10]
 *   @0x2826fc vldr s15, [r5]
 *   @0x282700 vcmpe.f32 s15, s16
 *   @0x282704 mov r4, r0
 *   @0x282708 vmrs APSR_nzcv, fpscr
 *   @0x28270c bgt 0x282750 <_spPathConstraintPositionTimeline_apply+0x64>
 *   @0x282710 ldr r2, [r0, #0xc]
 *   @0x282714 ldr r1, [r1, #0x34]
 *   @0x282718 sub r3, r2, #2
 *   @0x28271c ldr r0, [r0, #0x14]
 *   @0x282720 add r3, r5, r3, lsl #2
 *   @0x282724 vldr s15, [r3]
 *   @0x282728 vcmpe.f32 s16, s15
 *   @0x28272c ldr r6, [r1, r0, lsl #2]
 *   @0x282730 vmrs APSR_nzcv, fpscr
 *   @0x282734 blt 0x282758 <_spPathConstraintPositionTimeline_apply+0x6c>
 *   @0x282738 vldr s15, [r6, #16]
 *   @0x28273c vldr s14, [r3, #4]
 *   @0x282740 vsub.f32 s14, s14, s15
 *   @0x282744 vldr s13, [sp, #40]
 *   @0x282748 vmla.f32 s15, s14, s13
 *   @0x28274c vstr s15, [r6, #16]
 *   @0x282750 vpop {d8}
 *   @0x282754 pop {r3, r4, r5, r6, r7, pc}
 *   @0x282758 mov r1, r2
 *   @0x28275c vmov.f32 s0, s16
 *   @0x282760 mov r0, r5
 *   @0x282764 mov r2, #2
 *   @0x282768 bl 0x280ed0 <printbuf_free+0x20>
 *   @0x28276c vmov.f32 s14, #1.000000e+00
 *   @0x282770 sub r7, r0, #1
 *   @0x282774 add r1, r0, r0, lsr #31
 *   @0x282778 mov r0, r4
 *   @0x28277c lsl r7, r7, #2
 *   @0x282780 asr r1, r1, #1
 *   @0x282784 add r5, r5, r7
 *   @0x282788 vldr s15, [r5, #4]
 *   @0x28278c vldr s13, [r5, #-4]
 *   @0x282790 vsub.f32 s16, s16, s15
 *   @0x282794 sub r1, r1, #1
 *   @0x282798 vldr s17, [r5]
 *   @0x28279c vsub.f32 s15, s13, s15
 *   @0x2827a0 vdiv.f32 s15, s16, s15
 *   @0x2827a4 vsub.f32 s14, s14, s15
 *   @0x2827a8 vmov r2, s14
 *   @0x2827ac bl 0x2818e0 <spCurveTimeline_getCurvePercent>
 *   @0x2827b0 ldr r3, [r4, #0x10]
 *   @0x2827b4 vldr s15, [r6, #16]
 *   @0x2827b8 add r7, r3, r7
 *   @0x2827bc vldr s14, [r7, #8]
 *   @0x2827c0 vsub.f32 s14, s14, s17
 *   @0x2827c4 vmov s13, r0
 *   @0x2827c8 vmla.f32 s17, s14, s13
 *   @0x2827cc vldr s14, [sp, #40]
 *   @0x2827d0 vsub.f32 s17, s17, s15
 *   @0x2827d4 vmla.f32 s15, s17, s14
 *   @0x2827d8 vpop {d8}
 *   @0x2827dc vstr s15, [r6, #16]
 *   @0x2827e0 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §117/119 _spPathConstraintSpacingTimeline_apply  0x2827e4  size 248  62 条（0x2827e4..0x2828dc）
 * @func 0x2827e4 0x2828dc  size 248  62 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _spPathConstraintSpacingTimeline_apply+0x6c / anon_280ed0 / spCurveTimeline_getCurvePercent
 * 字段偏移 top8: 0x10×2 / 0xc×1 / 0x34×1 / 0x14×1 / 0x2×1
 * VFP 指令 35 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2827e4 push {r3, r4, r5, r6, r7, lr}
 *   @0x2827e8 vpush {d8}
 *   @0x2827ec vmov s16, r3
 *   @0x2827f0 ldr r5, [r0, #0x10]
 *   @0x2827f4 vldr s15, [r5]
 *   @0x2827f8 vcmpe.f32 s15, s16
 *   @0x2827fc mov r4, r0
 *   @0x282800 vmrs APSR_nzcv, fpscr
 *   @0x282804 bgt 0x282848 <_spPathConstraintSpacingTimeline_apply+0x64>
 *   @0x282808 ldr r2, [r0, #0xc]
 *   @0x28280c ldr r1, [r1, #0x34]
 *   @0x282810 sub r3, r2, #2
 *   @0x282814 ldr r0, [r0, #0x14]
 *   @0x282818 add r3, r5, r3, lsl #2
 *   @0x28281c vldr s15, [r3]
 *   @0x282820 vcmpe.f32 s16, s15
 *   @0x282824 ldr r6, [r1, r0, lsl #2]
 *   @0x282828 vmrs APSR_nzcv, fpscr
 *   @0x28282c blt 0x282850 <_spPathConstraintSpacingTimeline_apply+0x6c>
 *   @0x282830 vldr s15, [r6, #20]
 *   @0x282834 vldr s14, [r3, #4]
 *   @0x282838 vsub.f32 s14, s14, s15
 *   @0x28283c vldr s13, [sp, #40]
 *   @0x282840 vmla.f32 s15, s14, s13
 *   @0x282844 vstr s15, [r6, #20]
 *   @0x282848 vpop {d8}
 *   @0x28284c pop {r3, r4, r5, r6, r7, pc}
 *   @0x282850 mov r1, r2
 *   @0x282854 vmov.f32 s0, s16
 *   @0x282858 mov r0, r5
 *   @0x28285c mov r2, #2
 *   @0x282860 bl 0x280ed0 <printbuf_free+0x20>
 *   @0x282864 vmov.f32 s14, #1.000000e+00
 *   @0x282868 sub r7, r0, #1
 *   @0x28286c add r1, r0, r0, lsr #31
 *   @0x282870 mov r0, r4
 *   @0x282874 lsl r7, r7, #2
 *   @0x282878 asr r1, r1, #1
 *   @0x28287c add r5, r5, r7
 *   @0x282880 vldr s15, [r5, #4]
 *   @0x282884 vldr s13, [r5, #-4]
 *   @0x282888 vsub.f32 s16, s16, s15
 *   @0x28288c sub r1, r1, #1
 *   @0x282890 vldr s17, [r5]
 *   @0x282894 vsub.f32 s15, s13, s15
 *   @0x282898 vdiv.f32 s15, s16, s15
 *   @0x28289c vsub.f32 s14, s14, s15
 *   @0x2828a0 vmov r2, s14
 *   @0x2828a4 bl 0x2818e0 <spCurveTimeline_getCurvePercent>
 *   @0x2828a8 ldr r3, [r4, #0x10]
 *   @0x2828ac vldr s15, [r6, #20]
 *   @0x2828b0 add r7, r3, r7
 *   @0x2828b4 vldr s14, [r7, #8]
 *   @0x2828b8 vsub.f32 s14, s14, s17
 *   @0x2828bc vmov s13, r0
 *   @0x2828c0 vmla.f32 s17, s14, s13
 *   @0x2828c4 vldr s14, [sp, #40]
 *   @0x2828c8 vsub.f32 s17, s17, s15
 *   @0x2828cc vmla.f32 s15, s17, s14
 *   @0x2828d0 vpop {d8}
 *   @0x2828d4 vstr s15, [r6, #20]
 *   @0x2828d8 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §118/119 SoundHardware::StopMusic()  0x220950  size 172  36 条（0x220950..0x2209fc）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x220950 0x2209fc  size 172  36 条
 * 部分覆盖: 本节 36/43 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x220958→0x755361, 0x220970→0x755363, 0x220984→0x755362, 0x220998→0x75536c, 0x2209ac→0x3eb70c
 * 调用序列: 无
 * 字段偏移 top8: 0x3c×3 / 0x80×2 / 0x6c×1 / 0x5c×1 / 0x4c×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x220950 push {r4, lr}
 *   @0x220954 ldr r4, [pc, #0x80]
 *   @0x220958 ldr r3, [pc, #0x80]
 *   @0x22095c add r4, pc, r4
 *   @0x220960 ldr r3, [r4, r3]
 *   @0x220964 ldrb r3, [r3]
 *   @0x220984 ldr r3, [pc, #0x5c]
 *   @0x220988 ldr r3, [r4, r3]
 *   @0x22098c ldrb r3, [r3]
 *   @0x220990 cmp r3, #0
 *   @0x220994 popne {r4, pc}
 *   @0x220998 ldr r2, [pc, #0x4c]
 *   @0x22099c ldr r2, [r4, r2]
 *   @0x2209a0 strb r3, [r2]
 *   @0x2209a4 pop {r4, lr}
 *   @0x2209a8 b 0x223224 <_Z14OpenAL_StopMP3v>
 *   @0x2209ac ldr r3, [pc, #0x3c]
 *   @0x2209b0 ldr r2, [pc, #0x3c]
 *   @0x2209b4 ldr r1, [pc, #0x3c]
 *   @0x2209b8 ldr r3, [r4, r3]
 *   @0x2209bc add r2, pc, r2
 *   @0x2209c0 add r1, pc, r1
 *   @0x2209c4 add r2, r2, #100
 *   @0x2209c8 ldr r0, [r3]
 *   @0x2209cc ldr r3, [r0]
 *   @0x2209d0 ldr r3, [r3, #0xc]
 *   @0x2209d4 blx r3
 *   @0x2209d8 b 0x220970 <_ZN13SoundHardware9StopMusicEv+0x20>
 *   @0x2209dc ldrsheq r1, [sp], -r4
 *   @0x2209e0 .word 0xfffff7d8
 *   @0x2209e4 .word 0xffffd3fc
 *   @0x2209e8 .word 0xfffff7e0
 *   @0x2209ec .word 0xfffff7dc
 *   @0x2209f0 .word 0xffffbac4
 *   @0x2209f4 andseq sp, r3, r12, lsl #12
 *   @0x2209f8 andseq r3, r3, r12, ror lr
 *
 * ══ §119/119 FINALIZE_Code_Main()  0xcf478  size 4  1 条（0xcf478..0xcf47c）
 * @func 0xcf478 0xcf47c  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcf478 bx lr
 */
