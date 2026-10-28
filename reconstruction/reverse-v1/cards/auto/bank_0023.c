/* libyoyo.so 覆盖卡组 0023
 * 函数 0xf5098..0xf5804，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0xf5098 · CExtensionFile::CExtensionFile() · alias of the symbol above · insn=0 */

/* ── FUNC 0xf50e4 · CExtensionFile::~CExtensionFile() · size=108 · insn=27 */
/* @0xf50e4 push {r3, r4, r5, lr} */
/* @0xf50e8 mov r4, r0 */
/* @0xf50ec ldr r3, [pc, #0x58] */
/* @0xf50f0 mov r5, #0 */
/* @0xf50f4 ldr r0, [r0, #0x4] */
/* @0xf50f8 ldr r3, [pc, r3] */
/* @0xf50fc add r3, r3, #8 */
/* @0xf5100 str r3, [r4] */
/* @0xf5104 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xf5108 ldr r0, [r4, #0xc] */
/* @0xf510c str r5, [r4, #0x4] */
/* @0xf5110 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xf5114 ldr r0, [r4, #0x10] */
/* @0xf5118 str r5, [r4, #0xc] */
/* @0xf511c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xf5120 mov r0, r4 */
/* @0xf5124 str r5, [r4, #0x10] */
/* @0xf5128 bl 0xf5064 <_ZN14CExtensionFile5ClearEv> */
/* @0xf512c ldr r0, [r4, #0x18] */
/* @0xf5130 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xf5134 ldr r0, [r4, #0x24] */
/* @0xf5138 str r5, [r4, #0x18] */
/* @0xf513c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xf5140 str r5, [r4, #0x24] */
/* @0xf5144 mov r0, r4 */
/* @0xf5148 pop {r3, r4, r5, pc} */
/* @0xf514c eoreq r8, pc, r4, lsr sp */

/* ── FUNC 0xf50e4 · CExtensionFile::~CExtensionFile() · alias of the symbol above · insn=0 */

/* ── FUNC 0xf5150 · CExtensionFile::~CExtensionFile() · size=28 · insn=7 */
/* @0xf5150 push {r4, lr} */
/* @0xf5154 mov r4, r0 */
/* @0xf5158 bl 0xf50e4 <_ZN14CExtensionFileD2Ev> */
/* @0xf515c mov r0, r4 */
/* @0xf5160 bl 0x27d1d0 <_ZdlPv> */
/* @0xf5164 mov r0, r4 */
/* @0xf5168 pop {r4, pc} */

