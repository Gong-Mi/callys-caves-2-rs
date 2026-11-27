/* libyoyo.so 覆盖卡组 0182
 * 函数 0x201bb8..0x202dd8，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x201bb8 · CStream::WriteBoolean(bool) · size=4 · insn=1 */
/* @0x201bb8 b 0x201a10 <_ZN7CStream12WriteIntegerEi> */

/* ── FUNC 0x201bbc · ZDecompressStream(CStream&, CStream&) · size=460 · insn=115 */
/* @0x201bbc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x201bc0 sub sp, sp, #32768 */
/* @0x201bc4 ldr r6, [pc, #0x1ac] */
/* @0x201bc8 sub sp, sp, #76 */
/* @0x201bcc ldr lr, [pc, #0x1a8] */
/* @0x201bd0 add r12, sp, #12 */
/* @0x201bd4 ldr r6, [pc, r6] */
/* @0x201bd8 str r1, [sp, #0x4] */
/* @0x201bdc ldr lr, [pc, lr] */
/* @0x201be0 ldr r1, [pc, #0x198] */
/* @0x201be4 ldr r5, [r6] */
/* @0x201be8 add r7, sp, #32768 */
/* @0x201bec str lr, [sp, #0x2c] */
/* @0x201bf0 add lr, sp, #32768 */
/* @0x201bf4 add lr, lr, #72 */
/* @0x201bf8 movw r10, #0x7fc4 */
/* @0x201bfc ldr r3, [pc, #0x180] */
/* @0x201c00 movt r10, #0xffff */
/* @0x201c04 mov r9, r0 */
/* @0x201c08 add r1, pc, r1 */
/* @0x201c0c mov r0, r12 */
/* @0x201c10 mov r2, #56 */
/* @0x201c14 str r5, [r7, #0x44] */
/* @0x201c18 ldr r3, [pc, r3] */
/* @0x201c1c mov r4, r12 */
/* @0x201c20 str r3, [sp, #0x30] */
/* @0x201c24 mov r3, #0 */
/* @0x201c28 str r3, [lr, r10] */
/* @0x201c2c str r3, [sp, #0x34] */
/* @0x201c30 add r7, sp, #72 */
/* @0x201c34 str r3, [sp, #0x10] */
/* @0x201c38 bl 0xb69d0 <inflateInit_@plt> */
/* @0x201c3c subs r5, r0, #0 */
/* @0x201c40 movne r0, r5 */
/* @0x201c44 bne 0x201ce0 <_Z17ZDecompressStreamR7CStreamS0_+0x124> */
/* @0x201c48 add r8, sp, #16384 */
/* @0x201c4c sub r11, r7, #60 */
/* @0x201c50 add r8, r8, #68 */
/* @0x201c54 add r7, sp, #68 */
/* @0x201c58 mov r10, #16384 */
/* @0x201c5c mov r1, #0 */
/* @0x201c60 mov r2, #16384 */
/* @0x201c64 mov r0, r7 */
/* @0x201c68 bl 0xb65b0 <memset@plt> */
/* @0x201c6c mov r1, #0 */
/* @0x201c70 mov r2, #16384 */
/* @0x201c74 mov r0, r8 */
/* @0x201c78 bl 0xb65b0 <memset@plt> */
/* @0x201c7c mov r0, r9 */
/* @0x201c80 mov r1, r7 */
/* @0x201c84 mov r2, #16384 */
/* @0x201c88 bl 0x20172c <_ZN7CStream4ReadEPvi> */
/* @0x201c8c cmp r0, #0 */
/* @0x201c90 str r0, [r4, #0x4] */
/* @0x201c94 beq 0x201d4c <_Z17ZDecompressStreamR7CStreamS0_+0x190> */
/* @0x201c98 str r7, [sp, #0xc] */
/* @0x201c9c mov r0, r11 */
/* @0x201ca0 mov r1, #0 */
/* @0x201ca4 str r10, [r4, #0x10] */
/* @0x201ca8 str r8, [r4, #0xc] */
/* @0x201cac bl 0xb69dc <inflate@plt> */
/* @0x201cb0 mov r4, r11 */
/* @0x201cb4 cmn r0, #4 */
/* @0x201cb8 mov r5, r0 */
/* @0x201cbc blt 0x201d00 <_Z17ZDecompressStreamR7CStreamS0_+0x144> */
/* @0x201cc0 cmn r0, #3 */
/* @0x201cc4 ble 0x201cd4 <_Z17ZDecompressStreamR7CStreamS0_+0x118> */
/* @0x201cc8 cmp r0, #2 */
/* @0x201ccc bne 0x201d00 <_Z17ZDecompressStreamR7CStreamS0_+0x144> */
/* @0x201cd0 mvn r5, #2 */
/* @0x201cd4 mov r0, r11 */
/* @0x201cd8 bl 0xb69e8 <inflateEnd@plt> */
/* @0x201cdc mov r0, r5 */
/* @0x201ce0 add r3, sp, #32768 */
/* @0x201ce4 ldr r2, [r3, #0x44] */
/* @0x201ce8 ldr r3, [r6] */
/* @0x201cec cmp r2, r3 */
/* @0x201cf0 bne 0x201d74 <_Z17ZDecompressStreamR7CStreamS0_+0x1b8> */
/* @0x201cf4 add sp, sp, #32768 */
/* @0x201cf8 add sp, sp, #76 */
/* @0x201cfc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x201d00 ldr r3, [r11, #0x10] */
/* @0x201d04 mov r1, r8 */
/* @0x201d08 ldr r0, [sp, #0x4] */
/* @0x201d0c rsb r3, r3, #16384 */
/* @0x201d10 str r3, [sp] */
/* @0x201d14 mov r2, r3 */
/* @0x201d18 bl 0x2014c8 <_ZN7CStream5WriteEPvi> */
/* @0x201d1c ldr r3, [sp] */
/* @0x201d20 cmp r3, r0 */
/* @0x201d24 bne 0x201d64 <_Z17ZDecompressStreamR7CStreamS0_+0x1a8> */
/* @0x201d28 ldr r3, [r11, #0x10] */
/* @0x201d2c cmp r3, #0 */
/* @0x201d30 beq 0x201c9c <_Z17ZDecompressStreamR7CStreamS0_+0xe0> */
/* @0x201d34 cmp r5, #1 */
/* @0x201d38 bne 0x201c5c <_Z17ZDecompressStreamR7CStreamS0_+0xa0> */
/* @0x201d3c mov r0, r11 */
/* @0x201d40 bl 0xb69e8 <inflateEnd@plt> */
/* @0x201d44 mov r0, #0 */
/* @0x201d48 b 0x201ce0 <_Z17ZDecompressStreamR7CStreamS0_+0x124> */
/* @0x201d4c mov r0, r4 */
/* @0x201d50 bl 0xb69e8 <inflateEnd@plt> */
/* @0x201d54 cmp r5, #1 */
/* @0x201d58 mvnne r0, #2 */
/* @0x201d5c moveq r0, #0 */
/* @0x201d60 b 0x201ce0 <_Z17ZDecompressStreamR7CStreamS0_+0x124> */
/* @0x201d64 mov r0, r11 */
/* @0x201d68 bl 0xb69e8 <inflateEnd@plt> */
/* @0x201d6c mvn r0, #0 */
/* @0x201d70 b 0x201ce0 <_Z17ZDecompressStreamR7CStreamS0_+0x124> */
/* @0x201d74 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x201d78 andseq r11, lr, r12, ror sp */
/* @0x201d7c mulseq lr, r8, r7 */
/* @0x201d80 andseq pc, r4, r8, lsl r4 */
/* @0x201d84 andseq pc, lr, r0, ror #14 */

/* ── FUNC 0x201d88 · CStream::SkipCompressedStream() · size=40 · insn=10 */
/* @0x201d88 push {r3, r4, r5, lr} */
/* @0x201d8c mov r4, r0 */
/* @0x201d90 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x201d94 mov r5, r0 */
/* @0x201d98 mov r0, r4 */
/* @0x201d9c bl 0x201160 <_ZN7CStream11GetPositionEv> */
/* @0x201da0 add r1, r0, r5 */
/* @0x201da4 mov r0, r4 */
/* @0x201da8 pop {r3, r4, r5, lr} */
/* @0x201dac b 0x201148 <_ZN7CStream11SetPositionEi> */

