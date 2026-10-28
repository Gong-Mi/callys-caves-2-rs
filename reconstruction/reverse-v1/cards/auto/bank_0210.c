/* libyoyo.so 覆盖卡组 0210
 * 函数 0x235b1c..0x2368f8，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x235b1c · IniFile::ReadInt(char const*, char const*, int) · size=40 · insn=10 */
/* @0x235b1c push {r4, lr} */
/* @0x235b20 mov r4, r3 */
/* @0x235b24 bl 0x235ad0 <_ZN7IniFile6GetKeyEPKcS1_> */
/* @0x235b28 cmp r0, #0 */
/* @0x235b2c beq 0x235b3c <_ZN7IniFile7ReadIntEPKcS1_i+0x20> */
/* @0x235b30 ldr r0, [r0, #0x8] */
/* @0x235b34 pop {r4, lr} */
/* @0x235b38 b 0xb66b8 <atoi@plt> */
/* @0x235b3c mov r0, r4 */
/* @0x235b40 pop {r4, pc} */

/* ── FUNC 0x235b44 · IniFile::ReadFloat(char const*, char const*, float) · size=52 · insn=13 */
/* @0x235b44 push {r4, lr} */
/* @0x235b48 mov r4, r3 */
/* @0x235b4c bl 0x235ad0 <_ZN7IniFile6GetKeyEPKcS1_> */
/* @0x235b50 cmp r0, #0 */
/* @0x235b54 vmoveq s15, r4 */
/* @0x235b58 beq 0x235b70 <_ZN7IniFile9ReadFloatEPKcS1_f+0x2c> */
/* @0x235b5c ldr r0, [r0, #0x8] */
/* @0x235b60 mov r1, #0 */
/* @0x235b64 bl 0xb6658 <strtod@plt> */
/* @0x235b68 vmov d6, r0, r1 */
/* @0x235b6c vcvt.f32.f64 s15, d6 */
/* @0x235b70 vmov r0, s15 */
/* @0x235b74 pop {r4, pc} */

/* ── FUNC 0x235b78 · IniFile::ReadString(char const*, char const*, char const*) · size=28 · insn=7 */
/* @0x235b78 push {r4, lr} */
/* @0x235b7c mov r4, r3 */
/* @0x235b80 bl 0x235ad0 <_ZN7IniFile6GetKeyEPKcS1_> */
/* @0x235b84 cmp r0, #0 */
/* @0x235b88 ldrne r0, [r0, #0x8] */
/* @0x235b8c moveq r0, r4 */
/* @0x235b90 pop {r4, pc} */

/* ── FUNC 0x235b94 · IniFile::DeleteKey(char const*, char const*) · size=152 · insn=38 */
/* @0x235b94 push {r4, r5, r6, r7, r8, lr} */
/* @0x235b98 mov r6, r2 */
/* @0x235b9c mov r8, r0 */
/* @0x235ba0 bl 0x235a90 <_ZN7IniFile10GetSectionEPKc> */
/* @0x235ba4 subs r7, r0, #0 */
/* @0x235ba8 beq 0x235c1c <_ZN7IniFile9DeleteKeyEPKcS1_+0x88> */
/* @0x235bac ldr r4, [r7, #0x4] */
/* @0x235bb0 cmp r4, #0 */
/* @0x235bb4 beq 0x235c24 <_ZN7IniFile9DeleteKeyEPKcS1_+0x90> */
/* @0x235bb8 mov r5, #0 */
/* @0x235bbc b 0x235bd0 <_ZN7IniFile9DeleteKeyEPKcS1_+0x3c> */
/* @0x235bc0 cmp r3, #0 */
/* @0x235bc4 mov r5, r4 */
/* @0x235bc8 mov r4, r3 */
/* @0x235bcc beq 0x235c14 <_ZN7IniFile9DeleteKeyEPKcS1_+0x80> */
/* @0x235bd0 mov r0, r6 */
/* @0x235bd4 ldr r1, [r4, #0x4] */
/* @0x235bd8 bl 0xb6574 <strcmp@plt> */
/* @0x235bdc ldr r3, [r4] */
/* @0x235be0 cmp r0, #0 */
/* @0x235be4 bne 0x235bc0 <_ZN7IniFile9DeleteKeyEPKcS1_+0x2c> */
/* @0x235be8 cmp r5, #0 */
/* @0x235bec mov r0, r4 */
/* @0x235bf0 streq r3, [r7, #0x4] */
/* @0x235bf4 mov r7, #1 */
/* @0x235bf8 strne r3, [r5] */
/* @0x235bfc strb r7, [r8, #0x18] */
/* @0x235c00 bl 0x2353b0 <_ZN3KeyD2Ev> */
/* @0x235c04 mov r0, r4 */
/* @0x235c08 bl 0x27d1d0 <_ZdlPv> */
/* @0x235c0c mov r0, r7 */
/* @0x235c10 pop {r4, r5, r6, r7, r8, pc} */
/* @0x235c14 mov r0, r3 */
/* @0x235c18 pop {r4, r5, r6, r7, r8, pc} */
/* @0x235c1c mov r0, r7 */
/* @0x235c20 pop {r4, r5, r6, r7, r8, pc} */
/* @0x235c24 mov r0, r4 */
/* @0x235c28 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x235c2c · IniFile::DeleteSection(char const*) · size=132 · insn=33 */
/* @0x235c2c push {r3, r4, r5, r6, r7, lr} */
/* @0x235c30 mov r7, r0 */
/* @0x235c34 ldr r4, [r0, #0x8] */
/* @0x235c38 mov r6, r1 */
/* @0x235c3c cmp r4, #0 */
/* @0x235c40 beq 0x235ca8 <_ZN7IniFile13DeleteSectionEPKc+0x7c> */
/* @0x235c44 mov r5, #0 */
/* @0x235c48 b 0x235c5c <_ZN7IniFile13DeleteSectionEPKc+0x30> */
/* @0x235c4c cmp r3, #0 */
/* @0x235c50 mov r5, r4 */
/* @0x235c54 mov r4, r3 */
/* @0x235c58 beq 0x235ca0 <_ZN7IniFile13DeleteSectionEPKc+0x74> */
/* @0x235c5c mov r0, r6 */
/* @0x235c60 ldr r1, [r4, #0x8] */
/* @0x235c64 bl 0xb6574 <strcmp@plt> */
/* @0x235c68 ldr r3, [r4] */
/* @0x235c6c cmp r0, #0 */
/* @0x235c70 bne 0x235c4c <_ZN7IniFile13DeleteSectionEPKc+0x20> */
/* @0x235c74 cmp r5, #0 */
/* @0x235c78 mov r0, r4 */
/* @0x235c7c strne r3, [r5] */
/* @0x235c80 mov r5, #1 */
/* @0x235c84 streq r3, [r7, #0x8] */
/* @0x235c88 strb r5, [r7, #0x18] */
/* @0x235c8c bl 0x2353e0 <_ZN7SectionD2Ev> */
/* @0x235c90 mov r0, r4 */
/* @0x235c94 bl 0x27d1d0 <_ZdlPv> */
/* @0x235c98 mov r0, r5 */
/* @0x235c9c pop {r3, r4, r5, r6, r7, pc} */
/* @0x235ca0 mov r0, r3 */
/* @0x235ca4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x235ca8 mov r0, r4 */
/* @0x235cac pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x235cb0 · IniFile::CalcFileSize() · size=124 · insn=31 */
/* @0x235cb0 push {r3, r4, r5, r6, r7, lr} */
/* @0x235cb4 ldr r7, [r0, #0x8] */
/* @0x235cb8 cmp r7, #0 */
/* @0x235cbc beq 0x235d20 <_ZN7IniFile12CalcFileSizeEv+0x70> */
/* @0x235cc0 mov r5, #0 */
/* @0x235cc4 ldr r0, [r7, #0x8] */
/* @0x235cc8 add r5, r5, #4 */
/* @0x235ccc bl 0xb6538 <strlen@plt> */
/* @0x235cd0 ldr r4, [r7, #0x4] */
/* @0x235cd4 cmp r4, #0 */
/* @0x235cd8 add r5, r5, r0 */
/* @0x235cdc beq 0x235d0c <_ZN7IniFile12CalcFileSizeEv+0x5c> */
/* @0x235ce0 ldr r0, [r4, #0x4] */
/* @0x235ce4 bl 0xb6538 <strlen@plt> */
/* @0x235ce8 mov r6, r0 */
/* @0x235cec ldr r0, [r4, #0x8] */
/* @0x235cf0 bl 0xb6538 <strlen@plt> */
/* @0x235cf4 ldr r4, [r4] */
/* @0x235cf8 cmp r4, #0 */
/* @0x235cfc add r0, r6, r0 */
/* @0x235d00 add r5, r0, r5 */
/* @0x235d04 add r5, r5, #5 */
/* @0x235d08 bne 0x235ce0 <_ZN7IniFile12CalcFileSizeEv+0x30> */
/* @0x235d0c ldr r7, [r7] */
/* @0x235d10 cmp r7, #0 */
/* @0x235d14 bne 0x235cc4 <_ZN7IniFile12CalcFileSizeEv+0x14> */
/* @0x235d18 mov r0, r5 */
/* @0x235d1c pop {r3, r4, r5, r6, r7, pc} */
/* @0x235d20 mov r5, r7 */
/* @0x235d24 mov r0, r5 */
/* @0x235d28 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x235d2c · IniFile::_sysWriteIniFile(char const*, char const*, int) · size=16 · insn=4 */
/* @0x235d2c mov r0, r1 */
/* @0x235d30 mov r1, r2 */
/* @0x235d34 mov r2, r3 */
/* @0x235d38 b 0x18fa3c <_ZN8LoadSave9WriteFileEPKcS1_i> */

