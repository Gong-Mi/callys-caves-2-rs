/* libyoyo.so 覆盖卡组 0052
 * 函数 0x12060c..0x121e84，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x12060c · F_TileSetRegion(RValue&, CInstance*, CInstance*, int, RValue*) · size=236 · insn=59 */
/* @0x12060c push {r3, r4, r5, r6, r7, lr} */
/* @0x120610 mov r1, #0 */
/* @0x120614 ldr r6, [sp, #0x18] */
/* @0x120618 ldr r5, [pc, #0xd0] */
/* @0x12061c ldr r5, [pc, r5] */
/* @0x120620 mov r0, r6 */
/* @0x120624 ldr r4, [r5] */
/* @0x120628 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12062c mov r1, r0 */
/* @0x120630 mov r0, r4 */
/* @0x120634 bl 0x1af2bc <_ZN5CRoom8FindTileEi> */
/* @0x120638 subs r7, r0, #0 */
/* @0x12063c blt 0x1206dc <_Z15F_TileSetRegionR6RValueP9CInstanceS2_iPS_+0xd0> */
/* @0x120640 ldr r3, [r5] */
/* @0x120644 mov r1, #1 */
/* @0x120648 mov r0, r6 */
/* @0x12064c ldr r2, [r3, #0xb8] */
/* @0x120650 cmp r7, r2 */
/* @0x120654 rsblt r4, r7, r7, lsl #3 */
/* @0x120658 ldrlt r3, [r3, #0xc0] */
/* @0x12065c movge r4, #0 */
/* @0x120660 addlt r4, r3, r4, lsl #3 */
/* @0x120664 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x120668 mov r1, #2 */
/* @0x12066c str r0, [r4, #0xc] */
/* @0x120670 mov r0, r6 */
/* @0x120674 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x120678 mov r1, #3 */
/* @0x12067c str r0, [r4, #0x10] */
/* @0x120680 mov r0, r6 */
/* @0x120684 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x120688 mov r1, #4 */
/* @0x12068c str r0, [r4, #0x14] */
/* @0x120690 mov r0, r6 */
/* @0x120694 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x120698 ldr r3, [r5] */
/* @0x12069c ldr r2, [r3, #0xb8] */
/* @0x1206a0 cmp r7, r2 */
/* @0x1206a4 str r0, [r4, #0x18] */
/* @0x1206a8 popge {r3, r4, r5, r6, r7, pc} */
/* @0x1206ac ldr r5, [r3, #0xc0] */
/* @0x1206b0 rsb r7, r7, r7, lsl #3 */
/* @0x1206b4 ldm r4!, {r0, r1, r2, r3} */
/* @0x1206b8 add r12, r5, r7, lsl #3 */
/* @0x1206bc stm r12!, {r0, r1, r2, r3} */
/* @0x1206c0 ldm r4!, {r0, r1, r2, r3} */
/* @0x1206c4 stm r12!, {r0, r1, r2, r3} */
/* @0x1206c8 ldm r4!, {r0, r1, r2, r3} */
/* @0x1206cc stm r12!, {r0, r1, r2, r3} */
/* @0x1206d0 ldm r4, {r0, r1} */
/* @0x1206d4 stm r12, {r0, r1} */
/* @0x1206d8 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1206dc ldr r0, [pc, #0x10] */
/* @0x1206e0 mov r1, #0 */
/* @0x1206e4 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1206e8 add r0, pc, r0 */
/* @0x1206ec b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1206f0 eoreq sp, r12, r12, lsl #6 */
/* @0x1206f4 eoreq r9, r1, r4, lsl r11 */

/* ── FUNC 0x1206f8 · F_TileSetVisible(RValue&, CInstance*, CInstance*, int, RValue*) · size=188 · insn=47 */
/* @0x1206f8 push {r3, r4, r5, r6, r7, lr} */
/* @0x1206fc mov r1, #0 */
/* @0x120700 ldr r7, [sp, #0x18] */
/* @0x120704 ldr r5, [pc, #0xa0] */
/* @0x120708 ldr r5, [pc, r5] */
/* @0x12070c mov r0, r7 */
/* @0x120710 ldr r4, [r5] */
/* @0x120714 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x120718 mov r1, r0 */
/* @0x12071c mov r0, r4 */
/* @0x120720 bl 0x1af2bc <_ZN5CRoom8FindTileEi> */
/* @0x120724 subs r6, r0, #0 */
/* @0x120728 blt 0x120798 <_Z16F_TileSetVisibleR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x12072c ldr r3, [r5] */
/* @0x120730 mov r0, r7 */
/* @0x120734 mov r1, #1 */
/* @0x120738 ldr r2, [r3, #0xb8] */
/* @0x12073c cmp r6, r2 */
/* @0x120740 rsblt r4, r6, r6, lsl #3 */
/* @0x120744 ldrlt r3, [r3, #0xc0] */
/* @0x120748 movge r4, #0 */
/* @0x12074c addlt r4, r3, r4, lsl #3 */
/* @0x120750 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x120754 ldr r3, [r5] */
/* @0x120758 ldr r2, [r3, #0xb8] */
/* @0x12075c cmp r6, r2 */
/* @0x120760 strb r0, [r4, #0x34] */
/* @0x120764 popge {r3, r4, r5, r6, r7, pc} */
/* @0x120768 ldr r5, [r3, #0xc0] */
/* @0x12076c rsb r6, r6, r6, lsl #3 */
/* @0x120770 ldm r4!, {r0, r1, r2, r3} */
/* @0x120774 add r12, r5, r6, lsl #3 */
/* @0x120778 stm r12!, {r0, r1, r2, r3} */
/* @0x12077c ldm r4!, {r0, r1, r2, r3} */
/* @0x120780 stm r12!, {r0, r1, r2, r3} */
/* @0x120784 ldm r4!, {r0, r1, r2, r3} */
/* @0x120788 stm r12!, {r0, r1, r2, r3} */
/* @0x12078c ldm r4, {r0, r1} */
/* @0x120790 stm r12, {r0, r1} */
/* @0x120794 pop {r3, r4, r5, r6, r7, pc} */
/* @0x120798 ldr r0, [pc, #0x10] */
/* @0x12079c mov r1, #0 */
/* @0x1207a0 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1207a4 add r0, pc, r0 */
/* @0x1207a8 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1207ac eoreq sp, r12, r0, lsr #4 */
/* @0x1207b0 eoreq r9, r1, r8, asr r10 */

/* ── FUNC 0x1207b4 · F_TileSetBackground(RValue&, CInstance*, CInstance*, int, RValue*) · size=188 · insn=47 */
/* @0x1207b4 push {r3, r4, r5, r6, r7, lr} */
/* @0x1207b8 mov r1, #0 */
/* @0x1207bc ldr r7, [sp, #0x18] */
/* @0x1207c0 ldr r5, [pc, #0xa0] */
/* @0x1207c4 ldr r5, [pc, r5] */
/* @0x1207c8 mov r0, r7 */
/* @0x1207cc ldr r4, [r5] */
/* @0x1207d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1207d4 mov r1, r0 */
/* @0x1207d8 mov r0, r4 */
/* @0x1207dc bl 0x1af2bc <_ZN5CRoom8FindTileEi> */
/* @0x1207e0 subs r6, r0, #0 */
/* @0x1207e4 blt 0x120854 <_Z19F_TileSetBackgroundR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x1207e8 ldr r3, [r5] */
/* @0x1207ec mov r0, r7 */
/* @0x1207f0 mov r1, #1 */
/* @0x1207f4 ldr r2, [r3, #0xb8] */
/* @0x1207f8 cmp r6, r2 */
/* @0x1207fc rsblt r4, r6, r6, lsl #3 */
/* @0x120800 ldrlt r3, [r3, #0xc0] */
/* @0x120804 movge r4, #0 */
/* @0x120808 addlt r4, r3, r4, lsl #3 */
/* @0x12080c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x120810 ldr r3, [r5] */
/* @0x120814 ldr r2, [r3, #0xb8] */
/* @0x120818 cmp r6, r2 */
/* @0x12081c str r0, [r4, #0x8] */
/* @0x120820 popge {r3, r4, r5, r6, r7, pc} */
/* @0x120824 ldr r5, [r3, #0xc0] */
/* @0x120828 rsb r6, r6, r6, lsl #3 */
/* @0x12082c ldm r4!, {r0, r1, r2, r3} */
/* @0x120830 add r12, r5, r6, lsl #3 */
/* @0x120834 stm r12!, {r0, r1, r2, r3} */
/* @0x120838 ldm r4!, {r0, r1, r2, r3} */
/* @0x12083c stm r12!, {r0, r1, r2, r3} */
/* @0x120840 ldm r4!, {r0, r1, r2, r3} */
/* @0x120844 stm r12!, {r0, r1, r2, r3} */
/* @0x120848 ldm r4, {r0, r1} */
/* @0x12084c stm r12, {r0, r1} */
/* @0x120850 pop {r3, r4, r5, r6, r7, pc} */
/* @0x120854 ldr r0, [pc, #0x10] */
/* @0x120858 mov r1, #0 */
/* @0x12085c pop {r3, r4, r5, r6, r7, lr} */
/* @0x120860 add r0, pc, r0 */
/* @0x120864 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x120868 eoreq sp, r12, r4, ror #2 */
/* @0x12086c mlaeq r1, r12, r9, r9 */

/* ── FUNC 0x120870 · F_TileSetDepth(RValue&, CInstance*, CInstance*, int, RValue*) · size=188 · insn=47 */
/* @0x120870 push {r3, r4, r5, r6, r7, lr} */
/* @0x120874 mov r1, #0 */
/* @0x120878 ldr r7, [sp, #0x18] */
/* @0x12087c ldr r5, [pc, #0xa0] */
/* @0x120880 ldr r5, [pc, r5] */
/* @0x120884 mov r0, r7 */
/* @0x120888 ldr r4, [r5] */
/* @0x12088c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x120890 mov r1, r0 */
/* @0x120894 mov r0, r4 */
/* @0x120898 bl 0x1af2bc <_ZN5CRoom8FindTileEi> */
/* @0x12089c subs r6, r0, #0 */
/* @0x1208a0 blt 0x120910 <_Z14F_TileSetDepthR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x1208a4 ldr r3, [r5] */
/* @0x1208a8 mov r0, r7 */
/* @0x1208ac mov r1, #1 */
/* @0x1208b0 ldr r2, [r3, #0xb8] */
/* @0x1208b4 cmp r6, r2 */
/* @0x1208b8 rsblt r4, r6, r6, lsl #3 */
/* @0x1208bc ldrlt r3, [r3, #0xc0] */
/* @0x1208c0 movge r4, #0 */
/* @0x1208c4 addlt r4, r3, r4, lsl #3 */
/* @0x1208c8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1208cc ldr r3, [r5] */
/* @0x1208d0 ldr r2, [r3, #0xb8] */
/* @0x1208d4 cmp r6, r2 */
/* @0x1208d8 str r0, [r4, #0x1c] */
/* @0x1208dc popge {r3, r4, r5, r6, r7, pc} */
/* @0x1208e0 ldr r5, [r3, #0xc0] */
/* @0x1208e4 rsb r6, r6, r6, lsl #3 */
/* @0x1208e8 ldm r4!, {r0, r1, r2, r3} */
/* @0x1208ec add r12, r5, r6, lsl #3 */
/* @0x1208f0 stm r12!, {r0, r1, r2, r3} */
/* @0x1208f4 ldm r4!, {r0, r1, r2, r3} */
/* @0x1208f8 stm r12!, {r0, r1, r2, r3} */
/* @0x1208fc ldm r4!, {r0, r1, r2, r3} */
/* @0x120900 stm r12!, {r0, r1, r2, r3} */
/* @0x120904 ldm r4, {r0, r1} */
/* @0x120908 stm r12, {r0, r1} */
/* @0x12090c pop {r3, r4, r5, r6, r7, pc} */
/* @0x120910 ldr r0, [pc, #0x10] */
/* @0x120914 mov r1, #0 */
/* @0x120918 pop {r3, r4, r5, r6, r7, lr} */
/* @0x12091c add r0, pc, r0 */
/* @0x120920 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x120924 eoreq sp, r12, r8, lsr #1 */
/* @0x120928 eoreq r9, r1, r0, ror #17 */

