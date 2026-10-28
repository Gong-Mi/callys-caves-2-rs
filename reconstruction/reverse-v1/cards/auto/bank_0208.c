/* libyoyo.so 覆盖卡组 0208
 * 函数 0x233b24..0x234a1c，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x233b24 · oggpackB_adv1 · size=4 · insn=1 */
/* @0x233b24 b 0x233af0 <oggpack_adv1> */

/* ── FUNC 0x233b28 · oggpack_read · size=264 · insn=66 */
/* @0x233b28 cmp r1, #32 */
/* @0x233b2c mov r3, r0 */
/* @0x233b30 push {r4, r5, r6, r7, r8} */
/* @0x233b34 ldr r12, [r0, #0x10] */
/* @0x233b38 bhi 0x233c10 <oggpack_read+0xe8> */
/* @0x233b3c ldr r4, [r0] */
/* @0x233b40 sub r2, r12, #4 */
/* @0x233b44 ldr r0, [pc, #0xe0] */
/* @0x233b48 cmp r4, r2 */
/* @0x233b4c ldr r2, [r3, #0x4] */
/* @0x233b50 add r0, pc, r0 */
/* @0x233b54 ldr r6, [r0, r1, lsl #2] */
/* @0x233b58 add r1, r2, r1 */
/* @0x233b5c add r5, r1, #7 */
/* @0x233b60 blt 0x233b7c <oggpack_read+0x54> */
/* @0x233b64 sub r0, r12, r5, asr #3 */
/* @0x233b68 cmp r4, r0 */
/* @0x233b6c bgt 0x233c10 <oggpack_read+0xe8> */
/* @0x233b70 cmp r1, #0 */
/* @0x233b74 moveq r0, r1 */
/* @0x233b78 beq 0x233c08 <oggpack_read+0xe0> */
/* @0x233b7c ldr r12, [r3, #0xc] */
/* @0x233b80 cmp r1, #8 */
/* @0x233b84 ldrb r0, [r12] */
/* @0x233b88 asr r0, r0, r2 */
/* @0x233b8c ble 0x233bdc <oggpack_read+0xb4> */
/* @0x233b90 ldrb r8, [r12, #0x1] */
/* @0x233b94 cmp r1, #16 */
/* @0x233b98 rsb r7, r2, #8 */
/* @0x233b9c orr r0, r0, r8, lsl r7 */
/* @0x233ba0 ble 0x233bdc <oggpack_read+0xb4> */
/* @0x233ba4 ldrb r8, [r12, #0x2] */
/* @0x233ba8 cmp r1, #24 */
/* @0x233bac rsb r7, r2, #16 */
/* @0x233bb0 orr r0, r0, r8, lsl r7 */
/* @0x233bb4 ble 0x233bdc <oggpack_read+0xb4> */
/* @0x233bb8 ldrb r8, [r12, #0x3] */
/* @0x233bbc cmp r1, #32 */
/* @0x233bc0 rsb r7, r2, #24 */
/* @0x233bc4 orr r0, r0, r8, lsl r7 */
/* @0x233bc8 ble 0x233bdc <oggpack_read+0xb4> */
/* @0x233bcc cmp r2, #0 */
/* @0x233bd0 rsbne r2, r2, #32 */
/* @0x233bd4 ldrbne r7, [r12, #0x4] */
/* @0x233bd8 orrne r0, r0, r7, lsl r2 */
/* @0x233bdc cmp r1, #0 */
/* @0x233be0 and r0, r0, r6 */
/* @0x233be4 movge r2, r1 */
/* @0x233be8 movlt r2, r5 */
/* @0x233bec asr r2, r2, #3 */
/* @0x233bf0 and r1, r1, #7 */
/* @0x233bf4 add r12, r12, r2 */
/* @0x233bf8 add r4, r4, r2 */
/* @0x233bfc str r1, [r3, #0x4] */
/* @0x233c00 str r12, [r3, #0xc] */
/* @0x233c04 str r4, [r3] */
/* @0x233c08 pop {r4, r5, r6, r7, r8} */
/* @0x233c0c bx lr */
/* @0x233c10 mov r1, #0 */
/* @0x233c14 mov r2, #1 */
/* @0x233c18 str r12, [r3] */
/* @0x233c1c mvn r0, #0 */
/* @0x233c20 str r1, [r3, #0xc] */
/* @0x233c24 str r2, [r3, #0x4] */
/* @0x233c28 b 0x233c08 <oggpack_read+0xe0> */
/* @0x233c2c andseq r4, r3, r8, ror #29 */

/* ── FUNC 0x233c30 · oggpackB_read · size=268 · insn=67 */
/* @0x233c30 push {r4, r5, r6, r7, r8, r9} */
/* @0x233c34 rsb r6, r1, #32 */
/* @0x233c38 cmp r6, #32 */
/* @0x233c3c mov r3, r0 */
/* @0x233c40 bhi 0x233d1c <oggpackB_read+0xec> */
/* @0x233c44 ldr r5, [r0] */
/* @0x233c48 ldr r12, [r0, #0x10] */
/* @0x233c4c ldr r2, [r3, #0x4] */
/* @0x233c50 add r0, r5, #4 */
/* @0x233c54 cmp r0, r12 */
/* @0x233c58 add r0, r2, r1 */
/* @0x233c5c add r7, r0, #7 */
/* @0x233c60 blt 0x233c78 <oggpackB_read+0x48> */
/* @0x233c64 sub r4, r12, r7, asr #3 */
/* @0x233c68 cmp r5, r4 */
/* @0x233c6c bgt 0x233d20 <oggpackB_read+0xf0> */
/* @0x233c70 cmp r0, #0 */
/* @0x233c74 beq 0x233d14 <oggpackB_read+0xe4> */
/* @0x233c78 ldr r4, [r3, #0xc] */
/* @0x233c7c cmp r0, #8 */
/* @0x233c80 add r12, r2, #24 */
/* @0x233c84 ldrb r8, [r4] */
/* @0x233c88 lsl r12, r8, r12 */
/* @0x233c8c ble 0x233cd8 <oggpackB_read+0xa8> */
/* @0x233c90 ldrb r9, [r4, #0x1] */
/* @0x233c94 cmp r0, #16 */
/* @0x233c98 add r8, r2, #16 */
/* @0x233c9c orr r12, r12, r9, lsl r8 */
/* @0x233ca0 ble 0x233cd8 <oggpackB_read+0xa8> */
/* @0x233ca4 ldrb r9, [r4, #0x2] */
/* @0x233ca8 cmp r0, #24 */
/* @0x233cac add r8, r2, #8 */
/* @0x233cb0 orr r12, r12, r9, lsl r8 */
/* @0x233cb4 ble 0x233cd8 <oggpackB_read+0xa8> */
/* @0x233cb8 ldrb r8, [r4, #0x3] */
/* @0x233cbc cmp r0, #32 */
/* @0x233cc0 orr r12, r12, r8, lsl r2 */
/* @0x233cc4 ble 0x233cd8 <oggpackB_read+0xa8> */
/* @0x233cc8 cmp r2, #0 */
/* @0x233ccc rsbne r2, r2, #8 */
/* @0x233cd0 ldrbne r8, [r4, #0x4] */
/* @0x233cd4 orrne r12, r12, r8, asr r2 */
/* @0x233cd8 asr r6, r6, #1 */
/* @0x233cdc rsb r1, r1, #33 */
/* @0x233ce0 cmp r0, #0 */
/* @0x233ce4 lsr r12, r12, r6 */
/* @0x233ce8 asr r1, r1, #1 */
/* @0x233cec movge r2, r0 */
/* @0x233cf0 movlt r2, r7 */
/* @0x233cf4 and r7, r0, #7 */
/* @0x233cf8 lsr r0, r12, r1 */
/* @0x233cfc asr r2, r2, #3 */
/* @0x233d00 str r7, [r3, #0x4] */
/* @0x233d04 add r4, r4, r2 */
/* @0x233d08 add r5, r5, r2 */
/* @0x233d0c str r4, [r3, #0xc] */
/* @0x233d10 str r5, [r3] */
/* @0x233d14 pop {r4, r5, r6, r7, r8, r9} */
/* @0x233d18 bx lr */
/* @0x233d1c ldr r12, [r0, #0x10] */
/* @0x233d20 mov r1, #0 */
/* @0x233d24 mov r2, #1 */
/* @0x233d28 str r12, [r3] */
/* @0x233d2c mvn r0, #0 */
/* @0x233d30 str r1, [r3, #0xc] */
/* @0x233d34 str r2, [r3, #0x4] */
/* @0x233d38 b 0x233d14 <oggpackB_read+0xe4> */

