/* cally 逆向卡：All_59 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 212 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/212 Facebook_Setup(IniFile*)  0x1de8e8  size 148  37 条（0x1de8e8..0x1de97c）
 * @func 0x1de8e8 0x1de97c  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IniFile::GetKey(char const*, char const*) / 0xb6538 / MemoryManager::Alloc(unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x8×3 / 0x74×2 / 0x5c×2 / 0xc×1 / 0x38×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1de8e8 ldr r1, [pc, #0x74]
 *   @0x1de8ec ldr r2, [pc, #0x74]
 *   @0x1de8f0 push {r4, lr}
 *   @0x1de8f4 add r1, pc, r1
 *   @0x1de8f8 add r2, pc, r2
 *   @0x1de8fc bl 0x235ad0 <_ZN7IniFile6GetKeyEPKcS1_>
 *   @0x1de900 subs r4, r0, #0
 *   @0x1de904 popeq {r4, pc}
 *   @0x1de908 ldr r3, [pc, #0x5c]
 *   @0x1de90c ldr r1, [pc, #0x5c]
 *   @0x1de910 ldr r3, [pc, r3]
 *   @0x1de914 ldr r2, [r4, #0x8]
 *   @0x1de918 add r1, pc, r1
 *   @0x1de91c ldr r0, [r3]
 *   @0x1de920 ldr r3, [r0]
 *   @0x1de924 ldr r3, [r3, #0xc]
 *   @0x1de928 blx r3
 *   @0x1de92c ldr r0, [r4, #0x8]
 *   @0x1de930 bl 0xb6538 <strlen@plt>
 *   @0x1de934 ldr r1, [pc, #0x38]
 *   @0x1de938 mov r3, #1
 *   @0x1de93c movw r2, #0x72c
 *   @0x1de940 add r1, pc, r1
 *   @0x1de944 add r0, r0, r3
 *   @0x1de948 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1de94c ldr r3, [pc, #0x24]
 *   @0x1de950 ldr r1, [r4, #0x8]
 *   @0x1de954 ldr r3, [pc, r3]
 *   @0x1de958 pop {r4, lr}
 *   @0x1de95c str r0, [r3]
 *   @0x1de960 b 0xb65a4 <strcpy@plt>
 *   @0x1de964 andseq r2, r7, r0, lsl #30
 *   @0x1de968 andseq r2, r7, r4, lsl #30
 *   @0x1de96c eoreq lr, r0, r4, lsl #28
 *   @0x1de970 ldrsheq r2, [r7], -r0
 *   @0x1de974 andseq r2, r7, r4, ror #29
 *   @0x1de978 eoreq r1, r1, r4, asr r5
 *
 * ══ §2/212 Script_Find_Parent(char const*)  0x1e06dc  size 148  37 条（0x1e06dc..0x1e0770）
 * @func 0x1e06dc 0x1e0770  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Script_Find(char const*) / Script_Data(int)
 * 字段偏移 top8: 0x8×2 / 0x50×2 / 0x10×2 / 0x68×1 / 0x58×1 / 0x4×1 / 0x-4×1 / 0x6c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e06dc push {r3, r4, r5, lr}
 *   @0x1e06e0 bl 0x1e0610 <_Z11Script_FindPKc>
 *   @0x1e06e4 cmn r0, #1
 *   @0x1e06e8 beq 0x1e0760 <_Z18Script_Find_ParentPKc+0x84>
 *   @0x1e06ec bl 0x1e069c <_Z11Script_Datai>
 *   @0x1e06f0 subs r5, r0, #0
 *   @0x1e06f4 beq 0x1e0760 <_Z18Script_Find_ParentPKc+0x84>
 *   @0x1e06f8 ldr r3, [pc, #0x68]
 *   @0x1e06fc ldr r3, [pc, r3]
 *   @0x1e0700 ldr r2, [r3]
 *   @0x1e0704 subs r3, r2, #1
 *   @0x1e0708 bmi 0x1e0760 <_Z18Script_Find_ParentPKc+0x84>
 *   @0x1e070c ldr r1, [pc, #0x58]
 *   @0x1e0710 ldr r1, [pc, r1]
 *   @0x1e0714 ldr r1, [r1, #0x4]
 *   @0x1e0718 add r1, r1, r2, lsl #2
 *   @0x1e071c ldr r0, [r1, #-0x4]!
 *   @0x1e0720 sub r3, r3, #1
 *   @0x1e0724 cmp r0, #0
 *   @0x1e0728 beq 0x1e0758 <_Z18Script_Find_ParentPKc+0x7c>
 *   @0x1e072c ldr r2, [r0, #0x8]
 *   @0x1e0730 ldr r12, [r2, #0x6c]
 *   @0x1e0734 cmp r12, #0
 *   @0x1e0738 bne 0x1e0758 <_Z18Script_Find_ParentPKc+0x7c>
 *   @0x1e073c ldr r4, [r5, #0x8]
 *   @0x1e0740 ldr r12, [r2, #0x50]
 *   @0x1e0744 ldr r2, [r4, #0x50]
 *   @0x1e0748 ldr r12, [r12, #0x10]
 *   @0x1e074c ldr r2, [r2, #0x10]
 *   @0x1e0750 cmp r12, r2
 *   @0x1e0754 popeq {r3, r4, r5, pc}
 *   @0x1e0758 cmn r3, #1
 *   @0x1e075c bne 0x1e071c <_Z18Script_Find_ParentPKc+0x40>
 *   @0x1e0760 mov r0, #0
 *   @0x1e0764 pop {r3, r4, r5, pc}
 *   @0x1e0768 eoreq r0, r1, r0, lsr r6
 *   @0x1e076c eoreq r0, r1, r8, lsl r6
 *
 * ══ §3/212 FINALIZE_Sprite_Main()  0x1ef514  size 148  37 条（0x1ef514..0x1ef5a8）
 * @func 0x1ef514 0x1ef5a8  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1ef51c→0x7530d8, 0x1ef530→0x7530dc
 * 调用序列: MemoryManager::Free(void const*)×2 / FINALIZE_Sprite_Main()+0x7c / Sprite_FreeTextures()
 * 字段偏移 top8: 0x7c×2 / 0x2×2 / 0x6c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1ef514 push {r3, r4, r5, r6, r7, lr}
 *   @0x1ef518 ldr r3, [pc, #0x7c]
 *   @0x1ef51c ldr r2, [pc, #0x7c]
 *   @0x1ef520 add r3, pc, r3
 *   @0x1ef524 ldr r6, [r3, r2]
 *   @0x1ef528 ldr r2, [r6]
 *   @0x1ef52c cmp r2, #0
 *   @0x1ef530 ldr r2, [pc, #0x6c]
 *   @0x1ef534 ble 0x1ef590 <_Z20FINALIZE_Sprite_Mainv+0x7c>
 *   @0x1ef538 ldr r5, [r3, r2]
 *   @0x1ef53c mov r4, #0
 *   @0x1ef540 mov r7, r4
 *   @0x1ef544 ldr r2, [r5]
 *   @0x1ef548 ldr r0, [r2, r4, lsl #2]
 *   @0x1ef54c cmp r0, #0
 *   @0x1ef550 beq 0x1ef564 <_Z20FINALIZE_Sprite_Mainv+0x50>
 *   @0x1ef554 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1ef558 ldr r3, [r5]
 *   @0x1ef55c str r7, [r3, r4, lsl #2]
 *   @0x1ef560 ldr r2, [r5]
 *   @0x1ef564 ldr r3, [r6]
 *   @0x1ef568 add r4, r4, #1
 *   @0x1ef56c cmp r3, r4
 *   @0x1ef570 bgt 0x1ef548 <_Z20FINALIZE_Sprite_Mainv+0x34>
 *   @0x1ef574 mov r0, r2
 *   @0x1ef578 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1ef57c mov r3, #0
 *   @0x1ef580 str r3, [r5]
 *   @0x1ef584 bl 0x1eee30 <_Z19Sprite_FreeTexturesv>
 *   @0x1ef588 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1ef58c b 0x1eed3c <_Z11Sprite_Freev>
 *   @0x1ef590 ldr r5, [r3, r2]
 *   @0x1ef594 ldr r2, [r5]
 *   @0x1ef598 b 0x1ef574 <_Z20FINALIZE_Sprite_Mainv+0x60>
 *   @0x1ef59c eoreq r2, r0, r0, lsr r7
 *   @0x1ef5a0 .word 0xfffff1c0
 *   @0x1ef5a4 .word 0xfffff1bc
 *
 * ══ §4/212 Timing_Sleep  0x2151f0  size 148  37 条（0x2151f0..0x215284）
 * @func 0x2151f0 0x215284  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Timing_Time×3 / Timing_Sleep+0x64 / 0xb6a18
 * 字段偏移 top8: 0x6c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2151f0 push {r3, r4, r5, r6, r7, lr}
 *   @0x2151f4 mov r6, r0
 *   @0x2151f8 mov r7, r1
 *   @0x2151fc cmp r6, #1
 *   @0x215200 sbcs r1, r7, #0
 *   @0x215204 poplt {r3, r4, r5, r6, r7, pc}
 *   @0x215208 bl 0x215148 <Timing_Time>
 *   @0x21520c ldr r3, [pc, #0x6c]
 *   @0x215210 mov r2, #1000
 *   @0x215214 ldr r3, [pc, r3]
 *   @0x215218 ldr r12, [r3]
 *   @0x21521c mul r2, r2, r12
 *   @0x215220 asr r3, r2, #31
 *   @0x215224 adds r4, r0, r6
 *   @0x215228 adc r5, r1, r7
 *   @0x21522c cmp r2, r6
 *   @0x215230 sbcs r1, r3, r7
 *   @0x215234 blt 0x215254 <Timing_Sleep+0x64>
 *   @0x215238 bl 0x215148 <Timing_Time>
 *   @0x21523c subs r0, r4, r0
 *   @0x215240 sbc r1, r5, r1
 *   @0x215244 cmp r0, #1
 *   @0x215248 sbcs r3, r1, #0
 *   @0x21524c bge 0x215238 <Timing_Sleep+0x48>
 *   @0x215250 pop {r3, r4, r5, r6, r7, pc}
 *   @0x215254 movw r0, #0xfc18
 *   @0x215258 movt r0, #0xffff
 *   @0x21525c mla r0, r0, r12, r6
 *   @0x215260 bl 0xb6a18 <usleep@plt>
 *   @0x215264 bl 0x215148 <Timing_Time>
 *   @0x215268 subs r0, r4, r0
 *   @0x21526c sbc r1, r5, r1
 *   @0x215270 cmp r0, #1
 *   @0x215274 sbcs r3, r1, #0
 *   @0x215278 bge 0x215238 <Timing_Sleep+0x48>
 *   @0x21527c pop {r3, r4, r5, r6, r7, pc}
 *   @0x215280 andseq r9, sp, r0, lsr #7
 *
 * ══ §5/212 Audio_GetName(int)  0x218348  size 148  37 条（0x218348..0x2183dc）
 * @func 0x218348 0x2183dc  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Audio_GetName(int)+0x68 / Audio_GetNoiseFromID(int)
 * 字段偏移 top8: 0x70×1 / 0x60×1 / 0x48×1 / 0x20×1 / 0x4c×1 / 0x2×1 / 0x1c×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x218348 push {r3, lr}
 *   @0x21834c mov r2, r0
 *   @0x218350 ldr r3, [pc, #0x70]
 *   @0x218354 ldr r3, [pc, r3]
 *   @0x218358 ldrb r3, [r3]
 *   @0x21835c cmp r3, #0
 *   @0x218360 beq 0x2183bc <_Z13Audio_GetNamei+0x74>
 *   @0x218364 ldr r3, [pc, #0x60]
 *   @0x218368 ldr r3, [pc, r3]
 *   @0x21836c ldr r3, [r3]
 *   @0x218370 cmp r0, r3
 *   @0x218374 bge 0x2183a0 <_Z13Audio_GetNamei+0x58>
 *   @0x218378 cmp r2, #0
 *   @0x21837c blt 0x2183b0 <_Z13Audio_GetNamei+0x68>
 *   @0x218380 ldr r3, [pc, #0x48]
 *   @0x218384 add r3, pc, r3
 *   @0x218388 ldr r1, [r3, #0x20]
 *   @0x21838c cmp r2, r1
 *   @0x218390 bge 0x2183b0 <_Z13Audio_GetNamei+0x68>
 *   @0x218394 ldr r3, [r3, #0x4c]
 *   @0x218398 ldr r0, [r3, r2, lsl #2]
 *   @0x21839c pop {r3, pc}
 *   @0x2183a0 bl 0x216fbc <_Z20Audio_GetNoiseFromIDi>
 *   @0x2183a4 cmp r0, #0
 *   @0x2183a8 ldrne r2, [r0, #0x18]
 *   @0x2183ac bne 0x218378 <_Z13Audio_GetNamei+0x30>
 *   @0x2183b0 ldr r0, [pc, #0x1c]
 *   @0x2183b4 add r0, pc, r0
 *   @0x2183b8 pop {r3, pc}
 *   @0x2183bc ldr r0, [pc, #0x14]
 *   @0x2183c0 add r0, pc, r0
 *   @0x2183c4 pop {r3, pc}
 *   @0x2183c8 ldrsbeq r6, [sp], -r12
 *   @0x2183cc andseq r9, sp, r12, ror r0
 *   @0x2183d0 subseq r12, r3, r0, lsl pc
 *   @0x2183d4 andseq r8, r1, r12, lsl #14
 *   @0x2183d8 andseq r8, r1, r0, lsl #14
 *
 * ══ §6/212 Audio_GetListenerInfo(int)  0x2185a4  size 148  37 条（0x2185a4..0x218638）
 * @func 0x2185a4 0x218638  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CreateDsMap(int, ...)
 * 字段偏移 top8: 0x6c×1 / 0x68×1 / 0x60×1 / 0x38×1 / 0x10×1 / 0x20×1 / 0x4×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2185a4 subs r12, r0, #0
 *   @0x2185a8 push {r4, r5, r6, r7, r8, lr}
 *   @0x2185ac sub sp, sp, #40
 *   @0x2185b0 bne 0x218620 <_Z21Audio_GetListenerInfoi+0x7c>
 *   @0x2185b4 ldr r1, [pc, #0x6c]
 *   @0x2185b8 mov r4, #0
 *   @0x2185bc ldr r8, [pc, #0x68]
 *   @0x2185c0 mov r5, #0
 *   @0x2185c4 ldr r1, [pc, r1]
 *   @0x2185c8 ldr lr, [pc, #0x60]
 *   @0x2185cc mov r6, #0
 *   @0x2185d0 mov r7, #0
 *   @0x2185d4 ldr r1, [r1]
 *   @0x2185d8 movt r7, #0x3ff0
 *   @0x2185dc add r8, pc, r8
 *   @0x2185e0 add lr, pc, lr
 *   @0x2185e4 mov r2, r4
 *   @0x2185e8 mov r3, r5
 *   @0x2185ec str r1, [sp]
 *   @0x2185f0 mov r0, #3
 *   @0x2185f4 ldr r1, [pc, #0x38]
 *   @0x2185f8 strd r4, r5, [sp, #24]
 *   @0x2185fc str r12, [sp, #0x10]
 *   @0x218600 add r1, pc, r1
 *   @0x218604 str r12, [sp, #0x20]
 *   @0x218608 str r8, [sp, #0x4]
 *   @0x21860c str lr, [sp, #0x14]
 *   @0x218610 strd r6, r7, [sp, #8]
 *   @0x218614 bl 0x20bdc0 <_Z11CreateDsMapiz>
 *   @0x218618 add sp, sp, #40
 *   @0x21861c pop {r4, r5, r6, r7, r8, pc}
 *   @0x218620 mvn r0, #0
 *   @0x218624 b 0x218618 <_Z21Audio_GetListenerInfoi+0x74>
 *   @0x218628 andseq r8, sp, r4, lsr #28
 *   @0x21862c ldrsbeq r11, [r3], -r4
 *   @0x218630 andseq sp, r2, r8, lsr #24
 *   @0x218634 andseq r8, r1, r8, lsl #4
 *
 * ══ §7/212 Audio_StopRecording(int)  0x21caf8  size 148  37 条（0x21caf8..0x21cb8c）
 * @func 0x21caf8 0x21cb8c  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GetRecorder(int) / 0xb6b74 / 0xb6b80 / MemoryManager::Free(void const*) / operator delete(void*)
 * 字段偏移 top8: 0xc×2 / 0x10×2 / 0x8×1 / 0x40×1 / 0x54×1 / 0x2×1 / 0x28×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21caf8 push {r3, r4, r5, lr}
 *   @0x21cafc mov r5, r0
 *   @0x21cb00 bl 0x21c220 <_Z11GetRecorderi>
 *   @0x21cb04 subs r4, r0, #0
 *   @0x21cb08 beq 0x21cb54 <_Z19Audio_StopRecordingi+0x5c>
 *   @0x21cb0c ldrb r3, [r4, #0xc]
 *   @0x21cb10 cmp r3, #0
 *   @0x21cb14 beq 0x21cb54 <_Z19Audio_StopRecordingi+0x5c>
 *   @0x21cb18 ldr r0, [r4, #0x10]
 *   @0x21cb1c bl 0xb6b74 <alcCaptureStop@plt>
 *   @0x21cb20 ldr r0, [r4, #0x10]
 *   @0x21cb24 bl 0xb6b80 <alcCaptureCloseDevice@plt>
 *   @0x21cb28 ldr r0, [r4, #0x8]
 *   @0x21cb2c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x21cb30 mov r0, r4
 *   @0x21cb34 bl 0x27d1d0 <_ZdlPv>
 *   @0x21cb38 ldr r2, [pc, #0x40]
 *   @0x21cb3c mov r3, #0
 *   @0x21cb40 add r2, pc, r2
 *   @0x21cb44 mov r0, r3
 *   @0x21cb48 ldr r2, [r2, #0x54]
 *   @0x21cb4c str r3, [r2, r5, lsl #2]
 *   @0x21cb50 pop {r3, r4, r5, pc}
 *   @0x21cb54 ldr r3, [pc, #0x28]
 *   @0x21cb58 mov r2, r5
 *   @0x21cb5c ldr r1, [pc, #0x24]
 *   @0x21cb60 ldr r3, [pc, r3]
 *   @0x21cb64 add r1, pc, r1
 *   @0x21cb68 ldr r0, [r3]
 *   @0x21cb6c ldr r3, [r0]
 *   @0x21cb70 ldr r3, [r3, #0xc]
 *   @0x21cb74 blx r3
 *   @0x21cb78 mvn r0, #0
 *   @0x21cb7c pop {r3, r4, r5, pc}
 *   @0x21cb80 subseq r8, r3, r4, asr r7
 *   @0x21cb84 ldrheq r0, [sp], -r4
 *   @0x21cb88 andseq r7, r3, r8, asr r8
 *
 * ══ §8/212 anon_221c48  0x221c48  size 148  37 条（0x221c48..0x221cdc）
 * @func 0x221c48 0x221cdc  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _alutSetError×2 / 0xb65bc / 0xb68c8
 * 字段偏移 top8: 0xc×6 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x221c48 push {r4, r5, r6, lr}
 *   @0x221c4c mov r4, r0
 *   @0x221c50 ldrb r6, [r0]
 *   @0x221c54 mov r5, r2
 *   @0x221c58 cmp r6, #0
 *   @0x221c5c bne 0x221c9c <alutExit+0x124>
 *   @0x221c60 ldr r3, [r0, #0x8]
 *   @0x221c64 cmp r2, r3
 *   @0x221c68 bhi 0x221c8c <alutExit+0x114>
 *   @0x221c6c mov r0, r1
 *   @0x221c70 ldr r1, [r4, #0xc]
 *   @0x221c74 bl 0xb65bc <memcpy@plt>
 *   @0x221c78 ldr r3, [r4, #0xc]
 *   @0x221c7c mov r0, #1
 *   @0x221c80 add r5, r3, r5
 *   @0x221c84 str r5, [r4, #0xc]
 *   @0x221c88 pop {r4, r5, r6, pc}
 *   @0x221c8c movw r0, #0x211
 *   @0x221c90 bl 0x221940 <_alutSetError>
 *   @0x221c94 mov r0, r6
 *   @0x221c98 pop {r4, r5, r6, pc}
 *   @0x221c9c mov r0, r1
 *   @0x221ca0 ldr r3, [r4, #0xc]
 *   @0x221ca4 mov r1, #1
 *   @0x221ca8 bl 0xb68c8 <fread@plt>
 *   @0x221cac cmp r5, r0
 *   @0x221cb0 beq 0x221cd8 <alutExit+0x160>
 *   @0x221cb4 ldr r2, [r4, #0xc]
 *   @0x221cb8 movw r3, #0x20e
 *   @0x221cbc movw r0, #0x211
 *   @0x221cc0 ldrh r2, [r2, #12]
 *   @0x221cc4 tst r2, #64
 *   @0x221cc8 movne r0, r3
 *   @0x221ccc bl 0x221940 <_alutSetError>
 *   @0x221cd0 mov r0, #0
 *   @0x221cd4 pop {r4, r5, r6, pc}
 *   @0x221cd8 mov r0, #1
 *
 * ══ §9/212 COggThread::CleanUp()  0x223890  size 148  37 条（0x223890..0x223924）
 * @func 0x223890 0x223924  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete[](void*)×2 / Mutex::~Mutex() / operator delete(void*) / SOggChannel::~SOggChannel()
 * 字段偏移 top8: 0x804×3 / 0x810×2 / 0x814×1 / 0x-4×1 / 0x802×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x223890 push {r4, r5, r6, lr}
 *   @0x223894 mov r6, r0
 *   @0x223898 ldr r4, [r0, #0x814]
 *   @0x22389c cmp r4, #0
 *   @0x2238a0 beq 0x2238b4 <_ZN10COggThread7CleanUpEv+0x24>
 *   @0x2238a4 mov r0, r4
 *   @0x2238a8 bl 0x27e020 <_ZN5MutexD2Ev>
 *   @0x2238ac mov r0, r4
 *   @0x2238b0 bl 0x27d1d0 <_ZdlPv>
 *   @0x2238b4 ldr r0, [r6, #0x804]
 *   @0x2238b8 cmp r0, #0
 *   @0x2238bc beq 0x2238fc <_ZN10COggThread7CleanUpEv+0x6c>
 *   @0x2238c0 ldr r4, [r0, #-0x4]
 *   @0x2238c4 add r4, r4, r4, lsl #1
 *   @0x2238c8 add r4, r0, r4, lsl #8
 *   @0x2238cc cmp r0, r4
 *   @0x2238d0 beq 0x2238f4 <_ZN10COggThread7CleanUpEv+0x64>
 *   @0x2238d4 sub r4, r4, #768
 *   @0x2238d8 mov r0, r4
 *   @0x2238dc mov r5, r4
 *   @0x2238e0 bl 0x2234d0 <_ZN11SOggChannelD2Ev>
 *   @0x2238e4 ldr r0, [r6, #0x804]
 *   @0x2238e8 cmp r0, r4
 *   @0x2238ec sub r4, r4, #768
 *   @0x2238f0 bne 0x2238d8 <_ZN10COggThread7CleanUpEv+0x48>
 *   @0x2238f4 sub r0, r0, #8
 *   @0x2238f8 bl 0x27d1d4 <_ZdaPv>
 *   @0x2238fc ldr r0, [r6, #0x810]
 *   @0x223900 mov r3, #0
 *   @0x223904 str r3, [r6, #0x804]
 *   @0x223908 cmp r0, r3
 *   @0x22390c beq 0x223914 <_ZN10COggThread7CleanUpEv+0x84>
 *   @0x223910 bl 0x27d1d4 <_ZdaPv>
 *   @0x223914 mov r3, #0
 *   @0x223918 str r3, [r6, #0x810]
 *   @0x22391c strb r3, [r6, #0x802]
 *   @0x223920 pop {r4, r5, r6, pc}
 *
 * ══ §10/212 Hash<CPhysicsFixture>::~Hash()  0x2366f4  size 148  37 条（0x2366f4..0x236788）
 * @func 0x2366f4 0x236788  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / Hash<CPhysicsFixture>::~Hash()+0x88 / CPhysicsFixture::~CPhysicsFixture() / operator delete(void*)
 * 字段偏移 top8: 0x4×2 / 0x8×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2366f4 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2366f8 mov r7, r0
 *   @0x2366fc ldm r0, {r0, r9}
 *   @0x236700 cmp r9, #0
 *   @0x236704 lslge r8, r9, #3
 *   @0x236708 movge r10, #0
 *   @0x23670c blt 0x23677c <_ZN4HashI15CPhysicsFixtureED2Ev+0x88>
 *   @0x236710 ldr r4, [r0, r8]
 *   @0x236714 add r3, r0, r8
 *   @0x236718 str r10, [r0, r8]
 *   @0x23671c cmp r4, #0
 *   @0x236720 str r10, [r3, #0x4]
 *   @0x236724 beq 0x23676c <_ZN4HashI15CPhysicsFixtureED2Ev+0x78>
 *   @0x236728 ldr r5, [r4, #0xc]
 *   @0x23672c ldr r6, [r4, #0x4]
 *   @0x236730 cmp r5, #0
 *   @0x236734 mov r0, r5
 *   @0x236738 beq 0x236748 <_ZN4HashI15CPhysicsFixtureED2Ev+0x54>
 *   @0x23673c bl 0x23661c <_ZN15CPhysicsFixtureD2Ev>
 *   @0x236740 mov r0, r5
 *   @0x236744 bl 0x27d1d0 <_ZdlPv>
 *   @0x236748 mov r0, r4
 *   @0x23674c mov r4, r6
 *   @0x236750 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x236754 ldr r3, [r7, #0x8]
 *   @0x236758 cmp r6, #0
 *   @0x23675c sub r3, r3, #1
 *   @0x236760 str r3, [r7, #0x8]
 *   @0x236764 bne 0x236728 <_ZN4HashI15CPhysicsFixtureED2Ev+0x34>
 *   @0x236768 ldr r0, [r7]
 *   @0x23676c sub r9, r9, #1
 *   @0x236770 sub r8, r8, #8
 *   @0x236774 cmn r9, #1
 *   @0x236778 bne 0x236710 <_ZN4HashI15CPhysicsFixtureED2Ev+0x1c>
 *   @0x23677c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x236780 mov r0, r7
 *   @0x236784 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *
 * ══ §11/212 JS_Array_DefineOwnProperty(YYObjectBase*, char const*, RValue*, bool)  0x248ac4  size 148  37 条（0x248ac4..0x248b58）
 * @func 0x248ac4 0x248b58  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66c4 / JSArrayPut(RValue*, RValue*, RValue*) / JS_DefineOwnProperty_Internal(YYObjectBase*, char const*, RValue*, bool)
 * 字段偏移 top8: 0x1×2 / 0x4×2 / 0x80×1 / 0x-10×1 / 0x14×1 / 0x24×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x248ac4 push {r4, r5, r6, lr}
 *   @0x248ac8 sub sp, sp, #40
 *   @0x248acc ldr lr, [pc, #0x80]
 *   @0x248ad0 mov r6, r0
 *   @0x248ad4 mov r12, r1
 *   @0x248ad8 ldr lr, [pc, lr]
 *   @0x248adc ldr r5, [lr]
 *   @0x248ae0 ldrb r4, [r12], #1
 *   @0x248ae4 cmp r4, #0
 *   @0x248ae8 add lr, r5, r4
 *   @0x248aec bne 0x248b38 <_Z26JS_Array_DefineOwnPropertyP12YYObjectBasePKcP6RValueb+0x74>
 *   @0x248af0 mov r0, r1
 *   @0x248af4 str r2, [sp, #0x4]
 *   @0x248af8 bl 0xb66c4 <atol@plt>
 *   @0x248afc add r3, sp, #40
 *   @0x248b00 ldr r2, [sp, #0x4]
 *   @0x248b04 add r1, sp, #8
 *   @0x248b08 str r6, [r3, #-0x10]!
 *   @0x248b0c mov r12, #6
 *   @0x248b10 str r4, [sp, #0x14]
 *   @0x248b14 str r12, [sp, #0x24]
 *   @0x248b18 vmov s13, r0
 *   @0x248b1c mov r0, r3
 *   @0x248b20 vcvt.f64.s32 d7, s13
 *   @0x248b24 vstr d7, [sp, #8]
 *   @0x248b28 bl 0x247c68 <_Z10JSArrayPutP6RValueS0_S0_>
 *   @0x248b2c mov r0, #1
 *   @0x248b30 add sp, sp, #40
 *   @0x248b34 pop {r4, r5, r6, pc}
 *   @0x248b38 ldrb lr, [lr, #0x1]
 *   @0x248b3c tst lr, #4
 *   @0x248b40 bne 0x248ae0 <_Z26JS_Array_DefineOwnPropertyP12YYObjectBasePKcP6RValueb+0x1c>
 *   @0x248b44 mov r0, r6
 *   @0x248b48 bl 0x247d44 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb>
 *   @0x248b4c add sp, sp, #40
 *   @0x248b50 pop {r4, r5, r6, pc}
 *   @0x248b54 andseq r4, r10, r8, lsr #29
 *
 * ══ §12/212 JS_Array_GetOwnProperty(YYObjectBase*, RValue*, char const*)  0x24a168  size 148  37 条（0x24a168..0x24a1fc）
 * @func 0x24a168 0x24a1fc  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66c4 / JSArrayGet(RValue*, RValue*, RValue*) / JS_DefaultGetOwnProperty(YYObjectBase*, RValue*, char const*)
 * 字段偏移 top8: 0x1×2 / 0x88×1 / 0x-10×1 / 0xc×1 / 0x1c×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x24a168 ldr r12, [pc, #0x88]
 *   @0x24a16c mov r3, r2
 *   @0x24a170 push {r4, r5, r6, lr}
 *   @0x24a174 ldr r12, [pc, r12]
 *   @0x24a178 sub sp, sp, #32
 *   @0x24a17c mov r5, r0
 *   @0x24a180 ldr lr, [r12]
 *   @0x24a184 mov r6, r1
 *   @0x24a188 ldrb r4, [r3], #1
 *   @0x24a18c cmp r4, #0
 *   @0x24a190 add r12, lr, r4
 *   @0x24a194 bne 0x24a1d8 <_Z23JS_Array_GetOwnPropertyP12YYObjectBaseP6RValuePKc+0x70>
 *   @0x24a198 mov r0, r2
 *   @0x24a19c bl 0xb66c4 <atol@plt>
 *   @0x24a1a0 add r3, sp, #32
 *   @0x24a1a4 mov r2, r6
 *   @0x24a1a8 mov r1, sp
 *   @0x24a1ac str r5, [r3, #-0x10]!
 *   @0x24a1b0 mov r12, #6
 *   @0x24a1b4 str r4, [sp, #0xc]
 *   @0x24a1b8 str r12, [sp, #0x1c]
 *   @0x24a1bc vmov s13, r0
 *   @0x24a1c0 mov r0, r3
 *   @0x24a1c4 vcvt.f64.s32 d7, s13
 *   @0x24a1c8 vstr d7, [sp]
 *   @0x24a1cc bl 0x249cdc <_Z10JSArrayGetP6RValueS0_S0_>
 *   @0x24a1d0 add sp, sp, #32
 *   @0x24a1d4 pop {r4, r5, r6, pc}
 *   @0x24a1d8 ldrb r12, [r12, #0x1]
 *   @0x24a1dc tst r12, #4
 *   @0x24a1e0 bne 0x24a188 <_Z23JS_Array_GetOwnPropertyP12YYObjectBaseP6RValuePKc+0x20>
 *   @0x24a1e4 mov r0, r5
 *   @0x24a1e8 mov r1, r6
 *   @0x24a1ec bl 0x23d0f0 <_Z24JS_DefaultGetOwnPropertyP12YYObjectBaseP6RValuePKc>
 *   @0x24a1f0 add sp, sp, #32
 *   @0x24a1f4 pop {r4, r5, r6, pc}
 *   @0x24a1f8 andseq r3, r10, r12, lsl #16
 *
 * ══ §13/212 SortCompare(RValue*, RValue*, RValue*)  0x2566f0  size 148  37 条（0x2566f0..0x256784）
 * @func 0x2566f0 0x256784  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_JS_ToString(RValue&, RValue*)×2 / 0xb6574 / SortCompare(RValue*, RValue*, RValue*)+0x8c / translate(EJSRetVal)
 * 字段偏移 top8: 0xc×2 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2566f0 ldr r3, [r1, #0xc]
 *   @0x2566f4 push {r4, lr}
 *   @0x2566f8 bic r3, r3, #-16777216
 *   @0x2566fc cmp r3, #5
 *   @0x256700 sub sp, sp, #32
 *   @0x256704 mov r4, r2
 *   @0x256708 moveq r0, #1
 *   @0x25670c beq 0x256768 <_Z11SortCompareP6RValueS0_S0_+0x78>
 *   @0x256710 ldr r3, [r2, #0xc]
 *   @0x256714 bic r3, r3, #-16777216
 *   @0x256718 cmp r3, #5
 *   @0x25671c beq 0x25677c <_Z11SortCompareP6RValueS0_S0_+0x8c>
 *   @0x256720 mov r0, sp
 *   @0x256724 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x256728 cmp r0, #0
 *   @0x25672c bne 0x256770 <_Z11SortCompareP6RValueS0_S0_+0x80>
 *   @0x256730 mov r1, r4
 *   @0x256734 add r0, sp, #16
 *   @0x256738 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x25673c cmp r0, #0
 *   @0x256740 bne 0x256770 <_Z11SortCompareP6RValueS0_S0_+0x80>
 *   @0x256744 ldr r2, [sp]
 *   @0x256748 ldr r3, [sp, #0x10]
 *   @0x25674c ldr r0, [r2]
 *   @0x256750 ldr r1, [r3]
 *   @0x256754 bl 0xb6574 <strcmp@plt>
 *   @0x256758 cmp r0, #0
 *   @0x25675c blt 0x25677c <_Z11SortCompareP6RValueS0_S0_+0x8c>
 *   @0x256760 moveq r0, #0
 *   @0x256764 movne r0, #1
 *   @0x256768 add sp, sp, #32
 *   @0x25676c pop {r4, pc}
 *   @0x256770 bl 0x242ebc <_Z9translate9EJSRetVal>
 *   @0x256774 add sp, sp, #32
 *   @0x256778 pop {r4, pc}
 *   @0x25677c mvn r0, #0
 *   @0x256780 b 0x256768 <_Z11SortCompareP6RValueS0_S0_+0x78>
 *
 * ══ §14/212 _pcre_ord2utf  0x25fd98  size 148  37 条（0x25fd98..0x25fe2c）
 * @func 0x25fd98 0x25fe2c  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x84×1 / 0x-4×1 / 0x-1×1 / 0x30×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x25fd98 ldr r3, [pc, #0x84]
 *   @0x25fd9c mov r2, r0
 *   @0x25fda0 mov r12, #0
 *   @0x25fda4 ldr r3, [pc, r3]
 *   @0x25fda8 sub r3, r3, #4
 *   @0x25fdac str r4, [sp, #-0x4]!
 *   @0x25fdb0 ldr r0, [r3, #0x4]!
 *   @0x25fdb4 cmp r0, r2
 *   @0x25fdb8 bge 0x25fe0c <_pcre_ord2utf+0x74>
 *   @0x25fdbc add r12, r12, #1
 *   @0x25fdc0 cmp r12, #6
 *   @0x25fdc4 bne 0x25fdb0 <_pcre_ord2utf+0x18>
 *   @0x25fdc8 add r1, r1, #6
 *   @0x25fdcc mov r0, #7
 *   @0x25fdd0 rsb r4, r12, r1
 *   @0x25fdd4 and r3, r2, #63
 *   @0x25fdd8 lsr r2, r2, #6
 *   @0x25fddc mvn r3, r3, lsl #25
 *   @0x25fde0 mvn r3, r3, lsr #25
 *   @0x25fde4 strb r3, [r1], #-1
 *   @0x25fde8 cmp r1, r4
 *   @0x25fdec bne 0x25fdd4 <_pcre_ord2utf+0x3c>
 *   @0x25fdf0 ldr r3, [pc, #0x30]
 *   @0x25fdf4 ldr r3, [pc, r3]
 *   @0x25fdf8 ldr r3, [r3, r12, lsl #2]
 *   @0x25fdfc orr r2, r3, r2
 *   @0x25fe00 strb r2, [r1]
 *   @0x25fe04 ldr r4, [sp], #4
 *   @0x25fe08 bx lr
 *   @0x25fe0c cmp r12, #0
 *   @0x25fe10 add r1, r1, r12
 *   @0x25fe14 addne r0, r12, #1
 *   @0x25fe18 bne 0x25fdd0 <_pcre_ord2utf+0x38>
 *   @0x25fe1c mov r0, #1
 *   @0x25fe20 b 0x25fdf0 <_pcre_ord2utf+0x58>
 *   @0x25fe24 andseq r1, r9, r8, asr #20
 *   @0x25fe28 ldrsheq r1, [r9], -r12
 *
 * ══ §15/212 lh_table_resize  0x280a88  size 148  37 条（0x280a88..0x280b1c）
 * @func 0x280a88 0x280b1c  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: lh_table_new / lh_table_insert / 0xb655c
 * 字段偏移 top8: 0x20×3 / 0x28×3 / 0x24×2 / 0xc×2 / 0x34×1 / 0x30×1 / 0x1c×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x280a88 push {r4, r5, r6, r7, lr}
 *   @0x280a8c mov r6, r0
 *   @0x280a90 ldr r12, [r6, #0x34]
 *   @0x280a94 sub sp, sp, #12
 *   @0x280a98 mov r7, r1
 *   @0x280a9c ldr r3, [r6, #0x30]
 *   @0x280aa0 ldr r1, [r0, #0x1c]
 *   @0x280aa4 mov r2, #0
 *   @0x280aa8 mov r0, r7
 *   @0x280aac str r12, [sp]
 *   @0x280ab0 bl 0x280834 <lh_table_new>
 *   @0x280ab4 ldr r4, [r6, #0x20]
 *   @0x280ab8 cmp r4, #0
 *   @0x280abc mov r5, r0
 *   @0x280ac0 beq 0x280adc <lh_table_resize+0x54>
 *   @0x280ac4 ldm r4, {r1, r2}
 *   @0x280ac8 mov r0, r5
 *   @0x280acc bl 0x280998 <lh_table_insert>
 *   @0x280ad0 ldr r4, [r4, #0x8]
 *   @0x280ad4 cmp r4, #0
 *   @0x280ad8 bne 0x280ac4 <lh_table_resize+0x3c>
 *   @0x280adc ldr r0, [r6, #0x28]
 *   @0x280ae0 bl 0xb655c <free@plt>
 *   @0x280ae4 ldr r12, [r5, #0x28]
 *   @0x280ae8 ldr r1, [r5, #0x20]
 *   @0x280aec mov r0, r5
 *   @0x280af0 ldr r3, [r5, #0x24]
 *   @0x280af4 ldr r2, [r6, #0xc]
 *   @0x280af8 str r12, [r6, #0x28]
 *   @0x280afc add r2, r2, #1
 *   @0x280b00 str r7, [r6]
 *   @0x280b04 str r1, [r6, #0x20]
 *   @0x280b08 str r2, [r6, #0xc]
 *   @0x280b0c str r3, [r6, #0x24]
 *   @0x280b10 add sp, sp, #12
 *   @0x280b14 pop {r4, r5, r6, r7, lr}
 *   @0x280b18 b 0xb655c <free@plt>
 *
 * ══ §16/212 PB_PurchaseInfo(HTTP_REQ_CONTEXT*, void*, int*)  0x28faf4  size 148  37 条（0x28faf4..0x28fb88）
 * @func 0x28faf4 0x28fb88  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CreateDsMap(int, ...) / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x4×2 / 0x6c×1 / 0x5c×1 / 0x54×1 / 0x10×1 / 0x14×1 / 0x20×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28faf4 push {r4, r5, r6, r7, lr}
 *   @0x28faf8 mov r6, r1
 *   @0x28fafc vldr s13, [r6]
 *   @0x28fb00 vcvt.f64.s32 d7, s13
 *   @0x28fb04 sub sp, sp, #44
 *   @0x28fb08 ldr r1, [pc, #0x6c]
 *   @0x28fb0c mov r7, r2
 *   @0x28fb10 ldr r0, [r6, #0x4]
 *   @0x28fb14 mov r3, #0
 *   @0x28fb18 add r1, pc, r1
 *   @0x28fb1c ldr r2, [pc, #0x5c]
 *   @0x28fb20 str r1, [sp, #0x4]
 *   @0x28fb24 mov r4, #0
 *   @0x28fb28 ldr r1, [pc, #0x54]
 *   @0x28fb2c add r2, pc, r2
 *   @0x28fb30 str r0, [sp, #0x10]
 *   @0x28fb34 mov r5, #0
 *   @0x28fb38 str r2, [sp, #0x14]
 *   @0x28fb3c add r1, pc, r1
 *   @0x28fb40 str r3, [sp]
 *   @0x28fb44 mov r2, #0
 *   @0x28fb48 str r3, [sp, #0x20]
 *   @0x28fb4c vstr d7, [sp, #24]
 *   @0x28fb50 strd r4, r5, [sp, #8]
 *   @0x28fb54 mov r0, #3
 *   @0x28fb58 mov r3, #43008
 *   @0x28fb5c movt r3, #0x408f
 *   @0x28fb60 bl 0x20bdc0 <_Z11CreateDsMapiz>
 *   @0x28fb64 str r0, [r7]
 *   @0x28fb68 mov r0, r6
 *   @0x28fb6c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x28fb70 mov r0, #70
 *   @0x28fb74 add sp, sp, #44
 *   @0x28fb78 pop {r4, r5, r6, r7, pc}
 *   @0x28fb7c andeq r8, r12, r8, lsr #11
 *   @0x28fb80 andeq r8, r12, r0, lsr #11
 *   @0x28fb84 andeq r0, r10, r4, lsl #30
 *
 * ══ §17/212 CProfiler::Clean()  0x2a0364  size 148  37 条（0x2a0364..0x2a03f8）
 * @func 0x2a0364 0x2a03f8  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×5 / operator delete(void*)×2
 * 字段偏移 top8: 0x8×4 / 0x10×2 / 0xc×2 / 0x74×2 / 0x28×2 / 0x18×2 / 0x11×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a0364 ldrb r3, [r0, #0x10]
 *   @0x2a0368 push {r4, r5, r6, lr}
 *   @0x2a036c cmp r3, #0
 *   @0x2a0370 mov r4, r0
 *   @0x2a0374 popeq {r4, r5, r6, pc}
 *   @0x2a0378 ldr r5, [r0, #0x8]
 *   @0x2a037c mov r3, #0
 *   @0x2a0380 strb r3, [r0, #0x10]
 *   @0x2a0384 cmp r5, r3
 *   @0x2a0388 strb r3, [r0, #0x11]
 *   @0x2a038c beq 0x2a03a0 <_ZN9CProfiler5CleanEv+0x3c>
 *   @0x2a0390 ldr r0, [r5]
 *   @0x2a0394 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x2a0398 mov r0, r5
 *   @0x2a039c bl 0x27d1d0 <_ZdlPv>
 *   @0x2a03a0 ldr r5, [r4, #0xc]
 *   @0x2a03a4 mov r6, #0
 *   @0x2a03a8 str r6, [r4, #0x8]
 *   @0x2a03ac cmp r5, r6
 *   @0x2a03b0 beq 0x2a03c8 <_ZN9CProfiler5CleanEv+0x64>
 *   @0x2a03b4 ldr r0, [r5, #0x8]
 *   @0x2a03b8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x2a03bc str r6, [r5, #0x8]
 *   @0x2a03c0 mov r0, r5
 *   @0x2a03c4 bl 0x27d1d0 <_ZdlPv>
 *   @0x2a03c8 mov r5, #0
 *   @0x2a03cc ldr r0, [r4, #0x74]
 *   @0x2a03d0 str r5, [r4, #0xc]
 *   @0x2a03d4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x2a03d8 ldr r0, [r4, #0x28]
 *   @0x2a03dc str r5, [r4, #0x74]
 *   @0x2a03e0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x2a03e4 str r5, [r4, #0x28]
 *   @0x2a03e8 ldr r0, [r4, #0x18]
 *   @0x2a03ec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x2a03f0 str r5, [r4, #0x18]
 *   @0x2a03f4 pop {r4, r5, r6, pc}
 *
 * ══ §18/212 png_write_flush  0x2b0554  size 148  37 条（0x2b0554..0x2b05e8）
 * @func 0x2b0554 0x2b05e8  size 148  37 条
 * 部分覆盖: 本节 37/62 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb69ac / png_error / png_write_IDAT
 * 字段偏移 top8: 0x78×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b0554 push {r4, r5, r6, lr}
 *   @0x2b0558 cmp r0, #0x0
 *   @0x2b055c ldr.w r2, [r0, #0x1a8]
 *   @0x2b0560 ldr.w r3, [r0, #0x194]
 *   @0x2b0564 cmp r2, r3
 *   @0x2b0568 ldr r6, [pc, #0x78]
 *   @0x2b056c ldrbtmi r7, [lr], #-1436
 *   @0x2b0570 mov r0, r5
 *   @0x2b0574 blx 0xb69ac <deflate@plt>
 *   @0x2b0578 cbz r0, 0x2b0588 <png_write_flush+0x34>
 *   @0x2b057c qsaxmi r1, r0, r0
 *   @0x2b0580 cbnz r1, 0x2b0584 <png_write_flush+0x30>
 *   @0x2b0584 bl 0x2a642c <png_error>
 *   @0x2b0588 ldr.w r3, [r4, #0x148]
 *   @0x2b058c cbnz r3, 0x2b05ae <png_write_flush+0x5a>
 *   @0x2b0590 ldr.w r1, [r4, #0x170]
 *   @0x2b0594 ldr.w r2, [r4, #0x174]
 *   @0x2b0598 bl 0x2b16a0 <png_write_IDAT>
 *   @0x2b059c ldr.w r3, [r4, #0x170]
 *   @0x2b05a0 str.w r3, [r4, #0x144]
 *   @0x2b05a4 ldr.w r3, [r4, #0x174]
 *   @0x2b05a8 str.w r3, [r4, #0x148]
 *   @0x2b05ac b 0x2b0570 <png_write_flush+0x1c>
 *   @0x2b05b0 addsmi r2, r10, #116, #2
 *   @0x2b05b4 beq 0x2b05d2 <png_write_flush+0x7e>
 *   @0x2b05b8 mov r0, r4
 *   @0x2b05bc .word 0xf0011170
 *   @0x2b05c0 .word 0xf8d4f86f
 *   @0x2b05c4 .word 0xf8c43170
 *   @0x2b05c8 .word 0xf8d43144
 *   @0x2b05cc .word 0xf8c43174
 *   @0x2b05d0 movwhs r3, #0x148
 *   @0x2b05d4 mov r0, r4
 *   @0x2b05d8 pop {r3, r4, r9, r12, sp}
 *   @0x2b05dc .word 0xf7ff4070
 *   @0x2b05e0 .word 0xbd70bb15
 *   @0x2b05e4 bge 0x2b0606 <png_write_destroy+0x1e>
 *
 * ══ §19/212 png_write_sCAL  0x2b2384  size 148  37 条（0x2b2384..0x2b2418）
 * @func 0x2b2384 0x2b2418  size 148  37 条
 * 部分覆盖: 本节 37/63 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6538×2 / 0x832184 / png_write_sCAL+0x1c
 * 字段偏移 top8: 0x-44×1 / 0x54×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b2384 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2b2388 mov r10, r0
 *   @0x2b238c sub sp, #0x5c
 *   @0x2b2390 add r6, sp, #0x58
 *   @0x2b2394 ldr r7, [r7]
 *   @0x2b2398 ldrbtmi r11, [r12], #-124
 *   @0x2b239c strb r1, [r6, #-68]!
 *   @0x2b23a0 ldr r0, [r7]
 *   @0x2b23a4 strd r2, r3, [sp]
 *   @0x2b23a8 movs r1, #0x3f
 *   @0x2b23ac str r0, [sp, #0x54]
 *   @0x2b23b0 andls r0, r3, r2, ror #30
 *   @0x2b23b4 ldrb r0, [r4, #0x4]
 *   @0x2b23b8 strb.w r0, [sp, #0x10]
 *   @0x2b23bc mov r0, r4
 *   @0x2b23c0 strtmi lr, [r0], -r4, lsl #18
 *   @0x2b23c4 blx 0xb6538 <strlen@plt>
 *   @0x2b23c8 ldrd r4, r5, [sp, #128]
 *   @0x2b23cc mov r2, r11
 *   @0x2b23d0 .word 0xf1004500
 *   @0x2b23d4 strmi r0, [r1], -r2, lsl #16
 *   @0x2b23d8 add.w r9, r6, r8
 *   @0x2b23dc rsb.w r1, r1, #0x3e
 *   @0x2b23e0 mov r0, r9
 *   @0x2b23e4 .word 0x4648e8f2
 *   @0x2b23e8 blx 0xb6538 <strlen@plt>
 *   @0x2b23ec mov r2, r6
 *   @0x2b23f0 add.w r3, r8, r0
 *   @0x2b23f4 mov r0, r10
 *   @0x2b23f8 bls 0x832184 <b2_toiTime+0xd8ce0>
 *   @0x2b23fc ldr r3, [r7]
 *   @0x2b2400 beq 0x2b2406 <png_write_sCAL+0x82>
 *   @0x2b2404 andslt lr, r7, r8, ror #17
 *   @0x2b2408 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2b240c push {r1, r6, r7, lr}
 *   @0x2b2410 bls 0x2b23a0 <png_write_sCAL+0x1c>
 *   @0x2b2414 stm r2!, {r0, r1, r5, r6, r7}
 *
 * ══ §20/212 jpeg_new_colormap  0x2b6644  size 148  37 条（0x2b6644..0x2b66d8）
 * @func 0x2b6644 0x2b66d8  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x14×3 / 0x18×2 / 0x180×1 / 0x4a×1 / 0x59×1 / 0x74×1 / 0x1a8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b6644 push {r3, r4, r5, lr}
 *   @0x2b6648 mov r4, r0
 *   @0x2b664c ldr r3, [r0, #0x14]
 *   @0x2b6650 ldr r5, [r0, #0x180]
 *   @0x2b6654 cmp r3, #207
 *   @0x2b6658 beq 0x2b6678 <jpeg_new_colormap+0x34>
 *   @0x2b665c ldr r2, [r0]
 *   @0x2b6660 mov r1, #20
 *   @0x2b6664 str r3, [r2, #0x18]
 *   @0x2b6668 ldr r3, [r0]
 *   @0x2b666c str r1, [r2, #0x14]
 *   @0x2b6670 ldr r3, [r3]
 *   @0x2b6674 blx r3
 *   @0x2b6678 ldrb r3, [r4, #0x4a]
 *   @0x2b667c cmp r3, #0
 *   @0x2b6680 beq 0x2b66bc <jpeg_new_colormap+0x78>
 *   @0x2b6684 ldrb r3, [r4, #0x59]
 *   @0x2b6688 cmp r3, #0
 *   @0x2b668c beq 0x2b66bc <jpeg_new_colormap+0x78>
 *   @0x2b6690 ldr r3, [r4, #0x74]
 *   @0x2b6694 cmp r3, #0
 *   @0x2b6698 beq 0x2b66bc <jpeg_new_colormap+0x78>
 *   @0x2b669c ldr r3, [r5, #0x18]
 *   @0x2b66a0 mov r0, r4
 *   @0x2b66a4 str r3, [r4, #0x1a8]
 *   @0x2b66a8 ldr r3, [r3, #0xc]
 *   @0x2b66ac blx r3
 *   @0x2b66b0 mov r3, #0
 *   @0x2b66b4 strb r3, [r5, #0x8]
 *   @0x2b66b8 pop {r3, r4, r5, pc}
 *   @0x2b66bc ldr r3, [r4]
 *   @0x2b66c0 mov r1, #46
 *   @0x2b66c4 mov r0, r4
 *   @0x2b66c8 ldr r2, [r3]
 *   @0x2b66cc str r1, [r3, #0x14]
 *   @0x2b66d0 blx r2
 *   @0x2b66d4 pop {r3, r4, r5, pc}
 *
 * ══ §21/212 jpeg_std_error  0x2b8fc0  size 148  37 条（0x2b8fc0..0x2b9054）
 * @func 0x2b8fc0 0x2b9054  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x6c×2 / 0x68×2 / 0x64×1 / 0x60×1 / 0x5c×1 / 0x58×1 / 0x4×1 / 0x70×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b8fc0 push {r4, r5, r6, r7, r8}
 *   @0x2b8fc4 mov r3, r0
 *   @0x2b8fc8 ldr r8, [pc, #0x6c]
 *   @0x2b8fcc mov r2, #0
 *   @0x2b8fd0 ldr r7, [pc, #0x68]
 *   @0x2b8fd4 mov r12, #123
 *   @0x2b8fd8 ldr r6, [pc, #0x64]
 *   @0x2b8fdc add r8, pc, r8
 *   @0x2b8fe0 ldr r5, [pc, #0x60]
 *   @0x2b8fe4 add r7, pc, r7
 *   @0x2b8fe8 ldr r4, [pc, #0x5c]
 *   @0x2b8fec add r6, pc, r6
 *   @0x2b8ff0 ldr r1, [pc, #0x58]
 *   @0x2b8ff4 add r5, pc, r5
 *   @0x2b8ff8 str r8, [r0]
 *   @0x2b8ffc add r4, pc, r4
 *   @0x2b9000 str r7, [r0, #0x4]
 *   @0x2b9004 ldr r1, [pc, r1]
 *   @0x2b9008 str r1, [r0, #0x70]
 *   @0x2b900c str r6, [r3, #0x8]
 *   @0x2b9010 str r5, [r3, #0xc]
 *   @0x2b9014 str r4, [r3, #0x10]
 *   @0x2b9018 str r12, [r0, #0x74]
 *   @0x2b901c str r2, [r0, #0x68]
 *   @0x2b9020 str r2, [r0, #0x6c]
 *   @0x2b9024 str r2, [r0, #0x14]
 *   @0x2b9028 str r2, [r0, #0x78]
 *   @0x2b902c str r2, [r0, #0x7c]
 *   @0x2b9030 str r2, [r0, #0x80]
 *   @0x2b9034 pop {r4, r5, r6, r7, r8}
 *   @0x2b9038 bx lr
 *   @0x2b903c .word 0xffffffb8
 *   @0x2b9040 .word 0xfffffdd4
 *   @0x2b9044 .word 0xffffff38
 *   @0x2b9048 .word 0xfffffe38
 *   @0x2b904c .word 0xfffffe1c
 *   @0x2b9050 andseq r8, r3, r8, lsr #21
 *
 * ══ §22/212 jinit_inverse_dct  0x2be47c  size 148  37 条（0x2be47c..0x2be510）
 * @func 0x2be47c 0x2be510  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65b0
 * 字段偏移 top8: 0x4×2 / 0x24×2 / 0x68×1 / 0xc4×1 / 0x19c×1 / 0x-4×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2be47c ldr r3, [r0, #0x4]
 *   @0x2be480 mov r2, #84
 *   @0x2be484 push {r4, r5, r6, r7, r8, lr}
 *   @0x2be488 mov r1, #1
 *   @0x2be48c ldr r3, [r3]
 *   @0x2be490 mov r4, r0
 *   @0x2be494 blx r3
 *   @0x2be498 ldr r2, [r4, #0x24]
 *   @0x2be49c ldr r3, [pc, #0x68]
 *   @0x2be4a0 cmp r2, #0
 *   @0x2be4a4 ldr r5, [r4, #0xc4]
 *   @0x2be4a8 add r3, pc, r3
 *   @0x2be4ac str r0, [r4, #0x19c]
 *   @0x2be4b0 str r3, [r0]
 *   @0x2be4b4 pople {r4, r5, r6, r7, r8, pc}
 *   @0x2be4b8 mov r7, r0
 *   @0x2be4bc mov r6, #0
 *   @0x2be4c0 mvn r8, #0
 *   @0x2be4c4 ldr r3, [r4, #0x4]
 *   @0x2be4c8 mov r1, #1
 *   @0x2be4cc mov r2, #256
 *   @0x2be4d0 mov r0, r4
 *   @0x2be4d4 add r6, r6, r1
 *   @0x2be4d8 add r5, r5, #84
 *   @0x2be4dc ldr r3, [r3]
 *   @0x2be4e0 add r7, r7, #4
 *   @0x2be4e4 blx r3
 *   @0x2be4e8 mov r1, #0
 *   @0x2be4ec mov r2, #256
 *   @0x2be4f0 str r0, [r5, #-0x4]
 *   @0x2be4f4 bl 0xb65b0 <memset@plt>
 *   @0x2be4f8 str r8, [r7, #0x28]
 *   @0x2be4fc ldr r3, [r4, #0x24]
 *   @0x2be500 cmp r3, r6
 *   @0x2be504 bgt 0x2be4c4 <jinit_inverse_dct+0x48>
 *   @0x2be508 pop {r4, r5, r6, r7, r8, pc}
 *   @0x2be50c .word 0xfffffce4
 *
 * ══ §23/212 GifFreeSavedImages(GifFileType*)  0x2c3234  size 148  37 条（0x2c3234..0x2c32c8）
 * @func 0x2c3234 0x2c32c8  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb655c×2 / GifFreeMapObject(ColorMapObject*) / GifFreeExtensions(int*, ExtensionBlock**) / GifFreeSavedImages(GifFileType*)+0x30
 * 字段偏移 top8: 0x34×3 / 0x18×3 / 0x14×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c3234 push {r4, r5, r6, lr}
 *   @0x2c3238 subs r5, r0, #0
 *   @0x2c323c popeq {r4, r5, r6, pc}
 *   @0x2c3240 ldr r4, [r5, #0x34]
 *   @0x2c3244 cmp r4, #0
 *   @0x2c3248 popeq {r4, r5, r6, pc}
 *   @0x2c324c ldr r3, [r5, #0x18]
 *   @0x2c3250 add r3, r3, r3, lsl #3
 *   @0x2c3254 add r3, r4, r3, lsl #2
 *   @0x2c3258 cmp r4, r3
 *   @0x2c325c bhs 0x2c32c0 <_Z18GifFreeSavedImagesP11GifFileType+0x8c>
 *   @0x2c3260 mov r6, #0
 *   @0x2c3264 ldr r0, [r4, #0x14]
 *   @0x2c3268 cmp r0, #0
 *   @0x2c326c beq 0x2c3278 <_Z18GifFreeSavedImagesP11GifFileType+0x44>
 *   @0x2c3270 bl 0x2c2c48 <_Z16GifFreeMapObjectP14ColorMapObject>
 *   @0x2c3274 str r6, [r4, #0x14]
 *   @0x2c3278 ldr r0, [r4, #0x18]
 *   @0x2c327c cmp r0, #0
 *   @0x2c3280 beq 0x2c3288 <_Z18GifFreeSavedImagesP11GifFileType+0x54>
 *   @0x2c3284 bl 0xb655c <free@plt>
 *   @0x2c3288 add r0, r4, #28
 *   @0x2c328c add r1, r4, #32
 *   @0x2c3290 bl 0x2c2ff8 <_Z17GifFreeExtensionsPiPP14ExtensionBlock>
 *   @0x2c3294 ldr r3, [r5, #0x18]
 *   @0x2c3298 ldr r0, [r5, #0x34]
 *   @0x2c329c add r4, r4, #36
 *   @0x2c32a0 add r3, r3, r3, lsl #3
 *   @0x2c32a4 add r3, r0, r3, lsl #2
 *   @0x2c32a8 cmp r4, r3
 *   @0x2c32ac blo 0x2c3264 <_Z18GifFreeSavedImagesP11GifFileType+0x30>
 *   @0x2c32b0 bl 0xb655c <free@plt>
 *   @0x2c32b4 mov r3, #0
 *   @0x2c32b8 str r3, [r5, #0x34]
 *   @0x2c32bc pop {r4, r5, r6, pc}
 *   @0x2c32c0 mov r0, r4
 *   @0x2c32c4 b 0x2c32b0 <_Z18GifFreeSavedImagesP11GifFileType+0x7c>
 *
 * ══ §24/212 b2ChainShape::ComputeDistance(b2Transform const&, b2Vec2 const&, float*, b2Vec2*, int) const  0x2c4ca4  size 148  37 条（0x2c4ca4..0x2c4d38）
 * @func 0x2c4ca4 0x2c4d38  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2ChainShape::GetChildEdge(b2EdgeShape*, int) const / b2EdgeShape::ComputeDistance(b2Transform const&, b2Vec2 const&, float*, b2Vec2*, int) const
 * 字段偏移 top8: 0x7c×1 / 0x58×1 / 0x5c×1 / 0x8×1 / 0xc×1 / 0x24×1 / 0x28×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c4ca4 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x2c4ca8 sub sp, sp, #60
 *   @0x2c4cac add r5, sp, #8
 *   @0x2c4cb0 ldr r12, [pc, #0x7c]
 *   @0x2c4cb4 ldr r6, [sp, #0x58]
 *   @0x2c4cb8 mov r8, r1
 *   @0x2c4cbc mov r7, r2
 *   @0x2c4cc0 mov r9, r3
 *   @0x2c4cc4 mov r1, r5
 *   @0x2c4cc8 ldr r2, [sp, #0x5c]
 *   @0x2c4ccc ldr r12, [pc, r12]
 *   @0x2c4cd0 mov r4, #0
 *   @0x2c4cd4 add r12, r12, #8
 *   @0x2c4cd8 mov r3, #1
 *   @0x2c4cdc str r12, [sp, #0x8]
 *   @0x2c4ce0 mov r12, #0
 *   @0x2c4ce4 str r3, [sp, #0xc]
 *   @0x2c4ce8 movw r3, #0xd70a
 *   @0x2c4cec str r12, [sp, #0x24]
 *   @0x2c4cf0 movt r3, #0x3c23
 *   @0x2c4cf4 str r12, [sp, #0x28]
 *   @0x2c4cf8 str r3, [sp, #0x10]
 *   @0x2c4cfc str r12, [sp, #0x2c]
 *   @0x2c4d00 str r12, [sp, #0x30]
 *   @0x2c4d04 strb r4, [sp, #0x34]
 *   @0x2c4d08 strb r4, [sp, #0x35]
 *   @0x2c4d0c bl 0x2c4bf4 <_ZNK12b2ChainShape12GetChildEdgeEP11b2EdgeShapei>
 *   @0x2c4d10 str r6, [sp]
 *   @0x2c4d14 mov r0, r5
 *   @0x2c4d18 str r4, [sp, #0x4]
 *   @0x2c4d1c mov r1, r8
 *   @0x2c4d20 mov r2, r7
 *   @0x2c4d24 mov r3, r9
 *   @0x2c4d28 bl 0x2c54fc <_ZNK11b2EdgeShape15ComputeDistanceERK11b2TransformRK6b2Vec2PfPS3_i>
 *   @0x2c4d2c add sp, sp, #60
 *   @0x2c4d30 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x2c4d34 andseq r12, r2, r8, ror #15
 *
 * ══ §25/212 FT_CMap_New  0x2e8376  size 148  37 条（0x2e8376..0x2e840a）
 * @func 0x2e8376 0x2e840a  size 148  37 条
 * 部分覆盖: 本节 37/66 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x3e7eaa / ft_mem_realloc
 * 字段偏移 top8: 0xc×4
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e8376 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2e837a sub sp, #0x14
 *   @0x2e837e mov r11, r1
 *   @0x2e8382 mov r6, r2
 *   @0x2e8386 mov r7, r0
 *   @0x2e838a beq 0x2e8402 <FT_CMap_New+0x8c>
 *   @0x2e838e beq 0x2e8402 <FT_CMap_New+0x8c>
 *   @0x2e8392 cmp r5, #0x0
 *   @0x2e8396 ldr.w r9, [r5, #0x64]
 *   @0x2e839a add.w r10, sp, #0xc
 *   @0x2e839e ldr r1, [r7]
 *   @0x2e83a2 mov r0, r9
 *   @0x2e83a6 blls 0x3e7eaa <error_g0017+0x40b4e>
 *   @0x2e83aa mov r4, r0
 *   @0x2e83ae ldm.w r6, {r0, r1, r2}
 *   @0x2e83b2 str r7, [r4, #0xc]
 *   @0x2e83b6 ldmdavs r11!, {r0, r1, r2} ^
 *   @0x2e83ba cbnz r3, 0x2e83e0 <FT_CMap_New+0x6a>
 *   @0x2e83be mov r0, r9
 *   @0x2e83c2 movs r1, #0x4
 *   @0x2e83c6 mrrcne p4, #0x0, r0, r3, c8
 *   @0x2e83ca bl 0x2e808e <ft_mem_realloc>
 *   @0x2e83ce ldr r3, [sp, #0xc]
 *   @0x2e83d2 cbnz r3, 0x2e83ec <FT_CMap_New+0x76>
 *   @0x2e83d6 adds r2, r3, #0x1
 *   @0x2e83da str.w r4, [r0, r3, lsl #2]
 *   @0x2e83de b 0x2e83f4 <FT_CMap_New+0x7e>
 *   @0x2e83e2 mov r1, r11
 *   @0x2e83e6 str r0, [sp, #0xc]
 *   @0x2e83ea beq 0x2e83bc <FT_CMap_New+0x46>
 *   @0x2e83ee movs r4, #0x0
 *   @0x2e83f2 .word 0xf1b8fbb4
 *   @0x2e83f6 andle r0, r1, r0, lsl #30
 *   @0x2e83fa str.w r4, [r8]
 *   @0x2e83fe ldr r0, [sp, #0xc]
 *   @0x2e8402 movs r0, #0x6
 *   @0x2e8406 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §26/212 FT_Done_Library  0x2e998c  size 148  37 条（0x2e998c..0x2e9a20）
 * @func 0x2e998c 0x2e9a20  size 148  37 条
 * 部分覆盖: 本节 37/69 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2f1de8+0x3eb0 / 0xa0d9b0 / ft_mem_free
 * 字段偏移 top8: 0x10×3 / 0x8×1 / 0x390×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e998c push.w {r0, r1, r2, r4, r5, r6, r7, r8, r9, lr}
 *   @0x2e9990 mov r4, r0
 *   @0x2e9994 beq 0x2e9a0e <FT_Done_Library+0x82>
 *   @0x2e9998 .word 0x260030bc
 *   @0x2e999c subs r3, #0x1
 *   @0x2e99a0 blhs 0x2f5c98 <ps_hints_apply+0x4898>
 *   @0x2e99a4 bgt 0x2e9a12 <FT_Done_Library+0x86>
 *   @0x2e99a8 blmi 0xa0d9b0 <b2_toiTime+0x2b450c>
 *   @0x2e99ac add r3, pc
 *   @0x2e99b0 strhs r0, [r0, #-0x48]
 *   @0x2e99b4 ldr r3, [r4, #0x10]
 *   @0x2e99b8 bhs 0x2e99ec <FT_Done_Library+0x60>
 *   @0x2e99bc ldmdbvs pc, {r0, r2, r7, r8, r9} ^
 *   @0x2e99c0 mov r3, sp
 *   @0x2e99c4 ldr.w r8, [r7]
 *   @0x2e99c8 ldr.w r0, [r8, #0x8]
 *   @0x2e99cc cbz r1, 0x2e99d4 <FT_Done_Library+0x48>
 *   @0x2e99d0 stmdblt r8, {r1, r4, r6, r7, r8, r10, r11, sp, lr, pc} ^
 *   @0x2e99d4 ldr.w r3, [r8]
 *   @0x2e99d8 lsls r3, r3, #0x1f
 *   @0x2e99dc ldr r3, [r7, #0x10]
 *   @0x2e99e0 ldr r0, [r3, #0x8]
 *   @0x2e99e4 udf #0x9f8b
 *   @0x2e99e8 adds r5, #0x1
 *   @0x2e99ec adds r6, #0x4
 *   @0x2e99f0 bne 0x2e99b2 <FT_Done_Library+0x26>
 *   @0x2e99f4 cbz r6, 0x2e9a04 <FT_Done_Library+0x78>
 *   @0x2e99f8 strtmi r0, [r0], -r6, lsl #13
 *   @0x2e99fc ldr r1, [r6, #0x10]
 *   @0x2e9a00 .word 0xe7f6fe91
 *   @0x2e9a04 mov r0, r9
 *   @0x2e9a08 bl 0x2e7336 <ft_mem_free>
 *   @0x2e9a0c b 0x2e9a12 <FT_Done_Library+0x86>
 *   @0x2e9a10 b 0x2e9a14 <FT_Done_Library+0x88>
 *   @0x2e9a14 add sp, #0xc
 *   @0x2e9a18 svclt #0x83f0
 *   @0x2e9a1c ldr r5, [pc, #0x390]
 *
 * ══ §27/212 IBuffer::Copy(int, int, IBuffer*, int)  0xccd04  size 144  36 条（0xccd04..0xccd94）
 * @func 0xccd04 0xccd94  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IBuffer::CopyMemoryToBuffer(IBuffer*, unsigned char*, int, int, int, int, bool, bool, bool)
 * 字段偏移 top8: 0x10×3 / 0x18×2 / 0xc×2 / 0x28×1 / 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xccd04 push {r4, r5, lr}
 *   @0xccd08 subs r4, r3, #0
 *   @0xccd0c sub sp, sp, #28
 *   @0xccd10 mov r12, r0
 *   @0xccd14 mov r3, r1
 *   @0xccd18 beq 0xccd7c <_ZN7IBuffer4CopyEiiPS_i+0x78>
 *   @0xccd1c ldr r0, [r4, #0x18]
 *   @0xccd20 cmp r0, #1
 *   @0xccd24 beq 0xccd8c <_ZN7IBuffer4CopyEiiPS_i+0x88>
 *   @0xccd28 ldr r5, [r4, #0x10]
 *   @0xccd2c rsbs r5, r5, #1
 *   @0xccd30 movlo r5, #0
 *   @0xccd34 cmp r0, #2
 *   @0xccd38 beq 0xccd84 <_ZN7IBuffer4CopyEiiPS_i+0x80>
 *   @0xccd3c mov lr, #0
 *   @0xccd40 ldr r1, [r12, #0xc]
 *   @0xccd44 mov r0, r4
 *   @0xccd48 ldr r4, [r12, #0x10]
 *   @0xccd4c ldr r12, [r12, #0x18]
 *   @0xccd50 str r2, [sp]
 *   @0xccd54 ldr r2, [sp, #0x28]
 *   @0xccd58 str r5, [sp, #0x8]
 *   @0xccd5c str lr, [sp, #0xc]
 *   @0xccd60 str r2, [sp, #0x4]
 *   @0xccd64 subs r2, r12, #2
 *   @0xccd68 rsbs r12, r2, #0
 *   @0xccd6c adcs r12, r12, r2
 *   @0xccd70 mov r2, r4
 *   @0xccd74 str r12, [sp, #0x10]
 *   @0xccd78 bl 0xccabc <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb>
 *   @0xccd7c add sp, sp, #28
 *   @0xccd80 pop {r4, r5, pc}
 *   @0xccd84 mov lr, #1
 *   @0xccd88 b 0xccd40 <_ZN7IBuffer4CopyEiiPS_i+0x3c>
 *   @0xccd8c mov r5, r0
 *   @0xccd90 b 0xccd3c <_ZN7IBuffer4CopyEiiPS_i+0x38>
 *
 * ══ §28/212 CExtensionPackage::Assign(CExtensionPackage*)  0xf5770  size 144  36 条（0xf5770..0xf5800）
 * @func 0xf5770 0xf5800  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYFree(void const*)×2 / YYStrDup(char const*)×2 / CExtensionPackage::Clear() / CExtensionPackage::SetIncludesCount(int) / CExtensionFile::Assign(CExtensionFile*)
 * 字段偏移 top8: 0x4×3 / 0x8×3 / 0x18×3 / 0x14×2 / 0x2×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf5770 push {r4, r5, r6, lr}
 *   @0xf5774 mov r5, r0
 *   @0xf5778 mov r6, r1
 *   @0xf577c bl 0xf563c <_ZN17CExtensionPackage5ClearEv>
 *   @0xf5780 ldr r0, [r5, #0x4]
 *   @0xf5784 cmp r0, #0
 *   @0xf5788 beq 0xf5790 <_ZN17CExtensionPackage6AssignEPS_+0x20>
 *   @0xf578c bl 0xcef90 <_Z6YYFreePKv>
 *   @0xf5790 ldr r0, [r6, #0x4]
 *   @0xf5794 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xf5798 ldr r3, [r5, #0x8]
 *   @0xf579c cmp r3, #0
 *   @0xf57a0 str r0, [r5, #0x4]
 *   @0xf57a4 beq 0xf57b0 <_ZN17CExtensionPackage6AssignEPS_+0x40>
 *   @0xf57a8 mov r0, r3
 *   @0xf57ac bl 0xcef90 <_Z6YYFreePKv>
 *   @0xf57b0 ldr r0, [r6, #0x8]
 *   @0xf57b4 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xf57b8 ldr r1, [r6, #0x18]
 *   @0xf57bc str r0, [r5, #0x8]
 *   @0xf57c0 mov r0, r5
 *   @0xf57c4 bl 0xf5638 <_ZN17CExtensionPackage16SetIncludesCountEi>
 *   @0xf57c8 ldr r3, [r5, #0x18]
 *   @0xf57cc cmp r3, #0
 *   @0xf57d0 pople {r4, r5, r6, pc}
 *   @0xf57d4 mov r4, #0
 *   @0xf57d8 ldr r3, [r6, #0x14]
 *   @0xf57dc ldr r2, [r5, #0x14]
 *   @0xf57e0 ldr r1, [r3, r4, lsl #2]
 *   @0xf57e4 ldr r0, [r2, r4, lsl #2]
 *   @0xf57e8 add r4, r4, #1
 *   @0xf57ec bl 0xf516c <_ZN14CExtensionFile6AssignEPS_>
 *   @0xf57f0 ldr r3, [r5, #0x18]
 *   @0xf57f4 cmp r3, r4
 *   @0xf57f8 bgt 0xf57d8 <_ZN17CExtensionPackage6AssignEPS_+0x68>
 *   @0xf57fc pop {r4, r5, r6, pc}
 *
 * ══ §29/212 F_DsStackSize(RValue&, CInstance*, CInstance*, int, RValue*)  0xfbaf4  size 144  36 条（0xfbaf4..0xfbb84）
 * @func 0xfbaf4 0xfbb84  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_DsStackSize(RValue&, CInstance*, CInstance*, int, RValue*)+0x70 / CDS_Stack::Size()
 * 字段偏移 top8: 0x8×1 / 0x60×1 / 0x50×1 / 0x4×1 / 0x2×1 / 0xc×1 / 0x14×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfbaf4 push {r4, lr}
 *   @0xfbaf8 mov r1, #0
 *   @0xfbafc mov r4, r0
 *   @0xfbb00 ldr r0, [sp, #0x8]
 *   @0xfbb04 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfbb08 cmp r0, #0
 *   @0xfbb0c blt 0xfbb64 <_Z13F_DsStackSizeR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0xfbb10 ldr r3, [pc, #0x60]
 *   @0xfbb14 ldr r3, [pc, r3]
 *   @0xfbb18 ldr r3, [r3]
 *   @0xfbb1c cmp r0, r3
 *   @0xfbb20 bge 0xfbb64 <_Z13F_DsStackSizeR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0xfbb24 ldr r3, [pc, #0x50]
 *   @0xfbb28 ldr r3, [pc, r3]
 *   @0xfbb2c ldr r3, [r3, #0x4]
 *   @0xfbb30 ldr r0, [r3, r0, lsl #2]
 *   @0xfbb34 cmp r0, #0
 *   @0xfbb38 beq 0xfbb64 <_Z13F_DsStackSizeR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0xfbb3c mov r3, #0
 *   @0xfbb40 str r3, [r4, #0xc]
 *   @0xfbb44 bl 0x2052ac <_ZN9CDS_Stack4SizeEv>
 *   @0xfbb48 vmov s15, r0
 *   @0xfbb4c vcvt.f64.s32 d7, s15
 *   @0xfbb50 vmov r0, r1, d7
 *   @0xfbb54 vmov r2, s14
 *   @0xfbb58 mov r3, r1
 *   @0xfbb5c stm r4, {r2, r3}
 *   @0xfbb60 pop {r4, pc}
 *   @0xfbb64 ldr r0, [pc, #0x14]
 *   @0xfbb68 mov r1, #0
 *   @0xfbb6c pop {r4, lr}
 *   @0xfbb70 add r0, pc, r0
 *   @0xfbb74 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfbb78 eoreq r2, pc, r8, ror #6
 *   @0xfbb7c eoreq r2, pc, r8, asr r3
 *   @0xfbb80 eoreq r12, r3, r12, lsl #1
 *
 * ══ §30/212 F_DsListSize(RValue&, CInstance*, CInstance*, int, RValue*)  0xfc350  size 144  36 条（0xfc350..0xfc3e0）
 * @func 0xfc350 0xfc3e0  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_DsListSize(RValue&, CInstance*, CInstance*, int, RValue*)+0x70 / CDS_List::Size()
 * 字段偏移 top8: 0x8×1 / 0x60×1 / 0x50×1 / 0x4×1 / 0x2×1 / 0xc×1 / 0x14×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfc350 push {r4, lr}
 *   @0xfc354 mov r1, #0
 *   @0xfc358 mov r4, r0
 *   @0xfc35c ldr r0, [sp, #0x8]
 *   @0xfc360 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfc364 cmp r0, #0
 *   @0xfc368 blt 0xfc3c0 <_Z12F_DsListSizeR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0xfc36c ldr r3, [pc, #0x60]
 *   @0xfc370 ldr r3, [pc, r3]
 *   @0xfc374 ldr r3, [r3]
 *   @0xfc378 cmp r0, r3
 *   @0xfc37c bge 0xfc3c0 <_Z12F_DsListSizeR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0xfc380 ldr r3, [pc, #0x50]
 *   @0xfc384 ldr r3, [pc, r3]
 *   @0xfc388 ldr r3, [r3, #0x4]
 *   @0xfc38c ldr r0, [r3, r0, lsl #2]
 *   @0xfc390 cmp r0, #0
 *   @0xfc394 beq 0xfc3c0 <_Z12F_DsListSizeR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0xfc398 mov r3, #0
 *   @0xfc39c str r3, [r4, #0xc]
 *   @0xfc3a0 bl 0x2052b8 <_ZN8CDS_List4SizeEv>
 *   @0xfc3a4 vmov s15, r0
 *   @0xfc3a8 vcvt.f64.s32 d7, s15
 *   @0xfc3ac vmov r0, r1, d7
 *   @0xfc3b0 vmov r2, s14
 *   @0xfc3b4 mov r3, r1
 *   @0xfc3b8 stm r4, {r2, r3}
 *   @0xfc3bc pop {r4, pc}
 *   @0xfc3c0 ldr r0, [pc, #0x14]
 *   @0xfc3c4 mov r1, #0
 *   @0xfc3c8 pop {r4, lr}
 *   @0xfc3cc add r0, pc, r0
 *   @0xfc3d0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfc3d4 eoreq r1, pc, r12, lsl #18
 *   @0xfc3d8 .word 0x002f18fc
 *   @0xfc3dc eoreq r11, r3, r0, lsr r8
 *
 * ══ §31/212 F_DsListSetPost(RValue&, CInstance*, CInstance*, int, RValue*)  0xfc630  size 144  36 条（0xfc630..0xfc6c0）
 * @func 0xfc630 0xfc6d0  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / F_DsListSetPost(RValue&, CInstance*, CInstance*, int, RValue*)+0x70
 * 字段偏移 top8: 0x10×1 / 0x5c×1 / 0x4c×1 / 0x4×1 / 0x2×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfc630 push {r4, r5, r6, lr}
 *   @0xfc634 mov r1, #0
 *   @0xfc638 ldr r4, [sp, #0x10]
 *   @0xfc63c mov r6, r0
 *   @0xfc640 mov r0, r4
 *   @0xfc644 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfc648 cmp r0, #0
 *   @0xfc64c blt 0xfc6a0 <_Z15F_DsListSetPostR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0xfc650 ldr r1, [pc, #0x5c]
 *   @0xfc654 ldr r1, [pc, r1]
 *   @0xfc658 ldr r1, [r1]
 *   @0xfc65c cmp r0, r1
 *   @0xfc660 bge 0xfc6a0 <_Z15F_DsListSetPostR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0xfc664 ldr r1, [pc, #0x4c]
 *   @0xfc668 ldr r1, [pc, r1]
 *   @0xfc66c ldr r3, [r1, #0x4]
 *   @0xfc670 ldr r5, [r3, r0, lsl #2]
 *   @0xfc674 cmp r5, #0
 *   @0xfc678 beq 0xfc6a0 <_Z15F_DsListSetPostR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0xfc67c mov r0, r4
 *   @0xfc680 mov r1, #1
 *   @0xfc684 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfc688 add r2, r4, #32
 *   @0xfc68c mov r3, r6
 *   @0xfc690 mov r1, r0
 *   @0xfc694 mov r0, r5
 *   @0xfc698 pop {r4, r5, r6, lr}
 *   @0xfc69c b 0x2060c0 <_ZN8CDS_List3SetEiP6RValueS1_>
 *   @0xfc6a0 ldr r0, [pc, #0x14]
 *   @0xfc6a4 mov r1, #0
 *   @0xfc6a8 pop {r4, r5, r6, lr}
 *   @0xfc6ac add r0, pc, r0
 *   @0xfc6b0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfc6b4 eoreq r1, pc, r8, lsr #12
 *   @0xfc6b8 eoreq r1, pc, r8, lsl r6
 *   @0xfc6bc eoreq r11, r3, r0, asr r5
 *
 * ══ §32/212 F_DsPrioritySize(RValue&, CInstance*, CInstance*, int, RValue*)  0xfcbc0  size 144  36 条（0xfcbc0..0xfcc50）
 * @func 0xfcbc0 0xfcc50  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_DsPrioritySize(RValue&, CInstance*, CInstance*, int, RValue*)+0x70 / CDS_Priority::Size()
 * 字段偏移 top8: 0x8×1 / 0x60×1 / 0x50×1 / 0x4×1 / 0x2×1 / 0xc×1 / 0x14×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfcbc0 push {r4, lr}
 *   @0xfcbc4 mov r1, #0
 *   @0xfcbc8 mov r4, r0
 *   @0xfcbcc ldr r0, [sp, #0x8]
 *   @0xfcbd0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfcbd4 cmp r0, #0
 *   @0xfcbd8 blt 0xfcc30 <_Z16F_DsPrioritySizeR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0xfcbdc ldr r3, [pc, #0x60]
 *   @0xfcbe0 ldr r3, [pc, r3]
 *   @0xfcbe4 ldr r3, [r3]
 *   @0xfcbe8 cmp r0, r3
 *   @0xfcbec bge 0xfcc30 <_Z16F_DsPrioritySizeR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0xfcbf0 ldr r3, [pc, #0x50]
 *   @0xfcbf4 ldr r3, [pc, r3]
 *   @0xfcbf8 ldr r3, [r3, #0x4]
 *   @0xfcbfc ldr r0, [r3, r0, lsl #2]
 *   @0xfcc00 cmp r0, #0
 *   @0xfcc04 beq 0xfcc30 <_Z16F_DsPrioritySizeR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0xfcc08 mov r3, #0
 *   @0xfcc0c str r3, [r4, #0xc]
 *   @0xfcc10 bl 0x2052cc <_ZN12CDS_Priority4SizeEv>
 *   @0xfcc14 vmov s15, r0
 *   @0xfcc18 vcvt.f64.s32 d7, s15
 *   @0xfcc1c vmov r0, r1, d7
 *   @0xfcc20 vmov r2, s14
 *   @0xfcc24 mov r3, r1
 *   @0xfcc28 stm r4, {r2, r3}
 *   @0xfcc2c pop {r4, pc}
 *   @0xfcc30 ldr r0, [pc, #0x14]
 *   @0xfcc34 mov r1, #0
 *   @0xfcc38 pop {r4, lr}
 *   @0xfcc3c add r0, pc, r0
 *   @0xfcc40 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfcc44 mlaeq pc, r4, r2, r1
 *   @0xfcc48 eoreq r1, pc, r4, lsl #5
 *   @0xfcc4c eoreq r10, r3, r0, asr #31
 *
 * ══ §33/212 F_DsGridWidth(RValue&, CInstance*, CInstance*, int, RValue*)  0xfeaf8  size 144  36 条（0xfeaf8..0xfeb88）
 * @func 0xfeaf8 0xfeb98  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_DsGridWidth(RValue&, CInstance*, CInstance*, int, RValue*)+0x70
 * 字段偏移 top8: 0x4×3 / 0x8×1 / 0xc×1 / 0x50×1 / 0x40×1 / 0x2×1 / 0x14×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfeaf8 push {r4, lr}
 *   @0xfeafc mov r1, #0
 *   @0xfeb00 mov r4, r0
 *   @0xfeb04 ldr r0, [sp, #0x8]
 *   @0xfeb08 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfeb0c mov r3, #0
 *   @0xfeb10 str r3, [r4, #0xc]
 *   @0xfeb14 str r3, [r4]
 *   @0xfeb18 str r3, [r4, #0x4]
 *   @0xfeb1c cmp r0, #0
 *   @0xfeb20 blt 0xfeb68 <_Z13F_DsGridWidthR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0xfeb24 ldr r3, [pc, #0x50]
 *   @0xfeb28 ldr r3, [pc, r3]
 *   @0xfeb2c ldr r3, [r3]
 *   @0xfeb30 cmp r0, r3
 *   @0xfeb34 bge 0xfeb68 <_Z13F_DsGridWidthR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0xfeb38 ldr r3, [pc, #0x40]
 *   @0xfeb3c ldr r3, [pc, r3]
 *   @0xfeb40 ldr r3, [r3, #0x4]
 *   @0xfeb44 ldr r3, [r3, r0, lsl #2]
 *   @0xfeb48 cmp r3, #0
 *   @0xfeb4c beq 0xfeb68 <_Z13F_DsGridWidthR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0xfeb50 ldr r2, [r3, #0x4]
 *   @0xfeb54 vmov s15, r2
 *   @0xfeb58 vcvt.f64.s32 d7, s15
 *   @0xfeb5c vmov r2, r3, d7
 *   @0xfeb60 stm r4, {r2, r3}
 *   @0xfeb64 pop {r4, pc}
 *   @0xfeb68 ldr r0, [pc, #0x14]
 *   @0xfeb6c mov r1, #0
 *   @0xfeb70 pop {r4, lr}
 *   @0xfeb74 add r0, pc, r0
 *   @0xfeb78 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfeb7c eoreq pc, lr, r12, asr r3
 *   @0xfeb80 eoreq pc, lr, r12, asr #6
 *   @0xfeb84 eoreq r9, r3, r8, lsl #1
 *
 * ══ §34/212 F_DsGridHeight(RValue&, CInstance*, CInstance*, int, RValue*)  0xfeb88  size 144  36 条（0xfeb88..0xfec18）
 * @func 0xfeb88 0xfec18  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_DsGridHeight(RValue&, CInstance*, CInstance*, int, RValue*)+0x70
 * 字段偏移 top8: 0x8×2 / 0x4×2 / 0xc×1 / 0x50×1 / 0x40×1 / 0x2×1 / 0x14×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfeb88 push {r4, lr}
 *   @0xfeb8c mov r1, #0
 *   @0xfeb90 mov r4, r0
 *   @0xfeb94 ldr r0, [sp, #0x8]
 *   @0xfeb98 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfeb9c mov r3, #0
 *   @0xfeba0 str r3, [r4, #0xc]
 *   @0xfeba4 str r3, [r4]
 *   @0xfeba8 str r3, [r4, #0x4]
 *   @0xfebac cmp r0, #0
 *   @0xfebb0 blt 0xfebf8 <_Z14F_DsGridHeightR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0xfebb4 ldr r3, [pc, #0x50]
 *   @0xfebb8 ldr r3, [pc, r3]
 *   @0xfebbc ldr r3, [r3]
 *   @0xfebc0 cmp r0, r3
 *   @0xfebc4 bge 0xfebf8 <_Z14F_DsGridHeightR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0xfebc8 ldr r3, [pc, #0x40]
 *   @0xfebcc ldr r3, [pc, r3]
 *   @0xfebd0 ldr r3, [r3, #0x4]
 *   @0xfebd4 ldr r3, [r3, r0, lsl #2]
 *   @0xfebd8 cmp r3, #0
 *   @0xfebdc beq 0xfebf8 <_Z14F_DsGridHeightR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0xfebe0 ldr r2, [r3, #0x8]
 *   @0xfebe4 vmov s15, r2
 *   @0xfebe8 vcvt.f64.s32 d7, s15
 *   @0xfebec vmov r2, r3, d7
 *   @0xfebf0 stm r4, {r2, r3}
 *   @0xfebf4 pop {r4, pc}
 *   @0xfebf8 ldr r0, [pc, #0x14]
 *   @0xfebfc mov r1, #0
 *   @0xfec00 pop {r4, lr}
 *   @0xfec04 add r0, pc, r0
 *   @0xfec08 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfec0c eoreq pc, lr, r12, asr #5
 *   @0xfec10 .word 0x002ef2bc
 *   @0xfec14 .word 0x00238ff8
 *
 * ══ §35/212 Setup_SetupDataStructureFunctions(bool)  0x1004ec  size 144  36 条（0x1004ec..0x10057c）
 * @func 0x1004ec 0x10057c  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Function_Replace(char const*, void (*)(RValue&, CInstance*, CInstance*, int, RValue*))×2
 * 字段偏移 top8: 0x54×2 / 0x48×2 / 0x38×2 / 0x2c×2 / 0x5c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1004ec push {r4, lr}
 *   @0x1004f0 cmp r0, #0
 *   @0x1004f4 ldr r4, [pc, #0x5c]
 *   @0x1004f8 add r4, pc, r4
 *   @0x1004fc bne 0x10052c <_Z33Setup_SetupDataStructureFunctionsb+0x40>
 *   @0x100500 ldr r3, [pc, #0x54]
 *   @0x100504 ldr r0, [pc, #0x54]
 *   @0x100508 ldr r1, [r4, r3]
 *   @0x10050c add r0, pc, r0
 *   @0x100510 bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E>
 *   @0x100514 ldr r3, [pc, #0x48]
 *   @0x100518 ldr r0, [pc, #0x48]
 *   @0x10051c ldr r1, [r4, r3]
 *   @0x100520 add r0, pc, r0
 *   @0x100524 pop {r4, lr}
 *   @0x100528 b 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E>
 *   @0x10052c ldr r3, [pc, #0x38]
 *   @0x100530 ldr r0, [pc, #0x38]
 *   @0x100534 ldr r1, [r4, r3]
 *   @0x100538 add r0, pc, r0
 *   @0x10053c bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E>
 *   @0x100540 ldr r3, [pc, #0x2c]
 *   @0x100544 ldr r0, [pc, #0x2c]
 *   @0x100548 ldr r1, [r4, r3]
 *   @0x10054c add r0, pc, r0
 *   @0x100550 pop {r4, lr}
 *   @0x100554 b 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E>
 *   @0x100558 eoreq r1, pc, r8, asr r7
 *   @0x10055c .word 0xffffc244
 *   @0x100560 eoreq r7, r3, r12, lsr #16
 *   @0x100564 .word 0xffffc248
 *   @0x100568 eoreq r7, r3, r4, lsr #16
 *   @0x10056c .word 0xffffc24c
 *   @0x100570 eoreq r7, r3, r0, lsl #16
 *   @0x100574 .word 0xffffc250
 *   @0x100578 .word 0x002377f8
 *
 * ══ §36/212 dsMapAddInt  0x101850  size 144  36 条（0x101850..0x1018e0）
 * @func 0x101850 0x1018f0  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYSetString(RValue*, char const*) / F_DsMapAdd(RValue&, CInstance*, CInstance*, int, RValue*)
 * 字段偏移 top8: 0x4c×2 / 0xc×2 / 0x3c×1 / 0x10×1 / 0x28×1 / 0x38×1 / 0x48×1 / 0x2c×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x101850 vmov s15, r0
 *   @0x101854 mvn r3, #-16777216
 *   @0x101858 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x10185c vcvt.f64.s32 d6, s15
 *   @0x101860 sub sp, sp, #84
 *   @0x101864 mov r6, #0
 *   @0x101868 add r7, sp, #80
 *   @0x10186c add r0, sp, #48
 *   @0x101870 mov r4, #0
 *   @0x101874 mov r5, #0
 *   @0x101878 str r3, [sp, #0x3c]
 *   @0x10187c str r3, [sp, #0x4c]
 *   @0x101880 str r6, [sp, #0x10]
 *   @0x101884 vmov r8, r9, d6
 *   @0x101888 str r6, [sp, #0x28]
 *   @0x10188c str r6, [sp, #0x38]
 *   @0x101890 str r6, [sp, #0x48]
 *   @0x101894 str r6, [sp, #0x2c]
 *   @0x101898 strd r4, r5, [sp, #48]
 *   @0x10189c strd r4, r5, [sp, #64]
 *   @0x1018a0 strd r8, r9, [r7, #-48]!
 *   @0x1018a4 str r2, [sp, #0xc]
 *   @0x1018a8 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x1018ac ldr r2, [sp, #0xc]
 *   @0x1018b0 mov r1, r6
 *   @0x1018b4 str r7, [sp]
 *   @0x1018b8 add r0, sp, #16
 *   @0x1018bc mov r3, #3
 *   @0x1018c0 str r6, [sp, #0x4c]
 *   @0x1018c4 vmov s13, r2
 *   @0x1018c8 mov r2, r6
 *   @0x1018cc vcvt.f64.s32 d7, s13
 *   @0x1018d0 vstr d7, [sp, #64]
 *   @0x1018d4 bl 0xff014 <_Z10F_DsMapAddR6RValueP9CInstanceS2_iPS_>
 *   @0x1018d8 add sp, sp, #84
 *   @0x1018dc pop {r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §37/212 dsMapAddString  0x1019f4  size 144  36 条（0x1019f4..0x101a84）
 * @func 0x1019f4 0x101a94  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYSetString(RValue*, char const*)×2 / F_DsMapAdd(RValue&, CInstance*, CInstance*, int, RValue*)
 * 字段偏移 top8: 0x14×1 / 0x34×1 / 0x44×1 / 0x10×1 / 0x20×1 / 0x30×1 / 0x40×1 / 0x24×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1019f4 vmov s13, r0
 *   @0x1019f8 mvn r3, #-16777216
 *   @0x1019fc push {r4, r5, r6, r7, r8, lr}
 *   @0x101a00 vcvt.f64.s32 d7, s13
 *   @0x101a04 sub sp, sp, #72
 *   @0x101a08 mov r4, #0
 *   @0x101a0c mov r5, #0
 *   @0x101a10 add r7, sp, #72
 *   @0x101a14 strd r4, r5, [sp, #8]
 *   @0x101a18 mov r8, r2
 *   @0x101a1c strd r4, r5, [sp, #40]
 *   @0x101a20 add r0, sp, #40
 *   @0x101a24 strd r4, r5, [sp, #56]
 *   @0x101a28 mov r6, #0
 *   @0x101a2c str r3, [sp, #0x14]
 *   @0x101a30 vmov r4, r5, d7
 *   @0x101a34 str r3, [sp, #0x34]
 *   @0x101a38 str r3, [sp, #0x44]
 *   @0x101a3c str r6, [sp, #0x10]
 *   @0x101a40 str r6, [sp, #0x20]
 *   @0x101a44 str r6, [sp, #0x30]
 *   @0x101a48 str r6, [sp, #0x40]
 *   @0x101a4c str r6, [sp, #0x24]
 *   @0x101a50 strd r4, r5, [r7, #-48]!
 *   @0x101a54 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x101a58 mov r1, r8
 *   @0x101a5c add r0, sp, #56
 *   @0x101a60 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x101a64 mov r1, r6
 *   @0x101a68 str r7, [sp]
 *   @0x101a6c mov r2, r6
 *   @0x101a70 add r0, sp, #8
 *   @0x101a74 mov r3, #3
 *   @0x101a78 bl 0xff014 <_Z10F_DsMapAddR6RValueP9CInstanceS2_iPS_>
 *   @0x101a7c add sp, sp, #72
 *   @0x101a80 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §38/212 dsMapAddList  0x101b0c  size 144  36 条（0x101b0c..0x101b9c）
 * @func 0x101b0c 0x101b9c  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYSetString(RValue*, char const*) / F_DsMapAddList(RValue&, CInstance*, CInstance*, int, RValue*)
 * 字段偏移 top8: 0x4c×2 / 0xc×2 / 0x3c×1 / 0x10×1 / 0x28×1 / 0x38×1 / 0x48×1 / 0x2c×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x101b0c vmov s15, r0
 *   @0x101b10 mvn r3, #-16777216
 *   @0x101b14 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x101b18 vcvt.f64.s32 d6, s15
 *   @0x101b1c sub sp, sp, #84
 *   @0x101b20 mov r6, #0
 *   @0x101b24 add r7, sp, #80
 *   @0x101b28 add r0, sp, #48
 *   @0x101b2c mov r4, #0
 *   @0x101b30 mov r5, #0
 *   @0x101b34 str r3, [sp, #0x3c]
 *   @0x101b38 str r3, [sp, #0x4c]
 *   @0x101b3c str r6, [sp, #0x10]
 *   @0x101b40 vmov r8, r9, d6
 *   @0x101b44 str r6, [sp, #0x28]
 *   @0x101b48 str r6, [sp, #0x38]
 *   @0x101b4c str r6, [sp, #0x48]
 *   @0x101b50 str r6, [sp, #0x2c]
 *   @0x101b54 strd r4, r5, [sp, #48]
 *   @0x101b58 strd r4, r5, [sp, #64]
 *   @0x101b5c strd r8, r9, [r7, #-48]!
 *   @0x101b60 str r2, [sp, #0xc]
 *   @0x101b64 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x101b68 ldr r2, [sp, #0xc]
 *   @0x101b6c mov r1, r6
 *   @0x101b70 str r7, [sp]
 *   @0x101b74 add r0, sp, #16
 *   @0x101b78 mov r3, #3
 *   @0x101b7c str r6, [sp, #0x4c]
 *   @0x101b80 vmov s13, r2
 *   @0x101b84 mov r2, r6
 *   @0x101b88 vcvt.f64.s32 d7, s13
 *   @0x101b8c vstr d7, [sp, #64]
 *   @0x101b90 bl 0xff228 <_Z14F_DsMapAddListR6RValueP9CInstanceS2_iPS_>
 *   @0x101b94 add sp, sp, #84
 *   @0x101b98 pop {r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §39/212 F_MathAngleDifference(RValue&, CInstance*, CInstance*, int, RValue*)  0x10f310  size 144  36 条（0x10f310..0x10f3a0）
 * @func 0x10f310 0x10f3a0  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / 0xb6790×2
 * 字段偏移 top8: 0x18×1 / 0xc×1
 * VFP 指令 15 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10f310 push {r4, r5, r6, lr}
 *   @0x10f314 vpush {d8}
 *   @0x10f318 mov r4, r0
 *   @0x10f31c ldr r6, [sp, #0x18]
 *   @0x10f320 mov r1, #0
 *   @0x10f324 mov r5, #0
 *   @0x10f328 movt r5, #0x43b4
 *   @0x10f32c mov r0, r6
 *   @0x10f330 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10f334 mov r1, #1
 *   @0x10f338 vmov s16, r0
 *   @0x10f33c mov r0, r6
 *   @0x10f340 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10f344 mov r3, #0
 *   @0x10f348 mov r1, r5
 *   @0x10f34c str r3, [r4, #0xc]
 *   @0x10f350 vmov s12, r0
 *   @0x10f354 vsub.f32 s12, s16, s12
 *   @0x10f358 vmov r0, s12
 *   @0x10f35c bl 0xb6790 <fmodf@plt>
 *   @0x10f360 vldr s15, [pc, #48]
 *   @0x10f364 mov r1, r5
 *   @0x10f368 vmov s13, r0
 *   @0x10f36c vadd.f32 s13, s13, s15
 *   @0x10f370 vmov r0, s13
 *   @0x10f374 bl 0xb6790 <fmodf@plt>
 *   @0x10f378 vldr s15, [pc, #28]
 *   @0x10f37c vmov s14, r0
 *   @0x10f380 vsub.f32 s15, s14, s15
 *   @0x10f384 vcvt.f64.f32 d6, s15
 *   @0x10f388 vmov r2, r3, d6
 *   @0x10f38c stm r4, {r2, r3}
 *   @0x10f390 vpop {d8}
 *   @0x10f394 pop {r4, r5, r6, pc}
 *   @0x10f398 strmi r0, [r7], #-0
 *   @0x10f39c teqmi r4, #0
 *
 * ══ §40/212 F_ArraySet2D(RValue&, CInstance*, CInstance*, int, RValue*)  0x10f5b4  size 144  36 条（0x10f5b4..0x10f644）
 * @func 0x10f5b4 0x10f644  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2
 * 字段偏移 top8: 0xc×2 / 0x10×1 / 0x64×1 / 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10f5b4 cmp r3, #4
 *   @0x10f5b8 push {r4, r5, r6, lr}
 *   @0x10f5bc ldr r4, [sp, #0x10]
 *   @0x10f5c0 beq 0x10f5e0 <_Z12F_ArraySet2DR6RValueP9CInstanceS2_iPS_+0x2c>
 *   @0x10f5c4 ldr r3, [r4, #0xc]
 *   @0x10f5c8 cmp r3, #2
 *   @0x10f5cc beq 0x10f5f8 <_Z12F_ArraySet2DR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x10f5d0 ldr r0, [pc, #0x64]
 *   @0x10f5d4 pop {r4, r5, r6, lr}
 *   @0x10f5d8 add r0, pc, r0
 *   @0x10f5dc b 0xd547c <_Z7YYErrorPKcz>
 *   @0x10f5e0 ldr r5, [r4, #0xc]
 *   @0x10f5e4 cmp r5, #2
 *   @0x10f5e8 bne 0x10f5d0 <_Z12F_ArraySet2DR6RValueP9CInstanceS2_iPS_+0x1c>
 *   @0x10f5ec ldr r3, [r4]
 *   @0x10f5f0 cmp r3, #0
 *   @0x10f5f4 bne 0x10f608 <_Z12F_ArraySet2DR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x10f5f8 ldr r0, [pc, #0x40]
 *   @0x10f5fc pop {r4, r5, r6, lr}
 *   @0x10f600 add r0, pc, r0
 *   @0x10f604 b 0xd547c <_Z7YYErrorPKcz>
 *   @0x10f608 mov r0, r4
 *   @0x10f60c mov r1, #1
 *   @0x10f610 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x10f614 mov r1, r5
 *   @0x10f618 mov r6, r0
 *   @0x10f61c mov r0, r4
 *   @0x10f620 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x10f624 mov r2, #32000
 *   @0x10f628 add r1, r4, #48
 *   @0x10f62c mla r2, r2, r6, r0
 *   @0x10f630 mov r0, r4
 *   @0x10f634 pop {r4, r5, r6, lr}
 *   @0x10f638 b 0xcfcb4 <_Z16SET_RValue_ArrayP6RValueS0_i>
 *   @0x10f63c eoreq r9, r2, r0, asr r9
 *   @0x10f640 eoreq r9, r2, r4, asr r9
 *
 * ══ §41/212 F_StringCount(RValue&, CInstance*, CInstance*, int, RValue*)  0x110c88  size 144  36 条（0x110c88..0x110d18）
 * @func 0x110c88 0x110d18  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)×2 / 0xb6538 / F_StringCount(RValue&, CInstance*, CInstance*, int, RValue*)+0x68 / utf8_strstr(char const*, char const*)
 * 字段偏移 top8: 0x18×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x110c88 push {r4, r5, r6, r7, r8, lr}
 *   @0x110c8c mov r1, #0
 *   @0x110c90 ldr r4, [sp, #0x18]
 *   @0x110c94 mov r8, r0
 *   @0x110c98 mov r0, r4
 *   @0x110c9c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x110ca0 mov r1, #1
 *   @0x110ca4 mov r7, r0
 *   @0x110ca8 mov r0, r4
 *   @0x110cac bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x110cb0 mov r4, r0
 *   @0x110cb4 bl 0xb6538 <strlen@plt>
 *   @0x110cb8 add r6, r4, r0
 *   @0x110cbc cmp r4, r6
 *   @0x110cc0 bhs 0x110d0c <_Z13F_StringCountR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x110cc4 mov r5, #0
 *   @0x110cc8 b 0x110cd8 <_Z13F_StringCountR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x110ccc cmp r6, r4
 *   @0x110cd0 add r5, r5, #1
 *   @0x110cd4 bls 0x110cf0 <_Z13F_StringCountR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x110cd8 mov r0, r4
 *   @0x110cdc mov r1, r7
 *   @0x110ce0 bl 0x110c04 <_Z11utf8_strstrPKcS0_>
 *   @0x110ce4 cmp r0, #0
 *   @0x110ce8 add r4, r0, #1
 *   @0x110cec bne 0x110ccc <_Z13F_StringCountR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x110cf0 vmov s15, r5
 *   @0x110cf4 vcvt.f64.s32 d7, s15
 *   @0x110cf8 vmov r2, r3, d7
 *   @0x110cfc mov r1, #0
 *   @0x110d00 stm r8, {r2, r3}
 *   @0x110d04 str r1, [r8, #0xc]
 *   @0x110d08 pop {r4, r5, r6, r7, r8, pc}
 *   @0x110d0c mov r2, #0
 *   @0x110d10 mov r3, #0
 *   @0x110d14 b 0x110cfc <_Z13F_StringCountR6RValueP9CInstanceS2_iPS_+0x74>
 *
 * ══ §42/212 UTF8ToASCII(char const*)  0x1110a0  size 144  36 条（0x1110a0..0x111130）
 * @func 0x1110a0 0x111140  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: utf8_strlen / MemoryManager::Alloc(unsigned int, char const*, int, bool) / utf8_extract_char
 * 字段偏移 top8: 0x60×1 / 0x-4×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1110a0 push {r4, r5, r6, r7, lr}
 *   @0x1110a4 subs r5, r0, #0
 *   @0x1110a8 sub sp, sp, #12
 *   @0x1110ac beq 0x111124 <_Z11UTF8ToASCIIPKc+0x84>
 *   @0x1110b0 ldrb r7, [r5]
 *   @0x1110b4 cmp r7, #0
 *   @0x1110b8 moveq r0, r7
 *   @0x1110bc beq 0x11111c <_Z11UTF8ToASCIIPKc+0x7c>
 *   @0x1110c0 bl 0x110648 <utf8_strlen>
 *   @0x1110c4 ldr r1, [pc, #0x60]
 *   @0x1110c8 mov r3, #1
 *   @0x1110cc mov r2, #1536
 *   @0x1110d0 add r1, pc, r1
 *   @0x1110d4 add r4, sp, #8
 *   @0x1110d8 add r0, r0, r3
 *   @0x1110dc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1110e0 str r5, [r4, #-0x4]!
 *   @0x1110e4 mov r3, r5
 *   @0x1110e8 mov r7, r0
 *   @0x1110ec mov r6, r0
 *   @0x1110f0 b 0x111104 <_Z11UTF8ToASCIIPKc+0x64>
 *   @0x1110f4 bl 0x10fb38 <utf8_extract_char>
 *   @0x1110f8 cmp r0, #127
 *   @0x1110fc strbls r0, [r6], #1
 *   @0x111100 ldr r3, [sp, #0x4]
 *   @0x111104 ldrb r3, [r3]
 *   @0x111108 mov r0, r4
 *   @0x11110c cmp r3, #0
 *   @0x111110 bne 0x1110f4 <_Z11UTF8ToASCIIPKc+0x54>
 *   @0x111114 mov r0, r7
 *   @0x111118 strb r3, [r6]
 *   @0x11111c add sp, sp, #12
 *   @0x111120 pop {r4, r5, r6, r7, pc}
 *   @0x111124 mov r0, r5
 *   @0x111128 b 0x11111c <_Z11UTF8ToASCIIPKc+0x7c>
 *   @0x11112c eoreq r7, r2, r4, ror sp
 *
 * ══ §43/212 F_MakeColorHSV(RValue&, CInstance*, CInstance*, int, RValue*)  0x11aa50  size 144  36 条（0x11aa50..0x11aae0）
 * @func 0x11aa50 0x11aae0  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / Color_HSV(int, int, int) / Color_HSVToColor(THSV&)
 * 字段偏移 top8: 0x20×1 / 0xc×1 / 0x4×1 / 0x5×1 / 0x6×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11aa50 push {r4, r5, r6, r7, lr}
 *   @0x11aa54 sub sp, sp, #12
 *   @0x11aa58 mov r5, r0
 *   @0x11aa5c mov r1, #0
 *   @0x11aa60 ldr r4, [sp, #0x20]
 *   @0x11aa64 str r1, [r0, #0xc]
 *   @0x11aa68 mov r0, r4
 *   @0x11aa6c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11aa70 mov r1, #1
 *   @0x11aa74 mov r7, r0
 *   @0x11aa78 mov r0, r4
 *   @0x11aa7c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11aa80 mov r1, #2
 *   @0x11aa84 mov r6, r0
 *   @0x11aa88 mov r0, r4
 *   @0x11aa8c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11aa90 mov r1, r6
 *   @0x11aa94 mov r2, r0
 *   @0x11aa98 mov r0, r7
 *   @0x11aa9c bl 0x20f9d8 <_Z9Color_HSViii>
 *   @0x11aaa0 mov r3, r0
 *   @0x11aaa4 add r0, sp, #4
 *   @0x11aaa8 ubfx r2, r3, #0x8, #0x8
 *   @0x11aaac strb r3, [sp, #0x4]
 *   @0x11aab0 strb r2, [sp, #0x5]
 *   @0x11aab4 ubfx r3, r3, #0x10, #0x8
 *   @0x11aab8 strb r3, [sp, #0x6]
 *   @0x11aabc bl 0x20feac <_Z16Color_HSVToColorR4THSV>
 *   @0x11aac0 vmov s15, r0
 *   @0x11aac4 vcvt.f64.u32 d7, s15
 *   @0x11aac8 vmov r0, r1, d7
 *   @0x11aacc vmov r2, s14
 *   @0x11aad0 mov r3, r1
 *   @0x11aad4 stm r5, {r2, r3}
 *   @0x11aad8 add sp, sp, #12
 *   @0x11aadc pop {r4, r5, r6, r7, pc}
 *
 * ══ §44/212 F_TileGetLeft(RValue&, CInstance*, CInstance*, int, RValue*)  0x11ffec  size 144  36 条（0x11ffec..0x12007c）
 * @func 0x11ffec 0x12008c  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CRoom::FindTile(int) / F_TileGetLeft(RValue&, CInstance*, CInstance*, int, RValue*)+0x6c
 * 字段偏移 top8: 0x18×2 / 0xc×2 / 0x78×1 / 0xb8×1 / 0x4×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11ffec push {r3, r4, r5, r6, r7, lr}
 *   @0x11fff0 mov r5, r0
 *   @0x11fff4 ldr r4, [pc, #0x78]
 *   @0x11fff8 mov r6, #0
 *   @0x11fffc mov r1, r6
 *   @0x120000 ldr r0, [sp, #0x18]
 *   @0x120004 ldr r4, [pc, r4]
 *   @0x120008 str r6, [r5, #0xc]
 *   @0x12000c ldr r7, [r4]
 *   @0x120010 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x120014 mov r1, r0
 *   @0x120018 mov r0, r7
 *   @0x12001c bl 0x1af2bc <_ZN5CRoom8FindTileEi>
 *   @0x120020 cmp r0, #0
 *   @0x120024 blt 0x120058 <_Z13F_TileGetLeftR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x120028 ldr r3, [r4]
 *   @0x12002c ldr r2, [r3, #0xb8]
 *   @0x120030 cmp r0, r2
 *   @0x120034 rsblt r0, r0, r0, lsl #3
 *   @0x120038 ldrlt r3, [r3, #0xc0]
 *   @0x12003c addlt r6, r3, r0, lsl #3
 *   @0x120040 ldr r2, [r6, #0xc]
 *   @0x120044 vmov s15, r2
 *   @0x120048 vcvt.f64.s32 d7, s15
 *   @0x12004c vmov r2, r3, d7
 *   @0x120050 stm r5, {r2, r3}
 *   @0x120054 pop {r3, r4, r5, r6, r7, pc}
 *   @0x120058 ldr r0, [pc, #0x18]
 *   @0x12005c mov r1, r6
 *   @0x120060 str r6, [r5]
 *   @0x120064 str r6, [r5, #0x4]
 *   @0x120068 add r0, pc, r0
 *   @0x12006c pop {r3, r4, r5, r6, r7, lr}
 *   @0x120070 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x120074 eoreq sp, r12, r4, lsr #18
 *   @0x120078 mlaeq r1, r4, r1, r10
 *
 * ══ §45/212 F_TileGetTop(RValue&, CInstance*, CInstance*, int, RValue*)  0x12007c  size 144  36 条（0x12007c..0x12010c）
 * @func 0x12007c 0x12011c  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CRoom::FindTile(int) / F_TileGetTop(RValue&, CInstance*, CInstance*, int, RValue*)+0x6c
 * 字段偏移 top8: 0x18×2 / 0x78×1 / 0xc×1 / 0xb8×1 / 0x10×1 / 0x4×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12007c push {r3, r4, r5, r6, r7, lr}
 *   @0x120080 mov r5, r0
 *   @0x120084 ldr r4, [pc, #0x78]
 *   @0x120088 mov r6, #0
 *   @0x12008c mov r1, r6
 *   @0x120090 ldr r0, [sp, #0x18]
 *   @0x120094 ldr r4, [pc, r4]
 *   @0x120098 str r6, [r5, #0xc]
 *   @0x12009c ldr r7, [r4]
 *   @0x1200a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1200a4 mov r1, r0
 *   @0x1200a8 mov r0, r7
 *   @0x1200ac bl 0x1af2bc <_ZN5CRoom8FindTileEi>
 *   @0x1200b0 cmp r0, #0
 *   @0x1200b4 blt 0x1200e8 <_Z12F_TileGetTopR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x1200b8 ldr r3, [r4]
 *   @0x1200bc ldr r2, [r3, #0xb8]
 *   @0x1200c0 cmp r0, r2
 *   @0x1200c4 rsblt r0, r0, r0, lsl #3
 *   @0x1200c8 ldrlt r3, [r3, #0xc0]
 *   @0x1200cc addlt r6, r3, r0, lsl #3
 *   @0x1200d0 ldr r2, [r6, #0x10]
 *   @0x1200d4 vmov s15, r2
 *   @0x1200d8 vcvt.f64.s32 d7, s15
 *   @0x1200dc vmov r2, r3, d7
 *   @0x1200e0 stm r5, {r2, r3}
 *   @0x1200e4 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1200e8 ldr r0, [pc, #0x18]
 *   @0x1200ec mov r1, r6
 *   @0x1200f0 str r6, [r5]
 *   @0x1200f4 str r6, [r5, #0x4]
 *   @0x1200f8 add r0, pc, r0
 *   @0x1200fc pop {r3, r4, r5, r6, r7, lr}
 *   @0x120100 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x120104 mlaeq r12, r4, r8, sp
 *   @0x120108 eoreq r10, r1, r4, lsl #2
 *
 * ══ §46/212 F_TileGetWidth(RValue&, CInstance*, CInstance*, int, RValue*)  0x12010c  size 144  36 条（0x12010c..0x12019c）
 * @func 0x12010c 0x1201ac  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CRoom::FindTile(int) / F_TileGetWidth(RValue&, CInstance*, CInstance*, int, RValue*)+0x6c
 * 字段偏移 top8: 0x18×2 / 0x78×1 / 0xc×1 / 0xb8×1 / 0x14×1 / 0x4×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12010c push {r3, r4, r5, r6, r7, lr}
 *   @0x120110 mov r5, r0
 *   @0x120114 ldr r4, [pc, #0x78]
 *   @0x120118 mov r6, #0
 *   @0x12011c mov r1, r6
 *   @0x120120 ldr r0, [sp, #0x18]
 *   @0x120124 ldr r4, [pc, r4]
 *   @0x120128 str r6, [r5, #0xc]
 *   @0x12012c ldr r7, [r4]
 *   @0x120130 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x120134 mov r1, r0
 *   @0x120138 mov r0, r7
 *   @0x12013c bl 0x1af2bc <_ZN5CRoom8FindTileEi>
 *   @0x120140 cmp r0, #0
 *   @0x120144 blt 0x120178 <_Z14F_TileGetWidthR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x120148 ldr r3, [r4]
 *   @0x12014c ldr r2, [r3, #0xb8]
 *   @0x120150 cmp r0, r2
 *   @0x120154 rsblt r0, r0, r0, lsl #3
 *   @0x120158 ldrlt r3, [r3, #0xc0]
 *   @0x12015c addlt r6, r3, r0, lsl #3
 *   @0x120160 ldr r2, [r6, #0x14]
 *   @0x120164 vmov s15, r2
 *   @0x120168 vcvt.f64.s32 d7, s15
 *   @0x12016c vmov r2, r3, d7
 *   @0x120170 stm r5, {r2, r3}
 *   @0x120174 pop {r3, r4, r5, r6, r7, pc}
 *   @0x120178 ldr r0, [pc, #0x18]
 *   @0x12017c mov r1, r6
 *   @0x120180 str r6, [r5]
 *   @0x120184 str r6, [r5, #0x4]
 *   @0x120188 add r0, pc, r0
 *   @0x12018c pop {r3, r4, r5, r6, r7, lr}
 *   @0x120190 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x120194 eoreq sp, r12, r4, lsl #16
 *   @0x120198 eoreq r10, r1, r4, ror r0
 *
 * ══ §47/212 F_TileGetHeight(RValue&, CInstance*, CInstance*, int, RValue*)  0x12019c  size 144  36 条（0x12019c..0x12022c）
 * @func 0x12019c 0x12023c  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CRoom::FindTile(int) / F_TileGetHeight(RValue&, CInstance*, CInstance*, int, RValue*)+0x6c
 * 字段偏移 top8: 0x18×3 / 0x78×1 / 0xc×1 / 0xb8×1 / 0x4×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12019c push {r3, r4, r5, r6, r7, lr}
 *   @0x1201a0 mov r5, r0
 *   @0x1201a4 ldr r4, [pc, #0x78]
 *   @0x1201a8 mov r6, #0
 *   @0x1201ac mov r1, r6
 *   @0x1201b0 ldr r0, [sp, #0x18]
 *   @0x1201b4 ldr r4, [pc, r4]
 *   @0x1201b8 str r6, [r5, #0xc]
 *   @0x1201bc ldr r7, [r4]
 *   @0x1201c0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1201c4 mov r1, r0
 *   @0x1201c8 mov r0, r7
 *   @0x1201cc bl 0x1af2bc <_ZN5CRoom8FindTileEi>
 *   @0x1201d0 cmp r0, #0
 *   @0x1201d4 blt 0x120208 <_Z15F_TileGetHeightR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x1201d8 ldr r3, [r4]
 *   @0x1201dc ldr r2, [r3, #0xb8]
 *   @0x1201e0 cmp r0, r2
 *   @0x1201e4 rsblt r0, r0, r0, lsl #3
 *   @0x1201e8 ldrlt r3, [r3, #0xc0]
 *   @0x1201ec addlt r6, r3, r0, lsl #3
 *   @0x1201f0 ldr r2, [r6, #0x18]
 *   @0x1201f4 vmov s15, r2
 *   @0x1201f8 vcvt.f64.s32 d7, s15
 *   @0x1201fc vmov r2, r3, d7
 *   @0x120200 stm r5, {r2, r3}
 *   @0x120204 pop {r3, r4, r5, r6, r7, pc}
 *   @0x120208 ldr r0, [pc, #0x18]
 *   @0x12020c mov r1, r6
 *   @0x120210 str r6, [r5]
 *   @0x120214 str r6, [r5, #0x4]
 *   @0x120218 add r0, pc, r0
 *   @0x12021c pop {r3, r4, r5, r6, r7, lr}
 *   @0x120220 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x120224 eoreq sp, r12, r4, ror r7
 *   @0x120228 eoreq r9, r1, r4, ror #31
 *
 * ══ §48/212 F_TileGetVisible(RValue&, CInstance*, CInstance*, int, RValue*)  0x1202b8  size 144  36 条（0x1202b8..0x120348）
 * @func 0x1202b8 0x120358  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CRoom::FindTile(int) / F_TileGetVisible(RValue&, CInstance*, CInstance*, int, RValue*)+0x6c
 * 字段偏移 top8: 0x18×2 / 0x78×1 / 0xc×1 / 0xb8×1 / 0x34×1 / 0x4×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1202b8 push {r3, r4, r5, r6, r7, lr}
 *   @0x1202bc mov r5, r0
 *   @0x1202c0 ldr r4, [pc, #0x78]
 *   @0x1202c4 mov r6, #0
 *   @0x1202c8 mov r1, r6
 *   @0x1202cc ldr r0, [sp, #0x18]
 *   @0x1202d0 ldr r4, [pc, r4]
 *   @0x1202d4 str r6, [r5, #0xc]
 *   @0x1202d8 ldr r7, [r4]
 *   @0x1202dc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1202e0 mov r1, r0
 *   @0x1202e4 mov r0, r7
 *   @0x1202e8 bl 0x1af2bc <_ZN5CRoom8FindTileEi>
 *   @0x1202ec cmp r0, #0
 *   @0x1202f0 blt 0x120324 <_Z16F_TileGetVisibleR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x1202f4 ldr r3, [r4]
 *   @0x1202f8 ldr r2, [r3, #0xb8]
 *   @0x1202fc cmp r0, r2
 *   @0x120300 rsblt r0, r0, r0, lsl #3
 *   @0x120304 ldrlt r3, [r3, #0xc0]
 *   @0x120308 addlt r6, r3, r0, lsl #3
 *   @0x12030c ldrb r2, [r6, #0x34]
 *   @0x120310 vmov s15, r2
 *   @0x120314 vcvt.f64.u32 d7, s15
 *   @0x120318 vmov r2, r3, d7
 *   @0x12031c stm r5, {r2, r3}
 *   @0x120320 pop {r3, r4, r5, r6, r7, pc}
 *   @0x120324 ldr r0, [pc, #0x18]
 *   @0x120328 mov r1, r6
 *   @0x12032c str r6, [r5]
 *   @0x120330 str r6, [r5, #0x4]
 *   @0x120334 add r0, pc, r0
 *   @0x120338 pop {r3, r4, r5, r6, r7, lr}
 *   @0x12033c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x120340 eoreq sp, r12, r8, asr r6
 *   @0x120344 eoreq r9, r1, r8, asr #29
 *
 * ══ §49/212 F_TileGetBlend(RValue&, CInstance*, CInstance*, int, RValue*)  0x120460  size 144  36 条（0x120460..0x1204f0）
 * @func 0x120460 0x120500  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CRoom::FindTile(int) / F_TileGetBlend(RValue&, CInstance*, CInstance*, int, RValue*)+0x6c
 * 字段偏移 top8: 0x18×2 / 0x78×1 / 0xc×1 / 0xb8×1 / 0x2c×1 / 0x4×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x120460 push {r3, r4, r5, r6, r7, lr}
 *   @0x120464 mov r5, r0
 *   @0x120468 ldr r4, [pc, #0x78]
 *   @0x12046c mov r6, #0
 *   @0x120470 mov r1, r6
 *   @0x120474 ldr r0, [sp, #0x18]
 *   @0x120478 ldr r4, [pc, r4]
 *   @0x12047c str r6, [r5, #0xc]
 *   @0x120480 ldr r7, [r4]
 *   @0x120484 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x120488 mov r1, r0
 *   @0x12048c mov r0, r7
 *   @0x120490 bl 0x1af2bc <_ZN5CRoom8FindTileEi>
 *   @0x120494 cmp r0, #0
 *   @0x120498 blt 0x1204cc <_Z14F_TileGetBlendR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x12049c ldr r3, [r4]
 *   @0x1204a0 ldr r2, [r3, #0xb8]
 *   @0x1204a4 cmp r0, r2
 *   @0x1204a8 rsblt r0, r0, r0, lsl #3
 *   @0x1204ac ldrlt r3, [r3, #0xc0]
 *   @0x1204b0 addlt r6, r3, r0, lsl #3
 *   @0x1204b4 ldr r2, [r6, #0x2c]
 *   @0x1204b8 vmov s15, r2
 *   @0x1204bc vcvt.f64.s32 d7, s15
 *   @0x1204c0 vmov r2, r3, d7
 *   @0x1204c4 stm r5, {r2, r3}
 *   @0x1204c8 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1204cc ldr r0, [pc, #0x18]
 *   @0x1204d0 mov r1, r6
 *   @0x1204d4 str r6, [r5]
 *   @0x1204d8 str r6, [r5, #0x4]
 *   @0x1204dc add r0, pc, r0
 *   @0x1204e0 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1204e4 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1204e8 .word 0x002cd4b0
 *   @0x1204ec eoreq r9, r1, r0, lsr #26
 *
 * ══ §50/212 F_TileGetBackground(RValue&, CInstance*, CInstance*, int, RValue*)  0x12057c  size 144  36 条（0x12057c..0x12060c）
 * @func 0x12057c 0x12060c  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CRoom::FindTile(int) / F_TileGetBackground(RValue&, CInstance*, CInstance*, int, RValue*)+0x6c
 * 字段偏移 top8: 0x18×2 / 0x78×1 / 0xc×1 / 0xb8×1 / 0x8×1 / 0x4×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12057c push {r3, r4, r5, r6, r7, lr}
 *   @0x120580 mov r5, r0
 *   @0x120584 ldr r4, [pc, #0x78]
 *   @0x120588 mov r6, #0
 *   @0x12058c mov r1, r6
 *   @0x120590 ldr r0, [sp, #0x18]
 *   @0x120594 ldr r4, [pc, r4]
 *   @0x120598 str r6, [r5, #0xc]
 *   @0x12059c ldr r7, [r4]
 *   @0x1205a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1205a4 mov r1, r0
 *   @0x1205a8 mov r0, r7
 *   @0x1205ac bl 0x1af2bc <_ZN5CRoom8FindTileEi>
 *   @0x1205b0 cmp r0, #0
 *   @0x1205b4 blt 0x1205e8 <_Z19F_TileGetBackgroundR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x1205b8 ldr r3, [r4]
 *   @0x1205bc ldr r2, [r3, #0xb8]
 *   @0x1205c0 cmp r0, r2
 *   @0x1205c4 rsblt r0, r0, r0, lsl #3
 *   @0x1205c8 ldrlt r3, [r3, #0xc0]
 *   @0x1205cc addlt r6, r3, r0, lsl #3
 *   @0x1205d0 ldr r2, [r6, #0x8]
 *   @0x1205d4 vmov s15, r2
 *   @0x1205d8 vcvt.f64.s32 d7, s15
 *   @0x1205dc vmov r2, r3, d7
 *   @0x1205e0 stm r5, {r2, r3}
 *   @0x1205e4 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1205e8 ldr r0, [pc, #0x18]
 *   @0x1205ec mov r1, r6
 *   @0x1205f0 str r6, [r5]
 *   @0x1205f4 str r6, [r5, #0x4]
 *   @0x1205f8 add r0, pc, r0
 *   @0x1205fc pop {r3, r4, r5, r6, r7, lr}
 *   @0x120600 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x120604 mlaeq r12, r4, r3, sp
 *   @0x120608 eoreq r9, r1, r4, lsl #24
 *
 * ══ §51/212 GetTextFromArg(RValue const*, int, char**)  0x121ce0  size 144  36 条（0x121ce0..0x121d70）
 * @func 0x121ce0 0x121d70  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool) / STRING_RValue(char**, char**, int*, RValue const*) / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x10×2 / 0x70×1 / 0xc×1 / 0x-4×1 / 0x14×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x121ce0 push {r4, r5, lr}
 *   @0x121ce4 mov r12, r1
 *   @0x121ce8 mov r4, r0
 *   @0x121cec mov r0, r1
 *   @0x121cf0 ldr r1, [pc, #0x70]
 *   @0x121cf4 sub sp, sp, #28
 *   @0x121cf8 mov r5, r2
 *   @0x121cfc mov r3, #1
 *   @0x121d00 add r1, pc, r1
 *   @0x121d04 movw r2, #0x947
 *   @0x121d08 str r12, [sp, #0xc]
 *   @0x121d0c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x121d10 mov r3, r4
 *   @0x121d14 add r2, sp, #12
 *   @0x121d18 mov r4, #0
 *   @0x121d1c mov r1, r0
 *   @0x121d20 add r0, sp, #24
 *   @0x121d24 str r1, [sp, #0x10]
 *   @0x121d28 str r1, [r0, #-0x4]!
 *   @0x121d2c strb r4, [r1]
 *   @0x121d30 add r1, sp, #16
 *   @0x121d34 bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue>
 *   @0x121d38 ldr r0, [sp, #0x10]
 *   @0x121d3c ldr r1, [sp, #0x14]
 *   @0x121d40 mov r3, #74
 *   @0x121d44 ldr r2, [pc, #0x20]
 *   @0x121d48 rsb r1, r0, r1
 *   @0x121d4c str r4, [sp]
 *   @0x121d50 add r1, r1, #1
 *   @0x121d54 add r2, pc, r2
 *   @0x121d58 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x121d5c str r0, [r5]
 *   @0x121d60 add sp, sp, #28
 *   @0x121d64 pop {r4, r5, pc}
 *   @0x121d68 eoreq r8, r1, r0, asr r2
 *   @0x121d6c .word 0x0020f2dc
 *
 * ══ §52/212 F_GetOpenFileName(RValue&, CInstance*, CInstance*, int, RValue*)  0x126b78  size 144  36 条（0x126b78..0x126c08）
 * @func 0x126b78 0x126c08  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)×2 / YYGetOpenFileName(char*, char*, char*, char*) / operator new(unsigned int) / 0xb6640 / YYCreateString(RValue*, char const*)
 * 字段偏移 top8: 0x10×1 / 0x2c×1 / 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x126b78 push {r4, r5, r6, lr}
 *   @0x126b7c mov r1, #0
 *   @0x126b80 ldr r4, [sp, #0x10]
 *   @0x126b84 mov r6, r0
 *   @0x126b88 mov r0, r4
 *   @0x126b8c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x126b90 mov r1, #1
 *   @0x126b94 mov r5, r0
 *   @0x126b98 mov r0, r4
 *   @0x126b9c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x126ba0 mov r2, #0
 *   @0x126ba4 mov r3, r2
 *   @0x126ba8 mov r1, r0
 *   @0x126bac mov r0, r5
 *   @0x126bb0 bl 0x160ec0 <_Z17YYGetOpenFileNamePcS_S_S_>
 *   @0x126bb4 subs r5, r0, #0
 *   @0x126bb8 beq 0x126bf0 <_Z17F_GetOpenFileNameR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x126bbc mov r0, #12
 *   @0x126bc0 bl 0x27c524 <_Znwj>
 *   @0x126bc4 mov r4, r0
 *   @0x126bc8 mov r0, r5
 *   @0x126bcc bl 0xb6640 <strdup@plt>
 *   @0x126bd0 ldr r3, [pc, #0x2c]
 *   @0x126bd4 mov r2, #0
 *   @0x126bd8 strb r2, [r4, #0x8]
 *   @0x126bdc ldr r3, [pc, r3]
 *   @0x126be0 ldr r2, [r3]
 *   @0x126be4 str r2, [r4]
 *   @0x126be8 str r4, [r3]
 *   @0x126bec str r0, [r4, #0x4]
 *   @0x126bf0 mov r0, r6
 *   @0x126bf4 mov r1, r5
 *   @0x126bf8 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x126bfc pop {r4, r5, r6, lr}
 *   @0x126c00 b 0x18c2c8 <_Z8IO_Clearv>
 *   @0x126c04 eoreq r7, r12, r12, lsr #29
 *
 * ══ §53/212 F_GetSaveFileName(RValue&, CInstance*, CInstance*, int, RValue*)  0x126cb8  size 144  36 条（0x126cb8..0x126d48）
 * @func 0x126cb8 0x126d48  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)×2 / YYGetSaveFileName(char*, char*, char*, char*) / operator new(unsigned int) / 0xb6640 / YYCreateString(RValue*, char const*)
 * 字段偏移 top8: 0x10×1 / 0x2c×1 / 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x126cb8 push {r4, r5, r6, lr}
 *   @0x126cbc mov r1, #0
 *   @0x126cc0 ldr r4, [sp, #0x10]
 *   @0x126cc4 mov r6, r0
 *   @0x126cc8 mov r0, r4
 *   @0x126ccc bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x126cd0 mov r1, #1
 *   @0x126cd4 mov r5, r0
 *   @0x126cd8 mov r0, r4
 *   @0x126cdc bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x126ce0 mov r2, #0
 *   @0x126ce4 mov r3, r2
 *   @0x126ce8 mov r1, r0
 *   @0x126cec mov r0, r5
 *   @0x126cf0 bl 0x160ec8 <_Z17YYGetSaveFileNamePcS_S_S_>
 *   @0x126cf4 subs r5, r0, #0
 *   @0x126cf8 beq 0x126d30 <_Z17F_GetSaveFileNameR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x126cfc mov r0, #12
 *   @0x126d00 bl 0x27c524 <_Znwj>
 *   @0x126d04 mov r4, r0
 *   @0x126d08 mov r0, r5
 *   @0x126d0c bl 0xb6640 <strdup@plt>
 *   @0x126d10 ldr r3, [pc, #0x2c]
 *   @0x126d14 mov r2, #0
 *   @0x126d18 strb r2, [r4, #0x8]
 *   @0x126d1c ldr r3, [pc, r3]
 *   @0x126d20 ldr r2, [r3]
 *   @0x126d24 str r2, [r4]
 *   @0x126d28 str r4, [r3]
 *   @0x126d2c str r0, [r4, #0x4]
 *   @0x126d30 mov r0, r6
 *   @0x126d34 mov r1, r5
 *   @0x126d38 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x126d3c pop {r4, r5, r6, lr}
 *   @0x126d40 b 0x18c2c8 <_Z8IO_Clearv>
 *   @0x126d44 .word 0x002c6cb0
 *
 * ══ §54/212 F_SpriteGetSpeed(RValue&, CInstance*, CInstance*, int, RValue*)  0x12b2f8  size 144  36 条（0x12b2f8..0x12b388）
 * @func 0x12b2f8 0x12b388  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / Sprite_Data(int)
 * 字段偏移 top8: 0xc×2 / 0x18×1 / 0x4×1 / 0x20×1 / 0x1c×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12b2f8 push {r3, r4, r5, r6, r7, lr}
 *   @0x12b2fc mov r5, #0
 *   @0x12b300 ldr r6, [sp, #0x18]
 *   @0x12b304 mov r1, r5
 *   @0x12b308 str r5, [r0, #0xc]
 *   @0x12b30c mov r4, r0
 *   @0x12b310 str r5, [r0]
 *   @0x12b314 mov r3, r5
 *   @0x12b318 movt r3, #0xbff0
 *   @0x12b31c str r3, [r0, #0x4]
 *   @0x12b320 mov r0, r6
 *   @0x12b324 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12b328 mov r1, r5
 *   @0x12b32c mov r7, r0
 *   @0x12b330 mov r0, r6
 *   @0x12b334 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12b338 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x12b33c cmp r0, #0
 *   @0x12b340 beq 0x12b358 <_Z16F_SpriteGetSpeedR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0x12b344 vldr s15, [r0, #108]
 *   @0x12b348 vcvt.f64.f32 d6, s15
 *   @0x12b34c vmov r2, r3, d6
 *   @0x12b350 stm r4, {r2, r3}
 *   @0x12b354 pop {r3, r4, r5, r6, r7, pc}
 *   @0x12b358 ldr r3, [pc, #0x20]
 *   @0x12b35c mov r2, r7
 *   @0x12b360 ldr r1, [pc, #0x1c]
 *   @0x12b364 ldr r3, [pc, r3]
 *   @0x12b368 add r1, pc, r1
 *   @0x12b36c ldr r0, [r3]
 *   @0x12b370 ldr r3, [r0]
 *   @0x12b374 ldr r3, [r3, #0xc]
 *   @0x12b378 blx r3
 *   @0x12b37c pop {r3, r4, r5, r6, r7, pc}
 *   @0x12b380 .word 0x002c23b0
 *   @0x12b384 eoreq r2, r1, r8, lsr r1
 *
 * ══ §55/212 F_RoomInstanceAdd(RValue&, CInstance*, CInstance*, int, RValue*)  0x12e844  size 144  36 条（0x12e844..0x12e8d4）
 * @func 0x12e844 0x12e8d4  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / YYGetFloat(RValue const*, int)×2 / Room_Data(int) / CRoom::AddInstanceToStorage(float, float, int)
 * 字段偏移 top8: 0x18×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12e844 push {r4, r5, r6, r7, r8, lr}
 *   @0x12e848 mov r1, #0
 *   @0x12e84c ldr r4, [sp, #0x18]
 *   @0x12e850 mov r5, r0
 *   @0x12e854 mov r0, r4
 *   @0x12e858 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e85c bl 0x1b52c4 <_Z9Room_Datai>
 *   @0x12e860 subs r6, r0, #0
 *   @0x12e864 beq 0x12e8c4 <_Z17F_RoomInstanceAddR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x12e868 mov r1, #1
 *   @0x12e86c mov r0, r4
 *   @0x12e870 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x12e874 mov r1, #2
 *   @0x12e878 mov r8, r0
 *   @0x12e87c mov r0, r4
 *   @0x12e880 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x12e884 mov r1, #3
 *   @0x12e888 mov r7, r0
 *   @0x12e88c mov r0, r4
 *   @0x12e890 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e894 mov r2, r7
 *   @0x12e898 mov r1, r8
 *   @0x12e89c mov r3, r0
 *   @0x12e8a0 mov r0, r6
 *   @0x12e8a4 bl 0x1aadac <_ZN5CRoom20AddInstanceToStorageEffi>
 *   @0x12e8a8 vmov s15, r0
 *   @0x12e8ac vcvt.f64.s32 d7, s15
 *   @0x12e8b0 vmov r2, r3, d7
 *   @0x12e8b4 mov r1, #0
 *   @0x12e8b8 stm r5, {r2, r3}
 *   @0x12e8bc str r1, [r5, #0xc]
 *   @0x12e8c0 pop {r4, r5, r6, r7, r8, pc}
 *   @0x12e8c4 mov r3, #0
 *   @0x12e8c8 mov r2, #0
 *   @0x12e8cc movt r3, #0xbff0
 *   @0x12e8d0 b 0x12e8b4 <_Z17F_RoomInstanceAddR6RValueP9CInstanceS2_iPS_+0x70>
 *
 * ══ §56/212 F_Audio_QueueSound(RValue&, CInstance*, CInstance*, int, RValue*)  0x135c64  size 144  36 条（0x135c64..0x135cf4）
 * @func 0x135c64 0x135cf4  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×4 / Audio_QueueBufferSound(int, int, int, int)
 * 字段偏移 top8: 0x84×1 / 0x18×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x135c64 ldr r3, [pc, #0x84]
 *   @0x135c68 push {r4, r5, r6, r7, r8, lr}
 *   @0x135c6c ldr r3, [pc, r3]
 *   @0x135c70 mov r5, r0
 *   @0x135c74 ldr r4, [sp, #0x18]
 *   @0x135c78 ldrb r1, [r3]
 *   @0x135c7c cmp r1, #0
 *   @0x135c80 popne {r4, r5, r6, r7, r8, pc}
 *   @0x135c84 str r1, [r0, #0xc]
 *   @0x135c88 mov r0, r4
 *   @0x135c8c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x135c90 mov r1, #1
 *   @0x135c94 mov r8, r0
 *   @0x135c98 mov r0, r4
 *   @0x135c9c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x135ca0 mov r1, #2
 *   @0x135ca4 mov r7, r0
 *   @0x135ca8 mov r0, r4
 *   @0x135cac bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x135cb0 mov r1, #3
 *   @0x135cb4 mov r6, r0
 *   @0x135cb8 mov r0, r4
 *   @0x135cbc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x135cc0 mov r1, r7
 *   @0x135cc4 mov r2, r6
 *   @0x135cc8 mov r3, r0
 *   @0x135ccc mov r0, r8
 *   @0x135cd0 bl 0x21d0e0 <_Z22Audio_QueueBufferSoundiiii>
 *   @0x135cd4 vmov s15, r0
 *   @0x135cd8 vcvt.f64.s32 d7, s15
 *   @0x135cdc vmov r0, r1, d7
 *   @0x135ce0 vmov r2, s14
 *   @0x135ce4 mov r3, r1
 *   @0x135ce8 stm r5, {r2, r3}
 *   @0x135cec pop {r4, r5, r6, r7, r8, pc}
 *   @0x135cf0 eoreq r9, r11, r0, ror #7
 *
 * ══ §57/212 F_DirectoryCreate(RValue&, CInstance*, CInstance*, int, RValue*)  0x137a3c  size 144  36 条（0x137a3c..0x137acc）
 * @func 0x137a3c 0x137acc  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int) / LoadSave::_GetSaveFileName(char*, int, char const*) / ForceDirectories(char const*) / 0xb65d4
 * 字段偏移 top8: 0x404×2 / 0x7c×1 / 0x420×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x137a3c push {r4, r5, r6, r7, lr}
 *   @0x137a40 sub sp, sp, #1024
 *   @0x137a44 ldr r5, [pc, #0x7c]
 *   @0x137a48 sub sp, sp, #12
 *   @0x137a4c mov r4, r0
 *   @0x137a50 mov r1, #0
 *   @0x137a54 ldr r5, [pc, r5]
 *   @0x137a58 ldr r0, [sp, #0x420]
 *   @0x137a5c mov r6, r1
 *   @0x137a60 add r7, sp, #4
 *   @0x137a64 ldr r3, [r5]
 *   @0x137a68 str r3, [sp, #0x404]
 *   @0x137a6c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x137a70 mov r1, #1024
 *   @0x137a74 str r6, [r4, #0xc]
 *   @0x137a78 str r6, [r4]
 *   @0x137a7c str r6, [r4, #0x4]
 *   @0x137a80 mov r2, r0
 *   @0x137a84 mov r0, r7
 *   @0x137a88 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0x137a8c mov r0, r7
 *   @0x137a90 bl 0x2150b4 <_Z16ForceDirectoriesPKc>
 *   @0x137a94 ldr r2, [sp, #0x404]
 *   @0x137a98 cmp r0, r6
 *   @0x137a9c strne r6, [r4]
 *   @0x137aa0 movne r3, r6
 *   @0x137aa4 movtne r3, #0x3ff0
 *   @0x137aa8 strne r3, [r4, #0x4]
 *   @0x137aac ldr r3, [r5]
 *   @0x137ab0 cmp r2, r3
 *   @0x137ab4 bne 0x137ac4 <_Z17F_DirectoryCreateR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x137ab8 add sp, sp, #1024
 *   @0x137abc add sp, sp, #12
 *   @0x137ac0 pop {r4, r5, r6, r7, pc}
 *   @0x137ac4 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x137ac8 .word 0x002b5efc
 *
 * ══ §58/212 F_FileBinPosition(RValue&, CInstance*, CInstance*, int, RValue*)  0x1395f8  size 144  36 条（0x1395f8..0x139688）
 * @func 0x1395f8 0x139688  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / LoadSave::ftell(_YYFILE*)
 * 字段偏移 top8: 0x8×2 / 0x5c×1 / 0x4c×1 / 0xc×1 / 0x14×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1395f8 push {r4, lr}
 *   @0x1395fc mov r1, #0
 *   @0x139600 mov r4, r0
 *   @0x139604 ldr r0, [sp, #0x8]
 *   @0x139608 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13960c sub r3, r0, #1
 *   @0x139610 cmp r3, #30
 *   @0x139614 bhi 0x139668 <_Z17F_FileBinPositionR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x139618 ldr r3, [pc, #0x5c]
 *   @0x13961c ldr r3, [pc, r3]
 *   @0x139620 ldrb r3, [r3, r0]
 *   @0x139624 cmp r3, #0
 *   @0x139628 beq 0x139668 <_Z17F_FileBinPositionR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x13962c ldr r3, [pc, #0x4c]
 *   @0x139630 add r0, r0, r0, lsl #1
 *   @0x139634 mov r2, #0
 *   @0x139638 str r2, [r4, #0xc]
 *   @0x13963c ldr r3, [pc, r3]
 *   @0x139640 add r3, r3, r0, lsl #2
 *   @0x139644 ldr r0, [r3, #0x8]
 *   @0x139648 bl 0x18de24 <_ZN8LoadSave5ftellEP7_YYFILE>
 *   @0x13964c vmov s15, r0
 *   @0x139650 vcvt.f64.s32 d7, s15
 *   @0x139654 vmov r0, r1, d7
 *   @0x139658 vmov r2, s14
 *   @0x13965c mov r3, r1
 *   @0x139660 stm r4, {r2, r3}
 *   @0x139664 pop {r4, pc}
 *   @0x139668 ldr r0, [pc, #0x14]
 *   @0x13966c mov r1, #0
 *   @0x139670 pop {r4, lr}
 *   @0x139674 add r0, pc, r0
 *   @0x139678 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x13967c eoreq r5, r11, r0, ror r12
 *   @0x139680 eoreq r5, r11, r4, asr r12
 *   @0x139684 eoreq r6, r0, r12, lsl #22
 *
 * ══ §59/212 F_MouseXToGUI(RValue&, CInstance*, CInstance*, int, RValue*)  0x158704  size 144  36 条（0x158704..0x158794）
 * @func 0x158704 0x1587a4  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / 0xb6598
 * 字段偏移 top8: 0x50×2 / 0x2×2 / 0x8×1 / 0x5c×1 / 0xc×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x158704 push {r4, lr}
 *   @0x158708 mov r1, #0
 *   @0x15870c mov r4, r0
 *   @0x158710 ldr r0, [sp, #0x8]
 *   @0x158714 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x158718 cmp r0, #9
 *   @0x15871c mov r2, r0
 *   @0x158720 pophi {r4, pc}
 *   @0x158724 ldr r0, [pc, #0x5c]
 *   @0x158728 mov r3, #0
 *   @0x15872c str r3, [r4, #0xc]
 *   @0x158730 ldr r0, [pc, r0]
 *   @0x158734 ldr r1, [pc, #0x50]
 *   @0x158738 ldr r3, [pc, #0x50]
 *   @0x15873c ldr r0, [r0, r2, lsl #2]
 *   @0x158740 ldr r1, [pc, r1]
 *   @0x158744 ldr r3, [pc, r3]
 *   @0x158748 vldr s11, [r3, #16]
 *   @0x15874c ldr r1, [r1, r2, lsl #2]
 *   @0x158750 vldr s13, [r3]
 *   @0x158754 vmov s15, r0
 *   @0x158758 vldr s14, [r3, #48]
 *   @0x15875c vcvt.f32.s32 s15, s15
 *   @0x158760 vmov s12, r1
 *   @0x158764 vmul.f32 s15, s15, s11
 *   @0x158768 vcvt.f32.s32 s12, s12
 *   @0x15876c vmla.f32 s15, s12, s13
 *   @0x158770 vadd.f32 s15, s15, s14
 *   @0x158774 vcvt.f64.f32 d6, s15
 *   @0x158778 vmov r0, r1, d6
 *   @0x15877c bl 0xb6598 <floor@plt>
 *   @0x158780 stm r4, {r0, r1}
 *   @0x158784 pop {r4, pc}
 *   @0x158788 eoreq r7, r9, r8, ror #8
 *   @0x15878c eoreq r7, r9, r12, asr r4
 *   @0x158790 eoreq r7, r9, r12, asr r4
 *
 * ══ §60/212 F_MouseYToGUI(RValue&, CInstance*, CInstance*, int, RValue*)  0x158794  size 144  36 条（0x158794..0x158824）
 * @func 0x158794 0x158824  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / 0xb6598
 * 字段偏移 top8: 0x50×2 / 0x2×2 / 0x8×1 / 0x5c×1 / 0xc×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x158794 push {r4, lr}
 *   @0x158798 mov r1, #0
 *   @0x15879c mov r4, r0
 *   @0x1587a0 ldr r0, [sp, #0x8]
 *   @0x1587a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1587a8 cmp r0, #9
 *   @0x1587ac mov r2, r0
 *   @0x1587b0 pophi {r4, pc}
 *   @0x1587b4 ldr r0, [pc, #0x5c]
 *   @0x1587b8 mov r3, #0
 *   @0x1587bc str r3, [r4, #0xc]
 *   @0x1587c0 ldr r0, [pc, r0]
 *   @0x1587c4 ldr r1, [pc, #0x50]
 *   @0x1587c8 ldr r3, [pc, #0x50]
 *   @0x1587cc ldr r0, [r0, r2, lsl #2]
 *   @0x1587d0 ldr r1, [pc, r1]
 *   @0x1587d4 ldr r3, [pc, r3]
 *   @0x1587d8 vldr s11, [r3, #20]
 *   @0x1587dc ldr r1, [r1, r2, lsl #2]
 *   @0x1587e0 vldr s13, [r3, #4]
 *   @0x1587e4 vmov s15, r0
 *   @0x1587e8 vldr s14, [r3, #52]
 *   @0x1587ec vcvt.f32.s32 s15, s15
 *   @0x1587f0 vmov s12, r1
 *   @0x1587f4 vmul.f32 s15, s15, s11
 *   @0x1587f8 vcvt.f32.s32 s12, s12
 *   @0x1587fc vmla.f32 s15, s12, s13
 *   @0x158800 vadd.f32 s15, s15, s14
 *   @0x158804 vcvt.f64.f32 d6, s15
 *   @0x158808 vmov r0, r1, d6
 *   @0x15880c bl 0xb6598 <floor@plt>
 *   @0x158810 stm r4, {r0, r1}
 *   @0x158814 pop {r4, pc}
 *   @0x158818 .word 0x002973d8
 *   @0x15881c eoreq r7, r9, r12, asr #7
 *   @0x158820 eoreq r7, r9, r12, asr #7
 *
 * ══ §61/212 AddAchievementCacheBlock(eCacheType, char const*, unsigned int*)  0x159a9c  size 144  36 条（0x159a9c..0x159b2c）
 * @func 0x159a9c 0x159b2c  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6538 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb65bc / LinkCacheAchievementToEnd(SAchivementCache*)
 * 字段偏移 top8: 0x80×1 / 0x58×1 / 0x14×1 / 0xc×1 / 0x8×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x159a9c ldr r3, [pc, #0x80]
 *   @0x159aa0 push {r4, r5, r6, r7, r8, lr}
 *   @0x159aa4 ldr r3, [pc, r3]
 *   @0x159aa8 mov r6, r0
 *   @0x159aac mov r5, r1
 *   @0x159ab0 ldr r3, [r3]
 *   @0x159ab4 mov r7, r2
 *   @0x159ab8 cmp r3, #2048
 *   @0x159abc popgt {r4, r5, r6, r7, r8, pc}
 *   @0x159ac0 mov r0, r1
 *   @0x159ac4 bl 0xb6538 <strlen@plt>
 *   @0x159ac8 ldr r1, [pc, #0x58]
 *   @0x159acc movw r2, #0x1ea
 *   @0x159ad0 mov r3, #1
 *   @0x159ad4 add r1, pc, r1
 *   @0x159ad8 mov r8, r0
 *   @0x159adc add r0, r0, #21
 *   @0x159ae0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x159ae4 add r2, r8, #1
 *   @0x159ae8 mov r1, r5
 *   @0x159aec mov r4, r0
 *   @0x159af0 mov r3, r0
 *   @0x159af4 mov r0, #0
 *   @0x159af8 str r0, [r3], #20
 *   @0x159afc str r3, [r4, #0xc]
 *   @0x159b00 mov r0, r3
 *   @0x159b04 bl 0xb65bc <memcpy@plt>
 *   @0x159b08 ldr r3, [r7]
 *   @0x159b0c mov r0, r4
 *   @0x159b10 str r6, [r4, #0x8]
 *   @0x159b14 str r3, [r4, #0x10]
 *   @0x159b18 bl 0x159824 <_Z25LinkCacheAchievementToEndP16SAchivementCache>
 *   @0x159b1c pop {r4, r5, r6, r7, r8, lr}
 *   @0x159b20 b 0x159640 <_Z21FlushAchievementCachev>
 *   @0x159b24 eoreq r6, r9, r8, lsr #2
 *   @0x159b28 mulseq lr, r0, r10
 *
 * ══ §62/212 GR_3DM_Vertex_N(int, float, float, float, float, float, float)  0x165674  size 144  36 条（0x165674..0x165704）
 * @func 0x165674 0x165704  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_3DM_Vertex_N(int, float, float, float, float, float, float)+0x80 / C3D_Model::AddEntry(int, float, float, float, float, float, float, float, float, float, float)
 * 字段偏移 top8: 0x6c×1 / 0x5c×1 / 0x4×1 / 0x2×1 / 0x10×1 / 0x14×1 / 0x18×1 / 0x1c×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x165674 cmp r0, #0
 *   @0x165678 push {r4, lr}
 *   @0x16567c mov r4, r2
 *   @0x165680 sub sp, sp, #32
 *   @0x165684 blt 0x1656f4 <_Z15GR_3DM_Vertex_Niffffff+0x80>
 *   @0x165688 ldr r12, [pc, #0x6c]
 *   @0x16568c ldr r12, [pc, r12]
 *   @0x165690 ldr r12, [r12]
 *   @0x165694 cmp r0, r12
 *   @0x165698 bge 0x1656f4 <_Z15GR_3DM_Vertex_Niffffff+0x80>
 *   @0x16569c ldr r12, [pc, #0x5c]
 *   @0x1656a0 ldr r12, [pc, r12]
 *   @0x1656a4 ldr r2, [r12, #0x4]
 *   @0x1656a8 ldr r0, [r2, r0, lsl #2]
 *   @0x1656ac cmp r0, #0
 *   @0x1656b0 beq 0x1656f4 <_Z15GR_3DM_Vertex_Niffffff+0x80>
 *   @0x1656b4 mov r12, #0
 *   @0x1656b8 vldr s15, [sp, #40]
 *   @0x1656bc str r3, [sp]
 *   @0x1656c0 vstr s15, [sp, #4]
 *   @0x1656c4 mov r2, r1
 *   @0x1656c8 vldr s15, [sp, #44]
 *   @0x1656cc mov r3, r4
 *   @0x1656d0 vstr s15, [sp, #8]
 *   @0x1656d4 mov r1, #6
 *   @0x1656d8 vldr s15, [sp, #48]
 *   @0x1656dc str r12, [sp, #0x10]
 *   @0x1656e0 vstr s15, [sp, #12]
 *   @0x1656e4 str r12, [sp, #0x14]
 *   @0x1656e8 str r12, [sp, #0x18]
 *   @0x1656ec str r12, [sp, #0x1c]
 *   @0x1656f0 bl 0x1648d4 <_ZN9C3D_Model8AddEntryEiffffffffff>
 *   @0x1656f4 add sp, sp, #32
 *   @0x1656f8 pop {r4, pc}
 *   @0x1656fc eoreq r10, r8, r4, ror #20
 *   @0x165700 eoreq r10, r8, r4, asr r10
 *
 * ══ §63/212 GR_Draw_Vertex_Color(float, float, unsigned int, float)  0x16bae0  size 144  36 条（0x16bae0..0x16bb70）
 * @func 0x16bae0 0x16bb70  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ConvertAlpha(float) / GR_Color_To_D3DColor(unsigned int, unsigned int)
 * 字段偏移 top8: 0x50×2 / 0x74×1 / 0x8×1 / 0x4×1 / 0x10×1 / 0x14×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16bae0 push {r4, r5, r6, r7, r8, lr}
 *   @0x16bae4 mov r7, r0
 *   @0x16bae8 ldr r4, [pc, #0x74]
 *   @0x16baec mov r6, r1
 *   @0x16baf0 mov r8, r2
 *   @0x16baf4 ldr r4, [pc, r4]
 *   @0x16baf8 ldr r12, [r4]
 *   @0x16bafc cmp r12, #1000
 *   @0x16bb00 popgt {r4, r5, r6, r7, r8, pc}
 *   @0x16bb04 mov r0, r3
 *   @0x16bb08 bl 0x16ca2c <_Z12ConvertAlphaf>
 *   @0x16bb0c ldr r5, [r4]
 *   @0x16bb10 ldr r2, [pc, #0x50]
 *   @0x16bb14 ldr r3, [pc, #0x50]
 *   @0x16bb18 ldr r2, [pc, r2]
 *   @0x16bb1c add r5, r5, r5, lsl #1
 *   @0x16bb20 ldr r3, [pc, r3]
 *   @0x16bb24 ldr r2, [r2]
 *   @0x16bb28 add r5, r3, r5, lsl #3
 *   @0x16bb2c str r7, [r5]
 *   @0x16bb30 str r2, [r5, #0x8]
 *   @0x16bb34 str r6, [r5, #0x4]
 *   @0x16bb38 mov r1, r0
 *   @0x16bb3c mov r0, r8
 *   @0x16bb40 bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj>
 *   @0x16bb44 ldr r2, [r4]
 *   @0x16bb48 mov r3, #0
 *   @0x16bb4c str r3, [r5, #0x10]
 *   @0x16bb50 str r3, [r5, #0x14]
 *   @0x16bb54 add r3, r2, #1
 *   @0x16bb58 str r3, [r4]
 *   @0x16bb5c str r0, [r5, #0xc]
 *   @0x16bb60 pop {r4, r5, r6, r7, r8, pc}
 *   @0x16bb64 mlaeq r8, r0, r6, r4
 *   @0x16bb68 eoreq r1, r8, r8, lsl #28
 *   @0x16bb6c eoreq r4, r8, r12, ror r6
 *
 * ══ §64/212 F_CameraSetViewSpeed(RValue&, CInstance*, CInstance*, int, RValue*)  0x16fbe4  size 144  36 条（0x16fbe4..0x16fc74）
 * @func 0x16fbe4 0x16fc84  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / YYGetInt32(RValue const*, int) / CCameraManager::GetCamera(int) / CCamera::SetViewSpeedX(float)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x5c×1 / 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16fbe4 cmp r3, #3
 *   @0x16fbe8 push {r3, r4, r5, lr}
 *   @0x16fbec mov r3, #0
 *   @0x16fbf0 mov r1, r3
 *   @0x16fbf4 ldr r4, [sp, #0x10]
 *   @0x16fbf8 movt r3, #0xbff0
 *   @0x16fbfc str r1, [r0, #0xc]
 *   @0x16fc00 stm r0, {r1, r3}
 *   @0x16fc04 beq 0x16fc18 <_Z20F_CameraSetViewSpeedR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x16fc08 ldr r0, [pc, #0x5c]
 *   @0x16fc0c pop {r3, r4, r5, lr}
 *   @0x16fc10 add r0, pc, r0
 *   @0x16fc14 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x16fc18 mov r0, r4
 *   @0x16fc1c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x16fc20 ldr r3, [pc, #0x48]
 *   @0x16fc24 mov r1, r0
 *   @0x16fc28 ldr r0, [pc, r3]
 *   @0x16fc2c bl 0x16f45c <_ZN14CCameraManager9GetCameraEi>
 *   @0x16fc30 subs r5, r0, #0
 *   @0x16fc34 popeq {r3, r4, r5, pc}
 *   @0x16fc38 mov r0, r4
 *   @0x16fc3c mov r1, #1
 *   @0x16fc40 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x16fc44 mov r1, r0
 *   @0x16fc48 mov r0, r5
 *   @0x16fc4c bl 0x16d2dc <_ZN7CCamera13SetViewSpeedXEf>
 *   @0x16fc50 mov r0, r4
 *   @0x16fc54 mov r1, #2
 *   @0x16fc58 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x16fc5c mov r1, r0
 *   @0x16fc60 mov r0, r5
 *   @0x16fc64 pop {r3, r4, r5, lr}
 *   @0x16fc68 b 0x16d2ec <_ZN7CCamera13SetViewSpeedYEf>
 *   @0x16fc6c andseq r11, sp, r0, lsr #7
 *   @0x16fc70 eoreq lr, r7, r12, asr #32
 *
 * ══ §65/212 F_CameraSetViewBorder(RValue&, CInstance*, CInstance*, int, RValue*)  0x16fc74  size 144  36 条（0x16fc74..0x16fd04）
 * @func 0x16fc74 0x16fd04  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / YYGetInt32(RValue const*, int) / CCameraManager::GetCamera(int) / CCamera::SetViewBorderX(float)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x5c×1 / 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16fc74 cmp r3, #3
 *   @0x16fc78 push {r3, r4, r5, lr}
 *   @0x16fc7c mov r3, #0
 *   @0x16fc80 mov r1, r3
 *   @0x16fc84 ldr r4, [sp, #0x10]
 *   @0x16fc88 movt r3, #0xbff0
 *   @0x16fc8c str r1, [r0, #0xc]
 *   @0x16fc90 stm r0, {r1, r3}
 *   @0x16fc94 beq 0x16fca8 <_Z21F_CameraSetViewBorderR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x16fc98 ldr r0, [pc, #0x5c]
 *   @0x16fc9c pop {r3, r4, r5, lr}
 *   @0x16fca0 add r0, pc, r0
 *   @0x16fca4 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x16fca8 mov r0, r4
 *   @0x16fcac bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x16fcb0 ldr r3, [pc, #0x48]
 *   @0x16fcb4 mov r1, r0
 *   @0x16fcb8 ldr r0, [pc, r3]
 *   @0x16fcbc bl 0x16f45c <_ZN14CCameraManager9GetCameraEi>
 *   @0x16fcc0 subs r5, r0, #0
 *   @0x16fcc4 popeq {r3, r4, r5, pc}
 *   @0x16fcc8 mov r0, r4
 *   @0x16fccc mov r1, #1
 *   @0x16fcd0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x16fcd4 mov r1, r0
 *   @0x16fcd8 mov r0, r5
 *   @0x16fcdc bl 0x16d2fc <_ZN7CCamera14SetViewBorderXEf>
 *   @0x16fce0 mov r0, r4
 *   @0x16fce4 mov r1, #2
 *   @0x16fce8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x16fcec mov r1, r0
 *   @0x16fcf0 mov r0, r5
 *   @0x16fcf4 pop {r3, r4, r5, lr}
 *   @0x16fcf8 b 0x16d30c <_ZN7CCamera14SetViewBorderYEf>
 *   @0x16fcfc andseq r11, sp, r4, asr #6
 *   @0x16fd00 .word 0x0027dfbc
 *
 * ══ §66/212 Shader_Commit()  0x18805c  size 144  36 条（0x18805c..0x1880ec）
 * @func 0x18805c 0x1880ec  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x188064→0x532fbc, 0x18807c→0x3f2930, 0x188094→0x3f2934, 0x18809c→0x479b30, 0x1880c4→0x3f2934
 * 调用序列: Shader_Get(int)
 * 字段偏移 top8: 0x70×2 / 0x5c×1 / 0x48×1 / 0x44×1 / 0x8×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18805c push {r4, r5, r6, lr}
 *   @0x188060 ldr r4, [pc, #0x70]
 *   @0x188064 ldr r3, [pc, #0x70]
 *   @0x188068 add r4, pc, r4
 *   @0x18806c ldr r5, [r4, r3]
 *   @0x188070 ldrb r3, [r5]
 *   @0x188074 cmp r3, #0
 *   @0x188078 popeq {r4, r5, r6, pc}
 *   @0x18807c ldr r3, [pc, #0x5c]
 *   @0x188080 ldr r6, [r4, r3]
 *   @0x188084 ldr r0, [r6]
 *   @0x188088 bl 0x187e70 <_Z10Shader_Geti>
 *   @0x18808c cmp r0, #0
 *   @0x188090 beq 0x1880c4 <_Z13Shader_Commitv+0x68>
 *   @0x188094 ldr r2, [pc, #0x48]
 *   @0x188098 ldr r1, [r6]
 *   @0x18809c ldr r3, [pc, #0x44]
 *   @0x1880a0 ldr r2, [r4, r2]
 *   @0x1880a4 ldr r0, [r0, #0x8]
 *   @0x1880a8 str r1, [r2]
 *   @0x1880ac ldr r3, [r4, r3]
 *   @0x1880b0 ldr r3, [r3]
 *   @0x1880b4 blx r3
 *   @0x1880b8 mov r3, #0
 *   @0x1880bc strb r3, [r5]
 *   @0x1880c0 pop {r4, r5, r6, pc}
 *   @0x1880c4 ldr r3, [pc, #0x18]
 *   @0x1880c8 mvn r2, #0
 *   @0x1880cc ldr r3, [r4, r3]
 *   @0x1880d0 str r2, [r3]
 *   @0x1880d4 b 0x1880b8 <_Z13Shader_Commitv+0x5c>
 *   @0x1880d8 eoreq r9, r6, r8, ror #23
 *   @0x1880dc .word 0xffffe964
 *   @0x1880e0 .word 0xffffe96c
 *   @0x1880e4 .word 0xffffe940
 *   @0x1880e8 .word 0xffffbb80
 *
 * ══ §67/212 Motion_Potential_Settings(float, float, float, bool)  0x19cb18  size 144  36 条（0x19cb18..0x19cba8）
 * @func 0x19cb18 0x19cba8  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x58×2 / 0x70×1 / 0x6c×1 / 0x68×1
 * VFP 指令 16 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19cb18 vmov.f32 s15, #1.000000e+00
 *   @0x19cb1c ldr r12, [pc, #0x70]
 *   @0x19cb20 vmov s12, r0
 *   @0x19cb24 ldr r0, [pc, #0x6c]
 *   @0x19cb28 vmov s13, r1
 *   @0x19cb2c ldr r1, [pc, #0x68]
 *   @0x19cb30 vmov s14, r2
 *   @0x19cb34 add r12, pc, r12
 *   @0x19cb38 push {r4, r5}
 *   @0x19cb3c mov r2, r12
 *   @0x19cb40 ldr r5, [pc, #0x58]
 *   @0x19cb44 ldr r4, [pc, #0x58]
 *   @0x19cb48 ldr r0, [r12, r0]
 *   @0x19cb4c vcmpe.f32 s12, s15
 *   @0x19cb50 vmrs APSR_nzcv, fpscr
 *   @0x19cb54 vcmpe.f32 s13, s15
 *   @0x19cb58 vmovmi.f32 s12, s15
 *   @0x19cb5c vmrs APSR_nzcv, fpscr
 *   @0x19cb60 vstr s12, [r0]
 *   @0x19cb64 ldr r1, [r12, r1]
 *   @0x19cb68 vcmpe.f32 s14, s15
 *   @0x19cb6c vmovmi.f32 s13, s15
 *   @0x19cb70 vmrs APSR_nzcv, fpscr
 *   @0x19cb74 vstr s13, [r1]
 *   @0x19cb78 ldr r1, [r12, r5]
 *   @0x19cb7c vmovpl.f32 s15, s14
 *   @0x19cb80 vstr s15, [r1]
 *   @0x19cb84 ldr r2, [r12, r4]
 *   @0x19cb88 pop {r4, r5}
 *   @0x19cb8c strb r3, [r2]
 *   @0x19cb90 bx lr
 *   @0x19cb94 eoreq r5, r5, r12, lsl r1
 *   @0x19cb98 .word 0xffffea78
 *   @0x19cb9c .word 0xffffea7c
 *   @0x19cba0 .word 0xffffea80
 *   @0x19cba4 .word 0xffffea84
 *
 * ══ §68/212 F_LayerSpriteGetIndex(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bd74c  size 144  36 条（0x1bd74c..0x1bd7dc）
 * @func 0x1bd74c 0x1bd7dc  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x18×1 / 0x58×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bd74c cmp r3, #1
 *   @0x1bd750 push {r3, r4, r5, r6, r7, lr}
 *   @0x1bd754 mov r3, #0
 *   @0x1bd758 mov r4, r3
 *   @0x1bd75c mov r5, r0
 *   @0x1bd760 movt r3, #0xbff0
 *   @0x1bd764 str r4, [r0, #0xc]
 *   @0x1bd768 str r3, [r0, #0x4]
 *   @0x1bd76c str r4, [r0]
 *   @0x1bd770 ldr r6, [sp, #0x18]
 *   @0x1bd774 beq 0x1bd78c <_Z21F_LayerSpriteGetIndexR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bd778 ldr r0, [pc, #0x58]
 *   @0x1bd77c mov r1, r4
 *   @0x1bd780 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1bd784 add r0, pc, r0
 *   @0x1bd788 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bd78c bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bd790 mov r1, r4
 *   @0x1bd794 mov r7, r0
 *   @0x1bd798 mov r0, r6
 *   @0x1bd79c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bd7a0 mov r2, r4
 *   @0x1bd7a4 mov r1, r0
 *   @0x1bd7a8 mov r0, r7
 *   @0x1bd7ac bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bd7b0 cmp r0, #0
 *   @0x1bd7b4 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1bd7b8 ldr r3, [r0]
 *   @0x1bd7bc cmp r3, #4
 *   @0x1bd7c0 popne {r3, r4, r5, r6, r7, pc}
 *   @0x1bd7c4 vldr s15, [r0, #32]
 *   @0x1bd7c8 vcvt.f64.f32 d6, s15
 *   @0x1bd7cc vmov r2, r3, d6
 *   @0x1bd7d0 stm r5, {r2, r3}
 *   @0x1bd7d4 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bd7d8 andseq r0, r9, r4, lsl #28
 *
 * ══ §69/212 F_TilemapGetX(RValue&, CInstance*, CInstance*, int, RValue*)  0x1be5ec  size 144  36 条（0x1be5ec..0x1be67c）
 * @func 0x1be5ec 0x1be68c  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x18×1 / 0x58×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1be5ec cmp r3, #1
 *   @0x1be5f0 push {r3, r4, r5, r6, r7, lr}
 *   @0x1be5f4 mov r3, #0
 *   @0x1be5f8 mov r4, r3
 *   @0x1be5fc mov r5, r0
 *   @0x1be600 movt r3, #0xbff0
 *   @0x1be604 str r4, [r0, #0xc]
 *   @0x1be608 str r3, [r0, #0x4]
 *   @0x1be60c str r4, [r0]
 *   @0x1be610 ldr r6, [sp, #0x18]
 *   @0x1be614 beq 0x1be62c <_Z13F_TilemapGetXR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1be618 ldr r0, [pc, #0x58]
 *   @0x1be61c mov r1, r4
 *   @0x1be620 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1be624 add r0, pc, r0
 *   @0x1be628 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1be62c bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1be630 mov r1, r4
 *   @0x1be634 mov r7, r0
 *   @0x1be638 mov r0, r6
 *   @0x1be63c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1be640 mov r2, r4
 *   @0x1be644 mov r1, r0
 *   @0x1be648 mov r0, r7
 *   @0x1be64c bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1be650 cmp r0, #0
 *   @0x1be654 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1be658 ldr r3, [r0]
 *   @0x1be65c cmp r3, #5
 *   @0x1be660 popne {r3, r4, r5, r6, r7, pc}
 *   @0x1be664 vldr s15, [r0, #32]
 *   @0x1be668 vcvt.f64.f32 d6, s15
 *   @0x1be66c vmov r2, r3, d6
 *   @0x1be670 stm r5, {r2, r3}
 *   @0x1be674 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1be678 andseq r0, r9, r12, asr #10
 *
 * ══ §70/212 F_TilemapGetY(RValue&, CInstance*, CInstance*, int, RValue*)  0x1be67c  size 144  36 条（0x1be67c..0x1be70c）
 * @func 0x1be67c 0x1be70c  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x18×1 / 0x58×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1be67c cmp r3, #1
 *   @0x1be680 push {r3, r4, r5, r6, r7, lr}
 *   @0x1be684 mov r3, #0
 *   @0x1be688 mov r4, r3
 *   @0x1be68c mov r5, r0
 *   @0x1be690 movt r3, #0xbff0
 *   @0x1be694 str r4, [r0, #0xc]
 *   @0x1be698 str r3, [r0, #0x4]
 *   @0x1be69c str r4, [r0]
 *   @0x1be6a0 ldr r6, [sp, #0x18]
 *   @0x1be6a4 beq 0x1be6bc <_Z13F_TilemapGetYR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1be6a8 ldr r0, [pc, #0x58]
 *   @0x1be6ac mov r1, r4
 *   @0x1be6b0 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1be6b4 add r0, pc, r0
 *   @0x1be6b8 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1be6bc bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1be6c0 mov r1, r4
 *   @0x1be6c4 mov r7, r0
 *   @0x1be6c8 mov r0, r6
 *   @0x1be6cc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1be6d0 mov r2, r4
 *   @0x1be6d4 mov r1, r0
 *   @0x1be6d8 mov r0, r7
 *   @0x1be6dc bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1be6e0 cmp r0, #0
 *   @0x1be6e4 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1be6e8 ldr r3, [r0]
 *   @0x1be6ec cmp r3, #5
 *   @0x1be6f0 popne {r3, r4, r5, r6, r7, pc}
 *   @0x1be6f4 vldr s15, [r0, #36]
 *   @0x1be6f8 vcvt.f64.f32 d6, s15
 *   @0x1be6fc vmov r2, r3, d6
 *   @0x1be700 stm r5, {r2, r3}
 *   @0x1be704 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1be708 andseq r0, r9, r8, ror #9
 *
 * ══ §71/212 CSprite::LoadFromPNGData(void*, int, int, bool, bool, bool, int, int, bool)  0x1e70b0  size 144  36 条（0x1e70b0..0x1e7140）
 * @func 0x1e70b0 0x1e7140  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ReadPNGFile(void*, int, int*, int*, bool) / CSprite::LoadFromData(void*, int, int, int, bool, bool, bool, int, int, bool) / FreePNGFile()
 * 字段偏移 top8: 0x5c×1 / 0x48×1 / 0x4c×1 / 0x50×1 / 0x54×1 / 0x18×1 / 0x20×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e70b0 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x1e70b4 sub sp, sp, #44
 *   @0x1e70b8 mov r12, #0
 *   @0x1e70bc mov r9, r0
 *   @0x1e70c0 mov r8, r3
 *   @0x1e70c4 mov r0, r1
 *   @0x1e70c8 str r12, [sp]
 *   @0x1e70cc mov r1, r2
 *   @0x1e70d0 add r3, sp, #36
 *   @0x1e70d4 add r2, sp, #32
 *   @0x1e70d8 ldrb r4, [sp, #0x5c]
 *   @0x1e70dc ldrb r7, [sp, #0x48]
 *   @0x1e70e0 ldrb r6, [sp, #0x4c]
 *   @0x1e70e4 ldrb r5, [sp, #0x50]
 *   @0x1e70e8 bl 0x18a24c <_Z11ReadPNGFilePviPiS0_b>
 *   @0x1e70ec subs r1, r0, #0
 *   @0x1e70f0 moveq r4, r1
 *   @0x1e70f4 beq 0x1e7134 <_ZN7CSprite15LoadFromPNGDataEPviibbbiib+0x84>
 *   @0x1e70f8 ldr r12, [sp, #0x54]
 *   @0x1e70fc mov r0, r9
 *   @0x1e7100 str r4, [sp, #0x18]
 *   @0x1e7104 ldr r2, [sp, #0x20]
 *   @0x1e7108 str r12, [sp, #0x10]
 *   @0x1e710c ldr r12, [sp, #0x58]
 *   @0x1e7110 ldr r3, [sp, #0x24]
 *   @0x1e7114 str r8, [sp]
 *   @0x1e7118 str r7, [sp, #0x4]
 *   @0x1e711c str r6, [sp, #0x8]
 *   @0x1e7120 str r5, [sp, #0xc]
 *   @0x1e7124 str r12, [sp, #0x14]
 *   @0x1e7128 bl 0x1e6fd4 <_ZN7CSprite12LoadFromDataEPviiibbbiib>
 *   @0x1e712c mov r4, r0
 *   @0x1e7130 bl 0x18a518 <_Z11FreePNGFilev>
 *   @0x1e7134 mov r0, r4
 *   @0x1e7138 add sp, sp, #44
 *   @0x1e713c pop {r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §72/212 FreeRange(CVariableList&)  0x1f659c  size 144  36 条（0x1f659c..0x1f662c）
 * @func 0x1f659c 0x1f662c  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CVariableList::Free(RVariable*)
 * 字段偏移 top8: 0x4×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f659c push {r4, r5, r6, lr}
 *   @0x1f65a0 adds r4, r0, #4
 *   @0x1f65a4 addne r4, r0, #20
 *   @0x1f65a8 beq 0x1f6608 <_Z9FreeRangeR13CVariableList+0x6c>
 *   @0x1f65ac cmp r4, r0
 *   @0x1f65b0 add r6, r0, #4
 *   @0x1f65b4 beq 0x1f65c0 <_Z9FreeRangeR13CVariableList+0x24>
 *   @0x1f65b8 cmp r4, r6
 *   @0x1f65bc bne 0x1f6614 <_Z9FreeRangeR13CVariableList+0x78>
 *   @0x1f65c0 mov r6, r4
 *   @0x1f65c4 mov r5, #0
 *   @0x1f65c8 cmp r5, #0
 *   @0x1f65cc beq 0x1f6604 <_Z9FreeRangeR13CVariableList+0x68>
 *   @0x1f65d0 mov r0, r5
 *   @0x1f65d4 bl 0x1f6354 <_ZN13CVariableList4FreeEP9RVariable>
 *   @0x1f65d8 ldr r5, [r5]
 *   @0x1f65dc cmp r5, #0
 *   @0x1f65e0 add r3, r6, #4
 *   @0x1f65e4 bne 0x1f65c8 <_Z9FreeRangeR13CVariableList+0x2c>
 *   @0x1f65e8 cmp r4, r6
 *   @0x1f65ec beq 0x1f6628 <_Z9FreeRangeR13CVariableList+0x8c>
 *   @0x1f65f0 cmp r3, r4
 *   @0x1f65f4 popeq {r4, r5, r6, pc}
 *   @0x1f65f8 ldr r5, [r6, #0x4]
 *   @0x1f65fc mov r6, r3
 *   @0x1f6600 b 0x1f65dc <_Z9FreeRangeR13CVariableList+0x40>
 *   @0x1f6604 pop {r4, r5, r6, pc}
 *   @0x1f6608 mov r6, r4
 *   @0x1f660c mov r5, r4
 *   @0x1f6610 b 0x1f65c8 <_Z9FreeRangeR13CVariableList+0x2c>
 *   @0x1f6614 ldr r5, [r0, #0x4]
 *   @0x1f6618 cmp r5, #0
 *   @0x1f661c bne 0x1f65c8 <_Z9FreeRangeR13CVariableList+0x2c>
 *   @0x1f6620 mov r0, r6
 *   @0x1f6624 b 0x1f65ac <_Z9FreeRangeR13CVariableList+0x10>
 *   @0x1f6628 pop {r4, r5, r6, pc}
 *
 * ══ §73/212 CStream::Decrypt2(int, int, int)  0x2023f0  size 144  36 条（0x2023f0..0x202480）
 * @func 0x2023f0 0x202480  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::GetMemory()×2 / SetKey(int) / CStream::Decrypt2(int, int, int)+0x7c / CStream::GetSize()
 * 字段偏移 top8: 0x58×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2023f0 push {r4, r5, r6, r7, r8, lr}
 *   @0x2023f4 mov r6, r0
 *   @0x2023f8 mov r0, r1
 *   @0x2023fc mov r8, r3
 *   @0x202400 mov r4, r2
 *   @0x202404 bl 0x202294 <_Z6SetKeyi>
 *   @0x202408 cmp r8, #0
 *   @0x20240c ble 0x20246c <_ZN7CStream8Decrypt2Eiii+0x7c>
 *   @0x202410 add r8, r4, r8
 *   @0x202414 cmp r4, r8
 *   @0x202418 popge {r4, r5, r6, r7, r8, pc}
 *   @0x20241c ldr r7, [pc, #0x58]
 *   @0x202420 ldr r7, [pc, r7]
 *   @0x202424 mov r0, r6
 *   @0x202428 bl 0x201158 <_ZN7CStream9GetMemoryEv>
 *   @0x20242c asr r1, r4, #31
 *   @0x202430 lsr r1, r1, #24
 *   @0x202434 add r2, r4, r1
 *   @0x202438 uxtb r2, r2
 *   @0x20243c rsb r2, r1, r2
 *   @0x202440 ldrb r3, [r0, r4]
 *   @0x202444 mov r0, r6
 *   @0x202448 ldrb r1, [r7, r3]
 *   @0x20244c subs r5, r1, r2
 *   @0x202450 addmi r5, r5, #256
 *   @0x202454 bl 0x201158 <_ZN7CStream9GetMemoryEv>
 *   @0x202458 strb r5, [r0, r4]
 *   @0x20245c add r4, r4, #1
 *   @0x202460 cmp r4, r8
 *   @0x202464 bne 0x202424 <_ZN7CStream8Decrypt2Eiii+0x34>
 *   @0x202468 pop {r4, r5, r6, r7, r8, pc}
 *   @0x20246c mov r0, r6
 *   @0x202470 bl 0x201168 <_ZN7CStream7GetSizeEv>
 *   @0x202474 rsb r8, r4, r0
 *   @0x202478 b 0x202410 <_ZN7CStream8Decrypt2Eiii+0x20>
 *   @0x20247c andseq lr, lr, r0, ror #30
 *
 * ══ §74/212 CDS_Stack::WriteToString(char const*&)  0x202c70  size 144  36 条（0x202c70..0x202d00）
 * @func 0x202c70 0x202d00  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::WriteInteger(int)×2 / operator new(unsigned int) / CStream::CStream(int) / CDS_Stack::WriteToString(char const*&)+0x68 / WriteValue(CStream&, RValue&) / CStream::ConvertToString(char const*&) / CStream::~CStream()
 * 字段偏移 top8: 0x4×3 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x202c70 push {r3, r4, r5, r6, r7, lr}
 *   @0x202c74 mov r5, r0
 *   @0x202c78 mov r0, #32
 *   @0x202c7c mov r7, r1
 *   @0x202c80 bl 0x27c524 <_Znwj>
 *   @0x202c84 mov r1, #0
 *   @0x202c88 mov r6, r0
 *   @0x202c8c bl 0x2010ec <_ZN7CStreamC2Ei>
 *   @0x202c90 mov r0, r6
 *   @0x202c94 mov r1, #102
 *   @0x202c98 bl 0x201a10 <_ZN7CStream12WriteIntegerEi>
 *   @0x202c9c mov r0, r6
 *   @0x202ca0 ldr r1, [r5, #0x4]
 *   @0x202ca4 bl 0x201a10 <_ZN7CStream12WriteIntegerEi>
 *   @0x202ca8 ldr r3, [r5, #0x4]
 *   @0x202cac cmp r3, #0
 *   @0x202cb0 movgt r4, #0
 *   @0x202cb4 ble 0x202cd8 <_ZN9CDS_Stack13WriteToStringERPKc+0x68>
 *   @0x202cb8 ldr r1, [r5, #0xc]
 *   @0x202cbc mov r0, r6
 *   @0x202cc0 add r1, r1, r4, lsl #4
 *   @0x202cc4 add r4, r4, #1
 *   @0x202cc8 bl 0x202af8 <_Z10WriteValueR7CStreamR6RValue>
 *   @0x202ccc ldr r3, [r5, #0x4]
 *   @0x202cd0 cmp r3, r4
 *   @0x202cd4 bgt 0x202cb8 <_ZN9CDS_Stack13WriteToStringERPKc+0x48>
 *   @0x202cd8 mov r1, r7
 *   @0x202cdc mov r0, r6
 *   @0x202ce0 bl 0x2024b0 <_ZN7CStream15ConvertToStringERPKc>
 *   @0x202ce4 cmp r6, #0
 *   @0x202ce8 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x202cec mov r0, r6
 *   @0x202cf0 bl 0x201328 <_ZN7CStreamD2Ev>
 *   @0x202cf4 mov r0, r6
 *   @0x202cf8 pop {r3, r4, r5, r6, r7, lr}
 *   @0x202cfc b 0x27d1d0 <_ZdlPv>
 *
 * ══ §75/212 CDS_List::WriteToString(char const*&)  0x20301c  size 144  36 条（0x20301c..0x2030ac）
 * @func 0x20301c 0x2030ac  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::WriteInteger(int)×2 / operator new(unsigned int) / CStream::CStream(int) / CDS_List::WriteToString(char const*&)+0x68 / WriteValue(CStream&, RValue&) / CStream::ConvertToString(char const*&) / CStream::~CStream()
 * 字段偏移 top8: 0x4×3 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20301c push {r3, r4, r5, r6, r7, lr}
 *   @0x203020 mov r5, r0
 *   @0x203024 mov r0, #32
 *   @0x203028 mov r7, r1
 *   @0x20302c bl 0x27c524 <_Znwj>
 *   @0x203030 mov r1, #0
 *   @0x203034 mov r6, r0
 *   @0x203038 bl 0x2010ec <_ZN7CStreamC2Ei>
 *   @0x20303c mov r0, r6
 *   @0x203040 movw r1, #0x12e
 *   @0x203044 bl 0x201a10 <_ZN7CStream12WriteIntegerEi>
 *   @0x203048 mov r0, r6
 *   @0x20304c ldr r1, [r5, #0x4]
 *   @0x203050 bl 0x201a10 <_ZN7CStream12WriteIntegerEi>
 *   @0x203054 ldr r3, [r5, #0x4]
 *   @0x203058 cmp r3, #0
 *   @0x20305c movgt r4, #0
 *   @0x203060 ble 0x203084 <_ZN8CDS_List13WriteToStringERPKc+0x68>
 *   @0x203064 ldr r1, [r5, #0xc]
 *   @0x203068 mov r0, r6
 *   @0x20306c add r1, r1, r4, lsl #4
 *   @0x203070 add r4, r4, #1
 *   @0x203074 bl 0x202af8 <_Z10WriteValueR7CStreamR6RValue>
 *   @0x203078 ldr r3, [r5, #0x4]
 *   @0x20307c cmp r3, r4
 *   @0x203080 bgt 0x203064 <_ZN8CDS_List13WriteToStringERPKc+0x48>
 *   @0x203084 mov r1, r7
 *   @0x203088 mov r0, r6
 *   @0x20308c bl 0x2024b0 <_ZN7CStream15ConvertToStringERPKc>
 *   @0x203090 cmp r6, #0
 *   @0x203094 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x203098 mov r0, r6
 *   @0x20309c bl 0x201328 <_ZN7CStreamD2Ev>
 *   @0x2030a0 mov r0, r6
 *   @0x2030a4 pop {r3, r4, r5, r6, r7, lr}
 *   @0x2030a8 b 0x27d1d0 <_ZdlPv>
 *
 * ══ §76/212 CTimingSource::Update()  0x214770  size 144  36 条（0x214770..0x214800）
 * @func 0x214770 0x214800  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CTimingSource::Update()+0x74 / __fixdfdi / Timing_Time
 * 字段偏移 top8: 0x10×1
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x214770 vldr d7, [r0, #24]
 *   @0x214774 vcmpe.f64 d7, #0
 *   @0x214778 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x21477c mov r10, r0
 *   @0x214780 vmrs APSR_nzcv, fpscr
 *   @0x214784 ble 0x2147e4 <_ZN13CTimingSource6UpdateEv+0x74>
 *   @0x214788 vmov.f64 d5, #1.000000e+00
 *   @0x21478c vldr d6, [pc, #100]
 *   @0x214790 ldrd r8, r9, [r0, #8]
 *   @0x214794 mov r6, r8
 *   @0x214798 mov r7, r9
 *   @0x21479c vdiv.f64 d7, d5, d7
 *   @0x2147a0 vmul.f64 d5, d7, d6
 *   @0x2147a4 vmov r0, r1, d5
 *   @0x2147a8 bl 0x3194a0 <__fixdfdi>
 *   @0x2147ac adds r2, r8, r0
 *   @0x2147b0 adc r3, r9, r1
 *   @0x2147b4 ldrb r1, [r10, #0x10]
 *   @0x2147b8 subs r6, r2, r6
 *   @0x2147bc sbc r7, r3, r7
 *   @0x2147c0 strd r6, r7, [r10, #32]
 *   @0x2147c4 cmp r1, #0
 *   @0x2147c8 bne 0x2147dc <_ZN13CTimingSource6UpdateEv+0x6c>
 *   @0x2147cc ldrd r4, r5, [r10]
 *   @0x2147d0 adds r4, r4, r6
 *   @0x2147d4 adc r5, r5, r7
 *   @0x2147d8 strd r4, r5, [r10]
 *   @0x2147dc strd r2, r3, [r10, #8]
 *   @0x2147e0 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2147e4 bl 0x215148 <Timing_Time>
 *   @0x2147e8 ldrd r6, r7, [r10, #8]
 *   @0x2147ec mov r2, r0
 *   @0x2147f0 mov r3, r1
 *   @0x2147f4 b 0x2147b4 <_ZN13CTimingSource6UpdateEv+0x44>
 *   @0x2147f8 andeq r0, r0, r0
 *   @0x2147fc smlawbmi lr, r0, r4, r8
 *
 * ══ §77/212 CAudioGroup::AsyncDecode()  0x21dcb8  size 144  36 条（0x21dcb8..0x21dd48）
 * @func 0x21dcb8 0x21dd48  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int)×2 / Mutex::Mutex(char const*)
 * 字段偏移 top8: 0x4×3 / 0x20×2 / 0x68×1 / 0x8×1 / 0x9×1 / 0xc×1 / 0x10×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21dcb8 push {r4, r5, r6, lr}
 *   @0x21dcbc mov r2, r0
 *   @0x21dcc0 ldr r4, [r0, #0x20]
 *   @0x21dcc4 sub sp, sp, #8
 *   @0x21dcc8 cmp r4, #0
 *   @0x21dccc beq 0x21dcec <_ZN11CAudioGroup11AsyncDecodeEv+0x34>
 *   @0x21dcd0 ldr r1, [pc, #0x68]
 *   @0x21dcd4 mov r0, r4
 *   @0x21dcd8 mov r3, #1
 *   @0x21dcdc add r1, pc, r1
 *   @0x21dce0 add sp, sp, #8
 *   @0x21dce4 pop {r4, r5, r6, lr}
 *   @0x21dce8 b 0x27e0c0 <_ZN7CThread5StartEPFPvS0_ES0_NS_9ePriorityE>
 *   @0x21dcec mov r0, #24
 *   @0x21dcf0 str r2, [sp, #0x4]
 *   @0x21dcf4 bl 0x27c524 <_Znwj>
 *   @0x21dcf8 mov r5, r0
 *   @0x21dcfc strb r4, [r0, #0x8]
 *   @0x21dd00 str r4, [r5]
 *   @0x21dd04 mov r0, #8
 *   @0x21dd08 str r4, [r5, #0x4]
 *   @0x21dd0c strb r4, [r5, #0x9]
 *   @0x21dd10 str r4, [r5, #0xc]
 *   @0x21dd14 str r4, [r5, #0x10]
 *   @0x21dd18 mov r4, r5
 *   @0x21dd1c bl 0x27c524 <_Znwj>
 *   @0x21dd20 ldr r1, [pc, #0x1c]
 *   @0x21dd24 add r1, pc, r1
 *   @0x21dd28 mov r6, r0
 *   @0x21dd2c bl 0x27e070 <_ZN5MutexC2EPKc>
 *   @0x21dd30 ldr r2, [sp, #0x4]
 *   @0x21dd34 str r6, [r5, #0x14]
 *   @0x21dd38 str r5, [r2, #0x20]
 *   @0x21dd3c b 0x21dcd0 <_ZN11CAudioGroup11AsyncDecodeEv+0x18>
 *   @0x21dd40 .word 0xfffffe58
 *   @0x21dd44 mulseq r1, r0, r10
 *
 * ══ §78/212 SND_StopAll()  0x21ee90  size 144  36 条（0x21ee90..0x21ef20）
 * @func 0x21ee90 0x21ef20  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: SND_StopAll()+0x6c / SoundHardware::Stop(void*)
 * 字段偏移 top8: 0x74×1 / 0x60×1 / 0x50×1 / 0x4c×1 / 0x4×1 / 0x8×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21ee90 ldr r3, [pc, #0x74]
 *   @0x21ee94 push {r4, r5, r6, r7, r8, lr}
 *   @0x21ee98 ldr r3, [pc, r3]
 *   @0x21ee9c ldrb r4, [r3]
 *   @0x21eea0 cmp r4, #0
 *   @0x21eea4 popne {r4, r5, r6, r7, r8, pc}
 *   @0x21eea8 ldr r6, [pc, #0x60]
 *   @0x21eeac ldr r6, [pc, r6]
 *   @0x21eeb0 ldr r3, [r6]
 *   @0x21eeb4 cmp r3, #0
 *   @0x21eeb8 ble 0x21eefc <_Z11SND_StopAllv+0x6c>
 *   @0x21eebc ldr r7, [pc, #0x50]
 *   @0x21eec0 mov r5, r4
 *   @0x21eec4 ldr r8, [pc, #0x4c]
 *   @0x21eec8 ldr r7, [pc, r7]
 *   @0x21eecc add r8, pc, r8
 *   @0x21eed0 ldr r3, [r7, #0x4]
 *   @0x21eed4 add r5, r5, #1
 *   @0x21eed8 adds r3, r3, r4
 *   @0x21eedc add r4, r4, #20
 *   @0x21eee0 beq 0x21eef0 <_Z11SND_StopAllv+0x60>
 *   @0x21eee4 ldr r1, [r3, #0x8]
 *   @0x21eee8 ldr r0, [r8]
 *   @0x21eeec bl 0x220d90 <_ZN13SoundHardware4StopEPv>
 *   @0x21eef0 ldr r3, [r6]
 *   @0x21eef4 cmp r3, r5
 *   @0x21eef8 bgt 0x21eed0 <_Z11SND_StopAllv+0x40>
 *   @0x21eefc ldr r3, [pc, #0x18]
 *   @0x21ef00 pop {r4, r5, r6, r7, r8, lr}
 *   @0x21ef04 ldr r0, [pc, r3]
 *   @0x21ef08 b 0x220950 <_ZN13SoundHardware9StopMusicEv>
 *   @0x21ef0c ldrheq r0, [sp], -r4
 *   @0x21ef10 andseq r2, sp, r8, ror #10
 *   @0x21ef14 andseq r2, sp, r0, asr r5
 *   @0x21ef18 subseq r6, r3, r8, asr r4
 *   @0x21ef1c subseq r6, r3, r0, lsr #8
 *
 * ══ §79/212 SoundHardware::Pause(void*)  0x220fe8  size 144  36 条（0x220fe8..0x221078）
 * @func 0x220fe8 0x221078  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: SoundHardware::Playing(void*) / 0xb6ab4 / CheckALError()
 * 字段偏移 top8: 0x74×1 / 0x64×1 / 0x54×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x220fe8 push {r3, r4, r5, lr}
 *   @0x220fec mov r5, r1
 *   @0x220ff0 ldr r3, [pc, #0x74]
 *   @0x220ff4 ldr r3, [pc, r3]
 *   @0x220ff8 ldrb r3, [r3]
 *   @0x220ffc cmp r3, #0
 *   @0x221000 bne 0x221064 <_ZN13SoundHardware5PauseEPv+0x7c>
 *   @0x221004 ldr r3, [pc, #0x64]
 *   @0x221008 ldr r3, [pc, r3]
 *   @0x22100c ldrb r3, [r3]
 *   @0x221010 cmp r3, #0
 *   @0x221014 bne 0x221064 <_ZN13SoundHardware5PauseEPv+0x7c>
 *   @0x221018 ldr r3, [pc, #0x54]
 *   @0x22101c ldr r3, [pc, r3]
 *   @0x221020 ldrb r4, [r3]
 *   @0x221024 cmp r4, #0
 *   @0x221028 bne 0x221064 <_ZN13SoundHardware5PauseEPv+0x7c>
 *   @0x22102c cmp r1, #0
 *   @0x221030 beq 0x221064 <_ZN13SoundHardware5PauseEPv+0x7c>
 *   @0x221034 bl 0x220ee0 <_ZN13SoundHardware7PlayingEPv>
 *   @0x221038 cmp r0, #0
 *   @0x22103c beq 0x221064 <_ZN13SoundHardware5PauseEPv+0x7c>
 *   @0x221040 add r3, r5, r4
 *   @0x221044 add r4, r4, #4
 *   @0x221048 ldr r0, [r3, #0x4]
 *   @0x22104c bl 0xb6ab4 <alSourcePause@plt>
 *   @0x221050 bl 0x220198 <_Z12CheckALErrorv>
 *   @0x221054 cmp r4, #16
 *   @0x221058 bne 0x221040 <_ZN13SoundHardware5PauseEPv+0x58>
 *   @0x22105c mov r0, #1
 *   @0x221060 pop {r3, r4, r5, pc}
 *   @0x221064 mov r0, #0
 *   @0x221068 pop {r3, r4, r5, pc}
 *   @0x22106c andseq lr, r12, r8, asr r0
 *   @0x221070 andseq r0, sp, r8, lsr #8
 *   @0x221074 andseq r0, sp, r8, lsl r4
 *
 * ══ §80/212 COggAudio::Pause_Sound(int)  0x226470  size 144  36 条（0x226470..0x226500）
 * @func 0x226470 0x226510  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6a9c / COggAudio::GetThreadForChannel(int, int&) / COggThread::PauseResume_Sound(int, bool) / 0xb6ab4
 * 字段偏移 top8: 0x2×2 / 0x7c×1 / 0x-4×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x226470 push {r4, r5, r6, lr}
 *   @0x226474 sub sp, sp, #8
 *   @0x226478 ldr r4, [pc, #0x7c]
 *   @0x22647c mov r5, r1
 *   @0x226480 mov r2, sp
 *   @0x226484 mov r6, r0
 *   @0x226488 ldr r4, [pc, r4]
 *   @0x22648c movw r1, #0x1010
 *   @0x226490 ldr r3, [r4]
 *   @0x226494 ldr r0, [r3, r5, lsl #2]
 *   @0x226498 bl 0xb6a9c <alGetSourcei@plt>
 *   @0x22649c ldr r3, [sp]
 *   @0x2264a0 movw r2, #0x1012
 *   @0x2264a4 cmp r3, r2
 *   @0x2264a8 beq 0x2264ec <_ZN9COggAudio11Pause_SoundEi+0x7c>
 *   @0x2264ac movw r2, #0x1013
 *   @0x2264b0 cmp r3, r2
 *   @0x2264b4 beq 0x2264e4 <_ZN9COggAudio11Pause_SoundEi+0x74>
 *   @0x2264b8 add r2, sp, #8
 *   @0x2264bc mov r3, #0
 *   @0x2264c0 mov r0, r6
 *   @0x2264c4 mov r1, r5
 *   @0x2264c8 str r3, [r2, #-0x4]!
 *   @0x2264cc bl 0x226284 <_ZN9COggAudio19GetThreadForChannelEiRi>
 *   @0x2264d0 cmp r0, #0
 *   @0x2264d4 beq 0x2264e4 <_ZN9COggAudio11Pause_SoundEi+0x74>
 *   @0x2264d8 ldr r1, [sp, #0x4]
 *   @0x2264dc mov r2, #1
 *   @0x2264e0 bl 0x223b34 <_ZN10COggThread17PauseResume_SoundEib>
 *   @0x2264e4 add sp, sp, #8
 *   @0x2264e8 pop {r4, r5, r6, pc}
 *   @0x2264ec ldr r3, [r4]
 *   @0x2264f0 ldr r0, [r3, r5, lsl #2]
 *   @0x2264f4 bl 0xb6ab4 <alSourcePause@plt>
 *   @0x2264f8 b 0x2264e4 <_ZN9COggAudio11Pause_SoundEi+0x74>
 *   @0x2264fc andseq r10, r12, r4, asr #30
 *
 * ══ §81/212 COggAudio::Resume_Sound(int)  0x226500  size 144  36 条（0x226500..0x226590）
 * @func 0x226500 0x226590  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6a9c / COggAudio::GetThreadForChannel(int, int&) / COggThread::PauseResume_Sound(int, bool) / 0xb6a84
 * 字段偏移 top8: 0x2×2 / 0x7c×1 / 0x-4×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x226500 push {r4, r5, r6, lr}
 *   @0x226504 sub sp, sp, #8
 *   @0x226508 ldr r4, [pc, #0x7c]
 *   @0x22650c mov r5, r1
 *   @0x226510 mov r2, sp
 *   @0x226514 mov r6, r0
 *   @0x226518 ldr r4, [pc, r4]
 *   @0x22651c movw r1, #0x1010
 *   @0x226520 ldr r3, [r4]
 *   @0x226524 ldr r0, [r3, r5, lsl #2]
 *   @0x226528 bl 0xb6a9c <alGetSourcei@plt>
 *   @0x22652c ldr r3, [sp]
 *   @0x226530 movw r2, #0x1013
 *   @0x226534 cmp r3, r2
 *   @0x226538 beq 0x22657c <_ZN9COggAudio12Resume_SoundEi+0x7c>
 *   @0x22653c movw r2, #0x1012
 *   @0x226540 cmp r3, r2
 *   @0x226544 beq 0x226574 <_ZN9COggAudio12Resume_SoundEi+0x74>
 *   @0x226548 add r2, sp, #8
 *   @0x22654c mov r4, #0
 *   @0x226550 mov r0, r6
 *   @0x226554 mov r1, r5
 *   @0x226558 str r4, [r2, #-0x4]!
 *   @0x22655c bl 0x226284 <_ZN9COggAudio19GetThreadForChannelEiRi>
 *   @0x226560 cmp r0, r4
 *   @0x226564 beq 0x226574 <_ZN9COggAudio12Resume_SoundEi+0x74>
 *   @0x226568 mov r2, r4
 *   @0x22656c ldr r1, [sp, #0x4]
 *   @0x226570 bl 0x223b34 <_ZN10COggThread17PauseResume_SoundEib>
 *   @0x226574 add sp, sp, #8
 *   @0x226578 pop {r4, r5, r6, pc}
 *   @0x22657c ldr r3, [r4]
 *   @0x226580 ldr r0, [r3, r5, lsl #2]
 *   @0x226584 bl 0xb6a84 <alSourcePlay@plt>
 *   @0x226588 b 0x226574 <_ZN9COggAudio12Resume_SoundEi+0x74>
 *   @0x22658c ldrheq r10, [r12], -r4
 *
 * ══ §82/212 CPhysicsWorld::EndParticleGroup()  0x239d30  size 144  36 条（0x239d30..0x239dc0）
 * @func 0x239d30 0x239dc0  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2World::CreateParticleGroup(b2ParticleGroupDef const&) / CPhysicsWorld::GetFreeParticleGroupSlot() / CPhysicsWorld::EndParticleGroup()+0x84 / b2PolygonShape::Set(b2Vec2 const*, int)
 * 字段偏移 top8: 0x4×2 / 0x3c×1 / 0x10×1 / 0x48×1 / 0x2×1 / 0x94×1 / 0x-8×1 / 0x-4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x239d30 push {r4, r5, r6, lr}
 *   @0x239d34 mov r4, r0
 *   @0x239d38 ldr r0, [r0, #0x3c]
 *   @0x239d3c sub sp, sp, #64
 *   @0x239d40 cmp r0, #0
 *   @0x239d44 beq 0x239d54 <_ZN13CPhysicsWorld16EndParticleGroupEv+0x24>
 *   @0x239d48 ldr r3, [r0, #0x4]
 *   @0x239d4c cmp r3, #2
 *   @0x239d50 beq 0x239d7c <_ZN13CPhysicsWorld16EndParticleGroupEv+0x4c>
 *   @0x239d54 add r1, r4, #20
 *   @0x239d58 ldr r0, [r4, #0x10]
 *   @0x239d5c bl 0x2cb500 <_ZN7b2World19CreateParticleGroupERK18b2ParticleGroupDef>
 *   @0x239d60 mov r5, r0
 *   @0x239d64 mov r0, r4
 *   @0x239d68 bl 0x239c5c <_ZN13CPhysicsWorld24GetFreeParticleGroupSlotEv>
 *   @0x239d6c ldr r3, [r4, #0x48]
 *   @0x239d70 str r5, [r3, r0, lsl #2]
 *   @0x239d74 add sp, sp, #64
 *   @0x239d78 pop {r4, r5, r6, pc}
 *   @0x239d7c ldr r2, [r0, #0x94]
 *   @0x239d80 cmp r2, #0
 *   @0x239d84 addgt r12, r0, #20
 *   @0x239d88 addgt r6, sp, r2, lsl #3
 *   @0x239d8c movgt r3, sp
 *   @0x239d90 ble 0x239db4 <_ZN13CPhysicsWorld16EndParticleGroupEv+0x84>
 *   @0x239d94 ldr r5, [r12]
 *   @0x239d98 add r3, r3, #8
 *   @0x239d9c ldr lr, [r12, #0x4]
 *   @0x239da0 add r12, r12, #8
 *   @0x239da4 str r5, [r3, #-0x8]
 *   @0x239da8 str lr, [r3, #-0x4]
 *   @0x239dac cmp r3, r6
 *   @0x239db0 bne 0x239d94 <_ZN13CPhysicsWorld16EndParticleGroupEv+0x64>
 *   @0x239db4 mov r1, sp
 *   @0x239db8 bl 0x2c6028 <_ZN14b2PolygonShape3SetEPK6b2Vec2i>
 *   @0x239dbc b 0x239d54 <_ZN13CPhysicsWorld16EndParticleGroupEv+0x24>
 *
 * ══ §83/212 JS_Array_prototype_toString(RValue&, CInstance*, CInstance*, int, RValue*)  0x249898  size 144  36 条（0x249898..0x249928）
 * @func 0x249898 0x249928  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_JS_Object_Get(YYObjectBase*, RValue*, char const*) / JS_IsCallable(RValue&) / F_JS_Object_prototype_toString(RValue&, CInstance*, CInstance*, int, RValue*) / Call_RValue(YYObjectBase*, RValue*, RValue*, int, RValue*)
 * 字段偏移 top8: 0x74×1 / 0x14×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x249898 push {r4, r5, r6, r7, r8, lr}
 *   @0x24989c sub sp, sp, #24
 *   @0x2498a0 add r4, sp, #8
 *   @0x2498a4 mov r7, r2
 *   @0x2498a8 ldr r2, [pc, #0x74]
 *   @0x2498ac mov r5, r1
 *   @0x2498b0 mov r6, r0
 *   @0x2498b4 mov r0, r1
 *   @0x2498b8 add r2, pc, r2
 *   @0x2498bc mov r1, r4
 *   @0x2498c0 mov r12, #5
 *   @0x2498c4 mov r8, r3
 *   @0x2498c8 str r12, [sp, #0x14]
 *   @0x2498cc bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc>
 *   @0x2498d0 mov r0, r4
 *   @0x2498d4 bl 0x24076c <_Z13JS_IsCallableR6RValue>
 *   @0x2498d8 cmp r0, #0
 *   @0x2498dc bne 0x249904 <_Z27JS_Array_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x2498e0 ldr r3, [sp, #0x30]
 *   @0x2498e4 mov r0, r6
 *   @0x2498e8 mov r1, r5
 *   @0x2498ec mov r2, r7
 *   @0x2498f0 str r3, [sp]
 *   @0x2498f4 mov r3, r8
 *   @0x2498f8 bl 0x23cb44 <_Z30F_JS_Object_prototype_toStringR6RValueP9CInstanceS2_iPS_>
 *   @0x2498fc add sp, sp, #24
 *   @0x249900 pop {r4, r5, r6, r7, r8, pc}
 *   @0x249904 mov r3, #0
 *   @0x249908 mov r0, r5
 *   @0x24990c mov r1, r6
 *   @0x249910 mov r2, r4
 *   @0x249914 str r3, [sp]
 *   @0x249918 bl 0x249860 <_Z11Call_RValueP12YYObjectBaseP6RValueS2_iS2_>
 *   @0x24991c add sp, sp, #24
 *   @0x249920 pop {r4, r5, r6, r7, r8, pc}
 *   @0x249924 andseq r11, r0, r12, lsl #31
 *
 * ══ §84/212 spDrawOrderTimeline_create  0x282d4c  size 144  36 条（0x282d4c..0x282ddc）
 * @func 0x282d4c 0x282ddc  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _calloc×3 / _spTimeline_init
 * 字段偏移 top8: 0x58×2 / 0x74×1 / 0x8×1 / 0xc×1 / 0x14×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x282d4c push {r3, r4, r5, r6, r7, lr}
 *   @0x282d50 mov r5, r0
 *   @0x282d54 ldr r6, [pc, #0x74]
 *   @0x282d58 mov r7, r1
 *   @0x282d5c mov r3, #672
 *   @0x282d60 mov r1, #24
 *   @0x282d64 add r6, pc, r6
 *   @0x282d68 mov r0, #1
 *   @0x282d6c mov r2, r6
 *   @0x282d70 bl 0x285c4c <_calloc>
 *   @0x282d74 ldr r2, [pc, #0x58]
 *   @0x282d78 ldr r3, [pc, #0x58]
 *   @0x282d7c mov r1, #7
 *   @0x282d80 ldr r2, [pc, r2]
 *   @0x282d84 ldr r3, [pc, r3]
 *   @0x282d88 mov r4, r0
 *   @0x282d8c bl 0x281328 <_spTimeline_init>
 *   @0x282d90 mov r2, r6
 *   @0x282d94 str r5, [r4, #0x8]
 *   @0x282d98 mov r0, r5
 *   @0x282d9c mov r1, #4
 *   @0x282da0 mov r3, #676
 *   @0x282da4 bl 0x285c4c <_calloc>
 *   @0x282da8 mov r2, r6
 *   @0x282dac mov r1, #4
 *   @0x282db0 movw r3, #0x2a5
 *   @0x282db4 str r0, [r4, #0xc]
 *   @0x282db8 mov r0, r5
 *   @0x282dbc bl 0x285c4c <_calloc>
 *   @0x282dc0 str r7, [r4, #0x14]
 *   @0x282dc4 str r0, [r4, #0x10]
 *   @0x282dc8 mov r0, r4
 *   @0x282dcc pop {r3, r4, r5, r6, r7, pc}
 *   @0x282dd0 andeq r4, sp, r12, ror #13
 *   @0x282dd4 andseq lr, r6, r8, asr #22
 *   @0x282dd8 andseq lr, r6, r8, asr #22
 *
 * ══ §85/212 _zip_file_get_offset(zip*, int)  0x2a58ee  size 144  36 条（0x2a58ee..0x2a597e）
 * @func 0x2a58ee 0x2a597e  size 144  36 条
 * 部分覆盖: 本节 36/66 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xfe631d0e / 0xb6ed4 / 0xb6bf8 / _zip_dirent_read(zip_dirent*, __sFILE*, unsigned char**, unsigned int*, int, zip_error*) / _zip_dirent_read_buff(zip_dirent*, IBuffer*, unsigned char**, unsigned int*, int, zip_error*)
 * 字段偏移 top8: 0x4×2 / 0x20×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a58ee push {r4, r5, r6, r7, lr}
 *   @0x2a58f2 ldr r3, [r0, #0x20]
 *   @0x2a58f6 ldr r5, [r0, #0x4]
 *   @0x2a58fa add.w r7, r0, #0xc
 *   @0x2a58fe ldr r3, [r3]
 *   @0x2a5902 blvs 0xfe631d0e <b2_toiTime+0xfffffffffded886a>
 *   @0x2a5906 cbz r5, 0x2a593c <_Z20_zip_file_get_offsetP3zipi+0x4e>
 *   @0x2a590a mov r1, r6
 *   @0x2a590e blx 0xb6ed4 <fseeko@plt>
 *   @0x2a5912 mov r5, r0
 *   @0x2a5916 blx 0xb6bf8 <__errno@plt>
 *   @0x2a591a movs r1, #0x4
 *   @0x2a591e mov r0, r7
 *   @0x2a5922 andhs pc, r0, r10, lsl sp
 *   @0x2a5926 b 0x2a597a <_Z20_zip_file_get_offsetP3zipi+0x8c>
 *   @0x2a592a add r0, sp, #0xc
 *   @0x2a592e strtmi r0, [r10], -r8, lsl #1
 *   @0x2a5932 ldr r1, [r4, #0x4]
 *   @0x2a5936 bl 0x2a3ef0 <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error>
 *   @0x2a593a b 0x2a5962 <_Z20_zip_file_get_offsetP3zipi+0x74>
 *   @0x2a593e mov r1, r5
 *   @0x2a5942 ldr r3, [r0]
 *   @0x2a5946 blx r3
 *   @0x2a594a add r0, sp, #0xc
 *   @0x2a594e ldr r3, [r1, #0x1c]
 *   @0x2a5952 add r2, sp, #0x8
 *   @0x2a5956 movs r3, #0x1
 *   @0x2a595a strtmi r0, [r11], -r8, lsl #1
 *   @0x2a595e bl 0x2a4108 <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error>
 *   @0x2a5962 cbnz r0, 0x2a5978 <_Z20_zip_file_get_offsetP3zipi+0x8a>
 *   @0x2a5966 stmdage r3, {r3, r5, r12, lr}
 *   @0x2a596a ldrh.w r3, [sp, #0x30]
 *   @0x2a596e adds r5, #0x1e
 *   @0x2a5972 add r5, r6
 *   @0x2a5976 strtmi pc, [r8], -pc, lsr #18
 *   @0x2a597a add sp, #0x4c
 *
 * ══ §86/212 anon_2a6398  0x2a6398  size 144  36 条（0x2a6398..0x2a6428）
 * @func 0x2a6398 0x2a6428  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6398 mvnsmi lr, #737280
 *   @0x2a639c cdpmi p4, #0x2, c2, c2, c0, #0x0
 *   @0x2a63a0 .word 0xf04f4623
 *   @0x2a63a4 .word 0xf04f0c5b
 *   @0x2a63a8 ldrbtmi r0, [lr], #-2141
 *   @0x2a63ac stmdbne r5, {r0, r10, r12, sp}
 *   @0x2a63b0 .word 0x51dff895
 *   @0x2a63b4 strbeq pc, [r1, -r5, lsr #3]
 *   @0x2a63b8 stmdale r3, {r0, r3, r4, r5, r8, r9, r10, r11, sp}
 *   @0x2a63bc ldrbeq pc, [r11, -r5, lsr #3]
 *   @0x2a63c0 ldmdale r2, {r0, r2, r8, r9, r10, r11, sp}
 *   @0x2a63c4 ldmdbne r5, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc}
 *   @0x2a63c8 streq pc, [pc, #-0x5]
 *   @0x2a63cc .word 0xf80118cf
 *   @0x2a63d0 .word 0xf816c003
 *   @0x2a63d4 ldclpl p0, c9, [r5, #-36]!
 *   @0x2a63d8 andls pc, r1, r7, lsl #17
 *   @0x2a63dc stmdbeq r3, {r0, r1, r8, r12, sp, lr, pc}
 *   @0x2a63e0 movwlo r7, #0x40bd
 *   @0x2a63e4 andhi pc, r9, r1, lsl #16
 *   @0x2a63e8 strbpl lr, [sp], #1
 *   @0x2a63ec .word 0x2c043301
 *   @0x2a63f0 ldmdblt r2, {r2, r3, r4, r6, r7, r8, r12, lr, pc}
 *   @0x2a63f4 pop {r1, r3, r6, r7, r10, r12, lr}
 *   @0x2a63f8 stmne r12, {r4, r5, r6, r7, r8, r9, pc} ^
 *   @0x2a63fc strhs r2, [r0, #-0x3a]!
 *   @0x2a6400 ldcne p4, c5, [r8], {200}
 *   @0x2a6404 .word 0xf1037065
 *   @0x2a6408 bne 0xff767914 <b2_toiTime+0xffffffffff00e470>
 *   @0x2a640c .word 0xf814181c
 *   @0x2a6410 .word 0xb12c4c02
 *   @0x2a6414 stmdane r10, {r0, r12, sp}
 *   @0x2a6418 .word 0xf80242a8
 *   @0x2a641c mvnsle r4, r1, lsl #24
 *   @0x2a6420 strpl r2, [r11], #-768
 *   @0x2a6424 mvnshi lr, #12386304
 *
 * ══ §87/212 png_get_IHDR  0x2a693e  size 144  36 条（0x2a693e..0x2a69ce）
 * @func 0x2a693e 0x2a69ce  size 144  36 条
 * 部分覆盖: 本节 36/66 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_check_IHDR
 * 字段偏移 top8: 0x18×2 / 0x1c×2 / 0x2c×1 / 0x4×1 / 0x19×1 / 0x1a×1 / 0x1b×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a693e push.w {r0, r1, r2, r3, r4, r5, r6, r7, r8, lr}
 *   @0x2a6942 mov r4, r1
 *   @0x2a6946 ldr r1, [sp, #0x2c]
 *   @0x2a694a .word 0xf8ddc030
 *   @0x2a694e svcls #0xe8034
 *   @0x2a6952 cmp r0, #0x0
 *   @0x2a6956 cmp r4, #0x0
 *   @0x2a695a cmp r2, #0x0
 *   @0x2a695e cmp r3, #0x0
 *   @0x2a6962 cmp r5, #0x0
 *   @0x2a6966 cmp r1, #0x0
 *   @0x2a696a ldr r6, [r4]
 *   @0x2a696e ldr r2, [r4, #0x4]
 *   @0x2a6972 ldrb r3, [r4, #0x18]
 *   @0x2a6976 ldrb r3, [r4, #0x19]
 *   @0x2a697a cmp.w r8, #0x0
 *   @0x2a697e beq 0x2a6986 <png_get_IHDR+0x48>
 *   @0x2a6982 str.w r3, [r8]
 *   @0x2a6986 cbz r7, 0x2a698c <png_get_IHDR+0x4e>
 *   @0x2a698a str r3, [r7]
 *   @0x2a698e andle r0, r2, r0, lsl #30
 *   @0x2a6992 ldrb r3, [r4, #0x1c]
 *   @0x2a6996 cdpvc p0, #0x6, c3, c2, c0, #0x0
 *   @0x2a699a ldrb r3, [r4, #0x18]
 *   @0x2a699e ldrb r2, [r4, #0x1c]
 *   @0x2a69a2 ldrb r2, [r4, #0x1a]
 *   @0x2a69a6 ldrb r2, [r4, #0x1b]
 *   @0x2a69aa ldm.w r4, {r1, r2}
 *   @0x2a69ae bl 0x2a61b0 <png_check_IHDR>
 *   @0x2a69b2 movs r0, #0x1
 *   @0x2a69b6 mov r0, r4
 *   @0x2a69ba mov r0, r2
 *   @0x2a69be mov r0, r3
 *   @0x2a69c2 mov r0, r5
 *   @0x2a69c6 mov r0, r1
 *   @0x2a69ca pop.w {r4, r5, r6, r7, r8, pc}
 *
 * ══ §88/212 png_set_gAMA  0x2ae8f8  size 144  36 条（0x2ae8f8..0x2ae988）
 * @func 0x2ae8f8 0x2ae988  size 144  36 条
 * 部分覆盖: 本节 36/54 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_warning
 * 字段偏移 top8: 0x64×1 / 0x8×1 / 0x28×1 / 0x20×1
 * VFP 指令 13 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ae8f8 push {r3, r4, r5, lr}
 *   @0x2ae8fc strmi r8, [r12], -r2, lsl #22
 *   @0x2ae900 vmov d7, r2, r3
 *   @0x2ae904 mov r5, r0
 *   @0x2ae908 cbz r1, 0x2ae964 <png_set_gAMA+0x6c>
 *   @0x2ae90c .word 0xeeb48b19
 *   @0x2ae910 vsqrt.f64 d23, d8
 *   @0x2ae914 vstrle s30, [r5, #-64]
 *   @0x2ae918 ldr r1, [pc, #0x64]
 *   @0x2ae91c bl 0x2a6474 <png_warning>
 *   @0x2ae920 vmov.f64 d7, d8
 *   @0x2ae924 vldr d5, [pc, #80]
 *   @0x2ae928 ldr r3, [r4, #0x8]
 *   @0x2ae92c .word 0xf0436bc7
 *   @0x2ae930 adcvs r0, r3, r1, lsl #6
 *   @0x2ae934 vstr s13, [r4, #40]
 *   @0x2ae938 vmov.f64 d6, #5.000000e-01
 *   @0x2ae93c vmla.f64 d6, d7, d5
 *   @0x2ae940 vcvt.s32.f64 s12, d6
 *   @0x2ae944 vcmp.f64 d7, #0
 *   @0x2ae948 vstr s12, [r4, #252]
 *   @0x2ae94c vmrs APSR_nzcv, fpscr
 *   @0x2ae950 bne 0x2ae964 <png_set_gAMA+0x6c>
 *   @0x2ae954 strtmi r8, [r8], -r2, lsl #22
 *   @0x2ae958 ldr r1, [pc, #0x28]
 *   @0x2ae95c pop.w {r3, r4, r5, lr}
 *   @0x2ae960 b.w 0x2a6474 <png_warning>
 *   @0x2ae964 vpop {d8}
 *   @0x2ae968 pop {r3, r4, r5, pc}
 *   @0x2ae96c nop.w
 *   @0x2ae970 str r4, [r5, r7]
 *   @0x2ae974 ldrh.w r4, [r5, #0xd4]
 *   @0x2ae978 movs r0, r0
 *   @0x2ae97c ldr r0, [r0, #0x20]
 *   @0x2ae980 adcs r0, r12, #0xd
 *   @0x2ae984 .word 0xf137 000d
 *
 * ══ §89/212 FT_Get_Kerning  0x2e581c  size 142  36 条（0x2e581c..0x2e58aa）
 * @func 0x2e581c 0x2e58ac  size 144  36 条
 * 部分覆盖: 本节 36/69 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FT_MulDiv
 * 字段偏移 top8: 0x58×3 / 0x4×3 / 0x18×1 / 0x60×1 / 0xc×1 / 0x10×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e581c push {r3, r4, r5, r6, r7, lr}
 *   @0x2e5820 ldr r4, [sp, #0x18]
 *   @0x2e5824 cmp r0, #0x0
 *   @0x2e5828 cmp r4, #0x0
 *   @0x2e582c ldr r7, [r0, #0x60]
 *   @0x2e5830 str r3, [r4]
 *   @0x2e5834 ldr r3, [r7, #0xc]
 *   @0x2e5838 cmp r7, #0x0
 *   @0x2e583c mov r3, r4
 *   @0x2e5840 cmp r0, #0x0
 *   @0x2e5844 cmp r6, #0x2
 *   @0x2e5848 ldr r3, [r5, #0x58]
 *   @0x2e584c ldr r1, [r3, #0x10]
 *   @0x2e5850 .word 0x6020fafd
 *   @0x2e5854 ldr r3, [r5, #0x58]
 *   @0x2e5858 ldr r1, [r3, #0x14]
 *   @0x2e585c .word 0x2e01faf7
 *   @0x2e5860 mov r7, r0
 *   @0x2e5864 beq 0x2e589e <FT_Get_Kerning+0x82>
 *   @0x2e5868 ldr r0, [r4]
 *   @0x2e586c cmp r1, #0x18
 *   @0x2e5870 movs r2, #0x19
 *   @0x2e5874 eorvs pc, r0, r3, ror #20
 *   @0x2e5878 ldr r3, [r5, #0x58]
 *   @0x2e587c cmp r1, #0x18
 *   @0x2e5880 mov r0, r7
 *   @0x2e5884 bl 0x2e4d3c <FT_MulDiv>
 *   @0x2e5888 str r0, [r4, #0x4]
 *   @0x2e588c adds r3, #0x20
 *   @0x2e5890 eorvs r0, r3, pc, lsr r3
 *   @0x2e5894 ldr r3, [r4, #0x4]
 *   @0x2e5898 bic r3, r3, #0x3f
 *   @0x2e589c str r3, [r4, #0x4]
 *   @0x2e58a0 pop {r3, r4, r5, r6, r7, pc}
 *   @0x2e58a4 pop {r3, r4, r5, r6, r7, pc}
 *   @0x2e58a8 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §90/212 CSkeletonInstance::SelectAnimationExt(char const*, int)  0xbe4ec  size 140  35 条（0xbe4ec..0xbe578）
 * @func 0xbe4ec 0xbe578  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spSkeletonData_findAnimation×2
 * 字段偏移 top8: 0x30×1 / 0x34×1 / 0x38×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xbe4ec push {r4, r5, r6, lr}
 *   @0xbe4f0 mov r4, r0
 *   @0xbe4f4 ldr r0, [r0, #0x30]
 *   @0xbe4f8 mov r5, r2
 *   @0xbe4fc cmp r0, #0
 *   @0xbe500 popeq {r4, r5, r6, pc}
 *   @0xbe504 rsbs r6, r2, #1
 *   @0xbe508 movlo r6, #0
 *   @0xbe50c cmp r1, #0
 *   @0xbe510 cmpeq r2, #0
 *   @0xbe514 bne 0xbe564 <_ZN17CSkeletonInstance18SelectAnimationExtEPKci+0x78>
 *   @0xbe518 ldr r3, [r0, #0x34]
 *   @0xbe51c cmp r3, #0
 *   @0xbe520 pople {r4, r5, r6, pc}
 *   @0xbe524 ldr r3, [r0, #0x38]
 *   @0xbe528 ldr r3, [r3]
 *   @0xbe52c ldr r1, [r3]
 *   @0xbe530 bl 0x28b1dc <spSkeletonData_findAnimation>
 *   @0xbe534 mov r2, r0
 *   @0xbe538 cmp r2, #0
 *   @0xbe53c popeq {r4, r5, r6, pc}
 *   @0xbe540 cmp r6, #0
 *   @0xbe544 ldr r0, [r4, #0x28]
 *   @0xbe548 strne r2, [r4, #0x24]
 *   @0xbe54c mov r1, r5
 *   @0xbe550 movne r3, #0
 *   @0xbe554 strne r3, [r4]
 *   @0xbe558 mov r3, #1
 *   @0xbe55c pop {r4, r5, r6, lr}
 *   @0xbe560 b 0x283900 <spAnimationState_setAnimation>
 *   @0xbe564 bl 0x28b1dc <spSkeletonData_findAnimation>
 *   @0xbe568 mov r2, r0
 *   @0xbe56c cmp r2, #0
 *   @0xbe570 bne 0xbe540 <_ZN17CSkeletonInstance18SelectAnimationExtEPKci+0x54>
 *   @0xbe574 pop {r4, r5, r6, pc}
 *
 * ══ §91/212 CBackground::Clear()  0xc23c0  size 140  35 条（0xc23c0..0xc244c）
 * @func 0xc23c0 0xc244c  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*) / CBackground::FreeTexture()
 * 字段偏移 top8: 0x10×2 / 0x4×2 / 0x14×2 / 0x18×2 / 0x8×1 / 0x9×1 / 0xa×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc23c0 push {r3, r4, r5, lr}
 *   @0xc23c4 mov r4, r0
 *   @0xc23c8 ldr r0, [r0, #0x10]
 *   @0xc23cc cmp r0, #0
 *   @0xc23d0 beq 0xc23e0 <_ZN11CBackground5ClearEv+0x20>
 *   @0xc23d4 ldr r3, [r0]
 *   @0xc23d8 ldr r3, [r3, #0x4]
 *   @0xc23dc blx r3
 *   @0xc23e0 ldr r0, [r4, #0x14]
 *   @0xc23e4 mov r5, #0
 *   @0xc23e8 str r5, [r4, #0x10]
 *   @0xc23ec cmp r0, r5
 *   @0xc23f0 str r5, [r4]
 *   @0xc23f4 str r5, [r4, #0x4]
 *   @0xc23f8 strb r5, [r4, #0x8]
 *   @0xc23fc strb r5, [r4, #0x9]
 *   @0xc2400 strb r5, [r4, #0xa]
 *   @0xc2404 beq 0xc241c <_ZN11CBackground5ClearEv+0x5c>
 *   @0xc2408 ldrb r3, [r4, #0x18]
 *   @0xc240c cmp r3, r5
 *   @0xc2410 beq 0xc241c <_ZN11CBackground5ClearEv+0x5c>
 *   @0xc2414 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xc2418 strb r5, [r4, #0x18]
 *   @0xc241c mov r5, #0
 *   @0xc2420 mov r0, r4
 *   @0xc2424 str r5, [r4, #0x14]
 *   @0xc2428 bl 0xc1e3c <_ZN11CBackground11FreeTextureEv>
 *   @0xc242c mvn r3, #0
 *   @0xc2430 str r5, [r4, #0x1c]
 *   @0xc2434 str r5, [r4, #0x20]
 *   @0xc2438 str r5, [r4, #0x24]
 *   @0xc243c str r5, [r4, #0x28]
 *   @0xc2440 str r5, [r4, #0x2c]
 *   @0xc2444 str r3, [r4, #0xc]
 *   @0xc2448 pop {r3, r4, r5, pc}
 *
 * ══ §92/212 VMBuffer::~VMBuffer()  0xce4c0  size 140  35 条（0xce4c0..0xce54c）
 * @func 0xce4c0 0xce54c  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / MemoryInWad(void*) / operator delete[](void*) / operator delete(void*)
 * 字段偏移 top8: 0x10×3 / 0x14×2 / 0x18×2 / 0x74×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xce4c0 push {r4, lr}
 *   @0xce4c4 mov r4, r0
 *   @0xce4c8 ldr r0, [r0, #0x14]
 *   @0xce4cc ldr r3, [pc, #0x74]
 *   @0xce4d0 cmp r0, #0
 *   @0xce4d4 ldr r3, [pc, r3]
 *   @0xce4d8 add r3, r3, #8
 *   @0xce4dc str r3, [r4]
 *   @0xce4e0 beq 0xce4f0 <_ZN8VMBufferD0Ev+0x30>
 *   @0xce4e4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xce4e8 mov r3, #0
 *   @0xce4ec str r3, [r4, #0x14]
 *   @0xce4f0 ldr r0, [r4, #0x18]
 *   @0xce4f4 cmp r0, #0
 *   @0xce4f8 beq 0xce508 <_ZN8VMBufferD0Ev+0x48>
 *   @0xce4fc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xce500 mov r3, #0
 *   @0xce504 str r3, [r4, #0x18]
 *   @0xce508 ldr r0, [r4, #0x10]
 *   @0xce50c cmp r0, #0
 *   @0xce510 beq 0xce538 <_ZN8VMBufferD0Ev+0x78>
 *   @0xce514 bl 0x1aad50 <_Z11MemoryInWadPv>
 *   @0xce518 cmp r0, #0
 *   @0xce51c bne 0xce538 <_ZN8VMBufferD0Ev+0x78>
 *   @0xce520 ldr r0, [r4, #0x10]
 *   @0xce524 cmp r0, #0
 *   @0xce528 beq 0xce530 <_ZN8VMBufferD0Ev+0x70>
 *   @0xce52c bl 0x27d1d4 <_ZdaPv>
 *   @0xce530 mov r3, #0
 *   @0xce534 str r3, [r4, #0x10]
 *   @0xce538 mov r0, r4
 *   @0xce53c bl 0x27d1d0 <_ZdlPv>
 *   @0xce540 mov r0, r4
 *   @0xce544 pop {r4, pc}
 *   @0xce548 eorseq pc, r1, r8, asr r6
 *
 * ══ §93/212 GetFirstSlotTraversalDivergence(int, int)  0xd5ad4  size 140  35 条（0xd5ad4..0xd5b60）
 * @func 0xd5ad4 0xd5b60  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GetFirstSlotTraversalDivergence(int, int)+0x7c
 * 字段偏移 top8: 0x2×4 / 0x4×2 / 0x7c×1 / 0x58×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd5ad4 ldr r3, [pc, #0x7c]
 *   @0xd5ad8 push {r4, r5, r6}
 *   @0xd5adc ldr r3, [pc, r3]
 *   @0xd5ae0 ldr r5, [r3, r0, lsl #2]
 *   @0xd5ae4 ldr r6, [r3, r1, lsl #2]
 *   @0xd5ae8 cmp r5, r6
 *   @0xd5aec movlt r4, r5
 *   @0xd5af0 movge r4, r6
 *   @0xd5af4 cmp r4, #0
 *   @0xd5af8 ble 0xd5b50 <_Z31GetFirstSlotTraversalDivergenceii+0x7c>
 *   @0xd5afc ldr r3, [pc, #0x58]
 *   @0xd5b00 ldr r3, [pc, r3]
 *   @0xd5b04 ldr r2, [r3, r0, lsl #2]
 *   @0xd5b08 ldr r3, [r3, r1, lsl #2]
 *   @0xd5b0c ldr r0, [r2]
 *   @0xd5b10 ldr r1, [r3]
 *   @0xd5b14 cmp r0, r1
 *   @0xd5b18 mov r0, #0
 *   @0xd5b1c beq 0xd5b34 <_Z31GetFirstSlotTraversalDivergenceii+0x60>
 *   @0xd5b20 b 0xd5b48 <_Z31GetFirstSlotTraversalDivergenceii+0x74>
 *   @0xd5b24 ldr r12, [r2, #0x4]!
 *   @0xd5b28 ldr r1, [r3, #0x4]!
 *   @0xd5b2c cmp r12, r1
 *   @0xd5b30 bne 0xd5b48 <_Z31GetFirstSlotTraversalDivergenceii+0x74>
 *   @0xd5b34 add r0, r0, #1
 *   @0xd5b38 cmp r0, r4
 *   @0xd5b3c bne 0xd5b24 <_Z31GetFirstSlotTraversalDivergenceii+0x50>
 *   @0xd5b40 cmp r5, r6
 *   @0xd5b44 mvneq r0, #0
 *   @0xd5b48 pop {r4, r5, r6}
 *   @0xd5b4c bx lr
 *   @0xd5b50 mov r0, #0
 *   @0xd5b54 b 0xd5b40 <_Z31GetFirstSlotTraversalDivergenceii+0x6c>
 *   @0xd5b58 eorseq r8, r1, r8, ror r1
 *   @0xd5b5c eorseq r8, r1, r12, asr r1
 *
 * ══ §94/212 VMWriteBuffer::~VMWriteBuffer()  0xec528  size 140  35 条（0xec528..0xec5b4）
 * @func 0xec528 0xec5b4  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / MemoryInWad(void*) / operator delete[](void*) / operator delete(void*)
 * 字段偏移 top8: 0x10×3 / 0x14×2 / 0x18×2 / 0x74×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xec528 push {r4, lr}
 *   @0xec52c mov r4, r0
 *   @0xec530 ldr r0, [r0, #0x14]
 *   @0xec534 ldr r3, [pc, #0x74]
 *   @0xec538 cmp r0, #0
 *   @0xec53c ldr r3, [pc, r3]
 *   @0xec540 add r3, r3, #8
 *   @0xec544 str r3, [r4]
 *   @0xec548 beq 0xec558 <_ZN13VMWriteBufferD0Ev+0x30>
 *   @0xec54c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xec550 mov r3, #0
 *   @0xec554 str r3, [r4, #0x14]
 *   @0xec558 ldr r0, [r4, #0x18]
 *   @0xec55c cmp r0, #0
 *   @0xec560 beq 0xec570 <_ZN13VMWriteBufferD0Ev+0x48>
 *   @0xec564 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xec568 mov r3, #0
 *   @0xec56c str r3, [r4, #0x18]
 *   @0xec570 ldr r0, [r4, #0x10]
 *   @0xec574 cmp r0, #0
 *   @0xec578 beq 0xec5a0 <_ZN13VMWriteBufferD0Ev+0x78>
 *   @0xec57c bl 0x1aad50 <_Z11MemoryInWadPv>
 *   @0xec580 cmp r0, #0
 *   @0xec584 bne 0xec5a0 <_ZN13VMWriteBufferD0Ev+0x78>
 *   @0xec588 ldr r0, [r4, #0x10]
 *   @0xec58c cmp r0, #0
 *   @0xec590 beq 0xec598 <_ZN13VMWriteBufferD0Ev+0x70>
 *   @0xec594 bl 0x27d1d4 <_ZdaPv>
 *   @0xec598 mov r3, #0
 *   @0xec59c str r3, [r4, #0x10]
 *   @0xec5a0 mov r0, r4
 *   @0xec5a4 bl 0x27d1d0 <_ZdlPv>
 *   @0xec5a8 mov r0, r4
 *   @0xec5ac pop {r4, pc}
 *   @0xec5b0 ldrshteq r1, [r0], -r0
 *
 * ══ §95/212 InputQuery::SetUserNamePassword(int, int, char const*)  0xf27b4  size 140  35 条（0xf27b4..0xf2840）
 * @func 0xf27b4 0xf2840  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6538
 * 字段偏移 top8: 0x80×1 / 0x4×1 / 0x24×1 / 0x28×1 / 0xc×1 / 0x38×1 / 0x34×1 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf27b4 ldr r3, [pc, #0x80]
 *   @0xf27b8 push {r4, r5, r6, lr}
 *   @0xf27bc ldr r3, [pc, r3]
 *   @0xf27c0 mov r5, r1
 *   @0xf27c4 mov r6, r2
 *   @0xf27c8 ldr r4, [r3]
 *   @0xf27cc cmp r4, #0
 *   @0xf27d0 bne 0xf27e4 <_ZN10InputQuery19SetUserNamePasswordEiiPKc+0x30>
 *   @0xf27d4 pop {r4, r5, r6, pc}
 *   @0xf27d8 ldr r4, [r4, #0x4]
 *   @0xf27dc cmp r4, #0
 *   @0xf27e0 beq 0xf2838 <_ZN10InputQuery19SetUserNamePasswordEiiPKc+0x84>
 *   @0xf27e4 ldr r3, [r4, #0x24]
 *   @0xf27e8 cmp r3, r0
 *   @0xf27ec bne 0xf27d8 <_ZN10InputQuery19SetUserNamePasswordEiiPKc+0x24>
 *   @0xf27f0 cmp r6, #0
 *   @0xf27f4 mov r3, #7
 *   @0xf27f8 str r5, [r4, #0x28]
 *   @0xf27fc str r3, [r4, #0xc]
 *   @0xf2800 moveq r0, #1
 *   @0xf2804 beq 0xf2814 <_ZN10InputQuery19SetUserNamePasswordEiiPKc+0x60>
 *   @0xf2808 mov r0, r6
 *   @0xf280c bl 0xb6538 <strlen@plt>
 *   @0xf2810 add r0, r0, #1
 *   @0xf2814 cmp r5, #0
 *   @0xf2818 str r0, [r4, #0x38]
 *   @0xf281c str r6, [r4, #0x34]
 *   @0xf2820 addne r3, r5, #1
 *   @0xf2824 str r5, [r4, #0x3c]
 *   @0xf2828 movne r2, #0
 *   @0xf282c strbne r2, [r6, r5]
 *   @0xf2830 strne r3, [r4, #0x28]
 *   @0xf2834 pop {r4, r5, r6, pc}
 *   @0xf2838 pop {r4, r5, r6, pc}
 *   @0xf283c eoreq r11, pc, r12, lsr r6
 *
 * ══ §96/212 CEvent::LoadFromChunk(YYEvent*, unsigned char*)  0xf2d84  size 140  35 条（0xf2d84..0xf2e10）
 * @func 0xf2d84 0xf2e10  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int) / CCode::CCode(int, bool)
 * 字段偏移 top8: 0x4×2 / 0x54×1 / 0x44×1 / 0x34×1 / 0x8×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2d84 ldr r3, [r1, #0x4]
 *   @0xf2d88 push {r4, r5, r6, lr}
 *   @0xf2d8c cmp r3, #0
 *   @0xf2d90 mov r4, r0
 *   @0xf2d94 moveq r5, r3
 *   @0xf2d98 ldrne r2, [pc, #0x60]
 *   @0xf2d9c ldrne r2, [pc, r2]
 *   @0xf2da0 ldrne r5, [r2]
 *   @0xf2da4 addne r5, r5, r3
 *   @0xf2da8 ldr r3, [pc, #0x54]
 *   @0xf2dac ldr r3, [pc, r3]
 *   @0xf2db0 ldrb r2, [r3]
 *   @0xf2db4 cmp r2, #0
 *   @0xf2db8 bne 0xf2dd0 <_ZN6CEvent13LoadFromChunkEP7YYEventPh+0x4c>
 *   @0xf2dbc ldr r2, [pc, #0x44]
 *   @0xf2dc0 ldr r2, [pc, r2]
 *   @0xf2dc4 ldrb r3, [r2]
 *   @0xf2dc8 cmp r3, #0
 *   @0xf2dcc beq 0xf2df8 <_ZN6CEvent13LoadFromChunkEP7YYEventPh+0x74>
 *   @0xf2dd0 ldr r3, [pc, #0x34]
 *   @0xf2dd4 mov r0, #124
 *   @0xf2dd8 add r3, pc, r3
 *   @0xf2ddc str r3, [r4, #0x8]
 *   @0xf2de0 bl 0x27c524 <_Znwj>
 *   @0xf2de4 ldr r1, [r5, #0x20]
 *   @0xf2de8 mov r2, #0
 *   @0xf2dec mov r6, r0
 *   @0xf2df0 bl 0xcefc8 <_ZN5CCodeC2Eib>
 *   @0xf2df4 str r6, [r4, #0x4]
 *   @0xf2df8 mov r0, #1
 *   @0xf2dfc pop {r4, r5, r6, pc}
 *   @0xf2e00 eoreq r10, pc, r8, lsr #23
 *   @0xf2e04 .word 0x002fadb4
 *   @0xf2e08 eoreq r10, pc, r12, asr sp
 *   @0xf2e0c eoreq r11, r3, lr, asr sp
 *
 * ══ §97/212 CExtensionPackage::Clear()  0xf563c  size 140  35 条（0xf563c..0xf56c8）
 * @func 0xf563c 0xf56c8  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYRandom(int) / 0xb65c8 / YYStrDup(char const*) / CExtensionPackage::SetIncludesCount(int) / 0xb65d4
 * 字段偏移 top8: 0x8×2 / 0x104×2 / 0x74×1 / 0x4×1 / 0xc×1 / 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf563c push {r4, r5, r6, r7, lr}
 *   @0xf5640 mov r4, r0
 *   @0xf5644 ldr r5, [pc, #0x74]
 *   @0xf5648 sub sp, sp, #268
 *   @0xf564c mov r6, #0
 *   @0xf5650 movw r0, #0x3e7
 *   @0xf5654 ldr r5, [pc, r5]
 *   @0xf5658 str r6, [r4, #0x4]
 *   @0xf565c str r6, [r4, #0x8]
 *   @0xf5660 add r7, sp, #4
 *   @0xf5664 ldr r3, [r5]
 *   @0xf5668 str r6, [r4, #0xc]
 *   @0xf566c str r3, [sp, #0x104]
 *   @0xf5670 bl 0xc4600 <_Z8YYRandomi>
 *   @0xf5674 ldr r2, [pc, #0x48]
 *   @0xf5678 mov r1, #256
 *   @0xf567c add r2, pc, r2
 *   @0xf5680 mov r3, r0
 *   @0xf5684 mov r0, r7
 *   @0xf5688 bl 0xb65c8 <snprintf@plt>
 *   @0xf568c mov r0, r7
 *   @0xf5690 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xf5694 mov r1, r6
 *   @0xf5698 str r0, [r4, #0x8]
 *   @0xf569c mov r0, r4
 *   @0xf56a0 bl 0xf5638 <_ZN17CExtensionPackage16SetIncludesCountEi>
 *   @0xf56a4 ldr r2, [sp, #0x104]
 *   @0xf56a8 ldr r3, [r5]
 *   @0xf56ac cmp r2, r3
 *   @0xf56b0 bne 0xf56bc <_ZN17CExtensionPackage5ClearEv+0x80>
 *   @0xf56b4 add sp, sp, #268
 *   @0xf56b8 pop {r4, r5, r6, r7, pc}
 *   @0xf56bc bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0xf56c0 .word 0x002f82fc
 *   @0xf56c4 .word 0x002422d8
 *
 * ══ §98/212 F_DsListSet(RValue&, CInstance*, CInstance*, int, RValue*)  0xfc5a4  size 140  35 条（0xfc5a4..0xfc630）
 * @func 0xfc5a4 0xfc640  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / F_DsListSet(RValue&, CInstance*, CInstance*, int, RValue*)+0x6c
 * 字段偏移 top8: 0x10×1 / 0x5c×1 / 0x4c×1 / 0x4×1 / 0x2×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfc5a4 push {r4, r5, r6, lr}
 *   @0xfc5a8 mov r1, #0
 *   @0xfc5ac ldr r4, [sp, #0x10]
 *   @0xfc5b0 mov r0, r4
 *   @0xfc5b4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfc5b8 cmp r0, #0
 *   @0xfc5bc blt 0xfc610 <_Z11F_DsListSetR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0xfc5c0 ldr r3, [pc, #0x5c]
 *   @0xfc5c4 ldr r3, [pc, r3]
 *   @0xfc5c8 ldr r3, [r3]
 *   @0xfc5cc cmp r0, r3
 *   @0xfc5d0 bge 0xfc610 <_Z11F_DsListSetR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0xfc5d4 ldr r3, [pc, #0x4c]
 *   @0xfc5d8 ldr r3, [pc, r3]
 *   @0xfc5dc ldr r3, [r3, #0x4]
 *   @0xfc5e0 ldr r5, [r3, r0, lsl #2]
 *   @0xfc5e4 cmp r5, #0
 *   @0xfc5e8 beq 0xfc610 <_Z11F_DsListSetR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0xfc5ec mov r0, r4
 *   @0xfc5f0 mov r1, #1
 *   @0xfc5f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfc5f8 add r2, r4, #32
 *   @0xfc5fc mov r3, #0
 *   @0xfc600 mov r1, r0
 *   @0xfc604 mov r0, r5
 *   @0xfc608 pop {r4, r5, r6, lr}
 *   @0xfc60c b 0x2060c0 <_ZN8CDS_List3SetEiP6RValueS1_>
 *   @0xfc610 ldr r0, [pc, #0x14]
 *   @0xfc614 mov r1, #0
 *   @0xfc618 pop {r4, r5, r6, lr}
 *   @0xfc61c add r0, pc, r0
 *   @0xfc620 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfc624 .word 0x002f16b8
 *   @0xfc628 eoreq r1, pc, r8, lsr #13
 *   @0xfc62c eoreq r11, r3, r0, ror #11
 *
 * ══ §99/212 dsMapAddInt64  0x101968  size 140  35 条（0x101968..0x1019f4）
 * @func 0x101968 0x101a04  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYSetString(RValue*, char const*) / F_DsMapAdd(RValue&, CInstance*, CInstance*, int, RValue*)
 * 字段偏移 top8: 0x44×2 / 0x34×1 / 0x8×1 / 0x20×1 / 0x30×1 / 0x40×1 / 0x24×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x101968 vmov s13, r0
 *   @0x10196c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x101970 vcvt.f64.s32 d7, s13
 *   @0x101974 sub sp, sp, #76
 *   @0x101978 mov r8, #0
 *   @0x10197c add r9, sp, #72
 *   @0x101980 add r0, sp, #40
 *   @0x101984 mov r6, r2
 *   @0x101988 mov r7, r3
 *   @0x10198c mov r4, #0
 *   @0x101990 mvn r3, #-16777216
 *   @0x101994 mov r5, #0
 *   @0x101998 str r3, [sp, #0x34]
 *   @0x10199c str r3, [sp, #0x44]
 *   @0x1019a0 vmov r10, r11, d7
 *   @0x1019a4 str r8, [sp, #0x8]
 *   @0x1019a8 str r8, [sp, #0x20]
 *   @0x1019ac str r8, [sp, #0x30]
 *   @0x1019b0 str r8, [sp, #0x40]
 *   @0x1019b4 str r8, [sp, #0x24]
 *   @0x1019b8 strd r4, r5, [sp, #40]
 *   @0x1019bc strd r4, r5, [sp, #56]
 *   @0x1019c0 strd r10, r11, [r9, #-48]!
 *   @0x1019c4 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x1019c8 mov r1, r8
 *   @0x1019cc str r9, [sp]
 *   @0x1019d0 mov r2, r8
 *   @0x1019d4 add r0, sp, #8
 *   @0x1019d8 mov r3, #3
 *   @0x1019dc mov r12, #10
 *   @0x1019e0 strd r6, r7, [sp, #56]
 *   @0x1019e4 str r12, [sp, #0x44]
 *   @0x1019e8 bl 0xff014 <_Z10F_DsMapAddR6RValueP9CInstanceS2_iPS_>
 *   @0x1019ec add sp, sp, #76
 *   @0x1019f0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §100/212 F_ArcSin(RValue&, CInstance*, CInstance*, int, RValue*)  0x10e704  size 140  35 条（0x10e704..0x10e790）
 * @func 0x10e704 0x10e790  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int) / F_ArcSin(RValue&, CInstance*, CInstance*, int, RValue*)+0x40 / F_ArcSin(RValue&, CInstance*, CInstance*, int, RValue*)+0x54 / 0xb6754
 * 字段偏移 top8: 0x8×1 / 0xc×1 / 0x40×1
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10e704 push {r4, lr}
 *   @0x10e708 mov r1, #0
 *   @0x10e70c ldr r3, [sp, #0x8]
 *   @0x10e710 mov r4, r0
 *   @0x10e714 str r1, [r0, #0xc]
 *   @0x10e718 mov r0, r3
 *   @0x10e71c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10e720 vmov.f32 s14, #-1.000000e+00
 *   @0x10e724 vmov s15, r0
 *   @0x10e728 vcmpe.f32 s15, s14
 *   @0x10e72c vmrs APSR_nzcv, fpscr
 *   @0x10e730 blt 0x10e744 <_Z8F_ArcSinR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x10e734 vmov.f32 s14, #1.000000e+00
 *   @0x10e738 vcmpe.f32 s15, s14
 *   @0x10e73c vmrs APSR_nzcv, fpscr
 *   @0x10e740 bls 0x10e758 <_Z8F_ArcSinR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x10e744 ldr r0, [pc, #0x40]
 *   @0x10e748 mov r1, #0
 *   @0x10e74c pop {r4, lr}
 *   @0x10e750 add r0, pc, r0
 *   @0x10e754 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x10e758 bl 0xb6754 <asinf@plt>
 *   @0x10e75c vldr s14, [pc, #36]
 *   @0x10e760 vmov s15, r0
 *   @0x10e764 vabs.f32 s13, s15
 *   @0x10e768 vcmpe.f32 s13, s14
 *   @0x10e76c vmrs APSR_nzcv, fpscr
 *   @0x10e770 vcvtpl.f64.f32 d6, s15
 *   @0x10e774 movmi r2, #0
 *   @0x10e778 movmi r3, #0
 *   @0x10e77c vmovpl r2, r3, d6
 *   @0x10e780 stm r4, {r2, r3}
 *   @0x10e784 pop {r4, pc}
 *   @0x10e788 strlo r12, [r7, -r12, lsr #11]!
 *   @0x10e78c .word 0x0022a6bc
 *
 * ══ §101/212 F_DateCompareTime(RValue&, CInstance*, CInstance*, int, RValue*)  0x115d48  size 140  35 条（0x115d48..0x115dd4）
 * @func 0x115d48 0x115dd4  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×2 / 0xb6718×2
 * 字段偏移 top8: 0x28×1 / 0xc×1 / 0x4×1
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x115d48 push {r4, r5, r6, r7, lr}
 *   @0x115d4c vpush {d8}
 *   @0x115d50 sub sp, sp, #12
 *   @0x115d54 mov r5, #0
 *   @0x115d58 mov r4, r0
 *   @0x115d5c ldr r6, [sp, #0x28]
 *   @0x115d60 mov r1, r5
 *   @0x115d64 str r5, [r0, #0xc]
 *   @0x115d68 mov r0, r6
 *   @0x115d6c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x115d70 mov r2, sp
 *   @0x115d74 bl 0xb6718 <modf@plt>
 *   @0x115d78 vmov d8, r0, r1
 *   @0x115d7c mov r0, r6
 *   @0x115d80 mov r1, #1
 *   @0x115d84 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x115d88 mov r2, sp
 *   @0x115d8c bl 0xb6718 <modf@plt>
 *   @0x115d90 vmov d7, r0, r1
 *   @0x115d94 vcmp.f64 d8, d7
 *   @0x115d98 vmrs APSR_nzcv, fpscr
 *   @0x115d9c moveq r3, r5
 *   @0x115da0 beq 0x115dc0 <_Z17F_DateCompareTimeR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x115da4 vcmpe.f64 d8, d7
 *   @0x115da8 mov r2, r5
 *   @0x115dac mov r3, r5
 *   @0x115db0 movt r2, #0x3ff0
 *   @0x115db4 movt r3, #0xbff0
 *   @0x115db8 vmrs APSR_nzcv, fpscr
 *   @0x115dbc movgt r3, r2
 *   @0x115dc0 str r5, [r4]
 *   @0x115dc4 str r3, [r4, #0x4]
 *   @0x115dc8 add sp, sp, #12
 *   @0x115dcc vpop {d8}
 *   @0x115dd0 pop {r4, r5, r6, r7, pc}
 *
 * ══ §102/212 F_DrawLineExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x11b430  size 140  35 条（0x11b430..0x11b4bc）
 * @func 0x11b430 0x11b4bc  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×4 / YYGetInt32(RValue const*, int)×2 / GR_Draw_Line_Ext(float, float, float, float, unsigned int, unsigned int)
 * 字段偏移 top8: 0x28×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11b430 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x11b434 sub sp, sp, #12
 *   @0x11b438 mov r1, #0
 *   @0x11b43c ldr r4, [sp, #0x28]
 *   @0x11b440 mov r0, r4
 *   @0x11b444 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b448 mov r1, #1
 *   @0x11b44c mov r5, r0
 *   @0x11b450 mov r0, r4
 *   @0x11b454 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b458 mov r1, #2
 *   @0x11b45c mov r8, r0
 *   @0x11b460 mov r0, r4
 *   @0x11b464 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b468 mov r1, #3
 *   @0x11b46c mov r7, r0
 *   @0x11b470 mov r0, r4
 *   @0x11b474 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b478 mov r1, #4
 *   @0x11b47c mov r6, r0
 *   @0x11b480 mov r0, r4
 *   @0x11b484 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11b488 mov r1, #5
 *   @0x11b48c mov r9, r0
 *   @0x11b490 mov r0, r4
 *   @0x11b494 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11b498 str r9, [sp]
 *   @0x11b49c mov r1, r8
 *   @0x11b4a0 mov r2, r7
 *   @0x11b4a4 mov r3, r6
 *   @0x11b4a8 str r0, [sp, #0x4]
 *   @0x11b4ac mov r0, r5
 *   @0x11b4b0 bl 0x16a45c <_Z16GR_Draw_Line_Extffffjj>
 *   @0x11b4b4 add sp, sp, #12
 *   @0x11b4b8 pop {r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §103/212 F_DrawCircleExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x11b894  size 140  35 条（0x11b894..0x11b920）
 * @func 0x11b894 0x11b920  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×3 / YYGetInt32(RValue const*, int)×2 / YYGetBool(RValue const*, int) / GR_Draw_Circle_Ext(float, float, float, unsigned int, unsigned int, bool)
 * 字段偏移 top8: 0x28×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11b894 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x11b898 sub sp, sp, #12
 *   @0x11b89c mov r1, #0
 *   @0x11b8a0 ldr r4, [sp, #0x28]
 *   @0x11b8a4 mov r0, r4
 *   @0x11b8a8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b8ac mov r1, #1
 *   @0x11b8b0 mov r5, r0
 *   @0x11b8b4 mov r0, r4
 *   @0x11b8b8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b8bc mov r1, #2
 *   @0x11b8c0 mov r8, r0
 *   @0x11b8c4 mov r0, r4
 *   @0x11b8c8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b8cc mov r1, #3
 *   @0x11b8d0 mov r6, r0
 *   @0x11b8d4 mov r0, r4
 *   @0x11b8d8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11b8dc mov r1, #4
 *   @0x11b8e0 mov r7, r0
 *   @0x11b8e4 mov r0, r4
 *   @0x11b8e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11b8ec mov r1, #5
 *   @0x11b8f0 mov r9, r0
 *   @0x11b8f4 mov r0, r4
 *   @0x11b8f8 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x11b8fc str r9, [sp]
 *   @0x11b900 mov r1, r8
 *   @0x11b904 mov r3, r7
 *   @0x11b908 mov r2, r6
 *   @0x11b90c str r0, [sp, #0x4]
 *   @0x11b910 mov r0, r5
 *   @0x11b914 bl 0x16b1f4 <_Z18GR_Draw_Circle_Extfffjjb>
 *   @0x11b918 add sp, sp, #12
 *   @0x11b91c pop {r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §104/212 F_DrawVertexTextureColor(RValue&, CInstance*, CInstance*, int, RValue*)  0x11bb18  size 140  35 条（0x11bb18..0x11bba4）
 * @func 0x11bb18 0x11bba4  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×5 / YYGetInt32(RValue const*, int) / GR_Draw_Vertex_Texture_Color(float, float, float, float, unsigned int, float)
 * 字段偏移 top8: 0x28×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11bb18 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x11bb1c sub sp, sp, #12
 *   @0x11bb20 mov r1, #0
 *   @0x11bb24 ldr r4, [sp, #0x28]
 *   @0x11bb28 mov r0, r4
 *   @0x11bb2c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11bb30 mov r1, #1
 *   @0x11bb34 mov r5, r0
 *   @0x11bb38 mov r0, r4
 *   @0x11bb3c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11bb40 mov r1, #2
 *   @0x11bb44 mov r8, r0
 *   @0x11bb48 mov r0, r4
 *   @0x11bb4c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11bb50 mov r1, #3
 *   @0x11bb54 mov r7, r0
 *   @0x11bb58 mov r0, r4
 *   @0x11bb5c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11bb60 mov r1, #4
 *   @0x11bb64 mov r6, r0
 *   @0x11bb68 mov r0, r4
 *   @0x11bb6c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11bb70 mov r1, #5
 *   @0x11bb74 mov r9, r0
 *   @0x11bb78 mov r0, r4
 *   @0x11bb7c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11bb80 str r9, [sp]
 *   @0x11bb84 mov r1, r8
 *   @0x11bb88 mov r2, r7
 *   @0x11bb8c mov r3, r6
 *   @0x11bb90 str r0, [sp, #0x4]
 *   @0x11bb94 mov r0, r5
 *   @0x11bb98 bl 0x16bc84 <_Z28GR_Draw_Vertex_Texture_Colorffffjf>
 *   @0x11bb9c add sp, sp, #12
 *   @0x11bba0 pop {r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §105/212 F_SkeletonAnimationMix(RValue&, CInstance*, CInstance*, int, RValue*)  0x11cdbc  size 140  35 条（0x11cdbc..0x11ce48）
 * @func 0x11cdbc 0x11ce48  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)×2 / YYGetFloat(RValue const*, int) / CInstance::SkeletonAnimation() / CSkeletonInstance::SetAnimationMix(char const*, char const*, float)
 * 字段偏移 top8: 0x4×2 / 0x20×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11cdbc push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x11cdc0 mov r5, #0
 *   @0x11cdc4 ldr r6, [sp, #0x20]
 *   @0x11cdc8 mov r7, r1
 *   @0x11cdcc str r5, [r0, #0xc]
 *   @0x11cdd0 mov r1, r5
 *   @0x11cdd4 str r5, [r0]
 *   @0x11cdd8 mov r4, r0
 *   @0x11cddc mov r3, r5
 *   @0x11cde0 movt r3, #0xbff0
 *   @0x11cde4 str r3, [r0, #0x4]
 *   @0x11cde8 mov r0, r6
 *   @0x11cdec bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x11cdf0 mov r1, #1
 *   @0x11cdf4 mov r8, r0
 *   @0x11cdf8 mov r0, r6
 *   @0x11cdfc bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x11ce00 mov r1, #2
 *   @0x11ce04 mov r9, r0
 *   @0x11ce08 mov r0, r6
 *   @0x11ce0c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11ce10 mov r6, r0
 *   @0x11ce14 mov r0, r7
 *   @0x11ce18 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv>
 *   @0x11ce1c cmp r0, r5
 *   @0x11ce20 popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x11ce24 mov r3, r6
 *   @0x11ce28 mov r1, r8
 *   @0x11ce2c mov r2, r9
 *   @0x11ce30 bl 0xbe580 <_ZN17CSkeletonInstance15SetAnimationMixEPKcS1_f>
 *   @0x11ce34 mov r3, r5
 *   @0x11ce38 str r5, [r4]
 *   @0x11ce3c movt r3, #0x3ff0
 *   @0x11ce40 str r3, [r4, #0x4]
 *   @0x11ce44 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §106/212 F_TileGetX(RValue&, CInstance*, CInstance*, int, RValue*)  0x11fed4  size 140  35 条（0x11fed4..0x11ff60）
 * @func 0x11fed4 0x11ff70  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CRoom::FindTile(int) / F_TileGetX(RValue&, CInstance*, CInstance*, int, RValue*)+0x68
 * 字段偏移 top8: 0x18×2 / 0x74×1 / 0xc×1 / 0xb8×1 / 0x4×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11fed4 push {r3, r4, r5, r6, r7, lr}
 *   @0x11fed8 mov r5, r0
 *   @0x11fedc ldr r4, [pc, #0x74]
 *   @0x11fee0 mov r6, #0
 *   @0x11fee4 mov r1, r6
 *   @0x11fee8 ldr r0, [sp, #0x18]
 *   @0x11feec ldr r4, [pc, r4]
 *   @0x11fef0 str r6, [r5, #0xc]
 *   @0x11fef4 ldr r7, [r4]
 *   @0x11fef8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11fefc mov r1, r0
 *   @0x11ff00 mov r0, r7
 *   @0x11ff04 bl 0x1af2bc <_ZN5CRoom8FindTileEi>
 *   @0x11ff08 cmp r0, #0
 *   @0x11ff0c blt 0x11ff3c <_Z10F_TileGetXR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x11ff10 ldr r3, [r4]
 *   @0x11ff14 ldr r2, [r3, #0xb8]
 *   @0x11ff18 cmp r0, r2
 *   @0x11ff1c rsblt r0, r0, r0, lsl #3
 *   @0x11ff20 ldrlt r3, [r3, #0xc0]
 *   @0x11ff24 addlt r6, r3, r0, lsl #3
 *   @0x11ff28 vldr s15, [r6]
 *   @0x11ff2c vcvt.f64.f32 d6, s15
 *   @0x11ff30 vmov r2, r3, d6
 *   @0x11ff34 stm r5, {r2, r3}
 *   @0x11ff38 pop {r3, r4, r5, r6, r7, pc}
 *   @0x11ff3c ldr r0, [pc, #0x18]
 *   @0x11ff40 mov r1, r6
 *   @0x11ff44 str r6, [r5]
 *   @0x11ff48 str r6, [r5, #0x4]
 *   @0x11ff4c add r0, pc, r0
 *   @0x11ff50 pop {r3, r4, r5, r6, r7, lr}
 *   @0x11ff54 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x11ff58 eoreq sp, r12, r12, lsr r10
 *   @0x11ff5c .word 0x0021a2b0
 *
 * ══ §107/212 F_TileGetY(RValue&, CInstance*, CInstance*, int, RValue*)  0x11ff60  size 140  35 条（0x11ff60..0x11ffec）
 * @func 0x11ff60 0x11fffc  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CRoom::FindTile(int) / F_TileGetY(RValue&, CInstance*, CInstance*, int, RValue*)+0x68
 * 字段偏移 top8: 0x18×2 / 0x74×1 / 0xc×1 / 0xb8×1 / 0x4×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11ff60 push {r3, r4, r5, r6, r7, lr}
 *   @0x11ff64 mov r5, r0
 *   @0x11ff68 ldr r4, [pc, #0x74]
 *   @0x11ff6c mov r6, #0
 *   @0x11ff70 mov r1, r6
 *   @0x11ff74 ldr r0, [sp, #0x18]
 *   @0x11ff78 ldr r4, [pc, r4]
 *   @0x11ff7c str r6, [r5, #0xc]
 *   @0x11ff80 ldr r7, [r4]
 *   @0x11ff84 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11ff88 mov r1, r0
 *   @0x11ff8c mov r0, r7
 *   @0x11ff90 bl 0x1af2bc <_ZN5CRoom8FindTileEi>
 *   @0x11ff94 cmp r0, #0
 *   @0x11ff98 blt 0x11ffc8 <_Z10F_TileGetYR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x11ff9c ldr r3, [r4]
 *   @0x11ffa0 ldr r2, [r3, #0xb8]
 *   @0x11ffa4 cmp r0, r2
 *   @0x11ffa8 rsblt r0, r0, r0, lsl #3
 *   @0x11ffac ldrlt r3, [r3, #0xc0]
 *   @0x11ffb0 addlt r6, r3, r0, lsl #3
 *   @0x11ffb4 vldr s15, [r6, #4]
 *   @0x11ffb8 vcvt.f64.f32 d6, s15
 *   @0x11ffbc vmov r2, r3, d6
 *   @0x11ffc0 stm r5, {r2, r3}
 *   @0x11ffc4 pop {r3, r4, r5, r6, r7, pc}
 *   @0x11ffc8 ldr r0, [pc, #0x18]
 *   @0x11ffcc mov r1, r6
 *   @0x11ffd0 str r6, [r5]
 *   @0x11ffd4 str r6, [r5, #0x4]
 *   @0x11ffd8 add r0, pc, r0
 *   @0x11ffdc pop {r3, r4, r5, r6, r7, lr}
 *   @0x11ffe0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x11ffe4 .word 0x002cd9b0
 *   @0x11ffe8 eoreq r10, r1, r4, lsr #4
 *
 * ══ §108/212 F_TileGetDepth(RValue&, CInstance*, CInstance*, int, RValue*)  0x12022c  size 140  35 条（0x12022c..0x1202b8）
 * @func 0x12022c 0x1202c8  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CRoom::FindTile(int) / F_TileGetDepth(RValue&, CInstance*, CInstance*, int, RValue*)+0x68
 * 字段偏移 top8: 0x18×2 / 0x74×1 / 0xc×1 / 0xb8×1 / 0x4×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12022c push {r3, r4, r5, r6, r7, lr}
 *   @0x120230 mov r5, r0
 *   @0x120234 ldr r4, [pc, #0x74]
 *   @0x120238 mov r6, #0
 *   @0x12023c mov r1, r6
 *   @0x120240 ldr r0, [sp, #0x18]
 *   @0x120244 ldr r4, [pc, r4]
 *   @0x120248 str r6, [r5, #0xc]
 *   @0x12024c ldr r7, [r4]
 *   @0x120250 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x120254 mov r1, r0
 *   @0x120258 mov r0, r7
 *   @0x12025c bl 0x1af2bc <_ZN5CRoom8FindTileEi>
 *   @0x120260 cmp r0, #0
 *   @0x120264 blt 0x120294 <_Z14F_TileGetDepthR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x120268 ldr r3, [r4]
 *   @0x12026c ldr r2, [r3, #0xb8]
 *   @0x120270 cmp r0, r2
 *   @0x120274 rsblt r0, r0, r0, lsl #3
 *   @0x120278 ldrlt r3, [r3, #0xc0]
 *   @0x12027c addlt r6, r3, r0, lsl #3
 *   @0x120280 vldr s15, [r6, #28]
 *   @0x120284 vcvt.f64.f32 d6, s15
 *   @0x120288 vmov r2, r3, d6
 *   @0x12028c stm r5, {r2, r3}
 *   @0x120290 pop {r3, r4, r5, r6, r7, pc}
 *   @0x120294 ldr r0, [pc, #0x18]
 *   @0x120298 mov r1, r6
 *   @0x12029c str r6, [r5]
 *   @0x1202a0 str r6, [r5, #0x4]
 *   @0x1202a4 add r0, pc, r0
 *   @0x1202a8 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1202ac b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1202b0 eoreq sp, r12, r4, ror #13
 *   @0x1202b4 eoreq r9, r1, r8, asr pc
 *
 * ══ §109/212 F_TileGetXscale(RValue&, CInstance*, CInstance*, int, RValue*)  0x120348  size 140  35 条（0x120348..0x1203d4）
 * @func 0x120348 0x1203e4  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CRoom::FindTile(int) / F_TileGetXscale(RValue&, CInstance*, CInstance*, int, RValue*)+0x68
 * 字段偏移 top8: 0x18×2 / 0x74×1 / 0xc×1 / 0xb8×1 / 0x4×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x120348 push {r3, r4, r5, r6, r7, lr}
 *   @0x12034c mov r5, r0
 *   @0x120350 ldr r4, [pc, #0x74]
 *   @0x120354 mov r6, #0
 *   @0x120358 mov r1, r6
 *   @0x12035c ldr r0, [sp, #0x18]
 *   @0x120360 ldr r4, [pc, r4]
 *   @0x120364 str r6, [r5, #0xc]
 *   @0x120368 ldr r7, [r4]
 *   @0x12036c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x120370 mov r1, r0
 *   @0x120374 mov r0, r7
 *   @0x120378 bl 0x1af2bc <_ZN5CRoom8FindTileEi>
 *   @0x12037c cmp r0, #0
 *   @0x120380 blt 0x1203b0 <_Z15F_TileGetXscaleR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x120384 ldr r3, [r4]
 *   @0x120388 ldr r2, [r3, #0xb8]
 *   @0x12038c cmp r0, r2
 *   @0x120390 rsblt r0, r0, r0, lsl #3
 *   @0x120394 ldrlt r3, [r3, #0xc0]
 *   @0x120398 addlt r6, r3, r0, lsl #3
 *   @0x12039c vldr s15, [r6, #36]
 *   @0x1203a0 vcvt.f64.f32 d6, s15
 *   @0x1203a4 vmov r2, r3, d6
 *   @0x1203a8 stm r5, {r2, r3}
 *   @0x1203ac pop {r3, r4, r5, r6, r7, pc}
 *   @0x1203b0 ldr r0, [pc, #0x18]
 *   @0x1203b4 mov r1, r6
 *   @0x1203b8 str r6, [r5]
 *   @0x1203bc str r6, [r5, #0x4]
 *   @0x1203c0 add r0, pc, r0
 *   @0x1203c4 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1203c8 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1203cc eoreq sp, r12, r8, asr #11
 *   @0x1203d0 eoreq r9, r1, r12, lsr lr
 *
 * ══ §110/212 F_TileGetYscale(RValue&, CInstance*, CInstance*, int, RValue*)  0x1203d4  size 140  35 条（0x1203d4..0x120460）
 * @func 0x1203d4 0x120470  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CRoom::FindTile(int) / F_TileGetYscale(RValue&, CInstance*, CInstance*, int, RValue*)+0x68
 * 字段偏移 top8: 0x18×2 / 0x74×1 / 0xc×1 / 0xb8×1 / 0x4×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1203d4 push {r3, r4, r5, r6, r7, lr}
 *   @0x1203d8 mov r5, r0
 *   @0x1203dc ldr r4, [pc, #0x74]
 *   @0x1203e0 mov r6, #0
 *   @0x1203e4 mov r1, r6
 *   @0x1203e8 ldr r0, [sp, #0x18]
 *   @0x1203ec ldr r4, [pc, r4]
 *   @0x1203f0 str r6, [r5, #0xc]
 *   @0x1203f4 ldr r7, [r4]
 *   @0x1203f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1203fc mov r1, r0
 *   @0x120400 mov r0, r7
 *   @0x120404 bl 0x1af2bc <_ZN5CRoom8FindTileEi>
 *   @0x120408 cmp r0, #0
 *   @0x12040c blt 0x12043c <_Z15F_TileGetYscaleR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x120410 ldr r3, [r4]
 *   @0x120414 ldr r2, [r3, #0xb8]
 *   @0x120418 cmp r0, r2
 *   @0x12041c rsblt r0, r0, r0, lsl #3
 *   @0x120420 ldrlt r3, [r3, #0xc0]
 *   @0x120424 addlt r6, r3, r0, lsl #3
 *   @0x120428 vldr s15, [r6, #40]
 *   @0x12042c vcvt.f64.f32 d6, s15
 *   @0x120430 vmov r2, r3, d6
 *   @0x120434 stm r5, {r2, r3}
 *   @0x120438 pop {r3, r4, r5, r6, r7, pc}
 *   @0x12043c ldr r0, [pc, #0x18]
 *   @0x120440 mov r1, r6
 *   @0x120444 str r6, [r5]
 *   @0x120448 str r6, [r5, #0x4]
 *   @0x12044c add r0, pc, r0
 *   @0x120450 pop {r3, r4, r5, r6, r7, lr}
 *   @0x120454 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x120458 eoreq sp, r12, r12, lsr r5
 *   @0x12045c .word 0x00219db0
 *
 * ══ §111/212 F_TileGetAlpha(RValue&, CInstance*, CInstance*, int, RValue*)  0x1204f0  size 140  35 条（0x1204f0..0x12057c）
 * @func 0x1204f0 0x12058c  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CRoom::FindTile(int) / F_TileGetAlpha(RValue&, CInstance*, CInstance*, int, RValue*)+0x68
 * 字段偏移 top8: 0x18×2 / 0x74×1 / 0xc×1 / 0xb8×1 / 0x4×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1204f0 push {r3, r4, r5, r6, r7, lr}
 *   @0x1204f4 mov r5, r0
 *   @0x1204f8 ldr r4, [pc, #0x74]
 *   @0x1204fc mov r6, #0
 *   @0x120500 mov r1, r6
 *   @0x120504 ldr r0, [sp, #0x18]
 *   @0x120508 ldr r4, [pc, r4]
 *   @0x12050c str r6, [r5, #0xc]
 *   @0x120510 ldr r7, [r4]
 *   @0x120514 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x120518 mov r1, r0
 *   @0x12051c mov r0, r7
 *   @0x120520 bl 0x1af2bc <_ZN5CRoom8FindTileEi>
 *   @0x120524 cmp r0, #0
 *   @0x120528 blt 0x120558 <_Z14F_TileGetAlphaR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x12052c ldr r3, [r4]
 *   @0x120530 ldr r2, [r3, #0xb8]
 *   @0x120534 cmp r0, r2
 *   @0x120538 rsblt r0, r0, r0, lsl #3
 *   @0x12053c ldrlt r3, [r3, #0xc0]
 *   @0x120540 addlt r6, r3, r0, lsl #3
 *   @0x120544 vldr s15, [r6, #48]
 *   @0x120548 vcvt.f64.f32 d6, s15
 *   @0x12054c vmov r2, r3, d6
 *   @0x120550 stm r5, {r2, r3}
 *   @0x120554 pop {r3, r4, r5, r6, r7, pc}
 *   @0x120558 ldr r0, [pc, #0x18]
 *   @0x12055c mov r1, r6
 *   @0x120560 str r6, [r5]
 *   @0x120564 str r6, [r5, #0x4]
 *   @0x120568 add r0, pc, r0
 *   @0x12056c pop {r3, r4, r5, r6, r7, lr}
 *   @0x120570 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x120574 eoreq sp, r12, r0, lsr #8
 *   @0x120578 mlaeq r1, r4, r12, r9
 *
 * ══ §112/212 F_DrawTextExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x121e84  size 140  35 条（0x121e84..0x121f10）
 * @func 0x121e84 0x121f10  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / YYGetInt32(RValue const*, int)×2 / GetTextFromArg(RValue const*, int, char**) / GR_Text_Draw(float, float, char const*, int, int) / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0xc×2 / 0x28×1 / 0x-4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x121e84 push {r4, r5, r6, r7, r8, lr}
 *   @0x121e88 sub sp, sp, #16
 *   @0x121e8c add r2, sp, #16
 *   @0x121e90 mov r5, #0
 *   @0x121e94 ldr r4, [sp, #0x28]
 *   @0x121e98 mov r1, #1024
 *   @0x121e9c str r5, [r2, #-0x4]!
 *   @0x121ea0 add r0, r4, #32
 *   @0x121ea4 bl 0x121ce0 <_Z14GetTextFromArgPK6RValueiPPc>
 *   @0x121ea8 mov r1, r5
 *   @0x121eac mov r0, r4
 *   @0x121eb0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x121eb4 mov r1, #1
 *   @0x121eb8 mov r5, r0
 *   @0x121ebc mov r0, r4
 *   @0x121ec0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x121ec4 mov r1, #3
 *   @0x121ec8 ldr r7, [sp, #0xc]
 *   @0x121ecc mov r8, r0
 *   @0x121ed0 mov r0, r4
 *   @0x121ed4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x121ed8 mov r1, #4
 *   @0x121edc mov r6, r0
 *   @0x121ee0 mov r0, r4
 *   @0x121ee4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x121ee8 mov r1, r8
 *   @0x121eec mov r2, r7
 *   @0x121ef0 mov r3, r6
 *   @0x121ef4 str r0, [sp]
 *   @0x121ef8 mov r0, r5
 *   @0x121efc bl 0x172df8 <_Z12GR_Text_DrawffPKcii>
 *   @0x121f00 ldr r0, [sp, #0xc]
 *   @0x121f04 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x121f08 add sp, sp, #16
 *   @0x121f0c pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §113/212 YYGML_draw_text_transformed_color(float, float, char const*, float, float, float, int, int, int, int, float)  0x122528  size 140  35 条（0x122528..0x1225b4）
 * @func 0x122528 0x1225b4  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYStrDup(char const*) / GR_Text_Draw_Transformed_Color(float, float, char const*, int, int, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int, float)
 * 字段偏移 top8: 0x68×1 / 0x60×1 / 0x64×1 / 0x70×1 / 0x4×1 / 0x10×1 / 0x20×1 / 0x14×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x122528 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x12252c vpush {d8}
 *   @0x122530 sub sp, sp, #44
 *   @0x122534 vldr s17, [sp, #88]
 *   @0x122538 mov r8, r0
 *   @0x12253c mov r0, r2
 *   @0x122540 ldr r5, [sp, #0x68]
 *   @0x122544 mov r10, r3
 *   @0x122548 ldr r7, [sp, #0x60]
 *   @0x12254c mov r9, r1
 *   @0x122550 ldr r6, [sp, #0x64]
 *   @0x122554 vldr s16, [sp, #92]
 *   @0x122558 ldr r11, [sp, #0x70]
 *   @0x12255c bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x122560 mvn r12, #0
 *   @0x122564 str r10, [sp, #0x4]
 *   @0x122568 vstr s17, [sp, #8]
 *   @0x12256c vstr s16, [sp, #12]
 *   @0x122570 str r7, [sp, #0x10]
 *   @0x122574 mov r3, r12
 *   @0x122578 str r11, [sp, #0x20]
 *   @0x12257c mov r1, r9
 *   @0x122580 str r6, [sp, #0x14]
 *   @0x122584 str r5, [sp, #0x18]
 *   @0x122588 str r5, [sp, #0x1c]
 *   @0x12258c str r12, [sp]
 *   @0x122590 mov r4, r0
 *   @0x122594 mov r0, r8
 *   @0x122598 mov r2, r4
 *   @0x12259c bl 0x1735a0 <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf>
 *   @0x1225a0 mov r0, r4
 *   @0x1225a4 add sp, sp, #44
 *   @0x1225a8 vpop {d8}
 *   @0x1225ac pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1225b0 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *
 * ══ §114/212 F_PartParticlesCreateColor(RValue&, CInstance*, CInstance*, int, RValue*)  0x129b1c  size 140  35 条（0x129b1c..0x129ba8）
 * @func 0x129b1c 0x129ba8  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×4 / YYGetFloat(RValue const*, int)×2 / ParticleSystem_Particles_Create_Color(int, float, float, int, unsigned int, int)
 * 字段偏移 top8: 0x28×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x129b1c push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x129b20 sub sp, sp, #12
 *   @0x129b24 mov r1, #0
 *   @0x129b28 ldr r4, [sp, #0x28]
 *   @0x129b2c mov r0, r4
 *   @0x129b30 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129b34 mov r1, #1
 *   @0x129b38 mov r5, r0
 *   @0x129b3c mov r0, r4
 *   @0x129b40 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x129b44 mov r1, #2
 *   @0x129b48 mov r8, r0
 *   @0x129b4c mov r0, r4
 *   @0x129b50 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x129b54 mov r1, #3
 *   @0x129b58 mov r6, r0
 *   @0x129b5c mov r0, r4
 *   @0x129b60 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129b64 mov r1, #4
 *   @0x129b68 mov r7, r0
 *   @0x129b6c mov r0, r4
 *   @0x129b70 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129b74 mov r1, #5
 *   @0x129b78 mov r9, r0
 *   @0x129b7c mov r0, r4
 *   @0x129b80 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129b84 str r9, [sp]
 *   @0x129b88 mov r1, r8
 *   @0x129b8c mov r3, r7
 *   @0x129b90 mov r2, r6
 *   @0x129b94 str r0, [sp, #0x4]
 *   @0x129b98 mov r0, r5
 *   @0x129b9c bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji>
 *   @0x129ba0 add sp, sp, #12
 *   @0x129ba4 pop {r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §115/212 F_ObjectSetSolid(RValue&, CInstance*, CInstance*, int, RValue*)  0x12bd88  size 140  35 条（0x12bd88..0x12be14）
 * @func 0x12bd88 0x12be24  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x4×2 / 0x10×1 / 0x6c×1 / 0x3×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12bd88 push {r3, r4, r5, lr}
 *   @0x12bd8c mov r1, #0
 *   @0x12bd90 ldr r4, [sp, #0x10]
 *   @0x12bd94 mov r0, r4
 *   @0x12bd98 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12bd9c ldr r3, [pc, #0x6c]
 *   @0x12bda0 ldr r3, [pc, r3]
 *   @0x12bda4 ldr r3, [r3]
 *   @0x12bda8 ldr r2, [r3, #0x4]
 *   @0x12bdac ldr r3, [r3]
 *   @0x12bdb0 and r2, r0, r2
 *   @0x12bdb4 ldr r3, [r3, r2, lsl #3]
 *   @0x12bdb8 cmp r3, #0
 *   @0x12bdbc bne 0x12bdd0 <_Z16F_ObjectSetSolidR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x12bdc0 pop {r3, r4, r5, pc}
 *   @0x12bdc4 ldr r3, [r3, #0x4]
 *   @0x12bdc8 cmp r3, #0
 *   @0x12bdcc beq 0x12be0c <_Z16F_ObjectSetSolidR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x12bdd0 ldr r2, [r3, #0x8]
 *   @0x12bdd4 cmp r0, r2
 *   @0x12bdd8 bne 0x12bdc4 <_Z16F_ObjectSetSolidR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x12bddc ldr r5, [r3, #0xc]
 *   @0x12bde0 cmp r5, #0
 *   @0x12bde4 popeq {r3, r4, r5, pc}
 *   @0x12bde8 mov r0, r4
 *   @0x12bdec mov r1, #1
 *   @0x12bdf0 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x12bdf4 ldr r3, [r5]
 *   @0x12bdf8 cmp r0, #0
 *   @0x12bdfc orrne r3, r3, #1
 *   @0x12be00 biceq r3, r3, #1
 *   @0x12be04 str r3, [r5]
 *   @0x12be08 pop {r3, r4, r5, pc}
 *   @0x12be0c pop {r3, r4, r5, pc}
 *   @0x12be10 mlaeq r12, r12, lr, r1
 *
 * ══ §116/212 F_ObjectSetVisible(RValue&, CInstance*, CInstance*, int, RValue*)  0x12be14  size 140  35 条（0x12be14..0x12bea0）
 * @func 0x12be14 0x12beb0  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x4×2 / 0x10×1 / 0x6c×1 / 0x3×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12be14 push {r3, r4, r5, lr}
 *   @0x12be18 mov r1, #0
 *   @0x12be1c ldr r4, [sp, #0x10]
 *   @0x12be20 mov r0, r4
 *   @0x12be24 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12be28 ldr r3, [pc, #0x6c]
 *   @0x12be2c ldr r3, [pc, r3]
 *   @0x12be30 ldr r3, [r3]
 *   @0x12be34 ldr r2, [r3, #0x4]
 *   @0x12be38 ldr r3, [r3]
 *   @0x12be3c and r2, r0, r2
 *   @0x12be40 ldr r3, [r3, r2, lsl #3]
 *   @0x12be44 cmp r3, #0
 *   @0x12be48 bne 0x12be5c <_Z18F_ObjectSetVisibleR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x12be4c pop {r3, r4, r5, pc}
 *   @0x12be50 ldr r3, [r3, #0x4]
 *   @0x12be54 cmp r3, #0
 *   @0x12be58 beq 0x12be98 <_Z18F_ObjectSetVisibleR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x12be5c ldr r2, [r3, #0x8]
 *   @0x12be60 cmp r0, r2
 *   @0x12be64 bne 0x12be50 <_Z18F_ObjectSetVisibleR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x12be68 ldr r5, [r3, #0xc]
 *   @0x12be6c cmp r5, #0
 *   @0x12be70 popeq {r3, r4, r5, pc}
 *   @0x12be74 mov r0, r4
 *   @0x12be78 mov r1, #1
 *   @0x12be7c bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x12be80 ldr r3, [r5]
 *   @0x12be84 cmp r0, #0
 *   @0x12be88 orrne r3, r3, #2
 *   @0x12be8c biceq r3, r3, #2
 *   @0x12be90 str r3, [r5]
 *   @0x12be94 pop {r3, r4, r5, pc}
 *   @0x12be98 pop {r3, r4, r5, pc}
 *   @0x12be9c eoreq r1, r12, r0, lsl lr
 *
 * ══ §117/212 F_ObjectSetPersistent(RValue&, CInstance*, CInstance*, int, RValue*)  0x12bea0  size 140  35 条（0x12bea0..0x12bf2c）
 * @func 0x12bea0 0x12bf3c  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x4×2 / 0x10×1 / 0x6c×1 / 0x3×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12bea0 push {r3, r4, r5, lr}
 *   @0x12bea4 mov r1, #0
 *   @0x12bea8 ldr r4, [sp, #0x10]
 *   @0x12beac mov r0, r4
 *   @0x12beb0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12beb4 ldr r3, [pc, #0x6c]
 *   @0x12beb8 ldr r3, [pc, r3]
 *   @0x12bebc ldr r3, [r3]
 *   @0x12bec0 ldr r2, [r3, #0x4]
 *   @0x12bec4 ldr r3, [r3]
 *   @0x12bec8 and r2, r0, r2
 *   @0x12becc ldr r3, [r3, r2, lsl #3]
 *   @0x12bed0 cmp r3, #0
 *   @0x12bed4 bne 0x12bee8 <_Z21F_ObjectSetPersistentR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x12bed8 pop {r3, r4, r5, pc}
 *   @0x12bedc ldr r3, [r3, #0x4]
 *   @0x12bee0 cmp r3, #0
 *   @0x12bee4 beq 0x12bf24 <_Z21F_ObjectSetPersistentR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x12bee8 ldr r2, [r3, #0x8]
 *   @0x12beec cmp r0, r2
 *   @0x12bef0 bne 0x12bedc <_Z21F_ObjectSetPersistentR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x12bef4 ldr r5, [r3, #0xc]
 *   @0x12bef8 cmp r5, #0
 *   @0x12befc popeq {r3, r4, r5, pc}
 *   @0x12bf00 mov r0, r4
 *   @0x12bf04 mov r1, #1
 *   @0x12bf08 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x12bf0c ldr r3, [r5]
 *   @0x12bf10 cmp r0, #0
 *   @0x12bf14 orrne r3, r3, #4
 *   @0x12bf18 biceq r3, r3, #4
 *   @0x12bf1c str r3, [r5]
 *   @0x12bf20 pop {r3, r4, r5, pc}
 *   @0x12bf24 pop {r3, r4, r5, pc}
 *   @0x12bf28 eoreq r1, r12, r4, lsl #27
 *
 * ══ §118/212 F_ObjectSetCollisions(RValue&, CInstance*, CInstance*, int, RValue*)  0x12bf2c  size 140  35 条（0x12bf2c..0x12bfb8）
 * @func 0x12bf2c 0x12bfb8  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x4×2 / 0x10×1 / 0x6c×1 / 0x3×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12bf2c push {r3, r4, r5, lr}
 *   @0x12bf30 mov r1, #0
 *   @0x12bf34 ldr r4, [sp, #0x10]
 *   @0x12bf38 mov r0, r4
 *   @0x12bf3c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12bf40 ldr r3, [pc, #0x6c]
 *   @0x12bf44 ldr r3, [pc, r3]
 *   @0x12bf48 ldr r3, [r3]
 *   @0x12bf4c ldr r2, [r3, #0x4]
 *   @0x12bf50 ldr r3, [r3]
 *   @0x12bf54 and r2, r0, r2
 *   @0x12bf58 ldr r3, [r3, r2, lsl #3]
 *   @0x12bf5c cmp r3, #0
 *   @0x12bf60 bne 0x12bf74 <_Z21F_ObjectSetCollisionsR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x12bf64 pop {r3, r4, r5, pc}
 *   @0x12bf68 ldr r3, [r3, #0x4]
 *   @0x12bf6c cmp r3, #0
 *   @0x12bf70 beq 0x12bfb0 <_Z21F_ObjectSetCollisionsR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x12bf74 ldr r2, [r3, #0x8]
 *   @0x12bf78 cmp r0, r2
 *   @0x12bf7c bne 0x12bf68 <_Z21F_ObjectSetCollisionsR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x12bf80 ldr r5, [r3, #0xc]
 *   @0x12bf84 cmp r5, #0
 *   @0x12bf88 popeq {r3, r4, r5, pc}
 *   @0x12bf8c mov r0, r4
 *   @0x12bf90 mov r1, #1
 *   @0x12bf94 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x12bf98 ldr r3, [r5]
 *   @0x12bf9c cmp r0, #0
 *   @0x12bfa0 orrne r3, r3, #16
 *   @0x12bfa4 biceq r3, r3, #16
 *   @0x12bfa8 str r3, [r5]
 *   @0x12bfac pop {r3, r4, r5, pc}
 *   @0x12bfb0 pop {r3, r4, r5, pc}
 *   @0x12bfb4 .word 0x002c1cf8
 *
 * ══ §119/212 F_BackgroundAdd(RValue&, CInstance*, CInstance*, int, RValue*)  0x12c82c  size 140  35 条（0x12c82c..0x12c8b8）
 * @func 0x12c82c 0x12c8b8  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetBool(RValue const*, int)×3 / YYGetString(RValue const*, int) / Background_Add(char const*, bool, bool, bool)
 * 字段偏移 top8: 0x20×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12c82c push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x12c830 mov r1, #0
 *   @0x12c834 ldr r4, [sp, #0x20]
 *   @0x12c838 mov r5, r0
 *   @0x12c83c str r1, [r0, #0xc]
 *   @0x12c840 mov r9, r3
 *   @0x12c844 mov r0, r4
 *   @0x12c848 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x12c84c mov r1, #1
 *   @0x12c850 mov r7, r0
 *   @0x12c854 mov r0, r4
 *   @0x12c858 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x12c85c mov r1, #2
 *   @0x12c860 mov r6, r0
 *   @0x12c864 mov r0, r4
 *   @0x12c868 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x12c86c cmp r9, #3
 *   @0x12c870 moveq r3, #1
 *   @0x12c874 mov r8, r0
 *   @0x12c878 beq 0x12c88c <_Z15F_BackgroundAddR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0x12c87c mov r0, r4
 *   @0x12c880 mov r1, #3
 *   @0x12c884 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x12c888 mov r3, r0
 *   @0x12c88c mov r1, r6
 *   @0x12c890 mov r2, r8
 *   @0x12c894 mov r0, r7
 *   @0x12c898 bl 0xc38d4 <_Z14Background_AddPKcbbb>
 *   @0x12c89c vmov s15, r0
 *   @0x12c8a0 vcvt.f64.s32 d7, s15
 *   @0x12c8a4 vmov r0, r1, d7
 *   @0x12c8a8 vmov r2, s14
 *   @0x12c8ac mov r3, r1
 *   @0x12c8b0 stm r5, {r2, r3}
 *   @0x12c8b4 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §120/212 F_FileTextWriteString(RValue&, CInstance*, CInstance*, int, RValue*)  0x1381c0  size 140  35 条（0x1381c0..0x13824c）
 * @func 0x1381c0 0x13824c  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGetString(RValue const*, int)
 * 字段偏移 top8: 0x10×1 / 0x48×1 / 0x2×1 / 0x38×1 / 0x20×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1381c0 push {r3, r4, r5, lr}
 *   @0x1381c4 mov r1, #0
 *   @0x1381c8 ldr r5, [sp, #0x10]
 *   @0x1381cc mov r0, r5
 *   @0x1381d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1381d4 mov r1, #1
 *   @0x1381d8 mov r4, r0
 *   @0x1381dc mov r0, r5
 *   @0x1381e0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1381e4 sub r3, r4, #1
 *   @0x1381e8 cmp r3, #30
 *   @0x1381ec bhi 0x138204 <_Z21F_FileTextWriteStringR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x1381f0 ldr r3, [pc, #0x48]
 *   @0x1381f4 ldr r3, [pc, r3]
 *   @0x1381f8 ldr r3, [r3, r4, lsl #2]
 *   @0x1381fc cmp r3, #2
 *   @0x138200 beq 0x138218 <_Z21F_FileTextWriteStringR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x138204 ldr r0, [pc, #0x38]
 *   @0x138208 mov r1, #0
 *   @0x13820c pop {r3, r4, r5, lr}
 *   @0x138210 add r0, pc, r0
 *   @0x138214 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x138218 cmp r0, #0
 *   @0x13821c popeq {r3, r4, r5, pc}
 *   @0x138220 ldr r3, [pc, #0x20]
 *   @0x138224 add r4, r4, r4, lsl #1
 *   @0x138228 mov r1, r0
 *   @0x13822c ldr r3, [pc, r3]
 *   @0x138230 add r3, r3, r4, lsl #2
 *   @0x138234 ldr r0, [r3, #0x8]
 *   @0x138238 pop {r3, r4, r5, lr}
 *   @0x13823c b 0x18e114 <_ZN8LoadSave5fputsEP7_YYFILEPKc>
 *   @0x138240 eoreq r7, r11, r12, ror r0
 *   @0x138244 eoreq r7, r0, r12, ror lr
 *   @0x138248 eoreq r7, r11, r8, asr #32
 *
 * ══ §121/212 F_FileBinClose(RValue&, CInstance*, CInstance*, int, RValue*)  0x1392d4  size 140  35 条（0x1392d4..0x139360）
 * @func 0x1392d4 0x139360  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / LoadSave::fclose(_YYFILE*) / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x8×2 / 0x20×1 / 0x58×1 / 0x44×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1392d4 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x1392d8 mov r1, #0
 *   @0x1392dc ldr r0, [sp, #0x20]
 *   @0x1392e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1392e4 sub r3, r0, #1
 *   @0x1392e8 mov r4, r0
 *   @0x1392ec cmp r3, #30
 *   @0x1392f0 bhi 0x139340 <_Z14F_FileBinCloseR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x1392f4 ldr r5, [pc, #0x58]
 *   @0x1392f8 ldr r5, [pc, r5]
 *   @0x1392fc ldrb r3, [r5, r0]
 *   @0x139300 cmp r3, #0
 *   @0x139304 beq 0x139340 <_Z14F_FileBinCloseR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x139308 add r8, r0, r0, lsl #1
 *   @0x13930c ldr r6, [pc, #0x44]
 *   @0x139310 mov r7, #0
 *   @0x139314 ldr r6, [pc, r6]
 *   @0x139318 lsl r8, r8, #2
 *   @0x13931c add r9, r8, r6
 *   @0x139320 ldr r0, [r9, #0x8]
 *   @0x139324 bl 0x18ddb8 <_ZN8LoadSave6fcloseEP7_YYFILE>
 *   @0x139328 str r7, [r9, #0x8]
 *   @0x13932c ldr r0, [r6, r8]
 *   @0x139330 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x139334 str r7, [r8, r6]
 *   @0x139338 strb r7, [r5, r4]
 *   @0x13933c pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x139340 ldr r0, [pc, #0x14]
 *   @0x139344 mov r1, #0
 *   @0x139348 pop {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x13934c add r0, pc, r0
 *   @0x139350 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x139354 mlaeq r11, r4, pc, r5
 *   @0x139358 eoreq r5, r11, r12, ror pc
 *   @0x13935c .word 0x00206db8
 *
 * ══ §122/212 F_IniKeyExists(RValue&, CInstance*, CInstance*, int, RValue*)  0x13a058  size 140  35 条（0x13a058..0x13a0e4）
 * @func 0x13a058 0x13a0e4  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)×2 / IniFile::GetKey(char const*, char const*)
 * 字段偏移 top8: 0xc×2 / 0x10×1 / 0x54×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13a058 push {r4, r5, r6, lr}
 *   @0x13a05c mov r1, #0
 *   @0x13a060 ldr r5, [sp, #0x10]
 *   @0x13a064 mov r4, r0
 *   @0x13a068 mov r0, r5
 *   @0x13a06c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x13a070 mov r1, #1
 *   @0x13a074 mov r6, r0
 *   @0x13a078 mov r0, r5
 *   @0x13a07c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x13a080 ldr r3, [pc, #0x54]
 *   @0x13a084 ldr r3, [pc, r3]
 *   @0x13a088 mov r2, r0
 *   @0x13a08c ldr r0, [r3]
 *   @0x13a090 cmp r0, #0
 *   @0x13a094 beq 0x13a0c8 <_Z14F_IniKeyExistsR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x13a098 mov r1, r6
 *   @0x13a09c bl 0x235ad0 <_ZN7IniFile6GetKeyEPKcS1_>
 *   @0x13a0a0 mov r3, #0
 *   @0x13a0a4 str r3, [r4, #0xc]
 *   @0x13a0a8 cmp r0, #0
 *   @0x13a0ac moveq r3, r0
 *   @0x13a0b0 movne r2, r3
 *   @0x13a0b4 moveq r2, r3
 *   @0x13a0b8 movtne r2, #0x3ff0
 *   @0x13a0bc str r3, [r4]
 *   @0x13a0c0 str r2, [r4, #0x4]
 *   @0x13a0c4 pop {r4, r5, r6, pc}
 *   @0x13a0c8 mov r1, r0
 *   @0x13a0cc ldr r0, [pc, #0xc]
 *   @0x13a0d0 pop {r4, r5, r6, lr}
 *   @0x13a0d4 add r0, pc, r0
 *   @0x13a0d8 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x13a0dc eoreq r5, r11, r0, lsl r2
 *   @0x13a0e0 mlaeq r0, r4, r1, r6
 *
 * ══ §123/212 JSONToDSList(char*, char*, int)  0x13d2bc  size 140  35 条（0x13d2bc..0x13d348）
 * @func 0x13d2bc 0x13d348  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: json_tokener_parse / json_object_object_get / json_object_array_length / JSONToDSList(char*, char*, int)+0x5c / JSONToDSList(char*, char*, int)+0x6c / json_parse_array_to_list(json_object*, char*, CDS_List*) / json_object_put / json_parse_array(json_object*, char*)
 * 字段偏移 top8: 0x44×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13d2bc push {r4, r5, r6, lr}
 *   @0x13d2c0 mov r5, r1
 *   @0x13d2c4 mov r6, r2
 *   @0x13d2c8 bl 0x28075c <json_tokener_parse>
 *   @0x13d2cc cmn r0, #4000
 *   @0x13d2d0 mov r4, r0
 *   @0x13d2d4 bhi 0x13d33c <_Z12JSONToDSListPcS_i+0x80>
 *   @0x13d2d8 mov r1, r5
 *   @0x13d2dc bl 0x27ea38 <json_object_object_get>
 *   @0x13d2e0 bl 0x27ede8 <json_object_array_length>
 *   @0x13d2e4 cmp r0, #0
 *   @0x13d2e8 mvnle r5, #0
 *   @0x13d2ec ble 0x13d318 <_Z12JSONToDSListPcS_i+0x5c>
 *   @0x13d2f0 cmp r6, #0
 *   @0x13d2f4 blt 0x13d328 <_Z12JSONToDSListPcS_i+0x6c>
 *   @0x13d2f8 ldr r3, [pc, #0x44]
 *   @0x13d2fc mov r1, r5
 *   @0x13d300 mov r0, r4
 *   @0x13d304 mvn r5, #0
 *   @0x13d308 ldr r3, [pc, r3]
 *   @0x13d30c ldr r3, [r3, #0x4]
 *   @0x13d310 ldr r2, [r3, r6, lsl #2]
 *   @0x13d314 bl 0x13d140 <_Z24json_parse_array_to_listP11json_objectPcP8CDS_List>
 *   @0x13d318 mov r0, r4
 *   @0x13d31c bl 0x27e7c8 <json_object_put>
 *   @0x13d320 mov r0, r5
 *   @0x13d324 pop {r4, r5, r6, pc}
 *   @0x13d328 mov r1, r5
 *   @0x13d32c mov r0, r4
 *   @0x13d330 bl 0x13d274 <_Z16json_parse_arrayP11json_objectPc>
 *   @0x13d334 mov r5, r0
 *   @0x13d338 b 0x13d318 <_Z12JSONToDSListPcS_i+0x5c>
 *   @0x13d33c mvn r5, #0
 *   @0x13d340 b 0x13d320 <_Z12JSONToDSListPcS_i+0x64>
 *   @0x13d344 eoreq r0, r11, r8, ror r9
 *
 * ══ §124/212 F_ActionSetAlarm(RValue&, CInstance*, CInstance*, int, RValue*)  0x13e76c  size 140  35 条（0x13e76c..0x13e7f8）
 * @func 0x13e76c 0x13e7f8  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / CInstance::GetTimer(int)×2 / F_ActionSetAlarm(RValue&, CInstance*, CInstance*, int, RValue*)+0x40
 * 字段偏移 top8: 0x10×1 / 0x58×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13e76c push {r4, r5, r6, lr}
 *   @0x13e770 mov r6, r1
 *   @0x13e774 ldr r4, [sp, #0x10]
 *   @0x13e778 mov r1, #1
 *   @0x13e77c mov r0, r4
 *   @0x13e780 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13e784 mov r1, #0
 *   @0x13e788 mov r5, r0
 *   @0x13e78c mov r0, r4
 *   @0x13e790 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13e794 ldr r3, [pc, #0x58]
 *   @0x13e798 ldr r3, [pc, r3]
 *   @0x13e79c ldrb r3, [r3]
 *   @0x13e7a0 cmp r3, #0
 *   @0x13e7a4 mov r4, r0
 *   @0x13e7a8 bne 0x13e7c0 <_Z16F_ActionSetAlarmR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x13e7ac mov r0, r6
 *   @0x13e7b0 mov r1, r5
 *   @0x13e7b4 mov r2, r4
 *   @0x13e7b8 pop {r4, r5, r6, lr}
 *   @0x13e7bc b 0x193148 <_ZN9CInstance8SetTimerEii>
 *   @0x13e7c0 mov r0, r6
 *   @0x13e7c4 mov r1, r5
 *   @0x13e7c8 bl 0x193134 <_ZN9CInstance8GetTimerEi>
 *   @0x13e7cc cmp r0, #0
 *   @0x13e7d0 blt 0x13e7ac <_Z16F_ActionSetAlarmR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x13e7d4 mov r1, r5
 *   @0x13e7d8 mov r0, r6
 *   @0x13e7dc bl 0x193134 <_ZN9CInstance8GetTimerEi>
 *   @0x13e7e0 mov r1, r5
 *   @0x13e7e4 add r2, r0, r4
 *   @0x13e7e8 mov r0, r6
 *   @0x13e7ec pop {r4, r5, r6, lr}
 *   @0x13e7f0 b 0x193148 <_ZN9CInstance8SetTimerEii>
 *   @0x13e7f4 eoreq pc, r10, r4, lsr #7
 *
 * ══ §125/212 F_D3DVertexNormal(RValue&, CInstance*, CInstance*, int, RValue*)  0x143e54  size 140  35 条（0x143e54..0x143ee0）
 * @func 0x143e54 0x143ee0  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×6 / GR_3D_Vertex_N(float, float, float, float, float, float)
 * 字段偏移 top8: 0x28×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x143e54 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x143e58 sub sp, sp, #12
 *   @0x143e5c mov r1, #0
 *   @0x143e60 ldr r4, [sp, #0x28]
 *   @0x143e64 mov r0, r4
 *   @0x143e68 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x143e6c mov r1, #1
 *   @0x143e70 mov r5, r0
 *   @0x143e74 mov r0, r4
 *   @0x143e78 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x143e7c mov r1, #2
 *   @0x143e80 mov r8, r0
 *   @0x143e84 mov r0, r4
 *   @0x143e88 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x143e8c mov r1, #3
 *   @0x143e90 mov r7, r0
 *   @0x143e94 mov r0, r4
 *   @0x143e98 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x143e9c mov r1, #4
 *   @0x143ea0 mov r6, r0
 *   @0x143ea4 mov r0, r4
 *   @0x143ea8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x143eac mov r1, #5
 *   @0x143eb0 mov r9, r0
 *   @0x143eb4 mov r0, r4
 *   @0x143eb8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x143ebc str r9, [sp]
 *   @0x143ec0 mov r1, r8
 *   @0x143ec4 mov r2, r7
 *   @0x143ec8 mov r3, r6
 *   @0x143ecc str r0, [sp, #0x4]
 *   @0x143ed0 mov r0, r5
 *   @0x143ed4 bl 0x177214 <_Z14GR_3D_Vertex_Nffffff>
 *   @0x143ed8 add sp, sp, #12
 *   @0x143edc pop {r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §126/212 F_D3DModelVertexColor(RValue&, CInstance*, CInstance*, int, RValue*)  0x145558  size 140  35 条（0x145558..0x1455e4）
 * @func 0x145558 0x1455f4  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×4 / YYGetInt32(RValue const*, int)×2 / GR_3DM_Vertex_Color(int, float, float, float, unsigned int, float)
 * 字段偏移 top8: 0x28×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x145558 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x14555c sub sp, sp, #12
 *   @0x145560 mov r1, #0
 *   @0x145564 ldr r4, [sp, #0x28]
 *   @0x145568 mov r0, r4
 *   @0x14556c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x145570 mov r1, #1
 *   @0x145574 mov r5, r0
 *   @0x145578 mov r0, r4
 *   @0x14557c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145580 mov r1, #2
 *   @0x145584 mov r8, r0
 *   @0x145588 mov r0, r4
 *   @0x14558c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145590 mov r1, #3
 *   @0x145594 mov r7, r0
 *   @0x145598 mov r0, r4
 *   @0x14559c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1455a0 mov r1, #4
 *   @0x1455a4 mov r6, r0
 *   @0x1455a8 mov r0, r4
 *   @0x1455ac bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1455b0 mov r1, #5
 *   @0x1455b4 mov r9, r0
 *   @0x1455b8 mov r0, r4
 *   @0x1455bc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1455c0 str r9, [sp]
 *   @0x1455c4 mov r1, r8
 *   @0x1455c8 mov r2, r7
 *   @0x1455cc mov r3, r6
 *   @0x1455d0 str r0, [sp, #0x4]
 *   @0x1455d4 mov r0, r5
 *   @0x1455d8 bl 0x1654c8 <_Z19GR_3DM_Vertex_Colorifffjf>
 *   @0x1455dc add sp, sp, #12
 *   @0x1455e0 pop {r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §127/212 F_D3DModelVertexTexture(RValue&, CInstance*, CInstance*, int, RValue*)  0x1455e4  size 140  35 条（0x1455e4..0x145670）
 * @func 0x1455e4 0x145670  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×5 / YYGetInt32(RValue const*, int) / GR_3DM_Vertex_Texture(int, float, float, float, float, float)
 * 字段偏移 top8: 0x28×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1455e4 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x1455e8 sub sp, sp, #12
 *   @0x1455ec mov r1, #0
 *   @0x1455f0 ldr r4, [sp, #0x28]
 *   @0x1455f4 mov r0, r4
 *   @0x1455f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1455fc mov r1, #1
 *   @0x145600 mov r5, r0
 *   @0x145604 mov r0, r4
 *   @0x145608 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14560c mov r1, #2
 *   @0x145610 mov r8, r0
 *   @0x145614 mov r0, r4
 *   @0x145618 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14561c mov r1, #3
 *   @0x145620 mov r7, r0
 *   @0x145624 mov r0, r4
 *   @0x145628 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14562c mov r1, #4
 *   @0x145630 mov r6, r0
 *   @0x145634 mov r0, r4
 *   @0x145638 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14563c mov r1, #5
 *   @0x145640 mov r9, r0
 *   @0x145644 mov r0, r4
 *   @0x145648 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14564c str r9, [sp]
 *   @0x145650 mov r1, r8
 *   @0x145654 mov r2, r7
 *   @0x145658 mov r3, r6
 *   @0x14565c str r0, [sp, #0x4]
 *   @0x145660 mov r0, r5
 *   @0x145664 bl 0x165554 <_Z21GR_3DM_Vertex_Textureifffff>
 *   @0x145668 add sp, sp, #12
 *   @0x14566c pop {r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §128/212 F_PhysicsGetParticleGroupFlags(RValue&, CInstance*, CInstance*, int, RValue*)  0x14d7b0  size 140  35 条（0x14d7b0..0x14d83c）
 * @func 0x14d7b0 0x14d83c  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CPhysicsWorld::GetParticleGroupFlags(int)
 * 字段偏移 top8: 0x10×2 / 0x74×1 / 0xc×1 / 0x4×1 / 0xb4×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14d7b0 push {r3, r4, r5, lr}
 *   @0x14d7b4 mov r1, #0
 *   @0x14d7b8 ldr r3, [pc, #0x74]
 *   @0x14d7bc mov r4, r0
 *   @0x14d7c0 str r1, [r0]
 *   @0x14d7c4 mov r2, r1
 *   @0x14d7c8 ldr r3, [pc, r3]
 *   @0x14d7cc str r1, [r0, #0xc]
 *   @0x14d7d0 movt r2, #0xbff0
 *   @0x14d7d4 str r2, [r0, #0x4]
 *   @0x14d7d8 ldr r3, [r3]
 *   @0x14d7dc ldr r0, [sp, #0x10]
 *   @0x14d7e0 cmp r3, r1
 *   @0x14d7e4 beq 0x14d820 <_Z30F_PhysicsGetParticleGroupFlagsR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x14d7e8 ldr r5, [r3, #0xb4]
 *   @0x14d7ec cmp r5, r1
 *   @0x14d7f0 beq 0x14d820 <_Z30F_PhysicsGetParticleGroupFlagsR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x14d7f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14d7f8 mov r1, r0
 *   @0x14d7fc mov r0, r5
 *   @0x14d800 bl 0x23a230 <_ZN13CPhysicsWorld21GetParticleGroupFlagsEi>
 *   @0x14d804 vmov s15, r0
 *   @0x14d808 vcvt.f64.s32 d7, s15
 *   @0x14d80c vmov r0, r1, d7
 *   @0x14d810 vmov r2, s14
 *   @0x14d814 mov r3, r1
 *   @0x14d818 stm r4, {r2, r3}
 *   @0x14d81c pop {r3, r4, r5, pc}
 *   @0x14d820 ldr r0, [pc, #0x10]
 *   @0x14d824 mov r1, #0
 *   @0x14d828 pop {r3, r4, r5, lr}
 *   @0x14d82c add r0, pc, r0
 *   @0x14d830 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14d834 eoreq r0, r10, r0, ror #2
 *   @0x14d838 andseq r6, pc, r12, ror #14
 *
 * ══ §129/212 F_PhysicsParticleGroupCount(RValue&, CInstance*, CInstance*, int, RValue*)  0x14e04c  size 140  35 条（0x14e04c..0x14e0d8）
 * @func 0x14e04c 0x14e0d8  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CPhysicsWorld::GetParticleGroupCount(int)
 * 字段偏移 top8: 0x10×2 / 0x74×1 / 0xc×1 / 0x4×1 / 0xb4×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14e04c push {r3, r4, r5, lr}
 *   @0x14e050 mov r1, #0
 *   @0x14e054 ldr r3, [pc, #0x74]
 *   @0x14e058 mov r4, r0
 *   @0x14e05c str r1, [r0]
 *   @0x14e060 mov r2, r1
 *   @0x14e064 ldr r3, [pc, r3]
 *   @0x14e068 str r1, [r0, #0xc]
 *   @0x14e06c movt r2, #0xbff0
 *   @0x14e070 str r2, [r0, #0x4]
 *   @0x14e074 ldr r3, [r3]
 *   @0x14e078 ldr r0, [sp, #0x10]
 *   @0x14e07c cmp r3, r1
 *   @0x14e080 beq 0x14e0bc <_Z27F_PhysicsParticleGroupCountR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x14e084 ldr r5, [r3, #0xb4]
 *   @0x14e088 cmp r5, r1
 *   @0x14e08c beq 0x14e0bc <_Z27F_PhysicsParticleGroupCountR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x14e090 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14e094 mov r1, r0
 *   @0x14e098 mov r0, r5
 *   @0x14e09c bl 0x23a5d4 <_ZN13CPhysicsWorld21GetParticleGroupCountEi>
 *   @0x14e0a0 vmov s15, r0
 *   @0x14e0a4 vcvt.f64.s32 d7, s15
 *   @0x14e0a8 vmov r0, r1, d7
 *   @0x14e0ac vmov r2, s14
 *   @0x14e0b0 mov r3, r1
 *   @0x14e0b4 stm r4, {r2, r3}
 *   @0x14e0b8 pop {r3, r4, r5, pc}
 *   @0x14e0bc ldr r0, [pc, #0x10]
 *   @0x14e0c0 mov r1, #0
 *   @0x14e0c4 pop {r3, r4, r5, lr}
 *   @0x14e0c8 add r0, pc, r0
 *   @0x14e0cc b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14e0d0 eoreq pc, r9, r4, asr #17
 *   @0x14e0d4 andseq r6, pc, r4, asr r5
 *
 * ══ §130/212 F_PhysicsParticleGroupMass(RValue&, CInstance*, CInstance*, int, RValue*)  0x14e1a0  size 140  35 条（0x14e1a0..0x14e22c）
 * @func 0x14e1a0 0x14e23c  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CPhysicsWorld::GetParticleGroupMass(int)
 * 字段偏移 top8: 0x10×2 / 0x74×1 / 0xc×1 / 0x4×1 / 0xb4×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14e1a0 push {r3, r4, r5, lr}
 *   @0x14e1a4 mov r1, #0
 *   @0x14e1a8 ldr r3, [pc, #0x74]
 *   @0x14e1ac mov r4, r0
 *   @0x14e1b0 str r1, [r0]
 *   @0x14e1b4 mov r2, r1
 *   @0x14e1b8 ldr r3, [pc, r3]
 *   @0x14e1bc str r1, [r0, #0xc]
 *   @0x14e1c0 movt r2, #0xbff0
 *   @0x14e1c4 str r2, [r0, #0x4]
 *   @0x14e1c8 ldr r3, [r3]
 *   @0x14e1cc ldr r0, [sp, #0x10]
 *   @0x14e1d0 cmp r3, r1
 *   @0x14e1d4 beq 0x14e210 <_Z26F_PhysicsParticleGroupMassR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x14e1d8 ldr r5, [r3, #0xb4]
 *   @0x14e1dc cmp r5, r1
 *   @0x14e1e0 beq 0x14e210 <_Z26F_PhysicsParticleGroupMassR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x14e1e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14e1e8 mov r1, r0
 *   @0x14e1ec mov r0, r5
 *   @0x14e1f0 bl 0x23a648 <_ZN13CPhysicsWorld20GetParticleGroupMassEi>
 *   @0x14e1f4 vmov s15, r0
 *   @0x14e1f8 vcvt.f64.f32 d7, s15
 *   @0x14e1fc vmov r0, r1, d7
 *   @0x14e200 vmov r2, s14
 *   @0x14e204 mov r3, r1
 *   @0x14e208 stm r4, {r2, r3}
 *   @0x14e20c pop {r3, r4, r5, pc}
 *   @0x14e210 ldr r0, [pc, #0x10]
 *   @0x14e214 mov r1, #0
 *   @0x14e218 pop {r3, r4, r5, lr}
 *   @0x14e21c add r0, pc, r0
 *   @0x14e220 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14e224 eoreq pc, r9, r0, ror r7
 *   @0x14e228 andseq r6, pc, r0, asr #9
 *
 * ══ §131/212 F_PhysicsParticleGroupInertia(RValue&, CInstance*, CInstance*, int, RValue*)  0x14e22c  size 140  35 条（0x14e22c..0x14e2b8）
 * @func 0x14e22c 0x14e2c8  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CPhysicsWorld::GetParticleGroupInertia(int)
 * 字段偏移 top8: 0x10×2 / 0x74×1 / 0xc×1 / 0x4×1 / 0xb4×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14e22c push {r3, r4, r5, lr}
 *   @0x14e230 mov r1, #0
 *   @0x14e234 ldr r3, [pc, #0x74]
 *   @0x14e238 mov r4, r0
 *   @0x14e23c str r1, [r0]
 *   @0x14e240 mov r2, r1
 *   @0x14e244 ldr r3, [pc, r3]
 *   @0x14e248 str r1, [r0, #0xc]
 *   @0x14e24c movt r2, #0xbff0
 *   @0x14e250 str r2, [r0, #0x4]
 *   @0x14e254 ldr r3, [r3]
 *   @0x14e258 ldr r0, [sp, #0x10]
 *   @0x14e25c cmp r3, r1
 *   @0x14e260 beq 0x14e29c <_Z29F_PhysicsParticleGroupInertiaR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x14e264 ldr r5, [r3, #0xb4]
 *   @0x14e268 cmp r5, r1
 *   @0x14e26c beq 0x14e29c <_Z29F_PhysicsParticleGroupInertiaR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x14e270 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14e274 mov r1, r0
 *   @0x14e278 mov r0, r5
 *   @0x14e27c bl 0x23a668 <_ZN13CPhysicsWorld23GetParticleGroupInertiaEi>
 *   @0x14e280 vmov s15, r0
 *   @0x14e284 vcvt.f64.f32 d7, s15
 *   @0x14e288 vmov r0, r1, d7
 *   @0x14e28c vmov r2, s14
 *   @0x14e290 mov r3, r1
 *   @0x14e294 stm r4, {r2, r3}
 *   @0x14e298 pop {r3, r4, r5, pc}
 *   @0x14e29c ldr r0, [pc, #0x10]
 *   @0x14e2a0 mov r1, #0
 *   @0x14e2a4 pop {r3, r4, r5, lr}
 *   @0x14e2a8 add r0, pc, r0
 *   @0x14e2ac b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14e2b0 eoreq pc, r9, r4, ror #13
 *   @0x14e2b4 mulseq pc, r4, r4
 *
 * ══ §132/212 F_PhysicsParticleGroupCentreX(RValue&, CInstance*, CInstance*, int, RValue*)  0x14e2b8  size 140  35 条（0x14e2b8..0x14e344）
 * @func 0x14e2b8 0x14e354  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CPhysicsWorld::GetParticleGroupCentreX(int)
 * 字段偏移 top8: 0x10×2 / 0x74×1 / 0xc×1 / 0x4×1 / 0xb4×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14e2b8 push {r3, r4, r5, lr}
 *   @0x14e2bc mov r1, #0
 *   @0x14e2c0 ldr r3, [pc, #0x74]
 *   @0x14e2c4 mov r4, r0
 *   @0x14e2c8 str r1, [r0]
 *   @0x14e2cc mov r2, r1
 *   @0x14e2d0 ldr r3, [pc, r3]
 *   @0x14e2d4 str r1, [r0, #0xc]
 *   @0x14e2d8 movt r2, #0xbff0
 *   @0x14e2dc str r2, [r0, #0x4]
 *   @0x14e2e0 ldr r3, [r3]
 *   @0x14e2e4 ldr r0, [sp, #0x10]
 *   @0x14e2e8 cmp r3, r1
 *   @0x14e2ec beq 0x14e328 <_Z29F_PhysicsParticleGroupCentreXR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x14e2f0 ldr r5, [r3, #0xb4]
 *   @0x14e2f4 cmp r5, r1
 *   @0x14e2f8 beq 0x14e328 <_Z29F_PhysicsParticleGroupCentreXR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x14e2fc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14e300 mov r1, r0
 *   @0x14e304 mov r0, r5
 *   @0x14e308 bl 0x23a688 <_ZN13CPhysicsWorld23GetParticleGroupCentreXEi>
 *   @0x14e30c vmov s15, r0
 *   @0x14e310 vcvt.f64.f32 d7, s15
 *   @0x14e314 vmov r0, r1, d7
 *   @0x14e318 vmov r2, s14
 *   @0x14e31c mov r3, r1
 *   @0x14e320 stm r4, {r2, r3}
 *   @0x14e324 pop {r3, r4, r5, pc}
 *   @0x14e328 ldr r0, [pc, #0x10]
 *   @0x14e32c mov r1, #0
 *   @0x14e330 pop {r3, r4, r5, lr}
 *   @0x14e334 add r0, pc, r0
 *   @0x14e338 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14e33c eoreq pc, r9, r8, asr r6
 *   @0x14e340 andseq r6, pc, r12, ror #8
 *
 * ══ §133/212 F_PhysicsParticleGroupCentreY(RValue&, CInstance*, CInstance*, int, RValue*)  0x14e344  size 140  35 条（0x14e344..0x14e3d0）
 * @func 0x14e344 0x14e3e0  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CPhysicsWorld::GetParticleGroupCentreY(int)
 * 字段偏移 top8: 0x10×2 / 0x74×1 / 0xc×1 / 0x4×1 / 0xb4×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14e344 push {r3, r4, r5, lr}
 *   @0x14e348 mov r1, #0
 *   @0x14e34c ldr r3, [pc, #0x74]
 *   @0x14e350 mov r4, r0
 *   @0x14e354 str r1, [r0]
 *   @0x14e358 mov r2, r1
 *   @0x14e35c ldr r3, [pc, r3]
 *   @0x14e360 str r1, [r0, #0xc]
 *   @0x14e364 movt r2, #0xbff0
 *   @0x14e368 str r2, [r0, #0x4]
 *   @0x14e36c ldr r3, [r3]
 *   @0x14e370 ldr r0, [sp, #0x10]
 *   @0x14e374 cmp r3, r1
 *   @0x14e378 beq 0x14e3b4 <_Z29F_PhysicsParticleGroupCentreYR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x14e37c ldr r5, [r3, #0xb4]
 *   @0x14e380 cmp r5, r1
 *   @0x14e384 beq 0x14e3b4 <_Z29F_PhysicsParticleGroupCentreYR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x14e388 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14e38c mov r1, r0
 *   @0x14e390 mov r0, r5
 *   @0x14e394 bl 0x23a6d4 <_ZN13CPhysicsWorld23GetParticleGroupCentreYEi>
 *   @0x14e398 vmov s15, r0
 *   @0x14e39c vcvt.f64.f32 d7, s15
 *   @0x14e3a0 vmov r0, r1, d7
 *   @0x14e3a4 vmov r2, s14
 *   @0x14e3a8 mov r3, r1
 *   @0x14e3ac stm r4, {r2, r3}
 *   @0x14e3b0 pop {r3, r4, r5, pc}
 *   @0x14e3b4 ldr r0, [pc, #0x10]
 *   @0x14e3b8 mov r1, #0
 *   @0x14e3bc pop {r3, r4, r5, lr}
 *   @0x14e3c0 add r0, pc, r0
 *   @0x14e3c4 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14e3c8 eoreq pc, r9, r12, asr #11
 *   @0x14e3cc andseq r6, pc, r4, asr #8
 *
 * ══ §134/212 F_PhysicsParticleGroupVelX(RValue&, CInstance*, CInstance*, int, RValue*)  0x14e3d0  size 140  35 条（0x14e3d0..0x14e45c）
 * @func 0x14e3d0 0x14e46c  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CPhysicsWorld::GetParticleGroupVelocityX(int)
 * 字段偏移 top8: 0x10×2 / 0x74×1 / 0xc×1 / 0x4×1 / 0xb4×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14e3d0 push {r3, r4, r5, lr}
 *   @0x14e3d4 mov r1, #0
 *   @0x14e3d8 ldr r3, [pc, #0x74]
 *   @0x14e3dc mov r4, r0
 *   @0x14e3e0 str r1, [r0]
 *   @0x14e3e4 mov r2, r1
 *   @0x14e3e8 ldr r3, [pc, r3]
 *   @0x14e3ec str r1, [r0, #0xc]
 *   @0x14e3f0 movt r2, #0xbff0
 *   @0x14e3f4 str r2, [r0, #0x4]
 *   @0x14e3f8 ldr r3, [r3]
 *   @0x14e3fc ldr r0, [sp, #0x10]
 *   @0x14e400 cmp r3, r1
 *   @0x14e404 beq 0x14e440 <_Z26F_PhysicsParticleGroupVelXR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x14e408 ldr r5, [r3, #0xb4]
 *   @0x14e40c cmp r5, r1
 *   @0x14e410 beq 0x14e440 <_Z26F_PhysicsParticleGroupVelXR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x14e414 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14e418 mov r1, r0
 *   @0x14e41c mov r0, r5
 *   @0x14e420 bl 0x23a720 <_ZN13CPhysicsWorld25GetParticleGroupVelocityXEi>
 *   @0x14e424 vmov s15, r0
 *   @0x14e428 vcvt.f64.f32 d7, s15
 *   @0x14e42c vmov r0, r1, d7
 *   @0x14e430 vmov r2, s14
 *   @0x14e434 mov r3, r1
 *   @0x14e438 stm r4, {r2, r3}
 *   @0x14e43c pop {r3, r4, r5, pc}
 *   @0x14e440 ldr r0, [pc, #0x10]
 *   @0x14e444 mov r1, #0
 *   @0x14e448 pop {r3, r4, r5, lr}
 *   @0x14e44c add r0, pc, r0
 *   @0x14e450 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14e454 eoreq pc, r9, r0, asr #10
 *   @0x14e458 andseq r6, pc, r12, lsl r4
 *
 * ══ §135/212 F_PhysicsParticleGroupVelY(RValue&, CInstance*, CInstance*, int, RValue*)  0x14e45c  size 140  35 条（0x14e45c..0x14e4e8）
 * @func 0x14e45c 0x14e4f8  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CPhysicsWorld::GetParticleGroupVelocityY(int)
 * 字段偏移 top8: 0x10×2 / 0x74×1 / 0xc×1 / 0x4×1 / 0xb4×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14e45c push {r3, r4, r5, lr}
 *   @0x14e460 mov r1, #0
 *   @0x14e464 ldr r3, [pc, #0x74]
 *   @0x14e468 mov r4, r0
 *   @0x14e46c str r1, [r0]
 *   @0x14e470 mov r2, r1
 *   @0x14e474 ldr r3, [pc, r3]
 *   @0x14e478 str r1, [r0, #0xc]
 *   @0x14e47c movt r2, #0xbff0
 *   @0x14e480 str r2, [r0, #0x4]
 *   @0x14e484 ldr r3, [r3]
 *   @0x14e488 ldr r0, [sp, #0x10]
 *   @0x14e48c cmp r3, r1
 *   @0x14e490 beq 0x14e4cc <_Z26F_PhysicsParticleGroupVelYR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x14e494 ldr r5, [r3, #0xb4]
 *   @0x14e498 cmp r5, r1
 *   @0x14e49c beq 0x14e4cc <_Z26F_PhysicsParticleGroupVelYR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x14e4a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14e4a4 mov r1, r0
 *   @0x14e4a8 mov r0, r5
 *   @0x14e4ac bl 0x23a76c <_ZN13CPhysicsWorld25GetParticleGroupVelocityYEi>
 *   @0x14e4b0 vmov s15, r0
 *   @0x14e4b4 vcvt.f64.f32 d7, s15
 *   @0x14e4b8 vmov r0, r1, d7
 *   @0x14e4bc vmov r2, s14
 *   @0x14e4c0 mov r3, r1
 *   @0x14e4c4 stm r4, {r2, r3}
 *   @0x14e4c8 pop {r3, r4, r5, pc}
 *   @0x14e4cc ldr r0, [pc, #0x10]
 *   @0x14e4d0 mov r1, #0
 *   @0x14e4d4 pop {r3, r4, r5, lr}
 *   @0x14e4d8 add r0, pc, r0
 *   @0x14e4dc b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14e4e0 .word 0x0029f4b4
 *   @0x14e4e4 ldrsheq r6, [pc], -r4
 *
 * ══ §136/212 F_PhysicsParticleGroupAngVel(RValue&, CInstance*, CInstance*, int, RValue*)  0x14e4e8  size 140  35 条（0x14e4e8..0x14e574）
 * @func 0x14e4e8 0x14e584  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CPhysicsWorld::GetParticleGroupOmega(int)
 * 字段偏移 top8: 0x10×2 / 0x74×1 / 0xc×1 / 0x4×1 / 0xb4×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14e4e8 push {r3, r4, r5, lr}
 *   @0x14e4ec mov r1, #0
 *   @0x14e4f0 ldr r3, [pc, #0x74]
 *   @0x14e4f4 mov r4, r0
 *   @0x14e4f8 str r1, [r0]
 *   @0x14e4fc mov r2, r1
 *   @0x14e500 ldr r3, [pc, r3]
 *   @0x14e504 str r1, [r0, #0xc]
 *   @0x14e508 movt r2, #0xbff0
 *   @0x14e50c str r2, [r0, #0x4]
 *   @0x14e510 ldr r3, [r3]
 *   @0x14e514 ldr r0, [sp, #0x10]
 *   @0x14e518 cmp r3, r1
 *   @0x14e51c beq 0x14e558 <_Z28F_PhysicsParticleGroupAngVelR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x14e520 ldr r5, [r3, #0xb4]
 *   @0x14e524 cmp r5, r1
 *   @0x14e528 beq 0x14e558 <_Z28F_PhysicsParticleGroupAngVelR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x14e52c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14e530 mov r1, r0
 *   @0x14e534 mov r0, r5
 *   @0x14e538 bl 0x23a7b8 <_ZN13CPhysicsWorld21GetParticleGroupOmegaEi>
 *   @0x14e53c vmov s15, r0
 *   @0x14e540 vcvt.f64.f32 d7, s15
 *   @0x14e544 vmov r0, r1, d7
 *   @0x14e548 vmov r2, s14
 *   @0x14e54c mov r3, r1
 *   @0x14e550 stm r4, {r2, r3}
 *   @0x14e554 pop {r3, r4, r5, pc}
 *   @0x14e558 ldr r0, [pc, #0x10]
 *   @0x14e55c mov r1, #0
 *   @0x14e560 pop {r3, r4, r5, lr}
 *   @0x14e564 add r0, pc, r0
 *   @0x14e568 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14e56c eoreq pc, r9, r8, lsr #8
 *   @0x14e570 andseq r6, pc, r12, asr #7
 *
 * ══ §137/212 F_PhysicsParticleGroupX(RValue&, CInstance*, CInstance*, int, RValue*)  0x14e574  size 140  35 条（0x14e574..0x14e600）
 * @func 0x14e574 0x14e610  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CPhysicsWorld::GetParticleGroupX(int)
 * 字段偏移 top8: 0x10×2 / 0x74×1 / 0xc×1 / 0x4×1 / 0xb4×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14e574 push {r3, r4, r5, lr}
 *   @0x14e578 mov r1, #0
 *   @0x14e57c ldr r3, [pc, #0x74]
 *   @0x14e580 mov r4, r0
 *   @0x14e584 str r1, [r0]
 *   @0x14e588 mov r2, r1
 *   @0x14e58c ldr r3, [pc, r3]
 *   @0x14e590 str r1, [r0, #0xc]
 *   @0x14e594 movt r2, #0xbff0
 *   @0x14e598 str r2, [r0, #0x4]
 *   @0x14e59c ldr r3, [r3]
 *   @0x14e5a0 ldr r0, [sp, #0x10]
 *   @0x14e5a4 cmp r3, r1
 *   @0x14e5a8 beq 0x14e5e4 <_Z23F_PhysicsParticleGroupXR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x14e5ac ldr r5, [r3, #0xb4]
 *   @0x14e5b0 cmp r5, r1
 *   @0x14e5b4 beq 0x14e5e4 <_Z23F_PhysicsParticleGroupXR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x14e5b8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14e5bc mov r1, r0
 *   @0x14e5c0 mov r0, r5
 *   @0x14e5c4 bl 0x23a800 <_ZN13CPhysicsWorld17GetParticleGroupXEi>
 *   @0x14e5c8 vmov s15, r0
 *   @0x14e5cc vcvt.f64.f32 d7, s15
 *   @0x14e5d0 vmov r0, r1, d7
 *   @0x14e5d4 vmov r2, s14
 *   @0x14e5d8 mov r3, r1
 *   @0x14e5dc stm r4, {r2, r3}
 *   @0x14e5e0 pop {r3, r4, r5, pc}
 *   @0x14e5e4 ldr r0, [pc, #0x10]
 *   @0x14e5e8 mov r1, #0
 *   @0x14e5ec pop {r3, r4, r5, lr}
 *   @0x14e5f0 add r0, pc, r0
 *   @0x14e5f4 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14e5f8 mlaeq r9, r12, r3, pc
 *   @0x14e5fc andseq r6, pc, r0, asr #6
 *
 * ══ §138/212 F_PhysicsParticleGroupY(RValue&, CInstance*, CInstance*, int, RValue*)  0x14e600  size 140  35 条（0x14e600..0x14e68c）
 * @func 0x14e600 0x14e69c  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CPhysicsWorld::GetParticleGroupY(int)
 * 字段偏移 top8: 0x10×2 / 0x74×1 / 0xc×1 / 0x4×1 / 0xb4×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14e600 push {r3, r4, r5, lr}
 *   @0x14e604 mov r1, #0
 *   @0x14e608 ldr r3, [pc, #0x74]
 *   @0x14e60c mov r4, r0
 *   @0x14e610 str r1, [r0]
 *   @0x14e614 mov r2, r1
 *   @0x14e618 ldr r3, [pc, r3]
 *   @0x14e61c str r1, [r0, #0xc]
 *   @0x14e620 movt r2, #0xbff0
 *   @0x14e624 str r2, [r0, #0x4]
 *   @0x14e628 ldr r3, [r3]
 *   @0x14e62c ldr r0, [sp, #0x10]
 *   @0x14e630 cmp r3, r1
 *   @0x14e634 beq 0x14e670 <_Z23F_PhysicsParticleGroupYR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x14e638 ldr r5, [r3, #0xb4]
 *   @0x14e63c cmp r5, r1
 *   @0x14e640 beq 0x14e670 <_Z23F_PhysicsParticleGroupYR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x14e644 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14e648 mov r1, r0
 *   @0x14e64c mov r0, r5
 *   @0x14e650 bl 0x23a83c <_ZN13CPhysicsWorld17GetParticleGroupYEi>
 *   @0x14e654 vmov s15, r0
 *   @0x14e658 vcvt.f64.f32 d7, s15
 *   @0x14e65c vmov r0, r1, d7
 *   @0x14e660 vmov r2, s14
 *   @0x14e664 mov r3, r1
 *   @0x14e668 stm r4, {r2, r3}
 *   @0x14e66c pop {r3, r4, r5, pc}
 *   @0x14e670 ldr r0, [pc, #0x10]
 *   @0x14e674 mov r1, #0
 *   @0x14e678 pop {r3, r4, r5, lr}
 *   @0x14e67c add r0, pc, r0
 *   @0x14e680 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14e684 eoreq pc, r9, r0, lsl r3
 *   @0x14e688 andseq r6, pc, r4, lsl r3
 *
 * ══ §139/212 F_PhysicsParticleGroupAngle(RValue&, CInstance*, CInstance*, int, RValue*)  0x14e68c  size 140  35 条（0x14e68c..0x14e718）
 * @func 0x14e68c 0x14e718  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CPhysicsWorld::GetParticleGroupAngle(int)
 * 字段偏移 top8: 0x10×2 / 0x74×1 / 0xc×1 / 0x4×1 / 0xb4×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14e68c push {r3, r4, r5, lr}
 *   @0x14e690 mov r1, #0
 *   @0x14e694 ldr r3, [pc, #0x74]
 *   @0x14e698 mov r4, r0
 *   @0x14e69c str r1, [r0]
 *   @0x14e6a0 mov r2, r1
 *   @0x14e6a4 ldr r3, [pc, r3]
 *   @0x14e6a8 str r1, [r0, #0xc]
 *   @0x14e6ac movt r2, #0xbff0
 *   @0x14e6b0 str r2, [r0, #0x4]
 *   @0x14e6b4 ldr r3, [r3]
 *   @0x14e6b8 ldr r0, [sp, #0x10]
 *   @0x14e6bc cmp r3, r1
 *   @0x14e6c0 beq 0x14e6fc <_Z27F_PhysicsParticleGroupAngleR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x14e6c4 ldr r5, [r3, #0xb4]
 *   @0x14e6c8 cmp r5, r1
 *   @0x14e6cc beq 0x14e6fc <_Z27F_PhysicsParticleGroupAngleR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x14e6d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14e6d4 mov r1, r0
 *   @0x14e6d8 mov r0, r5
 *   @0x14e6dc bl 0x23a878 <_ZN13CPhysicsWorld21GetParticleGroupAngleEi>
 *   @0x14e6e0 vmov s15, r0
 *   @0x14e6e4 vcvt.f64.f32 d7, s15
 *   @0x14e6e8 vmov r0, r1, d7
 *   @0x14e6ec vmov r2, s14
 *   @0x14e6f0 mov r3, r1
 *   @0x14e6f4 stm r4, {r2, r3}
 *   @0x14e6f8 pop {r3, r4, r5, pc}
 *   @0x14e6fc ldr r0, [pc, #0x10]
 *   @0x14e700 mov r1, #0
 *   @0x14e704 pop {r3, r4, r5, lr}
 *   @0x14e708 add r0, pc, r0
 *   @0x14e70c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14e710 eoreq pc, r9, r4, lsl #5
 *   @0x14e714 andseq r6, pc, r8, ror #5
 *
 * ══ §140/212 F_GamepadSetVibration(RValue&, CInstance*, CInstance*, int, RValue*)  0x1518e8  size 140  35 条（0x1518e8..0x151974）
 * @func 0x1518e8 0x151974  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / anon_15149c / YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x4×1 / 0x4c×1 / 0x3c×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1518e8 push {r4, r5, r6, lr}
 *   @0x1518ec mov r4, #0
 *   @0x1518f0 ldr r5, [sp, #0x10]
 *   @0x1518f4 str r4, [r0, #0xc]
 *   @0x1518f8 str r4, [r0]
 *   @0x1518fc str r4, [r0, #0x4]
 *   @0x151900 bl 0x15149c <_Z20F_GamepadButtonCountR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x151904 mov r0, r5
 *   @0x151908 mov r1, r4
 *   @0x15190c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x151910 subs r2, r0, #0
 *   @0x151914 poplt {r4, r5, r6, pc}
 *   @0x151918 ldr r3, [pc, #0x4c]
 *   @0x15191c ldr r3, [pc, r3]
 *   @0x151920 ldr r3, [r3]
 *   @0x151924 cmp r2, r3
 *   @0x151928 popge {r4, r5, r6, pc}
 *   @0x15192c ldr r3, [pc, #0x3c]
 *   @0x151930 mov r0, r5
 *   @0x151934 mov r1, #1
 *   @0x151938 ldr r3, [pc, r3]
 *   @0x15193c ldr r3, [r3]
 *   @0x151940 ldr r6, [r3, r2, lsl #2]
 *   @0x151944 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x151948 mov r1, #2
 *   @0x15194c mov r4, r0
 *   @0x151950 mov r0, r5
 *   @0x151954 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x151958 mov r1, r4
 *   @0x15195c mov r2, r0
 *   @0x151960 mov r0, r6
 *   @0x151964 pop {r4, r5, r6, lr}
 *   @0x151968 b 0x18eee8 <_ZN9GMGamePad14SetMotorSpeedsEff>
 *   @0x15196c eoreq lr, r9, r4, asr #2
 *   @0x151970 eoreq lr, r9, r12, lsr #2
 *
 * ══ §141/212 GR_3D_Transform_Add_Translation(float, float, float)  0x163898  size 140  35 条（0x163898..0x163924）
 * @func 0x163898 0x163934  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics::GetMatrix(eMatrix, float*) / yyMatrix::Multiply(yyMatrix*, yyMatrix*, yyMatrix*) / Graphics::SetMatrix(eMatrix, float*) / DirtyRoomExtents()
 * 字段偏移 top8: 0x30×1 / 0x34×1 / 0x2c×1 / 0x24×1 / 0x20×1 / 0x1c×1 / 0x18×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x163898 push {r4, lr}
 *   @0x16389c sub sp, sp, #192
 *   @0x1638a0 add r4, sp, #64
 *   @0x1638a4 mov r3, #0
 *   @0x1638a8 str r0, [sp, #0x30]
 *   @0x1638ac mov r0, #2
 *   @0x1638b0 str r1, [sp, #0x34]
 *   @0x1638b4 mov r1, r4
 *   @0x1638b8 mov r12, #1065353216
 *   @0x1638bc str r3, [sp, #0x2c]
 *   @0x1638c0 str r3, [sp, #0x24]
 *   @0x1638c4 str r3, [sp, #0x20]
 *   @0x1638c8 str r3, [sp, #0x1c]
 *   @0x1638cc str r3, [sp, #0x18]
 *   @0x1638d0 str r3, [sp, #0x10]
 *   @0x1638d4 str r12, [sp, #0x3c]
 *   @0x1638d8 str r12, [sp, #0x28]
 *   @0x1638dc str r12, [sp, #0x14]
 *   @0x1638e0 str r12, [sp]
 *   @0x1638e4 str r3, [sp, #0xc]
 *   @0x1638e8 str r3, [sp, #0x8]
 *   @0x1638ec str r3, [sp, #0x4]
 *   @0x1638f0 str r2, [sp, #0x38]
 *   @0x1638f4 bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf>
 *   @0x1638f8 mov r1, r4
 *   @0x1638fc add r4, sp, #128
 *   @0x163900 mov r2, sp
 *   @0x163904 mov r0, r4
 *   @0x163908 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_>
 *   @0x16390c mov r1, r4
 *   @0x163910 mov r0, #2
 *   @0x163914 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf>
 *   @0x163918 bl 0x168d7c <_Z16DirtyRoomExtentsv>
 *   @0x16391c add sp, sp, #192
 *   @0x163920 pop {r4, pc}
 *
 * ══ §142/212 GR_3DM_Vertex_Color(int, float, float, float, unsigned int, float)  0x1654c8  size 140  35 条（0x1654c8..0x165554）
 * @func 0x1654c8 0x165564  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_3DM_Vertex_Color(int, float, float, float, unsigned int, float)+0x7c / C3D_Model::AddEntry(int, float, float, float, float, float, float, float, float, float, float)
 * 字段偏移 top8: 0x4×2 / 0x68×1 / 0x58×1 / 0x2×1 / 0x28×1 / 0xc×1 / 0x10×1 / 0x14×1
 * VFP 指令 2 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1654c8 cmp r0, #0
 *   @0x1654cc push {r4, lr}
 *   @0x1654d0 mov r4, r2
 *   @0x1654d4 sub sp, sp, #32
 *   @0x1654d8 blt 0x165544 <_Z19GR_3DM_Vertex_Colorifffjf+0x7c>
 *   @0x1654dc ldr r12, [pc, #0x68]
 *   @0x1654e0 ldr r12, [pc, r12]
 *   @0x1654e4 ldr r12, [r12]
 *   @0x1654e8 cmp r0, r12
 *   @0x1654ec bge 0x165544 <_Z19GR_3DM_Vertex_Colorifffjf+0x7c>
 *   @0x1654f0 ldr r12, [pc, #0x58]
 *   @0x1654f4 ldr r12, [pc, r12]
 *   @0x1654f8 ldr r2, [r12, #0x4]
 *   @0x1654fc ldr r0, [r2, r0, lsl #2]
 *   @0x165500 cmp r0, #0
 *   @0x165504 beq 0x165544 <_Z19GR_3DM_Vertex_Colorifffjf+0x7c>
 *   @0x165508 ldr r12, [sp, #0x28]
 *   @0x16550c vldr s15, [sp, #44]
 *   @0x165510 str r3, [sp]
 *   @0x165514 mov r2, r1
 *   @0x165518 vstr s15, [sp, #8]
 *   @0x16551c mov r1, #0
 *   @0x165520 mov r3, r4
 *   @0x165524 str r1, [sp, #0xc]
 *   @0x165528 str r1, [sp, #0x10]
 *   @0x16552c str r1, [sp, #0x14]
 *   @0x165530 str r1, [sp, #0x18]
 *   @0x165534 str r1, [sp, #0x1c]
 *   @0x165538 mov r1, #3
 *   @0x16553c str r12, [sp, #0x4]
 *   @0x165540 bl 0x1648d4 <_ZN9C3D_Model8AddEntryEiffffffffff>
 *   @0x165544 add sp, sp, #32
 *   @0x165548 pop {r4, pc}
 *   @0x16554c eoreq r10, r8, r0, lsl r12
 *   @0x165550 eoreq r10, r8, r0, lsl #24
 *
 * ══ §143/212 GR_3DM_Vertex_Texture(int, float, float, float, float, float)  0x165554  size 140  35 条（0x165554..0x1655e0）
 * @func 0x165554 0x1655e0  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_3DM_Vertex_Texture(int, float, float, float, float, float)+0x7c / C3D_Model::AddEntry(int, float, float, float, float, float, float, float, float, float, float)
 * 字段偏移 top8: 0x68×1 / 0x58×1 / 0x4×1 / 0x2×1 / 0xc×1 / 0x10×1 / 0x14×1 / 0x18×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x165554 cmp r0, #0
 *   @0x165558 push {r4, lr}
 *   @0x16555c mov r4, r2
 *   @0x165560 sub sp, sp, #32
 *   @0x165564 blt 0x1655d0 <_Z21GR_3DM_Vertex_Textureifffff+0x7c>
 *   @0x165568 ldr r12, [pc, #0x68]
 *   @0x16556c ldr r12, [pc, r12]
 *   @0x165570 ldr r12, [r12]
 *   @0x165574 cmp r0, r12
 *   @0x165578 bge 0x1655d0 <_Z21GR_3DM_Vertex_Textureifffff+0x7c>
 *   @0x16557c ldr r12, [pc, #0x58]
 *   @0x165580 ldr r12, [pc, r12]
 *   @0x165584 ldr r2, [r12, #0x4]
 *   @0x165588 ldr r0, [r2, r0, lsl #2]
 *   @0x16558c cmp r0, #0
 *   @0x165590 beq 0x1655d0 <_Z21GR_3DM_Vertex_Textureifffff+0x7c>
 *   @0x165594 vldr s15, [sp, #40]
 *   @0x165598 str r3, [sp]
 *   @0x16559c vstr s15, [sp, #4]
 *   @0x1655a0 mov r2, r1
 *   @0x1655a4 vldr s15, [sp, #44]
 *   @0x1655a8 mov r1, #0
 *   @0x1655ac vstr s15, [sp, #8]
 *   @0x1655b0 str r1, [sp, #0xc]
 *   @0x1655b4 str r1, [sp, #0x10]
 *   @0x1655b8 mov r3, r4
 *   @0x1655bc str r1, [sp, #0x14]
 *   @0x1655c0 str r1, [sp, #0x18]
 *   @0x1655c4 str r1, [sp, #0x1c]
 *   @0x1655c8 mov r1, #4
 *   @0x1655cc bl 0x1648d4 <_ZN9C3D_Model8AddEntryEiffffffffff>
 *   @0x1655d0 add sp, sp, #32
 *   @0x1655d4 pop {r4, pc}
 *   @0x1655d8 eoreq r10, r8, r4, lsl #23
 *   @0x1655dc eoreq r10, r8, r4, ror r11
 *
 * ══ §144/212 GR_Surface_DrawTiled(int, float, float, float, float, bool, bool, float, float, float, float, unsigned int, float)  0x172058  size 140  35 条（0x172058..0x1720e4）
 * @func 0x172058 0x1720e4  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Surface_Get(int) / GR_Texture_Draw_Tiled(int, float, float, float, float, float, float, bool, bool, float, float, float, float, unsigned int, float)
 * 字段偏移 top8: 0x4×2 / 0x4c×1 / 0x50×1 / 0x64×1 / 0x24×1 / 0xc×1 / 0x10×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x172058 push {r4, r5, r6, r7, r8, lr}
 *   @0x17205c sub sp, sp, #48
 *   @0x172060 mov r4, r1
 *   @0x172064 mov r8, r2
 *   @0x172068 mov r7, r3
 *   @0x17206c ldrb r6, [sp, #0x4c]
 *   @0x172070 ldrb r5, [sp, #0x50]
 *   @0x172074 bl 0x170f48 <_Z14GR_Surface_Geti>
 *   @0x172078 cmp r0, #0
 *   @0x17207c beq 0x1720dc <_Z20GR_Surface_DrawTilediffffbbffffjf+0x84>
 *   @0x172080 ldr r3, [sp, #0x64]
 *   @0x172084 mov r1, #0
 *   @0x172088 ldr r0, [r0, #0x4]
 *   @0x17208c vldr s15, [sp, #72]
 *   @0x172090 str r8, [sp]
 *   @0x172094 vstr s15, [sp, #8]
 *   @0x172098 str r3, [sp, #0x24]
 *   @0x17209c vldr s15, [sp, #84]
 *   @0x1720a0 str r7, [sp, #0x4]
 *   @0x1720a4 vstr s15, [sp, #20]
 *   @0x1720a8 str r6, [sp, #0xc]
 *   @0x1720ac vldr s15, [sp, #88]
 *   @0x1720b0 str r5, [sp, #0x10]
 *   @0x1720b4 vstr s15, [sp, #24]
 *   @0x1720b8 mov r3, r4
 *   @0x1720bc vldr s15, [sp, #92]
 *   @0x1720c0 mov r2, r1
 *   @0x1720c4 vstr s15, [sp, #28]
 *   @0x1720c8 vldr s15, [sp, #96]
 *   @0x1720cc vstr s15, [sp, #32]
 *   @0x1720d0 vldr s15, [sp, #104]
 *   @0x1720d4 vstr s15, [sp, #40]
 *   @0x1720d8 bl 0x175e90 <_Z21GR_Texture_Draw_Tilediffffffbbffffjf>
 *   @0x1720dc add sp, sp, #48
 *   @0x1720e0 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §145/212 Shader_Get_Sampler_Index(Shader*, char const*)  0x188468  size 140  35 条（0x188468..0x1884f4）
 * @func 0x188468 0x1884f4  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Shader_Get(int) / Shader_Get_Sampler_Index(Shader*, char const*)+0x80 / 0xb6574
 * 字段偏移 top8: 0x78×1 / 0x64×1 / 0x14×1 / 0x18×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x188468 push {r3, r4, r5, r6, r7, lr}
 *   @0x18846c mov r7, r1
 *   @0x188470 ldr r3, [pc, #0x78]
 *   @0x188474 ldr r3, [pc, r3]
 *   @0x188478 ldr r3, [r3]
 *   @0x18847c cmp r3, #1
 *   @0x188480 bne 0x1884e8 <_Z24Shader_Get_Sampler_IndexP6ShaderPKc+0x80>
 *   @0x188484 cmp r0, #0
 *   @0x188488 beq 0x1884e8 <_Z24Shader_Get_Sampler_IndexP6ShaderPKc+0x80>
 *   @0x18848c ldr r0, [r0, #0x64]
 *   @0x188490 bl 0x187e70 <_Z10Shader_Geti>
 *   @0x188494 cmp r0, #0
 *   @0x188498 beq 0x1884e8 <_Z24Shader_Get_Sampler_IndexP6ShaderPKc+0x80>
 *   @0x18849c ldr r4, [r0, #0x14]
 *   @0x1884a0 cmp r4, #0
 *   @0x1884a4 beq 0x1884e8 <_Z24Shader_Get_Sampler_IndexP6ShaderPKc+0x80>
 *   @0x1884a8 ldr r6, [r0, #0x18]
 *   @0x1884ac cmp r6, #0
 *   @0x1884b0 ble 0x1884e8 <_Z24Shader_Get_Sampler_IndexP6ShaderPKc+0x80>
 *   @0x1884b4 mov r5, #0
 *   @0x1884b8 b 0x1884c8 <_Z24Shader_Get_Sampler_IndexP6ShaderPKc+0x60>
 *   @0x1884bc cmp r5, r6
 *   @0x1884c0 add r4, r4, #12
 *   @0x1884c4 beq 0x1884e8 <_Z24Shader_Get_Sampler_IndexP6ShaderPKc+0x80>
 *   @0x1884c8 ldr r0, [r4]
 *   @0x1884cc mov r1, r7
 *   @0x1884d0 bl 0xb6574 <strcmp@plt>
 *   @0x1884d4 add r5, r5, #1
 *   @0x1884d8 cmp r0, #0
 *   @0x1884dc bne 0x1884bc <_Z24Shader_Get_Sampler_IndexP6ShaderPKc+0x54>
 *   @0x1884e0 ldr r0, [r4, #0x8]
 *   @0x1884e4 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1884e8 mvn r0, #0
 *   @0x1884ec pop {r3, r4, r5, r6, r7, pc}
 *   @0x1884f0 mlaeq r6, r4, pc, r7
 *
 * ══ §146/212 FINALIZE_Motion_Grid()  0x19c2cc  size 140  35 条（0x19c2cc..0x19c358）
 * @func 0x19c2cc 0x19c358  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FINALIZE_Motion_Grid()+0x6c / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x2×2 / 0x78×1 / 0x68×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19c2cc push {r3, r4, r5, r6, r7, lr}
 *   @0x19c2d0 ldr r5, [pc, #0x78]
 *   @0x19c2d4 ldr r5, [pc, r5]
 *   @0x19c2d8 ldr r2, [r5]
 *   @0x19c2dc cmp r2, #0
 *   @0x19c2e0 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x19c2e4 ldr r6, [pc, #0x68]
 *   @0x19c2e8 ldr r6, [pc, r6]
 *   @0x19c2ec ldr r3, [r6]
 *   @0x19c2f0 cmp r3, #0
 *   @0x19c2f4 ble 0x19c338 <_Z20FINALIZE_Motion_Gridv+0x6c>
 *   @0x19c2f8 mov r4, #0
 *   @0x19c2fc mov r7, r4
 *   @0x19c300 ldr r3, [r2, r4, lsl #2]
 *   @0x19c304 cmp r3, #0
 *   @0x19c308 mov r0, r3
 *   @0x19c30c beq 0x19c328 <_Z20FINALIZE_Motion_Gridv+0x5c>
 *   @0x19c310 ldr r3, [r3]
 *   @0x19c314 ldr r3, [r3, #0x4]
 *   @0x19c318 blx r3
 *   @0x19c31c ldr r3, [r5]
 *   @0x19c320 str r7, [r3, r4, lsl #2]
 *   @0x19c324 ldr r2, [r5]
 *   @0x19c328 ldr r3, [r6]
 *   @0x19c32c add r4, r4, #1
 *   @0x19c330 cmp r3, r4
 *   @0x19c334 bgt 0x19c300 <_Z20FINALIZE_Motion_Gridv+0x34>
 *   @0x19c338 mov r0, r2
 *   @0x19c33c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x19c340 mov r3, #0
 *   @0x19c344 str r3, [r5]
 *   @0x19c348 str r3, [r6]
 *   @0x19c34c pop {r3, r4, r5, r6, r7, pc}
 *   @0x19c350 .word 0x002543dc
 *   @0x19c354 eoreq r4, r5, r4, asr #7
 *
 * ══ §147/212 TBitmap::LockBits(int, void**, int*)  0x1a89b8  size 140  35 条（0x1a89b8..0x1a8a44）
 * @func 0x1a89b8 0x1a8a44  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x4×2 / 0xc×2 / 0x20×1 / 0x1c×1 / 0x28×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a89b8 ldr r12, [r0, #0x4]
 *   @0x1a89bc push {r3, r4, r5, r6, r7, lr}
 *   @0x1a89c0 cmp r12, #0
 *   @0x1a89c4 mov r4, r0
 *   @0x1a89c8 mov r7, r1
 *   @0x1a89cc mov r5, r2
 *   @0x1a89d0 mov r6, r3
 *   @0x1a89d4 beq 0x1a8a00 <_ZN7TBitmap8LockBitsEiPPvPi+0x48>
 *   @0x1a89d8 ldr r0, [r0, #0xc]
 *   @0x1a89dc cmp r6, #0
 *   @0x1a89e0 ldrne r3, [r4, #0x20]
 *   @0x1a89e4 strne r3, [r6]
 *   @0x1a89e8 cmp r5, #0
 *   @0x1a89ec ldrne r3, [r4, #0x20]
 *   @0x1a89f0 mlane r0, r3, r7, r0
 *   @0x1a89f4 strne r0, [r5]
 *   @0x1a89f8 ldrne r0, [r4, #0xc]
 *   @0x1a89fc pop {r3, r4, r5, r6, r7, pc}
 *   @0x1a8a00 ldr r0, [r0, #0x20]
 *   @0x1a8a04 movw r2, #0x131
 *   @0x1a8a08 ldr r12, [r4, #0x1c]
 *   @0x1a8a0c mov r3, #1
 *   @0x1a8a10 ldr r1, [pc, #0x28]
 *   @0x1a8a14 mul r0, r12, r0
 *   @0x1a8a18 add r1, pc, r1
 *   @0x1a8a1c add r0, r0, #52
 *   @0x1a8a20 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1a8a24 mov r2, #52
 *   @0x1a8a28 mov r3, r0
 *   @0x1a8a2c str r0, [r4, #0x4]
 *   @0x1a8a30 add r0, r0, r2
 *   @0x1a8a34 str r0, [r4, #0xc]
 *   @0x1a8a38 str r2, [r3, #0x8]
 *   @0x1a8a3c b 0x1a89dc <_ZN7TBitmap8LockBitsEiPPvPi+0x24>
 *   @0x1a8a40 andseq r4, r10, r12, asr r7
 *
 * ══ §148/212 BitmapLoader::Create(int)  0x1a8b8c  size 140  35 条（0x1a8b8c..0x1a8c18）
 * @func 0x1a8b8c 0x1a8c18  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: BitmapLoader::Create(int)+0x80 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb65bc / operator new(unsigned int) / TBitmap::TBitmap()
 * 字段偏移 top8: 0x4×2 / 0x8×1 / 0x60×1 / 0x10×1 / 0x14×1 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a8b8c ldr r3, [r0, #0x8]
 *   @0x1a8b90 push {r4, r5, r6, lr}
 *   @0x1a8b94 cmp r3, r1
 *   @0x1a8b98 mov r4, r0
 *   @0x1a8b9c movle r4, #0
 *   @0x1a8ba0 ble 0x1a8c0c <_ZN12BitmapLoader6CreateEi+0x80>
 *   @0x1a8ba4 ldr r0, [r4, #0x4]
 *   @0x1a8ba8 mov r3, #0
 *   @0x1a8bac ldr r1, [pc, #0x60]
 *   @0x1a8bb0 mov r2, #396
 *   @0x1a8bb4 ldr r12, [r0, #0x10]
 *   @0x1a8bb8 add r1, pc, r1
 *   @0x1a8bbc ldr r5, [r0, #0x14]
 *   @0x1a8bc0 mul r5, r5, r12
 *   @0x1a8bc4 lsl r5, r5, #2
 *   @0x1a8bc8 add r5, r5, #52
 *   @0x1a8bcc mov r0, r5
 *   @0x1a8bd0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1a8bd4 ldr r1, [r4, #0x4]
 *   @0x1a8bd8 mov r2, r5
 *   @0x1a8bdc mov r6, r0
 *   @0x1a8be0 bl 0xb65bc <memcpy@plt>
 *   @0x1a8be4 mov r0, #44
 *   @0x1a8be8 bl 0x27c524 <_Znwj>
 *   @0x1a8bec mov r4, r0
 *   @0x1a8bf0 bl 0x1a8b50 <_ZN7TBitmapC2Ev>
 *   @0x1a8bf4 ldr r3, [r4]
 *   @0x1a8bf8 mov r2, r5
 *   @0x1a8bfc mov r1, r6
 *   @0x1a8c00 mov r0, r4
 *   @0x1a8c04 ldr r3, [r3, #0x38]
 *   @0x1a8c08 blx r3
 *   @0x1a8c0c mov r0, r4
 *   @0x1a8c10 pop {r4, r5, r6, pc}
 *   @0x1a8c14 ldrheq r4, [r10], -r12
 *
 * ══ §149/212 F_LayerSpriteChange(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bd140  size 140  35 条（0x1bd140..0x1bd1cc）
 * @func 0x1bd140 0x1bd1dc  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / CLayerManager::GetTargetRoomObj() / CLayerManager::GetElementFromID(CRoom*, int, CLayer**)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x4×1 / 0x58×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bd140 cmp r3, #2
 *   @0x1bd144 mov r3, #0
 *   @0x1bd148 push {r4, r5, r6, lr}
 *   @0x1bd14c mov r4, r3
 *   @0x1bd150 ldr r5, [sp, #0x10]
 *   @0x1bd154 movt r3, #0xbff0
 *   @0x1bd158 str r4, [r0, #0xc]
 *   @0x1bd15c str r3, [r0, #0x4]
 *   @0x1bd160 str r4, [r0]
 *   @0x1bd164 beq 0x1bd17c <_Z19F_LayerSpriteChangeR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1bd168 ldr r0, [pc, #0x58]
 *   @0x1bd16c mov r1, r4
 *   @0x1bd170 pop {r4, r5, r6, lr}
 *   @0x1bd174 add r0, pc, r0
 *   @0x1bd178 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bd17c bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bd180 mov r1, r4
 *   @0x1bd184 mov r6, r0
 *   @0x1bd188 mov r0, r5
 *   @0x1bd18c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bd190 mov r2, r4
 *   @0x1bd194 mov r1, r0
 *   @0x1bd198 mov r0, r6
 *   @0x1bd19c bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bd1a0 subs r4, r0, #0
 *   @0x1bd1a4 popeq {r4, r5, r6, pc}
 *   @0x1bd1a8 ldr r3, [r4]
 *   @0x1bd1ac cmp r3, #4
 *   @0x1bd1b0 popne {r4, r5, r6, pc}
 *   @0x1bd1b4 mov r0, r5
 *   @0x1bd1b8 mov r1, #1
 *   @0x1bd1bc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bd1c0 str r0, [r4, #0x1c]
 *   @0x1bd1c4 pop {r4, r5, r6, pc}
 *   @0x1bd1c8 ldrsbeq r1, [r9], -r12
 *
 * ══ §150/212 F_LayerSpriteIndex(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bd1cc  size 140  35 条（0x1bd1cc..0x1bd258）
 * @func 0x1bd1cc 0x1bd268  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**) / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x4×1 / 0x58×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bd1cc cmp r3, #2
 *   @0x1bd1d0 mov r3, #0
 *   @0x1bd1d4 push {r4, r5, r6, lr}
 *   @0x1bd1d8 mov r4, r3
 *   @0x1bd1dc ldr r5, [sp, #0x10]
 *   @0x1bd1e0 movt r3, #0xbff0
 *   @0x1bd1e4 str r4, [r0, #0xc]
 *   @0x1bd1e8 str r3, [r0, #0x4]
 *   @0x1bd1ec str r4, [r0]
 *   @0x1bd1f0 beq 0x1bd208 <_Z18F_LayerSpriteIndexR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1bd1f4 ldr r0, [pc, #0x58]
 *   @0x1bd1f8 mov r1, r4
 *   @0x1bd1fc pop {r4, r5, r6, lr}
 *   @0x1bd200 add r0, pc, r0
 *   @0x1bd204 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bd208 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bd20c mov r1, r4
 *   @0x1bd210 mov r6, r0
 *   @0x1bd214 mov r0, r5
 *   @0x1bd218 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bd21c mov r2, r4
 *   @0x1bd220 mov r1, r0
 *   @0x1bd224 mov r0, r6
 *   @0x1bd228 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bd22c subs r4, r0, #0
 *   @0x1bd230 popeq {r4, r5, r6, pc}
 *   @0x1bd234 ldr r3, [r4]
 *   @0x1bd238 cmp r3, #4
 *   @0x1bd23c popne {r4, r5, r6, pc}
 *   @0x1bd240 mov r0, r5
 *   @0x1bd244 mov r1, #1
 *   @0x1bd248 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1bd24c str r0, [r4, #0x20]
 *   @0x1bd250 pop {r4, r5, r6, pc}
 *   @0x1bd254 andseq r1, r9, r4, lsl #3
 *
 * ══ §151/212 F_LayerSpriteSpeed(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bd258  size 140  35 条（0x1bd258..0x1bd2e4）
 * @func 0x1bd258 0x1bd2f4  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**) / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x4×1 / 0x58×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bd258 cmp r3, #2
 *   @0x1bd25c mov r3, #0
 *   @0x1bd260 push {r4, r5, r6, lr}
 *   @0x1bd264 mov r4, r3
 *   @0x1bd268 ldr r5, [sp, #0x10]
 *   @0x1bd26c movt r3, #0xbff0
 *   @0x1bd270 str r4, [r0, #0xc]
 *   @0x1bd274 str r3, [r0, #0x4]
 *   @0x1bd278 str r4, [r0]
 *   @0x1bd27c beq 0x1bd294 <_Z18F_LayerSpriteSpeedR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1bd280 ldr r0, [pc, #0x58]
 *   @0x1bd284 mov r1, r4
 *   @0x1bd288 pop {r4, r5, r6, lr}
 *   @0x1bd28c add r0, pc, r0
 *   @0x1bd290 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bd294 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bd298 mov r1, r4
 *   @0x1bd29c mov r6, r0
 *   @0x1bd2a0 mov r0, r5
 *   @0x1bd2a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bd2a8 mov r2, r4
 *   @0x1bd2ac mov r1, r0
 *   @0x1bd2b0 mov r0, r6
 *   @0x1bd2b4 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bd2b8 subs r4, r0, #0
 *   @0x1bd2bc popeq {r4, r5, r6, pc}
 *   @0x1bd2c0 ldr r3, [r4]
 *   @0x1bd2c4 cmp r3, #4
 *   @0x1bd2c8 popne {r4, r5, r6, pc}
 *   @0x1bd2cc mov r0, r5
 *   @0x1bd2d0 mov r1, #1
 *   @0x1bd2d4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1bd2d8 str r0, [r4, #0x24]
 *   @0x1bd2dc pop {r4, r5, r6, pc}
 *   @0x1bd2e0 andseq r1, r9, r12, lsr #2
 *
 * ══ §152/212 F_LayerSpriteXScale(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bd2e4  size 140  35 条（0x1bd2e4..0x1bd370）
 * @func 0x1bd2e4 0x1bd380  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**) / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x4×1 / 0x58×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bd2e4 cmp r3, #2
 *   @0x1bd2e8 mov r3, #0
 *   @0x1bd2ec push {r4, r5, r6, lr}
 *   @0x1bd2f0 mov r4, r3
 *   @0x1bd2f4 ldr r5, [sp, #0x10]
 *   @0x1bd2f8 movt r3, #0xbff0
 *   @0x1bd2fc str r4, [r0, #0xc]
 *   @0x1bd300 str r3, [r0, #0x4]
 *   @0x1bd304 str r4, [r0]
 *   @0x1bd308 beq 0x1bd320 <_Z19F_LayerSpriteXScaleR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1bd30c ldr r0, [pc, #0x58]
 *   @0x1bd310 mov r1, r4
 *   @0x1bd314 pop {r4, r5, r6, lr}
 *   @0x1bd318 add r0, pc, r0
 *   @0x1bd31c b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bd320 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bd324 mov r1, r4
 *   @0x1bd328 mov r6, r0
 *   @0x1bd32c mov r0, r5
 *   @0x1bd330 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bd334 mov r2, r4
 *   @0x1bd338 mov r1, r0
 *   @0x1bd33c mov r0, r6
 *   @0x1bd340 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bd344 subs r4, r0, #0
 *   @0x1bd348 popeq {r4, r5, r6, pc}
 *   @0x1bd34c ldr r3, [r4]
 *   @0x1bd350 cmp r3, #4
 *   @0x1bd354 popne {r4, r5, r6, pc}
 *   @0x1bd358 mov r0, r5
 *   @0x1bd35c mov r1, #1
 *   @0x1bd360 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1bd364 str r0, [r4, #0x2c]
 *   @0x1bd368 pop {r4, r5, r6, pc}
 *   @0x1bd36c ldrsbeq r1, [r9], -r4
 *
 * ══ §153/212 F_LayerSpriteYScale(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bd370  size 140  35 条（0x1bd370..0x1bd3fc）
 * @func 0x1bd370 0x1bd40c  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**) / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x4×1 / 0x58×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bd370 cmp r3, #2
 *   @0x1bd374 mov r3, #0
 *   @0x1bd378 push {r4, r5, r6, lr}
 *   @0x1bd37c mov r4, r3
 *   @0x1bd380 ldr r5, [sp, #0x10]
 *   @0x1bd384 movt r3, #0xbff0
 *   @0x1bd388 str r4, [r0, #0xc]
 *   @0x1bd38c str r3, [r0, #0x4]
 *   @0x1bd390 str r4, [r0]
 *   @0x1bd394 beq 0x1bd3ac <_Z19F_LayerSpriteYScaleR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1bd398 ldr r0, [pc, #0x58]
 *   @0x1bd39c mov r1, r4
 *   @0x1bd3a0 pop {r4, r5, r6, lr}
 *   @0x1bd3a4 add r0, pc, r0
 *   @0x1bd3a8 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bd3ac bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bd3b0 mov r1, r4
 *   @0x1bd3b4 mov r6, r0
 *   @0x1bd3b8 mov r0, r5
 *   @0x1bd3bc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bd3c0 mov r2, r4
 *   @0x1bd3c4 mov r1, r0
 *   @0x1bd3c8 mov r0, r6
 *   @0x1bd3cc bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bd3d0 subs r4, r0, #0
 *   @0x1bd3d4 popeq {r4, r5, r6, pc}
 *   @0x1bd3d8 ldr r3, [r4]
 *   @0x1bd3dc cmp r3, #4
 *   @0x1bd3e0 popne {r4, r5, r6, pc}
 *   @0x1bd3e4 mov r0, r5
 *   @0x1bd3e8 mov r1, #1
 *   @0x1bd3ec bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1bd3f0 str r0, [r4, #0x30]
 *   @0x1bd3f4 pop {r4, r5, r6, pc}
 *   @0x1bd3f8 andseq r1, r9, r12, ror r0
 *
 * ══ §154/212 F_LayerSpriteAngle(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bd3fc  size 140  35 条（0x1bd3fc..0x1bd488）
 * @func 0x1bd3fc 0x1bd498  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**) / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x4×1 / 0x58×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bd3fc cmp r3, #2
 *   @0x1bd400 mov r3, #0
 *   @0x1bd404 push {r4, r5, r6, lr}
 *   @0x1bd408 mov r4, r3
 *   @0x1bd40c ldr r5, [sp, #0x10]
 *   @0x1bd410 movt r3, #0xbff0
 *   @0x1bd414 str r4, [r0, #0xc]
 *   @0x1bd418 str r3, [r0, #0x4]
 *   @0x1bd41c str r4, [r0]
 *   @0x1bd420 beq 0x1bd438 <_Z18F_LayerSpriteAngleR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1bd424 ldr r0, [pc, #0x58]
 *   @0x1bd428 mov r1, r4
 *   @0x1bd42c pop {r4, r5, r6, lr}
 *   @0x1bd430 add r0, pc, r0
 *   @0x1bd434 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bd438 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bd43c mov r1, r4
 *   @0x1bd440 mov r6, r0
 *   @0x1bd444 mov r0, r5
 *   @0x1bd448 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bd44c mov r2, r4
 *   @0x1bd450 mov r1, r0
 *   @0x1bd454 mov r0, r6
 *   @0x1bd458 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bd45c subs r4, r0, #0
 *   @0x1bd460 popeq {r4, r5, r6, pc}
 *   @0x1bd464 ldr r3, [r4]
 *   @0x1bd468 cmp r3, #4
 *   @0x1bd46c popne {r4, r5, r6, pc}
 *   @0x1bd470 mov r0, r5
 *   @0x1bd474 mov r1, #1
 *   @0x1bd478 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1bd47c str r0, [r4, #0x34]
 *   @0x1bd480 pop {r4, r5, r6, pc}
 *   @0x1bd484 andseq r1, r9, r4, lsr #32
 *
 * ══ §155/212 F_LayerSpriteBlend(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bd488  size 140  35 条（0x1bd488..0x1bd514）
 * @func 0x1bd488 0x1bd524  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / CLayerManager::GetTargetRoomObj() / CLayerManager::GetElementFromID(CRoom*, int, CLayer**)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x4×1 / 0x58×1 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bd488 cmp r3, #2
 *   @0x1bd48c mov r3, #0
 *   @0x1bd490 push {r4, r5, r6, lr}
 *   @0x1bd494 mov r4, r3
 *   @0x1bd498 ldr r5, [sp, #0x10]
 *   @0x1bd49c movt r3, #0xbff0
 *   @0x1bd4a0 str r4, [r0, #0xc]
 *   @0x1bd4a4 str r3, [r0, #0x4]
 *   @0x1bd4a8 str r4, [r0]
 *   @0x1bd4ac beq 0x1bd4c4 <_Z18F_LayerSpriteBlendR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1bd4b0 ldr r0, [pc, #0x58]
 *   @0x1bd4b4 mov r1, r4
 *   @0x1bd4b8 pop {r4, r5, r6, lr}
 *   @0x1bd4bc add r0, pc, r0
 *   @0x1bd4c0 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bd4c4 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bd4c8 mov r1, r4
 *   @0x1bd4cc mov r6, r0
 *   @0x1bd4d0 mov r0, r5
 *   @0x1bd4d4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bd4d8 mov r2, r4
 *   @0x1bd4dc mov r1, r0
 *   @0x1bd4e0 mov r0, r6
 *   @0x1bd4e4 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bd4e8 subs r4, r0, #0
 *   @0x1bd4ec popeq {r4, r5, r6, pc}
 *   @0x1bd4f0 ldr r3, [r4]
 *   @0x1bd4f4 cmp r3, #4
 *   @0x1bd4f8 popne {r4, r5, r6, pc}
 *   @0x1bd4fc mov r0, r5
 *   @0x1bd500 mov r1, #1
 *   @0x1bd504 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bd508 str r0, [r4, #0x38]
 *   @0x1bd50c pop {r4, r5, r6, pc}
 *   @0x1bd510 andseq r0, r9, r12, asr #31
 *
 * ══ §156/212 F_LayerSpriteAlpha(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bd514  size 140  35 条（0x1bd514..0x1bd5a0）
 * @func 0x1bd514 0x1bd5b0  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**) / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x4×1 / 0x58×1 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bd514 cmp r3, #2
 *   @0x1bd518 mov r3, #0
 *   @0x1bd51c push {r4, r5, r6, lr}
 *   @0x1bd520 mov r4, r3
 *   @0x1bd524 ldr r5, [sp, #0x10]
 *   @0x1bd528 movt r3, #0xbff0
 *   @0x1bd52c str r4, [r0, #0xc]
 *   @0x1bd530 str r3, [r0, #0x4]
 *   @0x1bd534 str r4, [r0]
 *   @0x1bd538 beq 0x1bd550 <_Z18F_LayerSpriteAlphaR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1bd53c ldr r0, [pc, #0x58]
 *   @0x1bd540 mov r1, r4
 *   @0x1bd544 pop {r4, r5, r6, lr}
 *   @0x1bd548 add r0, pc, r0
 *   @0x1bd54c b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bd550 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bd554 mov r1, r4
 *   @0x1bd558 mov r6, r0
 *   @0x1bd55c mov r0, r5
 *   @0x1bd560 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bd564 mov r2, r4
 *   @0x1bd568 mov r1, r0
 *   @0x1bd56c mov r0, r6
 *   @0x1bd570 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bd574 subs r4, r0, #0
 *   @0x1bd578 popeq {r4, r5, r6, pc}
 *   @0x1bd57c ldr r3, [r4]
 *   @0x1bd580 cmp r3, #4
 *   @0x1bd584 popne {r4, r5, r6, pc}
 *   @0x1bd588 mov r0, r5
 *   @0x1bd58c mov r1, #1
 *   @0x1bd590 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1bd594 str r0, [r4, #0x3c]
 *   @0x1bd598 pop {r4, r5, r6, pc}
 *   @0x1bd59c andseq r0, r9, r4, ror pc
 *
 * ══ §157/212 F_LayerSpriteX(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bd5a0  size 140  35 条（0x1bd5a0..0x1bd62c）
 * @func 0x1bd5a0 0x1bd63c  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**) / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x4×1 / 0x58×1 / 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bd5a0 cmp r3, #2
 *   @0x1bd5a4 mov r3, #0
 *   @0x1bd5a8 push {r4, r5, r6, lr}
 *   @0x1bd5ac mov r4, r3
 *   @0x1bd5b0 ldr r5, [sp, #0x10]
 *   @0x1bd5b4 movt r3, #0xbff0
 *   @0x1bd5b8 str r4, [r0, #0xc]
 *   @0x1bd5bc str r3, [r0, #0x4]
 *   @0x1bd5c0 str r4, [r0]
 *   @0x1bd5c4 beq 0x1bd5dc <_Z14F_LayerSpriteXR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1bd5c8 ldr r0, [pc, #0x58]
 *   @0x1bd5cc mov r1, r4
 *   @0x1bd5d0 pop {r4, r5, r6, lr}
 *   @0x1bd5d4 add r0, pc, r0
 *   @0x1bd5d8 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bd5dc bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bd5e0 mov r1, r4
 *   @0x1bd5e4 mov r6, r0
 *   @0x1bd5e8 mov r0, r5
 *   @0x1bd5ec bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bd5f0 mov r2, r4
 *   @0x1bd5f4 mov r1, r0
 *   @0x1bd5f8 mov r0, r6
 *   @0x1bd5fc bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bd600 subs r4, r0, #0
 *   @0x1bd604 popeq {r4, r5, r6, pc}
 *   @0x1bd608 ldr r3, [r4]
 *   @0x1bd60c cmp r3, #4
 *   @0x1bd610 popne {r4, r5, r6, pc}
 *   @0x1bd614 mov r0, r5
 *   @0x1bd618 mov r1, #1
 *   @0x1bd61c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1bd620 str r0, [r4, #0x40]
 *   @0x1bd624 pop {r4, r5, r6, pc}
 *   @0x1bd628 andseq r0, r9, r12, lsl pc
 *
 * ══ §158/212 F_LayerSpriteY(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bd62c  size 140  35 条（0x1bd62c..0x1bd6b8）
 * @func 0x1bd62c 0x1bd6b8  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**) / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x4×1 / 0x58×1 / 0x44×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bd62c cmp r3, #2
 *   @0x1bd630 mov r3, #0
 *   @0x1bd634 push {r4, r5, r6, lr}
 *   @0x1bd638 mov r4, r3
 *   @0x1bd63c ldr r5, [sp, #0x10]
 *   @0x1bd640 movt r3, #0xbff0
 *   @0x1bd644 str r4, [r0, #0xc]
 *   @0x1bd648 str r3, [r0, #0x4]
 *   @0x1bd64c str r4, [r0]
 *   @0x1bd650 beq 0x1bd668 <_Z14F_LayerSpriteYR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1bd654 ldr r0, [pc, #0x58]
 *   @0x1bd658 mov r1, r4
 *   @0x1bd65c pop {r4, r5, r6, lr}
 *   @0x1bd660 add r0, pc, r0
 *   @0x1bd664 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bd668 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bd66c mov r1, r4
 *   @0x1bd670 mov r6, r0
 *   @0x1bd674 mov r0, r5
 *   @0x1bd678 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bd67c mov r2, r4
 *   @0x1bd680 mov r1, r0
 *   @0x1bd684 mov r0, r6
 *   @0x1bd688 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bd68c subs r4, r0, #0
 *   @0x1bd690 popeq {r4, r5, r6, pc}
 *   @0x1bd694 ldr r3, [r4]
 *   @0x1bd698 cmp r3, #4
 *   @0x1bd69c popne {r4, r5, r6, pc}
 *   @0x1bd6a0 mov r0, r5
 *   @0x1bd6a4 mov r1, #1
 *   @0x1bd6a8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1bd6ac str r0, [r4, #0x44]
 *   @0x1bd6b0 pop {r4, r5, r6, pc}
 *   @0x1bd6b4 andseq r0, r9, r0, asr #29
 *
 * ══ §159/212 F_TilemapTileset(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bdcb0  size 140  35 条（0x1bdcb0..0x1bdd3c）
 * @func 0x1bdcb0 0x1bdd4c  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / CLayerManager::GetTargetRoomObj() / CLayerManager::GetElementFromID(CRoom*, int, CLayer**)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x4×1 / 0x58×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bdcb0 cmp r3, #2
 *   @0x1bdcb4 mov r3, #0
 *   @0x1bdcb8 push {r4, r5, r6, lr}
 *   @0x1bdcbc mov r4, r3
 *   @0x1bdcc0 ldr r5, [sp, #0x10]
 *   @0x1bdcc4 movt r3, #0xbff0
 *   @0x1bdcc8 str r4, [r0, #0xc]
 *   @0x1bdccc str r3, [r0, #0x4]
 *   @0x1bdcd0 str r4, [r0]
 *   @0x1bdcd4 beq 0x1bdcec <_Z16F_TilemapTilesetR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1bdcd8 ldr r0, [pc, #0x58]
 *   @0x1bdcdc mov r1, r4
 *   @0x1bdce0 pop {r4, r5, r6, lr}
 *   @0x1bdce4 add r0, pc, r0
 *   @0x1bdce8 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bdcec bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bdcf0 mov r1, r4
 *   @0x1bdcf4 mov r6, r0
 *   @0x1bdcf8 mov r0, r5
 *   @0x1bdcfc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bdd00 mov r2, r4
 *   @0x1bdd04 mov r1, r0
 *   @0x1bdd08 mov r0, r6
 *   @0x1bdd0c bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bdd10 subs r4, r0, #0
 *   @0x1bdd14 popeq {r4, r5, r6, pc}
 *   @0x1bdd18 ldr r3, [r4]
 *   @0x1bdd1c cmp r3, #5
 *   @0x1bdd20 popne {r4, r5, r6, pc}
 *   @0x1bdd24 mov r0, r5
 *   @0x1bdd28 mov r1, #1
 *   @0x1bdd2c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bdd30 str r0, [r4, #0x1c]
 *   @0x1bdd34 pop {r4, r5, r6, pc}
 *   @0x1bdd38 mulseq r9, r4, r10
 *
 * ══ §160/212 F_TilemapX(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bdd3c  size 140  35 条（0x1bdd3c..0x1bddc8）
 * @func 0x1bdd3c 0x1bddd8  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**) / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x4×1 / 0x58×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bdd3c cmp r3, #2
 *   @0x1bdd40 mov r3, #0
 *   @0x1bdd44 push {r4, r5, r6, lr}
 *   @0x1bdd48 mov r4, r3
 *   @0x1bdd4c ldr r5, [sp, #0x10]
 *   @0x1bdd50 movt r3, #0xbff0
 *   @0x1bdd54 str r4, [r0, #0xc]
 *   @0x1bdd58 str r3, [r0, #0x4]
 *   @0x1bdd5c str r4, [r0]
 *   @0x1bdd60 beq 0x1bdd78 <_Z10F_TilemapXR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1bdd64 ldr r0, [pc, #0x58]
 *   @0x1bdd68 mov r1, r4
 *   @0x1bdd6c pop {r4, r5, r6, lr}
 *   @0x1bdd70 add r0, pc, r0
 *   @0x1bdd74 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bdd78 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bdd7c mov r1, r4
 *   @0x1bdd80 mov r6, r0
 *   @0x1bdd84 mov r0, r5
 *   @0x1bdd88 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bdd8c mov r2, r4
 *   @0x1bdd90 mov r1, r0
 *   @0x1bdd94 mov r0, r6
 *   @0x1bdd98 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bdd9c subs r4, r0, #0
 *   @0x1bdda0 popeq {r4, r5, r6, pc}
 *   @0x1bdda4 ldr r3, [r4]
 *   @0x1bdda8 cmp r3, #5
 *   @0x1bddac popne {r4, r5, r6, pc}
 *   @0x1bddb0 mov r0, r5
 *   @0x1bddb4 mov r1, #1
 *   @0x1bddb8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1bddbc str r0, [r4, #0x20]
 *   @0x1bddc0 pop {r4, r5, r6, pc}
 *   @0x1bddc4 andseq r0, r9, r8, lsr r10
 *
 * ══ §161/212 F_TilemapY(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bddc8  size 140  35 条（0x1bddc8..0x1bde54）
 * @func 0x1bddc8 0x1bde54  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**) / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x4×1 / 0x58×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bddc8 cmp r3, #2
 *   @0x1bddcc mov r3, #0
 *   @0x1bddd0 push {r4, r5, r6, lr}
 *   @0x1bddd4 mov r4, r3
 *   @0x1bddd8 ldr r5, [sp, #0x10]
 *   @0x1bdddc movt r3, #0xbff0
 *   @0x1bdde0 str r4, [r0, #0xc]
 *   @0x1bdde4 str r3, [r0, #0x4]
 *   @0x1bdde8 str r4, [r0]
 *   @0x1bddec beq 0x1bde04 <_Z10F_TilemapYR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1bddf0 ldr r0, [pc, #0x58]
 *   @0x1bddf4 mov r1, r4
 *   @0x1bddf8 pop {r4, r5, r6, lr}
 *   @0x1bddfc add r0, pc, r0
 *   @0x1bde00 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bde04 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bde08 mov r1, r4
 *   @0x1bde0c mov r6, r0
 *   @0x1bde10 mov r0, r5
 *   @0x1bde14 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bde18 mov r2, r4
 *   @0x1bde1c mov r1, r0
 *   @0x1bde20 mov r0, r6
 *   @0x1bde24 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bde28 subs r4, r0, #0
 *   @0x1bde2c popeq {r4, r5, r6, pc}
 *   @0x1bde30 ldr r3, [r4]
 *   @0x1bde34 cmp r3, #5
 *   @0x1bde38 popne {r4, r5, r6, pc}
 *   @0x1bde3c mov r0, r5
 *   @0x1bde40 mov r1, #1
 *   @0x1bde44 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1bde48 str r0, [r4, #0x24]
 *   @0x1bde4c pop {r4, r5, r6, pc}
 *   @0x1bde50 ldrsbeq r0, [r9], -r4
 *
 * ══ §162/212 F_LayerTileChange(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bf4b8  size 140  35 条（0x1bf4b8..0x1bf544）
 * @func 0x1bf4b8 0x1bf554  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / CLayerManager::GetTargetRoomObj() / CLayerManager::GetElementFromID(CRoom*, int, CLayer**)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x4×1 / 0x58×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bf4b8 cmp r3, #2
 *   @0x1bf4bc mov r3, #0
 *   @0x1bf4c0 push {r4, r5, r6, lr}
 *   @0x1bf4c4 mov r4, r3
 *   @0x1bf4c8 ldr r5, [sp, #0x10]
 *   @0x1bf4cc movt r3, #0xbff0
 *   @0x1bf4d0 str r4, [r0, #0xc]
 *   @0x1bf4d4 str r3, [r0, #0x4]
 *   @0x1bf4d8 str r4, [r0]
 *   @0x1bf4dc beq 0x1bf4f4 <_Z17F_LayerTileChangeR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1bf4e0 ldr r0, [pc, #0x58]
 *   @0x1bf4e4 mov r1, r4
 *   @0x1bf4e8 pop {r4, r5, r6, lr}
 *   @0x1bf4ec add r0, pc, r0
 *   @0x1bf4f0 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bf4f4 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bf4f8 mov r1, r4
 *   @0x1bf4fc mov r6, r0
 *   @0x1bf500 mov r0, r5
 *   @0x1bf504 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bf508 mov r2, r4
 *   @0x1bf50c mov r1, r0
 *   @0x1bf510 mov r0, r6
 *   @0x1bf514 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bf518 subs r4, r0, #0
 *   @0x1bf51c popeq {r4, r5, r6, pc}
 *   @0x1bf520 ldr r3, [r4]
 *   @0x1bf524 cmp r3, #7
 *   @0x1bf528 popne {r4, r5, r6, pc}
 *   @0x1bf52c mov r0, r5
 *   @0x1bf530 mov r1, #1
 *   @0x1bf534 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bf538 str r0, [r4, #0x20]
 *   @0x1bf53c pop {r4, r5, r6, pc}
 *   @0x1bf540 ldrheq pc, [r8], -r0
 *
 * ══ §163/212 F_LayerTileXScale(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bf544  size 140  35 条（0x1bf544..0x1bf5d0）
 * @func 0x1bf544 0x1bf5e0  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**) / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x4×1 / 0x58×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bf544 cmp r3, #2
 *   @0x1bf548 mov r3, #0
 *   @0x1bf54c push {r4, r5, r6, lr}
 *   @0x1bf550 mov r4, r3
 *   @0x1bf554 ldr r5, [sp, #0x10]
 *   @0x1bf558 movt r3, #0xbff0
 *   @0x1bf55c str r4, [r0, #0xc]
 *   @0x1bf560 str r3, [r0, #0x4]
 *   @0x1bf564 str r4, [r0]
 *   @0x1bf568 beq 0x1bf580 <_Z17F_LayerTileXScaleR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1bf56c ldr r0, [pc, #0x58]
 *   @0x1bf570 mov r1, r4
 *   @0x1bf574 pop {r4, r5, r6, lr}
 *   @0x1bf578 add r0, pc, r0
 *   @0x1bf57c b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bf580 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bf584 mov r1, r4
 *   @0x1bf588 mov r6, r0
 *   @0x1bf58c mov r0, r5
 *   @0x1bf590 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bf594 mov r2, r4
 *   @0x1bf598 mov r1, r0
 *   @0x1bf59c mov r0, r6
 *   @0x1bf5a0 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bf5a4 subs r4, r0, #0
 *   @0x1bf5a8 popeq {r4, r5, r6, pc}
 *   @0x1bf5ac ldr r3, [r4]
 *   @0x1bf5b0 cmp r3, #7
 *   @0x1bf5b4 popne {r4, r5, r6, pc}
 *   @0x1bf5b8 mov r0, r5
 *   @0x1bf5bc mov r1, #1
 *   @0x1bf5c0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1bf5c4 str r0, [r4, #0x34]
 *   @0x1bf5c8 pop {r4, r5, r6, pc}
 *   @0x1bf5cc andseq pc, r8, r8, asr sp
 *
 * ══ §164/212 F_LayerTileYScale(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bf5d0  size 140  35 条（0x1bf5d0..0x1bf65c）
 * @func 0x1bf5d0 0x1bf65c  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**) / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x4×1 / 0x58×1 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bf5d0 cmp r3, #2
 *   @0x1bf5d4 mov r3, #0
 *   @0x1bf5d8 push {r4, r5, r6, lr}
 *   @0x1bf5dc mov r4, r3
 *   @0x1bf5e0 ldr r5, [sp, #0x10]
 *   @0x1bf5e4 movt r3, #0xbff0
 *   @0x1bf5e8 str r4, [r0, #0xc]
 *   @0x1bf5ec str r3, [r0, #0x4]
 *   @0x1bf5f0 str r4, [r0]
 *   @0x1bf5f4 beq 0x1bf60c <_Z17F_LayerTileYScaleR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1bf5f8 ldr r0, [pc, #0x58]
 *   @0x1bf5fc mov r1, r4
 *   @0x1bf600 pop {r4, r5, r6, lr}
 *   @0x1bf604 add r0, pc, r0
 *   @0x1bf608 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bf60c bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bf610 mov r1, r4
 *   @0x1bf614 mov r6, r0
 *   @0x1bf618 mov r0, r5
 *   @0x1bf61c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bf620 mov r2, r4
 *   @0x1bf624 mov r1, r0
 *   @0x1bf628 mov r0, r6
 *   @0x1bf62c bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bf630 subs r4, r0, #0
 *   @0x1bf634 popeq {r4, r5, r6, pc}
 *   @0x1bf638 ldr r3, [r4]
 *   @0x1bf63c cmp r3, #7
 *   @0x1bf640 popne {r4, r5, r6, pc}
 *   @0x1bf644 mov r0, r5
 *   @0x1bf648 mov r1, #1
 *   @0x1bf64c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1bf650 str r0, [r4, #0x38]
 *   @0x1bf654 pop {r4, r5, r6, pc}
 *   @0x1bf658 andseq pc, r8, r0, lsl #26
 *
 * ══ §165/212 F_LayerTileAlpha(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bf6f0  size 140  35 条（0x1bf6f0..0x1bf77c）
 * @func 0x1bf6f0 0x1bf78c  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**) / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x4×1 / 0x58×1 / 0x44×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bf6f0 cmp r3, #2
 *   @0x1bf6f4 mov r3, #0
 *   @0x1bf6f8 push {r4, r5, r6, lr}
 *   @0x1bf6fc mov r4, r3
 *   @0x1bf700 ldr r5, [sp, #0x10]
 *   @0x1bf704 movt r3, #0xbff0
 *   @0x1bf708 str r4, [r0, #0xc]
 *   @0x1bf70c str r3, [r0, #0x4]
 *   @0x1bf710 str r4, [r0]
 *   @0x1bf714 beq 0x1bf72c <_Z16F_LayerTileAlphaR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1bf718 ldr r0, [pc, #0x58]
 *   @0x1bf71c mov r1, r4
 *   @0x1bf720 pop {r4, r5, r6, lr}
 *   @0x1bf724 add r0, pc, r0
 *   @0x1bf728 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bf72c bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bf730 mov r1, r4
 *   @0x1bf734 mov r6, r0
 *   @0x1bf738 mov r0, r5
 *   @0x1bf73c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bf740 mov r2, r4
 *   @0x1bf744 mov r1, r0
 *   @0x1bf748 mov r0, r6
 *   @0x1bf74c bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bf750 subs r4, r0, #0
 *   @0x1bf754 popeq {r4, r5, r6, pc}
 *   @0x1bf758 ldr r3, [r4]
 *   @0x1bf75c cmp r3, #7
 *   @0x1bf760 popne {r4, r5, r6, pc}
 *   @0x1bf764 mov r0, r5
 *   @0x1bf768 mov r1, #1
 *   @0x1bf76c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1bf770 str r0, [r4, #0x44]
 *   @0x1bf774 pop {r4, r5, r6, pc}
 *   @0x1bf778 andseq pc, r8, r8, asr #24
 *
 * ══ §166/212 F_LayerTileX(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bf77c  size 140  35 条（0x1bf77c..0x1bf808）
 * @func 0x1bf77c 0x1bf818  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**) / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x4×1 / 0x58×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bf77c cmp r3, #2
 *   @0x1bf780 mov r3, #0
 *   @0x1bf784 push {r4, r5, r6, lr}
 *   @0x1bf788 mov r4, r3
 *   @0x1bf78c ldr r5, [sp, #0x10]
 *   @0x1bf790 movt r3, #0xbff0
 *   @0x1bf794 str r4, [r0, #0xc]
 *   @0x1bf798 str r3, [r0, #0x4]
 *   @0x1bf79c str r4, [r0]
 *   @0x1bf7a0 beq 0x1bf7b8 <_Z12F_LayerTileXR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1bf7a4 ldr r0, [pc, #0x58]
 *   @0x1bf7a8 mov r1, r4
 *   @0x1bf7ac pop {r4, r5, r6, lr}
 *   @0x1bf7b0 add r0, pc, r0
 *   @0x1bf7b4 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bf7b8 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bf7bc mov r1, r4
 *   @0x1bf7c0 mov r6, r0
 *   @0x1bf7c4 mov r0, r5
 *   @0x1bf7c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bf7cc mov r2, r4
 *   @0x1bf7d0 mov r1, r0
 *   @0x1bf7d4 mov r0, r6
 *   @0x1bf7d8 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bf7dc subs r4, r0, #0
 *   @0x1bf7e0 popeq {r4, r5, r6, pc}
 *   @0x1bf7e4 ldr r3, [r4]
 *   @0x1bf7e8 cmp r3, #7
 *   @0x1bf7ec popne {r4, r5, r6, pc}
 *   @0x1bf7f0 mov r0, r5
 *   @0x1bf7f4 mov r1, #1
 *   @0x1bf7f8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1bf7fc str r0, [r4, #0x24]
 *   @0x1bf800 pop {r4, r5, r6, pc}
 *   @0x1bf804 ldrsheq pc, [r8], -r0
 *
 * ══ §167/212 F_LayerTileY(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bf808  size 140  35 条（0x1bf808..0x1bf894）
 * @func 0x1bf808 0x1bf894  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**) / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x4×1 / 0x58×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bf808 cmp r3, #2
 *   @0x1bf80c mov r3, #0
 *   @0x1bf810 push {r4, r5, r6, lr}
 *   @0x1bf814 mov r4, r3
 *   @0x1bf818 ldr r5, [sp, #0x10]
 *   @0x1bf81c movt r3, #0xbff0
 *   @0x1bf820 str r4, [r0, #0xc]
 *   @0x1bf824 str r3, [r0, #0x4]
 *   @0x1bf828 str r4, [r0]
 *   @0x1bf82c beq 0x1bf844 <_Z12F_LayerTileYR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1bf830 ldr r0, [pc, #0x58]
 *   @0x1bf834 mov r1, r4
 *   @0x1bf838 pop {r4, r5, r6, lr}
 *   @0x1bf83c add r0, pc, r0
 *   @0x1bf840 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bf844 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bf848 mov r1, r4
 *   @0x1bf84c mov r6, r0
 *   @0x1bf850 mov r0, r5
 *   @0x1bf854 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bf858 mov r2, r4
 *   @0x1bf85c mov r1, r0
 *   @0x1bf860 mov r0, r6
 *   @0x1bf864 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bf868 subs r4, r0, #0
 *   @0x1bf86c popeq {r4, r5, r6, pc}
 *   @0x1bf870 ldr r3, [r4]
 *   @0x1bf874 cmp r3, #7
 *   @0x1bf878 popne {r4, r5, r6, pc}
 *   @0x1bf87c mov r0, r5
 *   @0x1bf880 mov r1, #1
 *   @0x1bf884 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1bf888 str r0, [r4, #0x28]
 *   @0x1bf88c pop {r4, r5, r6, pc}
 *   @0x1bf890 mulseq r8, r4, r11
 *
 * ══ §168/212 F_Shader_Is_Compiled(RValue&, CInstance*, CInstance*, int, RValue*)  0x1e0fcc  size 140  35 条（0x1e0fcc..0x1e1058）
 * @func 0x1e0fcc 0x1e1058  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_Shader_Is_Compiled(RValue&, CInstance*, CInstance*, int, RValue*)+0x6c
 * 字段偏移 top8: 0x8×1 / 0xc×1 / 0x4×1 / 0x48×1 / 0x38×1 / 0x2×1 / 0x54×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e0fcc push {r4, lr}
 *   @0x1e0fd0 mov r3, #0
 *   @0x1e0fd4 ldr r2, [sp, #0x8]
 *   @0x1e0fd8 mov r4, r0
 *   @0x1e0fdc str r3, [r0, #0xc]
 *   @0x1e0fe0 mov r1, r3
 *   @0x1e0fe4 str r3, [r0]
 *   @0x1e0fe8 str r3, [r0, #0x4]
 *   @0x1e0fec mov r0, r2
 *   @0x1e0ff0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1e0ff4 cmp r0, #0
 *   @0x1e0ff8 blt 0x1e1038 <_Z20F_Shader_Is_CompiledR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x1e0ffc ldr r3, [pc, #0x48]
 *   @0x1e1000 ldr r3, [pc, r3]
 *   @0x1e1004 ldr r3, [r3]
 *   @0x1e1008 cmp r0, r3
 *   @0x1e100c bge 0x1e1038 <_Z20F_Shader_Is_CompiledR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x1e1010 ldr r3, [pc, #0x38]
 *   @0x1e1014 ldr r3, [pc, r3]
 *   @0x1e1018 ldr r3, [r3]
 *   @0x1e101c ldr r3, [r3, r0, lsl #2]
 *   @0x1e1020 ldr r3, [r3, #0x54]
 *   @0x1e1024 cmp r3, #0
 *   @0x1e1028 streq r3, [r4]
 *   @0x1e102c movteq r3, #0x3ff0
 *   @0x1e1030 streq r3, [r4, #0x4]
 *   @0x1e1034 pop {r4, pc}
 *   @0x1e1038 ldr r0, [pc, #0x14]
 *   @0x1e103c mov r1, #0
 *   @0x1e1040 pop {r4, lr}
 *   @0x1e1044 add r0, pc, r0
 *   @0x1e1048 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1e104c eoreq pc, r0, r4, asr #26
 *   @0x1e1050 eoreq pc, r0, r4, lsr sp
 *   @0x1e1054 andseq r0, r7, r0, lsr sp
 *
 * ══ §169/212 CVariableList::SetVar(int, int, RValue*)  0x1f539c  size 140  35 条（0x1f539c..0x1f5428）
 * @func 0x1f539c 0x1f5428  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CVariableList::Alloc(int) / CVariableList::Add(RVariable*)
 * 字段偏移 top8: 0x8×2 / 0x78×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f539c push {r3, r4, r5, r6, r7, lr}
 *   @0x1f53a0 and r4, r1, #3
 *   @0x1f53a4 ldr r12, [pc, #0x78]
 *   @0x1f53a8 mov r7, r3
 *   @0x1f53ac add r4, r0, r4, lsl #2
 *   @0x1f53b0 mov r3, #0
 *   @0x1f53b4 ldr r12, [pc, r12]
 *   @0x1f53b8 mov r5, r0
 *   @0x1f53bc ldr r4, [r4, #0x4]
 *   @0x1f53c0 mov r6, r2
 *   @0x1f53c4 strb r3, [r12]
 *   @0x1f53c8 cmp r4, r3
 *   @0x1f53cc beq 0x1f53f8 <_ZN13CVariableList6SetVarEiiP6RValue+0x5c>
 *   @0x1f53d0 ldr r3, [r4, #0x8]
 *   @0x1f53d4 cmp r3, r1
 *   @0x1f53d8 bne 0x1f53ec <_ZN13CVariableList6SetVarEiiP6RValue+0x50>
 *   @0x1f53dc b 0x1f5410 <_ZN13CVariableList6SetVarEiiP6RValue+0x74>
 *   @0x1f53e0 ldr r12, [r4, #0x8]
 *   @0x1f53e4 cmp r12, r1
 *   @0x1f53e8 beq 0x1f5410 <_ZN13CVariableList6SetVarEiiP6RValue+0x74>
 *   @0x1f53ec ldr r4, [r4]
 *   @0x1f53f0 cmp r4, #0
 *   @0x1f53f4 bne 0x1f53e0 <_ZN13CVariableList6SetVarEiiP6RValue+0x44>
 *   @0x1f53f8 mov r0, r1
 *   @0x1f53fc bl 0x1f50cc <_ZN13CVariableList5AllocEi>
 *   @0x1f5400 mov r4, r0
 *   @0x1f5404 mov r0, r5
 *   @0x1f5408 mov r1, r4
 *   @0x1f540c bl 0x1f51e8 <_ZN13CVariableList3AddEP9RVariable>
 *   @0x1f5410 add r0, r4, #24
 *   @0x1f5414 mov r1, r7
 *   @0x1f5418 mov r2, r6
 *   @0x1f541c pop {r3, r4, r5, r6, r7, lr}
 *   @0x1f5420 b 0xd0b24 <_Z10SET_RValueP6RValueS0_i>
 *   @0x1f5424 andseq r8, pc, r0, asr #15
 *
 * ══ §170/212 GetRecorderFromDevice(int)  0x21c254  size 140  35 条（0x21c254..0x21c2e0）
 * @func 0x21c254 0x21c2e0  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GetRecorderFromDevice(int)+0x78 / 0xb6574
 * 字段偏移 top8: 0x4×2 / 0x54×2 / 0x7c×1 / 0x2×1 / 0x50×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21c254 ldr r3, [pc, #0x7c]
 *   @0x21c258 push {r4, r5, r6, r7, r8, lr}
 *   @0x21c25c ldr r3, [pc, r3]
 *   @0x21c260 ldr r2, [r3]
 *   @0x21c264 cmp r0, r2
 *   @0x21c268 bge 0x21c2cc <_Z21GetRecorderFromDevicei+0x78>
 *   @0x21c26c ldr r3, [r3, #0x4]
 *   @0x21c270 ldr r8, [r3, r0, lsl #2]
 *   @0x21c274 cmp r8, #0
 *   @0x21c278 moveq r5, r8
 *   @0x21c27c beq 0x21c2d0 <_Z21GetRecorderFromDevicei+0x7c>
 *   @0x21c280 ldr r3, [pc, #0x54]
 *   @0x21c284 add r3, pc, r3
 *   @0x21c288 ldr r6, [r3, #0x50]
 *   @0x21c28c cmp r6, #0
 *   @0x21c290 ble 0x21c2cc <_Z21GetRecorderFromDevicei+0x78>
 *   @0x21c294 ldr r7, [r3, #0x54]
 *   @0x21c298 mov r4, #0
 *   @0x21c29c sub r7, r7, #4
 *   @0x21c2a0 ldr r5, [r7, #0x4]!
 *   @0x21c2a4 add r4, r4, #1
 *   @0x21c2a8 cmp r5, #0
 *   @0x21c2ac beq 0x21c2c4 <_Z21GetRecorderFromDevicei+0x70>
 *   @0x21c2b0 ldr r0, [r8]
 *   @0x21c2b4 ldr r1, [r5, #0x8]
 *   @0x21c2b8 bl 0xb6574 <strcmp@plt>
 *   @0x21c2bc cmp r0, #0
 *   @0x21c2c0 beq 0x21c2d0 <_Z21GetRecorderFromDevicei+0x7c>
 *   @0x21c2c4 cmp r4, r6
 *   @0x21c2c8 bne 0x21c2a0 <_Z21GetRecorderFromDevicei+0x4c>
 *   @0x21c2cc mov r5, #0
 *   @0x21c2d0 mov r0, r5
 *   @0x21c2d4 pop {r4, r5, r6, r7, r8, pc}
 *   @0x21c2d8 mulseq sp, r12, r1
 *   @0x21c2dc subseq r9, r3, r0, lsl r0
 *
 * ══ §171/212 CPhysicsObject::SetAngularVelocity(float)  0x236f44  size 140  35 条（0x236f44..0x236fd0）
 * @func 0x236f44 0x236fd0  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsObject::SetAngularVelocity(float)+0x58
 * 字段偏移 top8: 0x4×2
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x236f44 ldr r3, [r0]
 *   @0x236f48 vmov s15, r1
 *   @0x236f4c ldr r2, [r3]
 *   @0x236f50 cmp r2, #0
 *   @0x236f54 beq 0x236fb8 <_ZN14CPhysicsObject18SetAngularVelocityEf+0x74>
 *   @0x236f58 vldr s14, [pc, #104]
 *   @0x236f5c vmul.f32 s15, s15, s14
 *   @0x236f60 vldr s14, [pc, #100]
 *   @0x236f64 ldrh r1, [r3, #4]
 *   @0x236f68 mov r0, #0
 *   @0x236f6c and r2, r1, #2
 *   @0x236f70 uxth r2, r2
 *   @0x236f74 vdiv.f32 s15, s15, s14
 *   @0x236f78 vmul.f32 s14, s15, s15
 *   @0x236f7c vcmpe.f32 s14, #0
 *   @0x236f80 vmrs APSR_nzcv, fpscr
 *   @0x236f84 ble 0x236f9c <_ZN14CPhysicsObject18SetAngularVelocityEf+0x58>
 *   @0x236f88 cmp r2, #0
 *   @0x236f8c streq r0, [r3, #0xa0]
 *   @0x236f90 orreq r1, r1, #2
 *   @0x236f94 strheq r1, [r3, #4]
 *   @0x236f98 moveq r2, #2
 *   @0x236f9c vstr s15, [r3, #88]
 *   @0x236fa0 cmp r2, #0
 *   @0x236fa4 orreq r1, r1, #2
 *   @0x236fa8 strheq r1, [r3, #4]
 *   @0x236fac moveq r2, #0
 *   @0x236fb0 streq r2, [r3, #0xa0]
 *   @0x236fb4 bx lr
 *   @0x236fb8 ldrh r1, [r3, #4]
 *   @0x236fbc and r2, r1, #2
 *   @0x236fc0 uxth r2, r2
 *   @0x236fc4 b 0x236fa0 <_ZN14CPhysicsObject18SetAngularVelocityEf+0x5c>
 *   @0x236fc8 ldrdmi r0, r1, [r9], #-251
 *   @0x236fcc teqmi r4, #0
 *
 * ══ §172/212 CPhysicsWorld::GetCurrentContactNormal(CInstance*, int, float&, float&)  0x238d9c  size 140  35 条（0x238d9c..0x238e28）
 * @func 0x238d9c 0x238e28  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsWorld::GetValidCollisionData(CInstance*) / CPhysicsWorld::GetCurrentContactNormal(CInstance*, int, float&, float&)+0x5c
 * 字段偏移 top8: 0x48×1 / 0x88×1 / 0x20c×1 / 0x210×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x238d9c push {r4, r5, r6, r7, r8, lr}
 *   @0x238da0 mov r7, r2
 *   @0x238da4 mov r8, r3
 *   @0x238da8 bl 0x238cb0 <_ZN13CPhysicsWorld21GetValidCollisionDataEP9CInstance>
 *   @0x238dac subs r2, r0, #0
 *   @0x238db0 beq 0x238df8 <_ZN13CPhysicsWorld23GetCurrentContactNormalEP9CInstanceiRfS2_+0x5c>
 *   @0x238db4 ldr r6, [r2]
 *   @0x238db8 cmp r6, #0
 *   @0x238dbc ble 0x238df8 <_ZN13CPhysicsWorld23GetCurrentContactNormalEP9CInstanceiRfS2_+0x5c>
 *   @0x238dc0 ldr r12, [r2, #0x48]
 *   @0x238dc4 cmp r7, r12
 *   @0x238dc8 movgt r4, r2
 *   @0x238dcc movgt r1, #0
 *   @0x238dd0 bgt 0x238dec <_ZN13CPhysicsWorld23GetCurrentContactNormalEP9CInstanceiRfS2_+0x50>
 *   @0x238dd4 b 0x238e00 <_ZN13CPhysicsWorld23GetCurrentContactNormalEP9CInstanceiRfS2_+0x64>
 *   @0x238dd8 ldr r5, [r4, #0x88]
 *   @0x238ddc add r4, r4, #64
 *   @0x238de0 add r12, r12, r5
 *   @0x238de4 cmp r12, r7
 *   @0x238de8 bge 0x238e04 <_ZN13CPhysicsWorld23GetCurrentContactNormalEP9CInstanceiRfS2_+0x68>
 *   @0x238dec add r1, r1, #1
 *   @0x238df0 cmp r1, r6
 *   @0x238df4 bne 0x238dd8 <_ZN13CPhysicsWorld23GetCurrentContactNormalEP9CInstanceiRfS2_+0x3c>
 *   @0x238df8 mov r0, #0
 *   @0x238dfc pop {r4, r5, r6, r7, r8, pc}
 *   @0x238e00 mov r1, #0
 *   @0x238e04 add r1, r1, r1, lsl #1
 *   @0x238e08 mov r0, #1
 *   @0x238e0c add r2, r2, r1, lsl #3
 *   @0x238e10 ldr r3, [r2, #0x20c]
 *   @0x238e14 str r3, [r8]
 *   @0x238e18 ldr r3, [r2, #0x210]
 *   @0x238e1c ldr r2, [sp, #0x18]
 *   @0x238e20 str r3, [r2]
 *   @0x238e24 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §173/212 F_JS_IsNaN(RValue&, CInstance*, CInstance*, int, RValue*)  0x24d7e8  size 140  35 条（0x24d7e8..0x24d874）
 * @func 0x24d7e8 0x24d874  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_JS_ToNumber(RValue&, RValue&)
 * 字段偏移 top8: 0xc×2 / 0x28×1 / 0x8×1 / 0x4×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x24d7e8 push {r4, r5, r6, r7, lr}
 *   @0x24d7ec sub sp, sp, #20
 *   @0x24d7f0 mov r6, r0
 *   @0x24d7f4 mov r2, #0
 *   @0x24d7f8 ldr r1, [sp, #0x28]
 *   @0x24d7fc mov r0, sp
 *   @0x24d800 mov r7, #0
 *   @0x24d804 mov r3, #0
 *   @0x24d808 str r7, [sp, #0x8]
 *   @0x24d80c strd r2, r3, [sp]
 *   @0x24d810 mvn r3, #-16777216
 *   @0x24d814 str r3, [sp, #0xc]
 *   @0x24d818 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_>
 *   @0x24d81c ldrd r2, r3, [sp]
 *   @0x24d820 mov r1, #13
 *   @0x24d824 str r7, [r6]
 *   @0x24d828 str r7, [r6, #0x4]
 *   @0x24d82c vmov d6, r2, r3
 *   @0x24d830 str r1, [r6, #0xc]
 *   @0x24d834 vcmp.f64 d6, d6
 *   @0x24d838 vmrs APSR_nzcv, fpscr
 *   @0x24d83c bvs 0x24d848 <_Z10F_JS_IsNaNR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0x24d840 add sp, sp, #20
 *   @0x24d844 pop {r4, r5, r6, r7, pc}
 *   @0x24d848 movw r5, #0xffff
 *   @0x24d84c movt r5, #0xf
 *   @0x24d850 and r3, r3, r5
 *   @0x24d854 mvn r4, #0
 *   @0x24d858 and r2, r2, r4
 *   @0x24d85c orrs r1, r2, r3
 *   @0x24d860 movne r3, r7
 *   @0x24d864 movtne r3, #0x3ff0
 *   @0x24d868 strne r3, [r6, #0x4]
 *   @0x24d86c add sp, sp, #20
 *   @0x24d870 pop {r4, r5, r6, r7, pc}
 *
 * ══ §174/212 _readFile  0x285cd8  size 140  35 条（0x285cd8..0x285d64）
 * @func 0x285cd8 0x285d64  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb68d4×2 / 0xb6844 / 0xb68e0 / _malloc / 0xb68c8 / 0xb6850
 * 字段偏移 top8: 0x74×1 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x285cd8 push {r4, r5, r6, lr}
 *   @0x285cdc mov r5, r1
 *   @0x285ce0 ldr r1, [pc, #0x74]
 *   @0x285ce4 add r1, pc, r1
 *   @0x285ce8 bl 0xb6844 <fopen@plt>
 *   @0x285cec subs r4, r0, #0
 *   @0x285cf0 beq 0x285d54 <_readFile+0x7c>
 *   @0x285cf4 mov r1, #0
 *   @0x285cf8 mov r2, #2
 *   @0x285cfc bl 0xb68d4 <fseek@plt>
 *   @0x285d00 mov r0, r4
 *   @0x285d04 bl 0xb68e0 <ftell@plt>
 *   @0x285d08 mov r1, #0
 *   @0x285d0c mov r2, r1
 *   @0x285d10 str r0, [r5]
 *   @0x285d14 mov r0, r4
 *   @0x285d18 bl 0xb68d4 <fseek@plt>
 *   @0x285d1c ldr r1, [pc, #0x3c]
 *   @0x285d20 ldr r0, [r5]
 *   @0x285d24 mov r2, #74
 *   @0x285d28 add r1, pc, r1
 *   @0x285d2c bl 0x285c10 <_malloc>
 *   @0x285d30 ldr r2, [r5]
 *   @0x285d34 mov r1, #1
 *   @0x285d38 mov r3, r4
 *   @0x285d3c mov r6, r0
 *   @0x285d40 bl 0xb68c8 <fread@plt>
 *   @0x285d44 mov r0, r4
 *   @0x285d48 bl 0xb6850 <fclose@plt>
 *   @0x285d4c mov r0, r6
 *   @0x285d50 pop {r4, r5, r6, pc}
 *   @0x285d54 mov r0, r4
 *   @0x285d58 pop {r4, r5, r6, pc}
 *   @0x285d5c andeq r1, r11, r4, lsl pc
 *   @0x285d60 ldrdeq r1, r2, [sp], -r12
 *
 * ══ §175/212 yyServer::yyServer(bool)  0x2970f8  size 140  35 条（0x2970f8..0x297184）
 * @func 0x2970f8 0x297184  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool) / yySocket::Startup()
 * 字段偏移 top8: 0x1d×1 / 0x6c×1 / 0x4×1 / 0x8×1 / 0x4c×1 / 0x1c×1 / 0x20×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2970f8 push {r4, r5, r6, lr}
 *   @0x2970fc mov r4, r0
 *   @0x297100 strb r1, [r0, #0x1d]
 *   @0x297104 mov r5, #0
 *   @0x297108 ldr r1, [pc, #0x6c]
 *   @0x29710c mov r2, #72
 *   @0x297110 mov r3, #1
 *   @0x297114 mov r0, #65536
 *   @0x297118 add r1, pc, r1
 *   @0x29711c str r5, [r4]
 *   @0x297120 str r5, [r4, #0x4]
 *   @0x297124 str r5, [r4, #0x8]
 *   @0x297128 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x29712c ldr r6, [pc, #0x4c]
 *   @0x297130 mov r12, #65536
 *   @0x297134 mov r2, #131072
 *   @0x297138 ldr r6, [pc, r6]
 *   @0x29713c movw r3, #0x3f6
 *   @0x297140 strb r5, [r4, #0x1c]
 *   @0x297144 ldrb r1, [r6]
 *   @0x297148 str r5, [r4, #0x20]
 *   @0x29714c cmp r1, r5
 *   @0x297150 str r5, [r4, #0x28]
 *   @0x297154 str r12, [r4, #0x10]
 *   @0x297158 str r2, [r4, #0x14]
 *   @0x29715c str r3, [r4, #0x24]
 *   @0x297160 str r0, [r4, #0xc]
 *   @0x297164 bne 0x297174 <_ZN8yyServerC2Eb+0x7c>
 *   @0x297168 bl 0x294d18 <_ZN8yySocket7StartupEv>
 *   @0x29716c mov r3, #1
 *   @0x297170 strb r3, [r6]
 *   @0x297174 mov r0, r4
 *   @0x297178 pop {r4, r5, r6, pc}
 *   @0x29717c andeq r2, r12, r12, lsl #8
 *   @0x297180 andseq r10, r5, r4, ror #16
 *
 * ══ §176/212 png_set_crc_action  0x2a809c  size 140  35 条（0x2a809c..0x2a8128）
 * @func 0x2a809c 0x2a8128  size 140  35 条
 * 部分覆盖: 本节 35/56 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_warning
 * 字段偏移 top8: 0x54×1 / 0x300×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a809c push {r3, r4, r5, lr}
 *   @0x2a80a0 mov r4, r0
 *   @0x2a80a4 beq 0x2a8122 <png_set_crc_action+0x86>
 *   @0x2a80a8 cmp r1, #0x3
 *   @0x2a80ac tbb [pc, r1]
 *   @0x2a80b0 lsls r6, r1, #0x8
 *   @0x2a80b4 ldr.w r3, [r0, #0x130]
 *   @0x2a80b8 bic r3, r3, #0xc00
 *   @0x2a80bc orr r3, r3, #0x400
 *   @0x2a80c0 b 0x2a80dc <png_set_crc_action+0x40>
 *   @0x2a80c4 vst4.8 {d19, d21, d23, d25}, [r3:256], r0
 *   @0x2a80c8 and r6, r7, r0, asr #6
 *   @0x2a80cc ldr r1, [pc, #0x54]
 *   @0x2a80d0 bl 0x2a6474 <png_warning>
 *   @0x2a80d4 ldr.w r3, [r4, #0x130]
 *   @0x2a80d8 bic r3, r3, #0xc00
 *   @0x2a80dc str.w r3, [r4, #0x130]
 *   @0x2a80e0 subs r2, r5, #0x1
 *   @0x2a80e4 bhi 0x2a8116 <png_set_crc_action+0x7a>
 *   @0x2a80e8 strne pc, [pc], -r2
 *   @0x2a80ec lsrs r3, r0, #0x8
 *   @0x2a80f0 ldr.w r3, [r4, #0x130]
 *   @0x2a80f4 bic r3, r3, #0x300
 *   @0x2a80f8 orr r3, r3, #0x100
 *   @0x2a80fc b 0x2a811e <png_set_crc_action+0x82>
 *   @0x2a8100 vst4.8 {d19, d21, d23, d25}, [r3:256], r0
 *   @0x2a8104 and r7, r10, r0, asr #6
 *   @0x2a8108 ldr.w r3, [r4, #0x130]
 *   @0x2a810c bic r3, r3, #0x300
 *   @0x2a8110 orr r3, r3, #0x200
 *   @0x2a8114 b 0x2a811e <png_set_crc_action+0x82>
 *   @0x2a8118 vld4.8 {d3, d5, d7, d9}, [r3:256], r0
 *   @0x2a811c .word 0xf8c47340
 *   @0x2a8120 ldclt p1, c3, [r8, #-192]!
 *   @0x2a8124 ldr r0, [pc, #0x300]
 *
 * ══ §177/212 b2RevoluteJointDef::Initialize(b2Body*, b2Body*, b2Vec2 const&)  0x2d1fd8  size 140  35 条（0x2d1fd8..0x2d2064）
 * @func 0x2d1fd8 0x2d2064  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1 / 0xc×1
 * VFP 指令 32 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d1fd8 vldr s15, [r1, #16]
 *   @0x2d1fdc vldr s14, [r3, #4]
 *   @0x2d1fe0 vsub.f32 s14, s14, s15
 *   @0x2d1fe4 vldr s9, [r1, #20]
 *   @0x2d1fe8 vldr s8, [r1, #24]
 *   @0x2d1fec vldr s4, [r3]
 *   @0x2d1ff0 vldr s10, [r1, #12]
 *   @0x2d1ff4 vldr s12, [r2, #20]
 *   @0x2d1ff8 vldr s11, [r2, #24]
 *   @0x2d1ffc vldr s15, [r2, #16]
 *   @0x2d2000 vldr s5, [r2, #12]
 *   @0x2d2004 vldr s6, [r2, #72]
 *   @0x2d2008 vldr s7, [r1, #72]
 *   @0x2d200c str r1, [r0, #0x8]
 *   @0x2d2010 str r2, [r0, #0xc]
 *   @0x2d2014 vmul.f32 s13, s14, s9
 *   @0x2d2018 vmul.f32 s14, s14, s8
 *   @0x2d201c vsub.f32 s10, s4, s10
 *   @0x2d2020 vmla.f32 s13, s10, s8
 *   @0x2d2024 vmls.f32 s14, s9, s10
 *   @0x2d2028 vstr s13, [r0, #20]
 *   @0x2d202c vstr s14, [r0, #24]
 *   @0x2d2030 vldr s14, [r3, #4]
 *   @0x2d2034 vsub.f32 s15, s14, s15
 *   @0x2d2038 vldr s13, [r3]
 *   @0x2d203c vmul.f32 s14, s15, s12
 *   @0x2d2040 vsub.f32 s13, s13, s5
 *   @0x2d2044 vmul.f32 s15, s15, s11
 *   @0x2d2048 vmla.f32 s14, s13, s11
 *   @0x2d204c vmls.f32 s15, s12, s13
 *   @0x2d2050 vstr s14, [r0, #28]
 *   @0x2d2054 vsub.f32 s14, s6, s7
 *   @0x2d2058 vstr s15, [r0, #32]
 *   @0x2d205c vstr s14, [r0, #36]
 *   @0x2d2060 bx lr
 *
 * ══ §178/212 b2WeldJointDef::Initialize(b2Body*, b2Body*, b2Vec2 const&)  0x2d3698  size 140  35 条（0x2d3698..0x2d3724）
 * @func 0x2d3698 0x2d3724  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1 / 0xc×1
 * VFP 指令 32 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d3698 vldr s15, [r1, #16]
 *   @0x2d369c vldr s14, [r3, #4]
 *   @0x2d36a0 vsub.f32 s14, s14, s15
 *   @0x2d36a4 vldr s9, [r1, #20]
 *   @0x2d36a8 vldr s8, [r1, #24]
 *   @0x2d36ac vldr s4, [r3]
 *   @0x2d36b0 vldr s10, [r1, #12]
 *   @0x2d36b4 vldr s12, [r2, #20]
 *   @0x2d36b8 vldr s11, [r2, #24]
 *   @0x2d36bc vldr s15, [r2, #16]
 *   @0x2d36c0 vldr s5, [r2, #12]
 *   @0x2d36c4 vldr s6, [r2, #72]
 *   @0x2d36c8 vldr s7, [r1, #72]
 *   @0x2d36cc str r1, [r0, #0x8]
 *   @0x2d36d0 str r2, [r0, #0xc]
 *   @0x2d36d4 vmul.f32 s13, s14, s9
 *   @0x2d36d8 vmul.f32 s14, s14, s8
 *   @0x2d36dc vsub.f32 s10, s4, s10
 *   @0x2d36e0 vmla.f32 s13, s10, s8
 *   @0x2d36e4 vmls.f32 s14, s9, s10
 *   @0x2d36e8 vstr s13, [r0, #20]
 *   @0x2d36ec vstr s14, [r0, #24]
 *   @0x2d36f0 vldr s14, [r3, #4]
 *   @0x2d36f4 vsub.f32 s15, s14, s15
 *   @0x2d36f8 vldr s13, [r3]
 *   @0x2d36fc vmul.f32 s14, s15, s12
 *   @0x2d3700 vsub.f32 s13, s13, s5
 *   @0x2d3704 vmul.f32 s15, s15, s11
 *   @0x2d3708 vmla.f32 s14, s13, s11
 *   @0x2d370c vmls.f32 s15, s12, s13
 *   @0x2d3710 vstr s14, [r0, #28]
 *   @0x2d3714 vsub.f32 s14, s6, s7
 *   @0x2d3718 vstr s15, [r0, #32]
 *   @0x2d371c vstr s14, [r0, #36]
 *   @0x2d3720 bx lr
 *
 * ══ §179/212 png_do_write_invert_alpha  0x2b0d32  size 138  35 条（0x2b0d32..0x2b0dbc）
 * @func 0x2b0d32 0x2b0dbe  size 140  35 条
 * 部分覆盖: 本节 35/64 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x-1×4 / 0x18×2 / 0x8×1 / 0x9×1 / 0x2×1 / 0x-2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b0d32 ldrb r3, [r0, #0x8]
 *   @0x2b0d36 bne 0x2b0d76 <png_do_write_invert_alpha+0x44>
 *   @0x2b0d3a ldr r2, [r0]
 *   @0x2b0d3e mov.w r3, #0x0
 *   @0x2b0d42 bne 0x2b0d58 <png_do_write_invert_alpha+0x26>
 *   @0x2b0d46 beq 0x2b0d56 <png_do_write_invert_alpha+0x24>
 *   @0x2b0d4a adds r3, #0x1
 *   @0x2b0d4e mvns r0, r0
 *   @0x2b0d52 ldrb r0, [r6, r1, lsl #24]!
 *   @0x2b0d56 bx lr
 *   @0x2b0d5a beq 0x2b0d74 <png_do_write_invert_alpha+0x42>
 *   @0x2b0d5e adds r3, #0x1
 *   @0x2b0d62 mvns r0, r0
 *   @0x2b0d66 .word 0xf8110c02
 *   @0x2b0d6a bicmi r0, r0, #256
 *   @0x2b0d6e strb r0, [r1, #-1]
 *   @0x2b0d72 b 0x2b0d58 <png_do_write_invert_alpha+0x26>
 *   @0x2b0d76 cmp r3, #0x4
 *   @0x2b0d7a ldrb r3, [r0, #0x9]
 *   @0x2b0d7e cmp r3, #0x8
 *   @0x2b0d82 .word 0xd10b0300
 *   @0x2b0d86 cmp r3, r2
 *   @0x2b0d8a andle r0, r6, r2, lsl #2
 *   @0x2b0d8e ldrb r0, [r1, #-1]
 *   @0x2b0d92 adds r3, #0x1
 *   @0x2b0d96 strb r0, [r1, #-1]
 *   @0x2b0d9a b 0x2b0d86 <png_do_write_invert_alpha+0x54>
 *   @0x2b0d9e cmp r3, r2
 *   @0x2b0da2 ldrb r0, [r1, #0x2]
 *   @0x2b0da6 adds r1, #0x4
 *   @0x2b0daa strb r0, [r1, #-2]
 *   @0x2b0dae ldrb r0, [r1, #-1]
 *   @0x2b0db2 mvns r0, r0
 *   @0x2b0db6 ldrb r0, [r1, r1, lsl #24]!
 *   @0x2b0dba bx lr
 *
 * ══ §180/212 Background_Find(char const*)  0xc370c  size 136  34 条（0xc370c..0xc3794）
 * @func 0xc370c 0xc3794  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Background_Find(char const*)+0x6c / 0xb6574
 * 字段偏移 top8: 0x6c×1 / 0x5c×1 / 0x58×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc370c push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0xc3710 mov r7, r0
 *   @0xc3714 ldr r3, [pc, #0x6c]
 *   @0xc3718 ldr r3, [pc, r3]
 *   @0xc371c ldr r6, [r3]
 *   @0xc3720 cmp r6, #0
 *   @0xc3724 ble 0xc3778 <_Z15Background_FindPKc+0x6c>
 *   @0xc3728 ldr r3, [pc, #0x5c]
 *   @0xc372c mov r4, #0
 *   @0xc3730 ldr r2, [pc, #0x58]
 *   @0xc3734 mov r5, r4
 *   @0xc3738 ldr r3, [pc, r3]
 *   @0xc373c add r2, pc, r2
 *   @0xc3740 ldr r9, [r3]
 *   @0xc3744 ldr r8, [r2, #0x4]
 *   @0xc3748 ldr r3, [r8, r4]
 *   @0xc374c mov r1, r7
 *   @0xc3750 cmp r3, #0
 *   @0xc3754 beq 0xc3768 <_Z15Background_FindPKc+0x5c>
 *   @0xc3758 ldr r0, [r9, r4]
 *   @0xc375c bl 0xb6574 <strcmp@plt>
 *   @0xc3760 cmp r0, #0
 *   @0xc3764 beq 0xc3780 <_Z15Background_FindPKc+0x74>
 *   @0xc3768 add r5, r5, #1
 *   @0xc376c add r4, r4, #4
 *   @0xc3770 cmp r5, r6
 *   @0xc3774 bne 0xc3748 <_Z15Background_FindPKc+0x3c>
 *   @0xc3778 mvn r0, #0
 *   @0xc377c pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0xc3780 mov r0, r5
 *   @0xc3784 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0xc3788 eorseq r10, r2, r0, lsr r2
 *   @0xc378c eorseq r10, r2, r4, lsl r2
 *   @0xc3790 eorseq r6, r11, r12, ror #10
 *
 * ══ §181/212 AsyncSaveLoadCreateUpdateMap(HTTP_REQ_CONTEXT*, void*, int*)  0xc4dcc  size 136  34 条（0xc4dcc..0xc4e54）
 * @func 0xc4dcc 0xc4e54  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CreateDsMap(int, ...)
 * 字段偏移 top8: 0x24×1 / 0x58×1 / 0x54×1 / 0x4×1 / 0x3c×1 / 0x10×1 / 0x20×1 / 0x14×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc4dcc vldr s14, [r0, #84]
 *   @0xc4dd0 vcvt.f64.s32 d7, s14
 *   @0xc4dd4 push {r4, lr}
 *   @0xc4dd8 vldr s12, [r0, #80]
 *   @0xc4ddc mov r4, r2
 *   @0xc4de0 ldr r2, [r0, #0x24]
 *   @0xc4de4 sub sp, sp, #40
 *   @0xc4de8 ldr r1, [pc, #0x58]
 *   @0xc4dec mov r3, #0
 *   @0xc4df0 ldr r12, [pc, #0x54]
 *   @0xc4df4 mov r0, #3
 *   @0xc4df8 add r1, pc, r1
 *   @0xc4dfc str r1, [sp, #0x4]
 *   @0xc4e00 vstr d7, [sp, #24]
 *   @0xc4e04 vmov s15, r2
 *   @0xc4e08 vcvt.f64.s32 d6, s12
 *   @0xc4e0c ldr r1, [pc, #0x3c]
 *   @0xc4e10 add r12, pc, r12
 *   @0xc4e14 str r3, [sp]
 *   @0xc4e18 str r3, [sp, #0x10]
 *   @0xc4e1c add r1, pc, r1
 *   @0xc4e20 str r3, [sp, #0x20]
 *   @0xc4e24 str r12, [sp, #0x14]
 *   @0xc4e28 vcvt.f64.s32 d7, s15
 *   @0xc4e2c vstr d6, [sp, #8]
 *   @0xc4e30 vmov r2, r3, d7
 *   @0xc4e34 bl 0x20bdc0 <_Z11CreateDsMapiz>
 *   @0xc4e38 str r0, [r4]
 *   @0xc4e3c mov r0, #72
 *   @0xc4e40 add sp, sp, #40
 *   @0xc4e44 pop {r4, pc}
 *   @0xc4e48 eoreq r11, r6, r8, asr r12
 *   @0xc4e4c eoreq r11, r6, r4, ror sp
 *   @0xc4e50 eoreq r11, r6, r4, lsr #24
 *
 * ══ §182/212 F_BUFFER_Tell(RValue&, CInstance*, CInstance*, int, RValue*)  0xc6388  size 136  34 条（0xc6388..0xc6410）
 * @func 0xc6388 0xc6420  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_BUFFER_Tell(RValue&, CInstance*, CInstance*, int, RValue*)+0x6c
 * 字段偏移 top8: 0x8×1 / 0xc×1 / 0x48×1 / 0x4×1 / 0x2×1 / 0x1c×1 / 0x10×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc6388 push {r4, lr}
 *   @0xc638c mov r1, #0
 *   @0xc6390 ldr r2, [sp, #0x8]
 *   @0xc6394 mov r3, r1
 *   @0xc6398 str r1, [r0, #0xc]
 *   @0xc639c movt r3, #0xbff0
 *   @0xc63a0 mov r4, r0
 *   @0xc63a4 stm r0, {r1, r3}
 *   @0xc63a8 mov r0, r2
 *   @0xc63ac bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc63b0 cmp r0, #0
 *   @0xc63b4 blt 0xc63f4 <_Z13F_BUFFER_TellR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0xc63b8 ldr r3, [pc, #0x48]
 *   @0xc63bc add r3, pc, r3
 *   @0xc63c0 ldr r2, [r3]
 *   @0xc63c4 cmp r0, r2
 *   @0xc63c8 bge 0xc63f4 <_Z13F_BUFFER_TellR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0xc63cc ldr r3, [r3, #0x4]
 *   @0xc63d0 ldr r3, [r3, r0, lsl #2]
 *   @0xc63d4 cmp r3, #0
 *   @0xc63d8 beq 0xc63f4 <_Z13F_BUFFER_TellR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0xc63dc ldr r2, [r3, #0x1c]
 *   @0xc63e0 vmov s15, r2
 *   @0xc63e4 vcvt.f64.s32 d7, s15
 *   @0xc63e8 vmov r2, r3, d7
 *   @0xc63ec stm r4, {r2, r3}
 *   @0xc63f0 pop {r4, pc}
 *   @0xc63f4 ldr r0, [pc, #0x10]
 *   @0xc63f8 mov r1, #0
 *   @0xc63fc pop {r4, lr}
 *   @0xc6400 add r0, pc, r0
 *   @0xc6404 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc6408 eorseq r3, r11, r8, asr sp
 *   @0xc640c .word 0x0026a7b4
 *
 * ══ §183/212 F_BUFFER_Get_Size(RValue&, CInstance*, CInstance*, int, RValue*)  0xc6410  size 136  34 条（0xc6410..0xc6498）
 * @func 0xc6410 0xc6498  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_BUFFER_Get_Size(RValue&, CInstance*, CInstance*, int, RValue*)+0x6c
 * 字段偏移 top8: 0x10×2 / 0x8×1 / 0xc×1 / 0x48×1 / 0x4×1 / 0x2×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc6410 push {r4, lr}
 *   @0xc6414 mov r1, #0
 *   @0xc6418 ldr r2, [sp, #0x8]
 *   @0xc641c mov r3, r1
 *   @0xc6420 str r1, [r0, #0xc]
 *   @0xc6424 movt r3, #0xbff0
 *   @0xc6428 mov r4, r0
 *   @0xc642c stm r0, {r1, r3}
 *   @0xc6430 mov r0, r2
 *   @0xc6434 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc6438 cmp r0, #0
 *   @0xc643c blt 0xc647c <_Z17F_BUFFER_Get_SizeR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0xc6440 ldr r3, [pc, #0x48]
 *   @0xc6444 add r3, pc, r3
 *   @0xc6448 ldr r2, [r3]
 *   @0xc644c cmp r0, r2
 *   @0xc6450 bge 0xc647c <_Z17F_BUFFER_Get_SizeR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0xc6454 ldr r3, [r3, #0x4]
 *   @0xc6458 ldr r3, [r3, r0, lsl #2]
 *   @0xc645c cmp r3, #0
 *   @0xc6460 beq 0xc647c <_Z17F_BUFFER_Get_SizeR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0xc6464 ldr r2, [r3, #0x10]
 *   @0xc6468 vmov s15, r2
 *   @0xc646c vcvt.f64.s32 d7, s15
 *   @0xc6470 vmov r2, r3, d7
 *   @0xc6474 stm r4, {r2, r3}
 *   @0xc6478 pop {r4, pc}
 *   @0xc647c ldr r0, [pc, #0x10]
 *   @0xc6480 mov r1, #0
 *   @0xc6484 pop {r4, lr}
 *   @0xc6488 add r0, pc, r0
 *   @0xc648c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc6490 ldrsbteq r3, [r11], -r0
 *   @0xc6494 eoreq r10, r6, r12, lsr #14
 *
 * ══ §184/212 YYprintf(char const*, ...)  0xd5838  size 136  34 条（0xd5838..0xd58c0）
 * @func 0xd5838 0xd58c0  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb667c / 0xb65d4
 * 字段偏移 top8: 0x404×2 / 0x6c×1 / 0x418×1 / 0x40×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd5838 push {r0, r1, r2, r3}
 *   @0xd583c push {r4, r5, lr}
 *   @0xd5840 sub sp, sp, #1024
 *   @0xd5844 ldr r4, [pc, #0x6c]
 *   @0xd5848 sub sp, sp, #12
 *   @0xd584c add r5, sp, #4
 *   @0xd5850 add r2, sp, #1040
 *   @0xd5854 ldr r4, [pc, r4]
 *   @0xd5858 add r2, r2, #12
 *   @0xd585c ldr r1, [sp, #0x418]
 *   @0xd5860 mov r0, r5
 *   @0xd5864 ldr r3, [r4]
 *   @0xd5868 str r2, [sp]
 *   @0xd586c str r3, [sp, #0x404]
 *   @0xd5870 bl 0xb667c <vsprintf@plt>
 *   @0xd5874 ldr r3, [pc, #0x40]
 *   @0xd5878 mov r1, r5
 *   @0xd587c ldr r3, [pc, r3]
 *   @0xd5880 ldr r0, [r3]
 *   @0xd5884 ldr r3, [r0]
 *   @0xd5888 ldr r3, [r3, #0xc]
 *   @0xd588c blx r3
 *   @0xd5890 ldr r2, [sp, #0x404]
 *   @0xd5894 ldr r3, [r4]
 *   @0xd5898 cmp r2, r3
 *   @0xd589c bne 0xd58b4 <_Z8YYprintfPKcz+0x7c>
 *   @0xd58a0 add sp, sp, #1024
 *   @0xd58a4 add sp, sp, #12
 *   @0xd58a8 pop {r4, r5, lr}
 *   @0xd58ac add sp, sp, #16
 *   @0xd58b0 bx lr
 *   @0xd58b4 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0xd58b8 ldrshteq r8, [r1], -r12
 *   @0xd58bc mlaseq r1, r8, lr, r7
 *
 * ══ §185/212 Extension_Function_GetName(int)  0xf62bc  size 136  34 条（0xf62bc..0xf6344）
 * @func 0xf62bc 0xf6344  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Extension_Function_GetName(int)+0x78 / CExtensionPackage::FunctionFindId(int) / CExtensionFunction::GetName()
 * 字段偏移 top8: 0x70×1 / 0x60×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf62bc push {r4, r5, r6, r7, r8, lr}
 *   @0xf62c0 mov r7, r0
 *   @0xf62c4 ldr r6, [pc, #0x70]
 *   @0xf62c8 ldr r6, [pc, r6]
 *   @0xf62cc ldr r3, [r6]
 *   @0xf62d0 cmp r3, #0
 *   @0xf62d4 ble 0xf6334 <_Z26Extension_Function_GetNamei+0x78>
 *   @0xf62d8 ldr r8, [pc, #0x60]
 *   @0xf62dc mov r5, #0
 *   @0xf62e0 mov r4, r5
 *   @0xf62e4 add r8, pc, r8
 *   @0xf62e8 ldr r3, [r8, #0x4]
 *   @0xf62ec mov r1, r7
 *   @0xf62f0 ldr r0, [r3, r4, lsl #2]
 *   @0xf62f4 add r4, r4, #1
 *   @0xf62f8 bl 0xf54e0 <_ZN17CExtensionPackage14FunctionFindIdEi>
 *   @0xf62fc cmp r0, #0
 *   @0xf6300 beq 0xf630c <_Z26Extension_Function_GetNamei+0x50>
 *   @0xf6304 bl 0xf4bb0 <_ZN18CExtensionFunction7GetNameEv>
 *   @0xf6308 mov r5, r0
 *   @0xf630c cmp r5, #0
 *   @0xf6310 beq 0xf6320 <_Z26Extension_Function_GetNamei+0x64>
 *   @0xf6314 ldrb r3, [r5]
 *   @0xf6318 cmp r3, #0
 *   @0xf631c bne 0xf632c <_Z26Extension_Function_GetNamei+0x70>
 *   @0xf6320 ldr r3, [r6]
 *   @0xf6324 cmp r3, r4
 *   @0xf6328 bgt 0xf62e8 <_Z26Extension_Function_GetNamei+0x2c>
 *   @0xf632c mov r0, r5
 *   @0xf6330 pop {r4, r5, r6, r7, r8, pc}
 *   @0xf6334 mov r5, #0
 *   @0xf6338 b 0xf632c <_Z26Extension_Function_GetNamei+0x70>
 *   @0xf633c eoreq r7, pc, r12, ror #22
 *   @0xf6340 eorseq sp, r8, r4, ror #6
 *
 * ══ §186/212 Font_Find(char const*)  0xfa374  size 136  34 条（0xfa374..0xfa3fc）
 * @func 0xfa374 0xfa3fc  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Font_Find(char const*)+0x6c / 0xb6574
 * 字段偏移 top8: 0x6c×1 / 0x5c×1 / 0x58×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfa374 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0xfa378 mov r7, r0
 *   @0xfa37c ldr r3, [pc, #0x6c]
 *   @0xfa380 ldr r3, [pc, r3]
 *   @0xfa384 ldr r6, [r3]
 *   @0xfa388 cmp r6, #0
 *   @0xfa38c ble 0xfa3e0 <_Z9Font_FindPKc+0x6c>
 *   @0xfa390 ldr r2, [pc, #0x5c]
 *   @0xfa394 mov r4, #0
 *   @0xfa398 ldr r3, [pc, #0x58]
 *   @0xfa39c mov r5, r4
 *   @0xfa3a0 ldr r2, [pc, r2]
 *   @0xfa3a4 ldr r3, [pc, r3]
 *   @0xfa3a8 ldr r8, [r2, #0x4]
 *   @0xfa3ac ldr r9, [r3]
 *   @0xfa3b0 ldr r3, [r8, r4]
 *   @0xfa3b4 mov r1, r7
 *   @0xfa3b8 cmp r3, #0
 *   @0xfa3bc beq 0xfa3d0 <_Z9Font_FindPKc+0x5c>
 *   @0xfa3c0 ldr r0, [r9, r4]
 *   @0xfa3c4 bl 0xb6574 <strcmp@plt>
 *   @0xfa3c8 cmp r0, #0
 *   @0xfa3cc beq 0xfa3e8 <_Z9Font_FindPKc+0x74>
 *   @0xfa3d0 add r5, r5, #1
 *   @0xfa3d4 add r4, r4, #4
 *   @0xfa3d8 cmp r5, r6
 *   @0xfa3dc bne 0xfa3b0 <_Z9Font_FindPKc+0x3c>
 *   @0xfa3e0 mvn r0, #0
 *   @0xfa3e4 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0xfa3e8 mov r0, r5
 *   @0xfa3ec pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0xfa3f0 eoreq r3, pc, r0, ror #21
 *   @0xfa3f4 .word 0x002f3abc
 *   @0xfa3f8 eoreq r3, pc, r0, asr #21
 *
 * ══ §187/212 Font_Delete(int)  0xfabb8  size 136  34 条（0xfabb8..0xfac40）
 * @func 0xfabb8 0xfac40  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Font_Delete(int)+0x74 / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x2×4 / 0x4×3 / 0x68×1 / 0x58×1 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfabb8 push {r3, r4, r5, r6, r7, lr}
 *   @0xfabbc subs r4, r0, #0
 *   @0xfabc0 blt 0xfac2c <_Z11Font_Deletei+0x74>
 *   @0xfabc4 ldr r3, [pc, #0x68]
 *   @0xfabc8 ldr r3, [pc, r3]
 *   @0xfabcc ldr r3, [r3]
 *   @0xfabd0 cmp r4, r3
 *   @0xfabd4 bge 0xfac2c <_Z11Font_Deletei+0x74>
 *   @0xfabd8 ldr r5, [pc, #0x58]
 *   @0xfabdc ldr r5, [pc, r5]
 *   @0xfabe0 ldr r3, [r5, #0x4]
 *   @0xfabe4 ldr r0, [r3, r4, lsl #2]
 *   @0xfabe8 cmp r0, #0
 *   @0xfabec popeq {r3, r4, r5, r6, r7, pc}
 *   @0xfabf0 ldr r3, [r0]
 *   @0xfabf4 mov r7, #0
 *   @0xfabf8 ldr r6, [pc, #0x3c]
 *   @0xfabfc ldr r3, [r3, #0x4]
 *   @0xfac00 blx r3
 *   @0xfac04 ldr r3, [r5, #0x4]
 *   @0xfac08 ldr r6, [pc, r6]
 *   @0xfac0c str r7, [r3, r4, lsl #2]
 *   @0xfac10 ldr r3, [r6]
 *   @0xfac14 ldr r0, [r3, r4, lsl #2]
 *   @0xfac18 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xfac1c ldr r3, [r6]
 *   @0xfac20 mov r0, #1
 *   @0xfac24 str r7, [r3, r4, lsl #2]
 *   @0xfac28 pop {r3, r4, r5, r6, r7, pc}
 *   @0xfac2c mov r0, #0
 *   @0xfac30 pop {r3, r4, r5, r6, r7, pc}
 *   @0xfac34 mlaeq pc, r8, r2, r3
 *   @0xfac38 eoreq r3, pc, r0, lsl #5
 *   @0xfac3c eoreq r3, pc, r12, asr r2
 *
 * ══ §188/212 F_DsListInsert(RValue&, CInstance*, CInstance*, int, RValue*)  0xfc51c  size 136  34 条（0xfc51c..0xfc5a4）
 * @func 0xfc51c 0xfc5b4  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / F_DsListInsert(RValue&, CInstance*, CInstance*, int, RValue*)+0x68
 * 字段偏移 top8: 0x10×1 / 0x58×1 / 0x48×1 / 0x4×1 / 0x2×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfc51c push {r3, r4, r5, lr}
 *   @0xfc520 mov r1, #0
 *   @0xfc524 ldr r4, [sp, #0x10]
 *   @0xfc528 mov r0, r4
 *   @0xfc52c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfc530 cmp r0, #0
 *   @0xfc534 blt 0xfc584 <_Z14F_DsListInsertR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0xfc538 ldr r3, [pc, #0x58]
 *   @0xfc53c ldr r3, [pc, r3]
 *   @0xfc540 ldr r3, [r3]
 *   @0xfc544 cmp r0, r3
 *   @0xfc548 bge 0xfc584 <_Z14F_DsListInsertR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0xfc54c ldr r3, [pc, #0x48]
 *   @0xfc550 ldr r3, [pc, r3]
 *   @0xfc554 ldr r3, [r3, #0x4]
 *   @0xfc558 ldr r5, [r3, r0, lsl #2]
 *   @0xfc55c cmp r5, #0
 *   @0xfc560 beq 0xfc584 <_Z14F_DsListInsertR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0xfc564 mov r0, r4
 *   @0xfc568 mov r1, #1
 *   @0xfc56c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfc570 add r2, r4, #32
 *   @0xfc574 mov r1, r0
 *   @0xfc578 mov r0, r5
 *   @0xfc57c pop {r3, r4, r5, lr}
 *   @0xfc580 b 0x205f40 <_ZN8CDS_List6InsertEiP6RValue>
 *   @0xfc584 ldr r0, [pc, #0x14]
 *   @0xfc588 mov r1, #0
 *   @0xfc58c pop {r3, r4, r5, lr}
 *   @0xfc590 add r0, pc, r0
 *   @0xfc594 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfc598 eoreq r1, pc, r0, asr #14
 *   @0xfc59c eoreq r1, pc, r0, lsr r7
 *   @0xfc5a0 eoreq r11, r3, r12, ror #12
 *
 * ══ §189/212 F_DsListReplace(RValue&, CInstance*, CInstance*, int, RValue*)  0xfc6c0  size 136  34 条（0xfc6c0..0xfc748）
 * @func 0xfc6c0 0xfc748  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / F_DsListReplace(RValue&, CInstance*, CInstance*, int, RValue*)+0x68
 * 字段偏移 top8: 0x10×1 / 0x58×1 / 0x48×1 / 0x4×1 / 0x2×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfc6c0 push {r3, r4, r5, lr}
 *   @0xfc6c4 mov r1, #0
 *   @0xfc6c8 ldr r4, [sp, #0x10]
 *   @0xfc6cc mov r0, r4
 *   @0xfc6d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfc6d4 cmp r0, #0
 *   @0xfc6d8 blt 0xfc728 <_Z15F_DsListReplaceR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0xfc6dc ldr r3, [pc, #0x58]
 *   @0xfc6e0 ldr r3, [pc, r3]
 *   @0xfc6e4 ldr r3, [r3]
 *   @0xfc6e8 cmp r0, r3
 *   @0xfc6ec bge 0xfc728 <_Z15F_DsListReplaceR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0xfc6f0 ldr r3, [pc, #0x48]
 *   @0xfc6f4 ldr r3, [pc, r3]
 *   @0xfc6f8 ldr r3, [r3, #0x4]
 *   @0xfc6fc ldr r5, [r3, r0, lsl #2]
 *   @0xfc700 cmp r5, #0
 *   @0xfc704 beq 0xfc728 <_Z15F_DsListReplaceR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0xfc708 mov r0, r4
 *   @0xfc70c mov r1, #1
 *   @0xfc710 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfc714 add r2, r4, #32
 *   @0xfc718 mov r1, r0
 *   @0xfc71c mov r0, r5
 *   @0xfc720 pop {r3, r4, r5, lr}
 *   @0xfc724 b 0x208964 <_ZN8CDS_List7ReplaceEiP6RValue>
 *   @0xfc728 ldr r0, [pc, #0x14]
 *   @0xfc72c mov r1, #0
 *   @0xfc730 pop {r3, r4, r5, lr}
 *   @0xfc734 add r0, pc, r0
 *   @0xfc738 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfc73c mlaeq pc, r12, r5, r1
 *   @0xfc740 eoreq r1, pc, r12, lsl #11
 *   @0xfc744 eoreq r11, r3, r8, asr #9
 *
 * ══ §190/212 dsMapAddDouble  0x1018e0  size 136  34 条（0x1018e0..0x101968）
 * @func 0x1018e0 0x101978  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYSetString(RValue*, char const*) / F_DsMapAdd(RValue&, CInstance*, CInstance*, int, RValue*)
 * 字段偏移 top8: 0x44×2 / 0x34×1 / 0x8×1 / 0x20×1 / 0x30×1 / 0x40×1 / 0x24×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1018e0 vmov s13, r0
 *   @0x1018e4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1018e8 vcvt.f64.s32 d7, s13
 *   @0x1018ec sub sp, sp, #76
 *   @0x1018f0 mov r8, #0
 *   @0x1018f4 add r9, sp, #72
 *   @0x1018f8 add r0, sp, #40
 *   @0x1018fc mov r6, r2
 *   @0x101900 mov r7, r3
 *   @0x101904 mov r4, #0
 *   @0x101908 mvn r3, #-16777216
 *   @0x10190c mov r5, #0
 *   @0x101910 str r3, [sp, #0x34]
 *   @0x101914 str r3, [sp, #0x44]
 *   @0x101918 vmov r10, r11, d7
 *   @0x10191c str r8, [sp, #0x8]
 *   @0x101920 str r8, [sp, #0x20]
 *   @0x101924 str r8, [sp, #0x30]
 *   @0x101928 str r8, [sp, #0x40]
 *   @0x10192c str r8, [sp, #0x24]
 *   @0x101930 strd r4, r5, [sp, #40]
 *   @0x101934 strd r4, r5, [sp, #56]
 *   @0x101938 strd r10, r11, [r9, #-48]!
 *   @0x10193c bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x101940 mov r1, r8
 *   @0x101944 str r9, [sp]
 *   @0x101948 mov r2, r8
 *   @0x10194c add r0, sp, #8
 *   @0x101950 mov r3, #3
 *   @0x101954 strd r6, r7, [sp, #56]
 *   @0x101958 str r8, [sp, #0x44]
 *   @0x10195c bl 0xff014 <_Z10F_DsMapAddR6RValueP9CInstanceS2_iPS_>
 *   @0x101960 add sp, sp, #76
 *   @0x101964 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §191/212 dsMapAddPtr  0x101a84  size 136  34 条（0x101a84..0x101b0c）
 * @func 0x101a84 0x101b1c  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYSetString(RValue*, char const*) / F_DsMapAdd(RValue&, CInstance*, CInstance*, int, RValue*)
 * 字段偏移 top8: 0x44×2 / 0x34×1 / 0x8×1 / 0x20×1 / 0x30×1 / 0x40×1 / 0x24×1 / 0x38×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x101a84 vmov s13, r0
 *   @0x101a88 mvn r3, #-16777216
 *   @0x101a8c push {r4, r5, r6, r7, r8, r10, r11, lr}
 *   @0x101a90 vcvt.f64.s32 d7, s13
 *   @0x101a94 sub sp, sp, #72
 *   @0x101a98 mov r6, #0
 *   @0x101a9c add r7, sp, #72
 *   @0x101aa0 add r0, sp, #40
 *   @0x101aa4 mov r8, r2
 *   @0x101aa8 mov r4, #0
 *   @0x101aac mov r5, #0
 *   @0x101ab0 str r3, [sp, #0x34]
 *   @0x101ab4 str r3, [sp, #0x44]
 *   @0x101ab8 str r6, [sp, #0x8]
 *   @0x101abc vmov r10, r11, d7
 *   @0x101ac0 str r6, [sp, #0x20]
 *   @0x101ac4 str r6, [sp, #0x30]
 *   @0x101ac8 str r6, [sp, #0x40]
 *   @0x101acc str r6, [sp, #0x24]
 *   @0x101ad0 strd r4, r5, [sp, #40]
 *   @0x101ad4 strd r4, r5, [sp, #56]
 *   @0x101ad8 strd r10, r11, [r7, #-48]!
 *   @0x101adc bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x101ae0 mov r12, #3
 *   @0x101ae4 mov r1, r6
 *   @0x101ae8 str r7, [sp]
 *   @0x101aec mov r2, r6
 *   @0x101af0 mov r3, r12
 *   @0x101af4 add r0, sp, #8
 *   @0x101af8 str r8, [sp, #0x38]
 *   @0x101afc str r12, [sp, #0x44]
 *   @0x101b00 bl 0xff014 <_Z10F_DsMapAddR6RValueP9CInstanceS2_iPS_>
 *   @0x101b04 add sp, sp, #72
 *   @0x101b08 pop {r4, r5, r6, r7, r8, r10, r11, pc}
 *
 * ══ §192/212 YYGML_string(RValue const&)  0x111130  size 136  34 条（0x111130..0x1111b8）
 * @func 0x111130 0x1111b8  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool) / STRING_RValue(char**, char**, int*, RValue const*) / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x10×2 / 0x78×1 / 0xc×1 / 0x-4×1 / 0x14×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x111130 ldr r1, [pc, #0x78]
 *   @0x111134 mov r12, #256
 *   @0x111138 push {r4, lr}
 *   @0x11113c sub sp, sp, #24
 *   @0x111140 mov r4, r0
 *   @0x111144 add r1, pc, r1
 *   @0x111148 mov r0, r12
 *   @0x11114c movw r2, #0x63b
 *   @0x111150 mov r3, #1
 *   @0x111154 str r12, [sp, #0xc]
 *   @0x111158 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x11115c mov r3, r4
 *   @0x111160 add r1, sp, #16
 *   @0x111164 mov r4, #0
 *   @0x111168 mov r2, r0
 *   @0x11116c str r0, [sp, #0x10]
 *   @0x111170 add r0, sp, #24
 *   @0x111174 str r2, [r0, #-0x4]!
 *   @0x111178 strb r4, [r2]
 *   @0x11117c add r2, sp, #12
 *   @0x111180 bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue>
 *   @0x111184 ldr r0, [sp, #0x10]
 *   @0x111188 ldr r1, [sp, #0x14]
 *   @0x11118c mov r3, #74
 *   @0x111190 ldr r2, [pc, #0x1c]
 *   @0x111194 rsb r1, r0, r1
 *   @0x111198 str r4, [sp]
 *   @0x11119c add r1, r1, #1
 *   @0x1111a0 add r2, pc, r2
 *   @0x1111a4 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x1111a8 add sp, sp, #24
 *   @0x1111ac pop {r4, pc}
 *   @0x1111b0 eoreq r7, r2, r0, lsl #26
 *   @0x1111b4 mlaeq r1, r0, lr, pc
 *
 * ══ §193/212 F_VariableGlobalSet(RValue&, CInstance*, CInstance*, int, RValue*)  0x114e50  size 136  34 条（0x114e50..0x114ed8）
 * @func 0x114e50 0x114ed8  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int) / Variable_BuiltIn_Find(char const*) / F_VariableGlobalSet(RValue&, CInstance*, CInstance*, int, RValue*)+0x58 / Code_Variable_FindAlloc_Slot_From_Name(YYObjectBase*, char const*)
 * 字段偏移 top8: 0x10×1 / 0x64×1 / 0x4c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x114e50 push {r4, r5, r6, lr}
 *   @0x114e54 mov r1, #0
 *   @0x114e58 ldr r4, [sp, #0x10]
 *   @0x114e5c mov r0, r4
 *   @0x114e60 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x114e64 ldr r12, [pc, #0x64]
 *   @0x114e68 ldr r12, [pc, r12]
 *   @0x114e6c ldr r5, [r12]
 *   @0x114e70 mov r6, r0
 *   @0x114e74 bl 0x1f3a5c <_Z21Variable_BuiltIn_FindPKc>
 *   @0x114e78 subs r1, r0, #0
 *   @0x114e7c blt 0x114ea8 <_Z19F_VariableGlobalSetR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x114e80 ldr r12, [pc, #0x4c]
 *   @0x114e84 ldr r12, [pc, r12]
 *   @0x114e88 ldr r3, [r12]
 *   @0x114e8c cmp r1, r3
 *   @0x114e90 poplt {r4, r5, r6, pc}
 *   @0x114e94 mov r0, r5
 *   @0x114e98 add r3, r4, #16
 *   @0x114e9c mov r2, #-2147483648
 *   @0x114ea0 pop {r4, r5, r6, lr}
 *   @0x114ea4 b 0x1f3c28 <_Z24Variable_SetValue_DirectP12YYObjectBaseiiP6RValue>
 *   @0x114ea8 mov r1, r6
 *   @0x114eac mov r0, r5
 *   @0x114eb0 bl 0xd2c84 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc>
 *   @0x114eb4 add r2, r4, #16
 *   @0x114eb8 mov r1, #-2147483648
 *   @0x114ebc pop {r4, r5, r6, lr}
 *   @0x114ec0 cmp r0, #0
 *   @0x114ec4 addge r0, r0, #99328
 *   @0x114ec8 addge r0, r0, #672
 *   @0x114ecc b 0x1f38f8 <_Z22Variable_Global_SetVariiP6RValue>
 *   @0x114ed0 eoreq r8, sp, r12, asr #26
 *   @0x114ed4 eoreq r9, sp, r4, lsr #11
 *
 * ══ §194/212 F_DisplaySetAll(RValue&, CInstance*, CInstance*, int, RValue*)  0x119fc8  size 136  34 条（0x119fc8..0x11a050）
 * @func 0x119fc8 0x11a050  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×4 / DisplaySet(int, int, int, int)
 * 字段偏移 top8: 0x20×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x119fc8 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x119fcc mov r6, #0
 *   @0x119fd0 ldr r4, [sp, #0x20]
 *   @0x119fd4 mov r5, r0
 *   @0x119fd8 str r6, [r0, #0xc]
 *   @0x119fdc mov r1, r6
 *   @0x119fe0 mov r0, r4
 *   @0x119fe4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x119fe8 mov r1, #1
 *   @0x119fec mov r9, r0
 *   @0x119ff0 mov r0, r4
 *   @0x119ff4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x119ff8 mov r1, #2
 *   @0x119ffc mov r8, r0
 *   @0x11a000 mov r0, r4
 *   @0x11a004 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11a008 mov r1, #3
 *   @0x11a00c mov r7, r0
 *   @0x11a010 mov r0, r4
 *   @0x11a014 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11a018 mov r1, r8
 *   @0x11a01c mov r2, r7
 *   @0x11a020 mov r3, r0
 *   @0x11a024 mov r0, r9
 *   @0x11a028 bl 0x17db64 <_Z10DisplaySetiiii>
 *   @0x11a02c cmp r0, #0
 *   @0x11a030 moveq r6, r0
 *   @0x11a034 movne r3, r6
 *   @0x11a038 moveq r3, r6
 *   @0x11a03c movtne r3, #0x3ff0
 *   @0x11a040 str r6, [r5]
 *   @0x11a044 str r3, [r5, #0x4]
 *   @0x11a048 pop {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x11a04c b 0x168c24 <_Z12GR_D3D_Resetv>
 *
 * ══ §195/212 F_DrawRoundRect(RValue&, CInstance*, CInstance*, int, RValue*)  0x11af48  size 136  34 条（0x11af48..0x11afd0）
 * @func 0x11af48 0x11afd0  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×4 / YYGetBool(RValue const*, int) / GR_Draw_RoundRect(float, float, float, float, float, float, bool)
 * 字段偏移 top8: 0x28×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11af48 push {r4, r5, r6, r7, r8, lr}
 *   @0x11af4c sub sp, sp, #16
 *   @0x11af50 mov r1, #0
 *   @0x11af54 ldr r4, [sp, #0x28]
 *   @0x11af58 mov r0, r4
 *   @0x11af5c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11af60 mov r1, #1
 *   @0x11af64 mov r5, r0
 *   @0x11af68 mov r0, r4
 *   @0x11af6c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11af70 mov r1, #2
 *   @0x11af74 mov r8, r0
 *   @0x11af78 mov r0, r4
 *   @0x11af7c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11af80 mov r1, #3
 *   @0x11af84 mov r7, r0
 *   @0x11af88 mov r0, r4
 *   @0x11af8c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11af90 mov r1, #4
 *   @0x11af94 mov r6, r0
 *   @0x11af98 mov r0, r4
 *   @0x11af9c bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x11afa0 mov r1, r8
 *   @0x11afa4 mov r2, r7
 *   @0x11afa8 mov r3, r6
 *   @0x11afac mov r12, #0
 *   @0x11afb0 movt r12, #0x4120
 *   @0x11afb4 str r12, [sp]
 *   @0x11afb8 str r12, [sp, #0x4]
 *   @0x11afbc str r0, [sp, #0x8]
 *   @0x11afc0 mov r0, r5
 *   @0x11afc4 bl 0x16b77c <_Z17GR_Draw_RoundRectffffffb>
 *   @0x11afc8 add sp, sp, #16
 *   @0x11afcc pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §196/212 YYGML_keyboard_check(int)  0x1277f8  size 136  34 条（0x1277f8..0x127880）
 * @func 0x1277f8 0x127880  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IO_Key_Down(int)×2
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1277f8 push {r3, r4, r5, lr}
 *   @0x1277fc subs r4, r0, #0
 *   @0x127800 bne 0x12782c <_Z20YYGML_keyboard_checki+0x34>
 *   @0x127804 mov r5, #1
 *   @0x127808 mov r0, r4
 *   @0x12780c add r4, r4, #1
 *   @0x127810 bl 0x18bee8 <_Z11IO_Key_Downi>
 *   @0x127814 cmp r0, #0
 *   @0x127818 movne r5, #0
 *   @0x12781c cmp r4, #256
 *   @0x127820 bne 0x127808 <_Z20YYGML_keyboard_checki+0x10>
 *   @0x127824 mov r0, r5
 *   @0x127828 pop {r3, r4, r5, pc}
 *   @0x12782c cmp r4, #1
 *   @0x127830 beq 0x127848 <_Z20YYGML_keyboard_checki+0x50>
 *   @0x127834 cmp r4, #255
 *   @0x127838 movhi r5, #0
 *   @0x12783c bhi 0x127824 <_Z20YYGML_keyboard_checki+0x2c>
 *   @0x127840 pop {r3, r4, r5, lr}
 *   @0x127844 b 0x18bee8 <_Z11IO_Key_Downi>
 *   @0x127848 mov r4, #0
 *   @0x12784c b 0x127858 <_Z20YYGML_keyboard_checki+0x60>
 *   @0x127850 cmp r4, #256
 *   @0x127854 beq 0x127878 <_Z20YYGML_keyboard_checki+0x80>
 *   @0x127858 mov r0, r4
 *   @0x12785c add r4, r4, #1
 *   @0x127860 bl 0x18bee8 <_Z11IO_Key_Downi>
 *   @0x127864 cmp r0, #0
 *   @0x127868 beq 0x127850 <_Z20YYGML_keyboard_checki+0x58>
 *   @0x12786c mov r5, #1
 *   @0x127870 mov r0, r5
 *   @0x127874 pop {r3, r4, r5, pc}
 *   @0x127878 mov r5, r0
 *   @0x12787c b 0x127824 <_Z20YYGML_keyboard_checki+0x2c>
 *
 * ══ §197/212 F_SoundDelete(RValue&, CInstance*, CInstance*, int, RValue*)  0x12f858  size 136  34 条（0x12f858..0x12f8e0）
 * @func 0x12f858 0x12f8e0  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Sound_Data(int) / Sound_Delete(int) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0xc×2 / 0x70×1 / 0x18×1 / 0x4×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12f858 push {r3, r4, r5, r6, r7, lr}
 *   @0x12f85c mov r5, r0
 *   @0x12f860 ldr r3, [pc, #0x70]
 *   @0x12f864 ldr r3, [pc, r3]
 *   @0x12f868 ldrb r4, [r3]
 *   @0x12f86c cmp r4, #0
 *   @0x12f870 popne {r3, r4, r5, r6, r7, pc}
 *   @0x12f874 mov r1, r4
 *   @0x12f878 ldr r0, [sp, #0x18]
 *   @0x12f87c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12f880 mov r6, r0
 *   @0x12f884 bl 0x21fcd4 <_Z10Sound_Datai>
 *   @0x12f888 subs r7, r0, #0
 *   @0x12f88c beq 0x12f8b8 <_Z13F_SoundDeleteR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0x12f890 mov r0, r6
 *   @0x12f894 bl 0x2200cc <_Z12Sound_Deletei>
 *   @0x12f898 str r4, [r5, #0xc]
 *   @0x12f89c cmp r0, #0
 *   @0x12f8a0 movne r3, #0
 *   @0x12f8a4 movtne r3, #0x3ff0
 *   @0x12f8a8 beq 0x12f8cc <_Z13F_SoundDeleteR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x12f8ac str r4, [r5]
 *   @0x12f8b0 str r3, [r5, #0x4]
 *   @0x12f8b4 pop {r3, r4, r5, r6, r7, pc}
 *   @0x12f8b8 ldr r0, [pc, #0x1c]
 *   @0x12f8bc mov r1, r7
 *   @0x12f8c0 add r0, pc, r0
 *   @0x12f8c4 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x12f8c8 str r7, [r5, #0xc]
 *   @0x12f8cc mov r4, #0
 *   @0x12f8d0 mov r3, r4
 *   @0x12f8d4 b 0x12f8ac <_Z13F_SoundDeleteR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x12f8d8 eoreq pc, r11, r12, asr #9
 *   @0x12f8dc eoreq lr, r0, r0, lsl #1
 *
 * ══ §198/212 F_SpriteSetPrecise(RValue&, CInstance*, CInstance*, int, RValue*)  0x130e70  size 136  34 条（0x130e70..0x130ef8）
 * @func 0x130e70 0x130ef8  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / Sprite_Data(int) / CSprite::SetCollisionChecking(bool)
 * 字段偏移 top8: 0x10×1 / 0x74×1 / 0x3c×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x130e70 push {r3, r4, r5, lr}
 *   @0x130e74 mov r1, #0
 *   @0x130e78 ldr r4, [sp, #0x10]
 *   @0x130e7c mov r0, r4
 *   @0x130e80 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x130e84 mov r1, #0
 *   @0x130e88 mov r5, r0
 *   @0x130e8c mov r0, r4
 *   @0x130e90 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x130e94 cmp r0, #0
 *   @0x130e98 mov r0, r5
 *   @0x130e9c movle r4, #0
 *   @0x130ea0 movgt r4, #1
 *   @0x130ea4 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x130ea8 cmp r0, #0
 *   @0x130eac popeq {r3, r4, r5, pc}
 *   @0x130eb0 cmp r4, #0
 *   @0x130eb4 beq 0x130ed0 <_Z18F_SpriteSetPreciseR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0x130eb8 ldr r3, [r0, #0x74]
 *   @0x130ebc cmp r3, #0
 *   @0x130ec0 beq 0x130ed0 <_Z18F_SpriteSetPreciseR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0x130ec4 ldr r1, [r0, #0x3c]
 *   @0x130ec8 cmp r1, #0
 *   @0x130ecc beq 0x130ee4 <_Z18F_SpriteSetPreciseR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x130ed0 mov r1, r4
 *   @0x130ed4 bl 0x1e3d68 <_ZN7CSprite20SetCollisionCheckingEb>
 *   @0x130ed8 mov r0, r5
 *   @0x130edc pop {r3, r4, r5, lr}
 *   @0x130ee0 b 0x130cac <_Z20MarkInstancesAsDirtyi>
 *   @0x130ee4 ldr r0, [pc, #0x8]
 *   @0x130ee8 pop {r3, r4, r5, lr}
 *   @0x130eec add r0, pc, r0
 *   @0x130ef0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x130ef4 eoreq sp, r0, r0, lsl #9
 *
 * ══ §199/212 F_SoundPan(RValue&, CInstance*, CInstance*, int, RValue*)  0x133c90  size 136  34 条（0x133c90..0x133d18）
 * @func 0x133c90 0x133d18  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Sound_Data(int) / CSound::GetSoundId() / YYGetReal(RValue const*, int)
 * 字段偏移 top8: 0x10×2 / 0x74×1 / 0x5c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x133c90 ldr r3, [pc, #0x74]
 *   @0x133c94 push {r4, r5, r6, lr}
 *   @0x133c98 ldr r3, [pc, r3]
 *   @0x133c9c ldr r4, [sp, #0x10]
 *   @0x133ca0 ldrb r3, [r3]
 *   @0x133ca4 cmp r3, #0
 *   @0x133ca8 popne {r4, r5, r6, pc}
 *   @0x133cac ldr r3, [pc, #0x5c]
 *   @0x133cb0 ldr r3, [pc, r3]
 *   @0x133cb4 ldrb r1, [r3]
 *   @0x133cb8 cmp r1, #0
 *   @0x133cbc popne {r4, r5, r6, pc}
 *   @0x133cc0 mov r0, r4
 *   @0x133cc4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x133cc8 bl 0x21fcd4 <_Z10Sound_Datai>
 *   @0x133ccc subs r1, r0, #0
 *   @0x133cd0 beq 0x133cfc <_Z10F_SoundPanR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x133cd4 bl 0x215748 <_ZN6CSound10GetSoundIdEv>
 *   @0x133cd8 mov r1, #1
 *   @0x133cdc mov r5, r0
 *   @0x133ce0 mov r0, r4
 *   @0x133ce4 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x133ce8 mov r2, r0
 *   @0x133cec mov r3, r1
 *   @0x133cf0 mov r0, r5
 *   @0x133cf4 pop {r4, r5, r6, lr}
 *   @0x133cf8 b 0x21f11c <_Z15SND_Set_Panningid>
 *   @0x133cfc ldr r0, [pc, #0x10]
 *   @0x133d00 pop {r4, r5, r6, lr}
 *   @0x133d04 add r0, pc, r0
 *   @0x133d08 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x133d0c mlaeq r11, r8, r0, r11
 *   @0x133d10 mlaeq r11, r12, r3, r11
 *   @0x133d14 eoreq r11, r0, r8, lsl #15
 *
 * ══ §200/212 F_SoundIsPlaying(RValue&, CInstance*, CInstance*, int, RValue*)  0x1364d4  size 136  34 条（0x1364d4..0x13655c）
 * @func 0x1364d4 0x13655c  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Sound_Data(int) / CSound::GetSoundId() / SND_IsPlaying(char const*, int)
 * 字段偏移 top8: 0xc×2 / 0x70×1 / 0x60×1 / 0x10×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1364d4 push {r3, r4, r5, lr}
 *   @0x1364d8 mov r4, r0
 *   @0x1364dc ldr r3, [pc, #0x70]
 *   @0x1364e0 ldr r3, [pc, r3]
 *   @0x1364e4 ldrb r3, [r3]
 *   @0x1364e8 cmp r3, #0
 *   @0x1364ec popne {r3, r4, r5, pc}
 *   @0x1364f0 ldr r3, [pc, #0x60]
 *   @0x1364f4 ldr r3, [pc, r3]
 *   @0x1364f8 ldrb r1, [r3]
 *   @0x1364fc cmp r1, #0
 *   @0x136500 popne {r3, r4, r5, pc}
 *   @0x136504 str r1, [r0, #0xc]
 *   @0x136508 ldr r0, [sp, #0x10]
 *   @0x13650c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x136510 bl 0x21fcd4 <_Z10Sound_Datai>
 *   @0x136514 subs r3, r0, #0
 *   @0x136518 streq r3, [r4]
 *   @0x13651c streq r3, [r4, #0x4]
 *   @0x136520 popeq {r3, r4, r5, pc}
 *   @0x136524 ldr r5, [r3, #0xc]
 *   @0x136528 bl 0x215748 <_ZN6CSound10GetSoundIdEv>
 *   @0x13652c mov r1, r0
 *   @0x136530 mov r0, r5
 *   @0x136534 bl 0x21edc0 <_Z13SND_IsPlayingPKci>
 *   @0x136538 vmov s15, r0
 *   @0x13653c vcvt.f64.u32 d7, s15
 *   @0x136540 vmov r0, r1, d7
 *   @0x136544 vmov r2, s14
 *   @0x136548 mov r3, r1
 *   @0x13654c stm r4, {r2, r3}
 *   @0x136550 pop {r3, r4, r5, pc}
 *   @0x136554 eoreq r8, r11, r0, asr r8
 *   @0x136558 eoreq r8, r11, r8, asr r11
 *
 * ══ §201/212 F_FileBinSeek(RValue&, CInstance*, CInstance*, int, RValue*)  0x1394b4  size 136  34 条（0x1394b4..0x13953c）
 * @func 0x1394b4 0x13953c  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2
 * 字段偏移 top8: 0x10×1 / 0x44×1 / 0x34×1 / 0x8×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1394b4 push {r3, r4, r5, lr}
 *   @0x1394b8 mov r1, #0
 *   @0x1394bc ldr r5, [sp, #0x10]
 *   @0x1394c0 mov r0, r5
 *   @0x1394c4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1394c8 mov r1, #1
 *   @0x1394cc mov r4, r0
 *   @0x1394d0 mov r0, r5
 *   @0x1394d4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1394d8 sub r3, r4, #1
 *   @0x1394dc cmp r3, #30
 *   @0x1394e0 bhi 0x13951c <_Z13F_FileBinSeekR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x1394e4 ldr r3, [pc, #0x44]
 *   @0x1394e8 ldr r3, [pc, r3]
 *   @0x1394ec ldrb r3, [r3, r4]
 *   @0x1394f0 cmp r3, #0
 *   @0x1394f4 beq 0x13951c <_Z13F_FileBinSeekR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x1394f8 ldr r3, [pc, #0x34]
 *   @0x1394fc add r4, r4, r4, lsl #1
 *   @0x139500 mov r1, r0
 *   @0x139504 mov r2, #0
 *   @0x139508 ldr r3, [pc, r3]
 *   @0x13950c add r3, r3, r4, lsl #2
 *   @0x139510 ldr r0, [r3, #0x8]
 *   @0x139514 pop {r3, r4, r5, lr}
 *   @0x139518 b 0x18de30 <_ZN8LoadSave5fseekEP7_YYFILEli>
 *   @0x13951c ldr r0, [pc, #0x14]
 *   @0x139520 mov r1, #0
 *   @0x139524 pop {r3, r4, r5, lr}
 *   @0x139528 add r0, pc, r0
 *   @0x13952c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x139530 eoreq r5, r11, r4, lsr #27
 *   @0x139534 eoreq r5, r11, r8, lsl #27
 *   @0x139538 eoreq r6, r0, r8, asr r12
 *
 * ══ §202/212 F_ActionMoveTo(RValue&, CInstance*, CInstance*, int, RValue*)  0x13daf8  size 136  34 条（0x13daf8..0x13db80）
 * @func 0x13daf8 0x13db80  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2
 * 字段偏移 top8: 0x18×1 / 0x50×1
 * VFP 指令 13 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13daf8 push {r3, r4, r5, lr}
 *   @0x13dafc vpush {d8}
 *   @0x13db00 mov r5, r1
 *   @0x13db04 ldr r4, [sp, #0x18]
 *   @0x13db08 mov r1, #0
 *   @0x13db0c mov r0, r4
 *   @0x13db10 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13db14 mov r1, #1
 *   @0x13db18 vmov s16, r0
 *   @0x13db1c mov r0, r4
 *   @0x13db20 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13db24 ldr r3, [pc, #0x50]
 *   @0x13db28 ldr r3, [pc, r3]
 *   @0x13db2c ldrb r3, [r3]
 *   @0x13db30 cmp r3, #0
 *   @0x13db34 vmov s15, r0
 *   @0x13db38 bne 0x13db54 <_Z14F_ActionMoveToR6RValueP9CInstanceS2_iPS_+0x5c>
 *   @0x13db3c vmov r1, s16
 *   @0x13db40 mov r0, r5
 *   @0x13db44 vpop {d8}
 *   @0x13db48 vmov r2, s15
 *   @0x13db4c pop {r3, r4, r5, lr}
 *   @0x13db50 b 0x193e7c <_ZN9CInstance11SetPositionEff>
 *   @0x13db54 vldr s13, [r5, #180]
 *   @0x13db58 vldr s14, [r5, #184]
 *   @0x13db5c vadd.f32 s13, s16, s13
 *   @0x13db60 mov r0, r5
 *   @0x13db64 vpop {d8}
 *   @0x13db68 pop {r3, r4, r5, lr}
 *   @0x13db6c vadd.f32 s14, s15, s14
 *   @0x13db70 vmov r1, s13
 *   @0x13db74 vmov r2, s14
 *   @0x13db78 b 0x193e7c <_ZN9CInstance11SetPositionEff>
 *   @0x13db7c eoreq r0, r11, r4, lsl r0
 *
 * ══ §203/212 F_ActionIfSound(RValue&, CInstance*, CInstance*, int, RValue*)  0x13e638  size 136  34 条（0x13e638..0x13e6c0）
 * @func 0x13e638 0x13e6c0  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Audio_SoundIsPlaying(int) / Sound_Data(int) / CSound::GetSoundId() / SND_IsPlaying(char const*, int)
 * 字段偏移 top8: 0xc×3 / 0x10×1 / 0x68×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13e638 push {r3, r4, r5, lr}
 *   @0x13e63c mov r1, #0
 *   @0x13e640 mov r4, r0
 *   @0x13e644 ldr r0, [sp, #0x10]
 *   @0x13e648 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13e64c ldr r3, [pc, #0x68]
 *   @0x13e650 ldr r3, [pc, r3]
 *   @0x13e654 ldrb r3, [r3]
 *   @0x13e658 cmp r3, #0
 *   @0x13e65c beq 0x13e690 <_Z15F_ActionIfSoundR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x13e660 bl 0x21717c <_Z20Audio_SoundIsPlayingi>
 *   @0x13e664 cmp r0, #0
 *   @0x13e668 mov r3, #0
 *   @0x13e66c str r3, [r4, #0xc]
 *   @0x13e670 movne r2, #0
 *   @0x13e674 movtne r2, #0x3ff0
 *   @0x13e678 bne 0x13e684 <_Z15F_ActionIfSoundR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x13e67c mov r3, #0
 *   @0x13e680 mov r2, r3
 *   @0x13e684 str r3, [r4]
 *   @0x13e688 str r2, [r4, #0x4]
 *   @0x13e68c pop {r3, r4, r5, pc}
 *   @0x13e690 bl 0x21fcd4 <_Z10Sound_Datai>
 *   @0x13e694 subs r3, r0, #0
 *   @0x13e698 beq 0x13e6b4 <_Z15F_ActionIfSoundR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0x13e69c ldr r5, [r3, #0xc]
 *   @0x13e6a0 bl 0x215748 <_ZN6CSound10GetSoundIdEv>
 *   @0x13e6a4 mov r1, r0
 *   @0x13e6a8 mov r0, r5
 *   @0x13e6ac bl 0x21edc0 <_Z13SND_IsPlayingPKci>
 *   @0x13e6b0 b 0x13e664 <_Z15F_ActionIfSoundR6RValueP9CInstanceS2_iPS_+0x2c>
 *   @0x13e6b4 str r3, [r4, #0xc]
 *   @0x13e6b8 b 0x13e67c <_Z15F_ActionIfSoundR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x13e6bc eoreq r0, r11, r0, ror #13
 *
 * ══ §204/212 F_ActionHighscoreShow(RValue&, CInstance*, CInstance*, int, RValue*)  0x13f51c  size 136  34 条（0x13f51c..0x13f5a4）
 * @func 0x13f51c 0x13f5a4  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_DrawHighscore(RValue&, CInstance*, CInstance*, int, RValue*)
 * 字段偏移 top8: 0x14×2 / 0x74×1 / 0x10×1 / 0x24×1 / 0x34×1 / 0x44×1
 * VFP 指令 10 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13f51c push {r4, r5, lr}
 *   @0x13f520 sub sp, sp, #76
 *   @0x13f524 ldr lr, [pc, #0x74]
 *   @0x13f528 add r5, sp, #8
 *   @0x13f52c mov r3, #4
 *   @0x13f530 mov r12, #0
 *   @0x13f534 ldr lr, [pc, lr]
 *   @0x13f538 str r12, [sp, #0x14]
 *   @0x13f53c ldr r4, [lr]
 *   @0x13f540 ldr lr, [r4, #0x10]
 *   @0x13f544 ldr r4, [r4, #0x14]
 *   @0x13f548 str r5, [sp]
 *   @0x13f54c asr lr, lr, #1
 *   @0x13f550 str r12, [sp, #0x24]
 *   @0x13f554 sub r5, lr, #100
 *   @0x13f558 asr r4, r4, #1
 *   @0x13f55c add lr, lr, #100
 *   @0x13f560 sub r4, r4, #100
 *   @0x13f564 vmov s10, r5
 *   @0x13f568 str r12, [sp, #0x34]
 *   @0x13f56c vmov s15, r4
 *   @0x13f570 str r12, [sp, #0x44]
 *   @0x13f574 vcvt.f64.s32 d5, s10
 *   @0x13f578 vstr d5, [sp, #8]
 *   @0x13f57c vmov s11, lr
 *   @0x13f580 vcvt.f64.s32 d6, s15
 *   @0x13f584 vcvt.f64.s32 d7, s11
 *   @0x13f588 vstr d6, [sp, #24]
 *   @0x13f58c vstr d7, [sp, #40]
 *   @0x13f590 vstr d7, [sp, #56]
 *   @0x13f594 bl 0x1269fc <_Z15F_DrawHighscoreR6RValueP9CInstanceS2_iPS_>
 *   @0x13f598 add sp, sp, #76
 *   @0x13f59c pop {r4, r5, pc}
 *   @0x13f5a0 .word 0x002ae3f4
 *
 * ══ §205/212 F_D3DTransformVertex(RValue&, CInstance*, CInstance*, int, RValue*)  0x144dc8  size 136  34 条（0x144dc8..0x144e50）
 * @func 0x144dc8 0x144e50  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×3 / GR_3D_TransformVertex(float&, float&, float&) / CreateArray(RValue*, int, ...)
 * 字段偏移 top8: 0x30×1 / 0x14×1 / 0x18×1 / 0x1c×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x144dc8 push {r4, r5, lr}
 *   @0x144dcc sub sp, sp, #36
 *   @0x144dd0 mov r5, r0
 *   @0x144dd4 mov r1, #0
 *   @0x144dd8 ldr r4, [sp, #0x30]
 *   @0x144ddc mov r0, r4
 *   @0x144de0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144de4 mov r1, #1
 *   @0x144de8 str r0, [sp, #0x14]
 *   @0x144dec mov r0, r4
 *   @0x144df0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144df4 mov r1, #2
 *   @0x144df8 str r0, [sp, #0x18]
 *   @0x144dfc mov r0, r4
 *   @0x144e00 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144e04 add r1, sp, #24
 *   @0x144e08 add r2, sp, #28
 *   @0x144e0c str r0, [sp, #0x1c]
 *   @0x144e10 add r0, sp, #20
 *   @0x144e14 bl 0x163c3c <_Z21GR_3D_TransformVertexRfS_S_>
 *   @0x144e18 vldr s14, [sp, #28]
 *   @0x144e1c vcvt.f64.f32 d7, s14
 *   @0x144e20 vldr s12, [sp, #24]
 *   @0x144e24 vldr s11, [sp, #20]
 *   @0x144e28 mov r0, r5
 *   @0x144e2c mov r1, #3
 *   @0x144e30 vcvt.f64.f32 d6, s12
 *   @0x144e34 vstr d7, [sp, #8]
 *   @0x144e38 vcvt.f64.f32 d7, s11
 *   @0x144e3c vstr d6, [sp]
 *   @0x144e40 vmov r2, r3, d7
 *   @0x144e44 bl 0x120eb4 <_Z11CreateArrayP6RValueiz>
 *   @0x144e48 add sp, sp, #36
 *   @0x144e4c pop {r4, r5, pc}
 *
 * ══ §206/212 F_PhysicsBindFixtureExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x14c70c  size 136  34 条（0x14c70c..0x14c794）
 * @func 0x14c70c 0x14c794  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / YYGetFloat(RValue const*, int)×2 / anon_14c57c
 * 字段偏移 top8: 0x20×1 / 0xc×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14c70c push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x14c710 mov r3, #0
 *   @0x14c714 ldr r4, [sp, #0x20]
 *   @0x14c718 mov r5, r0
 *   @0x14c71c str r3, [r0, #0xc]
 *   @0x14c720 mov r8, r1
 *   @0x14c724 mov r1, r3
 *   @0x14c728 mov r0, r4
 *   @0x14c72c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14c730 mov r1, #1
 *   @0x14c734 mov r7, r0
 *   @0x14c738 mov r0, r4
 *   @0x14c73c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14c740 mov r1, #2
 *   @0x14c744 mov r6, r0
 *   @0x14c748 mov r0, r4
 *   @0x14c74c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14c750 mov r1, #3
 *   @0x14c754 mov r9, r0
 *   @0x14c758 mov r0, r4
 *   @0x14c75c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14c760 mov r1, r7
 *   @0x14c764 mov r2, r6
 *   @0x14c768 vmov s0, r9
 *   @0x14c76c vmov s1, r0
 *   @0x14c770 mov r0, r8
 *   @0x14c774 bl 0x14c57c <_Z29F_PhysicsFixtureAddShapePointR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x14c778 vmov s15, r0
 *   @0x14c77c vcvt.f64.s32 d7, s15
 *   @0x14c780 vmov r0, r1, d7
 *   @0x14c784 vmov r2, s14
 *   @0x14c788 mov r3, r1
 *   @0x14c78c stm r5, {r2, r3}
 *   @0x14c790 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §207/212 F_PhysicsSetGravity(RValue&, CInstance*, CInstance*, int, RValue*)  0x14cf38  size 136  34 条（0x14cf38..0x14cfc0）
 * @func 0x14cf38 0x14cfc0  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2
 * 字段偏移 top8: 0xb4×2 / 0x74×1 / 0x10×1 / 0x20×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14cf38 ldr r3, [pc, #0x74]
 *   @0x14cf3c push {r4, r5, r6, lr}
 *   @0x14cf40 ldr r3, [pc, r3]
 *   @0x14cf44 ldr r5, [sp, #0x10]
 *   @0x14cf48 ldr r4, [r3]
 *   @0x14cf4c cmp r4, #0
 *   @0x14cf50 beq 0x14cfa0 <_Z19F_PhysicsSetGravityR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x14cf54 ldr r1, [r4, #0xb4]
 *   @0x14cf58 cmp r1, #0
 *   @0x14cf5c beq 0x14cf90 <_Z19F_PhysicsSetGravityR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x14cf60 mov r0, r5
 *   @0x14cf64 mov r1, #0
 *   @0x14cf68 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14cf6c mov r1, #1
 *   @0x14cf70 mov r6, r0
 *   @0x14cf74 mov r0, r5
 *   @0x14cf78 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14cf7c mov r1, r6
 *   @0x14cf80 mov r2, r0
 *   @0x14cf84 ldr r0, [r4, #0xb4]
 *   @0x14cf88 pop {r4, r5, r6, lr}
 *   @0x14cf8c b 0x238c14 <_ZN13CPhysicsWorld10SetGravityEff>
 *   @0x14cf90 ldr r0, [pc, #0x20]
 *   @0x14cf94 pop {r4, r5, r6, lr}
 *   @0x14cf98 add r0, pc, r0
 *   @0x14cf9c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14cfa0 ldr r0, [pc, #0x14]
 *   @0x14cfa4 mov r1, r4
 *   @0x14cfa8 pop {r4, r5, r6, lr}
 *   @0x14cfac add r0, pc, r0
 *   @0x14cfb0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14cfb4 eoreq r0, r10, r8, ror #19
 *   @0x14cfb8 andseq r6, pc, r12, lsl #29
 *   @0x14cfbc andseq r6, pc, r0, ror #30
 *
 * ══ §208/212 F_PhysicsDestroyParticleRegionCircle(RValue&, CInstance*, CInstance*, int, RValue*)  0x14d3b4  size 136  34 条（0x14d3b4..0x14d43c）
 * @func 0x14d3b4 0x14d43c  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×3
 * 字段偏移 top8: 0x78×1 / 0x18×1 / 0xb4×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14d3b4 ldr r3, [pc, #0x78]
 *   @0x14d3b8 push {r4, r5, r6, r7, r8, lr}
 *   @0x14d3bc ldr r3, [pc, r3]
 *   @0x14d3c0 ldr r4, [sp, #0x18]
 *   @0x14d3c4 ldr r3, [r3]
 *   @0x14d3c8 cmp r3, #0
 *   @0x14d3cc beq 0x14d420 <_Z36F_PhysicsDestroyParticleRegionCircleR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x14d3d0 ldr r5, [r3, #0xb4]
 *   @0x14d3d4 cmp r5, #0
 *   @0x14d3d8 beq 0x14d420 <_Z36F_PhysicsDestroyParticleRegionCircleR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x14d3dc mov r0, r4
 *   @0x14d3e0 mov r1, #0
 *   @0x14d3e4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14d3e8 mov r1, #1
 *   @0x14d3ec mov r7, r0
 *   @0x14d3f0 mov r0, r4
 *   @0x14d3f4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14d3f8 mov r1, #2
 *   @0x14d3fc mov r6, r0
 *   @0x14d400 mov r0, r4
 *   @0x14d404 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14d408 mov r1, r7
 *   @0x14d40c mov r2, r6
 *   @0x14d410 mov r3, r0
 *   @0x14d414 mov r0, r5
 *   @0x14d418 pop {r4, r5, r6, r7, r8, lr}
 *   @0x14d41c b 0x239f50 <_ZN13CPhysicsWorld26DeleteParticleCircleRegionEfff>
 *   @0x14d420 ldr r0, [pc, #0x10]
 *   @0x14d424 mov r1, #0
 *   @0x14d428 pop {r4, r5, r6, r7, r8, lr}
 *   @0x14d42c add r0, pc, r0
 *   @0x14d430 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14d434 eoreq r0, r10, r12, ror #10
 *   @0x14d438 andseq r6, pc, r12, lsl r12
 *
 * ══ §209/212 GR_3D_Transform_Add_Scaling(float, float, float)  0x163924  size 136  34 条（0x163924..0x1639ac）
 * @func 0x163924 0x1639ac  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics::GetMatrix(eMatrix, float*) / yyMatrix::Multiply(yyMatrix*, yyMatrix*, yyMatrix*) / Graphics::SetMatrix(eMatrix, float*) / DirtyRoomExtents()
 * 字段偏移 top8: 0x40×1 / 0x54×1 / 0x78×1 / 0x74×1 / 0x70×1 / 0x6c×1 / 0x64×1 / 0x60×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x163924 push {r4, lr}
 *   @0x163928 sub sp, sp, #192
 *   @0x16392c add r4, sp, #128
 *   @0x163930 mov r3, #0
 *   @0x163934 str r0, [sp, #0x40]
 *   @0x163938 mov r0, #2
 *   @0x16393c str r1, [sp, #0x54]
 *   @0x163940 mov r1, sp
 *   @0x163944 mov r12, #1065353216
 *   @0x163948 str r3, [sp, #0x78]
 *   @0x16394c str r3, [sp, #0x74]
 *   @0x163950 str r3, [sp, #0x70]
 *   @0x163954 str r3, [sp, #0x6c]
 *   @0x163958 str r3, [sp, #0x64]
 *   @0x16395c str r3, [sp, #0x60]
 *   @0x163960 str r12, [sp, #0x7c]
 *   @0x163964 str r3, [sp, #0x5c]
 *   @0x163968 str r3, [sp, #0x58]
 *   @0x16396c str r3, [sp, #0x50]
 *   @0x163970 str r3, [sp, #0x4c]
 *   @0x163974 str r3, [sp, #0x48]
 *   @0x163978 str r3, [sp, #0x44]
 *   @0x16397c str r2, [sp, #0x68]
 *   @0x163980 bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf>
 *   @0x163984 add r2, sp, #64
 *   @0x163988 mov r1, sp
 *   @0x16398c mov r0, r4
 *   @0x163990 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_>
 *   @0x163994 mov r1, r4
 *   @0x163998 mov r0, #2
 *   @0x16399c bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf>
 *   @0x1639a0 bl 0x168d7c <_Z16DirtyRoomExtentsv>
 *   @0x1639a4 add sp, sp, #192
 *   @0x1639a8 pop {r4, pc}
 *
 * ══ §210/212 CBitmap32::CBitmap32(CBitmap32*)  0x165f98  size 136  34 条（0x165f98..0x166020）
 * @func 0x165f98 0x166020  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb65bc
 * 字段偏移 top8: 0x8×3 / 0xc×3 / 0x4×2 / 0x14×2 / 0x5c×1 / 0x3c×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x165f98 push {r3, r4, r5, lr}
 *   @0x165f9c mov r5, r1
 *   @0x165fa0 ldrb r2, [r1, #0x4]
 *   @0x165fa4 mov r4, r0
 *   @0x165fa8 ldr r1, [r1, #0x8]
 *   @0x165fac ldr r0, [r5, #0xc]
 *   @0x165fb0 cmp r2, #0
 *   @0x165fb4 ldr r3, [pc, #0x5c]
 *   @0x165fb8 strb r2, [r4, #0x4]
 *   @0x165fbc ldr r3, [pc, r3]
 *   @0x165fc0 str r1, [r4, #0x8]
 *   @0x165fc4 add r3, r3, #8
 *   @0x165fc8 str r0, [r4, #0xc]
 *   @0x165fcc str r3, [r4]
 *   @0x165fd0 beq 0x166010 <_ZN9CBitmap32C2EPS_+0x78>
 *   @0x165fd4 mul r0, r0, r1
 *   @0x165fd8 ldr r1, [pc, #0x3c]
 *   @0x165fdc mov r2, #204
 *   @0x165fe0 mov r3, #1
 *   @0x165fe4 add r1, pc, r1
 *   @0x165fe8 lsl r0, r0, #2
 *   @0x165fec bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x165ff0 ldr r3, [r4, #0x8]
 *   @0x165ff4 ldr r2, [r4, #0xc]
 *   @0x165ff8 mul r2, r2, r3
 *   @0x165ffc lsl r2, r2, #2
 *   @0x166000 str r2, [r4, #0x10]
 *   @0x166004 str r0, [r4, #0x14]
 *   @0x166008 ldr r1, [r5, #0x14]
 *   @0x16600c bl 0xb65bc <memcpy@plt>
 *   @0x166010 mov r0, r4
 *   @0x166014 pop {r3, r4, r5, pc}
 *   @0x166018 eoreq r10, r8, r12, lsr r1
 *   @0x16601c ldrsbeq r4, [lr], -r12
 *
 * ══ §211/212 GR_Draw_Vertex(float, float)  0x16ba58  size 136  34 条（0x16ba58..0x16bae0）
 * @func 0x16ba58 0x16baf0  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x16ba5c→0x4899b0, 0x16ba78→0x4899b4, 0x16ba80→0x4859ac, 0x16ba88→0x3f23d0
 * 调用序列: 无
 * 字段偏移 top8: 0x6c×2 / 0x54×1 / 0x50×1 / 0x4c×1 / 0x4×1 / 0x8×1 / 0x14×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16ba58 ldr r3, [pc, #0x6c]
 *   @0x16ba5c ldr r2, [pc, #0x6c]
 *   @0x16ba60 add r3, pc, r3
 *   @0x16ba64 push {r4, r5, r6, r7, r8}
 *   @0x16ba68 ldr r4, [r3, r2]
 *   @0x16ba6c ldr r12, [r4]
 *   @0x16ba70 cmp r12, #1000
 *   @0x16ba74 bgt 0x16bac4 <_Z14GR_Draw_Vertexff+0x6c>
 *   @0x16ba78 ldr r2, [pc, #0x54]
 *   @0x16ba7c add r8, r12, r12, lsl #1
 *   @0x16ba80 ldr r7, [pc, #0x50]
 *   @0x16ba84 mov r5, #0
 *   @0x16ba88 ldr r6, [pc, #0x4c]
 *   @0x16ba8c add r12, r12, #1
 *   @0x16ba90 ldr r2, [r3, r2]
 *   @0x16ba94 add r2, r2, r8, lsl #3
 *   @0x16ba98 str r0, [r2]
 *   @0x16ba9c str r1, [r2, #0x4]
 *   @0x16baa0 ldr r1, [r3, r7]
 *   @0x16baa4 ldr r1, [r1]
 *   @0x16baa8 str r1, [r2, #0x8]
 *   @0x16baac ldr r3, [r3, r6]
 *   @0x16bab0 str r5, [r2, #0x14]
 *   @0x16bab4 str r12, [r4]
 *   @0x16bab8 ldr r3, [r3]
 *   @0x16babc str r5, [r2, #0x10]
 *   @0x16bac0 str r3, [r2, #0xc]
 *   @0x16bac4 pop {r4, r5, r6, r7, r8}
 *   @0x16bac8 bx lr
 *   @0x16bacc .word 0x002861f0
 *   @0x16bad0 .word 0xffffe534
 *   @0x16bad4 .word 0xffffe54c
 *   @0x16bad8 .word 0xffffbcd0
 *   @0x16badc .word 0xffffc0ac
 *
 * ══ §212/212 CBackground::LoadFromGIFData(void*, int, bool, bool, bool, bool)  0xc279c  size 128  32 条（0xc279c..0xc281c）
 * @func 0xc279c 0xc281c  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ReadGIFFile(void*, int, int*, int*, bool) / CBackground::LoadFromData(void*, int, int, bool, bool, bool, bool) / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x40×1 / 0x38×1 / 0x3c×1 / 0xc×1 / 0x10×1 / 0x14×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc279c push {r4, r5, r6, r7, r8, r9, lr}
 *   @0xc27a0 sub sp, sp, #28
 *   @0xc27a4 mov r12, #0
 *   @0xc27a8 mov r9, r0
 *   @0xc27ac mov r8, r3
 *   @0xc27b0 mov r0, r1
 *   @0xc27b4 str r12, [sp]
 *   @0xc27b8 mov r1, r2
 *   @0xc27bc add r3, sp, #20
 *   @0xc27c0 add r2, sp, #16
 *   @0xc27c4 ldrb r5, [sp, #0x40]
 *   @0xc27c8 ldrb r7, [sp, #0x38]
 *   @0xc27cc ldrb r6, [sp, #0x3c]
 *   @0xc27d0 bl 0x18a918 <_Z11ReadGIFFilePviPiS0_b>
 *   @0xc27d4 subs r4, r0, #0
 *   @0xc27d8 moveq r5, r4
 *   @0xc27dc beq 0xc2810 <_ZN11CBackground15LoadFromGIFDataEPvibbbb+0x74>
 *   @0xc27e0 str r5, [sp, #0xc]
 *   @0xc27e4 mov r0, r9
 *   @0xc27e8 ldr r2, [sp, #0x10]
 *   @0xc27ec mov r1, r4
 *   @0xc27f0 ldr r3, [sp, #0x14]
 *   @0xc27f4 str r8, [sp]
 *   @0xc27f8 str r7, [sp, #0x4]
 *   @0xc27fc str r6, [sp, #0x8]
 *   @0xc2800 bl 0xc2618 <_ZN11CBackground12LoadFromDataEPviibbbb>
 *   @0xc2804 mov r5, r0
 *   @0xc2808 mov r0, r4
 *   @0xc280c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xc2810 mov r0, r5
 *   @0xc2814 add sp, sp, #28
 *   @0xc2818 pop {r4, r5, r6, r7, r8, r9, pc}
 */
