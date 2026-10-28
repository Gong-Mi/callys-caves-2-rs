/* libyoyo.so 覆盖卡组 0117
 * 函数 0x17daa8..0x17e0dc，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x17daa8 · InvalidateOGLResources() · size=84 · insn=21 */
/* @0x17daa8 push {r4, lr} */
/* @0x17daac bl 0x183d30 <_Z26FreeVertexBuilderResourcesv> */
/* @0x17dab0 ldr r3, [pc, #0x3c] */
/* @0x17dab4 ldr r3, [pc, r3] */
/* @0x17dab8 ldr r3, [r3] */
/* @0x17dabc cmp r3, #1 */
/* @0x17dac0 beq 0x17daec <_Z22InvalidateOGLResourcesv+0x44> */
/* @0x17dac4 ldr r4, [pc, #0x2c] */
/* @0x17dac8 bl 0x181190 <_Z20FreeTextureResourcesv> */
/* @0x17dacc mov r3, #1 */
/* @0x17dad0 ldr r4, [pc, r4] */
/* @0x17dad4 mov r0, r3 */
/* @0x17dad8 strb r3, [r4] */
/* @0x17dadc bl 0x1767d0 <_ZN8Graphics12TextureFlushEb> */
/* @0x17dae0 mov r3, #0 */
/* @0x17dae4 strb r3, [r4] */
/* @0x17dae8 pop {r4, pc} */
/* @0x17daec bl 0x187fa8 <_Z26FreeShaderManagerResourcesv> */
/* @0x17daf0 b 0x17dac4 <_Z22InvalidateOGLResourcesv+0x1c> */
/* @0x17daf4 eoreq r2, r7, r4, asr r9 */
/* @0x17daf8 eoreq r2, r7, r12, ror #18 */

/* ── FUNC 0x17dafc · DeleteOGLResources() · size=16 · insn=4 */
/* @0x17dafc push {r3, lr} */
/* @0x17db00 bl 0x183d34 <_Z28DeleteVertexBuilderResourcesv> */
/* @0x17db04 pop {r3, lr} */
/* @0x17db08 b 0x18639c <_Z28DeleteShaderManagerResourcesv> */

/* ── FUNC 0x17db0c · Graphics::SetVSync(bool) · size=20 · insn=5 */
/* @0x17db0c ldr r3, [pc, #0x8] */
/* @0x17db10 ldr r3, [pc, r3] */
/* @0x17db14 strb r0, [r3] */
/* @0x17db18 bx lr */
/* @0x17db1c eoreq r2, r7, r0, lsr r9 */

/* ── FUNC 0x17db20 · Graphics::SetMultiSample(int) · size=4 · insn=1 */
/* @0x17db20 bx lr */

/* ── FUNC 0x17db24 · Graphics_DisplayWidth() · size=20 · insn=5 */
/* @0x17db24 ldr r3, [pc, #0x8] */
/* @0x17db28 ldr r3, [pc, r3] */
/* @0x17db2c ldr r0, [r3] */
/* @0x17db30 bx lr */
/* @0x17db34 eoreq r2, r7, r4, ror r3 */

/* ── FUNC 0x17db38 · Graphics_DisplayHeight() · size=20 · insn=5 */
/* @0x17db38 ldr r3, [pc, #0x8] */
/* @0x17db3c ldr r3, [pc, r3] */
/* @0x17db40 ldr r0, [r3] */
/* @0x17db44 bx lr */
/* @0x17db48 eoreq r2, r7, r4, ror #6 */

/* ── FUNC 0x17db4c · DisplayFrequency() · size=8 · insn=2 */
/* @0x17db4c mov r0, #60 */
/* @0x17db50 bx lr */

/* ── FUNC 0x17db54 · DisplayColorDepth() · size=8 · insn=2 */
/* @0x17db54 mov r0, #32 */
/* @0x17db58 bx lr */

/* ── FUNC 0x17db5c · DisplayTest(int, int, int, int) · size=8 · insn=2 */
/* @0x17db5c mov r0, #1 */
/* @0x17db60 bx lr */

/* ── FUNC 0x17db64 · DisplaySet(int, int, int, int) · size=8 · insn=2 */
/* @0x17db64 mov r0, #1 */
/* @0x17db68 bx lr */

