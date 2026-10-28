/* libyoyo.so 覆盖卡组 0181
 * 函数 0x2010ec..0x201b58，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2010ec · CStream::CStream(int) · size=92 · insn=23 */
/* @0x2010ec cmp r1, #0 */
/* @0x2010f0 mov r2, #0 */
/* @0x2010f4 push {r4, lr} */
/* @0x2010f8 mov r4, r0 */
/* @0x2010fc mov r3, #0 */
/* @0x201100 mov r0, #0 */
/* @0x201104 sub sp, sp, #8 */
/* @0x201108 strd r2, r3, [r4, #16] */
/* @0x20110c strb r0, [r4] */
/* @0x201110 str r0, [r4, #0x18] */
/* @0x201114 str r0, [r4, #0xc] */
/* @0x201118 str r1, [r4, #0x8] */
/* @0x20111c beq 0x201138 <_ZN7CStreamC2Ei+0x4c> */
/* @0x201120 ldr r2, [pc, #0x1c] */
/* @0x201124 mov r3, #76 */
/* @0x201128 str r0, [sp] */
/* @0x20112c add r2, pc, r2 */
/* @0x201130 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x201134 str r0, [r4, #0x18] */
/* @0x201138 mov r0, r4 */
/* @0x20113c add sp, sp, #8 */
/* @0x201140 pop {r4, pc} */
/* @0x201144 ldrsheq r2, [r5], -r12 */

/* ── FUNC 0x2010ec · CStream::CStream(int) · alias of the symbol above · insn=0 */

/* ── FUNC 0x201148 · CStream::SetPosition(int) · size=16 · insn=4 */
/* @0x201148 mov r3, #0 */
/* @0x20114c str r1, [r0, #0x10] */
/* @0x201150 str r3, [r0, #0x14] */
/* @0x201154 bx lr */

/* ── FUNC 0x201158 · CStream::GetMemory() · size=8 · insn=2 */
/* @0x201158 ldr r0, [r0, #0x18] */
/* @0x20115c bx lr */

/* ── FUNC 0x201160 · CStream::GetPosition() · size=8 · insn=2 */
/* @0x201160 ldr r0, [r0, #0x10] */
/* @0x201164 bx lr */

/* ── FUNC 0x201168 · CStream::GetSize() · size=8 · insn=2 */
/* @0x201168 ldr r0, [r0, #0x8] */
/* @0x20116c bx lr */

/* ── FUNC 0x201170 · CStream::LoadFromMemory(void*, long long) · size=36 · insn=9 */
/* @0x201170 push {r4, r5} */
/* @0x201174 mov r3, #0 */
/* @0x201178 mov r4, #0 */
/* @0x20117c mov r5, #0 */
/* @0x201180 str r1, [r0, #0x18] */
/* @0x201184 strd r4, r5, [r0, #16] */
/* @0x201188 strd r2, r3, [r0, #8] */
/* @0x20118c pop {r4, r5} */
/* @0x201190 bx lr */

/* ── FUNC 0x201194 · CStream::SaveToFile(char const*) · size=80 · insn=20 */
/* @0x201194 push {r3, r4, r5, lr} */
/* @0x201198 mov r4, r0 */
/* @0x20119c ldr r3, [r0, #0x18] */
/* @0x2011a0 cmp r3, #0 */
/* @0x2011a4 popeq {r3, r4, r5, pc} */
/* @0x2011a8 mov r0, r1 */
/* @0x2011ac ldr r1, [pc, #0x2c] */
/* @0x2011b0 add r1, pc, r1 */
/* @0x2011b4 bl 0xb6844 <fopen@plt> */
/* @0x2011b8 subs r5, r0, #0 */
/* @0x2011bc popeq {r3, r4, r5, pc} */
/* @0x2011c0 ldr r0, [r4, #0x18] */
/* @0x2011c4 mov r3, r5 */
/* @0x2011c8 ldr r1, [r4, #0x10] */
/* @0x2011cc mov r2, #1 */
/* @0x2011d0 bl 0xb68bc <fwrite@plt> */
/* @0x2011d4 mov r0, r5 */
/* @0x2011d8 pop {r3, r4, r5, lr} */
/* @0x2011dc b 0xb6850 <fclose@plt> */
/* @0x2011e0 mulseq r3, r4, r1 */

