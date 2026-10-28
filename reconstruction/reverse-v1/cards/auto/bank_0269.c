/* libyoyo.so 覆盖卡组 0269
 * 函数 0x2c67b8..0x2c7810，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2c67b8 · b2Draw::b2Draw() · size=32 · insn=8 */
/* @0x2c67b8 ldr r3, [pc, #0x14] */
/* @0x2c67bc mov r1, #0 */
/* @0x2c67c0 str r1, [r0, #0x4] */
/* @0x2c67c4 ldr r3, [pc, r3] */
/* @0x2c67c8 add r3, r3, #8 */
/* @0x2c67cc str r3, [r0] */
/* @0x2c67d0 bx lr */
/* @0x2c67d4 andseq r10, r2, r8, lsr #26 */

/* ── FUNC 0x2c67b8 · b2Draw::b2Draw() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2c67d8 · b2Draw::SetFlags(unsigned int) · size=8 · insn=2 */
/* @0x2c67d8 str r1, [r0, #0x4] */
/* @0x2c67dc bx lr */

/* ── FUNC 0x2c67e0 · b2Draw::GetFlags() const · size=8 · insn=2 */
/* @0x2c67e0 ldr r0, [r0, #0x4] */
/* @0x2c67e4 bx lr */

/* ── FUNC 0x2c67e8 · b2Draw::AppendFlags(unsigned int) · size=16 · insn=4 */
/* @0x2c67e8 ldr r3, [r0, #0x4] */
/* @0x2c67ec orr r1, r3, r1 */
/* @0x2c67f0 str r1, [r0, #0x4] */
/* @0x2c67f4 bx lr */

/* ── FUNC 0x2c67f8 · b2Draw::ClearFlags(unsigned int) · size=16 · insn=4 */
/* @0x2c67f8 ldr r3, [r0, #0x4] */
/* @0x2c67fc bic r1, r3, r1 */
/* @0x2c6800 str r1, [r0, #0x4] */
/* @0x2c6804 bx lr */

/* ── FUNC 0x2c6808 · b2Mat33::Solve33(b2Vec3 const&) const · size=224 · insn=56 */
/* @0x2c6808 vldr s2, [r1, #32] */
/* @0x2c680c vldr s7, [r1, #12] */
/* @0x2c6810 vmul.f32 s12, s2, s7 */
/* @0x2c6814 vldr s1, [r1, #20] */
/* @0x2c6818 vldr s3, [r1, #24] */
/* @0x2c681c vldr s6, [r1, #28] */
/* @0x2c6820 vldr s4, [r1, #16] */
/* @0x2c6824 vpush {d8, d9} */
/* @0x2c6828 vldr s18, [r1, #4] */
/* @0x2c682c vldr s16, [r1] */
/* @0x2c6830 vldr s0, [r1, #8] */
/* @0x2c6834 vldr s9, [r2] */
/* @0x2c6838 vldr s11, [r2, #8] */
/* @0x2c683c vldr s10, [r2, #4] */
/* @0x2c6840 mov r3, r0 */
/* @0x2c6844 vnmls.f32 s12, s1, s3 */
/* @0x2c6848 vmul.f32 s5, s1, s6 */
/* @0x2c684c vnmls.f32 s5, s4, s2 */
/* @0x2c6850 vmul.f32 s15, s12, s18 */
/* @0x2c6854 vmul.f32 s8, s4, s3 */
/* @0x2c6858 vmla.f32 s15, s5, s16 */
/* @0x2c685c vnmls.f32 s8, s6, s7 */
/* @0x2c6860 vmla.f32 s15, s8, s0 */
/* @0x2c6864 vcmp.f32 s15, #0 */
/* @0x2c6868 vmrs APSR_nzcv, fpscr */
/* @0x2c686c vmovne.f32 s14, #1.000000e+00 */
/* @0x2c6870 vmul.f32 s13, s2, s9 */
/* @0x2c6874 vdivne.f32 s15, s14, s15 */
/* @0x2c6878 vmul.f32 s14, s7, s11 */
/* @0x2c687c vnmls.f32 s13, s3, s11 */
/* @0x2c6880 vnmls.f32 s14, s1, s9 */
/* @0x2c6884 vmul.f32 s17, s6, s11 */
/* @0x2c6888 vmul.f32 s1, s1, s10 */
/* @0x2c688c vnmls.f32 s17, s2, s10 */
/* @0x2c6890 vnmls.f32 s1, s4, s11 */
/* @0x2c6894 vmul.f32 s13, s18, s13 */
/* @0x2c6898 vmul.f32 s14, s18, s14 */
/* @0x2c689c vmul.f32 s12, s12, s10 */
/* @0x2c68a0 vmul.f32 s3, s3, s10 */
/* @0x2c68a4 vmul.f32 s4, s4, s9 */
/* @0x2c68a8 vmla.f32 s13, s16, s17 */
/* @0x2c68ac vmla.f32 s14, s16, s1 */
/* @0x2c68b0 vpop {d8, d9} */
/* @0x2c68b4 vmla.f32 s12, s5, s9 */
/* @0x2c68b8 vnmls.f32 s3, s6, s9 */
/* @0x2c68bc vnmls.f32 s4, s7, s10 */
/* @0x2c68c0 vmla.f32 s12, s8, s11 */
/* @0x2c68c4 vmla.f32 s13, s0, s3 */
/* @0x2c68c8 vmla.f32 s14, s0, s4 */
/* @0x2c68cc vmul.f32 s12, s15, s12 */
/* @0x2c68d0 vmul.f32 s13, s15, s13 */
/* @0x2c68d4 vstr s12, [r3] */
/* @0x2c68d8 vmul.f32 s15, s15, s14 */
/* @0x2c68dc vstr s13, [r3, #4] */
/* @0x2c68e0 vstr s15, [r3, #8] */
/* @0x2c68e4 bx lr */

/* ── FUNC 0x2c68e8 · b2Mat33::Solve22(b2Vec2 const&) const · size=88 · insn=22 */
/* @0x2c68e8 vldr s14, [r1, #12] */
/* @0x2c68ec vldr s13, [r1, #4] */
/* @0x2c68f0 vmul.f32 s15, s14, s13 */
/* @0x2c68f4 vldr s9, [r1] */
/* @0x2c68f8 vldr s12, [r1, #16] */
/* @0x2c68fc vldr s10, [r2, #4] */
/* @0x2c6900 mov r3, r0 */
/* @0x2c6904 vnmls.f32 s15, s9, s12 */
/* @0x2c6908 vcmp.f32 s15, #0 */
/* @0x2c690c vmrs APSR_nzcv, fpscr */
/* @0x2c6910 vmovne.f32 s11, #1.000000e+00 */
/* @0x2c6914 vdivne.f32 s15, s11, s15 */
/* @0x2c6918 vldr s11, [r2] */
/* @0x2c691c vmul.f32 s14, s10, s14 */
/* @0x2c6920 vmul.f32 s13, s13, s11 */
/* @0x2c6924 vnmls.f32 s14, s11, s12 */
/* @0x2c6928 vnmls.f32 s13, s9, s10 */
/* @0x2c692c vmul.f32 s13, s13, s15 */
/* @0x2c6930 vmul.f32 s15, s14, s15 */
/* @0x2c6934 vstr s13, [r3, #4] */
/* @0x2c6938 vstr s15, [r3] */
/* @0x2c693c bx lr */

/* ── FUNC 0x2c6940 · b2Mat33::GetInverse22(b2Mat33*) const · size=104 · insn=26 */
/* @0x2c6940 vldr s12, [r0, #12] */
/* @0x2c6944 vldr s13, [r0, #4] */
/* @0x2c6948 vmul.f32 s15, s12, s13 */
/* @0x2c694c vldr s11, [r0] */
/* @0x2c6950 vldr s10, [r0, #16] */
/* @0x2c6954 mov r3, #0 */
/* @0x2c6958 str r3, [r1, #0x8] */
/* @0x2c695c str r3, [r1, #0x14] */
/* @0x2c6960 str r3, [r1, #0x18] */
/* @0x2c6964 str r3, [r1, #0x1c] */
/* @0x2c6968 str r3, [r1, #0x20] */
/* @0x2c696c vnmls.f32 s15, s11, s10 */
/* @0x2c6970 vcmp.f32 s15, #0 */
/* @0x2c6974 vmrs APSR_nzcv, fpscr */
/* @0x2c6978 vmovne.f32 s14, #1.000000e+00 */
/* @0x2c697c vdivne.f32 s15, s14, s15 */
/* @0x2c6980 vneg.f32 s14, s15 */
/* @0x2c6984 vmul.f32 s10, s15, s10 */
/* @0x2c6988 vmul.f32 s12, s14, s12 */
/* @0x2c698c vstr s10, [r1] */
/* @0x2c6990 vmul.f32 s15, s15, s11 */
/* @0x2c6994 vstr s12, [r1, #12] */
/* @0x2c6998 vmul.f32 s14, s13, s14 */
/* @0x2c699c vstr s15, [r1, #16] */
/* @0x2c69a0 vstr s14, [r1, #4] */
/* @0x2c69a4 bx lr */

