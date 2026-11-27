
/data/data/com.termux/files/home/cally-oracle/libyoyo.so:	file format elf32-littlearm

Disassembly of section .text:

001d38e0 <_Z9StartRoomib>:
  1d38e0: e92d4ff0     	push	{r4, r5, r6, r7, r8, r9, r10, r11, lr}
  1d38e4: e24dd044     	sub	sp, sp, #68
  1d38e8: e59fbb1c     	ldr	r11, [pc, #0xb1c]       @ 0x1d440c <_Z9StartRoomib+0xb2c>
  1d38ec: e3a02000     	mov	r2, #0
  1d38f0: e59f3b18     	ldr	r3, [pc, #0xb18]        @ 0x1d4410 <_Z9StartRoomib+0xb30>
  1d38f4: e3510000     	cmp	r1, #0
  1d38f8: e08fb00b     	add	r11, pc, r11
  1d38fc: e58d2030     	str	r2, [sp, #0x30]
  1d3900: e58d102c     	str	r1, [sp, #0x2c]
  1d3904: e3e02000     	mvn	r2, #0
  1d3908: e79b3003     	ldr	r3, [r11, r3]
  1d390c: e1a07000     	mov	r7, r0
  1d3910: e5832000     	str	r2, [r3]
  1d3914: 1a00027b     	bne	0x1d4308 <_Z9StartRoomib+0xa28> @ imm = #0x9ec
  1d3918: ebff3b97     	bl	0x1a277c <_Z12Effect_Clearv> @ imm = #-0x311a4
  1d391c: e59f3af0     	ldr	r3, [pc, #0xaf0]        @ 0x1d4414 <_Z9StartRoomib+0xb34>
  1d3920: e79b4003     	ldr	r4, [r11, r3]
  1d3924: e5945000     	ldr	r5, [r4]
  1d3928: e1550007     	cmp	r5, r7
  1d392c: da000246     	ble	0x1d424c <_Z9StartRoomib+0x96c> @ imm = #0x918
  1d3930: e59f3ae0     	ldr	r3, [pc, #0xae0]        @ 0x1d4418 <_Z9StartRoomib+0xb38>
  1d3934: e79b3003     	ldr	r3, [r11, r3]
  1d3938: e5837000     	str	r7, [r3]
  1d393c: e5943004     	ldr	r3, [r4, #0x4]
  1d3940: e7930107     	ldr	r0, [r3, r7, lsl #2]
  1d3944: ebffe043     	bl	0x1cba58 <_Z12Run_Room_SetP5CRoom> @ imm = #-0x7ef4
  1d3948: e59f3acc     	ldr	r3, [pc, #0xacc]        @ 0x1d441c <_Z9StartRoomib+0xb3c>
  1d394c: e79b6003     	ldr	r6, [r11, r3]
  1d3950: e5963000     	ldr	r3, [r6]
  1d3954: e293c000     	adds	r12, r3, #0
  1d3958: 13a0c001     	movne	r12, #1
  1d395c: e35c0000     	cmp	r12, #0
  1d3960: e58dc020     	str	r12, [sp, #0x20]
  1d3964: 0a000221     	beq	0x1d41f0 <_Z9StartRoomib+0x910> @ imm = #0x884
  1d3968: e5934080     	ldr	r4, [r3, #0x80]
  1d396c: e3540000     	cmp	r4, #0
  1d3970: 0a000028     	beq	0x1d3a18 <_Z9StartRoomib+0x138> @ imm = #0xa0
  1d3974: e59f3aa4     	ldr	r3, [pc, #0xaa4]        @ 0x1d4420 <_Z9StartRoomib+0xb40>
  1d3978: e59faaa4     	ldr	r10, [pc, #0xaa4]       @ 0x1d4424 <_Z9StartRoomib+0xb44>
  1d397c: e79b5003     	ldr	r5, [r11, r3]
  1d3980: e08fa00a     	add	r10, pc, r10
  1d3984: e58d6014     	str	r6, [sp, #0x14]
  1d3988: ea000000     	b	0x1d3990 <_Z9StartRoomib+0xb0> @ imm = #0x0
  1d398c: e1a04007     	mov	r4, r7
  1d3990: e5940080     	ldr	r0, [r4, #0x80]
  1d3994: e1a01004     	mov	r1, r4
  1d3998: e5947178     	ldr	r7, [r4, #0x178]
  1d399c: ebff29a2     	bl	0x19e02c <_ZN9CObjectGM11AddInstanceEP9CInstance> @ imm = #-0x35978
  1d39a0: e3002132     	movw	r2, #0x132
  1d39a4: e3a03001     	mov	r3, #1
  1d39a8: e3a00010     	mov	r0, #16
  1d39ac: e1a0100a     	mov	r1, r10
  1d39b0: e5958000     	ldr	r8, [r5]
  1d39b4: e5946078     	ldr	r6, [r4, #0x78]
  1d39b8: e5959004     	ldr	r9, [r5, #0x4]
  1d39bc: eb02a52d     	bl	0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> @ imm = #0xa94b4
  1d39c0: e0069009     	and	r9, r6, r9
  1d39c4: e7982189     	ldr	r2, [r8, r9, lsl #3]
  1d39c8: e0883189     	add	r3, r8, r9, lsl #3
  1d39cc: e3520000     	cmp	r2, #0
  1d39d0: 15932004     	ldrne	r2, [r3, #0x4]
  1d39d4: 13a0e000     	movne	lr, #0
  1d39d8: e5806008     	str	r6, [r0, #0x8]
  1d39dc: e580400c     	str	r4, [r0, #0xc]
  1d39e0: 15802000     	strne	r2, [r0]
  1d39e4: 05830004     	streq	r0, [r3, #0x4]
  1d39e8: 15820004     	strne	r0, [r2, #0x4]
  1d39ec: 07880189     	streq	r0, [r8, r9, lsl #3]
  1d39f0: 15830004     	strne	r0, [r3, #0x4]
  1d39f4: 05802004     	streq	r2, [r0, #0x4]
  1d39f8: 05802000     	streq	r2, [r0]
  1d39fc: 1580e004     	strne	lr, [r0, #0x4]
  1d3a00: e3570000     	cmp	r7, #0
  1d3a04: e5953008     	ldr	r3, [r5, #0x8]
  1d3a08: e2833001     	add	r3, r3, #1
  1d3a0c: e5853008     	str	r3, [r5, #0x8]
  1d3a10: 1affffdd     	bne	0x1d398c <_Z9StartRoomib+0xac> @ imm = #-0x8c
  1d3a14: e59d6014     	ldr	r6, [sp, #0x14]
  1d3a18: e59f3a08     	ldr	r3, [pc, #0xa08]        @ 0x1d4428 <_Z9StartRoomib+0xb48>
  1d3a1c: e79b3003     	ldr	r3, [r11, r3]
  1d3a20: e58d3014     	str	r3, [sp, #0x14]
  1d3a24: e5d33000     	ldrb	r3, [r3]
  1d3a28: e3530000     	cmp	r3, #0
  1d3a2c: 1a0001eb     	bne	0x1d41e0 <_Z9StartRoomib+0x900> @ imm = #0x7ac
  1d3a30: e5960000     	ldr	r0, [r6]
  1d3a34: ebffc8e0     	bl	0x1c5dbc <_ZN13CLayerManager25BuildRoomLayerRuntimeDataEP5CRoom> @ imm = #-0xdc80
  1d3a38: ebff4857     	bl	0x1a5b9c <_Z29ParticleSystem_AddAllToLayersv> @ imm = #-0x2dea4
  1d3a3c: ebff7bde     	bl	0x1b29bc <_Z17Draw_Room_SetSizev> @ imm = #-0x21088
  1d3a40: e59f39e4     	ldr	r3, [pc, #0x9e4]        @ 0x1d442c <_Z9StartRoomib+0xb4c>
  1d3a44: e79b3003     	ldr	r3, [r11, r3]
  1d3a48: e58d3018     	str	r3, [sp, #0x18]
  1d3a4c: e5933000     	ldr	r3, [r3]
  1d3a50: e3530000     	cmp	r3, #0
  1d3a54: e59f39d4     	ldr	r3, [pc, #0x9d4]        @ 0x1d4430 <_Z9StartRoomib+0xb50>
  1d3a58: da000262     	ble	0x1d43e8 <_Z9StartRoomib+0xb08> @ imm = #0x988
  1d3a5c: e59f09d0     	ldr	r0, [pc, #0x9d0]        @ 0x1d4434 <_Z9StartRoomib+0xb54>
  1d3a60: e3a0c000     	mov	r12, #0
  1d3a64: e1a0800c     	mov	r8, r12
  1d3a68: e08f0000     	add	r0, pc, r0
  1d3a6c: e58d0028     	str	r0, [sp, #0x28]
  1d3a70: e79b7003     	ldr	r7, [r11, r3]
  1d3a74: e58db024     	str	r11, [sp, #0x24]
  1d3a78: e1a0b00c     	mov	r11, r12
  1d3a7c: e5973000     	ldr	r3, [r7]
  1d3a80: e596a000     	ldr	r10, [r6]
  1d3a84: e1530008     	cmp	r3, r8
  1d3a88: c5973004     	ldrgt	r3, [r7, #0x4]
  1d3a8c: d3a04000     	movle	r4, #0
  1d3a90: c793400b     	ldrgt	r4, [r3, r11]
  1d3a94: e59a3080     	ldr	r3, [r10, #0x80]
  1d3a98: e3530000     	cmp	r3, #0
  1d3a9c: e5949078     	ldr	r9, [r4, #0x78]
  1d3aa0: 0a00000b     	beq	0x1d3ad4 <_Z9StartRoomib+0x1f4> @ imm = #0x2c
  1d3aa4: e5932078     	ldr	r2, [r3, #0x78]
  1d3aa8: e5935178     	ldr	r5, [r3, #0x178]
  1d3aac: e1520009     	cmp	r2, r9
  1d3ab0: 1a000005     	bne	0x1d3acc <_Z9StartRoomib+0x1ec> @ imm = #0x14
  1d3ab4: ea0000e2     	b	0x1d3e44 <_Z9StartRoomib+0x564> @ imm = #0x388
  1d3ab8: e5953078     	ldr	r3, [r5, #0x78]
  1d3abc: e5952178     	ldr	r2, [r5, #0x178]
  1d3ac0: e1530009     	cmp	r3, r9
  1d3ac4: 0a0000df     	beq	0x1d3e48 <_Z9StartRoomib+0x568> @ imm = #0x37c
  1d3ac8: e1a05002     	mov	r5, r2
  1d3acc: e3550000     	cmp	r5, #0
  1d3ad0: 1afffff8     	bne	0x1d3ab8 <_Z9StartRoomib+0x1d8> @ imm = #-0x20
  1d3ad4: e594307c     	ldr	r3, [r4, #0x7c]
  1d3ad8: e3a00e1b     	mov	r0, #432
  1d3adc: e59410b4     	ldr	r1, [r4, #0xb4]
  1d3ae0: e594a0b8     	ldr	r10, [r4, #0xb8]
  1d3ae4: e58d300c     	str	r3, [sp, #0xc]
  1d3ae8: e58d1010     	str	r1, [sp, #0x10]
  1d3aec: eb02a28c     	bl	0x27c524 <_Znwj>        @ imm = #0xa8a30
  1d3af0: e59d300c     	ldr	r3, [sp, #0xc]
  1d3af4: e3a0e000     	mov	lr, #0
  1d3af8: e59d1010     	ldr	r1, [sp, #0x10]
  1d3afc: e1a0200a     	mov	r2, r10
  1d3b00: e58de004     	str	lr, [sp, #0x4]
  1d3b04: e58d3000     	str	r3, [sp]
  1d3b08: e1a03009     	mov	r3, r9
  1d3b0c: e1a05000     	mov	r5, r0
  1d3b10: ebff1671     	bl	0x1994dc <_ZN9CInstanceC2Effiib> @ imm = #-0x3a63c
  1d3b14: e59dc014     	ldr	r12, [sp, #0x14]
  1d3b18: e5dc3000     	ldrb	r3, [r12]
  1d3b1c: e3530000     	cmp	r3, #0
  1d3b20: 15943180     	ldrne	r3, [r4, #0x180]
  1d3b24: 15853180     	strne	r3, [r5, #0x180]
  1d3b28: e3a02001     	mov	r2, #1
  1d3b2c: e1a00005     	mov	r0, r5
  1d3b30: e1a01004     	mov	r1, r4
  1d3b34: ebff12ec     	bl	0x1986ec <_ZN9CInstance6AssignEPS_b> @ imm = #-0x3b450
  1d3b38: e5961000     	ldr	r1, [r6]
  1d3b3c: e1a00005     	mov	r0, r5
  1d3b40: ebfefd17     	bl	0x192fa4 <_ZN9CInstance18RebuildPhysicsBodyEP5CRoom> @ imm = #-0x40ba4
  1d3b44: e5962000     	ldr	r2, [r6]
  1d3b48: e5923084     	ldr	r3, [r2, #0x84]
  1d3b4c: e5921088     	ldr	r1, [r2, #0x88]
  1d3b50: e3530000     	cmp	r3, #0
  1d3b54: 1d957a60     	vldrne	s14, [r5, #384]
  1d3b58: e2811001     	add	r1, r1, #1
  1d3b5c: e5821088     	str	r1, [r2, #0x88]
  1d3b60: 0a000191     	beq	0x1d41ac <_Z9StartRoomib+0x8cc> @ imm = #0x644
  1d3b64: edd37a61     	vldr	s15, [r3, #388]
  1d3b68: eef47ac7     	vcmpe.f32	s15, s14
  1d3b6c: eef1fa10     	vmrs	APSR_nzcv, fpscr
  1d3b70: 9a000101     	bls	0x1d3f7c <_Z9StartRoomib+0x69c> @ imm = #0x404
  1d3b74: e593317c     	ldr	r3, [r3, #0x17c]
  1d3b78: e3530000     	cmp	r3, #0
  1d3b7c: 1afffff8     	bne	0x1d3b64 <_Z9StartRoomib+0x284> @ imm = #-0x20
  1d3b80: e5921080     	ldr	r1, [r2, #0x80]
  1d3b84: ed857a61     	vstr	s14, [r5, #388]
  1d3b88: e581517c     	str	r5, [r1, #0x17c]
  1d3b8c: e5851178     	str	r1, [r5, #0x178]
  1d3b90: e5825080     	str	r5, [r2, #0x80]
  1d3b94: e585317c     	str	r3, [r5, #0x17c]
  1d3b98: e595c078     	ldr	r12, [r5, #0x78]
  1d3b9c: e3002132     	movw	r2, #0x132
  1d3ba0: e59fe878     	ldr	lr, [pc, #0x878]        @ 0x1d4420 <_Z9StartRoomib+0xb40>
  1d3ba4: e3a03001     	mov	r3, #1
  1d3ba8: e59d1028     	ldr	r1, [sp, #0x28]
  1d3bac: e3a00010     	mov	r0, #16
  1d3bb0: e58dc01c     	str	r12, [sp, #0x1c]
  1d3bb4: e59dc024     	ldr	r12, [sp, #0x24]
  1d3bb8: e79c900e     	ldr	r9, [r12, lr]
  1d3bbc: e59de01c     	ldr	lr, [sp, #0x1c]
  1d3bc0: e8991400     	ldm	r9, {r10, r12}
  1d3bc4: e00ec00c     	and	r12, lr, r12
  1d3bc8: e58dc010     	str	r12, [sp, #0x10]
  1d3bcc: eb02a4a9     	bl	0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> @ imm = #0xa92a4
  1d3bd0: e59dc010     	ldr	r12, [sp, #0x10]
  1d3bd4: e59d101c     	ldr	r1, [sp, #0x1c]
  1d3bd8: e79a218c     	ldr	r2, [r10, r12, lsl #3]
  1d3bdc: e08a318c     	add	r3, r10, r12, lsl #3
  1d3be0: e3520000     	cmp	r2, #0
  1d3be4: 15932004     	ldrne	r2, [r3, #0x4]
  1d3be8: e5801008     	str	r1, [r0, #0x8]
  1d3bec: e1a01005     	mov	r1, r5
  1d3bf0: 15802000     	strne	r2, [r0]
  1d3bf4: e580500c     	str	r5, [r0, #0xc]
  1d3bf8: 05830004     	streq	r0, [r3, #0x4]
  1d3bfc: 15820004     	strne	r0, [r2, #0x4]
  1d3c00: 13a02000     	movne	r2, #0
  1d3c04: 15830004     	strne	r0, [r3, #0x4]
  1d3c08: e5993008     	ldr	r3, [r9, #0x8]
  1d3c0c: 078a018c     	streq	r0, [r10, r12, lsl #3]
  1d3c10: e3a0c000     	mov	r12, #0
  1d3c14: 05802004     	streq	r2, [r0, #0x4]
  1d3c18: e2833001     	add	r3, r3, #1
  1d3c1c: 05802000     	streq	r2, [r0]
  1d3c20: 15802004     	strne	r2, [r0, #0x4]
  1d3c24: e3e02000     	mvn	r2, #0
  1d3c28: e5c5c174     	strb	r12, [r5, #0x174]
  1d3c2c: e5852170     	str	r2, [r5, #0x170]
  1d3c30: e5960000     	ldr	r0, [r6]
  1d3c34: e5893008     	str	r3, [r9, #0x8]
  1d3c38: ebffc836     	bl	0x1c5d18 <_ZN13CLayerManager11AddInstanceEP5CRoomP9CInstance> @ imm = #-0xdf28
  1d3c3c: e3a0e001     	mov	lr, #1
  1d3c40: e5c5e06b     	strb	lr, [r5, #0x6b]
  1d3c44: e5943000     	ldr	r3, [r4]
  1d3c48: e1a00004     	mov	r0, r4
  1d3c4c: e2888001     	add	r8, r8, #1
  1d3c50: e5933004     	ldr	r3, [r3, #0x4]
  1d3c54: e12fff33     	blx	r3
  1d3c58: e59dc018     	ldr	r12, [sp, #0x18]
  1d3c5c: e5973004     	ldr	r3, [r7, #0x4]
  1d3c60: e3a0e000     	mov	lr, #0
  1d3c64: e59c2000     	ldr	r2, [r12]
  1d3c68: e783e00b     	str	lr, [r3, r11]
  1d3c6c: e28bb004     	add	r11, r11, #4
  1d3c70: e1520008     	cmp	r2, r8
  1d3c74: caffff80     	bgt	0x1d3a7c <_Z9StartRoomib+0x19c> @ imm = #-0x200
  1d3c78: e59db024     	ldr	r11, [sp, #0x24]
  1d3c7c: e5974004     	ldr	r4, [r7, #0x4]
  1d3c80: e3540000     	cmp	r4, #0
  1d3c84: 0a0001cd     	beq	0x1d43c0 <_Z9StartRoomib+0xae0> @ imm = #0x734
  1d3c88: e5972000     	ldr	r2, [r7]
  1d3c8c: e3520000     	cmp	r2, #0
  1d3c90: da000006     	ble	0x1d3cb0 <_Z9StartRoomib+0x3d0> @ imm = #0x18
  1d3c94: e3a03000     	mov	r3, #0
  1d3c98: e1a01003     	mov	r1, r3
  1d3c9c: e7841103     	str	r1, [r4, r3, lsl #2]
  1d3ca0: e2833001     	add	r3, r3, #1
  1d3ca4: e1530002     	cmp	r3, r2
  1d3ca8: e5974004     	ldr	r4, [r7, #0x4]
  1d3cac: 1afffffa     	bne	0x1d3c9c <_Z9StartRoomib+0x3bc> @ imm = #-0x18
  1d3cb0: e1a00004     	mov	r0, r4
  1d3cb4: eb02a185     	bl	0x27c2d0 <_ZN13MemoryManager4FreeEPKv> @ imm = #0xa8614
  1d3cb8: e3a03000     	mov	r3, #0
  1d3cbc: e5873004     	str	r3, [r7, #0x4]
  1d3cc0: e59dc020     	ldr	r12, [sp, #0x20]
  1d3cc4: e3a03000     	mov	r3, #0
  1d3cc8: e5873000     	str	r3, [r7]
  1d3ccc: e35c0000     	cmp	r12, #0
  1d3cd0: e59dc018     	ldr	r12, [sp, #0x18]
  1d3cd4: e58c3000     	str	r3, [r12]
  1d3cd8: 0a0000b4     	beq	0x1d3fb0 <_Z9StartRoomib+0x6d0> @ imm = #0x2d0
  1d3cdc: e5960000     	ldr	r0, [r6]
  1d3ce0: ebff5f8f     	bl	0x1abb24 <_ZN5CRoom12RemoveMarkedEv> @ imm = #-0x281c4
  1d3ce4: e59dc02c     	ldr	r12, [sp, #0x2c]
  1d3ce8: e3a03000     	mov	r3, #0
  1d3cec: e35c0000     	cmp	r12, #0
  1d3cf0: e59dc018     	ldr	r12, [sp, #0x18]
  1d3cf4: e58c3000     	str	r3, [r12]
  1d3cf8: 1a000132     	bne	0x1d41c8 <_Z9StartRoomib+0x8e8> @ imm = #0x4c8
  1d3cfc: e59dc020     	ldr	r12, [sp, #0x20]
  1d3d00: e35c0000     	cmp	r12, #0
  1d3d04: 1a00003d     	bne	0x1d3e00 <_Z9StartRoomib+0x520> @ imm = #0xf4
  1d3d08: e5963000     	ldr	r3, [r6]
  1d3d0c: e5932068     	ldr	r2, [r3, #0x68]
  1d3d10: e3520000     	cmp	r2, #0
  1d3d14: 0a000039     	beq	0x1d3e00 <_Z9StartRoomib+0x520> @ imm = #0xe4
  1d3d18: e593206c     	ldr	r2, [r3, #0x6c]
  1d3d1c: e3520000     	cmp	r2, #0
  1d3d20: 0a000036     	beq	0x1d3e00 <_Z9StartRoomib+0x520> @ imm = #0xd8
  1d3d24: e59f370c     	ldr	r3, [pc, #0x70c]        @ 0x1d4438 <_Z9StartRoomib+0xb58>
  1d3d28: e79b3003     	ldr	r3, [r11, r3]
  1d3d2c: e5d33000     	ldrb	r3, [r3]
  1d3d30: e3530000     	cmp	r3, #0
  1d3d34: 1a000110     	bne	0x1d417c <_Z9StartRoomib+0x89c> @ imm = #0x440
  1d3d38: e3a00e1b     	mov	r0, #432
  1d3d3c: e28d5030     	add	r5, sp, #48
  1d3d40: eb02a1f7     	bl	0x27c524 <_Znwj>        @ imm = #0xa87dc
  1d3d44: e59d3020     	ldr	r3, [sp, #0x20]
  1d3d48: e3a01000     	mov	r1, #0
  1d3d4c: e1a02001     	mov	r2, r1
  1d3d50: e58d3000     	str	r3, [sp]
  1d3d54: e58d3004     	str	r3, [sp, #0x4]
  1d3d58: e1a04000     	mov	r4, r0
  1d3d5c: ebff15de     	bl	0x1994dc <_ZN9CInstanceC2Effiib> @ imm = #-0x3a888
  1d3d60: e59d303c     	ldr	r3, [sp, #0x3c]
  1d3d64: e2433001     	sub	r3, r3, #1
  1d3d68: e3c334ff     	bic	r3, r3, #-16777216
  1d3d6c: e3c33003     	bic	r3, r3, #3
  1d3d70: e3530000     	cmp	r3, #0
  1d3d74: 0a000198     	beq	0x1d43dc <_Z9StartRoomib+0xafc> @ imm = #0x660
  1d3d78: e5962000     	ldr	r2, [r6]
  1d3d7c: e3a0c000     	mov	r12, #0
  1d3d80: e1a03005     	mov	r3, r5
  1d3d84: e1a00004     	mov	r0, r4
  1d3d88: e1a01004     	mov	r1, r4
  1d3d8c: e3a0e005     	mov	lr, #5
  1d3d90: e592206c     	ldr	r2, [r2, #0x6c]
  1d3d94: e58dc000     	str	r12, [sp]
  1d3d98: e58dc038     	str	r12, [sp, #0x38]
  1d3d9c: e58dc030     	str	r12, [sp, #0x30]
  1d3da0: e58de03c     	str	lr, [sp, #0x3c]
  1d3da4: ebfbefad     	bl	0xcfc60 <_Z12Code_ExecuteP9CInstanceS0_P5CCodeP6RValuei> @ imm = #-0x10414c
  1d3da8: e59d303c     	ldr	r3, [sp, #0x3c]
  1d3dac: e2433001     	sub	r3, r3, #1
  1d3db0: e3c334ff     	bic	r3, r3, #-16777216
  1d3db4: e3c33003     	bic	r3, r3, #3
  1d3db8: e3530000     	cmp	r3, #0
  1d3dbc: 0a000183     	beq	0x1d43d0 <_Z9StartRoomib+0xaf0> @ imm = #0x60c
  1d3dc0: e3540000     	cmp	r4, #0
  1d3dc4: e3a03000     	mov	r3, #0
  1d3dc8: e3a02005     	mov	r2, #5
  1d3dcc: e58d3038     	str	r3, [sp, #0x38]
  1d3dd0: e58d3030     	str	r3, [sp, #0x30]
  1d3dd4: e58d203c     	str	r2, [sp, #0x3c]
  1d3dd8: 0a000003     	beq	0x1d3dec <_Z9StartRoomib+0x50c> @ imm = #0xc
  1d3ddc: e5943000     	ldr	r3, [r4]
  1d3de0: e1a00004     	mov	r0, r4
  1d3de4: e5933004     	ldr	r3, [r3, #0x4]
  1d3de8: e12fff33     	blx	r3
  1d3dec: e59f3648     	ldr	r3, [pc, #0x648]        @ 0x1d443c <_Z9StartRoomib+0xb5c>
  1d3df0: e79b3003     	ldr	r3, [r11, r3]
  1d3df4: e5d33000     	ldrb	r3, [r3]
  1d3df8: e3530000     	cmp	r3, #0
  1d3dfc: 1a000180     	bne	0x1d4404 <_Z9StartRoomib+0xb24> @ imm = #0x600
  1d3e00: e3a00007     	mov	r0, #7
  1d3e04: e3a01004     	mov	r1, #4
  1d3e08: ebfc7d68     	bl	0xf33b0 <_Z17Perform_Event_Allii> @ imm = #-0xe0a60
  1d3e0c: e5960000     	ldr	r0, [r6]
  1d3e10: ebff5f43     	bl	0x1abb24 <_ZN5CRoom12RemoveMarkedEv> @ imm = #-0x282f4
  1d3e14: e59d303c     	ldr	r3, [sp, #0x3c]
  1d3e18: e2433001     	sub	r3, r3, #1
  1d3e1c: e3c334ff     	bic	r3, r3, #-16777216
  1d3e20: e3c33003     	bic	r3, r3, #3
  1d3e24: e3530000     	cmp	r3, #0
  1d3e28: 0a0000dc     	beq	0x1d41a0 <_Z9StartRoomib+0x8c0> @ imm = #0x370
  1d3e2c: e59f360c     	ldr	r3, [pc, #0x60c]        @ 0x1d4440 <_Z9StartRoomib+0xb60>
  1d3e30: e3a02001     	mov	r2, #1
  1d3e34: e79b3003     	ldr	r3, [r11, r3]
  1d3e38: e5c32000     	strb	r2, [r3]
  1d3e3c: e28dd044     	add	sp, sp, #68
  1d3e40: e8bd8ff0     	pop	{r4, r5, r6, r7, r8, r9, r10, r11, pc}
  1d3e44: e1a05003     	mov	r5, r3
  1d3e48: e59dc014     	ldr	r12, [sp, #0x14]
  1d3e4c: e5dc3000     	ldrb	r3, [r12]
  1d3e50: e3530000     	cmp	r3, #0
  1d3e54: 1a000010     	bne	0x1d3e9c <_Z9StartRoomib+0x5bc> @ imm = #0x40
  1d3e58: e1a00005     	mov	r0, r5
  1d3e5c: e1a01004     	mov	r1, r4
  1d3e60: e3a02001     	mov	r2, #1
  1d3e64: ebff1220     	bl	0x1986ec <_ZN9CInstance6AssignEPS_b> @ imm = #-0x3b780
  1d3e68: e1a00005     	mov	r0, r5
  1d3e6c: e5961000     	ldr	r1, [r6]
  1d3e70: ebfefc4b     	bl	0x192fa4 <_ZN9CInstance18RebuildPhysicsBodyEP5CRoom> @ imm = #-0x40ed4
  1d3e74: e3a0e001     	mov	lr, #1
  1d3e78: e3a00000     	mov	r0, #0
  1d3e7c: e3e03000     	mvn	r3, #0
  1d3e80: e5c50174     	strb	r0, [r5, #0x174]
  1d3e84: e1a01005     	mov	r1, r5
  1d3e88: e5c5e06b     	strb	lr, [r5, #0x6b]
  1d3e8c: e5853170     	str	r3, [r5, #0x170]
  1d3e90: e5960000     	ldr	r0, [r6]
  1d3e94: ebffc79f     	bl	0x1c5d18 <_ZN13CLayerManager11AddInstanceEP5CRoomP9CInstance> @ imm = #-0xe184
  1d3e98: eaffff69     	b	0x1d3c44 <_Z9StartRoomib+0x364> @ imm = #-0x25c
  1d3e9c: e5943180     	ldr	r3, [r4, #0x180]
  1d3ea0: e5853180     	str	r3, [r5, #0x180]
  1d3ea4: e5940078     	ldr	r0, [r4, #0x78]
  1d3ea8: ebff8be5     	bl	0x1b6e44 <_Z21CHashMapCalculateHashi> @ imm = #-0x1d06c
  1d3eac: e59a1118     	ldr	r1, [r10, #0x118]
  1d3eb0: e59a9120     	ldr	r9, [r10, #0x120]
  1d3eb4: e3c00102     	bic	r0, r0, #-2147483648
  1d3eb8: e0003001     	and	r3, r0, r1
  1d3ebc: e1a0e083     	lsl	lr, r3, #1
  1d3ec0: e08e2003     	add	r2, lr, r3
  1d3ec4: e0892102     	add	r2, r9, r2, lsl #2
  1d3ec8: e5922008     	ldr	r2, [r2, #0x8]
  1d3ecc: e3520000     	cmp	r2, #0
  1d3ed0: 0affffe0     	beq	0x1d3e58 <_Z9StartRoomib+0x578> @ imm = #-0x80
  1d3ed4: e1500002     	cmp	r0, r2
  1d3ed8: 0a00001a     	beq	0x1d3f48 <_Z9StartRoomib+0x668> @ imm = #0x68
  1d3edc: e59aa110     	ldr	r10, [r10, #0x110]
  1d3ee0: e0012002     	and	r2, r1, r2
  1d3ee4: e083c00a     	add	r12, r3, r10
  1d3ee8: e062200c     	rsb	r2, r2, r12
  1d3eec: e1120001     	tst	r2, r1
  1d3ef0: 4affffd8     	bmi	0x1d3e58 <_Z9StartRoomib+0x578> @ imm = #-0xa0
  1d3ef4: e3a0c000     	mov	r12, #0
  1d3ef8: ea000005     	b	0x1d3f14 <_Z9StartRoomib+0x634> @ imm = #0x14
  1d3efc: e0012002     	and	r2, r1, r2
  1d3f00: e083e00a     	add	lr, r3, r10
  1d3f04: e062200e     	rsb	r2, r2, lr
  1d3f08: e0022001     	and	r2, r2, r1
  1d3f0c: e152000c     	cmp	r2, r12
  1d3f10: baffffd0     	blt	0x1d3e58 <_Z9StartRoomib+0x578> @ imm = #-0xc0
  1d3f14: e2833001     	add	r3, r3, #1
  1d3f18: e28cc001     	add	r12, r12, #1
  1d3f1c: e0013003     	and	r3, r1, r3
  1d3f20: e1a0e083     	lsl	lr, r3, #1
  1d3f24: e08e2003     	add	r2, lr, r3
  1d3f28: e0892102     	add	r2, r9, r2, lsl #2
  1d3f2c: e5922008     	ldr	r2, [r2, #0x8]
  1d3f30: e3520000     	cmp	r2, #0
  1d3f34: 0affffc7     	beq	0x1d3e58 <_Z9StartRoomib+0x578> @ imm = #-0xe4
  1d3f38: e1500002     	cmp	r0, r2
  1d3f3c: 1affffee     	bne	0x1d3efc <_Z9StartRoomib+0x61c> @ imm = #-0x48
  1d3f40: e3730001     	cmn	r3, #1
  1d3f44: 0affffc3     	beq	0x1d3e58 <_Z9StartRoomib+0x578> @ imm = #-0xf4
  1d3f48: e08e3003     	add	r3, lr, r3
  1d3f4c: e0899103     	add	r9, r9, r3, lsl #2
  1d3f50: e3790004     	cmn	r9, #4
  1d3f54: 0affffbf     	beq	0x1d3e58 <_Z9StartRoomib+0x578> @ imm = #-0x104
  1d3f58: e5993004     	ldr	r3, [r9, #0x4]
  1d3f5c: e3530000     	cmp	r3, #0
  1d3f60: 0affffbc     	beq	0x1d3e58 <_Z9StartRoomib+0x578> @ imm = #-0x110
  1d3f64: e5931020     	ldr	r1, [r3, #0x20]
  1d3f68: e3510000     	cmp	r1, #0
  1d3f6c: 0affffb9     	beq	0x1d3e58 <_Z9StartRoomib+0x578> @ imm = #-0x11c
  1d3f70: e5960000     	ldr	r0, [r6]
  1d3f74: ebff97b8     	bl	0x1b9e5c <_ZN13CLayerManager14RemoveInstanceEP5CRoomP9CInstance> @ imm = #-0x1a120
  1d3f78: eaffffb6     	b	0x1d3e58 <_Z9StartRoomib+0x578> @ imm = #-0x128
  1d3f7c: e5931178     	ldr	r1, [r3, #0x178]
  1d3f80: e3510000     	cmp	r1, #0
  1d3f84: 0585317c     	streq	r3, [r5, #0x17c]
  1d3f88: 15851178     	strne	r1, [r5, #0x178]
  1d3f8c: 15932178     	ldrne	r2, [r3, #0x178]
  1d3f90: 05835178     	streq	r5, [r3, #0x178]
  1d3f94: 1585317c     	strne	r3, [r5, #0x17c]
  1d3f98: 05825084     	streq	r5, [r2, #0x84]
  1d3f9c: 1582517c     	strne	r5, [r2, #0x17c]
  1d3fa0: 05851178     	streq	r1, [r5, #0x178]
  1d3fa4: 15835178     	strne	r5, [r3, #0x178]
  1d3fa8: ed857a61     	vstr	s14, [r5, #388]
  1d3fac: eafffef9     	b	0x1d3b98 <_Z9StartRoomib+0x2b8> @ imm = #-0x41c
  1d3fb0: e5963000     	ldr	r3, [r6]
  1d3fb4: e3a08001     	mov	r8, #1
  1d3fb8: e59d4020     	ldr	r4, [sp, #0x20]
  1d3fbc: e3a07005     	mov	r7, #5
  1d3fc0: e28d9030     	add	r9, sp, #48
  1d3fc4: e593c0a8     	ldr	r12, [r3, #0xa8]
  1d3fc8: e1a0a004     	mov	r10, r4
  1d3fcc: e59300a4     	ldr	r0, [r3, #0xa4]
  1d3fd0: e154000c     	cmp	r4, r12
  1d3fd4: aa00001c     	bge	0x1d404c <_Z9StartRoomib+0x76c> @ imm = #0x70
  1d3fd8: e59f2440     	ldr	r2, [pc, #0x440]        @ 0x1d4420 <_Z9StartRoomib+0xb40>
  1d3fdc: e7903104     	ldr	r3, [r0, r4, lsl #2]
  1d3fe0: e79b2002     	ldr	r2, [r11, r2]
  1d3fe4: e5921004     	ldr	r1, [r2, #0x4]
  1d3fe8: e5922000     	ldr	r2, [r2]
  1d3fec: e0031001     	and	r1, r3, r1
  1d3ff0: e7922181     	ldr	r2, [r2, r1, lsl #3]
  1d3ff4: e3520000     	cmp	r2, #0
  1d3ff8: 1a000003     	bne	0x1d400c <_Z9StartRoomib+0x72c> @ imm = #0xc
  1d3ffc: ea00000f     	b	0x1d4040 <_Z9StartRoomib+0x760> @ imm = #0x3c
  1d4000: e5922004     	ldr	r2, [r2, #0x4]
  1d4004: e3520000     	cmp	r2, #0
  1d4008: 0a00000c     	beq	0x1d4040 <_Z9StartRoomib+0x760> @ imm = #0x30
  1d400c: e5921008     	ldr	r1, [r2, #0x8]
  1d4010: e1530001     	cmp	r3, r1
  1d4014: 1afffff9     	bne	0x1d4000 <_Z9StartRoomib+0x720> @ imm = #-0x1c
  1d4018: e592500c     	ldr	r5, [r2, #0xc]
  1d401c: e3550000     	cmp	r5, #0
  1d4020: 0a000006     	beq	0x1d4040 <_Z9StartRoomib+0x760> @ imm = #0x18
  1d4024: e5d5306b     	ldrb	r3, [r5, #0x6b]
  1d4028: e3530000     	cmp	r3, #0
  1d402c: 15c5a06b     	strbne	r10, [r5, #0x6b]
  1d4030: 1a000002     	bne	0x1d4040 <_Z9StartRoomib+0x760> @ imm = #0x8
  1d4034: e5d53068     	ldrb	r3, [r5, #0x68]
  1d4038: e3530000     	cmp	r3, #0
  1d403c: 0a000009     	beq	0x1d4068 <_Z9StartRoomib+0x788> @ imm = #0x24
  1d4040: e2844001     	add	r4, r4, #1
  1d4044: e154000c     	cmp	r4, r12
  1d4048: baffffe2     	blt	0x1d3fd8 <_Z9StartRoomib+0x6f8> @ imm = #-0x78
  1d404c: eb02a09f     	bl	0x27c2d0 <_ZN13MemoryManager4FreeEPKv> @ imm = #0xa827c
  1d4050: e5963000     	ldr	r3, [r6]
  1d4054: e3a02000     	mov	r2, #0
  1d4058: e1a00003     	mov	r0, r3
  1d405c: e58320a4     	str	r2, [r3, #0xa4]
  1d4060: e58320a8     	str	r2, [r3, #0xa8]
  1d4064: eaffff1d     	b	0x1d3ce0 <_Z9StartRoomib+0x400> @ imm = #-0x38c
  1d4068: e595207c     	ldr	r2, [r5, #0x7c]
  1d406c: e1a00005     	mov	r0, r5
  1d4070: e58d3000     	str	r3, [sp]
  1d4074: e1a01005     	mov	r1, r5
  1d4078: e3a0300e     	mov	r3, #14
  1d407c: ebfc7c98     	bl	0xf32e4 <_Z20Perform_Event_ObjectP9CInstanceS0_iii> @ imm = #-0xe0da0
  1d4080: e5952164     	ldr	r2, [r5, #0x164]
  1d4084: e3520000     	cmp	r2, #0
  1d4088: 0a000016     	beq	0x1d40e8 <_Z9StartRoomib+0x808> @ imm = #0x58
  1d408c: e59d303c     	ldr	r3, [sp, #0x3c]
  1d4090: e2433001     	sub	r3, r3, #1
  1d4094: e3c334ff     	bic	r3, r3, #-16777216
  1d4098: e3c33003     	bic	r3, r3, #3
  1d409c: e3530000     	cmp	r3, #0
  1d40a0: 0a00009d     	beq	0x1d431c <_Z9StartRoomib+0xa3c> @ imm = #0x274
  1d40a4: e1a03009     	mov	r3, r9
  1d40a8: e58d8000     	str	r8, [sp]
  1d40ac: e1a00005     	mov	r0, r5
  1d40b0: e1a01005     	mov	r1, r5
  1d40b4: e58da038     	str	r10, [sp, #0x38]
  1d40b8: e58d703c     	str	r7, [sp, #0x3c]
  1d40bc: e58da030     	str	r10, [sp, #0x30]
  1d40c0: ebfbeee6     	bl	0xcfc60 <_Z12Code_ExecuteP9CInstanceS0_P5CCodeP6RValuei> @ imm = #-0x104468
  1d40c4: e59d303c     	ldr	r3, [sp, #0x3c]
  1d40c8: e2433001     	sub	r3, r3, #1
  1d40cc: e3c334ff     	bic	r3, r3, #-16777216
  1d40d0: e3c33003     	bic	r3, r3, #3
  1d40d4: e3530000     	cmp	r3, #0
  1d40d8: 0a000094     	beq	0x1d4330 <_Z9StartRoomib+0xa50> @ imm = #0x250
  1d40dc: e58da038     	str	r10, [sp, #0x38]
  1d40e0: e58d703c     	str	r7, [sp, #0x3c]
  1d40e4: e58da030     	str	r10, [sp, #0x30]
  1d40e8: e595207c     	ldr	r2, [r5, #0x7c]
  1d40ec: e1a00005     	mov	r0, r5
  1d40f0: e58da000     	str	r10, [sp]
  1d40f4: e1a01005     	mov	r1, r5
  1d40f8: e3a03000     	mov	r3, #0
  1d40fc: ebfc7c78     	bl	0xf32e4 <_Z20Perform_Event_ObjectP9CInstanceS0_iii> @ imm = #-0xe0e20
  1d4100: e5952160     	ldr	r2, [r5, #0x160]
  1d4104: e3520000     	cmp	r2, #0
  1d4108: 0a000016     	beq	0x1d4168 <_Z9StartRoomib+0x888> @ imm = #0x58
  1d410c: e59d303c     	ldr	r3, [sp, #0x3c]
  1d4110: e2433001     	sub	r3, r3, #1
  1d4114: e3c334ff     	bic	r3, r3, #-16777216
  1d4118: e3c33003     	bic	r3, r3, #3
  1d411c: e3530000     	cmp	r3, #0
  1d4120: 0a000085     	beq	0x1d433c <_Z9StartRoomib+0xa5c> @ imm = #0x214
  1d4124: e1a03009     	mov	r3, r9
  1d4128: e58d8000     	str	r8, [sp]
  1d412c: e1a00005     	mov	r0, r5
  1d4130: e1a01005     	mov	r1, r5
  1d4134: e58da038     	str	r10, [sp, #0x38]
  1d4138: e58d703c     	str	r7, [sp, #0x3c]
  1d413c: e58da030     	str	r10, [sp, #0x30]
  1d4140: ebfbeec6     	bl	0xcfc60 <_Z12Code_ExecuteP9CInstanceS0_P5CCodeP6RValuei> @ imm = #-0x1044e8
  1d4144: e59d303c     	ldr	r3, [sp, #0x3c]
  1d4148: e2433001     	sub	r3, r3, #1
  1d414c: e3c334ff     	bic	r3, r3, #-16777216
  1d4150: e3c33003     	bic	r3, r3, #3
  1d4154: e3530000     	cmp	r3, #0
  1d4158: 0a00006c     	beq	0x1d4310 <_Z9StartRoomib+0xa30> @ imm = #0x1b0
  1d415c: e58da038     	str	r10, [sp, #0x38]
  1d4160: e58d703c     	str	r7, [sp, #0x3c]
  1d4164: e58da030     	str	r10, [sp, #0x30]
  1d4168: e5963000     	ldr	r3, [r6]
  1d416c: e5c5806c     	strb	r8, [r5, #0x6c]
  1d4170: e593c0a8     	ldr	r12, [r3, #0xa8]
  1d4174: e59300a4     	ldr	r0, [r3, #0xa4]
  1d4178: eaffffb0     	b	0x1d4040 <_Z9StartRoomib+0x760> @ imm = #-0x140
  1d417c: e59f12c0     	ldr	r1, [pc, #0x2c0]        @ 0x1d4444 <_Z9StartRoomib+0xb64>
  1d4180: e28d3030     	add	r3, sp, #48
  1d4184: e59dc020     	ldr	r12, [sp, #0x20]
  1d4188: e79b1001     	ldr	r1, [r11, r1]
  1d418c: e58dc000     	str	r12, [sp]
  1d4190: e5910000     	ldr	r0, [r1]
  1d4194: e1a01000     	mov	r1, r0
  1d4198: ebfbeeb0     	bl	0xcfc60 <_Z12Code_ExecuteP9CInstanceS0_P5CCodeP6RValuei> @ imm = #-0x104540
  1d419c: eaffff12     	b	0x1d3dec <_Z9StartRoomib+0x50c> @ imm = #-0x3b8
  1d41a0: e28d0030     	add	r0, sp, #48
  1d41a4: ebfbb234     	bl	0xc0a7c <_Z16FREE_RValue__PreP6RValue> @ imm = #-0x113730
  1d41a8: eaffff1f     	b	0x1d3e2c <_Z9StartRoomib+0x54c> @ imm = #-0x384
  1d41ac: e5951180     	ldr	r1, [r5, #0x180]
  1d41b0: e5825084     	str	r5, [r2, #0x84]
  1d41b4: e5825080     	str	r5, [r2, #0x80]
  1d41b8: e5851184     	str	r1, [r5, #0x184]
  1d41bc: e585317c     	str	r3, [r5, #0x17c]
  1d41c0: e5853178     	str	r3, [r5, #0x178]
  1d41c4: eafffe73     	b	0x1d3b98 <_Z9StartRoomib+0x2b8> @ imm = #-0x634
  1d41c8: e3a00007     	mov	r0, #7
  1d41cc: e3a01002     	mov	r1, #2
  1d41d0: ebfc7c76     	bl	0xf33b0 <_Z17Perform_Event_Allii> @ imm = #-0xe0e28
  1d41d4: e5960000     	ldr	r0, [r6]
  1d41d8: ebff5e51     	bl	0x1abb24 <_ZN5CRoom12RemoveMarkedEv> @ imm = #-0x286bc
  1d41dc: eafffec6     	b	0x1d3cfc <_Z9StartRoomib+0x41c> @ imm = #-0x4e8
  1d41e0: e59f3260     	ldr	r3, [pc, #0x260]        @ 0x1d4448 <_Z9StartRoomib+0xb68>
  1d41e4: e79b0003     	ldr	r0, [r11, r3]
  1d41e8: ebfe6aab     	bl	0x16ec9c <_ZN14CCameraManager9StartRoomEv> @ imm = #-0x65554
  1d41ec: eafffe0f     	b	0x1d3a30 <_Z9StartRoomib+0x150> @ imm = #-0x7c4
  1d41f0: e3a00f49     	mov	r0, #292
  1d41f4: eb02a0ca     	bl	0x27c524 <_Znwj>        @ imm = #0xa8328
  1d41f8: e1a05000     	mov	r5, r0
  1d41fc: ebff6432     	bl	0x1ad2cc <_ZN5CRoomC2Ev> @ imm = #-0x26f38
  1d4200: e894000c     	ldm	r4, {r2, r3}
  1d4204: e1a00007     	mov	r0, r7
  1d4208: e1570002     	cmp	r7, r2
  1d420c: e7835107     	str	r5, [r3, r7, lsl #2]
  1d4210: b5943004     	ldrlt	r3, [r4, #0x4]
  1d4214: a59d5020     	ldrge	r5, [sp, #0x20]
  1d4218: b7935107     	ldrlt	r5, [r3, r7, lsl #2]
  1d421c: ebff8428     	bl	0x1b52c4 <_Z9Room_Datai> @ imm = #-0x1ef60
  1d4220: e3a02001     	mov	r2, #1
  1d4224: e1a01000     	mov	r1, r0
  1d4228: e1a00005     	mov	r0, r5
  1d422c: ebff6536     	bl	0x1ad70c <_ZN5CRoom6AssignEPS_b> @ imm = #-0x26b28
  1d4230: e5943000     	ldr	r3, [r4]
  1d4234: e1570003     	cmp	r7, r3
  1d4238: b5943004     	ldrlt	r3, [r4, #0x4]
  1d423c: a3a00000     	movge	r0, #0
  1d4240: b7930107     	ldrlt	r0, [r3, r7, lsl #2]
  1d4244: ebffde03     	bl	0x1cba58 <_Z12Run_Room_SetP5CRoom> @ imm = #-0x87f4
  1d4248: eafffdf2     	b	0x1d3a18 <_Z9StartRoomib+0x138> @ imm = #-0x838
  1d424c: e2876001     	add	r6, r7, #1
  1d4250: e1550006     	cmp	r5, r6
  1d4254: 0a000065     	beq	0x1d43f0 <_Z9StartRoomib+0xb10> @ imm = #0x194
  1d4258: e3560000     	cmp	r6, #0
  1d425c: e5940004     	ldr	r0, [r4, #0x4]
  1d4260: 1a00003a     	bne	0x1d4350 <_Z9StartRoomib+0xa70> @ imm = #0xe8
  1d4264: e3500000     	cmp	r0, #0
  1d4268: 0a000022     	beq	0x1d42f8 <_Z9StartRoomib+0xa18> @ imm = #0x88
  1d426c: e3550000     	cmp	r5, #0
  1d4270: da000020     	ble	0x1d42f8 <_Z9StartRoomib+0xa18> @ imm = #0x80
  1d4274: e1a08006     	mov	r8, r6
  1d4278: e1a0a006     	mov	r10, r6
  1d427c: e1a03000     	mov	r3, r0
  1d4280: e58d5014     	str	r5, [sp, #0x14]
  1d4284: e5931000     	ldr	r1, [r3]
  1d4288: e30f2eee     	movw	r2, #0xfeee
  1d428c: e34f2eee     	movt	r2, #0xfeee
  1d4290: e1510002     	cmp	r1, r2
  1d4294: 0a000011     	beq	0x1d42e0 <_Z9StartRoomib+0xa00> @ imm = #0x44
  1d4298: e7939108     	ldr	r9, [r3, r8, lsl #2]
  1d429c: e1a05108     	lsl	r5, r8, #2
  1d42a0: e0831005     	add	r1, r3, r5
  1d42a4: e3590000     	cmp	r9, #0
  1d42a8: 0a00000c     	beq	0x1d42e0 <_Z9StartRoomib+0xa00> @ imm = #0x30
  1d42ac: e5990000     	ldr	r0, [r9]
  1d42b0: e30f3eee     	movw	r3, #0xfeee
  1d42b4: e34f3eee     	movt	r3, #0xfeee
  1d42b8: e1500003     	cmp	r0, r3
  1d42bc: 0a000005     	beq	0x1d42d8 <_Z9StartRoomib+0x9f8> @ imm = #0x14
  1d42c0: e1a00009     	mov	r0, r9
  1d42c4: ebff6dcd     	bl	0x1afa00 <_ZN5CRoomD2Ev> @ imm = #-0x248cc
  1d42c8: e1a00009     	mov	r0, r9
  1d42cc: eb02a3bf     	bl	0x27d1d0 <_ZdlPv>       @ imm = #0xa8efc
  1d42d0: e5941004     	ldr	r1, [r4, #0x4]
  1d42d4: e0811005     	add	r1, r1, r5
  1d42d8: e581a000     	str	r10, [r1]
  1d42dc: e5943004     	ldr	r3, [r4, #0x4]
  1d42e0: e5942000     	ldr	r2, [r4]
  1d42e4: e2888001     	add	r8, r8, #1
  1d42e8: e1580002     	cmp	r8, r2
  1d42ec: baffffe4     	blt	0x1d4284 <_Z9StartRoomib+0x9a4> @ imm = #-0x70
  1d42f0: e59d5014     	ldr	r5, [sp, #0x14]
  1d42f4: e1a00003     	mov	r0, r3
  1d42f8: eb029ff4     	bl	0x27c2d0 <_ZN13MemoryManager4FreeEPKv> @ imm = #0xa7fd0
  1d42fc: e3a03000     	mov	r3, #0
  1d4300: e5843004     	str	r3, [r4, #0x4]
  1d4304: ea00001a     	b	0x1d4374 <_Z9StartRoomib+0xa94> @ imm = #0x68
  1d4308: ebfedfee     	bl	0x18c2c8 <_Z8IO_Clearv> @ imm = #-0x48048
  1d430c: eafffd81     	b	0x1d3918 <_Z9StartRoomib+0x38> @ imm = #-0x9fc
  1d4310: e1a00009     	mov	r0, r9
  1d4314: ebfbb1d8     	bl	0xc0a7c <_Z16FREE_RValue__PreP6RValue> @ imm = #-0x1138a0
  1d4318: eaffff8f     	b	0x1d415c <_Z9StartRoomib+0x87c> @ imm = #-0x1c4
  1d431c: e1a00009     	mov	r0, r9
  1d4320: e58d2010     	str	r2, [sp, #0x10]
  1d4324: ebfbb1d4     	bl	0xc0a7c <_Z16FREE_RValue__PreP6RValue> @ imm = #-0x1138b0
  1d4328: e59d2010     	ldr	r2, [sp, #0x10]
  1d432c: eaffff5c     	b	0x1d40a4 <_Z9StartRoomib+0x7c4> @ imm = #-0x290
  1d4330: e1a00009     	mov	r0, r9
  1d4334: ebfbb1d0     	bl	0xc0a7c <_Z16FREE_RValue__PreP6RValue> @ imm = #-0x1138c0
  1d4338: eaffff67     	b	0x1d40dc <_Z9StartRoomib+0x7fc> @ imm = #-0x264
  1d433c: e1a00009     	mov	r0, r9
  1d4340: e58d2010     	str	r2, [sp, #0x10]
  1d4344: ebfbb1cc     	bl	0xc0a7c <_Z16FREE_RValue__PreP6RValue> @ imm = #-0x1138d0
  1d4348: e59d2010     	ldr	r2, [sp, #0x10]
  1d434c: eaffff74     	b	0x1d4124 <_Z9StartRoomib+0x844> @ imm = #-0x230
  1d4350: e1b01106     	lsls	r1, r6, #2
  1d4354: 0affffe7     	beq	0x1d42f8 <_Z9StartRoomib+0xa18> @ imm = #-0x64
  1d4358: e59f20ec     	ldr	r2, [pc, #0xec]         @ 0x1d444c <_Z9StartRoomib+0xb6c>
  1d435c: e3a03000     	mov	r3, #0
  1d4360: e58d3000     	str	r3, [sp]
  1d4364: e3a03087     	mov	r3, #135
  1d4368: e08f2002     	add	r2, pc, r2
  1d436c: eb02a2da     	bl	0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> @ imm = #0xa8b68
  1d4370: e5840004     	str	r0, [r4, #0x4]
  1d4374: e1550006     	cmp	r5, r6
  1d4378: e5846000     	str	r6, [r4]
  1d437c: aa000008     	bge	0x1d43a4 <_Z9StartRoomib+0xac4> @ imm = #0x20
  1d4380: e1a03105     	lsl	r3, r5, #2
  1d4384: e3a01000     	mov	r1, #0
  1d4388: e5942004     	ldr	r2, [r4, #0x4]
  1d438c: e2855001     	add	r5, r5, #1
  1d4390: e7821003     	str	r1, [r2, r3]
  1d4394: e2833004     	add	r3, r3, #4
  1d4398: e5946000     	ldr	r6, [r4]
  1d439c: e1560005     	cmp	r6, r5
  1d43a0: cafffff8     	bgt	0x1d4388 <_Z9StartRoomib+0xaa8> @ imm = #-0x20
  1d43a4: e59f306c     	ldr	r3, [pc, #0x6c]         @ 0x1d4418 <_Z9StartRoomib+0xb38>
  1d43a8: e1570006     	cmp	r7, r6
  1d43ac: a3a00000     	movge	r0, #0
  1d43b0: e79b3003     	ldr	r3, [r11, r3]
  1d43b4: e5837000     	str	r7, [r3]
  1d43b8: aafffd61     	bge	0x1d3944 <_Z9StartRoomib+0x64> @ imm = #-0xa7c
  1d43bc: eafffd5e     	b	0x1d393c <_Z9StartRoomib+0x5c> @ imm = #-0xa88
  1d43c0: e1a00004     	mov	r0, r4
  1d43c4: eb029fc1     	bl	0x27c2d0 <_ZN13MemoryManager4FreeEPKv> @ imm = #0xa7f04
  1d43c8: e5874004     	str	r4, [r7, #0x4]
  1d43cc: eafffe3b     	b	0x1d3cc0 <_Z9StartRoomib+0x3e0> @ imm = #-0x714
  1d43d0: e1a00005     	mov	r0, r5
  1d43d4: ebfbb1a8     	bl	0xc0a7c <_Z16FREE_RValue__PreP6RValue> @ imm = #-0x113960
  1d43d8: eafffe78     	b	0x1d3dc0 <_Z9StartRoomib+0x4e0> @ imm = #-0x620
  1d43dc: e1a00005     	mov	r0, r5
  1d43e0: ebfbb1a5     	bl	0xc0a7c <_Z16FREE_RValue__PreP6RValue> @ imm = #-0x11396c
  1d43e4: eafffe63     	b	0x1d3d78 <_Z9StartRoomib+0x498> @ imm = #-0x674
  1d43e8: e79b7003     	ldr	r7, [r11, r3]
  1d43ec: eafffe22     	b	0x1d3c7c <_Z9StartRoomib+0x39c> @ imm = #-0x778
  1d43f0: e59f3020     	ldr	r3, [pc, #0x20]         @ 0x1d4418 <_Z9StartRoomib+0xb38>
  1d43f4: e3a00000     	mov	r0, #0
  1d43f8: e79b3003     	ldr	r3, [r11, r3]
  1d43fc: e5837000     	str	r7, [r3]
  1d4400: eafffd4f     	b	0x1d3944 <_Z9StartRoomib+0x64> @ imm = #-0xac4
  1d4404: e3a00000     	mov	r0, #0
  1d4408: ebfb889e     	bl	0xb6688 <exit@plt>      @ imm = #-0x11dd88
  1d440c: 0021e358     	eoreq	lr, r1, r8, asr r3
  1d4410: ffffc154     	<unknown>
  1d4414: ffffeed8     	<unknown>
  1d4418: ffffd784     	<unknown>
  1d441c: ffffbcd8     	<unknown>
  1d4420: ffffbff4     	<unknown>
  1d4424: 0017932c     	andseq	r9, r7, r12, lsr #6
  1d4428: ffffbcd4     	<unknown>
  1d442c: ffffeef4     	<unknown>
  1d4430: ffffeef8     	<unknown>
  1d4434: 00179244     	andseq	r9, r7, r4, asr #4
  1d4438: ffffbf68     	<unknown>
  1d443c: ffffef38     	<unknown>
  1d4440: ffffef3c     	<unknown>
  1d4444: ffffbf64     	<unknown>
  1d4448: ffffc024     	<unknown>
  1d444c: 00178f88     	andseq	r8, r7, r8, lsl #31