/* ── FUNC 0xf516c · CExtensionFile::Assign(CExtensionFile*) · size=240 · insn=60 */
/* @0xf516c push {r4, r5, r6, lr} */
/* @0xf5170 mov r4, r0 */
/* @0xf5174 ldr r0, [r0, #0x4] */
/* @0xf5178 mov r6, r1 */
/* @0xf517c cmp r0, #0 */
/* @0xf5180 beq 0xf5188 <_ZN14CExtensionFile6AssignEPS_+0x1c> */
/* @0xf5184 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xf5188 ldr r0, [r6, #0x4] */
/* @0xf518c bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xf5190 ldr r3, [r4, #0xc] */
/* @0xf5194 ldr r2, [r6, #0x8] */
/* @0xf5198 cmp r3, #0 */
/* @0xf519c stmib r4, {r0, r2} */
/* @0xf51a0 beq 0xf51ac <_ZN14CExtensionFile6AssignEPS_+0x40> */
/* @0xf51a4 mov r0, r3 */
/* @0xf51a8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xf51ac ldr r0, [r6, #0xc] */
/* @0xf51b0 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xf51b4 ldr r3, [r4, #0x10] */
/* @0xf51b8 cmp r3, #0 */
/* @0xf51bc str r0, [r4, #0xc] */
/* @0xf51c0 beq 0xf51cc <_ZN14CExtensionFile6AssignEPS_+0x60> */
/* @0xf51c4 mov r0, r3 */
/* @0xf51c8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xf51cc ldr r0, [r6, #0x10] */
/* @0xf51d0 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xf51d4 ldr r1, [r6, #0x1c] */
/* @0xf51d8 str r0, [r4, #0x10] */
/* @0xf51dc mov r0, r4 */
/* @0xf51e0 bl 0xf504c <_ZN14CExtensionFile17SetFunctionsCountEi> */
/* @0xf51e4 ldr r3, [r4, #0x1c] */
/* @0xf51e8 cmp r3, #0 */
/* @0xf51ec movgt r5, #0 */
/* @0xf51f0 ble 0xf5218 <_ZN14CExtensionFile6AssignEPS_+0xac> */
/* @0xf51f4 ldr r3, [r6, #0x18] */
/* @0xf51f8 ldr r2, [r4, #0x18] */
/* @0xf51fc ldr r1, [r3, r5, lsl #2] */
/* @0xf5200 ldr r0, [r2, r5, lsl #2] */
/* @0xf5204 add r5, r5, #1 */
/* @0xf5208 bl 0xf4a0c <_ZN18CExtensionFunction6AssignEPS_> */
/* @0xf520c ldr r3, [r4, #0x1c] */
/* @0xf5210 cmp r3, r5 */
/* @0xf5214 bgt 0xf51f4 <_ZN14CExtensionFile6AssignEPS_+0x88> */
/* @0xf5218 mov r0, r4 */
/* @0xf521c ldr r1, [r6, #0x28] */
/* @0xf5220 bl 0xf5060 <_ZN14CExtensionFile17SetConstantsCountEi> */
/* @0xf5224 ldr r3, [r4, #0x28] */
/* @0xf5228 cmp r3, #0 */
/* @0xf522c pople {r4, r5, r6, pc} */
/* @0xf5230 mov r5, #0 */
/* @0xf5234 ldr r3, [r6, #0x24] */
/* @0xf5238 ldr r2, [r4, #0x24] */
/* @0xf523c ldr r1, [r3, r5, lsl #2] */
/* @0xf5240 ldr r0, [r2, r5, lsl #2] */
/* @0xf5244 add r5, r5, #1 */
/* @0xf5248 bl 0xf482c <_ZN18CExtensionConstant6AssignEPS_> */
/* @0xf524c ldr r3, [r4, #0x28] */
/* @0xf5250 cmp r3, r5 */
/* @0xf5254 bgt 0xf5234 <_ZN14CExtensionFile6AssignEPS_+0xc8> */
/* @0xf5258 pop {r4, r5, r6, pc} */

