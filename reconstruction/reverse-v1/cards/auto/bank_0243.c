/* libyoyo.so 覆盖卡组 0243
 * 函数 0x293d40..0x29528c，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x293d40 · Java_com_yoyogames_runner_RunnerJNILib_CreateAsynEventWithDSMap · size=32 · insn=8 */
/* @0x293d40 push {r3, r4, r5, lr} */
/* @0x293d44 mov r4, r2 */
/* @0x293d48 mov r5, r3 */
/* @0x293d4c bl 0x290614 <setJNIEnv> */
/* @0x293d50 mov r0, r4 */
/* @0x293d54 mov r1, r5 */
/* @0x293d58 pop {r3, r4, r5, lr} */
/* @0x293d5c b 0x18da04 <_Z24CreateAsynEventWithDSMapii> */

/* ── FUNC 0x293d60 · Java_com_yoyogames_runner_RunnerJNILib_jCreateDsMap · size=700 · insn=175 */
/* @0x293d60 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x293d64 sub sp, sp, #52 */
/* @0x293d68 mov r11, r0 */
/* @0x293d6c str r3, [sp, #0x1c] */
/* @0x293d70 str r2, [sp, #0x8] */
/* @0x293d74 bl 0x290614 <setJNIEnv> */
/* @0x293d78 ldr r3, [sp, #0x8] */
/* @0x293d7c cmp r3, #0 */
/* @0x293d80 beq 0x294010 <Java_com_yoyogames_runner_RunnerJNILib_jCreateDsMap+0x2b0> */
/* @0x293d84 ldr r3, [sp, #0x58] */
/* @0x293d88 cmp r3, #0 */
/* @0x293d8c beq 0x293dac <Java_com_yoyogames_runner_RunnerJNILib_jCreateDsMap+0x4c> */
/* @0x293d90 ldr r3, [r11] */
/* @0x293d94 mov r0, r11 */
/* @0x293d98 ldr r1, [sp, #0x58] */
/* @0x293d9c add r2, sp, #47 */
/* @0x293da0 ldr r3, [r3, #0x2f8] */
/* @0x293da4 blx r3 */
/* @0x293da8 str r0, [sp, #0x24] */
/* @0x293dac ldr r3, [r11] */
/* @0x293db0 mov r0, r11 */
/* @0x293db4 ldr r1, [sp, #0x8] */
/* @0x293db8 ldr r3, [r3, #0x2ac] */
/* @0x293dbc blx r3 */
/* @0x293dc0 ldr r3, [sp, #0x1c] */
/* @0x293dc4 cmp r3, #0 */
/* @0x293dc8 str r0, [sp, #0xc] */
/* @0x293dcc beq 0x293fd0 <Java_com_yoyogames_runner_RunnerJNILib_jCreateDsMap+0x270> */
/* @0x293dd0 ldr r3, [r11] */
/* @0x293dd4 mov r0, r11 */
/* @0x293dd8 ldr r1, [sp, #0x1c] */
/* @0x293ddc ldr r3, [r3, #0x2ac] */
/* @0x293de0 blx r3 */
/* @0x293de4 ldr r3, [sp, #0x58] */
/* @0x293de8 cmp r3, #0 */
/* @0x293dec str r0, [sp, #0x14] */
/* @0x293df0 beq 0x293fe4 <Java_com_yoyogames_runner_RunnerJNILib_jCreateDsMap+0x284> */
/* @0x293df4 ldr r3, [r11] */
/* @0x293df8 mov r0, r11 */
/* @0x293dfc ldr r1, [sp, #0x58] */
/* @0x293e00 ldr r3, [r3, #0x2ac] */
/* @0x293e04 blx r3 */
/* @0x293e08 str r0, [sp, #0x20] */
/* @0x293e0c mov r0, #0 */
/* @0x293e10 bl 0x20bdc0 <_Z11CreateDsMapiz> */
/* @0x293e14 ldr r3, [sp, #0xc] */
/* @0x293e18 cmp r3, #0 */
/* @0x293e1c str r0, [sp, #0x10] */
/* @0x293e20 ble 0x293fb8 <Java_com_yoyogames_runner_RunnerJNILib_jCreateDsMap+0x258> */
/* @0x293e24 ldr r3, [sp, #0x1c] */
/* @0x293e28 mov r4, #0 */
/* @0x293e2c ldr r8, [sp, #0x24] */
/* @0x293e30 adds r3, r3, #0 */
/* @0x293e34 movne r3, #1 */
/* @0x293e38 str r3, [sp, #0x18] */
/* @0x293e3c b 0x293ed4 <Java_com_yoyogames_runner_RunnerJNILib_jCreateDsMap+0x174> */
/* @0x293e40 ldr r3, [r11] */
/* @0x293e44 mov r0, r11 */
/* @0x293e48 mov r1, r7 */
/* @0x293e4c mov r2, #0 */
/* @0x293e50 ldr r3, [r3, #0x2a4] */
/* @0x293e54 blx r3 */
/* @0x293e58 adds r9, r0, #0 */
/* @0x293e5c mov r6, r0 */
/* @0x293e60 movne r9, #1 */
/* @0x293e64 ldr r5, [sp, #0x18] */
/* @0x293e68 ldr r3, [sp, #0x14] */
/* @0x293e6c cmp r4, r3 */
/* @0x293e70 movge r5, #0 */
/* @0x293e74 andlt r5, r5, #1 */
/* @0x293e78 cmp r5, #0 */
/* @0x293e7c bne 0x293f60 <Java_com_yoyogames_runner_RunnerJNILib_jCreateDsMap+0x200> */
/* @0x293e80 mov r3, #0 */
/* @0x293e84 str r3, [sp, #0x4] */
/* @0x293e88 ldr r3, [sp, #0x20] */
/* @0x293e8c mov r1, r6 */
/* @0x293e90 ldr r0, [sp, #0x10] */
/* @0x293e94 mov r5, #0 */
/* @0x293e98 cmp r3, r4 */
/* @0x293e9c mov r10, r5 */
/* @0x293ea0 ldrdgt r2, r3, [r8] */
/* @0x293ea4 movle r2, #0 */
/* @0x293ea8 movle r3, #0 */
/* @0x293eac bl 0x104d94 <_Z19F_DsMapAdd_InternaliPcd> */
/* @0x293eb0 cmp r9, #0 */
/* @0x293eb4 bne 0x293f30 <Java_com_yoyogames_runner_RunnerJNILib_jCreateDsMap+0x1d0> */
/* @0x293eb8 cmp r5, #0 */
/* @0x293ebc bne 0x293f00 <Java_com_yoyogames_runner_RunnerJNILib_jCreateDsMap+0x1a0> */
/* @0x293ec0 ldr r3, [sp, #0xc] */
/* @0x293ec4 add r4, r4, #1 */
/* @0x293ec8 add r8, r8, #8 */
/* @0x293ecc cmp r4, r3 */
/* @0x293ed0 beq 0x293fb8 <Java_com_yoyogames_runner_RunnerJNILib_jCreateDsMap+0x258> */
/* @0x293ed4 ldr r3, [r11] */
/* @0x293ed8 mov r0, r11 */
/* @0x293edc ldr r1, [sp, #0x8] */
/* @0x293ee0 mov r2, r4 */
/* @0x293ee4 ldr r3, [r3, #0x2b4] */
/* @0x293ee8 blx r3 */
/* @0x293eec subs r7, r0, #0 */
/* @0x293ef0 bne 0x293e40 <Java_com_yoyogames_runner_RunnerJNILib_jCreateDsMap+0xe0> */
/* @0x293ef4 mov r9, r7 */
/* @0x293ef8 mov r6, r7 */
/* @0x293efc b 0x293e64 <Java_com_yoyogames_runner_RunnerJNILib_jCreateDsMap+0x104> */
/* @0x293f00 ldr lr, [r11] */
/* @0x293f04 mov r0, r11 */
/* @0x293f08 ldr r1, [sp, #0x4] */
/* @0x293f0c mov r2, r10 */
/* @0x293f10 ldr r3, [lr, #0x2a8] */
/* @0x293f14 blx r3 */
/* @0x293f18 ldr r3, [r11] */
/* @0x293f1c ldr r1, [sp, #0x4] */
/* @0x293f20 mov r0, r11 */
/* @0x293f24 ldr r3, [r3, #0x5c] */
/* @0x293f28 blx r3 */
/* @0x293f2c b 0x293ec0 <Java_com_yoyogames_runner_RunnerJNILib_jCreateDsMap+0x160> */
/* @0x293f30 ldr lr, [r11] */
/* @0x293f34 mov r2, r6 */
/* @0x293f38 mov r0, r11 */
/* @0x293f3c mov r1, r7 */
/* @0x293f40 ldr r6, [lr, #0x2a8] */
/* @0x293f44 blx r6 */
/* @0x293f48 ldr r2, [r11] */
/* @0x293f4c mov r1, r7 */
/* @0x293f50 mov r0, r11 */
/* @0x293f54 ldr r2, [r2, #0x5c] */
/* @0x293f58 blx r2 */
/* @0x293f5c b 0x293eb8 <Java_com_yoyogames_runner_RunnerJNILib_jCreateDsMap+0x158> */
/* @0x293f60 ldr r3, [r11] */
/* @0x293f64 mov r0, r11 */
/* @0x293f68 ldr r1, [sp, #0x1c] */
/* @0x293f6c mov r2, r4 */
/* @0x293f70 ldr r3, [r3, #0x2b4] */
/* @0x293f74 blx r3 */
/* @0x293f78 cmp r0, #0 */
/* @0x293f7c str r0, [sp, #0x4] */
/* @0x293f80 beq 0x293e80 <Java_com_yoyogames_runner_RunnerJNILib_jCreateDsMap+0x120> */
/* @0x293f84 ldr r3, [r11] */
/* @0x293f88 mov r0, r11 */
/* @0x293f8c ldr r1, [sp, #0x4] */
/* @0x293f90 mov r2, #0 */
/* @0x293f94 ldr r3, [r3, #0x2a4] */
/* @0x293f98 blx r3 */
/* @0x293f9c subs r10, r0, #0 */
/* @0x293fa0 beq 0x293e88 <Java_com_yoyogames_runner_RunnerJNILib_jCreateDsMap+0x128> */
/* @0x293fa4 ldr r0, [sp, #0x10] */
/* @0x293fa8 mov r1, r6 */
/* @0x293fac mov r2, r10 */
/* @0x293fb0 bl 0x104f64 <_Z19F_DsMapAdd_InternaliPcS_> */
/* @0x293fb4 b 0x293eb0 <Java_com_yoyogames_runner_RunnerJNILib_jCreateDsMap+0x150> */
/* @0x293fb8 ldrb r3, [sp, #0x2f] */
/* @0x293fbc cmp r3, #1 */
/* @0x293fc0 beq 0x293ff0 <Java_com_yoyogames_runner_RunnerJNILib_jCreateDsMap+0x290> */
/* @0x293fc4 ldr r0, [sp, #0x10] */
/* @0x293fc8 add sp, sp, #52 */
/* @0x293fcc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x293fd0 ldr r3, [sp, #0x1c] */
/* @0x293fd4 str r3, [sp, #0x14] */
/* @0x293fd8 ldr r3, [sp, #0x58] */
/* @0x293fdc cmp r3, #0 */
/* @0x293fe0 bne 0x293df4 <Java_com_yoyogames_runner_RunnerJNILib_jCreateDsMap+0x94> */
/* @0x293fe4 ldr r3, [sp, #0x58] */
/* @0x293fe8 str r3, [sp, #0x20] */
/* @0x293fec b 0x293e0c <Java_com_yoyogames_runner_RunnerJNILib_jCreateDsMap+0xac> */
/* @0x293ff0 ldr lr, [r11] */
/* @0x293ff4 mov r0, r11 */
/* @0x293ff8 ldr r1, [sp, #0x58] */
/* @0x293ffc mov r3, #2 */
/* @0x294000 ldr r2, [sp, #0x24] */
/* @0x294004 ldr r12, [lr, #0x318] */
/* @0x294008 blx r12 */
/* @0x29400c b 0x293fc4 <Java_com_yoyogames_runner_RunnerJNILib_jCreateDsMap+0x264> */
/* @0x294010 mov r0, r3 */
/* @0x294014 bl 0x20bdc0 <_Z11CreateDsMapiz> */
/* @0x294018 b 0x293fc8 <Java_com_yoyogames_runner_RunnerJNILib_jCreateDsMap+0x268> */