/* ── FUNC 0x17db6c · DisplaySetSize(int, int) · size=12 · insn=3 */
/* @0x17db6c mov r2, #0 */
/* @0x17db70 mov r3, r2 */
/* @0x17db74 b 0x17db64 <_Z10DisplaySetiiii> */

/* ── FUNC 0x17db78 · DisplaySetFrequency(int) · size=20 · insn=5 */
/* @0x17db78 mov r2, r0 */
/* @0x17db7c mov r0, #0 */
/* @0x17db80 mov r1, r0 */
/* @0x17db84 mov r3, r0 */
/* @0x17db88 b 0x17db64 <_Z10DisplaySetiiii> */

/* ── FUNC 0x17db8c · DisplaySetColorDepth(int) · size=20 · insn=5 */
/* @0x17db8c mov r3, r0 */
/* @0x17db90 mov r0, #0 */
/* @0x17db94 mov r1, r0 */
/* @0x17db98 mov r2, r0 */
/* @0x17db9c b 0x17db64 <_Z10DisplaySetiiii> */

/* ── FUNC 0x17dba0 · DisplayReset() · size=4 · insn=1 */
/* @0x17dba0 bx lr */

/* ── FUNC 0x17dba4 · DisplayGetMouseX() · size=8 · insn=2 */
/* @0x17dba4 mov r0, #0 */
/* @0x17dba8 bx lr */

/* ── FUNC 0x17dbac · DisplayGetMouseY() · size=8 · insn=2 */
/* @0x17dbac mov r0, #0 */
/* @0x17dbb0 bx lr */

/* ── FUNC 0x17dbb4 · DisplaySetMouse(int, int) · size=4 · insn=1 */
/* @0x17dbb4 bx lr */

/* ── FUNC 0x17dbb8 · FINALIZE_Graphics_Display() · size=20 · insn=5 */
/* @0x17dbb8 push {r3, lr} */
/* @0x17dbbc bl 0x17dba0 <_Z12DisplayResetv> */
/* @0x17dbc0 bl 0x17daa8 <_Z22InvalidateOGLResourcesv> */
/* @0x17dbc4 pop {r3, lr} */
/* @0x17dbc8 b 0x17dafc <_Z18DeleteOGLResourcesv> */

