/* libyoyo.so 覆盖卡组 0022
 * 函数 0xf4c38..0xf5098，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0xf4c38 · CExtensionFunction::GetArgCount() · size=8 · insn=2 */
/* @0xf4c38 ldr r0, [r0, #0x14] */
/* @0xf4c3c bx lr */

/* ── FUNC 0xf4c40 · CExtensionFunction::SetArgCount(int) · size=8 · insn=2 */
/* @0xf4c40 str r1, [r0, #0x14] */
/* @0xf4c44 bx lr */

/* ── FUNC 0xf4c48 · CExtensionFunction::GetReturnType() · size=8 · insn=2 */
/* @0xf4c48 ldr r0, [r0, #0x58] */
/* @0xf4c4c bx lr */

/* ── FUNC 0xf4c50 · CExtensionFunction::SetReturnType(int) · size=8 · insn=2 */
/* @0xf4c50 str r1, [r0, #0x58] */
/* @0xf4c54 bx lr */

/* ── FUNC 0xf4c58 · CExtensionFunction::GetScript() · size=8 · insn=2 */
/* @0xf4c58 ldr r0, [r0, #0x5c] */
/* @0xf4c5c bx lr */

/* ── FUNC 0xf4c60 · CExtensionFunction::SetScript(char const*) · size=44 · insn=11 */
/* @0xf4c60 push {r3, r4, r5, lr} */
/* @0xf4c64 mov r4, r0 */
/* @0xf4c68 ldr r0, [r0, #0x5c] */
/* @0xf4c6c mov r5, r1 */
/* @0xf4c70 cmp r0, #0 */
/* @0xf4c74 beq 0xf4c7c <_ZN18CExtensionFunction9SetScriptEPKc+0x1c> */
/* @0xf4c78 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xf4c7c mov r0, r5 */
/* @0xf4c80 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xf4c84 str r0, [r4, #0x5c] */
/* @0xf4c88 pop {r3, r4, r5, pc} */

/* ── FUNC 0xf4c8c · CExtensionFile::GetFunction(int) · size=40 · insn=10 */
/* @0xf4c8c cmp r1, #0 */
/* @0xf4c90 blt 0xf4cac <_ZN14CExtensionFile11GetFunctionEi+0x20> */
/* @0xf4c94 ldr r3, [r0, #0x1c] */
/* @0xf4c98 cmp r1, r3 */
/* @0xf4c9c bge 0xf4cac <_ZN14CExtensionFile11GetFunctionEi+0x20> */
/* @0xf4ca0 ldr r3, [r0, #0x18] */
/* @0xf4ca4 ldr r0, [r3, r1, lsl #2] */
/* @0xf4ca8 bx lr */
/* @0xf4cac mov r0, #0 */
/* @0xf4cb0 bx lr */

/* ── FUNC 0xf4cb4 · CExtensionFile::SetFunction(int, CExtensionFunction*) · size=36 · insn=9 */
/* @0xf4cb4 subs r3, r1, #0 */
/* @0xf4cb8 bxlt lr */
/* @0xf4cbc ldr r12, [r0, #0x1c] */
/* @0xf4cc0 cmp r3, r12 */
/* @0xf4cc4 bxge lr */
/* @0xf4cc8 ldr r0, [r0, #0x18] */
/* @0xf4ccc mov r1, r2 */
/* @0xf4cd0 ldr r0, [r0, r3, lsl #2] */
/* @0xf4cd4 b 0xf4a0c <_ZN18CExtensionFunction6AssignEPS_> */