/* ── FUNC 0xf525c · CExtensionFile::LoadFromExeStream(CStream*) · size=308 · insn=77 */
/* @0xf525c push {r4, r5, r6, lr} */
/* @0xf5260 mov r6, r1 */
/* @0xf5264 mov r4, r0 */
/* @0xf5268 bl 0xf5064 <_ZN14CExtensionFile5ClearEv> */
/* @0xf526c mov r0, r6 */
/* @0xf5270 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0xf5274 cmp r0, #700 */
/* @0xf5278 beq 0xf5284 <_ZN14CExtensionFile17LoadFromExeStreamEP7CStream+0x28> */
/* @0xf527c mov r0, #0 */
/* @0xf5280 pop {r4, r5, r6, pc} */
/* @0xf5284 ldr r0, [r4, #0x4] */
/* @0xf5288 cmp r0, #0 */
/* @0xf528c beq 0xf529c <_ZN14CExtensionFile17LoadFromExeStreamEP7CStream+0x40> */
/* @0xf5290 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xf5294 mov r3, #0 */
/* @0xf5298 str r3, [r4, #0x4] */
/* @0xf529c mov r0, r6 */
/* @0xf52a0 add r1, r4, #4 */
/* @0xf52a4 bl 0x2018e8 <_ZN7CStream10ReadStringERPKc> */
/* @0xf52a8 mov r0, r6 */
/* @0xf52ac bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0xf52b0 ldr r3, [r4, #0xc] */
/* @0xf52b4 cmp r3, #0 */
/* @0xf52b8 str r0, [r4, #0x8] */
/* @0xf52bc beq 0xf52d0 <_ZN14CExtensionFile17LoadFromExeStreamEP7CStream+0x74> */
/* @0xf52c0 mov r0, r3 */
/* @0xf52c4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xf52c8 mov r3, #0 */
/* @0xf52cc str r3, [r4, #0xc] */
/* @0xf52d0 mov r0, r6 */
/* @0xf52d4 add r1, r4, #12 */
/* @0xf52d8 bl 0x2018e8 <_ZN7CStream10ReadStringERPKc> */
/* @0xf52dc ldr r0, [r4, #0x10] */
/* @0xf52e0 cmp r0, #0 */
/* @0xf52e4 beq 0xf52f4 <_ZN14CExtensionFile17LoadFromExeStreamEP7CStream+0x98> */
/* @0xf52e8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xf52ec mov r3, #0 */
/* @0xf52f0 str r3, [r4, #0x10] */
/* @0xf52f4 add r1, r4, #16 */
/* @0xf52f8 mov r0, r6 */
/* @0xf52fc bl 0x2018e8 <_ZN7CStream10ReadStringERPKc> */
/* @0xf5300 mov r0, r6 */
/* @0xf5304 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0xf5308 mov r1, r0 */
/* @0xf530c mov r0, r4 */
/* @0xf5310 bl 0xf504c <_ZN14CExtensionFile17SetFunctionsCountEi> */
/* @0xf5314 ldr r3, [r4, #0x1c] */
/* @0xf5318 cmp r3, #0 */
/* @0xf531c movgt r5, #0 */
/* @0xf5320 ble 0xf5344 <_ZN14CExtensionFile17LoadFromExeStreamEP7CStream+0xe8> */
/* @0xf5324 ldr r3, [r4, #0x18] */
/* @0xf5328 mov r1, r6 */
/* @0xf532c ldr r0, [r3, r5, lsl #2] */
/* @0xf5330 add r5, r5, #1 */
/* @0xf5334 bl 0xf4ab8 <_ZN18CExtensionFunction17LoadFromExeStreamEP7CStream> */
/* @0xf5338 ldr r3, [r4, #0x1c] */
/* @0xf533c cmp r3, r5 */
/* @0xf5340 bgt 0xf5324 <_ZN14CExtensionFile17LoadFromExeStreamEP7CStream+0xc8> */
/* @0xf5344 mov r0, r6 */
/* @0xf5348 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0xf534c mov r1, r0 */
/* @0xf5350 mov r0, r4 */
/* @0xf5354 bl 0xf5060 <_ZN14CExtensionFile17SetConstantsCountEi> */
/* @0xf5358 ldr r3, [r4, #0x28] */
/* @0xf535c cmp r3, #0 */
/* @0xf5360 movgt r5, #0 */
/* @0xf5364 ble 0xf5388 <_ZN14CExtensionFile17LoadFromExeStreamEP7CStream+0x12c> */
/* @0xf5368 ldr r3, [r4, #0x24] */
/* @0xf536c mov r1, r6 */
/* @0xf5370 ldr r0, [r3, r5, lsl #2] */
/* @0xf5374 add r5, r5, #1 */
/* @0xf5378 bl 0xf4878 <_ZN18CExtensionConstant17LoadFromExeStreamEP7CStream> */
/* @0xf537c ldr r3, [r4, #0x28] */
/* @0xf5380 cmp r3, r5 */
/* @0xf5384 bgt 0xf5368 <_ZN14CExtensionFile17LoadFromExeStreamEP7CStream+0x10c> */
/* @0xf5388 mov r0, #1 */
/* @0xf538c pop {r4, r5, r6, pc} */

/* ── FUNC 0xf5390 · CExtensionFile::GetConstantsData(int) · size=4 · insn=1 */
/* @0xf5390 b 0xf4d88 <_ZN14CExtensionFile11GetConstantEi> */

/* ── FUNC 0xf5394 · CExtensionFile::SetConstantsData(int, CExtensionConstant*) · size=4 · insn=1 */
/* @0xf5394 b 0xf4db0 <_ZN14CExtensionFile11SetConstantEiP18CExtensionConstant> */