/* ── FUNC 0x29401c · Java_com_yoyogames_runner_RunnerJNILib_LoadPicForUserWithUrl · size=392 · insn=98 */
/* @0x29401c push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x294020 mov r4, r0 */
/* @0x294024 sub sp, sp, #16 */
/* @0x294028 mov r9, r2 */
/* @0x29402c mov r8, r3 */
/* @0x294030 bl 0x290614 <setJNIEnv> */
/* @0x294034 ldr r3, [r4] */
/* @0x294038 mov r1, r9 */
/* @0x29403c mov r2, #0 */
/* @0x294040 mov r0, r4 */
/* @0x294044 ldr r3, [r3, #0x2a4] */
/* @0x294048 blx r3 */
/* @0x29404c ldr r3, [r4] */
/* @0x294050 mov r1, r8 */
/* @0x294054 mov r2, #0 */
/* @0x294058 ldr r3, [r3, #0x2a4] */
/* @0x29405c mov r7, r0 */
/* @0x294060 mov r0, r4 */
/* @0x294064 blx r3 */
/* @0x294068 ldr r1, [pc, #0x120] */
/* @0x29406c mov r2, r7 */
/* @0x294070 add r1, pc, r1 */
/* @0x294074 mov r6, r0 */
/* @0x294078 ldr r0, [pc, #0x114] */
/* @0x29407c mov r3, r6 */
/* @0x294080 ldr r0, [pc, r0] */
/* @0x294084 ldr r5, [r0] */
/* @0x294088 ldr r12, [r5] */
/* @0x29408c mov r0, r5 */
/* @0x294090 ldr r12, [r12, #0xc] */
/* @0x294094 blx r12 */
/* @0x294098 mov r12, #0 */
/* @0x29409c mov r1, r12 */
/* @0x2940a0 mov r2, r12 */
/* @0x2940a4 mov r3, r12 */
/* @0x2940a8 str r12, [sp] */
/* @0x2940ac str r12, [sp, #0x4] */
/* @0x2940b0 mov r0, r6 */
/* @0x2940b4 str r12, [sp, #0x8] */
/* @0x2940b8 str r12, [sp, #0xc] */
/* @0x2940bc bl 0x1f114c <_Z10Sprite_AddPKcibbbbii> */
/* @0x2940c0 ldr r3, [r5] */
/* @0x2940c4 ldr r1, [pc, #0xcc] */
/* @0x2940c8 ldr r3, [r3, #0xc] */
/* @0x2940cc add r1, pc, r1 */
/* @0x2940d0 mov r10, r0 */
/* @0x2940d4 mov r0, r5 */
/* @0x2940d8 mov r2, r10 */
/* @0x2940dc blx r3 */
/* @0x2940e0 ldr r1, [pc, #0xb4] */
/* @0x2940e4 movw r2, #0x9fe */
/* @0x2940e8 mov r3, #1 */
/* @0x2940ec add r1, pc, r1 */
/* @0x2940f0 mov r0, #8 */
/* @0x2940f4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x2940f8 mov r5, r0 */
/* @0x2940fc mov r0, r7 */
/* @0x294100 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x294104 cmp r7, #0 */
/* @0x294108 cmpne r9, #0 */
/* @0x29410c stm r5, {r0, r10} */
/* @0x294110 bne 0x294174 <Java_com_yoyogames_runner_RunnerJNILib_LoadPicForUserWithUrl+0x158> */
/* @0x294114 cmp r6, #0 */
/* @0x294118 cmpne r8, #0 */
/* @0x29411c beq 0x294138 <Java_com_yoyogames_runner_RunnerJNILib_LoadPicForUserWithUrl+0x11c> */
/* @0x294120 ldr r3, [r4] */
/* @0x294124 mov r1, r8 */
/* @0x294128 mov r2, r6 */
/* @0x29412c mov r0, r4 */
/* @0x294130 ldr r3, [r3, #0x2a8] */
/* @0x294134 blx r3 */
/* @0x294138 mov r0, #68 */
/* @0x29413c bl 0x27c524 <_Znwj> */
/* @0x294140 ldr r3, [pc, #0x58] */
/* @0x294144 mov r2, #0 */
/* @0x294148 str r5, [sp, #0x4] */
/* @0x29414c mov r1, r2 */
/* @0x294150 ldr r3, [pc, r3] */
/* @0x294154 str r2, [sp] */
/* @0x294158 str r2, [sp, #0x8] */
/* @0x29415c mov r4, r0 */
/* @0x294160 bl 0x18d834 <_ZN16HTTP_REQ_CONTEXTC2EPKciPFiPS_PvPiEPFvS2_ES3_b> */
/* @0x294164 mov r3, #7 */
/* @0x294168 str r3, [r4, #0xc] */
/* @0x29416c add sp, sp, #16 */
/* @0x294170 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x294174 ldr r3, [r4] */
/* @0x294178 mov r1, r9 */
/* @0x29417c mov r2, r7 */
/* @0x294180 mov r0, r4 */
/* @0x294184 ldr r3, [r3, #0x2a8] */
/* @0x294188 blx r3 */
/* @0x29418c b 0x294114 <Java_com_yoyogames_runner_RunnerJNILib_LoadPicForUserWithUrl+0xf8> */
/* @0x294190 strheq r5, [r12], -r8 */
/* @0x294194 andseq r9, r5, r0, asr #17 */
/* @0x294198 muleq r12, r0, r0 */
/* @0x29419c andeq r4, r12, r8, asr #32 */
/* @0x2941a0 andseq sp, r5, r8, lsr r8 */

/* ── FUNC 0x2941a4 · Java_com_yoyogames_runner_RunnerJNILib_CloudResultData · size=316 · insn=79 */
/* @0x2941a4 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2941a8 mov r6, r2 */
/* @0x2941ac mov r9, r3 */
/* @0x2941b0 mov r7, r0 */
/* @0x2941b4 ldr r5, [sp, #0x20] */
/* @0x2941b8 bl 0x290614 <setJNIEnv> */
/* @0x2941bc cmp r6, #0 */
/* @0x2941c0 beq 0x29429c <Java_com_yoyogames_runner_RunnerJNILib_CloudResultData+0xf8> */
/* @0x2941c4 ldr r3, [r7] */
/* @0x2941c8 mov r1, r6 */
/* @0x2941cc mov r0, r7 */
/* @0x2941d0 ldr r3, [r3, #0x2ac] */
/* @0x2941d4 blx r3 */
/* @0x2941d8 ldr r3, [r7] */
/* @0x2941dc mov r1, r6 */
/* @0x2941e0 mov r2, #0 */
/* @0x2941e4 ldr r3, [r3, #0x2e0] */
/* @0x2941e8 mov r8, r0 */
/* @0x2941ec mov r0, r7 */
/* @0x2941f0 blx r3 */
/* @0x2941f4 mov r10, r0 */
/* @0x2941f8 ldr r12, [pc, #0xd8] */
/* @0x2941fc ldr r12, [pc, r12] */
/* @0x294200 ldr r4, [r12] */
/* @0x294204 cmp r4, #0 */
/* @0x294208 beq 0x294234 <Java_com_yoyogames_runner_RunnerJNILib_CloudResultData+0x90> */
/* @0x29420c ldr r3, [r4, #0x24] */
/* @0x294210 cmp r3, r5 */
/* @0x294214 bne 0x294228 <Java_com_yoyogames_runner_RunnerJNILib_CloudResultData+0x84> */
/* @0x294218 b 0x29425c <Java_com_yoyogames_runner_RunnerJNILib_CloudResultData+0xb8> */
/* @0x29421c ldr r12, [r4, #0x24] */
/* @0x294220 cmp r12, r5 */
/* @0x294224 beq 0x29425c <Java_com_yoyogames_runner_RunnerJNILib_CloudResultData+0xb8> */
/* @0x294228 ldr r4, [r4, #0x4] */
/* @0x29422c cmp r4, #0 */
/* @0x294230 bne 0x29421c <Java_com_yoyogames_runner_RunnerJNILib_CloudResultData+0x78> */
/* @0x294234 cmp r6, #0 */
/* @0x294238 popeq {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x29423c ldr r12, [r7] */
/* @0x294240 mov r1, r6 */
/* @0x294244 mov r2, r10 */
/* @0x294248 mov r0, r7 */
/* @0x29424c mov r3, #0 */
/* @0x294250 ldr r12, [r12, #0x300] */
/* @0x294254 blx r12 */
/* @0x294258 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x29425c ldr r3, [r4, #0x38] */
/* @0x294260 cmp r8, r3 */
/* @0x294264 bgt 0x2942a8 <Java_com_yoyogames_runner_RunnerJNILib_CloudResultData+0x104> */
/* @0x294268 cmp r8, #0 */
/* @0x29426c mov r3, #7 */
/* @0x294270 str r9, [r4, #0x28] */
/* @0x294274 str r3, [r4, #0xc] */
/* @0x294278 ble 0x29428c <Java_com_yoyogames_runner_RunnerJNILib_CloudResultData+0xe8> */
/* @0x29427c ldr r0, [r4, #0x34] */
/* @0x294280 mov r1, r10 */
/* @0x294284 mov r2, r8 */
/* @0x294288 bl 0xb65bc <memcpy@plt> */
/* @0x29428c cmp r6, #0 */
/* @0x294290 str r8, [r4, #0x3c] */
/* @0x294294 bne 0x29423c <Java_com_yoyogames_runner_RunnerJNILib_CloudResultData+0x98> */
/* @0x294298 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x29429c mov r10, r6 */
/* @0x2942a0 mov r8, r6 */
/* @0x2942a4 b 0x2941f8 <Java_com_yoyogames_runner_RunnerJNILib_CloudResultData+0x54> */
/* @0x2942a8 ldr r0, [r4, #0x34] */
/* @0x2942ac add r5, r8, #1 */
/* @0x2942b0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2942b4 ldr r1, [pc, #0x20] */
/* @0x2942b8 mov r0, r5 */
/* @0x2942bc mov r2, #70 */
/* @0x2942c0 add r1, pc, r1 */
/* @0x2942c4 mov r3, #1 */
/* @0x2942c8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x2942cc str r5, [r4, #0x38] */
/* @0x2942d0 str r0, [r4, #0x34] */
/* @0x2942d4 b 0x294268 <Java_com_yoyogames_runner_RunnerJNILib_CloudResultData+0xc4> */
/* @0x2942d8 ldrsheq r9, [r5], -r12 */
/* @0x2942dc andeq r12, r9, r0, ror sp */