/* ── FUNC 0x2011e4 · CStream::ReadBuffer(void*, int) · size=160 · insn=40 */
/* @0x2011e4 cmp r1, #0 */
/* @0x2011e8 mov r3, r0 */
/* @0x2011ec push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2011f0 mov r12, r2 */
/* @0x2011f4 sub sp, sp, #12 */
/* @0x2011f8 beq 0x201278 <_ZN7CStream10ReadBufferEPvi+0x94> */
/* @0x2011fc ldrd r6, r7, [r0, #8] */
/* @0x201200 asr r9, r2, #31 */
/* @0x201204 ldrd r4, r5, [r0, #16] */
/* @0x201208 mov r8, r2 */
/* @0x20120c mov r10, r6 */
/* @0x201210 mov r11, r7 */
/* @0x201214 subs r10, r10, r4 */
/* @0x201218 sbc r11, r11, r5 */
/* @0x20121c cmp r10, r8 */
/* @0x201220 sbcs r2, r11, r9 */
/* @0x201224 rsblt r12, r4, r6 */
/* @0x201228 cmp r12, #0 */
/* @0x20122c movle r0, #0 */
/* @0x201230 ble 0x201270 <_ZN7CStream10ReadBufferEPvi+0x8c> */
/* @0x201234 ldr lr, [r3, #0x18] */
/* @0x201238 mov r2, r12 */
/* @0x20123c mov r0, r1 */
/* @0x201240 str r3, [sp, #0x4] */
/* @0x201244 add r1, lr, r4 */
/* @0x201248 str r12, [sp] */
/* @0x20124c bl 0xb65bc <memcpy@plt> */
/* @0x201250 ldr r3, [sp, #0x4] */
/* @0x201254 ldr r12, [sp] */
/* @0x201258 mov r2, #0 */
/* @0x20125c ldr r1, [r3, #0x10] */
/* @0x201260 mov r0, r12 */
/* @0x201264 str r2, [r3, #0x14] */
/* @0x201268 add r12, r12, r1 */
/* @0x20126c str r12, [r3, #0x10] */
/* @0x201270 add sp, sp, #12 */
/* @0x201274 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x201278 mov r0, r1 */
/* @0x20127c add sp, sp, #12 */
/* @0x201280 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x201284 · CStream::Seek(int, short) · size=108 · insn=27 */
/* @0x201284 cmp r2, #1 */
/* @0x201288 mov r12, r0 */
/* @0x20128c push {r4, r5} */
/* @0x201290 beq 0x2012b8 <_ZN7CStream4SeekEis+0x34> */
/* @0x201294 cmp r2, #2 */
/* @0x201298 beq 0x2012d4 <_ZN7CStream4SeekEis+0x50> */
/* @0x20129c cmp r2, #0 */
/* @0x2012a0 streq r1, [r12, #0x10] */
/* @0x2012a4 streq r2, [r12, #0x14] */
/* @0x2012a8 ldrne r0, [r0, #0x10] */
/* @0x2012ac moveq r0, r1 */
/* @0x2012b0 pop {r4, r5} */
/* @0x2012b4 bx lr */
/* @0x2012b8 ldrd r4, r5, [r0, #16] */
/* @0x2012bc adds r2, r4, r1 */
/* @0x2012c0 adc r3, r5, r1, asr #31 */
/* @0x2012c4 strd r2, r3, [r0, #16] */
/* @0x2012c8 pop {r4, r5} */
/* @0x2012cc mov r0, r2 */
/* @0x2012d0 bx lr */
/* @0x2012d4 ldr r0, [r0, #0x8] */
/* @0x2012d8 mov r3, #0 */
/* @0x2012dc pop {r4, r5} */
/* @0x2012e0 add r0, r1, r0 */
/* @0x2012e4 str r3, [r12, #0x14] */
/* @0x2012e8 str r0, [r12, #0x10] */
/* @0x2012ec bx lr */

/* ── FUNC 0x2012f0 · CStream::Clear() · size=56 · insn=14 */
/* @0x2012f0 push {r3, r4, r5, lr} */
/* @0x2012f4 mov r4, r0 */
/* @0x2012f8 ldrb r5, [r0] */
/* @0x2012fc cmp r5, #0 */
/* @0x201300 popne {r3, r4, r5, pc} */
/* @0x201304 ldr r0, [r0, #0x18] */
/* @0x201308 cmp r0, #0 */
/* @0x20130c popeq {r3, r4, r5, pc} */
/* @0x201310 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x201314 mov r2, #0 */
/* @0x201318 mov r3, #0 */
/* @0x20131c str r5, [r4, #0x18] */
/* @0x201320 strd r2, r3, [r4, #8] */
/* @0x201324 pop {r3, r4, r5, pc} */

/* ── FUNC 0x201328 · CStream::~CStream() · size=20 · insn=5 */
/* @0x201328 push {r4, lr} */
/* @0x20132c mov r4, r0 */
/* @0x201330 bl 0x2012f0 <_ZN7CStream5ClearEv> */
/* @0x201334 mov r0, r4 */
/* @0x201338 pop {r4, pc} */

/* ── FUNC 0x201328 · CStream::~CStream() · alias of the symbol above · insn=0 */

/* ── FUNC 0x20133c · CStream::Free() · size=28 · insn=7 */
/* @0x20133c push {r4, lr} */
/* @0x201340 subs r4, r0, #0 */
/* @0x201344 popeq {r4, pc} */
/* @0x201348 bl 0x201328 <_ZN7CStreamD2Ev> */
/* @0x20134c mov r0, r4 */
/* @0x201350 pop {r4, lr} */
/* @0x201354 b 0x27d1d0 <_ZdlPv> */