/* ── FUNC 0x233d3c · oggpack_read1 · size=116 · insn=29 */
/* @0x233d3c ldr r1, [r0] */
/* @0x233d40 mov r3, r0 */
/* @0x233d44 ldr r12, [r0, #0x10] */
/* @0x233d48 str r4, [sp, #-0x4]! */
/* @0x233d4c cmp r1, r12 */
/* @0x233d50 bge 0x233d94 <oggpack_read1+0x58> */
/* @0x233d54 ldr r12, [r0, #0xc] */
/* @0x233d58 ldr r2, [r0, #0x4] */
/* @0x233d5c ldrb r0, [r12] */
/* @0x233d60 add r4, r2, #1 */
/* @0x233d64 cmp r4, #7 */
/* @0x233d68 strle r4, [r3, #0x4] */
/* @0x233d6c addgt r12, r12, #1 */
/* @0x233d70 addgt r1, r1, #1 */
/* @0x233d74 asr r2, r0, r2 */
/* @0x233d78 strgt r12, [r3, #0xc] */
/* @0x233d7c and r0, r2, #1 */
/* @0x233d80 strgt r1, [r3] */
/* @0x233d84 movgt r2, #0 */
/* @0x233d88 strgt r2, [r3, #0x4] */
/* @0x233d8c ldr r4, [sp], #4 */
/* @0x233d90 bx lr */
/* @0x233d94 mov r1, #0 */
/* @0x233d98 mov r2, #1 */
/* @0x233d9c mvn r0, #0 */
/* @0x233da0 str r12, [r3] */
/* @0x233da4 str r1, [r3, #0xc] */
/* @0x233da8 str r2, [r3, #0x4] */
/* @0x233dac b 0x233d8c <oggpack_read1+0x50> */

/* ── FUNC 0x233db0 · oggpackB_read1 · size=120 · insn=30 */
/* @0x233db0 ldr r1, [r0] */
/* @0x233db4 mov r3, r0 */
/* @0x233db8 ldr r12, [r0, #0x10] */
/* @0x233dbc str r4, [sp, #-0x4]! */
/* @0x233dc0 cmp r1, r12 */
/* @0x233dc4 bge 0x233e0c <oggpackB_read1+0x5c> */
/* @0x233dc8 ldr r12, [r0, #0xc] */
/* @0x233dcc ldr r2, [r0, #0x4] */
/* @0x233dd0 ldrb r0, [r12] */
/* @0x233dd4 add r4, r2, #1 */
/* @0x233dd8 rsb r2, r2, #7 */
/* @0x233ddc cmp r4, #7 */
/* @0x233de0 addgt r12, r12, #1 */
/* @0x233de4 addgt r1, r1, #1 */
/* @0x233de8 asr r0, r0, r2 */
/* @0x233dec strle r4, [r3, #0x4] */
/* @0x233df0 and r0, r0, #1 */
/* @0x233df4 movgt r2, #0 */
/* @0x233df8 strgt r12, [r3, #0xc] */
/* @0x233dfc strgt r1, [r3] */
/* @0x233e00 strgt r2, [r3, #0x4] */
/* @0x233e04 ldr r4, [sp], #4 */
/* @0x233e08 bx lr */
/* @0x233e0c mov r1, #0 */
/* @0x233e10 mov r2, #1 */
/* @0x233e14 mvn r0, #0 */
/* @0x233e18 str r12, [r3] */
/* @0x233e1c str r1, [r3, #0xc] */
/* @0x233e20 str r2, [r3, #0x4] */
/* @0x233e24 b 0x233e04 <oggpackB_read1+0x54> */

/* ── FUNC 0x233e28 · oggpack_bytes · size=24 · insn=6 */
/* @0x233e28 ldm r0, {r0, r3} */
/* @0x233e2c adds r1, r3, #7 */
/* @0x233e30 addmi r3, r3, #14 */
/* @0x233e34 movpl r3, r1 */
/* @0x233e38 add r0, r0, r3, asr #3 */
/* @0x233e3c bx lr */

/* ── FUNC 0x233e40 · oggpack_bits · size=16 · insn=4 */
/* @0x233e40 ldr r2, [r0] */
/* @0x233e44 ldr r0, [r0, #0x4] */
/* @0x233e48 add r0, r0, r2, lsl #3 */
/* @0x233e4c bx lr */

/* ── FUNC 0x233e50 · oggpackB_bytes · size=4 · insn=1 */
/* @0x233e50 b 0x233e28 <oggpack_bytes> */

/* ── FUNC 0x233e54 · oggpackB_bits · size=4 · insn=1 */
/* @0x233e54 b 0x233e40 <oggpack_bits> */

/* ── FUNC 0x233e58 · oggpack_get_buffer · size=8 · insn=2 */
/* @0x233e58 ldr r0, [r0, #0x8] */
/* @0x233e5c bx lr */

/* ── FUNC 0x233e60 · oggpackB_get_buffer · size=4 · insn=1 */
/* @0x233e60 b 0x233e58 <oggpack_get_buffer> */