/* ── FUNC 0x2942e0 · Java_com_yoyogames_runner_RunnerJNILib_CloudResultString · size=268 · insn=67 */
/* @0x2942e0 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x2942e4 mov r6, r0 */
/* @0x2942e8 mov r7, r2 */
/* @0x2942ec mov r9, r3 */
/* @0x2942f0 ldr r5, [sp, #0x20] */
/* @0x2942f4 bl 0x290614 <setJNIEnv> */
/* @0x2942f8 ldr r3, [r6] */
/* @0x2942fc mov r1, r7 */
/* @0x294300 mov r2, #0 */
/* @0x294304 mov r0, r6 */
/* @0x294308 ldr r3, [r3, #0x2a4] */
/* @0x29430c blx r3 */
/* @0x294310 mov r8, r0 */
/* @0x294314 bl 0xb6538 <strlen@plt> */
/* @0x294318 ldr r12, [pc, #0xc4] */
/* @0x29431c ldr r12, [pc, r12] */
/* @0x294320 ldr r4, [r12] */
/* @0x294324 cmp r4, #0 */
/* @0x294328 beq 0x294354 <Java_com_yoyogames_runner_RunnerJNILib_CloudResultString+0x74> */
/* @0x29432c ldr r3, [r4, #0x24] */
/* @0x294330 cmp r3, r5 */
/* @0x294334 bne 0x294348 <Java_com_yoyogames_runner_RunnerJNILib_CloudResultString+0x68> */
/* @0x294338 b 0x29437c <Java_com_yoyogames_runner_RunnerJNILib_CloudResultString+0x9c> */
/* @0x29433c ldr r12, [r4, #0x24] */
/* @0x294340 cmp r12, r5 */
/* @0x294344 beq 0x29437c <Java_com_yoyogames_runner_RunnerJNILib_CloudResultString+0x9c> */
/* @0x294348 ldr r4, [r4, #0x4] */
/* @0x29434c cmp r4, #0 */
/* @0x294350 bne 0x29433c <Java_com_yoyogames_runner_RunnerJNILib_CloudResultString+0x5c> */
/* @0x294354 cmp r8, #0 */
/* @0x294358 cmpne r7, #0 */
/* @0x29435c popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x294360 ldr r3, [r6] */
/* @0x294364 mov r1, r7 */
/* @0x294368 mov r2, r8 */
/* @0x29436c mov r0, r6 */
/* @0x294370 ldr r3, [r3, #0x2a8] */
/* @0x294374 blx r3 */
/* @0x294378 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x29437c ldr r3, [r4, #0x38] */
/* @0x294380 cmp r0, r3 */
/* @0x294384 bgt 0x2943b4 <Java_com_yoyogames_runner_RunnerJNILib_CloudResultString+0xd4> */
/* @0x294388 ldr r0, [r4, #0x34] */
/* @0x29438c mov r3, #7 */
/* @0x294390 mov r1, r8 */
/* @0x294394 str r3, [r4, #0xc] */
/* @0x294398 str r9, [r4, #0x28] */
/* @0x29439c bl 0xb65a4 <strcpy@plt> */
/* @0x2943a0 ldr r0, [r4, #0x34] */
/* @0x2943a4 bl 0xb6538 <strlen@plt> */
/* @0x2943a8 add r0, r0, #1 */
/* @0x2943ac str r0, [r4, #0x3c] */
/* @0x2943b0 b 0x294354 <Java_com_yoyogames_runner_RunnerJNILib_CloudResultString+0x74> */
/* @0x2943b4 add r5, r0, #1 */
/* @0x2943b8 ldr r0, [r4, #0x34] */
/* @0x2943bc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2943c0 ldr r1, [pc, #0x20] */
/* @0x2943c4 mov r0, r5 */
/* @0x2943c8 mov r2, #70 */
/* @0x2943cc add r1, pc, r1 */
/* @0x2943d0 mov r3, #1 */
/* @0x2943d4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x2943d8 str r5, [r4, #0x38] */
/* @0x2943dc str r0, [r4, #0x34] */
/* @0x2943e0 b 0x29438c <Java_com_yoyogames_runner_RunnerJNILib_CloudResultString+0xac> */
/* @0x2943e4 ldrsbeq r9, [r5], -r12 */
/* @0x2943e8 andeq r12, r9, r4, ror #24 */

/* ── FUNC 0x2943ec · Java_com_yoyogames_runner_RunnerJNILib_callreward · size=300 · insn=75 */
/* @0x2943ec push {r4, r5, r6, r7, r8, r9, r11, lr} */
/* @0x2943f0 add r11, sp, #28 */
/* @0x2943f4 ldr r4, [pc, #0x110] */
/* @0x2943f8 sub sp, sp, #48 */
/* @0x2943fc mov r8, r2 */
/* @0x294400 ldr r4, [pc, r4] */
/* @0x294404 ldr r6, [r11, #0x4] */
/* @0x294408 mov r9, r0 */
/* @0x29440c mov r7, #0 */
/* @0x294410 ldr r2, [r4] */
/* @0x294414 str r3, [r11, #-0x40] */
/* @0x294418 str r2, [r11, #-0x20] */
/* @0x29441c bl 0x290614 <setJNIEnv> */
/* @0x294420 ldr r3, [r11, #-0x40] */
/* @0x294424 sub sp, sp, #40 */
/* @0x294428 mov r2, #2 */
/* @0x29442c str r2, [r11, #-0x38] */
/* @0x294430 str r7, [sp, #0x14] */
/* @0x294434 vmov s13, r3 */
/* @0x294438 add r3, sp, #8 */
/* @0x29443c str r3, [r11, #-0x34] */
/* @0x294440 vcvt.f64.s32 d7, s13 */
/* @0x294444 mov r5, r3 */
/* @0x294448 vmov r2, r3, d7 */
/* @0x29444c strd r2, r3, [r5], #16 */
/* @0x294450 bl 0x290274 <getJNIEnv> */
/* @0x294454 mov r2, r7 */
/* @0x294458 mov r1, r6 */
/* @0x29445c ldr r3, [r0] */
/* @0x294460 ldr r3, [r3, #0x2a4] */
/* @0x294464 blx r3 */
/* @0x294468 mov r7, r0 */
/* @0x29446c mov r0, r5 */
/* @0x294470 mov r1, r7 */
/* @0x294474 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x294478 cmp r7, #0 */
/* @0x29447c cmpne r6, #0 */
/* @0x294480 bne 0x2944ec <Java_com_yoyogames_runner_RunnerJNILib_callreward+0x100> */
/* @0x294484 mov r1, #0 */
/* @0x294488 sub r3, r11, #48 */
/* @0x29448c mov r0, r8 */
/* @0x294490 str r3, [sp] */
/* @0x294494 mov r2, r1 */
/* @0x294498 sub r3, r11, #56 */
/* @0x29449c str r3, [sp, #0x4] */
/* @0x2944a0 mov r3, #2 */
/* @0x2944a4 bl 0x1e0774 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue> */
/* @0x2944a8 ldr r3, [pc, #0x60] */
/* @0x2944ac ldr r3, [pc, r3] */
/* @0x2944b0 ldrb r3, [r3] */
/* @0x2944b4 cmp r3, #0 */
/* @0x2944b8 beq 0x2944d4 <Java_com_yoyogames_runner_RunnerJNILib_callreward+0xe8> */
/* @0x2944bc ldr r3, [pc, #0x50] */
/* @0x2944c0 mov r1, #0 */
/* @0x2944c4 ldr r3, [pc, r3] */
/* @0x2944c8 ldr r3, [r3] */
/* @0x2944cc ldr r0, [r3] */
/* @0x2944d0 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x2944d4 ldr r2, [r11, #-0x20] */
/* @0x2944d8 ldr r3, [r4] */
/* @0x2944dc cmp r2, r3 */
/* @0x2944e0 bne 0x294508 <Java_com_yoyogames_runner_RunnerJNILib_callreward+0x11c> */
/* @0x2944e4 sub sp, r11, #28 */
/* @0x2944e8 pop {r4, r5, r6, r7, r8, r9, r11, pc} */
/* @0x2944ec ldr r3, [r9] */
/* @0x2944f0 mov r1, r6 */
/* @0x2944f4 mov r2, r7 */
/* @0x2944f8 mov r0, r9 */
/* @0x2944fc ldr r3, [r3, #0x2a8] */
/* @0x294500 blx r3 */
/* @0x294504 b 0x294484 <Java_com_yoyogames_runner_RunnerJNILib_callreward+0x98> */
/* @0x294508 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x29450c andseq r9, r5, r0, asr r5 */
/* @0x294510 ldrheq r9, [r5], -r8 */
/* @0x294514 andseq r9, r5, r12, lsr #13 */

