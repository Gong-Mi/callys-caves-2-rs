/* libyoyo.so 覆盖卡组 0196
 * 函数 0x21db54..0x21e9f0，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x21db54 · CAudioGroup::CAudioGroup(int) · alias of the symbol above · insn=0 */

/* ── FUNC 0x21db80 · CAudioGroup::~CAudioGroup() · size=116 · insn=29 */
/* @0x21db80 push {r4, r5, r6, lr} */
/* @0x21db84 mov r4, r0 */
/* @0x21db88 ldr r5, [r0, #0x20] */
/* @0x21db8c cmp r5, #0 */
/* @0x21db90 beq 0x21dbb8 <_ZN11CAudioGroupD2Ev+0x38> */
/* @0x21db94 ldr r6, [r5, #0x14] */
/* @0x21db98 cmp r6, #0 */
/* @0x21db9c beq 0x21dbb0 <_ZN11CAudioGroupD2Ev+0x30> */
/* @0x21dba0 mov r0, r6 */
/* @0x21dba4 bl 0x27e020 <_ZN5MutexD2Ev> */
/* @0x21dba8 mov r0, r6 */
/* @0x21dbac bl 0x27d1d0 <_ZdlPv> */
/* @0x21dbb0 mov r0, r5 */
/* @0x21dbb4 bl 0x27d1d0 <_ZdlPv> */
/* @0x21dbb8 mov r5, #0 */
/* @0x21dbbc ldr r0, [r4, #0x24] */
/* @0x21dbc0 str r5, [r4, #0x20] */
/* @0x21dbc4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21dbc8 ldr r0, [r4, #0x18] */
/* @0x21dbcc str r5, [r4, #0x24] */
/* @0x21dbd0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21dbd4 ldr r0, [r4, #0x1c] */
/* @0x21dbd8 str r5, [r4, #0x18] */
/* @0x21dbdc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21dbe0 str r5, [r4, #0x1c] */
/* @0x21dbe4 str r5, [r4, #0xc] */
/* @0x21dbe8 mov r0, r4 */
/* @0x21dbec str r5, [r4, #0x8] */
/* @0x21dbf0 pop {r4, r5, r6, pc} */

/* ── FUNC 0x21db80 · CAudioGroup::~CAudioGroup() · alias of the symbol above · insn=0 */

/* ── FUNC 0x21dbf4 · CAudioGroup::SetName(char const*) · size=44 · insn=11 */
/* @0x21dbf4 push {r3, r4, r5, lr} */
/* @0x21dbf8 mov r4, r0 */
/* @0x21dbfc ldr r0, [r0, #0x1c] */
/* @0x21dc00 mov r5, r1 */
/* @0x21dc04 cmp r0, #0 */
/* @0x21dc08 beq 0x21dc10 <_ZN11CAudioGroup7SetNameEPKc+0x1c> */
/* @0x21dc0c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x21dc10 mov r0, r5 */
/* @0x21dc14 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x21dc18 str r0, [r4, #0x1c] */
/* @0x21dc1c pop {r3, r4, r5, pc} */

/* ── FUNC 0x21dc20 · CAudioGroup::AddSound(cAudio_Sound*) · size=96 · insn=24 */
/* @0x21dc20 push {r3, r4, r5, lr} */
/* @0x21dc24 mov r4, r0 */
/* @0x21dc28 ldr r3, [r0, #0x24] */
/* @0x21dc2c mov r5, r1 */
/* @0x21dc30 cmp r3, #0 */
/* @0x21dc34 beq 0x21dc58 <_ZN11CAudioGroup8AddSoundEP12cAudio_Sound+0x38> */
/* @0x21dc38 ldr r3, [r4, #0xc] */
/* @0x21dc3c ldr r2, [r4, #0x8] */
/* @0x21dc40 cmp r3, r2 */
/* @0x21dc44 addlt r1, r3, #1 */
/* @0x21dc48 strlt r1, [r4, #0xc] */
/* @0x21dc4c ldrlt r2, [r4, #0x24] */
/* @0x21dc50 strlt r5, [r2, r3, lsl #2] */
/* @0x21dc54 pop {r3, r4, r5, pc} */
/* @0x21dc58 ldr r0, [r0, #0x8] */
/* @0x21dc5c mov r2, #61 */
/* @0x21dc60 ldr r1, [pc, #0x14] */
/* @0x21dc64 mov r3, #1 */
/* @0x21dc68 add r1, pc, r1 */
/* @0x21dc6c lsl r0, r0, #2 */
/* @0x21dc70 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x21dc74 str r0, [r4, #0x24] */
/* @0x21dc78 b 0x21dc38 <_ZN11CAudioGroup8AddSoundEP12cAudio_Sound+0x18> */
/* @0x21dc7c ldrsbeq r6, [r3], -r8 */

/* ── FUNC 0x21dc80 · CAudioGroup::FreeBuffers() · size=56 · insn=14 */
/* @0x21dc80 push {r3, r4, r5, lr} */
/* @0x21dc84 mov r5, r0 */
/* @0x21dc88 ldr r3, [r0, #0x8] */
/* @0x21dc8c cmp r3, #0 */
/* @0x21dc90 pople {r3, r4, r5, pc} */
/* @0x21dc94 mov r4, #0 */
/* @0x21dc98 ldr r3, [r5, #0x24] */
/* @0x21dc9c ldr r0, [r3, r4, lsl #2] */
/* @0x21dca0 add r4, r4, #1 */
/* @0x21dca4 bl 0x2193d4 <_ZN12cAudio_Sound12FreeALBufferEv> */
/* @0x21dca8 ldr r3, [r5, #0x8] */
/* @0x21dcac cmp r3, r4 */
/* @0x21dcb0 bgt 0x21dc98 <_ZN11CAudioGroup11FreeBuffersEv+0x18> */
/* @0x21dcb4 pop {r3, r4, r5, pc} */

/* ── FUNC 0x21dcb8 · CAudioGroup::AsyncDecode() · size=144 · insn=36 */
/* @0x21dcb8 push {r4, r5, r6, lr} */
/* @0x21dcbc mov r2, r0 */
/* @0x21dcc0 ldr r4, [r0, #0x20] */
/* @0x21dcc4 sub sp, sp, #8 */
/* @0x21dcc8 cmp r4, #0 */
/* @0x21dccc beq 0x21dcec <_ZN11CAudioGroup11AsyncDecodeEv+0x34> */
/* @0x21dcd0 ldr r1, [pc, #0x68] */
/* @0x21dcd4 mov r0, r4 */
/* @0x21dcd8 mov r3, #1 */
/* @0x21dcdc add r1, pc, r1 */
/* @0x21dce0 add sp, sp, #8 */
/* @0x21dce4 pop {r4, r5, r6, lr} */
/* @0x21dce8 b 0x27e0c0 <_ZN7CThread5StartEPFPvS0_ES0_NS_9ePriorityE> */
/* @0x21dcec mov r0, #24 */
/* @0x21dcf0 str r2, [sp, #0x4] */
/* @0x21dcf4 bl 0x27c524 <_Znwj> */
/* @0x21dcf8 mov r5, r0 */
/* @0x21dcfc strb r4, [r0, #0x8] */
/* @0x21dd00 str r4, [r5] */
/* @0x21dd04 mov r0, #8 */
/* @0x21dd08 str r4, [r5, #0x4] */
/* @0x21dd0c strb r4, [r5, #0x9] */
/* @0x21dd10 str r4, [r5, #0xc] */
/* @0x21dd14 str r4, [r5, #0x10] */
/* @0x21dd18 mov r4, r5 */
/* @0x21dd1c bl 0x27c524 <_Znwj> */
/* @0x21dd20 ldr r1, [pc, #0x1c] */
/* @0x21dd24 add r1, pc, r1 */
/* @0x21dd28 mov r6, r0 */
/* @0x21dd2c bl 0x27e070 <_ZN5MutexC2EPKc> */
/* @0x21dd30 ldr r2, [sp, #0x4] */
/* @0x21dd34 str r6, [r5, #0x14] */
/* @0x21dd38 str r5, [r2, #0x20] */
/* @0x21dd3c b 0x21dcd0 <_ZN11CAudioGroup11AsyncDecodeEv+0x18> */
/* @0x21dd40 .word 0xfffffe58 */
/* @0x21dd44 mulseq r1, r0, r10 */