/* ── FUNC 0x12092c · F_TileSetBlend(RValue&, CInstance*, CInstance*, int, RValue*) · size=188 · insn=47 */
/* @0x12092c push {r3, r4, r5, r6, r7, lr} */
/* @0x120930 mov r1, #0 */
/* @0x120934 ldr r7, [sp, #0x18] */
/* @0x120938 ldr r5, [pc, #0xa0] */
/* @0x12093c ldr r5, [pc, r5] */
/* @0x120940 mov r0, r7 */
/* @0x120944 ldr r4, [r5] */
/* @0x120948 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12094c mov r1, r0 */
/* @0x120950 mov r0, r4 */
/* @0x120954 bl 0x1af2bc <_ZN5CRoom8FindTileEi> */
/* @0x120958 subs r6, r0, #0 */
/* @0x12095c blt 0x1209cc <_Z14F_TileSetBlendR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x120960 ldr r3, [r5] */
/* @0x120964 mov r0, r7 */
/* @0x120968 mov r1, #1 */
/* @0x12096c ldr r2, [r3, #0xb8] */
/* @0x120970 cmp r6, r2 */
/* @0x120974 rsblt r4, r6, r6, lsl #3 */
/* @0x120978 ldrlt r3, [r3, #0xc0] */
/* @0x12097c movge r4, #0 */
/* @0x120980 addlt r4, r3, r4, lsl #3 */
/* @0x120984 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x120988 ldr r3, [r5] */
/* @0x12098c ldr r2, [r3, #0xb8] */
/* @0x120990 cmp r6, r2 */
/* @0x120994 str r0, [r4, #0x2c] */
/* @0x120998 popge {r3, r4, r5, r6, r7, pc} */
/* @0x12099c ldr r5, [r3, #0xc0] */
/* @0x1209a0 rsb r6, r6, r6, lsl #3 */
/* @0x1209a4 ldm r4!, {r0, r1, r2, r3} */
/* @0x1209a8 add r12, r5, r6, lsl #3 */
/* @0x1209ac stm r12!, {r0, r1, r2, r3} */
/* @0x1209b0 ldm r4!, {r0, r1, r2, r3} */
/* @0x1209b4 stm r12!, {r0, r1, r2, r3} */
/* @0x1209b8 ldm r4!, {r0, r1, r2, r3} */
/* @0x1209bc stm r12!, {r0, r1, r2, r3} */
/* @0x1209c0 ldm r4, {r0, r1} */
/* @0x1209c4 stm r12, {r0, r1} */
/* @0x1209c8 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1209cc ldr r0, [pc, #0x10] */
/* @0x1209d0 mov r1, #0 */
/* @0x1209d4 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1209d8 add r0, pc, r0 */
/* @0x1209dc b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1209e0 eoreq r12, r12, r12, ror #31 */
/* @0x1209e4 eoreq r9, r1, r4, lsr #16 */

/* ── FUNC 0x1209e8 · F_TileSetAlpha(RValue&, CInstance*, CInstance*, int, RValue*) · size=188 · insn=47 */
/* @0x1209e8 push {r3, r4, r5, r6, r7, lr} */
/* @0x1209ec mov r1, #0 */
/* @0x1209f0 ldr r7, [sp, #0x18] */
/* @0x1209f4 ldr r5, [pc, #0xa0] */
/* @0x1209f8 ldr r5, [pc, r5] */
/* @0x1209fc mov r0, r7 */
/* @0x120a00 ldr r4, [r5] */
/* @0x120a04 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x120a08 mov r1, r0 */
/* @0x120a0c mov r0, r4 */
/* @0x120a10 bl 0x1af2bc <_ZN5CRoom8FindTileEi> */
/* @0x120a14 subs r6, r0, #0 */
/* @0x120a18 blt 0x120a88 <_Z14F_TileSetAlphaR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x120a1c ldr r3, [r5] */
/* @0x120a20 mov r0, r7 */
/* @0x120a24 mov r1, #1 */
/* @0x120a28 ldr r2, [r3, #0xb8] */
/* @0x120a2c cmp r6, r2 */
/* @0x120a30 rsblt r4, r6, r6, lsl #3 */
/* @0x120a34 ldrlt r3, [r3, #0xc0] */
/* @0x120a38 movge r4, #0 */
/* @0x120a3c addlt r4, r3, r4, lsl #3 */
/* @0x120a40 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x120a44 ldr r3, [r5] */
/* @0x120a48 ldr r2, [r3, #0xb8] */
/* @0x120a4c cmp r6, r2 */
/* @0x120a50 str r0, [r4, #0x30] */
/* @0x120a54 popge {r3, r4, r5, r6, r7, pc} */
/* @0x120a58 ldr r5, [r3, #0xc0] */
/* @0x120a5c rsb r6, r6, r6, lsl #3 */
/* @0x120a60 ldm r4!, {r0, r1, r2, r3} */
/* @0x120a64 add r12, r5, r6, lsl #3 */
/* @0x120a68 stm r12!, {r0, r1, r2, r3} */
/* @0x120a6c ldm r4!, {r0, r1, r2, r3} */
/* @0x120a70 stm r12!, {r0, r1, r2, r3} */
/* @0x120a74 ldm r4!, {r0, r1, r2, r3} */
/* @0x120a78 stm r12!, {r0, r1, r2, r3} */
/* @0x120a7c ldm r4, {r0, r1} */
/* @0x120a80 stm r12, {r0, r1} */
/* @0x120a84 pop {r3, r4, r5, r6, r7, pc} */
/* @0x120a88 ldr r0, [pc, #0x10] */
/* @0x120a8c mov r1, #0 */
/* @0x120a90 pop {r3, r4, r5, r6, r7, lr} */
/* @0x120a94 add r0, pc, r0 */
/* @0x120a98 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x120a9c eoreq r12, r12, r0, lsr pc */
/* @0x120aa0 eoreq r9, r1, r8, ror #14 */

/* ── FUNC 0x120aa4 · F_TileSetPosition(RValue&, CInstance*, CInstance*, int, RValue*) · size=204 · insn=51 */
/* @0x120aa4 push {r3, r4, r5, r6, r7, lr} */
/* @0x120aa8 mov r1, #0 */
/* @0x120aac ldr r7, [sp, #0x18] */
/* @0x120ab0 ldr r5, [pc, #0xb0] */
/* @0x120ab4 ldr r5, [pc, r5] */
/* @0x120ab8 mov r0, r7 */
/* @0x120abc ldr r4, [r5] */
/* @0x120ac0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x120ac4 mov r1, r0 */
/* @0x120ac8 mov r0, r4 */
/* @0x120acc bl 0x1af2bc <_ZN5CRoom8FindTileEi> */
/* @0x120ad0 subs r6, r0, #0 */
/* @0x120ad4 blt 0x120b54 <_Z17F_TileSetPositionR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x120ad8 ldr r3, [r5] */
/* @0x120adc mov r1, #1 */
/* @0x120ae0 mov r0, r7 */
/* @0x120ae4 ldr r2, [r3, #0xb8] */
/* @0x120ae8 cmp r6, r2 */
/* @0x120aec rsblt r4, r6, r6, lsl #3 */
/* @0x120af0 ldrlt r3, [r3, #0xc0] */
/* @0x120af4 movge r4, #0 */
/* @0x120af8 addlt r4, r3, r4, lsl #3 */
/* @0x120afc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x120b00 mov r1, #2 */
/* @0x120b04 str r0, [r4] */
/* @0x120b08 mov r0, r7 */
/* @0x120b0c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x120b10 ldr r3, [r5] */
/* @0x120b14 ldr r2, [r3, #0xb8] */
/* @0x120b18 cmp r6, r2 */
/* @0x120b1c str r0, [r4, #0x4] */
/* @0x120b20 popge {r3, r4, r5, r6, r7, pc} */
/* @0x120b24 ldr r5, [r3, #0xc0] */
/* @0x120b28 rsb r6, r6, r6, lsl #3 */
/* @0x120b2c ldm r4!, {r0, r1, r2, r3} */
/* @0x120b30 add r12, r5, r6, lsl #3 */
/* @0x120b34 stm r12!, {r0, r1, r2, r3} */
/* @0x120b38 ldm r4!, {r0, r1, r2, r3} */
/* @0x120b3c stm r12!, {r0, r1, r2, r3} */
/* @0x120b40 ldm r4!, {r0, r1, r2, r3} */
/* @0x120b44 stm r12!, {r0, r1, r2, r3} */
/* @0x120b48 ldm r4, {r0, r1} */
/* @0x120b4c stm r12, {r0, r1} */
/* @0x120b50 pop {r3, r4, r5, r6, r7, pc} */
/* @0x120b54 ldr r0, [pc, #0x10] */
/* @0x120b58 mov r1, #0 */
/* @0x120b5c pop {r3, r4, r5, r6, r7, lr} */
/* @0x120b60 add r0, pc, r0 */
/* @0x120b64 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x120b68 eoreq r12, r12, r4, ror lr */
/* @0x120b6c mlaeq r1, r12, r6, r9 */

/* ── FUNC 0x120b70 · F_TileSetScale(RValue&, CInstance*, CInstance*, int, RValue*) · size=204 · insn=51 */
/* @0x120b70 push {r3, r4, r5, r6, r7, lr} */
/* @0x120b74 mov r1, #0 */
/* @0x120b78 ldr r7, [sp, #0x18] */
/* @0x120b7c ldr r5, [pc, #0xb0] */
/* @0x120b80 ldr r5, [pc, r5] */
/* @0x120b84 mov r0, r7 */
/* @0x120b88 ldr r4, [r5] */
/* @0x120b8c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x120b90 mov r1, r0 */
/* @0x120b94 mov r0, r4 */
/* @0x120b98 bl 0x1af2bc <_ZN5CRoom8FindTileEi> */
/* @0x120b9c subs r6, r0, #0 */
/* @0x120ba0 blt 0x120c20 <_Z14F_TileSetScaleR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x120ba4 ldr r3, [r5] */
/* @0x120ba8 mov r1, #1 */
/* @0x120bac mov r0, r7 */
/* @0x120bb0 ldr r2, [r3, #0xb8] */
/* @0x120bb4 cmp r6, r2 */
/* @0x120bb8 rsblt r4, r6, r6, lsl #3 */
/* @0x120bbc ldrlt r3, [r3, #0xc0] */
/* @0x120bc0 movge r4, #0 */
/* @0x120bc4 addlt r4, r3, r4, lsl #3 */
/* @0x120bc8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x120bcc mov r1, #2 */
/* @0x120bd0 str r0, [r4, #0x24] */
/* @0x120bd4 mov r0, r7 */
/* @0x120bd8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x120bdc ldr r3, [r5] */
/* @0x120be0 ldr r2, [r3, #0xb8] */
/* @0x120be4 cmp r6, r2 */
/* @0x120be8 str r0, [r4, #0x28] */
/* @0x120bec popge {r3, r4, r5, r6, r7, pc} */
/* @0x120bf0 ldr r5, [r3, #0xc0] */
/* @0x120bf4 rsb r6, r6, r6, lsl #3 */
/* @0x120bf8 ldm r4!, {r0, r1, r2, r3} */
/* @0x120bfc add r12, r5, r6, lsl #3 */
/* @0x120c00 stm r12!, {r0, r1, r2, r3} */
/* @0x120c04 ldm r4!, {r0, r1, r2, r3} */
/* @0x120c08 stm r12!, {r0, r1, r2, r3} */
/* @0x120c0c ldm r4!, {r0, r1, r2, r3} */
/* @0x120c10 stm r12!, {r0, r1, r2, r3} */
/* @0x120c14 ldm r4, {r0, r1} */
/* @0x120c18 stm r12, {r0, r1} */
/* @0x120c1c pop {r3, r4, r5, r6, r7, pc} */
/* @0x120c20 ldr r0, [pc, #0x10] */
/* @0x120c24 mov r1, #0 */
/* @0x120c28 pop {r3, r4, r5, r6, r7, lr} */
/* @0x120c2c add r0, pc, r0 */
/* @0x120c30 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x120c34 eoreq r12, r12, r8, lsr #27 */
/* @0x120c38 .word 0x002195d0 */

