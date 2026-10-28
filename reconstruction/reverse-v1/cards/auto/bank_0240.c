/* libyoyo.so 覆盖卡组 0240
 * 函数 0x28addc..0x28ee80，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x28addc · spSkeletonData_create · size=28 · insn=7 */
/* @0x28addc ldr r2, [pc, #0x10] */
/* @0x28ade0 mov r0, #1 */
/* @0x28ade4 mov r1, #84 */
/* @0x28ade8 mov r3, #37 */
/* @0x28adec add r2, pc, r2 */
/* @0x28adf0 b 0x285c4c <_calloc> */
/* @0x28adf4 strheq r12, [r12], -r12 */

/* ── FUNC 0x28adf8 · spSkeletonData_dispose · size=452 · insn=113 */
/* @0x28adf8 push {r3, r4, r5, lr} */
/* @0x28adfc mov r4, r0 */
/* @0x28ae00 ldr r3, [r0, #0x10] */
/* @0x28ae04 cmp r3, #0 */
/* @0x28ae08 movgt r5, #0 */
/* @0x28ae0c ble 0x28ae2c <spSkeletonData_dispose+0x34> */
/* @0x28ae10 ldr r3, [r4, #0x14] */
/* @0x28ae14 ldr r0, [r3, r5, lsl #2] */
/* @0x28ae18 add r5, r5, #1 */
/* @0x28ae1c bl 0x285ac4 <spBoneData_dispose> */
/* @0x28ae20 ldr r3, [r4, #0x10] */
/* @0x28ae24 cmp r3, r5 */
/* @0x28ae28 bgt 0x28ae10 <spSkeletonData_dispose+0x18> */
/* @0x28ae2c ldr r0, [r4, #0x14] */
/* @0x28ae30 bl 0x285c80 <_free> */
/* @0x28ae34 ldr r3, [r4, #0x18] */
/* @0x28ae38 cmp r3, #0 */
/* @0x28ae3c movgt r5, #0 */
/* @0x28ae40 ble 0x28ae60 <spSkeletonData_dispose+0x68> */
/* @0x28ae44 ldr r3, [r4, #0x1c] */
/* @0x28ae48 ldr r0, [r3, r5, lsl #2] */
/* @0x28ae4c add r5, r5, #1 */
/* @0x28ae50 bl 0x28efa8 <spSlotData_dispose> */
/* @0x28ae54 ldr r3, [r4, #0x18] */
/* @0x28ae58 cmp r3, r5 */
/* @0x28ae5c bgt 0x28ae44 <spSkeletonData_dispose+0x4c> */
/* @0x28ae60 ldr r0, [r4, #0x1c] */
/* @0x28ae64 bl 0x285c80 <_free> */
/* @0x28ae68 ldr r3, [r4, #0x20] */
/* @0x28ae6c cmp r3, #0 */
/* @0x28ae70 movgt r5, #0 */
/* @0x28ae74 ble 0x28ae94 <spSkeletonData_dispose+0x9c> */
/* @0x28ae78 ldr r3, [r4, #0x24] */
/* @0x28ae7c ldr r0, [r3, r5, lsl #2] */
/* @0x28ae80 add r5, r5, #1 */
/* @0x28ae84 bl 0x28ec9c <spSkin_dispose> */
/* @0x28ae88 ldr r3, [r4, #0x20] */
/* @0x28ae8c cmp r3, r5 */
/* @0x28ae90 bgt 0x28ae78 <spSkeletonData_dispose+0x80> */
/* @0x28ae94 ldr r0, [r4, #0x24] */
/* @0x28ae98 bl 0x285c80 <_free> */
/* @0x28ae9c ldr r3, [r4, #0x2c] */
/* @0x28aea0 cmp r3, #0 */
/* @0x28aea4 movgt r5, #0 */
/* @0x28aea8 ble 0x28aec8 <spSkeletonData_dispose+0xd0> */
/* @0x28aeac ldr r3, [r4, #0x30] */
/* @0x28aeb0 ldr r0, [r3, r5, lsl #2] */
/* @0x28aeb4 add r5, r5, #1 */
/* @0x28aeb8 bl 0x285bec <spEventData_dispose> */
/* @0x28aebc ldr r3, [r4, #0x2c] */
/* @0x28aec0 cmp r3, r5 */
/* @0x28aec4 bgt 0x28aeac <spSkeletonData_dispose+0xb4> */
/* @0x28aec8 ldr r0, [r4, #0x30] */
/* @0x28aecc bl 0x285c80 <_free> */
/* @0x28aed0 ldr r3, [r4, #0x34] */
/* @0x28aed4 cmp r3, #0 */
/* @0x28aed8 movgt r5, #0 */
/* @0x28aedc ble 0x28aefc <spSkeletonData_dispose+0x104> */
/* @0x28aee0 ldr r3, [r4, #0x38] */
/* @0x28aee4 ldr r0, [r3, r5, lsl #2] */
/* @0x28aee8 add r5, r5, #1 */
/* @0x28aeec bl 0x28147c <spAnimation_dispose> */
/* @0x28aef0 ldr r3, [r4, #0x34] */
/* @0x28aef4 cmp r3, r5 */
/* @0x28aef8 bgt 0x28aee0 <spSkeletonData_dispose+0xe8> */
/* @0x28aefc ldr r0, [r4, #0x38] */
/* @0x28af00 bl 0x285c80 <_free> */
/* @0x28af04 ldr r3, [r4, #0x3c] */
/* @0x28af08 cmp r3, #0 */
/* @0x28af0c movgt r5, #0 */
/* @0x28af10 ble 0x28af30 <spSkeletonData_dispose+0x138> */
/* @0x28af14 ldr r3, [r4, #0x40] */
/* @0x28af18 ldr r0, [r3, r5, lsl #2] */
/* @0x28af1c add r5, r5, #1 */
/* @0x28af20 bl 0x286758 <spIkConstraintData_dispose> */
/* @0x28af24 ldr r3, [r4, #0x3c] */
/* @0x28af28 cmp r3, r5 */
/* @0x28af2c bgt 0x28af14 <spSkeletonData_dispose+0x11c> */
/* @0x28af30 ldr r0, [r4, #0x40] */
/* @0x28af34 bl 0x285c80 <_free> */
/* @0x28af38 ldr r3, [r4, #0x44] */
/* @0x28af3c cmp r3, #0 */
/* @0x28af40 movgt r5, #0 */
/* @0x28af44 ble 0x28af64 <spSkeletonData_dispose+0x16c> */
/* @0x28af48 ldr r3, [r4, #0x48] */
/* @0x28af4c ldr r0, [r3, r5, lsl #2] */
/* @0x28af50 add r5, r5, #1 */
/* @0x28af54 bl 0x28f608 <spTransformConstraintData_dispose> */
/* @0x28af58 ldr r3, [r4, #0x44] */
/* @0x28af5c cmp r3, r5 */
/* @0x28af60 bgt 0x28af48 <spSkeletonData_dispose+0x150> */
/* @0x28af64 ldr r0, [r4, #0x48] */
/* @0x28af68 bl 0x285c80 <_free> */
/* @0x28af6c ldr r3, [r4, #0x4c] */
/* @0x28af70 cmp r3, #0 */
/* @0x28af74 movgt r5, #0 */
/* @0x28af78 ble 0x28af98 <spSkeletonData_dispose+0x1a0> */
/* @0x28af7c ldr r3, [r4, #0x50] */
/* @0x28af80 ldr r0, [r3, r5, lsl #2] */
/* @0x28af84 add r5, r5, #1 */
/* @0x28af88 bl 0x288f34 <spPathConstraintData_dispose> */
/* @0x28af8c ldr r3, [r4, #0x4c] */
/* @0x28af90 cmp r3, r5 */
/* @0x28af94 bgt 0x28af7c <spSkeletonData_dispose+0x184> */
/* @0x28af98 ldr r0, [r4, #0x50] */
/* @0x28af9c bl 0x285c80 <_free> */
/* @0x28afa0 ldr r0, [r4, #0x4] */
/* @0x28afa4 bl 0x285c80 <_free> */
/* @0x28afa8 ldr r0, [r4] */
/* @0x28afac bl 0x285c80 <_free> */
/* @0x28afb0 mov r0, r4 */
/* @0x28afb4 pop {r3, r4, r5, lr} */
/* @0x28afb8 b 0x285c80 <_free> */

/* ── FUNC 0x28afbc · spSkeletonData_findBone · size=92 · insn=23 */
/* @0x28afbc push {r4, r5, r6, r7, r8, lr} */
/* @0x28afc0 mov r8, r1 */
/* @0x28afc4 ldr r7, [r0, #0x10] */
/* @0x28afc8 cmp r7, #0 */
/* @0x28afcc ble 0x28b00c <spSkeletonData_findBone+0x50> */
/* @0x28afd0 ldr r6, [r0, #0x14] */
/* @0x28afd4 mov r4, #0 */
/* @0x28afd8 sub r6, r6, #4 */
/* @0x28afdc b 0x28afe8 <spSkeletonData_findBone+0x2c> */
/* @0x28afe0 cmp r4, r7 */
/* @0x28afe4 beq 0x28b00c <spSkeletonData_findBone+0x50> */
/* @0x28afe8 ldr r5, [r6, #0x4]! */
/* @0x28afec mov r1, r8 */
/* @0x28aff0 add r4, r4, #1 */
/* @0x28aff4 ldr r0, [r5, #0x4] */
/* @0x28aff8 bl 0xb6574 <strcmp@plt> */
/* @0x28affc cmp r0, #0 */
/* @0x28b000 bne 0x28afe0 <spSkeletonData_findBone+0x24> */
/* @0x28b004 mov r0, r5 */
/* @0x28b008 pop {r4, r5, r6, r7, r8, pc} */
/* @0x28b00c mov r5, #0 */
/* @0x28b010 mov r0, r5 */
/* @0x28b014 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x28b018 · spSkeletonData_findBoneIndex · size=88 · insn=22 */
/* @0x28b018 push {r3, r4, r5, r6, r7, lr} */
/* @0x28b01c mov r7, r1 */
/* @0x28b020 ldr r6, [r0, #0x10] */
/* @0x28b024 cmp r6, #0 */
/* @0x28b028 ble 0x28b068 <spSkeletonData_findBoneIndex+0x50> */
/* @0x28b02c ldr r5, [r0, #0x14] */
/* @0x28b030 mov r4, #0 */
/* @0x28b034 sub r5, r5, #4 */
/* @0x28b038 b 0x28b048 <spSkeletonData_findBoneIndex+0x30> */
/* @0x28b03c add r4, r4, #1 */
/* @0x28b040 cmp r4, r6 */
/* @0x28b044 beq 0x28b068 <spSkeletonData_findBoneIndex+0x50> */
/* @0x28b048 ldr r3, [r5, #0x4]! */
/* @0x28b04c mov r1, r7 */
/* @0x28b050 ldr r0, [r3, #0x4] */
/* @0x28b054 bl 0xb6574 <strcmp@plt> */
/* @0x28b058 cmp r0, #0 */
/* @0x28b05c bne 0x28b03c <spSkeletonData_findBoneIndex+0x24> */
/* @0x28b060 mov r0, r4 */
/* @0x28b064 pop {r3, r4, r5, r6, r7, pc} */
/* @0x28b068 mvn r0, #0 */
/* @0x28b06c pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x28b070 · spSkeletonData_findSlot · size=92 · insn=23 */
/* @0x28b070 push {r4, r5, r6, r7, r8, lr} */
/* @0x28b074 mov r8, r1 */
/* @0x28b078 ldr r7, [r0, #0x18] */
/* @0x28b07c cmp r7, #0 */
/* @0x28b080 ble 0x28b0c0 <spSkeletonData_findSlot+0x50> */
/* @0x28b084 ldr r6, [r0, #0x1c] */
/* @0x28b088 mov r4, #0 */
/* @0x28b08c sub r6, r6, #4 */
/* @0x28b090 b 0x28b09c <spSkeletonData_findSlot+0x2c> */
/* @0x28b094 cmp r4, r7 */
/* @0x28b098 beq 0x28b0c0 <spSkeletonData_findSlot+0x50> */
/* @0x28b09c ldr r5, [r6, #0x4]! */
/* @0x28b0a0 mov r1, r8 */
/* @0x28b0a4 add r4, r4, #1 */
/* @0x28b0a8 ldr r0, [r5, #0x4] */
/* @0x28b0ac bl 0xb6574 <strcmp@plt> */
/* @0x28b0b0 cmp r0, #0 */
/* @0x28b0b4 bne 0x28b094 <spSkeletonData_findSlot+0x24> */
/* @0x28b0b8 mov r0, r5 */
/* @0x28b0bc pop {r4, r5, r6, r7, r8, pc} */
/* @0x28b0c0 mov r5, #0 */
/* @0x28b0c4 mov r0, r5 */
/* @0x28b0c8 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x28b0cc · spSkeletonData_findSlotIndex · size=88 · insn=22 */
/* @0x28b0cc push {r3, r4, r5, r6, r7, lr} */
/* @0x28b0d0 mov r7, r1 */
/* @0x28b0d4 ldr r6, [r0, #0x18] */
/* @0x28b0d8 cmp r6, #0 */
/* @0x28b0dc ble 0x28b11c <spSkeletonData_findSlotIndex+0x50> */
/* @0x28b0e0 ldr r5, [r0, #0x1c] */
/* @0x28b0e4 mov r4, #0 */
/* @0x28b0e8 sub r5, r5, #4 */
/* @0x28b0ec b 0x28b0fc <spSkeletonData_findSlotIndex+0x30> */
/* @0x28b0f0 add r4, r4, #1 */
/* @0x28b0f4 cmp r4, r6 */
/* @0x28b0f8 beq 0x28b11c <spSkeletonData_findSlotIndex+0x50> */
/* @0x28b0fc ldr r3, [r5, #0x4]! */
/* @0x28b100 mov r1, r7 */
/* @0x28b104 ldr r0, [r3, #0x4] */
/* @0x28b108 bl 0xb6574 <strcmp@plt> */
/* @0x28b10c cmp r0, #0 */
/* @0x28b110 bne 0x28b0f0 <spSkeletonData_findSlotIndex+0x24> */
/* @0x28b114 mov r0, r4 */
/* @0x28b118 pop {r3, r4, r5, r6, r7, pc} */
/* @0x28b11c mvn r0, #0 */
/* @0x28b120 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x28b124 · spSkeletonData_findSkin · size=92 · insn=23 */
/* @0x28b124 push {r4, r5, r6, r7, r8, lr} */
/* @0x28b128 mov r8, r1 */
/* @0x28b12c ldr r7, [r0, #0x20] */
/* @0x28b130 cmp r7, #0 */
/* @0x28b134 ble 0x28b174 <spSkeletonData_findSkin+0x50> */
/* @0x28b138 ldr r6, [r0, #0x24] */
/* @0x28b13c mov r4, #0 */
/* @0x28b140 sub r6, r6, #4 */
/* @0x28b144 b 0x28b150 <spSkeletonData_findSkin+0x2c> */
/* @0x28b148 cmp r4, r7 */
/* @0x28b14c beq 0x28b174 <spSkeletonData_findSkin+0x50> */
/* @0x28b150 ldr r5, [r6, #0x4]! */
/* @0x28b154 mov r1, r8 */
/* @0x28b158 add r4, r4, #1 */
/* @0x28b15c ldr r0, [r5] */
/* @0x28b160 bl 0xb6574 <strcmp@plt> */
/* @0x28b164 cmp r0, #0 */
/* @0x28b168 bne 0x28b148 <spSkeletonData_findSkin+0x24> */
/* @0x28b16c mov r0, r5 */
/* @0x28b170 pop {r4, r5, r6, r7, r8, pc} */
/* @0x28b174 mov r5, #0 */
/* @0x28b178 mov r0, r5 */
/* @0x28b17c pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x28b180 · spSkeletonData_findEvent · size=92 · insn=23 */
/* @0x28b180 push {r4, r5, r6, r7, r8, lr} */
/* @0x28b184 mov r8, r1 */
/* @0x28b188 ldr r7, [r0, #0x2c] */
/* @0x28b18c cmp r7, #0 */
/* @0x28b190 ble 0x28b1d0 <spSkeletonData_findEvent+0x50> */
/* @0x28b194 ldr r6, [r0, #0x30] */
/* @0x28b198 mov r4, #0 */
/* @0x28b19c sub r6, r6, #4 */
/* @0x28b1a0 b 0x28b1ac <spSkeletonData_findEvent+0x2c> */
/* @0x28b1a4 cmp r4, r7 */
/* @0x28b1a8 beq 0x28b1d0 <spSkeletonData_findEvent+0x50> */
/* @0x28b1ac ldr r5, [r6, #0x4]! */
/* @0x28b1b0 mov r1, r8 */
/* @0x28b1b4 add r4, r4, #1 */
/* @0x28b1b8 ldr r0, [r5] */
/* @0x28b1bc bl 0xb6574 <strcmp@plt> */
/* @0x28b1c0 cmp r0, #0 */
/* @0x28b1c4 bne 0x28b1a4 <spSkeletonData_findEvent+0x24> */
/* @0x28b1c8 mov r0, r5 */
/* @0x28b1cc pop {r4, r5, r6, r7, r8, pc} */
/* @0x28b1d0 mov r5, #0 */
/* @0x28b1d4 mov r0, r5 */
/* @0x28b1d8 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x28b1dc · spSkeletonData_findAnimation · size=92 · insn=23 */
/* @0x28b1dc push {r4, r5, r6, r7, r8, lr} */
/* @0x28b1e0 mov r8, r1 */
/* @0x28b1e4 ldr r7, [r0, #0x34] */
/* @0x28b1e8 cmp r7, #0 */
/* @0x28b1ec ble 0x28b22c <spSkeletonData_findAnimation+0x50> */
/* @0x28b1f0 ldr r6, [r0, #0x38] */
/* @0x28b1f4 mov r4, #0 */
/* @0x28b1f8 sub r6, r6, #4 */
/* @0x28b1fc b 0x28b208 <spSkeletonData_findAnimation+0x2c> */
/* @0x28b200 cmp r4, r7 */
/* @0x28b204 beq 0x28b22c <spSkeletonData_findAnimation+0x50> */
/* @0x28b208 ldr r5, [r6, #0x4]! */
/* @0x28b20c mov r1, r8 */
/* @0x28b210 add r4, r4, #1 */
/* @0x28b214 ldr r0, [r5] */
/* @0x28b218 bl 0xb6574 <strcmp@plt> */
/* @0x28b21c cmp r0, #0 */
/* @0x28b220 bne 0x28b200 <spSkeletonData_findAnimation+0x24> */
/* @0x28b224 mov r0, r5 */
/* @0x28b228 pop {r4, r5, r6, r7, r8, pc} */
/* @0x28b22c mov r5, #0 */
/* @0x28b230 mov r0, r5 */
/* @0x28b234 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x28b238 · spSkeletonData_findIkConstraint · size=92 · insn=23 */
/* @0x28b238 push {r4, r5, r6, r7, r8, lr} */
/* @0x28b23c mov r8, r1 */
/* @0x28b240 ldr r7, [r0, #0x3c] */
/* @0x28b244 cmp r7, #0 */
/* @0x28b248 ble 0x28b288 <spSkeletonData_findIkConstraint+0x50> */
/* @0x28b24c ldr r6, [r0, #0x40] */
/* @0x28b250 mov r4, #0 */
/* @0x28b254 sub r6, r6, #4 */
/* @0x28b258 b 0x28b264 <spSkeletonData_findIkConstraint+0x2c> */
/* @0x28b25c cmp r4, r7 */
/* @0x28b260 beq 0x28b288 <spSkeletonData_findIkConstraint+0x50> */
/* @0x28b264 ldr r5, [r6, #0x4]! */
/* @0x28b268 mov r1, r8 */
/* @0x28b26c add r4, r4, #1 */
/* @0x28b270 ldr r0, [r5] */
/* @0x28b274 bl 0xb6574 <strcmp@plt> */
/* @0x28b278 cmp r0, #0 */
/* @0x28b27c bne 0x28b25c <spSkeletonData_findIkConstraint+0x24> */
/* @0x28b280 mov r0, r5 */
/* @0x28b284 pop {r4, r5, r6, r7, r8, pc} */
/* @0x28b288 mov r5, #0 */
/* @0x28b28c mov r0, r5 */
/* @0x28b290 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x28b294 · spSkeletonData_findTransformConstraint · size=92 · insn=23 */
/* @0x28b294 push {r4, r5, r6, r7, r8, lr} */
/* @0x28b298 mov r8, r1 */
/* @0x28b29c ldr r7, [r0, #0x44] */
/* @0x28b2a0 cmp r7, #0 */
/* @0x28b2a4 ble 0x28b2e4 <spSkeletonData_findTransformConstraint+0x50> */
/* @0x28b2a8 ldr r6, [r0, #0x48] */
/* @0x28b2ac mov r4, #0 */
/* @0x28b2b0 sub r6, r6, #4 */
/* @0x28b2b4 b 0x28b2c0 <spSkeletonData_findTransformConstraint+0x2c> */
/* @0x28b2b8 cmp r4, r7 */
/* @0x28b2bc beq 0x28b2e4 <spSkeletonData_findTransformConstraint+0x50> */
/* @0x28b2c0 ldr r5, [r6, #0x4]! */
/* @0x28b2c4 mov r1, r8 */
/* @0x28b2c8 add r4, r4, #1 */
/* @0x28b2cc ldr r0, [r5] */
/* @0x28b2d0 bl 0xb6574 <strcmp@plt> */
/* @0x28b2d4 cmp r0, #0 */
/* @0x28b2d8 bne 0x28b2b8 <spSkeletonData_findTransformConstraint+0x24> */
/* @0x28b2dc mov r0, r5 */
/* @0x28b2e0 pop {r4, r5, r6, r7, r8, pc} */
/* @0x28b2e4 mov r5, #0 */
/* @0x28b2e8 mov r0, r5 */
/* @0x28b2ec pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x28b2f0 · spSkeletonData_findPathConstraint · size=92 · insn=23 */
/* @0x28b2f0 push {r4, r5, r6, r7, r8, lr} */
/* @0x28b2f4 mov r8, r1 */
/* @0x28b2f8 ldr r7, [r0, #0x4c] */
/* @0x28b2fc cmp r7, #0 */
/* @0x28b300 ble 0x28b340 <spSkeletonData_findPathConstraint+0x50> */
/* @0x28b304 ldr r6, [r0, #0x50] */
/* @0x28b308 mov r4, #0 */
/* @0x28b30c sub r6, r6, #4 */
/* @0x28b310 b 0x28b31c <spSkeletonData_findPathConstraint+0x2c> */
/* @0x28b314 cmp r4, r7 */
/* @0x28b318 beq 0x28b340 <spSkeletonData_findPathConstraint+0x50> */
/* @0x28b31c ldr r5, [r6, #0x4]! */
/* @0x28b320 mov r1, r8 */
/* @0x28b324 add r4, r4, #1 */
/* @0x28b328 ldr r0, [r5] */
/* @0x28b32c bl 0xb6574 <strcmp@plt> */
/* @0x28b330 cmp r0, #0 */
/* @0x28b334 bne 0x28b314 <spSkeletonData_findPathConstraint+0x24> */
/* @0x28b338 mov r0, r5 */
/* @0x28b33c pop {r4, r5, r6, r7, r8, pc} */
/* @0x28b340 mov r5, #0 */
/* @0x28b344 mov r0, r5 */
/* @0x28b348 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x28b34c · anon_28b34c · size=944 · insn=237 */
/* @0x28b34c push {r4, r5, lr} */
/* @0x28b350 mov r5, r1 */
/* @0x28b354 ldr r1, [pc, #0x98] */
/* @0x28b358 sub sp, sp, #12 */
/* @0x28b35c mov r4, r2 */
/* @0x28b360 add r1, pc, r1 */
/* @0x28b364 bl 0x2873c4 <Json_getItem> */
/* @0x28b368 cmp r0, #0 */
/* @0x28b36c beq 0x28b384 <spSkeletonData_findPathConstraint+0x94> */
/* @0x28b370 ldr r3, [r0, #0x8] */
/* @0x28b374 cmp r3, #4 */
/* @0x28b378 beq 0x28b38c <spSkeletonData_findPathConstraint+0x9c> */
/* @0x28b37c cmp r3, #5 */
/* @0x28b380 beq 0x28b3b8 <spSkeletonData_findPathConstraint+0xc8> */
/* @0x28b384 add sp, sp, #12 */
/* @0x28b388 pop {r4, r5, pc} */
/* @0x28b38c ldr r1, [pc, #0x64] */
/* @0x28b390 ldr r0, [r0, #0x10] */
/* @0x28b394 add r1, pc, r1 */
/* @0x28b398 bl 0xb6574 <strcmp@plt> */
/* @0x28b39c cmp r0, #0 */
/* @0x28b3a0 bne 0x28b384 <spSkeletonData_findPathConstraint+0x94> */
/* @0x28b3a4 mov r0, r5 */
/* @0x28b3a8 mov r1, r4 */
/* @0x28b3ac add sp, sp, #12 */
/* @0x28b3b0 pop {r4, r5, lr} */
/* @0x28b3b4 b 0x2817c0 <spCurveTimeline_setStepped> */
/* @0x28b3b8 ldr r3, [r0, #0x4] */
/* @0x28b3bc mov r1, r4 */
/* @0x28b3c0 mov r0, r5 */
/* @0x28b3c4 ldr r12, [r3] */
/* @0x28b3c8 ldr r2, [r3, #0x18] */
/* @0x28b3cc ldr r3, [r12, #0x18] */
/* @0x28b3d0 ldr r12, [r12] */
/* @0x28b3d4 ldr lr, [r12, #0x18] */
/* @0x28b3d8 str lr, [sp] */
/* @0x28b3dc ldr r12, [r12] */
/* @0x28b3e0 ldr r12, [r12, #0x18] */
/* @0x28b3e4 str r12, [sp, #0x4] */
/* @0x28b3e8 bl 0x2817d8 <spCurveTimeline_setCurve> */
/* @0x28b3ec add sp, sp, #12 */
/* @0x28b3f0 pop {r4, r5, pc} */
/* @0x28b3f4 andeq r12, r12, r4, lsl #15 */
/* @0x28b3f8 andeq r12, r12, r8, asr r7 */
/* @0x28b3fc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x28b400 mov r5, r0 */
/* @0x28b404 mov r0, r1 */
/* @0x28b408 ldr r1, [pc, #0x260] */
/* @0x28b40c mov r9, r2 */
/* @0x28b410 sub sp, sp, #12 */
/* @0x28b414 str r3, [r9, #0x20] */
/* @0x28b418 add r1, pc, r1 */
/* @0x28b41c mov r4, r3 */
/* @0x28b420 bl 0x2873c4 <Json_getItem> */
/* @0x28b424 ldr r1, [pc, #0x248] */
/* @0x28b428 movw r2, #0x201 */
/* @0x28b42c add r1, pc, r1 */
/* @0x28b430 ldr r8, [r0, #0xc] */
/* @0x28b434 mov r6, r0 */
/* @0x28b438 lsl r0, r8, #2 */
/* @0x28b43c bl 0x285c10 <_malloc> */
/* @0x28b440 ldr r2, [r6, #0x4] */
/* @0x28b444 cmp r2, #0 */
/* @0x28b448 mov r10, r0 */
/* @0x28b44c movne r1, r0 */
/* @0x28b450 beq 0x28b468 <spSkeletonData_findPathConstraint+0x178> */
/* @0x28b454 ldr r3, [r2, #0x18] */
/* @0x28b458 ldr r2, [r2] */
/* @0x28b45c cmp r2, #0 */
/* @0x28b460 str r3, [r1], #4 */
/* @0x28b464 bne 0x28b454 <spSkeletonData_findPathConstraint+0x164> */
/* @0x28b468 cmp r4, r8 */
/* @0x28b46c beq 0x28b5e0 <spSkeletonData_findPathConstraint+0x2f0> */
/* @0x28b470 cmp r8, #0 */
/* @0x28b474 mov r0, #0 */
/* @0x28b478 str r0, [r9, #0x18] */
/* @0x28b47c str r0, [r9, #0x10] */
/* @0x28b480 ble 0x28b63c <spSkeletonData_findPathConstraint+0x34c> */
/* @0x28b484 mov r12, r0 */
/* @0x28b488 mov lr, r0 */
/* @0x28b48c mov r2, r0 */
/* @0x28b490 add r3, r10, r2, lsl #2 */
/* @0x28b494 vldr s15, [r3] */
/* @0x28b498 vcvt.s32.f32 s15, s15 */
/* @0x28b49c vmov r3, s15 */
/* @0x28b4a0 add r2, r2, r3, lsl #2 */
/* @0x28b4a4 add r1, r3, #1 */
/* @0x28b4a8 add r2, r2, #1 */
/* @0x28b4ac add r3, r3, r3, lsl #1 */
/* @0x28b4b0 cmp r8, r2 */
/* @0x28b4b4 add lr, lr, r1 */
/* @0x28b4b8 add r12, r12, r3 */
/* @0x28b4bc bgt 0x28b490 <spSkeletonData_findPathConstraint+0x1a0> */
/* @0x28b4c0 ldr r4, [pc, #0x1b0] */
/* @0x28b4c4 lsl r0, r12, #2 */
/* @0x28b4c8 str lr, [r9, #0x10] */
/* @0x28b4cc movw r2, #0x219 */
/* @0x28b4d0 add r4, pc, r4 */
/* @0x28b4d4 str r12, [r9, #0x18] */
/* @0x28b4d8 mov r1, r4 */
/* @0x28b4dc bl 0x285c10 <_malloc> */
/* @0x28b4e0 ldr r3, [r9, #0x10] */
/* @0x28b4e4 movw r2, #0x21a */
/* @0x28b4e8 mov r1, r4 */
/* @0x28b4ec str r0, [r9, #0x1c] */
/* @0x28b4f0 lsl r0, r3, #2 */
/* @0x28b4f4 bl 0x285c10 <_malloc> */
/* @0x28b4f8 mov r2, #0 */
/* @0x28b4fc mov r3, r2 */
/* @0x28b500 mov r7, r2 */
/* @0x28b504 str r8, [sp, #0x4] */
/* @0x28b508 str r0, [r9, #0x14] */
/* @0x28b50c add r1, r10, r7, lsl #2 */
/* @0x28b510 vldr s15, [r1] */
/* @0x28b514 vcvt.s32.f32 s15, s15 */
/* @0x28b518 add r12, r7, #1 */
/* @0x28b51c add r11, r3, #1 */
/* @0x28b520 add r4, r0, r3, lsl #2 */
/* @0x28b524 vmov r8, s15 */
/* @0x28b528 add r6, r12, r8, lsl #2 */
/* @0x28b52c str r8, [r0, r3, lsl #2] */
/* @0x28b530 cmp r12, r6 */
/* @0x28b534 bge 0x28b5d4 <spSkeletonData_findPathConstraint+0x2e4> */
/* @0x28b538 ldr r3, [r9, #0x1c] */
/* @0x28b53c add r3, r3, r2, lsl #2 */
/* @0x28b540 vldr s14, [r1, #8] */
/* @0x28b544 vldr s15, [r5] */
/* @0x28b548 vmul.f32 s15, s14, s15 */
/* @0x28b54c vldr s14, [r1, #4] */
/* @0x28b550 add r12, r12, #4 */
/* @0x28b554 add r3, r3, #12 */
/* @0x28b558 cmp r6, r12 */
/* @0x28b55c vcvt.s32.f32 s14, s14 */
/* @0x28b560 vmov r8, s14 */
/* @0x28b564 str r8, [r4, #0x4]! */
/* @0x28b568 vstr s15, [r3, #-12] */
/* @0x28b56c vldr s14, [r1, #12] */
/* @0x28b570 vldr s15, [r5] */
/* @0x28b574 vmul.f32 s15, s14, s15 */
/* @0x28b578 vstr s15, [r3, #-8] */
/* @0x28b57c ldr r8, [r1, #0x10]! */
/* @0x28b580 str r8, [r3, #-0x4] */
/* @0x28b584 bgt 0x28b540 <spSkeletonData_findPathConstraint+0x250> */
/* @0x28b588 movw r1, #0xfffe */
/* @0x28b58c movt r1, #0xffff */
/* @0x28b590 rsb r1, r7, r1 */
/* @0x28b594 add r11, r11, #1 */
/* @0x28b598 add r6, r1, r6 */
/* @0x28b59c add r2, r2, #3 */
/* @0x28b5a0 add r7, r7, #5 */
/* @0x28b5a4 lsr r6, r6, #2 */
/* @0x28b5a8 add r3, r11, r6 */
/* @0x28b5ac add r1, r6, r6, lsl #1 */
/* @0x28b5b0 add r7, r7, r6, lsl #2 */
/* @0x28b5b4 add r2, r2, r1 */
/* @0x28b5b8 ldr r1, [sp, #0x4] */
/* @0x28b5bc cmp r1, r7 */
/* @0x28b5c0 bgt 0x28b50c <spSkeletonData_findPathConstraint+0x21c> */
/* @0x28b5c4 mov r0, r10 */
/* @0x28b5c8 add sp, sp, #12 */
/* @0x28b5cc pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x28b5d0 b 0x285c80 <_free> */
/* @0x28b5d4 mov r7, r12 */
/* @0x28b5d8 mov r3, r11 */
/* @0x28b5dc b 0x28b5b8 <spSkeletonData_findPathConstraint+0x2c8> */
/* @0x28b5e0 vmov.f32 s14, #1.000000e+00 */
/* @0x28b5e4 vldr s15, [r5] */
/* @0x28b5e8 vcmp.f32 s15, s14 */
/* @0x28b5ec vmrs APSR_nzcv, fpscr */
/* @0x28b5f0 beq 0x28b620 <spSkeletonData_findPathConstraint+0x330> */
/* @0x28b5f4 cmp r4, #0 */
/* @0x28b5f8 ble 0x28b620 <spSkeletonData_findPathConstraint+0x330> */
/* @0x28b5fc add r3, r10, r4, lsl #2 */
/* @0x28b600 mov r2, r10 */
/* @0x28b604 b 0x28b60c <spSkeletonData_findPathConstraint+0x31c> */
/* @0x28b608 vldr s15, [r5] */
/* @0x28b60c vldr s14, [r2] */
/* @0x28b610 vmul.f32 s15, s14, s15 */
/* @0x28b614 vstmia r2!, {s15} */
/* @0x28b618 cmp r2, r3 */
/* @0x28b61c bne 0x28b608 <spSkeletonData_findPathConstraint+0x318> */
/* @0x28b620 mov r3, #0 */
/* @0x28b624 str r4, [r9, #0x18] */
/* @0x28b628 str r10, [r9, #0x1c] */
/* @0x28b62c str r3, [r9, #0x10] */
/* @0x28b630 str r3, [r9, #0x14] */
/* @0x28b634 add sp, sp, #12 */
/* @0x28b638 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x28b63c ldr r4, [pc, #0x38] */
/* @0x28b640 movw r2, #0x219 */
/* @0x28b644 add r4, pc, r4 */
/* @0x28b648 mov r1, r4 */
/* @0x28b64c bl 0x285c10 <_malloc> */
/* @0x28b650 ldr r3, [r9, #0x10] */
/* @0x28b654 mov r1, r4 */
/* @0x28b658 movw r2, #0x21a */
/* @0x28b65c str r0, [r9, #0x1c] */
/* @0x28b660 lsl r0, r3, #2 */
/* @0x28b664 bl 0x285c10 <_malloc> */
/* @0x28b668 str r0, [r9, #0x14] */
/* @0x28b66c b 0x28b5c4 <spSkeletonData_findPathConstraint+0x2d4> */
/* @0x28b670 ldrdeq r12, sp, [r12], -r12 */
/* @0x28b674 ldrdeq r12, sp, [r12], -r4 */
/* @0x28b678 andeq r12, r12, r0, lsr r6 */
/* @0x28b67c strheq r12, [r12], -r12 */
/* @0x28b680 push {r4, r5, lr} */
/* @0x28b684 sub sp, sp, #12 */
/* @0x28b688 mov r5, r1 */
/* @0x28b68c mov r4, r0 */
/* @0x28b690 bl 0xb6538 <strlen@plt> */
/* @0x28b694 cmp r0, #8 */
/* @0x28b698 beq 0x28b6a8 <spSkeletonData_findPathConstraint+0x3b8> */
/* @0x28b69c vmov.f32 s0, #-1.000000e+00 */
/* @0x28b6a0 add sp, sp, #12 */
/* @0x28b6a4 pop {r4, r5, pc} */
/* @0x28b6a8 add r3, r4, r5, lsl #1 */
/* @0x28b6ac ldrb r12, [r4, r5, lsl #1] */
/* @0x28b6b0 mov r0, sp */
/* @0x28b6b4 add r1, sp, #4 */
/* @0x28b6b8 ldrb r3, [r3, #0x1] */
/* @0x28b6bc mov r2, #16 */
/* @0x28b6c0 strb r12, [sp] */
/* @0x28b6c4 mov r12, #0 */
/* @0x28b6c8 strb r12, [sp, #0x2] */
/* @0x28b6cc strb r3, [sp, #0x1] */
/* @0x28b6d0 bl 0xb697c <strtoul@plt> */
/* @0x28b6d4 ldr r3, [sp, #0x4] */
/* @0x28b6d8 ldrb r3, [r3] */
/* @0x28b6dc cmp r3, #0 */
/* @0x28b6e0 bne 0x28b69c <spSkeletonData_findPathConstraint+0x3ac> */
/* @0x28b6e4 vmov s15, r0 */
/* @0x28b6e8 vcvt.f32.s32 s0, s15 */
/* @0x28b6ec vldr s15, [pc, #8] */
/* @0x28b6f0 vdiv.f32 s0, s0, s15 */
/* @0x28b6f4 add sp, sp, #12 */
/* @0x28b6f8 pop {r4, r5, pc} */
/* @0x28b6fc cmnmi pc, #0 */