/* ── FUNC 0x21dd48 · CAudioGroup::SetLoadState(CAudioGroup::eLoadState) · size=84 · insn=21 */
/* @0x21dd48 push {r3, lr} */
/* @0x21dd4c ldr r3, [r0] */
/* @0x21dd50 cmp r3, r1 */
/* @0x21dd54 popeq {r3, pc} */
/* @0x21dd58 ldr r3, [pc, #0x30] */
/* @0x21dd5c ldr r12, [pc, #0x30] */
/* @0x21dd60 ldr r3, [pc, r3] */
/* @0x21dd64 str r1, [r0] */
/* @0x21dd68 ldr r2, [r0, #0x4] */
/* @0x21dd6c add r12, pc, r12 */
/* @0x21dd70 ldr r0, [r3] */
/* @0x21dd74 ldr r3, [r12, r1, lsl #2] */
/* @0x21dd78 ldr r1, [pc, #0x18] */
/* @0x21dd7c ldr r12, [r0] */
/* @0x21dd80 add r1, pc, r1 */
/* @0x21dd84 ldr r12, [r12, #0xc] */
/* @0x21dd88 blx r12 */
/* @0x21dd8c pop {r3, pc} */
/* @0x21dd90 ldrheq pc, [r12], -r4 */
/* @0x21dd94 andseq r9, r8, r12, ror #11 */
/* @0x21dd98 ldrsheq r6, [r3], -r8 */

/* ── FUNC 0x21dd9c · CAudioGroup::GetLoadProgress() · size=88 · insn=22 */
/* @0x21dd9c ldr r3, [r0] */
/* @0x21dda0 push {r4, lr} */
/* @0x21dda4 cmp r3, #2 */
/* @0x21dda8 mov r4, r0 */
/* @0x21ddac beq 0x21ddec <_ZN11CAudioGroup15GetLoadProgressEv+0x50> */
/* @0x21ddb0 cmp r3, #1 */
/* @0x21ddb4 beq 0x21ddc0 <_ZN11CAudioGroup15GetLoadProgressEv+0x24> */
/* @0x21ddb8 mov r0, #0 */
/* @0x21ddbc pop {r4, pc} */
/* @0x21ddc0 ldr r0, [r0, #0x20] */
/* @0x21ddc4 cmp r0, #0 */
/* @0x21ddc8 popeq {r4, pc} */
/* @0x21ddcc ldr r0, [r0, #0x14] */
/* @0x21ddd0 bl 0x27e084 <_ZN5Mutex4LockEv> */
/* @0x21ddd4 ldr r3, [r4, #0x20] */
/* @0x21ddd8 ldr r4, [r4, #0x14] */
/* @0x21dddc ldr r0, [r3, #0x14] */
/* @0x21dde0 bl 0x27e09c <_ZN5Mutex6UnlockEv> */
/* @0x21dde4 mov r0, r4 */
/* @0x21dde8 pop {r4, pc} */
/* @0x21ddec mov r0, #100 */
/* @0x21ddf0 pop {r4, pc} */

/* ── FUNC 0x21ddf4 · CAudioGroup::IncLoadCount() · size=72 · insn=18 */
/* @0x21ddf4 push {r3, r4, r5, lr} */
/* @0x21ddf8 mov r4, r0 */
/* @0x21ddfc ldr r3, [r4, #0x10] */
/* @0x21de00 mov r0, #100 */
/* @0x21de04 ldr r1, [r4, #0x8] */
/* @0x21de08 add r3, r3, #1 */
/* @0x21de0c str r3, [r4, #0x10] */
/* @0x21de10 mul r0, r0, r3 */
/* @0x21de14 bl 0x318d10 <__divsi3> */
/* @0x21de18 ldr r3, [r4, #0x20] */
/* @0x21de1c mov r5, r0 */
/* @0x21de20 ldr r0, [r3, #0x14] */
/* @0x21de24 bl 0x27e084 <_ZN5Mutex4LockEv> */
/* @0x21de28 ldr r3, [r4, #0x20] */
/* @0x21de2c str r5, [r4, #0x14] */
/* @0x21de30 ldr r0, [r3, #0x14] */
/* @0x21de34 pop {r3, r4, r5, lr} */
/* @0x21de38 b 0x27e09c <_ZN5Mutex6UnlockEv> */

/* ── FUNC 0x21de3c · CAudioGroupMan::CAudioGroupMan() · size=16 · insn=4 */
/* @0x21de3c mov r2, #0 */
/* @0x21de40 str r2, [r0] */
/* @0x21de44 str r2, [r0, #0x4] */
/* @0x21de48 bx lr */

/* ── FUNC 0x21de3c · CAudioGroupMan::CAudioGroupMan() · alias of the symbol above · insn=0 */

/* ── FUNC 0x21de4c · CAudioGroupMan::CreateGroups(int) · size=100 · insn=25 */
/* @0x21de4c push {r3, r4, r5, r6, r7, lr} */
/* @0x21de50 mov r6, r1 */
/* @0x21de54 ldr r1, [pc, #0x50] */
/* @0x21de58 mov r7, r0 */
/* @0x21de5c mov r2, #164 */
/* @0x21de60 lsl r0, r6, #2 */
/* @0x21de64 add r1, pc, r1 */
/* @0x21de68 mov r3, #1 */
/* @0x21de6c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x21de70 cmp r6, #0 */
/* @0x21de74 stm r7, {r0, r6} */
/* @0x21de78 pople {r3, r4, r5, r6, r7, pc} */
/* @0x21de7c mov r4, #0 */
/* @0x21de80 mov r0, #40 */
/* @0x21de84 bl 0x27c524 <_Znwj> */
/* @0x21de88 mov r1, r4 */
/* @0x21de8c mov r5, r0 */
/* @0x21de90 bl 0x21db54 <_ZN11CAudioGroupC2Ei> */
/* @0x21de94 ldr r3, [r7] */
/* @0x21de98 str r5, [r3, r4, lsl #2] */
/* @0x21de9c add r4, r4, #1 */
/* @0x21dea0 cmp r4, r6 */
/* @0x21dea4 bne 0x21de80 <_ZN14CAudioGroupMan12CreateGroupsEi+0x34> */
/* @0x21dea8 pop {r3, r4, r5, r6, r7, pc} */
/* @0x21deac ldrsbeq r6, [r3], -r12 */

/* ── FUNC 0x21deb0 · CAudioGroupMan::Finalise() · size=92 · insn=23 */
/* @0x21deb0 ldm r0, {r2, r3} */
/* @0x21deb4 push {r4, r5, r6, lr} */
/* @0x21deb8 cmp r3, #0 */
/* @0x21debc mov r6, r0 */
/* @0x21dec0 movgt r4, #0 */
/* @0x21dec4 ble 0x21def4 <_ZN14CAudioGroupMan8FinaliseEv+0x44> */
/* @0x21dec8 ldr r5, [r2, r4, lsl #2] */
/* @0x21decc add r4, r4, #1 */
/* @0x21ded0 cmp r5, #0 */
/* @0x21ded4 mov r0, r5 */
/* @0x21ded8 beq 0x21deec <_ZN14CAudioGroupMan8FinaliseEv+0x3c> */
/* @0x21dedc bl 0x21db80 <_ZN11CAudioGroupD2Ev> */
/* @0x21dee0 mov r0, r5 */
/* @0x21dee4 bl 0x27d1d0 <_ZdlPv> */
/* @0x21dee8 ldm r6, {r2, r3} */
/* @0x21deec cmp r3, r4 */
/* @0x21def0 bgt 0x21dec8 <_ZN14CAudioGroupMan8FinaliseEv+0x18> */
/* @0x21def4 mov r0, r2 */
/* @0x21def8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21defc mov r3, #0 */
/* @0x21df00 str r3, [r6] */
/* @0x21df04 str r3, [r6, #0x4] */
/* @0x21df08 pop {r4, r5, r6, pc} */

