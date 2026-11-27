/* libyoyo.so 覆盖卡组 0140
 * 函数 0x1a8750..0x1a8b50，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1a8750 · RomDisk::LoadTexture(int) · size=64 · insn=16 */
/* @0x1a8750 push {r4, r5, lr} */
/* @0x1a8754 sub sp, sp, #44 */
/* @0x1a8758 mov r5, r0 */
/* @0x1a875c bl 0x1a86fc <_ZN7RomDisk4LoadEi> */
/* @0x1a8760 mov r4, r0 */
/* @0x1a8764 mov r0, r5 */
/* @0x1a8768 bl 0x1a8728 <_ZN7RomDisk4SizeEi> */
/* @0x1a876c mov r3, #1 */
/* @0x1a8770 add r2, sp, #12 */
/* @0x1a8774 str r3, [sp] */
/* @0x1a8778 mov r3, #0 */
/* @0x1a877c mov r1, r0 */
/* @0x1a8780 mov r0, r4 */
/* @0x1a8784 bl 0x182f3c <_ZN8Graphics21CreateTextureFromFileEPhjP9ImageInfo14eTextureFormatb> */
/* @0x1a8788 add sp, sp, #44 */
/* @0x1a878c pop {r4, r5, pc} */

/* ── FUNC 0x1a8790 · RomDisk::MemoryInRomDisk(void*) · size=92 · insn=23 */
/* @0x1a8790 ldr r3, [pc, #0x4c] */
/* @0x1a8794 asr r1, r0, #31 */
/* @0x1a8798 ldr r12, [pc, #0x48] */
/* @0x1a879c ldr r3, [pc, r3] */
/* @0x1a87a0 ldr r12, [pc, r12] */
/* @0x1a87a4 ldr r2, [r3] */
/* @0x1a87a8 ldr r12, [r12] */
/* @0x1a87ac push {r4, r5} */
/* @0x1a87b0 asr r3, r2, #31 */
/* @0x1a87b4 adds r4, r2, r12 */
/* @0x1a87b8 adc r5, r3, #0 */
/* @0x1a87bc cmp r1, r5 */
/* @0x1a87c0 cmpeq r0, r4 */
/* @0x1a87c4 pop {r4, r5} */
/* @0x1a87c8 movhs r12, #0 */
/* @0x1a87cc movlo r12, #1 */
/* @0x1a87d0 cmp r1, r3 */
/* @0x1a87d4 cmpeq r0, r2 */
/* @0x1a87d8 movlo r0, #0 */
/* @0x1a87dc andhs r0, r12, #1 */
/* @0x1a87e0 bx lr */
/* @0x1a87e4 eoreq r8, r4, r4, asr #32 */
/* @0x1a87e8 eoreq r8, r4, r12, lsr r0 */

/* ── FUNC 0x1a87ec · TFont::~TFont() · size=72 · insn=18 */
/* @0x1a87ec ldr r3, [pc, #0x38] */
/* @0x1a87f0 push {r4, lr} */
/* @0x1a87f4 ldr r3, [pc, r3] */
/* @0x1a87f8 mov r4, r0 */
/* @0x1a87fc add r3, r3, #8 */
/* @0x1a8800 ldr r0, [r0, #0x8] */
/* @0x1a8804 str r3, [r4] */
/* @0x1a8808 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1a880c ldr r3, [pc, #0x1c] */
/* @0x1a8810 mov r2, #0 */
/* @0x1a8814 mov r0, r4 */
/* @0x1a8818 ldr r3, [pc, r3] */
/* @0x1a881c str r2, [r4, #0x8] */
/* @0x1a8820 add r3, r3, #8 */
/* @0x1a8824 str r3, [r4] */
/* @0x1a8828 pop {r4, pc} */
/* @0x1a882c eoreq r7, r4, r4, ror #31 */
/* @0x1a8830 .word 0x00247fbc */

