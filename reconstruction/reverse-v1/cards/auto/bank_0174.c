/* libyoyo.so 覆盖卡组 0174
 * 函数 0x1f9684..0x1fa010，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1f9684 · GV_PhysicsLinearVelocityX(CInstance*, int, RValue*) · size=100 · insn=25 */
/* @0x1f9684 ldr r3, [pc, #0x58] */
/* @0x1f9688 ldr r1, [r0, #0x84] */
/* @0x1f968c ldr r3, [pc, r3] */
/* @0x1f9690 push {r4, r5} */
/* @0x1f9694 ldr r3, [r3] */
/* @0x1f9698 ldr r3, [r3, #0xb4] */
/* @0x1f969c cmp r1, #0 */
/* @0x1f96a0 cmpne r3, #0 */
/* @0x1f96a4 moveq r0, #0 */
/* @0x1f96a8 movne r0, #1 */
/* @0x1f96ac beq 0x1f96dc <_Z25GV_PhysicsLinearVelocityXP9CInstanceiP6RValue+0x58> */
/* @0x1f96b0 ldr r12, [r1] */
/* @0x1f96b4 mov r1, #0 */
/* @0x1f96b8 vldr s14, [r12, #80] */
/* @0x1f96bc str r1, [r2, #0xc] */
/* @0x1f96c0 vldr s15, [r3, #96] */
/* @0x1f96c4 vdiv.f32 s15, s14, s15 */
/* @0x1f96c8 vcvt.f64.f32 d6, s15 */
/* @0x1f96cc vmov r4, r5, d6 */
/* @0x1f96d0 vmov r1, s12 */
/* @0x1f96d4 mov r3, r5 */
/* @0x1f96d8 stm r2, {r1, r3} */
/* @0x1f96dc pop {r4, r5} */
/* @0x1f96e0 bx lr */
/* @0x1f96e4 mulseq pc, r12, r2 */

/* ── FUNC 0x1f96e8 · GV_PhysicsLinearVelocityY(CInstance*, int, RValue*) · size=100 · insn=25 */
/* @0x1f96e8 ldr r3, [pc, #0x58] */
/* @0x1f96ec ldr r1, [r0, #0x84] */
/* @0x1f96f0 ldr r3, [pc, r3] */
/* @0x1f96f4 push {r4, r5} */
/* @0x1f96f8 ldr r3, [r3] */
/* @0x1f96fc ldr r3, [r3, #0xb4] */
/* @0x1f9700 cmp r1, #0 */
/* @0x1f9704 cmpne r3, #0 */
/* @0x1f9708 moveq r0, #0 */
/* @0x1f970c movne r0, #1 */
/* @0x1f9710 beq 0x1f9740 <_Z25GV_PhysicsLinearVelocityYP9CInstanceiP6RValue+0x58> */
/* @0x1f9714 ldr r12, [r1] */
/* @0x1f9718 mov r1, #0 */
/* @0x1f971c vldr s14, [r12, #84] */
/* @0x1f9720 str r1, [r2, #0xc] */
/* @0x1f9724 vldr s15, [r3, #96] */
/* @0x1f9728 vdiv.f32 s15, s14, s15 */
/* @0x1f972c vcvt.f64.f32 d6, s15 */
/* @0x1f9730 vmov r4, r5, d6 */
/* @0x1f9734 vmov r1, s12 */
/* @0x1f9738 mov r3, r5 */
/* @0x1f973c stm r2, {r1, r3} */
/* @0x1f9740 pop {r4, r5} */
/* @0x1f9744 bx lr */
/* @0x1f9748 andseq r4, pc, r8, lsr r2 */

/* ── FUNC 0x1f974c · GV_PhysicsAngularDamping(CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x1f974c ldr r0, [r0, #0x84] */
/* @0x1f9750 push {r4, r5} */
/* @0x1f9754 cmp r0, #0 */
/* @0x1f9758 beq 0x1f9784 <_Z24GV_PhysicsAngularDampingP9CInstanceiP6RValue+0x38> */
/* @0x1f975c ldr r3, [r0] */
/* @0x1f9760 vldr s15, [r3, #152] */
/* @0x1f9764 vcvt.f64.f32 d6, s15 */
/* @0x1f9768 mov r0, #1 */
/* @0x1f976c mov r3, #0 */
/* @0x1f9770 str r3, [r2, #0xc] */
/* @0x1f9774 vmov r4, r5, d6 */
/* @0x1f9778 vmov r1, s12 */
/* @0x1f977c mov r3, r5 */
/* @0x1f9780 stm r2, {r1, r3} */
/* @0x1f9784 pop {r4, r5} */
/* @0x1f9788 bx lr */

/* ── FUNC 0x1f978c · GV_PhysicsLinearDamping(CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x1f978c ldr r0, [r0, #0x84] */
/* @0x1f9790 push {r4, r5} */
/* @0x1f9794 cmp r0, #0 */
/* @0x1f9798 beq 0x1f97c4 <_Z23GV_PhysicsLinearDampingP9CInstanceiP6RValue+0x38> */
/* @0x1f979c ldr r3, [r0] */
/* @0x1f97a0 vldr s15, [r3, #148] */
/* @0x1f97a4 vcvt.f64.f32 d6, s15 */
/* @0x1f97a8 mov r0, #1 */
/* @0x1f97ac mov r3, #0 */
/* @0x1f97b0 str r3, [r2, #0xc] */
/* @0x1f97b4 vmov r4, r5, d6 */
/* @0x1f97b8 vmov r1, s12 */
/* @0x1f97bc mov r3, r5 */
/* @0x1f97c0 stm r2, {r1, r3} */
/* @0x1f97c4 pop {r4, r5} */
/* @0x1f97c8 bx lr */