/* ── FUNC 0xf5398 · CExtensionPackage::GetIncludes(int) · size=40 · insn=10 */
/* @0xf5398 cmp r1, #0 */
/* @0xf539c blt 0xf53b8 <_ZN17CExtensionPackage11GetIncludesEi+0x20> */
/* @0xf53a0 ldr r3, [r0, #0x18] */
/* @0xf53a4 cmp r1, r3 */
/* @0xf53a8 bge 0xf53b8 <_ZN17CExtensionPackage11GetIncludesEi+0x20> */
/* @0xf53ac ldr r3, [r0, #0x14] */
/* @0xf53b0 ldr r0, [r3, r1, lsl #2] */
/* @0xf53b4 bx lr */
/* @0xf53b8 mov r0, #0 */
/* @0xf53bc bx lr */

/* ── FUNC 0xf53c0 · CExtensionPackage::SetIncludes(int, CExtensionFile*) · size=36 · insn=9 */
/* @0xf53c0 subs r3, r1, #0 */
/* @0xf53c4 bxlt lr */
/* @0xf53c8 ldr r12, [r0, #0x18] */
/* @0xf53cc cmp r3, r12 */
/* @0xf53d0 bxge lr */
/* @0xf53d4 ldr r0, [r0, #0x14] */
/* @0xf53d8 mov r1, r2 */
/* @0xf53dc ldr r0, [r0, r3, lsl #2] */
/* @0xf53e0 b 0xf516c <_ZN14CExtensionFile6AssignEPS_> */

/* ── FUNC 0xf53e4 · CExtensionPackage::SetCIncludes(int) · size=176 · insn=44 */
/* @0xf53e4 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0xf53e8 bic r7, r1, r1, asr #31 */
/* @0xf53ec ldr r3, [r0, #0x18] */
/* @0xf53f0 mov r4, r0 */
/* @0xf53f4 lsl r9, r7, #2 */
/* @0xf53f8 cmp r7, r3 */
/* @0xf53fc bge 0xf5434 <_ZN17CExtensionPackage12SetCIncludesEi+0x50> */
/* @0xf5400 mov r6, r7 */
/* @0xf5404 mov r8, #0 */
/* @0xf5408 mov r5, r9 */
/* @0xf540c ldr r3, [r4, #0x14] */
/* @0xf5410 add r6, r6, #1 */
/* @0xf5414 ldr r0, [r3, r5] */
/* @0xf5418 bl 0xf4f90 <_ZN14CExtensionFile4FreeEv> */
/* @0xf541c ldr r2, [r4, #0x18] */
/* @0xf5420 ldr r3, [r4, #0x14] */
/* @0xf5424 cmp r2, r6 */
/* @0xf5428 str r8, [r3, r5] */
/* @0xf542c add r5, r5, #4 */
/* @0xf5430 bgt 0xf540c <_ZN17CExtensionPackage12SetCIncludesEi+0x28> */
/* @0xf5434 ldr r2, [pc, #0x54] */
/* @0xf5438 mov r1, r9 */
/* @0xf543c add r0, r4, #20 */
/* @0xf5440 movw r3, #0x2a1 */
/* @0xf5444 add r2, pc, r2 */
/* @0xf5448 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0xf544c ldr r5, [r4, #0x18] */
/* @0xf5450 str r7, [r4, #0x10] */
/* @0xf5454 cmp r7, r5 */
/* @0xf5458 lslgt r6, r5, #2 */
/* @0xf545c ble 0xf5488 <_ZN17CExtensionPackage12SetCIncludesEi+0xa4> */
/* @0xf5460 mov r0, #44 */
/* @0xf5464 add r5, r5, #1 */
/* @0xf5468 bl 0x27c524 <_Znwj> */
/* @0xf546c mov r8, r0 */
/* @0xf5470 bl 0xf5098 <_ZN14CExtensionFileC2Ev> */
/* @0xf5474 ldr r3, [r4, #0x14] */
/* @0xf5478 cmp r5, r7 */
/* @0xf547c str r8, [r3, r6] */
/* @0xf5480 add r6, r6, #4 */
/* @0xf5484 bne 0xf5460 <_ZN17CExtensionPackage12SetCIncludesEi+0x7c> */
/* @0xf5488 str r7, [r4, #0x18] */
/* @0xf548c pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0xf5490 .word 0x002424d0 */