/* ── FUNC 0x1a87ec · TFont::~TFont() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1a8834 · TFont::~TFont() · size=28 · insn=7 */
/* @0x1a8834 push {r4, lr} */
/* @0x1a8838 mov r4, r0 */
/* @0x1a883c bl 0x1a87ec <_ZN5TFontD2Ev> */
/* @0x1a8840 mov r0, r4 */
/* @0x1a8844 bl 0x27d1d0 <_ZdlPv> */
/* @0x1a8848 mov r0, r4 */
/* @0x1a884c pop {r4, pc} */

/* ── FUNC 0x1a8850 · TFont::Create() · size=4 · insn=1 */
/* @0x1a8850 bx lr */

/* ── FUNC 0x1a8854 · CreateDesktopWindow(int, int) · size=108 · insn=27 */
/* @0x1a8854 ldr r3, [pc, #0x4c] */
/* @0x1a8858 mov r2, #0 */
/* @0x1a885c ldr r12, [pc, #0x48] */
/* @0x1a8860 add r3, pc, r3 */
/* @0x1a8864 push {r4, r5, r6, r7} */
/* @0x1a8868 ldr r6, [pc, #0x40] */
/* @0x1a886c ldr r7, [r3, r12] */
/* @0x1a8870 ldr r5, [pc, #0x3c] */
/* @0x1a8874 ldr r4, [pc, #0x3c] */
/* @0x1a8878 str r2, [r7] */
/* @0x1a887c ldr r6, [r3, r6] */
/* @0x1a8880 ldr r12, [pc, #0x34] */
/* @0x1a8884 str r2, [r6] */
/* @0x1a8888 ldr r5, [r3, r5] */
/* @0x1a888c str r0, [r5] */
/* @0x1a8890 ldr r0, [r3, r4] */
/* @0x1a8894 pop {r4, r5, r6, r7} */
/* @0x1a8898 str r1, [r0] */
/* @0x1a889c ldr r3, [r3, r12] */
/* @0x1a88a0 str r2, [r3] */
/* @0x1a88a4 bx lr */
/* @0x1a88a8 .word 0x002493f0 */
/* @0x1a88ac .word 0xffffeb94 */
/* @0x1a88b0 .word 0xffffeb98 */
/* @0x1a88b4 .word 0xffffeb9c */
/* @0x1a88b8 .word 0xffffeba0 */
/* @0x1a88bc .word 0xffffeba4 */

/* ── FUNC 0x1a88c0 · yyDestroyWindow(void*) · size=4 · insn=1 */
/* @0x1a88c0 bx lr */

/* ── FUNC 0x1a88c4 · IBitmap::~IBitmap() · size=24 · insn=6 */
/* @0x1a88c4 ldr r3, [pc, #0xc] */
/* @0x1a88c8 ldr r3, [pc, r3] */
/* @0x1a88cc add r3, r3, #8 */
/* @0x1a88d0 str r3, [r0] */
/* @0x1a88d4 bx lr */
/* @0x1a88d8 eoreq r7, r4, r0, lsr pc */

/* ── FUNC 0x1a88c4 · IBitmap::~IBitmap() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1a88dc · IBitmapLoader::~IBitmapLoader() · size=24 · insn=6 */
/* @0x1a88dc ldr r3, [pc, #0xc] */
/* @0x1a88e0 ldr r3, [pc, r3] */
/* @0x1a88e4 add r3, r3, #8 */
/* @0x1a88e8 str r3, [r0] */
/* @0x1a88ec bx lr */
/* @0x1a88f0 eoreq r7, r4, r12, lsl pc */

/* ── FUNC 0x1a88dc · IBitmapLoader::~IBitmapLoader() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1a88f4 · TBitmap::GetNative() · size=8 · insn=2 */
/* @0x1a88f4 ldr r0, [r0, #0x8] */
/* @0x1a88f8 bx lr */