/* ── FUNC 0x233e64 · anon_233e64 · size=272 · insn=68 */
/* @0x233e64 ldr r12, [r0, #0x24] */
/* @0x233e68 ldr r3, [r0, #0x20] */
/* @0x233e6c push {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x233e70 cmp r12, r3 */
/* @0x233e74 movge r1, #0 */
/* @0x233e78 bge 0x233f44 <oggpackB_get_buffer+0xe4> */
/* @0x233e7c ldr r3, [r0, #0x10] */
/* @0x233e80 add r4, r3, r12, lsl #2 */
/* @0x233e84 ldr r8, [r3, r12, lsl #2] */
/* @0x233e88 tst r8, #1024 */
/* @0x233e8c bne 0x233f50 <oggpackB_get_buffer+0xf0> */
/* @0x233e90 cmp r1, #0 */
/* @0x233e94 cmpeq r2, #0 */
/* @0x233e98 beq 0x233f40 <oggpackB_get_buffer+0xe0> */
/* @0x233e9c uxtb r6, r8 */
/* @0x233ea0 and r7, r8, #512 */
/* @0x233ea4 cmp r6, #255 */
/* @0x233ea8 and r8, r8, #256 */
/* @0x233eac bne 0x233ed0 <oggpackB_get_buffer+0x70> */
/* @0x233eb0 ldr r3, [r4, #0x4]! */
/* @0x233eb4 add r12, r12, #1 */
/* @0x233eb8 tst r3, #512 */
/* @0x233ebc uxtb r3, r3 */
/* @0x233ec0 movne r7, #512 */
/* @0x233ec4 cmp r3, #255 */
/* @0x233ec8 add r6, r6, r3 */
/* @0x233ecc beq 0x233eb0 <oggpackB_get_buffer+0x50> */
/* @0x233ed0 cmp r1, #0 */
/* @0x233ed4 beq 0x233f10 <oggpackB_get_buffer+0xb0> */
/* @0x233ed8 mov r3, #344 */
/* @0x233edc ldr r10, [r0, #0x14] */
/* @0x233ee0 ldrd r4, r5, [r0, r3] */
/* @0x233ee4 lsl r11, r12, #3 */
/* @0x233ee8 ldr r9, [r0] */
/* @0x233eec ldr r3, [r0, #0xc] */
/* @0x233ef0 strd r4, r5, [r1, #24] */
/* @0x233ef4 ldrd r4, r5, [r10, r11] */
/* @0x233ef8 add r3, r9, r3 */
/* @0x233efc str r7, [r1, #0xc] */
/* @0x233f00 str r8, [r1, #0x8] */
/* @0x233f04 str r3, [r1] */
/* @0x233f08 strd r4, r5, [r1, #16] */
/* @0x233f0c str r6, [r1, #0x4] */
/* @0x233f10 cmp r2, #0 */
/* @0x233f14 beq 0x233f40 <oggpackB_get_buffer+0xe0> */
/* @0x233f18 mov r1, #344 */
/* @0x233f1c ldr r4, [r0, #0xc] */
/* @0x233f20 ldrd r2, r3, [r0, r1] */
/* @0x233f24 add r12, r12, #1 */
/* @0x233f28 add r6, r4, r6 */
/* @0x233f2c str r12, [r0, #0x24] */
/* @0x233f30 adds r2, r2, #1 */
/* @0x233f34 str r6, [r0, #0xc] */
/* @0x233f38 adc r3, r3, #0 */
/* @0x233f3c strd r2, r3, [r0, r1] */
/* @0x233f40 mov r1, #1 */
/* @0x233f44 mov r0, r1 */
/* @0x233f48 pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x233f4c bx lr */
/* @0x233f50 mov r4, #344 */
/* @0x233f54 add r12, r12, #1 */
/* @0x233f58 ldrd r2, r3, [r0, r4] */
/* @0x233f5c mvn r1, #0 */
/* @0x233f60 str r12, [r0, #0x24] */
/* @0x233f64 adds r2, r2, #1 */
/* @0x233f68 adc r3, r3, #0 */
/* @0x233f6c strd r2, r3, [r0, r4] */
/* @0x233f70 b 0x233f44 <oggpackB_get_buffer+0xe4> */

/* ── FUNC 0x233f74 · ogg_page_version · size=12 · insn=3 */
/* @0x233f74 ldr r3, [r0] */
/* @0x233f78 ldrb r0, [r3, #0x4] */
/* @0x233f7c bx lr */

/* ── FUNC 0x233f80 · ogg_page_continued · size=16 · insn=4 */
/* @0x233f80 ldr r3, [r0] */
/* @0x233f84 ldrb r0, [r3, #0x5] */
/* @0x233f88 and r0, r0, #1 */
/* @0x233f8c bx lr */

/* ── FUNC 0x233f90 · ogg_page_bos · size=16 · insn=4 */
/* @0x233f90 ldr r3, [r0] */
/* @0x233f94 ldrb r0, [r3, #0x5] */
/* @0x233f98 and r0, r0, #2 */
/* @0x233f9c bx lr */

/* ── FUNC 0x233fa0 · ogg_page_eos · size=16 · insn=4 */
/* @0x233fa0 ldr r3, [r0] */
/* @0x233fa4 ldrb r0, [r3, #0x5] */
/* @0x233fa8 and r0, r0, #4 */
/* @0x233fac bx lr */

/* ── FUNC 0x233fb0 · ogg_page_granulepos · size=236 · insn=59 */
/* @0x233fb0 ldr r12, [r0] */
/* @0x233fb4 mov r1, #0 */
/* @0x233fb8 push {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x233fbc mov r9, #0 */
/* @0x233fc0 ldrb r6, [r12, #0xd] */
/* @0x233fc4 sub sp, sp, #8 */
/* @0x233fc8 ldrb r8, [r12, #0xc] */
/* @0x233fcc mov r11, #0 */
/* @0x233fd0 ldrb r0, [r12, #0xa] */
/* @0x233fd4 lsr r3, r6, #24 */
/* @0x233fd8 lsl r2, r6, #8 */
/* @0x233fdc orr r9, r9, r3 */
/* @0x233fe0 orr r8, r8, r2 */
/* @0x233fe4 ldrb r10, [r12, #0xb] */
/* @0x233fe8 lsl r5, r9, #8 */
/* @0x233fec lsl r4, r8, #8 */
/* @0x233ff0 orr r5, r5, r8, lsr #24 */
/* @0x233ff4 strd r0, r1, [sp] */
/* @0x233ff8 orr r5, r5, r11 */
/* @0x233ffc orr r4, r4, r10 */
/* @0x234000 ldrd r2, r3, [sp] */
/* @0x234004 mov r9, #0 */
/* @0x234008 lsl r1, r5, #8 */
/* @0x23400c lsl r0, r4, #8 */
/* @0x234010 orr r1, r1, r4, lsr #24 */
/* @0x234014 orr r0, r0, r2 */
/* @0x234018 orr r1, r1, r3 */
/* @0x23401c ldrb r8, [r12, #0x9] */
/* @0x234020 lsl r2, r0, #8 */
/* @0x234024 ldrb r10, [r12, #0x8] */
/* @0x234028 lsl r3, r1, #8 */
/* @0x23402c orr r2, r2, r8 */
/* @0x234030 orr r3, r3, r0, lsr #24 */
/* @0x234034 ldrb r0, [r12, #0x7] */
/* @0x234038 orr r3, r3, r9 */
/* @0x23403c mov r11, #0 */
/* @0x234040 lsl r6, r2, #8 */
/* @0x234044 mov r1, #0 */
/* @0x234048 lsl r7, r3, #8 */
/* @0x23404c strd r0, r1, [sp] */
/* @0x234050 orr r7, r7, r2, lsr #24 */
/* @0x234054 orr r6, r6, r10 */
/* @0x234058 orr r7, r7, r11 */
/* @0x23405c ldrd r2, r3, [sp] */
/* @0x234060 lsl r4, r6, #8 */
/* @0x234064 ldrb r0, [r12, #0x6] */
/* @0x234068 lsl r5, r7, #8 */
/* @0x23406c orr r4, r4, r2 */
/* @0x234070 orr r5, r5, r6, lsr #24 */
/* @0x234074 mov r1, #0 */
/* @0x234078 orr r5, r5, r3 */
/* @0x23407c lsl r2, r4, #8 */
/* @0x234080 orr r0, r0, r2 */
/* @0x234084 lsl r3, r5, #8 */
/* @0x234088 orr r3, r3, r4, lsr #24 */
/* @0x23408c orr r1, r1, r3 */
/* @0x234090 add sp, sp, #8 */
/* @0x234094 pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x234098 bx lr */

/* ── FUNC 0x23409c · ogg_page_serialno · size=40 · insn=10 */
/* @0x23409c ldr r3, [r0] */
/* @0x2340a0 ldrb r1, [r3, #0x10] */
/* @0x2340a4 ldrb r12, [r3, #0xf] */
/* @0x2340a8 ldrb r2, [r3, #0xe] */
/* @0x2340ac ldrb r0, [r3, #0x11] */
/* @0x2340b0 lsl r1, r1, #16 */
/* @0x2340b4 orr r3, r1, r12, lsl #8 */
/* @0x2340b8 orr r3, r3, r2 */
/* @0x2340bc orr r0, r3, r0, lsl #24 */
/* @0x2340c0 bx lr */