/* ── FUNC 0x2c69a8 · b2Mat33::GetSymInverse33(b2Mat33*) const · size=192 · insn=48 */
/* @0x2c69a8 vldr s12, [r0, #12] */
/* @0x2c69ac vldr s5, [r0, #32] */
/* @0x2c69b0 vmul.f32 s4, s5, s12 */
/* @0x2c69b4 vldr s6, [r0, #16] */
/* @0x2c69b8 vldr s14, [r0, #24] */
/* @0x2c69bc vldr s11, [r0, #20] */
/* @0x2c69c0 vldr s13, [r0, #28] */
/* @0x2c69c4 vldr s15, [r0, #4] */
/* @0x2c69c8 vldr s10, [r0] */
/* @0x2c69cc vldr s9, [r0, #8] */
/* @0x2c69d0 vmov.f32 s7, s4 */
/* @0x2c69d4 vmul.f32 s3, s6, s5 */
/* @0x2c69d8 vnmls.f32 s7, s11, s14 */
/* @0x2c69dc vmov.f32 s8, s3 */
/* @0x2c69e0 vmls.f32 s8, s11, s13 */
/* @0x2c69e4 vmul.f32 s15, s7, s15 */
/* @0x2c69e8 vmul.f32 s11, s6, s14 */
/* @0x2c69ec vmla.f32 s15, s8, s10 */
/* @0x2c69f0 vnmls.f32 s11, s13, s12 */
/* @0x2c69f4 vmla.f32 s15, s11, s9 */
/* @0x2c69f8 vcmp.f32 s15, #0 */
/* @0x2c69fc vmrs APSR_nzcv, fpscr */
/* @0x2c6a00 vmovne.f32 s9, #1.000000e+00 */
/* @0x2c6a04 vdivne.f32 s15, s9, s15 */
/* @0x2c6a08 vmul.f32 s8, s14, s14 */
/* @0x2c6a0c vmul.f32 s7, s13, s10 */
/* @0x2c6a10 vmul.f32 s9, s12, s12 */
/* @0x2c6a14 vnmls.f32 s7, s14, s12 */
/* @0x2c6a18 vmls.f32 s3, s13, s13 */
/* @0x2c6a1c vnmls.f32 s4, s13, s14 */
/* @0x2c6a20 vnmls.f32 s8, s5, s10 */
/* @0x2c6a24 vnmls.f32 s9, s6, s10 */
/* @0x2c6a28 vmul.f32 s7, s7, s15 */
/* @0x2c6a2c vmul.f32 s14, s4, s15 */
/* @0x2c6a30 vstr s7, [r1, #20] */
/* @0x2c6a34 vstr s7, [r1, #28] */
/* @0x2c6a38 vmul.f32 s3, s3, s15 */
/* @0x2c6a3c vstr s14, [r1, #4] */
/* @0x2c6a40 vstr s14, [r1, #12] */
/* @0x2c6a44 vmul.f32 s8, s8, s15 */
/* @0x2c6a48 vstr s3, [r1] */
/* @0x2c6a4c vmul.f32 s9, s9, s15 */
/* @0x2c6a50 vstr s8, [r1, #16] */
/* @0x2c6a54 vmul.f32 s15, s15, s11 */
/* @0x2c6a58 vstr s9, [r1, #32] */
/* @0x2c6a5c vstr s15, [r1, #8] */
/* @0x2c6a60 vstr s15, [r1, #24] */
/* @0x2c6a64 bx lr */

/* ── FUNC 0x2c6a68 · _b2relassert(bool, wchar_t const*) · size=4 · insn=1 */
/* @0x2c6a68 bx lr */

/* ── FUNC 0x2c6a6c · b2Alloc(int) · size=4 · insn=1 */
/* @0x2c6a6c b 0xb6544 <malloc@plt> */

/* ── FUNC 0x2c6a70 · b2Free(void*) · size=4 · insn=1 */
/* @0x2c6a70 b 0xb655c <free@plt> */

/* ── FUNC 0x2c6a74 · b2Log(char const*, ...) · size=12 · insn=3 */
/* @0x2c6a74 push {r0, r1, r2, r3} */
/* @0x2c6a78 add sp, sp, #16 */
/* @0x2c6a7c bx lr */

/* ── FUNC 0x2c6a80 · b2Body::b2Body(b2BodyDef const*, b2World*) · size=380 · insn=95 */
/* @0x2c6a80 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2c6a84 mov r5, r1 */
/* @0x2c6a88 ldrb r3, [r1, #0x27] */
/* @0x2c6a8c mov r1, #0 */
/* @0x2c6a90 strh r1, [r0, #4] */
/* @0x2c6a94 mov r4, r0 */
/* @0x2c6a98 cmp r3, r1 */
/* @0x2c6a9c ldr r7, [r5, #0xc] */
/* @0x2c6aa0 add r6, r4, #12 */
/* @0x2c6aa4 add r8, r4, #28 */
/* @0x2c6aa8 movne r3, #8 */
/* @0x2c6aac strhne r3, [r0, #4] */
/* @0x2c6ab0 ldrb r3, [r5, #0x26] */
/* @0x2c6ab4 add r11, r4, #52 */
/* @0x2c6ab8 add r10, r4, #60 */
/* @0x2c6abc add r9, r5, #16 */
/* @0x2c6ac0 cmp r3, #0 */
/* @0x2c6ac4 ldrhne r3, [r0, #4] */
/* @0x2c6ac8 orrne r3, r3, #16 */
/* @0x2c6acc strhne r3, [r0, #4] */
/* @0x2c6ad0 ldrb r3, [r5, #0x24] */
/* @0x2c6ad4 cmp r3, #0 */
/* @0x2c6ad8 ldrhne r3, [r0, #4] */
/* @0x2c6adc orrne r3, r3, #4 */
/* @0x2c6ae0 strhne r3, [r0, #4] */
/* @0x2c6ae4 ldrb r3, [r5, #0x25] */
/* @0x2c6ae8 cmp r3, #0 */
/* @0x2c6aec ldrhne r3, [r0, #4] */
/* @0x2c6af0 orrne r3, r3, #2 */
/* @0x2c6af4 strhne r3, [r0, #4] */
/* @0x2c6af8 ldrb r3, [r5, #0x28] */
/* @0x2c6afc cmp r3, #0 */
/* @0x2c6b00 ldrhne r3, [r0, #4] */
/* @0x2c6b04 orrne r3, r3, #32 */
/* @0x2c6b08 strhne r3, [r0, #4] */
/* @0x2c6b0c ldmib r5, {r0, r1} */
/* @0x2c6b10 str r2, [r4, #0x68] */
/* @0x2c6b14 stm r6, {r0, r1} */
/* @0x2c6b18 mov r0, r7 */
/* @0x2c6b1c bl 0xb6580 <sinf@plt> */
/* @0x2c6b20 str r0, [r4, #0x14] */
/* @0x2c6b24 mov r0, r7 */
/* @0x2c6b28 bl 0xb658c <cosf@plt> */
/* @0x2c6b2c vldr s15, [pc, #196] */
/* @0x2c6b30 mov r12, #0 */
/* @0x2c6b34 str r0, [r4, #0x18] */
/* @0x2c6b38 ldm r6, {r0, r1, r2, r3} */
/* @0x2c6b3c stm r8, {r0, r1, r2, r3} */
/* @0x2c6b40 vstr s15, [r4, #44] */
/* @0x2c6b44 vstr s15, [r4, #48] */
/* @0x2c6b48 add r3, r4, #80 */
/* @0x2c6b4c ldm r6, {r0, r1} */
/* @0x2c6b50 stm r11, {r0, r1} */
/* @0x2c6b54 ldm r6, {r0, r1} */
/* @0x2c6b58 stm r10, {r0, r1} */
/* @0x2c6b5c str r7, [r4, #0x44] */
/* @0x2c6b60 ldm r9, {r0, r1} */
/* @0x2c6b64 vstr s15, [r4, #76] */
/* @0x2c6b68 ldr r2, [r5, #0x18] */
/* @0x2c6b6c str r7, [r4, #0x48] */
/* @0x2c6b70 str r12, [r4, #0x7c] */
/* @0x2c6b74 str r12, [r4, #0x80] */
/* @0x2c6b78 str r12, [r4, #0x6c] */
/* @0x2c6b7c str r12, [r4, #0x70] */
/* @0x2c6b80 stm r3, {r0, r1} */
/* @0x2c6b84 mov r0, r4 */
/* @0x2c6b88 ldr r3, [r5] */
/* @0x2c6b8c ldr r1, [r5, #0x1c] */
/* @0x2c6b90 str r2, [r4, #0x58] */
/* @0x2c6b94 cmp r3, #2 */
/* @0x2c6b98 ldr r2, [r5, #0x20] */
/* @0x2c6b9c str r1, [r4, #0x94] */
/* @0x2c6ba0 ldr r1, [r5, #0x2c] */
/* @0x2c6ba4 str r2, [r4, #0x98] */
/* @0x2c6ba8 ldr r2, [r5, #0x30] */
/* @0x2c6bac vstr s15, [r4, #92] */
/* @0x2c6bb0 str r3, [r4] */
/* @0x2c6bb4 vstr s15, [r4, #96] */
/* @0x2c6bb8 moveq r3, #1065353216 */
/* @0x2c6bbc vstr s15, [r4, #100] */
/* @0x2c6bc0 str r2, [r4, #0x9c] */
/* @0x2c6bc4 vstr s15, [r4, #160] */
/* @0x2c6bc8 streq r3, [r4, #0x84] */
/* @0x2c6bcc mov r2, #0 */
/* @0x2c6bd0 streq r3, [r4, #0x88] */
/* @0x2c6bd4 vstrne s15, [r4, #132] */
/* @0x2c6bd8 mov r3, #0 */
/* @0x2c6bdc vstrne s15, [r4, #136] */
/* @0x2c6be0 str r2, [r4, #0x8c] */
/* @0x2c6be4 str r2, [r4, #0x90] */
/* @0x2c6be8 str r3, [r4, #0x74] */
/* @0x2c6bec str r1, [r4, #0xa4] */
/* @0x2c6bf0 str r3, [r4, #0x78] */
/* @0x2c6bf4 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2c6bf8 andeq r0, r0, r0 */

