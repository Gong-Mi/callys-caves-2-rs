/* libyoyo.so 覆盖卡组 0253
 * 函数 0x2a659a..0x2a6ad0，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2a659a · png_get_image_height · size=12 · insn=6 */
/* @0x2a659a cbz r0, 0x2a65a4 <png_get_image_height+0xa> */
/* @0x2a659c cbz r1, 0x2a65a2 <png_get_image_height+0x8> */
/* @0x2a659e ldr r0, [r1, #0x4] */
/* @0x2a65a0 bx lr */
/* @0x2a65a2 mov r0, r1 */
/* @0x2a65a4 bx lr */

/* ── FUNC 0x2a65a6 · png_get_bit_depth · size=12 · insn=6 */
/* @0x2a65a6 cbz r0, 0x2a65b0 <png_get_bit_depth+0xa> */
/* @0x2a65a8 cbz r1, 0x2a65ae <png_get_bit_depth+0x8> */
/* @0x2a65aa ldrb r0, [r1, #0x18] */
/* @0x2a65ac bx lr */
/* @0x2a65ae mov r0, r1 */
/* @0x2a65b0 bx lr */

/* ── FUNC 0x2a65b2 · png_get_color_type · size=12 · insn=6 */
/* @0x2a65b2 cbz r0, 0x2a65bc <png_get_color_type+0xa> */
/* @0x2a65b4 cbz r1, 0x2a65ba <png_get_color_type+0x8> */
/* @0x2a65b6 ldrb r0, [r1, #0x19] */
/* @0x2a65b8 bx lr */
/* @0x2a65ba mov r0, r1 */
/* @0x2a65bc bx lr */

/* ── FUNC 0x2a65be · png_get_filter_type · size=12 · insn=6 */
/* @0x2a65be cbz r0, 0x2a65c8 <png_get_filter_type+0xa> */
/* @0x2a65c0 cbz r1, 0x2a65c6 <png_get_filter_type+0x8> */
/* @0x2a65c2 ldrb r0, [r1, #0x1b] */
/* @0x2a65c4 bx lr */
/* @0x2a65c6 mov r0, r1 */
/* @0x2a65c8 bx lr */

/* ── FUNC 0x2a65ca · png_get_interlace_type · size=12 · insn=6 */
/* @0x2a65ca cbz r0, 0x2a65d4 <png_get_interlace_type+0xa> */
/* @0x2a65cc cbz r1, 0x2a65d2 <png_get_interlace_type+0x8> */
/* @0x2a65ce ldrb r0, [r1, #0x1c] */
/* @0x2a65d0 bx lr */
/* @0x2a65d2 mov r0, r1 */
/* @0x2a65d4 bx lr */

/* ── FUNC 0x2a65d6 · png_get_compression_type · size=12 · insn=6 */
/* @0x2a65d6 cbz r0, 0x2a65e0 <png_get_compression_type+0xa> */
/* @0x2a65d8 cbz r1, 0x2a65de <png_get_compression_type+0x8> */
/* @0x2a65da ldrb r0, [r1, #0x1a] */
/* @0x2a65dc bx lr */
/* @0x2a65de mov r0, r1 */
/* @0x2a65e0 bx lr */

/* ── FUNC 0x2a65e2 · png_get_x_pixels_per_meter · size=32 · insn=15 */
/* @0x2a65e2 cbz r0, 0x2a6600 <png_get_x_pixels_per_meter+0x1e> */
/* @0x2a65e4 cbz r1, 0x2a65fa <png_get_x_pixels_per_meter+0x18> */
/* @0x2a65e6 ldr r0, [r1, #0x8] */
/* @0x2a65e8 ands r0, r0, #0x80 */
/* @0x2a65ea andle r0, r8, r0, lsl #1 */
/* @0x2a65ec beq 0x2a6600 <png_get_x_pixels_per_meter+0x1e> */
/* @0x2a65ee ldrb.w r3, [r1, #0x78] */
/* @0x2a65f2 cmp r3, #0x1 */
/* @0x2a65f4 bne 0x2a65fe <png_get_x_pixels_per_meter+0x1c> */
/* @0x2a65f6 ldr r0, [r1, #0x70] */
/* @0x2a65f8 bx lr */
/* @0x2a65fa mov r0, r1 */
/* @0x2a65fc bx lr */
/* @0x2a65fe movs r0, #0x0 */
/* @0x2a6600 bx lr */

/* ── FUNC 0x2a6602 · png_get_y_pixels_per_meter · size=32 · insn=15 */
/* @0x2a6602 cbz r0, 0x2a6620 <png_get_y_pixels_per_meter+0x1e> */
/* @0x2a6604 cbz r1, 0x2a661a <png_get_y_pixels_per_meter+0x18> */
/* @0x2a6606 ldr r0, [r1, #0x8] */
/* @0x2a6608 ands r0, r0, #0x80 */
/* @0x2a660a andle r0, r8, r0, lsl #1 */
/* @0x2a660c beq 0x2a6620 <png_get_y_pixels_per_meter+0x1e> */
/* @0x2a660e ldrb.w r3, [r1, #0x78] */
/* @0x2a6612 cmp r3, #0x1 */
/* @0x2a6614 bne 0x2a661e <png_get_y_pixels_per_meter+0x1c> */
/* @0x2a6616 ldr r0, [r1, #0x74] */
/* @0x2a6618 bx lr */
/* @0x2a661a mov r0, r1 */
/* @0x2a661c bx lr */
/* @0x2a661e movs r0, #0x0 */
/* @0x2a6620 bx lr */

