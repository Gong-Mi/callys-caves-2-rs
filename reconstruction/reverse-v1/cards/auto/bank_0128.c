/* libyoyo.so 覆盖卡组 0128
 * 函数 0x190874..0x1910b4，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x190874 · RegisterAndroidGamepadConnected(int, int, int) · size=124 · insn=31 */
/* @0x190874 push {r4, r5, r6, r7, r8, lr} */
/* @0x190878 mov r4, r0 */
/* @0x19087c mov r6, r1 */
/* @0x190880 mov r5, r2 */
/* @0x190884 bl 0x190014 <_Z12GamepadInitMv> */
/* @0x190888 ldr r3, [pc, #0x58] */
/* @0x19088c ldr r3, [pc, r3] */
/* @0x190890 ldr r3, [r3] */
/* @0x190894 cmp r4, r3 */
/* @0x190898 bge 0x1908bc <_Z31RegisterAndroidGamepadConnectediii+0x48> */
/* @0x19089c ldr r3, [pc, #0x48] */
/* @0x1908a0 mov r1, r6 */
/* @0x1908a4 mov r2, r5 */
/* @0x1908a8 ldr r3, [pc, r3] */
/* @0x1908ac ldr r3, [r3] */
/* @0x1908b0 ldr r0, [r3, r4, lsl #2] */
/* @0x1908b4 pop {r4, r5, r6, r7, r8, lr} */
/* @0x1908b8 b 0x18e69c <_ZN9GMGamePad12UpdateCountsEii> */
/* @0x1908bc add r0, r4, #1 */
/* @0x1908c0 bl 0x18e4a4 <_ZN9GMGamePad15SetGamePadCountEi> */
/* @0x1908c4 mov r7, r0 */
/* @0x1908c8 mov r0, #556 */
/* @0x1908cc bl 0x27c524 <_Znwj> */
/* @0x1908d0 mov r1, r6 */
/* @0x1908d4 mov r2, r5 */
/* @0x1908d8 mov r8, r0 */
/* @0x1908dc bl 0x18e9d4 <_ZN9GMGamePadC2Eii> */
/* @0x1908e0 str r8, [r7, r4, lsl #2] */
/* @0x1908e4 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1908e8 .word 0x0025f1d4 */
/* @0x1908ec .word 0x0025f1bc */

/* ── FUNC 0x1908f0 · iCadeSetButtonState(int, bool) · size=260 · insn=65 */
/* @0x1908f0 vmov.f32 s15, #1.000000e+00 */
/* @0x1908f4 cmp r1, #0 */
/* @0x1908f8 sub r3, r0, #8 */
/* @0x1908fc vldr s14, [pc, #216] */
/* @0x190900 vmoveq.f32 s15, s14 */
/* @0x190904 cmp r3, #3 */
/* @0x190908 addls pc, pc, r3, lsl #2 */
/* @0x19090c b 0x1909c0 <_Z19iCadeSetButtonStateib+0xd0> */
/* @0x190910 b 0x190970 <_Z19iCadeSetButtonStateib+0x80> */
/* @0x190914 b 0x190998 <_Z19iCadeSetButtonStateib+0xa8> */
/* @0x190918 b 0x190948 <_Z19iCadeSetButtonStateib+0x58> */
/* @0x19091c b 0x190920 <_Z19iCadeSetButtonStateib+0x30> */
/* @0x190920 cmp r1, #0 */
/* @0x190924 bne 0x190950 <_Z19iCadeSetButtonStateib+0x60> */
/* @0x190928 vmov.f32 s15, #1.000000e+00 */
/* @0x19092c ldr r3, [pc, #0xac] */
/* @0x190930 add r3, pc, r3 */
/* @0x190934 sub r3, r3, #2736 */
/* @0x190938 vldr s14, [r3, #-8] */
/* @0x19093c vadd.f32 s15, s14, s15 */
/* @0x190940 vstr s15, [r3, #-8] */
/* @0x190944 bx lr */
/* @0x190948 cmp r1, #0 */
/* @0x19094c bne 0x190928 <_Z19iCadeSetButtonStateib+0x38> */
/* @0x190950 vmov.f32 s15, #1.000000e+00 */
/* @0x190954 ldr r3, [pc, #0x88] */
/* @0x190958 add r3, pc, r3 */
/* @0x19095c sub r3, r3, #2736 */
/* @0x190960 vldr s14, [r3, #-8] */
/* @0x190964 vsub.f32 s15, s14, s15 */
/* @0x190968 vstr s15, [r3, #-8] */
/* @0x19096c bx lr */
/* @0x190970 cmp r1, #0 */
/* @0x190974 beq 0x1909a0 <_Z19iCadeSetButtonStateib+0xb0> */
/* @0x190978 vmov.f32 s15, #1.000000e+00 */
/* @0x19097c ldr r3, [pc, #0x64] */
/* @0x190980 add r3, pc, r3 */
/* @0x190984 sub r3, r3, #2736 */
/* @0x190988 vldr s14, [r3, #-12] */
/* @0x19098c vsub.f32 s15, s14, s15 */
/* @0x190990 vstr s15, [r3, #-12] */
/* @0x190994 bx lr */
/* @0x190998 cmp r1, #0 */
/* @0x19099c beq 0x190978 <_Z19iCadeSetButtonStateib+0x88> */
/* @0x1909a0 vmov.f32 s15, #1.000000e+00 */
/* @0x1909a4 ldr r3, [pc, #0x40] */
/* @0x1909a8 add r3, pc, r3 */
/* @0x1909ac sub r3, r3, #2736 */
/* @0x1909b0 vldr s14, [r3, #-12] */
/* @0x1909b4 vadd.f32 s15, s14, s15 */
/* @0x1909b8 vstr s15, [r3, #-12] */
/* @0x1909bc bx lr */
/* @0x1909c0 ldr r3, [pc, #0x28] */
/* @0x1909c4 add r3, pc, r3 */
/* @0x1909c8 sub r3, r3, #2768 */
/* @0x1909cc sub r3, r3, #12 */
/* @0x1909d0 add r0, r3, r0, lsl #2 */
/* @0x1909d4 vstr s15, [r0] */
/* @0x1909d8 bx lr */
/* @0x1909dc andeq r0, r0, r0 */
/* @0x1909e0 ldrshteq r6, [r10], -r0 */
/* @0x1909e4 eorseq r6, r10, r8, asr #29 */
/* @0x1909e8 eorseq r6, r10, r0, lsr #29 */
/* @0x1909ec eorseq r6, r10, r8, ror lr */
/* @0x1909f0 eorseq r6, r10, r12, asr lr */