/* ── FUNC 0xf4cd8 · CExtensionFile::SetCFunctions(int) · size=176 · insn=44 */
/* @0xf4cd8 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0xf4cdc bic r7, r1, r1, asr #31 */
/* @0xf4ce0 ldr r3, [r0, #0x1c] */
/* @0xf4ce4 mov r4, r0 */
/* @0xf4ce8 lsl r9, r7, #2 */
/* @0xf4cec cmp r7, r3 */
/* @0xf4cf0 bge 0xf4d28 <_ZN14CExtensionFile13SetCFunctionsEi+0x50> */
/* @0xf4cf4 mov r6, r7 */
/* @0xf4cf8 mov r8, #0 */
/* @0xf4cfc mov r5, r9 */
/* @0xf4d00 ldr r3, [r4, #0x18] */
/* @0xf4d04 add r6, r6, #1 */
/* @0xf4d08 ldr r0, [r3, r5] */
/* @0xf4d0c bl 0xf4b94 <_ZN18CExtensionFunction4FreeEv> */
/* @0xf4d10 ldr r2, [r4, #0x1c] */
/* @0xf4d14 ldr r3, [r4, #0x18] */
/* @0xf4d18 cmp r2, r6 */
/* @0xf4d1c str r8, [r3, r5] */
/* @0xf4d20 add r5, r5, #4 */
/* @0xf4d24 bgt 0xf4d00 <_ZN14CExtensionFile13SetCFunctionsEi+0x28> */
/* @0xf4d28 ldr r2, [pc, #0x54] */
/* @0xf4d2c mov r1, r9 */
/* @0xf4d30 add r0, r4, #24 */
/* @0xf4d34 movw r3, #0x152 */
/* @0xf4d38 add r2, pc, r2 */
/* @0xf4d3c bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0xf4d40 ldr r5, [r4, #0x1c] */
/* @0xf4d44 str r7, [r4, #0x14] */
/* @0xf4d48 cmp r7, r5 */
/* @0xf4d4c lslgt r6, r5, #2 */
/* @0xf4d50 ble 0xf4d7c <_ZN14CExtensionFile13SetCFunctionsEi+0xa4> */
/* @0xf4d54 mov r0, #100 */
/* @0xf4d58 add r5, r5, #1 */
/* @0xf4d5c bl 0x27c524 <_Znwj> */
/* @0xf4d60 mov r8, r0 */
/* @0xf4d64 bl 0xf49e4 <_ZN18CExtensionFunctionC2Ev> */
/* @0xf4d68 ldr r3, [r4, #0x18] */
/* @0xf4d6c cmp r5, r7 */
/* @0xf4d70 str r8, [r3, r6] */
/* @0xf4d74 add r6, r6, #4 */
/* @0xf4d78 bne 0xf4d54 <_ZN14CExtensionFile13SetCFunctionsEi+0x7c> */
/* @0xf4d7c str r7, [r4, #0x1c] */
/* @0xf4d80 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0xf4d84 .word 0x00242bdc */

/* ── FUNC 0xf4d88 · CExtensionFile::GetConstant(int) · size=40 · insn=10 */
/* @0xf4d88 cmp r1, #0 */
/* @0xf4d8c blt 0xf4da8 <_ZN14CExtensionFile11GetConstantEi+0x20> */
/* @0xf4d90 ldr r3, [r0, #0x28] */
/* @0xf4d94 cmp r1, r3 */
/* @0xf4d98 bge 0xf4da8 <_ZN14CExtensionFile11GetConstantEi+0x20> */
/* @0xf4d9c ldr r3, [r0, #0x24] */
/* @0xf4da0 ldr r0, [r3, r1, lsl #2] */
/* @0xf4da4 bx lr */
/* @0xf4da8 mov r0, #0 */
/* @0xf4dac bx lr */

/* ── FUNC 0xf4db0 · CExtensionFile::SetConstant(int, CExtensionConstant*) · size=36 · insn=9 */
/* @0xf4db0 subs r3, r1, #0 */
/* @0xf4db4 bxlt lr */
/* @0xf4db8 ldr r12, [r0, #0x28] */
/* @0xf4dbc cmp r3, r12 */
/* @0xf4dc0 bxge lr */
/* @0xf4dc4 ldr r0, [r0, #0x24] */
/* @0xf4dc8 mov r1, r2 */
/* @0xf4dcc ldr r0, [r0, r3, lsl #2] */
/* @0xf4dd0 b 0xf482c <_ZN18CExtensionConstant6AssignEPS_> */