/* ── FUNC 0x2a6622 · png_get_pixels_per_meter · size=40 · insn=19 */
/* @0x2a6622 cbz r0, 0x2a6648 <png_get_pixels_per_meter+0x26> */
/* @0x2a6624 cbz r1, 0x2a6642 <png_get_pixels_per_meter+0x20> */
/* @0x2a6626 ldr r0, [r1, #0x8] */
/* @0x2a6628 ands r0, r0, #0x80 */
/* @0x2a662a andle r0, r12, r0, lsl #1 */
/* @0x2a662c beq 0x2a6648 <png_get_pixels_per_meter+0x26> */
/* @0x2a662e ldrb.w r3, [r1, #0x78] */
/* @0x2a6632 cmp r3, #0x1 */
/* @0x2a6634 bne 0x2a6646 <png_get_pixels_per_meter+0x24> */
/* @0x2a6636 ldr r3, [r1, #0x70] */
/* @0x2a6638 ldr r0, [r1, #0x74] */
/* @0x2a663a cmp r3, r0 */
/* @0x2a663c it ne */
/* @0x2a663e movne r0, #0x0 */
/* @0x2a6640 bx lr */
/* @0x2a6642 mov r0, r1 */
/* @0x2a6644 bx lr */
/* @0x2a6646 movs r0, #0x0 */
/* @0x2a6648 bx lr */

/* ── FUNC 0x2a664a · anon_2a664a · size=0 · insn=1 */
/* @0x2a664a orrlt r0, r0, r0 */

/* ── FUNC 0x2a664c · png_get_pixel_aspect_ratio · size=52 · insn=24 */
/* @0x2a664c cbz r0, 0x2a6670 <png_get_pixel_aspect_ratio+0x24> */
/* @0x2a664e cbz r1, 0x2a6670 <png_get_pixel_aspect_ratio+0x24> */
/* @0x2a6650 ldr r3, [r1, #0x8] */
/* @0x2a6652 lsls r3, r3, #0x18 */
/* @0x2a6654 bpl 0x2a6670 <png_get_pixel_aspect_ratio+0x24> */
/* @0x2a6656 ldr r3, [r1, #0x70] */
/* @0x2a6658 cbz r3, 0x2a6670 <png_get_pixel_aspect_ratio+0x24> */
/* @0x2a665a vmov s13, r3 */
/* @0x2a665c vldr s7, [r1, #576] */
/* @0x2a665e vldr s15, [r1, #116] */
/* @0x2a6660 vmrs r7, fpexc */
/* @0x2a6662 vcvt.f32.u32 s15, s15 */
/* @0x2a6664 vcvt.f32.u32 s14, s15 */
/* @0x2a6666 vcvt.f32.u32 s14, s13 */
/* @0x2a6668 .word 0xeec77a66 */
/* @0x2a666a vdiv.f32 s15, s15, s14 */
/* @0x2a666c and r7, r1, r7, lsl #21 */
/* @0x2a666e b 0x2a6674 <png_get_pixel_aspect_ratio+0x28> */
/* @0x2a6670 vldr s15, [pc, #8] */
/* @0x2a6674 vmov r0, s15 */
/* @0x2a6678 bx lr */
/* @0x2a667a nop */
/* @0x2a667c movs r0, r0 */
/* @0x2a667e movs r0, r0 */

/* ── FUNC 0x2a6680 · png_get_x_offset_microns · size=32 · insn=15 */
/* @0x2a6680 cbz r0, 0x2a669e <png_get_x_offset_microns+0x1e> */
/* @0x2a6682 cbz r1, 0x2a6698 <png_get_x_offset_microns+0x18> */
/* @0x2a6684 ldr r0, [r1, #0x8] */
/* @0x2a6686 ands r0, r0, #0x100 */
/* @0x2a6688 andle r7, r8, r0, lsl #1 */
/* @0x2a668a beq 0x2a669e <png_get_x_offset_microns+0x1e> */
/* @0x2a668c ldrb.w r3, [r1, #0x6c] */
/* @0x2a6690 cmp r3, #0x1 */
/* @0x2a6692 bne 0x2a669c <png_get_x_offset_microns+0x1c> */
/* @0x2a6694 ldr r0, [r1, #0x64] */
/* @0x2a6696 bx lr */
/* @0x2a6698 mov r0, r1 */
/* @0x2a669a bx lr */
/* @0x2a669c movs r0, #0x0 */
/* @0x2a669e bx lr */

/* ── FUNC 0x2a66a0 · png_get_y_offset_microns · size=32 · insn=15 */
/* @0x2a66a0 cbz r0, 0x2a66be <png_get_y_offset_microns+0x1e> */
/* @0x2a66a2 cbz r1, 0x2a66b8 <png_get_y_offset_microns+0x18> */
/* @0x2a66a4 ldr r0, [r1, #0x8] */
/* @0x2a66a6 ands r0, r0, #0x100 */
/* @0x2a66a8 andle r7, r8, r0, lsl #1 */
/* @0x2a66aa beq 0x2a66be <png_get_y_offset_microns+0x1e> */
/* @0x2a66ac ldrb.w r3, [r1, #0x6c] */
/* @0x2a66b0 cmp r3, #0x1 */
/* @0x2a66b2 bne 0x2a66bc <png_get_y_offset_microns+0x1c> */
/* @0x2a66b4 ldr r0, [r1, #0x68] */
/* @0x2a66b6 bx lr */
/* @0x2a66b8 mov r0, r1 */
/* @0x2a66ba bx lr */
/* @0x2a66bc movs r0, #0x0 */
/* @0x2a66be bx lr */

/* ── FUNC 0x2a66c0 · png_get_x_offset_pixels · size=30 · insn=14 */
/* @0x2a66c0 cbz r0, 0x2a66dc <png_get_x_offset_pixels+0x1c> */
/* @0x2a66c2 cbz r1, 0x2a66d6 <png_get_x_offset_pixels+0x16> */
/* @0x2a66c4 ldr r0, [r1, #0x8] */
/* @0x2a66c6 ands r0, r0, #0x100 */
/* @0x2a66c8 andle r7, r7, r0, lsl #1 */
/* @0x2a66ca beq 0x2a66dc <png_get_x_offset_pixels+0x1c> */
/* @0x2a66cc ldrb.w r3, [r1, #0x6c] */
/* @0x2a66d0 cbnz r3, 0x2a66da <png_get_x_offset_pixels+0x1a> */
/* @0x2a66d2 ldr r0, [r1, #0x64] */
/* @0x2a66d4 bx lr */
/* @0x2a66d6 mov r0, r1 */
/* @0x2a66d8 bx lr */
/* @0x2a66da movs r0, #0x0 */
/* @0x2a66dc bx lr */

