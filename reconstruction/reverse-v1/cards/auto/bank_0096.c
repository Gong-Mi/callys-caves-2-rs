/* libyoyo.so 覆盖卡组 0096
 * 函数 0x160ea8..0x16120c，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x160ea8 · F_JoystickRpos(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x160ea8 bx lr */

/* ── FUNC 0x160eac · F_JoystickUpos(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x160eac bx lr */

/* ── FUNC 0x160eb0 · F_JoystickVpos(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x160eb0 bx lr */

/* ── FUNC 0x160eb4 · F_JoystickPov(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x160eb4 bx lr */

/* ── FUNC 0x160eb8 · F_KeyboardWait(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x160eb8 bx lr */

/* ── FUNC 0x160ebc · F_MouseWait(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x160ebc bx lr */

/* ── FUNC 0x160ec0 · YYGetOpenFileName(char*, char*, char*, char*) · size=8 · insn=2 */
/* @0x160ec0 mov r0, #0 */
/* @0x160ec4 bx lr */

/* ── FUNC 0x160ec8 · YYGetSaveFileName(char*, char*, char*, char*) · size=8 · insn=2 */
/* @0x160ec8 mov r0, #0 */
/* @0x160ecc bx lr */

/* ── FUNC 0x160ed0 · F_SetProgramPriority(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x160ed0 bx lr */

/* ── FUNC 0x160ed4 · F_SetApplicationTitle(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x160ed4 bx lr */

/* ── FUNC 0x160ed8 · F_ClipboardHasText(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x160ed8 bx lr */

/* ── FUNC 0x160edc · F_ClipboardGetText(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x160edc bx lr */

/* ── FUNC 0x160ee0 · F_ClipboardSetText(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x160ee0 bx lr */

/* ── FUNC 0x160ee4 · F_WindowHandle(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x160ee4 bx lr */

/* ── FUNC 0x160ee8 · F_WindowD3DDevice(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x160ee8 bx lr */

/* ── FUNC 0x160eec · OpenURL(char const*) · size=88 · insn=22 */
/* @0x160eec push {r4, lr} */
/* @0x160ef0 mov r4, r0 */
/* @0x160ef4 bl 0x290274 <getJNIEnv> */
/* @0x160ef8 mov r1, r4 */
/* @0x160efc ldr r3, [r0] */
/* @0x160f00 ldr r3, [r3, #0x29c] */
/* @0x160f04 blx r3 */
/* @0x160f08 mov r4, r0 */
/* @0x160f0c bl 0x290274 <getJNIEnv> */
/* @0x160f10 ldr r1, [pc, #0x24] */
/* @0x160f14 mov r3, r4 */
/* @0x160f18 ldr r2, [pc, #0x20] */
/* @0x160f1c ldr r1, [pc, r1] */
/* @0x160f20 ldr r2, [pc, r2] */
/* @0x160f24 ldr r1, [r1] */
/* @0x160f28 ldr r2, [r2] */
/* @0x160f2c bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x160f30 mov r0, #0 */
/* @0x160f34 mov r1, #0 */
/* @0x160f38 pop {r4, pc} */
/* @0x160f3c eoreq r12, r8, r8, lsl #21 */
/* @0x160f40 .word 0x0028effc */

/* ── FUNC 0x160f44 · AreOnlineAchievementsAvailable() · size=8 · insn=2 */
/* @0x160f44 mov r0, #1 */
/* @0x160f48 bx lr */

/* ── FUNC 0x160f4c · Achievement_LoginStatus() · size=48 · insn=12 */
/* @0x160f4c push {r3, lr} */
/* @0x160f50 bl 0x290274 <getJNIEnv> */
/* @0x160f54 ldr r2, [pc, #0x18] */
/* @0x160f58 ldr r3, [pc, #0x18] */
/* @0x160f5c ldr r2, [pc, r2] */
/* @0x160f60 ldr r3, [pc, r3] */
/* @0x160f64 ldr r1, [r2] */
/* @0x160f68 ldr r2, [r3] */
/* @0x160f6c pop {r3, lr} */
/* @0x160f70 b 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz> */
/* @0x160f74 eoreq r12, r8, r8, asr #20 */
/* @0x160f78 eoreq lr, r8, r0, asr #31 */

/* ── FUNC 0x160f7c · Achievement_Login() · size=48 · insn=12 */
/* @0x160f7c push {r3, lr} */
/* @0x160f80 bl 0x290274 <getJNIEnv> */
/* @0x160f84 ldr r2, [pc, #0x18] */
/* @0x160f88 ldr r3, [pc, #0x18] */
/* @0x160f8c ldr r2, [pc, r2] */
/* @0x160f90 ldr r3, [pc, r3] */
/* @0x160f94 ldr r1, [r2] */
/* @0x160f98 ldr r2, [r3] */
/* @0x160f9c pop {r3, lr} */
/* @0x160fa0 b 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x160fa4 eoreq r12, r8, r8, lsl r10 */
/* @0x160fa8 mlaeq r8, r4, pc, lr */