/* ── FUNC 0x28b700 · spSkeletonJson_createWithLoader · size=52 · insn=13 */
/* @0x28b700 ldr r2, [pc, #0x28] */
/* @0x28b704 mov r1, #28 */
/* @0x28b708 push {r4, lr} */
/* @0x28b70c add r2, pc, r2 */
/* @0x28b710 mov r4, r0 */
/* @0x28b714 mov r3, #62 */
/* @0x28b718 mov r0, #1 */
/* @0x28b71c bl 0x285c4c <_calloc> */
/* @0x28b720 mov r2, #1065353216 */
/* @0x28b724 str r4, [r0, #0x4] */
/* @0x28b728 str r2, [r0] */
/* @0x28b72c pop {r4, pc} */
/* @0x28b730 strdeq r12, sp, [r12], -r4 */

/* ── FUNC 0x28b734 · spSkeletonJson_create · size=24 · insn=6 */
/* @0x28b734 push {r3, lr} */
/* @0x28b738 bl 0x284bb4 <spAtlasAttachmentLoader_create> */
/* @0x28b73c bl 0x28b700 <spSkeletonJson_createWithLoader> */
/* @0x28b740 mov r3, #1 */
/* @0x28b744 str r3, [r0, #0xc] */
/* @0x28b748 pop {r3, pc} */

/* ── FUNC 0x28b74c · spSkeletonJson_dispose · size=56 · insn=14 */
/* @0x28b74c ldr r3, [r0, #0xc] */
/* @0x28b750 push {r4, lr} */
/* @0x28b754 cmp r3, #0 */
/* @0x28b758 mov r4, r0 */
/* @0x28b75c beq 0x28b768 <spSkeletonJson_dispose+0x1c> */
/* @0x28b760 ldr r0, [r0, #0x4] */
/* @0x28b764 bl 0x284d38 <spAttachmentLoader_dispose> */
/* @0x28b768 ldr r0, [r4, #0x18] */
/* @0x28b76c bl 0x285c80 <_free> */
/* @0x28b770 ldr r0, [r4, #0x8] */
/* @0x28b774 bl 0x285c80 <_free> */
/* @0x28b778 mov r0, r4 */
/* @0x28b77c pop {r4, lr} */
/* @0x28b780 b 0x285c80 <_free> */

/* ── FUNC 0x28b784 · _spSkeletonJson_setError · size=200 · insn=50 */
/* @0x28b784 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x28b788 mov r9, r3 */
/* @0x28b78c ldr r5, [pc, #0xb0] */
/* @0x28b790 sub sp, sp, #268 */
/* @0x28b794 add r4, sp, #4 */
/* @0x28b798 mov r7, r2 */
/* @0x28b79c ldr r5, [pc, r5] */
/* @0x28b7a0 mov r6, r0 */
/* @0x28b7a4 ldr r0, [r0, #0x8] */
/* @0x28b7a8 mov r8, r1 */
/* @0x28b7ac ldr r3, [r5] */
/* @0x28b7b0 str r3, [sp, #0x104] */
/* @0x28b7b4 bl 0x285c80 <_free> */
/* @0x28b7b8 mov r1, r7 */
/* @0x28b7bc mov r0, r4 */
/* @0x28b7c0 bl 0xb65a4 <strcpy@plt> */
/* @0x28b7c4 mov r0, r7 */
/* @0x28b7c8 bl 0xb6538 <strlen@plt> */
/* @0x28b7cc cmp r9, #0 */
/* @0x28b7d0 mov r2, r0 */
/* @0x28b7d4 beq 0x28b7e8 <_spSkeletonJson_setError+0x64> */
/* @0x28b7d8 mov r1, r9 */
/* @0x28b7dc add r0, r4, r0 */
/* @0x28b7e0 rsb r2, r2, #255 */
/* @0x28b7e4 bl 0xb6c1c <strncat@plt> */
/* @0x28b7e8 mov r0, r4 */
/* @0x28b7ec bl 0xb6538 <strlen@plt> */
/* @0x28b7f0 ldr r1, [pc, #0x50] */
/* @0x28b7f4 mov r2, #90 */
/* @0x28b7f8 add r1, pc, r1 */
/* @0x28b7fc add r0, r0, #1 */
/* @0x28b800 bl 0x285c10 <_malloc> */
/* @0x28b804 mov r1, r4 */
/* @0x28b808 str r0, [r6, #0x8] */
/* @0x28b80c bl 0xb65a4 <strcpy@plt> */
/* @0x28b810 mov r0, r4 */
/* @0x28b814 bl 0xc4404 <ReportSpineError> */
/* @0x28b818 cmp r8, #0 */
/* @0x28b81c beq 0x28b828 <_spSkeletonJson_setError+0xa4> */
/* @0x28b820 mov r0, r8 */
/* @0x28b824 bl 0x2872c8 <Json_dispose> */
/* @0x28b828 ldr r2, [sp, #0x104] */
/* @0x28b82c ldr r3, [r5] */
/* @0x28b830 cmp r2, r3 */
/* @0x28b834 bne 0x28b840 <_spSkeletonJson_setError+0xbc> */
/* @0x28b838 add sp, sp, #268 */
/* @0x28b83c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x28b840 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x28b844 ldrheq r2, [r6], -r4 */
/* @0x28b848 andeq r12, r12, r8, lsl #6 */