/* ── FUNC 0xf5494 · CExtensionPackage::FunctionFindName(char const*) · size=76 · insn=19 */
/* @0xf5494 ldr r3, [r0, #0x18] */
/* @0xf5498 push {r4, r5, r6, lr} */
/* @0xf549c cmp r3, #0 */
/* @0xf54a0 mov r5, r0 */
/* @0xf54a4 mov r6, r1 */
/* @0xf54a8 movgt r4, #0 */
/* @0xf54ac ble 0xf54d8 <_ZN17CExtensionPackage16FunctionFindNameEPKc+0x44> */
/* @0xf54b0 ldr r3, [r5, #0x14] */
/* @0xf54b4 mov r1, r6 */
/* @0xf54b8 ldr r0, [r3, r4, lsl #2] */
/* @0xf54bc add r4, r4, #1 */
/* @0xf54c0 bl 0xf4e84 <_ZN14CExtensionFile16FunctionFindNameEPKc> */
/* @0xf54c4 cmp r0, #0 */
/* @0xf54c8 popne {r4, r5, r6, pc} */
/* @0xf54cc ldr r3, [r5, #0x18] */
/* @0xf54d0 cmp r3, r4 */
/* @0xf54d4 bgt 0xf54b0 <_ZN17CExtensionPackage16FunctionFindNameEPKc+0x1c> */
/* @0xf54d8 mov r0, #0 */
/* @0xf54dc pop {r4, r5, r6, pc} */

/* ── FUNC 0xf54e0 · CExtensionPackage::FunctionFindId(int) · size=76 · insn=19 */
/* @0xf54e0 ldr r3, [r0, #0x18] */
/* @0xf54e4 push {r4, r5, r6, lr} */
/* @0xf54e8 cmp r3, #0 */
/* @0xf54ec mov r5, r0 */
/* @0xf54f0 mov r6, r1 */
/* @0xf54f4 movgt r4, #0 */
/* @0xf54f8 ble 0xf5524 <_ZN17CExtensionPackage14FunctionFindIdEi+0x44> */
/* @0xf54fc ldr r3, [r5, #0x14] */
/* @0xf5500 mov r1, r6 */
/* @0xf5504 ldr r0, [r3, r4, lsl #2] */
/* @0xf5508 add r4, r4, #1 */
/* @0xf550c bl 0xf4ee0 <_ZN14CExtensionFile14FunctionFindIdEi> */
/* @0xf5510 cmp r0, #0 */
/* @0xf5514 popne {r4, r5, r6, pc} */
/* @0xf5518 ldr r3, [r5, #0x18] */
/* @0xf551c cmp r3, r4 */
/* @0xf5520 bgt 0xf54fc <_ZN17CExtensionPackage14FunctionFindIdEi+0x1c> */
/* @0xf5524 mov r0, #0 */
/* @0xf5528 pop {r4, r5, r6, pc} */

/* ── FUNC 0xf552c · CExtensionPackage::ConstantFindName(char const*) · size=76 · insn=19 */
/* @0xf552c ldr r3, [r0, #0x18] */
/* @0xf5530 push {r4, r5, r6, lr} */
/* @0xf5534 cmp r3, #0 */
/* @0xf5538 mov r5, r0 */
/* @0xf553c mov r6, r1 */
/* @0xf5540 movgt r4, #0 */
/* @0xf5544 ble 0xf5570 <_ZN17CExtensionPackage16ConstantFindNameEPKc+0x44> */
/* @0xf5548 ldr r3, [r5, #0x14] */
/* @0xf554c mov r1, r6 */
/* @0xf5550 ldr r0, [r3, r4, lsl #2] */
/* @0xf5554 add r4, r4, #1 */
/* @0xf5558 bl 0xf4f34 <_ZN14CExtensionFile16ConstantFindNameEPKc> */
/* @0xf555c cmp r0, #0 */
/* @0xf5560 popne {r4, r5, r6, pc} */
/* @0xf5564 ldr r3, [r5, #0x18] */
/* @0xf5568 cmp r3, r4 */
/* @0xf556c bgt 0xf5548 <_ZN17CExtensionPackage16ConstantFindNameEPKc+0x1c> */
/* @0xf5570 mov r0, #0 */
/* @0xf5574 pop {r4, r5, r6, pc} */

