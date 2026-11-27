/* libyoyo.so 覆盖卡组 0190
 * 函数 0x214e1c..0x2157c8，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x214e1c · GetCurrentDir() · size=44 · insn=11 */
/* @0x214e1c ldr r1, [pc, #0x20] */
/* @0x214e20 mov r2, #234 */
/* @0x214e24 push {r3, lr} */
/* @0x214e28 add r1, pc, r1 */
/* @0x214e2c mov r3, #0 */
/* @0x214e30 mov r0, #1 */
/* @0x214e34 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x214e38 mov r2, #0 */
/* @0x214e3c strb r2, [r0] */
/* @0x214e40 pop {r3, pc} */
/* @0x214e44 andseq lr, r3, r4, lsr #24 */

/* ── FUNC 0x214e48 · FileExists(char const*) · size=40 · insn=10 */
/* @0x214e48 push {r4, lr} */
/* @0x214e4c mov r4, r0 */
/* @0x214e50 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc> */
/* @0x214e54 cmp r0, #0 */
/* @0x214e58 beq 0x214e64 <_Z10FileExistsPKc+0x1c> */
/* @0x214e5c mov r0, #1 */
/* @0x214e60 pop {r4, pc} */
/* @0x214e64 mov r0, r4 */
/* @0x214e68 pop {r4, lr} */
/* @0x214e6c b 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc> */

/* ── FUNC 0x214e70 · File_TempFile(char const*) · size=180 · insn=45 */
/* @0x214e70 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x214e74 sub sp, sp, #1040 */
/* @0x214e78 ldr r9, [pc, #0x98] */
/* @0x214e7c sub sp, sp, #4 */
/* @0x214e80 add r4, sp, #12 */
/* @0x214e84 ldr r6, [pc, #0x90] */
/* @0x214e88 ldr r9, [pc, r9] */
/* @0x214e8c ldr r7, [pc, #0x8c] */
/* @0x214e90 mov r8, r0 */
/* @0x214e94 mov r1, #0 */
/* @0x214e98 ldr r3, [r9] */
/* @0x214e9c mov r0, r4 */
/* @0x214ea0 mov r2, #1024 */
/* @0x214ea4 add r7, pc, r7 */
/* @0x214ea8 str r3, [sp, #0x40c] */
/* @0x214eac bl 0xb65b0 <memset@plt> */
/* @0x214eb0 ldr r6, [pc, r6] */
/* @0x214eb4 movw r0, #0x86a0 */
/* @0x214eb8 movt r0, #0x1 */
/* @0x214ebc ldr r5, [r6] */
/* @0x214ec0 bl 0xc4600 <_Z8YYRandomi> */
/* @0x214ec4 mov r1, #1024 */
/* @0x214ec8 mov r2, r7 */
/* @0x214ecc str r8, [sp, #0x4] */
/* @0x214ed0 mov r3, r5 */
/* @0x214ed4 str r0, [sp] */
/* @0x214ed8 mov r0, r4 */
/* @0x214edc bl 0xb65c8 <snprintf@plt> */
/* @0x214ee0 mov r0, r4 */
/* @0x214ee4 bl 0x214e48 <_Z10FileExistsPKc> */
/* @0x214ee8 cmp r0, #0 */
/* @0x214eec bne 0x214eb4 <_Z13File_TempFilePKc+0x44> */
/* @0x214ef0 mov r0, r4 */
/* @0x214ef4 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x214ef8 ldr r2, [sp, #0x40c] */
/* @0x214efc ldr r3, [r9] */
/* @0x214f00 cmp r2, r3 */
/* @0x214f04 bne 0x214f14 <_Z13File_TempFilePKc+0xa4> */
/* @0x214f08 add sp, sp, #1040 */
/* @0x214f0c add sp, sp, #4 */
/* @0x214f10 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x214f14 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x214f18 andseq r8, sp, r8, asr #21 */
/* @0x214f1c andseq r12, sp, r0, lsl r5 */
/* @0x214f20 andseq lr, r3, r12, ror #23 */

/* ── FUNC 0x214f24 · DirectoryExists(char const*) · size=56 · insn=14 */
/* @0x214f24 str lr, [sp, #-0x4]! */
/* @0x214f28 sub sp, sp, #108 */
/* @0x214f2c mov r1, sp */
/* @0x214f30 bl 0xb69f4 <stat@plt> */
/* @0x214f34 cmp r0, #0 */
/* @0x214f38 movne r0, #0 */
/* @0x214f3c bne 0x214f54 <_Z15DirectoryExistsPKc+0x30> */
/* @0x214f40 ldr r0, [sp, #0x10] */
/* @0x214f44 and r0, r0, #61440 */
/* @0x214f48 subs r3, r0, #16384 */
/* @0x214f4c rsbs r0, r3, #0 */
/* @0x214f50 adcs r0, r0, r3 */
/* @0x214f54 add sp, sp, #108 */
/* @0x214f58 ldr pc, [sp], #4 */

