/* libyoyo.so 覆盖卡组 0021
 * 函数 0xf46fc..0xf4c30，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0xf46fc · CExtensionConstant::~CExtensionConstant() · size=84 · insn=21 */
/* @0xf46fc push {r4, lr} */
/* @0xf4700 mov r4, r0 */
/* @0xf4704 ldr r0, [r0, #0x4] */
/* @0xf4708 ldr r3, [pc, #0x3c] */
/* @0xf470c cmp r0, #0 */
/* @0xf4710 ldr r3, [pc, r3] */
/* @0xf4714 add r3, r3, #8 */
/* @0xf4718 str r3, [r4] */
/* @0xf471c beq 0xf472c <_ZN18CExtensionConstantD2Ev+0x30> */
/* @0xf4720 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xf4724 mov r3, #0 */
/* @0xf4728 str r3, [r4, #0x4] */
/* @0xf472c ldr r0, [r4, #0x8] */
/* @0xf4730 cmp r0, #0 */
/* @0xf4734 beq 0xf4744 <_ZN18CExtensionConstantD2Ev+0x48> */
/* @0xf4738 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xf473c mov r3, #0 */
/* @0xf4740 str r3, [r4, #0x8] */
/* @0xf4744 mov r0, r4 */
/* @0xf4748 pop {r4, pc} */
/* @0xf474c eoreq r9, pc, r4, lsl r7 */

/* ── FUNC 0xf46fc · CExtensionConstant::~CExtensionConstant() · alias of the symbol above · insn=0 */

/* ── FUNC 0xf4750 · CExtensionConstant::~CExtensionConstant() · size=28 · insn=7 */
/* @0xf4750 push {r4, lr} */
/* @0xf4754 mov r4, r0 */
/* @0xf4758 bl 0xf46fc <_ZN18CExtensionConstantD2Ev> */
/* @0xf475c mov r0, r4 */
/* @0xf4760 bl 0x27d1d0 <_ZdlPv> */
/* @0xf4764 mov r0, r4 */
/* @0xf4768 pop {r4, pc} */

/* ── FUNC 0xf476c · CExtensionFunction::~CExtensionFunction() · size=108 · insn=27 */
/* @0xf476c push {r4, lr} */
/* @0xf4770 mov r4, r0 */
/* @0xf4774 ldr r0, [r0, #0x4] */
/* @0xf4778 ldr r3, [pc, #0x54] */
/* @0xf477c cmp r0, #0 */
/* @0xf4780 ldr r3, [pc, r3] */
/* @0xf4784 add r3, r3, #8 */
/* @0xf4788 str r3, [r4] */
/* @0xf478c beq 0xf479c <_ZN18CExtensionFunctionD2Ev+0x30> */
/* @0xf4790 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xf4794 mov r3, #0 */
/* @0xf4798 str r3, [r4, #0x4] */
/* @0xf479c ldr r0, [r4, #0x8] */
/* @0xf47a0 cmp r0, #0 */
/* @0xf47a4 beq 0xf47b4 <_ZN18CExtensionFunctionD2Ev+0x48> */
/* @0xf47a8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xf47ac mov r3, #0 */
/* @0xf47b0 str r3, [r4, #0x8] */
/* @0xf47b4 ldr r0, [r4, #0x5c] */
/* @0xf47b8 cmp r0, #0 */
/* @0xf47bc beq 0xf47cc <_ZN18CExtensionFunctionD2Ev+0x60> */
/* @0xf47c0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xf47c4 mov r3, #0 */
/* @0xf47c8 str r3, [r4, #0x5c] */
/* @0xf47cc mov r0, r4 */
/* @0xf47d0 pop {r4, pc} */
/* @0xf47d4 eoreq r9, pc, r8, lsr #13 */

/* ── FUNC 0xf476c · CExtensionFunction::~CExtensionFunction() · alias of the symbol above · insn=0 */