/* ── FUNC 0x28b84c · spSkeletonJson_readSkeletonData · size=13044 · insn=3261 */
/* @0x28b84c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x28b850 vpush {d8} */
/* @0x28b854 mov r8, r0 */
/* @0x28b858 sub sp, sp, #124 */
/* @0x28b85c ldr r0, [r0, #0x8] */
/* @0x28b860 mov r5, r1 */
/* @0x28b864 bl 0x285c80 <_free> */
/* @0x28b868 mov r3, #0 */
/* @0x28b86c mov r0, #1 */
/* @0x28b870 mov r1, r3 */
/* @0x28b874 str r3, [r8, #0x8] */
/* @0x28b878 str r3, [r8, #0x10] */
/* @0x28b87c bl 0xb679c <setlocale@plt> */
/* @0x28b880 subs r4, r0, #0 */
/* @0x28b884 beq 0x28bf58 <spSkeletonJson_readSkeletonData+0x70c> */
/* @0x28b888 bl 0xb6640 <strdup@plt> */
/* @0x28b88c ldr r1, [pc, #0xf50] */
/* @0x28b890 add r1, pc, r1 */
/* @0x28b894 mov r4, r0 */
/* @0x28b898 mov r0, #1 */
/* @0x28b89c bl 0xb679c <setlocale@plt> */
/* @0x28b8a0 mov r0, r5 */
/* @0x28b8a4 bl 0x287320 <Json_create> */
/* @0x28b8a8 mov r1, r4 */
/* @0x28b8ac str r0, [sp, #0x24] */
/* @0x28b8b0 mov r0, #1 */
/* @0x28b8b4 bl 0xb679c <setlocale@plt> */
/* @0x28b8b8 cmp r4, #0 */
/* @0x28b8bc beq 0x28b8c8 <spSkeletonJson_readSkeletonData+0x7c> */
/* @0x28b8c0 mov r0, r4 */
/* @0x28b8c4 bl 0xb655c <free@plt> */
/* @0x28b8c8 ldr r0, [sp, #0x24] */
/* @0x28b8cc cmp r0, #0 */
/* @0x28b8d0 beq 0x28c3b4 <spSkeletonJson_readSkeletonData+0xb68> */
/* @0x28b8d4 bl 0x28addc <spSkeletonData_create> */
/* @0x28b8d8 ldr r1, [pc, #0xf08] */
/* @0x28b8dc add r1, pc, r1 */
/* @0x28b8e0 mov r9, r0 */
/* @0x28b8e4 ldr r0, [sp, #0x24] */
/* @0x28b8e8 bl 0x2873c4 <Json_getItem> */
/* @0x28b8ec subs r4, r0, #0 */
/* @0x28b8f0 beq 0x28b9cc <spSkeletonJson_readSkeletonData+0x180> */
/* @0x28b8f4 ldr r3, [pc, #0xef0] */
/* @0x28b8f8 mov r2, #0 */
/* @0x28b8fc ldr r5, [pc, #0xeec] */
/* @0x28b900 add r3, pc, r3 */
/* @0x28b904 ldr r6, [pc, #0xee8] */
/* @0x28b908 add r5, pc, r5 */
/* @0x28b90c mov r1, r3 */
/* @0x28b910 mov r10, r3 */
/* @0x28b914 bl 0x287428 <Json_getString> */
/* @0x28b918 add r6, pc, r6 */
/* @0x28b91c bl 0xb6538 <strlen@plt> */
/* @0x28b920 mov r1, r5 */
/* @0x28b924 movw r2, #0x25f */
/* @0x28b928 add r0, r0, #1 */
/* @0x28b92c bl 0x285c10 <_malloc> */
/* @0x28b930 mov r2, #0 */
/* @0x28b934 mov r1, r10 */
/* @0x28b938 mov r7, r0 */
/* @0x28b93c str r0, [r9, #0x4] */
/* @0x28b940 mov r0, r4 */
/* @0x28b944 bl 0x287428 <Json_getString> */
/* @0x28b948 mov r1, r0 */
/* @0x28b94c mov r0, r7 */
/* @0x28b950 bl 0xb65a4 <strcpy@plt> */
/* @0x28b954 mov r1, r6 */
/* @0x28b958 mov r2, #0 */
/* @0x28b95c mov r0, r4 */
/* @0x28b960 bl 0x287428 <Json_getString> */
/* @0x28b964 bl 0xb6538 <strlen@plt> */
/* @0x28b968 mov r1, r5 */
/* @0x28b96c mov r2, #608 */
/* @0x28b970 add r0, r0, #1 */
/* @0x28b974 bl 0x285c10 <_malloc> */
/* @0x28b978 mov r2, #0 */
/* @0x28b97c mov r1, r6 */
/* @0x28b980 mov r5, r0 */
/* @0x28b984 str r0, [r9] */
/* @0x28b988 mov r0, r4 */
/* @0x28b98c bl 0x287428 <Json_getString> */
/* @0x28b990 mov r1, r0 */
/* @0x28b994 mov r0, r5 */
/* @0x28b998 bl 0xb65a4 <strcpy@plt> */
/* @0x28b99c ldr r1, [pc, #0xe54] */
/* @0x28b9a0 mov r2, #0 */
/* @0x28b9a4 mov r0, r4 */
/* @0x28b9a8 add r1, pc, r1 */
/* @0x28b9ac bl 0x287444 <Json_getFloat> */
/* @0x28b9b0 ldr r1, [pc, #0xe44] */
/* @0x28b9b4 mov r2, #0 */
/* @0x28b9b8 add r1, pc, r1 */
/* @0x28b9bc str r0, [r9, #0x8] */
/* @0x28b9c0 mov r0, r4 */
/* @0x28b9c4 bl 0x287444 <Json_getFloat> */
/* @0x28b9c8 str r0, [r9, #0xc] */
/* @0x28b9cc ldr r1, [pc, #0xe2c] */
/* @0x28b9d0 ldr r0, [sp, #0x24] */
/* @0x28b9d4 add r1, pc, r1 */
/* @0x28b9d8 bl 0x2873c4 <Json_getItem> */
/* @0x28b9dc ldr r1, [pc, #0xe20] */
/* @0x28b9e0 movw r2, #0x267 */
/* @0x28b9e4 add r1, pc, r1 */
/* @0x28b9e8 mov r4, r0 */
/* @0x28b9ec ldr r0, [r0, #0xc] */
/* @0x28b9f0 lsl r0, r0, #2 */
/* @0x28b9f4 bl 0x285c10 <_malloc> */
/* @0x28b9f8 ldr r4, [r4, #0x4] */
/* @0x28b9fc cmp r4, #0 */
/* @0x28ba00 str r0, [r9, #0x14] */
/* @0x28ba04 beq 0x28bbcc <spSkeletonJson_readSkeletonData+0x380> */
/* @0x28ba08 ldr r3, [pc, #0xdf8] */
/* @0x28ba0c mov r6, #0 */
/* @0x28ba10 ldr r7, [pc, #0xdf4] */
/* @0x28ba14 add r3, pc, r3 */
/* @0x28ba18 str r3, [sp, #0x18] */
/* @0x28ba1c ldr r3, [pc, #0xdec] */
/* @0x28ba20 add r7, pc, r7 */
/* @0x28ba24 ldr r11, [pc, #0xde8] */
/* @0x28ba28 add r3, pc, r3 */
/* @0x28ba2c str r3, [sp, #0x1c] */
/* @0x28ba30 ldr r3, [pc, #0xde0] */
/* @0x28ba34 add r11, pc, r11 */
/* @0x28ba38 add r3, pc, r3 */
/* @0x28ba3c str r3, [sp, #0x20] */
/* @0x28ba40 b 0x28bba4 <spSkeletonJson_readSkeletonData+0x358> */
/* @0x28ba44 bl 0x28afbc <spSkeletonData_findBone> */
/* @0x28ba48 subs r5, r0, #0 */
/* @0x28ba4c beq 0x28bf28 <spSkeletonJson_readSkeletonData+0x6dc> */
/* @0x28ba50 mov r0, r4 */
/* @0x28ba54 mov r1, r11 */
/* @0x28ba58 mov r2, #0 */
/* @0x28ba5c ldr r10, [r9, #0x10] */
/* @0x28ba60 bl 0x287428 <Json_getString> */
/* @0x28ba64 mov r2, r5 */
/* @0x28ba68 mov r1, r0 */
/* @0x28ba6c mov r0, r10 */
/* @0x28ba70 bl 0x285a44 <spBoneData_create> */
/* @0x28ba74 ldr r1, [sp, #0x18] */
/* @0x28ba78 mov r2, #0 */
/* @0x28ba7c mov r5, r0 */
/* @0x28ba80 mov r0, r4 */
/* @0x28ba84 bl 0x287444 <Json_getFloat> */
/* @0x28ba88 vldr s15, [r8] */
/* @0x28ba8c ldr r1, [sp, #0x1c] */
/* @0x28ba90 mov r2, #0 */
/* @0x28ba94 vmov s14, r0 */
/* @0x28ba98 mov r0, r4 */
/* @0x28ba9c vmul.f32 s15, s14, s15 */
/* @0x28baa0 vstr s15, [r5, #12] */
/* @0x28baa4 bl 0x287444 <Json_getFloat> */
/* @0x28baa8 vldr s15, [r8] */
/* @0x28baac ldr r1, [sp, #0x20] */
/* @0x28bab0 mov r2, #0 */
/* @0x28bab4 vmov s14, r0 */
/* @0x28bab8 mov r0, r4 */
/* @0x28babc vmul.f32 s15, s14, s15 */
/* @0x28bac0 vstr s15, [r5, #16] */
/* @0x28bac4 bl 0x287444 <Json_getFloat> */
/* @0x28bac8 vldr s15, [r8] */
/* @0x28bacc ldr r1, [pc, #0xd48] */
/* @0x28bad0 mov r2, #0 */
/* @0x28bad4 add r1, pc, r1 */
/* @0x28bad8 vmov s14, r0 */
/* @0x28badc mov r0, r4 */
/* @0x28bae0 vmul.f32 s15, s14, s15 */
/* @0x28bae4 vstr s15, [r5, #20] */
/* @0x28bae8 bl 0x287444 <Json_getFloat> */
/* @0x28baec ldr r1, [pc, #0xd2c] */
/* @0x28baf0 mov r2, #1065353216 */
/* @0x28baf4 add r1, pc, r1 */
/* @0x28baf8 str r0, [r5, #0x18] */
/* @0x28bafc mov r0, r4 */
/* @0x28bb00 bl 0x287444 <Json_getFloat> */
/* @0x28bb04 ldr r1, [pc, #0xd18] */
/* @0x28bb08 mov r2, #1065353216 */
/* @0x28bb0c add r1, pc, r1 */
/* @0x28bb10 str r0, [r5, #0x1c] */
/* @0x28bb14 mov r0, r4 */
/* @0x28bb18 bl 0x287444 <Json_getFloat> */
/* @0x28bb1c ldr r1, [pc, #0xd04] */
/* @0x28bb20 mov r2, #0 */
/* @0x28bb24 add r1, pc, r1 */
/* @0x28bb28 str r0, [r5, #0x20] */
/* @0x28bb2c mov r0, r4 */
/* @0x28bb30 bl 0x287444 <Json_getFloat> */
/* @0x28bb34 ldr r1, [pc, #0xcf0] */
/* @0x28bb38 mov r2, #0 */
/* @0x28bb3c add r1, pc, r1 */
/* @0x28bb40 str r0, [r5, #0x24] */
/* @0x28bb44 mov r0, r4 */
/* @0x28bb48 bl 0x287444 <Json_getFloat> */
/* @0x28bb4c ldr r1, [pc, #0xcdc] */
/* @0x28bb50 mov r2, #1 */
/* @0x28bb54 add r1, pc, r1 */
/* @0x28bb58 str r0, [r5, #0x28] */
/* @0x28bb5c mov r0, r4 */
/* @0x28bb60 bl 0x287460 <Json_getInt> */
/* @0x28bb64 ldr r1, [pc, #0xcc8] */
/* @0x28bb68 mov r2, #1 */
/* @0x28bb6c add r1, pc, r1 */
/* @0x28bb70 str r0, [r5, #0x2c] */
/* @0x28bb74 mov r0, r4 */
/* @0x28bb78 bl 0x287460 <Json_getInt> */
/* @0x28bb7c ldr r1, [r9, #0x14] */
/* @0x28bb80 ldr r2, [r9, #0x10] */
/* @0x28bb84 add r2, r2, #1 */
/* @0x28bb88 str r0, [r5, #0x30] */
/* @0x28bb8c str r5, [r1, r6] */
/* @0x28bb90 add r6, r6, #4 */
/* @0x28bb94 ldr r4, [r4] */
/* @0x28bb98 str r2, [r9, #0x10] */
/* @0x28bb9c cmp r4, #0 */
/* @0x28bba0 beq 0x28bbcc <spSkeletonJson_readSkeletonData+0x380> */
/* @0x28bba4 mov r1, r7 */
/* @0x28bba8 mov r0, r4 */
/* @0x28bbac mov r2, #0 */
/* @0x28bbb0 bl 0x287428 <Json_getString> */
/* @0x28bbb4 subs r10, r0, #0 */
/* @0x28bbb8 mov r0, r9 */
/* @0x28bbbc mov r1, r10 */
/* @0x28bbc0 bne 0x28ba44 <spSkeletonJson_readSkeletonData+0x1f8> */
/* @0x28bbc4 mov r5, r10 */
/* @0x28bbc8 b 0x28ba50 <spSkeletonJson_readSkeletonData+0x204> */
/* @0x28bbcc ldr r1, [pc, #0xc64] */
/* @0x28bbd0 ldr r0, [sp, #0x24] */
/* @0x28bbd4 add r1, pc, r1 */
/* @0x28bbd8 bl 0x2873c4 <Json_getItem> */
/* @0x28bbdc subs r4, r0, #0 */
/* @0x28bbe0 beq 0x28bddc <spSkeletonJson_readSkeletonData+0x590> */
/* @0x28bbe4 ldr r0, [r4, #0xc] */
/* @0x28bbe8 movw r2, #0x28b */
/* @0x28bbec ldr r1, [pc, #0xc48] */
/* @0x28bbf0 str r0, [r9, #0x18] */
/* @0x28bbf4 add r1, pc, r1 */
/* @0x28bbf8 lsl r0, r0, #2 */
/* @0x28bbfc bl 0x285c10 <_malloc> */
/* @0x28bc00 ldr r4, [r4, #0x4] */
/* @0x28bc04 cmp r4, #0 */
/* @0x28bc08 str r0, [r9, #0x1c] */
/* @0x28bc0c beq 0x28bddc <spSkeletonJson_readSkeletonData+0x590> */
/* @0x28bc10 ldr r3, [pc, #0xc28] */
/* @0x28bc14 mov r6, #0 */
/* @0x28bc18 ldr r10, [pc, #0xc24] */
/* @0x28bc1c add r3, pc, r3 */
/* @0x28bc20 str r3, [sp, #0x18] */
/* @0x28bc24 ldr r3, [pc, #0xc1c] */
/* @0x28bc28 add r10, pc, r10 */
/* @0x28bc2c ldr r11, [pc, #0xc18] */
/* @0x28bc30 add r3, pc, r3 */
/* @0x28bc34 str r3, [sp, #0x1c] */
/* @0x28bc38 ldr r3, [pc, #0xc10] */
/* @0x28bc3c add r11, pc, r11 */
/* @0x28bc40 ldr r0, [pc, #0xc0c] */
/* @0x28bc44 add r3, pc, r3 */
/* @0x28bc48 str r8, [sp, #0x28] */
/* @0x28bc4c add r0, pc, r0 */
/* @0x28bc50 str r0, [sp, #0x20] */
/* @0x28bc54 mov r8, r3 */
/* @0x28bc58 b 0x28bd7c <spSkeletonJson_readSkeletonData+0x530> */
/* @0x28bc5c mov r1, r11 */
/* @0x28bc60 mov r2, #0 */
/* @0x28bc64 mov r0, r4 */
/* @0x28bc68 bl 0x287428 <Json_getString> */
/* @0x28bc6c mov r2, r7 */
/* @0x28bc70 mov r1, r0 */
/* @0x28bc74 mov r0, r6 */
/* @0x28bc78 bl 0x28ef2c <spSlotData_create> */
/* @0x28bc7c ldr r1, [sp, #0x18] */
/* @0x28bc80 mov r2, #0 */
/* @0x28bc84 mov r5, r0 */
/* @0x28bc88 mov r0, r4 */
/* @0x28bc8c bl 0x287428 <Json_getString> */
/* @0x28bc90 subs r7, r0, #0 */
/* @0x28bc94 beq 0x28bcd4 <spSkeletonJson_readSkeletonData+0x488> */
/* @0x28bc98 mov r1, #0 */
/* @0x28bc9c bl 0x28b680 <spSkeletonData_findPathConstraint+0x390> */
/* @0x28bca0 mov r0, r7 */
/* @0x28bca4 mov r1, #1 */
/* @0x28bca8 vstr s0, [r5, #16] */
/* @0x28bcac bl 0x28b680 <spSkeletonData_findPathConstraint+0x390> */
/* @0x28bcb0 mov r0, r7 */
/* @0x28bcb4 mov r1, #2 */
/* @0x28bcb8 vstr s0, [r5, #20] */
/* @0x28bcbc bl 0x28b680 <spSkeletonData_findPathConstraint+0x390> */
/* @0x28bcc0 mov r0, r7 */
/* @0x28bcc4 mov r1, #3 */
/* @0x28bcc8 vstr s0, [r5, #24] */
/* @0x28bccc bl 0x28b680 <spSkeletonData_findPathConstraint+0x390> */
/* @0x28bcd0 vstr s0, [r5, #28] */
/* @0x28bcd4 mov r0, r4 */
/* @0x28bcd8 ldr r1, [sp, #0x1c] */
/* @0x28bcdc bl 0x2873c4 <Json_getItem> */
/* @0x28bce0 cmp r0, #0 */
/* @0x28bce4 beq 0x28bcf4 <spSkeletonJson_readSkeletonData+0x4a8> */
/* @0x28bce8 ldr r1, [r0, #0x10] */
/* @0x28bcec mov r0, r5 */
/* @0x28bcf0 bl 0x28efcc <spSlotData_setAttachmentName> */
/* @0x28bcf4 mov r0, r4 */
/* @0x28bcf8 mov r1, r8 */
/* @0x28bcfc bl 0x2873c4 <Json_getItem> */
/* @0x28bd00 cmp r0, #0 */
/* @0x28bd04 beq 0x28bd64 <spSkeletonJson_readSkeletonData+0x518> */
/* @0x28bd08 ldr r7, [r0, #0x10] */
/* @0x28bd0c ldr r1, [sp, #0x20] */
/* @0x28bd10 mov r0, r7 */
/* @0x28bd14 bl 0xb6574 <strcmp@plt> */
/* @0x28bd18 cmp r0, #0 */
/* @0x28bd1c moveq r3, #1 */
/* @0x28bd20 streq r3, [r5, #0x20] */
/* @0x28bd24 beq 0x28bd64 <spSkeletonJson_readSkeletonData+0x518> */
/* @0x28bd28 ldr r1, [pc, #0xb28] */
/* @0x28bd2c mov r0, r7 */
/* @0x28bd30 add r1, pc, r1 */
/* @0x28bd34 bl 0xb6574 <strcmp@plt> */
/* @0x28bd38 cmp r0, #0 */
/* @0x28bd3c moveq r3, #2 */
/* @0x28bd40 streq r3, [r5, #0x20] */
/* @0x28bd44 beq 0x28bd64 <spSkeletonJson_readSkeletonData+0x518> */
/* @0x28bd48 ldr r1, [pc, #0xb0c] */
/* @0x28bd4c mov r0, r7 */
/* @0x28bd50 add r1, pc, r1 */
/* @0x28bd54 bl 0xb6574 <strcmp@plt> */
/* @0x28bd58 cmp r0, #0 */
/* @0x28bd5c moveq r3, #3 */
/* @0x28bd60 streq r3, [r5, #0x20] */
/* @0x28bd64 ldr r3, [r9, #0x1c] */
/* @0x28bd68 str r5, [r3, r6, lsl #2] */
/* @0x28bd6c add r6, r6, #1 */
/* @0x28bd70 ldr r4, [r4] */
/* @0x28bd74 cmp r4, #0 */
/* @0x28bd78 beq 0x28bdd8 <spSkeletonJson_readSkeletonData+0x58c> */
/* @0x28bd7c mov r1, r10 */
/* @0x28bd80 mov r2, #0 */
/* @0x28bd84 mov r0, r4 */
/* @0x28bd88 bl 0x287428 <Json_getString> */
/* @0x28bd8c mov r5, r0 */
/* @0x28bd90 mov r0, r9 */
/* @0x28bd94 mov r1, r5 */
/* @0x28bd98 bl 0x28afbc <spSkeletonData_findBone> */
/* @0x28bd9c subs r7, r0, #0 */
/* @0x28bda0 bne 0x28bc5c <spSkeletonJson_readSkeletonData+0x410> */
/* @0x28bda4 ldr r8, [sp, #0x28] */
/* @0x28bda8 mov r0, r9 */
/* @0x28bdac bl 0x28adf8 <spSkeletonData_dispose> */
/* @0x28bdb0 ldr r2, [pc, #0xaa8] */
/* @0x28bdb4 ldr r1, [sp, #0x24] */
/* @0x28bdb8 mov r3, r5 */
/* @0x28bdbc mov r0, r8 */
/* @0x28bdc0 add r2, pc, r2 */
/* @0x28bdc4 bl 0x28b784 <_spSkeletonJson_setError> */
/* @0x28bdc8 mov r0, r7 */
/* @0x28bdcc add sp, sp, #124 */
/* @0x28bdd0 vpop {d8} */
/* @0x28bdd4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x28bdd8 ldr r8, [sp, #0x28] */
/* @0x28bddc ldr r1, [pc, #0xa80] */
/* @0x28bde0 ldr r0, [sp, #0x24] */
/* @0x28bde4 add r1, pc, r1 */
/* @0x28bde8 bl 0x2873c4 <Json_getItem> */
/* @0x28bdec subs r4, r0, #0 */
/* @0x28bdf0 beq 0x28bff8 <spSkeletonJson_readSkeletonData+0x7ac> */
/* @0x28bdf4 ldr r5, [pc, #0xa6c] */
/* @0x28bdf8 movw r2, #0x2b9 */
/* @0x28bdfc ldr r0, [r4, #0xc] */
/* @0x28be00 add r5, pc, r5 */
/* @0x28be04 str r0, [r9, #0x3c] */
/* @0x28be08 mov r1, r5 */
/* @0x28be0c lsl r0, r0, #2 */
/* @0x28be10 bl 0x285c10 <_malloc> */
/* @0x28be14 ldr r6, [r4, #0x4] */
/* @0x28be18 cmp r6, #0 */
/* @0x28be1c str r0, [r9, #0x40] */
/* @0x28be20 beq 0x28bff8 <spSkeletonJson_readSkeletonData+0x7ac> */
/* @0x28be24 ldr r3, [pc, #0xa40] */
/* @0x28be28 mov r7, #0 */
/* @0x28be2c str r5, [sp, #0x20] */
/* @0x28be30 add r3, pc, r3 */
/* @0x28be34 str r3, [sp, #0x18] */
/* @0x28be38 ldr r3, [pc, #0xa30] */
/* @0x28be3c add r3, pc, r3 */
/* @0x28be40 str r3, [sp, #0x1c] */
/* @0x28be44 ldr r3, [pc, #0xa28] */
/* @0x28be48 add r3, pc, r3 */
/* @0x28be4c str r3, [sp, #0x28] */
/* @0x28be50 ldr r3, [pc, #0xa20] */
/* @0x28be54 add r3, pc, r3 */
/* @0x28be58 str r3, [sp, #0x2c] */
/* @0x28be5c ldr r3, [pc, #0xa18] */
/* @0x28be60 add r3, pc, r3 */
/* @0x28be64 str r3, [sp, #0x30] */
/* @0x28be68 mov r2, #0 */
/* @0x28be6c ldr r1, [sp, #0x18] */
/* @0x28be70 mov r0, r6 */
/* @0x28be74 bl 0x287428 <Json_getString> */
/* @0x28be78 bl 0x2866f0 <spIkConstraintData_create> */
/* @0x28be7c ldr r1, [sp, #0x1c] */
/* @0x28be80 mov r5, r0 */
/* @0x28be84 mov r0, r6 */
/* @0x28be88 bl 0x2873c4 <Json_getItem> */
/* @0x28be8c ldr r1, [sp, #0x20] */
/* @0x28be90 movw r2, #0x2c1 */
/* @0x28be94 mov r4, r0 */
/* @0x28be98 ldr r0, [r0, #0xc] */
/* @0x28be9c str r0, [r5, #0x4] */
/* @0x28bea0 lsl r0, r0, #2 */
/* @0x28bea4 bl 0x285c10 <_malloc> */
/* @0x28bea8 ldr r4, [r4, #0x4] */
/* @0x28beac cmp r4, #0 */
/* @0x28beb0 movne r10, #0 */
/* @0x28beb4 str r0, [r5, #0x8] */
/* @0x28beb8 movne r11, r0 */
/* @0x28bebc bne 0x28bed0 <spSkeletonJson_readSkeletonData+0x684> */
/* @0x28bec0 b 0x28bf84 <spSkeletonJson_readSkeletonData+0x738> */
/* @0x28bec4 ldr r4, [r4] */
/* @0x28bec8 cmp r4, #0 */
/* @0x28becc beq 0x28bf84 <spSkeletonJson_readSkeletonData+0x738> */
/* @0x28bed0 ldr r1, [r4, #0x10] */
/* @0x28bed4 mov r0, r9 */
/* @0x28bed8 bl 0x28afbc <spSkeletonData_findBone> */
/* @0x28bedc str r0, [r11, r10] */
/* @0x28bee0 ldr r11, [r5, #0x8] */
/* @0x28bee4 ldr r1, [r11, r10] */
/* @0x28bee8 add r10, r10, #4 */
/* @0x28beec cmp r1, #0 */
/* @0x28bef0 bne 0x28bec4 <spSkeletonJson_readSkeletonData+0x678> */
/* @0x28bef4 mov r0, r9 */
/* @0x28bef8 mov r10, r1 */
/* @0x28befc bl 0x28adf8 <spSkeletonData_dispose> */
/* @0x28bf00 ldr r2, [pc, #0x978] */
/* @0x28bf04 mov r0, r8 */
/* @0x28bf08 ldr r1, [sp, #0x24] */
/* @0x28bf0c ldr r3, [r4, #0x10] */
/* @0x28bf10 add r2, pc, r2 */
/* @0x28bf14 bl 0x28b784 <_spSkeletonJson_setError> */
/* @0x28bf18 mov r0, r10 */
/* @0x28bf1c add sp, sp, #124 */
/* @0x28bf20 vpop {d8} */
/* @0x28bf24 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x28bf28 mov r0, r9 */
/* @0x28bf2c bl 0x28adf8 <spSkeletonData_dispose> */
/* @0x28bf30 ldr r2, [pc, #0x94c] */
/* @0x28bf34 mov r0, r8 */
/* @0x28bf38 ldr r1, [sp, #0x24] */
/* @0x28bf3c mov r3, r10 */
/* @0x28bf40 add r2, pc, r2 */
/* @0x28bf44 bl 0x28b784 <_spSkeletonJson_setError> */
/* @0x28bf48 mov r0, r5 */
/* @0x28bf4c add sp, sp, #124 */
/* @0x28bf50 vpop {d8} */
/* @0x28bf54 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x28bf58 ldr r1, [pc, #0x928] */
/* @0x28bf5c mov r0, #1 */
/* @0x28bf60 add r1, pc, r1 */
/* @0x28bf64 bl 0xb679c <setlocale@plt> */
/* @0x28bf68 mov r0, r5 */
/* @0x28bf6c bl 0x287320 <Json_create> */
/* @0x28bf70 mov r1, r4 */
/* @0x28bf74 str r0, [sp, #0x24] */
/* @0x28bf78 mov r0, #1 */
/* @0x28bf7c bl 0xb679c <setlocale@plt> */
/* @0x28bf80 b 0x28b8c8 <spSkeletonJson_readSkeletonData+0x7c> */
/* @0x28bf84 ldr r1, [sp, #0x28] */
/* @0x28bf88 mov r2, #0 */
/* @0x28bf8c mov r0, r6 */
/* @0x28bf90 bl 0x287428 <Json_getString> */
/* @0x28bf94 mov r1, r0 */
/* @0x28bf98 mov r0, r9 */
/* @0x28bf9c bl 0x28afbc <spSkeletonData_findBone> */
/* @0x28bfa0 cmp r0, #0 */
/* @0x28bfa4 str r0, [r5, #0xc] */
/* @0x28bfa8 beq 0x28cf3c <spSkeletonJson_readSkeletonData+0x16f0> */
/* @0x28bfac mov r0, r6 */
/* @0x28bfb0 ldr r1, [sp, #0x2c] */
/* @0x28bfb4 mov r2, #1 */
/* @0x28bfb8 bl 0x287460 <Json_getInt> */
/* @0x28bfbc ldr r1, [sp, #0x30] */
/* @0x28bfc0 mov r2, #1065353216 */
/* @0x28bfc4 cmp r0, #0 */
/* @0x28bfc8 mov r0, r6 */
/* @0x28bfcc mvneq r3, #0 */
/* @0x28bfd0 movne r3, #1 */
/* @0x28bfd4 str r3, [r5, #0x10] */
/* @0x28bfd8 bl 0x287444 <Json_getFloat> */
/* @0x28bfdc ldr r3, [r9, #0x40] */
/* @0x28bfe0 str r0, [r5, #0x14] */
/* @0x28bfe4 str r5, [r3, r7] */
/* @0x28bfe8 add r7, r7, #4 */
/* @0x28bfec ldr r6, [r6] */
/* @0x28bff0 cmp r6, #0 */
/* @0x28bff4 bne 0x28be68 <spSkeletonJson_readSkeletonData+0x61c> */
/* @0x28bff8 ldr r1, [pc, #0x88c] */
/* @0x28bffc ldr r0, [sp, #0x24] */
/* @0x28c000 add r1, pc, r1 */
/* @0x28c004 bl 0x2873c4 <Json_getItem> */
/* @0x28c008 subs r4, r0, #0 */
/* @0x28c00c beq 0x28c274 <spSkeletonJson_readSkeletonData+0xa28> */
/* @0x28c010 ldr r5, [pc, #0x878] */
/* @0x28c014 movw r2, #0x2df */
/* @0x28c018 ldr r0, [r4, #0xc] */
/* @0x28c01c add r5, pc, r5 */
/* @0x28c020 str r0, [r9, #0x44] */
/* @0x28c024 mov r1, r5 */
/* @0x28c028 lsl r0, r0, #2 */
/* @0x28c02c bl 0x285c10 <_malloc> */
/* @0x28c030 ldr r6, [r4, #0x4] */
/* @0x28c034 cmp r6, #0 */
/* @0x28c038 str r0, [r9, #0x48] */
/* @0x28c03c beq 0x28c274 <spSkeletonJson_readSkeletonData+0xa28> */
/* @0x28c040 ldr r3, [pc, #0x84c] */
/* @0x28c044 mov r7, #0 */
/* @0x28c048 str r5, [sp, #0x20] */
/* @0x28c04c add r3, pc, r3 */
/* @0x28c050 str r3, [sp, #0x18] */
/* @0x28c054 ldr r3, [pc, #0x83c] */
/* @0x28c058 add r3, pc, r3 */
/* @0x28c05c str r3, [sp, #0x1c] */
/* @0x28c060 ldr r3, [pc, #0x834] */
/* @0x28c064 add r3, pc, r3 */
/* @0x28c068 str r3, [sp, #0x28] */
/* @0x28c06c ldr r3, [pc, #0x82c] */
/* @0x28c070 add r3, pc, r3 */
/* @0x28c074 str r3, [sp, #0x2c] */
/* @0x28c078 mov r2, #0 */
/* @0x28c07c ldr r1, [sp, #0x18] */
/* @0x28c080 mov r0, r6 */
/* @0x28c084 bl 0x287428 <Json_getString> */
/* @0x28c088 bl 0x28f5b0 <spTransformConstraintData_create> */
/* @0x28c08c ldr r1, [sp, #0x1c] */
/* @0x28c090 mov r5, r0 */
/* @0x28c094 mov r0, r6 */
/* @0x28c098 bl 0x2873c4 <Json_getItem> */
/* @0x28c09c ldr r1, [sp, #0x20] */
/* @0x28c0a0 movw r2, #0x2e7 */
/* @0x28c0a4 mov r4, r0 */
/* @0x28c0a8 ldr r0, [r0, #0xc] */
/* @0x28c0ac str r0, [r5, #0x4] */
/* @0x28c0b0 lsl r0, r0, #2 */
/* @0x28c0b4 bl 0x285c10 <_malloc> */
/* @0x28c0b8 str r0, [r5, #0x8] */
/* @0x28c0bc ldr r4, [r4, #0x4] */
/* @0x28c0c0 cmp r4, #0 */
/* @0x28c0c4 movne r11, r0 */
/* @0x28c0c8 movne r10, #0 */
/* @0x28c0cc bne 0x28c0e0 <spSkeletonJson_readSkeletonData+0x894> */
/* @0x28c0d0 b 0x28c130 <spSkeletonJson_readSkeletonData+0x8e4> */
/* @0x28c0d4 ldr r4, [r4] */
/* @0x28c0d8 cmp r4, #0 */
/* @0x28c0dc beq 0x28c130 <spSkeletonJson_readSkeletonData+0x8e4> */
/* @0x28c0e0 mov r0, r9 */
/* @0x28c0e4 ldr r1, [r4, #0x10] */
/* @0x28c0e8 bl 0x28afbc <spSkeletonData_findBone> */
/* @0x28c0ec str r0, [r11, r10] */
/* @0x28c0f0 ldr r11, [r5, #0x8] */
/* @0x28c0f4 ldr r0, [r11, r10] */
/* @0x28c0f8 add r10, r10, #4 */
/* @0x28c0fc cmp r0, #0 */
/* @0x28c100 bne 0x28c0d4 <spSkeletonJson_readSkeletonData+0x888> */
/* @0x28c104 mov r10, r0 */
/* @0x28c108 mov r0, r9 */
/* @0x28c10c bl 0x28adf8 <spSkeletonData_dispose> */
/* @0x28c110 ldr r2, [pc, #0x78c] */
/* @0x28c114 mov r0, r8 */
/* @0x28c118 ldr r1, [sp, #0x24] */
/* @0x28c11c ldr r3, [r4, #0x10] */
/* @0x28c120 add r2, pc, r2 */
/* @0x28c124 bl 0x28b784 <_spSkeletonJson_setError> */
/* @0x28c128 mov r0, r10 */
/* @0x28c12c b 0x28bdcc <spSkeletonJson_readSkeletonData+0x580> */
/* @0x28c130 ldr r1, [sp, #0x28] */
/* @0x28c134 mov r2, #0 */
/* @0x28c138 mov r0, r6 */
/* @0x28c13c bl 0x287428 <Json_getString> */
/* @0x28c140 mov r1, r0 */
/* @0x28c144 mov r0, r9 */
/* @0x28c148 bl 0x28afbc <spSkeletonData_findBone> */
/* @0x28c14c cmp r0, #0 */
/* @0x28c150 str r0, [r5, #0xc] */
/* @0x28c154 beq 0x28d144 <spSkeletonJson_readSkeletonData+0x18f8> */
/* @0x28c158 mov r0, r6 */
/* @0x28c15c ldr r1, [sp, #0x2c] */
/* @0x28c160 mov r2, #0 */
/* @0x28c164 bl 0x287444 <Json_getFloat> */
/* @0x28c168 ldr r1, [pc, #0x738] */
/* @0x28c16c mov r2, #0 */
/* @0x28c170 add r1, pc, r1 */
/* @0x28c174 str r0, [r5, #0x20] */
/* @0x28c178 mov r0, r6 */
/* @0x28c17c bl 0x287444 <Json_getFloat> */
/* @0x28c180 vldr s15, [r8] */
/* @0x28c184 ldr r1, [pc, #0x720] */
/* @0x28c188 mov r2, #0 */
/* @0x28c18c add r1, pc, r1 */
/* @0x28c190 vmov s14, r0 */
/* @0x28c194 mov r0, r6 */
/* @0x28c198 vmul.f32 s15, s14, s15 */
/* @0x28c19c vstr s15, [r5, #36] */
/* @0x28c1a0 bl 0x287444 <Json_getFloat> */
/* @0x28c1a4 vldr s15, [r8] */
/* @0x28c1a8 ldr r1, [pc, #0x700] */
/* @0x28c1ac mov r2, #0 */
/* @0x28c1b0 add r1, pc, r1 */
/* @0x28c1b4 vmov s14, r0 */
/* @0x28c1b8 mov r0, r6 */
/* @0x28c1bc vmul.f32 s15, s14, s15 */
/* @0x28c1c0 vstr s15, [r5, #40] */
/* @0x28c1c4 bl 0x287444 <Json_getFloat> */
/* @0x28c1c8 ldr r1, [pc, #0x6e4] */
/* @0x28c1cc mov r2, #0 */
/* @0x28c1d0 add r1, pc, r1 */
/* @0x28c1d4 str r0, [r5, #0x2c] */
/* @0x28c1d8 mov r0, r6 */
/* @0x28c1dc bl 0x287444 <Json_getFloat> */
/* @0x28c1e0 ldr r1, [pc, #0x6d0] */
/* @0x28c1e4 mov r2, #0 */
/* @0x28c1e8 add r1, pc, r1 */
/* @0x28c1ec str r0, [r5, #0x30] */
/* @0x28c1f0 mov r0, r6 */
/* @0x28c1f4 bl 0x287444 <Json_getFloat> */
/* @0x28c1f8 ldr r1, [pc, #0x6bc] */
/* @0x28c1fc mov r2, #1065353216 */
/* @0x28c200 add r1, pc, r1 */
/* @0x28c204 str r0, [r5, #0x34] */
/* @0x28c208 mov r0, r6 */
/* @0x28c20c bl 0x287444 <Json_getFloat> */
/* @0x28c210 ldr r1, [pc, #0x6a8] */
/* @0x28c214 mov r2, #1065353216 */
/* @0x28c218 add r1, pc, r1 */
/* @0x28c21c str r0, [r5, #0x10] */
/* @0x28c220 mov r0, r6 */
/* @0x28c224 bl 0x287444 <Json_getFloat> */
/* @0x28c228 ldr r1, [pc, #0x694] */
/* @0x28c22c mov r2, #1065353216 */
/* @0x28c230 add r1, pc, r1 */
/* @0x28c234 str r0, [r5, #0x14] */
/* @0x28c238 mov r0, r6 */
/* @0x28c23c bl 0x287444 <Json_getFloat> */
/* @0x28c240 ldr r1, [pc, #0x680] */
/* @0x28c244 mov r2, #1065353216 */
/* @0x28c248 add r1, pc, r1 */
/* @0x28c24c str r0, [r5, #0x18] */
/* @0x28c250 mov r0, r6 */
/* @0x28c254 bl 0x287444 <Json_getFloat> */
/* @0x28c258 ldr r3, [r9, #0x48] */
/* @0x28c25c str r0, [r5, #0x1c] */
/* @0x28c260 str r5, [r3, r7] */
/* @0x28c264 add r7, r7, #4 */
/* @0x28c268 ldr r6, [r6] */
/* @0x28c26c cmp r6, #0 */
/* @0x28c270 bne 0x28c078 <spSkeletonJson_readSkeletonData+0x82c> */
/* @0x28c274 ldr r1, [pc, #0x650] */
/* @0x28c278 ldr r0, [sp, #0x24] */
/* @0x28c27c add r1, pc, r1 */
/* @0x28c280 bl 0x2873c4 <Json_getItem> */
/* @0x28c284 subs r5, r0, #0 */
/* @0x28c288 beq 0x28c5ec <spSkeletonJson_readSkeletonData+0xda0> */
/* @0x28c28c ldr r4, [pc, #0x63c] */
/* @0x28c290 movw r2, #0x30e */
/* @0x28c294 ldr r0, [r5, #0xc] */
/* @0x28c298 add r4, pc, r4 */
/* @0x28c29c str r0, [r9, #0x4c] */
/* @0x28c2a0 mov r1, r4 */
/* @0x28c2a4 lsl r0, r0, #2 */
/* @0x28c2a8 bl 0x285c10 <_malloc> */
/* @0x28c2ac ldr r6, [r5, #0x4] */
/* @0x28c2b0 cmp r6, #0 */
/* @0x28c2b4 str r0, [r9, #0x50] */
/* @0x28c2b8 beq 0x28c5ec <spSkeletonJson_readSkeletonData+0xda0> */
/* @0x28c2bc ldr r3, [pc, #0x610] */
/* @0x28c2c0 mov r7, #0 */
/* @0x28c2c4 str r4, [sp, #0x20] */
/* @0x28c2c8 add r3, pc, r3 */
/* @0x28c2cc str r3, [sp, #0x18] */
/* @0x28c2d0 ldr r3, [pc, #0x600] */
/* @0x28c2d4 add r3, pc, r3 */
/* @0x28c2d8 str r3, [sp, #0x1c] */
/* @0x28c2dc ldr r3, [pc, #0x5f8] */
/* @0x28c2e0 add r3, pc, r3 */
/* @0x28c2e4 str r3, [sp, #0x28] */
/* @0x28c2e8 ldr r3, [pc, #0x5f0] */
/* @0x28c2ec add r3, pc, r3 */
/* @0x28c2f0 str r3, [sp, #0x2c] */
/* @0x28c2f4 mov r2, #0 */
/* @0x28c2f8 ldr r1, [sp, #0x18] */
/* @0x28c2fc mov r0, r6 */
/* @0x28c300 bl 0x287428 <Json_getString> */
/* @0x28c304 bl 0x288edc <spPathConstraintData_create> */
/* @0x28c308 ldr r1, [sp, #0x1c] */
/* @0x28c30c mov r5, r0 */
/* @0x28c310 mov r0, r6 */
/* @0x28c314 bl 0x2873c4 <Json_getItem> */
/* @0x28c318 ldr r1, [sp, #0x20] */
/* @0x28c31c movw r2, #0x317 */
/* @0x28c320 mov r4, r0 */
/* @0x28c324 ldr r0, [r0, #0xc] */
/* @0x28c328 str r0, [r5, #0x4] */
/* @0x28c32c lsl r0, r0, #2 */
/* @0x28c330 bl 0x285c10 <_malloc> */
/* @0x28c334 str r0, [r5, #0x8] */
/* @0x28c338 ldr r10, [r4, #0x4] */
/* @0x28c33c cmp r10, #0 */
/* @0x28c340 movne r11, r0 */
/* @0x28c344 movne r4, #0 */
/* @0x28c348 bne 0x28c35c <spSkeletonJson_readSkeletonData+0xb10> */
/* @0x28c34c b 0x28c3d8 <spSkeletonJson_readSkeletonData+0xb8c> */
/* @0x28c350 ldr r10, [r10] */
/* @0x28c354 cmp r10, #0 */
/* @0x28c358 beq 0x28c3d8 <spSkeletonJson_readSkeletonData+0xb8c> */
/* @0x28c35c mov r0, r9 */
/* @0x28c360 ldr r1, [r10, #0x10] */
/* @0x28c364 bl 0x28afbc <spSkeletonData_findBone> */
/* @0x28c368 str r0, [r11, r4] */
/* @0x28c36c ldr r3, [r5, #0x8] */
/* @0x28c370 ldr r12, [r3, r4] */
/* @0x28c374 mov r11, r3 */
/* @0x28c378 add r4, r4, #4 */
/* @0x28c37c cmp r12, #0 */
/* @0x28c380 bne 0x28c350 <spSkeletonJson_readSkeletonData+0xb04> */
/* @0x28c384 mov r0, r9 */
/* @0x28c388 str r12, [sp, #0x14] */
/* @0x28c38c bl 0x28adf8 <spSkeletonData_dispose> */
/* @0x28c390 ldr r2, [pc, #0x54c] */
/* @0x28c394 mov r0, r8 */
/* @0x28c398 ldr r1, [sp, #0x24] */
/* @0x28c39c ldr r3, [r10, #0x10] */
/* @0x28c3a0 add r2, pc, r2 */
/* @0x28c3a4 bl 0x28b784 <_spSkeletonJson_setError> */
/* @0x28c3a8 ldr r12, [sp, #0x14] */
/* @0x28c3ac mov r0, r12 */
/* @0x28c3b0 b 0x28bdcc <spSkeletonJson_readSkeletonData+0x580> */
/* @0x28c3b4 bl 0x2872b8 <Json_getError> */
/* @0x28c3b8 ldr r2, [pc, #0x528] */
/* @0x28c3bc ldr r1, [sp, #0x24] */
/* @0x28c3c0 add r2, pc, r2 */
/* @0x28c3c4 mov r3, r0 */
/* @0x28c3c8 mov r0, r8 */
/* @0x28c3cc bl 0x28b784 <_spSkeletonJson_setError> */
/* @0x28c3d0 ldr r0, [sp, #0x24] */
/* @0x28c3d4 b 0x28bdcc <spSkeletonJson_readSkeletonData+0x580> */
/* @0x28c3d8 ldr r1, [sp, #0x28] */
/* @0x28c3dc mov r2, #0 */
/* @0x28c3e0 mov r0, r6 */
/* @0x28c3e4 bl 0x287428 <Json_getString> */
/* @0x28c3e8 mov r1, r0 */
/* @0x28c3ec mov r0, r9 */
/* @0x28c3f0 bl 0x28b070 <spSkeletonData_findSlot> */
/* @0x28c3f4 cmp r0, #0 */
/* @0x28c3f8 str r0, [r5, #0xc] */
/* @0x28c3fc beq 0x28d170 <spSkeletonJson_readSkeletonData+0x1924> */
/* @0x28c400 ldr r4, [pc, #0x4e4] */
/* @0x28c404 mov r0, r6 */
/* @0x28c408 ldr r1, [sp, #0x2c] */
/* @0x28c40c add r4, pc, r4 */
/* @0x28c410 mov r2, r4 */
/* @0x28c414 bl 0x287428 <Json_getString> */
/* @0x28c418 ldr r1, [pc, #0x4d0] */
/* @0x28c41c add r1, pc, r1 */
/* @0x28c420 mov r10, r0 */
/* @0x28c424 bl 0xb6574 <strcmp@plt> */
/* @0x28c428 cmp r0, #0 */
/* @0x28c42c streq r0, [r5, #0x10] */
/* @0x28c430 beq 0x28c44c <spSkeletonJson_readSkeletonData+0xc00> */
/* @0x28c434 mov r0, r10 */
/* @0x28c438 mov r1, r4 */
/* @0x28c43c bl 0xb6574 <strcmp@plt> */
/* @0x28c440 cmp r0, #0 */
/* @0x28c444 moveq r3, #1 */
/* @0x28c448 streq r3, [r5, #0x10] */
/* @0x28c44c ldr r10, [pc, #0x4a0] */
/* @0x28c450 mov r0, r6 */
/* @0x28c454 ldr r1, [pc, #0x49c] */
/* @0x28c458 add r10, pc, r10 */
/* @0x28c45c add r1, pc, r1 */
/* @0x28c460 mov r2, r10 */
/* @0x28c464 bl 0x287428 <Json_getString> */
/* @0x28c468 mov r1, r10 */
/* @0x28c46c mov r4, r0 */
/* @0x28c470 bl 0xb6574 <strcmp@plt> */
/* @0x28c474 cmp r0, #0 */
/* @0x28c478 streq r0, [r5, #0x14] */
/* @0x28c47c beq 0x28c4bc <spSkeletonJson_readSkeletonData+0xc70> */
/* @0x28c480 ldr r1, [pc, #0x474] */
/* @0x28c484 mov r0, r4 */
/* @0x28c488 add r1, pc, r1 */
/* @0x28c48c bl 0xb6574 <strcmp@plt> */
/* @0x28c490 cmp r0, #0 */
/* @0x28c494 moveq r3, #1 */
/* @0x28c498 streq r3, [r5, #0x14] */
/* @0x28c49c beq 0x28c4bc <spSkeletonJson_readSkeletonData+0xc70> */
/* @0x28c4a0 ldr r1, [pc, #0x458] */
/* @0x28c4a4 mov r0, r4 */
/* @0x28c4a8 add r1, pc, r1 */
/* @0x28c4ac bl 0xb6574 <strcmp@plt> */
/* @0x28c4b0 cmp r0, #0 */
/* @0x28c4b4 moveq r3, #2 */
/* @0x28c4b8 streq r3, [r5, #0x14] */
/* @0x28c4bc ldr r10, [pc, #0x440] */
/* @0x28c4c0 mov r0, r6 */
/* @0x28c4c4 ldr r1, [pc, #0x43c] */
/* @0x28c4c8 add r10, pc, r10 */
/* @0x28c4cc add r1, pc, r1 */
/* @0x28c4d0 mov r2, r10 */
/* @0x28c4d4 bl 0x287428 <Json_getString> */
/* @0x28c4d8 mov r1, r10 */
/* @0x28c4dc mov r4, r0 */
/* @0x28c4e0 bl 0xb6574 <strcmp@plt> */
/* @0x28c4e4 cmp r0, #0 */
/* @0x28c4e8 streq r0, [r5, #0x18] */
/* @0x28c4ec beq 0x28c52c <spSkeletonJson_readSkeletonData+0xce0> */
/* @0x28c4f0 ldr r1, [pc, #0x414] */
/* @0x28c4f4 mov r0, r4 */
/* @0x28c4f8 add r1, pc, r1 */
/* @0x28c4fc bl 0xb6574 <strcmp@plt> */
/* @0x28c500 cmp r0, #0 */
/* @0x28c504 moveq r3, #1 */
/* @0x28c508 streq r3, [r5, #0x18] */
/* @0x28c50c beq 0x28c52c <spSkeletonJson_readSkeletonData+0xce0> */
/* @0x28c510 ldr r1, [pc, #0x3f8] */
/* @0x28c514 mov r0, r4 */
/* @0x28c518 add r1, pc, r1 */
/* @0x28c51c bl 0xb6574 <strcmp@plt> */
/* @0x28c520 cmp r0, #0 */
/* @0x28c524 moveq r3, #2 */
/* @0x28c528 streq r3, [r5, #0x18] */
/* @0x28c52c ldr r1, [pc, #0x3e0] */
/* @0x28c530 mov r0, r6 */
/* @0x28c534 mov r2, #0 */
/* @0x28c538 add r1, pc, r1 */
/* @0x28c53c bl 0x287444 <Json_getFloat> */
/* @0x28c540 ldr r1, [pc, #0x3d0] */
/* @0x28c544 mov r2, #0 */
/* @0x28c548 add r1, pc, r1 */
/* @0x28c54c str r0, [r5, #0x1c] */
/* @0x28c550 mov r0, r6 */
/* @0x28c554 bl 0x287444 <Json_getFloat> */
/* @0x28c558 ldr r3, [r5, #0x10] */
/* @0x28c55c ldr r1, [pc, #0x3b8] */
/* @0x28c560 mov r2, #0 */
/* @0x28c564 cmp r3, #0 */
/* @0x28c568 vldreq s14, [r8] */
/* @0x28c56c add r1, pc, r1 */
/* @0x28c570 vmov s15, r0 */
/* @0x28c574 str r0, [r5, #0x20] */
/* @0x28c578 mov r0, r6 */
/* @0x28c57c vmuleq.f32 s15, s15, s14 */
/* @0x28c580 vstreq s15, [r5, #32] */
/* @0x28c584 bl 0x287444 <Json_getFloat> */
/* @0x28c588 ldr r3, [r5, #0x14] */
/* @0x28c58c ldr r1, [pc, #0x38c] */
/* @0x28c590 mov r2, #1065353216 */
/* @0x28c594 cmp r3, #1 */
/* @0x28c598 vldrls s14, [r8] */
/* @0x28c59c add r1, pc, r1 */
/* @0x28c5a0 vmov s15, r0 */
/* @0x28c5a4 str r0, [r5, #0x24] */
/* @0x28c5a8 mov r0, r6 */
/* @0x28c5ac vmulls.f32 s15, s15, s14 */
/* @0x28c5b0 vstrls s15, [r5, #36] */
/* @0x28c5b4 bl 0x287444 <Json_getFloat> */
/* @0x28c5b8 ldr r1, [pc, #0x364] */
/* @0x28c5bc mov r2, #1065353216 */
/* @0x28c5c0 add r1, pc, r1 */
/* @0x28c5c4 str r0, [r5, #0x28] */
/* @0x28c5c8 mov r0, r6 */
/* @0x28c5cc bl 0x287444 <Json_getFloat> */
/* @0x28c5d0 ldr r3, [r9, #0x50] */
/* @0x28c5d4 str r0, [r5, #0x2c] */
/* @0x28c5d8 str r5, [r3, r7] */
/* @0x28c5dc add r7, r7, #4 */
/* @0x28c5e0 ldr r6, [r6] */
/* @0x28c5e4 cmp r6, #0 */
/* @0x28c5e8 bne 0x28c2f4 <spSkeletonJson_readSkeletonData+0xaa8> */
/* @0x28c5ec ldr r1, [pc, #0x334] */
/* @0x28c5f0 ldr r0, [sp, #0x24] */
/* @0x28c5f4 add r1, pc, r1 */
/* @0x28c5f8 bl 0x2873c4 <Json_getItem> */
/* @0x28c5fc subs r4, r0, #0 */
/* @0x28c600 beq 0x28ccb8 <spSkeletonJson_readSkeletonData+0x146c> */
/* @0x28c604 ldr r0, [r4, #0xc] */
/* @0x28c608 movw r2, #0x347 */
/* @0x28c60c ldr r1, [pc, #0x318] */
/* @0x28c610 lsl r0, r0, #2 */
/* @0x28c614 add r1, pc, r1 */
/* @0x28c618 bl 0x285c10 <_malloc> */
/* @0x28c61c ldr r4, [r4, #0x4] */
/* @0x28c620 cmp r4, #0 */
/* @0x28c624 str r4, [sp, #0x18] */
/* @0x28c628 str r0, [r9, #0x24] */
/* @0x28c62c beq 0x28ccb8 <spSkeletonJson_readSkeletonData+0x146c> */
/* @0x28c630 ldr r0, [pc, #0x2f8] */
/* @0x28c634 mov r11, r9 */
/* @0x28c638 ldr r2, [pc, #0x2f4] */
/* @0x28c63c movw r1, #0x5556 */
/* @0x28c640 ldr r3, [pc, #0x2f0] */
/* @0x28c644 add r0, pc, r0 */
/* @0x28c648 add r2, pc, r2 */
/* @0x28c64c movt r1, #0x5555 */
/* @0x28c650 add r3, pc, r3 */
/* @0x28c654 str r0, [sp, #0x4c] */
/* @0x28c658 str r2, [sp, #0x30] */
/* @0x28c65c str r1, [sp, #0x38] */
/* @0x28c660 str r3, [sp, #0x20] */
/* @0x28c664 ldr r1, [sp, #0x18] */
/* @0x28c668 ldr r0, [r1, #0x1c] */
/* @0x28c66c bl 0x28ec44 <spSkin_create> */
/* @0x28c670 ldr r3, [r11, #0x20] */
/* @0x28c674 ldr r2, [r11, #0x24] */
/* @0x28c678 ldr r1, [sp, #0x4c] */
/* @0x28c67c mov r9, r0 */
/* @0x28c680 add r0, r3, #1 */
/* @0x28c684 str r0, [r11, #0x20] */
/* @0x28c688 str r9, [r2, r3, lsl #2] */
/* @0x28c68c ldr r2, [sp, #0x18] */
/* @0x28c690 ldr r0, [r2, #0x1c] */
/* @0x28c694 bl 0xb6574 <strcmp@plt> */
/* @0x28c698 ldr r3, [sp, #0x18] */
/* @0x28c69c ldr r3, [r3, #0x4] */
/* @0x28c6a0 str r3, [sp, #0x1c] */
/* @0x28c6a4 cmp r0, #0 */
/* @0x28c6a8 streq r9, [r11, #0x28] */
/* @0x28c6ac cmp r3, #0 */
/* @0x28c6b0 beq 0x28cca0 <spSkeletonJson_readSkeletonData+0x1454> */
/* @0x28c6b4 ldr r1, [pc, #0x280] */
/* @0x28c6b8 str r11, [sp, #0x34] */
/* @0x28c6bc add r1, pc, r1 */
/* @0x28c6c0 str r1, [sp, #0x2c] */
/* @0x28c6c4 ldr r2, [sp, #0x1c] */
/* @0x28c6c8 ldr r0, [sp, #0x34] */
/* @0x28c6cc ldr r1, [r2, #0x1c] */
/* @0x28c6d0 bl 0x28b0cc <spSkeletonData_findSlotIndex> */
/* @0x28c6d4 ldr r3, [sp, #0x1c] */
/* @0x28c6d8 ldr r4, [r3, #0x4] */
/* @0x28c6dc cmp r4, #0 */
/* @0x28c6e0 str r0, [sp, #0x28] */
/* @0x28c6e4 beq 0x28cc88 <spSkeletonJson_readSkeletonData+0x143c> */
/* @0x28c6e8 ldr r7, [r4, #0x1c] */
/* @0x28c6ec mov r0, r4 */
/* @0x28c6f0 ldr r1, [sp, #0x30] */
/* @0x28c6f4 ldr r10, [pc, #0x244] */
/* @0x28c6f8 mov r2, r7 */
/* @0x28c6fc bl 0x287428 <Json_getString> */
/* @0x28c700 ldr r1, [sp, #0x20] */
/* @0x28c704 add r10, pc, r10 */
/* @0x28c708 mov r11, r10 */
/* @0x28c70c mov r6, r0 */
/* @0x28c710 mov r0, r4 */
/* @0x28c714 mov r2, r6 */
/* @0x28c718 bl 0x287428 <Json_getString> */
/* @0x28c71c mov r2, r10 */
/* @0x28c720 ldr r1, [sp, #0x2c] */
/* @0x28c724 mov r5, r0 */
/* @0x28c728 mov r0, r4 */
/* @0x28c72c bl 0x287428 <Json_getString> */
/* @0x28c730 mov r1, r11 */
/* @0x28c734 mov r10, r0 */
/* @0x28c738 bl 0xb6574 <strcmp@plt> */
/* @0x28c73c cmp r0, #0 */
/* @0x28c740 beq 0x28cf2c <spSkeletonJson_readSkeletonData+0x16e0> */
/* @0x28c744 ldr r1, [pc, #0x1f8] */
/* @0x28c748 mov r0, r10 */
/* @0x28c74c add r1, pc, r1 */
/* @0x28c750 bl 0xb6574 <strcmp@plt> */
/* @0x28c754 cmp r0, #0 */
/* @0x28c758 beq 0x28cf24 <spSkeletonJson_readSkeletonData+0x16d8> */
/* @0x28c75c ldr r1, [pc, #0x1e4] */
/* @0x28c760 mov r0, r10 */
/* @0x28c764 add r1, pc, r1 */
/* @0x28c768 bl 0xb6574 <strcmp@plt> */
/* @0x28c76c cmp r0, #0 */
/* @0x28c770 beq 0x28cf34 <spSkeletonJson_readSkeletonData+0x16e8> */
/* @0x28c774 ldr r1, [pc, #0x1d0] */
/* @0x28c778 mov r0, r10 */
/* @0x28c77c add r1, pc, r1 */
/* @0x28c780 bl 0xb6574 <strcmp@plt> */
/* @0x28c784 cmp r0, #0 */
/* @0x28c788 beq 0x28cfa0 <spSkeletonJson_readSkeletonData+0x1754> */
/* @0x28c78c mov r0, r10 */
/* @0x28c790 ldr r1, [sp, #0x20] */
/* @0x28c794 bl 0xb6574 <strcmp@plt> */
/* @0x28c798 cmp r0, #0 */
/* @0x28c79c bne 0x28e7f4 <spSkeletonJson_readSkeletonData+0x2fa8> */
/* @0x28c7a0 mov r2, #4 */
/* @0x28c7a4 ldr r0, [r8, #0x4] */
/* @0x28c7a8 mov r3, r6 */
/* @0x28c7ac str r5, [sp] */
/* @0x28c7b0 mov r1, r9 */
/* @0x28c7b4 bl 0x284d58 <spAttachmentLoader_createAttachment> */
/* @0x28c7b8 subs r6, r0, #0 */
/* @0x28c7bc beq 0x28cf68 <spSkeletonJson_readSkeletonData+0x171c> */
/* @0x28c7c0 ldr r3, [r6, #0x4] */
/* @0x28c7c4 cmp r3, #4 */
/* @0x28c7c8 addls pc, pc, r3, lsl #2 */
/* @0x28c7cc b 0x28cc68 <spSkeletonJson_readSkeletonData+0x141c> */
/* @0x28c7d0 b 0x28cdac <spSkeletonJson_readSkeletonData+0x1560> */
/* @0x28c7d4 b 0x28cd6c <spSkeletonJson_readSkeletonData+0x1520> */
/* @0x28c7d8 b 0x28cb20 <spSkeletonJson_readSkeletonData+0x12d4> */
/* @0x28c7dc b 0x28cb20 <spSkeletonJson_readSkeletonData+0x12d4> */
/* @0x28c7e0 b 0x28ca5c <spSkeletonJson_readSkeletonData+0x1210> */
/* @0x28c7e4 andeq sp, r10, r0, lsl r8 */
/* @0x28c7e8 andeq r12, r12, r8, ror r2 */
/* @0x28c7ec andeq r12, r12, r0, ror #4 */
/* @0x28c7f0 strdeq r12, sp, [r12], -r8 */
/* @0x28c7f4 andeq r12, r12, r0, asr r2 */
/* @0x28c7f8 andeq r12, r12, r8, asr #3 */
/* @0x28c7fc andeq r12, r12, r0, asr #3 */
/* @0x28c800 andeq r12, r12, r12, lsr #3 */
/* @0x28c804 andeq r12, r12, r12, lsl r1 */
/* @0x28c808 andeq r4, r10, r8, asr lr */
/* @0x28c80c andeq r4, r10, r4, ror lr */
/* @0x28c810 andeq r4, r10, r12, asr #28 */
/* @0x28c814 ldrdeq r4, r5, [r10], -r4 */
/* @0x28c818 andeq r4, r10, r0, asr #28 */
/* @0x28c81c ldrdeq r12, sp, [r12], -r4 */
/* @0x28c820 andeq r12, r12, r0, asr #1 */
/* @0x28c824 strheq r12, [r12], -r0 */
/* @0x28c828 andeq r12, r12, r0, lsr #1 */
/* @0x28c82c muleq r12, r0, r0 */
/* @0x28c830 andeq r12, r12, r0, lsl #1 */
/* @0x28c834 andeq r12, r12, r8, ror r0 */
/* @0x28c838 strheq r11, [r12], -r4 */
/* @0x28c83c andeq r11, r12, r12, lsl #30 */
/* @0x28c840 strdeq r11, r12, [r12], -r4 */
/* @0x28c844 andeq r4, r10, r12, lsl #26 */
/* @0x28c848 andeq r4, r10, r12, lsl #26 */
/* @0x28c84c andeq r4, r10, r12, asr #23 */
/* @0x28c850 ldrdeq r11, r12, [r12], -r4 */
/* @0x28c854 ldrdeq r11, r12, [r12], -r4 */
/* @0x28c858 strdeq r11, r12, [r12], -r12 */
/* @0x28c85c andeq r11, r12, r8, ror #29 */
/* @0x28c860 andeq r11, r12, r8, lsr lr */
/* @0x28c864 andeq r11, r12, r0, lsl lr */
/* @0x28c868 andeq r11, r12, r0, lsl #26 */
/* @0x28c86c ldrdeq r4, r5, [r10], -r8 */
/* @0x28c870 andeq r11, r12, r4, asr #26 */
/* @0x28c874 andeq r11, r12, r4, lsl #28 */
/* @0x28c878 andeq r11, r12, r12, lsr #28 */
/* @0x28c87c andeq r11, r12, r0, lsr lr */
/* @0x28c880 andeq r11, r12, r4, asr #26 */
/* @0x28c884 andeq r11, r12, r0, asr r12 */
/* @0x28c888 andeq sp, r10, r0, asr #2 */
/* @0x28c88c andeq r11, r12, r0, asr #24 */
/* @0x28c890 andeq r11, r12, r4, ror #21 */
/* @0x28c894 strheq r4, [r10], -r12 */
/* @0x28c898 andeq r11, r12, r8, lsr #22 */
/* @0x28c89c andeq r11, r12, r8, ror #23 */
/* @0x28c8a0 andeq r11, r12, r8, lsr r11 */
/* @0x28c8a4 andeq r11, r12, r12, ror r11 */
/* @0x28c8a8 andeq r4, r10, r4, lsl #14 */
/* @0x28c8ac andeq r4, r10, r12, ror #13 */
/* @0x28c8b0 andeq r11, r12, r4, lsl #20 */
/* @0x28c8b4 andeq r11, r12, r12, ror #19 */
/* @0x28c8b8 andeq r11, r12, r4, ror #19 */
/* @0x28c8bc strheq r11, [r12], -r8 */
/* @0x28c8c0 andeq r11, r12, r12, lsr #21 */
/* @0x28c8c4 andeq r11, r12, r4, lsr #21 */
/* @0x28c8c8 muleq r12, r8, r10 */
/* @0x28c8cc andeq r11, r12, r8, lsl r10 */
/* @0x28c8d0 andeq r11, r12, r8, ror #16 */
/* @0x28c8d4 andeq r4, r10, r0, asr #10 */
/* @0x28c8d8 andeq r11, r12, r12, lsr #17 */
/* @0x28c8dc andeq r11, r12, r12, ror #18 */
/* @0x28c8e0 andeq r11, r12, r8, lsr r10 */
/* @0x28c8e4 andeq r11, r12, r4, asr r9 */
/* @0x28c8e8 andeq r11, r12, r12, ror r7 */
/* @0x28c8ec andeq r11, r12, r8, lsr #18 */
/* @0x28c8f0 andeq r11, r12, r0, lsr #18 */
/* @0x28c8f4 andeq r4, r10, r4, lsl r4 */
/* @0x28c8f8 andeq r11, r12, r8, ror #17 */
/* @0x28c8fc strheq r11, [r12], -r4 */
/* @0x28c900 andeq r11, r12, r12, lsl #17 */
/* @0x28c904 muleq r12, r4, r8 */
/* @0x28c908 andeq r11, r12, r4, lsl #17 */
/* @0x28c90c andeq r11, r12, r12, ror #16 */
/* @0x28c910 andeq r11, r12, r4, asr r8 */
/* @0x28c914 andeq r11, r12, r0, ror r6 */
/* @0x28c918 andeq r11, r12, r0, lsr r8 */
/* @0x28c91c andeq r11, r12, r8, lsl r8 */
/* @0x28c920 andeq r11, r12, r12, lsl r7 */
/* @0x28c924 andeq r11, r12, r4, lsl #14 */
/* @0x28c928 strdeq r11, r12, [r12], -r8 */
/* @0x28c92c andeq r11, r12, r12, ror #9 */
/* @0x28c930 andeq r4, r10, r4, asr pc */
/* @0x28c934 andeq r4, r10, r0, asr #3 */
/* @0x28c938 andeq r11, r12, r4, asr #12 */
/* @0x28c93c andeq r9, r11, r12, ror #20 */
/* @0x28c940 muleq r12, r0, r6 */
/* @0x28c944 andeq r11, r12, r0, asr r6 */
/* @0x28c948 andeq r11, r12, r0, asr #12 */
/* @0x28c94c andeq r11, r12, r4, lsr r6 */
/* @0x28c950 muleq r12, r0, r3 */
/* @0x28c954 andeq r11, r12, r8, lsl #7 */
/* @0x28c958 andeq r11, r12, r12, asr r3 */
/* @0x28c95c andeq r11, r12, r8, lsr r0 */
/* @0x28c960 andeq r11, r12, r0, lsr r3 */
/* @0x28c964 ldrdeq r10, r11, [r12], -r0 */
/* @0x28c968 strheq r11, [r12], -r12 */
/* @0x28c96c andeq r10, r12, r4, asr #31 */
/* @0x28c970 strheq r10, [r12], -r8 */
/* @0x28c974 strheq r3, [r10], -r4 */
/* @0x28c978 ldrdeq r11, r12, [r12], -r0 */
/* @0x28c97c andeq r11, r12, r8, asr #3 */
/* @0x28c980 strheq r11, [r12], -r12 */
/* @0x28c984 andeq r11, r12, r4, ror r0 */
/* @0x28c988 andeq r10, r12, r12, lsr sp */
/* @0x28c98c andeq r3, r10, r12, lsl #21 */
/* @0x28c990 andeq r3, r10, r12, ror r10 */
/* @0x28c994 muleq r12, r4, sp */
/* @0x28c998 andeq r10, r12, r12, ror sp */
/* @0x28c99c andeq r10, r12, r0, asr sp */
/* @0x28c9a0 andeq r10, r12, r0, lsl #26 */
/* @0x28c9a4 andeq r10, r12, r12, ror #25 */
/* @0x28c9a8 andeq r10, r12, r0, ror #26 */
/* @0x28c9ac andeq r10, r12, r4, lsl sp */
/* @0x28c9b0 andeq r10, r12, r8, lsr r11 */
/* @0x28c9b4 strheq r10, [r12], -r0 */
/* @0x28c9b8 andeq r10, r12, r4, ror #21 */
/* @0x28c9bc andeq r10, r12, r4, ror #26 */
/* @0x28c9c0 andeq r10, r12, r12, lsl #21 */
/* @0x28c9c4 strdeq r10, r11, [r12], -r4 */
/* @0x28c9c8 strdeq r10, r11, [r12], -r0 */
/* @0x28c9cc strdeq r10, r11, [r12], -r4 */
/* @0x28c9d0 andeq r10, r12, r12, lsl #22 */
/* @0x28c9d4 andeq r10, r12, r4, lsl #23 */
/* @0x28c9d8 andeq r10, r12, r8, ror #23 */
/* @0x28c9dc andeq r10, r12, r12, lsr r9 */
/* @0x28c9e0 andeq r10, r12, r0, ror #24 */
/* @0x28c9e4 andeq r3, r10, r4, lsr r6 */
/* @0x28c9e8 andeq r10, r12, r4, lsl #18 */
/* @0x28c9ec andeq r3, r10, r12, lsl r6 */
/* @0x28c9f0 andeq r10, r12, r12, lsr #23 */
/* @0x28c9f4 andeq r10, r12, r8, asr #16 */
/* @0x28c9f8 muleq r12, r12, r8 */
/* @0x28c9fc muleq r12, r8, r8 */
/* @0x28ca00 strdeq r10, r11, [r12], -r12 */
/* @0x28ca04 andeq r10, r12, r0, asr #18 */
/* @0x28ca08 strdeq r10, r11, [r12], -r12 */
/* @0x28ca0c andeq r10, r12, r0, ror r10 */
/* @0x28ca10 ldrdeq r10, r11, [r12], -r12 */
/* @0x28ca14 strdeq r10, r11, [r12], -r8 */
/* @0x28ca18 andeq r3, r10, r0, lsl r3 */
/* @0x28ca1c andeq lr, r11, r12, asr #25 */
/* @0x28ca20 andeq r10, r12, r8, lsl #14 */
/* @0x28ca24 andeq r3, r10, r0, lsr r4 */
/* @0x28ca28 strdeq r10, r11, [r12], -r12 */
/* @0x28ca2c andeq r10, r12, r12, asr r8 */
/* @0x28ca30 andeq r10, r12, r8, asr r8 */
/* @0x28ca34 andeq r10, r12, r8, asr r8 */
/* @0x28ca38 andeq r10, r12, r12, asr r8 */
/* @0x28ca3c andeq lr, r11, r4, asr #22 */
/* @0x28ca40 andeq r3, r10, r8, lsl r1 */
/* @0x28ca44 andeq r3, r10, r8, lsl r1 */
/* @0x28ca48 andeq lr, r11, r4, ror #18 */
/* @0x28ca4c andeq r10, r12, r4, lsr #8 */
/* @0x28ca50 andeq r10, r12, r12, lsl #8 */
/* @0x28ca54 andeq lr, r11, r4, asr #17 */
/* @0x28ca58 andeq r10, r12, r12, asr #8 */
/* @0x28ca5c ldr r1, [pc, #-0x114] */
/* @0x28ca60 mov r2, #0 */
/* @0x28ca64 mov r0, r4 */
/* @0x28ca68 add r1, pc, r1 */
/* @0x28ca6c bl 0x287460 <Json_getInt> */
/* @0x28ca70 ldr r1, [pc, #-0x124] */
/* @0x28ca74 mov r2, #1 */
/* @0x28ca78 add r1, pc, r1 */
/* @0x28ca7c str r0, [r6, #0x2c] */
/* @0x28ca80 mov r0, r4 */
/* @0x28ca84 bl 0x287460 <Json_getInt> */
/* @0x28ca88 ldr r1, [pc, #-0x138] */
/* @0x28ca8c mov r2, #0 */
/* @0x28ca90 add r1, pc, r1 */
/* @0x28ca94 str r0, [r6, #0x30] */
/* @0x28ca98 mov r0, r4 */
/* @0x28ca9c bl 0x287460 <Json_getInt> */
/* @0x28caa0 mov r1, r4 */
/* @0x28caa4 mov r2, r6 */
/* @0x28caa8 mov r5, r0 */
/* @0x28caac mov r0, r8 */
/* @0x28cab0 lsl r3, r5, #1 */
/* @0x28cab4 bl 0x28b3fc <spSkeletonData_findPathConstraint+0x10c> */
/* @0x28cab8 ldr r1, [sp, #0x38] */
/* @0x28cabc movw r2, #0x3d9 */
/* @0x28cac0 smull r1, r0, r1, r5 */
/* @0x28cac4 ldr r1, [pc, #-0x170] */
/* @0x28cac8 add r1, pc, r1 */
/* @0x28cacc sub r0, r0, r5, asr #31 */
/* @0x28cad0 str r0, [r6, #0x24] */
/* @0x28cad4 lsl r0, r0, #2 */
/* @0x28cad8 bl 0x285c10 <_malloc> */
/* @0x28cadc ldr r1, [pc, #-0x184] */
/* @0x28cae0 add r1, pc, r1 */
/* @0x28cae4 str r0, [r6, #0x28] */
/* @0x28cae8 mov r0, r4 */
/* @0x28caec bl 0x2873c4 <Json_getItem> */
/* @0x28caf0 ldr r3, [r0, #0x4] */
/* @0x28caf4 cmp r3, #0 */
/* @0x28caf8 beq 0x28cc68 <spSkeletonJson_readSkeletonData+0x141c> */
/* @0x28cafc ldr r2, [r6, #0x28] */
/* @0x28cb00 vldr s14, [r3, #24] */
/* @0x28cb04 vldr s15, [r8] */
/* @0x28cb08 vmul.f32 s15, s14, s15 */
/* @0x28cb0c ldr r3, [r3] */
/* @0x28cb10 cmp r3, #0 */
/* @0x28cb14 vstmia r2!, {s15} */
/* @0x28cb18 bne 0x28cb00 <spSkeletonJson_readSkeletonData+0x12b4> */
/* @0x28cb1c b 0x28cc68 <spSkeletonJson_readSkeletonData+0x141c> */
/* @0x28cb20 mov r0, r5 */
/* @0x28cb24 bl 0xb6538 <strlen@plt> */
/* @0x28cb28 ldr r1, [pc, #-0x1cc] */
/* @0x28cb2c movw r2, #0x395 */
/* @0x28cb30 add r1, pc, r1 */
/* @0x28cb34 add r0, r0, #1 */
/* @0x28cb38 bl 0x285c10 <_malloc> */
/* @0x28cb3c mov r1, r5 */
/* @0x28cb40 str r0, [r6, #0x54] */
/* @0x28cb44 bl 0xb65a4 <strcpy@plt> */
/* @0x28cb48 ldr r1, [pc, #-0x1e8] */
/* @0x28cb4c mov r0, r4 */
/* @0x28cb50 mov r2, #0 */
/* @0x28cb54 add r1, pc, r1 */
/* @0x28cb58 bl 0x287428 <Json_getString> */
/* @0x28cb5c subs r5, r0, #0 */
/* @0x28cb60 beq 0x28cba0 <spSkeletonJson_readSkeletonData+0x1354> */
/* @0x28cb64 mov r1, #0 */
/* @0x28cb68 bl 0x28b680 <spSkeletonData_findPathConstraint+0x390> */
/* @0x28cb6c mov r0, r5 */
/* @0x28cb70 mov r1, #1 */
/* @0x28cb74 vstr s0, [r6, #104] */
/* @0x28cb78 bl 0x28b680 <spSkeletonData_findPathConstraint+0x390> */
/* @0x28cb7c mov r0, r5 */
/* @0x28cb80 mov r1, #2 */
/* @0x28cb84 vstr s0, [r6, #108] */
/* @0x28cb88 bl 0x28b680 <spSkeletonData_findPathConstraint+0x390> */
/* @0x28cb8c mov r0, r5 */
/* @0x28cb90 mov r1, #3 */
/* @0x28cb94 vstr s0, [r6, #112] */
/* @0x28cb98 bl 0x28b680 <spSkeletonData_findPathConstraint+0x390> */
/* @0x28cb9c vstr s0, [r6, #116] */
/* @0x28cba0 ldr r1, [pc, #-0x23c] */
/* @0x28cba4 mov r2, #1107296256 */
/* @0x28cba8 mov r0, r4 */
/* @0x28cbac add r1, pc, r1 */
/* @0x28cbb0 bl 0x287444 <Json_getFloat> */
/* @0x28cbb4 vldr s15, [r8] */
/* @0x28cbb8 ldr r1, [pc, #-0x250] */
/* @0x28cbbc mov r2, #1107296256 */
/* @0x28cbc0 add r1, pc, r1 */
/* @0x28cbc4 vmov s14, r0 */
/* @0x28cbc8 mov r0, r4 */
/* @0x28cbcc vmul.f32 s15, s14, s15 */
/* @0x28cbd0 vstr s15, [r6, #140] */
/* @0x28cbd4 bl 0x287444 <Json_getFloat> */
/* @0x28cbd8 vldr s15, [r8] */
/* @0x28cbdc ldr r1, [pc, #-0x270] */
/* @0x28cbe0 add r1, pc, r1 */
/* @0x28cbe4 vmov s14, r0 */
/* @0x28cbe8 mov r0, r4 */
/* @0x28cbec vmul.f32 s15, s14, s15 */
/* @0x28cbf0 vstr s15, [r6, #144] */
/* @0x28cbf4 bl 0x2873c4 <Json_getItem> */
/* @0x28cbf8 subs r5, r0, #0 */
/* @0x28cbfc mov r0, r4 */
/* @0x28cc00 beq 0x28d008 <spSkeletonJson_readSkeletonData+0x17bc> */
/* @0x28cc04 ldr r1, [pc, #-0x294] */
/* @0x28cc08 mov r2, #1 */
/* @0x28cc0c add r1, pc, r1 */
/* @0x28cc10 bl 0x287460 <Json_getInt> */
/* @0x28cc14 ldr r1, [pc, #-0x2a0] */
/* @0x28cc18 mov r2, #0 */
/* @0x28cc1c add r1, pc, r1 */
/* @0x28cc20 str r0, [r6, #0x80] */
/* @0x28cc24 mov r0, r4 */
/* @0x28cc28 bl 0x287428 <Json_getString> */
/* @0x28cc2c ldr r2, [r8, #0x10] */
/* @0x28cc30 ldr r1, [r8, #0x14] */
/* @0x28cc34 ldr r10, [r5, #0x10] */
/* @0x28cc38 cmp r2, r1 */
/* @0x28cc3c mov r3, r0 */
/* @0x28cc40 beq 0x28cfa8 <spSkeletonJson_readSkeletonData+0x175c> */
/* @0x28cc44 ldr r1, [r8, #0x18] */
/* @0x28cc48 add r0, r1, r2, lsl #4 */
/* @0x28cc4c add r12, r2, #1 */
/* @0x28cc50 str r12, [r8, #0x10] */
/* @0x28cc54 str r3, [r0, #0x4] */
/* @0x28cc58 ldr r3, [sp, #0x28] */
/* @0x28cc5c str r6, [r0, #0xc] */
/* @0x28cc60 str r3, [r0, #0x8] */
/* @0x28cc64 str r10, [r1, r2, lsl #4] */
/* @0x28cc68 mov r2, r7 */
/* @0x28cc6c mov r3, r6 */
/* @0x28cc70 mov r0, r9 */
/* @0x28cc74 ldr r1, [sp, #0x28] */
/* @0x28cc78 bl 0x28ecd8 <spSkin_addAttachment> */
/* @0x28cc7c ldr r4, [r4] */
/* @0x28cc80 cmp r4, #0 */
/* @0x28cc84 bne 0x28c6e8 <spSkeletonJson_readSkeletonData+0xe9c> */
/* @0x28cc88 ldr r0, [sp, #0x1c] */
/* @0x28cc8c ldr r0, [r0] */
/* @0x28cc90 cmp r0, #0 */
/* @0x28cc94 str r0, [sp, #0x1c] */
/* @0x28cc98 bne 0x28c6c4 <spSkeletonJson_readSkeletonData+0xe78> */
/* @0x28cc9c ldr r11, [sp, #0x34] */
/* @0x28cca0 ldr r0, [sp, #0x18] */
/* @0x28cca4 ldr r0, [r0] */
/* @0x28cca8 cmp r0, #0 */
/* @0x28ccac str r0, [sp, #0x18] */
/* @0x28ccb0 bne 0x28c664 <spSkeletonJson_readSkeletonData+0xe18> */
/* @0x28ccb4 mov r9, r11 */
/* @0x28ccb8 ldr r3, [r8, #0x10] */
/* @0x28ccbc cmp r3, #0 */
/* @0x28ccc0 movgt r6, #0 */
/* @0x28ccc4 bgt 0x28cd0c <spSkeletonJson_readSkeletonData+0x14c0> */
/* @0x28ccc8 b 0x28d19c <spSkeletonJson_readSkeletonData+0x1950> */
/* @0x28cccc ldr r1, [r4, #0x8] */
/* @0x28ccd0 ldr r2, [r10, r7] */
/* @0x28ccd4 bl 0x28ed00 <spSkin_getAttachment> */
/* @0x28ccd8 cmp r0, #0 */
/* @0x28ccdc mov r1, r0 */
/* @0x28cce0 beq 0x28e880 <spSkeletonJson_readSkeletonData+0x3034> */
/* @0x28cce4 ldr r0, [r4, #0xc] */
/* @0x28cce8 bl 0x287654 <spMeshAttachment_setParentMesh> */
/* @0x28ccec ldr r0, [r4, #0xc] */
/* @0x28ccf0 bl 0x287538 <spMeshAttachment_updateUVs> */
/* @0x28ccf4 ldr r1, [r4, #0xc] */
/* @0x28ccf8 ldr r0, [r8, #0x4] */
/* @0x28ccfc bl 0x284db8 <spAttachmentLoader_configureAttachment> */
/* @0x28cd00 ldr r3, [r8, #0x10] */
/* @0x28cd04 cmp r3, r6 */
/* @0x28cd08 ble 0x28d19c <spSkeletonJson_readSkeletonData+0x1950> */
/* @0x28cd0c ldr r10, [r8, #0x18] */
/* @0x28cd10 lsl r7, r6, #4 */
/* @0x28cd14 mov r0, r9 */
/* @0x28cd18 add r4, r10, r7 */
/* @0x28cd1c ldr r1, [r4, #0x4] */
/* @0x28cd20 cmp r1, #0 */
/* @0x28cd24 ldreq r5, [r9, #0x28] */
/* @0x28cd28 beq 0x28cd34 <spSkeletonJson_readSkeletonData+0x14e8> */
/* @0x28cd2c bl 0x28b124 <spSkeletonData_findSkin> */
/* @0x28cd30 mov r5, r0 */
/* @0x28cd34 cmp r5, #0 */
/* @0x28cd38 add r6, r6, #1 */
/* @0x28cd3c mov r0, r5 */
/* @0x28cd40 bne 0x28cccc <spSkeletonJson_readSkeletonData+0x1480> */
/* @0x28cd44 mov r0, r9 */
/* @0x28cd48 bl 0x28adf8 <spSkeletonData_dispose> */
/* @0x28cd4c ldr r2, [pc, #-0x3d4] */
/* @0x28cd50 mov r0, r8 */
/* @0x28cd54 mov r1, r5 */
/* @0x28cd58 ldr r3, [r4, #0x4] */
/* @0x28cd5c add r2, pc, r2 */
/* @0x28cd60 bl 0x28b784 <_spSkeletonJson_setError> */
/* @0x28cd64 mov r0, r5 */
/* @0x28cd68 b 0x28bdcc <spSkeletonJson_readSkeletonData+0x580> */
/* @0x28cd6c ldr r1, [pc, #-0x3f0] */
/* @0x28cd70 mov r2, #0 */
/* @0x28cd74 mov r0, r4 */
/* @0x28cd78 add r1, pc, r1 */
/* @0x28cd7c bl 0x287460 <Json_getInt> */
/* @0x28cd80 mov r1, r4 */
/* @0x28cd84 mov r2, r6 */
/* @0x28cd88 lsl r5, r0, #1 */
/* @0x28cd8c mov r0, r8 */
/* @0x28cd90 mov r3, r5 */
/* @0x28cd94 bl 0x28b3fc <spSkeletonData_findPathConstraint+0x10c> */
/* @0x28cd98 str r5, [r6, #0x18] */
/* @0x28cd9c ldr r0, [r8, #0x4] */
/* @0x28cda0 mov r1, r6 */
/* @0x28cda4 bl 0x284db8 <spAttachmentLoader_configureAttachment> */
/* @0x28cda8 b 0x28cc68 <spSkeletonJson_readSkeletonData+0x141c> */
/* @0x28cdac cmp r5, #0 */
/* @0x28cdb0 beq 0x28cddc <spSkeletonJson_readSkeletonData+0x1590> */
/* @0x28cdb4 mov r0, r5 */
/* @0x28cdb8 bl 0xb6538 <strlen@plt> */
/* @0x28cdbc ldr r1, [pc, #-0x43c] */
/* @0x28cdc0 movw r2, #0x37b */
/* @0x28cdc4 add r1, pc, r1 */
/* @0x28cdc8 add r0, r0, #1 */
/* @0x28cdcc bl 0x285c10 <_malloc> */
/* @0x28cdd0 mov r1, r5 */
/* @0x28cdd4 str r0, [r6, #0x10] */
/* @0x28cdd8 bl 0xb65a4 <strcpy@plt> */
/* @0x28cddc ldr r1, [pc, #-0x458] */
/* @0x28cde0 mov r2, #0 */
/* @0x28cde4 mov r0, r4 */
/* @0x28cde8 add r1, pc, r1 */
/* @0x28cdec bl 0x287444 <Json_getFloat> */
/* @0x28cdf0 vldr s15, [r8] */
/* @0x28cdf4 ldr r1, [pc, #-0x46c] */
/* @0x28cdf8 mov r2, #0 */
/* @0x28cdfc add r1, pc, r1 */
/* @0x28ce00 vmov s14, r0 */
/* @0x28ce04 mov r0, r4 */
/* @0x28ce08 vmul.f32 s15, s14, s15 */
/* @0x28ce0c vstr s15, [r6, #20] */
/* @0x28ce10 bl 0x287444 <Json_getFloat> */
/* @0x28ce14 vldr s15, [r8] */
/* @0x28ce18 ldr r1, [pc, #-0x48c] */
/* @0x28ce1c mov r2, #1065353216 */
/* @0x28ce20 add r1, pc, r1 */
/* @0x28ce24 vmov s14, r0 */
/* @0x28ce28 mov r0, r4 */
/* @0x28ce2c vmul.f32 s15, s14, s15 */
/* @0x28ce30 vstr s15, [r6, #24] */
/* @0x28ce34 bl 0x287444 <Json_getFloat> */
/* @0x28ce38 ldr r1, [pc, #-0x4a8] */
/* @0x28ce3c mov r2, #1065353216 */
/* @0x28ce40 add r1, pc, r1 */
/* @0x28ce44 str r0, [r6, #0x1c] */
/* @0x28ce48 mov r0, r4 */
/* @0x28ce4c bl 0x287444 <Json_getFloat> */
/* @0x28ce50 ldr r1, [pc, #-0x4bc] */
/* @0x28ce54 mov r2, #0 */
/* @0x28ce58 add r1, pc, r1 */
/* @0x28ce5c str r0, [r6, #0x20] */
/* @0x28ce60 mov r0, r4 */
/* @0x28ce64 bl 0x287444 <Json_getFloat> */
/* @0x28ce68 ldr r1, [pc, #-0x4d0] */
/* @0x28ce6c mov r2, #1107296256 */
/* @0x28ce70 add r1, pc, r1 */
/* @0x28ce74 str r0, [r6, #0x24] */
/* @0x28ce78 mov r0, r4 */
/* @0x28ce7c bl 0x287444 <Json_getFloat> */
/* @0x28ce80 vldr s15, [r8] */
/* @0x28ce84 ldr r1, [pc, #-0x4e8] */
/* @0x28ce88 mov r2, #1107296256 */
/* @0x28ce8c add r1, pc, r1 */
/* @0x28ce90 vmov s14, r0 */
/* @0x28ce94 mov r0, r4 */
/* @0x28ce98 vmul.f32 s15, s14, s15 */
/* @0x28ce9c vstr s15, [r6, #40] */
/* @0x28cea0 bl 0x287444 <Json_getFloat> */
/* @0x28cea4 vldr s15, [r8] */
/* @0x28cea8 ldr r1, [pc, #-0x508] */
/* @0x28ceac mov r2, #0 */
/* @0x28ceb0 add r1, pc, r1 */
/* @0x28ceb4 vmov s14, r0 */
/* @0x28ceb8 mov r0, r4 */
/* @0x28cebc vmul.f32 s15, s14, s15 */
/* @0x28cec0 vstr s15, [r6, #44] */
/* @0x28cec4 bl 0x287428 <Json_getString> */
/* @0x28cec8 subs r5, r0, #0 */
/* @0x28cecc beq 0x28cf0c <spSkeletonJson_readSkeletonData+0x16c0> */
/* @0x28ced0 mov r1, #0 */
/* @0x28ced4 bl 0x28b680 <spSkeletonData_findPathConstraint+0x390> */
/* @0x28ced8 mov r0, r5 */
/* @0x28cedc mov r1, #1 */
/* @0x28cee0 vstr s0, [r6, #48] */
/* @0x28cee4 bl 0x28b680 <spSkeletonData_findPathConstraint+0x390> */
/* @0x28cee8 mov r0, r5 */
/* @0x28ceec mov r1, #2 */
/* @0x28cef0 vstr s0, [r6, #52] */
/* @0x28cef4 bl 0x28b680 <spSkeletonData_findPathConstraint+0x390> */
/* @0x28cef8 mov r0, r5 */
/* @0x28cefc mov r1, #3 */
/* @0x28cf00 vstr s0, [r6, #56] */
/* @0x28cf04 bl 0x28b680 <spSkeletonData_findPathConstraint+0x390> */
/* @0x28cf08 vstr s0, [r6, #60] */
/* @0x28cf0c mov r0, r6 */
/* @0x28cf10 bl 0x289040 <spRegionAttachment_updateOffset> */
/* @0x28cf14 ldr r0, [r8, #0x4] */
/* @0x28cf18 mov r1, r6 */
/* @0x28cf1c bl 0x284db8 <spAttachmentLoader_configureAttachment> */
/* @0x28cf20 b 0x28cc68 <spSkeletonJson_readSkeletonData+0x141c> */
/* @0x28cf24 mov r2, #2 */
/* @0x28cf28 b 0x28c7a4 <spSkeletonJson_readSkeletonData+0xf58> */
/* @0x28cf2c mov r2, r0 */
/* @0x28cf30 b 0x28c7a4 <spSkeletonJson_readSkeletonData+0xf58> */
/* @0x28cf34 mov r2, #3 */
/* @0x28cf38 b 0x28c7a4 <spSkeletonJson_readSkeletonData+0xf58> */
/* @0x28cf3c mov r4, r0 */
/* @0x28cf40 mov r0, r9 */
/* @0x28cf44 bl 0x28adf8 <spSkeletonData_dispose> */
/* @0x28cf48 ldr r2, [pc, #-0x5a4] */
/* @0x28cf4c mov r0, r8 */
/* @0x28cf50 ldr r1, [sp, #0x24] */
/* @0x28cf54 add r2, pc, r2 */
/* @0x28cf58 ldr r3, [r4, #0x1c] */
/* @0x28cf5c bl 0x28b784 <_spSkeletonJson_setError> */
/* @0x28cf60 mov r0, r4 */
/* @0x28cf64 b 0x28bdcc <spSkeletonJson_readSkeletonData+0x580> */
/* @0x28cf68 ldr r3, [r8, #0x4] */
/* @0x28cf6c ldr r3, [r3] */
/* @0x28cf70 cmp r3, #0 */
/* @0x28cf74 beq 0x28cc7c <spSkeletonJson_readSkeletonData+0x1430> */
/* @0x28cf78 ldr r9, [sp, #0x34] */
/* @0x28cf7c mov r0, r9 */
/* @0x28cf80 bl 0x28adf8 <spSkeletonData_dispose> */
/* @0x28cf84 ldr r3, [r8, #0x4] */
/* @0x28cf88 mov r0, r8 */
/* @0x28cf8c ldr r1, [sp, #0x24] */
/* @0x28cf90 ldm r3, {r2, r3} */
/* @0x28cf94 bl 0x28b784 <_spSkeletonJson_setError> */
/* @0x28cf98 mov r0, r6 */
/* @0x28cf9c b 0x28bdcc <spSkeletonJson_readSkeletonData+0x580> */
/* @0x28cfa0 mov r2, #1 */
/* @0x28cfa4 b 0x28c7a4 <spSkeletonJson_readSkeletonData+0xf58> */
/* @0x28cfa8 lsl r1, r2, #1 */
/* @0x28cfac cmp r1, #7 */
/* @0x28cfb0 strgt r1, [r8, #0x14] */
/* @0x28cfb4 ldr r1, [pc, #-0x60c] */
/* @0x28cfb8 lslgt r0, r2, #5 */
/* @0x28cfbc movle r2, #8 */
/* @0x28cfc0 movle r0, #128 */
/* @0x28cfc4 strle r2, [r8, #0x14] */
/* @0x28cfc8 add r1, pc, r1 */
/* @0x28cfcc mov r2, #136 */
/* @0x28cfd0 str r3, [sp, #0x10] */
/* @0x28cfd4 bl 0x285c10 <_malloc> */
/* @0x28cfd8 ldr r2, [r8, #0x10] */
/* @0x28cfdc ldr r1, [r8, #0x18] */
/* @0x28cfe0 lsl r2, r2, #4 */
/* @0x28cfe4 mov r5, r0 */
/* @0x28cfe8 bl 0xb65bc <memcpy@plt> */
/* @0x28cfec ldr r0, [r8, #0x18] */
/* @0x28cff0 bl 0x285c80 <_free> */
/* @0x28cff4 ldr r2, [r8, #0x10] */
/* @0x28cff8 mov r1, r5 */
/* @0x28cffc str r5, [r8, #0x18] */
/* @0x28d000 ldr r3, [sp, #0x10] */
/* @0x28d004 b 0x28cc48 <spSkeletonJson_readSkeletonData+0x13fc> */
/* @0x28d008 ldr r1, [pc, #-0x65c] */
/* @0x28d00c add r1, pc, r1 */
/* @0x28d010 bl 0x2873c4 <Json_getItem> */
/* @0x28d014 ldr r1, [pc, #-0x664] */
/* @0x28d018 movw r2, #0x3a7 */
/* @0x28d01c add r1, pc, r1 */
/* @0x28d020 mov r5, r0 */
/* @0x28d024 ldr r0, [r0, #0xc] */
/* @0x28d028 str r0, [r6, #0x60] */
/* @0x28d02c lsl r0, r0, #1 */
/* @0x28d030 bl 0x285c10 <_malloc> */
/* @0x28d034 ldr r3, [r5, #0x4] */
/* @0x28d038 cmp r3, #0 */
/* @0x28d03c str r0, [r6, #0x64] */
/* @0x28d040 subne r2, r0, #2 */
/* @0x28d044 beq 0x28d05c <spSkeletonJson_readSkeletonData+0x1810> */
/* @0x28d048 ldr r1, [r3, #0x14] */
/* @0x28d04c ldr r3, [r3] */
/* @0x28d050 cmp r3, #0 */
/* @0x28d054 strh r1, [r2, #2]! */
/* @0x28d058 bne 0x28d048 <spSkeletonJson_readSkeletonData+0x17fc> */
/* @0x28d05c ldr r1, [pc, #-0x6a8] */
/* @0x28d060 mov r0, r4 */
/* @0x28d064 add r1, pc, r1 */
/* @0x28d068 bl 0x2873c4 <Json_getItem> */
/* @0x28d06c ldr r1, [pc, #-0x6b4] */
/* @0x28d070 movw r2, #0x3ad */
/* @0x28d074 add r1, pc, r1 */
/* @0x28d078 ldr r5, [r0, #0xc] */
/* @0x28d07c mov r10, r0 */
/* @0x28d080 lsl r0, r5, #2 */
/* @0x28d084 bl 0x285c10 <_malloc> */
/* @0x28d088 ldr r2, [r10, #0x4] */
/* @0x28d08c cmp r2, #0 */
/* @0x28d090 str r0, [r6, #0x58] */
/* @0x28d094 movne r3, r0 */
/* @0x28d098 beq 0x28d0b0 <spSkeletonJson_readSkeletonData+0x1864> */
/* @0x28d09c ldr r1, [r2, #0x18] */
/* @0x28d0a0 ldr r2, [r2] */
/* @0x28d0a4 cmp r2, #0 */
/* @0x28d0a8 str r1, [r3], #4 */
/* @0x28d0ac bne 0x28d09c <spSkeletonJson_readSkeletonData+0x1850> */
/* @0x28d0b0 mov r3, r5 */
/* @0x28d0b4 mov r1, r4 */
/* @0x28d0b8 mov r2, r6 */
/* @0x28d0bc mov r0, r8 */
/* @0x28d0c0 bl 0x28b3fc <spSkeletonData_findPathConstraint+0x10c> */
/* @0x28d0c4 mov r0, r6 */
/* @0x28d0c8 bl 0x287538 <spMeshAttachment_updateUVs> */
/* @0x28d0cc ldr r1, [pc, #-0x710] */
/* @0x28d0d0 mov r2, #0 */
/* @0x28d0d4 mov r0, r4 */
/* @0x28d0d8 add r1, pc, r1 */
/* @0x28d0dc bl 0x287460 <Json_getInt> */
/* @0x28d0e0 ldr r1, [pc, #-0x720] */
/* @0x28d0e4 add r1, pc, r1 */
/* @0x28d0e8 str r0, [r6, #0x78] */
/* @0x28d0ec mov r0, r4 */
/* @0x28d0f0 bl 0x2873c4 <Json_getItem> */
/* @0x28d0f4 subs r5, r0, #0 */
/* @0x28d0f8 beq 0x28cd9c <spSkeletonJson_readSkeletonData+0x1550> */
/* @0x28d0fc ldr r0, [r5, #0xc] */
/* @0x28d100 movw r2, #0x3ba */
/* @0x28d104 ldr r1, [pc, #-0x740] */
/* @0x28d108 str r0, [r6, #0x84] */
/* @0x28d10c add r1, pc, r1 */
/* @0x28d110 lsl r0, r0, #2 */
/* @0x28d114 bl 0x285c10 <_malloc> */
/* @0x28d118 ldr r3, [r5, #0x4] */
/* @0x28d11c cmp r3, #0 */
/* @0x28d120 str r0, [r6, #0x88] */
/* @0x28d124 beq 0x28cd9c <spSkeletonJson_readSkeletonData+0x1550> */
/* @0x28d128 sub r2, r0, #4 */
/* @0x28d12c ldr r1, [r3, #0x14] */
/* @0x28d130 ldr r3, [r3] */
/* @0x28d134 cmp r3, #0 */
/* @0x28d138 str r1, [r2, #0x4]! */
/* @0x28d13c bne 0x28d12c <spSkeletonJson_readSkeletonData+0x18e0> */
/* @0x28d140 b 0x28cd9c <spSkeletonJson_readSkeletonData+0x1550> */
/* @0x28d144 mov r4, r0 */
/* @0x28d148 mov r0, r9 */
/* @0x28d14c bl 0x28adf8 <spSkeletonData_dispose> */
/* @0x28d150 ldr r2, [pc, #-0x788] */
/* @0x28d154 mov r0, r8 */
/* @0x28d158 ldr r1, [sp, #0x24] */
/* @0x28d15c add r2, pc, r2 */
/* @0x28d160 ldr r3, [r4, #0x1c] */
/* @0x28d164 bl 0x28b784 <_spSkeletonJson_setError> */
/* @0x28d168 mov r0, r4 */
/* @0x28d16c b 0x28bdcc <spSkeletonJson_readSkeletonData+0x580> */
/* @0x28d170 mov r4, r0 */
/* @0x28d174 mov r0, r9 */
/* @0x28d178 bl 0x28adf8 <spSkeletonData_dispose> */
/* @0x28d17c ldr r2, [pc, #-0x7b0] */
/* @0x28d180 mov r0, r8 */
/* @0x28d184 ldr r1, [sp, #0x24] */
/* @0x28d188 add r2, pc, r2 */
/* @0x28d18c ldr r3, [r4, #0x1c] */
/* @0x28d190 bl 0x28b784 <_spSkeletonJson_setError> */
/* @0x28d194 mov r0, r4 */
/* @0x28d198 b 0x28bdcc <spSkeletonJson_readSkeletonData+0x580> */
/* @0x28d19c ldr r1, [pc, #-0x7cc] */
/* @0x28d1a0 ldr r0, [sp, #0x24] */
/* @0x28d1a4 add r1, pc, r1 */
/* @0x28d1a8 bl 0x2873c4 <Json_getItem> */
/* @0x28d1ac subs r4, r0, #0 */
/* @0x28d1b0 beq 0x28d290 <spSkeletonJson_readSkeletonData+0x1a44> */
/* @0x28d1b4 ldr r0, [r4, #0xc] */
/* @0x28d1b8 movw r2, #0x404 */
/* @0x28d1bc ldr r1, [pc, #-0x7e8] */
/* @0x28d1c0 str r0, [r9, #0x2c] */
/* @0x28d1c4 add r1, pc, r1 */
/* @0x28d1c8 lsl r0, r0, #2 */
/* @0x28d1cc bl 0x285c10 <_malloc> */
/* @0x28d1d0 ldr r4, [r4, #0x4] */
/* @0x28d1d4 cmp r4, #0 */
/* @0x28d1d8 str r0, [r9, #0x30] */
/* @0x28d1dc beq 0x28d290 <spSkeletonJson_readSkeletonData+0x1a44> */
/* @0x28d1e0 ldr r3, [pc, #-0x808] */
/* @0x28d1e4 mov r10, #0 */
/* @0x28d1e8 ldr r7, [pc, #-0x80c] */
/* @0x28d1ec ldr r6, [pc, #-0x80c] */
/* @0x28d1f0 add r3, pc, r3 */
/* @0x28d1f4 add r7, pc, r7 */
/* @0x28d1f8 str r3, [sp, #0x18] */
/* @0x28d1fc add r6, pc, r6 */
/* @0x28d200 ldr r3, [pc, #-0x81c] */
/* @0x28d204 add r3, pc, r3 */
/* @0x28d208 str r3, [sp, #0x1c] */
/* @0x28d20c ldr r0, [r4, #0x1c] */
/* @0x28d210 bl 0x285b94 <spEventData_create> */
/* @0x28d214 ldr r1, [sp, #0x18] */
/* @0x28d218 mov r2, #0 */
/* @0x28d21c mov r5, r0 */
/* @0x28d220 mov r0, r4 */
/* @0x28d224 bl 0x287460 <Json_getInt> */
/* @0x28d228 ldr r1, [sp, #0x1c] */
/* @0x28d22c mov r2, #0 */
/* @0x28d230 str r0, [r5, #0x4] */
/* @0x28d234 mov r0, r4 */
/* @0x28d238 bl 0x287444 <Json_getFloat> */
/* @0x28d23c mov r1, r7 */
/* @0x28d240 mov r2, #0 */
/* @0x28d244 str r0, [r5, #0x8] */
/* @0x28d248 mov r0, r4 */
/* @0x28d24c bl 0x287428 <Json_getString> */
/* @0x28d250 subs r11, r0, #0 */
/* @0x28d254 beq 0x28d278 <spSkeletonJson_readSkeletonData+0x1a2c> */
/* @0x28d258 bl 0xb6538 <strlen@plt> */
/* @0x28d25c mov r1, r6 */
/* @0x28d260 movw r2, #0x40a */
/* @0x28d264 add r0, r0, #1 */
/* @0x28d268 bl 0x285c10 <_malloc> */
/* @0x28d26c mov r1, r11 */
/* @0x28d270 str r0, [r5, #0xc] */
/* @0x28d274 bl 0xb65a4 <strcpy@plt> */
/* @0x28d278 ldr r3, [r9, #0x30] */
/* @0x28d27c str r5, [r3, r10] */
/* @0x28d280 add r10, r10, #4 */
/* @0x28d284 ldr r4, [r4] */
/* @0x28d288 cmp r4, #0 */
/* @0x28d28c bne 0x28d20c <spSkeletonJson_readSkeletonData+0x19c0> */
/* @0x28d290 ldr r1, [pc, #-0x8a8] */
/* @0x28d294 ldr r0, [sp, #0x24] */
/* @0x28d298 add r1, pc, r1 */
/* @0x28d29c bl 0x2873c4 <Json_getItem> */
/* @0x28d2a0 subs r4, r0, #0 */
/* @0x28d2a4 beq 0x28e7a4 <spSkeletonJson_readSkeletonData+0x2f58> */
/* @0x28d2a8 ldr r0, [r4, #0xc] */
/* @0x28d2ac movw r2, #0x413 */
/* @0x28d2b0 ldr r1, [pc, #-0x8c4] */
/* @0x28d2b4 lsl r0, r0, #2 */
/* @0x28d2b8 add r1, pc, r1 */
/* @0x28d2bc bl 0x285c10 <_malloc> */
/* @0x28d2c0 ldr r4, [r4, #0x4] */
/* @0x28d2c4 cmp r4, #0 */
/* @0x28d2c8 str r4, [sp, #0x1c] */
/* @0x28d2cc str r0, [r9, #0x38] */
/* @0x28d2d0 beq 0x28e7a4 <spSkeletonJson_readSkeletonData+0x2f58> */
/* @0x28d2d4 ldr r0, [pc, #-0x8e4] */
/* @0x28d2d8 movw r1, #0x5556 */
/* @0x28d2dc ldr r2, [pc, #-0x8e8] */
/* @0x28d2e0 movt r1, #0x5555 */
/* @0x28d2e4 add r0, pc, r0 */
/* @0x28d2e8 ldr r3, [pc, #-0x8f0] */
/* @0x28d2ec str r0, [sp, #0x64] */
/* @0x28d2f0 add r2, pc, r2 */
/* @0x28d2f4 ldr r0, [pc, #-0x8f8] */
/* @0x28d2f8 add r3, pc, r3 */
/* @0x28d2fc str r2, [sp, #0x68] */
/* @0x28d300 add r0, pc, r0 */
/* @0x28d304 str r1, [sp, #0x60] */
/* @0x28d308 str r3, [sp, #0x6c] */
/* @0x28d30c str r0, [sp, #0x70] */
/* @0x28d310 str r9, [sp, #0x18] */
/* @0x28d314 str r8, [sp, #0x20] */
/* @0x28d318 ldr r1, [sp, #0x64] */
/* @0x28d31c ldr r0, [sp, #0x1c] */
/* @0x28d320 bl 0x2873c4 <Json_getItem> */
/* @0x28d324 ldr r1, [sp, #0x68] */
/* @0x28d328 str r0, [sp, #0x30] */
/* @0x28d32c ldr r0, [sp, #0x1c] */
/* @0x28d330 bl 0x2873c4 <Json_getItem> */
/* @0x28d334 ldr r1, [sp, #0x6c] */
/* @0x28d338 mov r4, r0 */
/* @0x28d33c ldr r0, [sp, #0x1c] */
/* @0x28d340 bl 0x2873c4 <Json_getItem> */
/* @0x28d344 ldr r1, [sp, #0x70] */
/* @0x28d348 str r0, [sp, #0x34] */
/* @0x28d34c ldr r0, [sp, #0x1c] */
/* @0x28d350 bl 0x2873c4 <Json_getItem> */
/* @0x28d354 ldr r1, [pc, #-0x954] */
/* @0x28d358 add r1, pc, r1 */
/* @0x28d35c str r0, [sp, #0x38] */
/* @0x28d360 ldr r0, [sp, #0x1c] */
/* @0x28d364 bl 0x2873c4 <Json_getItem> */
/* @0x28d368 ldr r1, [pc, #-0x964] */
/* @0x28d36c add r1, pc, r1 */
/* @0x28d370 str r0, [sp, #0x44] */
/* @0x28d374 ldr r0, [sp, #0x1c] */
/* @0x28d378 bl 0x2873c4 <Json_getItem> */
/* @0x28d37c ldr r1, [pc, #-0x974] */
/* @0x28d380 add r1, pc, r1 */
/* @0x28d384 str r0, [sp, #0x50] */
/* @0x28d388 ldr r0, [sp, #0x1c] */
/* @0x28d38c bl 0x2873c4 <Json_getItem> */
/* @0x28d390 ldr r1, [pc, #-0x984] */
/* @0x28d394 add r1, pc, r1 */
/* @0x28d398 str r0, [sp, #0x28] */
/* @0x28d39c ldr r0, [sp, #0x1c] */
/* @0x28d3a0 bl 0x2873c4 <Json_getItem> */
/* @0x28d3a4 ldr r1, [sp, #0x28] */
/* @0x28d3a8 cmp r1, #0 */
/* @0x28d3ac str r0, [sp, #0x4c] */
/* @0x28d3b0 beq 0x28eb28 <spSkeletonJson_readSkeletonData+0x32dc> */
/* @0x28d3b4 ldr r2, [sp, #0x30] */
/* @0x28d3b8 cmp r2, #0 */
/* @0x28d3bc beq 0x28ea80 <spSkeletonJson_readSkeletonData+0x3234> */
/* @0x28d3c0 ldr r2, [r2, #0x4] */
/* @0x28d3c4 cmp r2, #0 */
/* @0x28d3c8 beq 0x28ea40 <spSkeletonJson_readSkeletonData+0x31f4> */
/* @0x28d3cc mov r3, #0 */
/* @0x28d3d0 ldr r1, [r2, #0xc] */
/* @0x28d3d4 ldr r2, [r2] */
/* @0x28d3d8 add r3, r3, r1 */
/* @0x28d3dc cmp r2, #0 */
/* @0x28d3e0 bne 0x28d3d0 <spSkeletonJson_readSkeletonData+0x1b84> */
/* @0x28d3e4 cmp r4, #0 */
/* @0x28d3e8 beq 0x28d40c <spSkeletonJson_readSkeletonData+0x1bc0> */
/* @0x28d3ec ldr r2, [r4, #0x4] */
/* @0x28d3f0 cmp r2, #0 */
/* @0x28d3f4 beq 0x28d40c <spSkeletonJson_readSkeletonData+0x1bc0> */
/* @0x28d3f8 ldr r1, [r2, #0xc] */
/* @0x28d3fc ldr r2, [r2] */
/* @0x28d400 add r3, r3, r1 */
/* @0x28d404 cmp r2, #0 */
/* @0x28d408 bne 0x28d3f8 <spSkeletonJson_readSkeletonData+0x1bac> */
/* @0x28d40c ldr r0, [sp, #0x34] */
/* @0x28d410 ldr r1, [sp, #0x38] */
/* @0x28d414 cmp r0, #0 */
/* @0x28d418 ldrne r2, [r0, #0xc] */
/* @0x28d41c ldreq r2, [sp, #0x34] */
/* @0x28d420 cmp r1, #0 */
/* @0x28d424 ldr r0, [sp, #0x44] */
/* @0x28d428 add r3, r3, r2 */
/* @0x28d42c ldrne r2, [r1, #0xc] */
/* @0x28d430 ldreq r2, [sp, #0x38] */
/* @0x28d434 cmp r0, #0 */
/* @0x28d438 add r1, r3, r2 */
/* @0x28d43c beq 0x28d460 <spSkeletonJson_readSkeletonData+0x1c14> */
/* @0x28d440 ldr r3, [r0, #0x4] */
/* @0x28d444 cmp r3, #0 */
/* @0x28d448 beq 0x28d460 <spSkeletonJson_readSkeletonData+0x1c14> */
/* @0x28d44c ldr r2, [r3, #0xc] */
/* @0x28d450 ldr r3, [r3] */
/* @0x28d454 add r1, r1, r2 */
/* @0x28d458 cmp r3, #0 */
/* @0x28d45c bne 0x28d44c <spSkeletonJson_readSkeletonData+0x1c00> */
/* @0x28d460 ldr r2, [sp, #0x50] */
/* @0x28d464 cmp r2, #0 */
/* @0x28d468 beq 0x28d4a4 <spSkeletonJson_readSkeletonData+0x1c58> */
/* @0x28d46c ldr r0, [r2, #0x4] */
/* @0x28d470 cmp r0, #0 */
/* @0x28d474 beq 0x28d4a4 <spSkeletonJson_readSkeletonData+0x1c58> */
/* @0x28d478 ldr r3, [r0, #0x4] */
/* @0x28d47c cmp r3, #0 */
/* @0x28d480 beq 0x28d498 <spSkeletonJson_readSkeletonData+0x1c4c> */
/* @0x28d484 ldr r2, [r3, #0xc] */
/* @0x28d488 ldr r3, [r3] */
/* @0x28d48c add r1, r1, r2 */
/* @0x28d490 cmp r3, #0 */
/* @0x28d494 bne 0x28d484 <spSkeletonJson_readSkeletonData+0x1c38> */
/* @0x28d498 ldr r0, [r0] */
/* @0x28d49c cmp r0, #0 */
/* @0x28d4a0 bne 0x28d478 <spSkeletonJson_readSkeletonData+0x1c2c> */
/* @0x28d4a4 ldr r3, [sp, #0x28] */
/* @0x28d4a8 ldr r0, [sp, #0x4c] */
/* @0x28d4ac ldr r2, [sp, #0x1c] */
/* @0x28d4b0 cmp r3, #0 */
/* @0x28d4b4 addne r1, r1, #1 */
/* @0x28d4b8 cmp r0, #0 */
/* @0x28d4bc addne r1, r1, #1 */
/* @0x28d4c0 ldr r0, [r2, #0x1c] */
/* @0x28d4c4 bl 0x2812b4 <spAnimation_create> */
/* @0x28d4c8 cmp r4, #0 */
/* @0x28d4cc mov r3, #0 */
/* @0x28d4d0 mov r11, r0 */
/* @0x28d4d4 str r3, [r0, #0x8] */
/* @0x28d4d8 beq 0x28d640 <spSkeletonJson_readSkeletonData+0x1df4> */
/* @0x28d4dc ldr r4, [r4, #0x4] */
/* @0x28d4e0 cmp r4, #0 */
/* @0x28d4e4 str r4, [sp, #0x2c] */
/* @0x28d4e8 beq 0x28d640 <spSkeletonJson_readSkeletonData+0x1df4> */
/* @0x28d4ec ldr r7, [pc, #-0xadc] */
/* @0x28d4f0 ldr r6, [pc, #-0xadc] */
/* @0x28d4f4 ldr r0, [pc, #-0xadc] */
/* @0x28d4f8 add r7, pc, r7 */
/* @0x28d4fc ldr r1, [pc, #-0xae0] */
/* @0x28d500 add r6, pc, r6 */
/* @0x28d504 ldr r2, [pc, #-0xae4] */
/* @0x28d508 add r0, pc, r0 */
/* @0x28d50c add r1, pc, r1 */
/* @0x28d510 str r0, [sp, #0x40] */
/* @0x28d514 add r2, pc, r2 */
/* @0x28d518 str r1, [sp, #0x48] */
/* @0x28d51c str r2, [sp, #0x54] */
/* @0x28d520 ldr r3, [sp, #0x2c] */
/* @0x28d524 ldr r0, [sp, #0x18] */
/* @0x28d528 ldr r1, [r3, #0x1c] */
/* @0x28d52c bl 0x28b0cc <spSkeletonData_findSlotIndex> */
/* @0x28d530 cmn r0, #1 */
/* @0x28d534 str r0, [sp, #0x3c] */
/* @0x28d538 beq 0x28ea10 <spSkeletonJson_readSkeletonData+0x31c4> */
/* @0x28d53c ldr r3, [sp, #0x2c] */
/* @0x28d540 ldr r9, [r3, #0x4] */
/* @0x28d544 cmp r9, #0 */
/* @0x28d548 beq 0x28d62c <spSkeletonJson_readSkeletonData+0x1de0> */
/* @0x28d54c ldr r4, [r9, #0x1c] */
/* @0x28d550 ldr r1, [sp, #0x40] */
/* @0x28d554 mov r0, r4 */
/* @0x28d558 bl 0xb6574 <strcmp@plt> */
/* @0x28d55c subs r5, r0, #0 */
/* @0x28d560 beq 0x28d8dc <spSkeletonJson_readSkeletonData+0x2090> */
/* @0x28d564 mov r0, r4 */
/* @0x28d568 ldr r1, [sp, #0x48] */
/* @0x28d56c bl 0xb6574 <strcmp@plt> */
/* @0x28d570 subs r5, r0, #0 */
/* @0x28d574 bne 0x28da18 <spSkeletonJson_readSkeletonData+0x21cc> */
/* @0x28d578 ldr r0, [r9, #0xc] */
/* @0x28d57c bl 0x282b94 <spAttachmentTimeline_create> */
/* @0x28d580 ldr r4, [r9, #0x4] */
/* @0x28d584 ldr r2, [sp, #0x3c] */
/* @0x28d588 cmp r4, #0 */
/* @0x28d58c mov r8, r0 */
/* @0x28d590 str r2, [r0, #0x10] */
/* @0x28d594 beq 0x28d5e8 <spSkeletonJson_readSkeletonData+0x1d9c> */
/* @0x28d598 mov r0, r4 */
/* @0x28d59c mov r1, r7 */
/* @0x28d5a0 bl 0x2873c4 <Json_getItem> */
/* @0x28d5a4 mov r1, r6 */
/* @0x28d5a8 mov r2, #0 */
/* @0x28d5ac mov r10, r0 */
/* @0x28d5b0 mov r0, r4 */
/* @0x28d5b4 bl 0x287444 <Json_getFloat> */
/* @0x28d5b8 ldr r3, [r10, #0x8] */
/* @0x28d5bc mov r1, r5 */
/* @0x28d5c0 add r5, r5, #1 */
/* @0x28d5c4 cmp r3, #2 */
/* @0x28d5c8 ldrne r3, [r10, #0x10] */
/* @0x28d5cc moveq r3, #0 */
/* @0x28d5d0 mov r2, r0 */
/* @0x28d5d4 mov r0, r8 */
/* @0x28d5d8 bl 0x282c1c <spAttachmentTimeline_setFrame> */
/* @0x28d5dc ldr r4, [r4] */
/* @0x28d5e0 cmp r4, #0 */
/* @0x28d5e4 bne 0x28d598 <spSkeletonJson_readSkeletonData+0x1d4c> */
/* @0x28d5e8 ldr r3, [r11, #0x8] */
/* @0x28d5ec vldr s14, [r11, #4] */
/* @0x28d5f0 ldr r1, [r11, #0xc] */
/* @0x28d5f4 add r2, r3, #1 */
/* @0x28d5f8 str r2, [r11, #0x8] */
/* @0x28d5fc ldr r2, [r9, #0xc] */
/* @0x28d600 str r8, [r1, r3, lsl #2] */
/* @0x28d604 ldr r3, [r8, #0xc] */
/* @0x28d608 add r3, r3, r2, lsl #2 */
/* @0x28d60c vldr s15, [r3, #-4] */
/* @0x28d610 vcmpe.f32 s14, s15 */
/* @0x28d614 vmrs APSR_nzcv, fpscr */
/* @0x28d618 vmovgt.f32 s15, s14 */
/* @0x28d61c vstr s15, [r11, #4] */
/* @0x28d620 ldr r9, [r9] */
/* @0x28d624 cmp r9, #0 */
/* @0x28d628 bne 0x28d54c <spSkeletonJson_readSkeletonData+0x1d00> */
/* @0x28d62c ldr r0, [sp, #0x2c] */
/* @0x28d630 ldr r0, [r0] */
/* @0x28d634 cmp r0, #0 */
/* @0x28d638 str r0, [sp, #0x2c] */
/* @0x28d63c bne 0x28d520 <spSkeletonJson_readSkeletonData+0x1cd4> */
/* @0x28d640 ldr r3, [sp, #0x30] */
/* @0x28d644 cmp r3, #0 */
/* @0x28d648 beq 0x28d840 <spSkeletonJson_readSkeletonData+0x1ff4> */
/* @0x28d64c ldr r0, [sp, #0x30] */
/* @0x28d650 ldr r6, [r0, #0x4] */
/* @0x28d654 cmp r6, #0 */
/* @0x28d658 beq 0x28d840 <spSkeletonJson_readSkeletonData+0x1ff4> */
/* @0x28d65c ldr r1, [pc, #-0xc38] */
/* @0x28d660 ldr r2, [pc, #-0xc38] */
/* @0x28d664 add r1, pc, r1 */
/* @0x28d668 ldr r3, [pc, #-0xc3c] */
/* @0x28d66c str r1, [sp, #0x3c] */
/* @0x28d670 add r2, pc, r2 */
/* @0x28d674 ldr r0, [pc, #-0xc44] */
/* @0x28d678 add r3, pc, r3 */
/* @0x28d67c ldr r1, [pc, #-0xc48] */
/* @0x28d680 add r0, pc, r0 */
/* @0x28d684 str r2, [sp, #0x40] */
/* @0x28d688 add r1, pc, r1 */
/* @0x28d68c str r3, [sp, #0x48] */
/* @0x28d690 str r0, [sp, #0x54] */
/* @0x28d694 str r1, [sp, #0x30] */
/* @0x28d698 ldr r0, [sp, #0x18] */
/* @0x28d69c ldr r1, [r6, #0x1c] */
/* @0x28d6a0 bl 0x28b018 <spSkeletonData_findBoneIndex> */
/* @0x28d6a4 cmn r0, #1 */
/* @0x28d6a8 mov r8, r0 */
/* @0x28d6ac beq 0x28db5c <spSkeletonJson_readSkeletonData+0x2310> */
/* @0x28d6b0 ldr r7, [r6, #0x4] */
/* @0x28d6b4 cmp r7, #0 */
/* @0x28d6b8 strne r6, [sp, #0x58] */
/* @0x28d6bc beq 0x28d834 <spSkeletonJson_readSkeletonData+0x1fe8> */
/* @0x28d6c0 ldr r4, [r7, #0x1c] */
/* @0x28d6c4 ldr r1, [sp, #0x3c] */
/* @0x28d6c8 mov r0, r4 */
/* @0x28d6cc bl 0xb6574 <strcmp@plt> */
/* @0x28d6d0 subs r9, r0, #0 */
/* @0x28d6d4 beq 0x28da74 <spSkeletonJson_readSkeletonData+0x2228> */
/* @0x28d6d8 mov r0, r4 */
/* @0x28d6dc ldr r1, [sp, #0x40] */
/* @0x28d6e0 bl 0xb6574 <strcmp@plt> */
/* @0x28d6e4 ldr r1, [sp, #0x48] */
/* @0x28d6e8 rsbs r5, r0, #1 */
/* @0x28d6ec mov r0, r4 */
/* @0x28d6f0 movlo r5, #0 */
/* @0x28d6f4 bl 0xb6574 <strcmp@plt> */
/* @0x28d6f8 ldr r1, [sp, #0x54] */
/* @0x28d6fc rsbs r9, r0, #1 */
/* @0x28d700 mov r0, r4 */
/* @0x28d704 movlo r9, #0 */
/* @0x28d708 bl 0xb6574 <strcmp@plt> */
/* @0x28d70c orr r4, r9, r5 */
/* @0x28d710 rsbs r0, r0, #1 */
/* @0x28d714 movlo r0, #0 */
/* @0x28d718 orrs r4, r0, r4 */
/* @0x28d71c beq 0x28db88 <spSkeletonJson_readSkeletonData+0x233c> */
/* @0x28d720 cmp r9, #0 */
/* @0x28d724 bne 0x28da54 <spSkeletonJson_readSkeletonData+0x2208> */
/* @0x28d728 cmp r5, #0 */
/* @0x28d72c bne 0x28db48 <spSkeletonJson_readSkeletonData+0x22fc> */
/* @0x28d730 cmp r0, #0 */
/* @0x28d734 vmoveq.f32 s16, #1.000000e+00 */
/* @0x28d738 moveq r4, r0 */
/* @0x28d73c bne 0x28dbb4 <spSkeletonJson_readSkeletonData+0x2368> */
/* @0x28d740 ldr r6, [r7, #0x4] */
/* @0x28d744 str r8, [r4, #0x14] */
/* @0x28d748 cmp r6, #0 */
/* @0x28d74c beq 0x28d7e4 <spSkeletonJson_readSkeletonData+0x1f98> */
/* @0x28d750 ldr r10, [pc, #-0xd18] */
/* @0x28d754 mov r5, #0 */
/* @0x28d758 ldr r3, [pc, #-0xd1c] */
/* @0x28d75c add r10, pc, r10 */
/* @0x28d760 add r3, pc, r3 */
/* @0x28d764 str r3, [sp, #0x2c] */
/* @0x28d768 mov r0, r6 */
/* @0x28d76c ldr r1, [sp, #0x30] */
/* @0x28d770 mov r2, #0 */
/* @0x28d774 bl 0x287444 <Json_getFloat> */
/* @0x28d778 mov r1, r10 */
/* @0x28d77c mov r2, #0 */
/* @0x28d780 mov r9, r0 */
/* @0x28d784 mov r0, r6 */
/* @0x28d788 bl 0x287444 <Json_getFloat> */
/* @0x28d78c ldr r1, [sp, #0x2c] */
/* @0x28d790 mov r2, #0 */
/* @0x28d794 vmov s14, r0 */
/* @0x28d798 mov r0, r6 */
/* @0x28d79c vmul.f32 s17, s14, s16 */
/* @0x28d7a0 bl 0x287444 <Json_getFloat> */
/* @0x28d7a4 mov r1, r5 */
/* @0x28d7a8 mov r2, r9 */
/* @0x28d7ac vmov r3, s17 */
/* @0x28d7b0 vmov s14, r0 */
/* @0x28d7b4 mov r0, r4 */
/* @0x28d7b8 vmul.f32 s15, s16, s14 */
/* @0x28d7bc vstr s15, [sp] */
/* @0x28d7c0 bl 0x282ad4 <spTranslateTimeline_setFrame> */
/* @0x28d7c4 mov r0, r6 */
/* @0x28d7c8 mov r2, r5 */
/* @0x28d7cc mov r1, r4 */
/* @0x28d7d0 bl 0x28b34c <spSkeletonData_findPathConstraint+0x5c> */
/* @0x28d7d4 ldr r6, [r6] */
/* @0x28d7d8 add r5, r5, #1 */
/* @0x28d7dc cmp r6, #0 */
/* @0x28d7e0 bne 0x28d768 <spSkeletonJson_readSkeletonData+0x1f1c> */
/* @0x28d7e4 ldr r2, [r7, #0xc] */
/* @0x28d7e8 vldr s14, [r11, #4] */
/* @0x28d7ec ldr r3, [r11, #0x8] */
/* @0x28d7f0 ldr r1, [r11, #0xc] */
/* @0x28d7f4 sub r2, r2, #1 */
/* @0x28d7f8 add r0, r3, #1 */
/* @0x28d7fc str r0, [r11, #0x8] */
/* @0x28d800 add r2, r2, r2, lsl #1 */
/* @0x28d804 str r4, [r1, r3, lsl #2] */
/* @0x28d808 ldr r3, [r4, #0x10] */
/* @0x28d80c add r3, r3, r2, lsl #2 */
/* @0x28d810 vldr s15, [r3] */
/* @0x28d814 vcmpe.f32 s14, s15 */
/* @0x28d818 vmrs APSR_nzcv, fpscr */
/* @0x28d81c vmovgt.f32 s15, s14 */
/* @0x28d820 vstr s15, [r11, #4] */
/* @0x28d824 ldr r7, [r7] */
/* @0x28d828 cmp r7, #0 */
/* @0x28d82c bne 0x28d6c0 <spSkeletonJson_readSkeletonData+0x1e74> */
/* @0x28d830 ldr r6, [sp, #0x58] */
/* @0x28d834 ldr r6, [r6] */
/* @0x28d838 cmp r6, #0 */
/* @0x28d83c bne 0x28d698 <spSkeletonJson_readSkeletonData+0x1e4c> */
/* @0x28d840 ldr r3, [sp, #0x34] */
/* @0x28d844 cmp r3, #0 */
/* @0x28d848 beq 0x28dca8 <spSkeletonJson_readSkeletonData+0x245c> */
/* @0x28d84c ldr r1, [sp, #0x34] */
/* @0x28d850 ldr r4, [r1, #0x4] */
/* @0x28d854 cmp r4, #0 */
/* @0x28d858 beq 0x28dca8 <spSkeletonJson_readSkeletonData+0x245c> */
/* @0x28d85c ldr r10, [pc, #-0xe1c] */
/* @0x28d860 ldr r2, [pc, #-0xe1c] */
/* @0x28d864 ldr r3, [pc, #-0xe1c] */
/* @0x28d868 add r10, pc, r10 */
/* @0x28d86c add r2, pc, r2 */
/* @0x28d870 str r2, [sp, #0x2c] */
/* @0x28d874 add r3, pc, r3 */
/* @0x28d878 str r3, [sp, #0x30] */
/* @0x28d87c ldr r1, [r4, #0x1c] */
/* @0x28d880 ldr r0, [sp, #0x18] */
/* @0x28d884 bl 0x28b238 <spSkeletonData_findIkConstraint> */
/* @0x28d888 mov r5, r0 */
/* @0x28d88c ldr r0, [r4, #0xc] */
/* @0x28d890 bl 0x282f74 <spIkConstraintTimeline_create> */
/* @0x28d894 mov r6, r0 */
/* @0x28d898 ldr r0, [sp, #0x18] */
/* @0x28d89c ldr r1, [r0, #0x3c] */
/* @0x28d8a0 cmp r1, #0 */
/* @0x28d8a4 ble 0x28dbd0 <spSkeletonJson_readSkeletonData+0x2384> */
/* @0x28d8a8 ldr r2, [r0, #0x40] */
/* @0x28d8ac ldr r3, [r2] */
/* @0x28d8b0 cmp r5, r3 */
/* @0x28d8b4 movne r3, #0 */
/* @0x28d8b8 bne 0x28d8cc <spSkeletonJson_readSkeletonData+0x2080> */
/* @0x28d8bc b 0x28dbc8 <spSkeletonJson_readSkeletonData+0x237c> */
/* @0x28d8c0 ldr r0, [r2, #0x4]! */
/* @0x28d8c4 cmp r5, r0 */
/* @0x28d8c8 beq 0x28dbcc <spSkeletonJson_readSkeletonData+0x2380> */
/* @0x28d8cc add r3, r3, #1 */
/* @0x28d8d0 cmp r3, r1 */
/* @0x28d8d4 bne 0x28d8c0 <spSkeletonJson_readSkeletonData+0x2074> */
/* @0x28d8d8 b 0x28dbd0 <spSkeletonJson_readSkeletonData+0x2384> */
/* @0x28d8dc ldr r0, [r9, #0xc] */
/* @0x28d8e0 bl 0x282b3c <spColorTimeline_create> */
/* @0x28d8e4 ldr r10, [r9, #0x4] */
/* @0x28d8e8 ldr r1, [sp, #0x3c] */
/* @0x28d8ec cmp r10, #0 */
/* @0x28d8f0 mov r8, r0 */
/* @0x28d8f4 str r1, [r0, #0x14] */
/* @0x28d8f8 beq 0x28d9d4 <spSkeletonJson_readSkeletonData+0x2188> */
/* @0x28d8fc ldr r12, [pc, #-0xeb0] */
/* @0x28d900 str r7, [sp, #0x74] */
/* @0x28d904 mov r7, r10 */
/* @0x28d908 add r12, pc, r12 */
/* @0x28d90c mov r10, r6 */
/* @0x28d910 ldr r6, [sp, #0x54] */
/* @0x28d914 str r11, [sp, #0x58] */
/* @0x28d918 mov r11, r12 */
/* @0x28d91c str r9, [sp, #0x5c] */
/* @0x28d920 mov r0, r7 */
/* @0x28d924 mov r1, r6 */
/* @0x28d928 mov r2, #0 */
/* @0x28d92c bl 0x287428 <Json_getString> */
/* @0x28d930 mov r2, #0 */
/* @0x28d934 mov r1, r11 */
/* @0x28d938 mov r4, r0 */
/* @0x28d93c mov r0, r7 */
/* @0x28d940 bl 0x287444 <Json_getFloat> */
/* @0x28d944 mov r1, #0 */
/* @0x28d948 mov r9, r0 */
/* @0x28d94c mov r0, r4 */
/* @0x28d950 bl 0x28b680 <spSkeletonData_findPathConstraint+0x390> */
/* @0x28d954 mov r0, r4 */
/* @0x28d958 mov r1, #1 */
/* @0x28d95c vstr s0, [sp, #16] */
/* @0x28d960 bl 0x28b680 <spSkeletonData_findPathConstraint+0x390> */
/* @0x28d964 mov r0, r4 */
/* @0x28d968 mov r1, #2 */
/* @0x28d96c vmov.f32 s17, s0 */
/* @0x28d970 bl 0x28b680 <spSkeletonData_findPathConstraint+0x390> */
/* @0x28d974 mov r0, r4 */
/* @0x28d978 mov r1, #3 */
/* @0x28d97c vmov.f32 s16, s0 */
/* @0x28d980 bl 0x28b680 <spSkeletonData_findPathConstraint+0x390> */
/* @0x28d984 mov r1, r5 */
/* @0x28d988 mov r2, r9 */
/* @0x28d98c mov r0, r8 */
/* @0x28d990 ldr r3, [sp, #0x10] */
/* @0x28d994 vstr s17, [sp] */
/* @0x28d998 vstr s16, [sp, #4] */
/* @0x28d99c vstr s0, [sp, #8] */
/* @0x28d9a0 bl 0x282b54 <spColorTimeline_setFrame> */
/* @0x28d9a4 mov r0, r7 */
/* @0x28d9a8 mov r2, r5 */
/* @0x28d9ac mov r1, r8 */
/* @0x28d9b0 bl 0x28b34c <spSkeletonData_findPathConstraint+0x5c> */
/* @0x28d9b4 ldr r7, [r7] */
/* @0x28d9b8 add r5, r5, #1 */
/* @0x28d9bc cmp r7, #0 */
/* @0x28d9c0 bne 0x28d920 <spSkeletonJson_readSkeletonData+0x20d4> */
/* @0x28d9c4 ldr r11, [sp, #0x58] */
/* @0x28d9c8 mov r6, r10 */
/* @0x28d9cc ldr r9, [sp, #0x5c] */
/* @0x28d9d0 ldr r7, [sp, #0x74] */
/* @0x28d9d4 ldr r2, [r9, #0xc] */
/* @0x28d9d8 vldr s14, [r11, #4] */
/* @0x28d9dc ldr r3, [r11, #0x8] */
/* @0x28d9e0 ldr r1, [r11, #0xc] */
/* @0x28d9e4 sub r2, r2, #1 */
/* @0x28d9e8 add r0, r3, #1 */
/* @0x28d9ec str r0, [r11, #0x8] */
/* @0x28d9f0 add r2, r2, r2, lsl #2 */
/* @0x28d9f4 str r8, [r1, r3, lsl #2] */
/* @0x28d9f8 ldr r3, [r8, #0x10] */
/* @0x28d9fc add r3, r3, r2, lsl #2 */
/* @0x28da00 vldr s15, [r3] */
/* @0x28da04 vcmpe.f32 s14, s15 */
/* @0x28da08 vmrs APSR_nzcv, fpscr */
/* @0x28da0c vmovgt.f32 s15, s14 */
/* @0x28da10 vstr s15, [r11, #4] */
/* @0x28da14 b 0x28d620 <spSkeletonJson_readSkeletonData+0x1dd4> */
/* @0x28da18 ldr r8, [sp, #0x20] */
/* @0x28da1c mov r0, r11 */
/* @0x28da20 mov r4, r9 */
/* @0x28da24 ldr r9, [sp, #0x18] */
/* @0x28da28 bl 0x28147c <spAnimation_dispose> */
/* @0x28da2c ldr r2, [pc, #-0xfdc] */
/* @0x28da30 mov r0, r8 */
/* @0x28da34 ldr r3, [r4, #0x1c] */
/* @0x28da38 mov r1, #0 */
/* @0x28da3c add r2, pc, r2 */
/* @0x28da40 bl 0x28b784 <_spSkeletonJson_setError> */
/* @0x28da44 mov r0, r9 */
/* @0x28da48 bl 0x28adf8 <spSkeletonData_dispose> */
/* @0x28da4c mov r0, #0 */
/* @0x28da50 b 0x28bdcc <spSkeletonJson_readSkeletonData+0x580> */
/* @0x28da54 cmp r5, #0 */
/* @0x28da58 ldr r2, [sp, #0x20] */
/* @0x28da5c vldr s16, [r2] */
/* @0x28da60 bne 0x28db4c <spSkeletonJson_readSkeletonData+0x2300> */
/* @0x28da64 ldr r0, [r7, #0xc] */
/* @0x28da68 bl 0x282abc <spTranslateTimeline_create> */
/* @0x28da6c mov r4, r0 */
/* @0x28da70 b 0x28d740 <spSkeletonJson_readSkeletonData+0x1ef4> */
/* @0x28da74 ldr r0, [r7, #0xc] */
/* @0x28da78 bl 0x282a90 <spRotateTimeline_create> */
/* @0x28da7c ldr r4, [r7, #0x4] */
/* @0x28da80 cmp r4, #0 */
/* @0x28da84 mov r5, r0 */
/* @0x28da88 str r8, [r0, #0x14] */
/* @0x28da8c beq 0x28db0c <spSkeletonJson_readSkeletonData+0x22c0> */
/* @0x28da90 ldr r6, [pc, #0xff0] */
/* @0x28da94 mov r12, r7 */
/* @0x28da98 ldr r10, [pc, #0xfec] */
/* @0x28da9c add r6, pc, r6 */
/* @0x28daa0 add r10, pc, r10 */
/* @0x28daa4 mov r7, r6 */
/* @0x28daa8 mov r0, r4 */
/* @0x28daac mov r1, r7 */
/* @0x28dab0 mov r2, #0 */
/* @0x28dab4 str r12, [sp, #0x14] */
/* @0x28dab8 bl 0x287444 <Json_getFloat> */
/* @0x28dabc mov r1, r10 */
/* @0x28dac0 mov r2, #0 */
/* @0x28dac4 mov r6, r0 */
/* @0x28dac8 mov r0, r4 */
/* @0x28dacc bl 0x287444 <Json_getFloat> */
/* @0x28dad0 mov r1, r9 */
/* @0x28dad4 mov r2, r6 */
/* @0x28dad8 mov r3, r0 */
/* @0x28dadc mov r0, r5 */
/* @0x28dae0 bl 0x282aa8 <spRotateTimeline_setFrame> */
/* @0x28dae4 mov r0, r4 */
/* @0x28dae8 mov r2, r9 */
/* @0x28daec mov r1, r5 */
/* @0x28daf0 bl 0x28b34c <spSkeletonData_findPathConstraint+0x5c> */
/* @0x28daf4 ldr r4, [r4] */
/* @0x28daf8 add r9, r9, #1 */
/* @0x28dafc ldr r12, [sp, #0x14] */
/* @0x28db00 cmp r4, #0 */
/* @0x28db04 bne 0x28daa8 <spSkeletonJson_readSkeletonData+0x225c> */
/* @0x28db08 mov r7, r12 */
/* @0x28db0c ldr r3, [r11, #0x8] */
/* @0x28db10 vldr s14, [r11, #4] */
/* @0x28db14 ldr r1, [r11, #0xc] */
/* @0x28db18 add r2, r3, #1 */
/* @0x28db1c str r2, [r11, #0x8] */
/* @0x28db20 ldr r2, [r7, #0xc] */
/* @0x28db24 str r5, [r1, r3, lsl #2] */
/* @0x28db28 ldr r3, [r5, #0x10] */
/* @0x28db2c add r3, r3, r2, lsl #3 */
/* @0x28db30 vldr s15, [r3, #-8] */
/* @0x28db34 vcmpe.f32 s14, s15 */
/* @0x28db38 vmrs APSR_nzcv, fpscr */
/* @0x28db3c vmovgt.f32 s15, s14 */
/* @0x28db40 vstr s15, [r11, #4] */
/* @0x28db44 b 0x28d824 <spSkeletonJson_readSkeletonData+0x1fd8> */
/* @0x28db48 vmov.f32 s16, #1.000000e+00 */
/* @0x28db4c ldr r0, [r7, #0xc] */
/* @0x28db50 bl 0x282b04 <spScaleTimeline_create> */
/* @0x28db54 mov r4, r0 */
/* @0x28db58 b 0x28d740 <spSkeletonJson_readSkeletonData+0x1ef4> */
/* @0x28db5c ldr r8, [sp, #0x20] */
/* @0x28db60 mov r0, r11 */
/* @0x28db64 ldr r9, [sp, #0x18] */
/* @0x28db68 bl 0x28147c <spAnimation_dispose> */
/* @0x28db6c ldr r2, [pc, #0xf1c] */
/* @0x28db70 mov r0, r8 */
/* @0x28db74 ldr r1, [sp, #0x1c] */
/* @0x28db78 ldr r3, [r6, #0x1c] */
/* @0x28db7c add r2, pc, r2 */
/* @0x28db80 bl 0x28b784 <_spSkeletonJson_setError> */
/* @0x28db84 b 0x28da44 <spSkeletonJson_readSkeletonData+0x21f8> */
/* @0x28db88 ldr r8, [sp, #0x20] */
/* @0x28db8c mov r0, r11 */
/* @0x28db90 ldr r9, [sp, #0x18] */
/* @0x28db94 bl 0x28147c <spAnimation_dispose> */
/* @0x28db98 ldr r2, [pc, #0xef4] */
/* @0x28db9c mov r1, r4 */
/* @0x28dba0 mov r0, r8 */
/* @0x28dba4 ldr r3, [r7, #0x1c] */
/* @0x28dba8 add r2, pc, r2 */
/* @0x28dbac bl 0x28b784 <_spSkeletonJson_setError> */
/* @0x28dbb0 b 0x28da44 <spSkeletonJson_readSkeletonData+0x21f8> */
/* @0x28dbb4 ldr r0, [r7, #0xc] */
/* @0x28dbb8 vmov.f32 s16, #1.000000e+00 */
/* @0x28dbbc bl 0x282b20 <spShearTimeline_create> */
/* @0x28dbc0 mov r4, r0 */
/* @0x28dbc4 b 0x28d740 <spSkeletonJson_readSkeletonData+0x1ef4> */
/* @0x28dbc8 mov r3, #0 */
/* @0x28dbcc str r3, [r6, #0x14] */
/* @0x28dbd0 ldr r5, [r4, #0x4] */
/* @0x28dbd4 cmp r5, #0 */
/* @0x28dbd8 movne r7, #0 */
/* @0x28dbdc beq 0x28dc5c <spSkeletonJson_readSkeletonData+0x2410> */
/* @0x28dbe0 mov r0, r5 */
/* @0x28dbe4 mov r1, r10 */
/* @0x28dbe8 mov r2, #0 */
/* @0x28dbec bl 0x287444 <Json_getFloat> */
/* @0x28dbf0 ldr r1, [sp, #0x2c] */
/* @0x28dbf4 mov r2, #1065353216 */
/* @0x28dbf8 mov r9, r0 */
/* @0x28dbfc mov r0, r5 */
/* @0x28dc00 bl 0x287444 <Json_getFloat> */
/* @0x28dc04 ldr r1, [sp, #0x30] */
/* @0x28dc08 mov r2, #1 */
/* @0x28dc0c mov r8, r0 */
/* @0x28dc10 mov r0, r5 */
/* @0x28dc14 bl 0x287460 <Json_getInt> */
/* @0x28dc18 mov r1, r7 */
/* @0x28dc1c mov r2, r9 */
/* @0x28dc20 mov r3, r8 */
/* @0x28dc24 cmp r0, #0 */
/* @0x28dc28 mov r0, r6 */
/* @0x28dc2c mvneq r12, #0 */
/* @0x28dc30 movne r12, #1 */
/* @0x28dc34 str r12, [sp] */
/* @0x28dc38 bl 0x282f8c <spIkConstraintTimeline_setFrame> */
/* @0x28dc3c mov r0, r5 */
/* @0x28dc40 mov r2, r7 */
/* @0x28dc44 mov r1, r6 */
/* @0x28dc48 bl 0x28b34c <spSkeletonData_findPathConstraint+0x5c> */
/* @0x28dc4c ldr r5, [r5] */
/* @0x28dc50 add r7, r7, #1 */
/* @0x28dc54 cmp r5, #0 */
/* @0x28dc58 bne 0x28dbe0 <spSkeletonJson_readSkeletonData+0x2394> */
/* @0x28dc5c ldr r2, [r4, #0xc] */
/* @0x28dc60 vldr s14, [r11, #4] */
/* @0x28dc64 ldr r3, [r11, #0x8] */
/* @0x28dc68 ldr r1, [r11, #0xc] */
/* @0x28dc6c sub r2, r2, #1 */
/* @0x28dc70 add r0, r3, #1 */
/* @0x28dc74 str r0, [r11, #0x8] */
/* @0x28dc78 add r2, r2, r2, lsl #1 */
/* @0x28dc7c str r6, [r1, r3, lsl #2] */
/* @0x28dc80 ldr r3, [r6, #0x10] */
/* @0x28dc84 ldr r4, [r4] */
/* @0x28dc88 add r3, r3, r2, lsl #2 */
/* @0x28dc8c vldr s15, [r3] */
/* @0x28dc90 vcmpe.f32 s14, s15 */
/* @0x28dc94 vmrs APSR_nzcv, fpscr */
/* @0x28dc98 vmovgt.f32 s15, s14 */
/* @0x28dc9c cmp r4, #0 */
/* @0x28dca0 vstr s15, [r11, #4] */
/* @0x28dca4 bne 0x28d87c <spSkeletonJson_readSkeletonData+0x2030> */
/* @0x28dca8 ldr r0, [sp, #0x38] */
/* @0x28dcac cmp r0, #0 */
/* @0x28dcb0 beq 0x28de74 <spSkeletonJson_readSkeletonData+0x2628> */
/* @0x28dcb4 ldr r2, [sp, #0x38] */
/* @0x28dcb8 ldr r5, [r2, #0x4] */
/* @0x28dcbc cmp r5, #0 */
/* @0x28dcc0 beq 0x28de74 <spSkeletonJson_readSkeletonData+0x2628> */
/* @0x28dcc4 ldr r3, [pc, #0xdcc] */
/* @0x28dcc8 ldr r0, [pc, #0xdcc] */
/* @0x28dccc add r3, pc, r3 */
/* @0x28dcd0 ldr r1, [pc, #0xdc8] */
/* @0x28dcd4 str r3, [sp, #0x2c] */
/* @0x28dcd8 add r0, pc, r0 */
/* @0x28dcdc ldr r2, [pc, #0xdc0] */
/* @0x28dce0 add r1, pc, r1 */
/* @0x28dce4 ldr r3, [pc, #0xdbc] */
/* @0x28dce8 add r2, pc, r2 */
/* @0x28dcec str r0, [sp, #0x30] */
/* @0x28dcf0 add r3, pc, r3 */
/* @0x28dcf4 str r1, [sp, #0x34] */
/* @0x28dcf8 str r2, [sp, #0x38] */
/* @0x28dcfc str r3, [sp, #0x3c] */
/* @0x28dd00 ldr r1, [r5, #0x1c] */
/* @0x28dd04 ldr r0, [sp, #0x18] */
/* @0x28dd08 bl 0x28b294 <spSkeletonData_findTransformConstraint> */
/* @0x28dd0c mov r4, r0 */
/* @0x28dd10 ldr r0, [r5, #0xc] */
/* @0x28dd14 bl 0x282fb8 <spTransformConstraintTimeline_create> */
/* @0x28dd18 mov r6, r0 */
/* @0x28dd1c ldr r0, [sp, #0x18] */
/* @0x28dd20 ldr r1, [r0, #0x44] */
/* @0x28dd24 cmp r1, #0 */
/* @0x28dd28 ble 0x28dd68 <spSkeletonJson_readSkeletonData+0x251c> */
/* @0x28dd2c ldr r2, [r0, #0x48] */
/* @0x28dd30 ldr r3, [r2] */
/* @0x28dd34 cmp r4, r3 */
/* @0x28dd38 movne r3, #0 */
/* @0x28dd3c bne 0x28dd50 <spSkeletonJson_readSkeletonData+0x2504> */
/* @0x28dd40 b 0x28dd60 <spSkeletonJson_readSkeletonData+0x2514> */
/* @0x28dd44 ldr r0, [r2, #0x4]! */
/* @0x28dd48 cmp r4, r0 */
/* @0x28dd4c beq 0x28dd64 <spSkeletonJson_readSkeletonData+0x2518> */
/* @0x28dd50 add r3, r3, #1 */
/* @0x28dd54 cmp r3, r1 */
/* @0x28dd58 bne 0x28dd44 <spSkeletonJson_readSkeletonData+0x24f8> */
/* @0x28dd5c b 0x28dd68 <spSkeletonJson_readSkeletonData+0x251c> */
/* @0x28dd60 mov r3, #0 */
/* @0x28dd64 str r3, [r6, #0x14] */
/* @0x28dd68 ldr r4, [r5, #0x4] */
/* @0x28dd6c cmp r4, #0 */
/* @0x28dd70 movne r7, #0 */
/* @0x28dd74 movne r12, r5 */
/* @0x28dd78 beq 0x28de28 <spSkeletonJson_readSkeletonData+0x25dc> */
/* @0x28dd7c mov r0, r4 */
/* @0x28dd80 ldr r1, [sp, #0x2c] */
/* @0x28dd84 mov r2, #0 */
/* @0x28dd88 str r12, [sp, #0x14] */
/* @0x28dd8c bl 0x287444 <Json_getFloat> */
/* @0x28dd90 ldr r1, [sp, #0x30] */
/* @0x28dd94 mov r2, #1065353216 */
/* @0x28dd98 mov r9, r0 */
/* @0x28dd9c mov r0, r4 */
/* @0x28dda0 bl 0x287444 <Json_getFloat> */
/* @0x28dda4 ldr r1, [sp, #0x34] */
/* @0x28dda8 mov r2, #1065353216 */
/* @0x28ddac mov r8, r0 */
/* @0x28ddb0 mov r0, r4 */
/* @0x28ddb4 bl 0x287444 <Json_getFloat> */
/* @0x28ddb8 ldr r1, [sp, #0x38] */
/* @0x28ddbc mov r2, #1065353216 */
/* @0x28ddc0 mov r5, r0 */
/* @0x28ddc4 mov r0, r4 */
/* @0x28ddc8 bl 0x287444 <Json_getFloat> */
/* @0x28ddcc ldr r1, [sp, #0x3c] */
/* @0x28ddd0 mov r2, #1065353216 */
/* @0x28ddd4 mov r10, r0 */
/* @0x28ddd8 mov r0, r4 */
/* @0x28dddc bl 0x287444 <Json_getFloat> */
/* @0x28dde0 mov r1, r7 */
/* @0x28dde4 mov r2, r9 */
/* @0x28dde8 mov r3, r8 */
/* @0x28ddec str r5, [sp] */
/* @0x28ddf0 str r10, [sp, #0x4] */
/* @0x28ddf4 str r0, [sp, #0x8] */
/* @0x28ddf8 mov r0, r6 */
/* @0x28ddfc bl 0x282fd0 <spTransformConstraintTimeline_setFrame> */
/* @0x28de00 mov r0, r4 */
/* @0x28de04 mov r2, r7 */
/* @0x28de08 mov r1, r6 */
/* @0x28de0c bl 0x28b34c <spSkeletonData_findPathConstraint+0x5c> */
/* @0x28de10 ldr r4, [r4] */
/* @0x28de14 add r7, r7, #1 */
/* @0x28de18 ldr r12, [sp, #0x14] */
/* @0x28de1c cmp r4, #0 */
/* @0x28de20 bne 0x28dd7c <spSkeletonJson_readSkeletonData+0x2530> */
/* @0x28de24 mov r5, r12 */
/* @0x28de28 ldr r2, [r5, #0xc] */
/* @0x28de2c vldr s14, [r11, #4] */
/* @0x28de30 ldr r3, [r11, #0x8] */
/* @0x28de34 ldr r1, [r11, #0xc] */
/* @0x28de38 sub r2, r2, #1 */
/* @0x28de3c add r0, r3, #1 */
/* @0x28de40 str r0, [r11, #0x8] */
/* @0x28de44 add r2, r2, r2, lsl #2 */
/* @0x28de48 str r6, [r1, r3, lsl #2] */
/* @0x28de4c ldr r3, [r6, #0x10] */
/* @0x28de50 ldr r5, [r5] */
/* @0x28de54 add r3, r3, r2, lsl #2 */
/* @0x28de58 vldr s15, [r3] */
/* @0x28de5c vcmpe.f32 s14, s15 */
/* @0x28de60 vmrs APSR_nzcv, fpscr */
/* @0x28de64 vmovgt.f32 s15, s14 */
/* @0x28de68 cmp r5, #0 */
/* @0x28de6c vstr s15, [r11, #4] */
/* @0x28de70 bne 0x28dd00 <spSkeletonJson_readSkeletonData+0x24b4> */
/* @0x28de74 ldr r1, [sp, #0x44] */
/* @0x28de78 cmp r1, #0 */
/* @0x28de7c beq 0x28e060 <spSkeletonJson_readSkeletonData+0x2814> */
/* @0x28de80 ldr r2, [sp, #0x44] */
/* @0x28de84 ldr r10, [r2, #0x4] */
/* @0x28de88 cmp r10, #0 */
/* @0x28de8c beq 0x28e060 <spSkeletonJson_readSkeletonData+0x2814> */
/* @0x28de90 ldr r3, [pc, #0xc14] */
/* @0x28de94 mov r0, #0 */
/* @0x28de98 ldr r1, [pc, #0xc10] */
/* @0x28de9c add r3, pc, r3 */
/* @0x28dea0 str r0, [sp, #0x2c] */
/* @0x28dea4 str r3, [sp, #0x38] */
/* @0x28dea8 add r1, pc, r1 */
/* @0x28deac ldr r2, [pc, #0xc00] */
/* @0x28deb0 ldr r3, [pc, #0xc00] */
/* @0x28deb4 ldr r0, [pc, #0xc00] */
/* @0x28deb8 add r2, pc, r2 */
/* @0x28debc add r3, pc, r3 */
/* @0x28dec0 str r1, [sp, #0x3c] */
/* @0x28dec4 add r0, pc, r0 */
/* @0x28dec8 str r2, [sp, #0x40] */
/* @0x28decc str r3, [sp, #0x44] */
/* @0x28ded0 str r0, [sp, #0x48] */
/* @0x28ded4 ldr r0, [sp, #0x18] */
/* @0x28ded8 ldr r1, [r10, #0x1c] */
/* @0x28dedc bl 0x28b2f0 <spSkeletonData_findPathConstraint> */
/* @0x28dee0 subs r9, r0, #0 */
/* @0x28dee4 beq 0x28ea48 <spSkeletonJson_readSkeletonData+0x31fc> */
/* @0x28dee8 ldr r2, [sp, #0x18] */
/* @0x28deec ldr r1, [r2, #0x4c] */
/* @0x28def0 cmp r1, #0 */
/* @0x28def4 ble 0x28df30 <spSkeletonJson_readSkeletonData+0x26e4> */
/* @0x28def8 ldr r2, [r2, #0x50] */
/* @0x28defc ldr r3, [r2] */
/* @0x28df00 cmp r9, r3 */
/* @0x28df04 mov r3, #0 */
/* @0x28df08 bne 0x28df1c <spSkeletonJson_readSkeletonData+0x26d0> */
/* @0x28df0c b 0x28df2c <spSkeletonJson_readSkeletonData+0x26e0> */
/* @0x28df10 ldr r0, [r2, #0x4]! */
/* @0x28df14 cmp r9, r0 */
/* @0x28df18 beq 0x28df2c <spSkeletonJson_readSkeletonData+0x26e0> */
/* @0x28df1c add r3, r3, #1 */
/* @0x28df20 cmp r3, r1 */
/* @0x28df24 bne 0x28df10 <spSkeletonJson_readSkeletonData+0x26c4> */
/* @0x28df28 b 0x28df30 <spSkeletonJson_readSkeletonData+0x26e4> */
/* @0x28df2c str r3, [sp, #0x2c] */
/* @0x28df30 ldr r4, [r10, #0x4] */
/* @0x28df34 cmp r4, #0 */
/* @0x28df38 beq 0x28e054 <spSkeletonJson_readSkeletonData+0x2808> */
/* @0x28df3c ldr r6, [r4, #0x1c] */
/* @0x28df40 ldr r1, [sp, #0x38] */
/* @0x28df44 mov r0, r6 */
/* @0x28df48 bl 0xb6574 <strcmp@plt> */
/* @0x28df4c cmp r0, #0 */
/* @0x28df50 mov r0, r6 */
/* @0x28df54 bne 0x28e52c <spSkeletonJson_readSkeletonData+0x2ce0> */
/* @0x28df58 ldr r1, [sp, #0x40] */
/* @0x28df5c bl 0xb6574 <strcmp@plt> */
/* @0x28df60 cmp r0, #0 */
/* @0x28df64 beq 0x28e53c <spSkeletonJson_readSkeletonData+0x2cf0> */
/* @0x28df68 ldr r0, [r4, #0xc] */
/* @0x28df6c bl 0x283010 <spPathConstraintPositionTimeline_create> */
/* @0x28df70 ldr r3, [r9, #0x10] */
/* @0x28df74 cmp r3, #0 */
/* @0x28df78 mov r8, r0 */
/* @0x28df7c bne 0x28e554 <spSkeletonJson_readSkeletonData+0x2d08> */
/* @0x28df80 ldr r1, [sp, #0x20] */
/* @0x28df84 vldr s16, [r1] */
/* @0x28df88 ldr r5, [r4, #0x4] */
/* @0x28df8c ldr r2, [sp, #0x2c] */
/* @0x28df90 cmp r5, #0 */
/* @0x28df94 str r2, [r8, #0x14] */
/* @0x28df98 movne r7, #0 */
/* @0x28df9c movne r12, r4 */
/* @0x28dfa0 beq 0x28e010 <spSkeletonJson_readSkeletonData+0x27c4> */
/* @0x28dfa4 mov r0, r5 */
/* @0x28dfa8 ldr r1, [sp, #0x3c] */
/* @0x28dfac mov r2, #0 */
/* @0x28dfb0 str r12, [sp, #0x14] */
/* @0x28dfb4 bl 0x287444 <Json_getFloat> */
/* @0x28dfb8 mov r1, r6 */
/* @0x28dfbc mov r2, #0 */
/* @0x28dfc0 mov r4, r0 */
/* @0x28dfc4 mov r0, r5 */
/* @0x28dfc8 bl 0x287444 <Json_getFloat> */
/* @0x28dfcc mov r1, r7 */
/* @0x28dfd0 mov r2, r4 */
/* @0x28dfd4 vmov s14, r0 */
/* @0x28dfd8 mov r0, r8 */
/* @0x28dfdc vmul.f32 s15, s14, s16 */
/* @0x28dfe0 vmov r3, s15 */
/* @0x28dfe4 bl 0x283028 <spPathConstraintPositionTimeline_setFrame> */
/* @0x28dfe8 mov r0, r5 */
/* @0x28dfec mov r2, r7 */
/* @0x28dff0 mov r1, r8 */
/* @0x28dff4 bl 0x28b34c <spSkeletonData_findPathConstraint+0x5c> */
/* @0x28dff8 ldr r5, [r5] */
/* @0x28dffc add r7, r7, #1 */
/* @0x28e000 ldr r12, [sp, #0x14] */
/* @0x28e004 cmp r5, #0 */
/* @0x28e008 bne 0x28dfa4 <spSkeletonJson_readSkeletonData+0x2758> */
/* @0x28e00c mov r4, r12 */
/* @0x28e010 ldr r3, [r11, #0x8] */
/* @0x28e014 vldr s14, [r11, #4] */
/* @0x28e018 ldr r1, [r11, #0xc] */
/* @0x28e01c add r2, r3, #1 */
/* @0x28e020 str r2, [r11, #0x8] */
/* @0x28e024 ldr r2, [r4, #0xc] */
/* @0x28e028 str r8, [r1, r3, lsl #2] */
/* @0x28e02c ldr r3, [r8, #0x10] */
/* @0x28e030 add r3, r3, r2, lsl #3 */
/* @0x28e034 vldr s15, [r3, #-8] */
/* @0x28e038 vcmpe.f32 s14, s15 */
/* @0x28e03c vmrs APSR_nzcv, fpscr */
/* @0x28e040 vmovgt.f32 s15, s14 */
/* @0x28e044 vstr s15, [r11, #4] */
/* @0x28e048 ldr r4, [r4] */
/* @0x28e04c cmp r4, #0 */
/* @0x28e050 bne 0x28df3c <spSkeletonJson_readSkeletonData+0x26f0> */
/* @0x28e054 ldr r10, [r10] */
/* @0x28e058 cmp r10, #0 */
/* @0x28e05c bne 0x28ded4 <spSkeletonJson_readSkeletonData+0x2688> */
/* @0x28e060 ldr r1, [sp, #0x50] */
/* @0x28e064 cmp r1, #0 */
/* @0x28e068 beq 0x28e338 <spSkeletonJson_readSkeletonData+0x2aec> */
/* @0x28e06c ldr r0, [sp, #0x50] */
/* @0x28e070 ldr r0, [r0, #0x4] */
/* @0x28e074 cmp r0, #0 */
/* @0x28e078 str r0, [sp, #0x2c] */
/* @0x28e07c beq 0x28e338 <spSkeletonJson_readSkeletonData+0x2aec> */
/* @0x28e080 ldr r1, [pc, #0xa38] */
/* @0x28e084 mov r10, r11 */
/* @0x28e088 ldr r2, [pc, #0xa34] */
/* @0x28e08c ldr r3, [pc, #0xa34] */
/* @0x28e090 add r1, pc, r1 */
/* @0x28e094 ldr r0, [pc, #0xa30] */
/* @0x28e098 add r2, pc, r2 */
/* @0x28e09c add r3, pc, r3 */
/* @0x28e0a0 str r1, [sp, #0x50] */
/* @0x28e0a4 add r0, pc, r0 */
/* @0x28e0a8 str r2, [sp, #0x48] */
/* @0x28e0ac str r3, [sp, #0x54] */
/* @0x28e0b0 str r0, [sp, #0x58] */
/* @0x28e0b4 ldr r2, [sp, #0x2c] */
/* @0x28e0b8 ldr r0, [sp, #0x18] */
/* @0x28e0bc ldr r1, [r2, #0x1c] */
/* @0x28e0c0 bl 0x28b124 <spSkeletonData_findSkin> */
/* @0x28e0c4 ldr r3, [sp, #0x2c] */
/* @0x28e0c8 ldr r8, [r3, #0x4] */
/* @0x28e0cc cmp r8, #0 */
/* @0x28e0d0 movne r11, r8 */
/* @0x28e0d4 str r0, [sp, #0x40] */
/* @0x28e0d8 beq 0x28e320 <spSkeletonJson_readSkeletonData+0x2ad4> */
/* @0x28e0dc ldr r0, [sp, #0x18] */
/* @0x28e0e0 ldr r1, [r11, #0x1c] */
/* @0x28e0e4 bl 0x28b0cc <spSkeletonData_findSlotIndex> */
/* @0x28e0e8 ldr r9, [r11, #0x4] */
/* @0x28e0ec cmp r9, #0 */
/* @0x28e0f0 strne r11, [sp, #0x5c] */
/* @0x28e0f4 str r0, [sp, #0x3c] */
/* @0x28e0f8 beq 0x28e314 <spSkeletonJson_readSkeletonData+0x2ac8> */
/* @0x28e0fc ldr r0, [sp, #0x40] */
/* @0x28e100 ldr r1, [sp, #0x3c] */
/* @0x28e104 ldr r2, [r9, #0x1c] */
/* @0x28e108 bl 0x28ed00 <spSkin_getAttachment> */
/* @0x28e10c subs r8, r0, #0 */
/* @0x28e110 beq 0x28e55c <spSkeletonJson_readSkeletonData+0x2d10> */
/* @0x28e114 ldr r3, [r8, #0x14] */
/* @0x28e118 adds r3, r3, #0 */
/* @0x28e11c movne r3, #1 */
/* @0x28e120 cmp r3, #0 */
/* @0x28e124 str r3, [sp, #0x34] */
/* @0x28e128 ldrne r1, [sp, #0x60] */
/* @0x28e12c ldrne r3, [r8, #0x18] */
/* @0x28e130 ldreq r11, [r8, #0x18] */
/* @0x28e134 smullne r1, r2, r1, r3 */
/* @0x28e138 ldr r1, [sp, #0x50] */
/* @0x28e13c subne r3, r2, r3, asr #31 */
/* @0x28e140 lslne r11, r3, #1 */
/* @0x28e144 lsl r2, r11, #2 */
/* @0x28e148 str r2, [sp, #0x38] */
/* @0x28e14c ldr r0, [sp, #0x38] */
/* @0x28e150 mov r2, #388 */
/* @0x28e154 bl 0x285c10 <_malloc> */
/* @0x28e158 mov r1, r11 */
/* @0x28e15c mov r4, r0 */
/* @0x28e160 ldr r0, [r9, #0xc] */
/* @0x28e164 bl 0x282e58 <spDeformTimeline_create> */
/* @0x28e168 ldr r5, [r9, #0x4] */
/* @0x28e16c ldr r3, [sp, #0x3c] */
/* @0x28e170 cmp r5, #0 */
/* @0x28e174 mov r7, r0 */
/* @0x28e178 str r3, [r0, #0x1c] */
/* @0x28e17c str r8, [r0, #0x20] */
/* @0x28e180 beq 0x28e2c4 <spSkeletonJson_readSkeletonData+0x2a78> */
/* @0x28e184 vmov.f32 s16, #1.000000e+00 */
/* @0x28e188 ldr r0, [sp, #0x38] */
/* @0x28e18c mov r1, #0 */
/* @0x28e190 str r1, [sp, #0x30] */
/* @0x28e194 add r0, r0, r4 */
/* @0x28e198 str r0, [sp, #0x44] */
/* @0x28e19c mov r0, r5 */
/* @0x28e1a0 ldr r1, [sp, #0x48] */
/* @0x28e1a4 bl 0x2873c4 <Json_getItem> */
/* @0x28e1a8 subs r12, r0, #0 */
/* @0x28e1ac beq 0x28e820 <spSkeletonJson_readSkeletonData+0x2fd4> */
/* @0x28e1b0 ldr r1, [sp, #0x54] */
/* @0x28e1b4 mov r2, #0 */
/* @0x28e1b8 mov r0, r5 */
/* @0x28e1bc str r12, [sp, #0x14] */
/* @0x28e1c0 bl 0x287460 <Json_getInt> */
/* @0x28e1c4 mov r1, #0 */
/* @0x28e1c8 lsl r3, r0, #2 */
/* @0x28e1cc mov r6, r0 */
/* @0x28e1d0 mov r0, r4 */
/* @0x28e1d4 str r3, [sp, #0x10] */
/* @0x28e1d8 mov r2, r3 */
/* @0x28e1dc bl 0xb65b0 <memset@plt> */
/* @0x28e1e0 ldr r0, [sp, #0x20] */
/* @0x28e1e4 vldr s15, [r0] */
/* @0x28e1e8 vcmp.f32 s15, s16 */
/* @0x28e1ec ldr r12, [sp, #0x14] */
/* @0x28e1f0 ldr r3, [sp, #0x10] */
/* @0x28e1f4 vmrs APSR_nzcv, fpscr */
/* @0x28e1f8 ldr r2, [r12, #0x4] */
/* @0x28e1fc bne 0x28e848 <spSkeletonJson_readSkeletonData+0x2ffc> */
/* @0x28e200 cmp r2, #0 */
/* @0x28e204 beq 0x28e228 <spSkeletonJson_readSkeletonData+0x29dc> */
/* @0x28e208 add r3, r4, r3 */
/* @0x28e20c ldr r1, [r2, #0x18] */
/* @0x28e210 add r6, r6, #1 */
/* @0x28e214 ldr r2, [r2] */
/* @0x28e218 cmp r2, #0 */
/* @0x28e21c str r1, [r3], #4 */
/* @0x28e220 bne 0x28e20c <spSkeletonJson_readSkeletonData+0x29c0> */
/* @0x28e224 lsl r3, r6, #2 */
/* @0x28e228 rsb r2, r6, r11 */
/* @0x28e22c add r0, r4, r3 */
/* @0x28e230 mov r1, #0 */
/* @0x28e234 lsl r2, r2, #2 */
/* @0x28e238 bl 0xb65b0 <memset@plt> */
/* @0x28e23c ldr r2, [sp, #0x34] */
/* @0x28e240 cmp r2, #0 */
/* @0x28e244 bne 0x28e274 <spSkeletonJson_readSkeletonData+0x2a28> */
/* @0x28e248 cmp r11, #0 */
/* @0x28e24c ldr r2, [r8, #0x1c] */
/* @0x28e250 ble 0x28e274 <spSkeletonJson_readSkeletonData+0x2a28> */
/* @0x28e254 mov r3, r4 */
/* @0x28e258 vldr s14, [r3] */
/* @0x28e25c vldmia r2!, {s15} */
/* @0x28e260 vadd.f32 s15, s14, s15 */
/* @0x28e264 ldr r0, [sp, #0x44] */
/* @0x28e268 vstmia r3!, {s15} */
/* @0x28e26c cmp r3, r0 */
/* @0x28e270 bne 0x28e258 <spSkeletonJson_readSkeletonData+0x2a0c> */
/* @0x28e274 mov r6, r4 */
/* @0x28e278 mov r0, r5 */
/* @0x28e27c ldr r1, [sp, #0x58] */
/* @0x28e280 mov r2, #0 */
/* @0x28e284 bl 0x287444 <Json_getFloat> */
/* @0x28e288 ldr r1, [sp, #0x30] */
/* @0x28e28c mov r3, r6 */
/* @0x28e290 mov r2, r0 */
/* @0x28e294 mov r0, r7 */
/* @0x28e298 bl 0x282ef8 <spDeformTimeline_setFrame> */
/* @0x28e29c mov r0, r5 */
/* @0x28e2a0 mov r1, r7 */
/* @0x28e2a4 ldr r2, [sp, #0x30] */
/* @0x28e2a8 bl 0x28b34c <spSkeletonData_findPathConstraint+0x5c> */
/* @0x28e2ac ldr r5, [r5] */
/* @0x28e2b0 ldr r1, [sp, #0x30] */
/* @0x28e2b4 cmp r5, #0 */
/* @0x28e2b8 add r1, r1, #1 */
/* @0x28e2bc str r1, [sp, #0x30] */
/* @0x28e2c0 bne 0x28e19c <spSkeletonJson_readSkeletonData+0x2950> */
/* @0x28e2c4 mov r0, r4 */
/* @0x28e2c8 bl 0x285c80 <_free> */
/* @0x28e2cc ldr r3, [r10, #0x8] */
/* @0x28e2d0 ldr r1, [r10, #0xc] */
/* @0x28e2d4 vldr s14, [r10, #4] */
/* @0x28e2d8 add r2, r3, #1 */
/* @0x28e2dc str r2, [r10, #0x8] */
/* @0x28e2e0 ldr r2, [r9, #0xc] */
/* @0x28e2e4 str r7, [r1, r3, lsl #2] */
/* @0x28e2e8 ldr r3, [r7, #0x10] */
/* @0x28e2ec ldr r9, [r9] */
/* @0x28e2f0 add r3, r3, r2, lsl #2 */
/* @0x28e2f4 vldr s15, [r3, #-4] */
/* @0x28e2f8 vcmpe.f32 s14, s15 */
/* @0x28e2fc vmrs APSR_nzcv, fpscr */
/* @0x28e300 vmovgt.f32 s15, s14 */
/* @0x28e304 cmp r9, #0 */
/* @0x28e308 vstr s15, [r10, #4] */
/* @0x28e30c bne 0x28e0fc <spSkeletonJson_readSkeletonData+0x28b0> */
/* @0x28e310 ldr r11, [sp, #0x5c] */
/* @0x28e314 ldr r11, [r11] */
/* @0x28e318 cmp r11, #0 */
/* @0x28e31c bne 0x28e0dc <spSkeletonJson_readSkeletonData+0x2890> */
/* @0x28e320 ldr r0, [sp, #0x2c] */
/* @0x28e324 ldr r0, [r0] */
/* @0x28e328 cmp r0, #0 */
/* @0x28e32c str r0, [sp, #0x2c] */
/* @0x28e330 bne 0x28e0b4 <spSkeletonJson_readSkeletonData+0x2868> */
/* @0x28e334 mov r11, r10 */
/* @0x28e338 ldr r3, [sp, #0x28] */
/* @0x28e33c cmp r3, #0 */
/* @0x28e340 beq 0x28e614 <spSkeletonJson_readSkeletonData+0x2dc8> */
/* @0x28e344 ldr r2, [sp, #0x28] */
/* @0x28e348 ldr r3, [sp, #0x18] */
/* @0x28e34c ldr r0, [r2, #0xc] */
/* @0x28e350 ldr r1, [r3, #0x18] */
/* @0x28e354 bl 0x282d4c <spDrawOrderTimeline_create> */
/* @0x28e358 str r0, [sp, #0x2c] */
/* @0x28e35c ldr r0, [sp, #0x28] */
/* @0x28e360 ldr r9, [r0, #0x4] */
/* @0x28e364 cmp r9, #0 */
/* @0x28e368 beq 0x28e5d4 <spSkeletonJson_readSkeletonData+0x2d88> */
/* @0x28e36c ldr r1, [pc, #0x75c] */
/* @0x28e370 mov r10, #0 */
/* @0x28e374 ldr r8, [sp, #0x18] */
/* @0x28e378 add r1, pc, r1 */
/* @0x28e37c ldr r2, [pc, #0x750] */
/* @0x28e380 str r1, [sp, #0x3c] */
/* @0x28e384 ldr r3, [pc, #0x74c] */
/* @0x28e388 add r2, pc, r2 */
/* @0x28e38c ldr r0, [pc, #0x748] */
/* @0x28e390 ldr r1, [pc, #0x748] */
/* @0x28e394 add r3, pc, r3 */
/* @0x28e398 add r0, pc, r0 */
/* @0x28e39c str r2, [sp, #0x30] */
/* @0x28e3a0 add r1, pc, r1 */
/* @0x28e3a4 str r3, [sp, #0x34] */
/* @0x28e3a8 str r0, [sp, #0x40] */
/* @0x28e3ac str r1, [sp, #0x44] */
/* @0x28e3b0 str r11, [sp, #0x38] */
/* @0x28e3b4 mov r0, r9 */
/* @0x28e3b8 ldr r1, [sp, #0x3c] */
/* @0x28e3bc bl 0x2873c4 <Json_getItem> */
/* @0x28e3c0 subs r4, r0, #0 */
/* @0x28e3c4 beq 0x28e590 <spSkeletonJson_readSkeletonData+0x2d44> */
/* @0x28e3c8 ldr r3, [r4, #0xc] */
/* @0x28e3cc movw r2, #0x1ba */
/* @0x28e3d0 ldr r0, [r8, #0x18] */
/* @0x28e3d4 ldr r1, [sp, #0x30] */
/* @0x28e3d8 rsb r0, r3, r0 */
/* @0x28e3dc lsl r0, r0, #2 */
/* @0x28e3e0 bl 0x285c10 <_malloc> */
/* @0x28e3e4 ldr r1, [sp, #0x30] */
/* @0x28e3e8 movw r2, #0x1bd */
/* @0x28e3ec mov r11, r0 */
/* @0x28e3f0 ldr r0, [r8, #0x18] */
/* @0x28e3f4 lsl r0, r0, #2 */
/* @0x28e3f8 bl 0x285c10 <_malloc> */
/* @0x28e3fc ldr r2, [r8, #0x18] */
/* @0x28e400 subs r1, r2, #1 */
/* @0x28e404 mov r6, r0 */
/* @0x28e408 addpl r2, r0, r2, lsl #2 */
/* @0x28e40c mvnpl r0, #0 */
/* @0x28e410 bmi 0x28e424 <spSkeletonJson_readSkeletonData+0x2bd8> */
/* @0x28e414 sub r1, r1, #1 */
/* @0x28e418 str r0, [r2, #-0x4]! */
/* @0x28e41c cmn r1, #1 */
/* @0x28e420 bne 0x28e414 <spSkeletonJson_readSkeletonData+0x2bc8> */
/* @0x28e424 ldr r7, [r4, #0x4] */
/* @0x28e428 cmp r7, #0 */
/* @0x28e42c moveq r5, r7 */
/* @0x28e430 moveq r4, r5 */
/* @0x28e434 beq 0x28e4c4 <spSkeletonJson_readSkeletonData+0x2c78> */
/* @0x28e438 mov r5, #0 */
/* @0x28e43c mov r4, r5 */
/* @0x28e440 ldr r1, [sp, #0x34] */
/* @0x28e444 mov r2, #0 */
/* @0x28e448 mov r0, r7 */
/* @0x28e44c bl 0x287428 <Json_getString> */
/* @0x28e450 mov r1, r0 */
/* @0x28e454 mov r0, r8 */
/* @0x28e458 bl 0x28b0cc <spSkeletonData_findSlotIndex> */
/* @0x28e45c cmn r0, #1 */
/* @0x28e460 mov r3, r0 */
/* @0x28e464 beq 0x28e8ac <spSkeletonJson_readSkeletonData+0x3060> */
/* @0x28e468 cmp r0, r4 */
/* @0x28e46c subne r1, r5, #-1073741823 */
/* @0x28e470 movne r2, r4 */
/* @0x28e474 addne r1, r11, r1, lsl #2 */
/* @0x28e478 beq 0x28e49c <spSkeletonJson_readSkeletonData+0x2c50> */
/* @0x28e47c add r0, r2, #1 */
/* @0x28e480 str r2, [r1, #0x4]! */
/* @0x28e484 cmp r0, r3 */
/* @0x28e488 mov r2, r0 */
/* @0x28e48c bne 0x28e47c <spSkeletonJson_readSkeletonData+0x2c30> */
/* @0x28e490 add r5, r3, r5 */
/* @0x28e494 rsb r5, r4, r5 */
/* @0x28e498 mov r4, r3 */
/* @0x28e49c mov r0, r7 */
/* @0x28e4a0 ldr r1, [sp, #0x40] */
/* @0x28e4a4 mov r2, #0 */
/* @0x28e4a8 bl 0x287460 <Json_getInt> */
/* @0x28e4ac ldr r7, [r7] */
/* @0x28e4b0 cmp r7, #0 */
/* @0x28e4b4 add r0, r4, r0 */
/* @0x28e4b8 str r4, [r6, r0, lsl #2] */
/* @0x28e4bc add r4, r4, #1 */
/* @0x28e4c0 bne 0x28e440 <spSkeletonJson_readSkeletonData+0x2bf4> */
/* @0x28e4c4 ldr r2, [r8, #0x18] */
/* @0x28e4c8 cmp r4, r2 */
/* @0x28e4cc bge 0x28e4f4 <spSkeletonJson_readSkeletonData+0x2ca8> */
/* @0x28e4d0 sub r1, r5, #-1073741823 */
/* @0x28e4d4 add r1, r11, r1, lsl #2 */
/* @0x28e4d8 str r4, [r1, #0x4]! */
/* @0x28e4dc add r3, r4, #1 */
/* @0x28e4e0 ldr r2, [r8, #0x18] */
/* @0x28e4e4 add r5, r5, #1 */
/* @0x28e4e8 mov r4, r3 */
/* @0x28e4ec cmp r3, r2 */
/* @0x28e4f0 blt 0x28e4d8 <spSkeletonJson_readSkeletonData+0x2c8c> */
/* @0x28e4f4 subs r1, r2, #1 */
/* @0x28e4f8 addpl r2, r6, r2, lsl #2 */
/* @0x28e4fc bmi 0x28e520 <spSkeletonJson_readSkeletonData+0x2cd4> */
/* @0x28e500 ldr r3, [r2, #-0x4]! */
/* @0x28e504 sub r1, r1, #1 */
/* @0x28e508 cmn r3, #1 */
/* @0x28e50c subeq r5, r5, #1 */
/* @0x28e510 ldreq r3, [r11, r5, lsl #2] */
/* @0x28e514 streq r3, [r2] */
/* @0x28e518 cmn r1, #1 */
/* @0x28e51c bne 0x28e500 <spSkeletonJson_readSkeletonData+0x2cb4> */
/* @0x28e520 mov r0, r11 */
/* @0x28e524 bl 0x285c80 <_free> */
/* @0x28e528 b 0x28e594 <spSkeletonJson_readSkeletonData+0x2d48> */
/* @0x28e52c ldr r1, [sp, #0x44] */
/* @0x28e530 bl 0xb6574 <strcmp@plt> */
/* @0x28e534 cmp r0, #0 */
/* @0x28e538 bne 0x28e8ec <spSkeletonJson_readSkeletonData+0x30a0> */
/* @0x28e53c ldr r0, [r4, #0xc] */
/* @0x28e540 bl 0x28303c <spPathConstraintSpacingTimeline_create> */
/* @0x28e544 ldr r3, [r9, #0x14] */
/* @0x28e548 cmp r3, #1 */
/* @0x28e54c mov r8, r0 */
/* @0x28e550 bls 0x28ea74 <spSkeletonJson_readSkeletonData+0x3228> */
/* @0x28e554 vmov.f32 s16, #1.000000e+00 */
/* @0x28e558 b 0x28df88 <spSkeletonJson_readSkeletonData+0x273c> */
/* @0x28e55c mov r5, r8 */
/* @0x28e560 mov r0, r10 */
/* @0x28e564 ldr r8, [sp, #0x20] */
/* @0x28e568 mov r7, r9 */
/* @0x28e56c ldr r9, [sp, #0x18] */
/* @0x28e570 bl 0x28147c <spAnimation_dispose> */
/* @0x28e574 ldr r2, [pc, #0x568] */
/* @0x28e578 mov r1, r5 */
/* @0x28e57c mov r0, r8 */
/* @0x28e580 ldr r3, [r7, #0x1c] */
/* @0x28e584 add r2, pc, r2 */
/* @0x28e588 bl 0x28b784 <_spSkeletonJson_setError> */
/* @0x28e58c b 0x28da44 <spSkeletonJson_readSkeletonData+0x21f8> */
/* @0x28e590 mov r6, r4 */
/* @0x28e594 mov r0, r9 */
/* @0x28e598 ldr r1, [sp, #0x44] */
/* @0x28e59c mov r2, #0 */
/* @0x28e5a0 bl 0x287444 <Json_getFloat> */
/* @0x28e5a4 mov r1, r10 */
/* @0x28e5a8 mov r3, r6 */
/* @0x28e5ac add r10, r10, #1 */
/* @0x28e5b0 mov r2, r0 */
/* @0x28e5b4 ldr r0, [sp, #0x2c] */
/* @0x28e5b8 bl 0x282ddc <spDrawOrderTimeline_setFrame> */
/* @0x28e5bc mov r0, r6 */
/* @0x28e5c0 bl 0x285c80 <_free> */
/* @0x28e5c4 ldr r9, [r9] */
/* @0x28e5c8 cmp r9, #0 */
/* @0x28e5cc bne 0x28e3b4 <spSkeletonJson_readSkeletonData+0x2b68> */
/* @0x28e5d0 ldr r11, [sp, #0x38] */
/* @0x28e5d4 ldr r0, [sp, #0x28] */
/* @0x28e5d8 vldr s14, [r11, #4] */
/* @0x28e5dc ldr r3, [r11, #0x8] */
/* @0x28e5e0 ldr r1, [r11, #0xc] */
/* @0x28e5e4 ldr r2, [r0, #0xc] */
/* @0x28e5e8 add r0, r3, #1 */
/* @0x28e5ec str r0, [r11, #0x8] */
/* @0x28e5f0 ldr r0, [sp, #0x2c] */
/* @0x28e5f4 str r0, [r1, r3, lsl #2] */
/* @0x28e5f8 ldr r3, [r0, #0xc] */
/* @0x28e5fc add r3, r3, r2, lsl #2 */
/* @0x28e600 vldr s15, [r3, #-4] */
/* @0x28e604 vcmpe.f32 s14, s15 */
/* @0x28e608 vmrs APSR_nzcv, fpscr */
/* @0x28e60c vmovgt.f32 s15, s14 */
/* @0x28e610 vstr s15, [r11, #4] */
/* @0x28e614 ldr r2, [sp, #0x4c] */
/* @0x28e618 cmp r2, #0 */
/* @0x28e61c beq 0x28e774 <spSkeletonJson_readSkeletonData+0x2f28> */
/* @0x28e620 ldr r0, [r2, #0xc] */
/* @0x28e624 bl 0x282c8c <spEventTimeline_create> */
/* @0x28e628 ldr r3, [sp, #0x4c] */
/* @0x28e62c ldr r10, [r3, #0x4] */
/* @0x28e630 cmp r10, #0 */
/* @0x28e634 mov r6, r0 */
/* @0x28e638 beq 0x28e738 <spSkeletonJson_readSkeletonData+0x2eec> */
/* @0x28e63c ldr r3, [pc, #0x4a4] */
/* @0x28e640 mov r5, #0 */
/* @0x28e644 ldr r7, [pc, #0x4a0] */
/* @0x28e648 add r3, pc, r3 */
/* @0x28e64c ldr r9, [pc, #0x49c] */
/* @0x28e650 str r3, [sp, #0x28] */
/* @0x28e654 add r7, pc, r7 */
/* @0x28e658 ldr r3, [pc, #0x494] */
/* @0x28e65c add r9, pc, r9 */
/* @0x28e660 add r3, pc, r3 */
/* @0x28e664 str r3, [sp, #0x2c] */
/* @0x28e668 ldr r3, [pc, #0x488] */
/* @0x28e66c add r3, pc, r3 */
/* @0x28e670 str r3, [sp, #0x30] */
/* @0x28e674 mov r2, #0 */
/* @0x28e678 mov r1, r7 */
/* @0x28e67c mov r0, r10 */
/* @0x28e680 bl 0x287428 <Json_getString> */
/* @0x28e684 mov r1, r0 */
/* @0x28e688 ldr r0, [sp, #0x18] */
/* @0x28e68c bl 0x28b180 <spSkeletonData_findEvent> */
/* @0x28e690 mov r2, #0 */
/* @0x28e694 ldr r1, [sp, #0x28] */
/* @0x28e698 subs r8, r0, #0 */
/* @0x28e69c mov r0, r10 */
/* @0x28e6a0 beq 0x28e7b4 <spSkeletonJson_readSkeletonData+0x2f68> */
/* @0x28e6a4 bl 0x287444 <Json_getFloat> */
/* @0x28e6a8 mov r1, r8 */
/* @0x28e6ac bl 0x285b44 <spEvent_create> */
/* @0x28e6b0 ldr r2, [r8, #0x4] */
/* @0x28e6b4 mov r1, r9 */
/* @0x28e6b8 mov r4, r0 */
/* @0x28e6bc mov r0, r10 */
/* @0x28e6c0 bl 0x287460 <Json_getInt> */
/* @0x28e6c4 ldr r2, [r8, #0x8] */
/* @0x28e6c8 ldr r1, [sp, #0x2c] */
/* @0x28e6cc str r0, [r4, #0x8] */
/* @0x28e6d0 mov r0, r10 */
/* @0x28e6d4 bl 0x287444 <Json_getFloat> */
/* @0x28e6d8 ldr r2, [r8, #0xc] */
/* @0x28e6dc ldr r1, [sp, #0x30] */
/* @0x28e6e0 str r0, [r4, #0xc] */
/* @0x28e6e4 mov r0, r10 */
/* @0x28e6e8 bl 0x287428 <Json_getString> */
/* @0x28e6ec subs r8, r0, #0 */
/* @0x28e6f0 beq 0x28e718 <spSkeletonJson_readSkeletonData+0x2ecc> */
/* @0x28e6f4 bl 0xb6538 <strlen@plt> */
/* @0x28e6f8 ldr r1, [pc, #0x3fc] */
/* @0x28e6fc movw r2, #0x1ee */
/* @0x28e700 add r1, pc, r1 */
/* @0x28e704 add r0, r0, #1 */
/* @0x28e708 bl 0x285c10 <_malloc> */
/* @0x28e70c mov r1, r8 */
/* @0x28e710 str r0, [r4, #0x10] */
/* @0x28e714 bl 0xb65a4 <strcpy@plt> */
/* @0x28e718 mov r1, r5 */
/* @0x28e71c mov r2, r4 */
/* @0x28e720 mov r0, r6 */
/* @0x28e724 add r5, r5, #1 */
/* @0x28e728 bl 0x282d14 <spEventTimeline_setFrame> */
/* @0x28e72c ldr r10, [r10] */
/* @0x28e730 cmp r10, #0 */
/* @0x28e734 bne 0x28e674 <spSkeletonJson_readSkeletonData+0x2e28> */
/* @0x28e738 ldr r0, [sp, #0x4c] */
/* @0x28e73c vldr s14, [r11, #4] */
/* @0x28e740 ldr r3, [r11, #0x8] */
/* @0x28e744 ldr r1, [r11, #0xc] */
/* @0x28e748 ldr r2, [r0, #0xc] */
/* @0x28e74c add r0, r3, #1 */
/* @0x28e750 str r0, [r11, #0x8] */
/* @0x28e754 str r6, [r1, r3, lsl #2] */
/* @0x28e758 ldr r3, [r6, #0xc] */
/* @0x28e75c add r3, r3, r2, lsl #2 */
/* @0x28e760 vldr s15, [r3, #-4] */
/* @0x28e764 vcmpe.f32 s14, s15 */
/* @0x28e768 vmrs APSR_nzcv, fpscr */
/* @0x28e76c vmovgt.f32 s15, s14 */
/* @0x28e770 vstr s15, [r11, #4] */
/* @0x28e774 ldr r0, [sp, #0x18] */
/* @0x28e778 ldr r3, [r0, #0x34] */
/* @0x28e77c ldr r2, [r0, #0x38] */
/* @0x28e780 add r1, r3, #1 */
/* @0x28e784 str r1, [r0, #0x34] */
/* @0x28e788 ldr r1, [sp, #0x1c] */
/* @0x28e78c str r11, [r2, r3, lsl #2] */
/* @0x28e790 ldr r1, [r1] */
/* @0x28e794 cmp r1, #0 */
/* @0x28e798 str r1, [sp, #0x1c] */
/* @0x28e79c bne 0x28d318 <spSkeletonJson_readSkeletonData+0x1acc> */
/* @0x28e7a0 mov r9, r0 */
/* @0x28e7a4 ldr r0, [sp, #0x24] */
/* @0x28e7a8 bl 0x2872c8 <Json_dispose> */
/* @0x28e7ac mov r0, r9 */
/* @0x28e7b0 b 0x28bdcc <spSkeletonJson_readSkeletonData+0x580> */
/* @0x28e7b4 mov r4, r8 */
/* @0x28e7b8 mov r0, r11 */
/* @0x28e7bc ldr r8, [sp, #0x20] */
/* @0x28e7c0 ldr r9, [sp, #0x18] */
/* @0x28e7c4 bl 0x28147c <spAnimation_dispose> */
/* @0x28e7c8 mov r1, r7 */
/* @0x28e7cc mov r2, r4 */
/* @0x28e7d0 mov r0, r10 */
/* @0x28e7d4 bl 0x287428 <Json_getString> */
/* @0x28e7d8 ldr r2, [pc, #0x320] */
/* @0x28e7dc mov r1, r4 */
/* @0x28e7e0 add r2, pc, r2 */
/* @0x28e7e4 mov r3, r0 */
/* @0x28e7e8 mov r0, r8 */
/* @0x28e7ec bl 0x28b784 <_spSkeletonJson_setError> */
/* @0x28e7f0 b 0x28da44 <spSkeletonJson_readSkeletonData+0x21f8> */
/* @0x28e7f4 ldr r9, [sp, #0x34] */
/* @0x28e7f8 mov r0, r9 */
/* @0x28e7fc bl 0x28adf8 <spSkeletonData_dispose> */
/* @0x28e800 ldr r2, [pc, #0x2fc] */
/* @0x28e804 mov r0, r8 */
/* @0x28e808 ldr r1, [sp, #0x24] */
/* @0x28e80c mov r3, r10 */
/* @0x28e810 add r2, pc, r2 */
/* @0x28e814 bl 0x28b784 <_spSkeletonJson_setError> */
/* @0x28e818 mov r0, #0 */
/* @0x28e81c b 0x28bdcc <spSkeletonJson_readSkeletonData+0x580> */
/* @0x28e820 ldr r2, [sp, #0x34] */
/* @0x28e824 cmp r2, #0 */
/* @0x28e828 ldreq r6, [r8, #0x1c] */
/* @0x28e82c beq 0x28e278 <spSkeletonJson_readSkeletonData+0x2a2c> */
/* @0x28e830 mov r1, r12 */
/* @0x28e834 mov r0, r4 */
/* @0x28e838 ldr r2, [sp, #0x38] */
/* @0x28e83c mov r6, r4 */
/* @0x28e840 bl 0xb65b0 <memset@plt> */
/* @0x28e844 b 0x28e278 <spSkeletonJson_readSkeletonData+0x2a2c> */
/* @0x28e848 cmp r2, #0 */
/* @0x28e84c beq 0x28e228 <spSkeletonJson_readSkeletonData+0x29dc> */
/* @0x28e850 add r3, r4, r3 */
/* @0x28e854 b 0x28e860 <spSkeletonJson_readSkeletonData+0x3014> */
/* @0x28e858 ldr r1, [sp, #0x20] */
/* @0x28e85c vldr s15, [r1] */
/* @0x28e860 vldr s14, [r2, #24] */
/* @0x28e864 vmul.f32 s15, s15, s14 */
/* @0x28e868 ldr r2, [r2] */
/* @0x28e86c add r6, r6, #1 */
/* @0x28e870 cmp r2, #0 */
/* @0x28e874 vstmia r3!, {s15} */
/* @0x28e878 bne 0x28e858 <spSkeletonJson_readSkeletonData+0x300c> */
/* @0x28e87c b 0x28e224 <spSkeletonJson_readSkeletonData+0x29d8> */
/* @0x28e880 mov r5, r0 */
/* @0x28e884 mov r0, r9 */
/* @0x28e888 bl 0x28adf8 <spSkeletonData_dispose> */
/* @0x28e88c ldr r2, [pc, #0x274] */
/* @0x28e890 mov r0, r8 */
/* @0x28e894 mov r1, r5 */
/* @0x28e898 ldr r3, [r4] */
/* @0x28e89c add r2, pc, r2 */
/* @0x28e8a0 bl 0x28b784 <_spSkeletonJson_setError> */
/* @0x28e8a4 mov r0, r5 */
/* @0x28e8a8 b 0x28bdcc <spSkeletonJson_readSkeletonData+0x580> */
/* @0x28e8ac ldr r11, [sp, #0x38] */
/* @0x28e8b0 mov r9, r8 */
/* @0x28e8b4 ldr r8, [sp, #0x20] */
/* @0x28e8b8 mov r0, r11 */
/* @0x28e8bc bl 0x28147c <spAnimation_dispose> */
/* @0x28e8c0 ldr r1, [sp, #0x34] */
/* @0x28e8c4 mov r0, r7 */
/* @0x28e8c8 mov r2, #0 */
/* @0x28e8cc bl 0x287428 <Json_getString> */
/* @0x28e8d0 ldr r2, [pc, #0x234] */
/* @0x28e8d4 mov r1, #0 */
/* @0x28e8d8 add r2, pc, r2 */
/* @0x28e8dc mov r3, r0 */
/* @0x28e8e0 mov r0, r8 */
/* @0x28e8e4 bl 0x28b784 <_spSkeletonJson_setError> */
/* @0x28e8e8 b 0x28da44 <spSkeletonJson_readSkeletonData+0x21f8> */
/* @0x28e8ec mov r0, r6 */
/* @0x28e8f0 ldr r1, [sp, #0x48] */
/* @0x28e8f4 bl 0xb6574 <strcmp@plt> */
/* @0x28e8f8 cmp r0, #0 */
/* @0x28e8fc beq 0x28e048 <spSkeletonJson_readSkeletonData+0x27fc> */
/* @0x28e900 ldr r0, [r4, #0xc] */
/* @0x28e904 bl 0x283068 <spPathConstraintMixTimeline_create> */
/* @0x28e908 ldr r5, [r4, #0x4] */
/* @0x28e90c cmp r5, #0 */
/* @0x28e910 mov r6, r0 */
/* @0x28e914 ldr r0, [sp, #0x2c] */
/* @0x28e918 str r0, [r6, #0x14] */
/* @0x28e91c beq 0x28e9cc <spSkeletonJson_readSkeletonData+0x3180> */
/* @0x28e920 ldr r8, [pc, #0x1e8] */
/* @0x28e924 mov r7, #0 */
/* @0x28e928 ldr r1, [pc, #0x1e4] */
/* @0x28e92c mov r12, r4 */
/* @0x28e930 ldr r2, [pc, #0x1e0] */
/* @0x28e934 add r8, pc, r8 */
/* @0x28e938 add r1, pc, r1 */
/* @0x28e93c str r1, [sp, #0x30] */
/* @0x28e940 add r2, pc, r2 */
/* @0x28e944 str r2, [sp, #0x34] */
/* @0x28e948 mov r0, r5 */
/* @0x28e94c mov r1, r8 */
/* @0x28e950 mov r2, #0 */
/* @0x28e954 str r12, [sp, #0x14] */
/* @0x28e958 bl 0x287444 <Json_getFloat> */
/* @0x28e95c ldr r1, [sp, #0x30] */
/* @0x28e960 mov r2, #1065353216 */
/* @0x28e964 mov r3, r0 */
/* @0x28e968 mov r0, r5 */
/* @0x28e96c str r3, [sp, #0x10] */
/* @0x28e970 bl 0x287444 <Json_getFloat> */
/* @0x28e974 ldr r1, [sp, #0x34] */
/* @0x28e978 mov r2, #1065353216 */
/* @0x28e97c mov r4, r0 */
/* @0x28e980 mov r0, r5 */
/* @0x28e984 bl 0x287444 <Json_getFloat> */
/* @0x28e988 ldr r3, [sp, #0x10] */
/* @0x28e98c mov r1, r7 */
/* @0x28e990 mov r2, r3 */
/* @0x28e994 mov r3, r4 */
/* @0x28e998 str r0, [sp] */
/* @0x28e99c mov r0, r6 */
/* @0x28e9a0 bl 0x283080 <spPathConstraintMixTimeline_setFrame> */
/* @0x28e9a4 mov r0, r5 */
/* @0x28e9a8 mov r2, r7 */
/* @0x28e9ac mov r1, r6 */
/* @0x28e9b0 bl 0x28b34c <spSkeletonData_findPathConstraint+0x5c> */
/* @0x28e9b4 ldr r5, [r5] */
/* @0x28e9b8 add r7, r7, #1 */
/* @0x28e9bc ldr r12, [sp, #0x14] */
/* @0x28e9c0 cmp r5, #0 */
/* @0x28e9c4 bne 0x28e948 <spSkeletonJson_readSkeletonData+0x30fc> */
/* @0x28e9c8 mov r4, r12 */
/* @0x28e9cc ldr r2, [r4, #0xc] */
/* @0x28e9d0 vldr s14, [r11, #4] */
/* @0x28e9d4 ldr r3, [r11, #0x8] */
/* @0x28e9d8 ldr r1, [r11, #0xc] */
/* @0x28e9dc sub r2, r2, #1 */
/* @0x28e9e0 add r0, r3, #1 */
/* @0x28e9e4 str r0, [r11, #0x8] */
/* @0x28e9e8 add r2, r2, r2, lsl #1 */
/* @0x28e9ec str r6, [r1, r3, lsl #2] */
/* @0x28e9f0 ldr r3, [r6, #0x10] */
/* @0x28e9f4 add r3, r3, r2, lsl #2 */
/* @0x28e9f8 vldr s15, [r3] */
/* @0x28e9fc vcmpe.f32 s14, s15 */
/* @0x28ea00 vmrs APSR_nzcv, fpscr */
/* @0x28ea04 vmovgt.f32 s15, s14 */
/* @0x28ea08 vstr s15, [r11, #4] */
/* @0x28ea0c b 0x28e048 <spSkeletonJson_readSkeletonData+0x27fc> */
/* @0x28ea10 mov r0, r11 */
/* @0x28ea14 ldr r8, [sp, #0x20] */
/* @0x28ea18 ldr r9, [sp, #0x18] */
/* @0x28ea1c bl 0x28147c <spAnimation_dispose> */
/* @0x28ea20 ldr r2, [sp, #0x2c] */
/* @0x28ea24 mov r0, r8 */
/* @0x28ea28 ldr r1, [sp, #0x1c] */
/* @0x28ea2c ldr r3, [r2, #0x1c] */
/* @0x28ea30 ldr r2, [pc, #0xe4] */
/* @0x28ea34 add r2, pc, r2 */
/* @0x28ea38 bl 0x28b784 <_spSkeletonJson_setError> */
/* @0x28ea3c b 0x28da44 <spSkeletonJson_readSkeletonData+0x21f8> */
/* @0x28ea40 mov r3, r2 */
/* @0x28ea44 b 0x28d3e4 <spSkeletonJson_readSkeletonData+0x1b98> */
/* @0x28ea48 ldr r8, [sp, #0x20] */
/* @0x28ea4c mov r0, r11 */
/* @0x28ea50 ldr r9, [sp, #0x18] */
/* @0x28ea54 bl 0x28147c <spAnimation_dispose> */
/* @0x28ea58 ldr r2, [pc, #0xc0] */
/* @0x28ea5c mov r0, r8 */
/* @0x28ea60 ldr r1, [sp, #0x1c] */
/* @0x28ea64 ldr r3, [r10, #0x1c] */
/* @0x28ea68 add r2, pc, r2 */
/* @0x28ea6c bl 0x28b784 <_spSkeletonJson_setError> */
/* @0x28ea70 b 0x28da44 <spSkeletonJson_readSkeletonData+0x21f8> */
/* @0x28ea74 ldr r0, [sp, #0x20] */
/* @0x28ea78 vldr s16, [r0] */
/* @0x28ea7c b 0x28df88 <spSkeletonJson_readSkeletonData+0x273c> */
/* @0x28ea80 ldr r3, [sp, #0x30] */
/* @0x28ea84 b 0x28d3e4 <spSkeletonJson_readSkeletonData+0x1b98> */
/* @0x28ea88 andeq lr, r11, r0, lsr r7 */
/* @0x28ea8c ldrdeq r2, r3, [r10], -r12 */
/* @0x28ea90 andeq r10, r12, r0, lsr r3 */
/* @0x28ea94 andeq r10, r12, r12, lsr r3 */
/* @0x28ea98 andeq lr, r11, r0, lsl #10 */
/* @0x28ea9c andeq r9, r12, r0, ror #31 */
/* @0x28eaa0 andeq r9, r12, r4, ror #31 */
/* @0x28eaa4 andeq r9, r12, r12, ror #31 */
/* @0x28eaa8 strdeq r9, r10, [r12], -r0 */
/* @0x28eaac ldrdeq r9, r10, [r12], -r12 */
/* @0x28eab0 andeq lr, r11, r4, lsr #6 */
/* @0x28eab4 andeq r9, r12, r12, asr #29 */
/* @0x28eab8 andeq r9, r12, r8, asr #29 */
/* @0x28eabc andeq r9, r12, r12, asr #27 */
/* @0x28eac0 andeq r9, r12, r0, ror r10 */
/* @0x28eac4 andeq r9, r12, r12, asr r10 */
/* @0x28eac8 andeq r9, r12, r0, lsr #29 */
/* @0x28eacc andeq lr, r11, r8, lsr #2 */
/* @0x28ead0 andeq r9, r12, r12, asr #23 */
/* @0x28ead4 andeq r9, r12, r8, ror r7 */
/* @0x28ead8 strheq r9, [r12], -r8 */
/* @0x28eadc andeq r9, r12, r4, lsr #23 */
/* @0x28eae0 andeq sp, r11, r12, lsr #28 */
/* @0x28eae4 andeq r9, r12, r0, lsr #19 */
/* @0x28eae8 andeq sp, r11, r4, lsl #23 */
/* @0x28eaec strheq r2, [r10], -r4 */
/* @0x28eaf0 strdeq r9, r10, [r12], -r4 */
/* @0x28eaf4 andeq r2, r10, r0, asr #3 */
/* @0x28eaf8 strheq r2, [r10], -r12 */
/* @0x28eafc andeq r9, r12, r0, lsl #8 */
/* @0x28eb00 andeq r9, r12, r4, ror r7 */
/* @0x28eb04 strheq r8, [r12], -r12 */
/* @0x28eb08 muleq r12, r0, r5 */
/* @0x28eb0c muleq r12, r12, r5 */
/* @0x28eb10 muleq r11, r8, r8 */
/* @0x28eb14 andeq r9, r12, r0, lsl #7 */
/* @0x28eb18 andeq r9, r12, r4, lsl #7 */
/* @0x28eb1c andeq r9, r12, r0, asr #8 */
/* @0x28eb20 andeq r9, r12, r0, lsr #9 */
/* @0x28eb24 andeq r9, r12, r8, lsr r3 */
/* @0x28eb28 ldr r1, [pc, #-0xc] */
/* @0x28eb2c ldr r0, [sp, #0x1c] */
/* @0x28eb30 add r1, pc, r1 */
/* @0x28eb34 bl 0x2873c4 <Json_getItem> */
/* @0x28eb38 str r0, [sp, #0x28] */
/* @0x28eb3c b 0x28d3b4 <spSkeletonJson_readSkeletonData+0x1b68> */