/* ── FUNC 0x294518 · Java_com_yoyogames_runner_RunnerJNILib_Process · size=1244 · insn=311 */
/* @0x294518 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x29451c vpush {d8, d9} */
/* @0x294520 mov r9, r2 */
/* @0x294524 ldr r4, [pc, #0x448] */
/* @0x294528 sub sp, sp, #20 */
/* @0x29452c ldr r2, [pc, #0x444] */
/* @0x294530 vldr s18, [sp, #72] */
/* @0x294534 add r4, pc, r4 */
/* @0x294538 str r3, [sp, #0x4] */
/* @0x29453c ldr r1, [sp, #0x5c] */
/* @0x294540 vldr s17, [sp, #76] */
/* @0x294544 ldr r3, [r4, r2] */
/* @0x294548 vldr s16, [sp, #80] */
/* @0x29454c str r1, [r3] */
/* @0x294550 bl 0x290614 <setJNIEnv> */
/* @0x294554 ldr r3, [pc, #0x420] */
/* @0x294558 ldr r3, [r4, r3] */
/* @0x29455c str r3, [sp, #0x8] */
/* @0x294560 ldrb r3, [r3] */
/* @0x294564 cmp r3, #0 */
/* @0x294568 beq 0x294644 <Java_com_yoyogames_runner_RunnerJNILib_Process+0x12c> */
/* @0x29456c ldr r3, [pc, #0x40c] */
/* @0x294570 ldr r3, [r4, r3] */
/* @0x294574 str r3, [sp, #0xc] */
/* @0x294578 ldr r3, [r3] */
/* @0x29457c cmp r3, #0 */
/* @0x294580 beq 0x2947ec <Java_com_yoyogames_runner_RunnerJNILib_Process+0x2d4> */
/* @0x294584 cmp r3, #1 */
/* @0x294588 beq 0x2948f4 <Java_com_yoyogames_runner_RunnerJNILib_Process+0x3dc> */
/* @0x29458c ldr r3, [pc, #0x3f0] */
/* @0x294590 mov r1, #1065353216 */
/* @0x294594 mov r0, #0 */
/* @0x294598 ldr r3, [r4, r3] */
/* @0x29459c ldr r3, [r3] */
/* @0x2945a0 blx r3 */
/* @0x2945a4 ldr r3, [pc, #0x3dc] */
/* @0x2945a8 movw r0, #0xbe2 */
/* @0x2945ac ldr r5, [r4, r3] */
/* @0x2945b0 ldr r3, [r5] */
/* @0x2945b4 blx r3 */
/* @0x2945b8 ldr r3, [r5] */
/* @0x2945bc movw r0, #0xb44 */
/* @0x2945c0 blx r3 */
/* @0x2945c4 ldr r3, [r5] */
/* @0x2945c8 mov r0, #2960 */
/* @0x2945cc blx r3 */
/* @0x2945d0 ldr r3, [r5] */
/* @0x2945d4 movw r0, #0x1702 */
/* @0x2945d8 blx r3 */
/* @0x2945dc ldr r3, [r5] */
/* @0x2945e0 mov r0, #3024 */
/* @0x2945e4 blx r3 */
/* @0x2945e8 ldr r12, [sp, #0xc] */
/* @0x2945ec ldr r3, [r12] */
/* @0x2945f0 cmp r3, #0 */
/* @0x2945f4 beq 0x2948c4 <Java_com_yoyogames_runner_RunnerJNILib_Process+0x3ac> */
/* @0x2945f8 ldr r3, [pc, #0x38c] */
/* @0x2945fc movw r0, #0x203 */
/* @0x294600 ldr r3, [r4, r3] */
/* @0x294604 ldr r3, [r3] */
/* @0x294608 blx r3 */
/* @0x29460c bl 0x168a50 <_Z20GR_D3D_Settings_Initv> */
/* @0x294610 bl 0x17fb70 <_Z20GR_D3D_Lights_Resumev> */
/* @0x294614 ldr r2, [sp, #0xc] */
/* @0x294618 ldr r3, [r2] */
/* @0x29461c cmp r3, #1 */
/* @0x294620 beq 0x2948ec <Java_com_yoyogames_runner_RunnerJNILib_Process+0x3d4> */
/* @0x294624 ldr r3, [pc, #0x364] */
/* @0x294628 mov r2, #0 */
/* @0x29462c ldr r12, [sp, #0x8] */
/* @0x294630 ldr r3, [r4, r3] */
/* @0x294634 strb r2, [r12] */
/* @0x294638 ldr r2, [r3] */
/* @0x29463c add r2, r2, #1 */
/* @0x294640 str r2, [r3] */
/* @0x294644 bl 0x290274 <getJNIEnv> */
/* @0x294648 ldr r2, [pc, #0x344] */
/* @0x29464c ldr r3, [pc, #0x344] */
/* @0x294650 ldr r10, [pc, #0x344] */
/* @0x294654 ldr r2, [r4, r2] */
/* @0x294658 ldr r3, [r4, r3] */
/* @0x29465c ldr r7, [pc, #0x33c] */
/* @0x294660 ldr r1, [r2] */
/* @0x294664 ldr r2, [r3] */
/* @0x294668 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz> */
/* @0x29466c ldr r3, [pc, #0x330] */
/* @0x294670 ldr r6, [pc, #0x330] */
/* @0x294674 mov r2, #2560 */
/* @0x294678 ldr r11, [pc, #0x32c] */
/* @0x29467c ldr r5, [r4, r3] */
/* @0x294680 ldr r12, [sp, #0x54] */
/* @0x294684 ldr r3, [pc, #0x324] */
/* @0x294688 and lr, r12, #1 */
/* @0x29468c ldr r12, [pc, #0x320] */
/* @0x294690 ldr r1, [pc, #0x320] */
/* @0x294694 subs r8, r0, #1 */
/* @0x294698 rsbs r0, r8, #0 */
/* @0x29469c adcs r0, r0, r8 */
/* @0x2946a0 strb r0, [r5] */
/* @0x2946a4 ldr r0, [r4, r10] */
/* @0x2946a8 vstr s18, [r0] */
/* @0x2946ac ldr r0, [r4, r11] */
/* @0x2946b0 vstr s17, [r0] */
/* @0x2946b4 ldr r0, [r4, r7] */
/* @0x2946b8 vstr s16, [r0] */
/* @0x2946bc ldr r0, [r4, r6] */
/* @0x2946c0 strb lr, [r0] */
/* @0x2946c4 ldr r0, [r4, r12] */
/* @0x2946c8 ldr r12, [sp, #0x58] */
/* @0x2946cc str r12, [r0] */
/* @0x2946d0 ldr r0, [r4, r1] */
/* @0x2946d4 ldr r1, [r4, r3] */
/* @0x2946d8 bl 0xb65bc <memcpy@plt> */
/* @0x2946dc bl 0x215148 <Timing_Time> */
/* @0x2946e0 ldr lr, [pc, #0x2d4] */
/* @0x2946e4 ldr r12, [pc, #0x2d4] */
/* @0x2946e8 mov r2, r9 */
/* @0x2946ec add lr, pc, lr */
/* @0x2946f0 ldr r3, [sp, #0x4] */
/* @0x2946f4 mov r6, r0 */
/* @0x2946f8 mov r7, r1 */
/* @0x2946fc strd r6, r7, [lr, #16] */
/* @0x294700 mov r0, #0 */
/* @0x294704 ldr r12, [r4, r12] */
/* @0x294708 mov r1, r0 */
/* @0x29470c ldr r12, [r12] */
/* @0x294710 blx r12 */
/* @0x294714 ldr r12, [pc, #0x2a8] */
/* @0x294718 mov r0, #0 */
/* @0x29471c mov r2, r9 */
/* @0x294720 mov r1, r0 */
/* @0x294724 ldr r3, [sp, #0x4] */
/* @0x294728 ldr r12, [r4, r12] */
/* @0x29472c ldr r12, [r12] */
/* @0x294730 blx r12 */
/* @0x294734 ldr r3, [pc, #0x28c] */
/* @0x294738 ldr r1, [pc, #0x28c] */
/* @0x29473c ldr r2, [pc, #0x28c] */
/* @0x294740 ldr r0, [r4, r3] */
/* @0x294744 ldr r12, [sp, #0x4] */
/* @0x294748 ldr r3, [pc, #0x284] */
/* @0x29474c str r9, [r0] */
/* @0x294750 ldr r1, [r4, r1] */
/* @0x294754 str r9, [r1] */
/* @0x294758 ldr r2, [r4, r2] */
/* @0x29475c str r12, [r2] */
/* @0x294760 ldr r3, [r4, r3] */
/* @0x294764 str r12, [r3] */
/* @0x294768 bl 0x1d4778 <_Z16MainLoop_Processv> */
/* @0x29476c ldr r3, [pc, #0x264] */
/* @0x294770 ldr r3, [r4, r3] */
/* @0x294774 ldrb r3, [r3] */
/* @0x294778 cmp r3, #0 */
/* @0x29477c bne 0x29478c <Java_com_yoyogames_runner_RunnerJNILib_Process+0x274> */
/* @0x294780 ldrb r3, [r5] */
/* @0x294784 cmp r3, #0 */
/* @0x294788 bne 0x2948bc <Java_com_yoyogames_runner_RunnerJNILib_Process+0x3a4> */
/* @0x29478c ldr r3, [pc, #0x248] */
/* @0x294790 ldr r5, [r4, r3] */
/* @0x294794 ldrb r8, [r5] */
/* @0x294798 cmp r8, #0 */
/* @0x29479c beq 0x294894 <Java_com_yoyogames_runner_RunnerJNILib_Process+0x37c> */
/* @0x2947a0 bl 0x215148 <Timing_Time> */
/* @0x2947a4 ldr r3, [pc, #0x234] */
/* @0x2947a8 ldrb r2, [r5] */
/* @0x2947ac ldr r3, [r4, r3] */
/* @0x2947b0 subs r0, r0, r6 */
/* @0x2947b4 sbc r1, r1, r7 */
/* @0x2947b8 cmp r2, #0 */
/* @0x2947bc strd r0, r1, [r3] */
/* @0x2947c0 movne r0, #1 */
/* @0x2947c4 bne 0x2947e0 <Java_com_yoyogames_runner_RunnerJNILib_Process+0x2c8> */
/* @0x2947c8 ldr r3, [pc, #0x214] */
/* @0x2947cc ldr r3, [r4, r3] */
/* @0x2947d0 ldrb r0, [r3] */
/* @0x2947d4 cmp r0, #0 */
/* @0x2947d8 movne r0, #2 */
/* @0x2947dc moveq r0, #0 */
/* @0x2947e0 add sp, sp, #20 */
/* @0x2947e4 vpop {d8, d9} */
/* @0x2947e8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2947ec ldr r3, [pc, #0x1f4] */
/* @0x2947f0 ldr r3, [r4, r3] */
/* @0x2947f4 ldr r3, [r3] */
/* @0x2947f8 cmp r3, #0 */
/* @0x2947fc mvnne r2, #0 */
/* @0x294800 beq 0x294814 <Java_com_yoyogames_runner_RunnerJNILib_Process+0x2fc> */
/* @0x294804 str r2, [r3, #0x14] */
/* @0x294808 ldr r3, [r3, #0x34] */
/* @0x29480c cmp r3, #0 */
/* @0x294810 bne 0x294804 <Java_com_yoyogames_runner_RunnerJNILib_Process+0x2ec> */
/* @0x294814 ldr r3, [pc, #0x1d0] */
/* @0x294818 ldr r10, [r4, r3] */
/* @0x29481c ldr r6, [r10, #0x4] */
/* @0x294820 cmp r6, #0 */
/* @0x294824 lslge r5, r6, #3 */
/* @0x294828 movge r7, #0 */
/* @0x29482c blt 0x29458c <Java_com_yoyogames_runner_RunnerJNILib_Process+0x74> */
/* @0x294830 ldr r3, [r10] */
/* @0x294834 add r2, r3, r5 */
/* @0x294838 ldr r8, [r3, r5] */
/* @0x29483c str r7, [r3, r5] */
/* @0x294840 cmp r8, #0 */
/* @0x294844 str r7, [r2, #0x4] */
/* @0x294848 beq 0x294878 <Java_com_yoyogames_runner_RunnerJNILib_Process+0x360> */
/* @0x29484c ldr r11, [r8, #0x4] */
/* @0x294850 ldr r0, [r8, #0xc] */
/* @0x294854 bl 0x27d1d0 <_ZdlPv> */
/* @0x294858 mov r0, r8 */
/* @0x29485c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x294860 ldr r3, [r10, #0x8] */
/* @0x294864 cmp r11, #0 */
/* @0x294868 mov r8, r11 */
/* @0x29486c sub r3, r3, #1 */
/* @0x294870 str r3, [r10, #0x8] */
/* @0x294874 bne 0x29484c <Java_com_yoyogames_runner_RunnerJNILib_Process+0x334> */
/* @0x294878 sub r6, r6, #1 */
/* @0x29487c sub r5, r5, #8 */
/* @0x294880 cmn r6, #1 */
/* @0x294884 bne 0x294830 <Java_com_yoyogames_runner_RunnerJNILib_Process+0x318> */
/* @0x294888 ldr r2, [sp, #0xc] */
/* @0x29488c ldr r3, [r2] */
/* @0x294890 b 0x294584 <Java_com_yoyogames_runner_RunnerJNILib_Process+0x6c> */
/* @0x294894 bl 0x1d1b38 <_Z11Run_EndGamev> */
/* @0x294898 bl 0x2a16bc <_Z9EndOfGamev> */
/* @0x29489c bl 0x28fe4c <_Z9Terminatev> */
/* @0x2948a0 bl 0x2a27fc <_Z4Quitv> */
/* @0x2948a4 bl 0x2a2c3c <_Z7RunGamev> */
/* @0x2948a8 bl 0x1cba6c <_Z19FINALIZE_Run_Globalv> */
/* @0x2948ac ldr r3, [pc, #0x13c] */
/* @0x2948b0 ldr r3, [r4, r3] */
/* @0x2948b4 strb r8, [r3] */
/* @0x2948b8 b 0x2947a0 <Java_com_yoyogames_runner_RunnerJNILib_Process+0x288> */
/* @0x2948bc bl 0x2903f8 <_Z13DoFrameTimingv> */
/* @0x2948c0 b 0x29478c <Java_com_yoyogames_runner_RunnerJNILib_Process+0x274> */
/* @0x2948c4 ldr r3, [r5] */
/* @0x2948c8 mov r0, #3008 */
/* @0x2948cc blx r3 */
/* @0x2948d0 ldr r3, [r5] */
/* @0x2948d4 mov r0, #2912 */
/* @0x2948d8 blx r3 */
/* @0x2948dc ldr r3, [r5] */
/* @0x2948e0 mov r0, #2896 */
/* @0x2948e4 blx r3 */
/* @0x2948e8 b 0x2945f8 <Java_com_yoyogames_runner_RunnerJNILib_Process+0xe0> */
/* @0x2948ec bl 0x182d50 <_Z20ResetCurrentTexturesv> */
/* @0x2948f0 b 0x294624 <Java_com_yoyogames_runner_RunnerJNILib_Process+0x10c> */
/* @0x2948f4 bl 0x17daa8 <_Z22InvalidateOGLResourcesv> */
/* @0x2948f8 bl 0x17da94 <_Z16InitOGLResourcesv> */
/* @0x2948fc ldr r3, [pc, #0xe8] */
/* @0x294900 ldr r10, [r4, r3] */
/* @0x294904 ldr r6, [r10, #0x4] */
/* @0x294908 cmp r6, #0 */
/* @0x29490c blt 0x29458c <Java_com_yoyogames_runner_RunnerJNILib_Process+0x74> */
/* @0x294910 lsl r5, r6, #3 */
/* @0x294914 mov r8, #0 */
/* @0x294918 ldr r3, [r10] */
/* @0x29491c add r2, r3, r5 */
/* @0x294920 ldr r7, [r3, r5] */
/* @0x294924 str r8, [r3, r5] */
/* @0x294928 cmp r7, #0 */
/* @0x29492c str r8, [r2, #0x4] */
/* @0x294930 beq 0x294960 <Java_com_yoyogames_runner_RunnerJNILib_Process+0x448> */
/* @0x294934 ldr r11, [r7, #0x4] */
/* @0x294938 ldr r0, [r7, #0xc] */
/* @0x29493c bl 0x27d1d0 <_ZdlPv> */
/* @0x294940 mov r0, r7 */
/* @0x294944 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x294948 ldr r3, [r10, #0x8] */
/* @0x29494c cmp r11, #0 */
/* @0x294950 mov r7, r11 */
/* @0x294954 sub r3, r3, #1 */
/* @0x294958 str r3, [r10, #0x8] */
/* @0x29495c bne 0x294934 <Java_com_yoyogames_runner_RunnerJNILib_Process+0x41c> */
/* @0x294960 sub r6, r6, #1 */
/* @0x294964 sub r5, r5, #8 */
/* @0x294968 cmn r6, #1 */
/* @0x29496c bne 0x294918 <Java_com_yoyogames_runner_RunnerJNILib_Process+0x400> */
/* @0x294970 b 0x29458c <Java_com_yoyogames_runner_RunnerJNILib_Process+0x74> */
/* @0x294974 andseq sp, r5, r12, lsl r7 */
/* @0x294978 .word 0xffffef5c */
/* @0x29497c .word 0xfffffcec */
/* @0x294980 .word 0xffffe7b8 */
/* @0x294984 .word 0xffffbae8 */
/* @0x294988 .word 0xffffbad0 */
/* @0x29498c .word 0xffffbaec */
/* @0x294990 .word 0xffffe90c */
/* @0x294994 .word 0xffffbd54 */
/* @0x294998 .word 0xfffffd0c */
/* @0x29499c .word 0xffffdee4 */
/* @0x2949a0 .word 0xffffdeec */
/* @0x2949a4 .word 0xffffef54 */
/* @0x2949a8 .word 0xffffdef0 */
/* @0x2949ac .word 0xffffdee8 */
/* @0x2949b0 .word 0xfffffcf4 */
/* @0x2949b4 .word 0xffffe21c */
/* @0x2949b8 .word 0xffffe9c4 */
/* @0x2949bc ldrdeq r2, r3, [r12], #-76 */
/* @0x2949c0 .word 0xffffbae4 */
/* @0x2949c4 .word 0xffffbaf0 */
/* @0x2949c8 .word 0xffffe6b8 */
/* @0x2949cc .word 0xffffe24c */
/* @0x2949d0 .word 0xffffe6c0 */
/* @0x2949d4 .word 0xffffe250 */
/* @0x2949d8 .word 0xffffc960 */
/* @0x2949dc .word 0xffffeebc */
/* @0x2949e0 .word 0xffffe778 */
/* @0x2949e4 .word 0xfffffcf0 */
/* @0x2949e8 .word 0xffffe664 */
/* @0x2949ec .word 0xffffbec0 */
/* @0x2949f0 .word 0xffffdefc */