/* ── FUNC 0x235d3c · IniFile::WriteIniFile() · size=416 · insn=104 */
/* @0x235d3c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x235d40 sub sp, sp, #20 */
/* @0x235d44 str r0, [sp, #0x8] */
/* @0x235d48 bl 0x235cb0 <_ZN7IniFile12CalcFileSizeEv> */
/* @0x235d4c ldr r1, [pc, #0x184] */
/* @0x235d50 mov r3, #1 */
/* @0x235d54 movw r2, #0x2f5 */
/* @0x235d58 add r1, pc, r1 */
/* @0x235d5c str r0, [sp, #0xc] */
/* @0x235d60 add r0, r0, #1 */
/* @0x235d64 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x235d68 ldr r3, [sp, #0x8] */
/* @0x235d6c ldr r3, [r3, #0x8] */
/* @0x235d70 cmp r3, #0 */
/* @0x235d74 str r3, [sp, #0x4] */
/* @0x235d78 movne r5, #0 */
/* @0x235d7c movne r8, #13 */
/* @0x235d80 movne r7, #10 */
/* @0x235d84 movne r6, #34 */
/* @0x235d88 mov r4, r0 */
/* @0x235d8c beq 0x235e7c <_ZN7IniFile12WriteIniFileEv+0x140> */
/* @0x235d90 mov r3, #91 */
/* @0x235d94 strb r3, [r4, r5] */
/* @0x235d98 ldr r3, [sp, #0x4] */
/* @0x235d9c add r5, r5, #1 */
/* @0x235da0 ldr r11, [r3, #0x8] */
/* @0x235da4 mov r0, r11 */
/* @0x235da8 bl 0xb6538 <strlen@plt> */
/* @0x235dac mov r1, r11 */
/* @0x235db0 mov r9, r0 */
/* @0x235db4 add r0, r4, r5 */
/* @0x235db8 mov r2, r9 */
/* @0x235dbc add r9, r5, r9 */
/* @0x235dc0 bl 0xb65bc <memcpy@plt> */
/* @0x235dc4 mov r3, r4 */
/* @0x235dc8 mov r2, #93 */
/* @0x235dcc strb r2, [r3, r9]! */
/* @0x235dd0 strb r8, [r3, #0x1] */
/* @0x235dd4 add r5, r9, #3 */
/* @0x235dd8 strb r7, [r3, #0x2] */
/* @0x235ddc ldr r3, [sp, #0x4] */
/* @0x235de0 ldr r9, [r3, #0x4] */
/* @0x235de4 cmp r9, #0 */
/* @0x235de8 beq 0x235e68 <_ZN7IniFile12WriteIniFileEv+0x12c> */
/* @0x235dec ldr r11, [r9, #0x4] */
/* @0x235df0 mov r0, r11 */
/* @0x235df4 bl 0xb6538 <strlen@plt> */
/* @0x235df8 mov r1, r11 */
/* @0x235dfc mov r10, r0 */
/* @0x235e00 mov r2, r0 */
/* @0x235e04 add r0, r4, r5 */
/* @0x235e08 add r5, r5, r10 */
/* @0x235e0c bl 0xb65bc <memcpy@plt> */
/* @0x235e10 mov r3, r4 */
/* @0x235e14 mov r2, #61 */
/* @0x235e18 strb r2, [r3, r5]! */
/* @0x235e1c strb r6, [r3, #0x1] */
/* @0x235e20 add r10, r5, #2 */
/* @0x235e24 ldr r11, [r9, #0x8] */
/* @0x235e28 mov r0, r11 */
/* @0x235e2c bl 0xb6538 <strlen@plt> */
/* @0x235e30 mov r1, r11 */
/* @0x235e34 mov r5, r0 */
/* @0x235e38 add r0, r4, r10 */
/* @0x235e3c mov r2, r5 */
/* @0x235e40 add r10, r10, r5 */
/* @0x235e44 bl 0xb65bc <memcpy@plt> */
/* @0x235e48 mov r3, r4 */
/* @0x235e4c strb r6, [r3, r10]! */
/* @0x235e50 add r5, r10, #3 */
/* @0x235e54 strb r8, [r3, #0x1] */
/* @0x235e58 strb r7, [r3, #0x2] */
/* @0x235e5c ldr r9, [r9] */
/* @0x235e60 cmp r9, #0 */
/* @0x235e64 bne 0x235dec <_ZN7IniFile12WriteIniFileEv+0xb0> */
/* @0x235e68 ldr r3, [sp, #0x4] */
/* @0x235e6c ldr r3, [r3] */
/* @0x235e70 cmp r3, #0 */
/* @0x235e74 str r3, [sp, #0x4] */
/* @0x235e78 bne 0x235d90 <_ZN7IniFile12WriteIniFileEv+0x54> */
/* @0x235e7c ldr r2, [sp, #0x8] */
/* @0x235e80 ldrb r3, [r2, #0x18] */
/* @0x235e84 cmp r3, #0 */
/* @0x235e88 beq 0x235ec0 <_ZN7IniFile12WriteIniFileEv+0x184> */
/* @0x235e8c ldr r2, [sp, #0x8] */
/* @0x235e90 ldr r0, [r2] */
/* @0x235e94 cmp r0, #0 */
/* @0x235e98 beq 0x235eb4 <_ZN7IniFile12WriteIniFileEv+0x178> */
/* @0x235e9c bl 0x13ad20 <_Z24EnsureDirectoryIsCreatedPKc> */
/* @0x235ea0 ldr r0, [sp, #0x8] */
/* @0x235ea4 mov r2, r4 */
/* @0x235ea8 ldr r3, [sp, #0xc] */
/* @0x235eac ldr r1, [r0] */
/* @0x235eb0 bl 0x235d2c <_ZN7IniFile16_sysWriteIniFileEPKcS1_i> */
/* @0x235eb4 ldr r2, [sp, #0x8] */
/* @0x235eb8 mov r3, #0 */
/* @0x235ebc strb r3, [r2, #0x18] */
/* @0x235ec0 ldr r2, [sp, #0xc] */
/* @0x235ec4 mov r3, #0 */
/* @0x235ec8 mov r0, r4 */
/* @0x235ecc strb r3, [r4, r2] */
/* @0x235ed0 add sp, sp, #20 */
/* @0x235ed4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x235ed8 andseq pc, r1, r12, lsl #7 */