/* ── FUNC 0xf47d8 · CExtensionFunction::~CExtensionFunction() · size=28 · insn=7 */
/* @0xf47d8 push {r4, lr} */
/* @0xf47dc mov r4, r0 */
/* @0xf47e0 bl 0xf476c <_ZN18CExtensionFunctionD2Ev> */
/* @0xf47e4 mov r0, r4 */
/* @0xf47e8 bl 0x27d1d0 <_ZdlPv> */
/* @0xf47ec mov r0, r4 */
/* @0xf47f0 pop {r4, pc} */

/* ── FUNC 0xf47f4 · CExtensionConstant::Clear() · size=16 · insn=4 */
/* @0xf47f4 mov r3, #0 */
/* @0xf47f8 str r3, [r0, #0x4] */
/* @0xf47fc str r3, [r0, #0x8] */
/* @0xf4800 bx lr */

/* ── FUNC 0xf4804 · CExtensionConstant::CExtensionConstant() · size=40 · insn=10 */
/* @0xf4804 ldr r3, [pc, #0x1c] */
/* @0xf4808 push {r4, lr} */
/* @0xf480c ldr r3, [pc, r3] */
/* @0xf4810 mov r4, r0 */
/* @0xf4814 add r3, r3, #8 */
/* @0xf4818 str r3, [r0] */
/* @0xf481c bl 0xf47f4 <_ZN18CExtensionConstant5ClearEv> */
/* @0xf4820 mov r0, r4 */
/* @0xf4824 pop {r4, pc} */
/* @0xf4828 eoreq r9, pc, r8, lsl r6 */

/* ── FUNC 0xf4804 · CExtensionConstant::CExtensionConstant() · alias of the symbol above · insn=0 */

/* ── FUNC 0xf482c · CExtensionConstant::Assign(CExtensionConstant*) · size=76 · insn=19 */
/* @0xf482c push {r3, r4, r5, lr} */
/* @0xf4830 mov r4, r0 */
/* @0xf4834 ldr r0, [r0, #0x4] */
/* @0xf4838 mov r5, r1 */
/* @0xf483c cmp r0, #0 */
/* @0xf4840 beq 0xf4848 <_ZN18CExtensionConstant6AssignEPS_+0x1c> */
/* @0xf4844 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xf4848 ldr r0, [r5, #0x4] */
/* @0xf484c bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xf4850 ldr r3, [r4, #0x8] */
/* @0xf4854 cmp r3, #0 */
/* @0xf4858 str r0, [r4, #0x4] */
/* @0xf485c beq 0xf4868 <_ZN18CExtensionConstant6AssignEPS_+0x3c> */
/* @0xf4860 mov r0, r3 */
/* @0xf4864 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xf4868 ldr r0, [r5, #0x8] */
/* @0xf486c bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xf4870 str r0, [r4, #0x8] */
/* @0xf4874 pop {r3, r4, r5, pc} */

/* ── FUNC 0xf4878 · CExtensionConstant::LoadFromExeStream(CStream*) · size=120 · insn=30 */
/* @0xf4878 push {r3, r4, r5, lr} */
/* @0xf487c mov r5, r1 */
/* @0xf4880 mov r4, r0 */
/* @0xf4884 bl 0xf47f4 <_ZN18CExtensionConstant5ClearEv> */
/* @0xf4888 mov r0, r5 */
/* @0xf488c bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0xf4890 cmp r0, #700 */
/* @0xf4894 beq 0xf48a0 <_ZN18CExtensionConstant17LoadFromExeStreamEP7CStream+0x28> */
/* @0xf4898 mov r0, #0 */
/* @0xf489c pop {r3, r4, r5, pc} */
/* @0xf48a0 ldr r0, [r4, #0x4] */
/* @0xf48a4 cmp r0, #0 */
/* @0xf48a8 beq 0xf48b8 <_ZN18CExtensionConstant17LoadFromExeStreamEP7CStream+0x40> */
/* @0xf48ac bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xf48b0 mov r3, #0 */
/* @0xf48b4 str r3, [r4, #0x4] */
/* @0xf48b8 mov r0, r5 */
/* @0xf48bc add r1, r4, #4 */
/* @0xf48c0 bl 0x2018e8 <_ZN7CStream10ReadStringERPKc> */
/* @0xf48c4 ldr r0, [r4, #0x8] */
/* @0xf48c8 cmp r0, #0 */
/* @0xf48cc beq 0xf48dc <_ZN18CExtensionConstant17LoadFromExeStreamEP7CStream+0x64> */
/* @0xf48d0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xf48d4 mov r3, #0 */
/* @0xf48d8 str r3, [r4, #0x8] */
/* @0xf48dc mov r0, r5 */
/* @0xf48e0 add r1, r4, #8 */
/* @0xf48e4 bl 0x2018e8 <_ZN7CStream10ReadStringERPKc> */
/* @0xf48e8 mov r0, #1 */
/* @0xf48ec pop {r3, r4, r5, pc} */