/* ── FUNC 0x214f5c · ExtractFilePath(char const*) · size=128 · insn=32 */
/* @0x214f5c push {r4, r5, r6, lr} */
/* @0x214f60 mov r1, #92 */
/* @0x214f64 mov r2, #47 */
/* @0x214f68 mov r5, r0 */
/* @0x214f6c bl 0x10fbbc <utf8_strrchr> */
/* @0x214f70 cmp r0, #0 */
/* @0x214f74 beq 0x214fc4 <_Z15ExtractFilePathPKc+0x68> */
/* @0x214f78 rsb r4, r5, r0 */
/* @0x214f7c cmp r4, #0 */
/* @0x214f80 ble 0x214fc4 <_Z15ExtractFilePathPKc+0x68> */
/* @0x214f84 ldr r1, [pc, #0x48] */
/* @0x214f88 mov r3, #1 */
/* @0x214f8c mov r2, #70 */
/* @0x214f90 add r0, r4, #1 */
/* @0x214f94 add r1, pc, r1 */
/* @0x214f98 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x214f9c mov r1, r5 */
/* @0x214fa0 mov r2, r4 */
/* @0x214fa4 mov r6, r0 */
/* @0x214fa8 bl 0xb6568 <strncpy@plt> */
/* @0x214fac cmp r6, #0 */
/* @0x214fb0 mov r3, #0 */
/* @0x214fb4 strb r3, [r6, r4] */
/* @0x214fb8 beq 0x214fc4 <_Z15ExtractFilePathPKc+0x68> */
/* @0x214fbc mov r0, r6 */
/* @0x214fc0 pop {r4, r5, r6, pc} */
/* @0x214fc4 ldr r0, [pc, #0xc] */
/* @0x214fc8 pop {r4, r5, r6, lr} */
/* @0x214fcc add r0, pc, r0 */
/* @0x214fd0 b 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x214fd4 mulseq r1, r12, r0 */
/* @0x214fd8 andseq r9, r1, r10, ror #22 */

/* ── FUNC 0x214fdc · ExtractFileDrive(char const*) · size=4 · insn=1 */
/* @0x214fdc b 0xdb8c8 <_Z8YYStrDupPKc> */

/* ── FUNC 0x214fe0 · ExtractFileName(char const*) · size=40 · insn=10 */
/* @0x214fe0 push {r4, lr} */
/* @0x214fe4 mov r1, #92 */
/* @0x214fe8 mov r2, #47 */
/* @0x214fec mov r4, r0 */
/* @0x214ff0 bl 0x10fbbc <utf8_strrchr> */
/* @0x214ff4 cmp r0, #0 */
/* @0x214ff8 addne r4, r0, #1 */
/* @0x214ffc mov r0, r4 */
/* @0x215000 pop {r4, lr} */
/* @0x215004 b 0xdb8c8 <_Z8YYStrDupPKc> */

/* ── FUNC 0x215008 · ExtractFileExt(char const*) · size=52 · insn=13 */
/* @0x215008 mov r1, #46 */
/* @0x21500c push {r3, lr} */
/* @0x215010 mov r2, r1 */
/* @0x215014 bl 0x10fbbc <utf8_strrchr> */
/* @0x215018 cmp r0, #0 */
/* @0x21501c beq 0x215028 <_Z14ExtractFileExtPKc+0x20> */
/* @0x215020 pop {r3, lr} */
/* @0x215024 b 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x215028 ldr r0, [pc, #0x8] */
/* @0x21502c pop {r3, lr} */
/* @0x215030 add r0, pc, r0 */
/* @0x215034 b 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x215038 andseq r9, r1, r6, lsl #22 */

/* ── FUNC 0x21503c · IsPathDelimiter(char const*, int) · size=60 · insn=15 */
/* @0x21503c push {r3, r4, r5, lr} */
/* @0x215040 subs r4, r1, #0 */
/* @0x215044 mov r5, r0 */
/* @0x215048 ble 0x215070 <_Z15IsPathDelimiterPKci+0x34> */
/* @0x21504c bl 0xb6538 <strlen@plt> */
/* @0x215050 cmp r4, r0 */
/* @0x215054 bge 0x215070 <_Z15IsPathDelimiterPKci+0x34> */
/* @0x215058 ldrb r0, [r5, r4] */
/* @0x21505c cmp r0, #92 */
/* @0x215060 cmpne r0, #47 */
/* @0x215064 movne r0, #0 */
/* @0x215068 moveq r0, #1 */
/* @0x21506c pop {r3, r4, r5, pc} */
/* @0x215070 mov r0, #0 */
/* @0x215074 pop {r3, r4, r5, pc} */

/* ── FUNC 0x215078 · ExcludeTrailingPathDelimiter(char const*) · size=60 · insn=15 */
/* @0x215078 push {r4, lr} */
/* @0x21507c mov r4, r0 */
/* @0x215080 bl 0xb6538 <strlen@plt> */
/* @0x215084 sub r1, r0, #1 */
/* @0x215088 mov r0, r4 */
/* @0x21508c bl 0x21503c <_Z15IsPathDelimiterPKci> */
/* @0x215090 cmp r0, #0 */
/* @0x215094 beq 0x2150ac <_Z28ExcludeTrailingPathDelimiterPKc+0x34> */
/* @0x215098 mov r0, r4 */
/* @0x21509c bl 0xb6538 <strlen@plt> */
/* @0x2150a0 mov r3, #0 */
/* @0x2150a4 add r0, r4, r0 */
/* @0x2150a8 strb r3, [r0, #-0x1] */
/* @0x2150ac mov r0, r4 */
/* @0x2150b0 pop {r4, pc} */