/* ── FUNC 0x1f97cc · GV_PhysicsCOM_X(CInstance*, int, RValue*) · size=100 · insn=25 */
/* @0x1f97cc ldr r3, [pc, #0x58] */
/* @0x1f97d0 ldr r1, [r0, #0x84] */
/* @0x1f97d4 ldr r3, [pc, r3] */
/* @0x1f97d8 push {r4, r5} */
/* @0x1f97dc ldr r3, [r3] */
/* @0x1f97e0 ldr r3, [r3, #0xb4] */
/* @0x1f97e4 cmp r1, #0 */
/* @0x1f97e8 cmpne r3, #0 */
/* @0x1f97ec moveq r0, #0 */
/* @0x1f97f0 movne r0, #1 */
/* @0x1f97f4 beq 0x1f9824 <_Z15GV_PhysicsCOM_XP9CInstanceiP6RValue+0x58> */
/* @0x1f97f8 ldr r12, [r1] */
/* @0x1f97fc mov r1, #0 */
/* @0x1f9800 vldr s14, [r12, #60] */
/* @0x1f9804 str r1, [r2, #0xc] */
/* @0x1f9808 vldr s15, [r3, #96] */
/* @0x1f980c vdiv.f32 s15, s14, s15 */
/* @0x1f9810 vcvt.f64.f32 d6, s15 */
/* @0x1f9814 vmov r4, r5, d6 */
/* @0x1f9818 vmov r1, s12 */
/* @0x1f981c mov r3, r5 */
/* @0x1f9820 stm r2, {r1, r3} */
/* @0x1f9824 pop {r4, r5} */
/* @0x1f9828 bx lr */
/* @0x1f982c andseq r4, pc, r4, asr r1 */

/* ── FUNC 0x1f9830 · GV_PhysicsCOM_Y(CInstance*, int, RValue*) · size=100 · insn=25 */
/* @0x1f9830 ldr r3, [pc, #0x58] */
/* @0x1f9834 ldr r1, [r0, #0x84] */
/* @0x1f9838 ldr r3, [pc, r3] */
/* @0x1f983c push {r4, r5} */
/* @0x1f9840 ldr r3, [r3] */
/* @0x1f9844 ldr r3, [r3, #0xb4] */
/* @0x1f9848 cmp r1, #0 */
/* @0x1f984c cmpne r3, #0 */
/* @0x1f9850 moveq r0, #0 */
/* @0x1f9854 movne r0, #1 */
/* @0x1f9858 beq 0x1f9888 <_Z15GV_PhysicsCOM_YP9CInstanceiP6RValue+0x58> */
/* @0x1f985c ldr r12, [r1] */
/* @0x1f9860 mov r1, #0 */
/* @0x1f9864 vldr s14, [r12, #64] */
/* @0x1f9868 str r1, [r2, #0xc] */
/* @0x1f986c vldr s15, [r3, #96] */
/* @0x1f9870 vdiv.f32 s15, s14, s15 */
/* @0x1f9874 vcvt.f64.f32 d6, s15 */
/* @0x1f9878 vmov r4, r5, d6 */
/* @0x1f987c vmov r1, s12 */
/* @0x1f9880 mov r3, r5 */
/* @0x1f9884 stm r2, {r1, r3} */
/* @0x1f9888 pop {r4, r5} */
/* @0x1f988c bx lr */
/* @0x1f9890 ldrsheq r4, [pc], -r0 */

/* ── FUNC 0x1f9894 · GV_PhysicsBodyDynamic(CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x1f9894 ldr r0, [r0, #0x84] */
/* @0x1f9898 push {r4, r5} */
/* @0x1f989c cmp r0, #0 */
/* @0x1f98a0 beq 0x1f98dc <_Z21GV_PhysicsBodyDynamicP9CInstanceiP6RValue+0x48> */
/* @0x1f98a4 ldr r3, [r0] */
/* @0x1f98a8 mov r1, #0 */
/* @0x1f98ac str r1, [r2, #0xc] */
/* @0x1f98b0 mov r0, #1 */
/* @0x1f98b4 ldr r4, [r3] */
/* @0x1f98b8 subs r3, r4, #2 */
/* @0x1f98bc rsbs r4, r3, #0 */
/* @0x1f98c0 adcs r4, r4, r3 */
/* @0x1f98c4 vmov s15, r4 */
/* @0x1f98c8 vcvt.f64.u32 d7, s15 */
/* @0x1f98cc vmov r4, r5, d7 */
/* @0x1f98d0 vmov r1, s14 */
/* @0x1f98d4 mov r3, r5 */
/* @0x1f98d8 stm r2, {r1, r3} */
/* @0x1f98dc pop {r4, r5} */
/* @0x1f98e0 bx lr */