/* ── FUNC 0x28eb40 · spSkeletonJson_readSkeletonDataFile · size=120 · insn=30 */
/* @0x28eb40 push {r4, r5, r6, lr} */
/* @0x28eb44 mov r5, r1 */
/* @0x28eb48 sub sp, sp, #8 */
/* @0x28eb4c mov r6, r0 */
/* @0x28eb50 add r1, sp, #4 */
/* @0x28eb54 mov r0, r5 */
/* @0x28eb58 bl 0xbd83c <_spUtil_readFile> */
/* @0x28eb5c ldr r3, [sp, #0x4] */
/* @0x28eb60 cmp r3, #0 */
/* @0x28eb64 mov r4, r0 */
/* @0x28eb68 mov r0, r6 */
/* @0x28eb6c beq 0x28eb98 <spSkeletonJson_readSkeletonDataFile+0x58> */
/* @0x28eb70 cmp r4, #0 */
/* @0x28eb74 beq 0x28eb98 <spSkeletonJson_readSkeletonDataFile+0x58> */
/* @0x28eb78 mov r1, r4 */
/* @0x28eb7c bl 0x28b84c <spSkeletonJson_readSkeletonData> */
/* @0x28eb80 mov r5, r0 */
/* @0x28eb84 mov r0, r4 */
/* @0x28eb88 bl 0x285c80 <_free> */
/* @0x28eb8c mov r0, r5 */
/* @0x28eb90 add sp, sp, #8 */
/* @0x28eb94 pop {r4, r5, r6, pc} */
/* @0x28eb98 ldr r2, [pc, #0x14] */
/* @0x28eb9c mov r3, r5 */
/* @0x28eba0 mov r1, #0 */
/* @0x28eba4 add r2, pc, r2 */
/* @0x28eba8 bl 0x28b784 <_spSkeletonJson_setError> */
/* @0x28ebac mov r0, #0 */
/* @0x28ebb0 b 0x28eb90 <spSkeletonJson_readSkeletonDataFile+0x50> */
/* @0x28ebb4 andeq r9, r12, r4, asr #7 */