/* ── FUNC 0x21df0c · CAudioGroupMan::GetGroup(int) · size=40 · insn=10 */
/* @0x21df0c cmp r1, #0 */
/* @0x21df10 blt 0x21df2c <_ZN14CAudioGroupMan8GetGroupEi+0x20> */
/* @0x21df14 ldr r3, [r0, #0x4] */
/* @0x21df18 cmp r1, r3 */
/* @0x21df1c bge 0x21df2c <_ZN14CAudioGroupMan8GetGroupEi+0x20> */
/* @0x21df20 ldr r3, [r0] */
/* @0x21df24 ldr r0, [r3, r1, lsl #2] */
/* @0x21df28 bx lr */
/* @0x21df2c mov r0, #0 */
/* @0x21df30 bx lr */

/* ── FUNC 0x21df34 · CAudioGroupMan::GetGroupName(int) · size=40 · insn=10 */
/* @0x21df34 push {r3, lr} */
/* @0x21df38 bl 0x21df0c <_ZN14CAudioGroupMan8GetGroupEi> */
/* @0x21df3c cmp r0, #0 */
/* @0x21df40 beq 0x21df4c <_ZN14CAudioGroupMan12GetGroupNameEi+0x18> */
/* @0x21df44 ldr r0, [r0, #0x1c] */
/* @0x21df48 pop {r3, pc} */
/* @0x21df4c ldr r0, [pc, #0x4] */
/* @0x21df50 add r0, pc, r0 */
/* @0x21df54 pop {r3, pc} */
/* @0x21df58 andseq r2, r1, r0, ror r11 */

/* ── FUNC 0x21df5c · CAudioGroupMan::IncSoundCount(int) · size=28 · insn=7 */
/* @0x21df5c push {r3, lr} */
/* @0x21df60 bl 0x21df0c <_ZN14CAudioGroupMan8GetGroupEi> */
/* @0x21df64 cmp r0, #0 */
/* @0x21df68 ldrne r3, [r0, #0x8] */
/* @0x21df6c addne r3, r3, #1 */
/* @0x21df70 strne r3, [r0, #0x8] */
/* @0x21df74 pop {r3, pc} */

/* ── FUNC 0x21df78 · CAudioGroupMan::InitSoundLists(cARRAY_CLASS<cAudio_Sound*>&) · size=160 · insn=40 */
/* @0x21df78 push {r3, r4, r5, r6, r7, lr} */
/* @0x21df7c mov r7, r0 */
/* @0x21df80 ldr r3, [r0, #0x4] */
/* @0x21df84 mov r5, r1 */
/* @0x21df88 cmp r3, #0 */
/* @0x21df8c popeq {r3, r4, r5, r6, r7, pc} */
/* @0x21df90 ldr r3, [r1] */
/* @0x21df94 cmp r3, #0 */
/* @0x21df98 pople {r3, r4, r5, r6, r7, pc} */
/* @0x21df9c mov r4, #0 */
/* @0x21dfa0 ldr r2, [r5, #0x4] */
/* @0x21dfa4 mov r0, r7 */
/* @0x21dfa8 ldr r2, [r2, r4, lsl #2] */
/* @0x21dfac add r4, r4, #1 */
/* @0x21dfb0 cmp r2, #0 */
/* @0x21dfb4 beq 0x21dfc4 <_ZN14CAudioGroupMan14InitSoundListsER12cARRAY_CLASSIP12cAudio_SoundE+0x4c> */
/* @0x21dfb8 ldr r1, [r2, #0x4c] */
/* @0x21dfbc bl 0x21df5c <_ZN14CAudioGroupMan13IncSoundCountEi> */
/* @0x21dfc0 ldr r3, [r5] */
/* @0x21dfc4 cmp r3, r4 */
/* @0x21dfc8 bgt 0x21dfa0 <_ZN14CAudioGroupMan14InitSoundListsER12cARRAY_CLASSIP12cAudio_SoundE+0x28> */
/* @0x21dfcc cmp r3, #0 */
/* @0x21dfd0 pople {r3, r4, r5, r6, r7, pc} */
/* @0x21dfd4 mov r4, #0 */
/* @0x21dfd8 ldr r2, [r5, #0x4] */
/* @0x21dfdc mov r0, r7 */
/* @0x21dfe0 ldr r6, [r2, r4, lsl #2] */
/* @0x21dfe4 cmp r6, #0 */
/* @0x21dfe8 beq 0x21e008 <_ZN14CAudioGroupMan14InitSoundListsER12cARRAY_CLASSIP12cAudio_SoundE+0x90> */
/* @0x21dfec ldr r1, [r6, #0x4c] */
/* @0x21dff0 bl 0x21df0c <_ZN14CAudioGroupMan8GetGroupEi> */
/* @0x21dff4 mov r1, r6 */
/* @0x21dff8 cmp r0, #0 */
/* @0x21dffc beq 0x21e004 <_ZN14CAudioGroupMan14InitSoundListsER12cARRAY_CLASSIP12cAudio_SoundE+0x8c> */
/* @0x21e000 bl 0x21dc20 <_ZN11CAudioGroup8AddSoundEP12cAudio_Sound> */
/* @0x21e004 ldr r3, [r5] */
/* @0x21e008 add r4, r4, #1 */
/* @0x21e00c cmp r3, r4 */
/* @0x21e010 bgt 0x21dfd8 <_ZN14CAudioGroupMan14InitSoundListsER12cARRAY_CLASSIP12cAudio_SoundE+0x60> */
/* @0x21e014 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x21e018 · CAudioGroupMan::LoadGroup(int) · size=388 · insn=97 */
/* @0x21e018 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x21e01c subs r7, r1, #0 */
/* @0x21e020 ldr r4, [pc, #0x15c] */
/* @0x21e024 sub sp, sp, #148 */
/* @0x21e028 ldr r2, [pc, #0x158] */
/* @0x21e02c add r4, pc, r4 */
/* @0x21e030 ldr r5, [r4, r2] */
/* @0x21e034 ldr r2, [r5] */
/* @0x21e038 str r2, [sp, #0x8c] */
/* @0x21e03c bne 0x21e05c <_ZN14CAudioGroupMan9LoadGroupEi+0x44> */
/* @0x21e040 mov r0, #0 */
/* @0x21e044 ldr r2, [sp, #0x8c] */
/* @0x21e048 ldr r3, [r5] */
/* @0x21e04c cmp r2, r3 */
/* @0x21e050 bne 0x21e180 <_ZN14CAudioGroupMan9LoadGroupEi+0x168> */
/* @0x21e054 add sp, sp, #148 */
/* @0x21e058 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x21e05c bl 0x21df0c <_ZN14CAudioGroupMan8GetGroupEi> */
/* @0x21e060 subs r6, r0, #0 */
/* @0x21e064 beq 0x21e040 <_ZN14CAudioGroupMan9LoadGroupEi+0x28> */
/* @0x21e068 ldr r3, [r6, #0x8] */
/* @0x21e06c cmp r3, #0 */
/* @0x21e070 ble 0x21e040 <_ZN14CAudioGroupMan9LoadGroupEi+0x28> */
/* @0x21e074 ldr r8, [r6] */
/* @0x21e078 cmp r8, #0 */
/* @0x21e07c bne 0x21e040 <_ZN14CAudioGroupMan9LoadGroupEi+0x28> */
/* @0x21e080 add r10, sp, #12 */
/* @0x21e084 ldr r2, [pc, #0x100] */
/* @0x21e088 mov r1, #128 */
/* @0x21e08c mov r3, r7 */
/* @0x21e090 add r2, pc, r2 */
/* @0x21e094 mov r0, r10 */
/* @0x21e098 bl 0xb65c8 <snprintf@plt> */
/* @0x21e09c mov r0, r10 */
/* @0x21e0a0 mov r1, r8 */
/* @0x21e0a4 bl 0x18f848 <_ZN8LoadSave14ReadBundleFileEPKcPi> */
/* @0x21e0a8 subs r9, r0, #0 */
/* @0x21e0ac beq 0x21e154 <_ZN14CAudioGroupMan9LoadGroupEi+0x13c> */
/* @0x21e0b0 ldr r11, [r9, #0x8] */
/* @0x21e0b4 movw r3, #0x5541 */
/* @0x21e0b8 movt r3, #0x4f44 */
/* @0x21e0bc ldr r2, [r9, #0xc] */
/* @0x21e0c0 subs r3, r11, r3 */
/* @0x21e0c4 rsbs r11, r3, #0 */
/* @0x21e0c8 adcs r11, r11, r3 */
/* @0x21e0cc cmp r2, #0 */
/* @0x21e0d0 moveq r11, #0 */
/* @0x21e0d4 cmp r11, #0 */
/* @0x21e0d8 beq 0x21e120 <_ZN14CAudioGroupMan9LoadGroupEi+0x108> */
/* @0x21e0dc str r9, [r6, #0x18] */
/* @0x21e0e0 mov r0, r6 */
/* @0x21e0e4 mov r1, #1 */
/* @0x21e0e8 str r2, [sp, #0x4] */
/* @0x21e0ec bl 0x21dd48 <_ZN11CAudioGroup12SetLoadStateENS_10eLoadStateE> */
/* @0x21e0f0 ldr r2, [sp, #0x4] */
/* @0x21e0f4 mov r3, r7 */
/* @0x21e0f8 str r8, [r6, #0x10] */
/* @0x21e0fc str r8, [r6, #0x14] */
/* @0x21e100 add r0, r9, #16 */
/* @0x21e104 mov r1, r2 */
/* @0x21e108 mov r2, r9 */
/* @0x21e10c bl 0x219680 <_Z10Audio_WAVsPhjS_i> */
/* @0x21e110 mov r0, r6 */
/* @0x21e114 bl 0x21dcb8 <_ZN11CAudioGroup11AsyncDecodeEv> */
/* @0x21e118 mov r0, #1 */
/* @0x21e11c b 0x21e044 <_ZN14CAudioGroupMan9LoadGroupEi+0x2c> */
/* @0x21e120 ldr r3, [pc, #0x68] */
/* @0x21e124 mov r2, r10 */
/* @0x21e128 ldr r1, [pc, #0x64] */
/* @0x21e12c ldr r3, [r4, r3] */
/* @0x21e130 add r1, pc, r1 */
/* @0x21e134 ldr r0, [r3] */
/* @0x21e138 ldr r3, [r0] */
/* @0x21e13c ldr r3, [r3, #0xc] */
/* @0x21e140 blx r3 */
/* @0x21e144 mov r0, r9 */
/* @0x21e148 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21e14c mov r0, r11 */
/* @0x21e150 b 0x21e044 <_ZN14CAudioGroupMan9LoadGroupEi+0x2c> */
/* @0x21e154 ldr r3, [pc, #0x34] */
/* @0x21e158 mov r2, r10 */
/* @0x21e15c ldr r1, [pc, #0x34] */
/* @0x21e160 ldr r3, [r4, r3] */
/* @0x21e164 add r1, pc, r1 */
/* @0x21e168 ldr r0, [r3] */
/* @0x21e16c ldr r3, [r0] */
/* @0x21e170 ldr r3, [r3, #0xc] */
/* @0x21e174 blx r3 */
/* @0x21e178 mov r0, r9 */
/* @0x21e17c b 0x21e044 <_ZN14CAudioGroupMan9LoadGroupEi+0x2c> */
/* @0x21e180 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x21e184 andseq r3, sp, r4, lsr #24 */
/* @0x21e188 .word 0xffffbd00 */
/* @0x21e18c andseq r6, r3, r0, lsl #12 */
/* @0x21e190 .word 0xffffbac4 */
/* @0x21e194 andseq r6, r3, r8, lsl #11 */
/* @0x21e198 andseq r6, r3, r0, asr #10 */