/* ── FUNC 0x201db0 · CStream::ReadCompressedStream() · size=236 · insn=59 */
/* @0x201db0 push {r4, r5, r6, r7, lr} */
/* @0x201db4 mov r5, r0 */
/* @0x201db8 sub sp, sp, #12 */
/* @0x201dbc mov r0, #32 */
/* @0x201dc0 bl 0x27c524 <_Znwj> */
/* @0x201dc4 mov r1, #0 */
/* @0x201dc8 mov r6, r0 */
/* @0x201dcc bl 0x2010ec <_ZN7CStreamC2Ei> */
/* @0x201dd0 mov r0, #32 */
/* @0x201dd4 bl 0x27c524 <_Znwj> */
/* @0x201dd8 mov r1, #0 */
/* @0x201ddc mov r4, r0 */
/* @0x201de0 bl 0x2010ec <_ZN7CStreamC2Ei> */
/* @0x201de4 mov r0, r5 */
/* @0x201de8 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x201dec mov r12, #1 */
/* @0x201df0 mov r1, r5 */
/* @0x201df4 str r12, [sp] */
/* @0x201df8 mov r7, r0 */
/* @0x201dfc mov r0, r4 */
/* @0x201e00 mov r2, r7 */
/* @0x201e04 asr r3, r7, #31 */
/* @0x201e08 bl 0x2015c8 <_ZN7CStream8CopyFromEPS_xb> */
/* @0x201e0c mov r0, r4 */
/* @0x201e10 mov r1, #0 */
/* @0x201e14 bl 0x201148 <_ZN7CStream11SetPositionEi> */
/* @0x201e18 ldr r3, [pc, #0x70] */
/* @0x201e1c ldr r1, [pc, #0x70] */
/* @0x201e20 mov r2, r7 */
/* @0x201e24 ldr r3, [pc, r3] */
/* @0x201e28 add r1, pc, r1 */
/* @0x201e2c ldr r5, [r3] */
/* @0x201e30 ldr r3, [r5] */
/* @0x201e34 mov r0, r5 */
/* @0x201e38 ldr r3, [r3, #0xc] */
/* @0x201e3c blx r3 */
/* @0x201e40 mov r0, r4 */
/* @0x201e44 mov r1, r6 */
/* @0x201e48 bl 0x201bbc <_Z17ZDecompressStreamR7CStreamS0_> */
/* @0x201e4c subs r7, r0, #0 */
/* @0x201e50 movne r0, #0 */
/* @0x201e54 bne 0x201e88 <_ZN7CStream20ReadCompressedStreamEv+0xd8> */
/* @0x201e58 ldr r3, [r5] */
/* @0x201e5c mov r0, r5 */
/* @0x201e60 ldr r1, [pc, #0x30] */
/* @0x201e64 ldr r3, [r3, #0xc] */
/* @0x201e68 add r1, pc, r1 */
/* @0x201e6c blx r3 */
/* @0x201e70 mov r0, r4 */
/* @0x201e74 bl 0x20133c <_ZN7CStream4FreeEv> */
/* @0x201e78 mov r0, r6 */
/* @0x201e7c mov r1, r7 */
/* @0x201e80 bl 0x201148 <_ZN7CStream11SetPositionEi> */
/* @0x201e84 mov r0, r6 */
/* @0x201e88 add sp, sp, #12 */
/* @0x201e8c pop {r4, r5, r6, r7, pc} */
/* @0x201e90 ldrsheq r11, [lr], -r0 */
/* @0x201e94 andseq r1, r5, r12, lsr r9 */
/* @0x201e98 andseq r1, r5, r4, lsl r9 */

/* ── FUNC 0x201e9c · CStream::ReadBitmap() · size=76 · insn=19 */
/* @0x201e9c push {r3, r4, r5, lr} */
/* @0x201ea0 mov r5, r0 */
/* @0x201ea4 bl 0x2019b0 <_ZN7CStream11ReadBooleanEv> */
/* @0x201ea8 cmp r0, #0 */
/* @0x201eac popeq {r3, r4, r5, pc} */
/* @0x201eb0 bl 0x1a912c <_ZN7IBitmap6CreateEv> */
/* @0x201eb4 mov r4, r0 */
/* @0x201eb8 mov r0, r5 */
/* @0x201ebc bl 0x201db0 <_ZN7CStream20ReadCompressedStreamEv> */
/* @0x201ec0 ldr r3, [r4] */
/* @0x201ec4 ldr r3, [r3, #0x8] */
/* @0x201ec8 mov r5, r0 */
/* @0x201ecc mov r0, r4 */
/* @0x201ed0 mov r1, r5 */
/* @0x201ed4 blx r3 */
/* @0x201ed8 mov r0, r5 */
/* @0x201edc bl 0x20133c <_ZN7CStream4FreeEv> */
/* @0x201ee0 mov r0, r4 */
/* @0x201ee4 pop {r3, r4, r5, pc} */

/* ── FUNC 0x201ee8 · CStream::ReadEncryptedStream() · size=420 · insn=105 */
/* @0x201ee8 push {r4, r5, r6, r7, r8, lr} */
/* @0x201eec sub sp, sp, #520 */
/* @0x201ef0 ldr r5, [pc, #0x190] */
/* @0x201ef4 mov r7, r0 */
/* @0x201ef8 ldr r5, [pc, r5] */
/* @0x201efc ldr r3, [r5] */
/* @0x201f00 str r3, [sp, #0x204] */
/* @0x201f04 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x201f08 mov r6, r0 */
/* @0x201f0c mov r0, r7 */
/* @0x201f10 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x201f14 cmp r6, #0 */
/* @0x201f18 movgt r4, #1 */
/* @0x201f1c mov r8, r0 */
/* @0x201f20 ble 0x201f38 <_ZN7CStream19ReadEncryptedStreamEv+0x50> */
/* @0x201f24 add r4, r4, #1 */
/* @0x201f28 mov r0, r7 */
/* @0x201f2c bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x201f30 cmp r6, r4 */
/* @0x201f34 bge 0x201f24 <_ZN7CStream19ReadEncryptedStreamEv+0x3c> */
/* @0x201f38 add r4, sp, #4 */
/* @0x201f3c mov r0, r7 */
/* @0x201f40 mov r2, #256 */
/* @0x201f44 mov r1, r4 */
/* @0x201f48 bl 0x20172c <_ZN7CStream4ReadEPvi> */
/* @0x201f4c cmp r8, #0 */
/* @0x201f50 movgt r6, #1 */
/* @0x201f54 ble 0x201f6c <_ZN7CStream19ReadEncryptedStreamEv+0x84> */
/* @0x201f58 add r6, r6, #1 */
/* @0x201f5c mov r0, r7 */
/* @0x201f60 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x201f64 cmp r8, r6 */
/* @0x201f68 bge 0x201f58 <_ZN7CStream19ReadEncryptedStreamEv+0x70> */
/* @0x201f6c mov r3, #0 */
/* @0x201f70 ldrb r2, [r4, r3] */
/* @0x201f74 add r1, sp, #520 */
/* @0x201f78 add r2, r1, r2 */
/* @0x201f7c strb r3, [r2, #-0x104] */
/* @0x201f80 add r3, r3, #1 */
/* @0x201f84 cmp r3, #256 */
/* @0x201f88 bne 0x201f70 <_ZN7CStream19ReadEncryptedStreamEv+0x88> */
/* @0x201f8c mov r0, r7 */
/* @0x201f90 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x201f94 mov r6, r0 */
/* @0x201f98 mov r0, #32 */
/* @0x201f9c bl 0x27c524 <_Znwj> */
/* @0x201fa0 mov r1, #0 */
/* @0x201fa4 mov r4, r0 */
/* @0x201fa8 bl 0x2010ec <_ZN7CStreamC2Ei> */
/* @0x201fac asr r3, r6, #31 */
/* @0x201fb0 mov r2, r6 */
/* @0x201fb4 mov r0, r4 */
/* @0x201fb8 mov r1, r7 */
/* @0x201fbc bl 0x20170c <_ZN7CStream8CopyFromEPS_x> */
/* @0x201fc0 mov r0, r4 */
/* @0x201fc4 bl 0x201158 <_ZN7CStream9GetMemoryEv> */
/* @0x201fc8 sub r3, r6, #1 */
/* @0x201fcc cmp r3, #0 */
/* @0x201fd0 ble 0x202078 <_ZN7CStream19ReadEncryptedStreamEv+0x190> */
/* @0x201fd4 add r6, r0, r6 */
/* @0x201fd8 mov r1, r3 */
/* @0x201fdc mov r2, r6 */
/* @0x201fe0 ldrb lr, [r2, #-0x1] */
/* @0x201fe4 add r7, sp, #520 */
/* @0x201fe8 ldrb r12, [r2, #-0x2] */
/* @0x201fec add lr, r7, lr */
/* @0x201ff0 ldrb lr, [lr, #-0x104] */
/* @0x201ff4 rsb lr, r12, lr */
/* @0x201ff8 rsb lr, r1, lr */
/* @0x201ffc asr r12, lr, #31 */
/* @0x202000 lsr r12, r12, #24 */
/* @0x202004 add lr, lr, r12 */
/* @0x202008 uxtb lr, lr */
/* @0x20200c subs r12, lr, r12 */
/* @0x202010 addmi r12, r12, #256 */
/* @0x202014 subs r1, r1, #1 */
/* @0x202018 strb r12, [r2, #-0x1]! */
/* @0x20201c bne 0x201fe0 <_ZN7CStream19ReadEncryptedStreamEv+0xf8> */
/* @0x202020 mov r1, r6 */
/* @0x202024 add r12, sp, #520 */
/* @0x202028 uxtab r2, r12, r3 */
/* @0x20202c ldrb r12, [r1, #-0x1] */
/* @0x202030 ldrb r2, [r2, #-0x204] */
/* @0x202034 rsb r2, r2, r3 */
/* @0x202038 subs r3, r3, #1 */
/* @0x20203c bic r2, r2, r2, asr #31 */
/* @0x202040 ldrb lr, [r0, r2] */
/* @0x202044 strb lr, [r1, #-0x1]! */
/* @0x202048 strb r12, [r0, r2] */
/* @0x20204c bpl 0x202024 <_ZN7CStream19ReadEncryptedStreamEv+0x13c> */
/* @0x202050 mov r0, r4 */
/* @0x202054 mov r1, #0 */
/* @0x202058 bl 0x201148 <_ZN7CStream11SetPositionEi> */
/* @0x20205c ldr r2, [sp, #0x204] */
/* @0x202060 ldr r3, [r5] */
/* @0x202064 mov r0, r4 */
/* @0x202068 cmp r2, r3 */
/* @0x20206c bne 0x202084 <_ZN7CStream19ReadEncryptedStreamEv+0x19c> */
/* @0x202070 add sp, sp, #520 */
/* @0x202074 pop {r4, r5, r6, r7, r8, pc} */
/* @0x202078 addeq r6, r0, r6 */
/* @0x20207c bne 0x202050 <_ZN7CStream19ReadEncryptedStreamEv+0x168> */
/* @0x202080 b 0x202020 <_ZN7CStream19ReadEncryptedStreamEv+0x138> */
/* @0x202084 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x202088 andseq r11, lr, r8, asr r10 */