/* ── FUNC 0x28ebb8 · _Entry_create · size=104 · insn=26 */
/* @0x28ebb8 push {r4, r5, r6, r7, r8, lr} */
/* @0x28ebbc mov r3, #36 */
/* @0x28ebc0 ldr r6, [pc, #0x54] */
/* @0x28ebc4 mov r5, r1 */
/* @0x28ebc8 mov r8, r0 */
/* @0x28ebcc mov r7, r2 */
/* @0x28ebd0 add r6, pc, r6 */
/* @0x28ebd4 mov r1, #16 */
/* @0x28ebd8 mov r0, #1 */
/* @0x28ebdc mov r2, r6 */
/* @0x28ebe0 bl 0x285c4c <_calloc> */
/* @0x28ebe4 mov r4, r0 */
/* @0x28ebe8 str r8, [r0] */
/* @0x28ebec mov r0, r5 */
/* @0x28ebf0 bl 0xb6538 <strlen@plt> */
/* @0x28ebf4 mov r1, r6 */
/* @0x28ebf8 mov r2, #38 */
/* @0x28ebfc add r0, r0, #1 */
/* @0x28ec00 bl 0x285c10 <_malloc> */
/* @0x28ec04 mov r1, r5 */
/* @0x28ec08 str r0, [r4, #0x4] */
/* @0x28ec0c bl 0xb65a4 <strcpy@plt> */
/* @0x28ec10 str r7, [r4, #0x8] */
/* @0x28ec14 mov r0, r4 */
/* @0x28ec18 pop {r4, r5, r6, r7, r8, pc} */
/* @0x28ec1c strheq r9, [r12], -r8 */