/* ── FUNC 0x120c3c · SetImageALPHA(unsigned char*, int, int) · size=84 · insn=21 */
/* @0x120c3c cmp r2, #0 */
/* @0x120c40 push {r4, r5, r6} */
/* @0x120c44 ble 0x120c88 <_Z13SetImageALPHAPhii+0x4c> */
/* @0x120c48 lsl r6, r1, #2 */
/* @0x120c4c mov r5, #0 */
/* @0x120c50 mvn r4, #0 */
/* @0x120c54 cmp r1, #0 */
/* @0x120c58 ble 0x120c7c <_Z13SetImageALPHAPhii+0x40> */
/* @0x120c5c mov r12, r0 */
/* @0x120c60 mov r3, #0 */
/* @0x120c64 add r3, r3, #1 */
/* @0x120c68 strb r4, [r12, #0x3] */
/* @0x120c6c cmp r3, r1 */
/* @0x120c70 add r12, r12, #4 */
/* @0x120c74 bne 0x120c64 <_Z13SetImageALPHAPhii+0x28> */
/* @0x120c78 add r0, r0, r6 */
/* @0x120c7c add r5, r5, #1 */
/* @0x120c80 cmp r5, r2 */
/* @0x120c84 bne 0x120c54 <_Z13SetImageALPHAPhii+0x18> */
/* @0x120c88 pop {r4, r5, r6} */
/* @0x120c8c bx lr */

/* ── FUNC 0x120c90 · F_ScreenSave(RValue&, CInstance*, CInstance*, int, RValue*) · size=132 · insn=33 */
/* @0x120c90 push {r4, r5, lr} */
/* @0x120c94 sub sp, sp, #20 */
/* @0x120c98 mov r1, #0 */
/* @0x120c9c add r4, sp, #12 */
/* @0x120ca0 ldr r0, [sp, #0x20] */
/* @0x120ca4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x120ca8 mov r5, r0 */
/* @0x120cac bl 0x179988 <_Z26GR_Window_Get_Region_Widthv> */
/* @0x120cb0 str r0, [sp, #0x8] */
/* @0x120cb4 bl 0x17999c <_Z27GR_Window_Get_Region_Heightv> */
/* @0x120cb8 add r12, sp, #16 */
/* @0x120cbc mov r2, #0 */
/* @0x120cc0 mov r3, r2 */
/* @0x120cc4 mov r1, r0 */
/* @0x120cc8 str r0, [sp, #0xc] */
/* @0x120ccc ldr r0, [r12, #-0x8]! */
/* @0x120cd0 str r4, [sp, #0x4] */
/* @0x120cd4 str r12, [sp] */
/* @0x120cd8 bl 0x17e0dc <_ZN8Graphics14GrabScreenRectEiiiiPiS0_> */
/* @0x120cdc subs r4, r0, #0 */
/* @0x120ce0 beq 0x120d0c <_Z12F_ScreenSaveR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x120ce4 ldr r1, [sp, #0x8] */
/* @0x120ce8 ldr r2, [sp, #0xc] */
/* @0x120cec bl 0x120c3c <_Z13SetImageALPHAPhii> */
/* @0x120cf0 mov r0, r5 */
/* @0x120cf4 mov r1, r4 */
/* @0x120cf8 ldr r2, [sp, #0x8] */
/* @0x120cfc ldr r3, [sp, #0xc] */
/* @0x120d00 bl 0x16cc8c <_Z10WritePNG32PcPvii> */
/* @0x120d04 mov r0, r4 */
/* @0x120d08 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x120d0c add sp, sp, #20 */
/* @0x120d10 pop {r4, r5, pc} */

/* ── FUNC 0x120d14 · F_ScreenSavePart(RValue&, CInstance*, CInstance*, int, RValue*) · size=292 · insn=73 */
/* @0x120d14 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x120d18 sub sp, sp, #20 */
/* @0x120d1c mov r1, #0 */
/* @0x120d20 ldr r4, [sp, #0x30] */
/* @0x120d24 mov r0, r4 */
/* @0x120d28 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x120d2c mov r8, r0 */
/* @0x120d30 bl 0x179988 <_Z26GR_Window_Get_Region_Widthv> */
/* @0x120d34 mov r9, r0 */
/* @0x120d38 bl 0x17999c <_Z27GR_Window_Get_Region_Heightv> */
/* @0x120d3c mov r1, #1 */
/* @0x120d40 mov r7, r0 */
/* @0x120d44 mov r0, r4 */
/* @0x120d48 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x120d4c mov r1, #2 */
/* @0x120d50 mov r6, r0 */
/* @0x120d54 mov r0, r4 */
/* @0x120d58 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x120d5c mov r1, #3 */
/* @0x120d60 mov r5, r0 */
/* @0x120d64 mov r0, r4 */
/* @0x120d68 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x120d6c mov r1, #4 */
/* @0x120d70 str r0, [sp, #0x8] */
/* @0x120d74 mov r0, r4 */
/* @0x120d78 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x120d7c ldr r3, [sp, #0x8] */
/* @0x120d80 cmp r6, #0 */
/* @0x120d84 addlt r3, r6, r3 */
/* @0x120d88 movlt r6, #0 */
/* @0x120d8c strlt r3, [sp, #0x8] */
/* @0x120d90 cmp r5, #0 */
/* @0x120d94 add r1, r6, r3 */
/* @0x120d98 addlt r2, r5, r0 */
/* @0x120d9c movge r2, r0 */
/* @0x120da0 movlt r5, #0 */
/* @0x120da4 str r0, [sp, #0xc] */
/* @0x120da8 strlt r2, [sp, #0xc] */
/* @0x120dac cmp r9, r1 */
/* @0x120db0 add r1, r5, r2 */
/* @0x120db4 rsblt r3, r6, r9 */
/* @0x120db8 strlt r3, [sp, #0x8] */
/* @0x120dbc cmp r7, r1 */
/* @0x120dc0 rsblt r2, r5, r7 */
/* @0x120dc4 strlt r2, [sp, #0xc] */
/* @0x120dc8 cmp r3, #0 */
/* @0x120dcc cmpgt r2, #0 */
/* @0x120dd0 bgt 0x120ddc <_Z16F_ScreenSavePartR6RValueP9CInstanceS2_iPS_+0xc8> */
/* @0x120dd4 add sp, sp, #20 */
/* @0x120dd8 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x120ddc add r12, sp, #8 */
/* @0x120de0 mov r0, r9 */
/* @0x120de4 str r12, [sp] */
/* @0x120de8 mov r1, r7 */
/* @0x120dec add r12, sp, #12 */
/* @0x120df0 mov r2, r6 */
/* @0x120df4 mov r3, r5 */
/* @0x120df8 str r12, [sp, #0x4] */
/* @0x120dfc bl 0x17e0dc <_ZN8Graphics14GrabScreenRectEiiiiPiS0_> */
/* @0x120e00 subs r4, r0, #0 */
/* @0x120e04 beq 0x120dd4 <_Z16F_ScreenSavePartR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x120e08 ldr r1, [sp, #0x8] */
/* @0x120e0c ldr r2, [sp, #0xc] */
/* @0x120e10 bl 0x120c3c <_Z13SetImageALPHAPhii> */
/* @0x120e14 mov r1, r4 */
/* @0x120e18 ldr r2, [sp, #0x8] */
/* @0x120e1c mov r0, r8 */
/* @0x120e20 ldr r3, [sp, #0xc] */
/* @0x120e24 bl 0x16cc8c <_Z10WritePNG32PcPvii> */
/* @0x120e28 mov r0, r4 */
/* @0x120e2c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x120e30 add sp, sp, #20 */
/* @0x120e34 pop {r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x120e38 · ImageBGRAtoRGBA(unsigned char*, int, int) · size=100 · insn=25 */
/* @0x120e38 cmp r2, #0 */
/* @0x120e3c push {r4, r5, r6, r7, r8} */
/* @0x120e40 ble 0x120e94 <_Z15ImageBGRAtoRGBAPhii+0x5c> */
/* @0x120e44 lsl r8, r1, #2 */
/* @0x120e48 mov r7, #0 */
/* @0x120e4c cmp r1, #0 */
/* @0x120e50 ble 0x120e88 <_Z15ImageBGRAtoRGBAPhii+0x50> */
/* @0x120e54 add r12, r0, #4 */
/* @0x120e58 mov r3, r0 */
/* @0x120e5c mov r4, #0 */
/* @0x120e60 ldrb r5, [r12, #-0x4] */
/* @0x120e64 add r4, r4, #1 */
/* @0x120e68 ldrb r6, [r3, #0x2] */
/* @0x120e6c cmp r4, r1 */
/* @0x120e70 add r12, r12, #4 */
/* @0x120e74 add r3, r3, #4 */
/* @0x120e78 strb r6, [r12, #-0x8] */
/* @0x120e7c strb r5, [r3, #-0x2] */
/* @0x120e80 bne 0x120e60 <_Z15ImageBGRAtoRGBAPhii+0x28> */
/* @0x120e84 add r0, r0, r8 */
/* @0x120e88 add r7, r7, #1 */
/* @0x120e8c cmp r7, r2 */
/* @0x120e90 bne 0x120e4c <_Z15ImageBGRAtoRGBAPhii+0x14> */
/* @0x120e94 pop {r4, r5, r6, r7, r8} */
/* @0x120e98 bx lr */

/* ── FUNC 0x120e9c · YYGML_window_set_caption(char const*) · size=8 · insn=2 */
/* @0x120e9c mov r1, #0 */
/* @0x120ea0 b 0x17ae38 <_Z21GR_Window_Set_CaptionPKcb> */

/* ── FUNC 0x120ea4 · YYGML_make_color_rgb(int, int, int) · size=12 · insn=3 */
/* @0x120ea4 add r0, r0, r1, lsl #8 */
/* @0x120ea8 add r0, r0, r2, lsl #16 */
/* @0x120eac bx lr */

/* ── FUNC 0x120eb0 · YYGML_draw_set_blend_mode(int) · size=4 · insn=1 */
/* @0x120eb0 b 0x168360 <_Z16GR_D3D_Set_Blendi> */

/* ── FUNC 0x120eb4 · CreateArray(RValue*, int, ...) · size=232 · insn=58 */
/* @0x120eb4 push {r1, r2, r3} */
/* @0x120eb8 mov r3, #2 */
/* @0x120ebc push {r4, r5, r6, r7, lr} */
/* @0x120ec0 sub sp, sp, #8 */
/* @0x120ec4 str r3, [r0, #0xc] */
/* @0x120ec8 mov r6, r0 */
/* @0x120ecc ldr r7, [sp, #0x1c] */
/* @0x120ed0 bl 0xced9c <_Z14ARRAY_RefAllocPv> */
/* @0x120ed4 ldr r1, [pc, #0xb8] */
/* @0x120ed8 mov r5, #1 */
/* @0x120edc mov r3, r5 */
/* @0x120ee0 mov r2, #70 */
/* @0x120ee4 add r1, pc, r1 */
/* @0x120ee8 mov r4, r0 */
/* @0x120eec mov r0, #8 */
/* @0x120ef0 str r4, [r6] */
/* @0x120ef4 str r5, [r4, #0x10] */
/* @0x120ef8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x120efc ldr r1, [pc, #0x94] */
/* @0x120f00 mov r3, r5 */
/* @0x120f04 mov r2, #1808 */
/* @0x120f08 add r1, pc, r1 */
/* @0x120f0c str r0, [r4, #0x4] */
/* @0x120f10 lsl r0, r7, #4 */
/* @0x120f14 ldr r12, [r6] */
/* @0x120f18 add r4, sp, #32 */
/* @0x120f1c ldr r5, [r12, #0x4] */
/* @0x120f20 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x120f24 cmp r7, #0 */
/* @0x120f28 str r0, [r5, #0x4] */
/* @0x120f2c ldr r3, [r6] */
/* @0x120f30 ldr r3, [r3, #0x4] */
/* @0x120f34 str r7, [r3] */
/* @0x120f38 str r4, [sp, #0x4] */
/* @0x120f3c ble 0x120f84 <_Z11CreateArrayP6RValueiz+0xd0> */
/* @0x120f40 mov r3, #0 */
/* @0x120f44 mov r0, r3 */
/* @0x120f48 ldr r1, [r6] */
/* @0x120f4c add r2, r4, #7 */
/* @0x120f50 bic r2, r2, #7 */
/* @0x120f54 add r4, r2, #8 */
/* @0x120f58 ldr r1, [r1, #0x4] */
/* @0x120f5c ldr r5, [r2] */
/* @0x120f60 ldr r2, [r2, #0x4] */
/* @0x120f64 ldr r12, [r1, #0x4] */
/* @0x120f68 add r1, r12, r3, lsl #4 */
/* @0x120f6c str r0, [r1, #0xc] */
/* @0x120f70 str r5, [r12, r3, lsl #4] */
/* @0x120f74 add r3, r3, #1 */
/* @0x120f78 cmp r3, r7 */
/* @0x120f7c str r2, [r1, #0x4] */
/* @0x120f80 bne 0x120f48 <_Z11CreateArrayP6RValueiz+0x94> */
/* @0x120f84 add sp, sp, #8 */
/* @0x120f88 pop {r4, r5, r6, r7, lr} */
/* @0x120f8c add sp, sp, #12 */
/* @0x120f90 bx lr */
/* @0x120f94 eoreq r0, r1, r12, asr #2 */
/* @0x120f98 eoreq r9, r1, r8, asr #32 */