/* ── FUNC 0x2150b4 · ForceDirectories(char const*) · size=144 · insn=36 */
/* @0x2150b4 subs r3, r0, #0 */
/* @0x2150b8 push {r4, lr} */
/* @0x2150bc beq 0x2150cc <_Z16ForceDirectoriesPKc+0x18> */
/* @0x2150c0 ldrb r3, [r3] */
/* @0x2150c4 cmp r3, #0 */
/* @0x2150c8 bne 0x2150d4 <_Z16ForceDirectoriesPKc+0x20> */
/* @0x2150cc mov r0, #0 */
/* @0x2150d0 pop {r4, pc} */
/* @0x2150d4 bl 0x215078 <_Z28ExcludeTrailingPathDelimiterPKc> */
/* @0x2150d8 mov r4, r0 */
/* @0x2150dc bl 0xb6538 <strlen@plt> */
/* @0x2150e0 cmp r0, #2 */
/* @0x2150e4 bhi 0x2150f0 <_Z16ForceDirectoriesPKc+0x3c> */
/* @0x2150e8 mov r0, #1 */
/* @0x2150ec pop {r4, pc} */
/* @0x2150f0 mov r0, r4 */
/* @0x2150f4 bl 0x214f24 <_Z15DirectoryExistsPKc> */
/* @0x2150f8 cmp r0, #0 */
/* @0x2150fc bne 0x2150e8 <_Z16ForceDirectoriesPKc+0x34> */
/* @0x215100 mov r0, r4 */
/* @0x215104 bl 0x214f5c <_Z15ExtractFilePathPKc> */
/* @0x215108 mov r1, r4 */
/* @0x21510c bl 0xb6574 <strcmp@plt> */
/* @0x215110 cmp r0, #0 */
/* @0x215114 beq 0x2150e8 <_Z16ForceDirectoriesPKc+0x34> */
/* @0x215118 mov r0, r4 */
/* @0x21511c bl 0x214f5c <_Z15ExtractFilePathPKc> */
/* @0x215120 bl 0x2150b4 <_Z16ForceDirectoriesPKc> */
/* @0x215124 cmp r0, #0 */
/* @0x215128 beq 0x2150cc <_Z16ForceDirectoriesPKc+0x18> */
/* @0x21512c mov r0, r4 */
/* @0x215130 movw r1, #0x1fd */
/* @0x215134 bl 0xb6a00 <mkdir@plt> */
/* @0x215138 rsbs r0, r0, #1 */
/* @0x21513c movlo r0, #0 */
/* @0x215140 pop {r4, pc} */

/* ── FUNC 0x215144 · anon_215144 · size=0 · insn=1 */
/* @0x215144 andeq r0, r0, r0 */

/* ── FUNC 0x215148 · Timing_Time · size=108 · insn=27 */
/* @0x215148 str lr, [sp, #-0x4]! */
/* @0x21514c sub sp, sp, #12 */
/* @0x215150 mov r0, #1 */
/* @0x215154 mov r1, sp */
/* @0x215158 bl 0xb6a0c <clock_gettime@plt> */
/* @0x21515c vldr s7, [sp] */
/* @0x215160 vcvt.f64.s32 d4, s7 */
/* @0x215164 vldr s7, [sp, #4] */
/* @0x215168 vldr d5, [pc, #48] */
/* @0x21516c vldr d6, [pc, #52] */
/* @0x215170 vcvt.f64.s32 d7, s7 */
/* @0x215174 vmla.f64 d7, d4, d5 */
/* @0x215178 vdiv.f64 d5, d7, d6 */
/* @0x21517c vmov r0, r1, d5 */
/* @0x215180 bl 0x3194a0 <__fixdfdi> */
/* @0x215184 ldr r3, [pc, #0x24] */
/* @0x215188 add r3, pc, r3 */
/* @0x21518c ldrd r2, r3, [r3] */
/* @0x215190 subs r0, r0, r2 */
/* @0x215194 sbc r1, r1, r3 */
/* @0x215198 add sp, sp, #12 */
/* @0x21519c ldr pc, [sp], #4 */
/* @0x2151a0 andeq r0, r0, r0 */
/* @0x2151a4 bicmi r12, sp, r5, ror #26 */
/* @0x2151a8 andeq r0, r0, r0 */
/* @0x2151ac addmi r4, pc, r0 */
/* @0x2151b0 subseq r0, r4, r0, lsl #2 */

/* ── FUNC 0x2151b4 · anon_2151b4 · size=0 · insn=1 */
/* @0x2151b4 nop */

