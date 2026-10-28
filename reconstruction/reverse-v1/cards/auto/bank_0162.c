/* libyoyo.so 覆盖卡组 0162
 * 函数 0x1dfb8c..0x1e1100，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1dfb8c · CScript::Free() · size=28 · insn=7 */
/* @0x1dfb8c push {r3, lr} */
/* @0x1dfb90 subs r3, r0, #0 */
/* @0x1dfb94 popeq {r3, pc} */
/* @0x1dfb98 ldr r3, [r3] */
/* @0x1dfb9c ldr r3, [r3, #0x4] */
/* @0x1dfba0 blx r3 */
/* @0x1dfba4 pop {r3, pc} */

/* ── FUNC 0x1dfba8 · CScript::GetCode() · size=8 · insn=2 */
/* @0x1dfba8 ldr r0, [r0, #0x8] */
/* @0x1dfbac bx lr */

/* ── FUNC 0x1dfbb0 · CScript::Clear() · size=84 · insn=21 */
/* @0x1dfbb0 push {r3, r4, r5, lr} */
/* @0x1dfbb4 mov r4, r0 */
/* @0x1dfbb8 ldr r5, [r0, #0x4] */
/* @0x1dfbbc cmp r5, #0 */
/* @0x1dfbc0 beq 0x1dfbd4 <_ZN7CScript5ClearEv+0x24> */
/* @0x1dfbc4 mov r0, r5 */
/* @0x1dfbc8 bl 0x201328 <_ZN7CStreamD2Ev> */
/* @0x1dfbcc mov r0, r5 */
/* @0x1dfbd0 bl 0x27d1d0 <_ZdlPv> */
/* @0x1dfbd4 ldr r0, [r4, #0x8] */
/* @0x1dfbd8 cmp r0, #0 */
/* @0x1dfbdc beq 0x1dfbec <_ZN7CScript5ClearEv+0x3c> */
/* @0x1dfbe0 ldr r3, [r0] */
/* @0x1dfbe4 ldr r3, [r3, #0x4] */
/* @0x1dfbe8 blx r3 */
/* @0x1dfbec mov r3, #0 */
/* @0x1dfbf0 str r3, [r4, #0x8] */
/* @0x1dfbf4 str r3, [r4, #0x4] */
/* @0x1dfbf8 str r3, [r4, #0x10] */
/* @0x1dfbfc str r3, [r4, #0x18] */
/* @0x1dfc00 pop {r3, r4, r5, pc} */

/* ── FUNC 0x1dfc04 · CScript::CScript(char const*) · size=64 · insn=16 */
/* @0x1dfc04 ldr r2, [pc, #0x34] */
/* @0x1dfc08 mov r3, #0 */
/* @0x1dfc0c push {r4, lr} */
/* @0x1dfc10 ldr r2, [pc, r2] */
/* @0x1dfc14 mov r4, r0 */
/* @0x1dfc18 str r1, [r0, #0x14] */
/* @0x1dfc1c str r3, [r0, #0x4] */
/* @0x1dfc20 add r2, r2, #8 */
/* @0x1dfc24 str r3, [r0, #0x8] */
/* @0x1dfc28 str r2, [r0] */
/* @0x1dfc2c str r3, [r0, #0x10] */
/* @0x1dfc30 str r3, [r0, #0x18] */
/* @0x1dfc34 bl 0x1dfbb0 <_ZN7CScript5ClearEv> */
/* @0x1dfc38 mov r0, r4 */
/* @0x1dfc3c pop {r4, pc} */
/* @0x1dfc40 eoreq r1, r1, r4, lsl r1 */

/* ── FUNC 0x1dfc04 · CScript::CScript(char const*) · alias of the symbol above · insn=0 */

/* ── FUNC 0x1dfc44 · CScript::~CScript() · size=40 · insn=10 */
/* @0x1dfc44 ldr r3, [pc, #0x1c] */
/* @0x1dfc48 push {r4, lr} */
/* @0x1dfc4c ldr r3, [pc, r3] */
/* @0x1dfc50 mov r4, r0 */
/* @0x1dfc54 add r3, r3, #8 */
/* @0x1dfc58 str r3, [r0] */
/* @0x1dfc5c bl 0x1dfbb0 <_ZN7CScript5ClearEv> */
/* @0x1dfc60 mov r0, r4 */
/* @0x1dfc64 pop {r4, pc} */
/* @0x1dfc68 .word 0x002110d8 */

/* ── FUNC 0x1dfc44 · CScript::~CScript() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1dfc6c · CScript::~CScript() · size=28 · insn=7 */
/* @0x1dfc6c push {r4, lr} */
/* @0x1dfc70 mov r4, r0 */
/* @0x1dfc74 bl 0x1dfc44 <_ZN7CScriptD2Ev> */
/* @0x1dfc78 mov r0, r4 */
/* @0x1dfc7c bl 0x27d1d0 <_ZdlPv> */
/* @0x1dfc80 mov r0, r4 */
/* @0x1dfc84 pop {r4, pc} */

/* ── FUNC 0x1dfc88 · CScript::LoadFromStream(CStream*) · size=180 · insn=45 */
/* @0x1dfc88 push {r4, r5, r6, r7, lr} */
/* @0x1dfc8c mov r5, r1 */
/* @0x1dfc90 sub sp, sp, #12 */
/* @0x1dfc94 mov r6, r0 */
/* @0x1dfc98 bl 0x1dfbb0 <_ZN7CScript5ClearEv> */
/* @0x1dfc9c mov r0, r5 */
/* @0x1dfca0 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1dfca4 cmp r0, #400 */
/* @0x1dfca8 mov r4, r0 */
/* @0x1dfcac beq 0x1dfce0 <_ZN7CScript14LoadFromStreamEP7CStream+0x58> */
/* @0x1dfcb0 cmp r0, #800 */
/* @0x1dfcb4 beq 0x1dfcd0 <_ZN7CScript14LoadFromStreamEP7CStream+0x48> */
/* @0x1dfcb8 cmp r4, #400 */
/* @0x1dfcbc cmpne r4, #800 */
/* @0x1dfcc0 movne r0, #0 */
/* @0x1dfcc4 moveq r0, #1 */
/* @0x1dfcc8 add sp, sp, #12 */
/* @0x1dfccc pop {r4, r5, r6, r7, pc} */
/* @0x1dfcd0 mov r0, r5 */
/* @0x1dfcd4 bl 0x201950 <_ZN7CStream10ReadStringEv> */
/* @0x1dfcd8 str r0, [r6, #0x10] */
/* @0x1dfcdc b 0x1dfcb8 <_ZN7CScript14LoadFromStreamEP7CStream+0x30> */
/* @0x1dfce0 mov r0, r5 */
/* @0x1dfce4 bl 0x201db0 <_ZN7CStream20ReadCompressedStreamEv> */
/* @0x1dfce8 mov r5, r0 */
/* @0x1dfcec mov r0, #32 */
/* @0x1dfcf0 bl 0x27c524 <_Znwj> */
/* @0x1dfcf4 mov r1, #0 */
/* @0x1dfcf8 mov r7, r0 */
/* @0x1dfcfc bl 0x2010ec <_ZN7CStreamC2Ei> */
/* @0x1dfd00 str r7, [r6, #0x4] */
/* @0x1dfd04 mov r12, #1 */
/* @0x1dfd08 mov r0, r7 */
/* @0x1dfd0c mov r1, r5 */
/* @0x1dfd10 mov r2, #0 */
/* @0x1dfd14 mov r3, #0 */
/* @0x1dfd18 str r12, [sp] */
/* @0x1dfd1c bl 0x2015c8 <_ZN7CStream8CopyFromEPS_xb> */
/* @0x1dfd20 cmp r5, #0 */
/* @0x1dfd24 beq 0x1dfcb8 <_ZN7CScript14LoadFromStreamEP7CStream+0x30> */
/* @0x1dfd28 mov r0, r5 */
/* @0x1dfd2c bl 0x201328 <_ZN7CStreamD2Ev> */
/* @0x1dfd30 mov r0, r5 */
/* @0x1dfd34 bl 0x27d1d0 <_ZdlPv> */
/* @0x1dfd38 b 0x1dfcb8 <_ZN7CScript14LoadFromStreamEP7CStream+0x30> */

/* ── FUNC 0x1dfd3c · CScript::LoadFromChunk(YYScript*, unsigned char*) · size=212 · insn=53 */
/* @0x1dfd3c ldr r3, [r1] */
/* @0x1dfd40 push {r4, r5, r6, lr} */
/* @0x1dfd44 cmp r3, #0 */
/* @0x1dfd48 ldr r4, [pc, #0xac] */
/* @0x1dfd4c mov r6, r1 */
/* @0x1dfd50 mov r5, r0 */
/* @0x1dfd54 add r4, pc, r4 */
/* @0x1dfd58 ldrne r2, [pc, #0xa0] */
/* @0x1dfd5c ldrne r2, [r4, r2] */
/* @0x1dfd60 ldrne r2, [r2] */
/* @0x1dfd64 addne r3, r2, r3 */
/* @0x1dfd68 str r3, [r5, #0x14] */
/* @0x1dfd6c mov r0, r5 */
/* @0x1dfd70 bl 0x1dfbb0 <_ZN7CScript5ClearEv> */
/* @0x1dfd74 ldr r3, [pc, #0x88] */
/* @0x1dfd78 ldr r3, [r4, r3] */
/* @0x1dfd7c ldrb r3, [r3] */
/* @0x1dfd80 cmp r3, #0 */
/* @0x1dfd84 bne 0x1dfdec <_ZN7CScript13LoadFromChunkEP8YYScriptPh+0xb0> */
/* @0x1dfd88 ldr r3, [pc, #0x78] */
/* @0x1dfd8c ldr r3, [r4, r3] */
/* @0x1dfd90 ldrb r3, [r3] */
/* @0x1dfd94 cmp r3, #0 */
/* @0x1dfd98 bne 0x1dfdec <_ZN7CScript13LoadFromChunkEP8YYScriptPh+0xb0> */
/* @0x1dfd9c ldr r3, [r6, #0x4] */
/* @0x1dfda0 cmp r3, #0 */
/* @0x1dfda4 moveq r4, r3 */
/* @0x1dfda8 ldrne r2, [pc, #0x50] */
/* @0x1dfdac ldrne r2, [r4, r2] */
/* @0x1dfdb0 ldrne r4, [r2] */
/* @0x1dfdb4 addne r4, r4, r3 */
/* @0x1dfdb8 mov r0, r4 */
/* @0x1dfdbc bl 0xb6538 <strlen@plt> */
/* @0x1dfdc0 ldr r1, [pc, #0x44] */
/* @0x1dfdc4 mov r3, #1 */
/* @0x1dfdc8 mov r2, #155 */
/* @0x1dfdcc add r1, pc, r1 */
/* @0x1dfdd0 add r0, r0, r3 */
/* @0x1dfdd4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1dfdd8 mov r1, r4 */
/* @0x1dfddc str r0, [r5, #0x10] */
/* @0x1dfde0 bl 0xb65a4 <strcpy@plt> */
/* @0x1dfde4 mov r0, #1 */
/* @0x1dfde8 pop {r4, r5, r6, pc} */
/* @0x1dfdec ldr r3, [r6, #0x4] */
/* @0x1dfdf0 mov r0, #1 */
/* @0x1dfdf4 str r3, [r5, #0x10] */
/* @0x1dfdf8 pop {r4, r5, r6, pc} */
/* @0x1dfdfc .word 0x00211efc */
/* @0x1dfe00 .word 0xffffbcf4 */
/* @0x1dfe04 .word 0xffffbf10 */
/* @0x1dfe08 .word 0xffffbecc */
/* @0x1dfe0c andseq r1, r7, r0, lsl #30 */