/* ── FUNC 0x120f9c · F_SpriteGetBaseUV(RValue&, CInstance*, CInstance*, int, RValue*) · size=536 · insn=134 */
/* @0x120f9c push {r4, r5, r6, r7, lr} */
/* @0x120fa0 sub sp, sp, #60 */
/* @0x120fa4 mov r6, r0 */
/* @0x120fa8 mov r7, r1 */
/* @0x120fac ldr r4, [sp, #0x50] */
/* @0x120fb0 mov r1, #0 */
/* @0x120fb4 mov r0, r4 */
/* @0x120fb8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x120fbc mov r1, #1 */
/* @0x120fc0 mov r5, r0 */
/* @0x120fc4 mov r0, r4 */
/* @0x120fc8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x120fcc subs r4, r0, #0 */
/* @0x120fd0 blt 0x12105c <_Z17F_SpriteGetBaseUVR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x120fd4 mov r0, r5 */
/* @0x120fd8 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x120fdc subs r1, r0, #0 */
/* @0x120fe0 beq 0x12119c <_Z17F_SpriteGetBaseUVR6RValueP9CInstanceS2_iPS_+0x200> */
/* @0x120fe4 ldr r3, [r1, #0x74] */
/* @0x120fe8 cmp r3, #0 */
/* @0x120fec bne 0x12107c <_Z17F_SpriteGetBaseUVR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x120ff0 mov r1, r4 */
/* @0x120ff4 bl 0x1e57f4 <_ZN7CSprite10GetTextureEi> */
/* @0x120ff8 ldr r3, [pc, #0x1a8] */
/* @0x120ffc ldr r3, [pc, r3] */
/* @0x121000 ldr r2, [r3] */
/* @0x121004 cmp r0, r2 */
/* @0x121008 mov r12, r0 */
/* @0x12100c bls 0x121018 <_Z17F_SpriteGetBaseUVR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x121010 cmn r0, #1 */
/* @0x121014 bne 0x121094 <_Z17F_SpriteGetBaseUVR6RValueP9CInstanceS2_iPS_+0xf8> */
/* @0x121018 mov r4, #0 */
/* @0x12101c mov r2, #0 */
/* @0x121020 mov r3, #0 */
/* @0x121024 mov r0, r6 */
/* @0x121028 mov r1, #8 */
/* @0x12102c strd r2, r3, [sp] */
/* @0x121030 strd r2, r3, [sp, #24] */
/* @0x121034 mov r5, #0 */
/* @0x121038 strd r2, r3, [sp, #32] */
/* @0x12103c movt r5, #0x3ff0 */
/* @0x121040 strd r4, r5, [sp, #8] */
/* @0x121044 strd r4, r5, [sp, #16] */
/* @0x121048 strd r4, r5, [sp, #40] */
/* @0x12104c strd r4, r5, [sp, #48] */
/* @0x121050 bl 0x120eb4 <_Z11CreateArrayP6RValueiz> */
/* @0x121054 add sp, sp, #60 */
/* @0x121058 pop {r4, r5, r6, r7, pc} */
/* @0x12105c vldr s15, [r7, #144] */
/* @0x121060 vcvt.f64.f32 d6, s15 */
/* @0x121064 vmov r0, r1, d6 */
/* @0x121068 bl 0xb6598 <floor@plt> */
/* @0x12106c vmov d7, r0, r1 */
/* @0x121070 vcvt.s32.f64 s15, d7 */
/* @0x121074 vmov r4, s15 */
/* @0x121078 b 0x120fd4 <_Z17F_SpriteGetBaseUVR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x12107c ldr r0, [pc, #0x128] */
/* @0x121080 mov r1, #0 */
/* @0x121084 add r0, pc, r0 */
/* @0x121088 add sp, sp, #60 */
/* @0x12108c pop {r4, r5, r6, r7, lr} */
/* @0x121090 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x121094 ldrsh r4, [r0, #20] */
/* @0x121098 vmov.f32 s13, #1.000000e+00 */
/* @0x12109c ldr r3, [r3, #0x4] */
/* @0x1210a0 mov r0, r6 */
/* @0x1210a4 ldrsh r2, [r12, #2] */
/* @0x1210a8 mov r1, #8 */
/* @0x1210ac ldrsh lr, [r12] */
/* @0x1210b0 ldr r3, [r3, r4, lsl #2] */
/* @0x1210b4 vmov s12, r2 */
/* @0x1210b8 ldr r3, [r3] */
/* @0x1210bc vldr s15, [r3, #8] */
/* @0x1210c0 vldr s9, [r3, #4] */
/* @0x1210c4 vcvt.f32.s32 s15, s15 */
/* @0x1210c8 vdiv.f32 s15, s13, s15 */
/* @0x1210cc vcvt.f32.s32 s9, s9 */
/* @0x1210d0 vcvt.f32.s32 s10, s12 */
/* @0x1210d4 vdiv.f32 s9, s13, s9 */
/* @0x1210d8 vmov s13, lr */
/* @0x1210dc vmul.f32 s10, s10, s15 */
/* @0x1210e0 vcvt.f64.f32 d5, s10 */
/* @0x1210e4 vstr d5, [sp] */
/* @0x1210e8 ldrsh r3, [r12, #12] */
/* @0x1210ec vcvt.f32.s32 s14, s13 */
/* @0x1210f0 add r3, lr, r3 */
/* @0x1210f4 vmov s12, r3 */
/* @0x1210f8 vcvt.f32.s32 s12, s12 */
/* @0x1210fc vmul.f32 s12, s12, s9 */
/* @0x121100 vcvt.f64.f32 d6, s12 */
/* @0x121104 vstr d6, [sp, #8] */
/* @0x121108 ldrsh r3, [r12, #14] */
/* @0x12110c vmul.f32 s9, s14, s9 */
/* @0x121110 add r3, r2, r3 */
/* @0x121114 vmov s14, r3 */
/* @0x121118 vcvt.f32.s32 s14, s14 */
/* @0x12111c vmul.f32 s14, s14, s15 */
/* @0x121120 vcvt.f64.f32 d7, s14 */
/* @0x121124 vstr d7, [sp, #16] */
/* @0x121128 ldrsh r3, [r12, #8] */
/* @0x12112c vcvt.f64.f32 d6, s9 */
/* @0x121130 vmov s14, r3 */
/* @0x121134 vcvt.f64.s32 d7, s14 */
/* @0x121138 vmov r2, r3, d6 */
/* @0x12113c vstr d7, [sp, #24] */
/* @0x121140 ldrsh lr, [r12, #10] */
/* @0x121144 vmov s14, lr */
/* @0x121148 vcvt.f64.s32 d7, s14 */
/* @0x12114c vstr d7, [sp, #32] */
/* @0x121150 ldrsh lr, [r12, #4] */
/* @0x121154 vmov s12, lr */
/* @0x121158 ldrsh lr, [r12, #16] */
/* @0x12115c vcvt.f64.s32 d6, s12 */
/* @0x121160 vmov s14, lr */
/* @0x121164 vcvt.f64.s32 d7, s14 */
/* @0x121168 vdiv.f64 d7, d6, d7 */
/* @0x12116c vstr d7, [sp, #40] */
/* @0x121170 ldrsh lr, [r12, #6] */
/* @0x121174 ldrsh r12, [r12, #18] */
/* @0x121178 vmov s12, lr */
/* @0x12117c vmov s14, r12 */
/* @0x121180 vcvt.f64.s32 d6, s12 */
/* @0x121184 vcvt.f64.s32 d7, s14 */
/* @0x121188 vdiv.f64 d7, d6, d7 */
/* @0x12118c vstr d7, [sp, #48] */
/* @0x121190 bl 0x120eb4 <_Z11CreateArrayP6RValueiz> */
/* @0x121194 add sp, sp, #60 */
/* @0x121198 pop {r4, r5, r6, r7, pc} */
/* @0x12119c ldr r0, [pc, #0xc] */
/* @0x1211a0 add r0, pc, r0 */
/* @0x1211a4 b 0x121088 <_Z17F_SpriteGetBaseUVR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0x1211a8 eoreq r12, r12, r0, lsr #18 */
/* @0x1211ac .word 0x002193b0 */
/* @0x1211b0 eoreq r9, r1, r12, ror #1 */

