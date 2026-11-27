/* libyoyo.so 覆盖卡组 0188
 * 函数 0x21012c..0x214858，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x21012c · Call_Real_std(int, double*, RValue*) · size=2444 · insn=611 */
/* @0x21012c ldr r12, [pc, #0x8fc] */
/* @0x210130 mov r3, r1 */
/* @0x210134 push {r4, r5, r6, lr} */
/* @0x210138 ldr r12, [pc, r12] */
/* @0x21013c mov r6, r2 */
/* @0x210140 sub sp, sp, #112 */
/* @0x210144 ldrb r2, [r12] */
/* @0x210148 cmp r2, #0 */
/* @0x21014c bne 0x210238 <_Z13Call_Real_stdiPdP6RValue+0x10c> */
/* @0x210150 ldr r1, [pc, #0x8dc] */
/* @0x210154 ldr r1, [pc, r1] */
/* @0x210158 ldr r12, [r1] */
/* @0x21015c cmp r0, r12 */
/* @0x210160 ldrlt r2, [r1, #0x4] */
/* @0x210164 ldrlt r2, [r2, r0, lsl #2] */
/* @0x210168 ldr r1, [r2, #0x5c] */
/* @0x21016c cmp r1, #0 */
/* @0x210170 str r1, [r6, #0xc] */
/* @0x210174 ldr r1, [r2, #0x14] */
/* @0x210178 sub r1, r1, #5 */
/* @0x21017c bne 0x210240 <_Z13Call_Real_stdiPdP6RValue+0x114> */
/* @0x210180 cmp r1, #11 */
/* @0x210184 addls pc, pc, r1, lsl #2 */
/* @0x210188 b 0x210238 <_Z13Call_Real_stdiPdP6RValue+0x10c> */
/* @0x21018c b 0x210760 <_Z13Call_Real_stdiPdP6RValue+0x634> */
/* @0x210190 b 0x210790 <_Z13Call_Real_stdiPdP6RValue+0x664> */
/* @0x210194 b 0x2107c8 <_Z13Call_Real_stdiPdP6RValue+0x69c> */
/* @0x210198 b 0x210808 <_Z13Call_Real_stdiPdP6RValue+0x6dc> */
/* @0x21019c b 0x210850 <_Z13Call_Real_stdiPdP6RValue+0x724> */
/* @0x2101a0 b 0x2108a0 <_Z13Call_Real_stdiPdP6RValue+0x774> */
/* @0x2101a4 b 0x2108f8 <_Z13Call_Real_stdiPdP6RValue+0x7cc> */
/* @0x2101a8 b 0x210958 <_Z13Call_Real_stdiPdP6RValue+0x82c> */
/* @0x2101ac b 0x2109c0 <_Z13Call_Real_stdiPdP6RValue+0x894> */
/* @0x2101b0 b 0x210a38 <_Z13Call_Real_stdiPdP6RValue+0x90c> */
/* @0x2101b4 b 0x2101bc <_Z13Call_Real_stdiPdP6RValue+0x90> */
/* @0x2101b8 b 0x21027c <_Z13Call_Real_stdiPdP6RValue+0x150> */
/* @0x2101bc ldrd r0, r1, [r3, #16] */
/* @0x2101c0 ldrd r4, r5, [r3, #24] */
/* @0x2101c4 strd r0, r1, [sp] */
/* @0x2101c8 strd r4, r5, [sp, #8] */
/* @0x2101cc ldrd r0, r1, [r3, #32] */
/* @0x2101d0 ldrd r4, r5, [r3, #40] */
/* @0x2101d4 strd r0, r1, [sp, #16] */
/* @0x2101d8 strd r4, r5, [sp, #24] */
/* @0x2101dc ldrd r0, r1, [r3, #48] */
/* @0x2101e0 ldrd r4, r5, [r3, #56] */
/* @0x2101e4 strd r0, r1, [sp, #32] */
/* @0x2101e8 strd r4, r5, [sp, #40] */
/* @0x2101ec ldrd r0, r1, [r3, #64] */
/* @0x2101f0 ldrd r4, r5, [r3, #72] */
/* @0x2101f4 strd r0, r1, [sp, #48] */
/* @0x2101f8 strd r4, r5, [sp, #56] */
/* @0x2101fc ldrd r0, r1, [r3, #80] */
/* @0x210200 ldrd r4, r5, [r3, #88] */
/* @0x210204 strd r0, r1, [sp, #64] */
/* @0x210208 strd r4, r5, [sp, #72] */
/* @0x21020c ldrd r0, r1, [r3, #96] */
/* @0x210210 ldrd r4, r5, [r3, #104] */
/* @0x210214 strd r0, r1, [sp, #80] */
/* @0x210218 strd r4, r5, [sp, #88] */
/* @0x21021c ldrd r4, r5, [r3, #112] */
/* @0x210220 ldrd r0, r1, [r3] */
/* @0x210224 strd r4, r5, [sp, #96] */
/* @0x210228 ldr r12, [r2, #0xc] */
/* @0x21022c ldrd r2, r3, [r3, #8] */
/* @0x210230 blx r12 */
/* @0x210234 stm r6, {r0, r1} */
/* @0x210238 add sp, sp, #112 */
/* @0x21023c pop {r4, r5, r6, pc} */
/* @0x210240 cmp r1, #11 */
/* @0x210244 addls pc, pc, r1, lsl #2 */
/* @0x210248 b 0x210ab0 <_Z13Call_Real_stdiPdP6RValue+0x984> */
/* @0x21024c b 0x210304 <_Z13Call_Real_stdiPdP6RValue+0x1d8> */
/* @0x210250 b 0x210340 <_Z13Call_Real_stdiPdP6RValue+0x214> */
/* @0x210254 b 0x210378 <_Z13Call_Real_stdiPdP6RValue+0x24c> */
/* @0x210258 b 0x2103b8 <_Z13Call_Real_stdiPdP6RValue+0x28c> */
/* @0x21025c b 0x210400 <_Z13Call_Real_stdiPdP6RValue+0x2d4> */
/* @0x210260 b 0x210450 <_Z13Call_Real_stdiPdP6RValue+0x324> */
/* @0x210264 b 0x2104a8 <_Z13Call_Real_stdiPdP6RValue+0x37c> */
/* @0x210268 b 0x210508 <_Z13Call_Real_stdiPdP6RValue+0x3dc> */
/* @0x21026c b 0x210570 <_Z13Call_Real_stdiPdP6RValue+0x444> */
/* @0x210270 b 0x2105e0 <_Z13Call_Real_stdiPdP6RValue+0x4b4> */
/* @0x210274 b 0x210658 <_Z13Call_Real_stdiPdP6RValue+0x52c> */
/* @0x210278 b 0x2106d8 <_Z13Call_Real_stdiPdP6RValue+0x5ac> */
/* @0x21027c ldrd r0, r1, [r3, #16] */
/* @0x210280 ldrd r4, r5, [r3, #24] */
/* @0x210284 strd r0, r1, [sp] */
/* @0x210288 strd r4, r5, [sp, #8] */
/* @0x21028c ldrd r0, r1, [r3, #32] */
/* @0x210290 ldrd r4, r5, [r3, #40] */
/* @0x210294 strd r0, r1, [sp, #16] */
/* @0x210298 strd r4, r5, [sp, #24] */
/* @0x21029c ldrd r0, r1, [r3, #48] */
/* @0x2102a0 ldrd r4, r5, [r3, #56] */
/* @0x2102a4 strd r0, r1, [sp, #32] */
/* @0x2102a8 strd r4, r5, [sp, #40] */
/* @0x2102ac ldrd r0, r1, [r3, #64] */
/* @0x2102b0 ldrd r4, r5, [r3, #72] */
/* @0x2102b4 strd r0, r1, [sp, #48] */
/* @0x2102b8 strd r4, r5, [sp, #56] */
/* @0x2102bc ldrd r0, r1, [r3, #80] */
/* @0x2102c0 ldrd r4, r5, [r3, #88] */
/* @0x2102c4 strd r0, r1, [sp, #64] */
/* @0x2102c8 strd r4, r5, [sp, #72] */
/* @0x2102cc ldrd r0, r1, [r3, #96] */
/* @0x2102d0 ldrd r4, r5, [r3, #104] */
/* @0x2102d4 strd r0, r1, [sp, #80] */
/* @0x2102d8 strd r4, r5, [sp, #88] */
/* @0x2102dc ldrd r0, r1, [r3, #112] */
/* @0x2102e0 ldrd r4, r5, [r3, #120] */
/* @0x2102e4 strd r0, r1, [sp, #96] */
/* @0x2102e8 strd r4, r5, [sp, #104] */
/* @0x2102ec ldrd r0, r1, [r3] */
/* @0x2102f0 ldr r12, [r2, #0xc] */
/* @0x2102f4 ldrd r2, r3, [r3, #8] */
/* @0x2102f8 blx r12 */
/* @0x2102fc stm r6, {r0, r1} */
/* @0x210300 b 0x210238 <_Z13Call_Real_stdiPdP6RValue+0x10c> */
/* @0x210304 ldrd r0, r1, [r3, #16] */
/* @0x210308 ldrd r4, r5, [r3, #24] */
/* @0x21030c strd r0, r1, [sp] */
/* @0x210310 strd r4, r5, [sp, #8] */
/* @0x210314 ldrd r4, r5, [r3, #32] */
/* @0x210318 ldrd r0, r1, [r3] */
/* @0x21031c strd r4, r5, [sp, #16] */
/* @0x210320 ldr r12, [r2, #0xc] */
/* @0x210324 ldrd r2, r3, [r3, #8] */
/* @0x210328 blx r12 */
/* @0x21032c mov r1, r0 */
/* @0x210330 mov r0, r6 */
/* @0x210334 add sp, sp, #112 */
/* @0x210338 pop {r4, r5, r6, lr} */
/* @0x21033c b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x210340 ldrd r0, r1, [r3, #16] */
/* @0x210344 ldrd r4, r5, [r3, #24] */
/* @0x210348 strd r0, r1, [sp] */
/* @0x21034c strd r4, r5, [sp, #8] */
/* @0x210350 ldrd r0, r1, [r3, #32] */
/* @0x210354 ldrd r4, r5, [r3, #40] */
/* @0x210358 strd r0, r1, [sp, #16] */
/* @0x21035c strd r4, r5, [sp, #24] */
/* @0x210360 ldrd r0, r1, [r3] */
/* @0x210364 ldr r12, [r2, #0xc] */
/* @0x210368 ldrd r2, r3, [r3, #8] */
/* @0x21036c blx r12 */
/* @0x210370 mov r1, r0 */
/* @0x210374 b 0x210330 <_Z13Call_Real_stdiPdP6RValue+0x204> */
/* @0x210378 ldrd r0, r1, [r3, #16] */
/* @0x21037c ldrd r4, r5, [r3, #24] */
/* @0x210380 strd r0, r1, [sp] */
/* @0x210384 strd r4, r5, [sp, #8] */
/* @0x210388 ldrd r0, r1, [r3, #32] */
/* @0x21038c ldrd r4, r5, [r3, #40] */
/* @0x210390 strd r0, r1, [sp, #16] */
/* @0x210394 strd r4, r5, [sp, #24] */
/* @0x210398 ldrd r4, r5, [r3, #48] */
/* @0x21039c ldrd r0, r1, [r3] */
/* @0x2103a0 strd r4, r5, [sp, #32] */
/* @0x2103a4 ldr r12, [r2, #0xc] */
/* @0x2103a8 ldrd r2, r3, [r3, #8] */
/* @0x2103ac blx r12 */
/* @0x2103b0 mov r1, r0 */
/* @0x2103b4 b 0x210330 <_Z13Call_Real_stdiPdP6RValue+0x204> */
/* @0x2103b8 ldrd r0, r1, [r3, #16] */
/* @0x2103bc ldrd r4, r5, [r3, #24] */
/* @0x2103c0 strd r0, r1, [sp] */
/* @0x2103c4 strd r4, r5, [sp, #8] */
/* @0x2103c8 ldrd r0, r1, [r3, #32] */
/* @0x2103cc ldrd r4, r5, [r3, #40] */
/* @0x2103d0 strd r0, r1, [sp, #16] */
/* @0x2103d4 strd r4, r5, [sp, #24] */
/* @0x2103d8 ldrd r0, r1, [r3, #48] */
/* @0x2103dc ldrd r4, r5, [r3, #56] */
/* @0x2103e0 strd r0, r1, [sp, #32] */
/* @0x2103e4 strd r4, r5, [sp, #40] */
/* @0x2103e8 ldrd r0, r1, [r3] */
/* @0x2103ec ldr r12, [r2, #0xc] */
/* @0x2103f0 ldrd r2, r3, [r3, #8] */
/* @0x2103f4 blx r12 */
/* @0x2103f8 mov r1, r0 */
/* @0x2103fc b 0x210330 <_Z13Call_Real_stdiPdP6RValue+0x204> */
/* @0x210400 ldrd r0, r1, [r3, #16] */
/* @0x210404 ldrd r4, r5, [r3, #24] */
/* @0x210408 strd r0, r1, [sp] */
/* @0x21040c strd r4, r5, [sp, #8] */
/* @0x210410 ldrd r0, r1, [r3, #32] */
/* @0x210414 ldrd r4, r5, [r3, #40] */
/* @0x210418 strd r0, r1, [sp, #16] */
/* @0x21041c strd r4, r5, [sp, #24] */
/* @0x210420 ldrd r0, r1, [r3, #48] */
/* @0x210424 ldrd r4, r5, [r3, #56] */
/* @0x210428 strd r0, r1, [sp, #32] */
/* @0x21042c strd r4, r5, [sp, #40] */
/* @0x210430 ldrd r4, r5, [r3, #64] */
/* @0x210434 ldrd r0, r1, [r3] */
/* @0x210438 strd r4, r5, [sp, #48] */
/* @0x21043c ldr r12, [r2, #0xc] */
/* @0x210440 ldrd r2, r3, [r3, #8] */
/* @0x210444 blx r12 */
/* @0x210448 mov r1, r0 */
/* @0x21044c b 0x210330 <_Z13Call_Real_stdiPdP6RValue+0x204> */
/* @0x210450 ldrd r0, r1, [r3, #16] */
/* @0x210454 ldrd r4, r5, [r3, #24] */
/* @0x210458 strd r0, r1, [sp] */
/* @0x21045c strd r4, r5, [sp, #8] */
/* @0x210460 ldrd r0, r1, [r3, #32] */
/* @0x210464 ldrd r4, r5, [r3, #40] */
/* @0x210468 strd r0, r1, [sp, #16] */
/* @0x21046c strd r4, r5, [sp, #24] */
/* @0x210470 ldrd r0, r1, [r3, #48] */
/* @0x210474 ldrd r4, r5, [r3, #56] */
/* @0x210478 strd r0, r1, [sp, #32] */
/* @0x21047c strd r4, r5, [sp, #40] */
/* @0x210480 ldrd r0, r1, [r3, #64] */
/* @0x210484 ldrd r4, r5, [r3, #72] */
/* @0x210488 strd r0, r1, [sp, #48] */
/* @0x21048c strd r4, r5, [sp, #56] */
/* @0x210490 ldrd r0, r1, [r3] */
/* @0x210494 ldr r12, [r2, #0xc] */
/* @0x210498 ldrd r2, r3, [r3, #8] */
/* @0x21049c blx r12 */
/* @0x2104a0 mov r1, r0 */
/* @0x2104a4 b 0x210330 <_Z13Call_Real_stdiPdP6RValue+0x204> */
/* @0x2104a8 ldrd r0, r1, [r3, #16] */
/* @0x2104ac ldrd r4, r5, [r3, #24] */
/* @0x2104b0 strd r0, r1, [sp] */
/* @0x2104b4 strd r4, r5, [sp, #8] */
/* @0x2104b8 ldrd r0, r1, [r3, #32] */
/* @0x2104bc ldrd r4, r5, [r3, #40] */
/* @0x2104c0 strd r0, r1, [sp, #16] */
/* @0x2104c4 strd r4, r5, [sp, #24] */
/* @0x2104c8 ldrd r0, r1, [r3, #48] */
/* @0x2104cc ldrd r4, r5, [r3, #56] */
/* @0x2104d0 strd r0, r1, [sp, #32] */
/* @0x2104d4 strd r4, r5, [sp, #40] */
/* @0x2104d8 ldrd r0, r1, [r3, #64] */
/* @0x2104dc ldrd r4, r5, [r3, #72] */
/* @0x2104e0 strd r0, r1, [sp, #48] */
/* @0x2104e4 strd r4, r5, [sp, #56] */
/* @0x2104e8 ldrd r4, r5, [r3, #80] */
/* @0x2104ec ldrd r0, r1, [r3] */
/* @0x2104f0 strd r4, r5, [sp, #64] */
/* @0x2104f4 ldr r12, [r2, #0xc] */
/* @0x2104f8 ldrd r2, r3, [r3, #8] */
/* @0x2104fc blx r12 */
/* @0x210500 mov r1, r0 */
/* @0x210504 b 0x210330 <_Z13Call_Real_stdiPdP6RValue+0x204> */
/* @0x210508 ldrd r0, r1, [r3, #16] */
/* @0x21050c ldrd r4, r5, [r3, #24] */
/* @0x210510 strd r0, r1, [sp] */
/* @0x210514 strd r4, r5, [sp, #8] */
/* @0x210518 ldrd r0, r1, [r3, #32] */
/* @0x21051c ldrd r4, r5, [r3, #40] */
/* @0x210520 strd r0, r1, [sp, #16] */
/* @0x210524 strd r4, r5, [sp, #24] */
/* @0x210528 ldrd r0, r1, [r3, #48] */
/* @0x21052c ldrd r4, r5, [r3, #56] */
/* @0x210530 strd r0, r1, [sp, #32] */
/* @0x210534 strd r4, r5, [sp, #40] */
/* @0x210538 ldrd r0, r1, [r3, #64] */
/* @0x21053c ldrd r4, r5, [r3, #72] */
/* @0x210540 strd r0, r1, [sp, #48] */
/* @0x210544 strd r4, r5, [sp, #56] */
/* @0x210548 ldrd r0, r1, [r3, #80] */
/* @0x21054c ldrd r4, r5, [r3, #88] */
/* @0x210550 strd r0, r1, [sp, #64] */
/* @0x210554 strd r4, r5, [sp, #72] */
/* @0x210558 ldrd r0, r1, [r3] */
/* @0x21055c ldr r12, [r2, #0xc] */
/* @0x210560 ldrd r2, r3, [r3, #8] */
/* @0x210564 blx r12 */
/* @0x210568 mov r1, r0 */
/* @0x21056c b 0x210330 <_Z13Call_Real_stdiPdP6RValue+0x204> */
/* @0x210570 ldrd r0, r1, [r3, #16] */
/* @0x210574 ldrd r4, r5, [r3, #24] */
/* @0x210578 strd r0, r1, [sp] */
/* @0x21057c strd r4, r5, [sp, #8] */
/* @0x210580 ldrd r0, r1, [r3, #32] */
/* @0x210584 ldrd r4, r5, [r3, #40] */
/* @0x210588 strd r0, r1, [sp, #16] */
/* @0x21058c strd r4, r5, [sp, #24] */
/* @0x210590 ldrd r0, r1, [r3, #48] */
/* @0x210594 ldrd r4, r5, [r3, #56] */
/* @0x210598 strd r0, r1, [sp, #32] */
/* @0x21059c strd r4, r5, [sp, #40] */
/* @0x2105a0 ldrd r0, r1, [r3, #64] */
/* @0x2105a4 ldrd r4, r5, [r3, #72] */
/* @0x2105a8 strd r0, r1, [sp, #48] */
/* @0x2105ac strd r4, r5, [sp, #56] */
/* @0x2105b0 ldrd r0, r1, [r3, #80] */
/* @0x2105b4 ldrd r4, r5, [r3, #88] */
/* @0x2105b8 strd r0, r1, [sp, #64] */
/* @0x2105bc strd r4, r5, [sp, #72] */
/* @0x2105c0 ldrd r4, r5, [r3, #96] */
/* @0x2105c4 ldrd r0, r1, [r3] */
/* @0x2105c8 strd r4, r5, [sp, #80] */
/* @0x2105cc ldr r12, [r2, #0xc] */
/* @0x2105d0 ldrd r2, r3, [r3, #8] */
/* @0x2105d4 blx r12 */
/* @0x2105d8 mov r1, r0 */
/* @0x2105dc b 0x210330 <_Z13Call_Real_stdiPdP6RValue+0x204> */
/* @0x2105e0 ldrd r0, r1, [r3, #16] */
/* @0x2105e4 ldrd r4, r5, [r3, #24] */
/* @0x2105e8 strd r0, r1, [sp] */
/* @0x2105ec strd r4, r5, [sp, #8] */
/* @0x2105f0 ldrd r0, r1, [r3, #32] */
/* @0x2105f4 ldrd r4, r5, [r3, #40] */
/* @0x2105f8 strd r0, r1, [sp, #16] */
/* @0x2105fc strd r4, r5, [sp, #24] */
/* @0x210600 ldrd r0, r1, [r3, #48] */
/* @0x210604 ldrd r4, r5, [r3, #56] */
/* @0x210608 strd r0, r1, [sp, #32] */
/* @0x21060c strd r4, r5, [sp, #40] */
/* @0x210610 ldrd r0, r1, [r3, #64] */
/* @0x210614 ldrd r4, r5, [r3, #72] */
/* @0x210618 strd r0, r1, [sp, #48] */
/* @0x21061c strd r4, r5, [sp, #56] */
/* @0x210620 ldrd r0, r1, [r3, #80] */
/* @0x210624 ldrd r4, r5, [r3, #88] */
/* @0x210628 strd r0, r1, [sp, #64] */
/* @0x21062c strd r4, r5, [sp, #72] */
/* @0x210630 ldrd r0, r1, [r3, #96] */
/* @0x210634 ldrd r4, r5, [r3, #104] */
/* @0x210638 strd r0, r1, [sp, #80] */
/* @0x21063c strd r4, r5, [sp, #88] */
/* @0x210640 ldrd r0, r1, [r3] */
/* @0x210644 ldr r12, [r2, #0xc] */
/* @0x210648 ldrd r2, r3, [r3, #8] */
/* @0x21064c blx r12 */
/* @0x210650 mov r1, r0 */
/* @0x210654 b 0x210330 <_Z13Call_Real_stdiPdP6RValue+0x204> */
/* @0x210658 ldrd r0, r1, [r3, #16] */
/* @0x21065c ldrd r4, r5, [r3, #24] */
/* @0x210660 strd r0, r1, [sp] */
/* @0x210664 strd r4, r5, [sp, #8] */
/* @0x210668 ldrd r0, r1, [r3, #32] */
/* @0x21066c ldrd r4, r5, [r3, #40] */
/* @0x210670 strd r0, r1, [sp, #16] */
/* @0x210674 strd r4, r5, [sp, #24] */
/* @0x210678 ldrd r0, r1, [r3, #48] */
/* @0x21067c ldrd r4, r5, [r3, #56] */
/* @0x210680 strd r0, r1, [sp, #32] */
/* @0x210684 strd r4, r5, [sp, #40] */
/* @0x210688 ldrd r0, r1, [r3, #64] */
/* @0x21068c ldrd r4, r5, [r3, #72] */
/* @0x210690 strd r0, r1, [sp, #48] */
/* @0x210694 strd r4, r5, [sp, #56] */
/* @0x210698 ldrd r0, r1, [r3, #80] */
/* @0x21069c ldrd r4, r5, [r3, #88] */
/* @0x2106a0 strd r0, r1, [sp, #64] */
/* @0x2106a4 strd r4, r5, [sp, #72] */
/* @0x2106a8 ldrd r0, r1, [r3, #96] */
/* @0x2106ac ldrd r4, r5, [r3, #104] */
/* @0x2106b0 strd r0, r1, [sp, #80] */
/* @0x2106b4 strd r4, r5, [sp, #88] */
/* @0x2106b8 ldrd r4, r5, [r3, #112] */
/* @0x2106bc ldrd r0, r1, [r3] */
/* @0x2106c0 strd r4, r5, [sp, #96] */
/* @0x2106c4 ldr r12, [r2, #0xc] */
/* @0x2106c8 ldrd r2, r3, [r3, #8] */
/* @0x2106cc blx r12 */
/* @0x2106d0 mov r1, r0 */
/* @0x2106d4 b 0x210330 <_Z13Call_Real_stdiPdP6RValue+0x204> */
/* @0x2106d8 ldrd r0, r1, [r3, #16] */
/* @0x2106dc ldrd r4, r5, [r3, #24] */
/* @0x2106e0 strd r0, r1, [sp] */
/* @0x2106e4 strd r4, r5, [sp, #8] */
/* @0x2106e8 ldrd r0, r1, [r3, #32] */
/* @0x2106ec ldrd r4, r5, [r3, #40] */
/* @0x2106f0 strd r0, r1, [sp, #16] */
/* @0x2106f4 strd r4, r5, [sp, #24] */
/* @0x2106f8 ldrd r0, r1, [r3, #48] */
/* @0x2106fc ldrd r4, r5, [r3, #56] */
/* @0x210700 strd r0, r1, [sp, #32] */
/* @0x210704 strd r4, r5, [sp, #40] */
/* @0x210708 ldrd r0, r1, [r3, #64] */
/* @0x21070c ldrd r4, r5, [r3, #72] */
/* @0x210710 strd r0, r1, [sp, #48] */
/* @0x210714 strd r4, r5, [sp, #56] */
/* @0x210718 ldrd r0, r1, [r3, #80] */
/* @0x21071c ldrd r4, r5, [r3, #88] */
/* @0x210720 strd r0, r1, [sp, #64] */
/* @0x210724 strd r4, r5, [sp, #72] */
/* @0x210728 ldrd r0, r1, [r3, #96] */
/* @0x21072c ldrd r4, r5, [r3, #104] */
/* @0x210730 strd r0, r1, [sp, #80] */
/* @0x210734 strd r4, r5, [sp, #88] */
/* @0x210738 ldrd r0, r1, [r3, #112] */
/* @0x21073c ldrd r4, r5, [r3, #120] */
/* @0x210740 strd r0, r1, [sp, #96] */
/* @0x210744 strd r4, r5, [sp, #104] */
/* @0x210748 ldrd r0, r1, [r3] */
/* @0x21074c ldr r12, [r2, #0xc] */
/* @0x210750 ldrd r2, r3, [r3, #8] */
/* @0x210754 blx r12 */
/* @0x210758 mov r1, r0 */
/* @0x21075c b 0x210330 <_Z13Call_Real_stdiPdP6RValue+0x204> */
/* @0x210760 ldrd r0, r1, [r3, #16] */
/* @0x210764 ldrd r4, r5, [r3, #24] */
/* @0x210768 strd r0, r1, [sp] */
/* @0x21076c strd r4, r5, [sp, #8] */
/* @0x210770 ldrd r4, r5, [r3, #32] */
/* @0x210774 ldrd r0, r1, [r3] */
/* @0x210778 strd r4, r5, [sp, #16] */
/* @0x21077c ldr r12, [r2, #0xc] */
/* @0x210780 ldrd r2, r3, [r3, #8] */
/* @0x210784 blx r12 */
/* @0x210788 stm r6, {r0, r1} */
/* @0x21078c b 0x210238 <_Z13Call_Real_stdiPdP6RValue+0x10c> */
/* @0x210790 ldrd r0, r1, [r3, #16] */
/* @0x210794 ldrd r4, r5, [r3, #24] */
/* @0x210798 strd r0, r1, [sp] */
/* @0x21079c strd r4, r5, [sp, #8] */
/* @0x2107a0 ldrd r0, r1, [r3, #32] */
/* @0x2107a4 ldrd r4, r5, [r3, #40] */
/* @0x2107a8 strd r0, r1, [sp, #16] */
/* @0x2107ac strd r4, r5, [sp, #24] */
/* @0x2107b0 ldrd r0, r1, [r3] */
/* @0x2107b4 ldr r12, [r2, #0xc] */
/* @0x2107b8 ldrd r2, r3, [r3, #8] */
/* @0x2107bc blx r12 */
/* @0x2107c0 stm r6, {r0, r1} */
/* @0x2107c4 b 0x210238 <_Z13Call_Real_stdiPdP6RValue+0x10c> */
/* @0x2107c8 ldrd r0, r1, [r3, #16] */
/* @0x2107cc ldrd r4, r5, [r3, #24] */
/* @0x2107d0 strd r0, r1, [sp] */
/* @0x2107d4 strd r4, r5, [sp, #8] */
/* @0x2107d8 ldrd r0, r1, [r3, #32] */
/* @0x2107dc ldrd r4, r5, [r3, #40] */
/* @0x2107e0 strd r0, r1, [sp, #16] */
/* @0x2107e4 strd r4, r5, [sp, #24] */
/* @0x2107e8 ldrd r4, r5, [r3, #48] */
/* @0x2107ec ldrd r0, r1, [r3] */
/* @0x2107f0 strd r4, r5, [sp, #32] */
/* @0x2107f4 ldr r12, [r2, #0xc] */
/* @0x2107f8 ldrd r2, r3, [r3, #8] */
/* @0x2107fc blx r12 */
/* @0x210800 stm r6, {r0, r1} */
/* @0x210804 b 0x210238 <_Z13Call_Real_stdiPdP6RValue+0x10c> */
/* @0x210808 ldrd r0, r1, [r3, #16] */
/* @0x21080c ldrd r4, r5, [r3, #24] */
/* @0x210810 strd r0, r1, [sp] */
/* @0x210814 strd r4, r5, [sp, #8] */
/* @0x210818 ldrd r0, r1, [r3, #32] */
/* @0x21081c ldrd r4, r5, [r3, #40] */
/* @0x210820 strd r0, r1, [sp, #16] */
/* @0x210824 strd r4, r5, [sp, #24] */
/* @0x210828 ldrd r0, r1, [r3, #48] */
/* @0x21082c ldrd r4, r5, [r3, #56] */
/* @0x210830 strd r0, r1, [sp, #32] */
/* @0x210834 strd r4, r5, [sp, #40] */
/* @0x210838 ldrd r0, r1, [r3] */
/* @0x21083c ldr r12, [r2, #0xc] */
/* @0x210840 ldrd r2, r3, [r3, #8] */
/* @0x210844 blx r12 */
/* @0x210848 stm r6, {r0, r1} */
/* @0x21084c b 0x210238 <_Z13Call_Real_stdiPdP6RValue+0x10c> */
/* @0x210850 ldrd r0, r1, [r3, #16] */
/* @0x210854 ldrd r4, r5, [r3, #24] */
/* @0x210858 strd r0, r1, [sp] */
/* @0x21085c strd r4, r5, [sp, #8] */
/* @0x210860 ldrd r0, r1, [r3, #32] */
/* @0x210864 ldrd r4, r5, [r3, #40] */
/* @0x210868 strd r0, r1, [sp, #16] */
/* @0x21086c strd r4, r5, [sp, #24] */
/* @0x210870 ldrd r0, r1, [r3, #48] */
/* @0x210874 ldrd r4, r5, [r3, #56] */
/* @0x210878 strd r0, r1, [sp, #32] */
/* @0x21087c strd r4, r5, [sp, #40] */
/* @0x210880 ldrd r4, r5, [r3, #64] */
/* @0x210884 ldrd r0, r1, [r3] */
/* @0x210888 strd r4, r5, [sp, #48] */
/* @0x21088c ldr r12, [r2, #0xc] */
/* @0x210890 ldrd r2, r3, [r3, #8] */
/* @0x210894 blx r12 */
/* @0x210898 stm r6, {r0, r1} */
/* @0x21089c b 0x210238 <_Z13Call_Real_stdiPdP6RValue+0x10c> */
/* @0x2108a0 ldrd r0, r1, [r3, #16] */
/* @0x2108a4 ldrd r4, r5, [r3, #24] */
/* @0x2108a8 strd r0, r1, [sp] */
/* @0x2108ac strd r4, r5, [sp, #8] */
/* @0x2108b0 ldrd r0, r1, [r3, #32] */
/* @0x2108b4 ldrd r4, r5, [r3, #40] */
/* @0x2108b8 strd r0, r1, [sp, #16] */
/* @0x2108bc strd r4, r5, [sp, #24] */
/* @0x2108c0 ldrd r0, r1, [r3, #48] */
/* @0x2108c4 ldrd r4, r5, [r3, #56] */
/* @0x2108c8 strd r0, r1, [sp, #32] */
/* @0x2108cc strd r4, r5, [sp, #40] */
/* @0x2108d0 ldrd r0, r1, [r3, #64] */
/* @0x2108d4 ldrd r4, r5, [r3, #72] */
/* @0x2108d8 strd r0, r1, [sp, #48] */
/* @0x2108dc strd r4, r5, [sp, #56] */
/* @0x2108e0 ldrd r0, r1, [r3] */
/* @0x2108e4 ldr r12, [r2, #0xc] */
/* @0x2108e8 ldrd r2, r3, [r3, #8] */
/* @0x2108ec blx r12 */
/* @0x2108f0 stm r6, {r0, r1} */
/* @0x2108f4 b 0x210238 <_Z13Call_Real_stdiPdP6RValue+0x10c> */
/* @0x2108f8 ldrd r0, r1, [r3, #16] */
/* @0x2108fc ldrd r4, r5, [r3, #24] */
/* @0x210900 strd r0, r1, [sp] */
/* @0x210904 strd r4, r5, [sp, #8] */
/* @0x210908 ldrd r0, r1, [r3, #32] */
/* @0x21090c ldrd r4, r5, [r3, #40] */
/* @0x210910 strd r0, r1, [sp, #16] */
/* @0x210914 strd r4, r5, [sp, #24] */
/* @0x210918 ldrd r0, r1, [r3, #48] */
/* @0x21091c ldrd r4, r5, [r3, #56] */
/* @0x210920 strd r0, r1, [sp, #32] */
/* @0x210924 strd r4, r5, [sp, #40] */
/* @0x210928 ldrd r0, r1, [r3, #64] */
/* @0x21092c ldrd r4, r5, [r3, #72] */
/* @0x210930 strd r0, r1, [sp, #48] */
/* @0x210934 strd r4, r5, [sp, #56] */
/* @0x210938 ldrd r4, r5, [r3, #80] */
/* @0x21093c ldrd r0, r1, [r3] */
/* @0x210940 strd r4, r5, [sp, #64] */
/* @0x210944 ldr r12, [r2, #0xc] */
/* @0x210948 ldrd r2, r3, [r3, #8] */
/* @0x21094c blx r12 */
/* @0x210950 stm r6, {r0, r1} */
/* @0x210954 b 0x210238 <_Z13Call_Real_stdiPdP6RValue+0x10c> */
/* @0x210958 ldrd r0, r1, [r3, #16] */
/* @0x21095c ldrd r4, r5, [r3, #24] */
/* @0x210960 strd r0, r1, [sp] */
/* @0x210964 strd r4, r5, [sp, #8] */
/* @0x210968 ldrd r0, r1, [r3, #32] */
/* @0x21096c ldrd r4, r5, [r3, #40] */
/* @0x210970 strd r0, r1, [sp, #16] */
/* @0x210974 strd r4, r5, [sp, #24] */
/* @0x210978 ldrd r0, r1, [r3, #48] */
/* @0x21097c ldrd r4, r5, [r3, #56] */
/* @0x210980 strd r0, r1, [sp, #32] */
/* @0x210984 strd r4, r5, [sp, #40] */
/* @0x210988 ldrd r0, r1, [r3, #64] */
/* @0x21098c ldrd r4, r5, [r3, #72] */
/* @0x210990 strd r0, r1, [sp, #48] */
/* @0x210994 strd r4, r5, [sp, #56] */
/* @0x210998 ldrd r0, r1, [r3, #80] */
/* @0x21099c ldrd r4, r5, [r3, #88] */
/* @0x2109a0 strd r0, r1, [sp, #64] */
/* @0x2109a4 strd r4, r5, [sp, #72] */
/* @0x2109a8 ldrd r0, r1, [r3] */
/* @0x2109ac ldr r12, [r2, #0xc] */
/* @0x2109b0 ldrd r2, r3, [r3, #8] */
/* @0x2109b4 blx r12 */
/* @0x2109b8 stm r6, {r0, r1} */
/* @0x2109bc b 0x210238 <_Z13Call_Real_stdiPdP6RValue+0x10c> */
/* @0x2109c0 ldrd r0, r1, [r3, #16] */
/* @0x2109c4 ldrd r4, r5, [r3, #24] */
/* @0x2109c8 strd r0, r1, [sp] */
/* @0x2109cc strd r4, r5, [sp, #8] */
/* @0x2109d0 ldrd r0, r1, [r3, #32] */
/* @0x2109d4 ldrd r4, r5, [r3, #40] */
/* @0x2109d8 strd r0, r1, [sp, #16] */
/* @0x2109dc strd r4, r5, [sp, #24] */
/* @0x2109e0 ldrd r0, r1, [r3, #48] */
/* @0x2109e4 ldrd r4, r5, [r3, #56] */
/* @0x2109e8 strd r0, r1, [sp, #32] */
/* @0x2109ec strd r4, r5, [sp, #40] */
/* @0x2109f0 ldrd r0, r1, [r3, #64] */
/* @0x2109f4 ldrd r4, r5, [r3, #72] */
/* @0x2109f8 strd r0, r1, [sp, #48] */
/* @0x2109fc strd r4, r5, [sp, #56] */
/* @0x210a00 ldrd r0, r1, [r3, #80] */
/* @0x210a04 ldrd r4, r5, [r3, #88] */
/* @0x210a08 strd r0, r1, [sp, #64] */
/* @0x210a0c strd r4, r5, [sp, #72] */
/* @0x210a10 ldrd r4, r5, [r3, #96] */
/* @0x210a14 ldrd r0, r1, [r3] */
/* @0x210a18 strd r4, r5, [sp, #80] */
/* @0x210a1c ldr r12, [r2, #0xc] */
/* @0x210a20 ldrd r2, r3, [r3, #8] */
/* @0x210a24 blx r12 */
/* @0x210a28 stm r6, {r0, r1} */
/* @0x210a2c b 0x210238 <_Z13Call_Real_stdiPdP6RValue+0x10c> */
/* @0x210a30 andseq r1, lr, r4, ror r2 */
/* @0x210a34 andseq r1, lr, r12, asr r2 */
/* @0x210a38 ldrd r0, r1, [r3, #16] */
/* @0x210a3c ldrd r4, r5, [r3, #24] */
/* @0x210a40 strd r0, r1, [sp] */
/* @0x210a44 strd r4, r5, [sp, #8] */
/* @0x210a48 ldrd r0, r1, [r3, #32] */
/* @0x210a4c ldrd r4, r5, [r3, #40] */
/* @0x210a50 strd r0, r1, [sp, #16] */
/* @0x210a54 strd r4, r5, [sp, #24] */
/* @0x210a58 ldrd r0, r1, [r3, #48] */
/* @0x210a5c ldrd r4, r5, [r3, #56] */
/* @0x210a60 strd r0, r1, [sp, #32] */
/* @0x210a64 strd r4, r5, [sp, #40] */
/* @0x210a68 ldrd r0, r1, [r3, #64] */
/* @0x210a6c ldrd r4, r5, [r3, #72] */
/* @0x210a70 strd r0, r1, [sp, #48] */
/* @0x210a74 strd r4, r5, [sp, #56] */
/* @0x210a78 ldrd r0, r1, [r3, #80] */
/* @0x210a7c ldrd r4, r5, [r3, #88] */
/* @0x210a80 strd r0, r1, [sp, #64] */
/* @0x210a84 strd r4, r5, [sp, #72] */
/* @0x210a88 ldrd r0, r1, [r3, #96] */
/* @0x210a8c ldrd r4, r5, [r3, #104] */
/* @0x210a90 strd r0, r1, [sp, #80] */
/* @0x210a94 strd r4, r5, [sp, #88] */
/* @0x210a98 ldrd r0, r1, [r3] */
/* @0x210a9c ldr r12, [r2, #0xc] */
/* @0x210aa0 ldrd r2, r3, [r3, #8] */
/* @0x210aa4 blx r12 */
/* @0x210aa8 stm r6, {r0, r1} */
/* @0x210aac b 0x210238 <_Z13Call_Real_stdiPdP6RValue+0x10c> */
/* @0x210ab0 mov r1, #0 */
/* @0x210ab4 b 0x210330 <_Z13Call_Real_stdiPdP6RValue+0x204> */