/* ── FUNC 0x2a66de · png_get_y_offset_pixels · size=30 · insn=14 */
/* @0x2a66de cbz r0, 0x2a66fa <png_get_y_offset_pixels+0x1c> */
/* @0x2a66e0 cbz r1, 0x2a66f4 <png_get_y_offset_pixels+0x16> */
/* @0x2a66e2 ldr r0, [r1, #0x8] */
/* @0x2a66e4 ands r0, r0, #0x100 */
/* @0x2a66e6 andle r7, r7, r0, lsl #1 */
/* @0x2a66e8 beq 0x2a66fa <png_get_y_offset_pixels+0x1c> */
/* @0x2a66ea ldrb.w r3, [r1, #0x6c] */
/* @0x2a66ee cbnz r3, 0x2a66f8 <png_get_y_offset_pixels+0x1a> */
/* @0x2a66f0 ldr r0, [r1, #0x68] */
/* @0x2a66f2 bx lr */
/* @0x2a66f4 mov r0, r1 */
/* @0x2a66f6 bx lr */
/* @0x2a66f8 movs r0, #0x0 */
/* @0x2a66fa bx lr */

/* ── FUNC 0x2a66fc · png_get_channels · size=12 · insn=6 */
/* @0x2a66fc cbz r0, 0x2a6706 <png_get_channels+0xa> */
/* @0x2a66fe cbz r1, 0x2a6704 <png_get_channels+0x8> */
/* @0x2a6700 ldrb r0, [r1, #0x1d] */
/* @0x2a6702 bx lr */
/* @0x2a6704 mov r0, r1 */
/* @0x2a6706 bx lr */

/* ── FUNC 0x2a6708 · png_get_signature · size=14 · insn=6 */
/* @0x2a6708 cbz r0, 0x2a6714 <png_get_signature+0xc> */
/* @0x2a670a cbz r1, 0x2a6712 <png_get_signature+0xa> */
/* @0x2a670c add.w r0, r1, #0x20 */
/* @0x2a6710 bx lr */
/* @0x2a6712 mov r0, r1 */
/* @0x2a6714 bx lr */

/* ── FUNC 0x2a6716 · png_get_bKGD · size=30 · insn=15 */
/* @0x2a6716 cbz r0, 0x2a6732 <png_get_bKGD+0x1c> */
/* @0x2a6718 cbz r1, 0x2a672c <png_get_bKGD+0x16> */
/* @0x2a671a ldr r0, [r1, #0x8] */
/* @0x2a671c ands r0, r0, #0x20 */
/* @0x2a671e andle r0, r7, r0, lsr #32 */
/* @0x2a6720 beq 0x2a6732 <png_get_bKGD+0x1c> */
/* @0x2a6722 cbz r2, 0x2a6730 <png_get_bKGD+0x1a> */
/* @0x2a6724 adds r1, #0x5a */
/* @0x2a6726 movs r0, #0x20 */
/* @0x2a6728 str r1, [r2] */
/* @0x2a672a bx lr */
/* @0x2a672c mov r0, r1 */
/* @0x2a672e bx lr */
/* @0x2a6730 mov r0, r2 */
/* @0x2a6732 bx lr */