/* ── FUNC 0xf4dd4 · CExtensionFile::SetCConstants(int) · size=176 · insn=44 */
/* @0xf4dd4 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0xf4dd8 bic r7, r1, r1, asr #31 */
/* @0xf4ddc ldr r3, [r0, #0x28] */
/* @0xf4de0 mov r4, r0 */
/* @0xf4de4 lsl r9, r7, #2 */
/* @0xf4de8 cmp r7, r3 */
/* @0xf4dec bge 0xf4e24 <_ZN14CExtensionFile13SetCConstantsEi+0x50> */
/* @0xf4df0 mov r6, r7 */
/* @0xf4df4 mov r8, #0 */
/* @0xf4df8 mov r5, r9 */
/* @0xf4dfc ldr r3, [r4, #0x24] */
/* @0xf4e00 add r6, r6, #1 */
/* @0xf4e04 ldr r0, [r3, r5] */
/* @0xf4e08 bl 0xf48f0 <_ZN18CExtensionConstant4FreeEv> */
/* @0xf4e0c ldr r2, [r4, #0x28] */
/* @0xf4e10 ldr r3, [r4, #0x24] */
/* @0xf4e14 cmp r2, r6 */
/* @0xf4e18 str r8, [r3, r5] */
/* @0xf4e1c add r5, r5, #4 */
/* @0xf4e20 bgt 0xf4dfc <_ZN14CExtensionFile13SetCConstantsEi+0x28> */
/* @0xf4e24 ldr r2, [pc, #0x54] */
/* @0xf4e28 mov r1, r9 */
/* @0xf4e2c add r0, r4, #36 */
/* @0xf4e30 mov r3, #380 */
/* @0xf4e34 add r2, pc, r2 */
/* @0xf4e38 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0xf4e3c ldr r5, [r4, #0x28] */
/* @0xf4e40 str r7, [r4, #0x20] */
/* @0xf4e44 cmp r7, r5 */
/* @0xf4e48 lslgt r6, r5, #2 */
/* @0xf4e4c ble 0xf4e78 <_ZN14CExtensionFile13SetCConstantsEi+0xa4> */
/* @0xf4e50 mov r0, #12 */
/* @0xf4e54 add r5, r5, #1 */
/* @0xf4e58 bl 0x27c524 <_Znwj> */
/* @0xf4e5c mov r8, r0 */
/* @0xf4e60 bl 0xf4804 <_ZN18CExtensionConstantC2Ev> */
/* @0xf4e64 ldr r3, [r4, #0x24] */
/* @0xf4e68 cmp r5, r7 */
/* @0xf4e6c str r8, [r3, r6] */
/* @0xf4e70 add r6, r6, #4 */
/* @0xf4e74 bne 0xf4e50 <_ZN14CExtensionFile13SetCConstantsEi+0x7c> */
/* @0xf4e78 str r7, [r4, #0x28] */
/* @0xf4e7c pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0xf4e80 eoreq r2, r4, r0, ror #21 */