/* ── FUNC 0x2949f4 · Java_com_yoyogames_runner_RunnerJNILib_LoginResult · size=204 · insn=51 */
/* @0x2949f4 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2949f8 mov r4, r0 */
/* @0x2949fc mov r8, r2 */
/* @0x294a00 mov r7, r3 */
/* @0x294a04 bl 0x290614 <setJNIEnv> */
/* @0x294a08 ldr r3, [r4] */
/* @0x294a0c mov r1, r8 */
/* @0x294a10 mov r2, #0 */
/* @0x294a14 mov r0, r4 */
/* @0x294a18 ldr r3, [r3, #0x2a4] */
/* @0x294a1c blx r3 */
/* @0x294a20 ldr r3, [r4] */
/* @0x294a24 mov r1, r7 */
/* @0x294a28 mov r2, #0 */
/* @0x294a2c ldr r3, [r3, #0x2a4] */
/* @0x294a30 mov r6, r0 */
/* @0x294a34 mov r0, r4 */
/* @0x294a38 blx r3 */
/* @0x294a3c adds r3, r6, #0 */
/* @0x294a40 movne r3, #1 */
/* @0x294a44 adds r5, r0, #0 */
/* @0x294a48 mov r9, r0 */
/* @0x294a4c movne r5, #1 */
/* @0x294a50 tst r5, r3 */
/* @0x294a54 bne 0x294a9c <Java_com_yoyogames_runner_RunnerJNILib_LoginResult+0xa8> */
/* @0x294a58 cmp r3, #0 */
/* @0x294a5c beq 0x294a78 <Java_com_yoyogames_runner_RunnerJNILib_LoginResult+0x84> */
/* @0x294a60 ldr r3, [r4] */
/* @0x294a64 mov r1, r8 */
/* @0x294a68 mov r2, r6 */
/* @0x294a6c mov r0, r4 */
/* @0x294a70 ldr r3, [r3, #0x2a8] */
/* @0x294a74 blx r3 */
/* @0x294a78 cmp r5, #0 */
/* @0x294a7c popeq {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x294a80 ldr r3, [r4] */
/* @0x294a84 mov r1, r7 */
/* @0x294a88 mov r2, r9 */
/* @0x294a8c mov r0, r4 */
/* @0x294a90 ldr r3, [r3, #0x2a8] */
/* @0x294a94 blx r3 */
/* @0x294a98 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x294a9c bl 0xb6538 <strlen@plt> */
/* @0x294aa0 mov r10, r0 */
/* @0x294aa4 mov r0, r6 */
/* @0x294aa8 bl 0xb6640 <strdup@plt> */
/* @0x294aac mov r1, r10 */
/* @0x294ab0 mov r2, r0 */
/* @0x294ab4 ldr r0, [sp, #0x20] */
/* @0x294ab8 bl 0xf27b4 <_ZN10InputQuery19SetUserNamePasswordEiiPKc> */
/* @0x294abc b 0x294a60 <Java_com_yoyogames_runner_RunnerJNILib_LoginResult+0x6c> */

/* ── FUNC 0x294ac0 · Java_com_yoyogames_runner_RunnerJNILib_IAPStoreLoadEvent · size=24 · insn=6 */
/* @0x294ac0 push {r4, lr} */
/* @0x294ac4 mov r4, r2 */
/* @0x294ac8 bl 0x290614 <setJNIEnv> */
/* @0x294acc mov r0, r4 */
/* @0x294ad0 pop {r4, lr} */
/* @0x294ad4 b 0x155630 <_Z19YYIAPStoreLoadEventi> */