/* ── FUNC 0x235edc · IniFile::SetKey(char const*, char const*, char const*) · size=508 · insn=127 */
/* @0x235edc push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x235ee0 mov r6, r0 */
/* @0x235ee4 mov r4, r1 */
/* @0x235ee8 mov r0, r1 */
/* @0x235eec ldr r1, [pc, #0x1c8] */
/* @0x235ef0 mov r5, #1 */
/* @0x235ef4 strb r5, [r6, #0x18] */
/* @0x235ef8 mov r7, r2 */
/* @0x235efc add r1, pc, r1 */
/* @0x235f00 mov r8, r3 */
/* @0x235f04 bl 0xb6574 <strcmp@plt> */
/* @0x235f08 cmp r0, #0 */
/* @0x235f0c bne 0x235f48 <_ZN7IniFile6SetKeyEPKcS1_S1_+0x6c> */
/* @0x235f10 ldr r1, [pc, #0x1a8] */
/* @0x235f14 mov r0, r7 */
/* @0x235f18 add r1, pc, r1 */
/* @0x235f1c bl 0xb6574 <strcmp@plt> */
/* @0x235f20 cmp r0, #0 */
/* @0x235f24 bne 0x235f40 <_ZN7IniFile6SetKeyEPKcS1_S1_+0x64> */
/* @0x235f28 ldr r1, [pc, #0x194] */
/* @0x235f2c mov r0, r8 */
/* @0x235f30 add r1, pc, r1 */
/* @0x235f34 bl 0xb6574 <strcmp@plt> */
/* @0x235f38 cmp r0, #0 */
/* @0x235f3c beq 0x235fc0 <_ZN7IniFile6SetKeyEPKcS1_S1_+0xe4> */
/* @0x235f40 mov r0, #1 */
/* @0x235f44 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x235f48 cmp r7, #0 */
/* @0x235f4c cmpne r4, #0 */
/* @0x235f50 bne 0x235f5c <_ZN7IniFile6SetKeyEPKcS1_S1_+0x80> */
/* @0x235f54 mov r0, #0 */
/* @0x235f58 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x235f5c mov r0, r6 */
/* @0x235f60 mov r1, r4 */
/* @0x235f64 mov r2, r7 */
/* @0x235f68 bl 0x235ad0 <_ZN7IniFile6GetKeyEPKcS1_> */
/* @0x235f6c subs r9, r0, #0 */
/* @0x235f70 beq 0x236000 <_ZN7IniFile6SetKeyEPKcS1_S1_+0x124> */
/* @0x235f74 ldr r0, [r9, #0x8] */
/* @0x235f78 cmp r0, #0 */
/* @0x235f7c beq 0x235f84 <_ZN7IniFile6SetKeyEPKcS1_S1_+0xa8> */
/* @0x235f80 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x235f84 cmp r8, #0 */
/* @0x235f88 beq 0x235fd4 <_ZN7IniFile6SetKeyEPKcS1_S1_+0xf8> */
/* @0x235f8c mov r0, r8 */
/* @0x235f90 bl 0xb6538 <strlen@plt> */
/* @0x235f94 ldr r1, [pc, #0x12c] */
/* @0x235f98 movw r2, #0x26a */
/* @0x235f9c mov r3, #1 */
/* @0x235fa0 add r1, pc, r1 */
/* @0x235fa4 add r0, r0, #3 */
/* @0x235fa8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x235fac mov r1, r8 */
/* @0x235fb0 str r0, [r9, #0x8] */
/* @0x235fb4 bl 0xb65a4 <strcpy@plt> */
/* @0x235fb8 mov r0, #1 */
/* @0x235fbc pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x235fc0 mov r0, r6 */
/* @0x235fc4 bl 0x235d3c <_ZN7IniFile12WriteIniFileEv> */
/* @0x235fc8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x235fcc mov r0, r5 */
/* @0x235fd0 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x235fd4 ldr r1, [pc, #0xf0] */
/* @0x235fd8 mov r0, #1 */
/* @0x235fdc mov r3, r0 */
/* @0x235fe0 movw r2, #0x26a */
/* @0x235fe4 add r1, pc, r1 */
/* @0x235fe8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x235fec mov r3, r0 */
/* @0x235ff0 mov r0, #1 */
/* @0x235ff4 str r3, [r9, #0x8] */
/* @0x235ff8 strb r8, [r3] */
/* @0x235ffc pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x236000 mov r0, r6 */
/* @0x236004 mov r1, r4 */
/* @0x236008 bl 0x235a90 <_ZN7IniFile10GetSectionEPKc> */
/* @0x23600c subs r10, r0, #0 */
/* @0x236010 beq 0x236068 <_ZN7IniFile6SetKeyEPKcS1_S1_+0x18c> */
/* @0x236014 mov r0, #12 */
/* @0x236018 bl 0x27c524 <_Znwj> */
/* @0x23601c ldr r2, [r10, #0x4] */
/* @0x236020 mov r3, #0 */
/* @0x236024 mov r9, r0 */
/* @0x236028 mov r0, r7 */
/* @0x23602c str r3, [r9, #0x4] */
/* @0x236030 str r3, [r9, #0x8] */
/* @0x236034 str r2, [r9] */
/* @0x236038 str r9, [r10, #0x4] */
/* @0x23603c bl 0xb6538 <strlen@plt> */
/* @0x236040 ldr r1, [pc, #0x88] */
/* @0x236044 mov r3, #1 */
/* @0x236048 movw r2, #0x263 */
/* @0x23604c add r1, pc, r1 */
/* @0x236050 add r0, r0, r3 */
/* @0x236054 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x236058 mov r1, r7 */
/* @0x23605c str r0, [r9, #0x4] */
/* @0x236060 bl 0xb65a4 <strcpy@plt> */
/* @0x236064 b 0x235f74 <_ZN7IniFile6SetKeyEPKcS1_S1_+0x98> */
/* @0x236068 mov r0, #12 */
/* @0x23606c bl 0x27c524 <_Znwj> */
/* @0x236070 mov r10, r0 */
/* @0x236074 str r9, [r0] */
/* @0x236078 mov r0, r4 */
/* @0x23607c str r9, [r10, #0x4] */
/* @0x236080 str r9, [r10, #0x8] */
/* @0x236084 bl 0xb6538 <strlen@plt> */
/* @0x236088 ldr r1, [pc, #0x44] */
/* @0x23608c mov r3, r5 */
/* @0x236090 movw r2, #0x256 */
/* @0x236094 add r1, pc, r1 */
/* @0x236098 add r0, r0, #1 */
/* @0x23609c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x2360a0 mov r1, r4 */
/* @0x2360a4 str r0, [r10, #0x8] */
/* @0x2360a8 bl 0xb65a4 <strcpy@plt> */
/* @0x2360ac ldr r3, [r6, #0x8] */
/* @0x2360b0 str r3, [r10] */
/* @0x2360b4 str r10, [r6, #0x8] */
/* @0x2360b8 b 0x236014 <_ZN7IniFile6SetKeyEPKcS1_S1_+0x138> */
/* @0x2360bc andseq pc, r1, r8, lsl r2 */
/* @0x2360c0 andseq pc, r1, r12, lsl #4 */
/* @0x2360c4 andseq pc, r1, r4, lsl #4 */
/* @0x2360c8 andseq pc, r1, r4, asr #2 */
/* @0x2360cc andseq pc, r1, r0, lsl #2 */
/* @0x2360d0 mulseq r1, r8, r0 */
/* @0x2360d4 andseq pc, r1, r0, asr r0 */