/* ── FUNC 0xf4e84 · CExtensionFile::FunctionFindName(char const*) · size=92 · insn=23 */
/* @0xf4e84 push {r4, r5, r6, r7, r8, lr} */
/* @0xf4e88 mov r8, r1 */
/* @0xf4e8c ldr r7, [r0, #0x1c] */
/* @0xf4e90 cmp r7, #0 */
/* @0xf4e94 ble 0xf4ed4 <_ZN14CExtensionFile16FunctionFindNameEPKc+0x50> */
/* @0xf4e98 ldr r6, [r0, #0x18] */
/* @0xf4e9c mov r4, #0 */
/* @0xf4ea0 sub r6, r6, #4 */
/* @0xf4ea4 b 0xf4eb0 <_ZN14CExtensionFile16FunctionFindNameEPKc+0x2c> */
/* @0xf4ea8 cmp r4, r7 */
/* @0xf4eac beq 0xf4ed4 <_ZN14CExtensionFile16FunctionFindNameEPKc+0x50> */
/* @0xf4eb0 ldr r5, [r6, #0x4]! */
/* @0xf4eb4 mov r1, r8 */
/* @0xf4eb8 add r4, r4, #1 */
/* @0xf4ebc ldr r0, [r5, #0x4] */
/* @0xf4ec0 bl 0xb6574 <strcmp@plt> */
/* @0xf4ec4 cmp r0, #0 */
/* @0xf4ec8 bne 0xf4ea8 <_ZN14CExtensionFile16FunctionFindNameEPKc+0x24> */
/* @0xf4ecc mov r0, r5 */
/* @0xf4ed0 pop {r4, r5, r6, r7, r8, pc} */
/* @0xf4ed4 mov r5, #0 */
/* @0xf4ed8 mov r0, r5 */
/* @0xf4edc pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0xf4ee0 · CExtensionFile::FunctionFindId(int) · size=84 · insn=21 */
/* @0xf4ee0 str r4, [sp, #-0x4]! */
/* @0xf4ee4 ldr r4, [r0, #0x1c] */
/* @0xf4ee8 cmp r4, #0 */
/* @0xf4eec ble 0xf4f28 <_ZN14CExtensionFile14FunctionFindIdEi+0x48> */
/* @0xf4ef0 ldr r2, [r0, #0x18] */
/* @0xf4ef4 ldr r0, [r2] */
/* @0xf4ef8 ldr r3, [r0, #0x10] */
/* @0xf4efc cmp r3, r1 */
/* @0xf4f00 beq 0xf4f2c <_ZN14CExtensionFile14FunctionFindIdEi+0x4c> */
/* @0xf4f04 mov r3, #0 */
/* @0xf4f08 b 0xf4f1c <_ZN14CExtensionFile14FunctionFindIdEi+0x3c> */
/* @0xf4f0c ldr r0, [r2, #0x4]! */
/* @0xf4f10 ldr r12, [r0, #0x10] */
/* @0xf4f14 cmp r12, r1 */
/* @0xf4f18 beq 0xf4f2c <_ZN14CExtensionFile14FunctionFindIdEi+0x4c> */
/* @0xf4f1c add r3, r3, #1 */
/* @0xf4f20 cmp r3, r4 */
/* @0xf4f24 bne 0xf4f0c <_ZN14CExtensionFile14FunctionFindIdEi+0x2c> */
/* @0xf4f28 mov r0, #0 */
/* @0xf4f2c ldr r4, [sp], #4 */
/* @0xf4f30 bx lr */

/* ── FUNC 0xf4f34 · CExtensionFile::ConstantFindName(char const*) · size=92 · insn=23 */
/* @0xf4f34 push {r4, r5, r6, r7, r8, lr} */
/* @0xf4f38 mov r8, r1 */
/* @0xf4f3c ldr r7, [r0, #0x28] */
/* @0xf4f40 cmp r7, #0 */
/* @0xf4f44 ble 0xf4f84 <_ZN14CExtensionFile16ConstantFindNameEPKc+0x50> */
/* @0xf4f48 ldr r6, [r0, #0x24] */
/* @0xf4f4c mov r4, #0 */
/* @0xf4f50 sub r6, r6, #4 */
/* @0xf4f54 b 0xf4f60 <_ZN14CExtensionFile16ConstantFindNameEPKc+0x2c> */
/* @0xf4f58 cmp r4, r7 */
/* @0xf4f5c beq 0xf4f84 <_ZN14CExtensionFile16ConstantFindNameEPKc+0x50> */
/* @0xf4f60 ldr r5, [r6, #0x4]! */
/* @0xf4f64 mov r1, r8 */
/* @0xf4f68 add r4, r4, #1 */
/* @0xf4f6c ldr r0, [r5, #0x4] */
/* @0xf4f70 bl 0xb6574 <strcmp@plt> */
/* @0xf4f74 cmp r0, #0 */
/* @0xf4f78 bne 0xf4f58 <_ZN14CExtensionFile16ConstantFindNameEPKc+0x24> */
/* @0xf4f7c mov r0, r5 */
/* @0xf4f80 pop {r4, r5, r6, r7, r8, pc} */
/* @0xf4f84 mov r5, #0 */
/* @0xf4f88 mov r0, r5 */
/* @0xf4f8c pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0xf4f90 · CExtensionFile::Free() · size=28 · insn=7 */
/* @0xf4f90 push {r3, lr} */
/* @0xf4f94 subs r3, r0, #0 */
/* @0xf4f98 popeq {r3, pc} */
/* @0xf4f9c ldr r3, [r3] */
/* @0xf4fa0 ldr r3, [r3, #0x4] */
/* @0xf4fa4 blx r3 */
/* @0xf4fa8 pop {r3, pc} */