/* ── FUNC 0x201358 · CStream::LoadFromFile(char const*, int) · size=188 · insn=47 */
/* @0x201358 ldr r3, [r0, #0x18] */
/* @0x20135c push {r4, r5, r6, r7, lr} */
/* @0x201360 cmp r3, #0 */
/* @0x201364 sub sp, sp, #12 */
/* @0x201368 mov r4, r0 */
/* @0x20136c mov r5, r1 */
/* @0x201370 mov r6, r2 */
/* @0x201374 beq 0x20137c <_ZN7CStream12LoadFromFileEPKci+0x24> */
/* @0x201378 bl 0x2012f0 <_ZN7CStream5ClearEv> */
/* @0x20137c mov r0, r5 */
/* @0x201380 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc> */
/* @0x201384 cmp r0, #0 */
/* @0x201388 mov r0, r5 */
/* @0x20138c beq 0x2013f0 <_ZN7CStream12LoadFromFileEPKci+0x98> */
/* @0x201390 add r1, sp, #4 */
/* @0x201394 bl 0x18fb08 <_ZN8LoadSave12ReadSaveFileEPKcPi> */
/* @0x201398 mov r5, r0 */
/* @0x20139c cmp r5, #0 */
/* @0x2013a0 beq 0x2013e8 <_ZN7CStream12LoadFromFileEPKci+0x90> */
/* @0x2013a4 ldr r7, [sp, #0x4] */
/* @0x2013a8 mov r3, #0 */
/* @0x2013ac ldr r1, [pc, #0x5c] */
/* @0x2013b0 mov r2, #272 */
/* @0x2013b4 rsb r7, r6, r7 */
/* @0x2013b8 str r3, [r4, #0xc] */
/* @0x2013bc add r1, pc, r1 */
/* @0x2013c0 mov r3, #1 */
/* @0x2013c4 str r7, [r4, #0x8] */
/* @0x2013c8 mov r0, r7 */
/* @0x2013cc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x2013d0 mov r2, r7 */
/* @0x2013d4 add r1, r5, r6 */
/* @0x2013d8 str r0, [r4, #0x18] */
/* @0x2013dc bl 0xb65bc <memcpy@plt> */
/* @0x2013e0 mov r0, r5 */
/* @0x2013e4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2013e8 add sp, sp, #12 */
/* @0x2013ec pop {r4, r5, r6, r7, pc} */
/* @0x2013f0 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc> */
/* @0x2013f4 cmp r0, #0 */
/* @0x2013f8 beq 0x2013e8 <_ZN7CStream12LoadFromFileEPKci+0x90> */
/* @0x2013fc mov r0, r5 */
/* @0x201400 add r1, sp, #4 */
/* @0x201404 bl 0x18f848 <_ZN8LoadSave14ReadBundleFileEPKcPi> */
/* @0x201408 mov r5, r0 */
/* @0x20140c b 0x20139c <_ZN7CStream12LoadFromFileEPKci+0x44> */
/* @0x201410 andseq r2, r5, r12, ror #6 */

/* ── FUNC 0x201414 · CStream::_AllocExtraSpace(int) · size=180 · insn=45 */
/* @0x201414 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x201418 subs r9, r1, #0 */
/* @0x20141c mov r8, r0 */
/* @0x201420 sub sp, sp, #12 */
/* @0x201424 movle r0, #0 */
/* @0x201428 ble 0x2014bc <_ZN7CStream16_AllocExtraSpaceEi+0xa8> */
/* @0x20142c ldrd r4, r5, [r8, #8] */
/* @0x201430 asr r1, r9, #31 */
/* @0x201434 ldrd r2, r3, [r8, #16] */
/* @0x201438 mov r0, r9 */
/* @0x20143c mov r6, r4 */
/* @0x201440 mov r7, r5 */
/* @0x201444 subs r6, r6, r2 */
/* @0x201448 sbc r7, r7, r3 */
/* @0x20144c cmp r6, r0 */
/* @0x201450 sbcs r12, r7, r1 */
/* @0x201454 movge r0, r9 */
/* @0x201458 bge 0x2014bc <_ZN7CStream16_AllocExtraSpaceEi+0xa8> */
/* @0x20145c adds r0, r0, r2 */
/* @0x201460 lsl r4, r4, #1 */
/* @0x201464 adc r1, r1, r3 */
/* @0x201468 mov r7, #0 */
/* @0x20146c mov r6, r4 */
/* @0x201470 cmp r0, r6 */
/* @0x201474 sbcs r12, r1, r7 */
/* @0x201478 addge r4, r9, r2 */
/* @0x20147c movge r7, #0 */
/* @0x201480 movge r6, r4 */
/* @0x201484 ldr r2, [pc, #0x38] */
/* @0x201488 mov r3, #0 */
/* @0x20148c ldr r0, [r8, #0x18] */
/* @0x201490 mov r1, r4 */
/* @0x201494 str r3, [sp] */
/* @0x201498 add r2, pc, r2 */
/* @0x20149c mov r3, #384 */
/* @0x2014a0 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x2014a4 strd r6, r7, [r8, #8] */
/* @0x2014a8 cmp r0, #0 */
/* @0x2014ac mov r3, r0 */
/* @0x2014b0 str r3, [r8, #0x18] */
/* @0x2014b4 movne r0, r9 */
/* @0x2014b8 moveq r0, #0 */
/* @0x2014bc add sp, sp, #12 */
/* @0x2014c0 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x2014c4 mulseq r5, r0, r2 */