/* ── FUNC 0x1f98e4 · GV_PhysicsBodyKinematic(CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x1f98e4 ldr r0, [r0, #0x84] */
/* @0x1f98e8 push {r4, r5} */
/* @0x1f98ec cmp r0, #0 */
/* @0x1f98f0 beq 0x1f992c <_Z23GV_PhysicsBodyKinematicP9CInstanceiP6RValue+0x48> */
/* @0x1f98f4 ldr r3, [r0] */
/* @0x1f98f8 mov r0, #1 */
/* @0x1f98fc mov r1, #0 */
/* @0x1f9900 str r1, [r2, #0xc] */
/* @0x1f9904 ldr r4, [r3] */
/* @0x1f9908 subs r3, r4, r0 */
/* @0x1f990c rsbs r4, r3, #0 */
/* @0x1f9910 adcs r4, r4, r3 */
/* @0x1f9914 vmov s15, r4 */
/* @0x1f9918 vcvt.f64.u32 d7, s15 */
/* @0x1f991c vmov r4, r5, d7 */
/* @0x1f9920 vmov r1, s14 */
/* @0x1f9924 mov r3, r5 */
/* @0x1f9928 stm r2, {r1, r3} */
/* @0x1f992c pop {r4, r5} */
/* @0x1f9930 bx lr */

/* ── FUNC 0x1f9934 · GV_PhysicsBullet(CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x1f9934 ldr r0, [r0, #0x84] */
/* @0x1f9938 push {r4, r5} */
/* @0x1f993c cmp r0, #0 */
/* @0x1f9940 beq 0x1f9974 <_Z16GV_PhysicsBulletP9CInstanceiP6RValue+0x40> */
/* @0x1f9944 ldr r3, [r0] */
/* @0x1f9948 mov r1, #0 */
/* @0x1f994c str r1, [r2, #0xc] */
/* @0x1f9950 mov r0, #1 */
/* @0x1f9954 ldrh r4, [r3, #4] */
/* @0x1f9958 ubfx r4, r4, #0x3, #0x1 */
/* @0x1f995c vmov s15, r4 */
/* @0x1f9960 vcvt.f64.u32 d7, s15 */
/* @0x1f9964 vmov r4, r5, d7 */
/* @0x1f9968 vmov r1, s14 */
/* @0x1f996c mov r3, r5 */
/* @0x1f9970 stm r2, {r1, r3} */
/* @0x1f9974 pop {r4, r5} */
/* @0x1f9978 bx lr */

/* ── FUNC 0x1f997c · GV_PhysicsBodySleeping(CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x1f997c ldr r0, [r0, #0x84] */
/* @0x1f9980 push {r4, r5} */
/* @0x1f9984 cmp r0, #0 */
/* @0x1f9988 beq 0x1f99c0 <_Z22GV_PhysicsBodySleepingP9CInstanceiP6RValue+0x44> */
/* @0x1f998c ldr r3, [r0] */
/* @0x1f9990 mov r1, #0 */
/* @0x1f9994 str r1, [r2, #0xc] */
/* @0x1f9998 mov r0, #1 */
/* @0x1f999c ldrh r4, [r3, #4] */
/* @0x1f99a0 eor r4, r4, #2 */
/* @0x1f99a4 ubfx r4, r4, #0x1, #0x1 */
/* @0x1f99a8 vmov s15, r4 */
/* @0x1f99ac vcvt.f64.u32 d7, s15 */
/* @0x1f99b0 vmov r4, r5, d7 */
/* @0x1f99b4 vmov r1, s14 */
/* @0x1f99b8 mov r3, r5 */
/* @0x1f99bc stm r2, {r1, r3} */
/* @0x1f99c0 pop {r4, r5} */
/* @0x1f99c4 bx lr */

/* ── FUNC 0x1f99c8 · GV_PhysicsPositionXPrevious(CInstance*, int, RValue*) · size=96 · insn=24 */
/* @0x1f99c8 ldr r3, [pc, #0x54] */
/* @0x1f99cc ldr r1, [r0, #0x84] */
/* @0x1f99d0 ldr r3, [pc, r3] */
/* @0x1f99d4 push {r4, r5} */
/* @0x1f99d8 ldr r3, [r3] */
/* @0x1f99dc ldr r3, [r3, #0xb4] */
/* @0x1f99e0 cmp r1, #0 */
/* @0x1f99e4 cmpne r3, #0 */
/* @0x1f99e8 moveq r0, #0 */
/* @0x1f99ec movne r0, #1 */
/* @0x1f99f0 beq 0x1f9a1c <_Z27GV_PhysicsPositionXPreviousP9CInstanceiP6RValue+0x54> */
/* @0x1f99f4 vldr s14, [r1, #12] */
/* @0x1f99f8 mov r12, #0 */
/* @0x1f99fc str r12, [r2, #0xc] */
/* @0x1f9a00 vldr s15, [r3, #96] */
/* @0x1f9a04 vdiv.f32 s15, s14, s15 */
/* @0x1f9a08 vcvt.f64.f32 d6, s15 */
/* @0x1f9a0c vmov r4, r5, d6 */
/* @0x1f9a10 vmov r1, s12 */
/* @0x1f9a14 mov r3, r5 */
/* @0x1f9a18 stm r2, {r1, r3} */
/* @0x1f9a1c pop {r4, r5} */
/* @0x1f9a20 bx lr */
/* @0x1f9a24 andseq r3, pc, r8, asr pc */