/* ── FUNC 0x2a6734 · png_get_cHRM · size=170 · insn=70 */
/* @0x2a6734 push.w {r4, r5, r6, r7, r8, lr} */
/* @0x2a6738 mov r8, r3 */
/* @0x2a673a ldr.w r12, [sp, #0x18] */
/* @0x2a673c blls 0x4967a4 <g_prim_v+0x6798> */
/* @0x2a673e ldr r3, [sp, #0x1c] */
/* @0x2a6740 ldr r7, [sp, #0x20] */
/* @0x2a6742 ldr r6, [sp, #0x24] */
/* @0x2a6744 ldr r5, [sp, #0x28] */
/* @0x2a6746 ldr r4, [sp, #0x2c] */
/* @0x2a6748 cmp r0, #0x0 */
/* @0x2a674a beq 0x2a67da <png_get_cHRM+0xa6> */
/* @0x2a674c cmp r1, #0x0 */
/* @0x2a674e beq 0x2a67d2 <png_get_cHRM+0x9e> */
/* @0x2a6750 ldr r0, [r1, #0x8] */
/* @0x2a6752 ands r0, r0, #0x4 */
/* @0x2a6754 suble r0, r0, r4 */
/* @0x2a6756 beq 0x2a67da <png_get_cHRM+0xa6> */
/* @0x2a6758 cbz r2, 0x2a6766 <png_get_cHRM+0x32> */
/* @0x2a675a vldr s14, [r1, #128] */
/* @0x2a675c .word 0xeeb77a20 */
/* @0x2a675e vcvt.f64.f32 d7, s14 */
/* @0x2a6760 vstr s14, [r2, #796] */
/* @0x2a6762 vstr d7, [r2] */
/* @0x2a6764 .word 0xf1b87b00 */
/* @0x2a6766 cmp.w r8, #0x0 */
/* @0x2a6768 andle r0, r5, r0, lsl #30 */
/* @0x2a676a beq 0x2a6778 <png_get_cHRM+0x44> */
/* @0x2a676c vldr s14, [r1, #132] */
/* @0x2a6770 vcvt.f64.f32 d7, s14 */
/* @0x2a6774 vstr d7, [r8] */
/* @0x2a6778 cmp.w r12, #0x0 */
/* @0x2a677c beq 0x2a678a <png_get_cHRM+0x56> */
/* @0x2a677e vldr s14, [r1, #136] */
/* @0x2a6780 .word 0xeeb77a22 */
/* @0x2a6782 vcvt.f64.f32 d7, s14 */
/* @0x2a6784 vstr s14, [r12, #796] */
/* @0x2a6786 vstr d7, [r12] */
/* @0x2a6788 .word 0xb12b7b00 */
/* @0x2a678a cbz r3, 0x2a6798 <png_get_cHRM+0x64> */
/* @0x2a678c vldr s14, [r1, #140] */
/* @0x2a6790 vcvt.f64.f32 d7, s14 */
/* @0x2a6794 vstr d7, [r3] */
/* @0x2a6798 cbz r7, 0x2a67a6 <png_get_cHRM+0x72> */
/* @0x2a679a vldr s14, [r1, #144] */
/* @0x2a679c .word 0xeeb77a24 */
/* @0x2a679e vcvt.f64.f32 d7, s14 */
/* @0x2a67a0 vstr s14, [r7, #796] */
/* @0x2a67a2 vstr d7, [r7] */
/* @0x2a67a4 .word 0xb12e7b00 */
/* @0x2a67a6 cbz r6, 0x2a67b4 <png_get_cHRM+0x80> */
/* @0x2a67a8 vldr s14, [r1, #148] */
/* @0x2a67ac vcvt.f64.f32 d7, s14 */
/* @0x2a67b0 vstr d7, [r6] */
/* @0x2a67b4 cbz r5, 0x2a67c2 <png_get_cHRM+0x8e> */
/* @0x2a67b6 vldr s14, [r1, #152] */
/* @0x2a67b8 .word 0xeeb77a26 */
/* @0x2a67ba vcvt.f64.f32 d7, s14 */
/* @0x2a67bc vstr s14, [r5, #796] */
/* @0x2a67be vstr d7, [r5] */
/* @0x2a67c0 .word 0xb14c7b00 */
/* @0x2a67c2 cbz r4, 0x2a67d8 <png_get_cHRM+0xa4> */
/* @0x2a67c4 vldr s14, [r1, #156] */
/* @0x2a67c8 vcvt.f64.f32 d7, s14 */
/* @0x2a67cc vstr d7, [r4] */
/* @0x2a67d0 b 0x2a67d8 <png_get_cHRM+0xa4> */
/* @0x2a67d2 mov r0, r1 */
/* @0x2a67d4 pop.w {r4, r5, r6, r7, r8, pc} */
/* @0x2a67d8 movs r0, #0x4 */
/* @0x2a67da pop.w {r4, r5, r6, r7, r8, pc} */
/* @0x2a67dc push {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x2a67de · png_get_cHRM_fixed · size=122 · insn=56 */
/* @0x2a67de push.w {r4, r5, r6, r7, r8, lr} */
/* @0x2a67e2 mov r8, r3 */
/* @0x2a67e4 ldr.w r12, [sp, #0x18] */
/* @0x2a67e6 blls 0x49684e <g_prim_v+0x6842> */
/* @0x2a67e8 ldr r3, [sp, #0x1c] */
/* @0x2a67ea ldr r7, [sp, #0x20] */
/* @0x2a67ec ldr r6, [sp, #0x24] */
/* @0x2a67ee ldr r5, [sp, #0x28] */
/* @0x2a67f0 ldr r4, [sp, #0x2c] */
/* @0x2a67f2 cbz r0, 0x2a6854 <png_get_cHRM_fixed+0x76> */
/* @0x2a67f4 cbz r1, 0x2a684c <png_get_cHRM_fixed+0x6e> */
/* @0x2a67f6 ldr r0, [r1, #0x8] */
/* @0x2a67f8 ands r0, r0, #0x4 */
/* @0x2a67fa eorle r0, r10, r4 */
/* @0x2a67fc beq 0x2a6854 <png_get_cHRM_fixed+0x76> */
/* @0x2a67fe cbz r2, 0x2a6806 <png_get_cHRM_fixed+0x28> */
/* @0x2a6800 ldr.w r0, [r1, #0x100] */
/* @0x2a6802 andsvs r0, r0, r0, lsl #2 */
/* @0x2a6804 str r0, [r2] */
/* @0x2a6806 cmp.w r8, #0x0 */
/* @0x2a680a beq 0x2a6814 <png_get_cHRM_fixed+0x36> */
/* @0x2a680c ldr.w r2, [r1, #0x104] */
/* @0x2a680e .word 0xf8c82104 */
/* @0x2a6810 str.w r2, [r8] */
/* @0x2a6812 .word 0xf1bc2000 */
/* @0x2a6814 cmp.w r12, #0x0 */
/* @0x2a6816 andle r0, r3, r0, lsl #30 */
/* @0x2a6818 beq 0x2a6822 <png_get_cHRM_fixed+0x44> */
/* @0x2a681a ldr.w r2, [r1, #0x108] */
/* @0x2a681e str.w r2, [r12] */
/* @0x2a6822 cbz r3, 0x2a682a <png_get_cHRM_fixed+0x4c> */
/* @0x2a6824 ldr.w r2, [r1, #0x10c] */
/* @0x2a6826 andsvs r2, r10, r12, lsl #2 */
/* @0x2a6828 str r2, [r3] */
/* @0x2a682a cbz r7, 0x2a6832 <png_get_cHRM_fixed+0x54> */
/* @0x2a682c ldr.w r3, [r1, #0x110] */
/* @0x2a682e eorsvs r3, r11, r0, lsl r1 */
/* @0x2a6830 str r3, [r7] */
/* @0x2a6832 cbz r6, 0x2a683a <png_get_cHRM_fixed+0x5c> */
/* @0x2a6834 ldr.w r3, [r1, #0x114] */
/* @0x2a6836 eorsvs r3, r3, r4, lsl r1 */
/* @0x2a6838 str r3, [r6] */
/* @0x2a683a cbz r5, 0x2a6842 <png_get_cHRM_fixed+0x64> */
/* @0x2a683c ldr.w r3, [r1, #0x118] */
/* @0x2a683e eorvs r3, r11, r8, lsl r1 */
/* @0x2a6840 str r3, [r5] */
/* @0x2a6842 cbz r4, 0x2a6852 <png_get_cHRM_fixed+0x74> */
/* @0x2a6844 ldr.w r3, [r1, #0x11c] */
/* @0x2a6846 eorvs r3, r3, r12, lsl r1 */
/* @0x2a6848 str r3, [r4] */
/* @0x2a684a b 0x2a6852 <png_get_cHRM_fixed+0x74> */
/* @0x2a684c mov r0, r1 */
/* @0x2a684e pop.w {r4, r5, r6, r7, r8, pc} */
/* @0x2a6852 movs r0, #0x4 */
/* @0x2a6854 pop.w {r4, r5, r6, r7, r8, pc} */
/* @0x2a6856 strdlt r8, r9, [r0, r0] */