/* ── FUNC 0x1dfe10 · CScript::Compile() · size=132 · insn=33 */
/* @0x1dfe10 ldr r3, [pc, #0x70] */
/* @0x1dfe14 push {r4, r5, r6, lr} */
/* @0x1dfe18 ldr r3, [pc, r3] */
/* @0x1dfe1c mov r4, r0 */
/* @0x1dfe20 ldrb r5, [r3] */
/* @0x1dfe24 cmp r5, #0 */
/* @0x1dfe28 bne 0x1dfe64 <_ZN7CScript7CompileEv+0x54> */
/* @0x1dfe2c ldr r3, [pc, #0x58] */
/* @0x1dfe30 ldr r3, [pc, r3] */
/* @0x1dfe34 ldr r0, [r3] */
/* @0x1dfe38 cmp r0, #0 */
/* @0x1dfe3c popeq {r4, r5, r6, pc} */
/* @0x1dfe40 mov r0, #124 */
/* @0x1dfe44 bl 0x27c524 <_Znwj> */
/* @0x1dfe48 mov r2, r5 */
/* @0x1dfe4c ldr r1, [r4, #0x10] */
/* @0x1dfe50 mov r6, r0 */
/* @0x1dfe54 bl 0xcefc8 <_ZN5CCodeC2Eib> */
/* @0x1dfe58 str r6, [r4, #0x8] */
/* @0x1dfe5c mov r0, #1 */
/* @0x1dfe60 pop {r4, r5, r6, pc} */
/* @0x1dfe64 ldr r3, [pc, #0x24] */
/* @0x1dfe68 mov r0, #1 */
/* @0x1dfe6c ldr r2, [r4, #0x10] */
/* @0x1dfe70 ldr r3, [pc, r3] */
/* @0x1dfe74 ldr r3, [r3] */
/* @0x1dfe78 ldr r3, [r3, #0x1c] */
/* @0x1dfe7c add r3, r3, r2, lsl #3 */
/* @0x1dfe80 str r3, [r4, #0xc] */
/* @0x1dfe84 pop {r4, r5, r6, pc} */
/* @0x1dfe88 eoreq sp, r0, r4, lsl #26 */
/* @0x1dfe8c eoreq sp, r0, r8, lsl sp */
/* @0x1dfe90 .word 0x0020dcd0 */

/* ── FUNC 0x1dfe94 · CScript::GetText() · size=232 · insn=58 */
/* @0x1dfe94 push {r4, r5, r6, lr} */
/* @0x1dfe98 sub sp, sp, #16 */
/* @0x1dfe9c ldr r4, [r0, #0x10] */
/* @0x1dfea0 mov r5, r0 */
/* @0x1dfea4 cmp r4, #0 */
/* @0x1dfea8 str r4, [sp, #0xc] */
/* @0x1dfeac movne r0, r4 */
/* @0x1dfeb0 beq 0x1dfebc <_ZN7CScript7GetTextEv+0x28> */
/* @0x1dfeb4 add sp, sp, #16 */
/* @0x1dfeb8 pop {r4, r5, r6, pc} */
/* @0x1dfebc ldr r1, [pc, #0xb4] */
/* @0x1dfec0 mov r0, #1 */
/* @0x1dfec4 mov r3, r0 */
/* @0x1dfec8 mov r2, #234 */
/* @0x1dfecc add r1, pc, r1 */
/* @0x1dfed0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1dfed4 str r0, [sp, #0xc] */
/* @0x1dfed8 strb r4, [r0] */
/* @0x1dfedc ldr r3, [r5, #0x4] */
/* @0x1dfee0 cmp r3, #0 */
/* @0x1dfee4 beq 0x1dff70 <_ZN7CScript7GetTextEv+0xdc> */
/* @0x1dfee8 mov r0, #32 */
/* @0x1dfeec bl 0x27c524 <_Znwj> */
/* @0x1dfef0 mov r1, r4 */
/* @0x1dfef4 mov r6, r0 */
/* @0x1dfef8 bl 0x2010ec <_ZN7CStreamC2Ei> */
/* @0x1dfefc mov r12, #1 */
/* @0x1dff00 ldr r1, [r5, #0x4] */
/* @0x1dff04 mov r2, #0 */
/* @0x1dff08 str r12, [sp] */
/* @0x1dff0c mov r3, #0 */
/* @0x1dff10 mov r0, r6 */
/* @0x1dff14 bl 0x2015c8 <_ZN7CStream8CopyFromEPS_xb> */
/* @0x1dff18 mov r0, r6 */
/* @0x1dff1c movw r1, #0x3039 */
/* @0x1dff20 mov r2, r4 */
/* @0x1dff24 mov r3, r4 */
/* @0x1dff28 bl 0x202380 <_ZN7CStream7DecryptEiii> */
/* @0x1dff2c mov r0, r6 */
/* @0x1dff30 mov r1, r4 */
/* @0x1dff34 bl 0x201148 <_ZN7CStream11SetPositionEi> */
/* @0x1dff38 ldr r0, [sp, #0xc] */
/* @0x1dff3c cmp r0, #0 */
/* @0x1dff40 beq 0x1dff4c <_ZN7CScript7GetTextEv+0xb8> */
/* @0x1dff44 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1dff48 str r4, [sp, #0xc] */
/* @0x1dff4c mov r0, r6 */
/* @0x1dff50 add r1, sp, #12 */
/* @0x1dff54 bl 0x2018e8 <_ZN7CStream10ReadStringERPKc> */
/* @0x1dff58 cmp r6, #0 */
/* @0x1dff5c beq 0x1dff70 <_ZN7CScript7GetTextEv+0xdc> */
/* @0x1dff60 mov r0, r6 */
/* @0x1dff64 bl 0x201328 <_ZN7CStreamD2Ev> */
/* @0x1dff68 mov r0, r6 */
/* @0x1dff6c bl 0x27d1d0 <_ZdlPv> */
/* @0x1dff70 ldr r0, [sp, #0xc] */
/* @0x1dff74 b 0x1dfeb4 <_ZN7CScript7GetTextEv+0x20> */
/* @0x1dff78 andseq r1, r7, r0, lsl #28 */

/* ── FUNC 0x1dff7c · Script_Init() · size=156 · insn=39 */
/* @0x1dff7c push {r3, r4, r5, r6, r7, lr} */
/* @0x1dff80 ldr r6, [pc, #0x84] */
/* @0x1dff84 ldr r6, [pc, r6] */
/* @0x1dff88 ldr r2, [r6, #0x4] */
/* @0x1dff8c cmp r2, #0 */
/* @0x1dff90 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1dff94 ldr r5, [pc, #0x74] */
/* @0x1dff98 ldr r5, [pc, r5] */
/* @0x1dff9c ldr r3, [r5] */
/* @0x1dffa0 cmp r3, #0 */
/* @0x1dffa4 ble 0x1dffdc <_Z11Script_Initv+0x60> */
/* @0x1dffa8 mov r4, #0 */
/* @0x1dffac ldr r3, [r2, r4, lsl #2] */
/* @0x1dffb0 add r4, r4, #1 */
/* @0x1dffb4 cmp r3, #0 */
/* @0x1dffb8 mov r0, r3 */
/* @0x1dffbc beq 0x1dffd0 <_Z11Script_Initv+0x54> */
/* @0x1dffc0 ldr r3, [r3] */
/* @0x1dffc4 ldr r3, [r3, #0x4] */
/* @0x1dffc8 blx r3 */
/* @0x1dffcc ldr r2, [r6, #0x4] */
/* @0x1dffd0 ldr r3, [r5] */
/* @0x1dffd4 cmp r3, r4 */
/* @0x1dffd8 bgt 0x1dffac <_Z11Script_Initv+0x30> */
/* @0x1dffdc ldr r7, [pc, #0x30] */
/* @0x1dffe0 mov r0, r2 */
/* @0x1dffe4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1dffe8 mov r4, #0 */
/* @0x1dffec ldr r7, [pc, r7] */
/* @0x1dfff0 str r4, [r6, #0x4] */
/* @0x1dfff4 str r4, [r6] */
/* @0x1dfff8 ldr r0, [r7] */
/* @0x1dfffc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e0000 str r4, [r7] */
/* @0x1e0004 str r4, [r5] */
/* @0x1e0008 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1e000c eoreq r0, r1, r4, lsr #27 */
/* @0x1e0010 mlaeq r1, r4, sp, r0 */
/* @0x1e0014 eoreq r0, r1, r4, asr #26 */