/* ── FUNC 0x1f9a28 · GV_PhysicsPositionYPrevious(CInstance*, int, RValue*) · size=96 · insn=24 */
/* @0x1f9a28 ldr r3, [pc, #0x54] */
/* @0x1f9a2c ldr r1, [r0, #0x84] */
/* @0x1f9a30 ldr r3, [pc, r3] */
/* @0x1f9a34 push {r4, r5} */
/* @0x1f9a38 ldr r3, [r3] */
/* @0x1f9a3c ldr r3, [r3, #0xb4] */
/* @0x1f9a40 cmp r1, #0 */
/* @0x1f9a44 cmpne r3, #0 */
/* @0x1f9a48 moveq r0, #0 */
/* @0x1f9a4c movne r0, #1 */
/* @0x1f9a50 beq 0x1f9a7c <_Z27GV_PhysicsPositionYPreviousP9CInstanceiP6RValue+0x54> */
/* @0x1f9a54 vldr s14, [r1, #16] */
/* @0x1f9a58 mov r12, #0 */
/* @0x1f9a5c str r12, [r2, #0xc] */
/* @0x1f9a60 vldr s15, [r3, #96] */
/* @0x1f9a64 vdiv.f32 s15, s14, s15 */
/* @0x1f9a68 vcvt.f64.f32 d6, s15 */
/* @0x1f9a6c vmov r4, r5, d6 */
/* @0x1f9a70 vmov r1, s12 */
/* @0x1f9a74 mov r3, r5 */
/* @0x1f9a78 stm r2, {r1, r3} */
/* @0x1f9a7c pop {r4, r5} */
/* @0x1f9a80 bx lr */
/* @0x1f9a84 ldrsheq r3, [pc], -r8 */

/* ── FUNC 0x1f9a88 · GV_GetDisplayAA(CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x1f9a88 ldr r3, [pc, #0x34] */
/* @0x1f9a8c mov r1, #0 */
/* @0x1f9a90 push {r4, r5} */
/* @0x1f9a94 ldr r3, [pc, r3] */
/* @0x1f9a98 str r1, [r2, #0xc] */
/* @0x1f9a9c mov r0, #1 */
/* @0x1f9aa0 ldr r4, [r3] */
/* @0x1f9aa4 vmov s15, r4 */
/* @0x1f9aa8 vcvt.f64.s32 d7, s15 */
/* @0x1f9aac vmov r4, r5, d7 */
/* @0x1f9ab0 vmov r1, s14 */
/* @0x1f9ab4 mov r3, r5 */
/* @0x1f9ab8 pop {r4, r5} */
/* @0x1f9abc stm r2, {r1, r3} */
/* @0x1f9ac0 bx lr */
/* @0x1f9ac4 andseq r7, pc, r8, lsr #7 */

/* ── FUNC 0x1f9ac8 · GV_GetDeltaTime(CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x1f9ac8 ldr r3, [pc, #0x28] */
/* @0x1f9acc push {r4, lr} */
/* @0x1f9ad0 ldr r3, [pc, r3] */
/* @0x1f9ad4 mov r4, r2 */
/* @0x1f9ad8 mov r2, #0 */
/* @0x1f9adc ldrd r0, r1, [r3] */
/* @0x1f9ae0 str r2, [r4, #0xc] */
/* @0x1f9ae4 bl 0x319164 <__floatdidf> */
/* @0x1f9ae8 str r0, [r4] */
/* @0x1f9aec mov r0, #1 */
/* @0x1f9af0 str r1, [r4, #0x4] */
/* @0x1f9af4 pop {r4, pc} */
/* @0x1f9af8 andseq r7, pc, r4, lsr #1 */

/* ── FUNC 0x1f9afc · GV_GetWebGLEnabled(CInstance*, int, RValue*) · size=32 · insn=8 */
/* @0x1f9afc mov r1, #0 */
/* @0x1f9b00 mov r0, #1 */
/* @0x1f9b04 mov r3, r1 */
/* @0x1f9b08 movt r1, #0x3ff0 */
/* @0x1f9b0c str r3, [r2, #0xc] */
/* @0x1f9b10 str r1, [r2, #0x4] */
/* @0x1f9b14 str r3, [r2] */
/* @0x1f9b18 bx lr */

/* ── FUNC 0x1f9b1c · GV_PhysicsFixedRotation(CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x1f9b1c ldr r0, [r0, #0x84] */
/* @0x1f9b20 push {r4, r5} */
/* @0x1f9b24 cmp r0, #0 */
/* @0x1f9b28 beq 0x1f9b5c <_Z23GV_PhysicsFixedRotationP9CInstanceiP6RValue+0x40> */
/* @0x1f9b2c ldr r3, [r0] */
/* @0x1f9b30 mov r1, #0 */
/* @0x1f9b34 str r1, [r2, #0xc] */
/* @0x1f9b38 mov r0, #1 */
/* @0x1f9b3c ldrh r4, [r3, #4] */
/* @0x1f9b40 ubfx r4, r4, #0x4, #0x1 */
/* @0x1f9b44 vmov s15, r4 */
/* @0x1f9b48 vcvt.f64.u32 d7, s15 */
/* @0x1f9b4c vmov r4, r5, d7 */
/* @0x1f9b50 vmov r1, s14 */
/* @0x1f9b54 mov r3, r5 */
/* @0x1f9b58 stm r2, {r1, r3} */
/* @0x1f9b5c pop {r4, r5} */
/* @0x1f9b60 bx lr */