/* ── FUNC 0x2c6a80 · b2Body::b2Body(b2BodyDef const*, b2World*) · alias of the symbol above · insn=0 */

/* ── FUNC 0x2c6bfc · b2Body::~b2Body() · size=4 · insn=1 */
/* @0x2c6bfc bx lr */

/* ── FUNC 0x2c6bfc · b2Body::~b2Body() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2c6c00 · b2Body::ResetMassData() · size=508 · insn=127 */
/* @0x2c6c00 ldr r2, [r0] */
/* @0x2c6c04 mov r3, #0 */
/* @0x2c6c08 push {r4, r5, r6, lr} */
/* @0x2c6c0c vpush {d8} */
/* @0x2c6c10 cmp r2, #1 */
/* @0x2c6c14 sub sp, sp, #16 */
/* @0x2c6c18 mov r4, r0 */
/* @0x2c6c1c str r3, [r0, #0x84] */
/* @0x2c6c20 str r3, [r0, #0x88] */
/* @0x2c6c24 str r3, [r0, #0x8c] */
/* @0x2c6c28 str r3, [r0, #0x90] */
/* @0x2c6c2c str r3, [r0, #0x2c] */
/* @0x2c6c30 str r3, [r0, #0x30] */
/* @0x2c6c34 bls 0x2c6dc8 <_ZN6b2Body13ResetMassDataEv+0x1c8> */
/* @0x2c6c38 ldr r5, [r0, #0x74] */
/* @0x2c6c3c ldr r3, [pc, #0x1b4] */
/* @0x2c6c40 cmp r5, #0 */
/* @0x2c6c44 ldr r3, [pc, r3] */
/* @0x2c6c48 vldr s16, [r3] */
/* @0x2c6c4c vldr s17, [r3, #4] */
/* @0x2c6c50 bne 0x2c6c64 <_ZN6b2Body13ResetMassDataEv+0x64> */
/* @0x2c6c54 b 0x2c6db8 <_ZN6b2Body13ResetMassDataEv+0x1b8> */
/* @0x2c6c58 ldr r5, [r5, #0x4] */
/* @0x2c6c5c cmp r5, #0 */
/* @0x2c6c60 beq 0x2c6cc8 <_ZN6b2Body13ResetMassDataEv+0xc8> */
/* @0x2c6c64 vldr s15, [r5] */
/* @0x2c6c68 vcmp.f32 s15, #0 */
/* @0x2c6c6c vmrs APSR_nzcv, fpscr */
/* @0x2c6c70 beq 0x2c6c58 <_ZN6b2Body13ResetMassDataEv+0x58> */
/* @0x2c6c74 ldr r0, [r5, #0xc] */
/* @0x2c6c78 mov r1, sp */
/* @0x2c6c7c vmov r2, s15 */
/* @0x2c6c80 ldr r3, [r0] */
/* @0x2c6c84 ldr r3, [r3, #0x20] */
/* @0x2c6c88 blx r3 */
/* @0x2c6c8c vldr s15, [sp] */
/* @0x2c6c90 vldr s11, [r4, #132] */
/* @0x2c6c94 vldr s13, [r4, #140] */
/* @0x2c6c98 vadd.f32 s11, s11, s15 */
/* @0x2c6c9c vldr s10, [sp, #4] */
/* @0x2c6ca0 vldr s12, [sp, #8] */
/* @0x2c6ca4 vldr s14, [sp, #12] */
/* @0x2c6ca8 ldr r5, [r5, #0x4] */
/* @0x2c6cac cmp r5, #0 */
/* @0x2c6cb0 vmla.f32 s16, s15, s10 */
/* @0x2c6cb4 vstr s11, [r4, #132] */
/* @0x2c6cb8 vmla.f32 s17, s15, s12 */
/* @0x2c6cbc vadd.f32 s15, s13, s14 */
/* @0x2c6cc0 vstr s15, [r4, #140] */
/* @0x2c6cc4 bne 0x2c6c64 <_ZN6b2Body13ResetMassDataEv+0x64> */
/* @0x2c6cc8 vldr s15, [r4, #132] */
/* @0x2c6ccc vcmpe.f32 s15, #0 */
/* @0x2c6cd0 vmrs APSR_nzcv, fpscr */
/* @0x2c6cd4 ble 0x2c6db8 <_ZN6b2Body13ResetMassDataEv+0x1b8> */
/* @0x2c6cd8 vmov.f32 s14, #1.000000e+00 */
/* @0x2c6cdc vdiv.f32 s15, s14, s15 */
/* @0x2c6ce0 vmul.f32 s16, s16, s15 */
/* @0x2c6ce4 vstr s15, [r4, #136] */
/* @0x2c6ce8 vmul.f32 s17, s17, s15 */
/* @0x2c6cec vldr s15, [r4, #140] */
/* @0x2c6cf0 vcmpe.f32 s15, #0 */
/* @0x2c6cf4 vmrs APSR_nzcv, fpscr */
/* @0x2c6cf8 ble 0x2c6d08 <_ZN6b2Body13ResetMassDataEv+0x108> */
/* @0x2c6cfc ldrh r3, [r4, #4] */
/* @0x2c6d00 tst r3, #16 */
/* @0x2c6d04 beq 0x2c6d94 <_ZN6b2Body13ResetMassDataEv+0x194> */
/* @0x2c6d08 mov r3, #0 */
/* @0x2c6d0c str r3, [r4, #0x8c] */
/* @0x2c6d10 str r3, [r4, #0x90] */
/* @0x2c6d14 vldr s14, [r4, #24] */
/* @0x2c6d18 vldr s11, [r4, #20] */
/* @0x2c6d1c vstr s17, [r4, #48] */
/* @0x2c6d20 vmul.f32 s15, s14, s17 */
/* @0x2c6d24 vldr s8, [r4, #12] */
/* @0x2c6d28 vldr s12, [r4, #16] */
/* @0x2c6d2c vldr s9, [r4, #60] */
/* @0x2c6d30 vldr s10, [r4, #64] */
/* @0x2c6d34 add r2, r4, #60 */
/* @0x2c6d38 vstr s16, [r4, #44] */
/* @0x2c6d3c add r3, r4, #52 */
/* @0x2c6d40 vldr s13, [r4, #88] */
/* @0x2c6d44 vmul.f32 s17, s11, s17 */
/* @0x2c6d48 vmla.f32 s15, s11, s16 */
/* @0x2c6d4c vnmls.f32 s17, s14, s16 */
/* @0x2c6d50 vadd.f32 s12, s15, s12 */
/* @0x2c6d54 vadd.f32 s17, s17, s8 */
/* @0x2c6d58 vstr s12, [r4, #64] */
/* @0x2c6d5c vsub.f32 s11, s17, s9 */
/* @0x2c6d60 vstr s17, [r4, #60] */
/* @0x2c6d64 ldm r2, {r0, r1} */
/* @0x2c6d68 stm r3, {r0, r1} */
/* @0x2c6d6c vldr s14, [r4, #84] */
/* @0x2c6d70 vldr s15, [r4, #80] */
/* @0x2c6d74 vsub.f32 s12, s12, s10 */
/* @0x2c6d78 vmla.f32 s14, s13, s11 */
/* @0x2c6d7c vmls.f32 s15, s13, s12 */
/* @0x2c6d80 vstr s14, [r4, #84] */
/* @0x2c6d84 vstr s15, [r4, #80] */
/* @0x2c6d88 add sp, sp, #16 */
/* @0x2c6d8c vpop {d8} */
/* @0x2c6d90 pop {r4, r5, r6, pc} */
/* @0x2c6d94 vmul.f32 s14, s17, s17 */
/* @0x2c6d98 vldr s13, [r4, #132] */
/* @0x2c6d9c vmla.f32 s14, s16, s16 */
/* @0x2c6da0 vmls.f32 s15, s14, s13 */
/* @0x2c6da4 vmov.f32 s14, #1.000000e+00 */
/* @0x2c6da8 vstr s15, [r4, #140] */
/* @0x2c6dac vdiv.f32 s15, s14, s15 */
/* @0x2c6db0 vstr s15, [r4, #144] */
/* @0x2c6db4 b 0x2c6d14 <_ZN6b2Body13ResetMassDataEv+0x114> */
/* @0x2c6db8 mov r3, #1065353216 */
/* @0x2c6dbc str r3, [r4, #0x84] */
/* @0x2c6dc0 str r3, [r4, #0x88] */
/* @0x2c6dc4 b 0x2c6cec <_ZN6b2Body13ResetMassDataEv+0xec> */
/* @0x2c6dc8 add r3, r0, #12 */
/* @0x2c6dcc ldr r5, [r0, #0x48] */
/* @0x2c6dd0 add r12, r0, #52 */
/* @0x2c6dd4 add r2, r0, #60 */
/* @0x2c6dd8 ldm r3, {r0, r1} */
/* @0x2c6ddc stm r12, {r0, r1} */
/* @0x2c6de0 ldm r3, {r0, r1} */
/* @0x2c6de4 stm r2, {r0, r1} */
/* @0x2c6de8 str r5, [r4, #0x44] */
/* @0x2c6dec add sp, sp, #16 */
/* @0x2c6df0 vpop {d8} */
/* @0x2c6df4 pop {r4, r5, r6, pc} */
/* @0x2c6df8 mulseq r2, r4, r8 */