/* ── FUNC 0x17dbcc · Graphics::OpenWindow(void*, int, int, int) · size=376 · insn=94 */
/* @0x17dbcc push {r4, r5, r6, r7, r8, lr} */
/* @0x17dbd0 mov r6, r3 */
/* @0x17dbd4 ldr r4, [pc, #0x144] */
/* @0x17dbd8 mov r2, #1 */
/* @0x17dbdc ldr r1, [pc, #0x140] */
/* @0x17dbe0 mov r0, #0 */
/* @0x17dbe4 add r4, pc, r4 */
/* @0x17dbe8 ldr r3, [pc, #0x138] */
/* @0x17dbec ldr r12, [r4, r1] */
/* @0x17dbf0 mov r1, #1065353216 */
/* @0x17dbf4 strb r2, [r12] */
/* @0x17dbf8 ldr r3, [r4, r3] */
/* @0x17dbfc ldr r3, [r3] */
/* @0x17dc00 blx r3 */
/* @0x17dc04 ldr r3, [pc, #0x120] */
/* @0x17dc08 movw r0, #0xc11 */
/* @0x17dc0c ldr r8, [r4, r3] */
/* @0x17dc10 ldr r3, [r8] */
/* @0x17dc14 blx r3 */
/* @0x17dc18 ldr r3, [pc, #0x110] */
/* @0x17dc1c movw r0, #0xbe2 */
/* @0x17dc20 ldr r5, [r4, r3] */
/* @0x17dc24 ldr r3, [r5] */
/* @0x17dc28 blx r3 */
/* @0x17dc2c ldr r3, [r5] */
/* @0x17dc30 movw r0, #0xb44 */
/* @0x17dc34 blx r3 */
/* @0x17dc38 ldr r3, [r5] */
/* @0x17dc3c mov r0, #2960 */
/* @0x17dc40 blx r3 */
/* @0x17dc44 ldr r3, [r5] */
/* @0x17dc48 mov r0, #3024 */
/* @0x17dc4c blx r3 */
/* @0x17dc50 ldr r3, [pc, #0xdc] */
/* @0x17dc54 ldr r7, [r4, r3] */
/* @0x17dc58 ldr r3, [r7] */
/* @0x17dc5c cmp r3, #0 */
/* @0x17dc60 beq 0x17dcd4 <_ZN8Graphics10OpenWindowEPviii+0x108> */
/* @0x17dc64 ldr r3, [pc, #0xcc] */
/* @0x17dc68 movw r0, #0x203 */
/* @0x17dc6c ldr r3, [r4, r3] */
/* @0x17dc70 ldr r3, [r3] */
/* @0x17dc74 blx r3 */
/* @0x17dc78 bl 0x17d450 <_Z13GetOpenGLInfov> */
/* @0x17dc7c ands r3, r6, #8 */
/* @0x17dc80 beq 0x17dcc4 <_ZN8Graphics10OpenWindowEPviii+0xf8> */
/* @0x17dc84 ldr r3, [pc, #0xb0] */
/* @0x17dc88 mov r2, #1 */
/* @0x17dc8c ldr r3, [r4, r3] */
/* @0x17dc90 strb r2, [r3] */
/* @0x17dc94 ldr r3, [pc, #0xa4] */
/* @0x17dc98 ands r6, r6, #16 */
/* @0x17dc9c movne r2, #1 */
/* @0x17dca0 ldreq r3, [r4, r3] */
/* @0x17dca4 ldrne r3, [r4, r3] */
/* @0x17dca8 strbeq r6, [r3] */
/* @0x17dcac strbne r2, [r3] */
/* @0x17dcb0 ldr r3, [r7] */
/* @0x17dcb4 cmp r3, #1 */
/* @0x17dcb8 beq 0x17dd14 <_ZN8Graphics10OpenWindowEPviii+0x148> */
/* @0x17dcbc mov r0, #1 */
/* @0x17dcc0 pop {r4, r5, r6, r7, r8, pc} */
/* @0x17dcc4 ldr r2, [pc, #0x70] */
/* @0x17dcc8 ldr r2, [r4, r2] */
/* @0x17dccc strb r3, [r2] */
/* @0x17dcd0 b 0x17dc94 <_ZN8Graphics10OpenWindowEPviii+0xc8> */
/* @0x17dcd4 ldr r3, [r5] */
/* @0x17dcd8 mov r0, #3008 */
/* @0x17dcdc blx r3 */
/* @0x17dce0 ldr r3, [r5] */
/* @0x17dce4 mov r0, #2912 */
/* @0x17dce8 blx r3 */
/* @0x17dcec ldr r3, [r5] */
/* @0x17dcf0 mov r0, #2896 */
/* @0x17dcf4 blx r3 */
/* @0x17dcf8 ldr r3, [r5] */
/* @0x17dcfc movw r0, #0xde1 */
/* @0x17dd00 blx r3 */
/* @0x17dd04 ldr r3, [r8] */
/* @0x17dd08 movw r0, #0xba1 */
/* @0x17dd0c blx r3 */
/* @0x17dd10 b 0x17dc64 <_ZN8Graphics10OpenWindowEPviii+0x98> */
/* @0x17dd14 bl 0x17da94 <_Z16InitOGLResourcesv> */
/* @0x17dd18 mov r0, #1 */
/* @0x17dd1c pop {r4, r5, r6, r7, r8, pc} */
/* @0x17dd20 eoreq r4, r7, r12, rrx */
/* @0x17dd24 .word 0xffffe4d0 */
/* @0x17dd28 .word 0xffffbae8 */
/* @0x17dd2c .word 0xffffbad8 */
/* @0x17dd30 .word 0xffffbad0 */
/* @0x17dd34 .word 0xffffe7b8 */
/* @0x17dd38 .word 0xffffbaec */
/* @0x17dd3c .word 0xffffe4d8 */
/* @0x17dd40 .word 0xffffe6a0 */

/* ── FUNC 0x17dd44 · Graphics::EndInit() · size=4 · insn=1 */
/* @0x17dd44 bx lr */

/* ── FUNC 0x17dd48 · Graphics::GraphicsReset() · size=8 · insn=2 */
/* @0x17dd48 mov r0, #1 */
/* @0x17dd4c bx lr */

/* ── FUNC 0x17dd50 · Graphics::UpdateWindowSize() · size=4 · insn=1 */
/* @0x17dd50 bx lr */