/* ── FUNC 0x2014c8 · CStream::Write(void*, int) · size=256 · insn=64 */
/* @0x2014c8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2014cc subs r11, r2, #0 */
/* @0x2014d0 mov r10, r0 */
/* @0x2014d4 sub sp, sp, #20 */
/* @0x2014d8 mov r12, r1 */
/* @0x2014dc movle r0, #0 */
/* @0x2014e0 ble 0x201598 <_ZN7CStream5WriteEPvi+0xd0> */
/* @0x2014e4 cmp r1, #0 */
/* @0x2014e8 beq 0x2015b0 <_ZN7CStream5WriteEPvi+0xe8> */
/* @0x2014ec ldrd r6, r7, [r10, #8] */
/* @0x2014f0 asr r5, r11, #31 */
/* @0x2014f4 ldrd r0, r1, [r10, #16] */
/* @0x2014f8 mov r4, r11 */
/* @0x2014fc mov r8, r6 */
/* @0x201500 mov r9, r7 */
/* @0x201504 subs r8, r8, r0 */
/* @0x201508 sbc r9, r9, r1 */
/* @0x20150c cmp r8, r4 */
/* @0x201510 sbcs r3, r9, r5 */
/* @0x201514 bge 0x2015b8 <_ZN7CStream5WriteEPvi+0xf0> */
/* @0x201518 adds r2, r11, r0 */
/* @0x20151c lsl r6, r6, #1 */
/* @0x201520 adc r3, r5, r1 */
/* @0x201524 mov r9, #0 */
/* @0x201528 mov r8, r6 */
/* @0x20152c cmp r2, r8 */
/* @0x201530 sbcs lr, r3, r9 */
/* @0x201534 bge 0x2015a0 <_ZN7CStream5WriteEPvi+0xd8> */
/* @0x201538 ldr r2, [pc, #0x84] */
/* @0x20153c mov r3, #0 */
/* @0x201540 ldr r0, [r10, #0x18] */
/* @0x201544 mov r1, r6 */
/* @0x201548 str r3, [sp] */
/* @0x20154c add r2, pc, r2 */
/* @0x201550 movw r3, #0x1ad */
/* @0x201554 str r12, [sp, #0xc] */
/* @0x201558 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x20155c strd r8, r9, [r10, #8] */
/* @0x201560 ldr r12, [sp, #0xc] */
/* @0x201564 cmp r0, #0 */
/* @0x201568 str r0, [r10, #0x18] */
/* @0x20156c beq 0x201598 <_ZN7CStream5WriteEPvi+0xd0> */
/* @0x201570 ldr r3, [r10, #0x10] */
/* @0x201574 add r0, r0, r3 */
/* @0x201578 mov r2, r11 */
/* @0x20157c mov r1, r12 */
/* @0x201580 bl 0xb65bc <memcpy@plt> */
/* @0x201584 ldrd r2, r3, [r10, #16] */
/* @0x201588 mov r0, r11 */
/* @0x20158c adds r4, r4, r2 */
/* @0x201590 adc r5, r5, r3 */
/* @0x201594 strd r4, r5, [r10, #16] */
/* @0x201598 add sp, sp, #20 */
/* @0x20159c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2015a0 add r6, r11, r0 */
/* @0x2015a4 mov r9, #0 */
/* @0x2015a8 mov r8, r6 */
/* @0x2015ac b 0x201538 <_ZN7CStream5WriteEPvi+0x70> */
/* @0x2015b0 mov r0, r1 */
/* @0x2015b4 b 0x201598 <_ZN7CStream5WriteEPvi+0xd0> */
/* @0x2015b8 mov r3, r0 */
/* @0x2015bc ldr r0, [r10, #0x18] */
/* @0x2015c0 b 0x201574 <_ZN7CStream5WriteEPvi+0xac> */
/* @0x2015c4 ldrsbeq r2, [r5], -r12 */