/* ── FUNC 0xf48f0 · CExtensionConstant::Free() · size=28 · insn=7 */
/* @0xf48f0 push {r3, lr} */
/* @0xf48f4 subs r3, r0, #0 */
/* @0xf48f8 popeq {r3, pc} */
/* @0xf48fc ldr r3, [r3] */
/* @0xf4900 ldr r3, [r3, #0x4] */
/* @0xf4904 blx r3 */
/* @0xf4908 pop {r3, pc} */

/* ── FUNC 0xf490c · CExtensionConstant::GetName() · size=8 · insn=2 */
/* @0xf490c ldr r0, [r0, #0x4] */
/* @0xf4910 bx lr */

/* ── FUNC 0xf4914 · CExtensionConstant::Setname(char const*) · size=44 · insn=11 */
/* @0xf4914 push {r3, r4, r5, lr} */
/* @0xf4918 mov r4, r0 */
/* @0xf491c ldr r0, [r0, #0x4] */
/* @0xf4920 mov r5, r1 */
/* @0xf4924 cmp r0, #0 */
/* @0xf4928 beq 0xf4930 <_ZN18CExtensionConstant7SetnameEPKc+0x1c> */
/* @0xf492c bl 0xcef90 <_Z6YYFreePKv> */
/* @0xf4930 mov r0, r5 */
/* @0xf4934 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xf4938 str r0, [r4, #0x4] */
/* @0xf493c pop {r3, r4, r5, pc} */

/* ── FUNC 0xf4940 · CExtensionConstant::GetValue() · size=8 · insn=2 */
/* @0xf4940 ldr r0, [r0, #0x8] */
/* @0xf4944 bx lr */

/* ── FUNC 0xf4948 · CExtensionConstant::SetValue(char const*) · size=44 · insn=11 */
/* @0xf4948 push {r3, r4, r5, lr} */
/* @0xf494c mov r4, r0 */
/* @0xf4950 ldr r0, [r0, #0x8] */
/* @0xf4954 mov r5, r1 */
/* @0xf4958 cmp r0, #0 */
/* @0xf495c beq 0xf4964 <_ZN18CExtensionConstant8SetValueEPKc+0x1c> */
/* @0xf4960 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xf4964 mov r0, r5 */
/* @0xf4968 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xf496c str r0, [r4, #0x8] */
/* @0xf4970 pop {r3, r4, r5, pc} */

/* ── FUNC 0xf4974 · CExtensionFunction::GetArgType(int) · size=20 · insn=5 */
/* @0xf4974 cmp r1, #15 */
/* @0xf4978 addls r1, r1, #6 */
/* @0xf497c ldrls r0, [r0, r1, lsl #2] */
/* @0xf4980 movhi r0, #2 */
/* @0xf4984 bx lr */

/* ── FUNC 0xf4988 · CExtensionFunction::SetArgType(int, int) · size=16 · insn=4 */
/* @0xf4988 cmp r1, #15 */
/* @0xf498c addls r1, r1, #6 */
/* @0xf4990 strls r2, [r0, r1, lsl #2] */
/* @0xf4994 bx lr */