/* ── FUNC 0xf5578 · CExtensionPackage::Free() · size=28 · insn=7 */
/* @0xf5578 push {r3, lr} */
/* @0xf557c subs r3, r0, #0 */
/* @0xf5580 popeq {r3, pc} */
/* @0xf5584 ldr r3, [r3] */
/* @0xf5588 ldr r3, [r3, #0x4] */
/* @0xf558c blx r3 */
/* @0xf5590 pop {r3, pc} */

/* ── FUNC 0xf5594 · CExtensionPackage::GetName() · size=8 · insn=2 */
/* @0xf5594 ldr r0, [r0, #0x4] */
/* @0xf5598 bx lr */

/* ── FUNC 0xf559c · CExtensionPackage::SetName(char const*) · size=44 · insn=11 */
/* @0xf559c push {r3, r4, r5, lr} */
/* @0xf55a0 mov r4, r0 */
/* @0xf55a4 ldr r0, [r0, #0x4] */
/* @0xf55a8 mov r5, r1 */
/* @0xf55ac cmp r0, #0 */
/* @0xf55b0 beq 0xf55b8 <_ZN17CExtensionPackage7SetNameEPKc+0x1c> */
/* @0xf55b4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xf55b8 mov r0, r5 */
/* @0xf55bc bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xf55c0 str r0, [r4, #0x4] */
/* @0xf55c4 pop {r3, r4, r5, pc} */

/* ── FUNC 0xf55c8 · CExtensionPackage::GetClassName() · size=8 · insn=2 */
/* @0xf55c8 ldr r0, [r0, #0xc] */
/* @0xf55cc bx lr */

/* ── FUNC 0xf55d0 · CExtensionPackage::SetClassName(char const*) · size=44 · insn=11 */
/* @0xf55d0 push {r3, r4, r5, lr} */
/* @0xf55d4 mov r4, r0 */
/* @0xf55d8 ldr r0, [r0, #0xc] */
/* @0xf55dc mov r5, r1 */
/* @0xf55e0 cmp r0, #0 */
/* @0xf55e4 beq 0xf55ec <_ZN17CExtensionPackage12SetClassNameEPKc+0x1c> */
/* @0xf55e8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xf55ec mov r0, r5 */
/* @0xf55f0 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xf55f4 str r0, [r4, #0xc] */
/* @0xf55f8 pop {r3, r4, r5, pc} */

/* ── FUNC 0xf55fc · CExtensionPackage::GetFolder() · size=8 · insn=2 */
/* @0xf55fc ldr r0, [r0, #0x8] */
/* @0xf5600 bx lr */

/* ── FUNC 0xf5604 · CExtensionPackage::SetFolder(char const*) · size=44 · insn=11 */
/* @0xf5604 push {r3, r4, r5, lr} */
/* @0xf5608 mov r4, r0 */
/* @0xf560c ldr r0, [r0, #0x8] */
/* @0xf5610 mov r5, r1 */
/* @0xf5614 cmp r0, #0 */
/* @0xf5618 beq 0xf5620 <_ZN17CExtensionPackage9SetFolderEPKc+0x1c> */
/* @0xf561c bl 0xcef90 <_Z6YYFreePKv> */
/* @0xf5620 mov r0, r5 */
/* @0xf5624 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xf5628 str r0, [r4, #0x8] */
/* @0xf562c pop {r3, r4, r5, pc} */

/* ── FUNC 0xf5630 · CExtensionPackage::GetIncludesCount() · size=8 · insn=2 */
/* @0xf5630 ldr r0, [r0, #0x18] */
/* @0xf5634 bx lr */

/* ── FUNC 0xf5638 · CExtensionPackage::SetIncludesCount(int) · size=4 · insn=1 */
/* @0xf5638 b 0xf53e4 <_ZN17CExtensionPackage12SetCIncludesEi> */