/* ── FUNC 0x1211b4 · F_BackgroundGetBaseUV(RValue&, CInstance*, CInstance*, int, RValue*) · size=440 · insn=110 */
/* @0x1211b4 push {r4, r5, r6, lr} */
/* @0x1211b8 sub sp, sp, #56 */
/* @0x1211bc mov r1, #0 */
/* @0x1211c0 mov r6, r0 */
/* @0x1211c4 ldr r0, [sp, #0x48] */
/* @0x1211c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1211cc mov r4, r0 */
/* @0x1211d0 bl 0xc3640 <_Z17Background_Existsi> */
/* @0x1211d4 subs r1, r0, #0 */
/* @0x1211d8 beq 0x121248 <_Z21F_BackgroundGetBaseUVR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x1211dc mov r0, r4 */
/* @0x1211e0 bl 0xc3794 <_Z15Background_Datai> */
/* @0x1211e4 bl 0xc1e8c <_ZN11CBackground10GetTextureEv> */
/* @0x1211e8 subs r12, r0, #0 */
/* @0x1211ec blt 0x121204 <_Z21F_BackgroundGetBaseUVR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x1211f0 ldr r3, [pc, #0x16c] */
/* @0x1211f4 ldr r3, [pc, r3] */
/* @0x1211f8 ldr r2, [r3] */
/* @0x1211fc cmp r12, r2 */
/* @0x121200 bgt 0x12125c <_Z21F_BackgroundGetBaseUVR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x121204 mov r4, #0 */
/* @0x121208 mov r2, #0 */
/* @0x12120c mov r3, #0 */
/* @0x121210 mov r0, r6 */
/* @0x121214 mov r1, #8 */
/* @0x121218 strd r2, r3, [sp] */
/* @0x12121c strd r2, r3, [sp, #24] */
/* @0x121220 mov r5, #0 */
/* @0x121224 strd r2, r3, [sp, #32] */
/* @0x121228 movt r5, #0x3ff0 */
/* @0x12122c strd r4, r5, [sp, #8] */
/* @0x121230 strd r4, r5, [sp, #16] */
/* @0x121234 strd r4, r5, [sp, #40] */
/* @0x121238 strd r4, r5, [sp, #48] */
/* @0x12123c bl 0x120eb4 <_Z11CreateArrayP6RValueiz> */
/* @0x121240 add sp, sp, #56 */
/* @0x121244 pop {r4, r5, r6, pc} */
/* @0x121248 ldr r0, [pc, #0x118] */
/* @0x12124c add r0, pc, r0 */
/* @0x121250 add sp, sp, #56 */
/* @0x121254 pop {r4, r5, r6, lr} */
/* @0x121258 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x12125c ldrsh r4, [r12, #20] */
/* @0x121260 vmov.f32 s13, #1.000000e+00 */
/* @0x121264 ldr r3, [r3, #0x4] */
/* @0x121268 mov r0, r6 */
/* @0x12126c ldrsh r2, [r12, #2] */
/* @0x121270 mov r1, #8 */
/* @0x121274 ldrsh lr, [r12] */
/* @0x121278 ldr r3, [r3, r4, lsl #2] */
/* @0x12127c vmov s12, r2 */
/* @0x121280 ldr r3, [r3] */
/* @0x121284 vldr s15, [r3, #8] */
/* @0x121288 vldr s9, [r3, #4] */
/* @0x12128c vcvt.f32.s32 s15, s15 */
/* @0x121290 vdiv.f32 s15, s13, s15 */
/* @0x121294 vcvt.f32.s32 s9, s9 */
/* @0x121298 vcvt.f32.s32 s10, s12 */
/* @0x12129c vdiv.f32 s9, s13, s9 */
/* @0x1212a0 vmov s13, lr */
/* @0x1212a4 vmul.f32 s10, s10, s15 */
/* @0x1212a8 vcvt.f64.f32 d5, s10 */
/* @0x1212ac vstr d5, [sp] */
/* @0x1212b0 ldrsh r3, [r12, #12] */
/* @0x1212b4 vcvt.f32.s32 s14, s13 */
/* @0x1212b8 add r3, lr, r3 */
/* @0x1212bc vmov s12, r3 */
/* @0x1212c0 vcvt.f32.s32 s12, s12 */
/* @0x1212c4 vmul.f32 s12, s12, s9 */
/* @0x1212c8 vcvt.f64.f32 d6, s12 */
/* @0x1212cc vstr d6, [sp, #8] */
/* @0x1212d0 ldrsh r3, [r12, #14] */
/* @0x1212d4 vmul.f32 s9, s14, s9 */
/* @0x1212d8 add r3, r2, r3 */
/* @0x1212dc vmov s14, r3 */
/* @0x1212e0 vcvt.f32.s32 s14, s14 */
/* @0x1212e4 vmul.f32 s14, s14, s15 */
/* @0x1212e8 vcvt.f64.f32 d7, s14 */
/* @0x1212ec vstr d7, [sp, #16] */
/* @0x1212f0 ldrsh r3, [r12, #8] */
/* @0x1212f4 vcvt.f64.f32 d6, s9 */
/* @0x1212f8 vmov s14, r3 */
/* @0x1212fc vcvt.f64.s32 d7, s14 */
/* @0x121300 vmov r2, r3, d6 */
/* @0x121304 vstr d7, [sp, #24] */
/* @0x121308 ldrsh lr, [r12, #10] */
/* @0x12130c vmov s14, lr */
/* @0x121310 vcvt.f64.s32 d7, s14 */
/* @0x121314 vstr d7, [sp, #32] */
/* @0x121318 ldrsh lr, [r12, #4] */
/* @0x12131c vmov s12, lr */
/* @0x121320 ldrsh lr, [r12, #16] */
/* @0x121324 vcvt.f64.s32 d6, s12 */
/* @0x121328 vmov s14, lr */
/* @0x12132c vcvt.f64.s32 d7, s14 */
/* @0x121330 vdiv.f64 d7, d6, d7 */
/* @0x121334 vstr d7, [sp, #40] */
/* @0x121338 ldrsh lr, [r12, #6] */
/* @0x12133c ldrsh r12, [r12, #18] */
/* @0x121340 vmov s12, lr */
/* @0x121344 vmov s14, r12 */
/* @0x121348 vcvt.f64.s32 d6, s12 */
/* @0x12134c vcvt.f64.s32 d7, s14 */
/* @0x121350 vdiv.f64 d7, d6, d7 */
/* @0x121354 vstr d7, [sp, #48] */
/* @0x121358 bl 0x120eb4 <_Z11CreateArrayP6RValueiz> */
/* @0x12135c add sp, sp, #56 */
/* @0x121360 pop {r4, r5, r6, pc} */
/* @0x121364 eoreq r12, r12, r8, lsr #14 */
/* @0x121368 eoreq r8, r1, r4, lsr #30 */

/* ── FUNC 0x12136c · F_FontGetBaseUV(RValue&, CInstance*, CInstance*, int, RValue*) · size=336 · insn=84 */
/* @0x12136c push {r4, r5, r6, lr} */
/* @0x121370 sub sp, sp, #24 */
/* @0x121374 mov r1, #0 */
/* @0x121378 mov r6, r0 */
/* @0x12137c ldr r0, [sp, #0x28] */
/* @0x121380 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x121384 mov r4, r0 */
/* @0x121388 bl 0xfa2a8 <_Z11Font_Existsi> */
/* @0x12138c subs r1, r0, #0 */
/* @0x121390 beq 0x1213f8 <_Z15F_FontGetBaseUVR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x121394 mov r3, #0 */
/* @0x121398 mov r0, r4 */
/* @0x12139c str r3, [r6, #0xc] */
/* @0x1213a0 bl 0xfa3fc <_Z9Font_Datai> */
/* @0x1213a4 bl 0xf94e4 <_ZN7CFontGM10GetTextureEv> */
/* @0x1213a8 subs r2, r0, #0 */
/* @0x1213ac blt 0x1213c4 <_Z15F_FontGetBaseUVR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x1213b0 ldr r3, [pc, #0xfc] */
/* @0x1213b4 ldr r3, [pc, r3] */
/* @0x1213b8 ldr r1, [r3] */
/* @0x1213bc cmp r2, r1 */
/* @0x1213c0 bgt 0x12140c <_Z15F_FontGetBaseUVR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x1213c4 mov r4, #0 */
/* @0x1213c8 mov r2, #0 */
/* @0x1213cc mov r3, #0 */
/* @0x1213d0 mov r0, r6 */
/* @0x1213d4 mov r1, #4 */
/* @0x1213d8 strd r2, r3, [sp] */
/* @0x1213dc mov r5, #0 */
/* @0x1213e0 movt r5, #0x3ff0 */
/* @0x1213e4 strd r4, r5, [sp, #8] */
/* @0x1213e8 strd r4, r5, [sp, #16] */
/* @0x1213ec bl 0x120eb4 <_Z11CreateArrayP6RValueiz> */
/* @0x1213f0 add sp, sp, #24 */
/* @0x1213f4 pop {r4, r5, r6, pc} */
/* @0x1213f8 ldr r0, [pc, #0xb8] */
/* @0x1213fc add r0, pc, r0 */
/* @0x121400 add sp, sp, #24 */
/* @0x121404 pop {r4, r5, r6, lr} */
/* @0x121408 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x12140c ldrsh r4, [r2, #20] */
/* @0x121410 vmov.f32 s13, #1.000000e+00 */
/* @0x121414 ldr r3, [r3, #0x4] */
/* @0x121418 mov r0, r6 */
/* @0x12141c ldrsh r12, [r2, #2] */
/* @0x121420 mov r1, #4 */
/* @0x121424 ldrsh lr, [r2] */
/* @0x121428 ldr r3, [r3, r4, lsl #2] */
/* @0x12142c vmov s12, r12 */
/* @0x121430 ldr r3, [r3] */
/* @0x121434 vldr s15, [r3, #8] */
/* @0x121438 vldr s9, [r3, #4] */
/* @0x12143c vcvt.f32.s32 s15, s15 */
/* @0x121440 vdiv.f32 s15, s13, s15 */
/* @0x121444 vcvt.f32.s32 s9, s9 */
/* @0x121448 vcvt.f32.s32 s10, s12 */
/* @0x12144c vdiv.f32 s9, s13, s9 */
/* @0x121450 vmov s13, lr */
/* @0x121454 vmul.f32 s10, s10, s15 */
/* @0x121458 vcvt.f64.f32 d5, s10 */
/* @0x12145c vstr d5, [sp] */
/* @0x121460 ldrsh r3, [r2, #12] */
/* @0x121464 vcvt.f32.s32 s14, s13 */
/* @0x121468 add r3, lr, r3 */
/* @0x12146c vmov s12, r3 */
/* @0x121470 vcvt.f32.s32 s12, s12 */
/* @0x121474 vmul.f32 s12, s12, s9 */
/* @0x121478 vcvt.f64.f32 d6, s12 */
/* @0x12147c vstr d6, [sp, #8] */
/* @0x121480 ldrsh r3, [r2, #14] */
/* @0x121484 vmul.f32 s9, s14, s9 */
/* @0x121488 add r3, r12, r3 */
/* @0x12148c vmov s14, r3 */
/* @0x121490 vcvt.f32.s32 s14, s14 */
/* @0x121494 vmul.f32 s14, s14, s15 */
/* @0x121498 vcvt.f64.f32 d6, s9 */
/* @0x12149c vcvt.f64.f32 d7, s14 */
/* @0x1214a0 vmov r2, r3, d6 */
/* @0x1214a4 vstr d7, [sp, #16] */
/* @0x1214a8 bl 0x120eb4 <_Z11CreateArrayP6RValueiz> */
/* @0x1214ac add sp, sp, #24 */
/* @0x1214b0 pop {r4, r5, r6, pc} */
/* @0x1214b4 eoreq r12, r12, r8, ror #10 */
/* @0x1214b8 eoreq r8, r1, r8, lsr #27 */

/* ── FUNC 0x1214bc · F_SkeletonGetMinmax(RValue&, CInstance*, CInstance*, int, RValue*) · size=176 · insn=44 */
/* @0x1214bc push {r4, lr} */
/* @0x1214c0 mov r4, r0 */
/* @0x1214c4 mov r3, #2 */
/* @0x1214c8 sub sp, sp, #40 */
/* @0x1214cc mov r0, r1 */
/* @0x1214d0 str r3, [r4, #0xc] */
/* @0x1214d4 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv> */
/* @0x1214d8 cmp r0, #0 */
/* @0x1214dc beq 0x121500 <_Z19F_SkeletonGetMinmaxR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x1214e0 add r3, sp, #36 */
/* @0x1214e4 add r1, sp, #24 */
/* @0x1214e8 str r3, [sp] */
/* @0x1214ec add r2, sp, #28 */
/* @0x1214f0 add r3, sp, #32 */
/* @0x1214f4 bl 0xbee60 <_ZN17CSkeletonInstance14GetBoundingBoxERfS0_S0_S0_> */
/* @0x1214f8 cmp r0, #0 */
/* @0x1214fc bne 0x121528 <_Z19F_SkeletonGetMinmaxR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x121500 mov r2, #0 */
/* @0x121504 mov r3, #0 */
/* @0x121508 mov r0, r4 */
/* @0x12150c mov r1, #4 */
/* @0x121510 strd r2, r3, [sp] */
/* @0x121514 strd r2, r3, [sp, #8] */
/* @0x121518 strd r2, r3, [sp, #16] */
/* @0x12151c bl 0x120eb4 <_Z11CreateArrayP6RValueiz> */
/* @0x121520 add sp, sp, #40 */
/* @0x121524 pop {r4, pc} */
/* @0x121528 vldr s14, [sp, #36] */
/* @0x12152c vcvt.f64.f32 d7, s14 */
/* @0x121530 vldr s10, [sp, #28] */
/* @0x121534 vldr s12, [sp, #32] */
/* @0x121538 vldr s9, [sp, #24] */
/* @0x12153c mov r0, r4 */
/* @0x121540 mov r1, #4 */
/* @0x121544 vcvt.f64.f32 d5, s10 */
/* @0x121548 vstr d7, [sp, #16] */
/* @0x12154c vcvt.f64.f32 d6, s12 */
/* @0x121550 vstr d5, [sp] */
/* @0x121554 vcvt.f64.f32 d7, s9 */
/* @0x121558 vstr d6, [sp, #8] */
/* @0x12155c vmov r2, r3, d7 */
/* @0x121560 bl 0x120eb4 <_Z11CreateArrayP6RValueiz> */
/* @0x121564 add sp, sp, #40 */
/* @0x121568 pop {r4, pc} */