/* ── FUNC 0x2151b8 · Timing_Init · size=56 · insn=14 */
/* @0x2151b8 push {r4, lr} */
/* @0x2151bc mov r3, #0 */
/* @0x2151c0 ldr r4, [pc, #0x20] */
/* @0x2151c4 mov r2, #0 */
/* @0x2151c8 add r4, pc, r4 */
/* @0x2151cc strd r2, r3, [r4] */
/* @0x2151d0 bl 0x215148 <Timing_Time> */
/* @0x2151d4 ldr r3, [pc, #0x10] */
/* @0x2151d8 ldr r3, [pc, r3] */
/* @0x2151dc strd r0, r1, [r4] */
/* @0x2151e0 strd r0, r1, [r3] */
/* @0x2151e4 pop {r4, pc} */
/* @0x2151e8 subseq r0, r4, r0, asr #1 */
/* @0x2151ec andseq r9, sp, r4, ror r0 */

/* ── FUNC 0x2151f0 · Timing_Sleep · size=148 · insn=37 */
/* @0x2151f0 push {r3, r4, r5, r6, r7, lr} */
/* @0x2151f4 mov r6, r0 */
/* @0x2151f8 mov r7, r1 */
/* @0x2151fc cmp r6, #1 */
/* @0x215200 sbcs r1, r7, #0 */
/* @0x215204 poplt {r3, r4, r5, r6, r7, pc} */
/* @0x215208 bl 0x215148 <Timing_Time> */
/* @0x21520c ldr r3, [pc, #0x6c] */
/* @0x215210 mov r2, #1000 */
/* @0x215214 ldr r3, [pc, r3] */
/* @0x215218 ldr r12, [r3] */
/* @0x21521c mul r2, r2, r12 */
/* @0x215220 asr r3, r2, #31 */
/* @0x215224 adds r4, r0, r6 */
/* @0x215228 adc r5, r1, r7 */
/* @0x21522c cmp r2, r6 */
/* @0x215230 sbcs r1, r3, r7 */
/* @0x215234 blt 0x215254 <Timing_Sleep+0x64> */
/* @0x215238 bl 0x215148 <Timing_Time> */
/* @0x21523c subs r0, r4, r0 */
/* @0x215240 sbc r1, r5, r1 */
/* @0x215244 cmp r0, #1 */
/* @0x215248 sbcs r3, r1, #0 */
/* @0x21524c bge 0x215238 <Timing_Sleep+0x48> */
/* @0x215250 pop {r3, r4, r5, r6, r7, pc} */
/* @0x215254 movw r0, #0xfc18 */
/* @0x215258 movt r0, #0xffff */
/* @0x21525c mla r0, r0, r12, r6 */
/* @0x215260 bl 0xb6a18 <usleep@plt> */
/* @0x215264 bl 0x215148 <Timing_Time> */
/* @0x215268 subs r0, r4, r0 */
/* @0x21526c sbc r1, r5, r1 */
/* @0x215270 cmp r0, #1 */
/* @0x215274 sbcs r3, r1, #0 */
/* @0x215278 bge 0x215238 <Timing_Sleep+0x48> */
/* @0x21527c pop {r3, r4, r5, r6, r7, pc} */
/* @0x215280 andseq r9, sp, r0, lsr #7 */

/* ── FUNC 0x215284 · EnvironmentGetVariable(char*) · size=24 · insn=6 */
/* @0x215284 push {r3, lr} */
/* @0x215288 bl 0xb6a24 <getenv@plt> */
/* @0x21528c cmp r0, #0 */
/* @0x215290 popeq {r3, pc} */
/* @0x215294 pop {r3, lr} */
/* @0x215298 b 0xdb8c8 <_Z8YYStrDupPKc> */

/* ── FUNC 0x21529c · CSound::Clear() · size=184 · insn=46 */
/* @0x21529c push {r4, r5, r6, lr} */
/* @0x2152a0 mov r6, r0 */
/* @0x2152a4 ldr r0, [r0, #0x8] */
/* @0x2152a8 mvn r3, #0 */
/* @0x2152ac str r3, [r6, #0x4] */
/* @0x2152b0 cmp r0, #0 */
/* @0x2152b4 beq 0x2152c4 <_ZN6CSound5ClearEv+0x28> */
/* @0x2152b8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2152bc mov r3, #0 */
/* @0x2152c0 str r3, [r6, #0x8] */
/* @0x2152c4 ldr r0, [r6, #0xc] */
/* @0x2152c8 cmp r0, #0 */
/* @0x2152cc beq 0x2152dc <_ZN6CSound5ClearEv+0x40> */
/* @0x2152d0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2152d4 mov r3, #0 */
/* @0x2152d8 str r3, [r6, #0xc] */
/* @0x2152dc ldr r0, [r6, #0x10] */
/* @0x2152e0 mov r1, #0 */
/* @0x2152e4 mov r2, #0 */
/* @0x2152e8 mov r3, #0 */
/* @0x2152ec cmp r0, r1 */
/* @0x2152f0 movt r3, #0x3ff0 */
/* @0x2152f4 mov r4, #0 */
/* @0x2152f8 mov r5, #0 */
/* @0x2152fc str r1, [r6, #0x18] */
/* @0x215300 mov r1, #1 */
/* @0x215304 strd r4, r5, [r6, #40] */
/* @0x215308 strb r1, [r6, #0x14] */
/* @0x21530c strd r2, r3, [r6, #32] */
/* @0x215310 beq 0x215318 <_ZN6CSound5ClearEv+0x7c> */
/* @0x215314 bl 0x20133c <_ZN7CStream4FreeEv> */
/* @0x215318 ldr r0, [r6, #0x30] */
/* @0x21531c mov r3, #0 */
/* @0x215320 str r3, [r6, #0x10] */
/* @0x215324 cmp r0, r3 */
/* @0x215328 blt 0x215330 <_ZN6CSound5ClearEv+0x94> */
/* @0x21532c bl 0x21eadc <_Z10SND_Deletei> */
/* @0x215330 ldr r0, [r6, #0x34] */
/* @0x215334 mvn r3, #0 */
/* @0x215338 str r3, [r6, #0x30] */
/* @0x21533c cmp r0, #0 */
/* @0x215340 popeq {r4, r5, r6, pc} */
/* @0x215344 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x215348 mov r3, #0 */
/* @0x21534c str r3, [r6, #0x34] */
/* @0x215350 pop {r4, r5, r6, pc} */