/* ── FUNC 0x21e19c · CAudioGroupMan::UnloadGroup(int) · size=68 · insn=17 */
/* @0x21e19c push {r4, lr} */
/* @0x21e1a0 subs r4, r1, #0 */
/* @0x21e1a4 bne 0x21e1b0 <_ZN14CAudioGroupMan11UnloadGroupEi+0x14> */
/* @0x21e1a8 mov r0, #0 */
/* @0x21e1ac pop {r4, pc} */
/* @0x21e1b0 bl 0x21df0c <_ZN14CAudioGroupMan8GetGroupEi> */
/* @0x21e1b4 subs r3, r0, #0 */
/* @0x21e1b8 beq 0x21e1a8 <_ZN14CAudioGroupMan11UnloadGroupEi+0xc> */
/* @0x21e1bc ldr r3, [r3] */
/* @0x21e1c0 cmp r3, #2 */
/* @0x21e1c4 bne 0x21e1a8 <_ZN14CAudioGroupMan11UnloadGroupEi+0xc> */
/* @0x21e1c8 mov r1, #3 */
/* @0x21e1cc bl 0x21dd48 <_ZN11CAudioGroup12SetLoadStateENS_10eLoadStateE> */
/* @0x21e1d0 mov r0, r4 */
/* @0x21e1d4 bl 0x21ad0c <_Z18Audio_StopAllGroupi> */
/* @0x21e1d8 mov r0, #1 */
/* @0x21e1dc pop {r4, pc} */

/* ── FUNC 0x21e1e0 · CAudioGroupMan::IsGroupLoaded(int) · size=52 · insn=13 */
/* @0x21e1e0 cmp r1, #0 */
/* @0x21e1e4 push {r3, lr} */
/* @0x21e1e8 bne 0x21e1f4 <_ZN14CAudioGroupMan13IsGroupLoadedEi+0x14> */
/* @0x21e1ec mov r0, #1 */
/* @0x21e1f0 pop {r3, pc} */
/* @0x21e1f4 bl 0x21df0c <_ZN14CAudioGroupMan8GetGroupEi> */
/* @0x21e1f8 cmp r0, #0 */
/* @0x21e1fc popeq {r3, pc} */
/* @0x21e200 ldr r0, [r0] */
/* @0x21e204 subs r3, r0, #2 */
/* @0x21e208 rsbs r0, r3, #0 */
/* @0x21e20c adcs r0, r0, r3 */
/* @0x21e210 pop {r3, pc} */

/* ── FUNC 0x21e214 · anon_21e214 · size=4 · insn=1 */
/* @0x21e214 andeq r0, r0, r0 */

/* ── FUNC 0x21e218 · CAudioGroupMan::GetLoadProgress(int) · size=80 · insn=18 */
/* @0x21e218 cmp r1, #0 */
/* @0x21e21c push {r3, lr} */
/* @0x21e220 bne 0x21e230 <_ZN14CAudioGroupMan15GetLoadProgressEi+0x18> */
/* @0x21e224 vldr d7, [pc, #44] */
/* @0x21e228 vmov r0, r1, d7 */
/* @0x21e22c pop {r3, pc} */
/* @0x21e230 bl 0x21df0c <_ZN14CAudioGroupMan8GetGroupEi> */
/* @0x21e234 cmp r0, #0 */
/* @0x21e238 beq 0x21e250 <_ZN14CAudioGroupMan15GetLoadProgressEi+0x38> */
/* @0x21e23c bl 0x21dd9c <_ZN11CAudioGroup15GetLoadProgressEv> */
/* @0x21e240 vmov s13, r0 */
/* @0x21e244 vcvt.f64.s32 d7, s13 */
/* @0x21e248 vmov r0, r1, d7 */
/* @0x21e24c pop {r3, pc} */
/* @0x21e250 vldr d7, [pc, #8] */
/* @0x21e254 b 0x21e228 <_ZN14CAudioGroupMan15GetLoadProgressEi+0x10> */
/* @0x21e258 andeq r0, r0, r0 */
/* @0x21e25c subsmi r0, r9, r0 */