/* ── FUNC 0x294ad8 · Java_com_yoyogames_runner_RunnerJNILib_IAPProductDetailsReceived · size=88 · insn=22 */
/* @0x294ad8 push {r4, r5, r6, lr} */
/* @0x294adc mov r4, r0 */
/* @0x294ae0 mov r5, r2 */
/* @0x294ae4 bl 0x290614 <setJNIEnv> */
/* @0x294ae8 ldr r3, [r4] */
/* @0x294aec mov r1, r5 */
/* @0x294af0 mov r2, #0 */
/* @0x294af4 mov r0, r4 */
/* @0x294af8 ldr r3, [r3, #0x2a4] */
/* @0x294afc blx r3 */
/* @0x294b00 mov r6, r0 */
/* @0x294b04 bl 0x1553e8 <_Z27YYIAPProductDetailsReceivedPKc> */
/* @0x294b08 cmp r6, #0 */
/* @0x294b0c cmpne r5, #0 */
/* @0x294b10 popeq {r4, r5, r6, pc} */
/* @0x294b14 ldr r3, [r4] */
/* @0x294b18 mov r1, r5 */
/* @0x294b1c mov r2, r6 */
/* @0x294b20 mov r0, r4 */
/* @0x294b24 ldr r3, [r3, #0x2a8] */
/* @0x294b28 blx r3 */
/* @0x294b2c pop {r4, r5, r6, pc} */

/* ── FUNC 0x294b30 · Java_com_yoyogames_runner_RunnerJNILib_IAPProductPurchaseEvent · size=88 · insn=22 */
/* @0x294b30 push {r4, r5, r6, lr} */
/* @0x294b34 mov r4, r0 */
/* @0x294b38 mov r5, r2 */
/* @0x294b3c bl 0x290614 <setJNIEnv> */
/* @0x294b40 ldr r3, [r4] */
/* @0x294b44 mov r1, r5 */
/* @0x294b48 mov r2, #0 */
/* @0x294b4c mov r0, r4 */
/* @0x294b50 ldr r3, [r3, #0x2a4] */
/* @0x294b54 blx r3 */
/* @0x294b58 mov r6, r0 */
/* @0x294b5c bl 0x1554ac <_Z18YYIAPPurchaseEventPKc> */
/* @0x294b60 cmp r6, #0 */
/* @0x294b64 cmpne r5, #0 */
/* @0x294b68 popeq {r4, r5, r6, pc} */
/* @0x294b6c ldr r3, [r4] */
/* @0x294b70 mov r1, r5 */
/* @0x294b74 mov r2, r6 */
/* @0x294b78 mov r0, r4 */
/* @0x294b7c ldr r3, [r3, #0x2a8] */
/* @0x294b80 blx r3 */
/* @0x294b84 pop {r4, r5, r6, pc} */

/* ── FUNC 0x294b88 · Java_com_yoyogames_runner_RunnerJNILib_IAPConsumeEvent · size=88 · insn=22 */
/* @0x294b88 push {r4, r5, r6, lr} */
/* @0x294b8c mov r4, r0 */
/* @0x294b90 mov r5, r2 */
/* @0x294b94 bl 0x290614 <setJNIEnv> */
/* @0x294b98 ldr r3, [r4] */
/* @0x294b9c mov r1, r5 */
/* @0x294ba0 mov r2, #0 */
/* @0x294ba4 mov r0, r4 */
/* @0x294ba8 ldr r3, [r3, #0x2a4] */
/* @0x294bac blx r3 */
/* @0x294bb0 mov r6, r0 */
/* @0x294bb4 bl 0x15556c <_Z17YYIAPConsumeEventPKc> */
/* @0x294bb8 cmp r6, #0 */
/* @0x294bbc cmpne r5, #0 */
/* @0x294bc0 popeq {r4, r5, r6, pc} */
/* @0x294bc4 ldr r3, [r4] */
/* @0x294bc8 mov r1, r5 */
/* @0x294bcc mov r2, r6 */
/* @0x294bd0 mov r0, r4 */
/* @0x294bd4 ldr r3, [r3, #0x2a8] */
/* @0x294bd8 blx r3 */
/* @0x294bdc pop {r4, r5, r6, pc} */

/* ── FUNC 0x294be0 · Java_com_yoyogames_runner_RunnerJNILib_IAPRestoreEvent · size=24 · insn=6 */
/* @0x294be0 push {r4, lr} */
/* @0x294be4 mov r4, r2 */
/* @0x294be8 bl 0x290614 <setJNIEnv> */
/* @0x294bec mov r0, r4 */
/* @0x294bf0 pop {r4, lr} */
/* @0x294bf4 b 0x1556a8 <_Z17YYIAPRestoreEventi> */

/* ── FUNC 0x294bf8 · Java_com_yoyogames_runner_RunnerJNILib_iCadeEventDispatch · size=16 · insn=4 */
/* @0x294bf8 adds r1, r3, #0 */
/* @0x294bfc mov r0, r2 */
/* @0x294c00 movne r1, #1 */
/* @0x294c04 b 0x1908f0 <_Z19iCadeSetButtonStateib> */

/* ── FUNC 0x294c08 · Java_com_yoyogames_runner_RunnerJNILib_registerGamepadConnected · size=16 · insn=4 */
/* @0x294c08 mov r0, r2 */
/* @0x294c0c mov r1, r3 */
/* @0x294c10 ldr r2, [sp] */
/* @0x294c14 b 0x190874 <_Z31RegisterAndroidGamepadConnectediii> */

/* ── FUNC 0x294c18 · Java_com_yoyogames_runner_RunnerJNILib_initGLFuncs · size=32 · insn=8 */
/* @0x294c18 push {r4, lr} */
/* @0x294c1c ldr r4, [pc, #0x10] */
/* @0x294c20 ldr r4, [pc, r4] */
/* @0x294c24 str r2, [r4] */
/* @0x294c28 bl 0x28fce4 <_Z15ImportGLLibraryv> */
/* @0x294c2c ldr r0, [r4] */
/* @0x294c30 pop {r4, pc} */
/* @0x294c34 andseq r11, r5, r8, ror #15 */

/* ── FUNC 0x294c38 · Java_com_yoyogames_runner_RunnerJNILib_canFlip · size=20 · insn=5 */
/* @0x294c38 ldr r3, [pc, #0x8] */
/* @0x294c3c ldr r3, [pc, r3] */
/* @0x294c40 ldrb r0, [r3] */
/* @0x294c44 bx lr */
/* @0x294c48 andseq r11, r5, r8, lsl r8 */

/* ── FUNC 0x294c4c · Java_com_yoyogames_runner_RunnerJNILib_GCMPushResult · size=112 · insn=28 */
/* @0x294c4c push {r4, r5, r6, r7, r8, lr} */
/* @0x294c50 mov r4, r0 */
/* @0x294c54 mov r5, r2 */
/* @0x294c58 mov r8, r3 */
/* @0x294c5c ldrb r7, [sp, #0x18] */
/* @0x294c60 bl 0x290614 <setJNIEnv> */
/* @0x294c64 ldr r3, [r4] */
/* @0x294c68 mov r1, r5 */
/* @0x294c6c mov r2, #0 */
/* @0x294c70 mov r0, r4 */
/* @0x294c74 ldr r3, [r3, #0x2a4] */
/* @0x294c78 blx r3 */
/* @0x294c7c mov r1, r8 */
/* @0x294c80 mov r6, r0 */
/* @0x294c84 adds r0, r7, #0 */
/* @0x294c88 mov r2, r6 */
/* @0x294c8c movne r0, #1 */
/* @0x294c90 bl 0x155f84 <_Z14Push_SendEventb14ePushEventTypePKc> */
/* @0x294c94 cmp r6, #0 */
/* @0x294c98 cmpne r5, #0 */
/* @0x294c9c popeq {r4, r5, r6, r7, r8, pc} */
/* @0x294ca0 ldr r3, [r4] */
/* @0x294ca4 mov r1, r5 */
/* @0x294ca8 mov r2, r6 */
/* @0x294cac mov r0, r4 */
/* @0x294cb0 ldr r3, [r3, #0x2a8] */
/* @0x294cb4 blx r3 */
/* @0x294cb8 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x294cbc · yySocket::~yySocket() · size=92 · insn=23 */
/* @0x294cbc push {r4, lr} */
/* @0x294cc0 mov r4, r0 */
/* @0x294cc4 bl 0x296044 <_ZN8yySocket16CommonDestructorEv> */
/* @0x294cc8 ldr r0, [r4] */
/* @0x294ccc cmn r0, #1 */
/* @0x294cd0 beq 0x294cec <_ZN8yySocketD2Ev+0x30> */
/* @0x294cd4 mov r1, #2 */
/* @0x294cd8 bl 0xb6d6c <shutdown@plt> */
/* @0x294cdc ldr r0, [r4] */
/* @0x294ce0 bl 0xb6d78 <close@plt> */
/* @0x294ce4 mvn r3, #0 */
/* @0x294ce8 str r3, [r4] */
/* @0x294cec ldr r0, [r4, #0x4] */
/* @0x294cf0 cmn r0, #1 */
/* @0x294cf4 beq 0x294d10 <_ZN8yySocketD2Ev+0x54> */
/* @0x294cf8 mov r1, #2 */
/* @0x294cfc bl 0xb6d6c <shutdown@plt> */
/* @0x294d00 ldr r0, [r4, #0x4] */
/* @0x294d04 bl 0xb6d78 <close@plt> */
/* @0x294d08 mvn r3, #0 */
/* @0x294d0c str r3, [r4, #0x4] */
/* @0x294d10 mov r0, r4 */
/* @0x294d14 pop {r4, pc} */

/* ── FUNC 0x294cbc · yySocket::~yySocket() · alias of the symbol above · insn=0 */

/* ── FUNC 0x294d18 · yySocket::Startup() · size=8 · insn=2 */
/* @0x294d18 mov r0, #0 */
/* @0x294d1c bx lr */

/* ── FUNC 0x294d20 · yySocket::ShutDown() · size=4 · insn=1 */
/* @0x294d20 bx lr */

/* ── FUNC 0x294d24 · yySocket::DumpError() · size=4 · insn=1 */
/* @0x294d24 bx lr */