/* ── FUNC 0x1e0018 · Script_Load(CStream*) · size=460 · insn=115 */
/* @0x1e0018 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1e001c sub sp, sp, #12 */
/* @0x1e0020 str r0, [sp, #0x4] */
/* @0x1e0024 bl 0x1dff7c <_Z11Script_Initv> */
/* @0x1e0028 ldr r0, [sp, #0x4] */
/* @0x1e002c bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1e0030 cmp r0, #800 */
/* @0x1e0034 cmpne r0, #400 */
/* @0x1e0038 mov r7, r0 */
/* @0x1e003c moveq r4, #0 */
/* @0x1e0040 movne r4, #1 */
/* @0x1e0044 beq 0x1e0054 <_Z11Script_LoadP7CStream+0x3c> */
/* @0x1e0048 mov r0, #0 */
/* @0x1e004c add sp, sp, #12 */
/* @0x1e0050 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e0054 ldr r0, [sp, #0x4] */
/* @0x1e0058 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1e005c ldr r5, [pc, #0x170] */
/* @0x1e0060 ldr r11, [pc, #0x170] */
/* @0x1e0064 mov r3, #107 */
/* @0x1e0068 ldr r9, [pc, #0x16c] */
/* @0x1e006c add r5, pc, r5 */
/* @0x1e0070 ldr r11, [pc, r11] */
/* @0x1e0074 ldr r10, [pc, #0x164] */
/* @0x1e0078 ldr r9, [pc, r9] */
/* @0x1e007c mov r2, r5 */
/* @0x1e0080 mov lr, r0 */
/* @0x1e0084 lsl r1, r0, #2 */
/* @0x1e0088 add r0, r9, #4 */
/* @0x1e008c str lr, [r11] */
/* @0x1e0090 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1e0094 ldr r1, [r11] */
/* @0x1e0098 ldr r10, [pc, r10] */
/* @0x1e009c mov r3, #108 */
/* @0x1e00a0 mov r2, r5 */
/* @0x1e00a4 mov r0, r10 */
/* @0x1e00a8 lsl r1, r1, #2 */
/* @0x1e00ac bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1e00b0 ldr r3, [r11] */
/* @0x1e00b4 cmp r3, #0 */
/* @0x1e00b8 movgt r8, r4 */
/* @0x1e00bc bgt 0x1e00d4 <_Z11Script_LoadP7CStream+0xbc> */
/* @0x1e00c0 b 0x1e01b8 <_Z11Script_LoadP7CStream+0x1a0> */
/* @0x1e00c4 ldr r3, [r11] */
/* @0x1e00c8 add r4, r4, #1 */
/* @0x1e00cc cmp r3, r4 */
/* @0x1e00d0 ble 0x1e01b8 <_Z11Script_LoadP7CStream+0x1a0> */
/* @0x1e00d4 cmp r7, #800 */
/* @0x1e00d8 ldrne r6, [sp, #0x4] */
/* @0x1e00dc beq 0x1e01c4 <_Z11Script_LoadP7CStream+0x1ac> */
/* @0x1e00e0 mov r0, r6 */
/* @0x1e00e4 lsl r5, r4, #2 */
/* @0x1e00e8 bl 0x2019b0 <_ZN7CStream11ReadBooleanEv> */
/* @0x1e00ec ldr r2, [r9, #0x4] */
/* @0x1e00f0 str r8, [r2, r4, lsl #2] */
/* @0x1e00f4 ldr r2, [r10] */
/* @0x1e00f8 mov r3, r0 */
/* @0x1e00fc ldr r0, [r2, r4, lsl #2] */
/* @0x1e0100 str r3, [sp] */
/* @0x1e0104 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e0108 ldr r3, [sp] */
/* @0x1e010c ldr r2, [r10] */
/* @0x1e0110 cmp r3, #0 */
/* @0x1e0114 str r8, [r2, r4, lsl #2] */
/* @0x1e0118 beq 0x1e0188 <_Z11Script_LoadP7CStream+0x170> */
/* @0x1e011c ldr r3, [r10] */
/* @0x1e0120 add r1, r3, r5 */
/* @0x1e0124 ldr r0, [r3, r4, lsl #2] */
/* @0x1e0128 cmp r0, #0 */
/* @0x1e012c beq 0x1e0144 <_Z11Script_LoadP7CStream+0x12c> */
/* @0x1e0130 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e0134 ldr r3, [r10] */
/* @0x1e0138 str r8, [r3, r5] */
/* @0x1e013c ldr r1, [r10] */
/* @0x1e0140 add r1, r1, r5 */
/* @0x1e0144 mov r0, r6 */
/* @0x1e0148 bl 0x2018e8 <_ZN7CStream10ReadStringERPKc> */
/* @0x1e014c mov r0, #28 */
/* @0x1e0150 bl 0x27c524 <_Znwj> */
/* @0x1e0154 ldr r2, [r10] */
/* @0x1e0158 ldr r1, [r2, r5] */
/* @0x1e015c str r0, [sp] */
/* @0x1e0160 bl 0x1dfc04 <_ZN7CScriptC2EPKc> */
/* @0x1e0164 ldr r3, [sp] */
/* @0x1e0168 mov r1, r6 */
/* @0x1e016c ldr r2, [r9, #0x4] */
/* @0x1e0170 str r3, [r2, r5] */
/* @0x1e0174 ldr r3, [r9, #0x4] */
/* @0x1e0178 ldr r0, [r3, r5] */
/* @0x1e017c bl 0x1dfc88 <_ZN7CScript14LoadFromStreamEP7CStream> */
/* @0x1e0180 cmp r0, #0 */
/* @0x1e0184 beq 0x1e0048 <_Z11Script_LoadP7CStream+0x30> */
/* @0x1e0188 cmp r7, #800 */
/* @0x1e018c bne 0x1e00c4 <_Z11Script_LoadP7CStream+0xac> */
/* @0x1e0190 cmp r6, #0 */
/* @0x1e0194 beq 0x1e00c4 <_Z11Script_LoadP7CStream+0xac> */
/* @0x1e0198 mov r0, r6 */
/* @0x1e019c add r4, r4, #1 */
/* @0x1e01a0 bl 0x201328 <_ZN7CStreamD2Ev> */
/* @0x1e01a4 mov r0, r6 */
/* @0x1e01a8 bl 0x27d1d0 <_ZdlPv> */
/* @0x1e01ac ldr r3, [r11] */
/* @0x1e01b0 cmp r3, r4 */
/* @0x1e01b4 bgt 0x1e00d4 <_Z11Script_LoadP7CStream+0xbc> */
/* @0x1e01b8 mov r0, #1 */
/* @0x1e01bc add sp, sp, #12 */
/* @0x1e01c0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e01c4 ldr r0, [sp, #0x4] */
/* @0x1e01c8 bl 0x201db0 <_ZN7CStream20ReadCompressedStreamEv> */
/* @0x1e01cc mov r6, r0 */
/* @0x1e01d0 b 0x1e00e0 <_Z11Script_LoadP7CStream+0xc8> */
/* @0x1e01d4 mulseq r7, r8, r12 */
/* @0x1e01d8 .word 0x00210cbc */
/* @0x1e01dc .word 0x00210cb0 */
/* @0x1e01e0 mlaeq r1, r8, r12, r0 */

/* ── FUNC 0x1e01e4 · Script_Load(unsigned char*, unsigned int, unsigned char*) · size=640 · insn=160 */
/* @0x1e01e4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1e01e8 sub sp, sp, #36 */
/* @0x1e01ec ldr r11, [pc, #0x248] */
/* @0x1e01f0 mov r8, r0 */
/* @0x1e01f4 ldr r1, [pc, #0x244] */
/* @0x1e01f8 mov r3, #152 */
/* @0x1e01fc add r11, pc, r11 */
/* @0x1e0200 str r2, [sp, #0x10] */
/* @0x1e0204 ldr r0, [pc, #0x238] */
/* @0x1e0208 ldr r1, [r11, r1] */
/* @0x1e020c ldr r2, [pc, #0x234] */
/* @0x1e0210 ldr r5, [pc, #0x234] */
/* @0x1e0214 str r1, [sp, #0xc] */
/* @0x1e0218 ldr r4, [r11, r0] */
/* @0x1e021c add r5, pc, r5 */
/* @0x1e0220 ldr r0, [r8] */
/* @0x1e0224 str r0, [sp, #0x4] */
/* @0x1e0228 ldr r0, [sp, #0xc] */
/* @0x1e022c ldr r1, [r0] */
/* @0x1e0230 ldr r0, [sp, #0x4] */
/* @0x1e0234 add r1, r0, r1 */
/* @0x1e0238 str r1, [r4] */
/* @0x1e023c ldr r7, [r11, r2] */
/* @0x1e0240 mov r2, r5 */
/* @0x1e0244 lsl r1, r1, #2 */
/* @0x1e0248 add r0, r7, #4 */
/* @0x1e024c bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1e0250 ldr r1, [r4] */
/* @0x1e0254 ldr r0, [pc, #0x1f4] */
/* @0x1e0258 mov r2, r5 */
/* @0x1e025c mov r3, #154 */
/* @0x1e0260 str r1, [r7] */
/* @0x1e0264 lsl r1, r1, #2 */
/* @0x1e0268 ldr r10, [r11, r0] */
/* @0x1e026c mov r0, r10 */
/* @0x1e0270 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1e0274 ldr r1, [sp, #0x4] */
/* @0x1e0278 cmp r1, #0 */
/* @0x1e027c beq 0x1e038c <_Z11Script_LoadPhjS_+0x1a8> */
/* @0x1e0280 ldr r3, [pc, #0x1cc] */
/* @0x1e0284 mov r9, r10 */
/* @0x1e0288 ldr r0, [pc, #0x1c8] */
/* @0x1e028c mov r4, #0 */
/* @0x1e0290 add r3, pc, r3 */
/* @0x1e0294 str r11, [sp, #0x1c] */
/* @0x1e0298 add r0, pc, r0 */
/* @0x1e029c str r3, [sp, #0x14] */
/* @0x1e02a0 str r0, [sp, #0x18] */
/* @0x1e02a4 mov r10, r7 */
/* @0x1e02a8 b 0x1e036c <_Z11Script_LoadPhjS_+0x188> */
/* @0x1e02ac ldr r3, [pc, #0x1a8] */
/* @0x1e02b0 ldr r1, [sp, #0x1c] */
/* @0x1e02b4 ldr r3, [r1, r3] */
/* @0x1e02b8 ldr r11, [r3] */
/* @0x1e02bc str r3, [sp, #0x8] */
/* @0x1e02c0 adds r7, r11, r5 */
/* @0x1e02c4 beq 0x1e0434 <_Z11Script_LoadPhjS_+0x250> */
/* @0x1e02c8 mov r0, #28 */
/* @0x1e02cc bl 0x27c524 <_Znwj> */
/* @0x1e02d0 ldr r1, [sp, #0x14] */
/* @0x1e02d4 mov r6, r0 */
/* @0x1e02d8 bl 0x1dfc04 <_ZN7CScriptC2EPKc> */
/* @0x1e02dc ldr r2, [sp, #0x10] */
/* @0x1e02e0 mov r1, r7 */
/* @0x1e02e4 mov r0, r6 */
/* @0x1e02e8 bl 0x1dfd3c <_ZN7CScript13LoadFromChunkEP8YYScriptPh> */
/* @0x1e02ec ldr r7, [r11, r5] */
/* @0x1e02f0 cmp r7, #0 */
/* @0x1e02f4 ldrne r2, [sp, #0x8] */
/* @0x1e02f8 ldrne r3, [r2] */
/* @0x1e02fc addne r7, r3, r7 */
/* @0x1e0300 mov r0, r7 */
/* @0x1e0304 bl 0xb6538 <strlen@plt> */
/* @0x1e0308 ldr r1, [sp, #0x18] */
/* @0x1e030c mov r3, #1 */
/* @0x1e0310 mov r2, #166 */
/* @0x1e0314 add r0, r0, r3 */
/* @0x1e0318 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1e031c mov r1, r7 */
/* @0x1e0320 mov r5, r0 */
/* @0x1e0324 bl 0xb65a4 <strcpy@plt> */
/* @0x1e0328 ldr r3, [r9] */
/* @0x1e032c lsl r7, r4, #2 */
/* @0x1e0330 ldr r0, [r3, r4, lsl #2] */
/* @0x1e0334 cmp r0, #0 */
/* @0x1e0338 beq 0x1e034c <_Z11Script_LoadPhjS_+0x168> */
/* @0x1e033c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e0340 ldr r3, [r9] */
/* @0x1e0344 mov r0, #0 */
/* @0x1e0348 str r0, [r3, r4, lsl #2] */
/* @0x1e034c ldr r3, [r10, #0x4] */
/* @0x1e0350 add r4, r4, #1 */
/* @0x1e0354 ldr r1, [sp, #0x4] */
/* @0x1e0358 str r6, [r3, r7] */
/* @0x1e035c cmp r4, r1 */
/* @0x1e0360 ldr r3, [r9] */
/* @0x1e0364 str r5, [r3, r7] */
/* @0x1e0368 beq 0x1e0380 <_Z11Script_LoadPhjS_+0x19c> */
/* @0x1e036c ldr r5, [r8, #0x4]! */
/* @0x1e0370 cmp r5, #0 */
/* @0x1e0374 bne 0x1e02ac <_Z11Script_LoadPhjS_+0xc8> */
/* @0x1e0378 mov r6, r5 */
/* @0x1e037c b 0x1e0328 <_Z11Script_LoadPhjS_+0x144> */
/* @0x1e0380 ldr r11, [sp, #0x1c] */
/* @0x1e0384 mov r7, r10 */
/* @0x1e0388 mov r10, r9 */
/* @0x1e038c ldr r2, [sp, #0xc] */
/* @0x1e0390 ldr r3, [r2] */
/* @0x1e0394 cmp r3, #0 */
/* @0x1e0398 ble 0x1e0428 <_Z11Script_LoadPhjS_+0x244> */
/* @0x1e039c ldr r2, [sp, #0x4] */
/* @0x1e03a0 mov r4, #0 */
/* @0x1e03a4 ldr r3, [pc, #0xb4] */
/* @0x1e03a8 mov r12, r7 */
/* @0x1e03ac mov r8, r4 */
/* @0x1e03b0 lsl r5, r2, #2 */
/* @0x1e03b4 ldr r2, [r11, r3] */
/* @0x1e03b8 mov r7, r2 */
/* @0x1e03bc ldr r3, [r7] */
/* @0x1e03c0 add r8, r8, #1 */
/* @0x1e03c4 add r11, r3, r4 */
/* @0x1e03c8 ldr r0, [r3, r4] */
/* @0x1e03cc add r4, r4, #12 */
/* @0x1e03d0 str r12, [sp] */
/* @0x1e03d4 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1e03d8 mov r9, r0 */
/* @0x1e03dc mov r0, #28 */
/* @0x1e03e0 bl 0x27c524 <_Znwj> */
/* @0x1e03e4 mov r1, r9 */
/* @0x1e03e8 mov r6, r0 */
/* @0x1e03ec bl 0x1dfc04 <_ZN7CScriptC2EPKc> */
/* @0x1e03f0 ldr r1, [r11, #0x4] */
/* @0x1e03f4 ldr r12, [sp] */
/* @0x1e03f8 ldr r2, [sp, #0xc] */
/* @0x1e03fc str r1, [r6, #0x10] */
/* @0x1e0400 ldr r3, [r12, #0x4] */
/* @0x1e0404 ldr r1, [r11, #0x8] */
/* @0x1e0408 ldr r0, [r2] */
/* @0x1e040c str r1, [r6, #0x18] */
/* @0x1e0410 cmp r0, r8 */
/* @0x1e0414 str r6, [r3, r5] */
/* @0x1e0418 ldr r3, [r10] */
/* @0x1e041c str r9, [r3, r5] */
/* @0x1e0420 add r5, r5, #4 */
/* @0x1e0424 bgt 0x1e03bc <_Z11Script_LoadPhjS_+0x1d8> */
/* @0x1e0428 mov r0, #1 */
/* @0x1e042c add sp, sp, #36 */
/* @0x1e0430 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e0434 mov r5, r7 */
/* @0x1e0438 b 0x1e0378 <_Z11Script_LoadPhjS_+0x194> */
/* @0x1e043c eoreq r1, r1, r4, asr r10 */
/* @0x1e0440 .word 0xfffff0e4 */
/* @0x1e0444 .word 0xfffff0dc */
/* @0x1e0448 .word 0xfffff0d8 */
/* @0x1e044c andseq r1, r7, r8, ror #21 */
/* @0x1e0450 .word 0xfffff0e0 */
/* @0x1e0454 andseq lr, r4, r6, lsr #17 */
/* @0x1e0458 andseq r1, r7, r12, ror #20 */
/* @0x1e045c .word 0xffffbcf4 */
/* @0x1e0460 .word 0xfffff0e8 */