/* ── FUNC 0x210ab8 · Call_Normal_std(int, double*, char const**, RValue*) · size=2916 · insn=729 */
/* @0x210ab8 ldr r12, [pc, #0xb54] */
/* @0x210abc push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x210ac0 ldr r12, [pc, r12] */
/* @0x210ac4 sub sp, sp, #20 */
/* @0x210ac8 mov r4, r1 */
/* @0x210acc ldrb r12, [r12] */
/* @0x210ad0 mov r7, r2 */
/* @0x210ad4 mov r6, r3 */
/* @0x210ad8 cmp r12, #0 */
/* @0x210adc bne 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x210ae0 ldr r3, [pc, #0xb30] */
/* @0x210ae4 ldr r3, [pc, r3] */
/* @0x210ae8 ldr r2, [r3] */
/* @0x210aec cmp r0, r2 */
/* @0x210af0 ldrlt r3, [r3, #0x4] */
/* @0x210af4 ldrlt r12, [r3, r0, lsl #2] */
/* @0x210af8 ldr r1, [r12, #0x5c] */
/* @0x210afc ldr r2, [r12, #0x14] */
/* @0x210b00 cmp r1, #0 */
/* @0x210b04 movne r3, #2 */
/* @0x210b08 moveq r3, #1 */
/* @0x210b0c cmp r2, #0 */
/* @0x210b10 ble 0x210b74 <_Z15Call_Normal_stdiPdPPKcP6RValue+0xbc> */
/* @0x210b14 ldr r0, [r12, #0x18] */
/* @0x210b18 cmp r0, #0 */
/* @0x210b1c addeq r3, r3, #10 */
/* @0x210b20 addne r3, r3, #20 */
/* @0x210b24 cmp r2, #1 */
/* @0x210b28 beq 0x210b74 <_Z15Call_Normal_stdiPdPPKcP6RValue+0xbc> */
/* @0x210b2c ldr r0, [r12, #0x1c] */
/* @0x210b30 cmp r0, #0 */
/* @0x210b34 addeq r3, r3, #100 */
/* @0x210b38 addne r3, r3, #200 */
/* @0x210b3c cmp r2, #2 */
/* @0x210b40 beq 0x210b74 <_Z15Call_Normal_stdiPdPPKcP6RValue+0xbc> */
/* @0x210b44 ldr r0, [r12, #0x20] */
/* @0x210b48 cmp r0, #0 */
/* @0x210b4c addeq r3, r3, #1000 */
/* @0x210b50 addne r3, r3, #2000 */
/* @0x210b54 cmp r2, #3 */
/* @0x210b58 beq 0x210b74 <_Z15Call_Normal_stdiPdPPKcP6RValue+0xbc> */
/* @0x210b5c ldr r2, [r12, #0x24] */
/* @0x210b60 cmp r2, #0 */
/* @0x210b64 addeq r3, r3, #9984 */
/* @0x210b68 addne r3, r3, #19968 */
/* @0x210b6c addeq r3, r3, #16 */
/* @0x210b70 addne r3, r3, #32 */
/* @0x210b74 movw r2, #0x2b67 */
/* @0x210b78 cmp r3, r2 */
/* @0x210b7c str r1, [r6, #0xc] */
/* @0x210b80 beq 0x211464 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x9ac> */
/* @0x210b84 ble 0x210c28 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x170> */
/* @0x210b88 movw r2, #0x5277 */
/* @0x210b8c cmp r3, r2 */
/* @0x210b90 beq 0x21148c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x9d4> */
/* @0x210b94 bgt 0x210ca0 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x1e8> */
/* @0x210b98 movw r2, #0x2f4f */
/* @0x210b9c cmp r3, r2 */
/* @0x210ba0 beq 0x21119c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x6e4> */
/* @0x210ba4 bgt 0x210da4 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x2ec> */
/* @0x210ba8 sub r2, r2, #900 */
/* @0x210bac cmp r3, r2 */
/* @0x210bb0 beq 0x2110d4 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x61c> */
/* @0x210bb4 bgt 0x210fe8 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x530> */
/* @0x210bb8 movw r2, #0x2b71 */
/* @0x210bbc cmp r3, r2 */
/* @0x210bc0 beq 0x21141c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x964> */
/* @0x210bc4 add r2, r2, #1 */
/* @0x210bc8 cmp r3, r2 */
/* @0x210bcc beq 0x2113f4 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x93c> */
/* @0x210bd0 movw r2, #0x2b68 */
/* @0x210bd4 cmp r3, r2 */
/* @0x210bd8 bne 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x210bdc ldrd r2, r3, [r4, #16] */
/* @0x210be0 ldrd r0, r1, [r4, #24] */
/* @0x210be4 strd r2, r3, [sp] */
/* @0x210be8 strd r0, r1, [sp, #8] */
/* @0x210bec ldrd r0, r1, [r4] */
/* @0x210bf0 ldr r12, [r12, #0xc] */
/* @0x210bf4 ldrd r2, r3, [r4, #8] */
/* @0x210bf8 blx r12 */
/* @0x210bfc mov r1, r0 */
/* @0x210c00 b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x210c04 ldr lr, [r7, #0xc] */
/* @0x210c08 ldrd r0, r1, [r4] */
/* @0x210c0c ldmib r7, {r2, r3} */
/* @0x210c10 str lr, [sp] */
/* @0x210c14 ldr r12, [r12, #0xc] */
/* @0x210c18 blx r12 */
/* @0x210c1c stm r6, {r0, r1} */
/* @0x210c20 add sp, sp, #20 */
/* @0x210c24 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x210c28 movw r2, #0x457 */
/* @0x210c2c cmp r3, r2 */
/* @0x210c30 beq 0x2114b4 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x9fc> */
/* @0x210c34 ble 0x210d0c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x254> */
/* @0x210c38 movw r2, #0x83f */
/* @0x210c3c cmp r3, r2 */
/* @0x210c40 beq 0x211444 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x98c> */
/* @0x210c44 cmp r3, #2112 */
/* @0x210c48 bge 0x210d54 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x29c> */
/* @0x210c4c sub r2, r2, #900 */
/* @0x210c50 cmp r3, r2 */
/* @0x210c54 beq 0x2110b4 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x5fc> */
/* @0x210c58 bgt 0x210f58 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x4a0> */
/* @0x210c5c movw r2, #0x461 */
/* @0x210c60 cmp r3, r2 */
/* @0x210c64 beq 0x211384 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x8cc> */
/* @0x210c68 add r2, r2, #1 */
/* @0x210c6c cmp r3, r2 */
/* @0x210c70 beq 0x211364 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x8ac> */
/* @0x210c74 movw r2, #0x458 */
/* @0x210c78 cmp r3, r2 */
/* @0x210c7c bne 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x210c80 ldrd r2, r3, [r4, #16] */
/* @0x210c84 ldrd r0, r1, [r4] */
/* @0x210c88 strd r2, r3, [sp] */
/* @0x210c8c ldr r12, [r12, #0xc] */
/* @0x210c90 ldrd r2, r3, [r4, #8] */
/* @0x210c94 blx r12 */
/* @0x210c98 mov r1, r0 */
/* @0x210c9c b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x210ca0 movw r2, #0x565f */
/* @0x210ca4 cmp r3, r2 */
/* @0x210ca8 beq 0x211204 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x74c> */
/* @0x210cac bgt 0x210e00 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x348> */
/* @0x210cb0 sub r2, r2, #900 */
/* @0x210cb4 cmp r3, r2 */
/* @0x210cb8 beq 0x211110 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x658> */
/* @0x210cbc bgt 0x210f9c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x4e4> */
/* @0x210cc0 movw r2, #0x5281 */
/* @0x210cc4 cmp r3, r2 */
/* @0x210cc8 beq 0x2113cc <_Z15Call_Normal_stdiPdPPKcP6RValue+0x914> */
/* @0x210ccc add r2, r2, #1 */
/* @0x210cd0 cmp r3, r2 */
/* @0x210cd4 beq 0x2113a4 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x8ec> */
/* @0x210cd8 movw r2, #0x5278 */
/* @0x210cdc cmp r3, r2 */
/* @0x210ce0 bne 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x210ce4 ldrd r2, r3, [r4, #16] */
/* @0x210ce8 ldr lr, [r7, #0xc] */
/* @0x210cec ldrd r0, r1, [r4] */
/* @0x210cf0 strd r2, r3, [sp] */
/* @0x210cf4 ldrd r2, r3, [r4, #8] */
/* @0x210cf8 str lr, [sp, #0x8] */
/* @0x210cfc ldr r12, [r12, #0xc] */
/* @0x210d00 blx r12 */
/* @0x210d04 mov r1, r0 */
/* @0x210d08 b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x210d0c cmp r3, #111 */
/* @0x210d10 beq 0x21116c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x6b4> */
/* @0x210d14 ble 0x210e58 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3a0> */
/* @0x210d18 cmp r3, #211 */
/* @0x210d1c beq 0x211228 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x770> */
/* @0x210d20 bgt 0x210f28 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x470> */
/* @0x210d24 cmp r3, #121 */
/* @0x210d28 beq 0x2114ec <_Z15Call_Normal_stdiPdPPKcP6RValue+0xa34> */
/* @0x210d2c cmp r3, #122 */
/* @0x210d30 beq 0x2114d4 <_Z15Call_Normal_stdiPdPPKcP6RValue+0xa1c> */
/* @0x210d34 cmp r3, #112 */
/* @0x210d38 bne 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x210d3c ldrd r0, r1, [r4] */
/* @0x210d40 ldr r12, [r12, #0xc] */
/* @0x210d44 ldrd r2, r3, [r4, #8] */
/* @0x210d48 blx r12 */
/* @0x210d4c mov r1, r0 */
/* @0x210d50 b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x210d54 movw r2, #0x8a3 */
/* @0x210d58 cmp r3, r2 */
/* @0x210d5c beq 0x211184 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x6cc> */
/* @0x210d60 bgt 0x210eec <_Z15Call_Normal_stdiPdPPKcP6RValue+0x434> */
/* @0x210d64 movw r2, #0x849 */
/* @0x210d68 cmp r3, r2 */
/* @0x210d6c beq 0x2111e4 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x72c> */
/* @0x210d70 add r2, r2, #1 */
/* @0x210d74 cmp r3, r2 */
/* @0x210d78 beq 0x2111c4 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x70c> */
/* @0x210d7c cmp r3, #2112 */
/* @0x210d80 bne 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x210d84 ldr lr, [r7, #0x8] */
/* @0x210d88 ldrd r0, r1, [r4] */
/* @0x210d8c ldrd r2, r3, [r4, #8] */
/* @0x210d90 str lr, [sp] */
/* @0x210d94 ldr r12, [r12, #0xc] */
/* @0x210d98 blx r12 */
/* @0x210d9c mov r1, r0 */
/* @0x210da0 b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x210da4 movw r2, #0x2fb3 */
/* @0x210da8 cmp r3, r2 */
/* @0x210dac beq 0x211148 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x690> */
/* @0x210db0 bgt 0x210ea4 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3ec> */
/* @0x210db4 movw r2, #0x2f59 */
/* @0x210db8 cmp r3, r2 */
/* @0x210dbc beq 0x21133c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x884> */
/* @0x210dc0 add r2, r2, #1 */
/* @0x210dc4 cmp r3, r2 */
/* @0x210dc8 beq 0x211314 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x85c> */
/* @0x210dcc movw r2, #0x2f50 */
/* @0x210dd0 cmp r3, r2 */
/* @0x210dd4 bne 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x210dd8 ldrd r2, r3, [r4, #24] */
/* @0x210ddc ldr lr, [r7, #0x8] */
/* @0x210de0 ldrd r0, r1, [r4] */
/* @0x210de4 strd r2, r3, [sp, #8] */
/* @0x210de8 ldrd r2, r3, [r4, #8] */
/* @0x210dec str lr, [sp] */
/* @0x210df0 ldr r12, [r12, #0xc] */
/* @0x210df4 blx r12 */
/* @0x210df8 mov r1, r0 */
/* @0x210dfc b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x210e00 movw r2, #0x56c3 */
/* @0x210e04 cmp r3, r2 */
/* @0x210e08 beq 0x210c04 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x14c> */
/* @0x210e0c bgt 0x211034 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x57c> */
/* @0x210e10 movw r2, #0x5669 */
/* @0x210e14 cmp r3, r2 */
/* @0x210e18 beq 0x2112c4 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x80c> */
/* @0x210e1c add r2, r2, #1 */
/* @0x210e20 cmp r3, r2 */
/* @0x210e24 beq 0x21129c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x7e4> */
/* @0x210e28 movw r2, #0x5660 */
/* @0x210e2c cmp r3, r2 */
/* @0x210e30 bne 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x210e34 ldr r5, [r7, #0x8] */
/* @0x210e38 ldr lr, [r7, #0xc] */
/* @0x210e3c ldrd r0, r1, [r4] */
/* @0x210e40 ldrd r2, r3, [r4, #8] */
/* @0x210e44 stm sp, {r5, lr} */
/* @0x210e48 ldr r12, [r12, #0xc] */
/* @0x210e4c blx r12 */
/* @0x210e50 mov r1, r0 */
/* @0x210e54 b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x210e58 cmp r3, #11 */
/* @0x210e5c beq 0x211080 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x5c8> */
/* @0x210e60 ble 0x211094 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x5dc> */
/* @0x210e64 cmp r3, #21 */
/* @0x210e68 beq 0x211240 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x788> */
/* @0x210e6c cmp r3, #22 */
/* @0x210e70 beq 0x2110fc <_Z15Call_Normal_stdiPdPPKcP6RValue+0x644> */
/* @0x210e74 cmp r3, #12 */
/* @0x210e78 bne 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x210e7c ldrd r0, r1, [r4] */
/* @0x210e80 ldr r3, [r12, #0xc] */
/* @0x210e84 blx r3 */
/* @0x210e88 mov r1, r0 */
/* @0x210e8c cmp r1, #0 */
/* @0x210e90 beq 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x210e94 mov r0, r6 */
/* @0x210e98 add sp, sp, #20 */
/* @0x210e9c pop {r4, r5, r6, r7, r8, r9, lr} */
/* @0x210ea0 b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x210ea4 movw r2, #0x2fbd */
/* @0x210ea8 cmp r3, r2 */
/* @0x210eac beq 0x211550 <_Z15Call_Normal_stdiPdPPKcP6RValue+0xa98> */
/* @0x210eb0 add r2, r2, #1 */
/* @0x210eb4 cmp r3, r2 */
/* @0x210eb8 beq 0x21152c <_Z15Call_Normal_stdiPdPPKcP6RValue+0xa74> */
/* @0x210ebc movw r2, #0x2fb4 */
/* @0x210ec0 cmp r3, r2 */
/* @0x210ec4 bne 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x210ec8 ldrd r0, r1, [r4, #24] */
/* @0x210ecc ldr r2, [r7, #0x4] */
/* @0x210ed0 ldr r3, [r7, #0x8] */
/* @0x210ed4 strd r0, r1, [sp] */
/* @0x210ed8 ldrd r0, r1, [r4] */
/* @0x210edc ldr r12, [r12, #0xc] */
/* @0x210ee0 blx r12 */
/* @0x210ee4 mov r1, r0 */
/* @0x210ee8 b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x210eec movw r2, #0x8ad */
/* @0x210ef0 cmp r3, r2 */
/* @0x210ef4 beq 0x2115b8 <_Z15Call_Normal_stdiPdPPKcP6RValue+0xb00> */
/* @0x210ef8 add r2, r2, #1 */
/* @0x210efc cmp r3, r2 */
/* @0x210f00 beq 0x2115a4 <_Z15Call_Normal_stdiPdPPKcP6RValue+0xaec> */
/* @0x210f04 movw r2, #0x8a4 */
/* @0x210f08 cmp r3, r2 */
/* @0x210f0c bne 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x210f10 ldrd r0, r1, [r4] */
/* @0x210f14 ldr r12, [r12, #0xc] */
/* @0x210f18 ldmib r7, {r2, r3} */
/* @0x210f1c blx r12 */
/* @0x210f20 mov r1, r0 */
/* @0x210f24 b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x210f28 cmp r3, #221 */
/* @0x210f2c beq 0x211518 <_Z15Call_Normal_stdiPdPPKcP6RValue+0xa60> */
/* @0x210f30 cmp r3, #222 */
/* @0x210f34 beq 0x211504 <_Z15Call_Normal_stdiPdPPKcP6RValue+0xa4c> */
/* @0x210f38 cmp r3, #212 */
/* @0x210f3c bne 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x210f40 ldrd r0, r1, [r4] */
/* @0x210f44 ldr r3, [r12, #0xc] */
/* @0x210f48 ldr r2, [r7, #0x4] */
/* @0x210f4c blx r3 */
/* @0x210f50 mov r1, r0 */
/* @0x210f54 b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x210f58 movw r2, #0x4c5 */
/* @0x210f5c cmp r3, r2 */
/* @0x210f60 beq 0x21158c <_Z15Call_Normal_stdiPdPPKcP6RValue+0xad4> */
/* @0x210f64 add r2, r2, #1 */
/* @0x210f68 cmp r3, r2 */
/* @0x210f6c beq 0x211574 <_Z15Call_Normal_stdiPdPPKcP6RValue+0xabc> */
/* @0x210f70 movw r2, #0x4bc */
/* @0x210f74 cmp r3, r2 */
/* @0x210f78 bne 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x210f7c ldrd r8, r9, [r4, #16] */
/* @0x210f80 ldrd r0, r1, [r4] */
/* @0x210f84 ldr r2, [r7, #0x4] */
/* @0x210f88 strd r8, r9, [sp] */
/* @0x210f8c ldr r3, [r12, #0xc] */
/* @0x210f90 blx r3 */
/* @0x210f94 mov r1, r0 */
/* @0x210f98 b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x210f9c movw r2, #0x52e5 */
/* @0x210fa0 cmp r3, r2 */
/* @0x210fa4 beq 0x2115f4 <_Z15Call_Normal_stdiPdPPKcP6RValue+0xb3c> */
/* @0x210fa8 add r2, r2, #1 */
/* @0x210fac cmp r3, r2 */
/* @0x210fb0 beq 0x2115cc <_Z15Call_Normal_stdiPdPPKcP6RValue+0xb14> */
/* @0x210fb4 movw r2, #0x52dc */
/* @0x210fb8 cmp r3, r2 */
/* @0x210fbc bne 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x210fc0 ldr r3, [r7, #0xc] */
/* @0x210fc4 ldrd r0, r1, [r4, #16] */
/* @0x210fc8 ldr r2, [r7, #0x4] */
/* @0x210fcc strd r0, r1, [sp] */
/* @0x210fd0 ldrd r0, r1, [r4] */
/* @0x210fd4 str r3, [sp, #0x8] */
/* @0x210fd8 ldr r3, [r12, #0xc] */
/* @0x210fdc blx r3 */
/* @0x210fe0 mov r1, r0 */
/* @0x210fe4 b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x210fe8 movw r2, #0x2bd5 */
/* @0x210fec cmp r3, r2 */
/* @0x210ff0 beq 0x211278 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x7c0> */
/* @0x210ff4 add r2, r2, #1 */
/* @0x210ff8 cmp r3, r2 */
/* @0x210ffc beq 0x211254 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x79c> */
/* @0x211000 movw r2, #0x2bcc */
/* @0x211004 cmp r3, r2 */
/* @0x211008 bne 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x21100c ldrd r0, r1, [r4, #16] */
/* @0x211010 ldrd r8, r9, [r4, #24] */
/* @0x211014 ldr r2, [r7, #0x4] */
/* @0x211018 strd r0, r1, [sp] */
/* @0x21101c strd r8, r9, [sp, #8] */
/* @0x211020 ldrd r0, r1, [r4] */
/* @0x211024 ldr r3, [r12, #0xc] */
/* @0x211028 blx r3 */
/* @0x21102c mov r1, r0 */
/* @0x211030 b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x211034 movw r2, #0x56cd */
/* @0x211038 cmp r3, r2 */
/* @0x21103c beq 0x211300 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x848> */
/* @0x211040 add r2, r2, #1 */
/* @0x211044 cmp r3, r2 */
/* @0x211048 beq 0x2112ec <_Z15Call_Normal_stdiPdPPKcP6RValue+0x834> */
/* @0x21104c movw r2, #0x56c4 */
/* @0x211050 cmp r3, r2 */
/* @0x211054 bne 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x211058 ldrd r4, r5, [r4] */
/* @0x21105c ldr r1, [r7, #0xc] */
/* @0x211060 ldmib r7, {r2, r3} */
/* @0x211064 mov r0, r4 */
/* @0x211068 str r1, [sp] */
/* @0x21106c mov r1, r5 */
/* @0x211070 ldr r12, [r12, #0xc] */
/* @0x211074 blx r12 */
/* @0x211078 mov r1, r0 */
/* @0x21107c b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x211080 ldr r3, [r12, #0xc] */
/* @0x211084 ldrd r0, r1, [r4] */
/* @0x211088 blx r3 */
/* @0x21108c stm r6, {r0, r1} */
/* @0x211090 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x211094 cmp r3, #1 */
/* @0x211098 beq 0x211138 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x680> */
/* @0x21109c cmp r3, #2 */
/* @0x2110a0 bne 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x2110a4 ldr r3, [r12, #0xc] */
/* @0x2110a8 blx r3 */
/* @0x2110ac mov r1, r0 */
/* @0x2110b0 b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x2110b4 ldrd r8, r9, [r4, #16] */
/* @0x2110b8 ldr r2, [r7, #0x4] */
/* @0x2110bc ldrd r0, r1, [r4] */
/* @0x2110c0 strd r8, r9, [sp] */
/* @0x2110c4 ldr r3, [r12, #0xc] */
/* @0x2110c8 blx r3 */
/* @0x2110cc stm r6, {r0, r1} */
/* @0x2110d0 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x2110d4 ldrd r0, r1, [r4, #16] */
/* @0x2110d8 ldrd r8, r9, [r4, #24] */
/* @0x2110dc ldr r2, [r7, #0x4] */
/* @0x2110e0 strd r0, r1, [sp] */
/* @0x2110e4 strd r8, r9, [sp, #8] */
/* @0x2110e8 ldrd r0, r1, [r4] */
/* @0x2110ec ldr r3, [r12, #0xc] */
/* @0x2110f0 blx r3 */
/* @0x2110f4 stm r6, {r0, r1} */
/* @0x2110f8 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x2110fc ldr r3, [r12, #0xc] */
/* @0x211100 ldr r0, [r7] */
/* @0x211104 blx r3 */
/* @0x211108 mov r1, r0 */
/* @0x21110c b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x211110 ldr r3, [r7, #0xc] */
/* @0x211114 ldrd r0, r1, [r4, #16] */
/* @0x211118 ldr r2, [r7, #0x4] */
/* @0x21111c strd r0, r1, [sp] */
/* @0x211120 ldrd r0, r1, [r4] */
/* @0x211124 str r3, [sp, #0x8] */
/* @0x211128 ldr r3, [r12, #0xc] */
/* @0x21112c blx r3 */
/* @0x211130 stm r6, {r0, r1} */
/* @0x211134 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x211138 ldr r3, [r12, #0xc] */
/* @0x21113c blx r3 */
/* @0x211140 stm r6, {r0, r1} */
/* @0x211144 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x211148 ldrd r0, r1, [r4, #24] */
/* @0x21114c ldr r2, [r7, #0x4] */
/* @0x211150 ldr r3, [r7, #0x8] */
/* @0x211154 strd r0, r1, [sp] */
/* @0x211158 ldrd r0, r1, [r4] */
/* @0x21115c ldr r12, [r12, #0xc] */
/* @0x211160 blx r12 */
/* @0x211164 stm r6, {r0, r1} */
/* @0x211168 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x21116c ldr r12, [r12, #0xc] */
/* @0x211170 ldrd r0, r1, [r4] */
/* @0x211174 ldrd r2, r3, [r4, #8] */
/* @0x211178 blx r12 */
/* @0x21117c stm r6, {r0, r1} */
/* @0x211180 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x211184 ldr r12, [r12, #0xc] */
/* @0x211188 ldrd r0, r1, [r4] */
/* @0x21118c ldmib r7, {r2, r3} */
/* @0x211190 blx r12 */
/* @0x211194 stm r6, {r0, r1} */
/* @0x211198 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x21119c ldrd r2, r3, [r4, #24] */
/* @0x2111a0 ldr lr, [r7, #0x8] */
/* @0x2111a4 ldrd r0, r1, [r4] */
/* @0x2111a8 strd r2, r3, [sp, #8] */
/* @0x2111ac ldrd r2, r3, [r4, #8] */
/* @0x2111b0 str lr, [sp] */
/* @0x2111b4 ldr r12, [r12, #0xc] */
/* @0x2111b8 blx r12 */
/* @0x2111bc stm r6, {r0, r1} */
/* @0x2111c0 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x2111c4 ldr r1, [r7, #0x8] */
/* @0x2111c8 ldrd r2, r3, [r4, #8] */
/* @0x2111cc ldr r0, [r7] */
/* @0x2111d0 str r1, [sp] */
/* @0x2111d4 ldr r1, [r12, #0xc] */
/* @0x2111d8 blx r1 */
/* @0x2111dc mov r1, r0 */
/* @0x2111e0 b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x2111e4 ldr r1, [r7, #0x8] */
/* @0x2111e8 ldrd r2, r3, [r4, #8] */
/* @0x2111ec ldr r0, [r7] */
/* @0x2111f0 str r1, [sp] */
/* @0x2111f4 ldr r1, [r12, #0xc] */
/* @0x2111f8 blx r1 */
/* @0x2111fc stm r6, {r0, r1} */
/* @0x211200 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x211204 ldr r5, [r7, #0x8] */
/* @0x211208 ldr lr, [r7, #0xc] */
/* @0x21120c ldrd r0, r1, [r4] */
/* @0x211210 ldrd r2, r3, [r4, #8] */
/* @0x211214 stm sp, {r5, lr} */
/* @0x211218 ldr r12, [r12, #0xc] */
/* @0x21121c blx r12 */
/* @0x211220 stm r6, {r0, r1} */
/* @0x211224 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x211228 ldr r3, [r12, #0xc] */
/* @0x21122c ldr r2, [r7, #0x4] */
/* @0x211230 ldrd r0, r1, [r4] */
/* @0x211234 blx r3 */
/* @0x211238 stm r6, {r0, r1} */
/* @0x21123c b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x211240 ldr r3, [r12, #0xc] */
/* @0x211244 ldr r0, [r7] */
/* @0x211248 blx r3 */
/* @0x21124c stm r6, {r0, r1} */
/* @0x211250 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x211254 ldrd r2, r3, [r4, #24] */
/* @0x211258 ldr r1, [r7, #0x4] */
/* @0x21125c ldr r0, [r7] */
/* @0x211260 strd r2, r3, [sp] */
/* @0x211264 ldrd r2, r3, [r4, #16] */
/* @0x211268 ldr r12, [r12, #0xc] */
/* @0x21126c blx r12 */
/* @0x211270 mov r1, r0 */
/* @0x211274 b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x211278 ldrd r2, r3, [r4, #24] */
/* @0x21127c ldr r0, [r7] */
/* @0x211280 ldr r1, [r7, #0x4] */
/* @0x211284 strd r2, r3, [sp] */
/* @0x211288 ldrd r2, r3, [r4, #16] */
/* @0x21128c ldr r12, [r12, #0xc] */
/* @0x211290 blx r12 */
/* @0x211294 stm r6, {r0, r1} */
/* @0x211298 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x21129c ldr r1, [r7, #0xc] */
/* @0x2112a0 ldr lr, [r7, #0x8] */
/* @0x2112a4 ldrd r2, r3, [r4, #8] */
/* @0x2112a8 ldr r0, [r7] */
/* @0x2112ac str lr, [sp] */
/* @0x2112b0 str r1, [sp, #0x4] */
/* @0x2112b4 ldr r1, [r12, #0xc] */
/* @0x2112b8 blx r1 */
/* @0x2112bc mov r1, r0 */
/* @0x2112c0 b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x2112c4 ldr r1, [r7, #0xc] */
/* @0x2112c8 ldr lr, [r7, #0x8] */
/* @0x2112cc ldrd r2, r3, [r4, #8] */
/* @0x2112d0 ldr r0, [r7] */
/* @0x2112d4 str lr, [sp] */
/* @0x2112d8 str r1, [sp, #0x4] */
/* @0x2112dc ldr r1, [r12, #0xc] */
/* @0x2112e0 blx r1 */
/* @0x2112e4 stm r6, {r0, r1} */
/* @0x2112e8 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x2112ec ldm r7, {r0, r1, r2, r3} */
/* @0x2112f0 ldr r12, [r12, #0xc] */
/* @0x2112f4 blx r12 */
/* @0x2112f8 mov r1, r0 */
/* @0x2112fc b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x211300 ldr r12, [r12, #0xc] */
/* @0x211304 ldm r7, {r0, r1, r2, r3} */
/* @0x211308 blx r12 */
/* @0x21130c stm r6, {r0, r1} */
/* @0x211310 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x211314 ldr r1, [r7, #0x8] */
/* @0x211318 ldrd r2, r3, [r4, #24] */
/* @0x21131c ldr r0, [r7] */
/* @0x211320 strd r2, r3, [sp, #8] */
/* @0x211324 ldrd r2, r3, [r4, #8] */
/* @0x211328 str r1, [sp] */
/* @0x21132c ldr r1, [r12, #0xc] */
/* @0x211330 blx r1 */
/* @0x211334 mov r1, r0 */
/* @0x211338 b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x21133c ldr r1, [r7, #0x8] */
/* @0x211340 ldrd r2, r3, [r4, #24] */
/* @0x211344 ldr r0, [r7] */
/* @0x211348 strd r2, r3, [sp, #8] */
/* @0x21134c ldrd r2, r3, [r4, #8] */
/* @0x211350 str r1, [sp] */
/* @0x211354 ldr r1, [r12, #0xc] */
/* @0x211358 blx r1 */
/* @0x21135c stm r6, {r0, r1} */
/* @0x211360 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x211364 ldrd r8, r9, [r4, #16] */
/* @0x211368 ldr r0, [r7] */
/* @0x21136c ldrd r2, r3, [r4, #8] */
/* @0x211370 strd r8, r9, [sp] */
/* @0x211374 ldr r1, [r12, #0xc] */
/* @0x211378 blx r1 */
/* @0x21137c mov r1, r0 */
/* @0x211380 b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x211384 ldrd r8, r9, [r4, #16] */
/* @0x211388 ldr r0, [r7] */
/* @0x21138c ldrd r2, r3, [r4, #8] */
/* @0x211390 strd r8, r9, [sp] */
/* @0x211394 ldr r1, [r12, #0xc] */
/* @0x211398 blx r1 */
/* @0x21139c stm r6, {r0, r1} */
/* @0x2113a0 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x2113a4 ldr r1, [r7, #0xc] */
/* @0x2113a8 ldrd r2, r3, [r4, #16] */
/* @0x2113ac ldr r0, [r7] */
/* @0x2113b0 strd r2, r3, [sp] */
/* @0x2113b4 ldrd r2, r3, [r4, #8] */
/* @0x2113b8 str r1, [sp, #0x8] */
/* @0x2113bc ldr r1, [r12, #0xc] */
/* @0x2113c0 blx r1 */
/* @0x2113c4 mov r1, r0 */
/* @0x2113c8 b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x2113cc ldr r1, [r7, #0xc] */
/* @0x2113d0 ldrd r2, r3, [r4, #16] */
/* @0x2113d4 ldr r0, [r7] */
/* @0x2113d8 strd r2, r3, [sp] */
/* @0x2113dc ldrd r2, r3, [r4, #8] */
/* @0x2113e0 str r1, [sp, #0x8] */
/* @0x2113e4 ldr r1, [r12, #0xc] */
/* @0x2113e8 blx r1 */
/* @0x2113ec stm r6, {r0, r1} */
/* @0x2113f0 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x2113f4 ldrd r2, r3, [r4, #16] */
/* @0x2113f8 ldrd r8, r9, [r4, #24] */
/* @0x2113fc ldr r0, [r7] */
/* @0x211400 strd r2, r3, [sp] */
/* @0x211404 strd r8, r9, [sp, #8] */
/* @0x211408 ldr r1, [r12, #0xc] */
/* @0x21140c ldrd r2, r3, [r4, #8] */
/* @0x211410 blx r1 */
/* @0x211414 mov r1, r0 */
/* @0x211418 b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x21141c ldrd r2, r3, [r4, #16] */
/* @0x211420 ldrd r8, r9, [r4, #24] */
/* @0x211424 ldr r0, [r7] */
/* @0x211428 strd r2, r3, [sp] */
/* @0x21142c strd r8, r9, [sp, #8] */
/* @0x211430 ldrd r2, r3, [r4, #8] */
/* @0x211434 ldr r1, [r12, #0xc] */
/* @0x211438 blx r1 */
/* @0x21143c stm r6, {r0, r1} */
/* @0x211440 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x211444 ldr lr, [r7, #0x8] */
/* @0x211448 ldrd r0, r1, [r4] */
/* @0x21144c ldrd r2, r3, [r4, #8] */
/* @0x211450 str lr, [sp] */
/* @0x211454 ldr r12, [r12, #0xc] */
/* @0x211458 blx r12 */
/* @0x21145c stm r6, {r0, r1} */
/* @0x211460 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x211464 ldrd r2, r3, [r4, #16] */
/* @0x211468 ldrd r0, r1, [r4, #24] */
/* @0x21146c strd r2, r3, [sp] */
/* @0x211470 strd r0, r1, [sp, #8] */
/* @0x211474 ldrd r0, r1, [r4] */
/* @0x211478 ldr r12, [r12, #0xc] */
/* @0x21147c ldrd r2, r3, [r4, #8] */
/* @0x211480 blx r12 */
/* @0x211484 stm r6, {r0, r1} */
/* @0x211488 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x21148c ldrd r2, r3, [r4, #16] */
/* @0x211490 ldr lr, [r7, #0xc] */
/* @0x211494 ldrd r0, r1, [r4] */
/* @0x211498 strd r2, r3, [sp] */
/* @0x21149c ldrd r2, r3, [r4, #8] */
/* @0x2114a0 str lr, [sp, #0x8] */
/* @0x2114a4 ldr r12, [r12, #0xc] */
/* @0x2114a8 blx r12 */
/* @0x2114ac stm r6, {r0, r1} */
/* @0x2114b0 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x2114b4 ldrd r2, r3, [r4, #16] */
/* @0x2114b8 ldrd r0, r1, [r4] */
/* @0x2114bc strd r2, r3, [sp] */
/* @0x2114c0 ldr r12, [r12, #0xc] */
/* @0x2114c4 ldrd r2, r3, [r4, #8] */
/* @0x2114c8 blx r12 */
/* @0x2114cc stm r6, {r0, r1} */
/* @0x2114d0 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x2114d4 ldr r1, [r12, #0xc] */
/* @0x2114d8 ldr r0, [r7] */
/* @0x2114dc ldrd r2, r3, [r4, #8] */
/* @0x2114e0 blx r1 */
/* @0x2114e4 mov r1, r0 */
/* @0x2114e8 b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x2114ec ldr r1, [r12, #0xc] */
/* @0x2114f0 ldr r0, [r7] */
/* @0x2114f4 ldrd r2, r3, [r4, #8] */
/* @0x2114f8 blx r1 */
/* @0x2114fc stm r6, {r0, r1} */
/* @0x211500 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x211504 ldm r7, {r0, r1} */
/* @0x211508 ldr r3, [r12, #0xc] */
/* @0x21150c blx r3 */
/* @0x211510 mov r1, r0 */
/* @0x211514 b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x211518 ldr r3, [r12, #0xc] */
/* @0x21151c ldm r7, {r0, r1} */
/* @0x211520 blx r3 */
/* @0x211524 stm r6, {r0, r1} */
/* @0x211528 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x21152c ldrd r2, r3, [r4, #24] */
/* @0x211530 ldr r1, [r7, #0x4] */
/* @0x211534 ldr r0, [r7] */
/* @0x211538 strd r2, r3, [sp] */
/* @0x21153c ldr r2, [r7, #0x8] */
/* @0x211540 ldr r3, [r12, #0xc] */
/* @0x211544 blx r3 */
/* @0x211548 mov r1, r0 */
/* @0x21154c b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x211550 ldrd r2, r3, [r4, #24] */
/* @0x211554 ldr r0, [r7] */
/* @0x211558 ldr r1, [r7, #0x4] */
/* @0x21155c strd r2, r3, [sp] */
/* @0x211560 ldr r2, [r7, #0x8] */
/* @0x211564 ldr r3, [r12, #0xc] */
/* @0x211568 blx r3 */
/* @0x21156c stm r6, {r0, r1} */
/* @0x211570 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x211574 ldm r7, {r0, r1} */
/* @0x211578 ldr r12, [r12, #0xc] */
/* @0x21157c ldrd r2, r3, [r4, #16] */
/* @0x211580 blx r12 */
/* @0x211584 mov r1, r0 */
/* @0x211588 b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x21158c ldr r12, [r12, #0xc] */
/* @0x211590 ldm r7, {r0, r1} */
/* @0x211594 ldrd r2, r3, [r4, #16] */
/* @0x211598 blx r12 */
/* @0x21159c stm r6, {r0, r1} */
/* @0x2115a0 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x2115a4 ldm r7, {r0, r1, r2} */
/* @0x2115a8 ldr r3, [r12, #0xc] */
/* @0x2115ac blx r3 */
/* @0x2115b0 mov r1, r0 */
/* @0x2115b4 b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x2115b8 ldr r3, [r12, #0xc] */
/* @0x2115bc ldm r7, {r0, r1, r2} */
/* @0x2115c0 blx r3 */
/* @0x2115c4 stm r6, {r0, r1} */
/* @0x2115c8 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x2115cc ldrd r4, r5, [r4, #16] */
/* @0x2115d0 ldr r3, [r7, #0xc] */
/* @0x2115d4 ldm r7, {r0, r1} */
/* @0x2115d8 mov r2, r4 */
/* @0x2115dc str r3, [sp] */
/* @0x2115e0 mov r3, r5 */
/* @0x2115e4 ldr r12, [r12, #0xc] */
/* @0x2115e8 blx r12 */
/* @0x2115ec mov r1, r0 */
/* @0x2115f0 b 0x210e8c <_Z15Call_Normal_stdiPdPPKcP6RValue+0x3d4> */
/* @0x2115f4 ldr lr, [r7, #0xc] */
/* @0x2115f8 ldrd r2, r3, [r4, #16] */
/* @0x2115fc ldm r7, {r0, r1} */
/* @0x211600 str lr, [sp] */
/* @0x211604 ldr r12, [r12, #0xc] */
/* @0x211608 blx r12 */
/* @0x21160c stm r6, {r0, r1} */
/* @0x211610 b 0x210c20 <_Z15Call_Normal_stdiPdPPKcP6RValue+0x168> */
/* @0x211614 andseq r0, lr, r12, ror #17 */
/* @0x211618 andseq r0, lr, r12, asr #17 */

