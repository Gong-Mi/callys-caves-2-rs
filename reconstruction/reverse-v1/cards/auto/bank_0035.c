/* libyoyo.so 覆盖卡组 0035
 * 函数 0x10ac78..0x10c678，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x10ac78 · YYGML_move_snap(CInstance*, float, float) · size=4 · insn=1 */
/* @0x10ac78 b 0x1c9594 <_Z12Command_SnapP9CInstanceff> */

/* ── FUNC 0x10ac7c · YYGML_motion_set(CInstance*, float, float) · size=32 · insn=8 */
/* @0x10ac7c push {r3, r4, r5, lr} */
/* @0x10ac80 mov r4, r2 */
/* @0x10ac84 mov r5, r0 */
/* @0x10ac88 bl 0x193064 <_ZN9CInstance12SetDirectionEf> */
/* @0x10ac8c mov r0, r5 */
/* @0x10ac90 mov r1, r4 */
/* @0x10ac94 pop {r3, r4, r5, lr} */
/* @0x10ac98 b 0x1930d4 <_ZN9CInstance8SetSpeedEf> */

/* ── FUNC 0x10ac9c · FindDist(CInstance*, CInstance*) · size=236 · insn=59 */
/* @0x10ac9c cmp r0, #0 */
/* @0x10aca0 cmpne r0, r1 */
/* @0x10aca4 push {r3, r4, r5, lr} */
/* @0x10aca8 mov r5, r1 */
/* @0x10acac mov r4, r0 */
/* @0x10acb0 beq 0x10acc0 <_Z8FindDistP9CInstanceS0_+0x24> */
/* @0x10acb4 ldrb r3, [r0, #0x68] */
/* @0x10acb8 cmp r3, #0 */
/* @0x10acbc beq 0x10accc <_Z8FindDistP9CInstanceS0_+0x30> */
/* @0x10acc0 mov r0, #9216 */
/* @0x10acc4 movt r0, #0x4974 */
/* @0x10acc8 pop {r3, r4, r5, pc} */
/* @0x10accc ldrb r3, [r0, #0x69] */
/* @0x10acd0 cmp r3, #0 */
/* @0x10acd4 bne 0x10acc0 <_Z8FindDistP9CInstanceS0_+0x24> */
/* @0x10acd8 ldrb r3, [r0, #0x64] */
/* @0x10acdc cmp r3, #0 */
/* @0x10ace0 beq 0x10acec <_Z8FindDistP9CInstanceS0_+0x50> */
/* @0x10ace4 mov r1, #1 */
/* @0x10ace8 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x10acec ldrb r3, [r5, #0x64] */
/* @0x10acf0 cmp r3, #0 */
/* @0x10acf4 bne 0x10ad68 <_Z8FindDistP9CInstanceS0_+0xcc> */
/* @0x10acf8 ldr r3, [r5, #0xf0] */
/* @0x10acfc ldr r2, [r4, #0xe8] */
/* @0x10ad00 ldr r1, [r4, #0xf0] */
/* @0x10ad04 cmp r2, r3 */
/* @0x10ad08 ldr r0, [r4, #0xf4] */
/* @0x10ad0c rsbgt r3, r3, r2 */
/* @0x10ad10 ldr r2, [r5, #0xe8] */
/* @0x10ad14 movle r3, #0 */
/* @0x10ad18 cmp r1, r2 */
/* @0x10ad1c rsblt r3, r2, r1 */
/* @0x10ad20 ldr r2, [r5, #0xf4] */
/* @0x10ad24 ldr r1, [r4, #0xec] */
/* @0x10ad28 cmp r1, r2 */
/* @0x10ad2c rsbgt r2, r2, r1 */
/* @0x10ad30 ldr r1, [r5, #0xec] */
/* @0x10ad34 movle r2, #0 */
/* @0x10ad38 cmp r0, r1 */
/* @0x10ad3c rsblt r2, r1, r0 */
/* @0x10ad40 mul r2, r2, r2 */
/* @0x10ad44 mla r3, r3, r3, r2 */
/* @0x10ad48 vmov s15, r3 */
/* @0x10ad4c vcvt.f32.s32 s14, s15 */
/* @0x10ad50 vsqrt.f32 s15, s14 */
/* @0x10ad54 vcmp.f32 s15, s15 */
/* @0x10ad58 vmrs APSR_nzcv, fpscr */
/* @0x10ad5c bne 0x10ad78 <_Z8FindDistP9CInstanceS0_+0xdc> */
/* @0x10ad60 vmov r0, s15 */
/* @0x10ad64 pop {r3, r4, r5, pc} */
/* @0x10ad68 mov r0, r5 */
/* @0x10ad6c mov r1, #1 */
/* @0x10ad70 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x10ad74 b 0x10acf8 <_Z8FindDistP9CInstanceS0_+0x5c> */
/* @0x10ad78 vmov r0, s14 */
/* @0x10ad7c bl 0xb6700 <sqrtf@plt> */
/* @0x10ad80 vmov s15, r0 */
/* @0x10ad84 b 0x10ad60 <_Z8FindDistP9CInstanceS0_+0xc4> */

/* ── FUNC 0x10ad88 · F_DistanceToObject(RValue&, CInstance*, CInstance*, int, RValue*) · size=244 · insn=61 */
/* @0x10ad88 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x10ad8c sub sp, sp, #52 */
/* @0x10ad90 mov r4, #0 */
/* @0x10ad94 mov r9, r1 */
/* @0x10ad98 str r4, [r0, #0xc] */
/* @0x10ad9c mov r1, r4 */
/* @0x10ada0 str r4, [r0] */
/* @0x10ada4 mov r8, r0 */
/* @0x10ada8 movw r3, #0x8480 */
/* @0x10adac movt r3, #0x412e */
/* @0x10adb0 str r3, [r0, #0x4] */
/* @0x10adb4 mov r5, r2 */
/* @0x10adb8 ldr r0, [sp, #0x50] */
/* @0x10adbc add r6, sp, #12 */
/* @0x10adc0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x10adc4 str r4, [sp] */
/* @0x10adc8 mov r3, r5 */
/* @0x10adcc mov r2, r9 */
/* @0x10add0 mov r1, r0 */
/* @0x10add4 mov r0, r6 */
/* @0x10add8 bl 0x19d060 <_ZN15WithObjIteratorC2EiP9CInstanceS1_b> */
/* @0x10addc mov r0, r6 */
/* @0x10ade0 bl 0x19de4c <_ZN15WithObjIteratordeEv> */
/* @0x10ade4 cmp r0, #0 */
/* @0x10ade8 mov r0, r6 */
/* @0x10adec beq 0x10ae58 <_Z18F_DistanceToObjectR6RValueP9CInstanceS2_iPS_+0xd0> */
/* @0x10adf0 bl 0x19de4c <_ZN15WithObjIteratordeEv> */
/* @0x10adf4 mov r7, r0 */
/* @0x10adf8 mov r0, r6 */
/* @0x10adfc bl 0x19d1c8 <_ZN15WithObjIterator4NextEv> */
/* @0x10ae00 ldrb r3, [r7, #0x68] */
/* @0x10ae04 cmp r3, #0 */
/* @0x10ae08 bne 0x10addc <_Z18F_DistanceToObjectR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x10ae0c ldrb r3, [r7, #0x69] */
/* @0x10ae10 cmp r3, #0 */
/* @0x10ae14 bne 0x10addc <_Z18F_DistanceToObjectR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x10ae18 mov r0, r7 */
/* @0x10ae1c mov r1, r9 */
/* @0x10ae20 ldr r4, [r8] */
/* @0x10ae24 ldr r5, [r8, #0x4] */
/* @0x10ae28 bl 0x10ac9c <_Z8FindDistP9CInstanceS0_> */
/* @0x10ae2c vmov s12, r0 */
/* @0x10ae30 vcvt.f64.f32 d7, s12 */
/* @0x10ae34 vmov d6, r4, r5 */
/* @0x10ae38 vcmpe.f64 d6, d7 */
/* @0x10ae3c vmrs APSR_nzcv, fpscr */
/* @0x10ae40 bpl 0x10ae60 <_Z18F_DistanceToObjectR6RValueP9CInstanceS2_iPS_+0xd8> */
/* @0x10ae44 ldm r8, {r0, r1} */
/* @0x10ae48 mov r2, r0 */
/* @0x10ae4c mov r3, r1 */
/* @0x10ae50 stm r8, {r2, r3} */
/* @0x10ae54 b 0x10addc <_Z18F_DistanceToObjectR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x10ae58 add sp, sp, #52 */
/* @0x10ae5c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x10ae60 mov r1, r9 */
/* @0x10ae64 mov r0, r7 */
/* @0x10ae68 bl 0x10ac9c <_Z8FindDistP9CInstanceS0_> */
/* @0x10ae6c vmov s13, r0 */
/* @0x10ae70 vcvt.f64.f32 d6, s13 */
/* @0x10ae74 vmov r0, r1, d6 */
/* @0x10ae78 b 0x10ae48 <_Z18F_DistanceToObjectR6RValueP9CInstanceS2_iPS_+0xc0> */

/* ── FUNC 0x10ae7c · YYGML_instance_waiting_for_activation(int) · size=152 · insn=38 */
/* @0x10ae7c ldr r3, [pc, #0x8c] */
/* @0x10ae80 push {r4, r5} */
/* @0x10ae84 ldr r3, [pc, r3] */
/* @0x10ae88 ldr r4, [r3, #0x8] */
/* @0x10ae8c cmp r4, #0 */
/* @0x10ae90 ble 0x10aef8 <_Z37YYGML_instance_waiting_for_activationi+0x7c> */
/* @0x10ae94 ldr r5, [r3] */
/* @0x10ae98 mov r1, #0 */
/* @0x10ae9c ldr r3, [r5, r1, lsl #2] */
/* @0x10aea0 ldrb r2, [r3, #0x68] */
/* @0x10aea4 cmp r2, #0 */
/* @0x10aea8 bne 0x10aeec <_Z37YYGML_instance_waiting_for_activationi+0x70> */
/* @0x10aeac ldrb r2, [r3, #0x69] */
/* @0x10aeb0 cmp r2, #0 */
/* @0x10aeb4 bne 0x10aeec <_Z37YYGML_instance_waiting_for_activationi+0x70> */
/* @0x10aeb8 ldr r3, [r3, #0x80] */
/* @0x10aebc cmp r3, #0 */
/* @0x10aec0 beq 0x10aeec <_Z37YYGML_instance_waiting_for_activationi+0x70> */
/* @0x10aec4 ldr r2, [r3, #0x18] */
/* @0x10aec8 ldr r3, [r3, #0x48] */
/* @0x10aecc cmp r0, r2 */
/* @0x10aed0 movne r12, #0 */
/* @0x10aed4 moveq r12, #1 */
/* @0x10aed8 cmp r0, r2 */
/* @0x10aedc cmpne r3, #0 */
/* @0x10aee0 bne 0x10aec4 <_Z37YYGML_instance_waiting_for_activationi+0x48> */
/* @0x10aee4 cmp r12, #0 */
/* @0x10aee8 bne 0x10af04 <_Z37YYGML_instance_waiting_for_activationi+0x88> */
/* @0x10aeec add r1, r1, #1 */
/* @0x10aef0 cmp r1, r4 */
/* @0x10aef4 bne 0x10ae9c <_Z37YYGML_instance_waiting_for_activationi+0x20> */
/* @0x10aef8 mov r0, #0 */
/* @0x10aefc pop {r4, r5} */
/* @0x10af00 bx lr */
/* @0x10af04 mov r0, #1 */
/* @0x10af08 pop {r4, r5} */
/* @0x10af0c bx lr */
/* @0x10af10 eoreq r2, lr, r4, asr #27 */

/* ── FUNC 0x10af14 · YYGML_instance_exists(CInstance*, CInstance*, int) · size=128 · insn=32 */
/* @0x10af14 push {r4, r5, lr} */
/* @0x10af18 sub sp, sp, #52 */
/* @0x10af1c add r4, sp, #12 */
/* @0x10af20 mov r12, r0 */
/* @0x10af24 mov r3, r1 */
/* @0x10af28 mov r1, r2 */
/* @0x10af2c mov r0, r4 */
/* @0x10af30 mov r2, r12 */
/* @0x10af34 mov r12, #0 */
/* @0x10af38 str r12, [sp] */
/* @0x10af3c bl 0x19d060 <_ZN15WithObjIteratorC2EiP9CInstanceS1_b> */
/* @0x10af40 mov r0, r4 */
/* @0x10af44 bl 0x19de4c <_ZN15WithObjIteratordeEv> */
/* @0x10af48 subs r3, r0, #0 */
/* @0x10af4c mov r0, r4 */
/* @0x10af50 beq 0x10af88 <_Z21YYGML_instance_existsP9CInstanceS0_i+0x74> */
/* @0x10af54 bl 0x19de4c <_ZN15WithObjIteratordeEv> */
/* @0x10af58 mov r5, r0 */
/* @0x10af5c mov r0, r4 */
/* @0x10af60 bl 0x19d1c8 <_ZN15WithObjIterator4NextEv> */
/* @0x10af64 ldrb r3, [r5, #0x68] */
/* @0x10af68 cmp r3, #0 */
/* @0x10af6c bne 0x10af40 <_Z21YYGML_instance_existsP9CInstanceS0_i+0x2c> */
/* @0x10af70 ldrb r3, [r5, #0x69] */
/* @0x10af74 cmp r3, #0 */
/* @0x10af78 bne 0x10af40 <_Z21YYGML_instance_existsP9CInstanceS0_i+0x2c> */
/* @0x10af7c mov r0, #1 */
/* @0x10af80 add sp, sp, #52 */
/* @0x10af84 pop {r4, r5, pc} */
/* @0x10af88 mov r0, r3 */
/* @0x10af8c add sp, sp, #52 */
/* @0x10af90 pop {r4, r5, pc} */

