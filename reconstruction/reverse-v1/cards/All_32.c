/* cally 逆向卡：All_32 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 33 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/33 YYGML_ds_grid_set(int, int, int, YYRValue const&)  0x1049b4  size 992  248 条（0x1049b4..0x104d94）
 * @func 0x1049b4 0x104d94  size 992  248 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1049c0→0x479a24, 0x1049e0→0x483698, 0x104aa8→0x483694, 0x104abc→0x483698, 0x104bd0→0x3eb708
 * 调用序列: LOCK_RVALUE_MUTEX()×6 / YYFree(void const*)×6 / UNLOCK_RVALUE_MUTEX()×4 / operator delete(void*)×4 / YYGML_ds_grid_set(int, int, int, YYRValue const&)+0x17c / FREE_RValue__Pre(RValue*) / GetContextStackTop() / _RefThing<char const*>::dec()
 * 字段偏移 top8: 0x4×25 / 0x8×12 / 0xc×7 / 0x2×2 / 0x3bc×1 / 0x3b4×1 / 0x398×1 / 0x2d4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1049b4 ldr r12, [pc, #0x3bc]
 *   @0x1049b8 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x1049bc add r12, pc, r12
 *   @0x1049c0 ldr r5, [pc, #0x3b4]
 *   @0x1049c4 sub sp, sp, #20
 *   @0x1049c8 mov r8, r2
 *   @0x1049cc mov r4, r3
 *   @0x1049d0 ldr r5, [r12, r5]
 *   @0x1049d4 ldrb r5, [r5]
 *   @0x1049d8 cmp r5, #0
 *   @0x1049dc bne 0x104aa0 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0xec>
 *   @0x1049e0 ldr r3, [pc, #0x398]
 *   @0x1049e4 ldr r3, [r12, r3]
 *   @0x1049e8 ldr r3, [r3, #0x4]
 *   @0x1049ec ldr r3, [r3, r0, lsl #2]
 *   @0x1049f0 ldm r3, {r6, r7}
 *   @0x1049f4 mla r7, r7, r2, r1
 *   @0x1049f8 add r5, r6, r7, lsl #4
 *   @0x1049fc ldr r2, [r5, #0xc]
 *   @0x104a00 bic r3, r2, #-16777216
 *   @0x104a04 cmp r3, #1
 *   @0x104a08 beq 0x104b88 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x1d4>
 *   @0x104a0c cmp r3, #2
 *   @0x104a10 bne 0x104a38 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x84>
 *   @0x104a14 sub r2, r2, #1
 *   @0x104a18 bic r2, r2, #-16777216
 *   @0x104a1c bic r2, r2, #3
 *   @0x104a20 cmp r2, #0
 *   @0x104a24 beq 0x104b24 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x170>
 *   @0x104a28 mov r2, #0
 *   @0x104a2c mov r3, #5
 *   @0x104a30 str r2, [r5, #0x8]
 *   @0x104a34 str r3, [r5, #0xc]
 *   @0x104a38 ldr r3, [r4, #0xc]
 *   @0x104a3c mov r1, #0
 *   @0x104a40 ldr r2, [r4, #0x8]
 *   @0x104a44 str r1, [r6, r7, lsl #4]
 *   @0x104a48 str r3, [r5, #0xc]
 *   @0x104a4c ldr r3, [r4, #0xc]
 *   @0x104a50 str r2, [r5, #0x8]
 *   @0x104a54 bic r3, r3, #-16777216
 *   @0x104a58 cmp r3, #14
 *   @0x104a5c addls pc, pc, r3, lsl #2
 *   @0x104a60 b 0x104b70 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x1bc>
 *   @0x104a64 b 0x104bbc <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x208>
 *   @0x104a68 b 0x104c0c <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x258>
 *   @0x104a6c b 0x104b48 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x194>
 *   @0x104a70 b 0x104b78 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x1c4>
 *   @0x104a74 b 0x104b70 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x1bc>
 *   @0x104a78 b 0x104b70 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x1bc>
 *   @0x104a7c b 0x104c24 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x270>
 *   @0x104a80 b 0x104b78 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x1c4>
 *   @0x104a84 b 0x104b70 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x1bc>
 *   @0x104a88 b 0x104b70 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x1bc>
 *   @0x104a8c b 0x104bbc <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x208>
 *   @0x104a90 b 0x104b70 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x1bc>
 *   @0x104a94 b 0x104b70 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x1bc>
 *   @0x104a98 b 0x104bbc <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x208>
 *   @0x104a9c b 0x104b78 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x1c4>
 *   @0x104aa0 cmp r0, #0
 *   @0x104aa4 blt 0x104b30 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x17c>
 *   @0x104aa8 ldr r3, [pc, #0x2d4]
 *   @0x104aac ldr r3, [r12, r3]
 *   @0x104ab0 ldr r3, [r3]
 *   @0x104ab4 cmp r0, r3
 *   @0x104ab8 bge 0x104b30 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x17c>
 *   @0x104abc ldr r3, [pc, #0x2bc]
 *   @0x104ac0 ldr r3, [r12, r3]
 *   @0x104ac4 ldr r3, [r3, #0x4]
 *   @0x104ac8 ldr r3, [r3, r0, lsl #2]
 *   @0x104acc cmp r3, #0
 *   @0x104ad0 beq 0x104b30 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x17c>
 *   @0x104ad4 ldr r7, [r3, #0x4]
 *   @0x104ad8 ldr r5, [r3, #0x8]
 *   @0x104adc cmp r1, r7
 *   @0x104ae0 bhs 0x104bd0 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x21c>
 *   @0x104ae4 cmp r2, r5
 *   @0x104ae8 bhs 0x104bd0 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x21c>
 *   @0x104aec mla r7, r7, r2, r1
 *   @0x104af0 ldr r6, [r3]
 *   @0x104af4 add r5, r6, r7, lsl #4
 *   @0x104af8 ldr r2, [r5, #0xc]
 *   @0x104afc bic r3, r2, #-16777216
 *   @0x104b00 cmp r3, #1
 *   @0x104b04 beq 0x104cbc <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x308>
 *   @0x104b08 cmp r3, #2
 *   @0x104b0c bne 0x104a38 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x84>
 *   @0x104b10 sub r3, r2, #1
 *   @0x104b14 bic r3, r3, #-16777216
 *   @0x104b18 bic r3, r3, #3
 *   @0x104b1c cmp r3, #0
 *   @0x104b20 bne 0x104a28 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x74>
 *   @0x104b24 mov r0, r5
 *   @0x104b28 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x104b2c b 0x104a28 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x74>
 *   @0x104b30 ldr r0, [pc, #0x250]
 *   @0x104b34 mov r1, #0
 *   @0x104b38 add r0, pc, r0
 *   @0x104b3c add sp, sp, #20
 *   @0x104b40 pop {r4, r5, r6, r7, r8, r9, lr}
 *   @0x104b44 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x104b48 ldr r3, [r4]
 *   @0x104b4c cmp r3, #0
 *   @0x104b50 str r3, [r6, r7, lsl #4]
 *   @0x104b54 beq 0x104b70 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x1bc>
 *   @0x104b58 ldr r1, [r3, #0x8]
 *   @0x104b5c ldr r2, [r3]
 *   @0x104b60 cmp r1, #0
 *   @0x104b64 streq r5, [r3, #0x8]
 *   @0x104b68 add r2, r2, #1
 *   @0x104b6c str r2, [r3]
 *   @0x104b70 add sp, sp, #20
 *   @0x104b74 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x104b78 ldr r3, [r4]
 *   @0x104b7c str r3, [r6, r7, lsl #4]
 *   @0x104b80 add sp, sp, #20
 *   @0x104b84 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x104b88 ldr r8, [r6, r7, lsl #4]
 *   @0x104b8c cmp r8, #0
 *   @0x104b90 beq 0x104bb0 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x1fc>
 *   @0x104b94 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x104b98 ldr r9, [r8, #0x4]
 *   @0x104b9c sub r9, r9, #1
 *   @0x104ba0 str r9, [r8, #0x4]
 *   @0x104ba4 cmp r9, #0
 *   @0x104ba8 beq 0x104c4c <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x298>
 *   @0x104bac bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x104bb0 mov r3, #0
 *   @0x104bb4 str r3, [r6, r7, lsl #4]
 *   @0x104bb8 b 0x104a38 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x84>
 *   @0x104bbc ldm r4, {r2, r3}
 *   @0x104bc0 str r2, [r6, r7, lsl #4]
 *   @0x104bc4 str r3, [r5, #0x4]
 *   @0x104bc8 add sp, sp, #20
 *   @0x104bcc pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x104bd0 ldr lr, [pc, #0x1b4]
 *   @0x104bd4 mov r2, r0
 *   @0x104bd8 mov r3, r1
 *   @0x104bdc ldr r1, [pc, #0x1ac]
 *   @0x104be0 ldr r0, [r12, lr]
 *   @0x104be4 add r1, pc, r1
 *   @0x104be8 ldr r0, [r0]
 *   @0x104bec ldr r12, [r0]
 *   @0x104bf0 str r8, [sp]
 *   @0x104bf4 str r7, [sp, #0x4]
 *   @0x104bf8 str r5, [sp, #0x8]
 *   @0x104bfc ldr r12, [r12, #0xc]
 *   @0x104c00 blx r12
 *   @0x104c04 add sp, sp, #20
 *   @0x104c08 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x104c0c ldr r3, [r4]
 *   @0x104c10 cmp r3, #0
 *   @0x104c14 ldrne r2, [r3, #0x4]
 *   @0x104c18 addne r2, r2, #1
 *   @0x104c1c strne r2, [r3, #0x4]
 *   @0x104c20 b 0x104b7c <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x1c8>
 *   @0x104c24 ldr r3, [r4]
 *   @0x104c28 str r3, [r6, r7, lsl #4]
 *   @0x104c2c ldr r3, [r4]
 *   @0x104c30 cmp r3, #0
 *   @0x104c34 beq 0x104b70 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x1bc>
 *   @0x104c38 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x104c3c ldr r1, [r4]
 *   @0x104c40 add sp, sp, #20
 *   @0x104c44 pop {r4, r5, r6, r7, r8, r9, lr}
 *   @0x104c48 b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x104c4c ldr r0, [r8]
 *   @0x104c50 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x104c54 str r9, [r8]
 *   @0x104c58 str r9, [r8, #0x8]
 *   @0x104c5c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x104c60 ldr r9, [r8, #0x4]
 *   @0x104c64 sub r9, r9, #1
 *   @0x104c68 str r9, [r8, #0x4]
 *   @0x104c6c cmp r9, #0
 *   @0x104c70 beq 0x104c84 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x2d0>
 *   @0x104c74 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x104c78 mov r0, r8
 *   @0x104c7c bl 0x27d1d0 <_ZdlPv>
 *   @0x104c80 b 0x104bac <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x1f8>
 *   @0x104c84 ldr r0, [r8]
 *   @0x104c88 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x104c8c str r9, [r8]
 *   @0x104c90 str r9, [r8, #0x8]
 *   @0x104c94 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x104c98 ldr r9, [r8, #0x4]
 *   @0x104c9c sub r9, r9, #1
 *   @0x104ca0 str r9, [r8, #0x4]
 *   @0x104ca4 cmp r9, #0
 *   @0x104ca8 beq 0x104d20 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x36c>
 *   @0x104cac bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x104cb0 mov r0, r8
 *   @0x104cb4 bl 0x27d1d0 <_ZdlPv>
 *   @0x104cb8 b 0x104c74 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x2c0>
 *   @0x104cbc ldr r8, [r6, r7, lsl #4]
 *   @0x104cc0 cmp r8, #0
 *   @0x104cc4 beq 0x104bb0 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x1fc>
 *   @0x104cc8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x104ccc ldr r9, [r8, #0x4]
 *   @0x104cd0 sub r9, r9, #1
 *   @0x104cd4 str r9, [r8, #0x4]
 *   @0x104cd8 cmp r9, #0
 *   @0x104cdc bne 0x104bac <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x1f8>
 *   @0x104ce0 ldr r0, [r8]
 *   @0x104ce4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x104ce8 str r9, [r8]
 *   @0x104cec str r9, [r8, #0x8]
 *   @0x104cf0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x104cf4 ldr r3, [r8, #0x4]
 *   @0x104cf8 sub r3, r3, #1
 *   @0x104cfc str r3, [r8, #0x4]
 *   @0x104d00 cmp r3, #0
 *   @0x104d04 bne 0x104c74 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x2c0>
 *   @0x104d08 ldr r0, [r8]
 *   @0x104d0c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x104d10 mov r3, #0
 *   @0x104d14 str r3, [r8]
 *   @0x104d18 str r3, [r8, #0x8]
 *   @0x104d1c b 0x104c94 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x2e0>
 *   @0x104d20 ldr r0, [r8]
 *   @0x104d24 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x104d28 str r9, [r8]
 *   @0x104d2c str r9, [r8, #0x8]
 *   @0x104d30 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x104d34 ldr r9, [r8, #0x4]
 *   @0x104d38 sub r9, r9, #1
 *   @0x104d3c str r9, [r8, #0x4]
 *   @0x104d40 cmp r9, #0
 *   @0x104d44 bne 0x104d68 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x3b4>
 *   @0x104d48 ldr r0, [r8]
 *   @0x104d4c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x104d50 mov r0, r8
 *   @0x104d54 str r9, [r8]
 *   @0x104d58 str r9, [r8, #0x8]
 *   @0x104d5c bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x104d60 mov r0, r8
 *   @0x104d64 bl 0x27d1d0 <_ZdlPv>
 *   @0x104d68 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x104d6c mov r0, r8
 *   @0x104d70 bl 0x27d1d0 <_ZdlPv>
 *   @0x104d74 b 0x104cac <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x2f8>
 *   @0x104d78 mlaeq lr, r4, r2, sp
 *   @0x104d7c .word 0xffffc240
 *   @0x104d80 .word 0xffffc238
 *   @0x104d84 .word 0xffffc234
 *   @0x104d88 eoreq r3, r3, r4, asr #1
 *   @0x104d8c .word 0xffffbcf0
 *   @0x104d90 eoreq r3, r3, r8, lsr #21
 *
 * ══ §2/33 anon_190490  0x190490  size 992  248 条（0x190490..0x190870）
 * @func 0x190490 0x190870  size 992  248 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1904d0→0x5356c4, 0x19054c→0x756d44, 0x19056c→0x5356c0, 0x19059c→0x3eb70c, 0x190808→0x3eb70c
 * 调用序列: getJNIEnv×13 / _JNIEnv::CallStaticObjectMethod(_jclass*, _jmethodID*, ...)×3 / GMGamePad::SetDeviceId(char const*)×2 / 0xb65bc×2 / anon_190490+0x350 / _JNIEnv::CallStaticBooleanMethod(_jclass*, _jmethodID*, ...) / SetupGMLMappings(int) / GMGamePad::SetConnected(bool)
 * 字段偏移 top8: 0x-50×11 / 0x-30×4 / 0x-38×3 / 0x-34×3 / 0x314×3 / 0xc×3 / 0x-28×2 / 0x-48×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x190490 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x190494 add r11, sp, #32
 *   @0x190498 ldr r7, [pc, #0x3a0]
 *   @0x19049c sub sp, sp, #52
 *   @0x1904a0 ldr r2, [pc, #0x39c]
 *   @0x1904a4 add r7, pc, r7
 *   @0x1904a8 ldr r3, [pc, #0x398]
 *   @0x1904ac ldr r2, [r7, r2]
 *   @0x1904b0 add r3, pc, r3
 *   @0x1904b4 str r2, [r11, #-0x38]
 *   @0x1904b8 ldr r12, [r11, #-0x38]
 *   @0x1904bc ldr r2, [r3]
 *   @0x1904c0 ldr r3, [r12]
 *   @0x1904c4 tst r2, #2
 *   @0x1904c8 str r3, [r11, #-0x28]
 *   @0x1904cc beq 0x1907e0 <_Z16SetupGMLMappingsi+0x60c>
 *   @0x1904d0 ldr r3, [pc, #0x374]
 *   @0x1904d4 ldr r3, [r7, r3]
 *   @0x1904d8 ldr r3, [r3]
 *   @0x1904dc cmp r3, #0
 *   @0x1904e0 str r3, [r11, #-0x34]
 *   @0x1904e4 ble 0x1907e0 <_Z16SetupGMLMappingsi+0x60c>
 *   @0x1904e8 ldr r12, [pc, #0x360]
 *   @0x1904ec mov r4, #0
 *   @0x1904f0 ldr r8, [pc, #0x35c]
 *   @0x1904f4 add r12, pc, r12
 *   @0x1904f8 str r12, [r11, #-0x48]
 *   @0x1904fc ldr r12, [pc, #0x354]
 *   @0x190500 add r8, pc, r8
 *   @0x190504 add r12, pc, r12
 *   @0x190508 str r12, [r11, #-0x4c]
 *   @0x19050c ldr r12, [pc, #0x348]
 *   @0x190510 add r12, pc, r12
 *   @0x190514 str r12, [r11, #-0x3c]
 *   @0x190518 ldr r12, [pc, #0x340]
 *   @0x19051c add r12, pc, r12
 *   @0x190520 str r12, [r11, #-0x40]
 *   @0x190524 ldr r12, [pc, #0x338]
 *   @0x190528 add r12, pc, r12
 *   @0x19052c str r12, [r11, #-0x44]
 *   @0x190530 ldr r12, [r11, #-0x34]
 *   @0x190534 add r4, r4, #1
 *   @0x190538 cmp r4, r12
 *   @0x19053c beq 0x1907e0 <_Z16SetupGMLMappingsi+0x60c>
 *   @0x190540 cmp r4, #0
 *   @0x190544 beq 0x190530 <_Z16SetupGMLMappingsi+0x35c>
 *   @0x190548 bl 0x290274 <getJNIEnv>
 *   @0x19054c ldr r1, [pc, #0x314]
 *   @0x190550 mov r3, r4
 *   @0x190554 ldr r2, [r8, #0x8]
 *   @0x190558 lsl r9, r4, #2
 *   @0x19055c ldr r1, [r7, r1]
 *   @0x190560 str r1, [r11, #-0x30]
 *   @0x190564 ldr r1, [r1]
 *   @0x190568 bl 0x15e0b0 <_ZN7_JNIEnv23CallStaticBooleanMethodEP7_jclassP10_jmethodIDz>
 *   @0x19056c ldr r3, [pc, #0x2f8]
 *   @0x190570 ldr r12, [r7, r3]
 *   @0x190574 ldr r3, [r12]
 *   @0x190578 ldr r5, [r3, r4, lsl #2]
 *   @0x19057c cmp r5, #0
 *   @0x190580 mov r6, r0
 *   @0x190584 beq 0x190530 <_Z16SetupGMLMappingsi+0x35c>
 *   @0x190588 ldrb r3, [r5]
 *   @0x19058c cmp r3, r0
 *   @0x190590 beq 0x190668 <_Z16SetupGMLMappingsi+0x494>
 *   @0x190594 cmp r0, #0
 *   @0x190598 beq 0x1907fc <_Z16SetupGMLMappingsi+0x628>
 *   @0x19059c ldr r0, [pc, #0x2cc]
 *   @0x1905a0 mov r2, r4
 *   @0x1905a4 ldr r1, [r11, #-0x44]
 *   @0x1905a8 add r3, r5, #44
 *   @0x1905ac ldr r0, [r7, r0]
 *   @0x1905b0 ldr r0, [r0]
 *   @0x1905b4 ldr lr, [r0]
 *   @0x1905b8 ldr r10, [lr, #0xc]
 *   @0x1905bc str r12, [r11, #-0x50]
 *   @0x1905c0 blx r10
 *   @0x1905c4 mov r0, r4
 *   @0x1905c8 bl 0x1901d4 <_Z16SetupGMLMappingsi>
 *   @0x1905cc bl 0x290274 <getJNIEnv>
 *   @0x1905d0 ldr r3, [r11, #-0x30]
 *   @0x1905d4 ldr r2, [r8, #0xc]
 *   @0x1905d8 ldr r1, [r3]
 *   @0x1905dc mov r3, r4
 *   @0x1905e0 bl 0xf2840 <_ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz>
 *   @0x1905e4 mov r10, r0
 *   @0x1905e8 bl 0x290274 <getJNIEnv>
 *   @0x1905ec mov r1, r10
 *   @0x1905f0 mov r2, #0
 *   @0x1905f4 ldr r3, [r0]
 *   @0x1905f8 ldr r3, [r3, #0x2a4]
 *   @0x1905fc blx r3
 *   @0x190600 ldr r12, [r11, #-0x50]
 *   @0x190604 ldr r3, [r12]
 *   @0x190608 mov r2, r0
 *   @0x19060c mov r1, r0
 *   @0x190610 ldr r0, [r3, r9]
 *   @0x190614 str r2, [r11, #-0x50]
 *   @0x190618 bl 0x18e944 <_ZN9GMGamePad11SetDeviceIdEPKc>
 *   @0x19061c ldr r2, [r11, #-0x50]
 *   @0x190620 cmp r2, #0
 *   @0x190624 cmpne r10, #0
 *   @0x190628 beq 0x190658 <_Z16SetupGMLMappingsi+0x484>
 *   @0x19062c bl 0x290274 <getJNIEnv>
 *   @0x190630 mov r1, r10
 *   @0x190634 ldr r2, [r11, #-0x50]
 *   @0x190638 ldr r3, [r0]
 *   @0x19063c ldr r3, [r3, #0x2a8]
 *   @0x190640 blx r3
 *   @0x190644 bl 0x290274 <getJNIEnv>
 *   @0x190648 mov r1, r10
 *   @0x19064c ldr r3, [r0]
 *   @0x190650 ldr r3, [r3, #0x5c]
 *   @0x190654 blx r3
 *   @0x190658 adds r1, r6, #0
 *   @0x19065c mov r0, r5
 *   @0x190660 movne r1, #1
 *   @0x190664 bl 0x18e7f4 <_ZN9GMGamePad12SetConnectedEb>
 *   @0x190668 cmp r6, #0
 *   @0x19066c beq 0x190530 <_Z16SetupGMLMappingsi+0x35c>
 *   @0x190670 bl 0x290274 <getJNIEnv>
 *   @0x190674 ldr r12, [r11, #-0x30]
 *   @0x190678 mov r3, r4
 *   @0x19067c ldr r1, [r12]
 *   @0x190680 ldr r12, [r11, #-0x48]
 *   @0x190684 ldr r2, [r12, #0x10]
 *   @0x190688 bl 0xf2840 <_ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz>
 *   @0x19068c subs r6, r0, #0
 *   @0x190690 beq 0x190834 <_Z16SetupGMLMappingsi+0x660>
 *   @0x190694 bl 0x290274 <getJNIEnv>
 *   @0x190698 mov r1, r6
 *   @0x19069c ldr r3, [r0]
 *   @0x1906a0 ldr r3, [r3, #0x2ac]
 *   @0x1906a4 blx r3
 *   @0x1906a8 cmp r0, #0
 *   @0x1906ac ble 0x190834 <_Z16SetupGMLMappingsi+0x660>
 *   @0x1906b0 lsl r3, r0, #2
 *   @0x1906b4 str r3, [r11, #-0x50]
 *   @0x1906b8 add r2, r3, #14
 *   @0x1906bc bic r2, r2, #7
 *   @0x1906c0 sub sp, sp, r2
 *   @0x1906c4 bl 0x290274 <getJNIEnv>
 *   @0x1906c8 mov r1, r6
 *   @0x1906cc mov r2, #0
 *   @0x1906d0 mov r9, sp
 *   @0x1906d4 ldr r12, [r0]
 *   @0x1906d8 ldr r12, [r12, #0x2f4]
 *   @0x1906dc blx r12
 *   @0x1906e0 ldr r3, [r11, #-0x50]
 *   @0x1906e4 mov r2, r3
 *   @0x1906e8 mov r10, r0
 *   @0x1906ec mov r0, sp
 *   @0x1906f0 mov r1, r10
 *   @0x1906f4 bl 0xb65bc <memcpy@plt>
 *   @0x1906f8 bl 0x290274 <getJNIEnv>
 *   @0x1906fc mov r2, r10
 *   @0x190700 mov r1, r6
 *   @0x190704 mov r3, #0
 *   @0x190708 ldr r12, [r0]
 *   @0x19070c ldr r12, [r12, #0x314]
 *   @0x190710 blx r12
 *   @0x190714 bl 0x290274 <getJNIEnv>
 *   @0x190718 ldr r12, [r11, #-0x30]
 *   @0x19071c mov r3, r4
 *   @0x190720 ldr r1, [r12]
 *   @0x190724 ldr r12, [r11, #-0x4c]
 *   @0x190728 ldr r2, [r12, #0x14]
 *   @0x19072c bl 0xf2840 <_ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz>
 *   @0x190730 subs r6, r0, #0
 *   @0x190734 beq 0x19082c <_Z16SetupGMLMappingsi+0x658>
 *   @0x190738 bl 0x290274 <getJNIEnv>
 *   @0x19073c mov r1, r6
 *   @0x190740 ldr r3, [r0]
 *   @0x190744 ldr r3, [r3, #0x2ac]
 *   @0x190748 blx r3
 *   @0x19074c cmp r0, #0
 *   @0x190750 ble 0x19082c <_Z16SetupGMLMappingsi+0x658>
 *   @0x190754 lsl r12, r0, #2
 *   @0x190758 str r12, [r11, #-0x50]
 *   @0x19075c add r3, r12, #14
 *   @0x190760 bic r3, r3, #7
 *   @0x190764 sub sp, sp, r3
 *   @0x190768 bl 0x290274 <getJNIEnv>
 *   @0x19076c mov r1, r6
 *   @0x190770 mov r2, #0
 *   @0x190774 mov r10, sp
 *   @0x190778 ldr r3, [r0]
 *   @0x19077c ldr r3, [r3, #0x2f4]
 *   @0x190780 blx r3
 *   @0x190784 ldr r12, [r11, #-0x50]
 *   @0x190788 mov r2, r12
 *   @0x19078c mov r3, r0
 *   @0x190790 mov r0, sp
 *   @0x190794 mov r1, r3
 *   @0x190798 str r3, [r11, #-0x50]
 *   @0x19079c bl 0xb65bc <memcpy@plt>
 *   @0x1907a0 bl 0x290274 <getJNIEnv>
 *   @0x1907a4 ldr r3, [r11, #-0x50]
 *   @0x1907a8 mov r1, r6
 *   @0x1907ac mov r2, r3
 *   @0x1907b0 mov r3, #0
 *   @0x1907b4 ldr r12, [r0]
 *   @0x1907b8 ldr r12, [r12, #0x314]
 *   @0x1907bc blx r12
 *   @0x1907c0 mov r0, r5
 *   @0x1907c4 mov r1, r9
 *   @0x1907c8 mov r2, r10
 *   @0x1907cc add r4, r4, #1
 *   @0x1907d0 bl 0x18ee74 <_ZN9GMGamePad6UpdateEPfS0_>
 *   @0x1907d4 ldr r12, [r11, #-0x34]
 *   @0x1907d8 cmp r4, r12
 *   @0x1907dc bne 0x190540 <_Z16SetupGMLMappingsi+0x36c>
 *   @0x1907e0 ldr r12, [r11, #-0x38]
 *   @0x1907e4 ldr r2, [r11, #-0x28]
 *   @0x1907e8 ldr r3, [r12]
 *   @0x1907ec cmp r2, r3
 *   @0x1907f0 bne 0x19083c <_Z16SetupGMLMappingsi+0x668>
 *   @0x1907f4 sub sp, r11, #32
 *   @0x1907f8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1907fc mov r0, r5
 *   @0x190800 ldr r1, [r11, #-0x3c]
 *   @0x190804 bl 0x18e944 <_ZN9GMGamePad11SetDeviceIdEPKc>
 *   @0x190808 ldr r3, [pc, #0x60]
 *   @0x19080c ldr r1, [r11, #-0x40]
 *   @0x190810 mov r2, r4
 *   @0x190814 ldr r3, [r7, r3]
 *   @0x190818 ldr r0, [r3]
 *   @0x19081c ldr r3, [r0]
 *   @0x190820 ldr r3, [r3, #0xc]
 *   @0x190824 blx r3
 *   @0x190828 b 0x190658 <_Z16SetupGMLMappingsi+0x484>
 *   @0x19082c mov r10, #0
 *   @0x190830 b 0x1907c0 <_Z16SetupGMLMappingsi+0x5ec>
 *   @0x190834 mov r9, #0
 *   @0x190838 b 0x190714 <_Z16SetupGMLMappingsi+0x540>
 *   @0x19083c bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x190840 eoreq r1, r6, r12, lsr #15
 *   @0x190844 .word 0xffffbd00
 *   @0x190848 eorseq r5, r10, r8, ror r3
 *   @0x19084c .word 0xffffde10
 *   @0x190850 eorseq r5, r10, r4, lsr r3
 *   @0x190854 eorseq r5, r10, r8, lsr #6
 *   @0x190858 eorseq r5, r10, r4, lsr #6
 *   @0x19085c andseq lr, r9, r6, lsr #12
 *   @0x190860 mulseq r11, r12, r0
 *   @0x190864 andseq r12, r11, r8, rrx
 *   @0x190868 .word 0xffffbd54
 *   @0x19086c .word 0xffffde14
 *
 * ══ §3/33 b2CollidePolygonAndCircle(b2Manifold*, b2PolygonShape const*, b2Transform const&, b2CircleShape const*, b2Transform const&)  0x2dcad0  size 992  248 条（0x2dcad0..0x2dceb0）
 * @func 0x2dcad0 0x2dceb0  size 992  248 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6700×2 / b2CollidePolygonAndCircle(b2Manifold*, b2PolygonShape const*, b2Transform const&, b2CircleShape const*, b2Transform const&)+0x224 / b2CollidePolygonAndCircle(b2Manifold*, b2PolygonShape const*, b2Transform const&, b2CircleShape const*, b2Transform const&)+0x290 / b2CollidePolygonAndCircle(b2Manifold*, b2PolygonShape const*, b2Transform const&, b2CircleShape const*, b2Transform const&)+0x31c
 * 字段偏移 top8: 0x3c×5 / 0x38×4 / 0x10×4 / 0x4×4 / 0x30×1 / 0x94×1
 * VFP 指令 151 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2dcad0 push {r4, r5, r6, r7, r8, lr}
 *   @0x2dcad4 vpush {d8, d9}
 *   @0x2dcad8 sub sp, sp, #8
 *   @0x2dcadc vldr s6, [r3, #16]
 *   @0x2dcae0 vldr s11, [r3, #12]
 *   @0x2dcae4 vldr s2, [r2, #4]
 *   @0x2dcae8 ldr r12, [sp, #0x30]
 *   @0x2dcaec vldr s10, [r12, #12]
 *   @0x2dcaf0 vmul.f32 s14, s10, s6
 *   @0x2dcaf4 vldr s7, [r12, #8]
 *   @0x2dcaf8 vldr s9, [r12, #4]
 *   @0x2dcafc vldr s3, [r12]
 *   @0x2dcb00 vldr s12, [r2, #8]
 *   @0x2dcb04 vldr s13, [r2, #12]
 *   @0x2dcb08 vldr s4, [r2]
 *   @0x2dcb0c ldr r5, [r1, #0x94]
 *   @0x2dcb10 mov r4, #0
 *   @0x2dcb14 vldr s5, [r1, #8]
 *   @0x2dcb18 cmp r5, r4
 *   @0x2dcb1c vldr s8, [r3, #8]
 *   @0x2dcb20 mov r7, r0
 *   @0x2dcb24 str r4, [r0, #0x3c]
 *   @0x2dcb28 add r8, r1, #84
 *   @0x2dcb2c add r0, r1, #20
 *   @0x2dcb30 vmul.f32 s15, s7, s6
 *   @0x2dcb34 vmla.f32 s14, s11, s7
 *   @0x2dcb38 vnmls.f32 s15, s10, s11
 *   @0x2dcb3c vadd.f32 s9, s14, s9
 *   @0x2dcb40 vsub.f32 s9, s9, s2
 *   @0x2dcb44 vadd.f32 s15, s15, s3
 *   @0x2dcb48 vmul.f32 s10, s9, s12
 *   @0x2dcb4c vmul.f32 s9, s9, s13
 *   @0x2dcb50 vsub.f32 s15, s15, s4
 *   @0x2dcb54 vadd.f32 s8, s5, s8
 *   @0x2dcb58 vmls.f32 s9, s12, s15
 *   @0x2dcb5c vmla.f32 s10, s15, s13
 *   @0x2dcb60 ble 0x2dccf4 <_Z25b2CollidePolygonAndCircleP10b2ManifoldPK14b2PolygonShapeRK11b2TransformPK13b2CircleShapeS6_+0x224>
 *   @0x2dcb64 vldr s15, [r1, #24]
 *   @0x2dcb68 vldr s12, [r1, #88]
 *   @0x2dcb6c vldr s13, [r1, #20]
 *   @0x2dcb70 vldr s14, [r1, #84]
 *   @0x2dcb74 vsub.f32 s15, s9, s15
 *   @0x2dcb78 vmul.f32 s15, s15, s12
 *   @0x2dcb7c vsub.f32 s13, s10, s13
 *   @0x2dcb80 vmla.f32 s15, s13, s14
 *   @0x2dcb84 vcmpe.f32 s8, s15
 *   @0x2dcb88 vmrs APSR_nzcv, fpscr
 *   @0x2dcb8c bmi 0x2dcce8 <_Z25b2CollidePolygonAndCircleP10b2ManifoldPK14b2PolygonShapeRK11b2TransformPK13b2CircleShapeS6_+0x218>
 *   @0x2dcb90 add r12, r1, #28
 *   @0x2dcb94 mov r6, r4
 *   @0x2dcb98 add r2, r1, #92
 *   @0x2dcb9c vldr s11, [pc, #772]
 *   @0x2dcba0 b 0x2dcbd8 <_Z25b2CollidePolygonAndCircleP10b2ManifoldPK14b2PolygonShapeRK11b2TransformPK13b2CircleShapeS6_+0x108>
 *   @0x2dcba4 vldr s15, [r12, #4]
 *   @0x2dcba8 vsub.f32 s15, s9, s15
 *   @0x2dcbac vldr s12, [r2, #4]
 *   @0x2dcbb0 vldr s13, [r12]
 *   @0x2dcbb4 vldr s14, [r2]
 *   @0x2dcbb8 add r12, r12, #8
 *   @0x2dcbbc add r2, r2, #8
 *   @0x2dcbc0 vmul.f32 s15, s15, s12
 *   @0x2dcbc4 vsub.f32 s13, s10, s13
 *   @0x2dcbc8 vmla.f32 s15, s13, s14
 *   @0x2dcbcc vcmpe.f32 s8, s15
 *   @0x2dcbd0 vmrs APSR_nzcv, fpscr
 *   @0x2dcbd4 bmi 0x2dcce8 <_Z25b2CollidePolygonAndCircleP10b2ManifoldPK14b2PolygonShapeRK11b2TransformPK13b2CircleShapeS6_+0x218>
 *   @0x2dcbd8 vcmpe.f32 s11, s15
 *   @0x2dcbdc vmrs APSR_nzcv, fpscr
 *   @0x2dcbe0 movmi r6, r4
 *   @0x2dcbe4 add r4, r4, #1
 *   @0x2dcbe8 vmovmi.f32 s11, s15
 *   @0x2dcbec cmp r4, r5
 *   @0x2dcbf0 bne 0x2dcba4 <_Z25b2CollidePolygonAndCircleP10b2ManifoldPK14b2PolygonShapeRK11b2TransformPK13b2CircleShapeS6_+0xd4>
 *   @0x2dcbf4 vldr s15, [pc, #688]
 *   @0x2dcbf8 vcmpe.f32 s11, s15
 *   @0x2dcbfc add r2, r6, #1
 *   @0x2dcc00 lsl r6, r6, #3
 *   @0x2dcc04 cmp r4, r2
 *   @0x2dcc08 lslgt r2, r2, #3
 *   @0x2dcc0c movle r2, #0
 *   @0x2dcc10 vmrs APSR_nzcv, fpscr
 *   @0x2dcc14 add r2, r0, r2
 *   @0x2dcc18 add r0, r0, r6
 *   @0x2dcc1c vldr s19, [r2]
 *   @0x2dcc20 vldr s17, [r0]
 *   @0x2dcc24 vldr s16, [r0, #4]
 *   @0x2dcc28 vldr s18, [r2, #4]
 *   @0x2dcc2c bmi 0x2dcd08 <_Z25b2CollidePolygonAndCircleP10b2ManifoldPK14b2PolygonShapeRK11b2TransformPK13b2CircleShapeS6_+0x238>
 *   @0x2dcc30 vsub.f32 s14, s9, s16
 *   @0x2dcc34 vsub.f32 s15, s18, s16
 *   @0x2dcc38 vmul.f32 s15, s14, s15
 *   @0x2dcc3c vsub.f32 s13, s10, s17
 *   @0x2dcc40 vsub.f32 s12, s19, s17
 *   @0x2dcc44 vmla.f32 s15, s13, s12
 *   @0x2dcc48 vcmpe.f32 s15, #0
 *   @0x2dcc4c vmrs APSR_nzcv, fpscr
 *   @0x2dcc50 bls 0x2dcd60 <_Z25b2CollidePolygonAndCircleP10b2ManifoldPK14b2PolygonShapeRK11b2TransformPK13b2CircleShapeS6_+0x290>
 *   @0x2dcc54 vsub.f32 s14, s9, s18
 *   @0x2dcc58 vsub.f32 s15, s16, s18
 *   @0x2dcc5c vmul.f32 s15, s14, s15
 *   @0x2dcc60 vsub.f32 s13, s10, s19
 *   @0x2dcc64 vsub.f32 s12, s17, s19
 *   @0x2dcc68 vmla.f32 s15, s13, s12
 *   @0x2dcc6c vcmpe.f32 s15, #0
 *   @0x2dcc70 vmrs APSR_nzcv, fpscr
 *   @0x2dcc74 bls 0x2dcdec <_Z25b2CollidePolygonAndCircleP10b2ManifoldPK14b2PolygonShapeRK11b2TransformPK13b2CircleShapeS6_+0x31c>
 *   @0x2dcc78 vmov.f32 s14, #5.000000e-01
 *   @0x2dcc7c add r6, r8, r6
 *   @0x2dcc80 vldr s15, [r6, #4]
 *   @0x2dcc84 vldr s12, [r6]
 *   @0x2dcc88 vadd.f32 s13, s18, s16
 *   @0x2dcc8c vmul.f32 s13, s13, s14
 *   @0x2dcc90 vadd.f32 s17, s17, s19
 *   @0x2dcc94 vsub.f32 s9, s9, s13
 *   @0x2dcc98 vmul.f32 s14, s17, s14
 *   @0x2dcc9c vmul.f32 s15, s9, s15
 *   @0x2dcca0 vsub.f32 s10, s10, s14
 *   @0x2dcca4 vmla.f32 s15, s10, s12
 *   @0x2dcca8 vcmpe.f32 s8, s15
 *   @0x2dccac vmrs APSR_nzcv, fpscr
 *   @0x2dccb0 bmi 0x2dcce8 <_Z25b2CollidePolygonAndCircleP10b2ManifoldPK14b2PolygonShapeRK11b2TransformPK13b2CircleShapeS6_+0x218>
 *   @0x2dccb4 ldm r6, {r0, r1}
 *   @0x2dccb8 add r3, r3, #12
 *   @0x2dccbc add r2, r7, #40
 *   @0x2dccc0 mov r12, #1
 *   @0x2dccc4 str r12, [r7, #0x3c]
 *   @0x2dccc8 mov r4, #0
 *   @0x2dcccc str r12, [r7, #0x38]
 *   @0x2dccd0 stm r2, {r0, r1}
 *   @0x2dccd4 vstr s14, [r7, #48]
 *   @0x2dccd8 vstr s13, [r7, #52]
 *   @0x2dccdc ldm r3, {r0, r1}
 *   @0x2dcce0 str r4, [r7, #0x10]
 *   @0x2dcce4 stm r7, {r0, r1}
 *   @0x2dcce8 add sp, sp, #8
 *   @0x2dccec vpop {d8, d9}
 *   @0x2dccf0 pop {r4, r5, r6, r7, r8, pc}
 *   @0x2dccf4 vldr s17, [r1, #20]
 *   @0x2dccf8 vldr s16, [r1, #24]
 *   @0x2dccfc vmov.f32 s19, s17
 *   @0x2dcd00 mov r6, r4
 *   @0x2dcd04 vmov.f32 s18, s16
 *   @0x2dcd08 add r6, r8, r6
 *   @0x2dcd0c add r3, r3, #12
 *   @0x2dcd10 add r2, r7, #40
 *   @0x2dcd14 mov r12, #1
 *   @0x2dcd18 vadd.f32 s17, s17, s19
 *   @0x2dcd1c ldm r6, {r0, r1}
 *   @0x2dcd20 str r12, [r7, #0x3c]
 *   @0x2dcd24 mov r4, #0
 *   @0x2dcd28 str r12, [r7, #0x38]
 *   @0x2dcd2c stm r2, {r0, r1}
 *   @0x2dcd30 vadd.f32 s16, s18, s16
 *   @0x2dcd34 vmov.f32 s15, #5.000000e-01
 *   @0x2dcd38 vmul.f32 s17, s17, s15
 *   @0x2dcd3c vmul.f32 s15, s16, s15
 *   @0x2dcd40 vstr s17, [r7, #48]
 *   @0x2dcd44 vstr s15, [r7, #52]
 *   @0x2dcd48 ldm r3, {r0, r1}
 *   @0x2dcd4c str r4, [r7, #0x10]
 *   @0x2dcd50 stm r7, {r0, r1}
 *   @0x2dcd54 add sp, sp, #8
 *   @0x2dcd58 vpop {d8, d9}
 *   @0x2dcd5c pop {r4, r5, r6, r7, r8, pc}
 *   @0x2dcd60 vmul.f32 s15, s14, s14
 *   @0x2dcd64 vmla.f32 s15, s13, s13
 *   @0x2dcd68 vmul.f32 s8, s8, s8
 *   @0x2dcd6c vcmpe.f32 s8, s15
 *   @0x2dcd70 vmrs APSR_nzcv, fpscr
 *   @0x2dcd74 bmi 0x2dcce8 <_Z25b2CollidePolygonAndCircleP10b2ManifoldPK14b2PolygonShapeRK11b2TransformPK13b2CircleShapeS6_+0x218>
 *   @0x2dcd78 vsqrt.f32 s12, s15
 *   @0x2dcd7c mov r2, #1
 *   @0x2dcd80 vstr s13, [r7, #40]
 *   @0x2dcd84 vstr s14, [r7, #44]
 *   @0x2dcd88 str r2, [r7, #0x3c]
 *   @0x2dcd8c str r2, [r7, #0x38]
 *   @0x2dcd90 vcmp.f32 s12, s12
 *   @0x2dcd94 vmrs APSR_nzcv, fpscr
 *   @0x2dcd98 bne 0x2dce90 <_Z25b2CollidePolygonAndCircleP10b2ManifoldPK14b2PolygonShapeRK11b2TransformPK13b2CircleShapeS6_+0x3c0>
 *   @0x2dcd9c vldr s15, [pc, #264]
 *   @0x2dcda0 vcmpe.f32 s12, s15
 *   @0x2dcda4 vmrs APSR_nzcv, fpscr
 *   @0x2dcda8 bmi 0x2dcdcc <_Z25b2CollidePolygonAndCircleP10b2ManifoldPK14b2PolygonShapeRK11b2TransformPK13b2CircleShapeS6_+0x2fc>
 *   @0x2dcdac vmov.f32 s13, #1.000000e+00
 *   @0x2dcdb0 vldr s15, [r7, #40]
 *   @0x2dcdb4 vldr s14, [r7, #44]
 *   @0x2dcdb8 vdiv.f32 s12, s13, s12
 *   @0x2dcdbc vmul.f32 s15, s15, s12
 *   @0x2dcdc0 vmul.f32 s12, s14, s12
 *   @0x2dcdc4 vstr s15, [r7, #40]
 *   @0x2dcdc8 vstr s12, [r7, #44]
 *   @0x2dcdcc add r3, r3, #12
 *   @0x2dcdd0 vstr s17, [r7, #48]
 *   @0x2dcdd4 vstr s16, [r7, #52]
 *   @0x2dcdd8 mov r2, #0
 *   @0x2dcddc ldm r3, {r0, r1}
 *   @0x2dcde0 str r2, [r7, #0x10]
 *   @0x2dcde4 stm r7, {r0, r1}
 *   @0x2dcde8 b 0x2dcce8 <_Z25b2CollidePolygonAndCircleP10b2ManifoldPK14b2PolygonShapeRK11b2TransformPK13b2CircleShapeS6_+0x218>
 *   @0x2dcdec vmul.f32 s15, s14, s14
 *   @0x2dcdf0 vmla.f32 s15, s13, s13
 *   @0x2dcdf4 vmul.f32 s8, s8, s8
 *   @0x2dcdf8 vcmpe.f32 s8, s15
 *   @0x2dcdfc vmrs APSR_nzcv, fpscr
 *   @0x2dce00 bmi 0x2dcce8 <_Z25b2CollidePolygonAndCircleP10b2ManifoldPK14b2PolygonShapeRK11b2TransformPK13b2CircleShapeS6_+0x218>
 *   @0x2dce04 vsqrt.f32 s12, s15
 *   @0x2dce08 mov r2, #1
 *   @0x2dce0c vstr s13, [r7, #40]
 *   @0x2dce10 vstr s14, [r7, #44]
 *   @0x2dce14 str r2, [r7, #0x3c]
 *   @0x2dce18 str r2, [r7, #0x38]
 *   @0x2dce1c vcmp.f32 s12, s12
 *   @0x2dce20 vmrs APSR_nzcv, fpscr
 *   @0x2dce24 bne 0x2dce78 <_Z25b2CollidePolygonAndCircleP10b2ManifoldPK14b2PolygonShapeRK11b2TransformPK13b2CircleShapeS6_+0x3a8>
 *   @0x2dce28 vldr s15, [pc, #124]
 *   @0x2dce2c vcmpe.f32 s12, s15
 *   @0x2dce30 vmrs APSR_nzcv, fpscr
 *   @0x2dce34 bmi 0x2dce58 <_Z25b2CollidePolygonAndCircleP10b2ManifoldPK14b2PolygonShapeRK11b2TransformPK13b2CircleShapeS6_+0x388>
 *   @0x2dce38 vmov.f32 s13, #1.000000e+00
 *   @0x2dce3c vldr s15, [r7, #40]
 *   @0x2dce40 vldr s14, [r7, #44]
 *   @0x2dce44 vdiv.f32 s12, s13, s12
 *   @0x2dce48 vmul.f32 s15, s15, s12
 *   @0x2dce4c vmul.f32 s12, s14, s12
 *   @0x2dce50 vstr s15, [r7, #40]
 *   @0x2dce54 vstr s12, [r7, #44]
 *   @0x2dce58 add r3, r3, #12
 *   @0x2dce5c vstr s19, [r7, #48]
 *   @0x2dce60 vstr s18, [r7, #52]
 *   @0x2dce64 mov r2, #0
 *   @0x2dce68 ldm r3, {r0, r1}
 *   @0x2dce6c str r2, [r7, #0x10]
 *   @0x2dce70 stm r7, {r0, r1}
 *   @0x2dce74 b 0x2dcce8 <_Z25b2CollidePolygonAndCircleP10b2ManifoldPK14b2PolygonShapeRK11b2TransformPK13b2CircleShapeS6_+0x218>
 *   @0x2dce78 vmov r0, s15
 *   @0x2dce7c str r3, [sp, #0x4]
 *   @0x2dce80 bl 0xb6700 <sqrtf@plt>
 *   @0x2dce84 ldr r3, [sp, #0x4]
 *   @0x2dce88 vmov s12, r0
 *   @0x2dce8c b 0x2dce28 <_Z25b2CollidePolygonAndCircleP10b2ManifoldPK14b2PolygonShapeRK11b2TransformPK13b2CircleShapeS6_+0x358>
 *   @0x2dce90 vmov r0, s15
 *   @0x2dce94 str r3, [sp, #0x4]
 *   @0x2dce98 bl 0xb6700 <sqrtf@plt>
 *   @0x2dce9c ldr r3, [sp, #0x4]
 *   @0x2dcea0 vmov s12, r0
 *   @0x2dcea4 b 0x2dcd9c <_Z25b2CollidePolygonAndCircleP10b2ManifoldPK14b2PolygonShapeRK11b2TransformPK13b2CircleShapeS6_+0x2cc>
 *   @0x2dcea8 .word 0xff7fffff
 *   @0x2dceac strlo r0, [r0], #-0
 *
 * ══ §4/33 COggAudio::SyncDrawDebug()  0x226a10  size 988  247 条（0x226a10..0x226dec）
 * @func 0x226a10 0x226dec  size 988  247 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GraphicsPerf::oprintf(float, float, unsigned int, unsigned int, char const*, ...)×4 / 0xb6a9c×3 / ov_pcm_total×3 / GraphicsPerf::RenderRectangle(float, float, float, float, unsigned int)×2 / COggAudio::SyncDrawDebug()+0x180 / COggAudio::SyncDrawDebug()+0x318 / COggAudio::SyncDrawDebug()+0x394 / COggAudio::SyncDrawDebug()+0x37c
 * 字段偏移 top8: 0x38×6 / 0x804×6 / 0x4×4 / 0x8×4 / 0x80c×3 / 0x86c×3 / 0x2bc×3 / 0x3c×3
 * VFP 指令 36 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x226a10 ldr r3, [r0, #0x1c]
 *   @0x226a14 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x226a18 vpush {d8, d9, d10}
 *   @0x226a1c cmn r3, #1
 *   @0x226a20 sub sp, sp, #76
 *   @0x226a24 str r0, [sp, #0x38]
 *   @0x226a28 beq 0x226ca0 <_ZN9COggAudio13SyncDrawDebugEv+0x290>
 *   @0x226a2c ldr r2, [r0, #0x4]
 *   @0x226a30 cmp r3, r2
 *   @0x226a34 bge 0x226c70 <_ZN9COggAudio13SyncDrawDebugEv+0x260>
 *   @0x226a38 ldr r2, [r0, #0x10]
 *   @0x226a3c ldr r4, [r2, r3, lsl #2]
 *   @0x226a40 cmp r4, #0
 *   @0x226a44 beq 0x226c70 <_ZN9COggAudio13SyncDrawDebugEv+0x260>
 *   @0x226a48 ldr r12, [sp, #0x38]
 *   @0x226a4c vldr s20, [pc, #876]
 *   @0x226a50 ldr r0, [pc, #0x37c]
 *   @0x226a54 mov r2, #-16777216
 *   @0x226a58 ldr r10, [pc, #0x378]
 *   @0x226a5c mov r7, #0
 *   @0x226a60 ldr r1, [r12, #0x8]
 *   @0x226a64 add r0, pc, r0
 *   @0x226a68 str r3, [sp, #0x8]
 *   @0x226a6c mvn r3, #0
 *   @0x226a70 str r0, [sp]
 *   @0x226a74 str r1, [sp, #0x4]
 *   @0x226a78 ldr r0, [r4, #0x80c]
 *   @0x226a7c vmov r1, s20
 *   @0x226a80 str r0, [sp, #0xc]
 *   @0x226a84 mov r0, #0
 *   @0x226a88 ldr r12, [r4, #0x828]
 *   @0x226a8c movt r0, #0x4120
 *   @0x226a90 str r12, [sp, #0x10]
 *   @0x226a94 bl 0x17c2f8 <_ZN12GraphicsPerf7oprintfEffjjPKcz>
 *   @0x226a98 ldr r10, [pc, r10]
 *   @0x226a9c vldr s15, [r10]
 *   @0x226aa0 vadd.f32 s15, s15, s15
 *   @0x226aa4 add r2, sp, #72
 *   @0x226aa8 ldr r0, [r4, #0x86c]
 *   @0x226aac movw r1, #0x1015
 *   @0x226ab0 str r7, [r2, #-0x8]!
 *   @0x226ab4 vadd.f32 s15, s15, s20
 *   @0x226ab8 vmov r5, s15
 *   @0x226abc bl 0xb6a9c <alGetSourcei@plt>
 *   @0x226ac0 ldr r3, [sp, #0x40]
 *   @0x226ac4 ldr r6, [r10]
 *   @0x226ac8 cmp r3, r7
 *   @0x226acc addle r8, sp, #68
 *   @0x226ad0 ble 0x226b90 <_ZN9COggAudio13SyncDrawDebugEv+0x180>
 *   @0x226ad4 vmov.f32 s16, #1.000000e+01
 *   @0x226ad8 mov r9, #255
 *   @0x226adc add r8, sp, #68
 *   @0x226ae0 movt r9, #0xff00
 *   @0x226ae4 mov r11, r7
 *   @0x226ae8 mvn r7, #0
 *   @0x226aec vldr s19, [pc, #720]
 *   @0x226af0 vldr s17, [pc, #720]
 *   @0x226af4 str r7, [sp]
 *   @0x226af8 mov r1, r5
 *   @0x226afc vmov r0, s16
 *   @0x226b00 mov r2, #0
 *   @0x226b04 mov r3, r6
 *   @0x226b08 movt r2, #0x42c8
 *   @0x226b0c bl 0x17b83c <_ZN12GraphicsPerf15RenderRectangleEffffj>
 *   @0x226b10 cmp r11, #0
 *   @0x226b14 bne 0x226b7c <_ZN9COggAudio13SyncDrawDebugEv+0x16c>
 *   @0x226b18 ldr r3, [r4, #0x804]
 *   @0x226b1c mov r1, #0
 *   @0x226b20 mov r2, r8
 *   @0x226b24 ldr r3, [r3, #0x2bc]
 *   @0x226b28 cmp r3, #0
 *   @0x226b2c vldrne s18, [r3, #60]
 *   @0x226b30 str r1, [sp, #0x44]
 *   @0x226b34 movw r1, #0x1025
 *   @0x226b38 ldr r0, [r4, #0x86c]
 *   @0x226b3c vldreq s18, [pc, #648]
 *   @0x226b40 bl 0xb6a9c <alGetSourcei@plt>
 *   @0x226b44 vldr s13, [sp, #68]
 *   @0x226b48 vcvt.f32.s32 s15, s13
 *   @0x226b4c str r9, [sp]
 *   @0x226b50 mov r1, r5
 *   @0x226b54 mov r2, #1065353216
 *   @0x226b58 mov r3, r6
 *   @0x226b5c vmul.f32 s15, s15, s20
 *   @0x226b60 vadd.f32 s15, s15, s15
 *   @0x226b64 vcvt.f32.s32 s14, s18
 *   @0x226b68 vmul.f32 s15, s15, s14
 *   @0x226b6c vmov.f32 s14, s16
 *   @0x226b70 vmla.f32 s14, s15, s19
 *   @0x226b74 vmov r0, s14
 *   @0x226b78 bl 0x17b83c <_ZN12GraphicsPerf15RenderRectangleEffffj>
 *   @0x226b7c ldr r3, [sp, #0x40]
 *   @0x226b80 add r11, r11, #1
 *   @0x226b84 vadd.f32 s16, s16, s17
 *   @0x226b88 cmp r3, r11
 *   @0x226b8c bgt 0x226af4 <_ZN9COggAudio13SyncDrawDebugEv+0xe4>
 *   @0x226b90 ldr r1, [pc, #0x244]
 *   @0x226b94 mov r2, #-16777216
 *   @0x226b98 str r3, [sp, #0x4]
 *   @0x226b9c mov r0, #0
 *   @0x226ba0 mvn r3, #0
 *   @0x226ba4 add r1, pc, r1
 *   @0x226ba8 movt r0, #0x4120
 *   @0x226bac str r1, [sp]
 *   @0x226bb0 mov r1, r5
 *   @0x226bb4 bl 0x17c2f8 <_ZN12GraphicsPerf7oprintfEffjjPKcz>
 *   @0x226bb8 vldr s16, [r10]
 *   @0x226bbc vadd.f32 s16, s16, s16
 *   @0x226bc0 mov r2, r8
 *   @0x226bc4 vmov s15, r5
 *   @0x226bc8 ldr r0, [r4, #0x86c]
 *   @0x226bcc movw r1, #0x1010
 *   @0x226bd0 vadd.f32 s16, s16, s15
 *   @0x226bd4 bl 0xb6a9c <alGetSourcei@plt>
 *   @0x226bd8 ldr r3, [r4, #0x80c]
 *   @0x226bdc cmp r3, #0
 *   @0x226be0 ble 0x226d28 <_ZN9COggAudio13SyncDrawDebugEv+0x318>
 *   @0x226be4 ldr r12, [pc, #0x1f4]
 *   @0x226be8 mov r5, #0
 *   @0x226bec mov r7, r5
 *   @0x226bf0 vldr s17, [pc, #472]
 *   @0x226bf4 add r12, pc, r12
 *   @0x226bf8 str r12, [sp, #0x3c]
 *   @0x226bfc ldr r12, [pc, #0x1e0]
 *   @0x226c00 add r12, pc, r12
 *   @0x226c04 str r12, [sp, #0x34]
 *   @0x226c08 ldr r3, [r4, #0x804]
 *   @0x226c0c add r0, r3, r5
 *   @0x226c10 ldr r1, [r0, #0x2bc]
 *   @0x226c14 cmp r1, #0
 *   @0x226c18 beq 0x226d80 <_ZN9COggAudio13SyncDrawDebugEv+0x370>
 *   @0x226c1c ldr r8, [r1, #0x38]
 *   @0x226c20 ldr r9, [r1, #0x3c]
 *   @0x226c24 cmp r8, #0
 *   @0x226c28 ble 0x226da4 <_ZN9COggAudio13SyncDrawDebugEv+0x394>
 *   @0x226c2c vldr s15, [r1, #4]
 *   @0x226c30 vcmpe.f32 s15, s17
 *   @0x226c34 ldr r11, [r1]
 *   @0x226c38 vmrs APSR_nzcv, fpscr
 *   @0x226c3c ble 0x226d8c <_ZN9COggAudio13SyncDrawDebugEv+0x37c>
 *   @0x226c40 mov r6, #65280
 *   @0x226c44 bfi r6, r6, #16, #16
 *   @0x226c48 ldr r2, [sp, #0x44]
 *   @0x226c4c sub r2, r2, #4096
 *   @0x226c50 sub r2, r2, #17
 *   @0x226c54 cmp r2, #3
 *   @0x226c58 addls pc, pc, r2, lsl #2
 *   @0x226c5c b 0x226d98 <_ZN9COggAudio13SyncDrawDebugEv+0x388>
 *   @0x226c60 b 0x226cac <_ZN9COggAudio13SyncDrawDebugEv+0x29c>
 *   @0x226c64 b 0x226d70 <_ZN9COggAudio13SyncDrawDebugEv+0x360>
 *   @0x226c68 b 0x226d58 <_ZN9COggAudio13SyncDrawDebugEv+0x348>
 *   @0x226c6c b 0x226d44 <_ZN9COggAudio13SyncDrawDebugEv+0x334>
 *   @0x226c70 ldr r1, [sp, #0x38]
 *   @0x226c74 mov r0, #0
 *   @0x226c78 mov r2, #-16777216
 *   @0x226c7c mvn r3, #0
 *   @0x226c80 movt r0, #0x4120
 *   @0x226c84 ldr r12, [r1, #0x8]
 *   @0x226c88 ldr r1, [pc, #0x158]
 *   @0x226c8c add r1, pc, r1
 *   @0x226c90 stm sp, {r1, r12}
 *   @0x226c94 mov r1, #0
 *   @0x226c98 movt r1, #0x42c8
 *   @0x226c9c bl 0x17c2f8 <_ZN12GraphicsPerf7oprintfEffjjPKcz>
 *   @0x226ca0 add sp, sp, #76
 *   @0x226ca4 vpop {d8, d9, d10}
 *   @0x226ca8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x226cac mov r0, #0
 *   @0x226cb0 mov r1, #0
 *   @0x226cb4 mvn r6, #16711680
 *   @0x226cb8 add r3, r3, r5
 *   @0x226cbc ldr r12, [sp, #0x34]
 *   @0x226cc0 add r3, r3, #752
 *   @0x226cc4 mov lr, #2080
 *   @0x226cc8 add r5, r5, #768
 *   @0x226ccc ldrd r2, r3, [r3]
 *   @0x226cd0 str r12, [sp]
 *   @0x226cd4 str r7, [sp, #0x4]
 *   @0x226cd8 add r7, r7, #1
 *   @0x226cdc strd r2, r3, [sp, #32]
 *   @0x226ce0 str r11, [sp, #0x8]
 *   @0x226ce4 strd r0, r1, [sp, #16]
 *   @0x226ce8 str r9, [sp, #0x18]
 *   @0x226cec str r8, [sp, #0x1c]
 *   @0x226cf0 ldrd r0, r1, [r4, lr]
 *   @0x226cf4 bl 0x319414 <__aeabi_ldivmod>
 *   @0x226cf8 vmov r1, s16
 *   @0x226cfc mov r0, #0
 *   @0x226d00 movt r0, #0x4120
 *   @0x226d04 strd r2, r3, [sp, #40]
 *   @0x226d08 mov r3, r6
 *   @0x226d0c mov r2, #-16777216
 *   @0x226d10 bl 0x17c2f8 <_ZN12GraphicsPerf7oprintfEffjjPKcz>
 *   @0x226d14 ldr r3, [r4, #0x80c]
 *   @0x226d18 vldr s15, [r10]
 *   @0x226d1c vadd.f32 s16, s16, s15
 *   @0x226d20 cmp r3, r7
 *   @0x226d24 bgt 0x226c08 <_ZN9COggAudio13SyncDrawDebugEv+0x1f8>
 *   @0x226d28 mov r0, r4
 *   @0x226d2c bl 0x224c34 <_Z18UpdateTimingEventsP14COggSyncThread>
 *   @0x226d30 mov r0, r4
 *   @0x226d34 bl 0x224cdc <_Z16DrawTimingEventsP14COggSyncThread>
 *   @0x226d38 add sp, sp, #76
 *   @0x226d3c vpop {d8, d9, d10}
 *   @0x226d40 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x226d44 mvn r1, #0
 *   @0x226d48 mvn r6, #65280
 *   @0x226d4c bl 0x23138c <ov_pcm_total>
 *   @0x226d50 ldr r3, [r4, #0x804]
 *   @0x226d54 b 0x226cb8 <_ZN9COggAudio13SyncDrawDebugEv+0x2a8>
 *   @0x226d58 mvn r1, #0
 *   @0x226d5c mov r6, #0
 *   @0x226d60 bl 0x23138c <ov_pcm_total>
 *   @0x226d64 movt r6, #0xffff
 *   @0x226d68 ldr r3, [r4, #0x804]
 *   @0x226d6c b 0x226cb8 <_ZN9COggAudio13SyncDrawDebugEv+0x2a8>
 *   @0x226d70 mvn r1, #0
 *   @0x226d74 bl 0x23138c <ov_pcm_total>
 *   @0x226d78 ldr r3, [r4, #0x804]
 *   @0x226d7c b 0x226cb8 <_ZN9COggAudio13SyncDrawDebugEv+0x2a8>
 *   @0x226d80 ldr r11, [sp, #0x3c]
 *   @0x226d84 mov r9, #1
 *   @0x226d88 movw r8, #0xac44
 *   @0x226d8c mov r6, #255
 *   @0x226d90 movt r6, #0xff00
 *   @0x226d94 b 0x226c48 <_ZN9COggAudio13SyncDrawDebugEv+0x238>
 *   @0x226d98 mov r0, #0
 *   @0x226d9c mov r1, #0
 *   @0x226da0 b 0x226cb8 <_ZN9COggAudio13SyncDrawDebugEv+0x2a8>
 *   @0x226da4 ldr r0, [sp, #0x38]
 *   @0x226da8 bl 0x22688c <_ZN9COggAudio13CalcSoundInfoEP12cAudio_Sound>
 *   @0x226dac ldr r3, [r4, #0x804]
 *   @0x226db0 add r0, r3, r5
 *   @0x226db4 ldr r1, [r0, #0x2bc]
 *   @0x226db8 ldr r8, [r1, #0x38]
 *   @0x226dbc b 0x226c2c <_ZN9COggAudio13SyncDrawDebugEv+0x21c>
 *   @0x226dc0 sbcmi r0, r8, #0
 *   @0x226dc4 .word 0x38800000
 *   @0x226dc8 sbcsmi r0, r2, #0
 *   @0x226dcc andeq r0, r0, r1
 *   @0x226dd0 stclo p7, c13, [r3], #-40
 *   @0x226dd4 andseq lr, r2, r0, ror #9
 *   @0x226dd8 mulseq r12, r12, r8
 *   @0x226ddc ldrsbeq lr, [r2], -r4
 *   @0x226de0 andseq lr, r2, r4, lsr r3
 *   @0x226de4 andseq lr, r2, r12, lsl #7
 *   @0x226de8 andseq lr, r2, r4, lsr #5
 *
 * ══ §5/33 JS_NumberObjectSetup()  0x2445a8  size 988  247 条（0x2445a8..0x244984）
 * @func 0x2445a8 0x244984  size 988  247 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x2445d0→0x756424, 0x2445ec→0x756450, 0x2448a8→0x544be0
 * 调用序列: YYObjectBase::Add(char const*, YYObjectBase*, int)×8 / JS_SetupFunction(void (*)(RValue&, CInstance*, CInstance*, int, RValue*), int, bool)×7 / YYObjectBase::Add(char const*, RValue&, int)×6 / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)×3 / YYObjectBase::InternalGetYYVar(int)×3 / JS_StandardBuiltInObjectConstructor(RValue&, CInstance*, CInstance*, int, RValue*)
 * 字段偏移 top8: 0x4×3 / 0x8×2 / 0x40×2 / 0x18×2 / 0x28×2 / 0x1f4×2 / 0x348×1 / 0x344×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2445a8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2445ac sub sp, sp, #124
 *   @0x2445b0 mov r6, #0
 *   @0x2445b4 add r0, sp, #8
 *   @0x2445b8 mov r1, r6
 *   @0x2445bc mov r2, r6
 *   @0x2445c0 mov r3, r6
 *   @0x2445c4 str r6, [sp]
 *   @0x2445c8 ldr r8, [pc, #0x348]
 *   @0x2445cc bl 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_>
 *   @0x2445d0 ldr r3, [pc, #0x344]
 *   @0x2445d4 mov r4, #0
 *   @0x2445d8 add r8, pc, r8
 *   @0x2445dc ldr r11, [sp, #0x8]
 *   @0x2445e0 ldr r2, [pc, #0x338]
 *   @0x2445e4 mov r5, #0
 *   @0x2445e8 ldr r10, [r8, r3]
 *   @0x2445ec ldr r3, [pc, #0x330]
 *   @0x2445f0 add r2, pc, r2
 *   @0x2445f4 str r2, [r11, #0x40]
 *   @0x2445f8 mov r0, r11
 *   @0x2445fc str r11, [r10]
 *   @0x244600 ldr r9, [r8, r3]
 *   @0x244604 ldr r1, [r9]
 *   @0x244608 str r1, [r11, #0x18]
 *   @0x24460c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x244610 ldr r3, [pc, #0x310]
 *   @0x244614 ldr r0, [r11, #0x28]
 *   @0x244618 mov r1, r6
 *   @0x24461c mov r2, r6
 *   @0x244620 orr r0, r0, #1
 *   @0x244624 str r0, [r11, #0x28]
 *   @0x244628 ldr r0, [r8, r3]
 *   @0x24462c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x244630 ldr r1, [pc, #0x2f4]
 *   @0x244634 mov r3, #6
 *   @0x244638 add r1, pc, r1
 *   @0x24463c mov r2, r0
 *   @0x244640 mov r0, r11
 *   @0x244644 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x244648 ldr r3, [pc, #0x2e0]
 *   @0x24464c mov r1, r6
 *   @0x244650 mov r2, r6
 *   @0x244654 ldr r0, [r8, r3]
 *   @0x244658 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x24465c ldr r1, [pc, #0x2d0]
 *   @0x244660 mov r3, #6
 *   @0x244664 add r1, pc, r1
 *   @0x244668 mov r2, r0
 *   @0x24466c mov r0, r11
 *   @0x244670 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x244674 ldr r3, [pc, #0x2bc]
 *   @0x244678 mov r1, r6
 *   @0x24467c mov r2, r6
 *   @0x244680 ldr r0, [r8, r3]
 *   @0x244684 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x244688 ldr r1, [pc, #0x2ac]
 *   @0x24468c mov r3, #6
 *   @0x244690 add r1, pc, r1
 *   @0x244694 mov r2, r0
 *   @0x244698 mov r0, r11
 *   @0x24469c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2446a0 ldr r3, [pc, #0x298]
 *   @0x2446a4 mov r2, r6
 *   @0x2446a8 mov r1, #1
 *   @0x2446ac ldr r0, [r8, r3]
 *   @0x2446b0 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x2446b4 ldr r1, [pc, #0x288]
 *   @0x2446b8 mov r3, #6
 *   @0x2446bc add r1, pc, r1
 *   @0x2446c0 mov r2, r0
 *   @0x2446c4 mov r0, r11
 *   @0x2446c8 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2446cc ldr r3, [pc, #0x274]
 *   @0x2446d0 mov r2, r6
 *   @0x2446d4 mov r1, #1
 *   @0x2446d8 ldr r0, [r8, r3]
 *   @0x2446dc bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x2446e0 ldr r1, [pc, #0x264]
 *   @0x2446e4 mov r3, #6
 *   @0x2446e8 add r1, pc, r1
 *   @0x2446ec mov r2, r0
 *   @0x2446f0 mov r0, r11
 *   @0x2446f4 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2446f8 ldr r3, [pc, #0x250]
 *   @0x2446fc mov r2, r6
 *   @0x244700 mov r1, #1
 *   @0x244704 ldr r0, [r8, r3]
 *   @0x244708 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x24470c ldr r1, [pc, #0x240]
 *   @0x244710 mov r3, #6
 *   @0x244714 add r1, pc, r1
 *   @0x244718 mov r2, r0
 *   @0x24471c mov r0, r11
 *   @0x244720 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x244724 add r2, sp, #120
 *   @0x244728 ldr r1, [pc, #0x228]
 *   @0x24472c mov r0, r11
 *   @0x244730 strd r4, r5, [r2, #-96]!
 *   @0x244734 mov r3, r6
 *   @0x244738 add r1, pc, r1
 *   @0x24473c str r6, [sp, #0x24]
 *   @0x244740 bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei>
 *   @0x244744 ldr r3, [pc, #0x210]
 *   @0x244748 mov r1, r6
 *   @0x24474c mov r2, r6
 *   @0x244750 mvn r4, #0
 *   @0x244754 movw r5, #0xffff
 *   @0x244758 ldr r0, [r8, r3]
 *   @0x24475c movt r5, #0x7fef
 *   @0x244760 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x244764 ldr r12, [pc, #0x1f4]
 *   @0x244768 ldr r1, [pc, #0x1f4]
 *   @0x24476c mov r3, r6
 *   @0x244770 ldr r12, [r8, r12]
 *   @0x244774 add r1, pc, r1
 *   @0x244778 mov r7, r0
 *   @0x24477c mov r0, r11
 *   @0x244780 str r12, [r7, #0x94]
 *   @0x244784 mov r2, r7
 *   @0x244788 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x24478c ldr r1, [pc, #0x1d4]
 *   @0x244790 mov r0, r7
 *   @0x244794 mov r3, r6
 *   @0x244798 add r1, pc, r1
 *   @0x24479c add r2, sp, #40
 *   @0x2447a0 strd r4, r5, [sp, #40]
 *   @0x2447a4 mov r4, #1
 *   @0x2447a8 str r6, [sp, #0x34]
 *   @0x2447ac mov r5, #0
 *   @0x2447b0 str r6, [sp, #0x30]
 *   @0x2447b4 bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei>
 *   @0x2447b8 ldr r1, [pc, #0x1ac]
 *   @0x2447bc mov r0, r7
 *   @0x2447c0 mov r3, r6
 *   @0x2447c4 add r2, sp, #56
 *   @0x2447c8 add r1, pc, r1
 *   @0x2447cc strd r4, r5, [sp, #56]
 *   @0x2447d0 str r6, [sp, #0x44]
 *   @0x2447d4 mvn r4, #0
 *   @0x2447d8 str r6, [sp, #0x40]
 *   @0x2447dc bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei>
 *   @0x2447e0 ldr r1, [pc, #0x188]
 *   @0x2447e4 mov r0, r7
 *   @0x2447e8 mov r3, r6
 *   @0x2447ec add r2, sp, #72
 *   @0x2447f0 add r1, pc, r1
 *   @0x2447f4 mvn r5, #-2147483648
 *   @0x2447f8 str r6, [sp, #0x54]
 *   @0x2447fc strd r4, r5, [sp, #72]
 *   @0x244800 mov r4, #0
 *   @0x244804 str r6, [sp, #0x50]
 *   @0x244808 bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei>
 *   @0x24480c ldr r1, [pc, #0x160]
 *   @0x244810 mov r0, r7
 *   @0x244814 mov r3, r6
 *   @0x244818 add r2, sp, #88
 *   @0x24481c add r1, pc, r1
 *   @0x244820 str r6, [sp, #0x64]
 *   @0x244824 mov r5, #0
 *   @0x244828 str r6, [sp, #0x60]
 *   @0x24482c movt r5, #0xfff0
 *   @0x244830 strd r4, r5, [sp, #88]
 *   @0x244834 bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei>
 *   @0x244838 ldr r1, [pc, #0x138]
 *   @0x24483c mov r3, r6
 *   @0x244840 mov r0, r7
 *   @0x244844 add r1, pc, r1
 *   @0x244848 add r2, sp, #104
 *   @0x24484c str r6, [sp, #0x74]
 *   @0x244850 mov r4, #0
 *   @0x244854 mov r5, #0
 *   @0x244858 str r6, [sp, #0x70]
 *   @0x24485c movt r5, #0x7ff0
 *   @0x244860 strd r4, r5, [sp, #104]
 *   @0x244864 bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei>
 *   @0x244868 ldr r1, [r9]
 *   @0x24486c mov r0, r7
 *   @0x244870 str r1, [r7, #0x18]
 *   @0x244874 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x244878 ldr r3, [r7, #0x4]
 *   @0x24487c cmp r3, r6
 *   @0x244880 beq 0x2448d8 <_Z20JS_NumberObjectSetupv+0x330>
 *   @0x244884 ldr r1, [r10]
 *   @0x244888 mov r0, r7
 *   @0x24488c str r1, [r3]
 *   @0x244890 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x244894 ldr r1, [r7, #0x4]
 *   @0x244898 cmp r1, #0
 *   @0x24489c movne r3, #6
 *   @0x2448a0 strne r3, [r1, #0xc]
 *   @0x2448a4 beq 0x2448ec <_Z20JS_NumberObjectSetupv+0x344>
 *   @0x2448a8 ldr r0, [pc, #0xcc]
 *   @0x2448ac mov r3, #6
 *   @0x2448b0 str r3, [r1, #0x8]
 *   @0x2448b4 mov r2, r7
 *   @0x2448b8 ldr r1, [pc, #0xc0]
 *   @0x2448bc mov r3, #0
 *   @0x2448c0 ldr r0, [r8, r0]
 *   @0x2448c4 add r1, pc, r1
 *   @0x2448c8 ldr r0, [r0]
 *   @0x2448cc bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2448d0 add sp, sp, #124
 *   @0x2448d4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2448d8 mov r1, r3
 *   @0x2448dc mov r0, r7
 *   @0x2448e0 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x2448e4 mov r3, r0
 *   @0x2448e8 b 0x244884 <_Z20JS_NumberObjectSetupv+0x2dc>
 *   @0x2448ec mov r0, r7
 *   @0x2448f0 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x2448f4 ldr r1, [r7, #0x4]
 *   @0x2448f8 mov r3, #6
 *   @0x2448fc cmp r1, #0
 *   @0x244900 str r3, [r0, #0xc]
 *   @0x244904 bne 0x2448a8 <_Z20JS_NumberObjectSetupv+0x300>
 *   @0x244908 mov r0, r7
 *   @0x24490c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x244910 mov r1, r0
 *   @0x244914 b 0x2448a8 <_Z20JS_NumberObjectSetupv+0x300>
 *   @0x244918 andseq sp, r10, r8, ror r6
 *   @0x24491c .word 0xfffffab4
 *   @0x244920 andseq r1, r1, r0, lsr #7
 *   @0x244924 .word 0xffffc050
 *   @0x244928 .word 0xfffffab8
 *   @0x24492c ldrdeq sp, lr, [lr], -r8
 *   @0x244930 .word 0xfffffabc
 *   @0x244934 andseq r0, r1, r4, ror #31
 *   @0x244938 .word 0xfffffac0
 *   @0x24493c andseq r0, r1, r8, asr #31
 *   @0x244940 .word 0xfffffac4
 *   @0x244944 ldrsbeq r1, [r1], -r12
 *   @0x244948 .word 0xfffffac8
 *   @0x24494c ldrheq r1, [r1], -r8
 *   @0x244950 .word 0xfffffacc
 *   @0x244954 mulseq r1, r12, r2
 *   @0x244958 ldrsbeq r0, [r1], -r8
 *   @0x24495c .word 0xfffffad0
 *   @0x244960 .word 0xfffffad4
 *   @0x244964 ldrheq r0, [r1], -r0
 *   @0x244968 andseq r1, r1, r4, lsr #4
 *   @0x24496c andseq r1, r1, r0, lsl #4
 *   @0x244970 andeq sp, lr, r4, lsl #26
 *   @0x244974 ldrheq r1, [r1], -r8
 *   @0x244978 andseq r1, r1, r4, lsr #3
 *   @0x24497c .word 0xffffbf64
 *   @0x244980 andseq r1, r1, r12, asr #1
 *
 * ══ §6/33 IBuffer::Write(eBuffer_Type, RValue*)  0xcb878  size 984  246 条（0xcb878..0xcbc50）
 * @func 0xcb878 0xcbc50  size 984  246 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __aeabi_idivmod×3 / YYGetInt32(RValue const*, int)×3 / YYGetUint32(RValue const*, int)×2 / YYGetString(RValue const*, int)×2 / 0xb6538×2 / IBuffer::Write(eBuffer_Type, RValue*)+0x5c / IBuffer::Write(eBuffer_Type, RValue*)+0xa0 / IBuffer::Write(eBuffer_Type, RValue*)+0x1c4
 * 字段偏移 top8: 0x1c×15 / 0x24×6 / 0x10×6 / 0x-8×5 / 0x18×4 / 0x1×3 / 0xc×3 / 0x14×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcb878 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0xcb87c mov r4, r0
 *   @0xcb880 ldr r5, [r4, #0x1c]
 *   @0xcb884 mov r9, r1
 *   @0xcb888 ldr r0, [r0, #0x24]
 *   @0xcb88c mov r8, r2
 *   @0xcb890 ldr r7, [r4, #0x14]
 *   @0xcb894 sub sp, sp, #12
 *   @0xcb898 add r5, r0, r5
 *   @0xcb89c ldr r6, [r4, #0x10]
 *   @0xcb8a0 sub r1, r7, #1
 *   @0xcb8a4 rsb r2, r7, #0
 *   @0xcb8a8 add r5, r5, r1
 *   @0xcb8ac and r5, r5, r2
 *   @0xcb8b0 rsb r5, r0, r5
 *   @0xcb8b4 str r5, [r4, #0x1c]
 *   @0xcb8b8 cmp r5, r6
 *   @0xcb8bc blt 0xcb8d4 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x5c>
 *   @0xcb8c0 ldr r2, [r4, #0x18]
 *   @0xcb8c4 cmp r2, #2
 *   @0xcb8c8 beq 0xcb918 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0xa0>
 *   @0xcb8cc cmp r2, #1
 *   @0xcb8d0 bne 0xcbc10 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x398>
 *   @0xcb8d4 sub r1, r9, #1
 *   @0xcb8d8 cmp r1, #12
 *   @0xcb8dc addls pc, pc, r1, lsl #2
 *   @0xcb8e0 b 0xcbc18 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x3a0>
 *   @0xcb8e4 b 0xcbad4 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x25c>
 *   @0xcb8e8 b 0xcbad4 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x25c>
 *   @0xcb8ec b 0xcbb50 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x2d8>
 *   @0xcb8f0 b 0xcb940 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0xc8>
 *   @0xcb8f4 b 0xcba80 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x208>
 *   @0xcb8f8 b 0xcba9c <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x224>
 *   @0xcb8fc b 0xcbc18 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x3a0>
 *   @0xcb900 b 0xcbab8 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x240>
 *   @0xcb904 b 0xcbb6c <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x2f4>
 *   @0xcb908 b 0xcbb88 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x310>
 *   @0xcb90c b 0xcbbb4 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x33c>
 *   @0xcb910 b 0xcbbd4 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x35c>
 *   @0xcb914 b 0xcbbf0 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x378>
 *   @0xcb918 add r0, r6, r0
 *   @0xcb91c mov r1, r7
 *   @0xcb920 bl 0x318dec <__aeabi_idivmod>
 *   @0xcb924 rsb r5, r6, r5
 *   @0xcb928 cmp r6, r5
 *   @0xcb92c mov r0, r1
 *   @0xcb930 ble 0xcb918 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0xa0>
 *   @0xcb934 str r1, [r4, #0x24]
 *   @0xcb938 str r5, [r4, #0x1c]
 *   @0xcb93c b 0xcb8d4 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x5c>
 *   @0xcb940 mov r0, r8
 *   @0xcb944 mov r1, #0
 *   @0xcb948 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xcb94c add r5, sp, #8
 *   @0xcb950 mov r7, #2
 *   @0xcb954 strh r0, [r5, #-8]!
 *   @0xcb958 ldr r2, [r4, #0x1c]
 *   @0xcb95c ldr r1, [r4, #0x10]
 *   @0xcb960 add r3, r2, r7
 *   @0xcb964 cmp r3, r1
 *   @0xcb968 mov r0, r2
 *   @0xcb96c ble 0xcba3c <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x1c4>
 *   @0xcb970 ldr r0, [r4, #0x18]
 *   @0xcb974 cmp r0, #1
 *   @0xcb978 beq 0xcba18 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x1a0>
 *   @0xcb97c cmp r0, #2
 *   @0xcb980 ldreq r3, [r4, #0xc]
 *   @0xcb984 addeq r3, r3, r2
 *   @0xcb988 bne 0xcbc10 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x398>
 *   @0xcb98c cmp r7, #0
 *   @0xcb990 movle r7, r2
 *   @0xcb994 ldrle r6, [r4, #0x10]
 *   @0xcb998 ble 0xcb9f0 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x178>
 *   @0xcb99c add r7, r5, r7
 *   @0xcb9a0 mov r8, #0
 *   @0xcb9a4 ldrb r2, [r5], #1
 *   @0xcb9a8 add r3, r3, #1
 *   @0xcb9ac strb r2, [r3, #-0x1]
 *   @0xcb9b0 ldr r2, [r4, #0x1c]
 *   @0xcb9b4 ldr r6, [r4, #0x10]
 *   @0xcb9b8 add r2, r2, #1
 *   @0xcb9bc str r2, [r4, #0x1c]
 *   @0xcb9c0 cmp r2, r6
 *   @0xcb9c4 blt 0xcb9e4 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x16c>
 *   @0xcb9c8 ldr r0, [r4, #0x24]
 *   @0xcb9cc ldr r1, [r4, #0x14]
 *   @0xcb9d0 add r0, r6, r0
 *   @0xcb9d4 bl 0x318dec <__aeabi_idivmod>
 *   @0xcb9d8 ldr r3, [r4, #0xc]
 *   @0xcb9dc str r8, [r4, #0x1c]
 *   @0xcb9e0 str r1, [r4, #0x24]
 *   @0xcb9e4 cmp r5, r7
 *   @0xcb9e8 bne 0xcb9a4 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x12c>
 *   @0xcb9ec ldr r7, [r4, #0x1c]
 *   @0xcb9f0 ldr r2, [r4, #0x20]
 *   @0xcb9f4 mov r3, #0
 *   @0xcb9f8 cmp r7, r2
 *   @0xcb9fc movlt r7, r2
 *   @0xcba00 cmp r7, r6
 *   @0xcba04 strle r7, [r4, #0x20]
 *   @0xcba08 strgt r6, [r4, #0x20]
 *   @0xcba0c mov r0, r3
 *   @0xcba10 add sp, sp, #12
 *   @0xcba14 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0xcba18 lsl r1, r1, #1
 *   @0xcba1c cmp r3, r1
 *   @0xcba20 bgt 0xcba18 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x1a0>
 *   @0xcba24 ldr r3, [r4]
 *   @0xcba28 mov r0, r4
 *   @0xcba2c ldr r3, [r3, #0x34]
 *   @0xcba30 blx r3
 *   @0xcba34 ldr r2, [r4, #0x1c]
 *   @0xcba38 mov r0, r2
 *   @0xcba3c ldr r1, [r4, #0x18]
 *   @0xcba40 ldr r3, [r4, #0xc]
 *   @0xcba44 cmp r1, #2
 *   @0xcba48 add r3, r3, r2
 *   @0xcba4c beq 0xcb98c <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x114>
 *   @0xcba50 cmp r7, #0
 *   @0xcba54 addgt r1, r3, r7
 *   @0xcba58 ble 0xcba70 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x1f8>
 *   @0xcba5c ldrb r2, [r5], #1
 *   @0xcba60 strb r2, [r3], #1
 *   @0xcba64 cmp r3, r1
 *   @0xcba68 bne 0xcba5c <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x1e4>
 *   @0xcba6c ldr r0, [r4, #0x1c]
 *   @0xcba70 add r7, r7, r0
 *   @0xcba74 ldr r6, [r4, #0x10]
 *   @0xcba78 str r7, [r4, #0x1c]
 *   @0xcba7c b 0xcb9f0 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x178>
 *   @0xcba80 mov r0, r8
 *   @0xcba84 mov r1, #0
 *   @0xcba88 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0xcba8c add r5, sp, #8
 *   @0xcba90 mov r7, #4
 *   @0xcba94 str r0, [r5, #-0x8]!
 *   @0xcba98 b 0xcb958 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0xe0>
 *   @0xcba9c mov r0, r8
 *   @0xcbaa0 mov r1, #0
 *   @0xcbaa4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xcbaa8 add r5, sp, #8
 *   @0xcbaac mov r7, #4
 *   @0xcbab0 str r0, [r5, #-0x8]!
 *   @0xcbab4 b 0xcb958 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0xe0>
 *   @0xcbab8 mov r0, r8
 *   @0xcbabc mov r1, #0
 *   @0xcbac0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0xcbac4 add r5, sp, #8
 *   @0xcbac8 mov r7, #4
 *   @0xcbacc str r0, [r5, #-0x8]!
 *   @0xcbad0 b 0xcb958 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0xe0>
 *   @0xcbad4 cmp r5, r6
 *   @0xcbad8 blt 0xcbb08 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x290>
 *   @0xcbadc ldr r3, [r4, #0x18]
 *   @0xcbae0 cmp r3, #2
 *   @0xcbae4 beq 0xcbc20 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x3a8>
 *   @0xcbae8 cmp r3, #1
 *   @0xcbaec bne 0xcbc10 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x398>
 *   @0xcbaf0 ldr r3, [r4]
 *   @0xcbaf4 lsl r1, r6, #1
 *   @0xcbaf8 str r5, [r4, #0x10]
 *   @0xcbafc mov r0, r4
 *   @0xcbb00 ldr r3, [r3, #0x34]
 *   @0xcbb04 blx r3
 *   @0xcbb08 ldr r5, [r4, #0x1c]
 *   @0xcbb0c add r3, r5, #1
 *   @0xcbb10 mov r1, #0
 *   @0xcbb14 str r3, [r4, #0x1c]
 *   @0xcbb18 mov r0, r8
 *   @0xcbb1c ldr r6, [r4, #0xc]
 *   @0xcbb20 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xcbb24 mov r3, #0
 *   @0xcbb28 strb r0, [r6, r5]
 *   @0xcbb2c ldr r2, [r4, #0x10]
 *   @0xcbb30 ldr r0, [r4, #0x20]
 *   @0xcbb34 ldr r1, [r4, #0x1c]
 *   @0xcbb38 cmp r1, r0
 *   @0xcbb3c movlt r1, r0
 *   @0xcbb40 cmp r1, r2
 *   @0xcbb44 strle r1, [r4, #0x20]
 *   @0xcbb48 strgt r2, [r4, #0x20]
 *   @0xcbb4c b 0xcba0c <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x194>
 *   @0xcbb50 mov r0, r8
 *   @0xcbb54 mov r1, #0
 *   @0xcbb58 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0xcbb5c add r5, sp, #8
 *   @0xcbb60 mov r7, #2
 *   @0xcbb64 strh r0, [r5, #-8]!
 *   @0xcbb68 b 0xcb958 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0xe0>
 *   @0xcbb6c mov r0, r8
 *   @0xcbb70 mov r1, #0
 *   @0xcbb74 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0xcbb78 add r5, sp, #8
 *   @0xcbb7c mov r7, #8
 *   @0xcbb80 strd r0, r1, [r5, #-8]!
 *   @0xcbb84 b 0xcb958 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0xe0>
 *   @0xcbb88 mov r0, r8
 *   @0xcbb8c mov r1, #0
 *   @0xcbb90 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0xcbb94 cmp r0, #0
 *   @0xcbb98 addne r5, sp, #8
 *   @0xcbb9c addeq r5, sp, #8
 *   @0xcbba0 movne r7, #1
 *   @0xcbba4 moveq r7, #1
 *   @0xcbba8 strbne r7, [r5, #-0x8]!
 *   @0xcbbac strbeq r0, [r5, #-0x8]!
 *   @0xcbbb0 b 0xcb958 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0xe0>
 *   @0xcbbb4 mov r0, r8
 *   @0xcbbb8 mov r1, #0
 *   @0xcbbbc bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0xcbbc0 subs r5, r0, #0
 *   @0xcbbc4 beq 0xcbc18 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x3a0>
 *   @0xcbbc8 bl 0xb6538 <strlen@plt>
 *   @0xcbbcc add r7, r0, #1
 *   @0xcbbd0 b 0xcb958 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0xe0>
 *   @0xcbbd4 mov r0, r8
 *   @0xcbbd8 mov r1, #0
 *   @0xcbbdc bl 0xcea30 <_Z10YYGetInt64PK6RValuei>
 *   @0xcbbe0 add r5, sp, #8
 *   @0xcbbe4 mov r7, #8
 *   @0xcbbe8 strd r0, r1, [r5, #-8]!
 *   @0xcbbec b 0xcb958 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0xe0>
 *   @0xcbbf0 mov r0, r8
 *   @0xcbbf4 mov r1, #0
 *   @0xcbbf8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0xcbbfc subs r5, r0, #0
 *   @0xcbc00 beq 0xcbc18 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x3a0>
 *   @0xcbc04 bl 0xb6538 <strlen@plt>
 *   @0xcbc08 mov r7, r0
 *   @0xcbc0c b 0xcb958 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0xe0>
 *   @0xcbc10 mvn r3, #1
 *   @0xcbc14 b 0xcba0c <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x194>
 *   @0xcbc18 mvn r3, #0
 *   @0xcbc1c b 0xcba0c <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x194>
 *   @0xcbc20 ldr r5, [r4, #0x1c]
 *   @0xcbc24 cmp r6, r5
 *   @0xcbc28 bgt 0xcbb0c <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x294>
 *   @0xcbc2c ldr r1, [r4, #0x24]
 *   @0xcbc30 add r0, r6, r1
 *   @0xcbc34 rsb r5, r6, r5
 *   @0xcbc38 mov r1, r7
 *   @0xcbc3c bl 0x318dec <__aeabi_idivmod>
 *   @0xcbc40 cmp r6, r5
 *   @0xcbc44 ble 0xcbc30 <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x3b8>
 *   @0xcbc48 str r1, [r4, #0x24]
 *   @0xcbc4c b 0xcbb0c <_ZN7IBuffer5WriteE12eBuffer_TypeP6RValue+0x294>
 *
 * ══ §7/33 b2PrismaticJoint::InitVelocityConstraints(b2SolverData const&)  0x2cfba0  size 980  245 条（0x2cfba0..0x2cff74）
 * @func 0x2cfba0 0x2cff74  size 980  245 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6580×2 / 0xb658c×2 / b2PrismaticJoint::InitVelocityConstraints(b2SolverData const&)+0x3a8
 * 字段偏移 top8: 0x8×4 / 0x8c×3 / 0x70×2 / 0x30×1 / 0x34×1 / 0x18×1 / 0x90×1 / 0x1c×1
 * VFP 指令 166 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cfba0 ldr r2, [r0, #0x30]
 *   @0x2cfba4 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2cfba8 vpush {d8, d9, d10, d11, d12, d13, d14}
 *   @0x2cfbac mov r7, r1
 *   @0x2cfbb0 vldr s21, [r2, #136]
 *   @0x2cfbb4 ldr r3, [r0, #0x34]
 *   @0x2cfbb8 add r1, r2, #44
 *   @0x2cfbbc ldr r6, [r2, #0x8]
 *   @0x2cfbc0 mov r4, r0
 *   @0x2cfbc4 vldr s20, [r3, #136]
 *   @0x2cfbc8 ldr r9, [r7, #0x18]
 *   @0x2cfbcc ldr r12, [r3, #0x8]
 *   @0x2cfbd0 add lr, r0, #160
 *   @0x2cfbd4 add r10, r0, #152
 *   @0x2cfbd8 ldm r1, {r0, r1}
 *   @0x2cfbdc str r6, [r4, #0x90]
 *   @0x2cfbe0 add r6, r6, r6, lsl #1
 *   @0x2cfbe4 add r8, r3, #44
 *   @0x2cfbe8 vldr s19, [r2, #144]
 *   @0x2cfbec lsl r6, r6, #2
 *   @0x2cfbf0 ldr r5, [r7, #0x1c]
 *   @0x2cfbf4 str r12, [r4, #0x94]
 *   @0x2cfbf8 add r12, r12, r12, lsl #1
 *   @0x2cfbfc stm r10, {r0, r1}
 *   @0x2cfc00 vldr s18, [r3, #144]
 *   @0x2cfc04 ldm r8, {r0, r1}
 *   @0x2cfc08 add r8, r9, r6
 *   @0x2cfc0c lsl r12, r12, #2
 *   @0x2cfc10 add r6, r5, r6
 *   @0x2cfc14 ldr r11, [r8, #0x8]
 *   @0x2cfc18 add r9, r9, r12
 *   @0x2cfc1c stm lr, {r0, r1}
 *   @0x2cfc20 vstr s21, [r4, #168]
 *   @0x2cfc24 vstr s20, [r4, #172]
 *   @0x2cfc28 vstr s19, [r4, #176]
 *   @0x2cfc2c mov r0, r11
 *   @0x2cfc30 vstr s18, [r4, #180]
 *   @0x2cfc34 add r5, r5, r12
 *   @0x2cfc38 bl 0xb6580 <sinf@plt>
 *   @0x2cfc3c ldr r10, [r9, #0x8]
 *   @0x2cfc40 vadd.f32 s28, s21, s20
 *   @0x2cfc44 vmov s16, r0
 *   @0x2cfc48 mov r0, r11
 *   @0x2cfc4c bl 0xb658c <cosf@plt>
 *   @0x2cfc50 vmov s17, r0
 *   @0x2cfc54 mov r0, r10
 *   @0x2cfc58 bl 0xb6580 <sinf@plt>
 *   @0x2cfc5c vmov s22, r0
 *   @0x2cfc60 mov r0, r10
 *   @0x2cfc64 bl 0xb658c <cosf@plt>
 *   @0x2cfc68 vldr s15, [r4, #164]
 *   @0x2cfc6c vldr s7, [r4, #80]
 *   @0x2cfc70 vsub.f32 s7, s7, s15
 *   @0x2cfc74 vldr s27, [r4, #72]
 *   @0x2cfc78 vldr s15, [r4, #156]
 *   @0x2cfc7c vldr s8, [r4, #76]
 *   @0x2cfc80 vldr s10, [r4, #160]
 *   @0x2cfc84 vldr s26, [r4, #68]
 *   @0x2cfc88 vldr s11, [r4, #152]
 *   @0x2cfc8c vldr s4, [r9, #4]
 *   @0x2cfc90 vldr s5, [r8, #4]
 *   @0x2cfc94 vldr s13, [r4, #88]
 *   @0x2cfc98 vldr s6, [r8]
 *   @0x2cfc9c vldr s25, [r9]
 *   @0x2cfca0 vldr s14, [r4, #84]
 *   @0x2cfca4 vldr s24, [r6]
 *   @0x2cfca8 vldr s23, [r6, #4]
 *   @0x2cfcac vldr s0, [r6, #8]
 *   @0x2cfcb0 vldr s1, [r5]
 *   @0x2cfcb4 vldr s2, [r5, #4]
 *   @0x2cfcb8 vldr s3, [r5, #8]
 *   @0x2cfcbc vsub.f32 s15, s27, s15
 *   @0x2cfcc0 vsub.f32 s10, s8, s10
 *   @0x2cfcc4 vmul.f32 s8, s15, s17
 *   @0x2cfcc8 vmov s12, r0
 *   @0x2cfccc vmul.f32 s9, s7, s12
 *   @0x2cfcd0 vsub.f32 s11, s26, s11
 *   @0x2cfcd4 vmla.f32 s9, s10, s22
 *   @0x2cfcd8 vmul.f32 s7, s7, s22
 *   @0x2cfcdc vmla.f32 s8, s11, s16
 *   @0x2cfce0 vmul.f32 s15, s15, s16
 *   @0x2cfce4 vsub.f32 s22, s4, s5
 *   @0x2cfce8 vnmls.f32 s7, s10, s12
 *   @0x2cfcec vmul.f32 s12, s13, s16
 *   @0x2cfcf0 vadd.f32 s22, s9, s22
 *   @0x2cfcf4 vnmls.f32 s15, s11, s17
 *   @0x2cfcf8 vsub.f32 s25, s25, s6
 *   @0x2cfcfc vnmls.f32 s12, s14, s17
 *   @0x2cfd00 vmul.f32 s13, s13, s17
 *   @0x2cfd04 vstr s12, [r4, #184]
 *   @0x2cfd08 vldr s4, [r4, #92]
 *   @0x2cfd0c ldrb r3, [r4, #0x88]
 *   @0x2cfd10 vsub.f32 s22, s22, s8
 *   @0x2cfd14 vadd.f32 s25, s7, s25
 *   @0x2cfd18 vadd.f32 s8, s8, s22
 *   @0x2cfd1c vmla.f32 s13, s14, s16
 *   @0x2cfd20 vsub.f32 s25, s25, s15
 *   @0x2cfd24 vstr s13, [r4, #188]
 *   @0x2cfd28 vmul.f32 s14, s12, s8
 *   @0x2cfd2c vadd.f32 s5, s15, s25
 *   @0x2cfd30 vnmls.f32 s14, s13, s5
 *   @0x2cfd34 vmul.f32 s15, s9, s12
 *   @0x2cfd38 vstr s14, [r4, #208]
 *   @0x2cfd3c vnmls.f32 s15, s7, s13
 *   @0x2cfd40 vmul.f32 s27, s19, s14
 *   @0x2cfd44 vstr s15, [r4, #212]
 *   @0x2cfd48 vmov.f32 s6, s28
 *   @0x2cfd4c vmla.f32 s6, s27, s14
 *   @0x2cfd50 vmul.f32 s26, s18, s15
 *   @0x2cfd54 vmla.f32 s6, s26, s15
 *   @0x2cfd58 vcmpe.f32 s6, #0
 *   @0x2cfd5c vstr s6, [r4, #248]
 *   @0x2cfd60 vmrs APSR_nzcv, fpscr
 *   @0x2cfd64 vmovgt.f32 s11, #1.000000e+00
 *   @0x2cfd68 vstrle s6, [r4, #252]
 *   @0x2cfd6c vdivgt.f32 s11, s11, s6
 *   @0x2cfd70 vstrgt s11, [r4, #252]
 *   @0x2cfd74 vldr s11, [r4, #96]
 *   @0x2cfd78 vmul.f32 s10, s11, s16
 *   @0x2cfd7c vmul.f32 s11, s11, s17
 *   @0x2cfd80 vnmls.f32 s10, s4, s17
 *   @0x2cfd84 vmla.f32 s11, s4, s16
 *   @0x2cfd88 vstr s10, [r4, #192]
 *   @0x2cfd8c vmul.f32 s8, s8, s10
 *   @0x2cfd90 vstr s11, [r4, #196]
 *   @0x2cfd94 vnmls.f32 s8, s5, s11
 *   @0x2cfd98 vmul.f32 s9, s9, s10
 *   @0x2cfd9c vstr s8, [r4, #200]
 *   @0x2cfda0 vnmls.f32 s9, s7, s11
 *   @0x2cfda4 vmul.f32 s4, s19, s8
 *   @0x2cfda8 vstr s9, [r4, #204]
 *   @0x2cfdac vmov.f32 s7, s28
 *   @0x2cfdb0 vmla.f32 s7, s4, s8
 *   @0x2cfdb4 vmul.f32 s5, s18, s9
 *   @0x2cfdb8 vmul.f32 s6, s5, s15
 *   @0x2cfdbc vmla.f32 s7, s5, s9
 *   @0x2cfdc0 vmla.f32 s6, s4, s14
 *   @0x2cfdc4 vstr s7, [r4, #216]
 *   @0x2cfdc8 vadd.f32 s7, s19, s18
 *   @0x2cfdcc vstr s6, [r4, #224]
 *   @0x2cfdd0 vstr s6, [r4, #240]
 *   @0x2cfdd4 vmov.f32 s16, #1.000000e+00
 *   @0x2cfdd8 vadd.f32 s6, s27, s26
 *   @0x2cfddc vadd.f32 s5, s4, s5
 *   @0x2cfde0 vstr s6, [r4, #236]
 *   @0x2cfde4 vstr s6, [r4, #244]
 *   @0x2cfde8 vcmp.f32 s7, #0
 *   @0x2cfdec vstr s5, [r4, #220]
 *   @0x2cfdf0 vstr s5, [r4, #228]
 *   @0x2cfdf4 vmrs APSR_nzcv, fpscr
 *   @0x2cfdf8 vmoveq.f32 s7, s16
 *   @0x2cfdfc cmp r3, #0
 *   @0x2cfe00 vstr s7, [r4, #232]
 *   @0x2cfe04 beq 0x2cfe88 <_ZN16b2PrismaticJoint23InitVelocityConstraintsERK12b2SolverData+0x2e8>
 *   @0x2cfe08 vldr s5, [r4, #124]
 *   @0x2cfe0c vldr s6, [r4, #120]
 *   @0x2cfe10 vsub.f32 s7, s5, s6
 *   @0x2cfe14 vldr s4, [pc, #340]
 *   @0x2cfe18 vcmpe.f32 s7, #0
 *   @0x2cfe1c vmrs APSR_nzcv, fpscr
 *   @0x2cfe20 vnegle.f32 s7, s7
 *   @0x2cfe24 vcmpe.f32 s7, s4
 *   @0x2cfe28 vmrs APSR_nzcv, fpscr
 *   @0x2cfe2c movmi r3, #3
 *   @0x2cfe30 strmi r3, [r4, #0x8c]
 *   @0x2cfe34 bpl 0x2cfe9c <_ZN16b2PrismaticJoint23InitVelocityConstraintsERK12b2SolverData+0x2fc>
 *   @0x2cfe38 ldrb r3, [r4, #0x89]
 *   @0x2cfe3c cmp r3, #0
 *   @0x2cfe40 moveq r3, #0
 *   @0x2cfe44 streq r3, [r4, #0x74]
 *   @0x2cfe48 ldrb r3, [r7, #0x14]
 *   @0x2cfe4c cmp r3, #0
 *   @0x2cfe50 bne 0x2cfecc <_ZN16b2PrismaticJoint23InitVelocityConstraintsERK12b2SolverData+0x32c>
 *   @0x2cfe54 mov r3, #0
 *   @0x2cfe58 str r3, [r4, #0x68]
 *   @0x2cfe5c str r3, [r4, #0x6c]
 *   @0x2cfe60 str r3, [r4, #0x70]
 *   @0x2cfe64 str r3, [r4, #0x74]
 *   @0x2cfe68 vstr s24, [r6]
 *   @0x2cfe6c vstr s23, [r6, #4]
 *   @0x2cfe70 vpop {d8, d9, d10, d11, d12, d13, d14}
 *   @0x2cfe74 vstr s0, [r6, #8]
 *   @0x2cfe78 vstr s1, [r5]
 *   @0x2cfe7c vstr s2, [r5, #4]
 *   @0x2cfe80 vstr s3, [r5, #8]
 *   @0x2cfe84 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2cfe88 mov r3, #0
 *   @0x2cfe8c mov r2, #0
 *   @0x2cfe90 str r3, [r4, #0x8c]
 *   @0x2cfe94 str r2, [r4, #0x70]
 *   @0x2cfe98 b 0x2cfe38 <_ZN16b2PrismaticJoint23InitVelocityConstraintsERK12b2SolverData+0x298>
 *   @0x2cfe9c vmul.f32 s22, s22, s13
 *   @0x2cfea0 vmla.f32 s22, s25, s12
 *   @0x2cfea4 vcmpe.f32 s6, s22
 *   @0x2cfea8 vmrs APSR_nzcv, fpscr
 *   @0x2cfeac blt 0x2cff48 <_ZN16b2PrismaticJoint23InitVelocityConstraintsERK12b2SolverData+0x3a8>
 *   @0x2cfeb0 ldr r3, [r4, #0x8c]
 *   @0x2cfeb4 cmp r3, #1
 *   @0x2cfeb8 movne r3, #1
 *   @0x2cfebc movne r2, #0
 *   @0x2cfec0 strne r3, [r4, #0x8c]
 *   @0x2cfec4 strne r2, [r4, #0x70]
 *   @0x2cfec8 b 0x2cfe38 <_ZN16b2PrismaticJoint23InitVelocityConstraintsERK12b2SolverData+0x298>
 *   @0x2cfecc vldr s5, [r7, #8]
 *   @0x2cfed0 vldr s4, [r4, #112]
 *   @0x2cfed4 vldr s6, [r4, #116]
 *   @0x2cfed8 vmul.f32 s4, s5, s4
 *   @0x2cfedc vldr s7, [r4, #104]
 *   @0x2cfee0 vldr s16, [r4, #108]
 *   @0x2cfee4 vmul.f32 s7, s5, s7
 *   @0x2cfee8 vstr s4, [r4, #112]
 *   @0x2cfeec vmul.f32 s6, s5, s6
 *   @0x2cfef0 vstr s7, [r4, #104]
 *   @0x2cfef4 vmul.f32 s5, s5, s16
 *   @0x2cfef8 vstr s6, [r4, #116]
 *   @0x2cfefc vadd.f32 s6, s6, s4
 *   @0x2cff00 vstr s5, [r4, #108]
 *   @0x2cff04 vmov.f32 s4, s5
 *   @0x2cff08 vmla.f32 s4, s8, s7
 *   @0x2cff0c vmla.f32 s5, s9, s7
 *   @0x2cff10 vmul.f32 s12, s6, s12
 *   @0x2cff14 vmul.f32 s13, s6, s13
 *   @0x2cff18 vmov.f32 s8, s4
 *   @0x2cff1c vmla.f32 s12, s10, s7
 *   @0x2cff20 vmla.f32 s13, s11, s7
 *   @0x2cff24 vmla.f32 s8, s6, s14
 *   @0x2cff28 vmla.f32 s5, s6, s15
 *   @0x2cff2c vmls.f32 s24, s21, s12
 *   @0x2cff30 vmla.f32 s1, s20, s12
 *   @0x2cff34 vmls.f32 s23, s21, s13
 *   @0x2cff38 vmla.f32 s2, s20, s13
 *   @0x2cff3c vmls.f32 s0, s19, s8
 *   @0x2cff40 vmla.f32 s3, s18, s5
 *   @0x2cff44 b 0x2cfe68 <_ZN16b2PrismaticJoint23InitVelocityConstraintsERK12b2SolverData+0x2c8>
 *   @0x2cff48 vcmpe.f32 s5, s22
 *   @0x2cff4c vmrs APSR_nzcv, fpscr
 *   @0x2cff50 bhi 0x2cfe88 <_ZN16b2PrismaticJoint23InitVelocityConstraintsERK12b2SolverData+0x2e8>
 *   @0x2cff54 ldr r3, [r4, #0x8c]
 *   @0x2cff58 cmp r3, #2
 *   @0x2cff5c movne r3, #2
 *   @0x2cff60 movne r2, #0
 *   @0x2cff64 strne r3, [r4, #0x8c]
 *   @0x2cff68 strne r2, [r4, #0x70]
 *   @0x2cff6c b 0x2cfe38 <_ZN16b2PrismaticJoint23InitVelocityConstraintsERK12b2SolverData+0x298>
 *   @0x2cff70 stclo p7, c13, [r3], #-40
 *
 * ══ §8/33 Eff_Effect05(int, float, float, int, unsigned int)  0x1a1194  size 976  244 条（0x1a1194..0x1a1564）
 * @func 0x1a1194 0x1a1564  size 976  244 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1a11bc→0x542404
 * 调用序列: 0xb66e8×6 / YYRandom(int)×6 / ParticleType_Shape(int, int)×3 / ParticleType_Size(int, float, float, float, float)×3 / ParticleType_Alpha2(int, float, float)×3 / ParticleType_Speed(int, float, float, float, float)×3 / ParticleType_Direction(int, float, float, float, float)×3 / ParticleType_Life(int, int, int)×3
 * 字段偏移 top8: 0x4×7 / 0x8×7 / 0x38×1 / 0x398×1 / 0x38c×1
 * VFP 指令 82 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a1194 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1a1198 vpush {d8, d9}
 *   @0x1a119c sub sp, sp, #8
 *   @0x1a11a0 mov r4, r3
 *   @0x1a11a4 vmov s19, r1
 *   @0x1a11a8 mov r6, r0
 *   @0x1a11ac ldr r7, [sp, #0x38]
 *   @0x1a11b0 vmov s18, r2
 *   @0x1a11b4 bl 0x19ff6c <_Z12Speed_Factorv>
 *   @0x1a11b8 cmp r4, #0
 *   @0x1a11bc ldr r3, [pc, #0x398]
 *   @0x1a11c0 mov r1, #10
 *   @0x1a11c4 mov r9, #0
 *   @0x1a11c8 vmov s16, r0
 *   @0x1a11cc ldr r0, [pc, #0x38c]
 *   @0x1a11d0 add r0, pc, r0
 *   @0x1a11d4 beq 0x1a1308 <_Z12Eff_Effect05iffij+0x174>
 *   @0x1a11d8 cmp r4, #2
 *   @0x1a11dc beq 0x1a1430 <_Z12Eff_Effect05iffij+0x29c>
 *   @0x1a11e0 ldr r4, [r0, r3]
 *   @0x1a11e4 mov r5, #11
 *   @0x1a11e8 mov r8, #1
 *   @0x1a11ec ldr r0, [r4, #0x4]
 *   @0x1a11f0 bl 0x1a31a4 <_Z18ParticleType_Shapeii>
 *   @0x1a11f4 vldr s15, [pc, #856]
 *   @0x1a11f8 vmul.f32 s15, s16, s15
 *   @0x1a11fc ldr r0, [r4, #0x4]
 *   @0x1a1200 movw r1, #0xcccd
 *   @0x1a1204 str r9, [sp]
 *   @0x1a1208 movt r1, #0x3ecc
 *   @0x1a120c movw r2, #0x3333
 *   @0x1a1210 movt r2, #0x3f33
 *   @0x1a1214 vmov r3, s15
 *   @0x1a1218 bl 0x1a322c <_Z17ParticleType_Sizeiffff>
 *   @0x1a121c mov r2, r9
 *   @0x1a1220 ldr r0, [r4, #0x4]
 *   @0x1a1224 movw r1, #0xcccd
 *   @0x1a1228 movt r1, #0x3ecc
 *   @0x1a122c bl 0x1a36a4 <_Z19ParticleType_Alpha2iff>
 *   @0x1a1230 vmov.f32 s14, #5.000000e+00
 *   @0x1a1234 ldr r0, [r4, #0x4]
 *   @0x1a1238 mov r3, r9
 *   @0x1a123c str r9, [sp]
 *   @0x1a1240 vmov.f32 s15, #6.000000e+00
 *   @0x1a1244 vmul.f32 s14, s16, s14
 *   @0x1a1248 vmul.f32 s15, s16, s15
 *   @0x1a124c vmov r1, s14
 *   @0x1a1250 vmov r2, s15
 *   @0x1a1254 bl 0x1a3368 <_Z18ParticleType_Speediffff>
 *   @0x1a1258 mov r1, #0
 *   @0x1a125c movt r1, #0x42b4
 *   @0x1a1260 mov r3, r9
 *   @0x1a1264 ldr r0, [r4, #0x4]
 *   @0x1a1268 mov r2, r1
 *   @0x1a126c str r9, [sp]
 *   @0x1a1270 bl 0x1a33b4 <_Z22ParticleType_Directioniffff>
 *   @0x1a1274 vmov.f32 s15, #3.000000e+01
 *   @0x1a1278 ldr r10, [r4, #0x4]
 *   @0x1a127c vdiv.f32 s16, s15, s16
 *   @0x1a1280 vcvt.f64.f32 d8, s16
 *   @0x1a1284 vmov r0, r1, d8
 *   @0x1a1288 bl 0xb66e8 <lrint@plt>
 *   @0x1a128c mov r9, r0
 *   @0x1a1290 vmov r0, r1, d8
 *   @0x1a1294 bl 0xb66e8 <lrint@plt>
 *   @0x1a1298 mov r1, r9
 *   @0x1a129c vmov.f32 s17, #1.500000e+01
 *   @0x1a12a0 mov r2, r0
 *   @0x1a12a4 mov r0, r10
 *   @0x1a12a8 bl 0x1a32b4 <_Z17ParticleType_Lifeiii>
 *   @0x1a12ac vsub.f32 s19, s19, s17
 *   @0x1a12b0 mov r0, #30
 *   @0x1a12b4 bl 0xc4600 <_Z8YYRandomi>
 *   @0x1a12b8 vmov s15, r0
 *   @0x1a12bc mov r0, #30
 *   @0x1a12c0 vcvt.f32.u32 s16, s15
 *   @0x1a12c4 bl 0xc4600 <_Z8YYRandomi>
 *   @0x1a12c8 ldr r3, [r4, #0x4]
 *   @0x1a12cc stm sp, {r7, r8}
 *   @0x1a12d0 vsub.f32 s14, s18, s17
 *   @0x1a12d4 vadd.f32 s16, s19, s16
 *   @0x1a12d8 vmov r1, s16
 *   @0x1a12dc vmov s13, r0
 *   @0x1a12e0 mov r0, r6
 *   @0x1a12e4 vcvt.f32.u32 s15, s13
 *   @0x1a12e8 vadd.f32 s15, s14, s15
 *   @0x1a12ec vmov r2, s15
 *   @0x1a12f0 bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji>
 *   @0x1a12f4 subs r5, r5, #1
 *   @0x1a12f8 bne 0x1a12b0 <_Z12Eff_Effect05iffij+0x11c>
 *   @0x1a12fc add sp, sp, #8
 *   @0x1a1300 vpop {d8, d9}
 *   @0x1a1304 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1a1308 ldr r4, [r0, r3]
 *   @0x1a130c mov r5, #6
 *   @0x1a1310 mov r8, #1
 *   @0x1a1314 ldr r0, [r4]
 *   @0x1a1318 bl 0x1a31a4 <_Z18ParticleType_Shapeii>
 *   @0x1a131c vldr s15, [pc, #560]
 *   @0x1a1320 vmul.f32 s15, s16, s15
 *   @0x1a1324 ldr r0, [r4]
 *   @0x1a1328 movw r1, #0xcccd
 *   @0x1a132c str r9, [sp]
 *   @0x1a1330 movt r1, #0x3e4c
 *   @0x1a1334 movw r2, #0xcccd
 *   @0x1a1338 movt r2, #0x3ecc
 *   @0x1a133c vmov r3, s15
 *   @0x1a1340 bl 0x1a322c <_Z17ParticleType_Sizeiffff>
 *   @0x1a1344 mov r2, r9
 *   @0x1a1348 ldr r0, [r4]
 *   @0x1a134c movw r1, #0xcccd
 *   @0x1a1350 movt r1, #0x3ecc
 *   @0x1a1354 bl 0x1a36a4 <_Z19ParticleType_Alpha2iff>
 *   @0x1a1358 vmov.f32 s14, #3.000000e+00
 *   @0x1a135c ldr r0, [r4]
 *   @0x1a1360 mov r3, r9
 *   @0x1a1364 str r9, [sp]
 *   @0x1a1368 vmov.f32 s15, #4.000000e+00
 *   @0x1a136c vmul.f32 s14, s16, s14
 *   @0x1a1370 vmul.f32 s15, s16, s15
 *   @0x1a1374 vmov r1, s14
 *   @0x1a1378 vmov r2, s15
 *   @0x1a137c bl 0x1a3368 <_Z18ParticleType_Speediffff>
 *   @0x1a1380 mov r1, #0
 *   @0x1a1384 movt r1, #0x42b4
 *   @0x1a1388 mov r3, r9
 *   @0x1a138c ldr r0, [r4]
 *   @0x1a1390 mov r2, r1
 *   @0x1a1394 str r9, [sp]
 *   @0x1a1398 bl 0x1a33b4 <_Z22ParticleType_Directioniffff>
 *   @0x1a139c vmov.f32 s15, #2.500000e+01
 *   @0x1a13a0 ldr r10, [r4]
 *   @0x1a13a4 vdiv.f32 s16, s15, s16
 *   @0x1a13a8 vcvt.f64.f32 d8, s16
 *   @0x1a13ac vmov r0, r1, d8
 *   @0x1a13b0 bl 0xb66e8 <lrint@plt>
 *   @0x1a13b4 mov r9, r0
 *   @0x1a13b8 vmov r0, r1, d8
 *   @0x1a13bc bl 0xb66e8 <lrint@plt>
 *   @0x1a13c0 mov r1, r9
 *   @0x1a13c4 vmov.f32 s17, #5.000000e+00
 *   @0x1a13c8 mov r2, r0
 *   @0x1a13cc mov r0, r10
 *   @0x1a13d0 bl 0x1a32b4 <_Z17ParticleType_Lifeiii>
 *   @0x1a13d4 vsub.f32 s19, s19, s17
 *   @0x1a13d8 mov r0, #10
 *   @0x1a13dc bl 0xc4600 <_Z8YYRandomi>
 *   @0x1a13e0 vmov s13, r0
 *   @0x1a13e4 mov r0, #10
 *   @0x1a13e8 vcvt.f32.u32 s16, s13
 *   @0x1a13ec bl 0xc4600 <_Z8YYRandomi>
 *   @0x1a13f0 ldr r3, [r4]
 *   @0x1a13f4 stm sp, {r7, r8}
 *   @0x1a13f8 vsub.f32 s14, s18, s17
 *   @0x1a13fc vadd.f32 s16, s19, s16
 *   @0x1a1400 vmov r1, s16
 *   @0x1a1404 vmov s13, r0
 *   @0x1a1408 mov r0, r6
 *   @0x1a140c vcvt.f32.u32 s15, s13
 *   @0x1a1410 vadd.f32 s15, s14, s15
 *   @0x1a1414 vmov r2, s15
 *   @0x1a1418 bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji>
 *   @0x1a141c subs r5, r5, #1
 *   @0x1a1420 bne 0x1a13d8 <_Z12Eff_Effect05iffij+0x244>
 *   @0x1a1424 add sp, sp, #8
 *   @0x1a1428 vpop {d8, d9}
 *   @0x1a142c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1a1430 ldr r4, [r0, r3]
 *   @0x1a1434 mov r5, #16
 *   @0x1a1438 mov r8, #1
 *   @0x1a143c ldr r0, [r4, #0x8]
 *   @0x1a1440 bl 0x1a31a4 <_Z18ParticleType_Shapeii>
 *   @0x1a1444 vldr s15, [pc, #264]
 *   @0x1a1448 vmul.f32 s15, s16, s15
 *   @0x1a144c ldr r0, [r4, #0x8]
 *   @0x1a1450 mov r2, #1065353216
 *   @0x1a1454 str r9, [sp]
 *   @0x1a1458 movw r1, #0xcccd
 *   @0x1a145c movt r1, #0x3ecc
 *   @0x1a1460 vmov r3, s15
 *   @0x1a1464 bl 0x1a322c <_Z17ParticleType_Sizeiffff>
 *   @0x1a1468 mov r2, r9
 *   @0x1a146c ldr r0, [r4, #0x8]
 *   @0x1a1470 movw r1, #0xcccd
 *   @0x1a1474 movt r1, #0x3ecc
 *   @0x1a1478 bl 0x1a36a4 <_Z19ParticleType_Alpha2iff>
 *   @0x1a147c vmov.f32 s14, #6.000000e+00
 *   @0x1a1480 ldr r0, [r4, #0x8]
 *   @0x1a1484 mov r3, r9
 *   @0x1a1488 str r9, [sp]
 *   @0x1a148c vmov.f32 s15, #7.000000e+00
 *   @0x1a1490 vmul.f32 s14, s16, s14
 *   @0x1a1494 vmul.f32 s15, s16, s15
 *   @0x1a1498 vmov r1, s14
 *   @0x1a149c vmov r2, s15
 *   @0x1a14a0 bl 0x1a3368 <_Z18ParticleType_Speediffff>
 *   @0x1a14a4 mov r1, #0
 *   @0x1a14a8 movt r1, #0x42b4
 *   @0x1a14ac mov r3, r9
 *   @0x1a14b0 ldr r0, [r4, #0x8]
 *   @0x1a14b4 mov r2, r1
 *   @0x1a14b8 str r9, [sp]
 *   @0x1a14bc bl 0x1a33b4 <_Z22ParticleType_Directioniffff>
 *   @0x1a14c0 vldr s15, [pc, #144]
 *   @0x1a14c4 vdiv.f32 s16, s15, s16
 *   @0x1a14c8 ldr r10, [r4, #0x8]
 *   @0x1a14cc vcvt.f64.f32 d8, s16
 *   @0x1a14d0 vmov r0, r1, d8
 *   @0x1a14d4 bl 0xb66e8 <lrint@plt>
 *   @0x1a14d8 mov r9, r0
 *   @0x1a14dc vmov r0, r1, d8
 *   @0x1a14e0 bl 0xb66e8 <lrint@plt>
 *   @0x1a14e4 mov r1, r9
 *   @0x1a14e8 vmov.f32 s17, #3.000000e+01
 *   @0x1a14ec mov r2, r0
 *   @0x1a14f0 mov r0, r10
 *   @0x1a14f4 bl 0x1a32b4 <_Z17ParticleType_Lifeiii>
 *   @0x1a14f8 vsub.f32 s19, s19, s17
 *   @0x1a14fc mov r0, #60
 *   @0x1a1500 bl 0xc4600 <_Z8YYRandomi>
 *   @0x1a1504 vmov s15, r0
 *   @0x1a1508 mov r0, #60
 *   @0x1a150c vcvt.f32.u32 s16, s15
 *   @0x1a1510 bl 0xc4600 <_Z8YYRandomi>
 *   @0x1a1514 ldr r3, [r4, #0x8]
 *   @0x1a1518 stm sp, {r7, r8}
 *   @0x1a151c vsub.f32 s14, s18, s17
 *   @0x1a1520 vadd.f32 s16, s19, s16
 *   @0x1a1524 vmov r1, s16
 *   @0x1a1528 vmov s13, r0
 *   @0x1a152c mov r0, r6
 *   @0x1a1530 vcvt.f32.u32 s15, s13
 *   @0x1a1534 vadd.f32 s15, s14, s15
 *   @0x1a1538 vmov r2, s15
 *   @0x1a153c bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji>
 *   @0x1a1540 subs r5, r5, #1
 *   @0x1a1544 bne 0x1a14fc <_Z12Eff_Effect05iffij+0x368>
 *   @0x1a1548 add sp, sp, #8
 *   @0x1a154c vpop {d8, d9}
 *   @0x1a1550 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1a1554 stclt p7, c13, [r3], #-40
 *   @0x1a1558 submi r0, r8, #0
 *   @0x1a155c .word 0xffffeb34
 *   @0x1a1560 eoreq r0, r5, r0, lsl #21
 *
 * ══ §9/33 YYGML_min(YYRValue&, int, YYRValue**)  0x113c14  size 972  243 条（0x113c14..0x113fe0）
 * @func 0x113c14 0x113fe0  size 972  243 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / YYGetReal(RValue const*, int)×2 / GetContextStackTop()×2 / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)×2 / YYGML_min(YYRValue&, int, YYRValue**)+0x190
 * 字段偏移 top8: 0x4×19 / 0x8×11 / 0xc×9 / 0x-4×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x113c14 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x113c18 vpush {d8, d9}
 *   @0x113c1c subs r8, r1, #0
 *   @0x113c20 mov r3, #0
 *   @0x113c24 sub sp, sp, #12
 *   @0x113c28 mov r4, r0
 *   @0x113c2c mov r7, r2
 *   @0x113c30 str r3, [r0, #0xc]
 *   @0x113c34 str r3, [r0]
 *   @0x113c38 str r3, [r0, #0x4]
 *   @0x113c3c beq 0x113da4 <_Z9YYGML_minR8YYRValueiPPS_+0x190>
 *   @0x113c40 ldr r5, [r2]
 *   @0x113c44 ldr r3, [r5, #0xc]
 *   @0x113c48 ldr r2, [r5, #0x8]
 *   @0x113c4c str r3, [r0, #0xc]
 *   @0x113c50 ldr r3, [r5, #0xc]
 *   @0x113c54 str r2, [r0, #0x8]
 *   @0x113c58 bic r3, r3, #-16777216
 *   @0x113c5c cmp r3, #14
 *   @0x113c60 addls pc, pc, r3, lsl #2
 *   @0x113c64 b 0x113cac <_Z9YYGML_minR8YYRValueiPPS_+0x98>
 *   @0x113c68 b 0x113ec4 <_Z9YYGML_minR8YYRValueiPPS_+0x2b0>
 *   @0x113c6c b 0x113f10 <_Z9YYGML_minR8YYRValueiPPS_+0x2fc>
 *   @0x113c70 b 0x113f28 <_Z9YYGML_minR8YYRValueiPPS_+0x314>
 *   @0x113c74 b 0x113ca4 <_Z9YYGML_minR8YYRValueiPPS_+0x90>
 *   @0x113c78 b 0x113cac <_Z9YYGML_minR8YYRValueiPPS_+0x98>
 *   @0x113c7c b 0x113cac <_Z9YYGML_minR8YYRValueiPPS_+0x98>
 *   @0x113c80 b 0x113f54 <_Z9YYGML_minR8YYRValueiPPS_+0x340>
 *   @0x113c84 b 0x113ca4 <_Z9YYGML_minR8YYRValueiPPS_+0x90>
 *   @0x113c88 b 0x113cac <_Z9YYGML_minR8YYRValueiPPS_+0x98>
 *   @0x113c8c b 0x113cac <_Z9YYGML_minR8YYRValueiPPS_+0x98>
 *   @0x113c90 b 0x113ec4 <_Z9YYGML_minR8YYRValueiPPS_+0x2b0>
 *   @0x113c94 b 0x113cac <_Z9YYGML_minR8YYRValueiPPS_+0x98>
 *   @0x113c98 b 0x113cac <_Z9YYGML_minR8YYRValueiPPS_+0x98>
 *   @0x113c9c b 0x113ec4 <_Z9YYGML_minR8YYRValueiPPS_+0x2b0>
 *   @0x113ca0 b 0x113ca4 <_Z9YYGML_minR8YYRValueiPPS_+0x90>
 *   @0x113ca4 ldr r3, [r5]
 *   @0x113ca8 str r3, [r4]
 *   @0x113cac ldr r0, [r7]
 *   @0x113cb0 mov r1, #0
 *   @0x113cb4 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x113cb8 cmp r8, #1
 *   @0x113cbc vmov d9, r0, r1
 *   @0x113cc0 ble 0x113da4 <_Z9YYGML_minR8YYRValueiPPS_+0x190>
 *   @0x113cc4 add r7, r7, #4
 *   @0x113cc8 mov r5, #1
 *   @0x113ccc mov r9, #0
 *   @0x113cd0 mov r10, #5
 *   @0x113cd4 ldr r0, [r7], #4
 *   @0x113cd8 mov r1, #0
 *   @0x113cdc bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x113ce0 vmov d8, r0, r1
 *   @0x113ce4 vcmpe.f64 d8, d9
 *   @0x113ce8 vmrs APSR_nzcv, fpscr
 *   @0x113cec bpl 0x113d98 <_Z9YYGML_minR8YYRValueiPPS_+0x184>
 *   @0x113cf0 ldr r2, [r4, #0xc]
 *   @0x113cf4 ldr r6, [r7, #-0x4]
 *   @0x113cf8 bic r3, r2, #-16777216
 *   @0x113cfc cmp r3, #1
 *   @0x113d00 beq 0x113e00 <_Z9YYGML_minR8YYRValueiPPS_+0x1ec>
 *   @0x113d04 cmp r3, #2
 *   @0x113d08 bne 0x113d28 <_Z9YYGML_minR8YYRValueiPPS_+0x114>
 *   @0x113d0c sub r2, r2, #1
 *   @0x113d10 bic r2, r2, #-16777216
 *   @0x113d14 bic r2, r2, #3
 *   @0x113d18 cmp r2, #0
 *   @0x113d1c beq 0x113eb8 <_Z9YYGML_minR8YYRValueiPPS_+0x2a4>
 *   @0x113d20 str r9, [r4, #0x8]
 *   @0x113d24 str r10, [r4, #0xc]
 *   @0x113d28 ldr r3, [r6, #0xc]
 *   @0x113d2c ldr r2, [r6, #0x8]
 *   @0x113d30 str r9, [r4]
 *   @0x113d34 str r3, [r4, #0xc]
 *   @0x113d38 ldr r3, [r6, #0xc]
 *   @0x113d3c str r2, [r4, #0x8]
 *   @0x113d40 bic r3, r3, #-16777216
 *   @0x113d44 cmp r3, #14
 *   @0x113d48 addls pc, pc, r3, lsl #2
 *   @0x113d4c b 0x113df8 <_Z9YYGML_minR8YYRValueiPPS_+0x1e4>
 *   @0x113d50 b 0x113db4 <_Z9YYGML_minR8YYRValueiPPS_+0x1a0>
 *   @0x113d54 b 0x113e58 <_Z9YYGML_minR8YYRValueiPPS_+0x244>
 *   @0x113d58 b 0x113dc8 <_Z9YYGML_minR8YYRValueiPPS_+0x1b4>
 *   @0x113d5c b 0x113d8c <_Z9YYGML_minR8YYRValueiPPS_+0x178>
 *   @0x113d60 b 0x113df8 <_Z9YYGML_minR8YYRValueiPPS_+0x1e4>
 *   @0x113d64 b 0x113df8 <_Z9YYGML_minR8YYRValueiPPS_+0x1e4>
 *   @0x113d68 b 0x113e30 <_Z9YYGML_minR8YYRValueiPPS_+0x21c>
 *   @0x113d6c b 0x113d8c <_Z9YYGML_minR8YYRValueiPPS_+0x178>
 *   @0x113d70 b 0x113df8 <_Z9YYGML_minR8YYRValueiPPS_+0x1e4>
 *   @0x113d74 b 0x113df8 <_Z9YYGML_minR8YYRValueiPPS_+0x1e4>
 *   @0x113d78 b 0x113db4 <_Z9YYGML_minR8YYRValueiPPS_+0x1a0>
 *   @0x113d7c b 0x113df8 <_Z9YYGML_minR8YYRValueiPPS_+0x1e4>
 *   @0x113d80 b 0x113df8 <_Z9YYGML_minR8YYRValueiPPS_+0x1e4>
 *   @0x113d84 b 0x113db4 <_Z9YYGML_minR8YYRValueiPPS_+0x1a0>
 *   @0x113d88 b 0x113d8c <_Z9YYGML_minR8YYRValueiPPS_+0x178>
 *   @0x113d8c vmov.f64 d9, d8
 *   @0x113d90 ldr r3, [r6]
 *   @0x113d94 str r3, [r4]
 *   @0x113d98 add r5, r5, #1
 *   @0x113d9c cmp r5, r8
 *   @0x113da0 bne 0x113cd4 <_Z9YYGML_minR8YYRValueiPPS_+0xc0>
 *   @0x113da4 mov r0, r4
 *   @0x113da8 add sp, sp, #12
 *   @0x113dac vpop {d8, d9}
 *   @0x113db0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x113db4 ldr r2, [r6]
 *   @0x113db8 vmov.f64 d9, d8
 *   @0x113dbc ldr r3, [r6, #0x4]
 *   @0x113dc0 stm r4, {r2, r3}
 *   @0x113dc4 b 0x113d98 <_Z9YYGML_minR8YYRValueiPPS_+0x184>
 *   @0x113dc8 ldr r3, [r6]
 *   @0x113dcc cmp r3, #0
 *   @0x113dd0 str r3, [r4]
 *   @0x113dd4 beq 0x113df8 <_Z9YYGML_minR8YYRValueiPPS_+0x1e4>
 *   @0x113dd8 ldr r1, [r3, #0x8]
 *   @0x113ddc ldr r2, [r3]
 *   @0x113de0 cmp r1, #0
 *   @0x113de4 streq r4, [r3, #0x8]
 *   @0x113de8 add r2, r2, #1
 *   @0x113dec str r2, [r3]
 *   @0x113df0 vmoveq.f64 d9, d8
 *   @0x113df4 beq 0x113d98 <_Z9YYGML_minR8YYRValueiPPS_+0x184>
 *   @0x113df8 vmov.f64 d9, d8
 *   @0x113dfc b 0x113d98 <_Z9YYGML_minR8YYRValueiPPS_+0x184>
 *   @0x113e00 ldr r11, [r4]
 *   @0x113e04 cmp r11, #0
 *   @0x113e08 beq 0x113e28 <_Z9YYGML_minR8YYRValueiPPS_+0x214>
 *   @0x113e0c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x113e10 ldr r3, [r11, #0x4]
 *   @0x113e14 sub r3, r3, #1
 *   @0x113e18 str r3, [r11, #0x4]
 *   @0x113e1c cmp r3, #0
 *   @0x113e20 beq 0x113e78 <_Z9YYGML_minR8YYRValueiPPS_+0x264>
 *   @0x113e24 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x113e28 str r9, [r4]
 *   @0x113e2c b 0x113d28 <_Z9YYGML_minR8YYRValueiPPS_+0x114>
 *   @0x113e30 ldr r3, [r6]
 *   @0x113e34 str r3, [r4]
 *   @0x113e38 ldr r3, [r6]
 *   @0x113e3c cmp r3, #0
 *   @0x113e40 beq 0x113df8 <_Z9YYGML_minR8YYRValueiPPS_+0x1e4>
 *   @0x113e44 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x113e48 ldr r1, [r6]
 *   @0x113e4c vmov.f64 d9, d8
 *   @0x113e50 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x113e54 b 0x113d98 <_Z9YYGML_minR8YYRValueiPPS_+0x184>
 *   @0x113e58 ldr r3, [r6]
 *   @0x113e5c vmov.f64 d9, d8
 *   @0x113e60 cmp r3, #0
 *   @0x113e64 ldrne r2, [r3, #0x4]
 *   @0x113e68 addne r2, r2, #1
 *   @0x113e6c strne r2, [r3, #0x4]
 *   @0x113e70 str r3, [r4]
 *   @0x113e74 b 0x113d98 <_Z9YYGML_minR8YYRValueiPPS_+0x184>
 *   @0x113e78 ldr r0, [r11]
 *   @0x113e7c str r3, [sp, #0x4]
 *   @0x113e80 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x113e84 ldr r3, [sp, #0x4]
 *   @0x113e88 str r3, [r11]
 *   @0x113e8c str r3, [r11, #0x8]
 *   @0x113e90 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x113e94 ldr r3, [r11, #0x4]
 *   @0x113e98 sub r3, r3, #1
 *   @0x113e9c str r3, [r11, #0x4]
 *   @0x113ea0 cmp r3, #0
 *   @0x113ea4 beq 0x113ed0 <_Z9YYGML_minR8YYRValueiPPS_+0x2bc>
 *   @0x113ea8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x113eac mov r0, r11
 *   @0x113eb0 bl 0x27d1d0 <_ZdlPv>
 *   @0x113eb4 b 0x113e24 <_Z9YYGML_minR8YYRValueiPPS_+0x210>
 *   @0x113eb8 mov r0, r4
 *   @0x113ebc bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x113ec0 b 0x113d20 <_Z9YYGML_minR8YYRValueiPPS_+0x10c>
 *   @0x113ec4 ldm r5, {r2, r3}
 *   @0x113ec8 stm r0, {r2, r3}
 *   @0x113ecc b 0x113cac <_Z9YYGML_minR8YYRValueiPPS_+0x98>
 *   @0x113ed0 ldr r0, [r11]
 *   @0x113ed4 str r3, [sp, #0x4]
 *   @0x113ed8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x113edc ldr r3, [sp, #0x4]
 *   @0x113ee0 str r3, [r11]
 *   @0x113ee4 str r3, [r11, #0x8]
 *   @0x113ee8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x113eec ldr r3, [r11, #0x4]
 *   @0x113ef0 sub r3, r3, #1
 *   @0x113ef4 str r3, [r11, #0x4]
 *   @0x113ef8 cmp r3, #0
 *   @0x113efc beq 0x113f78 <_Z9YYGML_minR8YYRValueiPPS_+0x364>
 *   @0x113f00 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x113f04 mov r0, r11
 *   @0x113f08 bl 0x27d1d0 <_ZdlPv>
 *   @0x113f0c b 0x113ea8 <_Z9YYGML_minR8YYRValueiPPS_+0x294>
 *   @0x113f10 ldr r3, [r5]
 *   @0x113f14 cmp r3, #0
 *   @0x113f18 ldrne r2, [r3, #0x4]
 *   @0x113f1c addne r2, r2, #1
 *   @0x113f20 strne r2, [r3, #0x4]
 *   @0x113f24 b 0x113ca8 <_Z9YYGML_minR8YYRValueiPPS_+0x94>
 *   @0x113f28 ldr r3, [r5]
 *   @0x113f2c cmp r3, #0
 *   @0x113f30 str r3, [r0]
 *   @0x113f34 beq 0x113cac <_Z9YYGML_minR8YYRValueiPPS_+0x98>
 *   @0x113f38 ldr r1, [r3, #0x8]
 *   @0x113f3c ldr r2, [r3]
 *   @0x113f40 cmp r1, #0
 *   @0x113f44 streq r0, [r3, #0x8]
 *   @0x113f48 add r2, r2, #1
 *   @0x113f4c str r2, [r3]
 *   @0x113f50 b 0x113cac <_Z9YYGML_minR8YYRValueiPPS_+0x98>
 *   @0x113f54 ldr r3, [r5]
 *   @0x113f58 str r3, [r0]
 *   @0x113f5c ldr r3, [r5]
 *   @0x113f60 cmp r3, #0
 *   @0x113f64 beq 0x113cac <_Z9YYGML_minR8YYRValueiPPS_+0x98>
 *   @0x113f68 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x113f6c ldr r1, [r5]
 *   @0x113f70 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x113f74 b 0x113cac <_Z9YYGML_minR8YYRValueiPPS_+0x98>
 *   @0x113f78 ldr r0, [r11]
 *   @0x113f7c str r3, [sp, #0x4]
 *   @0x113f80 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x113f84 ldr r3, [sp, #0x4]
 *   @0x113f88 str r3, [r11]
 *   @0x113f8c str r3, [r11, #0x8]
 *   @0x113f90 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x113f94 ldr r3, [r11, #0x4]
 *   @0x113f98 sub r3, r3, #1
 *   @0x113f9c str r3, [r11, #0x4]
 *   @0x113fa0 cmp r3, #0
 *   @0x113fa4 bne 0x113fd0 <_Z9YYGML_minR8YYRValueiPPS_+0x3bc>
 *   @0x113fa8 ldr r0, [r11]
 *   @0x113fac str r3, [sp, #0x4]
 *   @0x113fb0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x113fb4 ldr r3, [sp, #0x4]
 *   @0x113fb8 mov r0, r11
 *   @0x113fbc str r3, [r11]
 *   @0x113fc0 str r3, [r11, #0x8]
 *   @0x113fc4 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x113fc8 mov r0, r11
 *   @0x113fcc bl 0x27d1d0 <_ZdlPv>
 *   @0x113fd0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x113fd4 mov r0, r11
 *   @0x113fd8 bl 0x27d1d0 <_ZdlPv>
 *   @0x113fdc b 0x113f00 <_Z9YYGML_minR8YYRValueiPPS_+0x2ec>
 *
 * ══ §10/33 YYGML_max(YYRValue&, int, YYRValue**)  0x113fe0  size 972  243 条（0x113fe0..0x1143ac）
 * @func 0x113fe0 0x1143ac  size 972  243 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / YYGetReal(RValue const*, int)×2 / GetContextStackTop()×2 / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)×2 / YYGML_max(YYRValue&, int, YYRValue**)+0x190
 * 字段偏移 top8: 0x4×19 / 0x8×11 / 0xc×9 / 0x-4×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x113fe0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x113fe4 vpush {d8, d9}
 *   @0x113fe8 subs r8, r1, #0
 *   @0x113fec mov r3, #0
 *   @0x113ff0 sub sp, sp, #12
 *   @0x113ff4 mov r4, r0
 *   @0x113ff8 mov r7, r2
 *   @0x113ffc str r3, [r0, #0xc]
 *   @0x114000 str r3, [r0]
 *   @0x114004 str r3, [r0, #0x4]
 *   @0x114008 beq 0x114170 <_Z9YYGML_maxR8YYRValueiPPS_+0x190>
 *   @0x11400c ldr r5, [r2]
 *   @0x114010 ldr r3, [r5, #0xc]
 *   @0x114014 ldr r2, [r5, #0x8]
 *   @0x114018 str r3, [r0, #0xc]
 *   @0x11401c ldr r3, [r5, #0xc]
 *   @0x114020 str r2, [r0, #0x8]
 *   @0x114024 bic r3, r3, #-16777216
 *   @0x114028 cmp r3, #14
 *   @0x11402c addls pc, pc, r3, lsl #2
 *   @0x114030 b 0x114078 <_Z9YYGML_maxR8YYRValueiPPS_+0x98>
 *   @0x114034 b 0x114290 <_Z9YYGML_maxR8YYRValueiPPS_+0x2b0>
 *   @0x114038 b 0x1142dc <_Z9YYGML_maxR8YYRValueiPPS_+0x2fc>
 *   @0x11403c b 0x1142f4 <_Z9YYGML_maxR8YYRValueiPPS_+0x314>
 *   @0x114040 b 0x114070 <_Z9YYGML_maxR8YYRValueiPPS_+0x90>
 *   @0x114044 b 0x114078 <_Z9YYGML_maxR8YYRValueiPPS_+0x98>
 *   @0x114048 b 0x114078 <_Z9YYGML_maxR8YYRValueiPPS_+0x98>
 *   @0x11404c b 0x114320 <_Z9YYGML_maxR8YYRValueiPPS_+0x340>
 *   @0x114050 b 0x114070 <_Z9YYGML_maxR8YYRValueiPPS_+0x90>
 *   @0x114054 b 0x114078 <_Z9YYGML_maxR8YYRValueiPPS_+0x98>
 *   @0x114058 b 0x114078 <_Z9YYGML_maxR8YYRValueiPPS_+0x98>
 *   @0x11405c b 0x114290 <_Z9YYGML_maxR8YYRValueiPPS_+0x2b0>
 *   @0x114060 b 0x114078 <_Z9YYGML_maxR8YYRValueiPPS_+0x98>
 *   @0x114064 b 0x114078 <_Z9YYGML_maxR8YYRValueiPPS_+0x98>
 *   @0x114068 b 0x114290 <_Z9YYGML_maxR8YYRValueiPPS_+0x2b0>
 *   @0x11406c b 0x114070 <_Z9YYGML_maxR8YYRValueiPPS_+0x90>
 *   @0x114070 ldr r3, [r5]
 *   @0x114074 str r3, [r4]
 *   @0x114078 ldr r0, [r7]
 *   @0x11407c mov r1, #0
 *   @0x114080 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x114084 cmp r8, #1
 *   @0x114088 vmov d9, r0, r1
 *   @0x11408c ble 0x114170 <_Z9YYGML_maxR8YYRValueiPPS_+0x190>
 *   @0x114090 add r7, r7, #4
 *   @0x114094 mov r5, #1
 *   @0x114098 mov r9, #0
 *   @0x11409c mov r10, #5
 *   @0x1140a0 ldr r0, [r7], #4
 *   @0x1140a4 mov r1, #0
 *   @0x1140a8 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x1140ac vmov d8, r0, r1
 *   @0x1140b0 vcmpe.f64 d8, d9
 *   @0x1140b4 vmrs APSR_nzcv, fpscr
 *   @0x1140b8 ble 0x114164 <_Z9YYGML_maxR8YYRValueiPPS_+0x184>
 *   @0x1140bc ldr r2, [r4, #0xc]
 *   @0x1140c0 ldr r6, [r7, #-0x4]
 *   @0x1140c4 bic r3, r2, #-16777216
 *   @0x1140c8 cmp r3, #1
 *   @0x1140cc beq 0x1141cc <_Z9YYGML_maxR8YYRValueiPPS_+0x1ec>
 *   @0x1140d0 cmp r3, #2
 *   @0x1140d4 bne 0x1140f4 <_Z9YYGML_maxR8YYRValueiPPS_+0x114>
 *   @0x1140d8 sub r2, r2, #1
 *   @0x1140dc bic r2, r2, #-16777216
 *   @0x1140e0 bic r2, r2, #3
 *   @0x1140e4 cmp r2, #0
 *   @0x1140e8 beq 0x114284 <_Z9YYGML_maxR8YYRValueiPPS_+0x2a4>
 *   @0x1140ec str r9, [r4, #0x8]
 *   @0x1140f0 str r10, [r4, #0xc]
 *   @0x1140f4 ldr r3, [r6, #0xc]
 *   @0x1140f8 ldr r2, [r6, #0x8]
 *   @0x1140fc str r9, [r4]
 *   @0x114100 str r3, [r4, #0xc]
 *   @0x114104 ldr r3, [r6, #0xc]
 *   @0x114108 str r2, [r4, #0x8]
 *   @0x11410c bic r3, r3, #-16777216
 *   @0x114110 cmp r3, #14
 *   @0x114114 addls pc, pc, r3, lsl #2
 *   @0x114118 b 0x1141c4 <_Z9YYGML_maxR8YYRValueiPPS_+0x1e4>
 *   @0x11411c b 0x114180 <_Z9YYGML_maxR8YYRValueiPPS_+0x1a0>
 *   @0x114120 b 0x114224 <_Z9YYGML_maxR8YYRValueiPPS_+0x244>
 *   @0x114124 b 0x114194 <_Z9YYGML_maxR8YYRValueiPPS_+0x1b4>
 *   @0x114128 b 0x114158 <_Z9YYGML_maxR8YYRValueiPPS_+0x178>
 *   @0x11412c b 0x1141c4 <_Z9YYGML_maxR8YYRValueiPPS_+0x1e4>
 *   @0x114130 b 0x1141c4 <_Z9YYGML_maxR8YYRValueiPPS_+0x1e4>
 *   @0x114134 b 0x1141fc <_Z9YYGML_maxR8YYRValueiPPS_+0x21c>
 *   @0x114138 b 0x114158 <_Z9YYGML_maxR8YYRValueiPPS_+0x178>
 *   @0x11413c b 0x1141c4 <_Z9YYGML_maxR8YYRValueiPPS_+0x1e4>
 *   @0x114140 b 0x1141c4 <_Z9YYGML_maxR8YYRValueiPPS_+0x1e4>
 *   @0x114144 b 0x114180 <_Z9YYGML_maxR8YYRValueiPPS_+0x1a0>
 *   @0x114148 b 0x1141c4 <_Z9YYGML_maxR8YYRValueiPPS_+0x1e4>
 *   @0x11414c b 0x1141c4 <_Z9YYGML_maxR8YYRValueiPPS_+0x1e4>
 *   @0x114150 b 0x114180 <_Z9YYGML_maxR8YYRValueiPPS_+0x1a0>
 *   @0x114154 b 0x114158 <_Z9YYGML_maxR8YYRValueiPPS_+0x178>
 *   @0x114158 vmov.f64 d9, d8
 *   @0x11415c ldr r3, [r6]
 *   @0x114160 str r3, [r4]
 *   @0x114164 add r5, r5, #1
 *   @0x114168 cmp r5, r8
 *   @0x11416c bne 0x1140a0 <_Z9YYGML_maxR8YYRValueiPPS_+0xc0>
 *   @0x114170 mov r0, r4
 *   @0x114174 add sp, sp, #12
 *   @0x114178 vpop {d8, d9}
 *   @0x11417c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x114180 ldr r2, [r6]
 *   @0x114184 vmov.f64 d9, d8
 *   @0x114188 ldr r3, [r6, #0x4]
 *   @0x11418c stm r4, {r2, r3}
 *   @0x114190 b 0x114164 <_Z9YYGML_maxR8YYRValueiPPS_+0x184>
 *   @0x114194 ldr r3, [r6]
 *   @0x114198 cmp r3, #0
 *   @0x11419c str r3, [r4]
 *   @0x1141a0 beq 0x1141c4 <_Z9YYGML_maxR8YYRValueiPPS_+0x1e4>
 *   @0x1141a4 ldr r1, [r3, #0x8]
 *   @0x1141a8 ldr r2, [r3]
 *   @0x1141ac cmp r1, #0
 *   @0x1141b0 streq r4, [r3, #0x8]
 *   @0x1141b4 add r2, r2, #1
 *   @0x1141b8 str r2, [r3]
 *   @0x1141bc vmoveq.f64 d9, d8
 *   @0x1141c0 beq 0x114164 <_Z9YYGML_maxR8YYRValueiPPS_+0x184>
 *   @0x1141c4 vmov.f64 d9, d8
 *   @0x1141c8 b 0x114164 <_Z9YYGML_maxR8YYRValueiPPS_+0x184>
 *   @0x1141cc ldr r11, [r4]
 *   @0x1141d0 cmp r11, #0
 *   @0x1141d4 beq 0x1141f4 <_Z9YYGML_maxR8YYRValueiPPS_+0x214>
 *   @0x1141d8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1141dc ldr r3, [r11, #0x4]
 *   @0x1141e0 sub r3, r3, #1
 *   @0x1141e4 str r3, [r11, #0x4]
 *   @0x1141e8 cmp r3, #0
 *   @0x1141ec beq 0x114244 <_Z9YYGML_maxR8YYRValueiPPS_+0x264>
 *   @0x1141f0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1141f4 str r9, [r4]
 *   @0x1141f8 b 0x1140f4 <_Z9YYGML_maxR8YYRValueiPPS_+0x114>
 *   @0x1141fc ldr r3, [r6]
 *   @0x114200 str r3, [r4]
 *   @0x114204 ldr r3, [r6]
 *   @0x114208 cmp r3, #0
 *   @0x11420c beq 0x1141c4 <_Z9YYGML_maxR8YYRValueiPPS_+0x1e4>
 *   @0x114210 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x114214 ldr r1, [r6]
 *   @0x114218 vmov.f64 d9, d8
 *   @0x11421c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x114220 b 0x114164 <_Z9YYGML_maxR8YYRValueiPPS_+0x184>
 *   @0x114224 ldr r3, [r6]
 *   @0x114228 vmov.f64 d9, d8
 *   @0x11422c cmp r3, #0
 *   @0x114230 ldrne r2, [r3, #0x4]
 *   @0x114234 addne r2, r2, #1
 *   @0x114238 strne r2, [r3, #0x4]
 *   @0x11423c str r3, [r4]
 *   @0x114240 b 0x114164 <_Z9YYGML_maxR8YYRValueiPPS_+0x184>
 *   @0x114244 ldr r0, [r11]
 *   @0x114248 str r3, [sp, #0x4]
 *   @0x11424c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x114250 ldr r3, [sp, #0x4]
 *   @0x114254 str r3, [r11]
 *   @0x114258 str r3, [r11, #0x8]
 *   @0x11425c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x114260 ldr r3, [r11, #0x4]
 *   @0x114264 sub r3, r3, #1
 *   @0x114268 str r3, [r11, #0x4]
 *   @0x11426c cmp r3, #0
 *   @0x114270 beq 0x11429c <_Z9YYGML_maxR8YYRValueiPPS_+0x2bc>
 *   @0x114274 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x114278 mov r0, r11
 *   @0x11427c bl 0x27d1d0 <_ZdlPv>
 *   @0x114280 b 0x1141f0 <_Z9YYGML_maxR8YYRValueiPPS_+0x210>
 *   @0x114284 mov r0, r4
 *   @0x114288 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x11428c b 0x1140ec <_Z9YYGML_maxR8YYRValueiPPS_+0x10c>
 *   @0x114290 ldm r5, {r2, r3}
 *   @0x114294 stm r0, {r2, r3}
 *   @0x114298 b 0x114078 <_Z9YYGML_maxR8YYRValueiPPS_+0x98>
 *   @0x11429c ldr r0, [r11]
 *   @0x1142a0 str r3, [sp, #0x4]
 *   @0x1142a4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1142a8 ldr r3, [sp, #0x4]
 *   @0x1142ac str r3, [r11]
 *   @0x1142b0 str r3, [r11, #0x8]
 *   @0x1142b4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1142b8 ldr r3, [r11, #0x4]
 *   @0x1142bc sub r3, r3, #1
 *   @0x1142c0 str r3, [r11, #0x4]
 *   @0x1142c4 cmp r3, #0
 *   @0x1142c8 beq 0x114344 <_Z9YYGML_maxR8YYRValueiPPS_+0x364>
 *   @0x1142cc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1142d0 mov r0, r11
 *   @0x1142d4 bl 0x27d1d0 <_ZdlPv>
 *   @0x1142d8 b 0x114274 <_Z9YYGML_maxR8YYRValueiPPS_+0x294>
 *   @0x1142dc ldr r3, [r5]
 *   @0x1142e0 cmp r3, #0
 *   @0x1142e4 ldrne r2, [r3, #0x4]
 *   @0x1142e8 addne r2, r2, #1
 *   @0x1142ec strne r2, [r3, #0x4]
 *   @0x1142f0 b 0x114074 <_Z9YYGML_maxR8YYRValueiPPS_+0x94>
 *   @0x1142f4 ldr r3, [r5]
 *   @0x1142f8 cmp r3, #0
 *   @0x1142fc str r3, [r0]
 *   @0x114300 beq 0x114078 <_Z9YYGML_maxR8YYRValueiPPS_+0x98>
 *   @0x114304 ldr r1, [r3, #0x8]
 *   @0x114308 ldr r2, [r3]
 *   @0x11430c cmp r1, #0
 *   @0x114310 streq r0, [r3, #0x8]
 *   @0x114314 add r2, r2, #1
 *   @0x114318 str r2, [r3]
 *   @0x11431c b 0x114078 <_Z9YYGML_maxR8YYRValueiPPS_+0x98>
 *   @0x114320 ldr r3, [r5]
 *   @0x114324 str r3, [r0]
 *   @0x114328 ldr r3, [r5]
 *   @0x11432c cmp r3, #0
 *   @0x114330 beq 0x114078 <_Z9YYGML_maxR8YYRValueiPPS_+0x98>
 *   @0x114334 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x114338 ldr r1, [r5]
 *   @0x11433c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x114340 b 0x114078 <_Z9YYGML_maxR8YYRValueiPPS_+0x98>
 *   @0x114344 ldr r0, [r11]
 *   @0x114348 str r3, [sp, #0x4]
 *   @0x11434c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x114350 ldr r3, [sp, #0x4]
 *   @0x114354 str r3, [r11]
 *   @0x114358 str r3, [r11, #0x8]
 *   @0x11435c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x114360 ldr r3, [r11, #0x4]
 *   @0x114364 sub r3, r3, #1
 *   @0x114368 str r3, [r11, #0x4]
 *   @0x11436c cmp r3, #0
 *   @0x114370 bne 0x11439c <_Z9YYGML_maxR8YYRValueiPPS_+0x3bc>
 *   @0x114374 ldr r0, [r11]
 *   @0x114378 str r3, [sp, #0x4]
 *   @0x11437c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x114380 ldr r3, [sp, #0x4]
 *   @0x114384 mov r0, r11
 *   @0x114388 str r3, [r11]
 *   @0x11438c str r3, [r11, #0x8]
 *   @0x114390 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x114394 mov r0, r11
 *   @0x114398 bl 0x27d1d0 <_ZdlPv>
 *   @0x11439c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1143a0 mov r0, r11
 *   @0x1143a4 bl 0x27d1d0 <_ZdlPv>
 *   @0x1143a8 b 0x1142cc <_Z9YYGML_maxR8YYRValueiPPS_+0x2ec>
 *
 * ══ §11/33 GraphicsPerf::oprintf_wrap(int, int, unsigned int, unsigned int, char const*, ...)  0x17ca30  size 972  243 条（0x17ca30..0x17cdfc）
 * @func 0x17ca30 0x17cdfc  size 972  243 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x17ca9c→0x3f26c0, 0x17cb04→0x3f2484, 0x17cc5c→0x3f2484
 * 调用序列: GraphicsPerf::Print(float, float, float, float, unsigned int, char*, int)×5 / 0xb667c / GraphicsPerf::oprintf_wrap(int, int, unsigned int, unsigned int, char const*, ...)+0x274 / GraphicsPerf::oprintf_wrap(int, int, unsigned int, unsigned int, char const*, ...)+0x280 / 0xb65d4
 * 字段偏移 top8: 0x1c×6 / 0x4×5 / 0x8×5 / 0x14×3 / 0x10×3 / 0x20×2 / 0x28×2 / 0x2c×2
 * VFP 指令 28 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17ca30 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x17ca34 vpush {d8, d9}
 *   @0x17ca38 sub sp, sp, #2096
 *   @0x17ca3c sub sp, sp, #12
 *   @0x17ca40 ldr r10, [pc, #0x3a4]
 *   @0x17ca44 mov r8, r1
 *   @0x17ca48 str r0, [sp, #0x20]
 *   @0x17ca4c add r10, pc, r10
 *   @0x17ca50 ldr r0, [pc, #0x398]
 *   @0x17ca54 str r10, [sp, #0x14]
 *   @0x17ca58 str r3, [sp, #0x28]
 *   @0x17ca5c str r2, [sp, #0x1c]
 *   @0x17ca60 ldr r0, [r10, r0]
 *   @0x17ca64 ldr r1, [sp, #0x870]
 *   @0x17ca68 ldr r3, [r0]
 *   @0x17ca6c cmp r1, #0
 *   @0x17ca70 str r0, [sp, #0x2c]
 *   @0x17ca74 str r3, [sp, #0x834]
 *   @0x17ca78 beq 0x17ccc0 <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0x290>
 *   @0x17ca7c add r3, sp, #2160
 *   @0x17ca80 add r2, sp, #52
 *   @0x17ca84 add r3, r3, #4
 *   @0x17ca88 str r2, [sp, #0x18]
 *   @0x17ca8c add r0, sp, #52
 *   @0x17ca90 str r3, [sp, #0x30]
 *   @0x17ca94 mov r2, r3
 *   @0x17ca98 bl 0xb667c <vsprintf@plt>
 *   @0x17ca9c ldr r2, [pc, #0x350]
 *   @0x17caa0 ldrb r3, [sp, #0x34]
 *   @0x17caa4 ldr r2, [r10, r2]
 *   @0x17caa8 cmp r3, #0
 *   @0x17caac ldr r7, [r2]
 *   @0x17cab0 sub r7, r7, #4
 *   @0x17cab4 beq 0x17ccc0 <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0x290>
 *   @0x17cab8 vmov.f32 s19, #1.000000e+00
 *   @0x17cabc mvn r6, #0
 *   @0x17cac0 str r8, [sp, #0x10]
 *   @0x17cac4 mov r4, #0
 *   @0x17cac8 mov r8, r6
 *   @0x17cacc movw r10, #0x4567
 *   @0x17cad0 movt r10, #0x8123
 *   @0x17cad4 str r10, [sp, #0x24]
 *   @0x17cad8 vmov.f32 s18, #2.000000e+00
 *   @0x17cadc cmp r3, #32
 *   @0x17cae0 cmpne r3, #10
 *   @0x17cae4 mov r0, r4
 *   @0x17cae8 beq 0x17cb78 <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0x148>
 *   @0x17caec cmp r3, #0
 *   @0x17caf0 beq 0x17cdd4 <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0x3a4>
 *   @0x17caf4 cmp r7, #0
 *   @0x17caf8 blt 0x17cca4 <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0x274>
 *   @0x17cafc cmp r3, #10
 *   @0x17cb00 beq 0x17cce8 <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0x2b8>
 *   @0x17cb04 ldr r9, [pc, #0x2ec]
 *   @0x17cb08 add r1, sp, #52
 *   @0x17cb0c ldr r10, [sp, #0x14]
 *   @0x17cb10 add r12, r1, r4
 *   @0x17cb14 mov r2, r4
 *   @0x17cb18 mov r5, #0
 *   @0x17cb1c mvn r1, #0
 *   @0x17cb20 ldr r11, [r10, r9]
 *   @0x17cb24 b 0x17cb58 <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0x128>
 *   @0x17cb28 add r9, r11, r3, lsl #2
 *   @0x17cb2c ldrb r3, [r12, #0x1]!
 *   @0x17cb30 add r10, r2, #1
 *   @0x17cb34 ldrb r9, [r9, #-0x7e]
 *   @0x17cb38 cmp r3, #0
 *   @0x17cb3c add r5, r5, r9
 *   @0x17cb40 beq 0x17cd08 <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0x2d8>
 *   @0x17cb44 cmp r7, r5
 *   @0x17cb48 blt 0x17ccb0 <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0x280>
 *   @0x17cb4c cmp r3, #10
 *   @0x17cb50 beq 0x17ccf0 <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0x2c0>
 *   @0x17cb54 mov r2, r10
 *   @0x17cb58 cmp r3, #32
 *   @0x17cb5c movne r6, r2
 *   @0x17cb60 bne 0x17cb28 <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0xf8>
 *   @0x17cb64 cmp r6, #0
 *   @0x17cb68 movgt r1, r5
 *   @0x17cb6c movgt r8, r2
 *   @0x17cb70 mvngt r6, #0
 *   @0x17cb74 b 0x17cb28 <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0xf8>
 *   @0x17cb78 cmp r3, #0
 *   @0x17cb7c beq 0x17cba8 <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0x178>
 *   @0x17cb80 add r12, sp, #52
 *   @0x17cb84 add r2, r12, r4
 *   @0x17cb88 ldrb r3, [r2, #0x1]!
 *   @0x17cb8c add r4, r4, #1
 *   @0x17cb90 cmp r3, #32
 *   @0x17cb94 cmpne r3, #10
 *   @0x17cb98 mov r0, r4
 *   @0x17cb9c bne 0x17caec <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0xbc>
 *   @0x17cba0 cmp r3, #0
 *   @0x17cba4 bne 0x17cb88 <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0x158>
 *   @0x17cba8 mvn r2, #0
 *   @0x17cbac mov r3, r4
 *   @0x17cbb0 mov r1, r2
 *   @0x17cbb4 mov r5, #0
 *   @0x17cbb8 cmp r7, r5
 *   @0x17cbbc movlt r4, r2
 *   @0x17cbc0 cmp r5, #0
 *   @0x17cbc4 beq 0x17ccc0 <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0x290>
 *   @0x17cbc8 add r12, sp, #2096
 *   @0x17cbcc add r12, r12, #8
 *   @0x17cbd0 add r2, r12, r4
 *   @0x17cbd4 ldrb r2, [r2, #-0x804]
 *   @0x17cbd8 tst r2, #223
 *   @0x17cbdc beq 0x17cc9c <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0x26c>
 *   @0x17cbe0 cmp r2, #10
 *   @0x17cbe4 movne r5, r1
 *   @0x17cbe8 movne r9, r8
 *   @0x17cbec movne r4, r8
 *   @0x17cbf0 beq 0x17cc9c <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0x26c>
 *   @0x17cbf4 ldr r10, [sp, #0x20]
 *   @0x17cbf8 add r1, sp, #52
 *   @0x17cbfc ldr r12, [sp, #0x24]
 *   @0x17cc00 vldr s15, [sp, #16]
 *   @0x17cc04 add r11, r1, r0
 *   @0x17cc08 vcvt.f32.s32 s16, s15
 *   @0x17cc0c cmp r10, r12
 *   @0x17cc10 rsb r10, r3, r4
 *   @0x17cc14 rsbeq r3, r5, r7
 *   @0x17cc18 ldr r12, [sp, #0x1c]
 *   @0x17cc1c vldrne s17, [sp, #32]
 *   @0x17cc20 addeq r3, r3, r3, lsr #31
 *   @0x17cc24 asreq r3, r3, #1
 *   @0x17cc28 vmoveq s17, r3
 *   @0x17cc2c cmp r12, #0
 *   @0x17cc30 bne 0x17cd14 <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0x2e4>
 *   @0x17cc34 vcvt.f32.s32 s17, s17
 *   @0x17cc38 ldr r12, [sp, #0x28]
 *   @0x17cc3c mov r2, #1065353216
 *   @0x17cc40 mov r3, r2
 *   @0x17cc44 str r11, [sp, #0x4]
 *   @0x17cc48 str r10, [sp, #0x8]
 *   @0x17cc4c str r12, [sp]
 *   @0x17cc50 vmov r1, s16
 *   @0x17cc54 vmov r0, s17
 *   @0x17cc58 bl 0x17c030 <_ZN12GraphicsPerf5PrintEffffjPci>
 *   @0x17cc5c ldr r3, [pc, #0x194]
 *   @0x17cc60 ldr r10, [sp, #0x14]
 *   @0x17cc64 add r1, sp, #2096
 *   @0x17cc68 add r1, r1, #8
 *   @0x17cc6c ldr r12, [sp, #0x10]
 *   @0x17cc70 add r9, r1, r9
 *   @0x17cc74 ldr r11, [r10, r3]
 *   @0x17cc78 ldrb r3, [r9, #-0x804]
 *   @0x17cc7c ldrb r2, [r11, #0x83]
 *   @0x17cc80 cmp r3, #0
 *   @0x17cc84 add r2, r2, #2
 *   @0x17cc88 add r12, r12, r2
 *   @0x17cc8c str r12, [sp, #0x10]
 *   @0x17cc90 bne 0x17cadc <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0xac>
 *   @0x17cc94 mov r0, r5
 *   @0x17cc98 b 0x17ccc4 <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0x294>
 *   @0x17cc9c mov r9, r4
 *   @0x17cca0 b 0x17cbf4 <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0x1c4>
 *   @0x17cca4 mvn r2, #0
 *   @0x17cca8 mov r5, #0
 *   @0x17ccac mov r1, r2
 *   @0x17ccb0 cmp r5, #0
 *   @0x17ccb4 mov r3, r4
 *   @0x17ccb8 mov r4, r2
 *   @0x17ccbc bne 0x17cbc8 <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0x198>
 *   @0x17ccc0 mov r0, #0
 *   @0x17ccc4 ldr r10, [sp, #0x2c]
 *   @0x17ccc8 ldr r2, [sp, #0x834]
 *   @0x17cccc ldr r3, [r10]
 *   @0x17ccd0 cmp r2, r3
 *   @0x17ccd4 bne 0x17cde8 <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0x3b8>
 *   @0x17ccd8 add sp, sp, #2096
 *   @0x17ccdc add sp, sp, #12
 *   @0x17cce0 vpop {d8, d9}
 *   @0x17cce4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x17cce8 mov r10, r4
 *   @0x17ccec mov r5, #0
 *   @0x17ccf0 mov r3, r4
 *   @0x17ccf4 mov r8, r10
 *   @0x17ccf8 mov r4, r10
 *   @0x17ccfc mov r1, r5
 *   @0x17cd00 mvn r6, #0
 *   @0x17cd04 b 0x17cbc0 <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0x190>
 *   @0x17cd08 mov r3, r4
 *   @0x17cd0c mov r4, r10
 *   @0x17cd10 b 0x17cbb8 <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0x188>
 *   @0x17cd14 vmov r1, s17
 *   @0x17cd18 mov r2, #1065353216
 *   @0x17cd1c ldr r12, [sp, #0x1c]
 *   @0x17cd20 mov r3, r2
 *   @0x17cd24 str r11, [sp, #0x4]
 *   @0x17cd28 str r10, [sp, #0x8]
 *   @0x17cd2c str r12, [sp]
 *   @0x17cd30 sub r0, r1, #1
 *   @0x17cd34 vmov r1, s16
 *   @0x17cd38 vmov s15, r0
 *   @0x17cd3c vcvt.f32.s32 s15, s15
 *   @0x17cd40 vmov r0, s15
 *   @0x17cd44 bl 0x17c030 <_ZN12GraphicsPerf5PrintEffffjPci>
 *   @0x17cd48 vmov r1, s17
 *   @0x17cd4c ldr r12, [sp, #0x1c]
 *   @0x17cd50 mov r2, #1065353216
 *   @0x17cd54 mov r3, r2
 *   @0x17cd58 str r11, [sp, #0x4]
 *   @0x17cd5c str r10, [sp, #0x8]
 *   @0x17cd60 str r12, [sp]
 *   @0x17cd64 add r0, r1, #1
 *   @0x17cd68 vmov r1, s16
 *   @0x17cd6c vmov s15, r0
 *   @0x17cd70 vcvt.f32.s32 s15, s15
 *   @0x17cd74 vmov r0, s15
 *   @0x17cd78 bl 0x17c030 <_ZN12GraphicsPerf5PrintEffffjPci>
 *   @0x17cd7c vsub.f32 s15, s16, s19
 *   @0x17cd80 ldr r12, [sp, #0x1c]
 *   @0x17cd84 mov r2, #1065353216
 *   @0x17cd88 mov r3, r2
 *   @0x17cd8c str r11, [sp, #0x4]
 *   @0x17cd90 str r10, [sp, #0x8]
 *   @0x17cd94 str r12, [sp]
 *   @0x17cd98 vcvt.f32.s32 s17, s17
 *   @0x17cd9c vmov r1, s15
 *   @0x17cda0 vmov r0, s17
 *   @0x17cda4 bl 0x17c030 <_ZN12GraphicsPerf5PrintEffffjPci>
 *   @0x17cda8 vadd.f32 s15, s16, s18
 *   @0x17cdac ldr r12, [sp, #0x1c]
 *   @0x17cdb0 mov r2, #1065353216
 *   @0x17cdb4 str r11, [sp, #0x4]
 *   @0x17cdb8 mov r3, r2
 *   @0x17cdbc str r10, [sp, #0x8]
 *   @0x17cdc0 str r12, [sp]
 *   @0x17cdc4 vmov r0, s17
 *   @0x17cdc8 vmov r1, s15
 *   @0x17cdcc bl 0x17c030 <_ZN12GraphicsPerf5PrintEffffjPci>
 *   @0x17cdd0 b 0x17cc38 <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0x208>
 *   @0x17cdd4 mvn r2, #0
 *   @0x17cdd8 mov r5, r3
 *   @0x17cddc mov r1, r2
 *   @0x17cde0 mov r3, r4
 *   @0x17cde4 b 0x17cbb8 <_ZN12GraphicsPerf12oprintf_wrapEiijjPKcz+0x188>
 *   @0x17cde8 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x17cdec eoreq r5, r7, r4, lsl #4
 *   @0x17cdf0 .word 0xffffbd00
 *   @0x17cdf4 .word 0xffffe24c
 *   @0x17cdf8 .word 0xffffe64c
 *
 * ══ §12/33 ReadPNG(yyPNGFile*)  0x189e80  size 972  243 条（0x189e80..0x18a24c）
 * @func 0x189e80 0x18a24c  size 972  243 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x18a0e0→0x3eb70c, 0x18a144→0x3eb70c, 0x18a18c→0x3eb70c
 * 调用序列: png_destroy_read_struct×3 / png_create_info_struct×2 / operator new[](unsigned int)×2 / png_sig_cmp / png_create_read_struct / png_set_longjmp_fn / 0xb6904 / png_set_read_fn
 * 字段偏移 top8: 0x18×35 / 0x14×16 / 0x1c×6 / 0x2c×5 / 0x24×4 / 0x28×4 / 0xc×4 / 0x20×4
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x189e80 push {r4, lr}
 *   @0x189e84 sub sp, sp, #56
 *   @0x189e88 mov r1, #0
 *   @0x189e8c mov r2, #8
 *   @0x189e90 str r0, [sp, #0x18]
 *   @0x189e94 ldr r0, [r0, #0x4]
 *   @0x189e98 blx 0x2a5a4c <png_sig_cmp>
 *   @0x189e9c ldr r1, [pc, #0x38c]
 *   @0x189ea0 add r1, pc, r1
 *   @0x189ea4 str r1, [sp, #0x1c]
 *   @0x189ea8 subs r1, r0, #0
 *   @0x189eac bne 0x18a0dc <_Z7ReadPNGP9yyPNGFile+0x25c>
 *   @0x189eb0 ldr r0, [pc, #0x37c]
 *   @0x189eb4 mov r2, r1
 *   @0x189eb8 mov r3, r1
 *   @0x189ebc add r0, pc, r0
 *   @0x189ec0 blx 0x2a6fdc <png_create_read_struct>
 *   @0x189ec4 ldr r2, [sp, #0x18]
 *   @0x189ec8 cmp r0, #0
 *   @0x189ecc str r0, [r2, #0x14]
 *   @0x189ed0 beq 0x18a144 <_Z7ReadPNGP9yyPNGFile+0x2c4>
 *   @0x189ed4 blx 0x2a5b64 <png_create_info_struct>
 *   @0x189ed8 ldr r3, [sp, #0x18]
 *   @0x189edc cmp r0, #0
 *   @0x189ee0 str r0, [r3, #0x18]
 *   @0x189ee4 beq 0x18a1b8 <_Z7ReadPNGP9yyPNGFile+0x338>
 *   @0x189ee8 ldr r12, [sp, #0x18]
 *   @0x189eec ldr r0, [r12, #0x14]
 *   @0x189ef0 blx 0x2a5b64 <png_create_info_struct>
 *   @0x189ef4 ldr r1, [sp, #0x18]
 *   @0x189ef8 cmp r0, #0
 *   @0x189efc str r0, [r1, #0x1c]
 *   @0x189f00 beq 0x18a134 <_Z7ReadPNGP9yyPNGFile+0x2b4>
 *   @0x189f04 ldr r12, [sp, #0x18]
 *   @0x189f08 mov r2, #256
 *   @0x189f0c ldr r3, [pc, #0x324]
 *   @0x189f10 ldr r0, [r12, #0x14]
 *   @0x189f14 ldr r12, [sp, #0x1c]
 *   @0x189f18 ldr r1, [r12, r3]
 *   @0x189f1c blx 0x2a653c <png_set_longjmp_fn>
 *   @0x189f20 bl 0xb6904 <setjmp@plt>
 *   @0x189f24 subs r4, r0, #0
 *   @0x189f28 bne 0x18a174 <_Z7ReadPNGP9yyPNGFile+0x2f4>
 *   @0x189f2c ldr r12, [sp, #0x18]
 *   @0x189f30 add r1, sp, #48
 *   @0x189f34 ldr r2, [pc, #0x300]
 *   @0x189f38 ldr r3, [r12, #0x4]
 *   @0x189f3c add r2, pc, r2
 *   @0x189f40 ldr r0, [r12, #0x14]
 *   @0x189f44 add r3, r3, #8
 *   @0x189f48 str r12, [sp, #0x30]
 *   @0x189f4c str r3, [sp, #0x34]
 *   @0x189f50 blx 0x2a804c <png_set_read_fn>
 *   @0x189f54 ldr r1, [sp, #0x18]
 *   @0x189f58 ldr r0, [r1, #0x14]
 *   @0x189f5c mov r1, #8
 *   @0x189f60 blx 0x2a5a24 <png_set_sig_bytes>
 *   @0x189f64 ldr r2, [sp, #0x18]
 *   @0x189f68 ldr r0, [r2, #0x14]
 *   @0x189f6c ldr r1, [r2, #0x18]
 *   @0x189f70 blx 0x2a6ff0 <png_read_info>
 *   @0x189f74 ldr r3, [sp, #0x18]
 *   @0x189f78 ldr r1, [r3, #0x18]
 *   @0x189f7c ldr r0, [r3, #0x14]
 *   @0x189f80 blx 0x2a65a6 <png_get_bit_depth>
 *   @0x189f84 ldr r12, [sp, #0x18]
 *   @0x189f88 ldr r1, [r12, #0x18]
 *   @0x189f8c str r0, [sp, #0x24]
 *   @0x189f90 ldr r0, [r12, #0x14]
 *   @0x189f94 blx 0x2a65b2 <png_get_color_type>
 *   @0x189f98 cmp r0, #3
 *   @0x189f9c str r0, [sp, #0x28]
 *   @0x189fa0 movne r3, r0
 *   @0x189fa4 beq 0x18a1e0 <_Z7ReadPNGP9yyPNGFile+0x360>
 *   @0x189fa8 bics r2, r3, #4
 *   @0x189fac beq 0x18a1cc <_Z7ReadPNGP9yyPNGFile+0x34c>
 *   @0x189fb0 bics r12, r3, #2
 *   @0x189fb4 beq 0x18a1a0 <_Z7ReadPNGP9yyPNGFile+0x320>
 *   @0x189fb8 eor r4, r4, #1
 *   @0x189fbc cmp r3, #3
 *   @0x189fc0 movne r3, #0
 *   @0x189fc4 andeq r3, r4, #1
 *   @0x189fc8 cmp r3, #0
 *   @0x189fcc bne 0x18a1a0 <_Z7ReadPNGP9yyPNGFile+0x320>
 *   @0x189fd0 ldr r2, [sp, #0x18]
 *   @0x189fd4 add r3, sp, #36
 *   @0x189fd8 ldr r1, [r2, #0x18]
 *   @0x189fdc ldr r0, [r2, #0x14]
 *   @0x189fe0 add r2, sp, #40
 *   @0x189fe4 str r3, [sp]
 *   @0x189fe8 mov r3, #0
 *   @0x189fec stmib sp, {r2, r3}
 *   @0x189ff0 add r2, sp, #32
 *   @0x189ff4 str r3, [sp, #0xc]
 *   @0x189ff8 str r3, [sp, #0x10]
 *   @0x189ffc add r3, sp, #44
 *   @0x18a000 blx 0x2a693e <png_get_IHDR>
 *   @0x18a004 ldr r1, [sp, #0x28]
 *   @0x18a008 ldr r12, [sp, #0x18]
 *   @0x18a00c ldr r2, [sp, #0x20]
 *   @0x18a010 cmp r1, #3
 *   @0x18a014 ldr r3, [sp, #0x2c]
 *   @0x18a018 str r2, [r12, #0xc]
 *   @0x18a01c str r3, [r12, #0x10]
 *   @0x18a020 beq 0x18a21c <_Z7ReadPNGP9yyPNGFile+0x39c>
 *   @0x18a024 ldr r1, [sp, #0x18]
 *   @0x18a028 ldr r0, [r1, #0x14]
 *   @0x18a02c ldr r1, [r1, #0x18]
 *   @0x18a030 blx 0x2a7448 <png_read_update_info>
 *   @0x18a034 ldr r2, [sp, #0x18]
 *   @0x18a038 ldr r0, [r2, #0x14]
 *   @0x18a03c ldr r1, [r2, #0x18]
 *   @0x18a040 blx 0x2a6574 <png_get_rowbytes>
 *   @0x18a044 ldr r12, [sp, #0x18]
 *   @0x18a048 ldr r3, [r12, #0x20]
 *   @0x18a04c cmp r3, #0
 *   @0x18a050 mov r4, r0
 *   @0x18a054 beq 0x18a158 <_Z7ReadPNGP9yyPNGFile+0x2d8>
 *   @0x18a058 ldr r0, [sp, #0x2c]
 *   @0x18a05c cmp r0, #532676608
 *   @0x18a060 lslls r0, r0, #2
 *   @0x18a064 mvnhi r0, #0
 *   @0x18a068 bl 0x27d14c <_Znaj>
 *   @0x18a06c ldr r2, [sp, #0x18]
 *   @0x18a070 cmp r0, #0
 *   @0x18a074 str r0, [r2, #0x24]
 *   @0x18a078 beq 0x18a174 <_Z7ReadPNGP9yyPNGFile+0x2f4>
 *   @0x18a07c ldr lr, [sp, #0x2c]
 *   @0x18a080 cmp lr, #0
 *   @0x18a084 beq 0x18a228 <_Z7ReadPNGP9yyPNGFile+0x3a8>
 *   @0x18a088 mov r2, #0
 *   @0x18a08c mov r1, r0
 *   @0x18a090 mov r3, r2
 *   @0x18a094 b 0x18a09c <_Z7ReadPNGP9yyPNGFile+0x21c>
 *   @0x18a098 ldr r1, [r0, #0x24]
 *   @0x18a09c ldr r0, [sp, #0x18]
 *   @0x18a0a0 ldr r12, [r0, #0x20]
 *   @0x18a0a4 add r12, r12, r2
 *   @0x18a0a8 str r12, [r1, r3, lsl #2]
 *   @0x18a0ac add r3, r3, #1
 *   @0x18a0b0 add r2, r2, r4
 *   @0x18a0b4 cmp r3, lr
 *   @0x18a0b8 bne 0x18a098 <_Z7ReadPNGP9yyPNGFile+0x218>
 *   @0x18a0bc ldr r2, [sp, #0x18]
 *   @0x18a0c0 ldr r1, [r2, #0x24]
 *   @0x18a0c4 ldr r3, [sp, #0x18]
 *   @0x18a0c8 ldr r0, [r3, #0x14]
 *   @0x18a0cc blx 0x2a7840 <png_read_image>
 *   @0x18a0d0 mov r0, #1
 *   @0x18a0d4 add sp, sp, #56
 *   @0x18a0d8 pop {r4, pc}
 *   @0x18a0dc ldr r0, [sp, #0x1c]
 *   @0x18a0e0 ldr r3, [pc, #0x158]
 *   @0x18a0e4 ldr r1, [pc, #0x158]
 *   @0x18a0e8 ldr r3, [r0, r3]
 *   @0x18a0ec add r1, pc, r1
 *   @0x18a0f0 ldr r4, [r3]
 *   @0x18a0f4 ldr r3, [r4]
 *   @0x18a0f8 mov r0, r4
 *   @0x18a0fc ldr r3, [r3, #0xc]
 *   @0x18a100 blx r3
 *   @0x18a104 mov r0, r4
 *   @0x18a108 ldr r3, [r0]
 *   @0x18a10c mov r2, #1
 *   @0x18a110 ldr r12, [sp, #0x18]
 *   @0x18a114 ldr r1, [pc, #0x12c]
 *   @0x18a118 ldr r3, [r3, #0xc]
 *   @0x18a11c add r1, pc, r1
 *   @0x18a120 strb r2, [r12]
 *   @0x18a124 blx r3
 *   @0x18a128 mov r0, #0
 *   @0x18a12c add sp, sp, #56
 *   @0x18a130 pop {r4, pc}
 *   @0x18a134 mov r2, r0
 *   @0x18a138 add r0, r1, #20
 *   @0x18a13c add r1, r1, #24
 *   @0x18a140 blx 0x2a7e2c <png_destroy_read_struct>
 *   @0x18a144 ldr r3, [pc, #0xf4]
 *   @0x18a148 ldr r12, [sp, #0x1c]
 *   @0x18a14c ldr r3, [r12, r3]
 *   @0x18a150 ldr r0, [r3]
 *   @0x18a154 b 0x18a108 <_Z7ReadPNGP9yyPNGFile+0x288>
 *   @0x18a158 ldr r0, [sp, #0x2c]
 *   @0x18a15c mul r0, r0, r4
 *   @0x18a160 bl 0x27d14c <_Znaj>
 *   @0x18a164 ldr r1, [sp, #0x18]
 *   @0x18a168 cmp r0, #0
 *   @0x18a16c str r0, [r1, #0x20]
 *   @0x18a170 bne 0x18a058 <_Z7ReadPNGP9yyPNGFile+0x1d8>
 *   @0x18a174 ldr r1, [sp, #0x18]
 *   @0x18a178 ldr r3, [sp, #0x18]
 *   @0x18a17c add r0, r1, #20
 *   @0x18a180 add r1, r1, #24
 *   @0x18a184 add r2, r3, #28
 *   @0x18a188 blx 0x2a7e2c <png_destroy_read_struct>
 *   @0x18a18c ldr r3, [pc, #0xac]
 *   @0x18a190 ldr r12, [sp, #0x1c]
 *   @0x18a194 ldr r3, [r12, r3]
 *   @0x18a198 ldr r0, [r3]
 *   @0x18a19c b 0x18a108 <_Z7ReadPNGP9yyPNGFile+0x288>
 *   @0x18a1a0 ldr r1, [sp, #0x18]
 *   @0x18a1a4 mov r2, #1
 *   @0x18a1a8 ldr r0, [r1, #0x14]
 *   @0x18a1ac mov r1, #255
 *   @0x18a1b0 blx 0x2af812 <png_set_add_alpha>
 *   @0x18a1b4 b 0x189fd0 <_Z7ReadPNGP9yyPNGFile+0x150>
 *   @0x18a1b8 mov r1, r0
 *   @0x18a1bc add r0, r3, #20
 *   @0x18a1c0 mov r2, r1
 *   @0x18a1c4 blx 0x2a7e2c <png_destroy_read_struct>
 *   @0x18a1c8 b 0x18a144 <_Z7ReadPNGP9yyPNGFile+0x2c4>
 *   @0x18a1cc ldr r3, [sp, #0x18]
 *   @0x18a1d0 ldr r0, [r3, #0x14]
 *   @0x18a1d4 blx 0x2a880a <png_set_gray_to_rgb>
 *   @0x18a1d8 ldr r3, [sp, #0x28]
 *   @0x18a1dc b 0x189fb0 <_Z7ReadPNGP9yyPNGFile+0x130>
 *   @0x18a1e0 ldr r1, [sp, #0x18]
 *   @0x18a1e4 mov r2, r4
 *   @0x18a1e8 add r3, sp, #44
 *   @0x18a1ec ldr r0, [r1, #0x14]
 *   @0x18a1f0 ldr r1, [r1, #0x18]
 *   @0x18a1f4 str r4, [sp]
 *   @0x18a1f8 blx 0x2a6b56 <png_get_tRNS>
 *   @0x18a1fc cmp r0, #0
 *   @0x18a200 moveq r4, r0
 *   @0x18a204 beq 0x18a214 <_Z7ReadPNGP9yyPNGFile+0x394>
 *   @0x18a208 ldr r4, [sp, #0x2c]
 *   @0x18a20c adds r4, r4, #0
 *   @0x18a210 movne r4, #1
 *   @0x18a214 ldr r3, [sp, #0x28]
 *   @0x18a218 b 0x189fa8 <_Z7ReadPNGP9yyPNGFile+0x128>
 *   @0x18a21c ldr r0, [r12, #0x14]
 *   @0x18a220 blx 0x2a87b0 <png_set_palette_to_rgb>
 *   @0x18a224 b 0x18a024 <_Z7ReadPNGP9yyPNGFile+0x1a4>
 *   @0x18a228 mov r1, r0
 *   @0x18a22c b 0x18a0c4 <_Z7ReadPNGP9yyPNGFile+0x244>
 *   @0x18a230 .word 0x00267db0
 *   @0x18a234 andseq r0, r12, r0, lsl #15
 *   @0x18a238 .word 0xffffe4ac
 *   @0x18a23c .word 0xfffff2c4
 *   @0x18a240 .word 0xffffbac4
 *   @0x18a244 andseq r1, r12, r0, ror #31
 *   @0x18a248 ldrsheq r1, [r12], -r8
 *
 * ══ §13/33 AddCreationCode(Buffer_Standard*)  0x29edf0  size 968  242 条（0x29edf0..0x29f1b8）
 * @func 0x29edf0 0x29f1b8  size 968  242 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x29ee8c→0x544c44, 0x29efa4→0x544c0c, 0x29efcc→0x544c08, 0x29f000→0x544c40, 0x29f010→0x544c40
 * 调用序列: WriteString(Buffer_Standard*, char const*)×2 / Room_Number() / AddCreationCode(Buffer_Standard*)+0x374 / Room_Data(int) / AddCreationCode(Buffer_Standard*)+0x3ac / AddCreationCode(Buffer_Standard*)+0x2e4 / Code_GetEntry(int) / AddCreationCode(Buffer_Standard*)+0x23c
 * 字段偏移 top8: 0x8×14 / 0x38×9 / 0x30×7 / 0x10×7 / 0x4×5 / 0x1c×4 / 0x2c×4 / 0xc×4
 * VFP 指令 20 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29edf0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x29edf4 sub sp, sp, #36
 *   @0x29edf8 mov r4, r0
 *   @0x29edfc bl 0x1b523c <_Z11Room_Numberv>
 *   @0x29ee00 ldr r3, [r4]
 *   @0x29ee04 add r11, r4, #44
 *   @0x29ee08 mov r5, #0
 *   @0x29ee0c mov r1, #5
 *   @0x29ee10 str r5, [r4, #0x38]
 *   @0x29ee14 mov r2, r11
 *   @0x29ee18 ldr r9, [pc, #0x384]
 *   @0x29ee1c add r9, pc, r9
 *   @0x29ee20 str r0, [sp, #0x14]
 *   @0x29ee24 mov r0, r4
 *   @0x29ee28 vldr s15, [sp, #20]
 *   @0x29ee2c vcvt.f64.u32 d7, s15
 *   @0x29ee30 vmov r6, r7, d7
 *   @0x29ee34 vstr s14, [r4, #44]
 *   @0x29ee38 str r7, [r4, #0x30]
 *   @0x29ee3c ldr r3, [r3, #0x8]
 *   @0x29ee40 blx r3
 *   @0x29ee44 ldr r3, [sp, #0x14]
 *   @0x29ee48 cmp r3, r5
 *   @0x29ee4c ble 0x29f164 <_Z15AddCreationCodeP15Buffer_Standard+0x374>
 *   @0x29ee50 mov r8, r5
 *   @0x29ee54 mov r12, r5
 *   @0x29ee58 movw r3, #0xffff
 *   @0x29ee5c movt r12, #0xffe0
 *   @0x29ee60 movt r3, #0x41ef
 *   @0x29ee64 str r5, [sp, #0x4]
 *   @0x29ee68 str r12, [sp, #0x18]
 *   @0x29ee6c str r3, [sp, #0x1c]
 *   @0x29ee70 str r5, [sp, #0x8]
 *   @0x29ee74 ldr r0, [sp, #0x4]
 *   @0x29ee78 bl 0x1b52c4 <_Z9Room_Datai>
 *   @0x29ee7c ldr r6, [r0, #0xac]
 *   @0x29ee80 mov r5, r0
 *   @0x29ee84 ldr r1, [r6]
 *   @0x29ee88 cmp r1, #0
 *   @0x29ee8c ldrne r3, [pc, #0x314]
 *   @0x29ee90 ldrne r3, [r9, r3]
 *   @0x29ee94 ldrne r3, [r3]
 *   @0x29ee98 addne r1, r3, r1
 *   @0x29ee9c mov r0, r4
 *   @0x29eea0 bl 0x29e624 <_Z11WriteStringP15Buffer_StandardPKc>
 *   @0x29eea4 ldr r3, [r5, #0x68]
 *   @0x29eea8 cmp r3, #0
 *   @0x29eeac beq 0x29f16c <_Z15AddCreationCodeP15Buffer_Standard+0x37c>
 *   @0x29eeb0 ldr r3, [r5, #0x6c]
 *   @0x29eeb4 cmp r3, #0
 *   @0x29eeb8 beq 0x29f16c <_Z15AddCreationCodeP15Buffer_Standard+0x37c>
 *   @0x29eebc vldr s14, [r3, #96]
 *   @0x29eec0 vcvt.f64.u32 d7, s14
 *   @0x29eec4 ldr r3, [r3, #0x50]
 *   @0x29eec8 mov r1, #5
 *   @0x29eecc ldr lr, [r4]
 *   @0x29eed0 mov r2, r11
 *   @0x29eed4 mov r0, r4
 *   @0x29eed8 ldr r7, [r3, #0x10]
 *   @0x29eedc str r8, [r4, #0x38]
 *   @0x29eee0 vstr s14, [r4, #44]
 *   @0x29eee4 vstr s15, [r4, #48]
 *   @0x29eee8 ldr r3, [lr, #0x8]
 *   @0x29eeec blx r3
 *   @0x29eef0 ldr r12, [r4]
 *   @0x29eef4 asr r3, r7, #31
 *   @0x29eef8 str r7, [r4, #0x2c]
 *   @0x29eefc mov lr, #10
 *   @0x29ef00 str r3, [r4, #0x30]
 *   @0x29ef04 str lr, [r4, #0x38]
 *   @0x29ef08 mov r0, r4
 *   @0x29ef0c mov r1, #12
 *   @0x29ef10 ldr r3, [r12, #0x8]
 *   @0x29ef14 mov r2, r11
 *   @0x29ef18 blx r3
 *   @0x29ef1c ldr r3, [r4]
 *   @0x29ef20 mov r0, r4
 *   @0x29ef24 ldr r12, [r4, #0x1c]
 *   @0x29ef28 mov r1, #5
 *   @0x29ef2c str r8, [r4, #0x2c]
 *   @0x29ef30 mov r2, r11
 *   @0x29ef34 str r8, [r4, #0x30]
 *   @0x29ef38 str r8, [r4, #0x38]
 *   @0x29ef3c ldr r3, [r3, #0x8]
 *   @0x29ef40 str r12, [sp, #0x10]
 *   @0x29ef44 blx r3
 *   @0x29ef48 ldr r7, [r6, #0x30]
 *   @0x29ef4c cmp r7, #0
 *   @0x29ef50 beq 0x29f0e4 <_Z15AddCreationCodeP15Buffer_Standard+0x2f4>
 *   @0x29ef54 ldr r7, [r5, #0xc8]
 *   @0x29ef58 cmp r7, #0
 *   @0x29ef5c beq 0x29f0e4 <_Z15AddCreationCodeP15Buffer_Standard+0x2f4>
 *   @0x29ef60 ldr r2, [r7]
 *   @0x29ef64 cmp r2, #0
 *   @0x29ef68 ble 0x29f19c <_Z15AddCreationCodeP15Buffer_Standard+0x3ac>
 *   @0x29ef6c mov r5, #1
 *   @0x29ef70 mov r3, #0
 *   @0x29ef74 str r3, [sp, #0xc]
 *   @0x29ef78 ldr r6, [r7, r5, lsl #2]
 *   @0x29ef7c ldr r3, [r6, #0x8]
 *   @0x29ef80 cmp r3, #0
 *   @0x29ef84 blt 0x29f0d4 <_Z15AddCreationCodeP15Buffer_Standard+0x2e4>
 *   @0x29ef88 ldr r0, [r6, #0x10]
 *   @0x29ef8c bl 0xced64 <_Z13Code_GetEntryi>
 *   @0x29ef90 cmp r0, #0
 *   @0x29ef94 beq 0x29f0d0 <_Z15AddCreationCodeP15Buffer_Standard+0x2e0>
 *   @0x29ef98 ldr r2, [r0, #0x60]
 *   @0x29ef9c cmn r2, #1
 *   @0x29efa0 beq 0x29f0d0 <_Z15AddCreationCodeP15Buffer_Standard+0x2e0>
 *   @0x29efa4 ldr r1, [pc, #0x200]
 *   @0x29efa8 ldr r3, [sp, #0xc]
 *   @0x29efac add r3, r3, #1
 *   @0x29efb0 str r3, [sp, #0xc]
 *   @0x29efb4 ldr r1, [r9, r1]
 *   @0x29efb8 ldr r3, [r0, #0x50]
 *   @0x29efbc ldr r10, [r1]
 *   @0x29efc0 ldr r3, [r3, #0x10]
 *   @0x29efc4 cmp r10, #0
 *   @0x29efc8 beq 0x29f02c <_Z15AddCreationCodeP15Buffer_Standard+0x23c>
 *   @0x29efcc ldr r1, [pc, #0x1dc]
 *   @0x29efd0 ldr r12, [sp, #0x8]
 *   @0x29efd4 ldr r1, [r9, r1]
 *   @0x29efd8 ldr r1, [r1]
 *   @0x29efdc cmp r1, r12
 *   @0x29efe0 movle r10, #0
 *   @0x29efe4 ble 0x29f02c <_Z15AddCreationCodeP15Buffer_Standard+0x23c>
 *   @0x29efe8 ldr r1, [r10, r12, lsl #2]
 *   @0x29efec cmp r1, #0
 *   @0x29eff0 bne 0x29f010 <_Z15AddCreationCodeP15Buffer_Standard+0x220>
 *   @0x29eff4 ldr r10, [r1]
 *   @0x29eff8 cmp r10, #0
 *   @0x29effc beq 0x29f02c <_Z15AddCreationCodeP15Buffer_Standard+0x23c>
 *   @0x29f000 ldr r1, [pc, #0x1ac]
 *   @0x29f004 ldr r1, [r9, r1]
 *   @0x29f008 ldr r0, [r1]
 *   @0x29f00c b 0x29f028 <_Z15AddCreationCodeP15Buffer_Standard+0x238>
 *   @0x29f010 ldr r0, [pc, #0x19c]
 *   @0x29f014 ldr r0, [r9, r0]
 *   @0x29f018 ldr r0, [r0]
 *   @0x29f01c ldr r10, [r1, r0]
 *   @0x29f020 cmp r10, #0
 *   @0x29f024 beq 0x29f02c <_Z15AddCreationCodeP15Buffer_Standard+0x23c>
 *   @0x29f028 add r10, r10, r0
 *   @0x29f02c vmov s13, r2
 *   @0x29f030 ldr lr, [r4]
 *   @0x29f034 ldr r12, [sp, #0x8]
 *   @0x29f038 mov r1, #5
 *   @0x29f03c vcvt.f64.u32 d7, s13
 *   @0x29f040 str r8, [r4, #0x38]
 *   @0x29f044 mov r2, r11
 *   @0x29f048 add r12, r12, #1
 *   @0x29f04c mov r0, r4
 *   @0x29f050 str r12, [sp, #0x8]
 *   @0x29f054 vstr s14, [r4, #44]
 *   @0x29f058 vstr s15, [r4, #48]
 *   @0x29f05c ldr r12, [lr, #0x8]
 *   @0x29f060 str r3, [sp]
 *   @0x29f064 blx r12
 *   @0x29f068 ldr r3, [sp]
 *   @0x29f06c ldr r12, [r4]
 *   @0x29f070 mov r2, r11
 *   @0x29f074 mov r0, #10
 *   @0x29f078 mov r1, #12
 *   @0x29f07c str r3, [r4, #0x2c]
 *   @0x29f080 asr r3, r3, #31
 *   @0x29f084 str r0, [r4, #0x38]
 *   @0x29f088 mov r0, r4
 *   @0x29f08c str r3, [r4, #0x30]
 *   @0x29f090 ldr r3, [r12, #0x8]
 *   @0x29f094 blx r3
 *   @0x29f098 mov r0, r4
 *   @0x29f09c mov r1, r10
 *   @0x29f0a0 bl 0x29e624 <_Z11WriteStringP15Buffer_StandardPKc>
 *   @0x29f0a4 vldr s14, [r6, #8]
 *   @0x29f0a8 vcvt.f64.u32 d7, s14
 *   @0x29f0ac ldr r3, [r4]
 *   @0x29f0b0 mov r0, r4
 *   @0x29f0b4 str r8, [r4, #0x38]
 *   @0x29f0b8 mov r1, #5
 *   @0x29f0bc mov r2, r11
 *   @0x29f0c0 vstr s14, [r4, #44]
 *   @0x29f0c4 vstr s15, [r4, #48]
 *   @0x29f0c8 ldr r3, [r3, #0x8]
 *   @0x29f0cc blx r3
 *   @0x29f0d0 ldr r2, [r7]
 *   @0x29f0d4 cmp r2, r5
 *   @0x29f0d8 add r5, r5, #1
 *   @0x29f0dc bgt 0x29ef78 <_Z15AddCreationCodeP15Buffer_Standard+0x188>
 *   @0x29f0e0 ldr r7, [sp, #0xc]
 *   @0x29f0e4 ldr r3, [r4]
 *   @0x29f0e8 mov r1, #0
 *   @0x29f0ec ldr r12, [sp, #0x4]
 *   @0x29f0f0 mov r0, r4
 *   @0x29f0f4 ldr r2, [sp, #0x10]
 *   @0x29f0f8 add r12, r12, #1
 *   @0x29f0fc ldr r3, [r3, #0x10]
 *   @0x29f100 str r12, [sp, #0x4]
 *   @0x29f104 ldr r5, [r4, #0x1c]
 *   @0x29f108 blx r3
 *   @0x29f10c vmov s15, r7
 *   @0x29f110 ldr lr, [r4]
 *   @0x29f114 mov r1, #5
 *   @0x29f118 mov r2, r11
 *   @0x29f11c vcvt.f64.u32 d7, s15
 *   @0x29f120 mov r0, r4
 *   @0x29f124 str r8, [r4, #0x38]
 *   @0x29f128 vmov r6, r7, d7
 *   @0x29f12c vstr s14, [r4, #44]
 *   @0x29f130 str r7, [r4, #0x30]
 *   @0x29f134 ldr r3, [lr, #0x8]
 *   @0x29f138 blx r3
 *   @0x29f13c ldr r3, [r4]
 *   @0x29f140 mov r2, r5
 *   @0x29f144 mov r0, r4
 *   @0x29f148 mov r1, #0
 *   @0x29f14c ldr r3, [r3, #0x10]
 *   @0x29f150 blx r3
 *   @0x29f154 ldr r3, [sp, #0x4]
 *   @0x29f158 ldr r12, [sp, #0x14]
 *   @0x29f15c cmp r3, r12
 *   @0x29f160 bne 0x29ee74 <_Z15AddCreationCodeP15Buffer_Standard+0x84>
 *   @0x29f164 add sp, sp, #36
 *   @0x29f168 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x29f16c ldr r12, [sp, #0x18]
 *   @0x29f170 mov r0, r4
 *   @0x29f174 ldr r3, [r4]
 *   @0x29f178 mov r1, #5
 *   @0x29f17c mov r2, r11
 *   @0x29f180 str r8, [r4, #0x38]
 *   @0x29f184 str r12, [r4, #0x2c]
 *   @0x29f188 ldr r12, [sp, #0x1c]
 *   @0x29f18c str r12, [r4, #0x30]
 *   @0x29f190 ldr r3, [r3, #0x8]
 *   @0x29f194 blx r3
 *   @0x29f198 b 0x29ef1c <_Z15AddCreationCodeP15Buffer_Standard+0x12c>
 *   @0x29f19c mov r7, #0
 *   @0x29f1a0 b 0x29f0e4 <_Z15AddCreationCodeP15Buffer_Standard+0x2f4>
 *   @0x29f1a4 andseq r2, r5, r4, lsr lr
 *   @0x29f1a8 .word 0xffffbcf4
 *   @0x29f1ac .word 0xfffff098
 *   @0x29f1b0 .word 0xfffff09c
 *   @0x29f1b4 .word 0xffffbf00
 *
 * ══ §14/33 jinit_1pass_quantizer  0x2bad30  size 968  242 条（0x2bad30..0x2bb0f8）
 * @func 0x2bad30 0x2bb0f8  size 968  242 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __divsi3×3 / jinit_1pass_quantizer+0x84 / jinit_1pass_quantizer+0xb8 / jinit_1pass_quantizer+0xf4 / jinit_1pass_quantizer+0xd0 / jinit_1pass_quantizer+0x3a0 / jinit_1pass_quantizer+0x1ac / jinit_1pass_quantizer+0x30c
 * 字段偏移 top8: 0x14×10 / 0x18×9 / 0x4×7 / 0x64×6 / 0x8×6 / 0x10×6 / 0x1c×4 / 0xc×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2bad30 ldr r3, [r0, #0x4]
 *   @0x2bad34 mov r1, #1
 *   @0x2bad38 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2bad3c mov r2, #88
 *   @0x2bad40 ldr r3, [r3]
 *   @0x2bad44 sub sp, sp, #36
 *   @0x2bad48 mov r8, r0
 *   @0x2bad4c blx r3
 *   @0x2bad50 ldr r2, [r8, #0x64]
 *   @0x2bad54 mov r3, #0
 *   @0x2bad58 ldr r12, [pc, #0x388]
 *   @0x2bad5c ldr r1, [pc, #0x388]
 *   @0x2bad60 cmp r2, #4
 *   @0x2bad64 ldr r2, [pc, #0x384]
 *   @0x2bad68 add r12, pc, r12
 *   @0x2bad6c add r1, pc, r1
 *   @0x2bad70 add r2, pc, r2
 *   @0x2bad74 str r0, [r8, #0x1a8]
 *   @0x2bad78 str r12, [r0]
 *   @0x2bad7c str r1, [r0, #0x8]
 *   @0x2bad80 str r2, [r0, #0xc]
 *   @0x2bad84 str r3, [r0, #0x44]
 *   @0x2bad88 str r3, [r0, #0x34]
 *   @0x2bad8c ble 0x2badb4 <jinit_1pass_quantizer+0x84>
 *   @0x2bad90 ldr r3, [r8]
 *   @0x2bad94 mov r2, #4
 *   @0x2bad98 mov r1, #55
 *   @0x2bad9c mov r0, r8
 *   @0x2bada0 str r2, [r3, #0x18]
 *   @0x2bada4 ldr r2, [r8]
 *   @0x2bada8 str r1, [r3, #0x14]
 *   @0x2badac ldr r3, [r2]
 *   @0x2badb0 blx r3
 *   @0x2badb4 ldr r6, [r8, #0x54]
 *   @0x2badb8 cmp r6, #256
 *   @0x2badbc ble 0x2bade8 <jinit_1pass_quantizer+0xb8>
 *   @0x2badc0 ldr r3, [r8]
 *   @0x2badc4 mov r2, #256
 *   @0x2badc8 mov r1, #57
 *   @0x2badcc mov r0, r8
 *   @0x2badd0 str r2, [r3, #0x18]
 *   @0x2badd4 ldr r2, [r8]
 *   @0x2badd8 str r1, [r3, #0x14]
 *   @0x2baddc ldr r3, [r2]
 *   @0x2bade0 blx r3
 *   @0x2bade4 ldr r6, [r8, #0x54]
 *   @0x2bade8 ldr r4, [r8, #0x1a8]
 *   @0x2badec mov r5, #1
 *   @0x2badf0 str r4, [sp, #0x10]
 *   @0x2badf4 ldr r2, [sp, #0x10]
 *   @0x2badf8 ldr r4, [r8, #0x64]
 *   @0x2badfc add r12, r2, #32
 *   @0x2bae00 add r1, r5, #1
 *   @0x2bae04 cmp r4, #1
 *   @0x2bae08 mov r2, r1
 *   @0x2bae0c ble 0x2bae24 <jinit_1pass_quantizer+0xf4>
 *   @0x2bae10 mov r3, #1
 *   @0x2bae14 add r3, r3, #1
 *   @0x2bae18 cmp r3, r4
 *   @0x2bae1c mul r2, r1, r2
 *   @0x2bae20 bne 0x2bae14 <jinit_1pass_quantizer+0xe4>
 *   @0x2bae24 cmp r2, r6
 *   @0x2bae28 movle r5, r1
 *   @0x2bae2c ble 0x2bae00 <jinit_1pass_quantizer+0xd0>
 *   @0x2bae30 cmp r5, #1
 *   @0x2bae34 beq 0x2bb0a0 <jinit_1pass_quantizer+0x370>
 *   @0x2bae38 cmp r4, #0
 *   @0x2bae3c ble 0x2bb0d0 <jinit_1pass_quantizer+0x3a0>
 *   @0x2bae40 add r2, r12, r4, lsl #2
 *   @0x2bae44 mov r3, r12
 *   @0x2bae48 mov r7, #1
 *   @0x2bae4c str r5, [r3], #4
 *   @0x2bae50 cmp r3, r2
 *   @0x2bae54 mul r7, r5, r7
 *   @0x2bae58 bne 0x2bae4c <jinit_1pass_quantizer+0x11c>
 *   @0x2bae5c ldr r3, [pc, #0x290]
 *   @0x2bae60 mov r9, #0
 *   @0x2bae64 mov r2, r8
 *   @0x2bae68 mov r5, r9
 *   @0x2bae6c add r3, pc, r3
 *   @0x2bae70 mov r8, r6
 *   @0x2bae74 mov r6, r12
 *   @0x2bae78 cmp r4, r5
 *   @0x2bae7c ble 0x2baedc <jinit_1pass_quantizer+0x1ac>
 *   @0x2bae80 ldr r1, [r2, #0x2c]
 *   @0x2bae84 mov r10, r5
 *   @0x2bae88 mov r0, r7
 *   @0x2bae8c cmp r1, #2
 *   @0x2bae90 addeq r1, r3, r5, lsl #2
 *   @0x2bae94 add r5, r5, #1
 *   @0x2bae98 ldreq r10, [r1, #0x100]
 *   @0x2bae9c ldr r11, [r6, r10, lsl #2]
 *   @0x2baea0 str r2, [sp, #0x8]
 *   @0x2baea4 str r3, [sp, #0x4]
 *   @0x2baea8 mov r1, r11
 *   @0x2baeac add r11, r11, #1
 *   @0x2baeb0 bl 0x318d10 <__divsi3>
 *   @0x2baeb4 ldr r2, [sp, #0x8]
 *   @0x2baeb8 ldr r3, [sp, #0x4]
 *   @0x2baebc mul r0, r11, r0
 *   @0x2baec0 cmp r0, r8
 *   @0x2baec4 bgt 0x2baedc <jinit_1pass_quantizer+0x1ac>
 *   @0x2baec8 cmp r4, r5
 *   @0x2baecc str r11, [r6, r10, lsl #2]
 *   @0x2baed0 mov r7, r0
 *   @0x2baed4 mov r9, #1
 *   @0x2baed8 bgt 0x2bae80 <jinit_1pass_quantizer+0x150>
 *   @0x2baedc cmp r9, #0
 *   @0x2baee0 mov r9, #0
 *   @0x2baee4 mov r5, r9
 *   @0x2baee8 bne 0x2bae78 <jinit_1pass_quantizer+0x148>
 *   @0x2baeec ldr r3, [r2, #0x64]
 *   @0x2baef0 mov r8, r2
 *   @0x2baef4 mov r10, r7
 *   @0x2baef8 cmp r3, #3
 *   @0x2baefc ldr r3, [r2]
 *   @0x2baf00 beq 0x2bb064 <jinit_1pass_quantizer+0x334>
 *   @0x2baf04 str r7, [r3, #0x18]
 *   @0x2baf08 mov r0, r2
 *   @0x2baf0c ldr r2, [r2]
 *   @0x2baf10 mov r12, #95
 *   @0x2baf14 mov r1, #1
 *   @0x2baf18 str r12, [r3, #0x14]
 *   @0x2baf1c ldr r3, [r2, #0x4]
 *   @0x2baf20 blx r3
 *   @0x2baf24 ldr r12, [r8, #0x4]
 *   @0x2baf28 mov r0, r8
 *   @0x2baf2c mov r1, #1
 *   @0x2baf30 mov r2, r7
 *   @0x2baf34 ldr r3, [r8, #0x64]
 *   @0x2baf38 ldr r12, [r12, #0x8]
 *   @0x2baf3c blx r12
 *   @0x2baf40 ldr r5, [r8, #0x64]
 *   @0x2baf44 cmp r5, #0
 *   @0x2baf48 mov r4, r0
 *   @0x2baf4c ble 0x2bb03c <jinit_1pass_quantizer+0x30c>
 *   @0x2baf50 ldr r3, [sp, #0x10]
 *   @0x2baf54 mov r2, #0
 *   @0x2baf58 str r8, [sp, #0x1c]
 *   @0x2baf5c str r2, [sp, #0x14]
 *   @0x2baf60 str r3, [sp, #0x18]
 *   @0x2baf64 ldr r3, [sp, #0x18]
 *   @0x2baf68 mov r0, r7
 *   @0x2baf6c ldr r9, [r3, #0x20]
 *   @0x2baf70 mov r1, r9
 *   @0x2baf74 bl 0x318d10 <__divsi3>
 *   @0x2baf78 cmp r9, #0
 *   @0x2baf7c mov r6, r0
 *   @0x2baf80 ble 0x2bb014 <jinit_1pass_quantizer+0x2e4>
 *   @0x2baf84 sub r2, r9, #1
 *   @0x2baf88 ldr r3, [sp, #0x14]
 *   @0x2baf8c mov r8, #0
 *   @0x2baf90 rsb r9, r9, r9, lsl #8
 *   @0x2baf94 asr r11, r2, #1
 *   @0x2baf98 str r2, [sp, #0xc]
 *   @0x2baf9c lsl r5, r3, #2
 *   @0x2bafa0 add r9, r9, r11
 *   @0x2bafa4 mov r3, r8
 *   @0x2bafa8 mov r8, r7
 *   @0x2bafac mov r7, r3
 *   @0x2bafb0 mov r0, r11
 *   @0x2bafb4 ldr r1, [sp, #0xc]
 *   @0x2bafb8 bl 0x318d10 <__divsi3>
 *   @0x2bafbc cmp r7, r10
 *   @0x2bafc0 mov lr, r7
 *   @0x2bafc4 bge 0x2baffc <jinit_1pass_quantizer+0x2cc>
 *   @0x2bafc8 uxtb r0, r0
 *   @0x2bafcc cmp r6, #0
 *   @0x2bafd0 ble 0x2baff0 <jinit_1pass_quantizer+0x2c0>
 *   @0x2bafd4 add r1, lr, r6
 *   @0x2bafd8 mov r3, lr
 *   @0x2bafdc ldr r2, [r4, r5]
 *   @0x2bafe0 strb r0, [r2, r3]
 *   @0x2bafe4 add r3, r3, #1
 *   @0x2bafe8 cmp r3, r1
 *   @0x2bafec bne 0x2bafdc <jinit_1pass_quantizer+0x2ac>
 *   @0x2baff0 add lr, lr, r8
 *   @0x2baff4 cmp lr, r10
 *   @0x2baff8 blt 0x2bafcc <jinit_1pass_quantizer+0x29c>
 *   @0x2baffc add r11, r11, #255
 *   @0x2bb000 add r7, r7, r6
 *   @0x2bb004 cmp r11, r9
 *   @0x2bb008 bne 0x2bafb0 <jinit_1pass_quantizer+0x280>
 *   @0x2bb00c ldr r2, [sp, #0x1c]
 *   @0x2bb010 ldr r5, [r2, #0x64]
 *   @0x2bb014 ldr r2, [sp, #0x14]
 *   @0x2bb018 ldr r3, [sp, #0x18]
 *   @0x2bb01c add r2, r2, #1
 *   @0x2bb020 str r2, [sp, #0x14]
 *   @0x2bb024 cmp r2, r5
 *   @0x2bb028 add r3, r3, #4
 *   @0x2bb02c str r3, [sp, #0x18]
 *   @0x2bb030 movlt r7, r6
 *   @0x2bb034 blt 0x2baf64 <jinit_1pass_quantizer+0x234>
 *   @0x2bb038 ldr r8, [sp, #0x1c]
 *   @0x2bb03c ldr r2, [sp, #0x10]
 *   @0x2bb040 mov r0, r8
 *   @0x2bb044 str r4, [r2, #0x10]
 *   @0x2bb048 str r10, [r2, #0x14]
 *   @0x2bb04c bl 0x2ba268 <jinit_memory_mgr+0x1b4>
 *   @0x2bb050 ldr r3, [r8, #0x4c]
 *   @0x2bb054 cmp r3, #2
 *   @0x2bb058 beq 0x2bb0d8 <jinit_1pass_quantizer+0x3a8>
 *   @0x2bb05c add sp, sp, #36
 *   @0x2bb060 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2bb064 ldr r4, [sp, #0x10]
 *   @0x2bb068 mov lr, #94
 *   @0x2bb06c str r7, [r3, #0x18]
 *   @0x2bb070 mov r0, r2
 *   @0x2bb074 mov r1, #1
 *   @0x2bb078 ldr r2, [r3, #0x4]
 *   @0x2bb07c ldr r12, [r4, #0x20]
 *   @0x2bb080 str r12, [r3, #0x1c]
 *   @0x2bb084 ldr r12, [r4, #0x24]
 *   @0x2bb088 str r12, [r3, #0x20]
 *   @0x2bb08c ldr r12, [r4, #0x28]
 *   @0x2bb090 str lr, [r3, #0x14]
 *   @0x2bb094 str r12, [r3, #0x24]
 *   @0x2bb098 blx r2
 *   @0x2bb09c b 0x2baf24 <jinit_1pass_quantizer+0x1f4>
 *   @0x2bb0a0 ldr r3, [r8]
 *   @0x2bb0a4 mov r1, #56
 *   @0x2bb0a8 mov r0, r8
 *   @0x2bb0ac str r2, [r3, #0x18]
 *   @0x2bb0b0 ldr r2, [r8]
 *   @0x2bb0b4 str r1, [r3, #0x14]
 *   @0x2bb0b8 ldr r3, [r2]
 *   @0x2bb0bc str r12, [sp, #0x8]
 *   @0x2bb0c0 blx r3
 *   @0x2bb0c4 cmp r4, #0
 *   @0x2bb0c8 ldr r12, [sp, #0x8]
 *   @0x2bb0cc bgt 0x2bae40 <jinit_1pass_quantizer+0x110>
 *   @0x2bb0d0 mov r7, #1
 *   @0x2bb0d4 b 0x2bae5c <jinit_1pass_quantizer+0x12c>
 *   @0x2bb0d8 mov r0, r8
 *   @0x2bb0dc add sp, sp, #36
 *   @0x2bb0e0 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2bb0e4 b 0x2ba69c <jinit_memory_mgr+0x5e8>
 *   @0x2bb0e8 .word 0xfffffd38
 *   @0x2bb0ec .word 0xfffff984
 *   @0x2bb0f0 .word 0xfffff984
 *   @0x2bb0f4 andeq r5, sp, r4, rrx
 *
 * ══ §15/33 DGifGetImageDesc(GifFileType*)  0x2c1ea8  size 968  242 条（0x2c1ea8..0x2c2270）
 * @func 0x2c1ea8 0x2c2270  size 968  242 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2c143c×4 / GifFreeMapObject(ColorMapObject*)×3 / 0xb68c8×3 / GifMakeMapObject(int, GifColorType const*)×2 / 0xb6c28 / 0xb6544 / DGifGetImageDesc(GifFileType*)+0xf4
 * 字段偏移 top8: 0x30×13 / 0xc×7 / 0x18×6 / 0x4×5 / 0x48×4 / 0x34×4 / 0x14×4 / 0x3c×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c1ea8 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x2c1eac mov r4, r0
 *   @0x2c1eb0 ldr r5, [r0, #0x48]
 *   @0x2c1eb4 sub sp, sp, #12
 *   @0x2c1eb8 ldr r3, [r5]
 *   @0x2c1ebc ands r3, r3, #8
 *   @0x2c1ec0 moveq r2, #111
 *   @0x2c1ec4 streq r2, [r0, #0x40]
 *   @0x2c1ec8 bne 0x2c1ed8 <_Z16DGifGetImageDescP11GifFileType+0x30>
 *   @0x2c1ecc mov r0, r3
 *   @0x2c1ed0 add sp, sp, #12
 *   @0x2c1ed4 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x2c1ed8 add r6, r0, #28
 *   @0x2c1edc mov r1, r6
 *   @0x2c1ee0 bl 0x2c143c <jpeg_mem_term+0x4>
 *   @0x2c1ee4 cmp r0, #0
 *   @0x2c1ee8 bne 0x2c1efc <_Z16DGifGetImageDescP11GifFileType+0x54>
 *   @0x2c1eec mov r3, #0
 *   @0x2c1ef0 mov r0, r3
 *   @0x2c1ef4 add sp, sp, #12
 *   @0x2c1ef8 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x2c1efc mov r0, r4
 *   @0x2c1f00 add r1, r4, #32
 *   @0x2c1f04 bl 0x2c143c <jpeg_mem_term+0x4>
 *   @0x2c1f08 cmp r0, #0
 *   @0x2c1f0c beq 0x2c1eec <_Z16DGifGetImageDescP11GifFileType+0x44>
 *   @0x2c1f10 mov r0, r4
 *   @0x2c1f14 add r1, r4, #36
 *   @0x2c1f18 bl 0x2c143c <jpeg_mem_term+0x4>
 *   @0x2c1f1c cmp r0, #0
 *   @0x2c1f20 beq 0x2c1eec <_Z16DGifGetImageDescP11GifFileType+0x44>
 *   @0x2c1f24 mov r0, r4
 *   @0x2c1f28 add r1, r4, #40
 *   @0x2c1f2c bl 0x2c143c <jpeg_mem_term+0x4>
 *   @0x2c1f30 cmp r0, #0
 *   @0x2c1f34 beq 0x2c1eec <_Z16DGifGetImageDescP11GifFileType+0x44>
 *   @0x2c1f38 ldr r2, [r4, #0x48]
 *   @0x2c1f3c ldr r3, [r2, #0x3c]
 *   @0x2c1f40 cmp r3, #0
 *   @0x2c1f44 beq 0x2c2118 <_Z16DGifGetImageDescP11GifFileType+0x270>
 *   @0x2c1f48 add r8, sp, #4
 *   @0x2c1f4c mov r0, r4
 *   @0x2c1f50 mov r2, #1
 *   @0x2c1f54 mov r1, r8
 *   @0x2c1f58 blx r3
 *   @0x2c1f5c subs r7, r0, #1
 *   @0x2c1f60 movne r7, #1
 *   @0x2c1f64 cmp r7, #0
 *   @0x2c1f68 bne 0x2c20f8 <_Z16DGifGetImageDescP11GifFileType+0x250>
 *   @0x2c1f6c ldr r0, [r4, #0x30]
 *   @0x2c1f70 ldrb r9, [sp, #0x4]
 *   @0x2c1f74 cmp r0, #0
 *   @0x2c1f78 ubfx r3, r9, #0x6, #0x1
 *   @0x2c1f7c strb r3, [r4, #0x2c]
 *   @0x2c1f80 moveq r3, r9
 *   @0x2c1f84 beq 0x2c1f94 <_Z16DGifGetImageDescP11GifFileType+0xec>
 *   @0x2c1f88 bl 0x2c2c48 <_Z16GifFreeMapObjectP14ColorMapObject>
 *   @0x2c1f8c ldrb r3, [sp, #0x4]
 *   @0x2c1f90 str r7, [r4, #0x30]
 *   @0x2c1f94 tst r3, #128
 *   @0x2c1f98 bne 0x2c2160 <_Z16DGifGetImageDescP11GifFileType+0x2b8>
 *   @0x2c1f9c ldr r0, [r4, #0x34]
 *   @0x2c1fa0 cmp r0, #0
 *   @0x2c1fa4 beq 0x2c213c <_Z16DGifGetImageDescP11GifFileType+0x294>
 *   @0x2c1fa8 ldr r3, [r4, #0x18]
 *   @0x2c1fac add r3, r3, #1
 *   @0x2c1fb0 add r1, r3, r3, lsl #3
 *   @0x2c1fb4 lsl r1, r1, #2
 *   @0x2c1fb8 bl 0xb6c28 <realloc@plt>
 *   @0x2c1fbc cmp r0, #0
 *   @0x2c1fc0 str r0, [r4, #0x34]
 *   @0x2c1fc4 beq 0x2c2150 <_Z16DGifGetImageDescP11GifFileType+0x2a8>
 *   @0x2c1fc8 ldr r12, [r4, #0x18]
 *   @0x2c1fcc ldr r1, [r6]
 *   @0x2c1fd0 ldr r2, [r6, #0x4]
 *   @0x2c1fd4 add r12, r12, r12, lsl #3
 *   @0x2c1fd8 ldr r3, [r6, #0xc]
 *   @0x2c1fdc ldr lr, [r6, #0x8]
 *   @0x2c1fe0 lsl r12, r12, #2
 *   @0x2c1fe4 add r7, r0, r12
 *   @0x2c1fe8 str r1, [r0, r12]
 *   @0x2c1fec str r2, [r7, #0x4]
 *   @0x2c1ff0 str lr, [r7, #0x8]
 *   @0x2c1ff4 str r3, [r7, #0xc]
 *   @0x2c1ff8 ldr r1, [r6, #0x10]
 *   @0x2c1ffc ldr r2, [r6, #0x14]
 *   @0x2c2000 str r1, [r7, #0x10]
 *   @0x2c2004 str r2, [r7, #0x14]
 *   @0x2c2008 ldr r3, [r4, #0x30]
 *   @0x2c200c cmp r3, #0
 *   @0x2c2010 beq 0x2c202c <_Z16DGifGetImageDescP11GifFileType+0x184>
 *   @0x2c2014 ldr r0, [r3]
 *   @0x2c2018 ldr r1, [r3, #0xc]
 *   @0x2c201c bl 0x2c2bb0 <_Z16GifMakeMapObjectiPK12GifColorType>
 *   @0x2c2020 cmp r0, #0
 *   @0x2c2024 str r0, [r7, #0x14]
 *   @0x2c2028 beq 0x2c2150 <_Z16DGifGetImageDescP11GifFileType+0x2a8>
 *   @0x2c202c ldr r2, [r4, #0x24]
 *   @0x2c2030 mov r3, #0
 *   @0x2c2034 ldr r0, [r4, #0x28]
 *   @0x2c2038 ldr r6, [r4, #0x48]
 *   @0x2c203c ldr r1, [r4, #0x18]
 *   @0x2c2040 mul r2, r0, r2
 *   @0x2c2044 ldr r12, [r6, #0x3c]
 *   @0x2c2048 add r1, r1, #1
 *   @0x2c204c str r3, [r7, #0x18]
 *   @0x2c2050 cmp r12, r3
 *   @0x2c2054 str r3, [r7, #0x1c]
 *   @0x2c2058 str r3, [r7, #0x20]
 *   @0x2c205c str r1, [r4, #0x18]
 *   @0x2c2060 str r2, [r5, #0x34]
 *   @0x2c2064 beq 0x2c2238 <_Z16DGifGetImageDescP11GifFileType+0x390>
 *   @0x2c2068 mov r0, r4
 *   @0x2c206c add r1, sp, #3
 *   @0x2c2070 mov r2, #1
 *   @0x2c2074 blx r12
 *   @0x2c2078 ldrb r4, [sp, #0x3]
 *   @0x2c207c add r2, r6, #8512
 *   @0x2c2080 mov r0, #0
 *   @0x2c2084 mov r8, #1
 *   @0x2c2088 movw r5, #0x1002
 *   @0x2c208c add r2, r2, #4
 *   @0x2c2090 lsl r12, r8, r4
 *   @0x2c2094 add r7, r4, r8
 *   @0x2c2098 mov r3, r0
 *   @0x2c209c mov r1, r5
 *   @0x2c20a0 str r4, [r6, #0x8]
 *   @0x2c20a4 lsl r8, r8, r7
 *   @0x2c20a8 add r4, r12, #1
 *   @0x2c20ac str r12, [r6, #0xc]
 *   @0x2c20b0 str r8, [r6, #0x1c]
 *   @0x2c20b4 add r12, r12, #2
 *   @0x2c20b8 str r7, [r6, #0x18]
 *   @0x2c20bc str r4, [r6, #0x10]
 *   @0x2c20c0 str r12, [r6, #0x14]
 *   @0x2c20c4 strb r0, [r6, #0x44]
 *   @0x2c20c8 str r0, [r6, #0x28]
 *   @0x2c20cc str r0, [r6, #0x2c]
 *   @0x2c20d0 str r0, [r6, #0x30]
 *   @0x2c20d4 str r5, [r6, #0x20]
 *   @0x2c20d8 str r1, [r2, r3]
 *   @0x2c20dc add r3, r3, #4
 *   @0x2c20e0 cmp r3, #16384
 *   @0x2c20e4 bne 0x2c20d8 <_Z16DGifGetImageDescP11GifFileType+0x230>
 *   @0x2c20e8 mov r3, #1
 *   @0x2c20ec mov r0, r3
 *   @0x2c20f0 add sp, sp, #12
 *   @0x2c20f4 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x2c20f8 mov r3, #102
 *   @0x2c20fc ldr r0, [r4, #0x30]
 *   @0x2c2100 str r3, [r4, #0x40]
 *   @0x2c2104 bl 0x2c2c48 <_Z16GifFreeMapObjectP14ColorMapObject>
 *   @0x2c2108 mov r2, #0
 *   @0x2c210c mov r3, r2
 *   @0x2c2110 str r2, [r4, #0x30]
 *   @0x2c2114 b 0x2c1ecc <_Z16DGifGetImageDescP11GifFileType+0x24>
 *   @0x2c2118 add r8, sp, #4
 *   @0x2c211c mov r1, #1
 *   @0x2c2120 ldr r3, [r2, #0x38]
 *   @0x2c2124 mov r2, r1
 *   @0x2c2128 mov r0, r8
 *   @0x2c212c bl 0xb68c8 <fread@plt>
 *   @0x2c2130 subs r7, r0, #1
 *   @0x2c2134 movne r7, #1
 *   @0x2c2138 b 0x2c1f64 <_Z16DGifGetImageDescP11GifFileType+0xbc>
 *   @0x2c213c mov r0, #36
 *   @0x2c2140 bl 0xb6544 <malloc@plt>
 *   @0x2c2144 cmp r0, #0
 *   @0x2c2148 str r0, [r4, #0x34]
 *   @0x2c214c bne 0x2c1fc8 <_Z16DGifGetImageDescP11GifFileType+0x120>
 *   @0x2c2150 mov r2, #109
 *   @0x2c2154 mov r3, r0
 *   @0x2c2158 str r2, [r4, #0x40]
 *   @0x2c215c b 0x2c1ecc <_Z16DGifGetImageDescP11GifFileType+0x24>
 *   @0x2c2160 and r3, r9, #7
 *   @0x2c2164 mov r0, #1
 *   @0x2c2168 add r3, r3, r0
 *   @0x2c216c mov r1, #0
 *   @0x2c2170 lsl r0, r0, r3
 *   @0x2c2174 bl 0x2c2bb0 <_Z16GifMakeMapObjectiPK12GifColorType>
 *   @0x2c2178 cmp r0, #0
 *   @0x2c217c str r0, [r4, #0x30]
 *   @0x2c2180 beq 0x2c2150 <_Z16DGifGetImageDescP11GifFileType+0x2a8>
 *   @0x2c2184 ldr r3, [r0]
 *   @0x2c2188 cmp r3, #0
 *   @0x2c218c movgt r7, #0
 *   @0x2c2190 bgt 0x2c21fc <_Z16DGifGetImageDescP11GifFileType+0x354>
 *   @0x2c2194 b 0x2c1f9c <_Z16DGifGetImageDescP11GifFileType+0xf4>
 *   @0x2c2198 blx r3
 *   @0x2c219c subs r0, r0, #3
 *   @0x2c21a0 movne r0, #1
 *   @0x2c21a4 cmp r0, #0
 *   @0x2c21a8 add r3, r7, r7, lsl #1
 *   @0x2c21ac add r7, r7, #1
 *   @0x2c21b0 bne 0x2c2250 <_Z16DGifGetImageDescP11GifFileType+0x3a8>
 *   @0x2c21b4 ldr r2, [r4, #0x30]
 *   @0x2c21b8 ldrb r1, [sp, #0x4]
 *   @0x2c21bc ldr r2, [r2, #0xc]
 *   @0x2c21c0 strb r1, [r2, r3]
 *   @0x2c21c4 ldr r2, [r4, #0x30]
 *   @0x2c21c8 ldrb r1, [sp, #0x5]
 *   @0x2c21cc ldr r2, [r2, #0xc]
 *   @0x2c21d0 add r2, r2, r3
 *   @0x2c21d4 strb r1, [r2, #0x1]
 *   @0x2c21d8 ldr r1, [r4, #0x30]
 *   @0x2c21dc ldrb r2, [sp, #0x6]
 *   @0x2c21e0 ldr r1, [r1, #0xc]
 *   @0x2c21e4 add r3, r1, r3
 *   @0x2c21e8 strb r2, [r3, #0x2]
 *   @0x2c21ec ldr r3, [r4, #0x30]
 *   @0x2c21f0 ldr r3, [r3]
 *   @0x2c21f4 cmp r3, r7
 *   @0x2c21f8 ble 0x2c1f9c <_Z16DGifGetImageDescP11GifFileType+0xf4>
 *   @0x2c21fc ldr r12, [r4, #0x48]
 *   @0x2c2200 mov r0, r4
 *   @0x2c2204 mov r1, r8
 *   @0x2c2208 mov r2, #3
 *   @0x2c220c ldr r3, [r12, #0x3c]
 *   @0x2c2210 cmp r3, #0
 *   @0x2c2214 bne 0x2c2198 <_Z16DGifGetImageDescP11GifFileType+0x2f0>
 *   @0x2c2218 ldr r3, [r12, #0x38]
 *   @0x2c221c mov r0, r8
 *   @0x2c2220 mov r1, #1
 *   @0x2c2224 mov r2, #3
 *   @0x2c2228 bl 0xb68c8 <fread@plt>
 *   @0x2c222c subs r0, r0, #3
 *   @0x2c2230 movne r0, #1
 *   @0x2c2234 b 0x2c21a4 <_Z16DGifGetImageDescP11GifFileType+0x2fc>
 *   @0x2c2238 mov r1, #1
 *   @0x2c223c add r0, sp, #3
 *   @0x2c2240 mov r2, r1
 *   @0x2c2244 ldr r3, [r6, #0x38]
 *   @0x2c2248 bl 0xb68c8 <fread@plt>
 *   @0x2c224c b 0x2c2078 <_Z16DGifGetImageDescP11GifFileType+0x1d0>
 *   @0x2c2250 ldr r0, [r4, #0x30]
 *   @0x2c2254 bl 0x2c2c48 <_Z16GifFreeMapObjectP14ColorMapObject>
 *   @0x2c2258 mov r2, #0
 *   @0x2c225c mov r3, r2
 *   @0x2c2260 str r2, [r4, #0x30]
 *   @0x2c2264 mov r2, #102
 *   @0x2c2268 str r2, [r4, #0x40]
 *   @0x2c226c b 0x2c1ecc <_Z16DGifGetImageDescP11GifFileType+0x24>
 *
 * ══ §16/33 OutputValue(tagIConsole*, RValue*)  0x1f563c  size 964  241 条（0x1f563c..0x1f5a00）
 * @func 0x1f563c 0x1f5a00  size 964  241 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: OutputValue(tagIConsole*, RValue*)+0x250×2 / OutputValue(tagIConsole*, RValue*)+0xc0 / OutputValue(tagIConsole*, RValue*)+0x288 / OutputValue(tagIConsole*, RValue*) / OutputValue(tagIConsole*, RValue*)+0x1c8 / 0xb66e8
 * 字段偏移 top8: 0xc×21 / 0x4×7 / 0x10×2 / 0x1e8×2 / 0x330×1 / 0x300×1 / 0x2cc×1 / 0x2a0×1
 * VFP 指令 11 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f563c ldr r3, [r1, #0xc]
 *   @0x1f5640 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1f5644 cmp r3, #6
 *   @0x1f5648 sub sp, sp, #12
 *   @0x1f564c mov r7, r1
 *   @0x1f5650 mov r6, r0
 *   @0x1f5654 beq 0x1f58e0 <_Z11OutputValueP11tagIConsoleP6RValue+0x2a4>
 *   @0x1f5658 bgt 0x1f5690 <_Z11OutputValueP11tagIConsoleP6RValue+0x54>
 *   @0x1f565c cmp r3, #2
 *   @0x1f5660 beq 0x1f57b4 <_Z11OutputValueP11tagIConsoleP6RValue+0x178>
 *   @0x1f5664 ble 0x1f56fc <_Z11OutputValueP11tagIConsoleP6RValue+0xc0>
 *   @0x1f5668 cmp r3, #3
 *   @0x1f566c beq 0x1f5760 <_Z11OutputValueP11tagIConsoleP6RValue+0x124>
 *   @0x1f5670 cmp r3, #5
 *   @0x1f5674 bne 0x1f577c <_Z11OutputValueP11tagIConsoleP6RValue+0x140>
 *   @0x1f5678 ldr r3, [r0]
 *   @0x1f567c ldr r1, [pc, #0x330]
 *   @0x1f5680 ldr r3, [r3, #0xc]
 *   @0x1f5684 add r1, pc, r1
 *   @0x1f5688 blx r3
 *   @0x1f568c b 0x1f56c8 <_Z11OutputValueP11tagIConsoleP6RValue+0x8c>
 *   @0x1f5690 cmp r3, #13
 *   @0x1f5694 beq 0x1f5734 <_Z11OutputValueP11tagIConsoleP6RValue+0xf8>
 *   @0x1f5698 bgt 0x1f56d0 <_Z11OutputValueP11tagIConsoleP6RValue+0x94>
 *   @0x1f569c cmp r3, #7
 *   @0x1f56a0 beq 0x1f5798 <_Z11OutputValueP11tagIConsoleP6RValue+0x15c>
 *   @0x1f56a4 cmp r3, #10
 *   @0x1f56a8 bne 0x1f577c <_Z11OutputValueP11tagIConsoleP6RValue+0x140>
 *   @0x1f56ac ldr r3, [r0]
 *   @0x1f56b0 ldr r1, [pc, #0x300]
 *   @0x1f56b4 ldr r2, [r7]
 *   @0x1f56b8 ldr r12, [r3, #0xc]
 *   @0x1f56bc add r1, pc, r1
 *   @0x1f56c0 ldr r3, [r7, #0x4]
 *   @0x1f56c4 blx r12
 *   @0x1f56c8 add sp, sp, #12
 *   @0x1f56cc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1f56d0 cmp r3, #14
 *   @0x1f56d4 beq 0x1f58fc <_Z11OutputValueP11tagIConsoleP6RValue+0x2c0>
 *   @0x1f56d8 mvn r2, #-16777216
 *   @0x1f56dc cmp r3, r2
 *   @0x1f56e0 bne 0x1f577c <_Z11OutputValueP11tagIConsoleP6RValue+0x140>
 *   @0x1f56e4 ldr r3, [r0]
 *   @0x1f56e8 ldr r1, [pc, #0x2cc]
 *   @0x1f56ec ldr r3, [r3, #0xc]
 *   @0x1f56f0 add r1, pc, r1
 *   @0x1f56f4 blx r3
 *   @0x1f56f8 b 0x1f56c8 <_Z11OutputValueP11tagIConsoleP6RValue+0x8c>
 *   @0x1f56fc cmp r3, #0
 *   @0x1f5700 beq 0x1f5914 <_Z11OutputValueP11tagIConsoleP6RValue+0x2d8>
 *   @0x1f5704 cmp r3, #1
 *   @0x1f5708 bne 0x1f577c <_Z11OutputValueP11tagIConsoleP6RValue+0x140>
 *   @0x1f570c ldr r3, [r1]
 *   @0x1f5710 ldr r2, [r0]
 *   @0x1f5714 cmp r3, #0
 *   @0x1f5718 ldr r1, [pc, #0x2a0]
 *   @0x1f571c ldr r12, [r2, #0xc]
 *   @0x1f5720 add r1, pc, r1
 *   @0x1f5724 ldrne r2, [r3]
 *   @0x1f5728 moveq r2, r3
 *   @0x1f572c blx r12
 *   @0x1f5730 b 0x1f56c8 <_Z11OutputValueP11tagIConsoleP6RValue+0x8c>
 *   @0x1f5734 ldm r1, {r2, r3}
 *   @0x1f5738 vmov d6, r2, r3
 *   @0x1f573c ldr r3, [r0]
 *   @0x1f5740 vcmp.f64 d6, #0
 *   @0x1f5744 vmrs APSR_nzcv, fpscr
 *   @0x1f5748 bne 0x1f5984 <_Z11OutputValueP11tagIConsoleP6RValue+0x348>
 *   @0x1f574c ldr r1, [pc, #0x270]
 *   @0x1f5750 ldr r3, [r3, #0xc]
 *   @0x1f5754 add r1, pc, r1
 *   @0x1f5758 blx r3
 *   @0x1f575c b 0x1f56c8 <_Z11OutputValueP11tagIConsoleP6RValue+0x8c>
 *   @0x1f5760 ldr r3, [r0]
 *   @0x1f5764 ldr r2, [r1]
 *   @0x1f5768 ldr r1, [pc, #0x258]
 *   @0x1f576c ldr r3, [r3, #0xc]
 *   @0x1f5770 add r1, pc, r1
 *   @0x1f5774 blx r3
 *   @0x1f5778 b 0x1f56c8 <_Z11OutputValueP11tagIConsoleP6RValue+0x8c>
 *   @0x1f577c ldr r3, [r6]
 *   @0x1f5780 mov r0, r6
 *   @0x1f5784 ldr r1, [pc, #0x240]
 *   @0x1f5788 ldr r3, [r3, #0xc]
 *   @0x1f578c add r1, pc, r1
 *   @0x1f5790 blx r3
 *   @0x1f5794 b 0x1f56c8 <_Z11OutputValueP11tagIConsoleP6RValue+0x8c>
 *   @0x1f5798 ldr r3, [r0]
 *   @0x1f579c ldr r2, [r1]
 *   @0x1f57a0 ldr r1, [pc, #0x228]
 *   @0x1f57a4 ldr r3, [r3, #0xc]
 *   @0x1f57a8 add r1, pc, r1
 *   @0x1f57ac blx r3
 *   @0x1f57b0 b 0x1f56c8 <_Z11OutputValueP11tagIConsoleP6RValue+0x8c>
 *   @0x1f57b4 ldr r10, [pc, #0x218]
 *   @0x1f57b8 ldr r3, [r0]
 *   @0x1f57bc add r10, pc, r10
 *   @0x1f57c0 ldr r3, [r3, #0xc]
 *   @0x1f57c4 mov r1, r10
 *   @0x1f57c8 blx r3
 *   @0x1f57cc ldr r8, [r7]
 *   @0x1f57d0 cmp r8, #0
 *   @0x1f57d4 beq 0x1f58c4 <_Z11OutputValueP11tagIConsoleP6RValue+0x288>
 *   @0x1f57d8 ldr r3, [r8, #0x10]
 *   @0x1f57dc cmp r3, #0
 *   @0x1f57e0 ble 0x1f58c4 <_Z11OutputValueP11tagIConsoleP6RValue+0x288>
 *   @0x1f57e4 ldr r5, [pc, #0x1ec]
 *   @0x1f57e8 mov r7, #0
 *   @0x1f57ec ldr r9, [pc, #0x1e8]
 *   @0x1f57f0 ldr r3, [pc, #0x1e8]
 *   @0x1f57f4 add r5, pc, r5
 *   @0x1f57f8 add r9, pc, r9
 *   @0x1f57fc add r3, pc, r3
 *   @0x1f5800 str r3, [sp, #0x4]
 *   @0x1f5804 ldr r3, [r6]
 *   @0x1f5808 mov r0, r6
 *   @0x1f580c ldr r4, [r8, #0x4]
 *   @0x1f5810 mov r1, r10
 *   @0x1f5814 ldr r2, [r3, #0xc]
 *   @0x1f5818 add r11, r4, r7, lsl #3
 *   @0x1f581c blx r2
 *   @0x1f5820 ldr r2, [r4, r7, lsl #3]
 *   @0x1f5824 cmp r2, #0
 *   @0x1f5828 ble 0x1f588c <_Z11OutputValueP11tagIConsoleP6RValue+0x250>
 *   @0x1f582c mov r4, #0
 *   @0x1f5830 ldr r1, [r11, #0x4]
 *   @0x1f5834 mov r0, r6
 *   @0x1f5838 add r1, r1, r4, lsl #4
 *   @0x1f583c add r4, r4, #1
 *   @0x1f5840 bl 0x1f563c <_Z11OutputValueP11tagIConsoleP6RValue>
 *   @0x1f5844 ldr r2, [r11]
 *   @0x1f5848 mov r0, r6
 *   @0x1f584c mov r1, r5
 *   @0x1f5850 cmp r2, #30
 *   @0x1f5854 movlt r12, r2
 *   @0x1f5858 movge r12, #30
 *   @0x1f585c cmp r4, r12
 *   @0x1f5860 bge 0x1f5874 <_Z11OutputValueP11tagIConsoleP6RValue+0x238>
 *   @0x1f5864 ldr r2, [r6]
 *   @0x1f5868 ldr r2, [r2, #0xc]
 *   @0x1f586c blx r2
 *   @0x1f5870 b 0x1f5830 <_Z11OutputValueP11tagIConsoleP6RValue+0x1f4>
 *   @0x1f5874 cmp r2, #30
 *   @0x1f5878 ble 0x1f588c <_Z11OutputValueP11tagIConsoleP6RValue+0x250>
 *   @0x1f587c ldr r3, [r6]
 *   @0x1f5880 ldr r1, [sp, #0x4]
 *   @0x1f5884 ldr r3, [r3, #0xc]
 *   @0x1f5888 blx r3
 *   @0x1f588c ldr r3, [r6]
 *   @0x1f5890 mov r0, r6
 *   @0x1f5894 mov r1, r9
 *   @0x1f5898 add r7, r7, #1
 *   @0x1f589c ldr r3, [r3, #0xc]
 *   @0x1f58a0 blx r3
 *   @0x1f58a4 ldr r3, [r8, #0x10]
 *   @0x1f58a8 cmp r3, #30
 *   @0x1f58ac movlt r2, r3
 *   @0x1f58b0 movge r2, #30
 *   @0x1f58b4 cmp r7, r2
 *   @0x1f58b8 blt 0x1f5804 <_Z11OutputValueP11tagIConsoleP6RValue+0x1c8>
 *   @0x1f58bc cmp r3, #30
 *   @0x1f58c0 bgt 0x1f5998 <_Z11OutputValueP11tagIConsoleP6RValue+0x35c>
 *   @0x1f58c4 ldr r3, [r6]
 *   @0x1f58c8 mov r0, r6
 *   @0x1f58cc ldr r1, [pc, #0x110]
 *   @0x1f58d0 ldr r3, [r3, #0xc]
 *   @0x1f58d4 add r1, pc, r1
 *   @0x1f58d8 blx r3
 *   @0x1f58dc b 0x1f56c8 <_Z11OutputValueP11tagIConsoleP6RValue+0x8c>
 *   @0x1f58e0 ldr r3, [r0]
 *   @0x1f58e4 ldr r2, [r1]
 *   @0x1f58e8 ldr r1, [pc, #0xf8]
 *   @0x1f58ec ldr r3, [r3, #0xc]
 *   @0x1f58f0 add r1, pc, r1
 *   @0x1f58f4 blx r3
 *   @0x1f58f8 b 0x1f56c8 <_Z11OutputValueP11tagIConsoleP6RValue+0x8c>
 *   @0x1f58fc ldr r3, [r0]
 *   @0x1f5900 ldr r1, [pc, #0xe4]
 *   @0x1f5904 ldr r3, [r3, #0xc]
 *   @0x1f5908 add r1, pc, r1
 *   @0x1f590c blx r3
 *   @0x1f5910 b 0x1f56c8 <_Z11OutputValueP11tagIConsoleP6RValue+0x8c>
 *   @0x1f5914 ldm r1, {r4, r5}
 *   @0x1f5918 mov r0, r4
 *   @0x1f591c mov r1, r5
 *   @0x1f5920 bl 0xb66e8 <lrint@plt>
 *   @0x1f5924 ldr r2, [r7]
 *   @0x1f5928 ldr r12, [r6]
 *   @0x1f592c vmov s12, r0
 *   @0x1f5930 mov r0, r6
 *   @0x1f5934 vcvt.f64.s32 d7, s12
 *   @0x1f5938 vmov d6, r4, r5
 *   @0x1f593c vcmp.f64 d6, d7
 *   @0x1f5940 vmrs APSR_nzcv, fpscr
 *   @0x1f5944 bne 0x1f596c <_Z11OutputValueP11tagIConsoleP6RValue+0x330>
 *   @0x1f5948 ldr r3, [r7, #0x4]
 *   @0x1f594c ldr r1, [pc, #0x9c]
 *   @0x1f5950 ldr r12, [r12, #0xc]
 *   @0x1f5954 vmov d7, r2, r3
 *   @0x1f5958 add r1, pc, r1
 *   @0x1f595c vcvt.s32.f64 s15, d7
 *   @0x1f5960 vmov r2, s15
 *   @0x1f5964 blx r12
 *   @0x1f5968 b 0x1f56c8 <_Z11OutputValueP11tagIConsoleP6RValue+0x8c>
 *   @0x1f596c ldr r1, [pc, #0x80]
 *   @0x1f5970 ldr r3, [r7, #0x4]
 *   @0x1f5974 add r1, pc, r1
 *   @0x1f5978 ldr r12, [r12, #0xc]
 *   @0x1f597c blx r12
 *   @0x1f5980 b 0x1f56c8 <_Z11OutputValueP11tagIConsoleP6RValue+0x8c>
 *   @0x1f5984 ldr r1, [pc, #0x6c]
 *   @0x1f5988 ldr r3, [r3, #0xc]
 *   @0x1f598c add r1, pc, r1
 *   @0x1f5990 blx r3
 *   @0x1f5994 b 0x1f56c8 <_Z11OutputValueP11tagIConsoleP6RValue+0x8c>
 *   @0x1f5998 ldr r3, [r6]
 *   @0x1f599c mov r0, r6
 *   @0x1f59a0 ldr r1, [pc, #0x54]
 *   @0x1f59a4 ldr r3, [r3, #0xc]
 *   @0x1f59a8 add r1, pc, r1
 *   @0x1f59ac blx r3
 *   @0x1f59b0 b 0x1f58c4 <_Z11OutputValueP11tagIConsoleP6RValue+0x288>
 *   @0x1f59b4 ldrsbeq r12, [r3], -r12
 *   @0x1f59b8 ldrsbeq sp, [r5], -r4
 *   @0x1f59bc andseq sp, r5, r4, lsr #3
 *   @0x1f59c0 andseq sp, r5, r8, asr r1
 *   @0x1f59c4 ldrsbeq pc, [r3], -r4
 *   @0x1f59c8 mulseq r3, r8, sp
 *   @0x1f59cc andseq sp, r5, r4, lsr #2
 *   @0x1f59d0 andseq r12, r3, r4, ror #26
 *   @0x1f59d4 andseq r12, r3, r0, ror #26
 *   @0x1f59d8 andseq sp, r5, r8, lsr #1
 *   @0x1f59dc ldrheq sp, [r5], -r0
 *   @0x1f59e0 andseq sp, r5, r4, lsr #1
 *   @0x1f59e4 andseq r12, r3, r12, asr #24
 *   @0x1f59e8 mulseq r5, r0, pc
 *   @0x1f59ec andseq r12, r3, r4, lsr #19
 *   @0x1f59f0 ldrheq r12, [r3], -r4
 *   @0x1f59f4 andseq r10, r4, r0, asr #20
 *   @0x1f59f8 mulseq r3, r4, r0
 *   @0x1f59fc ldrsheq r12, [r5], -r8
 *
 * ══ §17/33 b2RevoluteJoint::SolveVelocityConstraints(b2SolverData const&)  0x2d1508  size 964  241 条（0x2d1508..0x2d18cc）
 * @func 0x2d1508 0x2d18cc  size 964  241 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Mat33::Solve22(b2Vec2 const&) const×3 / b2Mat33::Solve33(b2Vec3 const&) const / b2RevoluteJoint::SolveVelocityConstraints(b2SolverData const&)+0x354
 * 字段偏移 top8: 0xe0×3 / 0x80×2 / 0x84×2 / 0x1c×2 / 0x64×1 / 0x70×1 / 0x5c×1
 * VFP 指令 167 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d1508 push {r4, r5, r6, r7, r8, lr}
 *   @0x2d150c vpush {d8, d9, d10, d11, d12, d13}
 *   @0x2d1510 vldr s19, [r0, #176]
 *   @0x2d1514 vldr s18, [r0, #180]
 *   @0x2d1518 vadd.f32 s15, s19, s18
 *   @0x2d151c ldr r2, [r0, #0x80]
 *   @0x2d1520 ldr r3, [r0, #0x84]
 *   @0x2d1524 mov r4, r0
 *   @0x2d1528 mov r5, r1
 *   @0x2d152c vldr s22, [r0, #168]
 *   @0x2d1530 ldr r1, [r1, #0x1c]
 *   @0x2d1534 add r2, r2, r2, lsl #1
 *   @0x2d1538 ldrb r0, [r0, #0x64]
 *   @0x2d153c add r3, r3, r3, lsl #1
 *   @0x2d1540 add r2, r1, r2, lsl #2
 *   @0x2d1544 vldr s25, [r2]
 *   @0x2d1548 vldr s23, [r2, #4]
 *   @0x2d154c vldr s17, [r2, #8]
 *   @0x2d1550 add r3, r1, r3, lsl #2
 *   @0x2d1554 sub sp, sp, #32
 *   @0x2d1558 vldr s21, [r4, #172]
 *   @0x2d155c vldr s24, [r3]
 *   @0x2d1560 vldr s20, [r3, #4]
 *   @0x2d1564 vldr s16, [r3, #8]
 *   @0x2d1568 vcmp.f32 s15, #0
 *   @0x2d156c vmrs APSR_nzcv, fpscr
 *   @0x2d1570 movne r2, #0
 *   @0x2d1574 moveq r2, #1
 *   @0x2d1578 cmp r0, #0
 *   @0x2d157c beq 0x2d1594 <_ZN15b2RevoluteJoint24SolveVelocityConstraintsERK12b2SolverData+0x8c>
 *   @0x2d1580 ldr r3, [r4, #0xe0]
 *   @0x2d1584 cmp r3, #3
 *   @0x2d1588 beq 0x2d1594 <_ZN15b2RevoluteJoint24SolveVelocityConstraintsERK12b2SolverData+0x8c>
 *   @0x2d158c cmp r2, #0
 *   @0x2d1590 beq 0x2d176c <_ZN15b2RevoluteJoint24SolveVelocityConstraintsERK12b2SolverData+0x264>
 *   @0x2d1594 ldrb r3, [r4, #0x70]
 *   @0x2d1598 cmp r3, #0
 *   @0x2d159c beq 0x2d15ac <_ZN15b2RevoluteJoint24SolveVelocityConstraintsERK12b2SolverData+0xa4>
 *   @0x2d15a0 ldr r3, [r4, #0xe0]
 *   @0x2d15a4 cmp r3, #0
 *   @0x2d15a8 bne 0x2d1694 <_ZN15b2RevoluteJoint24SolveVelocityConstraintsERK12b2SolverData+0x18c>
 *   @0x2d15ac vmov.f32 s11, s20
 *   @0x2d15b0 vldr s14, [r4, #144]
 *   @0x2d15b4 vldr s15, [r4, #148]
 *   @0x2d15b8 vldr s12, [r4, #136]
 *   @0x2d15bc vldr s13, [r4, #140]
 *   @0x2d15c0 add r0, sp, #8
 *   @0x2d15c4 add r1, r4, #184
 *   @0x2d15c8 add r2, sp, #20
 *   @0x2d15cc vmov.f32 s10, s24
 *   @0x2d15d0 vmla.f32 s11, s16, s14
 *   @0x2d15d4 vmls.f32 s10, s16, s15
 *   @0x2d15d8 vsub.f32 s14, s11, s23
 *   @0x2d15dc vsub.f32 s15, s10, s25
 *   @0x2d15e0 vmls.f32 s14, s17, s12
 *   @0x2d15e4 vmla.f32 s15, s17, s13
 *   @0x2d15e8 vneg.f32 s14, s14
 *   @0x2d15ec vneg.f32 s15, s15
 *   @0x2d15f0 vstr s14, [sp, #24]
 *   @0x2d15f4 vstr s15, [sp, #20]
 *   @0x2d15f8 bl 0x2c68e8 <_ZNK7b2Mat337Solve22ERK6b2Vec2>
 *   @0x2d15fc vldr s14, [sp, #8]
 *   @0x2d1600 vldr s12, [r4, #140]
 *   @0x2d1604 vldr s13, [r4, #148]
 *   @0x2d1608 vmul.f32 s12, s14, s12
 *   @0x2d160c vldr s15, [sp, #12]
 *   @0x2d1610 vldr s8, [r4, #136]
 *   @0x2d1614 vldr s9, [r4, #144]
 *   @0x2d1618 vldr s10, [r4, #84]
 *   @0x2d161c vldr s11, [r4, #88]
 *   @0x2d1620 vmul.f32 s13, s14, s13
 *   @0x2d1624 vnmls.f32 s12, s15, s8
 *   @0x2d1628 vnmls.f32 s13, s15, s9
 *   @0x2d162c vmls.f32 s17, s19, s12
 *   @0x2d1630 vmla.f32 s16, s18, s13
 *   @0x2d1634 vmls.f32 s25, s22, s14
 *   @0x2d1638 vmla.f32 s24, s21, s14
 *   @0x2d163c vmls.f32 s23, s22, s15
 *   @0x2d1640 vmla.f32 s20, s21, s15
 *   @0x2d1644 vadd.f32 s14, s10, s14
 *   @0x2d1648 vadd.f32 s15, s11, s15
 *   @0x2d164c vstr s14, [r4, #84]
 *   @0x2d1650 vstr s15, [r4, #88]
 *   @0x2d1654 ldr r2, [r4, #0x80]
 *   @0x2d1658 ldr r3, [r4, #0x84]
 *   @0x2d165c ldr r1, [r5, #0x1c]
 *   @0x2d1660 add r2, r2, r2, lsl #1
 *   @0x2d1664 add r3, r3, r3, lsl #1
 *   @0x2d1668 add r2, r1, r2, lsl #2
 *   @0x2d166c vstr s25, [r2]
 *   @0x2d1670 vstr s23, [r2, #4]
 *   @0x2d1674 vstr s17, [r2, #8]
 *   @0x2d1678 add r3, r1, r3, lsl #2
 *   @0x2d167c vstr s24, [r3]
 *   @0x2d1680 vstr s20, [r3, #4]
 *   @0x2d1684 vstr s16, [r3, #8]
 *   @0x2d1688 add sp, sp, #32
 *   @0x2d168c vpop {d8, d9, d10, d11, d12, d13}
 *   @0x2d1690 pop {r4, r5, r6, r7, r8, pc}
 *   @0x2d1694 cmp r2, #0
 *   @0x2d1698 bne 0x2d15ac <_ZN15b2RevoluteJoint24SolveVelocityConstraintsERK12b2SolverData+0xa4>
 *   @0x2d169c vmov.f32 s26, s24
 *   @0x2d16a0 vldr s12, [r4, #148]
 *   @0x2d16a4 vldr s13, [r4, #144]
 *   @0x2d16a8 vldr s14, [r4, #140]
 *   @0x2d16ac vldr s15, [r4, #136]
 *   @0x2d16b0 add r6, r4, #184
 *   @0x2d16b4 add r7, sp, #20
 *   @0x2d16b8 add r2, sp, #8
 *   @0x2d16bc vmov.f32 s27, s20
 *   @0x2d16c0 mov r1, r6
 *   @0x2d16c4 mov r0, r7
 *   @0x2d16c8 vmls.f32 s26, s16, s12
 *   @0x2d16cc vmla.f32 s27, s16, s13
 *   @0x2d16d0 vsub.f32 s26, s26, s25
 *   @0x2d16d4 vsub.f32 s27, s27, s23
 *   @0x2d16d8 vmla.f32 s26, s17, s14
 *   @0x2d16dc vmls.f32 s27, s17, s15
 *   @0x2d16e0 vstr s26, [sp, #8]
 *   @0x2d16e4 vsub.f32 s15, s16, s17
 *   @0x2d16e8 vstr s27, [sp, #12]
 *   @0x2d16ec vstr s15, [sp, #16]
 *   @0x2d16f0 bl 0x2c6808 <_ZNK7b2Mat337Solve33ERK6b2Vec3>
 *   @0x2d16f4 ldr r3, [r4, #0xe0]
 *   @0x2d16f8 vldr s10, [sp, #20]
 *   @0x2d16fc vldr s12, [sp, #24]
 *   @0x2d1700 vldr s13, [sp, #28]
 *   @0x2d1704 cmp r3, #3
 *   @0x2d1708 vneg.f32 s14, s10
 *   @0x2d170c vneg.f32 s15, s12
 *   @0x2d1710 vneg.f32 s11, s13
 *   @0x2d1714 beq 0x2d1834 <_ZN15b2RevoluteJoint24SolveVelocityConstraintsERK12b2SolverData+0x32c>
 *   @0x2d1718 cmp r3, #1
 *   @0x2d171c beq 0x2d187c <_ZN15b2RevoluteJoint24SolveVelocityConstraintsERK12b2SolverData+0x374>
 *   @0x2d1720 cmp r3, #2
 *   @0x2d1724 beq 0x2d17c4 <_ZN15b2RevoluteJoint24SolveVelocityConstraintsERK12b2SolverData+0x2bc>
 *   @0x2d1728 vldr s12, [r4, #140]
 *   @0x2d172c vldr s13, [r4, #148]
 *   @0x2d1730 vmul.f32 s12, s14, s12
 *   @0x2d1734 vldr s9, [r4, #136]
 *   @0x2d1738 vldr s10, [r4, #144]
 *   @0x2d173c vmul.f32 s13, s14, s13
 *   @0x2d1740 vnmls.f32 s12, s15, s9
 *   @0x2d1744 vnmls.f32 s13, s15, s10
 *   @0x2d1748 vadd.f32 s12, s12, s11
 *   @0x2d174c vadd.f32 s13, s13, s11
 *   @0x2d1750 vmls.f32 s25, s22, s14
 *   @0x2d1754 vmls.f32 s23, s22, s15
 *   @0x2d1758 vmla.f32 s24, s21, s14
 *   @0x2d175c vmla.f32 s20, s21, s15
 *   @0x2d1760 vmls.f32 s17, s12, s19
 *   @0x2d1764 vmla.f32 s16, s13, s18
 *   @0x2d1768 b 0x2d1654 <_ZN15b2RevoluteJoint24SolveVelocityConstraintsERK12b2SolverData+0x14c>
 *   @0x2d176c vsub.f32 s10, s16, s17
 *   @0x2d1770 vldr s12, [r4, #108]
 *   @0x2d1774 vldr s14, [r4, #96]
 *   @0x2d1778 vldr s11, [r4, #220]
 *   @0x2d177c vldr s13, [r5]
 *   @0x2d1780 vldr s15, [r4, #104]
 *   @0x2d1784 vsub.f32 s12, s10, s12
 *   @0x2d1788 vmov.f32 s10, s14
 *   @0x2d178c vmls.f32 s10, s11, s12
 *   @0x2d1790 vmul.f32 s15, s13, s15
 *   @0x2d1794 vcmpe.f32 s15, s10
 *   @0x2d1798 vneg.f32 s13, s15
 *   @0x2d179c vmrs APSR_nzcv, fpscr
 *   @0x2d17a0 vmovgt.f32 s15, s10
 *   @0x2d17a4 vcmpe.f32 s13, s15
 *   @0x2d17a8 vmrs APSR_nzcv, fpscr
 *   @0x2d17ac vmovgt.f32 s15, s13
 *   @0x2d17b0 vstr s15, [r4, #96]
 *   @0x2d17b4 vsub.f32 s15, s15, s14
 *   @0x2d17b8 vmls.f32 s17, s19, s15
 *   @0x2d17bc vmla.f32 s16, s18, s15
 *   @0x2d17c0 b 0x2d1594 <_ZN15b2RevoluteJoint24SolveVelocityConstraintsERK12b2SolverData+0x8c>
 *   @0x2d17c4 vldr s9, [r4, #92]
 *   @0x2d17c8 vsub.f32 s13, s9, s13
 *   @0x2d17cc mov r8, #0
 *   @0x2d17d0 vcmpe.f32 s13, #0
 *   @0x2d17d4 vmrs APSR_nzcv, fpscr
 *   @0x2d17d8 ble 0x2d185c <_ZN15b2RevoluteJoint24SolveVelocityConstraintsERK12b2SolverData+0x354>
 *   @0x2d17dc vldr s14, [r4, #212]
 *   @0x2d17e0 vldr s15, [r4, #208]
 *   @0x2d17e4 vnmls.f32 s27, s9, s14
 *   @0x2d17e8 mov r0, r7
 *   @0x2d17ec mov r1, r6
 *   @0x2d17f0 mov r2, sp
 *   @0x2d17f4 vnmls.f32 s26, s9, s15
 *   @0x2d17f8 vstr s27, [sp, #4]
 *   @0x2d17fc vstr s26, [sp]
 *   @0x2d1800 bl 0x2c68e8 <_ZNK7b2Mat337Solve22ERK6b2Vec2>
 *   @0x2d1804 vldr s14, [sp, #20]
 *   @0x2d1808 vldr s12, [r4, #84]
 *   @0x2d180c vldr s15, [sp, #24]
 *   @0x2d1810 vldr s13, [r4, #88]
 *   @0x2d1814 vadd.f32 s12, s12, s14
 *   @0x2d1818 vldr s11, [r4, #92]
 *   @0x2d181c str r8, [r4, #0x5c]
 *   @0x2d1820 vadd.f32 s13, s13, s15
 *   @0x2d1824 vstr s12, [r4, #84]
 *   @0x2d1828 vstr s13, [r4, #88]
 *   @0x2d182c vneg.f32 s11, s11
 *   @0x2d1830 b 0x2d1728 <_ZN15b2RevoluteJoint24SolveVelocityConstraintsERK12b2SolverData+0x220>
 *   @0x2d1834 vldr s7, [r4, #84]
 *   @0x2d1838 vldr s8, [r4, #88]
 *   @0x2d183c vldr s9, [r4, #92]
 *   @0x2d1840 vsub.f32 s10, s7, s10
 *   @0x2d1844 vsub.f32 s12, s8, s12
 *   @0x2d1848 vstr s10, [r4, #84]
 *   @0x2d184c vsub.f32 s13, s9, s13
 *   @0x2d1850 vstr s12, [r4, #88]
 *   @0x2d1854 vstr s13, [r4, #92]
 *   @0x2d1858 b 0x2d1728 <_ZN15b2RevoluteJoint24SolveVelocityConstraintsERK12b2SolverData+0x220>
 *   @0x2d185c vldr s8, [r4, #84]
 *   @0x2d1860 vldr s9, [r4, #88]
 *   @0x2d1864 vsub.f32 s10, s8, s10
 *   @0x2d1868 vstr s13, [r4, #92]
 *   @0x2d186c vsub.f32 s12, s9, s12
 *   @0x2d1870 vstr s10, [r4, #84]
 *   @0x2d1874 vstr s12, [r4, #88]
 *   @0x2d1878 b 0x2d1728 <_ZN15b2RevoluteJoint24SolveVelocityConstraintsERK12b2SolverData+0x220>
 *   @0x2d187c vldr s9, [r4, #92]
 *   @0x2d1880 vsub.f32 s13, s9, s13
 *   @0x2d1884 mov r8, #0
 *   @0x2d1888 vcmpe.f32 s13, #0
 *   @0x2d188c vmrs APSR_nzcv, fpscr
 *   @0x2d1890 bpl 0x2d185c <_ZN15b2RevoluteJoint24SolveVelocityConstraintsERK12b2SolverData+0x354>
 *   @0x2d1894 vldr s14, [r4, #212]
 *   @0x2d1898 vldr s15, [r4, #208]
 *   @0x2d189c vnmls.f32 s27, s9, s14
 *   @0x2d18a0 mov r1, r6
 *   @0x2d18a4 mov r2, r7
 *   @0x2d18a8 mov r0, sp
 *   @0x2d18ac vnmls.f32 s26, s9, s15
 *   @0x2d18b0 vstr s27, [sp, #24]
 *   @0x2d18b4 vstr s26, [sp, #20]
 *   @0x2d18b8 bl 0x2c68e8 <_ZNK7b2Mat337Solve22ERK6b2Vec2>
 *   @0x2d18bc vldr s14, [sp]
 *   @0x2d18c0 vldr s12, [r4, #84]
 *   @0x2d18c4 vldr s15, [sp, #4]
 *   @0x2d18c8 b 0x2d1810 <_ZN15b2RevoluteJoint24SolveVelocityConstraintsERK12b2SolverData+0x308>
 *
 * ══ §18/33 zip_open  0x2a4de0  size 960  240 条（0x2a4de0..0x2a51a0）
 * @func 0x2a4de0 0x2a51a0  size 960  240 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _zip_cdir_free(zip_cdir*)×4 / 0xb655c×3 / _zip_read2(unsigned char**)×3 / 0xb6bf8×2 / 0xb6f1c×2 / _zip_read4(unsigned char**)×2 / anon_2a4a60+0x25a / 0xb6844
 * 字段偏移 top8: 0x8×4 / 0x18×3 / 0x14×3 / 0x10×2 / 0x2c×2 / 0x1c×2 / 0x24×2 / 0x4×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a4de0 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2a4de4 sub sp, #0xa4
 *   @0x2a4de8 str r1, [sp, #0x10]
 *   @0x2a4dec cbnz r0, 0x2a4df6 <zip_open+0x16>
 *   @0x2a4df0 beq 0x2a4eca <zip_open+0xea>
 *   @0x2a4df4 b 0x2a4e1c <zip_open+0x3c>
 *   @0x2a4df8 mov r1, r7
 *   @0x2a4dfc ldrshlt lr, [r0, -r12]!
 *   @0x2a4e00 ldr r2, [sp, #0x10]
 *   @0x2a4e04 bmi 0x2a4e20 <zip_open+0x40>
 *   @0x2a4e08 beq 0x2a4eca <zip_open+0xea>
 *   @0x2a4e0c b 0x2a4e1c <zip_open+0x3c>
 *   @0x2a4e10 ands r4, r3, #0x2
 *   @0x2a4e14 beq 0x2a4e2a <zip_open+0x4a>
 *   @0x2a4e18 beq 0x2a4eca <zip_open+0xea>
 *   @0x2a4e1c str r3, [r5]
 *   @0x2a4e20 ldr r0, [sp, #0x18]
 *   @0x2a4e24 bl 0x2a4cba <zip_name_locate+0x262>
 *   @0x2a4e28 b 0x2a519a <zip_open+0x3ba>
 *   @0x2a4e2c ldr r0, [sp, #0x18]
 *   @0x2a4e30 blx 0xb6844 <fopen@plt>
 *   @0x2a4e34 mov r6, r0
 *   @0x2a4e38 cmp r5, #0x0
 *   @0x2a4e3c movs r3, #0xb
 *   @0x2a4e40 b 0x2a519a <zip_open+0x3ba>
 *   @0x2a4e44 movs r2, #0x2
 *   @0x2a4e48 ldrtmi lr, [r0], -r6, asr #16
 *   @0x2a4e4c blx 0xb6ee0 <ftello@plt>
 *   @0x2a4e50 cbnz r0, 0x2a4e62 <zip_open+0x82>
 *   @0x2a4e54 mov r1, r5
 *   @0x2a4e58 .word 0x4604ff30
 *   @0x2a4e5c cbz r0, 0x2a4ea0 <zip_open+0xc0>
 *   @0x2a4e60 b 0x2a4eb0 <zip_open+0xd0>
 *   @0x2a4e64 movs r2, #0x2
 *   @0x2a4e68 it lt
 *   @0x2a4e6c mov r0, r6
 *   @0x2a4e70 blx 0xb6ed4 <fseeko@plt>
 *   @0x2a4e74 adds r0, #0x1
 *   @0x2a4e78 blx 0xb6bf8 <__errno@plt>
 *   @0x2a4e7c ldr r3, [r0]
 *   @0x2a4e80 bne 0x2a4ed2 <zip_open+0xf2>
 *   @0x2a4e84 cmp.w r8, #0x0
 *   @0x2a4e88 beq 0x2a4ec4 <zip_open+0xe4>
 *   @0x2a4e8c mov r1, r5
 *   @0x2a4e90 .word 0x4604ff14
 *   @0x2a4e94 cmp r0, #0x0
 *   @0x2a4e98 strbmi r8, [r0], -r0, ror #2
 *   @0x2a4e9c bl 0x2a3bf6 <_Z14_zip_cdir_freeP8zip_cdir>
 *   @0x2a4ea0 mov r0, r6
 *   @0x2a4ea4 ldrd lr, pc, [r3], -r6
 *   @0x2a4ea8 bl 0x2a4a90 <zip_name_locate+0x38>
 *   @0x2a4eac ldr r3, [r4, #0x18]
 *   @0x2a4eb0 mov r0, r4
 *   @0x2a4eb4 ldr r0, [pc, #0x208]
 *   @0x2a4eb8 strmi lr, [r3], r6, asr #22
 *   @0x2a4ebc cbnz r0, 0x2a4eda <zip_open+0xfa>
 *   @0x2a4ec0 movs r3, #0xe
 *   @0x2a4ec4 mov r0, r6
 *   @0x2a4ec8 andhs lr, r0, r4, asr #25
 *   @0x2a4ecc b 0x2a519a <zip_open+0x3ba>
 *   @0x2a4ed0 b 0x2a519a <zip_open+0x3ba>
 *   @0x2a4ed4 cmp r5, #0x0
 *   @0x2a4ed8 b 0x2a4ec4 <zip_open+0xe4>
 *   @0x2a4edc blx 0xb6f1c <clearerr@plt>
 *   @0x2a4ee0 mov r0, r11
 *   @0x2a4ee4 ldr r2, [pc, #0x1d8]
 *   @0x2a4ee8 blx 0xb68c8 <fread@plt>
 *   @0x2a4eec ldrh.w r8, [r6, #0xc]
 *   @0x2a4ef0 and r8, r8, #0x40
 *   @0x2a4ef4 uxth.w r4, r8
 *   @0x2a4ef8 str r0, [sp, #0x20]
 *   @0x2a4efc cbz r5, 0x2a4f02 <zip_open+0x122>
 *   @0x2a4f00 str r3, [r5]
 *   @0x2a4f04 blx 0xb655c <free@plt>
 *   @0x2a4f08 b 0x2a4ec4 <zip_open+0xe4>
 *   @0x2a4f0c mov r0, r7
 *   @0x2a4f10 mov r8, r4
 *   @0x2a4f14 .word 0xf04ffa21
 *   @0x2a4f18 blmi 0x1d71b1c <b2_toiTime+0x1618678>
 *   @0x2a4f1c str r2, [sp, #0x8]
 *   @0x2a4f20 add r3, pc
 *   @0x2a4f24 movwls r11, #0xa01c
 *   @0x2a4f28 add r2, pc
 *   @0x2a4f2c str r2, [sp, #0x2c]
 *   @0x2a4f30 ldr r2, [sp, #0x1c]
 *   @0x2a4f34 rsb r1, r2, r11
 *   @0x2a4f38 add r1, r3
 *   @0x2a4f3c subs r1, #0x12
 *   @0x2a4f40 strmi pc, [r1], r3, lsl #28
 *   @0x2a4f44 cmp r0, #0x0
 *   @0x2a4f48 blls 0x4c5330 <SrcVerts+0x22374>
 *   @0x2a4f4c add.w r2, r9, #0x1
 *   @0x2a4f50 str r2, [sp, #0x1c]
 *   @0x2a4f54 rsb r3, r9, r3
 *   @0x2a4f58 subs r3, #0x16
 *   @0x2a4f5c bpl 0x2a4f66 <zip_open+0x186>
 *   @0x2a4f60 movs r1, #0x13
 *   @0x2a4f64 b 0x2a4f8a <zip_open+0x1aa>
 *   @0x2a4f68 movs r2, #0x4
 *   @0x2a4f6c strmi lr, [r4], -r10, ror #28
 *   @0x2a4f70 cmp r0, #0x0
 *   @0x2a4f74 add.w r0, r9, #0x4
 *   @0x2a4f78 ldr r1, [sp, #0x2c]
 *   @0x2a4f7c blx 0xb6c40 <memcmp@plt>
 *   @0x2a4f80 mov r10, r0
 *   @0x2a4f84 mov r0, r7
 *   @0x2a4f88 mov r2, r4
 *   @0x2a4f8c sbc pc, lr, r5, ror #19
 *   @0x2a4f90 add r0, sp, #0x30
 *   @0x2a4f94 movwls r0, #0xc308
 *   @0x2a4f98 bl 0x2a3ec0 <_Z10_zip_read2PPh>
 *   @0x2a4f9c str r0, [sp, #0x24]
 *   @0x2a4fa0 bl 0x2a3ec0 <_Z10_zip_read2PPh>
 *   @0x2a4fa4 mov r1, r7
 *   @0x2a4fa8 strmi pc, [r4], -pc, ror #27
 *   @0x2a4fac cmp r0, #0x0
 *   @0x2a4fb0 stmdage r12, {r1, r2, r3, r4, r5, r7, pc}
 *   @0x2a4fb4 bl 0x2a3ed2 <_Z10_zip_read4PPh>
 *   @0x2a4fb8 str r0, [r4, #0x8]
 *   @0x2a4fbc bl 0x2a3ed2 <_Z10_zip_read4PPh>
 *   @0x2a4fc0 str.w r10, [r4, #0x10]
 *   @0x2a4fc4 str r0, [r4, #0xc]
 *   @0x2a4fc8 bl 0x2a3ec0 <_Z10_zip_read2PPh>
 *   @0x2a4fcc ldr r3, [sp, #0x14]
 *   @0x2a4fd0 mov r1, r0
 *   @0x2a4fd4 blt 0x2a4fde <zip_open+0x1fe>
 *   @0x2a4fd8 ldr r2, [sp, #0x24]
 *   @0x2a4fdc beq 0x2a4fe6 <zip_open+0x206>
 *   @0x2a4fe0 movs r1, #0x13
 *   @0x2a4fe4 b 0x2a506e <zip_open+0x28e>
 *   @0x2a4fe8 lsls r2, r3, #0x1d
 *   @0x2a4fec ldr r3, [sp, #0x14]
 *   @0x2a4ff0 beq 0x2a4ffa <zip_open+0x21a>
 *   @0x2a4ff4 movs r1, #0x15
 *   @0x2a4ff8 b 0x2a506e <zip_open+0x28e>
 *   @0x2a4ffc add.w r0, r9, #0x16
 *   @0x2a5000 mov r2, r7
 *   @0x2a5004 strhvs pc, [r0, -r9]!
 *   @0x2a5008 cmp r0, #0x0
 *   @0x2a500c ldr r3, [r4, #0x8]
 *   @0x2a5010 addsmi r0, r3, #-1879048192
 *   @0x2a5014 bhs 0x2a5022 <zip_open+0x242>
 *   @0x2a5018 bge 0x5a5c44 <g_SWFlineaavertbuff+0x52b7c>
 *   @0x2a501c str r3, [sp, #0x30]
 *   @0x2a5020 b 0x2a507a <zip_open+0x29a>
 *   @0x2a5024 blx 0xb6f1c <clearerr@plt>
 *   @0x2a5028 mov r0, r6
 *   @0x2a502c movs r2, #0x0
 *   @0x2a5030 rfeia r6!
 *   @0x2a5034 .word 0xf00aa00c
 *   @0x2a5038 blx 0xa67940 <b2_toiTime+0x30e49c>
 *   @0x2a503c .word 0xf1bafa8a
 *   @0x2a5040 .word 0xd1080f00
 *   @0x2a5044 mov r0, r6
 *   @0x2a5048 stmvs r3!, {r2, r3, r6, r8, r9, r10, r11, sp, lr, pc} ^
 *   @0x2a504c cmp r0, r3
 *   @0x2a5050 str.w r10, [sp, #0x14]
 *   @0x2a5054 b 0x2a507a <zip_open+0x29a>
 *   @0x2a5058 and r2, r2, #0x40
 *   @0x2a505c uxth r2, r2
 *   @0x2a5060 beq.w 0x2a5194 <zip_open+0x3b4>
 *   @0x2a5064 blx 0xb6bf8 <__errno@plt>
 *   @0x2a5068 movs r1, #0x4
 *   @0x2a506c mov r0, r7
 *   @0x2a5070 qsub16mi pc, r0, r3
 *   @0x2a5074 blx 0xb655c <free@plt>
 *   @0x2a5078 b 0x2a512e <zip_open+0x34e>
 *   @0x2a507c add.w r9, sp, #0xa0
 *   @0x2a5080 mov.w r10, #0x0
 *   @0x2a5084 str r3, [r9, #-108]!
 *   @0x2a5088 ldr r3, [r4, #0x4]
 *   @0x2a508c bne 0x2a509e <zip_open+0x2be>
 *   @0x2a5090 cbz r3, 0x2a509e <zip_open+0x2be>
 *   @0x2a5094 add.w r1, r10, #0x10000
 *   @0x2a5098 mov r2, r7
 *   @0x2a509c stmdavs r0!, {r3, r4, r6, r8, r10, r11, r12, sp, lr, pc}
 *   @0x2a50a0 movs r2, #0x3c
 *   @0x2a50a4 mov r1, r6
 *   @0x2a50a8 strbmi r0, [r11], -r8, lsl #1
 *   @0x2a50ac mla r0, r2, r10, r0
 *   @0x2a50b0 ldr r2, [sp, #0x14]
 *   @0x2a50b4 stmdahs r0, {r0, r2, r3, r4, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2a50b8 bge 0x2a50d0 <zip_open+0x2f0>
 *   @0x2a50bc eor r10, r8, r4
 *   @0x2a50c0 movs r6, r2
 *   @0x2a50c4 strb r5, [r1, #0x7]
 *   @0x2a50c8 strb r0, [r5, #0x3]
 *   @0x2a50cc add r1, sp, #0xb8
 *   @0x2a50d0 ldr r3, [r4, #0x4]
 *   @0x2a50d4 ldrmi r0, [r10, #0xa01]
 *   @0x2a50d8 blt 0x2a5088 <zip_open+0x2a8>
 *   @0x2a50dc cmp.w r8, #0x0
 *   @0x2a50e0 beq 0x2a511a <zip_open+0x33a>
 *   @0x2a50e4 cmp r3, #0x0
 *   @0x2a50e8 mov r0, r6
 *   @0x2a50ec mov r2, r7
 *   @0x2a50f0 andls pc, r2, r6, lsl #28
 *   @0x2a50f4 mov r2, r7
 *   @0x2a50f8 mov r1, r4
 *   @0x2a50fc bls 0x364904 <_ZTS12CDS_Priority+0x695c>
 *   @0x2a5100 cmp r2, r0
 *   @0x2a5104 bge 0x2a5112 <zip_open+0x332>
 *   @0x2a5108 bl 0x2a3bf6 <_Z14_zip_cdir_freeP8zip_cdir>
 *   @0x2a510c str.w r9, [sp, #0x8]
 *   @0x2a5110 b 0x2a5136 <zip_open+0x356>
 *   @0x2a5114 bl 0x2a3bf6 <_Z14_zip_cdir_freeP8zip_cdir>
 *   @0x2a5118 b 0x2a512e <zip_open+0x34e>
 *   @0x2a511c lsls r3, r3, #0x1d
 *   @0x2a5120 mov r0, r6
 *   @0x2a5124 mov r2, r7
 *   @0x2a5128 andls pc, r2, r10, ror #27
 *   @0x2a512c b 0x2a5136 <zip_open+0x356>
 *   @0x2a5130 b 0x2a5136 <zip_open+0x356>
 *   @0x2a5134 strtmi r8, [r0], r8
 *   @0x2a5138 b 0x2a4f30 <zip_open+0x150>
 *   @0x2a513c blx 0xb655c <free@plt>
 *   @0x2a5140 ldr r2, [sp, #0x8]
 *   @0x2a5144 bge.w 0x2a4e84 <zip_open+0xa4>
 *   @0x2a5148 mov r0, r5
 *   @0x2a514c mov r2, r9
 *   @0x2a5150 strbmi pc, [r0], -r7, lsl #25
 *   @0x2a5154 bl 0x2a3bf6 <_Z14_zip_cdir_freeP8zip_cdir>
 *   @0x2a5158 b 0x2a4ec4 <zip_open+0xe4>
 *   @0x2a515c subvs r8, r6, r0, lsr #32
 *   @0x2a5160 movs r0, #0x14
 *   @0x2a5164 cmpmi r8, #4
 *   @0x2a5168 blx 0xb6544 <malloc@plt>
 *   @0x2a516c str r0, [r4, #0x34]
 *   @0x2a5170 cbz r5, 0x2a5176 <zip_open+0x396>
 *   @0x2a5174 str r3, [r5]
 *   @0x2a5178 bl 0x2a4884 <_Z9_zip_freeP3zip>
 *   @0x2a517c b 0x2a4eca <zip_open+0xea>
 *   @0x2a5180 strtmi r3, [r0], -r4
 *   @0x2a5184 cmp r9, r3
 *   @0x2a5188 .word 0xf000ae8f
 *   @0x2a518c .word 0xf109fb01
 *   @0x2a5190 ldrb r0, [r4, r1, lsl #18]!
 *   @0x2a5194 mov r0, r7
 *   @0x2a5198 b 0x2a506e <zip_open+0x28e>
 *   @0x2a519c pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §19/33 spVertexAttachment_computeWorldVertices1  0x28f64c  size 956  239 条（0x28f64c..0x28fa08）
 * @func 0x28f64c 0x28fa08  size 956  239 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spVertexAttachment_computeWorldVertices1+0x84
 * 字段偏移 top8: 0x4×10 / 0x8×8 / 0xc×6 / 0x2×5 / 0x14×3 / 0x10×2 / 0x1c×1 / 0x20×1
 * VFP 指令 70 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28f64c push {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x28f650 sub sp, sp, #24
 *   @0x28f654 ldr r6, [r0, #0x14]
 *   @0x28f658 ldr r4, [r3, #0x4]
 *   @0x28f65c ldr r0, [r0, #0x1c]
 *   @0x28f660 cmp r6, #0
 *   @0x28f664 ldr r9, [r3, #0x20]
 *   @0x28f668 ldr r3, [r3, #0x24]
 *   @0x28f66c ldr r10, [sp, #0x3c]
 *   @0x28f670 ldr r12, [r4, #0x4]
 *   @0x28f674 vldr s3, [r12, #88]
 *   @0x28f678 str r0, [sp, #0x8]
 *   @0x28f67c add r2, r2, r10
 *   @0x28f680 vldr s2, [r12, #92]
 *   @0x28f684 str r3, [sp, #0xc]
 *   @0x28f688 ldr r8, [sp, #0x38]
 *   @0x28f68c beq 0x28f95c <spVertexAttachment_computeWorldVertices1+0x310>
 *   @0x28f690 cmp r1, #0
 *   @0x28f694 movle r7, #0
 *   @0x28f698 movle r5, r7
 *   @0x28f69c movle r4, r7
 *   @0x28f6a0 ble 0x28f6d0 <spVertexAttachment_computeWorldVertices1+0x84>
 *   @0x28f6a4 mov r3, #0
 *   @0x28f6a8 mov r5, r3
 *   @0x28f6ac mov r4, r3
 *   @0x28f6b0 ldr r0, [r6, r4, lsl #2]
 *   @0x28f6b4 add r3, r3, #2
 *   @0x28f6b8 cmp r1, r3
 *   @0x28f6bc add r7, r0, #1
 *   @0x28f6c0 add r5, r5, r0
 *   @0x28f6c4 add r4, r4, r7
 *   @0x28f6c8 bgt 0x28f6b0 <spVertexAttachment_computeWorldVertices1+0x64>
 *   @0x28f6cc add r7, r5, r5, lsl #1
 *   @0x28f6d0 cmp r9, #0
 *   @0x28f6d4 ldr r12, [r12, #0x8]
 *   @0x28f6d8 bne 0x28f7e4 <spVertexAttachment_computeWorldVertices1+0x198>
 *   @0x28f6dc cmp r10, r2
 *   @0x28f6e0 bge 0x28f7d8 <spVertexAttachment_computeWorldVertices1+0x18c>
 *   @0x28f6e4 mvn r3, r10
 *   @0x28f6e8 add r3, r3, r2
 *   @0x28f6ec bic r3, r3, #1
 *   @0x28f6f0 add r2, r10, #1
 *   @0x28f6f4 add r10, r3, r10
 *   @0x28f6f8 add r3, r8, #12
 *   @0x28f6fc add r8, r8, r2, lsl #2
 *   @0x28f700 sub r2, r6, #4
 *   @0x28f704 add r11, r3, r10, lsl #2
 *   @0x28f708 str r2, [sp, #0x4]
 *   @0x28f70c ldr r5, [r6, r4, lsl #2]
 *   @0x28f710 add r9, r4, #1
 *   @0x28f714 mov r10, r4
 *   @0x28f718 add r1, r6, r4, lsl #2
 *   @0x28f71c add r5, r5, r9
 *   @0x28f720 cmp r9, r5
 *   @0x28f724 bge 0x28f94c <spVertexAttachment_computeWorldVertices1+0x300>
 *   @0x28f728 ldr r3, [sp, #0x4]
 *   @0x28f72c add r2, r7, #2
 *   @0x28f730 vmov.f32 s10, s2
 *   @0x28f734 str r4, [sp, #0xc]
 *   @0x28f738 add r0, r3, r5, lsl #2
 *   @0x28f73c ldr r3, [sp, #0x8]
 *   @0x28f740 add r2, r3, r2, lsl #2
 *   @0x28f744 vmov.f32 s9, s3
 *   @0x28f748 ldr r3, [r1, #0x4]!
 *   @0x28f74c vldr s11, [r2, #-4]
 *   @0x28f750 vldr s12, [r2, #-8]
 *   @0x28f754 mov r4, r2
 *   @0x28f758 cmp r1, r0
 *   @0x28f75c vldr s13, [r4]
 *   @0x28f760 ldr r3, [r12, r3, lsl #2]
 *   @0x28f764 vldr s14, [r3, #56]
 *   @0x28f768 vldr s15, [r3, #68]
 *   @0x28f76c vmul.f32 s14, s11, s14
 *   @0x28f770 vldr s5, [r3, #52]
 *   @0x28f774 vldr s6, [r3, #64]
 *   @0x28f778 vldr s7, [r3, #60]
 *   @0x28f77c vldr s8, [r3, #72]
 *   @0x28f780 add r2, r2, #12
 *   @0x28f784 vmul.f32 s15, s11, s15
 *   @0x28f788 vmla.f32 s14, s12, s5
 *   @0x28f78c vmla.f32 s15, s12, s6
 *   @0x28f790 vadd.f32 s14, s14, s7
 *   @0x28f794 vadd.f32 s15, s15, s8
 *   @0x28f798 vmla.f32 s9, s14, s13
 *   @0x28f79c vmla.f32 s10, s15, s13
 *   @0x28f7a0 bne 0x28f748 <spVertexAttachment_computeWorldVertices1+0xfc>
 *   @0x28f7a4 ldr r4, [sp, #0xc]
 *   @0x28f7a8 rsb r10, r10, r5
 *   @0x28f7ac sub r7, r7, #3
 *   @0x28f7b0 rsb r4, r4, r9
 *   @0x28f7b4 add r10, r10, r10, lsl #1
 *   @0x28f7b8 sub r4, r4, #1
 *   @0x28f7bc add r7, r7, r10
 *   @0x28f7c0 add r4, r5, r4
 *   @0x28f7c4 vmov r0, s10
 *   @0x28f7c8 vstr s9, [r8, #-4]
 *   @0x28f7cc str r0, [r8], #8
 *   @0x28f7d0 cmp r8, r11
 *   @0x28f7d4 bne 0x28f70c <spVertexAttachment_computeWorldVertices1+0xc0>
 *   @0x28f7d8 add sp, sp, #24
 *   @0x28f7dc pop {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x28f7e0 bx lr
 *   @0x28f7e4 cmp r10, r2
 *   @0x28f7e8 lsl r5, r5, #1
 *   @0x28f7ec str r5, [sp, #0x4]
 *   @0x28f7f0 bge 0x28f7d8 <spVertexAttachment_computeWorldVertices1+0x18c>
 *   @0x28f7f4 mvn r3, r10
 *   @0x28f7f8 add r9, r10, #1
 *   @0x28f7fc add r3, r3, r2
 *   @0x28f800 sub r1, r6, #4
 *   @0x28f804 bic r3, r3, #1
 *   @0x28f808 add r9, r8, r9, lsl #2
 *   @0x28f80c add r10, r3, r10
 *   @0x28f810 add r3, r8, #12
 *   @0x28f814 str r1, [sp, #0x14]
 *   @0x28f818 add r10, r3, r10, lsl #2
 *   @0x28f81c str r10, [sp, #0x10]
 *   @0x28f820 ldr r8, [r6, r4, lsl #2]
 *   @0x28f824 add r10, r4, #1
 *   @0x28f828 mov r11, r4
 *   @0x28f82c add r1, r6, r4, lsl #2
 *   @0x28f830 add r8, r8, r10
 *   @0x28f834 cmp r10, r8
 *   @0x28f838 bge 0x28f93c <spVertexAttachment_computeWorldVertices1+0x2f0>
 *   @0x28f83c ldr r2, [sp, #0x4]
 *   @0x28f840 vmov.f32 s10, s2
 *   @0x28f844 ldr r3, [sp, #0x14]
 *   @0x28f848 add r0, r2, #1
 *   @0x28f84c add r2, r7, #2
 *   @0x28f850 add r5, r3, r8, lsl #2
 *   @0x28f854 ldr r3, [sp, #0xc]
 *   @0x28f858 vmov.f32 s9, s3
 *   @0x28f85c str r4, [sp]
 *   @0x28f860 add r0, r3, r0, lsl #2
 *   @0x28f864 ldr r3, [sp, #0x8]
 *   @0x28f868 add r2, r3, r2, lsl #2
 *   @0x28f86c mov r4, r0
 *   @0x28f870 vldr s4, [r2, #-4]
 *   @0x28f874 vldr s11, [r4]
 *   @0x28f878 vadd.f32 s11, s4, s11
 *   @0x28f87c ldr r3, [r1, #0x4]!
 *   @0x28f880 vldr s15, [r0, #-4]
 *   @0x28f884 vldr s12, [r2, #-8]
 *   @0x28f888 mov r4, r2
 *   @0x28f88c cmp r1, r5
 *   @0x28f890 vldr s13, [r4]
 *   @0x28f894 ldr r3, [r12, r3, lsl #2]
 *   @0x28f898 vldr s14, [r3, #56]
 *   @0x28f89c vldr s5, [r3, #52]
 *   @0x28f8a0 vldr s6, [r3, #64]
 *   @0x28f8a4 vldr s7, [r3, #60]
 *   @0x28f8a8 vldr s8, [r3, #72]
 *   @0x28f8ac add r0, r0, #8
 *   @0x28f8b0 add r2, r2, #12
 *   @0x28f8b4 vadd.f32 s12, s12, s15
 *   @0x28f8b8 vldr s15, [r3, #68]
 *   @0x28f8bc vmul.f32 s14, s11, s14
 *   @0x28f8c0 vmul.f32 s15, s11, s15
 *   @0x28f8c4 vmla.f32 s14, s12, s5
 *   @0x28f8c8 vmla.f32 s15, s12, s6
 *   @0x28f8cc vadd.f32 s14, s14, s7
 *   @0x28f8d0 vadd.f32 s15, s15, s8
 *   @0x28f8d4 vmla.f32 s9, s14, s13
 *   @0x28f8d8 vmla.f32 s10, s15, s13
 *   @0x28f8dc bne 0x28f86c <spVertexAttachment_computeWorldVertices1+0x220>
 *   @0x28f8e0 ldr r4, [sp]
 *   @0x28f8e4 movw r3, #0xfffe
 *   @0x28f8e8 movt r3, #0x7fff
 *   @0x28f8ec ldr r0, [sp, #0x4]
 *   @0x28f8f0 rsb r3, r11, r3
 *   @0x28f8f4 rsb r11, r11, r8
 *   @0x28f8f8 rsb r4, r4, r10
 *   @0x28f8fc sub r7, r7, #3
 *   @0x28f900 sub r4, r4, #1
 *   @0x28f904 add r11, r11, r11, lsl #1
 *   @0x28f908 add r3, r8, r3
 *   @0x28f90c add r4, r8, r4
 *   @0x28f910 add r7, r7, r11
 *   @0x28f914 add r2, r0, #2
 *   @0x28f918 add r3, r2, r3, lsl #1
 *   @0x28f91c str r3, [sp, #0x4]
 *   @0x28f920 vmov r1, s10
 *   @0x28f924 vstr s9, [r9, #-4]
 *   @0x28f928 ldr r2, [sp, #0x10]
 *   @0x28f92c str r1, [r9], #8
 *   @0x28f930 cmp r9, r2
 *   @0x28f934 bne 0x28f820 <spVertexAttachment_computeWorldVertices1+0x1d4>
 *   @0x28f938 b 0x28f7d8 <spVertexAttachment_computeWorldVertices1+0x18c>
 *   @0x28f93c vmov.f32 s10, s2
 *   @0x28f940 mov r4, r10
 *   @0x28f944 vmov.f32 s9, s3
 *   @0x28f948 b 0x28f920 <spVertexAttachment_computeWorldVertices1+0x2d4>
 *   @0x28f94c vmov.f32 s10, s2
 *   @0x28f950 mov r4, r9
 *   @0x28f954 vmov.f32 s9, s3
 *   @0x28f958 b 0x28f7c4 <spVertexAttachment_computeWorldVertices1+0x178>
 *   @0x28f95c ldr r3, [sp, #0x8]
 *   @0x28f960 cmp r9, #0
 *   @0x28f964 ldr r0, [sp, #0xc]
 *   @0x28f968 vldr s14, [r4, #60]
 *   @0x28f96c vldr s15, [r4, #72]
 *   @0x28f970 vadd.f32 s3, s3, s14
 *   @0x28f974 movle r0, r3
 *   @0x28f978 cmp r10, r2
 *   @0x28f97c str r0, [sp, #0xc]
 *   @0x28f980 vadd.f32 s2, s2, s15
 *   @0x28f984 bge 0x28f7d8 <spVertexAttachment_computeWorldVertices1+0x18c>
 *   @0x28f988 mvn r3, r10
 *   @0x28f98c add r2, r3, r2
 *   @0x28f990 bic r2, r2, #1
 *   @0x28f994 add r3, r1, #1
 *   @0x28f998 add r2, r2, r1
 *   @0x28f99c add r10, r10, #1
 *   @0x28f9a0 add r3, r0, r3, lsl #2
 *   @0x28f9a4 add r2, r0, r2, lsl #2
 *   @0x28f9a8 add r8, r8, r10, lsl #2
 *   @0x28f9ac add r2, r2, #12
 *   @0x28f9b0 vldr s14, [r4, #56]
 *   @0x28f9b4 mov r0, r3
 *   @0x28f9b8 vldr s15, [r0]
 *   @0x28f9bc vmul.f32 s14, s15, s14
 *   @0x28f9c0 vldr s13, [r3, #-4]
 *   @0x28f9c4 vldr s12, [r4, #52]
 *   @0x28f9c8 add r3, r3, #8
 *   @0x28f9cc cmp r3, r2
 *   @0x28f9d0 vmla.f32 s14, s13, s12
 *   @0x28f9d4 vadd.f32 s14, s14, s3
 *   @0x28f9d8 vstr s14, [r8, #-4]
 *   @0x28f9dc vldr s14, [r4, #68]
 *   @0x28f9e0 vmul.f32 s15, s15, s14
 *   @0x28f9e4 vldr s14, [r4, #64]
 *   @0x28f9e8 vmla.f32 s15, s13, s14
 *   @0x28f9ec vadd.f32 s15, s15, s2
 *   @0x28f9f0 vmov r1, s15
 *   @0x28f9f4 str r1, [r8], #8
 *   @0x28f9f8 bne 0x28f9b0 <spVertexAttachment_computeWorldVertices1+0x364>
 *   @0x28f9fc add sp, sp, #24
 *   @0x28fa00 pop {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x28fa04 bx lr
 *
 * ══ §20/33 CGestureDoubleTap::Update(long long)  0x1d8a64  size 952  238 条（0x1d8a64..0x1d8e1c）
 * @func 0x1d8a64 0x1d8e1c  size 952  238 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1d8aac→0x3f5168, 0x1d8ad4→0x3f5130, 0x1d8aec→0x3ebdd8, 0x1d8b54→0x544aa8, 0x1d8c80→0x544a9c, 0x1d8d80→0x544a9c, 0x1d8dd4→0x3f5164
 * 调用序列: operator new(unsigned int)×3 / MemoryManager::Alloc(unsigned int, char const*, int, bool)×3 / ConvertGestureEventToGMEvent(int, bool)×2 / GetInstanceListWithEventType(int, int, float, float, int**, int*, bool)×2 / IO_Button_Down(int, int) / CalcDistInches(int, int) / CGesture::CGesture() / AddToDsMap(int, char*, double)
 * 字段偏移 top8: 0x8×16 / 0x4×12 / 0xc×6 / 0x44×5 / 0x40×5 / 0x28×4 / 0x3c×4 / 0x4c×2
 * VFP 指令 16 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d8a64 ldr r1, [r0]
 *   @0x1d8a68 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1d8a6c mov r6, r0
 *   @0x1d8a70 sub sp, sp, #20
 *   @0x1d8a74 ldr r1, [r1, #0x18]
 *   @0x1d8a78 mov r4, r2
 *   @0x1d8a7c mov r5, r3
 *   @0x1d8a80 blx r1
 *   @0x1d8a84 ldr r1, [r6, #0x28]
 *   @0x1d8a88 mov r0, #1
 *   @0x1d8a8c ldr r7, [pc, #0x35c]
 *   @0x1d8a90 bl 0x18c0b4 <_Z14IO_Button_Downii>
 *   @0x1d8a94 add r7, pc, r7
 *   @0x1d8a98 subs r9, r0, #0
 *   @0x1d8a9c beq 0x1d8ce0 <_ZN17CGestureDoubleTap6UpdateEx+0x27c>
 *   @0x1d8aa0 ldr r1, [r6, #0x4c]
 *   @0x1d8aa4 ldr r0, [r6, #0x48]
 *   @0x1d8aa8 bl 0x1d6708 <_Z14CalcDistInchesii>
 *   @0x1d8aac ldr r1, [pc, #0x340]
 *   @0x1d8ab0 ldrd r2, r3, [r6, #24]
 *   @0x1d8ab4 ldr r1, [r7, r1]
 *   @0x1d8ab8 subs r2, r4, r2
 *   @0x1d8abc sbc r3, r5, r3
 *   @0x1d8ac0 vmov s15, r0
 *   @0x1d8ac4 ldrd r0, r1, [r1]
 *   @0x1d8ac8 cmp r0, r2
 *   @0x1d8acc sbcs r12, r1, r3
 *   @0x1d8ad0 bge 0x1d8dd4 <_ZN17CGestureDoubleTap6UpdateEx+0x370>
 *   @0x1d8ad4 ldr r3, [pc, #0x31c]
 *   @0x1d8ad8 ldr r3, [r7, r3]
 *   @0x1d8adc ldrb r9, [r3]
 *   @0x1d8ae0 cmp r9, #0
 *   @0x1d8ae4 bne 0x1d8cd0 <_ZN17CGestureDoubleTap6UpdateEx+0x26c>
 *   @0x1d8ae8 mov r0, #96
 *   @0x1d8aec ldr r10, [pc, #0x308]
 *   @0x1d8af0 bl 0x27c524 <_Znwj>
 *   @0x1d8af4 mov r11, #3
 *   @0x1d8af8 mov r8, r0
 *   @0x1d8afc bl 0x1d7c0c <_ZN8CGestureC2Ev>
 *   @0x1d8b00 str r9, [r8, #0x44]
 *   @0x1d8b04 mvn r3, #0
 *   @0x1d8b08 ldr r1, [r6, #0x44]
 *   @0x1d8b0c mov r2, #0
 *   @0x1d8b10 str r9, [r8, #0x40]
 *   @0x1d8b14 mov r0, #12
 *   @0x1d8b18 ldr r12, [r6, #0x40]
 *   @0x1d8b1c str r3, [r8, #0x28]
 *   @0x1d8b20 str r2, [r8, #0x58]
 *   @0x1d8b24 mov r2, #143
 *   @0x1d8b28 ldr lr, [r6, #0x28]
 *   @0x1d8b2c str r9, [r8, #0x38]
 *   @0x1d8b30 str r9, [r8, #0x3c]
 *   @0x1d8b34 str r9, [r8, #0x48]
 *   @0x1d8b38 str r9, [r8, #0x4c]
 *   @0x1d8b3c str r3, [r8, #0x2c]
 *   @0x1d8b40 mov r3, #1
 *   @0x1d8b44 ldr r10, [r7, r10]
 *   @0x1d8b48 str r1, [r8, #0x34]
 *   @0x1d8b4c str r1, [r8, #0x44]
 *   @0x1d8b50 add r10, r10, #8
 *   @0x1d8b54 ldr r1, [pc, #0x2a4]
 *   @0x1d8b58 str lr, [r8, #0x28]
 *   @0x1d8b5c str r11, [r8, #0x8]
 *   @0x1d8b60 str r10, [r8]
 *   @0x1d8b64 str r9, [r8, #0x14]
 *   @0x1d8b68 strd r4, r5, [r8, #24]
 *   @0x1d8b6c strd r4, r5, [r8, #32]
 *   @0x1d8b70 str r12, [r8, #0x30]
 *   @0x1d8b74 str r12, [r8, #0x40]
 *   @0x1d8b78 ldr r10, [r7, r1]
 *   @0x1d8b7c ldr r1, [pc, #0x280]
 *   @0x1d8b80 ldr r12, [r10, #0x8]
 *   @0x1d8b84 add r1, pc, r1
 *   @0x1d8b88 add r12, r12, r3
 *   @0x1d8b8c str r12, [r10, #0x8]
 *   @0x1d8b90 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1d8b94 ldr r3, [r10, #0x4]
 *   @0x1d8b98 cmp r3, #0
 *   @0x1d8b9c str r8, [r0, #0x8]
 *   @0x1d8ba0 streq r0, [r10, #0x4]
 *   @0x1d8ba4 strne r0, [r3]
 *   @0x1d8ba8 streq r0, [r10]
 *   @0x1d8bac strne r3, [r0, #0x4]
 *   @0x1d8bb0 streq r3, [r0, #0x4]
 *   @0x1d8bb4 strne r0, [r10, #0x4]
 *   @0x1d8bb8 mvn r10, #0
 *   @0x1d8bbc streq r3, [r0]
 *   @0x1d8bc0 strne r9, [r0]
 *   @0x1d8bc4 mov r0, #16
 *   @0x1d8bc8 bl 0x27c524 <_Znwj>
 *   @0x1d8bcc ldr lr, [r6, #0x3c]
 *   @0x1d8bd0 ldr r12, [r6]
 *   @0x1d8bd4 mov r9, #0
 *   @0x1d8bd8 ldr r1, [r6, #0x40]
 *   @0x1d8bdc ldr r2, [r6, #0x44]
 *   @0x1d8be0 ldr r3, [r6, #0x38]
 *   @0x1d8be4 mov r8, r0
 *   @0x1d8be8 mov r0, r6
 *   @0x1d8bec str r9, [r8, #0x8]
 *   @0x1d8bf0 str r10, [r8, #0x4]
 *   @0x1d8bf4 str r9, [r8, #0xc]
 *   @0x1d8bf8 str r9, [r8]
 *   @0x1d8bfc str lr, [sp]
 *   @0x1d8c00 strd r4, r5, [sp, #8]
 *   @0x1d8c04 ldr r12, [r12, #0x1c]
 *   @0x1d8c08 blx r12
 *   @0x1d8c0c ldr r1, [pc, #0x1f4]
 *   @0x1d8c10 mov r2, #0
 *   @0x1d8c14 mov r3, #0
 *   @0x1d8c18 add r1, pc, r1
 *   @0x1d8c1c movt r3, #0x3ff0
 *   @0x1d8c20 str r0, [r8, #0x4]
 *   @0x1d8c24 bl 0x20bf40 <_Z10AddToDsMapiPcd>
 *   @0x1d8c28 mov r1, r9
 *   @0x1d8c2c ldr r0, [r8]
 *   @0x1d8c30 bl 0x1d6b44 <_Z28ConvertGestureEventToGMEventib>
 *   @0x1d8c34 ldr r2, [r6, #0x40]
 *   @0x1d8c38 ldr r3, [r6, #0x44]
 *   @0x1d8c3c add r12, r6, #12
 *   @0x1d8c40 str r9, [sp, #0x8]
 *   @0x1d8c44 vmov s15, r2
 *   @0x1d8c48 str r12, [sp]
 *   @0x1d8c4c vcvt.f32.s32 s15, s15
 *   @0x1d8c50 vmov r2, s15
 *   @0x1d8c54 vmov s15, r3
 *   @0x1d8c58 vcvt.f32.s32 s15, s15
 *   @0x1d8c5c vmov r3, s15
 *   @0x1d8c60 mov r1, r0
 *   @0x1d8c64 add r0, r6, #16
 *   @0x1d8c68 str r0, [sp, #0x4]
 *   @0x1d8c6c mov r0, #13
 *   @0x1d8c70 bl 0x1d68a0 <_Z28GetInstanceListWithEventTypeiiffPPiS_b>
 *   @0x1d8c74 ldr r3, [r6, #0xc]
 *   @0x1d8c78 ldr r12, [r6, #0x10]
 *   @0x1d8c7c mov r0, #12
 *   @0x1d8c80 ldr r1, [pc, #0x184]
 *   @0x1d8c84 mov r2, #143
 *   @0x1d8c88 str r3, [r8, #0x8]
 *   @0x1d8c8c mov r3, #1
 *   @0x1d8c90 str r12, [r8, #0xc]
 *   @0x1d8c94 ldr r4, [r7, r1]
 *   @0x1d8c98 ldr r1, [pc, #0x170]
 *   @0x1d8c9c ldr r12, [r4, #0x8]
 *   @0x1d8ca0 add r1, pc, r1
 *   @0x1d8ca4 add r12, r12, r3
 *   @0x1d8ca8 str r12, [r4, #0x8]
 *   @0x1d8cac bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1d8cb0 ldr r3, [r4, #0x4]
 *   @0x1d8cb4 cmp r3, r9
 *   @0x1d8cb8 str r8, [r0, #0x8]
 *   @0x1d8cbc beq 0x1d8dc0 <_ZN17CGestureDoubleTap6UpdateEx+0x35c>
 *   @0x1d8cc0 str r0, [r3]
 *   @0x1d8cc4 str r3, [r0, #0x4]
 *   @0x1d8cc8 str r0, [r4, #0x4]
 *   @0x1d8ccc str r9, [r0]
 *   @0x1d8cd0 mvn r3, #0
 *   @0x1d8cd4 str r3, [r6, #0x14]
 *   @0x1d8cd8 add sp, sp, #20
 *   @0x1d8cdc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1d8ce0 mov r0, #16
 *   @0x1d8ce4 mov r10, #1
 *   @0x1d8ce8 bl 0x27c524 <_Znwj>
 *   @0x1d8cec ldr lr, [r6, #0x3c]
 *   @0x1d8cf0 ldr r12, [r6]
 *   @0x1d8cf4 add r1, r6, #48
 *   @0x1d8cf8 mvn r11, #0
 *   @0x1d8cfc ldm r1, {r1, r2, r3}
 *   @0x1d8d00 mov r8, r0
 *   @0x1d8d04 mov r0, r6
 *   @0x1d8d08 str r9, [r8, #0x8]
 *   @0x1d8d0c str r9, [r8, #0xc]
 *   @0x1d8d10 stm r8, {r10, r11}
 *   @0x1d8d14 str lr, [sp]
 *   @0x1d8d18 strd r4, r5, [sp, #8]
 *   @0x1d8d1c ldr r12, [r12, #0x1c]
 *   @0x1d8d20 blx r12
 *   @0x1d8d24 mov r1, r9
 *   @0x1d8d28 str r0, [r8, #0x4]
 *   @0x1d8d2c ldr r0, [r8]
 *   @0x1d8d30 bl 0x1d6b44 <_Z28ConvertGestureEventToGMEventib>
 *   @0x1d8d34 ldr r2, [r6, #0x30]
 *   @0x1d8d38 ldr r3, [r6, #0x34]
 *   @0x1d8d3c add r12, r6, #12
 *   @0x1d8d40 str r9, [sp, #0x8]
 *   @0x1d8d44 vmov s15, r2
 *   @0x1d8d48 str r12, [sp]
 *   @0x1d8d4c vcvt.f32.s32 s15, s15
 *   @0x1d8d50 vmov r2, s15
 *   @0x1d8d54 vmov s15, r3
 *   @0x1d8d58 vcvt.f32.s32 s15, s15
 *   @0x1d8d5c vmov r3, s15
 *   @0x1d8d60 mov r1, r0
 *   @0x1d8d64 add r0, r6, #16
 *   @0x1d8d68 str r0, [sp, #0x4]
 *   @0x1d8d6c mov r0, #13
 *   @0x1d8d70 bl 0x1d68a0 <_Z28GetInstanceListWithEventTypeiiffPPiS_b>
 *   @0x1d8d74 ldr r2, [r6, #0xc]
 *   @0x1d8d78 ldr r12, [r6, #0x10]
 *   @0x1d8d7c mov r3, r10
 *   @0x1d8d80 ldr r1, [pc, #0x84]
 *   @0x1d8d84 mov r0, #12
 *   @0x1d8d88 str r2, [r8, #0x8]
 *   @0x1d8d8c mov r2, #143
 *   @0x1d8d90 str r12, [r8, #0xc]
 *   @0x1d8d94 ldr r4, [r7, r1]
 *   @0x1d8d98 ldr r1, [pc, #0x74]
 *   @0x1d8d9c ldr r12, [r4, #0x8]
 *   @0x1d8da0 add r1, pc, r1
 *   @0x1d8da4 add r12, r12, r10
 *   @0x1d8da8 str r12, [r4, #0x8]
 *   @0x1d8dac bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1d8db0 ldr r3, [r4, #0x4]
 *   @0x1d8db4 cmp r3, #0
 *   @0x1d8db8 str r8, [r0, #0x8]
 *   @0x1d8dbc bne 0x1d8cc0 <_ZN17CGestureDoubleTap6UpdateEx+0x25c>
 *   @0x1d8dc0 str r0, [r4, #0x4]
 *   @0x1d8dc4 str r0, [r4]
 *   @0x1d8dc8 str r3, [r0, #0x4]
 *   @0x1d8dcc str r3, [r0]
 *   @0x1d8dd0 b 0x1d8cd0 <_ZN17CGestureDoubleTap6UpdateEx+0x26c>
 *   @0x1d8dd4 ldr r3, [pc, #0x3c]
 *   @0x1d8dd8 ldr r3, [r7, r3]
 *   @0x1d8ddc vldr s14, [r3]
 *   @0x1d8de0 vcmpe.f32 s15, s14
 *   @0x1d8de4 vmrs APSR_nzcv, fpscr
 *   @0x1d8de8 bgt 0x1d8ad4 <_ZN17CGestureDoubleTap6UpdateEx+0x70>
 *   @0x1d8dec b 0x1d8cd8 <_ZN17CGestureDoubleTap6UpdateEx+0x274>
 *   @0x1d8df0 .word 0x002191bc
 *   @0x1d8df4 .word 0xffffef74
 *   @0x1d8df8 .word 0xffffef9c
 *   @0x1d8dfc .word 0xffffefc8
 *   @0x1d8e00 .word 0xffffefc4
 *   @0x1d8e04 andseq r4, r7, r12, lsr #5
 *   @0x1d8e08 andseq r8, r7, r4, asr r5
 *   @0x1d8e0c .word 0xffffefb0
 *   @0x1d8e10 mulseq r7, r0, r1
 *   @0x1d8e14 mulseq r7, r0, r0
 *   @0x1d8e18 .word 0xffffef78
 *
 * ══ §21/33 YYFTGlyphCache::GetLRUSlot(YYGlyph2*, int, bool)  0xf68c8  size 944  236 条（0xf68c8..0xf6c78）
 * @func 0xf68c8 0xf6c78  size 944  236 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYFTGlyphCache::GetLRUSlot(YYGlyph2*, int, bool)+0x104 / YYFTGlyphCache::GetLRUSlot(YYGlyph2*, int, bool)+0xf4 / FT_Get_Char_Index / FT_Load_Glyph / FT_Render_Glyph / Graphics::UpdateRegion(void*, int, int, int, int) / Graphics::Flush()
 * 字段偏移 top8: 0x50×8 / 0x8×7 / 0x4×6 / 0x14×5 / 0xc×5 / 0x-1×5 / 0x2×4 / 0x18×4
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf68c8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xf68cc mov r4, r0
 *   @0xf68d0 ldm r0, {r0, r5}
 *   @0xf68d4 mov r7, r3
 *   @0xf68d8 mov r12, #0
 *   @0xf68dc sub sp, sp, #20
 *   @0xf68e0 ldr r3, [r5, #0x8]
 *   @0xf68e4 ldr lr, [r5, #0x4]
 *   @0xf68e8 cmp r3, r12
 *   @0xf68ec str lr, [r4, #0x4]
 *   @0xf68f0 str r12, [lr]
 *   @0xf68f4 stm r5, {r0, r12}
 *   @0xf68f8 str r5, [r0, #0x4]
 *   @0xf68fc str r5, [r4]
 *   @0xf6900 beq 0xf691c <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x54>
 *   @0xf6904 ldr r0, [r5, #0x14]
 *   @0xf6908 cmp r0, r2
 *   @0xf690c beq 0xf6c60 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x398>
 *   @0xf6910 mvn r2, #0
 *   @0xf6914 strh r2, [r3, #2]
 *   @0xf6918 strh r2, [r3, #4]
 *   @0xf691c ldr r3, [r4, #0x8]
 *   @0xf6920 ldr r2, [r5, #0xc]
 *   @0xf6924 ldr r0, [r5, #0x10]
 *   @0xf6928 ldr r12, [r3]
 *   @0xf692c str r1, [r5, #0x8]
 *   @0xf6930 sub r12, r12, #6
 *   @0xf6934 strh r2, [r1, #2]
 *   @0xf6938 cmp r12, #5
 *   @0xf693c strh r0, [r1, #4]
 *   @0xf6940 movhi lr, #1
 *   @0xf6944 ldrls lr, [pc, #0x328]
 *   @0xf6948 addls lr, pc, lr
 *   @0xf694c ldrls lr, [lr, r12, lsl #2]
 *   @0xf6950 ldr r6, [r3, #0x4]
 *   @0xf6954 lsl r12, r2, #2
 *   @0xf6958 ldr r2, [r4, #0x1c]
 *   @0xf695c ldr r9, [r3, #0x28]
 *   @0xf6960 mul r6, r6, lr
 *   @0xf6964 cmp r2, #0
 *   @0xf6968 mla r0, r6, r0, r12
 *   @0xf696c add r10, r9, r0
 *   @0xf6970 ble 0xf69cc <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x104>
 *   @0xf6974 ldr r3, [r4, #0x18]
 *   @0xf6978 mov r8, #0
 *   @0xf697c mov lr, r8
 *   @0xf6980 mvn r12, #0
 *   @0xf6984 cmp r3, #0
 *   @0xf6988 ble 0xf69bc <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0xf4>
 *   @0xf698c mov r2, r10
 *   @0xf6990 mov r0, #0
 *   @0xf6994 strb r12, [r2]
 *   @0xf6998 add r0, r0, #1
 *   @0xf699c strb r12, [r2, #0x1]
 *   @0xf69a0 add r2, r2, #4
 *   @0xf69a4 strb r12, [r2, #-0x2]
 *   @0xf69a8 strb lr, [r2, #-0x1]
 *   @0xf69ac ldr r3, [r4, #0x18]
 *   @0xf69b0 cmp r3, r0
 *   @0xf69b4 bgt 0xf6994 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0xcc>
 *   @0xf69b8 ldr r2, [r4, #0x1c]
 *   @0xf69bc add r8, r8, #1
 *   @0xf69c0 add r10, r10, r6
 *   @0xf69c4 cmp r2, r8
 *   @0xf69c8 bgt 0xf6984 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0xbc>
 *   @0xf69cc ldrh r1, [r1]
 *   @0xf69d0 ldr r0, [r4, #0x14]
 *   @0xf69d4 blx 0x2e5960 <FT_Get_Char_Index>
 *   @0xf69d8 mov r2, #0
 *   @0xf69dc mov r1, r0
 *   @0xf69e0 ldr r0, [r4, #0x14]
 *   @0xf69e4 blx 0x2e7564 <FT_Load_Glyph>
 *   @0xf69e8 cmp r0, #0
 *   @0xf69ec bne 0xf6b10 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x248>
 *   @0xf69f0 ldr r3, [r4, #0x14]
 *   @0xf69f4 cmp r7, #0
 *   @0xf69f8 moveq r1, #2
 *   @0xf69fc movne r1, #0
 *   @0xf6a00 ldr r0, [r3, #0x54]
 *   @0xf6a04 blx 0x2e5ed8 <FT_Render_Glyph>
 *   @0xf6a08 subs r8, r0, #0
 *   @0xf6a0c bne 0xf6b10 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x248>
 *   @0xf6a10 ldr r3, [r4, #0x14]
 *   @0xf6a14 ldr r1, [r5, #0xc]
 *   @0xf6a18 ldr r2, [r5, #0x10]
 *   @0xf6a1c ldr r12, [r3, #0x54]
 *   @0xf6a20 ldr lr, [r3, #0x58]
 *   @0xf6a24 lsl r3, r1, #2
 *   @0xf6a28 ldr r0, [r12, #0x24]
 *   @0xf6a2c ldr r7, [lr, #0x18]
 *   @0xf6a30 ldr lr, [r12, #0x4c]
 *   @0xf6a34 rsb r0, r0, r7
 *   @0xf6a38 ldr r10, [r12, #0x54]
 *   @0xf6a3c add r0, r0, #63
 *   @0xf6a40 cmp lr, #0
 *   @0xf6a44 ldr r7, [r12, #0x58]
 *   @0xf6a48 add r0, r2, r0, asr #6
 *   @0xf6a4c mla r3, r6, r0, r3
 *   @0xf6a50 add r9, r9, r3
 *   @0xf6a54 beq 0xf6b18 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x250>
 *   @0xf6a58 str r5, [sp, #0xc]
 *   @0xf6a5c mvn r3, #0
 *   @0xf6a60 mov r5, r10
 *   @0xf6a64 ldrb r2, [r12, #0x5e]
 *   @0xf6a68 sub r2, r2, #1
 *   @0xf6a6c cmp r2, #5
 *   @0xf6a70 addls pc, pc, r2, lsl #2
 *   @0xf6a74 b 0xf6af8 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x230>
 *   @0xf6a78 b 0xf6a90 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x1c8>
 *   @0xf6a7c b 0xf6c20 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x358>
 *   @0xf6a80 b 0xf6bac <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x2e4>
 *   @0xf6a84 b 0xf6b38 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x270>
 *   @0xf6a88 b 0xf6c20 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x358>
 *   @0xf6a8c b 0xf6c20 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x358>
 *   @0xf6a90 ldr r2, [r12, #0x50]
 *   @0xf6a94 cmp r2, #0
 *   @0xf6a98 beq 0xf6af8 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x230>
 *   @0xf6a9c mov r2, r9
 *   @0xf6aa0 mov lr, r7
 *   @0xf6aa4 mov r0, #0
 *   @0xf6aa8 mov r1, #128
 *   @0xf6aac b 0xf6abc <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x1f4>
 *   @0xf6ab0 cmp r1, #0
 *   @0xf6ab4 addeq lr, lr, #1
 *   @0xf6ab8 moveq r1, #128
 *   @0xf6abc ldrb r10, [lr]
 *   @0xf6ac0 add r0, r0, #1
 *   @0xf6ac4 strb r3, [r2]
 *   @0xf6ac8 add r2, r2, #4
 *   @0xf6acc tst r10, r1
 *   @0xf6ad0 strb r3, [r2, #-0x3]
 *   @0xf6ad4 strb r3, [r2, #-0x2]
 *   @0xf6ad8 lsr r1, r1, #1
 *   @0xf6adc moveq r10, #0
 *   @0xf6ae0 mvnne r10, #0
 *   @0xf6ae4 strb r10, [r2, #-0x1]
 *   @0xf6ae8 ldr r10, [r12, #0x50]
 *   @0xf6aec cmp r10, r0
 *   @0xf6af0 bhi 0xf6ab0 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x1e8>
 *   @0xf6af4 ldr lr, [r12, #0x4c]
 *   @0xf6af8 add r8, r8, #1
 *   @0xf6afc add r9, r9, r6
 *   @0xf6b00 cmp lr, r8
 *   @0xf6b04 add r7, r7, r5
 *   @0xf6b08 bhi 0xf6a64 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x19c>
 *   @0xf6b0c ldr r5, [sp, #0xc]
 *   @0xf6b10 ldr r1, [r5, #0xc]
 *   @0xf6b14 ldr r2, [r5, #0x10]
 *   @0xf6b18 ldr r12, [r4, #0x1c]
 *   @0xf6b1c ldr r0, [r4, #0x8]
 *   @0xf6b20 ldr r3, [r4, #0x18]
 *   @0xf6b24 str r12, [sp]
 *   @0xf6b28 bl 0x183240 <_ZN8Graphics12UpdateRegionEPviiii>
 *   @0xf6b2c mov r0, r5
 *   @0xf6b30 add sp, sp, #20
 *   @0xf6b34 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xf6b38 ldr r2, [r12, #0x50]
 *   @0xf6b3c cmp r2, #0
 *   @0xf6b40 beq 0xf6af8 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x230>
 *   @0xf6b44 mov r2, r9
 *   @0xf6b48 mov lr, r7
 *   @0xf6b4c mov r0, #0
 *   @0xf6b50 mov r1, #240
 *   @0xf6b54 b 0xf6b64 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x29c>
 *   @0xf6b58 cmp r1, #0
 *   @0xf6b5c addeq lr, lr, #1
 *   @0xf6b60 moveq r1, #240
 *   @0xf6b64 ldrb r10, [lr]
 *   @0xf6b68 tst r0, #1
 *   @0xf6b6c strb r3, [r2]
 *   @0xf6b70 add r0, r0, #1
 *   @0xf6b74 and r10, r10, r1
 *   @0xf6b78 movne r11, #0
 *   @0xf6b7c moveq r11, #4
 *   @0xf6b80 strb r3, [r2, #0x1]
 *   @0xf6b84 lsr r1, r1, #4
 *   @0xf6b88 asr r10, r10, r11
 *   @0xf6b8c strb r3, [r2, #0x2]
 *   @0xf6b90 add r2, r2, #4
 *   @0xf6b94 rsb r10, r10, r10, lsl #3
 *   @0xf6b98 strb r10, [r2, #-0x1]
 *   @0xf6b9c ldr r10, [r12, #0x50]
 *   @0xf6ba0 cmp r10, r0
 *   @0xf6ba4 bhi 0xf6b58 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x290>
 *   @0xf6ba8 b 0xf6af4 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x22c>
 *   @0xf6bac ldr r2, [r12, #0x50]
 *   @0xf6bb0 cmp r2, #0
 *   @0xf6bb4 beq 0xf6af8 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x230>
 *   @0xf6bb8 mov r2, r9
 *   @0xf6bbc mov lr, r7
 *   @0xf6bc0 mov r0, #0
 *   @0xf6bc4 mov r1, #192
 *   @0xf6bc8 b 0xf6bd8 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x310>
 *   @0xf6bcc cmp r1, #0
 *   @0xf6bd0 addeq lr, lr, #1
 *   @0xf6bd4 moveq r1, #192
 *   @0xf6bd8 ldrb r11, [lr]
 *   @0xf6bdc mvn r10, r0
 *   @0xf6be0 and r10, r10, #3
 *   @0xf6be4 strb r3, [r2]
 *   @0xf6be8 and r11, r11, r1
 *   @0xf6bec strb r3, [r2, #0x1]
 *   @0xf6bf0 lsl r10, r10, #1
 *   @0xf6bf4 strb r3, [r2, #0x2]
 *   @0xf6bf8 asr r10, r11, r10
 *   @0xf6bfc add r0, r0, #1
 *   @0xf6c00 lsr r1, r1, #2
 *   @0xf6c04 add r2, r2, #4
 *   @0xf6c08 rsb r10, r10, r10, lsl #6
 *   @0xf6c0c strb r10, [r2, #-0x1]
 *   @0xf6c10 ldr r10, [r12, #0x50]
 *   @0xf6c14 cmp r10, r0
 *   @0xf6c18 bhi 0xf6bcc <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x304>
 *   @0xf6c1c b 0xf6af4 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x22c>
 *   @0xf6c20 ldr r2, [r12, #0x50]
 *   @0xf6c24 cmp r2, #0
 *   @0xf6c28 movne r1, r7
 *   @0xf6c2c movne r2, r9
 *   @0xf6c30 beq 0xf6af8 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x230>
 *   @0xf6c34 ldrb lr, [r1], #1
 *   @0xf6c38 add r2, r2, #4
 *   @0xf6c3c strb r3, [r2, #-0x4]
 *   @0xf6c40 strb r3, [r2, #-0x3]
 *   @0xf6c44 rsb r0, r7, r1
 *   @0xf6c48 strb lr, [r2, #-0x1]
 *   @0xf6c4c strb r3, [r2, #-0x2]
 *   @0xf6c50 ldr lr, [r12, #0x50]
 *   @0xf6c54 cmp lr, r0
 *   @0xf6c58 bhi 0xf6c34 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x36c>
 *   @0xf6c5c b 0xf6af4 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x22c>
 *   @0xf6c60 str r1, [sp, #0x8]
 *   @0xf6c64 bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0xf6c68 ldr r3, [r5, #0x8]
 *   @0xf6c6c ldr r1, [sp, #0x8]
 *   @0xf6c70 b 0xf6910 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x48>
 *   @0xf6c74 .word 0x00265fd0
 *
 * ══ §22/33 anon_1904c0  0x1904c0  size 944  236 条（0x1904c0..0x190870）
 * @func 0x1904c0 0x190870  size 944  236 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv×13 / _JNIEnv::CallStaticObjectMethod(_jclass*, _jmethodID*, ...)×3 / GMGamePad::SetDeviceId(char const*)×2 / 0xb65bc×2 / anon_190490+0x350 / _JNIEnv::CallStaticBooleanMethod(_jclass*, _jmethodID*, ...) / SetupGMLMappings(int) / GMGamePad::SetConnected(bool)
 * 字段偏移 top8: 0x-50×11 / 0x-30×4 / 0x-34×3 / 0x314×3 / 0xc×3 / 0x-28×2 / 0x-48×2 / 0x-4c×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1904c0 ldr r3, [r12]
 *   @0x1904c4 tst r2, #2
 *   @0x1904c8 str r3, [r11, #-0x28]
 *   @0x1904cc beq 0x1907e0 <_Z16SetupGMLMappingsi+0x60c>
 *   @0x1904d0 ldr r3, [pc, #0x374]
 *   @0x1904d4 ldr r3, [r7, r3]
 *   @0x1904d8 ldr r3, [r3]
 *   @0x1904dc cmp r3, #0
 *   @0x1904e0 str r3, [r11, #-0x34]
 *   @0x1904e4 ble 0x1907e0 <_Z16SetupGMLMappingsi+0x60c>
 *   @0x1904e8 ldr r12, [pc, #0x360]
 *   @0x1904ec mov r4, #0
 *   @0x1904f0 ldr r8, [pc, #0x35c]
 *   @0x1904f4 add r12, pc, r12
 *   @0x1904f8 str r12, [r11, #-0x48]
 *   @0x1904fc ldr r12, [pc, #0x354]
 *   @0x190500 add r8, pc, r8
 *   @0x190504 add r12, pc, r12
 *   @0x190508 str r12, [r11, #-0x4c]
 *   @0x19050c ldr r12, [pc, #0x348]
 *   @0x190510 add r12, pc, r12
 *   @0x190514 str r12, [r11, #-0x3c]
 *   @0x190518 ldr r12, [pc, #0x340]
 *   @0x19051c add r12, pc, r12
 *   @0x190520 str r12, [r11, #-0x40]
 *   @0x190524 ldr r12, [pc, #0x338]
 *   @0x190528 add r12, pc, r12
 *   @0x19052c str r12, [r11, #-0x44]
 *   @0x190530 ldr r12, [r11, #-0x34]
 *   @0x190534 add r4, r4, #1
 *   @0x190538 cmp r4, r12
 *   @0x19053c beq 0x1907e0 <_Z16SetupGMLMappingsi+0x60c>
 *   @0x190540 cmp r4, #0
 *   @0x190544 beq 0x190530 <_Z16SetupGMLMappingsi+0x35c>
 *   @0x190548 bl 0x290274 <getJNIEnv>
 *   @0x19054c ldr r1, [pc, #0x314]
 *   @0x190550 mov r3, r4
 *   @0x190554 ldr r2, [r8, #0x8]
 *   @0x190558 lsl r9, r4, #2
 *   @0x19055c ldr r1, [r7, r1]
 *   @0x190560 str r1, [r11, #-0x30]
 *   @0x190564 ldr r1, [r1]
 *   @0x190568 bl 0x15e0b0 <_ZN7_JNIEnv23CallStaticBooleanMethodEP7_jclassP10_jmethodIDz>
 *   @0x19056c ldr r3, [pc, #0x2f8]
 *   @0x190570 ldr r12, [r7, r3]
 *   @0x190574 ldr r3, [r12]
 *   @0x190578 ldr r5, [r3, r4, lsl #2]
 *   @0x19057c cmp r5, #0
 *   @0x190580 mov r6, r0
 *   @0x190584 beq 0x190530 <_Z16SetupGMLMappingsi+0x35c>
 *   @0x190588 ldrb r3, [r5]
 *   @0x19058c cmp r3, r0
 *   @0x190590 beq 0x190668 <_Z16SetupGMLMappingsi+0x494>
 *   @0x190594 cmp r0, #0
 *   @0x190598 beq 0x1907fc <_Z16SetupGMLMappingsi+0x628>
 *   @0x19059c ldr r0, [pc, #0x2cc]
 *   @0x1905a0 mov r2, r4
 *   @0x1905a4 ldr r1, [r11, #-0x44]
 *   @0x1905a8 add r3, r5, #44
 *   @0x1905ac ldr r0, [r7, r0]
 *   @0x1905b0 ldr r0, [r0]
 *   @0x1905b4 ldr lr, [r0]
 *   @0x1905b8 ldr r10, [lr, #0xc]
 *   @0x1905bc str r12, [r11, #-0x50]
 *   @0x1905c0 blx r10
 *   @0x1905c4 mov r0, r4
 *   @0x1905c8 bl 0x1901d4 <_Z16SetupGMLMappingsi>
 *   @0x1905cc bl 0x290274 <getJNIEnv>
 *   @0x1905d0 ldr r3, [r11, #-0x30]
 *   @0x1905d4 ldr r2, [r8, #0xc]
 *   @0x1905d8 ldr r1, [r3]
 *   @0x1905dc mov r3, r4
 *   @0x1905e0 bl 0xf2840 <_ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz>
 *   @0x1905e4 mov r10, r0
 *   @0x1905e8 bl 0x290274 <getJNIEnv>
 *   @0x1905ec mov r1, r10
 *   @0x1905f0 mov r2, #0
 *   @0x1905f4 ldr r3, [r0]
 *   @0x1905f8 ldr r3, [r3, #0x2a4]
 *   @0x1905fc blx r3
 *   @0x190600 ldr r12, [r11, #-0x50]
 *   @0x190604 ldr r3, [r12]
 *   @0x190608 mov r2, r0
 *   @0x19060c mov r1, r0
 *   @0x190610 ldr r0, [r3, r9]
 *   @0x190614 str r2, [r11, #-0x50]
 *   @0x190618 bl 0x18e944 <_ZN9GMGamePad11SetDeviceIdEPKc>
 *   @0x19061c ldr r2, [r11, #-0x50]
 *   @0x190620 cmp r2, #0
 *   @0x190624 cmpne r10, #0
 *   @0x190628 beq 0x190658 <_Z16SetupGMLMappingsi+0x484>
 *   @0x19062c bl 0x290274 <getJNIEnv>
 *   @0x190630 mov r1, r10
 *   @0x190634 ldr r2, [r11, #-0x50]
 *   @0x190638 ldr r3, [r0]
 *   @0x19063c ldr r3, [r3, #0x2a8]
 *   @0x190640 blx r3
 *   @0x190644 bl 0x290274 <getJNIEnv>
 *   @0x190648 mov r1, r10
 *   @0x19064c ldr r3, [r0]
 *   @0x190650 ldr r3, [r3, #0x5c]
 *   @0x190654 blx r3
 *   @0x190658 adds r1, r6, #0
 *   @0x19065c mov r0, r5
 *   @0x190660 movne r1, #1
 *   @0x190664 bl 0x18e7f4 <_ZN9GMGamePad12SetConnectedEb>
 *   @0x190668 cmp r6, #0
 *   @0x19066c beq 0x190530 <_Z16SetupGMLMappingsi+0x35c>
 *   @0x190670 bl 0x290274 <getJNIEnv>
 *   @0x190674 ldr r12, [r11, #-0x30]
 *   @0x190678 mov r3, r4
 *   @0x19067c ldr r1, [r12]
 *   @0x190680 ldr r12, [r11, #-0x48]
 *   @0x190684 ldr r2, [r12, #0x10]
 *   @0x190688 bl 0xf2840 <_ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz>
 *   @0x19068c subs r6, r0, #0
 *   @0x190690 beq 0x190834 <_Z16SetupGMLMappingsi+0x660>
 *   @0x190694 bl 0x290274 <getJNIEnv>
 *   @0x190698 mov r1, r6
 *   @0x19069c ldr r3, [r0]
 *   @0x1906a0 ldr r3, [r3, #0x2ac]
 *   @0x1906a4 blx r3
 *   @0x1906a8 cmp r0, #0
 *   @0x1906ac ble 0x190834 <_Z16SetupGMLMappingsi+0x660>
 *   @0x1906b0 lsl r3, r0, #2
 *   @0x1906b4 str r3, [r11, #-0x50]
 *   @0x1906b8 add r2, r3, #14
 *   @0x1906bc bic r2, r2, #7
 *   @0x1906c0 sub sp, sp, r2
 *   @0x1906c4 bl 0x290274 <getJNIEnv>
 *   @0x1906c8 mov r1, r6
 *   @0x1906cc mov r2, #0
 *   @0x1906d0 mov r9, sp
 *   @0x1906d4 ldr r12, [r0]
 *   @0x1906d8 ldr r12, [r12, #0x2f4]
 *   @0x1906dc blx r12
 *   @0x1906e0 ldr r3, [r11, #-0x50]
 *   @0x1906e4 mov r2, r3
 *   @0x1906e8 mov r10, r0
 *   @0x1906ec mov r0, sp
 *   @0x1906f0 mov r1, r10
 *   @0x1906f4 bl 0xb65bc <memcpy@plt>
 *   @0x1906f8 bl 0x290274 <getJNIEnv>
 *   @0x1906fc mov r2, r10
 *   @0x190700 mov r1, r6
 *   @0x190704 mov r3, #0
 *   @0x190708 ldr r12, [r0]
 *   @0x19070c ldr r12, [r12, #0x314]
 *   @0x190710 blx r12
 *   @0x190714 bl 0x290274 <getJNIEnv>
 *   @0x190718 ldr r12, [r11, #-0x30]
 *   @0x19071c mov r3, r4
 *   @0x190720 ldr r1, [r12]
 *   @0x190724 ldr r12, [r11, #-0x4c]
 *   @0x190728 ldr r2, [r12, #0x14]
 *   @0x19072c bl 0xf2840 <_ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz>
 *   @0x190730 subs r6, r0, #0
 *   @0x190734 beq 0x19082c <_Z16SetupGMLMappingsi+0x658>
 *   @0x190738 bl 0x290274 <getJNIEnv>
 *   @0x19073c mov r1, r6
 *   @0x190740 ldr r3, [r0]
 *   @0x190744 ldr r3, [r3, #0x2ac]
 *   @0x190748 blx r3
 *   @0x19074c cmp r0, #0
 *   @0x190750 ble 0x19082c <_Z16SetupGMLMappingsi+0x658>
 *   @0x190754 lsl r12, r0, #2
 *   @0x190758 str r12, [r11, #-0x50]
 *   @0x19075c add r3, r12, #14
 *   @0x190760 bic r3, r3, #7
 *   @0x190764 sub sp, sp, r3
 *   @0x190768 bl 0x290274 <getJNIEnv>
 *   @0x19076c mov r1, r6
 *   @0x190770 mov r2, #0
 *   @0x190774 mov r10, sp
 *   @0x190778 ldr r3, [r0]
 *   @0x19077c ldr r3, [r3, #0x2f4]
 *   @0x190780 blx r3
 *   @0x190784 ldr r12, [r11, #-0x50]
 *   @0x190788 mov r2, r12
 *   @0x19078c mov r3, r0
 *   @0x190790 mov r0, sp
 *   @0x190794 mov r1, r3
 *   @0x190798 str r3, [r11, #-0x50]
 *   @0x19079c bl 0xb65bc <memcpy@plt>
 *   @0x1907a0 bl 0x290274 <getJNIEnv>
 *   @0x1907a4 ldr r3, [r11, #-0x50]
 *   @0x1907a8 mov r1, r6
 *   @0x1907ac mov r2, r3
 *   @0x1907b0 mov r3, #0
 *   @0x1907b4 ldr r12, [r0]
 *   @0x1907b8 ldr r12, [r12, #0x314]
 *   @0x1907bc blx r12
 *   @0x1907c0 mov r0, r5
 *   @0x1907c4 mov r1, r9
 *   @0x1907c8 mov r2, r10
 *   @0x1907cc add r4, r4, #1
 *   @0x1907d0 bl 0x18ee74 <_ZN9GMGamePad6UpdateEPfS0_>
 *   @0x1907d4 ldr r12, [r11, #-0x34]
 *   @0x1907d8 cmp r4, r12
 *   @0x1907dc bne 0x190540 <_Z16SetupGMLMappingsi+0x36c>
 *   @0x1907e0 ldr r12, [r11, #-0x38]
 *   @0x1907e4 ldr r2, [r11, #-0x28]
 *   @0x1907e8 ldr r3, [r12]
 *   @0x1907ec cmp r2, r3
 *   @0x1907f0 bne 0x19083c <_Z16SetupGMLMappingsi+0x668>
 *   @0x1907f4 sub sp, r11, #32
 *   @0x1907f8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1907fc mov r0, r5
 *   @0x190800 ldr r1, [r11, #-0x3c]
 *   @0x190804 bl 0x18e944 <_ZN9GMGamePad11SetDeviceIdEPKc>
 *   @0x190808 ldr r3, [pc, #0x60]
 *   @0x19080c ldr r1, [r11, #-0x40]
 *   @0x190810 mov r2, r4
 *   @0x190814 ldr r3, [r7, r3]
 *   @0x190818 ldr r0, [r3]
 *   @0x19081c ldr r3, [r0]
 *   @0x190820 ldr r3, [r3, #0xc]
 *   @0x190824 blx r3
 *   @0x190828 b 0x190658 <_Z16SetupGMLMappingsi+0x484>
 *   @0x19082c mov r10, #0
 *   @0x190830 b 0x1907c0 <_Z16SetupGMLMappingsi+0x5ec>
 *   @0x190834 mov r9, #0
 *   @0x190838 b 0x190714 <_Z16SetupGMLMappingsi+0x540>
 *   @0x19083c bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x190840 eoreq r1, r6, r12, lsr #15
 *   @0x190844 .word 0xffffbd00
 *   @0x190848 eorseq r5, r10, r8, ror r3
 *   @0x19084c .word 0xffffde10
 *   @0x190850 eorseq r5, r10, r4, lsr r3
 *   @0x190854 eorseq r5, r10, r8, lsr #6
 *   @0x190858 eorseq r5, r10, r4, lsr #6
 *   @0x19085c andseq lr, r9, r6, lsr #12
 *   @0x190860 mulseq r11, r12, r0
 *   @0x190864 andseq r12, r11, r8, rrx
 *   @0x190868 .word 0xffffbd54
 *   @0x19086c .word 0xffffde14
 *
 * ══ §23/33 CSprite::TMaskCreate(CMask*, CMask*, CBitmap32*, int, int, int)  0x1e35e4  size 944  236 条（0x1e35e4..0x1e3994）
 * @func 0x1e35e4 0x1e3994  size 944  236 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CBitmap32::GetData()×2 / CSprite::TMaskCreate(CMask*, CMask*, CBitmap32*, int, int, int)+0x224×2 / CSprite::TMaskCreate(CMask*, CMask*, CBitmap32*, int, int, int)+0x394×2 / CSprite::TMaskCreate(CMask*, CMask*, CBitmap32*, int, int, int)+0x50 / CSprite::TMaskCreate(CMask*, CMask*, CBitmap32*, int, int, int)+0x68 / CSprite::TMaskCreate(CMask*, CMask*, CBitmap32*, int, int, int)+0x118
 * 字段偏移 top8: 0x4×8 / 0x8×3 / 0x10×3 / 0xc×3 / 0x14×3 / 0x1c×2 / 0x20×2 / 0x1×2
 * VFP 指令 62 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e35e4 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1e35e8 mov r7, r0
 *   @0x1e35ec ldr r4, [sp, #0x2c]
 *   @0x1e35f0 mov r8, r1
 *   @0x1e35f4 mov r6, r2
 *   @0x1e35f8 mov r9, r3
 *   @0x1e35fc cmp r4, #0
 *   @0x1e3600 ldr r5, [sp, #0x30]
 *   @0x1e3604 beq 0x1e368c <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0xa8>
 *   @0x1e3608 ldr r12, [r0, #0x1c]
 *   @0x1e360c ldr r2, [r0, #0x20]
 *   @0x1e3610 mul r2, r2, r12
 *   @0x1e3614 cmp r2, #0
 *   @0x1e3618 ble 0x1e3634 <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x50>
 *   @0x1e361c ldr r3, [r6, #0x4]
 *   @0x1e3620 mov r1, #0
 *   @0x1e3624 add r2, r3, r2
 *   @0x1e3628 strb r1, [r3], #1
 *   @0x1e362c cmp r3, r2
 *   @0x1e3630 bne 0x1e3628 <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x44>
 *   @0x1e3634 cmp r4, #2
 *   @0x1e3638 beq 0x1e388c <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x2a8>
 *   @0x1e363c cmp r4, #3
 *   @0x1e3640 beq 0x1e371c <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x138>
 *   @0x1e3644 cmp r4, #1
 *   @0x1e3648 beq 0x1e3824 <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x240>
 *   @0x1e364c cmp r8, #0
 *   @0x1e3650 popeq {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1e3654 ldr r1, [r6]
 *   @0x1e3658 cmp r1, #0
 *   @0x1e365c pople {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1e3660 ldr r0, [r8, #0x4]
 *   @0x1e3664 mov r3, #0
 *   @0x1e3668 mov r12, #1
 *   @0x1e366c ldrb r2, [r0, r3]
 *   @0x1e3670 cmp r2, #0
 *   @0x1e3674 ldrne r2, [r6, #0x4]
 *   @0x1e3678 strbne r12, [r2, r3]
 *   @0x1e367c add r3, r3, #1
 *   @0x1e3680 cmp r3, r1
 *   @0x1e3684 bne 0x1e366c <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x88>
 *   @0x1e3688 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1e368c mov r0, r3
 *   @0x1e3690 bl 0x167970 <_ZN9CBitmap327GetDataEv>
 *   @0x1e3694 mov r0, r9
 *   @0x1e3698 bl 0x167970 <_ZN9CBitmap327GetDataEv>
 *   @0x1e369c ldr r10, [r7, #0x20]
 *   @0x1e36a0 cmp r10, #0
 *   @0x1e36a4 ldr r9, [r0, #0x4]
 *   @0x1e36a8 ble 0x1e364c <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x68>
 *   @0x1e36ac ldr r1, [r7, #0x1c]
 *   @0x1e36b0 sub r9, r9, #4
 *   @0x1e36b4 mov r2, r4
 *   @0x1e36b8 mov r7, r4
 *   @0x1e36bc lsl r11, r1, #2
 *   @0x1e36c0 cmp r1, #0
 *   @0x1e36c4 ble 0x1e36fc <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x118>
 *   @0x1e36c8 ldr r3, [r6, #0x4]
 *   @0x1e36cc mov r0, r9
 *   @0x1e36d0 add r4, r3, r1
 *   @0x1e36d4 add r3, r3, r2
 *   @0x1e36d8 add r4, r4, r2
 *   @0x1e36dc ldr r12, [r0, #0x4]!
 *   @0x1e36e0 and r12, r12, #-16777216
 *   @0x1e36e4 cmp r5, r12
 *   @0x1e36e8 movhs r12, #0
 *   @0x1e36ec movlo r12, #1
 *   @0x1e36f0 strb r12, [r3], #1
 *   @0x1e36f4 cmp r3, r4
 *   @0x1e36f8 bne 0x1e36dc <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0xf8>
 *   @0x1e36fc add r7, r7, #1
 *   @0x1e3700 add r9, r9, r11
 *   @0x1e3704 cmp r7, r10
 *   @0x1e3708 add r2, r2, r1
 *   @0x1e370c bne 0x1e36c0 <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0xdc>
 *   @0x1e3710 cmp r8, #0
 *   @0x1e3714 bne 0x1e3654 <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x70>
 *   @0x1e3718 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1e371c ldr r9, [r7, #0x8]
 *   @0x1e3720 vmov.f32 s15, #5.000000e-01
 *   @0x1e3724 ldr r10, [r7, #0x10]
 *   @0x1e3728 ldr r4, [r7, #0xc]
 *   @0x1e372c add r2, r9, r10
 *   @0x1e3730 ldr r7, [r7, #0x14]
 *   @0x1e3734 vmov s13, r9
 *   @0x1e3738 add r3, r4, r7
 *   @0x1e373c add r2, r2, r2, lsr #31
 *   @0x1e3740 cmp r4, r7
 *   @0x1e3744 add r3, r3, r3, lsr #31
 *   @0x1e3748 asr r2, r2, #1
 *   @0x1e374c asr r3, r3, #1
 *   @0x1e3750 vmov s8, r2
 *   @0x1e3754 vcvt.f32.s32 s14, s13
 *   @0x1e3758 vmov s13, r4
 *   @0x1e375c vcvt.f32.s32 s12, s8
 *   @0x1e3760 vmov s8, r3
 *   @0x1e3764 vcvt.f32.s32 s10, s13
 *   @0x1e3768 vcvt.f32.s32 s9, s8
 *   @0x1e376c vsub.f32 s14, s12, s14
 *   @0x1e3770 vsub.f32 s10, s9, s10
 *   @0x1e3774 vadd.f32 s14, s14, s15
 *   @0x1e3778 vadd.f32 s10, s10, s15
 *   @0x1e377c bgt 0x1e364c <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x68>
 *   @0x1e3780 mul r5, r4, r12
 *   @0x1e3784 add r7, r7, #1
 *   @0x1e3788 add r0, r10, #1
 *   @0x1e378c vmov.f32 s11, #1.000000e+00
 *   @0x1e3790 cmp r9, r10
 *   @0x1e3794 bgt 0x1e3808 <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x224>
 *   @0x1e3798 vcmpe.f32 s14, #0
 *   @0x1e379c vmrs APSR_nzcv, fpscr
 *   @0x1e37a0 ble 0x1e3808 <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x224>
 *   @0x1e37a4 vcmpe.f32 s10, #0
 *   @0x1e37a8 vmrs APSR_nzcv, fpscr
 *   @0x1e37ac ble 0x1e3808 <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x224>
 *   @0x1e37b0 vmov s15, r4
 *   @0x1e37b4 ldr r1, [r6, #0x4]
 *   @0x1e37b8 mov r3, r9
 *   @0x1e37bc vcvt.f32.s32 s13, s15
 *   @0x1e37c0 add r1, r1, r5
 *   @0x1e37c4 vsub.f32 s13, s13, s9
 *   @0x1e37c8 vdiv.f32 s13, s13, s10
 *   @0x1e37cc vabs.f32 s13, s13
 *   @0x1e37d0 vmov s8, r3
 *   @0x1e37d4 vcvt.f32.s32 s15, s8
 *   @0x1e37d8 vsub.f32 s15, s15, s12
 *   @0x1e37dc vdiv.f32 s15, s15, s14
 *   @0x1e37e0 vabs.f32 s15, s15
 *   @0x1e37e4 vadd.f32 s15, s15, s13
 *   @0x1e37e8 vcmpe.f32 s15, s11
 *   @0x1e37ec vmrs APSR_nzcv, fpscr
 *   @0x1e37f0 movpl r2, #0
 *   @0x1e37f4 movmi r2, #1
 *   @0x1e37f8 strb r2, [r1, r3]
 *   @0x1e37fc add r3, r3, #1
 *   @0x1e3800 cmp r3, r0
 *   @0x1e3804 bne 0x1e37d0 <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x1ec>
 *   @0x1e3808 add r4, r4, #1
 *   @0x1e380c add r5, r5, r12
 *   @0x1e3810 cmp r4, r7
 *   @0x1e3814 bne 0x1e3790 <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x1ac>
 *   @0x1e3818 cmp r8, #0
 *   @0x1e381c bne 0x1e3654 <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x70>
 *   @0x1e3820 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1e3824 ldr r5, [r7, #0xc]
 *   @0x1e3828 ldr r11, [r7, #0x14]
 *   @0x1e382c cmp r5, r11
 *   @0x1e3830 bgt 0x1e364c <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x68>
 *   @0x1e3834 mul r9, r12, r5
 *   @0x1e3838 ldr r10, [r7, #0x10]
 *   @0x1e383c ldr r7, [r7, #0x8]
 *   @0x1e3840 add r11, r11, #1
 *   @0x1e3844 add r0, r10, #1
 *   @0x1e3848 mov r2, r4
 *   @0x1e384c cmp r7, r10
 *   @0x1e3850 bgt 0x1e3870 <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x28c>
 *   @0x1e3854 ldr r1, [r6, #0x4]
 *   @0x1e3858 mov r3, r7
 *   @0x1e385c add r1, r1, r9
 *   @0x1e3860 strb r2, [r1, r3]
 *   @0x1e3864 add r3, r3, #1
 *   @0x1e3868 cmp r3, r0
 *   @0x1e386c bne 0x1e3860 <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x27c>
 *   @0x1e3870 add r5, r5, #1
 *   @0x1e3874 add r9, r9, r12
 *   @0x1e3878 cmp r5, r11
 *   @0x1e387c bne 0x1e384c <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x268>
 *   @0x1e3880 cmp r8, #0
 *   @0x1e3884 bne 0x1e3654 <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x70>
 *   @0x1e3888 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1e388c ldr r9, [r7, #0x8]
 *   @0x1e3890 vmov.f32 s15, #5.000000e-01
 *   @0x1e3894 ldr r10, [r7, #0x10]
 *   @0x1e3898 ldr r4, [r7, #0xc]
 *   @0x1e389c add r2, r9, r10
 *   @0x1e38a0 ldr r7, [r7, #0x14]
 *   @0x1e38a4 vmov s13, r9
 *   @0x1e38a8 add r3, r4, r7
 *   @0x1e38ac add r2, r2, r2, lsr #31
 *   @0x1e38b0 cmp r4, r7
 *   @0x1e38b4 add r3, r3, r3, lsr #31
 *   @0x1e38b8 asr r2, r2, #1
 *   @0x1e38bc asr r3, r3, #1
 *   @0x1e38c0 vmov s8, r2
 *   @0x1e38c4 vcvt.f32.s32 s14, s13
 *   @0x1e38c8 vmov s13, r4
 *   @0x1e38cc vcvt.f32.s32 s12, s8
 *   @0x1e38d0 vmov s8, r3
 *   @0x1e38d4 vcvt.f32.s32 s10, s13
 *   @0x1e38d8 vcvt.f32.s32 s9, s8
 *   @0x1e38dc vsub.f32 s14, s12, s14
 *   @0x1e38e0 vsub.f32 s10, s9, s10
 *   @0x1e38e4 vadd.f32 s14, s14, s15
 *   @0x1e38e8 vadd.f32 s10, s10, s15
 *   @0x1e38ec bgt 0x1e364c <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x68>
 *   @0x1e38f0 mul r5, r4, r12
 *   @0x1e38f4 add r7, r7, #1
 *   @0x1e38f8 add r0, r10, #1
 *   @0x1e38fc vmov.f32 s11, #1.000000e+00
 *   @0x1e3900 cmp r9, r10
 *   @0x1e3904 bgt 0x1e3978 <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x394>
 *   @0x1e3908 vcmpe.f32 s14, #0
 *   @0x1e390c vmrs APSR_nzcv, fpscr
 *   @0x1e3910 ble 0x1e3978 <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x394>
 *   @0x1e3914 vcmpe.f32 s10, #0
 *   @0x1e3918 vmrs APSR_nzcv, fpscr
 *   @0x1e391c ble 0x1e3978 <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x394>
 *   @0x1e3920 vmov s15, r4
 *   @0x1e3924 ldr r1, [r6, #0x4]
 *   @0x1e3928 mov r3, r9
 *   @0x1e392c vcvt.f32.s32 s13, s15
 *   @0x1e3930 add r1, r1, r5
 *   @0x1e3934 vsub.f32 s13, s13, s9
 *   @0x1e3938 vdiv.f32 s13, s13, s10
 *   @0x1e393c vmul.f32 s13, s13, s13
 *   @0x1e3940 vmov s8, r3
 *   @0x1e3944 vcvt.f32.s32 s15, s8
 *   @0x1e3948 vsub.f32 s15, s15, s12
 *   @0x1e394c vdiv.f32 s15, s15, s14
 *   @0x1e3950 vmov.f32 s8, s13
 *   @0x1e3954 vmla.f32 s8, s15, s15
 *   @0x1e3958 vcmpe.f32 s8, s11
 *   @0x1e395c vmrs APSR_nzcv, fpscr
 *   @0x1e3960 movpl r2, #0
 *   @0x1e3964 movmi r2, #1
 *   @0x1e3968 strb r2, [r1, r3]
 *   @0x1e396c add r3, r3, #1
 *   @0x1e3970 cmp r3, r0
 *   @0x1e3974 bne 0x1e3940 <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x35c>
 *   @0x1e3978 add r4, r4, #1
 *   @0x1e397c add r5, r5, r12
 *   @0x1e3980 cmp r4, r7
 *   @0x1e3984 bne 0x1e3900 <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x31c>
 *   @0x1e3988 cmp r8, #0
 *   @0x1e398c bne 0x1e3654 <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x70>
 *   @0x1e3990 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §24/33 CSprite::PreciseCollisionEllipse(int, tagYYRECT*, int, int, float, float, float, tagYYRECT*)  0x1e4f0c  size 944  236 条（0x1e4f0c..0x1e52bc）
 * @func 0x1e4f0c 0x1e52bc  size 944  236 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CSprite::PreciseCollisionEllipse(int, tagYYRECT*, int, int, float, float, float, tagYYRECT*)+0x37c×3 / CSprite::PreciseCollisionEllipse(int, tagYYRECT*, int, int, float, float, float, tagYYRECT*)+0x38c×2 / 0xb6910×2 / CSprite::PreciseCollisionEllipse(int, tagYYRECT*, int, int, float, float, float, tagYYRECT*)+0x1a4×2 / CSprite::PreciseCollisionEllipse(int, tagYYRECT*, int, int, float, float, float, tagYYRECT*)+0x36c×2 / CSprite::UnpackWADMask(int) / __aeabi_idivmod / 0xb6580
 * 字段偏移 top8: 0x4×6 / 0x8×2 / 0xc×2 / 0x1c×2 / 0x20×2 / 0x40×2 / 0x68×1 / 0x78×1
 * VFP 指令 86 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e4f0c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1e4f10 vpush {d8, d9, d10, d11, d12, d13, d14}
 *   @0x1e4f14 sub sp, sp, #12
 *   @0x1e4f18 vldr s23, [sp, #108]
 *   @0x1e4f1c mov r4, r0
 *   @0x1e4f20 mov r8, r3
 *   @0x1e4f24 mov r10, r2
 *   @0x1e4f28 mov r6, r1
 *   @0x1e4f2c ldr r5, [sp, #0x68]
 *   @0x1e4f30 vldr s24, [sp, #112]
 *   @0x1e4f34 ldr r9, [sp, #0x78]
 *   @0x1e4f38 bl 0x1e3994 <_ZN7CSprite13UnpackWADMaskEi>
 *   @0x1e4f3c ldrb r3, [r4, #0x31]
 *   @0x1e4f40 cmp r3, #0
 *   @0x1e4f44 moveq r0, #1
 *   @0x1e4f48 beq 0x1e5190 <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x284>
 *   @0x1e4f4c ldr r3, [r4, #0x18]
 *   @0x1e4f50 cmp r3, #0
 *   @0x1e4f54 ble 0x1e5288 <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x37c>
 *   @0x1e4f58 ldr r7, [r4, #0x3c]
 *   @0x1e4f5c mov r0, r6
 *   @0x1e4f60 mov r1, r7
 *   @0x1e4f64 bl 0x318dec <__aeabi_idivmod>
 *   @0x1e4f68 vmov.f32 s13, #1.000000e+00
 *   @0x1e4f6c ldr r0, [r9]
 *   @0x1e4f70 ldr r12, [r9, #0x8]
 *   @0x1e4f74 ldr r3, [r10, #0x8]
 *   @0x1e4f78 ldr r2, [r9, #0xc]
 *   @0x1e4f7c ldr r6, [r10]
 *   @0x1e4f80 vcmp.f32 s23, s13
 *   @0x1e4f84 subs r11, r1, #0
 *   @0x1e4f88 ldr r1, [r10, #0xc]
 *   @0x1e4f8c addlt r11, r11, r7
 *   @0x1e4f90 cmp r3, r12
 *   @0x1e4f94 movge r3, r12
 *   @0x1e4f98 ldr r7, [r10, #0x4]
 *   @0x1e4f9c add r10, r0, r12
 *   @0x1e4fa0 str r3, [sp]
 *   @0x1e4fa4 cmp r6, r0
 *   @0x1e4fa8 movlt r6, r0
 *   @0x1e4fac ldr r3, [r9, #0x4]
 *   @0x1e4fb0 rsb r0, r0, r12
 *   @0x1e4fb4 cmp r2, r1
 *   @0x1e4fb8 movlt r9, r2
 *   @0x1e4fbc movge r9, r1
 *   @0x1e4fc0 add r10, r10, r10, lsr #31
 *   @0x1e4fc4 add r1, r3, r2
 *   @0x1e4fc8 cmp r7, r3
 *   @0x1e4fcc movlt r7, r3
 *   @0x1e4fd0 rsb r3, r3, r2
 *   @0x1e4fd4 vmrs APSR_nzcv, fpscr
 *   @0x1e4fd8 add r0, r0, r0, lsr #31
 *   @0x1e4fdc asr r10, r10, #1
 *   @0x1e4fe0 add r1, r1, r1, lsr #31
 *   @0x1e4fe4 add r3, r3, r3, lsr #31
 *   @0x1e4fe8 vcmp.f32 s24, s13
 *   @0x1e4fec asr r0, r0, #1
 *   @0x1e4ff0 vmov s12, r10
 *   @0x1e4ff4 asr r1, r1, #1
 *   @0x1e4ff8 asr r3, r3, #1
 *   @0x1e4ffc movne r2, #0
 *   @0x1e5000 moveq r2, #1
 *   @0x1e5004 vmov s14, r0
 *   @0x1e5008 vmrs APSR_nzcv, fpscr
 *   @0x1e500c vcvt.f32.s32 s25, s12
 *   @0x1e5010 movne r2, #0
 *   @0x1e5014 andeq r2, r2, #1
 *   @0x1e5018 vmov s15, r1
 *   @0x1e501c vmov s12, r3
 *   @0x1e5020 cmp r2, #0
 *   @0x1e5024 vcvt.f32.s32 s26, s14
 *   @0x1e5028 vcvt.f32.s32 s16, s15
 *   @0x1e502c vcvt.f32.s32 s17, s12
 *   @0x1e5030 bne 0x1e519c <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x290>
 *   @0x1e5034 vldr s13, [sp, #116]
 *   @0x1e5038 vldr s19, [pc, #624]
 *   @0x1e503c vldr s18, [pc, #624]
 *   @0x1e5040 vnmul.f32 s15, s13, s19
 *   @0x1e5044 vdiv.f32 s15, s15, s18
 *   @0x1e5048 vmov r0, s15
 *   @0x1e504c bl 0xb6580 <sinf@plt>
 *   @0x1e5050 vldr s14, [sp, #116]
 *   @0x1e5054 vmul.f32 s19, s14, s19
 *   @0x1e5058 vdiv.f32 s19, s19, s18
 *   @0x1e505c vmov s20, r0
 *   @0x1e5060 vmov r0, s19
 *   @0x1e5064 bl 0xb658c <cosf@plt>
 *   @0x1e5068 ldr r3, [sp]
 *   @0x1e506c cmp r3, r6
 *   @0x1e5070 vmov s21, r0
 *   @0x1e5074 blt 0x1e5288 <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x37c>
 *   @0x1e5078 vmov.f32 s19, #1.000000e+00
 *   @0x1e507c lsl r11, r11, #3
 *   @0x1e5080 str r11, [sp, #0x4]
 *   @0x1e5084 cmp r9, r7
 *   @0x1e5088 blt 0x1e5298 <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x38c>
 *   @0x1e508c vmov s12, r6
 *   @0x1e5090 rsb r3, r8, r6
 *   @0x1e5094 mov r10, r7
 *   @0x1e5098 vmov s22, r3
 *   @0x1e509c vcvt.f32.s32 s18, s12
 *   @0x1e50a0 vsub.f32 s18, s18, s25
 *   @0x1e50a4 vdiv.f32 s18, s18, s26
 *   @0x1e50a8 vmul.f32 s18, s18, s18
 *   @0x1e50ac b 0x1e50bc <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x1b0>
 *   @0x1e50b0 add r10, r10, #1
 *   @0x1e50b4 cmp r9, r10
 *   @0x1e50b8 blt 0x1e5298 <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x38c>
 *   @0x1e50bc vmov s12, r10
 *   @0x1e50c0 vmov.f32 s13, s18
 *   @0x1e50c4 vcvt.f32.s32 s15, s12
 *   @0x1e50c8 vsub.f32 s15, s15, s16
 *   @0x1e50cc vdiv.f32 s15, s15, s17
 *   @0x1e50d0 vmla.f32 s13, s15, s15
 *   @0x1e50d4 vcmpe.f32 s13, s19
 *   @0x1e50d8 vmrs APSR_nzcv, fpscr
 *   @0x1e50dc bgt 0x1e50b0 <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x1a4>
 *   @0x1e50e0 rsb r3, r5, r10
 *   @0x1e50e4 vcvt.f32.s32 s28, s22
 *   @0x1e50e8 vldr s12, [r4, #36]
 *   @0x1e50ec vmov s27, r3
 *   @0x1e50f0 vcvt.f32.s32 s27, s27
 *   @0x1e50f4 vmul.f32 s14, s27, s20
 *   @0x1e50f8 vmla.f32 s14, s28, s21
 *   @0x1e50fc vdiv.f32 s14, s14, s23
 *   @0x1e5100 vcvt.f32.s32 s15, s12
 *   @0x1e5104 vadd.f32 s15, s14, s15
 *   @0x1e5108 vmov r0, s15
 *   @0x1e510c bl 0xb6910 <floorf@plt>
 *   @0x1e5110 vmul.f32 s15, s20, s28
 *   @0x1e5114 vldr s13, [r4, #40]
 *   @0x1e5118 vnmls.f32 s15, s21, s27
 *   @0x1e511c vmov s12, r0
 *   @0x1e5120 vdiv.f32 s15, s15, s24
 *   @0x1e5124 vcvt.f32.s32 s14, s13
 *   @0x1e5128 vadd.f32 s14, s15, s14
 *   @0x1e512c vcvt.s32.f32 s12, s12
 *   @0x1e5130 vmov r0, s14
 *   @0x1e5134 vmov r11, s12
 *   @0x1e5138 bl 0xb6910 <floorf@plt>
 *   @0x1e513c cmp r11, #0
 *   @0x1e5140 vmov s15, r0
 *   @0x1e5144 blt 0x1e50b0 <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x1a4>
 *   @0x1e5148 ldr r2, [r4, #0x1c]
 *   @0x1e514c cmp r11, r2
 *   @0x1e5150 bge 0x1e50b0 <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x1a4>
 *   @0x1e5154 vcvt.s32.f32 s15, s15
 *   @0x1e5158 vmov r1, s15
 *   @0x1e515c cmp r1, #0
 *   @0x1e5160 blt 0x1e50b0 <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x1a4>
 *   @0x1e5164 ldr r0, [r4, #0x20]
 *   @0x1e5168 cmp r1, r0
 *   @0x1e516c bge 0x1e50b0 <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x1a4>
 *   @0x1e5170 ldr r0, [r4, #0x40]
 *   @0x1e5174 ldr r3, [sp, #0x4]
 *   @0x1e5178 add r0, r0, r3
 *   @0x1e517c ldr r0, [r0, #0x4]
 *   @0x1e5180 mla r2, r2, r1, r0
 *   @0x1e5184 ldrb r0, [r2, r11]
 *   @0x1e5188 cmp r0, #0
 *   @0x1e518c beq 0x1e50b0 <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x1a4>
 *   @0x1e5190 add sp, sp, #12
 *   @0x1e5194 vpop {d8, d9, d10, d11, d12, d13, d14}
 *   @0x1e5198 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1e519c vldr s12, [sp, #116]
 *   @0x1e51a0 vabs.f32 s14, s12
 *   @0x1e51a4 vldr s15, [pc, #268]
 *   @0x1e51a8 vcmpe.f32 s14, s15
 *   @0x1e51ac vmrs APSR_nzcv, fpscr
 *   @0x1e51b0 bpl 0x1e5034 <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x128>
 *   @0x1e51b4 ldr r3, [sp]
 *   @0x1e51b8 cmp r3, r6
 *   @0x1e51bc blt 0x1e5288 <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x37c>
 *   @0x1e51c0 lsl r11, r11, #3
 *   @0x1e51c4 cmp r9, r7
 *   @0x1e51c8 blt 0x1e5278 <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x36c>
 *   @0x1e51cc vmov s12, r6
 *   @0x1e51d0 mov r3, r7
 *   @0x1e51d4 rsb r2, r8, r6
 *   @0x1e51d8 vcvt.f32.s32 s14, s12
 *   @0x1e51dc vsub.f32 s14, s14, s25
 *   @0x1e51e0 vdiv.f32 s14, s14, s26
 *   @0x1e51e4 vmul.f32 s14, s14, s14
 *   @0x1e51e8 b 0x1e51f8 <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x2ec>
 *   @0x1e51ec add r3, r3, #1
 *   @0x1e51f0 cmp r9, r3
 *   @0x1e51f4 blt 0x1e5278 <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x36c>
 *   @0x1e51f8 vmov s12, r3
 *   @0x1e51fc vcvt.f32.s32 s15, s12
 *   @0x1e5200 vsub.f32 s15, s15, s16
 *   @0x1e5204 vdiv.f32 s15, s15, s17
 *   @0x1e5208 vmov.f32 s12, s14
 *   @0x1e520c vmla.f32 s12, s15, s15
 *   @0x1e5210 vcmpe.f32 s12, s13
 *   @0x1e5214 vmrs APSR_nzcv, fpscr
 *   @0x1e5218 bgt 0x1e51ec <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x2e0>
 *   @0x1e521c ldr r1, [r4, #0x24]
 *   @0x1e5220 ldr r0, [r4, #0x28]
 *   @0x1e5224 adds r1, r2, r1
 *   @0x1e5228 bmi 0x1e51ec <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x2e0>
 *   @0x1e522c ldr r12, [r4, #0x1c]
 *   @0x1e5230 rsb r10, r5, r3
 *   @0x1e5234 cmp r1, r12
 *   @0x1e5238 bge 0x1e51ec <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x2e0>
 *   @0x1e523c adds r0, r0, r10
 *   @0x1e5240 bmi 0x1e51ec <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x2e0>
 *   @0x1e5244 ldr r10, [r4, #0x20]
 *   @0x1e5248 cmp r0, r10
 *   @0x1e524c bge 0x1e51ec <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x2e0>
 *   @0x1e5250 ldr r10, [r4, #0x40]
 *   @0x1e5254 add r10, r10, r11
 *   @0x1e5258 ldr r10, [r10, #0x4]
 *   @0x1e525c mla r0, r12, r0, r10
 *   @0x1e5260 ldrb r0, [r0, r1]
 *   @0x1e5264 cmp r0, #0
 *   @0x1e5268 bne 0x1e5190 <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x284>
 *   @0x1e526c add r3, r3, #1
 *   @0x1e5270 cmp r9, r3
 *   @0x1e5274 bge 0x1e51f8 <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x2ec>
 *   @0x1e5278 ldr r3, [sp]
 *   @0x1e527c add r6, r6, #1
 *   @0x1e5280 cmp r6, r3
 *   @0x1e5284 ble 0x1e51c4 <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x2b8>
 *   @0x1e5288 mov r0, #0
 *   @0x1e528c add sp, sp, #12
 *   @0x1e5290 vpop {d8, d9, d10, d11, d12, d13, d14}
 *   @0x1e5294 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1e5298 ldr r3, [sp]
 *   @0x1e529c add r6, r6, #1
 *   @0x1e52a0 cmp r6, r3
 *   @0x1e52a4 ble 0x1e5084 <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x178>
 *   @0x1e52a8 mov r0, #0
 *   @0x1e52ac b 0x1e528c <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x380>
 *   @0x1e52b0 ldrdmi r0, r1, [r9], #-251
 *   @0x1e52b4 teqmi r4, #0
 *   @0x1e52b8 ldmlo r1, {r0, r1, r2, r4, r8, r9, r10, r12, sp, pc} ^
 *
 * ══ §25/33 b2RevoluteJoint::InitVelocityConstraints(b2SolverData const&)  0x2d18cc  size 944  236 条（0x2d18cc..0x2d1c7c）
 * @func 0x2d18cc 0x2d1c7c  size 944  236 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6580×2 / 0xb658c×2 / b2RevoluteJoint::InitVelocityConstraints(b2SolverData const&)+0x398
 * 字段偏移 top8: 0xe0×6 / 0x8×4 / 0x60×3 / 0x80×2 / 0x84×2 / 0x5c×2 / 0x70×2 / 0x30×1
 * VFP 指令 137 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d18cc ldr r2, [r0, #0x30]
 *   @0x2d18d0 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2d18d4 vpush {d8, d9, d10, d11, d12, d13, d14}
 *   @0x2d18d8 mov r6, r1
 *   @0x2d18dc vldr s18, [r2, #136]
 *   @0x2d18e0 ldr r3, [r0, #0x34]
 *   @0x2d18e4 add r1, r2, #44
 *   @0x2d18e8 ldr lr, [r2, #0x8]
 *   @0x2d18ec mov r4, r0
 *   @0x2d18f0 vldr s19, [r3, #136]
 *   @0x2d18f4 ldr r9, [r6, #0x18]
 *   @0x2d18f8 ldr r12, [r3, #0x8]
 *   @0x2d18fc add r8, r0, #160
 *   @0x2d1900 add r10, r0, #152
 *   @0x2d1904 ldm r1, {r0, r1}
 *   @0x2d1908 str lr, [r4, #0x80]
 *   @0x2d190c add lr, lr, lr, lsl #1
 *   @0x2d1910 vldr s16, [r2, #144]
 *   @0x2d1914 add r7, r3, #44
 *   @0x2d1918 lsl lr, lr, #2
 *   @0x2d191c ldr r5, [r6, #0x1c]
 *   @0x2d1920 add r2, r9, lr
 *   @0x2d1924 str r12, [r4, #0x84]
 *   @0x2d1928 stm r10, {r0, r1}
 *   @0x2d192c add r12, r12, r12, lsl #1
 *   @0x2d1930 ldm r7, {r0, r1}
 *   @0x2d1934 vldr s17, [r3, #144]
 *   @0x2d1938 ldr r7, [r2, #0x8]
 *   @0x2d193c lsl r12, r12, #2
 *   @0x2d1940 add lr, r5, lr
 *   @0x2d1944 add r9, r9, r12
 *   @0x2d1948 stm r8, {r0, r1}
 *   @0x2d194c vstr s18, [r4, #168]
 *   @0x2d1950 mov r0, r7
 *   @0x2d1954 vstr s19, [r4, #172]
 *   @0x2d1958 vstr s16, [r4, #176]
 *   @0x2d195c vstr s17, [r4, #180]
 *   @0x2d1960 add r12, r5, r12
 *   @0x2d1964 vldr s28, [lr]
 *   @0x2d1968 vldr s27, [lr, #4]
 *   @0x2d196c vldr s23, [lr, #8]
 *   @0x2d1970 vldr s26, [r12]
 *   @0x2d1974 vldr s25, [r12, #4]
 *   @0x2d1978 vldr s24, [r12, #8]
 *   @0x2d197c bl 0xb6580 <sinf@plt>
 *   @0x2d1980 ldr r8, [r9, #0x8]
 *   @0x2d1984 vmov s22, r0
 *   @0x2d1988 mov r0, r7
 *   @0x2d198c bl 0xb658c <cosf@plt>
 *   @0x2d1990 vmov s21, r0
 *   @0x2d1994 mov r0, r8
 *   @0x2d1998 bl 0xb6580 <sinf@plt>
 *   @0x2d199c vmov s20, r0
 *   @0x2d19a0 mov r0, r8
 *   @0x2d19a4 bl 0xb658c <cosf@plt>
 *   @0x2d19a8 vldr s14, [r4, #72]
 *   @0x2d19ac vldr s15, [r4, #156]
 *   @0x2d19b0 vsub.f32 s15, s14, s15
 *   @0x2d19b4 vldr s12, [r4, #80]
 *   @0x2d19b8 vldr s14, [r4, #164]
 *   @0x2d19bc vldr s13, [r4, #152]
 *   @0x2d19c0 vldr s9, [r4, #68]
 *   @0x2d19c4 vldr s8, [r4, #76]
 *   @0x2d19c8 vldr s10, [r4, #160]
 *   @0x2d19cc vsub.f32 s14, s12, s14
 *   @0x2d19d0 vmul.f32 s12, s15, s21
 *   @0x2d19d4 vmov s11, r0
 *   @0x2d19d8 vsub.f32 s9, s9, s13
 *   @0x2d19dc vmla.f32 s12, s9, s22
 *   @0x2d19e0 vmul.f32 s13, s14, s11
 *   @0x2d19e4 vstr s12, [r4, #140]
 *   @0x2d19e8 ldrb r2, [r4, #0x64]
 *   @0x2d19ec vmul.f32 s14, s14, s20
 *   @0x2d19f0 vsub.f32 s10, s8, s10
 *   @0x2d19f4 vmul.f32 s15, s15, s22
 *   @0x2d19f8 vmla.f32 s13, s10, s20
 *   @0x2d19fc vnmls.f32 s14, s10, s11
 *   @0x2d1a00 vstr s13, [r4, #148]
 *   @0x2d1a04 vadd.f32 s10, s18, s19
 *   @0x2d1a08 vstr s14, [r4, #144]
 *   @0x2d1a0c vnmls.f32 s15, s9, s21
 *   @0x2d1a10 vmul.f32 s9, s12, s12
 *   @0x2d1a14 vstr s15, [r4, #136]
 *   @0x2d1a18 vmov.f32 s7, s10
 *   @0x2d1a1c vmla.f32 s7, s16, s9
 *   @0x2d1a20 vmul.f32 s11, s14, s13
 *   @0x2d1a24 vmov.f32 s9, s7
 *   @0x2d1a28 vmul.f32 s7, s14, s14
 *   @0x2d1a2c vmul.f32 s14, s17, s14
 *   @0x2d1a30 vmul.f32 s8, s15, s15
 *   @0x2d1a34 vneg.f32 s12, s12
 *   @0x2d1a38 vmla.f32 s14, s16, s15
 *   @0x2d1a3c vmla.f32 s10, s16, s8
 *   @0x2d1a40 vstr s14, [r4, #212]
 *   @0x2d1a44 vstr s14, [r4, #204]
 *   @0x2d1a48 vmul.f32 s8, s12, s15
 *   @0x2d1a4c vadd.f32 s15, s16, s17
 *   @0x2d1a50 vcmp.f32 s15, #0
 *   @0x2d1a54 vstr s15, [r4, #216]
 *   @0x2d1a58 vmrs APSR_nzcv, fpscr
 *   @0x2d1a5c vcmpe.f32 s15, #0
 *   @0x2d1a60 movne r3, #0
 *   @0x2d1a64 moveq r3, #1
 *   @0x2d1a68 vmrs APSR_nzcv, fpscr
 *   @0x2d1a6c vmovgt.f32 s14, #1.000000e+00
 *   @0x2d1a70 vdivgt.f32 s15, s14, s15
 *   @0x2d1a74 cmp r2, #0
 *   @0x2d1a78 vmul.f32 s6, s13, s13
 *   @0x2d1a7c vstr s15, [r4, #220]
 *   @0x2d1a80 vmul.f32 s11, s17, s11
 *   @0x2d1a84 vmul.f32 s13, s17, s13
 *   @0x2d1a88 vnmls.f32 s11, s16, s8
 *   @0x2d1a8c vnmls.f32 s13, s16, s12
 *   @0x2d1a90 vstr s11, [r4, #196]
 *   @0x2d1a94 vstr s11, [r4, #188]
 *   @0x2d1a98 vmla.f32 s9, s17, s6
 *   @0x2d1a9c vstr s13, [r4, #208]
 *   @0x2d1aa0 vstr s13, [r4, #192]
 *   @0x2d1aa4 vmla.f32 s10, s17, s7
 *   @0x2d1aa8 vstr s9, [r4, #184]
 *   @0x2d1aac vstr s10, [r4, #200]
 *   @0x2d1ab0 beq 0x2d1b24 <_ZN15b2RevoluteJoint23InitVelocityConstraintsERK12b2SolverData+0x258>
 *   @0x2d1ab4 cmp r3, #0
 *   @0x2d1ab8 beq 0x2d1c54 <_ZN15b2RevoluteJoint23InitVelocityConstraintsERK12b2SolverData+0x388>
 *   @0x2d1abc mov r3, #0
 *   @0x2d1ac0 str r3, [r4, #0x60]
 *   @0x2d1ac4 mov r3, #0
 *   @0x2d1ac8 str r3, [r4, #0xe0]
 *   @0x2d1acc ldrb r3, [r6, #0x14]
 *   @0x2d1ad0 cmp r3, #0
 *   @0x2d1ad4 bne 0x2d1bac <_ZN15b2RevoluteJoint23InitVelocityConstraintsERK12b2SolverData+0x2e0>
 *   @0x2d1ad8 mov r3, #0
 *   @0x2d1adc str r3, [r4, #0x54]
 *   @0x2d1ae0 str r3, [r4, #0x58]
 *   @0x2d1ae4 str r3, [r4, #0x5c]
 *   @0x2d1ae8 str r3, [r4, #0x60]
 *   @0x2d1aec ldr r3, [r4, #0x80]
 *   @0x2d1af0 ldr r2, [r4, #0x84]
 *   @0x2d1af4 add r3, r3, r3, lsl #1
 *   @0x2d1af8 add r2, r2, r2, lsl #1
 *   @0x2d1afc add r3, r5, r3, lsl #2
 *   @0x2d1b00 vstr s28, [r3]
 *   @0x2d1b04 vstr s27, [r3, #4]
 *   @0x2d1b08 vstr s23, [r3, #8]
 *   @0x2d1b0c add r5, r5, r2, lsl #2
 *   @0x2d1b10 vstr s26, [r5]
 *   @0x2d1b14 vstr s25, [r5, #4]
 *   @0x2d1b18 vstr s24, [r5, #8]
 *   @0x2d1b1c vpop {d8, d9, d10, d11, d12, d13, d14}
 *   @0x2d1b20 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2d1b24 ldrb r2, [r4, #0x70]
 *   @0x2d1b28 mov r1, #0
 *   @0x2d1b2c str r1, [r4, #0x60]
 *   @0x2d1b30 cmp r2, #0
 *   @0x2d1b34 beq 0x2d1ac4 <_ZN15b2RevoluteJoint23InitVelocityConstraintsERK12b2SolverData+0x1f8>
 *   @0x2d1b38 cmp r3, #0
 *   @0x2d1b3c bne 0x2d1ac4 <_ZN15b2RevoluteJoint23InitVelocityConstraintsERK12b2SolverData+0x1f8>
 *   @0x2d1b40 vldr s13, [r4, #124]
 *   @0x2d1b44 vldr s14, [r4, #120]
 *   @0x2d1b48 vsub.f32 s15, s13, s14
 *   @0x2d1b4c vldr s12, [pc, #292]
 *   @0x2d1b50 vldr s11, [r4, #116]
 *   @0x2d1b54 vcmpe.f32 s15, #0
 *   @0x2d1b58 vmrs APSR_nzcv, fpscr
 *   @0x2d1b5c vnegle.f32 s15, s15
 *   @0x2d1b60 vcmpe.f32 s15, s12
 *   @0x2d1b64 vmrs APSR_nzcv, fpscr
 *   @0x2d1b68 movmi r3, #3
 *   @0x2d1b6c strmi r3, [r4, #0xe0]
 *   @0x2d1b70 bmi 0x2d1acc <_ZN15b2RevoluteJoint23InitVelocityConstraintsERK12b2SolverData+0x200>
 *   @0x2d1b74 vmov s10, r8
 *   @0x2d1b78 vmov s12, r7
 *   @0x2d1b7c vsub.f32 s15, s10, s12
 *   @0x2d1b80 vsub.f32 s11, s15, s11
 *   @0x2d1b84 vcmpe.f32 s11, s14
 *   @0x2d1b88 vmrs APSR_nzcv, fpscr
 *   @0x2d1b8c bhi 0x2d1c2c <_ZN15b2RevoluteJoint23InitVelocityConstraintsERK12b2SolverData+0x360>
 *   @0x2d1b90 ldr r3, [r4, #0xe0]
 *   @0x2d1b94 cmp r3, #1
 *   @0x2d1b98 movne r3, #0
 *   @0x2d1b9c strne r3, [r4, #0x5c]
 *   @0x2d1ba0 mov r3, #1
 *   @0x2d1ba4 str r3, [r4, #0xe0]
 *   @0x2d1ba8 b 0x2d1acc <_ZN15b2RevoluteJoint23InitVelocityConstraintsERK12b2SolverData+0x200>
 *   @0x2d1bac vldr s13, [r6, #8]
 *   @0x2d1bb0 vldr s14, [r4, #84]
 *   @0x2d1bb4 vmul.f32 s14, s13, s14
 *   @0x2d1bb8 vldr s15, [r4, #88]
 *   @0x2d1bbc vldr s10, [r4, #140]
 *   @0x2d1bc0 vldr s12, [r4, #148]
 *   @0x2d1bc4 vldr s7, [r4, #136]
 *   @0x2d1bc8 vldr s8, [r4, #144]
 *   @0x2d1bcc vldr s11, [r4, #96]
 *   @0x2d1bd0 vldr s9, [r4, #92]
 *   @0x2d1bd4 vmul.f32 s15, s13, s15
 *   @0x2d1bd8 vstr s14, [r4, #84]
 *   @0x2d1bdc vmul.f32 s10, s14, s10
 *   @0x2d1be0 vstr s15, [r4, #88]
 *   @0x2d1be4 vmul.f32 s12, s14, s12
 *   @0x2d1be8 vnmls.f32 s10, s15, s7
 *   @0x2d1bec vnmls.f32 s12, s15, s8
 *   @0x2d1bf0 vmul.f32 s11, s13, s11
 *   @0x2d1bf4 vmul.f32 s13, s13, s9
 *   @0x2d1bf8 vstr s11, [r4, #96]
 *   @0x2d1bfc vadd.f32 s10, s11, s10
 *   @0x2d1c00 vstr s13, [r4, #92]
 *   @0x2d1c04 vadd.f32 s12, s11, s12
 *   @0x2d1c08 vadd.f32 s10, s10, s13
 *   @0x2d1c0c vadd.f32 s13, s12, s13
 *   @0x2d1c10 vmls.f32 s28, s18, s14
 *   @0x2d1c14 vmla.f32 s26, s19, s14
 *   @0x2d1c18 vmls.f32 s27, s18, s15
 *   @0x2d1c1c vmla.f32 s25, s19, s15
 *   @0x2d1c20 vmls.f32 s23, s16, s10
 *   @0x2d1c24 vmla.f32 s24, s17, s13
 *   @0x2d1c28 b 0x2d1aec <_ZN15b2RevoluteJoint23InitVelocityConstraintsERK12b2SolverData+0x220>
 *   @0x2d1c2c vcmpe.f32 s11, s13
 *   @0x2d1c30 vmrs APSR_nzcv, fpscr
 *   @0x2d1c34 blt 0x2d1c64 <_ZN15b2RevoluteJoint23InitVelocityConstraintsERK12b2SolverData+0x398>
 *   @0x2d1c38 ldr r3, [r4, #0xe0]
 *   @0x2d1c3c cmp r3, #2
 *   @0x2d1c40 movne r3, #0
 *   @0x2d1c44 strne r3, [r4, #0x5c]
 *   @0x2d1c48 mov r3, #2
 *   @0x2d1c4c str r3, [r4, #0xe0]
 *   @0x2d1c50 b 0x2d1acc <_ZN15b2RevoluteJoint23InitVelocityConstraintsERK12b2SolverData+0x200>
 *   @0x2d1c54 ldrb r3, [r4, #0x70]
 *   @0x2d1c58 cmp r3, #0
 *   @0x2d1c5c bne 0x2d1b40 <_ZN15b2RevoluteJoint23InitVelocityConstraintsERK12b2SolverData+0x274>
 *   @0x2d1c60 b 0x2d1ac4 <_ZN15b2RevoluteJoint23InitVelocityConstraintsERK12b2SolverData+0x1f8>
 *   @0x2d1c64 mov r3, #0
 *   @0x2d1c68 mov r2, #0
 *   @0x2d1c6c str r3, [r4, #0xe0]
 *   @0x2d1c70 str r2, [r4, #0x5c]
 *   @0x2d1c74 b 0x2d1acc <_ZN15b2RevoluteJoint23InitVelocityConstraintsERK12b2SolverData+0x200>
 *   @0x2d1c78 vstrlo s30, [lr, #216]
 *
 * ══ §26/33 GR_Window_View_Convert(int, int, int, int&, int&)  0x179d64  size 940  235 条（0x179d64..0x17a110）
 * @func 0x179d64 0x17a110  size 940  235 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8×4 / 0xb67e4×2 / 0xb67d8×2 / Get_FullScreenOffset(int&, int&, int&, int&) / CCameraManager::GetCamera(int) / CCamera::GetInvViewProjMat()
 * 字段偏移 top8: 0xa0×6 / 0x370×1 / 0x358×1 / 0x2fc×1 / 0x8×1 / 0x2f4×1 / 0x2d8×1 / 0x2c4×1
 * VFP 指令 133 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x179d64 push {r4, r5, r6, r7, r8, lr}
 *   @0x179d68 vpush {d8, d9, d10, d11, d12, d13}
 *   @0x179d6c cmp r0, #31
 *   @0x179d70 ldr r4, [pc, #0x370]
 *   @0x179d74 sub sp, sp, #88
 *   @0x179d78 mov r7, r1
 *   @0x179d7c mov r6, r2
 *   @0x179d80 mov r5, r3
 *   @0x179d84 add r4, pc, r4
 *   @0x179d88 bhi 0x179da8 <_Z22GR_Window_View_ConvertiiiRiS_+0x44>
 *   @0x179d8c ldr r3, [pc, #0x358]
 *   @0x179d90 add r0, r0, r0, lsl #1
 *   @0x179d94 lsl r0, r0, #4
 *   @0x179d98 ldr r12, [r4, r3]
 *   @0x179d9c ldrb r3, [r12, r0]
 *   @0x179da0 cmp r3, #0
 *   @0x179da4 bne 0x179db4 <_Z22GR_Window_View_ConvertiiiRiS_+0x50>
 *   @0x179da8 add sp, sp, #88
 *   @0x179dac vpop {d8, d9, d10, d11, d12, d13}
 *   @0x179db0 pop {r4, r5, r6, r7, r8, pc}
 *   @0x179db4 add r8, r0, r12
 *   @0x179db8 vldr s15, [r8, #28]
 *   @0x179dbc vcmp.f32 s15, #0
 *   @0x179dc0 vmrs APSR_nzcv, fpscr
 *   @0x179dc4 beq 0x179da8 <_Z22GR_Window_View_ConvertiiiRiS_+0x44>
 *   @0x179dc8 vldr s15, [r8, #32]
 *   @0x179dcc vcmp.f32 s15, #0
 *   @0x179dd0 vmrs APSR_nzcv, fpscr
 *   @0x179dd4 beq 0x179da8 <_Z22GR_Window_View_ConvertiiiRiS_+0x44>
 *   @0x179dd8 add r0, sp, #8
 *   @0x179ddc add r1, sp, #12
 *   @0x179de0 add r2, sp, #16
 *   @0x179de4 add r3, sp, #20
 *   @0x179de8 bl 0x179a00 <_Z20Get_FullScreenOffsetRiS_S_S_>
 *   @0x179dec ldr r2, [pc, #0x2fc]
 *   @0x179df0 ldr r3, [sp, #0x8]
 *   @0x179df4 vldr s15, [r8, #20]
 *   @0x179df8 ldr r0, [pc, #0x2f4]
 *   @0x179dfc vcvt.s32.f32 s15, s15
 *   @0x179e00 ldr r2, [r4, r2]
 *   @0x179e04 rsb r7, r3, r7
 *   @0x179e08 ldr r12, [r4, r0]
 *   @0x179e0c vldr s7, [r12]
 *   @0x179e10 ldr r2, [r2]
 *   @0x179e14 vmov s11, r7
 *   @0x179e18 ldr r0, [pc, #0x2d8]
 *   @0x179e1c sub r2, r2, r3, lsl #1
 *   @0x179e20 vcvt.f32.s32 s7, s7
 *   @0x179e24 ldr r0, [r4, r0]
 *   @0x179e28 vldr s8, [r0]
 *   @0x179e2c vmov s10, r2
 *   @0x179e30 ldr r0, [pc, #0x2c4]
 *   @0x179e34 ldr r3, [sp, #0xc]
 *   @0x179e38 ldr r2, [pc, #0x2c0]
 *   @0x179e3c ldr r12, [r4, r0]
 *   @0x179e40 rsb r6, r3, r6
 *   @0x179e44 ldr r0, [pc, #0x2b8]
 *   @0x179e48 vcvt.f32.s32 s10, s10
 *   @0x179e4c ldr r2, [r4, r2]
 *   @0x179e50 ldr r12, [r12]
 *   @0x179e54 vldr s12, [r2]
 *   @0x179e58 vmov r1, s15
 *   @0x179e5c vldr s15, [r8, #24]
 *   @0x179e60 ldr r2, [pc, #0x2a0]
 *   @0x179e64 sub r3, r12, r3, lsl #1
 *   @0x179e68 vdiv.f32 s10, s7, s10
 *   @0x179e6c vdiv.f32 s10, s10, s8
 *   @0x179e70 vmov s8, r3
 *   @0x179e74 vcvt.f32.s32 s12, s12
 *   @0x179e78 vcvt.f32.s32 s9, s8
 *   @0x179e7c vdiv.f32 s12, s12, s9
 *   @0x179e80 vcvt.f32.s32 s11, s11
 *   @0x179e84 vmul.f32 s11, s11, s10
 *   @0x179e88 vmov s10, r6
 *   @0x179e8c vcvt.s32.f32 s11, s11
 *   @0x179e90 vstr s11, [r5]
 *   @0x179e94 ldr r3, [r4, r0]
 *   @0x179e98 vldr s14, [r3]
 *   @0x179e9c vdiv.f32 s14, s12, s14
 *   @0x179ea0 ldr r0, [sp, #0xa0]
 *   @0x179ea4 vcvt.f32.s32 s13, s10
 *   @0x179ea8 vcvt.s32.f32 s15, s15
 *   @0x179eac vmul.f32 s14, s13, s14
 *   @0x179eb0 vmov r3, s15
 *   @0x179eb4 vcvt.s32.f32 s14, s14
 *   @0x179eb8 vstr s14, [r0]
 *   @0x179ebc ldr r0, [r5]
 *   @0x179ec0 rsb r1, r1, r0
 *   @0x179ec4 ldr r0, [sp, #0xa0]
 *   @0x179ec8 str r1, [r5]
 *   @0x179ecc ldr r1, [r0]
 *   @0x179ed0 rsb r3, r3, r1
 *   @0x179ed4 str r3, [r0]
 *   @0x179ed8 ldr r2, [r4, r2]
 *   @0x179edc ldrb r2, [r2]
 *   @0x179ee0 cmp r2, #0
 *   @0x179ee4 bne 0x17a034 <_Z22GR_Window_View_ConvertiiiRiS_+0x2d0>
 *   @0x179ee8 vmov s8, r3
 *   @0x179eec vldr s15, [r8, #12]
 *   @0x179ef0 vldr s17, [r8, #16]
 *   @0x179ef4 vldr s14, [r8, #36]
 *   @0x179ef8 vcvt.f32.s32 s12, s8
 *   @0x179efc vldr s8, [r5]
 *   @0x179f00 vldr s9, [pc, #468]
 *   @0x179f04 vldr s11, [r8, #28]
 *   @0x179f08 vldr s13, [r8, #32]
 *   @0x179f0c vcvt.f32.s32 s10, s8
 *   @0x179f10 vmul.f32 s12, s17, s12
 *   @0x179f14 vmul.f32 s10, s15, s10
 *   @0x179f18 vabs.f32 s8, s14
 *   @0x179f1c vcmpe.f32 s8, s9
 *   @0x179f20 vdiv.f32 s11, s10, s11
 *   @0x179f24 vmrs APSR_nzcv, fpscr
 *   @0x179f28 vdiv.f32 s16, s12, s13
 *   @0x179f2c bpl 0x179f68 <_Z22GR_Window_View_ConvertiiiRiS_+0x204>
 *   @0x179f30 vldr s15, [r8, #4]
 *   @0x179f34 vadd.f32 s11, s11, s15
 *   @0x179f38 vcvt.f64.f32 d6, s11
 *   @0x179f3c vmov r0, r1, d6
 *   @0x179f40 bl 0xb66e8 <lrint@plt>
 *   @0x179f44 vldr s15, [r8, #8]
 *   @0x179f48 vadd.f32 s16, s16, s15
 *   @0x179f4c vcvt.f64.f32 d7, s16
 *   @0x179f50 str r0, [r5]
 *   @0x179f54 vmov r0, r1, d7
 *   @0x179f58 bl 0xb66e8 <lrint@plt>
 *   @0x179f5c ldr r1, [sp, #0xa0]
 *   @0x179f60 str r0, [r1]
 *   @0x179f64 b 0x179da8 <_Z22GR_Window_View_ConvertiiiRiS_+0x44>
 *   @0x179f68 vldr s26, [pc, #368]
 *   @0x179f6c vnmul.f32 s14, s14, s26
 *   @0x179f70 vldr s25, [pc, #364]
 *   @0x179f74 vdiv.f32 s20, s14, s25
 *   @0x179f78 vmov.f32 s24, #5.000000e-01
 *   @0x179f7c vmul.f32 s27, s15, s24
 *   @0x179f80 vsub.f32 s11, s11, s27
 *   @0x179f84 vcvt.f64.f32 d10, s20
 *   @0x179f88 vmov r0, r1, d10
 *   @0x179f8c vcvt.f64.f32 d9, s11
 *   @0x179f90 bl 0xb67e4 <cos@plt>
 *   @0x179f94 vmls.f32 s16, s17, s24
 *   @0x179f98 vcvt.f64.f32 d8, s16
 *   @0x179f9c vmov d11, r0, r1
 *   @0x179fa0 vmov r0, r1, d10
 *   @0x179fa4 bl 0xb67d8 <sin@plt>
 *   @0x179fa8 vldr s14, [r8, #4]
 *   @0x179fac vadd.f32 s14, s27, s14
 *   @0x179fb0 vcvt.f64.f32 d7, s14
 *   @0x179fb4 vmla.f64 d7, d9, d11
 *   @0x179fb8 vmov d6, r0, r1
 *   @0x179fbc vmov.f64 d5, d7
 *   @0x179fc0 vmla.f64 d5, d8, d6
 *   @0x179fc4 vmov r0, r1, d5
 *   @0x179fc8 bl 0xb66e8 <lrint@plt>
 *   @0x179fcc vldr s22, [r8, #36]
 *   @0x179fd0 vmul.f32 s15, s22, s26
 *   @0x179fd4 vdiv.f32 s15, s15, s25
 *   @0x179fd8 str r0, [r5]
 *   @0x179fdc vnmul.f32 s22, s22, s26
 *   @0x179fe0 vdiv.f32 s25, s22, s25
 *   @0x179fe4 vcvt.f64.f32 d5, s15
 *   @0x179fe8 vmov r0, r1, d5
 *   @0x179fec bl 0xb67d8 <sin@plt>
 *   @0x179ff0 vcvt.f64.f32 d6, s25
 *   @0x179ff4 vmov d10, r0, r1
 *   @0x179ff8 vmov r0, r1, d6
 *   @0x179ffc bl 0xb67e4 <cos@plt>
 *   @0x17a000 vldr s15, [r8, #16]
 *   @0x17a004 vldr s14, [r8, #8]
 *   @0x17a008 vmla.f32 s14, s15, s24
 *   @0x17a00c vcvt.f64.f32 d7, s14
 *   @0x17a010 vmla.f64 d7, d9, d10
 *   @0x17a014 vmov d6, r0, r1
 *   @0x17a018 vmov.f64 d5, d7
 *   @0x17a01c vmla.f64 d5, d8, d6
 *   @0x17a020 vmov r0, r1, d5
 *   @0x17a024 bl 0xb66e8 <lrint@plt>
 *   @0x17a028 ldr r1, [sp, #0xa0]
 *   @0x17a02c str r0, [r1]
 *   @0x17a030 b 0x179da8 <_Z22GR_Window_View_ConvertiiiRiS_+0x44>
 *   @0x17a034 ldr r3, [pc, #0xd0]
 *   @0x17a038 ldr r1, [r8, #0x2c]
 *   @0x17a03c ldr r0, [r4, r3]
 *   @0x17a040 bl 0x16f45c <_ZN14CCameraManager9GetCameraEi>
 *   @0x17a044 subs r1, r0, #0
 *   @0x17a048 beq 0x179da8 <_Z22GR_Window_View_ConvertiiiRiS_+0x44>
 *   @0x17a04c ldr r2, [sp, #0xa0]
 *   @0x17a050 vldr s13, [r8, #32]
 *   @0x17a054 vldr s10, [r5]
 *   @0x17a058 vcvt.f32.s32 s16, s10
 *   @0x17a05c vldr s14, [r8, #28]
 *   @0x17a060 add r0, sp, #24
 *   @0x17a064 ldr r2, [r2]
 *   @0x17a068 vmov s8, r2
 *   @0x17a06c str r2, [sp, #0x4]
 *   @0x17a070 vcvt.f32.s32 s17, s8
 *   @0x17a074 vdiv.f32 s17, s17, s13
 *   @0x17a078 vdiv.f32 s16, s16, s14
 *   @0x17a07c vmov.f32 s15, #1.000000e+00
 *   @0x17a080 vadd.f32 s17, s17, s17
 *   @0x17a084 vadd.f32 s16, s16, s16
 *   @0x17a088 vsub.f32 s17, s17, s15
 *   @0x17a08c vsub.f32 s16, s16, s15
 *   @0x17a090 bl 0x16d260 <_ZN7CCamera17GetInvViewProjMatEv>
 *   @0x17a094 vldr s14, [sp, #40]
 *   @0x17a098 vldr s15, [sp, #44]
 *   @0x17a09c vldr s10, [sp, #24]
 *   @0x17a0a0 vldr s11, [sp, #28]
 *   @0x17a0a4 vldr s12, [sp, #72]
 *   @0x17a0a8 vldr s13, [sp, #76]
 *   @0x17a0ac ldr r0, [sp, #0xa0]
 *   @0x17a0b0 vmul.f32 s14, s17, s14
 *   @0x17a0b4 vmul.f32 s15, s17, s15
 *   @0x17a0b8 vmla.f32 s14, s16, s10
 *   @0x17a0bc vmla.f32 s15, s16, s11
 *   @0x17a0c0 vadd.f32 s14, s14, s12
 *   @0x17a0c4 vadd.f32 s15, s15, s13
 *   @0x17a0c8 vcvt.s32.f32 s14, s14
 *   @0x17a0cc vcvt.s32.f32 s15, s15
 *   @0x17a0d0 vstr s14, [r5]
 *   @0x17a0d4 vstr s15, [r0]
 *   @0x17a0d8 b 0x179da8 <_Z22GR_Window_View_ConvertiiiRiS_+0x44>
 *   @0x17a0dc ldmlo r1, {r0, r1, r2, r4, r8, r9, r10, r12, sp, pc} ^
 *   @0x17a0e0 ldrdmi r0, r1, [r9], #-251
 *   @0x17a0e4 teqmi r4, #0
 *   @0x17a0e8 eoreq r7, r7, r12, asr #29
 *   @0x17a0ec .word 0xffffe6b0
 *   @0x17a0f0 .word 0xffffe6b8
 *   @0x17a0f4 .word 0xffffdf38
 *   @0x17a0f8 .word 0xffffe6bc
 *   @0x17a0fc .word 0xffffe6c0
 *   @0x17a100 .word 0xffffdf40
 *   @0x17a104 .word 0xffffe6c4
 *   @0x17a108 .word 0xffffbcd4
 *   @0x17a10c .word 0xffffc024
 *
 * ══ §27/33 F_InstanceDeactivateRegionSpecial(RValue&, CInstance*, CInstance*, int, RValue*)  0x10b750  size 936  234 条（0x10b750..0x10baf8）
 * @func 0x10b750 0x10baf8  size 936  234 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×4 / YYGetBool(RValue const*, int)×2 / operator new(unsigned int)×2 / operator delete(void*)×2 / GetContextStackTop()×2 / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)×2 / GetActiveList(void (*)(CInstance*)) / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x60×7 / 0x70×7 / 0x8×6 / 0xc×5 / 0x36c×2 / 0x6c×2 / 0x7c×2 / 0x2b0×2
 * VFP 指令 11 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10b750 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x10b754 vpush {d8}
 *   @0x10b758 sub sp, sp, #12
 *   @0x10b75c mov r7, r1
 *   @0x10b760 mov r1, #4
 *   @0x10b764 ldr r4, [sp, #0x30]
 *   @0x10b768 ldr r5, [pc, #0x36c]
 *   @0x10b76c ldr r6, [pc, #0x36c]
 *   @0x10b770 mov r0, r4
 *   @0x10b774 add r5, pc, r5
 *   @0x10b778 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x10b77c mov r1, #0
 *   @0x10b780 add r6, pc, r6
 *   @0x10b784 strb r0, [r5, #0xc]
 *   @0x10b788 mov r0, r4
 *   @0x10b78c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10b790 mov r1, #1
 *   @0x10b794 str r0, [r5, #0x10]
 *   @0x10b798 mov r0, r4
 *   @0x10b79c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10b7a0 mov r1, #2
 *   @0x10b7a4 vldr s17, [r5, #16]
 *   @0x10b7a8 str r0, [r5, #0x14]
 *   @0x10b7ac mov r0, r4
 *   @0x10b7b0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10b7b4 mov r1, #3
 *   @0x10b7b8 vldr s16, [r5, #20]
 *   @0x10b7bc vmov s15, r0
 *   @0x10b7c0 mov r0, r4
 *   @0x10b7c4 vadd.f32 s17, s17, s15
 *   @0x10b7c8 vstr s17, [r5, #24]
 *   @0x10b7cc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10b7d0 vmov s15, r0
 *   @0x10b7d4 mov r0, #16
 *   @0x10b7d8 vadd.f32 s16, s16, s15
 *   @0x10b7dc vstr s16, [r5, #28]
 *   @0x10b7e0 bl 0x27c524 <_Znwj>
 *   @0x10b7e4 mvn r3, #-16777216
 *   @0x10b7e8 str r3, [r0, #0xc]
 *   @0x10b7ec mov r5, r0
 *   @0x10b7f0 ldr r3, [r4, #0x6c]
 *   @0x10b7f4 bic r2, r3, #-16777216
 *   @0x10b7f8 cmp r2, #2
 *   @0x10b7fc beq 0x10b93c <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x1ec>
 *   @0x10b800 ldr r3, [pc, #0x2dc]
 *   @0x10b804 mov r0, #16
 *   @0x10b808 ldr r8, [r6, r3]
 *   @0x10b80c str r5, [r8]
 *   @0x10b810 bl 0x27c524 <_Znwj>
 *   @0x10b814 mvn r3, #-16777216
 *   @0x10b818 str r3, [r0, #0xc]
 *   @0x10b81c mov r5, r0
 *   @0x10b820 ldr r3, [r4, #0x7c]
 *   @0x10b824 bic r2, r3, #-16777216
 *   @0x10b828 cmp r2, #2
 *   @0x10b82c beq 0x10b8d8 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x188>
 *   @0x10b830 ldr r2, [pc, #0x2b0]
 *   @0x10b834 ldr r3, [pc, #0x2b0]
 *   @0x10b838 ldr r9, [r6, r2]
 *   @0x10b83c str r5, [r9]
 *   @0x10b840 ldr r0, [r6, r3]
 *   @0x10b844 bl 0x10b24c <_Z13GetActiveListPFvP9CInstanceE>
 *   @0x10b848 ldr r0, [r8]
 *   @0x10b84c bl 0x27d1d0 <_ZdlPv>
 *   @0x10b850 ldr r0, [r9]
 *   @0x10b854 bl 0x27d1d0 <_ZdlPv>
 *   @0x10b858 mov r0, r4
 *   @0x10b85c mov r1, #5
 *   @0x10b860 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x10b864 cmp r7, #0
 *   @0x10b868 moveq r0, #0
 *   @0x10b86c andne r0, r0, #1
 *   @0x10b870 cmp r0, #0
 *   @0x10b874 beq 0x10b8cc <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x17c>
 *   @0x10b878 ldrb r3, [r7, #0x68]
 *   @0x10b87c cmp r3, #0
 *   @0x10b880 bne 0x10b8cc <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x17c>
 *   @0x10b884 ldrb r2, [r7, #0x69]
 *   @0x10b888 cmp r2, #0
 *   @0x10b88c beq 0x10b8cc <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x17c>
 *   @0x10b890 ldr r2, [pc, #0x258]
 *   @0x10b894 ldr r4, [r6, r2]
 *   @0x10b898 ldmib r4, {r2, r12}
 *   @0x10b89c cmp r12, r2
 *   @0x10b8a0 beq 0x10baa8 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x358>
 *   @0x10b8a4 ldr r3, [r4]
 *   @0x10b8a8 str r7, [r3, r12, lsl #2]
 *   @0x10b8ac mov r0, r7
 *   @0x10b8b0 add r12, r12, #1
 *   @0x10b8b4 mov r1, #0
 *   @0x10b8b8 str r12, [r4, #0x8]
 *   @0x10b8bc add sp, sp, #12
 *   @0x10b8c0 vpop {d8}
 *   @0x10b8c4 pop {r4, r5, r6, r7, r8, r9, lr}
 *   @0x10b8c8 b 0x19230c <_ZN9CInstance14SetDeactivatedEb>
 *   @0x10b8cc add sp, sp, #12
 *   @0x10b8d0 vpop {d8}
 *   @0x10b8d4 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x10b8d8 ldr r2, [r4, #0x78]
 *   @0x10b8dc mov r1, #0
 *   @0x10b8e0 str r3, [r0, #0xc]
 *   @0x10b8e4 ldr r3, [r4, #0x7c]
 *   @0x10b8e8 str r1, [r0]
 *   @0x10b8ec bic r3, r3, #-16777216
 *   @0x10b8f0 str r2, [r0, #0x8]
 *   @0x10b8f4 cmp r3, #14
 *   @0x10b8f8 addls pc, pc, r3, lsl #2
 *   @0x10b8fc b 0x10b830 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x10b900 b 0x10b9b8 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x268>
 *   @0x10b904 b 0x10ba90 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x340>
 *   @0x10b908 b 0x10ba64 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x314>
 *   @0x10b90c b 0x10b9ac <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x25c>
 *   @0x10b910 b 0x10b830 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x10b914 b 0x10b830 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x10b918 b 0x10b9d8 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x288>
 *   @0x10b91c b 0x10b9ac <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x25c>
 *   @0x10b920 b 0x10b830 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x10b924 b 0x10b830 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x10b928 b 0x10b9b8 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x268>
 *   @0x10b92c b 0x10b830 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x10b930 b 0x10b830 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x10b934 b 0x10b9b8 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x268>
 *   @0x10b938 b 0x10b9ac <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x25c>
 *   @0x10b93c ldr r2, [r4, #0x68]
 *   @0x10b940 mov r1, #0
 *   @0x10b944 str r3, [r0, #0xc]
 *   @0x10b948 ldr r3, [r4, #0x6c]
 *   @0x10b94c str r1, [r0]
 *   @0x10b950 bic r3, r3, #-16777216
 *   @0x10b954 str r2, [r0, #0x8]
 *   @0x10b958 cmp r3, #14
 *   @0x10b95c addls pc, pc, r3, lsl #2
 *   @0x10b960 b 0x10b800 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0x10b964 b 0x10b9c8 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x278>
 *   @0x10b968 b 0x10b9fc <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x2ac>
 *   @0x10b96c b 0x10ba14 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x2c4>
 *   @0x10b970 b 0x10b9a0 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x250>
 *   @0x10b974 b 0x10b800 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0x10b978 b 0x10b800 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0x10b97c b 0x10ba40 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x2f0>
 *   @0x10b980 b 0x10b9a0 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x250>
 *   @0x10b984 b 0x10b800 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0x10b988 b 0x10b800 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0x10b98c b 0x10b9c8 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x278>
 *   @0x10b990 b 0x10b800 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0x10b994 b 0x10b800 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0x10b998 b 0x10b9c8 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x278>
 *   @0x10b99c b 0x10b9a0 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x250>
 *   @0x10b9a0 ldr r3, [r4, #0x60]
 *   @0x10b9a4 str r3, [r5]
 *   @0x10b9a8 b 0x10b800 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0x10b9ac ldr r3, [r4, #0x70]
 *   @0x10b9b0 str r3, [r5]
 *   @0x10b9b4 b 0x10b830 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x10b9b8 ldr r2, [r4, #0x70]
 *   @0x10b9bc ldr r3, [r4, #0x74]
 *   @0x10b9c0 stm r0, {r2, r3}
 *   @0x10b9c4 b 0x10b830 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x10b9c8 ldr r2, [r4, #0x60]
 *   @0x10b9cc ldr r3, [r4, #0x64]
 *   @0x10b9d0 stm r0, {r2, r3}
 *   @0x10b9d4 b 0x10b800 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0x10b9d8 ldr r3, [r4, #0x70]
 *   @0x10b9dc str r3, [r0]
 *   @0x10b9e0 ldr r3, [r4, #0x70]
 *   @0x10b9e4 cmp r3, #0
 *   @0x10b9e8 beq 0x10b830 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x10b9ec bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x10b9f0 ldr r1, [r4, #0x70]
 *   @0x10b9f4 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x10b9f8 b 0x10b830 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x10b9fc ldr r3, [r4, #0x60]
 *   @0x10ba00 cmp r3, #0
 *   @0x10ba04 ldrne r2, [r3, #0x4]
 *   @0x10ba08 addne r2, r2, #1
 *   @0x10ba0c strne r2, [r3, #0x4]
 *   @0x10ba10 b 0x10b9a4 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x254>
 *   @0x10ba14 ldr r3, [r4, #0x60]
 *   @0x10ba18 cmp r3, #0
 *   @0x10ba1c str r3, [r0]
 *   @0x10ba20 beq 0x10b800 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0x10ba24 ldr r1, [r3, #0x8]
 *   @0x10ba28 ldr r2, [r3]
 *   @0x10ba2c cmp r1, #0
 *   @0x10ba30 streq r0, [r3, #0x8]
 *   @0x10ba34 add r2, r2, #1
 *   @0x10ba38 str r2, [r3]
 *   @0x10ba3c b 0x10b800 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0x10ba40 ldr r3, [r4, #0x60]
 *   @0x10ba44 str r3, [r0]
 *   @0x10ba48 ldr r3, [r4, #0x60]
 *   @0x10ba4c cmp r3, #0
 *   @0x10ba50 beq 0x10b800 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0x10ba54 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x10ba58 ldr r1, [r4, #0x60]
 *   @0x10ba5c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x10ba60 b 0x10b800 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0x10ba64 ldr r3, [r4, #0x70]
 *   @0x10ba68 cmp r3, #0
 *   @0x10ba6c str r3, [r0]
 *   @0x10ba70 beq 0x10b830 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x10ba74 ldr r1, [r3, #0x8]
 *   @0x10ba78 ldr r2, [r3]
 *   @0x10ba7c cmp r1, #0
 *   @0x10ba80 streq r0, [r3, #0x8]
 *   @0x10ba84 add r2, r2, #1
 *   @0x10ba88 str r2, [r3]
 *   @0x10ba8c b 0x10b830 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x10ba90 ldr r3, [r4, #0x70]
 *   @0x10ba94 cmp r3, #0
 *   @0x10ba98 ldrne r2, [r3, #0x4]
 *   @0x10ba9c addne r2, r2, #1
 *   @0x10baa0 strne r2, [r3, #0x4]
 *   @0x10baa4 b 0x10b9b0 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x260>
 *   @0x10baa8 ldr r2, [pc, #0x44]
 *   @0x10baac lsl r1, r12, #3
 *   @0x10bab0 ldr r0, [r4]
 *   @0x10bab4 lsl r12, r12, #1
 *   @0x10bab8 str r3, [sp]
 *   @0x10babc add r2, pc, r2
 *   @0x10bac0 mov r3, #74
 *   @0x10bac4 str r12, [r4, #0x4]
 *   @0x10bac8 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x10bacc ldr r12, [r4, #0x8]
 *   @0x10bad0 mov r3, r0
 *   @0x10bad4 str r0, [r4]
 *   @0x10bad8 b 0x10b8a8 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x158>
 *   @0x10badc eorseq r7, r7, r4, ror #30
 *   @0x10bae0 .word 0x002e64d0
 *   @0x10bae4 .word 0xffffc460
 *   @0x10bae8 .word 0xffffc45c
 *   @0x10baec .word 0xffffc470
 *   @0x10baf0 .word 0xffffbff8
 *   @0x10baf4 eoreq r5, r2, r4, ror r5
 *
 * ══ §28/33 vorbis_book_decodev_add  0x228754  size 936  234 条（0x228754..0x228afc）
 * @func 0x228754 0x228afc  size 936  234 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: oggpack_adv×6 / oggpack_look×4 / vorbis_book_decodev_add+0x1a4×3 / vorbis_book_decodev_add+0x398×2 / vorbis_book_decodev_add+0x1d8 / vorbis_book_decodev_add+0x144 / vorbis_book_decodev_add+0x19c / vorbis_book_decodev_add+0x38c
 * 字段偏移 top8: 0x4×7 / 0x8×5 / 0x2×4 / 0x1c×4 / 0x24×2 / 0x28×2 / 0x20×2 / 0x14×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x228754 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x228758 sub sp, sp, #12
 *   @0x22875c mov r8, r0
 *   @0x228760 mov r6, r2
 *   @0x228764 str r1, [sp, #0x4]
 *   @0x228768 mov r10, r3
 *   @0x22876c ldr r1, [r0, #0x8]
 *   @0x228770 cmp r1, #0
 *   @0x228774 ble 0x2288f8 <vorbis_book_decodev_add+0x1a4>
 *   @0x228778 ldr r7, [r0, #0xc]
 *   @0x22877c ldr r1, [sp, #0x30]
 *   @0x228780 subs r7, r1, r7
 *   @0x228784 bmi 0x228948 <vorbis_book_decodev_add+0x1f4>
 *   @0x228788 cmp r3, #0
 *   @0x22878c ble 0x2288f8 <vorbis_book_decodev_add+0x1a4>
 *   @0x228790 mov r9, #0
 *   @0x228794 mov r0, r6
 *   @0x228798 ldr r1, [r8, #0x24]
 *   @0x22879c ldr r4, [r8, #0x28]
 *   @0x2287a0 bl 0x23388c <oggpack_look>
 *   @0x2287a4 cmp r0, #0
 *   @0x2287a8 blt 0x22892c <vorbis_book_decodev_add+0x1d8>
 *   @0x2287ac ldr r3, [r8, #0x20]
 *   @0x2287b0 ldr r5, [r3, r0, lsl #2]
 *   @0x2287b4 cmp r5, #0
 *   @0x2287b8 bge 0x228904 <vorbis_book_decodev_add+0x1b0>
 *   @0x2287bc ldr r2, [r8, #0x8]
 *   @0x2287c0 ubfx r3, r5, #0x0, #0xf
 *   @0x2287c4 ubfx r5, r5, #0xf, #0xf
 *   @0x2287c8 rsb r11, r3, r2
 *   @0x2287cc b 0x2287d4 <vorbis_book_decodev_add+0x80>
 *   @0x2287d0 sub r4, r4, #1
 *   @0x2287d4 mov r0, r6
 *   @0x2287d8 mov r1, r4
 *   @0x2287dc bl 0x23388c <oggpack_look>
 *   @0x2287e0 cmp r4, #1
 *   @0x2287e4 movle r3, #0
 *   @0x2287e8 movgt r3, #1
 *   @0x2287ec ands r3, r3, r0, lsr #31
 *   @0x2287f0 bne 0x2287d0 <vorbis_book_decodev_add+0x7c>
 *   @0x2287f4 cmp r0, #0
 *   @0x2287f8 blt 0x228aec <vorbis_book_decodev_add+0x398>
 *   @0x2287fc rev r0, r0
 *   @0x228800 movw r3, #0xf0f
 *   @0x228804 movw r1, #0xf0f0
 *   @0x228808 bfi r3, r3, #16, #16
 *   @0x22880c bfi r1, r1, #16, #16
 *   @0x228810 and r3, r3, r0, lsr #4
 *   @0x228814 and r0, r1, r0, lsl #4
 *   @0x228818 movw r1, #0x3333
 *   @0x22881c orr r0, r0, r3
 *   @0x228820 bfi r1, r1, #16, #16
 *   @0x228824 movw r3, #0xcccc
 *   @0x228828 bfi r3, r3, #16, #16
 *   @0x22882c and r1, r1, r0, lsr #2
 *   @0x228830 and r3, r3, r0, lsl #2
 *   @0x228834 orr r12, r3, r1
 *   @0x228838 rsb r3, r5, r11
 *   @0x22883c movw r0, #0xaaaa
 *   @0x228840 movw r1, #0x5555
 *   @0x228844 bfi r0, r0, #16, #16
 *   @0x228848 bfi r1, r1, #16, #16
 *   @0x22884c cmp r3, #1
 *   @0x228850 and r0, r0, r12, lsl #1
 *   @0x228854 and r1, r1, r12, lsr #1
 *   @0x228858 orr r0, r0, r1
 *   @0x22885c ble 0x228898 <vorbis_book_decodev_add+0x144>
 *   @0x228860 ldr r12, [r8, #0x14]
 *   @0x228864 asr r3, r3, #1
 *   @0x228868 add r1, r3, r5
 *   @0x22886c ldr r1, [r12, r1, lsl #2]
 *   @0x228870 cmp r1, r0
 *   @0x228874 movls lr, r3
 *   @0x228878 movhi lr, #0
 *   @0x22887c cmp r1, r0
 *   @0x228880 add r5, r5, lr
 *   @0x228884 movls r3, #0
 *   @0x228888 rsb r11, r3, r11
 *   @0x22888c rsb r3, r5, r11
 *   @0x228890 cmp r3, #1
 *   @0x228894 bgt 0x228864 <vorbis_book_decodev_add+0x110>
 *   @0x228898 ldr r3, [r8, #0x1c]
 *   @0x22889c mov r0, r6
 *   @0x2288a0 ldrb r1, [r3, r5]
 *   @0x2288a4 cmp r1, r4
 *   @0x2288a8 bgt 0x228938 <vorbis_book_decodev_add+0x1e4>
 *   @0x2288ac bl 0x233a7c <oggpack_adv>
 *   @0x2288b0 ldr r12, [r8]
 *   @0x2288b4 ldr r3, [r8, #0x10]
 *   @0x2288b8 cmp r12, #0
 *   @0x2288bc mul r5, r5, r12
 *   @0x2288c0 add r5, r3, r5, lsl #2
 *   @0x2288c4 ble 0x2288f0 <vorbis_book_decodev_add+0x19c>
 *   @0x2288c8 ldr r2, [sp, #0x4]
 *   @0x2288cc add r0, r5, r12, lsl #2
 *   @0x2288d0 add r3, r2, r9, lsl #2
 *   @0x2288d4 ldr r1, [r5], #4
 *   @0x2288d8 ldr r2, [r3]
 *   @0x2288dc cmp r5, r0
 *   @0x2288e0 add r2, r2, r1, asr r7
 *   @0x2288e4 str r2, [r3], #4
 *   @0x2288e8 bne 0x2288d4 <vorbis_book_decodev_add+0x180>
 *   @0x2288ec add r9, r9, r12
 *   @0x2288f0 cmp r10, r9
 *   @0x2288f4 bgt 0x228794 <vorbis_book_decodev_add+0x40>
 *   @0x2288f8 mov r0, #0
 *   @0x2288fc add sp, sp, #12
 *   @0x228900 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x228904 ldr r3, [r8, #0x1c]
 *   @0x228908 mov r0, r6
 *   @0x22890c add r3, r3, r5
 *   @0x228910 ldrb r1, [r3, #-0x1]
 *   @0x228914 bl 0x233a7c <oggpack_adv>
 *   @0x228918 subs r5, r5, #1
 *   @0x22891c bhs 0x2288b0 <vorbis_book_decodev_add+0x15c>
 *   @0x228920 mvn r0, #0
 *   @0x228924 add sp, sp, #12
 *   @0x228928 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x22892c ldr r11, [r8, #0x8]
 *   @0x228930 mov r5, #0
 *   @0x228934 b 0x2287d4 <vorbis_book_decodev_add+0x80>
 *   @0x228938 add r1, r4, #1
 *   @0x22893c bl 0x233a7c <oggpack_adv>
 *   @0x228940 mvn r0, #0
 *   @0x228944 b 0x228924 <vorbis_book_decodev_add+0x1d0>
 *   @0x228948 cmp r3, #0
 *   @0x22894c movgt r9, #0
 *   @0x228950 ble 0x2288f8 <vorbis_book_decodev_add+0x1a4>
 *   @0x228954 mov r0, r6
 *   @0x228958 ldr r1, [r8, #0x24]
 *   @0x22895c ldr r4, [r8, #0x28]
 *   @0x228960 bl 0x23388c <oggpack_look>
 *   @0x228964 cmp r0, #0
 *   @0x228968 blt 0x228ae0 <vorbis_book_decodev_add+0x38c>
 *   @0x22896c ldr r3, [r8, #0x20]
 *   @0x228970 ldr r5, [r3, r0, lsl #2]
 *   @0x228974 cmp r5, #0
 *   @0x228978 bge 0x228ac0 <vorbis_book_decodev_add+0x36c>
 *   @0x22897c ldr r2, [r8, #0x8]
 *   @0x228980 ubfx r3, r5, #0x0, #0xf
 *   @0x228984 ubfx r5, r5, #0xf, #0xf
 *   @0x228988 rsb r11, r3, r2
 *   @0x22898c b 0x228994 <vorbis_book_decodev_add+0x240>
 *   @0x228990 sub r4, r4, #1
 *   @0x228994 mov r0, r6
 *   @0x228998 mov r1, r4
 *   @0x22899c bl 0x23388c <oggpack_look>
 *   @0x2289a0 cmp r4, #1
 *   @0x2289a4 movle r3, #0
 *   @0x2289a8 movgt r3, #1
 *   @0x2289ac ands r3, r3, r0, lsr #31
 *   @0x2289b0 bne 0x228990 <vorbis_book_decodev_add+0x23c>
 *   @0x2289b4 cmp r0, #0
 *   @0x2289b8 blt 0x228aec <vorbis_book_decodev_add+0x398>
 *   @0x2289bc rev r0, r0
 *   @0x2289c0 movw r1, #0xf0f
 *   @0x2289c4 movw r3, #0xf0f0
 *   @0x2289c8 bfi r1, r1, #16, #16
 *   @0x2289cc bfi r3, r3, #16, #16
 *   @0x2289d0 and r12, r1, r0, lsr #4
 *   @0x2289d4 and r0, r3, r0, lsl #4
 *   @0x2289d8 movw r1, #0x3333
 *   @0x2289dc orr r0, r0, r12
 *   @0x2289e0 bfi r1, r1, #16, #16
 *   @0x2289e4 movw r3, #0xcccc
 *   @0x2289e8 bfi r3, r3, #16, #16
 *   @0x2289ec and r1, r1, r0, lsr #2
 *   @0x2289f0 and r3, r3, r0, lsl #2
 *   @0x2289f4 orr r12, r3, r1
 *   @0x2289f8 rsb r3, r5, r11
 *   @0x2289fc movw r0, #0xaaaa
 *   @0x228a00 movw r1, #0x5555
 *   @0x228a04 bfi r0, r0, #16, #16
 *   @0x228a08 bfi r1, r1, #16, #16
 *   @0x228a0c cmp r3, #1
 *   @0x228a10 and r0, r0, r12, lsl #1
 *   @0x228a14 and r1, r1, r12, lsr #1
 *   @0x228a18 orr r0, r0, r1
 *   @0x228a1c ble 0x228a58 <vorbis_book_decodev_add+0x304>
 *   @0x228a20 ldr r12, [r8, #0x14]
 *   @0x228a24 asr r3, r3, #1
 *   @0x228a28 add r1, r3, r5
 *   @0x228a2c ldr r1, [r12, r1, lsl #2]
 *   @0x228a30 cmp r1, r0
 *   @0x228a34 movls lr, r3
 *   @0x228a38 movhi lr, #0
 *   @0x228a3c cmp r1, r0
 *   @0x228a40 add r5, r5, lr
 *   @0x228a44 movls r3, #0
 *   @0x228a48 rsb r11, r3, r11
 *   @0x228a4c rsb r3, r5, r11
 *   @0x228a50 cmp r3, #1
 *   @0x228a54 bgt 0x228a24 <vorbis_book_decodev_add+0x2d0>
 *   @0x228a58 ldr r3, [r8, #0x1c]
 *   @0x228a5c mov r0, r6
 *   @0x228a60 ldrb r1, [r3, r5]
 *   @0x228a64 cmp r1, r4
 *   @0x228a68 bgt 0x228938 <vorbis_book_decodev_add+0x1e4>
 *   @0x228a6c bl 0x233a7c <oggpack_adv>
 *   @0x228a70 ldr r4, [r8]
 *   @0x228a74 ldr r3, [r8, #0x10]
 *   @0x228a78 cmp r4, #0
 *   @0x228a7c mul r5, r5, r4
 *   @0x228a80 add r3, r3, r5, lsl #2
 *   @0x228a84 ble 0x228ab4 <vorbis_book_decodev_add+0x360>
 *   @0x228a88 ldr r1, [sp, #0x4]
 *   @0x228a8c rsb r12, r7, #0
 *   @0x228a90 add r0, r3, r4, lsl #2
 *   @0x228a94 add r2, r1, r9, lsl #2
 *   @0x228a98 ldr r5, [r3], #4
 *   @0x228a9c ldr r1, [r2]
 *   @0x228aa0 cmp r3, r0
 *   @0x228aa4 add r1, r1, r5, lsl r12
 *   @0x228aa8 str r1, [r2], #4
 *   @0x228aac bne 0x228a98 <vorbis_book_decodev_add+0x344>
 *   @0x228ab0 add r9, r9, r4
 *   @0x228ab4 cmp r10, r9
 *   @0x228ab8 bgt 0x228954 <vorbis_book_decodev_add+0x200>
 *   @0x228abc b 0x2288f8 <vorbis_book_decodev_add+0x1a4>
 *   @0x228ac0 ldr r3, [r8, #0x1c]
 *   @0x228ac4 mov r0, r6
 *   @0x228ac8 add r3, r3, r5
 *   @0x228acc ldrb r1, [r3, #-0x1]
 *   @0x228ad0 bl 0x233a7c <oggpack_adv>
 *   @0x228ad4 subs r5, r5, #1
 *   @0x228ad8 bhs 0x228a70 <vorbis_book_decodev_add+0x31c>
 *   @0x228adc b 0x228920 <vorbis_book_decodev_add+0x1cc>
 *   @0x228ae0 ldr r11, [r8, #0x8]
 *   @0x228ae4 mov r5, #0
 *   @0x228ae8 b 0x228994 <vorbis_book_decodev_add+0x240>
 *   @0x228aec mov r0, r6
 *   @0x228af0 mov r1, #1
 *   @0x228af4 bl 0x233a7c <oggpack_adv>
 *   @0x228af8 b 0x228920 <vorbis_book_decodev_add+0x1cc>
 *
 * ══ §29/33 Sound_Load(unsigned char*, unsigned int, unsigned char*)  0x21f630  size 932  233 条（0x21f630..0x21f9d4）
 * @func 0x21f630 0x21f9d4  size 932  233 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×6 / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)×2 / Sound_Load(unsigned char*, unsigned int, unsigned char*)+0xf4 / CSound::~CSound() / operator delete(void*) / Sound_Load(unsigned char*, unsigned int, unsigned char*)+0x88 / Sound_Load(unsigned char*, unsigned int, unsigned char*)+0x1b4 / MemoryManager::IsAllocated(void const*)
 * 字段偏移 top8: 0xc×17 / 0x4×8 / 0x8×5 / 0x10×4 / 0x2×4 / 0x340×2 / 0x14×2 / 0x34c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21f630 ldr r3, [pc, #0x34c]
 *   @0x21f634 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x21f638 ldr r3, [pc, r3]
 *   @0x21f63c sub sp, sp, #28
 *   @0x21f640 ldr r1, [pc, #0x340]
 *   @0x21f644 ldr r6, [pc, #0x340]
 *   @0x21f648 str r0, [sp, #0xc]
 *   @0x21f64c add r1, pc, r1
 *   @0x21f650 ldr r0, [r3]
 *   @0x21f654 add r6, pc, r6
 *   @0x21f658 str r2, [sp, #0x10]
 *   @0x21f65c ldr r3, [r0]
 *   @0x21f660 ldr r3, [r3, #0xc]
 *   @0x21f664 blx r3
 *   @0x21f668 ldr r3, [sp, #0xc]
 *   @0x21f66c ldr r2, [r6]
 *   @0x21f670 ldr r9, [r3]
 *   @0x21f674 cmp r9, r2
 *   @0x21f678 str r9, [r6, #0x10]
 *   @0x21f67c moveq r6, r9
 *   @0x21f680 beq 0x21f76c <_Z10Sound_LoadPhjS_+0x13c>
 *   @0x21f684 cmp r9, #0
 *   @0x21f688 ldr r3, [r6, #0x4]
 *   @0x21f68c bne 0x21f740 <_Z10Sound_LoadPhjS_+0x110>
 *   @0x21f690 cmp r3, #0
 *   @0x21f694 beq 0x21f740 <_Z10Sound_LoadPhjS_+0x110>
 *   @0x21f698 cmp r2, #0
 *   @0x21f69c ble 0x21f724 <_Z10Sound_LoadPhjS_+0xf4>
 *   @0x21f6a0 ldr r10, [pc, #0x2e8]
 *   @0x21f6a4 mov r4, r9
 *   @0x21f6a8 ldr r8, [pc, #0x2e4]
 *   @0x21f6ac mov r7, r9
 *   @0x21f6b0 add r10, pc, r10
 *   @0x21f6b4 add r8, pc, r8
 *   @0x21f6b8 ldr r0, [r3]
 *   @0x21f6bc movw r2, #0xfeee
 *   @0x21f6c0 movt r2, #0xfeee
 *   @0x21f6c4 movw r1, #0xfeee
 *   @0x21f6c8 cmp r0, r2
 *   @0x21f6cc movt r1, #0xfeee
 *   @0x21f6d0 lsl r11, r4, #2
 *   @0x21f6d4 beq 0x21f714 <_Z10Sound_LoadPhjS_+0xe4>
 *   @0x21f6d8 ldr r5, [r3, r4, lsl #2]
 *   @0x21f6dc add r2, r3, r11
 *   @0x21f6e0 cmp r5, #0
 *   @0x21f6e4 mov r0, r5
 *   @0x21f6e8 beq 0x21f714 <_Z10Sound_LoadPhjS_+0xe4>
 *   @0x21f6ec ldr r3, [r5]
 *   @0x21f6f0 cmp r3, r1
 *   @0x21f6f4 beq 0x21f70c <_Z10Sound_LoadPhjS_+0xdc>
 *   @0x21f6f8 bl 0x215384 <_ZN6CSoundD2Ev>
 *   @0x21f6fc mov r0, r5
 *   @0x21f700 bl 0x27d1d0 <_ZdlPv>
 *   @0x21f704 ldr r2, [r8, #0x4]
 *   @0x21f708 add r2, r2, r11
 *   @0x21f70c str r7, [r2]
 *   @0x21f710 ldr r3, [r10, #0x4]
 *   @0x21f714 ldr r2, [r6]
 *   @0x21f718 add r4, r4, #1
 *   @0x21f71c cmp r4, r2
 *   @0x21f720 blt 0x21f6b8 <_Z10Sound_LoadPhjS_+0x88>
 *   @0x21f724 mov r0, r3
 *   @0x21f728 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x21f72c ldr r3, [pc, #0x264]
 *   @0x21f730 mov r2, #0
 *   @0x21f734 add r3, pc, r3
 *   @0x21f738 str r2, [r3, #0x4]
 *   @0x21f73c b 0x21f75c <_Z10Sound_LoadPhjS_+0x12c>
 *   @0x21f740 lsls r4, r9, #2
 *   @0x21f744 mov r0, r3
 *   @0x21f748 bne 0x21f950 <_Z10Sound_LoadPhjS_+0x320>
 *   @0x21f74c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x21f750 ldr r3, [pc, #0x244]
 *   @0x21f754 add r3, pc, r3
 *   @0x21f758 str r4, [r3, #0x4]
 *   @0x21f75c ldr r3, [pc, #0x23c]
 *   @0x21f760 add r3, pc, r3
 *   @0x21f764 ldr r6, [r3, #0x10]
 *   @0x21f768 str r9, [r3]
 *   @0x21f76c cmp r6, #0
 *   @0x21f770 bne 0x21f8ec <_Z10Sound_LoadPhjS_+0x2bc>
 *   @0x21f774 ldr r3, [pc, #0x228]
 *   @0x21f778 add r3, pc, r3
 *   @0x21f77c ldr r0, [r3, #0xc]
 *   @0x21f780 cmp r0, #0
 *   @0x21f784 beq 0x21f92c <_Z10Sound_LoadPhjS_+0x2fc>
 *   @0x21f788 ldr r2, [r3, #0x8]
 *   @0x21f78c cmp r2, #0
 *   @0x21f790 ble 0x21f7e4 <_Z10Sound_LoadPhjS_+0x1b4>
 *   @0x21f794 ldr r10, [pc, #0x20c]
 *   @0x21f798 mov r8, r3
 *   @0x21f79c mov r4, r6
 *   @0x21f7a0 mov r7, r6
 *   @0x21f7a4 add r10, pc, r10
 *   @0x21f7a8 ldr r0, [r0, r4, lsl #2]
 *   @0x21f7ac lsl r5, r4, #2
 *   @0x21f7b0 bl 0x27c454 <_ZN13MemoryManager11IsAllocatedEPKv>
 *   @0x21f7b4 cmp r0, #0
 *   @0x21f7b8 beq 0x21f7c8 <_Z10Sound_LoadPhjS_+0x198>
 *   @0x21f7bc ldr r3, [r10, #0xc]
 *   @0x21f7c0 ldr r0, [r3, r4, lsl #2]
 *   @0x21f7c4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x21f7c8 ldr r2, [r8, #0x8]
 *   @0x21f7cc add r4, r4, #1
 *   @0x21f7d0 ldr r3, [r8, #0xc]
 *   @0x21f7d4 cmp r4, r2
 *   @0x21f7d8 str r7, [r3, r5]
 *   @0x21f7dc ldr r0, [r8, #0xc]
 *   @0x21f7e0 blt 0x21f7a8 <_Z10Sound_LoadPhjS_+0x178>
 *   @0x21f7e4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x21f7e8 ldr r3, [pc, #0x1bc]
 *   @0x21f7ec mov r2, #0
 *   @0x21f7f0 add r3, pc, r3
 *   @0x21f7f4 str r2, [r3, #0xc]
 *   @0x21f7f8 ldr r10, [pc, #0x1b0]
 *   @0x21f7fc cmp r9, #0
 *   @0x21f800 add r10, pc, r10
 *   @0x21f804 str r6, [r10, #0x8]
 *   @0x21f808 beq 0x21f944 <_Z10Sound_LoadPhjS_+0x314>
 *   @0x21f80c ldr r3, [pc, #0x1a0]
 *   @0x21f810 mov r7, r10
 *   @0x21f814 ldr r8, [sp, #0xc]
 *   @0x21f818 mov r4, #0
 *   @0x21f81c add r3, pc, r3
 *   @0x21f820 str r9, [sp, #0xc]
 *   @0x21f824 str r3, [sp, #0x14]
 *   @0x21f828 b 0x21f8d8 <_Z10Sound_LoadPhjS_+0x2a8>
 *   @0x21f82c ldr r9, [pc, #0x184]
 *   @0x21f830 ldr r9, [pc, r9]
 *   @0x21f834 ldr r11, [r9]
 *   @0x21f838 adds r1, r11, r5
 *   @0x21f83c beq 0x21f97c <_Z10Sound_LoadPhjS_+0x34c>
 *   @0x21f840 mov r0, #64
 *   @0x21f844 str r1, [sp, #0x8]
 *   @0x21f848 bl 0x27c524 <_Znwj>
 *   @0x21f84c mov r6, r0
 *   @0x21f850 bl 0x215354 <_ZN6CSoundC2Ev>
 *   @0x21f854 ldr r1, [sp, #0x8]
 *   @0x21f858 mov r0, r6
 *   @0x21f85c ldr r2, [sp, #0x10]
 *   @0x21f860 bl 0x215498 <_ZN6CSound13LoadFromChunkEP7YYSoundPh>
 *   @0x21f864 ldr r12, [r11, r5]
 *   @0x21f868 cmp r12, #0
 *   @0x21f86c ldrne r3, [r9]
 *   @0x21f870 moveq r11, r12
 *   @0x21f874 addne r11, r3, r12
 *   @0x21f878 mov r0, r11
 *   @0x21f87c bl 0xb6538 <strlen@plt>
 *   @0x21f880 ldr r1, [sp, #0x14]
 *   @0x21f884 mov r3, #1
 *   @0x21f888 mov r2, #95
 *   @0x21f88c add r0, r0, r3
 *   @0x21f890 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x21f894 mov r1, r11
 *   @0x21f898 mov r5, r0
 *   @0x21f89c bl 0xb65a4 <strcpy@plt>
 *   @0x21f8a0 ldr r2, [r10, #0xc]
 *   @0x21f8a4 lsl r11, r4, #2
 *   @0x21f8a8 ldr r0, [r2, r4, lsl #2]
 *   @0x21f8ac cmp r0, #0
 *   @0x21f8b0 beq 0x21f8b8 <_Z10Sound_LoadPhjS_+0x288>
 *   @0x21f8b4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x21f8b8 ldr r2, [r7, #0x4]
 *   @0x21f8bc add r4, r4, #1
 *   @0x21f8c0 ldr r3, [sp, #0xc]
 *   @0x21f8c4 str r6, [r2, r11]
 *   @0x21f8c8 cmp r4, r3
 *   @0x21f8cc ldr r2, [r7, #0xc]
 *   @0x21f8d0 str r5, [r2, r11]
 *   @0x21f8d4 beq 0x21f944 <_Z10Sound_LoadPhjS_+0x314>
 *   @0x21f8d8 ldr r5, [r8, #0x4]!
 *   @0x21f8dc cmp r5, #0
 *   @0x21f8e0 bne 0x21f82c <_Z10Sound_LoadPhjS_+0x1fc>
 *   @0x21f8e4 mov r6, r5
 *   @0x21f8e8 b 0x21f8a0 <_Z10Sound_LoadPhjS_+0x270>
 *   @0x21f8ec lsls r1, r6, #2
 *   @0x21f8f0 beq 0x21f920 <_Z10Sound_LoadPhjS_+0x2f0>
 *   @0x21f8f4 ldr r4, [pc, #0xc0]
 *   @0x21f8f8 mov r3, #0
 *   @0x21f8fc ldr r2, [pc, #0xbc]
 *   @0x21f900 add r4, pc, r4
 *   @0x21f904 str r3, [sp]
 *   @0x21f908 add r2, pc, r2
 *   @0x21f90c mov r3, #92
 *   @0x21f910 ldr r0, [r4, #0xc]
 *   @0x21f914 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x21f918 str r0, [r4, #0xc]
 *   @0x21f91c b 0x21f7f8 <_Z10Sound_LoadPhjS_+0x1c8>
 *   @0x21f920 ldr r3, [pc, #0x9c]
 *   @0x21f924 add r3, pc, r3
 *   @0x21f928 ldr r0, [r3, #0xc]
 *   @0x21f92c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x21f930 ldr r3, [pc, #0x90]
 *   @0x21f934 mov r2, #0
 *   @0x21f938 add r3, pc, r3
 *   @0x21f93c str r2, [r3, #0xc]
 *   @0x21f940 b 0x21f7f8 <_Z10Sound_LoadPhjS_+0x1c8>
 *   @0x21f944 mov r0, #1
 *   @0x21f948 add sp, sp, #28
 *   @0x21f94c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x21f950 ldr r2, [pc, #0x74]
 *   @0x21f954 mov r3, #0
 *   @0x21f958 mov r1, r4
 *   @0x21f95c str r3, [sp]
 *   @0x21f960 add r2, pc, r2
 *   @0x21f964 mov r3, #135
 *   @0x21f968 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x21f96c ldr r3, [pc, #0x5c]
 *   @0x21f970 add r3, pc, r3
 *   @0x21f974 str r0, [r3, #0x4]
 *   @0x21f978 b 0x21f75c <_Z10Sound_LoadPhjS_+0x12c>
 *   @0x21f97c mov r5, r1
 *   @0x21f980 b 0x21f8e4 <_Z10Sound_LoadPhjS_+0x2b4>
 *   @0x21f984 ldrsbeq lr, [r12], -r12
 *   @0x21f988 andseq r5, r3, r0, lsr r1
 *   @0x21f98c subseq r5, r3, r4, ror #25
 *   @0x21f990 subseq r5, r3, r8, lsl #25
 *   @0x21f994 subseq r5, r3, r4, lsl #25
 *   @0x21f998 subseq r5, r3, r4, lsl #24
 *   @0x21f99c subseq r5, r3, r4, ror #23
 *   @0x21f9a0 ldrsbeq r5, [r3], #-184
 *   @0x21f9a4 subseq r5, r3, r0, asr #23
 *   @0x21f9a8 .word 0x00535b94
 *   @0x21f9ac subseq r5, r3, r8, asr #22
 *   @0x21f9b0 subseq r5, r3, r8, lsr r11
 *   @0x21f9b4 ldrheq r4, [r3], -r0
 *   @0x21f9b8 andseq lr, r12, r4, lsl r1
 *   @0x21f9bc subseq r5, r3, r8, lsr r10
 *   @0x21f9c0 andseq r4, r3, r12, asr #8
 *   @0x21f9c4 subseq r5, r3, r4, lsl r10
 *   @0x21f9c8 subseq r5, r3, r0, lsl #20
 *   @0x21f9cc andseq r4, r3, r12, lsr #28
 *   @0x21f9d0 subseq r5, r3, r8, asr #19
 *
 * ══ §30/33 VirtualKeys_Serialise(IBuffer*)  0x18c698  size 928  232 条（0x18c698..0x18ca38）
 * @func 0x18c698 0x18ca38  size 928  232 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: VirtualKeys_Serialise(IBuffer*)+0x390
 * 字段偏移 top8: 0x8×15 / 0x30×14 / 0x38×14 / 0x4×7 / 0x388×1 / 0x2c×1 / 0x304×1 / 0x2×1
 * VFP 指令 52 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18c698 ldr r1, [r0]
 *   @0x18c69c mov r2, #38912
 *   @0x18c6a0 ldr r3, [pc, #0x388]
 *   @0x18c6a4 movt r2, #0x408a
 *   @0x18c6a8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x18c6ac add r8, r0, #44
 *   @0x18c6b0 sub sp, sp, #12
 *   @0x18c6b4 mov r7, #0
 *   @0x18c6b8 str r2, [r0, #0x30]
 *   @0x18c6bc mov r2, r8
 *   @0x18c6c0 str r7, [r0, #0x2c]
 *   @0x18c6c4 mov r6, r0
 *   @0x18c6c8 ldr r12, [r1, #0x8]
 *   @0x18c6cc mov r1, #6
 *   @0x18c6d0 str r7, [r0, #0x38]
 *   @0x18c6d4 str r3, [sp, #0x4]
 *   @0x18c6d8 blx r12
 *   @0x18c6dc ldr r3, [sp, #0x4]
 *   @0x18c6e0 ldr r12, [r6]
 *   @0x18c6e4 mov r2, r8
 *   @0x18c6e8 ldr r3, [pc, r3]
 *   @0x18c6ec vldr s15, [r3]
 *   @0x18c6f0 vcvt.f64.s32 d7, s15
 *   @0x18c6f4 str r7, [r6, #0x38]
 *   @0x18c6f8 mov r0, r6
 *   @0x18c6fc mov r1, #6
 *   @0x18c700 vmov r4, r5, d7
 *   @0x18c704 vstr s14, [r6, #44]
 *   @0x18c708 str r5, [r6, #0x30]
 *   @0x18c70c ldr r12, [r12, #0x8]
 *   @0x18c710 str r3, [sp, #0x4]
 *   @0x18c714 blx r12
 *   @0x18c718 ldr r3, [sp, #0x4]
 *   @0x18c71c ldr r2, [r3]
 *   @0x18c720 cmp r2, r7
 *   @0x18c724 ble 0x18ca28 <_Z21VirtualKeys_SerialiseP7IBuffer+0x390>
 *   @0x18c728 ldr r9, [pc, #0x304]
 *   @0x18c72c mov r11, r7
 *   @0x18c730 mov r10, r7
 *   @0x18c734 ldr r9, [pc, r9]
 *   @0x18c738 ldr lr, [r9]
 *   @0x18c73c mov r1, #4
 *   @0x18c740 ldr r12, [r6]
 *   @0x18c744 mov r2, r8
 *   @0x18c748 mov r0, r6
 *   @0x18c74c add r11, r11, #1
 *   @0x18c750 ldrh r4, [lr, r7]
 *   @0x18c754 str r10, [r6, #0x38]
 *   @0x18c758 sxth r4, r4
 *   @0x18c75c vmov s15, r4
 *   @0x18c760 vcvt.f64.s32 d7, s15
 *   @0x18c764 vmov r4, r5, d7
 *   @0x18c768 vstr s14, [r6, #44]
 *   @0x18c76c str r5, [r6, #0x30]
 *   @0x18c770 ldr r12, [r12, #0x8]
 *   @0x18c774 str r3, [sp, #0x4]
 *   @0x18c778 blx r12
 *   @0x18c77c ldr lr, [r9]
 *   @0x18c780 ldr r12, [r6]
 *   @0x18c784 mov r1, #4
 *   @0x18c788 add lr, lr, r7
 *   @0x18c78c mov r2, r8
 *   @0x18c790 mov r0, r6
 *   @0x18c794 ldrh r4, [lr, #2]
 *   @0x18c798 str r10, [r6, #0x38]
 *   @0x18c79c sxth r4, r4
 *   @0x18c7a0 vmov s15, r4
 *   @0x18c7a4 vcvt.f64.s32 d7, s15
 *   @0x18c7a8 vmov r4, r5, d7
 *   @0x18c7ac vstr s14, [r6, #44]
 *   @0x18c7b0 str r5, [r6, #0x30]
 *   @0x18c7b4 ldr r12, [r12, #0x8]
 *   @0x18c7b8 blx r12
 *   @0x18c7bc ldr lr, [r9]
 *   @0x18c7c0 ldr r12, [r6]
 *   @0x18c7c4 mov r1, #6
 *   @0x18c7c8 add lr, lr, r7
 *   @0x18c7cc mov r2, r8
 *   @0x18c7d0 mov r0, r6
 *   @0x18c7d4 ldr r4, [lr, #0x4]
 *   @0x18c7d8 str r10, [r6, #0x38]
 *   @0x18c7dc vmov s15, r4
 *   @0x18c7e0 vcvt.f64.s32 d7, s15
 *   @0x18c7e4 vmov r4, r5, d7
 *   @0x18c7e8 vstr s14, [r6, #44]
 *   @0x18c7ec str r5, [r6, #0x30]
 *   @0x18c7f0 ldr r12, [r12, #0x8]
 *   @0x18c7f4 blx r12
 *   @0x18c7f8 ldr lr, [r9]
 *   @0x18c7fc ldr r12, [r6]
 *   @0x18c800 mov r1, #6
 *   @0x18c804 add lr, lr, r7
 *   @0x18c808 mov r2, r8
 *   @0x18c80c mov r0, r6
 *   @0x18c810 ldr r4, [lr, #0x8]
 *   @0x18c814 str r10, [r6, #0x38]
 *   @0x18c818 vmov s15, r4
 *   @0x18c81c vcvt.f64.s32 d7, s15
 *   @0x18c820 vmov r4, r5, d7
 *   @0x18c824 vstr s14, [r6, #44]
 *   @0x18c828 str r5, [r6, #0x30]
 *   @0x18c82c ldr r12, [r12, #0x8]
 *   @0x18c830 blx r12
 *   @0x18c834 ldr lr, [r9]
 *   @0x18c838 ldr r12, [r6]
 *   @0x18c83c mov r1, #6
 *   @0x18c840 add lr, lr, r7
 *   @0x18c844 mov r2, r8
 *   @0x18c848 mov r0, r6
 *   @0x18c84c ldr r4, [lr, #0xc]
 *   @0x18c850 str r10, [r6, #0x38]
 *   @0x18c854 vmov s15, r4
 *   @0x18c858 vcvt.f64.s32 d7, s15
 *   @0x18c85c vmov r4, r5, d7
 *   @0x18c860 vstr s14, [r6, #44]
 *   @0x18c864 str r5, [r6, #0x30]
 *   @0x18c868 ldr r12, [r12, #0x8]
 *   @0x18c86c blx r12
 *   @0x18c870 ldr lr, [r9]
 *   @0x18c874 ldr r12, [r6]
 *   @0x18c878 mov r1, #6
 *   @0x18c87c add lr, lr, r7
 *   @0x18c880 mov r2, r8
 *   @0x18c884 mov r0, r6
 *   @0x18c888 ldr r4, [lr, #0x10]
 *   @0x18c88c str r10, [r6, #0x38]
 *   @0x18c890 vmov s15, r4
 *   @0x18c894 vcvt.f64.s32 d7, s15
 *   @0x18c898 vmov r4, r5, d7
 *   @0x18c89c vstr s14, [r6, #44]
 *   @0x18c8a0 str r5, [r6, #0x30]
 *   @0x18c8a4 ldr r12, [r12, #0x8]
 *   @0x18c8a8 blx r12
 *   @0x18c8ac ldr lr, [r9]
 *   @0x18c8b0 ldr r12, [r6]
 *   @0x18c8b4 mov r1, #6
 *   @0x18c8b8 add lr, lr, r7
 *   @0x18c8bc mov r2, r8
 *   @0x18c8c0 mov r0, r6
 *   @0x18c8c4 ldr r4, [lr, #0x14]
 *   @0x18c8c8 str r10, [r6, #0x38]
 *   @0x18c8cc vmov s15, r4
 *   @0x18c8d0 vcvt.f64.s32 d7, s15
 *   @0x18c8d4 vmov r4, r5, d7
 *   @0x18c8d8 vstr s14, [r6, #44]
 *   @0x18c8dc str r5, [r6, #0x30]
 *   @0x18c8e0 ldr r12, [r12, #0x8]
 *   @0x18c8e4 blx r12
 *   @0x18c8e8 ldr lr, [r9]
 *   @0x18c8ec ldr r12, [r6]
 *   @0x18c8f0 mov r1, #6
 *   @0x18c8f4 add lr, lr, r7
 *   @0x18c8f8 mov r2, r8
 *   @0x18c8fc mov r0, r6
 *   @0x18c900 ldr r4, [lr, #0x18]
 *   @0x18c904 str r10, [r6, #0x38]
 *   @0x18c908 vmov s15, r4
 *   @0x18c90c vcvt.f64.s32 d7, s15
 *   @0x18c910 vmov r4, r5, d7
 *   @0x18c914 vstr s14, [r6, #44]
 *   @0x18c918 str r5, [r6, #0x30]
 *   @0x18c91c ldr r12, [r12, #0x8]
 *   @0x18c920 blx r12
 *   @0x18c924 ldr lr, [r9]
 *   @0x18c928 ldr r12, [r6]
 *   @0x18c92c mov r1, #6
 *   @0x18c930 add lr, lr, r7
 *   @0x18c934 mov r2, r8
 *   @0x18c938 mov r0, r6
 *   @0x18c93c ldr r4, [lr, #0x1c]
 *   @0x18c940 str r10, [r6, #0x38]
 *   @0x18c944 vmov s15, r4
 *   @0x18c948 vcvt.f64.s32 d7, s15
 *   @0x18c94c vmov r4, r5, d7
 *   @0x18c950 vstr s14, [r6, #44]
 *   @0x18c954 str r5, [r6, #0x30]
 *   @0x18c958 ldr r12, [r12, #0x8]
 *   @0x18c95c blx r12
 *   @0x18c960 ldr lr, [r9]
 *   @0x18c964 ldr r12, [r6]
 *   @0x18c968 mov r1, #6
 *   @0x18c96c add lr, lr, r7
 *   @0x18c970 mov r2, r8
 *   @0x18c974 mov r0, r6
 *   @0x18c978 ldr r4, [lr, #0x20]
 *   @0x18c97c str r10, [r6, #0x38]
 *   @0x18c980 vmov s15, r4
 *   @0x18c984 vcvt.f64.s32 d7, s15
 *   @0x18c988 vmov r4, r5, d7
 *   @0x18c98c vstr s14, [r6, #44]
 *   @0x18c990 str r5, [r6, #0x30]
 *   @0x18c994 ldr r12, [r12, #0x8]
 *   @0x18c998 blx r12
 *   @0x18c99c ldr lr, [r9]
 *   @0x18c9a0 ldr r12, [r6]
 *   @0x18c9a4 mov r1, #6
 *   @0x18c9a8 add lr, lr, r7
 *   @0x18c9ac mov r2, r8
 *   @0x18c9b0 mov r0, r6
 *   @0x18c9b4 ldr r4, [lr, #0x24]
 *   @0x18c9b8 str r10, [r6, #0x38]
 *   @0x18c9bc vmov s15, r4
 *   @0x18c9c0 vcvt.f64.s32 d7, s15
 *   @0x18c9c4 vmov r4, r5, d7
 *   @0x18c9c8 vstr s14, [r6, #44]
 *   @0x18c9cc str r5, [r6, #0x30]
 *   @0x18c9d0 ldr r12, [r12, #0x8]
 *   @0x18c9d4 blx r12
 *   @0x18c9d8 ldr lr, [r9]
 *   @0x18c9dc ldr r12, [r6]
 *   @0x18c9e0 mov r2, r8
 *   @0x18c9e4 add lr, lr, r7
 *   @0x18c9e8 mov r0, r6
 *   @0x18c9ec mov r1, #6
 *   @0x18c9f0 add r7, r7, #44
 *   @0x18c9f4 ldr r4, [lr, #0x28]
 *   @0x18c9f8 str r10, [r6, #0x38]
 *   @0x18c9fc vmov s15, r4
 *   @0x18ca00 vcvt.f64.s32 d7, s15
 *   @0x18ca04 vmov r4, r5, d7
 *   @0x18ca08 vstr s14, [r6, #44]
 *   @0x18ca0c str r5, [r6, #0x30]
 *   @0x18ca10 ldr r12, [r12, #0x8]
 *   @0x18ca14 blx r12
 *   @0x18ca18 ldr r3, [sp, #0x4]
 *   @0x18ca1c ldr r2, [r3]
 *   @0x18ca20 cmp r2, r11
 *   @0x18ca24 bgt 0x18c738 <_Z21VirtualKeys_SerialiseP7IBuffer+0xa0>
 *   @0x18ca28 add sp, sp, #12
 *   @0x18ca2c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x18ca30 eoreq r3, r6, r8, ror #8
 *   @0x18ca34 eoreq r3, r6, r0, lsr #8
 *
 * ══ §31/33 jpeg_make_d_derived_tbl  0x2be510  size 928  232 条（0x2be510..0x2be8b0）
 * @func 0x2be510 0x2be8b0  size 928  232 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: jpeg_make_d_derived_tbl+0x54 / jpeg_make_d_derived_tbl+0x110 / 0xb65b0 / jpeg_make_d_derived_tbl+0x324 / 0xb65d4
 * 字段偏移 top8: 0x4×9 / 0x14×8 / 0x18×4 / 0x1×4 / 0xc×3 / 0x8×3 / 0x10×2 / 0x52c×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2be510 ldr r12, [pc, #0x394]
 *   @0x2be514 cmp r2, #3
 *   @0x2be518 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2be51c ldr r12, [pc, r12]
 *   @0x2be520 sub sp, sp, #1328
 *   @0x2be524 mov r5, r3
 *   @0x2be528 ldr r3, [r12]
 *   @0x2be52c sub sp, sp, #4
 *   @0x2be530 mov r4, r2
 *   @0x2be534 mov r11, r0
 *   @0x2be538 str r1, [sp, #0x14]
 *   @0x2be53c str r12, [sp, #0x10]
 *   @0x2be540 str r3, [sp, #0x52c]
 *   @0x2be544 bls 0x2be564 <jpeg_make_d_derived_tbl+0x54>
 *   @0x2be548 ldr r3, [r0]
 *   @0x2be54c mov r1, #50
 *   @0x2be550 str r2, [r3, #0x18]
 *   @0x2be554 ldr r2, [r0]
 *   @0x2be558 str r1, [r3, #0x14]
 *   @0x2be55c ldr r3, [r2]
 *   @0x2be560 blx r3
 *   @0x2be564 ldr r12, [sp, #0x14]
 *   @0x2be568 cmp r12, #0
 *   @0x2be56c addne r3, r4, #40
 *   @0x2be570 addeq r3, r4, #44
 *   @0x2be574 ldr r7, [r11, r3, lsl #2]
 *   @0x2be578 cmp r7, #0
 *   @0x2be57c bne 0x2be5a0 <jpeg_make_d_derived_tbl+0x90>
 *   @0x2be580 ldr r3, [r11]
 *   @0x2be584 mov r1, #50
 *   @0x2be588 mov r0, r11
 *   @0x2be58c str r4, [r3, #0x18]
 *   @0x2be590 ldr r2, [r11]
 *   @0x2be594 str r1, [r3, #0x14]
 *   @0x2be598 ldr r3, [r2]
 *   @0x2be59c blx r3
 *   @0x2be5a0 ldr r8, [r5]
 *   @0x2be5a4 cmp r8, #0
 *   @0x2be5a8 bne 0x2be5cc <jpeg_make_d_derived_tbl+0xbc>
 *   @0x2be5ac ldr r3, [r11, #0x4]
 *   @0x2be5b0 mov r0, r11
 *   @0x2be5b4 mov r1, #1
 *   @0x2be5b8 mov r2, #1424
 *   @0x2be5bc ldr r3, [r3]
 *   @0x2be5c0 blx r3
 *   @0x2be5c4 mov r8, r0
 *   @0x2be5c8 str r0, [r5]
 *   @0x2be5cc add r10, sp, #1056
 *   @0x2be5d0 mov r3, #0
 *   @0x2be5d4 add r10, r10, #8
 *   @0x2be5d8 str r7, [r8, #0x8c]
 *   @0x2be5dc mov r12, r8
 *   @0x2be5e0 mov r5, #1
 *   @0x2be5e4 mov r9, #8
 *   @0x2be5e8 mov r8, r7
 *   @0x2be5ec mov r6, r3
 *   @0x2be5f0 str r3, [sp, #0xc]
 *   @0x2be5f4 ldrb r4, [r7, #0x1]!
 *   @0x2be5f8 add r3, r6, r4
 *   @0x2be5fc cmp r3, #256
 *   @0x2be600 ble 0x2be620 <jpeg_make_d_derived_tbl+0x110>
 *   @0x2be604 ldr r2, [r11]
 *   @0x2be608 mov r0, r11
 *   @0x2be60c str r9, [r2, #0x14]
 *   @0x2be610 ldr r3, [r2]
 *   @0x2be614 str r12, [sp, #0x4]
 *   @0x2be618 blx r3
 *   @0x2be61c ldr r12, [sp, #0x4]
 *   @0x2be620 cmp r4, #0
 *   @0x2be624 sub r0, r4, #1
 *   @0x2be628 beq 0x2be650 <jpeg_make_d_derived_tbl+0x140>
 *   @0x2be62c uxtb r1, r5
 *   @0x2be630 add r2, r10, r6
 *   @0x2be634 mov r3, #0
 *   @0x2be638 strb r1, [r2, r3]
 *   @0x2be63c add r3, r3, #1
 *   @0x2be640 cmp r3, r4
 *   @0x2be644 bne 0x2be638 <jpeg_make_d_derived_tbl+0x128>
 *   @0x2be648 add r6, r6, #1
 *   @0x2be64c add r6, r0, r6
 *   @0x2be650 add r5, r5, #1
 *   @0x2be654 cmp r5, #17
 *   @0x2be658 bne 0x2be5f4 <jpeg_make_d_derived_tbl+0xe4>
 *   @0x2be65c mov r7, r8
 *   @0x2be660 mov r8, r12
 *   @0x2be664 add r12, sp, #1328
 *   @0x2be668 mov r4, #0
 *   @0x2be66c add r3, r12, r6
 *   @0x2be670 str r6, [sp, #0xc]
 *   @0x2be674 strb r4, [r3, #-0x108]
 *   @0x2be678 ldrb r5, [sp, #0x428]
 *   @0x2be67c cmp r5, r4
 *   @0x2be680 mov r9, r5
 *   @0x2be684 beq 0x2be6f0 <jpeg_make_d_derived_tbl+0x1e0>
 *   @0x2be688 add r10, sp, #36
 *   @0x2be68c add r1, sp, #1056
 *   @0x2be690 mov r6, r4
 *   @0x2be694 mov r12, #1
 *   @0x2be698 add r1, r1, #8
 *   @0x2be69c str r1, [sp, #0x8]
 *   @0x2be6a0 cmp r5, r9
 *   @0x2be6a4 mov r1, r5
 *   @0x2be6a8 bne 0x2be6d8 <jpeg_make_d_derived_tbl+0x1c8>
 *   @0x2be6ac sub r3, r6, #1
 *   @0x2be6b0 add lr, sp, #1056
 *   @0x2be6b4 add lr, lr, #8
 *   @0x2be6b8 add r2, lr, r6
 *   @0x2be6bc add r3, r10, r3, lsl #2
 *   @0x2be6c0 ldrb r5, [r2, #0x1]!
 *   @0x2be6c4 add r6, r6, #1
 *   @0x2be6c8 str r4, [r3, #0x4]!
 *   @0x2be6cc add r4, r4, #1
 *   @0x2be6d0 cmp r5, r1
 *   @0x2be6d4 beq 0x2be6c0 <jpeg_make_d_derived_tbl+0x1b0>
 *   @0x2be6d8 cmp r4, r12, lsl r9
 *   @0x2be6dc bge 0x2be884 <jpeg_make_d_derived_tbl+0x374>
 *   @0x2be6e0 cmp r5, #0
 *   @0x2be6e4 lsl r4, r4, #1
 *   @0x2be6e8 add r9, r9, #1
 *   @0x2be6ec bne 0x2be6a0 <jpeg_make_d_derived_tbl+0x190>
 *   @0x2be6f0 mov r1, r8
 *   @0x2be6f4 mov r2, #1
 *   @0x2be6f8 mov r3, #0
 *   @0x2be6fc mvn r0, #0
 *   @0x2be700 ldrb r12, [r7, r2]
 *   @0x2be704 cmp r12, #0
 *   @0x2be708 streq r0, [r1, #0x4]
 *   @0x2be70c beq 0x2be738 <jpeg_make_d_derived_tbl+0x228>
 *   @0x2be710 add lr, sp, #1328
 *   @0x2be714 add r12, lr, r3, lsl #2
 *   @0x2be718 ldr r12, [r12, #-0x50c]
 *   @0x2be71c rsb r12, r12, r3
 *   @0x2be720 str r12, [r1, #0x4c]
 *   @0x2be724 ldrb r12, [r7, r2]
 *   @0x2be728 add r3, r3, r12
 *   @0x2be72c add r12, lr, r3, lsl #2
 *   @0x2be730 ldr r12, [r12, #-0x510]
 *   @0x2be734 str r12, [r1, #0x4]
 *   @0x2be738 add r2, r2, #1
 *   @0x2be73c add r1, r1, #4
 *   @0x2be740 cmp r2, #17
 *   @0x2be744 bne 0x2be700 <jpeg_make_d_derived_tbl+0x1f0>
 *   @0x2be748 mov r1, #0
 *   @0x2be74c movw r3, #0xffff
 *   @0x2be750 add r0, r8, #144
 *   @0x2be754 movt r3, #0xf
 *   @0x2be758 mov r2, #1024
 *   @0x2be75c str r3, [r8, #0x44]
 *   @0x2be760 bl 0xb65b0 <memset@plt>
 *   @0x2be764 mov r5, #0
 *   @0x2be768 mov r0, #1
 *   @0x2be76c add r3, sp, #36
 *   @0x2be770 add r1, r8, #140
 *   @0x2be774 str r3, [sp, #0x18]
 *   @0x2be778 str r1, [sp, #0x8]
 *   @0x2be77c str r11, [sp, #0x1c]
 *   @0x2be780 ldrb r3, [r7, r0]
 *   @0x2be784 cmp r3, #0
 *   @0x2be788 beq 0x2be7fc <jpeg_make_d_derived_tbl+0x2ec>
 *   @0x2be78c sub r9, r5, #1
 *   @0x2be790 ldr r3, [sp, #0x18]
 *   @0x2be794 mov r2, #1
 *   @0x2be798 rsb r10, r0, #8
 *   @0x2be79c lsl r11, r2, r10
 *   @0x2be7a0 add r9, r3, r9, lsl #2
 *   @0x2be7a4 mov r6, r2
 *   @0x2be7a8 ldr r12, [r9, #0x4]!
 *   @0x2be7ac add r4, r7, r5
 *   @0x2be7b0 ldr r1, [sp, #0x8]
 *   @0x2be7b4 lsl r12, r12, r10
 *   @0x2be7b8 add r2, r12, #1152
 *   @0x2be7bc add r3, r12, #35
 *   @0x2be7c0 add r12, r12, r11
 *   @0x2be7c4 add r2, r2, #15
 *   @0x2be7c8 add r2, r8, r2
 *   @0x2be7cc add r3, r8, r3, lsl #2
 *   @0x2be7d0 add r12, r1, r12, lsl #2
 *   @0x2be7d4 str r0, [r3, #0x4]!
 *   @0x2be7d8 cmp r3, r12
 *   @0x2be7dc ldrb r1, [r4, #0x11]
 *   @0x2be7e0 strb r1, [r2, #0x1]!
 *   @0x2be7e4 bne 0x2be7d4 <jpeg_make_d_derived_tbl+0x2c4>
 *   @0x2be7e8 ldrb r3, [r7, r0]
 *   @0x2be7ec add r6, r6, #1
 *   @0x2be7f0 add r5, r5, #1
 *   @0x2be7f4 cmp r3, r6
 *   @0x2be7f8 bge 0x2be7a8 <jpeg_make_d_derived_tbl+0x298>
 *   @0x2be7fc add r0, r0, #1
 *   @0x2be800 cmp r0, #9
 *   @0x2be804 bne 0x2be780 <jpeg_make_d_derived_tbl+0x270>
 *   @0x2be808 ldr r12, [sp, #0x14]
 *   @0x2be80c ldr r11, [sp, #0x1c]
 *   @0x2be810 cmp r12, #0
 *   @0x2be814 beq 0x2be864 <jpeg_make_d_derived_tbl+0x354>
 *   @0x2be818 ldr r3, [sp, #0xc]
 *   @0x2be81c cmp r3, #0
 *   @0x2be820 beq 0x2be864 <jpeg_make_d_derived_tbl+0x354>
 *   @0x2be824 add r7, r7, #16
 *   @0x2be828 mov r5, #8
 *   @0x2be82c add r4, r7, r3
 *   @0x2be830 b 0x2be83c <jpeg_make_d_derived_tbl+0x32c>
 *   @0x2be834 cmp r7, r4
 *   @0x2be838 beq 0x2be864 <jpeg_make_d_derived_tbl+0x354>
 *   @0x2be83c ldrb r3, [r7, #0x1]!
 *   @0x2be840 cmp r3, #15
 *   @0x2be844 bls 0x2be834 <jpeg_make_d_derived_tbl+0x324>
 *   @0x2be848 ldr r3, [r11]
 *   @0x2be84c mov r0, r11
 *   @0x2be850 str r5, [r3, #0x14]
 *   @0x2be854 ldr r3, [r3]
 *   @0x2be858 blx r3
 *   @0x2be85c cmp r7, r4
 *   @0x2be860 bne 0x2be83c <jpeg_make_d_derived_tbl+0x32c>
 *   @0x2be864 ldr r12, [sp, #0x10]
 *   @0x2be868 ldr r2, [sp, #0x52c]
 *   @0x2be86c ldr r3, [r12]
 *   @0x2be870 cmp r2, r3
 *   @0x2be874 bne 0x2be8a8 <jpeg_make_d_derived_tbl+0x398>
 *   @0x2be878 add sp, sp, #1328
 *   @0x2be87c add sp, sp, #4
 *   @0x2be880 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2be884 ldr r3, [r11]
 *   @0x2be888 mov r2, #8
 *   @0x2be88c mov r0, r11
 *   @0x2be890 str r2, [r3, #0x14]
 *   @0x2be894 ldr r3, [r3]
 *   @0x2be898 str r12, [sp, #0x4]
 *   @0x2be89c blx r3
 *   @0x2be8a0 ldr r12, [sp, #0x4]
 *   @0x2be8a4 b 0x2be6e0 <jpeg_make_d_derived_tbl+0x1d0>
 *   @0x2be8a8 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x2be8ac andseq pc, r2, r4, lsr r4
 *
 * ══ §32/33 SoundHardware::PlayMP3(char const*, bool)  0x2209fc  size 224  49 条（0x2209fc..0x220adc）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x2209fc 0x220adc  size 224  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x220a0c→0x755361, 0x220a28→0x755363, 0x220a3c→0x755362, 0x220a50→0x75536c, 0x220a80→0x3eb70c
 * 调用序列: 0xb65a4 / SoundHardware::StopMusic()
 * 字段偏移 top8: 0x48×3 / 0xb0×1 / 0xac×1 / 0x94×1 / 0x84×1 / 0x74×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2209fc push {r3, r4, r5, r6, r7, lr}
 *   @0x220a00 mov r7, r0
 *   @0x220a04 ldr r4, [pc, #0xb0]
 *   @0x220a08 mov r6, r1
 *   @0x220a0c ldr r3, [pc, #0xac]
 *   @0x220a10 mov r5, r2
 *   @0x220a14 add r4, pc, r4
 *   @0x220a18 ldr r3, [r4, r3]
 *   @0x220a1c ldrb r3, [r3]
 *   @0x220a3c ldr r3, [pc, #0x84]
 *   @0x220a40 ldr r3, [r4, r3]
 *   @0x220a44 ldrb r3, [r3]
 *   @0x220a48 cmp r3, #0
 *   @0x220a4c popne {r3, r4, r5, r6, r7, pc}
 *   @0x220a50 ldr r3, [pc, #0x74]
 *   @0x220a54 ldr r4, [r4, r3]
 *   @0x220a58 ldrb r3, [r4]
 *   @0x220a5c cmp r3, #0
 *   @0x220a60 bne 0x220ab0 <_ZN13SoundHardware7PlayMP3EPKcb+0xb4>
 *   @0x220a64 mov r1, r6
 *   @0x220a68 mov r0, r4
 *   @0x220a6c bl 0xb65a4 <strcpy@plt>
 *   @0x220a70 mov r0, r6
 *   @0x220a74 mov r1, r5
 *   @0x220a78 pop {r3, r4, r5, r6, r7, lr}
 *   @0x220a7c b 0x223098 <_Z14OpenAL_PlayMP3PKcb>
 *   @0x220a80 ldr r3, [pc, #0x48]
 *   @0x220a84 ldr r2, [pc, #0x48]
 *   @0x220a88 ldr r1, [pc, #0x48]
 *   @0x220a8c ldr r3, [r4, r3]
 *   @0x220a90 add r2, pc, r2
 *   @0x220a94 add r1, pc, r1
 *   @0x220a98 add r2, r2, #112
 *   @0x220a9c ldr r0, [r3]
 *   @0x220aa0 ldr r3, [r0]
 *   @0x220aa4 ldr r3, [r3, #0xc]
 *   @0x220aa8 blx r3
 *   @0x220aac b 0x220a28 <_ZN13SoundHardware7PlayMP3EPKcb+0x2c>
 *   @0x220ab0 mov r0, r7
 *   @0x220ab4 bl 0x220950 <_ZN13SoundHardware9StopMusicEv>
 *   @0x220ab8 b 0x220a64 <_ZN13SoundHardware7PlayMP3EPKcb+0x68>
 *   @0x220abc andseq r1, sp, r12, lsr r2
 *   @0x220ac0 .word 0xfffff7d8
 *   @0x220ac4 .word 0xffffd3fc
 *   @0x220ac8 .word 0xfffff7e0
 *   @0x220acc .word 0xfffff7dc
 *   @0x220ad0 .word 0xffffbac4
 *   @0x220ad4 andseq sp, r3, r8, lsr r5
 *   @0x220ad8 andseq r3, r3, r8, lsr #27
 *
 * ══ §33/33 TestBuffers()  0xc7ba8  size 4  1 条（0xc7ba8..0xc7bac）
 * @func 0xc7ba8 0xc7bac  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc7ba8 bx lr
 */