/* ── FUNC 0x21161c · Call_Real(int, double*, RValue*) · size=2444 · insn=611 */
/* @0x21161c ldr r12, [pc, #0x8fc] */
/* @0x211620 mov r3, r1 */
/* @0x211624 push {r4, r5, r6, lr} */
/* @0x211628 ldr r12, [pc, r12] */
/* @0x21162c mov r6, r2 */
/* @0x211630 sub sp, sp, #112 */
/* @0x211634 ldrb r2, [r12] */
/* @0x211638 cmp r2, #0 */
/* @0x21163c bne 0x2116d8 <_Z9Call_RealiPdP6RValue+0xbc> */
/* @0x211640 ldr r1, [pc, #0x8dc] */
/* @0x211644 ldr r1, [pc, r1] */
/* @0x211648 ldr r12, [r1] */
/* @0x21164c cmp r0, r12 */
/* @0x211650 ldrlt r2, [r1, #0x4] */
/* @0x211654 ldrlt r2, [r2, r0, lsl #2] */
/* @0x211658 ldr r1, [r2, #0x5c] */
/* @0x21165c cmp r1, #0 */
/* @0x211660 str r1, [r6, #0xc] */
/* @0x211664 ldr r1, [r2, #0x14] */
/* @0x211668 sub r1, r1, #5 */
/* @0x21166c bne 0x2116e0 <_Z9Call_RealiPdP6RValue+0xc4> */
/* @0x211670 cmp r1, #11 */
/* @0x211674 addls pc, pc, r1, lsl #2 */
/* @0x211678 b 0x2116d8 <_Z9Call_RealiPdP6RValue+0xbc> */
/* @0x21167c b 0x2116ac <_Z9Call_RealiPdP6RValue+0x90> */
/* @0x211680 b 0x211c08 <_Z9Call_RealiPdP6RValue+0x5ec> */
/* @0x211684 b 0x211c40 <_Z9Call_RealiPdP6RValue+0x624> */
/* @0x211688 b 0x211c80 <_Z9Call_RealiPdP6RValue+0x664> */
/* @0x21168c b 0x211cc8 <_Z9Call_RealiPdP6RValue+0x6ac> */
/* @0x211690 b 0x211d18 <_Z9Call_RealiPdP6RValue+0x6fc> */
/* @0x211694 b 0x211d70 <_Z9Call_RealiPdP6RValue+0x754> */
/* @0x211698 b 0x211dd0 <_Z9Call_RealiPdP6RValue+0x7b4> */
/* @0x21169c b 0x211e38 <_Z9Call_RealiPdP6RValue+0x81c> */
/* @0x2116a0 b 0x211ea8 <_Z9Call_RealiPdP6RValue+0x88c> */
/* @0x2116a4 b 0x211f28 <_Z9Call_RealiPdP6RValue+0x90c> */
/* @0x2116a8 b 0x21171c <_Z9Call_RealiPdP6RValue+0x100> */
/* @0x2116ac ldrd r0, r1, [r3, #16] */
/* @0x2116b0 ldrd r4, r5, [r3, #24] */
/* @0x2116b4 strd r0, r1, [sp] */
/* @0x2116b8 strd r4, r5, [sp, #8] */
/* @0x2116bc ldrd r4, r5, [r3, #32] */
/* @0x2116c0 ldrd r0, r1, [r3] */
/* @0x2116c4 strd r4, r5, [sp, #16] */
/* @0x2116c8 ldr r12, [r2, #0xc] */
/* @0x2116cc ldrd r2, r3, [r3, #8] */
/* @0x2116d0 blx r12 */
/* @0x2116d4 stm r6, {r0, r1} */
/* @0x2116d8 add sp, sp, #112 */
/* @0x2116dc pop {r4, r5, r6, pc} */
/* @0x2116e0 cmp r1, #11 */
/* @0x2116e4 addls pc, pc, r1, lsl #2 */
/* @0x2116e8 b 0x2116d8 <_Z9Call_RealiPdP6RValue+0xbc> */
/* @0x2116ec b 0x2117a4 <_Z9Call_RealiPdP6RValue+0x188> */
/* @0x2116f0 b 0x2117e8 <_Z9Call_RealiPdP6RValue+0x1cc> */
/* @0x2116f4 b 0x211820 <_Z9Call_RealiPdP6RValue+0x204> */
/* @0x2116f8 b 0x211860 <_Z9Call_RealiPdP6RValue+0x244> */
/* @0x2116fc b 0x2118a8 <_Z9Call_RealiPdP6RValue+0x28c> */
/* @0x211700 b 0x2118f8 <_Z9Call_RealiPdP6RValue+0x2dc> */
/* @0x211704 b 0x211950 <_Z9Call_RealiPdP6RValue+0x334> */
/* @0x211708 b 0x2119b0 <_Z9Call_RealiPdP6RValue+0x394> */
/* @0x21170c b 0x211a18 <_Z9Call_RealiPdP6RValue+0x3fc> */
/* @0x211710 b 0x211a88 <_Z9Call_RealiPdP6RValue+0x46c> */
/* @0x211714 b 0x211b00 <_Z9Call_RealiPdP6RValue+0x4e4> */
/* @0x211718 b 0x211b80 <_Z9Call_RealiPdP6RValue+0x564> */
/* @0x21171c ldrd r0, r1, [r3, #16] */
/* @0x211720 ldrd r4, r5, [r3, #24] */
/* @0x211724 strd r0, r1, [sp] */
/* @0x211728 strd r4, r5, [sp, #8] */
/* @0x21172c ldrd r0, r1, [r3, #32] */
/* @0x211730 ldrd r4, r5, [r3, #40] */
/* @0x211734 strd r0, r1, [sp, #16] */
/* @0x211738 strd r4, r5, [sp, #24] */
/* @0x21173c ldrd r0, r1, [r3, #48] */
/* @0x211740 ldrd r4, r5, [r3, #56] */
/* @0x211744 strd r0, r1, [sp, #32] */
/* @0x211748 strd r4, r5, [sp, #40] */
/* @0x21174c ldrd r0, r1, [r3, #64] */
/* @0x211750 ldrd r4, r5, [r3, #72] */
/* @0x211754 strd r0, r1, [sp, #48] */
/* @0x211758 strd r4, r5, [sp, #56] */
/* @0x21175c ldrd r0, r1, [r3, #80] */
/* @0x211760 ldrd r4, r5, [r3, #88] */
/* @0x211764 strd r0, r1, [sp, #64] */
/* @0x211768 strd r4, r5, [sp, #72] */
/* @0x21176c ldrd r0, r1, [r3, #96] */
/* @0x211770 ldrd r4, r5, [r3, #104] */
/* @0x211774 strd r0, r1, [sp, #80] */
/* @0x211778 strd r4, r5, [sp, #88] */
/* @0x21177c ldrd r0, r1, [r3, #112] */
/* @0x211780 ldrd r4, r5, [r3, #120] */
/* @0x211784 strd r0, r1, [sp, #96] */
/* @0x211788 strd r4, r5, [sp, #104] */
/* @0x21178c ldrd r0, r1, [r3] */
/* @0x211790 ldr r12, [r2, #0xc] */
/* @0x211794 ldrd r2, r3, [r3, #8] */
/* @0x211798 blx r12 */
/* @0x21179c stm r6, {r0, r1} */
/* @0x2117a0 b 0x2116d8 <_Z9Call_RealiPdP6RValue+0xbc> */
/* @0x2117a4 ldrd r0, r1, [r3, #16] */
/* @0x2117a8 ldrd r4, r5, [r3, #24] */
/* @0x2117ac strd r0, r1, [sp] */
/* @0x2117b0 strd r4, r5, [sp, #8] */
/* @0x2117b4 ldrd r4, r5, [r3, #32] */
/* @0x2117b8 ldrd r0, r1, [r3] */
/* @0x2117bc strd r4, r5, [sp, #16] */
/* @0x2117c0 ldr r12, [r2, #0xc] */
/* @0x2117c4 ldrd r2, r3, [r3, #8] */
/* @0x2117c8 blx r12 */
/* @0x2117cc mov r1, r0 */
/* @0x2117d0 cmp r1, #0 */
/* @0x2117d4 beq 0x2116d8 <_Z9Call_RealiPdP6RValue+0xbc> */
/* @0x2117d8 mov r0, r6 */
/* @0x2117dc add sp, sp, #112 */
/* @0x2117e0 pop {r4, r5, r6, lr} */
/* @0x2117e4 b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x2117e8 ldrd r0, r1, [r3, #16] */
/* @0x2117ec ldrd r4, r5, [r3, #24] */
/* @0x2117f0 strd r0, r1, [sp] */
/* @0x2117f4 strd r4, r5, [sp, #8] */
/* @0x2117f8 ldrd r0, r1, [r3, #32] */
/* @0x2117fc ldrd r4, r5, [r3, #40] */
/* @0x211800 strd r0, r1, [sp, #16] */
/* @0x211804 strd r4, r5, [sp, #24] */
/* @0x211808 ldrd r0, r1, [r3] */
/* @0x21180c ldr r12, [r2, #0xc] */
/* @0x211810 ldrd r2, r3, [r3, #8] */
/* @0x211814 blx r12 */
/* @0x211818 mov r1, r0 */
/* @0x21181c b 0x2117d0 <_Z9Call_RealiPdP6RValue+0x1b4> */
/* @0x211820 ldrd r0, r1, [r3, #16] */
/* @0x211824 ldrd r4, r5, [r3, #24] */
/* @0x211828 strd r0, r1, [sp] */
/* @0x21182c strd r4, r5, [sp, #8] */
/* @0x211830 ldrd r0, r1, [r3, #32] */
/* @0x211834 ldrd r4, r5, [r3, #40] */
/* @0x211838 strd r0, r1, [sp, #16] */
/* @0x21183c strd r4, r5, [sp, #24] */
/* @0x211840 ldrd r4, r5, [r3, #48] */
/* @0x211844 ldrd r0, r1, [r3] */
/* @0x211848 strd r4, r5, [sp, #32] */
/* @0x21184c ldr r12, [r2, #0xc] */
/* @0x211850 ldrd r2, r3, [r3, #8] */
/* @0x211854 blx r12 */
/* @0x211858 mov r1, r0 */
/* @0x21185c b 0x2117d0 <_Z9Call_RealiPdP6RValue+0x1b4> */
/* @0x211860 ldrd r0, r1, [r3, #16] */
/* @0x211864 ldrd r4, r5, [r3, #24] */
/* @0x211868 strd r0, r1, [sp] */
/* @0x21186c strd r4, r5, [sp, #8] */
/* @0x211870 ldrd r0, r1, [r3, #32] */
/* @0x211874 ldrd r4, r5, [r3, #40] */
/* @0x211878 strd r0, r1, [sp, #16] */
/* @0x21187c strd r4, r5, [sp, #24] */
/* @0x211880 ldrd r0, r1, [r3, #48] */
/* @0x211884 ldrd r4, r5, [r3, #56] */
/* @0x211888 strd r0, r1, [sp, #32] */
/* @0x21188c strd r4, r5, [sp, #40] */
/* @0x211890 ldrd r0, r1, [r3] */
/* @0x211894 ldr r12, [r2, #0xc] */
/* @0x211898 ldrd r2, r3, [r3, #8] */
/* @0x21189c blx r12 */
/* @0x2118a0 mov r1, r0 */
/* @0x2118a4 b 0x2117d0 <_Z9Call_RealiPdP6RValue+0x1b4> */
/* @0x2118a8 ldrd r0, r1, [r3, #16] */
/* @0x2118ac ldrd r4, r5, [r3, #24] */
/* @0x2118b0 strd r0, r1, [sp] */
/* @0x2118b4 strd r4, r5, [sp, #8] */
/* @0x2118b8 ldrd r0, r1, [r3, #32] */
/* @0x2118bc ldrd r4, r5, [r3, #40] */
/* @0x2118c0 strd r0, r1, [sp, #16] */
/* @0x2118c4 strd r4, r5, [sp, #24] */
/* @0x2118c8 ldrd r0, r1, [r3, #48] */
/* @0x2118cc ldrd r4, r5, [r3, #56] */
/* @0x2118d0 strd r0, r1, [sp, #32] */
/* @0x2118d4 strd r4, r5, [sp, #40] */
/* @0x2118d8 ldrd r4, r5, [r3, #64] */
/* @0x2118dc ldrd r0, r1, [r3] */
/* @0x2118e0 strd r4, r5, [sp, #48] */
/* @0x2118e4 ldr r12, [r2, #0xc] */
/* @0x2118e8 ldrd r2, r3, [r3, #8] */
/* @0x2118ec blx r12 */
/* @0x2118f0 mov r1, r0 */
/* @0x2118f4 b 0x2117d0 <_Z9Call_RealiPdP6RValue+0x1b4> */
/* @0x2118f8 ldrd r0, r1, [r3, #16] */
/* @0x2118fc ldrd r4, r5, [r3, #24] */
/* @0x211900 strd r0, r1, [sp] */
/* @0x211904 strd r4, r5, [sp, #8] */
/* @0x211908 ldrd r0, r1, [r3, #32] */
/* @0x21190c ldrd r4, r5, [r3, #40] */
/* @0x211910 strd r0, r1, [sp, #16] */
/* @0x211914 strd r4, r5, [sp, #24] */
/* @0x211918 ldrd r0, r1, [r3, #48] */
/* @0x21191c ldrd r4, r5, [r3, #56] */
/* @0x211920 strd r0, r1, [sp, #32] */
/* @0x211924 strd r4, r5, [sp, #40] */
/* @0x211928 ldrd r0, r1, [r3, #64] */
/* @0x21192c ldrd r4, r5, [r3, #72] */
/* @0x211930 strd r0, r1, [sp, #48] */
/* @0x211934 strd r4, r5, [sp, #56] */
/* @0x211938 ldrd r0, r1, [r3] */
/* @0x21193c ldr r12, [r2, #0xc] */
/* @0x211940 ldrd r2, r3, [r3, #8] */
/* @0x211944 blx r12 */
/* @0x211948 mov r1, r0 */
/* @0x21194c b 0x2117d0 <_Z9Call_RealiPdP6RValue+0x1b4> */
/* @0x211950 ldrd r0, r1, [r3, #16] */
/* @0x211954 ldrd r4, r5, [r3, #24] */
/* @0x211958 strd r0, r1, [sp] */
/* @0x21195c strd r4, r5, [sp, #8] */
/* @0x211960 ldrd r0, r1, [r3, #32] */
/* @0x211964 ldrd r4, r5, [r3, #40] */
/* @0x211968 strd r0, r1, [sp, #16] */
/* @0x21196c strd r4, r5, [sp, #24] */
/* @0x211970 ldrd r0, r1, [r3, #48] */
/* @0x211974 ldrd r4, r5, [r3, #56] */
/* @0x211978 strd r0, r1, [sp, #32] */
/* @0x21197c strd r4, r5, [sp, #40] */
/* @0x211980 ldrd r0, r1, [r3, #64] */
/* @0x211984 ldrd r4, r5, [r3, #72] */
/* @0x211988 strd r0, r1, [sp, #48] */
/* @0x21198c strd r4, r5, [sp, #56] */
/* @0x211990 ldrd r4, r5, [r3, #80] */
/* @0x211994 ldrd r0, r1, [r3] */
/* @0x211998 strd r4, r5, [sp, #64] */
/* @0x21199c ldr r12, [r2, #0xc] */
/* @0x2119a0 ldrd r2, r3, [r3, #8] */
/* @0x2119a4 blx r12 */
/* @0x2119a8 mov r1, r0 */
/* @0x2119ac b 0x2117d0 <_Z9Call_RealiPdP6RValue+0x1b4> */
/* @0x2119b0 ldrd r0, r1, [r3, #16] */
/* @0x2119b4 ldrd r4, r5, [r3, #24] */
/* @0x2119b8 strd r0, r1, [sp] */
/* @0x2119bc strd r4, r5, [sp, #8] */
/* @0x2119c0 ldrd r0, r1, [r3, #32] */
/* @0x2119c4 ldrd r4, r5, [r3, #40] */
/* @0x2119c8 strd r0, r1, [sp, #16] */
/* @0x2119cc strd r4, r5, [sp, #24] */
/* @0x2119d0 ldrd r0, r1, [r3, #48] */
/* @0x2119d4 ldrd r4, r5, [r3, #56] */
/* @0x2119d8 strd r0, r1, [sp, #32] */
/* @0x2119dc strd r4, r5, [sp, #40] */
/* @0x2119e0 ldrd r0, r1, [r3, #64] */
/* @0x2119e4 ldrd r4, r5, [r3, #72] */
/* @0x2119e8 strd r0, r1, [sp, #48] */
/* @0x2119ec strd r4, r5, [sp, #56] */
/* @0x2119f0 ldrd r0, r1, [r3, #80] */
/* @0x2119f4 ldrd r4, r5, [r3, #88] */
/* @0x2119f8 strd r0, r1, [sp, #64] */
/* @0x2119fc strd r4, r5, [sp, #72] */
/* @0x211a00 ldrd r0, r1, [r3] */
/* @0x211a04 ldr r12, [r2, #0xc] */
/* @0x211a08 ldrd r2, r3, [r3, #8] */
/* @0x211a0c blx r12 */
/* @0x211a10 mov r1, r0 */
/* @0x211a14 b 0x2117d0 <_Z9Call_RealiPdP6RValue+0x1b4> */
/* @0x211a18 ldrd r0, r1, [r3, #16] */
/* @0x211a1c ldrd r4, r5, [r3, #24] */
/* @0x211a20 strd r0, r1, [sp] */
/* @0x211a24 strd r4, r5, [sp, #8] */
/* @0x211a28 ldrd r0, r1, [r3, #32] */
/* @0x211a2c ldrd r4, r5, [r3, #40] */
/* @0x211a30 strd r0, r1, [sp, #16] */
/* @0x211a34 strd r4, r5, [sp, #24] */
/* @0x211a38 ldrd r0, r1, [r3, #48] */
/* @0x211a3c ldrd r4, r5, [r3, #56] */
/* @0x211a40 strd r0, r1, [sp, #32] */
/* @0x211a44 strd r4, r5, [sp, #40] */
/* @0x211a48 ldrd r0, r1, [r3, #64] */
/* @0x211a4c ldrd r4, r5, [r3, #72] */
/* @0x211a50 strd r0, r1, [sp, #48] */
/* @0x211a54 strd r4, r5, [sp, #56] */
/* @0x211a58 ldrd r0, r1, [r3, #80] */
/* @0x211a5c ldrd r4, r5, [r3, #88] */
/* @0x211a60 strd r0, r1, [sp, #64] */
/* @0x211a64 strd r4, r5, [sp, #72] */
/* @0x211a68 ldrd r4, r5, [r3, #96] */
/* @0x211a6c ldrd r0, r1, [r3] */
/* @0x211a70 strd r4, r5, [sp, #80] */
/* @0x211a74 ldr r12, [r2, #0xc] */
/* @0x211a78 ldrd r2, r3, [r3, #8] */
/* @0x211a7c blx r12 */
/* @0x211a80 mov r1, r0 */
/* @0x211a84 b 0x2117d0 <_Z9Call_RealiPdP6RValue+0x1b4> */
/* @0x211a88 ldrd r0, r1, [r3, #16] */
/* @0x211a8c ldrd r4, r5, [r3, #24] */
/* @0x211a90 strd r0, r1, [sp] */
/* @0x211a94 strd r4, r5, [sp, #8] */
/* @0x211a98 ldrd r0, r1, [r3, #32] */
/* @0x211a9c ldrd r4, r5, [r3, #40] */
/* @0x211aa0 strd r0, r1, [sp, #16] */
/* @0x211aa4 strd r4, r5, [sp, #24] */
/* @0x211aa8 ldrd r0, r1, [r3, #48] */
/* @0x211aac ldrd r4, r5, [r3, #56] */
/* @0x211ab0 strd r0, r1, [sp, #32] */
/* @0x211ab4 strd r4, r5, [sp, #40] */
/* @0x211ab8 ldrd r0, r1, [r3, #64] */
/* @0x211abc ldrd r4, r5, [r3, #72] */
/* @0x211ac0 strd r0, r1, [sp, #48] */
/* @0x211ac4 strd r4, r5, [sp, #56] */
/* @0x211ac8 ldrd r0, r1, [r3, #80] */
/* @0x211acc ldrd r4, r5, [r3, #88] */
/* @0x211ad0 strd r0, r1, [sp, #64] */
/* @0x211ad4 strd r4, r5, [sp, #72] */
/* @0x211ad8 ldrd r0, r1, [r3, #96] */
/* @0x211adc ldrd r4, r5, [r3, #104] */
/* @0x211ae0 strd r0, r1, [sp, #80] */
/* @0x211ae4 strd r4, r5, [sp, #88] */
/* @0x211ae8 ldrd r0, r1, [r3] */
/* @0x211aec ldr r12, [r2, #0xc] */
/* @0x211af0 ldrd r2, r3, [r3, #8] */
/* @0x211af4 blx r12 */
/* @0x211af8 mov r1, r0 */
/* @0x211afc b 0x2117d0 <_Z9Call_RealiPdP6RValue+0x1b4> */
/* @0x211b00 ldrd r0, r1, [r3, #16] */
/* @0x211b04 ldrd r4, r5, [r3, #24] */
/* @0x211b08 strd r0, r1, [sp] */
/* @0x211b0c strd r4, r5, [sp, #8] */
/* @0x211b10 ldrd r0, r1, [r3, #32] */
/* @0x211b14 ldrd r4, r5, [r3, #40] */
/* @0x211b18 strd r0, r1, [sp, #16] */
/* @0x211b1c strd r4, r5, [sp, #24] */
/* @0x211b20 ldrd r0, r1, [r3, #48] */
/* @0x211b24 ldrd r4, r5, [r3, #56] */
/* @0x211b28 strd r0, r1, [sp, #32] */
/* @0x211b2c strd r4, r5, [sp, #40] */
/* @0x211b30 ldrd r0, r1, [r3, #64] */
/* @0x211b34 ldrd r4, r5, [r3, #72] */
/* @0x211b38 strd r0, r1, [sp, #48] */
/* @0x211b3c strd r4, r5, [sp, #56] */
/* @0x211b40 ldrd r0, r1, [r3, #80] */
/* @0x211b44 ldrd r4, r5, [r3, #88] */
/* @0x211b48 strd r0, r1, [sp, #64] */
/* @0x211b4c strd r4, r5, [sp, #72] */
/* @0x211b50 ldrd r0, r1, [r3, #96] */
/* @0x211b54 ldrd r4, r5, [r3, #104] */
/* @0x211b58 strd r0, r1, [sp, #80] */
/* @0x211b5c strd r4, r5, [sp, #88] */
/* @0x211b60 ldrd r4, r5, [r3, #112] */
/* @0x211b64 ldrd r0, r1, [r3] */
/* @0x211b68 strd r4, r5, [sp, #96] */
/* @0x211b6c ldr r12, [r2, #0xc] */
/* @0x211b70 ldrd r2, r3, [r3, #8] */
/* @0x211b74 blx r12 */
/* @0x211b78 mov r1, r0 */
/* @0x211b7c b 0x2117d0 <_Z9Call_RealiPdP6RValue+0x1b4> */
/* @0x211b80 ldrd r0, r1, [r3, #16] */
/* @0x211b84 ldrd r4, r5, [r3, #24] */
/* @0x211b88 strd r0, r1, [sp] */
/* @0x211b8c strd r4, r5, [sp, #8] */
/* @0x211b90 ldrd r0, r1, [r3, #32] */
/* @0x211b94 ldrd r4, r5, [r3, #40] */
/* @0x211b98 strd r0, r1, [sp, #16] */
/* @0x211b9c strd r4, r5, [sp, #24] */
/* @0x211ba0 ldrd r0, r1, [r3, #48] */
/* @0x211ba4 ldrd r4, r5, [r3, #56] */
/* @0x211ba8 strd r0, r1, [sp, #32] */
/* @0x211bac strd r4, r5, [sp, #40] */
/* @0x211bb0 ldrd r0, r1, [r3, #64] */
/* @0x211bb4 ldrd r4, r5, [r3, #72] */
/* @0x211bb8 strd r0, r1, [sp, #48] */
/* @0x211bbc strd r4, r5, [sp, #56] */
/* @0x211bc0 ldrd r0, r1, [r3, #80] */
/* @0x211bc4 ldrd r4, r5, [r3, #88] */
/* @0x211bc8 strd r0, r1, [sp, #64] */
/* @0x211bcc strd r4, r5, [sp, #72] */
/* @0x211bd0 ldrd r0, r1, [r3, #96] */
/* @0x211bd4 ldrd r4, r5, [r3, #104] */
/* @0x211bd8 strd r0, r1, [sp, #80] */
/* @0x211bdc strd r4, r5, [sp, #88] */
/* @0x211be0 ldrd r0, r1, [r3, #112] */
/* @0x211be4 ldrd r4, r5, [r3, #120] */
/* @0x211be8 strd r0, r1, [sp, #96] */
/* @0x211bec strd r4, r5, [sp, #104] */
/* @0x211bf0 ldrd r0, r1, [r3] */
/* @0x211bf4 ldr r12, [r2, #0xc] */
/* @0x211bf8 ldrd r2, r3, [r3, #8] */
/* @0x211bfc blx r12 */
/* @0x211c00 mov r1, r0 */
/* @0x211c04 b 0x2117d0 <_Z9Call_RealiPdP6RValue+0x1b4> */
/* @0x211c08 ldrd r0, r1, [r3, #16] */
/* @0x211c0c ldrd r4, r5, [r3, #24] */
/* @0x211c10 strd r0, r1, [sp] */
/* @0x211c14 strd r4, r5, [sp, #8] */
/* @0x211c18 ldrd r0, r1, [r3, #32] */
/* @0x211c1c ldrd r4, r5, [r3, #40] */
/* @0x211c20 strd r0, r1, [sp, #16] */
/* @0x211c24 strd r4, r5, [sp, #24] */
/* @0x211c28 ldrd r0, r1, [r3] */
/* @0x211c2c ldr r12, [r2, #0xc] */
/* @0x211c30 ldrd r2, r3, [r3, #8] */
/* @0x211c34 blx r12 */
/* @0x211c38 stm r6, {r0, r1} */
/* @0x211c3c b 0x2116d8 <_Z9Call_RealiPdP6RValue+0xbc> */
/* @0x211c40 ldrd r0, r1, [r3, #16] */
/* @0x211c44 ldrd r4, r5, [r3, #24] */
/* @0x211c48 strd r0, r1, [sp] */
/* @0x211c4c strd r4, r5, [sp, #8] */
/* @0x211c50 ldrd r0, r1, [r3, #32] */
/* @0x211c54 ldrd r4, r5, [r3, #40] */
/* @0x211c58 strd r0, r1, [sp, #16] */
/* @0x211c5c strd r4, r5, [sp, #24] */
/* @0x211c60 ldrd r4, r5, [r3, #48] */
/* @0x211c64 ldrd r0, r1, [r3] */
/* @0x211c68 strd r4, r5, [sp, #32] */
/* @0x211c6c ldr r12, [r2, #0xc] */
/* @0x211c70 ldrd r2, r3, [r3, #8] */
/* @0x211c74 blx r12 */
/* @0x211c78 stm r6, {r0, r1} */
/* @0x211c7c b 0x2116d8 <_Z9Call_RealiPdP6RValue+0xbc> */
/* @0x211c80 ldrd r0, r1, [r3, #16] */
/* @0x211c84 ldrd r4, r5, [r3, #24] */
/* @0x211c88 strd r0, r1, [sp] */
/* @0x211c8c strd r4, r5, [sp, #8] */
/* @0x211c90 ldrd r0, r1, [r3, #32] */
/* @0x211c94 ldrd r4, r5, [r3, #40] */
/* @0x211c98 strd r0, r1, [sp, #16] */
/* @0x211c9c strd r4, r5, [sp, #24] */
/* @0x211ca0 ldrd r0, r1, [r3, #48] */
/* @0x211ca4 ldrd r4, r5, [r3, #56] */
/* @0x211ca8 strd r0, r1, [sp, #32] */
/* @0x211cac strd r4, r5, [sp, #40] */
/* @0x211cb0 ldrd r0, r1, [r3] */
/* @0x211cb4 ldr r12, [r2, #0xc] */
/* @0x211cb8 ldrd r2, r3, [r3, #8] */
/* @0x211cbc blx r12 */
/* @0x211cc0 stm r6, {r0, r1} */
/* @0x211cc4 b 0x2116d8 <_Z9Call_RealiPdP6RValue+0xbc> */
/* @0x211cc8 ldrd r0, r1, [r3, #16] */
/* @0x211ccc ldrd r4, r5, [r3, #24] */
/* @0x211cd0 strd r0, r1, [sp] */
/* @0x211cd4 strd r4, r5, [sp, #8] */
/* @0x211cd8 ldrd r0, r1, [r3, #32] */
/* @0x211cdc ldrd r4, r5, [r3, #40] */
/* @0x211ce0 strd r0, r1, [sp, #16] */
/* @0x211ce4 strd r4, r5, [sp, #24] */
/* @0x211ce8 ldrd r0, r1, [r3, #48] */
/* @0x211cec ldrd r4, r5, [r3, #56] */
/* @0x211cf0 strd r0, r1, [sp, #32] */
/* @0x211cf4 strd r4, r5, [sp, #40] */
/* @0x211cf8 ldrd r4, r5, [r3, #64] */
/* @0x211cfc ldrd r0, r1, [r3] */
/* @0x211d00 strd r4, r5, [sp, #48] */
/* @0x211d04 ldr r12, [r2, #0xc] */
/* @0x211d08 ldrd r2, r3, [r3, #8] */
/* @0x211d0c blx r12 */
/* @0x211d10 stm r6, {r0, r1} */
/* @0x211d14 b 0x2116d8 <_Z9Call_RealiPdP6RValue+0xbc> */
/* @0x211d18 ldrd r0, r1, [r3, #16] */
/* @0x211d1c ldrd r4, r5, [r3, #24] */
/* @0x211d20 strd r0, r1, [sp] */
/* @0x211d24 strd r4, r5, [sp, #8] */
/* @0x211d28 ldrd r0, r1, [r3, #32] */
/* @0x211d2c ldrd r4, r5, [r3, #40] */
/* @0x211d30 strd r0, r1, [sp, #16] */
/* @0x211d34 strd r4, r5, [sp, #24] */
/* @0x211d38 ldrd r0, r1, [r3, #48] */
/* @0x211d3c ldrd r4, r5, [r3, #56] */
/* @0x211d40 strd r0, r1, [sp, #32] */
/* @0x211d44 strd r4, r5, [sp, #40] */
/* @0x211d48 ldrd r0, r1, [r3, #64] */
/* @0x211d4c ldrd r4, r5, [r3, #72] */
/* @0x211d50 strd r0, r1, [sp, #48] */
/* @0x211d54 strd r4, r5, [sp, #56] */
/* @0x211d58 ldrd r0, r1, [r3] */
/* @0x211d5c ldr r12, [r2, #0xc] */
/* @0x211d60 ldrd r2, r3, [r3, #8] */
/* @0x211d64 blx r12 */
/* @0x211d68 stm r6, {r0, r1} */
/* @0x211d6c b 0x2116d8 <_Z9Call_RealiPdP6RValue+0xbc> */
/* @0x211d70 ldrd r0, r1, [r3, #16] */
/* @0x211d74 ldrd r4, r5, [r3, #24] */
/* @0x211d78 strd r0, r1, [sp] */
/* @0x211d7c strd r4, r5, [sp, #8] */
/* @0x211d80 ldrd r0, r1, [r3, #32] */
/* @0x211d84 ldrd r4, r5, [r3, #40] */
/* @0x211d88 strd r0, r1, [sp, #16] */
/* @0x211d8c strd r4, r5, [sp, #24] */
/* @0x211d90 ldrd r0, r1, [r3, #48] */
/* @0x211d94 ldrd r4, r5, [r3, #56] */
/* @0x211d98 strd r0, r1, [sp, #32] */
/* @0x211d9c strd r4, r5, [sp, #40] */
/* @0x211da0 ldrd r0, r1, [r3, #64] */
/* @0x211da4 ldrd r4, r5, [r3, #72] */
/* @0x211da8 strd r0, r1, [sp, #48] */
/* @0x211dac strd r4, r5, [sp, #56] */
/* @0x211db0 ldrd r4, r5, [r3, #80] */
/* @0x211db4 ldrd r0, r1, [r3] */
/* @0x211db8 strd r4, r5, [sp, #64] */
/* @0x211dbc ldr r12, [r2, #0xc] */
/* @0x211dc0 ldrd r2, r3, [r3, #8] */
/* @0x211dc4 blx r12 */
/* @0x211dc8 stm r6, {r0, r1} */
/* @0x211dcc b 0x2116d8 <_Z9Call_RealiPdP6RValue+0xbc> */
/* @0x211dd0 ldrd r0, r1, [r3, #16] */
/* @0x211dd4 ldrd r4, r5, [r3, #24] */
/* @0x211dd8 strd r0, r1, [sp] */
/* @0x211ddc strd r4, r5, [sp, #8] */
/* @0x211de0 ldrd r0, r1, [r3, #32] */
/* @0x211de4 ldrd r4, r5, [r3, #40] */
/* @0x211de8 strd r0, r1, [sp, #16] */
/* @0x211dec strd r4, r5, [sp, #24] */
/* @0x211df0 ldrd r0, r1, [r3, #48] */
/* @0x211df4 ldrd r4, r5, [r3, #56] */
/* @0x211df8 strd r0, r1, [sp, #32] */
/* @0x211dfc strd r4, r5, [sp, #40] */
/* @0x211e00 ldrd r0, r1, [r3, #64] */
/* @0x211e04 ldrd r4, r5, [r3, #72] */
/* @0x211e08 strd r0, r1, [sp, #48] */
/* @0x211e0c strd r4, r5, [sp, #56] */
/* @0x211e10 ldrd r0, r1, [r3, #80] */
/* @0x211e14 ldrd r4, r5, [r3, #88] */
/* @0x211e18 strd r0, r1, [sp, #64] */
/* @0x211e1c strd r4, r5, [sp, #72] */
/* @0x211e20 ldrd r0, r1, [r3] */
/* @0x211e24 ldr r12, [r2, #0xc] */
/* @0x211e28 ldrd r2, r3, [r3, #8] */
/* @0x211e2c blx r12 */
/* @0x211e30 stm r6, {r0, r1} */
/* @0x211e34 b 0x2116d8 <_Z9Call_RealiPdP6RValue+0xbc> */
/* @0x211e38 ldrd r0, r1, [r3, #16] */
/* @0x211e3c ldrd r4, r5, [r3, #24] */
/* @0x211e40 strd r0, r1, [sp] */
/* @0x211e44 strd r4, r5, [sp, #8] */
/* @0x211e48 ldrd r0, r1, [r3, #32] */
/* @0x211e4c ldrd r4, r5, [r3, #40] */
/* @0x211e50 strd r0, r1, [sp, #16] */
/* @0x211e54 strd r4, r5, [sp, #24] */
/* @0x211e58 ldrd r0, r1, [r3, #48] */
/* @0x211e5c ldrd r4, r5, [r3, #56] */
/* @0x211e60 strd r0, r1, [sp, #32] */
/* @0x211e64 strd r4, r5, [sp, #40] */
/* @0x211e68 ldrd r0, r1, [r3, #64] */
/* @0x211e6c ldrd r4, r5, [r3, #72] */
/* @0x211e70 strd r0, r1, [sp, #48] */
/* @0x211e74 strd r4, r5, [sp, #56] */
/* @0x211e78 ldrd r0, r1, [r3, #80] */
/* @0x211e7c ldrd r4, r5, [r3, #88] */
/* @0x211e80 strd r0, r1, [sp, #64] */
/* @0x211e84 strd r4, r5, [sp, #72] */
/* @0x211e88 ldrd r4, r5, [r3, #96] */
/* @0x211e8c ldrd r0, r1, [r3] */
/* @0x211e90 strd r4, r5, [sp, #80] */
/* @0x211e94 ldr r12, [r2, #0xc] */
/* @0x211e98 ldrd r2, r3, [r3, #8] */
/* @0x211e9c blx r12 */
/* @0x211ea0 stm r6, {r0, r1} */
/* @0x211ea4 b 0x2116d8 <_Z9Call_RealiPdP6RValue+0xbc> */
/* @0x211ea8 ldrd r0, r1, [r3, #16] */
/* @0x211eac ldrd r4, r5, [r3, #24] */
/* @0x211eb0 strd r0, r1, [sp] */
/* @0x211eb4 strd r4, r5, [sp, #8] */
/* @0x211eb8 ldrd r0, r1, [r3, #32] */
/* @0x211ebc ldrd r4, r5, [r3, #40] */
/* @0x211ec0 strd r0, r1, [sp, #16] */
/* @0x211ec4 strd r4, r5, [sp, #24] */
/* @0x211ec8 ldrd r0, r1, [r3, #48] */
/* @0x211ecc ldrd r4, r5, [r3, #56] */
/* @0x211ed0 strd r0, r1, [sp, #32] */
/* @0x211ed4 strd r4, r5, [sp, #40] */
/* @0x211ed8 ldrd r0, r1, [r3, #64] */
/* @0x211edc ldrd r4, r5, [r3, #72] */
/* @0x211ee0 strd r0, r1, [sp, #48] */
/* @0x211ee4 strd r4, r5, [sp, #56] */
/* @0x211ee8 ldrd r0, r1, [r3, #80] */
/* @0x211eec ldrd r4, r5, [r3, #88] */
/* @0x211ef0 strd r0, r1, [sp, #64] */
/* @0x211ef4 strd r4, r5, [sp, #72] */
/* @0x211ef8 ldrd r0, r1, [r3, #96] */
/* @0x211efc ldrd r4, r5, [r3, #104] */
/* @0x211f00 strd r0, r1, [sp, #80] */
/* @0x211f04 strd r4, r5, [sp, #88] */
/* @0x211f08 ldrd r0, r1, [r3] */
/* @0x211f0c ldr r12, [r2, #0xc] */
/* @0x211f10 ldrd r2, r3, [r3, #8] */
/* @0x211f14 blx r12 */
/* @0x211f18 stm r6, {r0, r1} */
/* @0x211f1c b 0x2116d8 <_Z9Call_RealiPdP6RValue+0xbc> */
/* @0x211f20 andseq pc, sp, r4, lsl #27 */
/* @0x211f24 andseq pc, sp, r12, ror #26 */
/* @0x211f28 ldrd r0, r1, [r3, #16] */
/* @0x211f2c ldrd r4, r5, [r3, #24] */
/* @0x211f30 strd r0, r1, [sp] */
/* @0x211f34 strd r4, r5, [sp, #8] */
/* @0x211f38 ldrd r0, r1, [r3, #32] */
/* @0x211f3c ldrd r4, r5, [r3, #40] */
/* @0x211f40 strd r0, r1, [sp, #16] */
/* @0x211f44 strd r4, r5, [sp, #24] */
/* @0x211f48 ldrd r0, r1, [r3, #48] */
/* @0x211f4c ldrd r4, r5, [r3, #56] */
/* @0x211f50 strd r0, r1, [sp, #32] */
/* @0x211f54 strd r4, r5, [sp, #40] */
/* @0x211f58 ldrd r0, r1, [r3, #64] */
/* @0x211f5c ldrd r4, r5, [r3, #72] */
/* @0x211f60 strd r0, r1, [sp, #48] */
/* @0x211f64 strd r4, r5, [sp, #56] */
/* @0x211f68 ldrd r0, r1, [r3, #80] */
/* @0x211f6c ldrd r4, r5, [r3, #88] */
/* @0x211f70 strd r0, r1, [sp, #64] */
/* @0x211f74 strd r4, r5, [sp, #72] */
/* @0x211f78 ldrd r0, r1, [r3, #96] */
/* @0x211f7c ldrd r4, r5, [r3, #104] */
/* @0x211f80 strd r0, r1, [sp, #80] */
/* @0x211f84 strd r4, r5, [sp, #88] */
/* @0x211f88 ldrd r4, r5, [r3, #112] */
/* @0x211f8c ldrd r0, r1, [r3] */
/* @0x211f90 strd r4, r5, [sp, #96] */
/* @0x211f94 ldr r12, [r2, #0xc] */
/* @0x211f98 ldrd r2, r3, [r3, #8] */
/* @0x211f9c blx r12 */
/* @0x211fa0 stm r6, {r0, r1} */
/* @0x211fa4 b 0x2116d8 <_Z9Call_RealiPdP6RValue+0xbc> */