/* ── FUNC 0x1909f4 · GamepadReportFailureM() · size=4 · insn=1 */
/* @0x1909f4 bx lr */

/* ── FUNC 0x1909f8 · GamepadQuitM() · size=200 · insn=50 */
/* @0x1909f8 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1909fc ldr r9, [pc, #0xa4] */
/* @0x190a00 ldr r2, [pc, #0xa4] */
/* @0x190a04 add r9, pc, r9 */
/* @0x190a08 ldr r3, [pc, #0xa0] */
/* @0x190a0c ldr r7, [r9, r2] */
/* @0x190a10 ldr r2, [r9, r3] */
/* @0x190a14 ldr r3, [r7] */
/* @0x190a18 ldr r6, [r2] */
/* @0x190a1c cmp r3, #0 */
/* @0x190a20 movgt r5, #0 */
/* @0x190a24 movgt r8, r5 */
/* @0x190a28 ble 0x190a5c <_Z12GamepadQuitMv+0x64> */
/* @0x190a2c ldr r4, [r6], #4 */
/* @0x190a30 add r5, r5, #1 */
/* @0x190a34 cmp r4, #0 */
/* @0x190a38 mov r0, r4 */
/* @0x190a3c beq 0x190a50 <_Z12GamepadQuitMv+0x58> */
/* @0x190a40 bl 0x18e64c <_ZN9GMGamePadD2Ev> */
/* @0x190a44 mov r0, r4 */
/* @0x190a48 bl 0x27d1d0 <_ZdlPv> */
/* @0x190a4c str r8, [r6, #-0x4] */
/* @0x190a50 ldr r3, [r7] */
/* @0x190a54 cmp r5, r3 */
/* @0x190a58 blt 0x190a2c <_Z12GamepadQuitMv+0x34> */
/* @0x190a5c ldr r4, [pc, #0x50] */
/* @0x190a60 mov r1, #0 */
/* @0x190a64 mov r2, #5376 */
/* @0x190a68 add r4, pc, r4 */
/* @0x190a6c add r0, r4, #28 */
/* @0x190a70 bl 0xb65b0 <memset@plt> */
/* @0x190a74 mov r0, #0 */
/* @0x190a78 bl 0x18e4a4 <_ZN9GMGamePad15SetGamePadCountEi> */
/* @0x190a7c bl 0x290274 <getJNIEnv> */
/* @0x190a80 ldr r2, [pc, #0x30] */
/* @0x190a84 ldr r3, [pc, #0x30] */
/* @0x190a88 ldr r2, [r9, r2] */
/* @0x190a8c ldr r3, [r9, r3] */
/* @0x190a90 ldr r1, [r2] */
/* @0x190a94 ldr r2, [r3] */
/* @0x190a98 bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x190a9c mov r3, #0 */
/* @0x190aa0 str r3, [r4] */
/* @0x190aa4 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x190aa8 eoreq r1, r6, r12, asr #4 */
/* @0x190aac .word 0xffffde10 */
/* @0x190ab0 .word 0xffffde14 */
/* @0x190ab4 eorseq r4, r10, r0, asr #27 */
/* @0x190ab8 .word 0xffffbd54 */
/* @0x190abc .word 0xffffea18 */