/* ── FUNC 0x1e0464 · Script_Free() · size=204 · insn=51 */
/* @0x1e0464 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1e0468 ldr r3, [pc, #0xb0] */
/* @0x1e046c ldr r2, [pc, #0xb0] */
/* @0x1e0470 add r3, pc, r3 */
/* @0x1e0474 ldr r1, [pc, #0xac] */
/* @0x1e0478 ldr r6, [r3, r2] */
/* @0x1e047c ldr r2, [r6] */
/* @0x1e0480 cmp r2, #0 */
/* @0x1e0484 ble 0x1e050c <_Z11Script_Freev+0xa8> */
/* @0x1e0488 ldr r2, [pc, #0x9c] */
/* @0x1e048c mov r4, #0 */
/* @0x1e0490 ldr r7, [r3, r1] */
/* @0x1e0494 mov r8, r4 */
/* @0x1e0498 ldr r5, [r3, r2] */
/* @0x1e049c ldr r2, [r7, #0x4] */
/* @0x1e04a0 ldr r0, [r2, r4, lsl #2] */
/* @0x1e04a4 lsl r9, r4, #2 */
/* @0x1e04a8 cmp r0, #0 */
/* @0x1e04ac beq 0x1e04d4 <_Z11Script_Freev+0x70> */
/* @0x1e04b0 bl 0x1dfb8c <_ZN7CScript4FreeEv> */
/* @0x1e04b4 ldr r3, [r5] */
/* @0x1e04b8 ldr r0, [r3, r4, lsl #2] */
/* @0x1e04bc cmp r0, #0 */
/* @0x1e04c0 beq 0x1e04d0 <_Z11Script_Freev+0x6c> */
/* @0x1e04c4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e04c8 ldr r3, [r5] */
/* @0x1e04cc str r8, [r3, r9] */
/* @0x1e04d0 ldr r2, [r7, #0x4] */
/* @0x1e04d4 ldr r3, [r6] */
/* @0x1e04d8 add r4, r4, #1 */
/* @0x1e04dc cmp r3, r4 */
/* @0x1e04e0 bgt 0x1e04a0 <_Z11Script_Freev+0x3c> */
/* @0x1e04e4 mov r0, r2 */
/* @0x1e04e8 mov r4, #0 */
/* @0x1e04ec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e04f0 ldr r0, [r5] */
/* @0x1e04f4 str r4, [r7, #0x4] */
/* @0x1e04f8 str r4, [r7] */
/* @0x1e04fc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e0500 str r4, [r6] */
/* @0x1e0504 str r4, [r5] */
/* @0x1e0508 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1e050c ldr r2, [pc, #0x18] */
/* @0x1e0510 ldr r7, [r3, r1] */
/* @0x1e0514 ldr r5, [r3, r2] */
/* @0x1e0518 ldr r2, [r7, #0x4] */
/* @0x1e051c b 0x1e04e4 <_Z11Script_Freev+0x80> */
/* @0x1e0520 eoreq r1, r1, r0, ror #15 */
/* @0x1e0524 .word 0xfffff0dc */
/* @0x1e0528 .word 0xfffff0d8 */
/* @0x1e052c .word 0xfffff0e0 */

/* ── FUNC 0x1e0530 · Script_Number() · size=20 · insn=5 */
/* @0x1e0530 ldr r3, [pc, #0x8] */
/* @0x1e0534 ldr r3, [pc, r3] */
/* @0x1e0538 ldr r0, [r3] */
/* @0x1e053c bx lr */
/* @0x1e0540 .word 0x002107f8 */

/* ── FUNC 0x1e0544 · Script_Exists(int) · size=72 · insn=18 */
/* @0x1e0544 cmp r0, #0 */
/* @0x1e0548 blt 0x1e057c <_Z13Script_Existsi+0x38> */
/* @0x1e054c ldr r3, [pc, #0x30] */
/* @0x1e0550 ldr r3, [pc, r3] */
/* @0x1e0554 ldr r3, [r3] */
/* @0x1e0558 cmp r0, r3 */
/* @0x1e055c bge 0x1e057c <_Z13Script_Existsi+0x38> */
/* @0x1e0560 ldr r3, [pc, #0x20] */
/* @0x1e0564 ldr r3, [pc, r3] */
/* @0x1e0568 ldr r3, [r3, #0x4] */
/* @0x1e056c ldr r0, [r3, r0, lsl #2] */
/* @0x1e0570 adds r0, r0, #0 */
/* @0x1e0574 movne r0, #1 */
/* @0x1e0578 bx lr */
/* @0x1e057c mov r0, #0 */
/* @0x1e0580 bx lr */
/* @0x1e0584 .word 0x002107dc */
/* @0x1e0588 eoreq r0, r1, r4, asr #15 */

/* ── FUNC 0x1e058c · Script_Name(int) · size=132 · insn=33 */
/* @0x1e058c cmp r0, #0 */
/* @0x1e0590 blt 0x1e05e0 <_Z11Script_Namei+0x54> */
/* @0x1e0594 ldr r3, [pc, #0x5c] */
/* @0x1e0598 ldr r3, [pc, r3] */
/* @0x1e059c ldr r3, [r3] */
/* @0x1e05a0 cmp r0, r3 */
/* @0x1e05a4 bge 0x1e05d4 <_Z11Script_Namei+0x48> */
/* @0x1e05a8 ldr r3, [pc, #0x4c] */
/* @0x1e05ac ldr r3, [pc, r3] */
/* @0x1e05b0 ldr r3, [r3, #0x4] */
/* @0x1e05b4 ldr r3, [r3, r0, lsl #2] */
/* @0x1e05b8 cmp r3, #0 */
/* @0x1e05bc beq 0x1e05ec <_Z11Script_Namei+0x60> */
/* @0x1e05c0 ldr r3, [pc, #0x38] */
/* @0x1e05c4 ldr r3, [pc, r3] */
/* @0x1e05c8 ldr r3, [r3] */
/* @0x1e05cc ldr r0, [r3, r0, lsl #2] */
/* @0x1e05d0 bx lr */
/* @0x1e05d4 ldr r0, [pc, #0x28] */
/* @0x1e05d8 add r0, pc, r0 */
/* @0x1e05dc bx lr */
/* @0x1e05e0 ldr r0, [pc, #0x20] */
/* @0x1e05e4 add r0, pc, r0 */
/* @0x1e05e8 bx lr */
/* @0x1e05ec ldr r0, [pc, #0x18] */
/* @0x1e05f0 add r0, pc, r0 */
/* @0x1e05f4 bx lr */
/* @0x1e05f8 mlaeq r1, r4, r7, r0 */
/* @0x1e05fc eoreq r0, r1, r12, ror r7 */
/* @0x1e0600 eoreq r0, r1, r12, ror #14 */
/* @0x1e0604 andseq r0, r5, r8, ror #9 */
/* @0x1e0608 ldrsbeq r0, [r5], -r12 */
/* @0x1e060c ldrsbeq r0, [r5], -r0 */

/* ── FUNC 0x1e0610 · Script_Find(char const*) · size=140 · insn=35 */
/* @0x1e0610 push {r3, r4, r5, r6, r7, lr} */
/* @0x1e0614 mov r7, r0 */
/* @0x1e0618 ldr r3, [pc, #0x70] */
/* @0x1e061c ldr r3, [pc, r3] */
/* @0x1e0620 ldr r5, [r3] */
/* @0x1e0624 subs r4, r5, #1 */
/* @0x1e0628 bmi 0x1e0680 <_Z11Script_FindPKc+0x70> */
/* @0x1e062c ldr r2, [pc, #0x60] */
/* @0x1e0630 lsl r5, r5, #2 */
/* @0x1e0634 ldr r3, [pc, #0x5c] */
/* @0x1e0638 ldr r2, [pc, r2] */
/* @0x1e063c ldr r3, [pc, r3] */
/* @0x1e0640 ldr r6, [r2, #0x4] */
/* @0x1e0644 ldr r3, [r3] */
/* @0x1e0648 add r6, r6, r5 */
/* @0x1e064c add r5, r3, r5 */
/* @0x1e0650 ldr r3, [r6, #-0x4]! */
/* @0x1e0654 mov r1, r7 */
/* @0x1e0658 cmp r3, #0 */
/* @0x1e065c beq 0x1e0670 <_Z11Script_FindPKc+0x60> */
/* @0x1e0660 ldr r0, [r5, #-0x4] */
/* @0x1e0664 bl 0xb6574 <strcmp@plt> */
/* @0x1e0668 cmp r0, #0 */
/* @0x1e066c beq 0x1e0688 <_Z11Script_FindPKc+0x78> */
/* @0x1e0670 sub r4, r4, #1 */
/* @0x1e0674 sub r5, r5, #4 */
/* @0x1e0678 cmn r4, #1 */
/* @0x1e067c bne 0x1e0650 <_Z11Script_FindPKc+0x40> */
/* @0x1e0680 mvn r0, #0 */
/* @0x1e0684 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1e0688 mov r0, r4 */
/* @0x1e068c pop {r3, r4, r5, r6, r7, pc} */
/* @0x1e0690 eoreq r0, r1, r0, lsl r7 */
/* @0x1e0694 .word 0x002106f0 */
/* @0x1e0698 .word 0x002106f4 */