/* ── FUNC 0x1a88fc · TBitmap::SetDIB(SDIB*, int) · size=64 · insn=16 */
/* @0x1a88fc ldr r3, [r1, #0x10] */
/* @0x1a8900 mov r12, #7 */
/* @0x1a8904 push {r4, r5, r6} */
/* @0x1a8908 ldr r5, [r1, #0x14] */
/* @0x1a890c lsl r4, r3, #2 */
/* @0x1a8910 ldr r6, [r1, #0x8] */
/* @0x1a8914 str r1, [r0, #0x4] */
/* @0x1a8918 str r5, [r0, #0x1c] */
/* @0x1a891c add r1, r1, r6 */
/* @0x1a8920 str r4, [r0, #0x20] */
/* @0x1a8924 str r2, [r0, #0x10] */
/* @0x1a8928 str r1, [r0, #0xc] */
/* @0x1a892c str r3, [r0, #0x18] */
/* @0x1a8930 str r12, [r0, #0x14] */
/* @0x1a8934 pop {r4, r5, r6} */
/* @0x1a8938 bx lr */

/* ── FUNC 0x1a893c · TBitmap::GetPixelFormat() · size=8 · insn=2 */
/* @0x1a893c ldr r0, [r0, #0x14] */
/* @0x1a8940 bx lr */

/* ── FUNC 0x1a8944 · TBitmap::GetWidth() · size=8 · insn=2 */
/* @0x1a8944 ldr r0, [r0, #0x18] */
/* @0x1a8948 bx lr */

/* ── FUNC 0x1a894c · TBitmap::GetHeight() · size=8 · insn=2 */
/* @0x1a894c ldr r0, [r0, #0x1c] */
/* @0x1a8950 bx lr */

/* ── FUNC 0x1a8954 · TBitmap::UnlockBits(void*) · size=4 · insn=1 */
/* @0x1a8954 bx lr */

/* ── FUNC 0x1a8958 · BitmapLoader::Animated() · size=8 · insn=2 */
/* @0x1a8958 mov r0, #0 */
/* @0x1a895c bx lr */

/* ── FUNC 0x1a8960 · BitmapLoader::GetFrameCount() · size=8 · insn=2 */
/* @0x1a8960 ldr r0, [r0, #0x8] */
/* @0x1a8964 bx lr */

/* ── FUNC 0x1a8968 · IBitmap::~IBitmap() · size=40 · insn=10 */
/* @0x1a8968 ldr r3, [pc, #0x1c] */
/* @0x1a896c push {r4, lr} */
/* @0x1a8970 ldr r3, [pc, r3] */
/* @0x1a8974 mov r4, r0 */
/* @0x1a8978 add r3, r3, #8 */
/* @0x1a897c str r3, [r0] */
/* @0x1a8980 bl 0x27d1d0 <_ZdlPv> */
/* @0x1a8984 mov r0, r4 */
/* @0x1a8988 pop {r4, pc} */
/* @0x1a898c eoreq r7, r4, r8, lsl #29 */

/* ── FUNC 0x1a8990 · IBitmapLoader::~IBitmapLoader() · size=40 · insn=10 */
/* @0x1a8990 ldr r3, [pc, #0x1c] */
/* @0x1a8994 push {r4, lr} */
/* @0x1a8998 ldr r3, [pc, r3] */
/* @0x1a899c mov r4, r0 */
/* @0x1a89a0 add r3, r3, #8 */
/* @0x1a89a4 str r3, [r0] */
/* @0x1a89a8 bl 0x27d1d0 <_ZdlPv> */
/* @0x1a89ac mov r0, r4 */
/* @0x1a89b0 pop {r4, pc} */
/* @0x1a89b4 eoreq r7, r4, r4, ror #28 */