/* ── FUNC 0x2015c8 · CStream::CopyFrom(CStream*, long long, bool) · size=324 · insn=81 */
/* @0x2015c8 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2015cc mov r5, r3 */
/* @0x2015d0 ldrb r3, [sp, #0x20] */
/* @0x2015d4 mov r4, r2 */
/* @0x2015d8 orrs r2, r4, r5 */
/* @0x2015dc mov r7, r0 */
/* @0x2015e0 mov r6, r1 */
/* @0x2015e4 strb r3, [r0] */
/* @0x2015e8 mov r0, r1 */
/* @0x2015ec beq 0x2016a0 <_ZN7CStream8CopyFromEPS_xb+0xd8> */
/* @0x2015f0 cmp r3, #0 */
/* @0x2015f4 mov r8, r4 */
/* @0x2015f8 bne 0x201674 <_ZN7CStream8CopyFromEPS_xb+0xac> */
/* @0x2015fc bl 0x201158 <_ZN7CStream9GetMemoryEv> */
/* @0x201600 mov r8, r0 */
/* @0x201604 mov r0, r6 */
/* @0x201608 bl 0x201160 <_ZN7CStream11GetPositionEv> */
/* @0x20160c add r8, r8, r0 */
/* @0x201610 mov r0, r6 */
/* @0x201614 bl 0x201168 <_ZN7CStream7GetSizeEv> */
/* @0x201618 mov r9, r0 */
/* @0x20161c mov r0, r6 */
/* @0x201620 bl 0x201160 <_ZN7CStream11GetPositionEv> */
/* @0x201624 rsb r0, r0, r9 */
/* @0x201628 asr r3, r0, #31 */
/* @0x20162c mov r2, r0 */
/* @0x201630 cmp r2, r4 */
/* @0x201634 sbcs r1, r3, r5 */
/* @0x201638 movge r9, r4 */
/* @0x20163c blt 0x2016f0 <_ZN7CStream8CopyFromEPS_xb+0x128> */
/* @0x201640 mov r1, r8 */
/* @0x201644 mov r0, r7 */
/* @0x201648 mov r2, r9 */
/* @0x20164c bl 0x2014c8 <_ZN7CStream5WriteEPvi> */
/* @0x201650 mov r8, r0 */
/* @0x201654 mov r0, r6 */
/* @0x201658 bl 0x201160 <_ZN7CStream11GetPositionEv> */
/* @0x20165c add r1, r9, r0 */
/* @0x201660 mov r0, r6 */
/* @0x201664 bl 0x201148 <_ZN7CStream11SetPositionEi> */
/* @0x201668 mov r0, r8 */
/* @0x20166c asr r1, r8, #31 */
/* @0x201670 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x201674 bl 0x201158 <_ZN7CStream9GetMemoryEv> */
/* @0x201678 mov r5, #0 */
/* @0x20167c mov r9, r4 */
/* @0x201680 mov r10, r0 */
/* @0x201684 mov r0, r6 */
/* @0x201688 bl 0x201160 <_ZN7CStream11GetPositionEv> */
/* @0x20168c strd r4, r5, [r7, #8] */
/* @0x201690 strd r4, r5, [r7, #16] */
/* @0x201694 add r0, r10, r0 */
/* @0x201698 str r0, [r7, #0x18] */
/* @0x20169c b 0x201654 <_ZN7CStream8CopyFromEPS_xb+0x8c> */
/* @0x2016a0 mov r1, #0 */
/* @0x2016a4 bl 0x201148 <_ZN7CStream11SetPositionEi> */
/* @0x2016a8 mov r0, r6 */
/* @0x2016ac bl 0x201158 <_ZN7CStream9GetMemoryEv> */
/* @0x2016b0 mov r4, r0 */
/* @0x2016b4 mov r0, r6 */
/* @0x2016b8 bl 0x201168 <_ZN7CStream7GetSizeEv> */
/* @0x2016bc mov r1, r4 */
/* @0x2016c0 mov r2, r0 */
/* @0x2016c4 mov r0, r7 */
/* @0x2016c8 bl 0x2014c8 <_ZN7CStream5WriteEPvi> */
/* @0x2016cc mov r4, r0 */
/* @0x2016d0 mov r0, r6 */
/* @0x2016d4 bl 0x201168 <_ZN7CStream7GetSizeEv> */
/* @0x2016d8 mov r1, r0 */
/* @0x2016dc mov r0, r6 */
/* @0x2016e0 bl 0x201148 <_ZN7CStream11SetPositionEi> */
/* @0x2016e4 mov r0, r4 */
/* @0x2016e8 asr r1, r4, #31 */
/* @0x2016ec pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2016f0 mov r0, r6 */
/* @0x2016f4 bl 0x201168 <_ZN7CStream7GetSizeEv> */
/* @0x2016f8 mov r9, r0 */
/* @0x2016fc mov r0, r6 */
/* @0x201700 bl 0x201160 <_ZN7CStream11GetPositionEv> */
/* @0x201704 rsb r9, r0, r9 */
/* @0x201708 b 0x201640 <_ZN7CStream8CopyFromEPS_xb+0x78> */

/* ── FUNC 0x20170c · CStream::CopyFrom(CStream*, long long) · size=28 · insn=7 */
/* @0x20170c str lr, [sp, #-0x4]! */
/* @0x201710 sub sp, sp, #12 */
/* @0x201714 mov r12, #0 */
/* @0x201718 str r12, [sp] */
/* @0x20171c bl 0x2015c8 <_ZN7CStream8CopyFromEPS_xb> */
/* @0x201720 add sp, sp, #12 */
/* @0x201724 ldr pc, [sp], #4 */

/* ── FUNC 0x201728 · CStream::WriteBuffer(void*, int) · size=4 · insn=1 */
/* @0x201728 b 0x2014c8 <_ZN7CStream5WriteEPvi> */

/* ── FUNC 0x20172c · CStream::Read(void*, int) · size=4 · insn=1 */
/* @0x20172c b 0x2011e4 <_ZN7CStream10ReadBufferEPvi> */

/* ── FUNC 0x201730 · CStream::ReadInteger() · size=84 · insn=21 */
/* @0x201730 ldrd r2, r3, [r0, #16] */
/* @0x201734 ldr r1, [r0, #0x8] */
/* @0x201738 ldr r12, [r0, #0x18] */
/* @0x20173c cmp r1, r2 */
/* @0x201740 push {r4, r5} */
/* @0x201744 movle r0, #0 */
/* @0x201748 ble 0x20177c <_ZN7CStream11ReadIntegerEv+0x4c> */
/* @0x20174c add r1, r12, r2 */
/* @0x201750 ldrb r12, [r12, r2] */
/* @0x201754 adds r2, r2, #4 */
/* @0x201758 ldrb r4, [r1, #0x2] */
/* @0x20175c adc r3, r3, #0 */
/* @0x201760 ldrb r5, [r1, #0x1] */
/* @0x201764 ldrb r1, [r1, #0x3] */
/* @0x201768 lsl r4, r4, #16 */
/* @0x20176c strd r2, r3, [r0, #16] */
/* @0x201770 orr r0, r4, r5, lsl #8 */
/* @0x201774 orr r0, r0, r12 */
/* @0x201778 orr r0, r0, r1, lsl #24 */
/* @0x20177c pop {r4, r5} */
/* @0x201780 bx lr */