/* ── FUNC 0xf563c · CExtensionPackage::Clear() · size=140 · insn=35 */
/* @0xf563c push {r4, r5, r6, r7, lr} */
/* @0xf5640 mov r4, r0 */
/* @0xf5644 ldr r5, [pc, #0x74] */
/* @0xf5648 sub sp, sp, #268 */
/* @0xf564c mov r6, #0 */
/* @0xf5650 movw r0, #0x3e7 */
/* @0xf5654 ldr r5, [pc, r5] */
/* @0xf5658 str r6, [r4, #0x4] */
/* @0xf565c str r6, [r4, #0x8] */
/* @0xf5660 add r7, sp, #4 */
/* @0xf5664 ldr r3, [r5] */
/* @0xf5668 str r6, [r4, #0xc] */
/* @0xf566c str r3, [sp, #0x104] */
/* @0xf5670 bl 0xc4600 <_Z8YYRandomi> */
/* @0xf5674 ldr r2, [pc, #0x48] */
/* @0xf5678 mov r1, #256 */
/* @0xf567c add r2, pc, r2 */
/* @0xf5680 mov r3, r0 */
/* @0xf5684 mov r0, r7 */
/* @0xf5688 bl 0xb65c8 <snprintf@plt> */
/* @0xf568c mov r0, r7 */
/* @0xf5690 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xf5694 mov r1, r6 */
/* @0xf5698 str r0, [r4, #0x8] */
/* @0xf569c mov r0, r4 */
/* @0xf56a0 bl 0xf5638 <_ZN17CExtensionPackage16SetIncludesCountEi> */
/* @0xf56a4 ldr r2, [sp, #0x104] */
/* @0xf56a8 ldr r3, [r5] */
/* @0xf56ac cmp r2, r3 */
/* @0xf56b0 bne 0xf56bc <_ZN17CExtensionPackage5ClearEv+0x80> */
/* @0xf56b4 add sp, sp, #268 */
/* @0xf56b8 pop {r4, r5, r6, r7, pc} */
/* @0xf56bc bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0xf56c0 .word 0x002f82fc */
/* @0xf56c4 .word 0x002422d8 */

/* ── FUNC 0xf56c8 · CExtensionPackage::CExtensionPackage() · size=56 · insn=14 */
/* @0xf56c8 ldr r2, [pc, #0x2c] */
/* @0xf56cc mov r3, #0 */
/* @0xf56d0 push {r4, lr} */
/* @0xf56d4 ldr r2, [pc, r2] */
/* @0xf56d8 mov r4, r0 */
/* @0xf56dc str r3, [r0, #0x14] */
/* @0xf56e0 str r3, [r0, #0x10] */
/* @0xf56e4 add r2, r2, #8 */
/* @0xf56e8 str r3, [r0, #0x18] */
/* @0xf56ec str r2, [r0] */
/* @0xf56f0 bl 0xf563c <_ZN17CExtensionPackage5ClearEv> */
/* @0xf56f4 mov r0, r4 */
/* @0xf56f8 pop {r4, pc} */
/* @0xf56fc eoreq r8, pc, r12, asr r7 */

/* ── FUNC 0xf56c8 · CExtensionPackage::CExtensionPackage() · alias of the symbol above · insn=0 */

/* ── FUNC 0xf5700 · CExtensionPackage::~CExtensionPackage() · size=84 · insn=21 */
/* @0xf5700 push {r3, r4, r5, lr} */
/* @0xf5704 mov r4, r0 */
/* @0xf5708 ldr r3, [pc, #0x40] */
/* @0xf570c mov r5, #0 */
/* @0xf5710 ldr r0, [r0, #0x4] */
/* @0xf5714 ldr r3, [pc, r3] */
/* @0xf5718 add r3, r3, #8 */
/* @0xf571c str r3, [r4] */
/* @0xf5720 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xf5724 ldr r0, [r4, #0x8] */
/* @0xf5728 str r5, [r4, #0x4] */
/* @0xf572c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xf5730 ldr r0, [r4, #0xc] */
/* @0xf5734 str r5, [r4, #0x8] */
/* @0xf5738 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xf573c mov r0, r4 */
/* @0xf5740 str r5, [r4, #0xc] */
/* @0xf5744 bl 0xf563c <_ZN17CExtensionPackage5ClearEv> */
/* @0xf5748 mov r0, r4 */
/* @0xf574c pop {r3, r4, r5, pc} */
/* @0xf5750 eoreq r8, pc, r12, lsl r7 */