/* ── FUNC 0x1a89b8 · TBitmap::LockBits(int, void**, int*) · size=140 · insn=35 */
/* @0x1a89b8 ldr r12, [r0, #0x4] */
/* @0x1a89bc push {r3, r4, r5, r6, r7, lr} */
/* @0x1a89c0 cmp r12, #0 */
/* @0x1a89c4 mov r4, r0 */
/* @0x1a89c8 mov r7, r1 */
/* @0x1a89cc mov r5, r2 */
/* @0x1a89d0 mov r6, r3 */
/* @0x1a89d4 beq 0x1a8a00 <_ZN7TBitmap8LockBitsEiPPvPi+0x48> */
/* @0x1a89d8 ldr r0, [r0, #0xc] */
/* @0x1a89dc cmp r6, #0 */
/* @0x1a89e0 ldrne r3, [r4, #0x20] */
/* @0x1a89e4 strne r3, [r6] */
/* @0x1a89e8 cmp r5, #0 */
/* @0x1a89ec ldrne r3, [r4, #0x20] */
/* @0x1a89f0 mlane r0, r3, r7, r0 */
/* @0x1a89f4 strne r0, [r5] */
/* @0x1a89f8 ldrne r0, [r4, #0xc] */
/* @0x1a89fc pop {r3, r4, r5, r6, r7, pc} */
/* @0x1a8a00 ldr r0, [r0, #0x20] */
/* @0x1a8a04 movw r2, #0x131 */
/* @0x1a8a08 ldr r12, [r4, #0x1c] */
/* @0x1a8a0c mov r3, #1 */
/* @0x1a8a10 ldr r1, [pc, #0x28] */
/* @0x1a8a14 mul r0, r12, r0 */
/* @0x1a8a18 add r1, pc, r1 */
/* @0x1a8a1c add r0, r0, #52 */
/* @0x1a8a20 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1a8a24 mov r2, #52 */
/* @0x1a8a28 mov r3, r0 */
/* @0x1a8a2c str r0, [r4, #0x4] */
/* @0x1a8a30 add r0, r0, r2 */
/* @0x1a8a34 str r0, [r4, #0xc] */
/* @0x1a8a38 str r2, [r3, #0x8] */
/* @0x1a8a3c b 0x1a89dc <_ZN7TBitmap8LockBitsEiPPvPi+0x24> */
/* @0x1a8a40 andseq r4, r10, r12, asr r7 */

/* ── FUNC 0x1a8a44 · TBitmap::Clear() · size=48 · insn=12 */
/* @0x1a8a44 push {r4, lr} */
/* @0x1a8a48 mov r4, r0 */
/* @0x1a8a4c ldr r0, [r0, #0x4] */
/* @0x1a8a50 cmp r0, #0 */
/* @0x1a8a54 beq 0x1a8a5c <_ZN7TBitmap5ClearEv+0x18> */
/* @0x1a8a58 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1a8a5c ldr r3, [r4, #0x28] */
/* @0x1a8a60 mov r2, #0 */
/* @0x1a8a64 str r2, [r4, #0x4] */
/* @0x1a8a68 add r3, r3, #1 */
/* @0x1a8a6c str r3, [r4, #0x28] */
/* @0x1a8a70 pop {r4, pc} */

/* ── FUNC 0x1a8a74 · TBitmap::~TBitmap() · size=60 · insn=15 */
/* @0x1a8a74 ldr r3, [pc, #0x2c] */
/* @0x1a8a78 push {r4, lr} */
/* @0x1a8a7c ldr r3, [pc, r3] */
/* @0x1a8a80 add r3, r3, #8 */
/* @0x1a8a84 str r3, [r0] */
/* @0x1a8a88 mov r4, r0 */
/* @0x1a8a8c bl 0x1a8a44 <_ZN7TBitmap5ClearEv> */
/* @0x1a8a90 ldr r3, [pc, #0x14] */
/* @0x1a8a94 mov r0, r4 */
/* @0x1a8a98 ldr r3, [pc, r3] */
/* @0x1a8a9c add r3, r3, #8 */
/* @0x1a8aa0 str r3, [r4] */
/* @0x1a8aa4 pop {r4, pc} */
/* @0x1a8aa8 eoreq r7, r4, r4, lsl #27 */
/* @0x1a8aac eoreq r7, r4, r0, ror #26 */