/* ── FUNC 0x215354 · CSound::CSound() · size=48 · insn=12 */
/* @0x215354 push {r4, lr} */
/* @0x215358 mov r1, #0 */
/* @0x21535c mov r4, r0 */
/* @0x215360 mov r2, #64 */
/* @0x215364 bl 0xb65b0 <memset@plt> */
/* @0x215368 mvn r3, #0 */
/* @0x21536c mov r0, r4 */
/* @0x215370 str r4, [r4] */
/* @0x215374 str r3, [r4, #0x30] */
/* @0x215378 bl 0x21529c <_ZN6CSound5ClearEv> */
/* @0x21537c mov r0, r4 */
/* @0x215380 pop {r4, pc} */

/* ── FUNC 0x215354 · CSound::CSound() · alias of the symbol above · insn=0 */

/* ── FUNC 0x215384 · CSound::~CSound() · size=20 · insn=5 */
/* @0x215384 push {r4, lr} */
/* @0x215388 mov r4, r0 */
/* @0x21538c bl 0x21529c <_ZN6CSound5ClearEv> */
/* @0x215390 mov r0, r4 */
/* @0x215394 pop {r4, pc} */

/* ── FUNC 0x215384 · CSound::~CSound() · alias of the symbol above · insn=0 */

/* ── FUNC 0x215398 · CSound::LoadFromStream(CStream*) · size=256 · insn=64 */
/* @0x215398 push {r3, r4, r5, r6, r7, lr} */
/* @0x21539c mov r4, r1 */
/* @0x2153a0 mov r5, r0 */
/* @0x2153a4 bl 0x21529c <_ZN6CSound5ClearEv> */
/* @0x2153a8 mov r0, r4 */
/* @0x2153ac bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x2153b0 cmp r0, #800 */
/* @0x2153b4 cmpne r0, #600 */
/* @0x2153b8 mov r6, r0 */
/* @0x2153bc moveq r7, #0 */
/* @0x2153c0 movne r7, #1 */
/* @0x2153c4 movne r3, #0 */
/* @0x2153c8 beq 0x2153d4 <_ZN6CSound14LoadFromStreamEP7CStream+0x3c> */
/* @0x2153cc mov r0, r3 */
/* @0x2153d0 pop {r3, r4, r5, r6, r7, pc} */
/* @0x2153d4 mov r0, r4 */
/* @0x2153d8 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x2153dc ldr r3, [r5, #0x8] */
/* @0x2153e0 cmp r3, #0 */
/* @0x2153e4 str r0, [r5, #0x4] */
/* @0x2153e8 beq 0x2153f8 <_ZN6CSound14LoadFromStreamEP7CStream+0x60> */
/* @0x2153ec mov r0, r3 */
/* @0x2153f0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2153f4 str r7, [r5, #0x8] */
/* @0x2153f8 mov r0, r4 */
/* @0x2153fc add r1, r5, #8 */
/* @0x215400 bl 0x2018e8 <_ZN7CStream10ReadStringERPKc> */
/* @0x215404 ldr r0, [r5, #0xc] */
/* @0x215408 cmp r0, #0 */
/* @0x21540c beq 0x21541c <_ZN6CSound14LoadFromStreamEP7CStream+0x84> */
/* @0x215410 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x215414 mov r3, #0 */
/* @0x215418 str r3, [r5, #0xc] */
/* @0x21541c mov r0, r4 */
/* @0x215420 add r1, r5, #12 */
/* @0x215424 bl 0x2018e8 <_ZN7CStream10ReadStringERPKc> */
/* @0x215428 mov r0, r4 */
/* @0x21542c bl 0x2019b0 <_ZN7CStream11ReadBooleanEv> */
/* @0x215430 cmp r0, #0 */
/* @0x215434 beq 0x21544c <_ZN6CSound14LoadFromStreamEP7CStream+0xb4> */
/* @0x215438 cmp r6, #600 */
/* @0x21543c mov r0, r4 */
/* @0x215440 beq 0x215488 <_ZN6CSound14LoadFromStreamEP7CStream+0xf0> */
/* @0x215444 bl 0x2019c4 <_ZN7CStream10ReadStreamEv> */
/* @0x215448 str r0, [r5, #0x10] */
/* @0x21544c mov r0, r4 */
/* @0x215450 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x215454 str r0, [r5, #0x18] */
/* @0x215458 mov r0, r4 */
/* @0x21545c bl 0x20187c <_ZN7CStream8ReadRealEv> */
/* @0x215460 strd r0, r1, [r5, #32] */
/* @0x215464 mov r0, r4 */
/* @0x215468 bl 0x20187c <_ZN7CStream8ReadRealEv> */
/* @0x21546c strd r0, r1, [r5, #40] */
/* @0x215470 mov r0, r4 */
/* @0x215474 bl 0x2019b0 <_ZN7CStream11ReadBooleanEv> */
/* @0x215478 mov r3, #1 */
/* @0x21547c strb r0, [r5, #0x14] */
/* @0x215480 mov r0, r3 */
/* @0x215484 pop {r3, r4, r5, r6, r7, pc} */
/* @0x215488 bl 0x201d88 <_ZN7CStream20SkipCompressedStreamEv> */
/* @0x21548c mov r3, #0 */
/* @0x215490 str r3, [r5, #0x10] */
/* @0x215494 b 0x21544c <_ZN6CSound14LoadFromStreamEP7CStream+0xb4> */