/* ── FUNC 0x1e069c · Script_Data(int) · size=64 · insn=16 */
/* @0x1e069c cmp r0, #0 */
/* @0x1e06a0 blt 0x1e06cc <_Z11Script_Datai+0x30> */
/* @0x1e06a4 ldr r3, [pc, #0x28] */
/* @0x1e06a8 ldr r3, [pc, r3] */
/* @0x1e06ac ldr r3, [r3] */
/* @0x1e06b0 cmp r0, r3 */
/* @0x1e06b4 bge 0x1e06cc <_Z11Script_Datai+0x30> */
/* @0x1e06b8 ldr r3, [pc, #0x18] */
/* @0x1e06bc ldr r3, [pc, r3] */
/* @0x1e06c0 ldr r3, [r3, #0x4] */
/* @0x1e06c4 ldr r0, [r3, r0, lsl #2] */
/* @0x1e06c8 bx lr */
/* @0x1e06cc mov r0, #0 */
/* @0x1e06d0 bx lr */
/* @0x1e06d4 eoreq r0, r1, r4, lsl #13 */
/* @0x1e06d8 eoreq r0, r1, r12, ror #12 */

/* ── FUNC 0x1e06dc · Script_Find_Parent(char const*) · size=148 · insn=37 */
/* @0x1e06dc push {r3, r4, r5, lr} */
/* @0x1e06e0 bl 0x1e0610 <_Z11Script_FindPKc> */
/* @0x1e06e4 cmn r0, #1 */
/* @0x1e06e8 beq 0x1e0760 <_Z18Script_Find_ParentPKc+0x84> */
/* @0x1e06ec bl 0x1e069c <_Z11Script_Datai> */
/* @0x1e06f0 subs r5, r0, #0 */
/* @0x1e06f4 beq 0x1e0760 <_Z18Script_Find_ParentPKc+0x84> */
/* @0x1e06f8 ldr r3, [pc, #0x68] */
/* @0x1e06fc ldr r3, [pc, r3] */
/* @0x1e0700 ldr r2, [r3] */
/* @0x1e0704 subs r3, r2, #1 */
/* @0x1e0708 bmi 0x1e0760 <_Z18Script_Find_ParentPKc+0x84> */
/* @0x1e070c ldr r1, [pc, #0x58] */
/* @0x1e0710 ldr r1, [pc, r1] */
/* @0x1e0714 ldr r1, [r1, #0x4] */
/* @0x1e0718 add r1, r1, r2, lsl #2 */
/* @0x1e071c ldr r0, [r1, #-0x4]! */
/* @0x1e0720 sub r3, r3, #1 */
/* @0x1e0724 cmp r0, #0 */
/* @0x1e0728 beq 0x1e0758 <_Z18Script_Find_ParentPKc+0x7c> */
/* @0x1e072c ldr r2, [r0, #0x8] */
/* @0x1e0730 ldr r12, [r2, #0x6c] */
/* @0x1e0734 cmp r12, #0 */
/* @0x1e0738 bne 0x1e0758 <_Z18Script_Find_ParentPKc+0x7c> */
/* @0x1e073c ldr r4, [r5, #0x8] */
/* @0x1e0740 ldr r12, [r2, #0x50] */
/* @0x1e0744 ldr r2, [r4, #0x50] */
/* @0x1e0748 ldr r12, [r12, #0x10] */
/* @0x1e074c ldr r2, [r2, #0x10] */
/* @0x1e0750 cmp r12, r2 */
/* @0x1e0754 popeq {r3, r4, r5, pc} */
/* @0x1e0758 cmn r3, #1 */
/* @0x1e075c bne 0x1e071c <_Z18Script_Find_ParentPKc+0x40> */
/* @0x1e0760 mov r0, #0 */
/* @0x1e0764 pop {r3, r4, r5, pc} */
/* @0x1e0768 eoreq r0, r1, r0, lsr r6 */
/* @0x1e076c eoreq r0, r1, r8, lsl r6 */

/* ── FUNC 0x1e0770 · FINALIZE_Script_Main() · size=4 · insn=1 */
/* @0x1e0770 b 0x1e0464 <_Z11Script_Freev> */

/* ── FUNC 0x1e0774 · Script_Perform(int, CInstance*, CInstance*, int, RValue*, DynamicArrayOfRValue*) · size=892 · insn=223 */
/* @0x1e0774 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1e0778 add r11, sp, #32 */
/* @0x1e077c ldr r4, [pc, #0x34c] */
/* @0x1e0780 sub sp, sp, #1072 */
/* @0x1e0784 sub sp, sp, #4 */
/* @0x1e0788 ldr r12, [pc, #0x344] */
/* @0x1e078c add r4, pc, r4 */
/* @0x1e0790 subs r7, r0, #0 */
/* @0x1e0794 ldr r0, [pc, #0x33c] */
/* @0x1e0798 ldr r12, [r4, r12] */
/* @0x1e079c mov r8, r1 */
/* @0x1e07a0 ldr r1, [pc, #0x334] */
/* @0x1e07a4 mov r6, r3 */
/* @0x1e07a8 ldmib r11, {r3, r9} */
/* @0x1e07ac str r12, [r11, #-0x430] */
/* @0x1e07b0 ldr r12, [r12] */
/* @0x1e07b4 str r12, [r11, #-0x28] */
/* @0x1e07b8 ldr r0, [r4, r0] */
/* @0x1e07bc ldr r5, [r4, r1] */
/* @0x1e07c0 str r0, [r11, #-0x434] */
/* @0x1e07c4 ldr r1, [r11, #-0x434] */
/* @0x1e07c8 ldr r0, [r5] */
/* @0x1e07cc ldr r1, [r1] */
/* @0x1e07d0 str r0, [r11, #-0x438] */
/* @0x1e07d4 str r1, [r11, #-0x43c] */
/* @0x1e07d8 blt 0x1e0848 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0xd4> */
/* @0x1e07dc ldr r1, [pc, #0x2fc] */
/* @0x1e07e0 ldr r1, [r4, r1] */
/* @0x1e07e4 ldr r1, [r1] */
/* @0x1e07e8 cmp r7, r1 */
/* @0x1e07ec bge 0x1e0848 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0xd4> */
/* @0x1e07f0 ldr r1, [pc, #0x2ec] */
/* @0x1e07f4 ldr r1, [r4, r1] */
/* @0x1e07f8 ldr r1, [r1, #0x4] */
/* @0x1e07fc ldr r1, [r1, r7, lsl #2] */
/* @0x1e0800 cmp r1, #0 */
/* @0x1e0804 moveq r9, r1 */
/* @0x1e0808 beq 0x1e084c <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0xd8> */
/* @0x1e080c mov r0, r1 */
/* @0x1e0810 str r1, [r11, #-0x44c] */
/* @0x1e0814 str r2, [r11, #-0x444] */
/* @0x1e0818 str r3, [r11, #-0x448] */
/* @0x1e081c bl 0x1dfba8 <_ZN7CScript7GetCodeEv> */
/* @0x1e0820 ldr r1, [r11, #-0x44c] */
/* @0x1e0824 ldr r2, [r11, #-0x444] */
/* @0x1e0828 ldr r3, [r11, #-0x448] */
/* @0x1e082c subs r12, r0, #0 */
/* @0x1e0830 beq 0x1e0884 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0x110> */
/* @0x1e0834 ldr r0, [r12, #0x64] */
/* @0x1e0838 cmp r0, #0 */
/* @0x1e083c beq 0x1e086c <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0xf8> */
/* @0x1e0840 mov r9, #1 */
/* @0x1e0844 b 0x1e084c <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0xd8> */
/* @0x1e0848 mov r9, #0 */
/* @0x1e084c ldr r5, [r11, #-0x430] */
/* @0x1e0850 mov r0, r9 */
/* @0x1e0854 ldr r2, [r11, #-0x28] */
/* @0x1e0858 ldr r3, [r5] */
/* @0x1e085c cmp r2, r3 */
/* @0x1e0860 bne 0x1e0acc <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0x358> */
/* @0x1e0864 sub sp, r11, #32 */
/* @0x1e0868 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e086c ldr r0, [r12, #0x50] */
/* @0x1e0870 cmp r0, #0 */
/* @0x1e0874 beq 0x1e0884 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0x110> */
/* @0x1e0878 ldr r0, [r0, #0x4] */
/* @0x1e087c cmp r0, #0 */
/* @0x1e0880 beq 0x1e0840 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0xcc> */
/* @0x1e0884 cmp r9, #0 */
/* @0x1e0888 beq 0x1e0a64 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0x2f0> */
/* @0x1e088c ldr r0, [r9, #0x4] */
/* @0x1e0890 str r0, [r5] */
/* @0x1e0894 ldr r0, [r11, #-0x434] */
/* @0x1e0898 cmp r12, #0 */
/* @0x1e089c str r6, [r0] */
/* @0x1e08a0 beq 0x1e0a6c <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0x2f8> */
/* @0x1e08a4 mov r1, r2 */
/* @0x1e08a8 mov r2, r12 */
/* @0x1e08ac adds r12, r8, #0 */
/* @0x1e08b0 mov r0, r8 */
/* @0x1e08b4 movne r12, #1 */
/* @0x1e08b8 str r12, [sp] */
/* @0x1e08bc bl 0xd05d4 <_Z20Code_Execute_SpecialP9CInstanceS0_P5CCodeP6RValuei> */
/* @0x1e08c0 subs r9, r0, #0 */
/* @0x1e08c4 beq 0x1e095c <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0x1e8> */
/* @0x1e08c8 cmp r6, #0 */
/* @0x1e08cc ble 0x1e0944 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0x1d0> */
/* @0x1e08d0 mov r7, #0 */
/* @0x1e08d4 str r9, [r11, #-0x440] */
/* @0x1e08d8 mov r1, #5 */
/* @0x1e08dc mov r9, r5 */
/* @0x1e08e0 mov r10, r7 */
/* @0x1e08e4 mov r5, r6 */
/* @0x1e08e8 b 0x1e0904 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0x190> */
/* @0x1e08ec add r7, r7, #1 */
/* @0x1e08f0 str r10, [r4, #0x8] */
/* @0x1e08f4 cmp r7, r5 */
/* @0x1e08f8 str r1, [r4, #0xc] */
/* @0x1e08fc str r10, [r6, r8] */
/* @0x1e0900 beq 0x1e093c <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0x1c8> */
/* @0x1e0904 ldr r6, [r9] */
/* @0x1e0908 lsl r8, r7, #4 */
/* @0x1e090c add r4, r6, r8 */
/* @0x1e0910 ldr r3, [r4, #0xc] */
/* @0x1e0914 sub r3, r3, #1 */
/* @0x1e0918 bic r3, r3, #-16777216 */
/* @0x1e091c bic r3, r3, #3 */
/* @0x1e0920 cmp r3, #0 */
/* @0x1e0924 bne 0x1e08ec <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0x178> */
/* @0x1e0928 mov r0, r4 */
/* @0x1e092c str r1, [r11, #-0x44c] */
/* @0x1e0930 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1e0934 ldr r1, [r11, #-0x44c] */
/* @0x1e0938 b 0x1e08ec <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0x178> */
/* @0x1e093c mov r5, r9 */
/* @0x1e0940 ldr r9, [r11, #-0x440] */
/* @0x1e0944 ldr r1, [r11, #-0x438] */
/* @0x1e0948 ldr r0, [r11, #-0x434] */
/* @0x1e094c str r1, [r5] */
/* @0x1e0950 ldr r5, [r11, #-0x43c] */
/* @0x1e0954 str r5, [r0] */
/* @0x1e0958 b 0x1e084c <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0xd8> */
/* @0x1e095c sub r8, r11, #1056 */
/* @0x1e0960 mov r1, r9 */
/* @0x1e0964 sub r8, r8, #4 */
/* @0x1e0968 mov r2, #1024 */
/* @0x1e096c sub r8, r8, #4 */
/* @0x1e0970 mov r0, r8 */
/* @0x1e0974 bl 0xb65b0 <memset@plt> */
/* @0x1e0978 mov r0, r7 */
/* @0x1e097c bl 0x1e058c <_Z11Script_Namei> */
/* @0x1e0980 ldr r12, [pc, #0x160] */
/* @0x1e0984 ldr r2, [pc, #0x160] */
/* @0x1e0988 mov r1, #1024 */
/* @0x1e098c ldr r4, [r4, r12] */
/* @0x1e0990 add r2, pc, r2 */
/* @0x1e0994 ldr r12, [r4] */
/* @0x1e0998 ldr r12, [r12] */
/* @0x1e099c str r12, [sp] */
/* @0x1e09a0 mov r3, r0 */
/* @0x1e09a4 mov r0, r8 */
/* @0x1e09a8 bl 0xb65c8 <snprintf@plt> */
/* @0x1e09ac ldr r7, [r4] */
/* @0x1e09b0 cmp r7, #0 */
/* @0x1e09b4 beq 0x1e09dc <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0x268> */
/* @0x1e09b8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1e09bc ldr r3, [r7, #0x4] */
/* @0x1e09c0 sub r3, r3, #1 */
/* @0x1e09c4 str r3, [r7, #0x4] */
/* @0x1e09c8 cmp r3, #0 */
/* @0x1e09cc beq 0x1e0a0c <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0x298> */
/* @0x1e09d0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1e09d4 mov r0, r7 */
/* @0x1e09d8 bl 0x27d1d0 <_ZdlPv> */
/* @0x1e09dc mov r0, #12 */
/* @0x1e09e0 bl 0x27c524 <_Znwj> */
/* @0x1e09e4 mov r7, r0 */
/* @0x1e09e8 mov r0, r8 */
/* @0x1e09ec bl 0xb6538 <strlen@plt> */
/* @0x1e09f0 str r0, [r7, #0x8] */
/* @0x1e09f4 mov r0, r8 */
/* @0x1e09f8 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1e09fc mov r3, #1 */
/* @0x1e0a00 stm r7, {r0, r3} */
/* @0x1e0a04 str r7, [r4] */
/* @0x1e0a08 b 0x1e08c8 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0x154> */
/* @0x1e0a0c ldr r0, [r7] */
/* @0x1e0a10 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1e0a14 str r9, [r7] */
/* @0x1e0a18 str r9, [r7, #0x8] */
/* @0x1e0a1c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1e0a20 ldr r3, [r7, #0x4] */
/* @0x1e0a24 sub r3, r3, #1 */
/* @0x1e0a28 str r3, [r7, #0x4] */
/* @0x1e0a2c cmp r3, #0 */
/* @0x1e0a30 bne 0x1e0a54 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0x2e0> */
/* @0x1e0a34 ldr r0, [r7] */
/* @0x1e0a38 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1e0a3c mov r0, r7 */
/* @0x1e0a40 str r9, [r7] */
/* @0x1e0a44 str r9, [r7, #0x8] */
/* @0x1e0a48 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x1e0a4c mov r0, r7 */
/* @0x1e0a50 bl 0x27d1d0 <_ZdlPv> */
/* @0x1e0a54 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1e0a58 mov r0, r7 */
/* @0x1e0a5c bl 0x27d1d0 <_ZdlPv> */
/* @0x1e0a60 b 0x1e09d0 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0x25c> */
/* @0x1e0a64 str r9, [r5] */
/* @0x1e0a68 b 0x1e0894 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0x120> */
/* @0x1e0a6c lsl r4, r6, #2 */
/* @0x1e0a70 cmp r6, #0 */
/* @0x1e0a74 add r12, r4, #14 */
/* @0x1e0a78 ldr r0, [r5] */
/* @0x1e0a7c bic r12, r12, #7 */
/* @0x1e0a80 sub sp, sp, r12 */
/* @0x1e0a84 add lr, sp, #8 */
/* @0x1e0a88 addgt r4, lr, r4 */
/* @0x1e0a8c movgt r12, lr */
/* @0x1e0a90 ble 0x1e0aa4 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0x330> */
/* @0x1e0a94 str r0, [r12], #4 */
/* @0x1e0a98 cmp r12, r4 */
/* @0x1e0a9c add r0, r0, #16 */
/* @0x1e0aa0 bne 0x1e0a94 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0x320> */
/* @0x1e0aa4 ldr r12, [r1, #0xc] */
/* @0x1e0aa8 mov r0, r8 */
/* @0x1e0aac str lr, [sp] */
/* @0x1e0ab0 mov r1, r2 */
/* @0x1e0ab4 mov r2, r3 */
/* @0x1e0ab8 mov r3, r6 */
/* @0x1e0abc ldr r12, [r12, #0x4] */
/* @0x1e0ac0 mov r9, #1 */
/* @0x1e0ac4 blx r12 */
/* @0x1e0ac8 b 0x1e08c8 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0x154> */
/* @0x1e0acc bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x1e0ad0 eoreq r1, r1, r4, asr #9 */
/* @0x1e0ad4 .word 0xffffbd00 */
/* @0x1e0ad8 .word 0xffffc0bc */
/* @0x1e0adc .word 0xffffc0c0 */
/* @0x1e0ae0 .word 0xfffff0dc */
/* @0x1e0ae4 .word 0xfffff0d8 */
/* @0x1e0ae8 .word 0xffffbf20 */
/* @0x1e0aec andseq r1, r7, r12, lsr #7 */