/* ── FUNC 0x20208c · ZCompressStream(CStream&, CStream&, int) · size=368 · insn=92 */
/* @0x20208c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x202090 sub sp, sp, #32768 */
/* @0x202094 ldr r6, [pc, #0x158] */
/* @0x202098 sub sp, sp, #84 */
/* @0x20209c add r12, sp, #20 */
/* @0x2020a0 mov r8, r1 */
/* @0x2020a4 ldr r6, [pc, r6] */
/* @0x2020a8 mov r1, r2 */
/* @0x2020ac ldr r2, [pc, #0x144] */
/* @0x2020b0 mov r3, #56 */
/* @0x2020b4 ldr r5, [r6] */
/* @0x2020b8 mov lr, #0 */
/* @0x2020bc str r6, [sp] */
/* @0x2020c0 add r6, sp, #32768 */
/* @0x2020c4 str r0, [sp, #0x8] */
/* @0x2020c8 add r2, pc, r2 */
/* @0x2020cc mov r0, r12 */
/* @0x2020d0 mov r4, r12 */
/* @0x2020d4 str lr, [sp, #0x34] */
/* @0x2020d8 str r5, [r6, #0x4c] */
/* @0x2020dc str lr, [sp, #0x38] */
/* @0x2020e0 str lr, [sp, #0x3c] */
/* @0x2020e4 bl 0xb69a0 <deflateInit_@plt> */
/* @0x2020e8 cmp r0, #0 */
/* @0x2020ec bne 0x2021b4 <_Z15ZCompressStreamR7CStreamS0_i+0x128> */
/* @0x2020f0 add r6, sp, #76 */
/* @0x2020f4 str r6, [sp, #0x4] */
/* @0x2020f8 add r6, sp, #16384 */
/* @0x2020fc mov r9, #16384 */
/* @0x202100 add r6, r6, #76 */
/* @0x202104 mov r5, r4 */
/* @0x202108 movw r3, #0x7fc4 */
/* @0x20210c movt r3, #0xffff */
/* @0x202110 str r3, [sp, #0xc] */
/* @0x202114 add r1, sp, #76 */
/* @0x202118 mov r2, #16384 */
/* @0x20211c ldr r0, [sp, #0x8] */
/* @0x202120 bl 0x20172c <_ZN7CStream4ReadEPvi> */
/* @0x202124 str r0, [r4, #0x4] */
/* @0x202128 ldr r0, [sp, #0x8] */
/* @0x20212c bl 0x201160 <_ZN7CStream11GetPositionEv> */
/* @0x202130 mov r7, r0 */
/* @0x202134 ldr r0, [sp, #0x8] */
/* @0x202138 bl 0x201168 <_ZN7CStream7GetSizeEv> */
/* @0x20213c add r1, sp, #32768 */
/* @0x202140 ldr r3, [sp, #0xc] */
/* @0x202144 add r1, r1, #80 */
/* @0x202148 add r2, sp, #76 */
/* @0x20214c str r2, [r1, r3] */
/* @0x202150 cmp r7, r0 */
/* @0x202154 movge r7, #4 */
/* @0x202158 movlt r7, #0 */
/* @0x20215c b 0x20216c <_Z15ZCompressStreamR7CStreamS0_i+0xe0> */
/* @0x202160 ldr r3, [r10] */
/* @0x202164 cmp r3, #0 */
/* @0x202168 bne 0x2021d8 <_Z15ZCompressStreamR7CStreamS0_i+0x14c> */
/* @0x20216c mov r10, r4 */
/* @0x202170 mov r1, r7 */
/* @0x202174 mov r0, r5 */
/* @0x202178 str r9, [r4, #0x10] */
/* @0x20217c str r6, [r4, #0xc] */
/* @0x202180 bl 0xb69ac <deflate@plt> */
/* @0x202184 ldr r11, [r10, #0x10]! */
/* @0x202188 mov r0, r8 */
/* @0x20218c mov r1, r6 */
/* @0x202190 mov r4, r5 */
/* @0x202194 rsb r11, r11, #16384 */
/* @0x202198 mov r2, r11 */
/* @0x20219c bl 0x2014c8 <_ZN7CStream5WriteEPvi> */
/* @0x2021a0 cmp r11, r0 */
/* @0x2021a4 beq 0x202160 <_Z15ZCompressStreamR7CStreamS0_i+0xd4> */
/* @0x2021a8 mov r0, r5 */
/* @0x2021ac bl 0xb69b8 <deflateEnd@plt> */
/* @0x2021b0 mvn r0, #0 */
/* @0x2021b4 ldr r6, [sp] */
/* @0x2021b8 add r3, sp, #32768 */
/* @0x2021bc ldr r2, [r3, #0x4c] */
/* @0x2021c0 ldr r3, [r6] */
/* @0x2021c4 cmp r2, r3 */
/* @0x2021c8 bne 0x2021f0 <_Z15ZCompressStreamR7CStreamS0_i+0x164> */
/* @0x2021cc add sp, sp, #32768 */
/* @0x2021d0 add sp, sp, #84 */
/* @0x2021d4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2021d8 cmp r7, #4 */
/* @0x2021dc bne 0x202114 <_Z15ZCompressStreamR7CStreamS0_i+0x88> */
/* @0x2021e0 mov r0, r5 */
/* @0x2021e4 bl 0xb69b8 <deflateEnd@plt> */
/* @0x2021e8 mov r0, #0 */
/* @0x2021ec b 0x2021b4 <_Z15ZCompressStreamR7CStreamS0_i+0x128> */
/* @0x2021f0 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x2021f4 andseq r11, lr, r12, lsr #17 */
/* @0x2021f8 andseq lr, r4, r8, asr pc */

/* ── FUNC 0x2021fc · CStream::WriteCompressedStream(CStream*) · size=152 · insn=38 */
/* @0x2021fc push {r4, r5, r6, r7, r8, lr} */
/* @0x202200 mov r6, r0 */
/* @0x202204 mov r0, r1 */
/* @0x202208 mov r5, r1 */
/* @0x20220c bl 0x201160 <_ZN7CStream11GetPositionEv> */
/* @0x202210 mov r1, #0 */
/* @0x202214 mov r8, r0 */
/* @0x202218 mov r0, r5 */
/* @0x20221c bl 0x201148 <_ZN7CStream11SetPositionEi> */
/* @0x202220 mov r0, #32 */
/* @0x202224 bl 0x27c524 <_Znwj> */
/* @0x202228 mov r1, #0 */
/* @0x20222c mov r4, r0 */
/* @0x202230 bl 0x2010ec <_ZN7CStreamC2Ei> */
/* @0x202234 mvn r2, #0 */
/* @0x202238 mov r1, r4 */
/* @0x20223c mov r0, r5 */
/* @0x202240 bl 0x20208c <_Z15ZCompressStreamR7CStreamS0_i> */
/* @0x202244 mov r0, r4 */
/* @0x202248 mov r1, #0 */
/* @0x20224c bl 0x201148 <_ZN7CStream11SetPositionEi> */
/* @0x202250 mov r0, r4 */
/* @0x202254 bl 0x201168 <_ZN7CStream7GetSizeEv> */
/* @0x202258 mov r7, r0 */
/* @0x20225c mov r0, r6 */
/* @0x202260 mov r1, r7 */
/* @0x202264 bl 0x201a10 <_ZN7CStream12WriteIntegerEi> */
/* @0x202268 mov r2, r7 */
/* @0x20226c asr r3, r7, #31 */
/* @0x202270 mov r0, r6 */
/* @0x202274 mov r1, r4 */
/* @0x202278 bl 0x20170c <_ZN7CStream8CopyFromEPS_x> */
/* @0x20227c mov r0, r4 */
/* @0x202280 bl 0x20133c <_ZN7CStream4FreeEv> */
/* @0x202284 mov r0, r5 */
/* @0x202288 mov r1, r8 */
/* @0x20228c pop {r4, r5, r6, r7, r8, lr} */
/* @0x202290 b 0x201148 <_ZN7CStream11SetPositionEi> */