/* ── FUNC 0x201784 · CStream::ReadInteger64() · size=248 · insn=62 */
/* @0x201784 push {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x201788 sub sp, sp, #24 */
/* @0x20178c ldrd r4, r5, [r0, #16] */
/* @0x201790 ldr r3, [r0, #0x8] */
/* @0x201794 ldr r12, [r0, #0x18] */
/* @0x201798 cmp r3, r4 */
/* @0x20179c movle r0, #0 */
/* @0x2017a0 movle r1, #0 */
/* @0x2017a4 ble 0x201870 <_ZN7CStream13ReadInteger64Ev+0xec> */
/* @0x2017a8 add r1, r12, r4 */
/* @0x2017ac mov r7, #0 */
/* @0x2017b0 ldrb r2, [r1, #0x1] */
/* @0x2017b4 ldrb r10, [r1, #0x2] */
/* @0x2017b8 ldrb r6, [r1, #0x3] */
/* @0x2017bc lsl r8, r2, #8 */
/* @0x2017c0 lsr r9, r2, #24 */
/* @0x2017c4 ldrb r3, [r1, #0x4] */
/* @0x2017c8 mov r2, #0 */
/* @0x2017cc strd r6, r7, [sp] */
/* @0x2017d0 lsl r6, r10, #16 */
/* @0x2017d4 lsr r7, r10, #16 */
/* @0x2017d8 orr r10, r8, r6 */
/* @0x2017dc ldrb r6, [r12, r4] */
/* @0x2017e0 orr r11, r9, r7 */
/* @0x2017e4 ldr r7, [sp] */
/* @0x2017e8 adds r4, r4, #8 */
/* @0x2017ec orr r6, r6, r10 */
/* @0x2017f0 ldrb r10, [r1, #0x5] */
/* @0x2017f4 adc r5, r5, #0 */
/* @0x2017f8 lsr r9, r7, #8 */
/* @0x2017fc mov r7, #0 */
/* @0x201800 orr r7, r7, r11 */
/* @0x201804 mov r11, #0 */
/* @0x201808 strd r10, r11, [sp, #8] */
/* @0x20180c orr r9, r9, r7 */
/* @0x201810 ldr r11, [sp] */
/* @0x201814 mov r7, #0 */
/* @0x201818 ldrb r10, [r1, #0x6] */
/* @0x20181c orr r9, r9, r3 */
/* @0x201820 lsl r8, r11, #24 */
/* @0x201824 mov r11, #0 */
/* @0x201828 orr r8, r8, r6 */
/* @0x20182c ldrb r6, [r1, #0x7] */
/* @0x201830 strd r10, r11, [sp] */
/* @0x201834 orr r8, r8, r2 */
/* @0x201838 ldr r12, [sp] */
/* @0x20183c orr r8, r8, r2 */
/* @0x201840 strd r6, r7, [sp, #16] */
/* @0x201844 orr r8, r8, r2 */
/* @0x201848 ldr r7, [sp, #0x8] */
/* @0x20184c ldr r1, [sp, #0x10] */
/* @0x201850 strd r4, r5, [r0, #16] */
/* @0x201854 orr r0, r8, r2 */
/* @0x201858 lsl r11, r7, #8 */
/* @0x20185c lsl r7, r12, #16 */
/* @0x201860 orr r9, r9, r11 */
/* @0x201864 lsl r11, r1, #24 */
/* @0x201868 orr r9, r9, r7 */
/* @0x20186c orr r1, r9, r11 */
/* @0x201870 add sp, sp, #24 */
/* @0x201874 pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x201878 bx lr */

/* ── FUNC 0x20187c · CStream::ReadReal() · size=108 · insn=27 */
/* @0x20187c ldrd r2, r3, [r0, #16] */
/* @0x201880 ldr r1, [r0, #0x8] */
/* @0x201884 push {r4, r5} */
/* @0x201888 cmp r1, r2 */
/* @0x20188c sub sp, sp, #8 */
/* @0x201890 mov r4, #0 */
/* @0x201894 mov r5, #0 */
/* @0x201898 ldr r12, [r0, #0x18] */
/* @0x20189c strd r4, r5, [sp] */
/* @0x2018a0 ble 0x2018d4 <_ZN7CStream8ReadRealEv+0x58> */
/* @0x2018a4 add r5, r12, r2 */
/* @0x2018a8 mov r4, sp */
/* @0x2018ac mov r1, #0 */
/* @0x2018b0 ldrb r12, [r5, r1] */
/* @0x2018b4 strb r12, [r4, r1] */
/* @0x2018b8 add r1, r1, #1 */
/* @0x2018bc cmp r1, #8 */
/* @0x2018c0 bne 0x2018b0 <_ZN7CStream8ReadRealEv+0x34> */
/* @0x2018c4 ldrd r4, r5, [sp] */
/* @0x2018c8 adds r2, r2, #8 */
/* @0x2018cc adc r3, r3, #0 */
/* @0x2018d0 strd r2, r3, [r0, #16] */
/* @0x2018d4 mov r0, r4 */
/* @0x2018d8 mov r1, r5 */
/* @0x2018dc add sp, sp, #8 */
/* @0x2018e0 pop {r4, r5} */
/* @0x2018e4 bx lr */