/* ── FUNC 0x215498 · CSound::LoadFromChunk(YYSound*, unsigned char*) · size=168 · insn=42 */
/* @0x215498 push {r4, r5, r6, lr} */
/* @0x21549c mov r5, r1 */
/* @0x2154a0 mov r4, r0 */
/* @0x2154a4 bl 0x21529c <_ZN6CSound5ClearEv> */
/* @0x2154a8 ldr r0, [r5, #0x8] */
/* @0x2154ac ldr r3, [r5, #0x4] */
/* @0x2154b0 cmp r0, #0 */
/* @0x2154b4 str r3, [r4, #0x4] */
/* @0x2154b8 ldrne r3, [pc, #0x78] */
/* @0x2154bc ldrne r3, [pc, r3] */
/* @0x2154c0 ldrne r3, [r3] */
/* @0x2154c4 addne r0, r3, r0 */
/* @0x2154c8 ldr r3, [r5, #0xc] */
/* @0x2154cc cmp r3, #0 */
/* @0x2154d0 moveq r6, r3 */
/* @0x2154d4 ldrne r2, [pc, #0x60] */
/* @0x2154d8 ldrne r2, [pc, r2] */
/* @0x2154dc ldrne r6, [r2] */
/* @0x2154e0 addne r6, r6, r3 */
/* @0x2154e4 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x2154e8 str r0, [r4, #0x8] */
/* @0x2154ec mov r0, r6 */
/* @0x2154f0 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x2154f4 vldr s12, [r5, #20] */
/* @0x2154f8 vldr s14, [r5, #24] */
/* @0x2154fc vcvt.f64.f32 d6, s12 */
/* @0x215500 ldr r3, [r5, #0x1c] */
/* @0x215504 ldr r1, [r5, #0x10] */
/* @0x215508 ldr r2, [r5, #0x20] */
/* @0x21550c adds r3, r3, #0 */
/* @0x215510 str r1, [r4, #0x18] */
/* @0x215514 movne r3, #1 */
/* @0x215518 str r2, [r4, #0x3c] */
/* @0x21551c vcvt.f64.f32 d7, s14 */
/* @0x215520 strb r3, [r4, #0x14] */
/* @0x215524 vstr d6, [r4, #32] */
/* @0x215528 vstr d7, [r4, #40] */
/* @0x21552c str r0, [r4, #0xc] */
/* @0x215530 mov r0, #1 */
/* @0x215534 pop {r4, r5, r6, pc} */
/* @0x215538 andseq r8, sp, r8, lsl #9 */
/* @0x21553c andseq r8, sp, r12, ror #8 */

