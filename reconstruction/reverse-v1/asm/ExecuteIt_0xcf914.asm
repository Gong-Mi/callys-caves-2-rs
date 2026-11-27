
/data/data/com.termux/files/usr/tmp/yoyo_1793147743/lib/armeabi-v7a/libyoyo.so:	file format elf32-littlearm

Disassembly of section .text:

000cf914 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei>:
   cf914: e92d43f0     	push	{r4, r5, r6, r7, r8, r9, lr}
   cf918: e1a04002     	mov	r4, r2
   cf91c: e59f632c     	ldr	r6, [pc, #0x32c]        @ 0xcfc50 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x33c>
   cf920: e1a05003     	mov	r5, r3
   cf924: e59f2328     	ldr	r2, [pc, #0x328]        @ 0xcfc54 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x340>
   cf928: e3a07000     	mov	r7, #0
   cf92c: e08f6006     	add	r6, pc, r6
   cf930: e594c008     	ldr	r12, [r4, #0x8]
   cf934: e24dd01c     	sub	sp, sp, #28
   cf938: e1a08000     	mov	r8, r0
   cf93c: e7963002     	ldr	r3, [r6, r2]
   cf940: e35c0001     	cmp	r12, #1
   cf944: e1a09001     	mov	r9, r1
   cf948: e5c37000     	strb	r7, [r3]
   cf94c: ba000034     	blt	0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> @ imm = #0xd0
   cf950: e35c0002     	cmp	r12, #2
   cf954: da000035     	ble	0xcfa30 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x11c> @ imm = #0xd4
   cf958: e35c0003     	cmp	r12, #3
   cf95c: 1a000030     	bne	0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> @ imm = #0xc0
   cf960: e595200c     	ldr	r2, [r5, #0xc]
   cf964: e3c234ff     	bic	r3, r2, #-16777216
   cf968: e3530001     	cmp	r3, #1
   cf96c: 0a00005e     	beq	0xcfaec <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x1d8> @ imm = #0x178
   cf970: e3530002     	cmp	r3, #2
   cf974: 1a000008     	bne	0xcf99c <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x88> @ imm = #0x20
   cf978: e2422001     	sub	r2, r2, #1
   cf97c: e3c224ff     	bic	r2, r2, #-16777216
   cf980: e3c22003     	bic	r2, r2, #3
   cf984: e3520000     	cmp	r2, #0
   cf988: 0a000083     	beq	0xcfb9c <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x288> @ imm = #0x20c
   cf98c: e3a02000     	mov	r2, #0
   cf990: e3a03005     	mov	r3, #5
   cf994: e5852008     	str	r2, [r5, #0x8]
   cf998: e585300c     	str	r3, [r5, #0xc]
   cf99c: e594304c     	ldr	r3, [r4, #0x4c]
   cf9a0: e3a01000     	mov	r1, #0
   cf9a4: e5942048     	ldr	r2, [r4, #0x48]
   cf9a8: e5851000     	str	r1, [r5]
   cf9ac: e585300c     	str	r3, [r5, #0xc]
   cf9b0: e594304c     	ldr	r3, [r4, #0x4c]
   cf9b4: e5852008     	str	r2, [r5, #0x8]
   cf9b8: e3c334ff     	bic	r3, r3, #-16777216
   cf9bc: e353000e     	cmp	r3, #14
   cf9c0: 908ff103     	addls	pc, pc, r3, lsl #2
   cf9c4: ea000016     	b	0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> @ imm = #0x58
   cf9c8: ea000043     	b	0xcfadc <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x1c8> @ imm = #0x10c
   cf9cc: ea000053     	b	0xcfb20 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x20c> @ imm = #0x14c
   cf9d0: ea000058     	b	0xcfb38 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x224> @ imm = #0x160
   cf9d4: ea00003b     	b	0xcfac8 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x1b4> @ imm = #0xec
   cf9d8: ea000011     	b	0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> @ imm = #0x44
   cf9dc: ea000010     	b	0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> @ imm = #0x40
   cf9e0: ea000007     	b	0xcfa04 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0xf0> @ imm = #0x1c
   cf9e4: ea000037     	b	0xcfac8 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x1b4> @ imm = #0xdc
   cf9e8: ea00000d     	b	0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> @ imm = #0x34
   cf9ec: ea00000c     	b	0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> @ imm = #0x30
   cf9f0: ea000039     	b	0xcfadc <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x1c8> @ imm = #0xe4
   cf9f4: ea00000a     	b	0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> @ imm = #0x28
   cf9f8: ea000009     	b	0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> @ imm = #0x24
   cf9fc: ea000036     	b	0xcfadc <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x1c8> @ imm = #0xd8
   cfa00: ea000030     	b	0xcfac8 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x1b4> @ imm = #0xc0
   cfa04: e5943040     	ldr	r3, [r4, #0x40]
   cfa08: e5853000     	str	r3, [r5]
   cfa0c: e5943040     	ldr	r3, [r4, #0x40]
   cfa10: e3530000     	cmp	r3, #0
   cfa14: 0a000002     	beq	0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> @ imm = #0x8
   cfa18: eb00100d     	bl	0xd3a54 <_Z18GetContextStackTopv> @ imm = #0x4034
   cfa1c: e5941040     	ldr	r1, [r4, #0x40]
   cfa20: eb03073a     	bl	0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> @ imm = #0xc1ce8
   cfa24: e3a00001     	mov	r0, #1
   cfa28: e28dd01c     	add	sp, sp, #28
   cfa2c: e8bd83f0     	pop	{r4, r5, r6, r7, r8, r9, pc}
   cfa30: e5943064     	ldr	r3, [r4, #0x64]
   cfa34: e3530000     	cmp	r3, #0
   cfa38: 0a000004     	beq	0xcfa50 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x13c> @ imm = #0x10
   cfa3c: e5933004     	ldr	r3, [r3, #0x4]
   cfa40: e12fff33     	blx	r3
   cfa44: e3a00001     	mov	r0, #1
   cfa48: e28dd01c     	add	sp, sp, #28
   cfa4c: e8bd83f0     	pop	{r4, r5, r6, r7, r8, r9, pc}
   cfa50: e5943050     	ldr	r3, [r4, #0x50]
   cfa54: e3530000     	cmp	r3, #0
   cfa58: 0afffff1     	beq	0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> @ imm = #-0x3c
   cfa5c: e5933004     	ldr	r3, [r3, #0x4]
   cfa60: e3530000     	cmp	r3, #0
   cfa64: daffffee     	ble	0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> @ imm = #-0x48
   cfa68: e59f31e8     	ldr	r3, [pc, #0x1e8]        @ 0xcfc58 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x344>
   cfa6c: e7967003     	ldr	r7, [r6, r3]
   cfa70: e5d73000     	ldrb	r3, [r7]
   cfa74: e3530000     	cmp	r3, #0
   cfa78: 1a00004a     	bne	0xcfba8 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x294> @ imm = #0x128
   cfa7c: e59d3038     	ldr	r3, [sp, #0x38]
   cfa80: e3a0c000     	mov	r12, #0
   cfa84: e1a00004     	mov	r0, r4
   cfa88: e1a01008     	mov	r1, r8
   cfa8c: e1a02009     	mov	r2, r9
   cfa90: e58dc000     	str	r12, [sp]
   cfa94: e58d300c     	str	r3, [sp, #0xc]
   cfa98: e1a03005     	mov	r3, r5
   cfa9c: e58dc004     	str	r12, [sp, #0x4]
   cfaa0: e58dc008     	str	r12, [sp, #0x8]
   cfaa4: e58dc010     	str	r12, [sp, #0x10]
   cfaa8: eb006148     	bl	0xe7fd0 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_> @ imm = #0x18520
   cfaac: e5d73000     	ldrb	r3, [r7]
   cfab0: e3530000     	cmp	r3, #0
   cfab4: 0affffda     	beq	0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> @ imm = #-0x98
   cfab8: e59f319c     	ldr	r3, [pc, #0x19c]        @ 0xcfc5c <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x348>
   cfabc: e7960003     	ldr	r0, [r6, r3]
   cfac0: eb074379     	bl	0x2a08ac <_ZN9CProfiler3PopEv> @ imm = #0x1d0de4
   cfac4: eaffffd6     	b	0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> @ imm = #-0xa8
   cfac8: e5943040     	ldr	r3, [r4, #0x40]
   cfacc: e3a00001     	mov	r0, #1
   cfad0: e5853000     	str	r3, [r5]
   cfad4: e28dd01c     	add	sp, sp, #28
   cfad8: e8bd83f0     	pop	{r4, r5, r6, r7, r8, r9, pc}
   cfadc: e5942040     	ldr	r2, [r4, #0x40]
   cfae0: e5943044     	ldr	r3, [r4, #0x44]
   cfae4: e885000c     	stm	r5, {r2, r3}
   cfae8: eaffffcd     	b	0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> @ imm = #-0xcc
   cfaec: e5956000     	ldr	r6, [r5]
   cfaf0: e3560000     	cmp	r6, #0
   cfaf4: 0a000006     	beq	0xcfb14 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x200> @ imm = #0x18
   cfaf8: eb03050b     	bl	0x190f2c <_Z17LOCK_RVALUE_MUTEXv> @ imm = #0xc142c
   cfafc: e5967004     	ldr	r7, [r6, #0x4]
   cfb00: e2477001     	sub	r7, r7, #1
   cfb04: e5867004     	str	r7, [r6, #0x4]
   cfb08: e3570000     	cmp	r7, #0
   cfb0c: 0a000014     	beq	0xcfb64 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x250> @ imm = #0x50
   cfb10: eb030506     	bl	0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> @ imm = #0xc1418
   cfb14: e3a03000     	mov	r3, #0
   cfb18: e5853000     	str	r3, [r5]
   cfb1c: eaffff9e     	b	0xcf99c <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x88> @ imm = #-0x188
   cfb20: e5943040     	ldr	r3, [r4, #0x40]
   cfb24: e3530000     	cmp	r3, #0
   cfb28: 15932004     	ldrne	r2, [r3, #0x4]
   cfb2c: 12822001     	addne	r2, r2, #1
   cfb30: 15832004     	strne	r2, [r3, #0x4]
   cfb34: eaffffe4     	b	0xcfacc <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x1b8> @ imm = #-0x70
   cfb38: e5943040     	ldr	r3, [r4, #0x40]
   cfb3c: e3530000     	cmp	r3, #0
   cfb40: e5853000     	str	r3, [r5]
   cfb44: 0affffb6     	beq	0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> @ imm = #-0x128
   cfb48: e5931008     	ldr	r1, [r3, #0x8]
   cfb4c: e5932000     	ldr	r2, [r3]
   cfb50: e3510000     	cmp	r1, #0
   cfb54: 05835008     	streq	r5, [r3, #0x8]
   cfb58: e2822001     	add	r2, r2, #1
   cfb5c: e5832000     	str	r2, [r3]
   cfb60: eaffffaf     	b	0xcfa24 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x110> @ imm = #-0x144
   cfb64: e5960000     	ldr	r0, [r6]
   cfb68: ebfffd08     	bl	0xcef90 <_Z6YYFreePKv>  @ imm = #-0xbe0
   cfb6c: e5867000     	str	r7, [r6]
   cfb70: e5867008     	str	r7, [r6, #0x8]
   cfb74: eb0304ec     	bl	0x190f2c <_Z17LOCK_RVALUE_MUTEXv> @ imm = #0xc13b0
   cfb78: e5967004     	ldr	r7, [r6, #0x4]
   cfb7c: e2477001     	sub	r7, r7, #1
   cfb80: e5867004     	str	r7, [r6, #0x4]
   cfb84: e3570000     	cmp	r7, #0
   cfb88: 0a00000c     	beq	0xcfbc0 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x2ac> @ imm = #0x30
   cfb8c: eb0304e7     	bl	0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> @ imm = #0xc139c
   cfb90: e1a00006     	mov	r0, r6
   cfb94: eb06b58d     	bl	0x27d1d0 <_ZdlPv>       @ imm = #0x1ad634
   cfb98: eaffffdc     	b	0xcfb10 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x1fc> @ imm = #-0x90
   cfb9c: e1a00005     	mov	r0, r5
   cfba0: ebffc3b5     	bl	0xc0a7c <_Z16FREE_RValue__PreP6RValue> @ imm = #-0xf12c
   cfba4: eaffff78     	b	0xcf98c <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x78> @ imm = #-0x220
   cfba8: e59f30ac     	ldr	r3, [pc, #0xac]         @ 0xcfc5c <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x348>
   cfbac: e3a01001     	mov	r1, #1
   cfbb0: e5942060     	ldr	r2, [r4, #0x60]
   cfbb4: e7960003     	ldr	r0, [r6, r3]
   cfbb8: eb0742de     	bl	0x2a0738 <_ZN9CProfiler4PushEii> @ imm = #0x1d0b78
   cfbbc: eaffffae     	b	0xcfa7c <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x168> @ imm = #-0x148
   cfbc0: e5960000     	ldr	r0, [r6]
   cfbc4: ebfffcf1     	bl	0xcef90 <_Z6YYFreePKv>  @ imm = #-0xc3c
   cfbc8: e5867000     	str	r7, [r6]
   cfbcc: e5867008     	str	r7, [r6, #0x8]
   cfbd0: eb0304d5     	bl	0x190f2c <_Z17LOCK_RVALUE_MUTEXv> @ imm = #0xc1354
   cfbd4: e5967004     	ldr	r7, [r6, #0x4]
   cfbd8: e2477001     	sub	r7, r7, #1
   cfbdc: e5867004     	str	r7, [r6, #0x4]
   cfbe0: e3570000     	cmp	r7, #0
   cfbe4: 0a000003     	beq	0xcfbf8 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x2e4> @ imm = #0xc
   cfbe8: eb0304d0     	bl	0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> @ imm = #0xc1340
   cfbec: e1a00006     	mov	r0, r6
   cfbf0: eb06b576     	bl	0x27d1d0 <_ZdlPv>       @ imm = #0x1ad5d8
   cfbf4: eaffffe4     	b	0xcfb8c <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x278> @ imm = #-0x70
   cfbf8: e5960000     	ldr	r0, [r6]
   cfbfc: ebfffce3     	bl	0xcef90 <_Z6YYFreePKv>  @ imm = #-0xc74
   cfc00: e5867000     	str	r7, [r6]
   cfc04: e5867008     	str	r7, [r6, #0x8]
   cfc08: eb0304c7     	bl	0x190f2c <_Z17LOCK_RVALUE_MUTEXv> @ imm = #0xc131c
   cfc0c: e5967004     	ldr	r7, [r6, #0x4]
   cfc10: e2477001     	sub	r7, r7, #1
   cfc14: e5867004     	str	r7, [r6, #0x4]
   cfc18: e3570000     	cmp	r7, #0
   cfc1c: 1a000007     	bne	0xcfc40 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x32c> @ imm = #0x1c
   cfc20: e5960000     	ldr	r0, [r6]
   cfc24: ebfffcd9     	bl	0xcef90 <_Z6YYFreePKv>  @ imm = #-0xc9c
   cfc28: e1a00006     	mov	r0, r6
   cfc2c: e5867000     	str	r7, [r6]
   cfc30: e5867008     	str	r7, [r6, #0x8]
   cfc34: ebffc36f     	bl	0xc09f8 <_ZN9_RefThingIPKcE3decEv> @ imm = #-0xf244
   cfc38: e1a00006     	mov	r0, r6
   cfc3c: eb06b563     	bl	0x27d1d0 <_ZdlPv>       @ imm = #0x1ad58c
   cfc40: eb0304ba     	bl	0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> @ imm = #0xc12e8
   cfc44: e1a00006     	mov	r0, r6
   cfc48: eb06b560     	bl	0x27d1d0 <_ZdlPv>       @ imm = #0x1ad580
   cfc4c: eaffffe5     	b	0xcfbe8 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei+0x2d4> @ imm = #-0x6c
   cfc50: 00322324     	eorseq	r2, r2, r4, lsr #6
   cfc54: ffffbf14     	<unknown>
   cfc58: ffffbf18     	<unknown>
   cfc5c: ffffbf1c     	<unknown>