/* ── FUNC 0x10af94 · F_InstanceExists(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x10af94 push {r4, r5, r6, lr} */
/* @0x10af98 mov r3, #0 */
/* @0x10af9c mov r4, r0 */
/* @0x10afa0 str r3, [r0, #0xc] */
/* @0x10afa4 mov r5, r1 */
/* @0x10afa8 ldr r0, [sp, #0x10] */
/* @0x10afac mov r1, r3 */
/* @0x10afb0 mov r6, r2 */
/* @0x10afb4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x10afb8 mov r1, r6 */
/* @0x10afbc mov r2, r0 */
/* @0x10afc0 mov r0, r5 */
/* @0x10afc4 bl 0x10af14 <_Z21YYGML_instance_existsP9CInstanceS0_i> */
/* @0x10afc8 vmov s15, r0 */
/* @0x10afcc vcvt.f64.u32 d7, s15 */
/* @0x10afd0 vmov r0, r1, d7 */
/* @0x10afd4 vmov r2, s14 */
/* @0x10afd8 mov r3, r1 */
/* @0x10afdc stm r4, {r2, r3} */
/* @0x10afe0 pop {r4, r5, r6, pc} */

/* ── FUNC 0x10afe4 · YYGML_instance_number(CInstance*, CInstance*, int) · size=104 · insn=26 */
/* @0x10afe4 cmn r2, #2 */
/* @0x10afe8 beq 0x10b01c <_Z21YYGML_instance_numberP9CInstanceS0_i+0x38> */
/* @0x10afec cmn r2, #1 */
/* @0x10aff0 bne 0x10b014 <_Z21YYGML_instance_numberP9CInstanceS0_i+0x30> */
/* @0x10aff4 cmp r0, #0 */
/* @0x10aff8 bxeq lr */
/* @0x10affc ldrb r3, [r0, #0x68] */
/* @0x10b000 cmp r3, #0 */
/* @0x10b004 bne 0x10b030 <_Z21YYGML_instance_numberP9CInstanceS0_i+0x4c> */
/* @0x10b008 ldrb r0, [r0, #0x69] */
/* @0x10b00c eor r0, r0, #1 */
/* @0x10b010 bx lr */
/* @0x10b014 mov r0, r2 */
/* @0x10b018 b 0x1c8ed0 <_Z22Command_InstanceNumberi> */
/* @0x10b01c cmp r1, #0 */
/* @0x10b020 beq 0x10b044 <_Z21YYGML_instance_numberP9CInstanceS0_i+0x60> */
/* @0x10b024 ldrb r3, [r1, #0x68] */
/* @0x10b028 cmp r3, #0 */
/* @0x10b02c beq 0x10b038 <_Z21YYGML_instance_numberP9CInstanceS0_i+0x54> */
/* @0x10b030 mov r0, #0 */
/* @0x10b034 bx lr */
/* @0x10b038 ldrb r0, [r1, #0x69] */
/* @0x10b03c eor r0, r0, #1 */
/* @0x10b040 bx lr */
/* @0x10b044 mov r0, r1 */
/* @0x10b048 bx lr */

/* ── FUNC 0x10b04c · F_InstanceNumber(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x10b04c push {r4, r5, r6, lr} */
/* @0x10b050 mov r4, r0 */
/* @0x10b054 mov r5, r1 */
/* @0x10b058 ldr r0, [sp, #0x10] */
/* @0x10b05c mov r1, #0 */
/* @0x10b060 mov r6, r2 */
/* @0x10b064 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x10b068 mov r3, #0 */
/* @0x10b06c mov r1, r6 */
/* @0x10b070 str r3, [r4, #0xc] */
/* @0x10b074 mov r2, r0 */
/* @0x10b078 mov r0, r5 */
/* @0x10b07c bl 0x10afe4 <_Z21YYGML_instance_numberP9CInstanceS0_i> */
/* @0x10b080 vmov s15, r0 */
/* @0x10b084 vcvt.f64.s32 d7, s15 */
/* @0x10b088 vmov r0, r1, d7 */
/* @0x10b08c vmov r2, s14 */
/* @0x10b090 mov r3, r1 */
/* @0x10b094 stm r4, {r2, r3} */
/* @0x10b098 pop {r4, r5, r6, pc} */

/* ── FUNC 0x10b09c · YYGML_instance_create(float, float, int) · size=40 · insn=10 */
/* @0x10b09c push {r3, lr} */
/* @0x10b0a0 mov r3, r0 */
/* @0x10b0a4 mov r0, r2 */
/* @0x10b0a8 mov r2, r1 */
/* @0x10b0ac mov r1, r3 */
/* @0x10b0b0 bl 0x1c983c <_Z14Command_Createiff> */
/* @0x10b0b4 cmp r0, #0 */
/* @0x10b0b8 ldrne r0, [r0, #0x78] */
/* @0x10b0bc mvneq r0, #0 */
/* @0x10b0c0 pop {r3, pc} */

/* ── FUNC 0x10b0c4 · DoDestroy(CInstance*, bool) · size=104 · insn=26 */
/* @0x10b0c4 push {r4, lr} */
/* @0x10b0c8 subs r4, r0, #0 */
/* @0x10b0cc popeq {r4, pc} */
/* @0x10b0d0 ldrb r2, [r4, #0x68] */
/* @0x10b0d4 cmp r2, #0 */
/* @0x10b0d8 popne {r4, pc} */
/* @0x10b0dc ldrb r3, [r4, #0x69] */
/* @0x10b0e0 cmp r3, #0 */
/* @0x10b0e4 popne {r4, pc} */
/* @0x10b0e8 cmp r1, #0 */
/* @0x10b0ec bne 0x10b120 <_Z9DoDestroyP9CInstanceb+0x5c> */
/* @0x10b0f0 mov r3, r1 */
/* @0x10b0f4 mov r2, #12 */
/* @0x10b0f8 mov r1, r4 */
/* @0x10b0fc bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x10b100 ldr r3, [pc, #0x20] */
/* @0x10b104 mov r2, #1 */
/* @0x10b108 strb r2, [r4, #0x68] */
/* @0x10b10c ldr r3, [pc, r3] */
/* @0x10b110 ldr r2, [r3] */
/* @0x10b114 add r2, r2, #1 */
/* @0x10b118 str r2, [r3] */
/* @0x10b11c pop {r4, pc} */
/* @0x10b120 pop {r4, lr} */
/* @0x10b124 b 0x1c9b54 <_Z15Command_DestroyP9CInstance> */
/* @0x10b128 eoreq r2, lr, r8, lsr #31 */

/* ── FUNC 0x10b12c · DoInstanceDestroy(CInstance*, CInstance*, int, bool) · size=100 · insn=25 */
/* @0x10b12c push {r4, r5, lr} */
/* @0x10b130 sub sp, sp, #52 */
/* @0x10b134 add r4, sp, #12 */
/* @0x10b138 mov r12, r1 */
/* @0x10b13c mov r5, r3 */
/* @0x10b140 mov r1, r2 */
/* @0x10b144 mov r3, r12 */
/* @0x10b148 mov r2, r0 */
/* @0x10b14c mov r12, #0 */
/* @0x10b150 mov r0, r4 */
/* @0x10b154 str r12, [sp] */
/* @0x10b158 bl 0x19d060 <_ZN15WithObjIteratorC2EiP9CInstanceS1_b> */
/* @0x10b15c b 0x10b174 <_Z17DoInstanceDestroyP9CInstanceS0_ib+0x48> */
/* @0x10b160 bl 0x19de4c <_ZN15WithObjIteratordeEv> */
/* @0x10b164 mov r1, r5 */
/* @0x10b168 bl 0x10b0c4 <_Z9DoDestroyP9CInstanceb> */
/* @0x10b16c mov r0, r4 */
/* @0x10b170 bl 0x19d1c8 <_ZN15WithObjIterator4NextEv> */
/* @0x10b174 mov r0, r4 */
/* @0x10b178 bl 0x19de4c <_ZN15WithObjIteratordeEv> */
/* @0x10b17c cmp r0, #0 */
/* @0x10b180 mov r0, r4 */
/* @0x10b184 bne 0x10b160 <_Z17DoInstanceDestroyP9CInstanceS0_ib+0x34> */
/* @0x10b188 add sp, sp, #52 */
/* @0x10b18c pop {r4, r5, pc} */

/* ── FUNC 0x10b190 · F_InstanceDestroy(RValue&, CInstance*, CInstance*, int, RValue*) · size=96 · insn=24 */
/* @0x10b190 cmp r3, #1 */
/* @0x10b194 push {r4, r5, r6, r7, r8, lr} */
/* @0x10b198 mov r5, r1 */
/* @0x10b19c mov r6, r2 */
/* @0x10b1a0 ldr r4, [sp, #0x18] */
/* @0x10b1a4 ble 0x10b1dc <_Z17F_InstanceDestroyR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x10b1a8 mov r0, r4 */
/* @0x10b1ac mov r1, #1 */
/* @0x10b1b0 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x10b1b4 mov r7, r0 */
/* @0x10b1b8 mov r0, r4 */
/* @0x10b1bc mov r1, #0 */
/* @0x10b1c0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x10b1c4 mov r2, r0 */
/* @0x10b1c8 mov r0, r5 */
/* @0x10b1cc mov r1, r6 */
/* @0x10b1d0 mov r3, r7 */
/* @0x10b1d4 pop {r4, r5, r6, r7, r8, lr} */
/* @0x10b1d8 b 0x10b12c <_Z17DoInstanceDestroyP9CInstanceS0_ib> */
/* @0x10b1dc movne r7, #1 */
/* @0x10b1e0 mvnne r2, #0 */
/* @0x10b1e4 bne 0x10b1c8 <_Z17F_InstanceDestroyR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x10b1e8 mov r7, r3 */
/* @0x10b1ec b 0x10b1b8 <_Z17F_InstanceDestroyR6RValueP9CInstanceS2_iPS_+0x28> */

/* ── FUNC 0x10b1f0 · YYGML_instance_destroy(CInstance*, CInstance*, int, YYRValue**) · size=88 · insn=22 */
/* @0x10b1f0 cmp r2, #1 */
/* @0x10b1f4 push {r4, r5, r6, r7, r8, lr} */
/* @0x10b1f8 mov r5, r0 */
/* @0x10b1fc mov r6, r1 */
/* @0x10b200 mov r4, r3 */
/* @0x10b204 ble 0x10b234 <_Z22YYGML_instance_destroyP9CInstanceS0_iPP8YYRValue+0x44> */
/* @0x10b208 ldr r0, [r3, #0x4] */
/* @0x10b20c bl 0xd1294 <_Z11BOOL_RValuePK6RValue> */
/* @0x10b210 mov r7, r0 */
/* @0x10b214 ldr r0, [r4] */
/* @0x10b218 bl 0xd11b0 <_Z12INT32_RValuePK6RValue> */
/* @0x10b21c mov r2, r0 */
/* @0x10b220 mov r0, r5 */
/* @0x10b224 mov r1, r6 */
/* @0x10b228 mov r3, r7 */
/* @0x10b22c pop {r4, r5, r6, r7, r8, lr} */
/* @0x10b230 b 0x10b12c <_Z17DoInstanceDestroyP9CInstanceS0_ib> */
/* @0x10b234 movne r7, #1 */
/* @0x10b238 mvnne r2, #0 */
/* @0x10b23c bne 0x10b220 <_Z22YYGML_instance_destroyP9CInstanceS0_iPP8YYRValue+0x30> */
/* @0x10b240 mov r7, r2 */
/* @0x10b244 b 0x10b214 <_Z22YYGML_instance_destroyP9CInstanceS0_iPP8YYRValue+0x24> */

/* ── FUNC 0x10b248 · YYGML_instance_change(CInstance*, int, bool) · size=4 · insn=1 */
/* @0x10b248 b 0x1c9bb4 <_Z14Command_ChangeP9CInstanceib> */