/* ── FUNC 0x21e268 · CAudioGroupMan::Update() · size=284 · insn=71 */
/* @0x21e268 ldr r2, [r0, #0x4] */
/* @0x21e26c push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x21e270 cmp r2, #1 */
/* @0x21e274 sub sp, sp, #24 */
/* @0x21e278 mov r6, r0 */
/* @0x21e27c ble 0x21e330 <_ZN14CAudioGroupMan6UpdateEv+0xc8> */
/* @0x21e280 ldr r9, [pc, #0xf0] */
/* @0x21e284 mov r4, #1 */
/* @0x21e288 ldr r8, [pc, #0xec] */
/* @0x21e28c ldr r7, [pc, #0xec] */
/* @0x21e290 add r9, pc, r9 */
/* @0x21e294 add r8, pc, r8 */
/* @0x21e298 add r7, pc, r7 */
/* @0x21e29c b 0x21e2ac <_ZN14CAudioGroupMan6UpdateEv+0x44> */
/* @0x21e2a0 add r4, r4, #1 */
/* @0x21e2a4 cmp r2, r4 */
/* @0x21e2a8 ble 0x21e330 <_ZN14CAudioGroupMan6UpdateEv+0xc8> */
/* @0x21e2ac ldr r3, [r6] */
/* @0x21e2b0 ldr r5, [r3, r4, lsl #2] */
/* @0x21e2b4 ldr r3, [r5] */
/* @0x21e2b8 cmp r3, #3 */
/* @0x21e2bc beq 0x21e338 <_ZN14CAudioGroupMan6UpdateEv+0xd0> */
/* @0x21e2c0 cmp r3, #1 */
/* @0x21e2c4 bne 0x21e2a0 <_ZN14CAudioGroupMan6UpdateEv+0x38> */
/* @0x21e2c8 ldr r3, [r5, #0x20] */
/* @0x21e2cc mov r0, r5 */
/* @0x21e2d0 mov r1, #2 */
/* @0x21e2d4 cmp r3, #0 */
/* @0x21e2d8 beq 0x21e2a0 <_ZN14CAudioGroupMan6UpdateEv+0x38> */
/* @0x21e2dc ldrb r3, [r3, #0x9] */
/* @0x21e2e0 ands r10, r3, #255 */
/* @0x21e2e4 bne 0x21e2a0 <_ZN14CAudioGroupMan6UpdateEv+0x38> */
/* @0x21e2e8 bl 0x21dd48 <_ZN11CAudioGroup12SetLoadStateENS_10eLoadStateE> */
/* @0x21e2ec str r8, [sp] */
/* @0x21e2f0 str r7, [sp, #0x4] */
/* @0x21e2f4 vldr s14, [r5, #4] */
/* @0x21e2f8 vcvt.f64.s32 d7, s14 */
/* @0x21e2fc mov r2, #0 */
/* @0x21e300 mov r1, r9 */
/* @0x21e304 mov r3, #0 */
/* @0x21e308 mov r0, #2 */
/* @0x21e30c str r10, [sp, #0x10] */
/* @0x21e310 add r4, r4, #1 */
/* @0x21e314 vstr d7, [sp, #8] */
/* @0x21e318 bl 0x20bdc0 <_Z11CreateDsMapiz> */
/* @0x21e31c mov r1, #72 */
/* @0x21e320 bl 0x18da04 <_Z24CreateAsynEventWithDSMapii> */
/* @0x21e324 ldr r2, [r6, #0x4] */
/* @0x21e328 cmp r2, r4 */
/* @0x21e32c bgt 0x21e2ac <_ZN14CAudioGroupMan6UpdateEv+0x44> */
/* @0x21e330 add sp, sp, #24 */
/* @0x21e334 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x21e338 ldr r0, [r5, #0x4] */
/* @0x21e33c bl 0x218ae0 <_Z27Audio_AllGroupSoundsStoppedi> */
/* @0x21e340 cmp r0, #0 */
/* @0x21e344 bne 0x21e350 <_ZN14CAudioGroupMan6UpdateEv+0xe8> */
/* @0x21e348 ldr r2, [r6, #0x4] */
/* @0x21e34c b 0x21e2a0 <_ZN14CAudioGroupMan6UpdateEv+0x38> */
/* @0x21e350 mov r0, r5 */
/* @0x21e354 bl 0x21dc80 <_ZN11CAudioGroup11FreeBuffersEv> */
/* @0x21e358 ldr r0, [r5, #0x18] */
/* @0x21e35c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21e360 mov r3, #0 */
/* @0x21e364 mov r1, r3 */
/* @0x21e368 str r3, [r5, #0x18] */
/* @0x21e36c mov r0, r5 */
/* @0x21e370 bl 0x21dd48 <_ZN11CAudioGroup12SetLoadStateENS_10eLoadStateE> */
/* @0x21e374 b 0x21e348 <_ZN14CAudioGroupMan6UpdateEv+0xe0> */
/* @0x21e378 mulseq r2, r8, lr */
/* @0x21e37c andseq r6, r3, r0, asr #8 */
/* @0x21e380 andseq r6, r3, r12, asr #8 */