/* ── FUNC 0x17dd54 · Graphics::Quit() · size=4 · insn=1 */
/* @0x17dd54 bx lr */

/* ── FUNC 0x17dd58 · Graphics::SceneBegin() · size=284 · insn=71 */
/* @0x17dd58 push {r4, r5, lr} */
/* @0x17dd5c sub sp, sp, #20 */
/* @0x17dd60 ldr r4, [pc, #0xe4] */
/* @0x17dd64 ldr r3, [pc, #0xe4] */
/* @0x17dd68 add r4, pc, r4 */
/* @0x17dd6c ldr r3, [r4, r3] */
/* @0x17dd70 ldr r5, [r3] */
/* @0x17dd74 cmp r5, #0 */
/* @0x17dd78 bne 0x17dd90 <_ZN8Graphics10SceneBeginEv+0x38> */
/* @0x17dd7c ldr r2, [pc, #0xd0] */
/* @0x17dd80 ldr r2, [r4, r2] */
/* @0x17dd84 ldrb r2, [r2] */
/* @0x17dd88 cmp r2, #0 */
/* @0x17dd8c bne 0x17dd98 <_ZN8Graphics10SceneBeginEv+0x40> */
/* @0x17dd90 add sp, sp, #20 */
/* @0x17dd94 pop {r4, r5, pc} */
/* @0x17dd98 ldr r2, [pc, #0xb8] */
/* @0x17dd9c mov r1, #1 */
/* @0x17dda0 ldr r12, [pc, #0xb4] */
/* @0x17dda4 ldr r0, [pc, #0xb4] */
/* @0x17dda8 ldr r2, [r4, r2] */
/* @0x17ddac ldr lr, [r2] */
/* @0x17ddb0 add lr, lr, r1 */
/* @0x17ddb4 str lr, [r2] */
/* @0x17ddb8 ldr r2, [r4, r12] */
/* @0x17ddbc ldr r12, [r2] */
/* @0x17ddc0 eor r12, r12, r1 */
/* @0x17ddc4 str r12, [r2] */
/* @0x17ddc8 ldr r2, [r4, r0] */
/* @0x17ddcc str r1, [r3] */
/* @0x17ddd0 str r5, [r2] */
/* @0x17ddd4 bl 0x17b9a0 <_ZN12GraphicsPerf10BeginFrameEv> */
/* @0x17ddd8 ldr r2, [pc, #0x84] */
/* @0x17dddc ldr r3, [pc, #0x84] */
/* @0x17dde0 ldr r2, [r4, r2] */
/* @0x17dde4 strb r5, [r2] */
/* @0x17dde8 ldr r3, [r4, r3] */
/* @0x17ddec ldr r3, [r3] */
/* @0x17ddf0 cmp r3, #0 */
/* @0x17ddf4 beq 0x17de04 <_ZN8Graphics10SceneBeginEv+0xac> */
/* @0x17ddf8 bl 0x182598 <_Z23_InvalidateTextureStatev> */
/* @0x17ddfc add sp, sp, #20 */
/* @0x17de00 pop {r4, r5, pc} */
/* @0x17de04 ldr r3, [pc, #0x60] */
/* @0x17de08 movw r0, #0xb57 */
/* @0x17de0c ldr r3, [r4, r3] */
/* @0x17de10 ldr r3, [r3] */
/* @0x17de14 blx r3 */
/* @0x17de18 ldr r2, [pc, #0x50] */
/* @0x17de1c mov r3, #0 */
/* @0x17de20 mov r12, #1065353216 */
/* @0x17de24 str r3, [sp] */
/* @0x17de28 movw r0, #0xb53 */
/* @0x17de2c str r3, [sp, #0x4] */
/* @0x17de30 mov r1, sp */
/* @0x17de34 str r3, [sp, #0x8] */
/* @0x17de38 str r12, [sp, #0xc] */
/* @0x17de3c ldr r3, [r4, r2] */
/* @0x17de40 ldr r3, [r3] */
/* @0x17de44 blx r3 */
/* @0x17de48 b 0x17ddf8 <_ZN8Graphics10SceneBeginEv+0xa0> */
/* @0x17de4c eoreq r3, r7, r8, ror #29 */
/* @0x17de50 .word 0xffffe7f4 */
/* @0x17de54 .word 0xffffe4d0 */
/* @0x17de58 .word 0xffffe7f8 */
/* @0x17de5c .word 0xffffe7fc */
/* @0x17de60 .word 0xffffe800 */
/* @0x17de64 .word 0xffffe804 */
/* @0x17de68 .word 0xffffe7b8 */
/* @0x17de6c .word 0xffffbad8 */
/* @0x17de70 .word 0xffffbc70 */