/* ── FUNC 0x10b24c · GetActiveList(void (*)(CInstance*)) · size=564 · insn=141 */
/* @0x10b24c push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x10b250 mov r6, r0 */
/* @0x10b254 ldr r7, [pc, #0x210] */
/* @0x10b258 sub sp, sp, #8 */
/* @0x10b25c ldr r7, [pc, r7] */
/* @0x10b260 ldr r4, [r7] */
/* @0x10b264 cmp r4, #0 */
/* @0x10b268 beq 0x10b3d0 <_Z13GetActiveListPFvP9CInstanceE+0x184> */
/* @0x10b26c ldr r8, [pc, #0x1fc] */
/* @0x10b270 mov r3, #0 */
/* @0x10b274 str r3, [r4, #0x8] */
/* @0x10b278 ldr r8, [pc, r8] */
/* @0x10b27c ldr r3, [r8] */
/* @0x10b280 ldr r4, [r3, #0x80] */
/* @0x10b284 cmp r4, #0 */
/* @0x10b288 beq 0x10b2c8 <_Z13GetActiveListPFvP9CInstanceE+0x7c> */
/* @0x10b28c cmp r6, #0 */
/* @0x10b290 beq 0x10b318 <_Z13GetActiveListPFvP9CInstanceE+0xcc> */
/* @0x10b294 ldrb r3, [r4, #0x68] */
/* @0x10b298 ldr r5, [r4, #0x178] */
/* @0x10b29c cmp r3, #0 */
/* @0x10b2a0 bne 0x10b2b8 <_Z13GetActiveListPFvP9CInstanceE+0x6c> */
/* @0x10b2a4 ldrb r3, [r4, #0x69] */
/* @0x10b2a8 mov r0, r4 */
/* @0x10b2ac cmp r3, #0 */
/* @0x10b2b0 bne 0x10b2b8 <_Z13GetActiveListPFvP9CInstanceE+0x6c> */
/* @0x10b2b4 blx r6 */
/* @0x10b2b8 cmp r5, #0 */
/* @0x10b2bc mov r4, r5 */
/* @0x10b2c0 bne 0x10b294 <_Z13GetActiveListPFvP9CInstanceE+0x48> */
/* @0x10b2c4 ldr r3, [r8] */
/* @0x10b2c8 ldr r4, [r3, #0x8c] */
/* @0x10b2cc cmp r4, #0 */
/* @0x10b2d0 beq 0x10b30c <_Z13GetActiveListPFvP9CInstanceE+0xc0> */
/* @0x10b2d4 cmp r6, #0 */
/* @0x10b2d8 beq 0x10b370 <_Z13GetActiveListPFvP9CInstanceE+0x124> */
/* @0x10b2dc ldrb r3, [r4, #0x68] */
/* @0x10b2e0 ldr r5, [r4, #0x178] */
/* @0x10b2e4 cmp r3, #0 */
/* @0x10b2e8 bne 0x10b300 <_Z13GetActiveListPFvP9CInstanceE+0xb4> */
/* @0x10b2ec ldrb r3, [r4, #0x69] */
/* @0x10b2f0 mov r0, r4 */
/* @0x10b2f4 cmp r3, #0 */
/* @0x10b2f8 bne 0x10b300 <_Z13GetActiveListPFvP9CInstanceE+0xb4> */
/* @0x10b2fc blx r6 */
/* @0x10b300 cmp r5, #0 */
/* @0x10b304 mov r4, r5 */
/* @0x10b308 bne 0x10b2dc <_Z13GetActiveListPFvP9CInstanceE+0x90> */
/* @0x10b30c ldr r0, [r7] */
/* @0x10b310 add sp, sp, #8 */
/* @0x10b314 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x10b318 ldr r10, [pc, #0x154] */
/* @0x10b31c add r10, pc, r10 */
/* @0x10b320 ldrb r3, [r4, #0x68] */
/* @0x10b324 ldr r5, [r4, #0x178] */
/* @0x10b328 cmp r3, #0 */
/* @0x10b32c bne 0x10b360 <_Z13GetActiveListPFvP9CInstanceE+0x114> */
/* @0x10b330 ldrb r12, [r4, #0x69] */
/* @0x10b334 cmp r12, #0 */
/* @0x10b338 bne 0x10b360 <_Z13GetActiveListPFvP9CInstanceE+0x114> */
/* @0x10b33c ldr r9, [r7] */
/* @0x10b340 ldr r3, [r9, #0x4] */
/* @0x10b344 ldr r1, [r9, #0x8] */
/* @0x10b348 cmp r1, r3 */
/* @0x10b34c ldrne r3, [r9] */
/* @0x10b350 beq 0x10b40c <_Z13GetActiveListPFvP9CInstanceE+0x1c0> */
/* @0x10b354 str r4, [r3, r1, lsl #2] */
/* @0x10b358 add r1, r1, #1 */
/* @0x10b35c str r1, [r9, #0x8] */
/* @0x10b360 cmp r5, #0 */
/* @0x10b364 mov r4, r5 */
/* @0x10b368 bne 0x10b320 <_Z13GetActiveListPFvP9CInstanceE+0xd4> */
/* @0x10b36c b 0x10b2c4 <_Z13GetActiveListPFvP9CInstanceE+0x78> */
/* @0x10b370 ldr r8, [pc, #0x100] */
/* @0x10b374 add r8, pc, r8 */
/* @0x10b378 ldrb r3, [r4, #0x68] */
/* @0x10b37c ldr r5, [r4, #0x178] */
/* @0x10b380 cmp r3, #0 */
/* @0x10b384 bne 0x10b3b8 <_Z13GetActiveListPFvP9CInstanceE+0x16c> */
/* @0x10b388 ldrb r12, [r4, #0x69] */
/* @0x10b38c cmp r12, #0 */
/* @0x10b390 bne 0x10b3b8 <_Z13GetActiveListPFvP9CInstanceE+0x16c> */
/* @0x10b394 ldr r6, [r7] */
/* @0x10b398 ldr r3, [r6, #0x4] */
/* @0x10b39c ldr r1, [r6, #0x8] */
/* @0x10b3a0 cmp r1, r3 */
/* @0x10b3a4 ldrne r3, [r6] */
/* @0x10b3a8 beq 0x10b43c <_Z13GetActiveListPFvP9CInstanceE+0x1f0> */
/* @0x10b3ac str r4, [r3, r1, lsl #2] */
/* @0x10b3b0 add r1, r1, #1 */
/* @0x10b3b4 str r1, [r6, #0x8] */
/* @0x10b3b8 cmp r5, #0 */
/* @0x10b3bc mov r4, r5 */
/* @0x10b3c0 bne 0x10b378 <_Z13GetActiveListPFvP9CInstanceE+0x12c> */
/* @0x10b3c4 ldr r0, [r7] */
/* @0x10b3c8 add sp, sp, #8 */
/* @0x10b3cc pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x10b3d0 mov r0, #12 */
/* @0x10b3d4 bl 0x27c524 <_Znwj> */
/* @0x10b3d8 ldr r1, [pc, #0x9c] */
/* @0x10b3dc mov r3, #1 */
/* @0x10b3e0 mov r2, #50 */
/* @0x10b3e4 add r1, pc, r1 */
/* @0x10b3e8 mov r5, r0 */
/* @0x10b3ec mov r0, #128 */
/* @0x10b3f0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x10b3f4 str r4, [r5, #0x8] */
/* @0x10b3f8 mov r3, #32 */
/* @0x10b3fc mov r4, r5 */
/* @0x10b400 stm r5, {r0, r3} */
/* @0x10b404 str r5, [r7] */
/* @0x10b408 b 0x10b26c <_Z13GetActiveListPFvP9CInstanceE+0x20> */
/* @0x10b40c lsl r3, r1, #1 */
/* @0x10b410 ldr r0, [r9] */
/* @0x10b414 str r3, [r9, #0x4] */
/* @0x10b418 lsl r1, r1, #3 */
/* @0x10b41c mov r3, #74 */
/* @0x10b420 mov r2, r10 */
/* @0x10b424 str r12, [sp] */
/* @0x10b428 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x10b42c ldr r1, [r9, #0x8] */
/* @0x10b430 mov r3, r0 */
/* @0x10b434 str r0, [r9] */
/* @0x10b438 b 0x10b354 <_Z13GetActiveListPFvP9CInstanceE+0x108> */
/* @0x10b43c lsl r3, r1, #1 */
/* @0x10b440 ldr r0, [r6] */
/* @0x10b444 str r3, [r6, #0x4] */
/* @0x10b448 lsl r1, r1, #3 */
/* @0x10b44c mov r3, #74 */
/* @0x10b450 mov r2, r8 */
/* @0x10b454 str r12, [sp] */
/* @0x10b458 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x10b45c ldr r1, [r6, #0x8] */
/* @0x10b460 mov r3, r0 */
/* @0x10b464 str r0, [r6] */
/* @0x10b468 b 0x10b3ac <_Z13GetActiveListPFvP9CInstanceE+0x160> */
/* @0x10b46c eoreq r2, lr, r12, asr lr */
/* @0x10b470 .word 0x002e26b0 */
/* @0x10b474 eoreq r5, r2, r4, lsl sp */
/* @0x10b478 .word 0x00225cbc */
/* @0x10b47c eoreq sp, r2, r4, lsl r3 */

/* ── FUNC 0x10b480 · F_InstanceDeactivateAll(RValue&, CInstance*, CInstance*, int, RValue*) · size=372 · insn=93 */
/* @0x10b480 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x10b484 sub sp, sp, #8 */
/* @0x10b488 mov r0, #0 */
/* @0x10b48c mov r7, r1 */
/* @0x10b490 ldr r8, [sp, #0x28] */
/* @0x10b494 bl 0x10b24c <_Z13GetActiveListPFvP9CInstanceE> */
/* @0x10b498 ldr r9, [pc, #0x144] */
/* @0x10b49c mov r4, #0 */
/* @0x10b4a0 add r9, pc, r9 */
/* @0x10b4a4 ldr r2, [r0, #0x8] */
/* @0x10b4a8 mov r10, r0 */
/* @0x10b4ac cmp r2, #0 */
/* @0x10b4b0 ble 0x10b514 <_Z23F_InstanceDeactivateAllR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x10b4b4 ldr r3, [r10] */
/* @0x10b4b8 ldr r5, [r3, r4, lsl #2] */
/* @0x10b4bc ldrb r3, [r5, #0x68] */
/* @0x10b4c0 cmp r3, #0 */
/* @0x10b4c4 bne 0x10b508 <_Z23F_InstanceDeactivateAllR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x10b4c8 ldrb r12, [r5, #0x69] */
/* @0x10b4cc cmp r12, #0 */
/* @0x10b4d0 bne 0x10b508 <_Z23F_InstanceDeactivateAllR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x10b4d4 ldr r6, [pc, #0x10c] */
/* @0x10b4d8 ldr r6, [pc, r6] */
/* @0x10b4dc ldmib r6, {r2, r3} */
/* @0x10b4e0 cmp r3, r2 */
/* @0x10b4e4 beq 0x10b544 <_Z23F_InstanceDeactivateAllR6RValueP9CInstanceS2_iPS_+0xc4> */
/* @0x10b4e8 ldr r12, [r6] */
/* @0x10b4ec mov r1, #1 */
/* @0x10b4f0 str r5, [r12, r3, lsl #2] */
/* @0x10b4f4 mov r0, r5 */
/* @0x10b4f8 add r2, r3, r1 */
/* @0x10b4fc str r2, [r6, #0x8] */
/* @0x10b500 bl 0x19230c <_ZN9CInstance14SetDeactivatedEb> */
/* @0x10b504 ldr r2, [r10, #0x8] */
/* @0x10b508 add r4, r4, #1 */
/* @0x10b50c cmp r2, r4 */
/* @0x10b510 bgt 0x10b4b4 <_Z23F_InstanceDeactivateAllR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x10b514 cmp r7, #0 */
/* @0x10b518 beq 0x10b53c <_Z23F_InstanceDeactivateAllR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x10b51c mov r0, r8 */
/* @0x10b520 mov r1, #0 */
/* @0x10b524 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x10b528 cmp r0, #0 */
/* @0x10b52c beq 0x10b53c <_Z23F_InstanceDeactivateAllR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x10b530 ldrb r12, [r7, #0x68] */
/* @0x10b534 cmp r12, #0 */
/* @0x10b538 beq 0x10b574 <_Z23F_InstanceDeactivateAllR6RValueP9CInstanceS2_iPS_+0xf4> */
/* @0x10b53c add sp, sp, #8 */
/* @0x10b540 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x10b544 lsl r2, r3, #1 */
/* @0x10b548 ldr r0, [r6] */
/* @0x10b54c str r2, [r6, #0x4] */
/* @0x10b550 lsl r1, r3, #3 */
/* @0x10b554 str r12, [sp] */
/* @0x10b558 mov r3, #74 */
/* @0x10b55c mov r2, r9 */
/* @0x10b560 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x10b564 ldr r3, [r6, #0x8] */
/* @0x10b568 mov r12, r0 */
/* @0x10b56c str r0, [r6] */
/* @0x10b570 b 0x10b4ec <_Z23F_InstanceDeactivateAllR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x10b574 ldr r6, [pc, #0x70] */
/* @0x10b578 ldr r6, [pc, r6] */
/* @0x10b57c ldr r1, [r6, #0x8] */
/* @0x10b580 ldr r3, [r6, #0x4] */
/* @0x10b584 cmp r1, r3 */
/* @0x10b588 beq 0x10b5b0 <_Z23F_InstanceDeactivateAllR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x10b58c ldr r3, [r6] */
/* @0x10b590 str r7, [r3, r1, lsl #2] */
/* @0x10b594 mov r0, r7 */
/* @0x10b598 add r3, r1, #1 */
/* @0x10b59c mov r1, #0 */
/* @0x10b5a0 str r3, [r6, #0x8] */
/* @0x10b5a4 add sp, sp, #8 */
/* @0x10b5a8 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x10b5ac b 0x19230c <_ZN9CInstance14SetDeactivatedEb> */
/* @0x10b5b0 ldr r2, [pc, #0x38] */
/* @0x10b5b4 lsl r3, r1, #1 */
/* @0x10b5b8 ldr r0, [r6] */
/* @0x10b5bc lsl r1, r1, #3 */
/* @0x10b5c0 str r3, [r6, #0x4] */
/* @0x10b5c4 add r2, pc, r2 */
/* @0x10b5c8 mov r3, #74 */
/* @0x10b5cc str r12, [sp] */
/* @0x10b5d0 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x10b5d4 ldr r1, [r6, #0x8] */
/* @0x10b5d8 mov r3, r0 */
/* @0x10b5dc str r0, [r6] */
/* @0x10b5e0 b 0x10b590 <_Z23F_InstanceDeactivateAllR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x10b5e4 mlaeq r2, r0, r11, r5 */
/* @0x10b5e8 eoreq r2, lr, r0, ror r7 */
/* @0x10b5ec .word 0x002e26d0 */
/* @0x10b5f0 eoreq r5, r2, r12, ror #20 */