/* ── FUNC 0x2a6858 · png_get_gAMA · size=38 · insn=18 */
/* @0x2a6858 cbz r0, 0x2a687c <png_get_gAMA+0x24> */
/* @0x2a685a cbz r1, 0x2a6876 <png_get_gAMA+0x1e> */
/* @0x2a685c ldr r0, [r1, #0x8] */
/* @0x2a685e ands r0, r0, #0x1 */
/* @0x2a6860 andle r0, r11, r1 */
/* @0x2a6862 beq 0x2a687c <png_get_gAMA+0x24> */
/* @0x2a6864 cbz r2, 0x2a687a <png_get_gAMA+0x22> */
/* @0x2a6866 vldr s14, [r1, #40] */
/* @0x2a6868 vmov.f32 s14, #1.625000e+00 */
/* @0x2a686a vcvt.f64.f32 d7, s14 */
/* @0x2a686c andhs r7, r1, r7, asr #21 */
/* @0x2a686e movs r0, #0x1 */
/* @0x2a6870 vstr d7, [r2] */
/* @0x2a6874 bx lr */
/* @0x2a6876 mov r0, r1 */
/* @0x2a6878 bx lr */
/* @0x2a687a mov r0, r2 */
/* @0x2a687c bx lr */

/* ── FUNC 0x2a687e · png_get_gAMA_fixed · size=32 · insn=16 */
/* @0x2a687e cbz r0, 0x2a689c <png_get_gAMA_fixed+0x1e> */
/* @0x2a6880 cbz r1, 0x2a6896 <png_get_gAMA_fixed+0x18> */
/* @0x2a6882 ldr r0, [r1, #0x8] */
/* @0x2a6884 ands r0, r0, #0x1 */
/* @0x2a6886 andle r0, r8, r1 */
/* @0x2a6888 beq 0x2a689c <png_get_gAMA_fixed+0x1e> */
/* @0x2a688a cbz r2, 0x2a689a <png_get_gAMA_fixed+0x1c> */
/* @0x2a688c ldr.w r3, [r1, #0xfc] */
/* @0x2a688e strdhs r3, r4, [r1], -r12 */
/* @0x2a6890 movs r0, #0x1 */
/* @0x2a6892 str r3, [r2] */
/* @0x2a6894 bx lr */
/* @0x2a6896 mov r0, r1 */
/* @0x2a6898 bx lr */
/* @0x2a689a mov r0, r2 */
/* @0x2a689c bx lr */

/* ── FUNC 0x2a689e · png_get_sRGB · size=34 · insn=17 */
/* @0x2a689e cbz r0, 0x2a68be <png_get_sRGB+0x20> */
/* @0x2a68a0 cbz r1, 0x2a68b8 <png_get_sRGB+0x1a> */
/* @0x2a68a2 ldr r0, [r1, #0x8] */
/* @0x2a68a4 ands r0, r0, #0x800 */
/* @0x2a68a6 andle r6, r9, r0 */
/* @0x2a68a8 beq 0x2a68be <png_get_sRGB+0x20> */
/* @0x2a68aa cbz r2, 0x2a68bc <png_get_sRGB+0x1e> */
/* @0x2a68ac ldrb.w r3, [r1, #0x2c] */
/* @0x2a68ae vst4.8 {d19, d20, d21, d22}, [pc:128], r12 */
/* @0x2a68b0 mov.w r0, #0x800 */
/* @0x2a68b2 andsvs r6, r3, r0 */
/* @0x2a68b4 str r3, [r2] */
/* @0x2a68b6 bx lr */
/* @0x2a68b8 mov r0, r1 */
/* @0x2a68ba bx lr */
/* @0x2a68bc mov r0, r2 */
/* @0x2a68be bx lr */

/* ── FUNC 0x2a68c0 · png_get_iCCP · size=70 · insn=32 */
/* @0x2a68c0 push {r4, r5, lr} */
/* @0x2a68c2 ldr r5, [sp, #0xc] */
/* @0x2a68c4 ldr r4, [sp, #0x10] */
/* @0x2a68c6 cbz r0, 0x2a6904 <png_get_iCCP+0x44> */
/* @0x2a68c8 cbz r1, 0x2a68f6 <png_get_iCCP+0x36> */
/* @0x2a68ca ldr r0, [r1, #0x8] */
/* @0x2a68cc ands r0, r0, #0x1000 */
/* @0x2a68d0 beq 0x2a6904 <png_get_iCCP+0x44> */
/* @0x2a68d2 cbz r2, 0x2a68fa <png_get_iCCP+0x3a> */
/* @0x2a68d4 cbz r5, 0x2a68fe <png_get_iCCP+0x3e> */
/* @0x2a68d6 cbz r4, 0x2a6902 <png_get_iCCP+0x42> */
/* @0x2a68d8 ldr.w r0, [r1, #0xc4] */
/* @0x2a68dc str r0, [r2] */
/* @0x2a68de mov.w r0, #0x1000 */
/* @0x2a68e0 .word 0xf8d15080 */
/* @0x2a68e2 ldr.w r2, [r1, #0xc8] */
/* @0x2a68e4 eorvs r2, r10, r8, asr #1 */
/* @0x2a68e6 str r2, [r5] */
/* @0x2a68e8 ldr.w r2, [r1, #0xcc] */
/* @0x2a68ec str r2, [r4] */
/* @0x2a68ee ldrb.w r2, [r1, #0xd0] */
/* @0x2a68f0 ldrsbvs r2, [r10], -r0 */
/* @0x2a68f2 str r2, [r3] */
/* @0x2a68f4 pop {r4, r5, pc} */
/* @0x2a68f6 mov r0, r1 */
/* @0x2a68f8 pop {r4, r5, pc} */
/* @0x2a68fa mov r0, r2 */
/* @0x2a68fc pop {r4, r5, pc} */
/* @0x2a68fe mov r0, r5 */
/* @0x2a6900 pop {r4, r5, pc} */
/* @0x2a6902 mov r0, r4 */
/* @0x2a6904 pop {r4, r5, pc} */