/* ── FUNC 0x2018e8 · CStream::ReadString(char const*&) · size=104 · insn=26 */
/* @0x2018e8 push {r4, r5, r6, lr} */
/* @0x2018ec sub sp, sp, #8 */
/* @0x2018f0 mov r4, r1 */
/* @0x2018f4 mov r2, #4 */
/* @0x2018f8 add r1, sp, r2 */
/* @0x2018fc mov r5, r0 */
/* @0x201900 bl 0x2011e4 <_ZN7CStream10ReadBufferEPvi> */
/* @0x201904 ldr r0, [sp, #0x4] */
/* @0x201908 cmp r0, #0 */
/* @0x20190c streq r0, [r4] */
/* @0x201910 beq 0x201944 <_ZN7CStream10ReadStringERPKc+0x5c> */
/* @0x201914 ldr r1, [pc, #0x30] */
/* @0x201918 movw r2, #0x21e */
/* @0x20191c mov r3, #1 */
/* @0x201920 add r0, r0, #1 */
/* @0x201924 add r1, pc, r1 */
/* @0x201928 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x20192c ldr r2, [sp, #0x4] */
/* @0x201930 mov r6, r0 */
/* @0x201934 mov r0, r5 */
/* @0x201938 mov r1, r6 */
/* @0x20193c bl 0x2011e4 <_ZN7CStream10ReadBufferEPvi> */
/* @0x201940 str r6, [r4] */
/* @0x201944 add sp, sp, #8 */
/* @0x201948 pop {r4, r5, r6, pc} */
/* @0x20194c andseq r1, r5, r4, lsl #28 */

/* ── FUNC 0x201950 · CStream::ReadString() · size=96 · insn=24 */
/* @0x201950 push {r4, r5, lr} */
/* @0x201954 sub sp, sp, #12 */
/* @0x201958 add r1, sp, #4 */
/* @0x20195c mov r2, #4 */
/* @0x201960 mov r5, r0 */
/* @0x201964 bl 0x2011e4 <_ZN7CStream10ReadBufferEPvi> */
/* @0x201968 ldr r0, [sp, #0x4] */
/* @0x20196c cmp r0, #0 */
/* @0x201970 beq 0x2019a4 <_ZN7CStream10ReadStringEv+0x54> */
/* @0x201974 ldr r1, [pc, #0x30] */
/* @0x201978 movw r2, #0x239 */
/* @0x20197c mov r3, #1 */
/* @0x201980 add r0, r0, #1 */
/* @0x201984 add r1, pc, r1 */
/* @0x201988 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x20198c ldr r2, [sp, #0x4] */
/* @0x201990 mov r4, r0 */
/* @0x201994 mov r0, r5 */
/* @0x201998 mov r1, r4 */
/* @0x20199c bl 0x2011e4 <_ZN7CStream10ReadBufferEPvi> */
/* @0x2019a0 mov r0, r4 */
/* @0x2019a4 add sp, sp, #12 */
/* @0x2019a8 pop {r4, r5, pc} */
/* @0x2019ac andseq r1, r5, r4, lsr #27 */

/* ── FUNC 0x2019b0 · CStream::ReadBoolean() · size=20 · insn=5 */
/* @0x2019b0 push {r3, lr} */
/* @0x2019b4 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x2019b8 adds r0, r0, #0 */
/* @0x2019bc movne r0, #1 */
/* @0x2019c0 pop {r3, pc} */

/* ── FUNC 0x2019c4 · CStream::ReadStream() · size=76 · insn=19 */
/* @0x2019c4 push {r3, r4, r5, lr} */
/* @0x2019c8 mov r5, r0 */
/* @0x2019cc mov r0, #32 */
/* @0x2019d0 bl 0x27c524 <_Znwj> */
/* @0x2019d4 mov r1, #0 */
/* @0x2019d8 mov r4, r0 */
/* @0x2019dc bl 0x2010ec <_ZN7CStreamC2Ei> */
/* @0x2019e0 mov r0, r5 */
/* @0x2019e4 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x2019e8 mov r1, r5 */
/* @0x2019ec mov r2, r0 */
/* @0x2019f0 asr r3, r0, #31 */
/* @0x2019f4 mov r0, r4 */
/* @0x2019f8 bl 0x20170c <_ZN7CStream8CopyFromEPS_x> */
/* @0x2019fc mov r0, r4 */
/* @0x201a00 mov r1, #0 */
/* @0x201a04 bl 0x201148 <_ZN7CStream11SetPositionEi> */
/* @0x201a08 mov r0, r4 */
/* @0x201a0c pop {r3, r4, r5, pc} */

/* ── FUNC 0x201a10 · CStream::WriteInteger(int) · size=88 · insn=22 */
/* @0x201a10 push {r3, r4, r5, lr} */
/* @0x201a14 mov r4, r0 */
/* @0x201a18 mov r5, r1 */
/* @0x201a1c mov r1, #4 */
/* @0x201a20 bl 0x201414 <_ZN7CStream16_AllocExtraSpaceEi> */
/* @0x201a24 ldr r2, [r4, #0x10] */
/* @0x201a28 ldr r1, [r4, #0x8] */
/* @0x201a2c ldr r3, [r4, #0x18] */
/* @0x201a30 cmp r1, r2 */
/* @0x201a34 pople {r3, r4, r5, pc} */
/* @0x201a38 strb r5, [r3, r2]! */
/* @0x201a3c asr r1, r5, #8 */
/* @0x201a40 asr r2, r5, #16 */
/* @0x201a44 strb r1, [r3, #0x1] */
/* @0x201a48 strb r2, [r3, #0x2] */
/* @0x201a4c lsr r5, r5, #24 */
/* @0x201a50 strb r5, [r3, #0x3] */
/* @0x201a54 ldrd r2, r3, [r4, #16] */
/* @0x201a58 adds r2, r2, #4 */
/* @0x201a5c adc r3, r3, #0 */
/* @0x201a60 strd r2, r3, [r4, #16] */
/* @0x201a64 pop {r3, r4, r5, pc} */