/* ── FUNC 0x211fa8 · Call_Normal(int, double*, char const**, RValue*) · size=2916 · insn=729 */
/* @0x211fa8 ldr r12, [pc, #0xb54] */
/* @0x211fac push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x211fb0 ldr r12, [pc, r12] */
/* @0x211fb4 sub sp, sp, #20 */
/* @0x211fb8 mov r4, r1 */
/* @0x211fbc ldrb r12, [r12] */
/* @0x211fc0 mov r7, r2 */
/* @0x211fc4 mov r6, r3 */
/* @0x211fc8 cmp r12, #0 */
/* @0x211fcc bne 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x211fd0 ldr r3, [pc, #0xb30] */
/* @0x211fd4 ldr r3, [pc, r3] */
/* @0x211fd8 ldr r2, [r3] */
/* @0x211fdc cmp r0, r2 */
/* @0x211fe0 ldrlt r3, [r3, #0x4] */
/* @0x211fe4 ldrlt r12, [r3, r0, lsl #2] */
/* @0x211fe8 ldr r1, [r12, #0x5c] */
/* @0x211fec ldr r2, [r12, #0x14] */
/* @0x211ff0 cmp r1, #0 */
/* @0x211ff4 movne r3, #2 */
/* @0x211ff8 moveq r3, #1 */
/* @0x211ffc cmp r2, #0 */
/* @0x212000 ble 0x212064 <_Z11Call_NormaliPdPPKcP6RValue+0xbc> */
/* @0x212004 ldr r0, [r12, #0x18] */
/* @0x212008 cmp r0, #0 */
/* @0x21200c addeq r3, r3, #10 */
/* @0x212010 addne r3, r3, #20 */
/* @0x212014 cmp r2, #1 */
/* @0x212018 beq 0x212064 <_Z11Call_NormaliPdPPKcP6RValue+0xbc> */
/* @0x21201c ldr r0, [r12, #0x1c] */
/* @0x212020 cmp r0, #0 */
/* @0x212024 addeq r3, r3, #100 */
/* @0x212028 addne r3, r3, #200 */
/* @0x21202c cmp r2, #2 */
/* @0x212030 beq 0x212064 <_Z11Call_NormaliPdPPKcP6RValue+0xbc> */
/* @0x212034 ldr r0, [r12, #0x20] */
/* @0x212038 cmp r0, #0 */
/* @0x21203c addeq r3, r3, #1000 */
/* @0x212040 addne r3, r3, #2000 */
/* @0x212044 cmp r2, #3 */
/* @0x212048 beq 0x212064 <_Z11Call_NormaliPdPPKcP6RValue+0xbc> */
/* @0x21204c ldr r2, [r12, #0x24] */
/* @0x212050 cmp r2, #0 */
/* @0x212054 addeq r3, r3, #9984 */
/* @0x212058 addne r3, r3, #19968 */
/* @0x21205c addeq r3, r3, #16 */
/* @0x212060 addne r3, r3, #32 */
/* @0x212064 movw r2, #0x2b67 */
/* @0x212068 cmp r3, r2 */
/* @0x21206c str r1, [r6, #0xc] */
/* @0x212070 beq 0x212954 <_Z11Call_NormaliPdPPKcP6RValue+0x9ac> */
/* @0x212074 ble 0x212118 <_Z11Call_NormaliPdPPKcP6RValue+0x170> */
/* @0x212078 movw r2, #0x5277 */
/* @0x21207c cmp r3, r2 */
/* @0x212080 beq 0x21297c <_Z11Call_NormaliPdPPKcP6RValue+0x9d4> */
/* @0x212084 bgt 0x212190 <_Z11Call_NormaliPdPPKcP6RValue+0x1e8> */
/* @0x212088 movw r2, #0x2f4f */
/* @0x21208c cmp r3, r2 */
/* @0x212090 beq 0x21268c <_Z11Call_NormaliPdPPKcP6RValue+0x6e4> */
/* @0x212094 bgt 0x212294 <_Z11Call_NormaliPdPPKcP6RValue+0x2ec> */
/* @0x212098 sub r2, r2, #900 */
/* @0x21209c cmp r3, r2 */
/* @0x2120a0 beq 0x2125c4 <_Z11Call_NormaliPdPPKcP6RValue+0x61c> */
/* @0x2120a4 bgt 0x2124d8 <_Z11Call_NormaliPdPPKcP6RValue+0x530> */
/* @0x2120a8 movw r2, #0x2b71 */
/* @0x2120ac cmp r3, r2 */
/* @0x2120b0 beq 0x21290c <_Z11Call_NormaliPdPPKcP6RValue+0x964> */
/* @0x2120b4 add r2, r2, #1 */
/* @0x2120b8 cmp r3, r2 */
/* @0x2120bc beq 0x2128e4 <_Z11Call_NormaliPdPPKcP6RValue+0x93c> */
/* @0x2120c0 movw r2, #0x2b68 */
/* @0x2120c4 cmp r3, r2 */
/* @0x2120c8 bne 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x2120cc ldrd r2, r3, [r4, #16] */
/* @0x2120d0 ldrd r0, r1, [r4, #24] */
/* @0x2120d4 strd r2, r3, [sp] */
/* @0x2120d8 strd r0, r1, [sp, #8] */
/* @0x2120dc ldrd r0, r1, [r4] */
/* @0x2120e0 ldr r12, [r12, #0xc] */
/* @0x2120e4 ldrd r2, r3, [r4, #8] */
/* @0x2120e8 blx r12 */
/* @0x2120ec mov r1, r0 */
/* @0x2120f0 b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x2120f4 ldr lr, [r7, #0xc] */
/* @0x2120f8 ldrd r0, r1, [r4] */
/* @0x2120fc ldmib r7, {r2, r3} */
/* @0x212100 str lr, [sp] */
/* @0x212104 ldr r12, [r12, #0xc] */
/* @0x212108 blx r12 */
/* @0x21210c stm r6, {r0, r1} */
/* @0x212110 add sp, sp, #20 */
/* @0x212114 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x212118 movw r2, #0x457 */
/* @0x21211c cmp r3, r2 */
/* @0x212120 beq 0x2129a4 <_Z11Call_NormaliPdPPKcP6RValue+0x9fc> */
/* @0x212124 ble 0x2121fc <_Z11Call_NormaliPdPPKcP6RValue+0x254> */
/* @0x212128 movw r2, #0x83f */
/* @0x21212c cmp r3, r2 */
/* @0x212130 beq 0x212934 <_Z11Call_NormaliPdPPKcP6RValue+0x98c> */
/* @0x212134 cmp r3, #2112 */
/* @0x212138 bge 0x212244 <_Z11Call_NormaliPdPPKcP6RValue+0x29c> */
/* @0x21213c sub r2, r2, #900 */
/* @0x212140 cmp r3, r2 */
/* @0x212144 beq 0x2125a4 <_Z11Call_NormaliPdPPKcP6RValue+0x5fc> */
/* @0x212148 bgt 0x212448 <_Z11Call_NormaliPdPPKcP6RValue+0x4a0> */
/* @0x21214c movw r2, #0x461 */
/* @0x212150 cmp r3, r2 */
/* @0x212154 beq 0x212874 <_Z11Call_NormaliPdPPKcP6RValue+0x8cc> */
/* @0x212158 add r2, r2, #1 */
/* @0x21215c cmp r3, r2 */
/* @0x212160 beq 0x212854 <_Z11Call_NormaliPdPPKcP6RValue+0x8ac> */
/* @0x212164 movw r2, #0x458 */
/* @0x212168 cmp r3, r2 */
/* @0x21216c bne 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x212170 ldrd r2, r3, [r4, #16] */
/* @0x212174 ldrd r0, r1, [r4] */
/* @0x212178 strd r2, r3, [sp] */
/* @0x21217c ldr r12, [r12, #0xc] */
/* @0x212180 ldrd r2, r3, [r4, #8] */
/* @0x212184 blx r12 */
/* @0x212188 mov r1, r0 */
/* @0x21218c b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x212190 movw r2, #0x565f */
/* @0x212194 cmp r3, r2 */
/* @0x212198 beq 0x2126f4 <_Z11Call_NormaliPdPPKcP6RValue+0x74c> */
/* @0x21219c bgt 0x2122f0 <_Z11Call_NormaliPdPPKcP6RValue+0x348> */
/* @0x2121a0 sub r2, r2, #900 */
/* @0x2121a4 cmp r3, r2 */
/* @0x2121a8 beq 0x212600 <_Z11Call_NormaliPdPPKcP6RValue+0x658> */
/* @0x2121ac bgt 0x21248c <_Z11Call_NormaliPdPPKcP6RValue+0x4e4> */
/* @0x2121b0 movw r2, #0x5281 */
/* @0x2121b4 cmp r3, r2 */
/* @0x2121b8 beq 0x2128bc <_Z11Call_NormaliPdPPKcP6RValue+0x914> */
/* @0x2121bc add r2, r2, #1 */
/* @0x2121c0 cmp r3, r2 */
/* @0x2121c4 beq 0x212894 <_Z11Call_NormaliPdPPKcP6RValue+0x8ec> */
/* @0x2121c8 movw r2, #0x5278 */
/* @0x2121cc cmp r3, r2 */
/* @0x2121d0 bne 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x2121d4 ldrd r2, r3, [r4, #16] */
/* @0x2121d8 ldr lr, [r7, #0xc] */
/* @0x2121dc ldrd r0, r1, [r4] */
/* @0x2121e0 strd r2, r3, [sp] */
/* @0x2121e4 ldrd r2, r3, [r4, #8] */
/* @0x2121e8 str lr, [sp, #0x8] */
/* @0x2121ec ldr r12, [r12, #0xc] */
/* @0x2121f0 blx r12 */
/* @0x2121f4 mov r1, r0 */
/* @0x2121f8 b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x2121fc cmp r3, #111 */
/* @0x212200 beq 0x21265c <_Z11Call_NormaliPdPPKcP6RValue+0x6b4> */
/* @0x212204 ble 0x212348 <_Z11Call_NormaliPdPPKcP6RValue+0x3a0> */
/* @0x212208 cmp r3, #211 */
/* @0x21220c beq 0x212718 <_Z11Call_NormaliPdPPKcP6RValue+0x770> */
/* @0x212210 bgt 0x212418 <_Z11Call_NormaliPdPPKcP6RValue+0x470> */
/* @0x212214 cmp r3, #121 */
/* @0x212218 beq 0x2129dc <_Z11Call_NormaliPdPPKcP6RValue+0xa34> */
/* @0x21221c cmp r3, #122 */
/* @0x212220 beq 0x2129c4 <_Z11Call_NormaliPdPPKcP6RValue+0xa1c> */
/* @0x212224 cmp r3, #112 */
/* @0x212228 bne 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x21222c ldrd r0, r1, [r4] */
/* @0x212230 ldr r12, [r12, #0xc] */
/* @0x212234 ldrd r2, r3, [r4, #8] */
/* @0x212238 blx r12 */
/* @0x21223c mov r1, r0 */
/* @0x212240 b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x212244 movw r2, #0x8a3 */
/* @0x212248 cmp r3, r2 */
/* @0x21224c beq 0x212674 <_Z11Call_NormaliPdPPKcP6RValue+0x6cc> */
/* @0x212250 bgt 0x2123dc <_Z11Call_NormaliPdPPKcP6RValue+0x434> */
/* @0x212254 movw r2, #0x849 */
/* @0x212258 cmp r3, r2 */
/* @0x21225c beq 0x2126d4 <_Z11Call_NormaliPdPPKcP6RValue+0x72c> */
/* @0x212260 add r2, r2, #1 */
/* @0x212264 cmp r3, r2 */
/* @0x212268 beq 0x2126b4 <_Z11Call_NormaliPdPPKcP6RValue+0x70c> */
/* @0x21226c cmp r3, #2112 */
/* @0x212270 bne 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x212274 ldr lr, [r7, #0x8] */
/* @0x212278 ldrd r0, r1, [r4] */
/* @0x21227c ldrd r2, r3, [r4, #8] */
/* @0x212280 str lr, [sp] */
/* @0x212284 ldr r12, [r12, #0xc] */
/* @0x212288 blx r12 */
/* @0x21228c mov r1, r0 */
/* @0x212290 b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x212294 movw r2, #0x2fb3 */
/* @0x212298 cmp r3, r2 */
/* @0x21229c beq 0x212638 <_Z11Call_NormaliPdPPKcP6RValue+0x690> */
/* @0x2122a0 bgt 0x212394 <_Z11Call_NormaliPdPPKcP6RValue+0x3ec> */
/* @0x2122a4 movw r2, #0x2f59 */
/* @0x2122a8 cmp r3, r2 */
/* @0x2122ac beq 0x21282c <_Z11Call_NormaliPdPPKcP6RValue+0x884> */
/* @0x2122b0 add r2, r2, #1 */
/* @0x2122b4 cmp r3, r2 */
/* @0x2122b8 beq 0x212804 <_Z11Call_NormaliPdPPKcP6RValue+0x85c> */
/* @0x2122bc movw r2, #0x2f50 */
/* @0x2122c0 cmp r3, r2 */
/* @0x2122c4 bne 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x2122c8 ldrd r2, r3, [r4, #24] */
/* @0x2122cc ldr lr, [r7, #0x8] */
/* @0x2122d0 ldrd r0, r1, [r4] */
/* @0x2122d4 strd r2, r3, [sp, #8] */
/* @0x2122d8 ldrd r2, r3, [r4, #8] */
/* @0x2122dc str lr, [sp] */
/* @0x2122e0 ldr r12, [r12, #0xc] */
/* @0x2122e4 blx r12 */
/* @0x2122e8 mov r1, r0 */
/* @0x2122ec b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x2122f0 movw r2, #0x56c3 */
/* @0x2122f4 cmp r3, r2 */
/* @0x2122f8 beq 0x2120f4 <_Z11Call_NormaliPdPPKcP6RValue+0x14c> */
/* @0x2122fc bgt 0x212524 <_Z11Call_NormaliPdPPKcP6RValue+0x57c> */
/* @0x212300 movw r2, #0x5669 */
/* @0x212304 cmp r3, r2 */
/* @0x212308 beq 0x2127b4 <_Z11Call_NormaliPdPPKcP6RValue+0x80c> */
/* @0x21230c add r2, r2, #1 */
/* @0x212310 cmp r3, r2 */
/* @0x212314 beq 0x21278c <_Z11Call_NormaliPdPPKcP6RValue+0x7e4> */
/* @0x212318 movw r2, #0x5660 */
/* @0x21231c cmp r3, r2 */
/* @0x212320 bne 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x212324 ldr r5, [r7, #0x8] */
/* @0x212328 ldr lr, [r7, #0xc] */
/* @0x21232c ldrd r0, r1, [r4] */
/* @0x212330 ldrd r2, r3, [r4, #8] */
/* @0x212334 stm sp, {r5, lr} */
/* @0x212338 ldr r12, [r12, #0xc] */
/* @0x21233c blx r12 */
/* @0x212340 mov r1, r0 */
/* @0x212344 b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x212348 cmp r3, #11 */
/* @0x21234c beq 0x212570 <_Z11Call_NormaliPdPPKcP6RValue+0x5c8> */
/* @0x212350 ble 0x212584 <_Z11Call_NormaliPdPPKcP6RValue+0x5dc> */
/* @0x212354 cmp r3, #21 */
/* @0x212358 beq 0x212730 <_Z11Call_NormaliPdPPKcP6RValue+0x788> */
/* @0x21235c cmp r3, #22 */
/* @0x212360 beq 0x2125ec <_Z11Call_NormaliPdPPKcP6RValue+0x644> */
/* @0x212364 cmp r3, #12 */
/* @0x212368 bne 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x21236c ldrd r0, r1, [r4] */
/* @0x212370 ldr r3, [r12, #0xc] */
/* @0x212374 blx r3 */
/* @0x212378 mov r1, r0 */
/* @0x21237c cmp r1, #0 */
/* @0x212380 beq 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x212384 mov r0, r6 */
/* @0x212388 add sp, sp, #20 */
/* @0x21238c pop {r4, r5, r6, r7, r8, r9, lr} */
/* @0x212390 b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x212394 movw r2, #0x2fbd */
/* @0x212398 cmp r3, r2 */
/* @0x21239c beq 0x212a40 <_Z11Call_NormaliPdPPKcP6RValue+0xa98> */
/* @0x2123a0 add r2, r2, #1 */
/* @0x2123a4 cmp r3, r2 */
/* @0x2123a8 beq 0x212a1c <_Z11Call_NormaliPdPPKcP6RValue+0xa74> */
/* @0x2123ac movw r2, #0x2fb4 */
/* @0x2123b0 cmp r3, r2 */
/* @0x2123b4 bne 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x2123b8 ldrd r0, r1, [r4, #24] */
/* @0x2123bc ldr r2, [r7, #0x4] */
/* @0x2123c0 ldr r3, [r7, #0x8] */
/* @0x2123c4 strd r0, r1, [sp] */
/* @0x2123c8 ldrd r0, r1, [r4] */
/* @0x2123cc ldr r12, [r12, #0xc] */
/* @0x2123d0 blx r12 */
/* @0x2123d4 mov r1, r0 */
/* @0x2123d8 b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x2123dc movw r2, #0x8ad */
/* @0x2123e0 cmp r3, r2 */
/* @0x2123e4 beq 0x212aa8 <_Z11Call_NormaliPdPPKcP6RValue+0xb00> */
/* @0x2123e8 add r2, r2, #1 */
/* @0x2123ec cmp r3, r2 */
/* @0x2123f0 beq 0x212a94 <_Z11Call_NormaliPdPPKcP6RValue+0xaec> */
/* @0x2123f4 movw r2, #0x8a4 */
/* @0x2123f8 cmp r3, r2 */
/* @0x2123fc bne 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x212400 ldrd r0, r1, [r4] */
/* @0x212404 ldr r12, [r12, #0xc] */
/* @0x212408 ldmib r7, {r2, r3} */
/* @0x21240c blx r12 */
/* @0x212410 mov r1, r0 */
/* @0x212414 b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x212418 cmp r3, #221 */
/* @0x21241c beq 0x212a08 <_Z11Call_NormaliPdPPKcP6RValue+0xa60> */
/* @0x212420 cmp r3, #222 */
/* @0x212424 beq 0x2129f4 <_Z11Call_NormaliPdPPKcP6RValue+0xa4c> */
/* @0x212428 cmp r3, #212 */
/* @0x21242c bne 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x212430 ldrd r0, r1, [r4] */
/* @0x212434 ldr r3, [r12, #0xc] */
/* @0x212438 ldr r2, [r7, #0x4] */
/* @0x21243c blx r3 */
/* @0x212440 mov r1, r0 */
/* @0x212444 b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x212448 movw r2, #0x4c5 */
/* @0x21244c cmp r3, r2 */
/* @0x212450 beq 0x212a7c <_Z11Call_NormaliPdPPKcP6RValue+0xad4> */
/* @0x212454 add r2, r2, #1 */
/* @0x212458 cmp r3, r2 */
/* @0x21245c beq 0x212a64 <_Z11Call_NormaliPdPPKcP6RValue+0xabc> */
/* @0x212460 movw r2, #0x4bc */
/* @0x212464 cmp r3, r2 */
/* @0x212468 bne 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x21246c ldrd r8, r9, [r4, #16] */
/* @0x212470 ldrd r0, r1, [r4] */
/* @0x212474 ldr r2, [r7, #0x4] */
/* @0x212478 strd r8, r9, [sp] */
/* @0x21247c ldr r3, [r12, #0xc] */
/* @0x212480 blx r3 */
/* @0x212484 mov r1, r0 */
/* @0x212488 b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x21248c movw r2, #0x52e5 */
/* @0x212490 cmp r3, r2 */
/* @0x212494 beq 0x212ae4 <_Z11Call_NormaliPdPPKcP6RValue+0xb3c> */
/* @0x212498 add r2, r2, #1 */
/* @0x21249c cmp r3, r2 */
/* @0x2124a0 beq 0x212abc <_Z11Call_NormaliPdPPKcP6RValue+0xb14> */
/* @0x2124a4 movw r2, #0x52dc */
/* @0x2124a8 cmp r3, r2 */
/* @0x2124ac bne 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x2124b0 ldr r3, [r7, #0xc] */
/* @0x2124b4 ldrd r0, r1, [r4, #16] */
/* @0x2124b8 ldr r2, [r7, #0x4] */
/* @0x2124bc strd r0, r1, [sp] */
/* @0x2124c0 ldrd r0, r1, [r4] */
/* @0x2124c4 str r3, [sp, #0x8] */
/* @0x2124c8 ldr r3, [r12, #0xc] */
/* @0x2124cc blx r3 */
/* @0x2124d0 mov r1, r0 */
/* @0x2124d4 b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x2124d8 movw r2, #0x2bd5 */
/* @0x2124dc cmp r3, r2 */
/* @0x2124e0 beq 0x212768 <_Z11Call_NormaliPdPPKcP6RValue+0x7c0> */
/* @0x2124e4 add r2, r2, #1 */
/* @0x2124e8 cmp r3, r2 */
/* @0x2124ec beq 0x212744 <_Z11Call_NormaliPdPPKcP6RValue+0x79c> */
/* @0x2124f0 movw r2, #0x2bcc */
/* @0x2124f4 cmp r3, r2 */
/* @0x2124f8 bne 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x2124fc ldrd r0, r1, [r4, #16] */
/* @0x212500 ldrd r8, r9, [r4, #24] */
/* @0x212504 ldr r2, [r7, #0x4] */
/* @0x212508 strd r0, r1, [sp] */
/* @0x21250c strd r8, r9, [sp, #8] */
/* @0x212510 ldrd r0, r1, [r4] */
/* @0x212514 ldr r3, [r12, #0xc] */
/* @0x212518 blx r3 */
/* @0x21251c mov r1, r0 */
/* @0x212520 b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x212524 movw r2, #0x56cd */
/* @0x212528 cmp r3, r2 */
/* @0x21252c beq 0x2127f0 <_Z11Call_NormaliPdPPKcP6RValue+0x848> */
/* @0x212530 add r2, r2, #1 */
/* @0x212534 cmp r3, r2 */
/* @0x212538 beq 0x2127dc <_Z11Call_NormaliPdPPKcP6RValue+0x834> */
/* @0x21253c movw r2, #0x56c4 */
/* @0x212540 cmp r3, r2 */
/* @0x212544 bne 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x212548 ldrd r4, r5, [r4] */
/* @0x21254c ldr r1, [r7, #0xc] */
/* @0x212550 ldmib r7, {r2, r3} */
/* @0x212554 mov r0, r4 */
/* @0x212558 str r1, [sp] */
/* @0x21255c mov r1, r5 */
/* @0x212560 ldr r12, [r12, #0xc] */
/* @0x212564 blx r12 */
/* @0x212568 mov r1, r0 */
/* @0x21256c b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x212570 ldr r3, [r12, #0xc] */
/* @0x212574 ldrd r0, r1, [r4] */
/* @0x212578 blx r3 */
/* @0x21257c stm r6, {r0, r1} */
/* @0x212580 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x212584 cmp r3, #1 */
/* @0x212588 beq 0x212628 <_Z11Call_NormaliPdPPKcP6RValue+0x680> */
/* @0x21258c cmp r3, #2 */
/* @0x212590 bne 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x212594 ldr r3, [r12, #0xc] */
/* @0x212598 blx r3 */
/* @0x21259c mov r1, r0 */
/* @0x2125a0 b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x2125a4 ldrd r8, r9, [r4, #16] */
/* @0x2125a8 ldr r2, [r7, #0x4] */
/* @0x2125ac ldrd r0, r1, [r4] */
/* @0x2125b0 strd r8, r9, [sp] */
/* @0x2125b4 ldr r3, [r12, #0xc] */
/* @0x2125b8 blx r3 */
/* @0x2125bc stm r6, {r0, r1} */
/* @0x2125c0 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x2125c4 ldrd r0, r1, [r4, #16] */
/* @0x2125c8 ldrd r8, r9, [r4, #24] */
/* @0x2125cc ldr r2, [r7, #0x4] */
/* @0x2125d0 strd r0, r1, [sp] */
/* @0x2125d4 strd r8, r9, [sp, #8] */
/* @0x2125d8 ldrd r0, r1, [r4] */
/* @0x2125dc ldr r3, [r12, #0xc] */
/* @0x2125e0 blx r3 */
/* @0x2125e4 stm r6, {r0, r1} */
/* @0x2125e8 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x2125ec ldr r3, [r12, #0xc] */
/* @0x2125f0 ldr r0, [r7] */
/* @0x2125f4 blx r3 */
/* @0x2125f8 mov r1, r0 */
/* @0x2125fc b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x212600 ldr r3, [r7, #0xc] */
/* @0x212604 ldrd r0, r1, [r4, #16] */
/* @0x212608 ldr r2, [r7, #0x4] */
/* @0x21260c strd r0, r1, [sp] */
/* @0x212610 ldrd r0, r1, [r4] */
/* @0x212614 str r3, [sp, #0x8] */
/* @0x212618 ldr r3, [r12, #0xc] */
/* @0x21261c blx r3 */
/* @0x212620 stm r6, {r0, r1} */
/* @0x212624 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x212628 ldr r3, [r12, #0xc] */
/* @0x21262c blx r3 */
/* @0x212630 stm r6, {r0, r1} */
/* @0x212634 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x212638 ldrd r0, r1, [r4, #24] */
/* @0x21263c ldr r2, [r7, #0x4] */
/* @0x212640 ldr r3, [r7, #0x8] */
/* @0x212644 strd r0, r1, [sp] */
/* @0x212648 ldrd r0, r1, [r4] */
/* @0x21264c ldr r12, [r12, #0xc] */
/* @0x212650 blx r12 */
/* @0x212654 stm r6, {r0, r1} */
/* @0x212658 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x21265c ldr r12, [r12, #0xc] */
/* @0x212660 ldrd r0, r1, [r4] */
/* @0x212664 ldrd r2, r3, [r4, #8] */
/* @0x212668 blx r12 */
/* @0x21266c stm r6, {r0, r1} */
/* @0x212670 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x212674 ldr r12, [r12, #0xc] */
/* @0x212678 ldrd r0, r1, [r4] */
/* @0x21267c ldmib r7, {r2, r3} */
/* @0x212680 blx r12 */
/* @0x212684 stm r6, {r0, r1} */
/* @0x212688 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x21268c ldrd r2, r3, [r4, #24] */
/* @0x212690 ldr lr, [r7, #0x8] */
/* @0x212694 ldrd r0, r1, [r4] */
/* @0x212698 strd r2, r3, [sp, #8] */
/* @0x21269c ldrd r2, r3, [r4, #8] */
/* @0x2126a0 str lr, [sp] */
/* @0x2126a4 ldr r12, [r12, #0xc] */
/* @0x2126a8 blx r12 */
/* @0x2126ac stm r6, {r0, r1} */
/* @0x2126b0 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x2126b4 ldr r1, [r7, #0x8] */
/* @0x2126b8 ldrd r2, r3, [r4, #8] */
/* @0x2126bc ldr r0, [r7] */
/* @0x2126c0 str r1, [sp] */
/* @0x2126c4 ldr r1, [r12, #0xc] */
/* @0x2126c8 blx r1 */
/* @0x2126cc mov r1, r0 */
/* @0x2126d0 b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x2126d4 ldr r1, [r7, #0x8] */
/* @0x2126d8 ldrd r2, r3, [r4, #8] */
/* @0x2126dc ldr r0, [r7] */
/* @0x2126e0 str r1, [sp] */
/* @0x2126e4 ldr r1, [r12, #0xc] */
/* @0x2126e8 blx r1 */
/* @0x2126ec stm r6, {r0, r1} */
/* @0x2126f0 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x2126f4 ldr r5, [r7, #0x8] */
/* @0x2126f8 ldr lr, [r7, #0xc] */
/* @0x2126fc ldrd r0, r1, [r4] */
/* @0x212700 ldrd r2, r3, [r4, #8] */
/* @0x212704 stm sp, {r5, lr} */
/* @0x212708 ldr r12, [r12, #0xc] */
/* @0x21270c blx r12 */
/* @0x212710 stm r6, {r0, r1} */
/* @0x212714 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x212718 ldr r3, [r12, #0xc] */
/* @0x21271c ldr r2, [r7, #0x4] */
/* @0x212720 ldrd r0, r1, [r4] */
/* @0x212724 blx r3 */
/* @0x212728 stm r6, {r0, r1} */
/* @0x21272c b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x212730 ldr r3, [r12, #0xc] */
/* @0x212734 ldr r0, [r7] */
/* @0x212738 blx r3 */
/* @0x21273c stm r6, {r0, r1} */
/* @0x212740 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x212744 ldrd r2, r3, [r4, #24] */
/* @0x212748 ldr r1, [r7, #0x4] */
/* @0x21274c ldr r0, [r7] */
/* @0x212750 strd r2, r3, [sp] */
/* @0x212754 ldrd r2, r3, [r4, #16] */
/* @0x212758 ldr r12, [r12, #0xc] */
/* @0x21275c blx r12 */
/* @0x212760 mov r1, r0 */
/* @0x212764 b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x212768 ldrd r2, r3, [r4, #24] */
/* @0x21276c ldr r0, [r7] */
/* @0x212770 ldr r1, [r7, #0x4] */
/* @0x212774 strd r2, r3, [sp] */
/* @0x212778 ldrd r2, r3, [r4, #16] */
/* @0x21277c ldr r12, [r12, #0xc] */
/* @0x212780 blx r12 */
/* @0x212784 stm r6, {r0, r1} */
/* @0x212788 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x21278c ldr r1, [r7, #0xc] */
/* @0x212790 ldr lr, [r7, #0x8] */
/* @0x212794 ldrd r2, r3, [r4, #8] */
/* @0x212798 ldr r0, [r7] */
/* @0x21279c str lr, [sp] */
/* @0x2127a0 str r1, [sp, #0x4] */
/* @0x2127a4 ldr r1, [r12, #0xc] */
/* @0x2127a8 blx r1 */
/* @0x2127ac mov r1, r0 */
/* @0x2127b0 b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x2127b4 ldr r1, [r7, #0xc] */
/* @0x2127b8 ldr lr, [r7, #0x8] */
/* @0x2127bc ldrd r2, r3, [r4, #8] */
/* @0x2127c0 ldr r0, [r7] */
/* @0x2127c4 str lr, [sp] */
/* @0x2127c8 str r1, [sp, #0x4] */
/* @0x2127cc ldr r1, [r12, #0xc] */
/* @0x2127d0 blx r1 */
/* @0x2127d4 stm r6, {r0, r1} */
/* @0x2127d8 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x2127dc ldm r7, {r0, r1, r2, r3} */
/* @0x2127e0 ldr r12, [r12, #0xc] */
/* @0x2127e4 blx r12 */
/* @0x2127e8 mov r1, r0 */
/* @0x2127ec b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x2127f0 ldr r12, [r12, #0xc] */
/* @0x2127f4 ldm r7, {r0, r1, r2, r3} */
/* @0x2127f8 blx r12 */
/* @0x2127fc stm r6, {r0, r1} */
/* @0x212800 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x212804 ldr r1, [r7, #0x8] */
/* @0x212808 ldrd r2, r3, [r4, #24] */
/* @0x21280c ldr r0, [r7] */
/* @0x212810 strd r2, r3, [sp, #8] */
/* @0x212814 ldrd r2, r3, [r4, #8] */
/* @0x212818 str r1, [sp] */
/* @0x21281c ldr r1, [r12, #0xc] */
/* @0x212820 blx r1 */
/* @0x212824 mov r1, r0 */
/* @0x212828 b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x21282c ldr r1, [r7, #0x8] */
/* @0x212830 ldrd r2, r3, [r4, #24] */
/* @0x212834 ldr r0, [r7] */
/* @0x212838 strd r2, r3, [sp, #8] */
/* @0x21283c ldrd r2, r3, [r4, #8] */
/* @0x212840 str r1, [sp] */
/* @0x212844 ldr r1, [r12, #0xc] */
/* @0x212848 blx r1 */
/* @0x21284c stm r6, {r0, r1} */
/* @0x212850 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x212854 ldrd r8, r9, [r4, #16] */
/* @0x212858 ldr r0, [r7] */
/* @0x21285c ldrd r2, r3, [r4, #8] */
/* @0x212860 strd r8, r9, [sp] */
/* @0x212864 ldr r1, [r12, #0xc] */
/* @0x212868 blx r1 */
/* @0x21286c mov r1, r0 */
/* @0x212870 b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x212874 ldrd r8, r9, [r4, #16] */
/* @0x212878 ldr r0, [r7] */
/* @0x21287c ldrd r2, r3, [r4, #8] */
/* @0x212880 strd r8, r9, [sp] */
/* @0x212884 ldr r1, [r12, #0xc] */
/* @0x212888 blx r1 */
/* @0x21288c stm r6, {r0, r1} */
/* @0x212890 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x212894 ldr r1, [r7, #0xc] */
/* @0x212898 ldrd r2, r3, [r4, #16] */
/* @0x21289c ldr r0, [r7] */
/* @0x2128a0 strd r2, r3, [sp] */
/* @0x2128a4 ldrd r2, r3, [r4, #8] */
/* @0x2128a8 str r1, [sp, #0x8] */
/* @0x2128ac ldr r1, [r12, #0xc] */
/* @0x2128b0 blx r1 */
/* @0x2128b4 mov r1, r0 */
/* @0x2128b8 b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x2128bc ldr r1, [r7, #0xc] */
/* @0x2128c0 ldrd r2, r3, [r4, #16] */
/* @0x2128c4 ldr r0, [r7] */
/* @0x2128c8 strd r2, r3, [sp] */
/* @0x2128cc ldrd r2, r3, [r4, #8] */
/* @0x2128d0 str r1, [sp, #0x8] */
/* @0x2128d4 ldr r1, [r12, #0xc] */
/* @0x2128d8 blx r1 */
/* @0x2128dc stm r6, {r0, r1} */
/* @0x2128e0 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x2128e4 ldrd r2, r3, [r4, #16] */
/* @0x2128e8 ldrd r8, r9, [r4, #24] */
/* @0x2128ec ldr r0, [r7] */
/* @0x2128f0 strd r2, r3, [sp] */
/* @0x2128f4 strd r8, r9, [sp, #8] */
/* @0x2128f8 ldr r1, [r12, #0xc] */
/* @0x2128fc ldrd r2, r3, [r4, #8] */
/* @0x212900 blx r1 */
/* @0x212904 mov r1, r0 */
/* @0x212908 b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x21290c ldrd r2, r3, [r4, #16] */
/* @0x212910 ldrd r8, r9, [r4, #24] */
/* @0x212914 ldr r0, [r7] */
/* @0x212918 strd r2, r3, [sp] */
/* @0x21291c strd r8, r9, [sp, #8] */
/* @0x212920 ldrd r2, r3, [r4, #8] */
/* @0x212924 ldr r1, [r12, #0xc] */
/* @0x212928 blx r1 */
/* @0x21292c stm r6, {r0, r1} */
/* @0x212930 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x212934 ldr lr, [r7, #0x8] */
/* @0x212938 ldrd r0, r1, [r4] */
/* @0x21293c ldrd r2, r3, [r4, #8] */
/* @0x212940 str lr, [sp] */
/* @0x212944 ldr r12, [r12, #0xc] */
/* @0x212948 blx r12 */
/* @0x21294c stm r6, {r0, r1} */
/* @0x212950 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x212954 ldrd r2, r3, [r4, #16] */
/* @0x212958 ldrd r0, r1, [r4, #24] */
/* @0x21295c strd r2, r3, [sp] */
/* @0x212960 strd r0, r1, [sp, #8] */
/* @0x212964 ldrd r0, r1, [r4] */
/* @0x212968 ldr r12, [r12, #0xc] */
/* @0x21296c ldrd r2, r3, [r4, #8] */
/* @0x212970 blx r12 */
/* @0x212974 stm r6, {r0, r1} */
/* @0x212978 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x21297c ldrd r2, r3, [r4, #16] */
/* @0x212980 ldr lr, [r7, #0xc] */
/* @0x212984 ldrd r0, r1, [r4] */
/* @0x212988 strd r2, r3, [sp] */
/* @0x21298c ldrd r2, r3, [r4, #8] */
/* @0x212990 str lr, [sp, #0x8] */
/* @0x212994 ldr r12, [r12, #0xc] */
/* @0x212998 blx r12 */
/* @0x21299c stm r6, {r0, r1} */
/* @0x2129a0 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x2129a4 ldrd r2, r3, [r4, #16] */
/* @0x2129a8 ldrd r0, r1, [r4] */
/* @0x2129ac strd r2, r3, [sp] */
/* @0x2129b0 ldr r12, [r12, #0xc] */
/* @0x2129b4 ldrd r2, r3, [r4, #8] */
/* @0x2129b8 blx r12 */
/* @0x2129bc stm r6, {r0, r1} */
/* @0x2129c0 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x2129c4 ldr r1, [r12, #0xc] */
/* @0x2129c8 ldr r0, [r7] */
/* @0x2129cc ldrd r2, r3, [r4, #8] */
/* @0x2129d0 blx r1 */
/* @0x2129d4 mov r1, r0 */
/* @0x2129d8 b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x2129dc ldr r1, [r12, #0xc] */
/* @0x2129e0 ldr r0, [r7] */
/* @0x2129e4 ldrd r2, r3, [r4, #8] */
/* @0x2129e8 blx r1 */
/* @0x2129ec stm r6, {r0, r1} */
/* @0x2129f0 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x2129f4 ldm r7, {r0, r1} */
/* @0x2129f8 ldr r3, [r12, #0xc] */
/* @0x2129fc blx r3 */
/* @0x212a00 mov r1, r0 */
/* @0x212a04 b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x212a08 ldr r3, [r12, #0xc] */
/* @0x212a0c ldm r7, {r0, r1} */
/* @0x212a10 blx r3 */
/* @0x212a14 stm r6, {r0, r1} */
/* @0x212a18 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x212a1c ldrd r2, r3, [r4, #24] */
/* @0x212a20 ldr r1, [r7, #0x4] */
/* @0x212a24 ldr r0, [r7] */
/* @0x212a28 strd r2, r3, [sp] */
/* @0x212a2c ldr r2, [r7, #0x8] */
/* @0x212a30 ldr r3, [r12, #0xc] */
/* @0x212a34 blx r3 */
/* @0x212a38 mov r1, r0 */
/* @0x212a3c b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x212a40 ldrd r2, r3, [r4, #24] */
/* @0x212a44 ldr r0, [r7] */
/* @0x212a48 ldr r1, [r7, #0x4] */
/* @0x212a4c strd r2, r3, [sp] */
/* @0x212a50 ldr r2, [r7, #0x8] */
/* @0x212a54 ldr r3, [r12, #0xc] */
/* @0x212a58 blx r3 */
/* @0x212a5c stm r6, {r0, r1} */
/* @0x212a60 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x212a64 ldm r7, {r0, r1} */
/* @0x212a68 ldr r12, [r12, #0xc] */
/* @0x212a6c ldrd r2, r3, [r4, #16] */
/* @0x212a70 blx r12 */
/* @0x212a74 mov r1, r0 */
/* @0x212a78 b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x212a7c ldr r12, [r12, #0xc] */
/* @0x212a80 ldm r7, {r0, r1} */
/* @0x212a84 ldrd r2, r3, [r4, #16] */
/* @0x212a88 blx r12 */
/* @0x212a8c stm r6, {r0, r1} */
/* @0x212a90 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x212a94 ldm r7, {r0, r1, r2} */
/* @0x212a98 ldr r3, [r12, #0xc] */
/* @0x212a9c blx r3 */
/* @0x212aa0 mov r1, r0 */
/* @0x212aa4 b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x212aa8 ldr r3, [r12, #0xc] */
/* @0x212aac ldm r7, {r0, r1, r2} */
/* @0x212ab0 blx r3 */
/* @0x212ab4 stm r6, {r0, r1} */
/* @0x212ab8 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x212abc ldrd r4, r5, [r4, #16] */
/* @0x212ac0 ldr r3, [r7, #0xc] */
/* @0x212ac4 ldm r7, {r0, r1} */
/* @0x212ac8 mov r2, r4 */
/* @0x212acc str r3, [sp] */
/* @0x212ad0 mov r3, r5 */
/* @0x212ad4 ldr r12, [r12, #0xc] */
/* @0x212ad8 blx r12 */
/* @0x212adc mov r1, r0 */
/* @0x212ae0 b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x212ae4 ldr lr, [r7, #0xc] */
/* @0x212ae8 ldrd r2, r3, [r4, #16] */
/* @0x212aec ldm r7, {r0, r1} */
/* @0x212af0 str lr, [sp] */
/* @0x212af4 ldr r12, [r12, #0xc] */
/* @0x212af8 blx r12 */
/* @0x212afc stm r6, {r0, r1} */
/* @0x212b00 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x212b04 ldrsheq pc, [sp], -r12 */
/* @0x212b08 ldrsbeq pc, [sp], -r12 */