/* ── FUNC 0x190ac0 · GamepadUpdateM() · size=4 · insn=1 */
/* @0x190ac0 b 0x190490 <_Z16SetupGMLMappingsi+0x2bc> */

/* ── FUNC 0x190ac4 · GamepadSupportedM() · size=8 · insn=2 */
/* @0x190ac4 mov r0, #1 */
/* @0x190ac8 bx lr */

/* ── FUNC 0x190acc · TranslateGamepadButtonM(int, int) · size=120 · insn=30 */
/* @0x190acc cmp r1, #32768 */
/* @0x190ad0 blt 0x190b04 <_Z23TranslateGamepadButtonMii+0x38> */
/* @0x190ad4 cmp r0, #0 */
/* @0x190ad8 beq 0x190b0c <_Z23TranslateGamepadButtonMii+0x40> */
/* @0x190adc cmp r0, #63 */
/* @0x190ae0 bgt 0x190b1c <_Z23TranslateGamepadButtonMii+0x50> */
/* @0x190ae4 add r0, r0, r0, lsl #1 */
/* @0x190ae8 sub r1, r1, #32768 */
/* @0x190aec ldr r3, [pc, #0x48] */
/* @0x190af0 rsb r0, r0, r0, lsl #3 */
/* @0x190af4 add r1, r0, r1 */
/* @0x190af8 add r3, pc, r3 */
/* @0x190afc add r0, r3, r1, lsl #2 */
/* @0x190b00 ldr r1, [r0, #0x1c] */
/* @0x190b04 mov r0, r1 */
/* @0x190b08 bx lr */
/* @0x190b0c sub r1, r1, #32768 */
/* @0x190b10 sub r1, r1, #1 */
/* @0x190b14 cmp r1, #7 */
/* @0x190b18 bls 0x190b28 <_Z23TranslateGamepadButtonMii+0x5c> */
/* @0x190b1c mvn r1, #0 */
/* @0x190b20 mov r0, r1 */
/* @0x190b24 bx lr */
/* @0x190b28 ldr r3, [pc, #0x10] */
/* @0x190b2c add r3, pc, r3 */
/* @0x190b30 ldr r1, [r3, r1, lsl #2] */
/* @0x190b34 mov r0, r1 */
/* @0x190b38 bx lr */
/* @0x190b3c eorseq r4, r10, r0, lsr sp */
/* @0x190b40 andseq sp, r12, r0, asr r1 */

/* ── FUNC 0x190b44 · TranslateGamepadAxisM(int, int) · size=108 · insn=27 */
/* @0x190b44 cmp r1, #32768 */
/* @0x190b48 blt 0x190b7c <_Z21TranslateGamepadAxisMii+0x38> */
/* @0x190b4c cmp r0, #0 */
/* @0x190b50 beq 0x190b84 <_Z21TranslateGamepadAxisMii+0x40> */
/* @0x190b54 cmp r0, #63 */
/* @0x190b58 bgt 0x190ba4 <_Z21TranslateGamepadAxisMii+0x60> */
/* @0x190b5c add r0, r0, r0, lsl #1 */
/* @0x190b60 sub r1, r1, #32768 */
/* @0x190b64 ldr r3, [pc, #0x40] */
/* @0x190b68 rsb r0, r0, r0, lsl #3 */
/* @0x190b6c add r1, r0, r1 */
/* @0x190b70 add r3, pc, r3 */
/* @0x190b74 add r0, r3, r1, lsl #2 */
/* @0x190b78 ldr r1, [r0, #0x1c] */
/* @0x190b7c mov r0, r1 */
/* @0x190b80 bx lr */
/* @0x190b84 sub r1, r1, #32768 */
/* @0x190b88 movw r3, #0x8001 */
/* @0x190b8c sub r1, r1, #17 */
/* @0x190b90 cmp r1, #1 */
/* @0x190b94 mvnhi r1, #0 */
/* @0x190b98 movls r1, r3 */
/* @0x190b9c mov r0, r1 */
/* @0x190ba0 bx lr */
/* @0x190ba4 mvn r1, #0 */
/* @0x190ba8 b 0x190b7c <_Z21TranslateGamepadAxisMii+0x38> */
/* @0x190bac ldrhteq r4, [r10], -r8 */