/* ── FUNC 0x215540 · CSound::Restore() · size=332 · insn=83 */
/* @0x215540 push {r4, r5, lr} */
/* @0x215544 mov r4, r0 */
/* @0x215548 ldr r3, [pc, #0x134] */
/* @0x21554c sub sp, sp, #12 */
/* @0x215550 ldr r5, [r0, #0x4] */
/* @0x215554 ldr r2, [r0, #0xc] */
/* @0x215558 ldr r3, [pc, r3] */
/* @0x21555c cmp r5, #0 */
/* @0x215560 str r2, [r3] */
/* @0x215564 bne 0x21559c <_ZN6CSound7RestoreEv+0x5c> */
/* @0x215568 ldr r3, [r4, #0x10] */
/* @0x21556c ldr r0, [r4, #0x38] */
/* @0x215570 cmp r3, #0 */
/* @0x215574 beq 0x215648 <_ZN6CSound7RestoreEv+0x108> */
/* @0x215578 cmp r0, #0 */
/* @0x21557c beq 0x215670 <_ZN6CSound7RestoreEv+0x130> */
/* @0x215580 mov r1, r5 */
/* @0x215584 bl 0x21e9f8 <_Z17SND_AddFromMemoryPvi> */
/* @0x215588 str r0, [r4, #0x30] */
/* @0x21558c cmn r0, #1 */
/* @0x215590 beq 0x215654 <_ZN6CSound7RestoreEv+0x114> */
/* @0x215594 ldr r5, [r4, #0x4] */
/* @0x215598 b 0x2155d0 <_ZN6CSound7RestoreEv+0x90> */
/* @0x21559c ldr r1, [pc, #0xe4] */
/* @0x2155a0 mov r2, #4 */
/* @0x2155a4 ldr r0, [r0, #0x8] */
/* @0x2155a8 add r1, pc, r1 */
/* @0x2155ac bl 0xb65e0 <strncmp@plt> */
/* @0x2155b0 cmp r0, #0 */
/* @0x2155b4 beq 0x215634 <_ZN6CSound7RestoreEv+0xf4> */
/* @0x2155b8 subs r3, r5, #3 */
/* @0x2155bc movne r3, #1 */
/* @0x2155c0 cmp r5, #0 */
/* @0x2155c4 movlt r3, #0 */
/* @0x2155c8 cmp r3, #0 */
/* @0x2155cc bne 0x215568 <_ZN6CSound7RestoreEv+0x28> */
/* @0x2155d0 cmp r5, #3 */
/* @0x2155d4 beq 0x21565c <_ZN6CSound7RestoreEv+0x11c> */
/* @0x2155d8 ldr r0, [r4, #0x30] */
/* @0x2155dc cmp r0, #0 */
/* @0x2155e0 blt 0x215600 <_ZN6CSound7RestoreEv+0xc0> */
/* @0x2155e4 ldr r1, [r4, #0x18] */
/* @0x2155e8 cmp r1, #0 */
/* @0x2155ec ble 0x215608 <_ZN6CSound7RestoreEv+0xc8> */
/* @0x2155f0 bl 0x21f120 <_Z14SND_Set_Effectii> */
/* @0x2155f4 ldr r0, [r4, #0x30] */
/* @0x2155f8 cmp r0, #0 */
/* @0x2155fc bge 0x215608 <_ZN6CSound7RestoreEv+0xc8> */
/* @0x215600 add sp, sp, #12 */
/* @0x215604 pop {r4, r5, pc} */
/* @0x215608 ldrd r2, r3, [r4, #32] */
/* @0x21560c mov r1, #0 */
/* @0x215610 str r1, [sp] */
/* @0x215614 bl 0x21f07c <_Z14SND_Set_Volumeidi> */
/* @0x215618 ldr r0, [r4, #0x30] */
/* @0x21561c cmp r0, #0 */
/* @0x215620 blt 0x215600 <_ZN6CSound7RestoreEv+0xc0> */
/* @0x215624 ldrd r2, r3, [r4, #40] */
/* @0x215628 add sp, sp, #12 */
/* @0x21562c pop {r4, r5, lr} */
/* @0x215630 b 0x21f11c <_Z15SND_Set_Panningid> */
/* @0x215634 mov r1, r5 */
/* @0x215638 bl 0x21e9f8 <_Z17SND_AddFromMemoryPvi> */
/* @0x21563c str r0, [r4, #0x30] */
/* @0x215640 add sp, sp, #12 */
/* @0x215644 pop {r4, r5, pc} */
/* @0x215648 cmp r0, #0 */
/* @0x21564c bne 0x215580 <_ZN6CSound7RestoreEv+0x40> */
/* @0x215650 b 0x215600 <_ZN6CSound7RestoreEv+0xc0> */
/* @0x215654 mov r3, #3 */
/* @0x215658 str r3, [r4, #0x4] */
/* @0x21565c mov r0, #0 */
/* @0x215660 mov r1, #3 */
/* @0x215664 bl 0x21e9f8 <_Z17SND_AddFromMemoryPvi> */
/* @0x215668 str r0, [r4, #0x30] */
/* @0x21566c b 0x2155dc <_ZN6CSound7RestoreEv+0x9c> */
/* @0x215670 mov r0, r3 */
/* @0x215674 mov r1, r5 */
/* @0x215678 bl 0x21ea60 <_Z17SND_AddFromMemoryP7CStreami> */
/* @0x21567c str r0, [r4, #0x30] */
/* @0x215680 b 0x21558c <_ZN6CSound7RestoreEv+0x4c> */
/* @0x215684 andseq r11, sp, r12, ror #28 */
/* @0x215688 ldrsheq lr, [r3], -r4 */

/* ── FUNC 0x21568c · CSound::Prepare() · size=16 · insn=4 */
/* @0x21568c ldrb r3, [r0, #0x14] */
/* @0x215690 cmp r3, #0 */
/* @0x215694 bxeq lr */
/* @0x215698 b 0x215540 <_ZN6CSound7RestoreEv> */