/* ── FUNC 0x160fac · Achievement_Logout() · size=48 · insn=12 */
/* @0x160fac push {r3, lr} */
/* @0x160fb0 bl 0x290274 <getJNIEnv> */
/* @0x160fb4 ldr r2, [pc, #0x18] */
/* @0x160fb8 ldr r3, [pc, #0x18] */
/* @0x160fbc ldr r2, [pc, r2] */
/* @0x160fc0 ldr r3, [pc, r3] */
/* @0x160fc4 ldr r1, [r2] */
/* @0x160fc8 ldr r2, [r3] */
/* @0x160fcc pop {r3, lr} */
/* @0x160fd0 b 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x160fd4 eoreq r12, r8, r8, ror #19 */
/* @0x160fd8 eoreq lr, r8, r8, ror #30 */

/* ── FUNC 0x160fdc · Achievement_Show_Achievement() · size=48 · insn=12 */
/* @0x160fdc push {r3, lr} */
/* @0x160fe0 bl 0x290274 <getJNIEnv> */
/* @0x160fe4 ldr r2, [pc, #0x18] */
/* @0x160fe8 ldr r3, [pc, #0x18] */
/* @0x160fec ldr r2, [pc, r2] */
/* @0x160ff0 ldr r3, [pc, r3] */
/* @0x160ff4 ldr r1, [r2] */
/* @0x160ff8 ldr r2, [r3] */
/* @0x160ffc pop {r3, lr} */
/* @0x161000 b 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x161004 .word 0x0028c9b8 */
/* @0x161008 eoreq lr, r8, r12, lsr pc */

/* ── FUNC 0x16100c · Achievement_Show(int, char*, int) · size=100 · insn=25 */
/* @0x16100c push {r4, r5, r6, lr} */
/* @0x161010 sub sp, sp, #8 */
/* @0x161014 mov r5, r2 */
/* @0x161018 mov r6, r0 */
/* @0x16101c mov r4, r1 */
/* @0x161020 bl 0x290274 <getJNIEnv> */
/* @0x161024 mov r1, r4 */
/* @0x161028 ldr r3, [r0] */
/* @0x16102c ldr r3, [r3, #0x29c] */
/* @0x161030 blx r3 */
/* @0x161034 mov r4, r0 */
/* @0x161038 bl 0x290274 <getJNIEnv> */
/* @0x16103c ldr r1, [pc, #0x24] */
/* @0x161040 mov r3, r6 */
/* @0x161044 ldr r12, [pc, #0x20] */
/* @0x161048 ldr r1, [pc, r1] */
/* @0x16104c ldr r12, [pc, r12] */
/* @0x161050 ldr r1, [r1] */
/* @0x161054 ldr r2, [r12] */
/* @0x161058 stm sp, {r4, r5} */
/* @0x16105c bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x161060 add sp, sp, #8 */
/* @0x161064 pop {r4, r5, r6, pc} */
/* @0x161068 eoreq r12, r8, r12, asr r9 */
/* @0x16106c eoreq lr, r8, r4, ror #29 */

/* ── FUNC 0x161070 · Achievement_Show_Challenge_Notifications(int, int, int) · size=4 · insn=1 */
/* @0x161070 bx lr */

/* ── FUNC 0x161074 · Achievement_Get_Challenges() · size=4 · insn=1 */
/* @0x161074 bx lr */

/* ── FUNC 0x161078 · Achievement_Send_Challenge(char*, char*, int, int, char*) · size=4 · insn=1 */
/* @0x161078 bx lr */

/* ── FUNC 0x16107c · Achievement_Load_Leaderboard(char*, int, int, int) · size=108 · insn=27 */
/* @0x16107c push {r4, r5, r6, r7, lr} */
/* @0x161080 sub sp, sp, #20 */
/* @0x161084 mov r7, r2 */
/* @0x161088 mov r5, r1 */
/* @0x16108c mov r4, r3 */
/* @0x161090 mov r6, r0 */
/* @0x161094 bl 0x290274 <getJNIEnv> */
/* @0x161098 mov r1, r6 */
/* @0x16109c ldr r3, [r0] */
/* @0x1610a0 ldr r3, [r3, #0x29c] */
/* @0x1610a4 blx r3 */
/* @0x1610a8 mov r6, r0 */
/* @0x1610ac bl 0x290274 <getJNIEnv> */
/* @0x1610b0 ldr lr, [pc, #0x28] */
/* @0x1610b4 mov r3, r6 */
/* @0x1610b8 ldr r12, [pc, #0x24] */
/* @0x1610bc ldr lr, [pc, lr] */
/* @0x1610c0 ldr r12, [pc, r12] */
/* @0x1610c4 ldr r1, [lr] */
/* @0x1610c8 ldr r2, [r12] */
/* @0x1610cc stm sp, {r5, r7} */
/* @0x1610d0 str r4, [sp, #0x8] */
/* @0x1610d4 bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x1610d8 add sp, sp, #20 */
/* @0x1610dc pop {r4, r5, r6, r7, pc} */
/* @0x1610e0 eoreq r12, r8, r8, ror #17 */
/* @0x1610e4 eoreq lr, r8, r4, ror lr */