/* ── FUNC 0x2360d8 · IniFile::_sysReadIniFile(char const*) · size=72 · insn=18 */
/* @0x2360d8 push {r4, lr} */
/* @0x2360dc mov r0, r1 */
/* @0x2360e0 mov r4, r1 */
/* @0x2360e4 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc> */
/* @0x2360e8 cmp r0, #0 */
/* @0x2360ec bne 0x236104 <_ZN7IniFile15_sysReadIniFileEPKc+0x2c> */
/* @0x2360f0 ldr r1, [pc, #0x20] */
/* @0x2360f4 mov r0, r4 */
/* @0x2360f8 pop {r4, lr} */
/* @0x2360fc ldr r1, [pc, r1] */
/* @0x236100 b 0x18f848 <_ZN8LoadSave14ReadBundleFileEPKcPi> */
/* @0x236104 ldr r1, [pc, #0x10] */
/* @0x236108 mov r0, r4 */
/* @0x23610c pop {r4, lr} */
/* @0x236110 ldr r1, [pc, r1] */
/* @0x236114 b 0x18fb08 <_ZN8LoadSave12ReadSaveFileEPKcPi> */
/* @0x236118 andseq r11, r11, r0, lsr #7 */
/* @0x23611c andseq r11, r11, r12, lsl #7 */

/* ── FUNC 0x236120 · IniFile::ReadIniFile() · size=304 · insn=76 */
/* @0x236120 ldr r2, [r0, #0x10] */
/* @0x236124 push {r3, r4, r5, lr} */
/* @0x236128 cmp r2, #0 */
/* @0x23612c mov r4, r0 */
/* @0x236130 beq 0x236230 <_ZN7IniFile11ReadIniFileEv+0x110> */
/* @0x236134 ldr r3, [pc, #0x110] */
/* @0x236138 mov r1, #0 */
/* @0x23613c str r1, [r4, #0xc] */
/* @0x236140 ldr r3, [pc, r3] */
/* @0x236144 str r1, [r4, #0x14] */
/* @0x236148 ldr r3, [r3] */
/* @0x23614c cmp r3, #2 */
/* @0x236150 str r3, [r4, #0x4] */
/* @0x236154 bgt 0x236204 <_ZN7IniFile11ReadIniFileEv+0xe4> */
/* @0x236158 mov r0, r4 */
/* @0x23615c bl 0x2355e4 <_ZN7IniFile10GetSectionEv> */
/* @0x236160 ldr r2, [r4, #0xc] */
/* @0x236164 ldr r1, [r4, #0x4] */
/* @0x236168 mov r5, r0 */
/* @0x23616c str r0, [r4, #0x8] */
/* @0x236170 cmp r2, r1 */
/* @0x236174 mov r0, r4 */
/* @0x236178 bge 0x2361a8 <_ZN7IniFile11ReadIniFileEv+0x88> */
/* @0x23617c bl 0x235710 <_ZN7IniFile6GetKeyEv> */
/* @0x236180 cmp r0, #0 */
/* @0x236184 beq 0x2361c0 <_ZN7IniFile11ReadIniFileEv+0xa0> */
/* @0x236188 ldr r2, [r4, #0xc] */
/* @0x23618c ldr r1, [r4, #0x4] */
/* @0x236190 ldr r3, [r5, #0x4] */
/* @0x236194 cmp r2, r1 */
/* @0x236198 str r3, [r0] */
/* @0x23619c str r0, [r5, #0x4] */
/* @0x2361a0 mov r0, r4 */
/* @0x2361a4 blt 0x23617c <_ZN7IniFile11ReadIniFileEv+0x5c> */
/* @0x2361a8 ldr r0, [r4, #0x10] */
/* @0x2361ac bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2361b0 mov r3, #0 */
/* @0x2361b4 mov r0, #1 */
/* @0x2361b8 str r3, [r4, #0x10] */
/* @0x2361bc pop {r3, r4, r5, pc} */
/* @0x2361c0 ldr r2, [r4, #0xc] */
/* @0x2361c4 ldr r1, [r4, #0x4] */
/* @0x2361c8 cmp r2, r1 */
/* @0x2361cc bge 0x236170 <_ZN7IniFile11ReadIniFileEv+0x50> */
/* @0x2361d0 ldr r3, [r4, #0x10] */
/* @0x2361d4 ldrb r3, [r3, r2] */
/* @0x2361d8 cmp r3, #91 */
/* @0x2361dc bne 0x236170 <_ZN7IniFile11ReadIniFileEv+0x50> */
/* @0x2361e0 mov r0, r4 */
/* @0x2361e4 bl 0x2355e4 <_ZN7IniFile10GetSectionEv> */
/* @0x2361e8 ldr r3, [r4, #0x8] */
/* @0x2361ec ldr r2, [r4, #0xc] */
/* @0x2361f0 ldr r1, [r4, #0x4] */
/* @0x2361f4 mov r5, r0 */
/* @0x2361f8 str r3, [r0] */
/* @0x2361fc str r0, [r4, #0x8] */
/* @0x236200 b 0x236170 <_ZN7IniFile11ReadIniFileEv+0x50> */
/* @0x236204 ldrb r3, [r2] */
/* @0x236208 cmp r3, #239 */
/* @0x23620c bne 0x236158 <_ZN7IniFile11ReadIniFileEv+0x38> */
/* @0x236210 ldrb r3, [r2, #0x1] */
/* @0x236214 cmp r3, #187 */
/* @0x236218 bne 0x236158 <_ZN7IniFile11ReadIniFileEv+0x38> */
/* @0x23621c ldrb r3, [r2, #0x2] */
/* @0x236220 cmp r3, #191 */
/* @0x236224 moveq r3, #3 */
/* @0x236228 streq r3, [r4, #0xc] */
/* @0x23622c b 0x236158 <_ZN7IniFile11ReadIniFileEv+0x38> */
/* @0x236230 ldr r1, [r0] */
/* @0x236234 bl 0x2360d8 <_ZN7IniFile15_sysReadIniFileEPKc> */
/* @0x236238 cmp r0, #0 */
/* @0x23623c mov r2, r0 */
/* @0x236240 str r0, [r4, #0x10] */
/* @0x236244 bne 0x236134 <_ZN7IniFile11ReadIniFileEv+0x14> */
/* @0x236248 pop {r3, r4, r5, pc} */
/* @0x23624c andseq r11, r11, r12, asr r3 */