/* ── FUNC 0x10b5f4 · F_InstanceDeactivateRegion(RValue&, CInstance*, CInstance*, int, RValue*) · size=348 · insn=87 */
/* @0x10b5f4 push {r4, r5, r6, lr} */
/* @0x10b5f8 vpush {d8} */
/* @0x10b5fc sub sp, sp, #8 */
/* @0x10b600 mov r6, r1 */
/* @0x10b604 mov r1, #4 */
/* @0x10b608 ldr r5, [sp, #0x20] */
/* @0x10b60c ldr r4, [pc, #0x12c] */
/* @0x10b610 mov r0, r5 */
/* @0x10b614 add r4, pc, r4 */
/* @0x10b618 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x10b61c mov r1, #0 */
/* @0x10b620 strb r0, [r4, #0xc] */
/* @0x10b624 mov r0, r5 */
/* @0x10b628 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10b62c mov r1, #1 */
/* @0x10b630 str r0, [r4, #0x10] */
/* @0x10b634 mov r0, r5 */
/* @0x10b638 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10b63c mov r1, #2 */
/* @0x10b640 vldr s17, [r4, #16] */
/* @0x10b644 str r0, [r4, #0x14] */
/* @0x10b648 mov r0, r5 */
/* @0x10b64c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10b650 mov r1, #3 */
/* @0x10b654 vldr s16, [r4, #20] */
/* @0x10b658 vmov s15, r0 */
/* @0x10b65c mov r0, r5 */
/* @0x10b660 vadd.f32 s17, s17, s15 */
/* @0x10b664 vstr s17, [r4, #24] */
/* @0x10b668 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10b66c mov r1, #5 */
/* @0x10b670 vmov s15, r0 */
/* @0x10b674 mov r0, r5 */
/* @0x10b678 vadd.f32 s16, s16, s15 */
/* @0x10b67c vstr s16, [r4, #28] */
/* @0x10b680 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x10b684 mov r4, r0 */
/* @0x10b688 ldr r0, [pc, #0xb4] */
/* @0x10b68c cmp r6, #0 */
/* @0x10b690 moveq r4, #0 */
/* @0x10b694 andne r4, r4, #1 */
/* @0x10b698 ldr r0, [pc, r0] */
/* @0x10b69c bl 0x10b24c <_Z13GetActiveListPFvP9CInstanceE> */
/* @0x10b6a0 cmp r4, #0 */
/* @0x10b6a4 beq 0x10b700 <_Z26F_InstanceDeactivateRegionR6RValueP9CInstanceS2_iPS_+0x10c> */
/* @0x10b6a8 ldrb r12, [r6, #0x68] */
/* @0x10b6ac cmp r12, #0 */
/* @0x10b6b0 bne 0x10b700 <_Z26F_InstanceDeactivateRegionR6RValueP9CInstanceS2_iPS_+0x10c> */
/* @0x10b6b4 ldrb r3, [r6, #0x69] */
/* @0x10b6b8 cmp r3, #0 */
/* @0x10b6bc beq 0x10b700 <_Z26F_InstanceDeactivateRegionR6RValueP9CInstanceS2_iPS_+0x10c> */
/* @0x10b6c0 ldr r4, [pc, #0x80] */
/* @0x10b6c4 ldr r4, [pc, r4] */
/* @0x10b6c8 ldr r1, [r4, #0x8] */
/* @0x10b6cc ldr r3, [r4, #0x4] */
/* @0x10b6d0 cmp r1, r3 */
/* @0x10b6d4 beq 0x10b70c <_Z26F_InstanceDeactivateRegionR6RValueP9CInstanceS2_iPS_+0x118> */
/* @0x10b6d8 ldr r3, [r4] */
/* @0x10b6dc str r6, [r3, r1, lsl #2] */
/* @0x10b6e0 mov r0, r6 */
/* @0x10b6e4 add r3, r1, #1 */
/* @0x10b6e8 mov r1, #0 */
/* @0x10b6ec str r3, [r4, #0x8] */
/* @0x10b6f0 add sp, sp, #8 */
/* @0x10b6f4 vpop {d8} */
/* @0x10b6f8 pop {r4, r5, r6, lr} */
/* @0x10b6fc b 0x19230c <_ZN9CInstance14SetDeactivatedEb> */
/* @0x10b700 add sp, sp, #8 */
/* @0x10b704 vpop {d8} */
/* @0x10b708 pop {r4, r5, r6, pc} */
/* @0x10b70c ldr r2, [pc, #0x38] */
/* @0x10b710 lsl r3, r1, #1 */
/* @0x10b714 ldr r0, [r4] */
/* @0x10b718 lsl r1, r1, #3 */
/* @0x10b71c str r3, [r4, #0x4] */
/* @0x10b720 add r2, pc, r2 */
/* @0x10b724 mov r3, #74 */
/* @0x10b728 str r12, [sp] */
/* @0x10b72c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x10b730 ldr r1, [r4, #0x8] */
/* @0x10b734 mov r3, r0 */
/* @0x10b738 str r0, [r4] */
/* @0x10b73c b 0x10b6dc <_Z26F_InstanceDeactivateRegionR6RValueP9CInstanceS2_iPS_+0xe8> */
/* @0x10b740 eorseq r8, r7, r4, asr #1 */
/* @0x10b744 eoreq r2, lr, r4, lsr #20 */
/* @0x10b748 eoreq r2, lr, r4, lsl #11 */
/* @0x10b74c eoreq r5, r2, r0, lsl r9 */

/* ── FUNC 0x10b750 · F_InstanceDeactivateRegionSpecial(RValue&, CInstance*, CInstance*, int, RValue*) · size=936 · insn=234 */
/* @0x10b750 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x10b754 vpush {d8} */
/* @0x10b758 sub sp, sp, #12 */
/* @0x10b75c mov r7, r1 */
/* @0x10b760 mov r1, #4 */
/* @0x10b764 ldr r4, [sp, #0x30] */
/* @0x10b768 ldr r5, [pc, #0x36c] */
/* @0x10b76c ldr r6, [pc, #0x36c] */
/* @0x10b770 mov r0, r4 */
/* @0x10b774 add r5, pc, r5 */
/* @0x10b778 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x10b77c mov r1, #0 */
/* @0x10b780 add r6, pc, r6 */
/* @0x10b784 strb r0, [r5, #0xc] */
/* @0x10b788 mov r0, r4 */
/* @0x10b78c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10b790 mov r1, #1 */
/* @0x10b794 str r0, [r5, #0x10] */
/* @0x10b798 mov r0, r4 */
/* @0x10b79c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10b7a0 mov r1, #2 */
/* @0x10b7a4 vldr s17, [r5, #16] */
/* @0x10b7a8 str r0, [r5, #0x14] */
/* @0x10b7ac mov r0, r4 */
/* @0x10b7b0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10b7b4 mov r1, #3 */
/* @0x10b7b8 vldr s16, [r5, #20] */
/* @0x10b7bc vmov s15, r0 */
/* @0x10b7c0 mov r0, r4 */
/* @0x10b7c4 vadd.f32 s17, s17, s15 */
/* @0x10b7c8 vstr s17, [r5, #24] */
/* @0x10b7cc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10b7d0 vmov s15, r0 */
/* @0x10b7d4 mov r0, #16 */
/* @0x10b7d8 vadd.f32 s16, s16, s15 */
/* @0x10b7dc vstr s16, [r5, #28] */
/* @0x10b7e0 bl 0x27c524 <_Znwj> */
/* @0x10b7e4 mvn r3, #-16777216 */
/* @0x10b7e8 str r3, [r0, #0xc] */
/* @0x10b7ec mov r5, r0 */
/* @0x10b7f0 ldr r3, [r4, #0x6c] */
/* @0x10b7f4 bic r2, r3, #-16777216 */
/* @0x10b7f8 cmp r2, #2 */
/* @0x10b7fc beq 0x10b93c <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x1ec> */
/* @0x10b800 ldr r3, [pc, #0x2dc] */
/* @0x10b804 mov r0, #16 */
/* @0x10b808 ldr r8, [r6, r3] */
/* @0x10b80c str r5, [r8] */
/* @0x10b810 bl 0x27c524 <_Znwj> */
/* @0x10b814 mvn r3, #-16777216 */
/* @0x10b818 str r3, [r0, #0xc] */
/* @0x10b81c mov r5, r0 */
/* @0x10b820 ldr r3, [r4, #0x7c] */
/* @0x10b824 bic r2, r3, #-16777216 */
/* @0x10b828 cmp r2, #2 */
/* @0x10b82c beq 0x10b8d8 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x188> */
/* @0x10b830 ldr r2, [pc, #0x2b0] */
/* @0x10b834 ldr r3, [pc, #0x2b0] */
/* @0x10b838 ldr r9, [r6, r2] */
/* @0x10b83c str r5, [r9] */
/* @0x10b840 ldr r0, [r6, r3] */
/* @0x10b844 bl 0x10b24c <_Z13GetActiveListPFvP9CInstanceE> */
/* @0x10b848 ldr r0, [r8] */
/* @0x10b84c bl 0x27d1d0 <_ZdlPv> */
/* @0x10b850 ldr r0, [r9] */
/* @0x10b854 bl 0x27d1d0 <_ZdlPv> */
/* @0x10b858 mov r0, r4 */
/* @0x10b85c mov r1, #5 */
/* @0x10b860 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x10b864 cmp r7, #0 */
/* @0x10b868 moveq r0, #0 */
/* @0x10b86c andne r0, r0, #1 */
/* @0x10b870 cmp r0, #0 */
/* @0x10b874 beq 0x10b8cc <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x17c> */
/* @0x10b878 ldrb r3, [r7, #0x68] */
/* @0x10b87c cmp r3, #0 */
/* @0x10b880 bne 0x10b8cc <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x17c> */
/* @0x10b884 ldrb r2, [r7, #0x69] */
/* @0x10b888 cmp r2, #0 */
/* @0x10b88c beq 0x10b8cc <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x17c> */
/* @0x10b890 ldr r2, [pc, #0x258] */
/* @0x10b894 ldr r4, [r6, r2] */
/* @0x10b898 ldmib r4, {r2, r12} */
/* @0x10b89c cmp r12, r2 */
/* @0x10b8a0 beq 0x10baa8 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x358> */
/* @0x10b8a4 ldr r3, [r4] */
/* @0x10b8a8 str r7, [r3, r12, lsl #2] */
/* @0x10b8ac mov r0, r7 */
/* @0x10b8b0 add r12, r12, #1 */
/* @0x10b8b4 mov r1, #0 */
/* @0x10b8b8 str r12, [r4, #0x8] */
/* @0x10b8bc add sp, sp, #12 */
/* @0x10b8c0 vpop {d8} */
/* @0x10b8c4 pop {r4, r5, r6, r7, r8, r9, lr} */
/* @0x10b8c8 b 0x19230c <_ZN9CInstance14SetDeactivatedEb> */
/* @0x10b8cc add sp, sp, #12 */
/* @0x10b8d0 vpop {d8} */
/* @0x10b8d4 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x10b8d8 ldr r2, [r4, #0x78] */
/* @0x10b8dc mov r1, #0 */
/* @0x10b8e0 str r3, [r0, #0xc] */
/* @0x10b8e4 ldr r3, [r4, #0x7c] */
/* @0x10b8e8 str r1, [r0] */
/* @0x10b8ec bic r3, r3, #-16777216 */
/* @0x10b8f0 str r2, [r0, #0x8] */
/* @0x10b8f4 cmp r3, #14 */
/* @0x10b8f8 addls pc, pc, r3, lsl #2 */
/* @0x10b8fc b 0x10b830 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x10b900 b 0x10b9b8 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x268> */
/* @0x10b904 b 0x10ba90 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x340> */
/* @0x10b908 b 0x10ba64 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x314> */
/* @0x10b90c b 0x10b9ac <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x25c> */
/* @0x10b910 b 0x10b830 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x10b914 b 0x10b830 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x10b918 b 0x10b9d8 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x288> */
/* @0x10b91c b 0x10b9ac <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x25c> */
/* @0x10b920 b 0x10b830 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x10b924 b 0x10b830 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x10b928 b 0x10b9b8 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x268> */
/* @0x10b92c b 0x10b830 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x10b930 b 0x10b830 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x10b934 b 0x10b9b8 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x268> */
/* @0x10b938 b 0x10b9ac <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x25c> */
/* @0x10b93c ldr r2, [r4, #0x68] */
/* @0x10b940 mov r1, #0 */
/* @0x10b944 str r3, [r0, #0xc] */
/* @0x10b948 ldr r3, [r4, #0x6c] */
/* @0x10b94c str r1, [r0] */
/* @0x10b950 bic r3, r3, #-16777216 */
/* @0x10b954 str r2, [r0, #0x8] */
/* @0x10b958 cmp r3, #14 */
/* @0x10b95c addls pc, pc, r3, lsl #2 */
/* @0x10b960 b 0x10b800 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x10b964 b 0x10b9c8 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x278> */
/* @0x10b968 b 0x10b9fc <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x2ac> */
/* @0x10b96c b 0x10ba14 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x2c4> */
/* @0x10b970 b 0x10b9a0 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x250> */
/* @0x10b974 b 0x10b800 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x10b978 b 0x10b800 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x10b97c b 0x10ba40 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x2f0> */
/* @0x10b980 b 0x10b9a0 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x250> */
/* @0x10b984 b 0x10b800 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x10b988 b 0x10b800 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x10b98c b 0x10b9c8 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x278> */
/* @0x10b990 b 0x10b800 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x10b994 b 0x10b800 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x10b998 b 0x10b9c8 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x278> */
/* @0x10b99c b 0x10b9a0 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x250> */
/* @0x10b9a0 ldr r3, [r4, #0x60] */
/* @0x10b9a4 str r3, [r5] */
/* @0x10b9a8 b 0x10b800 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x10b9ac ldr r3, [r4, #0x70] */
/* @0x10b9b0 str r3, [r5] */
/* @0x10b9b4 b 0x10b830 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x10b9b8 ldr r2, [r4, #0x70] */
/* @0x10b9bc ldr r3, [r4, #0x74] */
/* @0x10b9c0 stm r0, {r2, r3} */
/* @0x10b9c4 b 0x10b830 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x10b9c8 ldr r2, [r4, #0x60] */
/* @0x10b9cc ldr r3, [r4, #0x64] */
/* @0x10b9d0 stm r0, {r2, r3} */
/* @0x10b9d4 b 0x10b800 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x10b9d8 ldr r3, [r4, #0x70] */
/* @0x10b9dc str r3, [r0] */
/* @0x10b9e0 ldr r3, [r4, #0x70] */
/* @0x10b9e4 cmp r3, #0 */
/* @0x10b9e8 beq 0x10b830 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x10b9ec bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x10b9f0 ldr r1, [r4, #0x70] */
/* @0x10b9f4 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x10b9f8 b 0x10b830 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x10b9fc ldr r3, [r4, #0x60] */
/* @0x10ba00 cmp r3, #0 */
/* @0x10ba04 ldrne r2, [r3, #0x4] */
/* @0x10ba08 addne r2, r2, #1 */
/* @0x10ba0c strne r2, [r3, #0x4] */
/* @0x10ba10 b 0x10b9a4 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x254> */
/* @0x10ba14 ldr r3, [r4, #0x60] */
/* @0x10ba18 cmp r3, #0 */
/* @0x10ba1c str r3, [r0] */
/* @0x10ba20 beq 0x10b800 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x10ba24 ldr r1, [r3, #0x8] */
/* @0x10ba28 ldr r2, [r3] */
/* @0x10ba2c cmp r1, #0 */
/* @0x10ba30 streq r0, [r3, #0x8] */
/* @0x10ba34 add r2, r2, #1 */
/* @0x10ba38 str r2, [r3] */
/* @0x10ba3c b 0x10b800 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x10ba40 ldr r3, [r4, #0x60] */
/* @0x10ba44 str r3, [r0] */
/* @0x10ba48 ldr r3, [r4, #0x60] */
/* @0x10ba4c cmp r3, #0 */
/* @0x10ba50 beq 0x10b800 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x10ba54 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x10ba58 ldr r1, [r4, #0x60] */
/* @0x10ba5c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x10ba60 b 0x10b800 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x10ba64 ldr r3, [r4, #0x70] */
/* @0x10ba68 cmp r3, #0 */
/* @0x10ba6c str r3, [r0] */
/* @0x10ba70 beq 0x10b830 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x10ba74 ldr r1, [r3, #0x8] */
/* @0x10ba78 ldr r2, [r3] */
/* @0x10ba7c cmp r1, #0 */
/* @0x10ba80 streq r0, [r3, #0x8] */
/* @0x10ba84 add r2, r2, #1 */
/* @0x10ba88 str r2, [r3] */
/* @0x10ba8c b 0x10b830 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x10ba90 ldr r3, [r4, #0x70] */
/* @0x10ba94 cmp r3, #0 */
/* @0x10ba98 ldrne r2, [r3, #0x4] */
/* @0x10ba9c addne r2, r2, #1 */
/* @0x10baa0 strne r2, [r3, #0x4] */
/* @0x10baa4 b 0x10b9b0 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x260> */
/* @0x10baa8 ldr r2, [pc, #0x44] */
/* @0x10baac lsl r1, r12, #3 */
/* @0x10bab0 ldr r0, [r4] */
/* @0x10bab4 lsl r12, r12, #1 */
/* @0x10bab8 str r3, [sp] */
/* @0x10babc add r2, pc, r2 */
/* @0x10bac0 mov r3, #74 */
/* @0x10bac4 str r12, [r4, #0x4] */
/* @0x10bac8 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x10bacc ldr r12, [r4, #0x8] */
/* @0x10bad0 mov r3, r0 */
/* @0x10bad4 str r0, [r4] */
/* @0x10bad8 b 0x10b8a8 <_Z33F_InstanceDeactivateRegionSpecialR6RValueP9CInstanceS2_iPS_+0x158> */
/* @0x10badc eorseq r7, r7, r4, ror #30 */
/* @0x10bae0 .word 0x002e64d0 */
/* @0x10bae4 .word 0xffffc460 */
/* @0x10bae8 .word 0xffffc45c */
/* @0x10baec .word 0xffffc470 */
/* @0x10baf0 .word 0xffffbff8 */
/* @0x10baf4 eoreq r5, r2, r4, ror r5 */