/* ── FUNC 0x202294 · SetKey(int) · size=236 · insn=59 */
/* @0x202294 movw r3, #0x4dd3 */
/* @0x202298 movt r3, #0x1062 */
/* @0x20229c mov r1, #250 */
/* @0x2022a0 smull r2, r3, r3, r0 */
/* @0x2022a4 asr r2, r0, #31 */
/* @0x2022a8 push {r4, r5, r6, r7, r8} */
/* @0x2022ac rsb r3, r2, r3, asr #4 */
/* @0x2022b0 mls r3, r1, r3, r0 */
/* @0x2022b4 ldr r1, [pc, #0xbc] */
/* @0x2022b8 ldr r1, [pc, r1] */
/* @0x2022bc adds r7, r3, #6 */
/* @0x2022c0 addmi r7, r3, #260 */
/* @0x2022c4 movw r3, #0x4dd3 */
/* @0x2022c8 movt r3, #0x1062 */
/* @0x2022cc addmi r7, r7, #2 */
/* @0x2022d0 smull r12, r0, r3, r0 */
/* @0x2022d4 rsbs r3, r2, r0, asr #4 */
/* @0x2022d8 mov r2, #0 */
/* @0x2022dc addmi r3, r3, #256 */
/* @0x2022e0 strb r2, [r1, r2] */
/* @0x2022e4 add r2, r2, #1 */
/* @0x2022e8 cmp r2, #256 */
/* @0x2022ec bne 0x2022e0 <_Z6SetKeyi+0x4c> */
/* @0x2022f0 ldr r4, [pc, #0x84] */
/* @0x2022f4 mov r2, #0 */
/* @0x2022f8 ldr r4, [pc, r4] */
/* @0x2022fc strb r2, [r4, r2] */
/* @0x202300 add r2, r2, #1 */
/* @0x202304 cmp r2, #256 */
/* @0x202308 bne 0x2022fc <_Z6SetKeyi+0x68> */
/* @0x20230c movw r8, #0x409 */
/* @0x202310 add r3, r7, r3 */
/* @0x202314 movt r8, #0x8102 */
/* @0x202318 movw r0, #0x2710 */
/* @0x20231c smull r12, r2, r8, r3 */
/* @0x202320 asr r12, r3, #31 */
/* @0x202324 subs r0, r0, #1 */
/* @0x202328 add r2, r2, r3 */
/* @0x20232c rsb r2, r12, r2, asr #7 */
/* @0x202330 rsb r2, r2, r2, lsl #7 */
/* @0x202334 sub r2, r3, r2, lsl #1 */
/* @0x202338 add r3, r3, r7 */
/* @0x20233c add r12, r2, #1 */
/* @0x202340 add r2, r2, #2 */
/* @0x202344 ldrb r5, [r1, r12] */
/* @0x202348 ldrb r6, [r1, r2] */
/* @0x20234c strb r6, [r1, r12] */
/* @0x202350 strb r5, [r1, r2] */
/* @0x202354 bne 0x20231c <_Z6SetKeyi+0x88> */
/* @0x202358 mov r3, #1 */
/* @0x20235c ldrb r2, [r1, #0x1]! */
/* @0x202360 strb r3, [r4, r2] */
/* @0x202364 add r3, r3, #1 */
/* @0x202368 cmp r3, #256 */
/* @0x20236c bne 0x20235c <_Z6SetKeyi+0xc8> */
/* @0x202370 pop {r4, r5, r6, r7, r8} */
/* @0x202374 bx lr */
/* @0x202378 andseq pc, lr, r4, asr #1 */
/* @0x20237c andseq pc, lr, r8, lsl #1 */

/* ── FUNC 0x202380 · CStream::Decrypt(int, int, int) · size=112 · insn=28 */
/* @0x202380 push {r4, r5, r6, lr} */
/* @0x202384 mov r6, r0 */
/* @0x202388 mov r0, r1 */
/* @0x20238c mov r5, r3 */
/* @0x202390 mov r4, r2 */
/* @0x202394 bl 0x202294 <_Z6SetKeyi> */
/* @0x202398 cmp r5, #0 */
/* @0x20239c ble 0x2023dc <_ZN7CStream7DecryptEiii+0x5c> */
/* @0x2023a0 mov r0, r6 */
/* @0x2023a4 add r5, r4, r5 */
/* @0x2023a8 bl 0x201158 <_ZN7CStream9GetMemoryEv> */
/* @0x2023ac cmp r4, r5 */
/* @0x2023b0 popge {r4, r5, r6, pc} */
/* @0x2023b4 ldr r1, [pc, #0x30] */
/* @0x2023b8 add r2, r0, r4 */
/* @0x2023bc add r0, r0, r5 */
/* @0x2023c0 ldr r1, [pc, r1] */
/* @0x2023c4 ldrb r3, [r2] */
/* @0x2023c8 ldrb r3, [r1, r3] */
/* @0x2023cc strb r3, [r2], #1 */
/* @0x2023d0 cmp r2, r0 */
/* @0x2023d4 bne 0x2023c4 <_ZN7CStream7DecryptEiii+0x44> */
/* @0x2023d8 pop {r4, r5, r6, pc} */
/* @0x2023dc mov r0, r6 */
/* @0x2023e0 bl 0x201168 <_ZN7CStream7GetSizeEv> */
/* @0x2023e4 rsb r5, r4, r0 */
/* @0x2023e8 b 0x2023a0 <_ZN7CStream7DecryptEiii+0x20> */
/* @0x2023ec andseq lr, lr, r0, asr #31 */

/* ── FUNC 0x2023f0 · CStream::Decrypt2(int, int, int) · size=144 · insn=36 */
/* @0x2023f0 push {r4, r5, r6, r7, r8, lr} */
/* @0x2023f4 mov r6, r0 */
/* @0x2023f8 mov r0, r1 */
/* @0x2023fc mov r8, r3 */
/* @0x202400 mov r4, r2 */
/* @0x202404 bl 0x202294 <_Z6SetKeyi> */
/* @0x202408 cmp r8, #0 */
/* @0x20240c ble 0x20246c <_ZN7CStream8Decrypt2Eiii+0x7c> */
/* @0x202410 add r8, r4, r8 */
/* @0x202414 cmp r4, r8 */
/* @0x202418 popge {r4, r5, r6, r7, r8, pc} */
/* @0x20241c ldr r7, [pc, #0x58] */
/* @0x202420 ldr r7, [pc, r7] */
/* @0x202424 mov r0, r6 */
/* @0x202428 bl 0x201158 <_ZN7CStream9GetMemoryEv> */
/* @0x20242c asr r1, r4, #31 */
/* @0x202430 lsr r1, r1, #24 */
/* @0x202434 add r2, r4, r1 */
/* @0x202438 uxtb r2, r2 */
/* @0x20243c rsb r2, r1, r2 */
/* @0x202440 ldrb r3, [r0, r4] */
/* @0x202444 mov r0, r6 */
/* @0x202448 ldrb r1, [r7, r3] */
/* @0x20244c subs r5, r1, r2 */
/* @0x202450 addmi r5, r5, #256 */
/* @0x202454 bl 0x201158 <_ZN7CStream9GetMemoryEv> */
/* @0x202458 strb r5, [r0, r4] */
/* @0x20245c add r4, r4, #1 */
/* @0x202460 cmp r4, r8 */
/* @0x202464 bne 0x202424 <_ZN7CStream8Decrypt2Eiii+0x34> */
/* @0x202468 pop {r4, r5, r6, r7, r8, pc} */
/* @0x20246c mov r0, r6 */
/* @0x202470 bl 0x201168 <_ZN7CStream7GetSizeEv> */
/* @0x202474 rsb r8, r4, r0 */
/* @0x202478 b 0x202410 <_ZN7CStream8Decrypt2Eiii+0x20> */
/* @0x20247c andseq lr, lr, r0, ror #30 */

/* ── FUNC 0x202480 · CStream::WriteStream(CStream*) · size=4 · insn=1 */
/* @0x202480 bx lr */

/* ── FUNC 0x202484 · CStream::WriteBitmap(IBitmap*) · size=4 · insn=1 */
/* @0x202484 bx lr */

/* ── FUNC 0x202488 · CStream::Encrypt(int, int, int) · size=4 · insn=1 */
/* @0x202488 bx lr */

/* ── FUNC 0x20248c · CStream::Encrypt2(int, int, int) · size=4 · insn=1 */
/* @0x20248c bx lr */

/* ── FUNC 0x202490 · CStream::CheckSum() · size=8 · insn=2 */
/* @0x202490 mov r0, #0 */
/* @0x202494 bx lr */

/* ── FUNC 0x202498 · IntToHex(int) · size=24 · insn=6 */
/* @0x202498 ldr r3, [pc, #0xc] */
/* @0x20249c and r0, r0, #15 */
/* @0x2024a0 add r3, pc, r3 */
/* @0x2024a4 ldrb r0, [r3, r0] */
/* @0x2024a8 bx lr */
/* @0x2024ac ldrsheq r1, [r5], -r4 */

/* ── FUNC 0x2024b0 · CStream::ConvertToString(char const*&) · size=188 · insn=47 */
/* @0x2024b0 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2024b4 mov r8, r1 */
/* @0x2024b8 ldrd r2, r3, [r0, #16] */
/* @0x2024bc mov r1, #0 */
/* @0x2024c0 str r1, [r8] */
/* @0x2024c4 mov r10, r0 */
/* @0x2024c8 cmp r2, #1 */
/* @0x2024cc sbcs r1, r3, #0 */
/* @0x2024d0 poplt {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2024d4 ldr r1, [pc, #0x8c] */
/* @0x2024d8 lsl r0, r2, #1 */
/* @0x2024dc mov r3, #1 */
/* @0x2024e0 movw r2, #0x50c */
/* @0x2024e4 add r1, pc, r1 */
/* @0x2024e8 add r0, r0, #1 */
/* @0x2024ec bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x2024f0 ldrd r2, r3, [r10, #16] */
/* @0x2024f4 cmp r2, #1 */
/* @0x2024f8 sbcs r1, r3, #0 */
/* @0x2024fc mov r9, r0 */
/* @0x202500 blt 0x202558 <_ZN7CStream15ConvertToStringERPKc+0xa8> */
/* @0x202504 mov r4, #1 */
/* @0x202508 mov r5, #0 */
/* @0x20250c mov r11, r0 */
/* @0x202510 ldr r3, [r10, #0x18] */
/* @0x202514 mov r7, r5 */
/* @0x202518 add r11, r11, #2 */
/* @0x20251c add r3, r3, r4 */
/* @0x202520 ldrb r6, [r3, #-0x1] */
/* @0x202524 lsr r0, r6, #4 */
/* @0x202528 bl 0x202498 <_Z8IntToHexi> */
/* @0x20252c strb r0, [r11, #-0x2] */
/* @0x202530 and r0, r6, #15 */
/* @0x202534 bl 0x202498 <_Z8IntToHexi> */
/* @0x202538 mov r6, r4 */
/* @0x20253c adds r4, r4, #1 */
/* @0x202540 adc r5, r5, #0 */
/* @0x202544 strb r0, [r11, #-0x1] */
/* @0x202548 ldrd r2, r3, [r10, #16] */
/* @0x20254c cmp r6, r2 */
/* @0x202550 sbcs r1, r7, r3 */
/* @0x202554 blt 0x202510 <_ZN7CStream15ConvertToStringERPKc+0x60> */
/* @0x202558 mov r3, #0 */
/* @0x20255c strb r3, [r9, r2, lsl #1] */
/* @0x202560 str r9, [r8] */
/* @0x202564 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x202568 andseq r1, r5, r4, asr #4 */