/* ── FUNC 0x236250 · IniFile::SetText(char const*) · size=104 · insn=26 */
/* @0x236250 push {r3, r4, r5, lr} */
/* @0x236254 mov r4, r0 */
/* @0x236258 mov r0, r1 */
/* @0x23625c mov r5, r1 */
/* @0x236260 bl 0xb6538 <strlen@plt> */
/* @0x236264 ldr r1, [pc, #0x44] */
/* @0x236268 mov r3, #1 */
/* @0x23626c mov r2, #109 */
/* @0x236270 add r1, pc, r1 */
/* @0x236274 add r0, r0, r3 */
/* @0x236278 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x23627c mov r1, r5 */
/* @0x236280 str r0, [r4, #0x10] */
/* @0x236284 bl 0xb65a4 <strcpy@plt> */
/* @0x236288 ldr r0, [r4, #0x10] */
/* @0x23628c bl 0xb6538 <strlen@plt> */
/* @0x236290 ldr r3, [pc, #0x1c] */
/* @0x236294 ldr r3, [pc, r3] */
/* @0x236298 mov r2, r0 */
/* @0x23629c mov r0, r4 */
/* @0x2362a0 str r2, [r4, #0x4] */
/* @0x2362a4 str r2, [r3] */
/* @0x2362a8 pop {r3, r4, r5, lr} */
/* @0x2362ac b 0x236120 <_ZN7IniFile11ReadIniFileEv> */
/* @0x2362b0 andseq lr, r1, r4, ror lr */
/* @0x2362b4 andseq r11, r11, r8, lsl #4 */

/* ── FUNC 0x2362b8 · IniFile::IniFile(char*, bool) · size=268 · insn=67 */
/* @0x2362b8 push {r4, r5, r6, lr} */
/* @0x2362bc mov r4, r0 */
/* @0x2362c0 mov r3, #0 */
/* @0x2362c4 mov r0, r1 */
/* @0x2362c8 str r3, [r4, #0x4] */
/* @0x2362cc mov r5, r1 */
/* @0x2362d0 str r3, [r4, #0x8] */
/* @0x2362d4 mov r6, r2 */
/* @0x2362d8 str r3, [r4, #0x10] */
/* @0x2362dc str r3, [r4, #0x14] */
/* @0x2362e0 strb r3, [r4, #0x18] */
/* @0x2362e4 bl 0xb6538 <strlen@plt> */
/* @0x2362e8 ldr r1, [pc, #0xc4] */
/* @0x2362ec mov r3, #1 */
/* @0x2362f0 mov r2, #129 */
/* @0x2362f4 add r1, pc, r1 */
/* @0x2362f8 add r0, r0, r3 */
/* @0x2362fc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x236300 mov r1, r5 */
/* @0x236304 str r0, [r4] */
/* @0x236308 bl 0xb65a4 <strcpy@plt> */
/* @0x23630c cmp r6, #0 */
/* @0x236310 bne 0x236324 <_ZN7IniFileC2EPcb+0x6c> */
/* @0x236314 mov r0, r4 */
/* @0x236318 bl 0x236120 <_ZN7IniFile11ReadIniFileEv> */
/* @0x23631c mov r0, r4 */
/* @0x236320 pop {r4, r5, r6, pc} */
/* @0x236324 ldr r0, [r4] */
/* @0x236328 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc> */
/* @0x23632c cmp r0, #0 */
/* @0x236330 bne 0x236398 <_ZN7IniFileC2EPcb+0xe0> */
/* @0x236334 ldr r5, [pc, #0x7c] */
/* @0x236338 ldr r0, [r4] */
/* @0x23633c ldr r5, [pc, r5] */
/* @0x236340 mov r1, r5 */
/* @0x236344 bl 0x18f848 <_ZN8LoadSave14ReadBundleFileEPKcPi> */
/* @0x236348 str r0, [r4, #0x10] */
/* @0x23634c cmp r0, #0 */
/* @0x236350 beq 0x236314 <_ZN7IniFileC2EPcb+0x5c> */
/* @0x236354 ldr r0, [r5] */
/* @0x236358 mov r3, #1 */
/* @0x23635c ldr r1, [pc, #0x58] */
/* @0x236360 mov r2, #143 */
/* @0x236364 add r0, r0, r3 */
/* @0x236368 add r1, pc, r1 */
/* @0x23636c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x236370 ldr r2, [r5] */
/* @0x236374 ldr r1, [r4, #0x10] */
/* @0x236378 mov r6, r0 */
/* @0x23637c bl 0xb6568 <strncpy@plt> */
/* @0x236380 ldr r3, [r5] */
/* @0x236384 mov r2, #0 */
/* @0x236388 mov r0, r6 */
/* @0x23638c strb r2, [r6, r3] */
/* @0x236390 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x236394 b 0x236314 <_ZN7IniFileC2EPcb+0x5c> */
/* @0x236398 ldr r5, [pc, #0x20] */
/* @0x23639c ldr r0, [r4] */
/* @0x2363a0 ldr r5, [pc, r5] */
/* @0x2363a4 mov r1, r5 */
/* @0x2363a8 bl 0x18fb08 <_ZN8LoadSave12ReadSaveFileEPKcPi> */
/* @0x2363ac str r0, [r4, #0x10] */
/* @0x2363b0 b 0x23634c <_ZN7IniFileC2EPcb+0x94> */
/* @0x2363b4 ldrsheq lr, [r1], -r0 */
/* @0x2363b8 andseq r11, r11, r0, ror #2 */
/* @0x2363bc andseq lr, r1, r12, ror sp */
/* @0x2363c0 ldrsheq r11, [r11], -r12 */

/* ── FUNC 0x2362b8 · IniFile::IniFile(char*, bool) · alias of the symbol above · insn=0 */

/* ── FUNC 0x2363c4 · b2Shape::~b2Shape() · size=24 · insn=6 */
/* @0x2363c4 ldr r3, [pc, #0xc] */
/* @0x2363c8 ldr r3, [pc, r3] */
/* @0x2363cc add r3, r3, #8 */
/* @0x2363d0 str r3, [r0] */
/* @0x2363d4 bx lr */
/* @0x2363d8 ldrsbeq r11, [r11], -r8 */

/* ── FUNC 0x2363c4 · b2Shape::~b2Shape() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2363dc · b2Shape::~b2Shape() · size=40 · insn=10 */
/* @0x2363dc ldr r3, [pc, #0x1c] */
/* @0x2363e0 push {r4, lr} */
/* @0x2363e4 ldr r3, [pc, r3] */
/* @0x2363e8 mov r4, r0 */
/* @0x2363ec add r3, r3, #8 */
/* @0x2363f0 str r3, [r0] */
/* @0x2363f4 bl 0x27d1d0 <_ZdlPv> */
/* @0x2363f8 mov r0, r4 */
/* @0x2363fc pop {r4, pc} */
/* @0x236400 ldrheq r11, [r11], -r12 */