/* ── FUNC 0x2c6dfc · b2Body::CreateFixture(b2FixtureDef const*) · size=212 · insn=53 */
/* @0x2c6dfc push {r3, r4, r5, r6, r7, lr} */
/* @0x2c6e00 movw r2, #0x91d4 */
/* @0x2c6e04 ldr r6, [r0, #0x68] */
/* @0x2c6e08 movt r2, #0x1 */
/* @0x2c6e0c mov r4, r0 */
/* @0x2c6e10 mov r7, r1 */
/* @0x2c6e14 ldr r2, [r6, r2] */
/* @0x2c6e18 tst r2, #2 */
/* @0x2c6e1c bne 0x2c6ec8 <_ZN6b2Body13CreateFixtureEPK12b2FixtureDef+0xcc> */
/* @0x2c6e20 mov r0, r6 */
/* @0x2c6e24 mov r1, #52 */
/* @0x2c6e28 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi> */
/* @0x2c6e2c subs r5, r0, #0 */
/* @0x2c6e30 beq 0x2c6e38 <_ZN6b2Body13CreateFixtureEPK12b2FixtureDef+0x3c> */
/* @0x2c6e34 bl 0x2c84e0 <_ZN9b2FixtureC2Ev> */
/* @0x2c6e38 mov r3, r7 */
/* @0x2c6e3c mov r1, r6 */
/* @0x2c6e40 mov r0, r5 */
/* @0x2c6e44 mov r2, r4 */
/* @0x2c6e48 bl 0x2c851c <_ZN9b2Fixture6CreateEP16b2BlockAllocatorP6b2BodyPK12b2FixtureDef> */
/* @0x2c6e4c ldrh r3, [r4, #4] */
/* @0x2c6e50 tst r3, #32 */
/* @0x2c6e54 bne 0x2c6eac <_ZN6b2Body13CreateFixtureEPK12b2FixtureDef+0xb0> */
/* @0x2c6e58 vldr s15, [r5] */
/* @0x2c6e5c vcmpe.f32 s15, #0 */
/* @0x2c6e60 ldr r2, [r4, #0x74] */
/* @0x2c6e64 ldr r3, [r4, #0x78] */
/* @0x2c6e68 vmrs APSR_nzcv, fpscr */
/* @0x2c6e6c str r2, [r5, #0x4] */
/* @0x2c6e70 add r3, r3, #1 */
/* @0x2c6e74 str r5, [r4, #0x74] */
/* @0x2c6e78 str r3, [r4, #0x78] */
/* @0x2c6e7c str r4, [r5, #0x8] */
/* @0x2c6e80 ble 0x2c6e8c <_ZN6b2Body13CreateFixtureEPK12b2FixtureDef+0x90> */
/* @0x2c6e84 mov r0, r4 */
/* @0x2c6e88 bl 0x2c6c00 <_ZN6b2Body13ResetMassDataEv> */
/* @0x2c6e8c ldr r2, [r4, #0x68] */
/* @0x2c6e90 movw r3, #0x91d4 */
/* @0x2c6e94 movt r3, #0x1 */
/* @0x2c6e98 mov r0, r5 */
/* @0x2c6e9c ldr r1, [r2, r3] */
/* @0x2c6ea0 orr r1, r1, #1 */
/* @0x2c6ea4 str r1, [r2, r3] */
/* @0x2c6ea8 pop {r3, r4, r5, r6, r7, pc} */
/* @0x2c6eac ldr r1, [r4, #0x68] */
/* @0x2c6eb0 mov r0, r5 */
/* @0x2c6eb4 add r2, r4, #12 */
/* @0x2c6eb8 add r1, r1, #102400 */
/* @0x2c6ebc add r1, r1, #472 */
/* @0x2c6ec0 bl 0x2c86e4 <_ZN9b2Fixture13CreateProxiesEP12b2BroadPhaseRK11b2Transform> */
/* @0x2c6ec4 b 0x2c6e58 <_ZN6b2Body13CreateFixtureEPK12b2FixtureDef+0x5c> */
/* @0x2c6ec8 mov r0, #0 */
/* @0x2c6ecc pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x2c6ed0 · b2Body::CreateFixture(b2Shape const*, float) · size=84 · insn=21 */
/* @0x2c6ed0 str lr, [sp, #-0x4]! */
/* @0x2c6ed4 sub sp, sp, #44 */
/* @0x2c6ed8 movw r3, #0xffff */
/* @0x2c6edc movw r12, #0xcccd */
/* @0x2c6ee0 str r1, [sp, #0x4] */
/* @0x2c6ee4 add r1, sp, #4 */
/* @0x2c6ee8 str r2, [sp, #0x14] */
/* @0x2c6eec movt r12, #0x3e4c */
/* @0x2c6ef0 str r3, [sp, #0x20] */
/* @0x2c6ef4 mov r2, #1 */
/* @0x2c6ef8 mov r3, #0 */
/* @0x2c6efc str r2, [sp, #0x1c] */
/* @0x2c6f00 strh r3, [sp, #36] */
/* @0x2c6f04 mov r2, #0 */
/* @0x2c6f08 str r3, [sp, #0x8] */
/* @0x2c6f0c strb r3, [sp, #0x18] */
/* @0x2c6f10 str r12, [sp, #0xc] */
/* @0x2c6f14 str r2, [sp, #0x10] */
/* @0x2c6f18 bl 0x2c6dfc <_ZN6b2Body13CreateFixtureEPK12b2FixtureDef> */
/* @0x2c6f1c add sp, sp, #44 */
/* @0x2c6f20 ldr pc, [sp], #4 */