/* ── FUNC 0x1f9b64 · GV_PhysicsActive(CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x1f9b64 ldr r0, [r0, #0x84] */
/* @0x1f9b68 push {r4, r5} */
/* @0x1f9b6c cmp r0, #0 */
/* @0x1f9b70 beq 0x1f9ba4 <_Z16GV_PhysicsActiveP9CInstanceiP6RValue+0x40> */
/* @0x1f9b74 ldr r3, [r0] */
/* @0x1f9b78 mov r1, #0 */
/* @0x1f9b7c str r1, [r2, #0xc] */
/* @0x1f9b80 mov r0, #1 */
/* @0x1f9b84 ldrh r4, [r3, #4] */
/* @0x1f9b88 ubfx r4, r4, #0x5, #0x1 */
/* @0x1f9b8c vmov s15, r4 */
/* @0x1f9b90 vcvt.f64.u32 d7, s15 */
/* @0x1f9b94 vmov r4, r5, d7 */
/* @0x1f9b98 vmov r1, s14 */
/* @0x1f9b9c mov r3, r5 */
/* @0x1f9ba0 stm r2, {r1, r3} */
/* @0x1f9ba4 pop {r4, r5} */
/* @0x1f9ba8 bx lr */

/* ── FUNC 0x1f9bac · GV_RoomFirst(CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x1f9bac push {r4, r5, r6, lr} */
/* @0x1f9bb0 mov r3, #0 */
/* @0x1f9bb4 str r3, [r2, #0xc] */
/* @0x1f9bb8 mov r6, r2 */
/* @0x1f9bbc bl 0x1b5d08 <_Z10Room_Firstv> */
/* @0x1f9bc0 vmov s15, r0 */
/* @0x1f9bc4 mov r0, #1 */
/* @0x1f9bc8 vcvt.f64.s32 d7, s15 */
/* @0x1f9bcc vmov r4, r5, d7 */
/* @0x1f9bd0 vmov r2, s14 */
/* @0x1f9bd4 mov r3, r5 */
/* @0x1f9bd8 stm r6, {r2, r3} */
/* @0x1f9bdc pop {r4, r5, r6, pc} */

/* ── FUNC 0x1f9be0 · GV_RoomLast(CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x1f9be0 push {r4, r5, r6, lr} */
/* @0x1f9be4 mov r3, #0 */
/* @0x1f9be8 str r3, [r2, #0xc] */
/* @0x1f9bec mov r6, r2 */
/* @0x1f9bf0 bl 0x1b5d20 <_Z9Room_Lastv> */
/* @0x1f9bf4 vmov s15, r0 */
/* @0x1f9bf8 mov r0, #1 */
/* @0x1f9bfc vcvt.f64.s32 d7, s15 */
/* @0x1f9c00 vmov r4, r5, d7 */
/* @0x1f9c04 vmov r2, s14 */
/* @0x1f9c08 mov r3, r5 */
/* @0x1f9c0c stm r6, {r2, r3} */
/* @0x1f9c10 pop {r4, r5, r6, pc} */

/* ── FUNC 0x1f9c14 · GV_GameDisplayName(CInstance*, int, RValue*) · size=36 · insn=9 */
/* @0x1f9c14 push {r3, lr} */
/* @0x1f9c18 mov r0, r2 */
/* @0x1f9c1c ldr r3, [pc, #0x10] */
/* @0x1f9c20 ldr r3, [pc, r3] */
/* @0x1f9c24 ldr r1, [r3] */
/* @0x1f9c28 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x1f9c2c mov r0, #1 */
/* @0x1f9c30 pop {r3, pc} */
/* @0x1f9c34 andseq r4, pc, r4, ror lr */

/* ── FUNC 0x1f9c38 · GV_GameProjectName(CInstance*, int, RValue*) · size=36 · insn=9 */
/* @0x1f9c38 push {r3, lr} */
/* @0x1f9c3c mov r0, r2 */
/* @0x1f9c40 ldr r3, [pc, #0x10] */
/* @0x1f9c44 ldr r3, [pc, r3] */
/* @0x1f9c48 ldr r1, [r3] */
/* @0x1f9c4c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x1f9c50 mov r0, #1 */
/* @0x1f9c54 pop {r3, pc} */
/* @0x1f9c58 andseq r6, pc, r4, lsr #30 */

/* ── FUNC 0x1f9c5c · GV_GameGuId(CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x1f9c5c mov r0, r2 */
/* @0x1f9c60 mov r1, #0 */
/* @0x1f9c64 push {r3, lr} */
/* @0x1f9c68 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x1f9c6c mov r0, #1 */
/* @0x1f9c70 pop {r3, pc} */

/* ── FUNC 0x1f9c74 · GV_WorkingDirectory(CInstance*, int, RValue*) · size=36 · insn=9 */
/* @0x1f9c74 push {r3, lr} */
/* @0x1f9c78 mov r0, r2 */
/* @0x1f9c7c ldr r3, [pc, #0x10] */
/* @0x1f9c80 ldr r3, [pc, r3] */
/* @0x1f9c84 ldr r1, [r3] */
/* @0x1f9c88 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x1f9c8c mov r0, #1 */
/* @0x1f9c90 pop {r3, pc} */
/* @0x1f9c94 ldrsbeq r6, [pc], -r8 */