/* ── FUNC 0x28ec20 · _Entry_dispose · size=36 · insn=9 */
/* @0x28ec20 push {r4, lr} */
/* @0x28ec24 mov r4, r0 */
/* @0x28ec28 ldr r0, [r0, #0x8] */
/* @0x28ec2c bl 0x284cb4 <spAttachment_dispose> */
/* @0x28ec30 ldr r0, [r4, #0x4] */
/* @0x28ec34 bl 0x285c80 <_free> */
/* @0x28ec38 mov r0, r4 */
/* @0x28ec3c pop {r4, lr} */
/* @0x28ec40 b 0x285c80 <_free> */

/* ── FUNC 0x28ec44 · spSkin_create · size=88 · insn=22 */
/* @0x28ec44 push {r4, r5, r6, lr} */
/* @0x28ec48 mov r3, #52 */
/* @0x28ec4c ldr r6, [pc, #0x44] */
/* @0x28ec50 mov r5, r0 */
/* @0x28ec54 mov r1, #8 */
/* @0x28ec58 mov r0, #1 */
/* @0x28ec5c add r6, pc, r6 */
/* @0x28ec60 mov r2, r6 */
/* @0x28ec64 bl 0x285c4c <_calloc> */
/* @0x28ec68 mov r4, r0 */
/* @0x28ec6c mov r0, r5 */
/* @0x28ec70 bl 0xb6538 <strlen@plt> */
/* @0x28ec74 mov r1, r6 */
/* @0x28ec78 mov r2, #53 */
/* @0x28ec7c add r0, r0, #1 */
/* @0x28ec80 bl 0x285c10 <_malloc> */
/* @0x28ec84 mov r1, r5 */
/* @0x28ec88 str r0, [r4] */
/* @0x28ec8c bl 0xb65a4 <strcpy@plt> */
/* @0x28ec90 mov r0, r4 */
/* @0x28ec94 pop {r4, r5, r6, pc} */
/* @0x28ec98 andeq r9, r12, r12, lsr #6 */