/* ── FUNC 0xf4fac · CExtensionFile::GetFileName() · size=8 · insn=2 */
/* @0xf4fac ldr r0, [r0, #0x4] */
/* @0xf4fb0 bx lr */

/* ── FUNC 0xf4fb4 · CExtensionFile::SetFileName(char const*) · size=44 · insn=11 */
/* @0xf4fb4 push {r3, r4, r5, lr} */
/* @0xf4fb8 mov r4, r0 */
/* @0xf4fbc ldr r0, [r0, #0x4] */
/* @0xf4fc0 mov r5, r1 */
/* @0xf4fc4 cmp r0, #0 */
/* @0xf4fc8 beq 0xf4fd0 <_ZN14CExtensionFile11SetFileNameEPKc+0x1c> */
/* @0xf4fcc bl 0xcef90 <_Z6YYFreePKv> */
/* @0xf4fd0 mov r0, r5 */
/* @0xf4fd4 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xf4fd8 str r0, [r4, #0x4] */
/* @0xf4fdc pop {r3, r4, r5, pc} */

/* ── FUNC 0xf4fe0 · CExtensionFile::GetKind() · size=8 · insn=2 */
/* @0xf4fe0 ldr r0, [r0, #0x8] */
/* @0xf4fe4 bx lr */

/* ── FUNC 0xf4fe8 · CExtensionFile::SetKind(int) · size=8 · insn=2 */
/* @0xf4fe8 str r1, [r0, #0x8] */
/* @0xf4fec bx lr */

/* ── FUNC 0xf4ff0 · CExtensionFile::GetFunction_Init() · size=8 · insn=2 */
/* @0xf4ff0 ldr r0, [r0, #0xc] */
/* @0xf4ff4 bx lr */

/* ── FUNC 0xf4ff8 · CExtensionFile::SetFunction_Init(char const*) · size=24 · insn=6 */
/* @0xf4ff8 push {r4, lr} */
/* @0xf4ffc mov r4, r0 */
/* @0xf5000 mov r0, r1 */
/* @0xf5004 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xf5008 str r0, [r4, #0xc] */
/* @0xf500c pop {r4, pc} */

/* ── FUNC 0xf5010 · CExtensionFile::GetFunction_Final() · size=8 · insn=2 */
/* @0xf5010 ldr r0, [r0, #0x10] */
/* @0xf5014 bx lr */

/* ── FUNC 0xf5018 · CExtensionFile::SetFunction_Final(char const*) · size=44 · insn=11 */
/* @0xf5018 push {r3, r4, r5, lr} */
/* @0xf501c mov r4, r0 */
/* @0xf5020 ldr r0, [r0, #0x10] */
/* @0xf5024 mov r5, r1 */
/* @0xf5028 cmp r0, #0 */
/* @0xf502c beq 0xf5034 <_ZN14CExtensionFile17SetFunction_FinalEPKc+0x1c> */
/* @0xf5030 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xf5034 mov r0, r5 */
/* @0xf5038 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xf503c str r0, [r4, #0x10] */
/* @0xf5040 pop {r3, r4, r5, pc} */