/* ── FUNC 0x2a6906 · png_get_sPLT · size=26 · insn=12 */
/* @0x2a6906 cbz r0, 0x2a691e <png_get_sPLT+0x18> */
/* @0x2a6908 cbz r1, 0x2a6918 <png_get_sPLT+0x12> */
/* @0x2a690a cbz r2, 0x2a691c <png_get_sPLT+0x16> */
/* @0x2a690c ldr.w r3, [r1, #0xd4] */
/* @0x2a690e ldrsbvs r3, [r3], -r4 */
/* @0x2a6910 str r3, [r2] */
/* @0x2a6912 ldr.w r0, [r1, #0xd8] */
/* @0x2a6916 bx lr */
/* @0x2a6918 mov r0, r1 */
/* @0x2a691a bx lr */
/* @0x2a691c mov r0, r2 */
/* @0x2a691e bx lr */

/* ── FUNC 0x2a6920 · png_get_hIST · size=30 · insn=15 */
/* @0x2a6920 cbz r0, 0x2a693c <png_get_hIST+0x1c> */
/* @0x2a6922 cbz r1, 0x2a6936 <png_get_hIST+0x16> */
/* @0x2a6924 ldr r0, [r1, #0x8] */
/* @0x2a6926 ands r0, r0, #0x40 */
/* @0x2a6928 andle r0, r7, r0, asr #32 */
/* @0x2a692a beq 0x2a693c <png_get_hIST+0x1c> */
/* @0x2a692c cbz r2, 0x2a693a <png_get_hIST+0x1a> */
/* @0x2a692e ldr r3, [r1, #0x7c] */
/* @0x2a6930 movs r0, #0x40 */
/* @0x2a6932 str r3, [r2] */
/* @0x2a6934 bx lr */
/* @0x2a6936 mov r0, r1 */
/* @0x2a6938 bx lr */
/* @0x2a693a mov r0, r2 */
/* @0x2a693c bx lr */