/* ── FUNC 0x212b0c · anon_212b0c · size=0 · insn=1 */
/* @0x212b0c andeq r0, r0, r0 */

/* ── FUNC 0x212b10 · DLL_Call(int, int, RValue*, RValue*) · size=520 · insn=128 */
/* @0x212b10 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x212b14 vpush {d8} */
/* @0x212b18 subs r5, r0, #0 */
/* @0x212b1c mov r7, r2 */
/* @0x212b20 sub sp, sp, #228 */
/* @0x212b24 mov r2, #0 */
/* @0x212b28 str r2, [r3, #0xc] */
/* @0x212b2c str r2, [r3] */
/* @0x212b30 str r2, [r3, #0x4] */
/* @0x212b34 blt 0x212b4c <_Z8DLL_CalliiP6RValueS0_+0x3c> */
/* @0x212b38 ldr r0, [pc, #0x1d0] */
/* @0x212b3c ldr r0, [pc, r0] */
/* @0x212b40 ldr r0, [r0] */
/* @0x212b44 cmp r5, r0 */
/* @0x212b48 blt 0x212b58 <_Z8DLL_CalliiP6RValueS0_+0x48> */
/* @0x212b4c add sp, sp, #228 */
/* @0x212b50 vpop {d8} */
/* @0x212b54 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x212b58 ldr r10, [pc, #0x1b4] */
/* @0x212b5c ldr r10, [pc, r10] */
/* @0x212b60 ldr r4, [r10] */
/* @0x212b64 cmp r5, r4 */
/* @0x212b68 ldrlt r2, [r10, #0x4] */
/* @0x212b6c ldrlt r2, [r2, r5, lsl #2] */
/* @0x212b70 ldr r11, [r2, #0x14] */
/* @0x212b74 cmp r11, r1 */
/* @0x212b78 bne 0x212b4c <_Z8DLL_CalliiP6RValueS0_+0x3c> */
/* @0x212b7c ldr r2, [r2, #0x4] */
/* @0x212b80 cmp r2, #0 */
/* @0x212b84 beq 0x212b4c <_Z8DLL_CalliiP6RValueS0_+0x3c> */
/* @0x212b88 add r8, sp, #88 */
/* @0x212b8c add r2, sp, #20 */
/* @0x212b90 mov r1, #0 */
/* @0x212b94 str r2, [sp, #0x8] */
/* @0x212b98 mov r0, r8 */
/* @0x212b9c mov r2, #136 */
/* @0x212ba0 str r3, [sp, #0x4] */
/* @0x212ba4 bl 0xb65b0 <memset@plt> */
/* @0x212ba8 add r0, sp, #20 */
/* @0x212bac mov r1, #0 */
/* @0x212bb0 mov r2, #68 */
/* @0x212bb4 bl 0xb65b0 <memset@plt> */
/* @0x212bb8 cmp r11, #0 */
/* @0x212bbc ldr r3, [sp, #0x4] */
/* @0x212bc0 ble 0x212c3c <_Z8DLL_CalliiP6RValueS0_+0x12c> */
/* @0x212bc4 str r5, [sp, #0xc] */
/* @0x212bc8 mov r4, #0 */
/* @0x212bcc mov r5, r11 */
/* @0x212bd0 mov r9, #1 */
/* @0x212bd4 mov r11, r7 */
/* @0x212bd8 vldr d8, [pc, #296] */
/* @0x212bdc mov r7, r8 */
/* @0x212be0 mov r6, r3 */
/* @0x212be4 b 0x212bfc <_Z8DLL_CalliiP6RValueS0_+0xec> */
/* @0x212be8 vstr d8, [r7] */
/* @0x212bec add r4, r4, #1 */
/* @0x212bf0 add r7, r7, #8 */
/* @0x212bf4 cmp r4, r5 */
/* @0x212bf8 beq 0x212c74 <_Z8DLL_CalliiP6RValueS0_+0x164> */
/* @0x212bfc add r1, r11, r4, lsl #4 */
/* @0x212c00 movw r2, #0x24c3 */
/* @0x212c04 ldr r1, [r1, #0xc] */
/* @0x212c08 bic r1, r1, #-16777216 */
/* @0x212c0c cmp r1, #13 */
/* @0x212c10 lsl r0, r9, r1 */
/* @0x212c14 and r2, r0, r2 */
/* @0x212c18 bhi 0x212be8 <_Z8DLL_CalliiP6RValueS0_+0xd8> */
/* @0x212c1c cmp r2, #0 */
/* @0x212c20 beq 0x212be8 <_Z8DLL_CalliiP6RValueS0_+0xd8> */
/* @0x212c24 mov r0, r11 */
/* @0x212c28 mov r1, r4 */
/* @0x212c2c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x212c30 strd r0, r1, [r7] */
/* @0x212c34 b 0x212bec <_Z8DLL_CalliiP6RValueS0_+0xdc> */
/* @0x212c38 ldr r4, [r10] */
/* @0x212c3c cmp r5, r4 */
/* @0x212c40 mov r0, r5 */
/* @0x212c44 mov r1, r8 */
/* @0x212c48 ldrlt r2, [r10, #0x4] */
/* @0x212c4c movge r2, #0 */
/* @0x212c50 ldrlt r2, [r2, r5, lsl #2] */
/* @0x212c54 ldr r2, [r2, #0x10] */
/* @0x212c58 cmp r2, #1 */
/* @0x212c5c beq 0x212ce8 <_Z8DLL_CalliiP6RValueS0_+0x1d8> */
/* @0x212c60 cmp r11, #4 */
/* @0x212c64 ble 0x212cdc <_Z8DLL_CalliiP6RValueS0_+0x1cc> */
/* @0x212c68 mov r2, r3 */
/* @0x212c6c bl 0x21161c <_Z9Call_RealiPdP6RValue> */
/* @0x212c70 b 0x212b4c <_Z8DLL_CalliiP6RValueS0_+0x3c> */
/* @0x212c74 mov r7, r11 */
/* @0x212c78 mov r11, r5 */
/* @0x212c7c mov r2, r7 */
/* @0x212c80 ldr r5, [sp, #0xc] */
/* @0x212c84 mov r3, r6 */
/* @0x212c88 add r7, r7, #12 */
/* @0x212c8c add r4, r2, r11, lsl #4 */
/* @0x212c90 add r12, sp, #16 */
/* @0x212c94 b 0x212cac <_Z8DLL_CalliiP6RValueS0_+0x19c> */
/* @0x212c98 add r2, r2, #16 */
/* @0x212c9c str r0, [r12, #0x4]! */
/* @0x212ca0 cmp r2, r4 */
/* @0x212ca4 add r7, r7, #16 */
/* @0x212ca8 beq 0x212c38 <_Z8DLL_CalliiP6RValueS0_+0x128> */
/* @0x212cac ldr r1, [r2, #0xc] */
/* @0x212cb0 mov r0, #0 */
/* @0x212cb4 cmp r1, #3 */
/* @0x212cb8 bic lr, r1, #-16777216 */
/* @0x212cbc ldreq r0, [r7, #-0xc] */
/* @0x212cc0 beq 0x212c98 <_Z8DLL_CalliiP6RValueS0_+0x188> */
/* @0x212cc4 cmp lr, #1 */
/* @0x212cc8 bne 0x212c98 <_Z8DLL_CalliiP6RValueS0_+0x188> */
/* @0x212ccc ldr r0, [r7, #-0xc] */
/* @0x212cd0 cmp r0, #0 */
/* @0x212cd4 ldrne r0, [r0] */
/* @0x212cd8 b 0x212c98 <_Z8DLL_CalliiP6RValueS0_+0x188> */
/* @0x212cdc add r2, sp, #20 */
/* @0x212ce0 bl 0x211fa8 <_Z11Call_NormaliPdPPKcP6RValue> */
/* @0x212ce4 b 0x212b4c <_Z8DLL_CalliiP6RValueS0_+0x3c> */
/* @0x212ce8 cmp r11, #4 */
/* @0x212cec ble 0x212cfc <_Z8DLL_CalliiP6RValueS0_+0x1ec> */
/* @0x212cf0 mov r2, r3 */
/* @0x212cf4 bl 0x21012c <_Z13Call_Real_stdiPdP6RValue> */
/* @0x212cf8 b 0x212b4c <_Z8DLL_CalliiP6RValueS0_+0x3c> */
/* @0x212cfc add r2, sp, #20 */
/* @0x212d00 bl 0x210ab8 <_Z15Call_Normal_stdiPdPPKcP6RValue> */
/* @0x212d04 b 0x212b4c <_Z8DLL_CalliiP6RValueS0_+0x3c> */
/* @0x212d10 andseq lr, sp, r8, ror r8 */
/* @0x212d14 andseq lr, sp, r4, asr r8 */

/* ── FUNC 0x212d18 · DLL_Free_All() · size=136 · insn=34 */
/* @0x212d18 push {r3, r4, r5, r6, r7, lr} */
/* @0x212d1c ldr r6, [pc, #0x74] */
/* @0x212d20 ldr r6, [pc, r6] */
/* @0x212d24 ldr r3, [r6] */
/* @0x212d28 cmp r3, #0 */
/* @0x212d2c pople {r3, r4, r5, r6, r7, pc} */
/* @0x212d30 ldr r5, [pc, #0x64] */
/* @0x212d34 mov r4, #0 */
/* @0x212d38 mov r7, r4 */
/* @0x212d3c ldr r5, [pc, r5] */
/* @0x212d40 ldr r2, [r5] */
/* @0x212d44 mov r3, #0 */
/* @0x212d48 cmp r2, r4 */
/* @0x212d4c bgt 0x212d78 <_Z12DLL_Free_Allv+0x60> */
/* @0x212d50 ldr r2, [r7, #0x4] */
/* @0x212d54 cmp r2, #0 */
/* @0x212d58 beq 0x212d64 <_Z12DLL_Free_Allv+0x4c> */
/* @0x212d5c ldr r0, [r3] */
/* @0x212d60 bl 0x214904 <_Z8DLL_FreePKc> */
/* @0x212d64 ldr r3, [r6] */
/* @0x212d68 add r4, r4, #1 */
/* @0x212d6c cmp r3, r4 */
/* @0x212d70 bgt 0x212d40 <_Z12DLL_Free_Allv+0x28> */
/* @0x212d74 pop {r3, r4, r5, r6, r7, pc} */
/* @0x212d78 ldr r3, [r5, #0x4] */
/* @0x212d7c ldr r3, [r3, r4, lsl #2] */
/* @0x212d80 ldr r2, [r3, #0x4] */
/* @0x212d84 cmp r2, #0 */
/* @0x212d88 beq 0x212d64 <_Z12DLL_Free_Allv+0x4c> */
/* @0x212d8c ldr r0, [r3] */
/* @0x212d90 bl 0x214904 <_Z8DLL_FreePKc> */
/* @0x212d94 b 0x212d64 <_Z12DLL_Free_Allv+0x4c> */
/* @0x212d98 mulseq sp, r4, r6 */
/* @0x212d9c andseq lr, sp, r4, ror r6 */