/* ── FUNC 0x20256c · Hex2Int(char) · size=20 · insn=5 */
/* @0x20256c ubfx r3, r0, #0x6, #0x1 */
/* @0x202570 and r0, r0, #15 */
/* @0x202574 add r0, r0, r3, lsl #3 */
/* @0x202578 add r0, r0, r3 */
/* @0x20257c bx lr */

/* ── FUNC 0x202580 · isHexdigit(char) · size=48 · insn=12 */
/* @0x202580 sub r2, r0, #65 */
/* @0x202584 sub r3, r0, #48 */
/* @0x202588 cmp r3, #9 */
/* @0x20258c cmphi r2, #5 */
/* @0x202590 bls 0x2025a8 <_Z10isHexdigitc+0x28> */
/* @0x202594 sub r0, r0, #97 */
/* @0x202598 cmp r0, #5 */
/* @0x20259c movhi r0, #0 */
/* @0x2025a0 movls r0, #1 */
/* @0x2025a4 bx lr */
/* @0x2025a8 mov r0, #1 */
/* @0x2025ac bx lr */

/* ── FUNC 0x2025b0 · CStream::ConvertFromString(char const*) · size=248 · insn=62 */
/* @0x2025b0 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2025b4 mov r8, r0 */
/* @0x2025b8 sub sp, sp, #8 */
/* @0x2025bc mov r0, r1 */
/* @0x2025c0 mov r6, r1 */
/* @0x2025c4 bl 0xb6538 <strlen@plt> */
/* @0x2025c8 subs r9, r0, #0 */
/* @0x2025cc beq 0x20269c <_ZN7CStream17ConvertFromStringEPKc+0xec> */
/* @0x2025d0 mov r4, #0 */
/* @0x2025d4 mov r5, r6 */
/* @0x2025d8 mov r7, r4 */
/* @0x2025dc b 0x2025f0 <_ZN7CStream17ConvertFromStringEPKc+0x40> */
/* @0x2025e0 add r4, r4, #2 */
/* @0x2025e4 add r5, r5, #2 */
/* @0x2025e8 cmp r9, r4 */
/* @0x2025ec bls 0x202620 <_ZN7CStream17ConvertFromStringEPKc+0x70> */
/* @0x2025f0 ldrb r0, [r6, r4] */
/* @0x2025f4 bl 0x202580 <_Z10isHexdigitc> */
/* @0x2025f8 cmp r0, #0 */
/* @0x2025fc beq 0x2025e0 <_ZN7CStream17ConvertFromStringEPKc+0x30> */
/* @0x202600 ldrb r0, [r5, #0x1] */
/* @0x202604 add r4, r4, #2 */
/* @0x202608 bl 0x202580 <_Z10isHexdigitc> */
/* @0x20260c add r5, r5, #2 */
/* @0x202610 cmp r0, #0 */
/* @0x202614 addne r7, r7, #2 */
/* @0x202618 cmp r9, r4 */
/* @0x20261c bhi 0x2025f0 <_ZN7CStream17ConvertFromStringEPKc+0x40> */
/* @0x202620 ldr r2, [pc, #0x7c] */
/* @0x202624 mov r4, #0 */
/* @0x202628 ldr r0, [r8, #0x18] */
/* @0x20262c asr r1, r7, #1 */
/* @0x202630 str r4, [r8, #0xc] */
/* @0x202634 add r2, pc, r2 */
/* @0x202638 str r1, [r8, #0x8] */
/* @0x20263c movw r3, #0x534 */
/* @0x202640 str r4, [sp] */
/* @0x202644 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x202648 cmp r7, r4 */
/* @0x20264c mov r2, #0 */
/* @0x202650 mov r3, #0 */
/* @0x202654 strd r2, r3, [r8, #16] */
/* @0x202658 mov r9, r0 */
/* @0x20265c str r0, [r8, #0x18] */
/* @0x202660 beq 0x20269c <_ZN7CStream17ConvertFromStringEPKc+0xec> */
/* @0x202664 mov r5, r6 */
/* @0x202668 b 0x202670 <_ZN7CStream17ConvertFromStringEPKc+0xc0> */
/* @0x20266c ldr r9, [r8, #0x18] */
/* @0x202670 ldrb r0, [r6, r4] */
/* @0x202674 add r5, r5, #2 */
/* @0x202678 bl 0x20256c <_Z7Hex2Intc> */
/* @0x20267c mov r10, r0 */
/* @0x202680 ldrb r0, [r5, #-0x1] */
/* @0x202684 bl 0x20256c <_Z7Hex2Intc> */
/* @0x202688 add r0, r0, r10, lsl #4 */
/* @0x20268c strb r0, [r9, r4, asr #1] */
/* @0x202690 add r4, r4, #2 */
/* @0x202694 cmp r4, r7 */
/* @0x202698 blt 0x20266c <_ZN7CStream17ConvertFromStringEPKc+0xbc> */
/* @0x20269c add sp, sp, #8 */
/* @0x2026a0 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2026a4 ldrsheq r1, [r5], -r4 */

/* ── FUNC 0x2026a8 · DS_SetPrecision(double) · size=28 · insn=7 */
/* @0x2026a8 vmov d6, r0, r1 */
/* @0x2026ac ldr r3, [pc, #0xc] */
/* @0x2026b0 vabs.f64 d7, d6 */
/* @0x2026b4 ldr r3, [pc, r3] */
/* @0x2026b8 vstr d7, [r3] */
/* @0x2026bc bx lr */
/* @0x2026c0 ldrsbeq lr, [lr], -r0 */