/* ── FUNC 0x21e384 · YYAudioDrawDebug() · size=1076 · insn=269 */
/* @0x21e384 ldr r0, [pc, #0x408] */
/* @0x21e388 mvn r1, #-2147483648 */
/* @0x21e38c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x21e390 vpush {d8, d9, d10, d11, d12, d13} */
/* @0x21e394 add r0, pc, r0 */
/* @0x21e398 sub sp, sp, #68 */
/* @0x21e39c ldr r10, [pc, #0x3f4] */
/* @0x21e3a0 bl 0x17c49c <_ZN12GraphicsPerf8strwidthEPKci> */
/* @0x21e3a4 mvn r1, #-2147483648 */
/* @0x21e3a8 vmov s22, r0 */
/* @0x21e3ac ldr r0, [pc, #0x3e8] */
/* @0x21e3b0 add r0, pc, r0 */
/* @0x21e3b4 bl 0x17c49c <_ZN12GraphicsPerf8strwidthEPKci> */
/* @0x21e3b8 mvn r1, #-2147483648 */
/* @0x21e3bc vmov s23, r0 */
/* @0x21e3c0 ldr r0, [pc, #0x3d8] */
/* @0x21e3c4 add r0, pc, r0 */
/* @0x21e3c8 bl 0x17c49c <_ZN12GraphicsPerf8strwidthEPKci> */
/* @0x21e3cc ldr r10, [pc, r10] */
/* @0x21e3d0 ldr r3, [r10] */
/* @0x21e3d4 cmp r3, #0 */
/* @0x21e3d8 vmov s24, r0 */
/* @0x21e3dc ble 0x21e770 <_Z16YYAudioDrawDebugv+0x3ec> */
/* @0x21e3e0 ldr r11, [pc, #0x3bc] */
/* @0x21e3e4 mov r5, #0 */
/* @0x21e3e8 ldr r0, [pc, #0x3b8] */
/* @0x21e3ec movt r5, #0x42c8 */
/* @0x21e3f0 add r2, sp, #28 */
/* @0x21e3f4 ldr r11, [pc, r11] */
/* @0x21e3f8 add r0, pc, r0 */
/* @0x21e3fc vmov s21, r5 */
/* @0x21e400 str r0, [sp, #0xc] */
/* @0x21e404 mov r4, #0 */
/* @0x21e408 str r2, [sp, #0x8] */
/* @0x21e40c vldr s19, [pc, #880] */
/* @0x21e410 vldr s25, [pc, #880] */
/* @0x21e414 vldr s18, [pc, #880] */
/* @0x21e418 vldr s17, [pc, #880] */
/* @0x21e41c b 0x21e430 <_Z16YYAudioDrawDebugv+0xac> */
/* @0x21e420 ldr r3, [r10] */
/* @0x21e424 add r4, r4, #1 */
/* @0x21e428 cmp r3, r4 */
/* @0x21e42c ble 0x21e770 <_Z16YYAudioDrawDebugv+0x3ec> */
/* @0x21e430 ldr r3, [r11] */
/* @0x21e434 add r2, sp, #28 */
/* @0x21e438 mvn r6, #0 */
/* @0x21e43c movw r1, #0x1010 */
/* @0x21e440 str r6, [sp, #0x1c] */
/* @0x21e444 ldr r0, [r3, r4, lsl #2] */
/* @0x21e448 bl 0xb6a9c <alGetSourcei@plt> */
/* @0x21e44c ldr r2, [sp, #0x1c] */
/* @0x21e450 movw r3, #0x1012 */
/* @0x21e454 cmp r2, r3 */
/* @0x21e458 bne 0x21e420 <_Z16YYAudioDrawDebugv+0x9c> */
/* @0x21e45c ldr r3, [r11] */
/* @0x21e460 add r2, sp, #64 */
/* @0x21e464 mov r9, #0 */
/* @0x21e468 movw r1, #0x1015 */
/* @0x21e46c str r9, [r2, #-0x20]! */
/* @0x21e470 vmov.f32 s16, #1.000000e+01 */
/* @0x21e474 ldr r0, [r3, r4, lsl #2] */
/* @0x21e478 bl 0xb6a9c <alGetSourcei@plt> */
/* @0x21e47c ldr r3, [r11] */
/* @0x21e480 add r2, sp, #64 */
/* @0x21e484 movw r1, #0x1016 */
/* @0x21e488 str r9, [r2, #-0x1c]! */
/* @0x21e48c ldr r0, [r3, r4, lsl #2] */
/* @0x21e490 bl 0xb6a9c <alGetSourcei@plt> */
/* @0x21e494 ldr r3, [r11] */
/* @0x21e498 add r2, sp, #64 */
/* @0x21e49c movw r1, #0x1009 */
/* @0x21e4a0 str r6, [r2, #-0x18]! */
/* @0x21e4a4 ldr r0, [r3, r4, lsl #2] */
/* @0x21e4a8 bl 0xb6a9c <alGetSourcei@plt> */
/* @0x21e4ac ldr r0, [sp, #0x28] */
/* @0x21e4b0 movw r1, #0x2004 */
/* @0x21e4b4 add r2, sp, #44 */
/* @0x21e4b8 str r9, [sp, #0x2c] */
/* @0x21e4bc bl 0xb6ac0 <alGetBufferi@plt> */
/* @0x21e4c0 ldr r3, [sp, #0xc] */
/* @0x21e4c4 mov r2, #267386880 */
/* @0x21e4c8 ldr lr, [pc, #0x2dc] */
/* @0x21e4cc mov r1, r5 */
/* @0x21e4d0 mov r0, #0 */
/* @0x21e4d4 movt r0, #0x4120 */
/* @0x21e4d8 str r3, [sp] */
/* @0x21e4dc mov r3, r6 */
/* @0x21e4e0 ldr r12, [r11] */
/* @0x21e4e4 str lr, [sp, #0x10] */
/* @0x21e4e8 ldr r12, [r12, r4, lsl #2] */
/* @0x21e4ec str r12, [sp, #0x4] */
/* @0x21e4f0 bl 0x17c2f8 <_ZN12GraphicsPerf7oprintfEffjjPKcz> */
/* @0x21e4f4 vcvt.f32.s32 s26, s24 */
/* @0x21e4f8 ldr r0, [sp, #0x28] */
/* @0x21e4fc mov r2, #267386880 */
/* @0x21e500 ldr r3, [sp, #0xc] */
/* @0x21e504 mov r1, r5 */
/* @0x21e508 str r0, [sp, #0x4] */
/* @0x21e50c str r3, [sp] */
/* @0x21e510 mov r3, r6 */
/* @0x21e514 vadd.f32 s26, s26, s19 */
/* @0x21e518 vadd.f32 s16, s26, s16 */
/* @0x21e51c vmov r0, s16 */
/* @0x21e520 bl 0x17c2f8 <_ZN12GraphicsPerf7oprintfEffjjPKcz> */
/* @0x21e524 vadd.f32 s16, s26, s16 */
/* @0x21e528 ldr lr, [sp, #0xc] */
/* @0x21e52c mov r2, #267386880 */
/* @0x21e530 ldr r0, [sp, #0x24] */
/* @0x21e534 mov r3, r6 */
/* @0x21e538 mov r1, r5 */
/* @0x21e53c str lr, [sp] */
/* @0x21e540 str r0, [sp, #0x4] */
/* @0x21e544 vmov r0, s16 */
/* @0x21e548 bl 0x17c2f8 <_ZN12GraphicsPerf7oprintfEffjjPKcz> */
/* @0x21e54c vcvt.f32.s32 s20, s22 */
/* @0x21e550 ldr r0, [sp, #0x20] */
/* @0x21e554 mov r2, #267386880 */
/* @0x21e558 ldr r3, [sp, #0xc] */
/* @0x21e55c mov r1, r5 */
/* @0x21e560 str r0, [sp, #0x4] */
/* @0x21e564 str r3, [sp] */
/* @0x21e568 mov r3, r6 */
/* @0x21e56c vadd.f32 s20, s20, s19 */
/* @0x21e570 vadd.f32 s16, s20, s16 */
/* @0x21e574 vmov r0, s16 */
/* @0x21e578 bl 0x17c2f8 <_ZN12GraphicsPerf7oprintfEffjjPKcz> */
/* @0x21e57c vmov lr, s19 */
/* @0x21e580 ldr r3, [r11] */
/* @0x21e584 add r2, sp, #64 */
/* @0x21e588 movw r1, #0x100a */
/* @0x21e58c vadd.f32 s20, s20, s16 */
/* @0x21e590 ldr r0, [r3, r4, lsl #2] */
/* @0x21e594 str lr, [r2, #-0x10]! */
/* @0x21e598 bl 0xb6acc <alGetSourcef@plt> */
/* @0x21e59c vldr s15, [sp, #48] */
/* @0x21e5a0 vmul.f32 s15, s15, s25 */
/* @0x21e5a4 ldr r0, [sp, #0xc] */
/* @0x21e5a8 mov r2, #267386880 */
/* @0x21e5ac mov r1, r5 */
/* @0x21e5b0 mov r3, r6 */
/* @0x21e5b4 str r0, [sp] */
/* @0x21e5b8 vmov r0, s20 */
/* @0x21e5bc vcvt.s32.f32 s15, s15 */
/* @0x21e5c0 vstr s15, [sp, #4] */
/* @0x21e5c4 bl 0x17c2f8 <_ZN12GraphicsPerf7oprintfEffjjPKcz> */
/* @0x21e5c8 vcvt.f32.s32 s16, s23 */
/* @0x21e5cc ldr r3, [r11] */
/* @0x21e5d0 add r2, sp, #64 */
/* @0x21e5d4 movw r1, #0x1025 */
/* @0x21e5d8 str r9, [r2, #-0xc]! */
/* @0x21e5dc ldr r0, [r3, r4, lsl #2] */
/* @0x21e5e0 bl 0xb6a9c <alGetSourcei@plt> */
/* @0x21e5e4 ldr r0, [sp, #0x28] */
/* @0x21e5e8 movw r1, #0x2002 */
/* @0x21e5ec add r2, sp, #56 */
/* @0x21e5f0 vadd.f32 s16, s16, s19 */
/* @0x21e5f4 str r9, [sp, #0x38] */
/* @0x21e5f8 bl 0xb6ac0 <alGetBufferi@plt> */
/* @0x21e5fc ldr r3, [sp, #0x38] */
/* @0x21e600 ldr r0, [sp, #0x28] */
/* @0x21e604 movw r1, #0x2003 */
/* @0x21e608 cmp r3, r9 */
/* @0x21e60c add r2, r3, #7 */
/* @0x21e610 str r9, [sp, #0x3c] */
/* @0x21e614 movlt r3, r2 */
/* @0x21e618 add r2, sp, #60 */
/* @0x21e61c asr r3, r3, #3 */
/* @0x21e620 vadd.f32 s16, s16, s20 */
/* @0x21e624 vmov s20, r3 */
/* @0x21e628 bl 0xb6ac0 <alGetBufferi@plt> */
/* @0x21e62c ldr r1, [sp, #0x34] */
/* @0x21e630 mov r2, #267386880 */
/* @0x21e634 ldr r12, [pc, #0x174] */
/* @0x21e638 mov r3, r6 */
/* @0x21e63c add r12, pc, r12 */
/* @0x21e640 str r1, [sp, #0x4] */
/* @0x21e644 str r12, [sp] */
/* @0x21e648 mov r1, r5 */
/* @0x21e64c vmov r0, s16 */
/* @0x21e650 bl 0x17c2f8 <_ZN12GraphicsPerf7oprintfEffjjPKcz> */
/* @0x21e654 ldr r2, [sp, #0x10] */
/* @0x21e658 ldr r3, [sp, #0x20] */
/* @0x21e65c vadd.f32 s16, s26, s16 */
/* @0x21e660 ldr r2, [pc, r2] */
/* @0x21e664 str r2, [sp, #0x10] */
/* @0x21e668 cmp r3, r9 */
/* @0x21e66c ldr r7, [r2] */
/* @0x21e670 ble 0x21e77c <_Z16YYAudioDrawDebugv+0x3f8> */
/* @0x21e674 ldr r8, [pc, #0x138] */
/* @0x21e678 mov r12, #255 */
/* @0x21e67c movt r12, #0xff00 */
/* @0x21e680 str r4, [sp, #0x14] */
/* @0x21e684 add r8, pc, r8 */
/* @0x21e688 mov r4, r9 */
/* @0x21e68c mov r9, r12 */
/* @0x21e690 b 0x21e6a4 <_Z16YYAudioDrawDebugv+0x320> */
/* @0x21e694 ldr r3, [sp, #0x20] */
/* @0x21e698 vadd.f32 s16, s16, s17 */
/* @0x21e69c cmp r3, r4 */
/* @0x21e6a0 ble 0x21e748 <_Z16YYAudioDrawDebugv+0x3c4> */
/* @0x21e6a4 vmov r0, s16 */
/* @0x21e6a8 mov r1, r5 */
/* @0x21e6ac mov r3, r7 */
/* @0x21e6b0 str r6, [sp] */
/* @0x21e6b4 mov r2, #0 */
/* @0x21e6b8 movt r2, #0x42c8 */
/* @0x21e6bc bl 0x17b83c <_ZN12GraphicsPerf15RenderRectangleEffffj> */
/* @0x21e6c0 str r4, [sp, #0x4] */
/* @0x21e6c4 vadd.f32 s13, s16, s18 */
/* @0x21e6c8 str r8, [sp] */
/* @0x21e6cc mov r3, #255 */
/* @0x21e6d0 mov r1, r5 */
/* @0x21e6d4 movt r3, #0xff00 */
/* @0x21e6d8 mov r2, #267386880 */
/* @0x21e6dc vmov r0, s13 */
/* @0x21e6e0 bl 0x17c2f8 <_ZN12GraphicsPerf7oprintfEffjjPKcz> */
/* @0x21e6e4 cmp r4, #0 */
/* @0x21e6e8 add r4, r4, #1 */
/* @0x21e6ec bne 0x21e694 <_Z16YYAudioDrawDebugv+0x310> */
/* @0x21e6f0 vldr s14, [sp, #52] */
/* @0x21e6f4 vcvt.f32.s32 s15, s14 */
/* @0x21e6f8 vldr s13, [sp, #60] */
/* @0x21e6fc mov r3, r7 */
/* @0x21e700 str r9, [sp] */
/* @0x21e704 mov r2, #1065353216 */
/* @0x21e708 mov r1, r5 */
/* @0x21e70c vmul.f32 s15, s15, s21 */
/* @0x21e710 vcvt.f32.s32 s14, s20 */
/* @0x21e714 vmul.f32 s15, s15, s14 */
/* @0x21e718 vcvt.f32.s32 s14, s13 */
/* @0x21e71c vldr s13, [sp, #44] */
/* @0x21e720 vmul.f32 s15, s15, s14 */
/* @0x21e724 vcvt.f32.s32 s14, s13 */
/* @0x21e728 vdiv.f32 s15, s15, s14 */
/* @0x21e72c vadd.f32 s15, s15, s16 */
/* @0x21e730 vmov r0, s15 */
/* @0x21e734 bl 0x17b83c <_ZN12GraphicsPerf15RenderRectangleEffffj> */
/* @0x21e738 ldr r3, [sp, #0x20] */
/* @0x21e73c vadd.f32 s16, s16, s17 */
/* @0x21e740 cmp r3, r4 */
/* @0x21e744 bgt 0x21e6a4 <_Z16YYAudioDrawDebugv+0x320> */
/* @0x21e748 ldr r4, [sp, #0x14] */
/* @0x21e74c ldr r0, [sp, #0x10] */
/* @0x21e750 vldr s15, [r0] */
/* @0x21e754 vmov s13, r5 */
/* @0x21e758 ldr r3, [r10] */
/* @0x21e75c add r4, r4, #1 */
/* @0x21e760 vadd.f32 s13, s13, s15 */
/* @0x21e764 cmp r3, r4 */
/* @0x21e768 vmov r5, s13 */
/* @0x21e76c bgt 0x21e430 <_Z16YYAudioDrawDebugv+0xac> */
/* @0x21e770 add sp, sp, #68 */
/* @0x21e774 vpop {d8, d9, d10, d11, d12, d13} */
/* @0x21e778 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x21e77c vmov s15, r7 */
/* @0x21e780 b 0x21e754 <_Z16YYAudioDrawDebugv+0x3d0> */
/* @0x21e784 andeq r0, r0, r0 */
/* @0x21e788 strmi r0, [r0, r0] */
/* @0x21e78c eormi r0, r0, #0 */
/* @0x21e790 sbcsmi r0, r2, #0 */
/* @0x21e794 andseq r6, r3, r12, lsl #7 */
/* @0x21e798 andseq r3, sp, r4 */
/* @0x21e79c andseq r6, r3, r4, ror r3 */
/* @0x21e7a0 andseq r6, r3, r8, ror #6 */
/* @0x21e7a4 ldrsbeq r2, [sp], -r8 */
/* @0x21e7a8 andseq r4, r1, r4, lsl r1 */
/* @0x21e7ac ldrsbeq r1, [sp], -r4 */
/* @0x21e7b0 andseq r3, r1, r0, ror r11 */
/* @0x21e7b4 andseq r3, r1, r8, lsl #29 */

