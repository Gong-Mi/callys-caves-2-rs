
/data/data/com.termux/files/home/cally-oracle/libyoyo.so:	file format elf32-littlearm

Disassembly of section .text:

001994dc <_ZN9CInstanceC2Effiib>:
  1994dc: e92d4ff0     	push	{r4, r5, r6, r7, r8, r9, r10, r11, lr}
  1994e0: e1a0b001     	mov	r11, r1
  1994e4: e59f83d4     	ldr	r8, [pc, #0x3d4]        @ 0x1998c0 <_ZN9CInstanceC2Effiib+0x3e4>
  1994e8: e24dd00c     	sub	sp, sp, #12
  1994ec: e59f13d0     	ldr	r1, [pc, #0x3d0]        @ 0x1998c4 <_ZN9CInstanceC2Effiib+0x3e8>
  1994f0: e1a0a003     	mov	r10, r3
  1994f4: e08f8008     	add	r8, pc, r8
  1994f8: e5dd3034     	ldrb	r3, [sp, #0x34]
  1994fc: e1a09002     	mov	r9, r2
  199500: e3e024ff     	mvn	r2, #-16777216
  199504: e7981001     	ldr	r1, [r8, r1]
  199508: e1a06000     	mov	r6, r0
  19950c: e59f53b4     	ldr	r5, [pc, #0x3b4]        @ 0x1998c8 <_ZN9CInstanceC2Effiib+0x3ec>
  199510: e3e04000     	mvn	r4, #0
  199514: e3a0700c     	mov	r7, #12
  199518: e5911000     	ldr	r1, [r1]
  19951c: e58d3004     	str	r3, [sp, #0x4]
  199520: ebffe0d9     	bl	0x19188c <_ZN12YYObjectBaseC2Eii> @ imm = #-0x7c9c
  199524: e59f13a0     	ldr	r1, [pc, #0x3a0]        @ 0x1998cc <_ZN9CInstanceC2Effiib+0x3f0>
  199528: e3a0e000     	mov	lr, #0
  19952c: e2862f63     	add	r2, r6, #396
  199530: e7980001     	ldr	r0, [r8, r1]
  199534: e2861f66     	add	r1, r6, #408
  199538: e5864188     	str	r4, [r6, #0x188]
  19953c: e2864f69     	add	r4, r6, #420
  199540: e586218c     	str	r2, [r6, #0x18c]
  199544: e2800008     	add	r0, r0, #8
  199548: e5862190     	str	r2, [r6, #0x190]
  19954c: e1a02006     	mov	r2, r6
  199550: e5860000     	str	r0, [r6]
  199554: e1a0000e     	mov	r0, lr
  199558: e5861198     	str	r1, [r6, #0x198]
  19955c: e586119c     	str	r1, [r6, #0x19c]
  199560: e3a01000     	mov	r1, #0
  199564: e586e194     	str	lr, [r6, #0x194]
  199568: e586e1a0     	str	lr, [r6, #0x1a0]
  19956c: e586e1ac     	str	lr, [r6, #0x1ac]
  199570: e58641a4     	str	r4, [r6, #0x1a4]
  199574: e58641a8     	str	r4, [r6, #0x1a8]
  199578: e7984005     	ldr	r4, [r8, r5]
  19957c: e58610b4     	str	r1, [r6, #0xb4]
  199580: e586e078     	str	lr, [r6, #0x78]
  199584: e1c440d0     	ldrd	r4, r5, [r4]
  199588: e58610b8     	str	r1, [r6, #0xb8]
  19958c: e5c6e06b     	strb	lr, [r6, #0x6b]
  199590: e5861180     	str	r1, [r6, #0x180]
  199594: e5861184     	str	r1, [r6, #0x184]
  199598: e5c6e06c     	strb	lr, [r6, #0x6c]
  19959c: e5861090     	str	r1, [r6, #0x90]
  1995a0: e5c6e06a     	strb	lr, [r6, #0x6a]
  1995a4: e5861094     	str	r1, [r6, #0x94]
  1995a8: e586e0a8     	str	lr, [r6, #0xa8]
  1995ac: e5861098     	str	r1, [r6, #0x98]
  1995b0: e1c647f0     	strd	r4, r5, [r6, #112]
  1995b4: e586109c     	str	r1, [r6, #0x9c]
  1995b8: e58610a0     	str	r1, [r6, #0xa0]
  1995bc: e58610a4     	str	r1, [r6, #0xa4]
  1995c0: e58610bc     	str	r1, [r6, #0xbc]
  1995c4: e58610c0     	str	r1, [r6, #0xc0]
  1995c8: e58610c4     	str	r1, [r6, #0xc4]
  1995cc: e58610c8     	str	r1, [r6, #0xc8]
  1995d0: e59d3004     	ldr	r3, [sp, #0x4]
  1995d4: e58610cc     	str	r1, [r6, #0xcc]
  1995d8: e58610d0     	str	r1, [r6, #0xd0]
  1995dc: e58610e0     	str	r1, [r6, #0xe0]
  1995e0: e58610e4     	str	r1, [r6, #0xe4]
  1995e4: e58610d4     	str	r1, [r6, #0xd4]
  1995e8: e58610d8     	str	r1, [r6, #0xd8]
  1995ec: e58610dc     	str	r1, [r6, #0xdc]
  1995f0: e2577001     	subs	r7, r7, #1
  1995f4: e58200f8     	str	r0, [r2, #0xf8]
  1995f8: e2822004     	add	r2, r2, #4
  1995fc: 1afffffb     	bne	0x1995f0 <_ZN9CInstanceC2Effiib+0x114> @ imm = #-0x14
  199600: e3a04000     	mov	r4, #0
  199604: e1a02003     	mov	r2, r3
  199608: e59d1030     	ldr	r1, [sp, #0x30]
  19960c: e1a00006     	mov	r0, r6
  199610: e5c67068     	strb	r7, [r6, #0x68]
  199614: e5c67069     	strb	r7, [r6, #0x69]
  199618: e5867160     	str	r7, [r6, #0x160]
  19961c: e5867164     	str	r7, [r6, #0x164]
  199620: e586412c     	str	r4, [r6, #0x12c]
  199624: e5867128     	str	r7, [r6, #0x128]
  199628: e5864130     	str	r4, [r6, #0x130]
  19962c: e5867140     	str	r7, [r6, #0x140]
  199630: e5864134     	str	r4, [r6, #0x134]
  199634: e586714c     	str	r7, [r6, #0x14c]
  199638: e5864138     	str	r4, [r6, #0x138]
  19963c: e5c6715c     	strb	r7, [r6, #0x15c]
  199640: e586413c     	str	r4, [r6, #0x13c]
  199644: e5c6715d     	strb	r7, [r6, #0x15d]
  199648: e5864150     	str	r4, [r6, #0x150]
  19964c: e5867080     	str	r7, [r6, #0x80]
  199650: e5864154     	str	r4, [r6, #0x154]
  199654: e5867084     	str	r7, [r6, #0x84]
  199658: e5864158     	str	r4, [r6, #0x158]
  19965c: e5867088     	str	r7, [r6, #0x88]
  199660: ebffe6f9     	bl	0x19324c <_ZN9CInstance14SetObjectIndexEib> @ imm = #-0x641c
  199664: e1a03006     	mov	r3, r6
  199668: e3e01000     	mvn	r1, #0
  19966c: e3a025fe     	mov	r2, #1065353216
  199670: e3a00000     	mov	r0, #0
  199674: e5862094     	str	r2, [r6, #0x94]
  199678: e5862098     	str	r2, [r6, #0x98]
  19967c: e3440387     	movt	r0, #0x4387
  199680: e586209c     	str	r2, [r6, #0x9c]
  199684: e58620a4     	str	r2, [r6, #0xa4]
  199688: e3e024ff     	mvn	r2, #-16777216
  19968c: e5864090     	str	r4, [r6, #0x90]
  199690: e58640a0     	str	r4, [r6, #0xa0]
  199694: e58640cc     	str	r4, [r6, #0xcc]
  199698: e58640d0     	str	r4, [r6, #0xd0]
  19969c: e58640e0     	str	r4, [r6, #0xe0]
  1996a0: e58640e4     	str	r4, [r6, #0xe4]
  1996a4: e58640d4     	str	r4, [r6, #0xd4]
  1996a8: e58640dc     	str	r4, [r6, #0xdc]
  1996ac: e586b0b4     	str	r11, [r6, #0xb4]
  1996b0: e58690b8     	str	r9, [r6, #0xb8]
  1996b4: e586a078     	str	r10, [r6, #0x78]
  1996b8: e586b0bc     	str	r11, [r6, #0xbc]
  1996bc: e58690c0     	str	r9, [r6, #0xc0]
  1996c0: e586b0c4     	str	r11, [r6, #0xc4]
  1996c4: e58690c8     	str	r9, [r6, #0xc8]
  1996c8: e58620a8     	str	r2, [r6, #0xa8]
  1996cc: e58600d8     	str	r0, [r6, #0xd8]
  1996d0: e2877001     	add	r7, r7, #1
  1996d4: e58310f8     	str	r1, [r3, #0xf8]
  1996d8: e357000c     	cmp	r7, #12
  1996dc: e2833004     	add	r3, r3, #4
  1996e0: e3e02000     	mvn	r2, #0
  1996e4: 1afffff9     	bne	0x1996d0 <_ZN9CInstanceC2Effiib+0x1f4> @ imm = #-0x1c
  1996e8: e59f01e0     	ldr	r0, [pc, #0x1e0]        @ 0x1998d0 <_ZN9CInstanceC2Effiib+0x3f4>
  1996ec: e3a04000     	mov	r4, #0
  1996f0: e3a03000     	mov	r3, #0
  1996f4: e3a015fe     	mov	r1, #1065353216
  1996f8: e586312c     	str	r3, [r6, #0x12c]
  1996fc: e5863130     	str	r3, [r6, #0x130]
  199700: e5863134     	str	r3, [r6, #0x134]
  199704: e586313c     	str	r3, [r6, #0x13c]
  199708: e5863150     	str	r3, [r6, #0x150]
  19970c: e5863154     	str	r3, [r6, #0x154]
  199710: e3a03002     	mov	r3, #2
  199714: e5862128     	str	r2, [r6, #0x128]
  199718: e586214c     	str	r2, [r6, #0x14c]
  19971c: e5862170     	str	r2, [r6, #0x170]
  199720: e58640f4     	str	r4, [r6, #0xf4]
  199724: e58640e8     	str	r4, [r6, #0xe8]
  199728: e58640f0     	str	r4, [r6, #0xf0]
  19972c: e58640ec     	str	r4, [r6, #0xec]
  199730: e5c64068     	strb	r4, [r6, #0x68]
  199734: e5c64069     	strb	r4, [r6, #0x69]
  199738: e5861138     	str	r1, [r6, #0x138]
  19973c: e5861158     	str	r1, [r6, #0x158]
  199740: e5864140     	str	r4, [r6, #0x140]
  199744: e5864160     	str	r4, [r6, #0x160]
  199748: e5864164     	str	r4, [r6, #0x164]
  19974c: e5864168     	str	r4, [r6, #0x168]
  199750: e5c6415e     	strb	r4, [r6, #0x15e]
  199754: e5c64174     	strb	r4, [r6, #0x174]
  199758: e586316c     	str	r3, [r6, #0x16c]
  19975c: e7985000     	ldr	r5, [r8, r0]
  199760: e5957008     	ldr	r7, [r5, #0x8]
  199764: e595c004     	ldr	r12, [r5, #0x4]
  199768: e157000c     	cmp	r7, r12
  19976c: aa000042     	bge	0x19987c <_ZN9CInstanceC2Effiib+0x3a0> @ imm = #0x108
  199770: e35c0000     	cmp	r12, #0
  199774: e595300c     	ldr	r3, [r5, #0xc]
  199778: da000010     	ble	0x1997c0 <_ZN9CInstanceC2Effiib+0x2e4> @ imm = #0x40
  19977c: e5950000     	ldr	r0, [r5]
  199780: e1a0100c     	mov	r1, r12
  199784: ea000002     	b	0x199794 <_ZN9CInstanceC2Effiib+0x2b8> @ imm = #0x8
  199788: e2511001     	subs	r1, r1, #1
  19978c: e2833001     	add	r3, r3, #1
  199790: 0a00000a     	beq	0x1997c0 <_ZN9CInstanceC2Effiib+0x2e4> @ imm = #0x28
  199794: e15c0003     	cmp	r12, r3
  199798: e1a02103     	lsl	r2, r3, #2
  19979c: d3a03000     	movle	r3, #0
  1997a0: d1a02003     	movle	r2, r3
  1997a4: e0804002     	add	r4, r0, r2
  1997a8: e7902002     	ldr	r2, [r0, r2]
  1997ac: e3520000     	cmp	r2, #0
  1997b0: 1afffff4     	bne	0x199788 <_ZN9CInstanceC2Effiib+0x2ac> @ imm = #-0x30
  1997b4: e5846000     	str	r6, [r4]
  1997b8: e585300c     	str	r3, [r5, #0xc]
  1997bc: ea000000     	b	0x1997c4 <_ZN9CInstanceC2Effiib+0x2e8> @ imm = #0x0
  1997c0: e3e03000     	mvn	r3, #0
  1997c4: e59f2108     	ldr	r2, [pc, #0x108]        @ 0x1998d4 <_ZN9CInstanceC2Effiib+0x3f8>
  1997c8: e2877001     	add	r7, r7, #1
  1997cc: e5863044     	str	r3, [r6, #0x44]
  1997d0: e5857008     	str	r7, [r5, #0x8]
  1997d4: e7983002     	ldr	r3, [r8, r2]
  1997d8: e5d33000     	ldrb	r3, [r3]
  1997dc: e3530000     	cmp	r3, #0
  1997e0: 0a00001d     	beq	0x19985c <_ZN9CInstanceC2Effiib+0x380> @ imm = #0x74
  1997e4: e59f30ec     	ldr	r3, [pc, #0xec]         @ 0x1998d8 <_ZN9CInstanceC2Effiib+0x3fc>
  1997e8: e7987003     	ldr	r7, [r8, r3]
  1997ec: e5973000     	ldr	r3, [r7]
  1997f0: e3530000     	cmp	r3, #0
  1997f4: da000018     	ble	0x19985c <_ZN9CInstanceC2Effiib+0x380> @ imm = #0x60
  1997f8: e59f30dc     	ldr	r3, [pc, #0xdc]         @ 0x1998dc <_ZN9CInstanceC2Effiib+0x400>
  1997fc: e3a05000     	mov	r5, #0
  199800: e7984003     	ldr	r4, [r8, r3]
  199804: e2844008     	add	r4, r4, #8
  199808: ea000003     	b	0x19981c <_ZN9CInstanceC2Effiib+0x340> @ imm = #0xc
  19980c: e5973000     	ldr	r3, [r7]
  199810: e2844010     	add	r4, r4, #16
  199814: e1530005     	cmp	r3, r5
  199818: da00000f     	ble	0x19985c <_ZN9CInstanceC2Effiib+0x380> @ imm = #0x3c
  19981c: e5140008     	ldr	r0, [r4, #-0x8]
  199820: e2855001     	add	r5, r5, #1
  199824: eb029831     	bl	0x23f8f0 <_Z18isGlobalBuiltinVarPKc> @ imm = #0xa60c4
  199828: e3500000     	cmp	r0, #0
  19982c: 1afffff6     	bne	0x19980c <_ZN9CInstanceC2Effiib+0x330> @ imm = #-0x28
  199830: e8140003     	ldmda	r4, {r0, r1}
  199834: e2844010     	add	r4, r4, #16
  199838: eb0299db     	bl	0x23ffac <_Z23JS_SetupBuiltinPropertyPFbP9CInstanceiP6RValueES4_> @ imm = #0xa676c
  19983c: e5141018     	ldr	r1, [r4, #-0x18]
  199840: e3a03001     	mov	r3, #1
  199844: e1a02000     	mov	r2, r0
  199848: e1a00006     	mov	r0, r6
  19984c: ebffff06     	bl	0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> @ imm = #-0x3e8
  199850: e5973000     	ldr	r3, [r7]
  199854: e1530005     	cmp	r3, r5
  199858: caffffef     	bgt	0x19981c <_ZN9CInstanceC2Effiib+0x340> @ imm = #-0x44
  19985c: e3a03000     	mov	r3, #0
  199860: e3a02001     	mov	r2, #1
  199864: e1a00006     	mov	r0, r6
  199868: e5862048     	str	r2, [r6, #0x48]
  19986c: e5863010     	str	r3, [r6, #0x10]
  199870: e5863014     	str	r3, [r6, #0x14]
  199874: e28dd00c     	add	sp, sp, #12
  199878: e8bd8ff0     	pop	{r4, r5, r6, r7, r8, r9, r10, r11, pc}
  19987c: e08cc08c     	add	r12, r12, r12, lsl #1
  199880: e5950000     	ldr	r0, [r5]
  199884: e08ccfac     	add	r12, r12, r12, lsr #31
  199888: e1a070cc     	asr	r7, r12, #1
  19988c: e1a01107     	lsl	r1, r7, #2
  199890: ebfcd5b3     	bl	0xcef64 <_Z9YYReallocPvi> @ imm = #-0xca934
  199894: e5953004     	ldr	r3, [r5, #0x4]
  199898: e1a01004     	mov	r1, r4
  19989c: e0632007     	rsb	r2, r3, r7
  1998a0: e1a02102     	lsl	r2, r2, #2
  1998a4: e5850000     	str	r0, [r5]
  1998a8: e0800103     	add	r0, r0, r3, lsl #2
  1998ac: ebfc733f     	bl	0xb65b0 <memset@plt>    @ imm = #-0xe3304
  1998b0: e5857004     	str	r7, [r5, #0x4]
  1998b4: e1a0c007     	mov	r12, r7
  1998b8: e5957008     	ldr	r7, [r5, #0x8]
  1998bc: eaffffab     	b	0x199770 <_ZN9CInstanceC2Effiib+0x294> @ imm = #-0x154
  1998c0: 0025875c     	eoreq	r8, r5, r12, asr r7
  1998c4: ffffc0c4     	<unknown>
  1998c8: ffffdeb4     	<unknown>
  1998cc: ffffea3c     	<unknown>
  1998d0: ffffc014     	<unknown>
  1998d4: ffffbf68     	<unknown>
  1998d8: ffffbfe4     	<unknown>
  1998dc: ffffbfe8     	<unknown>