/* ── FUNC 0x294d28 · yySocket::Process() · size=416 · insn=104 */
/* @0x294d28 ldrb r3, [r0, #0x2d] */
/* @0x294d2c push {r4, r5, r6, r7, lr} */
/* @0x294d30 cmp r3, #0 */
/* @0x294d34 sub sp, sp, #156 */
/* @0x294d38 mov r6, r0 */
/* @0x294d3c bne 0x294d84 <_ZN8yySocket7ProcessEv+0x5c> */
/* @0x294d40 ldrb r12, [r6, #0x2f] */
/* @0x294d44 cmp r12, #0 */
/* @0x294d48 bne 0x294d54 <_ZN8yySocket7ProcessEv+0x2c> */
/* @0x294d4c add sp, sp, #156 */
/* @0x294d50 pop {r4, r5, r6, r7, pc} */
/* @0x294d54 mov r0, r6 */
/* @0x294d58 bl 0x296320 <_ZN8yySocket19ProcessGMSHandshakeEv> */
/* @0x294d5c subs r1, r0, #0 */
/* @0x294d60 beq 0x294ea4 <_ZN8yySocket7ProcessEv+0x17c> */
/* @0x294d64 cmp r1, #2 */
/* @0x294d68 bne 0x294d4c <_ZN8yySocket7ProcessEv+0x24> */
/* @0x294d6c ldr r0, [r6, #0x68] */
/* @0x294d70 mov r1, #1 */
/* @0x294d74 bl 0x2989ac <_Z41ThrowNonBlockingConnectSocketNetworkEventib> */
/* @0x294d78 mov r3, #0 */
/* @0x294d7c strb r3, [r6, #0x2f] */
/* @0x294d80 b 0x294d4c <_ZN8yySocket7ProcessEv+0x24> */
/* @0x294d84 add r4, sp, #24 */
/* @0x294d88 mov r1, #0 */
/* @0x294d8c mov r2, #128 */
/* @0x294d90 mov r7, r1 */
/* @0x294d94 mov r0, r4 */
/* @0x294d98 add r5, sp, #152 */
/* @0x294d9c bl 0xb65b0 <memset@plt> */
/* @0x294da0 ldr r3, [r6] */
/* @0x294da4 mov r2, r4 */
/* @0x294da8 mov r4, #1 */
/* @0x294dac and lr, r3, #31 */
/* @0x294db0 add r0, r3, r4 */
/* @0x294db4 asr r12, r3, #5 */
/* @0x294db8 lsl lr, r4, lr */
/* @0x294dbc mov r1, r7 */
/* @0x294dc0 mov r3, r7 */
/* @0x294dc4 add r12, r5, r12, lsl #2 */
/* @0x294dc8 add r5, sp, #16 */
/* @0x294dcc str r5, [sp] */
/* @0x294dd0 str lr, [r12, #-0x80] */
/* @0x294dd4 str r7, [sp, #0x10] */
/* @0x294dd8 str r7, [sp, #0x14] */
/* @0x294ddc bl 0xb6d84 <select@plt> */
/* @0x294de0 cmp r0, #1 */
/* @0x294de4 mov r4, r0 */
/* @0x294de8 beq 0x294e50 <_ZN8yySocket7ProcessEv+0x128> */
/* @0x294dec bl 0x215148 <Timing_Time> */
/* @0x294df0 ldr r12, [pc, #0xcc] */
/* @0x294df4 mov r4, #1000 */
/* @0x294df8 ldrd r2, r3, [r6, #64] */
/* @0x294dfc ldr r12, [pc, r12] */
/* @0x294e00 ldr r12, [r12] */
/* @0x294e04 mul r4, r4, r12 */
/* @0x294e08 asr r5, r4, #31 */
/* @0x294e0c subs r0, r0, r2 */
/* @0x294e10 sbc r1, r1, r3 */
/* @0x294e14 cmp r1, r5 */
/* @0x294e18 cmpeq r0, r4 */
/* @0x294e1c bls 0x294d40 <_ZN8yySocket7ProcessEv+0x18> */
/* @0x294e20 mov r2, #0 */
/* @0x294e24 mov r3, #0 */
/* @0x294e28 strb r7, [r6, #0x2d] */
/* @0x294e2c strd r2, r3, [r6, #64] */
/* @0x294e30 ldr r0, [r6] */
/* @0x294e34 bl 0xb6d78 <close@plt> */
/* @0x294e38 mvn r3, #0 */
/* @0x294e3c mov r1, r7 */
/* @0x294e40 ldr r0, [r6, #0x68] */
/* @0x294e44 str r3, [r6] */
/* @0x294e48 bl 0x2989ac <_Z41ThrowNonBlockingConnectSocketNetworkEventib> */
/* @0x294e4c b 0x294d40 <_ZN8yySocket7ProcessEv+0x18> */
/* @0x294e50 ldr r0, [r6] */
/* @0x294e54 mov r1, r4 */
/* @0x294e58 add r3, sp, #12 */
/* @0x294e5c mov r2, #4 */
/* @0x294e60 str r3, [sp] */
/* @0x294e64 add r3, sp, #11 */
/* @0x294e68 str r4, [sp, #0xc] */
/* @0x294e6c bl 0xb6d90 <getsockopt@plt> */
/* @0x294e70 ldrb r1, [sp, #0xb] */
/* @0x294e74 cmp r1, r7 */
/* @0x294e78 bne 0x294d40 <_ZN8yySocket7ProcessEv+0x18> */
/* @0x294e7c ldrb r12, [r6, #0x2e] */
/* @0x294e80 mov r2, #0 */
/* @0x294e84 mov r3, #0 */
/* @0x294e88 strb r1, [r6, #0x2d] */
/* @0x294e8c cmp r12, #0 */
/* @0x294e90 strd r2, r3, [r6, #64] */
/* @0x294e94 beq 0x294eb0 <_ZN8yySocket7ProcessEv+0x188> */
/* @0x294e98 str r1, [r6, #0x34] */
/* @0x294e9c strb r4, [r6, #0x2f] */
/* @0x294ea0 b 0x294d44 <_ZN8yySocket7ProcessEv+0x1c> */
/* @0x294ea4 ldr r0, [r6, #0x68] */
/* @0x294ea8 bl 0x2989ac <_Z41ThrowNonBlockingConnectSocketNetworkEventib> */
/* @0x294eac b 0x294d4c <_ZN8yySocket7ProcessEv+0x24> */
/* @0x294eb0 mov r1, r4 */
/* @0x294eb4 ldr r0, [r6, #0x68] */
/* @0x294eb8 bl 0x2989ac <_Z41ThrowNonBlockingConnectSocketNetworkEventib> */
/* @0x294ebc ldrb r12, [r6, #0x2f] */
/* @0x294ec0 b 0x294d44 <_ZN8yySocket7ProcessEv+0x1c> */
/* @0x294ec4 mulseq r5, r0, r11 */

/* ── FUNC 0x294ec8 · yySocket::Init() · size=8 · insn=2 */
/* @0x294ec8 mov r0, #0 */
/* @0x294ecc bx lr */

/* ── FUNC 0x294ed0 · yySocket::Quit() · size=4 · insn=1 */
/* @0x294ed0 bx lr */

/* ── FUNC 0x294ed4 · yySocket::SetTimeout(int, int) · size=92 · insn=23 */
/* @0x294ed4 push {r4, r5, r6, lr} */
/* @0x294ed8 add r6, r0, #180 */
/* @0x294edc sub sp, sp, #8 */
/* @0x294ee0 mov r4, r0 */
/* @0x294ee4 mov r5, #4 */
/* @0x294ee8 ldr r0, [r0] */
/* @0x294eec mov r3, r6 */
/* @0x294ef0 str r1, [r4, #0xb4] */
/* @0x294ef4 str r2, [r4, #0xb8] */
/* @0x294ef8 mov r1, #1 */
/* @0x294efc str r5, [sp] */
/* @0x294f00 mov r2, #20 */
/* @0x294f04 bl 0xb6d9c <setsockopt@plt> */
/* @0x294f08 cmp r0, #0 */
/* @0x294f0c bne 0x294f28 <_ZN8yySocket10SetTimeoutEii+0x54> */
/* @0x294f10 ldr r0, [r4] */
/* @0x294f14 mov r3, r6 */
/* @0x294f18 str r5, [sp] */
/* @0x294f1c mov r1, #1 */
/* @0x294f20 mov r2, #21 */
/* @0x294f24 bl 0xb6d9c <setsockopt@plt> */
/* @0x294f28 add sp, sp, #8 */
/* @0x294f2c pop {r4, r5, r6, pc} */

/* ── FUNC 0x294f30 · yySocket::AvoidTimeWait() · size=56 · insn=14 */
/* @0x294f30 str lr, [sp, #-0x4]! */
/* @0x294f34 sub sp, sp, #20 */
/* @0x294f38 ldr r0, [r0] */
/* @0x294f3c mov r3, #8 */
/* @0x294f40 mov r1, #1 */
/* @0x294f44 str r3, [sp] */
/* @0x294f48 mov r2, #13 */
/* @0x294f4c add r3, sp, r3 */
/* @0x294f50 mov r12, #0 */
/* @0x294f54 str r12, [sp, #0x8] */
/* @0x294f58 str r12, [sp, #0xc] */
/* @0x294f5c bl 0xb6d9c <setsockopt@plt> */
/* @0x294f60 add sp, sp, #20 */
/* @0x294f64 ldr pc, [sp], #4 */