/* ── FUNC 0x21e7b8 · cARRAY_STRUCTURE<RSoundSample>::~cARRAY_STRUCTURE() · size=60 · insn=15 */
/* @0x21e7b8 push {r3, r4, r5, lr} */
/* @0x21e7bc mov r4, r0 */
/* @0x21e7c0 ldr r5, [r0, #0x4] */
/* @0x21e7c4 subs r0, r5, #0 */
/* @0x21e7c8 beq 0x21e7e8 <_ZN16cARRAY_STRUCTUREI12RSoundSampleED2Ev+0x30> */
/* @0x21e7cc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21e7d0 mov r3, #0 */
/* @0x21e7d4 str r3, [r4, #0x4] */
/* @0x21e7d8 mov r3, #0 */
/* @0x21e7dc mov r0, r4 */
/* @0x21e7e0 str r3, [r4] */
/* @0x21e7e4 pop {r3, r4, r5, pc} */
/* @0x21e7e8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21e7ec str r5, [r4, #0x4] */
/* @0x21e7f0 b 0x21e7d8 <_ZN16cARRAY_STRUCTUREI12RSoundSampleED2Ev+0x20> */

/* ── FUNC 0x21e7b8 · cARRAY_STRUCTURE<RSoundSample>::~cARRAY_STRUCTURE() · alias of the symbol above · insn=0 */