/* ── FUNC 0x10baf8 · GetDeactiveList(void (*)(CInstance*)) · size=748 · insn=187 */
/* @0x10baf8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x10bafc mov r8, r0 */
/* @0x10bb00 ldr r7, [pc, #0x2c0] */
/* @0x10bb04 sub sp, sp, #12 */
/* @0x10bb08 ldr r7, [pc, r7] */
/* @0x10bb0c ldr r4, [r7] */
/* @0x10bb10 cmp r4, #0 */
/* @0x10bb14 beq 0x10bd8c <_Z15GetDeactiveListPFvP9CInstanceE+0x294> */
/* @0x10bb18 ldr r9, [pc, #0x2ac] */
/* @0x10bb1c mov r3, #0 */
/* @0x10bb20 str r3, [r4, #0x8] */
/* @0x10bb24 ldr r9, [pc, r9] */
/* @0x10bb28 ldr r3, [r9] */
/* @0x10bb2c ldr r4, [r3, #0x80] */
/* @0x10bb30 cmp r4, #0 */
/* @0x10bb34 beq 0x10bba0 <_Z15GetDeactiveListPFvP9CInstanceE+0xa8> */
/* @0x10bb38 ldr r10, [pc, #0x290] */
/* @0x10bb3c cmp r8, #0 */
/* @0x10bb40 add r10, pc, r10 */
/* @0x10bb44 beq 0x10bc7c <_Z15GetDeactiveListPFvP9CInstanceE+0x184> */
/* @0x10bb48 ldrb r11, [r4, #0x68] */
/* @0x10bb4c ldr r5, [r4, #0x178] */
/* @0x10bb50 cmp r11, #0 */
/* @0x10bb54 bne 0x10bb90 <_Z15GetDeactiveListPFvP9CInstanceE+0x98> */
/* @0x10bb58 ldrb r3, [r4, #0x69] */
/* @0x10bb5c mov r0, r4 */
/* @0x10bb60 cmp r3, #0 */
/* @0x10bb64 beq 0x10bb90 <_Z15GetDeactiveListPFvP9CInstanceE+0x98> */
/* @0x10bb68 blx r8 */
/* @0x10bb6c ldr r6, [r7] */
/* @0x10bb70 ldr r1, [r6, #0x8] */
/* @0x10bb74 ldr r3, [r6, #0x4] */
/* @0x10bb78 cmp r1, r3 */
/* @0x10bb7c beq 0x10bc1c <_Z15GetDeactiveListPFvP9CInstanceE+0x124> */
/* @0x10bb80 ldr r2, [r6] */
/* @0x10bb84 add r3, r1, #1 */
/* @0x10bb88 str r4, [r2, r1, lsl #2] */
/* @0x10bb8c str r3, [r6, #0x8] */
/* @0x10bb90 cmp r5, #0 */
/* @0x10bb94 mov r4, r5 */
/* @0x10bb98 bne 0x10bb48 <_Z15GetDeactiveListPFvP9CInstanceE+0x50> */
/* @0x10bb9c ldr r3, [r9] */
/* @0x10bba0 ldr r4, [r3, #0x8c] */
/* @0x10bba4 cmp r4, #0 */
/* @0x10bba8 beq 0x10bc10 <_Z15GetDeactiveListPFvP9CInstanceE+0x118> */
/* @0x10bbac ldr r10, [pc, #0x220] */
/* @0x10bbb0 cmp r8, #0 */
/* @0x10bbb4 add r10, pc, r10 */
/* @0x10bbb8 beq 0x10bd04 <_Z15GetDeactiveListPFvP9CInstanceE+0x20c> */
/* @0x10bbbc ldrb r9, [r4, #0x68] */
/* @0x10bbc0 ldr r5, [r4, #0x178] */
/* @0x10bbc4 cmp r9, #0 */
/* @0x10bbc8 bne 0x10bc04 <_Z15GetDeactiveListPFvP9CInstanceE+0x10c> */
/* @0x10bbcc ldrb r3, [r4, #0x69] */
/* @0x10bbd0 mov r0, r4 */
/* @0x10bbd4 cmp r3, #0 */
/* @0x10bbd8 beq 0x10bc04 <_Z15GetDeactiveListPFvP9CInstanceE+0x10c> */
/* @0x10bbdc blx r8 */
/* @0x10bbe0 ldr r6, [r7] */
/* @0x10bbe4 ldr r1, [r6, #0x8] */
/* @0x10bbe8 ldr r3, [r6, #0x4] */
/* @0x10bbec cmp r1, r3 */
/* @0x10bbf0 beq 0x10bc4c <_Z15GetDeactiveListPFvP9CInstanceE+0x154> */
/* @0x10bbf4 ldr r2, [r6] */
/* @0x10bbf8 add r3, r1, #1 */
/* @0x10bbfc str r4, [r2, r1, lsl #2] */
/* @0x10bc00 str r3, [r6, #0x8] */
/* @0x10bc04 cmp r5, #0 */
/* @0x10bc08 mov r4, r5 */
/* @0x10bc0c bne 0x10bbbc <_Z15GetDeactiveListPFvP9CInstanceE+0xc4> */
/* @0x10bc10 ldr r0, [r7] */
/* @0x10bc14 add sp, sp, #12 */
/* @0x10bc18 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x10bc1c lsl r3, r1, #1 */
/* @0x10bc20 ldr r0, [r6] */
/* @0x10bc24 str r3, [r6, #0x4] */
/* @0x10bc28 lsl r1, r1, #3 */
/* @0x10bc2c mov r2, r10 */
/* @0x10bc30 str r11, [sp] */
/* @0x10bc34 mov r3, #74 */
/* @0x10bc38 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x10bc3c ldr r1, [r6, #0x8] */
/* @0x10bc40 mov r2, r0 */
/* @0x10bc44 str r0, [r6] */
/* @0x10bc48 b 0x10bb84 <_Z15GetDeactiveListPFvP9CInstanceE+0x8c> */
/* @0x10bc4c lsl r3, r1, #1 */
/* @0x10bc50 ldr r0, [r6] */
/* @0x10bc54 str r3, [r6, #0x4] */
/* @0x10bc58 lsl r1, r1, #3 */
/* @0x10bc5c mov r2, r10 */
/* @0x10bc60 str r9, [sp] */
/* @0x10bc64 mov r3, #74 */
/* @0x10bc68 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x10bc6c ldr r1, [r6, #0x8] */
/* @0x10bc70 mov r2, r0 */
/* @0x10bc74 str r0, [r6] */
/* @0x10bc78 b 0x10bbf8 <_Z15GetDeactiveListPFvP9CInstanceE+0x100> */
/* @0x10bc7c ldr r10, [pc, #0x154] */
/* @0x10bc80 add r10, pc, r10 */
/* @0x10bc84 b 0x10bca0 <_Z15GetDeactiveListPFvP9CInstanceE+0x1a8> */
/* @0x10bc88 str r4, [r3, r1, lsl #2] */
/* @0x10bc8c add r1, r1, #1 */
/* @0x10bc90 str r1, [r6, #0x8] */
/* @0x10bc94 cmp r5, #0 */
/* @0x10bc98 mov r4, r5 */
/* @0x10bc9c beq 0x10bb9c <_Z15GetDeactiveListPFvP9CInstanceE+0xa4> */
/* @0x10bca0 ldrb r12, [r4, #0x68] */
/* @0x10bca4 ldr r5, [r4, #0x178] */
/* @0x10bca8 cmp r12, #0 */
/* @0x10bcac bne 0x10bc94 <_Z15GetDeactiveListPFvP9CInstanceE+0x19c> */
/* @0x10bcb0 ldrb r3, [r4, #0x69] */
/* @0x10bcb4 cmp r3, #0 */
/* @0x10bcb8 beq 0x10bc94 <_Z15GetDeactiveListPFvP9CInstanceE+0x19c> */
/* @0x10bcbc ldr r6, [r7] */
/* @0x10bcc0 ldr r3, [r6, #0x4] */
/* @0x10bcc4 ldr r1, [r6, #0x8] */
/* @0x10bcc8 cmp r1, r3 */
/* @0x10bccc ldrne r3, [r6] */
/* @0x10bcd0 bne 0x10bc88 <_Z15GetDeactiveListPFvP9CInstanceE+0x190> */
/* @0x10bcd4 lsl r3, r1, #1 */
/* @0x10bcd8 ldr r0, [r6] */
/* @0x10bcdc str r3, [r6, #0x4] */
/* @0x10bce0 lsl r1, r1, #3 */
/* @0x10bce4 mov r3, #74 */
/* @0x10bce8 mov r2, r10 */
/* @0x10bcec str r12, [sp] */
/* @0x10bcf0 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x10bcf4 ldr r1, [r6, #0x8] */
/* @0x10bcf8 mov r3, r0 */
/* @0x10bcfc str r0, [r6] */
/* @0x10bd00 b 0x10bc88 <_Z15GetDeactiveListPFvP9CInstanceE+0x190> */
/* @0x10bd04 ldr r8, [pc, #0xd0] */
/* @0x10bd08 add r8, pc, r8 */
/* @0x10bd0c b 0x10bd28 <_Z15GetDeactiveListPFvP9CInstanceE+0x230> */
/* @0x10bd10 str r4, [r3, r1, lsl #2] */
/* @0x10bd14 add r1, r1, #1 */
/* @0x10bd18 str r1, [r6, #0x8] */
/* @0x10bd1c cmp r5, #0 */
/* @0x10bd20 mov r4, r5 */
/* @0x10bd24 beq 0x10bc10 <_Z15GetDeactiveListPFvP9CInstanceE+0x118> */
/* @0x10bd28 ldrb r12, [r4, #0x68] */
/* @0x10bd2c ldr r5, [r4, #0x178] */
/* @0x10bd30 cmp r12, #0 */
/* @0x10bd34 bne 0x10bd1c <_Z15GetDeactiveListPFvP9CInstanceE+0x224> */
/* @0x10bd38 ldrb r3, [r4, #0x69] */
/* @0x10bd3c cmp r3, #0 */
/* @0x10bd40 beq 0x10bd1c <_Z15GetDeactiveListPFvP9CInstanceE+0x224> */
/* @0x10bd44 ldr r6, [r7] */
/* @0x10bd48 ldr r3, [r6, #0x4] */
/* @0x10bd4c ldr r1, [r6, #0x8] */
/* @0x10bd50 cmp r1, r3 */
/* @0x10bd54 ldrne r3, [r6] */
/* @0x10bd58 bne 0x10bd10 <_Z15GetDeactiveListPFvP9CInstanceE+0x218> */
/* @0x10bd5c lsl r3, r1, #1 */
/* @0x10bd60 ldr r0, [r6] */
/* @0x10bd64 str r3, [r6, #0x4] */
/* @0x10bd68 lsl r1, r1, #3 */
/* @0x10bd6c mov r3, #74 */
/* @0x10bd70 mov r2, r8 */
/* @0x10bd74 str r12, [sp] */
/* @0x10bd78 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x10bd7c ldr r1, [r6, #0x8] */
/* @0x10bd80 mov r3, r0 */
/* @0x10bd84 str r0, [r6] */
/* @0x10bd88 b 0x10bd10 <_Z15GetDeactiveListPFvP9CInstanceE+0x218> */
/* @0x10bd8c mov r0, #12 */
/* @0x10bd90 bl 0x27c524 <_Znwj> */
/* @0x10bd94 ldr r1, [pc, #0x44] */
/* @0x10bd98 mov r3, #1 */
/* @0x10bd9c mov r2, #50 */
/* @0x10bda0 add r1, pc, r1 */
/* @0x10bda4 mov r5, r0 */
/* @0x10bda8 mov r0, #128 */
/* @0x10bdac bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x10bdb0 str r4, [r5, #0x8] */
/* @0x10bdb4 mov r3, #32 */
/* @0x10bdb8 mov r4, r5 */
/* @0x10bdbc stm r5, {r0, r3} */
/* @0x10bdc0 str r5, [r7] */
/* @0x10bdc4 b 0x10bb18 <_Z15GetDeactiveListPFvP9CInstanceE+0x20> */
/* @0x10bdc8 .word 0x002e25b0 */
/* @0x10bdcc eoreq r1, lr, r4, lsl #28 */
/* @0x10bdd0 .word 0x002254f0 */
/* @0x10bdd4 eoreq r5, r2, r12, ror r4 */
/* @0x10bdd8 .word 0x002253b0 */
/* @0x10bddc eoreq r5, r2, r8, lsr #6 */
/* @0x10bde0 eoreq r12, r2, r8, asr r9 */