/* ── FUNC 0x1e0af0 · Script_Prepare() · size=696 · insn=174 */
/* @0x1e0af0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1e0af4 add r11, sp, #32 */
/* @0x1e0af8 ldr r5, [pc, #0x274] */
/* @0x1e0afc sub sp, sp, #60 */
/* @0x1e0b00 ldr r2, [pc, #0x270] */
/* @0x1e0b04 add r5, pc, r5 */
/* @0x1e0b08 ldr r3, [pc, #0x26c] */
/* @0x1e0b0c ldr r2, [r5, r2] */
/* @0x1e0b10 str r2, [r11, #-0x54] */
/* @0x1e0b14 ldr r2, [r2] */
/* @0x1e0b18 str r2, [r11, #-0x28] */
/* @0x1e0b1c ldr r6, [r5, r3] */
/* @0x1e0b20 ldr r3, [r6] */
/* @0x1e0b24 cmp r3, #0 */
/* @0x1e0b28 ble 0x1e0b68 <_Z14Script_Preparev+0x78> */
/* @0x1e0b2c ldr r3, [pc, #0x24c] */
/* @0x1e0b30 mov r4, #0 */
/* @0x1e0b34 ldr r8, [r5, r3] */
/* @0x1e0b38 ldr r3, [r8, #0x4] */
/* @0x1e0b3c lsl r7, r4, #2 */
/* @0x1e0b40 ldr r0, [r3, r4, lsl #2] */
/* @0x1e0b44 cmp r0, #0 */
/* @0x1e0b48 beq 0x1e0b58 <_Z14Script_Preparev+0x68> */
/* @0x1e0b4c bl 0x1dfe10 <_ZN7CScript7CompileEv> */
/* @0x1e0b50 subs r9, r0, #0 */
/* @0x1e0b54 beq 0x1e0cf8 <_Z14Script_Preparev+0x208> */
/* @0x1e0b58 ldr r3, [r6] */
/* @0x1e0b5c add r4, r4, #1 */
/* @0x1e0b60 cmp r3, r4 */
/* @0x1e0b64 bgt 0x1e0b38 <_Z14Script_Preparev+0x48> */
/* @0x1e0b68 ldr r3, [pc, #0x214] */
/* @0x1e0b6c mov r2, #5 */
/* @0x1e0b70 str r2, [r11, #-0x3c] */
/* @0x1e0b74 ldr r6, [r5, r3] */
/* @0x1e0b78 ldr r3, [r6] */
/* @0x1e0b7c cmp r3, #0 */
/* @0x1e0b80 ble 0x1e0c08 <_Z14Script_Preparev+0x118> */
/* @0x1e0b84 ldr r3, [pc, #0x1fc] */
/* @0x1e0b88 sub r10, r11, #72 */
/* @0x1e0b8c ldr r2, [pc, #0x1f8] */
/* @0x1e0b90 mov r7, #0 */
/* @0x1e0b94 ldr r3, [r5, r3] */
/* @0x1e0b98 ldr r8, [r5, r2] */
/* @0x1e0b9c str r3, [r11, #-0x50] */
/* @0x1e0ba0 ldr r3, [r8] */
/* @0x1e0ba4 mov r0, #124 */
/* @0x1e0ba8 ldr r9, [r3, r7, lsl #2] */
/* @0x1e0bac bl 0x27c524 <_Znwj> */
/* @0x1e0bb0 mov r2, #0 */
/* @0x1e0bb4 mov r1, r9 */
/* @0x1e0bb8 mov r4, r0 */
/* @0x1e0bbc bl 0xcefc8 <_ZN5CCodeC2Eib> */
/* @0x1e0bc0 ldr r1, [r11, #-0x50] */
/* @0x1e0bc4 mov r3, #0 */
/* @0x1e0bc8 mov r2, r4 */
/* @0x1e0bcc ldr r0, [r1] */
/* @0x1e0bd0 str r3, [sp] */
/* @0x1e0bd4 mov r3, r10 */
/* @0x1e0bd8 mov r1, r0 */
/* @0x1e0bdc bl 0xcfc60 <_Z12Code_ExecuteP9CInstanceS0_P5CCodeP6RValuei> */
/* @0x1e0be0 cmp r4, #0 */
/* @0x1e0be4 beq 0x1e0bf8 <_Z14Script_Preparev+0x108> */
/* @0x1e0be8 ldr r3, [r4] */
/* @0x1e0bec mov r0, r4 */
/* @0x1e0bf0 ldr r3, [r3, #0x4] */
/* @0x1e0bf4 blx r3 */
/* @0x1e0bf8 ldr r3, [r6] */
/* @0x1e0bfc add r7, r7, #1 */
/* @0x1e0c00 cmp r3, r7 */
/* @0x1e0c04 bgt 0x1e0ba0 <_Z14Script_Preparev+0xb0> */
/* @0x1e0c08 ldr r3, [pc, #0x180] */
/* @0x1e0c0c ldr r3, [r5, r3] */
/* @0x1e0c10 ldrb r3, [r3] */
/* @0x1e0c14 cmp r3, #0 */
/* @0x1e0c18 beq 0x1e0cd4 <_Z14Script_Preparev+0x1e4> */
/* @0x1e0c1c ldr r3, [pc, #0x170] */
/* @0x1e0c20 ldr r4, [r5, r3] */
/* @0x1e0c24 ldrb r3, [r4] */
/* @0x1e0c28 cmp r3, #0 */
/* @0x1e0c2c beq 0x1e0c54 <_Z14Script_Preparev+0x164> */
/* @0x1e0c30 ldr r3, [pc, #0x160] */
/* @0x1e0c34 ldr r6, [r5, r3] */
/* @0x1e0c38 bl 0x29d770 <_Z12TickDebuggerv> */
/* @0x1e0c3c ldrb r3, [r4] */
/* @0x1e0c40 cmp r3, #0 */
/* @0x1e0c44 bne 0x1e0c38 <_Z14Script_Preparev+0x148> */
/* @0x1e0c48 ldrb r3, [r6] */
/* @0x1e0c4c cmp r3, #0 */
/* @0x1e0c50 beq 0x1e0c38 <_Z14Script_Preparev+0x148> */
/* @0x1e0c54 bl 0x1e0530 <_Z13Script_Numberv> */
/* @0x1e0c58 mov r4, #0 */
/* @0x1e0c5c mvn r3, #-16777216 */
/* @0x1e0c60 str r4, [r11, #-0x38] */
/* @0x1e0c64 str r4, [r11, #-0x34] */
/* @0x1e0c68 str r4, [r11, #-0x30] */
/* @0x1e0c6c str r3, [r11, #-0x2c] */
/* @0x1e0c70 subs r6, r0, #0 */
/* @0x1e0c74 subgt r7, r11, #56 */
/* @0x1e0c78 bgt 0x1e0c8c <_Z14Script_Preparev+0x19c> */
/* @0x1e0c7c b 0x1e0cd4 <_Z14Script_Preparev+0x1e4> */
/* @0x1e0c80 add r4, r4, #1 */
/* @0x1e0c84 cmp r4, r6 */
/* @0x1e0c88 beq 0x1e0cd4 <_Z14Script_Preparev+0x1e4> */
/* @0x1e0c8c mov r0, r4 */
/* @0x1e0c90 bl 0x1e069c <_Z11Script_Datai> */
/* @0x1e0c94 bl 0x1dfba8 <_ZN7CScript7GetCodeEv> */
/* @0x1e0c98 ldr r2, [r0, #0x6c] */
/* @0x1e0c9c cmp r2, #0 */
/* @0x1e0ca0 bne 0x1e0c80 <_Z14Script_Preparev+0x190> */
/* @0x1e0ca4 ldr r1, [pc, #0xdc] */
/* @0x1e0ca8 mov r3, r2 */
/* @0x1e0cac mov r0, r4 */
/* @0x1e0cb0 add r4, r4, #1 */
/* @0x1e0cb4 ldr r1, [r5, r1] */
/* @0x1e0cb8 str r2, [sp, #0x4] */
/* @0x1e0cbc str r7, [sp] */
/* @0x1e0cc0 ldr r1, [r1] */
/* @0x1e0cc4 mov r2, r1 */
/* @0x1e0cc8 bl 0x1e0774 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue> */
/* @0x1e0ccc cmp r4, r6 */
/* @0x1e0cd0 bne 0x1e0c8c <_Z14Script_Preparev+0x19c> */
/* @0x1e0cd4 mov r9, #1 */
/* @0x1e0cd8 ldr r1, [r11, #-0x54] */
/* @0x1e0cdc mov r0, r9 */
/* @0x1e0ce0 ldr r2, [r11, #-0x28] */
/* @0x1e0ce4 ldr r3, [r1] */
/* @0x1e0ce8 cmp r2, r3 */
/* @0x1e0cec bne 0x1e0d70 <_Z14Script_Preparev+0x280> */
/* @0x1e0cf0 sub sp, r11, #32 */
/* @0x1e0cf4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e0cf8 ldr r3, [pc, #0x9c] */
/* @0x1e0cfc ldr r3, [r5, r3] */
/* @0x1e0d00 ldr r3, [r3] */
/* @0x1e0d04 ldr r6, [r3] */
/* @0x1e0d08 mov r0, r6 */
/* @0x1e0d0c bl 0xb6538 <strlen@plt> */
/* @0x1e0d10 ldr r3, [pc, #0x88] */
/* @0x1e0d14 ldr r3, [r5, r3] */
/* @0x1e0d18 ldr r3, [r3] */
/* @0x1e0d1c ldr r4, [r3, r7] */
/* @0x1e0d20 mov r8, r0 */
/* @0x1e0d24 mov r0, r4 */
/* @0x1e0d28 bl 0xb6538 <strlen@plt> */
/* @0x1e0d2c mov r3, r4 */
/* @0x1e0d30 ldr r2, [pc, #0x6c] */
/* @0x1e0d34 add r2, pc, r2 */
/* @0x1e0d38 add r0, r8, r0 */
/* @0x1e0d3c add r1, r0, #34 */
/* @0x1e0d40 lsl r1, r1, #1 */
/* @0x1e0d44 add r0, r1, #14 */
/* @0x1e0d48 bic r0, r0, #7 */
/* @0x1e0d4c sub sp, sp, r0 */
/* @0x1e0d50 add r4, sp, #8 */
/* @0x1e0d54 str r6, [sp] */
/* @0x1e0d58 mov r0, r4 */
/* @0x1e0d5c bl 0xb65c8 <snprintf@plt> */
/* @0x1e0d60 mov r0, r4 */
/* @0x1e0d64 mov r1, #1 */
/* @0x1e0d68 bl 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1e0d6c b 0x1e0cd8 <_Z14Script_Preparev+0x1e8> */
/* @0x1e0d70 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x1e0d74 eoreq r1, r1, r12, asr #2 */
/* @0x1e0d78 .word 0xffffbd00 */
/* @0x1e0d7c .word 0xfffff0dc */
/* @0x1e0d80 .word 0xfffff0d8 */
/* @0x1e0d84 .word 0xfffff058 */
/* @0x1e0d88 .word 0xffffbf64 */
/* @0x1e0d8c .word 0xfffff054 */
/* @0x1e0d90 .word 0xffffbf68 */
/* @0x1e0d94 .word 0xffffdf9c */
/* @0x1e0d98 .word 0xfffff0ec */
/* @0x1e0d9c .word 0xffffbf20 */
/* @0x1e0da0 .word 0xfffff0e0 */
/* @0x1e0da4 andseq r1, r7, r12, lsl r0 */