/* ── FUNC 0x17de74 · Graphics::SceneEnd() · size=160 · insn=40 */
/* @0x17de74 push {r3, r4, r5, lr} */
/* @0x17de78 ldr r4, [pc, #0x7c] */
/* @0x17de7c ldr r3, [pc, #0x7c] */
/* @0x17de80 add r4, pc, r4 */
/* @0x17de84 ldr r5, [r4, r3] */
/* @0x17de88 ldr r3, [r5] */
/* @0x17de8c cmp r3, #0 */
/* @0x17de90 popeq {r3, r4, r5, pc} */
/* @0x17de94 bl 0x17c7e8 <_ZN12GraphicsPerf8EndFrameEv> */
/* @0x17de98 ldr r3, [pc, #0x64] */
/* @0x17de9c ldr r3, [r4, r3] */
/* @0x17dea0 ldrb r3, [r3] */
/* @0x17dea4 cmp r3, #0 */
/* @0x17dea8 popeq {r3, r4, r5, pc} */
/* @0x17deac bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x17deb0 bl 0x1851b8 <_ZN8Graphics13ResetVBuffersEv> */
/* @0x17deb4 ldr r3, [pc, #0x4c] */
/* @0x17deb8 ldr r3, [r4, r3] */
/* @0x17debc ldr r3, [r3] */
/* @0x17dec0 cmp r3, #1 */
/* @0x17dec4 beq 0x17ded4 <_ZN8Graphics8SceneEndEv+0x60> */
/* @0x17dec8 mov r3, #0 */
/* @0x17decc str r3, [r5] */
/* @0x17ded0 pop {r3, r4, r5, pc} */
/* @0x17ded4 ldr r2, [pc, #0x30] */
/* @0x17ded8 mov r1, #0 */
/* @0x17dedc ldr r3, [pc, #0x2c] */
/* @0x17dee0 movw r0, #0x84c0 */
/* @0x17dee4 ldr r2, [r4, r2] */
/* @0x17dee8 str r1, [r2] */
/* @0x17deec ldr r3, [r4, r3] */
/* @0x17def0 ldr r3, [r3] */
/* @0x17def4 blx r3 */
/* @0x17def8 b 0x17dec8 <_ZN8Graphics8SceneEndEv+0x54> */
/* @0x17defc .word 0x00273dd0 */
/* @0x17df00 .word 0xffffe7f4 */
/* @0x17df04 .word 0xffffe4d0 */
/* @0x17df08 .word 0xffffe7b8 */
/* @0x17df0c .word 0xffffe808 */
/* @0x17df10 .word 0xffffbbf0 */

/* ── FUNC 0x17df14 · Graphics::Flip() · size=28 · insn=7 */
/* @0x17df14 ldr r3, [pc, #0x10] */
/* @0x17df18 mov r2, #1 */
/* @0x17df1c mov r0, r2 */
/* @0x17df20 ldr r3, [pc, r3] */
/* @0x17df24 strb r2, [r3] */
/* @0x17df28 bx lr */
/* @0x17df2c eoreq r2, r7, r4, lsr r5 */

/* ── FUNC 0x17df30 · Graphics::PickResolution(int, int) · size=8 · insn=2 */
/* @0x17df30 mov r0, #0 */
/* @0x17df34 bx lr */

/* ── FUNC 0x17df38 · ExitFullScreen() · size=4 · insn=1 */
/* @0x17df38 bx lr */

/* ── FUNC 0x17df3c · Graphics::ShadersSupported() · size=32 · insn=8 */
/* @0x17df3c ldr r3, [pc, #0x14] */
/* @0x17df40 ldr r3, [pc, r3] */
/* @0x17df44 ldr r0, [r3] */
/* @0x17df48 subs r3, r0, #1 */
/* @0x17df4c rsbs r0, r3, #0 */
/* @0x17df50 adcs r0, r0, r3 */
/* @0x17df54 bx lr */
/* @0x17df58 eoreq r2, r7, r8, asr #9 */

