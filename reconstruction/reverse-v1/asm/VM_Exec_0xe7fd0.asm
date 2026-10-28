
/data/data/com.termux/files/usr/tmp/yoyo_1793147743/lib/armeabi-v7a/libyoyo.so:	file format elf32-littlearm

Disassembly of section .text:

000e7fd0 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_>:
   e7fd0:      	ldr	r12, [pc, #0x580]       @ 0xe8558 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x588>
   e7fd4:      	push	{r4, r5, r6, r7, r8, r9, r10, r11, lr}
   e7fd8:      	add	r12, pc, r12
   e7fdc:      	mov	r9, r3
   e7fe0:      	ldr	r4, [pc, #0x574]        @ 0xe855c <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x58c>
   e7fe4:      	ldrb	r3, [r12, #0x14]
   e7fe8:      	sub	sp, sp, #124
   e7fec:      	add	r4, pc, r4
   e7ff0:      	mov	r6, r0
   e7ff4:      	cmp	r3, #0
   e7ff8:      	mov	r11, r1
   e7ffc:      	mov	r10, r2
   e8000:      	beq	0xe8210 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x240> @ imm = #0x208
   e8004:      	ldr	r3, [pc, #0x554]        @ 0xe8560 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x590>
   e8008:      	ldr	r5, [r4, r3]
   e800c:      	ldr	r3, [pc, #0x550]        @ 0xe8564 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x594>
   e8010:      	ldr	r2, [pc, #0x550]        @ 0xe8568 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x598>
   e8014:      	ldr	r0, [r6, #0x58]
   e8018:      	ldr	r3, [r4, r3]
   e801c:      	ldr	r2, [r4, r2]
   e8020:      	ldr	r8, [r6, #0x5c]
   e8024:      	ldrb	r3, [r3]
   e8028:      	ldr	r2, [r2]
   e802c:      	cmp	r3, #0
   e8030:      	ldr	r7, [r6, #0x50]
   e8034:      	ldr	r3, [r6, #0x54]
   e8038:      	str	r2, [sp, #0x10]
   e803c:      	str	r0, [sp, #0xc]
   e8040:      	bne	0xe82a8 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x2d8> @ imm = #0x260
   e8044:      	ldr	lr, [r5, #0x8]
   e8048:      	mov	r2, #16384
   e804c:      	str	r11, [sp, #0x2c]
   e8050:      	cmp	lr, #0
   e8054:      	str	r10, [sp, #0x30]
   e8058:      	str	r2, [sp, #0x58]
   e805c:      	beq	0xe832c <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x35c> @ imm = #0x2c8
   e8060:      	ldr	r10, [r5, #0x10]
   e8064:      	movw	r12, #0x3ff0
   e8068:      	ldr	r0, [lr]
   e806c:      	ldr	r1, [sp, #0xa4]
   e8070:      	add	r12, lr, r12
   e8074:      	str	r0, [r5, #0x8]
   e8078:      	sub	r10, r10, #1
   e807c:      	ldr	r0, [r7, #0x4]
   e8080:      	lsl	r2, r1, #4
   e8084:      	ldr	r11, [r7, #0x10]
   e8088:      	rsb	r12, r2, r12
   e808c:      	str	r3, [sp, #0x50]
   e8090:      	ldr	r3, [sp, #0xc]
   e8094:      	str	lr, [sp, #0x20]
   e8098:      	ldr	lr, [r5, #0xc]
   e809c:      	ldr	r1, [sp, #0xa8]
   e80a0:      	str	r0, [sp, #0x68]
   e80a4:      	mov	r0, r12
   e80a8:      	str	r10, [r5, #0x10]
   e80ac:      	add	lr, lr, #1
   e80b0:      	str	r11, [sp, #0x3c]
   e80b4:      	add	r11, sp, #24
   e80b8:      	str	lr, [r5, #0xc]
   e80bc:      	str	r7, [sp, #0x44]
   e80c0:      	str	r3, [sp, #0x54]
   e80c4:      	str	r8, [sp, #0x4c]
   e80c8:      	bl	0xb65bc <memcpy@plt>    @ imm = #-0x31b14
   e80cc:      	ldr	r5, [pc, #0x498]        @ 0xe856c <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x59c>
   e80d0:      	mov	r1, #0
   e80d4:      	ldr	lr, [pc, #0x494]        @ 0xe8570 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x5a0>
   e80d8:      	mov	r2, #60
   e80dc:      	ldr	r10, [sp, #0xa4]
   e80e0:      	ldr	r7, [r4, r5]
   e80e4:      	ldr	r5, [r4, lr]
   e80e8:      	str	r10, [sp, #0x38]
   e80ec:      	ldr	r10, [r7]
   e80f0:      	ldr	r8, [r5]
   e80f4:      	sub	r3, r0, #60
   e80f8:      	mov	r12, r0
   e80fc:      	str	r3, [sp, #0x40]
   e8100:      	mov	r0, r3
   e8104:      	ldr	r3, [sp, #0xa4]
   e8108:      	str	r12, [sp, #0x34]
   e810c:      	str	r12, [r5]
   e8110:      	str	r3, [r7]
   e8114:      	bl	0xb65b0 <memset@plt>    @ imm = #-0x31b6c
   e8118:      	ldr	r1, [r6, #0x6c]
   e811c:      	mov	r2, #0
   e8120:      	ldr	r0, [sp, #0x40]
   e8124:      	mvn	r12, #0
   e8128:      	ldr	r3, [pc, #0x444]        @ 0xe8574 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x5a4>
   e812c:      	str	r12, [r0, #0xc]
   e8130:      	str	r1, [sp, #0x5c]
   e8134:      	mov	r1, #0
   e8138:      	str	r2, [sp, #0x64]
   e813c:      	ldr	r6, [r4, r3]
   e8140:      	ldr	r3, [r6]
   e8144:      	cmp	r3, r2
   e8148:      	ldr	r2, [sp, #0x44]
   e814c:      	strne	r11, [r3]
   e8150:      	str	r3, [sp, #0x1c]
   e8154:      	mov	r0, r2
   e8158:      	str	r11, [r6]
   e815c:      	str	r1, [sp, #0x18]
   e8160:      	str	r2, [sp]
   e8164:      	bl	0xec750 <_ZN8VMBuffer13convertBufferEv> @ imm = #0x45e4
   e8168:      	ldr	r3, [sp, #0x44]
   e816c:      	ldr	r2, [sp]
   e8170:      	ldr	lr, [sp, #0xa0]
   e8174:      	ldr	r3, [r3, #0x18]
   e8178:      	ldr	r2, [r2, #0x14]
   e817c:      	cmp	lr, #0
   e8180:      	str	r3, [sp, #0x74]
   e8184:      	str	r2, [sp, #0x70]
   e8188:      	beq	0xe83cc <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x3fc> @ imm = #0x23c
   e818c:      	mov	r3, #1
   e8190:      	str	lr, [sp, #0x28]
   e8194:      	str	r3, [sp, #0x24]
   e8198:      	ldr	r3, [pc, #0x3d8]        @ 0xe8578 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x5a8>
   e819c:      	ldr	r3, [r4, r3]
   e81a0:      	ldrb	r3, [r3]
   e81a4:      	cmp	r3, #0
   e81a8:      	bne	0xe8230 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x260> @ imm = #0x80
   e81ac:      	ldr	r3, [pc, #0x3c8]        @ 0xe857c <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x5ac>
   e81b0:      	mov	r0, r11
   e81b4:      	mov	r1, r9
   e81b8:      	ldr	r3, [r4, r3]
   e81bc:      	ldr	r3, [r3]
   e81c0:      	cmp	r3, #0
   e81c4:      	beq	0xe8324 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x354> @ imm = #0x158
   e81c8:      	mov	r2, #0
   e81cc:      	bl	0xe47c8 <_ZN2VM9ExecDebugER6VMExecP6RValueb> @ imm = #-0x3a0c
   e81d0:      	ldr	r3, [sp, #0x1c]
   e81d4:      	cmp	r3, #0
   e81d8:      	movne	r2, #0
   e81dc:      	strne	r2, [r3]
   e81e0:      	ldr	r2, [sp, #0x24]
   e81e4:      	str	r3, [r6]
   e81e8:      	cmp	r2, #0
   e81ec:      	str	r10, [r7]
   e81f0:      	str	r8, [r5]
   e81f4:      	bne	0xe8208 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x238> @ imm = #0xc
   e81f8:      	ldr	r0, [sp, #0x28]
   e81fc:      	cmp	r0, #0
   e8200:      	beq	0xe8208 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x238> @ imm = #0x0
   e8204:      	bl	0x198f88 <_ZN12YYObjectBase4FreeEPS_> @ imm = #0xb0d7c
   e8208:      	add	sp, sp, #124
   e820c:      	pop	{r4, r5, r6, r7, r8, r9, r10, r11, pc}
   e8210:      	ldr	r1, [pc, #0x348]        @ 0xe8560 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x590>
   e8214:      	mov	r2, #1
   e8218:      	ldr	r5, [r4, r1]
   e821c:      	strb	r2, [r12, #0x14]
   e8220:      	str	r3, [r5, #0x4]
   e8224:      	str	r3, [r5, #0x8]
   e8228:      	str	r3, [r5, #0xc]
   e822c:      	b	0xe800c <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x3c> @ imm = #-0x228
   e8230:      	ldr	r0, [sp, #0x28]
   e8234:      	bl	0xd3968 <_Z16PushContextStackP12YYObjectBase> @ imm = #-0x148d4
   e8238:      	ldr	r0, [sp, #0x28]
   e823c:      	ldr	r1, [r0, #0x4]
   e8240:      	cmp	r1, #0
   e8244:      	beq	0xe8454 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x484> @ imm = #0x208
   e8248:      	ldr	r2, [r1, #0xc]
   e824c:      	bic	r3, r2, #-16777216
   e8250:      	cmp	r3, #1
   e8254:      	beq	0xe82d8 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x308> @ imm = #0x7c
   e8258:      	cmp	r3, #2
   e825c:      	bne	0xe8274 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x2a4> @ imm = #0x10
   e8260:      	sub	r3, r2, #1
   e8264:      	bic	r3, r3, #-16777216
   e8268:      	bic	r3, r3, #3
   e826c:      	cmp	r3, #0
   e8270:      	beq	0xe8440 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x470> @ imm = #0x1c8
   e8274:      	ldr	lr, [sp, #0xb0]
   e8278:      	mov	r2, #6
   e827c:      	mov	r3, #5
   e8280:      	str	r2, [r1, #0xc]
   e8284:      	cmp	lr, #0
   e8288:      	str	r3, [r1, #0x8]
   e828c:      	str	lr, [r1]
   e8290:      	beq	0xe82a0 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x2d0> @ imm = #0x8
   e8294:      	bl	0xd3a54 <_Z18GetContextStackTopv> @ imm = #-0x14848
   e8298:      	ldr	r1, [sp, #0xb0]
   e829c:      	bl	0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> @ imm = #0xa946c
   e82a0:      	bl	0xd3a34 <_Z15PopContextStackv> @ imm = #-0x14874
   e82a4:      	b	0xe81ac <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x1dc> @ imm = #-0x100
   e82a8:      	ldr	r0, [pc, #0x2d0]        @ 0xe8580 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x5b0>
   e82ac:      	mov	r2, r8
   e82b0:      	ldr	r1, [pc, #0x2cc]        @ 0xe8584 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x5b4>
   e82b4:      	ldr	r0, [r4, r0]
   e82b8:      	add	r1, pc, r1
   e82bc:      	ldr	r0, [r0]
   e82c0:      	ldr	r12, [r0]
   e82c4:      	ldr	r12, [r12, #0xc]
   e82c8:      	str	r3, [sp, #0x4]
   e82cc:      	blx	r12
   e82d0:      	ldr	r3, [sp, #0x4]
   e82d4:      	b	0xe8044 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x74> @ imm = #-0x298
   e82d8:      	ldr	r3, [r1]
   e82dc:      	cmp	r3, #0
   e82e0:      	beq	0xe8318 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x348> @ imm = #0x30
   e82e4:      	str	r1, [sp, #0x8]
   e82e8:      	str	r3, [sp, #0x4]
   e82ec:      	bl	0x190f2c <_Z17LOCK_RVALUE_MUTEXv> @ imm = #0xa8c38
   e82f0:      	ldr	r3, [sp, #0x4]
   e82f4:      	ldr	r1, [sp, #0x8]
   e82f8:      	ldr	r2, [r3, #0x4]
   e82fc:      	sub	r2, r2, #1
   e8300:      	str	r2, [r3, #0x4]
   e8304:      	cmp	r2, #0
   e8308:      	beq	0xe83e4 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x414> @ imm = #0xd4
   e830c:      	str	r1, [sp, #0x8]
   e8310:      	bl	0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> @ imm = #0xa8c18
   e8314:      	ldr	r1, [sp, #0x8]
   e8318:      	mov	r3, #0
   e831c:      	str	r3, [r1]
   e8320:      	b	0xe8274 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x2a4> @ imm = #-0xb4
   e8324:      	bl	0xe4540 <_ZN2VM11ExecReleaseER6VMExecP6RValue> @ imm = #-0x3dec
   e8328:      	b	0xe81d0 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x200> @ imm = #-0x160
   e832c:      	movw	r0, #0x8008
   e8330:      	movt	r0, #0x10
   e8334:      	str	r3, [sp, #0x4]
   e8338:      	bl	0x27c524 <_Znwj>        @ imm = #0x1941e4
   e833c:      	mov	r1, #120
   e8340:      	mov	r2, #1081344
   e8344:      	mov	r10, r0
   e8348:      	add	r0, r0, #8
   e834c:      	bl	0xb65b0 <memset@plt>    @ imm = #-0x31da4
   e8350:      	ldr	r1, [r5, #0x8]
   e8354:      	ldr	r0, [r5, #0x4]
   e8358:      	add	lr, r10, #32768
   e835c:      	add	lr, lr, #8
   e8360:      	ldr	r11, [r5, #0x10]
   e8364:      	str	r1, [sp, #0x14]
   e8368:      	bic	lr, lr, #32512
   e836c:      	str	r0, [r10]
   e8370:      	bic	lr, lr, #255
   e8374:      	str	r10, [r5, #0x4]
   e8378:      	add	r12, r11, #1
   e837c:      	ldr	r10, [sp, #0x14]
   e8380:      	add	r2, lr, #32768
   e8384:      	add	r1, lr, #1015808
   e8388:      	mov	r0, lr
   e838c:      	ldr	r3, [sp, #0x4]
   e8390:      	str	r10, [lr]
   e8394:      	str	lr, [r5, #0x8]
   e8398:      	str	r12, [r5, #0x10]
   e839c:      	b	0xe83a4 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x3d4> @ imm = #0x0
   e83a0:      	mov	r0, r12
   e83a4:      	str	r0, [r2]
   e83a8:      	mov	r12, r2
   e83ac:      	add	r2, r2, #32768
   e83b0:      	cmp	r2, r1
   e83b4:      	bne	0xe83a0 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x3d0> @ imm = #-0x1c
   e83b8:      	ldr	r2, [sp, #0x58]
   e83bc:      	add	r10, r11, #31
   e83c0:      	add	lr, lr, #983040
   e83c4:      	sub	r12, r2, #16
   e83c8:      	b	0xe806c <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x9c> @ imm = #-0x364
   e83cc:      	ldr	r0, [sp, #0x10]
   e83d0:      	bl	0xd41e4 <_Z20YYAllocLocalStackNewi> @ imm = #-0x141f4
   e83d4:      	ldr	r3, [sp, #0xa0]
   e83d8:      	str	r3, [sp, #0x24]
   e83dc:      	str	r0, [sp, #0x28]
   e83e0:      	b	0xe8198 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x1c8> @ imm = #-0x250
   e83e4:      	ldr	r0, [r3]
   e83e8:      	stm	sp, {r2, r3}
   e83ec:      	bl	0xcef90 <_Z6YYFreePKv>  @ imm = #-0x19464
   e83f0:      	ldm	sp, {r2, r3}
   e83f4:      	str	r2, [r3]
   e83f8:      	str	r2, [r3, #0x8]
   e83fc:      	str	r3, [sp, #0x4]
   e8400:      	bl	0x190f2c <_Z17LOCK_RVALUE_MUTEXv> @ imm = #0xa8b24
   e8404:      	ldr	r3, [sp, #0x4]
   e8408:      	ldr	r1, [sp, #0x8]
   e840c:      	ldr	r2, [r3, #0x4]
   e8410:      	sub	r2, r2, #1
   e8414:      	str	r2, [r3, #0x4]
   e8418:      	cmp	r2, #0
   e841c:      	beq	0xe8460 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x490> @ imm = #0x3c
   e8420:      	str	r1, [sp, #0x8]
   e8424:      	str	r3, [sp, #0x4]
   e8428:      	bl	0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> @ imm = #0xa8b00
   e842c:      	ldr	r3, [sp, #0x4]
   e8430:      	mov	r0, r3
   e8434:      	bl	0x27d1d0 <_ZdlPv>       @ imm = #0x194d94
   e8438:      	ldr	r1, [sp, #0x8]
   e843c:      	b	0xe830c <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x33c> @ imm = #-0x138
   e8440:      	mov	r0, r1
   e8444:      	str	r1, [sp, #0x8]
   e8448:      	bl	0xc0a7c <_Z16FREE_RValue__PreP6RValue> @ imm = #-0x279d4
   e844c:      	ldr	r1, [sp, #0x8]
   e8450:      	b	0xe8274 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x2a4> @ imm = #-0x1e4
   e8454:      	bl	0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> @ imm = #0xae614
   e8458:      	mov	r1, r0
   e845c:      	b	0xe8248 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x278> @ imm = #-0x21c
   e8460:      	ldr	r0, [r3]
   e8464:      	stm	sp, {r2, r3}
   e8468:      	bl	0xcef90 <_Z6YYFreePKv>  @ imm = #-0x194e0
   e846c:      	ldm	sp, {r2, r3}
   e8470:      	str	r2, [r3]
   e8474:      	str	r2, [r3, #0x8]
   e8478:      	str	r3, [sp, #0x4]
   e847c:      	bl	0x190f2c <_Z17LOCK_RVALUE_MUTEXv> @ imm = #0xa8aa8
   e8480:      	ldr	r3, [sp, #0x4]
   e8484:      	ldr	r1, [sp, #0x8]
   e8488:      	ldr	r2, [r3, #0x4]
   e848c:      	sub	r2, r2, #1
   e8490:      	str	r2, [r3, #0x4]
   e8494:      	cmp	r2, #0
   e8498:      	beq	0xe84c0 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x4f0> @ imm = #0x20
   e849c:      	str	r1, [sp, #0x8]
   e84a0:      	str	r3, [sp, #0x4]
   e84a4:      	bl	0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> @ imm = #0xa8a84
   e84a8:      	ldr	r3, [sp, #0x4]
   e84ac:      	mov	r0, r3
   e84b0:      	bl	0x27d1d0 <_ZdlPv>       @ imm = #0x194d18
   e84b4:      	ldr	r3, [sp, #0x4]
   e84b8:      	ldr	r1, [sp, #0x8]
   e84bc:      	b	0xe8420 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x450> @ imm = #-0xa4
   e84c0:      	ldr	r0, [r3]
   e84c4:      	stm	sp, {r2, r3}
   e84c8:      	bl	0xcef90 <_Z6YYFreePKv>  @ imm = #-0x19540
   e84cc:      	ldm	sp, {r2, r3}
   e84d0:      	str	r2, [r3]
   e84d4:      	str	r2, [r3, #0x8]
   e84d8:      	str	r3, [sp, #0x4]
   e84dc:      	bl	0x190f2c <_Z17LOCK_RVALUE_MUTEXv> @ imm = #0xa8a48
   e84e0:      	ldr	r3, [sp, #0x4]
   e84e4:      	ldr	r1, [sp, #0x8]
   e84e8:      	ldr	r2, [r3, #0x4]
   e84ec:      	sub	r2, r2, #1
   e84f0:      	str	r2, [r3, #0x4]
   e84f4:      	cmp	r2, #0
   e84f8:      	bne	0xe8534 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x564> @ imm = #0x34
   e84fc:      	ldr	r0, [r3]
   e8500:      	stm	sp, {r2, r3}
   e8504:      	bl	0xcef90 <_Z6YYFreePKv>  @ imm = #-0x1957c
   e8508:      	ldm	sp, {r2, r3}
   e850c:      	str	r2, [r3]
   e8510:      	mov	r0, r3
   e8514:      	str	r2, [r3, #0x8]
   e8518:      	str	r3, [sp, #0x4]
   e851c:      	bl	0xc09f8 <_ZN9_RefThingIPKcE3decEv> @ imm = #-0x27b2c
   e8520:      	ldr	r3, [sp, #0x4]
   e8524:      	mov	r0, r3
   e8528:      	bl	0x27d1d0 <_ZdlPv>       @ imm = #0x194ca0
   e852c:      	ldr	r3, [sp, #0x4]
   e8530:      	ldr	r1, [sp, #0x8]
   e8534:      	str	r1, [sp, #0x8]
   e8538:      	str	r3, [sp, #0x4]
   e853c:      	bl	0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> @ imm = #0xa89ec
   e8540:      	ldr	r3, [sp, #0x4]
   e8544:      	mov	r0, r3
   e8548:      	bl	0x27d1d0 <_ZdlPv>       @ imm = #0x194c80
   e854c:      	ldr	r3, [sp, #0x4]
   e8550:      	ldr	r1, [sp, #0x8]
   e8554:      	b	0xe849c <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x4cc> @ imm = #-0xc0
   e8558:      	ldrsbteq	r2, [r9], -r12
   e855c:      	eorseq	r9, r0, r4, ror #24
   e8560:      	<unknown>
   e8564:      	<unknown>
   e8568:      	<unknown>
   e856c:      	<unknown>
   e8570:      	<unknown>
   e8574:      	<unknown>
   e8578:      	<unknown>
   e857c:      	<unknown>
   e8580:      	<unknown>
   e8584:      	eoreq	r12, r4, r0, asr r5