/* ── FUNC 0x2c6f24 · b2Body::DestroyFixture(b2Fixture*) · size=268 · insn=67 */
/* @0x2c6f24 push {r3, r4, r5, r6, r7, lr} */
/* @0x2c6f28 movw r3, #0x91d4 */
/* @0x2c6f2c ldr r7, [r0, #0x68] */
/* @0x2c6f30 movt r3, #0x1 */
/* @0x2c6f34 mov r6, r0 */
/* @0x2c6f38 mov r5, r1 */
/* @0x2c6f3c ldr r3, [r7, r3] */
/* @0x2c6f40 tst r3, #2 */
/* @0x2c6f44 popne {r3, r4, r5, r6, r7, pc} */
/* @0x2c6f48 ldr r2, [r0, #0x74] */
/* @0x2c6f4c cmp r2, #0 */
/* @0x2c6f50 beq 0x2c6f7c <_ZN6b2Body14DestroyFixtureEP9b2Fixture+0x58> */
/* @0x2c6f54 cmp r2, r1 */
/* @0x2c6f58 addeq r2, r0, #116 */
/* @0x2c6f5c bne 0x2c6f70 <_ZN6b2Body14DestroyFixtureEP9b2Fixture+0x4c> */
/* @0x2c6f60 b 0x2c700c <_ZN6b2Body14DestroyFixtureEP9b2Fixture+0xe8> */
/* @0x2c6f64 cmp r3, r5 */
/* @0x2c6f68 beq 0x2c7008 <_ZN6b2Body14DestroyFixtureEP9b2Fixture+0xe4> */
/* @0x2c6f6c mov r2, r3 */
/* @0x2c6f70 ldr r3, [r2, #0x4] */
/* @0x2c6f74 cmp r3, #0 */
/* @0x2c6f78 bne 0x2c6f64 <_ZN6b2Body14DestroyFixtureEP9b2Fixture+0x40> */
/* @0x2c6f7c ldr r4, [r6, #0x80] */
/* @0x2c6f80 cmp r4, #0 */
/* @0x2c6f84 beq 0x2c6fbc <_ZN6b2Body14DestroyFixtureEP9b2Fixture+0x98> */
/* @0x2c6f88 ldr r1, [r4, #0x4] */
/* @0x2c6f8c ldr r4, [r4, #0xc] */
/* @0x2c6f90 ldr r2, [r1, #0x34] */
/* @0x2c6f94 ldr r3, [r1, #0x30] */
/* @0x2c6f98 cmp r5, r3 */
/* @0x2c6f9c cmpne r5, r2 */
/* @0x2c6fa0 bne 0x2c6f80 <_ZN6b2Body14DestroyFixtureEP9b2Fixture+0x5c> */
/* @0x2c6fa4 add r0, r7, #102400 */
/* @0x2c6fa8 add r0, r0, #472 */
/* @0x2c6fac bl 0x2c7894 <_ZN16b2ContactManager7DestroyEP9b2Contact> */
/* @0x2c6fb0 cmp r4, #0 */
/* @0x2c6fb4 ldr r7, [r6, #0x68] */
/* @0x2c6fb8 bne 0x2c6f88 <_ZN6b2Body14DestroyFixtureEP9b2Fixture+0x64> */
/* @0x2c6fbc ldrh r3, [r6, #4] */
/* @0x2c6fc0 tst r3, #32 */
/* @0x2c6fc4 bne 0x2c701c <_ZN6b2Body14DestroyFixtureEP9b2Fixture+0xf8> */
/* @0x2c6fc8 mov r0, r5 */
/* @0x2c6fcc mov r1, r7 */
/* @0x2c6fd0 bl 0x2c85f0 <_ZN9b2Fixture7DestroyEP16b2BlockAllocator> */
/* @0x2c6fd4 mov r3, #0 */
/* @0x2c6fd8 mov r0, r7 */
/* @0x2c6fdc str r3, [r5, #0x8] */
/* @0x2c6fe0 str r3, [r5, #0x4] */
/* @0x2c6fe4 mov r1, r5 */
/* @0x2c6fe8 mov r2, #52 */
/* @0x2c6fec bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2c6ff0 ldr r3, [r6, #0x78] */
/* @0x2c6ff4 mov r0, r6 */
/* @0x2c6ff8 sub r3, r3, #1 */
/* @0x2c6ffc str r3, [r6, #0x78] */
/* @0x2c7000 pop {r3, r4, r5, r6, r7, lr} */
/* @0x2c7004 b 0x2c6c00 <_ZN6b2Body13ResetMassDataEv> */
/* @0x2c7008 add r2, r2, #4 */
/* @0x2c700c ldr r3, [r5, #0x4] */
/* @0x2c7010 str r3, [r2] */
/* @0x2c7014 ldr r7, [r6, #0x68] */
/* @0x2c7018 b 0x2c6f7c <_ZN6b2Body14DestroyFixtureEP9b2Fixture+0x58> */
/* @0x2c701c add r1, r7, #102400 */
/* @0x2c7020 mov r0, r5 */
/* @0x2c7024 add r1, r1, #472 */
/* @0x2c7028 bl 0x2c8770 <_ZN9b2Fixture14DestroyProxiesEP12b2BroadPhase> */
/* @0x2c702c b 0x2c6fc8 <_ZN6b2Body14DestroyFixtureEP9b2Fixture+0xa4> */

/* ── FUNC 0x2c7030 · b2Body::SetMassData(b2MassData const*) · size=296 · insn=74 */
/* @0x2c7030 mov r3, r0 */
/* @0x2c7034 ldr r0, [r0, #0x68] */
/* @0x2c7038 movw r2, #0x91d4 */
/* @0x2c703c movt r2, #0x1 */
/* @0x2c7040 ldr r2, [r0, r2] */
/* @0x2c7044 tst r2, #2 */
/* @0x2c7048 bxne lr */
/* @0x2c704c ldr r2, [r3] */
/* @0x2c7050 cmp r2, #2 */
/* @0x2c7054 bxne lr */
/* @0x2c7058 vmov.f32 s14, #1.000000e+00 */
/* @0x2c705c vldr s15, [r1] */
/* @0x2c7060 mov r2, #0 */
/* @0x2c7064 str r2, [r3, #0x88] */
/* @0x2c7068 str r2, [r3, #0x8c] */
/* @0x2c706c str r2, [r3, #0x90] */
/* @0x2c7070 vcmpe.f32 s15, #0 */
/* @0x2c7074 vmrs APSR_nzcv, fpscr */
/* @0x2c7078 vstrhi s15, [r3, #132] */
/* @0x2c707c vmovhi.f32 s13, s15 */
/* @0x2c7080 vstrls s14, [r3, #132] */
/* @0x2c7084 vdivhi.f32 s15, s14, s15 */
/* @0x2c7088 vmovls.f32 s15, s14 */
/* @0x2c708c vldr s14, [r1, #12] */
/* @0x2c7090 vstr s15, [r3, #136] */
/* @0x2c7094 vcmpe.f32 s14, #0 */
/* @0x2c7098 vmovls.f32 s13, s15 */
/* @0x2c709c vmrs APSR_nzcv, fpscr */
/* @0x2c70a0 ble 0x2c70d4 <_ZN6b2Body11SetMassDataEPK10b2MassData+0xa4> */
/* @0x2c70a4 ldrh r2, [r3, #4] */
/* @0x2c70a8 tst r2, #16 */
/* @0x2c70ac bne 0x2c70d4 <_ZN6b2Body11SetMassDataEPK10b2MassData+0xa4> */
/* @0x2c70b0 vldr s15, [r1, #8] */
/* @0x2c70b4 vmul.f32 s15, s15, s15 */
/* @0x2c70b8 vldr s12, [r1, #4] */
/* @0x2c70bc vmla.f32 s15, s12, s12 */
/* @0x2c70c0 vmls.f32 s14, s15, s13 */
/* @0x2c70c4 vmov.f32 s15, #1.000000e+00 */
/* @0x2c70c8 vstr s14, [r3, #140] */
/* @0x2c70cc vdiv.f32 s14, s15, s14 */
/* @0x2c70d0 vstr s14, [r3, #144] */
/* @0x2c70d4 ldmib r1, {r0, r1} */
/* @0x2c70d8 add r2, r3, #44 */
/* @0x2c70dc vldr s11, [r3, #20] */
/* @0x2c70e0 vldr s7, [r3, #60] */
/* @0x2c70e4 vldr s8, [r3, #64] */
/* @0x2c70e8 vldr s9, [r3, #24] */
/* @0x2c70ec stm r2, {r0, r1} */
/* @0x2c70f0 vldr s15, [r3, #48] */
/* @0x2c70f4 vmul.f32 s14, s11, s15 */
/* @0x2c70f8 vldr s10, [r3, #44] */
/* @0x2c70fc vldr s6, [r3, #12] */
/* @0x2c7100 vldr s12, [r3, #16] */
/* @0x2c7104 add r1, r3, #60 */
/* @0x2c7108 add r2, r3, #52 */
/* @0x2c710c vldr s13, [r3, #88] */
/* @0x2c7110 vmul.f32 s15, s9, s15 */
/* @0x2c7114 vnmls.f32 s14, s9, s10 */
/* @0x2c7118 vmla.f32 s15, s10, s11 */
/* @0x2c711c vadd.f32 s14, s14, s6 */
/* @0x2c7120 vadd.f32 s12, s15, s12 */
/* @0x2c7124 vstr s14, [r3, #60] */
/* @0x2c7128 vstr s12, [r3, #64] */
/* @0x2c712c vsub.f32 s11, s14, s7 */
/* @0x2c7130 ldm r1, {r0, r1} */
/* @0x2c7134 stm r2, {r0, r1} */
/* @0x2c7138 vldr s15, [r3, #80] */
/* @0x2c713c vldr s14, [r3, #84] */
/* @0x2c7140 vsub.f32 s12, s12, s8 */
/* @0x2c7144 vmla.f32 s14, s13, s11 */
/* @0x2c7148 vmls.f32 s15, s13, s12 */
/* @0x2c714c vstr s14, [r3, #84] */
/* @0x2c7150 vstr s15, [r3, #80] */
/* @0x2c7154 bx lr */

/* ── FUNC 0x2c7158 · b2Body::ShouldCollide(b2Body const*) const · size=108 · insn=27 */
/* @0x2c7158 ldr r3, [r0] */
/* @0x2c715c cmp r3, #2 */
/* @0x2c7160 beq 0x2c7178 <_ZNK6b2Body13ShouldCollideEPKS_+0x20> */
/* @0x2c7164 ldr r3, [r1] */
/* @0x2c7168 cmp r3, #2 */
/* @0x2c716c beq 0x2c7178 <_ZNK6b2Body13ShouldCollideEPKS_+0x20> */
/* @0x2c7170 mov r0, #0 */
/* @0x2c7174 bx lr */
/* @0x2c7178 ldr r3, [r0, #0x7c] */
/* @0x2c717c cmp r3, #0 */
/* @0x2c7180 bne 0x2c7194 <_ZNK6b2Body13ShouldCollideEPKS_+0x3c> */
/* @0x2c7184 b 0x2c71bc <_ZNK6b2Body13ShouldCollideEPKS_+0x64> */
/* @0x2c7188 ldr r3, [r3, #0xc] */
/* @0x2c718c cmp r3, #0 */
/* @0x2c7190 beq 0x2c71bc <_ZNK6b2Body13ShouldCollideEPKS_+0x64> */
/* @0x2c7194 ldr r2, [r3] */
/* @0x2c7198 cmp r2, r1 */
/* @0x2c719c bne 0x2c7188 <_ZNK6b2Body13ShouldCollideEPKS_+0x30> */
/* @0x2c71a0 ldr r2, [r3, #0x4] */
/* @0x2c71a4 ldrb r0, [r2, #0x3d] */
/* @0x2c71a8 cmp r0, #0 */
/* @0x2c71ac bxeq lr */
/* @0x2c71b0 ldr r3, [r3, #0xc] */
/* @0x2c71b4 cmp r3, #0 */
/* @0x2c71b8 bne 0x2c7194 <_ZNK6b2Body13ShouldCollideEPKS_+0x3c> */
/* @0x2c71bc mov r0, #1 */
/* @0x2c71c0 bx lr */