/* ── FUNC 0xf4998 · CExtensionFunction::Clear() · size=76 · insn=19 */
/* @0xf4998 mov r3, #16 */
/* @0xf499c mov r2, r0 */
/* @0xf49a0 mov r12, #2 */
/* @0xf49a4 mov r1, #0 */
/* @0xf49a8 str r4, [sp, #-0x4]! */
/* @0xf49ac mvn r4, #0 */
/* @0xf49b0 str r1, [r0, #0x4] */
/* @0xf49b4 str r4, [r0, #0x14] */
/* @0xf49b8 str r1, [r0, #0x8] */
/* @0xf49bc str r1, [r0, #0xc] */
/* @0xf49c0 subs r3, r3, #1 */
/* @0xf49c4 str r12, [r2, #0x18] */
/* @0xf49c8 mov r1, #2 */
/* @0xf49cc add r2, r2, #4 */
/* @0xf49d0 bne 0xf49c0 <_ZN18CExtensionFunction5ClearEv+0x28> */
/* @0xf49d4 str r1, [r0, #0x58] */
/* @0xf49d8 str r3, [r0, #0x5c] */
/* @0xf49dc ldr r4, [sp], #4 */
/* @0xf49e0 bx lr */

/* ── FUNC 0xf49e4 · CExtensionFunction::CExtensionFunction() · size=40 · insn=10 */
/* @0xf49e4 ldr r3, [pc, #0x1c] */
/* @0xf49e8 push {r4, lr} */
/* @0xf49ec ldr r3, [pc, r3] */
/* @0xf49f0 mov r4, r0 */
/* @0xf49f4 add r3, r3, #8 */
/* @0xf49f8 str r3, [r0] */
/* @0xf49fc bl 0xf4998 <_ZN18CExtensionFunction5ClearEv> */
/* @0xf4a00 mov r0, r4 */
/* @0xf4a04 pop {r4, pc} */
/* @0xf4a08 eoreq r9, pc, r12, lsr r4 */

/* ── FUNC 0xf49e4 · CExtensionFunction::CExtensionFunction() · alias of the symbol above · insn=0 */

/* ── FUNC 0xf4a0c · CExtensionFunction::Assign(CExtensionFunction*) · size=172 · insn=43 */
/* @0xf4a0c push {r4, r5, r6, lr} */
/* @0xf4a10 mov r4, r0 */
/* @0xf4a14 ldr r0, [r0, #0x4] */
/* @0xf4a18 mov r5, r1 */
/* @0xf4a1c cmp r0, #0 */
/* @0xf4a20 beq 0xf4a28 <_ZN18CExtensionFunction6AssignEPS_+0x1c> */
/* @0xf4a24 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xf4a28 ldr r0, [r5, #0x4] */
/* @0xf4a2c bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xf4a30 ldr r3, [r4, #0x8] */
/* @0xf4a34 cmp r3, #0 */
/* @0xf4a38 str r0, [r4, #0x4] */
/* @0xf4a3c beq 0xf4a48 <_ZN18CExtensionFunction6AssignEPS_+0x3c> */
/* @0xf4a40 mov r0, r3 */
/* @0xf4a44 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xf4a48 ldr r0, [r5, #0x8] */
/* @0xf4a4c bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xf4a50 ldr r6, [r5, #0xc] */
/* @0xf4a54 ldr lr, [r5, #0x10] */
/* @0xf4a58 mov r12, r5 */
/* @0xf4a5c ldr r1, [r5, #0x14] */
/* @0xf4a60 mov r2, r4 */
/* @0xf4a64 mov r3, #16 */
/* @0xf4a68 str r6, [r4, #0xc] */
/* @0xf4a6c str lr, [r4, #0x10] */
/* @0xf4a70 str r1, [r4, #0x14] */
/* @0xf4a74 str r0, [r4, #0x8] */
/* @0xf4a78 ldr lr, [r12, #0x18] */
/* @0xf4a7c subs r3, r3, #1 */
/* @0xf4a80 add r12, r12, #4 */
/* @0xf4a84 add r2, r2, #4 */
/* @0xf4a88 str lr, [r2, #0x14] */
/* @0xf4a8c bne 0xf4a78 <_ZN18CExtensionFunction6AssignEPS_+0x6c> */
/* @0xf4a90 ldr r0, [r4, #0x5c] */
/* @0xf4a94 ldr r3, [r5, #0x58] */
/* @0xf4a98 cmp r0, #0 */
/* @0xf4a9c str r3, [r4, #0x58] */
/* @0xf4aa0 beq 0xf4aa8 <_ZN18CExtensionFunction6AssignEPS_+0x9c> */
/* @0xf4aa4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xf4aa8 ldr r0, [r5, #0x5c] */
/* @0xf4aac bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xf4ab0 str r0, [r4, #0x5c] */
/* @0xf4ab4 pop {r4, r5, r6, pc} */