/* ── FUNC 0x1e0da8 · F_Shader_Current(RValue&, CInstance*, CInstance*, int, RValue*) · size=176 · insn=44 */
/* @0x1e0da8 ldr r3, [pc, #0x9c] */
/* @0x1e0dac mov r2, #0 */
/* @0x1e0db0 str r2, [r0] */
/* @0x1e0db4 mov r1, r2 */
/* @0x1e0db8 ldr r3, [pc, r3] */
/* @0x1e0dbc movt r1, #0xbff0 */
/* @0x1e0dc0 str r4, [sp, #-0x4]! */
/* @0x1e0dc4 ldr r12, [r3] */
/* @0x1e0dc8 str r2, [r0, #0xc] */
/* @0x1e0dcc cmp r12, r2 */
/* @0x1e0dd0 str r1, [r0, #0x4] */
/* @0x1e0dd4 beq 0x1e0e20 <_Z16F_Shader_CurrentR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x1e0dd8 ldr r3, [pc, #0x70] */
/* @0x1e0ddc ldr r3, [pc, r3] */
/* @0x1e0de0 ldr r4, [r3] */
/* @0x1e0de4 cmp r4, r2 */
/* @0x1e0de8 ble 0x1e0e20 <_Z16F_Shader_CurrentR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x1e0dec ldr r3, [pc, #0x60] */
/* @0x1e0df0 ldr r3, [pc, r3] */
/* @0x1e0df4 ldr r3, [r3] */
/* @0x1e0df8 ldr r1, [r3] */
/* @0x1e0dfc cmp r12, r1 */
/* @0x1e0e00 bne 0x1e0e14 <_Z16F_Shader_CurrentR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x1e0e04 b 0x1e0e40 <_Z16F_Shader_CurrentR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0x1e0e08 ldr r1, [r3, #0x4]! */
/* @0x1e0e0c cmp r12, r1 */
/* @0x1e0e10 beq 0x1e0e28 <_Z16F_Shader_CurrentR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x1e0e14 add r2, r2, #1 */
/* @0x1e0e18 cmp r2, r4 */
/* @0x1e0e1c bne 0x1e0e08 <_Z16F_Shader_CurrentR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0x1e0e20 ldr r4, [sp], #4 */
/* @0x1e0e24 bx lr */
/* @0x1e0e28 vmov s15, r2 */
/* @0x1e0e2c vcvt.f64.s32 d7, s15 */
/* @0x1e0e30 vmov r2, r3, d7 */
/* @0x1e0e34 stm r0, {r2, r3} */
/* @0x1e0e38 ldr r4, [sp], #4 */
/* @0x1e0e3c bx lr */
/* @0x1e0e40 mov r2, #0 */
/* @0x1e0e44 mov r3, #0 */
/* @0x1e0e48 b 0x1e0e34 <_Z16F_Shader_CurrentR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x1e0e4c eoreq pc, r0, r8, lsl #31 */
/* @0x1e0e50 eoreq pc, r0, r8, ror #30 */
/* @0x1e0e54 eoreq pc, r0, r8, asr pc */

/* ── FUNC 0x1e0e58 · F_Texture_Get_Texel_Width(RValue&, CInstance*, CInstance*, int, RValue*) · size=160 · insn=40 */
/* @0x1e0e58 push {r4, r5, r6, lr} */
/* @0x1e0e5c mov r1, #0 */
/* @0x1e0e60 mov r3, r1 */
/* @0x1e0e64 str r1, [r0, #0xc] */
/* @0x1e0e68 movt r3, #0x3ff0 */
/* @0x1e0e6c mov r4, r0 */
/* @0x1e0e70 stm r0, {r1, r3} */
/* @0x1e0e74 ldr r0, [sp, #0x10] */
/* @0x1e0e78 bl 0xce6c0 <_Z13YYGetPtrOrIntPK6RValuei> */
/* @0x1e0e7c cmn r0, #1 */
/* @0x1e0e80 mov r5, r0 */
/* @0x1e0e84 popeq {r4, r5, r6, pc} */
/* @0x1e0e88 bl 0x173e2c <_Z17GR_Texture_Existsi> */
/* @0x1e0e8c cmp r0, #0 */
/* @0x1e0e90 beq 0x1e0ec4 <_Z25F_Texture_Get_Texel_WidthR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x1e0e94 ldr r6, [pc, #0x54] */
/* @0x1e0e98 ldr r6, [pc, r6] */
/* @0x1e0e9c ldr r3, [r6, #0x4] */
/* @0x1e0ea0 vmov.f64 d6, #1.000000e+00 */
/* @0x1e0ea4 ldr r3, [r3, r5, lsl #2] */
/* @0x1e0ea8 ldr r3, [r3] */
/* @0x1e0eac vldr s14, [r3, #4] */
/* @0x1e0eb0 vcvt.f64.s32 d7, s14 */
/* @0x1e0eb4 vdiv.f64 d5, d6, d7 */
/* @0x1e0eb8 vmov r2, r3, d5 */
/* @0x1e0ebc stm r4, {r2, r3} */
/* @0x1e0ec0 pop {r4, r5, r6, pc} */
/* @0x1e0ec4 ldr r6, [pc, #0x28] */
/* @0x1e0ec8 ldr r6, [pc, r6] */
/* @0x1e0ecc ldr r3, [r6] */
/* @0x1e0ed0 cmp r5, r3 */
/* @0x1e0ed4 poplo {r4, r5, r6, pc} */
/* @0x1e0ed8 ldrsh r5, [r5, #20] */
/* @0x1e0edc mov r0, r5 */
/* @0x1e0ee0 bl 0x173e2c <_Z17GR_Texture_Existsi> */
/* @0x1e0ee4 cmp r0, #0 */
/* @0x1e0ee8 bne 0x1e0e9c <_Z25F_Texture_Get_Texel_WidthR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x1e0eec pop {r4, r5, r6, pc} */
/* @0x1e0ef0 eoreq r12, r0, r4, lsl #21 */
/* @0x1e0ef4 eoreq r12, r0, r4, asr r10 */