/* ── FUNC 0x10bde4 · F_InstanceActivateAll(RValue&, CInstance*, CInstance*, int, RValue*) · size=204 · insn=51 */
/* @0x10bde4 push {r4, r5, r6, r7, r8, lr} */
/* @0x10bde8 mov r0, #0 */
/* @0x10bdec sub sp, sp, #8 */
/* @0x10bdf0 bl 0x10baf8 <_Z15GetDeactiveListPFvP9CInstanceE> */
/* @0x10bdf4 ldr r1, [r0, #0x8] */
/* @0x10bdf8 mov r7, r0 */
/* @0x10bdfc cmp r1, #0 */
/* @0x10be00 ble 0x10be70 <_Z21F_InstanceActivateAllR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x10be04 ldr r8, [pc, #0x9c] */
/* @0x10be08 mov r4, #0 */
/* @0x10be0c add r8, pc, r8 */
/* @0x10be10 ldr r3, [r7] */
/* @0x10be14 ldr r5, [r3, r4, lsl #2] */
/* @0x10be18 ldrb r3, [r5, #0x68] */
/* @0x10be1c cmp r3, #0 */
/* @0x10be20 bne 0x10be64 <_Z21F_InstanceActivateAllR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x10be24 ldrb r2, [r5, #0x69] */
/* @0x10be28 ldr r6, [pc, #0x7c] */
/* @0x10be2c cmp r2, #0 */
/* @0x10be30 beq 0x10be64 <_Z21F_InstanceActivateAllR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x10be34 ldr r6, [pc, r6] */
/* @0x10be38 ldmib r6, {r1, r2} */
/* @0x10be3c cmp r2, r1 */
/* @0x10be40 beq 0x10be78 <_Z21F_InstanceActivateAllR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x10be44 ldr r12, [r6] */
/* @0x10be48 mov r1, #0 */
/* @0x10be4c str r5, [r12, r2, lsl #2] */
/* @0x10be50 mov r0, r5 */
/* @0x10be54 add r3, r2, #1 */
/* @0x10be58 str r3, [r6, #0x8] */
/* @0x10be5c bl 0x19230c <_ZN9CInstance14SetDeactivatedEb> */
/* @0x10be60 ldr r1, [r7, #0x8] */
/* @0x10be64 add r4, r4, #1 */
/* @0x10be68 cmp r1, r4 */
/* @0x10be6c bgt 0x10be10 <_Z21F_InstanceActivateAllR6RValueP9CInstanceS2_iPS_+0x2c> */
/* @0x10be70 add sp, sp, #8 */
/* @0x10be74 pop {r4, r5, r6, r7, r8, pc} */
/* @0x10be78 lsl r12, r2, #1 */
/* @0x10be7c ldr r0, [r6] */
/* @0x10be80 str r12, [r6, #0x4] */
/* @0x10be84 lsl r1, r2, #3 */
/* @0x10be88 str r3, [sp] */
/* @0x10be8c mov r2, r8 */
/* @0x10be90 mov r3, #74 */
/* @0x10be94 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x10be98 ldr r2, [r6, #0x8] */
/* @0x10be9c mov r12, r0 */
/* @0x10bea0 str r0, [r6] */
/* @0x10bea4 b 0x10be48 <_Z21F_InstanceActivateAllR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x10bea8 eoreq r5, r2, r4, lsr #4 */
/* @0x10beac eoreq r1, lr, r4, lsl lr */

/* ── FUNC 0x10beb0 · F_InstanceActivateObject(RValue&, CInstance*, CInstance*, int, RValue*) · size=924 · insn=231 */
/* @0x10beb0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x10beb4 sub sp, sp, #12 */
/* @0x10beb8 mov r4, r1 */
/* @0x10bebc mov r1, #0 */
/* @0x10bec0 ldr r0, [sp, #0x30] */
/* @0x10bec4 mov r5, r2 */
/* @0x10bec8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x10becc ldr r8, [pc, #0x358] */
/* @0x10bed0 add r8, pc, r8 */
/* @0x10bed4 cmn r0, #1 */
/* @0x10bed8 mov r6, r0 */
/* @0x10bedc beq 0x10c018 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x168> */
/* @0x10bee0 cmn r0, #2 */
/* @0x10bee4 beq 0x10c058 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x1a8> */
/* @0x10bee8 cmn r0, #3 */
/* @0x10beec beq 0x10c0a8 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x1f8> */
/* @0x10bef0 movw r3, #0x869f */
/* @0x10bef4 movt r3, #0x1 */
/* @0x10bef8 cmp r0, r3 */
/* @0x10befc bgt 0x10bfb0 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x100> */
/* @0x10bf00 mov r0, #0 */
/* @0x10bf04 bl 0x10baf8 <_Z15GetDeactiveListPFvP9CInstanceE> */
/* @0x10bf08 ldr r2, [r0, #0x8] */
/* @0x10bf0c mov r11, r0 */
/* @0x10bf10 cmp r2, #0 */
/* @0x10bf14 ble 0x10c010 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x10bf18 ldr r10, [pc, #0x310] */
/* @0x10bf1c mov r4, #0 */
/* @0x10bf20 mov r9, r4 */
/* @0x10bf24 add r10, pc, r10 */
/* @0x10bf28 b 0x10bf6c <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x10bf2c ldr r3, [pc, #0x300] */
/* @0x10bf30 ldr r7, [r8, r3] */
/* @0x10bf34 ldmib r7, {r2, r3} */
/* @0x10bf38 cmp r3, r2 */
/* @0x10bf3c ldrne r2, [r7] */
/* @0x10bf40 beq 0x10c130 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x280> */
/* @0x10bf44 str r5, [r2, r3, lsl #2] */
/* @0x10bf48 mov r0, r5 */
/* @0x10bf4c mov r1, #0 */
/* @0x10bf50 add r3, r3, #1 */
/* @0x10bf54 str r3, [r7, #0x8] */
/* @0x10bf58 bl 0x19230c <_ZN9CInstance14SetDeactivatedEb> */
/* @0x10bf5c ldr r2, [r11, #0x8] */
/* @0x10bf60 add r4, r4, #1 */
/* @0x10bf64 cmp r2, r4 */
/* @0x10bf68 ble 0x10c010 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x10bf6c ldr r3, [r11] */
/* @0x10bf70 ldr r5, [r3, r4, lsl #2] */
/* @0x10bf74 ldrb r3, [r5, #0x68] */
/* @0x10bf78 cmp r3, #0 */
/* @0x10bf7c bne 0x10bf60 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x10bf80 ldrb r3, [r5, #0x69] */
/* @0x10bf84 cmp r3, #0 */
/* @0x10bf88 beq 0x10bf60 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x10bf8c ldr r3, [r5, #0x7c] */
/* @0x10bf90 cmp r6, r3 */
/* @0x10bf94 beq 0x10bf2c <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x10bf98 ldr r0, [r5, #0x80] */
/* @0x10bf9c mov r1, r6 */
/* @0x10bfa0 bl 0x19ddb0 <_ZN9CObjectGM13IsDecendentOfEi> */
/* @0x10bfa4 cmp r0, #0 */
/* @0x10bfa8 bne 0x10bf2c <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x10bfac b 0x10bf5c <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0x10bfb0 ldr r3, [pc, #0x280] */
/* @0x10bfb4 ldr r3, [r8, r3] */
/* @0x10bfb8 ldr r2, [r3, #0x4] */
/* @0x10bfbc ldr r3, [r3] */
/* @0x10bfc0 and r2, r0, r2 */
/* @0x10bfc4 ldr r3, [r3, r2, lsl #3] */
/* @0x10bfc8 cmp r3, #0 */
/* @0x10bfcc bne 0x10bfe0 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x10bfd0 b 0x10c010 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x10bfd4 ldr r3, [r3, #0x4] */
/* @0x10bfd8 cmp r3, #0 */
/* @0x10bfdc beq 0x10c010 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x10bfe0 ldr r2, [r3, #0x8] */
/* @0x10bfe4 cmp r6, r2 */
/* @0x10bfe8 bne 0x10bfd4 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x10bfec ldr r4, [r3, #0xc] */
/* @0x10bff0 cmp r4, #0 */
/* @0x10bff4 beq 0x10c010 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x10bff8 ldrb r12, [r4, #0x68] */
/* @0x10bffc cmp r12, #0 */
/* @0x10c000 bne 0x10c010 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x10c004 ldrb r3, [r4, #0x69] */
/* @0x10c008 cmp r3, #0 */
/* @0x10c00c bne 0x10c160 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x2b0> */
/* @0x10c010 add sp, sp, #12 */
/* @0x10c014 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x10c018 cmp r4, #0 */
/* @0x10c01c beq 0x10c010 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x10c020 ldrb r12, [r4, #0x68] */
/* @0x10c024 cmp r12, #0 */
/* @0x10c028 bne 0x10c010 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x10c02c ldr r3, [pc, #0x200] */
/* @0x10c030 ldr r7, [r8, r3] */
/* @0x10c034 ldr r1, [r7, #0x8] */
/* @0x10c038 ldr r3, [r7, #0x4] */
/* @0x10c03c cmp r1, r3 */
/* @0x10c040 beq 0x10c1dc <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x32c> */
/* @0x10c044 ldr r3, [r7] */
/* @0x10c048 str r4, [r3, r1, lsl #2] */
/* @0x10c04c mov r0, r4 */
/* @0x10c050 add r3, r1, #1 */
/* @0x10c054 b 0x10c094 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x10c058 cmp r5, #0 */
/* @0x10c05c beq 0x10c010 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x10c060 ldrb r12, [r5, #0x68] */
/* @0x10c064 cmp r12, #0 */
/* @0x10c068 bne 0x10c010 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x10c06c ldr r3, [pc, #0x1c0] */
/* @0x10c070 ldr r7, [r8, r3] */
/* @0x10c074 ldr r1, [r7, #0x8] */
/* @0x10c078 ldr r3, [r7, #0x4] */
/* @0x10c07c cmp r1, r3 */
/* @0x10c080 beq 0x10c1f8 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x348> */
/* @0x10c084 ldr r3, [r7] */
/* @0x10c088 str r5, [r3, r1, lsl #2] */
/* @0x10c08c add r3, r1, #1 */
/* @0x10c090 mov r0, r5 */
/* @0x10c094 mov r1, #0 */
/* @0x10c098 str r3, [r7, #0x8] */
/* @0x10c09c add sp, sp, #12 */
/* @0x10c0a0 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x10c0a4 b 0x19230c <_ZN9CInstance14SetDeactivatedEb> */
/* @0x10c0a8 mov r0, #0 */
/* @0x10c0ac bl 0x10baf8 <_Z15GetDeactiveListPFvP9CInstanceE> */
/* @0x10c0b0 ldr r2, [r0, #0x8] */
/* @0x10c0b4 mov r6, r0 */
/* @0x10c0b8 cmp r2, #0 */
/* @0x10c0bc ble 0x10c010 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x10c0c0 ldr r9, [pc, #0x174] */
/* @0x10c0c4 mov r4, #0 */
/* @0x10c0c8 add r9, pc, r9 */
/* @0x10c0cc ldr r3, [r6] */
/* @0x10c0d0 ldr r5, [r3, r4, lsl #2] */
/* @0x10c0d4 ldrb r3, [r5, #0x68] */
/* @0x10c0d8 cmp r3, #0 */
/* @0x10c0dc bne 0x10c120 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x270> */
/* @0x10c0e0 ldrb r1, [r5, #0x69] */
/* @0x10c0e4 ldr r0, [pc, #0x148] */
/* @0x10c0e8 cmp r1, #0 */
/* @0x10c0ec beq 0x10c120 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x270> */
/* @0x10c0f0 ldr r7, [r8, r0] */
/* @0x10c0f4 ldmib r7, {r1, r2} */
/* @0x10c0f8 cmp r2, r1 */
/* @0x10c0fc beq 0x10c1ac <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x2fc> */
/* @0x10c100 ldr r12, [r7] */
/* @0x10c104 str r5, [r12, r2, lsl #2] */
/* @0x10c108 mov r1, #0 */
/* @0x10c10c mov r0, r5 */
/* @0x10c110 add r3, r2, #1 */
/* @0x10c114 str r3, [r7, #0x8] */
/* @0x10c118 bl 0x19230c <_ZN9CInstance14SetDeactivatedEb> */
/* @0x10c11c ldr r2, [r6, #0x8] */
/* @0x10c120 add r4, r4, #1 */
/* @0x10c124 cmp r2, r4 */
/* @0x10c128 bgt 0x10c0cc <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x21c> */
/* @0x10c12c b 0x10c010 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x10c130 lsl r2, r3, #1 */
/* @0x10c134 ldr r0, [r7] */
/* @0x10c138 str r2, [r7, #0x4] */
/* @0x10c13c lsl r1, r3, #3 */
/* @0x10c140 mov r2, r10 */
/* @0x10c144 mov r3, #74 */
/* @0x10c148 str r9, [sp] */
/* @0x10c14c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x10c150 ldr r3, [r7, #0x8] */
/* @0x10c154 mov r2, r0 */
/* @0x10c158 str r0, [r7] */
/* @0x10c15c b 0x10bf44 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x10c160 ldr r3, [pc, #0xcc] */
/* @0x10c164 ldr r7, [r8, r3] */
/* @0x10c168 ldr r1, [r7, #0x8] */
/* @0x10c16c ldr r3, [r7, #0x4] */
/* @0x10c170 cmp r1, r3 */
/* @0x10c174 bne 0x10c044 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x10c178 ldr r2, [pc, #0xc0] */
/* @0x10c17c lsl r3, r1, #1 */
/* @0x10c180 ldr r0, [r7] */
/* @0x10c184 lsl r1, r1, #3 */
/* @0x10c188 add r2, pc, r2 */
/* @0x10c18c str r3, [r7, #0x4] */
/* @0x10c190 mov r3, #74 */
/* @0x10c194 str r12, [sp] */
/* @0x10c198 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x10c19c ldr r1, [r7, #0x8] */
/* @0x10c1a0 mov r3, r0 */
/* @0x10c1a4 str r0, [r7] */
/* @0x10c1a8 b 0x10c048 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x10c1ac lsl r12, r2, #1 */
/* @0x10c1b0 ldr r0, [r7] */
/* @0x10c1b4 str r12, [r7, #0x4] */
/* @0x10c1b8 lsl r1, r2, #3 */
/* @0x10c1bc str r3, [sp] */
/* @0x10c1c0 mov r2, r9 */
/* @0x10c1c4 mov r3, #74 */
/* @0x10c1c8 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x10c1cc ldr r2, [r7, #0x8] */
/* @0x10c1d0 mov r12, r0 */
/* @0x10c1d4 str r0, [r7] */
/* @0x10c1d8 b 0x10c104 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x254> */
/* @0x10c1dc ldr r2, [pc, #0x60] */
/* @0x10c1e0 lsl r3, r1, #1 */
/* @0x10c1e4 ldr r0, [r7] */
/* @0x10c1e8 lsl r1, r1, #3 */
/* @0x10c1ec str r3, [r7, #0x4] */
/* @0x10c1f0 add r2, pc, r2 */
/* @0x10c1f4 b 0x10c190 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x2e0> */
/* @0x10c1f8 ldr r2, [pc, #0x48] */
/* @0x10c1fc lsl r3, r1, #1 */
/* @0x10c200 ldr r0, [r7] */
/* @0x10c204 lsl r1, r1, #3 */
/* @0x10c208 str r3, [r7, #0x4] */
/* @0x10c20c add r2, pc, r2 */
/* @0x10c210 mov r3, #74 */
/* @0x10c214 str r12, [sp] */
/* @0x10c218 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x10c21c ldr r1, [r7, #0x8] */
/* @0x10c220 mov r3, r0 */
/* @0x10c224 str r0, [r7] */
/* @0x10c228 b 0x10c088 <_Z24F_InstanceActivateObjectR6RValueP9CInstanceS2_iPS_+0x1d8> */
/* @0x10c22c eoreq r5, lr, r0, lsl #27 */
/* @0x10c230 eoreq r5, r2, r12, lsl #2 */
/* @0x10c234 .word 0xffffbff8 */
/* @0x10c238 .word 0xffffbff4 */
/* @0x10c23c eoreq r4, r2, r8, ror #30 */
/* @0x10c240 eoreq r4, r2, r8, lsr #29 */
/* @0x10c244 eoreq r4, r2, r0, asr #28 */
/* @0x10c248 eoreq r4, r2, r4, lsr #28 */