/* ── FUNC 0x236404 · CPhysicsFixtureFactory::FindFixture(unsigned int) · size=80 · insn=20 */
/* @0x236404 ldr r3, [pc, #0x44] */
/* @0x236408 ldr r3, [pc, r3] */
/* @0x23640c ldr r2, [r3, #0x4] */
/* @0x236410 ldr r3, [r3] */
/* @0x236414 and r2, r0, r2 */
/* @0x236418 ldr r3, [r3, r2, lsl #3] */
/* @0x23641c cmp r3, #0 */
/* @0x236420 bne 0x236434 <_ZN22CPhysicsFixtureFactory11FindFixtureEj+0x30> */
/* @0x236424 b 0x236448 <_ZN22CPhysicsFixtureFactory11FindFixtureEj+0x44> */
/* @0x236428 ldr r3, [r3, #0x4] */
/* @0x23642c cmp r3, #0 */
/* @0x236430 beq 0x236448 <_ZN22CPhysicsFixtureFactory11FindFixtureEj+0x44> */
/* @0x236434 ldr r2, [r3, #0x8] */
/* @0x236438 cmp r0, r2 */
/* @0x23643c bne 0x236428 <_ZN22CPhysicsFixtureFactory11FindFixtureEj+0x24> */
/* @0x236440 ldr r0, [r3, #0xc] */
/* @0x236444 bx lr */
/* @0x236448 mov r0, r3 */
/* @0x23644c bx lr */
/* @0x236450 mulseq r11, r12, r0 */

/* ── FUNC 0x236454 · CPhysicsFixture::CPhysicsFixture(int) · size=128 · insn=32 */
/* @0x236454 push {r3, r4, r5, r6, r7, lr} */
/* @0x236458 mov r5, #0 */
/* @0x23645c mov r4, r0 */
/* @0x236460 mov r6, #0 */
/* @0x236464 str r1, [r0, #0x1c] */
/* @0x236468 mov r7, #1 */
/* @0x23646c str r6, [r0] */
/* @0x236470 str r6, [r0, #0x4] */
/* @0x236474 strb r5, [r0, #0x18] */
/* @0x236478 strb r7, [r0, #0x8] */
/* @0x23647c mov r0, #36 */
/* @0x236480 bl 0x27c524 <_Znwj> */
/* @0x236484 movw r2, #0xffff */
/* @0x236488 movw r1, #0xcccd */
/* @0x23648c movt r1, #0x3e4c */
/* @0x236490 str r7, [r0, #0x18] */
/* @0x236494 mov r3, r0 */
/* @0x236498 str r6, [r0, #0xc] */
/* @0x23649c strh r5, [r0, #32] */
/* @0x2364a0 str r6, [r0, #0x10] */
/* @0x2364a4 str r5, [r0] */
/* @0x2364a8 str r5, [r0, #0x4] */
/* @0x2364ac strb r5, [r0, #0x14] */
/* @0x2364b0 str r1, [r0, #0x8] */
/* @0x2364b4 str r2, [r0, #0x1c] */
/* @0x2364b8 mov r0, r4 */
/* @0x2364bc str r3, [r4, #0x20] */
/* @0x2364c0 strb r5, [r4, #0x19] */
/* @0x2364c4 str r5, [r4, #0xc] */
/* @0x2364c8 str r5, [r4, #0x10] */
/* @0x2364cc str r5, [r4, #0x14] */
/* @0x2364d0 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x236454 · CPhysicsFixture::CPhysicsFixture(int) · alias of the symbol above · insn=0 */

/* ── FUNC 0x2364d4 · CPhysicsFixtureFactory::CreateFixture() · size=184 · insn=46 */
/* @0x2364d4 ldr r3, [pc, #0xa4] */
/* @0x2364d8 mov r0, #36 */
/* @0x2364dc push {r4, r5, r6, r7, r8, lr} */
/* @0x2364e0 ldr r3, [pc, r3] */
/* @0x2364e4 ldr r4, [pc, #0x98] */
/* @0x2364e8 ldr r5, [r3] */
/* @0x2364ec add r5, r5, #1 */
/* @0x2364f0 str r5, [r3] */
/* @0x2364f4 bl 0x27c524 <_Znwj> */
/* @0x2364f8 mov r1, r5 */
/* @0x2364fc mov r8, r0 */
/* @0x236500 bl 0x236454 <_ZN15CPhysicsFixtureC2Ei> */
/* @0x236504 ldr r1, [pc, #0x7c] */
/* @0x236508 ldr r4, [pc, r4] */
/* @0x23650c movw r2, #0x132 */
/* @0x236510 mov r3, #1 */
/* @0x236514 add r1, pc, r1 */
/* @0x236518 mov r0, #16 */
/* @0x23651c ldr r6, [r4] */
/* @0x236520 ldr r7, [r4, #0x4] */
/* @0x236524 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x236528 and r7, r5, r7 */
/* @0x23652c ldr r1, [r6, r7, lsl #3] */
/* @0x236530 add r2, r6, r7, lsl #3 */
/* @0x236534 cmp r1, #0 */
/* @0x236538 ldrne r1, [r2, #0x4] */
/* @0x23653c mov r3, r0 */
/* @0x236540 str r5, [r0, #0x8] */
/* @0x236544 str r8, [r0, #0xc] */
/* @0x236548 movne r0, #0 */
/* @0x23654c strne r1, [r3] */
/* @0x236550 strne r3, [r1, #0x4] */
/* @0x236554 strne r3, [r2, #0x4] */
/* @0x236558 strne r0, [r3, #0x4] */
/* @0x23655c ldr r3, [r4, #0x8] */
/* @0x236560 streq r0, [r2, #0x4] */
/* @0x236564 add r3, r3, #1 */
/* @0x236568 streq r0, [r6, r7, lsl #3] */
/* @0x23656c streq r1, [r0, #0x4] */
/* @0x236570 streq r1, [r0] */
/* @0x236574 mov r0, r8 */
/* @0x236578 str r3, [r4, #0x8] */
/* @0x23657c pop {r4, r5, r6, r7, r8, pc} */
/* @0x236580 andseq r10, r11, r8, asr #31 */
/* @0x236584 mulseq r11, r12, pc */
/* @0x236588 mulseq r1, r8, r7 */

/* ── FUNC 0x23658c · CPhysicsFixture::AllocVertices(int) · size=68 · insn=17 */
/* @0x23658c push {r4, lr} */
/* @0x236590 sub sp, sp, #8 */
/* @0x236594 ldr r2, [pc, #0x30] */
/* @0x236598 mov r4, r0 */
/* @0x23659c mov r3, r1 */
/* @0x2365a0 ldr r0, [r0, #0x14] */
/* @0x2365a4 mov r12, #0 */
/* @0x2365a8 str r3, [r4, #0x10] */
/* @0x2365ac lsl r1, r1, #3 */
/* @0x2365b0 add r2, pc, r2 */
/* @0x2365b4 mov r3, #105 */
/* @0x2365b8 str r12, [sp] */
/* @0x2365bc bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x2365c0 str r0, [r4, #0x14] */
/* @0x2365c4 add sp, sp, #8 */
/* @0x2365c8 pop {r4, pc} */
/* @0x2365cc andseq lr, r1, r8, lsl #23 */