/* ── FUNC 0xf5044 · CExtensionFile::GetFunctionsCount() · size=8 · insn=2 */
/* @0xf5044 ldr r0, [r0, #0x1c] */
/* @0xf5048 bx lr */

/* ── FUNC 0xf504c · CExtensionFile::SetFunctionsCount(int) · size=4 · insn=1 */
/* @0xf504c b 0xf4cd8 <_ZN14CExtensionFile13SetCFunctionsEi> */

/* ── FUNC 0xf5050 · CExtensionFile::GetFunctionsData(int) · size=4 · insn=1 */
/* @0xf5050 b 0xf4c8c <_ZN14CExtensionFile11GetFunctionEi> */

/* ── FUNC 0xf5054 · CExtensionFile::SetFunctionsData(int, CExtensionFunction*) · size=4 · insn=1 */
/* @0xf5054 b 0xf4cb4 <_ZN14CExtensionFile11SetFunctionEiP18CExtensionFunction> */

/* ── FUNC 0xf5058 · CExtensionFile::GetConstantsCount() · size=8 · insn=2 */
/* @0xf5058 ldr r0, [r0, #0x28] */
/* @0xf505c bx lr */

/* ── FUNC 0xf5060 · CExtensionFile::SetConstantsCount(int) · size=4 · insn=1 */
/* @0xf5060 b 0xf4dd4 <_ZN14CExtensionFile13SetCConstantsEi> */

/* ── FUNC 0xf5064 · CExtensionFile::Clear() · size=52 · insn=13 */
/* @0xf5064 push {r3, r4, r5, lr} */
/* @0xf5068 mov r4, #0 */
/* @0xf506c mov r5, r0 */
/* @0xf5070 mov r1, r4 */
/* @0xf5074 str r4, [r0, #0x4] */
/* @0xf5078 str r4, [r0, #0x8] */
/* @0xf507c str r4, [r0, #0xc] */
/* @0xf5080 str r4, [r0, #0x10] */
/* @0xf5084 bl 0xf504c <_ZN14CExtensionFile17SetFunctionsCountEi> */
/* @0xf5088 mov r0, r5 */
/* @0xf508c mov r1, r4 */
/* @0xf5090 pop {r3, r4, r5, lr} */
/* @0xf5094 b 0xf5060 <_ZN14CExtensionFile17SetConstantsCountEi> */

/* ── FUNC 0xf5098 · CExtensionFile::CExtensionFile() · size=76 · insn=19 */
/* @0xf5098 ldr r2, [pc, #0x40] */
/* @0xf509c mov r3, #0 */
/* @0xf50a0 push {r4, lr} */
/* @0xf50a4 ldr r2, [pc, r2] */
/* @0xf50a8 mov r4, r0 */
/* @0xf50ac str r3, [r0, #0x18] */
/* @0xf50b0 str r3, [r0, #0x14] */
/* @0xf50b4 add r2, r2, #8 */
/* @0xf50b8 str r3, [r0, #0x1c] */
/* @0xf50bc str r2, [r0] */
/* @0xf50c0 str r3, [r0, #0x24] */
/* @0xf50c4 str r3, [r0, #0x20] */
/* @0xf50c8 str r3, [r0, #0x28] */
/* @0xf50cc str r3, [r0, #0x10] */
/* @0xf50d0 str r3, [r0, #0xc] */
/* @0xf50d4 bl 0xf5064 <_ZN14CExtensionFile5ClearEv> */
/* @0xf50d8 mov r0, r4 */
/* @0xf50dc pop {r4, pc} */
/* @0xf50e0 eoreq r8, pc, r8, lsl #27 */