/* ── FUNC 0x10c24c · F_InstanceActivateRegion(RValue&, CInstance*, CInstance*, int, RValue*) · size=152 · insn=38 */
/* @0x10c24c push {r3, r4, r5, lr} */
/* @0x10c250 vpush {d8} */
/* @0x10c254 mov r1, #4 */
/* @0x10c258 ldr r5, [sp, #0x18] */
/* @0x10c25c ldr r4, [pc, #0x78] */
/* @0x10c260 mov r0, r5 */
/* @0x10c264 add r4, pc, r4 */
/* @0x10c268 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x10c26c mov r1, #0 */
/* @0x10c270 strb r0, [r4, #0xc] */
/* @0x10c274 mov r0, r5 */
/* @0x10c278 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10c27c mov r1, #1 */
/* @0x10c280 str r0, [r4, #0x10] */
/* @0x10c284 mov r0, r5 */
/* @0x10c288 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10c28c mov r1, #2 */
/* @0x10c290 vldr s17, [r4, #16] */
/* @0x10c294 str r0, [r4, #0x14] */
/* @0x10c298 mov r0, r5 */
/* @0x10c29c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10c2a0 mov r1, #3 */
/* @0x10c2a4 vldr s16, [r4, #20] */
/* @0x10c2a8 vmov s15, r0 */
/* @0x10c2ac mov r0, r5 */
/* @0x10c2b0 vadd.f32 s17, s17, s15 */
/* @0x10c2b4 vstr s17, [r4, #24] */
/* @0x10c2b8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10c2bc ldr r3, [pc, #0x1c] */
/* @0x10c2c0 vmov s15, r0 */
/* @0x10c2c4 ldr r0, [pc, r3] */
/* @0x10c2c8 vadd.f32 s16, s16, s15 */
/* @0x10c2cc vstr s16, [r4, #28] */
/* @0x10c2d0 vpop {d8} */
/* @0x10c2d4 pop {r3, r4, r5, lr} */
/* @0x10c2d8 b 0x10baf8 <_Z15GetDeactiveListPFvP9CInstanceE> */
/* @0x10c2dc eorseq r7, r7, r4, ror r4 */
/* @0x10c2e0 eoreq r1, lr, r0, lsl #28 */

/* ── FUNC 0x10c2e4 · YYGML_room_goto_previous() · size=20 · insn=5 */
/* @0x10c2e4 ldr r3, [pc, #0x8] */
/* @0x10c2e8 ldr r3, [pc, r3] */
/* @0x10c2ec ldr r0, [r3] */
/* @0x10c2f0 b 0x1c9e68 <_Z20Command_PreviousRoomi> */
/* @0x10c2f4 eoreq r1, lr, r0, asr #27 */

/* ── FUNC 0x10c2f8 · YYGML_room_goto_next() · size=20 · insn=5 */
/* @0x10c2f8 ldr r3, [pc, #0x8] */
/* @0x10c2fc ldr r3, [pc, r3] */
/* @0x10c300 ldr r0, [r3] */
/* @0x10c304 b 0x1c9ed0 <_Z16Command_NextRoomi> */
/* @0x10c308 eoreq r1, lr, r12, lsr #27 */

/* ── FUNC 0x10c30c · YYGML_room_restart() · size=20 · insn=5 */
/* @0x10c30c ldr r3, [pc, #0x8] */
/* @0x10c310 ldr r3, [pc, r3] */
/* @0x10c314 ldr r0, [r3] */
/* @0x10c318 b 0x1c9f38 <_Z19Command_CurrentRoomi> */
/* @0x10c31c mlaeq lr, r8, sp, r1 */

/* ── FUNC 0x10c320 · YYGML_game_end() · size=4 · insn=1 */
/* @0x10c320 b 0x1c9f50 <_Z15Command_EndGamev> */

/* ── FUNC 0x10c324 · YYGML_game_restart() · size=4 · insn=1 */
/* @0x10c324 b 0x1c9f54 <_Z19Command_RestartGamev> */

/* ── FUNC 0x10c328 · Point_In_Triangle(float, float, float, float, float, float, float, float) · size=192 · insn=48 */
/* @0x10c328 vmov s14, r3 */
/* @0x10c32c vldr s10, [sp, #4] */
/* @0x10c330 vldr s11, [sp, #12] */
/* @0x10c334 vmov s7, r2 */
/* @0x10c338 vsub.f32 s11, s11, s14 */
/* @0x10c33c vldr s12, [sp] */
/* @0x10c340 vldr s13, [sp, #8] */
/* @0x10c344 vmov s5, r1 */
/* @0x10c348 vsub.f32 s10, s10, s14 */
/* @0x10c34c vmul.f32 s15, s11, s10 */
/* @0x10c350 vsub.f32 s12, s12, s7 */
/* @0x10c354 vsub.f32 s13, s13, s7 */
/* @0x10c358 vsub.f32 s6, s5, s14 */
/* @0x10c35c vmov s5, r0 */
/* @0x10c360 vmla.f32 s15, s13, s12 */
/* @0x10c364 vmul.f32 s9, s11, s11 */
/* @0x10c368 vmul.f32 s14, s10, s10 */
/* @0x10c36c vmla.f32 s9, s13, s13 */
/* @0x10c370 vmla.f32 s14, s12, s12 */
/* @0x10c374 vmul.f32 s8, s15, s15 */
/* @0x10c378 vmul.f32 s10, s10, s6 */
/* @0x10c37c vsub.f32 s7, s5, s7 */
/* @0x10c380 vnmls.f32 s8, s9, s14 */
/* @0x10c384 vmla.f32 s10, s12, s7 */
/* @0x10c388 vmul.f32 s11, s11, s6 */
/* @0x10c38c vmov.f32 s12, #1.000000e+00 */
/* @0x10c390 vmla.f32 s11, s13, s7 */
/* @0x10c394 vdiv.f32 s8, s12, s8 */
/* @0x10c398 vmul.f32 s13, s15, s10 */
/* @0x10c39c vnmls.f32 s13, s14, s11 */
/* @0x10c3a0 vmul.f32 s13, s13, s8 */
/* @0x10c3a4 vcmpe.f32 s13, #0 */
/* @0x10c3a8 vmrs APSR_nzcv, fpscr */
/* @0x10c3ac blt 0x10c3e0 <_Z17Point_In_Triangleffffffff+0xb8> */
/* @0x10c3b0 vmul.f32 s11, s15, s11 */
/* @0x10c3b4 vnmls.f32 s11, s9, s10 */
/* @0x10c3b8 vmul.f32 s11, s11, s8 */
/* @0x10c3bc vcmpe.f32 s11, #0 */
/* @0x10c3c0 vmrs APSR_nzcv, fpscr */
/* @0x10c3c4 blt 0x10c3e0 <_Z17Point_In_Triangleffffffff+0xb8> */
/* @0x10c3c8 vadd.f32 s11, s13, s11 */
/* @0x10c3cc vcmpe.f32 s11, s12 */
/* @0x10c3d0 vmrs APSR_nzcv, fpscr */
/* @0x10c3d4 movpl r0, #0 */
/* @0x10c3d8 movmi r0, #1 */
/* @0x10c3dc bx lr */
/* @0x10c3e0 mov r0, #0 */
/* @0x10c3e4 bx lr */