/* ── FUNC 0x2340c4 · ogg_page_pageno · size=40 · insn=10 */
/* @0x2340c4 ldr r3, [r0] */
/* @0x2340c8 ldrb r1, [r3, #0x14] */
/* @0x2340cc ldrb r12, [r3, #0x13] */
/* @0x2340d0 ldrb r2, [r3, #0x12] */
/* @0x2340d4 ldrb r0, [r3, #0x15] */
/* @0x2340d8 lsl r1, r1, #16 */
/* @0x2340dc orr r3, r1, r12, lsl #8 */
/* @0x2340e0 orr r3, r3, r2 */
/* @0x2340e4 orr r0, r3, r0, lsl #24 */
/* @0x2340e8 bx lr */

/* ── FUNC 0x2340ec · ogg_page_packets · size=64 · insn=16 */
/* @0x2340ec ldr r2, [r0] */
/* @0x2340f0 ldrb r12, [r2, #0x1a] */
/* @0x2340f4 cmp r12, #0 */
/* @0x2340f8 beq 0x234124 <ogg_page_packets+0x38> */
/* @0x2340fc mov r0, #0 */
/* @0x234100 add r2, r2, #26 */
/* @0x234104 mov r3, r0 */
/* @0x234108 ldrb r1, [r2, #0x1]! */
/* @0x23410c add r3, r3, #1 */
/* @0x234110 cmp r1, #255 */
/* @0x234114 addne r0, r0, #1 */
/* @0x234118 cmp r12, r3 */
/* @0x23411c bgt 0x234108 <ogg_page_packets+0x1c> */
/* @0x234120 bx lr */
/* @0x234124 mov r0, r12 */
/* @0x234128 bx lr */

/* ── FUNC 0x23412c · ogg_stream_check · size=36 · insn=9 */
/* @0x23412c cmp r0, #0 */
/* @0x234130 beq 0x234148 <ogg_stream_check+0x1c> */
/* @0x234134 ldr r0, [r0] */
/* @0x234138 cmp r0, #0 */
/* @0x23413c movne r0, #0 */
/* @0x234140 mvneq r0, #0 */
/* @0x234144 bx lr */
/* @0x234148 mvn r0, #0 */
/* @0x23414c bx lr */

/* ── FUNC 0x234150 · ogg_stream_clear · size=84 · insn=21 */
/* @0x234150 push {r4, lr} */
/* @0x234154 subs r4, r0, #0 */
/* @0x234158 beq 0x23419c <ogg_stream_clear+0x4c> */
/* @0x23415c ldr r0, [r4] */
/* @0x234160 cmp r0, #0 */
/* @0x234164 beq 0x23416c <ogg_stream_clear+0x1c> */
/* @0x234168 bl 0xb655c <free@plt> */
/* @0x23416c ldr r0, [r4, #0x10] */
/* @0x234170 cmp r0, #0 */
/* @0x234174 beq 0x23417c <ogg_stream_clear+0x2c> */
/* @0x234178 bl 0xb655c <free@plt> */
/* @0x23417c ldr r0, [r4, #0x14] */
/* @0x234180 cmp r0, #0 */
/* @0x234184 beq 0x23418c <ogg_stream_clear+0x3c> */
/* @0x234188 bl 0xb655c <free@plt> */
/* @0x23418c mov r0, r4 */
/* @0x234190 mov r1, #0 */
/* @0x234194 mov r2, #360 */
/* @0x234198 bl 0xb65b0 <memset@plt> */
/* @0x23419c mov r0, #0 */
/* @0x2341a0 pop {r4, pc} */

/* ── FUNC 0x2341a4 · ogg_stream_init · size=148 · insn=37 */
/* @0x2341a4 push {r3, r4, r5, r6, r7, lr} */
/* @0x2341a8 subs r4, r0, #0 */
/* @0x2341ac mov r7, r1 */
/* @0x2341b0 beq 0x234220 <ogg_stream_init+0x7c> */
/* @0x2341b4 mov r1, #0 */
/* @0x2341b8 mov r2, #360 */
/* @0x2341bc bl 0xb65b0 <memset@plt> */
/* @0x2341c0 mov r3, #16384 */
/* @0x2341c4 mov r0, r3 */
/* @0x2341c8 str r3, [r4, #0x4] */
/* @0x2341cc mov r3, #1024 */
/* @0x2341d0 str r3, [r4, #0x18] */
/* @0x2341d4 bl 0xb6544 <malloc@plt> */
/* @0x2341d8 mov r5, r0 */
/* @0x2341dc mov r0, #4096 */
/* @0x2341e0 str r5, [r4] */
/* @0x2341e4 bl 0xb6544 <malloc@plt> */
/* @0x2341e8 mov r6, r0 */
/* @0x2341ec mov r0, #8192 */
/* @0x2341f0 str r6, [r4, #0x10] */
/* @0x2341f4 bl 0xb6544 <malloc@plt> */
/* @0x2341f8 cmp r5, #0 */
/* @0x2341fc str r0, [r4, #0x14] */
/* @0x234200 beq 0x234228 <ogg_stream_init+0x84> */
/* @0x234204 cmp r6, #0 */
/* @0x234208 beq 0x234228 <ogg_stream_init+0x84> */
/* @0x23420c cmp r0, #0 */
/* @0x234210 beq 0x234228 <ogg_stream_init+0x84> */
/* @0x234214 str r7, [r4, #0x150] */
/* @0x234218 mov r0, #0 */
/* @0x23421c pop {r3, r4, r5, r6, r7, pc} */
/* @0x234220 mvn r0, #0 */
/* @0x234224 pop {r3, r4, r5, r6, r7, pc} */
/* @0x234228 mov r0, r4 */
/* @0x23422c bl 0x234150 <ogg_stream_clear> */
/* @0x234230 mvn r0, #0 */
/* @0x234234 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x234238 · anon_234238 · size=252 · insn=63 */
/* @0x234238 push {r3, r4, r5, lr} */
/* @0x23423c mov r5, r1 */
/* @0x234240 ldmib r0, {r1, r3} */
/* @0x234244 mov r4, r0 */
/* @0x234248 add r3, r5, r3 */
/* @0x23424c cmp r1, r3 */
/* @0x234250 ble 0x23425c <ogg_stream_init+0xb8> */
/* @0x234254 mov r0, #0 */
/* @0x234258 pop {r3, r4, r5, pc} */
/* @0x23425c add r1, r1, r5 */
/* @0x234260 ldr r0, [r0] */
/* @0x234264 add r1, r1, #1024 */
/* @0x234268 bl 0xb6c28 <realloc@plt> */
/* @0x23426c cmp r0, #0 */
/* @0x234270 beq 0x234290 <ogg_stream_init+0xec> */
/* @0x234274 ldr r3, [r4, #0x4] */
/* @0x234278 add r5, r5, #1024 */
/* @0x23427c str r0, [r4] */
/* @0x234280 mov r0, #0 */
/* @0x234284 add r5, r3, r5 */
/* @0x234288 str r5, [r4, #0x4] */
/* @0x23428c pop {r3, r4, r5, pc} */
/* @0x234290 mov r0, r4 */
/* @0x234294 bl 0x234150 <ogg_stream_clear> */
/* @0x234298 mvn r0, #0 */
/* @0x23429c pop {r3, r4, r5, pc} */
/* @0x2342a0 ldr r2, [r0, #0x1c] */
/* @0x2342a4 push {r3, r4, r5, lr} */
/* @0x2342a8 add r2, r1, r2 */
/* @0x2342ac ldr r3, [r0, #0x18] */
/* @0x2342b0 mov r4, r0 */
/* @0x2342b4 mov r5, r1 */
/* @0x2342b8 cmp r3, r2 */
/* @0x2342bc ble 0x2342c8 <ogg_stream_init+0x124> */
/* @0x2342c0 mov r0, #0 */
/* @0x2342c4 pop {r3, r4, r5, pc} */
/* @0x2342c8 add r3, r3, r1 */
/* @0x2342cc ldr r0, [r0, #0x10] */
/* @0x2342d0 add r1, r3, #32 */
/* @0x2342d4 lsl r1, r1, #2 */
/* @0x2342d8 bl 0xb6c28 <realloc@plt> */
/* @0x2342dc cmp r0, #0 */
/* @0x2342e0 beq 0x234324 <ogg_stream_init+0x180> */
/* @0x2342e4 ldr r1, [r4, #0x18] */
/* @0x2342e8 str r0, [r4, #0x10] */
/* @0x2342ec add r1, r5, r1 */
/* @0x2342f0 ldr r0, [r4, #0x14] */
/* @0x2342f4 add r1, r1, #32 */
/* @0x2342f8 lsl r1, r1, #3 */
/* @0x2342fc bl 0xb6c28 <realloc@plt> */
/* @0x234300 cmp r0, #0 */
/* @0x234304 beq 0x234324 <ogg_stream_init+0x180> */
/* @0x234308 ldr r3, [r4, #0x18] */
/* @0x23430c add r5, r5, #32 */
/* @0x234310 str r0, [r4, #0x14] */
/* @0x234314 mov r0, #0 */
/* @0x234318 add r5, r3, r5 */
/* @0x23431c str r5, [r4, #0x18] */
/* @0x234320 pop {r3, r4, r5, pc} */
/* @0x234324 mov r0, r4 */
/* @0x234328 bl 0x234150 <ogg_stream_clear> */
/* @0x23432c mvn r0, #0 */
/* @0x234330 pop {r3, r4, r5, pc} */