/* ── FUNC 0x201a68 · CStream::WriteInteger64(long long) · size=120 · insn=30 */
/* @0x201a68 push {r4, r5, r6, lr} */
/* @0x201a6c mov r1, #8 */
/* @0x201a70 mov r4, r0 */
/* @0x201a74 mov r5, r2 */
/* @0x201a78 mov r6, r3 */
/* @0x201a7c bl 0x201414 <_ZN7CStream16_AllocExtraSpaceEi> */
/* @0x201a80 ldr r3, [r4, #0x10] */
/* @0x201a84 ldr r2, [r4, #0x8] */
/* @0x201a88 ldr r1, [r4, #0x18] */
/* @0x201a8c cmp r2, r3 */
/* @0x201a90 pople {r4, r5, r6, pc} */
/* @0x201a94 strb r5, [r1, r3]! */
/* @0x201a98 lsr r2, r5, #8 */
/* @0x201a9c lsr r3, r5, #16 */
/* @0x201aa0 strb r6, [r1, #0x4] */
/* @0x201aa4 strb r2, [r1, #0x1] */
/* @0x201aa8 lsr r5, r5, #24 */
/* @0x201aac asr r2, r6, #8 */
/* @0x201ab0 strb r3, [r1, #0x2] */
/* @0x201ab4 strb r5, [r1, #0x3] */
/* @0x201ab8 asr r3, r6, #16 */
/* @0x201abc strb r2, [r1, #0x5] */
/* @0x201ac0 lsr r6, r6, #24 */
/* @0x201ac4 strb r3, [r1, #0x6] */
/* @0x201ac8 strb r6, [r1, #0x7] */
/* @0x201acc ldrd r2, r3, [r4, #16] */
/* @0x201ad0 adds r2, r2, #8 */
/* @0x201ad4 adc r3, r3, #0 */
/* @0x201ad8 strd r2, r3, [r4, #16] */
/* @0x201adc pop {r4, r5, r6, pc} */

/* ── FUNC 0x201ae0 · CStream::WriteReal(double) · size=120 · insn=30 */
/* @0x201ae0 push {r4, r5, r6, lr} */
/* @0x201ae4 mov r1, #8 */
/* @0x201ae8 mov r4, r0 */
/* @0x201aec mov r6, r2 */
/* @0x201af0 mov r5, r3 */
/* @0x201af4 bl 0x201414 <_ZN7CStream16_AllocExtraSpaceEi> */
/* @0x201af8 ldr r0, [r4, #0x10] */
/* @0x201afc ldr r12, [r4, #0x8] */
/* @0x201b00 ldr r1, [r4, #0x18] */
/* @0x201b04 cmp r12, r0 */
/* @0x201b08 pople {r4, r5, r6, pc} */
/* @0x201b0c strb r6, [r1, r0]! */
/* @0x201b10 lsr r12, r6, #8 */
/* @0x201b14 lsr r0, r6, #16 */
/* @0x201b18 strb r12, [r1, #0x1] */
/* @0x201b1c strb r0, [r1, #0x2] */
/* @0x201b20 lsr r2, r6, #24 */
/* @0x201b24 strb r5, [r1, #0x4] */
/* @0x201b28 lsr r3, r5, #24 */
/* @0x201b2c strb r2, [r1, #0x3] */
/* @0x201b30 lsr r12, r5, #8 */
/* @0x201b34 strb r3, [r1, #0x7] */
/* @0x201b38 lsr r0, r5, #16 */
/* @0x201b3c strb r12, [r1, #0x5] */
/* @0x201b40 strb r0, [r1, #0x6] */
/* @0x201b44 ldrd r2, r3, [r4, #16] */
/* @0x201b48 adds r2, r2, #8 */
/* @0x201b4c adc r3, r3, #0 */
/* @0x201b50 strd r2, r3, [r4, #16] */
/* @0x201b54 pop {r4, r5, r6, pc} */

/* ── FUNC 0x201b58 · CStream::WriteString(char const*) · size=96 · insn=24 */
/* @0x201b58 push {r4, r5, lr} */
/* @0x201b5c subs r5, r1, #0 */
/* @0x201b60 sub sp, sp, #12 */
/* @0x201b64 mov r3, #0 */
/* @0x201b68 mov r4, r0 */
/* @0x201b6c str r3, [sp, #0x4] */
/* @0x201b70 beq 0x201b80 <_ZN7CStream11WriteStringEPKc+0x28> */
/* @0x201b74 mov r0, r5 */
/* @0x201b78 bl 0xb6538 <strlen@plt> */
/* @0x201b7c str r0, [sp, #0x4] */
/* @0x201b80 mov r2, #4 */
/* @0x201b84 mov r0, r4 */
/* @0x201b88 add r1, sp, #4 */
/* @0x201b8c bl 0x2014c8 <_ZN7CStream5WriteEPvi> */
/* @0x201b90 ldr r2, [sp, #0x4] */
/* @0x201b94 cmp r2, #0 */
/* @0x201b98 bne 0x201ba4 <_ZN7CStream11WriteStringEPKc+0x4c> */
/* @0x201b9c add sp, sp, #12 */
/* @0x201ba0 pop {r4, r5, pc} */
/* @0x201ba4 mov r0, r4 */
/* @0x201ba8 mov r1, r5 */
/* @0x201bac bl 0x2014c8 <_ZN7CStream5WriteEPvi> */
/* @0x201bb0 add sp, sp, #12 */
/* @0x201bb4 pop {r4, r5, pc} */