/* ── FUNC 0x1e0ef8 · F_Texture_Get_Texel_Height(RValue&, CInstance*, CInstance*, int, RValue*) · size=160 · insn=40 */
/* @0x1e0ef8 push {r4, r5, r6, lr} */
/* @0x1e0efc mov r1, #0 */
/* @0x1e0f00 mov r3, r1 */
/* @0x1e0f04 str r1, [r0, #0xc] */
/* @0x1e0f08 movt r3, #0x3ff0 */
/* @0x1e0f0c mov r4, r0 */
/* @0x1e0f10 stm r0, {r1, r3} */
/* @0x1e0f14 ldr r0, [sp, #0x10] */
/* @0x1e0f18 bl 0xce6c0 <_Z13YYGetPtrOrIntPK6RValuei> */
/* @0x1e0f1c cmn r0, #1 */
/* @0x1e0f20 mov r5, r0 */
/* @0x1e0f24 popeq {r4, r5, r6, pc} */
/* @0x1e0f28 bl 0x173e2c <_Z17GR_Texture_Existsi> */
/* @0x1e0f2c cmp r0, #0 */
/* @0x1e0f30 beq 0x1e0f64 <_Z26F_Texture_Get_Texel_HeightR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x1e0f34 ldr r6, [pc, #0x54] */
/* @0x1e0f38 ldr r6, [pc, r6] */
/* @0x1e0f3c ldr r3, [r6, #0x4] */
/* @0x1e0f40 vmov.f64 d6, #1.000000e+00 */
/* @0x1e0f44 ldr r3, [r3, r5, lsl #2] */
/* @0x1e0f48 ldr r3, [r3] */
/* @0x1e0f4c vldr s14, [r3, #8] */
/* @0x1e0f50 vcvt.f64.s32 d7, s14 */
/* @0x1e0f54 vdiv.f64 d5, d6, d7 */
/* @0x1e0f58 vmov r2, r3, d5 */
/* @0x1e0f5c stm r4, {r2, r3} */
/* @0x1e0f60 pop {r4, r5, r6, pc} */
/* @0x1e0f64 ldr r6, [pc, #0x28] */
/* @0x1e0f68 ldr r6, [pc, r6] */
/* @0x1e0f6c ldr r3, [r6] */
/* @0x1e0f70 cmp r5, r3 */
/* @0x1e0f74 poplo {r4, r5, r6, pc} */
/* @0x1e0f78 ldrsh r5, [r5, #20] */
/* @0x1e0f7c mov r0, r5 */
/* @0x1e0f80 bl 0x173e2c <_Z17GR_Texture_Existsi> */
/* @0x1e0f84 cmp r0, #0 */
/* @0x1e0f88 bne 0x1e0f3c <_Z26F_Texture_Get_Texel_HeightR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x1e0f8c pop {r4, r5, r6, pc} */
/* @0x1e0f90 eoreq r12, r0, r4, ror #19 */
/* @0x1e0f94 .word 0x0020c9b4 */

/* ── FUNC 0x1e0f98 · F_Shaders_Are_Supported(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x1e0f98 push {r3, r4, r5, lr} */
/* @0x1e0f9c mov r5, #0 */
/* @0x1e0fa0 str r5, [r0, #0xc] */
/* @0x1e0fa4 mov r4, r0 */
/* @0x1e0fa8 str r5, [r0] */
/* @0x1e0fac str r5, [r0, #0x4] */
/* @0x1e0fb0 bl 0x17df3c <_ZN8Graphics16ShadersSupportedEv> */
/* @0x1e0fb4 cmp r0, r5 */
/* @0x1e0fb8 strne r5, [r4] */
/* @0x1e0fbc movne r3, r5 */
/* @0x1e0fc0 movtne r3, #0x3ff0 */
/* @0x1e0fc4 strne r3, [r4, #0x4] */
/* @0x1e0fc8 pop {r3, r4, r5, pc} */

/* ── FUNC 0x1e0fcc · F_Shader_Is_Compiled(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x1e0fcc push {r4, lr} */
/* @0x1e0fd0 mov r3, #0 */
/* @0x1e0fd4 ldr r2, [sp, #0x8] */
/* @0x1e0fd8 mov r4, r0 */
/* @0x1e0fdc str r3, [r0, #0xc] */
/* @0x1e0fe0 mov r1, r3 */
/* @0x1e0fe4 str r3, [r0] */
/* @0x1e0fe8 str r3, [r0, #0x4] */
/* @0x1e0fec mov r0, r2 */
/* @0x1e0ff0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1e0ff4 cmp r0, #0 */
/* @0x1e0ff8 blt 0x1e1038 <_Z20F_Shader_Is_CompiledR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x1e0ffc ldr r3, [pc, #0x48] */
/* @0x1e1000 ldr r3, [pc, r3] */
/* @0x1e1004 ldr r3, [r3] */
/* @0x1e1008 cmp r0, r3 */
/* @0x1e100c bge 0x1e1038 <_Z20F_Shader_Is_CompiledR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x1e1010 ldr r3, [pc, #0x38] */
/* @0x1e1014 ldr r3, [pc, r3] */
/* @0x1e1018 ldr r3, [r3] */
/* @0x1e101c ldr r3, [r3, r0, lsl #2] */
/* @0x1e1020 ldr r3, [r3, #0x54] */
/* @0x1e1024 cmp r3, #0 */
/* @0x1e1028 streq r3, [r4] */
/* @0x1e102c movteq r3, #0x3ff0 */
/* @0x1e1030 streq r3, [r4, #0x4] */
/* @0x1e1034 pop {r4, pc} */
/* @0x1e1038 ldr r0, [pc, #0x14] */
/* @0x1e103c mov r1, #0 */
/* @0x1e1040 pop {r4, lr} */
/* @0x1e1044 add r0, pc, r0 */
/* @0x1e1048 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1e104c eoreq pc, r0, r4, asr #26 */
/* @0x1e1050 eoreq pc, r0, r4, lsr sp */
/* @0x1e1054 andseq r0, r7, r0, lsr sp */

/* ── FUNC 0x1e1058 · F_Shader_Get_Uniform(RValue&, CInstance*, CInstance*, int, RValue*) · size=168 · insn=42 */
/* @0x1e1058 push {r3, r4, r5, lr} */
/* @0x1e105c mov r1, #0 */
/* @0x1e1060 ldr r5, [sp, #0x10] */
/* @0x1e1064 mov r3, r1 */
/* @0x1e1068 str r1, [r0, #0xc] */
/* @0x1e106c movt r3, #0xbff0 */
/* @0x1e1070 mov r4, r0 */
/* @0x1e1074 stm r0, {r1, r3} */
/* @0x1e1078 mov r0, r5 */
/* @0x1e107c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1e1080 subs r2, r0, #0 */
/* @0x1e1084 blt 0x1e109c <_Z20F_Shader_Get_UniformR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x1e1088 ldr r3, [pc, #0x64] */
/* @0x1e108c ldr r3, [pc, r3] */
/* @0x1e1090 ldr r3, [r3] */
/* @0x1e1094 cmp r2, r3 */
/* @0x1e1098 blt 0x1e10b0 <_Z20F_Shader_Get_UniformR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x1e109c ldr r0, [pc, #0x54] */
/* @0x1e10a0 mov r1, #0 */
/* @0x1e10a4 pop {r3, r4, r5, lr} */
/* @0x1e10a8 add r0, pc, r0 */
/* @0x1e10ac b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1e10b0 ldr r3, [pc, #0x44] */
/* @0x1e10b4 mov r0, r5 */
/* @0x1e10b8 mov r1, #1 */
/* @0x1e10bc ldr r3, [pc, r3] */
/* @0x1e10c0 ldr r3, [r3] */
/* @0x1e10c4 ldr r5, [r3, r2, lsl #2] */
/* @0x1e10c8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1e10cc mov r1, r0 */
/* @0x1e10d0 mov r0, r5 */
/* @0x1e10d4 bl 0x1883b8 <_Z25Shader_Get_Uniform_HandleP6ShaderPKc> */
/* @0x1e10d8 vmov s15, r0 */
/* @0x1e10dc vcvt.f64.s32 d7, s15 */
/* @0x1e10e0 vmov r0, r1, d7 */
/* @0x1e10e4 vmov r2, s14 */
/* @0x1e10e8 mov r3, r1 */
/* @0x1e10ec stm r4, {r2, r3} */
/* @0x1e10f0 pop {r3, r4, r5, pc} */
/* @0x1e10f4 .word 0x0020fcb8 */
/* @0x1e10f8 andseq r0, r7, r12, asr #25 */
/* @0x1e10fc eoreq pc, r0, r12, lsl #25 */

/* ── FUNC 0x1e1100 · F_Shader_Get_Sampler_Index(RValue&, CInstance*, CInstance*, int, RValue*) · size=168 · insn=42 */
/* @0x1e1100 push {r3, r4, r5, lr} */
/* @0x1e1104 mov r1, #0 */
/* @0x1e1108 ldr r5, [sp, #0x10] */
/* @0x1e110c mov r3, r1 */
/* @0x1e1110 str r1, [r0, #0xc] */
/* @0x1e1114 movt r3, #0xbff0 */
/* @0x1e1118 mov r4, r0 */
/* @0x1e111c stm r0, {r1, r3} */
/* @0x1e1120 mov r0, r5 */
/* @0x1e1124 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1e1128 subs r2, r0, #0 */
/* @0x1e112c blt 0x1e1144 <_Z26F_Shader_Get_Sampler_IndexR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x1e1130 ldr r3, [pc, #0x64] */
/* @0x1e1134 ldr r3, [pc, r3] */
/* @0x1e1138 ldr r3, [r3] */
/* @0x1e113c cmp r2, r3 */
/* @0x1e1140 blt 0x1e1158 <_Z26F_Shader_Get_Sampler_IndexR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x1e1144 ldr r0, [pc, #0x54] */
/* @0x1e1148 mov r1, #0 */
/* @0x1e114c pop {r3, r4, r5, lr} */
/* @0x1e1150 add r0, pc, r0 */
/* @0x1e1154 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1e1158 ldr r3, [pc, #0x44] */
/* @0x1e115c mov r0, r5 */
/* @0x1e1160 mov r1, #1 */
/* @0x1e1164 ldr r3, [pc, r3] */
/* @0x1e1168 ldr r3, [r3] */
/* @0x1e116c ldr r5, [r3, r2, lsl #2] */
/* @0x1e1170 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1e1174 mov r1, r0 */
/* @0x1e1178 mov r0, r5 */
/* @0x1e117c bl 0x188468 <_Z24Shader_Get_Sampler_IndexP6ShaderPKc> */
/* @0x1e1180 vmov s15, r0 */
/* @0x1e1184 vcvt.f64.s32 d7, s15 */
/* @0x1e1188 vmov r0, r1, d7 */
/* @0x1e118c vmov r2, s14 */
/* @0x1e1190 mov r3, r1 */
/* @0x1e1194 stm r4, {r2, r3} */
/* @0x1e1198 pop {r3, r4, r5, pc} */
/* @0x1e119c eoreq pc, r0, r0, lsl r12 */
/* @0x1e11a0 andseq r0, r7, r4, lsr #24 */
/* @0x1e11a4 eoreq pc, r0, r4, ror #23 */