/* ── FUNC 0x12156c · F_TextureGetUVs(RValue&, CInstance*, CInstance*, int, RValue*) · size=392 · insn=98 */
/* @0x12156c push {r4, r5, r6, lr} */
/* @0x121570 sub sp, sp, #56 */
/* @0x121574 mov r6, r0 */
/* @0x121578 mov r1, #0 */
/* @0x12157c ldr r0, [sp, #0x48] */
/* @0x121580 bl 0xce6c0 <_Z13YYGetPtrOrIntPK6RValuei> */
/* @0x121584 ldr r3, [pc, #0x164] */
/* @0x121588 ldr r3, [pc, r3] */
/* @0x12158c ldr r2, [r3] */
/* @0x121590 cmp r0, r2 */
/* @0x121594 mov r12, r0 */
/* @0x121598 bls 0x1215a4 <_Z15F_TextureGetUVsR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x12159c cmn r0, #1 */
/* @0x1215a0 bne 0x1215e8 <_Z15F_TextureGetUVsR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x1215a4 mov r4, #0 */
/* @0x1215a8 mov r2, #0 */
/* @0x1215ac mov r3, #0 */
/* @0x1215b0 mov r0, r6 */
/* @0x1215b4 mov r1, #8 */
/* @0x1215b8 strd r2, r3, [sp] */
/* @0x1215bc strd r2, r3, [sp, #24] */
/* @0x1215c0 mov r5, #0 */
/* @0x1215c4 strd r2, r3, [sp, #32] */
/* @0x1215c8 movt r5, #0x3ff0 */
/* @0x1215cc strd r4, r5, [sp, #8] */
/* @0x1215d0 strd r4, r5, [sp, #16] */
/* @0x1215d4 strd r4, r5, [sp, #40] */
/* @0x1215d8 strd r4, r5, [sp, #48] */
/* @0x1215dc bl 0x120eb4 <_Z11CreateArrayP6RValueiz> */
/* @0x1215e0 add sp, sp, #56 */
/* @0x1215e4 pop {r4, r5, r6, pc} */
/* @0x1215e8 ldrsh r4, [r0, #20] */
/* @0x1215ec vmov.f32 s13, #1.000000e+00 */
/* @0x1215f0 ldr r3, [r3, #0x4] */
/* @0x1215f4 mov r0, r6 */
/* @0x1215f8 ldrsh r2, [r12, #2] */
/* @0x1215fc mov r1, #8 */
/* @0x121600 ldrsh lr, [r12] */
/* @0x121604 ldr r3, [r3, r4, lsl #2] */
/* @0x121608 vmov s12, r2 */
/* @0x12160c ldr r3, [r3] */
/* @0x121610 vldr s15, [r3, #8] */
/* @0x121614 vldr s9, [r3, #4] */
/* @0x121618 vcvt.f32.s32 s15, s15 */
/* @0x12161c vdiv.f32 s15, s13, s15 */
/* @0x121620 vcvt.f32.s32 s9, s9 */
/* @0x121624 vcvt.f32.s32 s10, s12 */
/* @0x121628 vdiv.f32 s9, s13, s9 */
/* @0x12162c vmov s13, lr */
/* @0x121630 vmul.f32 s10, s10, s15 */
/* @0x121634 vcvt.f64.f32 d5, s10 */
/* @0x121638 vstr d5, [sp] */
/* @0x12163c ldrsh r3, [r12, #12] */
/* @0x121640 vcvt.f32.s32 s14, s13 */
/* @0x121644 add r3, lr, r3 */
/* @0x121648 vmov s12, r3 */
/* @0x12164c vcvt.f32.s32 s12, s12 */
/* @0x121650 vmul.f32 s12, s12, s9 */
/* @0x121654 vcvt.f64.f32 d6, s12 */
/* @0x121658 vstr d6, [sp, #8] */
/* @0x12165c ldrsh r3, [r12, #14] */
/* @0x121660 vmul.f32 s9, s14, s9 */
/* @0x121664 add r3, r2, r3 */
/* @0x121668 vmov s14, r3 */
/* @0x12166c vcvt.f32.s32 s14, s14 */
/* @0x121670 vmul.f32 s14, s14, s15 */
/* @0x121674 vcvt.f64.f32 d7, s14 */
/* @0x121678 vstr d7, [sp, #16] */
/* @0x12167c ldrsh r3, [r12, #8] */
/* @0x121680 vcvt.f64.f32 d6, s9 */
/* @0x121684 vmov s14, r3 */
/* @0x121688 vcvt.f64.s32 d7, s14 */
/* @0x12168c vmov r2, r3, d6 */
/* @0x121690 vstr d7, [sp, #24] */
/* @0x121694 ldrsh lr, [r12, #10] */
/* @0x121698 vmov s14, lr */
/* @0x12169c vcvt.f64.s32 d7, s14 */
/* @0x1216a0 vstr d7, [sp, #32] */
/* @0x1216a4 ldrsh lr, [r12, #4] */
/* @0x1216a8 vmov s12, lr */
/* @0x1216ac ldrsh lr, [r12, #16] */
/* @0x1216b0 vcvt.f64.s32 d6, s12 */
/* @0x1216b4 vmov s14, lr */
/* @0x1216b8 vcvt.f64.s32 d7, s14 */
/* @0x1216bc vdiv.f64 d7, d6, d7 */
/* @0x1216c0 vstr d7, [sp, #40] */
/* @0x1216c4 ldrsh lr, [r12, #6] */
/* @0x1216c8 ldrsh r12, [r12, #18] */
/* @0x1216cc vmov s12, lr */
/* @0x1216d0 vmov s14, r12 */
/* @0x1216d4 vcvt.f64.s32 d6, s12 */
/* @0x1216d8 vcvt.f64.s32 d7, s14 */
/* @0x1216dc vdiv.f64 d7, d6, d7 */
/* @0x1216e0 vstr d7, [sp, #48] */
/* @0x1216e4 bl 0x120eb4 <_Z11CreateArrayP6RValueiz> */
/* @0x1216e8 add sp, sp, #56 */
/* @0x1216ec pop {r4, r5, r6, pc} */
/* @0x1216f0 mlaeq r12, r4, r3, r12 */

/* ── FUNC 0x1216f4 · F_TileGetIDs(RValue&, CInstance*, CInstance*, int, RValue*) · size=244 · insn=61 */
/* @0x1216f4 push {r4, r5, r6, lr} */
/* @0x1216f8 mov r6, r0 */
/* @0x1216fc ldr r5, [pc, #0xd8] */
/* @0x121700 ldr r5, [pc, r5] */
/* @0x121704 ldr r2, [r5] */
/* @0x121708 ldr r4, [r2, #0xb8] */
/* @0x12170c cmp r4, #0 */
/* @0x121710 popeq {r4, r5, r6, pc} */
/* @0x121714 cmp r3, #0 */
/* @0x121718 bne 0x1217a0 <_Z12F_TileGetIDsR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0x12171c mov r3, #0 */
/* @0x121720 mov r1, #1 */
/* @0x121724 mov r2, #0 */
/* @0x121728 bl 0x120eb4 <_Z11CreateArrayP6RValueiz> */
/* @0x12172c ldr r3, [r6] */
/* @0x121730 ldr r0, [r3, #0x4] */
/* @0x121734 ldr r3, [r0] */
/* @0x121738 cmp r4, r3 */
/* @0x12173c bge 0x1217b4 <_Z12F_TileGetIDsR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x121740 cmp r4, #0 */
/* @0x121744 ldr r1, [r0, #0x4] */
/* @0x121748 pople {r4, r5, r6, pc} */
/* @0x12174c ldr r5, [r5] */
/* @0x121750 mov r12, #0 */
/* @0x121754 mov r0, r12 */
/* @0x121758 mov r6, r12 */
/* @0x12175c ldr r2, [r5, #0xb8] */
/* @0x121760 mov r3, #0 */
/* @0x121764 cmp r2, r0 */
/* @0x121768 add r0, r0, #1 */
/* @0x12176c ldrgt r3, [r5, #0xc0] */
/* @0x121770 str r6, [r1, #0xc] */
/* @0x121774 addgt r3, r3, r12 */
/* @0x121778 cmp r0, r4 */
/* @0x12177c add r12, r12, #56 */
/* @0x121780 ldr r2, [r3, #0x20] */
/* @0x121784 vmov s15, r2 */
/* @0x121788 vcvt.f64.s32 d7, s15 */
/* @0x12178c vmov r2, r3, d7 */
/* @0x121790 stm r1, {r2, r3} */
/* @0x121794 add r1, r1, #16 */
/* @0x121798 bne 0x12175c <_Z12F_TileGetIDsR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x12179c pop {r4, r5, r6, pc} */
/* @0x1217a0 ldr r0, [pc, #0x38] */
/* @0x1217a4 mov r1, #0 */
/* @0x1217a8 pop {r4, r5, r6, lr} */
/* @0x1217ac add r0, pc, r0 */
/* @0x1217b0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1217b4 ldr r2, [pc, #0x28] */
/* @0x1217b8 add r0, r0, #4 */
/* @0x1217bc movw r3, #0x1160 */
/* @0x1217c0 lsl r1, r4, #4 */
/* @0x1217c4 add r2, pc, r2 */
/* @0x1217c8 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1217cc ldr r3, [r6] */
/* @0x1217d0 ldr r0, [r3, #0x4] */
/* @0x1217d4 str r4, [r0] */
/* @0x1217d8 b 0x121740 <_Z12F_TileGetIDsR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x1217dc eoreq r12, r12, r8, lsr #4 */
/* @0x1217e0 .word 0x00218cbc */
/* @0x1217e4 eoreq r8, r1, r12, lsl #15 */