/* ── FUNC 0x2c71c4 · b2Body::SetTransform(b2Vec2 const&, float) · size=264 · insn=66 */
/* @0x2c71c4 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2c71c8 vpush {d8} */
/* @0x2c71cc movw r3, #0x91d4 */
/* @0x2c71d0 ldr r7, [r0, #0x68] */
/* @0x2c71d4 movt r3, #0x1 */
/* @0x2c71d8 mov r6, r0 */
/* @0x2c71dc mov r4, r1 */
/* @0x2c71e0 mov r8, r2 */
/* @0x2c71e4 ldr r3, [r7, r3] */
/* @0x2c71e8 tst r3, #2 */
/* @0x2c71ec beq 0x2c71f8 <_ZN6b2Body12SetTransformERK6b2Vec2f+0x34> */
/* @0x2c71f0 vpop {d8} */
/* @0x2c71f4 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2c71f8 mov r0, r2 */
/* @0x2c71fc add r5, r6, #12 */
/* @0x2c7200 bl 0xb6580 <sinf@plt> */
/* @0x2c7204 add r10, r6, #60 */
/* @0x2c7208 add r9, r6, #52 */
/* @0x2c720c add r7, r7, #102400 */
/* @0x2c7210 add r7, r7, #472 */
/* @0x2c7214 vmov s16, r0 */
/* @0x2c7218 mov r0, r8 */
/* @0x2c721c vstr s16, [r6, #20] */
/* @0x2c7220 bl 0xb658c <cosf@plt> */
/* @0x2c7224 add r12, r6, #28 */
/* @0x2c7228 vmov s13, r0 */
/* @0x2c722c ldm r4, {r0, r1} */
/* @0x2c7230 vstr s13, [r6, #24] */
/* @0x2c7234 ldr r4, [r6, #0x74] */
/* @0x2c7238 stm r5, {r0, r1} */
/* @0x2c723c cmp r4, #0 */
/* @0x2c7240 ldm r5, {r0, r1, r2, r3} */
/* @0x2c7244 stm r12, {r0, r1, r2, r3} */
/* @0x2c7248 vldr s15, [r6, #48] */
/* @0x2c724c vmul.f32 s14, s15, s13 */
/* @0x2c7250 vldr s12, [r6, #44] */
/* @0x2c7254 vldr s10, [r6, #16] */
/* @0x2c7258 vldr s11, [r6, #12] */
/* @0x2c725c str r8, [r6, #0x48] */
/* @0x2c7260 vmul.f32 s15, s15, s16 */
/* @0x2c7264 vmla.f32 s14, s12, s16 */
/* @0x2c7268 vnmls.f32 s15, s12, s13 */
/* @0x2c726c vadd.f32 s14, s14, s10 */
/* @0x2c7270 vadd.f32 s15, s15, s11 */
/* @0x2c7274 vstr s14, [r6, #64] */
/* @0x2c7278 vstr s15, [r6, #60] */
/* @0x2c727c ldm r10, {r0, r1} */
/* @0x2c7280 stm r9, {r0, r1} */
/* @0x2c7284 str r8, [r6, #0x44] */
/* @0x2c7288 beq 0x2c72c4 <_ZN6b2Body12SetTransformERK6b2Vec2f+0x100> */
/* @0x2c728c mov r0, r4 */
/* @0x2c7290 mov r1, r7 */
/* @0x2c7294 mov r2, r5 */
/* @0x2c7298 mov r3, r5 */
/* @0x2c729c bl 0x2c87cc <_ZN9b2Fixture11SynchronizeEP12b2BroadPhaseRK11b2TransformS4_> */
/* @0x2c72a0 ldr r4, [r4, #0x4] */
/* @0x2c72a4 cmp r4, #0 */
/* @0x2c72a8 bne 0x2c728c <_ZN6b2Body12SetTransformERK6b2Vec2f+0xc8> */
/* @0x2c72ac ldr r0, [r6, #0x68] */
/* @0x2c72b0 add r0, r0, #102400 */
/* @0x2c72b4 add r0, r0, #472 */
/* @0x2c72b8 vpop {d8} */
/* @0x2c72bc pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2c72c0 b 0x2c84d8 <_ZN16b2ContactManager15FindNewContactsEv> */
/* @0x2c72c4 mov r0, r7 */
/* @0x2c72c8 b 0x2c72b8 <_ZN6b2Body12SetTransformERK6b2Vec2f+0xf4> */

/* ── FUNC 0x2c72cc · b2Body::SynchronizeFixtures() · size=172 · insn=43 */
/* @0x2c72cc push {r4, r5, r6, r7, lr} */
/* @0x2c72d0 vpush {d8} */
/* @0x2c72d4 mov r7, r0 */
/* @0x2c72d8 ldr r4, [r0, #0x44] */
/* @0x2c72dc sub sp, sp, #20 */
/* @0x2c72e0 mov r0, r4 */
/* @0x2c72e4 bl 0xb6580 <sinf@plt> */
/* @0x2c72e8 vmov s16, r0 */
/* @0x2c72ec mov r0, r4 */
/* @0x2c72f0 vstr s16, [sp, #8] */
/* @0x2c72f4 bl 0xb658c <cosf@plt> */
/* @0x2c72f8 vldr s15, [r7, #48] */
/* @0x2c72fc vmul.f32 s14, s15, s16 */
/* @0x2c7300 vldr s12, [r7, #44] */
/* @0x2c7304 vldr s11, [r7, #56] */
/* @0x2c7308 vldr s10, [r7, #52] */
/* @0x2c730c ldr r4, [r7, #0x74] */
/* @0x2c7310 ldr r5, [r7, #0x68] */
/* @0x2c7314 cmp r4, #0 */
/* @0x2c7318 add r5, r5, #102400 */
/* @0x2c731c add r5, r5, #472 */
/* @0x2c7320 vmov s13, r0 */
/* @0x2c7324 str r0, [sp, #0xc] */
/* @0x2c7328 vmul.f32 s15, s15, s13 */
/* @0x2c732c vnmls.f32 s14, s12, s13 */
/* @0x2c7330 vmla.f32 s15, s12, s16 */
/* @0x2c7334 vsub.f32 s14, s10, s14 */
/* @0x2c7338 vsub.f32 s15, s11, s15 */
/* @0x2c733c vstr s14, [sp] */
/* @0x2c7340 vstr s15, [sp, #4] */
/* @0x2c7344 beq 0x2c736c <_ZN6b2Body19SynchronizeFixturesEv+0xa0> */
/* @0x2c7348 add r7, r7, #12 */
/* @0x2c734c mov r0, r4 */
/* @0x2c7350 mov r1, r5 */
/* @0x2c7354 mov r2, sp */
/* @0x2c7358 mov r3, r7 */
/* @0x2c735c bl 0x2c87cc <_ZN9b2Fixture11SynchronizeEP12b2BroadPhaseRK11b2TransformS4_> */
/* @0x2c7360 ldr r4, [r4, #0x4] */
/* @0x2c7364 cmp r4, #0 */
/* @0x2c7368 bne 0x2c734c <_ZN6b2Body19SynchronizeFixturesEv+0x80> */
/* @0x2c736c add sp, sp, #20 */
/* @0x2c7370 vpop {d8} */
/* @0x2c7374 pop {r4, r5, r6, r7, pc} */