/* ── FUNC 0x1f9c98 · GV_RoomCaption(CInstance*, int, RValue*) · size=40 · insn=10 */
/* @0x1f9c98 push {r3, lr} */
/* @0x1f9c9c mov r0, r2 */
/* @0x1f9ca0 ldr r3, [pc, #0x14] */
/* @0x1f9ca4 ldr r3, [pc, r3] */
/* @0x1f9ca8 ldr r3, [r3] */
/* @0x1f9cac ldr r1, [r3, #0x8] */
/* @0x1f9cb0 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x1f9cb4 mov r0, #1 */
/* @0x1f9cb8 pop {r3, pc} */
/* @0x1f9cbc andseq r3, pc, r4, lsl #25 */

/* ── FUNC 0x1f9cc0 · GV_ProgramDirectory(CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x1f9cc0 push {r3, r4, r5, lr} */
/* @0x1f9cc4 mov r5, r2 */
/* @0x1f9cc8 bl 0x28fe50 <GetExeName> */
/* @0x1f9ccc bl 0x214f5c <_Z15ExtractFilePathPKc> */
/* @0x1f9cd0 mov r4, r0 */
/* @0x1f9cd4 bl 0xb6538 <strlen@plt> */
/* @0x1f9cd8 mov r1, r4 */
/* @0x1f9cdc sub r0, r0, #1 */
/* @0x1f9ce0 ldrb r3, [r4, r0] */
/* @0x1f9ce4 cmp r3, #92 */
/* @0x1f9ce8 cmpne r3, #47 */
/* @0x1f9cec moveq r3, #0 */
/* @0x1f9cf0 strbeq r3, [r4, r0] */
/* @0x1f9cf4 mov r0, r5 */
/* @0x1f9cf8 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x1f9cfc mov r0, r4 */
/* @0x1f9d00 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f9d04 mov r0, #1 */
/* @0x1f9d08 pop {r3, r4, r5, pc} */

/* ── FUNC 0x1f9d0c · GV_SaveDirectory(CInstance*, int, RValue*) · size=32 · insn=8 */
/* @0x1f9d0c push {r4, lr} */
/* @0x1f9d10 mov r4, r2 */
/* @0x1f9d14 bl 0x28fd6c <_Z14GetSavePrePendv> */
/* @0x1f9d18 mov r1, r0 */
/* @0x1f9d1c mov r0, r4 */
/* @0x1f9d20 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x1f9d24 mov r0, #1 */
/* @0x1f9d28 pop {r4, pc} */

/* ── FUNC 0x1f9d2c · GV_TempDirectory(CInstance*, int, RValue*) · size=44 · insn=11 */
/* @0x1f9d2c push {r3, r4, r5, lr} */
/* @0x1f9d30 mov r5, r2 */
/* @0x1f9d34 bl 0x214dfc <_Z12File_TempDirv> */
/* @0x1f9d38 mov r4, r0 */
/* @0x1f9d3c mov r0, r5 */
/* @0x1f9d40 mov r1, r4 */
/* @0x1f9d44 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x1f9d48 mov r0, r4 */
/* @0x1f9d4c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f9d50 mov r0, #1 */
/* @0x1f9d54 pop {r3, r4, r5, pc} */

/* ── FUNC 0x1f9d58 · GV_PhysicsSpeedX(CInstance*, int, RValue*) · size=228 · insn=57 */
/* @0x1f9d58 ldr r3, [pc, #0xd0] */
/* @0x1f9d5c ldr r1, [r0, #0x84] */
/* @0x1f9d60 ldr r3, [pc, r3] */
/* @0x1f9d64 push {r4, r5, r6, lr} */
/* @0x1f9d68 vpush {d8} */
/* @0x1f9d6c sub sp, sp, #8 */
/* @0x1f9d70 ldr r12, [r3] */
/* @0x1f9d74 ldr r3, [r12, #0xb4] */
/* @0x1f9d78 cmp r1, #0 */
/* @0x1f9d7c cmpne r3, #0 */
/* @0x1f9d80 moveq r6, #0 */
/* @0x1f9d84 movne r6, #1 */
/* @0x1f9d88 beq 0x1f9dd8 <_Z16GV_PhysicsSpeedXP9CInstanceiP6RValue+0x80> */
/* @0x1f9d8c ldr r4, [pc, #0xa0] */
/* @0x1f9d90 mov r0, #0 */
/* @0x1f9d94 str r0, [r2, #0xc] */
/* @0x1f9d98 vldr s15, [r3, #96] */
/* @0x1f9d9c ldr r4, [pc, r4] */
/* @0x1f9da0 ldr r1, [r1] */
/* @0x1f9da4 ldrb r0, [r4] */
/* @0x1f9da8 cmp r0, #0 */
/* @0x1f9dac bne 0x1f9de8 <_Z16GV_PhysicsSpeedXP9CInstanceiP6RValue+0x90> */
/* @0x1f9db0 vldr s13, [r1, #80] */
/* @0x1f9db4 vdiv.f32 s13, s13, s15 */
/* @0x1f9db8 vldr s14, [r12, #12] */
/* @0x1f9dbc vcvt.f32.s32 s14, s14 */
/* @0x1f9dc0 vdiv.f32 s15, s13, s14 */
/* @0x1f9dc4 vcvt.f64.f32 d6, s15 */
/* @0x1f9dc8 vmov r4, r5, d6 */
/* @0x1f9dcc vmov r1, s12 */
/* @0x1f9dd0 mov r3, r5 */
/* @0x1f9dd4 stm r2, {r1, r3} */
/* @0x1f9dd8 mov r0, r6 */
/* @0x1f9ddc add sp, sp, #8 */
/* @0x1f9de0 vpop {d8} */
/* @0x1f9de4 pop {r4, r5, r6, pc} */
/* @0x1f9de8 vldr s16, [r1, #80] */
/* @0x1f9dec vdiv.f32 s16, s16, s15 */
/* @0x1f9df0 ldr r0, [pc, #0x40] */
/* @0x1f9df4 str r2, [sp, #0x4] */
/* @0x1f9df8 ldr r0, [pc, r0] */
/* @0x1f9dfc bl 0x214808 <_ZN13CTimingSource6GetFPSEv> */
/* @0x1f9e00 ldr r2, [sp, #0x4] */
/* @0x1f9e04 vmov d6, r0, r1 */
/* @0x1f9e08 mov r0, r6 */
/* @0x1f9e0c vcvt.f64.f32 d8, s16 */
/* @0x1f9e10 vdiv.f64 d6, d8, d6 */
/* @0x1f9e14 vmov r4, r5, d6 */
/* @0x1f9e18 vmov r1, s12 */
/* @0x1f9e1c mov r3, r5 */
/* @0x1f9e20 stm r2, {r1, r3} */
/* @0x1f9e24 add sp, sp, #8 */
/* @0x1f9e28 vpop {d8} */
/* @0x1f9e2c pop {r4, r5, r6, pc} */
/* @0x1f9e30 andseq r3, pc, r8, asr #23 */
/* @0x1f9e34 andseq r3, pc, r8, lsl #23 */
/* @0x1f9e38 andseq r3, pc, r4, lsr r11 */