/* ── FUNC 0x1217e8 · F_TileGetIDsAtDepth(RValue&, CInstance*, CInstance*, int, RValue*) · size=348 · insn=87 */
/* @0x1217e8 push {r3, r4, r5, r6, r7, lr} */
/* @0x1217ec vpush {d8} */
/* @0x1217f0 mov r7, r0 */
/* @0x1217f4 ldr r6, [pc, #0x140] */
/* @0x1217f8 ldr r6, [pc, r6] */
/* @0x1217fc ldr r3, [r6] */
/* @0x121800 ldr r4, [r3, #0xb8] */
/* @0x121804 cmp r4, #0 */
/* @0x121808 bne 0x121814 <_Z19F_TileGetIDsAtDepthR6RValueP9CInstanceS2_iPS_+0x2c> */
/* @0x12180c vpop {d8} */
/* @0x121810 pop {r3, r4, r5, r6, r7, pc} */
/* @0x121814 ldr r0, [sp, #0x20] */
/* @0x121818 mov r1, #0 */
/* @0x12181c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x121820 cmp r4, #0 */
/* @0x121824 vmov s16, r0 */
/* @0x121828 ble 0x121934 <_Z19F_TileGetIDsAtDepthR6RValueP9CInstanceS2_iPS_+0x14c> */
/* @0x12182c ldr r0, [r6] */
/* @0x121830 mov r2, #0 */
/* @0x121834 mov r3, r2 */
/* @0x121838 mov r5, r2 */
/* @0x12183c ldr r12, [r0, #0xb8] */
/* @0x121840 cmp r12, r3 */
/* @0x121844 mov r1, #0 */
/* @0x121848 add r3, r3, #1 */
/* @0x12184c ldrgt r1, [r0, #0xc0] */
/* @0x121850 addgt r1, r1, r2 */
/* @0x121854 vldr s15, [r1, #28] */
/* @0x121858 vcmp.f32 s15, s16 */
/* @0x12185c add r2, r2, #56 */
/* @0x121860 vmrs APSR_nzcv, fpscr */
/* @0x121864 addeq r5, r5, #1 */
/* @0x121868 cmp r3, r4 */
/* @0x12186c bne 0x121840 <_Z19F_TileGetIDsAtDepthR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x121870 mov r0, r7 */
/* @0x121874 mov r3, #0 */
/* @0x121878 mov r1, #1 */
/* @0x12187c mov r2, #0 */
/* @0x121880 bl 0x120eb4 <_Z11CreateArrayP6RValueiz> */
/* @0x121884 ldr r3, [r7] */
/* @0x121888 ldr r0, [r3, #0x4] */
/* @0x12188c ldr r3, [r0] */
/* @0x121890 cmp r3, r5 */
/* @0x121894 ble 0x12190c <_Z19F_TileGetIDsAtDepthR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x121898 cmp r4, #0 */
/* @0x12189c ldr r12, [r0, #0x4] */
/* @0x1218a0 ble 0x12180c <_Z19F_TileGetIDsAtDepthR6RValueP9CInstanceS2_iPS_+0x24> */
/* @0x1218a4 mov r0, #0 */
/* @0x1218a8 ldr r5, [r6] */
/* @0x1218ac mov r1, r0 */
/* @0x1218b0 mov r6, r0 */
/* @0x1218b4 ldr r2, [r5, #0xb8] */
/* @0x1218b8 mov r3, #0 */
/* @0x1218bc cmp r2, r1 */
/* @0x1218c0 add r1, r1, #1 */
/* @0x1218c4 ldrgt r3, [r5, #0xc0] */
/* @0x1218c8 addgt r3, r3, r0 */
/* @0x1218cc vldr s15, [r3, #28] */
/* @0x1218d0 vcmp.f32 s15, s16 */
/* @0x1218d4 add r0, r0, #56 */
/* @0x1218d8 vmrs APSR_nzcv, fpscr */
/* @0x1218dc bne 0x1218fc <_Z19F_TileGetIDsAtDepthR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0x1218e0 ldr r2, [r3, #0x20] */
/* @0x1218e4 str r6, [r12, #0xc] */
/* @0x1218e8 vmov s15, r2 */
/* @0x1218ec vcvt.f64.s32 d7, s15 */
/* @0x1218f0 vmov r2, r3, d7 */
/* @0x1218f4 stm r12, {r2, r3} */
/* @0x1218f8 add r12, r12, #16 */
/* @0x1218fc cmp r1, r4 */
/* @0x121900 bne 0x1218b4 <_Z19F_TileGetIDsAtDepthR6RValueP9CInstanceS2_iPS_+0xcc> */
/* @0x121904 vpop {d8} */
/* @0x121908 pop {r3, r4, r5, r6, r7, pc} */
/* @0x12190c ldr r2, [pc, #0x2c] */
/* @0x121910 add r0, r0, #4 */
/* @0x121914 movw r3, #0x118e */
/* @0x121918 lsl r1, r5, #4 */
/* @0x12191c add r2, pc, r2 */
/* @0x121920 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x121924 ldr r3, [r7] */
/* @0x121928 ldr r0, [r3, #0x4] */
/* @0x12192c str r5, [r0] */
/* @0x121930 b 0x121898 <_Z19F_TileGetIDsAtDepthR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x121934 mov r5, #0 */
/* @0x121938 b 0x121870 <_Z19F_TileGetIDsAtDepthR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x12193c eoreq r12, r12, r0, lsr r1 */
/* @0x121940 eoreq r8, r1, r4, lsr r6 */

/* ── FUNC 0x121944 · CreateArrayValOrString(RValue*, int, ...) · size=328 · insn=82 */
/* @0x121944 push {r1, r2, r3} */
/* @0x121948 mov r3, #2 */
/* @0x12194c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x121950 sub sp, sp, #8 */
/* @0x121954 str r3, [r0, #0xc] */
/* @0x121958 mov r10, r0 */
/* @0x12195c ldr r7, [sp, #0x2c] */
/* @0x121960 bl 0xced9c <_Z14ARRAY_RefAllocPv> */
/* @0x121964 ldr r1, [pc, #0x118] */
/* @0x121968 mov r9, #1 */
/* @0x12196c mov r3, r9 */
/* @0x121970 mov r2, #70 */
/* @0x121974 add r1, pc, r1 */
/* @0x121978 mov r4, r0 */
/* @0x12197c mov r0, #8 */
/* @0x121980 str r4, [r10] */
/* @0x121984 str r9, [r4, #0x10] */
/* @0x121988 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x12198c ldr r1, [pc, #0xf4] */
/* @0x121990 mov r3, r9 */
/* @0x121994 movw r2, #0x724 */
/* @0x121998 add r1, pc, r1 */
/* @0x12199c str r0, [r4, #0x4] */
/* @0x1219a0 lsl r0, r7, #4 */
/* @0x1219a4 ldr r12, [r10] */
/* @0x1219a8 ldr r4, [r12, #0x4] */
/* @0x1219ac bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1219b0 cmp r7, #0 */
/* @0x1219b4 add r3, sp, #48 */
/* @0x1219b8 str r0, [r4, #0x4] */
/* @0x1219bc ldr r2, [r10] */
/* @0x1219c0 ldr r2, [r2, #0x4] */
/* @0x1219c4 str r7, [r2] */
/* @0x1219c8 str r3, [sp, #0x4] */
/* @0x1219cc ble 0x121a74 <_Z22CreateArrayValOrStringP6RValueiz+0x130> */
/* @0x1219d0 mov r4, #0 */
/* @0x1219d4 mov r8, r4 */
/* @0x1219d8 b 0x121a00 <_Z22CreateArrayValOrStringP6RValueiz+0xbc> */
/* @0x1219dc ldr r2, [r10] */
/* @0x1219e0 add r4, r4, #1 */
/* @0x1219e4 ldr r2, [r2, #0x4] */
/* @0x1219e8 ldr r0, [r2, #0x4] */
/* @0x1219ec add r0, r0, r3 */
/* @0x1219f0 str r9, [r0, #0xc] */
/* @0x1219f4 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x1219f8 cmp r4, r7 */
/* @0x1219fc beq 0x121a74 <_Z22CreateArrayValOrStringP6RValueiz+0x130> */
/* @0x121a00 ldr r1, [r10] */
/* @0x121a04 lsl r3, r4, #4 */
/* @0x121a08 ldr r2, [sp, #0x4] */
/* @0x121a0c ldr r1, [r1, #0x4] */
/* @0x121a10 add r2, r2, #7 */
/* @0x121a14 bic r2, r2, #7 */
/* @0x121a18 add r11, r2, #12 */
/* @0x121a1c ldr r12, [r2, #0x8] */
/* @0x121a20 ldr r6, [r1, #0x4] */
/* @0x121a24 ldr r0, [r2] */
/* @0x121a28 cmp r12, #0 */
/* @0x121a2c ldr r2, [r2, #0x4] */
/* @0x121a30 add r5, r6, r3 */
/* @0x121a34 str r11, [sp, #0x4] */
/* @0x121a38 mov r1, r12 */
/* @0x121a3c str r8, [r5, #0xc] */
/* @0x121a40 str r0, [r6, r4, lsl #4] */
/* @0x121a44 str r2, [r5, #0x4] */
/* @0x121a48 bne 0x1219dc <_Z22CreateArrayValOrStringP6RValueiz+0x98> */
/* @0x121a4c ldr r1, [r10] */
/* @0x121a50 ldr r1, [r1, #0x4] */
/* @0x121a54 ldr r1, [r1, #0x4] */
/* @0x121a58 add r3, r1, r3 */
/* @0x121a5c str r12, [r3, #0xc] */
/* @0x121a60 str r0, [r1, r4, lsl #4] */
/* @0x121a64 add r4, r4, #1 */
/* @0x121a68 cmp r4, r7 */
/* @0x121a6c str r2, [r3, #0x4] */
/* @0x121a70 bne 0x121a00 <_Z22CreateArrayValOrStringP6RValueiz+0xbc> */
/* @0x121a74 add sp, sp, #8 */
/* @0x121a78 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x121a7c add sp, sp, #12 */
/* @0x121a80 bx lr */
/* @0x121a84 .word 0x0020f6bc */
/* @0x121a88 .word 0x002185b8 */

/* ── FUNC 0x121a8c · F_SkeletonGetBounds(RValue&, CInstance*, CInstance*, int, RValue*) · size=584 · insn=146 */
/* @0x121a8c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x121a90 add r11, sp, #32 */
/* @0x121a94 ldr r4, [pc, #0x228] */
/* @0x121a98 sub sp, sp, #52 */
/* @0x121a9c mov r10, r0 */
/* @0x121aa0 ldr r4, [pc, r4] */
/* @0x121aa4 mov r6, #2 */
/* @0x121aa8 mov r0, r1 */
/* @0x121aac str r6, [r10, #0xc] */
/* @0x121ab0 ldr r3, [r4] */
/* @0x121ab4 ldr r8, [r11, #0x4] */
/* @0x121ab8 str r3, [r11, #-0x28] */
/* @0x121abc bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv> */
/* @0x121ac0 subs r7, r0, #0 */
/* @0x121ac4 beq 0x121b04 <_Z19F_SkeletonGetBoundsR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x121ac8 mov r1, #0 */
/* @0x121acc mov r0, r8 */
/* @0x121ad0 sub r2, r11, #48 */
/* @0x121ad4 str r2, [r11, #-0x38] */
/* @0x121ad8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x121adc sub r9, r11, #44 */
/* @0x121ae0 mov r5, #0 */
/* @0x121ae4 sub r2, r11, #48 */
/* @0x121ae8 mov r3, r9 */
/* @0x121aec str r5, [sp] */
/* @0x121af0 mov r1, r0 */
/* @0x121af4 mov r0, r7 */
/* @0x121af8 bl 0xbef04 <_ZN17CSkeletonInstance24GetBoundingBoxAttachmentEiPPKcPiPf> */
/* @0x121afc cmp r0, r5 */
/* @0x121b00 bne 0x121b48 <_Z19F_SkeletonGetBoundsR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x121b04 ldr r1, [pc, #0x1bc] */
/* @0x121b08 mov r2, #0 */
/* @0x121b0c mov r3, #0 */
/* @0x121b10 mov r12, #0 */
/* @0x121b14 add r1, pc, r1 */
/* @0x121b18 mov r0, r10 */
/* @0x121b1c str r1, [sp, #0x10] */
/* @0x121b20 mov r1, #2 */
/* @0x121b24 strd r2, r3, [sp, #8] */
/* @0x121b28 str r12, [sp] */
/* @0x121b2c bl 0x121944 <_Z22CreateArrayValOrStringP6RValueiz> */
/* @0x121b30 ldr r2, [r11, #-0x28] */
/* @0x121b34 ldr r3, [r4] */
/* @0x121b38 cmp r2, r3 */
/* @0x121b3c bne 0x121cc0 <_Z19F_SkeletonGetBoundsR6RValueP9CInstanceS2_iPS_+0x234> */
/* @0x121b40 sub sp, r11, #32 */
/* @0x121b44 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x121b48 ldr r3, [r11, #-0x2c] */
/* @0x121b4c mov r0, r8 */
/* @0x121b50 mov r1, r5 */
/* @0x121b54 mov r8, #1 */
/* @0x121b58 lsl r3, r3, #3 */
/* @0x121b5c add r3, r3, #8 */
/* @0x121b60 sub sp, sp, r3 */
/* @0x121b64 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x121b68 sub r2, r11, #48 */
/* @0x121b6c mov r3, r9 */
/* @0x121b70 mov r1, r0 */
/* @0x121b74 mov r0, r7 */
/* @0x121b78 add r7, sp, #24 */
/* @0x121b7c str r7, [sp] */
/* @0x121b80 bl 0xbef04 <_ZN17CSkeletonInstance24GetBoundingBoxAttachmentEiPPKcPiPf> */
/* @0x121b84 str r6, [r10, #0xc] */
/* @0x121b88 mov r0, r10 */
/* @0x121b8c bl 0xced9c <_Z14ARRAY_RefAllocPv> */
/* @0x121b90 ldr r1, [pc, #0x134] */
/* @0x121b94 mov r3, r8 */
/* @0x121b98 mov r2, #70 */
/* @0x121b9c add r1, pc, r1 */
/* @0x121ba0 mov r6, r0 */
/* @0x121ba4 str r0, [r10] */
/* @0x121ba8 str r8, [r6, #0x10] */
/* @0x121bac mov r0, #8 */
/* @0x121bb0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x121bb4 ldr lr, [r11, #-0x2c] */
/* @0x121bb8 ldr r1, [pc, #0x110] */
/* @0x121bbc mov r3, r8 */
/* @0x121bc0 add lr, lr, r8 */
/* @0x121bc4 movw r2, #0x1529 */
/* @0x121bc8 add r1, pc, r1 */
/* @0x121bcc str r0, [r6, #0x4] */
/* @0x121bd0 lsl r0, lr, #5 */
/* @0x121bd4 ldr lr, [r10] */
/* @0x121bd8 ldr r6, [lr, #0x4] */
/* @0x121bdc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x121be0 ldr r3, [r11, #-0x2c] */
/* @0x121be4 add lr, r3, r8 */
/* @0x121be8 vmov s13, r3 */
/* @0x121bec lsl lr, lr, r8 */
/* @0x121bf0 vcvt.f64.s32 d6, s13 */
/* @0x121bf4 vmov r2, r3, d6 */
/* @0x121bf8 str r0, [r6, #0x4] */
/* @0x121bfc mov r1, r3 */
/* @0x121c00 ldr r3, [r10] */
/* @0x121c04 ldr r2, [r3, #0x4] */
/* @0x121c08 ldr r3, [r2, #0x4] */
/* @0x121c0c str lr, [r2] */
/* @0x121c10 vstr s12, [r3] */
/* @0x121c14 str r1, [r3, #0x4] */
/* @0x121c18 ldr r2, [r10] */
/* @0x121c1c str r5, [r3, #0xc] */
/* @0x121c20 ldr r1, [r11, #-0x30] */
/* @0x121c24 ldr r3, [r2, #0x4] */
/* @0x121c28 ldr r3, [r3, #0x4] */
/* @0x121c2c add r0, r3, #16 */
/* @0x121c30 str r8, [r3, #0x1c] */
/* @0x121c34 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x121c38 ldr r8, [r11, #-0x2c] */
/* @0x121c3c cmp r8, r5 */
/* @0x121c40 ble 0x121b30 <_Z19F_SkeletonGetBoundsR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0x121c44 add r8, r7, r8, lsl #3 */
/* @0x121c48 add r0, r7, #4 */
/* @0x121c4c add r8, r8, #4 */
/* @0x121c50 mov r1, #32 */
/* @0x121c54 vldr s15, [r0, #-4] */
/* @0x121c58 vcvt.f64.f32 d6, s15 */
/* @0x121c5c ldr r6, [r10] */
/* @0x121c60 add r7, r1, #16 */
/* @0x121c64 ldr r6, [r6, #0x4] */
/* @0x121c68 vmov r2, r3, d6 */
/* @0x121c6c ldr r9, [r6, #0x4] */
/* @0x121c70 add r6, r9, r1 */
/* @0x121c74 str r5, [r6, #0xc] */
/* @0x121c78 str r2, [r9, r1] */
/* @0x121c7c mov r2, r0 */
/* @0x121c80 str r3, [r6, #0x4] */
/* @0x121c84 vldr s15, [r2] */
/* @0x121c88 vcvt.f64.f32 d6, s15 */
/* @0x121c8c ldr r3, [r10] */
/* @0x121c90 add r0, r0, #8 */
/* @0x121c94 add r1, r1, #32 */
/* @0x121c98 cmp r0, r8 */
/* @0x121c9c ldr r6, [r3, #0x4] */
/* @0x121ca0 ldr r9, [r6, #0x4] */
/* @0x121ca4 vmov r2, r3, d6 */
/* @0x121ca8 add r6, r9, r7 */
/* @0x121cac str r5, [r6, #0xc] */
/* @0x121cb0 str r2, [r9, r7] */
/* @0x121cb4 str r3, [r6, #0x4] */
/* @0x121cb8 bne 0x121c54 <_Z19F_SkeletonGetBoundsR6RValueP9CInstanceS2_iPS_+0x1c8> */
/* @0x121cbc b 0x121b30 <_Z19F_SkeletonGetBoundsR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0x121cc0 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x121cc4 .word 0x002cbeb0 */
/* @0x121cc8 eoreq sp, r0, r2, lsr #32 */
/* @0x121ccc mlaeq r0, r4, r4, pc */
/* @0x121cd0 eoreq r8, r1, r8, lsl #7 */