/* ── FUNC 0x190bb0 · CInstanceBase::~CInstanceBase() · size=24 · insn=6 */
/* @0x190bb0 ldr r3, [pc, #0xc] */
/* @0x190bb4 ldr r3, [pc, r3] */
/* @0x190bb8 add r3, r3, #8 */
/* @0x190bbc str r3, [r0] */
/* @0x190bc0 bx lr */
/* @0x190bc4 .word 0x0025fab8 */

/* ── FUNC 0x190bb0 · CInstanceBase::~CInstanceBase() · alias of the symbol above · insn=0 */

/* ── FUNC 0x190bc8 · CBucket<16u, 1048576u, false>::Free(void const*) · size=120 · insn=30 */
/* @0x190bc8 ldr r3, [r0, #0x4] */
/* @0x190bcc str r4, [sp, #-0x4]! */
/* @0x190bd0 cmp r3, #0 */
/* @0x190bd4 mov r4, r0 */
/* @0x190bd8 beq 0x190c04 <_ZN7CBucketILj16ELj1048576ELb0EE4FreeEPKv+0x3c> */
/* @0x190bdc add r12, r3, #8 */
/* @0x190be0 add r2, r3, #1048576 */
/* @0x190be4 cmp r1, r12 */
/* @0x190be8 add r2, r2, #8 */
/* @0x190bec blo 0x190bf8 <_ZN7CBucketILj16ELj1048576ELb0EE4FreeEPKv+0x30> */
/* @0x190bf0 cmp r2, r1 */
/* @0x190bf4 bhi 0x190c10 <_ZN7CBucketILj16ELj1048576ELb0EE4FreeEPKv+0x48> */
/* @0x190bf8 ldr r3, [r3] */
/* @0x190bfc cmp r3, #0 */
/* @0x190c00 bne 0x190bdc <_ZN7CBucketILj16ELj1048576ELb0EE4FreeEPKv+0x14> */
/* @0x190c04 mov r0, r3 */
/* @0x190c08 ldr r4, [sp], #4 */
/* @0x190c0c bx lr */
/* @0x190c10 ldr r12, [r4, #0x8] */
/* @0x190c14 mov r0, #1 */
/* @0x190c18 ldr r2, [r4, #0x10] */
/* @0x190c1c ldr r3, [r4, #0xc] */
/* @0x190c20 add r2, r2, r0 */
/* @0x190c24 str r12, [r1] */
/* @0x190c28 sub r3, r3, #1 */
/* @0x190c2c str r1, [r4, #0x8] */
/* @0x190c30 str r2, [r4, #0x10] */
/* @0x190c34 str r3, [r4, #0xc] */
/* @0x190c38 ldr r4, [sp], #4 */
/* @0x190c3c bx lr */

/* ── FUNC 0x190c40 · CBucket<16u, 1048576u, false>::Init() · size=20 · insn=5 */
/* @0x190c40 mov r3, #0 */
/* @0x190c44 str r3, [r0, #0x4] */
/* @0x190c48 str r3, [r0, #0x8] */
/* @0x190c4c str r3, [r0, #0xc] */
/* @0x190c50 bx lr */

/* ── FUNC 0x190c54 · CBucket<16u, 1048576u, false>::Check() · size=124 · insn=31 */
/* @0x190c54 ldr r12, [r0, #0x8] */
/* @0x190c58 push {r4, r5, r6} */
/* @0x190c5c cmp r12, #0 */
/* @0x190c60 beq 0x190cc4 <_ZN7CBucketILj16ELj1048576ELb0EE5CheckEv+0x70> */
/* @0x190c64 ldr r4, [pc, #0x60] */
/* @0x190c68 mov r6, #0 */
/* @0x190c6c mov r5, #42 */
/* @0x190c70 ldr r4, [pc, r4] */
/* @0x190c74 ldr r3, [r0, #0x4] */
/* @0x190c78 cmp r3, #0 */
/* @0x190c7c beq 0x190ca8 <_ZN7CBucketILj16ELj1048576ELb0EE5CheckEv+0x54> */
/* @0x190c80 add r1, r3, #8 */
/* @0x190c84 add r2, r3, #1048576 */
/* @0x190c88 cmp r12, r1 */
/* @0x190c8c add r2, r2, #8 */
/* @0x190c90 blo 0x190c9c <_ZN7CBucketILj16ELj1048576ELb0EE5CheckEv+0x48> */
/* @0x190c94 cmp r2, r12 */
/* @0x190c98 bhi 0x190cac <_ZN7CBucketILj16ELj1048576ELb0EE5CheckEv+0x58> */
/* @0x190c9c ldr r3, [r3] */
/* @0x190ca0 cmp r3, #0 */
/* @0x190ca4 bne 0x190c80 <_ZN7CBucketILj16ELj1048576ELb0EE5CheckEv+0x2c> */
/* @0x190ca8 str r5, [r6] */
/* @0x190cac ldr r12, [r12] */
/* @0x190cb0 ldr r3, [r4] */
/* @0x190cb4 cmp r12, #0 */
/* @0x190cb8 add r3, r3, #1 */
/* @0x190cbc str r3, [r4] */
/* @0x190cc0 bne 0x190c74 <_ZN7CBucketILj16ELj1048576ELb0EE5CheckEv+0x20> */
/* @0x190cc4 pop {r4, r5, r6} */
/* @0x190cc8 bx lr */
/* @0x190ccc eoreq r12, r5, r4, asr pc */