/* ── FUNC 0x1a8a74 · TBitmap::~TBitmap() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1a8ab0 · TBitmap::~TBitmap() · size=28 · insn=7 */
/* @0x1a8ab0 push {r4, lr} */
/* @0x1a8ab4 mov r4, r0 */
/* @0x1a8ab8 bl 0x1a8a74 <_ZN7TBitmapD2Ev> */
/* @0x1a8abc mov r0, r4 */
/* @0x1a8ac0 bl 0x27d1d0 <_ZdlPv> */
/* @0x1a8ac4 mov r0, r4 */
/* @0x1a8ac8 pop {r4, pc} */

/* ── FUNC 0x1a8acc · BitmapLoader::~BitmapLoader() · size=64 · insn=16 */
/* @0x1a8acc ldr r3, [pc, #0x30] */
/* @0x1a8ad0 push {r4, lr} */
/* @0x1a8ad4 ldr r3, [pc, r3] */
/* @0x1a8ad8 mov r4, r0 */
/* @0x1a8adc add r3, r3, #8 */
/* @0x1a8ae0 ldr r0, [r0, #0x4] */
/* @0x1a8ae4 str r3, [r4] */
/* @0x1a8ae8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1a8aec ldr r3, [pc, #0x14] */
/* @0x1a8af0 mov r0, r4 */
/* @0x1a8af4 ldr r3, [pc, r3] */
/* @0x1a8af8 add r3, r3, #8 */
/* @0x1a8afc str r3, [r4] */
/* @0x1a8b00 pop {r4, pc} */
/* @0x1a8b04 eoreq r7, r4, r0, lsr sp */
/* @0x1a8b08 eoreq r7, r4, r8, lsl #26 */

/* ── FUNC 0x1a8acc · BitmapLoader::~BitmapLoader() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1a8b0c · BitmapLoader::~BitmapLoader() · size=28 · insn=7 */
/* @0x1a8b0c push {r4, lr} */
/* @0x1a8b10 mov r4, r0 */
/* @0x1a8b14 bl 0x1a8acc <_ZN12BitmapLoaderD2Ev> */
/* @0x1a8b18 mov r0, r4 */
/* @0x1a8b1c bl 0x27d1d0 <_ZdlPv> */
/* @0x1a8b20 mov r0, r4 */
/* @0x1a8b24 pop {r4, pc} */

/* ── FUNC 0x1a8b28 · GetTPixelFormat(int) · size=40 · insn=10 */
/* @0x1a8b28 sub r0, r0, #1 */
/* @0x1a8b2c cmp r0, #23 */
/* @0x1a8b30 bhi 0x1a8b44 <_Z15GetTPixelFormati+0x1c> */
/* @0x1a8b34 ldr r3, [pc, #0x10] */
/* @0x1a8b38 add r3, pc, r3 */
/* @0x1a8b3c ldr r0, [r3, r0, lsl #2] */
/* @0x1a8b40 bx lr */
/* @0x1a8b44 mov r0, #7 */
/* @0x1a8b48 bx lr */
/* @0x1a8b4c ldrsheq r5, [r11], -r8 */

/* ── FUNC 0x1a8b50 · TBitmap::TBitmap() · size=60 · insn=15 */
/* @0x1a8b50 ldr r1, [pc, #0x30] */
/* @0x1a8b54 mov r2, #0 */
/* @0x1a8b58 mov r12, #7 */
/* @0x1a8b5c str r2, [r0, #0x8] */
/* @0x1a8b60 ldr r1, [pc, r1] */
/* @0x1a8b64 str r12, [r0, #0x14] */
/* @0x1a8b68 add r1, r1, #8 */
/* @0x1a8b6c str r2, [r0, #0x18] */
/* @0x1a8b70 stm r0, {r1, r2} */
/* @0x1a8b74 mvn r1, #0 */
/* @0x1a8b78 str r2, [r0, #0x1c] */
/* @0x1a8b7c str r1, [r0, #0x24] */
/* @0x1a8b80 str r1, [r0, #0x28] */
/* @0x1a8b84 bx lr */
/* @0x1a8b88 eoreq r7, r4, r0, lsr #25 */