/* ── FUNC 0x234334 · ogg_stream_destroy · size=32 · insn=8 */
/* @0x234334 push {r4, lr} */
/* @0x234338 subs r4, r0, #0 */
/* @0x23433c beq 0x23434c <ogg_stream_destroy+0x18> */
/* @0x234340 bl 0x234150 <ogg_stream_clear> */
/* @0x234344 mov r0, r4 */
/* @0x234348 bl 0xb655c <free@plt> */
/* @0x23434c mov r0, #0 */
/* @0x234350 pop {r4, pc} */

/* ── FUNC 0x234354 · ogg_page_checksum_set · size=224 · insn=56 */
/* @0x234354 cmp r0, #0 */
/* @0x234358 push {r4, r5} */
/* @0x23435c beq 0x234424 <ogg_page_checksum_set+0xd0> */
/* @0x234360 ldr r2, [r0] */
/* @0x234364 mov r3, #0 */
/* @0x234368 strb r3, [r2, #0x16] */
/* @0x23436c ldr r2, [r0] */
/* @0x234370 strb r3, [r2, #0x17] */
/* @0x234374 ldr r2, [r0] */
/* @0x234378 strb r3, [r2, #0x18] */
/* @0x23437c ldr r2, [r0] */
/* @0x234380 strb r3, [r2, #0x19] */
/* @0x234384 ldr r12, [r0, #0x4] */
/* @0x234388 cmp r12, r3 */
/* @0x23438c movle r2, r3 */
/* @0x234390 ldrle r5, [r0] */
/* @0x234394 ble 0x2343c8 <ogg_page_checksum_set+0x74> */
/* @0x234398 ldr r5, [r0] */
/* @0x23439c ldr r4, [pc, #0x88] */
/* @0x2343a0 add r12, r5, r12 */
/* @0x2343a4 add r4, pc, r4 */
/* @0x2343a8 mov r2, r5 */
/* @0x2343ac ldrb r1, [r2], #1 */
/* @0x2343b0 eor r1, r1, r3, lsr #24 */
/* @0x2343b4 cmp r2, r12 */
/* @0x2343b8 ldr r1, [r4, r1, lsl #2] */
/* @0x2343bc eor r3, r1, r3, lsl #8 */
/* @0x2343c0 bne 0x2343ac <ogg_page_checksum_set+0x58> */
/* @0x2343c4 lsr r2, r3, #24 */
/* @0x2343c8 ldr r12, [r0, #0xc] */
/* @0x2343cc cmp r12, #0 */
/* @0x2343d0 ble 0x234400 <ogg_page_checksum_set+0xac> */
/* @0x2343d4 ldr r2, [r0, #0x8] */
/* @0x2343d8 ldr r4, [pc, #0x50] */
/* @0x2343dc add r12, r2, r12 */
/* @0x2343e0 add r4, pc, r4 */
/* @0x2343e4 ldrb r1, [r2], #1 */
/* @0x2343e8 eor r1, r1, r3, lsr #24 */
/* @0x2343ec cmp r2, r12 */
/* @0x2343f0 ldr r1, [r4, r1, lsl #2] */
/* @0x2343f4 eor r3, r1, r3, lsl #8 */
/* @0x2343f8 bne 0x2343e4 <ogg_page_checksum_set+0x90> */
/* @0x2343fc lsr r2, r3, #24 */
/* @0x234400 strb r3, [r5, #0x16] */
/* @0x234404 lsr r12, r3, #8 */
/* @0x234408 ldr r1, [r0] */
/* @0x23440c lsr r3, r3, #16 */
/* @0x234410 strb r12, [r1, #0x17] */
/* @0x234414 ldr r1, [r0] */
/* @0x234418 strb r3, [r1, #0x18] */
/* @0x23441c ldr r3, [r0] */
/* @0x234420 strb r2, [r3, #0x19] */
/* @0x234424 pop {r4, r5} */
/* @0x234428 bx lr */
/* @0x23442c andseq r4, r3, r12, lsr r7 */
/* @0x234430 andseq r4, r3, r0, lsl #14 */