/* ── FUNC 0x121cd4 · YYGML_draw_set_font(int) · size=4 · insn=1 */
/* @0x121cd4 b 0x172ac8 <_Z16GR_Text_Set_Fonti> */

/* ── FUNC 0x121cd8 · YYGML_draw_set_halign(int) · size=4 · insn=1 */
/* @0x121cd8 b 0x172b30 <_Z18GR_Text_Set_HAligni> */

/* ── FUNC 0x121cdc · YYGML_draw_set_valign(int) · size=4 · insn=1 */
/* @0x121cdc b 0x172b7c <_Z18GR_Text_Set_VAligni> */

/* ── FUNC 0x121ce0 · GetTextFromArg(RValue const*, int, char**) · size=144 · insn=36 */
/* @0x121ce0 push {r4, r5, lr} */
/* @0x121ce4 mov r12, r1 */
/* @0x121ce8 mov r4, r0 */
/* @0x121cec mov r0, r1 */
/* @0x121cf0 ldr r1, [pc, #0x70] */
/* @0x121cf4 sub sp, sp, #28 */
/* @0x121cf8 mov r5, r2 */
/* @0x121cfc mov r3, #1 */
/* @0x121d00 add r1, pc, r1 */
/* @0x121d04 movw r2, #0x947 */
/* @0x121d08 str r12, [sp, #0xc] */
/* @0x121d0c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x121d10 mov r3, r4 */
/* @0x121d14 add r2, sp, #12 */
/* @0x121d18 mov r4, #0 */
/* @0x121d1c mov r1, r0 */
/* @0x121d20 add r0, sp, #24 */
/* @0x121d24 str r1, [sp, #0x10] */
/* @0x121d28 str r1, [r0, #-0x4]! */
/* @0x121d2c strb r4, [r1] */
/* @0x121d30 add r1, sp, #16 */
/* @0x121d34 bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue> */
/* @0x121d38 ldr r0, [sp, #0x10] */
/* @0x121d3c ldr r1, [sp, #0x14] */
/* @0x121d40 mov r3, #74 */
/* @0x121d44 ldr r2, [pc, #0x20] */
/* @0x121d48 rsb r1, r0, r1 */
/* @0x121d4c str r4, [sp] */
/* @0x121d50 add r1, r1, #1 */
/* @0x121d54 add r2, pc, r2 */
/* @0x121d58 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x121d5c str r0, [r5] */
/* @0x121d60 add sp, sp, #28 */
/* @0x121d64 pop {r4, r5, pc} */
/* @0x121d68 eoreq r8, r1, r0, asr r2 */
/* @0x121d6c .word 0x0020f2dc */

/* ── FUNC 0x121d70 · F_DrawText(RValue&, CInstance*, CInstance*, int, RValue*) · size=108 · insn=27 */
/* @0x121d70 push {r4, r5, lr} */
/* @0x121d74 sub sp, sp, #20 */
/* @0x121d78 add r2, sp, #16 */
/* @0x121d7c mov r5, #0 */
/* @0x121d80 ldr r4, [sp, #0x20] */
/* @0x121d84 mov r1, #1024 */
/* @0x121d88 str r5, [r2, #-0x4]! */
/* @0x121d8c add r0, r4, #32 */
/* @0x121d90 bl 0x121ce0 <_Z14GetTextFromArgPK6RValueiPPc> */
/* @0x121d94 mov r1, r5 */
/* @0x121d98 mov r0, r4 */
/* @0x121d9c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x121da0 mov r1, #1 */
/* @0x121da4 mov r5, r0 */
/* @0x121da8 mov r0, r4 */
/* @0x121dac bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x121db0 mvn r12, #0 */
/* @0x121db4 ldr r2, [sp, #0xc] */
/* @0x121db8 mov r3, r12 */
/* @0x121dbc str r12, [sp] */
/* @0x121dc0 mov r1, r0 */
/* @0x121dc4 mov r0, r5 */
/* @0x121dc8 bl 0x172df8 <_Z12GR_Text_DrawffPKcii> */
/* @0x121dcc ldr r0, [sp, #0xc] */
/* @0x121dd0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x121dd4 add sp, sp, #20 */
/* @0x121dd8 pop {r4, r5, pc} */

/* ── FUNC 0x121ddc · F_DrawTextTransformed(RValue&, CInstance*, CInstance*, int, RValue*) · size=168 · insn=42 */
/* @0x121ddc push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x121de0 sub sp, sp, #28 */
/* @0x121de4 add r2, sp, #24 */
/* @0x121de8 mov r5, #0 */
/* @0x121dec ldr r4, [sp, #0x38] */
/* @0x121df0 mov r1, #1024 */
/* @0x121df4 str r5, [r2, #-0x4]! */
/* @0x121df8 add r0, r4, #32 */
/* @0x121dfc bl 0x121ce0 <_Z14GetTextFromArgPK6RValueiPPc> */
/* @0x121e00 mov r1, r5 */
/* @0x121e04 mov r0, r4 */
/* @0x121e08 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x121e0c mov r1, #1 */
/* @0x121e10 mov r5, r0 */
/* @0x121e14 mov r0, r4 */
/* @0x121e18 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x121e1c mov r1, #3 */
/* @0x121e20 ldr r6, [sp, #0x14] */
/* @0x121e24 mov r7, r0 */
/* @0x121e28 mov r0, r4 */
/* @0x121e2c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x121e30 mov r1, #4 */
/* @0x121e34 mov r9, r0 */
/* @0x121e38 mov r0, r4 */
/* @0x121e3c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x121e40 mov r1, #5 */
/* @0x121e44 mov r8, r0 */
/* @0x121e48 mov r0, r4 */
/* @0x121e4c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x121e50 mvn r3, #0 */
/* @0x121e54 mov r1, r7 */
/* @0x121e58 mov r2, r6 */
/* @0x121e5c str r3, [sp] */
/* @0x121e60 str r9, [sp, #0x4] */
/* @0x121e64 str r8, [sp, #0x8] */
/* @0x121e68 str r0, [sp, #0xc] */
/* @0x121e6c mov r0, r5 */
/* @0x121e70 bl 0x173068 <_Z24GR_Text_Draw_TransformedffPKciifff> */
/* @0x121e74 ldr r0, [sp, #0x14] */
/* @0x121e78 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x121e7c add sp, sp, #28 */
/* @0x121e80 pop {r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x121e84 · F_DrawTextExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x121e84 push {r4, r5, r6, r7, r8, lr} */
/* @0x121e88 sub sp, sp, #16 */
/* @0x121e8c add r2, sp, #16 */
/* @0x121e90 mov r5, #0 */
/* @0x121e94 ldr r4, [sp, #0x28] */
/* @0x121e98 mov r1, #1024 */
/* @0x121e9c str r5, [r2, #-0x4]! */
/* @0x121ea0 add r0, r4, #32 */
/* @0x121ea4 bl 0x121ce0 <_Z14GetTextFromArgPK6RValueiPPc> */
/* @0x121ea8 mov r1, r5 */
/* @0x121eac mov r0, r4 */
/* @0x121eb0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x121eb4 mov r1, #1 */
/* @0x121eb8 mov r5, r0 */
/* @0x121ebc mov r0, r4 */
/* @0x121ec0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x121ec4 mov r1, #3 */
/* @0x121ec8 ldr r7, [sp, #0xc] */
/* @0x121ecc mov r8, r0 */
/* @0x121ed0 mov r0, r4 */
/* @0x121ed4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x121ed8 mov r1, #4 */
/* @0x121edc mov r6, r0 */
/* @0x121ee0 mov r0, r4 */
/* @0x121ee4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x121ee8 mov r1, r8 */
/* @0x121eec mov r2, r7 */
/* @0x121ef0 mov r3, r6 */
/* @0x121ef4 str r0, [sp] */
/* @0x121ef8 mov r0, r5 */
/* @0x121efc bl 0x172df8 <_Z12GR_Text_DrawffPKcii> */
/* @0x121f00 ldr r0, [sp, #0xc] */
/* @0x121f04 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x121f08 add sp, sp, #16 */
/* @0x121f0c pop {r4, r5, r6, r7, r8, pc} */