/* ── FUNC 0x17df5c · GLError(char*) · size=84 · insn=21 */
/* @0x17df5c ldr r3, [pc, #0x40] */
/* @0x17df60 push {r4, lr} */
/* @0x17df64 ldr r3, [pc, r3] */
/* @0x17df68 mov r4, r0 */
/* @0x17df6c ldr r3, [r3] */
/* @0x17df70 blx r3 */
/* @0x17df74 subs r3, r0, #0 */
/* @0x17df78 popeq {r4, pc} */
/* @0x17df7c ldr r12, [pc, #0x24] */
/* @0x17df80 mov r2, r4 */
/* @0x17df84 ldr r1, [pc, #0x20] */
/* @0x17df88 ldr r12, [pc, r12] */
/* @0x17df8c add r1, pc, r1 */
/* @0x17df90 ldr r0, [r12] */
/* @0x17df94 ldr r12, [r0] */
/* @0x17df98 ldr r12, [r12, #0xc] */
/* @0x17df9c blx r12 */
/* @0x17dfa0 pop {r4, pc} */
/* @0x17dfa4 eoreq pc, r6, r8, asr #15 */
/* @0x17dfa8 eoreq pc, r6, r12, lsl #15 */
/* @0x17dfac mulseq r12, r12, r9 */

/* ── FUNC 0x17dfb0 · Graphics::SetViewPort(int, int, int, int) · size=300 · insn=75 */
/* @0x17dfb0 push {r4, r5, r6, r7, r8, lr} */
/* @0x17dfb4 mov r7, r0 */
/* @0x17dfb8 ldr r4, [pc, #0xf8] */
/* @0x17dfbc mov r8, r1 */
/* @0x17dfc0 ldr r0, [pc, #0xf4] */
/* @0x17dfc4 mov r6, r2 */
/* @0x17dfc8 add r4, pc, r4 */
/* @0x17dfcc ldr r1, [pc, #0xec] */
/* @0x17dfd0 ldr r2, [pc, #0xec] */
/* @0x17dfd4 mov r5, r3 */
/* @0x17dfd8 ldr r12, [r4, r0] */
/* @0x17dfdc ldr r0, [pc, #0xe4] */
/* @0x17dfe0 ldr r3, [pc, #0xe4] */
/* @0x17dfe4 str r7, [r12] */
/* @0x17dfe8 ldr r1, [r4, r1] */
/* @0x17dfec str r8, [r1] */
/* @0x17dff0 ldr r2, [r4, r2] */
/* @0x17dff4 str r6, [r2] */
/* @0x17dff8 ldr r2, [r4, r0] */
/* @0x17dffc str r5, [r2] */
/* @0x17e000 ldr r3, [r4, r3] */
/* @0x17e004 ldr r3, [r3] */
/* @0x17e008 cmp r3, #1 */
/* @0x17e00c beq 0x17e068 <_ZN8Graphics11SetViewPortEiiii+0xb8> */
/* @0x17e010 ldr r3, [pc, #0xb8] */
/* @0x17e014 movw r0, #0xc11 */
/* @0x17e018 ldr r3, [r4, r3] */
/* @0x17e01c ldr r3, [r3] */
/* @0x17e020 blx r3 */
/* @0x17e024 ldr r12, [pc, #0xa8] */
/* @0x17e028 mov r0, r7 */
/* @0x17e02c mov r1, r8 */
/* @0x17e030 mov r2, r6 */
/* @0x17e034 mov r3, r5 */
/* @0x17e038 ldr r12, [r4, r12] */
/* @0x17e03c ldr r12, [r12] */
/* @0x17e040 blx r12 */
/* @0x17e044 ldr r12, [pc, #0x8c] */
/* @0x17e048 mov r0, r7 */
/* @0x17e04c mov r1, r8 */
/* @0x17e050 ldr r12, [r4, r12] */
/* @0x17e054 mov r2, r6 */
/* @0x17e058 mov r3, r5 */
/* @0x17e05c ldr r12, [r12] */
/* @0x17e060 blx r12 */
/* @0x17e064 pop {r4, r5, r6, r7, r8, pc} */
/* @0x17e068 bl 0x17af64 <_Z20GR_Window_Get_Heightv> */
/* @0x17e06c ldr r3, [pc, #0x5c] */
/* @0x17e070 add r8, r5, r8 */
/* @0x17e074 ldr r3, [r4, r3] */
/* @0x17e078 ldr r3, [r3] */
/* @0x17e07c rsb r8, r8, r0 */
/* @0x17e080 movw r0, #0xc11 */
/* @0x17e084 blx r3 */
/* @0x17e088 ldr r12, [pc, #0x44] */
/* @0x17e08c mov r1, r8 */
/* @0x17e090 mov r0, r7 */
/* @0x17e094 mov r2, r6 */
/* @0x17e098 mov r3, r5 */
/* @0x17e09c ldr r12, [r4, r12] */
/* @0x17e0a0 ldr r12, [r12] */
/* @0x17e0a4 blx r12 */
/* @0x17e0a8 ldr r12, [pc, #0x28] */
/* @0x17e0ac mov r1, r8 */
/* @0x17e0b0 mov r0, r7 */
/* @0x17e0b4 b 0x17e050 <_ZN8Graphics11SetViewPortEiiii+0xa0> */
/* @0x17e0b8 eoreq r3, r7, r8, lsl #25 */
/* @0x17e0bc .word 0xffffe80c */
/* @0x17e0c0 .word 0xffffe810 */
/* @0x17e0c4 .word 0xffffe814 */
/* @0x17e0c8 .word 0xffffe818 */
/* @0x17e0cc .word 0xffffe48c */
/* @0x17e0d0 .word 0xffffbad8 */
/* @0x17e0d4 .word 0xffffbae4 */
/* @0x17e0d8 .word 0xffffbaf0 */