/* ── FUNC 0x1f9e3c · GV_PhysicsSpeedY(CInstance*, int, RValue*) · size=228 · insn=57 */
/* @0x1f9e3c ldr r3, [pc, #0xd0] */
/* @0x1f9e40 ldr r1, [r0, #0x84] */
/* @0x1f9e44 ldr r3, [pc, r3] */
/* @0x1f9e48 push {r4, r5, r6, lr} */
/* @0x1f9e4c vpush {d8} */
/* @0x1f9e50 sub sp, sp, #8 */
/* @0x1f9e54 ldr r12, [r3] */
/* @0x1f9e58 ldr r3, [r12, #0xb4] */
/* @0x1f9e5c cmp r1, #0 */
/* @0x1f9e60 cmpne r3, #0 */
/* @0x1f9e64 moveq r6, #0 */
/* @0x1f9e68 movne r6, #1 */
/* @0x1f9e6c beq 0x1f9ebc <_Z16GV_PhysicsSpeedYP9CInstanceiP6RValue+0x80> */
/* @0x1f9e70 ldr r4, [pc, #0xa0] */
/* @0x1f9e74 mov r0, #0 */
/* @0x1f9e78 str r0, [r2, #0xc] */
/* @0x1f9e7c vldr s15, [r3, #96] */
/* @0x1f9e80 ldr r4, [pc, r4] */
/* @0x1f9e84 ldr r1, [r1] */
/* @0x1f9e88 ldrb r0, [r4] */
/* @0x1f9e8c cmp r0, #0 */
/* @0x1f9e90 bne 0x1f9ecc <_Z16GV_PhysicsSpeedYP9CInstanceiP6RValue+0x90> */
/* @0x1f9e94 vldr s13, [r1, #84] */
/* @0x1f9e98 vdiv.f32 s13, s13, s15 */
/* @0x1f9e9c vldr s14, [r12, #12] */
/* @0x1f9ea0 vcvt.f32.s32 s14, s14 */
/* @0x1f9ea4 vdiv.f32 s15, s13, s14 */
/* @0x1f9ea8 vcvt.f64.f32 d6, s15 */
/* @0x1f9eac vmov r4, r5, d6 */
/* @0x1f9eb0 vmov r1, s12 */
/* @0x1f9eb4 mov r3, r5 */
/* @0x1f9eb8 stm r2, {r1, r3} */
/* @0x1f9ebc mov r0, r6 */
/* @0x1f9ec0 add sp, sp, #8 */
/* @0x1f9ec4 vpop {d8} */
/* @0x1f9ec8 pop {r4, r5, r6, pc} */
/* @0x1f9ecc vldr s16, [r1, #84] */
/* @0x1f9ed0 vdiv.f32 s16, s16, s15 */
/* @0x1f9ed4 ldr r0, [pc, #0x40] */
/* @0x1f9ed8 str r2, [sp, #0x4] */
/* @0x1f9edc ldr r0, [pc, r0] */
/* @0x1f9ee0 bl 0x214808 <_ZN13CTimingSource6GetFPSEv> */
/* @0x1f9ee4 ldr r2, [sp, #0x4] */
/* @0x1f9ee8 vmov d6, r0, r1 */
/* @0x1f9eec mov r0, r6 */
/* @0x1f9ef0 vcvt.f64.f32 d8, s16 */
/* @0x1f9ef4 vdiv.f64 d6, d8, d6 */
/* @0x1f9ef8 vmov r4, r5, d6 */
/* @0x1f9efc vmov r1, s12 */
/* @0x1f9f00 mov r3, r5 */
/* @0x1f9f04 stm r2, {r1, r3} */
/* @0x1f9f08 add sp, sp, #8 */
/* @0x1f9f0c vpop {d8} */
/* @0x1f9f10 pop {r4, r5, r6, pc} */
/* @0x1f9f14 andseq r3, pc, r4, ror #21 */
/* @0x1f9f18 andseq r3, pc, r4, lsr #21 */
/* @0x1f9f1c andseq r3, pc, r0, asr r10 */

