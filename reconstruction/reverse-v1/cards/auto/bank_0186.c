/* libyoyo.so 覆盖卡组 0186
 * 函数 0x209a34..0x20e61c，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x209a34 · CDS_Priority::~CDS_Priority() · alias of the symbol above · insn=0 */

/* ── FUNC 0x209a5c · CDS_Priority::~CDS_Priority() · size=28 · insn=7 */
/* @0x209a5c push {r4, lr} */
/* @0x209a60 mov r4, r0 */
/* @0x209a64 bl 0x209a34 <_ZN12CDS_PriorityD2Ev> */
/* @0x209a68 mov r0, r4 */
/* @0x209a6c bl 0x27d1d0 <_ZdlPv> */
/* @0x209a70 mov r0, r4 */
/* @0x209a74 pop {r4, pc} */

/* ── FUNC 0x209a78 · CDS_Priority::Assign(CDS_Priority*) · size=1744 · insn=436 */
/* @0x209a78 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x209a7c subs r6, r1, #0 */
/* @0x209a80 sub sp, sp, #20 */
/* @0x209a84 mov r8, r0 */
/* @0x209a88 beq 0x20a134 <_ZN12CDS_Priority6AssignEPS_+0x6bc> */
/* @0x209a8c ldr r1, [r6, #0x8] */
/* @0x209a90 movw r3, #0x994 */
/* @0x209a94 ldr r12, [r6, #0x4] */
/* @0x209a98 add r0, r0, #12 */
/* @0x209a9c ldr r2, [pc, #0x69c] */
/* @0x209aa0 lsl r1, r1, #4 */
/* @0x209aa4 add r2, pc, r2 */
/* @0x209aa8 str r12, [r8, #0x4] */
/* @0x209aac bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x209ab0 ldr r3, [r6, #0x8] */
/* @0x209ab4 str r3, [r8, #0x8] */
/* @0x209ab8 ldr r3, [r6, #0x8] */
/* @0x209abc cmp r3, #0 */
/* @0x209ac0 movgt r9, #0 */
/* @0x209ac4 movgt r10, r9 */
/* @0x209ac8 ble 0x209b94 <_ZN12CDS_Priority6AssignEPS_+0x11c> */
/* @0x209acc ldr r7, [r8, #0xc] */
/* @0x209ad0 lsl r4, r9, #4 */
/* @0x209ad4 ldr r11, [r6, #0xc] */
/* @0x209ad8 add r5, r7, r4 */
/* @0x209adc add r3, r11, r4 */
/* @0x209ae0 ldr r0, [r5, #0xc] */
/* @0x209ae4 bic r1, r0, #-16777216 */
/* @0x209ae8 cmp r1, #1 */
/* @0x209aec beq 0x209d94 <_ZN12CDS_Priority6AssignEPS_+0x31c> */
/* @0x209af0 cmp r1, #2 */
/* @0x209af4 bne 0x209b18 <_ZN12CDS_Priority6AssignEPS_+0xa0> */
/* @0x209af8 sub r0, r0, #1 */
/* @0x209afc bic r0, r0, #-16777216 */
/* @0x209b00 bic r0, r0, #3 */
/* @0x209b04 cmp r0, #0 */
/* @0x209b08 beq 0x209eec <_ZN12CDS_Priority6AssignEPS_+0x474> */
/* @0x209b0c mov r2, #5 */
/* @0x209b10 str r10, [r5, #0x8] */
/* @0x209b14 str r2, [r5, #0xc] */
/* @0x209b18 ldr r1, [r3, #0xc] */
/* @0x209b1c ldr r0, [r3, #0x8] */
/* @0x209b20 str r10, [r7, r4] */
/* @0x209b24 str r1, [r5, #0xc] */
/* @0x209b28 ldr r1, [r3, #0xc] */
/* @0x209b2c str r0, [r5, #0x8] */
/* @0x209b30 bic r1, r1, #-16777216 */
/* @0x209b34 cmp r1, #14 */
/* @0x209b38 addls pc, pc, r1, lsl #2 */
/* @0x209b3c b 0x209b84 <_ZN12CDS_Priority6AssignEPS_+0x10c> */
/* @0x209b40 b 0x209c7c <_ZN12CDS_Priority6AssignEPS_+0x204> */
/* @0x209b44 b 0x209ce0 <_ZN12CDS_Priority6AssignEPS_+0x268> */
/* @0x209b48 b 0x209cb4 <_ZN12CDS_Priority6AssignEPS_+0x23c> */
/* @0x209b4c b 0x209b7c <_ZN12CDS_Priority6AssignEPS_+0x104> */
/* @0x209b50 b 0x209b84 <_ZN12CDS_Priority6AssignEPS_+0x10c> */
/* @0x209b54 b 0x209b84 <_ZN12CDS_Priority6AssignEPS_+0x10c> */
/* @0x209b58 b 0x209c90 <_ZN12CDS_Priority6AssignEPS_+0x218> */
/* @0x209b5c b 0x209b7c <_ZN12CDS_Priority6AssignEPS_+0x104> */
/* @0x209b60 b 0x209b84 <_ZN12CDS_Priority6AssignEPS_+0x10c> */
/* @0x209b64 b 0x209b84 <_ZN12CDS_Priority6AssignEPS_+0x10c> */
/* @0x209b68 b 0x209c7c <_ZN12CDS_Priority6AssignEPS_+0x204> */
/* @0x209b6c b 0x209b84 <_ZN12CDS_Priority6AssignEPS_+0x10c> */
/* @0x209b70 b 0x209b84 <_ZN12CDS_Priority6AssignEPS_+0x10c> */
/* @0x209b74 b 0x209c7c <_ZN12CDS_Priority6AssignEPS_+0x204> */
/* @0x209b78 b 0x209b7c <_ZN12CDS_Priority6AssignEPS_+0x104> */
/* @0x209b7c ldr r3, [r11, r4] */
/* @0x209b80 str r3, [r7, r4] */
/* @0x209b84 ldr r3, [r6, #0x8] */
/* @0x209b88 add r9, r9, #1 */
/* @0x209b8c cmp r3, r9 */
/* @0x209b90 bgt 0x209acc <_ZN12CDS_Priority6AssignEPS_+0x54> */
/* @0x209b94 ldr r1, [r6, #0x10] */
/* @0x209b98 movw r3, #0x99a */
/* @0x209b9c ldr r2, [pc, #0x5a0] */
/* @0x209ba0 add r0, r8, #20 */
/* @0x209ba4 add r2, pc, r2 */
/* @0x209ba8 lsl r1, r1, #4 */
/* @0x209bac bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x209bb0 ldr r3, [r6, #0x10] */
/* @0x209bb4 str r3, [r8, #0x10] */
/* @0x209bb8 ldr r3, [r6, #0x10] */
/* @0x209bbc cmp r3, #0 */
/* @0x209bc0 movgt r9, #0 */
/* @0x209bc4 movgt r10, r9 */
/* @0x209bc8 ble 0x209d10 <_ZN12CDS_Priority6AssignEPS_+0x298> */
/* @0x209bcc ldr r7, [r8, #0x14] */
/* @0x209bd0 lsl r4, r9, #4 */
/* @0x209bd4 ldr r11, [r6, #0x14] */
/* @0x209bd8 add r5, r7, r4 */
/* @0x209bdc add r3, r11, r4 */
/* @0x209be0 ldr r0, [r5, #0xc] */
/* @0x209be4 bic r1, r0, #-16777216 */
/* @0x209be8 cmp r1, #1 */
/* @0x209bec beq 0x209ddc <_ZN12CDS_Priority6AssignEPS_+0x364> */
/* @0x209bf0 cmp r1, #2 */
/* @0x209bf4 bne 0x209c18 <_ZN12CDS_Priority6AssignEPS_+0x1a0> */
/* @0x209bf8 sub r0, r0, #1 */
/* @0x209bfc bic r0, r0, #-16777216 */
/* @0x209c00 bic r0, r0, #3 */
/* @0x209c04 cmp r0, #0 */
/* @0x209c08 beq 0x209f00 <_ZN12CDS_Priority6AssignEPS_+0x488> */
/* @0x209c0c mov r2, #5 */
/* @0x209c10 str r10, [r5, #0x8] */
/* @0x209c14 str r2, [r5, #0xc] */
/* @0x209c18 ldr r1, [r3, #0xc] */
/* @0x209c1c ldr r0, [r3, #0x8] */
/* @0x209c20 str r10, [r7, r4] */
/* @0x209c24 str r1, [r5, #0xc] */
/* @0x209c28 ldr r1, [r3, #0xc] */
/* @0x209c2c str r0, [r5, #0x8] */
/* @0x209c30 bic r1, r1, #-16777216 */
/* @0x209c34 cmp r1, #14 */
/* @0x209c38 addls pc, pc, r1, lsl #2 */
/* @0x209c3c b 0x209d00 <_ZN12CDS_Priority6AssignEPS_+0x288> */
/* @0x209c40 b 0x209d18 <_ZN12CDS_Priority6AssignEPS_+0x2a0> */
/* @0x209c44 b 0x209d7c <_ZN12CDS_Priority6AssignEPS_+0x304> */
/* @0x209c48 b 0x209d50 <_ZN12CDS_Priority6AssignEPS_+0x2d8> */
/* @0x209c4c b 0x209cf8 <_ZN12CDS_Priority6AssignEPS_+0x280> */
/* @0x209c50 b 0x209d00 <_ZN12CDS_Priority6AssignEPS_+0x288> */
/* @0x209c54 b 0x209d00 <_ZN12CDS_Priority6AssignEPS_+0x288> */
/* @0x209c58 b 0x209d2c <_ZN12CDS_Priority6AssignEPS_+0x2b4> */
/* @0x209c5c b 0x209cf8 <_ZN12CDS_Priority6AssignEPS_+0x280> */
/* @0x209c60 b 0x209d00 <_ZN12CDS_Priority6AssignEPS_+0x288> */
/* @0x209c64 b 0x209d00 <_ZN12CDS_Priority6AssignEPS_+0x288> */
/* @0x209c68 b 0x209d18 <_ZN12CDS_Priority6AssignEPS_+0x2a0> */
/* @0x209c6c b 0x209d00 <_ZN12CDS_Priority6AssignEPS_+0x288> */
/* @0x209c70 b 0x209d00 <_ZN12CDS_Priority6AssignEPS_+0x288> */
/* @0x209c74 b 0x209d18 <_ZN12CDS_Priority6AssignEPS_+0x2a0> */
/* @0x209c78 b 0x209cf8 <_ZN12CDS_Priority6AssignEPS_+0x280> */
/* @0x209c7c ldr r2, [r11, r4] */
/* @0x209c80 ldr r3, [r3, #0x4] */
/* @0x209c84 str r2, [r7, r4] */
/* @0x209c88 str r3, [r5, #0x4] */
/* @0x209c8c b 0x209b84 <_ZN12CDS_Priority6AssignEPS_+0x10c> */
/* @0x209c90 ldr r3, [r11, r4] */
/* @0x209c94 str r3, [r7, r4] */
/* @0x209c98 ldr r3, [r11, r4] */
/* @0x209c9c cmp r3, #0 */
/* @0x209ca0 beq 0x209b84 <_ZN12CDS_Priority6AssignEPS_+0x10c> */
/* @0x209ca4 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x209ca8 ldr r1, [r11, r4] */
/* @0x209cac bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x209cb0 b 0x209b84 <_ZN12CDS_Priority6AssignEPS_+0x10c> */
/* @0x209cb4 ldr r3, [r11, r4] */
/* @0x209cb8 cmp r3, #0 */
/* @0x209cbc str r3, [r7, r4] */
/* @0x209cc0 beq 0x209b84 <_ZN12CDS_Priority6AssignEPS_+0x10c> */
/* @0x209cc4 ldr r1, [r3, #0x8] */
/* @0x209cc8 ldr r2, [r3] */
/* @0x209ccc cmp r1, #0 */
/* @0x209cd0 streq r5, [r3, #0x8] */
/* @0x209cd4 add r2, r2, #1 */
/* @0x209cd8 str r2, [r3] */
/* @0x209cdc b 0x209b84 <_ZN12CDS_Priority6AssignEPS_+0x10c> */
/* @0x209ce0 ldr r3, [r11, r4] */
/* @0x209ce4 cmp r3, #0 */
/* @0x209ce8 ldrne r2, [r3, #0x4] */
/* @0x209cec addne r2, r2, #1 */
/* @0x209cf0 strne r2, [r3, #0x4] */
/* @0x209cf4 b 0x209b80 <_ZN12CDS_Priority6AssignEPS_+0x108> */
/* @0x209cf8 ldr r3, [r11, r4] */
/* @0x209cfc str r3, [r7, r4] */
/* @0x209d00 ldr r3, [r6, #0x10] */
/* @0x209d04 add r9, r9, #1 */
/* @0x209d08 cmp r3, r9 */
/* @0x209d0c bgt 0x209bcc <_ZN12CDS_Priority6AssignEPS_+0x154> */
/* @0x209d10 add sp, sp, #20 */
/* @0x209d14 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x209d18 ldr r2, [r11, r4] */
/* @0x209d1c ldr r3, [r3, #0x4] */
/* @0x209d20 str r2, [r7, r4] */
/* @0x209d24 str r3, [r5, #0x4] */
/* @0x209d28 b 0x209d00 <_ZN12CDS_Priority6AssignEPS_+0x288> */
/* @0x209d2c ldr r3, [r11, r4] */
/* @0x209d30 str r3, [r7, r4] */
/* @0x209d34 ldr r3, [r11, r4] */
/* @0x209d38 cmp r3, #0 */
/* @0x209d3c beq 0x209d00 <_ZN12CDS_Priority6AssignEPS_+0x288> */
/* @0x209d40 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x209d44 ldr r1, [r11, r4] */
/* @0x209d48 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x209d4c b 0x209d00 <_ZN12CDS_Priority6AssignEPS_+0x288> */
/* @0x209d50 ldr r3, [r11, r4] */
/* @0x209d54 cmp r3, #0 */
/* @0x209d58 str r3, [r7, r4] */
/* @0x209d5c beq 0x209d00 <_ZN12CDS_Priority6AssignEPS_+0x288> */
/* @0x209d60 ldr r1, [r3, #0x8] */
/* @0x209d64 ldr r2, [r3] */
/* @0x209d68 cmp r1, #0 */
/* @0x209d6c streq r5, [r3, #0x8] */
/* @0x209d70 add r2, r2, #1 */
/* @0x209d74 str r2, [r3] */
/* @0x209d78 b 0x209d00 <_ZN12CDS_Priority6AssignEPS_+0x288> */
/* @0x209d7c ldr r3, [r11, r4] */
/* @0x209d80 cmp r3, #0 */
/* @0x209d84 ldrne r2, [r3, #0x4] */
/* @0x209d88 addne r2, r2, #1 */
/* @0x209d8c strne r2, [r3, #0x4] */
/* @0x209d90 b 0x209cfc <_ZN12CDS_Priority6AssignEPS_+0x284> */
/* @0x209d94 ldr r1, [r7, r9, lsl #4] */
/* @0x209d98 cmp r1, #0 */
/* @0x209d9c beq 0x209dd4 <_ZN12CDS_Priority6AssignEPS_+0x35c> */
/* @0x209da0 str r1, [sp, #0x8] */
/* @0x209da4 str r3, [sp, #0x4] */
/* @0x209da8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x209dac ldr r1, [sp, #0x8] */
/* @0x209db0 ldr r3, [sp, #0x4] */
/* @0x209db4 ldr r12, [r1, #0x4] */
/* @0x209db8 sub r12, r12, #1 */
/* @0x209dbc str r12, [r1, #0x4] */
/* @0x209dc0 cmp r12, #0 */
/* @0x209dc4 beq 0x209e24 <_ZN12CDS_Priority6AssignEPS_+0x3ac> */
/* @0x209dc8 str r3, [sp, #0x4] */
/* @0x209dcc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x209dd0 ldr r3, [sp, #0x4] */
/* @0x209dd4 str r10, [r7, r4] */
/* @0x209dd8 b 0x209b18 <_ZN12CDS_Priority6AssignEPS_+0xa0> */
/* @0x209ddc ldr r1, [r7, r9, lsl #4] */
/* @0x209de0 cmp r1, #0 */
/* @0x209de4 beq 0x209e1c <_ZN12CDS_Priority6AssignEPS_+0x3a4> */
/* @0x209de8 str r1, [sp, #0x8] */
/* @0x209dec str r3, [sp, #0x4] */
/* @0x209df0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x209df4 ldr r1, [sp, #0x8] */
/* @0x209df8 ldr r3, [sp, #0x4] */
/* @0x209dfc ldr r12, [r1, #0x4] */
/* @0x209e00 sub r12, r12, #1 */
/* @0x209e04 str r12, [r1, #0x4] */
/* @0x209e08 cmp r12, #0 */
/* @0x209e0c beq 0x209e88 <_ZN12CDS_Priority6AssignEPS_+0x410> */
/* @0x209e10 str r3, [sp, #0x4] */
/* @0x209e14 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x209e18 ldr r3, [sp, #0x4] */
/* @0x209e1c str r10, [r7, r4] */
/* @0x209e20 b 0x209c18 <_ZN12CDS_Priority6AssignEPS_+0x1a0> */
/* @0x209e24 ldr r0, [r1] */
/* @0x209e28 str r1, [sp, #0x8] */
/* @0x209e2c str r12, [sp, #0xc] */
/* @0x209e30 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x209e34 ldr r1, [sp, #0x8] */
/* @0x209e38 ldr r12, [sp, #0xc] */
/* @0x209e3c str r12, [r1] */
/* @0x209e40 str r12, [r1, #0x8] */
/* @0x209e44 str r1, [sp, #0x8] */
/* @0x209e48 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x209e4c ldr r1, [sp, #0x8] */
/* @0x209e50 ldr r3, [sp, #0x4] */
/* @0x209e54 ldr r12, [r1, #0x4] */
/* @0x209e58 sub r12, r12, #1 */
/* @0x209e5c str r12, [r1, #0x4] */
/* @0x209e60 cmp r12, #0 */
/* @0x209e64 beq 0x209f14 <_ZN12CDS_Priority6AssignEPS_+0x49c> */
/* @0x209e68 str r3, [sp, #0x4] */
/* @0x209e6c str r1, [sp, #0x8] */
/* @0x209e70 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x209e74 ldr r1, [sp, #0x8] */
/* @0x209e78 mov r0, r1 */
/* @0x209e7c bl 0x27d1d0 <_ZdlPv> */
/* @0x209e80 ldr r3, [sp, #0x4] */
/* @0x209e84 b 0x209dc8 <_ZN12CDS_Priority6AssignEPS_+0x350> */
/* @0x209e88 ldr r0, [r1] */
/* @0x209e8c str r1, [sp, #0x8] */
/* @0x209e90 str r12, [sp, #0xc] */
/* @0x209e94 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x209e98 ldr r1, [sp, #0x8] */
/* @0x209e9c ldr r12, [sp, #0xc] */
/* @0x209ea0 str r12, [r1] */
/* @0x209ea4 str r12, [r1, #0x8] */
/* @0x209ea8 str r1, [sp, #0x8] */
/* @0x209eac bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x209eb0 ldr r1, [sp, #0x8] */
/* @0x209eb4 ldr r3, [sp, #0x4] */
/* @0x209eb8 ldr r12, [r1, #0x4] */
/* @0x209ebc sub r12, r12, #1 */
/* @0x209ec0 str r12, [r1, #0x4] */
/* @0x209ec4 cmp r12, #0 */
/* @0x209ec8 beq 0x209f7c <_ZN12CDS_Priority6AssignEPS_+0x504> */
/* @0x209ecc str r3, [sp, #0x4] */
/* @0x209ed0 str r1, [sp, #0x8] */
/* @0x209ed4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x209ed8 ldr r1, [sp, #0x8] */
/* @0x209edc mov r0, r1 */
/* @0x209ee0 bl 0x27d1d0 <_ZdlPv> */
/* @0x209ee4 ldr r3, [sp, #0x4] */
/* @0x209ee8 b 0x209e10 <_ZN12CDS_Priority6AssignEPS_+0x398> */
/* @0x209eec mov r0, r5 */
/* @0x209ef0 str r3, [sp, #0x4] */
/* @0x209ef4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x209ef8 ldr r3, [sp, #0x4] */
/* @0x209efc b 0x209b0c <_ZN12CDS_Priority6AssignEPS_+0x94> */
/* @0x209f00 mov r0, r5 */
/* @0x209f04 str r3, [sp, #0x4] */
/* @0x209f08 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x209f0c ldr r3, [sp, #0x4] */
/* @0x209f10 b 0x209c0c <_ZN12CDS_Priority6AssignEPS_+0x194> */
/* @0x209f14 ldr r0, [r1] */
/* @0x209f18 str r1, [sp, #0x8] */
/* @0x209f1c str r12, [sp, #0xc] */
/* @0x209f20 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x209f24 ldr r1, [sp, #0x8] */
/* @0x209f28 ldr r12, [sp, #0xc] */
/* @0x209f2c str r12, [r1] */
/* @0x209f30 str r12, [r1, #0x8] */
/* @0x209f34 str r1, [sp, #0x8] */
/* @0x209f38 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x209f3c ldr r1, [sp, #0x8] */
/* @0x209f40 ldr r3, [sp, #0x4] */
/* @0x209f44 ldr r12, [r1, #0x4] */
/* @0x209f48 sub r12, r12, #1 */
/* @0x209f4c str r12, [r1, #0x4] */
/* @0x209f50 cmp r12, #0 */
/* @0x209f54 beq 0x20a08c <_ZN12CDS_Priority6AssignEPS_+0x614> */
/* @0x209f58 str r3, [sp, #0x4] */
/* @0x209f5c str r1, [sp, #0x8] */
/* @0x209f60 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x209f64 ldr r1, [sp, #0x8] */
/* @0x209f68 mov r0, r1 */
/* @0x209f6c bl 0x27d1d0 <_ZdlPv> */
/* @0x209f70 ldr r3, [sp, #0x4] */
/* @0x209f74 ldr r1, [sp, #0x8] */
/* @0x209f78 b 0x209e68 <_ZN12CDS_Priority6AssignEPS_+0x3f0> */
/* @0x209f7c ldr r0, [r1] */
/* @0x209f80 str r1, [sp, #0x8] */
/* @0x209f84 str r12, [sp, #0xc] */
/* @0x209f88 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x209f8c ldr r1, [sp, #0x8] */
/* @0x209f90 ldr r12, [sp, #0xc] */
/* @0x209f94 str r12, [r1] */
/* @0x209f98 str r12, [r1, #0x8] */
/* @0x209f9c str r1, [sp, #0x8] */
/* @0x209fa0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x209fa4 ldr r1, [sp, #0x8] */
/* @0x209fa8 ldr r3, [sp, #0x4] */
/* @0x209fac ldr r12, [r1, #0x4] */
/* @0x209fb0 sub r12, r12, #1 */
/* @0x209fb4 str r12, [r1, #0x4] */
/* @0x209fb8 cmp r12, #0 */
/* @0x209fbc beq 0x209fe4 <_ZN12CDS_Priority6AssignEPS_+0x56c> */
/* @0x209fc0 str r3, [sp, #0x4] */
/* @0x209fc4 str r1, [sp, #0x8] */
/* @0x209fc8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x209fcc ldr r1, [sp, #0x8] */
/* @0x209fd0 mov r0, r1 */
/* @0x209fd4 bl 0x27d1d0 <_ZdlPv> */
/* @0x209fd8 ldr r3, [sp, #0x4] */
/* @0x209fdc ldr r1, [sp, #0x8] */
/* @0x209fe0 b 0x209ecc <_ZN12CDS_Priority6AssignEPS_+0x454> */
/* @0x209fe4 ldr r0, [r1] */
/* @0x209fe8 str r1, [sp, #0x8] */
/* @0x209fec str r12, [sp, #0xc] */
/* @0x209ff0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x209ff4 ldr r1, [sp, #0x8] */
/* @0x209ff8 ldr r12, [sp, #0xc] */
/* @0x209ffc str r12, [r1] */
/* @0x20a000 str r12, [r1, #0x8] */
/* @0x20a004 str r1, [sp, #0x8] */
/* @0x20a008 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20a00c ldr r1, [sp, #0x8] */
/* @0x20a010 ldr r3, [sp, #0x4] */
/* @0x20a014 ldr r12, [r1, #0x4] */
/* @0x20a018 sub r12, r12, #1 */
/* @0x20a01c str r12, [r1, #0x4] */
/* @0x20a020 cmp r12, #0 */
/* @0x20a024 bne 0x20a068 <_ZN12CDS_Priority6AssignEPS_+0x5f0> */
/* @0x20a028 ldr r0, [r1] */
/* @0x20a02c str r1, [sp, #0x8] */
/* @0x20a030 str r12, [sp, #0xc] */
/* @0x20a034 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20a038 ldr r1, [sp, #0x8] */
/* @0x20a03c ldr r12, [sp, #0xc] */
/* @0x20a040 mov r0, r1 */
/* @0x20a044 str r12, [r1] */
/* @0x20a048 str r12, [r1, #0x8] */
/* @0x20a04c str r1, [sp, #0x8] */
/* @0x20a050 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x20a054 ldr r1, [sp, #0x8] */
/* @0x20a058 mov r0, r1 */
/* @0x20a05c bl 0x27d1d0 <_ZdlPv> */
/* @0x20a060 ldr r3, [sp, #0x4] */
/* @0x20a064 ldr r1, [sp, #0x8] */
/* @0x20a068 str r3, [sp, #0x4] */
/* @0x20a06c str r1, [sp, #0x8] */
/* @0x20a070 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20a074 ldr r1, [sp, #0x8] */
/* @0x20a078 mov r0, r1 */
/* @0x20a07c bl 0x27d1d0 <_ZdlPv> */
/* @0x20a080 ldr r3, [sp, #0x4] */
/* @0x20a084 ldr r1, [sp, #0x8] */
/* @0x20a088 b 0x209fc0 <_ZN12CDS_Priority6AssignEPS_+0x548> */
/* @0x20a08c ldr r0, [r1] */
/* @0x20a090 str r1, [sp, #0x8] */
/* @0x20a094 str r12, [sp, #0xc] */
/* @0x20a098 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20a09c ldr r1, [sp, #0x8] */
/* @0x20a0a0 ldr r12, [sp, #0xc] */
/* @0x20a0a4 str r12, [r1] */
/* @0x20a0a8 str r12, [r1, #0x8] */
/* @0x20a0ac str r1, [sp, #0x8] */
/* @0x20a0b0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20a0b4 ldr r1, [sp, #0x8] */
/* @0x20a0b8 ldr r3, [sp, #0x4] */
/* @0x20a0bc ldr r12, [r1, #0x4] */
/* @0x20a0c0 sub r12, r12, #1 */
/* @0x20a0c4 str r12, [r1, #0x4] */
/* @0x20a0c8 cmp r12, #0 */
/* @0x20a0cc bne 0x20a110 <_ZN12CDS_Priority6AssignEPS_+0x698> */
/* @0x20a0d0 ldr r0, [r1] */
/* @0x20a0d4 str r1, [sp, #0x8] */
/* @0x20a0d8 str r12, [sp, #0xc] */
/* @0x20a0dc bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20a0e0 ldr r1, [sp, #0x8] */
/* @0x20a0e4 ldr r12, [sp, #0xc] */
/* @0x20a0e8 mov r0, r1 */
/* @0x20a0ec str r12, [r1] */
/* @0x20a0f0 str r12, [r1, #0x8] */
/* @0x20a0f4 str r1, [sp, #0x8] */
/* @0x20a0f8 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x20a0fc ldr r1, [sp, #0x8] */
/* @0x20a100 mov r0, r1 */
/* @0x20a104 bl 0x27d1d0 <_ZdlPv> */
/* @0x20a108 ldr r3, [sp, #0x4] */
/* @0x20a10c ldr r1, [sp, #0x8] */
/* @0x20a110 str r3, [sp, #0x4] */
/* @0x20a114 str r1, [sp, #0x8] */
/* @0x20a118 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20a11c ldr r1, [sp, #0x8] */
/* @0x20a120 mov r0, r1 */
/* @0x20a124 bl 0x27d1d0 <_ZdlPv> */
/* @0x20a128 ldr r3, [sp, #0x4] */
/* @0x20a12c ldr r1, [sp, #0x8] */
/* @0x20a130 b 0x209f58 <_ZN12CDS_Priority6AssignEPS_+0x4e0> */
/* @0x20a134 add sp, sp, #20 */
/* @0x20a138 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x20a13c b 0x209768 <_ZN12CDS_Priority5ClearEv> */
/* @0x20a140 andseq r9, r4, r8, asr #26 */
/* @0x20a144 andseq r9, r4, r8, asr #24 */

/* ── FUNC 0x20a148 · CDS_Priority::Change(RValue*, RValue*) · size=732 · insn=183 */
/* @0x20a148 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x20a14c mov r5, r0 */
/* @0x20a150 ldr r3, [r0, #0x4] */
/* @0x20a154 mov r8, r1 */
/* @0x20a158 mov r9, r2 */
/* @0x20a15c cmp r3, #0 */
/* @0x20a160 pople {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x20a164 ldr r7, [pc, #0x2b4] */
/* @0x20a168 mov r4, #0 */
/* @0x20a16c ldr r7, [pc, r7] */
/* @0x20a170 b 0x20a180 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x38> */
/* @0x20a174 ldr r3, [r5, #0x4] */
/* @0x20a178 cmp r3, r4 */
/* @0x20a17c ble 0x20a280 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x138> */
/* @0x20a180 ldr r0, [r5, #0xc] */
/* @0x20a184 lsl r6, r4, #4 */
/* @0x20a188 mov r1, r8 */
/* @0x20a18c ldrd r2, r3, [r7] */
/* @0x20a190 add r0, r0, r6 */
/* @0x20a194 add r4, r4, #1 */
/* @0x20a198 bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d> */
/* @0x20a19c cmp r0, #0 */
/* @0x20a1a0 bne 0x20a174 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x2c> */
/* @0x20a1a4 ldr r8, [r5, #0x14] */
/* @0x20a1a8 add r7, r8, r6 */
/* @0x20a1ac ldr r3, [r7, #0xc] */
/* @0x20a1b0 sub r3, r3, #1 */
/* @0x20a1b4 bic r3, r3, #-16777216 */
/* @0x20a1b8 bic r3, r3, #3 */
/* @0x20a1bc cmp r3, #0 */
/* @0x20a1c0 movne r4, r7 */
/* @0x20a1c4 beq 0x20a338 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x1f0> */
/* @0x20a1c8 mov r3, #5 */
/* @0x20a1cc str r3, [r7, #0xc] */
/* @0x20a1d0 ldr r1, [r4, #0xc] */
/* @0x20a1d4 mov r3, #0 */
/* @0x20a1d8 str r3, [r7, #0x8] */
/* @0x20a1dc bic r2, r1, #-16777216 */
/* @0x20a1e0 str r3, [r8, r6] */
/* @0x20a1e4 cmp r2, #1 */
/* @0x20a1e8 beq 0x20a304 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x1bc> */
/* @0x20a1ec cmp r2, #2 */
/* @0x20a1f0 bne 0x20a218 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0xd0> */
/* @0x20a1f4 sub r3, r1, #1 */
/* @0x20a1f8 bic r3, r3, #-16777216 */
/* @0x20a1fc bic r3, r3, #3 */
/* @0x20a200 cmp r3, #0 */
/* @0x20a204 beq 0x20a3bc <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x274> */
/* @0x20a208 mov r2, #0 */
/* @0x20a20c mov r3, #5 */
/* @0x20a210 str r2, [r4, #0x8] */
/* @0x20a214 str r3, [r4, #0xc] */
/* @0x20a218 ldr r3, [r9, #0xc] */
/* @0x20a21c mov r1, #0 */
/* @0x20a220 ldr r2, [r9, #0x8] */
/* @0x20a224 str r1, [r4] */
/* @0x20a228 str r3, [r4, #0xc] */
/* @0x20a22c ldr r3, [r9, #0xc] */
/* @0x20a230 str r2, [r4, #0x8] */
/* @0x20a234 bic r3, r3, #-16777216 */
/* @0x20a238 cmp r3, #14 */
/* @0x20a23c addls pc, pc, r3, lsl #2 */
/* @0x20a240 b 0x20a280 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x138> */
/* @0x20a244 b 0x20a290 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x148> */
/* @0x20a248 b 0x20a2ec <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x1a4> */
/* @0x20a24c b 0x20a2c0 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x178> */
/* @0x20a250 b 0x20a284 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x13c> */
/* @0x20a254 b 0x20a280 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x138> */
/* @0x20a258 b 0x20a280 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x138> */
/* @0x20a25c b 0x20a29c <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x154> */
/* @0x20a260 b 0x20a284 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x13c> */
/* @0x20a264 b 0x20a280 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x138> */
/* @0x20a268 b 0x20a280 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x138> */
/* @0x20a26c b 0x20a290 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x148> */
/* @0x20a270 b 0x20a280 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x138> */
/* @0x20a274 b 0x20a280 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x138> */
/* @0x20a278 b 0x20a290 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x148> */
/* @0x20a27c b 0x20a284 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x13c> */
/* @0x20a280 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x20a284 ldr r3, [r9] */
/* @0x20a288 str r3, [r4] */
/* @0x20a28c pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x20a290 ldm r9, {r2, r3} */
/* @0x20a294 stm r4, {r2, r3} */
/* @0x20a298 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x20a29c ldr r3, [r9] */
/* @0x20a2a0 str r3, [r4] */
/* @0x20a2a4 ldr r3, [r9] */
/* @0x20a2a8 cmp r3, #0 */
/* @0x20a2ac popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x20a2b0 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x20a2b4 ldr r1, [r9] */
/* @0x20a2b8 pop {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x20a2bc b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x20a2c0 ldr r3, [r9] */
/* @0x20a2c4 cmp r3, #0 */
/* @0x20a2c8 str r3, [r4] */
/* @0x20a2cc popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x20a2d0 ldr r1, [r3, #0x8] */
/* @0x20a2d4 ldr r2, [r3] */
/* @0x20a2d8 cmp r1, #0 */
/* @0x20a2dc streq r4, [r3, #0x8] */
/* @0x20a2e0 add r2, r2, #1 */
/* @0x20a2e4 str r2, [r3] */
/* @0x20a2e8 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x20a2ec ldr r3, [r9] */
/* @0x20a2f0 cmp r3, #0 */
/* @0x20a2f4 ldrne r2, [r3, #0x4] */
/* @0x20a2f8 addne r2, r2, #1 */
/* @0x20a2fc strne r2, [r3, #0x4] */
/* @0x20a300 b 0x20a288 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x140> */
/* @0x20a304 ldr r5, [r4] */
/* @0x20a308 cmp r5, #0 */
/* @0x20a30c beq 0x20a32c <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x1e4> */
/* @0x20a310 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20a314 ldr r6, [r5, #0x4] */
/* @0x20a318 sub r6, r6, #1 */
/* @0x20a31c str r6, [r5, #0x4] */
/* @0x20a320 cmp r6, #0 */
/* @0x20a324 beq 0x20a34c <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x204> */
/* @0x20a328 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20a32c mov r3, #0 */
/* @0x20a330 str r3, [r4] */
/* @0x20a334 b 0x20a218 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0xd0> */
/* @0x20a338 mov r0, r7 */
/* @0x20a33c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20a340 ldr r4, [r5, #0x14] */
/* @0x20a344 add r4, r4, r6 */
/* @0x20a348 b 0x20a1c8 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x80> */
/* @0x20a34c ldr r0, [r5] */
/* @0x20a350 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20a354 str r6, [r5] */
/* @0x20a358 str r6, [r5, #0x8] */
/* @0x20a35c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20a360 ldr r6, [r5, #0x4] */
/* @0x20a364 sub r6, r6, #1 */
/* @0x20a368 str r6, [r5, #0x4] */
/* @0x20a36c cmp r6, #0 */
/* @0x20a370 beq 0x20a384 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x23c> */
/* @0x20a374 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20a378 mov r0, r5 */
/* @0x20a37c bl 0x27d1d0 <_ZdlPv> */
/* @0x20a380 b 0x20a328 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x1e0> */
/* @0x20a384 ldr r0, [r5] */
/* @0x20a388 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20a38c str r6, [r5] */
/* @0x20a390 str r6, [r5, #0x8] */
/* @0x20a394 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20a398 ldr r6, [r5, #0x4] */
/* @0x20a39c sub r6, r6, #1 */
/* @0x20a3a0 str r6, [r5, #0x4] */
/* @0x20a3a4 cmp r6, #0 */
/* @0x20a3a8 beq 0x20a3c8 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x280> */
/* @0x20a3ac bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20a3b0 mov r0, r5 */
/* @0x20a3b4 bl 0x27d1d0 <_ZdlPv> */
/* @0x20a3b8 b 0x20a374 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x22c> */
/* @0x20a3bc mov r0, r4 */
/* @0x20a3c0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20a3c4 b 0x20a208 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0xc0> */
/* @0x20a3c8 ldr r0, [r5] */
/* @0x20a3cc bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20a3d0 str r6, [r5] */
/* @0x20a3d4 str r6, [r5, #0x8] */
/* @0x20a3d8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20a3dc ldr r6, [r5, #0x4] */
/* @0x20a3e0 sub r6, r6, #1 */
/* @0x20a3e4 str r6, [r5, #0x4] */
/* @0x20a3e8 cmp r6, #0 */
/* @0x20a3ec bne 0x20a410 <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x2c8> */
/* @0x20a3f0 ldr r0, [r5] */
/* @0x20a3f4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20a3f8 mov r0, r5 */
/* @0x20a3fc str r6, [r5] */
/* @0x20a400 str r6, [r5, #0x8] */
/* @0x20a404 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x20a408 mov r0, r5 */
/* @0x20a40c bl 0x27d1d0 <_ZdlPv> */
/* @0x20a410 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20a414 mov r0, r5 */
/* @0x20a418 bl 0x27d1d0 <_ZdlPv> */
/* @0x20a41c b 0x20a3ac <_ZN12CDS_Priority6ChangeEP6RValueS1_+0x264> */
/* @0x20a420 andseq r7, lr, r8, lsl r2 */

/* ── FUNC 0x20a424 · CDS_Priority::Delete(RValue*) · size=1400 · insn=350 */
/* @0x20a424 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x20a428 mov r5, r0 */
/* @0x20a42c ldr r3, [r0, #0x4] */
/* @0x20a430 mov r8, r1 */
/* @0x20a434 cmp r3, #0 */
/* @0x20a438 pople {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x20a43c ldr r7, [pc, #0x554] */
/* @0x20a440 mov r4, #0 */
/* @0x20a444 ldr r7, [pc, r7] */
/* @0x20a448 b 0x20a458 <_ZN12CDS_Priority6DeleteEP6RValue+0x34> */
/* @0x20a44c ldr r3, [r5, #0x4] */
/* @0x20a450 cmp r3, r4 */
/* @0x20a454 ble 0x20a59c <_ZN12CDS_Priority6DeleteEP6RValue+0x178> */
/* @0x20a458 ldr r0, [r5, #0xc] */
/* @0x20a45c lsl r6, r4, #4 */
/* @0x20a460 mov r1, r8 */
/* @0x20a464 ldrd r2, r3, [r7] */
/* @0x20a468 add r0, r0, r6 */
/* @0x20a46c add r4, r4, #1 */
/* @0x20a470 bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d> */
/* @0x20a474 cmp r0, #0 */
/* @0x20a478 bne 0x20a44c <_ZN12CDS_Priority6DeleteEP6RValue+0x28> */
/* @0x20a47c ldr r7, [r5, #0xc] */
/* @0x20a480 add r4, r7, r6 */
/* @0x20a484 ldr r3, [r4, #0xc] */
/* @0x20a488 sub r3, r3, #1 */
/* @0x20a48c bic r3, r3, #-16777216 */
/* @0x20a490 bic r3, r3, #3 */
/* @0x20a494 cmp r3, #0 */
/* @0x20a498 beq 0x20a7e4 <_ZN12CDS_Priority6DeleteEP6RValue+0x3c0> */
/* @0x20a49c mov r3, #0 */
/* @0x20a4a0 mov r2, #5 */
/* @0x20a4a4 str r3, [r4, #0x8] */
/* @0x20a4a8 str r2, [r4, #0xc] */
/* @0x20a4ac str r3, [r7, r6] */
/* @0x20a4b0 ldr r7, [r5, #0x14] */
/* @0x20a4b4 add r4, r7, r6 */
/* @0x20a4b8 ldr r3, [r4, #0xc] */
/* @0x20a4bc sub r3, r3, #1 */
/* @0x20a4c0 bic r3, r3, #-16777216 */
/* @0x20a4c4 bic r3, r3, #3 */
/* @0x20a4c8 cmp r3, #0 */
/* @0x20a4cc beq 0x20a7d8 <_ZN12CDS_Priority6DeleteEP6RValue+0x3b4> */
/* @0x20a4d0 mov r3, #0 */
/* @0x20a4d4 mov r2, #5 */
/* @0x20a4d8 str r3, [r4, #0x8] */
/* @0x20a4dc str r2, [r4, #0xc] */
/* @0x20a4e0 str r3, [r7, r6] */
/* @0x20a4e4 ldr r4, [r5, #0xc] */
/* @0x20a4e8 ldr r9, [r5, #0x4] */
/* @0x20a4ec add r7, r4, r6 */
/* @0x20a4f0 sub r9, r9, #-268435455 */
/* @0x20a4f4 ldr r2, [r7, #0xc] */
/* @0x20a4f8 add r8, r4, r9, lsl #4 */
/* @0x20a4fc bic r3, r2, #-16777216 */
/* @0x20a500 cmp r3, #1 */
/* @0x20a504 beq 0x20a7a4 <_ZN12CDS_Priority6DeleteEP6RValue+0x380> */
/* @0x20a508 cmp r3, #2 */
/* @0x20a50c bne 0x20a534 <_ZN12CDS_Priority6DeleteEP6RValue+0x110> */
/* @0x20a510 sub r3, r2, #1 */
/* @0x20a514 bic r3, r3, #-16777216 */
/* @0x20a518 bic r3, r3, #3 */
/* @0x20a51c cmp r3, #0 */
/* @0x20a520 beq 0x20a8d0 <_ZN12CDS_Priority6DeleteEP6RValue+0x4ac> */
/* @0x20a524 mov r2, #0 */
/* @0x20a528 mov r3, #5 */
/* @0x20a52c str r2, [r7, #0x8] */
/* @0x20a530 str r3, [r7, #0xc] */
/* @0x20a534 ldr r3, [r8, #0xc] */
/* @0x20a538 mov r1, #0 */
/* @0x20a53c ldr r2, [r8, #0x8] */
/* @0x20a540 str r1, [r4, r6] */
/* @0x20a544 str r3, [r7, #0xc] */
/* @0x20a548 ldr r3, [r8, #0xc] */
/* @0x20a54c str r2, [r7, #0x8] */
/* @0x20a550 bic r3, r3, #-16777216 */
/* @0x20a554 cmp r3, #14 */
/* @0x20a558 addls pc, pc, r3, lsl #2 */
/* @0x20a55c b 0x20a5a8 <_ZN12CDS_Priority6DeleteEP6RValue+0x184> */
/* @0x20a560 b 0x20a678 <_ZN12CDS_Priority6DeleteEP6RValue+0x254> */
/* @0x20a564 b 0x20a758 <_ZN12CDS_Priority6DeleteEP6RValue+0x334> */
/* @0x20a568 b 0x20a6c4 <_ZN12CDS_Priority6DeleteEP6RValue+0x2a0> */
/* @0x20a56c b 0x20a5a0 <_ZN12CDS_Priority6DeleteEP6RValue+0x17c> */
/* @0x20a570 b 0x20a5a8 <_ZN12CDS_Priority6DeleteEP6RValue+0x184> */
/* @0x20a574 b 0x20a5a8 <_ZN12CDS_Priority6DeleteEP6RValue+0x184> */
/* @0x20a578 b 0x20a6a0 <_ZN12CDS_Priority6DeleteEP6RValue+0x27c> */
/* @0x20a57c b 0x20a5a0 <_ZN12CDS_Priority6DeleteEP6RValue+0x17c> */
/* @0x20a580 b 0x20a5a8 <_ZN12CDS_Priority6DeleteEP6RValue+0x184> */
/* @0x20a584 b 0x20a5a8 <_ZN12CDS_Priority6DeleteEP6RValue+0x184> */
/* @0x20a588 b 0x20a678 <_ZN12CDS_Priority6DeleteEP6RValue+0x254> */
/* @0x20a58c b 0x20a5a8 <_ZN12CDS_Priority6DeleteEP6RValue+0x184> */
/* @0x20a590 b 0x20a5a8 <_ZN12CDS_Priority6DeleteEP6RValue+0x184> */
/* @0x20a594 b 0x20a678 <_ZN12CDS_Priority6DeleteEP6RValue+0x254> */
/* @0x20a598 b 0x20a5a0 <_ZN12CDS_Priority6DeleteEP6RValue+0x17c> */
/* @0x20a59c pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x20a5a0 ldr r3, [r4, r9, lsl #4] */
/* @0x20a5a4 str r3, [r4, r6] */
/* @0x20a5a8 ldr r4, [r5, #0x14] */
/* @0x20a5ac ldr r9, [r5, #0x4] */
/* @0x20a5b0 add r7, r4, r6 */
/* @0x20a5b4 sub r9, r9, #-268435455 */
/* @0x20a5b8 ldr r2, [r7, #0xc] */
/* @0x20a5bc add r8, r4, r9, lsl #4 */
/* @0x20a5c0 bic r3, r2, #-16777216 */
/* @0x20a5c4 cmp r3, #1 */
/* @0x20a5c8 beq 0x20a770 <_ZN12CDS_Priority6DeleteEP6RValue+0x34c> */
/* @0x20a5cc cmp r3, #2 */
/* @0x20a5d0 bne 0x20a5f8 <_ZN12CDS_Priority6DeleteEP6RValue+0x1d4> */
/* @0x20a5d4 sub r3, r2, #1 */
/* @0x20a5d8 bic r3, r3, #-16777216 */
/* @0x20a5dc bic r3, r3, #3 */
/* @0x20a5e0 cmp r3, #0 */
/* @0x20a5e4 beq 0x20a8dc <_ZN12CDS_Priority6DeleteEP6RValue+0x4b8> */
/* @0x20a5e8 mov r2, #0 */
/* @0x20a5ec mov r3, #5 */
/* @0x20a5f0 str r2, [r7, #0x8] */
/* @0x20a5f4 str r3, [r7, #0xc] */
/* @0x20a5f8 ldr r3, [r8, #0xc] */
/* @0x20a5fc mov r1, #0 */
/* @0x20a600 ldr r2, [r8, #0x8] */
/* @0x20a604 str r1, [r4, r6] */
/* @0x20a608 str r3, [r7, #0xc] */
/* @0x20a60c ldr r3, [r8, #0xc] */
/* @0x20a610 str r2, [r7, #0x8] */
/* @0x20a614 bic r3, r3, #-16777216 */
/* @0x20a618 cmp r3, #14 */
/* @0x20a61c addls pc, pc, r3, lsl #2 */
/* @0x20a620 b 0x20a668 <_ZN12CDS_Priority6DeleteEP6RValue+0x244> */
/* @0x20a624 b 0x20a68c <_ZN12CDS_Priority6DeleteEP6RValue+0x268> */
/* @0x20a628 b 0x20a740 <_ZN12CDS_Priority6DeleteEP6RValue+0x31c> */
/* @0x20a62c b 0x20a714 <_ZN12CDS_Priority6DeleteEP6RValue+0x2f0> */
/* @0x20a630 b 0x20a660 <_ZN12CDS_Priority6DeleteEP6RValue+0x23c> */
/* @0x20a634 b 0x20a668 <_ZN12CDS_Priority6DeleteEP6RValue+0x244> */
/* @0x20a638 b 0x20a668 <_ZN12CDS_Priority6DeleteEP6RValue+0x244> */
/* @0x20a63c b 0x20a6f0 <_ZN12CDS_Priority6DeleteEP6RValue+0x2cc> */
/* @0x20a640 b 0x20a660 <_ZN12CDS_Priority6DeleteEP6RValue+0x23c> */
/* @0x20a644 b 0x20a668 <_ZN12CDS_Priority6DeleteEP6RValue+0x244> */
/* @0x20a648 b 0x20a668 <_ZN12CDS_Priority6DeleteEP6RValue+0x244> */
/* @0x20a64c b 0x20a68c <_ZN12CDS_Priority6DeleteEP6RValue+0x268> */
/* @0x20a650 b 0x20a668 <_ZN12CDS_Priority6DeleteEP6RValue+0x244> */
/* @0x20a654 b 0x20a668 <_ZN12CDS_Priority6DeleteEP6RValue+0x244> */
/* @0x20a658 b 0x20a68c <_ZN12CDS_Priority6DeleteEP6RValue+0x268> */
/* @0x20a65c b 0x20a660 <_ZN12CDS_Priority6DeleteEP6RValue+0x23c> */
/* @0x20a660 ldr r3, [r4, r9, lsl #4] */
/* @0x20a664 str r3, [r4, r6] */
/* @0x20a668 ldr r3, [r5, #0x4] */
/* @0x20a66c sub r3, r3, #1 */
/* @0x20a670 str r3, [r5, #0x4] */
/* @0x20a674 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x20a678 ldr r2, [r4, r9, lsl #4] */
/* @0x20a67c ldr r3, [r8, #0x4] */
/* @0x20a680 str r2, [r4, r6] */
/* @0x20a684 str r3, [r7, #0x4] */
/* @0x20a688 b 0x20a5a8 <_ZN12CDS_Priority6DeleteEP6RValue+0x184> */
/* @0x20a68c ldr r2, [r4, r9, lsl #4] */
/* @0x20a690 ldr r3, [r8, #0x4] */
/* @0x20a694 str r2, [r4, r6] */
/* @0x20a698 str r3, [r7, #0x4] */
/* @0x20a69c b 0x20a668 <_ZN12CDS_Priority6DeleteEP6RValue+0x244> */
/* @0x20a6a0 ldr r3, [r4, r9, lsl #4] */
/* @0x20a6a4 str r3, [r4, r6] */
/* @0x20a6a8 ldr r3, [r4, r9, lsl #4] */
/* @0x20a6ac cmp r3, #0 */
/* @0x20a6b0 beq 0x20a5a8 <_ZN12CDS_Priority6DeleteEP6RValue+0x184> */
/* @0x20a6b4 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x20a6b8 ldr r1, [r4, r9, lsl #4] */
/* @0x20a6bc bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x20a6c0 b 0x20a5a8 <_ZN12CDS_Priority6DeleteEP6RValue+0x184> */
/* @0x20a6c4 ldr r3, [r4, r9, lsl #4] */
/* @0x20a6c8 cmp r3, #0 */
/* @0x20a6cc str r3, [r4, r6] */
/* @0x20a6d0 beq 0x20a5a8 <_ZN12CDS_Priority6DeleteEP6RValue+0x184> */
/* @0x20a6d4 ldr r1, [r3, #0x8] */
/* @0x20a6d8 ldr r2, [r3] */
/* @0x20a6dc cmp r1, #0 */
/* @0x20a6e0 streq r7, [r3, #0x8] */
/* @0x20a6e4 add r2, r2, #1 */
/* @0x20a6e8 str r2, [r3] */
/* @0x20a6ec b 0x20a5a8 <_ZN12CDS_Priority6DeleteEP6RValue+0x184> */
/* @0x20a6f0 ldr r3, [r4, r9, lsl #4] */
/* @0x20a6f4 str r3, [r4, r6] */
/* @0x20a6f8 ldr r3, [r4, r9, lsl #4] */
/* @0x20a6fc cmp r3, #0 */
/* @0x20a700 beq 0x20a668 <_ZN12CDS_Priority6DeleteEP6RValue+0x244> */
/* @0x20a704 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x20a708 ldr r1, [r4, r9, lsl #4] */
/* @0x20a70c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x20a710 b 0x20a668 <_ZN12CDS_Priority6DeleteEP6RValue+0x244> */
/* @0x20a714 ldr r3, [r4, r9, lsl #4] */
/* @0x20a718 cmp r3, #0 */
/* @0x20a71c str r3, [r4, r6] */
/* @0x20a720 beq 0x20a668 <_ZN12CDS_Priority6DeleteEP6RValue+0x244> */
/* @0x20a724 ldr r1, [r3, #0x8] */
/* @0x20a728 ldr r2, [r3] */
/* @0x20a72c cmp r1, #0 */
/* @0x20a730 streq r7, [r3, #0x8] */
/* @0x20a734 add r2, r2, #1 */
/* @0x20a738 str r2, [r3] */
/* @0x20a73c b 0x20a668 <_ZN12CDS_Priority6DeleteEP6RValue+0x244> */
/* @0x20a740 ldr r3, [r4, r9, lsl #4] */
/* @0x20a744 cmp r3, #0 */
/* @0x20a748 ldrne r2, [r3, #0x4] */
/* @0x20a74c addne r2, r2, #1 */
/* @0x20a750 strne r2, [r3, #0x4] */
/* @0x20a754 b 0x20a664 <_ZN12CDS_Priority6DeleteEP6RValue+0x240> */
/* @0x20a758 ldr r3, [r4, r9, lsl #4] */
/* @0x20a75c cmp r3, #0 */
/* @0x20a760 ldrne r2, [r3, #0x4] */
/* @0x20a764 addne r2, r2, #1 */
/* @0x20a768 strne r2, [r3, #0x4] */
/* @0x20a76c b 0x20a5a4 <_ZN12CDS_Priority6DeleteEP6RValue+0x180> */
/* @0x20a770 ldr r10, [r4, r6] */
/* @0x20a774 cmp r10, #0 */
/* @0x20a778 beq 0x20a798 <_ZN12CDS_Priority6DeleteEP6RValue+0x374> */
/* @0x20a77c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20a780 ldr r11, [r10, #0x4] */
/* @0x20a784 sub r11, r11, #1 */
/* @0x20a788 str r11, [r10, #0x4] */
/* @0x20a78c cmp r11, #0 */
/* @0x20a790 beq 0x20a7f0 <_ZN12CDS_Priority6DeleteEP6RValue+0x3cc> */
/* @0x20a794 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20a798 mov r3, #0 */
/* @0x20a79c str r3, [r4, r6] */
/* @0x20a7a0 b 0x20a5f8 <_ZN12CDS_Priority6DeleteEP6RValue+0x1d4> */
/* @0x20a7a4 ldr r10, [r4, r6] */
/* @0x20a7a8 cmp r10, #0 */
/* @0x20a7ac beq 0x20a7cc <_ZN12CDS_Priority6DeleteEP6RValue+0x3a8> */
/* @0x20a7b0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20a7b4 ldr r11, [r10, #0x4] */
/* @0x20a7b8 sub r11, r11, #1 */
/* @0x20a7bc str r11, [r10, #0x4] */
/* @0x20a7c0 cmp r11, #0 */
/* @0x20a7c4 beq 0x20a828 <_ZN12CDS_Priority6DeleteEP6RValue+0x404> */
/* @0x20a7c8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20a7cc mov r3, #0 */
/* @0x20a7d0 str r3, [r4, r6] */
/* @0x20a7d4 b 0x20a534 <_ZN12CDS_Priority6DeleteEP6RValue+0x110> */
/* @0x20a7d8 mov r0, r4 */
/* @0x20a7dc bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20a7e0 b 0x20a4d0 <_ZN12CDS_Priority6DeleteEP6RValue+0xac> */
/* @0x20a7e4 mov r0, r4 */
/* @0x20a7e8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20a7ec b 0x20a49c <_ZN12CDS_Priority6DeleteEP6RValue+0x78> */
/* @0x20a7f0 ldr r0, [r10] */
/* @0x20a7f4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20a7f8 str r11, [r10] */
/* @0x20a7fc str r11, [r10, #0x8] */
/* @0x20a800 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20a804 ldr r11, [r10, #0x4] */
/* @0x20a808 sub r11, r11, #1 */
/* @0x20a80c str r11, [r10, #0x4] */
/* @0x20a810 cmp r11, #0 */
/* @0x20a814 beq 0x20a898 <_ZN12CDS_Priority6DeleteEP6RValue+0x474> */
/* @0x20a818 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20a81c mov r0, r10 */
/* @0x20a820 bl 0x27d1d0 <_ZdlPv> */
/* @0x20a824 b 0x20a794 <_ZN12CDS_Priority6DeleteEP6RValue+0x370> */
/* @0x20a828 ldr r0, [r10] */
/* @0x20a82c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20a830 str r11, [r10] */
/* @0x20a834 str r11, [r10, #0x8] */
/* @0x20a838 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20a83c ldr r11, [r10, #0x4] */
/* @0x20a840 sub r11, r11, #1 */
/* @0x20a844 str r11, [r10, #0x4] */
/* @0x20a848 cmp r11, #0 */
/* @0x20a84c beq 0x20a860 <_ZN12CDS_Priority6DeleteEP6RValue+0x43c> */
/* @0x20a850 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20a854 mov r0, r10 */
/* @0x20a858 bl 0x27d1d0 <_ZdlPv> */
/* @0x20a85c b 0x20a7c8 <_ZN12CDS_Priority6DeleteEP6RValue+0x3a4> */
/* @0x20a860 ldr r0, [r10] */
/* @0x20a864 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20a868 str r11, [r10] */
/* @0x20a86c str r11, [r10, #0x8] */
/* @0x20a870 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20a874 ldr r11, [r10, #0x4] */
/* @0x20a878 sub r11, r11, #1 */
/* @0x20a87c str r11, [r10, #0x4] */
/* @0x20a880 cmp r11, #0 */
/* @0x20a884 beq 0x20a8e8 <_ZN12CDS_Priority6DeleteEP6RValue+0x4c4> */
/* @0x20a888 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20a88c mov r0, r10 */
/* @0x20a890 bl 0x27d1d0 <_ZdlPv> */
/* @0x20a894 b 0x20a850 <_ZN12CDS_Priority6DeleteEP6RValue+0x42c> */
/* @0x20a898 ldr r0, [r10] */
/* @0x20a89c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20a8a0 str r11, [r10] */
/* @0x20a8a4 str r11, [r10, #0x8] */
/* @0x20a8a8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20a8ac ldr r11, [r10, #0x4] */
/* @0x20a8b0 sub r11, r11, #1 */
/* @0x20a8b4 str r11, [r10, #0x4] */
/* @0x20a8b8 cmp r11, #0 */
/* @0x20a8bc beq 0x20a940 <_ZN12CDS_Priority6DeleteEP6RValue+0x51c> */
/* @0x20a8c0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20a8c4 mov r0, r10 */
/* @0x20a8c8 bl 0x27d1d0 <_ZdlPv> */
/* @0x20a8cc b 0x20a818 <_ZN12CDS_Priority6DeleteEP6RValue+0x3f4> */
/* @0x20a8d0 mov r0, r7 */
/* @0x20a8d4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20a8d8 b 0x20a524 <_ZN12CDS_Priority6DeleteEP6RValue+0x100> */
/* @0x20a8dc mov r0, r7 */
/* @0x20a8e0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20a8e4 b 0x20a5e8 <_ZN12CDS_Priority6DeleteEP6RValue+0x1c4> */
/* @0x20a8e8 ldr r0, [r10] */
/* @0x20a8ec bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20a8f0 str r11, [r10] */
/* @0x20a8f4 str r11, [r10, #0x8] */
/* @0x20a8f8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20a8fc ldr r11, [r10, #0x4] */
/* @0x20a900 sub r11, r11, #1 */
/* @0x20a904 str r11, [r10, #0x4] */
/* @0x20a908 cmp r11, #0 */
/* @0x20a90c bne 0x20a930 <_ZN12CDS_Priority6DeleteEP6RValue+0x50c> */
/* @0x20a910 ldr r0, [r10] */
/* @0x20a914 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20a918 mov r0, r10 */
/* @0x20a91c str r11, [r10] */
/* @0x20a920 str r11, [r10, #0x8] */
/* @0x20a924 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x20a928 mov r0, r10 */
/* @0x20a92c bl 0x27d1d0 <_ZdlPv> */
/* @0x20a930 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20a934 mov r0, r10 */
/* @0x20a938 bl 0x27d1d0 <_ZdlPv> */
/* @0x20a93c b 0x20a888 <_ZN12CDS_Priority6DeleteEP6RValue+0x464> */
/* @0x20a940 ldr r0, [r10] */
/* @0x20a944 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20a948 str r11, [r10] */
/* @0x20a94c str r11, [r10, #0x8] */
/* @0x20a950 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20a954 ldr r11, [r10, #0x4] */
/* @0x20a958 sub r11, r11, #1 */
/* @0x20a95c str r11, [r10, #0x4] */
/* @0x20a960 cmp r11, #0 */
/* @0x20a964 bne 0x20a988 <_ZN12CDS_Priority6DeleteEP6RValue+0x564> */
/* @0x20a968 ldr r0, [r10] */
/* @0x20a96c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20a970 mov r0, r10 */
/* @0x20a974 str r11, [r10] */
/* @0x20a978 str r11, [r10, #0x8] */
/* @0x20a97c bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x20a980 mov r0, r10 */
/* @0x20a984 bl 0x27d1d0 <_ZdlPv> */
/* @0x20a988 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20a98c mov r0, r10 */
/* @0x20a990 bl 0x27d1d0 <_ZdlPv> */
/* @0x20a994 b 0x20a8c0 <_ZN12CDS_Priority6DeleteEP6RValue+0x49c> */
/* @0x20a998 andseq r6, lr, r0, asr #30 */

/* ── FUNC 0x20a99c · CDS_Priority::DeleteMin(RValue*) · size=816 · insn=204 */
/* @0x20a99c push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x20a9a0 mov r7, #0 */
/* @0x20a9a4 str r7, [r1] */
/* @0x20a9a8 mov r9, r1 */
/* @0x20a9ac str r7, [r1, #0x4] */
/* @0x20a9b0 mov r6, r0 */
/* @0x20a9b4 ldr r3, [r0, #0x4] */
/* @0x20a9b8 str r7, [r1, #0xc] */
/* @0x20a9bc cmp r3, r7 */
/* @0x20a9c0 popeq {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x20a9c4 cmp r3, #1 */
/* @0x20a9c8 ble 0x20ac98 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x2fc> */
/* @0x20a9cc ldr r10, [pc, #0x2f4] */
/* @0x20a9d0 mov r4, #1 */
/* @0x20a9d4 ldr r10, [pc, r10] */
/* @0x20a9d8 ldr r1, [r6, #0x14] */
/* @0x20a9dc lsl r8, r4, #4 */
/* @0x20a9e0 lsl r5, r7, #4 */
/* @0x20a9e4 ldrd r2, r3, [r10] */
/* @0x20a9e8 add r0, r1, r8 */
/* @0x20a9ec add r1, r1, r5 */
/* @0x20a9f0 bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d> */
/* @0x20a9f4 ldr r3, [r6, #0x4] */
/* @0x20a9f8 cmp r0, #0 */
/* @0x20a9fc movlt r7, r4 */
/* @0x20aa00 add r4, r4, #1 */
/* @0x20aa04 movlt r5, r8 */
/* @0x20aa08 cmp r3, r4 */
/* @0x20aa0c bgt 0x20a9d8 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x3c> */
/* @0x20aa10 ldr r2, [r9, #0xc] */
/* @0x20aa14 ldr r4, [r6, #0xc] */
/* @0x20aa18 bic r3, r2, #-16777216 */
/* @0x20aa1c cmp r3, #1 */
/* @0x20aa20 add r4, r4, r5 */
/* @0x20aa24 beq 0x20aabc <_ZN12CDS_Priority9DeleteMinEP6RValue+0x120> */
/* @0x20aa28 cmp r3, #2 */
/* @0x20aa2c bne 0x20aa54 <_ZN12CDS_Priority9DeleteMinEP6RValue+0xb8> */
/* @0x20aa30 sub r3, r2, #1 */
/* @0x20aa34 bic r3, r3, #-16777216 */
/* @0x20aa38 bic r3, r3, #3 */
/* @0x20aa3c cmp r3, #0 */
/* @0x20aa40 beq 0x20ac3c <_ZN12CDS_Priority9DeleteMinEP6RValue+0x2a0> */
/* @0x20aa44 mov r2, #0 */
/* @0x20aa48 mov r3, #5 */
/* @0x20aa4c str r2, [r9, #0x8] */
/* @0x20aa50 str r3, [r9, #0xc] */
/* @0x20aa54 ldr r3, [r4, #0xc] */
/* @0x20aa58 mov r1, #0 */
/* @0x20aa5c ldr r2, [r4, #0x8] */
/* @0x20aa60 str r1, [r9] */
/* @0x20aa64 str r3, [r9, #0xc] */
/* @0x20aa68 ldr r3, [r4, #0xc] */
/* @0x20aa6c str r2, [r9, #0x8] */
/* @0x20aa70 bic r3, r3, #-16777216 */
/* @0x20aa74 cmp r3, #14 */
/* @0x20aa78 addls pc, pc, r3, lsl #2 */
/* @0x20aa7c b 0x20aaf8 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x15c> */
/* @0x20aa80 b 0x20abc8 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x22c> */
/* @0x20aa84 b 0x20ac00 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x264> */
/* @0x20aa88 b 0x20abd4 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x238> */
/* @0x20aa8c b 0x20aaf0 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x154> */
/* @0x20aa90 b 0x20aaf8 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x15c> */
/* @0x20aa94 b 0x20aaf8 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x15c> */
/* @0x20aa98 b 0x20ac18 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x27c> */
/* @0x20aa9c b 0x20aaf0 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x154> */
/* @0x20aaa0 b 0x20aaf8 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x15c> */
/* @0x20aaa4 b 0x20aaf8 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x15c> */
/* @0x20aaa8 b 0x20abc8 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x22c> */
/* @0x20aaac b 0x20aaf8 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x15c> */
/* @0x20aab0 b 0x20aaf8 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x15c> */
/* @0x20aab4 b 0x20abc8 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x22c> */
/* @0x20aab8 b 0x20aaf0 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x154> */
/* @0x20aabc ldr r7, [r9] */
/* @0x20aac0 cmp r7, #0 */
/* @0x20aac4 beq 0x20aae4 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x148> */
/* @0x20aac8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20aacc ldr r8, [r7, #0x4] */
/* @0x20aad0 sub r8, r8, #1 */
/* @0x20aad4 str r8, [r7, #0x4] */
/* @0x20aad8 cmp r8, #0 */
/* @0x20aadc beq 0x20ac60 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x2c4> */
/* @0x20aae0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20aae4 mov r3, #0 */
/* @0x20aae8 str r3, [r9] */
/* @0x20aaec b 0x20aa54 <_ZN12CDS_Priority9DeleteMinEP6RValue+0xb8> */
/* @0x20aaf0 ldr r3, [r4] */
/* @0x20aaf4 str r3, [r9] */
/* @0x20aaf8 ldr r7, [r6, #0xc] */
/* @0x20aafc add r7, r7, r5 */
/* @0x20ab00 ldr r3, [r7, #0xc] */
/* @0x20ab04 sub r3, r3, #1 */
/* @0x20ab08 bic r3, r3, #-16777216 */
/* @0x20ab0c bic r3, r3, #3 */
/* @0x20ab10 cmp r3, #0 */
/* @0x20ab14 beq 0x20ac54 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x2b8> */
/* @0x20ab18 mov r3, #0 */
/* @0x20ab1c str r3, [r7] */
/* @0x20ab20 ldr r4, [r6, #0x14] */
/* @0x20ab24 mov r2, #5 */
/* @0x20ab28 str r3, [r7, #0x8] */
/* @0x20ab2c add r4, r4, r5 */
/* @0x20ab30 str r2, [r7, #0xc] */
/* @0x20ab34 ldr r3, [r4, #0xc] */
/* @0x20ab38 sub r3, r3, #1 */
/* @0x20ab3c bic r3, r3, #-16777216 */
/* @0x20ab40 bic r3, r3, #3 */
/* @0x20ab44 cmp r3, #0 */
/* @0x20ab48 beq 0x20ac48 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x2ac> */
/* @0x20ab4c mov r7, #0 */
/* @0x20ab50 str r7, [r4] */
/* @0x20ab54 ldr r1, [r6, #0x4] */
/* @0x20ab58 mov r12, #5 */
/* @0x20ab5c ldr r3, [r6, #0xc] */
/* @0x20ab60 mov r2, #16 */
/* @0x20ab64 sub r1, r1, #-268435455 */
/* @0x20ab68 str r12, [r4, #0xc] */
/* @0x20ab6c add r0, r3, r5 */
/* @0x20ab70 str r7, [r4, #0x8] */
/* @0x20ab74 add r1, r3, r1, lsl #4 */
/* @0x20ab78 bl 0xb6694 <memmove@plt> */
/* @0x20ab7c ldr r3, [r6, #0x4] */
/* @0x20ab80 ldr r12, [r6, #0xc] */
/* @0x20ab84 mov r2, #16 */
/* @0x20ab88 sub r3, r3, #-268435455 */
/* @0x20ab8c ldr r1, [r6, #0x14] */
/* @0x20ab90 lsl r3, r3, #4 */
/* @0x20ab94 add r0, r1, r5 */
/* @0x20ab98 add r12, r12, r3 */
/* @0x20ab9c add r1, r1, r3 */
/* @0x20aba0 str r7, [r12, #0xc] */
/* @0x20aba4 bl 0xb6694 <memmove@plt> */
/* @0x20aba8 ldr r3, [r6, #0x4] */
/* @0x20abac ldr r2, [r6, #0x14] */
/* @0x20abb0 sub r1, r3, #-268435455 */
/* @0x20abb4 sub r3, r3, #1 */
/* @0x20abb8 add r2, r2, r1, lsl #4 */
/* @0x20abbc str r7, [r2, #0xc] */
/* @0x20abc0 str r3, [r6, #0x4] */
/* @0x20abc4 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x20abc8 ldm r4, {r2, r3} */
/* @0x20abcc stm r9, {r2, r3} */
/* @0x20abd0 b 0x20aaf8 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x15c> */
/* @0x20abd4 ldr r3, [r4] */
/* @0x20abd8 cmp r3, #0 */
/* @0x20abdc str r3, [r9] */
/* @0x20abe0 beq 0x20aaf8 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x15c> */
/* @0x20abe4 ldr r1, [r3, #0x8] */
/* @0x20abe8 ldr r2, [r3] */
/* @0x20abec cmp r1, #0 */
/* @0x20abf0 streq r9, [r3, #0x8] */
/* @0x20abf4 add r2, r2, #1 */
/* @0x20abf8 str r2, [r3] */
/* @0x20abfc b 0x20aaf8 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x15c> */
/* @0x20ac00 ldr r3, [r4] */
/* @0x20ac04 cmp r3, #0 */
/* @0x20ac08 ldrne r2, [r3, #0x4] */
/* @0x20ac0c addne r2, r2, #1 */
/* @0x20ac10 strne r2, [r3, #0x4] */
/* @0x20ac14 b 0x20aaf4 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x158> */
/* @0x20ac18 ldr r3, [r4] */
/* @0x20ac1c str r3, [r9] */
/* @0x20ac20 ldr r3, [r4] */
/* @0x20ac24 cmp r3, #0 */
/* @0x20ac28 beq 0x20aaf8 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x15c> */
/* @0x20ac2c bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x20ac30 ldr r1, [r4] */
/* @0x20ac34 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x20ac38 b 0x20aaf8 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x15c> */
/* @0x20ac3c mov r0, r9 */
/* @0x20ac40 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20ac44 b 0x20aa44 <_ZN12CDS_Priority9DeleteMinEP6RValue+0xa8> */
/* @0x20ac48 mov r0, r4 */
/* @0x20ac4c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20ac50 b 0x20ab4c <_ZN12CDS_Priority9DeleteMinEP6RValue+0x1b0> */
/* @0x20ac54 mov r0, r7 */
/* @0x20ac58 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20ac5c b 0x20ab18 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x17c> */
/* @0x20ac60 ldr r0, [r7] */
/* @0x20ac64 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20ac68 str r8, [r7] */
/* @0x20ac6c str r8, [r7, #0x8] */
/* @0x20ac70 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20ac74 ldr r8, [r7, #0x4] */
/* @0x20ac78 sub r8, r8, #1 */
/* @0x20ac7c str r8, [r7, #0x4] */
/* @0x20ac80 cmp r8, #0 */
/* @0x20ac84 beq 0x20aca4 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x308> */
/* @0x20ac88 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20ac8c mov r0, r7 */
/* @0x20ac90 bl 0x27d1d0 <_ZdlPv> */
/* @0x20ac94 b 0x20aae0 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x144> */
/* @0x20ac98 mov r5, r7 */
/* @0x20ac9c ldr r4, [r0, #0xc] */
/* @0x20aca0 b 0x20aa54 <_ZN12CDS_Priority9DeleteMinEP6RValue+0xb8> */
/* @0x20aca4 ldr r0, [r7] */
/* @0x20aca8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20acac mov r0, r7 */
/* @0x20acb0 str r8, [r7] */
/* @0x20acb4 str r8, [r7, #0x8] */
/* @0x20acb8 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x20acbc mov r0, r7 */
/* @0x20acc0 bl 0x27d1d0 <_ZdlPv> */
/* @0x20acc4 b 0x20ac88 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x2ec> */
/* @0x20acc8 ldrheq r6, [lr], -r0 */

/* ── FUNC 0x20accc · CDS_Priority::DeleteMax(RValue*) · size=816 · insn=204 */
/* @0x20accc push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x20acd0 mov r7, #0 */
/* @0x20acd4 str r7, [r1] */
/* @0x20acd8 mov r9, r1 */
/* @0x20acdc str r7, [r1, #0x4] */
/* @0x20ace0 mov r6, r0 */
/* @0x20ace4 ldr r3, [r0, #0x4] */
/* @0x20ace8 str r7, [r1, #0xc] */
/* @0x20acec cmp r3, r7 */
/* @0x20acf0 popeq {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x20acf4 cmp r3, #1 */
/* @0x20acf8 ble 0x20afc8 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x2fc> */
/* @0x20acfc ldr r10, [pc, #0x2f4] */
/* @0x20ad00 mov r4, #1 */
/* @0x20ad04 ldr r10, [pc, r10] */
/* @0x20ad08 ldr r1, [r6, #0x14] */
/* @0x20ad0c lsl r5, r4, #4 */
/* @0x20ad10 lsl r8, r7, #4 */
/* @0x20ad14 ldrd r2, r3, [r10] */
/* @0x20ad18 add r0, r1, r5 */
/* @0x20ad1c add r1, r1, r8 */
/* @0x20ad20 bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d> */
/* @0x20ad24 ldr r3, [r6, #0x4] */
/* @0x20ad28 cmp r0, #0 */
/* @0x20ad2c movgt r7, r4 */
/* @0x20ad30 add r4, r4, #1 */
/* @0x20ad34 movle r5, r8 */
/* @0x20ad38 cmp r3, r4 */
/* @0x20ad3c bgt 0x20ad08 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x3c> */
/* @0x20ad40 ldr r2, [r9, #0xc] */
/* @0x20ad44 ldr r4, [r6, #0xc] */
/* @0x20ad48 bic r3, r2, #-16777216 */
/* @0x20ad4c cmp r3, #1 */
/* @0x20ad50 add r4, r4, r5 */
/* @0x20ad54 beq 0x20adec <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x120> */
/* @0x20ad58 cmp r3, #2 */
/* @0x20ad5c bne 0x20ad84 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0xb8> */
/* @0x20ad60 sub r3, r2, #1 */
/* @0x20ad64 bic r3, r3, #-16777216 */
/* @0x20ad68 bic r3, r3, #3 */
/* @0x20ad6c cmp r3, #0 */
/* @0x20ad70 beq 0x20af6c <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x2a0> */
/* @0x20ad74 mov r2, #0 */
/* @0x20ad78 mov r3, #5 */
/* @0x20ad7c str r2, [r9, #0x8] */
/* @0x20ad80 str r3, [r9, #0xc] */
/* @0x20ad84 ldr r3, [r4, #0xc] */
/* @0x20ad88 mov r1, #0 */
/* @0x20ad8c ldr r2, [r4, #0x8] */
/* @0x20ad90 str r1, [r9] */
/* @0x20ad94 str r3, [r9, #0xc] */
/* @0x20ad98 ldr r3, [r4, #0xc] */
/* @0x20ad9c str r2, [r9, #0x8] */
/* @0x20ada0 bic r3, r3, #-16777216 */
/* @0x20ada4 cmp r3, #14 */
/* @0x20ada8 addls pc, pc, r3, lsl #2 */
/* @0x20adac b 0x20ae28 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x15c> */
/* @0x20adb0 b 0x20aef8 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x22c> */
/* @0x20adb4 b 0x20af30 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x264> */
/* @0x20adb8 b 0x20af04 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x238> */
/* @0x20adbc b 0x20ae20 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x154> */
/* @0x20adc0 b 0x20ae28 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x15c> */
/* @0x20adc4 b 0x20ae28 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x15c> */
/* @0x20adc8 b 0x20af48 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x27c> */
/* @0x20adcc b 0x20ae20 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x154> */
/* @0x20add0 b 0x20ae28 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x15c> */
/* @0x20add4 b 0x20ae28 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x15c> */
/* @0x20add8 b 0x20aef8 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x22c> */
/* @0x20addc b 0x20ae28 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x15c> */
/* @0x20ade0 b 0x20ae28 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x15c> */
/* @0x20ade4 b 0x20aef8 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x22c> */
/* @0x20ade8 b 0x20ae20 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x154> */
/* @0x20adec ldr r7, [r9] */
/* @0x20adf0 cmp r7, #0 */
/* @0x20adf4 beq 0x20ae14 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x148> */
/* @0x20adf8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20adfc ldr r8, [r7, #0x4] */
/* @0x20ae00 sub r8, r8, #1 */
/* @0x20ae04 str r8, [r7, #0x4] */
/* @0x20ae08 cmp r8, #0 */
/* @0x20ae0c beq 0x20af90 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x2c4> */
/* @0x20ae10 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20ae14 mov r3, #0 */
/* @0x20ae18 str r3, [r9] */
/* @0x20ae1c b 0x20ad84 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0xb8> */
/* @0x20ae20 ldr r3, [r4] */
/* @0x20ae24 str r3, [r9] */
/* @0x20ae28 ldr r7, [r6, #0xc] */
/* @0x20ae2c add r7, r7, r5 */
/* @0x20ae30 ldr r3, [r7, #0xc] */
/* @0x20ae34 sub r3, r3, #1 */
/* @0x20ae38 bic r3, r3, #-16777216 */
/* @0x20ae3c bic r3, r3, #3 */
/* @0x20ae40 cmp r3, #0 */
/* @0x20ae44 beq 0x20af84 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x2b8> */
/* @0x20ae48 mov r3, #0 */
/* @0x20ae4c str r3, [r7] */
/* @0x20ae50 ldr r4, [r6, #0x14] */
/* @0x20ae54 mov r2, #5 */
/* @0x20ae58 str r3, [r7, #0x8] */
/* @0x20ae5c add r4, r4, r5 */
/* @0x20ae60 str r2, [r7, #0xc] */
/* @0x20ae64 ldr r3, [r4, #0xc] */
/* @0x20ae68 sub r3, r3, #1 */
/* @0x20ae6c bic r3, r3, #-16777216 */
/* @0x20ae70 bic r3, r3, #3 */
/* @0x20ae74 cmp r3, #0 */
/* @0x20ae78 beq 0x20af78 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x2ac> */
/* @0x20ae7c mov r7, #0 */
/* @0x20ae80 str r7, [r4] */
/* @0x20ae84 ldr r1, [r6, #0x4] */
/* @0x20ae88 mov r12, #5 */
/* @0x20ae8c ldr r3, [r6, #0xc] */
/* @0x20ae90 mov r2, #16 */
/* @0x20ae94 sub r1, r1, #-268435455 */
/* @0x20ae98 str r12, [r4, #0xc] */
/* @0x20ae9c add r0, r3, r5 */
/* @0x20aea0 str r7, [r4, #0x8] */
/* @0x20aea4 add r1, r3, r1, lsl #4 */
/* @0x20aea8 bl 0xb6694 <memmove@plt> */
/* @0x20aeac ldr r3, [r6, #0x4] */
/* @0x20aeb0 ldr r12, [r6, #0xc] */
/* @0x20aeb4 mov r2, #16 */
/* @0x20aeb8 sub r3, r3, #-268435455 */
/* @0x20aebc ldr r1, [r6, #0x14] */
/* @0x20aec0 lsl r3, r3, #4 */
/* @0x20aec4 add r0, r1, r5 */
/* @0x20aec8 add r12, r12, r3 */
/* @0x20aecc add r1, r1, r3 */
/* @0x20aed0 str r7, [r12, #0xc] */
/* @0x20aed4 bl 0xb6694 <memmove@plt> */
/* @0x20aed8 ldr r3, [r6, #0x4] */
/* @0x20aedc ldr r2, [r6, #0x14] */
/* @0x20aee0 sub r1, r3, #-268435455 */
/* @0x20aee4 sub r3, r3, #1 */
/* @0x20aee8 add r2, r2, r1, lsl #4 */
/* @0x20aeec str r7, [r2, #0xc] */
/* @0x20aef0 str r3, [r6, #0x4] */
/* @0x20aef4 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x20aef8 ldm r4, {r2, r3} */
/* @0x20aefc stm r9, {r2, r3} */
/* @0x20af00 b 0x20ae28 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x15c> */
/* @0x20af04 ldr r3, [r4] */
/* @0x20af08 cmp r3, #0 */
/* @0x20af0c str r3, [r9] */
/* @0x20af10 beq 0x20ae28 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x15c> */
/* @0x20af14 ldr r1, [r3, #0x8] */
/* @0x20af18 ldr r2, [r3] */
/* @0x20af1c cmp r1, #0 */
/* @0x20af20 streq r9, [r3, #0x8] */
/* @0x20af24 add r2, r2, #1 */
/* @0x20af28 str r2, [r3] */
/* @0x20af2c b 0x20ae28 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x15c> */
/* @0x20af30 ldr r3, [r4] */
/* @0x20af34 cmp r3, #0 */
/* @0x20af38 ldrne r2, [r3, #0x4] */
/* @0x20af3c addne r2, r2, #1 */
/* @0x20af40 strne r2, [r3, #0x4] */
/* @0x20af44 b 0x20ae24 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x158> */
/* @0x20af48 ldr r3, [r4] */
/* @0x20af4c str r3, [r9] */
/* @0x20af50 ldr r3, [r4] */
/* @0x20af54 cmp r3, #0 */
/* @0x20af58 beq 0x20ae28 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x15c> */
/* @0x20af5c bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x20af60 ldr r1, [r4] */
/* @0x20af64 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x20af68 b 0x20ae28 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x15c> */
/* @0x20af6c mov r0, r9 */
/* @0x20af70 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20af74 b 0x20ad74 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0xa8> */
/* @0x20af78 mov r0, r4 */
/* @0x20af7c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20af80 b 0x20ae7c <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x1b0> */
/* @0x20af84 mov r0, r7 */
/* @0x20af88 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20af8c b 0x20ae48 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x17c> */
/* @0x20af90 ldr r0, [r7] */
/* @0x20af94 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20af98 str r8, [r7] */
/* @0x20af9c str r8, [r7, #0x8] */
/* @0x20afa0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20afa4 ldr r8, [r7, #0x4] */
/* @0x20afa8 sub r8, r8, #1 */
/* @0x20afac str r8, [r7, #0x4] */
/* @0x20afb0 cmp r8, #0 */
/* @0x20afb4 beq 0x20afd4 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x308> */
/* @0x20afb8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20afbc mov r0, r7 */
/* @0x20afc0 bl 0x27d1d0 <_ZdlPv> */
/* @0x20afc4 b 0x20ae10 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x144> */
/* @0x20afc8 mov r5, r7 */
/* @0x20afcc ldr r4, [r0, #0xc] */
/* @0x20afd0 b 0x20ad84 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0xb8> */
/* @0x20afd4 ldr r0, [r7] */
/* @0x20afd8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20afdc mov r0, r7 */
/* @0x20afe0 str r8, [r7] */
/* @0x20afe4 str r8, [r7, #0x8] */
/* @0x20afe8 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x20afec mov r0, r7 */
/* @0x20aff0 bl 0x27d1d0 <_ZdlPv> */
/* @0x20aff4 b 0x20afb8 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x2ec> */
/* @0x20aff8 andseq r6, lr, r0, lsl #13 */

/* ── FUNC 0x20affc · CDS_Grid::SetSize(int, int) · size=272 · insn=68 */
/* @0x20affc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x20b000 mov r9, r0 */
/* @0x20b004 ldr r0, [r0] */
/* @0x20b008 sub sp, sp, #12 */
/* @0x20b00c ldmib r9, {r3, r10} */
/* @0x20b010 mov r8, r1 */
/* @0x20b014 cmp r0, #0 */
/* @0x20b018 mov r7, r2 */
/* @0x20b01c mul r10, r10, r3 */
/* @0x20b020 beq 0x20b080 <_ZN8CDS_Grid7SetSizeEii+0x84> */
/* @0x20b024 cmp r10, #0 */
/* @0x20b028 ble 0x20b080 <_ZN8CDS_Grid7SetSizeEii+0x84> */
/* @0x20b02c mov r5, #0 */
/* @0x20b030 mov r11, #5 */
/* @0x20b034 mov r6, r5 */
/* @0x20b038 b 0x20b050 <_ZN8CDS_Grid7SetSizeEii+0x54> */
/* @0x20b03c cmp r5, r10 */
/* @0x20b040 str r6, [r4, #0x8] */
/* @0x20b044 str r11, [r4, #0xc] */
/* @0x20b048 str r6, [r4] */
/* @0x20b04c beq 0x20b080 <_ZN8CDS_Grid7SetSizeEii+0x84> */
/* @0x20b050 add r4, r0, r5, lsl #4 */
/* @0x20b054 add r5, r5, #1 */
/* @0x20b058 ldr r3, [r4, #0xc] */
/* @0x20b05c sub r3, r3, #1 */
/* @0x20b060 bic r3, r3, #-16777216 */
/* @0x20b064 bic r3, r3, #3 */
/* @0x20b068 cmp r3, #0 */
/* @0x20b06c bne 0x20b03c <_ZN8CDS_Grid7SetSizeEii+0x40> */
/* @0x20b070 mov r0, r4 */
/* @0x20b074 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20b078 ldr r0, [r9] */
/* @0x20b07c b 0x20b03c <_ZN8CDS_Grid7SetSizeEii+0x40> */
/* @0x20b080 cmp r7, #0 */
/* @0x20b084 cmpne r8, #0 */
/* @0x20b088 movne r4, #0 */
/* @0x20b08c moveq r4, #1 */
/* @0x20b090 beq 0x20b0ec <_ZN8CDS_Grid7SetSizeEii+0xf0> */
/* @0x20b094 mul r5, r7, r8 */
/* @0x20b098 ldr r2, [pc, #0x68] */
/* @0x20b09c str r4, [sp] */
/* @0x20b0a0 mov r3, #74 */
/* @0x20b0a4 add r2, pc, r2 */
/* @0x20b0a8 lsl r6, r5, #4 */
/* @0x20b0ac mov r1, r6 */
/* @0x20b0b0 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x20b0b4 cmp r5, #0 */
/* @0x20b0b8 str r7, [r9, #0x8] */
/* @0x20b0bc stm r9, {r0, r8} */
/* @0x20b0c0 ble 0x20b0e4 <_ZN8CDS_Grid7SetSizeEii+0xe8> */
/* @0x20b0c4 add r1, r0, r6 */
/* @0x20b0c8 mov r3, r4 */
/* @0x20b0cc str r3, [r0, #0xc] */
/* @0x20b0d0 add r0, r0, #16 */
/* @0x20b0d4 str r3, [r0, #-0x10] */
/* @0x20b0d8 str r3, [r0, #-0xc] */
/* @0x20b0dc cmp r0, r1 */
/* @0x20b0e0 bne 0x20b0cc <_ZN8CDS_Grid7SetSizeEii+0xd0> */
/* @0x20b0e4 add sp, sp, #12 */
/* @0x20b0e8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x20b0ec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x20b0f0 mov r3, #0 */
/* @0x20b0f4 str r8, [r9, #0x4] */
/* @0x20b0f8 str r7, [r9, #0x8] */
/* @0x20b0fc str r3, [r9] */
/* @0x20b100 add sp, sp, #12 */
/* @0x20b104 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x20b108 andseq r5, r2, r12, lsl #31 */

/* ── FUNC 0x20b10c · CDS_Grid::CDS_Grid(int, int) · size=44 · insn=11 */
/* @0x20b10c push {r4, r5, r6, lr} */
/* @0x20b110 mov r3, #0 */
/* @0x20b114 mov r4, r0 */
/* @0x20b118 str r3, [r0] */
/* @0x20b11c mov r6, r1 */
/* @0x20b120 mov r5, r2 */
/* @0x20b124 bl 0x20affc <_ZN8CDS_Grid7SetSizeEii> */
/* @0x20b128 str r6, [r4, #0x4] */
/* @0x20b12c mov r0, r4 */
/* @0x20b130 str r5, [r4, #0x8] */
/* @0x20b134 pop {r4, r5, r6, pc} */

/* ── FUNC 0x20b10c · CDS_Grid::CDS_Grid(int, int) · alias of the symbol above · insn=0 */

/* ── FUNC 0x20b138 · CDS_Grid::ReadFromString(char const*, bool) · size=296 · insn=74 */
/* @0x20b138 push {r4, r5, r6, r7, r8, lr} */
/* @0x20b13c mov r5, r0 */
/* @0x20b140 mov r0, #32 */
/* @0x20b144 mov r4, r1 */
/* @0x20b148 mov r7, r2 */
/* @0x20b14c bl 0x27c524 <_Znwj> */
/* @0x20b150 mov r1, #0 */
/* @0x20b154 mov r6, r0 */
/* @0x20b158 bl 0x2010ec <_ZN7CStreamC2Ei> */
/* @0x20b15c mov r1, r4 */
/* @0x20b160 mov r0, r6 */
/* @0x20b164 bl 0x2025b0 <_ZN7CStream17ConvertFromStringEPKc> */
/* @0x20b168 mov r0, r6 */
/* @0x20b16c bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x20b170 sub r3, r0, #600 */
/* @0x20b174 mov r4, r0 */
/* @0x20b178 sub r3, r3, #1 */
/* @0x20b17c mov r0, r6 */
/* @0x20b180 cmp r3, #1 */
/* @0x20b184 bls 0x20b1a8 <_ZN8CDS_Grid14ReadFromStringEPKcb+0x70> */
/* @0x20b188 cmp r6, #0 */
/* @0x20b18c beq 0x20b1a4 <_ZN8CDS_Grid14ReadFromStringEPKcb+0x6c> */
/* @0x20b190 bl 0x201328 <_ZN7CStreamD2Ev> */
/* @0x20b194 mov r0, r6 */
/* @0x20b198 bl 0x27d1d0 <_ZdlPv> */
/* @0x20b19c mov r0, #0 */
/* @0x20b1a0 pop {r4, r5, r6, r7, r8, pc} */
/* @0x20b1a4 pop {r4, r5, r6, r7, r8, pc} */
/* @0x20b1a8 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x20b1ac mov r8, r0 */
/* @0x20b1b0 mov r0, r6 */
/* @0x20b1b4 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x20b1b8 mov r1, r8 */
/* @0x20b1bc mov r2, r0 */
/* @0x20b1c0 mov r0, r5 */
/* @0x20b1c4 bl 0x20affc <_ZN8CDS_Grid7SetSizeEii> */
/* @0x20b1c8 cmp r7, #0 */
/* @0x20b1cc movne r8, #1 */
/* @0x20b1d0 bne 0x20b1e4 <_ZN8CDS_Grid14ReadFromStringEPKcb+0xac> */
/* @0x20b1d4 movw r8, #0x259 */
/* @0x20b1d8 cmp r4, r8 */
/* @0x20b1dc moveq r8, #2 */
/* @0x20b1e0 movne r8, #0 */
/* @0x20b1e4 ldr r3, [r5, #0x4] */
/* @0x20b1e8 cmp r3, #0 */
/* @0x20b1ec ble 0x20b238 <_ZN8CDS_Grid14ReadFromStringEPKcb+0x100> */
/* @0x20b1f0 ldr r12, [r5, #0x8] */
/* @0x20b1f4 mov r7, #0 */
/* @0x20b1f8 cmp r12, #0 */
/* @0x20b1fc ble 0x20b22c <_ZN8CDS_Grid14ReadFromStringEPKcb+0xf4> */
/* @0x20b200 mov r4, #0 */
/* @0x20b204 mla r3, r3, r4, r7 */
/* @0x20b208 ldr r0, [r5] */
/* @0x20b20c mov r1, r6 */
/* @0x20b210 mov r2, r8 */
/* @0x20b214 add r4, r4, #1 */
/* @0x20b218 add r0, r0, r3, lsl #4 */
/* @0x20b21c bl 0x208638 <_Z9ReadValueR6RValueR7CStreami> */
/* @0x20b220 ldmib r5, {r3, r12} */
/* @0x20b224 cmp r12, r4 */
/* @0x20b228 bgt 0x20b204 <_ZN8CDS_Grid14ReadFromStringEPKcb+0xcc> */
/* @0x20b22c add r7, r7, #1 */
/* @0x20b230 cmp r7, r3 */
/* @0x20b234 blt 0x20b1f8 <_ZN8CDS_Grid14ReadFromStringEPKcb+0xc0> */
/* @0x20b238 cmp r6, #0 */
/* @0x20b23c beq 0x20b258 <_ZN8CDS_Grid14ReadFromStringEPKcb+0x120> */
/* @0x20b240 mov r0, r6 */
/* @0x20b244 bl 0x201328 <_ZN7CStreamD2Ev> */
/* @0x20b248 mov r0, r6 */
/* @0x20b24c bl 0x27d1d0 <_ZdlPv> */
/* @0x20b250 mov r0, #1 */
/* @0x20b254 pop {r4, r5, r6, r7, r8, pc} */
/* @0x20b258 mov r0, #1 */
/* @0x20b25c pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x20b260 · CDS_Grid::~CDS_Grid() · size=28 · insn=7 */
/* @0x20b260 mov r1, #0 */
/* @0x20b264 push {r4, lr} */
/* @0x20b268 mov r2, r1 */
/* @0x20b26c mov r4, r0 */
/* @0x20b270 bl 0x20affc <_ZN8CDS_Grid7SetSizeEii> */
/* @0x20b274 mov r0, r4 */
/* @0x20b278 pop {r4, pc} */

/* ── FUNC 0x20b260 · CDS_Grid::~CDS_Grid() · alias of the symbol above · insn=0 */

/* ── FUNC 0x20b27c · FreeAllDataStructures() · size=508 · insn=127 */
/* @0x20b27c push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x20b280 sub sp, sp, #28 */
/* @0x20b284 add r6, sp, #4 */
/* @0x20b288 ldr r5, [pc, #0x1d4] */
/* @0x20b28c mov r0, r6 */
/* @0x20b290 add r5, pc, r5 */
/* @0x20b294 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0x20b298 ldr r3, [pc, #0x1c8] */
/* @0x20b29c ldr r7, [r5, r3] */
/* @0x20b2a0 ldr r3, [r7] */
/* @0x20b2a4 cmp r3, #0 */
/* @0x20b2a8 movgt r4, #0 */
/* @0x20b2ac ble 0x20b2c8 <_Z21FreeAllDataStructuresv+0x4c> */
/* @0x20b2b0 mov r0, r4 */
/* @0x20b2b4 add r4, r4, #1 */
/* @0x20b2b8 bl 0x205334 <_Z12DestroyDsMapi> */
/* @0x20b2bc ldr r3, [r7] */
/* @0x20b2c0 cmp r3, r4 */
/* @0x20b2c4 bgt 0x20b2b0 <_Z21FreeAllDataStructuresv+0x34> */
/* @0x20b2c8 ldr r3, [pc, #0x19c] */
/* @0x20b2cc ldr r7, [r5, r3] */
/* @0x20b2d0 ldr r3, [r7] */
/* @0x20b2d4 cmp r3, #0 */
/* @0x20b2d8 movgt r4, #0 */
/* @0x20b2dc ble 0x20b2f8 <_Z21FreeAllDataStructuresv+0x7c> */
/* @0x20b2e0 mov r0, r4 */
/* @0x20b2e4 add r4, r4, #1 */
/* @0x20b2e8 bl 0x205378 <_Z13DestroyDsListi> */
/* @0x20b2ec ldr r3, [r7] */
/* @0x20b2f0 cmp r3, r4 */
/* @0x20b2f4 bgt 0x20b2e0 <_Z21FreeAllDataStructuresv+0x64> */
/* @0x20b2f8 add r0, sp, #8 */
/* @0x20b2fc bl 0xffc9c <_Z12GetTheStacksRi> */
/* @0x20b300 ldr r2, [sp, #0x8] */
/* @0x20b304 cmp r2, #0 */
/* @0x20b308 movgt r4, #0 */
/* @0x20b30c movgt r8, r4 */
/* @0x20b310 movgt r7, r0 */
/* @0x20b314 ble 0x20b348 <_Z21FreeAllDataStructuresv+0xcc> */
/* @0x20b318 ldr r3, [r7], #4 */
/* @0x20b31c add r4, r4, #1 */
/* @0x20b320 cmp r3, #0 */
/* @0x20b324 mov r0, r3 */
/* @0x20b328 beq 0x20b340 <_Z21FreeAllDataStructuresv+0xc4> */
/* @0x20b32c ldr r3, [r3] */
/* @0x20b330 ldr r3, [r3, #0x4] */
/* @0x20b334 blx r3 */
/* @0x20b338 ldr r2, [sp, #0x8] */
/* @0x20b33c str r8, [r7, #-0x4] */
/* @0x20b340 cmp r2, r4 */
/* @0x20b344 bgt 0x20b318 <_Z21FreeAllDataStructuresv+0x9c> */
/* @0x20b348 add r0, sp, #12 */
/* @0x20b34c bl 0xffee8 <_Z12GetTheQueuesRi> */
/* @0x20b350 ldr r2, [sp, #0xc] */
/* @0x20b354 cmp r2, #0 */
/* @0x20b358 movgt r4, #0 */
/* @0x20b35c movgt r8, r4 */
/* @0x20b360 movgt r7, r0 */
/* @0x20b364 ble 0x20b398 <_Z21FreeAllDataStructuresv+0x11c> */
/* @0x20b368 ldr r3, [r7], #4 */
/* @0x20b36c add r4, r4, #1 */
/* @0x20b370 cmp r3, #0 */
/* @0x20b374 mov r0, r3 */
/* @0x20b378 beq 0x20b390 <_Z21FreeAllDataStructuresv+0x114> */
/* @0x20b37c ldr r3, [r3] */
/* @0x20b380 ldr r3, [r3, #0x4] */
/* @0x20b384 blx r3 */
/* @0x20b388 ldr r2, [sp, #0xc] */
/* @0x20b38c str r8, [r7, #-0x4] */
/* @0x20b390 cmp r2, r4 */
/* @0x20b394 bgt 0x20b368 <_Z21FreeAllDataStructuresv+0xec> */
/* @0x20b398 add r0, sp, #16 */
/* @0x20b39c bl 0x10026c <_Z11GetTheGridsRi> */
/* @0x20b3a0 ldr r3, [sp, #0x10] */
/* @0x20b3a4 cmp r3, #0 */
/* @0x20b3a8 movgt r7, #0 */
/* @0x20b3ac movgt r9, r7 */
/* @0x20b3b0 movgt r8, r0 */
/* @0x20b3b4 ble 0x20b3e8 <_Z21FreeAllDataStructuresv+0x16c> */
/* @0x20b3b8 ldr r4, [r8], #4 */
/* @0x20b3bc add r7, r7, #1 */
/* @0x20b3c0 cmp r4, #0 */
/* @0x20b3c4 mov r0, r4 */
/* @0x20b3c8 beq 0x20b3e0 <_Z21FreeAllDataStructuresv+0x164> */
/* @0x20b3cc bl 0x20b260 <_ZN8CDS_GridD2Ev> */
/* @0x20b3d0 mov r0, r4 */
/* @0x20b3d4 bl 0x27d1d0 <_ZdlPv> */
/* @0x20b3d8 ldr r3, [sp, #0x10] */
/* @0x20b3dc str r9, [r8, #-0x4] */
/* @0x20b3e0 cmp r3, r7 */
/* @0x20b3e4 bgt 0x20b3b8 <_Z21FreeAllDataStructuresv+0x13c> */
/* @0x20b3e8 add r0, sp, #20 */
/* @0x20b3ec bl 0x100244 <_Z20GetThePriorityQueuesRi> */
/* @0x20b3f0 ldr r2, [sp, #0x14] */
/* @0x20b3f4 cmp r2, #0 */
/* @0x20b3f8 movgt r4, #0 */
/* @0x20b3fc movgt r8, r4 */
/* @0x20b400 movgt r7, r0 */
/* @0x20b404 ble 0x20b438 <_Z21FreeAllDataStructuresv+0x1bc> */
/* @0x20b408 ldr r3, [r7], #4 */
/* @0x20b40c add r4, r4, #1 */
/* @0x20b410 cmp r3, #0 */
/* @0x20b414 mov r0, r3 */
/* @0x20b418 beq 0x20b430 <_Z21FreeAllDataStructuresv+0x1b4> */
/* @0x20b41c ldr r3, [r3] */
/* @0x20b420 ldr r3, [r3, #0x4] */
/* @0x20b424 blx r3 */
/* @0x20b428 ldr r2, [sp, #0x14] */
/* @0x20b42c str r8, [r7, #-0x4] */
/* @0x20b430 cmp r2, r4 */
/* @0x20b434 bgt 0x20b408 <_Z21FreeAllDataStructuresv+0x18c> */
/* @0x20b438 ldr r1, [pc, #0x30] */
/* @0x20b43c mvn r3, #0 */
/* @0x20b440 ldr r2, [pc, #0x2c] */
/* @0x20b444 mov r0, r6 */
/* @0x20b448 ldr r1, [r5, r1] */
/* @0x20b44c str r3, [r1] */
/* @0x20b450 ldr r2, [r5, r2] */
/* @0x20b454 str r3, [r2] */
/* @0x20b458 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x20b45c add sp, sp, #28 */
/* @0x20b460 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x20b464 andseq r6, lr, r0, asr #19 */
/* @0x20b468 .word 0xffffc028 */
/* @0x20b46c .word 0xffffc02c */
/* @0x20b470 .word 0xfffff750 */
/* @0x20b474 .word 0xffffdec8 */

/* ── FUNC 0x20b478 · CDS_Grid::Assign(CDS_Grid*) · size=596 · insn=149 */
/* @0x20b478 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x20b47c mov r4, r0 */
/* @0x20b480 mov r5, r1 */
/* @0x20b484 sub sp, sp, #12 */
/* @0x20b488 ldmib r1, {r1, r2} */
/* @0x20b48c bl 0x20affc <_ZN8CDS_Grid7SetSizeEii> */
/* @0x20b490 ldmib r4, {r3, r6} */
/* @0x20b494 ldr r5, [r5] */
/* @0x20b498 ldr r4, [r4] */
/* @0x20b49c mul r6, r6, r3 */
/* @0x20b4a0 cmp r6, #0 */
/* @0x20b4a4 ble 0x20b56c <_ZN8CDS_Grid6AssignEPS_+0xf4> */
/* @0x20b4a8 add r4, r4, #16 */
/* @0x20b4ac add r5, r5, #16 */
/* @0x20b4b0 mov r9, #0 */
/* @0x20b4b4 mov r10, #5 */
/* @0x20b4b8 ldr r2, [r4, #-0x4] */
/* @0x20b4bc sub r8, r5, #16 */
/* @0x20b4c0 sub r7, r4, #16 */
/* @0x20b4c4 bic r3, r2, #-16777216 */
/* @0x20b4c8 cmp r3, #1 */
/* @0x20b4cc beq 0x20b5e8 <_ZN8CDS_Grid6AssignEPS_+0x170> */
/* @0x20b4d0 cmp r3, #2 */
/* @0x20b4d4 bne 0x20b4f0 <_ZN8CDS_Grid6AssignEPS_+0x78> */
/* @0x20b4d8 sub r2, r2, #1 */
/* @0x20b4dc bic r2, r2, #-16777216 */
/* @0x20b4e0 bic r2, r2, #3 */
/* @0x20b4e4 cmp r2, #0 */
/* @0x20b4e8 beq 0x20b654 <_ZN8CDS_Grid6AssignEPS_+0x1dc> */
/* @0x20b4ec stmdb r4, {r9, r10} */
/* @0x20b4f0 str r9, [r4, #-0x10] */
/* @0x20b4f4 ldr r3, [r5, #-0x4] */
/* @0x20b4f8 str r3, [r4, #-0x4] */
/* @0x20b4fc ldr r3, [r5, #-0x8] */
/* @0x20b500 str r3, [r4, #-0x8] */
/* @0x20b504 ldr r3, [r5, #-0x4] */
/* @0x20b508 bic r3, r3, #-16777216 */
/* @0x20b50c cmp r3, #14 */
/* @0x20b510 addls pc, pc, r3, lsl #2 */
/* @0x20b514 b 0x20b55c <_ZN8CDS_Grid6AssignEPS_+0xe4> */
/* @0x20b518 b 0x20b574 <_ZN8CDS_Grid6AssignEPS_+0xfc> */
/* @0x20b51c b 0x20b5d0 <_ZN8CDS_Grid6AssignEPS_+0x158> */
/* @0x20b520 b 0x20b5a4 <_ZN8CDS_Grid6AssignEPS_+0x12c> */
/* @0x20b524 b 0x20b554 <_ZN8CDS_Grid6AssignEPS_+0xdc> */
/* @0x20b528 b 0x20b55c <_ZN8CDS_Grid6AssignEPS_+0xe4> */
/* @0x20b52c b 0x20b55c <_ZN8CDS_Grid6AssignEPS_+0xe4> */
/* @0x20b530 b 0x20b580 <_ZN8CDS_Grid6AssignEPS_+0x108> */
/* @0x20b534 b 0x20b554 <_ZN8CDS_Grid6AssignEPS_+0xdc> */
/* @0x20b538 b 0x20b55c <_ZN8CDS_Grid6AssignEPS_+0xe4> */
/* @0x20b53c b 0x20b55c <_ZN8CDS_Grid6AssignEPS_+0xe4> */
/* @0x20b540 b 0x20b574 <_ZN8CDS_Grid6AssignEPS_+0xfc> */
/* @0x20b544 b 0x20b55c <_ZN8CDS_Grid6AssignEPS_+0xe4> */
/* @0x20b548 b 0x20b55c <_ZN8CDS_Grid6AssignEPS_+0xe4> */
/* @0x20b54c b 0x20b574 <_ZN8CDS_Grid6AssignEPS_+0xfc> */
/* @0x20b550 b 0x20b554 <_ZN8CDS_Grid6AssignEPS_+0xdc> */
/* @0x20b554 ldr r3, [r5, #-0x10] */
/* @0x20b558 str r3, [r4, #-0x10] */
/* @0x20b55c subs r6, r6, #1 */
/* @0x20b560 add r4, r4, #16 */
/* @0x20b564 add r5, r5, #16 */
/* @0x20b568 bne 0x20b4b8 <_ZN8CDS_Grid6AssignEPS_+0x40> */
/* @0x20b56c add sp, sp, #12 */
/* @0x20b570 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x20b574 ldm r8, {r2, r3} */
/* @0x20b578 stm r7, {r2, r3} */
/* @0x20b57c b 0x20b55c <_ZN8CDS_Grid6AssignEPS_+0xe4> */
/* @0x20b580 ldr r3, [r5, #-0x10] */
/* @0x20b584 str r3, [r4, #-0x10] */
/* @0x20b588 ldr r3, [r5, #-0x10] */
/* @0x20b58c cmp r3, #0 */
/* @0x20b590 beq 0x20b55c <_ZN8CDS_Grid6AssignEPS_+0xe4> */
/* @0x20b594 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x20b598 ldr r1, [r5, #-0x10] */
/* @0x20b59c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x20b5a0 b 0x20b55c <_ZN8CDS_Grid6AssignEPS_+0xe4> */
/* @0x20b5a4 ldr r3, [r5, #-0x10] */
/* @0x20b5a8 cmp r3, #0 */
/* @0x20b5ac str r3, [r4, #-0x10] */
/* @0x20b5b0 beq 0x20b55c <_ZN8CDS_Grid6AssignEPS_+0xe4> */
/* @0x20b5b4 ldr r1, [r3, #0x8] */
/* @0x20b5b8 ldr r2, [r3] */
/* @0x20b5bc cmp r1, #0 */
/* @0x20b5c0 streq r7, [r3, #0x8] */
/* @0x20b5c4 add r2, r2, #1 */
/* @0x20b5c8 str r2, [r3] */
/* @0x20b5cc b 0x20b55c <_ZN8CDS_Grid6AssignEPS_+0xe4> */
/* @0x20b5d0 ldr r3, [r5, #-0x10] */
/* @0x20b5d4 cmp r3, #0 */
/* @0x20b5d8 ldrne r2, [r3, #0x4] */
/* @0x20b5dc addne r2, r2, #1 */
/* @0x20b5e0 strne r2, [r3, #0x4] */
/* @0x20b5e4 b 0x20b558 <_ZN8CDS_Grid6AssignEPS_+0xe0> */
/* @0x20b5e8 ldr r11, [r4, #-0x10] */
/* @0x20b5ec cmp r11, #0 */
/* @0x20b5f0 beq 0x20b4f0 <_ZN8CDS_Grid6AssignEPS_+0x78> */
/* @0x20b5f4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20b5f8 ldr r3, [r11, #0x4] */
/* @0x20b5fc sub r3, r3, #1 */
/* @0x20b600 str r3, [r11, #0x4] */
/* @0x20b604 cmp r3, #0 */
/* @0x20b608 beq 0x20b614 <_ZN8CDS_Grid6AssignEPS_+0x19c> */
/* @0x20b60c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20b610 b 0x20b4f0 <_ZN8CDS_Grid6AssignEPS_+0x78> */
/* @0x20b614 ldr r0, [r11] */
/* @0x20b618 str r3, [sp, #0x4] */
/* @0x20b61c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20b620 ldr r3, [sp, #0x4] */
/* @0x20b624 str r3, [r11] */
/* @0x20b628 str r3, [r11, #0x8] */
/* @0x20b62c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20b630 ldr r3, [r11, #0x4] */
/* @0x20b634 sub r3, r3, #1 */
/* @0x20b638 str r3, [r11, #0x4] */
/* @0x20b63c cmp r3, #0 */
/* @0x20b640 beq 0x20b660 <_ZN8CDS_Grid6AssignEPS_+0x1e8> */
/* @0x20b644 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20b648 mov r0, r11 */
/* @0x20b64c bl 0x27d1d0 <_ZdlPv> */
/* @0x20b650 b 0x20b60c <_ZN8CDS_Grid6AssignEPS_+0x194> */
/* @0x20b654 mov r0, r7 */
/* @0x20b658 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20b65c b 0x20b4ec <_ZN8CDS_Grid6AssignEPS_+0x74> */
/* @0x20b660 ldr r0, [r11] */
/* @0x20b664 str r3, [sp, #0x4] */
/* @0x20b668 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20b66c ldr r3, [sp, #0x4] */
/* @0x20b670 str r3, [r11] */
/* @0x20b674 str r3, [r11, #0x8] */
/* @0x20b678 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20b67c ldr r3, [r11, #0x4] */
/* @0x20b680 sub r3, r3, #1 */
/* @0x20b684 str r3, [r11, #0x4] */
/* @0x20b688 cmp r3, #0 */
/* @0x20b68c beq 0x20b6a0 <_ZN8CDS_Grid6AssignEPS_+0x228> */
/* @0x20b690 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20b694 mov r0, r11 */
/* @0x20b698 bl 0x27d1d0 <_ZdlPv> */
/* @0x20b69c b 0x20b644 <_ZN8CDS_Grid6AssignEPS_+0x1cc> */
/* @0x20b6a0 ldr r0, [r11] */
/* @0x20b6a4 str r3, [sp, #0x4] */
/* @0x20b6a8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20b6ac ldr r3, [sp, #0x4] */
/* @0x20b6b0 mov r0, r11 */
/* @0x20b6b4 str r3, [r11] */
/* @0x20b6b8 str r3, [r11, #0x8] */
/* @0x20b6bc bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x20b6c0 mov r0, r11 */
/* @0x20b6c4 bl 0x27d1d0 <_ZdlPv> */
/* @0x20b6c8 b 0x20b690 <_ZN8CDS_Grid6AssignEPS_+0x218> */

/* ── FUNC 0x20b6cc · CDS_Map::Delete(RValue*) · size=440 · insn=110 */
/* @0x20b6cc ldr r3, [r1, #0xc] */
/* @0x20b6d0 push {r4, r5, r6, lr} */
/* @0x20b6d4 bic r3, r3, #-16777216 */
/* @0x20b6d8 cmp r3, #6 */
/* @0x20b6dc sub sp, sp, #8 */
/* @0x20b6e0 ldr r5, [r0] */
/* @0x20b6e4 beq 0x20b85c <_ZN7CDS_Map6DeleteEP6RValue+0x190> */
/* @0x20b6e8 bgt 0x20b804 <_ZN7CDS_Map6DeleteEP6RValue+0x138> */
/* @0x20b6ec cmp r3, #4 */
/* @0x20b6f0 bgt 0x20b81c <_ZN7CDS_Map6DeleteEP6RValue+0x150> */
/* @0x20b6f4 cmp r3, #2 */
/* @0x20b6f8 bge 0x20b85c <_ZN7CDS_Map6DeleteEP6RValue+0x190> */
/* @0x20b6fc cmp r3, #1 */
/* @0x20b700 bne 0x20b830 <_ZN7CDS_Map6DeleteEP6RValue+0x164> */
/* @0x20b704 ldr r0, [r1] */
/* @0x20b708 cmp r0, #0 */
/* @0x20b70c ldrne r0, [r0] */
/* @0x20b710 bl 0x27dfa8 <_Z14CalcCRC_stringPKc> */
/* @0x20b714 ldr r1, [r5, #0x4] */
/* @0x20b718 ldr r2, [r5] */
/* @0x20b71c and r1, r0, r1 */
/* @0x20b720 ldr r4, [r2, r1, lsl #3] */
/* @0x20b724 add r12, r2, r1, lsl #3 */
/* @0x20b728 cmp r4, #0 */
/* @0x20b72c bne 0x20b740 <_ZN7CDS_Map6DeleteEP6RValue+0x74> */
/* @0x20b730 b 0x20b7fc <_ZN7CDS_Map6DeleteEP6RValue+0x130> */
/* @0x20b734 ldr r4, [r4, #0x4] */
/* @0x20b738 cmp r4, #0 */
/* @0x20b73c beq 0x20b7fc <_ZN7CDS_Map6DeleteEP6RValue+0x130> */
/* @0x20b740 ldr r3, [r4, #0x8] */
/* @0x20b744 cmp r0, r3 */
/* @0x20b748 bne 0x20b734 <_ZN7CDS_Map6DeleteEP6RValue+0x68> */
/* @0x20b74c ldr r3, [r4] */
/* @0x20b750 ldr r6, [r4, #0xc] */
/* @0x20b754 cmp r3, #0 */
/* @0x20b758 ldrne r2, [r4, #0x4] */
/* @0x20b75c ldreq r0, [r4, #0x4] */
/* @0x20b760 strne r2, [r3, #0x4] */
/* @0x20b764 ldrne r0, [r4, #0x4] */
/* @0x20b768 streq r0, [r2, r1, lsl #3] */
/* @0x20b76c cmp r0, #0 */
/* @0x20b770 streq r3, [r12, #0x4] */
/* @0x20b774 strne r3, [r0] */
/* @0x20b778 cmp r6, #0 */
/* @0x20b77c beq 0x20b7e8 <_ZN7CDS_Map6DeleteEP6RValue+0x11c> */
/* @0x20b780 ldr r3, [r6, #0xc] */
/* @0x20b784 sub r3, r3, #1 */
/* @0x20b788 bic r3, r3, #-16777216 */
/* @0x20b78c bic r3, r3, #3 */
/* @0x20b790 cmp r3, #0 */
/* @0x20b794 beq 0x20b878 <_ZN7CDS_Map6DeleteEP6RValue+0x1ac> */
/* @0x20b798 ldr r1, [r6, #0x1c] */
/* @0x20b79c mov r3, #0 */
/* @0x20b7a0 str r3, [r6, #0x8] */
/* @0x20b7a4 mov r2, #5 */
/* @0x20b7a8 sub r1, r1, #1 */
/* @0x20b7ac str r3, [r6] */
/* @0x20b7b0 bic r3, r1, #-16777216 */
/* @0x20b7b4 str r2, [r6, #0xc] */
/* @0x20b7b8 bic r3, r3, #3 */
/* @0x20b7bc cmp r3, #0 */
/* @0x20b7c0 bne 0x20b7cc <_ZN7CDS_Map6DeleteEP6RValue+0x100> */
/* @0x20b7c4 add r0, r6, #16 */
/* @0x20b7c8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20b7cc mov r3, #0 */
/* @0x20b7d0 mov r2, #5 */
/* @0x20b7d4 str r3, [r6, #0x18] */
/* @0x20b7d8 mov r0, r6 */
/* @0x20b7dc str r3, [r6, #0x10] */
/* @0x20b7e0 str r2, [r6, #0x1c] */
/* @0x20b7e4 bl 0x27d1d0 <_ZdlPv> */
/* @0x20b7e8 mov r0, r4 */
/* @0x20b7ec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x20b7f0 ldr r3, [r5, #0x8] */
/* @0x20b7f4 sub r3, r3, #1 */
/* @0x20b7f8 str r3, [r5, #0x8] */
/* @0x20b7fc add sp, sp, #8 */
/* @0x20b800 pop {r4, r5, r6, pc} */
/* @0x20b804 cmp r3, #11 */
/* @0x20b808 beq 0x20b85c <_ZN7CDS_Map6DeleteEP6RValue+0x190> */
/* @0x20b80c ble 0x20b824 <_ZN7CDS_Map6DeleteEP6RValue+0x158> */
/* @0x20b810 mvn r2, #-16777216 */
/* @0x20b814 cmp r3, r2 */
/* @0x20b818 bne 0x20b830 <_ZN7CDS_Map6DeleteEP6RValue+0x164> */
/* @0x20b81c mov r0, #0 */
/* @0x20b820 b 0x20b714 <_ZN7CDS_Map6DeleteEP6RValue+0x48> */
/* @0x20b824 sub r2, r3, #8 */
/* @0x20b828 cmp r2, #1 */
/* @0x20b82c bls 0x20b85c <_ZN7CDS_Map6DeleteEP6RValue+0x190> */
/* @0x20b830 cmp r3, #0 */
/* @0x20b834 bne 0x20b86c <_ZN7CDS_Map6DeleteEP6RValue+0x1a0> */
/* @0x20b838 ldm r1, {r0, r1} */
/* @0x20b83c mov r2, r0 */
/* @0x20b840 add r0, sp, #8 */
/* @0x20b844 mov r3, r1 */
/* @0x20b848 mov r1, #8 */
/* @0x20b84c strd r2, r3, [r0, #-8]! */
/* @0x20b850 mov r0, sp */
/* @0x20b854 bl 0x27dfa0 <_Z7CalcCRCPKci> */
/* @0x20b858 b 0x20b714 <_ZN7CDS_Map6DeleteEP6RValue+0x48> */
/* @0x20b85c mov r0, r1 */
/* @0x20b860 mov r1, #8 */
/* @0x20b864 bl 0x27dfa0 <_Z7CalcCRCPKci> */
/* @0x20b868 b 0x20b714 <_ZN7CDS_Map6DeleteEP6RValue+0x48> */
/* @0x20b86c mov r0, r1 */
/* @0x20b870 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x20b874 b 0x20b83c <_ZN7CDS_Map6DeleteEP6RValue+0x170> */
/* @0x20b878 mov r0, r6 */
/* @0x20b87c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20b880 b 0x20b798 <_ZN7CDS_Map6DeleteEP6RValue+0xcc> */

/* ── FUNC 0x20b884 · CDS_Map::Add(RValue*, RValue*) · size=960 · insn=240 */
/* @0x20b884 ldr r3, [r1, #0xc] */
/* @0x20b888 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x20b88c bic r3, r3, #-16777216 */
/* @0x20b890 cmp r3, #6 */
/* @0x20b894 sub sp, sp, #12 */
/* @0x20b898 mov r6, r1 */
/* @0x20b89c mov r8, r0 */
/* @0x20b8a0 mov r7, r2 */
/* @0x20b8a4 beq 0x20badc <_ZN7CDS_Map3AddEP6RValueS1_+0x258> */
/* @0x20b8a8 bgt 0x20b8dc <_ZN7CDS_Map3AddEP6RValueS1_+0x58> */
/* @0x20b8ac cmp r3, #4 */
/* @0x20b8b0 bgt 0x20b8f4 <_ZN7CDS_Map3AddEP6RValueS1_+0x70> */
/* @0x20b8b4 cmp r3, #2 */
/* @0x20b8b8 bge 0x20badc <_ZN7CDS_Map3AddEP6RValueS1_+0x258> */
/* @0x20b8bc cmp r3, #1 */
/* @0x20b8c0 bne 0x20baac <_ZN7CDS_Map3AddEP6RValueS1_+0x228> */
/* @0x20b8c4 ldr r0, [r1] */
/* @0x20b8c8 cmp r0, #0 */
/* @0x20b8cc ldrne r0, [r0] */
/* @0x20b8d0 bl 0x27dfa8 <_Z14CalcCRC_stringPKc> */
/* @0x20b8d4 mov r9, r0 */
/* @0x20b8d8 b 0x20b8f8 <_ZN7CDS_Map3AddEP6RValueS1_+0x74> */
/* @0x20b8dc cmp r3, #11 */
/* @0x20b8e0 beq 0x20badc <_ZN7CDS_Map3AddEP6RValueS1_+0x258> */
/* @0x20b8e4 ble 0x20baa0 <_ZN7CDS_Map3AddEP6RValueS1_+0x21c> */
/* @0x20b8e8 mvn r2, #-16777216 */
/* @0x20b8ec cmp r3, r2 */
/* @0x20b8f0 bne 0x20baac <_ZN7CDS_Map3AddEP6RValueS1_+0x228> */
/* @0x20b8f4 mov r9, #0 */
/* @0x20b8f8 mov r0, #32 */
/* @0x20b8fc bl 0x27c524 <_Znwj> */
/* @0x20b900 mov r1, #0 */
/* @0x20b904 mov r2, #16 */
/* @0x20b908 add r5, r0, #16 */
/* @0x20b90c mov r4, r0 */
/* @0x20b910 bl 0xb65b0 <memset@plt> */
/* @0x20b914 mov r1, #0 */
/* @0x20b918 mov r0, r5 */
/* @0x20b91c mov r2, #16 */
/* @0x20b920 bl 0xb65b0 <memset@plt> */
/* @0x20b924 ldr r3, [r4, #0xc] */
/* @0x20b928 sub r3, r3, #1 */
/* @0x20b92c bic r3, r3, #-16777216 */
/* @0x20b930 bic r3, r3, #3 */
/* @0x20b934 cmp r3, #0 */
/* @0x20b938 beq 0x20ba94 <_ZN7CDS_Map3AddEP6RValueS1_+0x210> */
/* @0x20b93c mov r3, #5 */
/* @0x20b940 str r3, [r4, #0xc] */
/* @0x20b944 ldr r3, [r6, #0xc] */
/* @0x20b948 mov r2, #0 */
/* @0x20b94c str r2, [r4, #0x8] */
/* @0x20b950 ldr r1, [r6, #0x8] */
/* @0x20b954 str r3, [r4, #0xc] */
/* @0x20b958 ldr r3, [r6, #0xc] */
/* @0x20b95c str r2, [r4] */
/* @0x20b960 bic r3, r3, #-16777216 */
/* @0x20b964 str r1, [r4, #0x8] */
/* @0x20b968 cmp r3, #14 */
/* @0x20b96c addls pc, pc, r3, lsl #2 */
/* @0x20b970 b 0x20b9b8 <_ZN7CDS_Map3AddEP6RValueS1_+0x134> */
/* @0x20b974 b 0x20ba7c <_ZN7CDS_Map3AddEP6RValueS1_+0x1f8> */
/* @0x20b978 b 0x20bb14 <_ZN7CDS_Map3AddEP6RValueS1_+0x290> */
/* @0x20b97c b 0x20bb94 <_ZN7CDS_Map3AddEP6RValueS1_+0x310> */
/* @0x20b980 b 0x20b9b0 <_ZN7CDS_Map3AddEP6RValueS1_+0x12c> */
/* @0x20b984 b 0x20b9b8 <_ZN7CDS_Map3AddEP6RValueS1_+0x134> */
/* @0x20b988 b 0x20b9b8 <_ZN7CDS_Map3AddEP6RValueS1_+0x134> */
/* @0x20b98c b 0x20bb70 <_ZN7CDS_Map3AddEP6RValueS1_+0x2ec> */
/* @0x20b990 b 0x20b9b0 <_ZN7CDS_Map3AddEP6RValueS1_+0x12c> */
/* @0x20b994 b 0x20b9b8 <_ZN7CDS_Map3AddEP6RValueS1_+0x134> */
/* @0x20b998 b 0x20b9b8 <_ZN7CDS_Map3AddEP6RValueS1_+0x134> */
/* @0x20b99c b 0x20ba7c <_ZN7CDS_Map3AddEP6RValueS1_+0x1f8> */
/* @0x20b9a0 b 0x20b9b8 <_ZN7CDS_Map3AddEP6RValueS1_+0x134> */
/* @0x20b9a4 b 0x20b9b8 <_ZN7CDS_Map3AddEP6RValueS1_+0x134> */
/* @0x20b9a8 b 0x20ba7c <_ZN7CDS_Map3AddEP6RValueS1_+0x1f8> */
/* @0x20b9ac b 0x20b9b0 <_ZN7CDS_Map3AddEP6RValueS1_+0x12c> */
/* @0x20b9b0 ldr r3, [r6] */
/* @0x20b9b4 str r3, [r4] */
/* @0x20b9b8 ldr r3, [r4, #0x1c] */
/* @0x20b9bc sub r3, r3, #1 */
/* @0x20b9c0 bic r3, r3, #-16777216 */
/* @0x20b9c4 bic r3, r3, #3 */
/* @0x20b9c8 cmp r3, #0 */
/* @0x20b9cc beq 0x20ba88 <_ZN7CDS_Map3AddEP6RValueS1_+0x204> */
/* @0x20b9d0 mov r3, #5 */
/* @0x20b9d4 str r3, [r4, #0x1c] */
/* @0x20b9d8 ldr r3, [r7, #0xc] */
/* @0x20b9dc mov r2, #0 */
/* @0x20b9e0 str r2, [r4, #0x18] */
/* @0x20b9e4 ldr r1, [r7, #0x8] */
/* @0x20b9e8 str r3, [r4, #0x1c] */
/* @0x20b9ec ldr r3, [r7, #0xc] */
/* @0x20b9f0 str r2, [r4, #0x10] */
/* @0x20b9f4 bic r3, r3, #-16777216 */
/* @0x20b9f8 str r1, [r4, #0x18] */
/* @0x20b9fc cmp r3, #14 */
/* @0x20ba00 addls pc, pc, r3, lsl #2 */
/* @0x20ba04 b 0x20ba4c <_ZN7CDS_Map3AddEP6RValueS1_+0x1c8> */
/* @0x20ba08 b 0x20ba6c <_ZN7CDS_Map3AddEP6RValueS1_+0x1e8> */
/* @0x20ba0c b 0x20bb58 <_ZN7CDS_Map3AddEP6RValueS1_+0x2d4> */
/* @0x20ba10 b 0x20bb2c <_ZN7CDS_Map3AddEP6RValueS1_+0x2a8> */
/* @0x20ba14 b 0x20ba44 <_ZN7CDS_Map3AddEP6RValueS1_+0x1c0> */
/* @0x20ba18 b 0x20ba4c <_ZN7CDS_Map3AddEP6RValueS1_+0x1c8> */
/* @0x20ba1c b 0x20ba4c <_ZN7CDS_Map3AddEP6RValueS1_+0x1c8> */
/* @0x20ba20 b 0x20baf0 <_ZN7CDS_Map3AddEP6RValueS1_+0x26c> */
/* @0x20ba24 b 0x20ba44 <_ZN7CDS_Map3AddEP6RValueS1_+0x1c0> */
/* @0x20ba28 b 0x20ba4c <_ZN7CDS_Map3AddEP6RValueS1_+0x1c8> */
/* @0x20ba2c b 0x20ba4c <_ZN7CDS_Map3AddEP6RValueS1_+0x1c8> */
/* @0x20ba30 b 0x20ba6c <_ZN7CDS_Map3AddEP6RValueS1_+0x1e8> */
/* @0x20ba34 b 0x20ba4c <_ZN7CDS_Map3AddEP6RValueS1_+0x1c8> */
/* @0x20ba38 b 0x20ba4c <_ZN7CDS_Map3AddEP6RValueS1_+0x1c8> */
/* @0x20ba3c b 0x20ba6c <_ZN7CDS_Map3AddEP6RValueS1_+0x1e8> */
/* @0x20ba40 b 0x20ba44 <_ZN7CDS_Map3AddEP6RValueS1_+0x1c0> */
/* @0x20ba44 ldr r3, [r7] */
/* @0x20ba48 str r3, [r4, #0x10] */
/* @0x20ba4c mov r1, r6 */
/* @0x20ba50 mov r0, r8 */
/* @0x20ba54 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue> */
/* @0x20ba58 subs r5, r0, #0 */
/* @0x20ba5c movne r0, #0 */
/* @0x20ba60 beq 0x20bbcc <_ZN7CDS_Map3AddEP6RValueS1_+0x348> */
/* @0x20ba64 add sp, sp, #12 */
/* @0x20ba68 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x20ba6c ldm r7, {r2, r3} */
/* @0x20ba70 str r2, [r4, #0x10] */
/* @0x20ba74 str r3, [r4, #0x14] */
/* @0x20ba78 b 0x20ba4c <_ZN7CDS_Map3AddEP6RValueS1_+0x1c8> */
/* @0x20ba7c ldm r6, {r2, r3} */
/* @0x20ba80 stm r4, {r2, r3} */
/* @0x20ba84 b 0x20b9b8 <_ZN7CDS_Map3AddEP6RValueS1_+0x134> */
/* @0x20ba88 mov r0, r5 */
/* @0x20ba8c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20ba90 b 0x20b9d0 <_ZN7CDS_Map3AddEP6RValueS1_+0x14c> */
/* @0x20ba94 mov r0, r4 */
/* @0x20ba98 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20ba9c b 0x20b93c <_ZN7CDS_Map3AddEP6RValueS1_+0xb8> */
/* @0x20baa0 sub r2, r3, #8 */
/* @0x20baa4 cmp r2, #1 */
/* @0x20baa8 bls 0x20badc <_ZN7CDS_Map3AddEP6RValueS1_+0x258> */
/* @0x20baac cmp r3, #0 */
/* @0x20bab0 bne 0x20bbc0 <_ZN7CDS_Map3AddEP6RValueS1_+0x33c> */
/* @0x20bab4 ldm r6, {r0, r1} */
/* @0x20bab8 mov r4, r0 */
/* @0x20babc add r0, sp, #8 */
/* @0x20bac0 mov r5, r1 */
/* @0x20bac4 mov r1, #8 */
/* @0x20bac8 strd r4, r5, [r0, #-8]! */
/* @0x20bacc mov r0, sp */
/* @0x20bad0 bl 0x27dfa0 <_Z7CalcCRCPKci> */
/* @0x20bad4 mov r9, r0 */
/* @0x20bad8 b 0x20b8f8 <_ZN7CDS_Map3AddEP6RValueS1_+0x74> */
/* @0x20badc mov r0, r6 */
/* @0x20bae0 mov r1, #8 */
/* @0x20bae4 bl 0x27dfa0 <_Z7CalcCRCPKci> */
/* @0x20bae8 mov r9, r0 */
/* @0x20baec b 0x20b8f8 <_ZN7CDS_Map3AddEP6RValueS1_+0x74> */
/* @0x20baf0 ldr r3, [r7] */
/* @0x20baf4 str r3, [r4, #0x10] */
/* @0x20baf8 ldr r3, [r7] */
/* @0x20bafc cmp r3, #0 */
/* @0x20bb00 beq 0x20ba4c <_ZN7CDS_Map3AddEP6RValueS1_+0x1c8> */
/* @0x20bb04 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x20bb08 ldr r1, [r7] */
/* @0x20bb0c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x20bb10 b 0x20ba4c <_ZN7CDS_Map3AddEP6RValueS1_+0x1c8> */
/* @0x20bb14 ldr r3, [r6] */
/* @0x20bb18 cmp r3, #0 */
/* @0x20bb1c ldrne r2, [r3, #0x4] */
/* @0x20bb20 addne r2, r2, #1 */
/* @0x20bb24 strne r2, [r3, #0x4] */
/* @0x20bb28 b 0x20b9b4 <_ZN7CDS_Map3AddEP6RValueS1_+0x130> */
/* @0x20bb2c ldr r3, [r7] */
/* @0x20bb30 cmp r3, #0 */
/* @0x20bb34 str r3, [r4, #0x10] */
/* @0x20bb38 beq 0x20ba4c <_ZN7CDS_Map3AddEP6RValueS1_+0x1c8> */
/* @0x20bb3c ldr r1, [r3, #0x8] */
/* @0x20bb40 ldr r2, [r3] */
/* @0x20bb44 cmp r1, #0 */
/* @0x20bb48 streq r5, [r3, #0x8] */
/* @0x20bb4c add r2, r2, #1 */
/* @0x20bb50 str r2, [r3] */
/* @0x20bb54 b 0x20ba4c <_ZN7CDS_Map3AddEP6RValueS1_+0x1c8> */
/* @0x20bb58 ldr r3, [r7] */
/* @0x20bb5c cmp r3, #0 */
/* @0x20bb60 ldrne r2, [r3, #0x4] */
/* @0x20bb64 addne r2, r2, #1 */
/* @0x20bb68 strne r2, [r3, #0x4] */
/* @0x20bb6c b 0x20ba48 <_ZN7CDS_Map3AddEP6RValueS1_+0x1c4> */
/* @0x20bb70 ldr r3, [r6] */
/* @0x20bb74 str r3, [r4] */
/* @0x20bb78 ldr r3, [r6] */
/* @0x20bb7c cmp r3, #0 */
/* @0x20bb80 beq 0x20b9b8 <_ZN7CDS_Map3AddEP6RValueS1_+0x134> */
/* @0x20bb84 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x20bb88 ldr r1, [r6] */
/* @0x20bb8c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x20bb90 b 0x20b9b8 <_ZN7CDS_Map3AddEP6RValueS1_+0x134> */
/* @0x20bb94 ldr r3, [r6] */
/* @0x20bb98 cmp r3, #0 */
/* @0x20bb9c str r3, [r4] */
/* @0x20bba0 beq 0x20b9b8 <_ZN7CDS_Map3AddEP6RValueS1_+0x134> */
/* @0x20bba4 ldr r1, [r3, #0x8] */
/* @0x20bba8 ldr r2, [r3] */
/* @0x20bbac cmp r1, #0 */
/* @0x20bbb0 streq r4, [r3, #0x8] */
/* @0x20bbb4 add r2, r2, #1 */
/* @0x20bbb8 str r2, [r3] */
/* @0x20bbbc b 0x20b9b8 <_ZN7CDS_Map3AddEP6RValueS1_+0x134> */
/* @0x20bbc0 mov r0, r6 */
/* @0x20bbc4 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x20bbc8 b 0x20bab8 <_ZN7CDS_Map3AddEP6RValueS1_+0x234> */
/* @0x20bbcc ldr r6, [r8] */
/* @0x20bbd0 movw r2, #0x132 */
/* @0x20bbd4 ldr r1, [pc, #0x64] */
/* @0x20bbd8 mov r3, #1 */
/* @0x20bbdc mov r0, #16 */
/* @0x20bbe0 add r1, pc, r1 */
/* @0x20bbe4 ldm r6, {r7, r8} */
/* @0x20bbe8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x20bbec and r8, r9, r8 */
/* @0x20bbf0 ldr r2, [r7, r8, lsl #3] */
/* @0x20bbf4 add r3, r7, r8, lsl #3 */
/* @0x20bbf8 cmp r2, #0 */
/* @0x20bbfc ldrne r2, [r3, #0x4] */
/* @0x20bc00 str r9, [r0, #0x8] */
/* @0x20bc04 str r4, [r0, #0xc] */
/* @0x20bc08 strne r2, [r0] */
/* @0x20bc0c streq r0, [r3, #0x4] */
/* @0x20bc10 strne r0, [r2, #0x4] */
/* @0x20bc14 strne r0, [r3, #0x4] */
/* @0x20bc18 ldr r3, [r6, #0x8] */
/* @0x20bc1c streq r0, [r7, r8, lsl #3] */
/* @0x20bc20 strne r5, [r0, #0x4] */
/* @0x20bc24 streq r2, [r0, #0x4] */
/* @0x20bc28 streq r2, [r0] */
/* @0x20bc2c mov r0, #1 */
/* @0x20bc30 add r3, r3, r0 */
/* @0x20bc34 str r3, [r6, #0x8] */
/* @0x20bc38 add sp, sp, #12 */
/* @0x20bc3c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x20bc40 andseq r1, r4, r12, asr #1 */

/* ── FUNC 0x20bc44 · CDS_Map::Replace(RValue*, RValue*) · size=380 · insn=95 */
/* @0x20bc44 push {r3, r4, r5, r6, r7, lr} */
/* @0x20bc48 mov r5, r2 */
/* @0x20bc4c mov r7, r0 */
/* @0x20bc50 mov r6, r1 */
/* @0x20bc54 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue> */
/* @0x20bc58 subs r4, r0, #0 */
/* @0x20bc5c beq 0x20bd0c <_ZN7CDS_Map7ReplaceEP6RValueS1_+0xc8> */
/* @0x20bc60 ldr r3, [r4, #0x1c] */
/* @0x20bc64 add r6, r4, #16 */
/* @0x20bc68 sub r3, r3, #1 */
/* @0x20bc6c bic r3, r3, #-16777216 */
/* @0x20bc70 bic r3, r3, #3 */
/* @0x20bc74 cmp r3, #0 */
/* @0x20bc78 beq 0x20bd00 <_ZN7CDS_Map7ReplaceEP6RValueS1_+0xbc> */
/* @0x20bc7c mov r3, #5 */
/* @0x20bc80 str r3, [r4, #0x1c] */
/* @0x20bc84 ldr r3, [r5, #0xc] */
/* @0x20bc88 mov r2, #0 */
/* @0x20bc8c str r2, [r4, #0x18] */
/* @0x20bc90 ldr r1, [r5, #0x8] */
/* @0x20bc94 str r3, [r4, #0x1c] */
/* @0x20bc98 ldr r3, [r5, #0xc] */
/* @0x20bc9c str r2, [r4, #0x10] */
/* @0x20bca0 bic r3, r3, #-16777216 */
/* @0x20bca4 str r1, [r4, #0x18] */
/* @0x20bca8 cmp r3, #14 */
/* @0x20bcac addls pc, pc, r3, lsl #2 */
/* @0x20bcb0 b 0x20bd84 <_ZN7CDS_Map7ReplaceEP6RValueS1_+0x140> */
/* @0x20bcb4 b 0x20bd24 <_ZN7CDS_Map7ReplaceEP6RValueS1_+0xe0> */
/* @0x20bcb8 b 0x20bd3c <_ZN7CDS_Map7ReplaceEP6RValueS1_+0xf8> */
/* @0x20bcbc b 0x20bd5c <_ZN7CDS_Map7ReplaceEP6RValueS1_+0x118> */
/* @0x20bcc0 b 0x20bcf0 <_ZN7CDS_Map7ReplaceEP6RValueS1_+0xac> */
/* @0x20bcc4 b 0x20bd84 <_ZN7CDS_Map7ReplaceEP6RValueS1_+0x140> */
/* @0x20bcc8 b 0x20bd84 <_ZN7CDS_Map7ReplaceEP6RValueS1_+0x140> */
/* @0x20bccc b 0x20bd8c <_ZN7CDS_Map7ReplaceEP6RValueS1_+0x148> */
/* @0x20bcd0 b 0x20bcf0 <_ZN7CDS_Map7ReplaceEP6RValueS1_+0xac> */
/* @0x20bcd4 b 0x20bd84 <_ZN7CDS_Map7ReplaceEP6RValueS1_+0x140> */
/* @0x20bcd8 b 0x20bd84 <_ZN7CDS_Map7ReplaceEP6RValueS1_+0x140> */
/* @0x20bcdc b 0x20bd24 <_ZN7CDS_Map7ReplaceEP6RValueS1_+0xe0> */
/* @0x20bce0 b 0x20bd84 <_ZN7CDS_Map7ReplaceEP6RValueS1_+0x140> */
/* @0x20bce4 b 0x20bd84 <_ZN7CDS_Map7ReplaceEP6RValueS1_+0x140> */
/* @0x20bce8 b 0x20bd24 <_ZN7CDS_Map7ReplaceEP6RValueS1_+0xe0> */
/* @0x20bcec b 0x20bcf0 <_ZN7CDS_Map7ReplaceEP6RValueS1_+0xac> */
/* @0x20bcf0 ldr r3, [r5] */
/* @0x20bcf4 mov r0, #1 */
/* @0x20bcf8 str r3, [r4, #0x10] */
/* @0x20bcfc pop {r3, r4, r5, r6, r7, pc} */
/* @0x20bd00 mov r0, r6 */
/* @0x20bd04 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20bd08 b 0x20bc7c <_ZN7CDS_Map7ReplaceEP6RValueS1_+0x38> */
/* @0x20bd0c mov r0, r7 */
/* @0x20bd10 mov r1, r6 */
/* @0x20bd14 mov r2, r5 */
/* @0x20bd18 bl 0x20b884 <_ZN7CDS_Map3AddEP6RValueS1_> */
/* @0x20bd1c mov r0, r4 */
/* @0x20bd20 pop {r3, r4, r5, r6, r7, pc} */
/* @0x20bd24 ldr r2, [r5] */
/* @0x20bd28 mov r0, #1 */
/* @0x20bd2c ldr r3, [r5, #0x4] */
/* @0x20bd30 str r2, [r4, #0x10] */
/* @0x20bd34 str r3, [r4, #0x14] */
/* @0x20bd38 pop {r3, r4, r5, r6, r7, pc} */
/* @0x20bd3c ldr r3, [r5] */
/* @0x20bd40 mov r0, #1 */
/* @0x20bd44 cmp r3, #0 */
/* @0x20bd48 ldrne r2, [r3, #0x4] */
/* @0x20bd4c addne r2, r2, #1 */
/* @0x20bd50 strne r2, [r3, #0x4] */
/* @0x20bd54 str r3, [r4, #0x10] */
/* @0x20bd58 pop {r3, r4, r5, r6, r7, pc} */
/* @0x20bd5c ldr r3, [r5] */
/* @0x20bd60 cmp r3, #0 */
/* @0x20bd64 str r3, [r4, #0x10] */
/* @0x20bd68 beq 0x20bd84 <_ZN7CDS_Map7ReplaceEP6RValueS1_+0x140> */
/* @0x20bd6c ldr r1, [r3, #0x8] */
/* @0x20bd70 ldr r2, [r3] */
/* @0x20bd74 cmp r1, #0 */
/* @0x20bd78 add r2, r2, #1 */
/* @0x20bd7c str r2, [r3] */
/* @0x20bd80 beq 0x20bdb4 <_ZN7CDS_Map7ReplaceEP6RValueS1_+0x170> */
/* @0x20bd84 mov r0, #1 */
/* @0x20bd88 pop {r3, r4, r5, r6, r7, pc} */
/* @0x20bd8c ldr r3, [r5] */
/* @0x20bd90 str r3, [r4, #0x10] */
/* @0x20bd94 ldr r3, [r5] */
/* @0x20bd98 cmp r3, #0 */
/* @0x20bd9c beq 0x20bd84 <_ZN7CDS_Map7ReplaceEP6RValueS1_+0x140> */
/* @0x20bda0 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x20bda4 ldr r1, [r5] */
/* @0x20bda8 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x20bdac mov r0, #1 */
/* @0x20bdb0 pop {r3, r4, r5, r6, r7, pc} */
/* @0x20bdb4 str r6, [r3, #0x8] */
/* @0x20bdb8 mov r0, #1 */
/* @0x20bdbc pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x20bdc0 · CreateDsMap(int, ...) · size=384 · insn=96 */
/* @0x20bdc0 push {r0, r1, r2, r3} */
/* @0x20bdc4 mov r0, #4 */
/* @0x20bdc8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x20bdcc sub sp, sp, #60 */
/* @0x20bdd0 bl 0x27c524 <_Znwj> */
/* @0x20bdd4 mov r8, r0 */
/* @0x20bdd8 bl 0x203624 <_ZN7CDS_MapC2Ev> */
/* @0x20bddc ldr r3, [sp, #0x60] */
/* @0x20bde0 cmp r3, #0 */
/* @0x20bde4 add r3, sp, #100 */
/* @0x20bde8 str r3, [sp, #0x14] */
/* @0x20bdec ble 0x20bf0c <_Z11CreateDsMapiz+0x14c> */
/* @0x20bdf0 add r7, sp, #24 */
/* @0x20bdf4 mov r6, #0 */
/* @0x20bdf8 add r3, sp, #32 */
/* @0x20bdfc add r11, sp, #28 */
/* @0x20be00 str r3, [sp, #0xc] */
/* @0x20be04 add r5, sp, #40 */
/* @0x20be08 add r3, sp, #44 */
/* @0x20be0c mov r4, r7 */
/* @0x20be10 str r3, [sp] */
/* @0x20be14 mov r9, r6 */
/* @0x20be18 add r3, sp, #48 */
/* @0x20be1c str r3, [sp, #0x4] */
/* @0x20be20 add r3, sp, #52 */
/* @0x20be24 str r3, [sp, #0x8] */
/* @0x20be28 b 0x20be90 <_Z11CreateDsMapiz+0xd0> */
/* @0x20be2c bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x20be30 mov r0, r8 */
/* @0x20be34 mov r1, r4 */
/* @0x20be38 mov r2, r5 */
/* @0x20be3c add r6, r6, #1 */
/* @0x20be40 bl 0x20b884 <_ZN7CDS_Map3AddEP6RValueS1_> */
/* @0x20be44 ldr r3, [sp, #0x24] */
/* @0x20be48 sub r3, r3, #1 */
/* @0x20be4c bic r3, r3, #-16777216 */
/* @0x20be50 bic r3, r3, #3 */
/* @0x20be54 cmp r3, #0 */
/* @0x20be58 beq 0x20bf30 <_Z11CreateDsMapiz+0x170> */
/* @0x20be5c ldr r3, [sp, #0x34] */
/* @0x20be60 mov r2, #5 */
/* @0x20be64 str r9, [sp, #0x20] */
/* @0x20be68 sub r3, r3, #1 */
/* @0x20be6c str r2, [sp, #0x24] */
/* @0x20be70 bic r3, r3, #-16777216 */
/* @0x20be74 str r9, [sp, #0x18] */
/* @0x20be78 bic r3, r3, #3 */
/* @0x20be7c cmp r3, #0 */
/* @0x20be80 beq 0x20bef8 <_Z11CreateDsMapiz+0x138> */
/* @0x20be84 ldr r3, [sp, #0x60] */
/* @0x20be88 cmp r6, r3 */
/* @0x20be8c beq 0x20bf0c <_Z11CreateDsMapiz+0x14c> */
/* @0x20be90 ldr r10, [sp, #0x14] */
/* @0x20be94 mov r0, r4 */
/* @0x20be98 mov r2, #1 */
/* @0x20be9c str r9, [r7] */
/* @0x20bea0 str r2, [sp, #0x24] */
/* @0x20bea4 mov r7, r4 */
/* @0x20bea8 ldr r1, [r10], #11 */
/* @0x20beac str r9, [r11] */
/* @0x20beb0 str r9, [sp, #0x20] */
/* @0x20beb4 str r9, [r5] */
/* @0x20beb8 str r9, [sp, #0x2c] */
/* @0x20bebc str r9, [sp, #0x30] */
/* @0x20bec0 str r9, [sp, #0x34] */
/* @0x20bec4 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x20bec8 bic r3, r10, #7 */
/* @0x20becc mov r0, r5 */
/* @0x20bed0 ldr lr, [r3, #0x8] */
/* @0x20bed4 mov r12, r3 */
/* @0x20bed8 ldrd r2, r3, [r12], #12 */
/* @0x20bedc cmp lr, #0 */
/* @0x20bee0 mov r1, lr */
/* @0x20bee4 str r12, [sp, #0x14] */
/* @0x20bee8 bne 0x20be2c <_Z11CreateDsMapiz+0x6c> */
/* @0x20beec strd r2, r3, [sp, #40] */
/* @0x20bef0 str lr, [sp, #0x34] */
/* @0x20bef4 b 0x20be30 <_Z11CreateDsMapiz+0x70> */
/* @0x20bef8 mov r0, r5 */
/* @0x20befc bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20bf00 ldr r3, [sp, #0x60] */
/* @0x20bf04 cmp r6, r3 */
/* @0x20bf08 bne 0x20be90 <_Z11CreateDsMapiz+0xd0> */
/* @0x20bf0c bl 0x100014 <_Z18FindFreeDsMapIndexv> */
/* @0x20bf10 ldr r3, [pc, #0x24] */
/* @0x20bf14 ldr r3, [pc, r3] */
/* @0x20bf18 ldr r3, [r3, #0x4] */
/* @0x20bf1c str r8, [r3, r0, lsl #2] */
/* @0x20bf20 add sp, sp, #60 */
/* @0x20bf24 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x20bf28 add sp, sp, #16 */
/* @0x20bf2c bx lr */
/* @0x20bf30 mov r0, r4 */
/* @0x20bf34 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20bf38 b 0x20be5c <_Z11CreateDsMapiz+0x9c> */
/* @0x20bf3c andseq r1, lr, r8, lsr #20 */

/* ── FUNC 0x20bf40 · AddToDsMap(int, char*, double) · size=240 · insn=60 */
/* @0x20bf40 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x20bf44 subs r6, r1, #0 */
/* @0x20bf48 sub sp, sp, #36 */
/* @0x20bf4c mov r4, r2 */
/* @0x20bf50 mov r5, r3 */
/* @0x20bf54 beq 0x20c004 <_Z10AddToDsMapiPcd+0xc4> */
/* @0x20bf58 bl 0x2052d4 <_Z8GetDsMapi> */
/* @0x20bf5c subs r9, r0, #0 */
/* @0x20bf60 beq 0x20c004 <_Z10AddToDsMapiPcd+0xc4> */
/* @0x20bf64 add r8, sp, #16 */
/* @0x20bf68 mov r1, r6 */
/* @0x20bf6c mov r0, sp */
/* @0x20bf70 mov r6, #0 */
/* @0x20bf74 mov r3, #1 */
/* @0x20bf78 str r6, [sp] */
/* @0x20bf7c str r3, [sp, #0xc] */
/* @0x20bf80 str r6, [sp, #0x4] */
/* @0x20bf84 str r6, [sp, #0x8] */
/* @0x20bf88 str r6, [sp, #0x10] */
/* @0x20bf8c str r6, [sp, #0x14] */
/* @0x20bf90 str r6, [sp, #0x18] */
/* @0x20bf94 str r6, [sp, #0x1c] */
/* @0x20bf98 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x20bf9c mov r0, r9 */
/* @0x20bfa0 mov r1, sp */
/* @0x20bfa4 mov r2, r8 */
/* @0x20bfa8 str r6, [sp, #0x1c] */
/* @0x20bfac strd r4, r5, [sp, #16] */
/* @0x20bfb0 bl 0x20b884 <_ZN7CDS_Map3AddEP6RValueS1_> */
/* @0x20bfb4 ldr r3, [sp, #0xc] */
/* @0x20bfb8 sub r3, r3, #1 */
/* @0x20bfbc bic r3, r3, #-16777216 */
/* @0x20bfc0 bic r3, r3, #3 */
/* @0x20bfc4 cmp r3, r6 */
/* @0x20bfc8 beq 0x20c024 <_Z10AddToDsMapiPcd+0xe4> */
/* @0x20bfcc ldr r1, [sp, #0x1c] */
/* @0x20bfd0 mov r3, #0 */
/* @0x20bfd4 str r3, [sp, #0x8] */
/* @0x20bfd8 mov r2, #5 */
/* @0x20bfdc sub r1, r1, #1 */
/* @0x20bfe0 str r3, [sp] */
/* @0x20bfe4 bic r3, r1, #-16777216 */
/* @0x20bfe8 str r2, [sp, #0xc] */
/* @0x20bfec bic r3, r3, #3 */
/* @0x20bff0 cmp r3, #0 */
/* @0x20bff4 movne r0, #1 */
/* @0x20bff8 beq 0x20c010 <_Z10AddToDsMapiPcd+0xd0> */
/* @0x20bffc add sp, sp, #36 */
/* @0x20c000 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x20c004 mov r0, #0 */
/* @0x20c008 add sp, sp, #36 */
/* @0x20c00c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x20c010 mov r0, r8 */
/* @0x20c014 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20c018 mov r0, #1 */
/* @0x20c01c add sp, sp, #36 */
/* @0x20c020 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x20c024 mov r0, sp */
/* @0x20c028 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20c02c b 0x20bfcc <_Z10AddToDsMapiPcd+0x8c> */

/* ── FUNC 0x20c030 · AddToDsMap(int, char*, char*) · size=240 · insn=60 */
/* @0x20c030 push {r4, r5, r6, r7, r8, lr} */
/* @0x20c034 subs r7, r1, #0 */
/* @0x20c038 sub sp, sp, #32 */
/* @0x20c03c mov r6, r2 */
/* @0x20c040 beq 0x20c0f4 <_Z10AddToDsMapiPcS_+0xc4> */
/* @0x20c044 bl 0x2052d4 <_Z8GetDsMapi> */
/* @0x20c048 subs r8, r0, #0 */
/* @0x20c04c beq 0x20c0f4 <_Z10AddToDsMapiPcS_+0xc4> */
/* @0x20c050 add r4, sp, #16 */
/* @0x20c054 mov r1, r7 */
/* @0x20c058 mov r0, sp */
/* @0x20c05c mov r3, #0 */
/* @0x20c060 mov r2, #1 */
/* @0x20c064 str r3, [sp] */
/* @0x20c068 str r3, [sp, #0x4] */
/* @0x20c06c str r3, [sp, #0x8] */
/* @0x20c070 str r3, [sp, #0x10] */
/* @0x20c074 str r3, [sp, #0x14] */
/* @0x20c078 str r3, [sp, #0x18] */
/* @0x20c07c str r3, [sp, #0x1c] */
/* @0x20c080 str r2, [sp, #0xc] */
/* @0x20c084 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x20c088 mov r1, r6 */
/* @0x20c08c mov r0, r4 */
/* @0x20c090 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x20c094 mov r0, r8 */
/* @0x20c098 mov r1, sp */
/* @0x20c09c mov r2, r4 */
/* @0x20c0a0 bl 0x20b884 <_ZN7CDS_Map3AddEP6RValueS1_> */
/* @0x20c0a4 ldr r3, [sp, #0xc] */
/* @0x20c0a8 sub r3, r3, #1 */
/* @0x20c0ac bic r3, r3, #-16777216 */
/* @0x20c0b0 bic r3, r3, #3 */
/* @0x20c0b4 cmp r3, #0 */
/* @0x20c0b8 beq 0x20c114 <_Z10AddToDsMapiPcS_+0xe4> */
/* @0x20c0bc ldr r1, [sp, #0x1c] */
/* @0x20c0c0 mov r3, #0 */
/* @0x20c0c4 str r3, [sp, #0x8] */
/* @0x20c0c8 mov r2, #5 */
/* @0x20c0cc sub r1, r1, #1 */
/* @0x20c0d0 str r3, [sp] */
/* @0x20c0d4 bic r3, r1, #-16777216 */
/* @0x20c0d8 str r2, [sp, #0xc] */
/* @0x20c0dc bic r3, r3, #3 */
/* @0x20c0e0 cmp r3, #0 */
/* @0x20c0e4 movne r0, #1 */
/* @0x20c0e8 beq 0x20c100 <_Z10AddToDsMapiPcS_+0xd0> */
/* @0x20c0ec add sp, sp, #32 */
/* @0x20c0f0 pop {r4, r5, r6, r7, r8, pc} */
/* @0x20c0f4 mov r0, #0 */
/* @0x20c0f8 add sp, sp, #32 */
/* @0x20c0fc pop {r4, r5, r6, r7, r8, pc} */
/* @0x20c100 mov r0, r4 */
/* @0x20c104 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20c108 mov r0, #1 */
/* @0x20c10c add sp, sp, #32 */
/* @0x20c110 pop {r4, r5, r6, r7, r8, pc} */
/* @0x20c114 mov r0, sp */
/* @0x20c118 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20c11c b 0x20c0bc <_Z10AddToDsMapiPcS_+0x8c> */

/* ── FUNC 0x20c120 · CDS_Grid::Clear(RValue*) · size=668 · insn=167 */
/* @0x20c120 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x20c124 mov r5, r0 */
/* @0x20c128 ldr r8, [r0, #0x4] */
/* @0x20c12c sub sp, sp, #12 */
/* @0x20c130 mov r9, r1 */
/* @0x20c134 cmp r8, #0 */
/* @0x20c138 ble 0x20c258 <_ZN8CDS_Grid5ClearEP6RValue+0x138> */
/* @0x20c13c ldr r2, [r0, #0x8] */
/* @0x20c140 mov r10, #0 */
/* @0x20c144 mov r11, r10 */
/* @0x20c148 cmp r2, #0 */
/* @0x20c14c ble 0x20c24c <_ZN8CDS_Grid5ClearEP6RValue+0x12c> */
/* @0x20c150 mov r4, #0 */
/* @0x20c154 mla r8, r8, r4, r10 */
/* @0x20c158 ldr r7, [r5] */
/* @0x20c15c add r6, r7, r8, lsl #4 */
/* @0x20c160 ldr r2, [r6, #0xc] */
/* @0x20c164 sub r2, r2, #1 */
/* @0x20c168 bic r2, r2, #-16777216 */
/* @0x20c16c bic r2, r2, #3 */
/* @0x20c170 cmp r2, #0 */
/* @0x20c174 beq 0x20c310 <_ZN8CDS_Grid5ClearEP6RValue+0x1f0> */
/* @0x20c178 str r11, [r6, #0x8] */
/* @0x20c17c mov r3, #5 */
/* @0x20c180 str r3, [r6, #0xc] */
/* @0x20c184 str r11, [r7, r8, lsl #4] */
/* @0x20c188 ldm r5, {r7, r8} */
/* @0x20c18c mla r8, r8, r4, r10 */
/* @0x20c190 add r6, r7, r8, lsl #4 */
/* @0x20c194 ldr r1, [r6, #0xc] */
/* @0x20c198 bic r2, r1, #-16777216 */
/* @0x20c19c cmp r2, #1 */
/* @0x20c1a0 beq 0x20c2d8 <_ZN8CDS_Grid5ClearEP6RValue+0x1b8> */
/* @0x20c1a4 cmp r2, #2 */
/* @0x20c1a8 bne 0x20c1cc <_ZN8CDS_Grid5ClearEP6RValue+0xac> */
/* @0x20c1ac sub r1, r1, #1 */
/* @0x20c1b0 bic r1, r1, #-16777216 */
/* @0x20c1b4 bic r1, r1, #3 */
/* @0x20c1b8 cmp r1, #0 */
/* @0x20c1bc beq 0x20c3b0 <_ZN8CDS_Grid5ClearEP6RValue+0x290> */
/* @0x20c1c0 mov r3, #5 */
/* @0x20c1c4 str r11, [r6, #0x8] */
/* @0x20c1c8 str r3, [r6, #0xc] */
/* @0x20c1cc ldr r2, [r9, #0xc] */
/* @0x20c1d0 ldr r1, [r9, #0x8] */
/* @0x20c1d4 str r11, [r7, r8, lsl #4] */
/* @0x20c1d8 str r2, [r6, #0xc] */
/* @0x20c1dc ldr r2, [r9, #0xc] */
/* @0x20c1e0 str r1, [r6, #0x8] */
/* @0x20c1e4 bic r2, r2, #-16777216 */
/* @0x20c1e8 cmp r2, #14 */
/* @0x20c1ec addls pc, pc, r2, lsl #2 */
/* @0x20c1f0 b 0x20c238 <_ZN8CDS_Grid5ClearEP6RValue+0x118> */
/* @0x20c1f4 b 0x20c260 <_ZN8CDS_Grid5ClearEP6RValue+0x140> */
/* @0x20c1f8 b 0x20c29c <_ZN8CDS_Grid5ClearEP6RValue+0x17c> */
/* @0x20c1fc b 0x20c270 <_ZN8CDS_Grid5ClearEP6RValue+0x150> */
/* @0x20c200 b 0x20c230 <_ZN8CDS_Grid5ClearEP6RValue+0x110> */
/* @0x20c204 b 0x20c238 <_ZN8CDS_Grid5ClearEP6RValue+0x118> */
/* @0x20c208 b 0x20c238 <_ZN8CDS_Grid5ClearEP6RValue+0x118> */
/* @0x20c20c b 0x20c2b4 <_ZN8CDS_Grid5ClearEP6RValue+0x194> */
/* @0x20c210 b 0x20c230 <_ZN8CDS_Grid5ClearEP6RValue+0x110> */
/* @0x20c214 b 0x20c238 <_ZN8CDS_Grid5ClearEP6RValue+0x118> */
/* @0x20c218 b 0x20c238 <_ZN8CDS_Grid5ClearEP6RValue+0x118> */
/* @0x20c21c b 0x20c260 <_ZN8CDS_Grid5ClearEP6RValue+0x140> */
/* @0x20c220 b 0x20c238 <_ZN8CDS_Grid5ClearEP6RValue+0x118> */
/* @0x20c224 b 0x20c238 <_ZN8CDS_Grid5ClearEP6RValue+0x118> */
/* @0x20c228 b 0x20c260 <_ZN8CDS_Grid5ClearEP6RValue+0x140> */
/* @0x20c22c b 0x20c230 <_ZN8CDS_Grid5ClearEP6RValue+0x110> */
/* @0x20c230 ldr r2, [r9] */
/* @0x20c234 str r2, [r7, r8, lsl #4] */
/* @0x20c238 ldr r2, [r5, #0x8] */
/* @0x20c23c add r4, r4, #1 */
/* @0x20c240 ldr r8, [r5, #0x4] */
/* @0x20c244 cmp r2, r4 */
/* @0x20c248 bgt 0x20c154 <_ZN8CDS_Grid5ClearEP6RValue+0x34> */
/* @0x20c24c add r10, r10, #1 */
/* @0x20c250 cmp r10, r8 */
/* @0x20c254 blt 0x20c148 <_ZN8CDS_Grid5ClearEP6RValue+0x28> */
/* @0x20c258 add sp, sp, #12 */
/* @0x20c25c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x20c260 ldm r9, {r1, r2} */
/* @0x20c264 str r1, [r7, r8, lsl #4] */
/* @0x20c268 str r2, [r6, #0x4] */
/* @0x20c26c b 0x20c238 <_ZN8CDS_Grid5ClearEP6RValue+0x118> */
/* @0x20c270 ldr r2, [r9] */
/* @0x20c274 cmp r2, #0 */
/* @0x20c278 str r2, [r7, r8, lsl #4] */
/* @0x20c27c beq 0x20c238 <_ZN8CDS_Grid5ClearEP6RValue+0x118> */
/* @0x20c280 ldr r0, [r2, #0x8] */
/* @0x20c284 ldr r1, [r2] */
/* @0x20c288 cmp r0, #0 */
/* @0x20c28c streq r6, [r2, #0x8] */
/* @0x20c290 add r1, r1, #1 */
/* @0x20c294 str r1, [r2] */
/* @0x20c298 b 0x20c238 <_ZN8CDS_Grid5ClearEP6RValue+0x118> */
/* @0x20c29c ldr r2, [r9] */
/* @0x20c2a0 cmp r2, #0 */
/* @0x20c2a4 ldrne r1, [r2, #0x4] */
/* @0x20c2a8 addne r1, r1, #1 */
/* @0x20c2ac strne r1, [r2, #0x4] */
/* @0x20c2b0 b 0x20c234 <_ZN8CDS_Grid5ClearEP6RValue+0x114> */
/* @0x20c2b4 ldr r2, [r9] */
/* @0x20c2b8 str r2, [r7, r8, lsl #4] */
/* @0x20c2bc ldr r2, [r9] */
/* @0x20c2c0 cmp r2, #0 */
/* @0x20c2c4 beq 0x20c238 <_ZN8CDS_Grid5ClearEP6RValue+0x118> */
/* @0x20c2c8 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x20c2cc ldr r1, [r9] */
/* @0x20c2d0 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x20c2d4 b 0x20c238 <_ZN8CDS_Grid5ClearEP6RValue+0x118> */
/* @0x20c2d8 ldr r2, [r7, r8, lsl #4] */
/* @0x20c2dc cmp r2, #0 */
/* @0x20c2e0 beq 0x20c308 <_ZN8CDS_Grid5ClearEP6RValue+0x1e8> */
/* @0x20c2e4 str r2, [sp] */
/* @0x20c2e8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20c2ec ldr r2, [sp] */
/* @0x20c2f0 ldr r1, [r2, #0x4] */
/* @0x20c2f4 sub r1, r1, #1 */
/* @0x20c2f8 str r1, [r2, #0x4] */
/* @0x20c2fc cmp r1, #0 */
/* @0x20c300 beq 0x20c31c <_ZN8CDS_Grid5ClearEP6RValue+0x1fc> */
/* @0x20c304 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20c308 str r11, [r7, r8, lsl #4] */
/* @0x20c30c b 0x20c1cc <_ZN8CDS_Grid5ClearEP6RValue+0xac> */
/* @0x20c310 mov r0, r6 */
/* @0x20c314 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20c318 b 0x20c178 <_ZN8CDS_Grid5ClearEP6RValue+0x58> */
/* @0x20c31c ldr r0, [r2] */
/* @0x20c320 str r1, [sp, #0x4] */
/* @0x20c324 str r2, [sp] */
/* @0x20c328 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20c32c ldr r2, [sp] */
/* @0x20c330 ldr r1, [sp, #0x4] */
/* @0x20c334 str r1, [r2] */
/* @0x20c338 str r1, [r2, #0x8] */
/* @0x20c33c str r2, [sp] */
/* @0x20c340 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20c344 ldr r2, [sp] */
/* @0x20c348 ldr r1, [r2, #0x4] */
/* @0x20c34c sub r1, r1, #1 */
/* @0x20c350 str r1, [r2, #0x4] */
/* @0x20c354 cmp r1, #0 */
/* @0x20c358 bne 0x20c398 <_ZN8CDS_Grid5ClearEP6RValue+0x278> */
/* @0x20c35c ldr r0, [r2] */
/* @0x20c360 str r1, [sp, #0x4] */
/* @0x20c364 str r2, [sp] */
/* @0x20c368 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20c36c ldr r2, [sp] */
/* @0x20c370 ldr r1, [sp, #0x4] */
/* @0x20c374 mov r0, r2 */
/* @0x20c378 str r1, [r2] */
/* @0x20c37c str r1, [r2, #0x8] */
/* @0x20c380 str r2, [sp] */
/* @0x20c384 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x20c388 ldr r2, [sp] */
/* @0x20c38c mov r0, r2 */
/* @0x20c390 bl 0x27d1d0 <_ZdlPv> */
/* @0x20c394 ldr r2, [sp] */
/* @0x20c398 str r2, [sp] */
/* @0x20c39c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20c3a0 ldr r2, [sp] */
/* @0x20c3a4 mov r0, r2 */
/* @0x20c3a8 bl 0x27d1d0 <_ZdlPv> */
/* @0x20c3ac b 0x20c304 <_ZN8CDS_Grid5ClearEP6RValue+0x1e4> */
/* @0x20c3b0 mov r0, r6 */
/* @0x20c3b4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20c3b8 b 0x20c1c0 <_ZN8CDS_Grid5ClearEP6RValue+0xa0> */

/* ── FUNC 0x20c3bc · CDS_Grid::Resize(int, int) · size=1216 · insn=304 */
/* @0x20c3bc ldr r12, [r0] */
/* @0x20c3c0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x20c3c4 sub sp, sp, #52 */
/* @0x20c3c8 mov r4, #0 */
/* @0x20c3cc ldr r6, [r0, #0x4] */
/* @0x20c3d0 str r12, [sp, #0x2c] */
/* @0x20c3d4 mov r8, r1 */
/* @0x20c3d8 ldr r12, [r0, #0x8] */
/* @0x20c3dc str r4, [r0] */
/* @0x20c3e0 str r4, [r0, #0x4] */
/* @0x20c3e4 str r4, [r0, #0x8] */
/* @0x20c3e8 str r12, [sp, #0x24] */
/* @0x20c3ec str r2, [sp, #0x20] */
/* @0x20c3f0 str r0, [sp, #0x8] */
/* @0x20c3f4 bl 0x20affc <_ZN8CDS_Grid7SetSizeEii> */
/* @0x20c3f8 ldr r12, [sp, #0x20] */
/* @0x20c3fc ldr r3, [sp, #0x8] */
/* @0x20c400 cmp r12, r4 */
/* @0x20c404 ble 0x20c640 <_ZN8CDS_Grid6ResizeEii+0x284> */
/* @0x20c408 lsl r2, r6, #4 */
/* @0x20c40c str r2, [sp, #0x28] */
/* @0x20c410 ldr r2, [sp, #0x2c] */
/* @0x20c414 mov r12, r4 */
/* @0x20c418 mov r11, r3 */
/* @0x20c41c str r4, [sp, #0x18] */
/* @0x20c420 add r2, r2, #12 */
/* @0x20c424 str r6, [sp, #0x14] */
/* @0x20c428 str r2, [sp, #0x1c] */
/* @0x20c42c cmp r8, #0 */
/* @0x20c430 ble 0x20c610 <_ZN8CDS_Grid6ResizeEii+0x254> */
/* @0x20c434 ldr r2, [sp, #0x24] */
/* @0x20c438 mov r4, #0 */
/* @0x20c43c ldr r1, [sp, #0x18] */
/* @0x20c440 cmp r2, r1 */
/* @0x20c444 ldr r2, [sp, #0x1c] */
/* @0x20c448 movle r3, #0 */
/* @0x20c44c movgt r3, #1 */
/* @0x20c450 sub r5, r2, #12 */
/* @0x20c454 mov r6, r2 */
/* @0x20c458 mov r2, r8 */
/* @0x20c45c mov r8, r3 */
/* @0x20c460 mov r3, r2 */
/* @0x20c464 b 0x20c47c <_ZN8CDS_Grid6ResizeEii+0xc0> */
/* @0x20c468 add r4, r4, #1 */
/* @0x20c46c add r6, r6, #16 */
/* @0x20c470 cmp r4, r3 */
/* @0x20c474 add r5, r5, #16 */
/* @0x20c478 beq 0x20c60c <_ZN8CDS_Grid6ResizeEii+0x250> */
/* @0x20c47c ldr r1, [sp, #0x14] */
/* @0x20c480 cmp r4, r1 */
/* @0x20c484 movge r2, #0 */
/* @0x20c488 andlt r2, r8, #1 */
/* @0x20c48c cmp r2, #0 */
/* @0x20c490 beq 0x20c468 <_ZN8CDS_Grid6ResizeEii+0xac> */
/* @0x20c494 ldm r11, {r9, r10} */
/* @0x20c498 ldr r2, [sp, #0x18] */
/* @0x20c49c mla r10, r10, r2, r4 */
/* @0x20c4a0 add r7, r9, r10, lsl #4 */
/* @0x20c4a4 ldr r2, [r7, #0xc] */
/* @0x20c4a8 sub r2, r2, #1 */
/* @0x20c4ac bic r2, r2, #-16777216 */
/* @0x20c4b0 bic r2, r2, #3 */
/* @0x20c4b4 cmp r2, #0 */
/* @0x20c4b8 beq 0x20c774 <_ZN8CDS_Grid6ResizeEii+0x3b8> */
/* @0x20c4bc str r12, [r7, #0x8] */
/* @0x20c4c0 mov r1, #5 */
/* @0x20c4c4 ldr r2, [sp, #0x18] */
/* @0x20c4c8 str r1, [r7, #0xc] */
/* @0x20c4cc str r12, [r9, r10, lsl #4] */
/* @0x20c4d0 ldm r11, {r9, r10} */
/* @0x20c4d4 mla r10, r10, r2, r4 */
/* @0x20c4d8 add r7, r9, r10, lsl #4 */
/* @0x20c4dc ldr r1, [r7, #0xc] */
/* @0x20c4e0 bic r2, r1, #-16777216 */
/* @0x20c4e4 cmp r2, #1 */
/* @0x20c4e8 beq 0x20c71c <_ZN8CDS_Grid6ResizeEii+0x360> */
/* @0x20c4ec cmp r2, #2 */
/* @0x20c4f0 bne 0x20c514 <_ZN8CDS_Grid6ResizeEii+0x158> */
/* @0x20c4f4 sub r1, r1, #1 */
/* @0x20c4f8 bic r1, r1, #-16777216 */
/* @0x20c4fc bic r1, r1, #3 */
/* @0x20c500 cmp r1, #0 */
/* @0x20c504 beq 0x20c860 <_ZN8CDS_Grid6ResizeEii+0x4a4> */
/* @0x20c508 mov r1, #5 */
/* @0x20c50c str r12, [r7, #0x8] */
/* @0x20c510 str r1, [r7, #0xc] */
/* @0x20c514 str r12, [r9, r10, lsl #4] */
/* @0x20c518 ldr r2, [r5, #0xc] */
/* @0x20c51c str r2, [r7, #0xc] */
/* @0x20c520 ldr r2, [r5, #0x8] */
/* @0x20c524 str r2, [r7, #0x8] */
/* @0x20c528 ldr r2, [r5, #0xc] */
/* @0x20c52c bic r2, r2, #-16777216 */
/* @0x20c530 cmp r2, #14 */
/* @0x20c534 addls pc, pc, r2, lsl #2 */
/* @0x20c538 b 0x20c468 <_ZN8CDS_Grid6ResizeEii+0xac> */
/* @0x20c53c b 0x20c584 <_ZN8CDS_Grid6ResizeEii+0x1c8> */
/* @0x20c540 b 0x20c5f4 <_ZN8CDS_Grid6ResizeEii+0x238> */
/* @0x20c544 b 0x20c5c8 <_ZN8CDS_Grid6ResizeEii+0x20c> */
/* @0x20c548 b 0x20c578 <_ZN8CDS_Grid6ResizeEii+0x1bc> */
/* @0x20c54c b 0x20c468 <_ZN8CDS_Grid6ResizeEii+0xac> */
/* @0x20c550 b 0x20c468 <_ZN8CDS_Grid6ResizeEii+0xac> */
/* @0x20c554 b 0x20c594 <_ZN8CDS_Grid6ResizeEii+0x1d8> */
/* @0x20c558 b 0x20c578 <_ZN8CDS_Grid6ResizeEii+0x1bc> */
/* @0x20c55c b 0x20c468 <_ZN8CDS_Grid6ResizeEii+0xac> */
/* @0x20c560 b 0x20c468 <_ZN8CDS_Grid6ResizeEii+0xac> */
/* @0x20c564 b 0x20c584 <_ZN8CDS_Grid6ResizeEii+0x1c8> */
/* @0x20c568 b 0x20c468 <_ZN8CDS_Grid6ResizeEii+0xac> */
/* @0x20c56c b 0x20c468 <_ZN8CDS_Grid6ResizeEii+0xac> */
/* @0x20c570 b 0x20c584 <_ZN8CDS_Grid6ResizeEii+0x1c8> */
/* @0x20c574 b 0x20c578 <_ZN8CDS_Grid6ResizeEii+0x1bc> */
/* @0x20c578 ldr r2, [r6, #-0xc] */
/* @0x20c57c str r2, [r9, r10, lsl #4] */
/* @0x20c580 b 0x20c468 <_ZN8CDS_Grid6ResizeEii+0xac> */
/* @0x20c584 ldm r5, {r1, r2} */
/* @0x20c588 str r1, [r9, r10, lsl #4] */
/* @0x20c58c str r2, [r7, #0x4] */
/* @0x20c590 b 0x20c468 <_ZN8CDS_Grid6ResizeEii+0xac> */
/* @0x20c594 ldr r2, [r6, #-0xc] */
/* @0x20c598 str r2, [r9, r10, lsl #4] */
/* @0x20c59c ldr r2, [r6, #-0xc] */
/* @0x20c5a0 cmp r2, #0 */
/* @0x20c5a4 beq 0x20c468 <_ZN8CDS_Grid6ResizeEii+0xac> */
/* @0x20c5a8 str r3, [sp, #0x8] */
/* @0x20c5ac str r12, [sp, #0x4] */
/* @0x20c5b0 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x20c5b4 ldr r1, [r6, #-0xc] */
/* @0x20c5b8 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x20c5bc ldr r3, [sp, #0x8] */
/* @0x20c5c0 ldr r12, [sp, #0x4] */
/* @0x20c5c4 b 0x20c468 <_ZN8CDS_Grid6ResizeEii+0xac> */
/* @0x20c5c8 ldr r2, [r6, #-0xc] */
/* @0x20c5cc cmp r2, #0 */
/* @0x20c5d0 str r2, [r9, r10, lsl #4] */
/* @0x20c5d4 beq 0x20c468 <_ZN8CDS_Grid6ResizeEii+0xac> */
/* @0x20c5d8 ldr r0, [r2, #0x8] */
/* @0x20c5dc ldr r1, [r2] */
/* @0x20c5e0 cmp r0, #0 */
/* @0x20c5e4 streq r7, [r2, #0x8] */
/* @0x20c5e8 add r1, r1, #1 */
/* @0x20c5ec str r1, [r2] */
/* @0x20c5f0 b 0x20c468 <_ZN8CDS_Grid6ResizeEii+0xac> */
/* @0x20c5f4 ldr r2, [r6, #-0xc] */
/* @0x20c5f8 cmp r2, #0 */
/* @0x20c5fc ldrne r1, [r2, #0x4] */
/* @0x20c600 addne r1, r1, #1 */
/* @0x20c604 strne r1, [r2, #0x4] */
/* @0x20c608 b 0x20c57c <_ZN8CDS_Grid6ResizeEii+0x1c0> */
/* @0x20c60c mov r8, r3 */
/* @0x20c610 ldr r2, [sp, #0x18] */
/* @0x20c614 ldr r3, [sp, #0x1c] */
/* @0x20c618 add r2, r2, #1 */
/* @0x20c61c str r2, [sp, #0x18] */
/* @0x20c620 ldr r2, [sp, #0x28] */
/* @0x20c624 ldr r1, [sp, #0x20] */
/* @0x20c628 add r3, r3, r2 */
/* @0x20c62c str r3, [sp, #0x1c] */
/* @0x20c630 ldr r3, [sp, #0x18] */
/* @0x20c634 cmp r3, r1 */
/* @0x20c638 bne 0x20c42c <_ZN8CDS_Grid6ResizeEii+0x70> */
/* @0x20c63c ldr r6, [sp, #0x14] */
/* @0x20c640 ldr r3, [sp, #0x24] */
/* @0x20c644 cmp r3, #0 */
/* @0x20c648 ble 0x20c70c <_ZN8CDS_Grid6ResizeEii+0x350> */
/* @0x20c64c mov r10, #0 */
/* @0x20c650 ldr r3, [sp, #0x2c] */
/* @0x20c654 mov r11, r10 */
/* @0x20c658 mov r1, r10 */
/* @0x20c65c ldr r10, [sp, #0x24] */
/* @0x20c660 mov r2, r8 */
/* @0x20c664 mov r9, #5 */
/* @0x20c668 mov r8, r3 */
/* @0x20c66c lsl r12, r6, #4 */
/* @0x20c670 str r12, [sp, #0x14] */
/* @0x20c674 cmp r6, #0 */
/* @0x20c678 ble 0x20c6f8 <_ZN8CDS_Grid6ResizeEii+0x33c> */
/* @0x20c67c ldr r12, [sp, #0x20] */
/* @0x20c680 mov r5, r8 */
/* @0x20c684 mov r4, #0 */
/* @0x20c688 cmp r12, r1 */
/* @0x20c68c mov r12, r8 */
/* @0x20c690 mov r8, r2 */
/* @0x20c694 movle r7, #0 */
/* @0x20c698 movgt r7, #1 */
/* @0x20c69c cmp r4, r8 */
/* @0x20c6a0 movge r3, #0 */
/* @0x20c6a4 andlt r3, r7, #1 */
/* @0x20c6a8 cmp r3, #0 */
/* @0x20c6ac beq 0x20c6e0 <_ZN8CDS_Grid6ResizeEii+0x324> */
/* @0x20c6b0 cmp r4, r10 */
/* @0x20c6b4 cmplt r1, r6 */
/* @0x20c6b8 bge 0x20c6e0 <_ZN8CDS_Grid6ResizeEii+0x324> */
/* @0x20c6bc ldr r3, [r5, #0xc] */
/* @0x20c6c0 sub r3, r3, #1 */
/* @0x20c6c4 bic r3, r3, #-16777216 */
/* @0x20c6c8 bic r3, r3, #3 */
/* @0x20c6cc cmp r3, #0 */
/* @0x20c6d0 beq 0x20c790 <_ZN8CDS_Grid6ResizeEii+0x3d4> */
/* @0x20c6d4 str r11, [r5, #0x8] */
/* @0x20c6d8 str r9, [r5, #0xc] */
/* @0x20c6dc str r11, [r5] */
/* @0x20c6e0 add r4, r4, #1 */
/* @0x20c6e4 add r5, r5, #16 */
/* @0x20c6e8 cmp r4, r6 */
/* @0x20c6ec bne 0x20c69c <_ZN8CDS_Grid6ResizeEii+0x2e0> */
/* @0x20c6f0 mov r2, r8 */
/* @0x20c6f4 mov r8, r12 */
/* @0x20c6f8 add r1, r1, #1 */
/* @0x20c6fc ldr r3, [sp, #0x14] */
/* @0x20c700 cmp r1, r10 */
/* @0x20c704 add r8, r8, r3 */
/* @0x20c708 bne 0x20c674 <_ZN8CDS_Grid6ResizeEii+0x2b8> */
/* @0x20c70c ldr r0, [sp, #0x2c] */
/* @0x20c710 add sp, sp, #52 */
/* @0x20c714 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x20c718 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x20c71c ldr r2, [r9, r10, lsl #4] */
/* @0x20c720 cmp r2, #0 */
/* @0x20c724 beq 0x20c76c <_ZN8CDS_Grid6ResizeEii+0x3b0> */
/* @0x20c728 str r2, [sp, #0xc] */
/* @0x20c72c str r3, [sp, #0x8] */
/* @0x20c730 str r12, [sp, #0x4] */
/* @0x20c734 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20c738 ldr r2, [sp, #0xc] */
/* @0x20c73c ldr r3, [sp, #0x8] */
/* @0x20c740 ldr r12, [sp, #0x4] */
/* @0x20c744 ldr r1, [r2, #0x4] */
/* @0x20c748 sub r1, r1, #1 */
/* @0x20c74c str r1, [r2, #0x4] */
/* @0x20c750 cmp r1, #0 */
/* @0x20c754 beq 0x20c7ac <_ZN8CDS_Grid6ResizeEii+0x3f0> */
/* @0x20c758 str r3, [sp, #0x8] */
/* @0x20c75c str r12, [sp, #0x4] */
/* @0x20c760 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20c764 ldr r12, [sp, #0x4] */
/* @0x20c768 ldr r3, [sp, #0x8] */
/* @0x20c76c str r12, [r9, r10, lsl #4] */
/* @0x20c770 b 0x20c514 <_ZN8CDS_Grid6ResizeEii+0x158> */
/* @0x20c774 mov r0, r7 */
/* @0x20c778 str r3, [sp, #0x8] */
/* @0x20c77c str r12, [sp, #0x4] */
/* @0x20c780 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20c784 ldr r12, [sp, #0x4] */
/* @0x20c788 ldr r3, [sp, #0x8] */
/* @0x20c78c b 0x20c4bc <_ZN8CDS_Grid6ResizeEii+0x100> */
/* @0x20c790 mov r0, r5 */
/* @0x20c794 str r1, [sp, #0x10] */
/* @0x20c798 str r12, [sp, #0x4] */
/* @0x20c79c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20c7a0 ldr r12, [sp, #0x4] */
/* @0x20c7a4 ldr r1, [sp, #0x10] */
/* @0x20c7a8 b 0x20c6d4 <_ZN8CDS_Grid6ResizeEii+0x318> */
/* @0x20c7ac ldr r0, [r2] */
/* @0x20c7b0 str r1, [sp, #0x10] */
/* @0x20c7b4 str r2, [sp, #0xc] */
/* @0x20c7b8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20c7bc ldr r2, [sp, #0xc] */
/* @0x20c7c0 ldr r1, [sp, #0x10] */
/* @0x20c7c4 str r1, [r2] */
/* @0x20c7c8 str r1, [r2, #0x8] */
/* @0x20c7cc str r2, [sp, #0xc] */
/* @0x20c7d0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20c7d4 ldr r2, [sp, #0xc] */
/* @0x20c7d8 ldr r3, [sp, #0x8] */
/* @0x20c7dc ldr r12, [sp, #0x4] */
/* @0x20c7e0 ldr r1, [r2, #0x4] */
/* @0x20c7e4 sub r1, r1, #1 */
/* @0x20c7e8 str r1, [r2, #0x4] */
/* @0x20c7ec cmp r1, #0 */
/* @0x20c7f0 bne 0x20c838 <_ZN8CDS_Grid6ResizeEii+0x47c> */
/* @0x20c7f4 ldr r0, [r2] */
/* @0x20c7f8 str r1, [sp, #0x10] */
/* @0x20c7fc str r2, [sp, #0xc] */
/* @0x20c800 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20c804 ldr r2, [sp, #0xc] */
/* @0x20c808 ldr r1, [sp, #0x10] */
/* @0x20c80c mov r0, r2 */
/* @0x20c810 str r1, [r2] */
/* @0x20c814 str r1, [r2, #0x8] */
/* @0x20c818 str r2, [sp, #0xc] */
/* @0x20c81c bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x20c820 ldr r2, [sp, #0xc] */
/* @0x20c824 mov r0, r2 */
/* @0x20c828 bl 0x27d1d0 <_ZdlPv> */
/* @0x20c82c ldr r12, [sp, #0x4] */
/* @0x20c830 ldr r3, [sp, #0x8] */
/* @0x20c834 ldr r2, [sp, #0xc] */
/* @0x20c838 str r3, [sp, #0x8] */
/* @0x20c83c str r12, [sp, #0x4] */
/* @0x20c840 str r2, [sp, #0xc] */
/* @0x20c844 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20c848 ldr r2, [sp, #0xc] */
/* @0x20c84c mov r0, r2 */
/* @0x20c850 bl 0x27d1d0 <_ZdlPv> */
/* @0x20c854 ldr r12, [sp, #0x4] */
/* @0x20c858 ldr r3, [sp, #0x8] */
/* @0x20c85c b 0x20c758 <_ZN8CDS_Grid6ResizeEii+0x39c> */
/* @0x20c860 mov r0, r7 */
/* @0x20c864 str r3, [sp, #0x8] */
/* @0x20c868 str r12, [sp, #0x4] */
/* @0x20c86c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20c870 ldr r12, [sp, #0x4] */
/* @0x20c874 ldr r3, [sp, #0x8] */
/* @0x20c878 b 0x20c508 <_ZN8CDS_Grid6ResizeEii+0x14c> */

/* ── FUNC 0x20c87c · CDS_Map::Assign(CDS_Map*) · size=1308 · insn=327 */
/* @0x20c87c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x20c880 sub sp, sp, #28 */
/* @0x20c884 ldr r10, [r0] */
/* @0x20c888 str r0, [sp, #0x4] */
/* @0x20c88c str r1, [sp] */
/* @0x20c890 ldr r9, [r10, #0x4] */
/* @0x20c894 cmp r9, #0 */
/* @0x20c898 lslge r7, r9, #3 */
/* @0x20c89c movge r6, #0 */
/* @0x20c8a0 movge r8, #5 */
/* @0x20c8a4 blt 0x20c95c <_ZN7CDS_Map6AssignEPS_+0xe0> */
/* @0x20c8a8 ldr r3, [r10] */
/* @0x20c8ac add r2, r3, r7 */
/* @0x20c8b0 ldr r4, [r3, r7] */
/* @0x20c8b4 str r6, [r3, r7] */
/* @0x20c8b8 cmp r4, #0 */
/* @0x20c8bc str r6, [r2, #0x4] */
/* @0x20c8c0 beq 0x20c94c <_ZN7CDS_Map6AssignEPS_+0xd0> */
/* @0x20c8c4 ldr r5, [r4, #0xc] */
/* @0x20c8c8 ldr r11, [r4, #0x4] */
/* @0x20c8cc cmp r5, #0 */
/* @0x20c8d0 beq 0x20c92c <_ZN7CDS_Map6AssignEPS_+0xb0> */
/* @0x20c8d4 ldr r3, [r5, #0xc] */
/* @0x20c8d8 sub r3, r3, #1 */
/* @0x20c8dc bic r3, r3, #-16777216 */
/* @0x20c8e0 bic r3, r3, #3 */
/* @0x20c8e4 cmp r3, #0 */
/* @0x20c8e8 beq 0x20ccf0 <_ZN7CDS_Map6AssignEPS_+0x474> */
/* @0x20c8ec ldr r3, [r5, #0x1c] */
/* @0x20c8f0 str r6, [r5, #0x8] */
/* @0x20c8f4 sub r3, r3, #1 */
/* @0x20c8f8 str r8, [r5, #0xc] */
/* @0x20c8fc bic r3, r3, #-16777216 */
/* @0x20c900 str r6, [r5] */
/* @0x20c904 bic r3, r3, #3 */
/* @0x20c908 cmp r3, #0 */
/* @0x20c90c bne 0x20c918 <_ZN7CDS_Map6AssignEPS_+0x9c> */
/* @0x20c910 add r0, r5, #16 */
/* @0x20c914 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20c918 str r6, [r5, #0x18] */
/* @0x20c91c mov r0, r5 */
/* @0x20c920 str r8, [r5, #0x1c] */
/* @0x20c924 str r6, [r5, #0x10] */
/* @0x20c928 bl 0x27d1d0 <_ZdlPv> */
/* @0x20c92c mov r0, r4 */
/* @0x20c930 mov r4, r11 */
/* @0x20c934 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x20c938 ldr r3, [r10, #0x8] */
/* @0x20c93c cmp r11, #0 */
/* @0x20c940 sub r3, r3, #1 */
/* @0x20c944 str r3, [r10, #0x8] */
/* @0x20c948 bne 0x20c8c4 <_ZN7CDS_Map6AssignEPS_+0x48> */
/* @0x20c94c sub r9, r9, #1 */
/* @0x20c950 sub r7, r7, #8 */
/* @0x20c954 cmn r9, #1 */
/* @0x20c958 bne 0x20c8a8 <_ZN7CDS_Map6AssignEPS_+0x2c> */
/* @0x20c95c ldr r2, [sp] */
/* @0x20c960 mov r6, #0 */
/* @0x20c964 ldr r11, [r2] */
/* @0x20c968 ldr r2, [r11] */
/* @0x20c96c b 0x20c980 <_ZN7CDS_Map6AssignEPS_+0x104> */
/* @0x20c970 ldr r3, [r11, #0x4] */
/* @0x20c974 add r6, r6, #1 */
/* @0x20c978 cmp r6, r3 */
/* @0x20c97c bgt 0x20cd8c <_ZN7CDS_Map6AssignEPS_+0x510> */
/* @0x20c980 ldr r5, [r2, r6, lsl #3] */
/* @0x20c984 cmp r5, #0 */
/* @0x20c988 beq 0x20c970 <_ZN7CDS_Map6AssignEPS_+0xf4> */
/* @0x20c98c ldr r0, [pc, #0x400] */
/* @0x20c990 mov r8, #0 */
/* @0x20c994 add r3, sp, #16 */
/* @0x20c998 str r11, [sp, #0x8] */
/* @0x20c99c add r0, pc, r0 */
/* @0x20c9a0 str r3, [sp, #0xc] */
/* @0x20c9a4 str r0, [sp] */
/* @0x20c9a8 cmp r5, #0 */
/* @0x20c9ac beq 0x20cbf8 <_ZN7CDS_Map6AssignEPS_+0x37c> */
/* @0x20c9b0 ldr r9, [r5, #0xc] */
/* @0x20c9b4 cmp r9, #0 */
/* @0x20c9b8 beq 0x20cbf8 <_ZN7CDS_Map6AssignEPS_+0x37c> */
/* @0x20c9bc ldr r3, [r9, #0xc] */
/* @0x20c9c0 bic r3, r3, #-16777216 */
/* @0x20c9c4 cmp r3, #6 */
/* @0x20c9c8 beq 0x20cd6c <_ZN7CDS_Map6AssignEPS_+0x4f0> */
/* @0x20c9cc bgt 0x20ccfc <_ZN7CDS_Map6AssignEPS_+0x480> */
/* @0x20c9d0 cmp r3, #4 */
/* @0x20c9d4 bgt 0x20cd14 <_ZN7CDS_Map6AssignEPS_+0x498> */
/* @0x20c9d8 cmp r3, #2 */
/* @0x20c9dc bge 0x20cd6c <_ZN7CDS_Map6AssignEPS_+0x4f0> */
/* @0x20c9e0 cmp r3, #1 */
/* @0x20c9e4 bne 0x20cd40 <_ZN7CDS_Map6AssignEPS_+0x4c4> */
/* @0x20c9e8 ldr r0, [r9] */
/* @0x20c9ec cmp r0, #0 */
/* @0x20c9f0 ldrne r0, [r0] */
/* @0x20c9f4 bl 0x27dfa8 <_Z14CalcCRC_stringPKc> */
/* @0x20c9f8 mov r10, r0 */
/* @0x20c9fc mov r0, #32 */
/* @0x20ca00 bl 0x27c524 <_Znwj> */
/* @0x20ca04 mov r1, #0 */
/* @0x20ca08 mov r2, #16 */
/* @0x20ca0c add r7, r0, #16 */
/* @0x20ca10 mov r4, r0 */
/* @0x20ca14 bl 0xb65b0 <memset@plt> */
/* @0x20ca18 mov r1, #0 */
/* @0x20ca1c mov r0, r7 */
/* @0x20ca20 mov r2, #16 */
/* @0x20ca24 bl 0xb65b0 <memset@plt> */
/* @0x20ca28 ldr r3, [r4, #0xc] */
/* @0x20ca2c sub r3, r3, #1 */
/* @0x20ca30 bic r3, r3, #-16777216 */
/* @0x20ca34 bic r3, r3, #3 */
/* @0x20ca38 cmp r3, #0 */
/* @0x20ca3c beq 0x20cd28 <_ZN7CDS_Map6AssignEPS_+0x4ac> */
/* @0x20ca40 mov r3, #5 */
/* @0x20ca44 str r3, [r4, #0xc] */
/* @0x20ca48 ldr r3, [r9, #0xc] */
/* @0x20ca4c str r8, [r4, #0x8] */
/* @0x20ca50 ldr r2, [r9, #0x8] */
/* @0x20ca54 str r3, [r4, #0xc] */
/* @0x20ca58 ldr r3, [r9, #0xc] */
/* @0x20ca5c str r8, [r4] */
/* @0x20ca60 bic r3, r3, #-16777216 */
/* @0x20ca64 str r2, [r4, #0x8] */
/* @0x20ca68 cmp r3, #14 */
/* @0x20ca6c addls pc, pc, r3, lsl #2 */
/* @0x20ca70 b 0x20cab8 <_ZN7CDS_Map6AssignEPS_+0x23c> */
/* @0x20ca74 b 0x20cc14 <_ZN7CDS_Map6AssignEPS_+0x398> */
/* @0x20ca78 b 0x20cc4c <_ZN7CDS_Map6AssignEPS_+0x3d0> */
/* @0x20ca7c b 0x20cc20 <_ZN7CDS_Map6AssignEPS_+0x3a4> */
/* @0x20ca80 b 0x20cab0 <_ZN7CDS_Map6AssignEPS_+0x234> */
/* @0x20ca84 b 0x20cab8 <_ZN7CDS_Map6AssignEPS_+0x23c> */
/* @0x20ca88 b 0x20cab8 <_ZN7CDS_Map6AssignEPS_+0x23c> */
/* @0x20ca8c b 0x20cc64 <_ZN7CDS_Map6AssignEPS_+0x3e8> */
/* @0x20ca90 b 0x20cab0 <_ZN7CDS_Map6AssignEPS_+0x234> */
/* @0x20ca94 b 0x20cab8 <_ZN7CDS_Map6AssignEPS_+0x23c> */
/* @0x20ca98 b 0x20cab8 <_ZN7CDS_Map6AssignEPS_+0x23c> */
/* @0x20ca9c b 0x20cc14 <_ZN7CDS_Map6AssignEPS_+0x398> */
/* @0x20caa0 b 0x20cab8 <_ZN7CDS_Map6AssignEPS_+0x23c> */
/* @0x20caa4 b 0x20cab8 <_ZN7CDS_Map6AssignEPS_+0x23c> */
/* @0x20caa8 b 0x20cc14 <_ZN7CDS_Map6AssignEPS_+0x398> */
/* @0x20caac b 0x20cab0 <_ZN7CDS_Map6AssignEPS_+0x234> */
/* @0x20cab0 ldr r3, [r9] */
/* @0x20cab4 str r3, [r4] */
/* @0x20cab8 ldr r3, [r4, #0x1c] */
/* @0x20cabc sub r3, r3, #1 */
/* @0x20cac0 bic r3, r3, #-16777216 */
/* @0x20cac4 bic r3, r3, #3 */
/* @0x20cac8 cmp r3, #0 */
/* @0x20cacc beq 0x20cd1c <_ZN7CDS_Map6AssignEPS_+0x4a0> */
/* @0x20cad0 mov r3, #5 */
/* @0x20cad4 str r3, [r4, #0x1c] */
/* @0x20cad8 ldr r3, [r9, #0x1c] */
/* @0x20cadc str r8, [r4, #0x18] */
/* @0x20cae0 ldr r2, [r9, #0x18] */
/* @0x20cae4 str r3, [r4, #0x1c] */
/* @0x20cae8 ldr r3, [r9, #0x1c] */
/* @0x20caec str r8, [r4, #0x10] */
/* @0x20caf0 bic r3, r3, #-16777216 */
/* @0x20caf4 str r2, [r4, #0x18] */
/* @0x20caf8 cmp r3, #14 */
/* @0x20cafc addls pc, pc, r3, lsl #2 */
/* @0x20cb00 b 0x20cb48 <_ZN7CDS_Map6AssignEPS_+0x2cc> */
/* @0x20cb04 b 0x20cc00 <_ZN7CDS_Map6AssignEPS_+0x384> */
/* @0x20cb08 b 0x20ccd8 <_ZN7CDS_Map6AssignEPS_+0x45c> */
/* @0x20cb0c b 0x20ccac <_ZN7CDS_Map6AssignEPS_+0x430> */
/* @0x20cb10 b 0x20cb40 <_ZN7CDS_Map6AssignEPS_+0x2c4> */
/* @0x20cb14 b 0x20cb48 <_ZN7CDS_Map6AssignEPS_+0x2cc> */
/* @0x20cb18 b 0x20cb48 <_ZN7CDS_Map6AssignEPS_+0x2cc> */
/* @0x20cb1c b 0x20cc88 <_ZN7CDS_Map6AssignEPS_+0x40c> */
/* @0x20cb20 b 0x20cb40 <_ZN7CDS_Map6AssignEPS_+0x2c4> */
/* @0x20cb24 b 0x20cb48 <_ZN7CDS_Map6AssignEPS_+0x2cc> */
/* @0x20cb28 b 0x20cb48 <_ZN7CDS_Map6AssignEPS_+0x2cc> */
/* @0x20cb2c b 0x20cc00 <_ZN7CDS_Map6AssignEPS_+0x384> */
/* @0x20cb30 b 0x20cb48 <_ZN7CDS_Map6AssignEPS_+0x2cc> */
/* @0x20cb34 b 0x20cb48 <_ZN7CDS_Map6AssignEPS_+0x2cc> */
/* @0x20cb38 b 0x20cc00 <_ZN7CDS_Map6AssignEPS_+0x384> */
/* @0x20cb3c b 0x20cb40 <_ZN7CDS_Map6AssignEPS_+0x2c4> */
/* @0x20cb40 ldr r3, [r9, #0x10] */
/* @0x20cb44 str r3, [r4, #0x10] */
/* @0x20cb48 ldr r3, [sp, #0x4] */
/* @0x20cb4c movw r2, #0x132 */
/* @0x20cb50 mov r0, #16 */
/* @0x20cb54 ldr r1, [sp] */
/* @0x20cb58 ldr r7, [r3] */
/* @0x20cb5c mov r3, #1 */
/* @0x20cb60 ldm r7, {r9, r12} */
/* @0x20cb64 and r11, r10, r12 */
/* @0x20cb68 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x20cb6c ldr r2, [r9, r11, lsl #3] */
/* @0x20cb70 add r3, r9, r11, lsl #3 */
/* @0x20cb74 cmp r2, #0 */
/* @0x20cb78 ldrne r2, [r3, #0x4] */
/* @0x20cb7c str r10, [r0, #0x8] */
/* @0x20cb80 str r4, [r0, #0xc] */
/* @0x20cb84 strne r2, [r0] */
/* @0x20cb88 streq r0, [r3, #0x4] */
/* @0x20cb8c strne r0, [r2, #0x4] */
/* @0x20cb90 streq r0, [r9, r11, lsl #3] */
/* @0x20cb94 strne r0, [r3, #0x4] */
/* @0x20cb98 streq r2, [r0, #0x4] */
/* @0x20cb9c strne r8, [r0, #0x4] */
/* @0x20cba0 ldr r5, [r5, #0x4] */
/* @0x20cba4 streq r2, [r0] */
/* @0x20cba8 ldr r3, [r7, #0x8] */
/* @0x20cbac cmp r5, #0 */
/* @0x20cbb0 add r3, r3, #1 */
/* @0x20cbb4 str r3, [r7, #0x8] */
/* @0x20cbb8 bne 0x20c9a8 <_ZN7CDS_Map6AssignEPS_+0x12c> */
/* @0x20cbbc ldr r0, [sp, #0x8] */
/* @0x20cbc0 add r3, r6, #1 */
/* @0x20cbc4 ldr r1, [r0, #0x4] */
/* @0x20cbc8 cmp r3, r1 */
/* @0x20cbcc bgt 0x20cbf8 <_ZN7CDS_Map6AssignEPS_+0x37c> */
/* @0x20cbd0 ldr r2, [r0] */
/* @0x20cbd4 add r2, r2, r6, lsl #3 */
/* @0x20cbd8 ldr r5, [r2, #0x8] */
/* @0x20cbdc mov r6, r3 */
/* @0x20cbe0 add r2, r2, #8 */
/* @0x20cbe4 add r3, r3, #1 */
/* @0x20cbe8 cmp r5, #0 */
/* @0x20cbec bne 0x20c9a8 <_ZN7CDS_Map6AssignEPS_+0x12c> */
/* @0x20cbf0 cmp r1, r3 */
/* @0x20cbf4 bge 0x20cbd8 <_ZN7CDS_Map6AssignEPS_+0x35c> */
/* @0x20cbf8 add sp, sp, #28 */
/* @0x20cbfc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x20cc00 ldr r2, [r9, #0x10] */
/* @0x20cc04 ldr r3, [r9, #0x14] */
/* @0x20cc08 str r2, [r4, #0x10] */
/* @0x20cc0c str r3, [r4, #0x14] */
/* @0x20cc10 b 0x20cb48 <_ZN7CDS_Map6AssignEPS_+0x2cc> */
/* @0x20cc14 ldm r9, {r2, r3} */
/* @0x20cc18 stm r4, {r2, r3} */
/* @0x20cc1c b 0x20cab8 <_ZN7CDS_Map6AssignEPS_+0x23c> */
/* @0x20cc20 ldr r3, [r9] */
/* @0x20cc24 cmp r3, #0 */
/* @0x20cc28 str r3, [r4] */
/* @0x20cc2c beq 0x20cab8 <_ZN7CDS_Map6AssignEPS_+0x23c> */
/* @0x20cc30 ldr r1, [r3, #0x8] */
/* @0x20cc34 ldr r2, [r3] */
/* @0x20cc38 cmp r1, #0 */
/* @0x20cc3c streq r4, [r3, #0x8] */
/* @0x20cc40 add r2, r2, #1 */
/* @0x20cc44 str r2, [r3] */
/* @0x20cc48 b 0x20cab8 <_ZN7CDS_Map6AssignEPS_+0x23c> */
/* @0x20cc4c ldr r3, [r9] */
/* @0x20cc50 cmp r3, #0 */
/* @0x20cc54 ldrne r2, [r3, #0x4] */
/* @0x20cc58 addne r2, r2, #1 */
/* @0x20cc5c strne r2, [r3, #0x4] */
/* @0x20cc60 b 0x20cab4 <_ZN7CDS_Map6AssignEPS_+0x238> */
/* @0x20cc64 ldr r3, [r9] */
/* @0x20cc68 str r3, [r4] */
/* @0x20cc6c ldr r3, [r9] */
/* @0x20cc70 cmp r3, #0 */
/* @0x20cc74 beq 0x20cab8 <_ZN7CDS_Map6AssignEPS_+0x23c> */
/* @0x20cc78 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x20cc7c ldr r1, [r9] */
/* @0x20cc80 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x20cc84 b 0x20cab8 <_ZN7CDS_Map6AssignEPS_+0x23c> */
/* @0x20cc88 ldr r3, [r9, #0x10] */
/* @0x20cc8c str r3, [r4, #0x10] */
/* @0x20cc90 ldr r3, [r9, #0x10] */
/* @0x20cc94 cmp r3, #0 */
/* @0x20cc98 beq 0x20cb48 <_ZN7CDS_Map6AssignEPS_+0x2cc> */
/* @0x20cc9c bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x20cca0 ldr r1, [r9, #0x10] */
/* @0x20cca4 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x20cca8 b 0x20cb48 <_ZN7CDS_Map6AssignEPS_+0x2cc> */
/* @0x20ccac ldr r3, [r9, #0x10] */
/* @0x20ccb0 cmp r3, #0 */
/* @0x20ccb4 str r3, [r4, #0x10] */
/* @0x20ccb8 beq 0x20cb48 <_ZN7CDS_Map6AssignEPS_+0x2cc> */
/* @0x20ccbc ldr r1, [r3, #0x8] */
/* @0x20ccc0 ldr r2, [r3] */
/* @0x20ccc4 cmp r1, #0 */
/* @0x20ccc8 streq r7, [r3, #0x8] */
/* @0x20cccc add r2, r2, #1 */
/* @0x20ccd0 str r2, [r3] */
/* @0x20ccd4 b 0x20cb48 <_ZN7CDS_Map6AssignEPS_+0x2cc> */
/* @0x20ccd8 ldr r3, [r9, #0x10] */
/* @0x20ccdc cmp r3, #0 */
/* @0x20cce0 ldrne r2, [r3, #0x4] */
/* @0x20cce4 addne r2, r2, #1 */
/* @0x20cce8 strne r2, [r3, #0x4] */
/* @0x20ccec b 0x20cb44 <_ZN7CDS_Map6AssignEPS_+0x2c8> */
/* @0x20ccf0 mov r0, r5 */
/* @0x20ccf4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20ccf8 b 0x20c8ec <_ZN7CDS_Map6AssignEPS_+0x70> */
/* @0x20ccfc cmp r3, #11 */
/* @0x20cd00 beq 0x20cd6c <_ZN7CDS_Map6AssignEPS_+0x4f0> */
/* @0x20cd04 ble 0x20cd34 <_ZN7CDS_Map6AssignEPS_+0x4b8> */
/* @0x20cd08 mvn r2, #-16777216 */
/* @0x20cd0c cmp r3, r2 */
/* @0x20cd10 bne 0x20cd40 <_ZN7CDS_Map6AssignEPS_+0x4c4> */
/* @0x20cd14 mov r10, #0 */
/* @0x20cd18 b 0x20c9fc <_ZN7CDS_Map6AssignEPS_+0x180> */
/* @0x20cd1c mov r0, r7 */
/* @0x20cd20 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20cd24 b 0x20cad0 <_ZN7CDS_Map6AssignEPS_+0x254> */
/* @0x20cd28 mov r0, r4 */
/* @0x20cd2c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20cd30 b 0x20ca40 <_ZN7CDS_Map6AssignEPS_+0x1c4> */
/* @0x20cd34 sub r2, r3, #8 */
/* @0x20cd38 cmp r2, #1 */
/* @0x20cd3c bls 0x20cd6c <_ZN7CDS_Map6AssignEPS_+0x4f0> */
/* @0x20cd40 cmp r3, #0 */
/* @0x20cd44 bne 0x20cd80 <_ZN7CDS_Map6AssignEPS_+0x504> */
/* @0x20cd48 ldm r9, {r0, r1} */
/* @0x20cd4c mov r2, r0 */
/* @0x20cd50 mov r3, r1 */
/* @0x20cd54 add r0, sp, #16 */
/* @0x20cd58 mov r1, #8 */
/* @0x20cd5c strd r2, r3, [sp, #16] */
/* @0x20cd60 bl 0x27dfa0 <_Z7CalcCRCPKci> */
/* @0x20cd64 mov r10, r0 */
/* @0x20cd68 b 0x20c9fc <_ZN7CDS_Map6AssignEPS_+0x180> */
/* @0x20cd6c mov r0, r9 */
/* @0x20cd70 mov r1, #8 */
/* @0x20cd74 bl 0x27dfa0 <_Z7CalcCRCPKci> */
/* @0x20cd78 mov r10, r0 */
/* @0x20cd7c b 0x20c9fc <_ZN7CDS_Map6AssignEPS_+0x180> */
/* @0x20cd80 mov r0, r9 */
/* @0x20cd84 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x20cd88 b 0x20cd4c <_ZN7CDS_Map6AssignEPS_+0x4d0> */
/* @0x20cd8c mvn r6, #0 */
/* @0x20cd90 b 0x20c98c <_ZN7CDS_Map6AssignEPS_+0x110> */
/* @0x20cd94 andseq r0, r4, r0, lsl r3 */

/* ── FUNC 0x20cd98 · CDS_Grid::Shuffle() · size=2504 · insn=626 */
/* @0x20cd98 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x20cd9c mov r4, r0 */
/* @0x20cda0 ldmib r0, {r0, r2} */
/* @0x20cda4 mov r5, #0 */
/* @0x20cda8 sub sp, sp, #52 */
/* @0x20cdac lsl r3, r0, #3 */
/* @0x20cdb0 str r5, [sp, #0x20] */
/* @0x20cdb4 str r5, [sp, #0x24] */
/* @0x20cdb8 mul r3, r2, r3 */
/* @0x20cdbc str r5, [sp, #0x28] */
/* @0x20cdc0 str r5, [sp, #0x2c] */
/* @0x20cdc4 cmp r3, r5 */
/* @0x20cdc8 ble 0x20d0f8 <_ZN8CDS_Grid7ShuffleEv+0x360> */
/* @0x20cdcc add r2, sp, #32 */
/* @0x20cdd0 mov r3, #1 */
/* @0x20cdd4 str r2, [sp, #0x1c] */
/* @0x20cdd8 str r3, [sp, #0x14] */
/* @0x20cddc bl 0xc4600 <_Z8YYRandomi> */
/* @0x20cde0 mov r10, r0 */
/* @0x20cde4 ldr r0, [r4, #0x4] */
/* @0x20cde8 bl 0xc4600 <_Z8YYRandomi> */
/* @0x20cdec mov r6, r0 */
/* @0x20cdf0 ldr r0, [r4, #0x8] */
/* @0x20cdf4 bl 0xc4600 <_Z8YYRandomi> */
/* @0x20cdf8 mov r8, r0 */
/* @0x20cdfc ldr r0, [r4, #0x8] */
/* @0x20ce00 bl 0xc4600 <_Z8YYRandomi> */
/* @0x20ce04 cmp r10, r6 */
/* @0x20ce08 cmpeq r8, r0 */
/* @0x20ce0c mov r7, r0 */
/* @0x20ce10 beq 0x20d0d0 <_ZN8CDS_Grid7ShuffleEv+0x338> */
/* @0x20ce14 ldr r2, [r4, #0x4] */
/* @0x20ce18 ldr r0, [sp, #0x2c] */
/* @0x20ce1c ldr r11, [r4] */
/* @0x20ce20 mla r2, r2, r8, r10 */
/* @0x20ce24 bic r1, r0, #-16777216 */
/* @0x20ce28 cmp r1, #1 */
/* @0x20ce2c add r9, r11, r2, lsl #4 */
/* @0x20ce30 beq 0x20d2ac <_ZN8CDS_Grid7ShuffleEv+0x514> */
/* @0x20ce34 cmp r1, #2 */
/* @0x20ce38 bne 0x20ce5c <_ZN8CDS_Grid7ShuffleEv+0xc4> */
/* @0x20ce3c sub r0, r0, #1 */
/* @0x20ce40 bic r0, r0, #-16777216 */
/* @0x20ce44 bic r0, r0, #3 */
/* @0x20ce48 cmp r0, #0 */
/* @0x20ce4c beq 0x20d4b8 <_ZN8CDS_Grid7ShuffleEv+0x720> */
/* @0x20ce50 mov r0, #5 */
/* @0x20ce54 str r5, [sp, #0x28] */
/* @0x20ce58 str r0, [sp, #0x2c] */
/* @0x20ce5c ldr r1, [r9, #0xc] */
/* @0x20ce60 ldr r0, [r9, #0x8] */
/* @0x20ce64 str r5, [sp, #0x20] */
/* @0x20ce68 str r1, [sp, #0x2c] */
/* @0x20ce6c ldr r1, [r9, #0xc] */
/* @0x20ce70 str r0, [sp, #0x28] */
/* @0x20ce74 bic r1, r1, #-16777216 */
/* @0x20ce78 cmp r1, #14 */
/* @0x20ce7c addls pc, pc, r1, lsl #2 */
/* @0x20ce80 b 0x20cec8 <_ZN8CDS_Grid7ShuffleEv+0x130> */
/* @0x20ce84 b 0x20d25c <_ZN8CDS_Grid7ShuffleEv+0x4c4> */
/* @0x20ce88 b 0x20d244 <_ZN8CDS_Grid7ShuffleEv+0x4ac> */
/* @0x20ce8c b 0x20d214 <_ZN8CDS_Grid7ShuffleEv+0x47c> */
/* @0x20ce90 b 0x20cec0 <_ZN8CDS_Grid7ShuffleEv+0x128> */
/* @0x20ce94 b 0x20cec8 <_ZN8CDS_Grid7ShuffleEv+0x130> */
/* @0x20ce98 b 0x20cec8 <_ZN8CDS_Grid7ShuffleEv+0x130> */
/* @0x20ce9c b 0x20d280 <_ZN8CDS_Grid7ShuffleEv+0x4e8> */
/* @0x20cea0 b 0x20cec0 <_ZN8CDS_Grid7ShuffleEv+0x128> */
/* @0x20cea4 b 0x20cec8 <_ZN8CDS_Grid7ShuffleEv+0x130> */
/* @0x20cea8 b 0x20cec8 <_ZN8CDS_Grid7ShuffleEv+0x130> */
/* @0x20ceac b 0x20d26c <_ZN8CDS_Grid7ShuffleEv+0x4d4> */
/* @0x20ceb0 b 0x20cec8 <_ZN8CDS_Grid7ShuffleEv+0x130> */
/* @0x20ceb4 b 0x20cec8 <_ZN8CDS_Grid7ShuffleEv+0x130> */
/* @0x20ceb8 b 0x20d25c <_ZN8CDS_Grid7ShuffleEv+0x4c4> */
/* @0x20cebc b 0x20cec0 <_ZN8CDS_Grid7ShuffleEv+0x128> */
/* @0x20cec0 ldr r2, [r11, r2, lsl #4] */
/* @0x20cec4 str r2, [sp, #0x20] */
/* @0x20cec8 ldr r2, [r4, #0x4] */
/* @0x20cecc ldr r9, [r4] */
/* @0x20ced0 mla r1, r2, r8, r10 */
/* @0x20ced4 mla r2, r2, r7, r6 */
/* @0x20ced8 add r11, r9, r1, lsl #4 */
/* @0x20cedc ldr r0, [r11, #0xc] */
/* @0x20cee0 str r2, [sp, #0x18] */
/* @0x20cee4 add r2, r9, r2, lsl #4 */
/* @0x20cee8 sub r0, r0, #1 */
/* @0x20ceec bic r0, r0, #-16777216 */
/* @0x20cef0 bic r0, r0, #3 */
/* @0x20cef4 cmp r0, #0 */
/* @0x20cef8 beq 0x20d378 <_ZN8CDS_Grid7ShuffleEv+0x5e0> */
/* @0x20cefc str r5, [r11, #0x8] */
/* @0x20cf00 mov r3, #5 */
/* @0x20cf04 str r3, [r11, #0xc] */
/* @0x20cf08 str r5, [r9, r1, lsl #4] */
/* @0x20cf0c ldr r1, [r4, #0x4] */
/* @0x20cf10 ldr r11, [r4] */
/* @0x20cf14 mla r3, r1, r8, r10 */
/* @0x20cf18 add r10, r11, r3, lsl #4 */
/* @0x20cf1c ldr r0, [r10, #0xc] */
/* @0x20cf20 bic r1, r0, #-16777216 */
/* @0x20cf24 cmp r1, #1 */
/* @0x20cf28 beq 0x20d2f0 <_ZN8CDS_Grid7ShuffleEv+0x558> */
/* @0x20cf2c cmp r1, #2 */
/* @0x20cf30 bne 0x20cf54 <_ZN8CDS_Grid7ShuffleEv+0x1bc> */
/* @0x20cf34 sub r0, r0, #1 */
/* @0x20cf38 bic r0, r0, #-16777216 */
/* @0x20cf3c bic r0, r0, #3 */
/* @0x20cf40 cmp r0, #0 */
/* @0x20cf44 beq 0x20d4d8 <_ZN8CDS_Grid7ShuffleEv+0x740> */
/* @0x20cf48 mov r0, #5 */
/* @0x20cf4c str r5, [r10, #0x8] */
/* @0x20cf50 str r0, [r10, #0xc] */
/* @0x20cf54 ldr r1, [r2, #0xc] */
/* @0x20cf58 ldr r0, [r2, #0x8] */
/* @0x20cf5c str r5, [r11, r3, lsl #4] */
/* @0x20cf60 str r1, [r10, #0xc] */
/* @0x20cf64 ldr r1, [r2, #0xc] */
/* @0x20cf68 str r0, [r10, #0x8] */
/* @0x20cf6c bic r1, r1, #-16777216 */
/* @0x20cf70 cmp r1, #14 */
/* @0x20cf74 addls pc, pc, r1, lsl #2 */
/* @0x20cf78 b 0x20cfc4 <_ZN8CDS_Grid7ShuffleEv+0x22c> */
/* @0x20cf7c b 0x20d100 <_ZN8CDS_Grid7ShuffleEv+0x368> */
/* @0x20cf80 b 0x20d1f8 <_ZN8CDS_Grid7ShuffleEv+0x460> */
/* @0x20cf84 b 0x20d1c8 <_ZN8CDS_Grid7ShuffleEv+0x430> */
/* @0x20cf88 b 0x20cfb8 <_ZN8CDS_Grid7ShuffleEv+0x220> */
/* @0x20cf8c b 0x20cfc4 <_ZN8CDS_Grid7ShuffleEv+0x22c> */
/* @0x20cf90 b 0x20cfc4 <_ZN8CDS_Grid7ShuffleEv+0x22c> */
/* @0x20cf94 b 0x20d19c <_ZN8CDS_Grid7ShuffleEv+0x404> */
/* @0x20cf98 b 0x20cfb8 <_ZN8CDS_Grid7ShuffleEv+0x220> */
/* @0x20cf9c b 0x20cfc4 <_ZN8CDS_Grid7ShuffleEv+0x22c> */
/* @0x20cfa0 b 0x20cfc4 <_ZN8CDS_Grid7ShuffleEv+0x22c> */
/* @0x20cfa4 b 0x20d100 <_ZN8CDS_Grid7ShuffleEv+0x368> */
/* @0x20cfa8 b 0x20cfc4 <_ZN8CDS_Grid7ShuffleEv+0x22c> */
/* @0x20cfac b 0x20cfc4 <_ZN8CDS_Grid7ShuffleEv+0x22c> */
/* @0x20cfb0 b 0x20d100 <_ZN8CDS_Grid7ShuffleEv+0x368> */
/* @0x20cfb4 b 0x20cfb8 <_ZN8CDS_Grid7ShuffleEv+0x220> */
/* @0x20cfb8 ldr r1, [sp, #0x18] */
/* @0x20cfbc ldr r2, [r9, r1, lsl #4] */
/* @0x20cfc0 str r2, [r11, r3, lsl #4] */
/* @0x20cfc4 ldm r4, {r10, r11} */
/* @0x20cfc8 mla r11, r11, r7, r6 */
/* @0x20cfcc add r9, r10, r11, lsl #4 */
/* @0x20cfd0 ldr r3, [r9, #0xc] */
/* @0x20cfd4 sub r3, r3, #1 */
/* @0x20cfd8 bic r3, r3, #-16777216 */
/* @0x20cfdc bic r3, r3, #3 */
/* @0x20cfe0 cmp r3, #0 */
/* @0x20cfe4 beq 0x20d3a0 <_ZN8CDS_Grid7ShuffleEv+0x608> */
/* @0x20cfe8 str r5, [r9, #0x8] */
/* @0x20cfec mov r2, #5 */
/* @0x20cff0 str r2, [r9, #0xc] */
/* @0x20cff4 str r5, [r10, r11, lsl #4] */
/* @0x20cff8 ldr r3, [r4, #0x4] */
/* @0x20cffc ldr r10, [r4] */
/* @0x20d000 mla r6, r3, r7, r6 */
/* @0x20d004 add r9, r10, r6, lsl #4 */
/* @0x20d008 ldr r2, [r9, #0xc] */
/* @0x20d00c bic r3, r2, #-16777216 */
/* @0x20d010 cmp r3, #1 */
/* @0x20d014 beq 0x20d348 <_ZN8CDS_Grid7ShuffleEv+0x5b0> */
/* @0x20d018 cmp r3, #2 */
/* @0x20d01c bne 0x20d040 <_ZN8CDS_Grid7ShuffleEv+0x2a8> */
/* @0x20d020 sub r2, r2, #1 */
/* @0x20d024 bic r2, r2, #-16777216 */
/* @0x20d028 bic r2, r2, #3 */
/* @0x20d02c cmp r2, #0 */
/* @0x20d030 beq 0x20d4cc <_ZN8CDS_Grid7ShuffleEv+0x734> */
/* @0x20d034 mov r3, #5 */
/* @0x20d038 str r5, [r9, #0x8] */
/* @0x20d03c str r3, [r9, #0xc] */
/* @0x20d040 ldr r3, [sp, #0x2c] */
/* @0x20d044 ldr r2, [sp, #0x28] */
/* @0x20d048 str r5, [r10, r6, lsl #4] */
/* @0x20d04c str r3, [r9, #0xc] */
/* @0x20d050 ldr r3, [sp, #0x2c] */
/* @0x20d054 str r2, [r9, #0x8] */
/* @0x20d058 bic r2, r3, #-16777216 */
/* @0x20d05c cmp r2, #14 */
/* @0x20d060 addls pc, pc, r2, lsl #2 */
/* @0x20d064 b 0x20d0ac <_ZN8CDS_Grid7ShuffleEv+0x314> */
/* @0x20d068 b 0x20d118 <_ZN8CDS_Grid7ShuffleEv+0x380> */
/* @0x20d06c b 0x20d158 <_ZN8CDS_Grid7ShuffleEv+0x3c0> */
/* @0x20d070 b 0x20d12c <_ZN8CDS_Grid7ShuffleEv+0x394> */
/* @0x20d074 b 0x20d0a4 <_ZN8CDS_Grid7ShuffleEv+0x30c> */
/* @0x20d078 b 0x20d0ac <_ZN8CDS_Grid7ShuffleEv+0x314> */
/* @0x20d07c b 0x20d0ac <_ZN8CDS_Grid7ShuffleEv+0x314> */
/* @0x20d080 b 0x20d174 <_ZN8CDS_Grid7ShuffleEv+0x3dc> */
/* @0x20d084 b 0x20d0a4 <_ZN8CDS_Grid7ShuffleEv+0x30c> */
/* @0x20d088 b 0x20d0ac <_ZN8CDS_Grid7ShuffleEv+0x314> */
/* @0x20d08c b 0x20d0ac <_ZN8CDS_Grid7ShuffleEv+0x314> */
/* @0x20d090 b 0x20d118 <_ZN8CDS_Grid7ShuffleEv+0x380> */
/* @0x20d094 b 0x20d0ac <_ZN8CDS_Grid7ShuffleEv+0x314> */
/* @0x20d098 b 0x20d0ac <_ZN8CDS_Grid7ShuffleEv+0x314> */
/* @0x20d09c b 0x20d118 <_ZN8CDS_Grid7ShuffleEv+0x380> */
/* @0x20d0a0 b 0x20d0a4 <_ZN8CDS_Grid7ShuffleEv+0x30c> */
/* @0x20d0a4 ldr r2, [sp, #0x20] */
/* @0x20d0a8 str r2, [r10, r6, lsl #4] */
/* @0x20d0ac sub r3, r3, #1 */
/* @0x20d0b0 bic r3, r3, #-16777216 */
/* @0x20d0b4 bic r3, r3, #3 */
/* @0x20d0b8 cmp r3, #0 */
/* @0x20d0bc beq 0x20d394 <_ZN8CDS_Grid7ShuffleEv+0x5fc> */
/* @0x20d0c0 mov r0, #5 */
/* @0x20d0c4 str r5, [sp, #0x28] */
/* @0x20d0c8 str r0, [sp, #0x2c] */
/* @0x20d0cc str r5, [sp, #0x20] */
/* @0x20d0d0 ldr r2, [sp, #0x14] */
/* @0x20d0d4 ldr r0, [r4, #0x4] */
/* @0x20d0d8 add r2, r2, #1 */
/* @0x20d0dc str r2, [sp, #0x14] */
/* @0x20d0e0 ldr r2, [r4, #0x8] */
/* @0x20d0e4 lsl r3, r0, #3 */
/* @0x20d0e8 mul r3, r2, r3 */
/* @0x20d0ec ldr r2, [sp, #0x14] */
/* @0x20d0f0 cmp r3, r2 */
/* @0x20d0f4 bge 0x20cddc <_ZN8CDS_Grid7ShuffleEv+0x44> */
/* @0x20d0f8 add sp, sp, #52 */
/* @0x20d0fc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x20d100 ldr r0, [sp, #0x18] */
/* @0x20d104 ldr r2, [r2, #0x4] */
/* @0x20d108 ldr r1, [r9, r0, lsl #4] */
/* @0x20d10c str r1, [r11, r3, lsl #4] */
/* @0x20d110 str r2, [r10, #0x4] */
/* @0x20d114 b 0x20cfc4 <_ZN8CDS_Grid7ShuffleEv+0x22c> */
/* @0x20d118 ldr r1, [sp, #0x20] */
/* @0x20d11c ldr r2, [sp, #0x24] */
/* @0x20d120 str r1, [r10, r6, lsl #4] */
/* @0x20d124 str r2, [r9, #0x4] */
/* @0x20d128 b 0x20d0ac <_ZN8CDS_Grid7ShuffleEv+0x314> */
/* @0x20d12c ldr r2, [sp, #0x20] */
/* @0x20d130 cmp r2, #0 */
/* @0x20d134 str r2, [r10, r6, lsl #4] */
/* @0x20d138 beq 0x20d0ac <_ZN8CDS_Grid7ShuffleEv+0x314> */
/* @0x20d13c ldr r0, [r2, #0x8] */
/* @0x20d140 ldr r1, [r2] */
/* @0x20d144 cmp r0, #0 */
/* @0x20d148 streq r9, [r2, #0x8] */
/* @0x20d14c add r1, r1, #1 */
/* @0x20d150 str r1, [r2] */
/* @0x20d154 b 0x20d0ac <_ZN8CDS_Grid7ShuffleEv+0x314> */
/* @0x20d158 ldr r2, [sp, #0x20] */
/* @0x20d15c cmp r2, #0 */
/* @0x20d160 ldrne r3, [r2, #0x4] */
/* @0x20d164 addne r3, r3, #1 */
/* @0x20d168 strne r3, [r2, #0x4] */
/* @0x20d16c ldrne r3, [sp, #0x2c] */
/* @0x20d170 b 0x20d0a8 <_ZN8CDS_Grid7ShuffleEv+0x310> */
/* @0x20d174 ldr r2, [sp, #0x20] */
/* @0x20d178 str r2, [r10, r6, lsl #4] */
/* @0x20d17c ldr r2, [sp, #0x20] */
/* @0x20d180 cmp r2, #0 */
/* @0x20d184 beq 0x20d0ac <_ZN8CDS_Grid7ShuffleEv+0x314> */
/* @0x20d188 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x20d18c ldr r1, [sp, #0x20] */
/* @0x20d190 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x20d194 ldr r3, [sp, #0x2c] */
/* @0x20d198 b 0x20d0ac <_ZN8CDS_Grid7ShuffleEv+0x314> */
/* @0x20d19c ldr r1, [sp, #0x18] */
/* @0x20d1a0 ldr r2, [r9, r1, lsl #4] */
/* @0x20d1a4 str r2, [r11, r3, lsl #4] */
/* @0x20d1a8 ldr r3, [r9, r1, lsl #4] */
/* @0x20d1ac cmp r3, #0 */
/* @0x20d1b0 beq 0x20cfc4 <_ZN8CDS_Grid7ShuffleEv+0x22c> */
/* @0x20d1b4 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x20d1b8 ldr r2, [sp, #0x18] */
/* @0x20d1bc ldr r1, [r9, r2, lsl #4] */
/* @0x20d1c0 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x20d1c4 b 0x20cfc4 <_ZN8CDS_Grid7ShuffleEv+0x22c> */
/* @0x20d1c8 ldr r1, [sp, #0x18] */
/* @0x20d1cc ldr r2, [r9, r1, lsl #4] */
/* @0x20d1d0 cmp r2, #0 */
/* @0x20d1d4 str r2, [r11, r3, lsl #4] */
/* @0x20d1d8 beq 0x20cfc4 <_ZN8CDS_Grid7ShuffleEv+0x22c> */
/* @0x20d1dc ldr r1, [r2, #0x8] */
/* @0x20d1e0 ldr r3, [r2] */
/* @0x20d1e4 cmp r1, #0 */
/* @0x20d1e8 streq r10, [r2, #0x8] */
/* @0x20d1ec add r3, r3, #1 */
/* @0x20d1f0 str r3, [r2] */
/* @0x20d1f4 b 0x20cfc4 <_ZN8CDS_Grid7ShuffleEv+0x22c> */
/* @0x20d1f8 ldr r1, [sp, #0x18] */
/* @0x20d1fc ldr r2, [r9, r1, lsl #4] */
/* @0x20d200 cmp r2, #0 */
/* @0x20d204 ldrne r1, [r2, #0x4] */
/* @0x20d208 addne r1, r1, #1 */
/* @0x20d20c strne r1, [r2, #0x4] */
/* @0x20d210 b 0x20cfc0 <_ZN8CDS_Grid7ShuffleEv+0x228> */
/* @0x20d214 ldr r2, [r11, r2, lsl #4] */
/* @0x20d218 cmp r2, #0 */
/* @0x20d21c str r2, [sp, #0x20] */
/* @0x20d220 beq 0x20cec8 <_ZN8CDS_Grid7ShuffleEv+0x130> */
/* @0x20d224 ldr r0, [r2, #0x8] */
/* @0x20d228 ldr r1, [r2] */
/* @0x20d22c cmp r0, #0 */
/* @0x20d230 add r1, r1, #1 */
/* @0x20d234 str r1, [r2] */
/* @0x20d238 addeq r1, sp, #32 */
/* @0x20d23c streq r1, [r2, #0x8] */
/* @0x20d240 b 0x20cec8 <_ZN8CDS_Grid7ShuffleEv+0x130> */
/* @0x20d244 ldr r2, [r11, r2, lsl #4] */
/* @0x20d248 cmp r2, #0 */
/* @0x20d24c ldrne r1, [r2, #0x4] */
/* @0x20d250 addne r1, r1, #1 */
/* @0x20d254 strne r1, [r2, #0x4] */
/* @0x20d258 b 0x20cec4 <_ZN8CDS_Grid7ShuffleEv+0x12c> */
/* @0x20d25c ldr r0, [r11, r2, lsl #4] */
/* @0x20d260 ldr r1, [r9, #0x4] */
/* @0x20d264 strd r0, r1, [sp, #32] */
/* @0x20d268 b 0x20cec8 <_ZN8CDS_Grid7ShuffleEv+0x130> */
/* @0x20d26c ldr r1, [r11, r2, lsl #4] */
/* @0x20d270 ldr r2, [r9, #0x4] */
/* @0x20d274 str r1, [sp, #0x20] */
/* @0x20d278 str r2, [sp, #0x24] */
/* @0x20d27c b 0x20cec8 <_ZN8CDS_Grid7ShuffleEv+0x130> */
/* @0x20d280 ldr r1, [r11, r2, lsl #4] */
/* @0x20d284 str r1, [sp, #0x20] */
/* @0x20d288 ldr r1, [r11, r2, lsl #4] */
/* @0x20d28c cmp r1, #0 */
/* @0x20d290 beq 0x20cec8 <_ZN8CDS_Grid7ShuffleEv+0x130> */
/* @0x20d294 str r2, [sp, #0x4] */
/* @0x20d298 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x20d29c ldr r2, [sp, #0x4] */
/* @0x20d2a0 ldr r1, [r11, r2, lsl #4] */
/* @0x20d2a4 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x20d2a8 b 0x20cec8 <_ZN8CDS_Grid7ShuffleEv+0x130> */
/* @0x20d2ac ldr r1, [sp, #0x20] */
/* @0x20d2b0 cmp r1, #0 */
/* @0x20d2b4 beq 0x20ce5c <_ZN8CDS_Grid7ShuffleEv+0xc4> */
/* @0x20d2b8 str r1, [sp, #0x8] */
/* @0x20d2bc str r2, [sp, #0x4] */
/* @0x20d2c0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20d2c4 ldr r1, [sp, #0x8] */
/* @0x20d2c8 ldr r2, [sp, #0x4] */
/* @0x20d2cc ldr r12, [r1, #0x4] */
/* @0x20d2d0 sub r12, r12, #1 */
/* @0x20d2d4 str r12, [r1, #0x4] */
/* @0x20d2d8 cmp r12, #0 */
/* @0x20d2dc beq 0x20d3ac <_ZN8CDS_Grid7ShuffleEv+0x614> */
/* @0x20d2e0 str r2, [sp, #0x4] */
/* @0x20d2e4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20d2e8 ldr r2, [sp, #0x4] */
/* @0x20d2ec b 0x20ce5c <_ZN8CDS_Grid7ShuffleEv+0xc4> */
/* @0x20d2f0 ldr r1, [r11, r3, lsl #4] */
/* @0x20d2f4 cmp r1, #0 */
/* @0x20d2f8 beq 0x20d340 <_ZN8CDS_Grid7ShuffleEv+0x5a8> */
/* @0x20d2fc str r1, [sp, #0x8] */
/* @0x20d300 str r2, [sp, #0x4] */
/* @0x20d304 str r3, [sp, #0xc] */
/* @0x20d308 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20d30c ldr r1, [sp, #0x8] */
/* @0x20d310 ldr r2, [sp, #0x4] */
/* @0x20d314 ldr r3, [sp, #0xc] */
/* @0x20d318 ldr r12, [r1, #0x4] */
/* @0x20d31c sub r12, r12, #1 */
/* @0x20d320 str r12, [r1, #0x4] */
/* @0x20d324 cmp r12, #0 */
/* @0x20d328 beq 0x20d410 <_ZN8CDS_Grid7ShuffleEv+0x678> */
/* @0x20d32c str r2, [sp, #0x4] */
/* @0x20d330 str r3, [sp, #0xc] */
/* @0x20d334 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20d338 ldr r3, [sp, #0xc] */
/* @0x20d33c ldr r2, [sp, #0x4] */
/* @0x20d340 str r5, [r11, r3, lsl #4] */
/* @0x20d344 b 0x20cf54 <_ZN8CDS_Grid7ShuffleEv+0x1bc> */
/* @0x20d348 ldr r7, [r10, r6, lsl #4] */
/* @0x20d34c cmp r7, #0 */
/* @0x20d350 beq 0x20d370 <_ZN8CDS_Grid7ShuffleEv+0x5d8> */
/* @0x20d354 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20d358 ldr r11, [r7, #0x4] */
/* @0x20d35c sub r11, r11, #1 */
/* @0x20d360 str r11, [r7, #0x4] */
/* @0x20d364 cmp r11, #0 */
/* @0x20d368 beq 0x20d480 <_ZN8CDS_Grid7ShuffleEv+0x6e8> */
/* @0x20d36c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20d370 str r5, [r10, r6, lsl #4] */
/* @0x20d374 b 0x20d040 <_ZN8CDS_Grid7ShuffleEv+0x2a8> */
/* @0x20d378 mov r0, r11 */
/* @0x20d37c str r1, [sp, #0x8] */
/* @0x20d380 str r2, [sp, #0x4] */
/* @0x20d384 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20d388 ldr r2, [sp, #0x4] */
/* @0x20d38c ldr r1, [sp, #0x8] */
/* @0x20d390 b 0x20cefc <_ZN8CDS_Grid7ShuffleEv+0x164> */
/* @0x20d394 add r0, sp, #32 */
/* @0x20d398 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20d39c b 0x20d0c0 <_ZN8CDS_Grid7ShuffleEv+0x328> */
/* @0x20d3a0 mov r0, r9 */
/* @0x20d3a4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20d3a8 b 0x20cfe8 <_ZN8CDS_Grid7ShuffleEv+0x250> */
/* @0x20d3ac ldr r0, [r1] */
/* @0x20d3b0 str r1, [sp, #0x8] */
/* @0x20d3b4 str r12, [sp, #0x10] */
/* @0x20d3b8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20d3bc ldr r1, [sp, #0x8] */
/* @0x20d3c0 ldr r12, [sp, #0x10] */
/* @0x20d3c4 str r12, [r1] */
/* @0x20d3c8 str r12, [r1, #0x8] */
/* @0x20d3cc str r1, [sp, #0x8] */
/* @0x20d3d0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20d3d4 ldr r1, [sp, #0x8] */
/* @0x20d3d8 ldr r2, [sp, #0x4] */
/* @0x20d3dc ldr r12, [r1, #0x4] */
/* @0x20d3e0 sub r12, r12, #1 */
/* @0x20d3e4 str r12, [r1, #0x4] */
/* @0x20d3e8 cmp r12, #0 */
/* @0x20d3ec beq 0x20d598 <_ZN8CDS_Grid7ShuffleEv+0x800> */
/* @0x20d3f0 str r2, [sp, #0x4] */
/* @0x20d3f4 str r1, [sp, #0x8] */
/* @0x20d3f8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20d3fc ldr r1, [sp, #0x8] */
/* @0x20d400 mov r0, r1 */
/* @0x20d404 bl 0x27d1d0 <_ZdlPv> */
/* @0x20d408 ldr r2, [sp, #0x4] */
/* @0x20d40c b 0x20d2e0 <_ZN8CDS_Grid7ShuffleEv+0x548> */
/* @0x20d410 ldr r0, [r1] */
/* @0x20d414 str r1, [sp, #0x8] */
/* @0x20d418 str r12, [sp, #0x10] */
/* @0x20d41c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20d420 ldr r1, [sp, #0x8] */
/* @0x20d424 ldr r12, [sp, #0x10] */
/* @0x20d428 str r12, [r1] */
/* @0x20d42c str r12, [r1, #0x8] */
/* @0x20d430 str r1, [sp, #0x8] */
/* @0x20d434 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20d438 ldr r1, [sp, #0x8] */
/* @0x20d43c ldr r2, [sp, #0x4] */
/* @0x20d440 ldr r3, [sp, #0xc] */
/* @0x20d444 ldr r12, [r1, #0x4] */
/* @0x20d448 sub r12, r12, #1 */
/* @0x20d44c str r12, [r1, #0x4] */
/* @0x20d450 cmp r12, #0 */
/* @0x20d454 beq 0x20d524 <_ZN8CDS_Grid7ShuffleEv+0x78c> */
/* @0x20d458 str r2, [sp, #0x4] */
/* @0x20d45c str r3, [sp, #0xc] */
/* @0x20d460 str r1, [sp, #0x8] */
/* @0x20d464 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20d468 ldr r1, [sp, #0x8] */
/* @0x20d46c mov r0, r1 */
/* @0x20d470 bl 0x27d1d0 <_ZdlPv> */
/* @0x20d474 ldr r3, [sp, #0xc] */
/* @0x20d478 ldr r2, [sp, #0x4] */
/* @0x20d47c b 0x20d32c <_ZN8CDS_Grid7ShuffleEv+0x594> */
/* @0x20d480 ldr r0, [r7] */
/* @0x20d484 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20d488 str r11, [r7] */
/* @0x20d48c str r11, [r7, #0x8] */
/* @0x20d490 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20d494 ldr r11, [r7, #0x4] */
/* @0x20d498 sub r11, r11, #1 */
/* @0x20d49c str r11, [r7, #0x4] */
/* @0x20d4a0 cmp r11, #0 */
/* @0x20d4a4 beq 0x20d4f4 <_ZN8CDS_Grid7ShuffleEv+0x75c> */
/* @0x20d4a8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20d4ac mov r0, r7 */
/* @0x20d4b0 bl 0x27d1d0 <_ZdlPv> */
/* @0x20d4b4 b 0x20d36c <_ZN8CDS_Grid7ShuffleEv+0x5d4> */
/* @0x20d4b8 add r0, sp, #32 */
/* @0x20d4bc str r2, [sp, #0x4] */
/* @0x20d4c0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20d4c4 ldr r2, [sp, #0x4] */
/* @0x20d4c8 b 0x20ce50 <_ZN8CDS_Grid7ShuffleEv+0xb8> */
/* @0x20d4cc mov r0, r9 */
/* @0x20d4d0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20d4d4 b 0x20d034 <_ZN8CDS_Grid7ShuffleEv+0x29c> */
/* @0x20d4d8 mov r0, r10 */
/* @0x20d4dc str r2, [sp, #0x4] */
/* @0x20d4e0 str r3, [sp, #0xc] */
/* @0x20d4e4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20d4e8 ldr r3, [sp, #0xc] */
/* @0x20d4ec ldr r2, [sp, #0x4] */
/* @0x20d4f0 b 0x20cf48 <_ZN8CDS_Grid7ShuffleEv+0x1b0> */
/* @0x20d4f4 ldr r0, [r7] */
/* @0x20d4f8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20d4fc mov r0, r7 */
/* @0x20d500 str r11, [r7] */
/* @0x20d504 str r11, [r7, #0x8] */
/* @0x20d508 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x20d50c mov r0, r7 */
/* @0x20d510 bl 0x27d1d0 <_ZdlPv> */
/* @0x20d514 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20d518 mov r0, r7 */
/* @0x20d51c bl 0x27d1d0 <_ZdlPv> */
/* @0x20d520 b 0x20d36c <_ZN8CDS_Grid7ShuffleEv+0x5d4> */
/* @0x20d524 ldr r0, [r1] */
/* @0x20d528 str r1, [sp, #0x8] */
/* @0x20d52c str r12, [sp, #0x10] */
/* @0x20d530 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20d534 ldr r1, [sp, #0x8] */
/* @0x20d538 ldr r12, [sp, #0x10] */
/* @0x20d53c str r12, [r1] */
/* @0x20d540 str r12, [r1, #0x8] */
/* @0x20d544 str r1, [sp, #0x8] */
/* @0x20d548 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20d54c ldr r1, [sp, #0x8] */
/* @0x20d550 ldr r2, [sp, #0x4] */
/* @0x20d554 ldr r3, [sp, #0xc] */
/* @0x20d558 ldr r12, [r1, #0x4] */
/* @0x20d55c sub r12, r12, #1 */
/* @0x20d560 str r12, [r1, #0x4] */
/* @0x20d564 cmp r12, #0 */
/* @0x20d568 beq 0x20d600 <_ZN8CDS_Grid7ShuffleEv+0x868> */
/* @0x20d56c str r2, [sp, #0x4] */
/* @0x20d570 str r3, [sp, #0xc] */
/* @0x20d574 str r1, [sp, #0x8] */
/* @0x20d578 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20d57c ldr r1, [sp, #0x8] */
/* @0x20d580 mov r0, r1 */
/* @0x20d584 bl 0x27d1d0 <_ZdlPv> */
/* @0x20d588 ldr r3, [sp, #0xc] */
/* @0x20d58c ldr r2, [sp, #0x4] */
/* @0x20d590 ldr r1, [sp, #0x8] */
/* @0x20d594 b 0x20d458 <_ZN8CDS_Grid7ShuffleEv+0x6c0> */
/* @0x20d598 ldr r0, [r1] */
/* @0x20d59c str r1, [sp, #0x8] */
/* @0x20d5a0 str r12, [sp, #0x10] */
/* @0x20d5a4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20d5a8 ldr r1, [sp, #0x8] */
/* @0x20d5ac ldr r12, [sp, #0x10] */
/* @0x20d5b0 str r12, [r1] */
/* @0x20d5b4 str r12, [r1, #0x8] */
/* @0x20d5b8 str r1, [sp, #0x8] */
/* @0x20d5bc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20d5c0 ldr r1, [sp, #0x8] */
/* @0x20d5c4 ldr r2, [sp, #0x4] */
/* @0x20d5c8 ldr r12, [r1, #0x4] */
/* @0x20d5cc sub r12, r12, #1 */
/* @0x20d5d0 str r12, [r1, #0x4] */
/* @0x20d5d4 cmp r12, #0 */
/* @0x20d5d8 beq 0x20d6b8 <_ZN8CDS_Grid7ShuffleEv+0x920> */
/* @0x20d5dc str r2, [sp, #0x4] */
/* @0x20d5e0 str r1, [sp, #0x8] */
/* @0x20d5e4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20d5e8 ldr r1, [sp, #0x8] */
/* @0x20d5ec mov r0, r1 */
/* @0x20d5f0 bl 0x27d1d0 <_ZdlPv> */
/* @0x20d5f4 ldr r2, [sp, #0x4] */
/* @0x20d5f8 ldr r1, [sp, #0x8] */
/* @0x20d5fc b 0x20d3f0 <_ZN8CDS_Grid7ShuffleEv+0x658> */
/* @0x20d600 ldr r0, [r1] */
/* @0x20d604 str r1, [sp, #0x8] */
/* @0x20d608 str r12, [sp, #0x10] */
/* @0x20d60c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20d610 ldr r1, [sp, #0x8] */
/* @0x20d614 ldr r12, [sp, #0x10] */
/* @0x20d618 str r12, [r1] */
/* @0x20d61c str r12, [r1, #0x8] */
/* @0x20d620 str r1, [sp, #0x8] */
/* @0x20d624 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20d628 ldr r1, [sp, #0x8] */
/* @0x20d62c ldr r2, [sp, #0x4] */
/* @0x20d630 ldr r3, [sp, #0xc] */
/* @0x20d634 ldr r12, [r1, #0x4] */
/* @0x20d638 sub r12, r12, #1 */
/* @0x20d63c str r12, [r1, #0x4] */
/* @0x20d640 cmp r12, #0 */
/* @0x20d644 bne 0x20d68c <_ZN8CDS_Grid7ShuffleEv+0x8f4> */
/* @0x20d648 ldr r0, [r1] */
/* @0x20d64c str r1, [sp, #0x8] */
/* @0x20d650 str r12, [sp, #0x10] */
/* @0x20d654 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20d658 ldr r1, [sp, #0x8] */
/* @0x20d65c ldr r12, [sp, #0x10] */
/* @0x20d660 mov r0, r1 */
/* @0x20d664 str r12, [r1] */
/* @0x20d668 str r12, [r1, #0x8] */
/* @0x20d66c str r1, [sp, #0x8] */
/* @0x20d670 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x20d674 ldr r1, [sp, #0x8] */
/* @0x20d678 mov r0, r1 */
/* @0x20d67c bl 0x27d1d0 <_ZdlPv> */
/* @0x20d680 ldr r3, [sp, #0xc] */
/* @0x20d684 ldr r2, [sp, #0x4] */
/* @0x20d688 ldr r1, [sp, #0x8] */
/* @0x20d68c str r2, [sp, #0x4] */
/* @0x20d690 str r3, [sp, #0xc] */
/* @0x20d694 str r1, [sp, #0x8] */
/* @0x20d698 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20d69c ldr r1, [sp, #0x8] */
/* @0x20d6a0 mov r0, r1 */
/* @0x20d6a4 bl 0x27d1d0 <_ZdlPv> */
/* @0x20d6a8 ldr r3, [sp, #0xc] */
/* @0x20d6ac ldr r2, [sp, #0x4] */
/* @0x20d6b0 ldr r1, [sp, #0x8] */
/* @0x20d6b4 b 0x20d56c <_ZN8CDS_Grid7ShuffleEv+0x7d4> */
/* @0x20d6b8 ldr r0, [r1] */
/* @0x20d6bc str r1, [sp, #0x8] */
/* @0x20d6c0 str r12, [sp, #0x10] */
/* @0x20d6c4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20d6c8 ldr r1, [sp, #0x8] */
/* @0x20d6cc ldr r12, [sp, #0x10] */
/* @0x20d6d0 str r12, [r1] */
/* @0x20d6d4 str r12, [r1, #0x8] */
/* @0x20d6d8 str r1, [sp, #0x8] */
/* @0x20d6dc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20d6e0 ldr r1, [sp, #0x8] */
/* @0x20d6e4 ldr r2, [sp, #0x4] */
/* @0x20d6e8 ldr r12, [r1, #0x4] */
/* @0x20d6ec sub r12, r12, #1 */
/* @0x20d6f0 str r12, [r1, #0x4] */
/* @0x20d6f4 cmp r12, #0 */
/* @0x20d6f8 bne 0x20d73c <_ZN8CDS_Grid7ShuffleEv+0x9a4> */
/* @0x20d6fc ldr r0, [r1] */
/* @0x20d700 str r1, [sp, #0x8] */
/* @0x20d704 str r12, [sp, #0x10] */
/* @0x20d708 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20d70c ldr r1, [sp, #0x8] */
/* @0x20d710 ldr r12, [sp, #0x10] */
/* @0x20d714 mov r0, r1 */
/* @0x20d718 str r12, [r1] */
/* @0x20d71c str r12, [r1, #0x8] */
/* @0x20d720 str r1, [sp, #0x8] */
/* @0x20d724 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x20d728 ldr r1, [sp, #0x8] */
/* @0x20d72c mov r0, r1 */
/* @0x20d730 bl 0x27d1d0 <_ZdlPv> */
/* @0x20d734 ldr r2, [sp, #0x4] */
/* @0x20d738 ldr r1, [sp, #0x8] */
/* @0x20d73c str r2, [sp, #0x4] */
/* @0x20d740 str r1, [sp, #0x8] */
/* @0x20d744 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20d748 ldr r1, [sp, #0x8] */
/* @0x20d74c mov r0, r1 */
/* @0x20d750 bl 0x27d1d0 <_ZdlPv> */
/* @0x20d754 ldr r2, [sp, #0x4] */
/* @0x20d758 ldr r1, [sp, #0x8] */
/* @0x20d75c b 0x20d5dc <_ZN8CDS_Grid7ShuffleEv+0x844> */

/* ── FUNC 0x20d760 · CDS_Map::Add(char const*, double, char const*) · size=648 · insn=162 */
/* @0x20d760 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x20d764 sub sp, sp, #36 */
/* @0x20d768 mov r8, r0 */
/* @0x20d76c mov r4, r2 */
/* @0x20d770 ldr r6, [sp, #0x48] */
/* @0x20d774 mov r0, sp */
/* @0x20d778 mov r5, r3 */
/* @0x20d77c mov r2, #1 */
/* @0x20d780 mov r3, #0 */
/* @0x20d784 str r2, [sp, #0xc] */
/* @0x20d788 str r3, [sp] */
/* @0x20d78c str r3, [sp, #0x4] */
/* @0x20d790 str r3, [sp, #0x8] */
/* @0x20d794 str r3, [sp, #0x10] */
/* @0x20d798 str r3, [sp, #0x14] */
/* @0x20d79c str r3, [sp, #0x18] */
/* @0x20d7a0 str r3, [sp, #0x1c] */
/* @0x20d7a4 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x20d7a8 cmp r6, #0 */
/* @0x20d7ac strd r4, r5, [sp, #16] */
/* @0x20d7b0 add r4, sp, #16 */
/* @0x20d7b4 beq 0x20d7c4 <_ZN7CDS_Map3AddEPKcdS1_+0x64> */
/* @0x20d7b8 mov r1, r6 */
/* @0x20d7bc mov r0, r4 */
/* @0x20d7c0 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x20d7c4 mov r0, r8 */
/* @0x20d7c8 mov r1, sp */
/* @0x20d7cc mov r2, r4 */
/* @0x20d7d0 bl 0x20b884 <_ZN7CDS_Map3AddEP6RValueS1_> */
/* @0x20d7d4 ldr r3, [sp, #0xc] */
/* @0x20d7d8 sub r3, r3, #1 */
/* @0x20d7dc bic r3, r3, #-16777216 */
/* @0x20d7e0 bic r3, r3, #3 */
/* @0x20d7e4 cmp r3, #0 */
/* @0x20d7e8 mov r6, r0 */
/* @0x20d7ec beq 0x20d874 <_ZN7CDS_Map3AddEPKcdS1_+0x114> */
/* @0x20d7f0 ldr r2, [sp, #0x1c] */
/* @0x20d7f4 mov r1, #0 */
/* @0x20d7f8 mov r0, #5 */
/* @0x20d7fc str r1, [sp, #0x8] */
/* @0x20d800 sub r3, r2, #1 */
/* @0x20d804 str r1, [sp] */
/* @0x20d808 bic r3, r3, #-16777216 */
/* @0x20d80c str r0, [sp, #0xc] */
/* @0x20d810 bics r5, r3, #3 */
/* @0x20d814 beq 0x20d824 <_ZN7CDS_Map3AddEPKcdS1_+0xc4> */
/* @0x20d818 mov r0, r6 */
/* @0x20d81c add sp, sp, #36 */
/* @0x20d820 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x20d824 bic r2, r2, #-16777216 */
/* @0x20d828 cmp r2, #2 */
/* @0x20d82c beq 0x20d8a8 <_ZN7CDS_Map3AddEPKcdS1_+0x148> */
/* @0x20d830 cmp r2, #3 */
/* @0x20d834 beq 0x20d880 <_ZN7CDS_Map3AddEPKcdS1_+0x120> */
/* @0x20d838 cmp r2, #1 */
/* @0x20d83c bne 0x20d818 <_ZN7CDS_Map3AddEPKcdS1_+0xb8> */
/* @0x20d840 ldr r4, [sp, #0x10] */
/* @0x20d844 cmp r4, #0 */
/* @0x20d848 beq 0x20d818 <_ZN7CDS_Map3AddEPKcdS1_+0xb8> */
/* @0x20d84c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20d850 ldr r5, [r4, #0x4] */
/* @0x20d854 sub r5, r5, #1 */
/* @0x20d858 str r5, [r4, #0x4] */
/* @0x20d85c cmp r5, #0 */
/* @0x20d860 beq 0x20d948 <_ZN7CDS_Map3AddEPKcdS1_+0x1e8> */
/* @0x20d864 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20d868 mov r0, r6 */
/* @0x20d86c add sp, sp, #36 */
/* @0x20d870 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x20d874 mov r0, sp */
/* @0x20d878 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20d87c b 0x20d7f0 <_ZN7CDS_Map3AddEPKcdS1_+0x90> */
/* @0x20d880 ldr r3, [sp, #0x18] */
/* @0x20d884 tst r3, #8 */
/* @0x20d888 beq 0x20d818 <_ZN7CDS_Map3AddEPKcdS1_+0xb8> */
/* @0x20d88c ldr r0, [sp, #0x10] */
/* @0x20d890 cmp r0, #0 */
/* @0x20d894 beq 0x20d818 <_ZN7CDS_Map3AddEPKcdS1_+0xb8> */
/* @0x20d898 ldr r3, [r0] */
/* @0x20d89c ldr r3, [r3, #0x4] */
/* @0x20d8a0 blx r3 */
/* @0x20d8a4 b 0x20d818 <_ZN7CDS_Map3AddEPKcdS1_+0xb8> */
/* @0x20d8a8 ldr r8, [sp, #0x10] */
/* @0x20d8ac cmp r8, #0 */
/* @0x20d8b0 beq 0x20d818 <_ZN7CDS_Map3AddEPKcdS1_+0xb8> */
/* @0x20d8b4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20d8b8 ldr r3, [r8] */
/* @0x20d8bc ldr r2, [r8, #0x8] */
/* @0x20d8c0 sub r3, r3, #1 */
/* @0x20d8c4 str r3, [r8] */
/* @0x20d8c8 cmp r2, r4 */
/* @0x20d8cc streq r5, [r8, #0x8] */
/* @0x20d8d0 cmp r3, #0 */
/* @0x20d8d4 bgt 0x20d864 <_ZN7CDS_Map3AddEPKcdS1_+0x104> */
/* @0x20d8d8 ldr r3, [r8, #0x10] */
/* @0x20d8dc cmp r3, #0 */
/* @0x20d8e0 movgt r7, #0 */
/* @0x20d8e4 movgt r11, #5 */
/* @0x20d8e8 movgt r5, r7 */
/* @0x20d8ec ble 0x20d99c <_ZN7CDS_Map3AddEPKcdS1_+0x23c> */
/* @0x20d8f0 ldr r3, [r8, #0x4] */
/* @0x20d8f4 add r9, r3, r7, lsl #3 */
/* @0x20d8f8 ldr r10, [r3, r7, lsl #3] */
/* @0x20d8fc ldr r4, [r9, #0x4] */
/* @0x20d900 add r10, r4, r10, lsl #4 */
/* @0x20d904 cmp r4, r10 */
/* @0x20d908 blo 0x20d924 <_ZN7CDS_Map3AddEPKcdS1_+0x1c4> */
/* @0x20d90c b 0x20d9bc <_ZN7CDS_Map3AddEPKcdS1_+0x25c> */
/* @0x20d910 str r5, [r4, #0x8] */
/* @0x20d914 str r11, [r4, #0xc] */
/* @0x20d918 str r5, [r4], #16 */
/* @0x20d91c cmp r10, r4 */
/* @0x20d920 bls 0x20d980 <_ZN7CDS_Map3AddEPKcdS1_+0x220> */
/* @0x20d924 ldr r3, [r4, #0xc] */
/* @0x20d928 sub r3, r3, #1 */
/* @0x20d92c bic r3, r3, #-16777216 */
/* @0x20d930 bic r3, r3, #3 */
/* @0x20d934 cmp r3, #0 */
/* @0x20d938 bne 0x20d910 <_ZN7CDS_Map3AddEPKcdS1_+0x1b0> */
/* @0x20d93c mov r0, r4 */
/* @0x20d940 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20d944 b 0x20d910 <_ZN7CDS_Map3AddEPKcdS1_+0x1b0> */
/* @0x20d948 ldr r0, [r4] */
/* @0x20d94c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20d950 str r5, [r4] */
/* @0x20d954 str r5, [r4, #0x8] */
/* @0x20d958 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20d95c ldr r5, [r4, #0x4] */
/* @0x20d960 sub r5, r5, #1 */
/* @0x20d964 str r5, [r4, #0x4] */
/* @0x20d968 cmp r5, #0 */
/* @0x20d96c beq 0x20d9c4 <_ZN7CDS_Map3AddEPKcdS1_+0x264> */
/* @0x20d970 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20d974 mov r0, r4 */
/* @0x20d978 bl 0x27d1d0 <_ZdlPv> */
/* @0x20d97c b 0x20d864 <_ZN7CDS_Map3AddEPKcdS1_+0x104> */
/* @0x20d980 ldr r0, [r9, #0x4] */
/* @0x20d984 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0x20d988 ldr r3, [r8, #0x10] */
/* @0x20d98c add r7, r7, #1 */
/* @0x20d990 str r5, [r9, #0x4] */
/* @0x20d994 cmp r7, r3 */
/* @0x20d998 blt 0x20d8f0 <_ZN7CDS_Map3AddEPKcdS1_+0x190> */
/* @0x20d99c ldr r0, [r8, #0x4] */
/* @0x20d9a0 mov r4, #0 */
/* @0x20d9a4 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0x20d9a8 str r4, [r8, #0x4] */
/* @0x20d9ac mov r0, r8 */
/* @0x20d9b0 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0x20d9b4 str r4, [sp, #0x10] */
/* @0x20d9b8 b 0x20d864 <_ZN7CDS_Map3AddEPKcdS1_+0x104> */
/* @0x20d9bc mov r0, r4 */
/* @0x20d9c0 b 0x20d984 <_ZN7CDS_Map3AddEPKcdS1_+0x224> */
/* @0x20d9c4 ldr r0, [r4] */
/* @0x20d9c8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20d9cc mov r0, r4 */
/* @0x20d9d0 str r5, [r4] */
/* @0x20d9d4 str r5, [r4, #0x8] */
/* @0x20d9d8 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x20d9dc mov r0, r4 */
/* @0x20d9e0 bl 0x27d1d0 <_ZdlPv> */
/* @0x20d9e4 b 0x20d970 <_ZN7CDS_Map3AddEPKcdS1_+0x210> */

/* ── FUNC 0x20d9e8 · CDS_Map::~CDS_Map() · size=272 · insn=68 */
/* @0x20d9e8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x20d9ec sub sp, sp, #12 */
/* @0x20d9f0 str r0, [sp, #0x4] */
/* @0x20d9f4 bl 0x20daf8 <_ZN7CDS_Map5ClearEv> */
/* @0x20d9f8 ldr r3, [sp, #0x4] */
/* @0x20d9fc ldr r11, [r3] */
/* @0x20da00 cmp r11, #0 */
/* @0x20da04 beq 0x20dae0 <_ZN7CDS_MapD2Ev+0xf8> */
/* @0x20da08 ldm r11, {r0, r10} */
/* @0x20da0c cmp r10, #0 */
/* @0x20da10 lslge r8, r10, #3 */
/* @0x20da14 movge r7, #0 */
/* @0x20da18 movge r9, #5 */
/* @0x20da1c blt 0x20dad4 <_ZN7CDS_MapD2Ev+0xec> */
/* @0x20da20 ldr r4, [r0, r8] */
/* @0x20da24 add r2, r0, r8 */
/* @0x20da28 str r7, [r0, r8] */
/* @0x20da2c cmp r4, #0 */
/* @0x20da30 str r7, [r2, #0x4] */
/* @0x20da34 beq 0x20dac4 <_ZN7CDS_MapD2Ev+0xdc> */
/* @0x20da38 ldr r5, [r4, #0xc] */
/* @0x20da3c ldr r6, [r4, #0x4] */
/* @0x20da40 cmp r5, #0 */
/* @0x20da44 beq 0x20daa0 <_ZN7CDS_MapD2Ev+0xb8> */
/* @0x20da48 ldr r2, [r5, #0xc] */
/* @0x20da4c sub r2, r2, #1 */
/* @0x20da50 bic r2, r2, #-16777216 */
/* @0x20da54 bic r2, r2, #3 */
/* @0x20da58 cmp r2, #0 */
/* @0x20da5c beq 0x20daec <_ZN7CDS_MapD2Ev+0x104> */
/* @0x20da60 ldr r2, [r5, #0x1c] */
/* @0x20da64 str r7, [r5, #0x8] */
/* @0x20da68 sub r2, r2, #1 */
/* @0x20da6c str r9, [r5, #0xc] */
/* @0x20da70 bic r2, r2, #-16777216 */
/* @0x20da74 str r7, [r5] */
/* @0x20da78 bic r2, r2, #3 */
/* @0x20da7c cmp r2, #0 */
/* @0x20da80 bne 0x20da8c <_ZN7CDS_MapD2Ev+0xa4> */
/* @0x20da84 add r0, r5, #16 */
/* @0x20da88 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20da8c str r7, [r5, #0x18] */
/* @0x20da90 mov r0, r5 */
/* @0x20da94 str r9, [r5, #0x1c] */
/* @0x20da98 str r7, [r5, #0x10] */
/* @0x20da9c bl 0x27d1d0 <_ZdlPv> */
/* @0x20daa0 mov r0, r4 */
/* @0x20daa4 mov r4, r6 */
/* @0x20daa8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x20daac ldr r2, [r11, #0x8] */
/* @0x20dab0 cmp r6, #0 */
/* @0x20dab4 sub r2, r2, #1 */
/* @0x20dab8 str r2, [r11, #0x8] */
/* @0x20dabc bne 0x20da38 <_ZN7CDS_MapD2Ev+0x50> */
/* @0x20dac0 ldr r0, [r11] */
/* @0x20dac4 sub r10, r10, #1 */
/* @0x20dac8 sub r8, r8, #8 */
/* @0x20dacc cmn r10, #1 */
/* @0x20dad0 bne 0x20da20 <_ZN7CDS_MapD2Ev+0x38> */
/* @0x20dad4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x20dad8 mov r0, r11 */
/* @0x20dadc bl 0x27d1d0 <_ZdlPv> */
/* @0x20dae0 ldr r0, [sp, #0x4] */
/* @0x20dae4 add sp, sp, #12 */
/* @0x20dae8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x20daec mov r0, r5 */
/* @0x20daf0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20daf4 b 0x20da60 <_ZN7CDS_MapD2Ev+0x78> */

/* ── FUNC 0x20d9e8 · CDS_Map::~CDS_Map() · alias of the symbol above · insn=0 */

/* ── FUNC 0x20daf8 · CDS_Map::Clear() · size=784 · insn=196 */
/* @0x20daf8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x20dafc sub sp, sp, #36 */
/* @0x20db00 add r3, sp, #28 */
/* @0x20db04 mov r11, r0 */
/* @0x20db08 str r3, [sp, #0x14] */
/* @0x20db0c mov r6, #0 */
/* @0x20db10 mov r0, r3 */
/* @0x20db14 ldr r9, [pc, #0x2d8] */
/* @0x20db18 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0x20db1c ldr r10, [r11] */
/* @0x20db20 add r9, pc, r9 */
/* @0x20db24 ldr r1, [r10] */
/* @0x20db28 b 0x20db3c <_ZN7CDS_Map5ClearEv+0x44> */
/* @0x20db2c ldr r3, [r10, #0x4] */
/* @0x20db30 add r6, r6, #1 */
/* @0x20db34 cmp r6, r3 */
/* @0x20db38 bgt 0x20ddec <_ZN7CDS_Map5ClearEv+0x2f4> */
/* @0x20db3c ldr r5, [r1, r6, lsl #3] */
/* @0x20db40 cmp r5, #0 */
/* @0x20db44 beq 0x20db2c <_ZN7CDS_Map5ClearEv+0x34> */
/* @0x20db48 mov r7, #0 */
/* @0x20db4c mov r8, #5 */
/* @0x20db50 cmp r5, #0 */
/* @0x20db54 beq 0x20dc40 <_ZN7CDS_Map5ClearEv+0x148> */
/* @0x20db58 ldr r4, [r5, #0xc] */
/* @0x20db5c cmp r4, #0 */
/* @0x20db60 beq 0x20dc40 <_ZN7CDS_Map5ClearEv+0x148> */
/* @0x20db64 ldr r3, [r4, #0x1c] */
/* @0x20db68 uxth r1, r3 */
/* @0x20db6c cmp r1, #0 */
/* @0x20db70 bne 0x20dbb4 <_ZN7CDS_Map5ClearEv+0xbc> */
/* @0x20db74 tst r3, #-1073741824 */
/* @0x20db78 beq 0x20dbb4 <_ZN7CDS_Map5ClearEv+0xbc> */
/* @0x20db7c ldr r2, [r4, #0x10] */
/* @0x20db80 cmp r3, #0 */
/* @0x20db84 ldr r3, [r4, #0x14] */
/* @0x20db88 vmov d7, r2, r3 */
/* @0x20db8c vcvt.s32.f64 s15, d7 */
/* @0x20db90 vmov r2, s15 */
/* @0x20db94 blt 0x20dd44 <_ZN7CDS_Map5ClearEv+0x24c> */
/* @0x20db98 cmp r2, #0 */
/* @0x20db9c blt 0x20dbb4 <_ZN7CDS_Map5ClearEv+0xbc> */
/* @0x20dba0 ldr r3, [pc, #0x250] */
/* @0x20dba4 ldr r3, [r9, r3] */
/* @0x20dba8 ldr r3, [r3] */
/* @0x20dbac cmp r2, r3 */
/* @0x20dbb0 blt 0x20ddac <_ZN7CDS_Map5ClearEv+0x2b4> */
/* @0x20dbb4 ldr r3, [r4, #0xc] */
/* @0x20dbb8 sub r3, r3, #1 */
/* @0x20dbbc bic r3, r3, #-16777216 */
/* @0x20dbc0 bic r3, r3, #3 */
/* @0x20dbc4 cmp r3, #0 */
/* @0x20dbc8 beq 0x20dd38 <_ZN7CDS_Map5ClearEv+0x240> */
/* @0x20dbcc ldr r3, [r4, #0x1c] */
/* @0x20dbd0 str r7, [r4, #0x8] */
/* @0x20dbd4 sub r3, r3, #1 */
/* @0x20dbd8 str r8, [r4, #0xc] */
/* @0x20dbdc bic r3, r3, #-16777216 */
/* @0x20dbe0 str r7, [r4] */
/* @0x20dbe4 bic r3, r3, #3 */
/* @0x20dbe8 cmp r3, #0 */
/* @0x20dbec beq 0x20dd2c <_ZN7CDS_Map5ClearEv+0x234> */
/* @0x20dbf0 str r7, [r4, #0x10] */
/* @0x20dbf4 ldr r5, [r5, #0x4] */
/* @0x20dbf8 str r7, [r4, #0x18] */
/* @0x20dbfc cmp r5, #0 */
/* @0x20dc00 str r8, [r4, #0x1c] */
/* @0x20dc04 bne 0x20db50 <_ZN7CDS_Map5ClearEv+0x58> */
/* @0x20dc08 ldr r1, [r10, #0x4] */
/* @0x20dc0c add r3, r6, #1 */
/* @0x20dc10 cmp r3, r1 */
/* @0x20dc14 bgt 0x20dc40 <_ZN7CDS_Map5ClearEv+0x148> */
/* @0x20dc18 ldr r2, [r10] */
/* @0x20dc1c add r2, r2, r6, lsl #3 */
/* @0x20dc20 ldr r5, [r2, #0x8] */
/* @0x20dc24 mov r6, r3 */
/* @0x20dc28 add r2, r2, #8 */
/* @0x20dc2c add r3, r3, #1 */
/* @0x20dc30 cmp r5, #0 */
/* @0x20dc34 bne 0x20db50 <_ZN7CDS_Map5ClearEv+0x58> */
/* @0x20dc38 cmp r3, r1 */
/* @0x20dc3c ble 0x20dc20 <_ZN7CDS_Map5ClearEv+0x128> */
/* @0x20dc40 ldr r10, [r11] */
/* @0x20dc44 ldr r11, [r10, #0x4] */
/* @0x20dc48 cmp r11, #0 */
/* @0x20dc4c lslge r8, r11, #3 */
/* @0x20dc50 movge r7, #0 */
/* @0x20dc54 movge r9, #5 */
/* @0x20dc58 blt 0x20dd10 <_ZN7CDS_Map5ClearEv+0x218> */
/* @0x20dc5c ldr r3, [r10] */
/* @0x20dc60 add r2, r3, r8 */
/* @0x20dc64 ldr r4, [r3, r8] */
/* @0x20dc68 str r7, [r3, r8] */
/* @0x20dc6c cmp r4, #0 */
/* @0x20dc70 str r7, [r2, #0x4] */
/* @0x20dc74 beq 0x20dd00 <_ZN7CDS_Map5ClearEv+0x208> */
/* @0x20dc78 ldr r5, [r4, #0xc] */
/* @0x20dc7c ldr r6, [r4, #0x4] */
/* @0x20dc80 cmp r5, #0 */
/* @0x20dc84 beq 0x20dce0 <_ZN7CDS_Map5ClearEv+0x1e8> */
/* @0x20dc88 ldr r3, [r5, #0xc] */
/* @0x20dc8c sub r3, r3, #1 */
/* @0x20dc90 bic r3, r3, #-16777216 */
/* @0x20dc94 bic r3, r3, #3 */
/* @0x20dc98 cmp r3, #0 */
/* @0x20dc9c beq 0x20dd20 <_ZN7CDS_Map5ClearEv+0x228> */
/* @0x20dca0 ldr r3, [r5, #0x1c] */
/* @0x20dca4 str r7, [r5, #0x8] */
/* @0x20dca8 sub r3, r3, #1 */
/* @0x20dcac str r9, [r5, #0xc] */
/* @0x20dcb0 bic r3, r3, #-16777216 */
/* @0x20dcb4 str r7, [r5] */
/* @0x20dcb8 bic r3, r3, #3 */
/* @0x20dcbc cmp r3, #0 */
/* @0x20dcc0 bne 0x20dccc <_ZN7CDS_Map5ClearEv+0x1d4> */
/* @0x20dcc4 add r0, r5, #16 */
/* @0x20dcc8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20dccc str r7, [r5, #0x18] */
/* @0x20dcd0 mov r0, r5 */
/* @0x20dcd4 str r9, [r5, #0x1c] */
/* @0x20dcd8 str r7, [r5, #0x10] */
/* @0x20dcdc bl 0x27d1d0 <_ZdlPv> */
/* @0x20dce0 mov r0, r4 */
/* @0x20dce4 mov r4, r6 */
/* @0x20dce8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x20dcec ldr r3, [r10, #0x8] */
/* @0x20dcf0 cmp r6, #0 */
/* @0x20dcf4 sub r3, r3, #1 */
/* @0x20dcf8 str r3, [r10, #0x8] */
/* @0x20dcfc bne 0x20dc78 <_ZN7CDS_Map5ClearEv+0x180> */
/* @0x20dd00 sub r11, r11, #1 */
/* @0x20dd04 sub r8, r8, #8 */
/* @0x20dd08 cmn r11, #1 */
/* @0x20dd0c bne 0x20dc5c <_ZN7CDS_Map5ClearEv+0x164> */
/* @0x20dd10 add r0, sp, #28 */
/* @0x20dd14 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x20dd18 add sp, sp, #36 */
/* @0x20dd1c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x20dd20 mov r0, r5 */
/* @0x20dd24 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20dd28 b 0x20dca0 <_ZN7CDS_Map5ClearEv+0x1a8> */
/* @0x20dd2c add r0, r4, #16 */
/* @0x20dd30 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20dd34 b 0x20dbf0 <_ZN7CDS_Map5ClearEv+0xf8> */
/* @0x20dd38 mov r0, r4 */
/* @0x20dd3c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20dd40 b 0x20dbcc <_ZN7CDS_Map5ClearEv+0xd4> */
/* @0x20dd44 cmp r2, #0 */
/* @0x20dd48 blt 0x20dbb4 <_ZN7CDS_Map5ClearEv+0xbc> */
/* @0x20dd4c ldr r3, [pc, #0xa8] */
/* @0x20dd50 ldr r3, [r9, r3] */
/* @0x20dd54 ldr r3, [r3] */
/* @0x20dd58 cmp r2, r3 */
/* @0x20dd5c bge 0x20dbb4 <_ZN7CDS_Map5ClearEv+0xbc> */
/* @0x20dd60 ldr r3, [pc, #0x98] */
/* @0x20dd64 ldr r12, [r9, r3] */
/* @0x20dd68 ldr r3, [r12, #0x4] */
/* @0x20dd6c ldr r3, [r3, r2, lsl #2] */
/* @0x20dd70 cmp r3, #0 */
/* @0x20dd74 beq 0x20dbb4 <_ZN7CDS_Map5ClearEv+0xbc> */
/* @0x20dd78 mov r0, r3 */
/* @0x20dd7c stmib sp, {r1, r2} */
/* @0x20dd80 str r12, [sp, #0xc] */
/* @0x20dd84 str r3, [sp, #0x10] */
/* @0x20dd88 bl 0x20d9e8 <_ZN7CDS_MapD2Ev> */
/* @0x20dd8c ldr r3, [sp, #0x10] */
/* @0x20dd90 mov r0, r3 */
/* @0x20dd94 bl 0x27d1d0 <_ZdlPv> */
/* @0x20dd98 ldr r12, [sp, #0xc] */
/* @0x20dd9c ldmib sp, {r1, r2} */
/* @0x20dda0 ldr r3, [r12, #0x4] */
/* @0x20dda4 str r1, [r3, r2, lsl #2] */
/* @0x20dda8 b 0x20dbb4 <_ZN7CDS_Map5ClearEv+0xbc> */
/* @0x20ddac ldr r3, [pc, #0x50] */
/* @0x20ddb0 ldr r3, [r9, r3] */
/* @0x20ddb4 ldr r0, [r3, #0x4] */
/* @0x20ddb8 ldr r0, [r0, r2, lsl #2] */
/* @0x20ddbc cmp r0, #0 */
/* @0x20ddc0 beq 0x20dbb4 <_ZN7CDS_Map5ClearEv+0xbc> */
/* @0x20ddc4 ldr r12, [r0] */
/* @0x20ddc8 ldr r12, [r12, #0x4] */
/* @0x20ddcc stmib sp, {r1, r2} */
/* @0x20ddd0 str r3, [sp, #0x10] */
/* @0x20ddd4 blx r12 */
/* @0x20ddd8 ldr r3, [sp, #0x10] */
/* @0x20dddc ldmib sp, {r1, r2} */
/* @0x20dde0 ldr r3, [r3, #0x4] */
/* @0x20dde4 str r1, [r3, r2, lsl #2] */
/* @0x20dde8 b 0x20dbb4 <_ZN7CDS_Map5ClearEv+0xbc> */
/* @0x20ddec mvn r6, #0 */
/* @0x20ddf0 b 0x20db48 <_ZN7CDS_Map5ClearEv+0x50> */
/* @0x20ddf4 andseq r4, lr, r0, lsr r1 */
/* @0x20ddf8 .word 0xffffc02c */
/* @0x20ddfc .word 0xffffc028 */
/* @0x20de00 .word 0xffffbcec */
/* @0x20de04 .word 0xffffc030 */

/* ── FUNC 0x20de08 · CDS_Map::ReadFromString(char const*, bool) · size=1648 · insn=412 */
/* @0x20de08 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x20de0c sub sp, sp, #68 */
/* @0x20de10 mov r7, r1 */
/* @0x20de14 str r0, [sp, #0x8] */
/* @0x20de18 bl 0x20daf8 <_ZN7CDS_Map5ClearEv> */
/* @0x20de1c cmp r7, #0 */
/* @0x20de20 beq 0x20de90 <_ZN7CDS_Map14ReadFromStringEPKcb+0x88> */
/* @0x20de24 mov r0, r7 */
/* @0x20de28 bl 0xb6538 <strlen@plt> */
/* @0x20de2c cmp r0, #1 */
/* @0x20de30 bls 0x20de90 <_ZN7CDS_Map14ReadFromStringEPKcb+0x88> */
/* @0x20de34 ldrb r3, [r7, #0x1] */
/* @0x20de38 cmp r3, #58 */
/* @0x20de3c beq 0x20de9c <_ZN7CDS_Map14ReadFromStringEPKcb+0x94> */
/* @0x20de40 mov r0, #32 */
/* @0x20de44 bl 0x27c524 <_Znwj> */
/* @0x20de48 mov r1, #0 */
/* @0x20de4c mov r5, r0 */
/* @0x20de50 bl 0x2010ec <_ZN7CStreamC2Ei> */
/* @0x20de54 mov r0, r5 */
/* @0x20de58 mov r1, r7 */
/* @0x20de5c bl 0x2025b0 <_ZN7CStream17ConvertFromStringEPKc> */
/* @0x20de60 mov r0, r5 */
/* @0x20de64 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x20de68 sub r0, r0, #400 */
/* @0x20de6c sub r0, r0, #1 */
/* @0x20de70 cmp r0, #1 */
/* @0x20de74 bls 0x20e324 <_ZN7CDS_Map14ReadFromStringEPKcb+0x51c> */
/* @0x20de78 cmp r5, #0 */
/* @0x20de7c beq 0x20de90 <_ZN7CDS_Map14ReadFromStringEPKcb+0x88> */
/* @0x20de80 mov r0, r5 */
/* @0x20de84 bl 0x201328 <_ZN7CStreamD2Ev> */
/* @0x20de88 mov r0, r5 */
/* @0x20de8c bl 0x27d1d0 <_ZdlPv> */
/* @0x20de90 mov r0, #0 */
/* @0x20de94 add sp, sp, #68 */
/* @0x20de98 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x20de9c ldrb r3, [r7] */
/* @0x20dea0 cmp r3, #0 */
/* @0x20dea4 beq 0x20e188 <_ZN7CDS_Map14ReadFromStringEPKcb+0x380> */
/* @0x20dea8 ldr r1, [pc, #0x5b4] */
/* @0x20deac ldr r6, [pc, #0x5b4] */
/* @0x20deb0 add r1, pc, r1 */
/* @0x20deb4 ldr r2, [pc, #0x5b0] */
/* @0x20deb8 str r1, [sp, #0x14] */
/* @0x20debc add r6, pc, r6 */
/* @0x20dec0 ldr r3, [pc, #0x5a8] */
/* @0x20dec4 add r2, pc, r2 */
/* @0x20dec8 ldr r1, [pc, #0x5a4] */
/* @0x20decc add r3, pc, r3 */
/* @0x20ded0 str r2, [sp, #0xc] */
/* @0x20ded4 add r1, pc, r1 */
/* @0x20ded8 str r3, [sp, #0x18] */
/* @0x20dedc str r1, [sp, #0x10] */
/* @0x20dee0 mov r0, #32 */
/* @0x20dee4 mov r8, r7 */
/* @0x20dee8 bl 0x27c524 <_Znwj> */
/* @0x20deec mov r1, #0 */
/* @0x20def0 mov r2, #16 */
/* @0x20def4 add r5, r0, #16 */
/* @0x20def8 mov r4, r0 */
/* @0x20defc bl 0xb65b0 <memset@plt> */
/* @0x20df00 mov r2, #16 */
/* @0x20df04 mov r0, r5 */
/* @0x20df08 mov r1, #0 */
/* @0x20df0c bl 0xb65b0 <memset@plt> */
/* @0x20df10 ldrb r9, [r8], #2 */
/* @0x20df14 sub r9, r9, #48 */
/* @0x20df18 and r3, r9, #1 */
/* @0x20df1c ubfx r9, r9, #0x1, #0x1 */
/* @0x20df20 ands r2, r3, #255 */
/* @0x20df24 str r3, [r4, #0xc] */
/* @0x20df28 str r9, [r4, #0x1c] */
/* @0x20df2c beq 0x20e228 <_ZN7CDS_Map14ReadFromStringEPKcb+0x420> */
/* @0x20df30 ldrb r3, [r7, #0x2] */
/* @0x20df34 add r7, r7, #3 */
/* @0x20df38 cmp r3, #44 */
/* @0x20df3c cmpne r3, #58 */
/* @0x20df40 movne r10, #0 */
/* @0x20df44 moveq r10, #1 */
/* @0x20df48 beq 0x20e2dc <_ZN7CDS_Map14ReadFromStringEPKcb+0x4d4> */
/* @0x20df4c cmp r3, #0 */
/* @0x20df50 beq 0x20e2dc <_ZN7CDS_Map14ReadFromStringEPKcb+0x4d4> */
/* @0x20df54 mov r2, r7 */
/* @0x20df58 b 0x20df64 <_ZN7CDS_Map14ReadFromStringEPKcb+0x15c> */
/* @0x20df5c cmp r3, #0 */
/* @0x20df60 beq 0x20df78 <_ZN7CDS_Map14ReadFromStringEPKcb+0x170> */
/* @0x20df64 ldrb r3, [r2], #1 */
/* @0x20df68 add r10, r10, #1 */
/* @0x20df6c cmp r3, #58 */
/* @0x20df70 cmpne r3, #44 */
/* @0x20df74 bne 0x20df5c <_ZN7CDS_Map14ReadFromStringEPKcb+0x154> */
/* @0x20df78 asr r10, r10, #1 */
/* @0x20df7c ldr r1, [sp, #0xc] */
/* @0x20df80 add r0, r10, #1 */
/* @0x20df84 movw r2, #0x76a */
/* @0x20df88 mov r3, #1 */
/* @0x20df8c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x20df90 cmp r10, #0 */
/* @0x20df94 moveq r10, r8 */
/* @0x20df98 mov r1, r0 */
/* @0x20df9c moveq r0, r0 */
/* @0x20dfa0 beq 0x20e000 <_ZN7CDS_Map14ReadFromStringEPKcb+0x1f8> */
/* @0x20dfa4 add r0, r1, r10 */
/* @0x20dfa8 mov r3, r8 */
/* @0x20dfac mov r12, r1 */
/* @0x20dfb0 ldrb r2, [r3] */
/* @0x20dfb4 add r3, r3, #2 */
/* @0x20dfb8 sub r7, r2, #55 */
/* @0x20dfbc cmp r2, #64 */
/* @0x20dfc0 sub lr, r2, #48 */
/* @0x20dfc4 ldrb r2, [r3, #-0x1] */
/* @0x20dfc8 lsl lr, lr, #4 */
/* @0x20dfcc sub r11, r2, #55 */
/* @0x20dfd0 lslhi lr, r7, #4 */
/* @0x20dfd4 cmp r2, #64 */
/* @0x20dfd8 sub r7, r2, #48 */
/* @0x20dfdc orr r2, lr, r11 */
/* @0x20dfe0 orrls r2, lr, r7 */
/* @0x20dfe4 strb r2, [r12], #1 */
/* @0x20dfe8 cmp r12, r0 */
/* @0x20dfec bne 0x20dfb0 <_ZN7CDS_Map14ReadFromStringEPKcb+0x1a8> */
/* @0x20dff0 lsl r10, r10, #1 */
/* @0x20dff4 add r7, r8, r10 */
/* @0x20dff8 mov r10, r7 */
/* @0x20dffc add r7, r7, #1 */
/* @0x20e000 mov r8, #0 */
/* @0x20e004 strb r8, [r0] */
/* @0x20e008 mov r0, r4 */
/* @0x20e00c bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x20e010 ldr r3, [r4, #0xc] */
/* @0x20e014 bic r3, r3, #-16777216 */
/* @0x20e018 cmp r3, #1 */
/* @0x20e01c movne r0, r8 */
/* @0x20e020 beq 0x20e2cc <_ZN7CDS_Map14ReadFromStringEPKcb+0x4c4> */
/* @0x20e024 bl 0x27dfa8 <_Z14CalcCRC_stringPKc> */
/* @0x20e028 mov r8, r0 */
/* @0x20e02c cmp r9, #0 */
/* @0x20e030 beq 0x20e194 <_ZN7CDS_Map14ReadFromStringEPKcb+0x38c> */
/* @0x20e034 ldrb r3, [r10, #0x1] */
/* @0x20e038 add r10, r10, #2 */
/* @0x20e03c cmp r3, #44 */
/* @0x20e040 cmpne r3, #58 */
/* @0x20e044 movne r9, #0 */
/* @0x20e048 moveq r9, #1 */
/* @0x20e04c beq 0x20e304 <_ZN7CDS_Map14ReadFromStringEPKcb+0x4fc> */
/* @0x20e050 cmp r3, #0 */
/* @0x20e054 bne 0x20e064 <_ZN7CDS_Map14ReadFromStringEPKcb+0x25c> */
/* @0x20e058 b 0x20e304 <_ZN7CDS_Map14ReadFromStringEPKcb+0x4fc> */
/* @0x20e05c cmp r3, #0 */
/* @0x20e060 beq 0x20e078 <_ZN7CDS_Map14ReadFromStringEPKcb+0x270> */
/* @0x20e064 ldrb r3, [r10], #1 */
/* @0x20e068 add r9, r9, #1 */
/* @0x20e06c cmp r3, #58 */
/* @0x20e070 cmpne r3, #44 */
/* @0x20e074 bne 0x20e05c <_ZN7CDS_Map14ReadFromStringEPKcb+0x254> */
/* @0x20e078 asr r9, r9, #1 */
/* @0x20e07c ldr r1, [sp, #0x10] */
/* @0x20e080 add r0, r9, #1 */
/* @0x20e084 movw r2, #0x76a */
/* @0x20e088 mov r3, #1 */
/* @0x20e08c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x20e090 cmp r9, #0 */
/* @0x20e094 mov r1, r0 */
/* @0x20e098 moveq r11, r0 */
/* @0x20e09c beq 0x20e0f0 <_ZN7CDS_Map14ReadFromStringEPKcb+0x2e8> */
/* @0x20e0a0 add r11, r0, r9 */
/* @0x20e0a4 mov r3, r7 */
/* @0x20e0a8 mov r12, r0 */
/* @0x20e0ac ldrb r2, [r3] */
/* @0x20e0b0 add r3, r3, #2 */
/* @0x20e0b4 sub lr, r2, #55 */
/* @0x20e0b8 cmp r2, #64 */
/* @0x20e0bc sub r0, r2, #48 */
/* @0x20e0c0 ldrb r2, [r3, #-0x1] */
/* @0x20e0c4 lsl r0, r0, #4 */
/* @0x20e0c8 sub r10, r2, #55 */
/* @0x20e0cc lslhi r0, lr, #4 */
/* @0x20e0d0 cmp r2, #64 */
/* @0x20e0d4 sub lr, r2, #48 */
/* @0x20e0d8 orr r2, r0, r10 */
/* @0x20e0dc orrls r2, r0, lr */
/* @0x20e0e0 strb r2, [r12], #1 */
/* @0x20e0e4 cmp r12, r11 */
/* @0x20e0e8 bne 0x20e0ac <_ZN7CDS_Map14ReadFromStringEPKcb+0x2a4> */
/* @0x20e0ec add r7, r7, r9, lsl #1 */
/* @0x20e0f0 mov r3, #0 */
/* @0x20e0f4 mov r0, r5 */
/* @0x20e0f8 strb r3, [r11] */
/* @0x20e0fc bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x20e100 ldr r2, [sp, #0x8] */
/* @0x20e104 mov r1, r6 */
/* @0x20e108 mov r3, #1 */
/* @0x20e10c mov r0, #16 */
/* @0x20e110 ldr r5, [r2] */
/* @0x20e114 movw r2, #0x132 */
/* @0x20e118 ldm r5, {r9, r10} */
/* @0x20e11c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x20e120 and r10, r8, r10 */
/* @0x20e124 ldr r2, [r9, r10, lsl #3] */
/* @0x20e128 add r3, r9, r10, lsl #3 */
/* @0x20e12c cmp r2, #0 */
/* @0x20e130 ldrne r2, [r3, #0x4] */
/* @0x20e134 movne r1, #0 */
/* @0x20e138 str r8, [r0, #0x8] */
/* @0x20e13c str r4, [r0, #0xc] */
/* @0x20e140 strne r2, [r0] */
/* @0x20e144 streq r0, [r3, #0x4] */
/* @0x20e148 strne r0, [r2, #0x4] */
/* @0x20e14c strne r0, [r3, #0x4] */
/* @0x20e150 ldr r3, [r5, #0x8] */
/* @0x20e154 streq r0, [r9, r10, lsl #3] */
/* @0x20e158 strne r1, [r0, #0x4] */
/* @0x20e15c add r3, r3, #1 */
/* @0x20e160 streq r2, [r0, #0x4] */
/* @0x20e164 streq r2, [r0] */
/* @0x20e168 str r3, [r5, #0x8] */
/* @0x20e16c ldrb r3, [r7] */
/* @0x20e170 cmp r3, #0 */
/* @0x20e174 beq 0x20e188 <_ZN7CDS_Map14ReadFromStringEPKcb+0x380> */
/* @0x20e178 ldrb r3, [r7, #0x1] */
/* @0x20e17c add r7, r7, #1 */
/* @0x20e180 cmp r3, #0 */
/* @0x20e184 bne 0x20dee0 <_ZN7CDS_Map14ReadFromStringEPKcb+0xd8> */
/* @0x20e188 mov r0, #1 */
/* @0x20e18c add sp, sp, #68 */
/* @0x20e190 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x20e194 str r9, [sp, #0x34] */
/* @0x20e198 str r9, [sp, #0x30] */
/* @0x20e19c ldrb r3, [r10, #0x1] */
/* @0x20e1a0 cmp r3, #44 */
/* @0x20e1a4 cmpne r3, #0 */
/* @0x20e1a8 beq 0x20e214 <_ZN7CDS_Map14ReadFromStringEPKcb+0x40c> */
/* @0x20e1ac cmp r3, #58 */
/* @0x20e1b0 addne r12, sp, #56 */
/* @0x20e1b4 movne r2, r7 */
/* @0x20e1b8 bne 0x20e1c8 <_ZN7CDS_Map14ReadFromStringEPKcb+0x3c0> */
/* @0x20e1bc b 0x20e214 <_ZN7CDS_Map14ReadFromStringEPKcb+0x40c> */
/* @0x20e1c0 cmp r3, #58 */
/* @0x20e1c4 beq 0x20e214 <_ZN7CDS_Map14ReadFromStringEPKcb+0x40c> */
/* @0x20e1c8 sub r1, r3, #55 */
/* @0x20e1cc cmp r3, #64 */
/* @0x20e1d0 sub r0, r3, #48 */
/* @0x20e1d4 ldrb r3, [r2, #0x1] */
/* @0x20e1d8 lsl r0, r0, #4 */
/* @0x20e1dc sub r5, r3, #55 */
/* @0x20e1e0 lslhi r0, r1, #4 */
/* @0x20e1e4 sub lr, r3, #48 */
/* @0x20e1e8 cmp r3, #64 */
/* @0x20e1ec orr r3, r0, lr */
/* @0x20e1f0 orrhi r3, r0, r5 */
/* @0x20e1f4 strb r3, [r12, #-0x1]! */
/* @0x20e1f8 ldrb r3, [r2, #0x2] */
/* @0x20e1fc add r1, r2, #2 */
/* @0x20e200 cmp r3, #0 */
/* @0x20e204 cmpne r3, #44 */
/* @0x20e208 mov r7, r1 */
/* @0x20e20c mov r2, r1 */
/* @0x20e210 bne 0x20e1c0 <_ZN7CDS_Map14ReadFromStringEPKcb+0x3b8> */
/* @0x20e214 ldr r2, [sp, #0x30] */
/* @0x20e218 ldr r3, [sp, #0x34] */
/* @0x20e21c str r2, [r4, #0x10] */
/* @0x20e220 str r3, [r4, #0x14] */
/* @0x20e224 b 0x20e100 <_ZN7CDS_Map14ReadFromStringEPKcb+0x2f8> */
/* @0x20e228 str r2, [sp, #0x34] */
/* @0x20e22c str r2, [sp, #0x30] */
/* @0x20e230 ldrb r3, [r7, #0x2] */
/* @0x20e234 cmp r3, #44 */
/* @0x20e238 cmpne r3, #0 */
/* @0x20e23c beq 0x20e2fc <_ZN7CDS_Map14ReadFromStringEPKcb+0x4f4> */
/* @0x20e240 cmp r3, #58 */
/* @0x20e244 addne r0, sp, #56 */
/* @0x20e248 bne 0x20e258 <_ZN7CDS_Map14ReadFromStringEPKcb+0x450> */
/* @0x20e24c b 0x20e2fc <_ZN7CDS_Map14ReadFromStringEPKcb+0x4f4> */
/* @0x20e250 cmp r3, #58 */
/* @0x20e254 beq 0x20e2a4 <_ZN7CDS_Map14ReadFromStringEPKcb+0x49c> */
/* @0x20e258 sub r2, r3, #55 */
/* @0x20e25c cmp r3, #64 */
/* @0x20e260 sub r1, r3, #48 */
/* @0x20e264 ldrb r3, [r8, #0x1] */
/* @0x20e268 lsl r1, r1, #4 */
/* @0x20e26c sub lr, r3, #55 */
/* @0x20e270 lslhi r1, r2, #4 */
/* @0x20e274 sub r12, r3, #48 */
/* @0x20e278 cmp r3, #64 */
/* @0x20e27c orr r3, r1, r12 */
/* @0x20e280 orrhi r3, r1, lr */
/* @0x20e284 strb r3, [r0, #-0x1]! */
/* @0x20e288 ldrb r3, [r8, #0x2] */
/* @0x20e28c add r2, r8, #2 */
/* @0x20e290 cmp r3, #0 */
/* @0x20e294 cmpne r3, #44 */
/* @0x20e298 mov r10, r2 */
/* @0x20e29c mov r8, r2 */
/* @0x20e2a0 bne 0x20e250 <_ZN7CDS_Map14ReadFromStringEPKcb+0x448> */
/* @0x20e2a4 ldr r2, [sp, #0x30] */
/* @0x20e2a8 mov r0, r4 */
/* @0x20e2ac ldr r3, [sp, #0x34] */
/* @0x20e2b0 mov r1, #8 */
/* @0x20e2b4 add r7, r10, #1 */
/* @0x20e2b8 str r2, [r4] */
/* @0x20e2bc str r3, [r4, #0x4] */
/* @0x20e2c0 bl 0x27dfa0 <_Z7CalcCRCPKci> */
/* @0x20e2c4 mov r8, r0 */
/* @0x20e2c8 b 0x20e02c <_ZN7CDS_Map14ReadFromStringEPKcb+0x224> */
/* @0x20e2cc ldr r0, [r4] */
/* @0x20e2d0 cmp r0, r8 */
/* @0x20e2d4 ldrne r0, [r0] */
/* @0x20e2d8 b 0x20e024 <_ZN7CDS_Map14ReadFromStringEPKcb+0x21c> */
/* @0x20e2dc mov r0, #1 */
/* @0x20e2e0 ldr r1, [sp, #0x14] */
/* @0x20e2e4 mov r3, r0 */
/* @0x20e2e8 movw r2, #0x76a */
/* @0x20e2ec bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x20e2f0 mov r10, r8 */
/* @0x20e2f4 mov r1, r0 */
/* @0x20e2f8 b 0x20e000 <_ZN7CDS_Map14ReadFromStringEPKcb+0x1f8> */
/* @0x20e2fc mov r10, r8 */
/* @0x20e300 b 0x20e2a4 <_ZN7CDS_Map14ReadFromStringEPKcb+0x49c> */
/* @0x20e304 mov r0, #1 */
/* @0x20e308 ldr r1, [sp, #0x18] */
/* @0x20e30c mov r3, r0 */
/* @0x20e310 movw r2, #0x76a */
/* @0x20e314 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x20e318 mov r11, r0 */
/* @0x20e31c mov r1, r0 */
/* @0x20e320 b 0x20e0f0 <_ZN7CDS_Map14ReadFromStringEPKcb+0x2e8> */
/* @0x20e324 mov r0, r5 */
/* @0x20e328 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x20e32c subs r10, r0, #0 */
/* @0x20e330 ble 0x20e434 <_ZN7CDS_Map14ReadFromStringEPKcb+0x62c> */
/* @0x20e334 add r8, sp, #32 */
/* @0x20e338 add r3, sp, #48 */
/* @0x20e33c mov r11, #0 */
/* @0x20e340 add r1, sp, #36 */
/* @0x20e344 add r2, sp, #40 */
/* @0x20e348 str r1, [sp, #0xc] */
/* @0x20e34c str r2, [sp, #0x10] */
/* @0x20e350 add r1, sp, #44 */
/* @0x20e354 add r2, sp, #52 */
/* @0x20e358 str r1, [sp, #0x14] */
/* @0x20e35c add r9, sp, #56 */
/* @0x20e360 add r1, sp, #60 */
/* @0x20e364 str r2, [sp, #0x18] */
/* @0x20e368 mov r7, r8 */
/* @0x20e36c str r1, [sp, #0x1c] */
/* @0x20e370 mov r6, r3 */
/* @0x20e374 mov r4, r11 */
/* @0x20e378 b 0x20e3ac <_ZN7CDS_Map14ReadFromStringEPKcb+0x5a4> */
/* @0x20e37c ldr r2, [sp, #0x3c] */
/* @0x20e380 mov r1, #5 */
/* @0x20e384 str r4, [sp, #0x28] */
/* @0x20e388 sub r2, r2, #1 */
/* @0x20e38c str r1, [sp, #0x2c] */
/* @0x20e390 bic r2, r2, #-16777216 */
/* @0x20e394 str r4, [sp, #0x20] */
/* @0x20e398 bic r2, r2, #3 */
/* @0x20e39c cmp r2, #0 */
/* @0x20e3a0 beq 0x20e450 <_ZN7CDS_Map14ReadFromStringEPKcb+0x648> */
/* @0x20e3a4 cmp r11, r10 */
/* @0x20e3a8 beq 0x20e434 <_ZN7CDS_Map14ReadFromStringEPKcb+0x62c> */
/* @0x20e3ac mov r0, r7 */
/* @0x20e3b0 mov r1, r5 */
/* @0x20e3b4 mov r2, #0 */
/* @0x20e3b8 str r4, [r3] */
/* @0x20e3bc str r4, [r8] */
/* @0x20e3c0 add r11, r11, #1 */
/* @0x20e3c4 str r4, [sp, #0x24] */
/* @0x20e3c8 mov r8, r7 */
/* @0x20e3cc str r4, [sp, #0x28] */
/* @0x20e3d0 str r4, [sp, #0x2c] */
/* @0x20e3d4 str r4, [sp, #0x34] */
/* @0x20e3d8 str r4, [r9] */
/* @0x20e3dc str r4, [sp, #0x3c] */
/* @0x20e3e0 bl 0x208638 <_Z9ReadValueR6RValueR7CStreami> */
/* @0x20e3e4 mov r0, r6 */
/* @0x20e3e8 mov r1, r5 */
/* @0x20e3ec mov r2, #0 */
/* @0x20e3f0 bl 0x208638 <_Z9ReadValueR6RValueR7CStreami> */
/* @0x20e3f4 mov r2, r6 */
/* @0x20e3f8 ldr r0, [sp, #0x8] */
/* @0x20e3fc mov r1, r7 */
/* @0x20e400 bl 0x20b884 <_ZN7CDS_Map3AddEP6RValueS1_> */
/* @0x20e404 ldr r2, [sp, #0x2c] */
/* @0x20e408 mov r3, r6 */
/* @0x20e40c sub r2, r2, #1 */
/* @0x20e410 bic r2, r2, #-16777216 */
/* @0x20e414 bic r2, r2, #3 */
/* @0x20e418 cmp r2, #0 */
/* @0x20e41c bne 0x20e37c <_ZN7CDS_Map14ReadFromStringEPKcb+0x574> */
/* @0x20e420 mov r0, r7 */
/* @0x20e424 str r6, [sp, #0x4] */
/* @0x20e428 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20e42c ldr r3, [sp, #0x4] */
/* @0x20e430 b 0x20e37c <_ZN7CDS_Map14ReadFromStringEPKcb+0x574> */
/* @0x20e434 cmp r5, #0 */
/* @0x20e438 beq 0x20e188 <_ZN7CDS_Map14ReadFromStringEPKcb+0x380> */
/* @0x20e43c mov r0, r5 */
/* @0x20e440 bl 0x201328 <_ZN7CStreamD2Ev> */
/* @0x20e444 mov r0, r5 */
/* @0x20e448 bl 0x27d1d0 <_ZdlPv> */
/* @0x20e44c b 0x20e188 <_ZN7CDS_Map14ReadFromStringEPKcb+0x380> */
/* @0x20e450 mov r0, r6 */
/* @0x20e454 str r3, [sp, #0x4] */
/* @0x20e458 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20e45c ldr r3, [sp, #0x4] */
/* @0x20e460 b 0x20e3a4 <_ZN7CDS_Map14ReadFromStringEPKcb+0x59c> */
/* @0x20e464 andseq r5, r4, r12, lsr r9 */
/* @0x20e468 ldrsheq lr, [r3], -r0 */
/* @0x20e46c andseq r5, r4, r8, lsr #18 */
/* @0x20e470 andseq r5, r4, r0, lsr #18 */
/* @0x20e474 andseq r5, r4, r8, lsl r9 */

/* ── FUNC 0x20e478 · CDS_List::Clear() · size=420 · insn=105 */
/* @0x20e478 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x20e47c sub sp, sp, #28 */
/* @0x20e480 add r7, sp, #20 */
/* @0x20e484 mov r10, r0 */
/* @0x20e488 ldr r6, [pc, #0x178] */
/* @0x20e48c mov r0, r7 */
/* @0x20e490 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0x20e494 ldr r3, [r10, #0x4] */
/* @0x20e498 add r6, pc, r6 */
/* @0x20e49c cmp r3, #0 */
/* @0x20e4a0 movgt r5, #0 */
/* @0x20e4a4 movgt r11, #5 */
/* @0x20e4a8 movgt r9, r5 */
/* @0x20e4ac ble 0x20e5a0 <_ZN8CDS_List5ClearEv+0x128> */
/* @0x20e4b0 ldr r0, [r10, #0xc] */
/* @0x20e4b4 lsl r1, r5, #4 */
/* @0x20e4b8 add r4, r0, r1 */
/* @0x20e4bc ldr r3, [r4, #0xc] */
/* @0x20e4c0 uxth r8, r3 */
/* @0x20e4c4 cmp r8, #0 */
/* @0x20e4c8 bne 0x20e554 <_ZN8CDS_List5ClearEv+0xdc> */
/* @0x20e4cc tst r3, #-1073741824 */
/* @0x20e4d0 beq 0x20e580 <_ZN8CDS_List5ClearEv+0x108> */
/* @0x20e4d4 ldr r2, [r0, r1] */
/* @0x20e4d8 cmp r3, #0 */
/* @0x20e4dc ldr r3, [r4, #0x4] */
/* @0x20e4e0 vmov d7, r2, r3 */
/* @0x20e4e4 vcvt.s32.f64 s15, d7 */
/* @0x20e4e8 vmov r2, s15 */
/* @0x20e4ec blt 0x20e578 <_ZN8CDS_List5ClearEv+0x100> */
/* @0x20e4f0 cmp r2, #0 */
/* @0x20e4f4 blt 0x20e580 <_ZN8CDS_List5ClearEv+0x108> */
/* @0x20e4f8 ldr r3, [pc, #0x10c] */
/* @0x20e4fc ldr r3, [r6, r3] */
/* @0x20e500 ldr r3, [r3] */
/* @0x20e504 cmp r2, r3 */
/* @0x20e508 bge 0x20e580 <_ZN8CDS_List5ClearEv+0x108> */
/* @0x20e50c ldr r3, [pc, #0xfc] */
/* @0x20e510 ldr r3, [r6, r3] */
/* @0x20e514 ldr r0, [r3, #0x4] */
/* @0x20e518 ldr r0, [r0, r2, lsl #2] */
/* @0x20e51c cmp r0, #0 */
/* @0x20e520 beq 0x20e580 <_ZN8CDS_List5ClearEv+0x108> */
/* @0x20e524 ldr r12, [r0] */
/* @0x20e528 ldr r12, [r12, #0x4] */
/* @0x20e52c stm sp, {r1, r2, r3} */
/* @0x20e530 blx r12 */
/* @0x20e534 ldr r3, [sp, #0x8] */
/* @0x20e538 ldr r3, [r3, #0x4] */
/* @0x20e53c ldr r2, [sp, #0x4] */
/* @0x20e540 ldr r1, [sp] */
/* @0x20e544 str r8, [r3, r2, lsl #2] */
/* @0x20e548 ldr r4, [r10, #0xc] */
/* @0x20e54c add r4, r4, r1 */
/* @0x20e550 ldrh r8, [r4, #12] */
/* @0x20e554 sub r3, r8, #1 */
/* @0x20e558 str r8, [r4, #0xc] */
/* @0x20e55c bic r3, r3, #-16777216 */
/* @0x20e560 bic r3, r3, #3 */
/* @0x20e564 cmp r3, #0 */
/* @0x20e568 bne 0x20e584 <_ZN8CDS_List5ClearEv+0x10c> */
/* @0x20e56c mov r0, r4 */
/* @0x20e570 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20e574 b 0x20e584 <_ZN8CDS_List5ClearEv+0x10c> */
/* @0x20e578 cmp r2, #0 */
/* @0x20e57c bge 0x20e5b8 <_ZN8CDS_List5ClearEv+0x140> */
/* @0x20e580 str r9, [r4, #0xc] */
/* @0x20e584 str r9, [r4] */
/* @0x20e588 add r5, r5, #1 */
/* @0x20e58c ldr r3, [r10, #0x4] */
/* @0x20e590 str r9, [r4, #0x8] */
/* @0x20e594 cmp r3, r5 */
/* @0x20e598 str r11, [r4, #0xc] */
/* @0x20e59c bgt 0x20e4b0 <_ZN8CDS_List5ClearEv+0x38> */
/* @0x20e5a0 mov r3, #0 */
/* @0x20e5a4 mov r0, r7 */
/* @0x20e5a8 str r3, [r10, #0x4] */
/* @0x20e5ac bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x20e5b0 add sp, sp, #28 */
/* @0x20e5b4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x20e5b8 ldr r3, [pc, #0x54] */
/* @0x20e5bc ldr r3, [r6, r3] */
/* @0x20e5c0 ldr r3, [r3] */
/* @0x20e5c4 cmp r2, r3 */
/* @0x20e5c8 bge 0x20e580 <_ZN8CDS_List5ClearEv+0x108> */
/* @0x20e5cc ldr r3, [pc, #0x44] */
/* @0x20e5d0 ldr r12, [r6, r3] */
/* @0x20e5d4 ldr r3, [r12, #0x4] */
/* @0x20e5d8 ldr r3, [r3, r2, lsl #2] */
/* @0x20e5dc cmp r3, #0 */
/* @0x20e5e0 beq 0x20e580 <_ZN8CDS_List5ClearEv+0x108> */
/* @0x20e5e4 mov r0, r3 */
/* @0x20e5e8 stm sp, {r1, r2, r3, r12} */
/* @0x20e5ec bl 0x20d9e8 <_ZN7CDS_MapD2Ev> */
/* @0x20e5f0 ldr r3, [sp, #0x8] */
/* @0x20e5f4 mov r0, r3 */
/* @0x20e5f8 bl 0x27d1d0 <_ZdlPv> */
/* @0x20e5fc ldr r12, [sp, #0xc] */
/* @0x20e600 ldr r3, [r12, #0x4] */
/* @0x20e604 b 0x20e53c <_ZN8CDS_List5ClearEv+0xc4> */
/* @0x20e608 ldrheq r3, [lr], -r8 */
/* @0x20e60c .word 0xffffc02c */
/* @0x20e610 .word 0xffffc030 */
/* @0x20e614 .word 0xffffc028 */
/* @0x20e618 .word 0xffffbcec */

/* ── FUNC 0x20e61c · CDS_List::Assign(CDS_List*) · size=844 · insn=211 */
/* @0x20e61c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x20e620 subs r11, r1, #0 */
/* @0x20e624 sub sp, sp, #20 */
/* @0x20e628 str r0, [sp, #0xc] */
/* @0x20e62c beq 0x20e958 <_ZN8CDS_List6AssignEPS_+0x33c> */
/* @0x20e630 ldr r12, [sp, #0xc] */
/* @0x20e634 movw r3, #0x44d */
/* @0x20e638 ldr r1, [r11, #0x8] */
/* @0x20e63c ldr lr, [r11, #0x4] */
/* @0x20e640 add r0, r12, #12 */
/* @0x20e644 ldr r2, [pc, #0x318] */
/* @0x20e648 lsl r1, r1, #4 */
/* @0x20e64c str lr, [r12, #0x4] */
/* @0x20e650 add r2, pc, r2 */
/* @0x20e654 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x20e658 ldr r3, [r11, #0x8] */
/* @0x20e65c ldr r12, [sp, #0xc] */
/* @0x20e660 str r3, [r12, #0x8] */
/* @0x20e664 ldr r3, [r11, #0x8] */
/* @0x20e668 cmp r3, #0 */
/* @0x20e66c ble 0x20e744 <_ZN8CDS_List6AssignEPS_+0x128> */
/* @0x20e670 mov r7, #0 */
/* @0x20e674 mov r9, r7 */
/* @0x20e678 ldr r12, [sp, #0xc] */
/* @0x20e67c lsl r4, r7, #4 */
/* @0x20e680 ldr r10, [r11, #0xc] */
/* @0x20e684 ldr r6, [r12, #0xc] */
/* @0x20e688 add r8, r10, r4 */
/* @0x20e68c add r5, r6, r4 */
/* @0x20e690 ldr r1, [r5, #0xc] */
/* @0x20e694 bic r2, r1, #-16777216 */
/* @0x20e698 cmp r2, #1 */
/* @0x20e69c beq 0x20e7c8 <_ZN8CDS_List6AssignEPS_+0x1ac> */
/* @0x20e6a0 cmp r2, #2 */
/* @0x20e6a4 bne 0x20e6c8 <_ZN8CDS_List6AssignEPS_+0xac> */
/* @0x20e6a8 sub r1, r1, #1 */
/* @0x20e6ac bic r1, r1, #-16777216 */
/* @0x20e6b0 bic r1, r1, #3 */
/* @0x20e6b4 cmp r1, #0 */
/* @0x20e6b8 beq 0x20e858 <_ZN8CDS_List6AssignEPS_+0x23c> */
/* @0x20e6bc mov r2, #5 */
/* @0x20e6c0 str r9, [r5, #0x8] */
/* @0x20e6c4 str r2, [r5, #0xc] */
/* @0x20e6c8 ldr r2, [r8, #0xc] */
/* @0x20e6cc ldr r1, [r8, #0x8] */
/* @0x20e6d0 str r9, [r6, r4] */
/* @0x20e6d4 str r2, [r5, #0xc] */
/* @0x20e6d8 ldr r2, [r8, #0xc] */
/* @0x20e6dc str r1, [r5, #0x8] */
/* @0x20e6e0 bic r2, r2, #-16777216 */
/* @0x20e6e4 cmp r2, #14 */
/* @0x20e6e8 addls pc, pc, r2, lsl #2 */
/* @0x20e6ec b 0x20e734 <_ZN8CDS_List6AssignEPS_+0x118> */
/* @0x20e6f0 b 0x20e74c <_ZN8CDS_List6AssignEPS_+0x130> */
/* @0x20e6f4 b 0x20e7b0 <_ZN8CDS_List6AssignEPS_+0x194> */
/* @0x20e6f8 b 0x20e784 <_ZN8CDS_List6AssignEPS_+0x168> */
/* @0x20e6fc b 0x20e72c <_ZN8CDS_List6AssignEPS_+0x110> */
/* @0x20e700 b 0x20e734 <_ZN8CDS_List6AssignEPS_+0x118> */
/* @0x20e704 b 0x20e734 <_ZN8CDS_List6AssignEPS_+0x118> */
/* @0x20e708 b 0x20e760 <_ZN8CDS_List6AssignEPS_+0x144> */
/* @0x20e70c b 0x20e72c <_ZN8CDS_List6AssignEPS_+0x110> */
/* @0x20e710 b 0x20e734 <_ZN8CDS_List6AssignEPS_+0x118> */
/* @0x20e714 b 0x20e734 <_ZN8CDS_List6AssignEPS_+0x118> */
/* @0x20e718 b 0x20e74c <_ZN8CDS_List6AssignEPS_+0x130> */
/* @0x20e71c b 0x20e734 <_ZN8CDS_List6AssignEPS_+0x118> */
/* @0x20e720 b 0x20e734 <_ZN8CDS_List6AssignEPS_+0x118> */
/* @0x20e724 b 0x20e74c <_ZN8CDS_List6AssignEPS_+0x130> */
/* @0x20e728 b 0x20e72c <_ZN8CDS_List6AssignEPS_+0x110> */
/* @0x20e72c ldr r3, [r10, r4] */
/* @0x20e730 str r3, [r6, r4] */
/* @0x20e734 ldr r3, [r11, #0x8] */
/* @0x20e738 add r7, r7, #1 */
/* @0x20e73c cmp r3, r7 */
/* @0x20e740 bgt 0x20e678 <_ZN8CDS_List6AssignEPS_+0x5c> */
/* @0x20e744 add sp, sp, #20 */
/* @0x20e748 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x20e74c ldr r2, [r10, r4] */
/* @0x20e750 ldr r3, [r8, #0x4] */
/* @0x20e754 str r2, [r6, r4] */
/* @0x20e758 str r3, [r5, #0x4] */
/* @0x20e75c b 0x20e734 <_ZN8CDS_List6AssignEPS_+0x118> */
/* @0x20e760 ldr r2, [r10, r4] */
/* @0x20e764 str r2, [r6, r4] */
/* @0x20e768 ldr r2, [r10, r4] */
/* @0x20e76c cmp r2, #0 */
/* @0x20e770 beq 0x20e734 <_ZN8CDS_List6AssignEPS_+0x118> */
/* @0x20e774 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x20e778 ldr r1, [r10, r4] */
/* @0x20e77c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x20e780 b 0x20e734 <_ZN8CDS_List6AssignEPS_+0x118> */
/* @0x20e784 ldr r3, [r10, r4] */
/* @0x20e788 cmp r3, #0 */
/* @0x20e78c str r3, [r6, r4] */
/* @0x20e790 beq 0x20e734 <_ZN8CDS_List6AssignEPS_+0x118> */
/* @0x20e794 ldr r1, [r3, #0x8] */
/* @0x20e798 ldr r2, [r3] */
/* @0x20e79c cmp r1, #0 */
/* @0x20e7a0 streq r5, [r3, #0x8] */
/* @0x20e7a4 add r2, r2, #1 */
/* @0x20e7a8 str r2, [r3] */
/* @0x20e7ac b 0x20e734 <_ZN8CDS_List6AssignEPS_+0x118> */
/* @0x20e7b0 ldr r3, [r10, r4] */
/* @0x20e7b4 cmp r3, #0 */
/* @0x20e7b8 ldrne r2, [r3, #0x4] */
/* @0x20e7bc addne r2, r2, #1 */
/* @0x20e7c0 strne r2, [r3, #0x4] */
/* @0x20e7c4 b 0x20e730 <_ZN8CDS_List6AssignEPS_+0x114> */
/* @0x20e7c8 ldr r2, [r6, r7, lsl #4] */
/* @0x20e7cc cmp r2, #0 */
/* @0x20e7d0 beq 0x20e7f8 <_ZN8CDS_List6AssignEPS_+0x1dc> */
/* @0x20e7d4 str r2, [sp, #0x4] */
/* @0x20e7d8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20e7dc ldr r2, [sp, #0x4] */
/* @0x20e7e0 ldr r1, [r2, #0x4] */
/* @0x20e7e4 sub r1, r1, #1 */
/* @0x20e7e8 str r1, [r2, #0x4] */
/* @0x20e7ec cmp r1, #0 */
/* @0x20e7f0 beq 0x20e800 <_ZN8CDS_List6AssignEPS_+0x1e4> */
/* @0x20e7f4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20e7f8 str r9, [r6, r4] */
/* @0x20e7fc b 0x20e6c8 <_ZN8CDS_List6AssignEPS_+0xac> */
/* @0x20e800 ldr r0, [r2] */
/* @0x20e804 str r1, [sp, #0x8] */
/* @0x20e808 str r2, [sp, #0x4] */
/* @0x20e80c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20e810 ldr r2, [sp, #0x4] */
/* @0x20e814 ldr r1, [sp, #0x8] */
/* @0x20e818 str r1, [r2] */
/* @0x20e81c str r1, [r2, #0x8] */
/* @0x20e820 str r2, [sp, #0x4] */
/* @0x20e824 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20e828 ldr r2, [sp, #0x4] */
/* @0x20e82c ldr r1, [r2, #0x4] */
/* @0x20e830 sub r1, r1, #1 */
/* @0x20e834 str r1, [r2, #0x4] */
/* @0x20e838 cmp r1, #0 */
/* @0x20e83c beq 0x20e864 <_ZN8CDS_List6AssignEPS_+0x248> */
/* @0x20e840 str r2, [sp, #0x4] */
/* @0x20e844 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20e848 ldr r2, [sp, #0x4] */
/* @0x20e84c mov r0, r2 */
/* @0x20e850 bl 0x27d1d0 <_ZdlPv> */
/* @0x20e854 b 0x20e7f4 <_ZN8CDS_List6AssignEPS_+0x1d8> */
/* @0x20e858 mov r0, r5 */
/* @0x20e85c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20e860 b 0x20e6bc <_ZN8CDS_List6AssignEPS_+0xa0> */
/* @0x20e864 ldr r0, [r2] */
/* @0x20e868 str r1, [sp, #0x8] */
/* @0x20e86c str r2, [sp, #0x4] */
/* @0x20e870 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20e874 ldr r2, [sp, #0x4] */
/* @0x20e878 ldr r1, [sp, #0x8] */
/* @0x20e87c str r1, [r2] */
/* @0x20e880 str r1, [r2, #0x8] */
/* @0x20e884 str r2, [sp, #0x4] */
/* @0x20e888 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20e88c ldr r2, [sp, #0x4] */
/* @0x20e890 ldr r1, [r2, #0x4] */
/* @0x20e894 sub r1, r1, #1 */
/* @0x20e898 str r1, [r2, #0x4] */
/* @0x20e89c cmp r1, #0 */
/* @0x20e8a0 beq 0x20e8c0 <_ZN8CDS_List6AssignEPS_+0x2a4> */
/* @0x20e8a4 str r2, [sp, #0x4] */
/* @0x20e8a8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20e8ac ldr r2, [sp, #0x4] */
/* @0x20e8b0 mov r0, r2 */
/* @0x20e8b4 bl 0x27d1d0 <_ZdlPv> */
/* @0x20e8b8 ldr r2, [sp, #0x4] */
/* @0x20e8bc b 0x20e840 <_ZN8CDS_List6AssignEPS_+0x224> */
/* @0x20e8c0 ldr r0, [r2] */
/* @0x20e8c4 str r1, [sp, #0x8] */
/* @0x20e8c8 str r2, [sp, #0x4] */
/* @0x20e8cc bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20e8d0 ldr r2, [sp, #0x4] */
/* @0x20e8d4 ldr r1, [sp, #0x8] */
/* @0x20e8d8 str r1, [r2] */
/* @0x20e8dc str r1, [r2, #0x8] */
/* @0x20e8e0 str r2, [sp, #0x4] */
/* @0x20e8e4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20e8e8 ldr r2, [sp, #0x4] */
/* @0x20e8ec ldr r1, [r2, #0x4] */
/* @0x20e8f0 sub r1, r1, #1 */
/* @0x20e8f4 str r1, [r2, #0x4] */
/* @0x20e8f8 cmp r1, #0 */
/* @0x20e8fc bne 0x20e93c <_ZN8CDS_List6AssignEPS_+0x320> */
/* @0x20e900 ldr r0, [r2] */
/* @0x20e904 str r1, [sp, #0x8] */
/* @0x20e908 str r2, [sp, #0x4] */
/* @0x20e90c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20e910 ldr r2, [sp, #0x4] */
/* @0x20e914 ldr r1, [sp, #0x8] */
/* @0x20e918 mov r0, r2 */
/* @0x20e91c str r1, [r2] */
/* @0x20e920 str r1, [r2, #0x8] */
/* @0x20e924 str r2, [sp, #0x4] */
/* @0x20e928 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x20e92c ldr r2, [sp, #0x4] */
/* @0x20e930 mov r0, r2 */
/* @0x20e934 bl 0x27d1d0 <_ZdlPv> */
/* @0x20e938 ldr r2, [sp, #0x4] */
/* @0x20e93c str r2, [sp, #0x4] */
/* @0x20e940 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20e944 ldr r2, [sp, #0x4] */
/* @0x20e948 mov r0, r2 */
/* @0x20e94c bl 0x27d1d0 <_ZdlPv> */
/* @0x20e950 ldr r2, [sp, #0x4] */
/* @0x20e954 b 0x20e8a4 <_ZN8CDS_List6AssignEPS_+0x288> */
/* @0x20e958 add sp, sp, #20 */
/* @0x20e95c pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x20e960 b 0x20e478 <_ZN8CDS_List5ClearEv> */
/* @0x20e964 mulseq r4, r12, r1 */