/* ── FUNC 0x28ec9c · spSkin_dispose · size=60 · insn=15 */
/* @0x28ec9c push {r3, r4, r5, lr} */
/* @0x28eca0 mov r5, r0 */
/* @0x28eca4 ldr r0, [r0, #0x4] */
/* @0x28eca8 cmp r0, #0 */
/* @0x28ecac beq 0x28ecc4 <spSkin_dispose+0x28> */
/* @0x28ecb0 ldr r4, [r0, #0xc] */
/* @0x28ecb4 bl 0x28ec20 <_Entry_dispose> */
/* @0x28ecb8 cmp r4, #0 */
/* @0x28ecbc mov r0, r4 */
/* @0x28ecc0 bne 0x28ecb0 <spSkin_dispose+0x14> */
/* @0x28ecc4 ldr r0, [r5] */
/* @0x28ecc8 bl 0x285c80 <_free> */
/* @0x28eccc mov r0, r5 */
/* @0x28ecd0 pop {r3, r4, r5, lr} */
/* @0x28ecd4 b 0x285c80 <_free> */

/* ── FUNC 0x28ecd8 · spSkin_addAttachment · size=40 · insn=10 */
/* @0x28ecd8 push {r4, lr} */
/* @0x28ecdc mov r4, r0 */
/* @0x28ece0 mov r0, r1 */
/* @0x28ece4 mov r1, r2 */
/* @0x28ece8 mov r2, r3 */
/* @0x28ecec bl 0x28ebb8 <_Entry_create> */
/* @0x28ecf0 ldr r3, [r4, #0x4] */
/* @0x28ecf4 str r3, [r0, #0xc] */
/* @0x28ecf8 str r0, [r4, #0x4] */
/* @0x28ecfc pop {r4, pc} */