/* ── FUNC 0x17e0dc · Graphics::GrabScreenRect(int, int, int, int, int*, int*) · size=460 · insn=115 */
/* @0x17e0dc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x17e0e0 vpush {d8} */
/* @0x17e0e4 sub sp, sp, #36 */
/* @0x17e0e8 mov r9, r0 */
/* @0x17e0ec mov r5, r2 */
/* @0x17e0f0 ldr r12, [sp, #0x50] */
/* @0x17e0f4 mov r6, r3 */
/* @0x17e0f8 ldr r0, [sp, #0x54] */
/* @0x17e0fc mov r10, r1 */
/* @0x17e100 ldr r4, [pc, #0x194] */
/* @0x17e104 vmov.f32 s16, #5.000000e-01 */
/* @0x17e108 ldr r8, [r12] */
/* @0x17e10c ldr r7, [r0] */
/* @0x17e110 bl 0x17af50 <_Z19GR_Window_Get_Widthv> */
/* @0x17e114 vmov s12, r5 */
/* @0x17e118 ldr r4, [pc, r4] */
/* @0x17e11c ldr r3, [r4] */
/* @0x17e120 vldr s15, [r3, #16] */
/* @0x17e124 vcvt.f32.s32 s14, s12 */
/* @0x17e128 vcvt.f32.s32 s15, s15 */
/* @0x17e12c vmov s12, r0 */
/* @0x17e130 vcvt.f32.s32 s13, s12 */
/* @0x17e134 vdiv.f32 s15, s13, s15 */
/* @0x17e138 vmov.f32 s13, s16 */
/* @0x17e13c vmla.f32 s13, s14, s15 */
/* @0x17e140 vcvt.s32.f32 s15, s13 */
/* @0x17e144 vstr s15, [sp, #24] */
/* @0x17e148 bl 0x17af64 <_Z20GR_Window_Get_Heightv> */
/* @0x17e14c vmov s12, r6 */
/* @0x17e150 ldr r3, [r4] */
/* @0x17e154 vldr s15, [r3, #20] */
/* @0x17e158 vcvt.f32.s32 s15, s15 */
/* @0x17e15c ldr r12, [sp, #0x18] */
/* @0x17e160 add r3, r12, r8 */
/* @0x17e164 cmp r12, #0 */
/* @0x17e168 movlt r5, #0 */
/* @0x17e16c vcvt.f32.s32 s14, s12 */
/* @0x17e170 vmov s12, r0 */
/* @0x17e174 vcvt.f32.s32 s13, s12 */
/* @0x17e178 vdiv.f32 s15, s13, s15 */
/* @0x17e17c vmla.f32 s16, s14, s15 */
/* @0x17e180 vcvt.s32.f32 s16, s16 */
/* @0x17e184 vmov r12, s16 */
/* @0x17e188 cmp r12, #0 */
/* @0x17e18c movlt r6, #0 */
/* @0x17e190 cmp r3, r9 */
/* @0x17e194 add r3, r12, r7 */
/* @0x17e198 rsbgt r8, r5, r9 */
/* @0x17e19c cmp r3, r10 */
/* @0x17e1a0 rsbgt r7, r6, r10 */
/* @0x17e1a4 cmp r8, #0 */
/* @0x17e1a8 cmpgt r7, #0 */
/* @0x17e1ac movgt r5, #0 */
/* @0x17e1b0 movle r5, #1 */
/* @0x17e1b4 movle r0, #0 */
/* @0x17e1b8 ble 0x17e290 <_ZN8Graphics14GrabScreenRectEiiiiPiS0_+0x1b4> */
/* @0x17e1bc mul r11, r7, r8 */
/* @0x17e1c0 vstr s16, [sp, #20] */
/* @0x17e1c4 ldr r4, [pc, #0xd4] */
/* @0x17e1c8 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x17e1cc mov r2, #70 */
/* @0x17e1d0 mov r3, #1 */
/* @0x17e1d4 add r4, pc, r4 */
/* @0x17e1d8 lsl r6, r8, #2 */
/* @0x17e1dc mov r1, r4 */
/* @0x17e1e0 lsl r9, r11, #2 */
/* @0x17e1e4 rsb r11, r8, r11 */
/* @0x17e1e8 mov r0, r9 */
/* @0x17e1ec bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x17e1f0 mov r1, r4 */
/* @0x17e1f4 mov r2, #70 */
/* @0x17e1f8 mov r3, #1 */
/* @0x17e1fc mov r10, r0 */
/* @0x17e200 mov r0, r9 */
/* @0x17e204 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x17e208 ldr r3, [pc, #0x94] */
/* @0x17e20c mov r4, r10 */
/* @0x17e210 ldr r3, [pc, r3] */
/* @0x17e214 ldr r3, [r3] */
/* @0x17e218 str r3, [sp, #0x1c] */
/* @0x17e21c mov r9, r0 */
/* @0x17e220 bl 0x17af64 <_Z20GR_Window_Get_Heightv> */
/* @0x17e224 ldr r12, [sp, #0x14] */
/* @0x17e228 movw r2, #0x1908 */
/* @0x17e22c movw r3, #0x1401 */
/* @0x17e230 str r9, [sp, #0x8] */
/* @0x17e234 add r1, r12, r7 */
/* @0x17e238 stm sp, {r2, r3} */
/* @0x17e23c ldr r12, [sp, #0x1c] */
/* @0x17e240 mov r2, r8 */
/* @0x17e244 mov r3, r7 */
/* @0x17e248 add r11, r9, r11, lsl #2 */
/* @0x17e24c rsb r1, r1, r0 */
/* @0x17e250 ldr r0, [sp, #0x18] */
/* @0x17e254 blx r12 */
/* @0x17e258 rsb r12, r8, r8, lsl #30 */
/* @0x17e25c lsl r8, r12, #2 */
/* @0x17e260 mov r0, r4 */
/* @0x17e264 mov r1, r11 */
/* @0x17e268 add r5, r5, #1 */
/* @0x17e26c mov r2, r6 */
/* @0x17e270 bl 0xb65bc <memcpy@plt> */
/* @0x17e274 cmp r7, r5 */
/* @0x17e278 add r4, r4, r6 */
/* @0x17e27c add r11, r11, r8 */
/* @0x17e280 bgt 0x17e260 <_ZN8Graphics14GrabScreenRectEiiiiPiS0_+0x184> */
/* @0x17e284 mov r0, r9 */
/* @0x17e288 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x17e28c mov r0, r10 */
/* @0x17e290 add sp, sp, #36 */
/* @0x17e294 vpop {d8} */
/* @0x17e298 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x17e29c eoreq pc, r6, r0, lsl r8 */
/* @0x17e2a0 andseq r2, r11, r12, asr lr */
/* @0x17e2a4 eoreq pc, r6, r4, lsr r5 */