/* ── FUNC 0x234434 · anon_234434 · size=836 · insn=209 */
/* @0x234434 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x234438 sub sp, sp, #20 */
/* @0x23443c ldr r6, [r0, #0x1c] */
/* @0x234440 mov r4, r0 */
/* @0x234444 str r3, [sp] */
/* @0x234448 mov r9, r1 */
/* @0x23444c str r2, [sp, #0x8] */
/* @0x234450 bl 0x23412c <ogg_stream_check> */
/* @0x234454 ldr r3, [sp] */
/* @0x234458 cmp r0, #0 */
/* @0x23445c movne r0, #0 */
/* @0x234460 bne 0x2346b4 <ogg_page_checksum_set+0x360> */
/* @0x234464 cmp r6, #255 */
/* @0x234468 movge r6, #255 */
/* @0x23446c cmp r6, #0 */
/* @0x234470 beq 0x2346b4 <ogg_page_checksum_set+0x360> */
/* @0x234474 ldr r2, [r4, #0x14c] */
/* @0x234478 cmp r2, #0 */
/* @0x23447c str r2, [sp, #0xc] */
/* @0x234480 beq 0x2346bc <ogg_page_checksum_set+0x368> */
/* @0x234484 cmp r6, #0 */
/* @0x234488 ble 0x23475c <ogg_page_checksum_set+0x408> */
/* @0x23448c ldr r2, [r4, #0x10] */
/* @0x234490 mvn r7, #0 */
/* @0x234494 mov r8, r7 */
/* @0x234498 mov r11, r0 */
/* @0x23449c sub r10, r2, #4 */
/* @0x2344a0 mov r12, r0 */
/* @0x2344a4 str r2, [sp, #0x4] */
/* @0x2344a8 mov r2, r0 */
/* @0x2344ac b 0x2344cc <ogg_page_checksum_set+0x178> */
/* @0x2344b0 cmp r5, #3 */
/* @0x2344b4 movle r5, #0 */
/* @0x2344b8 movgt r5, #1 */
/* @0x2344bc cmp r3, r12 */
/* @0x2344c0 movge r5, #0 */
/* @0x2344c4 cmp r5, #0 */
/* @0x2344c8 bne 0x234738 <ogg_page_checksum_set+0x3e4> */
/* @0x2344cc ldr r1, [r10, #0x4]! */
/* @0x2344d0 mov r5, #0 */
/* @0x2344d4 uxtb r1, r1 */
/* @0x2344d8 cmp r1, #255 */
/* @0x2344dc add r12, r12, r1 */
/* @0x2344e0 beq 0x2344fc <ogg_page_checksum_set+0x1a8> */
/* @0x2344e4 ldr r1, [r4, #0x14] */
/* @0x2344e8 add r11, r11, #1 */
/* @0x2344ec add r8, r1, r2, lsl #3 */
/* @0x2344f0 mov r5, r11 */
/* @0x2344f4 ldr r7, [r1, r2, lsl #3] */
/* @0x2344f8 ldr r8, [r8, #0x4] */
/* @0x2344fc add r2, r2, #1 */
/* @0x234500 cmp r2, r6 */
/* @0x234504 bne 0x2344b0 <ogg_page_checksum_set+0x15c> */
/* @0x234508 cmp r2, #255 */
/* @0x23450c bne 0x234708 <ogg_page_checksum_set+0x3b4> */
/* @0x234510 movw r5, #0x7f8 */
/* @0x234514 mov r1, #1020 */
/* @0x234518 movw r12, #0x11a */
/* @0x23451c mov r10, r2 */
/* @0x234520 ldr r0, [pc, #0x24c] */
/* @0x234524 mov r3, #0 */
/* @0x234528 strb r3, [r4, #0x2d] */
/* @0x23452c add r6, r4, #40 */
/* @0x234530 add r0, pc, r0 */
/* @0x234534 strb r3, [r4, #0x2c] */
/* @0x234538 ldr lr, [r4, #0x1c] */
/* @0x23453c ldr r0, [r0] */
/* @0x234540 str r0, [r4, #0x28] */
/* @0x234544 ldr r0, [sp, #0x4] */
/* @0x234548 ldr r3, [r0] */
/* @0x23454c tst r3, #256 */
/* @0x234550 moveq r3, #1 */
/* @0x234554 strbeq r3, [r4, #0x2d] */
/* @0x234558 ldr r3, [sp, #0xc] */
/* @0x23455c cmp r3, #0 */
/* @0x234560 ldrbeq r3, [r4, #0x2d] */
/* @0x234564 orreq r3, r3, #2 */
/* @0x234568 strbeq r3, [r4, #0x2d] */
/* @0x23456c ldr r3, [r4, #0x148] */
/* @0x234570 cmp r3, #0 */
/* @0x234574 beq 0x234588 <ogg_page_checksum_set+0x234> */
/* @0x234578 cmp lr, r2 */
/* @0x23457c ldrbeq r3, [r4, #0x2d] */
/* @0x234580 orreq r3, r3, #4 */
/* @0x234584 strbeq r3, [r4, #0x2d] */
/* @0x234588 mov r0, r4 */
/* @0x23458c mov r3, #6 */
/* @0x234590 mov r11, #1 */
/* @0x234594 str r11, [r4, #0x14c] */
/* @0x234598 add r3, r3, #1 */
/* @0x23459c strb r7, [r0, #0x2e] */
/* @0x2345a0 cmp r3, #14 */
/* @0x2345a4 lsr r7, r7, #8 */
/* @0x2345a8 orr r7, r7, r8, lsl #24 */
/* @0x2345ac add r0, r0, #1 */
/* @0x2345b0 asr r8, r8, #8 */
/* @0x2345b4 bne 0x234598 <ogg_page_checksum_set+0x244> */
/* @0x2345b8 ldr r3, [r4, #0x154] */
/* @0x2345bc ldr r0, [r4, #0x150] */
/* @0x2345c0 cmn r3, #1 */
/* @0x2345c4 strb r10, [r4, #0x42] */
/* @0x2345c8 moveq r3, #0 */
/* @0x2345cc asr r7, r0, #8 */
/* @0x2345d0 strb r0, [r4, #0x36] */
/* @0x2345d4 strb r7, [r4, #0x37] */
/* @0x2345d8 asr r7, r0, #16 */
/* @0x2345dc asr r0, r0, #24 */
/* @0x2345e0 strb r0, [r4, #0x39] */
/* @0x2345e4 addne r0, r3, #1 */
/* @0x2345e8 moveq r0, #1 */
/* @0x2345ec cmp r2, #0 */
/* @0x2345f0 strb r7, [r4, #0x38] */
/* @0x2345f4 str r0, [r4, #0x154] */
/* @0x2345f8 asr r7, r3, #8 */
/* @0x2345fc asr r0, r3, #16 */
/* @0x234600 strb r3, [r4, #0x3a] */
/* @0x234604 strb r7, [r4, #0x3b] */
/* @0x234608 asr r3, r3, #24 */
/* @0x23460c mov r7, #0 */
/* @0x234610 strb r0, [r4, #0x3c] */
/* @0x234614 strb r3, [r4, #0x3d] */
/* @0x234618 strb r7, [r4, #0x3e] */
/* @0x23461c strb r7, [r4, #0x3f] */
/* @0x234620 strb r7, [r4, #0x40] */
/* @0x234624 strb r7, [r4, #0x41] */
/* @0x234628 ble 0x234650 <ogg_page_checksum_set+0x2fc> */
/* @0x23462c ldr r0, [sp, #0x4] */
/* @0x234630 add r8, r4, #66 */
/* @0x234634 sub r3, r0, #4 */
/* @0x234638 add r10, r3, r2, lsl #2 */
/* @0x23463c ldr r0, [r3, #0x4]! */
/* @0x234640 cmp r3, r10 */
/* @0x234644 strb r0, [r8, #0x1]! */
/* @0x234648 uxtab r7, r7, r0 */
/* @0x23464c bne 0x23463c <ogg_page_checksum_set+0x2e8> */
/* @0x234650 rsb lr, r2, lr */
/* @0x234654 ldr r3, [r4, #0xc] */
/* @0x234658 ldr r2, [r4] */
/* @0x23465c ldr r0, [sp, #0x4] */
/* @0x234660 add r3, r2, r3 */
/* @0x234664 str r6, [r9] */
/* @0x234668 lsl r2, lr, #2 */
/* @0x23466c str r12, [r4, #0x144] */
/* @0x234670 add r1, r0, r1 */
/* @0x234674 str r12, [r9, #0x4] */
/* @0x234678 str r3, [r9, #0x8] */
/* @0x23467c str r7, [r9, #0xc] */
/* @0x234680 str lr, [r4, #0x1c] */
/* @0x234684 bl 0xb6694 <memmove@plt> */
/* @0x234688 ldr r2, [r4, #0x1c] */
/* @0x23468c ldr r0, [r4, #0x14] */
/* @0x234690 lsl r2, r2, #3 */
/* @0x234694 add r1, r0, r5 */
/* @0x234698 bl 0xb6694 <memmove@plt> */
/* @0x23469c ldr r3, [r4, #0xc] */
/* @0x2346a0 mov r0, r9 */
/* @0x2346a4 add r7, r3, r7 */
/* @0x2346a8 str r7, [r4, #0xc] */
/* @0x2346ac bl 0x234354 <ogg_page_checksum_set> */
/* @0x2346b0 mov r0, #1 */
/* @0x2346b4 add sp, sp, #20 */
/* @0x2346b8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2346bc cmp r6, #0 */
/* @0x2346c0 ble 0x23474c <ogg_page_checksum_set+0x3f8> */
/* @0x2346c4 ldr r3, [r4, #0x10] */
/* @0x2346c8 str r3, [sp, #0x4] */
/* @0x2346cc ldrb r3, [r3] */
/* @0x2346d0 cmp r3, #255 */
/* @0x2346d4 bne 0x23476c <ogg_page_checksum_set+0x418> */
/* @0x2346d8 ldr r3, [sp, #0x4] */
/* @0x2346dc ldr r2, [sp, #0xc] */
/* @0x2346e0 b 0x2346f4 <ogg_page_checksum_set+0x3a0> */
/* @0x2346e4 ldr r1, [r3, #0x4]! */
/* @0x2346e8 uxtb r1, r1 */
/* @0x2346ec cmp r1, #255 */
/* @0x2346f0 bne 0x234730 <ogg_page_checksum_set+0x3dc> */
/* @0x2346f4 add r2, r2, #1 */
/* @0x2346f8 cmp r2, r6 */
/* @0x2346fc bne 0x2346e4 <ogg_page_checksum_set+0x390> */
/* @0x234700 mov r7, #0 */
/* @0x234704 mov r8, r7 */
/* @0x234708 ldr r3, [sp, #0x8] */
/* @0x23470c cmp r3, #0 */
/* @0x234710 beq 0x2346b4 <ogg_page_checksum_set+0x360> */
/* @0x234714 ldr r3, [r4, #0x10] */
/* @0x234718 uxtb r10, r2 */
/* @0x23471c add r12, r2, #27 */
/* @0x234720 lsl r1, r2, #2 */
/* @0x234724 lsl r5, r2, #3 */
/* @0x234728 str r3, [sp, #0x4] */
/* @0x23472c b 0x234520 <ogg_page_checksum_set+0x1cc> */
/* @0x234730 add r2, r2, #1 */
/* @0x234734 b 0x234700 <ogg_page_checksum_set+0x3ac> */
/* @0x234738 uxtb r10, r2 */
/* @0x23473c add r12, r2, #27 */
/* @0x234740 lsl r1, r2, #2 */
/* @0x234744 lsl r5, r2, #3 */
/* @0x234748 b 0x234520 <ogg_page_checksum_set+0x1cc> */
/* @0x23474c ldr r7, [sp, #0xc] */
/* @0x234750 mov r8, r7 */
/* @0x234754 mov r2, r7 */
/* @0x234758 b 0x234708 <ogg_page_checksum_set+0x3b4> */
/* @0x23475c mvn r7, #0 */
/* @0x234760 mov r2, r0 */
/* @0x234764 mov r8, r7 */
/* @0x234768 b 0x234708 <ogg_page_checksum_set+0x3b4> */
/* @0x23476c mov r2, #1 */
/* @0x234770 b 0x234700 <ogg_page_checksum_set+0x3ac> */
/* @0x234774 andseq r0, r2, r12, lsr #23 */