/* ── FUNC 0x190cd0 · CBucket<16u, 1048576u, false>::GetSize() · size=8 · insn=2 */
/* @0x190cd0 mov r0, #16 */
/* @0x190cd4 bx lr */

/* ── FUNC 0x190cd8 · CInstanceBase::~CInstanceBase() · size=40 · insn=10 */
/* @0x190cd8 ldr r3, [pc, #0x1c] */
/* @0x190cdc push {r4, lr} */
/* @0x190ce0 ldr r3, [pc, r3] */
/* @0x190ce4 mov r4, r0 */
/* @0x190ce8 add r3, r3, #8 */
/* @0x190cec str r3, [r0] */
/* @0x190cf0 bl 0x27d1d0 <_ZdlPv> */
/* @0x190cf4 mov r0, r4 */
/* @0x190cf8 pop {r4, pc} */
/* @0x190cfc eoreq pc, r5, r12, lsl #19 */

/* ── FUNC 0x190d00 · YYSlot<YYObjectBase>::~YYSlot() · size=44 · insn=11 */
/* @0x190d00 push {r4, lr} */
/* @0x190d04 mov r4, r0 */
/* @0x190d08 ldr r0, [r0] */
/* @0x190d0c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x190d10 mov r3, #0 */
/* @0x190d14 mov r0, r4 */
/* @0x190d18 str r3, [r4] */
/* @0x190d1c str r3, [r4, #0x4] */
/* @0x190d20 str r3, [r4, #0x8] */
/* @0x190d24 str r3, [r4, #0xc] */
/* @0x190d28 pop {r4, pc} */

/* ── FUNC 0x190d00 · YYSlot<YYObjectBase>::~YYSlot() · alias of the symbol above · insn=0 */

/* ── FUNC 0x190d2c · Hash<CInstance>::~Hash() · size=148 · insn=37 */
/* @0x190d2c push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x190d30 mov r6, r0 */
/* @0x190d34 ldm r0, {r0, r8} */
/* @0x190d38 cmp r8, #0 */
/* @0x190d3c lslge r7, r8, #3 */
/* @0x190d40 movge r9, #0 */
/* @0x190d44 blt 0x190db4 <_ZN4HashI9CInstanceED2Ev+0x88> */
/* @0x190d48 ldr r4, [r0, r7] */
/* @0x190d4c add r3, r0, r7 */
/* @0x190d50 str r9, [r0, r7] */
/* @0x190d54 cmp r4, #0 */
/* @0x190d58 str r9, [r3, #0x4] */
/* @0x190d5c beq 0x190da4 <_ZN4HashI9CInstanceED2Ev+0x78> */
/* @0x190d60 ldr r3, [r4, #0xc] */
/* @0x190d64 ldr r5, [r4, #0x4] */
/* @0x190d68 cmp r3, #0 */
/* @0x190d6c mov r0, r3 */
/* @0x190d70 beq 0x190d80 <_ZN4HashI9CInstanceED2Ev+0x54> */
/* @0x190d74 ldr r3, [r3] */
/* @0x190d78 ldr r3, [r3, #0x4] */
/* @0x190d7c blx r3 */
/* @0x190d80 mov r0, r4 */
/* @0x190d84 mov r4, r5 */
/* @0x190d88 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x190d8c ldr r3, [r6, #0x8] */
/* @0x190d90 cmp r5, #0 */
/* @0x190d94 sub r3, r3, #1 */
/* @0x190d98 str r3, [r6, #0x8] */
/* @0x190d9c bne 0x190d60 <_ZN4HashI9CInstanceED2Ev+0x34> */
/* @0x190da0 ldr r0, [r6] */
/* @0x190da4 sub r8, r8, #1 */
/* @0x190da8 sub r7, r7, #8 */
/* @0x190dac cmn r8, #1 */
/* @0x190db0 bne 0x190d48 <_ZN4HashI9CInstanceED2Ev+0x1c> */
/* @0x190db4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x190db8 mov r0, r6 */
/* @0x190dbc pop {r3, r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x190d2c · Hash<CInstance>::~Hash() · alias of the symbol above · insn=0 */