/* ── FUNC 0x2026c4 · YYCompareVal(RValue const&, RValue const&, double) · size=924 · insn=231 */
/* @0x2026c4 push {r4, r5, r6, lr} */
/* @0x2026c8 mov r6, r1 */
/* @0x2026cc ldr r1, [r0, #0xc] */
/* @0x2026d0 vmov d7, r2, r3 */
/* @0x2026d4 ldr r3, [r6, #0xc] */
/* @0x2026d8 bic r2, r1, #-16777216 */
/* @0x2026dc bic r3, r3, #-16777216 */
/* @0x2026e0 add r3, r3, r2, lsl #4 */
/* @0x2026e4 cmp r3, #119 */
/* @0x2026e8 beq 0x202a10 <_Z12YYCompareValRK6RValueS1_d+0x34c> */
/* @0x2026ec ble 0x202748 <_Z12YYCompareValRK6RValueS1_d+0x84> */
/* @0x2026f0 cmp r3, #170 */
/* @0x2026f4 beq 0x2029ec <_Z12YYCompareValRK6RValueS1_d+0x328> */
/* @0x2026f8 bgt 0x2027b4 <_Z12YYCompareValRK6RValueS1_d+0xf0> */
/* @0x2026fc cmp r3, #125 */
/* @0x202700 beq 0x202854 <_Z12YYCompareValRK6RValueS1_d+0x190> */
/* @0x202704 ble 0x202930 <_Z12YYCompareValRK6RValueS1_d+0x26c> */
/* @0x202708 cmp r3, #160 */
/* @0x20270c beq 0x2027c8 <_Z12YYCompareValRK6RValueS1_d+0x104> */
/* @0x202710 cmp r3, #167 */
/* @0x202714 bne 0x2029dc <_Z12YYCompareValRK6RValueS1_d+0x318> */
/* @0x202718 ldr r1, [r6] */
/* @0x20271c ldr r2, [r0] */
/* @0x202720 ldr r3, [r0, #0x4] */
/* @0x202724 subs r2, r2, r1 */
/* @0x202728 sbc r3, r3, r1, asr #31 */
/* @0x20272c orrs r1, r2, r3 */
/* @0x202730 beq 0x2028b4 <_Z12YYCompareValRK6RValueS1_d+0x1f0> */
/* @0x202734 cmp r2, #0 */
/* @0x202738 sbcs r1, r3, #0 */
/* @0x20273c mvnlt r0, #0 */
/* @0x202740 movge r0, #1 */
/* @0x202744 pop {r4, r5, r6, pc} */
/* @0x202748 cmp r3, #17 */
/* @0x20274c beq 0x20298c <_Z12YYCompareValRK6RValueS1_d+0x2c8> */
/* @0x202750 ble 0x20287c <_Z12YYCompareValRK6RValueS1_d+0x1b8> */
/* @0x202754 cmp r3, #51 */
/* @0x202758 beq 0x202838 <_Z12YYCompareValRK6RValueS1_d+0x174> */
/* @0x20275c ble 0x20290c <_Z12YYCompareValRK6RValueS1_d+0x248> */
/* @0x202760 cmp r3, #85 */
/* @0x202764 beq 0x2028b4 <_Z12YYCompareValRK6RValueS1_d+0x1f0> */
/* @0x202768 cmp r3, #112 */
/* @0x20276c bne 0x2029dc <_Z12YYCompareValRK6RValueS1_d+0x318> */
/* @0x202770 ldr r2, [r6] */
/* @0x202774 vldr s11, [r0] */
/* @0x202778 ldr r3, [r6, #0x4] */
/* @0x20277c vcvt.f32.s32 s11, s11 */
/* @0x202780 vmov d4, r2, r3 */
/* @0x202784 vcvt.f32.f64 s13, d4 */
/* @0x202788 vsub.f32 s11, s11, s13 */
/* @0x20278c vabs.f32 s12, s11 */
/* @0x202790 vcvt.f64.f32 d6, s12 */
/* @0x202794 vcmpe.f64 d6, d7 */
/* @0x202798 vmrs APSR_nzcv, fpscr */
/* @0x20279c bls 0x2028b4 <_Z12YYCompareValRK6RValueS1_d+0x1f0> */
/* @0x2027a0 vcmpe.f32 s11, #0 */
/* @0x2027a4 vmrs APSR_nzcv, fpscr */
/* @0x2027a8 mvnmi r0, #0 */
/* @0x2027ac movpl r0, #1 */
/* @0x2027b0 pop {r4, r5, r6, pc} */
/* @0x2027b4 cmp r3, #215 */
/* @0x2027b8 beq 0x202808 <_Z12YYCompareValRK6RValueS1_d+0x144> */
/* @0x2027bc bgt 0x2028bc <_Z12YYCompareValRK6RValueS1_d+0x1f8> */
/* @0x2027c0 cmp r3, #173 */
/* @0x2027c4 bne 0x2029d4 <_Z12YYCompareValRK6RValueS1_d+0x310> */
/* @0x2027c8 ldr r3, [r6, #0x4] */
/* @0x2027cc ldr r2, [r6] */
/* @0x2027d0 ldr r4, [r0] */
/* @0x2027d4 ldr r5, [r0, #0x4] */
/* @0x2027d8 mov r1, r3 */
/* @0x2027dc mov r0, r2 */
/* @0x2027e0 bl 0x3194a0 <__fixdfdi> */
/* @0x2027e4 subs r0, r4, r0 */
/* @0x2027e8 sbc r1, r5, r1 */
/* @0x2027ec orrs r3, r0, r1 */
/* @0x2027f0 beq 0x2028b4 <_Z12YYCompareValRK6RValueS1_d+0x1f0> */
/* @0x2027f4 cmp r0, #0 */
/* @0x2027f8 sbcs r3, r1, #0 */
/* @0x2027fc mvnlt r0, #0 */
/* @0x202800 movge r0, #1 */
/* @0x202804 pop {r4, r5, r6, pc} */
/* @0x202808 ldr r2, [r0] */
/* @0x20280c ldr r3, [r0, #0x4] */
/* @0x202810 ldr r1, [r6] */
/* @0x202814 vmov d4, r2, r3 */
/* @0x202818 vcvt.s32.f64 s9, d4 */
/* @0x20281c vmov r0, s9 */
/* @0x202820 rsb r0, r1, r0 */
/* @0x202824 cmp r0, #0 */
/* @0x202828 popeq {r4, r5, r6, pc} */
/* @0x20282c blt 0x20284c <_Z12YYCompareValRK6RValueS1_d+0x188> */
/* @0x202830 mov r0, #1 */
/* @0x202834 pop {r4, r5, r6, pc} */
/* @0x202838 ldr r2, [r0] */
/* @0x20283c ldr r3, [r6] */
/* @0x202840 cmp r2, r3 */
/* @0x202844 beq 0x2028b4 <_Z12YYCompareValRK6RValueS1_d+0x1f0> */
/* @0x202848 blo 0x202830 <_Z12YYCompareValRK6RValueS1_d+0x16c> */
/* @0x20284c mvn r0, #0 */
/* @0x202850 pop {r4, r5, r6, pc} */
/* @0x202854 ldr r2, [r6] */
/* @0x202858 ldr r3, [r6, #0x4] */
/* @0x20285c ldr r1, [r0] */
/* @0x202860 vmov d5, r2, r3 */
/* @0x202864 vcvt.s32.f64 s11, d5 */
/* @0x202868 vmov r0, s11 */
/* @0x20286c rsb r0, r0, r1 */
/* @0x202870 cmp r0, #0 */
/* @0x202874 bne 0x20282c <_Z12YYCompareValRK6RValueS1_d+0x168> */
/* @0x202878 pop {r4, r5, r6, pc} */
/* @0x20287c cmp r3, #7 */
/* @0x202880 beq 0x202958 <_Z12YYCompareValRK6RValueS1_d+0x294> */
/* @0x202884 ble 0x202a28 <_Z12YYCompareValRK6RValueS1_d+0x364> */
/* @0x202888 cmp r3, #10 */
/* @0x20288c bne 0x202a34 <_Z12YYCompareValRK6RValueS1_d+0x370> */
/* @0x202890 ldm r0, {r2, r3} */
/* @0x202894 mov r0, r2 */
/* @0x202898 mov r1, r3 */
/* @0x20289c bl 0x3194a0 <__fixdfdi> */
/* @0x2028a0 ldm r6, {r2, r3} */
/* @0x2028a4 subs r0, r0, r2 */
/* @0x2028a8 sbc r1, r1, r3 */
/* @0x2028ac orrs r3, r0, r1 */
/* @0x2028b0 bne 0x2027f4 <_Z12YYCompareValRK6RValueS1_d+0x130> */
/* @0x2028b4 mov r0, #0 */
/* @0x2028b8 pop {r4, r5, r6, pc} */
/* @0x2028bc cmp r3, #218 */
/* @0x2028c0 beq 0x202890 <_Z12YYCompareValRK6RValueS1_d+0x1cc> */
/* @0x2028c4 cmp r3, #221 */
/* @0x2028c8 bne 0x2029dc <_Z12YYCompareValRK6RValueS1_d+0x318> */
/* @0x2028cc ldr r4, [r0] */
/* @0x2028d0 ldr r2, [r6] */
/* @0x2028d4 ldr r5, [r0, #0x4] */
/* @0x2028d8 ldr r3, [r6, #0x4] */
/* @0x2028dc vmov d4, r4, r5 */
/* @0x2028e0 vmov d5, r2, r3 */
/* @0x2028e4 vsub.f64 d6, d4, d5 */
/* @0x2028e8 vabs.f64 d5, d6 */
/* @0x2028ec vcmpe.f64 d7, d5 */
/* @0x2028f0 vmrs APSR_nzcv, fpscr */
/* @0x2028f4 bge 0x2028b4 <_Z12YYCompareValRK6RValueS1_d+0x1f0> */
/* @0x2028f8 vcmpe.f64 d6, #0 */
/* @0x2028fc vmrs APSR_nzcv, fpscr */
/* @0x202900 mvnmi r0, #0 */
/* @0x202904 movpl r0, #1 */
/* @0x202908 pop {r4, r5, r6, pc} */
/* @0x20290c cmp r3, #34 */
/* @0x202910 bne 0x2029dc <_Z12YYCompareValRK6RValueS1_d+0x318> */
/* @0x202914 ldr r3, [r0] */
/* @0x202918 cmp r3, #0 */
/* @0x20291c beq 0x202830 <_Z12YYCompareValRK6RValueS1_d+0x16c> */
/* @0x202920 ldr r0, [r6] */
/* @0x202924 subs r0, r3, r0 */
/* @0x202928 movne r0, #1 */
/* @0x20292c pop {r4, r5, r6, pc} */
/* @0x202930 cmp r3, #122 */
/* @0x202934 bne 0x2029dc <_Z12YYCompareValRK6RValueS1_d+0x318> */
/* @0x202938 ldr r1, [r0] */
/* @0x20293c ldr r2, [r6] */
/* @0x202940 ldr r3, [r6, #0x4] */
/* @0x202944 rsbs r2, r2, r1 */
/* @0x202948 rsc r3, r3, r1, asr #31 */
/* @0x20294c orrs r1, r2, r3 */
/* @0x202950 bne 0x202734 <_Z12YYCompareValRK6RValueS1_d+0x70> */
/* @0x202954 b 0x2028b4 <_Z12YYCompareValRK6RValueS1_d+0x1f0> */
/* @0x202958 ldr r2, [r0] */
/* @0x20295c vldr s13, [r6] */
/* @0x202960 ldr r3, [r0, #0x4] */
/* @0x202964 vcvt.f32.s32 s13, s13 */
/* @0x202968 vmov d4, r2, r3 */
/* @0x20296c vcvt.f32.f64 s11, d4 */
/* @0x202970 vsub.f32 s11, s11, s13 */
/* @0x202974 vabs.f32 s12, s11 */
/* @0x202978 vcvt.f64.f32 d6, s12 */
/* @0x20297c vcmpe.f64 d7, d6 */
/* @0x202980 vmrs APSR_nzcv, fpscr */
/* @0x202984 blt 0x2027a0 <_Z12YYCompareValRK6RValueS1_d+0xdc> */
/* @0x202988 b 0x2028b4 <_Z12YYCompareValRK6RValueS1_d+0x1f0> */
/* @0x20298c ldr r3, [r0] */
/* @0x202990 cmp r3, #0 */
/* @0x202994 beq 0x202830 <_Z12YYCompareValRK6RValueS1_d+0x16c> */
/* @0x202998 ldr r2, [r6] */
/* @0x20299c cmp r2, #0 */
/* @0x2029a0 beq 0x202830 <_Z12YYCompareValRK6RValueS1_d+0x16c> */
/* @0x2029a4 ldr r0, [r3] */
/* @0x2029a8 cmp r0, #0 */
/* @0x2029ac beq 0x202a50 <_Z12YYCompareValRK6RValueS1_d+0x38c> */
/* @0x2029b0 ldr r1, [r2] */
/* @0x2029b4 cmp r1, #0 */
/* @0x2029b8 beq 0x202a40 <_Z12YYCompareValRK6RValueS1_d+0x37c> */
/* @0x2029bc bl 0xb6574 <strcmp@plt> */
/* @0x2029c0 cmp r0, #0 */
/* @0x2029c4 blt 0x20284c <_Z12YYCompareValRK6RValueS1_d+0x188> */
/* @0x2029c8 moveq r0, #0 */
/* @0x2029cc movne r0, #1 */
/* @0x2029d0 pop {r4, r5, r6, pc} */
/* @0x2029d4 cmp r3, #208 */
/* @0x2029d8 beq 0x2028cc <_Z12YYCompareValRK6RValueS1_d+0x208> */
/* @0x2029dc cmp r2, #0 */
/* @0x2029e0 mvneq r0, #0 */
/* @0x2029e4 movne r0, #1 */
/* @0x2029e8 pop {r4, r5, r6, pc} */
/* @0x2029ec ldr r4, [r0] */
/* @0x2029f0 ldr r2, [r6] */
/* @0x2029f4 ldr r5, [r0, #0x4] */
/* @0x2029f8 ldr r3, [r6, #0x4] */
/* @0x2029fc subs r2, r4, r2 */
/* @0x202a00 sbc r3, r5, r3 */
/* @0x202a04 orrs r1, r2, r3 */
/* @0x202a08 bne 0x202734 <_Z12YYCompareValRK6RValueS1_d+0x70> */
/* @0x202a0c b 0x2028b4 <_Z12YYCompareValRK6RValueS1_d+0x1f0> */
/* @0x202a10 ldr r0, [r0] */
/* @0x202a14 ldr r3, [r6] */
/* @0x202a18 rsb r0, r3, r0 */
/* @0x202a1c cmp r0, #0 */
/* @0x202a20 bne 0x20282c <_Z12YYCompareValRK6RValueS1_d+0x168> */
/* @0x202a24 pop {r4, r5, r6, pc} */
/* @0x202a28 cmp r3, #0 */
/* @0x202a2c beq 0x2028cc <_Z12YYCompareValRK6RValueS1_d+0x208> */
/* @0x202a30 b 0x2029dc <_Z12YYCompareValRK6RValueS1_d+0x318> */
/* @0x202a34 cmp r3, #13 */
/* @0x202a38 beq 0x2028cc <_Z12YYCompareValRK6RValueS1_d+0x208> */
/* @0x202a3c b 0x2029dc <_Z12YYCompareValRK6RValueS1_d+0x318> */
/* @0x202a40 ldrb r0, [r0] */
/* @0x202a44 adds r0, r0, #0 */
/* @0x202a48 movne r0, #1 */
/* @0x202a4c pop {r4, r5, r6, pc} */
/* @0x202a50 ldr r0, [r2] */
/* @0x202a54 cmp r0, #0 */
/* @0x202a58 bne 0x202a40 <_Z12YYCompareValRK6RValueS1_d+0x37c> */
/* @0x202a5c pop {r4, r5, r6, pc} */