/* ── FUNC 0x234778 · ogg_stream_iovecin · size=592 · insn=148 */
/* @0x234778 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x23477c sub sp, sp, #20 */
/* @0x234780 mov r8, r1 */
/* @0x234784 mov r9, r2 */
/* @0x234788 str r3, [sp, #0xc] */
/* @0x23478c mov r4, r0 */
/* @0x234790 bl 0x23412c <ogg_stream_check> */
/* @0x234794 cmp r0, #0 */
/* @0x234798 bne 0x23497c <ogg_stream_iovecin+0x204> */
/* @0x23479c cmp r8, #0 */
/* @0x2347a0 beq 0x23496c <ogg_stream_iovecin+0x1f4> */
/* @0x2347a4 cmp r9, #0 */
/* @0x2347a8 ble 0x23499c <ogg_stream_iovecin+0x224> */
/* @0x2347ac lsl r2, r9, #3 */
/* @0x2347b0 mov r11, r0 */
/* @0x2347b4 mov r5, r0 */
/* @0x2347b8 add r3, r8, r11 */
/* @0x2347bc add r11, r11, #8 */
/* @0x2347c0 cmp r11, r2 */
/* @0x2347c4 ldr r3, [r3, #0x4] */
/* @0x2347c8 add r5, r5, r3 */
/* @0x2347cc bne 0x2347b8 <ogg_stream_iovecin+0x40> */
/* @0x2347d0 movw r3, #0x8081 */
/* @0x2347d4 movt r3, #0x8080 */
/* @0x2347d8 asr r11, r5, #31 */
/* @0x2347dc smull r2, r3, r3, r5 */
/* @0x2347e0 add r3, r3, r5 */
/* @0x2347e4 rsb r11, r11, r3, asr #7 */
/* @0x2347e8 str r11, [sp, #0x4] */
/* @0x2347ec add r3, r11, #1 */
/* @0x2347f0 str r3, [sp, #0x8] */
/* @0x2347f4 ldr r1, [r4, #0xc] */
/* @0x2347f8 cmp r1, #0 */
/* @0x2347fc bne 0x23494c <ogg_stream_iovecin+0x1d4> */
/* @0x234800 mov r0, r4 */
/* @0x234804 mov r1, r5 */
/* @0x234808 bl 0x234238 <ogg_stream_init+0x94> */
/* @0x23480c cmp r0, #0 */
/* @0x234810 bne 0x23497c <ogg_stream_iovecin+0x204> */
/* @0x234814 mov r0, r4 */
/* @0x234818 ldr r1, [sp, #0x8] */
/* @0x23481c bl 0x2342a0 <ogg_stream_init+0xfc> */
/* @0x234820 subs r6, r0, #0 */
/* @0x234824 bne 0x23497c <ogg_stream_iovecin+0x204> */
/* @0x234828 cmp r9, #0 */
/* @0x23482c ble 0x234874 <ogg_stream_iovecin+0xfc> */
/* @0x234830 ldr r0, [r4, #0x8] */
/* @0x234834 mov r7, r6 */
/* @0x234838 mov r10, r6 */
/* @0x23483c add r11, r8, r7 */
/* @0x234840 ldr r3, [r4] */
/* @0x234844 ldr r1, [r8, r7] */
/* @0x234848 add r10, r10, #1 */
/* @0x23484c add r0, r3, r0 */
/* @0x234850 ldr r2, [r11, #0x4] */
/* @0x234854 bl 0xb65bc <memcpy@plt> */
/* @0x234858 ldr r3, [r11, #0x4] */
/* @0x23485c ldr r0, [r4, #0x8] */
/* @0x234860 cmp r10, r9 */
/* @0x234864 add r7, r7, #8 */
/* @0x234868 add r0, r0, r3 */
/* @0x23486c str r0, [r4, #0x8] */
/* @0x234870 bne 0x23483c <ogg_stream_iovecin+0xc4> */
/* @0x234874 ldr r10, [sp, #0x4] */
/* @0x234878 cmp r10, #0 */
/* @0x23487c ble 0x2349b0 <ogg_stream_iovecin+0x238> */
/* @0x234880 ldr r8, [r4, #0x1c] */
/* @0x234884 mov r10, #255 */
/* @0x234888 ldr r3, [sp, #0x4] */
/* @0x23488c mov r7, #352 */
/* @0x234890 ldr r9, [r4, #0x10] */
/* @0x234894 sub r0, r8, #-536870911 */
/* @0x234898 ldr r2, [r4, #0x14] */
/* @0x23489c add r11, r8, r3 */
/* @0x2348a0 add r1, r9, r8, lsl #2 */
/* @0x2348a4 add r12, r9, r11, lsl #2 */
/* @0x2348a8 add r0, r2, r0, lsl #3 */
/* @0x2348ac str r2, [sp, #0x4] */
/* @0x2348b0 ldrd r2, r3, [r4, r7] */
/* @0x2348b4 str r10, [r1], #4 */
/* @0x2348b8 cmp r1, r12 */
/* @0x2348bc strd r2, r3, [r0, #8]! */
/* @0x2348c0 bne 0x2348b0 <ogg_stream_iovecin+0x138> */
/* @0x2348c4 movw r3, #0x8081 */
/* @0x2348c8 movt r3, #0x8080 */
/* @0x2348cc asr r12, r5, #31 */
/* @0x2348d0 lsl r2, r11, #3 */
/* @0x2348d4 smull r10, r3, r3, r5 */
/* @0x2348d8 ldr r7, [sp, #0x8] */
/* @0x2348dc mov r1, #344 */
/* @0x2348e0 add r3, r3, r5 */
/* @0x2348e4 add r0, r7, r8 */
/* @0x2348e8 ldr r7, [sp, #0xc] */
/* @0x2348ec rsb r3, r12, r3, asr #7 */
/* @0x2348f0 mov r12, #352 */
/* @0x2348f4 rsb r3, r3, r3, lsl #8 */
/* @0x2348f8 rsb r5, r3, r5 */
/* @0x2348fc ldr r3, [sp, #0x4] */
/* @0x234900 str r5, [r9, r11, lsl #2] */
/* @0x234904 ldrd r10, r11, [sp, #56] */
/* @0x234908 ldr r5, [r9, r8, lsl #2] */
/* @0x23490c strd r10, r11, [r3, r2] */
/* @0x234910 orr r5, r5, #256 */
/* @0x234914 ldrd r2, r3, [r4, r1] */
/* @0x234918 strd r10, r11, [r4, r12] */
/* @0x23491c adds r2, r2, #1 */
/* @0x234920 str r5, [r9, r8, lsl #2] */
/* @0x234924 adc r3, r3, #0 */
/* @0x234928 cmp r7, #0 */
/* @0x23492c str r0, [r4, #0x1c] */
/* @0x234930 strd r2, r3, [r4, r1] */
/* @0x234934 beq 0x23496c <ogg_stream_iovecin+0x1f4> */
/* @0x234938 mov r3, #1 */
/* @0x23493c mov r0, r6 */
/* @0x234940 str r3, [r4, #0x148] */
/* @0x234944 add sp, sp, #20 */
/* @0x234948 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x23494c ldr r2, [r4, #0x8] */
/* @0x234950 rsb r2, r1, r2 */
/* @0x234954 str r2, [r4, #0x8] */
/* @0x234958 cmp r2, #0 */
/* @0x23495c bne 0x23498c <ogg_stream_iovecin+0x214> */
/* @0x234960 mov r3, #0 */
/* @0x234964 str r3, [r4, #0xc] */
/* @0x234968 b 0x234800 <ogg_stream_iovecin+0x88> */
/* @0x23496c mov r6, #0 */
/* @0x234970 mov r0, r6 */
/* @0x234974 add sp, sp, #20 */
/* @0x234978 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x23497c mvn r6, #0 */
/* @0x234980 mov r0, r6 */
/* @0x234984 add sp, sp, #20 */
/* @0x234988 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x23498c ldr r0, [r4] */
/* @0x234990 add r1, r0, r1 */
/* @0x234994 bl 0xb6694 <memmove@plt> */
/* @0x234998 b 0x234960 <ogg_stream_iovecin+0x1e8> */
/* @0x23499c mov r7, #1 */
/* @0x2349a0 str r0, [sp, #0x4] */
/* @0x2349a4 str r7, [sp, #0x8] */
/* @0x2349a8 mov r5, r0 */
/* @0x2349ac b 0x2347f4 <ogg_stream_iovecin+0x7c> */
/* @0x2349b0 ldr r11, [r4, #0x14] */
/* @0x2349b4 ldr r8, [r4, #0x1c] */
/* @0x2349b8 ldr r9, [r4, #0x10] */
/* @0x2349bc str r11, [sp, #0x4] */
/* @0x2349c0 mov r11, r8 */
/* @0x2349c4 b 0x2348c4 <ogg_stream_iovecin+0x14c> */