/* ── FUNC 0x2a693e · png_get_IHDR · size=144 · insn=66 */
/* @0x2a693e push.w {r0, r1, r2, r3, r4, r5, r6, r7, r8, lr} */
/* @0x2a6942 mov r4, r1 */
/* @0x2a6944 ldr r5, [sp, #0x28] */
/* @0x2a6946 ldr r1, [sp, #0x2c] */
/* @0x2a6948 ldr.w r12, [sp, #0x30] */
/* @0x2a694a .word 0xf8ddc030 */
/* @0x2a694c ldr.w r8, [sp, #0x34] */
/* @0x2a694e svcls #0xe8034 */
/* @0x2a6950 ldr r7, [sp, #0x38] */
/* @0x2a6952 cmp r0, #0x0 */
/* @0x2a6954 beq 0x2a69c8 <png_get_IHDR+0x8a> */
/* @0x2a6956 cmp r4, #0x0 */
/* @0x2a6958 beq 0x2a69b6 <png_get_IHDR+0x78> */
/* @0x2a695a cmp r2, #0x0 */
/* @0x2a695c beq 0x2a69ba <png_get_IHDR+0x7c> */
/* @0x2a695e cmp r3, #0x0 */
/* @0x2a6960 beq 0x2a69be <png_get_IHDR+0x80> */
/* @0x2a6962 cmp r5, #0x0 */
/* @0x2a6964 beq 0x2a69c2 <png_get_IHDR+0x84> */
/* @0x2a6966 cmp r1, #0x0 */
/* @0x2a6968 beq 0x2a69c6 <png_get_IHDR+0x88> */
/* @0x2a696a ldr r6, [r4] */
/* @0x2a696c str r6, [r2] */
/* @0x2a696e ldr r2, [r4, #0x4] */
/* @0x2a6970 str r2, [r3] */
/* @0x2a6972 ldrb r3, [r4, #0x18] */
/* @0x2a6974 str r3, [r5] */
/* @0x2a6976 ldrb r3, [r4, #0x19] */
/* @0x2a6978 str r3, [r1] */
/* @0x2a697a cmp.w r8, #0x0 */
/* @0x2a697e beq 0x2a6986 <png_get_IHDR+0x48> */
/* @0x2a6980 ldrb r3, [r4, #0x1a] */
/* @0x2a6982 str.w r3, [r8] */
/* @0x2a6986 cbz r7, 0x2a698c <png_get_IHDR+0x4e> */
/* @0x2a6988 ldrb r3, [r4, #0x1b] */
/* @0x2a698a str r3, [r7] */
/* @0x2a698c cmp.w r12, #0x0 */
/* @0x2a698e andle r0, r2, r0, lsl #30 */
/* @0x2a6990 beq 0x2a6998 <png_get_IHDR+0x5a> */
/* @0x2a6992 ldrb r3, [r4, #0x1c] */
/* @0x2a6994 str.w r3, [r12] */
/* @0x2a6996 cdpvc p0, #0x6, c3, c2, c0, #0x0 */
/* @0x2a6998 ldrb r2, [r4, #0x19] */
/* @0x2a699a ldrb r3, [r4, #0x18] */
/* @0x2a699c str r2, [sp] */
/* @0x2a699e ldrb r2, [r4, #0x1c] */
/* @0x2a69a0 str r2, [sp, #0x4] */
/* @0x2a69a2 ldrb r2, [r4, #0x1a] */
/* @0x2a69a4 str r2, [sp, #0x8] */
/* @0x2a69a6 ldrb r2, [r4, #0x1b] */
/* @0x2a69a8 str r2, [sp, #0xc] */
/* @0x2a69aa ldm.w r4, {r1, r2} */
/* @0x2a69ae bl 0x2a61b0 <png_check_IHDR> */
/* @0x2a69b2 movs r0, #0x1 */
/* @0x2a69b4 b 0x2a69c8 <png_get_IHDR+0x8a> */
/* @0x2a69b6 mov r0, r4 */
/* @0x2a69b8 b 0x2a69c8 <png_get_IHDR+0x8a> */
/* @0x2a69ba mov r0, r2 */
/* @0x2a69bc b 0x2a69c8 <png_get_IHDR+0x8a> */
/* @0x2a69be mov r0, r3 */
/* @0x2a69c0 b 0x2a69c8 <png_get_IHDR+0x8a> */
/* @0x2a69c2 mov r0, r5 */
/* @0x2a69c4 b 0x2a69c8 <png_get_IHDR+0x8a> */
/* @0x2a69c6 mov r0, r1 */
/* @0x2a69c8 add sp, #0x10 */
/* @0x2a69ca pop.w {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x2a69ce · png_get_oFFs · size=58 · insn=29 */
/* @0x2a69ce push {r4, lr} */
/* @0x2a69d0 ldr r4, [sp, #0x8] */
/* @0x2a69d2 cbz r0, 0x2a6a06 <png_get_oFFs+0x38> */
/* @0x2a69d4 cbz r1, 0x2a69f8 <png_get_oFFs+0x2a> */
/* @0x2a69d6 ldr r0, [r1, #0x8] */
/* @0x2a69d8 ands r0, r0, #0x100 */
/* @0x2a69da andsle r7, r3, r0, lsl #1 */
/* @0x2a69dc beq 0x2a6a06 <png_get_oFFs+0x38> */
/* @0x2a69de cbz r2, 0x2a69fc <png_get_oFFs+0x2e> */
/* @0x2a69e0 cbz r3, 0x2a6a00 <png_get_oFFs+0x32> */
/* @0x2a69e2 cbz r4, 0x2a6a04 <png_get_oFFs+0x36> */
/* @0x2a69e4 ldr r0, [r1, #0x64] */
/* @0x2a69e6 str r0, [r2] */
/* @0x2a69e8 mov.w r0, #0x100 */
/* @0x2a69ea cdpvs p0, #0x8, c7, c10, c0, #0x4 */
/* @0x2a69ec ldr r2, [r1, #0x68] */
/* @0x2a69ee str r2, [r3] */
/* @0x2a69f0 ldrb.w r3, [r1, #0x6c] */
/* @0x2a69f2 eorvs r3, r3, r12, rrx */
/* @0x2a69f4 str r3, [r4] */
/* @0x2a69f6 pop {r4, pc} */
/* @0x2a69f8 mov r0, r1 */
/* @0x2a69fa pop {r4, pc} */
/* @0x2a69fc mov r0, r2 */
/* @0x2a69fe pop {r4, pc} */
/* @0x2a6a00 mov r0, r3 */
/* @0x2a6a02 pop {r4, pc} */
/* @0x2a6a04 mov r0, r4 */
/* @0x2a6a06 pop {r4, pc} */

/* ── FUNC 0x2a6a08 · png_get_pCAL · size=98 · insn=43 */
/* @0x2a6a08 push {r4, r5, r6, r7, lr} */
/* @0x2a6a0a ldr r7, [sp, #0x14] */
/* @0x2a6a0c ldr r6, [sp, #0x18] */
/* @0x2a6a0e ldr r5, [sp, #0x1c] */
/* @0x2a6a10 ldr r4, [sp, #0x20] */
/* @0x2a6a12 ldr.w r12, [sp, #0x24] */
/* @0x2a6a14 teqlt r8, #36 */
/* @0x2a6a16 cbz r0, 0x2a6a68 <png_get_pCAL+0x60> */
/* @0x2a6a18 cbz r1, 0x2a6a66 <png_get_pCAL+0x5e> */
/* @0x2a6a1a ldr r0, [r1, #0x8] */
/* @0x2a6a1c ands r0, r0, #0x400 */
/* @0x2a6a20 beq 0x2a6a68 <png_get_pCAL+0x60> */
/* @0x2a6a22 cbz r2, 0x2a6a66 <png_get_pCAL+0x5e> */
/* @0x2a6a24 cbz r3, 0x2a6a66 <png_get_pCAL+0x5e> */
/* @0x2a6a26 cbz r7, 0x2a6a66 <png_get_pCAL+0x5e> */
/* @0x2a6a28 cbz r6, 0x2a6a66 <png_get_pCAL+0x5e> */
/* @0x2a6a2a cbz r5, 0x2a6a66 <png_get_pCAL+0x5e> */
/* @0x2a6a2c cbz r4, 0x2a6a66 <png_get_pCAL+0x5e> */
/* @0x2a6a2e cmp.w r12, #0x0 */
/* @0x2a6a30 andsle r0, r8, r0, lsl #30 */
/* @0x2a6a32 beq 0x2a6a66 <png_get_pCAL+0x5e> */
/* @0x2a6a34 ldr.w r0, [r1, #0xa0] */
/* @0x2a6a38 str r0, [r2] */
/* @0x2a6a3a mov.w r0, #0x400 */
/* @0x2a6a3c .word 0xf8d16080 */
/* @0x2a6a3e ldr.w r2, [r1, #0xa4] */
/* @0x2a6a40 andsvs r2, r10, r4, lsr #1 */
/* @0x2a6a42 str r2, [r3] */
/* @0x2a6a44 ldr.w r3, [r1, #0xa8] */
/* @0x2a6a48 str r3, [r7] */
/* @0x2a6a4a ldrb.w r3, [r1, #0xb4] */
/* @0x2a6a4c ldrhtvs r3, [r3], -r4 */
/* @0x2a6a4e str r3, [r6] */
/* @0x2a6a50 ldrb.w r3, [r1, #0xb5] */
/* @0x2a6a54 str r3, [r5] */
/* @0x2a6a56 ldr.w r3, [r1, #0xac] */
/* @0x2a6a58 eorvs r3, r3, r12, lsr #1 */
/* @0x2a6a5a str r3, [r4] */
/* @0x2a6a5c ldr.w r3, [r1, #0xb0] */
/* @0x2a6a60 str.w r3, [r12] */
/* @0x2a6a64 pop {r4, r5, r6, r7, pc} */
/* @0x2a6a66 movs r0, #0x0 */
/* @0x2a6a68 pop {r4, r5, r6, r7, pc} */