/* ── FUNC 0x202a60 · FUNC_GridSort(void const*, void const*) · size=152 · insn=38 */
/* @0x202a60 push {r3, r4, r5, lr} */
/* @0x202a64 ldr r4, [pc, #0x78] */
/* @0x202a68 ldr r2, [pc, #0x78] */
/* @0x202a6c add r4, pc, r4 */
/* @0x202a70 ldr r3, [pc, #0x74] */
/* @0x202a74 ldr r5, [r1] */
/* @0x202a78 ldr r12, [r4, r2] */
/* @0x202a7c ldr r2, [r4, r3] */
/* @0x202a80 ldr r0, [r0] */
/* @0x202a84 ldr r12, [r12] */
/* @0x202a88 ldr r2, [r2] */
/* @0x202a8c ldr r1, [r12, #0x4] */
/* @0x202a90 ldr r3, [r12] */
/* @0x202a94 mla r0, r0, r1, r2 */
/* @0x202a98 mla r1, r5, r1, r2 */
/* @0x202a9c adds r0, r3, r0, lsl #4 */
/* @0x202aa0 moveq r2, #0 */
/* @0x202aa4 movne r2, #1 */
/* @0x202aa8 adds r1, r3, r1, lsl #4 */
/* @0x202aac moveq r2, #0 */
/* @0x202ab0 andne r2, r2, #1 */
/* @0x202ab4 cmp r2, #0 */
/* @0x202ab8 moveq r0, r2 */
/* @0x202abc beq 0x202ad0 <_Z13FUNC_GridSortPKvS0_+0x70> */
/* @0x202ac0 ldr r3, [pc, #0x28] */
/* @0x202ac4 ldr r3, [r4, r3] */
/* @0x202ac8 ldrd r2, r3, [r3] */
/* @0x202acc bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d> */
/* @0x202ad0 ldr r3, [pc, #0x1c] */
/* @0x202ad4 ldr r3, [r4, r3] */
/* @0x202ad8 ldr r3, [r3] */
/* @0x202adc mul r0, r3, r0 */
/* @0x202ae0 pop {r3, r4, r5, pc} */
/* @0x202ae4 andseq pc, lr, r4, ror #3 */
/* @0x202ae8 .word 0xfffff738 */
/* @0x202aec .word 0xfffff73c */
/* @0x202af0 .word 0xfffff734 */
/* @0x202af4 .word 0xfffff740 */

/* ── FUNC 0x202af8 · WriteValue(CStream&, RValue&) · size=376 · insn=94 */
/* @0x202af8 push {r4, r5, r6, r7, r8, lr} */
/* @0x202afc mov r4, r1 */
/* @0x202b00 ldr r1, [r1, #0xc] */
/* @0x202b04 mov r6, r0 */
/* @0x202b08 bl 0x201a10 <_ZN7CStream12WriteIntegerEi> */
/* @0x202b0c ldr r2, [r4, #0xc] */
/* @0x202b10 cmp r2, #13 */
/* @0x202b14 addls pc, pc, r2, lsl #2 */
/* @0x202b18 b 0x202b54 <_Z10WriteValueR7CStreamR6RValue+0x5c> */
/* @0x202b1c b 0x202bac <_Z10WriteValueR7CStreamR6RValue+0xb4> */
/* @0x202b20 b 0x202bc0 <_Z10WriteValueR7CStreamR6RValue+0xc8> */
/* @0x202b24 b 0x202bdc <_Z10WriteValueR7CStreamR6RValue+0xe4> */
/* @0x202b28 b 0x202b78 <_Z10WriteValueR7CStreamR6RValue+0x80> */
/* @0x202b2c b 0x202b54 <_Z10WriteValueR7CStreamR6RValue+0x5c> */
/* @0x202b30 b 0x202b74 <_Z10WriteValueR7CStreamR6RValue+0x7c> */
/* @0x202b34 b 0x202b54 <_Z10WriteValueR7CStreamR6RValue+0x5c> */
/* @0x202b38 b 0x202b8c <_Z10WriteValueR7CStreamR6RValue+0x94> */
/* @0x202b3c b 0x202b54 <_Z10WriteValueR7CStreamR6RValue+0x5c> */
/* @0x202b40 b 0x202b54 <_Z10WriteValueR7CStreamR6RValue+0x5c> */
/* @0x202b44 b 0x202b9c <_Z10WriteValueR7CStreamR6RValue+0xa4> */
/* @0x202b48 b 0x202b54 <_Z10WriteValueR7CStreamR6RValue+0x5c> */
/* @0x202b4c b 0x202b54 <_Z10WriteValueR7CStreamR6RValue+0x5c> */
/* @0x202b50 b 0x202bac <_Z10WriteValueR7CStreamR6RValue+0xb4> */
/* @0x202b54 ldr r3, [pc, #0x10c] */
/* @0x202b58 ldr r1, [pc, #0x10c] */
/* @0x202b5c ldr r3, [pc, r3] */
/* @0x202b60 add r1, pc, r1 */
/* @0x202b64 ldr r0, [r3] */
/* @0x202b68 ldr r3, [r0] */
/* @0x202b6c ldr r3, [r3, #0xc] */
/* @0x202b70 blx r3 */
/* @0x202b74 pop {r4, r5, r6, r7, r8, pc} */
/* @0x202b78 ldr r2, [r4] */
/* @0x202b7c mov r0, r6 */
/* @0x202b80 pop {r4, r5, r6, r7, r8, lr} */
/* @0x202b84 asr r3, r2, #31 */
/* @0x202b88 b 0x201a68 <_ZN7CStream14WriteInteger64Ex> */
/* @0x202b8c mov r0, r6 */
/* @0x202b90 ldr r1, [r4] */
/* @0x202b94 pop {r4, r5, r6, r7, r8, lr} */
/* @0x202b98 b 0x201a10 <_ZN7CStream12WriteIntegerEi> */
/* @0x202b9c mov r0, r6 */
/* @0x202ba0 ldm r4, {r2, r3} */
/* @0x202ba4 pop {r4, r5, r6, r7, r8, lr} */
/* @0x202ba8 b 0x201a68 <_ZN7CStream14WriteInteger64Ex> */
/* @0x202bac ldr r2, [r4] */
/* @0x202bb0 mov r0, r6 */
/* @0x202bb4 ldr r3, [r4, #0x4] */
/* @0x202bb8 pop {r4, r5, r6, r7, r8, lr} */
/* @0x202bbc b 0x201ae0 <_ZN7CStream9WriteRealEd> */
/* @0x202bc0 ldr r3, [r4] */
/* @0x202bc4 mov r0, r6 */
/* @0x202bc8 pop {r4, r5, r6, r7, r8, lr} */
/* @0x202bcc cmp r3, #0 */
/* @0x202bd0 ldrne r1, [r3] */
/* @0x202bd4 moveq r1, r3 */
/* @0x202bd8 b 0x201b58 <_ZN7CStream11WriteStringEPKc> */
/* @0x202bdc ldr r8, [r4] */
/* @0x202be0 mov r0, r6 */
/* @0x202be4 cmp r8, #0 */
/* @0x202be8 beq 0x202c5c <_Z10WriteValueR7CStreamR6RValue+0x164> */
/* @0x202bec ldr r1, [r8, #0x10] */
/* @0x202bf0 bl 0x201a10 <_ZN7CStream12WriteIntegerEi> */
/* @0x202bf4 ldr r3, [r8, #0x10] */
/* @0x202bf8 cmp r3, #0 */
/* @0x202bfc pople {r4, r5, r6, r7, r8, pc} */
/* @0x202c00 mov r7, #0 */
/* @0x202c04 ldr r4, [r8, #0x4] */
/* @0x202c08 mov r0, r6 */
/* @0x202c0c add r5, r4, r7, lsl #3 */
/* @0x202c10 ldr r1, [r4, r7, lsl #3] */
/* @0x202c14 bl 0x201a10 <_ZN7CStream12WriteIntegerEi> */
/* @0x202c18 ldr r3, [r4, r7, lsl #3] */
/* @0x202c1c cmp r3, #0 */
/* @0x202c20 movgt r4, #0 */
/* @0x202c24 ble 0x202c48 <_Z10WriteValueR7CStreamR6RValue+0x150> */
/* @0x202c28 ldr r1, [r5, #0x4] */
/* @0x202c2c mov r0, r6 */
/* @0x202c30 add r1, r1, r4, lsl #4 */
/* @0x202c34 add r4, r4, #1 */
/* @0x202c38 bl 0x202af8 <_Z10WriteValueR7CStreamR6RValue> */
/* @0x202c3c ldr r3, [r5] */
/* @0x202c40 cmp r4, r3 */
/* @0x202c44 blt 0x202c28 <_Z10WriteValueR7CStreamR6RValue+0x130> */
/* @0x202c48 ldr r3, [r8, #0x10] */
/* @0x202c4c add r7, r7, #1 */
/* @0x202c50 cmp r7, r3 */
/* @0x202c54 blt 0x202c04 <_Z10WriteValueR7CStreamR6RValue+0x10c> */
/* @0x202c58 pop {r4, r5, r6, r7, r8, pc} */
/* @0x202c5c mov r1, r8 */
/* @0x202c60 pop {r4, r5, r6, r7, r8, lr} */
/* @0x202c64 b 0x201a10 <_ZN7CStream12WriteIntegerEi> */
/* @0x202c68 ldrheq r10, [lr], -r8 */
/* @0x202c6c andseq r0, r5, r8, asr #24 */