/* ── FUNC 0x212da0 · FINALIZATION_Support_DLL() · size=4 · insn=1 */
/* @0x212da0 b 0x212d18 <_Z12DLL_Free_Allv> */

/* ── FUNC 0x212da4 · Timing_Wait · size=4 · insn=1 */
/* @0x212da4 b 0x2151f0 <Timing_Sleep> */

/* ── FUNC 0x212da8 · String_Replace_Hash(char*) · size=224 · insn=56 */
/* @0x212da8 subs r3, r0, #0 */
/* @0x212dac push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x212db0 sub sp, sp, #12 */
/* @0x212db4 beq 0x212e78 <_Z19String_Replace_HashPc+0xd0> */
/* @0x212db8 ldr r2, [pc, #0xc4] */
/* @0x212dbc ldr r2, [pc, r2] */
/* @0x212dc0 ldrb r6, [r2] */
/* @0x212dc4 cmp r6, #0 */
/* @0x212dc8 bne 0x212e6c <_Z19String_Replace_HashPc+0xc4> */
/* @0x212dcc str r3, [sp] */
/* @0x212dd0 mov r5, r6 */
/* @0x212dd4 str r3, [sp, #0x4] */
/* @0x212dd8 add r8, sp, #4 */
/* @0x212ddc mov r9, #10 */
/* @0x212de0 b 0x212e20 <_Z19String_Replace_HashPc+0x78> */
/* @0x212de4 cmp r5, #0 */
/* @0x212de8 movle r3, #0 */
/* @0x212dec movgt r3, #1 */
/* @0x212df0 cmp r6, #92 */
/* @0x212df4 mov r6, r4 */
/* @0x212df8 movne r3, #0 */
/* @0x212dfc cmp r3, #0 */
/* @0x212e00 ldr r3, [sp, #0x4] */
/* @0x212e04 addeq r5, r5, #1 */
/* @0x212e08 moveq r6, r4 */
/* @0x212e0c addeq r2, r3, #1 */
/* @0x212e10 streq r2, [sp, #0x4] */
/* @0x212e14 strbne r4, [r3, #-0x1] */
/* @0x212e18 strbeq r9, [r3] */
/* @0x212e1c ldr r3, [sp] */
/* @0x212e20 ldrb r3, [r3] */
/* @0x212e24 mov r0, sp */
/* @0x212e28 cmp r3, #0 */
/* @0x212e2c beq 0x212e58 <_Z19String_Replace_HashPc+0xb0> */
/* @0x212e30 bl 0x10fb38 <utf8_extract_char> */
/* @0x212e34 mov r4, r0 */
/* @0x212e38 cmp r4, #35 */
/* @0x212e3c mov r1, r0 */
/* @0x212e40 mov r0, r8 */
/* @0x212e44 beq 0x212de4 <_Z19String_Replace_HashPc+0x3c> */
/* @0x212e48 bl 0x10fe28 <utf8_add_char> */
/* @0x212e4c add r5, r5, #1 */
/* @0x212e50 mov r6, r4 */
/* @0x212e54 b 0x212e1c <_Z19String_Replace_HashPc+0x74> */
/* @0x212e58 ldr r2, [sp, #0x4] */
/* @0x212e5c mov r0, r5 */
/* @0x212e60 strb r3, [r2] */
/* @0x212e64 add sp, sp, #12 */
/* @0x212e68 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x212e6c bl 0x110648 <utf8_strlen> */
/* @0x212e70 add sp, sp, #12 */
/* @0x212e74 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x212e78 mov r0, r3 */
/* @0x212e7c add sp, sp, #12 */
/* @0x212e80 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x212e84 andseq r10, sp, r8, ror #22 */

/* ── FUNC 0x212e88 · StringToFont(char const*, TFont&) · size=16 · insn=4 */
/* @0x212e88 ldr r0, [pc, #0x4] */
/* @0x212e8c add r0, pc, r0 */
/* @0x212e90 b 0xc4b0c <_Z11ShowMessagePKc> */
/* @0x212e94 ldrsbeq r0, [r4], -r8 */

/* ── FUNC 0x212e98 · IsBigEndian() · size=8 · insn=2 */
/* @0x212e98 mov r0, #0 */
/* @0x212e9c bx lr */

/* ── FUNC 0x212ea0 · _CountLinesInText(char*) · size=112 · insn=28 */
/* @0x212ea0 cmp r0, #0 */
/* @0x212ea4 bxeq lr */
/* @0x212ea8 ldrb r3, [r0] */
/* @0x212eac cmp r3, #0 */
/* @0x212eb0 beq 0x212f08 <_Z17_CountLinesInTextPc+0x68> */
/* @0x212eb4 mov r1, #0 */
/* @0x212eb8 mov r2, r0 */
/* @0x212ebc mov r0, r1 */
/* @0x212ec0 b 0x212ed4 <_Z17_CountLinesInTextPc+0x34> */
/* @0x212ec4 mov r1, #0 */
/* @0x212ec8 ldrb r3, [r2, #0x1]! */
/* @0x212ecc cmp r3, #0 */
/* @0x212ed0 beq 0x212f04 <_Z17_CountLinesInTextPc+0x64> */
/* @0x212ed4 cmp r3, #13 */
/* @0x212ed8 addeq r0, r0, #1 */
/* @0x212edc moveq r1, #1 */
/* @0x212ee0 beq 0x212ec8 <_Z17_CountLinesInTextPc+0x28> */
/* @0x212ee4 cmp r3, #10 */
/* @0x212ee8 bne 0x212ec4 <_Z17_CountLinesInTextPc+0x24> */
/* @0x212eec cmp r1, #0 */
/* @0x212ef0 addeq r0, r0, #1 */
/* @0x212ef4 bne 0x212ec4 <_Z17_CountLinesInTextPc+0x24> */
/* @0x212ef8 ldrb r3, [r2, #0x1]! */
/* @0x212efc cmp r3, #0 */
/* @0x212f00 bne 0x212ed4 <_Z17_CountLinesInTextPc+0x34> */
/* @0x212f04 bx lr */
/* @0x212f08 mov r0, r3 */
/* @0x212f0c bx lr */

/* ── FUNC 0x212f10 · _BuildLineList(char*, int) · size=220 · insn=55 */
/* @0x212f10 push {r3, r4, r5, r6, r7, lr} */
/* @0x212f14 subs r7, r0, #0 */
/* @0x212f18 beq 0x212fe0 <_Z14_BuildLineListPci+0xd0> */
/* @0x212f1c ldrb r0, [r7] */
/* @0x212f20 cmp r0, #0 */
/* @0x212f24 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x212f28 cmp r1, #0 */
/* @0x212f2c ble 0x212fe0 <_Z14_BuildLineListPci+0xd0> */
/* @0x212f30 lsl r0, r1, #2 */
/* @0x212f34 ldr r1, [pc, #0xac] */
/* @0x212f38 mov r3, #1 */
/* @0x212f3c mov r2, #236 */
/* @0x212f40 add r1, pc, r1 */
/* @0x212f44 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x212f48 ldrb r3, [r7] */
/* @0x212f4c cmp r3, #0 */
/* @0x212f50 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x212f54 mov r4, #0 */
/* @0x212f58 add r2, r7, #1 */
/* @0x212f5c mov r5, r4 */
/* @0x212f60 mov r6, r4 */
/* @0x212f64 mov r12, r7 */
/* @0x212f68 mov r1, #1 */
/* @0x212f6c b 0x212f9c <_Z14_BuildLineListPci+0x8c> */
/* @0x212f70 cmp r3, #10 */
/* @0x212f74 beq 0x212fc8 <_Z14_BuildLineListPci+0xb8> */
/* @0x212f78 cmp r1, #0 */
/* @0x212f7c mov r4, r1 */
/* @0x212f80 strne r12, [r0, r5, lsl #2] */
/* @0x212f84 movne r1, #0 */
/* @0x212f88 movne r4, r1 */
/* @0x212f8c ldrb r3, [r12, #0x1]! */
/* @0x212f90 add r2, r2, #1 */
/* @0x212f94 cmp r3, #0 */
/* @0x212f98 beq 0x212fc4 <_Z14_BuildLineListPci+0xb4> */
/* @0x212f9c cmp r3, #13 */
/* @0x212fa0 bne 0x212f70 <_Z14_BuildLineListPci+0x60> */
/* @0x212fa4 strb r6, [r2, #-0x1] */
/* @0x212fa8 mov r1, #1 */
/* @0x212fac ldrb r3, [r12, #0x1]! */
/* @0x212fb0 add r5, r5, r1 */
/* @0x212fb4 mov r4, r1 */
/* @0x212fb8 add r2, r2, #1 */
/* @0x212fbc cmp r3, #0 */
/* @0x212fc0 bne 0x212f9c <_Z14_BuildLineListPci+0x8c> */
/* @0x212fc4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x212fc8 cmp r4, #0 */
/* @0x212fcc mov r1, #1 */
/* @0x212fd0 mov r4, #0 */
/* @0x212fd4 addeq r5, r5, r1 */
/* @0x212fd8 strb r6, [r2, #-0x1] */
/* @0x212fdc b 0x212f8c <_Z14_BuildLineListPci+0x7c> */
/* @0x212fe0 mov r0, #0 */
/* @0x212fe4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x212fe8 andseq r0, r4, r8, asr #20 */

/* ── FUNC 0x212fec · _GetNumEntriesInLine(char*) · size=184 · insn=46 */
/* @0x212fec push {r4, r5} */
/* @0x212ff0 mov r4, r0 */
/* @0x212ff4 ldrb r3, [r0] */
/* @0x212ff8 cmp r3, #0 */
/* @0x212ffc beq 0x21309c <_Z20_GetNumEntriesInLinePc+0xb0> */
/* @0x213000 mov r1, #0 */
/* @0x213004 mov r2, r0 */
/* @0x213008 mov r12, r1 */
/* @0x21300c mov r0, #1 */
/* @0x213010 b 0x213030 <_Z20_GetNumEntriesInLinePc+0x44> */
/* @0x213014 cmp r3, #34 */
/* @0x213018 beq 0x213060 <_Z20_GetNumEntriesInLinePc+0x74> */
/* @0x21301c ldrb r3, [r2, #0x1] */
/* @0x213020 mov r1, #0 */
/* @0x213024 cmp r3, #0 */
/* @0x213028 add r2, r2, #1 */
/* @0x21302c beq 0x213058 <_Z20_GetNumEntriesInLinePc+0x6c> */
/* @0x213030 cmp r3, #44 */
/* @0x213034 bne 0x213014 <_Z20_GetNumEntriesInLinePc+0x28> */
/* @0x213038 cmp r12, #0 */
/* @0x21303c bne 0x21301c <_Z20_GetNumEntriesInLinePc+0x30> */
/* @0x213040 ldrb r3, [r2, #0x1] */
/* @0x213044 add r0, r0, #1 */
/* @0x213048 mov r1, #1 */
/* @0x21304c add r2, r2, #1 */
/* @0x213050 cmp r3, #0 */
/* @0x213054 bne 0x213030 <_Z20_GetNumEntriesInLinePc+0x44> */
/* @0x213058 pop {r4, r5} */
/* @0x21305c bx lr */
/* @0x213060 cmp r12, #0 */
/* @0x213064 ldrb r3, [r2, #0x1] */
/* @0x213068 beq 0x213080 <_Z20_GetNumEntriesInLinePc+0x94> */
/* @0x21306c cmp r3, #44 */
/* @0x213070 cmpne r3, #0 */
/* @0x213074 moveq r1, #0 */
/* @0x213078 moveq r12, r1 */
/* @0x21307c beq 0x213024 <_Z20_GetNumEntriesInLinePc+0x38> */
/* @0x213080 cmp r2, r4 */
/* @0x213084 movne r5, r1 */
/* @0x213088 orreq r5, r1, #1 */
/* @0x21308c mov r1, #0 */
/* @0x213090 cmp r5, r1 */
/* @0x213094 movne r12, #1 */
/* @0x213098 b 0x213024 <_Z20_GetNumEntriesInLinePc+0x38> */
/* @0x21309c mov r0, #1 */
/* @0x2130a0 b 0x213058 <_Z20_GetNumEntriesInLinePc+0x6c> */

/* ── FUNC 0x2130a4 · AddStringToGrid(CDS_Grid*, int, int, char*) · size=700 · insn=175 */
/* @0x2130a4 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x2130a8 subs r5, r0, #0 */
/* @0x2130ac sub sp, sp, #28 */
/* @0x2130b0 mov r4, r1 */
/* @0x2130b4 beq 0x213228 <_Z15AddStringToGridP8CDS_GridiiPc+0x184> */
/* @0x2130b8 cmp r3, #0 */
/* @0x2130bc beq 0x213228 <_Z15AddStringToGridP8CDS_GridiiPc+0x184> */
/* @0x2130c0 cmp r1, #0 */
/* @0x2130c4 blt 0x213228 <_Z15AddStringToGridP8CDS_GridiiPc+0x184> */
/* @0x2130c8 cmp r2, #0 */
/* @0x2130cc blt 0x213228 <_Z15AddStringToGridP8CDS_GridiiPc+0x184> */
/* @0x2130d0 ldr r1, [r5, #0x4] */
/* @0x2130d4 cmp r4, r1 */
/* @0x2130d8 bge 0x213228 <_Z15AddStringToGridP8CDS_GridiiPc+0x184> */
/* @0x2130dc ldr r1, [r5, #0x8] */
/* @0x2130e0 cmp r2, r1 */
/* @0x2130e4 bge 0x213228 <_Z15AddStringToGridP8CDS_GridiiPc+0x184> */
/* @0x2130e8 add r7, sp, #8 */
/* @0x2130ec mov r1, r3 */
/* @0x2130f0 mov r12, #1 */
/* @0x2130f4 mov r3, #0 */
/* @0x2130f8 mov r0, r7 */
/* @0x2130fc str r3, [sp, #0x8] */
/* @0x213100 str r3, [sp, #0xc] */
/* @0x213104 str r3, [sp, #0x10] */
/* @0x213108 str r2, [sp, #0x4] */
/* @0x21310c str r12, [sp, #0x14] */
/* @0x213110 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x213114 ldm r5, {r8, r9} */
/* @0x213118 ldr r2, [sp, #0x4] */
/* @0x21311c mla r9, r9, r2, r4 */
/* @0x213120 add r6, r8, r9, lsl #4 */
/* @0x213124 ldr r3, [r6, #0xc] */
/* @0x213128 sub r3, r3, #1 */
/* @0x21312c bic r3, r3, #-16777216 */
/* @0x213130 bic r3, r3, #3 */
/* @0x213134 cmp r3, #0 */
/* @0x213138 beq 0x213264 <_Z15AddStringToGridP8CDS_GridiiPc+0x1c0> */
/* @0x21313c mov r3, #0 */
/* @0x213140 mov r1, #5 */
/* @0x213144 str r3, [r6, #0x8] */
/* @0x213148 str r1, [r6, #0xc] */
/* @0x21314c str r3, [r8, r9, lsl #4] */
/* @0x213150 ldr r3, [r5, #0x4] */
/* @0x213154 ldr r6, [r5] */
/* @0x213158 mla r4, r3, r2, r4 */
/* @0x21315c add r5, r6, r4, lsl #4 */
/* @0x213160 ldr r2, [r5, #0xc] */
/* @0x213164 bic r3, r2, #-16777216 */
/* @0x213168 cmp r3, #1 */
/* @0x21316c beq 0x213230 <_Z15AddStringToGridP8CDS_GridiiPc+0x18c> */
/* @0x213170 cmp r3, #2 */
/* @0x213174 bne 0x21319c <_Z15AddStringToGridP8CDS_GridiiPc+0xf8> */
/* @0x213178 sub r3, r2, #1 */
/* @0x21317c bic r3, r3, #-16777216 */
/* @0x213180 bic r3, r3, #3 */
/* @0x213184 cmp r3, #0 */
/* @0x213188 beq 0x213330 <_Z15AddStringToGridP8CDS_GridiiPc+0x28c> */
/* @0x21318c mov r2, #0 */
/* @0x213190 mov r3, #5 */
/* @0x213194 str r2, [r5, #0x8] */
/* @0x213198 str r3, [r5, #0xc] */
/* @0x21319c ldr r3, [sp, #0x14] */
/* @0x2131a0 mov r2, #0 */
/* @0x2131a4 str r2, [r6, r4, lsl #4] */
/* @0x2131a8 ldr r2, [sp, #0x10] */
/* @0x2131ac str r3, [r5, #0xc] */
/* @0x2131b0 ldr r3, [sp, #0x14] */
/* @0x2131b4 str r2, [r5, #0x8] */
/* @0x2131b8 bic r2, r3, #-16777216 */
/* @0x2131bc cmp r2, #14 */
/* @0x2131c0 addls pc, pc, r2, lsl #2 */
/* @0x2131c4 b 0x21320c <_Z15AddStringToGridP8CDS_GridiiPc+0x168> */
/* @0x2131c8 b 0x213274 <_Z15AddStringToGridP8CDS_GridiiPc+0x1d0> */
/* @0x2131cc b 0x2132dc <_Z15AddStringToGridP8CDS_GridiiPc+0x238> */
/* @0x2131d0 b 0x2132b0 <_Z15AddStringToGridP8CDS_GridiiPc+0x20c> */
/* @0x2131d4 b 0x213204 <_Z15AddStringToGridP8CDS_GridiiPc+0x160> */
/* @0x2131d8 b 0x21320c <_Z15AddStringToGridP8CDS_GridiiPc+0x168> */
/* @0x2131dc b 0x21320c <_Z15AddStringToGridP8CDS_GridiiPc+0x168> */
/* @0x2131e0 b 0x213288 <_Z15AddStringToGridP8CDS_GridiiPc+0x1e4> */
/* @0x2131e4 b 0x213204 <_Z15AddStringToGridP8CDS_GridiiPc+0x160> */
/* @0x2131e8 b 0x21320c <_Z15AddStringToGridP8CDS_GridiiPc+0x168> */
/* @0x2131ec b 0x21320c <_Z15AddStringToGridP8CDS_GridiiPc+0x168> */
/* @0x2131f0 b 0x213274 <_Z15AddStringToGridP8CDS_GridiiPc+0x1d0> */
/* @0x2131f4 b 0x21320c <_Z15AddStringToGridP8CDS_GridiiPc+0x168> */
/* @0x2131f8 b 0x21320c <_Z15AddStringToGridP8CDS_GridiiPc+0x168> */
/* @0x2131fc b 0x213274 <_Z15AddStringToGridP8CDS_GridiiPc+0x1d0> */
/* @0x213200 b 0x213204 <_Z15AddStringToGridP8CDS_GridiiPc+0x160> */
/* @0x213204 ldr r2, [sp, #0x8] */
/* @0x213208 str r2, [r6, r4, lsl #4] */
/* @0x21320c sub r3, r3, #1 */
/* @0x213210 bic r3, r3, #-16777216 */
/* @0x213214 bic r3, r3, #3 */
/* @0x213218 cmp r3, #0 */
/* @0x21321c bne 0x213228 <_Z15AddStringToGridP8CDS_GridiiPc+0x184> */
/* @0x213220 mov r0, r7 */
/* @0x213224 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x213228 add sp, sp, #28 */
/* @0x21322c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x213230 ldr r8, [r6, r4, lsl #4] */
/* @0x213234 cmp r8, #0 */
/* @0x213238 beq 0x213258 <_Z15AddStringToGridP8CDS_GridiiPc+0x1b4> */
/* @0x21323c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x213240 ldr r9, [r8, #0x4] */
/* @0x213244 sub r9, r9, #1 */
/* @0x213248 str r9, [r8, #0x4] */
/* @0x21324c cmp r9, #0 */
/* @0x213250 beq 0x2132f8 <_Z15AddStringToGridP8CDS_GridiiPc+0x254> */
/* @0x213254 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x213258 mov r3, #0 */
/* @0x21325c str r3, [r6, r4, lsl #4] */
/* @0x213260 b 0x21319c <_Z15AddStringToGridP8CDS_GridiiPc+0xf8> */
/* @0x213264 mov r0, r6 */
/* @0x213268 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x21326c ldr r2, [sp, #0x4] */
/* @0x213270 b 0x21313c <_Z15AddStringToGridP8CDS_GridiiPc+0x98> */
/* @0x213274 ldr r1, [sp, #0x8] */
/* @0x213278 ldr r2, [sp, #0xc] */
/* @0x21327c str r1, [r6, r4, lsl #4] */
/* @0x213280 str r2, [r5, #0x4] */
/* @0x213284 b 0x21320c <_Z15AddStringToGridP8CDS_GridiiPc+0x168> */
/* @0x213288 ldr r2, [sp, #0x8] */
/* @0x21328c str r2, [r6, r4, lsl #4] */
/* @0x213290 ldr r2, [sp, #0x8] */
/* @0x213294 cmp r2, #0 */
/* @0x213298 beq 0x21320c <_Z15AddStringToGridP8CDS_GridiiPc+0x168> */
/* @0x21329c bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x2132a0 ldr r1, [sp, #0x8] */
/* @0x2132a4 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x2132a8 ldr r3, [sp, #0x14] */
/* @0x2132ac b 0x21320c <_Z15AddStringToGridP8CDS_GridiiPc+0x168> */
/* @0x2132b0 ldr r2, [sp, #0x8] */
/* @0x2132b4 cmp r2, #0 */
/* @0x2132b8 str r2, [r6, r4, lsl #4] */
/* @0x2132bc beq 0x21320c <_Z15AddStringToGridP8CDS_GridiiPc+0x168> */
/* @0x2132c0 ldr r0, [r2, #0x8] */
/* @0x2132c4 ldr r1, [r2] */
/* @0x2132c8 cmp r0, #0 */
/* @0x2132cc streq r5, [r2, #0x8] */
/* @0x2132d0 add r1, r1, #1 */
/* @0x2132d4 str r1, [r2] */
/* @0x2132d8 b 0x21320c <_Z15AddStringToGridP8CDS_GridiiPc+0x168> */
/* @0x2132dc ldr r2, [sp, #0x8] */
/* @0x2132e0 cmp r2, #0 */
/* @0x2132e4 ldrne r3, [r2, #0x4] */
/* @0x2132e8 addne r3, r3, #1 */
/* @0x2132ec strne r3, [r2, #0x4] */
/* @0x2132f0 ldrne r3, [sp, #0x14] */
/* @0x2132f4 b 0x213208 <_Z15AddStringToGridP8CDS_GridiiPc+0x164> */
/* @0x2132f8 ldr r0, [r8] */
/* @0x2132fc bl 0xcef90 <_Z6YYFreePKv> */
/* @0x213300 str r9, [r8] */
/* @0x213304 str r9, [r8, #0x8] */
/* @0x213308 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x21330c ldr r9, [r8, #0x4] */
/* @0x213310 sub r9, r9, #1 */
/* @0x213314 str r9, [r8, #0x4] */
/* @0x213318 cmp r9, #0 */
/* @0x21331c beq 0x21333c <_Z15AddStringToGridP8CDS_GridiiPc+0x298> */
/* @0x213320 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x213324 mov r0, r8 */
/* @0x213328 bl 0x27d1d0 <_ZdlPv> */
/* @0x21332c b 0x213254 <_Z15AddStringToGridP8CDS_GridiiPc+0x1b0> */
/* @0x213330 mov r0, r5 */
/* @0x213334 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x213338 b 0x21318c <_Z15AddStringToGridP8CDS_GridiiPc+0xe8> */
/* @0x21333c ldr r0, [r8] */
/* @0x213340 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x213344 mov r0, r8 */
/* @0x213348 str r9, [r8] */
/* @0x21334c str r9, [r8, #0x8] */
/* @0x213350 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x213354 mov r0, r8 */
/* @0x213358 bl 0x27d1d0 <_ZdlPv> */
/* @0x21335c b 0x213320 <_Z15AddStringToGridP8CDS_GridiiPc+0x27c> */

/* ── FUNC 0x213360 · _PopulateDSGrid(char**, int, int, int) · size=456 · insn=114 */
/* @0x213360 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x213364 subs r9, r0, #0 */
/* @0x213368 sub sp, sp, #20 */
/* @0x21336c mov r4, r3 */
/* @0x213370 str r1, [sp] */
/* @0x213374 beq 0x21349c <_Z15_PopulateDSGridPPciii+0x13c> */
/* @0x213378 add r0, sp, #12 */
/* @0x21337c bl 0x10026c <_Z11GetTheGridsRi> */
/* @0x213380 cmp r4, #0 */
/* @0x213384 blt 0x21349c <_Z15_PopulateDSGridPPciii+0x13c> */
/* @0x213388 ldr r3, [sp, #0xc] */
/* @0x21338c cmp r4, r3 */
/* @0x213390 bge 0x21349c <_Z15_PopulateDSGridPPciii+0x13c> */
/* @0x213394 ldr r3, [sp] */
/* @0x213398 ldr r10, [r0, r4, lsl #2] */
/* @0x21339c cmp r3, #0 */
/* @0x2133a0 ble 0x213490 <_Z15_PopulateDSGridPPciii+0x130> */
/* @0x2133a4 ldr r3, [pc, #0x178] */
/* @0x2133a8 mov r8, #0 */
/* @0x2133ac add r3, pc, r3 */
/* @0x2133b0 str r3, [sp, #0x4] */
/* @0x2133b4 ldr r0, [r9] */
/* @0x2133b8 bl 0xb6538 <strlen@plt> */
/* @0x2133bc mov r3, #1 */
/* @0x2133c0 ldr r1, [sp, #0x4] */
/* @0x2133c4 movw r2, #0x172 */
/* @0x2133c8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x2133cc ldr r4, [r9], #4 */
/* @0x2133d0 ldrb r3, [r4] */
/* @0x2133d4 cmp r3, #0 */
/* @0x2133d8 mov r7, r0 */
/* @0x2133dc beq 0x213518 <_Z15_PopulateDSGridPPciii+0x1b8> */
/* @0x2133e0 mov r6, #0 */
/* @0x2133e4 mov r2, r0 */
/* @0x2133e8 mov r11, r6 */
/* @0x2133ec mov r1, r6 */
/* @0x2133f0 mov r5, r6 */
/* @0x2133f4 b 0x213418 <_Z15_PopulateDSGridPPciii+0xb8> */
/* @0x2133f8 cmp r3, #34 */
/* @0x2133fc beq 0x2134a8 <_Z15_PopulateDSGridPPciii+0x148> */
/* @0x213400 strb r3, [r2], #1 */
/* @0x213404 mov r1, #0 */
/* @0x213408 ldrb r3, [r4, #0x1] */
/* @0x21340c cmp r3, #0 */
/* @0x213410 add r4, r4, #1 */
/* @0x213414 beq 0x21345c <_Z15_PopulateDSGridPPciii+0xfc> */
/* @0x213418 cmp r3, #44 */
/* @0x21341c bne 0x2133f8 <_Z15_PopulateDSGridPPciii+0x98> */
/* @0x213420 cmp r5, #0 */
/* @0x213424 bne 0x213400 <_Z15_PopulateDSGridPPciii+0xa0> */
/* @0x213428 mov r1, r6 */
/* @0x21342c strb r5, [r2] */
/* @0x213430 mov r3, r7 */
/* @0x213434 mov r2, r8 */
/* @0x213438 mov r0, r10 */
/* @0x21343c add r6, r6, #1 */
/* @0x213440 bl 0x2130a4 <_Z15AddStringToGridP8CDS_GridiiPc> */
/* @0x213444 ldrb r3, [r4, #0x1] */
/* @0x213448 mov r2, r7 */
/* @0x21344c mov r1, #1 */
/* @0x213450 cmp r3, #0 */
/* @0x213454 add r4, r4, #1 */
/* @0x213458 bne 0x213418 <_Z15_PopulateDSGridPPciii+0xb8> */
/* @0x21345c mov r3, #0 */
/* @0x213460 mov r1, r6 */
/* @0x213464 strb r3, [r2] */
/* @0x213468 mov r0, r10 */
/* @0x21346c mov r2, r8 */
/* @0x213470 mov r3, r7 */
/* @0x213474 bl 0x2130a4 <_Z15AddStringToGridP8CDS_GridiiPc> */
/* @0x213478 mov r0, r7 */
/* @0x21347c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x213480 ldr r3, [sp] */
/* @0x213484 add r8, r8, #1 */
/* @0x213488 cmp r8, r3 */
/* @0x21348c bne 0x2133b4 <_Z15_PopulateDSGridPPciii+0x54> */
/* @0x213490 mov r0, #1 */
/* @0x213494 add sp, sp, #20 */
/* @0x213498 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x21349c mov r0, #0 */
/* @0x2134a0 add sp, sp, #20 */
/* @0x2134a4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2134a8 cmp r5, #0 */
/* @0x2134ac beq 0x2134c8 <_Z15_PopulateDSGridPPciii+0x168> */
/* @0x2134b0 ldrb r3, [r4, #0x1] */
/* @0x2134b4 cmp r3, #44 */
/* @0x2134b8 cmpne r3, #0 */
/* @0x2134bc moveq r1, #0 */
/* @0x2134c0 moveq r5, r1 */
/* @0x2134c4 beq 0x21340c <_Z15_PopulateDSGridPPciii+0xac> */
/* @0x2134c8 cmp r1, #0 */
/* @0x2134cc bne 0x2134fc <_Z15_PopulateDSGridPPciii+0x19c> */
/* @0x2134d0 ldr r3, [r9, #-0x4] */
/* @0x2134d4 cmp r3, r4 */
/* @0x2134d8 beq 0x21350c <_Z15_PopulateDSGridPPciii+0x1ac> */
/* @0x2134dc cmp r11, #0 */
/* @0x2134e0 movne r3, #34 */
/* @0x2134e4 ldrbeq r3, [r4, #0x1] */
/* @0x2134e8 strbne r3, [r2], #1 */
/* @0x2134ec moveq r11, #1 */
/* @0x2134f0 movne r11, r1 */
/* @0x2134f4 ldrbne r3, [r4, #0x1] */
/* @0x2134f8 b 0x21340c <_Z15_PopulateDSGridPPciii+0xac> */
/* @0x2134fc ldrb r3, [r4, #0x1] */
/* @0x213500 mov r1, #0 */
/* @0x213504 mov r5, #1 */
/* @0x213508 b 0x21340c <_Z15_PopulateDSGridPPciii+0xac> */
/* @0x21350c ldrb r3, [r4, #0x1] */
/* @0x213510 mov r5, #1 */
/* @0x213514 b 0x21340c <_Z15_PopulateDSGridPPciii+0xac> */
/* @0x213518 mov r6, r3 */
/* @0x21351c mov r2, r0 */
/* @0x213520 b 0x21345c <_Z15_PopulateDSGridPPciii+0xfc> */
/* @0x213524 ldrsbeq r0, [r4], -r12 */

/* ── FUNC 0x213528 · LoadCSV(char*) · size=260 · insn=65 */
/* @0x213528 push {r4, r5, r6, r7, r8, lr} */
/* @0x21352c sub sp, sp, #8 */
/* @0x213530 mov r3, #0 */
/* @0x213534 mov r4, r0 */
/* @0x213538 str r3, [sp] */
/* @0x21353c bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc> */
/* @0x213540 cmp r0, #0 */
/* @0x213544 mov r0, r4 */
/* @0x213548 beq 0x2135c4 <_Z7LoadCSVPc+0x9c> */
/* @0x21354c mov r1, sp */
/* @0x213550 bl 0x18fb08 <_ZN8LoadSave12ReadSaveFileEPKcPi> */
/* @0x213554 mov r4, r0 */
/* @0x213558 mov r0, r4 */
/* @0x21355c bl 0x212ea0 <_Z17_CountLinesInTextPc> */
/* @0x213560 mov r5, r0 */
/* @0x213564 mov r0, r4 */
/* @0x213568 mov r1, r5 */
/* @0x21356c bl 0x212f10 <_Z14_BuildLineListPci> */
/* @0x213570 subs r6, r0, #0 */
/* @0x213574 beq 0x213614 <_Z7LoadCSVPc+0xec> */
/* @0x213578 ldr r0, [r6] */
/* @0x21357c bl 0x212fec <_Z20_GetNumEntriesInLinePc> */
/* @0x213580 subs r8, r0, #0 */
/* @0x213584 ble 0x213614 <_Z7LoadCSVPc+0xec> */
/* @0x213588 mov r1, r5 */
/* @0x21358c bl 0x100294 <_Z20YYGML_ds_grid_createii> */
/* @0x213590 mov r1, r5 */
/* @0x213594 mov r2, r8 */
/* @0x213598 mov r7, r0 */
/* @0x21359c mov r0, r6 */
/* @0x2135a0 mov r3, r7 */
/* @0x2135a4 bl 0x213360 <_Z15_PopulateDSGridPPciii> */
/* @0x2135a8 cmp r0, #0 */
/* @0x2135ac beq 0x2135e4 <_Z7LoadCSVPc+0xbc> */
/* @0x2135b0 mov r0, r4 */
/* @0x2135b4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2135b8 mov r0, r7 */
/* @0x2135bc add sp, sp, #8 */
/* @0x2135c0 pop {r4, r5, r6, r7, r8, pc} */
/* @0x2135c4 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc> */
/* @0x2135c8 cmp r0, #0 */
/* @0x2135cc beq 0x213624 <_Z7LoadCSVPc+0xfc> */
/* @0x2135d0 mov r0, r4 */
/* @0x2135d4 mov r1, sp */
/* @0x2135d8 bl 0x18f848 <_ZN8LoadSave14ReadBundleFileEPKcPi> */
/* @0x2135dc mov r4, r0 */
/* @0x2135e0 b 0x213558 <_Z7LoadCSVPc+0x30> */
/* @0x2135e4 add r0, sp, #4 */
/* @0x2135e8 bl 0x10026c <_Z11GetTheGridsRi> */
/* @0x2135ec ldr r5, [r0, r7, lsl #2] */
/* @0x2135f0 mov r6, r0 */
/* @0x2135f4 cmp r5, #0 */
/* @0x2135f8 beq 0x21360c <_Z7LoadCSVPc+0xe4> */
/* @0x2135fc mov r0, r5 */
/* @0x213600 bl 0x20b260 <_ZN8CDS_GridD2Ev> */
/* @0x213604 mov r0, r5 */
/* @0x213608 bl 0x27d1d0 <_ZdlPv> */
/* @0x21360c mov r3, #0 */
/* @0x213610 str r3, [r6, r7, lsl #2] */
/* @0x213614 mov r0, r4 */
/* @0x213618 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21361c mvn r0, #0 */
/* @0x213620 b 0x2135bc <_Z7LoadCSVPc+0x94> */
/* @0x213624 mvn r0, #0 */
/* @0x213628 b 0x2135bc <_Z7LoadCSVPc+0x94> */