/* ── FUNC 0x2365d0 · CPhysicsFixture::DeleteShape() · size=76 · insn=19 */
/* @0x2365d0 ldr r3, [r0, #0x20] */
/* @0x2365d4 push {r4, lr} */
/* @0x2365d8 mov r4, r0 */
/* @0x2365dc ldr r0, [r3] */
/* @0x2365e0 cmp r0, #0 */
/* @0x2365e4 beq 0x236600 <_ZN15CPhysicsFixture11DeleteShapeEv+0x30> */
/* @0x2365e8 ldr r3, [r0] */
/* @0x2365ec ldr r3, [r3, #0x4] */
/* @0x2365f0 blx r3 */
/* @0x2365f4 ldr r3, [r4, #0x20] */
/* @0x2365f8 mov r2, #0 */
/* @0x2365fc str r2, [r3] */
/* @0x236600 ldr r0, [r4, #0x14] */
/* @0x236604 cmp r0, #0 */
/* @0x236608 popeq {r4, pc} */
/* @0x23660c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x236610 mov r3, #0 */
/* @0x236614 str r3, [r4, #0x14] */
/* @0x236618 pop {r4, pc} */

/* ── FUNC 0x23661c · CPhysicsFixture::~CPhysicsFixture() · size=44 · insn=11 */
/* @0x23661c push {r4, lr} */
/* @0x236620 mov r4, r0 */
/* @0x236624 bl 0x2365d0 <_ZN15CPhysicsFixture11DeleteShapeEv> */
/* @0x236628 ldr r0, [r4, #0x20] */
/* @0x23662c cmp r0, #0 */
/* @0x236630 beq 0x236640 <_ZN15CPhysicsFixtureD2Ev+0x24> */
/* @0x236634 bl 0x27d1d0 <_ZdlPv> */
/* @0x236638 mov r3, #0 */
/* @0x23663c str r3, [r4, #0x20] */
/* @0x236640 mov r0, r4 */
/* @0x236644 pop {r4, pc} */

/* ── FUNC 0x23661c · CPhysicsFixture::~CPhysicsFixture() · alias of the symbol above · insn=0 */

/* ── FUNC 0x236648 · CPhysicsFixtureFactory::DestroyFixture(unsigned int) · size=172 · insn=43 */
/* @0x236648 push {r3, r4, r5, lr} */
/* @0x23664c bl 0x236404 <_ZN22CPhysicsFixtureFactory11FindFixtureEj> */
/* @0x236650 subs r5, r0, #0 */
/* @0x236654 beq 0x2366e8 <_ZN22CPhysicsFixtureFactory14DestroyFixtureEj+0xa0> */
/* @0x236658 ldr r4, [pc, #0x90] */
/* @0x23665c ldr r1, [r5, #0x1c] */
/* @0x236660 ldr r4, [pc, r4] */
/* @0x236664 ldm r4, {r0, r12} */
/* @0x236668 and r12, r1, r12 */
/* @0x23666c ldr r3, [r0, r12, lsl #3] */
/* @0x236670 add lr, r0, r12, lsl #3 */
/* @0x236674 cmp r3, #0 */
/* @0x236678 bne 0x23668c <_ZN22CPhysicsFixtureFactory14DestroyFixtureEj+0x44> */
/* @0x23667c b 0x2366d0 <_ZN22CPhysicsFixtureFactory14DestroyFixtureEj+0x88> */
/* @0x236680 ldr r3, [r3, #0x4] */
/* @0x236684 cmp r3, #0 */
/* @0x236688 beq 0x2366d0 <_ZN22CPhysicsFixtureFactory14DestroyFixtureEj+0x88> */
/* @0x23668c ldr r2, [r3, #0x8] */
/* @0x236690 cmp r1, r2 */
/* @0x236694 bne 0x236680 <_ZN22CPhysicsFixtureFactory14DestroyFixtureEj+0x38> */
/* @0x236698 ldr r2, [r3] */
/* @0x23669c ldr r1, [r3, #0x4] */
/* @0x2366a0 cmp r2, #0 */
/* @0x2366a4 strne r1, [r2, #0x4] */
/* @0x2366a8 ldrne r1, [r3, #0x4] */
/* @0x2366ac streq r1, [r0, r12, lsl #3] */
/* @0x2366b0 mov r0, r3 */
/* @0x2366b4 cmp r1, #0 */
/* @0x2366b8 streq r2, [lr, #0x4] */
/* @0x2366bc strne r2, [r1] */
/* @0x2366c0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2366c4 ldr r3, [r4, #0x8] */
/* @0x2366c8 sub r3, r3, #1 */
/* @0x2366cc str r3, [r4, #0x8] */
/* @0x2366d0 mov r0, r5 */
/* @0x2366d4 bl 0x23661c <_ZN15CPhysicsFixtureD2Ev> */
/* @0x2366d8 mov r0, r5 */
/* @0x2366dc bl 0x27d1d0 <_ZdlPv> */
/* @0x2366e0 mov r0, #1 */
/* @0x2366e4 pop {r3, r4, r5, pc} */
/* @0x2366e8 mov r0, r5 */
/* @0x2366ec pop {r3, r4, r5, pc} */
/* @0x2366f0 andseq r10, r11, r4, asr #28 */

/* ── FUNC 0x2366f4 · Hash<CPhysicsFixture>::~Hash() · size=148 · insn=37 */
/* @0x2366f4 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2366f8 mov r7, r0 */
/* @0x2366fc ldm r0, {r0, r9} */
/* @0x236700 cmp r9, #0 */
/* @0x236704 lslge r8, r9, #3 */
/* @0x236708 movge r10, #0 */
/* @0x23670c blt 0x23677c <_ZN4HashI15CPhysicsFixtureED2Ev+0x88> */
/* @0x236710 ldr r4, [r0, r8] */
/* @0x236714 add r3, r0, r8 */
/* @0x236718 str r10, [r0, r8] */
/* @0x23671c cmp r4, #0 */
/* @0x236720 str r10, [r3, #0x4] */
/* @0x236724 beq 0x23676c <_ZN4HashI15CPhysicsFixtureED2Ev+0x78> */
/* @0x236728 ldr r5, [r4, #0xc] */
/* @0x23672c ldr r6, [r4, #0x4] */
/* @0x236730 cmp r5, #0 */
/* @0x236734 mov r0, r5 */
/* @0x236738 beq 0x236748 <_ZN4HashI15CPhysicsFixtureED2Ev+0x54> */
/* @0x23673c bl 0x23661c <_ZN15CPhysicsFixtureD2Ev> */
/* @0x236740 mov r0, r5 */
/* @0x236744 bl 0x27d1d0 <_ZdlPv> */
/* @0x236748 mov r0, r4 */
/* @0x23674c mov r4, r6 */
/* @0x236750 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x236754 ldr r3, [r7, #0x8] */
/* @0x236758 cmp r6, #0 */
/* @0x23675c sub r3, r3, #1 */
/* @0x236760 str r3, [r7, #0x8] */
/* @0x236764 bne 0x236728 <_ZN4HashI15CPhysicsFixtureED2Ev+0x34> */
/* @0x236768 ldr r0, [r7] */
/* @0x23676c sub r9, r9, #1 */
/* @0x236770 sub r8, r8, #8 */
/* @0x236774 cmn r9, #1 */
/* @0x236778 bne 0x236710 <_ZN4HashI15CPhysicsFixtureED2Ev+0x1c> */
/* @0x23677c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x236780 mov r0, r7 */
/* @0x236784 pop {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── FUNC 0x2366f4 · Hash<CPhysicsFixture>::~Hash() · alias of the symbol above · insn=0 */