/* ── FUNC 0x21e7f4 · SND_AddEmpty(int) · size=332 · insn=83 */
/* @0x21e7f4 ldr r3, [pc, #0x134] */
/* @0x21e7f8 ldr r2, [pc, #0x134] */
/* @0x21e7fc add r3, pc, r3 */
/* @0x21e800 push {r4, r6, r7, r8, r9, r10, lr} */
/* @0x21e804 mov r6, r0 */
/* @0x21e808 ldr r7, [r3, r2] */
/* @0x21e80c sub sp, sp, #12 */
/* @0x21e810 ldr r2, [pc, #0x120] */
/* @0x21e814 ldr r12, [r7] */
/* @0x21e818 ldr r8, [r3, r2] */
/* @0x21e81c cmp r12, #0 */
/* @0x21e820 ble 0x21e918 <_Z12SND_AddEmptyi+0x124> */
/* @0x21e824 ldr r0, [r8, #0x4] */
/* @0x21e828 ldrb r4, [r0] */
/* @0x21e82c cmp r4, #0 */
/* @0x21e830 beq 0x21e928 <_Z12SND_AddEmptyi+0x134> */
/* @0x21e834 add r3, r0, #20 */
/* @0x21e838 mov r4, #0 */
/* @0x21e83c b 0x21e84c <_Z12SND_AddEmptyi+0x58> */
/* @0x21e840 ldrb r2, [r3], #20 */
/* @0x21e844 cmp r2, #0 */
/* @0x21e848 beq 0x21e8d4 <_Z12SND_AddEmptyi+0xe0> */
/* @0x21e84c add r4, r4, #1 */
/* @0x21e850 mov r1, r3 */
/* @0x21e854 cmp r4, r12 */
/* @0x21e858 bne 0x21e840 <_Z12SND_AddEmptyi+0x4c> */
/* @0x21e85c add r12, r4, r4, lsl #2 */
/* @0x21e860 adds r9, r4, #1 */
/* @0x21e864 lsl r10, r12, #2 */
/* @0x21e868 bne 0x21e894 <_Z12SND_AddEmptyi+0xa0> */
/* @0x21e86c cmp r0, #0 */
/* @0x21e870 beq 0x21e904 <_Z12SND_AddEmptyi+0x110> */
/* @0x21e874 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21e878 str r9, [r8, #0x4] */
/* @0x21e87c mov r1, r9 */
/* @0x21e880 b 0x21e8c0 <_Z12SND_AddEmptyi+0xcc> */
/* @0x21e884 mov r10, r12 */
/* @0x21e888 mov r0, r1 */
/* @0x21e88c mov r4, r12 */
/* @0x21e890 mov r9, #1 */
/* @0x21e894 add r3, r9, r9, lsl #2 */
/* @0x21e898 lsls r1, r3, #2 */
/* @0x21e89c beq 0x21e904 <_Z12SND_AddEmptyi+0x110> */
/* @0x21e8a0 ldr r2, [pc, #0x94] */
/* @0x21e8a4 mov r3, #0 */
/* @0x21e8a8 str r3, [sp] */
/* @0x21e8ac mov r3, #106 */
/* @0x21e8b0 add r2, pc, r2 */
/* @0x21e8b4 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x21e8b8 mov r1, r0 */
/* @0x21e8bc str r0, [r8, #0x4] */
/* @0x21e8c0 ldr r3, [r7] */
/* @0x21e8c4 add r1, r1, r10 */
/* @0x21e8c8 str r9, [r8] */
/* @0x21e8cc add r3, r3, #1 */
/* @0x21e8d0 str r3, [r7] */
/* @0x21e8d4 mov r3, #0 */
/* @0x21e8d8 mov r2, #1 */
/* @0x21e8dc cmp r6, #3 */
/* @0x21e8e0 str r6, [r1, #0x4] */
/* @0x21e8e4 mov r0, r4 */
/* @0x21e8e8 strb r2, [r1] */
/* @0x21e8ec strb r3, [r1, #0x1] */
/* @0x21e8f0 str r3, [r1, #0x8] */
/* @0x21e8f4 str r3, [r1, #0xc] */
/* @0x21e8f8 streq r2, [r1, #0x4] */
/* @0x21e8fc add sp, sp, #12 */
/* @0x21e900 pop {r4, r6, r7, r8, r9, r10, pc} */
/* @0x21e904 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21e908 mov r3, #0 */
/* @0x21e90c mov r1, r3 */
/* @0x21e910 str r3, [r8, #0x4] */
/* @0x21e914 b 0x21e8c0 <_Z12SND_AddEmptyi+0xcc> */
/* @0x21e918 ldr r1, [r8, #0x4] */
/* @0x21e91c beq 0x21e884 <_Z12SND_AddEmptyi+0x90> */
/* @0x21e920 mov r4, #0 */
/* @0x21e924 b 0x21e8d4 <_Z12SND_AddEmptyi+0xe0> */
/* @0x21e928 mov r1, r0 */
/* @0x21e92c b 0x21e8d4 <_Z12SND_AddEmptyi+0xe0> */
/* @0x21e930 andseq r3, sp, r4, asr r4 */
/* @0x21e934 .word 0xfffff7c4 */
/* @0x21e938 .word 0xfffff7c8 */
/* @0x21e93c andseq r5, r3, r8, lsl #29 */

/* ── FUNC 0x21e940 · SND_Init() · size=144 · insn=36 */
/* @0x21e940 push {r3, r4, r5, lr} */
/* @0x21e944 mov r0, #4 */
/* @0x21e948 bl 0x27c524 <_Znwj> */
/* @0x21e94c ldr r4, [pc, #0x6c] */
/* @0x21e950 mov r5, r0 */
/* @0x21e954 bl 0x220188 <_ZN13SoundHardwareC2Ev> */
/* @0x21e958 ldr r3, [pc, #0x64] */
/* @0x21e95c mov r0, r5 */
/* @0x21e960 add r3, pc, r3 */
/* @0x21e964 str r5, [r3] */
/* @0x21e968 bl 0x22021c <_ZN13SoundHardware4InitEv> */
/* @0x21e96c ldr r4, [pc, r4] */
/* @0x21e970 ldr r5, [r4, #0x4] */
/* @0x21e974 subs r0, r5, #0 */
/* @0x21e978 beq 0x21e9b4 <_Z8SND_Initv+0x74> */
/* @0x21e97c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21e980 mov r3, #0 */
/* @0x21e984 str r3, [r4, #0x4] */
/* @0x21e988 ldr r2, [pc, #0x38] */
/* @0x21e98c mov r5, #0 */
/* @0x21e990 ldr r3, [pc, #0x34] */
/* @0x21e994 add r2, pc, r2 */
/* @0x21e998 str r5, [r4] */
/* @0x21e99c ldr r3, [pc, r3] */
/* @0x21e9a0 ldr r0, [r2] */
/* @0x21e9a4 str r5, [r3] */
/* @0x21e9a8 bl 0x2166bc <_Z10Audio_InitP13SoundHardware> */
/* @0x21e9ac mov r0, r5 */
/* @0x21e9b0 pop {r3, r4, r5, pc} */
/* @0x21e9b4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21e9b8 str r5, [r4, #0x4] */
/* @0x21e9bc b 0x21e988 <_Z8SND_Initv+0x48> */
/* @0x21e9c0 andseq r2, sp, r12, lsr #21 */
/* @0x21e9c4 subseq r6, r3, r4, asr #19 */
/* @0x21e9c8 .word 0x00536990 */
/* @0x21e9cc andseq r2, sp, r8, ror r10 */

/* ── FUNC 0x21e9d0 · SND_End() · size=28 · insn=7 */
/* @0x21e9d0 push {r3, lr} */
/* @0x21e9d4 ldr r3, [pc, #0xc] */
/* @0x21e9d8 ldr r0, [pc, r3] */
/* @0x21e9dc bl 0x220324 <_ZN13SoundHardware4QuitEv> */
/* @0x21e9e0 mov r0, #1 */
/* @0x21e9e4 pop {r3, pc} */
/* @0x21e9e8 subseq r6, r3, r12, asr #18 */

/* ── FUNC 0x21e9ec · SND_Set_Search_Directory(char const*) · size=4 · insn=1 */
/* @0x21e9ec bx lr */

/* ── FUNC 0x21e9f0 · SND_AddFromFile(char const*, int) · size=8 · insn=2 */
/* @0x21e9f0 mvn r0, #0 */
/* @0x21e9f4 bx lr */