/* ── FUNC 0xf4ab8 · CExtensionFunction::LoadFromExeStream(CStream*) · size=220 · insn=55 */
/* @0xf4ab8 push {r3, r4, r5, r6, r7, lr} */
/* @0xf4abc mov r6, r1 */
/* @0xf4ac0 mov r7, r0 */
/* @0xf4ac4 bl 0xf4998 <_ZN18CExtensionFunction5ClearEv> */
/* @0xf4ac8 mov r0, r6 */
/* @0xf4acc bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0xf4ad0 cmp r0, #700 */
/* @0xf4ad4 beq 0xf4ae0 <_ZN18CExtensionFunction17LoadFromExeStreamEP7CStream+0x28> */
/* @0xf4ad8 mov r0, #0 */
/* @0xf4adc pop {r3, r4, r5, r6, r7, pc} */
/* @0xf4ae0 ldr r0, [r7, #0x4] */
/* @0xf4ae4 cmp r0, #0 */
/* @0xf4ae8 beq 0xf4af8 <_ZN18CExtensionFunction17LoadFromExeStreamEP7CStream+0x40> */
/* @0xf4aec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xf4af0 mov r3, #0 */
/* @0xf4af4 str r3, [r7, #0x4] */
/* @0xf4af8 mov r0, r6 */
/* @0xf4afc add r1, r7, #4 */
/* @0xf4b00 bl 0x2018e8 <_ZN7CStream10ReadStringERPKc> */
/* @0xf4b04 ldr r0, [r7, #0x8] */
/* @0xf4b08 cmp r0, #0 */
/* @0xf4b0c beq 0xf4b1c <_ZN18CExtensionFunction17LoadFromExeStreamEP7CStream+0x64> */
/* @0xf4b10 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xf4b14 mov r3, #0 */
/* @0xf4b18 str r3, [r7, #0x8] */
/* @0xf4b1c add r1, r7, #8 */
/* @0xf4b20 mov r0, r6 */
/* @0xf4b24 bl 0x2018e8 <_ZN7CStream10ReadStringERPKc> */
/* @0xf4b28 mov r0, r6 */
/* @0xf4b2c bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0xf4b30 mov r5, r7 */
/* @0xf4b34 mov r4, #16 */
/* @0xf4b38 str r0, [r7, #0xc] */
/* @0xf4b3c mov r0, r6 */
/* @0xf4b40 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0xf4b44 str r0, [r7, #0x10] */
/* @0xf4b48 mov r0, r6 */
/* @0xf4b4c bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0xf4b50 str r0, [r7, #0x14] */
/* @0xf4b54 mov r0, r6 */
/* @0xf4b58 add r5, r5, #4 */
/* @0xf4b5c bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0xf4b60 subs r4, r4, #1 */
/* @0xf4b64 str r0, [r5, #0x14] */
/* @0xf4b68 bne 0xf4b54 <_ZN18CExtensionFunction17LoadFromExeStreamEP7CStream+0x9c> */
/* @0xf4b6c mov r0, r6 */
/* @0xf4b70 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0xf4b74 sub r3, r0, #1 */
/* @0xf4b78 cmp r3, #1 */
/* @0xf4b7c strls r0, [r7, #0x58] */
/* @0xf4b80 movhi r3, #2 */
/* @0xf4b84 movls r0, #1 */
/* @0xf4b88 strhi r3, [r7, #0x58] */
/* @0xf4b8c movhi r0, #1 */
/* @0xf4b90 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0xf4b94 · CExtensionFunction::Free() · size=28 · insn=7 */
/* @0xf4b94 push {r3, lr} */
/* @0xf4b98 subs r3, r0, #0 */
/* @0xf4b9c popeq {r3, pc} */
/* @0xf4ba0 ldr r3, [r3] */
/* @0xf4ba4 ldr r3, [r3, #0x4] */
/* @0xf4ba8 blx r3 */
/* @0xf4bac pop {r3, pc} */