/* ── FUNC 0x2c7378 · b2Body::SetType(b2BodyType) · size=308 · insn=77 */
/* @0x2c7378 ldr r2, [r0, #0x68] */
/* @0x2c737c movw r3, #0x91d4 */
/* @0x2c7380 movt r3, #0x1 */
/* @0x2c7384 push {r4, r5, r6, r7, r8, lr} */
/* @0x2c7388 mov r5, r0 */
/* @0x2c738c ldr r3, [r2, r3] */
/* @0x2c7390 tst r3, #2 */
/* @0x2c7394 popne {r4, r5, r6, r7, r8, pc} */
/* @0x2c7398 ldr r3, [r0] */
/* @0x2c739c cmp r3, r1 */
/* @0x2c73a0 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x2c73a4 str r1, [r0] */
/* @0x2c73a8 bl 0x2c6c00 <_ZN6b2Body13ResetMassDataEv> */
/* @0x2c73ac ldr r3, [r5] */
/* @0x2c73b0 cmp r3, #0 */
/* @0x2c73b4 beq 0x2c7478 <_ZN6b2Body7SetTypeE10b2BodyType+0x100> */
/* @0x2c73b8 ldrh r3, [r5, #4] */
/* @0x2c73bc tst r3, #2 */
/* @0x2c73c0 orreq r3, r3, #2 */
/* @0x2c73c4 strheq r3, [r5, #4] */
/* @0x2c73c8 ldr r3, [r5, #0x80] */
/* @0x2c73cc moveq r2, #0 */
/* @0x2c73d0 streq r2, [r5, #0xa0] */
/* @0x2c73d4 mov r2, #0 */
/* @0x2c73d8 cmp r3, #0 */
/* @0x2c73dc str r2, [r5, #0x5c] */
/* @0x2c73e0 str r2, [r5, #0x60] */
/* @0x2c73e4 str r2, [r5, #0x64] */
/* @0x2c73e8 beq 0x2c7410 <_ZN6b2Body7SetTypeE10b2BodyType+0x98> */
/* @0x2c73ec ldr r0, [r5, #0x68] */
/* @0x2c73f0 ldr r4, [r3, #0xc] */
/* @0x2c73f4 add r0, r0, #102400 */
/* @0x2c73f8 ldr r1, [r3, #0x4] */
/* @0x2c73fc add r0, r0, #472 */
/* @0x2c7400 bl 0x2c7894 <_ZN16b2ContactManager7DestroyEP9b2Contact> */
/* @0x2c7404 cmp r4, #0 */
/* @0x2c7408 mov r3, r4 */
/* @0x2c740c bne 0x2c73ec <_ZN6b2Body7SetTypeE10b2BodyType+0x74> */
/* @0x2c7410 ldr r6, [r5, #0x74] */
/* @0x2c7414 mov r3, #0 */
/* @0x2c7418 ldr r8, [r5, #0x68] */
/* @0x2c741c cmp r6, r3 */
/* @0x2c7420 str r3, [r5, #0x80] */
/* @0x2c7424 add r8, r8, #102400 */
/* @0x2c7428 add r8, r8, #472 */
/* @0x2c742c popeq {r4, r5, r6, r7, r8, pc} */
/* @0x2c7430 ldr r7, [r6, #0x1c] */
/* @0x2c7434 cmp r7, #0 */
/* @0x2c7438 movgt r4, #0 */
/* @0x2c743c movgt r5, r4 */
/* @0x2c7440 ble 0x2c7468 <_ZN6b2Body7SetTypeE10b2BodyType+0xf0> */
/* @0x2c7444 ldr r3, [r6, #0x18] */
/* @0x2c7448 add r5, r5, #1 */
/* @0x2c744c mov r0, r8 */
/* @0x2c7450 add r3, r3, r4 */
/* @0x2c7454 add r4, r4, #28 */
/* @0x2c7458 ldr r1, [r3, #0x18] */
/* @0x2c745c bl 0x2dc8e0 <_ZN12b2BroadPhase10TouchProxyEi> */
/* @0x2c7460 cmp r5, r7 */
/* @0x2c7464 bne 0x2c7444 <_ZN6b2Body7SetTypeE10b2BodyType+0xcc> */
/* @0x2c7468 ldr r6, [r6, #0x4] */
/* @0x2c746c cmp r6, #0 */
/* @0x2c7470 bne 0x2c7430 <_ZN6b2Body7SetTypeE10b2BodyType+0xb8> */
/* @0x2c7474 pop {r4, r5, r6, r7, r8, pc} */
/* @0x2c7478 add r2, r5, #60 */
/* @0x2c747c mov r3, #0 */
/* @0x2c7480 str r3, [r5, #0x50] */
/* @0x2c7484 str r3, [r5, #0x54] */
/* @0x2c7488 ldm r2, {r0, r1} */
/* @0x2c748c add r2, r5, #52 */
/* @0x2c7490 str r3, [r5, #0x58] */
/* @0x2c7494 ldr r3, [r5, #0x48] */
/* @0x2c7498 str r3, [r5, #0x44] */
/* @0x2c749c stm r2, {r0, r1} */
/* @0x2c74a0 mov r0, r5 */
/* @0x2c74a4 bl 0x2c72cc <_ZN6b2Body19SynchronizeFixturesEv> */
/* @0x2c74a8 b 0x2c73b8 <_ZN6b2Body7SetTypeE10b2BodyType+0x40> */

/* ── FUNC 0x2c74ac · b2Body::SetActive(bool) · size=212 · insn=53 */
/* @0x2c74ac ldrh r3, [r0, #4] */
/* @0x2c74b0 push {r4, r5, r6, lr} */
/* @0x2c74b4 ubfx r2, r3, #0x5, #0x1 */
/* @0x2c74b8 cmp r1, r2 */
/* @0x2c74bc mov r5, r0 */
/* @0x2c74c0 popeq {r4, r5, r6, pc} */
/* @0x2c74c4 cmp r1, #0 */
/* @0x2c74c8 ldr r4, [r0, #0x74] */
/* @0x2c74cc beq 0x2c7510 <_ZN6b2Body9SetActiveEb+0x64> */
/* @0x2c74d0 ldr r6, [r0, #0x68] */
/* @0x2c74d4 cmp r4, #0 */
/* @0x2c74d8 orr r3, r3, #32 */
/* @0x2c74dc strh r3, [r0, #4] */
/* @0x2c74e0 add r6, r6, #102400 */
/* @0x2c74e4 add r6, r6, #472 */
/* @0x2c74e8 popeq {r4, r5, r6, pc} */
/* @0x2c74ec add r5, r0, #12 */
/* @0x2c74f0 mov r0, r4 */
/* @0x2c74f4 mov r1, r6 */
/* @0x2c74f8 mov r2, r5 */
/* @0x2c74fc bl 0x2c86e4 <_ZN9b2Fixture13CreateProxiesEP12b2BroadPhaseRK11b2Transform> */
/* @0x2c7500 ldr r4, [r4, #0x4] */
/* @0x2c7504 cmp r4, #0 */
/* @0x2c7508 bne 0x2c74f0 <_ZN6b2Body9SetActiveEb+0x44> */
/* @0x2c750c pop {r4, r5, r6, pc} */
/* @0x2c7510 ldr r6, [r0, #0x68] */
/* @0x2c7514 cmp r4, #0 */
/* @0x2c7518 bic r3, r3, #32 */
/* @0x2c751c strh r3, [r0, #4] */
/* @0x2c7520 add r6, r6, #102400 */
/* @0x2c7524 add r6, r6, #472 */
/* @0x2c7528 beq 0x2c7544 <_ZN6b2Body9SetActiveEb+0x98> */
/* @0x2c752c mov r0, r4 */
/* @0x2c7530 mov r1, r6 */
/* @0x2c7534 bl 0x2c8770 <_ZN9b2Fixture14DestroyProxiesEP12b2BroadPhase> */
/* @0x2c7538 ldr r4, [r4, #0x4] */
/* @0x2c753c cmp r4, #0 */
/* @0x2c7540 bne 0x2c752c <_ZN6b2Body9SetActiveEb+0x80> */
/* @0x2c7544 ldr r3, [r5, #0x80] */
/* @0x2c7548 cmp r3, #0 */
/* @0x2c754c beq 0x2c7574 <_ZN6b2Body9SetActiveEb+0xc8> */
/* @0x2c7550 ldr r0, [r5, #0x68] */
/* @0x2c7554 ldr r4, [r3, #0xc] */
/* @0x2c7558 add r0, r0, #102400 */
/* @0x2c755c ldr r1, [r3, #0x4] */
/* @0x2c7560 add r0, r0, #472 */
/* @0x2c7564 bl 0x2c7894 <_ZN16b2ContactManager7DestroyEP9b2Contact> */
/* @0x2c7568 cmp r4, #0 */
/* @0x2c756c mov r3, r4 */
/* @0x2c7570 bne 0x2c7550 <_ZN6b2Body9SetActiveEb+0xa4> */
/* @0x2c7574 mov r3, #0 */
/* @0x2c7578 str r3, [r5, #0x80] */
/* @0x2c757c pop {r4, r5, r6, pc} */

/* ── FUNC 0x2c7580 · b2Body::SetFixedRotation(bool) · size=52 · insn=13 */
/* @0x2c7580 ldrh r2, [r0, #4] */
/* @0x2c7584 mov r3, r0 */
/* @0x2c7588 ubfx r0, r2, #0x4, #0x1 */
/* @0x2c758c cmp r0, r1 */
/* @0x2c7590 bxeq lr */
/* @0x2c7594 cmp r1, #0 */
/* @0x2c7598 mov r0, r3 */
/* @0x2c759c orrne r2, r2, #16 */
/* @0x2c75a0 biceq r2, r2, #16 */
/* @0x2c75a4 strh r2, [r3, #4] */
/* @0x2c75a8 mov r2, #0 */
/* @0x2c75ac str r2, [r3, #0x58] */
/* @0x2c75b0 b 0x2c6c00 <_ZN6b2Body13ResetMassDataEv> */