/* ── FUNC 0x1610e8 · Achievement_Get_Info(char*) · size=80 · insn=20 */
/* @0x1610e8 push {r4, lr} */
/* @0x1610ec mov r4, r0 */
/* @0x1610f0 bl 0x290274 <getJNIEnv> */
/* @0x1610f4 mov r1, r4 */
/* @0x1610f8 ldr r3, [r0] */
/* @0x1610fc ldr r3, [r3, #0x29c] */
/* @0x161100 blx r3 */
/* @0x161104 mov r4, r0 */
/* @0x161108 bl 0x290274 <getJNIEnv> */
/* @0x16110c ldr r1, [pc, #0x1c] */
/* @0x161110 mov r3, r4 */
/* @0x161114 ldr r2, [pc, #0x18] */
/* @0x161118 ldr r1, [pc, r1] */
/* @0x16111c ldr r2, [pc, r2] */
/* @0x161120 ldr r1, [r1] */
/* @0x161124 ldr r2, [r2] */
/* @0x161128 pop {r4, lr} */
/* @0x16112c b 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x161130 eoreq r12, r8, r12, lsl #17 */
/* @0x161134 eoreq lr, r8, r12, lsl lr */

/* ── FUNC 0x161138 · Achievement_Load_Friends() · size=48 · insn=12 */
/* @0x161138 push {r3, lr} */
/* @0x16113c bl 0x290274 <getJNIEnv> */
/* @0x161140 ldr r2, [pc, #0x18] */
/* @0x161144 ldr r3, [pc, #0x18] */
/* @0x161148 ldr r2, [pc, r2] */
/* @0x16114c ldr r3, [pc, r3] */
/* @0x161150 ldr r1, [r2] */
/* @0x161154 ldr r2, [r3] */
/* @0x161158 pop {r3, lr} */
/* @0x16115c b 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x161160 eoreq r12, r8, r12, asr r8 */
/* @0x161164 .word 0x0028edf0 */

/* ── FUNC 0x161168 · Achievement_Load_Pic(char*) · size=80 · insn=20 */
/* @0x161168 push {r4, lr} */
/* @0x16116c mov r4, r0 */
/* @0x161170 bl 0x290274 <getJNIEnv> */
/* @0x161174 mov r1, r4 */
/* @0x161178 ldr r3, [r0] */
/* @0x16117c ldr r3, [r3, #0x29c] */
/* @0x161180 blx r3 */
/* @0x161184 mov r4, r0 */
/* @0x161188 bl 0x290274 <getJNIEnv> */
/* @0x16118c ldr r1, [pc, #0x1c] */
/* @0x161190 mov r3, r4 */
/* @0x161194 ldr r2, [pc, #0x18] */
/* @0x161198 ldr r1, [pc, r1] */
/* @0x16119c ldr r2, [pc, r2] */
/* @0x1611a0 ldr r1, [r1] */
/* @0x1611a4 ldr r2, [r2] */
/* @0x1611a8 pop {r4, lr} */
/* @0x1611ac b 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x1611b0 eoreq r12, r8, r12, lsl #16 */
/* @0x1611b4 eoreq lr, r8, r4, lsr #27 */

/* ── FUNC 0x1611b8 · Achievement_Event(char*) · size=80 · insn=20 */
/* @0x1611b8 push {r4, lr} */
/* @0x1611bc mov r4, r0 */
/* @0x1611c0 bl 0x290274 <getJNIEnv> */
/* @0x1611c4 mov r1, r4 */
/* @0x1611c8 ldr r3, [r0] */
/* @0x1611cc ldr r3, [r3, #0x29c] */
/* @0x1611d0 blx r3 */
/* @0x1611d4 mov r4, r0 */
/* @0x1611d8 bl 0x290274 <getJNIEnv> */
/* @0x1611dc ldr r1, [pc, #0x1c] */
/* @0x1611e0 mov r3, r4 */
/* @0x1611e4 ldr r2, [pc, #0x18] */
/* @0x1611e8 ldr r1, [pc, r1] */
/* @0x1611ec ldr r2, [pc, r2] */
/* @0x1611f0 ldr r1, [r1] */
/* @0x1611f4 ldr r2, [r2] */
/* @0x1611f8 pop {r4, lr} */
/* @0x1611fc b 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x161200 .word 0x0028c7bc */
/* @0x161204 eoreq lr, r8, r8, asr sp */

/* ── FUNC 0x161208 · Achievement_Load_Progress() · size=4 · insn=1 */
/* @0x161208 bx lr */

/* ── FUNC 0x16120c · Achievement_Reset() · size=4 · insn=1 */
/* @0x16120c bx lr */