/* ── FUNC 0xf4bb0 · CExtensionFunction::GetName() · size=8 · insn=2 */
/* @0xf4bb0 ldr r0, [r0, #0x4] */
/* @0xf4bb4 bx lr */

/* ── FUNC 0xf4bb8 · CExtensionFunction::SetName(char const*) · size=44 · insn=11 */
/* @0xf4bb8 push {r3, r4, r5, lr} */
/* @0xf4bbc mov r4, r0 */
/* @0xf4bc0 ldr r0, [r0, #0x4] */
/* @0xf4bc4 mov r5, r1 */
/* @0xf4bc8 cmp r0, #0 */
/* @0xf4bcc beq 0xf4bd4 <_ZN18CExtensionFunction7SetNameEPKc+0x1c> */
/* @0xf4bd0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xf4bd4 mov r0, r5 */
/* @0xf4bd8 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xf4bdc str r0, [r4, #0x4] */
/* @0xf4be0 pop {r3, r4, r5, pc} */

/* ── FUNC 0xf4be4 · CExtensionFunction::GetExternalName() · size=8 · insn=2 */
/* @0xf4be4 ldr r0, [r0, #0x8] */
/* @0xf4be8 bx lr */

/* ── FUNC 0xf4bec · CExtensionFunction::SetExternalName(char const*) · size=44 · insn=11 */
/* @0xf4bec push {r3, r4, r5, lr} */
/* @0xf4bf0 mov r4, r0 */
/* @0xf4bf4 ldr r0, [r0, #0x8] */
/* @0xf4bf8 mov r5, r1 */
/* @0xf4bfc cmp r0, #0 */
/* @0xf4c00 beq 0xf4c08 <_ZN18CExtensionFunction15SetExternalNameEPKc+0x1c> */
/* @0xf4c04 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xf4c08 mov r0, r5 */
/* @0xf4c0c bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xf4c10 str r0, [r4, #0x8] */
/* @0xf4c14 pop {r3, r4, r5, pc} */

/* ── FUNC 0xf4c18 · CExtensionFunction::GetKind() · size=8 · insn=2 */
/* @0xf4c18 ldr r0, [r0, #0xc] */
/* @0xf4c1c bx lr */

/* ── FUNC 0xf4c20 · CExtensionFunction::SetKind(int) · size=8 · insn=2 */
/* @0xf4c20 str r1, [r0, #0xc] */
/* @0xf4c24 bx lr */

/* ── FUNC 0xf4c28 · CExtensionFunction::GetId() · size=8 · insn=2 */
/* @0xf4c28 ldr r0, [r0, #0x10] */
/* @0xf4c2c bx lr */

/* ── FUNC 0xf4c30 · CExtensionFunction::SetId(int) · size=8 · insn=2 */
/* @0xf4c30 str r1, [r0, #0x10] */
/* @0xf4c34 bx lr */