/* ── FUNC 0x21362c · anon_21362c · size=2728 · insn=683 */
/* @0x21362c ldr r3, [r1] */
/* @0x213630 movw r2, #0xa478 */
/* @0x213634 push {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x213638 sub sp, sp, #72 */
/* @0x21363c ldr r6, [r0, #0x4] */
/* @0x213640 movt r2, #0xd76a */
/* @0x213644 str r3, [sp, #0x14] */
/* @0x213648 movw r12, #0xb756 */
/* @0x21364c ldr r5, [r0, #0xc] */
/* @0x213650 movt r12, #0xe8c7 */
/* @0x213654 ldr r7, [r0, #0x8] */
/* @0x213658 ldr r8, [sp, #0x14] */
/* @0x21365c bic r4, r5, r6 */
/* @0x213660 ldr r9, [r0] */
/* @0x213664 and r3, r7, r6 */
/* @0x213668 add r2, r8, r2 */
/* @0x21366c orr r3, r4, r3 */
/* @0x213670 add r2, r2, r9 */
/* @0x213674 ldr r10, [r1, #0x4] */
/* @0x213678 add r3, r2, r3 */
/* @0x21367c ldr r11, [r1, #0x8] */
/* @0x213680 add r12, r10, r12 */
/* @0x213684 ldr r4, [r0, #0x8] */
/* @0x213688 add r3, r6, r3, ror #25 */
/* @0x21368c add r12, r12, r5 */
/* @0x213690 bic r7, r7, r3 */
/* @0x213694 and r2, r3, r6 */
/* @0x213698 orr r2, r7, r2 */
/* @0x21369c ldr r5, [r0, #0x4] */
/* @0x2136a0 add r12, r12, r2 */
/* @0x2136a4 ldr r2, [r1, #0xc] */
/* @0x2136a8 movw r6, #0x70db */
/* @0x2136ac movt r6, #0x2420 */
/* @0x2136b0 add r12, r3, r12, ror #20 */
/* @0x2136b4 add r6, r11, r6 */
/* @0x2136b8 str r2, [sp, #0x20] */
/* @0x2136bc add r6, r6, r4 */
/* @0x2136c0 and r2, r12, r3 */
/* @0x2136c4 bic r4, r5, r12 */
/* @0x2136c8 orr r4, r4, r2 */
/* @0x2136cc movw r7, #0xceee */
/* @0x2136d0 add r4, r6, r4 */
/* @0x2136d4 ldr r6, [sp, #0x20] */
/* @0x2136d8 movt r7, #0xc1bd */
/* @0x2136dc ldr r8, [r1, #0x10] */
/* @0x2136e0 add r4, r12, r4, ror #15 */
/* @0x2136e4 add r7, r6, r7 */
/* @0x2136e8 add r7, r7, r5 */
/* @0x2136ec and r2, r4, r12 */
/* @0x2136f0 bic r5, r3, r4 */
/* @0x2136f4 ldr r9, [r1, #0x14] */
/* @0x2136f8 orr r2, r5, r2 */
/* @0x2136fc movw r5, #0xfaf */
/* @0x213700 add r2, r7, r2 */
/* @0x213704 movt r5, #0xf57c */
/* @0x213708 add r5, r8, r5 */
/* @0x21370c movw r7, #0xc62a */
/* @0x213710 add r2, r4, r2, ror #10 */
/* @0x213714 add r3, r5, r3 */
/* @0x213718 bic r6, r12, r2 */
/* @0x21371c and r5, r2, r4 */
/* @0x213720 orr r5, r6, r5 */
/* @0x213724 movt r7, #0x4787 */
/* @0x213728 add r5, r3, r5 */
/* @0x21372c add r7, r9, r7 */
/* @0x213730 add r7, r7, r12 */
/* @0x213734 str r10, [sp, #0x18] */
/* @0x213738 add r5, r2, r5, ror #25 */
/* @0x21373c ldr r10, [r1, #0x18] */
/* @0x213740 and r3, r5, r2 */
/* @0x213744 bic r12, r4, r5 */
/* @0x213748 orr r12, r12, r3 */
/* @0x21374c movw r6, #0x4613 */
/* @0x213750 add r12, r7, r12 */
/* @0x213754 movt r6, #0xa830 */
/* @0x213758 add r6, r10, r6 */
/* @0x21375c str r11, [sp, #0x1c] */
/* @0x213760 add r12, r5, r12, ror #20 */
/* @0x213764 add r4, r6, r4 */
/* @0x213768 and r3, r12, r5 */
/* @0x21376c bic r6, r2, r12 */
/* @0x213770 orr r6, r6, r3 */
/* @0x213774 ldr r11, [r1, #0x1c] */
/* @0x213778 ldr r3, [r1, #0x20] */
/* @0x21377c add r6, r4, r6 */
/* @0x213780 movw r7, #0x9501 */
/* @0x213784 movt r7, #0xfd46 */
/* @0x213788 add r6, r12, r6, ror #15 */
/* @0x21378c add r7, r11, r7 */
/* @0x213790 str r3, [sp, #0x34] */
/* @0x213794 add r7, r7, r2 */
/* @0x213798 and r3, r6, r12 */
/* @0x21379c bic r2, r5, r6 */
/* @0x2137a0 orr r2, r2, r3 */
/* @0x2137a4 ldr r4, [sp, #0x34] */
/* @0x2137a8 add r2, r7, r2 */
/* @0x2137ac movw r3, #0x98d8 */
/* @0x2137b0 ldr r7, [r1, #0x24] */
/* @0x2137b4 movt r3, #0x6980 */
/* @0x2137b8 add r2, r6, r2, ror #10 */
/* @0x2137bc add r3, r4, r3 */
/* @0x2137c0 add r5, r3, r5 */
/* @0x2137c4 bic r4, r12, r2 */
/* @0x2137c8 and r3, r2, r6 */
/* @0x2137cc str r7, [sp, #0x38] */
/* @0x2137d0 orr r4, r4, r3 */
/* @0x2137d4 str r8, [sp, #0x24] */
/* @0x2137d8 add r5, r5, r4 */
/* @0x2137dc ldr r8, [sp, #0x38] */
/* @0x2137e0 movw r7, #0xf7af */
/* @0x2137e4 movt r7, #0x8b44 */
/* @0x2137e8 add r5, r2, r5, ror #25 */
/* @0x2137ec add r7, r8, r7 */
/* @0x2137f0 and r3, r5, r2 */
/* @0x2137f4 add r7, r7, r12 */
/* @0x2137f8 bic r12, r6, r5 */
/* @0x2137fc str r9, [sp, #0x28] */
/* @0x213800 orr r12, r12, r3 */
/* @0x213804 ldr r9, [r1, #0x28] */
/* @0x213808 add r12, r7, r12 */
/* @0x21380c str r10, [sp, #0x2c] */
/* @0x213810 sub r4, r9, #41984 */
/* @0x213814 ldr r10, [r1, #0x2c] */
/* @0x213818 add r12, r5, r12, ror #20 */
/* @0x21381c sub r4, r4, #79 */
/* @0x213820 add r4, r4, r6 */
/* @0x213824 and r3, r12, r5 */
/* @0x213828 bic r6, r2, r12 */
/* @0x21382c movw r7, #0xd7be */
/* @0x213830 orr r3, r6, r3 */
/* @0x213834 movt r7, #0x895c */
/* @0x213838 add r3, r4, r3 */
/* @0x21383c str r11, [sp, #0x30] */
/* @0x213840 str r9, [sp, #0x3c] */
/* @0x213844 add r7, r10, r7 */
/* @0x213848 str r10, [sp, #0x40] */
/* @0x21384c add r3, r12, r3, ror #15 */
/* @0x213850 ldr r4, [r1, #0x30] */
/* @0x213854 bic r6, r5, r3 */
/* @0x213858 add r7, r7, r2 */
/* @0x21385c movw r11, #0x1122 */
/* @0x213860 and r2, r3, r12 */
/* @0x213864 movt r11, #0x6b90 */
/* @0x213868 add r11, r4, r11 */
/* @0x21386c orr r2, r6, r2 */
/* @0x213870 add r5, r11, r5 */
/* @0x213874 add r2, r7, r2 */
/* @0x213878 ldr r11, [r1, #0x34] */
/* @0x21387c movw r7, #0x7193 */
/* @0x213880 add r2, r3, r2, ror #10 */
/* @0x213884 movt r7, #0xfd98 */
/* @0x213888 and r6, r2, r3 */
/* @0x21388c str r11, [sp, #0x44] */
/* @0x213890 bic r11, r12, r2 */
/* @0x213894 orr r11, r11, r6 */
/* @0x213898 movw r6, #0x438e */
/* @0x21389c add r11, r5, r11 */
/* @0x2138a0 ldr r5, [sp, #0x44] */
/* @0x2138a4 movt r6, #0xa679 */
/* @0x2138a8 add r11, r2, r11, ror #25 */
/* @0x2138ac add r7, r5, r7 */
/* @0x2138b0 bic r8, r3, r11 */
/* @0x2138b4 add r12, r7, r12 */
/* @0x2138b8 and r7, r11, r2 */
/* @0x2138bc ldr r5, [r1, #0x38] */
/* @0x2138c0 orr r7, r8, r7 */
/* @0x2138c4 add r7, r12, r7 */
/* @0x2138c8 add r6, r5, r6 */
/* @0x2138cc add r3, r6, r3 */
/* @0x2138d0 ldr r12, [r1, #0x3c] */
/* @0x2138d4 add r7, r11, r7, ror #20 */
/* @0x2138d8 movw r1, #0x821 */
/* @0x2138dc and r6, r7, r11 */
/* @0x2138e0 movt r1, #0x49b4 */
/* @0x2138e4 mvn r8, r7 */
/* @0x2138e8 and r9, r8, r2 */
/* @0x2138ec orr r6, r9, r6 */
/* @0x2138f0 ldr r9, [sp, #0x18] */
/* @0x2138f4 add r6, r3, r6 */
/* @0x2138f8 add r1, r12, r1 */
/* @0x2138fc movw r3, #0x2562 */
/* @0x213900 movt r3, #0xf61e */
/* @0x213904 add r6, r7, r6, ror #15 */
/* @0x213908 add r1, r1, r2 */
/* @0x21390c add r3, r9, r3 */
/* @0x213910 and r2, r6, r7 */
/* @0x213914 mvn r10, r6 */
/* @0x213918 and r9, r10, r11 */
/* @0x21391c orr r2, r9, r2 */
/* @0x213920 add r11, r3, r11 */
/* @0x213924 add r2, r1, r2 */
/* @0x213928 ldr r3, [sp, #0x2c] */
/* @0x21392c movw r9, #0xb340 */
/* @0x213930 movt r9, #0xc040 */
/* @0x213934 add r2, r6, r2, ror #10 */
/* @0x213938 and r8, r6, r8 */
/* @0x21393c add r9, r3, r9 */
/* @0x213940 and r3, r2, r7 */
/* @0x213944 orr r3, r3, r8 */
/* @0x213948 ldr r8, [sp, #0x40] */
/* @0x21394c add r3, r11, r3 */
/* @0x213950 movw r1, #0x5a51 */
/* @0x213954 movt r1, #0x265e */
/* @0x213958 and r10, r2, r10 */
/* @0x21395c add r3, r2, r3, ror #27 */
/* @0x213960 add r1, r8, r1 */
/* @0x213964 add r1, r1, r6 */
/* @0x213968 and r6, r3, r6 */
/* @0x21396c orr r6, r6, r10 */
/* @0x213970 add r7, r9, r7 */
/* @0x213974 ldr r10, [sp, #0x14] */
/* @0x213978 add r7, r7, r6 */
/* @0x21397c movw r11, #0xc7aa */
/* @0x213980 movt r11, #0xe9b6 */
/* @0x213984 add r8, r3, r7, ror #23 */
/* @0x213988 add r11, r10, r11 */
/* @0x21398c bic r9, r3, r2 */
/* @0x213990 add r11, r11, r2 */
/* @0x213994 and r2, r8, r2 */
/* @0x213998 movw r6, #0x105d */
/* @0x21399c orr r2, r2, r9 */
/* @0x2139a0 ldr r9, [sp, #0x28] */
/* @0x2139a4 add r1, r1, r2 */
/* @0x2139a8 movt r6, #0xd62f */
/* @0x2139ac add r6, r9, r6 */
/* @0x2139b0 bic r7, r8, r3 */
/* @0x2139b4 add r1, r8, r1, ror #18 */
/* @0x2139b8 add r9, r6, r3 */
/* @0x2139bc and r3, r1, r3 */
/* @0x2139c0 ldr r10, [sp, #0x3c] */
/* @0x2139c4 orr r7, r3, r7 */
/* @0x2139c8 movw r2, #0x1453 */
/* @0x2139cc add r7, r11, r7 */
/* @0x2139d0 movt r2, #0x244 */
/* @0x2139d4 add r2, r10, r2 */
/* @0x2139d8 bic r6, r1, r8 */
/* @0x2139dc add r7, r1, r7, ror #12 */
/* @0x2139e0 add r2, r2, r8 */
/* @0x2139e4 and r8, r7, r8 */
/* @0x2139e8 movw r3, #0xe681 */
/* @0x2139ec orr r6, r8, r6 */
/* @0x2139f0 movt r3, #0xd8a1 */
/* @0x2139f4 add r6, r9, r6 */
/* @0x2139f8 add r3, r12, r3 */
/* @0x2139fc bic r11, r7, r1 */
/* @0x213a00 add r3, r3, r1 */
/* @0x213a04 add r6, r7, r6, ror #27 */
/* @0x213a08 ldr r8, [sp, #0x24] */
/* @0x213a0c and r1, r6, r1 */
/* @0x213a10 movw r10, #0xfbc8 */
/* @0x213a14 orr r1, r1, r11 */
/* @0x213a18 movt r10, #0xe7d3 */
/* @0x213a1c add r2, r2, r1 */
/* @0x213a20 add r10, r8, r10 */
/* @0x213a24 bic r11, r6, r7 */
/* @0x213a28 add r10, r10, r7 */
/* @0x213a2c add r2, r6, r2, ror #23 */
/* @0x213a30 ldr r1, [sp, #0x38] */
/* @0x213a34 and r7, r2, r7 */
/* @0x213a38 movw r9, #0xcde6 */
/* @0x213a3c orr r7, r7, r11 */
/* @0x213a40 movt r9, #0x21e1 */
/* @0x213a44 add r3, r3, r7 */
/* @0x213a48 add r9, r1, r9 */
/* @0x213a4c add r9, r9, r6 */
/* @0x213a50 bic r11, r2, r6 */
/* @0x213a54 add r3, r2, r3, ror #18 */
/* @0x213a58 ldr r1, [sp, #0x20] */
/* @0x213a5c and r6, r3, r6 */
/* @0x213a60 movw r8, #0x7d6 */
/* @0x213a64 orr r11, r6, r11 */
/* @0x213a68 movt r8, #0xc337 */
/* @0x213a6c add r11, r10, r11 */
/* @0x213a70 add r8, r5, r8 */
/* @0x213a74 movw r7, #0xd87 */
/* @0x213a78 movt r7, #0xf4d5 */
/* @0x213a7c add r11, r3, r11, ror #12 */
/* @0x213a80 add r8, r8, r2 */
/* @0x213a84 add r7, r1, r7 */
/* @0x213a88 bic r1, r3, r2 */
/* @0x213a8c and r2, r11, r2 */
/* @0x213a90 add r7, r7, r3 */
/* @0x213a94 orr r2, r2, r1 */
/* @0x213a98 bic r1, r11, r3 */
/* @0x213a9c add r2, r9, r2 */
/* @0x213aa0 ldr r9, [sp, #0x44] */
/* @0x213aa4 movw r10, #0xe905 */
/* @0x213aa8 movt r10, #0xa9e3 */
/* @0x213aac add r2, r11, r2, ror #27 */
/* @0x213ab0 str r7, [sp, #0x10] */
/* @0x213ab4 and r3, r2, r3 */
/* @0x213ab8 ldr r7, [sp, #0x34] */
/* @0x213abc orr r3, r3, r1 */
/* @0x213ac0 add r10, r9, r10 */
/* @0x213ac4 add r3, r8, r3 */
/* @0x213ac8 add r10, r10, r2 */
/* @0x213acc movw r6, #0x14ed */
/* @0x213ad0 str r10, [sp, #0xc] */
/* @0x213ad4 movt r6, #0x455a */
/* @0x213ad8 ldr r10, [sp, #0x1c] */
/* @0x213adc add r3, r2, r3, ror #23 */
/* @0x213ae0 add r6, r7, r6 */
/* @0x213ae4 movw r9, #0xa3f8 */
/* @0x213ae8 movt r9, #0xfcef */
/* @0x213aec add r6, r6, r11 */
/* @0x213af0 bic r1, r2, r11 */
/* @0x213af4 add r9, r10, r9 */
/* @0x213af8 and r11, r3, r11 */
/* @0x213afc ldr r10, [sp, #0x10] */
/* @0x213b00 orr r1, r11, r1 */
/* @0x213b04 bic r11, r3, r2 */
/* @0x213b08 ldr r7, [sp, #0x30] */
/* @0x213b0c add r1, r10, r1 */
/* @0x213b10 movw r8, #0x2d9 */
/* @0x213b14 movt r8, #0x676f */
/* @0x213b18 add r9, r9, r3 */
/* @0x213b1c add r1, r3, r1, ror #18 */
/* @0x213b20 add r8, r7, r8 */
/* @0x213b24 and r2, r1, r2 */
/* @0x213b28 movw r7, #0x4c8a */
/* @0x213b2c orr r2, r2, r11 */
/* @0x213b30 movt r7, #0x8d2a */
/* @0x213b34 add r2, r6, r2 */
/* @0x213b38 add r7, r4, r7 */
/* @0x213b3c bic r11, r1, r3 */
/* @0x213b40 add r8, r8, r1 */
/* @0x213b44 add r2, r1, r2, ror #12 */
/* @0x213b48 ldr r10, [sp, #0x28] */
/* @0x213b4c add r7, r7, r2 */
/* @0x213b50 and r3, r2, r3 */
/* @0x213b54 str r7, [sp, #0x10] */
/* @0x213b58 orr r3, r3, r11 */
/* @0x213b5c ldr r7, [sp, #0xc] */
/* @0x213b60 bic r11, r2, r1 */
/* @0x213b64 movw r6, #0x3942 */
/* @0x213b68 movt r6, #0xfffa */
/* @0x213b6c add r3, r7, r3 */
/* @0x213b70 ldr r7, [sp, #0x34] */
/* @0x213b74 add r6, r10, r6 */
/* @0x213b78 movw r10, #0xf681 */
/* @0x213b7c add r3, r2, r3, ror #27 */
/* @0x213b80 movt r10, #0x8771 */
/* @0x213b84 and r1, r3, r1 */
/* @0x213b88 add r10, r7, r10 */
/* @0x213b8c orr r1, r1, r11 */
/* @0x213b90 bic r11, r3, r2 */
/* @0x213b94 add r9, r9, r1 */
/* @0x213b98 add r6, r6, r3 */
/* @0x213b9c str r6, [sp, #0xc] */
/* @0x213ba0 movw r1, #0x6122 */
/* @0x213ba4 add r9, r3, r9, ror #23 */
/* @0x213ba8 ldr r6, [sp, #0x40] */
/* @0x213bac and r2, r9, r2 */
/* @0x213bb0 add r10, r10, r9 */
/* @0x213bb4 orr r2, r2, r11 */
/* @0x213bb8 str r10, [sp, #0x8] */
/* @0x213bbc add r8, r8, r2 */
/* @0x213bc0 bic r11, r9, r3 */
/* @0x213bc4 ldr r10, [sp, #0x10] */
/* @0x213bc8 movt r1, #0x6d9d */
/* @0x213bcc add r8, r9, r8, ror #18 */
/* @0x213bd0 add r1, r6, r1 */
/* @0x213bd4 and r3, r8, r3 */
/* @0x213bd8 add r1, r1, r8 */
/* @0x213bdc orr r3, r3, r11 */
/* @0x213be0 str r1, [sp, #0x4] */
/* @0x213be4 add r7, r10, r3 */
/* @0x213be8 ldr r1, [sp, #0x18] */
/* @0x213bec ldr r10, [sp, #0xc] */
/* @0x213bf0 eor r9, r8, r9 */
/* @0x213bf4 add r7, r8, r7, ror #12 */
/* @0x213bf8 movw r3, #0xea44 */
/* @0x213bfc eor r9, r9, r7 */
/* @0x213c00 movt r3, #0xa4be */
/* @0x213c04 add r6, r10, r9 */
/* @0x213c08 add r3, r1, r3 */
/* @0x213c0c ldr r1, [sp, #0x24] */
/* @0x213c10 movw r11, #0xcfa9 */
/* @0x213c14 movt r11, #0x4bde */
/* @0x213c18 add r6, r7, r6, ror #28 */
/* @0x213c1c eor r8, r7, r8 */
/* @0x213c20 add r11, r1, r11 */
/* @0x213c24 ldr r1, [sp, #0x8] */
/* @0x213c28 eor r8, r8, r6 */
/* @0x213c2c movw r2, #0x380c */
/* @0x213c30 movt r2, #0xfde5 */
/* @0x213c34 add r2, r5, r2 */
/* @0x213c38 add r10, r1, r8 */
/* @0x213c3c add r3, r3, r6 */
/* @0x213c40 str r3, [sp, #0xc] */
/* @0x213c44 ldr r8, [sp, #0x30] */
/* @0x213c48 add r9, r2, r7 */
/* @0x213c4c movw r2, #0x4b60 */
/* @0x213c50 movt r2, #0xf6bb */
/* @0x213c54 add r10, r6, r10, ror #21 */
/* @0x213c58 eor r7, r6, r7 */
/* @0x213c5c add r2, r8, r2 */
/* @0x213c60 ldr r8, [sp, #0x4] */
/* @0x213c64 eor r7, r7, r10 */
/* @0x213c68 eor r6, r10, r6 */
/* @0x213c6c add r1, r8, r7 */
/* @0x213c70 ldr r7, [sp, #0x3c] */
/* @0x213c74 movw r3, #0xbc70 */
/* @0x213c78 movt r3, #0xbebf */
/* @0x213c7c add r1, r10, r1, ror #16 */
/* @0x213c80 add r11, r11, r10 */
/* @0x213c84 eor r6, r6, r1 */
/* @0x213c88 add r3, r7, r3 */
/* @0x213c8c add r6, r9, r6 */
/* @0x213c90 ldr r7, [sp, #0xc] */
/* @0x213c94 eor r10, r1, r10 */
/* @0x213c98 str r11, [sp, #0x10] */
/* @0x213c9c add r6, r1, r6, ror #9 */
/* @0x213ca0 add r2, r2, r1 */
/* @0x213ca4 eor r10, r10, r6 */
/* @0x213ca8 eor r1, r6, r1 */
/* @0x213cac add r10, r7, r10 */
/* @0x213cb0 ldr r7, [sp, #0x10] */
/* @0x213cb4 add r3, r3, r6 */
/* @0x213cb8 ldr r8, [sp, #0x44] */
/* @0x213cbc add r10, r6, r10, ror #28 */
/* @0x213cc0 str r3, [sp, #0xc] */
/* @0x213cc4 eor r1, r1, r10 */
/* @0x213cc8 eor r6, r10, r6 */
/* @0x213ccc add r1, r7, r1 */
/* @0x213cd0 ldr r3, [sp, #0x14] */
/* @0x213cd4 movw r11, #0x7ec6 */
/* @0x213cd8 movt r11, #0x289b */
/* @0x213cdc add r1, r10, r1, ror #21 */
/* @0x213ce0 add r11, r8, r11 */
/* @0x213ce4 eor r6, r6, r1 */
/* @0x213ce8 movw r9, #0x27fa */
/* @0x213cec add r2, r2, r6 */
/* @0x213cf0 ldr r6, [sp, #0x2c] */
/* @0x213cf4 movt r9, #0xeaa1 */
/* @0x213cf8 movw r7, #0x1d05 */
/* @0x213cfc movt r7, #0x488 */
/* @0x213d00 add r2, r1, r2, ror #16 */
/* @0x213d04 add r11, r11, r10 */
/* @0x213d08 add r7, r6, r7 */
/* @0x213d0c add r9, r3, r9 */
/* @0x213d10 ldr r6, [sp, #0xc] */
/* @0x213d14 ldr r3, [sp, #0x20] */
/* @0x213d18 eor r10, r1, r10 */
/* @0x213d1c eor r10, r10, r2 */
/* @0x213d20 movw r8, #0x3085 */
/* @0x213d24 movt r8, #0xd4ef */
/* @0x213d28 add r9, r9, r1 */
/* @0x213d2c add r8, r3, r8 */
/* @0x213d30 add r3, r6, r10 */
/* @0x213d34 eor r1, r2, r1 */
/* @0x213d38 ldr r6, [sp, #0x38] */
/* @0x213d3c add r3, r2, r3, ror #9 */
/* @0x213d40 str r9, [sp, #0x10] */
/* @0x213d44 eor r1, r1, r3 */
/* @0x213d48 movw r9, #0xd039 */
/* @0x213d4c add r1, r11, r1 */
/* @0x213d50 movt r9, #0xd9d4 */
/* @0x213d54 add r10, r8, r2 */
/* @0x213d58 add r9, r6, r9 */
/* @0x213d5c add r1, r3, r1, ror #28 */
/* @0x213d60 ldr r6, [sp, #0x10] */
/* @0x213d64 eor r2, r3, r2 */
/* @0x213d68 add r11, r7, r3 */
/* @0x213d6c eor r2, r2, r1 */
/* @0x213d70 eor r3, r1, r3 */
/* @0x213d74 add r2, r6, r2 */
/* @0x213d78 add r9, r9, r1 */
/* @0x213d7c movw r8, #0x99e5 */
/* @0x213d80 movt r8, #0xe6db */
/* @0x213d84 add r2, r1, r2, ror #21 */
/* @0x213d88 add r8, r4, r8 */
/* @0x213d8c eor r3, r3, r2 */
/* @0x213d90 eor r1, r2, r1 */
/* @0x213d94 add r3, r10, r3 */
/* @0x213d98 add r8, r8, r2 */
/* @0x213d9c str r8, [sp, #0x10] */
/* @0x213da0 movw r6, #0x5665 */
/* @0x213da4 add r3, r2, r3, ror #16 */
/* @0x213da8 ldr r8, [sp, #0x1c] */
/* @0x213dac eor r1, r1, r3 */
/* @0x213db0 movt r6, #0xc4ac */
/* @0x213db4 add r1, r11, r1 */
/* @0x213db8 add r6, r8, r6 */
/* @0x213dbc eor r2, r3, r2 */
/* @0x213dc0 ldr r8, [sp, #0x14] */
/* @0x213dc4 add r1, r3, r1, ror #9 */
/* @0x213dc8 movw r10, #0x2244 */
/* @0x213dcc eor r2, r2, r1 */
/* @0x213dd0 movt r10, #0xf429 */
/* @0x213dd4 add r10, r8, r10 */
/* @0x213dd8 add r2, r9, r2 */
/* @0x213ddc ldr r8, [sp, #0x30] */
/* @0x213de0 movw r7, #0x7cf8 */
/* @0x213de4 movt r7, #0x1fa2 */
/* @0x213de8 movw r11, #0xff97 */
/* @0x213dec add r7, r12, r7 */
/* @0x213df0 movt r11, #0x432a */
/* @0x213df4 add r2, r1, r2, ror #28 */
/* @0x213df8 add r7, r7, r3 */
/* @0x213dfc add r11, r8, r11 */
/* @0x213e00 eor r3, r1, r3 */
/* @0x213e04 ldr r8, [sp, #0x10] */
/* @0x213e08 eor r3, r3, r2 */
/* @0x213e0c add r9, r6, r1 */
/* @0x213e10 eor r1, r2, r1 */
/* @0x213e14 add r3, r8, r3 */
/* @0x213e18 movw r6, #0x23a7 */
/* @0x213e1c movt r6, #0xab94 */
/* @0x213e20 add r8, r10, r2 */
/* @0x213e24 add r3, r2, r3, ror #21 */
/* @0x213e28 add r6, r5, r6 */
/* @0x213e2c eor r1, r1, r3 */
/* @0x213e30 eor r2, r3, r2 */
/* @0x213e34 add r1, r7, r1 */
/* @0x213e38 mvn r5, r3 */
/* @0x213e3c add r11, r11, r3 */
/* @0x213e40 movw r10, #0xa039 */
/* @0x213e44 add r3, r3, r1, ror #16 */
/* @0x213e48 ldr r1, [sp, #0x28] */
/* @0x213e4c eor r2, r2, r3 */
/* @0x213e50 add r6, r6, r3 */
/* @0x213e54 add r9, r9, r2 */
/* @0x213e58 mvn r2, r3 */
/* @0x213e5c movt r10, #0xfc93 */
/* @0x213e60 movw r7, #0x59c3 */
/* @0x213e64 add r9, r3, r9, ror #9 */
/* @0x213e68 add r10, r1, r10 */
/* @0x213e6c orr r5, r9, r5 */
/* @0x213e70 movw r1, #0xcc92 */
/* @0x213e74 eor r3, r5, r3 */
/* @0x213e78 mvn r5, r9 */
/* @0x213e7c add r8, r8, r3 */
/* @0x213e80 ldr r3, [sp, #0x20] */
/* @0x213e84 movt r1, #0x8f0c */
/* @0x213e88 add r10, r10, r9 */
/* @0x213e8c add r8, r9, r8, ror #26 */
/* @0x213e90 add r1, r3, r1 */
/* @0x213e94 orr r2, r8, r2 */
/* @0x213e98 movt r7, #0x655b */
/* @0x213e9c eor r2, r2, r9 */
/* @0x213ea0 mvn r3, r8 */
/* @0x213ea4 add r11, r11, r2 */
/* @0x213ea8 add r7, r4, r7 */
/* @0x213eac add r7, r7, r8 */
/* @0x213eb0 ldr r9, [sp, #0x3c] */
/* @0x213eb4 add r11, r8, r11, ror #22 */
/* @0x213eb8 movw r4, #0xf47d */
/* @0x213ebc orr r5, r11, r5 */
/* @0x213ec0 add r1, r1, r11 */
/* @0x213ec4 eor r5, r5, r8 */
/* @0x213ec8 mvn r2, r11 */
/* @0x213ecc add r6, r6, r5 */
/* @0x213ed0 movt r4, #0xffef */
/* @0x213ed4 ldr r5, [sp, #0x18] */
/* @0x213ed8 add r4, r9, r4 */
/* @0x213edc add r6, r11, r6, ror #17 */
/* @0x213ee0 ldr r8, [sp, #0x34] */
/* @0x213ee4 orr r3, r6, r3 */
/* @0x213ee8 movw r9, #0x5dd1 */
/* @0x213eec eor r11, r3, r11 */
/* @0x213ef0 mvn r3, r6 */
/* @0x213ef4 add r10, r10, r11 */
/* @0x213ef8 movt r9, #0x8584 */
/* @0x213efc add r9, r5, r9 */
/* @0x213f00 movw r11, #0xe6e0 */
/* @0x213f04 add r10, r6, r10, ror #11 */
/* @0x213f08 movw r5, #0x7e4f */
/* @0x213f0c orr r2, r10, r2 */
/* @0x213f10 movt r5, #0x6fa8 */
/* @0x213f14 eor r2, r2, r6 */
/* @0x213f18 movt r11, #0xfe2c */
/* @0x213f1c add r7, r7, r2 */
/* @0x213f20 ldr r2, [sp, #0x2c] */
/* @0x213f24 add r5, r8, r5 */
/* @0x213f28 add r11, r12, r11 */
/* @0x213f2c add r7, r10, r7, ror #26 */
/* @0x213f30 mvn r12, r10 */
/* @0x213f34 orr r3, r7, r3 */
/* @0x213f38 movw r8, #0x4314 */
/* @0x213f3c eor r3, r3, r10 */
/* @0x213f40 movt r8, #0xa301 */
/* @0x213f44 add r1, r1, r3 */
/* @0x213f48 add r5, r5, r7 */
/* @0x213f4c add r4, r4, r6 */
/* @0x213f50 add r8, r2, r8 */
/* @0x213f54 add r1, r7, r1, ror #22 */
/* @0x213f58 mvn r2, r7 */
/* @0x213f5c orr r12, r1, r12 */
/* @0x213f60 add r9, r9, r10 */
/* @0x213f64 eor r7, r12, r7 */
/* @0x213f68 add r11, r11, r1 */
/* @0x213f6c add r4, r4, r7 */
/* @0x213f70 str r11, [sp, #0x18] */
/* @0x213f74 ldr r11, [sp, #0x40] */
/* @0x213f78 movw r7, #0xf235 */
/* @0x213f7c add r4, r1, r4, ror #17 */
/* @0x213f80 str r5, [sp, #0x14] */
/* @0x213f84 orr r2, r4, r2 */
/* @0x213f88 movt r7, #0xbd3a */
/* @0x213f8c eor r2, r2, r1 */
/* @0x213f90 ldr r5, [sp, #0x24] */
/* @0x213f94 add r9, r9, r2 */
/* @0x213f98 mvn r12, r1 */
/* @0x213f9c add r7, r11, r7 */
/* @0x213fa0 ldr r11, [sp, #0x14] */
/* @0x213fa4 add r9, r4, r9, ror #11 */
/* @0x213fa8 movw r10, #0x7e82 */
/* @0x213fac orr r12, r9, r12 */
/* @0x213fb0 movt r10, #0xf753 */
/* @0x213fb4 eor r12, r12, r4 */
/* @0x213fb8 add r10, r5, r10 */
/* @0x213fbc add r5, r11, r12 */
/* @0x213fc0 ldr r3, [sp, #0x44] */
/* @0x213fc4 movw r6, #0x11a1 */
/* @0x213fc8 movt r6, #0x4e08 */
/* @0x213fcc add r5, r9, r5, ror #26 */
/* @0x213fd0 add r6, r3, r6 */
/* @0x213fd4 mvn r1, r4 */
/* @0x213fd8 orr r1, r5, r1 */
/* @0x213fdc add r8, r8, r4 */
/* @0x213fe0 add r6, r6, r9 */
/* @0x213fe4 mvn r4, r9 */
/* @0x213fe8 eor r1, r1, r9 */
/* @0x213fec ldr r9, [sp, #0x18] */
/* @0x213ff0 movw r3, #0xd2bb */
/* @0x213ff4 ldr r2, [sp, #0x1c] */
/* @0x213ff8 movt r3, #0x2ad7 */
/* @0x213ffc add r1, r9, r1 */
/* @0x214000 ldr r12, [sp, #0x38] */
/* @0x214004 add r3, r2, r3 */
/* @0x214008 movw r2, #0xd391 */
/* @0x21400c add r1, r5, r1, ror #22 */
/* @0x214010 movt r2, #0xeb86 */
/* @0x214014 orr r4, r1, r4 */
/* @0x214018 add r2, r12, r2 */
/* @0x21401c add r10, r10, r5 */
/* @0x214020 mvn r12, r5 */
/* @0x214024 eor r5, r4, r5 */
/* @0x214028 mvn r9, r1 */
/* @0x21402c add r5, r8, r5 */
/* @0x214030 add r7, r7, r1 */
/* @0x214034 add r5, r1, r5, ror #17 */
/* @0x214038 orr r12, r5, r12 */
/* @0x21403c add r3, r3, r5 */
/* @0x214040 eor r12, r12, r1 */
/* @0x214044 mvn r4, r5 */
/* @0x214048 add r12, r6, r12 */
/* @0x21404c ldr r1, [r0] */
/* @0x214050 add r12, r5, r12, ror #11 */
/* @0x214054 orr r9, r12, r9 */
/* @0x214058 add r2, r2, r12 */
/* @0x21405c eor r9, r9, r5 */
/* @0x214060 mvn r11, r12 */
/* @0x214064 add r10, r10, r9 */
/* @0x214068 add r10, r12, r10, ror #26 */
/* @0x21406c orr r4, r10, r4 */
/* @0x214070 add r5, r10, r1 */
/* @0x214074 eor r12, r4, r12 */
/* @0x214078 mvn r8, r10 */
/* @0x21407c add r7, r7, r12 */
/* @0x214080 str r5, [r0] */
/* @0x214084 ldr r4, [r0, #0xc] */
/* @0x214088 add r7, r10, r7, ror #22 */
/* @0x21408c ldr r5, [r0, #0x4] */
/* @0x214090 orr r11, r7, r11 */
/* @0x214094 add r1, r7, r4 */
/* @0x214098 eor r10, r11, r10 */
/* @0x21409c ldr r6, [r0, #0x8] */
/* @0x2140a0 add r3, r3, r10 */
/* @0x2140a4 str r1, [r0, #0xc] */
/* @0x2140a8 add r3, r7, r3, ror #17 */
/* @0x2140ac orr r12, r3, r8 */
/* @0x2140b0 add r1, r3, r5 */
/* @0x2140b4 eor r7, r12, r7 */
/* @0x2140b8 add r3, r3, r6 */
/* @0x2140bc add r2, r2, r7 */
/* @0x2140c0 str r3, [r0, #0x8] */
/* @0x2140c4 add r2, r1, r2, ror #11 */
/* @0x2140c8 str r2, [r0, #0x4] */
/* @0x2140cc add sp, sp, #72 */
/* @0x2140d0 pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x2140d4 bx lr */