/* ── FUNC 0x28ed00 · spSkin_getAttachment · size=88 · insn=22 */
/* @0x28ed00 push {r4, r5, r6, lr} */
/* @0x28ed04 mov r5, r1 */
/* @0x28ed08 ldr r4, [r0, #0x4] */
/* @0x28ed0c mov r6, r2 */
/* @0x28ed10 cmp r4, #0 */
/* @0x28ed14 bne 0x28ed28 <spSkin_getAttachment+0x28> */
/* @0x28ed18 b 0x28ed50 <spSkin_getAttachment+0x50> */
/* @0x28ed1c ldr r4, [r4, #0xc] */
/* @0x28ed20 cmp r4, #0 */
/* @0x28ed24 beq 0x28ed50 <spSkin_getAttachment+0x50> */
/* @0x28ed28 ldr r3, [r4] */
/* @0x28ed2c cmp r3, r5 */
/* @0x28ed30 bne 0x28ed1c <spSkin_getAttachment+0x1c> */
/* @0x28ed34 ldr r0, [r4, #0x4] */
/* @0x28ed38 mov r1, r6 */
/* @0x28ed3c bl 0xb6574 <strcmp@plt> */
/* @0x28ed40 cmp r0, #0 */
/* @0x28ed44 bne 0x28ed1c <spSkin_getAttachment+0x1c> */
/* @0x28ed48 ldr r0, [r4, #0x8] */
/* @0x28ed4c pop {r4, r5, r6, pc} */
/* @0x28ed50 mov r0, r4 */
/* @0x28ed54 pop {r4, r5, r6, pc} */

/* ── FUNC 0x28ed58 · spSkin_getAttachmentName · size=68 · insn=17 */
/* @0x28ed58 ldr r0, [r0, #0x4] */
/* @0x28ed5c cmp r0, #0 */
/* @0x28ed60 bxeq lr */
/* @0x28ed64 mov r12, #0 */
/* @0x28ed68 b 0x28ed78 <spSkin_getAttachmentName+0x20> */
/* @0x28ed6c ldr r0, [r0, #0xc] */
/* @0x28ed70 cmp r0, #0 */
/* @0x28ed74 beq 0x28ed98 <spSkin_getAttachmentName+0x40> */
/* @0x28ed78 ldr r3, [r0] */
/* @0x28ed7c cmp r3, r1 */
/* @0x28ed80 bne 0x28ed6c <spSkin_getAttachmentName+0x14> */
/* @0x28ed84 cmp r12, r2 */
/* @0x28ed88 add r12, r12, #1 */
/* @0x28ed8c bne 0x28ed6c <spSkin_getAttachmentName+0x14> */
/* @0x28ed90 ldr r0, [r0, #0x4] */
/* @0x28ed94 bx lr */
/* @0x28ed98 bx lr */

/* ── FUNC 0x28ed9c · spSkin_attachAll · size=100 · insn=25 */
/* @0x28ed9c push {r3, r4, r5, r6, r7, lr} */
/* @0x28eda0 mov r7, r0 */
/* @0x28eda4 ldr r4, [r2, #0x4] */
/* @0x28eda8 mov r6, r1 */
/* @0x28edac cmp r4, #0 */
/* @0x28edb0 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x28edb4 ldr r12, [r6, #0x14] */
/* @0x28edb8 ldr r1, [r4] */
/* @0x28edbc ldr r2, [r4, #0x8] */
/* @0x28edc0 ldr r5, [r12, r1, lsl #2] */
/* @0x28edc4 ldr r12, [r5, #0x18] */
/* @0x28edc8 cmp r12, r2 */
/* @0x28edcc beq 0x28ede0 <spSkin_attachAll+0x44> */
/* @0x28edd0 ldr r4, [r4, #0xc] */
/* @0x28edd4 cmp r4, #0 */
/* @0x28edd8 bne 0x28edb4 <spSkin_attachAll+0x18> */
/* @0x28eddc pop {r3, r4, r5, r6, r7, pc} */
/* @0x28ede0 mov r0, r7 */
/* @0x28ede4 ldr r2, [r4, #0x4] */
/* @0x28ede8 bl 0x28ed00 <spSkin_getAttachment> */
/* @0x28edec subs r1, r0, #0 */
/* @0x28edf0 mov r0, r5 */
/* @0x28edf4 beq 0x28edd0 <spSkin_attachAll+0x34> */
/* @0x28edf8 bl 0x28ee1c <spSlot_setAttachment> */
/* @0x28edfc b 0x28edd0 <spSkin_attachAll+0x34> */

/* ── FUNC 0x28ee00 · spSlot_dispose · size=28 · insn=7 */
/* @0x28ee00 push {r4, lr} */
/* @0x28ee04 mov r4, r0 */
/* @0x28ee08 ldr r0, [r0, #0x24] */
/* @0x28ee0c bl 0x285c80 <_free> */
/* @0x28ee10 mov r0, r4 */
/* @0x28ee14 pop {r4, lr} */
/* @0x28ee18 b 0x285c80 <_free> */

/* ── FUNC 0x28ee1c · spSlot_setAttachment · size=44 · insn=11 */
/* @0x28ee1c ldr r3, [r0, #0x18] */
/* @0x28ee20 cmp r3, r1 */
/* @0x28ee24 bxeq lr */
/* @0x28ee28 ldr r2, [r0, #0x4] */
/* @0x28ee2c mov r3, #0 */
/* @0x28ee30 str r1, [r0, #0x18] */
/* @0x28ee34 ldr r2, [r2, #0x4] */
/* @0x28ee38 ldr r2, [r2, #0x4c] */
/* @0x28ee3c str r3, [r0, #0x20] */
/* @0x28ee40 str r2, [r0, #0x28] */
/* @0x28ee44 bx lr */

/* ── FUNC 0x28ee48 · spSlot_setAttachmentTime · size=28 · insn=7 */
/* @0x28ee48 ldr r3, [r0, #0x4] */
/* @0x28ee4c vmov s14, r1 */
/* @0x28ee50 ldr r3, [r3, #0x4] */
/* @0x28ee54 vldr s15, [r3, #76] */
/* @0x28ee58 vsub.f32 s15, s15, s14 */
/* @0x28ee5c vstr s15, [r0, #40] */
/* @0x28ee60 bx lr */

/* ── FUNC 0x28ee64 · spSlot_getAttachmentTime · size=28 · insn=7 */
/* @0x28ee64 ldr r3, [r0, #0x4] */
/* @0x28ee68 vldr s15, [r0, #40] */
/* @0x28ee6c ldr r3, [r3, #0x4] */
/* @0x28ee70 vldr s14, [r3, #76] */
/* @0x28ee74 vsub.f32 s15, s14, s15 */
/* @0x28ee78 vmov r0, s15 */
/* @0x28ee7c bx lr */

/* ── FUNC 0x28ee80 · spSlot_setToSetupPose · size=108 · insn=27 */
/* @0x28ee80 ldr r3, [r0] */
/* @0x28ee84 push {r4, lr} */
/* @0x28ee88 mov r4, r0 */
/* @0x28ee8c ldr r1, [r3, #0x10] */
/* @0x28ee90 ldr r2, [r3, #0x14] */
/* @0x28ee94 str r1, [r0, #0x8] */
/* @0x28ee98 ldr r1, [r3, #0x18] */
/* @0x28ee9c str r2, [r0, #0xc] */
/* @0x28eea0 ldr r2, [r3, #0xc] */
/* @0x28eea4 str r1, [r0, #0x10] */
/* @0x28eea8 ldr r1, [r3, #0x1c] */
/* @0x28eeac cmp r2, #0 */
/* @0x28eeb0 str r1, [r0, #0x14] */
/* @0x28eeb4 beq 0x28eee0 <spSlot_setToSetupPose+0x60> */
/* @0x28eeb8 ldr r0, [r0, #0x4] */
/* @0x28eebc ldr r1, [r3] */
/* @0x28eec0 ldr r0, [r0, #0x4] */
/* @0x28eec4 bl 0x28a314 <spSkeleton_getAttachmentForSlotIndex> */
/* @0x28eec8 mov r3, #0 */
/* @0x28eecc str r3, [r4, #0x18] */
/* @0x28eed0 mov r1, r0 */
/* @0x28eed4 mov r0, r4 */
/* @0x28eed8 pop {r4, lr} */
/* @0x28eedc b 0x28ee1c <spSlot_setAttachment> */
/* @0x28eee0 mov r1, r2 */
/* @0x28eee4 pop {r4, lr} */
/* @0x28eee8 b 0x28ee1c <spSlot_setAttachment> */