/* ── FUNC 0x190dc0 · GetRValue() · size=196 · insn=49 */
/* @0x190dc0 push {r4, r5, r6, r7, r8, lr} */
/* @0x190dc4 ldr r4, [pc, #0xb4] */
/* @0x190dc8 ldr r4, [pc, r4] */
/* @0x190dcc ldr r0, [r4, #0x8] */
/* @0x190dd0 cmp r0, #0 */
/* @0x190dd4 beq 0x190dfc <_Z9GetRValuev+0x3c> */
/* @0x190dd8 ldr r3, [r4, #0x10] */
/* @0x190ddc ldr r2, [r0] */
/* @0x190de0 ldr r1, [r4, #0xc] */
/* @0x190de4 sub r3, r3, #1 */
/* @0x190de8 str r2, [r4, #0x8] */
/* @0x190dec str r3, [r4, #0x10] */
/* @0x190df0 add r3, r1, #1 */
/* @0x190df4 str r3, [r4, #0xc] */
/* @0x190df8 pop {r4, r5, r6, r7, r8, pc} */
/* @0x190dfc mov r0, #24 */
/* @0x190e00 movt r0, #0x10 */
/* @0x190e04 bl 0x27c524 <_Znwj> */
/* @0x190e08 mov r1, #120 */
/* @0x190e0c mov r2, #16 */
/* @0x190e10 movt r2, #0x10 */
/* @0x190e14 mov r5, r0 */
/* @0x190e18 add r0, r0, #8 */
/* @0x190e1c bl 0xb65b0 <memset@plt> */
/* @0x190e20 ldmib r4, {r7, r8} */
/* @0x190e24 add r1, r5, #24 */
/* @0x190e28 ldr r6, [r4, #0x10] */
/* @0x190e2c bic r1, r1, #15 */
/* @0x190e30 add r0, r1, #1044480 */
/* @0x190e34 str r7, [r5] */
/* @0x190e38 add r12, r0, #4080 */
/* @0x190e3c add r7, r6, #1 */
/* @0x190e40 str r5, [r4, #0x4] */
/* @0x190e44 add r3, r1, #16 */
/* @0x190e48 str r8, [r1] */
/* @0x190e4c mov r2, r1 */
/* @0x190e50 str r1, [r4, #0x8] */
/* @0x190e54 str r7, [r4, #0x10] */
/* @0x190e58 b 0x190e60 <_Z9GetRValuev+0xa0> */
/* @0x190e5c mov r2, r1 */
/* @0x190e60 mov r1, r3 */
/* @0x190e64 str r2, [r3], #16 */
/* @0x190e68 cmp r3, r12 */
/* @0x190e6c bne 0x190e5c <_Z9GetRValuev+0x9c> */
/* @0x190e70 add r3, r6, #65280 */
/* @0x190e74 add r0, r0, #4064 */
/* @0x190e78 add r3, r3, #255 */
/* @0x190e7c b 0x190de0 <_Z9GetRValuev+0x20> */
/* @0x190e80 eoreq pc, r5, r8, lsr #17 */

/* ── FUNC 0x190e84 · FreeRValue(RValue*, RValue**, RValue**) · size=108 · insn=27 */
/* @0x190e84 ldr r12, [pc, #0x60] */
/* @0x190e88 ldr r12, [pc, r12] */
/* @0x190e8c ldr r3, [r12, #0x4] */
/* @0x190e90 cmp r3, #0 */
/* @0x190e94 bxeq lr */
/* @0x190e98 add r1, r3, #8 */
/* @0x190e9c add r2, r3, #1048576 */
/* @0x190ea0 cmp r0, r1 */
/* @0x190ea4 add r2, r2, #8 */
/* @0x190ea8 blo 0x190eb4 <_Z10FreeRValueP6RValuePS0_S1_+0x30> */
/* @0x190eac cmp r2, r0 */
/* @0x190eb0 bhi 0x190ec4 <_Z10FreeRValueP6RValuePS0_S1_+0x40> */
/* @0x190eb4 ldr r3, [r3] */
/* @0x190eb8 cmp r3, #0 */
/* @0x190ebc bne 0x190e98 <_Z10FreeRValueP6RValuePS0_S1_+0x14> */
/* @0x190ec0 bx lr */
/* @0x190ec4 ldr r1, [r12, #0x8] */
/* @0x190ec8 ldr r2, [r12, #0x10] */
/* @0x190ecc ldr r3, [r12, #0xc] */
/* @0x190ed0 add r2, r2, #1 */
/* @0x190ed4 str r1, [r0] */
/* @0x190ed8 sub r3, r3, #1 */
/* @0x190edc str r0, [r12, #0x8] */
/* @0x190ee0 str r2, [r12, #0x10] */
/* @0x190ee4 str r3, [r12, #0xc] */
/* @0x190ee8 bx lr */
/* @0x190eec eoreq pc, r5, r8, ror #15 */