/* ── FUNC 0x2c75b4 · b2Body::Dump() · size=544 · insn=136 */
/* @0x2c75b4 push {r4, r5, r6, r7, lr} */
/* @0x2c75b8 mov r4, r0 */
/* @0x2c75bc ldr r0, [pc, #0x1c0] */
/* @0x2c75c0 sub sp, sp, #12 */
/* @0x2c75c4 ldr r5, [r4, #0x8] */
/* @0x2c75c8 add r0, pc, r0 */
/* @0x2c75cc ldr r7, [pc, #0x1b4] */
/* @0x2c75d0 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c75d4 ldr r0, [pc, #0x1b0] */
/* @0x2c75d8 ldr r6, [pc, #0x1b0] */
/* @0x2c75dc add r7, pc, r7 */
/* @0x2c75e0 add r0, pc, r0 */
/* @0x2c75e4 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c75e8 ldr r0, [pc, #0x1a4] */
/* @0x2c75ec ldr r1, [r4] */
/* @0x2c75f0 add r6, pc, r6 */
/* @0x2c75f4 add r0, pc, r0 */
/* @0x2c75f8 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c75fc vldr s13, [r4, #12] */
/* @0x2c7600 vldr s14, [r4, #16] */
/* @0x2c7604 vcvt.f64.f32 d5, s13 */
/* @0x2c7608 ldr r0, [pc, #0x188] */
/* @0x2c760c add r0, pc, r0 */
/* @0x2c7610 vcvt.f64.f32 d7, s14 */
/* @0x2c7614 vmov r2, r3, d5 */
/* @0x2c7618 vstr d7, [sp] */
/* @0x2c761c bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c7620 vldr s15, [r4, #72] */
/* @0x2c7624 vcvt.f64.f32 d6, s15 */
/* @0x2c7628 ldr r0, [pc, #0x16c] */
/* @0x2c762c add r0, pc, r0 */
/* @0x2c7630 vmov r2, r3, d6 */
/* @0x2c7634 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c7638 vldr s13, [r4, #80] */
/* @0x2c763c vldr s14, [r4, #84] */
/* @0x2c7640 vcvt.f64.f32 d5, s13 */
/* @0x2c7644 ldr r0, [pc, #0x154] */
/* @0x2c7648 add r0, pc, r0 */
/* @0x2c764c vcvt.f64.f32 d7, s14 */
/* @0x2c7650 vmov r2, r3, d5 */
/* @0x2c7654 vstr d7, [sp] */
/* @0x2c7658 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c765c vldr s15, [r4, #88] */
/* @0x2c7660 vcvt.f64.f32 d6, s15 */
/* @0x2c7664 ldr r0, [pc, #0x138] */
/* @0x2c7668 add r0, pc, r0 */
/* @0x2c766c vmov r2, r3, d6 */
/* @0x2c7670 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c7674 vldr s15, [r4, #148] */
/* @0x2c7678 vcvt.f64.f32 d5, s15 */
/* @0x2c767c ldr r0, [pc, #0x124] */
/* @0x2c7680 add r0, pc, r0 */
/* @0x2c7684 vmov r2, r3, d5 */
/* @0x2c7688 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c768c vldr s15, [r4, #152] */
/* @0x2c7690 vcvt.f64.f32 d6, s15 */
/* @0x2c7694 ldr r0, [pc, #0x110] */
/* @0x2c7698 add r0, pc, r0 */
/* @0x2c769c vmov r2, r3, d6 */
/* @0x2c76a0 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c76a4 ldrh r1, [r4, #4] */
/* @0x2c76a8 ldr r0, [pc, #0x100] */
/* @0x2c76ac and r1, r1, #4 */
/* @0x2c76b0 add r0, pc, r0 */
/* @0x2c76b4 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c76b8 ldrh r1, [r4, #4] */
/* @0x2c76bc ldr r0, [pc, #0xf0] */
/* @0x2c76c0 and r1, r1, #2 */
/* @0x2c76c4 add r0, pc, r0 */
/* @0x2c76c8 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c76cc ldrh r1, [r4, #4] */
/* @0x2c76d0 ldr r0, [pc, #0xe0] */
/* @0x2c76d4 and r1, r1, #16 */
/* @0x2c76d8 add r0, pc, r0 */
/* @0x2c76dc bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c76e0 ldrh r1, [r4, #4] */
/* @0x2c76e4 ldr r0, [pc, #0xd0] */
/* @0x2c76e8 and r1, r1, #8 */
/* @0x2c76ec add r0, pc, r0 */
/* @0x2c76f0 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c76f4 ldrh r1, [r4, #4] */
/* @0x2c76f8 ldr r0, [pc, #0xc0] */
/* @0x2c76fc and r1, r1, #32 */
/* @0x2c7700 add r0, pc, r0 */
/* @0x2c7704 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c7708 vldr s15, [r4, #156] */
/* @0x2c770c vcvt.f64.f32 d5, s15 */
/* @0x2c7710 ldr r0, [pc, #0xac] */
/* @0x2c7714 add r0, pc, r0 */
/* @0x2c7718 vmov r2, r3, d5 */
/* @0x2c771c bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c7720 ldr r0, [pc, #0xa0] */
/* @0x2c7724 ldr r1, [r4, #0x8] */
/* @0x2c7728 add r0, pc, r0 */
/* @0x2c772c bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c7730 ldr r0, [pc, #0x94] */
/* @0x2c7734 add r0, pc, r0 */
/* @0x2c7738 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c773c ldr r4, [r4, #0x74] */
/* @0x2c7740 cmp r4, #0 */
/* @0x2c7744 beq 0x2c7770 <_ZN6b2Body4DumpEv+0x1bc> */
/* @0x2c7748 mov r0, r7 */
/* @0x2c774c bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c7750 mov r0, r4 */
/* @0x2c7754 mov r1, r5 */
/* @0x2c7758 bl 0x2c89f4 <_ZN9b2Fixture4DumpEi> */
/* @0x2c775c mov r0, r6 */
/* @0x2c7760 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c7764 ldr r4, [r4, #0x4] */
/* @0x2c7768 cmp r4, #0 */
/* @0x2c776c bne 0x2c7748 <_ZN6b2Body4DumpEv+0x194> */
/* @0x2c7770 ldr r0, [pc, #0x58] */
/* @0x2c7774 add r0, pc, r0 */
/* @0x2c7778 add sp, sp, #12 */
/* @0x2c777c pop {r4, r5, r6, r7, lr} */
/* @0x2c7780 b 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c7784 andeq r4, r9, r8, lsl #3 */
/* @0x2c7788 andeq r4, r9, r12, asr r3 */
/* @0x2c778c andeq r4, r9, r4, ror r1 */
/* @0x2c7790 andeq r4, r9, r0, asr r3 */
/* @0x2c7794 andeq r4, r9, r4, ror r1 */
/* @0x2c7798 andeq r4, r9, r12, ror r1 */
/* @0x2c779c andeq r4, r9, r4, lsl #3 */
/* @0x2c77a0 andeq r4, r9, r0, lsl #3 */
/* @0x2c77a4 andeq r4, r9, r12, lsl #3 */
/* @0x2c77a8 muleq r9, r8, r1 */
/* @0x2c77ac andeq r4, r9, r0, lsr #3 */
/* @0x2c77b0 andeq r4, r9, r8, lsr #3 */
/* @0x2c77b4 strheq r4, [r9], -r4 */
/* @0x2c77b8 strheq r4, [r9], -r8 */
/* @0x2c77bc andeq r4, r9, r4, asr #3 */
/* @0x2c77c0 andeq r4, r9, r12, asr #3 */
/* @0x2c77c4 ldrdeq r4, r5, [r9], -r4 */
/* @0x2c77c8 andeq r4, r9, r0, ror #3 */
/* @0x2c77cc andeq r11, r6, r4, ror #10 */
/* @0x2c77d0 andeq r4, r9, r0, asr #3 */

/* ── FUNC 0x2c77d4 · b2PairLessThan(b2Pair const&, b2Pair const&) · size=60 · insn=15 */
/* @0x2c77d4 ldr r2, [r0] */
/* @0x2c77d8 ldr r3, [r1] */
/* @0x2c77dc cmp r2, r3 */
/* @0x2c77e0 blt 0x2c7808 <_Z14b2PairLessThanRK6b2PairS1_+0x34> */
/* @0x2c77e4 beq 0x2c77f0 <_Z14b2PairLessThanRK6b2PairS1_+0x1c> */
/* @0x2c77e8 mov r0, #0 */
/* @0x2c77ec bx lr */
/* @0x2c77f0 ldr r0, [r0, #0x4] */
/* @0x2c77f4 ldr r3, [r1, #0x4] */
/* @0x2c77f8 cmp r0, r3 */
/* @0x2c77fc movge r0, #0 */
/* @0x2c7800 movlt r0, #1 */
/* @0x2c7804 bx lr */
/* @0x2c7808 mov r0, #1 */
/* @0x2c780c bx lr */

/* ── FUNC 0x2c7810 · b2ContactFilter::~b2ContactFilter() · size=24 · insn=6 */
/* @0x2c7810 ldr r3, [pc, #0xc] */
/* @0x2c7814 ldr r3, [pc, r3] */
/* @0x2c7818 add r3, r3, #8 */
/* @0x2c781c str r3, [r0] */
/* @0x2c7820 bx lr */
/* @0x2c7824 andseq r10, r2, r12, asr #5 */