/* ── FUNC 0x1f9f20 · GV_BackgroundWidth(CInstance*, int, RValue*) · size=120 · insn=30 */
/* @0x1f9f20 push {r3, r4, r5, lr} */
/* @0x1f9f24 cmp r1, #7 */
/* @0x1f9f28 ldr r3, [pc, #0x64] */
/* @0x1f9f2c mov r4, r2 */
/* @0x1f9f30 mov r2, #0 */
/* @0x1f9f34 str r2, [r4] */
/* @0x1f9f38 ldr r3, [pc, r3] */
/* @0x1f9f3c movhi r1, #0 */
/* @0x1f9f40 str r2, [r4, #0x4] */
/* @0x1f9f44 ldr r3, [r3] */
/* @0x1f9f48 str r2, [r4, #0xc] */
/* @0x1f9f4c add r1, r3, r1, lsl #2 */
/* @0x1f9f50 ldr r3, [r1, #0x24] */
/* @0x1f9f54 ldr r5, [r3, #0x4] */
/* @0x1f9f58 mov r0, r5 */
/* @0x1f9f5c bl 0xc3640 <_Z17Background_Existsi> */
/* @0x1f9f60 cmp r0, #0 */
/* @0x1f9f64 beq 0x1f9f8c <_Z18GV_BackgroundWidthP9CInstanceiP6RValue+0x6c> */
/* @0x1f9f68 mov r0, r5 */
/* @0x1f9f6c bl 0xc3794 <_Z15Background_Datai> */
/* @0x1f9f70 bl 0xc2d78 <_ZN11CBackground8GetWidthEv> */
/* @0x1f9f74 vmov s15, r0 */
/* @0x1f9f78 vcvt.f64.s32 d7, s15 */
/* @0x1f9f7c vmov r0, r1, d7 */
/* @0x1f9f80 vmov r2, s14 */
/* @0x1f9f84 mov r3, r1 */
/* @0x1f9f88 stm r4, {r2, r3} */
/* @0x1f9f8c mov r0, #1 */
/* @0x1f9f90 pop {r3, r4, r5, pc} */
/* @0x1f9f94 ldrsheq r3, [pc], -r0 */

/* ── FUNC 0x1f9f98 · GV_BackgroundHeight(CInstance*, int, RValue*) · size=120 · insn=30 */
/* @0x1f9f98 push {r3, r4, r5, lr} */
/* @0x1f9f9c cmp r1, #7 */
/* @0x1f9fa0 ldr r3, [pc, #0x64] */
/* @0x1f9fa4 mov r4, r2 */
/* @0x1f9fa8 mov r2, #0 */
/* @0x1f9fac str r2, [r4] */
/* @0x1f9fb0 ldr r3, [pc, r3] */
/* @0x1f9fb4 movhi r1, #0 */
/* @0x1f9fb8 str r2, [r4, #0x4] */
/* @0x1f9fbc ldr r3, [r3] */
/* @0x1f9fc0 str r2, [r4, #0xc] */
/* @0x1f9fc4 add r1, r3, r1, lsl #2 */
/* @0x1f9fc8 ldr r3, [r1, #0x24] */
/* @0x1f9fcc ldr r5, [r3, #0x4] */
/* @0x1f9fd0 mov r0, r5 */
/* @0x1f9fd4 bl 0xc3640 <_Z17Background_Existsi> */
/* @0x1f9fd8 cmp r0, #0 */
/* @0x1f9fdc beq 0x1fa004 <_Z19GV_BackgroundHeightP9CInstanceiP6RValue+0x6c> */
/* @0x1f9fe0 mov r0, r5 */
/* @0x1f9fe4 bl 0xc3794 <_Z15Background_Datai> */
/* @0x1f9fe8 bl 0xc2d80 <_ZN11CBackground9GetHeightEv> */
/* @0x1f9fec vmov s15, r0 */
/* @0x1f9ff0 vcvt.f64.s32 d7, s15 */
/* @0x1f9ff4 vmov r0, r1, d7 */
/* @0x1f9ff8 vmov r2, s14 */
/* @0x1f9ffc mov r3, r1 */
/* @0x1fa000 stm r4, {r2, r3} */
/* @0x1fa004 mov r0, #1 */
/* @0x1fa008 pop {r3, r4, r5, pc} */
/* @0x1fa00c andseq r3, pc, r8, ror r9 */

/* ── FUNC 0x1fa010 · GV_MouseX(CInstance*, int, RValue*) · size=56 · insn=14 */
/* @0x1fa010 mov r3, #0 */
/* @0x1fa014 push {r4, r5, r6, lr} */
/* @0x1fa018 mov r0, r3 */
/* @0x1fa01c str r3, [r2, #0xc] */
/* @0x1fa020 mov r6, r2 */
/* @0x1fa024 bl 0x17ad8c <_Z27GR_Window_Views_Mouse_Get_Xi> */
/* @0x1fa028 vmov s15, r0 */
/* @0x1fa02c mov r0, #1 */
/* @0x1fa030 vcvt.f64.s32 d7, s15 */
/* @0x1fa034 vmov r4, r5, d7 */
/* @0x1fa038 vmov r2, s14 */
/* @0x1fa03c mov r3, r5 */
/* @0x1fa040 stm r6, {r2, r3} */
/* @0x1fa044 pop {r4, r5, r6, pc} */