/* ── FUNC 0x294f68 · yySocket::Create() · size=604 · insn=151 */
/* @0x294f68 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x294f6c sub sp, sp, #52 */
/* @0x294f70 ldr r6, [pc, #0x230] */
/* @0x294f74 mov r4, r0 */
/* @0x294f78 ldr r2, [pc, #0x22c] */
/* @0x294f7c add r6, pc, r6 */
/* @0x294f80 ldr r3, [r0, #0x8] */
/* @0x294f84 ldr r7, [r6, r2] */
/* @0x294f88 cmp r3, #0 */
/* @0x294f8c ldr r2, [r7] */
/* @0x294f90 str r2, [sp, #0x2c] */
/* @0x294f94 beq 0x294fec <_ZN8yySocket6CreateEv+0x84> */
/* @0x294f98 cmp r3, #1 */
/* @0x294f9c bne 0x295128 <_ZN8yySocket6CreateEv+0x1c0> */
/* @0x294fa0 ldr r5, [r4] */
/* @0x294fa4 mov r2, #17 */
/* @0x294fa8 mov r1, #2 */
/* @0x294fac cmn r5, #1 */
/* @0x294fb0 bne 0x295000 <_ZN8yySocket6CreateEv+0x98> */
/* @0x294fb4 ldrb r0, [r4, #0xc4] */
/* @0x294fb8 cmp r0, #0 */
/* @0x294fbc moveq r0, #2 */
/* @0x294fc0 movne r0, #10 */
/* @0x294fc4 bl 0xb6da8 <socket@plt> */
/* @0x294fc8 ldr r1, [pc, #0x1e0] */
/* @0x294fcc ldr r3, [pc, #0x1e0] */
/* @0x294fd0 add r1, pc, r1 */
/* @0x294fd4 cmn r0, #1 */
/* @0x294fd8 mov r5, r0 */
/* @0x294fdc str r0, [r4] */
/* @0x294fe0 beq 0x29518c <_ZN8yySocket6CreateEv+0x224> */
/* @0x294fe4 ldr r3, [r4, #0x8] */
/* @0x294fe8 b 0x295000 <_ZN8yySocket6CreateEv+0x98> */
/* @0x294fec ldr r5, [r4] */
/* @0x294ff0 mov r2, r3 */
/* @0x294ff4 mov r1, #1 */
/* @0x294ff8 cmn r5, #1 */
/* @0x294ffc beq 0x294fb4 <_ZN8yySocket6CreateEv+0x4c> */
/* @0x295000 cmp r3, #1 */
/* @0x295004 mov r8, #1 */
/* @0x295008 addeq r9, sp, #16 */
/* @0x29500c str r8, [sp, #0xc] */
/* @0x295010 beq 0x295070 <_ZN8yySocket6CreateEv+0x108> */
/* @0x295014 mov r3, #4 */
/* @0x295018 mov r0, r5 */
/* @0x29501c str r3, [sp] */
/* @0x295020 mov r1, #6 */
/* @0x295024 mov r2, r8 */
/* @0x295028 add r3, sp, #12 */
/* @0x29502c bl 0xb6d9c <setsockopt@plt> */
/* @0x295030 cmp r0, #0 */
/* @0x295034 blt 0x2950e4 <_ZN8yySocket6CreateEv+0x17c> */
/* @0x295038 ldrb r12, [r4, #0x2c] */
/* @0x29503c add r9, sp, #16 */
/* @0x295040 ldr r0, [r4] */
/* @0x295044 mov r2, #8 */
/* @0x295048 mov r1, r8 */
/* @0x29504c str r2, [sp] */
/* @0x295050 mov r3, r9 */
/* @0x295054 mov r2, #13 */
/* @0x295058 str r12, [sp, #0x10] */
/* @0x29505c mov r12, #0 */
/* @0x295060 str r12, [sp, #0x14] */
/* @0x295064 bl 0xb6d9c <setsockopt@plt> */
/* @0x295068 cmp r0, #0 */
/* @0x29506c blt 0x2950e4 <_ZN8yySocket6CreateEv+0x17c> */
/* @0x295070 ldrb r3, [r4, #0xc4] */
/* @0x295074 cmp r3, #0 */
/* @0x295078 beq 0x2950b4 <_ZN8yySocket6CreateEv+0x14c> */
/* @0x29507c ldr r0, [r4] */
/* @0x295080 mov r3, #4 */
/* @0x295084 mov r1, #41 */
/* @0x295088 str r3, [sp] */
/* @0x29508c mov r2, #26 */
/* @0x295090 mov r3, r9 */
/* @0x295094 mov r8, #0 */
/* @0x295098 str r8, [sp, #0x10] */
/* @0x29509c bl 0xb6d9c <setsockopt@plt> */
/* @0x2950a0 cmp r0, #0 */
/* @0x2950a4 blt 0x2950e4 <_ZN8yySocket6CreateEv+0x17c> */
/* @0x2950a8 ldr r3, [r4, #0x8] */
/* @0x2950ac cmp r3, #1 */
/* @0x2950b0 beq 0x295130 <_ZN8yySocket6CreateEv+0x1c8> */
/* @0x2950b4 mov r2, r9 */
/* @0x2950b8 ldr r0, [r4] */
/* @0x2950bc movw r1, #0x5452 */
/* @0x2950c0 mov r3, #1 */
/* @0x2950c4 str r3, [sp, #0x10] */
/* @0x2950c8 bl 0xb6db4 <ioctl@plt> */
/* @0x2950cc cmp r0, #0 */
/* @0x2950d0 bne 0x295104 <_ZN8yySocket6CreateEv+0x19c> */
/* @0x2950d4 mov r0, r4 */
/* @0x2950d8 ldr r1, [r4, #0xb4] */
/* @0x2950dc ldr r2, [r4, #0xb8] */
/* @0x2950e0 bl 0x294ed4 <_ZN8yySocket10SetTimeoutEii> */
/* @0x2950e4 mov r5, r0 */
/* @0x2950e8 ldr r2, [sp, #0x2c] */
/* @0x2950ec mov r0, r5 */
/* @0x2950f0 ldr r3, [r7] */
/* @0x2950f4 cmp r2, r3 */
/* @0x2950f8 bne 0x2951a4 <_ZN8yySocket6CreateEv+0x23c> */
/* @0x2950fc add sp, sp, #52 */
/* @0x295100 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x295104 ldr r3, [pc, #0xa8] */
/* @0x295108 ldr r1, [pc, #0xa8] */
/* @0x29510c ldr r3, [r6, r3] */
/* @0x295110 add r1, pc, r1 */
/* @0x295114 ldr r0, [r3] */
/* @0x295118 ldr r3, [r0] */
/* @0x29511c ldr r3, [r3, #0xc] */
/* @0x295120 blx r3 */
/* @0x295124 b 0x2950d4 <_ZN8yySocket6CreateEv+0x16c> */
/* @0x295128 mvn r5, #0 */
/* @0x29512c b 0x2950e8 <_ZN8yySocket6CreateEv+0x180> */
/* @0x295130 add r5, sp, #24 */
/* @0x295134 ldr r1, [pc, #0x80] */
/* @0x295138 mov r0, #10 */
/* @0x29513c str r8, [sp, #0x18] */
/* @0x295140 add r1, pc, r1 */
/* @0x295144 mov r2, r5 */
/* @0x295148 str r8, [sp, #0x1c] */
/* @0x29514c str r8, [sp, #0x20] */
/* @0x295150 str r8, [sp, #0x24] */
/* @0x295154 str r8, [sp, #0x28] */
/* @0x295158 bl 0xb6dc0 <inet_pton@plt> */
/* @0x29515c ldr r0, [r4] */
/* @0x295160 mov r2, #20 */
/* @0x295164 mov r3, r5 */
/* @0x295168 str r2, [sp] */
/* @0x29516c mov r1, #41 */
/* @0x295170 bl 0xb6d9c <setsockopt@plt> */
/* @0x295174 cmp r0, #0 */
/* @0x295178 bge 0x2950b4 <_ZN8yySocket6CreateEv+0x14c> */
/* @0x29517c ldr r1, [pc, #0x3c] */
/* @0x295180 mov r5, r0 */
/* @0x295184 ldr r3, [pc, #0x28] */
/* @0x295188 add r1, pc, r1 */
/* @0x29518c ldr r3, [r6, r3] */
/* @0x295190 ldr r0, [r3] */
/* @0x295194 ldr r3, [r0] */
/* @0x295198 ldr r3, [r3, #0xc] */
/* @0x29519c blx r3 */
/* @0x2951a0 b 0x2950e8 <_ZN8yySocket6CreateEv+0x180> */
/* @0x2951a4 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x2951a8 ldrsbeq r12, [r5], -r4 */
/* @0x2951ac .word 0xffffbd00 */
/* @0x2951b0 ldrdeq r4, r5, [r12], -r12 */
/* @0x2951b4 .word 0xffffbac4 */
/* @0x2951b8 andeq r4, r12, r8, ror #1 */
/* @0x2951bc andeq r4, r12, r8, lsl #1 */
/* @0x2951c0 andeq r4, r12, r8, asr #32 */

/* ── FUNC 0x2951c4 · yySocket::Bind(sockaddr const*, int) · size=124 · insn=31 */
/* @0x2951c4 push {r4, r5, r6, r7, lr} */
/* @0x2951c8 mov r5, r0 */
/* @0x2951cc sub sp, sp, #12 */
/* @0x2951d0 ldr r0, [r0] */
/* @0x2951d4 bl 0xb6dcc <bind@plt> */
/* @0x2951d8 subs r4, r0, #0 */
/* @0x2951dc blt 0x2951ec <_ZN8yySocket4BindEPK8sockaddri+0x28> */
/* @0x2951e0 mov r0, r4 */
/* @0x2951e4 add sp, sp, #12 */
/* @0x2951e8 pop {r4, r5, r6, r7, pc} */
/* @0x2951ec ldr r3, [pc, #0x44] */
/* @0x2951f0 ldr r7, [r5] */
/* @0x2951f4 ldr r3, [pc, r3] */
/* @0x2951f8 ldr r5, [r3] */
/* @0x2951fc ldr r3, [r5] */
/* @0x295200 ldr r6, [r3, #0xc] */
/* @0x295204 bl 0xb6bf8 <__errno@plt> */
/* @0x295208 ldr r1, [pc, #0x2c] */
/* @0x29520c mov r2, r7 */
/* @0x295210 add r1, pc, r1 */
/* @0x295214 mov r3, r0 */
/* @0x295218 mov r0, r5 */
/* @0x29521c ldr r12, [r3] */
/* @0x295220 mov r3, r4 */
/* @0x295224 str r12, [sp] */
/* @0x295228 blx r6 */
/* @0x29522c mov r0, r4 */
/* @0x295230 add sp, sp, #12 */
/* @0x295234 pop {r4, r5, r6, r7, pc} */
/* @0x295238 andseq r8, r5, r0, lsr #10 */
/* @0x29523c andeq r4, r12, r4, lsl r0 */

/* ── FUNC 0x295240 · yySocket::Listen(int) · size=76 · insn=19 */
/* @0x295240 push {r4, lr} */
/* @0x295244 ldr r0, [r0] */
/* @0x295248 bl 0xb6dd8 <listen@plt> */
/* @0x29524c subs r4, r0, #0 */
/* @0x295250 blt 0x29525c <_ZN8yySocket6ListenEi+0x1c> */
/* @0x295254 mov r0, r4 */
/* @0x295258 pop {r4, pc} */
/* @0x29525c ldr r3, [pc, #0x20] */
/* @0x295260 ldr r1, [pc, #0x20] */
/* @0x295264 ldr r3, [pc, r3] */
/* @0x295268 add r1, pc, r1 */
/* @0x29526c ldr r0, [r3] */
/* @0x295270 ldr r3, [r0] */
/* @0x295274 ldr r3, [r3, #0xc] */
/* @0x295278 blx r3 */
/* @0x29527c mov r0, r4 */
/* @0x295280 pop {r4, pc} */
/* @0x295284 ldrheq r8, [r5], -r0 */
/* @0x295288 andeq r3, r12, r8, ror #31 */

/* ── FUNC 0x29528c · yySocket::Accept() · size=80 · insn=20 */
/* @0x29528c ldrb r3, [r0, #0xc4] */
/* @0x295290 mov r1, r0 */
/* @0x295294 str lr, [sp, #-0x4]! */
/* @0x295298 cmp r3, #0 */
/* @0x29529c add r2, r0, #16 */
/* @0x2952a0 sub sp, sp, #12 */
/* @0x2952a4 movne r3, #28 */
/* @0x2952a8 moveq r3, #16 */
/* @0x2952ac str r3, [r0, #0x10] */
/* @0x2952b0 ldr r0, [r1], #24 */
/* @0x2952b4 bl 0xb6de4 <accept@plt> */
/* @0x2952b8 cmn r0, #1 */
/* @0x2952bc beq 0x2952c8 <_ZN8yySocket6AcceptEv+0x3c> */
/* @0x2952c0 add sp, sp, #12 */
/* @0x2952c4 ldr pc, [sp], #4 */
/* @0x2952c8 str r0, [sp, #0x4] */
/* @0x2952cc bl 0x294d24 <_ZN8yySocket9DumpErrorEv> */
/* @0x2952d0 ldr r0, [sp, #0x4] */
/* @0x2952d4 add sp, sp, #12 */
/* @0x2952d8 ldr pc, [sp], #4 */