/* ── FUNC 0x190ef0 · CREATE_RVALUE_MUTEX() · size=60 · insn=15 */
/* @0x190ef0 push {r4, lr} */
/* @0x190ef4 ldr r4, [pc, #0x28] */
/* @0x190ef8 ldr r4, [pc, r4] */
/* @0x190efc ldr r3, [r4] */
/* @0x190f00 cmp r3, #0 */
/* @0x190f04 popne {r4, pc} */
/* @0x190f08 mov r0, #8 */
/* @0x190f0c bl 0xb6544 <malloc@plt> */
/* @0x190f10 ldr r1, [pc, #0x10] */
/* @0x190f14 add r1, pc, r1 */
/* @0x190f18 str r0, [r4] */
/* @0x190f1c pop {r4, lr} */
/* @0x190f20 b 0x27e038 <_ZN5Mutex4InitEPKc> */
/* @0x190f24 eoreq pc, r5, r12, ror r7 */
/* @0x190f28 andseq r11, r11, r8, asr #13 */

/* ── FUNC 0x190f2c · LOCK_RVALUE_MUTEX() · size=4 · insn=1 */
/* @0x190f2c bx lr */

/* ── FUNC 0x190f30 · UNLOCK_RVALUE_MUTEX() · size=4 · insn=1 */
/* @0x190f30 bx lr */

/* ── FUNC 0x190f34 · unsigned int CHashMapCalculateHash<YYObjectBase*>(YYObjectBase*) · size=12 · insn=3 */
/* @0x190f34 asr r0, r0, #8 */
/* @0x190f38 add r0, r0, #1 */
/* @0x190f3c bx lr */

/* ── FUNC 0x190f40 · unsigned int CHashMapCalculateHash<int>(int) · size=8 · insn=2 */
/* @0x190f40 add r0, r0, #1 */
/* @0x190f44 bx lr */

/* ── FUNC 0x190f48 · bool CHashMapCompareKeys<YYObjectBase*>(YYObjectBase*, YYObjectBase*) · size=16 · insn=4 */
/* @0x190f48 subs r3, r1, r0 */
/* @0x190f4c rsbs r0, r3, #0 */
/* @0x190f50 adcs r0, r0, r3 */
/* @0x190f54 bx lr */