/* ── FUNC 0x2349c8 · ogg_stream_packetin · size=60 · insn=15 */
/* @0x2349c8 mov r12, r1 */
/* @0x2349cc ldr r3, [r1, #0xc] */
/* @0x2349d0 push {r4, r5, lr} */
/* @0x2349d4 sub sp, sp, #20 */
/* @0x2349d8 ldrd r4, r5, [r12, #16] */
/* @0x2349dc mov r2, #1 */
/* @0x2349e0 ldr lr, [r12] */
/* @0x2349e4 add r1, sp, #8 */
/* @0x2349e8 ldr r12, [r12, #0x4] */
/* @0x2349ec strd r4, r5, [sp] */
/* @0x2349f0 str lr, [sp, #0x8] */
/* @0x2349f4 str r12, [sp, #0xc] */
/* @0x2349f8 bl 0x234778 <ogg_stream_iovecin> */
/* @0x2349fc add sp, sp, #20 */
/* @0x234a00 pop {r4, r5, pc} */

/* ── FUNC 0x234a04 · ogg_stream_flush · size=12 · insn=3 */
/* @0x234a04 mov r2, #1 */
/* @0x234a08 mov r3, #4096 */
/* @0x234a0c b 0x234434 <ogg_page_checksum_set+0xe0> */

/* ── FUNC 0x234a10 · ogg_stream_flush_fill · size=12 · insn=3 */
/* @0x234a10 mov r3, r2 */
/* @0x234a14 mov r2, #1 */
/* @0x234a18 b 0x234434 <ogg_page_checksum_set+0xe0> */

/* ── FUNC 0x234a1c · ogg_stream_pageout · size=100 · insn=25 */
/* @0x234a1c push {r4, r5, r6, lr} */
/* @0x234a20 mov r5, r1 */
/* @0x234a24 mov r4, r0 */
/* @0x234a28 bl 0x23412c <ogg_stream_check> */
/* @0x234a2c cmp r0, #0 */
/* @0x234a30 bne 0x234a78 <ogg_stream_pageout+0x5c> */
/* @0x234a34 ldr r3, [r4, #0x148] */
/* @0x234a38 ldr r2, [r4, #0x1c] */
/* @0x234a3c cmp r3, #0 */
/* @0x234a40 bne 0x234a6c <ogg_stream_pageout+0x50> */
/* @0x234a44 cmp r2, #0 */
/* @0x234a48 beq 0x234a58 <ogg_stream_pageout+0x3c> */
/* @0x234a4c ldr r2, [r4, #0x14c] */
/* @0x234a50 rsbs r2, r2, #1 */
/* @0x234a54 movlo r2, #0 */
/* @0x234a58 mov r0, r4 */
/* @0x234a5c mov r1, r5 */
/* @0x234a60 mov r3, #4096 */
/* @0x234a64 pop {r4, r5, r6, lr} */
/* @0x234a68 b 0x234434 <ogg_page_checksum_set+0xe0> */
/* @0x234a6c adds r2, r2, #0 */
/* @0x234a70 movne r2, #1 */
/* @0x234a74 b 0x234a58 <ogg_stream_pageout+0x3c> */
/* @0x234a78 mov r0, #0 */
/* @0x234a7c pop {r4, r5, r6, pc} */