/* ── FUNC 0x236788 · CPhysicsFixture::SetCircleShape(float) · size=80 · insn=20 */
/* @0x236788 push {r3, r4, r5, lr} */
/* @0x23678c mov r4, r1 */
/* @0x236790 mov r5, r0 */
/* @0x236794 bl 0x2365d0 <_ZN15CPhysicsFixture11DeleteShapeEv> */
/* @0x236798 mov r0, #20 */
/* @0x23679c bl 0x27c524 <_Znwj> */
/* @0x2367a0 ldr r1, [r5, #0x20] */
/* @0x2367a4 ldr r3, [pc, #0x28] */
/* @0x2367a8 mov r2, #0 */
/* @0x2367ac mov r12, #0 */
/* @0x2367b0 ldr r3, [pc, r3] */
/* @0x2367b4 add r3, r3, #8 */
/* @0x2367b8 str r4, [r0, #0x8] */
/* @0x2367bc str r12, [r0, #0x4] */
/* @0x2367c0 str r2, [r0, #0xc] */
/* @0x2367c4 str r2, [r0, #0x10] */
/* @0x2367c8 str r3, [r0] */
/* @0x2367cc str r0, [r1] */
/* @0x2367d0 pop {r3, r4, r5, pc} */
/* @0x2367d4 ldrsheq r10, [r11], -r12 */

/* ── FUNC 0x2367d8 · CPhysicsFixture::SetBoxShape(float, float) · size=112 · insn=28 */
/* @0x2367d8 push {r3, r4, r5, r6, r7, lr} */
/* @0x2367dc mov r7, r1 */
/* @0x2367e0 mov r5, r0 */
/* @0x2367e4 mov r6, r2 */
/* @0x2367e8 bl 0x2365d0 <_ZN15CPhysicsFixture11DeleteShapeEv> */
/* @0x2367ec mov r0, #152 */
/* @0x2367f0 bl 0x27c524 <_Znwj> */
/* @0x2367f4 ldr r3, [pc, #0x48] */
/* @0x2367f8 mov r12, #2 */
/* @0x2367fc mov r1, r7 */
/* @0x236800 ldr r3, [pc, r3] */
/* @0x236804 movw lr, #0xd70a */
/* @0x236808 add r3, r3, #8 */
/* @0x23680c movt lr, #0x3c23 */
/* @0x236810 mov r2, r6 */
/* @0x236814 stm r0, {r3, r12} */
/* @0x236818 mov r3, #0 */
/* @0x23681c mov r12, #0 */
/* @0x236820 str r3, [r0, #0xc] */
/* @0x236824 str r3, [r0, #0x10] */
/* @0x236828 mov r4, r0 */
/* @0x23682c str lr, [r0, #0x8] */
/* @0x236830 str r12, [r0, #0x94] */
/* @0x236834 bl 0x2c5e9c <_ZN14b2PolygonShape8SetAsBoxEff> */
/* @0x236838 ldr r3, [r5, #0x20] */
/* @0x23683c str r4, [r3] */
/* @0x236840 pop {r3, r4, r5, r6, r7, pc} */
/* @0x236844 ldrheq r10, [r11], -r0 */

/* ── FUNC 0x236848 · CPhysicsFixture::SetEdgeShape(float, float, float, float) · size=176 · insn=44 */
/* @0x236848 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x23684c mov r5, r0 */
/* @0x236850 mov r6, r1 */
/* @0x236854 mov r7, r2 */
/* @0x236858 mov r8, r3 */
/* @0x23685c ldr r9, [sp, #0x20] */
/* @0x236860 bl 0x2365d0 <_ZN15CPhysicsFixture11DeleteShapeEv> */
/* @0x236864 mov r0, #48 */
/* @0x236868 bl 0x27c524 <_Znwj> */
/* @0x23686c mov r12, #2 */
/* @0x236870 mov r3, #1 */
/* @0x236874 mov lr, #0 */
/* @0x236878 mov r1, r12 */
/* @0x23687c movw r2, #0xd70a */
/* @0x236880 movt r2, #0x3c23 */
/* @0x236884 mov r4, r0 */
/* @0x236888 ldr r0, [pc, #0x64] */
/* @0x23688c str r3, [r4, #0x4] */
/* @0x236890 ldr r0, [pc, r0] */
/* @0x236894 str r2, [r4, #0x8] */
/* @0x236898 strb lr, [r4, #0x2c] */
/* @0x23689c add r0, r0, #8 */
/* @0x2368a0 strb lr, [r4, #0x2d] */
/* @0x2368a4 str r0, [r4] */
/* @0x2368a8 mov r0, #0 */
/* @0x2368ac str r0, [r4, #0x1c] */
/* @0x2368b0 str r0, [r4, #0x20] */
/* @0x2368b4 str r0, [r4, #0x24] */
/* @0x2368b8 str r0, [r4, #0x28] */
/* @0x2368bc mov r0, r5 */
/* @0x2368c0 str r12, [r5, #0xc] */
/* @0x2368c4 bl 0x23658c <_ZN15CPhysicsFixture13AllocVerticesEi> */
/* @0x2368c8 ldr r1, [r5, #0x14] */
/* @0x2368cc mov r0, r4 */
/* @0x2368d0 add r2, r1, #8 */
/* @0x2368d4 str r6, [r1] */
/* @0x2368d8 str r7, [r1, #0x4] */
/* @0x2368dc str r8, [r1, #0x8] */
/* @0x2368e0 str r9, [r1, #0xc] */
/* @0x2368e4 bl 0x2c5630 <_ZN11b2EdgeShape3SetERK6b2Vec2S2_> */
/* @0x2368e8 ldr r3, [r5, #0x20] */
/* @0x2368ec str r4, [r3] */
/* @0x2368f0 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2368f4 andseq r10, r11, r4, lsr #24 */

/* ── FUNC 0x2368f8 · CPhysicsFixture::SetPolygonShape() · size=108 · insn=27 */
/* @0x2368f8 push {r4, lr} */
/* @0x2368fc mov r4, r0 */
/* @0x236900 bl 0x2365d0 <_ZN15CPhysicsFixture11DeleteShapeEv> */
/* @0x236904 mov r0, #152 */
/* @0x236908 bl 0x27c524 <_Znwj> */
/* @0x23690c ldr r12, [r4, #0x20] */
/* @0x236910 ldr r2, [pc, #0x48] */
/* @0x236914 mov r1, #2 */
/* @0x236918 ldr r2, [pc, r2] */
/* @0x23691c add r2, r2, #8 */
/* @0x236920 mov r3, r0 */
/* @0x236924 movw r0, #0xd70a */
/* @0x236928 str r1, [r3, #0x4] */
/* @0x23692c movt r0, #0x3c23 */
/* @0x236930 str r2, [r3] */
/* @0x236934 mov r1, #8 */
/* @0x236938 str r0, [r3, #0x8] */
/* @0x23693c mov r2, #0 */
/* @0x236940 mov r0, r4 */
/* @0x236944 str r2, [r3, #0x94] */
/* @0x236948 pop {r4, lr} */
/* @0x23694c mov r2, #0 */
/* @0x236950 str r2, [r3, #0xc] */
/* @0x236954 str r2, [r3, #0x10] */
/* @0x236958 str r3, [r12] */
/* @0x23695c b 0x23658c <_ZN15CPhysicsFixture13AllocVerticesEi> */
/* @0x236960 mulseq r11, r8, r11 */