/* ── FUNC 0x190f58 · CGCGeneration::CGCGeneration() · size=268 · insn=67 */
/* @0x190f58 push {r4, r5, r6, lr} */
/* @0x190f5c mov r4, r0 */
/* @0x190f60 mov r0, #20 */
/* @0x190f64 mov r6, #0 */
/* @0x190f68 bl 0x27c524 <_Znwj> */
/* @0x190f6c ldr r1, [pc, #0xe8] */
/* @0x190f70 mov r2, #16 */
/* @0x190f74 mov r3, #15 */
/* @0x190f78 add r1, pc, r1 */
/* @0x190f7c mov r5, r0 */
/* @0x190f80 str r2, [r0] */
/* @0x190f84 str r3, [r0, #0x8] */
/* @0x190f88 mov r2, #70 */
/* @0x190f8c mov r3, #1 */
/* @0x190f90 mov r0, #192 */
/* @0x190f94 str r6, [r5, #0x10] */
/* @0x190f98 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x190f9c mov r2, #192 */
/* @0x190fa0 mov r1, r6 */
/* @0x190fa4 str r0, [r5, #0x10] */
/* @0x190fa8 bl 0xb65b0 <memset@plt> */
/* @0x190fac ldr r2, [r5] */
/* @0x190fb0 vldr s15, [pc, #160] */
/* @0x190fb4 str r6, [r5, #0x4] */
/* @0x190fb8 cmp r2, r6 */
/* @0x190fbc vmov s13, r2 */
/* @0x190fc0 vcvt.f32.s32 s14, s13 */
/* @0x190fc4 vmul.f32 s15, s14, s15 */
/* @0x190fc8 vcvt.s32.f32 s15, s15 */
/* @0x190fcc vstr s15, [r5, #12] */
/* @0x190fd0 ble 0x190ff4 <_ZN13CGCGenerationC2Ev+0x9c> */
/* @0x190fd4 add r2, r2, r2, lsl #1 */
/* @0x190fd8 ldr r3, [r5, #0x10] */
/* @0x190fdc mov r1, r6 */
/* @0x190fe0 add r2, r3, r2, lsl #2 */
/* @0x190fe4 str r1, [r3, #0x8] */
/* @0x190fe8 add r3, r3, #12 */
/* @0x190fec cmp r3, r2 */
/* @0x190ff0 bne 0x190fe4 <_ZN13CGCGenerationC2Ev+0x8c> */
/* @0x190ff4 ldr r2, [pc, #0x64] */
/* @0x190ff8 mov r3, #0 */
/* @0x190ffc mvn r1, #0 */
/* @0x191000 str r5, [r4] */
/* @0x191004 ldr r2, [pc, r2] */
/* @0x191008 str r3, [r4, #0x4] */
/* @0x19100c str r3, [r4, #0xc] */
/* @0x191010 mov r0, r4 */
/* @0x191014 ldr r2, [r2] */
/* @0x191018 str r3, [r4, #0x8] */
/* @0x19101c str r3, [r4, #0x20] */
/* @0x191020 str r2, [r4, #0x2c] */
/* @0x191024 mvn r2, #-2147483648 */
/* @0x191028 str r3, [r4, #0x24] */
/* @0x19102c str r3, [r4, #0x28] */
/* @0x191030 str r3, [r4, #0x30] */
/* @0x191034 str r3, [r4, #0x34] */
/* @0x191038 str r3, [r4, #0x38] */
/* @0x19103c str r3, [r4, #0x48] */
/* @0x191040 str r3, [r4, #0x4c] */
/* @0x191044 str r3, [r4, #0x50] */
/* @0x191048 str r1, [r4, #0x1c] */
/* @0x19104c str r1, [r4, #0x18] */
/* @0x191050 str r2, [r4, #0x14] */
/* @0x191054 pop {r4, r5, r6, pc} */
/* @0x191058 svclo #0x19999a */
/* @0x19105c ldrheq r0, [r10], -r8 */
/* @0x191060 eoreq r12, r5, r12, lsl #25 */

/* ── FUNC 0x190f58 · CGCGeneration::CGCGeneration() · alias of the symbol above · insn=0 */

/* ── FUNC 0x191064 · CGCGeneration::~CGCGeneration() · size=80 · insn=20 */
/* @0x191064 push {r3, r4, r5, lr} */
/* @0x191068 mov r4, r0 */
/* @0x19106c ldr r5, [r0] */
/* @0x191070 cmp r5, #0 */
/* @0x191074 beq 0x191098 <_ZN13CGCGenerationD2Ev+0x34> */
/* @0x191078 ldr r0, [r5, #0x10] */
/* @0x19107c cmp r0, #0 */
/* @0x191080 beq 0x191090 <_ZN13CGCGenerationD2Ev+0x2c> */
/* @0x191084 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x191088 mov r3, #0 */
/* @0x19108c str r3, [r5, #0x10] */
/* @0x191090 mov r0, r5 */
/* @0x191094 bl 0x27d1d0 <_ZdlPv> */
/* @0x191098 mov r5, #0 */
/* @0x19109c ldr r0, [r4, #0x4] */
/* @0x1910a0 str r5, [r4] */
/* @0x1910a4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1910a8 str r5, [r4, #0x4] */
/* @0x1910ac mov r0, r4 */
/* @0x1910b0 pop {r3, r4, r5, pc} */

/* ── FUNC 0x191064 · CGCGeneration::~CGCGeneration() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1910b4 · anon_1910b4 · size=52 · insn=13 */
/* @0x1910b4 push {r4, lr} */
/* @0x1910b8 ldr r4, [pc, #0x24] */
/* @0x1910bc ldr r4, [pc, r4] */
/* @0x1910c0 add r0, r4, #264 */
/* @0x1910c4 bl 0x191064 <_ZN13CGCGenerationD2Ev> */
/* @0x1910c8 add r0, r4, #176 */
/* @0x1910cc bl 0x191064 <_ZN13CGCGenerationD2Ev> */
/* @0x1910d0 add r0, r4, #88 */
/* @0x1910d4 bl 0x191064 <_ZN13CGCGenerationD2Ev> */
/* @0x1910d8 mov r0, r4 */
/* @0x1910dc pop {r4, lr} */
/* @0x1910e0 b 0x191064 <_ZN13CGCGenerationD2Ev> */
/* @0x1910e4 eoreq r12, r5, r4, lsr #23 */