/* ── FUNC 0x10c3e8 · F_Point_In_Triangle(RValue&, CInstance*, CInstance*, int, RValue*) · size=220 · insn=55 */
/* @0x10c3e8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x10c3ec sub sp, sp, #28 */
/* @0x10c3f0 mov r5, r0 */
/* @0x10c3f4 mov r1, #0 */
/* @0x10c3f8 ldr r4, [sp, #0x40] */
/* @0x10c3fc str r1, [r0, #0xc] */
/* @0x10c400 mov r0, r4 */
/* @0x10c404 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10c408 mov r1, #1 */
/* @0x10c40c mov r6, r0 */
/* @0x10c410 mov r0, r4 */
/* @0x10c414 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10c418 mov r1, #2 */
/* @0x10c41c mov r9, r0 */
/* @0x10c420 mov r0, r4 */
/* @0x10c424 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10c428 mov r1, #3 */
/* @0x10c42c mov r8, r0 */
/* @0x10c430 mov r0, r4 */
/* @0x10c434 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10c438 mov r1, #4 */
/* @0x10c43c mov r7, r0 */
/* @0x10c440 mov r0, r4 */
/* @0x10c444 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10c448 mov r1, #5 */
/* @0x10c44c mov r3, r0 */
/* @0x10c450 mov r0, r4 */
/* @0x10c454 str r3, [sp, #0x14] */
/* @0x10c458 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10c45c mov r1, #6 */
/* @0x10c460 mov r11, r0 */
/* @0x10c464 mov r0, r4 */
/* @0x10c468 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10c46c mov r1, #7 */
/* @0x10c470 mov r10, r0 */
/* @0x10c474 mov r0, r4 */
/* @0x10c478 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10c47c ldr r3, [sp, #0x14] */
/* @0x10c480 mov r1, r9 */
/* @0x10c484 mov r2, r8 */
/* @0x10c488 str r11, [sp, #0x4] */
/* @0x10c48c str r3, [sp] */
/* @0x10c490 mov r3, r7 */
/* @0x10c494 str r10, [sp, #0x8] */
/* @0x10c498 str r0, [sp, #0xc] */
/* @0x10c49c mov r0, r6 */
/* @0x10c4a0 bl 0x10c328 <_Z17Point_In_Triangleffffffff> */
/* @0x10c4a4 vmov s15, r0 */
/* @0x10c4a8 vcvt.f64.u32 d7, s15 */
/* @0x10c4ac vmov r0, r1, d7 */
/* @0x10c4b0 vmov r2, s14 */
/* @0x10c4b4 mov r3, r1 */
/* @0x10c4b8 stm r5, {r2, r3} */
/* @0x10c4bc add sp, sp, #28 */
/* @0x10c4c0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x10c4c4 · F_Rectangle_In_Triangle(RValue&, CInstance*, CInstance*, int, RValue*) · size=436 · insn=109 */
/* @0x10c4c4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x10c4c8 sub sp, sp, #36 */
/* @0x10c4cc mov r11, r0 */
/* @0x10c4d0 mov r1, #0 */
/* @0x10c4d4 ldr r6, [sp, #0x48] */
/* @0x10c4d8 mov r0, r6 */
/* @0x10c4dc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10c4e0 mov r1, #1 */
/* @0x10c4e4 str r0, [sp, #0x10] */
/* @0x10c4e8 mov r0, r6 */
/* @0x10c4ec bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10c4f0 mov r1, #2 */
/* @0x10c4f4 str r0, [sp, #0x14] */
/* @0x10c4f8 mov r0, r6 */
/* @0x10c4fc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10c500 mov r1, #3 */
/* @0x10c504 str r0, [sp, #0x18] */
/* @0x10c508 mov r0, r6 */
/* @0x10c50c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10c510 mov r1, #4 */
/* @0x10c514 str r0, [sp, #0x1c] */
/* @0x10c518 mov r0, r6 */
/* @0x10c51c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10c520 mov r1, #5 */
/* @0x10c524 mov r5, r0 */
/* @0x10c528 mov r0, r6 */
/* @0x10c52c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10c530 mov r1, #6 */
/* @0x10c534 mov r4, r0 */
/* @0x10c538 mov r0, r6 */
/* @0x10c53c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10c540 mov r1, #7 */
/* @0x10c544 mov r9, r0 */
/* @0x10c548 mov r0, r6 */
/* @0x10c54c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10c550 mov r1, #8 */
/* @0x10c554 mov r8, r0 */
/* @0x10c558 mov r0, r6 */
/* @0x10c55c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10c560 mov r1, #9 */
/* @0x10c564 mov r7, r0 */
/* @0x10c568 mov r0, r6 */
/* @0x10c56c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10c570 str r9, [sp] */
/* @0x10c574 str r8, [sp, #0x4] */
/* @0x10c578 mov r3, #0 */
/* @0x10c57c str r7, [sp, #0x8] */
/* @0x10c580 mov r2, r5 */
/* @0x10c584 ldr r1, [sp, #0x14] */
/* @0x10c588 mov r6, r0 */
/* @0x10c58c str r0, [sp, #0xc] */
/* @0x10c590 str r3, [r11, #0xc] */
/* @0x10c594 mov r3, r4 */
/* @0x10c598 ldr r0, [sp, #0x10] */
/* @0x10c59c bl 0x10c328 <_Z17Point_In_Triangleffffffff> */
/* @0x10c5a0 ldr r1, [sp, #0x14] */
/* @0x10c5a4 mov r2, r5 */
/* @0x10c5a8 mov r3, r4 */
/* @0x10c5ac str r9, [sp] */
/* @0x10c5b0 str r8, [sp, #0x4] */
/* @0x10c5b4 str r7, [sp, #0x8] */
/* @0x10c5b8 str r6, [sp, #0xc] */
/* @0x10c5bc mov r10, r0 */
/* @0x10c5c0 ldr r0, [sp, #0x18] */
/* @0x10c5c4 bl 0x10c328 <_Z17Point_In_Triangleffffffff> */
/* @0x10c5c8 ldr r1, [sp, #0x1c] */
/* @0x10c5cc mov r2, r5 */
/* @0x10c5d0 mov r3, r4 */
/* @0x10c5d4 str r9, [sp] */
/* @0x10c5d8 str r8, [sp, #0x4] */
/* @0x10c5dc str r7, [sp, #0x8] */
/* @0x10c5e0 str r6, [sp, #0xc] */
/* @0x10c5e4 cmp r0, #0 */
/* @0x10c5e8 ldr r0, [sp, #0x18] */
/* @0x10c5ec orrne r10, r10, #2 */
/* @0x10c5f0 bl 0x10c328 <_Z17Point_In_Triangleffffffff> */
/* @0x10c5f4 str r9, [sp] */
/* @0x10c5f8 mov r2, r5 */
/* @0x10c5fc str r8, [sp, #0x4] */
/* @0x10c600 mov r3, r4 */
/* @0x10c604 str r7, [sp, #0x8] */
/* @0x10c608 str r6, [sp, #0xc] */
/* @0x10c60c ldr r1, [sp, #0x1c] */
/* @0x10c610 cmp r0, #0 */
/* @0x10c614 ldr r0, [sp, #0x10] */
/* @0x10c618 orrne r10, r10, #4 */
/* @0x10c61c bl 0x10c328 <_Z17Point_In_Triangleffffffff> */
/* @0x10c620 cmp r0, #0 */
/* @0x10c624 beq 0x10c648 <_Z23F_Rectangle_In_TriangleR6RValueP9CInstanceS2_iPS_+0x184> */
/* @0x10c628 orr r10, r10, #8 */
/* @0x10c62c cmp r10, #15 */
/* @0x10c630 beq 0x10c660 <_Z23F_Rectangle_In_TriangleR6RValueP9CInstanceS2_iPS_+0x19c> */
/* @0x10c634 mov r2, #0 */
/* @0x10c638 mov r3, #1073741824 */
/* @0x10c63c stm r11, {r2, r3} */
/* @0x10c640 add sp, sp, #36 */
/* @0x10c644 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x10c648 cmp r10, #0 */
/* @0x10c64c streq r10, [r11] */
/* @0x10c650 streq r10, [r11, #0x4] */
/* @0x10c654 bne 0x10c634 <_Z23F_Rectangle_In_TriangleR6RValueP9CInstanceS2_iPS_+0x170> */
/* @0x10c658 add sp, sp, #36 */
/* @0x10c65c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x10c660 mov r3, #0 */
/* @0x10c664 mov r2, r3 */
/* @0x10c668 movt r3, #0x3ff0 */
/* @0x10c66c stm r11, {r2, r3} */
/* @0x10c670 add sp, sp, #36 */
/* @0x10c674 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x10c678 · F_Circle_In_Rectangle(RValue&, CInstance*, CInstance*, int, RValue*) · size=352 · insn=88 */
/* @0x10c678 push {r3, r4, r5, lr} */
/* @0x10c67c vpush {d8, d9, d10} */
/* @0x10c680 mov r1, #0 */
/* @0x10c684 ldr r4, [sp, #0x28] */
/* @0x10c688 mov r5, r0 */
/* @0x10c68c mov r0, r4 */
/* @0x10c690 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10c694 mov r1, #1 */
/* @0x10c698 vmov s18, r0 */
/* @0x10c69c mov r0, r4 */
/* @0x10c6a0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10c6a4 mov r1, #2 */
/* @0x10c6a8 vmov s20, r0 */
/* @0x10c6ac mov r0, r4 */
/* @0x10c6b0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10c6b4 mov r1, #3 */
/* @0x10c6b8 vmov s19, r0 */
/* @0x10c6bc mov r0, r4 */
/* @0x10c6c0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10c6c4 mov r1, #4 */
/* @0x10c6c8 vmov s21, r0 */
/* @0x10c6cc mov r0, r4 */
/* @0x10c6d0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10c6d4 mov r1, #5 */
/* @0x10c6d8 vmov s16, r0 */
/* @0x10c6dc mov r0, r4 */
/* @0x10c6e0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10c6e4 mov r1, #6 */
/* @0x10c6e8 vmov s17, r0 */
/* @0x10c6ec mov r0, r4 */
/* @0x10c6f0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10c6f4 vcmpe.f32 s18, s16 */
/* @0x10c6f8 vmrs APSR_nzcv, fpscr */
/* @0x10c6fc vmovle.f32 s15, s16 */
/* @0x10c700 vmovgt.f32 s15, s18 */
/* @0x10c704 vcmp.f32 s15, s19 */
/* @0x10c708 vmrs APSR_nzcv, fpscr */
/* @0x10c70c vcmpe.f32 s20, s17 */
/* @0x10c710 vmovgt.f32 s15, s19 */
/* @0x10c714 vmrs APSR_nzcv, fpscr */
/* @0x10c718 vmovle.f32 s14, s17 */
/* @0x10c71c vmovgt.f32 s14, s20 */
/* @0x10c720 vcmp.f32 s14, s21 */
/* @0x10c724 vmrs APSR_nzcv, fpscr */
/* @0x10c728 vmovgt.f32 s14, s21 */
/* @0x10c72c vsub.f32 s14, s14, s17 */
/* @0x10c730 vmov s13, r0 */
/* @0x10c734 vmul.f32 s14, s14, s14 */
/* @0x10c738 vsub.f32 s15, s15, s16 */
/* @0x10c73c vmla.f32 s14, s15, s15 */
/* @0x10c740 vmul.f32 s15, s13, s13 */
/* @0x10c744 vcmpe.f32 s15, s14 */
/* @0x10c748 vmrs APSR_nzcv, fpscr */
/* @0x10c74c blt 0x10c7c4 <_Z21F_Circle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x14c> */
/* @0x10c750 vsub.f32 s18, s16, s18 */
/* @0x10c754 mov r3, #0 */
/* @0x10c758 mov r2, #1073741824 */
/* @0x10c75c str r3, [r5] */
/* @0x10c760 str r2, [r5, #0x4] */
/* @0x10c764 vabs.f32 s18, s18 */
/* @0x10c768 vcmpe.f32 s13, s18 */
/* @0x10c76c vmrs APSR_nzcv, fpscr */
/* @0x10c770 bpl 0x10c7bc <_Z21F_Circle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x10c774 vsub.f32 s16, s16, s19 */
/* @0x10c778 vabs.f32 s16, s16 */
/* @0x10c77c vcmpe.f32 s13, s16 */
/* @0x10c780 vmrs APSR_nzcv, fpscr */
/* @0x10c784 bpl 0x10c7bc <_Z21F_Circle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x10c788 vsub.f32 s20, s17, s20 */
/* @0x10c78c vabs.f32 s20, s20 */
/* @0x10c790 vcmpe.f32 s13, s20 */
/* @0x10c794 vmrs APSR_nzcv, fpscr */
/* @0x10c798 bpl 0x10c7bc <_Z21F_Circle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x10c79c vsub.f32 s17, s17, s21 */
/* @0x10c7a0 vabs.f32 s17, s17 */
/* @0x10c7a4 vcmpe.f32 s13, s17 */
/* @0x10c7a8 vmrs APSR_nzcv, fpscr */
/* @0x10c7ac strmi r3, [r5] */
/* @0x10c7b0 movmi r3, #0 */
/* @0x10c7b4 movtmi r3, #0x3ff0 */
/* @0x10c7b8 strmi r3, [r5, #0x4] */
/* @0x10c7bc vpop {d8, d9, d10} */
/* @0x10c7c0 pop {r3, r4, r5, pc} */
/* @0x10c7c4 mov r3, #0 */
/* @0x10c7c8 str r3, [r5] */
/* @0x10c7cc str r3, [r5, #0x4] */
/* @0x10c7d0 vpop {d8, d9, d10} */
/* @0x10c7d4 pop {r3, r4, r5, pc} */