/* ── FUNC 0x2a6a6a · png_get_sCAL · size=50 · insn=22 */
/* @0x2a6a6a push {r4, lr} */
/* @0x2a6a6c mov r4, r3 */
/* @0x2a6a6e cbz r0, 0x2a6a9a <png_get_sCAL+0x30> */
/* @0x2a6a70 cbz r1, 0x2a6a98 <png_get_sCAL+0x2e> */
/* @0x2a6a72 ldr r0, [r1, #0x8] */
/* @0x2a6a74 ands r0, r0, #0x4000 */
/* @0x2a6a76 andle r4, pc, r0, lsl #1 */
/* @0x2a6a78 beq 0x2a6a9a <png_get_sCAL+0x30> */
/* @0x2a6a7a ldrb.w r3, [r1, #0xdc] */
/* @0x2a6a7e mov.w r0, #0x4000 */
/* @0x2a6a82 str r3, [r2] */
/* @0x2a6a84 ldrd r2, r3, [r1, #224] */
/* @0x2a6a86 stmib r4, {r3, r4, r5, r8, r9, sp} ^ */
/* @0x2a6a88 strd r2, r3, [r4] */
/* @0x2a6a8a ldmib r1, {r8, r9, sp} ^ */
/* @0x2a6a8c ldrd r2, r3, [r1, #232] */
/* @0x2a6a8e stmdbls r2, {r1, r3, r4, r5, r8, r9, sp} */
/* @0x2a6a90 ldr r1, [sp, #0x8] */
/* @0x2a6a92 strd r2, r3, [r1] */
/* @0x2a6a96 pop {r4, pc} */
/* @0x2a6a98 mov r0, r1 */
/* @0x2a6a9a pop {r4, pc} */

/* ── FUNC 0x2a6a9c · png_get_pHYs · size=52 · insn=26 */
/* @0x2a6a9c push {r4, lr} */
/* @0x2a6a9e ldr r4, [sp, #0x8] */
/* @0x2a6aa0 cbz r0, 0x2a6ace <png_get_pHYs+0x32> */
/* @0x2a6aa2 cbz r1, 0x2a6acc <png_get_pHYs+0x30> */
/* @0x2a6aa4 ldr r0, [r1, #0x8] */
/* @0x2a6aa6 ands r0, r0, #0x80 */
/* @0x2a6aa8 andsle r0, r0, r0, lsl #1 */
/* @0x2a6aaa beq 0x2a6ace <png_get_pHYs+0x32> */
/* @0x2a6aac cbz r2, 0x2a6ab6 <png_get_pHYs+0x1a> */
/* @0x2a6aae ldr r0, [r1, #0x70] */
/* @0x2a6ab0 str r0, [r2] */
/* @0x2a6ab2 movs r0, #0x80 */
/* @0x2a6ab4 b 0x2a6ab8 <png_get_pHYs+0x1c> */
/* @0x2a6ab6 mov r0, r2 */
/* @0x2a6ab8 cbz r3, 0x2a6ac0 <png_get_pHYs+0x24> */
/* @0x2a6aba ldr r2, [r1, #0x74] */
/* @0x2a6abc movs r0, #0x80 */
/* @0x2a6abe str r2, [r3] */
/* @0x2a6ac0 cbz r4, 0x2a6ace <png_get_pHYs+0x32> */
/* @0x2a6ac2 ldrb.w r3, [r1, #0x78] */
/* @0x2a6ac4 addhs r3, r0, r8, ror r0 */
/* @0x2a6ac6 movs r0, #0x80 */
/* @0x2a6ac8 str r3, [r4] */
/* @0x2a6aca pop {r4, pc} */
/* @0x2a6acc mov r0, r1 */
/* @0x2a6ace pop {r4, pc} */

/* ── FUNC 0x2a6ad0 · png_get_PLTE · size=34 · insn=17 */
/* @0x2a6ad0 cbz r0, 0x2a6af0 <png_get_PLTE+0x20> */
/* @0x2a6ad2 cbz r1, 0x2a6aea <png_get_PLTE+0x1a> */
/* @0x2a6ad4 ldr r0, [r1, #0x8] */
/* @0x2a6ad6 ands r0, r0, #0x8 */
/* @0x2a6ad8 andle r0, r9, r8 */
/* @0x2a6ada beq 0x2a6af0 <png_get_PLTE+0x20> */
/* @0x2a6adc cbz r2, 0x2a6aee <png_get_PLTE+0x1e> */
/* @0x2a6ade ldr r0, [r1, #0x10] */
/* @0x2a6ae0 str r0, [r2] */
/* @0x2a6ae2 movs r0, #0x8 */
/* @0x2a6ae4 ldrh r2, [r1, #0x14] */
/* @0x2a6ae6 str r2, [r3] */
/* @0x2a6ae8 bx lr */
/* @0x2a6aea mov r0, r1 */
/* @0x2a6aec bx lr */
/* @0x2a6aee mov r0, r2 */
/* @0x2a6af0 bx lr */