/* ── FUNC 0x21569c · CSound::LoadFromFile(char const*, int, bool) · size=136 · insn=34 */
/* @0x21569c push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x2156a0 mov r5, r1 */
/* @0x2156a4 mov r8, r2 */
/* @0x2156a8 mov r7, r3 */
/* @0x2156ac mov r4, r0 */
/* @0x2156b0 bl 0x21529c <_ZN6CSound5ClearEv> */
/* @0x2156b4 mov r0, r5 */
/* @0x2156b8 bl 0x214e48 <_Z10FileExistsPKc> */
/* @0x2156bc subs r6, r0, #0 */
/* @0x2156c0 beq 0x21571c <_ZN6CSound12LoadFromFileEPKcib+0x80> */
/* @0x2156c4 mov r0, r5 */
/* @0x2156c8 bl 0x215008 <_Z14ExtractFileExtPKc> */
/* @0x2156cc bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x2156d0 str r0, [r4, #0x8] */
/* @0x2156d4 mov r0, r5 */
/* @0x2156d8 bl 0x214fe0 <_Z15ExtractFileNamePKc> */
/* @0x2156dc bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x2156e0 str r0, [r4, #0xc] */
/* @0x2156e4 mov r0, #32 */
/* @0x2156e8 bl 0x27c524 <_Znwj> */
/* @0x2156ec mov r1, #0 */
/* @0x2156f0 mov r9, r0 */
/* @0x2156f4 bl 0x2010ec <_ZN7CStreamC2Ei> */
/* @0x2156f8 mov r0, r9 */
/* @0x2156fc str r9, [r4, #0x10] */
/* @0x215700 mov r1, r5 */
/* @0x215704 mov r2, #0 */
/* @0x215708 bl 0x201358 <_ZN7CStream12LoadFromFileEPKci> */
/* @0x21570c str r8, [r4, #0x4] */
/* @0x215710 strb r7, [r4, #0x14] */
/* @0x215714 mov r0, r4 */
/* @0x215718 bl 0x21568c <_ZN6CSound7PrepareEv> */
/* @0x21571c mov r0, r6 */
/* @0x215720 pop {r3, r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x215724 · CSound::Discard() · size=36 · insn=9 */
/* @0x215724 push {r4, lr} */
/* @0x215728 mov r4, r0 */
/* @0x21572c ldr r0, [r0, #0x30] */
/* @0x215730 cmp r0, #0 */
/* @0x215734 blt 0x21573c <_ZN6CSound7DiscardEv+0x18> */
/* @0x215738 bl 0x21eadc <_Z10SND_Deletei> */
/* @0x21573c mvn r3, #0 */
/* @0x215740 str r3, [r4, #0x30] */
/* @0x215744 pop {r4, pc} */

/* ── FUNC 0x215748 · CSound::GetSoundId() · size=44 · insn=11 */
/* @0x215748 ldr r3, [r0, #0x30] */
/* @0x21574c push {r4, lr} */
/* @0x215750 cmp r3, #0 */
/* @0x215754 mov r4, r0 */
/* @0x215758 blt 0x215764 <_ZN6CSound10GetSoundIdEv+0x1c> */
/* @0x21575c mov r0, r3 */
/* @0x215760 pop {r4, pc} */
/* @0x215764 bl 0x215540 <_ZN6CSound7RestoreEv> */
/* @0x215768 ldr r3, [r4, #0x30] */
/* @0x21576c mov r0, r3 */
/* @0x215770 pop {r4, pc} */

/* ── FUNC 0x215774 · CEmitter::Reset() · size=84 · insn=21 */
/* @0x215774 push {r4, lr} */
/* @0x215778 mov r1, #0 */
/* @0x21577c mov r2, #60 */
/* @0x215780 mov r4, r0 */
/* @0x215784 bl 0xb65b0 <memset@plt> */
/* @0x215788 ldr r3, [pc, #0x34] */
/* @0x21578c mov r2, #1065353216 */
/* @0x215790 mov r0, #0 */
/* @0x215794 ldr r3, [pc, r3] */
/* @0x215798 movt r0, #0x42c8 */
/* @0x21579c mov r1, #20480 */
/* @0x2157a0 str r0, [r4, #0x1c] */
/* @0x2157a4 ldr r3, [r3] */
/* @0x2157a8 movt r1, #0x47c3 */
/* @0x2157ac str r2, [r4, #0x24] */
/* @0x2157b0 str r1, [r4, #0x20] */
/* @0x2157b4 str r3, [r4, #0x30] */
/* @0x2157b8 str r2, [r4, #0x28] */
/* @0x2157bc str r2, [r4, #0x2c] */
/* @0x2157c0 pop {r4, pc} */
/* @0x2157c4 andseq r11, sp, r4, lsr r12 */

/* ── FUNC 0x2157c8 · CEmitter::CEmitter() · size=64 · insn=16 */
/* @0x2157c8 push {r4, lr} */
/* @0x2157cc mov r2, #0 */
/* @0x2157d0 mov r4, r0 */
/* @0x2157d4 str r2, [r0, #0x34] */
/* @0x2157d8 str r2, [r0, #0x38] */
/* @0x2157dc movw r3, #0x4f80 */
/* @0x2157e0 movt r3, #0xc7c3 */
/* @0x2157e4 str r3, [r0] */
/* @0x2157e8 str r3, [r0, #0x4] */
/* @0x2157ec str r3, [r0, #0x8] */
/* @0x2157f0 str r3, [r0, #0xc] */
/* @0x2157f4 str r3, [r0, #0x10] */
/* @0x2157f8 str r3, [r0, #0x14] */
/* @0x2157fc bl 0x215774 <_ZN8CEmitter5ResetEv> */
/* @0x215800 mov r0, r4 */
/* @0x215804 pop {r4, pc} */

/* ── FUNC 0x2157c8 · CEmitter::CEmitter() · alias of the symbol above · insn=0 */