/* ── FUNC 0x202c70 · CDS_Stack::WriteToString(char const*&) · size=144 · insn=36 */
/* @0x202c70 push {r3, r4, r5, r6, r7, lr} */
/* @0x202c74 mov r5, r0 */
/* @0x202c78 mov r0, #32 */
/* @0x202c7c mov r7, r1 */
/* @0x202c80 bl 0x27c524 <_Znwj> */
/* @0x202c84 mov r1, #0 */
/* @0x202c88 mov r6, r0 */
/* @0x202c8c bl 0x2010ec <_ZN7CStreamC2Ei> */
/* @0x202c90 mov r0, r6 */
/* @0x202c94 mov r1, #102 */
/* @0x202c98 bl 0x201a10 <_ZN7CStream12WriteIntegerEi> */
/* @0x202c9c mov r0, r6 */
/* @0x202ca0 ldr r1, [r5, #0x4] */
/* @0x202ca4 bl 0x201a10 <_ZN7CStream12WriteIntegerEi> */
/* @0x202ca8 ldr r3, [r5, #0x4] */
/* @0x202cac cmp r3, #0 */
/* @0x202cb0 movgt r4, #0 */
/* @0x202cb4 ble 0x202cd8 <_ZN9CDS_Stack13WriteToStringERPKc+0x68> */
/* @0x202cb8 ldr r1, [r5, #0xc] */
/* @0x202cbc mov r0, r6 */
/* @0x202cc0 add r1, r1, r4, lsl #4 */
/* @0x202cc4 add r4, r4, #1 */
/* @0x202cc8 bl 0x202af8 <_Z10WriteValueR7CStreamR6RValue> */
/* @0x202ccc ldr r3, [r5, #0x4] */
/* @0x202cd0 cmp r3, r4 */
/* @0x202cd4 bgt 0x202cb8 <_ZN9CDS_Stack13WriteToStringERPKc+0x48> */
/* @0x202cd8 mov r1, r7 */
/* @0x202cdc mov r0, r6 */
/* @0x202ce0 bl 0x2024b0 <_ZN7CStream15ConvertToStringERPKc> */
/* @0x202ce4 cmp r6, #0 */
/* @0x202ce8 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x202cec mov r0, r6 */
/* @0x202cf0 bl 0x201328 <_ZN7CStreamD2Ev> */
/* @0x202cf4 mov r0, r6 */
/* @0x202cf8 pop {r3, r4, r5, r6, r7, lr} */
/* @0x202cfc b 0x27d1d0 <_ZdlPv> */

/* ── FUNC 0x202d00 · CDS_Stack::Pop() · size=36 · insn=9 */
/* @0x202d00 ldr r3, [r0, #0x4] */
/* @0x202d04 cmp r3, #0 */
/* @0x202d08 subne r1, r3, #-268435455 */
/* @0x202d0c subne r3, r3, #1 */
/* @0x202d10 ldrne r2, [r0, #0xc] */
/* @0x202d14 strne r3, [r0, #0x4] */
/* @0x202d18 addne r0, r2, r1, lsl #4 */
/* @0x202d1c moveq r0, r3 */
/* @0x202d20 bx lr */

/* ── FUNC 0x202d24 · CDS_Stack::Top() · size=28 · insn=7 */
/* @0x202d24 ldr r3, [r0, #0x4] */
/* @0x202d28 cmp r3, #0 */
/* @0x202d2c subne r3, r3, #-268435455 */
/* @0x202d30 ldrne r2, [r0, #0xc] */
/* @0x202d34 addne r0, r2, r3, lsl #4 */
/* @0x202d38 moveq r0, r3 */
/* @0x202d3c bx lr */

/* ── FUNC 0x202d40 · CDS_Stack::Empty() · size=16 · insn=4 */
/* @0x202d40 ldr r0, [r0, #0x4] */
/* @0x202d44 rsbs r0, r0, #1 */
/* @0x202d48 movlo r0, #0 */
/* @0x202d4c bx lr */

/* ── FUNC 0x202d50 · CDS_Stack::Mark4GC(unsigned int*, int) · size=72 · insn=18 */
/* @0x202d50 push {r3, r4, r5, r6, r7, lr} */
/* @0x202d54 mov r5, r0 */
/* @0x202d58 ldr r3, [r0, #0x4] */
/* @0x202d5c mov r6, r1 */
/* @0x202d60 mov r7, r2 */
/* @0x202d64 cmp r3, #0 */
/* @0x202d68 pople {r3, r4, r5, r6, r7, pc} */
/* @0x202d6c mov r4, #0 */
/* @0x202d70 ldr r0, [r5, #0xc] */
/* @0x202d74 mov r1, r6 */
/* @0x202d78 mov r2, r7 */
/* @0x202d7c add r0, r0, r4, lsl #4 */
/* @0x202d80 add r4, r4, #1 */
/* @0x202d84 bl 0x191db8 <_Z9RVALUE_GCPK6RValuePji> */
/* @0x202d88 ldr r3, [r5, #0x4] */
/* @0x202d8c cmp r3, r4 */
/* @0x202d90 bgt 0x202d70 <_ZN9CDS_Stack7Mark4GCEPji+0x20> */
/* @0x202d94 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x202d98 · CDS_Stack::Add4GC(CGCGeneration*) · size=64 · insn=16 */
/* @0x202d98 ldr r3, [r0, #0x4] */
/* @0x202d9c push {r4, r5, r6, lr} */
/* @0x202da0 cmp r3, #0 */
/* @0x202da4 mov r5, r0 */
/* @0x202da8 mov r6, r1 */
/* @0x202dac pople {r4, r5, r6, pc} */
/* @0x202db0 mov r4, #0 */
/* @0x202db4 ldr r0, [r5, #0xc] */
/* @0x202db8 mov r1, r6 */
/* @0x202dbc add r0, r0, r4, lsl #4 */
/* @0x202dc0 add r4, r4, #1 */
/* @0x202dc4 bl 0x191bac <_Z17RVALUE_GC_ADDROOTPK6RValueP13CGCGeneration> */
/* @0x202dc8 ldr r3, [r5, #0x4] */
/* @0x202dcc cmp r3, r4 */
/* @0x202dd0 bgt 0x202db4 <_ZN9CDS_Stack6Add4GCEP13CGCGeneration+0x1c> */
/* @0x202dd4 pop {r4, r5, r6, pc} */

/* ── FUNC 0x202dd8 · CDS_Stack::MarkOnlyChildren4GC(unsigned int*, int) · size=72 · insn=18 */
/* @0x202dd8 push {r3, r4, r5, r6, r7, lr} */
/* @0x202ddc mov r5, r0 */
/* @0x202de0 ldr r3, [r0, #0x4] */
/* @0x202de4 mov r6, r1 */
/* @0x202de8 mov r7, r2 */
/* @0x202dec cmp r3, #0 */
/* @0x202df0 pople {r3, r4, r5, r6, r7, pc} */
/* @0x202df4 mov r4, #0 */
/* @0x202df8 ldr r0, [r5, #0xc] */
/* @0x202dfc mov r1, r6 */
/* @0x202e00 mov r2, r7 */
/* @0x202e04 add r0, r0, r4, lsl #4 */
/* @0x202e08 add r4, r4, #1 */
/* @0x202e0c bl 0x191f5c <_Z18RVALUE_GC_THISONLYPK6RValuePji> */
/* @0x202e10 ldr r3, [r5, #0x4] */
/* @0x202e14 cmp r3, r4 */
/* @0x202e18 bgt 0x202df8 <_ZN9CDS_Stack19MarkOnlyChildren4GCEPji+0x20> */
/* @0x202e1c pop {r3, r4, r5, r6, r7, pc} */