/* ── FUNC 0xf5700 · CExtensionPackage::~CExtensionPackage() · alias of the symbol above · insn=0 */

/* ── FUNC 0xf5754 · CExtensionPackage::~CExtensionPackage() · size=28 · insn=7 */
/* @0xf5754 push {r4, lr} */
/* @0xf5758 mov r4, r0 */
/* @0xf575c bl 0xf5700 <_ZN17CExtensionPackageD2Ev> */
/* @0xf5760 mov r0, r4 */
/* @0xf5764 bl 0x27d1d0 <_ZdlPv> */
/* @0xf5768 mov r0, r4 */
/* @0xf576c pop {r4, pc} */

/* ── FUNC 0xf5770 · CExtensionPackage::Assign(CExtensionPackage*) · size=144 · insn=36 */
/* @0xf5770 push {r4, r5, r6, lr} */
/* @0xf5774 mov r5, r0 */
/* @0xf5778 mov r6, r1 */
/* @0xf577c bl 0xf563c <_ZN17CExtensionPackage5ClearEv> */
/* @0xf5780 ldr r0, [r5, #0x4] */
/* @0xf5784 cmp r0, #0 */
/* @0xf5788 beq 0xf5790 <_ZN17CExtensionPackage6AssignEPS_+0x20> */
/* @0xf578c bl 0xcef90 <_Z6YYFreePKv> */
/* @0xf5790 ldr r0, [r6, #0x4] */
/* @0xf5794 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xf5798 ldr r3, [r5, #0x8] */
/* @0xf579c cmp r3, #0 */
/* @0xf57a0 str r0, [r5, #0x4] */
/* @0xf57a4 beq 0xf57b0 <_ZN17CExtensionPackage6AssignEPS_+0x40> */
/* @0xf57a8 mov r0, r3 */
/* @0xf57ac bl 0xcef90 <_Z6YYFreePKv> */
/* @0xf57b0 ldr r0, [r6, #0x8] */
/* @0xf57b4 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xf57b8 ldr r1, [r6, #0x18] */
/* @0xf57bc str r0, [r5, #0x8] */
/* @0xf57c0 mov r0, r5 */
/* @0xf57c4 bl 0xf5638 <_ZN17CExtensionPackage16SetIncludesCountEi> */
/* @0xf57c8 ldr r3, [r5, #0x18] */
/* @0xf57cc cmp r3, #0 */
/* @0xf57d0 pople {r4, r5, r6, pc} */
/* @0xf57d4 mov r4, #0 */
/* @0xf57d8 ldr r3, [r6, #0x14] */
/* @0xf57dc ldr r2, [r5, #0x14] */
/* @0xf57e0 ldr r1, [r3, r4, lsl #2] */
/* @0xf57e4 ldr r0, [r2, r4, lsl #2] */
/* @0xf57e8 add r4, r4, #1 */
/* @0xf57ec bl 0xf516c <_ZN14CExtensionFile6AssignEPS_> */
/* @0xf57f0 ldr r3, [r5, #0x18] */
/* @0xf57f4 cmp r3, r4 */
/* @0xf57f8 bgt 0xf57d8 <_ZN17CExtensionPackage6AssignEPS_+0x68> */
/* @0xf57fc pop {r4, r5, r6, pc} */

/* ── FUNC 0xf5800 · CExtensionPackage::GetIncludesFile(int) · size=4 · insn=1 */
/* @0xf5800 b 0xf5398 <_ZN17CExtensionPackage11GetIncludesEi> */

/* ── FUNC 0xf5804 · CExtensionPackage::SetIncludesFile(int, CExtensionFile*) · size=4 · insn=1 */
/* @0xf5804 b 0xf53c0 <_ZN17CExtensionPackage11SetIncludesEiP14CExtensionFile> */