/* ── FUNC 0x2140d8 · MD5Init(MD5_CTX*) · size=64 · insn=16 */
/* @0x2140d8 movw r2, #0x2301 */
/* @0x2140dc movw r3, #0xab89 */
/* @0x2140e0 movt r2, #0x6745 */
/* @0x2140e4 movt r3, #0xefcd */
/* @0x2140e8 str r2, [r0, #0x8] */
/* @0x2140ec movw r2, #0xdcfe */
/* @0x2140f0 str r3, [r0, #0xc] */
/* @0x2140f4 movt r2, #0x98ba */
/* @0x2140f8 movw r3, #0x5476 */
/* @0x2140fc str r2, [r0, #0x10] */
/* @0x214100 movt r3, #0x1032 */
/* @0x214104 str r3, [r0, #0x14] */
/* @0x214108 mov r3, #0 */
/* @0x21410c str r3, [r0, #0x4] */
/* @0x214110 str r3, [r0] */
/* @0x214114 bx lr */

/* ── FUNC 0x214118 · MD5Update(MD5_CTX*, unsigned char*, unsigned int) · size=184 · insn=46 */
/* @0x214118 ldr r3, [r0] */
/* @0x21411c push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x214120 mov r8, r0 */
/* @0x214124 add r0, r3, r2, lsl #3 */
/* @0x214128 mov r7, r1 */
/* @0x21412c cmp r3, r0 */
/* @0x214130 ubfx r1, r3, #0x3, #0x6 */
/* @0x214134 ldr r3, [r8, #0x4] */
/* @0x214138 sub sp, sp, #68 */
/* @0x21413c add r9, r7, r2 */
/* @0x214140 add r4, sp, #60 */
/* @0x214144 addhi r3, r3, #1 */
/* @0x214148 add r6, r8, #8 */
/* @0x21414c add r3, r3, r2, lsr #29 */
/* @0x214150 stm r8, {r0, r3} */
/* @0x214154 b 0x21415c <_Z9MD5UpdateP7MD5_CTXPhj+0x44> */
/* @0x214158 mov r1, r3 */
/* @0x21415c cmp r7, r9 */
/* @0x214160 beq 0x2141c8 <_Z9MD5UpdateP7MD5_CTXPhj+0xb0> */
/* @0x214164 add r3, r1, #1 */
/* @0x214168 ldrb r2, [r7], #1 */
/* @0x21416c add r1, r8, r1 */
/* @0x214170 cmp r3, #64 */
/* @0x214174 strb r2, [r1, #0x18] */
/* @0x214178 bne 0x214158 <_Z9MD5UpdateP7MD5_CTXPhj+0x40> */
/* @0x21417c sub r2, sp, #4 */
/* @0x214180 mov r3, r8 */
/* @0x214184 ldrb r12, [r3, #0x1a] */
/* @0x214188 add r3, r3, #4 */
/* @0x21418c ldrb r0, [r3, #0x17] */
/* @0x214190 ldrb r1, [r3, #0x14] */
/* @0x214194 ldrb lr, [r3, #0x15] */
/* @0x214198 lsl r12, r12, #16 */
/* @0x21419c orr r12, r12, r0, lsl #24 */
/* @0x2141a0 orr r12, r12, r1 */
/* @0x2141a4 orr r12, r12, lr, lsl #8 */
/* @0x2141a8 str r12, [r2, #0x4]! */
/* @0x2141ac cmp r2, r4 */
/* @0x2141b0 bne 0x214184 <_Z9MD5UpdateP7MD5_CTXPhj+0x6c> */
/* @0x2141b4 mov r0, r6 */
/* @0x2141b8 mov r1, sp */
/* @0x2141bc bl 0x21362c <_Z7LoadCSVPc+0x104> */
/* @0x2141c0 mov r3, #0 */
/* @0x2141c4 b 0x214158 <_Z9MD5UpdateP7MD5_CTXPhj+0x40> */
/* @0x2141c8 add sp, sp, #68 */
/* @0x2141cc pop {r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x2141d0 · MD5Final(MD5_CTX*) · size=196 · insn=49 */
/* @0x2141d0 ldr r1, [r0, #0x4] */
/* @0x2141d4 push {r4, r5, lr} */
/* @0x2141d8 sub sp, sp, #68 */
/* @0x2141dc ldr r3, [r0] */
/* @0x2141e0 mov r5, r0 */
/* @0x2141e4 str r1, [sp, #0x3c] */
/* @0x2141e8 ubfx r2, r3, #0x3, #0x6 */
/* @0x2141ec ldr r1, [pc, #0x9c] */
/* @0x2141f0 cmp r2, #55 */
/* @0x2141f4 str r3, [sp, #0x38] */
/* @0x2141f8 rsble r2, r2, #56 */
/* @0x2141fc rsbgt r2, r2, #120 */
/* @0x214200 add r1, pc, r1 */
/* @0x214204 bl 0x214118 <_Z9MD5UpdateP7MD5_CTXPhj> */
/* @0x214208 sub r2, sp, #4 */
/* @0x21420c add r0, sp, #52 */
/* @0x214210 mov r3, r5 */
/* @0x214214 ldrb r1, [r3, #0x1a] */
/* @0x214218 add r3, r3, #4 */
/* @0x21421c ldrb r4, [r3, #0x17] */
/* @0x214220 ldrb lr, [r3, #0x14] */
/* @0x214224 ldrb r12, [r3, #0x15] */
/* @0x214228 lsl r1, r1, #16 */
/* @0x21422c orr r1, r1, r4, lsl #24 */
/* @0x214230 orr r1, r1, lr */
/* @0x214234 orr r1, r1, r12, lsl #8 */
/* @0x214238 str r1, [r2, #0x4]! */
/* @0x21423c cmp r2, r0 */
/* @0x214240 bne 0x214214 <_Z8MD5FinalP7MD5_CTX+0x44> */
/* @0x214244 add r0, r5, #8 */
/* @0x214248 mov r1, sp */
/* @0x21424c bl 0x21362c <_Z7LoadCSVPc+0x104> */
/* @0x214250 mov r0, r5 */
/* @0x214254 mov r2, #0 */
/* @0x214258 ldr r3, [r0, #0x8] */
/* @0x21425c add r2, r2, #4 */
/* @0x214260 cmp r2, #16 */
/* @0x214264 add r0, r0, #4 */
/* @0x214268 strb r3, [r0, #0x54] */
/* @0x21426c lsr r12, r3, #8 */
/* @0x214270 lsr r1, r3, #16 */
/* @0x214274 strb r12, [r0, #0x55] */
/* @0x214278 strb r1, [r0, #0x56] */
/* @0x21427c lsr r3, r3, #24 */
/* @0x214280 strb r3, [r0, #0x57] */
/* @0x214284 bne 0x214258 <_Z8MD5FinalP7MD5_CTX+0x88> */
/* @0x214288 add sp, sp, #68 */
/* @0x21428c pop {r4, r5, pc} */
/* @0x214290 andseq r1, lr, r0, ror r0 */

/* ── FUNC 0x214294 · SHA1Reset(SHA1Context*) · size=84 · insn=21 */
/* @0x214294 movw r2, #0x2301 */
/* @0x214298 movw r3, #0xab89 */
/* @0x21429c movt r2, #0x6745 */
/* @0x2142a0 movt r3, #0xefcd */
/* @0x2142a4 stm r0, {r2, r3} */
/* @0x2142a8 movw r2, #0xdcfe */
/* @0x2142ac movw r3, #0x5476 */
/* @0x2142b0 movt r2, #0x98ba */
/* @0x2142b4 movt r3, #0x1032 */
/* @0x2142b8 str r2, [r0, #0x8] */
/* @0x2142bc str r3, [r0, #0xc] */
/* @0x2142c0 movw r2, #0xe1f0 */
/* @0x2142c4 mov r3, #0 */
/* @0x2142c8 movt r2, #0xc3d2 */
/* @0x2142cc str r3, [r0, #0x14] */
/* @0x2142d0 str r2, [r0, #0x10] */
/* @0x2142d4 str r3, [r0, #0x18] */
/* @0x2142d8 str r3, [r0, #0x5c] */
/* @0x2142dc str r3, [r0, #0x60] */
/* @0x2142e0 str r3, [r0, #0x64] */
/* @0x2142e4 bx lr */

/* ── FUNC 0x2142e8 · SHA1ProcessMessageBlock(SHA1Context*) · size=592 · insn=148 */
/* @0x2142e8 push {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x2142ec sub sp, sp, #336 */
/* @0x2142f0 add r1, sp, #12 */
/* @0x2142f4 add r7, sp, #16 */
/* @0x2142f8 add r8, sp, #76 */
/* @0x2142fc mov r3, r0 */
/* @0x214300 mov r2, r1 */
/* @0x214304 ldrb r12, [r3, #0x1d] */
/* @0x214308 add r3, r3, #4 */
/* @0x21430c ldrb r6, [r3, #0x18] */
/* @0x214310 ldrb r5, [r3, #0x1b] */
/* @0x214314 ldrb r4, [r3, #0x1a] */
/* @0x214318 lsl r12, r12, #16 */
/* @0x21431c orr r12, r12, r6, lsl #24 */
/* @0x214320 orr r12, r12, r5 */
/* @0x214324 orr r12, r12, r4, lsl #8 */
/* @0x214328 str r12, [r2, #0x4]! */
/* @0x21432c cmp r2, r8 */
/* @0x214330 bne 0x214304 <_Z23SHA1ProcessMessageBlockP11SHA1Context+0x1c> */
/* @0x214334 mov r3, r7 */
/* @0x214338 mov r2, #0 */
/* @0x21433c ldr r4, [r3, #0x34] */
/* @0x214340 add r3, r3, #4 */
/* @0x214344 ldr r12, [r3, #0x1c] */
/* @0x214348 ldr r5, [r7, r2] */
/* @0x21434c add r2, r2, #4 */
/* @0x214350 eor r12, r4, r12 */
/* @0x214354 ldr r4, [r3, #0x4] */
/* @0x214358 eor r12, r12, r5 */
/* @0x21435c cmp r2, #256 */
/* @0x214360 eor r12, r12, r4 */
/* @0x214364 ror r12, r12, #31 */
/* @0x214368 str r12, [r3, #0x3c] */
/* @0x21436c bne 0x21433c <_Z23SHA1ProcessMessageBlockP11SHA1Context+0x54> */
/* @0x214370 ldr r3, [r0, #0x4] */
/* @0x214374 add r11, r7, #76 */
/* @0x214378 ldr r8, [r0] */
/* @0x21437c str r3, [sp] */
/* @0x214380 ldr r3, [r0, #0x8] */
/* @0x214384 mov r5, r8 */
/* @0x214388 str r3, [sp, #0x4] */
/* @0x21438c ldr r3, [r0, #0xc] */
/* @0x214390 str r3, [sp, #0x8] */
/* @0x214394 ldr r3, [r0, #0x10] */
/* @0x214398 ldm sp, {r2, r4, r6} */
/* @0x21439c str r3, [sp, #0xc] */
/* @0x2143a0 mov r9, r3 */
/* @0x2143a4 b 0x2143b4 <_Z23SHA1ProcessMessageBlockP11SHA1Context+0xcc> */
/* @0x2143a8 mov r6, r4 */
/* @0x2143ac mov r5, r12 */
/* @0x2143b0 mov r4, r10 */
/* @0x2143b4 ldr r10, [r1, #0x4]! */
/* @0x2143b8 movw r3, #0x7999 */
/* @0x2143bc movt r3, #0x5a82 */
/* @0x2143c0 bic r12, r6, r2 */
/* @0x2143c4 add r3, r10, r3 */
/* @0x2143c8 and r10, r4, r2 */
/* @0x2143cc orr r12, r12, r10 */
/* @0x2143d0 add r3, r3, r5, ror #27 */
/* @0x2143d4 cmp r1, r11 */
/* @0x2143d8 add r12, r3, r12 */
/* @0x2143dc ror r10, r2, #2 */
/* @0x2143e0 add r12, r12, r9 */
/* @0x2143e4 mov r2, r5 */
/* @0x2143e8 mov r9, r6 */
/* @0x2143ec bne 0x2143a8 <_Z23SHA1ProcessMessageBlockP11SHA1Context+0xc0> */
/* @0x2143f0 mov r3, r10 */
/* @0x2143f4 add r9, sp, #92 */
/* @0x2143f8 add r10, r7, #156 */
/* @0x2143fc b 0x21440c <_Z23SHA1ProcessMessageBlockP11SHA1Context+0x124> */
/* @0x214400 mov r4, r3 */
/* @0x214404 mov r12, r1 */
/* @0x214408 mov r3, r2 */
/* @0x21440c ldr r11, [r9, #0x4]! */
/* @0x214410 movw r2, #0xeba1 */
/* @0x214414 movt r2, #0x6ed9 */
/* @0x214418 eor r1, r3, r5 */
/* @0x21441c add r2, r11, r2 */
/* @0x214420 eor r1, r1, r4 */
/* @0x214424 add r2, r2, r12, ror #27 */
/* @0x214428 cmp r9, r10 */
/* @0x21442c add r1, r2, r1 */
/* @0x214430 ror r2, r5, #2 */
/* @0x214434 add r1, r1, r6 */
/* @0x214438 mov r5, r12 */
/* @0x21443c mov r6, r4 */
/* @0x214440 bne 0x214400 <_Z23SHA1ProcessMessageBlockP11SHA1Context+0x118> */
/* @0x214444 add r6, sp, #172 */
/* @0x214448 add r11, r7, #236 */
/* @0x21444c b 0x21445c <_Z23SHA1ProcessMessageBlockP11SHA1Context+0x174> */
/* @0x214450 mov r3, r2 */
/* @0x214454 mov r1, r5 */
/* @0x214458 mov r2, r9 */
/* @0x21445c ldr r10, [r6, #0x4]! */
/* @0x214460 movw r5, #0xbcdc */
/* @0x214464 orr r9, r3, r2 */
/* @0x214468 movt r5, #0x8f1b */
/* @0x21446c add r5, r10, r5 */
/* @0x214470 and r9, r9, r12 */
/* @0x214474 and r10, r3, r2 */
/* @0x214478 add r5, r5, r1, ror #27 */
/* @0x21447c orr r9, r9, r10 */
/* @0x214480 cmp r6, r11 */
/* @0x214484 add r5, r5, r9 */
/* @0x214488 ror r9, r12, #2 */
/* @0x21448c add r5, r5, r4 */
/* @0x214490 mov r12, r1 */
/* @0x214494 mov r4, r3 */
/* @0x214498 bne 0x214450 <_Z23SHA1ProcessMessageBlockP11SHA1Context+0x168> */
/* @0x21449c add r7, r7, #316 */
/* @0x2144a0 add r4, sp, #252 */
/* @0x2144a4 b 0x2144b4 <_Z23SHA1ProcessMessageBlockP11SHA1Context+0x1cc> */
/* @0x2144a8 mov r2, r9 */
/* @0x2144ac mov r5, r12 */
/* @0x2144b0 mov r9, r10 */
/* @0x2144b4 ldr r10, [r4, #0x4]! */
/* @0x2144b8 movw r12, #0xc1d6 */
/* @0x2144bc movt r12, #0xca62 */
/* @0x2144c0 eor r6, r9, r1 */
/* @0x2144c4 add r12, r10, r12 */
/* @0x2144c8 eor r6, r6, r2 */
/* @0x2144cc add r12, r12, r5, ror #27 */
/* @0x2144d0 cmp r4, r7 */
/* @0x2144d4 add r12, r12, r6 */
/* @0x2144d8 ror r10, r1, #2 */
/* @0x2144dc add r12, r12, r3 */
/* @0x2144e0 mov r1, r5 */
/* @0x2144e4 mov r3, r2 */
/* @0x2144e8 bne 0x2144a8 <_Z23SHA1ProcessMessageBlockP11SHA1Context+0x1c0> */
/* @0x2144ec ldr r3, [sp] */
/* @0x2144f0 add r12, r12, r8 */
/* @0x2144f4 str r12, [r0] */
/* @0x2144f8 add r5, r5, r3 */
/* @0x2144fc ldr r3, [sp, #0x4] */
/* @0x214500 str r5, [r0, #0x4] */
/* @0x214504 add r10, r10, r3 */
/* @0x214508 ldr r3, [sp, #0x8] */
/* @0x21450c str r10, [r0, #0x8] */
/* @0x214510 add r9, r9, r3 */
/* @0x214514 ldr r3, [sp, #0xc] */
/* @0x214518 str r9, [r0, #0xc] */
/* @0x21451c add r2, r2, r3 */
/* @0x214520 mov r3, #0 */
/* @0x214524 str r2, [r0, #0x10] */
/* @0x214528 str r3, [r0, #0x5c] */
/* @0x21452c add sp, sp, #336 */
/* @0x214530 pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x214534 bx lr */

/* ── FUNC 0x214538 · SHA1Input(SHA1Context*, unsigned char const*, unsigned int) · size=176 · insn=44 */
/* @0x214538 cmp r2, #0 */
/* @0x21453c push {r3, r4, r5, r6, r7, lr} */
/* @0x214540 mov r4, r0 */
/* @0x214544 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x214548 ldr r3, [r0, #0x60] */
/* @0x21454c cmp r3, #0 */
/* @0x214550 bne 0x2145dc <_Z9SHA1InputP11SHA1ContextPKhj+0xa4> */
/* @0x214554 ldr r3, [r0, #0x64] */
/* @0x214558 cmp r3, #0 */
/* @0x21455c bne 0x2145dc <_Z9SHA1InputP11SHA1ContextPKhj+0xa4> */
/* @0x214560 add r6, r1, r2 */
/* @0x214564 add r5, r1, #1 */
/* @0x214568 mov r7, #1 */
/* @0x21456c b 0x214590 <_Z9SHA1InputP11SHA1ContextPKhj+0x58> */
/* @0x214570 mov r0, r4 */
/* @0x214574 bl 0x2142e8 <_Z23SHA1ProcessMessageBlockP11SHA1Context> */
/* @0x214578 cmp r5, r6 */
/* @0x21457c add r5, r5, #1 */
/* @0x214580 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x214584 ldr r3, [r4, #0x64] */
/* @0x214588 cmp r3, #0 */
/* @0x21458c popne {r3, r4, r5, r6, r7, pc} */
/* @0x214590 ldr r1, [r4, #0x5c] */
/* @0x214594 ldr r2, [r4, #0x14] */
/* @0x214598 add r3, r1, #1 */
/* @0x21459c str r3, [r4, #0x5c] */
/* @0x2145a0 add r2, r2, #8 */
/* @0x2145a4 ldrb r0, [r5, #-0x1] */
/* @0x2145a8 add r1, r4, r1 */
/* @0x2145ac cmp r2, #0 */
/* @0x2145b0 strb r0, [r1, #0x1c] */
/* @0x2145b4 str r2, [r4, #0x14] */
/* @0x2145b8 bne 0x2145d0 <_Z9SHA1InputP11SHA1ContextPKhj+0x98> */
/* @0x2145bc ldr r2, [r4, #0x18] */
/* @0x2145c0 add r2, r2, #1 */
/* @0x2145c4 str r2, [r4, #0x18] */
/* @0x2145c8 cmp r2, #0 */
/* @0x2145cc streq r7, [r4, #0x64] */
/* @0x2145d0 cmp r3, #64 */
/* @0x2145d4 bne 0x214578 <_Z9SHA1InputP11SHA1ContextPKhj+0x40> */
/* @0x2145d8 b 0x214570 <_Z9SHA1InputP11SHA1ContextPKhj+0x38> */
/* @0x2145dc mov r3, #1 */
/* @0x2145e0 str r3, [r4, #0x64] */
/* @0x2145e4 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x2145e8 · SHA1PadMessage(SHA1Context*) · size=252 · insn=63 */
/* @0x2145e8 ldr r2, [r0, #0x5c] */
/* @0x2145ec push {r4, lr} */
/* @0x2145f0 cmp r2, #55 */
/* @0x2145f4 mov r4, r0 */
/* @0x2145f8 add r3, r2, #1 */
/* @0x2145fc ble 0x2146b0 <_Z14SHA1PadMessageP11SHA1Context+0xc8> */
/* @0x214600 add r2, r0, r2 */
/* @0x214604 cmp r3, #63 */
/* @0x214608 mvn r1, #127 */
/* @0x21460c str r3, [r0, #0x5c] */
/* @0x214610 strb r1, [r2, #0x1c] */
/* @0x214614 movle r1, #0 */
/* @0x214618 bgt 0x214634 <_Z14SHA1PadMessageP11SHA1Context+0x4c> */
/* @0x21461c add r2, r4, r3 */
/* @0x214620 add r3, r3, #1 */
/* @0x214624 cmp r3, #64 */
/* @0x214628 strb r1, [r2, #0x1c] */
/* @0x21462c bne 0x21461c <_Z14SHA1PadMessageP11SHA1Context+0x34> */
/* @0x214630 str r3, [r4, #0x5c] */
/* @0x214634 mov r0, r4 */
/* @0x214638 bl 0x2142e8 <_Z23SHA1ProcessMessageBlockP11SHA1Context> */
/* @0x21463c ldr r3, [r4, #0x5c] */
/* @0x214640 cmp r3, #55 */
/* @0x214644 movle r1, #0 */
/* @0x214648 bgt 0x214664 <_Z14SHA1PadMessageP11SHA1Context+0x7c> */
/* @0x21464c add r2, r4, r3 */
/* @0x214650 add r3, r3, #1 */
/* @0x214654 cmp r3, #56 */
/* @0x214658 strb r1, [r2, #0x1c] */
/* @0x21465c bne 0x21464c <_Z14SHA1PadMessageP11SHA1Context+0x64> */
/* @0x214660 str r3, [r4, #0x5c] */
/* @0x214664 ldr r2, [r4, #0x18] */
/* @0x214668 mov r0, r4 */
/* @0x21466c ldr r3, [r4, #0x14] */
/* @0x214670 lsr r1, r2, #16 */
/* @0x214674 strb r2, [r4, #0x57] */
/* @0x214678 lsr r12, r2, #24 */
/* @0x21467c strb r1, [r4, #0x55] */
/* @0x214680 lsr r2, r2, #8 */
/* @0x214684 strb r3, [r4, #0x5b] */
/* @0x214688 lsr r1, r3, #24 */
/* @0x21468c strb r2, [r4, #0x56] */
/* @0x214690 strb r12, [r4, #0x54] */
/* @0x214694 lsr r2, r3, #16 */
/* @0x214698 strb r1, [r4, #0x58] */
/* @0x21469c lsr r3, r3, #8 */
/* @0x2146a0 strb r2, [r4, #0x59] */
/* @0x2146a4 strb r3, [r4, #0x5a] */
/* @0x2146a8 pop {r4, lr} */
/* @0x2146ac b 0x2142e8 <_Z23SHA1ProcessMessageBlockP11SHA1Context> */
/* @0x2146b0 add r1, r0, r2 */
/* @0x2146b4 cmp r3, #56 */
/* @0x2146b8 str r3, [r0, #0x5c] */
/* @0x2146bc mvn r0, #127 */
/* @0x2146c0 strb r0, [r1, #0x1c] */
/* @0x2146c4 beq 0x214664 <_Z14SHA1PadMessageP11SHA1Context+0x7c> */
/* @0x2146c8 add r2, r1, #28 */
/* @0x2146cc mov r1, #0 */
/* @0x2146d0 add r3, r3, #1 */
/* @0x2146d4 strb r1, [r2, #0x1]! */
/* @0x2146d8 cmp r3, #56 */
/* @0x2146dc bne 0x2146d0 <_Z14SHA1PadMessageP11SHA1Context+0xe8> */
/* @0x2146e0 b 0x214660 <_Z14SHA1PadMessageP11SHA1Context+0x78> */

/* ── FUNC 0x2146e4 · SHA1Result(SHA1Context*) · size=68 · insn=17 */
/* @0x2146e4 ldr r3, [r0, #0x64] */
/* @0x2146e8 push {r4, lr} */
/* @0x2146ec cmp r3, #0 */
/* @0x2146f0 mov r4, r0 */
/* @0x2146f4 bne 0x214720 <_Z10SHA1ResultP11SHA1Context+0x3c> */
/* @0x2146f8 ldr r3, [r0, #0x60] */
/* @0x2146fc cmp r3, #0 */
/* @0x214700 beq 0x21470c <_Z10SHA1ResultP11SHA1Context+0x28> */
/* @0x214704 mov r0, #1 */
/* @0x214708 pop {r4, pc} */
/* @0x21470c bl 0x2145e8 <_Z14SHA1PadMessageP11SHA1Context> */
/* @0x214710 mov r3, #1 */
/* @0x214714 mov r0, r3 */
/* @0x214718 str r3, [r4, #0x60] */
/* @0x21471c pop {r4, pc} */
/* @0x214720 mov r0, #0 */
/* @0x214724 pop {r4, pc} */

/* ── FUNC 0x214728 · CTimingSource::Reset() · size=72 · insn=18 */
/* @0x214728 vldr d7, [r0, #24] */
/* @0x21472c vcmpe.f64 d7, #0 */
/* @0x214730 push {r4, lr} */
/* @0x214734 mov r2, #0 */
/* @0x214738 mov r3, #0 */
/* @0x21473c mov r4, r0 */
/* @0x214740 vmrs APSR_nzcv, fpscr */
/* @0x214744 strd r2, r3, [r0] */
/* @0x214748 strdle r2, r3, [r0, #8] */
/* @0x21474c ble 0x214758 <_ZN13CTimingSource5ResetEv+0x30> */
/* @0x214750 bl 0x215148 <Timing_Time> */
/* @0x214754 strd r0, r1, [r4, #8] */
/* @0x214758 mov r2, #0 */
/* @0x21475c mov r3, #0 */
/* @0x214760 mov r1, #0 */
/* @0x214764 strd r2, r3, [r4, #32] */
/* @0x214768 strb r1, [r4, #0x10] */
/* @0x21476c pop {r4, pc} */

/* ── FUNC 0x214770 · CTimingSource::Update() · size=144 · insn=36 */
/* @0x214770 vldr d7, [r0, #24] */
/* @0x214774 vcmpe.f64 d7, #0 */
/* @0x214778 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x21477c mov r10, r0 */
/* @0x214780 vmrs APSR_nzcv, fpscr */
/* @0x214784 ble 0x2147e4 <_ZN13CTimingSource6UpdateEv+0x74> */
/* @0x214788 vmov.f64 d5, #1.000000e+00 */
/* @0x21478c vldr d6, [pc, #100] */
/* @0x214790 ldrd r8, r9, [r0, #8] */
/* @0x214794 mov r6, r8 */
/* @0x214798 mov r7, r9 */
/* @0x21479c vdiv.f64 d7, d5, d7 */
/* @0x2147a0 vmul.f64 d5, d7, d6 */
/* @0x2147a4 vmov r0, r1, d5 */
/* @0x2147a8 bl 0x3194a0 <__fixdfdi> */
/* @0x2147ac adds r2, r8, r0 */
/* @0x2147b0 adc r3, r9, r1 */
/* @0x2147b4 ldrb r1, [r10, #0x10] */
/* @0x2147b8 subs r6, r2, r6 */
/* @0x2147bc sbc r7, r3, r7 */
/* @0x2147c0 strd r6, r7, [r10, #32] */
/* @0x2147c4 cmp r1, #0 */
/* @0x2147c8 bne 0x2147dc <_ZN13CTimingSource6UpdateEv+0x6c> */
/* @0x2147cc ldrd r4, r5, [r10] */
/* @0x2147d0 adds r4, r4, r6 */
/* @0x2147d4 adc r5, r5, r7 */
/* @0x2147d8 strd r4, r5, [r10] */
/* @0x2147dc strd r2, r3, [r10, #8] */
/* @0x2147e0 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2147e4 bl 0x215148 <Timing_Time> */
/* @0x2147e8 ldrd r6, r7, [r10, #8] */
/* @0x2147ec mov r2, r0 */
/* @0x2147f0 mov r3, r1 */
/* @0x2147f4 b 0x2147b4 <_ZN13CTimingSource6UpdateEv+0x44> */
/* @0x2147f8 andeq r0, r0, r0 */
/* @0x2147fc smlawbmi lr, r0, r4, r8 */

/* ── FUNC 0x214800 · CTimingSource::SetFrameRate(double) · size=8 · insn=2 */
/* @0x214800 strd r2, r3, [r0, #24] */
/* @0x214804 b 0x214728 <_ZN13CTimingSource5ResetEv> */

/* ── FUNC 0x214808 · CTimingSource::GetFPS() · size=80 · insn=20 */
/* @0x214808 vldr d7, [r0, #24] */
/* @0x21480c vcmpe.f64 d7, #0 */
/* @0x214810 push {r3, lr} */
/* @0x214814 vmrs APSR_nzcv, fpscr */
/* @0x214818 ble 0x214824 <_ZN13CTimingSource6GetFPSEv+0x1c> */
/* @0x21481c vmov r0, r1, d7 */
/* @0x214820 pop {r3, pc} */
/* @0x214824 ldrd r0, r1, [r0, #32] */
/* @0x214828 cmp r0, #1 */
/* @0x21482c sbcs r3, r1, #0 */
/* @0x214830 vmovlt.f64 d7, #3.000000e+01 */
/* @0x214834 blt 0x21481c <_ZN13CTimingSource6GetFPSEv+0x14> */
/* @0x214838 bl 0x319164 <__floatdidf> */
/* @0x21483c vldr d7, [pc, #12] */
/* @0x214840 vmov d6, r0, r1 */
/* @0x214844 vdiv.f64 d7, d7, d6 */
/* @0x214848 vmov r0, r1, d7 */
/* @0x21484c pop {r3, pc} */
/* @0x214850 andeq r0, r0, r0 */
/* @0x214854 smlawbmi lr, r0, r4, r8 */

/* ── FUNC 0x214858 · CD_Init() · size=4 · insn=1 */
/* @0x214858 bx lr */
