/* cally 逆向卡：All_60 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 230 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/230 _SetTextureInfo(Texture*)  0x182e7c  size 136  34 条（0x182e7c..0x182f04）
 * @func 0x182e7c 0x182f04  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×4 / 0x8×4 / 0x2c×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x182e7c ldr r3, [r0, #0x2c]
 *   @0x182e80 movw r1, #0x4152
 *   @0x182e84 movt r1, #0x2057
 *   @0x182e88 mov r2, r0
 *   @0x182e8c ldr r12, [r3]
 *   @0x182e90 cmp r12, r1
 *   @0x182e94 beq 0x182ed8 <_Z15_SetTextureInfoP7Texture+0x5c>
 *   @0x182e98 movw r1, #0x5089
 *   @0x182e9c movt r1, #0x474e
 *   @0x182ea0 cmp r12, r1
 *   @0x182ea4 beq 0x182f00 <_Z15_SetTextureInfoP7Texture+0x84>
 *   @0x182ea8 ldr r0, [r3, #0x2c]
 *   @0x182eac movw r1, #0x5650
 *   @0x182eb0 movt r1, #0x2152
 *   @0x182eb4 cmp r0, r1
 *   @0x182eb8 bxne lr
 *   @0x182ebc ldr r1, [r3, #0x4]
 *   @0x182ec0 mov r0, #6
 *   @0x182ec4 ldr r3, [r3, #0x8]
 *   @0x182ec8 str r0, [r2]
 *   @0x182ecc str r1, [r2, #0x8]
 *   @0x182ed0 str r3, [r2, #0x4]
 *   @0x182ed4 bx lr
 *   @0x182ed8 ldr r0, [r3, #0xc]
 *   @0x182edc ldr r1, [r3, #0x8]
 *   @0x182ee0 ldr r3, [r3, #0x4]
 *   @0x182ee4 cmp r0, #1
 *   @0x182ee8 str r1, [r2, #0x8]
 *   @0x182eec str r3, [r2, #0x4]
 *   @0x182ef0 moveq r3, #11
 *   @0x182ef4 movne r3, #6
 *   @0x182ef8 str r3, [r2]
 *   @0x182efc bx lr
 *   @0x182f00 b 0x189968 <_Z14getTextureInfoP7Texture>
 *
 * ══ §2/230 anon_18b538  0x18b538  size 136  34 条（0x18b538..0x18b5c0）
 * @func 0x18b538 0x18b5c0  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FREE_RValue__Pre(RValue*) / YYSetString(RValue*, char const*) / F_DsMapFindValue(RValue&, CInstance*, CInstance*, int, RValue*)
 * 字段偏移 top8: 0xc×4 / 0x8×1 / 0x1c×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18b538 ldr r3, [r0, #0xc]
 *   @0x18b53c push {r4, r5, r6, lr}
 *   @0x18b540 sub r3, r3, #1
 *   @0x18b544 bic r3, r3, #-16777216
 *   @0x18b548 sub sp, sp, #48
 *   @0x18b54c bic r3, r3, #3
 *   @0x18b550 mov r4, r0
 *   @0x18b554 cmp r3, #0
 *   @0x18b558 mov r5, r2
 *   @0x18b55c bne 0x18b56c <_ZN11CIAPProduct11PopulateMapEi+0x224>
 *   @0x18b560 str r1, [sp, #0xc]
 *   @0x18b564 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x18b568 ldr r1, [sp, #0xc]
 *   @0x18b56c vmov s13, r1
 *   @0x18b570 mov r3, #5
 *   @0x18b574 str r3, [r4, #0xc]
 *   @0x18b578 add r6, sp, #48
 *   @0x18b57c vcvt.f64.s32 d7, s13
 *   @0x18b580 mov r1, r5
 *   @0x18b584 add r0, sp, #32
 *   @0x18b588 mov r5, #0
 *   @0x18b58c str r5, [r4, #0x8]
 *   @0x18b590 str r5, [r4]
 *   @0x18b594 str r5, [sp, #0x1c]
 *   @0x18b598 vmov r2, r3, d7
 *   @0x18b59c strd r2, r3, [r6, #-32]!
 *   @0x18b5a0 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x18b5a4 mov r1, r5
 *   @0x18b5a8 str r6, [sp]
 *   @0x18b5ac mov r0, r4
 *   @0x18b5b0 mov r2, r5
 *   @0x18b5b4 mov r3, #2
 *   @0x18b5b8 bl 0x106bcc <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_>
 *   @0x18b5bc add sp, sp, #48
 *
 * ══ §3/230 RegisterAndroidKeyEvent(int, int)  0x18ef50  size 136  34 条（0x18ef50..0x18efd8）
 * @func 0x18ef50 0x18efd8  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int)
 * 字段偏移 top8: 0x4×5 / 0x74×1 / 0x50×1 / 0x8×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18ef50 ldr r2, [pc, #0x74]
 *   @0x18ef54 push {r4, lr}
 *   @0x18ef58 add r2, pc, r2
 *   @0x18ef5c sub sp, sp, #8
 *   @0x18ef60 mov r4, r0
 *   @0x18ef64 ldr r3, [r2]
 *   @0x18ef68 cmp r3, #0
 *   @0x18ef6c beq 0x18efb4 <_Z23RegisterAndroidKeyEventii+0x64>
 *   @0x18ef70 ldr r0, [r3]
 *   @0x18ef74 str r0, [r2]
 *   @0x18ef78 ldr r12, [pc, #0x50]
 *   @0x18ef7c mov r0, #0
 *   @0x18ef80 str r4, [r3, #0x4]
 *   @0x18ef84 add r12, pc, r12
 *   @0x18ef88 str r1, [r3, #0x8]
 *   @0x18ef8c str r0, [r3]
 *   @0x18ef90 ldr r2, [r12, #0x4]
 *   @0x18ef94 cmp r2, r0
 *   @0x18ef98 streq r3, [r12, #0x8]
 *   @0x18ef9c strne r3, [r2]
 *   @0x18efa0 ldr r2, [pc, #0x2c]
 *   @0x18efa4 add r2, pc, r2
 *   @0x18efa8 str r3, [r2, #0x4]
 *   @0x18efac add sp, sp, #8
 *   @0x18efb0 pop {r4, pc}
 *   @0x18efb4 mov r0, #12
 *   @0x18efb8 str r1, [sp, #0x4]
 *   @0x18efbc bl 0x27c524 <_Znwj>
 *   @0x18efc0 ldr r1, [sp, #0x4]
 *   @0x18efc4 mov r3, r0
 *   @0x18efc8 b 0x18ef78 <_Z23RegisterAndroidKeyEventii+0x28>
 *   @0x18efcc eorseq r6, r10, r8, ror #14
 *   @0x18efd0 eorseq r6, r10, r12, lsr r7
 *   @0x18efd4 eorseq r6, r10, r12, lsl r7
 *
 * ══ §4/230 Path_Find(char const*)  0x1a80d4  size 136  34 条（0x1a80d4..0x1a815c）
 * @func 0x1a80d4 0x1a815c  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Path_Find(char const*)+0x6c / 0xb6574
 * 字段偏移 top8: 0x6c×1 / 0x5c×1 / 0x58×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a80d4 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x1a80d8 mov r7, r0
 *   @0x1a80dc ldr r3, [pc, #0x6c]
 *   @0x1a80e0 ldr r3, [pc, r3]
 *   @0x1a80e4 ldr r6, [r3]
 *   @0x1a80e8 cmp r6, #0
 *   @0x1a80ec ble 0x1a8140 <_Z9Path_FindPKc+0x6c>
 *   @0x1a80f0 ldr r3, [pc, #0x5c]
 *   @0x1a80f4 mov r4, #0
 *   @0x1a80f8 ldr r2, [pc, #0x58]
 *   @0x1a80fc mov r5, r4
 *   @0x1a8100 ldr r3, [pc, r3]
 *   @0x1a8104 add r2, pc, r2
 *   @0x1a8108 ldr r9, [r3]
 *   @0x1a810c ldr r8, [r2, #0x4]
 *   @0x1a8110 ldr r3, [r8, r4]
 *   @0x1a8114 mov r1, r7
 *   @0x1a8118 cmp r3, #0
 *   @0x1a811c beq 0x1a8130 <_Z9Path_FindPKc+0x5c>
 *   @0x1a8120 ldr r0, [r9, r4]
 *   @0x1a8124 bl 0xb6574 <strcmp@plt>
 *   @0x1a8128 cmp r0, #0
 *   @0x1a812c beq 0x1a8148 <_Z9Path_FindPKc+0x74>
 *   @0x1a8130 add r5, r5, #1
 *   @0x1a8134 add r4, r4, #4
 *   @0x1a8138 cmp r5, r6
 *   @0x1a813c bne 0x1a8110 <_Z9Path_FindPKc+0x3c>
 *   @0x1a8140 mvn r0, #0
 *   @0x1a8144 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1a8148 mov r0, r5
 *   @0x1a814c pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1a8150 eoreq r8, r4, r12, ror #13
 *   @0x1a8154 .word 0x002486d0
 *   @0x1a8158 eorseq r10, r9, r4, lsr #8
 *
 * ══ §5/230 F_LayerGetId(RValue&, CInstance*, CInstance*, int, RValue*)  0x1ba778  size 136  34 条（0x1ba778..0x1ba800）
 * @func 0x1ba778 0x1ba800  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetString(RValue const*, int) / CLayerManager::GetLayerFromName(CRoom*, char const*)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x18×1 / 0x50×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1ba778 cmp r3, #1
 *   @0x1ba77c push {r3, r4, r5, r6, r7, lr}
 *   @0x1ba780 mov r3, #0
 *   @0x1ba784 mov r5, r3
 *   @0x1ba788 mov r4, r0
 *   @0x1ba78c movt r3, #0xbff0
 *   @0x1ba790 str r5, [r0, #0xc]
 *   @0x1ba794 str r3, [r0, #0x4]
 *   @0x1ba798 str r5, [r0]
 *   @0x1ba79c ldr r6, [sp, #0x18]
 *   @0x1ba7a0 beq 0x1ba7b8 <_Z12F_LayerGetIdR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1ba7a4 ldr r0, [pc, #0x50]
 *   @0x1ba7a8 mov r1, r5
 *   @0x1ba7ac pop {r3, r4, r5, r6, r7, lr}
 *   @0x1ba7b0 add r0, pc, r0
 *   @0x1ba7b4 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1ba7b8 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1ba7bc subs r7, r0, #0
 *   @0x1ba7c0 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1ba7c4 mov r1, r5
 *   @0x1ba7c8 mov r0, r6
 *   @0x1ba7cc bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1ba7d0 mov r1, r0
 *   @0x1ba7d4 mov r0, r7
 *   @0x1ba7d8 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc>
 *   @0x1ba7dc cmp r0, #0
 *   @0x1ba7e0 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1ba7e4 ldr r2, [r0]
 *   @0x1ba7e8 vmov s15, r2
 *   @0x1ba7ec vcvt.f64.s32 d7, s15
 *   @0x1ba7f0 vmov r2, r3, d7
 *   @0x1ba7f4 stm r4, {r2, r3}
 *   @0x1ba7f8 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1ba7fc andseq r2, r9, r12, asr pc
 *
 * ══ §6/230 CSprite::CSprite()  0x1e761c  size 136  34 条（0x1e761c..0x1e76a4）
 * @func 0x1e761c 0x1e76a4  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CSprite::Clear()
 * 字段偏移 top8: 0x7c×2 / 0x35×1 / 0x40×1 / 0x3c×1 / 0x48×1 / 0x44×1 / 0x18×1 / 0x6c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e761c ldr r3, [pc, #0x7c]
 *   @0x1e7620 mov r2, #1
 *   @0x1e7624 push {r4, lr}
 *   @0x1e7628 ldr r3, [pc, r3]
 *   @0x1e762c mov r4, r0
 *   @0x1e7630 strb r2, [r0, #0x35]
 *   @0x1e7634 mov r1, #0
 *   @0x1e7638 add r2, r3, #8
 *   @0x1e763c movt r1, #0x41f0
 *   @0x1e7640 mov r3, #0
 *   @0x1e7644 str r2, [r0]
 *   @0x1e7648 str r3, [r0, #0x40]
 *   @0x1e764c str r3, [r0, #0x3c]
 *   @0x1e7650 str r3, [r0, #0x48]
 *   @0x1e7654 str r3, [r0, #0x44]
 *   @0x1e7658 str r3, [r0, #0x18]
 *   @0x1e765c str r1, [r0, #0x6c]
 *   @0x1e7660 str r3, [r0, #0x50]
 *   @0x1e7664 str r3, [r0, #0x4c]
 *   @0x1e7668 strb r3, [r0, #0x31]
 *   @0x1e766c strb r3, [r0, #0x36]
 *   @0x1e7670 str r3, [r0, #0x74]
 *   @0x1e7674 strb r3, [r0, #0x78]
 *   @0x1e7678 str r3, [r0, #0x7c]
 *   @0x1e767c str r3, [r0, #0x84]
 *   @0x1e7680 str r3, [r0, #0x80]
 *   @0x1e7684 str r3, [r0, #0x58]
 *   @0x1e7688 str r3, [r0, #0x64]
 *   @0x1e768c str r3, [r0, #0x68]
 *   @0x1e7690 str r3, [r0, #0x70]
 *   @0x1e7694 bl 0x1e6b4c <_ZN7CSprite5ClearEv>
 *   @0x1e7698 mov r0, r4
 *   @0x1e769c pop {r4, pc}
 *   @0x1e76a0 eoreq r9, r0, r8, lsr #15
 *
 * ══ §7/230 GV_Argument1(CInstance*, int, RValue*)  0x1ffea0  size 136  34 条（0x1ffea0..0x1fff28）
 * @func 0x1ffea0 0x1fff38  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GV_Argument1(CInstance*, int, RValue*)+0x6c / GET_RValue(RValue*, RValue*, int) / FREE_RValue__Pre(RValue*)
 * 字段偏移 top8: 0xc×2 / 0x54×1 / 0x8×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1ffea0 push {r3, r4, r5, lr}
 *   @0x1ffea4 mov r4, r2
 *   @0x1ffea8 ldr r3, [r2, #0xc]
 *   @0x1ffeac mov r5, r1
 *   @0x1ffeb0 sub r3, r3, #1
 *   @0x1ffeb4 bic r3, r3, #-16777216
 *   @0x1ffeb8 bic r3, r3, #3
 *   @0x1ffebc cmp r3, #0
 *   @0x1ffec0 beq 0x1fff14 <_Z12GV_Argument1P9CInstanceiP6RValue+0x74>
 *   @0x1ffec4 ldr r3, [pc, #0x54]
 *   @0x1ffec8 mov r0, #0
 *   @0x1ffecc str r0, [r4]
 *   @0x1ffed0 mov r12, #5
 *   @0x1ffed4 ldr r3, [pc, r3]
 *   @0x1ffed8 str r0, [r4, #0x8]
 *   @0x1ffedc str r12, [r4, #0xc]
 *   @0x1ffee0 ldr r3, [r3]
 *   @0x1ffee4 cmp r3, #1
 *   @0x1ffee8 strle r0, [r4, #0x4]
 *   @0x1ffeec ble 0x1fff0c <_Z12GV_Argument1P9CInstanceiP6RValue+0x6c>
 *   @0x1ffef0 ldr r3, [pc, #0x2c]
 *   @0x1ffef4 mov r0, r4
 *   @0x1ffef8 mov r2, r5
 *   @0x1ffefc ldr r3, [pc, r3]
 *   @0x1fff00 ldr r1, [r3]
 *   @0x1fff04 add r1, r1, #16
 *   @0x1fff08 bl 0xd13bc <_Z10GET_RValueP6RValueS0_i>
 *   @0x1fff0c mov r0, #1
 *   @0x1fff10 pop {r3, r4, r5, pc}
 *   @0x1fff14 mov r0, r2
 *   @0x1fff18 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x1fff1c b 0x1ffec4 <_Z12GV_Argument1P9CInstanceiP6RValue+0x24>
 *   @0x1fff20 andseq sp, lr, r8, lsr lr
 *   @0x1fff24 andseq sp, lr, r4, lsl lr
 *
 * ══ §8/230 GV_Argument2(CInstance*, int, RValue*)  0x1fff28  size 136  34 条（0x1fff28..0x1fffb0）
 * @func 0x1fff28 0x1fffc0  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GV_Argument2(CInstance*, int, RValue*)+0x6c / GET_RValue(RValue*, RValue*, int) / FREE_RValue__Pre(RValue*)
 * 字段偏移 top8: 0xc×2 / 0x54×1 / 0x8×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fff28 push {r3, r4, r5, lr}
 *   @0x1fff2c mov r4, r2
 *   @0x1fff30 ldr r3, [r2, #0xc]
 *   @0x1fff34 mov r5, r1
 *   @0x1fff38 sub r3, r3, #1
 *   @0x1fff3c bic r3, r3, #-16777216
 *   @0x1fff40 bic r3, r3, #3
 *   @0x1fff44 cmp r3, #0
 *   @0x1fff48 beq 0x1fff9c <_Z12GV_Argument2P9CInstanceiP6RValue+0x74>
 *   @0x1fff4c ldr r0, [pc, #0x54]
 *   @0x1fff50 mov r3, #0
 *   @0x1fff54 str r3, [r4]
 *   @0x1fff58 mov r12, #5
 *   @0x1fff5c ldr r0, [pc, r0]
 *   @0x1fff60 str r3, [r4, #0x8]
 *   @0x1fff64 str r12, [r4, #0xc]
 *   @0x1fff68 ldr r0, [r0]
 *   @0x1fff6c cmp r0, #2
 *   @0x1fff70 strle r3, [r4, #0x4]
 *   @0x1fff74 ble 0x1fff94 <_Z12GV_Argument2P9CInstanceiP6RValue+0x6c>
 *   @0x1fff78 ldr r3, [pc, #0x2c]
 *   @0x1fff7c mov r0, r4
 *   @0x1fff80 mov r2, r5
 *   @0x1fff84 ldr r3, [pc, r3]
 *   @0x1fff88 ldr r1, [r3]
 *   @0x1fff8c add r1, r1, #32
 *   @0x1fff90 bl 0xd13bc <_Z10GET_RValueP6RValueS0_i>
 *   @0x1fff94 mov r0, #1
 *   @0x1fff98 pop {r3, r4, r5, pc}
 *   @0x1fff9c mov r0, r2
 *   @0x1fffa0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x1fffa4 b 0x1fff4c <_Z12GV_Argument2P9CInstanceiP6RValue+0x24>
 *   @0x1fffa8 ldrheq sp, [lr], -r0
 *   @0x1fffac andseq sp, lr, r12, lsl #27
 *
 * ══ §9/230 GV_Argument3(CInstance*, int, RValue*)  0x1fffb0  size 136  34 条（0x1fffb0..0x200038）
 * @func 0x1fffb0 0x200048  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GV_Argument3(CInstance*, int, RValue*)+0x6c / GET_RValue(RValue*, RValue*, int) / FREE_RValue__Pre(RValue*)
 * 字段偏移 top8: 0xc×2 / 0x54×1 / 0x8×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fffb0 push {r3, r4, r5, lr}
 *   @0x1fffb4 mov r4, r2
 *   @0x1fffb8 ldr r3, [r2, #0xc]
 *   @0x1fffbc mov r5, r1
 *   @0x1fffc0 sub r3, r3, #1
 *   @0x1fffc4 bic r3, r3, #-16777216
 *   @0x1fffc8 bic r3, r3, #3
 *   @0x1fffcc cmp r3, #0
 *   @0x1fffd0 beq 0x200024 <_Z12GV_Argument3P9CInstanceiP6RValue+0x74>
 *   @0x1fffd4 ldr r0, [pc, #0x54]
 *   @0x1fffd8 mov r3, #0
 *   @0x1fffdc str r3, [r4]
 *   @0x1fffe0 mov r12, #5
 *   @0x1fffe4 ldr r0, [pc, r0]
 *   @0x1fffe8 str r3, [r4, #0x8]
 *   @0x1fffec str r12, [r4, #0xc]
 *   @0x1ffff0 ldr r0, [r0]
 *   @0x1ffff4 cmp r0, #3
 *   @0x1ffff8 strle r3, [r4, #0x4]
 *   @0x1ffffc ble 0x20001c <_Z12GV_Argument3P9CInstanceiP6RValue+0x6c>
 *   @0x200000 ldr r3, [pc, #0x2c]
 *   @0x200004 mov r0, r4
 *   @0x200008 mov r2, r5
 *   @0x20000c ldr r3, [pc, r3]
 *   @0x200010 ldr r1, [r3]
 *   @0x200014 add r1, r1, #48
 *   @0x200018 bl 0xd13bc <_Z10GET_RValueP6RValueS0_i>
 *   @0x20001c mov r0, #1
 *   @0x200020 pop {r3, r4, r5, pc}
 *   @0x200024 mov r0, r2
 *   @0x200028 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20002c b 0x1fffd4 <_Z12GV_Argument3P9CInstanceiP6RValue+0x24>
 *   @0x200030 andseq sp, lr, r8, lsr #26
 *   @0x200034 andseq sp, lr, r4, lsl #26
 *
 * ══ §10/230 GV_Argument4(CInstance*, int, RValue*)  0x200038  size 136  34 条（0x200038..0x2000c0）
 * @func 0x200038 0x2000d0  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GV_Argument4(CInstance*, int, RValue*)+0x6c / GET_RValue(RValue*, RValue*, int) / FREE_RValue__Pre(RValue*)
 * 字段偏移 top8: 0xc×2 / 0x54×1 / 0x8×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x200038 push {r3, r4, r5, lr}
 *   @0x20003c mov r4, r2
 *   @0x200040 ldr r3, [r2, #0xc]
 *   @0x200044 mov r5, r1
 *   @0x200048 sub r3, r3, #1
 *   @0x20004c bic r3, r3, #-16777216
 *   @0x200050 bic r3, r3, #3
 *   @0x200054 cmp r3, #0
 *   @0x200058 beq 0x2000ac <_Z12GV_Argument4P9CInstanceiP6RValue+0x74>
 *   @0x20005c ldr r0, [pc, #0x54]
 *   @0x200060 mov r3, #0
 *   @0x200064 str r3, [r4]
 *   @0x200068 mov r12, #5
 *   @0x20006c ldr r0, [pc, r0]
 *   @0x200070 str r3, [r4, #0x8]
 *   @0x200074 str r12, [r4, #0xc]
 *   @0x200078 ldr r0, [r0]
 *   @0x20007c cmp r0, #4
 *   @0x200080 strle r3, [r4, #0x4]
 *   @0x200084 ble 0x2000a4 <_Z12GV_Argument4P9CInstanceiP6RValue+0x6c>
 *   @0x200088 ldr r3, [pc, #0x2c]
 *   @0x20008c mov r0, r4
 *   @0x200090 mov r2, r5
 *   @0x200094 ldr r3, [pc, r3]
 *   @0x200098 ldr r1, [r3]
 *   @0x20009c add r1, r1, #64
 *   @0x2000a0 bl 0xd13bc <_Z10GET_RValueP6RValueS0_i>
 *   @0x2000a4 mov r0, #1
 *   @0x2000a8 pop {r3, r4, r5, pc}
 *   @0x2000ac mov r0, r2
 *   @0x2000b0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x2000b4 b 0x20005c <_Z12GV_Argument4P9CInstanceiP6RValue+0x24>
 *   @0x2000b8 andseq sp, lr, r0, lsr #25
 *   @0x2000bc andseq sp, lr, r12, ror r12
 *
 * ══ §11/230 GV_Argument5(CInstance*, int, RValue*)  0x2000c0  size 136  34 条（0x2000c0..0x200148）
 * @func 0x2000c0 0x200158  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GV_Argument5(CInstance*, int, RValue*)+0x6c / GET_RValue(RValue*, RValue*, int) / FREE_RValue__Pre(RValue*)
 * 字段偏移 top8: 0xc×2 / 0x54×1 / 0x8×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2000c0 push {r3, r4, r5, lr}
 *   @0x2000c4 mov r4, r2
 *   @0x2000c8 ldr r3, [r2, #0xc]
 *   @0x2000cc mov r5, r1
 *   @0x2000d0 sub r3, r3, #1
 *   @0x2000d4 bic r3, r3, #-16777216
 *   @0x2000d8 bic r3, r3, #3
 *   @0x2000dc cmp r3, #0
 *   @0x2000e0 beq 0x200134 <_Z12GV_Argument5P9CInstanceiP6RValue+0x74>
 *   @0x2000e4 ldr r0, [pc, #0x54]
 *   @0x2000e8 mov r3, #0
 *   @0x2000ec str r3, [r4]
 *   @0x2000f0 mov r12, #5
 *   @0x2000f4 ldr r0, [pc, r0]
 *   @0x2000f8 str r3, [r4, #0x8]
 *   @0x2000fc str r12, [r4, #0xc]
 *   @0x200100 ldr r0, [r0]
 *   @0x200104 cmp r0, r12
 *   @0x200108 strle r3, [r4, #0x4]
 *   @0x20010c ble 0x20012c <_Z12GV_Argument5P9CInstanceiP6RValue+0x6c>
 *   @0x200110 ldr r3, [pc, #0x2c]
 *   @0x200114 mov r0, r4
 *   @0x200118 mov r2, r5
 *   @0x20011c ldr r3, [pc, r3]
 *   @0x200120 ldr r1, [r3]
 *   @0x200124 add r1, r1, #80
 *   @0x200128 bl 0xd13bc <_Z10GET_RValueP6RValueS0_i>
 *   @0x20012c mov r0, #1
 *   @0x200130 pop {r3, r4, r5, pc}
 *   @0x200134 mov r0, r2
 *   @0x200138 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20013c b 0x2000e4 <_Z12GV_Argument5P9CInstanceiP6RValue+0x24>
 *   @0x200140 andseq sp, lr, r8, lsl r12
 *   @0x200144 ldrsheq sp, [lr], -r4
 *
 * ══ §12/230 GV_Argument6(CInstance*, int, RValue*)  0x200148  size 136  34 条（0x200148..0x2001d0）
 * @func 0x200148 0x2001e0  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GV_Argument6(CInstance*, int, RValue*)+0x6c / GET_RValue(RValue*, RValue*, int) / FREE_RValue__Pre(RValue*)
 * 字段偏移 top8: 0xc×2 / 0x54×1 / 0x8×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x200148 push {r3, r4, r5, lr}
 *   @0x20014c mov r4, r2
 *   @0x200150 ldr r3, [r2, #0xc]
 *   @0x200154 mov r5, r1
 *   @0x200158 sub r3, r3, #1
 *   @0x20015c bic r3, r3, #-16777216
 *   @0x200160 bic r3, r3, #3
 *   @0x200164 cmp r3, #0
 *   @0x200168 beq 0x2001bc <_Z12GV_Argument6P9CInstanceiP6RValue+0x74>
 *   @0x20016c ldr r0, [pc, #0x54]
 *   @0x200170 mov r3, #0
 *   @0x200174 str r3, [r4]
 *   @0x200178 mov r12, #5
 *   @0x20017c ldr r0, [pc, r0]
 *   @0x200180 str r3, [r4, #0x8]
 *   @0x200184 str r12, [r4, #0xc]
 *   @0x200188 ldr r0, [r0]
 *   @0x20018c cmp r0, #6
 *   @0x200190 strle r3, [r4, #0x4]
 *   @0x200194 ble 0x2001b4 <_Z12GV_Argument6P9CInstanceiP6RValue+0x6c>
 *   @0x200198 ldr r3, [pc, #0x2c]
 *   @0x20019c mov r0, r4
 *   @0x2001a0 mov r2, r5
 *   @0x2001a4 ldr r3, [pc, r3]
 *   @0x2001a8 ldr r1, [r3]
 *   @0x2001ac add r1, r1, #96
 *   @0x2001b0 bl 0xd13bc <_Z10GET_RValueP6RValueS0_i>
 *   @0x2001b4 mov r0, #1
 *   @0x2001b8 pop {r3, r4, r5, pc}
 *   @0x2001bc mov r0, r2
 *   @0x2001c0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x2001c4 b 0x20016c <_Z12GV_Argument6P9CInstanceiP6RValue+0x24>
 *   @0x2001c8 mulseq lr, r0, r11
 *   @0x2001cc andseq sp, lr, r12, ror #22
 *
 * ══ §13/230 GV_Argument7(CInstance*, int, RValue*)  0x2001d0  size 136  34 条（0x2001d0..0x200258）
 * @func 0x2001d0 0x200268  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GV_Argument7(CInstance*, int, RValue*)+0x6c / GET_RValue(RValue*, RValue*, int) / FREE_RValue__Pre(RValue*)
 * 字段偏移 top8: 0xc×2 / 0x54×1 / 0x8×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2001d0 push {r3, r4, r5, lr}
 *   @0x2001d4 mov r4, r2
 *   @0x2001d8 ldr r3, [r2, #0xc]
 *   @0x2001dc mov r5, r1
 *   @0x2001e0 sub r3, r3, #1
 *   @0x2001e4 bic r3, r3, #-16777216
 *   @0x2001e8 bic r3, r3, #3
 *   @0x2001ec cmp r3, #0
 *   @0x2001f0 beq 0x200244 <_Z12GV_Argument7P9CInstanceiP6RValue+0x74>
 *   @0x2001f4 ldr r0, [pc, #0x54]
 *   @0x2001f8 mov r3, #0
 *   @0x2001fc str r3, [r4]
 *   @0x200200 mov r12, #5
 *   @0x200204 ldr r0, [pc, r0]
 *   @0x200208 str r3, [r4, #0x8]
 *   @0x20020c str r12, [r4, #0xc]
 *   @0x200210 ldr r0, [r0]
 *   @0x200214 cmp r0, #7
 *   @0x200218 strle r3, [r4, #0x4]
 *   @0x20021c ble 0x20023c <_Z12GV_Argument7P9CInstanceiP6RValue+0x6c>
 *   @0x200220 ldr r3, [pc, #0x2c]
 *   @0x200224 mov r0, r4
 *   @0x200228 mov r2, r5
 *   @0x20022c ldr r3, [pc, r3]
 *   @0x200230 ldr r1, [r3]
 *   @0x200234 add r1, r1, #112
 *   @0x200238 bl 0xd13bc <_Z10GET_RValueP6RValueS0_i>
 *   @0x20023c mov r0, #1
 *   @0x200240 pop {r3, r4, r5, pc}
 *   @0x200244 mov r0, r2
 *   @0x200248 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20024c b 0x2001f4 <_Z12GV_Argument7P9CInstanceiP6RValue+0x24>
 *   @0x200250 andseq sp, lr, r8, lsl #22
 *   @0x200254 andseq sp, lr, r4, ror #21
 *
 * ══ §14/230 GV_Argument8(CInstance*, int, RValue*)  0x200258  size 136  34 条（0x200258..0x2002e0）
 * @func 0x200258 0x2002f0  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GV_Argument8(CInstance*, int, RValue*)+0x6c / GET_RValue(RValue*, RValue*, int) / FREE_RValue__Pre(RValue*)
 * 字段偏移 top8: 0xc×2 / 0x54×1 / 0x8×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x200258 push {r3, r4, r5, lr}
 *   @0x20025c mov r4, r2
 *   @0x200260 ldr r3, [r2, #0xc]
 *   @0x200264 mov r5, r1
 *   @0x200268 sub r3, r3, #1
 *   @0x20026c bic r3, r3, #-16777216
 *   @0x200270 bic r3, r3, #3
 *   @0x200274 cmp r3, #0
 *   @0x200278 beq 0x2002cc <_Z12GV_Argument8P9CInstanceiP6RValue+0x74>
 *   @0x20027c ldr r0, [pc, #0x54]
 *   @0x200280 mov r3, #0
 *   @0x200284 str r3, [r4]
 *   @0x200288 mov r12, #5
 *   @0x20028c ldr r0, [pc, r0]
 *   @0x200290 str r3, [r4, #0x8]
 *   @0x200294 str r12, [r4, #0xc]
 *   @0x200298 ldr r0, [r0]
 *   @0x20029c cmp r0, #8
 *   @0x2002a0 strle r3, [r4, #0x4]
 *   @0x2002a4 ble 0x2002c4 <_Z12GV_Argument8P9CInstanceiP6RValue+0x6c>
 *   @0x2002a8 ldr r3, [pc, #0x2c]
 *   @0x2002ac mov r0, r4
 *   @0x2002b0 mov r2, r5
 *   @0x2002b4 ldr r3, [pc, r3]
 *   @0x2002b8 ldr r1, [r3]
 *   @0x2002bc add r1, r1, #128
 *   @0x2002c0 bl 0xd13bc <_Z10GET_RValueP6RValueS0_i>
 *   @0x2002c4 mov r0, #1
 *   @0x2002c8 pop {r3, r4, r5, pc}
 *   @0x2002cc mov r0, r2
 *   @0x2002d0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x2002d4 b 0x20027c <_Z12GV_Argument8P9CInstanceiP6RValue+0x24>
 *   @0x2002d8 andseq sp, lr, r0, lsl #21
 *   @0x2002dc andseq sp, lr, r12, asr r10
 *
 * ══ §15/230 GV_Argument9(CInstance*, int, RValue*)  0x2002e0  size 136  34 条（0x2002e0..0x200368）
 * @func 0x2002e0 0x200378  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GV_Argument9(CInstance*, int, RValue*)+0x6c / GET_RValue(RValue*, RValue*, int) / FREE_RValue__Pre(RValue*)
 * 字段偏移 top8: 0xc×2 / 0x54×1 / 0x8×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2002e0 push {r3, r4, r5, lr}
 *   @0x2002e4 mov r4, r2
 *   @0x2002e8 ldr r3, [r2, #0xc]
 *   @0x2002ec mov r5, r1
 *   @0x2002f0 sub r3, r3, #1
 *   @0x2002f4 bic r3, r3, #-16777216
 *   @0x2002f8 bic r3, r3, #3
 *   @0x2002fc cmp r3, #0
 *   @0x200300 beq 0x200354 <_Z12GV_Argument9P9CInstanceiP6RValue+0x74>
 *   @0x200304 ldr r0, [pc, #0x54]
 *   @0x200308 mov r3, #0
 *   @0x20030c str r3, [r4]
 *   @0x200310 mov r12, #5
 *   @0x200314 ldr r0, [pc, r0]
 *   @0x200318 str r3, [r4, #0x8]
 *   @0x20031c str r12, [r4, #0xc]
 *   @0x200320 ldr r0, [r0]
 *   @0x200324 cmp r0, #9
 *   @0x200328 strle r3, [r4, #0x4]
 *   @0x20032c ble 0x20034c <_Z12GV_Argument9P9CInstanceiP6RValue+0x6c>
 *   @0x200330 ldr r3, [pc, #0x2c]
 *   @0x200334 mov r0, r4
 *   @0x200338 mov r2, r5
 *   @0x20033c ldr r3, [pc, r3]
 *   @0x200340 ldr r1, [r3]
 *   @0x200344 add r1, r1, #144
 *   @0x200348 bl 0xd13bc <_Z10GET_RValueP6RValueS0_i>
 *   @0x20034c mov r0, #1
 *   @0x200350 pop {r3, r4, r5, pc}
 *   @0x200354 mov r0, r2
 *   @0x200358 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20035c b 0x200304 <_Z12GV_Argument9P9CInstanceiP6RValue+0x24>
 *   @0x200360 ldrsheq sp, [lr], -r8
 *   @0x200364 ldrsbeq sp, [lr], -r4
 *
 * ══ §16/230 GV_Argument10(CInstance*, int, RValue*)  0x200368  size 136  34 条（0x200368..0x2003f0）
 * @func 0x200368 0x200400  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GV_Argument10(CInstance*, int, RValue*)+0x6c / GET_RValue(RValue*, RValue*, int) / FREE_RValue__Pre(RValue*)
 * 字段偏移 top8: 0xc×2 / 0x54×1 / 0x8×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x200368 push {r3, r4, r5, lr}
 *   @0x20036c mov r4, r2
 *   @0x200370 ldr r3, [r2, #0xc]
 *   @0x200374 mov r5, r1
 *   @0x200378 sub r3, r3, #1
 *   @0x20037c bic r3, r3, #-16777216
 *   @0x200380 bic r3, r3, #3
 *   @0x200384 cmp r3, #0
 *   @0x200388 beq 0x2003dc <_Z13GV_Argument10P9CInstanceiP6RValue+0x74>
 *   @0x20038c ldr r0, [pc, #0x54]
 *   @0x200390 mov r3, #0
 *   @0x200394 str r3, [r4]
 *   @0x200398 mov r12, #5
 *   @0x20039c ldr r0, [pc, r0]
 *   @0x2003a0 str r3, [r4, #0x8]
 *   @0x2003a4 str r12, [r4, #0xc]
 *   @0x2003a8 ldr r0, [r0]
 *   @0x2003ac cmp r0, #10
 *   @0x2003b0 strle r3, [r4, #0x4]
 *   @0x2003b4 ble 0x2003d4 <_Z13GV_Argument10P9CInstanceiP6RValue+0x6c>
 *   @0x2003b8 ldr r3, [pc, #0x2c]
 *   @0x2003bc mov r0, r4
 *   @0x2003c0 mov r2, r5
 *   @0x2003c4 ldr r3, [pc, r3]
 *   @0x2003c8 ldr r1, [r3]
 *   @0x2003cc add r1, r1, #160
 *   @0x2003d0 bl 0xd13bc <_Z10GET_RValueP6RValueS0_i>
 *   @0x2003d4 mov r0, #1
 *   @0x2003d8 pop {r3, r4, r5, pc}
 *   @0x2003dc mov r0, r2
 *   @0x2003e0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x2003e4 b 0x20038c <_Z13GV_Argument10P9CInstanceiP6RValue+0x24>
 *   @0x2003e8 andseq sp, lr, r0, ror r9
 *   @0x2003ec andseq sp, lr, r12, asr #18
 *
 * ══ §17/230 GV_Argument11(CInstance*, int, RValue*)  0x2003f0  size 136  34 条（0x2003f0..0x200478）
 * @func 0x2003f0 0x200488  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GV_Argument11(CInstance*, int, RValue*)+0x6c / GET_RValue(RValue*, RValue*, int) / FREE_RValue__Pre(RValue*)
 * 字段偏移 top8: 0xc×2 / 0x54×1 / 0x8×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2003f0 push {r3, r4, r5, lr}
 *   @0x2003f4 mov r4, r2
 *   @0x2003f8 ldr r3, [r2, #0xc]
 *   @0x2003fc mov r5, r1
 *   @0x200400 sub r3, r3, #1
 *   @0x200404 bic r3, r3, #-16777216
 *   @0x200408 bic r3, r3, #3
 *   @0x20040c cmp r3, #0
 *   @0x200410 beq 0x200464 <_Z13GV_Argument11P9CInstanceiP6RValue+0x74>
 *   @0x200414 ldr r0, [pc, #0x54]
 *   @0x200418 mov r3, #0
 *   @0x20041c str r3, [r4]
 *   @0x200420 mov r12, #5
 *   @0x200424 ldr r0, [pc, r0]
 *   @0x200428 str r3, [r4, #0x8]
 *   @0x20042c str r12, [r4, #0xc]
 *   @0x200430 ldr r0, [r0]
 *   @0x200434 cmp r0, #11
 *   @0x200438 strle r3, [r4, #0x4]
 *   @0x20043c ble 0x20045c <_Z13GV_Argument11P9CInstanceiP6RValue+0x6c>
 *   @0x200440 ldr r3, [pc, #0x2c]
 *   @0x200444 mov r0, r4
 *   @0x200448 mov r2, r5
 *   @0x20044c ldr r3, [pc, r3]
 *   @0x200450 ldr r1, [r3]
 *   @0x200454 add r1, r1, #176
 *   @0x200458 bl 0xd13bc <_Z10GET_RValueP6RValueS0_i>
 *   @0x20045c mov r0, #1
 *   @0x200460 pop {r3, r4, r5, pc}
 *   @0x200464 mov r0, r2
 *   @0x200468 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20046c b 0x200414 <_Z13GV_Argument11P9CInstanceiP6RValue+0x24>
 *   @0x200470 andseq sp, lr, r8, ror #17
 *   @0x200474 andseq sp, lr, r4, asr #17
 *
 * ══ §18/230 GV_Argument12(CInstance*, int, RValue*)  0x200478  size 136  34 条（0x200478..0x200500）
 * @func 0x200478 0x200510  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GV_Argument12(CInstance*, int, RValue*)+0x6c / GET_RValue(RValue*, RValue*, int) / FREE_RValue__Pre(RValue*)
 * 字段偏移 top8: 0xc×2 / 0x54×1 / 0x8×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x200478 push {r3, r4, r5, lr}
 *   @0x20047c mov r4, r2
 *   @0x200480 ldr r3, [r2, #0xc]
 *   @0x200484 mov r5, r1
 *   @0x200488 sub r3, r3, #1
 *   @0x20048c bic r3, r3, #-16777216
 *   @0x200490 bic r3, r3, #3
 *   @0x200494 cmp r3, #0
 *   @0x200498 beq 0x2004ec <_Z13GV_Argument12P9CInstanceiP6RValue+0x74>
 *   @0x20049c ldr r0, [pc, #0x54]
 *   @0x2004a0 mov r3, #0
 *   @0x2004a4 str r3, [r4]
 *   @0x2004a8 mov r12, #5
 *   @0x2004ac ldr r0, [pc, r0]
 *   @0x2004b0 str r3, [r4, #0x8]
 *   @0x2004b4 str r12, [r4, #0xc]
 *   @0x2004b8 ldr r0, [r0]
 *   @0x2004bc cmp r0, #12
 *   @0x2004c0 strle r3, [r4, #0x4]
 *   @0x2004c4 ble 0x2004e4 <_Z13GV_Argument12P9CInstanceiP6RValue+0x6c>
 *   @0x2004c8 ldr r3, [pc, #0x2c]
 *   @0x2004cc mov r0, r4
 *   @0x2004d0 mov r2, r5
 *   @0x2004d4 ldr r3, [pc, r3]
 *   @0x2004d8 ldr r1, [r3]
 *   @0x2004dc add r1, r1, #192
 *   @0x2004e0 bl 0xd13bc <_Z10GET_RValueP6RValueS0_i>
 *   @0x2004e4 mov r0, #1
 *   @0x2004e8 pop {r3, r4, r5, pc}
 *   @0x2004ec mov r0, r2
 *   @0x2004f0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x2004f4 b 0x20049c <_Z13GV_Argument12P9CInstanceiP6RValue+0x24>
 *   @0x2004f8 andseq sp, lr, r0, ror #16
 *   @0x2004fc andseq sp, lr, r12, lsr r8
 *
 * ══ §19/230 GV_Argument13(CInstance*, int, RValue*)  0x200500  size 136  34 条（0x200500..0x200588）
 * @func 0x200500 0x200598  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GV_Argument13(CInstance*, int, RValue*)+0x6c / GET_RValue(RValue*, RValue*, int) / FREE_RValue__Pre(RValue*)
 * 字段偏移 top8: 0xc×2 / 0x54×1 / 0x8×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x200500 push {r3, r4, r5, lr}
 *   @0x200504 mov r4, r2
 *   @0x200508 ldr r3, [r2, #0xc]
 *   @0x20050c mov r5, r1
 *   @0x200510 sub r3, r3, #1
 *   @0x200514 bic r3, r3, #-16777216
 *   @0x200518 bic r3, r3, #3
 *   @0x20051c cmp r3, #0
 *   @0x200520 beq 0x200574 <_Z13GV_Argument13P9CInstanceiP6RValue+0x74>
 *   @0x200524 ldr r0, [pc, #0x54]
 *   @0x200528 mov r3, #0
 *   @0x20052c str r3, [r4]
 *   @0x200530 mov r12, #5
 *   @0x200534 ldr r0, [pc, r0]
 *   @0x200538 str r3, [r4, #0x8]
 *   @0x20053c str r12, [r4, #0xc]
 *   @0x200540 ldr r0, [r0]
 *   @0x200544 cmp r0, #13
 *   @0x200548 strle r3, [r4, #0x4]
 *   @0x20054c ble 0x20056c <_Z13GV_Argument13P9CInstanceiP6RValue+0x6c>
 *   @0x200550 ldr r3, [pc, #0x2c]
 *   @0x200554 mov r0, r4
 *   @0x200558 mov r2, r5
 *   @0x20055c ldr r3, [pc, r3]
 *   @0x200560 ldr r1, [r3]
 *   @0x200564 add r1, r1, #208
 *   @0x200568 bl 0xd13bc <_Z10GET_RValueP6RValueS0_i>
 *   @0x20056c mov r0, #1
 *   @0x200570 pop {r3, r4, r5, pc}
 *   @0x200574 mov r0, r2
 *   @0x200578 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20057c b 0x200524 <_Z13GV_Argument13P9CInstanceiP6RValue+0x24>
 *   @0x200580 ldrsbeq sp, [lr], -r8
 *   @0x200584 ldrheq sp, [lr], -r4
 *
 * ══ §20/230 GV_Argument14(CInstance*, int, RValue*)  0x200588  size 136  34 条（0x200588..0x200610）
 * @func 0x200588 0x200620  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GV_Argument14(CInstance*, int, RValue*)+0x6c / GET_RValue(RValue*, RValue*, int) / FREE_RValue__Pre(RValue*)
 * 字段偏移 top8: 0xc×2 / 0x54×1 / 0x8×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x200588 push {r3, r4, r5, lr}
 *   @0x20058c mov r4, r2
 *   @0x200590 ldr r3, [r2, #0xc]
 *   @0x200594 mov r5, r1
 *   @0x200598 sub r3, r3, #1
 *   @0x20059c bic r3, r3, #-16777216
 *   @0x2005a0 bic r3, r3, #3
 *   @0x2005a4 cmp r3, #0
 *   @0x2005a8 beq 0x2005fc <_Z13GV_Argument14P9CInstanceiP6RValue+0x74>
 *   @0x2005ac ldr r0, [pc, #0x54]
 *   @0x2005b0 mov r3, #0
 *   @0x2005b4 str r3, [r4]
 *   @0x2005b8 mov r12, #5
 *   @0x2005bc ldr r0, [pc, r0]
 *   @0x2005c0 str r3, [r4, #0x8]
 *   @0x2005c4 str r12, [r4, #0xc]
 *   @0x2005c8 ldr r0, [r0]
 *   @0x2005cc cmp r0, #14
 *   @0x2005d0 strle r3, [r4, #0x4]
 *   @0x2005d4 ble 0x2005f4 <_Z13GV_Argument14P9CInstanceiP6RValue+0x6c>
 *   @0x2005d8 ldr r3, [pc, #0x2c]
 *   @0x2005dc mov r0, r4
 *   @0x2005e0 mov r2, r5
 *   @0x2005e4 ldr r3, [pc, r3]
 *   @0x2005e8 ldr r1, [r3]
 *   @0x2005ec add r1, r1, #224
 *   @0x2005f0 bl 0xd13bc <_Z10GET_RValueP6RValueS0_i>
 *   @0x2005f4 mov r0, #1
 *   @0x2005f8 pop {r3, r4, r5, pc}
 *   @0x2005fc mov r0, r2
 *   @0x200600 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x200604 b 0x2005ac <_Z13GV_Argument14P9CInstanceiP6RValue+0x24>
 *   @0x200608 andseq sp, lr, r0, asr r7
 *   @0x20060c andseq sp, lr, r12, lsr #14
 *
 * ══ §21/230 GV_Argument15(CInstance*, int, RValue*)  0x200610  size 136  34 条（0x200610..0x200698）
 * @func 0x200610 0x200698  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GV_Argument15(CInstance*, int, RValue*)+0x6c / GET_RValue(RValue*, RValue*, int) / FREE_RValue__Pre(RValue*)
 * 字段偏移 top8: 0xc×2 / 0x54×1 / 0x8×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x200610 push {r3, r4, r5, lr}
 *   @0x200614 mov r4, r2
 *   @0x200618 ldr r3, [r2, #0xc]
 *   @0x20061c mov r5, r1
 *   @0x200620 sub r3, r3, #1
 *   @0x200624 bic r3, r3, #-16777216
 *   @0x200628 bic r3, r3, #3
 *   @0x20062c cmp r3, #0
 *   @0x200630 beq 0x200684 <_Z13GV_Argument15P9CInstanceiP6RValue+0x74>
 *   @0x200634 ldr r0, [pc, #0x54]
 *   @0x200638 mov r3, #0
 *   @0x20063c str r3, [r4]
 *   @0x200640 mov r12, #5
 *   @0x200644 ldr r0, [pc, r0]
 *   @0x200648 str r3, [r4, #0x8]
 *   @0x20064c str r12, [r4, #0xc]
 *   @0x200650 ldr r0, [r0]
 *   @0x200654 cmp r0, #15
 *   @0x200658 strle r3, [r4, #0x4]
 *   @0x20065c ble 0x20067c <_Z13GV_Argument15P9CInstanceiP6RValue+0x6c>
 *   @0x200660 ldr r3, [pc, #0x2c]
 *   @0x200664 mov r0, r4
 *   @0x200668 mov r2, r5
 *   @0x20066c ldr r3, [pc, r3]
 *   @0x200670 ldr r1, [r3]
 *   @0x200674 add r1, r1, #240
 *   @0x200678 bl 0xd13bc <_Z10GET_RValueP6RValueS0_i>
 *   @0x20067c mov r0, #1
 *   @0x200680 pop {r3, r4, r5, pc}
 *   @0x200684 mov r0, r2
 *   @0x200688 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20068c b 0x200634 <_Z13GV_Argument15P9CInstanceiP6RValue+0x24>
 *   @0x200690 andseq sp, lr, r8, asr #13
 *   @0x200694 andseq sp, lr, r4, lsr #13
 *
 * ══ §22/230 DLL_Free_All()  0x212d18  size 136  34 条（0x212d18..0x212da0）
 * @func 0x212d18 0x212da0  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DLL_Free(char const*)×2
 * 字段偏移 top8: 0x4×3 / 0x74×1 / 0x64×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x212d18 push {r3, r4, r5, r6, r7, lr}
 *   @0x212d1c ldr r6, [pc, #0x74]
 *   @0x212d20 ldr r6, [pc, r6]
 *   @0x212d24 ldr r3, [r6]
 *   @0x212d28 cmp r3, #0
 *   @0x212d2c pople {r3, r4, r5, r6, r7, pc}
 *   @0x212d30 ldr r5, [pc, #0x64]
 *   @0x212d34 mov r4, #0
 *   @0x212d38 mov r7, r4
 *   @0x212d3c ldr r5, [pc, r5]
 *   @0x212d40 ldr r2, [r5]
 *   @0x212d44 mov r3, #0
 *   @0x212d48 cmp r2, r4
 *   @0x212d4c bgt 0x212d78 <_Z12DLL_Free_Allv+0x60>
 *   @0x212d50 ldr r2, [r7, #0x4]
 *   @0x212d54 cmp r2, #0
 *   @0x212d58 beq 0x212d64 <_Z12DLL_Free_Allv+0x4c>
 *   @0x212d5c ldr r0, [r3]
 *   @0x212d60 bl 0x214904 <_Z8DLL_FreePKc>
 *   @0x212d64 ldr r3, [r6]
 *   @0x212d68 add r4, r4, #1
 *   @0x212d6c cmp r3, r4
 *   @0x212d70 bgt 0x212d40 <_Z12DLL_Free_Allv+0x28>
 *   @0x212d74 pop {r3, r4, r5, r6, r7, pc}
 *   @0x212d78 ldr r3, [r5, #0x4]
 *   @0x212d7c ldr r3, [r3, r4, lsl #2]
 *   @0x212d80 ldr r2, [r3, #0x4]
 *   @0x212d84 cmp r2, #0
 *   @0x212d88 beq 0x212d64 <_Z12DLL_Free_Allv+0x4c>
 *   @0x212d8c ldr r0, [r3]
 *   @0x212d90 bl 0x214904 <_Z8DLL_FreePKc>
 *   @0x212d94 b 0x212d64 <_Z12DLL_Free_Allv+0x4c>
 *   @0x212d98 mulseq sp, r4, r6
 *   @0x212d9c andseq lr, sp, r4, ror r6
 *
 * ══ §23/230 CSound::LoadFromFile(char const*, int, bool)  0x21569c  size 136  34 条（0x21569c..0x215724）
 * @func 0x21569c 0x215724  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYStrDup(char const*)×2 / CSound::Clear() / FileExists(char const*) / ExtractFileExt(char const*) / ExtractFileName(char const*) / operator new(unsigned int) / CStream::CStream(int) / CStream::LoadFromFile(char const*, int)
 * 字段偏移 top8: 0x8×1 / 0xc×1 / 0x10×1 / 0x4×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21569c push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x2156a0 mov r5, r1
 *   @0x2156a4 mov r8, r2
 *   @0x2156a8 mov r7, r3
 *   @0x2156ac mov r4, r0
 *   @0x2156b0 bl 0x21529c <_ZN6CSound5ClearEv>
 *   @0x2156b4 mov r0, r5
 *   @0x2156b8 bl 0x214e48 <_Z10FileExistsPKc>
 *   @0x2156bc subs r6, r0, #0
 *   @0x2156c0 beq 0x21571c <_ZN6CSound12LoadFromFileEPKcib+0x80>
 *   @0x2156c4 mov r0, r5
 *   @0x2156c8 bl 0x215008 <_Z14ExtractFileExtPKc>
 *   @0x2156cc bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x2156d0 str r0, [r4, #0x8]
 *   @0x2156d4 mov r0, r5
 *   @0x2156d8 bl 0x214fe0 <_Z15ExtractFileNamePKc>
 *   @0x2156dc bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x2156e0 str r0, [r4, #0xc]
 *   @0x2156e4 mov r0, #32
 *   @0x2156e8 bl 0x27c524 <_Znwj>
 *   @0x2156ec mov r1, #0
 *   @0x2156f0 mov r9, r0
 *   @0x2156f4 bl 0x2010ec <_ZN7CStreamC2Ei>
 *   @0x2156f8 mov r0, r9
 *   @0x2156fc str r9, [r4, #0x10]
 *   @0x215700 mov r1, r5
 *   @0x215704 mov r2, #0
 *   @0x215708 bl 0x201358 <_ZN7CStream12LoadFromFileEPKci>
 *   @0x21570c str r8, [r4, #0x4]
 *   @0x215710 strb r7, [r4, #0x14]
 *   @0x215714 mov r0, r4
 *   @0x215718 bl 0x21568c <_ZN6CSound7PrepareEv>
 *   @0x21571c mov r0, r6
 *   @0x215720 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §24/230 alutLoadMemoryWaveform  0x222f20  size 136  34 条（0x222f20..0x222fa8）
 * @func 0x222f20 0x222fb8  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _alutSanityCheck / anon_222bd4+0x6c / _alutOutputStreamGetData / _alutOutputStreamGetLength / _alutInputStreamConstructFromMemory / _alutLoadMemoryFromInputStream / _alutOutputStreamDestroy
 * 字段偏移 top8: 无
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x222f20 push {r3, r4, r5, r6, r7, lr}
 *   @0x222f24 mov r4, r0
 *   @0x222f28 mov r7, r1
 *   @0x222f2c mov r6, r2
 *   @0x222f30 mov r5, r3
 *   @0x222f34 bl 0x2219a8 <_alutSanityCheck>
 *   @0x222f38 cmp r0, #0
 *   @0x222f3c beq 0x222fa0 <alutLoadMemoryWaveform+0x80>
 *   @0x222f40 mov r0, r4
 *   @0x222f44 vmov s0, r7
 *   @0x222f48 vmov s1, r6
 *   @0x222f4c vmov s2, r5
 *   @0x222f50 bl 0x222c40 <alutGetMinorVersion+0x74>
 *   @0x222f54 subs r4, r0, #0
 *   @0x222f58 beq 0x222fa0 <alutLoadMemoryWaveform+0x80>
 *   @0x222f5c bl 0x22291c <_alutOutputStreamGetData>
 *   @0x222f60 mov r5, r0
 *   @0x222f64 mov r0, r4
 *   @0x222f68 bl 0x222924 <_alutOutputStreamGetLength>
 *   @0x222f6c mov r1, r0
 *   @0x222f70 mov r0, r5
 *   @0x222f74 bl 0x221d94 <_alutInputStreamConstructFromMemory>
 *   @0x222f78 subs r5, r0, #0
 *   @0x222f7c beq 0x222f90 <alutLoadMemoryWaveform+0x70>
 *   @0x222f80 add r1, sp, #24
 *   @0x222f84 ldm r1, {r1, r2, r3}
 *   @0x222f88 bl 0x222664 <_alutLoadMemoryFromInputStream>
 *   @0x222f8c mov r5, r0
 *   @0x222f90 mov r0, r4
 *   @0x222f94 bl 0x2228fc <_alutOutputStreamDestroy>
 *   @0x222f98 mov r0, r5
 *   @0x222f9c pop {r3, r4, r5, r6, r7, pc}
 *   @0x222fa0 mov r0, #0
 *   @0x222fa4 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §25/230 COggThread::Play_Sound(int, cAudio_Sound*, bool, float, int)  0x223aac  size 136  34 条（0x223aac..0x223b34）
 * @func 0x223aac 0x223b34  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: COggThread::Lock()
 * 字段偏移 top8: 0x804×1 / 0x24×1 / 0x2d6×1 / 0x2dc×1 / 0x2d8×1 / 0x2d5×1 / 0x2e0×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x223aac ldr r12, [r0, #0x804]
 *   @0x223ab0 add r1, r1, r1, lsl #1
 *   @0x223ab4 push {r4, r5, r6, r7, r8, lr}
 *   @0x223ab8 vpush {d8}
 *   @0x223abc add r4, r12, r1, lsl #8
 *   @0x223ac0 vldr s16, [sp, #32]
 *   @0x223ac4 mov r6, r2
 *   @0x223ac8 ldr r7, [sp, #0x24]
 *   @0x223acc mov r8, r3
 *   @0x223ad0 mov r5, r0
 *   @0x223ad4 bl 0x223a9c <_ZN10COggThread4LockEv>
 *   @0x223ad8 vcmpe.f32 s16, #0
 *   @0x223adc cmp r8, #0
 *   @0x223ae0 mov r3, #1
 *   @0x223ae4 strb r3, [r4, #0x2d6]
 *   @0x223ae8 mov r0, r5
 *   @0x223aec movne r3, #3
 *   @0x223af0 strbne r3, [r4, #0x2d6]
 *   @0x223af4 mov r3, #0
 *   @0x223af8 vmrs APSR_nzcv, fpscr
 *   @0x223afc ldrbgt r3, [r4, #0x2d6]
 *   @0x223b00 vstrgt s16, [r4, #744]
 *   @0x223b04 strle r3, [r4, #0x2e8]
 *   @0x223b08 mov r2, #1
 *   @0x223b0c orrgt r3, r3, #16
 *   @0x223b10 str r7, [r4, #0x2dc]
 *   @0x223b14 strbgt r3, [r4, #0x2d6]
 *   @0x223b18 mov r3, #0
 *   @0x223b1c vpop {d8}
 *   @0x223b20 str r6, [r4, #0x2d8]
 *   @0x223b24 strb r2, [r4, #0x2d5]
 *   @0x223b28 str r3, [r4, #0x2e0]
 *   @0x223b2c pop {r4, r5, r6, r7, r8, lr}
 *   @0x223b30 b 0x223aa4 <_ZN10COggThread6UnlockEv>
 *
 * ══ §26/230 COggAudio::GetThreadForChannel(int, int&)  0x226284  size 136  34 条（0x226284..0x22630c）
 * @func 0x226284 0x22630c  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __divsi3×2 / __aeabi_idivmod / COggThread::Create(int, int, int)
 * 字段偏移 top8: 0x14×2 / 0x802×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x226284 push {r4, r5, r6, r7, r8, lr}
 *   @0x226288 mov r4, r0
 *   @0x22628c ldr r5, [r0, #0x14]
 *   @0x226290 mov r6, r1
 *   @0x226294 mov r0, r1
 *   @0x226298 mov r8, r2
 *   @0x22629c mov r1, r5
 *   @0x2262a0 bl 0x318dec <__aeabi_idivmod>
 *   @0x2262a4 mov r0, r6
 *   @0x2262a8 mov r7, r1
 *   @0x2262ac mov r1, r5
 *   @0x2262b0 bl 0x318d10 <__divsi3>
 *   @0x2262b4 ldr r3, [r4]
 *   @0x2262b8 movw r5, #0x834
 *   @0x2262bc mla r5, r5, r7, r3
 *   @0x2262c0 ldrb r3, [r5, #0x802]
 *   @0x2262c4 cmp r3, #0
 *   @0x2262c8 str r0, [r8]
 *   @0x2262cc beq 0x2262d8 <_ZN9COggAudio19GetThreadForChannelEiRi+0x54>
 *   @0x2262d0 mov r0, r5
 *   @0x2262d4 pop {r4, r5, r6, r7, r8, pc}
 *   @0x2262d8 ldr r6, [r4, #0x14]
 *   @0x2262dc ldr r0, [r4, #0x18]
 *   @0x2262e0 mov r1, r6
 *   @0x2262e4 bl 0x318d10 <__divsi3>
 *   @0x2262e8 mov r1, r7
 *   @0x2262ec mov r2, r6
 *   @0x2262f0 mov r3, r0
 *   @0x2262f4 mov r0, r5
 *   @0x2262f8 bl 0x223924 <_ZN10COggThread6CreateEiii>
 *   @0x2262fc cmp r0, #0
 *   @0x226300 movne r0, r5
 *   @0x226304 moveq r0, #0
 *   @0x226308 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §27/230 CPhysicsObject::ApplyImpulse(float, float, float, float)  0x236fd0  size 136  34 条（0x236fd0..0x237058）
 * @func 0x236fd0 0x237068  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0xa0×1
 * VFP 指令 21 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x236fd0 ldr r0, [r0]
 *   @0x236fd4 vmov s15, r3
 *   @0x236fd8 vmov s14, r1
 *   @0x236fdc vmov s13, r2
 *   @0x236fe0 ldr r3, [r0]
 *   @0x236fe4 cmp r3, #2
 *   @0x236fe8 bxne lr
 *   @0x236fec ldrh r3, [r0, #4]
 *   @0x236ff0 tst r3, #2
 *   @0x236ff4 beq 0x237044 <_ZN14CPhysicsObject12ApplyImpulseEffff+0x74>
 *   @0x236ff8 vldr s12, [r0, #64]
 *   @0x236ffc vsub.f32 s13, s13, s12
 *   @0x237000 vldr s7, [r0, #60]
 *   @0x237004 vldr s11, [r0, #88]
 *   @0x237008 vldr s9, [r0, #136]
 *   @0x23700c vldr s10, [r0, #80]
 *   @0x237010 vldr s12, [r0, #84]
 *   @0x237014 vldr s8, [r0, #144]
 *   @0x237018 vmul.f32 s13, s15, s13
 *   @0x23701c vsub.f32 s14, s14, s7
 *   @0x237020 vldr s7, [sp]
 *   @0x237024 vnmls.f32 s13, s7, s14
 *   @0x237028 vmla.f32 s10, s15, s9
 *   @0x23702c vmla.f32 s11, s13, s8
 *   @0x237030 vstr s10, [r0, #80]
 *   @0x237034 vmla.f32 s12, s7, s9
 *   @0x237038 vstr s11, [r0, #88]
 *   @0x23703c vstr s12, [r0, #84]
 *   @0x237040 bx lr
 *   @0x237044 orr r3, r3, #2
 *   @0x237048 mov r2, #0
 *   @0x23704c strh r3, [r0, #4]
 *   @0x237050 str r2, [r0, #0xa0]
 *   @0x237054 b 0x236ff8 <_ZN14CPhysicsObject12ApplyImpulseEffff+0x28>
 *
 * ══ §28/230 Hash<CPhysicsJoint>::~Hash()  0x23b220  size 136  34 条（0x23b220..0x23b2a8）
 * @func 0x23b220 0x23b2a8  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / Hash<CPhysicsJoint>::~Hash()+0x7c / operator delete(void*)
 * 字段偏移 top8: 0x4×2 / 0x8×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23b220 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x23b224 mov r6, r0
 *   @0x23b228 ldm r0, {r0, r8}
 *   @0x23b22c cmp r8, #0
 *   @0x23b230 lslge r7, r8, #3
 *   @0x23b234 movge r9, #0
 *   @0x23b238 blt 0x23b29c <_ZN4HashI13CPhysicsJointED2Ev+0x7c>
 *   @0x23b23c ldr r4, [r0, r7]
 *   @0x23b240 add r3, r0, r7
 *   @0x23b244 str r9, [r0, r7]
 *   @0x23b248 cmp r4, #0
 *   @0x23b24c str r9, [r3, #0x4]
 *   @0x23b250 beq 0x23b28c <_ZN4HashI13CPhysicsJointED2Ev+0x6c>
 *   @0x23b254 ldr r0, [r4, #0xc]
 *   @0x23b258 ldr r5, [r4, #0x4]
 *   @0x23b25c cmp r0, #0
 *   @0x23b260 beq 0x23b268 <_ZN4HashI13CPhysicsJointED2Ev+0x48>
 *   @0x23b264 bl 0x27d1d0 <_ZdlPv>
 *   @0x23b268 mov r0, r4
 *   @0x23b26c mov r4, r5
 *   @0x23b270 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x23b274 ldr r3, [r6, #0x8]
 *   @0x23b278 cmp r5, #0
 *   @0x23b27c sub r3, r3, #1
 *   @0x23b280 str r3, [r6, #0x8]
 *   @0x23b284 bne 0x23b254 <_ZN4HashI13CPhysicsJointED2Ev+0x34>
 *   @0x23b288 ldr r0, [r6]
 *   @0x23b28c sub r8, r8, #1
 *   @0x23b290 sub r7, r7, #8
 *   @0x23b294 cmn r8, #1
 *   @0x23b298 bne 0x23b23c <_ZN4HashI13CPhysicsJointED2Ev+0x1c>
 *   @0x23b29c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x23b2a0 mov r0, r6
 *   @0x23b2a4 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §29/230 JS_StandardScriptRefConstructor(RValue&, CInstance*, CInstance*, int, RValue*)  0x240d20  size 136  34 条（0x240d20..0x240da8）
 * @func 0x240d20 0x240da8  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x240d30→0x756454
 * 调用序列: YYSetScriptRef(RValue*) / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)
 * 字段偏移 top8: 0x28×3 / 0x5c×2 / 0x40×2 / 0x18×1 / 0x3c×1 / 0x2c×1 / 0x4c×1 / 0x50×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x240d20 push {r3, r4, r5, lr}
 *   @0x240d24 mov r4, r0
 *   @0x240d28 bl 0xdc3b0 <_Z14YYSetScriptRefP6RValue>
 *   @0x240d2c ldr r5, [pc, #0x5c]
 *   @0x240d30 ldr r3, [pc, #0x5c]
 *   @0x240d34 add r5, pc, r5
 *   @0x240d38 ldr r4, [r4]
 *   @0x240d3c ldr r3, [r5, r3]
 *   @0x240d40 mov r0, r4
 *   @0x240d44 ldr r1, [r3]
 *   @0x240d48 str r1, [r4, #0x18]
 *   @0x240d4c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x240d50 ldr r3, [pc, #0x40]
 *   @0x240d54 ldr r1, [r4, #0x28]
 *   @0x240d58 ldr r2, [pc, #0x3c]
 *   @0x240d5c orr r1, r1, #1
 *   @0x240d60 str r1, [r4, #0x28]
 *   @0x240d64 add r2, pc, r2
 *   @0x240d68 str r2, [r4, #0x40]
 *   @0x240d6c ldr r2, [pc, #0x2c]
 *   @0x240d70 ldr r1, [r5, r3]
 *   @0x240d74 ldr r3, [pc, #0x28]
 *   @0x240d78 str r1, [r4, #0x4c]
 *   @0x240d7c ldr r2, [r5, r2]
 *   @0x240d80 str r2, [r4, #0x50]
 *   @0x240d84 ldr r3, [r5, r3]
 *   @0x240d88 str r3, [r4, #0x54]
 *   @0x240d8c pop {r3, r4, r5, pc}
 *   @0x240d90 andseq r0, r11, r12, lsl pc
 *   @0x240d94 .word 0xffffc054
 *   @0x240d98 .word 0xfffff8ac
 *   @0x240d9c ldrsheq r4, [r1], -r0
 *   @0x240da0 .word 0xfffff8b0
 *   @0x240da4 .word 0xfffff8b4
 *
 * ══ §30/230 JS_Math_sqrt(RValue&, CInstance*, CInstance*, int, RValue*)  0x252afc  size 136  34 条（0x252afc..0x252b84）
 * @func 0x252afc 0x252b84  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JS_Math_sqrt(RValue&, CInstance*, CInstance*, int, RValue*)+0x58 / F_JS_ToNumber(RValue&, RValue&) / YYGetReal(RValue const*, int) / 0xb66f4
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x14×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x252afc cmp r3, #0
 *   @0x252b00 push {r3, r4, r5, lr}
 *   @0x252b04 mov r5, #0
 *   @0x252b08 mov r4, r0
 *   @0x252b0c ldr r1, [sp, #0x10]
 *   @0x252b10 str r5, [r0, #0xc]
 *   @0x252b14 ble 0x252b54 <_Z12JS_Math_sqrtR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x252b18 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_>
 *   @0x252b1c cmp r0, #1
 *   @0x252b20 beq 0x252b64 <_Z12JS_Math_sqrtR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x252b24 mov r1, r5
 *   @0x252b28 mov r0, r4
 *   @0x252b2c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x252b30 vmov d6, r0, r1
 *   @0x252b34 vsqrt.f64 d7, d6
 *   @0x252b38 vcmp.f64 d7, d7
 *   @0x252b3c vmrs APSR_nzcv, fpscr
 *   @0x252b40 bne 0x252b74 <_Z12JS_Math_sqrtR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x252b44 vmov r2, s14
 *   @0x252b48 vmov r3, s15
 *   @0x252b4c stm r4, {r2, r3}
 *   @0x252b50 pop {r3, r4, r5, pc}
 *   @0x252b54 mvn r2, #0
 *   @0x252b58 mvn r3, #-2147483648
 *   @0x252b5c stm r0, {r2, r3}
 *   @0x252b60 pop {r3, r4, r5, pc}
 *   @0x252b64 ldr r0, [pc, #0x14]
 *   @0x252b68 pop {r3, r4, r5, lr}
 *   @0x252b6c add r0, pc, r0
 *   @0x252b70 b 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x252b74 bl 0xb66f4 <sqrt@plt>
 *   @0x252b78 vmov d7, r0, r1
 *   @0x252b7c b 0x252b44 <_Z12JS_Math_sqrtR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x252b80 ldrsbeq r3, [r0], -r12
 *
 * ══ §31/230 F_JS_Object_prototype_hasOwnProperty(RValue&, CInstance*, CInstance*, int, RValue*)  0x2552ec  size 136  34 条（0x2552ec..0x255374）
 * @func 0x2552ec 0x255374  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_JS_ToString(RValue&, RValue*) / JS_GetOwnProperty(YYObjectBase*, RValue*, char const*)
 * 字段偏移 top8: 0x1c×2 / 0xc×2 / 0x4×2 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2552ec push {r4, r5, lr}
 *   @0x2552f0 sub sp, sp, #36
 *   @0x2552f4 mov r5, r1
 *   @0x2552f8 mov r4, r0
 *   @0x2552fc ldr r1, [sp, #0x30]
 *   @0x255300 mov r0, sp
 *   @0x255304 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x255308 ldr r3, [sp]
 *   @0x25530c mov r2, #5
 *   @0x255310 mov r0, r5
 *   @0x255314 str r2, [sp, #0x1c]
 *   @0x255318 add r1, sp, #16
 *   @0x25531c ldr r2, [r3]
 *   @0x255320 bl 0x241890 <_Z17JS_GetOwnPropertyP12YYObjectBaseP6RValuePKc>
 *   @0x255324 ldr r2, [sp, #0x1c]
 *   @0x255328 mvn r3, #-16777216
 *   @0x25532c cmp r2, r3
 *   @0x255330 beq 0x255358 <_Z36F_JS_Object_prototype_hasOwnPropertyR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x255334 mov r2, #13
 *   @0x255338 mov r3, #0
 *   @0x25533c str r2, [r4, #0xc]
 *   @0x255340 movt r3, #0x3ff0
 *   @0x255344 str r3, [r4, #0x4]
 *   @0x255348 mov r3, #0
 *   @0x25534c str r3, [r4]
 *   @0x255350 add sp, sp, #36
 *   @0x255354 pop {r4, r5, pc}
 *   @0x255358 mov r3, #0
 *   @0x25535c mov r2, #13
 *   @0x255360 str r3, [r4]
 *   @0x255364 str r2, [r4, #0xc]
 *   @0x255368 str r3, [r4, #0x4]
 *   @0x25536c add sp, sp, #36
 *   @0x255370 pop {r4, r5, pc}
 *
 * ══ §32/230 pcre_get_substring  0x25f5e8  size 136  34 条（0x25f5e8..0x25f670）
 * @func 0x25f5e8 0x25f670  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65bc
 * 字段偏移 top8: 0x3×2 / 0x54×1 / 0x4×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x25f5e8 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x25f5ec lsr r7, r3, #31
 *   @0x25f5f0 cmp r3, r2
 *   @0x25f5f4 orrge r7, r7, #1
 *   @0x25f5f8 mov r4, r3
 *   @0x25f5fc cmp r7, #0
 *   @0x25f600 mov r9, r0
 *   @0x25f604 mov r6, r1
 *   @0x25f608 bne 0x25f65c <pcre_get_substring+0x74>
 *   @0x25f60c add r1, r1, r3, lsl #3
 *   @0x25f610 ldr r3, [pc, #0x54]
 *   @0x25f614 ldr r2, [r6, r4, lsl #3]
 *   @0x25f618 ldr r5, [r1, #0x4]
 *   @0x25f61c ldr r3, [pc, r3]
 *   @0x25f620 rsb r5, r2, r5
 *   @0x25f624 ldr r3, [r3]
 *   @0x25f628 add r0, r5, #1
 *   @0x25f62c blx r3
 *   @0x25f630 subs r8, r0, #0
 *   @0x25f634 beq 0x25f664 <pcre_get_substring+0x7c>
 *   @0x25f638 ldr r1, [r6, r4, lsl #3]
 *   @0x25f63c mov r2, r5
 *   @0x25f640 add r1, r9, r1
 *   @0x25f644 bl 0xb65bc <memcpy@plt>
 *   @0x25f648 ldr r3, [sp, #0x20]
 *   @0x25f64c strb r7, [r8, r5]
 *   @0x25f650 mov r0, r5
 *   @0x25f654 str r8, [r3]
 *   @0x25f658 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x25f65c mvn r0, #6
 *   @0x25f660 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x25f664 mvn r0, #5
 *   @0x25f668 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x25f66c andseq r2, r9, r8, asr #3
 *
 * ══ §33/230 spAttachmentTimeline_create  0x282b94  size 136  34 条（0x282b94..0x282c1c）
 * @func 0x282b94 0x282c1c  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _calloc×3 / _spTimeline_init
 * 字段偏移 top8: 0x54×2 / 0x6c×1 / 0x8×1 / 0xc×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x282b94 push {r4, r5, r6, lr}
 *   @0x282b98 mov r1, #24
 *   @0x282b9c ldr r6, [pc, #0x6c]
 *   @0x282ba0 mov r5, r0
 *   @0x282ba4 mov r3, #544
 *   @0x282ba8 mov r0, #1
 *   @0x282bac add r6, pc, r6
 *   @0x282bb0 mov r2, r6
 *   @0x282bb4 bl 0x285c4c <_calloc>
 *   @0x282bb8 ldr r2, [pc, #0x54]
 *   @0x282bbc ldr r3, [pc, #0x54]
 *   @0x282bc0 mov r1, #5
 *   @0x282bc4 ldr r2, [pc, r2]
 *   @0x282bc8 ldr r3, [pc, r3]
 *   @0x282bcc mov r4, r0
 *   @0x282bd0 bl 0x281328 <_spTimeline_init>
 *   @0x282bd4 mov r2, r6
 *   @0x282bd8 str r5, [r4, #0x8]
 *   @0x282bdc mov r0, r5
 *   @0x282be0 mov r1, #4
 *   @0x282be4 mov r3, #548
 *   @0x282be8 bl 0x285c4c <_calloc>
 *   @0x282bec mov r2, r6
 *   @0x282bf0 mov r1, #4
 *   @0x282bf4 movw r3, #0x225
 *   @0x282bf8 str r0, [r4, #0xc]
 *   @0x282bfc mov r0, r5
 *   @0x282c00 bl 0x285c4c <_calloc>
 *   @0x282c04 str r0, [r4, #0x14]
 *   @0x282c08 mov r0, r4
 *   @0x282c0c pop {r4, r5, r6, pc}
 *   @0x282c10 andeq r4, sp, r4, lsr #17
 *   @0x282c14 ldrsheq lr, [r6], -r4
 *   @0x282c18 ldrsheq lr, [r6], -r4
 *
 * ══ §34/230 spEventTimeline_create  0x282c8c  size 136  34 条（0x282c8c..0x282d14）
 * @func 0x282c8c 0x282d14  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _calloc×3 / _spTimeline_init
 * 字段偏移 top8: 0x54×2 / 0x6c×1 / 0x8×1 / 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x282c8c push {r4, r5, r6, lr}
 *   @0x282c90 mov r1, #20
 *   @0x282c94 ldr r6, [pc, #0x6c]
 *   @0x282c98 mov r5, r0
 *   @0x282c9c movw r3, #0x263
 *   @0x282ca0 mov r0, #1
 *   @0x282ca4 add r6, pc, r6
 *   @0x282ca8 mov r2, r6
 *   @0x282cac bl 0x285c4c <_calloc>
 *   @0x282cb0 ldr r2, [pc, #0x54]
 *   @0x282cb4 ldr r3, [pc, #0x54]
 *   @0x282cb8 mov r1, #6
 *   @0x282cbc ldr r2, [pc, r2]
 *   @0x282cc0 ldr r3, [pc, r3]
 *   @0x282cc4 mov r4, r0
 *   @0x282cc8 bl 0x281328 <_spTimeline_init>
 *   @0x282ccc mov r2, r6
 *   @0x282cd0 str r5, [r4, #0x8]
 *   @0x282cd4 mov r0, r5
 *   @0x282cd8 mov r1, #4
 *   @0x282cdc movw r3, #0x267
 *   @0x282ce0 bl 0x285c4c <_calloc>
 *   @0x282ce4 mov r2, r6
 *   @0x282ce8 mov r1, #4
 *   @0x282cec mov r3, #616
 *   @0x282cf0 str r0, [r4, #0xc]
 *   @0x282cf4 mov r0, r5
 *   @0x282cf8 bl 0x285c4c <_calloc>
 *   @0x282cfc str r0, [r4, #0x10]
 *   @0x282d00 mov r0, r4
 *   @0x282d04 pop {r4, r5, r6, pc}
 *   @0x282d08 andeq r4, sp, r12, lsr #15
 *   @0x282d0c andseq lr, r6, r4, lsl #24
 *   @0x282d10 andseq lr, r6, r4, lsl #24
 *
 * ══ §35/230 spBone_rotateWorld  0x285600  size 136  34 条（0x285600..0x285688）
 * @func 0x285600 0x285688  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb67e4 / 0xb67d8
 * 字段偏移 top8: 无
 * VFP 指令 29 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x285600 vmov s10, r1
 *   @0x285604 push {r4, lr}
 *   @0x285608 vpush {d8, d9, d10, d11}
 *   @0x28560c vldr s16, [pc, #112]
 *   @0x285610 vmul.f32 s16, s10, s16
 *   @0x285614 vldr s22, [r0, #64]
 *   @0x285618 vldr s21, [r0, #68]
 *   @0x28561c vldr s20, [r0, #52]
 *   @0x285620 vldr s19, [r0, #56]
 *   @0x285624 mov r4, r0
 *   @0x285628 vcvt.f64.f32 d8, s16
 *   @0x28562c vmov r0, r1, d8
 *   @0x285630 bl 0xb67e4 <cos@plt>
 *   @0x285634 vmov d7, r0, r1
 *   @0x285638 vmov r0, r1, d8
 *   @0x28563c vcvt.f32.f64 s18, d7
 *   @0x285640 bl 0xb67d8 <sin@plt>
 *   @0x285644 vmul.f32 s12, s18, s22
 *   @0x285648 vmul.f32 s14, s18, s21
 *   @0x28564c vmov d5, r0, r1
 *   @0x285650 vcvt.f32.f64 s15, d5
 *   @0x285654 vmul.f32 s11, s15, s22
 *   @0x285658 vmul.f32 s13, s15, s21
 *   @0x28565c vnmls.f32 s11, s18, s20
 *   @0x285660 vmla.f32 s12, s15, s20
 *   @0x285664 vstr s11, [r4, #52]
 *   @0x285668 vnmls.f32 s13, s18, s19
 *   @0x28566c vstr s12, [r4, #64]
 *   @0x285670 vmla.f32 s14, s15, s19
 *   @0x285674 vstr s13, [r4, #56]
 *   @0x285678 vpop {d8, d9, d10, d11}
 *   @0x28567c vstr s14, [r4, #68]
 *   @0x285680 pop {r4, pc}
 *   @0x285684 vstmialo lr, {s30, s31}
 *
 * ══ §36/230 Debug_WriteOutput(Buffer_Standard*)  0x29c080  size 136  34 条（0x29c080..0x29c108）
 * @func 0x29c080 0x29c108  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IBuffer::Write(char const*)
 * 字段偏移 top8: 0x4×2 / 0x70×1 / 0x2c×1 / 0x38×1 / 0x30×1 / 0x8×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29c080 push {r4, r5, r6, r7, r8, lr}
 *   @0x29c084 mov r7, r0
 *   @0x29c088 ldr r6, [pc, #0x70]
 *   @0x29c08c add r6, pc, r6
 *   @0x29c090 ldr r3, [r6]
 *   @0x29c094 cmp r3, #0
 *   @0x29c098 beq 0x29c0f0 <_Z17Debug_WriteOutputP15Buffer_Standard+0x70>
 *   @0x29c09c ldr r4, [r6, #0x4]
 *   @0x29c0a0 mov r2, r0
 *   @0x29c0a4 ldr r3, [r2], #44
 *   @0x29c0a8 mov r8, #0
 *   @0x29c0ac add r4, r4, #1
 *   @0x29c0b0 str r8, [r0, #0x38]
 *   @0x29c0b4 mov r1, #5
 *   @0x29c0b8 vmov s15, r4
 *   @0x29c0bc vcvt.f64.u32 d7, s15
 *   @0x29c0c0 vmov r4, r5, d7
 *   @0x29c0c4 vstr s14, [r7, #44]
 *   @0x29c0c8 str r5, [r7, #0x30]
 *   @0x29c0cc ldr r3, [r3, #0x8]
 *   @0x29c0d0 blx r3
 *   @0x29c0d4 mov r0, r7
 *   @0x29c0d8 ldr r1, [r6]
 *   @0x29c0dc bl 0xcddb8 <_ZN7IBuffer5WriteEPKc>
 *   @0x29c0e0 ldr r3, [r6]
 *   @0x29c0e4 str r8, [r6, #0x4]
 *   @0x29c0e8 strb r8, [r3]
 *   @0x29c0ec pop {r4, r5, r6, r7, r8, pc}
 *   @0x29c0f0 ldr r1, [pc, #0xc]
 *   @0x29c0f4 pop {r4, r5, r6, r7, r8, lr}
 *   @0x29c0f8 add r1, pc, r1
 *   @0x29c0fc b 0x29e624 <_Z11WriteStringP15Buffer_StandardPKc>
 *   @0x29c100 subeq r11, r11, r12, ror r11
 *   @0x29c104 andeq r2, r9, lr, lsr r10
 *
 * ══ §37/230 _zip_dirent_torrent_normalize(zip_dirent*)  0x2a3c58  size 136  34 条（0x2a3c58..0x2a3ce0）
 * @func 0x2a3c58 0x2a3ce0  size 136  34 条
 * 部分覆盖: 本节 34/65 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb67fc / 0xb6ef8 / 0xb655c
 * 字段偏移 top8: 0x28×2 / 0x78×1 / 0x1c×1 / 0x24×1 / 0x2×1 / 0x4×1 / 0x6×1 / 0x2e×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a3c58 push {r0, r1, r4, r5, r6, lr}
 *   @0x2a3c5c ldr r5, [pc, #0x78]
 *   @0x2a3c60 ldr r3, [r5]
 *   @0x2a3c64 add r6, sp, #0x4
 *   @0x2a3c68 str r3, [r5, #0x1c]
 *   @0x2a3c6c mov r0, r6
 *   @0x2a3c70 str r3, [r5, #0x24]
 *   @0x2a3c74 movs r2, #0x17
 *   @0x2a3c78 movs r2, #0x18
 *   @0x2a3c7c movs r2, #0xb
 *   @0x2a3c80 movs r2, #0x60
 *   @0x2a3c84 blx 0xb67fc <time@plt>
 *   @0x2a3c88 mov r0, r6
 *   @0x2a3c8c bvs 0x139e184 <b2_toiTime+0xc44ce0>
 *   @0x2a3c90 str r3, [r5, #0x28]
 *   @0x2a3c94 adds r0, r5, #0x4
 *   @0x2a3c98 blx 0xb6ef8 <mktime@plt>
 *   @0x2a3c9c str r0, [r5]
 *   @0x2a3ca0 strh r3, [r4, #0x2]
 *   @0x2a3ca4 strh r3, [r4, #0x4]
 *   @0x2a3ca8 strh r3, [r4, #0x6]
 *   @0x2a3cac movs r5, #0x0
 *   @0x2a3cb0 add r3, pc
 *   @0x2a3cb4 strh r5, [r4, #0x2e]
 *   @0x2a3cb8 strh r5, [r4, #0x30]
 *   @0x2a3cbc str r3, [r4, #0x8]
 *   @0x2a3cc0 blx 0xb655c <free@plt>
 *   @0x2a3cc4 str r5, [r4, #0x20]
 *   @0x2a3cc8 ldr r0, [r4, #0x28]
 *   @0x2a3ccc adcvs lr, r5, #72, #24
 *   @0x2a3cd0 strh r5, [r4, #0x2c]
 *   @0x2a3cd4 pop {r4, r5, r6, pc}
 *   @0x2a3cd8 strb r6, [r1, r2]
 *   @0x2a3cdc strb r4, [r7, r0]
 *
 * ══ §38/230 jpeg_read_header  0x2b31b8  size 136  34 条（0x2b31b8..0x2b3240）
 * @func 0x2b31b8 0x2b3240  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: jpeg_read_header+0x38 / jpeg_consume_input / jpeg_abort
 * 字段偏移 top8: 0x14×3 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b31b8 ldr r3, [r0, #0x14]
 *   @0x2b31bc push {r4, r5, r6, lr}
 *   @0x2b31c0 sub r2, r3, #200
 *   @0x2b31c4 cmp r2, #1
 *   @0x2b31c8 mov r4, r0
 *   @0x2b31cc mov r6, r1
 *   @0x2b31d0 bls 0x2b31f0 <jpeg_read_header+0x38>
 *   @0x2b31d4 ldr r2, [r0]
 *   @0x2b31d8 mov r1, #20
 *   @0x2b31dc str r3, [r2, #0x18]
 *   @0x2b31e0 ldr r3, [r0]
 *   @0x2b31e4 str r1, [r2, #0x14]
 *   @0x2b31e8 ldr r3, [r3]
 *   @0x2b31ec blx r3
 *   @0x2b31f0 mov r0, r4
 *   @0x2b31f4 bl 0x2b2f08 <jpeg_consume_input>
 *   @0x2b31f8 cmp r0, #2
 *   @0x2b31fc mov r5, r0
 *   @0x2b3200 beq 0x2b320c <jpeg_read_header+0x54>
 *   @0x2b3204 mov r0, r5
 *   @0x2b3208 pop {r4, r5, r6, pc}
 *   @0x2b320c cmp r6, #0
 *   @0x2b3210 bne 0x2b3224 <jpeg_read_header+0x6c>
 *   @0x2b3214 mov r0, r4
 *   @0x2b3218 bl 0x2bc874 <jpeg_abort>
 *   @0x2b321c mov r0, r5
 *   @0x2b3220 pop {r4, r5, r6, pc}
 *   @0x2b3224 ldr r3, [r4]
 *   @0x2b3228 mov r2, #51
 *   @0x2b322c mov r0, r4
 *   @0x2b3230 str r2, [r3, #0x14]
 *   @0x2b3234 ldr r3, [r3]
 *   @0x2b3238 blx r3
 *   @0x2b323c b 0x2b3214 <jpeg_read_header+0x5c>
 *
 * ══ §39/230 b2ParticleSystem::DestroyParticlesInShape(b2Shape const&, b2Transform const&, bool)  0x2d523c  size 136  34 条（0x2d523c..0x2d52c4）
 * @func 0x2d523c 0x2d52c4  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2World::QueryAABB(b2QueryCallback*, b2AABB const&) const
 * 字段偏移 top8: 0x1c×2 / 0x34×2 / 0x30×1 / 0x50×1 / 0x18×1 / 0x14×1 / 0xd4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d523c push {r4, r5, r6, r7, r8, lr}
 *   @0x2d5240 mov r12, r2
 *   @0x2d5244 mov r4, r1
 *   @0x2d5248 mov r5, r0
 *   @0x2d524c mov lr, r3
 *   @0x2d5250 sub sp, sp, #56
 *   @0x2d5254 ldm r2, {r0, r1, r2, r3}
 *   @0x2d5258 mov r6, #0
 *   @0x2d525c strb lr, [sp, #0x30]
 *   @0x2d5260 add lr, sp, #32
 *   @0x2d5264 ldr r8, [r4]
 *   @0x2d5268 ldr r7, [pc, #0x50]
 *   @0x2d526c stm lr, {r0, r1, r2, r3}
 *   @0x2d5270 mov r0, r4
 *   @0x2d5274 str r4, [sp, #0x1c]
 *   @0x2d5278 add r4, sp, #4
 *   @0x2d527c add r7, pc, r7
 *   @0x2d5280 mov r2, r12
 *   @0x2d5284 mov r1, r4
 *   @0x2d5288 ldr r12, [r8, #0x1c]
 *   @0x2d528c mov r3, r6
 *   @0x2d5290 str r5, [sp, #0x18]
 *   @0x2d5294 add r7, r7, #8
 *   @0x2d5298 str r6, [sp, #0x34]
 *   @0x2d529c str r7, [sp, #0x14]
 *   @0x2d52a0 blx r12
 *   @0x2d52a4 ldr r0, [r5, #0xd4]
 *   @0x2d52a8 mov r2, r4
 *   @0x2d52ac add r1, sp, #20
 *   @0x2d52b0 bl 0x2cb89c <_ZNK7b2World9QueryAABBEP15b2QueryCallbackRK6b2AABB>
 *   @0x2d52b4 ldr r0, [sp, #0x34]
 *   @0x2d52b8 add sp, sp, #56
 *   @0x2d52bc pop {r4, r5, r6, r7, r8, pc}
 *   @0x2d52c0 andseq r3, r1, r12, asr #13
 *
 * ══ §40/230 anon_31a6b0  0x31a6b0  size 136  34 条（0x31a6b0..0x31a738）
 * @func 0x31a6b0 0x31a738  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _Unwind_VRS_Get
 * 字段偏移 top8: 0x4×3 / 0x8×2 / 0x9×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x31a6b0 ldrb r3, [r0, #0x8]
 *   @0x31a6b4 cmp r3, #0
 *   @0x31a6b8 bne 0x31a6ec <___Unwind_Backtrace+0x60>
 *   @0x31a6bc ldrb r3, [r0, #0x9]
 *   @0x31a6c0 cmp r3, #0
 *   @0x31a6c4 beq 0x31a708 <___Unwind_Backtrace+0x7c>
 *   @0x31a6c8 sub r3, r3, #1
 *   @0x31a6cc strb r3, [r0, #0x9]
 *   @0x31a6d0 ldr r3, [r0, #0x4]
 *   @0x31a6d4 add r2, r3, #4
 *   @0x31a6d8 str r2, [r0, #0x4]
 *   @0x31a6dc ldr r3, [r3]
 *   @0x31a6e0 str r3, [r0]
 *   @0x31a6e4 mov r3, #3
 *   @0x31a6e8 b 0x31a6f0 <___Unwind_Backtrace+0x64>
 *   @0x31a6ec sub r3, r3, #1
 *   @0x31a6f0 strb r3, [r0, #0x8]
 *   @0x31a6f4 ldr r3, [r0]
 *   @0x31a6f8 lsl r2, r3, #8
 *   @0x31a6fc str r2, [r0]
 *   @0x31a700 lsr r0, r3, #24
 *   @0x31a704 bx lr
 *   @0x31a708 mov r0, #176
 *   @0x31a70c bx lr
 *   @0x31a710 push {r0, r1, r2, r3, r4, lr}
 *   @0x31a714 mov r1, #0
 *   @0x31a718 add r3, sp, #12
 *   @0x31a71c mov r2, #12
 *   @0x31a720 str r3, [sp]
 *   @0x31a724 mov r3, r1
 *   @0x31a728 bl 0x319be4 <_Unwind_VRS_Get>
 *   @0x31a72c ldr r0, [sp, #0xc]
 *   @0x31a730 add sp, sp, #20
 *   @0x31a734 ldr pc, [sp], #4
 *
 * ══ §41/230 png_do_read_intrapixel  0x2ab9f8  size 134  34 条（0x2ab9f8..0x2aba7e）
 * @func 0x2ab9f8 0x2aba80  size 136  34 条
 * 部分覆盖: 本节 34/67 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1×1 / 0x4×1 / 0x5×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ab9f8 push {r4, r5, r6, r7, lr}
 *   @0x2ab9fc lsls r2, r3, #0x1e
 *   @0x2aba00 ldr r2, [r0]
 *   @0x2aba04 cmp r0, #0x8
 *   @0x2aba08 cmp r3, #0x2
 *   @0x2aba0c cmp r3, #0x6
 *   @0x2aba10 movs r0, #0x4
 *   @0x2aba14 movs r0, #0x3
 *   @0x2aba18 cmp r3, r2
 *   @0x2aba1c ldrb r4, [r1, #0x1]
 *   @0x2aba20 ldrb r5, [r1]
 *   @0x2aba24 strb r5, [r1]
 *   @0x2aba28 add r4, r5
 *   @0x2aba2c add r1, r0
 *   @0x2aba30 pop {r4, r5, r6, r7, pc}
 *   @0x2aba34 bne 0x2aba7c <png_do_read_intrapixel+0x84>
 *   @0x2aba38 beq 0x2aba42 <png_do_read_intrapixel+0x4a>
 *   @0x2aba3c bne 0x2aba7c <png_do_read_intrapixel+0x84>
 *   @0x2aba40 b 0x2aba44 <png_do_read_intrapixel+0x4c>
 *   @0x2aba44 movs r3, #0x0
 *   @0x2aba48 beq 0x2aba7c <png_do_read_intrapixel+0x84>
 *   @0x2aba4c adds r3, #0x1
 *   @0x2aba50 ldrb r5, [r1]
 *   @0x2aba54 stmdavc r12, {r1, r2, r9, r10, sp} ^
 *   @0x2aba58 ldrb r7, [r1, #0x4]
 *   @0x2aba5c stmdbvc r12, {r0, r2, r8, r10, sp} ^
 *   @0x2aba60 add r5, r6
 *   @0x2aba64 ldrtmi r2, [r4], #-1031
 *   @0x2aba68 uxth r5, r5
 *   @0x2aba6c uxth r4, r4
 *   @0x2aba70 strb r4, [r1, #0x5]
 *   @0x2aba74 lsrs r5, r4, #0x8
 *   @0x2aba78 add r1, r0
 *   @0x2aba7c pop {r4, r5, r6, r7, pc}
 *
 * ══ §42/230 png_set_IHDR  0x2aea84  size 134  34 条（0x2aea84..0x2aeb0a）
 * @func 0x2aea84 0x2aeb0c  size 136  34 条
 * 部分覆盖: 本节 34/67 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x1a9eb10
 * 字段偏移 top8: 0x1d×4 / 0x4×2 / 0x28×1 / 0x34×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2aea84 push {r4, r5, r6, r7, lr}
 *   @0x2aea88 mov r4, r1
 *   @0x2aea8c ldr r6, [sp, #0x28]
 *   @0x2aea90 svcls #0xcc02c
 *   @0x2aea94 ldr r1, [sp, #0x34]
 *   @0x2aea98 cmp r0, #0x0
 *   @0x2aea9c cmp r4, #0x0
 *   @0x2aeaa0 str r3, [r4, #0x4]
 *   @0x2aeaa4 blx 0x1a9eb10 <b2_toiTime+0x134566c>
 *   @0x2aeaa8 strtvc pc, [r1], r12, lsl #25
 *   @0x2aeaac uxtb r1, r1
 *   @0x2aeab0 uxtb r2, r2
 *   @0x2aeab4 uxtb r7, r7
 *   @0x2aeab8 mov r1, r5
 *   @0x2aeabc mov r2, r3
 *   @0x2aeac0 uxtb r3, r6
 *   @0x2aeac4 str.w r12, [sp]
 *   @0x2aeac8 str r7, [sp, #0x4]
 *   @0x2aeacc .word 0x7e63fb71
 *   @0x2aead0 cmp r3, #0x3
 *   @0x2aead4 movs r2, #0x1
 *   @0x2aead8 lsls r2, r3, #0x1e
 *   @0x2aeadc movs r2, #0x3
 *   @0x2aeae0 strb r2, [r4, #0x1d]
 *   @0x2aeae4 ldrb r3, [r4, #0x1d]
 *   @0x2aeae8 strb r3, [r4, #0x1d]
 *   @0x2aeaec ldrb r3, [r4, #0x1d]
 *   @0x2aeaf0 uxtb r3, r3
 *   @0x2aeaf4 cmp r3, #0x7
 *   @0x2aeaf8 lsrs r3, r3, #0x3
 *   @0x2aeafc b 0x2aeb04 <png_set_IHDR+0x80>
 *   @0x2aeb00 adds r5, #0x7
 *   @0x2aeb04 str r5, [r4, #0xc]
 *   @0x2aeb08 pop {r4, r5, r6, r7, pc}
 *
 * ══ §43/230 png_do_write_intrapixel  0x2b0eb6  size 134  34 条（0x2b0eb6..0x2b0f3c）
 * @func 0x2b0eb6 0x2b0f3e  size 136  34 条
 * 部分覆盖: 本节 34/67 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xfebb9f46
 * 字段偏移 top8: 0x1×1 / 0x4×1 / 0x5×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b0eb6 push {r4, r5, r6, r7, lr}
 *   @0x2b0eba lsls r2, r3, #0x1e
 *   @0x2b0ebe ldr r2, [r0]
 *   @0x2b0ec2 cmp r0, #0x8
 *   @0x2b0ec6 cmp r3, #0x2
 *   @0x2b0eca cmp r3, #0x6
 *   @0x2b0ece movs r0, #0x4
 *   @0x2b0ed2 movs r0, #0x3
 *   @0x2b0ed6 cmp r3, r2
 *   @0x2b0eda ldrb r4, [r1, #0x1]
 *   @0x2b0ede ldrb r5, [r1]
 *   @0x2b0ee2 strb r5, [r1]
 *   @0x2b0ee6 subs r4, r5, r4
 *   @0x2b0eea add r1, r0
 *   @0x2b0eee pop {r4, r5, r6, r7, pc}
 *   @0x2b0ef2 bne 0x2b0f3a <png_do_write_intrapixel+0x84>
 *   @0x2b0ef6 beq 0x2b0f00 <png_do_write_intrapixel+0x4a>
 *   @0x2b0efa bne 0x2b0f3a <png_do_write_intrapixel+0x84>
 *   @0x2b0efe b 0x2b0f02 <png_do_write_intrapixel+0x4c>
 *   @0x2b0f02 movs r3, #0x0
 *   @0x2b0f06 beq 0x2b0f3a <png_do_write_intrapixel+0x84>
 *   @0x2b0f0a adds r3, #0x1
 *   @0x2b0f0e ldrb r5, [r1]
 *   @0x2b0f12 stmdavc r12, {r1, r2, r9, r10, sp} ^
 *   @0x2b0f16 ldrb r7, [r1, #0x4]
 *   @0x2b0f1a stmdbvc r12, {r0, r2, r8, r10, sp} ^
 *   @0x2b0f1e subs r5, r5, r6
 *   @0x2b0f22 blne 0xfebb9f46 <b2_toiTime+0xfffffffffe460aa2>
 *   @0x2b0f26 uxth r5, r5
 *   @0x2b0f2a uxth r4, r4
 *   @0x2b0f2e strb r4, [r1, #0x5]
 *   @0x2b0f32 lsrs r5, r4, #0x8
 *   @0x2b0f36 add r1, r0
 *   @0x2b0f3a pop {r4, r5, r6, r7, pc}
 *
 * ══ §44/230 CSkeletonInstance::SetAnimationTransformTime(float, float, float, float, float, float)  0xbeaa0  size 132  33 条（0xbeaa0..0xbeb24）
 * @func 0xbeaa0 0xbeb24  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CSkeletonInstance::FrameCount(int) / CSkeletonInstance::SetAnimationTransform(int, float, float, float, float, float, CInstance*)
 * 字段偏移 top8: 0x38×1 / 0x3c×1 / 0x40×1 / 0x24×1 / 0x4×1 / 0x8×1 / 0xc×1
 * VFP 指令 11 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xbeaa0 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0xbeaa4 vpush {d8}
 *   @0xbeaa8 sub sp, sp, #20
 *   @0xbeaac vmov s16, r1
 *   @0xbeab0 mov r1, #0
 *   @0xbeab4 mov r4, r0
 *   @0xbeab8 mov r5, r3
 *   @0xbeabc mov r6, r2
 *   @0xbeac0 ldr r9, [sp, #0x38]
 *   @0xbeac4 ldr r8, [sp, #0x3c]
 *   @0xbeac8 ldr r7, [sp, #0x40]
 *   @0xbeacc bl 0xbe220 <_ZN17CSkeletonInstance10FrameCountEi>
 *   @0xbead0 ldr r3, [r4, #0x24]
 *   @0xbead4 vldr s15, [r3, #4]
 *   @0xbead8 vdiv.f32 s16, s16, s15
 *   @0xbeadc str r9, [sp]
 *   @0xbeae0 mov r2, r6
 *   @0xbeae4 str r8, [sp, #0x4]
 *   @0xbeae8 mov r3, r5
 *   @0xbeaec str r7, [sp, #0x8]
 *   @0xbeaf0 mov r1, #0
 *   @0xbeaf4 str r1, [sp, #0xc]
 *   @0xbeaf8 vmov s13, r0
 *   @0xbeafc mov r0, r4
 *   @0xbeb00 vmov.f32 s15, #5.000000e-01
 *   @0xbeb04 vcvt.f32.s32 s14, s13
 *   @0xbeb08 vmla.f32 s15, s16, s14
 *   @0xbeb0c vcvt.s32.f32 s15, s15
 *   @0xbeb10 vmov r1, s15
 *   @0xbeb14 bl 0xbe80c <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance>
 *   @0xbeb18 add sp, sp, #20
 *   @0xbeb1c vpop {d8}
 *   @0xbeb20 pop {r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §45/230 Background_Name(int)  0xc3688  size 132  33 条（0xc3688..0xc370c）
 * @func 0xc3688 0xc370c  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Background_Name(int)+0x54
 * 字段偏移 top8: 0x2×2 / 0x5c×1 / 0x4c×1 / 0x4×1 / 0x38×1 / 0x28×1 / 0x20×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc3688 cmp r0, #0
 *   @0xc368c blt 0xc36dc <_Z15Background_Namei+0x54>
 *   @0xc3690 ldr r3, [pc, #0x5c]
 *   @0xc3694 ldr r3, [pc, r3]
 *   @0xc3698 ldr r3, [r3]
 *   @0xc369c cmp r0, r3
 *   @0xc36a0 bge 0xc36d0 <_Z15Background_Namei+0x48>
 *   @0xc36a4 ldr r3, [pc, #0x4c]
 *   @0xc36a8 add r3, pc, r3
 *   @0xc36ac ldr r3, [r3, #0x4]
 *   @0xc36b0 ldr r3, [r3, r0, lsl #2]
 *   @0xc36b4 cmp r3, #0
 *   @0xc36b8 beq 0xc36e8 <_Z15Background_Namei+0x60>
 *   @0xc36bc ldr r3, [pc, #0x38]
 *   @0xc36c0 ldr r3, [pc, r3]
 *   @0xc36c4 ldr r3, [r3]
 *   @0xc36c8 ldr r0, [r3, r0, lsl #2]
 *   @0xc36cc bx lr
 *   @0xc36d0 ldr r0, [pc, #0x28]
 *   @0xc36d4 add r0, pc, r0
 *   @0xc36d8 bx lr
 *   @0xc36dc ldr r0, [pc, #0x20]
 *   @0xc36e0 add r0, pc, r0
 *   @0xc36e4 bx lr
 *   @0xc36e8 ldr r0, [pc, #0x18]
 *   @0xc36ec add r0, pc, r0
 *   @0xc36f0 bx lr
 *   @0xc36f4 ldrhteq r10, [r2], -r4
 *   @0xc36f8 eorseq r6, r11, r0, lsl #12
 *   @0xc36fc eorseq r10, r2, r12, lsl #5
 *   @0xc3700 eoreq sp, r6, r12, ror #7
 *   @0xc3704 eoreq sp, r6, r0, ror #7
 *   @0xc3708 .word 0x0026d3d4
 *
 * ══ §46/230 VMBuffer::~VMBuffer()  0xce43c  size 132  33 条（0xce43c..0xce4c0）
 * @func 0xce43c 0xce4c0  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / MemoryInWad(void*) / operator delete[](void*)
 * 字段偏移 top8: 0x10×3 / 0x14×2 / 0x18×2 / 0x6c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xce43c push {r4, lr}
 *   @0xce440 mov r4, r0
 *   @0xce444 ldr r0, [r0, #0x14]
 *   @0xce448 ldr r3, [pc, #0x6c]
 *   @0xce44c cmp r0, #0
 *   @0xce450 ldr r3, [pc, r3]
 *   @0xce454 add r3, r3, #8
 *   @0xce458 str r3, [r4]
 *   @0xce45c beq 0xce46c <_ZN8VMBufferD2Ev+0x30>
 *   @0xce460 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xce464 mov r3, #0
 *   @0xce468 str r3, [r4, #0x14]
 *   @0xce46c ldr r0, [r4, #0x18]
 *   @0xce470 cmp r0, #0
 *   @0xce474 beq 0xce484 <_ZN8VMBufferD2Ev+0x48>
 *   @0xce478 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xce47c mov r3, #0
 *   @0xce480 str r3, [r4, #0x18]
 *   @0xce484 ldr r0, [r4, #0x10]
 *   @0xce488 cmp r0, #0
 *   @0xce48c beq 0xce4b4 <_ZN8VMBufferD2Ev+0x78>
 *   @0xce490 bl 0x1aad50 <_Z11MemoryInWadPv>
 *   @0xce494 cmp r0, #0
 *   @0xce498 bne 0xce4b4 <_ZN8VMBufferD2Ev+0x78>
 *   @0xce49c ldr r0, [r4, #0x10]
 *   @0xce4a0 cmp r0, #0
 *   @0xce4a4 beq 0xce4ac <_ZN8VMBufferD2Ev+0x70>
 *   @0xce4a8 bl 0x27d1d4 <_ZdaPv>
 *   @0xce4ac mov r3, #0
 *   @0xce4b0 str r3, [r4, #0x10]
 *   @0xce4b4 mov r0, r4
 *   @0xce4b8 pop {r4, pc}
 *   @0xce4bc ldrsbteq pc, [r1], -r12
 *
 * ══ §47/230 StartGCThread()  0xd3d98  size 132  33 条（0xd3d98..0xd3e1c）
 * @func 0xd3d98 0xd3e1c  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int)×2 / Mutex::Mutex(char const*)
 * 字段偏移 top8: 0x6c×1 / 0x8×1 / 0x4×1 / 0x9×1 / 0xc×1 / 0x10×1 / 0x30×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd3d98 push {r4, r5, r6, r7, r8, lr}
 *   @0xd3d9c ldr r4, [pc, #0x6c]
 *   @0xd3da0 ldr r4, [pc, r4]
 *   @0xd3da4 ldr r5, [r4]
 *   @0xd3da8 cmp r5, #0
 *   @0xd3dac popne {r4, r5, r6, r7, r8, pc}
 *   @0xd3db0 mov r0, #24
 *   @0xd3db4 bl 0x27c524 <_Znwj>
 *   @0xd3db8 mov r6, r0
 *   @0xd3dbc strb r5, [r0, #0x8]
 *   @0xd3dc0 str r5, [r6]
 *   @0xd3dc4 mov r0, #8
 *   @0xd3dc8 str r5, [r6, #0x4]
 *   @0xd3dcc strb r5, [r6, #0x9]
 *   @0xd3dd0 str r5, [r6, #0xc]
 *   @0xd3dd4 str r5, [r6, #0x10]
 *   @0xd3dd8 bl 0x27c524 <_Znwj>
 *   @0xd3ddc ldr r1, [pc, #0x30]
 *   @0xd3de0 add r1, pc, r1
 *   @0xd3de4 mov r7, r0
 *   @0xd3de8 bl 0x27e070 <_ZN5MutexC2EPKc>
 *   @0xd3dec ldr r1, [pc, #0x24]
 *   @0xd3df0 mov r0, r6
 *   @0xd3df4 str r7, [r6, #0x14]
 *   @0xd3df8 mov r2, r5
 *   @0xd3dfc str r6, [r4]
 *   @0xd3e00 ldr r1, [pc, r1]
 *   @0xd3e04 mov r3, #1
 *   @0xd3e08 pop {r4, r5, r6, r7, r8, lr}
 *   @0xd3e0c b 0x27e0c0 <_ZN7CThread5StartEPFPvS0_ES0_NS_9ePriorityE>
 *   @0xd3e10 eorseq r9, r1, r4, lsl #29
 *   @0xd3e14 .word 0x0025e9d4
 *   @0xd3e18 eorseq r9, r1, r8, lsr #28
 *
 * ══ §48/230 VMWriteBuffer::~VMWriteBuffer()  0xec4a4  size 132  33 条（0xec4a4..0xec528）
 * @func 0xec4a4 0xec528  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / MemoryInWad(void*) / operator delete[](void*)
 * 字段偏移 top8: 0x10×3 / 0x14×2 / 0x18×2 / 0x6c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xec4a4 push {r4, lr}
 *   @0xec4a8 mov r4, r0
 *   @0xec4ac ldr r0, [r0, #0x14]
 *   @0xec4b0 ldr r3, [pc, #0x6c]
 *   @0xec4b4 cmp r0, #0
 *   @0xec4b8 ldr r3, [pc, r3]
 *   @0xec4bc add r3, r3, #8
 *   @0xec4c0 str r3, [r4]
 *   @0xec4c4 beq 0xec4d4 <_ZN13VMWriteBufferD2Ev+0x30>
 *   @0xec4c8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xec4cc mov r3, #0
 *   @0xec4d0 str r3, [r4, #0x14]
 *   @0xec4d4 ldr r0, [r4, #0x18]
 *   @0xec4d8 cmp r0, #0
 *   @0xec4dc beq 0xec4ec <_ZN13VMWriteBufferD2Ev+0x48>
 *   @0xec4e0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xec4e4 mov r3, #0
 *   @0xec4e8 str r3, [r4, #0x18]
 *   @0xec4ec ldr r0, [r4, #0x10]
 *   @0xec4f0 cmp r0, #0
 *   @0xec4f4 beq 0xec51c <_ZN13VMWriteBufferD2Ev+0x78>
 *   @0xec4f8 bl 0x1aad50 <_Z11MemoryInWadPv>
 *   @0xec4fc cmp r0, #0
 *   @0xec500 bne 0xec51c <_ZN13VMWriteBufferD2Ev+0x78>
 *   @0xec504 ldr r0, [r4, #0x10]
 *   @0xec508 cmp r0, #0
 *   @0xec50c beq 0xec514 <_ZN13VMWriteBufferD2Ev+0x70>
 *   @0xec510 bl 0x27d1d4 <_ZdaPv>
 *   @0xec514 mov r3, #0
 *   @0xec518 str r3, [r4, #0x10]
 *   @0xec51c mov r0, r4
 *   @0xec520 pop {r4, pc}
 *   @0xec524 eorseq r1, r0, r4, ror r6
 *
 * ══ §49/230 Font_Name(int)  0xfa2f0  size 132  33 条（0xfa2f0..0xfa374）
 * @func 0xfa2f0 0xfa374  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Font_Name(int)+0x54
 * 字段偏移 top8: 0x2×2 / 0x5c×1 / 0x4c×1 / 0x4×1 / 0x38×1 / 0x28×1 / 0x20×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfa2f0 cmp r0, #0
 *   @0xfa2f4 blt 0xfa344 <_Z9Font_Namei+0x54>
 *   @0xfa2f8 ldr r3, [pc, #0x5c]
 *   @0xfa2fc ldr r3, [pc, r3]
 *   @0xfa300 ldr r3, [r3]
 *   @0xfa304 cmp r0, r3
 *   @0xfa308 bge 0xfa338 <_Z9Font_Namei+0x48>
 *   @0xfa30c ldr r3, [pc, #0x4c]
 *   @0xfa310 ldr r3, [pc, r3]
 *   @0xfa314 ldr r3, [r3, #0x4]
 *   @0xfa318 ldr r3, [r3, r0, lsl #2]
 *   @0xfa31c cmp r3, #0
 *   @0xfa320 beq 0xfa350 <_Z9Font_Namei+0x60>
 *   @0xfa324 ldr r3, [pc, #0x38]
 *   @0xfa328 ldr r3, [pc, r3]
 *   @0xfa32c ldr r3, [r3]
 *   @0xfa330 ldr r0, [r3, r0, lsl #2]
 *   @0xfa334 bx lr
 *   @0xfa338 ldr r0, [pc, #0x28]
 *   @0xfa33c add r0, pc, r0
 *   @0xfa340 bx lr
 *   @0xfa344 ldr r0, [pc, #0x20]
 *   @0xfa348 add r0, pc, r0
 *   @0xfa34c bx lr
 *   @0xfa350 ldr r0, [pc, #0x18]
 *   @0xfa354 add r0, pc, r0
 *   @0xfa358 bx lr
 *   @0xfa35c eoreq r3, pc, r4, ror #22
 *   @0xfa360 eoreq r3, pc, r12, asr #22
 *   @0xfa364 eoreq r3, pc, r12, lsr r11
 *   @0xfa368 eoreq r6, r3, r4, lsl #15
 *   @0xfa36c eoreq r6, r3, r8, ror r7
 *   @0xfa370 eoreq r6, r3, r12, ror #14
 *
 * ══ §50/230 F_DsListDelete(RValue&, CInstance*, CInstance*, int, RValue*)  0xfc748  size 132  33 条（0xfc748..0xfc7cc）
 * @func 0xfc748 0xfc7cc  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / F_DsListDelete(RValue&, CInstance*, CInstance*, int, RValue*)+0x64
 * 字段偏移 top8: 0x10×1 / 0x54×1 / 0x44×1 / 0x4×1 / 0x2×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfc748 push {r3, r4, r5, lr}
 *   @0xfc74c mov r1, #0
 *   @0xfc750 ldr r4, [sp, #0x10]
 *   @0xfc754 mov r0, r4
 *   @0xfc758 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfc75c cmp r0, #0
 *   @0xfc760 blt 0xfc7ac <_Z14F_DsListDeleteR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0xfc764 ldr r3, [pc, #0x54]
 *   @0xfc768 ldr r3, [pc, r3]
 *   @0xfc76c ldr r3, [r3]
 *   @0xfc770 cmp r0, r3
 *   @0xfc774 bge 0xfc7ac <_Z14F_DsListDeleteR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0xfc778 ldr r3, [pc, #0x44]
 *   @0xfc77c ldr r3, [pc, r3]
 *   @0xfc780 ldr r3, [r3, #0x4]
 *   @0xfc784 ldr r5, [r3, r0, lsl #2]
 *   @0xfc788 cmp r5, #0
 *   @0xfc78c beq 0xfc7ac <_Z14F_DsListDeleteR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0xfc790 mov r0, r4
 *   @0xfc794 mov r1, #1
 *   @0xfc798 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfc79c mov r1, r0
 *   @0xfc7a0 mov r0, r5
 *   @0xfc7a4 pop {r3, r4, r5, lr}
 *   @0xfc7a8 b 0x208b94 <_ZN8CDS_List6DeleteEi>
 *   @0xfc7ac ldr r0, [pc, #0x14]
 *   @0xfc7b0 mov r1, #0
 *   @0xfc7b4 pop {r3, r4, r5, lr}
 *   @0xfc7b8 add r0, pc, r0
 *   @0xfc7bc b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfc7c0 eoreq r1, pc, r4, lsl r5
 *   @0xfc7c4 eoreq r1, pc, r4, lsl #10
 *   @0xfc7c8 eoreq r11, r3, r4, asr #8
 *
 * ══ §51/230 F_DsListSort(RValue&, CInstance*, CInstance*, int, RValue*)  0xfc864  size 132  33 条（0xfc864..0xfc8e8）
 * @func 0xfc864 0xfc8e8  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_DsListSort(RValue&, CInstance*, CInstance*, int, RValue*)+0x64 / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x10×1 / 0x54×1 / 0x44×1 / 0x4×1 / 0x2×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfc864 push {r3, r4, r5, lr}
 *   @0xfc868 mov r1, #0
 *   @0xfc86c ldr r4, [sp, #0x10]
 *   @0xfc870 mov r0, r4
 *   @0xfc874 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfc878 cmp r0, #0
 *   @0xfc87c blt 0xfc8c8 <_Z12F_DsListSortR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0xfc880 ldr r3, [pc, #0x54]
 *   @0xfc884 ldr r3, [pc, r3]
 *   @0xfc888 ldr r3, [r3]
 *   @0xfc88c cmp r0, r3
 *   @0xfc890 bge 0xfc8c8 <_Z12F_DsListSortR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0xfc894 ldr r3, [pc, #0x44]
 *   @0xfc898 ldr r3, [pc, r3]
 *   @0xfc89c ldr r3, [r3, #0x4]
 *   @0xfc8a0 ldr r5, [r3, r0, lsl #2]
 *   @0xfc8a4 cmp r5, #0
 *   @0xfc8a8 beq 0xfc8c8 <_Z12F_DsListSortR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0xfc8ac mov r0, r4
 *   @0xfc8b0 mov r1, #1
 *   @0xfc8b4 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0xfc8b8 mov r1, r0
 *   @0xfc8bc mov r0, r5
 *   @0xfc8c0 pop {r3, r4, r5, lr}
 *   @0xfc8c4 b 0x20321c <_ZN8CDS_List4SortEb>
 *   @0xfc8c8 ldr r0, [pc, #0x14]
 *   @0xfc8cc mov r1, #0
 *   @0xfc8d0 pop {r3, r4, r5, lr}
 *   @0xfc8d4 add r0, pc, r0
 *   @0xfc8d8 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfc8dc .word 0x002f13f8
 *   @0xfc8e0 eoreq r1, pc, r8, ror #7
 *   @0xfc8e4 eoreq r11, r3, r8, lsr #6
 *
 * ══ §52/230 F_DsGridDestroy(RValue&, CInstance*, CInstance*, int, RValue*)  0xfd07c  size 132  33 条（0xfd07c..0xfd100）
 * @func 0xfd07c 0xfd100  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_DsGridDestroy(RValue&, CInstance*, CInstance*, int, RValue*)+0x64 / CDS_Grid::~CDS_Grid() / operator delete(void*)
 * 字段偏移 top8: 0x4×2 / 0x2×2 / 0x10×1 / 0x58×1 / 0x48×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfd07c push {r4, r5, r6, lr}
 *   @0xfd080 mov r1, #0
 *   @0xfd084 ldr r0, [sp, #0x10]
 *   @0xfd088 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfd08c subs r4, r0, #0
 *   @0xfd090 blt 0xfd0e0 <_Z15F_DsGridDestroyR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0xfd094 ldr r3, [pc, #0x58]
 *   @0xfd098 ldr r3, [pc, r3]
 *   @0xfd09c ldr r3, [r3]
 *   @0xfd0a0 cmp r4, r3
 *   @0xfd0a4 bge 0xfd0e0 <_Z15F_DsGridDestroyR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0xfd0a8 ldr r5, [pc, #0x48]
 *   @0xfd0ac ldr r5, [pc, r5]
 *   @0xfd0b0 ldr r3, [r5, #0x4]
 *   @0xfd0b4 ldr r6, [r3, r4, lsl #2]
 *   @0xfd0b8 cmp r6, #0
 *   @0xfd0bc beq 0xfd0e0 <_Z15F_DsGridDestroyR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0xfd0c0 mov r0, r6
 *   @0xfd0c4 bl 0x20b260 <_ZN8CDS_GridD2Ev>
 *   @0xfd0c8 mov r0, r6
 *   @0xfd0cc bl 0x27d1d0 <_ZdlPv>
 *   @0xfd0d0 ldr r3, [r5, #0x4]
 *   @0xfd0d4 mov r2, #0
 *   @0xfd0d8 str r2, [r3, r4, lsl #2]
 *   @0xfd0dc pop {r4, r5, r6, pc}
 *   @0xfd0e0 ldr r0, [pc, #0x14]
 *   @0xfd0e4 mov r1, #0
 *   @0xfd0e8 pop {r4, r5, r6, lr}
 *   @0xfd0ec add r0, pc, r0
 *   @0xfd0f0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfd0f4 eoreq r0, pc, r12, ror #27
 *   @0xfd0f8 .word 0x002f0ddc
 *   @0xfd0fc eoreq r10, r3, r0, lsl r11
 *
 * ══ §53/230 utf8_strstr(char const*, char const*)  0x110c04  size 132  33 条（0x110c04..0x110c88）
 * @func 0x110c04 0x110c88  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: utf8_strlen×2 / utf8_extract_char / utf8_strncmp
 * 字段偏移 top8: 0x4×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x110c04 push {r4, r5, r6, r7, r8, lr}
 *   @0x110c08 sub sp, sp, #8
 *   @0x110c0c mov r4, r0
 *   @0x110c10 mov r5, r1
 *   @0x110c14 bl 0x110648 <utf8_strlen>
 *   @0x110c18 mov r6, r0
 *   @0x110c1c mov r0, r5
 *   @0x110c20 bl 0x110648 <utf8_strlen>
 *   @0x110c24 cmp r6, #0
 *   @0x110c28 str r4, [sp, #0x4]
 *   @0x110c2c addgt r8, sp, #4
 *   @0x110c30 mov r7, r0
 *   @0x110c34 movgt r0, r4
 *   @0x110c38 movgt r4, #0
 *   @0x110c3c bgt 0x110c54 <_Z11utf8_strstrPKcS0_+0x50>
 *   @0x110c40 b 0x110c7c <_Z11utf8_strstrPKcS0_+0x78>
 *   @0x110c44 bl 0x10fb38 <utf8_extract_char>
 *   @0x110c48 cmp r4, r6
 *   @0x110c4c beq 0x110c7c <_Z11utf8_strstrPKcS0_+0x78>
 *   @0x110c50 ldr r0, [sp, #0x4]
 *   @0x110c54 mov r1, r5
 *   @0x110c58 mov r2, r7
 *   @0x110c5c bl 0x110b34 <utf8_strncmp>
 *   @0x110c60 add r4, r4, #1
 *   @0x110c64 cmp r0, #0
 *   @0x110c68 mov r0, r8
 *   @0x110c6c bne 0x110c44 <_Z11utf8_strstrPKcS0_+0x40>
 *   @0x110c70 ldr r0, [sp, #0x4]
 *   @0x110c74 add sp, sp, #8
 *   @0x110c78 pop {r4, r5, r6, r7, r8, pc}
 *   @0x110c7c mov r0, #0
 *   @0x110c80 add sp, sp, #8
 *   @0x110c84 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §54/230 F_GameGetSpeed(RValue&, CInstance*, CInstance*, int, RValue*)  0x116840  size 132  33 条（0x116840..0x1168c4）
 * @func 0x116840 0x1168c4  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CTimingSource::GetFPS()×2 / YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x70×1 / 0xc×1 / 0x10×1
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x116840 push {r3, r4, r5, lr}
 *   @0x116844 mov r1, #0
 *   @0x116848 ldr r4, [pc, #0x70]
 *   @0x11684c mov r5, r0
 *   @0x116850 ldr r4, [pc, r4]
 *   @0x116854 vldr d7, [r4, #24]
 *   @0x116858 vcmpe.f64 d7, #0
 *   @0x11685c str r1, [r0, #0xc]
 *   @0x116860 vmrs APSR_nzcv, fpscr
 *   @0x116864 strle r1, [r0]
 *   @0x116868 strle r1, [r0, #0x4]
 *   @0x11686c pople {r3, r4, r5, pc}
 *   @0x116870 ldr r0, [sp, #0x10]
 *   @0x116874 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x116878 cmp r0, #0
 *   @0x11687c mov r0, r4
 *   @0x116880 beq 0x1168a8 <_Z14F_GameGetSpeedR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x116884 bl 0x214808 <_ZN13CTimingSource6GetFPSEv>
 *   @0x116888 vldr d7, [pc, #40]
 *   @0x11688c vmov d6, r0, r1
 *   @0x116890 vdiv.f64 d6, d7, d6
 *   @0x116894 vmov r0, r1, d6
 *   @0x116898 vmov r2, s12
 *   @0x11689c mov r3, r1
 *   @0x1168a0 stm r5, {r2, r3}
 *   @0x1168a4 pop {r3, r4, r5, pc}
 *   @0x1168a8 bl 0x214808 <_ZN13CTimingSource6GetFPSEv>
 *   @0x1168ac stm r5, {r0, r1}
 *   @0x1168b0 pop {r3, r4, r5, pc}
 *   @0x1168b4 nop
 *   @0x1168b8 andeq r0, r0, r0
 *   @0x1168bc smlawbmi lr, r0, r4, r8
 *   @0x1168c0 .word 0x002d70dc
 *
 * ══ §55/230 F_DisplayTestAll(RValue&, CInstance*, CInstance*, int, RValue*)  0x11a050  size 132  33 条（0x11a050..0x11a0d4）
 * @func 0x11a050 0x11a0d4  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×4 / DisplayTest(int, int, int, int)
 * 字段偏移 top8: 0x20×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11a050 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x11a054 mov r6, #0
 *   @0x11a058 ldr r4, [sp, #0x20]
 *   @0x11a05c mov r5, r0
 *   @0x11a060 str r6, [r0, #0xc]
 *   @0x11a064 mov r1, r6
 *   @0x11a068 mov r0, r4
 *   @0x11a06c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11a070 mov r1, #1
 *   @0x11a074 mov r9, r0
 *   @0x11a078 mov r0, r4
 *   @0x11a07c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11a080 mov r1, #2
 *   @0x11a084 mov r8, r0
 *   @0x11a088 mov r0, r4
 *   @0x11a08c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11a090 mov r1, #3
 *   @0x11a094 mov r7, r0
 *   @0x11a098 mov r0, r4
 *   @0x11a09c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11a0a0 mov r1, r8
 *   @0x11a0a4 mov r2, r7
 *   @0x11a0a8 mov r3, r0
 *   @0x11a0ac mov r0, r9
 *   @0x11a0b0 bl 0x17db5c <_Z11DisplayTestiiii>
 *   @0x11a0b4 cmp r0, #0
 *   @0x11a0b8 moveq r6, r0
 *   @0x11a0bc movne r3, r6
 *   @0x11a0c0 moveq r3, r6
 *   @0x11a0c4 movtne r3, #0x3ff0
 *   @0x11a0c8 str r6, [r5]
 *   @0x11a0cc str r3, [r5, #0x4]
 *   @0x11a0d0 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §56/230 F_SkeletonSetAnimationExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x11ce48  size 132  33 条（0x11ce48..0x11cecc）
 * @func 0x11ce48 0x11cecc  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::SkeletonAnimation() / YYGetInt32(RValue const*, int) / YYGetString(RValue const*, int) / CSkeletonInstance::SelectAnimationExt(char const*, int)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11ce48 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x11ce4c mov r4, r0
 *   @0x11ce50 mov r3, #0
 *   @0x11ce54 mov r7, r1
 *   @0x11ce58 mov r5, r3
 *   @0x11ce5c movt r3, #0xbff0
 *   @0x11ce60 str r5, [r0, #0xc]
 *   @0x11ce64 str r3, [r0, #0x4]
 *   @0x11ce68 mov r0, r1
 *   @0x11ce6c str r5, [r4]
 *   @0x11ce70 ldr r6, [sp, #0x20]
 *   @0x11ce74 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv>
 *   @0x11ce78 subs r9, r0, #0
 *   @0x11ce7c popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x11ce80 mov r1, #1
 *   @0x11ce84 mov r0, r6
 *   @0x11ce88 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11ce8c mov r1, r5
 *   @0x11ce90 mov r8, r0
 *   @0x11ce94 mov r0, r6
 *   @0x11ce98 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x11ce9c mov r2, r8
 *   @0x11cea0 mov r1, r0
 *   @0x11cea4 mov r0, r9
 *   @0x11cea8 bl 0xbe4ec <_ZN17CSkeletonInstance18SelectAnimationExtEPKci>
 *   @0x11ceac cmp r8, r5
 *   @0x11ceb0 moveq r3, #0
 *   @0x11ceb4 streq r3, [r7, #0x90]
 *   @0x11ceb8 mov r3, #0
 *   @0x11cebc mov r2, r3
 *   @0x11cec0 movt r3, #0x3ff0
 *   @0x11cec4 stm r4, {r2, r3}
 *   @0x11cec8 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §57/230 F_ScreenSave(RValue&, CInstance*, CInstance*, int, RValue*)  0x120c90  size 132  33 条（0x120c90..0x120d14）
 * @func 0x120c90 0x120d14  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int) / GR_Window_Get_Region_Width() / GR_Window_Get_Region_Height() / Graphics::GrabScreenRect(int, int, int, int, int*, int*) / SetImageALPHA(unsigned char*, int, int) / WritePNG32(char*, void*, int, int) / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x8×3 / 0xc×3 / 0x20×1 / 0x-8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x120c90 push {r4, r5, lr}
 *   @0x120c94 sub sp, sp, #20
 *   @0x120c98 mov r1, #0
 *   @0x120c9c add r4, sp, #12
 *   @0x120ca0 ldr r0, [sp, #0x20]
 *   @0x120ca4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x120ca8 mov r5, r0
 *   @0x120cac bl 0x179988 <_Z26GR_Window_Get_Region_Widthv>
 *   @0x120cb0 str r0, [sp, #0x8]
 *   @0x120cb4 bl 0x17999c <_Z27GR_Window_Get_Region_Heightv>
 *   @0x120cb8 add r12, sp, #16
 *   @0x120cbc mov r2, #0
 *   @0x120cc0 mov r3, r2
 *   @0x120cc4 mov r1, r0
 *   @0x120cc8 str r0, [sp, #0xc]
 *   @0x120ccc ldr r0, [r12, #-0x8]!
 *   @0x120cd0 str r4, [sp, #0x4]
 *   @0x120cd4 str r12, [sp]
 *   @0x120cd8 bl 0x17e0dc <_ZN8Graphics14GrabScreenRectEiiiiPiS0_>
 *   @0x120cdc subs r4, r0, #0
 *   @0x120ce0 beq 0x120d0c <_Z12F_ScreenSaveR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0x120ce4 ldr r1, [sp, #0x8]
 *   @0x120ce8 ldr r2, [sp, #0xc]
 *   @0x120cec bl 0x120c3c <_Z13SetImageALPHAPhii>
 *   @0x120cf0 mov r0, r5
 *   @0x120cf4 mov r1, r4
 *   @0x120cf8 ldr r2, [sp, #0x8]
 *   @0x120cfc ldr r3, [sp, #0xc]
 *   @0x120d00 bl 0x16cc8c <_Z10WritePNG32PcPvii>
 *   @0x120d04 mov r0, r4
 *   @0x120d08 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x120d0c add sp, sp, #20
 *   @0x120d10 pop {r4, r5, pc}
 *
 * ══ §58/230 GetSpriteIndices(CInstance*, RValue*, int&, int&)  0x1226c4  size 132  33 条（0x1226c4..0x122748）
 * @func 0x1226c4 0x122748  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / GetSpriteIndices(CInstance*, RValue*, int&, int&)+0x60 / Sprite_Exists(int) / Error_Show_Action(char const*, bool) / 0xb6598
 * 字段偏移 top8: 0x30×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1226c4 push {r3, r4, r5, r6, r7, lr}
 *   @0x1226c8 mov r4, r1
 *   @0x1226cc mov r7, r0
 *   @0x1226d0 mov r1, #1
 *   @0x1226d4 mov r0, r4
 *   @0x1226d8 mov r5, r3
 *   @0x1226dc mov r6, r2
 *   @0x1226e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1226e4 cmp r0, #0
 *   @0x1226e8 str r0, [r5]
 *   @0x1226ec blt 0x122724 <_Z16GetSpriteIndicesP9CInstanceP6RValueRiS3_+0x60>
 *   @0x1226f0 mov r0, r4
 *   @0x1226f4 mov r1, #0
 *   @0x1226f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1226fc str r0, [r6]
 *   @0x122700 bl 0x1eee98 <_Z13Sprite_Existsi>
 *   @0x122704 subs r4, r0, #0
 *   @0x122708 bne 0x12271c <_Z16GetSpriteIndicesP9CInstanceP6RValueRiS3_+0x58>
 *   @0x12270c ldr r0, [pc, #0x30]
 *   @0x122710 mov r1, r4
 *   @0x122714 add r0, pc, r0
 *   @0x122718 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x12271c mov r0, r4
 *   @0x122720 pop {r3, r4, r5, r6, r7, pc}
 *   @0x122724 vldr s15, [r7, #144]
 *   @0x122728 vcvt.f64.f32 d6, s15
 *   @0x12272c vmov r0, r1, d6
 *   @0x122730 bl 0xb6598 <floor@plt>
 *   @0x122734 vmov d7, r0, r1
 *   @0x122738 vcvt.s32.f64 s15, d7
 *   @0x12273c vstr s15, [r5]
 *   @0x122740 b 0x1226f0 <_Z16GetSpriteIndicesP9CInstanceP6RValueRiS3_+0x2c>
 *   @0x122744 eoreq r7, r1, r0, lsr #17
 *
 * ══ §59/230 YYGML_draw_sprite_part(CInstance*, int, int, float, float, float, float, float, float)  0x1231dc  size 132  33 条（0x1231dc..0x123260）
 * @func 0x1231dc 0x123260  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Sprite_Data(int) / GR_Draw_Get_Alpha() / CSprite::DrawPart(int, float, float, float, float, float, float, float, float, unsigned int, float)
 * 字段偏移 top8: 0x48×1 / 0x4c×1 / 0x50×1 / 0x54×1 / 0x58×1 / 0x4×1 / 0x8×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1231dc push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1231e0 subs r4, r2, #0
 *   @0x1231e4 vldrlt s15, [r0, #144]
 *   @0x1231e8 sub sp, sp, #36
 *   @0x1231ec mov r0, r1
 *   @0x1231f0 vcvtlt.s32.f32 s15, s15
 *   @0x1231f4 mov r7, r3
 *   @0x1231f8 ldr r5, [sp, #0x48]
 *   @0x1231fc ldr r11, [sp, #0x4c]
 *   @0x123200 ldr r10, [sp, #0x50]
 *   @0x123204 ldr r9, [sp, #0x54]
 *   @0x123208 ldr r8, [sp, #0x58]
 *   @0x12320c vmovlt r4, s15
 *   @0x123210 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x123214 mov r6, r0
 *   @0x123218 bl 0x169f1c <_Z17GR_Draw_Get_Alphav>
 *   @0x12321c mov r12, #1065353216
 *   @0x123220 mvn lr, #-16777216
 *   @0x123224 str r11, [sp]
 *   @0x123228 mov r1, r4
 *   @0x12322c str r10, [sp, #0x4]
 *   @0x123230 mov r2, r7
 *   @0x123234 str r9, [sp, #0x8]
 *   @0x123238 mov r3, r5
 *   @0x12323c str r8, [sp, #0xc]
 *   @0x123240 str lr, [sp, #0x18]
 *   @0x123244 str r12, [sp, #0x10]
 *   @0x123248 str r12, [sp, #0x14]
 *   @0x12324c str r0, [sp, #0x1c]
 *   @0x123250 mov r0, r6
 *   @0x123254 bl 0x1e5e34 <_ZN7CSprite8DrawPartEiffffffffjf>
 *   @0x123258 add sp, sp, #36
 *   @0x12325c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §60/230 F_ShowVideo(RValue&, CInstance*, CInstance*, int, RValue*)  0x126298  size 132  33 条（0x126298..0x12631c）
 * @func 0x126298 0x12631c  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetBool(RValue const*, int)×2 / YYGetString(RValue const*, int) / Splash_Show_Movie(char const*, bool) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x5c×2 / 0x10×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x126298 push {r3, r4, r5, lr}
 *   @0x12629c mov r1, #1
 *   @0x1262a0 ldr r4, [sp, #0x10]
 *   @0x1262a4 mov r0, r4
 *   @0x1262a8 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x1262ac ldr r2, [pc, #0x5c]
 *   @0x1262b0 ldr r3, [pc, #0x5c]
 *   @0x1262b4 mov r1, #0
 *   @0x1262b8 ldr r2, [pc, r2]
 *   @0x1262bc ldr r3, [pc, r3]
 *   @0x1262c0 mov r12, r0
 *   @0x1262c4 mov r0, r4
 *   @0x1262c8 eor lr, r12, #1
 *   @0x1262cc strb r12, [r2]
 *   @0x1262d0 strb lr, [r3]
 *   @0x1262d4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1262d8 mov r1, #2
 *   @0x1262dc mov r5, r0
 *   @0x1262e0 mov r0, r4
 *   @0x1262e4 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x1262e8 mov r1, r0
 *   @0x1262ec mov r0, r5
 *   @0x1262f0 bl 0x1dc774 <_Z17Splash_Show_MoviePKcb>
 *   @0x1262f4 subs r1, r0, #0
 *   @0x1262f8 bne 0x126308 <_Z11F_ShowVideoR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x1262fc ldr r0, [pc, #0x14]
 *   @0x126300 add r0, pc, r0
 *   @0x126304 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x126308 pop {r3, r4, r5, lr}
 *   @0x12630c b 0x18c2c8 <_Z8IO_Clearv>
 *   @0x126310 eoreq r8, r12, r12, ror r7
 *   @0x126314 eoreq r8, r12, r8, lsl #15
 *   @0x126318 .word 0x00215dfc
 *
 * ══ §61/230 F_ShowImage(RValue&, CInstance*, CInstance*, int, RValue*)  0x1264c8  size 132  33 条（0x1264c8..0x12654c）
 * @func 0x1264c8 0x12654c  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetBool(RValue const*, int) / YYGetString(RValue const*, int) / YYGetInt32(RValue const*, int) / Splash_Show_Image(char const*, int) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x5c×2 / 0x10×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1264c8 push {r3, r4, r5, lr}
 *   @0x1264cc mov r1, #1
 *   @0x1264d0 ldr r4, [sp, #0x10]
 *   @0x1264d4 mov r0, r4
 *   @0x1264d8 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x1264dc ldr r2, [pc, #0x5c]
 *   @0x1264e0 ldr r3, [pc, #0x5c]
 *   @0x1264e4 mov r1, #0
 *   @0x1264e8 ldr r2, [pc, r2]
 *   @0x1264ec ldr r3, [pc, r3]
 *   @0x1264f0 mov r12, r0
 *   @0x1264f4 mov r0, r4
 *   @0x1264f8 eor lr, r12, #1
 *   @0x1264fc strb r12, [r2]
 *   @0x126500 strb lr, [r3]
 *   @0x126504 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x126508 mov r1, #2
 *   @0x12650c mov r5, r0
 *   @0x126510 mov r0, r4
 *   @0x126514 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x126518 mov r1, r0
 *   @0x12651c mov r0, r5
 *   @0x126520 bl 0x1dc77c <_Z17Splash_Show_ImagePKci>
 *   @0x126524 subs r1, r0, #0
 *   @0x126528 bne 0x126538 <_Z11F_ShowImageR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x12652c ldr r0, [pc, #0x14]
 *   @0x126530 add r0, pc, r0
 *   @0x126534 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x126538 pop {r3, r4, r5, lr}
 *   @0x12653c b 0x18c2c8 <_Z8IO_Clearv>
 *   @0x126540 eoreq r8, r12, r12, asr #10
 *   @0x126544 eoreq r8, r12, r8, asr r5
 *   @0x126548 .word 0x00215cd4
 *
 * ══ §62/230 F_SpriteSetSpeed(RValue&, CInstance*, CInstance*, int, RValue*)  0x12d4b8  size 132  33 条（0x12d4b8..0x12d53c）
 * @func 0x12d4b8 0x12d53c  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / Sprite_Data(int) / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x10×1 / 0x6c×1 / 0x70×1 / 0x20×1 / 0x1c×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12d4b8 push {r4, r5, r6, lr}
 *   @0x12d4bc mov r1, #0
 *   @0x12d4c0 ldr r4, [sp, #0x10]
 *   @0x12d4c4 mov r0, r4
 *   @0x12d4c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12d4cc mov r1, #0
 *   @0x12d4d0 mov r6, r0
 *   @0x12d4d4 mov r0, r4
 *   @0x12d4d8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12d4dc bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x12d4e0 subs r5, r0, #0
 *   @0x12d4e4 beq 0x12d50c <_Z16F_SpriteSetSpeedR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x12d4e8 mov r1, #1
 *   @0x12d4ec mov r0, r4
 *   @0x12d4f0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x12d4f4 mov r1, #2
 *   @0x12d4f8 str r0, [r5, #0x6c]
 *   @0x12d4fc mov r0, r4
 *   @0x12d500 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12d504 str r0, [r5, #0x70]
 *   @0x12d508 pop {r4, r5, r6, pc}
 *   @0x12d50c ldr r3, [pc, #0x20]
 *   @0x12d510 mov r2, r6
 *   @0x12d514 ldr r1, [pc, #0x1c]
 *   @0x12d518 ldr r3, [pc, r3]
 *   @0x12d51c add r1, pc, r1
 *   @0x12d520 ldr r0, [r3]
 *   @0x12d524 ldr r3, [r0]
 *   @0x12d528 ldr r3, [r3, #0xc]
 *   @0x12d52c blx r3
 *   @0x12d530 pop {r4, r5, r6, pc}
 *   @0x12d534 .word 0x002c01fc
 *   @0x12d538 eoreq pc, r0, r4, lsl #31
 *
 * ══ §63/230 F_RoomGetCamera(RValue&, CInstance*, CInstance*, int, RValue*)  0x12e4c0  size 132  33 条（0x12e4c0..0x12e544）
 * @func 0x12e4c0 0x12e544  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / Room_Data(int)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x2×1 / 0x40×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12e4c0 push {r4, r5, r6, lr}
 *   @0x12e4c4 mov r1, #0
 *   @0x12e4c8 ldr r5, [sp, #0x10]
 *   @0x12e4cc mov r4, r0
 *   @0x12e4d0 str r1, [r0, #0xc]
 *   @0x12e4d4 mov r0, r5
 *   @0x12e4d8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e4dc mov r1, #1
 *   @0x12e4e0 mov r6, r0
 *   @0x12e4e4 mov r0, r5
 *   @0x12e4e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e4ec mov r5, r0
 *   @0x12e4f0 mov r0, r6
 *   @0x12e4f4 bl 0x1b52c4 <_Z9Room_Datai>
 *   @0x12e4f8 cmp r0, #0
 *   @0x12e4fc beq 0x12e530 <_Z15F_RoomGetCameraR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x12e500 cmp r5, #7
 *   @0x12e504 bhi 0x12e530 <_Z15F_RoomGetCameraR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x12e508 add r5, r5, #18
 *   @0x12e50c ldr r3, [r0, r5, lsl #2]
 *   @0x12e510 cmp r3, #0
 *   @0x12e514 beq 0x12e530 <_Z15F_RoomGetCameraR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x12e518 ldr r2, [r3, #0x40]
 *   @0x12e51c vmov s15, r2
 *   @0x12e520 vcvt.f64.s32 d7, s15
 *   @0x12e524 vmov r2, r3, d7
 *   @0x12e528 stm r4, {r2, r3}
 *   @0x12e52c pop {r4, r5, r6, pc}
 *   @0x12e530 mov r3, #0
 *   @0x12e534 mov r2, r3
 *   @0x12e538 movt r3, #0xbff0
 *   @0x12e53c stm r4, {r2, r3}
 *   @0x12e540 pop {r4, r5, r6, pc}
 *
 * ══ §64/230 F_SpriteSetBbox(RValue&, CInstance*, CInstance*, int, RValue*)  0x130dec  size 132  33 条（0x130dec..0x130e70）
 * @func 0x130dec 0x130e70  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×5 / Sprite_Data(int) / CSprite::SetBoundingBox(tagYYRECT*) / MarkInstancesAsDirty(int)
 * 字段偏移 top8: 0x20×1 / 0x4×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x130dec push {r4, r5, r6, lr}
 *   @0x130df0 sub sp, sp, #16
 *   @0x130df4 mov r1, #0
 *   @0x130df8 ldr r4, [sp, #0x20]
 *   @0x130dfc mov r0, r4
 *   @0x130e00 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x130e04 mov r5, r0
 *   @0x130e08 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x130e0c subs r6, r0, #0
 *   @0x130e10 beq 0x130e68 <_Z15F_SpriteSetBboxR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0x130e14 mov r1, #1
 *   @0x130e18 mov r0, r4
 *   @0x130e1c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x130e20 mov r1, #2
 *   @0x130e24 str r0, [sp]
 *   @0x130e28 mov r0, r4
 *   @0x130e2c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x130e30 mov r1, #3
 *   @0x130e34 str r0, [sp, #0x4]
 *   @0x130e38 mov r0, r4
 *   @0x130e3c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x130e40 mov r1, #4
 *   @0x130e44 str r0, [sp, #0x8]
 *   @0x130e48 mov r0, r4
 *   @0x130e4c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x130e50 mov r1, sp
 *   @0x130e54 str r0, [sp, #0xc]
 *   @0x130e58 mov r0, r6
 *   @0x130e5c bl 0x1e32e8 <_ZN7CSprite14SetBoundingBoxEP9tagYYRECT>
 *   @0x130e60 mov r0, r5
 *   @0x130e64 bl 0x130cac <_Z20MarkInstancesAsDirtyi>
 *   @0x130e68 add sp, sp, #16
 *   @0x130e6c pop {r4, r5, r6, pc}
 *
 * ══ §65/230 F_SoundEffectSet(RValue&, CInstance*, CInstance*, int, RValue*)  0x133de4  size 132  33 条（0x133de4..0x133e68）
 * @func 0x133de4 0x133e68  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / Sound_Data(int) / CSound::GetSoundId()
 * 字段偏移 top8: 0x10×2 / 0x6c×1 / 0x58×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x133de4 push {r3, r4, r5, lr}
 *   @0x133de8 ldr r3, [pc, #0x6c]
 *   @0x133dec ldr r4, [sp, #0x10]
 *   @0x133df0 ldr r3, [pc, r3]
 *   @0x133df4 ldrb r3, [r3]
 *   @0x133df8 cmp r3, #0
 *   @0x133dfc popne {r3, r4, r5, pc}
 *   @0x133e00 ldr r3, [pc, #0x58]
 *   @0x133e04 ldr r3, [pc, r3]
 *   @0x133e08 ldrb r1, [r3]
 *   @0x133e0c cmp r1, #0
 *   @0x133e10 popne {r3, r4, r5, pc}
 *   @0x133e14 mov r0, r4
 *   @0x133e18 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x133e1c bl 0x21fcd4 <_Z10Sound_Datai>
 *   @0x133e20 subs r1, r0, #0
 *   @0x133e24 beq 0x133e4c <_Z16F_SoundEffectSetR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x133e28 bl 0x215748 <_ZN6CSound10GetSoundIdEv>
 *   @0x133e2c mov r1, #1
 *   @0x133e30 mov r5, r0
 *   @0x133e34 mov r0, r4
 *   @0x133e38 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x133e3c mov r1, r0
 *   @0x133e40 mov r0, r5
 *   @0x133e44 pop {r3, r4, r5, lr}
 *   @0x133e48 b 0x21f120 <_Z14SND_Set_Effectii>
 *   @0x133e4c ldr r0, [pc, #0x10]
 *   @0x133e50 pop {r3, r4, r5, lr}
 *   @0x133e54 add r0, pc, r0
 *   @0x133e58 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x133e5c eoreq r10, r11, r0, asr #30
 *   @0x133e60 eoreq r11, r11, r8, asr #4
 *   @0x133e64 eoreq r11, r0, r8, lsr r6
 *
 * ══ §66/230 F_AudioSetListenerPositionN(RValue&, CInstance*, CInstance*, int, RValue*)  0x134684  size 132  33 条（0x134684..0x134708）
 * @func 0x134684 0x134708  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×3 / YYGetInt32(RValue const*, int) / Audio_SetListenerPosition(int, double, double, double)
 * 字段偏移 top8: 0x78×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x134684 ldr r3, [pc, #0x78]
 *   @0x134688 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x13468c ldr r3, [pc, r3]
 *   @0x134690 sub sp, sp, #20
 *   @0x134694 ldrb r1, [r3]
 *   @0x134698 ldr r8, [sp, #0x30]
 *   @0x13469c cmp r1, #0
 *   @0x1346a0 bne 0x1346fc <_Z27F_AudioSetListenerPositionNR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x1346a4 mov r0, r8
 *   @0x1346a8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1346ac mov r1, #1
 *   @0x1346b0 mov r9, r0
 *   @0x1346b4 mov r0, r8
 *   @0x1346b8 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x1346bc mov r4, r0
 *   @0x1346c0 mov r5, r1
 *   @0x1346c4 mov r0, r8
 *   @0x1346c8 mov r1, #2
 *   @0x1346cc bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x1346d0 mov r6, r0
 *   @0x1346d4 mov r7, r1
 *   @0x1346d8 mov r0, r8
 *   @0x1346dc mov r1, #3
 *   @0x1346e0 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x1346e4 strd r6, r7, [sp]
 *   @0x1346e8 mov r2, r4
 *   @0x1346ec mov r3, r5
 *   @0x1346f0 strd r0, r1, [sp, #8]
 *   @0x1346f4 mov r0, r9
 *   @0x1346f8 bl 0x2165c0 <_Z25Audio_SetListenerPositioniddd>
 *   @0x1346fc add sp, sp, #20
 *   @0x134700 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x134704 eoreq r10, r11, r0, asr #19
 *
 * ══ §67/230 F_AudioSetListenerVelocityN(RValue&, CInstance*, CInstance*, int, RValue*)  0x134780  size 132  33 条（0x134780..0x134804）
 * @func 0x134780 0x134804  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×3 / YYGetInt32(RValue const*, int) / Audio_SetListenerVelocity(int, double, double, double)
 * 字段偏移 top8: 0x78×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x134780 ldr r3, [pc, #0x78]
 *   @0x134784 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x134788 ldr r3, [pc, r3]
 *   @0x13478c sub sp, sp, #20
 *   @0x134790 ldrb r1, [r3]
 *   @0x134794 ldr r8, [sp, #0x30]
 *   @0x134798 cmp r1, #0
 *   @0x13479c bne 0x1347f8 <_Z27F_AudioSetListenerVelocityNR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x1347a0 mov r0, r8
 *   @0x1347a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1347a8 mov r1, #1
 *   @0x1347ac mov r9, r0
 *   @0x1347b0 mov r0, r8
 *   @0x1347b4 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x1347b8 mov r4, r0
 *   @0x1347bc mov r5, r1
 *   @0x1347c0 mov r0, r8
 *   @0x1347c4 mov r1, #2
 *   @0x1347c8 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x1347cc mov r6, r0
 *   @0x1347d0 mov r7, r1
 *   @0x1347d4 mov r0, r8
 *   @0x1347d8 mov r1, #3
 *   @0x1347dc bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x1347e0 strd r6, r7, [sp]
 *   @0x1347e4 mov r2, r4
 *   @0x1347e8 mov r3, r5
 *   @0x1347ec strd r0, r1, [sp, #8]
 *   @0x1347f0 mov r0, r9
 *   @0x1347f4 bl 0x216608 <_Z25Audio_SetListenerVelocityiddd>
 *   @0x1347f8 add sp, sp, #20
 *   @0x1347fc pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x134800 eoreq r10, r11, r4, asr #17
 *
 * ══ §68/230 F_AudioSetEmitterPosition(RValue&, CInstance*, CInstance*, int, RValue*)  0x134a54  size 132  33 条（0x134a54..0x134ad8）
 * @func 0x134a54 0x134ae8  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×3 / YYGetInt32(RValue const*, int) / Audio_SetEmitterPosition(int, double, double, double)
 * 字段偏移 top8: 0x78×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x134a54 ldr r3, [pc, #0x78]
 *   @0x134a58 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x134a5c ldr r3, [pc, r3]
 *   @0x134a60 sub sp, sp, #20
 *   @0x134a64 ldrb r1, [r3]
 *   @0x134a68 ldr r8, [sp, #0x30]
 *   @0x134a6c cmp r1, #0
 *   @0x134a70 bne 0x134acc <_Z25F_AudioSetEmitterPositionR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x134a74 mov r0, r8
 *   @0x134a78 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x134a7c mov r1, #1
 *   @0x134a80 mov r9, r0
 *   @0x134a84 mov r0, r8
 *   @0x134a88 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x134a8c mov r4, r0
 *   @0x134a90 mov r5, r1
 *   @0x134a94 mov r0, r8
 *   @0x134a98 mov r1, #2
 *   @0x134a9c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x134aa0 mov r6, r0
 *   @0x134aa4 mov r7, r1
 *   @0x134aa8 mov r0, r8
 *   @0x134aac mov r1, #3
 *   @0x134ab0 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x134ab4 strd r6, r7, [sp]
 *   @0x134ab8 mov r2, r4
 *   @0x134abc mov r3, r5
 *   @0x134ac0 strd r0, r1, [sp, #8]
 *   @0x134ac4 mov r0, r9
 *   @0x134ac8 bl 0x216df8 <_Z24Audio_SetEmitterPositioniddd>
 *   @0x134acc add sp, sp, #20
 *   @0x134ad0 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x134ad4 .word 0x002ba5f0
 *
 * ══ §69/230 F_AudioSetEmitterVelocity(RValue&, CInstance*, CInstance*, int, RValue*)  0x134ad8  size 132  33 条（0x134ad8..0x134b5c）
 * @func 0x134ad8 0x134b5c  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×3 / YYGetInt32(RValue const*, int) / Audio_SetEmitterVelocity(int, double, double, double)
 * 字段偏移 top8: 0x78×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x134ad8 ldr r3, [pc, #0x78]
 *   @0x134adc push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x134ae0 ldr r3, [pc, r3]
 *   @0x134ae4 sub sp, sp, #20
 *   @0x134ae8 ldrb r1, [r3]
 *   @0x134aec ldr r8, [sp, #0x30]
 *   @0x134af0 cmp r1, #0
 *   @0x134af4 bne 0x134b50 <_Z25F_AudioSetEmitterVelocityR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x134af8 mov r0, r8
 *   @0x134afc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x134b00 mov r1, #1
 *   @0x134b04 mov r9, r0
 *   @0x134b08 mov r0, r8
 *   @0x134b0c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x134b10 mov r4, r0
 *   @0x134b14 mov r5, r1
 *   @0x134b18 mov r0, r8
 *   @0x134b1c mov r1, #2
 *   @0x134b20 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x134b24 mov r6, r0
 *   @0x134b28 mov r7, r1
 *   @0x134b2c mov r0, r8
 *   @0x134b30 mov r1, #3
 *   @0x134b34 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x134b38 strd r6, r7, [sp]
 *   @0x134b3c mov r2, r4
 *   @0x134b40 mov r3, r5
 *   @0x134b44 strd r0, r1, [sp, #8]
 *   @0x134b48 mov r0, r9
 *   @0x134b4c bl 0x216ed8 <_Z24Audio_SetEmitterVelocityiddd>
 *   @0x134b50 add sp, sp, #20
 *   @0x134b54 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x134b58 eoreq r10, r11, r12, ror #10
 *
 * ══ §70/230 F_AudioSetEmitterFalloff(RValue&, CInstance*, CInstance*, int, RValue*)  0x135108  size 132  33 条（0x135108..0x13518c）
 * @func 0x135108 0x13518c  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×3 / YYGetInt32(RValue const*, int) / Audio_SetEmitterFalloff(int, double, double, double)
 * 字段偏移 top8: 0x78×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x135108 ldr r3, [pc, #0x78]
 *   @0x13510c push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x135110 ldr r3, [pc, r3]
 *   @0x135114 sub sp, sp, #20
 *   @0x135118 ldrb r1, [r3]
 *   @0x13511c ldr r8, [sp, #0x30]
 *   @0x135120 cmp r1, #0
 *   @0x135124 bne 0x135180 <_Z24F_AudioSetEmitterFalloffR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x135128 mov r0, r8
 *   @0x13512c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x135130 mov r1, #1
 *   @0x135134 mov r9, r0
 *   @0x135138 mov r0, r8
 *   @0x13513c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x135140 mov r4, r0
 *   @0x135144 mov r5, r1
 *   @0x135148 mov r0, r8
 *   @0x13514c mov r1, #2
 *   @0x135150 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x135154 mov r6, r0
 *   @0x135158 mov r7, r1
 *   @0x13515c mov r0, r8
 *   @0x135160 mov r1, #3
 *   @0x135164 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x135168 strd r6, r7, [sp]
 *   @0x13516c mov r2, r4
 *   @0x135170 mov r3, r5
 *   @0x135174 strd r0, r1, [sp, #8]
 *   @0x135178 mov r0, r9
 *   @0x13517c bl 0x216c94 <_Z23Audio_SetEmitterFalloffiddd>
 *   @0x135180 add sp, sp, #20
 *   @0x135184 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x135188 eoreq r9, r11, r12, lsr pc
 *
 * ══ §71/230 EncodeArray(RValue*)  0x13c05c  size 132  33 条（0x13c05c..0x13c0e0）
 * @func 0x13c05c 0x13c0e0  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: json_object_new_array / EncodeArray(RValue*)+0x7c / EncodeArray(RValue*)+0x70 / EncodeValue(RValue*) / json_object_array_add
 * 字段偏移 top8: 0x10×2 / 0x4×2 / 0x3×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13c05c push {r4, r5, r6, r7, r8, lr}
 *   @0x13c060 mov r4, r0
 *   @0x13c064 bl 0x27ed80 <json_object_new_array>
 *   @0x13c068 ldr r8, [r4]
 *   @0x13c06c cmp r8, #0
 *   @0x13c070 mov r6, r0
 *   @0x13c074 beq 0x13c0d8 <_Z11EncodeArrayP6RValue+0x7c>
 *   @0x13c078 ldr r2, [r8, #0x10]
 *   @0x13c07c cmp r2, #0
 *   @0x13c080 ble 0x13c0d8 <_Z11EncodeArrayP6RValue+0x7c>
 *   @0x13c084 mov r7, #0
 *   @0x13c088 ldr r3, [r8, #0x4]
 *   @0x13c08c add r5, r3, r7, lsl #3
 *   @0x13c090 ldr r3, [r3, r7, lsl #3]
 *   @0x13c094 cmp r3, #0
 *   @0x13c098 movgt r4, #0
 *   @0x13c09c ble 0x13c0cc <_Z11EncodeArrayP6RValue+0x70>
 *   @0x13c0a0 ldr r0, [r5, #0x4]
 *   @0x13c0a4 add r0, r0, r4, lsl #4
 *   @0x13c0a8 add r4, r4, #1
 *   @0x13c0ac bl 0x13be2c <_Z11EncodeValueP6RValue>
 *   @0x13c0b0 mov r1, r0
 *   @0x13c0b4 mov r0, r6
 *   @0x13c0b8 bl 0x27edf0 <json_object_array_add>
 *   @0x13c0bc ldr r3, [r5]
 *   @0x13c0c0 cmp r3, r4
 *   @0x13c0c4 bgt 0x13c0a0 <_Z11EncodeArrayP6RValue+0x44>
 *   @0x13c0c8 ldr r2, [r8, #0x10]
 *   @0x13c0cc add r7, r7, #1
 *   @0x13c0d0 cmp r2, r7
 *   @0x13c0d4 bgt 0x13c088 <_Z11EncodeArrayP6RValue+0x2c>
 *   @0x13c0d8 mov r0, r6
 *   @0x13c0dc pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §72/230 JSONToDSMap(char*, int)  0x13d5ac  size 132  33 条（0x13d5ac..0x13d630）
 * @func 0x13d5ac 0x13d630  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: json_tokener_parse / DS_AutoMutex::DS_AutoMutex() / JSONToDSMap(char*, int)+0x68 / json_parse_to_map(json_object*, CDS_Map*) / json_object_put / DS_AutoMutex::~DS_AutoMutex() / json_parse(json_object*)
 * 字段偏移 top8: 0x48×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13d5ac push {r4, r5, r6, r7, lr}
 *   @0x13d5b0 sub sp, sp, #12
 *   @0x13d5b4 mov r6, r1
 *   @0x13d5b8 bl 0x28075c <json_tokener_parse>
 *   @0x13d5bc cmn r0, #4000
 *   @0x13d5c0 mov r4, r0
 *   @0x13d5c4 bhi 0x13d624 <_Z11JSONToDSMapPci+0x78>
 *   @0x13d5c8 add r5, sp, #4
 *   @0x13d5cc mov r0, r5
 *   @0x13d5d0 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0x13d5d4 cmp r6, #0
 *   @0x13d5d8 blt 0x13d614 <_Z11JSONToDSMapPci+0x68>
 *   @0x13d5dc ldr r3, [pc, #0x48]
 *   @0x13d5e0 mov r0, r4
 *   @0x13d5e4 mvn r7, #0
 *   @0x13d5e8 ldr r3, [pc, r3]
 *   @0x13d5ec ldr r3, [r3, #0x4]
 *   @0x13d5f0 ldr r1, [r3, r6, lsl #2]
 *   @0x13d5f4 bl 0x13cf68 <_Z17json_parse_to_mapP11json_objectP7CDS_Map>
 *   @0x13d5f8 mov r0, r4
 *   @0x13d5fc bl 0x27e7c8 <json_object_put>
 *   @0x13d600 mov r0, r5
 *   @0x13d604 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0x13d608 mov r0, r7
 *   @0x13d60c add sp, sp, #12
 *   @0x13d610 pop {r4, r5, r6, r7, pc}
 *   @0x13d614 mov r0, r4
 *   @0x13d618 bl 0x13d0dc <_Z10json_parseP11json_object>
 *   @0x13d61c mov r7, r0
 *   @0x13d620 b 0x13d5f8 <_Z11JSONToDSMapPci+0x4c>
 *   @0x13d624 mvn r7, #0
 *   @0x13d628 b 0x13d608 <_Z11JSONToDSMapPci+0x5c>
 *   @0x13d62c eoreq r0, r11, r4, asr r3
 *
 * ══ §73/230 F_ActionShowVideo(RValue&, CInstance*, CInstance*, int, RValue*)  0x13ebc8  size 132  33 条（0x13ebc8..0x13ec4c）
 * @func 0x13ebc8 0x13ec4c  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetBool(RValue const*, int)×2 / YYGetString(RValue const*, int) / Splash_Show_Movie(char const*, bool) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x5c×2 / 0x10×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13ebc8 push {r3, r4, r5, lr}
 *   @0x13ebcc mov r1, #1
 *   @0x13ebd0 ldr r4, [sp, #0x10]
 *   @0x13ebd4 mov r0, r4
 *   @0x13ebd8 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x13ebdc ldr r2, [pc, #0x5c]
 *   @0x13ebe0 ldr r3, [pc, #0x5c]
 *   @0x13ebe4 mov r1, #0
 *   @0x13ebe8 ldr r2, [pc, r2]
 *   @0x13ebec ldr r3, [pc, r3]
 *   @0x13ebf0 mov r12, r0
 *   @0x13ebf4 mov r0, r4
 *   @0x13ebf8 eor lr, r12, #1
 *   @0x13ebfc strb r12, [r2]
 *   @0x13ec00 strb lr, [r3]
 *   @0x13ec04 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x13ec08 mov r1, #2
 *   @0x13ec0c mov r5, r0
 *   @0x13ec10 mov r0, r4
 *   @0x13ec14 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x13ec18 mov r1, r0
 *   @0x13ec1c mov r0, r5
 *   @0x13ec20 bl 0x1dc774 <_Z17Splash_Show_MoviePKcb>
 *   @0x13ec24 subs r1, r0, #0
 *   @0x13ec28 bne 0x13ec38 <_Z17F_ActionShowVideoR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x13ec2c ldr r0, [pc, #0x14]
 *   @0x13ec30 add r0, pc, r0
 *   @0x13ec34 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x13ec38 pop {r3, r4, r5, lr}
 *   @0x13ec3c b 0x18c2c8 <_Z8IO_Clearv>
 *   @0x13ec40 eoreq pc, r10, r12, asr #28
 *   @0x13ec44 eoreq pc, r10, r8, asr lr
 *   @0x13ec48 andseq sp, pc, r12, asr #9
 *
 * ══ §74/230 YYGML_action_sound(int, bool)  0x141b00  size 132  33 条（0x141b00..0x141b84）
 * @func 0x141b00 0x141b84  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Sound_Data(int) / CSound::GetSoundId() / Audio_PlaySound(int, double, int)
 * 字段偏移 top8: 0x74×1 / 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x141b00 ldr r3, [pc, #0x74]
 *   @0x141b04 push {r4, r5, lr}
 *   @0x141b08 ldr r3, [pc, r3]
 *   @0x141b0c sub sp, sp, #12
 *   @0x141b10 mov r4, r1
 *   @0x141b14 ldrb r3, [r3]
 *   @0x141b18 cmp r3, #0
 *   @0x141b1c bne 0x141b4c <_Z18YYGML_action_soundib+0x4c>
 *   @0x141b20 bl 0x21fcd4 <_Z10Sound_Datai>
 *   @0x141b24 subs r1, r0, #0
 *   @0x141b28 beq 0x141b68 <_Z18YYGML_action_soundib+0x68>
 *   @0x141b2c ldr r5, [r1, #0xc]
 *   @0x141b30 bl 0x215748 <_ZN6CSound10GetSoundIdEv>
 *   @0x141b34 mov r2, r4
 *   @0x141b38 mov r1, r0
 *   @0x141b3c mov r0, r5
 *   @0x141b40 add sp, sp, #12
 *   @0x141b44 pop {r4, r5, lr}
 *   @0x141b48 b 0x21eb7c <_Z8SND_PlayPKcib>
 *   @0x141b4c str r1, [sp]
 *   @0x141b50 mov r2, #0
 *   @0x141b54 mov r3, #0
 *   @0x141b58 movt r3, #0x3ff0
 *   @0x141b5c bl 0x21b5d8 <_Z15Audio_PlaySoundidi>
 *   @0x141b60 add sp, sp, #12
 *   @0x141b64 pop {r4, r5, pc}
 *   @0x141b68 ldr r0, [pc, #0x10]
 *   @0x141b6c add r0, pc, r0
 *   @0x141b70 add sp, sp, #12
 *   @0x141b74 pop {r4, r5, lr}
 *   @0x141b78 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x141b7c eoreq sp, r10, r8, lsr #4
 *   @0x141b80 ldrsheq lr, [pc], -r0
 *
 * ══ §75/230 F_YoYo_WinPhone_SetTile_Common_Title(RValue&, CInstance*, CInstance*, int, RValue*)  0x158a08  size 132  33 条（0x158a08..0x158a8c）
 * @func 0x158a08 0x158a9c  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×4 / 0x50×2 / 0x24×2 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x158a08 cmp r3, #1
 *   @0x158a0c push {r3, lr}
 *   @0x158a10 mov r3, #0
 *   @0x158a14 str r3, [r0, #0xc]
 *   @0x158a18 str r3, [r0]
 *   @0x158a1c str r3, [r0, #0x4]
 *   @0x158a20 beq 0x158a48 <_Z36F_YoYo_WinPhone_SetTile_Common_TitleR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x158a24 ldr r3, [pc, #0x50]
 *   @0x158a28 ldr r1, [pc, #0x50]
 *   @0x158a2c ldr r3, [pc, r3]
 *   @0x158a30 add r1, pc, r1
 *   @0x158a34 ldr r0, [r3]
 *   @0x158a38 ldr r3, [r0]
 *   @0x158a3c ldr r3, [r3, #0xc]
 *   @0x158a40 blx r3
 *   @0x158a44 pop {r3, pc}
 *   @0x158a48 ldr r2, [sp, #0x8]
 *   @0x158a4c ldr r3, [r2, #0xc]
 *   @0x158a50 cmp r3, #1
 *   @0x158a54 bne 0x158a24 <_Z36F_YoYo_WinPhone_SetTile_Common_TitleR6RValueP9CInstanceS2_iPS_+0x1c>
 *   @0x158a58 ldr r3, [pc, #0x24]
 *   @0x158a5c ldr r1, [pc, #0x24]
 *   @0x158a60 ldr r3, [pc, r3]
 *   @0x158a64 add r1, pc, r1
 *   @0x158a68 ldr r0, [r3]
 *   @0x158a6c ldr r3, [r0]
 *   @0x158a70 ldr r3, [r3, #0xc]
 *   @0x158a74 blx r3
 *   @0x158a78 pop {r3, pc}
 *   @0x158a7c eoreq r4, r9, r8, ror #25
 *   @0x158a80 andseq sp, lr, r4, asr sp
 *   @0x158a84 .word 0x00294cb4
 *   @0x158a88 andseq sp, lr, r8, lsr #21
 *
 * ══ §76/230 F_YoYo_WinPhone_SetTile_Flip_BackTitle(RValue&, CInstance*, CInstance*, int, RValue*)  0x158a8c  size 132  33 条（0x158a8c..0x158b10）
 * @func 0x158a8c 0x158b20  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×4 / 0x50×2 / 0x24×2 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x158a8c cmp r3, #1
 *   @0x158a90 push {r3, lr}
 *   @0x158a94 mov r3, #0
 *   @0x158a98 str r3, [r0, #0xc]
 *   @0x158a9c str r3, [r0]
 *   @0x158aa0 str r3, [r0, #0x4]
 *   @0x158aa4 beq 0x158acc <_Z38F_YoYo_WinPhone_SetTile_Flip_BackTitleR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x158aa8 ldr r3, [pc, #0x50]
 *   @0x158aac ldr r1, [pc, #0x50]
 *   @0x158ab0 ldr r3, [pc, r3]
 *   @0x158ab4 add r1, pc, r1
 *   @0x158ab8 ldr r0, [r3]
 *   @0x158abc ldr r3, [r0]
 *   @0x158ac0 ldr r3, [r3, #0xc]
 *   @0x158ac4 blx r3
 *   @0x158ac8 pop {r3, pc}
 *   @0x158acc ldr r2, [sp, #0x8]
 *   @0x158ad0 ldr r3, [r2, #0xc]
 *   @0x158ad4 cmp r3, #1
 *   @0x158ad8 bne 0x158aa8 <_Z38F_YoYo_WinPhone_SetTile_Flip_BackTitleR6RValueP9CInstanceS2_iPS_+0x1c>
 *   @0x158adc ldr r3, [pc, #0x24]
 *   @0x158ae0 ldr r1, [pc, #0x24]
 *   @0x158ae4 ldr r3, [pc, r3]
 *   @0x158ae8 add r1, pc, r1
 *   @0x158aec ldr r0, [r3]
 *   @0x158af0 ldr r3, [r0]
 *   @0x158af4 ldr r3, [r3, #0xc]
 *   @0x158af8 blx r3
 *   @0x158afc pop {r3, pc}
 *   @0x158b00 eoreq r4, r9, r4, ror #24
 *   @0x158b04 andseq sp, lr, r8, lsl #26
 *   @0x158b08 eoreq r4, r9, r0, lsr r12
 *   @0x158b0c andseq sp, lr, r4, lsr #20
 *
 * ══ §77/230 F_YoYo_WinPhone_SetTile_Flip_BackContent(RValue&, CInstance*, CInstance*, int, RValue*)  0x158b10  size 132  33 条（0x158b10..0x158b94）
 * @func 0x158b10 0x158ba4  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×4 / 0x50×2 / 0x24×2 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x158b10 cmp r3, #1
 *   @0x158b14 push {r3, lr}
 *   @0x158b18 mov r3, #0
 *   @0x158b1c str r3, [r0, #0xc]
 *   @0x158b20 str r3, [r0]
 *   @0x158b24 str r3, [r0, #0x4]
 *   @0x158b28 beq 0x158b50 <_Z40F_YoYo_WinPhone_SetTile_Flip_BackContentR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x158b2c ldr r3, [pc, #0x50]
 *   @0x158b30 ldr r1, [pc, #0x50]
 *   @0x158b34 ldr r3, [pc, r3]
 *   @0x158b38 add r1, pc, r1
 *   @0x158b3c ldr r0, [r3]
 *   @0x158b40 ldr r3, [r0]
 *   @0x158b44 ldr r3, [r3, #0xc]
 *   @0x158b48 blx r3
 *   @0x158b4c pop {r3, pc}
 *   @0x158b50 ldr r2, [sp, #0x8]
 *   @0x158b54 ldr r3, [r2, #0xc]
 *   @0x158b58 cmp r3, #1
 *   @0x158b5c bne 0x158b2c <_Z40F_YoYo_WinPhone_SetTile_Flip_BackContentR6RValueP9CInstanceS2_iPS_+0x1c>
 *   @0x158b60 ldr r3, [pc, #0x24]
 *   @0x158b64 ldr r1, [pc, #0x24]
 *   @0x158b68 ldr r3, [pc, r3]
 *   @0x158b6c add r1, pc, r1
 *   @0x158b70 ldr r0, [r3]
 *   @0x158b74 ldr r3, [r0]
 *   @0x158b78 ldr r3, [r3, #0xc]
 *   @0x158b7c blx r3
 *   @0x158b80 pop {r3, pc}
 *   @0x158b84 eoreq r4, r9, r0, ror #23
 *   @0x158b88 andseq sp, lr, r0, asr #25
 *   @0x158b8c eoreq r4, r9, r12, lsr #23
 *   @0x158b90 andseq sp, lr, r0, lsr #19
 *
 * ══ §78/230 F_YoYo_WinPhone_SetTile_Flip_BackContentWide(RValue&, CInstance*, CInstance*, int, RValue*)  0x158b94  size 132  33 条（0x158b94..0x158c18）
 * @func 0x158b94 0x158c28  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×4 / 0x50×2 / 0x24×2 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x158b94 cmp r3, #1
 *   @0x158b98 push {r3, lr}
 *   @0x158b9c mov r3, #0
 *   @0x158ba0 str r3, [r0, #0xc]
 *   @0x158ba4 str r3, [r0]
 *   @0x158ba8 str r3, [r0, #0x4]
 *   @0x158bac beq 0x158bd4 <_Z44F_YoYo_WinPhone_SetTile_Flip_BackContentWideR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x158bb0 ldr r3, [pc, #0x50]
 *   @0x158bb4 ldr r1, [pc, #0x50]
 *   @0x158bb8 ldr r3, [pc, r3]
 *   @0x158bbc add r1, pc, r1
 *   @0x158bc0 ldr r0, [r3]
 *   @0x158bc4 ldr r3, [r0]
 *   @0x158bc8 ldr r3, [r3, #0xc]
 *   @0x158bcc blx r3
 *   @0x158bd0 pop {r3, pc}
 *   @0x158bd4 ldr r2, [sp, #0x8]
 *   @0x158bd8 ldr r3, [r2, #0xc]
 *   @0x158bdc cmp r3, #1
 *   @0x158be0 bne 0x158bb0 <_Z44F_YoYo_WinPhone_SetTile_Flip_BackContentWideR6RValueP9CInstanceS2_iPS_+0x1c>
 *   @0x158be4 ldr r3, [pc, #0x24]
 *   @0x158be8 ldr r1, [pc, #0x24]
 *   @0x158bec ldr r3, [pc, r3]
 *   @0x158bf0 add r1, pc, r1
 *   @0x158bf4 ldr r0, [r3]
 *   @0x158bf8 ldr r3, [r0]
 *   @0x158bfc ldr r3, [r3, #0xc]
 *   @0x158c00 blx r3
 *   @0x158c04 pop {r3, pc}
 *   @0x158c08 eoreq r4, r9, r12, asr r11
 *   @0x158c0c andseq sp, lr, r12, ror r12
 *   @0x158c10 eoreq r4, r9, r8, lsr #22
 *   @0x158c14 andseq sp, lr, r12, lsl r9
 *
 * ══ §79/230 F_YoYo_WinPhone_SetTile_Flip_FrontImage(RValue&, CInstance*, CInstance*, int, RValue*)  0x158c18  size 132  33 条（0x158c18..0x158c9c）
 * @func 0x158c18 0x158cac  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×4 / 0x50×2 / 0x24×2 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x158c18 cmp r3, #1
 *   @0x158c1c push {r3, lr}
 *   @0x158c20 mov r3, #0
 *   @0x158c24 str r3, [r0, #0xc]
 *   @0x158c28 str r3, [r0]
 *   @0x158c2c str r3, [r0, #0x4]
 *   @0x158c30 beq 0x158c58 <_Z39F_YoYo_WinPhone_SetTile_Flip_FrontImageR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x158c34 ldr r3, [pc, #0x50]
 *   @0x158c38 ldr r1, [pc, #0x50]
 *   @0x158c3c ldr r3, [pc, r3]
 *   @0x158c40 add r1, pc, r1
 *   @0x158c44 ldr r0, [r3]
 *   @0x158c48 ldr r3, [r0]
 *   @0x158c4c ldr r3, [r3, #0xc]
 *   @0x158c50 blx r3
 *   @0x158c54 pop {r3, pc}
 *   @0x158c58 ldr r2, [sp, #0x8]
 *   @0x158c5c ldr r3, [r2, #0xc]
 *   @0x158c60 cmp r3, #1
 *   @0x158c64 bne 0x158c34 <_Z39F_YoYo_WinPhone_SetTile_Flip_FrontImageR6RValueP9CInstanceS2_iPS_+0x1c>
 *   @0x158c68 ldr r3, [pc, #0x24]
 *   @0x158c6c ldr r1, [pc, #0x24]
 *   @0x158c70 ldr r3, [pc, r3]
 *   @0x158c74 add r1, pc, r1
 *   @0x158c78 ldr r0, [r3]
 *   @0x158c7c ldr r3, [r0]
 *   @0x158c80 ldr r3, [r3, #0xc]
 *   @0x158c84 blx r3
 *   @0x158c88 pop {r3, pc}
 *   @0x158c8c .word 0x00294ad8
 *   @0x158c90 andseq sp, lr, r12, lsr r12
 *   @0x158c94 eoreq r4, r9, r4, lsr #21
 *   @0x158c98 mulseq lr, r8, r8
 *
 * ══ §80/230 F_YoYo_WinPhone_SetTile_Flip_FrontImageSmall(RValue&, CInstance*, CInstance*, int, RValue*)  0x158c9c  size 132  33 条（0x158c9c..0x158d20）
 * @func 0x158c9c 0x158d30  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×4 / 0x50×2 / 0x24×2 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x158c9c cmp r3, #1
 *   @0x158ca0 push {r3, lr}
 *   @0x158ca4 mov r3, #0
 *   @0x158ca8 str r3, [r0, #0xc]
 *   @0x158cac str r3, [r0]
 *   @0x158cb0 str r3, [r0, #0x4]
 *   @0x158cb4 beq 0x158cdc <_Z44F_YoYo_WinPhone_SetTile_Flip_FrontImageSmallR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x158cb8 ldr r3, [pc, #0x50]
 *   @0x158cbc ldr r1, [pc, #0x50]
 *   @0x158cc0 ldr r3, [pc, r3]
 *   @0x158cc4 add r1, pc, r1
 *   @0x158cc8 ldr r0, [r3]
 *   @0x158ccc ldr r3, [r0]
 *   @0x158cd0 ldr r3, [r3, #0xc]
 *   @0x158cd4 blx r3
 *   @0x158cd8 pop {r3, pc}
 *   @0x158cdc ldr r2, [sp, #0x8]
 *   @0x158ce0 ldr r3, [r2, #0xc]
 *   @0x158ce4 cmp r3, #1
 *   @0x158ce8 bne 0x158cb8 <_Z44F_YoYo_WinPhone_SetTile_Flip_FrontImageSmallR6RValueP9CInstanceS2_iPS_+0x1c>
 *   @0x158cec ldr r3, [pc, #0x24]
 *   @0x158cf0 ldr r1, [pc, #0x24]
 *   @0x158cf4 ldr r3, [pc, r3]
 *   @0x158cf8 add r1, pc, r1
 *   @0x158cfc ldr r0, [r3]
 *   @0x158d00 ldr r3, [r0]
 *   @0x158d04 ldr r3, [r3, #0xc]
 *   @0x158d08 blx r3
 *   @0x158d0c pop {r3, pc}
 *   @0x158d10 eoreq r4, r9, r4, asr r10
 *   @0x158d14 ldrsheq sp, [lr], -r8
 *   @0x158d18 eoreq r4, r9, r0, lsr #20
 *   @0x158d1c andseq sp, lr, r4, lsl r8
 *
 * ══ §81/230 F_YoYo_WinPhone_SetTile_Flip_FrontImageWide(RValue&, CInstance*, CInstance*, int, RValue*)  0x158d20  size 132  33 条（0x158d20..0x158da4）
 * @func 0x158d20 0x158db4  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×4 / 0x50×2 / 0x24×2 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x158d20 cmp r3, #1
 *   @0x158d24 push {r3, lr}
 *   @0x158d28 mov r3, #0
 *   @0x158d2c str r3, [r0, #0xc]
 *   @0x158d30 str r3, [r0]
 *   @0x158d34 str r3, [r0, #0x4]
 *   @0x158d38 beq 0x158d60 <_Z43F_YoYo_WinPhone_SetTile_Flip_FrontImageWideR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x158d3c ldr r3, [pc, #0x50]
 *   @0x158d40 ldr r1, [pc, #0x50]
 *   @0x158d44 ldr r3, [pc, r3]
 *   @0x158d48 add r1, pc, r1
 *   @0x158d4c ldr r0, [r3]
 *   @0x158d50 ldr r3, [r0]
 *   @0x158d54 ldr r3, [r3, #0xc]
 *   @0x158d58 blx r3
 *   @0x158d5c pop {r3, pc}
 *   @0x158d60 ldr r2, [sp, #0x8]
 *   @0x158d64 ldr r3, [r2, #0xc]
 *   @0x158d68 cmp r3, #1
 *   @0x158d6c bne 0x158d3c <_Z43F_YoYo_WinPhone_SetTile_Flip_FrontImageWideR6RValueP9CInstanceS2_iPS_+0x1c>
 *   @0x158d70 ldr r3, [pc, #0x24]
 *   @0x158d74 ldr r1, [pc, #0x24]
 *   @0x158d78 ldr r3, [pc, r3]
 *   @0x158d7c add r1, pc, r1
 *   @0x158d80 ldr r0, [r3]
 *   @0x158d84 ldr r3, [r0]
 *   @0x158d88 ldr r3, [r3, #0xc]
 *   @0x158d8c blx r3
 *   @0x158d90 pop {r3, pc}
 *   @0x158d94 .word 0x002949d0
 *   @0x158d98 ldrheq sp, [lr], -r8
 *   @0x158d9c mlaeq r9, r12, r9, r4
 *   @0x158da0 mulseq lr, r0, r7
 *
 * ══ §82/230 F_YoYo_WinPhone_SetTile_Flip_BackImage(RValue&, CInstance*, CInstance*, int, RValue*)  0x158da4  size 132  33 条（0x158da4..0x158e28）
 * @func 0x158da4 0x158e38  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×4 / 0x50×2 / 0x24×2 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x158da4 cmp r3, #1
 *   @0x158da8 push {r3, lr}
 *   @0x158dac mov r3, #0
 *   @0x158db0 str r3, [r0, #0xc]
 *   @0x158db4 str r3, [r0]
 *   @0x158db8 str r3, [r0, #0x4]
 *   @0x158dbc beq 0x158de4 <_Z38F_YoYo_WinPhone_SetTile_Flip_BackImageR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x158dc0 ldr r3, [pc, #0x50]
 *   @0x158dc4 ldr r1, [pc, #0x50]
 *   @0x158dc8 ldr r3, [pc, r3]
 *   @0x158dcc add r1, pc, r1
 *   @0x158dd0 ldr r0, [r3]
 *   @0x158dd4 ldr r3, [r0]
 *   @0x158dd8 ldr r3, [r3, #0xc]
 *   @0x158ddc blx r3
 *   @0x158de0 pop {r3, pc}
 *   @0x158de4 ldr r2, [sp, #0x8]
 *   @0x158de8 ldr r3, [r2, #0xc]
 *   @0x158dec cmp r3, #1
 *   @0x158df0 bne 0x158dc0 <_Z38F_YoYo_WinPhone_SetTile_Flip_BackImageR6RValueP9CInstanceS2_iPS_+0x1c>
 *   @0x158df4 ldr r3, [pc, #0x24]
 *   @0x158df8 ldr r1, [pc, #0x24]
 *   @0x158dfc ldr r3, [pc, r3]
 *   @0x158e00 add r1, pc, r1
 *   @0x158e04 ldr r0, [r3]
 *   @0x158e08 ldr r3, [r0]
 *   @0x158e0c ldr r3, [r3, #0xc]
 *   @0x158e10 blx r3
 *   @0x158e14 pop {r3, pc}
 *   @0x158e18 eoreq r4, r9, r12, asr #18
 *   @0x158e1c andseq sp, lr, r8, ror r11
 *   @0x158e20 eoreq r4, r9, r8, lsl r9
 *   @0x158e24 andseq sp, lr, r12, lsl #14
 *
 * ══ §83/230 F_YoYo_WinPhone_SetTile_Flip_BackImageWide(RValue&, CInstance*, CInstance*, int, RValue*)  0x158e28  size 132  33 条（0x158e28..0x158eac）
 * @func 0x158e28 0x158ebc  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×4 / 0x50×2 / 0x24×2 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x158e28 cmp r3, #1
 *   @0x158e2c push {r3, lr}
 *   @0x158e30 mov r3, #0
 *   @0x158e34 str r3, [r0, #0xc]
 *   @0x158e38 str r3, [r0]
 *   @0x158e3c str r3, [r0, #0x4]
 *   @0x158e40 beq 0x158e68 <_Z42F_YoYo_WinPhone_SetTile_Flip_BackImageWideR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x158e44 ldr r3, [pc, #0x50]
 *   @0x158e48 ldr r1, [pc, #0x50]
 *   @0x158e4c ldr r3, [pc, r3]
 *   @0x158e50 add r1, pc, r1
 *   @0x158e54 ldr r0, [r3]
 *   @0x158e58 ldr r3, [r0]
 *   @0x158e5c ldr r3, [r3, #0xc]
 *   @0x158e60 blx r3
 *   @0x158e64 pop {r3, pc}
 *   @0x158e68 ldr r2, [sp, #0x8]
 *   @0x158e6c ldr r3, [r2, #0xc]
 *   @0x158e70 cmp r3, #1
 *   @0x158e74 bne 0x158e44 <_Z42F_YoYo_WinPhone_SetTile_Flip_BackImageWideR6RValueP9CInstanceS2_iPS_+0x1c>
 *   @0x158e78 ldr r3, [pc, #0x24]
 *   @0x158e7c ldr r1, [pc, #0x24]
 *   @0x158e80 ldr r3, [pc, r3]
 *   @0x158e84 add r1, pc, r1
 *   @0x158e88 ldr r0, [r3]
 *   @0x158e8c ldr r3, [r0]
 *   @0x158e90 ldr r3, [r3, #0xc]
 *   @0x158e94 blx r3
 *   @0x158e98 pop {r3, pc}
 *   @0x158e9c eoreq r4, r9, r8, asr #17
 *   @0x158ea0 andseq sp, lr, r4, lsr r11
 *   @0x158ea4 mlaeq r9, r4, r8, r4
 *   @0x158ea8 andseq sp, lr, r8, lsl #13
 *
 * ══ §84/230 F_YoYo_WinPhone_SetTile_Iconic_IconImage(RValue&, CInstance*, CInstance*, int, RValue*)  0x158eac  size 132  33 条（0x158eac..0x158f30）
 * @func 0x158eac 0x158f40  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×4 / 0x50×2 / 0x24×2 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x158eac cmp r3, #1
 *   @0x158eb0 push {r3, lr}
 *   @0x158eb4 mov r3, #0
 *   @0x158eb8 str r3, [r0, #0xc]
 *   @0x158ebc str r3, [r0]
 *   @0x158ec0 str r3, [r0, #0x4]
 *   @0x158ec4 beq 0x158eec <_Z40F_YoYo_WinPhone_SetTile_Iconic_IconImageR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x158ec8 ldr r3, [pc, #0x50]
 *   @0x158ecc ldr r1, [pc, #0x50]
 *   @0x158ed0 ldr r3, [pc, r3]
 *   @0x158ed4 add r1, pc, r1
 *   @0x158ed8 ldr r0, [r3]
 *   @0x158edc ldr r3, [r0]
 *   @0x158ee0 ldr r3, [r3, #0xc]
 *   @0x158ee4 blx r3
 *   @0x158ee8 pop {r3, pc}
 *   @0x158eec ldr r2, [sp, #0x8]
 *   @0x158ef0 ldr r3, [r2, #0xc]
 *   @0x158ef4 cmp r3, #1
 *   @0x158ef8 bne 0x158ec8 <_Z40F_YoYo_WinPhone_SetTile_Iconic_IconImageR6RValueP9CInstanceS2_iPS_+0x1c>
 *   @0x158efc ldr r3, [pc, #0x24]
 *   @0x158f00 ldr r1, [pc, #0x24]
 *   @0x158f04 ldr r3, [pc, r3]
 *   @0x158f08 add r1, pc, r1
 *   @0x158f0c ldr r0, [r3]
 *   @0x158f10 ldr r3, [r0]
 *   @0x158f14 ldr r3, [r3, #0xc]
 *   @0x158f18 blx r3
 *   @0x158f1c pop {r3, pc}
 *   @0x158f20 eoreq r4, r9, r4, asr #16
 *   @0x158f24 ldrsheq sp, [lr], -r4
 *   @0x158f28 eoreq r4, r9, r0, lsl r8
 *   @0x158f2c andseq sp, lr, r4, lsl #12
 *
 * ══ §85/230 F_YoYo_WinPhone_SetTile_Iconic_SmallIconImage(RValue&, CInstance*, CInstance*, int, RValue*)  0x158f30  size 132  33 条（0x158f30..0x158fb4）
 * @func 0x158f30 0x158fc4  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×4 / 0x50×2 / 0x24×2 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x158f30 cmp r3, #1
 *   @0x158f34 push {r3, lr}
 *   @0x158f38 mov r3, #0
 *   @0x158f3c str r3, [r0, #0xc]
 *   @0x158f40 str r3, [r0]
 *   @0x158f44 str r3, [r0, #0x4]
 *   @0x158f48 beq 0x158f70 <_Z45F_YoYo_WinPhone_SetTile_Iconic_SmallIconImageR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x158f4c ldr r3, [pc, #0x50]
 *   @0x158f50 ldr r1, [pc, #0x50]
 *   @0x158f54 ldr r3, [pc, r3]
 *   @0x158f58 add r1, pc, r1
 *   @0x158f5c ldr r0, [r3]
 *   @0x158f60 ldr r3, [r0]
 *   @0x158f64 ldr r3, [r3, #0xc]
 *   @0x158f68 blx r3
 *   @0x158f6c pop {r3, pc}
 *   @0x158f70 ldr r2, [sp, #0x8]
 *   @0x158f74 ldr r3, [r2, #0xc]
 *   @0x158f78 cmp r3, #1
 *   @0x158f7c bne 0x158f4c <_Z45F_YoYo_WinPhone_SetTile_Iconic_SmallIconImageR6RValueP9CInstanceS2_iPS_+0x1c>
 *   @0x158f80 ldr r3, [pc, #0x24]
 *   @0x158f84 ldr r1, [pc, #0x24]
 *   @0x158f88 ldr r3, [pc, r3]
 *   @0x158f8c add r1, pc, r1
 *   @0x158f90 ldr r0, [r3]
 *   @0x158f94 ldr r3, [r0]
 *   @0x158f98 ldr r3, [r3, #0xc]
 *   @0x158f9c blx r3
 *   @0x158fa0 pop {r3, pc}
 *   @0x158fa4 eoreq r4, r9, r0, asr #15
 *   @0x158fa8 ldrheq sp, [lr], -r0
 *   @0x158fac eoreq r4, r9, r12, lsl #15
 *   @0x158fb0 andseq sp, lr, r0, lsl #11
 *
 * ══ §86/230 F_YoYo_WinPhone_SetTile_Cycle_SmallBackgroundImage(RValue&, CInstance*, CInstance*, int, RValue*)  0x158fb4  size 132  33 条（0x158fb4..0x159038）
 * @func 0x158fb4 0x159038  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×4 / 0x50×2 / 0x24×2 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x158fb4 cmp r3, #1
 *   @0x158fb8 push {r3, lr}
 *   @0x158fbc mov r3, #0
 *   @0x158fc0 str r3, [r0, #0xc]
 *   @0x158fc4 str r3, [r0]
 *   @0x158fc8 str r3, [r0, #0x4]
 *   @0x158fcc beq 0x158ff4 <_Z50F_YoYo_WinPhone_SetTile_Cycle_SmallBackgroundImageR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x158fd0 ldr r3, [pc, #0x50]
 *   @0x158fd4 ldr r1, [pc, #0x50]
 *   @0x158fd8 ldr r3, [pc, r3]
 *   @0x158fdc add r1, pc, r1
 *   @0x158fe0 ldr r0, [r3]
 *   @0x158fe4 ldr r3, [r0]
 *   @0x158fe8 ldr r3, [r3, #0xc]
 *   @0x158fec blx r3
 *   @0x158ff0 pop {r3, pc}
 *   @0x158ff4 ldr r2, [sp, #0x8]
 *   @0x158ff8 ldr r3, [r2, #0xc]
 *   @0x158ffc cmp r3, #1
 *   @0x159000 bne 0x158fd0 <_Z50F_YoYo_WinPhone_SetTile_Cycle_SmallBackgroundImageR6RValueP9CInstanceS2_iPS_+0x1c>
 *   @0x159004 ldr r3, [pc, #0x24]
 *   @0x159008 ldr r1, [pc, #0x24]
 *   @0x15900c ldr r3, [pc, r3]
 *   @0x159010 add r1, pc, r1
 *   @0x159014 ldr r0, [r3]
 *   @0x159018 ldr r3, [r0]
 *   @0x15901c ldr r3, [r3, #0xc]
 *   @0x159020 blx r3
 *   @0x159024 pop {r3, pc}
 *   @0x159028 eoreq r4, r9, r12, lsr r7
 *   @0x15902c andseq sp, lr, r0, ror r10
 *   @0x159030 eoreq r4, r9, r8, lsl #14
 *   @0x159034 ldrsheq sp, [lr], -r12
 *
 * ══ §87/230 GR_3DM_Primitive_Begin(int, int)  0x1653c0  size 132  33 条（0x1653c0..0x165444）
 * @func 0x1653c0 0x165454  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_3DM_Primitive_Begin(int, int)+0x74 / C3D_Model::AddEntry(int, float, float, float, float, float, float, float, float, float, float)
 * 字段偏移 top8: 0x4×3 / 0x-4×1 / 0x64×1 / 0x54×1 / 0x2×1 / 0x8×1 / 0xc×1 / 0x10×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1653c0 cmp r0, #0
 *   @0x1653c4 str lr, [sp, #-0x4]!
 *   @0x1653c8 sub sp, sp, #36
 *   @0x1653cc blt 0x165434 <_Z22GR_3DM_Primitive_Beginii+0x74>
 *   @0x1653d0 ldr r3, [pc, #0x64]
 *   @0x1653d4 ldr r3, [pc, r3]
 *   @0x1653d8 ldr r3, [r3]
 *   @0x1653dc cmp r0, r3
 *   @0x1653e0 bge 0x165434 <_Z22GR_3DM_Primitive_Beginii+0x74>
 *   @0x1653e4 ldr r3, [pc, #0x54]
 *   @0x1653e8 ldr r3, [pc, r3]
 *   @0x1653ec ldr r3, [r3, #0x4]
 *   @0x1653f0 ldr r0, [r3, r0, lsl #2]
 *   @0x1653f4 cmp r0, #0
 *   @0x1653f8 beq 0x165434 <_Z22GR_3DM_Primitive_Beginii+0x74>
 *   @0x1653fc vmov s15, r1
 *   @0x165400 mov r3, #0
 *   @0x165404 mov r1, #0
 *   @0x165408 str r3, [sp]
 *   @0x16540c vcvt.f32.s32 s15, s15
 *   @0x165410 str r3, [sp, #0x4]
 *   @0x165414 str r3, [sp, #0x8]
 *   @0x165418 str r3, [sp, #0xc]
 *   @0x16541c str r3, [sp, #0x10]
 *   @0x165420 str r3, [sp, #0x14]
 *   @0x165424 str r3, [sp, #0x18]
 *   @0x165428 str r3, [sp, #0x1c]
 *   @0x16542c vmov r2, s15
 *   @0x165430 bl 0x1648d4 <_ZN9C3D_Model8AddEntryEiffffffffff>
 *   @0x165434 add sp, sp, #36
 *   @0x165438 ldr pc, [sp], #4
 *   @0x16543c eoreq r10, r8, r12, lsl sp
 *   @0x165440 eoreq r10, r8, r12, lsl #26
 *
 * ══ §88/230 GR_3DM_Vertex(int, float, float, float)  0x165444  size 132  33 条（0x165444..0x1654c8）
 * @func 0x165444 0x1654c8  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_3DM_Vertex(int, float, float, float)+0x74 / C3D_Model::AddEntry(int, float, float, float, float, float, float, float, float, float, float)
 * 字段偏移 top8: 0x4×2 / 0x60×1 / 0x50×1 / 0x2×1 / 0x8×1 / 0xc×1 / 0x10×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x165444 cmp r0, #0
 *   @0x165448 push {r4, lr}
 *   @0x16544c mov r4, r2
 *   @0x165450 sub sp, sp, #32
 *   @0x165454 blt 0x1654b8 <_Z13GR_3DM_Vertexifff+0x74>
 *   @0x165458 ldr r12, [pc, #0x60]
 *   @0x16545c ldr r12, [pc, r12]
 *   @0x165460 ldr r12, [r12]
 *   @0x165464 cmp r0, r12
 *   @0x165468 bge 0x1654b8 <_Z13GR_3DM_Vertexifff+0x74>
 *   @0x16546c ldr r12, [pc, #0x50]
 *   @0x165470 ldr r12, [pc, r12]
 *   @0x165474 ldr r2, [r12, #0x4]
 *   @0x165478 ldr r0, [r2, r0, lsl #2]
 *   @0x16547c cmp r0, #0
 *   @0x165480 beq 0x1654b8 <_Z13GR_3DM_Vertexifff+0x74>
 *   @0x165484 str r3, [sp]
 *   @0x165488 mov r2, r1
 *   @0x16548c mov r3, r4
 *   @0x165490 mov r1, #0
 *   @0x165494 str r1, [sp, #0x4]
 *   @0x165498 str r1, [sp, #0x8]
 *   @0x16549c str r1, [sp, #0xc]
 *   @0x1654a0 str r1, [sp, #0x10]
 *   @0x1654a4 str r1, [sp, #0x14]
 *   @0x1654a8 str r1, [sp, #0x18]
 *   @0x1654ac str r1, [sp, #0x1c]
 *   @0x1654b0 mov r1, #2
 *   @0x1654b4 bl 0x1648d4 <_ZN9C3D_Model8AddEntryEiffffffffff>
 *   @0x1654b8 add sp, sp, #32
 *   @0x1654bc pop {r4, pc}
 *   @0x1654c0 mlaeq r8, r4, r12, r10
 *   @0x1654c4 eoreq r10, r8, r4, lsl #25
 *
 * ══ §89/230 CBitmap32::RemoveBackground()  0x166404  size 132  33 条（0x166404..0x166488）
 * @func 0x166404 0x166488  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CBitmap32::RemoveBackground()+0x74 / CBitmap32::RemoveBackground()+0x4c
 * 字段偏移 top8: 0x4×2 / 0xc×1 / 0x8×1 / 0x14×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x166404 ldrb r3, [r0, #0x4]
 *   @0x166408 push {r4, r5}
 *   @0x16640c cmp r3, #0
 *   @0x166410 beq 0x166480 <_ZN9CBitmap3216RemoveBackgroundEv+0x7c>
 *   @0x166414 ldr r12, [r0, #0xc]
 *   @0x166418 cmp r12, #0
 *   @0x16641c beq 0x166480 <_ZN9CBitmap3216RemoveBackgroundEv+0x7c>
 *   @0x166420 ldr r4, [r0, #0x8]
 *   @0x166424 cmp r4, #0
 *   @0x166428 beq 0x166480 <_ZN9CBitmap3216RemoveBackgroundEv+0x7c>
 *   @0x16642c sub r3, r12, #1
 *   @0x166430 ldr r2, [r0, #0x14]
 *   @0x166434 mul r3, r3, r4
 *   @0x166438 add r1, r3, r4
 *   @0x16643c cmp r1, #0
 *   @0x166440 ldr r5, [r2, r3, lsl #2]
 *   @0x166444 movgt r3, #0
 *   @0x166448 bic r5, r5, #-16777216
 *   @0x16644c ble 0x166478 <_ZN9CBitmap3216RemoveBackgroundEv+0x74>
 *   @0x166450 ldr r1, [r2], #4
 *   @0x166454 add r3, r3, #1
 *   @0x166458 bic r1, r1, #-16777216
 *   @0x16645c cmp r5, r1
 *   @0x166460 streq r5, [r2, #-0x4]
 *   @0x166464 ldreq r12, [r0, #0xc]
 *   @0x166468 ldreq r4, [r0, #0x8]
 *   @0x16646c mul r1, r4, r12
 *   @0x166470 cmp r3, r1
 *   @0x166474 blt 0x166450 <_ZN9CBitmap3216RemoveBackgroundEv+0x4c>
 *   @0x166478 pop {r4, r5}
 *   @0x16647c b 0x166304 <_ZN9CBitmap3215ImproveBoundaryEv>
 *   @0x166480 pop {r4, r5}
 *   @0x166484 bx lr
 *
 * ══ §90/230 GR_Draw_Circle_Ext(float, float, float, unsigned int, unsigned int, bool)  0x16b1f4  size 132  33 条（0x16b1f4..0x16b278）
 * @func 0x16b1f4 0x16b278  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Color_To_D3DColor(unsigned int, unsigned int)×2 / _Draw_Ellipse(float, float, float, float, unsigned int, unsigned int, bool)
 * 字段偏移 top8: 0x6c×1 / 0x38×1 / 0x3c×1 / 0x8×1 / 0x4×1
 * VFP 指令 13 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16b1f4 push {r4, r5, r6, r7, lr}
 *   @0x16b1f8 vpush {d8, d9}
 *   @0x16b1fc vmov s15, r2
 *   @0x16b200 ldr r4, [pc, #0x6c]
 *   @0x16b204 sub sp, sp, #20
 *   @0x16b208 vmov s13, r1
 *   @0x16b20c ldr r4, [pc, r4]
 *   @0x16b210 vmov s14, r0
 *   @0x16b214 mov r0, r3
 *   @0x16b218 vsub.f32 s19, s13, s15
 *   @0x16b21c ldr r1, [r4]
 *   @0x16b220 ldr r5, [sp, #0x38]
 *   @0x16b224 ldrb r6, [sp, #0x3c]
 *   @0x16b228 vadd.f32 s18, s13, s15
 *   @0x16b22c vsub.f32 s16, s14, s15
 *   @0x16b230 vadd.f32 s17, s14, s15
 *   @0x16b234 bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj>
 *   @0x16b238 ldr r1, [r4]
 *   @0x16b23c mov r7, r0
 *   @0x16b240 mov r0, r5
 *   @0x16b244 bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj>
 *   @0x16b248 str r7, [sp]
 *   @0x16b24c str r6, [sp, #0x8]
 *   @0x16b250 vmov r1, s19
 *   @0x16b254 vmov r3, s18
 *   @0x16b258 vmov r2, s17
 *   @0x16b25c str r0, [sp, #0x4]
 *   @0x16b260 vmov r0, s16
 *   @0x16b264 bl 0x16af3c <_Z13_Draw_Ellipseffffjjb>
 *   @0x16b268 add sp, sp, #20
 *   @0x16b26c vpop {d8, d9}
 *   @0x16b270 pop {r4, r5, r6, r7, pc}
 *   @0x16b274 .word 0x00282af4
 *
 * ══ §91/230 GraphicsRecorder::DeleteHWBuffers()  0x1857d8  size 132  33 条（0x1857d8..0x18585c）
 * @func 0x1857d8 0x18585c  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / GraphicsRecorder::DeleteHWBuffers()+0x60
 * 字段偏移 top8: 0x18×3 / 0x74×1 / 0x4×1 / 0x44×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1857d8 ldr r3, [pc, #0x74]
 *   @0x1857dc push {r4, r5, r6, r7, r8, lr}
 *   @0x1857e0 ldr r3, [pc, r3]
 *   @0x1857e4 mov r8, r0
 *   @0x1857e8 ldrb r3, [r3]
 *   @0x1857ec cmp r3, #0
 *   @0x1857f0 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x1857f4 ldr r5, [r0, #0x18]
 *   @0x1857f8 cmp r5, #0
 *   @0x1857fc popeq {r4, r5, r6, r7, r8, pc}
 *   @0x185800 ldr r7, [r5, #0x4]
 *   @0x185804 cmp r7, #0
 *   @0x185808 ble 0x185838 <_ZN16GraphicsRecorder15DeleteHWBuffersEv+0x60>
 *   @0x18580c ldr r6, [pc, #0x44]
 *   @0x185810 mov r4, #0
 *   @0x185814 ldr r6, [pc, r6]
 *   @0x185818 ldr r1, [r5]
 *   @0x18581c mov r0, #1
 *   @0x185820 ldr r3, [r6]
 *   @0x185824 add r1, r1, r4, lsl #3
 *   @0x185828 add r4, r4, r0
 *   @0x18582c blx r3
 *   @0x185830 cmp r4, r7
 *   @0x185834 bne 0x185818 <_ZN16GraphicsRecorder15DeleteHWBuffersEv+0x40>
 *   @0x185838 ldr r0, [r5]
 *   @0x18583c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x185840 ldr r0, [r8, #0x18]
 *   @0x185844 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x185848 mov r3, #0
 *   @0x18584c str r3, [r8, #0x18]
 *   @0x185850 pop {r4, r5, r6, r7, r8, pc}
 *   @0x185854 eoreq r10, r6, r0, asr r12
 *   @0x185858 eoreq r7, r6, r0, ror pc
 *
 * ══ §92/230 anon_18b53c  0x18b53c  size 132  33 条（0x18b53c..0x18b5c0）
 * @func 0x18b53c 0x18b5c0  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FREE_RValue__Pre(RValue*) / YYSetString(RValue*, char const*) / F_DsMapFindValue(RValue&, CInstance*, CInstance*, int, RValue*)
 * 字段偏移 top8: 0xc×3 / 0x8×1 / 0x1c×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18b53c push {r4, r5, r6, lr}
 *   @0x18b540 sub r3, r3, #1
 *   @0x18b544 bic r3, r3, #-16777216
 *   @0x18b548 sub sp, sp, #48
 *   @0x18b54c bic r3, r3, #3
 *   @0x18b550 mov r4, r0
 *   @0x18b554 cmp r3, #0
 *   @0x18b558 mov r5, r2
 *   @0x18b55c bne 0x18b56c <_ZN11CIAPProduct11PopulateMapEi+0x224>
 *   @0x18b560 str r1, [sp, #0xc]
 *   @0x18b564 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x18b568 ldr r1, [sp, #0xc]
 *   @0x18b56c vmov s13, r1
 *   @0x18b570 mov r3, #5
 *   @0x18b574 str r3, [r4, #0xc]
 *   @0x18b578 add r6, sp, #48
 *   @0x18b57c vcvt.f64.s32 d7, s13
 *   @0x18b580 mov r1, r5
 *   @0x18b584 add r0, sp, #32
 *   @0x18b588 mov r5, #0
 *   @0x18b58c str r5, [r4, #0x8]
 *   @0x18b590 str r5, [r4]
 *   @0x18b594 str r5, [sp, #0x1c]
 *   @0x18b598 vmov r2, r3, d7
 *   @0x18b59c strd r2, r3, [r6, #-32]!
 *   @0x18b5a0 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x18b5a4 mov r1, r5
 *   @0x18b5a8 str r6, [sp]
 *   @0x18b5ac mov r0, r4
 *   @0x18b5b0 mov r2, r5
 *   @0x18b5b4 mov r3, #2
 *   @0x18b5b8 bl 0x106bcc <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_>
 *   @0x18b5bc add sp, sp, #48
 *
 * ══ §93/230 FINALIZE_Object_Lists()  0x19e884  size 132  33 条（0x19e884..0x19e908）
 * @func 0x19e884 0x19e908  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / FINALIZE_Object_Lists()+0x40
 * 字段偏移 top8: 0x4×4 / 0x6c×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19e884 push {r4, r5, r6, r7, r8, lr}
 *   @0x19e888 mov r7, #0
 *   @0x19e88c ldr r6, [pc, #0x6c]
 *   @0x19e890 ldr r6, [pc, r6]
 *   @0x19e894 add r8, r6, #30720
 *   @0x19e898 mov r4, #0
 *   @0x19e89c add r5, r6, r4
 *   @0x19e8a0 ldr r0, [r5, #0x4]
 *   @0x19e8a4 cmp r0, #0
 *   @0x19e8a8 beq 0x19e8c4 <_Z21FINALIZE_Object_Listsv+0x40>
 *   @0x19e8ac ldr r3, [r6, r4]
 *   @0x19e8b0 cmp r3, #0
 *   @0x19e8b4 ble 0x19e8c4 <_Z21FINALIZE_Object_Listsv+0x40>
 *   @0x19e8b8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x19e8bc str r7, [r5, #0x4]
 *   @0x19e8c0 str r7, [r6, r4]
 *   @0x19e8c4 add r4, r4, #8
 *   @0x19e8c8 cmp r4, #2048
 *   @0x19e8cc bne 0x19e89c <_Z21FINALIZE_Object_Listsv+0x18>
 *   @0x19e8d0 add r6, r6, #2048
 *   @0x19e8d4 cmp r6, r8
 *   @0x19e8d8 bne 0x19e898 <_Z21FINALIZE_Object_Listsv+0x14>
 *   @0x19e8dc ldr r4, [pc, #0x20]
 *   @0x19e8e0 ldr r4, [pc, r4]
 *   @0x19e8e4 ldr r0, [r4, #0x4]
 *   @0x19e8e8 cmp r0, #0
 *   @0x19e8ec popeq {r4, r5, r6, r7, r8, pc}
 *   @0x19e8f0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x19e8f4 mov r3, #0
 *   @0x19e8f8 str r3, [r4, #0x4]
 *   @0x19e8fc pop {r4, r5, r6, r7, r8, pc}
 *   @0x19e900 eoreq r1, r5, r12, ror r2
 *   @0x19e904 eoreq r1, r5, r0, lsl #28
 *
 * ══ §94/230 ParticleType_DestroyAll()  0x1a2d90  size 132  33 条（0x1a2d90..0x1a2e14）
 * @func 0x1a2d90 0x1a2e14  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / ParticleType_DestroyAll()+0x50
 * 字段偏移 top8: 0x4×4 / 0x2×2 / 0x20×2 / 0x6c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a2d90 push {r4, r5, r6, lr}
 *   @0x1a2d94 ldr r5, [pc, #0x6c]
 *   @0x1a2d98 ldr r5, [pc, r5]
 *   @0x1a2d9c ldr r0, [r5, #0x4]
 *   @0x1a2da0 cmp r0, #0
 *   @0x1a2da4 popeq {r4, r5, r6, pc}
 *   @0x1a2da8 ldr r3, [r5]
 *   @0x1a2dac cmp r3, #0
 *   @0x1a2db0 ble 0x1a2de0 <_Z23ParticleType_DestroyAllv+0x50>
 *   @0x1a2db4 mov r4, #0
 *   @0x1a2db8 mov r6, r4
 *   @0x1a2dbc ldr r0, [r0, r4, lsl #2]
 *   @0x1a2dc0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1a2dc4 ldr r2, [r5, #0x4]
 *   @0x1a2dc8 ldr r3, [r5]
 *   @0x1a2dcc str r6, [r2, r4, lsl #2]
 *   @0x1a2dd0 add r4, r4, #1
 *   @0x1a2dd4 cmp r3, r4
 *   @0x1a2dd8 ldr r0, [r5, #0x4]
 *   @0x1a2ddc bgt 0x1a2dbc <_Z23ParticleType_DestroyAllv+0x2c>
 *   @0x1a2de0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1a2de4 ldr r1, [pc, #0x20]
 *   @0x1a2de8 ldr r3, [pc, #0x20]
 *   @0x1a2dec mov r2, #0
 *   @0x1a2df0 ldr r1, [pc, r1]
 *   @0x1a2df4 str r2, [r5, #0x4]
 *   @0x1a2df8 ldr r3, [pc, r3]
 *   @0x1a2dfc str r2, [r1]
 *   @0x1a2e00 strb r2, [r3]
 *   @0x1a2e04 pop {r4, r5, r6, pc}
 *   @0x1a2e08 eoreq sp, r4, r4, lsl r10
 *   @0x1a2e0c eoreq sp, r4, r0, asr #19
 *   @0x1a2e10 eoreq sp, r4, r8, lsr #19
 *
 * ══ §95/230 Path_Name(int)  0x1a8050  size 132  33 条（0x1a8050..0x1a80d4）
 * @func 0x1a8050 0x1a80e4  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Path_Name(int)+0x54
 * 字段偏移 top8: 0x2×2 / 0x5c×1 / 0x4c×1 / 0x4×1 / 0x38×1 / 0x28×1 / 0x20×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a8050 cmp r0, #0
 *   @0x1a8054 blt 0x1a80a4 <_Z9Path_Namei+0x54>
 *   @0x1a8058 ldr r3, [pc, #0x5c]
 *   @0x1a805c ldr r3, [pc, r3]
 *   @0x1a8060 ldr r3, [r3]
 *   @0x1a8064 cmp r0, r3
 *   @0x1a8068 bge 0x1a8098 <_Z9Path_Namei+0x48>
 *   @0x1a806c ldr r3, [pc, #0x4c]
 *   @0x1a8070 add r3, pc, r3
 *   @0x1a8074 ldr r3, [r3, #0x4]
 *   @0x1a8078 ldr r3, [r3, r0, lsl #2]
 *   @0x1a807c cmp r3, #0
 *   @0x1a8080 beq 0x1a80b0 <_Z9Path_Namei+0x60>
 *   @0x1a8084 ldr r3, [pc, #0x38]
 *   @0x1a8088 ldr r3, [pc, r3]
 *   @0x1a808c ldr r3, [r3]
 *   @0x1a8090 ldr r0, [r3, r0, lsl #2]
 *   @0x1a8094 bx lr
 *   @0x1a8098 ldr r0, [pc, #0x28]
 *   @0x1a809c add r0, pc, r0
 *   @0x1a80a0 bx lr
 *   @0x1a80a4 ldr r0, [pc, #0x20]
 *   @0x1a80a8 add r0, pc, r0
 *   @0x1a80ac bx lr
 *   @0x1a80b0 ldr r0, [pc, #0x18]
 *   @0x1a80b4 add r0, pc, r0
 *   @0x1a80b8 bx lr
 *   @0x1a80bc eoreq r8, r4, r0, ror r7
 *   @0x1a80c0 ldrhteq r10, [r9], -r8
 *   @0x1a80c4 eoreq r8, r4, r8, asr #14
 *   @0x1a80c8 andseq r8, r8, r4, lsr #20
 *   @0x1a80cc andseq r8, r8, r8, lsl r10
 *   @0x1a80d0 andseq r8, r8, r12, lsl #20
 *
 * ══ §96/230 OverwriteGameINI(IniFile*, IniFile*)  0x1dee84  size 132  33 条（0x1dee84..0x1def08）
 * @func 0x1dee84 0x1def08  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: OverwriteGameINIKey(IniFile*, IniFile*, char const*, char const*)×3
 * 字段偏移 top8: 0x60×1 / 0x5c×1 / 0x4c×1 / 0x38×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dee84 push {r4, r5, r6, lr}
 *   @0x1dee88 mov r6, r0
 *   @0x1dee8c ldr r4, [pc, #0x60]
 *   @0x1dee90 mov r5, r1
 *   @0x1dee94 ldr r3, [pc, #0x5c]
 *   @0x1dee98 add r4, pc, r4
 *   @0x1dee9c add r3, pc, r3
 *   @0x1deea0 mov r2, r4
 *   @0x1deea4 bl 0x1dee44 <_Z19OverwriteGameINIKeyP7IniFileS0_PKcS2_>
 *   @0x1deea8 ldr r3, [pc, #0x4c]
 *   @0x1deeac mov r0, r6
 *   @0x1deeb0 mov r1, r5
 *   @0x1deeb4 mov r2, r4
 *   @0x1deeb8 add r3, pc, r3
 *   @0x1deebc bl 0x1dee44 <_Z19OverwriteGameINIKeyP7IniFileS0_PKcS2_>
 *   @0x1deec0 ldr r3, [pc, #0x38]
 *   @0x1deec4 mov r0, r6
 *   @0x1deec8 mov r1, r5
 *   @0x1deecc mov r2, r4
 *   @0x1deed0 add r3, pc, r3
 *   @0x1deed4 bl 0x1dee44 <_Z19OverwriteGameINIKeyP7IniFileS0_PKcS2_>
 *   @0x1deed8 ldr r3, [pc, #0x24]
 *   @0x1deedc mov r0, r6
 *   @0x1deee0 mov r1, r5
 *   @0x1deee4 mov r2, r4
 *   @0x1deee8 add r3, pc, r3
 *   @0x1deeec pop {r4, r5, r6, lr}
 *   @0x1deef0 b 0x1dee44 <_Z19OverwriteGameINIKeyP7IniFileS0_PKcS2_>
 *   @0x1deef4 andseq r2, r7, r12, asr r9
 *   @0x1deef8 andseq r2, r7, r0, asr #19
 *   @0x1deefc ldrheq r2, [r7], -r4
 *   @0x1def00 ldrheq r2, [r7], -r4
 *   @0x1def04 andseq r2, r7, r12, lsr #19
 *
 * ══ §97/230 CVariableList::Find(char const*)  0x1f5218  size 132  33 条（0x1f5218..0x1f529c）
 * @func 0x1f5218 0x1f52ac  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CalcCRC_string(char const*) / 0xb6574
 * 字段偏移 top8: 0x4×1 / 0x28×1 / 0x14×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f5218 push {r4, r5, r6, lr}
 *   @0x1f521c mov r4, r0
 *   @0x1f5220 mov r0, r1
 *   @0x1f5224 mov r6, r1
 *   @0x1f5228 bl 0x27dfa8 <_Z14CalcCRC_stringPKc>
 *   @0x1f522c and r3, r0, #3
 *   @0x1f5230 mov r5, r0
 *   @0x1f5234 add r4, r4, r3, lsl #2
 *   @0x1f5238 ldr r4, [r4, #0x4]
 *   @0x1f523c cmp r4, #0
 *   @0x1f5240 bne 0x1f5254 <_ZN13CVariableList4FindEPKc+0x3c>
 *   @0x1f5244 b 0x1f5294 <_ZN13CVariableList4FindEPKc+0x7c>
 *   @0x1f5248 ldr r4, [r4]
 *   @0x1f524c cmp r4, #0
 *   @0x1f5250 beq 0x1f5294 <_ZN13CVariableList4FindEPKc+0x7c>
 *   @0x1f5254 ldr r3, [r4, #0x28]
 *   @0x1f5258 cmp r3, r5
 *   @0x1f525c bne 0x1f5248 <_ZN13CVariableList4FindEPKc+0x30>
 *   @0x1f5260 ldr r3, [r4, #0x14]
 *   @0x1f5264 cmp r3, #1
 *   @0x1f5268 bne 0x1f5248 <_ZN13CVariableList4FindEPKc+0x30>
 *   @0x1f526c ldr r3, [r4, #0x8]
 *   @0x1f5270 mov r1, r6
 *   @0x1f5274 cmp r3, #0
 *   @0x1f5278 beq 0x1f5248 <_ZN13CVariableList4FindEPKc+0x30>
 *   @0x1f527c ldr r0, [r3]
 *   @0x1f5280 cmp r0, #0
 *   @0x1f5284 beq 0x1f5248 <_ZN13CVariableList4FindEPKc+0x30>
 *   @0x1f5288 bl 0xb6574 <strcmp@plt>
 *   @0x1f528c cmp r0, #0
 *   @0x1f5290 bne 0x1f5248 <_ZN13CVariableList4FindEPKc+0x30>
 *   @0x1f5294 mov r0, r4
 *   @0x1f5298 pop {r4, r5, r6, pc}
 *
 * ══ §98/230 GV_PhysicsCollisionPositionX(CInstance*, int, RValue*)  0x1fabc4  size 132  33 条（0x1fabc4..0x1fac48）
 * @func 0x1fabc4 0x1fac58  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsWorld::GetCurrentContactPosition(CInstance*, int, float&, float&)
 * 字段偏移 top8: 0x78×1 / 0xb4×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fabc4 ldr r3, [pc, #0x78]
 *   @0x1fabc8 mov r12, r1
 *   @0x1fabcc push {r4, r5, r6, lr}
 *   @0x1fabd0 ldr r3, [pc, r3]
 *   @0x1fabd4 mov r4, r0
 *   @0x1fabd8 sub sp, sp, #16
 *   @0x1fabdc ldr r3, [r3]
 *   @0x1fabe0 mov r6, r2
 *   @0x1fabe4 ldr r0, [r3, #0xb4]
 *   @0x1fabe8 cmp r0, #0
 *   @0x1fabec beq 0x1fac10 <_Z28GV_PhysicsCollisionPositionXP9CInstanceiP6RValue+0x4c>
 *   @0x1fabf0 mov r2, r12
 *   @0x1fabf4 mov r1, r4
 *   @0x1fabf8 add r12, sp, #12
 *   @0x1fabfc add r3, sp, #8
 *   @0x1fac00 str r12, [sp]
 *   @0x1fac04 bl 0x238ce4 <_ZN13CPhysicsWorld25GetCurrentContactPositionEP9CInstanceiRfS2_>
 *   @0x1fac08 cmp r0, #0
 *   @0x1fac0c bne 0x1fac18 <_Z28GV_PhysicsCollisionPositionXP9CInstanceiP6RValue+0x54>
 *   @0x1fac10 add sp, sp, #16
 *   @0x1fac14 pop {r4, r5, r6, pc}
 *   @0x1fac18 vldr s15, [sp, #8]
 *   @0x1fac1c vcvt.f64.f32 d6, s15
 *   @0x1fac20 mov r3, #0
 *   @0x1fac24 mov r0, #1
 *   @0x1fac28 str r3, [r6, #0xc]
 *   @0x1fac2c vmov r4, r5, d6
 *   @0x1fac30 vmov r2, s12
 *   @0x1fac34 mov r3, r5
 *   @0x1fac38 stm r6, {r2, r3}
 *   @0x1fac3c add sp, sp, #16
 *   @0x1fac40 pop {r4, r5, r6, pc}
 *   @0x1fac44 andseq r2, pc, r8, asr sp
 *
 * ══ §99/230 GV_PhysicsCollisionPositionY(CInstance*, int, RValue*)  0x1fac48  size 132  33 条（0x1fac48..0x1faccc）
 * @func 0x1fac48 0x1facdc  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsWorld::GetCurrentContactPosition(CInstance*, int, float&, float&)
 * 字段偏移 top8: 0x78×1 / 0xb4×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fac48 ldr r3, [pc, #0x78]
 *   @0x1fac4c mov r12, r1
 *   @0x1fac50 push {r4, r5, r6, lr}
 *   @0x1fac54 ldr r3, [pc, r3]
 *   @0x1fac58 mov r4, r0
 *   @0x1fac5c sub sp, sp, #16
 *   @0x1fac60 ldr r3, [r3]
 *   @0x1fac64 mov r6, r2
 *   @0x1fac68 ldr r0, [r3, #0xb4]
 *   @0x1fac6c cmp r0, #0
 *   @0x1fac70 beq 0x1fac94 <_Z28GV_PhysicsCollisionPositionYP9CInstanceiP6RValue+0x4c>
 *   @0x1fac74 mov r2, r12
 *   @0x1fac78 mov r1, r4
 *   @0x1fac7c add r12, sp, #12
 *   @0x1fac80 add r3, sp, #8
 *   @0x1fac84 str r12, [sp]
 *   @0x1fac88 bl 0x238ce4 <_ZN13CPhysicsWorld25GetCurrentContactPositionEP9CInstanceiRfS2_>
 *   @0x1fac8c cmp r0, #0
 *   @0x1fac90 bne 0x1fac9c <_Z28GV_PhysicsCollisionPositionYP9CInstanceiP6RValue+0x54>
 *   @0x1fac94 add sp, sp, #16
 *   @0x1fac98 pop {r4, r5, r6, pc}
 *   @0x1fac9c vldr s15, [sp, #12]
 *   @0x1faca0 vcvt.f64.f32 d6, s15
 *   @0x1faca4 mov r3, #0
 *   @0x1faca8 mov r0, #1
 *   @0x1facac str r3, [r6, #0xc]
 *   @0x1facb0 vmov r4, r5, d6
 *   @0x1facb4 vmov r2, s12
 *   @0x1facb8 mov r3, r5
 *   @0x1facbc stm r6, {r2, r3}
 *   @0x1facc0 add sp, sp, #16
 *   @0x1facc4 pop {r4, r5, r6, pc}
 *   @0x1facc8 ldrsbeq r2, [pc], -r4
 *
 * ══ §100/230 GV_PhysicsCollisionNormalX(CInstance*, int, RValue*)  0x1faccc  size 132  33 条（0x1faccc..0x1fad50）
 * @func 0x1faccc 0x1fad60  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsWorld::GetCurrentContactNormal(CInstance*, int, float&, float&)
 * 字段偏移 top8: 0x78×1 / 0xb4×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1faccc ldr r3, [pc, #0x78]
 *   @0x1facd0 mov r12, r1
 *   @0x1facd4 push {r4, r5, r6, lr}
 *   @0x1facd8 ldr r3, [pc, r3]
 *   @0x1facdc mov r4, r0
 *   @0x1face0 sub sp, sp, #16
 *   @0x1face4 ldr r3, [r3]
 *   @0x1face8 mov r6, r2
 *   @0x1facec ldr r0, [r3, #0xb4]
 *   @0x1facf0 cmp r0, #0
 *   @0x1facf4 beq 0x1fad18 <_Z26GV_PhysicsCollisionNormalXP9CInstanceiP6RValue+0x4c>
 *   @0x1facf8 mov r2, r12
 *   @0x1facfc mov r1, r4
 *   @0x1fad00 add r12, sp, #12
 *   @0x1fad04 add r3, sp, #8
 *   @0x1fad08 str r12, [sp]
 *   @0x1fad0c bl 0x238d9c <_ZN13CPhysicsWorld23GetCurrentContactNormalEP9CInstanceiRfS2_>
 *   @0x1fad10 cmp r0, #0
 *   @0x1fad14 bne 0x1fad20 <_Z26GV_PhysicsCollisionNormalXP9CInstanceiP6RValue+0x54>
 *   @0x1fad18 add sp, sp, #16
 *   @0x1fad1c pop {r4, r5, r6, pc}
 *   @0x1fad20 vldr s15, [sp, #8]
 *   @0x1fad24 vcvt.f64.f32 d6, s15
 *   @0x1fad28 mov r3, #0
 *   @0x1fad2c mov r0, #1
 *   @0x1fad30 str r3, [r6, #0xc]
 *   @0x1fad34 vmov r4, r5, d6
 *   @0x1fad38 vmov r2, s12
 *   @0x1fad3c mov r3, r5
 *   @0x1fad40 stm r6, {r2, r3}
 *   @0x1fad44 add sp, sp, #16
 *   @0x1fad48 pop {r4, r5, r6, pc}
 *   @0x1fad4c andseq r2, pc, r0, asr r12
 *
 * ══ §101/230 GV_PhysicsCollisionNormalY(CInstance*, int, RValue*)  0x1fad50  size 132  33 条（0x1fad50..0x1fadd4）
 * @func 0x1fad50 0x1fade4  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsWorld::GetCurrentContactNormal(CInstance*, int, float&, float&)
 * 字段偏移 top8: 0x78×1 / 0xb4×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fad50 ldr r3, [pc, #0x78]
 *   @0x1fad54 mov r12, r1
 *   @0x1fad58 push {r4, r5, r6, lr}
 *   @0x1fad5c ldr r3, [pc, r3]
 *   @0x1fad60 mov r4, r0
 *   @0x1fad64 sub sp, sp, #16
 *   @0x1fad68 ldr r3, [r3]
 *   @0x1fad6c mov r6, r2
 *   @0x1fad70 ldr r0, [r3, #0xb4]
 *   @0x1fad74 cmp r0, #0
 *   @0x1fad78 beq 0x1fad9c <_Z26GV_PhysicsCollisionNormalYP9CInstanceiP6RValue+0x4c>
 *   @0x1fad7c mov r2, r12
 *   @0x1fad80 mov r1, r4
 *   @0x1fad84 add r12, sp, #12
 *   @0x1fad88 add r3, sp, #8
 *   @0x1fad8c str r12, [sp]
 *   @0x1fad90 bl 0x238d9c <_ZN13CPhysicsWorld23GetCurrentContactNormalEP9CInstanceiRfS2_>
 *   @0x1fad94 cmp r0, #0
 *   @0x1fad98 bne 0x1fada4 <_Z26GV_PhysicsCollisionNormalYP9CInstanceiP6RValue+0x54>
 *   @0x1fad9c add sp, sp, #16
 *   @0x1fada0 pop {r4, r5, r6, pc}
 *   @0x1fada4 vldr s15, [sp, #12]
 *   @0x1fada8 vcvt.f64.f32 d6, s15
 *   @0x1fadac mov r3, #0
 *   @0x1fadb0 mov r0, #1
 *   @0x1fadb4 str r3, [r6, #0xc]
 *   @0x1fadb8 vmov r4, r5, d6
 *   @0x1fadbc vmov r2, s12
 *   @0x1fadc0 mov r3, r5
 *   @0x1fadc4 stm r6, {r2, r3}
 *   @0x1fadc8 add sp, sp, #16
 *   @0x1fadcc pop {r4, r5, r6, pc}
 *   @0x1fadd0 andseq r2, pc, r12, asr #23
 *
 * ══ §102/230 GV_Layer(CInstance*, int, RValue*)  0x1fadd4  size 132  33 条（0x1fadd4..0x1fae58）
 * @func 0x1fadd4 0x1fae58  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetLayerFromID(CRoom*, int)
 * 字段偏移 top8: 0x4×1 / 0x174×1 / 0xc×1 / 0x44×1 / 0x170×1 / 0x19×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fadd4 push {r4, lr}
 *   @0x1fadd8 mov r4, r2
 *   @0x1faddc mov r2, #0
 *   @0x1fade0 mov r3, r2
 *   @0x1fade4 movt r2, #0xbff0
 *   @0x1fade8 str r3, [r4]
 *   @0x1fadec str r2, [r4, #0x4]
 *   @0x1fadf0 ldrb r2, [r0, #0x174]
 *   @0x1fadf4 str r3, [r4, #0xc]
 *   @0x1fadf8 cmp r2, r3
 *   @0x1fadfc bne 0x1fae08 <_Z8GV_LayerP9CInstanceiP6RValue+0x34>
 *   @0x1fae00 mov r0, #1
 *   @0x1fae04 pop {r4, pc}
 *   @0x1fae08 ldr r3, [pc, #0x44]
 *   @0x1fae0c ldr r1, [r0, #0x170]
 *   @0x1fae10 ldr r3, [pc, r3]
 *   @0x1fae14 ldr r0, [r3]
 *   @0x1fae18 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1fae1c cmp r0, #0
 *   @0x1fae20 beq 0x1fae00 <_Z8GV_LayerP9CInstanceiP6RValue+0x2c>
 *   @0x1fae24 ldrb r3, [r0, #0x19]
 *   @0x1fae28 cmp r3, #0
 *   @0x1fae2c bne 0x1fae00 <_Z8GV_LayerP9CInstanceiP6RValue+0x2c>
 *   @0x1fae30 ldr r0, [r0]
 *   @0x1fae34 vmov s15, r0
 *   @0x1fae38 vcvt.f64.s32 d7, s15
 *   @0x1fae3c vmov r0, r1, d7
 *   @0x1fae40 mov r0, #1
 *   @0x1fae44 vmov r2, s14
 *   @0x1fae48 mov r3, r1
 *   @0x1fae4c stm r4, {r2, r3}
 *   @0x1fae50 pop {r4, pc}
 *   @0x1fae54 andseq r2, pc, r8, lsl r11
 *
 * ══ §103/230 SV_ShowScore(CInstance*, int, RValue*)  0x1fb4e0  size 132  33 条（0x1fb4e0..0x1fb564）
 * @func 0x1fb4e0 0x1fb564  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8 / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x48×1 / 0x44×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fb4e0 push {r3, lr}
 *   @0x1fb4e4 ldr r3, [r2, #0xc]
 *   @0x1fb4e8 bic r3, r3, #-16777216
 *   @0x1fb4ec cmp r3, #0
 *   @0x1fb4f0 bne 0x1fb548 <_Z12SV_ShowScoreP9CInstanceiP6RValue+0x68>
 *   @0x1fb4f4 ldr r12, [r2]
 *   @0x1fb4f8 ldr r3, [r2, #0x4]
 *   @0x1fb4fc mov r1, r3
 *   @0x1fb500 mov r0, r12
 *   @0x1fb504 bl 0xb66e8 <lrint@plt>
 *   @0x1fb508 vmov.f64 d7, #5.000000e-01
 *   @0x1fb50c ldr r3, [pc, #0x48]
 *   @0x1fb510 mov r1, #1
 *   @0x1fb514 ldr r2, [pc, #0x44]
 *   @0x1fb518 ldr r3, [pc, r3]
 *   @0x1fb51c ldr r2, [pc, r2]
 *   @0x1fb520 strb r1, [r2]
 *   @0x1fb524 vmov s11, r0
 *   @0x1fb528 mov r0, r1
 *   @0x1fb52c vcvt.f64.s32 d6, s11
 *   @0x1fb530 vcmpe.f64 d6, d7
 *   @0x1fb534 vmrs APSR_nzcv, fpscr
 *   @0x1fb538 movle r2, #0
 *   @0x1fb53c movgt r2, #1
 *   @0x1fb540 strb r2, [r3]
 *   @0x1fb544 pop {r3, pc}
 *   @0x1fb548 mov r0, r2
 *   @0x1fb54c bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fb550 mov r12, r0
 *   @0x1fb554 mov r3, r1
 *   @0x1fb558 b 0x1fb4fc <_Z12SV_ShowScoreP9CInstanceiP6RValue+0x1c>
 *   @0x1fb55c ldrsbeq r4, [pc], -r4
 *   @0x1fb560 andseq r4, pc, r12, asr #1
 *
 * ══ §104/230 SV_ViewVisible(CInstance*, int, RValue*)  0x1fc1f4  size 132  33 条（0x1fc1f4..0x1fc278）
 * @func 0x1fc1f4 0x1fc278  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8 / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0x78×1 / 0xc×1 / 0x2×1 / 0x4×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fc1f4 ldr r3, [pc, #0x78]
 *   @0x1fc1f8 cmp r1, #7
 *   @0x1fc1fc ldr r0, [r2, #0xc]
 *   @0x1fc200 ldr r3, [pc, r3]
 *   @0x1fc204 movhi r1, #0
 *   @0x1fc208 bic r0, r0, #-16777216
 *   @0x1fc20c add r1, r1, #18
 *   @0x1fc210 ldr r3, [r3]
 *   @0x1fc214 cmp r0, #0
 *   @0x1fc218 push {r4, lr}
 *   @0x1fc21c ldr r4, [r3, r1, lsl #2]
 *   @0x1fc220 bne 0x1fc260 <_Z14SV_ViewVisibleP9CInstanceiP6RValue+0x6c>
 *   @0x1fc224 ldr r12, [r2]
 *   @0x1fc228 ldr r3, [r2, #0x4]
 *   @0x1fc22c mov r1, r3
 *   @0x1fc230 mov r0, r12
 *   @0x1fc234 bl 0xb66e8 <lrint@plt>
 *   @0x1fc238 vmov.f64 d7, #5.000000e-01
 *   @0x1fc23c vmov s11, r0
 *   @0x1fc240 mov r0, #1
 *   @0x1fc244 vcvt.f64.s32 d6, s11
 *   @0x1fc248 vcmpe.f64 d6, d7
 *   @0x1fc24c vmrs APSR_nzcv, fpscr
 *   @0x1fc250 movle r3, #0
 *   @0x1fc254 movgt r3, #1
 *   @0x1fc258 strb r3, [r4]
 *   @0x1fc25c pop {r4, pc}
 *   @0x1fc260 mov r0, r2
 *   @0x1fc264 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fc268 mov r12, r0
 *   @0x1fc26c mov r3, r1
 *   @0x1fc270 b 0x1fc22c <_Z14SV_ViewVisibleP9CInstanceiP6RValue+0x38>
 *   @0x1fc274 andseq r1, pc, r8, lsr #14
 *
 * ══ §105/230 SV_BackgroundVisible(CInstance*, int, RValue*)  0x1fc8a8  size 132  33 条（0x1fc8a8..0x1fc92c）
 * @func 0x1fc8a8 0x1fc93c  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8 / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0x78×1 / 0xc×1 / 0x24×1 / 0x4×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fc8a8 ldr r3, [pc, #0x78]
 *   @0x1fc8ac cmp r1, #7
 *   @0x1fc8b0 ldr r0, [r2, #0xc]
 *   @0x1fc8b4 ldr r3, [pc, r3]
 *   @0x1fc8b8 movhi r1, #0
 *   @0x1fc8bc bic r0, r0, #-16777216
 *   @0x1fc8c0 ldr r3, [r3]
 *   @0x1fc8c4 cmp r0, #0
 *   @0x1fc8c8 push {r4, lr}
 *   @0x1fc8cc add r1, r3, r1, lsl #2
 *   @0x1fc8d0 ldr r4, [r1, #0x24]
 *   @0x1fc8d4 bne 0x1fc914 <_Z20SV_BackgroundVisibleP9CInstanceiP6RValue+0x6c>
 *   @0x1fc8d8 ldr r12, [r2]
 *   @0x1fc8dc ldr r3, [r2, #0x4]
 *   @0x1fc8e0 mov r1, r3
 *   @0x1fc8e4 mov r0, r12
 *   @0x1fc8e8 bl 0xb66e8 <lrint@plt>
 *   @0x1fc8ec vmov.f64 d7, #5.000000e-01
 *   @0x1fc8f0 vmov s11, r0
 *   @0x1fc8f4 mov r0, #1
 *   @0x1fc8f8 vcvt.f64.s32 d6, s11
 *   @0x1fc8fc vcmpe.f64 d6, d7
 *   @0x1fc900 vmrs APSR_nzcv, fpscr
 *   @0x1fc904 movle r3, #0
 *   @0x1fc908 movgt r3, #1
 *   @0x1fc90c strb r3, [r4]
 *   @0x1fc910 pop {r4, pc}
 *   @0x1fc914 mov r0, r2
 *   @0x1fc918 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fc91c mov r12, r0
 *   @0x1fc920 mov r3, r1
 *   @0x1fc924 b 0x1fc8e0 <_Z20SV_BackgroundVisibleP9CInstanceiP6RValue+0x38>
 *   @0x1fc928 andseq r1, pc, r4, ror r0
 *
 * ══ §106/230 SV_BackgroundForeground(CInstance*, int, RValue*)  0x1fc92c  size 132  33 条（0x1fc92c..0x1fc9b0）
 * @func 0x1fc92c 0x1fc9b0  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8 / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0x78×1 / 0xc×1 / 0x24×1 / 0x4×1 / 0x1×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fc92c ldr r3, [pc, #0x78]
 *   @0x1fc930 cmp r1, #7
 *   @0x1fc934 ldr r0, [r2, #0xc]
 *   @0x1fc938 ldr r3, [pc, r3]
 *   @0x1fc93c movhi r1, #0
 *   @0x1fc940 bic r0, r0, #-16777216
 *   @0x1fc944 ldr r3, [r3]
 *   @0x1fc948 cmp r0, #0
 *   @0x1fc94c push {r4, lr}
 *   @0x1fc950 add r1, r3, r1, lsl #2
 *   @0x1fc954 ldr r4, [r1, #0x24]
 *   @0x1fc958 bne 0x1fc998 <_Z23SV_BackgroundForegroundP9CInstanceiP6RValue+0x6c>
 *   @0x1fc95c ldr r12, [r2]
 *   @0x1fc960 ldr r3, [r2, #0x4]
 *   @0x1fc964 mov r1, r3
 *   @0x1fc968 mov r0, r12
 *   @0x1fc96c bl 0xb66e8 <lrint@plt>
 *   @0x1fc970 vmov.f64 d7, #5.000000e-01
 *   @0x1fc974 vmov s11, r0
 *   @0x1fc978 mov r0, #1
 *   @0x1fc97c vcvt.f64.s32 d6, s11
 *   @0x1fc980 vcmpe.f64 d6, d7
 *   @0x1fc984 vmrs APSR_nzcv, fpscr
 *   @0x1fc988 movle r3, #0
 *   @0x1fc98c movgt r3, #1
 *   @0x1fc990 strb r3, [r4, #0x1]
 *   @0x1fc994 pop {r4, pc}
 *   @0x1fc998 mov r0, r2
 *   @0x1fc99c bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fc9a0 mov r12, r0
 *   @0x1fc9a4 mov r3, r1
 *   @0x1fc9a8 b 0x1fc964 <_Z23SV_BackgroundForegroundP9CInstanceiP6RValue+0x38>
 *   @0x1fc9ac ldrsheq r0, [pc], -r0
 *
 * ══ §107/230 SV_BackgroundHTiled(CInstance*, int, RValue*)  0x1fcac8  size 132  33 条（0x1fcac8..0x1fcb4c）
 * @func 0x1fcac8 0x1fcb5c  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8 / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0x78×1 / 0xc×1 / 0x24×1 / 0x4×1 / 0x10×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fcac8 ldr r3, [pc, #0x78]
 *   @0x1fcacc cmp r1, #7
 *   @0x1fcad0 ldr r0, [r2, #0xc]
 *   @0x1fcad4 ldr r3, [pc, r3]
 *   @0x1fcad8 movhi r1, #0
 *   @0x1fcadc bic r0, r0, #-16777216
 *   @0x1fcae0 ldr r3, [r3]
 *   @0x1fcae4 cmp r0, #0
 *   @0x1fcae8 push {r4, lr}
 *   @0x1fcaec add r1, r3, r1, lsl #2
 *   @0x1fcaf0 ldr r4, [r1, #0x24]
 *   @0x1fcaf4 bne 0x1fcb34 <_Z19SV_BackgroundHTiledP9CInstanceiP6RValue+0x6c>
 *   @0x1fcaf8 ldr r12, [r2]
 *   @0x1fcafc ldr r3, [r2, #0x4]
 *   @0x1fcb00 mov r1, r3
 *   @0x1fcb04 mov r0, r12
 *   @0x1fcb08 bl 0xb66e8 <lrint@plt>
 *   @0x1fcb0c vmov.f64 d7, #5.000000e-01
 *   @0x1fcb10 vmov s11, r0
 *   @0x1fcb14 mov r0, #1
 *   @0x1fcb18 vcvt.f64.s32 d6, s11
 *   @0x1fcb1c vcmpe.f64 d6, d7
 *   @0x1fcb20 vmrs APSR_nzcv, fpscr
 *   @0x1fcb24 movle r3, #0
 *   @0x1fcb28 movgt r3, #1
 *   @0x1fcb2c strb r3, [r4, #0x10]
 *   @0x1fcb30 pop {r4, pc}
 *   @0x1fcb34 mov r0, r2
 *   @0x1fcb38 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fcb3c mov r12, r0
 *   @0x1fcb40 mov r3, r1
 *   @0x1fcb44 b 0x1fcb00 <_Z19SV_BackgroundHTiledP9CInstanceiP6RValue+0x38>
 *   @0x1fcb48 andseq r0, pc, r4, asr lr
 *
 * ══ §108/230 SV_BackgroundVTiled(CInstance*, int, RValue*)  0x1fcb4c  size 132  33 条（0x1fcb4c..0x1fcbd0）
 * @func 0x1fcb4c 0x1fcbd0  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8 / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0x78×1 / 0xc×1 / 0x24×1 / 0x4×1 / 0x11×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fcb4c ldr r3, [pc, #0x78]
 *   @0x1fcb50 cmp r1, #7
 *   @0x1fcb54 ldr r0, [r2, #0xc]
 *   @0x1fcb58 ldr r3, [pc, r3]
 *   @0x1fcb5c movhi r1, #0
 *   @0x1fcb60 bic r0, r0, #-16777216
 *   @0x1fcb64 ldr r3, [r3]
 *   @0x1fcb68 cmp r0, #0
 *   @0x1fcb6c push {r4, lr}
 *   @0x1fcb70 add r1, r3, r1, lsl #2
 *   @0x1fcb74 ldr r4, [r1, #0x24]
 *   @0x1fcb78 bne 0x1fcbb8 <_Z19SV_BackgroundVTiledP9CInstanceiP6RValue+0x6c>
 *   @0x1fcb7c ldr r12, [r2]
 *   @0x1fcb80 ldr r3, [r2, #0x4]
 *   @0x1fcb84 mov r1, r3
 *   @0x1fcb88 mov r0, r12
 *   @0x1fcb8c bl 0xb66e8 <lrint@plt>
 *   @0x1fcb90 vmov.f64 d7, #5.000000e-01
 *   @0x1fcb94 vmov s11, r0
 *   @0x1fcb98 mov r0, #1
 *   @0x1fcb9c vcvt.f64.s32 d6, s11
 *   @0x1fcba0 vcmpe.f64 d6, d7
 *   @0x1fcba4 vmrs APSR_nzcv, fpscr
 *   @0x1fcba8 movle r3, #0
 *   @0x1fcbac movgt r3, #1
 *   @0x1fcbb0 strb r3, [r4, #0x11]
 *   @0x1fcbb4 pop {r4, pc}
 *   @0x1fcbb8 mov r0, r2
 *   @0x1fcbbc bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fcbc0 mov r12, r0
 *   @0x1fcbc4 mov r3, r1
 *   @0x1fcbc8 b 0x1fcb84 <_Z19SV_BackgroundVTiledP9CInstanceiP6RValue+0x38>
 *   @0x1fcbcc ldrsbeq r0, [pc], -r0
 *
 * ══ §109/230 CheckPhysicsError(CInstance*, bool, bool)  0x1fe500  size 132  33 条（0x1fe500..0x1fe584）
 * @func 0x1fe500 0x1fe584  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYError(char const*, ...)×2
 * 字段偏移 top8: 0x64×1 / 0xb4×1 / 0x84×1 / 0x80×1 / 0x2c×1 / 0x14×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fe500 cmp r2, #0
 *   @0x1fe504 push {r4, lr}
 *   @0x1fe508 beq 0x1fe524 <_Z17CheckPhysicsErrorP9CInstancebb+0x24>
 *   @0x1fe50c ldr r3, [pc, #0x64]
 *   @0x1fe510 ldr r3, [pc, r3]
 *   @0x1fe514 ldr r3, [r3]
 *   @0x1fe518 ldr r4, [r3, #0xb4]
 *   @0x1fe51c cmp r4, #0
 *   @0x1fe520 beq 0x1fe560 <_Z17CheckPhysicsErrorP9CInstancebb+0x60>
 *   @0x1fe524 cmp r1, #0
 *   @0x1fe528 beq 0x1fe538 <_Z17CheckPhysicsErrorP9CInstancebb+0x38>
 *   @0x1fe52c ldr r4, [r0, #0x84]
 *   @0x1fe530 cmp r4, #0
 *   @0x1fe534 beq 0x1fe540 <_Z17CheckPhysicsErrorP9CInstancebb+0x40>
 *   @0x1fe538 mov r0, #1
 *   @0x1fe53c pop {r4, pc}
 *   @0x1fe540 ldr r3, [r0, #0x80]
 *   @0x1fe544 mov r2, #1
 *   @0x1fe548 ldr r0, [pc, #0x2c]
 *   @0x1fe54c ldr r1, [r3, #0x14]
 *   @0x1fe550 add r0, pc, r0
 *   @0x1fe554 bl 0xd547c <_Z7YYErrorPKcz>
 *   @0x1fe558 mov r0, r4
 *   @0x1fe55c pop {r4, pc}
 *   @0x1fe560 ldr r0, [pc, #0x18]
 *   @0x1fe564 mov r1, #1
 *   @0x1fe568 add r0, pc, r0
 *   @0x1fe56c bl 0xd547c <_Z7YYErrorPKcz>
 *   @0x1fe570 mov r0, r4
 *   @0x1fe574 pop {r4, pc}
 *   @0x1fe578 andseq pc, lr, r8, lsl r4
 *   @0x1fe57c andseq r4, r5, r12, ror #24
 *   @0x1fe580 andseq r4, r5, r8, lsl #24
 *
 * ══ §110/230 SV_PhysicsFixedRotation(CInstance*, int, RValue*)  0x1fec54  size 132  33 条（0x1fec54..0x1fecd8）
 * @func 0x1fec54 0x1fece8  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CheckPhysicsError(CInstance*, bool, bool) / b2Body::SetFixedRotation(bool) / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0x84×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fec54 push {r4, r5, r6, r7, r8, lr}
 *   @0x1fec58 mov r1, #1
 *   @0x1fec5c mov r6, r2
 *   @0x1fec60 mov r2, #0
 *   @0x1fec64 mov r4, r0
 *   @0x1fec68 bl 0x1fe500 <_Z17CheckPhysicsErrorP9CInstancebb>
 *   @0x1fec6c subs r7, r0, #0
 *   @0x1fec70 beq 0x1fecb4 <_Z23SV_PhysicsFixedRotationP9CInstanceiP6RValue+0x60>
 *   @0x1fec74 ldr r8, [r4, #0x84]
 *   @0x1fec78 cmp r8, #0
 *   @0x1fec7c beq 0x1fecd0 <_Z23SV_PhysicsFixedRotationP9CInstanceiP6RValue+0x7c>
 *   @0x1fec80 ldr r3, [r6, #0xc]
 *   @0x1fec84 bic r3, r3, #-16777216
 *   @0x1fec88 cmp r3, #0
 *   @0x1fec8c bne 0x1fecbc <_Z23SV_PhysicsFixedRotationP9CInstanceiP6RValue+0x68>
 *   @0x1fec90 ldm r6, {r4, r5}
 *   @0x1fec94 vmov.f64 d7, #5.000000e-01
 *   @0x1fec98 ldr r0, [r8]
 *   @0x1fec9c vmov d6, r4, r5
 *   @0x1feca0 vcmpe.f64 d6, d7
 *   @0x1feca4 vmrs APSR_nzcv, fpscr
 *   @0x1feca8 movle r1, #0
 *   @0x1fecac movgt r1, #1
 *   @0x1fecb0 bl 0x2c7580 <_ZN6b2Body16SetFixedRotationEb>
 *   @0x1fecb4 mov r0, r7
 *   @0x1fecb8 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1fecbc mov r0, r6
 *   @0x1fecc0 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fecc4 mov r4, r0
 *   @0x1fecc8 mov r5, r1
 *   @0x1feccc b 0x1fec94 <_Z23SV_PhysicsFixedRotationP9CInstanceiP6RValue+0x40>
 *   @0x1fecd0 mov r7, r8
 *   @0x1fecd4 b 0x1fecb4 <_Z23SV_PhysicsFixedRotationP9CInstanceiP6RValue+0x60>
 *
 * ══ §111/230 SV_PhysicsActive(CInstance*, int, RValue*)  0x1fecd8  size 132  33 条（0x1fecd8..0x1fed5c）
 * @func 0x1fecd8 0x1fed5c  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CheckPhysicsError(CInstance*, bool, bool) / b2Body::SetActive(bool) / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0x84×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fecd8 push {r4, r5, r6, r7, r8, lr}
 *   @0x1fecdc mov r1, #1
 *   @0x1fece0 mov r6, r2
 *   @0x1fece4 mov r2, #0
 *   @0x1fece8 mov r4, r0
 *   @0x1fecec bl 0x1fe500 <_Z17CheckPhysicsErrorP9CInstancebb>
 *   @0x1fecf0 subs r7, r0, #0
 *   @0x1fecf4 beq 0x1fed38 <_Z16SV_PhysicsActiveP9CInstanceiP6RValue+0x60>
 *   @0x1fecf8 ldr r8, [r4, #0x84]
 *   @0x1fecfc cmp r8, #0
 *   @0x1fed00 beq 0x1fed54 <_Z16SV_PhysicsActiveP9CInstanceiP6RValue+0x7c>
 *   @0x1fed04 ldr r3, [r6, #0xc]
 *   @0x1fed08 bic r3, r3, #-16777216
 *   @0x1fed0c cmp r3, #0
 *   @0x1fed10 bne 0x1fed40 <_Z16SV_PhysicsActiveP9CInstanceiP6RValue+0x68>
 *   @0x1fed14 ldm r6, {r4, r5}
 *   @0x1fed18 vmov.f64 d7, #5.000000e-01
 *   @0x1fed1c ldr r0, [r8]
 *   @0x1fed20 vmov d6, r4, r5
 *   @0x1fed24 vcmpe.f64 d6, d7
 *   @0x1fed28 vmrs APSR_nzcv, fpscr
 *   @0x1fed2c movle r1, #0
 *   @0x1fed30 movgt r1, #1
 *   @0x1fed34 bl 0x2c74ac <_ZN6b2Body9SetActiveEb>
 *   @0x1fed38 mov r0, r7
 *   @0x1fed3c pop {r4, r5, r6, r7, r8, pc}
 *   @0x1fed40 mov r0, r6
 *   @0x1fed44 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fed48 mov r4, r0
 *   @0x1fed4c mov r5, r1
 *   @0x1fed50 b 0x1fed18 <_Z16SV_PhysicsActiveP9CInstanceiP6RValue+0x40>
 *   @0x1fed54 mov r7, r8
 *   @0x1fed58 b 0x1fed38 <_Z16SV_PhysicsActiveP9CInstanceiP6RValue+0x60>
 *
 * ══ §112/230 GV_Argument0(CInstance*, int, RValue*)  0x1ffe1c  size 132  33 条（0x1ffe1c..0x1ffea0）
 * @func 0x1ffe1c 0x1ffeb0  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GV_Argument0(CInstance*, int, RValue*)+0x68 / GET_RValue(RValue*, RValue*, int) / FREE_RValue__Pre(RValue*)
 * 字段偏移 top8: 0xc×2 / 0x50×1 / 0x8×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1ffe1c push {r3, r4, r5, lr}
 *   @0x1ffe20 mov r4, r2
 *   @0x1ffe24 ldr r3, [r2, #0xc]
 *   @0x1ffe28 mov r5, r1
 *   @0x1ffe2c sub r3, r3, #1
 *   @0x1ffe30 bic r3, r3, #-16777216
 *   @0x1ffe34 bic r3, r3, #3
 *   @0x1ffe38 cmp r3, #0
 *   @0x1ffe3c beq 0x1ffe8c <_Z12GV_Argument0P9CInstanceiP6RValue+0x70>
 *   @0x1ffe40 ldr r3, [pc, #0x50]
 *   @0x1ffe44 mov r0, #0
 *   @0x1ffe48 str r0, [r4]
 *   @0x1ffe4c mov r12, #5
 *   @0x1ffe50 ldr r3, [pc, r3]
 *   @0x1ffe54 str r0, [r4, #0x8]
 *   @0x1ffe58 str r12, [r4, #0xc]
 *   @0x1ffe5c ldr r3, [r3]
 *   @0x1ffe60 cmp r3, r0
 *   @0x1ffe64 strle r0, [r4, #0x4]
 *   @0x1ffe68 ble 0x1ffe84 <_Z12GV_Argument0P9CInstanceiP6RValue+0x68>
 *   @0x1ffe6c ldr r3, [pc, #0x28]
 *   @0x1ffe70 mov r0, r4
 *   @0x1ffe74 mov r2, r5
 *   @0x1ffe78 ldr r3, [pc, r3]
 *   @0x1ffe7c ldr r1, [r3]
 *   @0x1ffe80 bl 0xd13bc <_Z10GET_RValueP6RValueS0_i>
 *   @0x1ffe84 mov r0, #1
 *   @0x1ffe88 pop {r3, r4, r5, pc}
 *   @0x1ffe8c mov r0, r2
 *   @0x1ffe90 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x1ffe94 b 0x1ffe40 <_Z12GV_Argument0P9CInstanceiP6RValue+0x24>
 *   @0x1ffe98 ldrheq sp, [lr], -r12
 *   @0x1ffe9c mulseq lr, r8, lr
 *
 * ══ §113/230 IniFile::DeleteSection(char const*)  0x235c2c  size 132  33 条（0x235c2c..0x235cb0）
 * @func 0x235c2c 0x235cb0  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6574 / Section::~Section() / operator delete(void*)
 * 字段偏移 top8: 0x8×2 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x235c2c push {r3, r4, r5, r6, r7, lr}
 *   @0x235c30 mov r7, r0
 *   @0x235c34 ldr r4, [r0, #0x8]
 *   @0x235c38 mov r6, r1
 *   @0x235c3c cmp r4, #0
 *   @0x235c40 beq 0x235ca8 <_ZN7IniFile13DeleteSectionEPKc+0x7c>
 *   @0x235c44 mov r5, #0
 *   @0x235c48 b 0x235c5c <_ZN7IniFile13DeleteSectionEPKc+0x30>
 *   @0x235c4c cmp r3, #0
 *   @0x235c50 mov r5, r4
 *   @0x235c54 mov r4, r3
 *   @0x235c58 beq 0x235ca0 <_ZN7IniFile13DeleteSectionEPKc+0x74>
 *   @0x235c5c mov r0, r6
 *   @0x235c60 ldr r1, [r4, #0x8]
 *   @0x235c64 bl 0xb6574 <strcmp@plt>
 *   @0x235c68 ldr r3, [r4]
 *   @0x235c6c cmp r0, #0
 *   @0x235c70 bne 0x235c4c <_ZN7IniFile13DeleteSectionEPKc+0x20>
 *   @0x235c74 cmp r5, #0
 *   @0x235c78 mov r0, r4
 *   @0x235c7c strne r3, [r5]
 *   @0x235c80 mov r5, #1
 *   @0x235c84 streq r3, [r7, #0x8]
 *   @0x235c88 strb r5, [r7, #0x18]
 *   @0x235c8c bl 0x2353e0 <_ZN7SectionD2Ev>
 *   @0x235c90 mov r0, r4
 *   @0x235c94 bl 0x27d1d0 <_ZdlPv>
 *   @0x235c98 mov r0, r5
 *   @0x235c9c pop {r3, r4, r5, r6, r7, pc}
 *   @0x235ca0 mov r0, r3
 *   @0x235ca4 pop {r3, r4, r5, r6, r7, pc}
 *   @0x235ca8 mov r0, r4
 *   @0x235cac pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §114/230 CPhysicsDebugRender::DrawCircle(b2Vec2 const&, float, b2Color const&)  0x23c4d0  size 132  33 条（0x23c4d0..0x23c554）
 * @func 0x23c4d0 0x23c554  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsDebugRender::TranslateColour(b2Color const&) / YYGML_draw_set_colour(unsigned int) / GR_Draw_Ellipse(float, float, float, float, bool)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 20 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23c4d0 push {r4, r5, lr}
 *   @0x23c4d4 vpush {d8}
 *   @0x23c4d8 mov r4, r1
 *   @0x23c4dc sub sp, sp, #12
 *   @0x23c4e0 mov r1, r3
 *   @0x23c4e4 vmov s16, r2
 *   @0x23c4e8 mov r5, r0
 *   @0x23c4ec bl 0x23c338 <_ZN19CPhysicsDebugRender15TranslateColourERK7b2Color>
 *   @0x23c4f0 bl 0x169d98 <_Z21YYGML_draw_set_colourj>
 *   @0x23c4f4 vmov.f32 s12, #1.000000e+00
 *   @0x23c4f8 ldr r3, [r5, #0x8]
 *   @0x23c4fc vldr s15, [r3, #96]
 *   @0x23c500 vldr s13, [r4]
 *   @0x23c504 vldr s14, [r4, #4]
 *   @0x23c508 mov r3, #1
 *   @0x23c50c str r3, [sp]
 *   @0x23c510 vdiv.f32 s15, s12, s15
 *   @0x23c514 vsub.f32 s11, s13, s16
 *   @0x23c518 vsub.f32 s12, s14, s16
 *   @0x23c51c vadd.f32 s13, s13, s16
 *   @0x23c520 vadd.f32 s16, s16, s14
 *   @0x23c524 vmul.f32 s11, s11, s15
 *   @0x23c528 vmul.f32 s12, s12, s15
 *   @0x23c52c vmov r0, s11
 *   @0x23c530 vmul.f32 s13, s13, s15
 *   @0x23c534 vmov r1, s12
 *   @0x23c538 vmul.f32 s16, s16, s15
 *   @0x23c53c vmov r2, s13
 *   @0x23c540 vmov r3, s16
 *   @0x23c544 bl 0x16b278 <_Z15GR_Draw_Ellipseffffb>
 *   @0x23c548 add sp, sp, #12
 *   @0x23c54c vpop {d8}
 *   @0x23c550 pop {r4, r5, pc}
 *
 * ══ §115/230 JS_Date_create(RValue&, CInstance*, CInstance*, int, RValue*, double)  0x246080  size 132  33 条（0x246080..0x246104）
 * @func 0x246080 0x246104  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JS_StandardBuiltInObjectConstructor(RValue&, CInstance*, CInstance*, int, RValue*) / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)
 * 字段偏移 top8: 0x28×3 / 0x20×2 / 0x64×1 / 0x50×1 / 0x18×1 / 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x246080 push {r4, r5, r6, r7, lr}
 *   @0x246084 sub sp, sp, #12
 *   @0x246088 mov r6, r0
 *   @0x24608c ldr r7, [pc, #0x64]
 *   @0x246090 ldr r12, [sp, #0x20]
 *   @0x246094 ldrd r4, r5, [sp, #40]
 *   @0x246098 add r7, pc, r7
 *   @0x24609c str r12, [sp]
 *   @0x2460a0 bl 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_>
 *   @0x2460a4 ldr r3, [pc, #0x50]
 *   @0x2460a8 ldr r6, [r6]
 *   @0x2460ac ldr r3, [pc, r3]
 *   @0x2460b0 ldr r1, [r3]
 *   @0x2460b4 mov r0, r6
 *   @0x2460b8 str r1, [r6, #0x18]
 *   @0x2460bc bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x2460c0 ldr r1, [r6, #0x28]
 *   @0x2460c4 mov r2, r4
 *   @0x2460c8 mov r12, #0
 *   @0x2460cc orr r4, r1, #1
 *   @0x2460d0 ldr r1, [pc, #0x28]
 *   @0x2460d4 str r7, [r6, #0x40]
 *   @0x2460d8 mov r0, r6
 *   @0x2460dc str r4, [r6, #0x28]
 *   @0x2460e0 mov r3, r5
 *   @0x2460e4 add r1, pc, r1
 *   @0x2460e8 str r12, [sp, #0x20]
 *   @0x2460ec add sp, sp, #12
 *   @0x2460f0 pop {r4, r5, r6, r7, lr}
 *   @0x2460f4 b 0x1999d0 <_ZN12YYObjectBase3AddEPKcdi>
 *   @0x2460f8 andseq pc, r0, r4, ror #18
 *   @0x2460fc andseq r11, r10, r4, lsl #13
 *   @0x246100 andseq pc, r0, r12, lsr #8
 *
 * ══ §116/230 F_JSObjectCall(RValue&, CInstance*, CInstance*, int, RValue*)  0x24ed70  size 132  33 条（0x24ed70..0x24edf4）
 * @func 0x24ed70 0x24edf4  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_JSToObject(RValue&, CInstance*, CInstance*, int, RValue*)
 * 字段偏移 top8: 0x20×2 / 0xc×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x24ed70 push {r4, r5, r6, r7, r8, lr}
 *   @0x24ed74 subs r5, r3, #0
 *   @0x24ed78 sub sp, sp, #8
 *   @0x24ed7c mov r8, r0
 *   @0x24ed80 mov r7, r1
 *   @0x24ed84 mov r6, r2
 *   @0x24ed88 ldr r12, [sp, #0x20]
 *   @0x24ed8c beq 0x24edbc <_Z14F_JSObjectCallR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x24ed90 ldr r4, [r12, #0xc]
 *   @0x24ed94 cmp r4, #5
 *   @0x24ed98 beq 0x24edbc <_Z14F_JSObjectCallR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x24ed9c cmp r4, #12
 *   @0x24eda0 beq 0x24edbc <_Z14F_JSObjectCallR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x24eda4 str r12, [sp]
 *   @0x24eda8 bl 0x247648 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_>
 *   @0x24edac cmp r0, #1
 *   @0x24edb0 beq 0x24eddc <_Z14F_JSObjectCallR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x24edb4 add sp, sp, #8
 *   @0x24edb8 pop {r4, r5, r6, r7, r8, pc}
 *   @0x24edbc str r12, [sp, #0x20]
 *   @0x24edc0 mov r0, r8
 *   @0x24edc4 mov r1, r7
 *   @0x24edc8 mov r2, r6
 *   @0x24edcc mov r3, r5
 *   @0x24edd0 add sp, sp, #8
 *   @0x24edd4 pop {r4, r5, r6, r7, r8, lr}
 *   @0x24edd8 b 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_>
 *   @0x24eddc ldr r0, [pc, #0xc]
 *   @0x24ede0 add r0, pc, r0
 *   @0x24ede4 add sp, sp, #8
 *   @0x24ede8 pop {r4, r5, r6, r7, r8, lr}
 *   @0x24edec b 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x24edf0 andseq r7, r0, r8, ror #2
 *
 * ══ §117/230 yyMatrix::Transpose(yyMatrix*, yyMatrix*)  0x27ac2c  size 132  33 条（0x27ac2c..0x27acb0）
 * @func 0x27ac2c 0x27acb0  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×2 / 0x4×2 / 0x20×2 / 0x8×2 / 0x30×2 / 0x14×2 / 0xc×2 / 0x24×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27ac2c ldr r3, [r1, #0x10]
 *   @0x27ac30 ldr r2, [r1]
 *   @0x27ac34 str r3, [r0, #0x4]
 *   @0x27ac38 ldr r3, [r1, #0x20]
 *   @0x27ac3c ldr r12, [r1, #0x4]
 *   @0x27ac40 str r2, [r0]
 *   @0x27ac44 str r3, [r0, #0x8]
 *   @0x27ac48 ldr r2, [r1, #0x30]
 *   @0x27ac4c ldr r3, [r1, #0x14]
 *   @0x27ac50 str r12, [r0, #0x10]
 *   @0x27ac54 str r2, [r0, #0xc]
 *   @0x27ac58 str r3, [r0, #0x14]
 *   @0x27ac5c ldr r2, [r1, #0x24]
 *   @0x27ac60 ldr r3, [r1, #0x34]
 *   @0x27ac64 str r2, [r0, #0x18]
 *   @0x27ac68 str r3, [r0, #0x1c]
 *   @0x27ac6c ldr r2, [r1, #0x8]
 *   @0x27ac70 ldr r3, [r1, #0x18]
 *   @0x27ac74 str r2, [r0, #0x20]
 *   @0x27ac78 str r3, [r0, #0x24]
 *   @0x27ac7c ldr r2, [r1, #0x28]
 *   @0x27ac80 ldr r3, [r1, #0x38]
 *   @0x27ac84 str r2, [r0, #0x28]
 *   @0x27ac88 str r3, [r0, #0x2c]
 *   @0x27ac8c ldr r2, [r1, #0xc]
 *   @0x27ac90 ldr r3, [r1, #0x1c]
 *   @0x27ac94 str r2, [r0, #0x30]
 *   @0x27ac98 str r3, [r0, #0x34]
 *   @0x27ac9c ldr r2, [r1, #0x2c]
 *   @0x27aca0 ldr r3, [r1, #0x3c]
 *   @0x27aca4 str r2, [r0, #0x38]
 *   @0x27aca8 str r3, [r0, #0x3c]
 *   @0x27acac bx lr
 *
 * ══ §118/230 yyMatrix::SetYRotation(yyMatrix*, float)  0x27af60  size 132  33 条（0x27af60..0x27afe4）
 * @func 0x27af60 0x27aff4  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6580 / 0xb658c
 * 字段偏移 top8: 0x38×1 / 0x34×1 / 0x30×1 / 0x2c×1 / 0x24×1 / 0x1c×1 / 0x18×1 / 0x10×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27af60 vmov s15, r1
 *   @0x27af64 mov r3, #0
 *   @0x27af68 push {r4, lr}
 *   @0x27af6c vpush {d8}
 *   @0x27af70 vldr s17, [pc, #104]
 *   @0x27af74 vmul.f32 s17, s15, s17
 *   @0x27af78 mov r4, r0
 *   @0x27af7c str r3, [r0, #0x38]
 *   @0x27af80 str r3, [r0, #0x34]
 *   @0x27af84 str r3, [r0, #0x30]
 *   @0x27af88 str r3, [r0, #0x2c]
 *   @0x27af8c str r3, [r0, #0x24]
 *   @0x27af90 str r3, [r0, #0x1c]
 *   @0x27af94 str r3, [r0, #0x18]
 *   @0x27af98 str r3, [r0, #0x10]
 *   @0x27af9c str r3, [r0, #0xc]
 *   @0x27afa0 str r3, [r0, #0x4]
 *   @0x27afa4 mov r3, #1065353216
 *   @0x27afa8 str r3, [r4, #0x3c]
 *   @0x27afac vmov r0, s17
 *   @0x27afb0 str r3, [r4, #0x14]
 *   @0x27afb4 bl 0xb6580 <sinf@plt>
 *   @0x27afb8 vmov s16, r0
 *   @0x27afbc vmov r0, s17
 *   @0x27afc0 bl 0xb658c <cosf@plt>
 *   @0x27afc4 vneg.f32 s15, s16
 *   @0x27afc8 vstr s16, [r4, #8]
 *   @0x27afcc vstr s15, [r4, #32]
 *   @0x27afd0 str r0, [r4]
 *   @0x27afd4 str r0, [r4, #0x28]
 *   @0x27afd8 vpop {d8}
 *   @0x27afdc pop {r4, pc}
 *   @0x27afe0 vstmialo lr, {s30, s31}
 *
 * ══ §119/230 yyMatrix::SetXRotation(yyMatrix*, float)  0x27afe4  size 132  33 条（0x27afe4..0x27b068）
 * @func 0x27afe4 0x27b068  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6580 / 0xb658c
 * 字段偏移 top8: 0x38×1 / 0x34×1 / 0x30×1 / 0x2c×1 / 0x20×1 / 0x1c×1 / 0x10×1 / 0xc×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27afe4 vmov s15, r1
 *   @0x27afe8 mov r3, #0
 *   @0x27afec push {r4, lr}
 *   @0x27aff0 vpush {d8}
 *   @0x27aff4 vldr s17, [pc, #104]
 *   @0x27aff8 vmul.f32 s17, s15, s17
 *   @0x27affc mov r4, r0
 *   @0x27b000 str r3, [r0, #0x38]
 *   @0x27b004 str r3, [r0, #0x34]
 *   @0x27b008 str r3, [r0, #0x30]
 *   @0x27b00c str r3, [r0, #0x2c]
 *   @0x27b010 str r3, [r0, #0x20]
 *   @0x27b014 str r3, [r0, #0x1c]
 *   @0x27b018 str r3, [r0, #0x10]
 *   @0x27b01c str r3, [r0, #0xc]
 *   @0x27b020 str r3, [r0, #0x8]
 *   @0x27b024 str r3, [r0, #0x4]
 *   @0x27b028 mov r3, #1065353216
 *   @0x27b02c str r3, [r4, #0x3c]
 *   @0x27b030 vmov r0, s17
 *   @0x27b034 str r3, [r4]
 *   @0x27b038 bl 0xb6580 <sinf@plt>
 *   @0x27b03c vmov s16, r0
 *   @0x27b040 vmov r0, s17
 *   @0x27b044 bl 0xb658c <cosf@plt>
 *   @0x27b048 vneg.f32 s15, s16
 *   @0x27b04c vstr s16, [r4, #36]
 *   @0x27b050 vstr s15, [r4, #24]
 *   @0x27b054 str r0, [r4, #0x14]
 *   @0x27b058 str r0, [r4, #0x28]
 *   @0x27b05c vpop {d8}
 *   @0x27b060 pop {r4, pc}
 *   @0x27b064 vstmialo lr, {s30, s31}
 *
 * ══ §120/230 png_convert_to_rfc1123  0x2a5f30  size 132  33 条（0x2a5f30..0x2a5fb4）
 * @func 0x2a5f30 0x2a5fb4  size 132  33 条
 * 部分覆盖: 本节 33/54 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __aeabi_uidivmod×4 / png_malloc / 0xb65c8
 * 字段偏移 top8: 0x2×1 / 0x3×1 / 0x50×1 / 0x5×1 / 0x8×1 / 0x6×1 / 0xc×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a5f30 push {r4, r5, r6, lr}
 *   @0x2a5f34 sub sp, #0x18
 *   @0x2a5f38 cmp r0, #0x0
 *   @0x2a5f3c ldr.w r3, [r0, #0x2bc]
 *   @0x2a5f40 cbnz r3, 0x2a5f4c <png_convert_to_rfc1123+0x1c>
 *   @0x2a5f44 bl 0x2a6ca0 <png_malloc>
 *   @0x2a5f48 str.w r0, [r5, #0x2bc]
 *   @0x2a5f4c ldrb r0, [r4, #0x2]
 *   @0x2a5f50 ldrb r6, [r4, #0x3]
 *   @0x2a5f54 blx 0x318cf0 <__aeabi_uidivmod>
 *   @0x2a5f58 ldr r3, [pc, #0x50]
 *   @0x2a5f5c and r6, r6, #0x1f
 *   @0x2a5f60 add r3, pc
 *   @0x2a5f64 add.w r1, r3, r1, lsl #2
 *   @0x2a5f68 ldrh r3, [r4]
 *   @0x2a5f6c movs r1, #0x18
 *   @0x2a5f70 blx 0x318cf0 <__aeabi_uidivmod>
 *   @0x2a5f74 ldrb r0, [r4, #0x5]
 *   @0x2a5f78 str r1, [sp, #0x8]
 *   @0x2a5f7c blx 0x318cf0 <__aeabi_uidivmod>
 *   @0x2a5f80 ldrb r0, [r4, #0x6]
 *   @0x2a5f84 str r1, [sp, #0xc]
 *   @0x2a5f88 blx 0x318cf0 <__aeabi_uidivmod>
 *   @0x2a5f8c ldr r2, [pc, #0x20]
 *   @0x2a5f90 add r2, pc
 *   @0x2a5f94 str r1, [sp, #0x10]
 *   @0x2a5f98 ldr.w r0, [r5, #0x2bc]
 *   @0x2a5f9c blx 0xb65c8 <snprintf@plt>
 *   @0x2a5fa0 ldr.w r0, [r5, #0x2bc]
 *   @0x2a5fa4 b 0x2a5fa6 <png_convert_to_rfc1123+0x76>
 *   @0x2a5fa8 pop {r4, r5, r6, pc}
 *   @0x2a5fac ldr r1, [sp, #0x180]
 *   @0x2a5fb0 str r0, [r7, #0x2c]
 *
 * ══ §121/230 png_do_read_invert_alpha  0x2a8e3a  size 132  33 条（0x2a8e3a..0x2a8ebe）
 * @func 0x2a8e3a 0x2a8ebe  size 132  33 条
 * 部分覆盖: 本节 33/64 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x9×2 / 0x4×2 / 0x3×2 / 0x8×1 / 0x7×1 / 0x1×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a8e3a ldrb r2, [r0, #0x8]
 *   @0x2a8e3e cmp r2, #0x6
 *   @0x2a8e42 ldrb r2, [r0, #0x9]
 *   @0x2a8e46 ldr r2, [r0, #0x4]
 *   @0x2a8e4a mov.w r2, #0x0
 *   @0x2a8e4e bne 0x2a8e64 <png_do_read_invert_alpha+0x2a>
 *   @0x2a8e52 beq 0x2a8e62 <png_do_read_invert_alpha+0x28>
 *   @0x2a8e56 andlo r0, r1, #256
 *   @0x2a8e5a subs r1, #0x4
 *   @0x2a8e5e strb r0, [r1, #0x3]
 *   @0x2a8e62 bx lr
 *   @0x2a8e66 beq 0x2a8e7c <png_do_read_invert_alpha+0x42>
 *   @0x2a8e6a andlo r0, r1, #256
 *   @0x2a8e6e subs r1, #0x8
 *   @0x2a8e72 strb r0, [r1, #0x7]
 *   @0x2a8e76 mvns r0, r0
 *   @0x2a8e7a b 0x2a8e64 <png_do_read_invert_alpha+0x2a>
 *   @0x2a8e7e cmp r2, #0x4
 *   @0x2a8e82 ldrb r2, [r0, #0x9]
 *   @0x2a8e86 ldr r2, [r0, #0x4]
 *   @0x2a8e8a mov.w r2, #0x0
 *   @0x2a8e8e bne 0x2a8ea4 <png_do_read_invert_alpha+0x6a>
 *   @0x2a8e92 beq 0x2a8ea2 <png_do_read_invert_alpha+0x68>
 *   @0x2a8e96 andlo r0, r1, #256
 *   @0x2a8e9a subs r1, #0x2
 *   @0x2a8e9e strb r0, [r1, #0x1]
 *   @0x2a8ea2 bx lr
 *   @0x2a8ea6 beq 0x2a8ebc <png_do_read_invert_alpha+0x82>
 *   @0x2a8eaa andlo r0, r1, #256
 *   @0x2a8eae subs r1, #0x4
 *   @0x2a8eb2 strb r0, [r1, #0x3]
 *   @0x2a8eb6 mvns r0, r0
 *   @0x2a8eba b 0x2a8ea4 <png_do_read_invert_alpha+0x6a>
 *
 * ══ §122/230 b2GearJoint::SetRatio(float)  0x2e4880  size 132  33 条（0x2e4880..0x2e4904）
 * @func 0x2e4880 0x2e4904  size 132  33 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2GearJoint::SetRatio(float)+0x60
 * 字段偏移 top8: 0x68×1 / 0x2×1 / 0x18×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e4880 push {r4, lr}
 *   @0x2e4884 vpush {d8}
 *   @0x2e4888 vmov s16, r1
 *   @0x2e488c ldr r3, [pc, #0x68]
 *   @0x2e4890 mov r4, r0
 *   @0x2e4894 vcmp.f32 s16, s16
 *   @0x2e4898 sub sp, sp, #16
 *   @0x2e489c ldr r3, [pc, r3]
 *   @0x2e48a0 mov r0, #0
 *   @0x2e48a4 ldr r3, [r3]
 *   @0x2e48a8 vmrs APSR_nzcv, fpscr
 *   @0x2e48ac bne 0x2e48e0 <_ZN11b2GearJoint8SetRatioEf+0x60>
 *   @0x2e48b0 movw r2, #0x7f80
 *   @0x2e48b4 strh r0, [sp]
 *   @0x2e48b8 strh r2, [sp, #2]
 *   @0x2e48bc vldr s15, [sp]
 *   @0x2e48c0 vneg.f32 s14, s15
 *   @0x2e48c4 vcmpe.f32 s16, s14
 *   @0x2e48c8 vmrs APSR_nzcv, fpscr
 *   @0x2e48cc ble 0x2e48e0 <_ZN11b2GearJoint8SetRatioEf+0x60>
 *   @0x2e48d0 vcmpe.f32 s16, s15
 *   @0x2e48d4 vmrs APSR_nzcv, fpscr
 *   @0x2e48d8 movpl r0, #0
 *   @0x2e48dc movmi r0, #1
 *   @0x2e48e0 ldr r1, [pc, #0x18]
 *   @0x2e48e4 add r1, pc, r1
 *   @0x2e48e8 blx r3
 *   @0x2e48ec vstr s16, [r4, #152]
 *   @0x2e48f0 add sp, sp, #16
 *   @0x2e48f4 vpop {d8}
 *   @0x2e48f8 pop {r4, pc}
 *   @0x2e48fc andseq r12, r0, r12, lsr #24
 *   @0x2e4900 andeq r9, r7, r4, ror #3
 *
 * ══ §123/230 ft_corner_orientation  0x2e51c4  size 132  33 条（0x2e51c4..0x2e5248）
 * @func 0x2e51c4 0x2e5248  size 132  33 条
 * 部分覆盖: 本节 33/62 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xfeb41954 / 0xfeb81d68 / 0xfec82d80 / 0xfeb41984 / anon_2e490c / ft_corner_orientation+0x74
 * 字段偏移 top8: 0x64×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e51c4 push {r0, r1, r2, r3, r4, r5, r6, lr}
 *   @0x2e51c8 mov r4, r2
 *   @0x2e51cc bl 0xfeb41954 <b2_toiTime+0xfffffffffe3e84b0>
 *   @0x2e51d0 b 0xfe3c1958 <b2_toiTime+0xfffffffffdc684b4>
 *   @0x2e51d4 bl 0xfeb81d68 <b2_toiTime+0xfffffffffe4288c4>
 *   @0x2e51d8 ldrmi r7, [r1], #-739
 *   @0x2e51dc ldr r2, [pc, #0x64]
 *   @0x2e51e0 bhi 0x2e520a <ft_corner_orientation+0x46>
 *   @0x2e51e4 bl 0xfec82d80 <b2_toiTime+0xfffffffffe5298dc>
 *   @0x2e51e8 b 0xfe402d84 <b2_toiTime+0xfffffffffdca98e0>
 *   @0x2e51ec bl 0xfeb41984 <b2_toiTime+0xfffffffffe3e84e0>
 *   @0x2e51f0 ldrtmi r7, [r1], #-484
 *   @0x2e51f4 cmp r1, r2
 *   @0x2e51f8 muls r0, r3, r0
 *   @0x2e51fc cmp r0, r4
 *   @0x2e5200 ite ge
 *   @0x2e5204 mvnlt r0, #0x0
 *   @0x2e5208 b 0x2e5240 <ft_corner_orientation+0x7c>
 *   @0x2e520c mov r2, sp
 *   @0x2e5210 bge 0x3a400c <af_blue_strings+0x1ce8>
 *   @0x2e5214 mov r0, r5
 *   @0x2e5218 bl 0x2e490c <_ZNK11b2GearJoint8GetRatioEv+0x8>
 *   @0x2e521c ldr r3, [sp, #0xc]
 *   @0x2e5220 cmp r2, r3
 *   @0x2e5224 blo 0x2e5238 <ft_corner_orientation+0x74>
 *   @0x2e5228 ldr r2, [sp]
 *   @0x2e522c bhi 0x2e523e <ft_corner_orientation+0x7a>
 *   @0x2e5230 movhs r0, #0x0
 *   @0x2e5234 and r0, r3, r0
 *   @0x2e5238 mov.w r0, #0xffffffff
 *   @0x2e523c b 0x2e5240 <ft_corner_orientation+0x7c>
 *   @0x2e5240 add sp, #0x10
 *   @0x2e5244 .word 0xffff 0001
 *
 * ══ §124/230 FT_Gzip_Uncompress  0x316c58  size 132  33 条（0x316c58..0x316cdc）
 * @func 0x316c58 0x316cdc  size 132  33 条
 * 部分覆盖: 本节 33/63 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x28×1 / 0x4×1 / 0x10×1 / 0x50×1 / 0x24×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x316c58 push {r4, r5, r6, lr}
 *   @0x316c5c sub sp, #0x38
 *   @0x316c60 movs r0, #0x6
 *   @0x316c64 cmp r2, #0x0
 *   @0x316c68 cmp r1, #0x0
 *   @0x316c6c str r3, [sp]
 *   @0x316c70 str r1, [sp, #0xc]
 *   @0x316c74 str r0, [sp, #0x28]
 *   @0x316c78 str r3, [sp, #0x4]
 *   @0x316c7c str r3, [sp, #0x10]
 *   @0x316c80 add r3, pc
 *   @0x316c84 ldr r3, [pc, #0x50]
 *   @0x316c88 str r3, [sp, #0x24]
 *   @0x316c8c stmdahs r0, {r0, r1, r2, r3, r6, r7, r8, r10, r11, r12, sp, lr, pc}
 *   @0x316c90 bne 0x316c60 <FT_Gzip_Uncompress+0x8>
 *   @0x316c94 movs r1, #0x4
 *   @0x316c98 stmdahs r1, {r0, r4, r6, r9, r10, r11, r12, sp, lr, pc}
 *   @0x316c9c mov r4, r0
 *   @0x316ca0 mov r0, sp
 *   @0x316ca4 ldmdblt r12!, {r0, r2, r5, r6, r8, r10, r11, r12, sp, lr, pc}
 *   @0x316ca8 movs r0, #0xa
 *   @0x316cac ldr r3, [sp, #0x14]
 *   @0x316cb0 str r3, [r6]
 *   @0x316cb4 .word 0x4604fd5d
 *   @0x316cb8 adds r2, r4, #0x4
 *   @0x316cbc adds r3, r4, #0x5
 *   @0x316cc0 cmn.w r4, #0x3
 *   @0x316cc4 ite eq
 *   @0x316cc8 movne r0, #0x0
 *   @0x316ccc movs r0, #0x40
 *   @0x316cd0 pop {r4, r5, r6, pc}
 *   @0x316cd4 ldmdb r9, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x316cd8 .word 0xe90b ffff
 *
 * ══ §125/230 FT_Matrix_Multiply_Scaled  0x2e4fce  size 130  33 条（0x2e4fce..0x2e5050）
 * @func 0x2e4fce 0x2e5052  size 132  33 条
 * 部分覆盖: 本节 33/55 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FT_MulDiv×8
 * 字段偏移 top8: 0x8×3 / 0xc×3 / 0x4×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e4fce push.w {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2e4fd2 mov r4, r1
 *   @0x2e4fd6 cmp r0, #0x0
 *   @0x2e4fda cmp r1, #0x0
 *   @0x2e4fde lsls r6, r2, #0x10
 *   @0x2e4fe2 ldr r0, [r0]
 *   @0x2e4fe6 bl 0x2e4d3c <FT_MulDiv>
 *   @0x2e4fea ldr r1, [r4, #0x8]
 *   @0x2e4fee mov r9, r0
 *   @0x2e4ff2 bl 0x2e4d3c <FT_MulDiv>
 *   @0x2e4ff6 ldr r1, [r4, #0x4]
 *   @0x2e4ffa add r9, r0
 *   @0x2e4ffe bl 0x2e4d3c <FT_MulDiv>
 *   @0x2e5002 ldr r1, [r4, #0xc]
 *   @0x2e5006 mov r8, r0
 *   @0x2e500a bl 0x2e4d3c <FT_MulDiv>
 *   @0x2e500e ldr r1, [r4]
 *   @0x2e5012 add r8, r0
 *   @0x2e5016 bl 0x2e4d3c <FT_MulDiv>
 *   @0x2e501a ldr r1, [r4, #0x8]
 *   @0x2e501e mov r7, r0
 *   @0x2e5022 bl 0x2e4d3c <FT_MulDiv>
 *   @0x2e5026 ldr r1, [r4, #0x4]
 *   @0x2e502a add r7, r0
 *   @0x2e502e bl 0x2e4d3c <FT_MulDiv>
 *   @0x2e5032 ldr r1, [r4, #0xc]
 *   @0x2e5036 mov r10, r0
 *   @0x2e503a bl 0x2e4d3c <FT_MulDiv>
 *   @0x2e503e str.w r9, [r4]
 *   @0x2e5042 str.w r8, [r4, #0x4]
 *   @0x2e5046 str r7, [r4, #0x8]
 *   @0x2e504a str r0, [r4, #0xc]
 *   @0x2e504e push {r4, r5, r6, r7, r8, r9, r10, pc}
 *
 * ══ §126/230 FT_Stream_New  0x2e73dc  size 130  33 条（0x2e73dc..0x2e745e）
 * @func 0x2e73dc 0x2e7460  size 132  33 条
 * 部分覆盖: 本节 33/62 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ft_mem_free×2 / 0x366e58 / FT_Stream_OpenMemory / FT_Stream_Open
 * 字段偏移 top8: 0x4×4 / 0x1c×2 / 0x10×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e73dc push {r0, r1, r2, r4, r5, r6, r7, lr}
 *   @0x2e73e0 mov r5, r1
 *   @0x2e73e4 str r3, [r2]
 *   @0x2e73e8 beq 0x2e7454 <FT_Stream_New+0x78>
 *   @0x2e73ec beq 0x2e7458 <FT_Stream_New+0x7c>
 *   @0x2e73f0 movs r1, #0x28
 *   @0x2e73f4 mov r0, r6
 *   @0x2e73f8 blls 0x366e58 <_ZTS12CDS_Priority+0x8eb0>
 *   @0x2e73fc mov r4, r0
 *   @0x2e7400 str r6, [r0, #0x1c]
 *   @0x2e7404 lsls r1, r3, #0x1f
 *   @0x2e7408 ldr r1, [r5, #0x4]
 *   @0x2e740c bl 0x2e688a <FT_Stream_OpenMemory>
 *   @0x2e7410 b 0x2e743c <FT_Stream_New+0x60>
 *   @0x2e7414 bpl 0x2e7424 <FT_Stream_New+0x48>
 *   @0x2e7418 bl 0x2e9bd4 <FT_Stream_Open>
 *   @0x2e741c ldr r3, [r5, #0xc]
 *   @0x2e7420 str r0, [sp, #0x4]
 *   @0x2e7424 lsls r3, r3, #0x1e
 *   @0x2e7428 ldr r3, [r5, #0x10]
 *   @0x2e742c mov r1, r4
 *   @0x2e7430 bl 0x2e7336 <ft_mem_free>
 *   @0x2e7434 ldr r4, [r5, #0x10]
 *   @0x2e7438 movs r3, #0x6
 *   @0x2e743c ldr r3, [sp, #0x4]
 *   @0x2e7440 mov r1, r4
 *   @0x2e7444 bl 0x2e7336 <ft_mem_free>
 *   @0x2e7448 movs r4, #0x0
 *   @0x2e744c str r6, [r4, #0x1c]
 *   @0x2e7450 ldr r0, [sp, #0x4]
 *   @0x2e7454 movs r0, #0x21
 *   @0x2e7458 movs r0, #0x6
 *   @0x2e745c pop {r4, r5, r6, r7, pc}
 *
 * ══ §127/230 CBackground::CreateColor(int, int, unsigned int, bool)  0xc2a40  size 128  32 条（0xc2a40..0xc2ac0）
 * @func 0xc2a40 0xc2ac0  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CBackground::Clear() / operator new(unsigned int) / CBitmap32::CBitmap32(int, int, unsigned int) / CBackground::InitTexture()
 * 字段偏移 top8: 0x10×2 / 0x4×2 / 0x18×1 / 0xa×1 / 0x8×1 / 0x9×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc2a40 push {r4, r5, r6, r7, r8, lr}
 *   @0xc2a44 mov r4, r0
 *   @0xc2a48 mov r5, r2
 *   @0xc2a4c mov r6, r1
 *   @0xc2a50 ldrb r8, [sp, #0x18]
 *   @0xc2a54 mov r7, r3
 *   @0xc2a58 bl 0xc23c0 <_ZN11CBackground5ClearEv>
 *   @0xc2a5c ldr r0, [r4, #0x10]
 *   @0xc2a60 mov r2, #0
 *   @0xc2a64 str r6, [r4]
 *   @0xc2a68 cmp r0, r2
 *   @0xc2a6c strb r8, [r4, #0xa]
 *   @0xc2a70 str r5, [r4, #0x4]
 *   @0xc2a74 strb r2, [r4, #0x8]
 *   @0xc2a78 strb r2, [r4, #0x9]
 *   @0xc2a7c beq 0xc2a8c <_ZN11CBackground11CreateColorEiijb+0x4c>
 *   @0xc2a80 ldr r3, [r0]
 *   @0xc2a84 ldr r3, [r3, #0x4]
 *   @0xc2a88 blx r3
 *   @0xc2a8c mov r0, #24
 *   @0xc2a90 bl 0x27c524 <_Znwj>
 *   @0xc2a94 mov r1, r6
 *   @0xc2a98 mov r2, r5
 *   @0xc2a9c mov r3, r7
 *   @0xc2aa0 mov r8, r0
 *   @0xc2aa4 bl 0x166140 <_ZN9CBitmap32C2Eiij>
 *   @0xc2aa8 mov r0, r4
 *   @0xc2aac str r8, [r4, #0x10]
 *   @0xc2ab0 bl 0xc1e60 <_ZN11CBackground11InitTextureEv>
 *   @0xc2ab4 mov r0, r4
 *   @0xc2ab8 pop {r4, r5, r6, r7, r8, lr}
 *   @0xc2abc b 0xc1ea0 <_ZN11CBackground12InitLocalTPEEv>
 *
 * ══ §128/230 Background_Delete(int)  0xc3f74  size 128  32 条（0xc3f74..0xc3ff4）
 * @func 0xc3f74 0xc3ff4  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Background_Delete(int)+0x6c / CBackground::Free() / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x2×4 / 0x4×2 / 0x60×1 / 0x50×1 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc3f74 push {r4, r5, r6, lr}
 *   @0xc3f78 subs r4, r0, #0
 *   @0xc3f7c blt 0xc3fe0 <_Z17Background_Deletei+0x6c>
 *   @0xc3f80 ldr r3, [pc, #0x60]
 *   @0xc3f84 ldr r3, [pc, r3]
 *   @0xc3f88 ldr r3, [r3]
 *   @0xc3f8c cmp r4, r3
 *   @0xc3f90 bge 0xc3fe0 <_Z17Background_Deletei+0x6c>
 *   @0xc3f94 ldr r6, [pc, #0x50]
 *   @0xc3f98 add r6, pc, r6
 *   @0xc3f9c ldr r3, [r6, #0x4]
 *   @0xc3fa0 ldr r0, [r3, r4, lsl #2]
 *   @0xc3fa4 cmp r0, #0
 *   @0xc3fa8 popeq {r4, r5, r6, pc}
 *   @0xc3fac ldr r5, [pc, #0x3c]
 *   @0xc3fb0 bl 0xc2d5c <_ZN11CBackground4FreeEv>
 *   @0xc3fb4 ldr r3, [r6, #0x4]
 *   @0xc3fb8 mov r6, #0
 *   @0xc3fbc ldr r5, [pc, r5]
 *   @0xc3fc0 str r6, [r3, r4, lsl #2]
 *   @0xc3fc4 ldr r3, [r5]
 *   @0xc3fc8 ldr r0, [r3, r4, lsl #2]
 *   @0xc3fcc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xc3fd0 ldr r3, [r5]
 *   @0xc3fd4 mov r0, #1
 *   @0xc3fd8 str r6, [r3, r4, lsl #2]
 *   @0xc3fdc pop {r4, r5, r6, pc}
 *   @0xc3fe0 mov r0, #0
 *   @0xc3fe4 pop {r4, r5, r6, pc}
 *   @0xc3fe8 eorseq r9, r2, r4, asr #19
 *   @0xc3fec eorseq r5, r11, r0, lsl sp
 *   @0xc3ff0 mlaseq r2, r0, r9, r9
 *
 * ══ §129/230 F_BUFFER_Resize(RValue&, CInstance*, CInstance*, int, RValue*)  0xc5888  size 128  32 条（0xc5888..0xc5908）
 * @func 0xc5888 0xc5908  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / F_BUFFER_Resize(RValue&, CInstance*, CInstance*, int, RValue*)+0x64
 * 字段偏移 top8: 0x10×2 / 0x54×1 / 0x4×1 / 0x2×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc5888 push {r3, r4, r5, lr}
 *   @0xc588c mov r1, #0
 *   @0xc5890 ldr r4, [sp, #0x10]
 *   @0xc5894 mov r0, r4
 *   @0xc5898 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc589c cmp r0, #0
 *   @0xc58a0 blt 0xc58ec <_Z15F_BUFFER_ResizeR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0xc58a4 ldr r2, [pc, #0x54]
 *   @0xc58a8 add r2, pc, r2
 *   @0xc58ac ldr r1, [r2]
 *   @0xc58b0 cmp r0, r1
 *   @0xc58b4 bge 0xc58ec <_Z15F_BUFFER_ResizeR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0xc58b8 ldr r2, [r2, #0x4]
 *   @0xc58bc ldr r5, [r2, r0, lsl #2]
 *   @0xc58c0 cmp r5, #0
 *   @0xc58c4 beq 0xc58ec <_Z15F_BUFFER_ResizeR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0xc58c8 ldr r3, [r5]
 *   @0xc58cc mov r0, r4
 *   @0xc58d0 mov r1, #1
 *   @0xc58d4 ldr r4, [r3, #0x34]
 *   @0xc58d8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc58dc mov r1, r0
 *   @0xc58e0 mov r0, r5
 *   @0xc58e4 blx r4
 *   @0xc58e8 pop {r3, r4, r5, pc}
 *   @0xc58ec ldr r0, [pc, #0x10]
 *   @0xc58f0 mov r1, #0
 *   @0xc58f4 pop {r3, r4, r5, lr}
 *   @0xc58f8 add r0, pc, r0
 *   @0xc58fc b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc5900 eorseq r4, r11, r12, ror #16
 *   @0xc5904 .word 0x0026b2bc
 *
 * ══ §130/230 F_Vertex_Get_Number_debug(RValue&, CInstance*, CInstance*, int, RValue*)  0xc8894  size 128  32 条（0xc8894..0xc8914）
 * @func 0xc8894 0xc8914  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / GetBufferVertex(int)
 * 字段偏移 top8: 0x10×2 / 0xc×1 / 0x4×1 / 0x48×1 / 0x1c×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc8894 cmp r3, #1
 *   @0xc8898 mov r1, #0
 *   @0xc889c push {r3, r4, r5, lr}
 *   @0xc88a0 mov r4, r0
 *   @0xc88a4 mov r5, r3
 *   @0xc88a8 ldr r0, [sp, #0x10]
 *   @0xc88ac str r1, [r4, #0xc]
 *   @0xc88b0 str r1, [r4]
 *   @0xc88b4 str r1, [r4, #0x4]
 *   @0xc88b8 beq 0xc88d0 <_Z25F_Vertex_Get_Number_debugR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0xc88bc ldr r0, [pc, #0x48]
 *   @0xc88c0 mov r1, #1
 *   @0xc88c4 pop {r3, r4, r5, lr}
 *   @0xc88c8 add r0, pc, r0
 *   @0xc88cc b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc88d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc88d4 bl 0xc8860 <_Z15GetBufferVertexi>
 *   @0xc88d8 cmp r0, #0
 *   @0xc88dc beq 0xc88f8 <_Z25F_Vertex_Get_Number_debugR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0xc88e0 ldr r2, [r0, #0x1c]
 *   @0xc88e4 vmov s15, r2
 *   @0xc88e8 vcvt.f64.s32 d7, s15
 *   @0xc88ec vmov r2, r3, d7
 *   @0xc88f0 stm r4, {r2, r3}
 *   @0xc88f4 pop {r3, r4, r5, pc}
 *   @0xc88f8 ldr r0, [pc, #0x10]
 *   @0xc88fc mov r1, r5
 *   @0xc8900 pop {r3, r4, r5, lr}
 *   @0xc8904 add r0, pc, r0
 *   @0xc8908 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc890c eoreq r9, r6, r8, lsl #1
 *   @0xc8910 eoreq r9, r6, r8, ror r0
 *
 * ══ §131/230 YYGML_vertex_begin(int, int)  0xc9054  size 128  32 条（0xc9054..0xc90d4）
 * @func 0xc9054 0xc90d4  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GetBufferVertex(int) / GetVertexFormat(int)
 * 字段偏移 top8: 0xc×2 / 0x20×1 / 0x50×1 / 0x18×1 / 0x8×1 / 0x24×1 / 0x1c×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc9054 push {r4, r5, r6, lr}
 *   @0xc9058 mov r6, r1
 *   @0xc905c bl 0xc8860 <_Z15GetBufferVertexi>
 *   @0xc9060 subs r4, r0, #0
 *   @0xc9064 beq 0xc9074 <_Z18YYGML_vertex_beginii+0x20>
 *   @0xc9068 ldrb r5, [r4, #0x20]
 *   @0xc906c cmp r5, #0
 *   @0xc9070 beq 0xc9084 <_Z18YYGML_vertex_beginii+0x30>
 *   @0xc9074 ldr r0, [pc, #0x50]
 *   @0xc9078 pop {r4, r5, r6, lr}
 *   @0xc907c add r0, pc, r0
 *   @0xc9080 b 0xd547c <_Z7YYErrorPKcz>
 *   @0xc9084 mov r0, r6
 *   @0xc9088 bl 0x1e2cd0 <_Z15GetVertexFormati>
 *   @0xc908c cmp r0, #0
 *   @0xc9090 beq 0xc90bc <_Z18YYGML_vertex_beginii+0x68>
 *   @0xc9094 ldm r0, {r2, r3}
 *   @0xc9098 str r5, [r4, #0x18]
 *   @0xc909c str r5, [r4, #0x8]
 *   @0xc90a0 str r2, [r4, #0x24]
 *   @0xc90a4 str r5, [r4, #0xc]
 *   @0xc90a8 str r5, [r4, #0x1c]
 *   @0xc90ac str r5, [r4, #0x10]
 *   @0xc90b0 str r3, [r4, #0x14]
 *   @0xc90b4 str r0, [r4, #0x2c]
 *   @0xc90b8 pop {r4, r5, r6, pc}
 *   @0xc90bc ldr r0, [pc, #0xc]
 *   @0xc90c0 pop {r4, r5, r6, lr}
 *   @0xc90c4 add r0, pc, r0
 *   @0xc90c8 b 0xd547c <_Z7YYErrorPKcz>
 *   @0xc90cc eoreq r8, r6, r8, asr r12
 *   @0xc90d0 eoreq r8, r6, r0, lsr r12
 *
 * ══ §132/230 F_DsStackDestroy(RValue&, CInstance*, CInstance*, int, RValue*)  0xfb7e4  size 128  32 条（0xfb7e4..0xfb864）
 * @func 0xfb7e4 0xfb874  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_DsStackDestroy(RValue&, CInstance*, CInstance*, int, RValue*)+0x60
 * 字段偏移 top8: 0x4×3 / 0x2×2 / 0x10×1 / 0x54×1 / 0x44×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfb7e4 push {r3, r4, r5, lr}
 *   @0xfb7e8 mov r1, #0
 *   @0xfb7ec ldr r0, [sp, #0x10]
 *   @0xfb7f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfb7f4 subs r4, r0, #0
 *   @0xfb7f8 blt 0xfb844 <_Z16F_DsStackDestroyR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0xfb7fc ldr r3, [pc, #0x54]
 *   @0xfb800 ldr r3, [pc, r3]
 *   @0xfb804 ldr r3, [r3]
 *   @0xfb808 cmp r4, r3
 *   @0xfb80c bge 0xfb844 <_Z16F_DsStackDestroyR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0xfb810 ldr r5, [pc, #0x44]
 *   @0xfb814 ldr r5, [pc, r5]
 *   @0xfb818 ldr r3, [r5, #0x4]
 *   @0xfb81c ldr r0, [r3, r4, lsl #2]
 *   @0xfb820 cmp r0, #0
 *   @0xfb824 beq 0xfb844 <_Z16F_DsStackDestroyR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0xfb828 ldr r3, [r0]
 *   @0xfb82c ldr r3, [r3, #0x4]
 *   @0xfb830 blx r3
 *   @0xfb834 ldr r3, [r5, #0x4]
 *   @0xfb838 mov r2, #0
 *   @0xfb83c str r2, [r3, r4, lsl #2]
 *   @0xfb840 pop {r3, r4, r5, pc}
 *   @0xfb844 ldr r0, [pc, #0x14]
 *   @0xfb848 mov r1, #0
 *   @0xfb84c pop {r3, r4, r5, lr}
 *   @0xfb850 add r0, pc, r0
 *   @0xfb854 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfb858 eoreq r2, pc, r12, ror r6
 *   @0xfb85c eoreq r2, pc, r12, ror #12
 *   @0xfb860 eoreq r12, r3, r12, lsr #7
 *
 * ══ §133/230 F_DsQueueDestroy(RValue&, CInstance*, CInstance*, int, RValue*)  0xfb864  size 128  32 条（0xfb864..0xfb8e4）
 * @func 0xfb864 0xfb8f4  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_DsQueueDestroy(RValue&, CInstance*, CInstance*, int, RValue*)+0x60
 * 字段偏移 top8: 0x4×3 / 0x2×2 / 0x10×1 / 0x54×1 / 0x44×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfb864 push {r3, r4, r5, lr}
 *   @0xfb868 mov r1, #0
 *   @0xfb86c ldr r0, [sp, #0x10]
 *   @0xfb870 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfb874 subs r4, r0, #0
 *   @0xfb878 blt 0xfb8c4 <_Z16F_DsQueueDestroyR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0xfb87c ldr r3, [pc, #0x54]
 *   @0xfb880 ldr r3, [pc, r3]
 *   @0xfb884 ldr r3, [r3]
 *   @0xfb888 cmp r4, r3
 *   @0xfb88c bge 0xfb8c4 <_Z16F_DsQueueDestroyR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0xfb890 ldr r5, [pc, #0x44]
 *   @0xfb894 ldr r5, [pc, r5]
 *   @0xfb898 ldr r3, [r5, #0x4]
 *   @0xfb89c ldr r0, [r3, r4, lsl #2]
 *   @0xfb8a0 cmp r0, #0
 *   @0xfb8a4 beq 0xfb8c4 <_Z16F_DsQueueDestroyR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0xfb8a8 ldr r3, [r0]
 *   @0xfb8ac ldr r3, [r3, #0x4]
 *   @0xfb8b0 blx r3
 *   @0xfb8b4 ldr r3, [r5, #0x4]
 *   @0xfb8b8 mov r2, #0
 *   @0xfb8bc str r2, [r3, r4, lsl #2]
 *   @0xfb8c0 pop {r3, r4, r5, pc}
 *   @0xfb8c4 ldr r0, [pc, #0x14]
 *   @0xfb8c8 mov r1, #0
 *   @0xfb8cc pop {r3, r4, r5, lr}
 *   @0xfb8d0 add r0, pc, r0
 *   @0xfb8d4 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfb8d8 eoreq r2, pc, r12, ror #11
 *   @0xfb8dc .word 0x002f25dc
 *   @0xfb8e0 eoreq r12, r3, r12, lsr #6
 *
 * ══ §134/230 F_DsListDestroy(RValue&, CInstance*, CInstance*, int, RValue*)  0xfb8e4  size 128  32 条（0xfb8e4..0xfb964）
 * @func 0xfb8e4 0xfb974  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_DsListDestroy(RValue&, CInstance*, CInstance*, int, RValue*)+0x60
 * 字段偏移 top8: 0x4×3 / 0x2×2 / 0x10×1 / 0x54×1 / 0x44×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfb8e4 push {r3, r4, r5, lr}
 *   @0xfb8e8 mov r1, #0
 *   @0xfb8ec ldr r0, [sp, #0x10]
 *   @0xfb8f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfb8f4 subs r4, r0, #0
 *   @0xfb8f8 blt 0xfb944 <_Z15F_DsListDestroyR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0xfb8fc ldr r3, [pc, #0x54]
 *   @0xfb900 ldr r3, [pc, r3]
 *   @0xfb904 ldr r3, [r3]
 *   @0xfb908 cmp r4, r3
 *   @0xfb90c bge 0xfb944 <_Z15F_DsListDestroyR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0xfb910 ldr r5, [pc, #0x44]
 *   @0xfb914 ldr r5, [pc, r5]
 *   @0xfb918 ldr r3, [r5, #0x4]
 *   @0xfb91c ldr r0, [r3, r4, lsl #2]
 *   @0xfb920 cmp r0, #0
 *   @0xfb924 popeq {r3, r4, r5, pc}
 *   @0xfb928 ldr r3, [r0]
 *   @0xfb92c ldr r3, [r3, #0x4]
 *   @0xfb930 blx r3
 *   @0xfb934 ldr r3, [r5, #0x4]
 *   @0xfb938 mov r2, #0
 *   @0xfb93c str r2, [r3, r4, lsl #2]
 *   @0xfb940 pop {r3, r4, r5, pc}
 *   @0xfb944 ldr r0, [pc, #0x14]
 *   @0xfb948 mov r1, #0
 *   @0xfb94c pop {r3, r4, r5, lr}
 *   @0xfb950 add r0, pc, r0
 *   @0xfb954 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfb958 eoreq r2, pc, r12, ror r3
 *   @0xfb95c eoreq r2, pc, r12, ror #6
 *   @0xfb960 eoreq r12, r3, r12, lsr #5
 *
 * ══ §135/230 F_DsPriorityDestroy(RValue&, CInstance*, CInstance*, int, RValue*)  0xfb964  size 128  32 条（0xfb964..0xfb9e4）
 * @func 0xfb964 0xfb9e4  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_DsPriorityDestroy(RValue&, CInstance*, CInstance*, int, RValue*)+0x60
 * 字段偏移 top8: 0x4×3 / 0x2×2 / 0x10×1 / 0x54×1 / 0x44×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfb964 push {r3, r4, r5, lr}
 *   @0xfb968 mov r1, #0
 *   @0xfb96c ldr r0, [sp, #0x10]
 *   @0xfb970 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfb974 subs r4, r0, #0
 *   @0xfb978 blt 0xfb9c4 <_Z19F_DsPriorityDestroyR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0xfb97c ldr r3, [pc, #0x54]
 *   @0xfb980 ldr r3, [pc, r3]
 *   @0xfb984 ldr r3, [r3]
 *   @0xfb988 cmp r4, r3
 *   @0xfb98c bge 0xfb9c4 <_Z19F_DsPriorityDestroyR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0xfb990 ldr r5, [pc, #0x44]
 *   @0xfb994 ldr r5, [pc, r5]
 *   @0xfb998 ldr r3, [r5, #0x4]
 *   @0xfb99c ldr r0, [r3, r4, lsl #2]
 *   @0xfb9a0 cmp r0, #0
 *   @0xfb9a4 beq 0xfb9c4 <_Z19F_DsPriorityDestroyR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0xfb9a8 ldr r3, [r0]
 *   @0xfb9ac ldr r3, [r3, #0x4]
 *   @0xfb9b0 blx r3
 *   @0xfb9b4 ldr r3, [r5, #0x4]
 *   @0xfb9b8 mov r2, #0
 *   @0xfb9bc str r2, [r3, r4, lsl #2]
 *   @0xfb9c0 pop {r3, r4, r5, pc}
 *   @0xfb9c4 ldr r0, [pc, #0x14]
 *   @0xfb9c8 mov r1, #0
 *   @0xfb9cc pop {r3, r4, r5, lr}
 *   @0xfb9d0 add r0, pc, r0
 *   @0xfb9d4 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfb9d8 .word 0x002f24f4
 *   @0xfb9dc eoreq r2, pc, r4, ror #9
 *   @0xfb9e0 eoreq r12, r3, r12, lsr #4
 *
 * ══ §136/230 F_PathStart(RValue&, CInstance*, CInstance*, int, RValue*)  0x10884c  size 128  32 条（0x10884c..0x1088cc）
 * @func 0x10884c 0x1088cc  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / YYGetFloat(RValue const*, int) / YYGetBool(RValue const*, int) / CInstance::Assign_Path(int, float, float, float, bool, int)
 * 字段偏移 top8: 0x28×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10884c push {r4, r5, r6, r7, r8, lr}
 *   @0x108850 sub sp, sp, #16
 *   @0x108854 mov r5, r1
 *   @0x108858 mov r1, #0
 *   @0x10885c ldr r4, [sp, #0x28]
 *   @0x108860 mov r0, r4
 *   @0x108864 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x108868 mov r1, #1
 *   @0x10886c mov r7, r0
 *   @0x108870 mov r0, r4
 *   @0x108874 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x108878 mov r1, #3
 *   @0x10887c mov r6, r0
 *   @0x108880 mov r0, r4
 *   @0x108884 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x108888 mov r1, #2
 *   @0x10888c mov r8, r0
 *   @0x108890 mov r0, r4
 *   @0x108894 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x108898 eor r3, r8, #1
 *   @0x10889c mov r12, #0
 *   @0x1088a0 mov r1, r7
 *   @0x1088a4 mov r2, r6
 *   @0x1088a8 uxtb r3, r3
 *   @0x1088ac str r12, [sp]
 *   @0x1088b0 str r3, [sp, #0x4]
 *   @0x1088b4 mov r3, #1065353216
 *   @0x1088b8 str r0, [sp, #0x8]
 *   @0x1088bc mov r0, r5
 *   @0x1088c0 bl 0x193fe0 <_ZN9CInstance11Assign_PathEifffbi>
 *   @0x1088c4 add sp, sp, #16
 *   @0x1088c8 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §137/230 YYGML_instance_exists(CInstance*, CInstance*, int)  0x10af14  size 128  32 条（0x10af14..0x10af94）
 * @func 0x10af14 0x10af94  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: WithObjIterator::operator*()×2 / WithObjIterator::WithObjIterator(int, CInstance*, CInstance*, bool) / WithObjIterator::Next()
 * 字段偏移 top8: 0x68×1 / 0x69×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10af14 push {r4, r5, lr}
 *   @0x10af18 sub sp, sp, #52
 *   @0x10af1c add r4, sp, #12
 *   @0x10af20 mov r12, r0
 *   @0x10af24 mov r3, r1
 *   @0x10af28 mov r1, r2
 *   @0x10af2c mov r0, r4
 *   @0x10af30 mov r2, r12
 *   @0x10af34 mov r12, #0
 *   @0x10af38 str r12, [sp]
 *   @0x10af3c bl 0x19d060 <_ZN15WithObjIteratorC2EiP9CInstanceS1_b>
 *   @0x10af40 mov r0, r4
 *   @0x10af44 bl 0x19de4c <_ZN15WithObjIteratordeEv>
 *   @0x10af48 subs r3, r0, #0
 *   @0x10af4c mov r0, r4
 *   @0x10af50 beq 0x10af88 <_Z21YYGML_instance_existsP9CInstanceS0_i+0x74>
 *   @0x10af54 bl 0x19de4c <_ZN15WithObjIteratordeEv>
 *   @0x10af58 mov r5, r0
 *   @0x10af5c mov r0, r4
 *   @0x10af60 bl 0x19d1c8 <_ZN15WithObjIterator4NextEv>
 *   @0x10af64 ldrb r3, [r5, #0x68]
 *   @0x10af68 cmp r3, #0
 *   @0x10af6c bne 0x10af40 <_Z21YYGML_instance_existsP9CInstanceS0_i+0x2c>
 *   @0x10af70 ldrb r3, [r5, #0x69]
 *   @0x10af74 cmp r3, #0
 *   @0x10af78 bne 0x10af40 <_Z21YYGML_instance_existsP9CInstanceS0_i+0x2c>
 *   @0x10af7c mov r0, #1
 *   @0x10af80 add sp, sp, #52
 *   @0x10af84 pop {r4, r5, pc}
 *   @0x10af88 mov r0, r3
 *   @0x10af8c add sp, sp, #52
 *   @0x10af90 pop {r4, r5, pc}
 *
 * ══ §138/230 F_DArcTan2(RValue&, CInstance*, CInstance*, int, RValue*)  0x10ea9c  size 128  32 条（0x10ea9c..0x10eb1c）
 * @func 0x10ea9c 0x10eb1c  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / 0xb6778
 * 字段偏移 top8: 0x10×1 / 0xc×1
 * VFP 指令 11 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10ea9c push {r4, r5, r6, lr}
 *   @0x10eaa0 mov r1, #0
 *   @0x10eaa4 ldr r5, [sp, #0x10]
 *   @0x10eaa8 mov r4, r0
 *   @0x10eaac str r1, [r0, #0xc]
 *   @0x10eab0 mov r0, r5
 *   @0x10eab4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10eab8 mov r1, #1
 *   @0x10eabc mov r6, r0
 *   @0x10eac0 mov r0, r5
 *   @0x10eac4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10eac8 mov r1, r0
 *   @0x10eacc mov r0, r6
 *   @0x10ead0 bl 0xb6778 <atan2f@plt>
 *   @0x10ead4 vldr s15, [pc, #52]
 *   @0x10ead8 vldr s13, [pc, #52]
 *   @0x10eadc vldr s14, [pc, #52]
 *   @0x10eae0 vmov s12, r0
 *   @0x10eae4 vmul.f32 s15, s12, s15
 *   @0x10eae8 vdiv.f32 s15, s15, s13
 *   @0x10eaec vabs.f32 s13, s15
 *   @0x10eaf0 vcmpe.f32 s13, s14
 *   @0x10eaf4 vmrs APSR_nzcv, fpscr
 *   @0x10eaf8 vcvtpl.f64.f32 d6, s15
 *   @0x10eafc movmi r2, #0
 *   @0x10eb00 movmi r3, #0
 *   @0x10eb04 vmovpl r2, r3, d6
 *   @0x10eb08 stm r4, {r2, r3}
 *   @0x10eb0c pop {r4, r5, r6, pc}
 *   @0x10eb10 teqmi r4, #0
 *   @0x10eb14 ldrdmi r0, r1, [r9], #-251
 *   @0x10eb18 strlo r12, [r7, -r12, lsr #11]!
 *
 * ══ §139/230 F_Mean(RValue&, CInstance*, CInstance*, int, RValue*)  0x10f6f0  size 128  30 条（0x10f6f0..0x10f770）
 * @func 0x10f6f0 0x10f768  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_Mean(RValue&, CInstance*, CInstance*, int, RValue*)+0x50 / YYGetReal(RValue const*, int)
 * 字段偏移 top8: 0xc×2 / 0x20×1 / 0x4×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10f6f0 push {r3, r4, r5, r6, r7, lr}
 *   @0x10f6f4 vpush {d8}
 *   @0x10f6f8 subs r5, r3, #0
 *   @0x10f6fc mov r4, #0
 *   @0x10f700 mov r7, r0
 *   @0x10f704 ldr r6, [sp, #0x20]
 *   @0x10f708 str r4, [r0, #0xc]
 *   @0x10f70c str r4, [r0]
 *   @0x10f710 str r4, [r0, #0x4]
 *   @0x10f714 beq 0x10f75c <_Z6F_MeanR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x10f718 vldr d8, [pc, #72]
 *   @0x10f71c ble 0x10f740 <_Z6F_MeanR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x10f720 mov r1, r4
 *   @0x10f724 mov r0, r6
 *   @0x10f728 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x10f72c add r4, r4, #1
 *   @0x10f730 cmp r4, r5
 *   @0x10f734 vmov d6, r0, r1
 *   @0x10f738 vadd.f64 d8, d8, d6
 *   @0x10f73c bne 0x10f720 <_Z6F_MeanR6RValueP9CInstanceS2_iPS_+0x30>
 *   @0x10f740 vmov s13, r5
 *   @0x10f744 mov r3, #0
 *   @0x10f748 str r3, [r7, #0xc]
 *   @0x10f74c vcvt.f64.s32 d7, s13
 *   @0x10f750 vdiv.f64 d6, d8, d7
 *   @0x10f754 vmov r2, r3, d6
 *   @0x10f758 stm r7, {r2, r3}
 *   @0x10f75c vpop {d8}
 *   @0x10f760 pop {r3, r4, r5, r6, r7, pc}
 *   @0x10f764 nop
 *
 * ══ §140/230 utf8_strcmp  0x1109f4  size 128  32 条（0x1109f4..0x110a74）
 * @func 0x1109f4 0x110a74  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: utf8_extract_char×4
 * 字段偏移 top8: 0x4×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1109f4 push {r4, r5, r6, r7, r8, lr}
 *   @0x1109f8 sub sp, sp, #8
 *   @0x1109fc add r7, sp, #4
 *   @0x110a00 str r0, [sp, #0x4]
 *   @0x110a04 str r1, [sp]
 *   @0x110a08 b 0x110a34 <utf8_strcmp+0x40>
 *   @0x110a0c ldr r5, [sp]
 *   @0x110a10 ldrb r3, [r5]
 *   @0x110a14 cmp r3, #0
 *   @0x110a18 beq 0x110a48 <utf8_strcmp+0x54>
 *   @0x110a1c bl 0x10fb38 <utf8_extract_char>
 *   @0x110a20 mov r6, r0
 *   @0x110a24 mov r0, sp
 *   @0x110a28 bl 0x10fb38 <utf8_extract_char>
 *   @0x110a2c cmp r6, r0
 *   @0x110a30 bne 0x110a68 <utf8_strcmp+0x74>
 *   @0x110a34 ldr r4, [sp, #0x4]
 *   @0x110a38 mov r0, r7
 *   @0x110a3c ldrb r3, [r4]
 *   @0x110a40 cmp r3, #0
 *   @0x110a44 bne 0x110a0c <utf8_strcmp+0x18>
 *   @0x110a48 mov r0, r7
 *   @0x110a4c bl 0x10fb38 <utf8_extract_char>
 *   @0x110a50 mov r4, r0
 *   @0x110a54 mov r0, sp
 *   @0x110a58 bl 0x10fb38 <utf8_extract_char>
 *   @0x110a5c rsb r0, r0, r4
 *   @0x110a60 add sp, sp, #8
 *   @0x110a64 pop {r4, r5, r6, r7, r8, pc}
 *   @0x110a68 str r4, [sp, #0x4]
 *   @0x110a6c str r5, [sp]
 *   @0x110a70 b 0x110a48 <utf8_strcmp+0x54>
 *
 * ══ §141/230 iScript_Random(long long)  0x110d18  size 128  32 条（0x110d18..0x110d98）
 * @func 0x110d18 0x110d98  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYRandom()×2 / anon_319414
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x110d18 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x110d1c mov r5, r1
 *   @0x110d20 mov r4, r0
 *   @0x110d24 bl 0xc44ec <_Z8YYRandomv>
 *   @0x110d28 mvn r7, #-2147483648
 *   @0x110d2c mvn r6, #0
 *   @0x110d30 mov r10, r0
 *   @0x110d34 bl 0xc44ec <_Z8YYRandomv>
 *   @0x110d38 mov r2, #0
 *   @0x110d3c mov r3, #0
 *   @0x110d40 cmp r4, r2
 *   @0x110d44 sbcs r3, r5, r3
 *   @0x110d48 mov r2, #0
 *   @0x110d4c orr r8, r2, r10
 *   @0x110d50 mov r3, r0
 *   @0x110d54 and r1, r3, r7
 *   @0x110d58 mvnlt r7, #0
 *   @0x110d5c movge r7, #1
 *   @0x110d60 mov r9, r0
 *   @0x110d64 and r0, r8, r6
 *   @0x110d68 mul r12, r7, r5
 *   @0x110d6c movge r8, r2
 *   @0x110d70 movlt r8, r7
 *   @0x110d74 mla r12, r8, r4, r12
 *   @0x110d78 umull r2, r3, r7, r4
 *   @0x110d7c add r3, r12, r3
 *   @0x110d80 bl 0x319414 <__aeabi_ldivmod>
 *   @0x110d84 mul r3, r7, r3
 *   @0x110d88 umull r0, r1, r7, r2
 *   @0x110d8c mla r2, r2, r8, r3
 *   @0x110d90 add r1, r2, r1
 *   @0x110d94 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *
 * ══ §142/230 F_StringReplaceAll(RValue&, CInstance*, CInstance*, int, RValue*)  0x111924  size 128  32 条（0x111924..0x1119a4）
 * @func 0x111924 0x1119a4  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)×3 / StringReplace(char const*&, char const*, char const*, char const*, bool) / YYCreateString(RValue*, char const*) / YYFree(void const*)
 * 字段偏移 top8: 0xc×2 / 0x28×1 / 0x-4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x111924 push {r4, r5, r6, r7, r8, lr}
 *   @0x111928 sub sp, sp, #16
 *   @0x11192c mov r3, #0
 *   @0x111930 add r5, sp, #16
 *   @0x111934 ldr r4, [sp, #0x28]
 *   @0x111938 mov r1, r3
 *   @0x11193c mov r6, r0
 *   @0x111940 str r3, [r5, #-0x4]!
 *   @0x111944 mov r0, r4
 *   @0x111948 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x11194c mov r1, #1
 *   @0x111950 mov r8, r0
 *   @0x111954 mov r0, r4
 *   @0x111958 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x11195c mov r1, #2
 *   @0x111960 mov r7, r0
 *   @0x111964 mov r0, r4
 *   @0x111968 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x11196c mov r12, #1
 *   @0x111970 mov r2, r7
 *   @0x111974 str r12, [sp]
 *   @0x111978 mov r1, r8
 *   @0x11197c mov r3, r0
 *   @0x111980 mov r0, r5
 *   @0x111984 bl 0x1116a4 <_Z13StringReplaceRPKcS0_S0_S0_b>
 *   @0x111988 mov r0, r6
 *   @0x11198c ldr r1, [sp, #0xc]
 *   @0x111990 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x111994 ldr r0, [sp, #0xc]
 *   @0x111998 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x11199c add sp, sp, #16
 *   @0x1119a0 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §143/230 F_SkeletonGetBoneData(RValue&, CInstance*, CInstance*, int, RValue*)  0x11d230  size 128  32 条（0x11d230..0x11d2b0）
 * @func 0x11d230 0x11d2c0  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::SkeletonAnimation() / YYGetString(RValue const*, int) / YYGetInt32(RValue const*, int) / CSkeletonInstance::GetBoneData(char const*, int)
 * 字段偏移 top8: 0x4×2 / 0xc×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11d230 push {r4, r5, r6, r7, r8, lr}
 *   @0x11d234 mov r4, r0
 *   @0x11d238 mov r5, #0
 *   @0x11d23c mov r3, #0
 *   @0x11d240 mov r0, r1
 *   @0x11d244 movt r3, #0xbff0
 *   @0x11d248 str r5, [r4, #0xc]
 *   @0x11d24c str r3, [r4, #0x4]
 *   @0x11d250 str r5, [r4]
 *   @0x11d254 ldr r6, [sp, #0x18]
 *   @0x11d258 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv>
 *   @0x11d25c subs r7, r0, #0
 *   @0x11d260 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x11d264 mov r1, r5
 *   @0x11d268 mov r0, r6
 *   @0x11d26c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x11d270 mov r1, #1
 *   @0x11d274 mov r8, r0
 *   @0x11d278 mov r0, r6
 *   @0x11d27c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11d280 mov r1, r8
 *   @0x11d284 mov r2, r0
 *   @0x11d288 mov r0, r7
 *   @0x11d28c bl 0xbfd18 <_ZN17CSkeletonInstance11GetBoneDataEPKci>
 *   @0x11d290 cmp r0, #0
 *   @0x11d294 moveq r5, r0
 *   @0x11d298 movne r3, r5
 *   @0x11d29c moveq r3, r5
 *   @0x11d2a0 movtne r3, #0x3ff0
 *   @0x11d2a4 str r5, [r4]
 *   @0x11d2a8 str r3, [r4, #0x4]
 *   @0x11d2ac pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §144/230 F_SkeletonSetBoneData(RValue&, CInstance*, CInstance*, int, RValue*)  0x11d2b0  size 128  32 条（0x11d2b0..0x11d330）
 * @func 0x11d2b0 0x11d340  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::SkeletonAnimation() / YYGetString(RValue const*, int) / YYGetInt32(RValue const*, int) / CSkeletonInstance::SetBoneData(char const*, int)
 * 字段偏移 top8: 0x4×2 / 0xc×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11d2b0 push {r4, r5, r6, r7, r8, lr}
 *   @0x11d2b4 mov r4, r0
 *   @0x11d2b8 mov r5, #0
 *   @0x11d2bc mov r3, #0
 *   @0x11d2c0 mov r0, r1
 *   @0x11d2c4 movt r3, #0xbff0
 *   @0x11d2c8 str r5, [r4, #0xc]
 *   @0x11d2cc str r3, [r4, #0x4]
 *   @0x11d2d0 str r5, [r4]
 *   @0x11d2d4 ldr r6, [sp, #0x18]
 *   @0x11d2d8 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv>
 *   @0x11d2dc subs r7, r0, #0
 *   @0x11d2e0 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x11d2e4 mov r1, r5
 *   @0x11d2e8 mov r0, r6
 *   @0x11d2ec bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x11d2f0 mov r1, #1
 *   @0x11d2f4 mov r8, r0
 *   @0x11d2f8 mov r0, r6
 *   @0x11d2fc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11d300 mov r1, r8
 *   @0x11d304 mov r2, r0
 *   @0x11d308 mov r0, r7
 *   @0x11d30c bl 0xc16c0 <_ZN17CSkeletonInstance11SetBoneDataEPKci>
 *   @0x11d310 cmp r0, #0
 *   @0x11d314 moveq r5, r0
 *   @0x11d318 movne r3, r5
 *   @0x11d31c moveq r3, r5
 *   @0x11d320 movtne r3, #0x3ff0
 *   @0x11d324 str r5, [r4]
 *   @0x11d328 str r3, [r4, #0x4]
 *   @0x11d32c pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §145/230 F_SkeletonGetBoneState(RValue&, CInstance*, CInstance*, int, RValue*)  0x11d330  size 128  32 条（0x11d330..0x11d3b0）
 * @func 0x11d330 0x11d3c0  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::SkeletonAnimation() / YYGetString(RValue const*, int) / YYGetInt32(RValue const*, int) / CSkeletonInstance::GetBoneState(char const*, int)
 * 字段偏移 top8: 0x4×2 / 0xc×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11d330 push {r4, r5, r6, r7, r8, lr}
 *   @0x11d334 mov r4, r0
 *   @0x11d338 mov r5, #0
 *   @0x11d33c mov r3, #0
 *   @0x11d340 mov r0, r1
 *   @0x11d344 movt r3, #0xbff0
 *   @0x11d348 str r5, [r4, #0xc]
 *   @0x11d34c str r3, [r4, #0x4]
 *   @0x11d350 str r5, [r4]
 *   @0x11d354 ldr r6, [sp, #0x18]
 *   @0x11d358 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv>
 *   @0x11d35c subs r7, r0, #0
 *   @0x11d360 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x11d364 mov r1, r5
 *   @0x11d368 mov r0, r6
 *   @0x11d36c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x11d370 mov r1, #1
 *   @0x11d374 mov r8, r0
 *   @0x11d378 mov r0, r6
 *   @0x11d37c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11d380 mov r1, r8
 *   @0x11d384 mov r2, r0
 *   @0x11d388 mov r0, r7
 *   @0x11d38c bl 0xbfea8 <_ZN17CSkeletonInstance12GetBoneStateEPKci>
 *   @0x11d390 cmp r0, #0
 *   @0x11d394 moveq r5, r0
 *   @0x11d398 movne r3, r5
 *   @0x11d39c moveq r3, r5
 *   @0x11d3a0 movtne r3, #0x3ff0
 *   @0x11d3a4 str r5, [r4]
 *   @0x11d3a8 str r3, [r4, #0x4]
 *   @0x11d3ac pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §146/230 F_SkeletonSetBoneState(RValue&, CInstance*, CInstance*, int, RValue*)  0x11d3b0  size 128  32 条（0x11d3b0..0x11d430）
 * @func 0x11d3b0 0x11d430  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::SkeletonAnimation() / YYGetString(RValue const*, int) / YYGetInt32(RValue const*, int) / CSkeletonInstance::SetBoneState(char const*, int)
 * 字段偏移 top8: 0x4×2 / 0xc×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11d3b0 push {r4, r5, r6, r7, r8, lr}
 *   @0x11d3b4 mov r4, r0
 *   @0x11d3b8 mov r5, #0
 *   @0x11d3bc mov r3, #0
 *   @0x11d3c0 mov r0, r1
 *   @0x11d3c4 movt r3, #0xbff0
 *   @0x11d3c8 str r5, [r4, #0xc]
 *   @0x11d3cc str r3, [r4, #0x4]
 *   @0x11d3d0 str r5, [r4]
 *   @0x11d3d4 ldr r6, [sp, #0x18]
 *   @0x11d3d8 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv>
 *   @0x11d3dc subs r7, r0, #0
 *   @0x11d3e0 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x11d3e4 mov r1, r5
 *   @0x11d3e8 mov r0, r6
 *   @0x11d3ec bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x11d3f0 mov r1, #1
 *   @0x11d3f4 mov r8, r0
 *   @0x11d3f8 mov r0, r6
 *   @0x11d3fc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11d400 mov r1, r8
 *   @0x11d404 mov r2, r0
 *   @0x11d408 mov r0, r7
 *   @0x11d40c bl 0xc1480 <_ZN17CSkeletonInstance12SetBoneStateEPKci>
 *   @0x11d410 cmp r0, #0
 *   @0x11d414 moveq r5, r0
 *   @0x11d418 movne r3, r5
 *   @0x11d41c moveq r3, r5
 *   @0x11d420 movtne r3, #0x3ff0
 *   @0x11d424 str r5, [r4]
 *   @0x11d428 str r3, [r4, #0x4]
 *   @0x11d42c pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §147/230 F_HighscoreSetFont(RValue&, CInstance*, CInstance*, int, RValue*)  0x12766c  size 128  32 条（0x12766c..0x1276ec）
 * @func 0x12766c 0x1276ec  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int) / YYGetInt32(RValue const*, int) / operator new(unsigned int) / 0xb6538 / YYStrDup(char const*)
 * 字段偏移 top8: 0x20×2 / 0x10×1 / 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12766c push {r4, r5, r6, lr}
 *   @0x127670 mov r1, #0
 *   @0x127674 ldr r4, [sp, #0x10]
 *   @0x127678 mov r0, r4
 *   @0x12767c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x127680 mov r1, #1
 *   @0x127684 mov r5, r0
 *   @0x127688 mov r0, r4
 *   @0x12768c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x127690 cmp r5, #0
 *   @0x127694 mov r6, r0
 *   @0x127698 popeq {r4, r5, r6, pc}
 *   @0x12769c mov r0, #12
 *   @0x1276a0 bl 0x27c524 <_Znwj>
 *   @0x1276a4 mov r4, r0
 *   @0x1276a8 mov r0, r5
 *   @0x1276ac bl 0xb6538 <strlen@plt>
 *   @0x1276b0 str r0, [r4, #0x8]
 *   @0x1276b4 mov r0, r5
 *   @0x1276b8 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x1276bc ldr r2, [pc, #0x20]
 *   @0x1276c0 ldr r3, [pc, #0x20]
 *   @0x1276c4 mov r1, #1
 *   @0x1276c8 ldr r2, [pc, r2]
 *   @0x1276cc str r1, [r4, #0x4]
 *   @0x1276d0 ldr r3, [pc, r3]
 *   @0x1276d4 str r0, [r4]
 *   @0x1276d8 str r4, [r2]
 *   @0x1276dc str r6, [r3]
 *   @0x1276e0 pop {r4, r5, r6, pc}
 *   @0x1276e4 eoreq r7, r12, r4, asr #7
 *   @0x1276e8 eoreq r7, r12, r0, asr #7
 *
 * ══ §148/230 F_PathAppend(RValue&, CInstance*, CInstance*, int, RValue*)  0x12f92c  size 128  32 条（0x12f92c..0x12f9ac）
 * @func 0x12f92c 0x12f9ac  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / Path_Data(int)×2 / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x10×2 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12f92c push {r4, r5, r6, lr}
 *   @0x12f930 mov r1, #0
 *   @0x12f934 ldr r4, [sp, #0x10]
 *   @0x12f938 mov r0, r4
 *   @0x12f93c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12f940 mov r1, #1
 *   @0x12f944 mov r5, r0
 *   @0x12f948 mov r0, r4
 *   @0x12f94c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12f950 mov r6, r0
 *   @0x12f954 mov r0, r5
 *   @0x12f958 bl 0x1a815c <_Z9Path_Datai>
 *   @0x12f95c mov r4, r0
 *   @0x12f960 mov r0, r6
 *   @0x12f964 bl 0x1a815c <_Z9Path_Datai>
 *   @0x12f968 cmp r4, #0
 *   @0x12f96c mov r1, r0
 *   @0x12f970 beq 0x12f980 <_Z12F_PathAppendR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x12f974 mov r0, r4
 *   @0x12f978 pop {r4, r5, r6, lr}
 *   @0x12f97c b 0x1a79e8 <_ZN5CPath6AppendEPS_>
 *   @0x12f980 ldr r0, [pc, #0x1c]
 *   @0x12f984 mov r1, r4
 *   @0x12f988 add r0, pc, r0
 *   @0x12f98c bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x12f990 ldr r0, [pc, #0x10]
 *   @0x12f994 mov r1, r4
 *   @0x12f998 add r0, pc, r0
 *   @0x12f99c pop {r4, r5, r6, lr}
 *   @0x12f9a0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x12f9a4 .word 0x0020dff8
 *   @0x12f9a8 eoreq lr, r0, r8
 *
 * ══ §149/230 F_ActionPath(RValue&, CInstance*, CInstance*, int, RValue*)  0x13e028  size 128  32 条（0x13e028..0x13e0a8）
 * @func 0x13e028 0x13e0a8  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / YYGetFloat(RValue const*, int) / YYGetBool(RValue const*, int) / CInstance::Assign_Path(int, float, float, float, bool, int)
 * 字段偏移 top8: 0x28×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13e028 push {r4, r5, r6, r7, r8, lr}
 *   @0x13e02c sub sp, sp, #16
 *   @0x13e030 mov r5, r1
 *   @0x13e034 mov r1, #0
 *   @0x13e038 ldr r4, [sp, #0x28]
 *   @0x13e03c mov r0, r4
 *   @0x13e040 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13e044 mov r1, #1
 *   @0x13e048 mov r7, r0
 *   @0x13e04c mov r0, r4
 *   @0x13e050 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13e054 mov r1, #3
 *   @0x13e058 mov r6, r0
 *   @0x13e05c mov r0, r4
 *   @0x13e060 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x13e064 mov r1, #2
 *   @0x13e068 mov r8, r0
 *   @0x13e06c mov r0, r4
 *   @0x13e070 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13e074 eor r3, r8, #1
 *   @0x13e078 mov r12, #0
 *   @0x13e07c mov r1, r7
 *   @0x13e080 mov r2, r6
 *   @0x13e084 uxtb r3, r3
 *   @0x13e088 str r12, [sp]
 *   @0x13e08c str r3, [sp, #0x4]
 *   @0x13e090 mov r3, #1065353216
 *   @0x13e094 str r0, [sp, #0x8]
 *   @0x13e098 mov r0, r5
 *   @0x13e09c bl 0x193fe0 <_ZN9CInstance11Assign_PathEifffbi>
 *   @0x13e0a0 add sp, sp, #16
 *   @0x13e0a4 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §150/230 F_ActionKillPosition(RValue&, CInstance*, CInstance*, int, RValue*)  0x13e510  size 128  32 条（0x13e510..0x13e590）
 * @func 0x13e510 0x13e590  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2
 * 字段偏移 top8: 0x18×1 / 0x48×1
 * VFP 指令 13 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13e510 push {r3, r4, r5, lr}
 *   @0x13e514 vpush {d8}
 *   @0x13e518 mov r5, r1
 *   @0x13e51c ldr r4, [sp, #0x18]
 *   @0x13e520 mov r1, #0
 *   @0x13e524 mov r0, r4
 *   @0x13e528 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13e52c mov r1, #1
 *   @0x13e530 vmov s16, r0
 *   @0x13e534 mov r0, r4
 *   @0x13e538 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13e53c ldr r3, [pc, #0x48]
 *   @0x13e540 ldr r3, [pc, r3]
 *   @0x13e544 ldrb r3, [r3]
 *   @0x13e548 cmp r3, #0
 *   @0x13e54c vmov s15, r0
 *   @0x13e550 bne 0x13e568 <_Z20F_ActionKillPositionR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x13e554 vmov r0, s16
 *   @0x13e558 vpop {d8}
 *   @0x13e55c vmov r1, s15
 *   @0x13e560 pop {r3, r4, r5, lr}
 *   @0x13e564 b 0x1c9c88 <_Z17Command_DestroyAtff>
 *   @0x13e568 vldr s13, [r5, #180]
 *   @0x13e56c vldr s14, [r5, #184]
 *   @0x13e570 vadd.f32 s13, s16, s13
 *   @0x13e574 vpop {d8}
 *   @0x13e578 pop {r3, r4, r5, lr}
 *   @0x13e57c vadd.f32 s14, s15, s14
 *   @0x13e580 vmov r0, s13
 *   @0x13e584 vmov r1, s14
 *   @0x13e588 b 0x1c9c88 <_Z17Command_DestroyAtff>
 *   @0x13e58c .word 0x002af5fc
 *
 * ══ §151/230 F_ActionIfDice(RValue&, CInstance*, CInstance*, int, RValue*)  0x13e7f8  size 128  32 条（0x13e7f8..0x13e878）
 * @func 0x13e7f8 0x13e878  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int) / F_ActionIfDice(RValue&, CInstance*, CInstance*, int, RValue*)+0x60 / 0xb66e8 / YYRandom(int)
 * 字段偏移 top8: 0x4×2 / 0x10×1 / 0xc×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13e7f8 push {r3, r4, r5, lr}
 *   @0x13e7fc mov r1, #0
 *   @0x13e800 mov r4, r0
 *   @0x13e804 ldr r0, [sp, #0x10]
 *   @0x13e808 mov r5, r1
 *   @0x13e80c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x13e810 vmov.f64 d6, #1.000000e+00
 *   @0x13e814 str r5, [r4, #0xc]
 *   @0x13e818 vmov d7, r0, r1
 *   @0x13e81c vcmpe.f64 d7, d6
 *   @0x13e820 vmrs APSR_nzcv, fpscr
 *   @0x13e824 bls 0x13e858 <_Z14F_ActionIfDiceR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0x13e828 vldr d6, [pc, #64]
 *   @0x13e82c vmul.f64 d5, d7, d6
 *   @0x13e830 vmov r0, r1, d5
 *   @0x13e834 bl 0xb66e8 <lrint@plt>
 *   @0x13e838 bl 0xc4600 <_Z8YYRandomi>
 *   @0x13e83c str r5, [r4]
 *   @0x13e840 cmp r0, #1000
 *   @0x13e844 movls r3, #0
 *   @0x13e848 movhi r3, r5
 *   @0x13e84c movtls r3, #0x3ff0
 *   @0x13e850 str r3, [r4, #0x4]
 *   @0x13e854 pop {r3, r4, r5, pc}
 *   @0x13e858 mov r3, r5
 *   @0x13e85c str r5, [r4]
 *   @0x13e860 movt r3, #0x3ff0
 *   @0x13e864 str r3, [r4, #0x4]
 *   @0x13e868 pop {r3, r4, r5, pc}
 *   @0x13e86c nop
 *   @0x13e870 andeq r0, r0, r0
 *   @0x13e874 addmi r4, pc, r0
 *
 * ══ §152/230 F_ActionCreateObjectMotion(RValue&, CInstance*, CInstance*, int, RValue*)  0x141a14  size 128  32 条（0x141a14..0x141a94）
 * @func 0x141a14 0x141a94  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×4 / YYGetInt32(RValue const*, int) / YYGML_action_create_object_motion(CInstance*, int, float, float, float, float)
 * 字段偏移 top8: 0x28×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x141a14 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x141a18 sub sp, sp, #12
 *   @0x141a1c mov r5, r1
 *   @0x141a20 mov r1, #0
 *   @0x141a24 ldr r4, [sp, #0x28]
 *   @0x141a28 mov r0, r4
 *   @0x141a2c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x141a30 mov r1, #1
 *   @0x141a34 mov r8, r0
 *   @0x141a38 mov r0, r4
 *   @0x141a3c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x141a40 mov r1, #2
 *   @0x141a44 mov r7, r0
 *   @0x141a48 mov r0, r4
 *   @0x141a4c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x141a50 mov r1, #3
 *   @0x141a54 mov r6, r0
 *   @0x141a58 mov r0, r4
 *   @0x141a5c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x141a60 mov r1, #4
 *   @0x141a64 mov r9, r0
 *   @0x141a68 mov r0, r4
 *   @0x141a6c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x141a70 str r9, [sp]
 *   @0x141a74 mov r1, r8
 *   @0x141a78 mov r2, r7
 *   @0x141a7c mov r3, r6
 *   @0x141a80 str r0, [sp, #0x4]
 *   @0x141a84 mov r0, r5
 *   @0x141a88 bl 0x1418bc <_Z33YYGML_action_create_object_motionP9CInstanceiffff>
 *   @0x141a8c add sp, sp, #12
 *   @0x141a90 pop {r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §153/230 F_D3DModelSave(RValue&, CInstance*, CInstance*, int, RValue*)  0x14538c  size 128  32 条（0x14538c..0x14540c）
 * @func 0x14538c 0x14540c  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int) / LoadSave::_GetSaveFileName(char*, int, char const*) / EnsureDirectoryIsCreated(char const*) / YYGetInt32(RValue const*, int) / GR_3DM_SaveToFile(int, char const*) / 0xb65d4
 * 字段偏移 top8: 0x404×2 / 0x6c×1 / 0x418×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14538c push {r4, r5, r6, lr}
 *   @0x145390 sub sp, sp, #1024
 *   @0x145394 ldr r4, [pc, #0x6c]
 *   @0x145398 sub sp, sp, #8
 *   @0x14539c mov r1, #1
 *   @0x1453a0 add r5, sp, #4
 *   @0x1453a4 ldr r4, [pc, r4]
 *   @0x1453a8 ldr r6, [sp, #0x418]
 *   @0x1453ac ldr r3, [r4]
 *   @0x1453b0 mov r0, r6
 *   @0x1453b4 str r3, [sp, #0x404]
 *   @0x1453b8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1453bc mov r1, #1024
 *   @0x1453c0 mov r2, r0
 *   @0x1453c4 mov r0, r5
 *   @0x1453c8 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0x1453cc mov r0, r5
 *   @0x1453d0 bl 0x13ad20 <_Z24EnsureDirectoryIsCreatedPKc>
 *   @0x1453d4 mov r1, #0
 *   @0x1453d8 mov r0, r6
 *   @0x1453dc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1453e0 mov r1, r5
 *   @0x1453e4 bl 0x1652e0 <_Z17GR_3DM_SaveToFileiPKc>
 *   @0x1453e8 ldr r2, [sp, #0x404]
 *   @0x1453ec ldr r3, [r4]
 *   @0x1453f0 cmp r2, r3
 *   @0x1453f4 bne 0x145404 <_Z14F_D3DModelSaveR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x1453f8 add sp, sp, #1024
 *   @0x1453fc add sp, sp, #8
 *   @0x145400 pop {r4, r5, r6, pc}
 *   @0x145404 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x145408 eoreq r8, r10, r12, lsr #11
 *
 * ══ §154/230 F_GPUGetTexRepeatExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x148644  size 128  32 条（0x148644..0x1486c4）
 * @func 0x148644 0x1486c4  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / RenderStateManager::GetSamplerState(int, eSamplerState)
 * 字段偏移 top8: 0x4×2 / 0x10×1 / 0xc×1 / 0x48×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x148644 cmp r3, #1
 *   @0x148648 push {r3, r4, r5, lr}
 *   @0x14864c mov r5, r0
 *   @0x148650 mov r4, #0
 *   @0x148654 ldr r0, [sp, #0x10]
 *   @0x148658 str r4, [r5, #0xc]
 *   @0x14865c mov r1, r4
 *   @0x148660 str r4, [r5]
 *   @0x148664 str r4, [r5, #0x4]
 *   @0x148668 beq 0x14867c <_Z20F_GPUGetTexRepeatExtR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x14866c ldr r0, [pc, #0x48]
 *   @0x148670 pop {r3, r4, r5, lr}
 *   @0x148674 add r0, pc, r0
 *   @0x148678 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14867c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x148680 cmp r0, #7
 *   @0x148684 pophi {r3, r4, r5, pc}
 *   @0x148688 ldr r3, [pc, #0x30]
 *   @0x14868c mov r1, r0
 *   @0x148690 mov r2, #2
 *   @0x148694 ldr r0, [pc, r3]
 *   @0x148698 bl 0x167fa0 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState>
 *   @0x14869c cmp r0, #0
 *   @0x1486a0 moveq r3, #0
 *   @0x1486a4 moveq r4, r0
 *   @0x1486a8 movteq r3, #0x3ff0
 *   @0x1486ac movne r3, r4
 *   @0x1486b0 str r4, [r5]
 *   @0x1486b4 str r3, [r5, #0x4]
 *   @0x1486b8 pop {r3, r4, r5, pc}
 *   @0x1486bc andseq r9, pc, r8, lsl #25
 *   @0x1486c0 eoreq r5, r10, r4, ror #12
 *
 * ══ §155/230 F_D3DFrustumTestSphere(RValue&, CInstance*, CInstance*, int, RValue*)  0x149d90  size 128  32 条（0x149d90..0x149e10）
 * @func 0x149d90 0x149e10  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×4 / Frustum_TestSphere(float, float, float, float)
 * 字段偏移 top8: 0x18×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x149d90 push {r4, r5, r6, r7, r8, lr}
 *   @0x149d94 mov r1, #0
 *   @0x149d98 ldr r4, [sp, #0x18]
 *   @0x149d9c mov r5, r0
 *   @0x149da0 mov r0, r4
 *   @0x149da4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x149da8 mov r1, #1
 *   @0x149dac mov r6, r0
 *   @0x149db0 mov r0, r4
 *   @0x149db4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x149db8 mov r1, #2
 *   @0x149dbc mov r8, r0
 *   @0x149dc0 mov r0, r4
 *   @0x149dc4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x149dc8 mov r1, #3
 *   @0x149dcc mov r7, r0
 *   @0x149dd0 mov r0, r4
 *   @0x149dd4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x149dd8 mov r1, r8
 *   @0x149ddc mov r12, #0
 *   @0x149de0 mov r2, r7
 *   @0x149de4 str r12, [r5, #0xc]
 *   @0x149de8 mov r3, r0
 *   @0x149dec mov r0, r6
 *   @0x149df0 bl 0x149d20 <_Z18Frustum_TestSphereffff>
 *   @0x149df4 vmov s15, r0
 *   @0x149df8 vcvt.f64.f32 d7, s15
 *   @0x149dfc vmov r0, r1, d7
 *   @0x149e00 vmov r2, s14
 *   @0x149e04 mov r3, r1
 *   @0x149e08 stm r5, {r2, r3}
 *   @0x149e0c pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §156/230 F_PhysicsApplyAngularImpulse(RValue&, CInstance*, CInstance*, int, RValue*)  0x14ca28  size 128  32 条（0x14ca28..0x14caa8）
 * @func 0x14ca28 0x14caa8  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x84×1 / 0x8×1 / 0x58×1 / 0xb4×1 / 0x24×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14ca28 push {r4, lr}
 *   @0x14ca2c ldr r4, [r1, #0x84]
 *   @0x14ca30 ldr r0, [sp, #0x8]
 *   @0x14ca34 cmp r4, #0
 *   @0x14ca38 beq 0x14ca88 <_Z28F_PhysicsApplyAngularImpulseR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0x14ca3c ldr r3, [pc, #0x58]
 *   @0x14ca40 ldr r3, [pc, r3]
 *   @0x14ca44 ldr r3, [r3]
 *   @0x14ca48 cmp r3, #0
 *   @0x14ca4c beq 0x14ca74 <_Z28F_PhysicsApplyAngularImpulseR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x14ca50 ldr r3, [r3, #0xb4]
 *   @0x14ca54 cmp r3, #0
 *   @0x14ca58 beq 0x14ca74 <_Z28F_PhysicsApplyAngularImpulseR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x14ca5c mov r1, #0
 *   @0x14ca60 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14ca64 mov r1, r0
 *   @0x14ca68 mov r0, r4
 *   @0x14ca6c pop {r4, lr}
 *   @0x14ca70 b 0x2372a4 <_ZN14CPhysicsObject19ApplyAngularImpulseEf>
 *   @0x14ca74 ldr r0, [pc, #0x24]
 *   @0x14ca78 mov r1, #0
 *   @0x14ca7c pop {r4, lr}
 *   @0x14ca80 add r0, pc, r0
 *   @0x14ca84 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14ca88 ldr r0, [pc, #0x14]
 *   @0x14ca8c mov r1, r4
 *   @0x14ca90 pop {r4, lr}
 *   @0x14ca94 add r0, pc, r0
 *   @0x14ca98 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14ca9c eoreq r0, r10, r8, ror #29
 *   @0x14caa0 andseq r7, pc, r4, lsr #7
 *   @0x14caa4 andseq r7, pc, r0, asr r3
 *
 * ══ §157/230 F_PhysicsParticleMaxCount(RValue&, CInstance*, CInstance*, int, RValue*)  0x14e718  size 128  32 条（0x14e718..0x14e798）
 * @func 0x14e718 0x14e7a8  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2World::GetParticleMaxCount() const
 * 字段偏移 top8: 0x10×2 / 0x70×1 / 0xc×1 / 0x4×1 / 0xb4×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14e718 ldr r3, [pc, #0x70]
 *   @0x14e71c mov r1, #0
 *   @0x14e720 push {r4, lr}
 *   @0x14e724 ldr r3, [pc, r3]
 *   @0x14e728 str r1, [r0]
 *   @0x14e72c mov r2, r1
 *   @0x14e730 ldr r3, [r3]
 *   @0x14e734 movt r2, #0xbff0
 *   @0x14e738 mov r4, r0
 *   @0x14e73c str r1, [r0, #0xc]
 *   @0x14e740 cmp r3, r1
 *   @0x14e744 str r2, [r0, #0x4]
 *   @0x14e748 beq 0x14e77c <_Z25F_PhysicsParticleMaxCountR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x14e74c ldr r3, [r3, #0xb4]
 *   @0x14e750 cmp r3, r1
 *   @0x14e754 beq 0x14e77c <_Z25F_PhysicsParticleMaxCountR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x14e758 ldr r0, [r3, #0x10]
 *   @0x14e75c bl 0x2cb42c <_ZNK7b2World19GetParticleMaxCountEv>
 *   @0x14e760 vmov s15, r0
 *   @0x14e764 vcvt.f64.s32 d7, s15
 *   @0x14e768 vmov r0, r1, d7
 *   @0x14e76c vmov r2, s14
 *   @0x14e770 mov r3, r1
 *   @0x14e774 stm r4, {r2, r3}
 *   @0x14e778 pop {r4, pc}
 *   @0x14e77c ldr r0, [pc, #0x10]
 *   @0x14e780 mov r1, #0
 *   @0x14e784 pop {r4, lr}
 *   @0x14e788 add r0, pc, r0
 *   @0x14e78c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14e790 eoreq pc, r9, r4, lsl #4
 *   @0x14e794 andseq r6, pc, r12, asr #5
 *
 * ══ §158/230 F_PhysicsParticleRadius(RValue&, CInstance*, CInstance*, int, RValue*)  0x14e798  size 128  32 条（0x14e798..0x14e818）
 * @func 0x14e798 0x14e828  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2World::GetParticleRadius() const
 * 字段偏移 top8: 0x10×2 / 0x68×1 / 0xc×1 / 0x4×1 / 0xb4×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14e798 push {r3, r4, r5, lr}
 *   @0x14e79c mov r1, #0
 *   @0x14e7a0 ldr r3, [pc, #0x68]
 *   @0x14e7a4 mov r2, r1
 *   @0x14e7a8 str r1, [r0]
 *   @0x14e7ac movt r2, #0xbff0
 *   @0x14e7b0 ldr r3, [pc, r3]
 *   @0x14e7b4 mov r4, r0
 *   @0x14e7b8 str r1, [r0, #0xc]
 *   @0x14e7bc ldr r3, [r3]
 *   @0x14e7c0 str r2, [r0, #0x4]
 *   @0x14e7c4 cmp r3, r1
 *   @0x14e7c8 beq 0x14e7fc <_Z23F_PhysicsParticleRadiusR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x14e7cc ldr r5, [r3, #0xb4]
 *   @0x14e7d0 cmp r5, r1
 *   @0x14e7d4 beq 0x14e7fc <_Z23F_PhysicsParticleRadiusR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x14e7d8 ldr r0, [r5, #0x10]
 *   @0x14e7dc bl 0x2cb498 <_ZNK7b2World17GetParticleRadiusEv>
 *   @0x14e7e0 vldr s15, [r5, #96]
 *   @0x14e7e4 vmov s12, r0
 *   @0x14e7e8 vdiv.f32 s15, s12, s15
 *   @0x14e7ec vcvt.f64.f32 d6, s15
 *   @0x14e7f0 vmov r2, r3, d6
 *   @0x14e7f4 stm r4, {r2, r3}
 *   @0x14e7f8 pop {r3, r4, r5, pc}
 *   @0x14e7fc ldr r0, [pc, #0x10]
 *   @0x14e800 mov r1, #0
 *   @0x14e804 pop {r3, r4, r5, lr}
 *   @0x14e808 add r0, pc, r0
 *   @0x14e80c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14e810 eoreq pc, r9, r8, ror r1
 *   @0x14e814 andseq r6, pc, r8, lsr #5
 *
 * ══ §159/230 F_PhysicsParticleDensity(RValue&, CInstance*, CInstance*, int, RValue*)  0x14e818  size 128  32 条（0x14e818..0x14e898）
 * @func 0x14e818 0x14e8a8  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2World::GetParticleDensity() const
 * 字段偏移 top8: 0x10×2 / 0x70×1 / 0xc×1 / 0x4×1 / 0xb4×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14e818 ldr r3, [pc, #0x70]
 *   @0x14e81c mov r1, #0
 *   @0x14e820 push {r4, lr}
 *   @0x14e824 ldr r3, [pc, r3]
 *   @0x14e828 str r1, [r0]
 *   @0x14e82c mov r2, r1
 *   @0x14e830 ldr r3, [r3]
 *   @0x14e834 movt r2, #0xbff0
 *   @0x14e838 mov r4, r0
 *   @0x14e83c str r1, [r0, #0xc]
 *   @0x14e840 cmp r3, r1
 *   @0x14e844 str r2, [r0, #0x4]
 *   @0x14e848 beq 0x14e87c <_Z24F_PhysicsParticleDensityR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x14e84c ldr r3, [r3, #0xb4]
 *   @0x14e850 cmp r3, r1
 *   @0x14e854 beq 0x14e87c <_Z24F_PhysicsParticleDensityR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x14e858 ldr r0, [r3, #0x10]
 *   @0x14e85c bl 0x2cb450 <_ZNK7b2World18GetParticleDensityEv>
 *   @0x14e860 vmov s15, r0
 *   @0x14e864 vcvt.f64.f32 d7, s15
 *   @0x14e868 vmov r0, r1, d7
 *   @0x14e86c vmov r2, s14
 *   @0x14e870 mov r3, r1
 *   @0x14e874 stm r4, {r2, r3}
 *   @0x14e878 pop {r4, pc}
 *   @0x14e87c ldr r0, [pc, #0x10]
 *   @0x14e880 mov r1, #0
 *   @0x14e884 pop {r4, lr}
 *   @0x14e888 add r0, pc, r0
 *   @0x14e88c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14e890 eoreq pc, r9, r4, lsl #2
 *   @0x14e894 andseq r6, pc, r0, lsl #5
 *
 * ══ §160/230 F_PhysicsParticleDamping(RValue&, CInstance*, CInstance*, int, RValue*)  0x14e898  size 128  32 条（0x14e898..0x14e918）
 * @func 0x14e898 0x14e928  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2World::GetParticleDamping() const
 * 字段偏移 top8: 0x10×2 / 0x70×1 / 0xc×1 / 0x4×1 / 0xb4×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14e898 ldr r3, [pc, #0x70]
 *   @0x14e89c mov r1, #0
 *   @0x14e8a0 push {r4, lr}
 *   @0x14e8a4 ldr r3, [pc, r3]
 *   @0x14e8a8 str r1, [r0]
 *   @0x14e8ac mov r2, r1
 *   @0x14e8b0 ldr r3, [r3]
 *   @0x14e8b4 movt r2, #0xbff0
 *   @0x14e8b8 mov r4, r0
 *   @0x14e8bc str r1, [r0, #0xc]
 *   @0x14e8c0 cmp r3, r1
 *   @0x14e8c4 str r2, [r0, #0x4]
 *   @0x14e8c8 beq 0x14e8fc <_Z24F_PhysicsParticleDampingR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x14e8cc ldr r3, [r3, #0xb4]
 *   @0x14e8d0 cmp r3, r1
 *   @0x14e8d4 beq 0x14e8fc <_Z24F_PhysicsParticleDampingR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x14e8d8 ldr r0, [r3, #0x10]
 *   @0x14e8dc bl 0x2cb480 <_ZNK7b2World18GetParticleDampingEv>
 *   @0x14e8e0 vmov s15, r0
 *   @0x14e8e4 vcvt.f64.f32 d7, s15
 *   @0x14e8e8 vmov r0, r1, d7
 *   @0x14e8ec vmov r2, s14
 *   @0x14e8f0 mov r3, r1
 *   @0x14e8f4 stm r4, {r2, r3}
 *   @0x14e8f8 pop {r4, pc}
 *   @0x14e8fc ldr r0, [pc, #0x10]
 *   @0x14e900 mov r1, #0
 *   @0x14e904 pop {r4, lr}
 *   @0x14e908 add r0, pc, r0
 *   @0x14e90c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14e910 eoreq pc, r9, r4, lsl #1
 *   @0x14e914 andseq r6, pc, r12, asr r2
 *
 * ══ §161/230 F_PhysicsParticleGravityScale(RValue&, CInstance*, CInstance*, int, RValue*)  0x14e918  size 128  32 条（0x14e918..0x14e998）
 * @func 0x14e918 0x14e998  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2World::GetParticleGravityScale() const
 * 字段偏移 top8: 0x10×2 / 0x70×1 / 0xc×1 / 0x4×1 / 0xb4×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14e918 ldr r3, [pc, #0x70]
 *   @0x14e91c mov r1, #0
 *   @0x14e920 push {r4, lr}
 *   @0x14e924 ldr r3, [pc, r3]
 *   @0x14e928 str r1, [r0]
 *   @0x14e92c mov r2, r1
 *   @0x14e930 ldr r3, [r3]
 *   @0x14e934 movt r2, #0xbff0
 *   @0x14e938 mov r4, r0
 *   @0x14e93c str r1, [r0, #0xc]
 *   @0x14e940 cmp r3, r1
 *   @0x14e944 str r2, [r0, #0x4]
 *   @0x14e948 beq 0x14e97c <_Z29F_PhysicsParticleGravityScaleR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x14e94c ldr r3, [r3, #0xb4]
 *   @0x14e950 cmp r3, r1
 *   @0x14e954 beq 0x14e97c <_Z29F_PhysicsParticleGravityScaleR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x14e958 ldr r0, [r3, #0x10]
 *   @0x14e95c bl 0x2cb468 <_ZNK7b2World23GetParticleGravityScaleEv>
 *   @0x14e960 vmov s15, r0
 *   @0x14e964 vcvt.f64.f32 d7, s15
 *   @0x14e968 vmov r0, r1, d7
 *   @0x14e96c vmov r2, s14
 *   @0x14e970 mov r3, r1
 *   @0x14e974 stm r4, {r2, r3}
 *   @0x14e978 pop {r4, pc}
 *   @0x14e97c ldr r0, [pc, #0x10]
 *   @0x14e980 mov r1, #0
 *   @0x14e984 pop {r4, lr}
 *   @0x14e988 add r0, pc, r0
 *   @0x14e98c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14e990 eoreq pc, r9, r4
 *   @0x14e994 andseq r6, pc, r8, lsr r2
 *
 * ══ §162/230 F_YoYo_AchievementSendChallenge(RValue&, CInstance*, CInstance*, int, RValue*)  0x1566d4  size 128  32 条（0x1566d4..0x156754）
 * @func 0x1566d4 0x156754  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)×3 / YYGetInt32(RValue const*, int)×2
 * 字段偏移 top8: 0x18×2 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1566d4 push {r4, r5, r6, r7, r8, lr}
 *   @0x1566d8 mov r3, #0
 *   @0x1566dc ldr r4, [sp, #0x18]
 *   @0x1566e0 mov r1, r3
 *   @0x1566e4 str r3, [r0, #0xc]
 *   @0x1566e8 str r3, [r0]
 *   @0x1566ec str r3, [r0, #0x4]
 *   @0x1566f0 mov r0, r4
 *   @0x1566f4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1566f8 mov r1, #1
 *   @0x1566fc mov r5, r0
 *   @0x156700 mov r0, r4
 *   @0x156704 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x156708 mov r1, #2
 *   @0x15670c mov r8, r0
 *   @0x156710 mov r0, r4
 *   @0x156714 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x156718 mov r1, #3
 *   @0x15671c mov r7, r0
 *   @0x156720 mov r0, r4
 *   @0x156724 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x156728 mov r1, #4
 *   @0x15672c mov r6, r0
 *   @0x156730 mov r0, r4
 *   @0x156734 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x156738 mov r1, r8
 *   @0x15673c mov r2, r7
 *   @0x156740 mov r3, r6
 *   @0x156744 str r0, [sp, #0x18]
 *   @0x156748 mov r0, r5
 *   @0x15674c pop {r4, r5, r6, r7, r8, lr}
 *   @0x156750 b 0x161078 <_Z26Achievement_Send_ChallengePcS_iiS_>
 *
 * ══ §163/230 RaiseOSPauseEvent_Metro(bool)  0x159d5c  size 128  32 条（0x159d5c..0x159ddc）
 * @func 0x159d5c 0x159ddc  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x159d70→0x484aad, 0x159d74→0x484aac, 0x159d78→0x757e72, 0x159da4→0x542979, 0x159db4→0x484aac
 * 调用序列: DebuggerIsConnected()
 * 字段偏移 top8: 0x54×3 / 0x5c×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x159d5c push {r4, lr}
 *   @0x159d60 cmp r0, #0
 *   @0x159d64 ldr r4, [pc, #0x5c]
 *   @0x159d68 add r4, pc, r4
 *   @0x159d6c bne 0x159db4 <_Z23RaiseOSPauseEvent_Metrob+0x58>
 *   @0x159d70 ldr r1, [pc, #0x54]
 *   @0x159d74 ldr r2, [pc, #0x54]
 *   @0x159d78 ldr r3, [pc, #0x54]
 *   @0x159d7c ldr r1, [r4, r1]
 *   @0x159d80 strb r0, [r1]
 *   @0x159d84 ldr r2, [r4, r2]
 *   @0x159d88 strb r0, [r2]
 *   @0x159d8c ldr r3, [r4, r3]
 *   @0x159d90 ldrb r3, [r3]
 *   @0x159d94 cmp r3, #0
 *   @0x159d98 popne {r4, pc}
 *   @0x159d9c bl 0x29cb74 <_Z19DebuggerIsConnectedv>
 *   @0x159da0 cmp r0, #0
 *   @0x159da4 ldreq r3, [pc, #0x2c]
 *   @0x159da8 ldreq r3, [r4, r3]
 *   @0x159dac strbeq r0, [r3]
 *   @0x159db0 pop {r4, pc}
 *   @0x159db4 ldr r3, [pc, #0x14]
 *   @0x159db8 mov r2, #1
 *   @0x159dbc ldr r3, [r4, r3]
 *   @0x159dc0 strb r2, [r3]
 *   @0x159dc4 pop {r4, pc}
 *   @0x159dc8 eoreq r7, r9, r8, ror #29
 *   @0x159dcc .word 0xffffdef4
 *   @0x159dd0 .word 0xffffdf98
 *   @0x159dd4 .word 0xffffdf9c
 *   @0x159dd8 .word 0xffffdfa0
 *
 * ══ §164/230 CBitmap32::Assign(CBitmap32*)  0x165dac  size 128  32 条（0x165dac..0x165e2c）
 * @func 0x165dac 0x165e2c  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CBitmap32::Assign(CBitmap32*)+0x48 / MemoryManager::Free(void const*) / MemoryManager::SetLength(void**, unsigned int, char const*, int)
 * 字段偏移 top8: 0x10×6 / 0x14×3 / 0x4×2 / 0x8×2 / 0xc×2 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x165dac push {r3, r4, r5, lr}
 *   @0x165db0 mov r5, r1
 *   @0x165db4 ldr r3, [r0, #0x10]
 *   @0x165db8 mov r4, r0
 *   @0x165dbc ldrb r1, [r1, #0x4]
 *   @0x165dc0 ldr r2, [r5, #0x8]
 *   @0x165dc4 cmp r3, #0
 *   @0x165dc8 ldr r3, [r5, #0xc]
 *   @0x165dcc strb r1, [r0, #0x4]
 *   @0x165dd0 str r2, [r0, #0x8]
 *   @0x165dd4 str r3, [r0, #0xc]
 *   @0x165dd8 movle r3, #0
 *   @0x165ddc strle r3, [r0, #0x14]
 *   @0x165de0 ble 0x165df4 <_ZN9CBitmap326AssignEPS_+0x48>
 *   @0x165de4 ldr r0, [r0, #0x14]
 *   @0x165de8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x165dec mov r3, #0
 *   @0x165df0 str r3, [r4, #0x10]
 *   @0x165df4 ldr r1, [r5, #0x10]
 *   @0x165df8 add r0, r4, #20
 *   @0x165dfc ldr r2, [pc, #0x24]
 *   @0x165e00 mov r3, #111
 *   @0x165e04 str r1, [r4, #0x10]
 *   @0x165e08 add r2, pc, r2
 *   @0x165e0c ldr r1, [r5, #0x10]
 *   @0x165e10 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x165e14 ldr r0, [r4, #0x14]
 *   @0x165e18 ldr r1, [r5, #0x14]
 *   @0x165e1c ldr r2, [r5, #0x10]
 *   @0x165e20 pop {r3, r4, r5, lr}
 *   @0x165e24 b 0xb65bc <memcpy@plt>
 *   @0x165e28 ldrheq r4, [lr], -r8
 *
 * ══ §165/230 CCamera::GetCamDir()  0x16d7c4  size 128  32 条（0x16d7c4..0x16d844）
 * @func 0x16d7c4 0x16d854  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6700
 * 字段偏移 top8: 无
 * VFP 指令 25 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16d7c4 vldr s12, [r1, #92]
 *   @0x16d7c8 vmul.f32 s15, s12, s12
 *   @0x16d7cc vldr s13, [r1, #76]
 *   @0x16d7d0 vldr s14, [r1, #108]
 *   @0x16d7d4 push {r4, lr}
 *   @0x16d7d8 vstr s14, [r0, #8]
 *   @0x16d7dc mov r4, r0
 *   @0x16d7e0 vstr s12, [r0, #4]
 *   @0x16d7e4 vstr s13, [r0]
 *   @0x16d7e8 vmla.f32 s15, s13, s13
 *   @0x16d7ec vmla.f32 s15, s14, s14
 *   @0x16d7f0 vsqrt.f32 s14, s15
 *   @0x16d7f4 vcmp.f32 s14, s14
 *   @0x16d7f8 vmrs APSR_nzcv, fpscr
 *   @0x16d7fc bne 0x16d834 <_ZN7CCamera9GetCamDirEv+0x70>
 *   @0x16d800 vmov.f32 s11, #1.000000e+00
 *   @0x16d804 vldr s12, [r4]
 *   @0x16d808 vldr s15, [r4, #4]
 *   @0x16d80c vldr s13, [r4, #8]
 *   @0x16d810 mov r0, r4
 *   @0x16d814 vdiv.f32 s14, s11, s14
 *   @0x16d818 vmul.f32 s12, s12, s14
 *   @0x16d81c vmul.f32 s15, s15, s14
 *   @0x16d820 vstr s12, [r4]
 *   @0x16d824 vmul.f32 s14, s13, s14
 *   @0x16d828 vstr s15, [r4, #4]
 *   @0x16d82c vstr s14, [r4, #8]
 *   @0x16d830 pop {r4, pc}
 *   @0x16d834 vmov r0, s15
 *   @0x16d838 bl 0xb6700 <sqrtf@plt>
 *   @0x16d83c vmov s14, r0
 *   @0x16d840 b 0x16d800 <_ZN7CCamera9GetCamDirEv+0x3c>
 *
 * ══ §166/230 CCamera::GetCamUp()  0x16d844  size 128  32 条（0x16d844..0x16d8c4）
 * @func 0x16d844 0x16d8c4  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6700
 * 字段偏移 top8: 无
 * VFP 指令 25 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16d844 vldr s12, [r1, #88]
 *   @0x16d848 vmul.f32 s15, s12, s12
 *   @0x16d84c vldr s13, [r1, #72]
 *   @0x16d850 vldr s14, [r1, #104]
 *   @0x16d854 push {r4, lr}
 *   @0x16d858 vstr s14, [r0, #8]
 *   @0x16d85c mov r4, r0
 *   @0x16d860 vstr s12, [r0, #4]
 *   @0x16d864 vstr s13, [r0]
 *   @0x16d868 vmla.f32 s15, s13, s13
 *   @0x16d86c vmla.f32 s15, s14, s14
 *   @0x16d870 vsqrt.f32 s14, s15
 *   @0x16d874 vcmp.f32 s14, s14
 *   @0x16d878 vmrs APSR_nzcv, fpscr
 *   @0x16d87c bne 0x16d8b4 <_ZN7CCamera8GetCamUpEv+0x70>
 *   @0x16d880 vmov.f32 s11, #1.000000e+00
 *   @0x16d884 vldr s12, [r4]
 *   @0x16d888 vldr s15, [r4, #4]
 *   @0x16d88c vldr s13, [r4, #8]
 *   @0x16d890 mov r0, r4
 *   @0x16d894 vdiv.f32 s14, s11, s14
 *   @0x16d898 vmul.f32 s12, s12, s14
 *   @0x16d89c vmul.f32 s15, s15, s14
 *   @0x16d8a0 vstr s12, [r4]
 *   @0x16d8a4 vmul.f32 s14, s13, s14
 *   @0x16d8a8 vstr s15, [r4, #4]
 *   @0x16d8ac vstr s14, [r4, #8]
 *   @0x16d8b0 pop {r4, pc}
 *   @0x16d8b4 vmov r0, s15
 *   @0x16d8b8 bl 0xb6700 <sqrtf@plt>
 *   @0x16d8bc vmov s14, r0
 *   @0x16d8c0 b 0x16d880 <_ZN7CCamera8GetCamUpEv+0x3c>
 *
 * ══ §167/230 F_CameraSetViewAngle(RValue&, CInstance*, CInstance*, int, RValue*)  0x16fd04  size 128  32 条（0x16fd04..0x16fd84）
 * @func 0x16fd04 0x16fd84  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CCameraManager::GetCamera(int) / YYGetFloat(RValue const*, int) / CCamera::SetViewAngle(float)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x4c×1 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16fd04 cmp r3, #2
 *   @0x16fd08 push {r3, r4, r5, lr}
 *   @0x16fd0c mov r3, #0
 *   @0x16fd10 mov r1, r3
 *   @0x16fd14 ldr r4, [sp, #0x10]
 *   @0x16fd18 movt r3, #0xbff0
 *   @0x16fd1c str r1, [r0, #0xc]
 *   @0x16fd20 stm r0, {r1, r3}
 *   @0x16fd24 beq 0x16fd38 <_Z20F_CameraSetViewAngleR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x16fd28 ldr r0, [pc, #0x4c]
 *   @0x16fd2c pop {r3, r4, r5, lr}
 *   @0x16fd30 add r0, pc, r0
 *   @0x16fd34 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x16fd38 mov r0, r4
 *   @0x16fd3c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x16fd40 ldr r3, [pc, #0x38]
 *   @0x16fd44 mov r1, r0
 *   @0x16fd48 ldr r0, [pc, r3]
 *   @0x16fd4c bl 0x16f45c <_ZN14CCameraManager9GetCameraEi>
 *   @0x16fd50 subs r5, r0, #0
 *   @0x16fd54 popeq {r3, r4, r5, pc}
 *   @0x16fd58 mov r0, r4
 *   @0x16fd5c mov r1, #1
 *   @0x16fd60 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x16fd64 mov r1, r0
 *   @0x16fd68 mov r0, r5
 *   @0x16fd6c bl 0x16d31c <_ZN7CCamera12SetViewAngleEf>
 *   @0x16fd70 mov r0, r5
 *   @0x16fd74 pop {r3, r4, r5, lr}
 *   @0x16fd78 b 0x16d36c <_ZN7CCamera12SetViewDirtyEv>
 *   @0x16fd7c andseq r11, sp, r12, ror #5
 *   @0x16fd80 eoreq sp, r7, r12, lsr #30
 *
 * ══ §168/230 Hash<RSurface>::~Hash()  0x170ec8  size 128  32 条（0x170ec8..0x170f48）
 * @func 0x170ec8 0x170f48  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / Hash<RSurface>::~Hash()+0x74 / operator delete(void*)
 * 字段偏移 top8: 0x4×2 / 0x8×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x170ec8 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x170ecc mov r6, r0
 *   @0x170ed0 ldm r0, {r0, r8}
 *   @0x170ed4 cmp r8, #0
 *   @0x170ed8 lslge r7, r8, #3
 *   @0x170edc movge r9, #0
 *   @0x170ee0 blt 0x170f3c <_ZN4HashI8RSurfaceED2Ev+0x74>
 *   @0x170ee4 ldr r4, [r0, r7]
 *   @0x170ee8 add r3, r0, r7
 *   @0x170eec str r9, [r0, r7]
 *   @0x170ef0 cmp r4, #0
 *   @0x170ef4 str r9, [r3, #0x4]
 *   @0x170ef8 beq 0x170f2c <_ZN4HashI8RSurfaceED2Ev+0x64>
 *   @0x170efc ldr r5, [r4, #0x4]
 *   @0x170f00 ldr r0, [r4, #0xc]
 *   @0x170f04 bl 0x27d1d0 <_ZdlPv>
 *   @0x170f08 mov r0, r4
 *   @0x170f0c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x170f10 ldr r3, [r6, #0x8]
 *   @0x170f14 cmp r5, #0
 *   @0x170f18 mov r4, r5
 *   @0x170f1c sub r3, r3, #1
 *   @0x170f20 str r3, [r6, #0x8]
 *   @0x170f24 bne 0x170efc <_ZN4HashI8RSurfaceED2Ev+0x34>
 *   @0x170f28 ldr r0, [r6]
 *   @0x170f2c sub r8, r8, #1
 *   @0x170f30 sub r7, r7, #8
 *   @0x170f34 cmn r8, #1
 *   @0x170f38 bne 0x170ee4 <_ZN4HashI8RSurfaceED2Ev+0x1c>
 *   @0x170f3c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x170f40 mov r0, r6
 *   @0x170f44 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §169/230 IO_String_Get()  0x18bd34  size 128  32 条（0x18bd34..0x18bdb4）
 * @func 0x18bd34 0x18bdb4  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: utf8_add_char×2 / yywcslen(unsigned short const*)
 * 字段偏移 top8: 0x64×1 / 0x58×1 / 0x4×1 / 0x2×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18bd34 push {r4, r5, r6, r7, lr}
 *   @0x18bd38 sub sp, sp, #12
 *   @0x18bd3c ldr r5, [pc, #0x64]
 *   @0x18bd40 ldr r5, [pc, r5]
 *   @0x18bd44 mov r0, r5
 *   @0x18bd48 bl 0xf6c78 <_Z8yywcslenPKt>
 *   @0x18bd4c ldr r3, [pc, #0x58]
 *   @0x18bd50 add r3, pc, r3
 *   @0x18bd54 str r3, [sp, #0x4]
 *   @0x18bd58 subs r7, r0, #0
 *   @0x18bd5c subne r5, r5, #2
 *   @0x18bd60 addne r6, sp, #4
 *   @0x18bd64 movne r4, #0
 *   @0x18bd68 beq 0x18bda0 <_Z13IO_String_Getv+0x6c>
 *   @0x18bd6c add r4, r4, #1
 *   @0x18bd70 mov r0, r6
 *   @0x18bd74 ldrh r1, [r5, #2]!
 *   @0x18bd78 bl 0x10fe28 <utf8_add_char>
 *   @0x18bd7c cmp r4, r7
 *   @0x18bd80 bne 0x18bd6c <_Z13IO_String_Getv+0x38>
 *   @0x18bd84 mov r0, r6
 *   @0x18bd88 mov r1, #0
 *   @0x18bd8c bl 0x10fe28 <utf8_add_char>
 *   @0x18bd90 ldr r0, [pc, #0x18]
 *   @0x18bd94 add r0, pc, r0
 *   @0x18bd98 add sp, sp, #12
 *   @0x18bd9c pop {r4, r5, r6, r7, pc}
 *   @0x18bda0 add r6, sp, #4
 *   @0x18bda4 b 0x18bd84 <_Z13IO_String_Getv+0x50>
 *   @0x18bda8 mlaeq r6, r4, r8, r4
 *   @0x18bdac eorseq r7, r10, r8, ror r2
 *   @0x18bdb0 eorseq r7, r10, r4, lsr r2
 *
 * ══ §170/230 LoadSave::_WriteFile(char const*, char const*, int)  0x18e094  size 128  32 条（0x18e094..0x18e114）
 * @func 0x18e094 0x18e114  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6844 / 0xb68bc / 0xb6850 / 0xb6934
 * 字段偏移 top8: 0x68×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18e094 push {r4, r5, r6, lr}
 *   @0x18e098 mov r5, r1
 *   @0x18e09c ldr r1, [pc, #0x68]
 *   @0x18e0a0 mov r4, r2
 *   @0x18e0a4 add r1, pc, r1
 *   @0x18e0a8 bl 0xb6844 <fopen@plt>
 *   @0x18e0ac subs r6, r0, #0
 *   @0x18e0b0 beq 0x18e0f8 <_ZN8LoadSave10_WriteFileEPKcS1_i+0x64>
 *   @0x18e0b4 cmp r4, #0
 *   @0x18e0b8 bne 0x18e0c8 <_ZN8LoadSave10_WriteFileEPKcS1_i+0x34>
 *   @0x18e0bc b 0x18e0e8 <_ZN8LoadSave10_WriteFileEPKcS1_i+0x54>
 *   @0x18e0c0 subs r4, r4, r0
 *   @0x18e0c4 beq 0x18e0e8 <_ZN8LoadSave10_WriteFileEPKcS1_i+0x54>
 *   @0x18e0c8 mov r0, r5
 *   @0x18e0cc mov r1, #1
 *   @0x18e0d0 mov r2, r4
 *   @0x18e0d4 mov r3, r6
 *   @0x18e0d8 bl 0xb68bc <fwrite@plt>
 *   @0x18e0dc cmp r0, #0
 *   @0x18e0e0 add r5, r5, r0
 *   @0x18e0e4 bne 0x18e0c0 <_ZN8LoadSave10_WriteFileEPKcS1_i+0x2c>
 *   @0x18e0e8 mov r0, r6
 *   @0x18e0ec bl 0xb6850 <fclose@plt>
 *   @0x18e0f0 mov r0, #1
 *   @0x18e0f4 pop {r4, r5, r6, pc}
 *   @0x18e0f8 ldr r0, [pc, #0x10]
 *   @0x18e0fc add r0, pc, r0
 *   @0x18e100 bl 0xb6934 <perror@plt>
 *   @0x18e104 mov r0, r6
 *   @0x18e108 pop {r4, r5, r6, pc}
 *   @0x18e10c andseq r2, r11, r0, lsr #5
 *   @0x18e110 andseq lr, r11, r0, lsl r2
 *
 * ══ §171/230 YYObjectBase::GetDispose(YYObjectBase*)  0x191714  size 128  32 条（0x191714..0x191794）
 * @func 0x191714 0x191794  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JS_GetProperty(YYObjectBase*, RValue*, char const*) / JS_IsCallable(RValue&)
 * 字段偏移 top8: 0xc×2 / 0x4×2 / 0x48×1 / 0x28×1 / 0x38×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x191714 push {r3, r4, r5, lr}
 *   @0x191718 mvn r5, #-16777216
 *   @0x19171c ldr r3, [r1, #0x48]
 *   @0x191720 mov r4, r0
 *   @0x191724 str r5, [r0, #0xc]
 *   @0x191728 cmp r3, #0
 *   @0x19172c bne 0x19173c <_ZN12YYObjectBase10GetDisposeEPS_+0x28>
 *   @0x191730 ldr r3, [r1, #0x4]
 *   @0x191734 cmp r3, #0
 *   @0x191738 beq 0x191744 <_ZN12YYObjectBase10GetDisposeEPS_+0x30>
 *   @0x19173c mov r0, r4
 *   @0x191740 pop {r3, r4, r5, pc}
 *   @0x191744 ldr r3, [r1, #0x28]
 *   @0x191748 ands r3, r3, #2
 *   @0x19174c bne 0x19173c <_ZN12YYObjectBase10GetDisposeEPS_+0x28>
 *   @0x191750 ldr r2, [pc, #0x38]
 *   @0x191754 str r3, [r0]
 *   @0x191758 mov r0, r1
 *   @0x19175c str r3, [r4, #0x4]
 *   @0x191760 mov r1, r4
 *   @0x191764 str r3, [r4, #0x8]
 *   @0x191768 add r2, pc, r2
 *   @0x19176c bl 0x2418dc <_Z14JS_GetPropertyP12YYObjectBaseP6RValuePKc>
 *   @0x191770 ldr r3, [r4, #0xc]
 *   @0x191774 cmp r3, r5
 *   @0x191778 beq 0x19173c <_ZN12YYObjectBase10GetDisposeEPS_+0x28>
 *   @0x19177c mov r0, r4
 *   @0x191780 bl 0x24076c <_Z13JS_IsCallableR6RValue>
 *   @0x191784 cmp r0, #0
 *   @0x191788 streq r5, [r4, #0xc]
 *   @0x19178c b 0x19173c <_ZN12YYObjectBase10GetDisposeEPS_+0x28>
 *   @0x191790 andseq r1, r10, r4, asr #32
 *
 * ══ §172/230 CPath::DeletePoint(int)  0x1a733c  size 128  32 条（0x1a733c..0x1a73bc）
 * @func 0x1a733c 0x1a73bc  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPath::DeletePoint(int)+0x78
 * 字段偏移 top8: 0x10×3 / 0x4×3 / 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a733c cmp r1, #0
 *   @0x1a7340 push {r4, r5, r6, r7}
 *   @0x1a7344 blt 0x1a73b4 <_ZN5CPath11DeletePointEi+0x78>
 *   @0x1a7348 ldr r2, [r0, #0x10]
 *   @0x1a734c cmp r1, r2
 *   @0x1a7350 bge 0x1a73b4 <_ZN5CPath11DeletePointEi+0x78>
 *   @0x1a7354 sub r2, r2, #1
 *   @0x1a7358 cmp r1, r2
 *   @0x1a735c bge 0x1a73a8 <_ZN5CPath11DeletePointEi+0x6c>
 *   @0x1a7360 add r3, r1, r1, lsl #1
 *   @0x1a7364 lsl r3, r3, #2
 *   @0x1a7368 ldr r2, [r0, #0x4]
 *   @0x1a736c add r5, r3, #12
 *   @0x1a7370 add r1, r1, #1
 *   @0x1a7374 add r12, r2, r5
 *   @0x1a7378 add r4, r2, r3
 *   @0x1a737c ldr r7, [r12]
 *   @0x1a7380 ldr r6, [r12, #0x4]
 *   @0x1a7384 ldr r12, [r12, #0x8]
 *   @0x1a7388 str r7, [r2, r3]
 *   @0x1a738c mov r3, r5
 *   @0x1a7390 str r6, [r4, #0x4]
 *   @0x1a7394 str r12, [r4, #0x8]
 *   @0x1a7398 ldr r2, [r0, #0x10]
 *   @0x1a739c sub r2, r2, #1
 *   @0x1a73a0 cmp r2, r1
 *   @0x1a73a4 bgt 0x1a7368 <_ZN5CPath11DeletePointEi+0x2c>
 *   @0x1a73a8 str r2, [r0, #0x10]
 *   @0x1a73ac pop {r4, r5, r6, r7}
 *   @0x1a73b0 b 0x1a6e30 <_ZN5CPath15ComputeInternalEv>
 *   @0x1a73b4 pop {r4, r5, r6, r7}
 *   @0x1a73b8 bx lr
 *
 * ══ §173/230 CPath::Reverse()  0x1a76b4  size 128  32 条（0x1a76b4..0x1a7734）
 * @func 0x1a76b4 0x1a7734  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPath::Reverse()+0x78
 * 字段偏移 top8: 0x4×3 / 0x-8×2 / 0x-4×2 / 0x8×2 / 0x10×1 / 0x-c×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a76b4 ldr r2, [r0, #0x10]
 *   @0x1a76b8 push {r4, r5, r6}
 *   @0x1a76bc cmp r2, #1
 *   @0x1a76c0 ble 0x1a772c <_ZN5CPath7ReverseEv+0x78>
 *   @0x1a76c4 sub r1, r2, #1
 *   @0x1a76c8 ldr r3, [r0, #0x4]
 *   @0x1a76cc add r2, r2, r2, lsl #1
 *   @0x1a76d0 asr r1, r1, #1
 *   @0x1a76d4 add r12, r3, #20
 *   @0x1a76d8 add r2, r3, r2, lsl #2
 *   @0x1a76dc add r3, r3, #8
 *   @0x1a76e0 add r1, r1, r1, lsl #1
 *   @0x1a76e4 add r6, r12, r1, lsl #2
 *   @0x1a76e8 ldr r1, [r2, #-0xc]
 *   @0x1a76ec sub r2, r2, #12
 *   @0x1a76f0 ldr r4, [r3, #-0x8]
 *   @0x1a76f4 ldr r12, [r3, #-0x4]
 *   @0x1a76f8 str r1, [r3, #-0x8]
 *   @0x1a76fc ldr r5, [r2, #0x4]
 *   @0x1a7700 ldr r1, [r3]
 *   @0x1a7704 str r5, [r3, #-0x4]
 *   @0x1a7708 ldr r5, [r2, #0x8]
 *   @0x1a770c str r5, [r3], #12
 *   @0x1a7710 cmp r3, r6
 *   @0x1a7714 str r4, [r2]
 *   @0x1a7718 str r12, [r2, #0x4]
 *   @0x1a771c str r1, [r2, #0x8]
 *   @0x1a7720 bne 0x1a76e8 <_ZN5CPath7ReverseEv+0x34>
 *   @0x1a7724 pop {r4, r5, r6}
 *   @0x1a7728 b 0x1a6e30 <_ZN5CPath15ComputeInternalEv>
 *   @0x1a772c pop {r4, r5, r6}
 *   @0x1a7730 bx lr
 *
 * ══ §174/230 CPath::Mirror()  0x1a777c  size 128  32 条（0x1a777c..0x1a77fc）
 * @func 0x1a777c 0x1a780c  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPath::Shift(float, float)×2 / CPath::Center(float&, float&) / CPath::Mirror()+0x60 / CPath::ComputeInternal()
 * 字段偏移 top8: 0x4×3 / 0x10×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a777c push {r4, lr}
 *   @0x1a7780 sub sp, sp, #8
 *   @0x1a7784 add r2, sp, #4
 *   @0x1a7788 mov r4, r0
 *   @0x1a778c mov r1, sp
 *   @0x1a7790 bl 0x1a7610 <_ZN5CPath6CenterERfS0_>
 *   @0x1a7794 ldr r1, [sp]
 *   @0x1a7798 ldr r2, [sp, #0x4]
 *   @0x1a779c mov r0, r4
 *   @0x1a77a0 eor r1, r1, #-2147483648
 *   @0x1a77a4 eor r2, r2, #-2147483648
 *   @0x1a77a8 bl 0x1a7734 <_ZN5CPath5ShiftEff>
 *   @0x1a77ac ldr r2, [r4, #0x10]
 *   @0x1a77b0 cmp r2, #0
 *   @0x1a77b4 ble 0x1a77dc <_ZN5CPath6MirrorEv+0x60>
 *   @0x1a77b8 add r2, r2, r2, lsl #1
 *   @0x1a77bc ldr r3, [r4, #0x4]
 *   @0x1a77c0 add r2, r3, r2, lsl #2
 *   @0x1a77c4 vldr s15, [r3]
 *   @0x1a77c8 vneg.f32 s15, s15
 *   @0x1a77cc vmov r1, s15
 *   @0x1a77d0 str r1, [r3], #12
 *   @0x1a77d4 cmp r3, r2
 *   @0x1a77d8 bne 0x1a77c4 <_ZN5CPath6MirrorEv+0x48>
 *   @0x1a77dc mov r0, r4
 *   @0x1a77e0 ldr r1, [sp]
 *   @0x1a77e4 ldr r2, [sp, #0x4]
 *   @0x1a77e8 bl 0x1a7734 <_ZN5CPath5ShiftEff>
 *   @0x1a77ec mov r0, r4
 *   @0x1a77f0 bl 0x1a6e30 <_ZN5CPath15ComputeInternalEv>
 *   @0x1a77f4 add sp, sp, #8
 *   @0x1a77f8 pop {r4, pc}
 *
 * ══ §175/230 CPath::Flip()  0x1a77fc  size 128  32 条（0x1a77fc..0x1a787c）
 * @func 0x1a77fc 0x1a787c  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPath::Shift(float, float)×2 / CPath::Center(float&, float&) / CPath::Flip()+0x60 / CPath::ComputeInternal()
 * 字段偏移 top8: 0x4×3 / 0x10×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a77fc push {r4, lr}
 *   @0x1a7800 sub sp, sp, #8
 *   @0x1a7804 add r2, sp, #4
 *   @0x1a7808 mov r4, r0
 *   @0x1a780c mov r1, sp
 *   @0x1a7810 bl 0x1a7610 <_ZN5CPath6CenterERfS0_>
 *   @0x1a7814 ldr r1, [sp]
 *   @0x1a7818 ldr r2, [sp, #0x4]
 *   @0x1a781c mov r0, r4
 *   @0x1a7820 eor r1, r1, #-2147483648
 *   @0x1a7824 eor r2, r2, #-2147483648
 *   @0x1a7828 bl 0x1a7734 <_ZN5CPath5ShiftEff>
 *   @0x1a782c ldr r2, [r4, #0x10]
 *   @0x1a7830 cmp r2, #0
 *   @0x1a7834 ble 0x1a785c <_ZN5CPath4FlipEv+0x60>
 *   @0x1a7838 add r2, r2, r2, lsl #1
 *   @0x1a783c ldr r3, [r4, #0x4]
 *   @0x1a7840 add r2, r3, r2, lsl #2
 *   @0x1a7844 vldr s15, [r3, #4]
 *   @0x1a7848 vneg.f32 s15, s15
 *   @0x1a784c add r3, r3, #12
 *   @0x1a7850 vstr s15, [r3, #-8]
 *   @0x1a7854 cmp r3, r2
 *   @0x1a7858 bne 0x1a7844 <_ZN5CPath4FlipEv+0x48>
 *   @0x1a785c mov r0, r4
 *   @0x1a7860 ldr r1, [sp]
 *   @0x1a7864 ldr r2, [sp, #0x4]
 *   @0x1a7868 bl 0x1a7734 <_ZN5CPath5ShiftEff>
 *   @0x1a786c mov r0, r4
 *   @0x1a7870 bl 0x1a6e30 <_ZN5CPath15ComputeInternalEv>
 *   @0x1a7874 add sp, sp, #8
 *   @0x1a7878 pop {r4, pc}
 *
 * ══ §176/230 Path_Delete(int)  0x1a82a0  size 128  32 条（0x1a82a0..0x1a8320）
 * @func 0x1a82a0 0x1a8320  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Path_Delete(int)+0x6c / CPath::Free() / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x2×4 / 0x4×2 / 0x60×1 / 0x50×1 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a82a0 push {r4, r5, r6, lr}
 *   @0x1a82a4 subs r4, r0, #0
 *   @0x1a82a8 blt 0x1a830c <_Z11Path_Deletei+0x6c>
 *   @0x1a82ac ldr r3, [pc, #0x60]
 *   @0x1a82b0 ldr r3, [pc, r3]
 *   @0x1a82b4 ldr r3, [r3]
 *   @0x1a82b8 cmp r4, r3
 *   @0x1a82bc bge 0x1a830c <_Z11Path_Deletei+0x6c>
 *   @0x1a82c0 ldr r6, [pc, #0x50]
 *   @0x1a82c4 add r6, pc, r6
 *   @0x1a82c8 ldr r3, [r6, #0x4]
 *   @0x1a82cc ldr r0, [r3, r4, lsl #2]
 *   @0x1a82d0 cmp r0, #0
 *   @0x1a82d4 popeq {r4, r5, r6, pc}
 *   @0x1a82d8 ldr r5, [pc, #0x3c]
 *   @0x1a82dc bl 0x1a6ffc <_ZN5CPath4FreeEv>
 *   @0x1a82e0 ldr r3, [r6, #0x4]
 *   @0x1a82e4 mov r6, #0
 *   @0x1a82e8 ldr r5, [pc, r5]
 *   @0x1a82ec str r6, [r3, r4, lsl #2]
 *   @0x1a82f0 ldr r3, [r5]
 *   @0x1a82f4 ldr r0, [r3, r4, lsl #2]
 *   @0x1a82f8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1a82fc ldr r3, [r5]
 *   @0x1a8300 mov r0, #1
 *   @0x1a8304 str r6, [r3, r4, lsl #2]
 *   @0x1a8308 pop {r4, r5, r6, pc}
 *   @0x1a830c mov r0, #0
 *   @0x1a8310 pop {r4, r5, r6, pc}
 *   @0x1a8314 eoreq r8, r4, r12, lsl r5
 *   @0x1a8318 eorseq r10, r9, r4, ror #4
 *   @0x1a831c eoreq r8, r4, r8, ror #9
 *
 * ══ §177/230 SetAll(int, char const*, int)  0x1dc254  size 128  32 条（0x1dc254..0x1dc2d4）
 * @func 0x1dc254 0x1dc2d4  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*) / 0xb6538 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb65a4
 * 字段偏移 top8: 0x4×2 / 0x3×2 / 0x68×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dc254 push {r4, r5, r6, r7, lr}
 *   @0x1dc258 sub r6, r0, #1
 *   @0x1dc25c ldr r4, [pc, #0x68]
 *   @0x1dc260 mov r3, #0
 *   @0x1dc264 sub sp, sp, #12
 *   @0x1dc268 mov r5, r1
 *   @0x1dc26c ldr r4, [pc, r4]
 *   @0x1dc270 mov r7, r2
 *   @0x1dc274 strb r3, [sp, #0x4]
 *   @0x1dc278 ldr r0, [r4, r6, lsl #3]
 *   @0x1dc27c cmp r0, r3
 *   @0x1dc280 beq 0x1dc288 <_Z6SetAlliPKci+0x34>
 *   @0x1dc284 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1dc288 cmp r5, #0
 *   @0x1dc28c addeq r5, sp, #4
 *   @0x1dc290 mov r0, r5
 *   @0x1dc294 bl 0xb6538 <strlen@plt>
 *   @0x1dc298 ldr r1, [pc, #0x30]
 *   @0x1dc29c mov r3, #1
 *   @0x1dc2a0 mov r2, #284
 *   @0x1dc2a4 add r1, pc, r1
 *   @0x1dc2a8 add r0, r0, r3
 *   @0x1dc2ac bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1dc2b0 mov r1, r5
 *   @0x1dc2b4 str r0, [r4, r6, lsl #3]
 *   @0x1dc2b8 add r4, r4, r6, lsl #3
 *   @0x1dc2bc bl 0xb65a4 <strcpy@plt>
 *   @0x1dc2c0 str r7, [r4, #0x4]
 *   @0x1dc2c4 add sp, sp, #12
 *   @0x1dc2c8 pop {r4, r5, r6, r7, pc}
 *   @0x1dc2cc eoreq r4, r1, r0, lsr #20
 *   @0x1dc2d0 andseq r5, r7, r0, asr r3
 *
 * ══ §178/230 F_VertexFormat_Add_Position(RValue&, CInstance*, CInstance*, int, RValue*)  0x1e2888  size 128  32 条（0x1e2888..0x1e2908）
 * @func 0x1e2888 0x1e2918  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: VertexFormat::Add(yyVertexType, yyVertexUsage, unsigned int)
 * 字段偏移 top8: 0x68×1 / 0x54×1 / 0x28×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e2888 ldr r3, [pc, #0x68]
 *   @0x1e288c push {r4, lr}
 *   @0x1e2890 ldr r3, [pc, r3]
 *   @0x1e2894 ldr r0, [r3]
 *   @0x1e2898 cmp r0, #0
 *   @0x1e289c beq 0x1e28e4 <_Z27F_VertexFormat_Add_PositionR6RValueP9CInstanceS2_iPS_+0x5c>
 *   @0x1e28a0 ldr r4, [pc, #0x54]
 *   @0x1e28a4 ldr r4, [pc, r4]
 *   @0x1e28a8 ldr r3, [r4]
 *   @0x1e28ac cmp r3, #0
 *   @0x1e28b0 beq 0x1e28d0 <_Z27F_VertexFormat_Add_PositionR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x1e28b4 mov r1, #2
 *   @0x1e28b8 mov r2, #1
 *   @0x1e28bc bl 0x1e2440 <_ZN12VertexFormat3AddE12yyVertexType13yyVertexUsagej>
 *   @0x1e28c0 ldr r3, [r4]
 *   @0x1e28c4 lsl r3, r3, #1
 *   @0x1e28c8 str r3, [r4]
 *   @0x1e28cc pop {r4, pc}
 *   @0x1e28d0 ldr r0, [pc, #0x28]
 *   @0x1e28d4 mov r1, r3
 *   @0x1e28d8 pop {r4, lr}
 *   @0x1e28dc add r0, pc, r0
 *   @0x1e28e0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1e28e4 mov r1, r0
 *   @0x1e28e8 ldr r0, [pc, #0x14]
 *   @0x1e28ec pop {r4, lr}
 *   @0x1e28f0 add r0, pc, r0
 *   @0x1e28f4 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1e28f8 eoreq lr, r0, r0, lsl #10
 *   @0x1e28fc .word 0x0020e4f0
 *   @0x1e2900 andseq pc, r6, r12, lsl r7
 *   @0x1e2904 andseq pc, r6, r12, asr #13
 *
 * ══ §179/230 F_VertexFormat_Add_Position3D(RValue&, CInstance*, CInstance*, int, RValue*)  0x1e2908  size 128  32 条（0x1e2908..0x1e2988）
 * @func 0x1e2908 0x1e2998  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: VertexFormat::Add(yyVertexType, yyVertexUsage, unsigned int)
 * 字段偏移 top8: 0x68×1 / 0x54×1 / 0x28×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e2908 ldr r3, [pc, #0x68]
 *   @0x1e290c push {r4, lr}
 *   @0x1e2910 ldr r3, [pc, r3]
 *   @0x1e2914 ldr r0, [r3]
 *   @0x1e2918 cmp r0, #0
 *   @0x1e291c beq 0x1e2964 <_Z29F_VertexFormat_Add_Position3DR6RValueP9CInstanceS2_iPS_+0x5c>
 *   @0x1e2920 ldr r4, [pc, #0x54]
 *   @0x1e2924 ldr r4, [pc, r4]
 *   @0x1e2928 ldr r3, [r4]
 *   @0x1e292c cmp r3, #0
 *   @0x1e2930 beq 0x1e2950 <_Z29F_VertexFormat_Add_Position3DR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x1e2934 mov r1, #3
 *   @0x1e2938 mov r2, #1
 *   @0x1e293c bl 0x1e2440 <_ZN12VertexFormat3AddE12yyVertexType13yyVertexUsagej>
 *   @0x1e2940 ldr r3, [r4]
 *   @0x1e2944 lsl r3, r3, #1
 *   @0x1e2948 str r3, [r4]
 *   @0x1e294c pop {r4, pc}
 *   @0x1e2950 ldr r0, [pc, #0x28]
 *   @0x1e2954 mov r1, r3
 *   @0x1e2958 pop {r4, lr}
 *   @0x1e295c add r0, pc, r0
 *   @0x1e2960 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1e2964 mov r1, r0
 *   @0x1e2968 ldr r0, [pc, #0x14]
 *   @0x1e296c pop {r4, lr}
 *   @0x1e2970 add r0, pc, r0
 *   @0x1e2974 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1e2978 eoreq lr, r0, r0, lsl #9
 *   @0x1e297c eoreq lr, r0, r0, ror r4
 *   @0x1e2980 andseq pc, r6, r12, lsl #14
 *   @0x1e2984 ldrheq pc, [r6], -r8
 *
 * ══ §180/230 F_VertexFormat_Add_Normal(RValue&, CInstance*, CInstance*, int, RValue*)  0x1e2988  size 128  32 条（0x1e2988..0x1e2a08）
 * @func 0x1e2988 0x1e2a18  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: VertexFormat::Add(yyVertexType, yyVertexUsage, unsigned int)
 * 字段偏移 top8: 0x68×1 / 0x54×1 / 0x28×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e2988 ldr r3, [pc, #0x68]
 *   @0x1e298c push {r4, lr}
 *   @0x1e2990 ldr r3, [pc, r3]
 *   @0x1e2994 ldr r0, [r3]
 *   @0x1e2998 cmp r0, #0
 *   @0x1e299c beq 0x1e29e4 <_Z25F_VertexFormat_Add_NormalR6RValueP9CInstanceS2_iPS_+0x5c>
 *   @0x1e29a0 ldr r4, [pc, #0x54]
 *   @0x1e29a4 ldr r4, [pc, r4]
 *   @0x1e29a8 ldr r3, [r4]
 *   @0x1e29ac cmp r3, #0
 *   @0x1e29b0 beq 0x1e29d0 <_Z25F_VertexFormat_Add_NormalR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x1e29b4 mov r1, #3
 *   @0x1e29b8 mov r2, r1
 *   @0x1e29bc bl 0x1e2440 <_ZN12VertexFormat3AddE12yyVertexType13yyVertexUsagej>
 *   @0x1e29c0 ldr r3, [r4]
 *   @0x1e29c4 lsl r3, r3, #1
 *   @0x1e29c8 str r3, [r4]
 *   @0x1e29cc pop {r4, pc}
 *   @0x1e29d0 ldr r0, [pc, #0x28]
 *   @0x1e29d4 mov r1, r3
 *   @0x1e29d8 pop {r4, lr}
 *   @0x1e29dc add r0, pc, r0
 *   @0x1e29e0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1e29e4 mov r1, r0
 *   @0x1e29e8 ldr r0, [pc, #0x14]
 *   @0x1e29ec pop {r4, lr}
 *   @0x1e29f0 add r0, pc, r0
 *   @0x1e29f4 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1e29f8 eoreq lr, r0, r0, lsl #8
 *   @0x1e29fc .word 0x0020e3f0
 *   @0x1e2a00 ldrsheq pc, [r6], -r12
 *   @0x1e2a04 andseq pc, r6, r12, lsr #13
 *
 * ══ §181/230 F_VertexFormat_Add_Colour(RValue&, CInstance*, CInstance*, int, RValue*)  0x1e2a08  size 128  32 条（0x1e2a08..0x1e2a88）
 * @func 0x1e2a08 0x1e2a98  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: VertexFormat::Add(yyVertexType, yyVertexUsage, unsigned int)
 * 字段偏移 top8: 0x68×1 / 0x54×1 / 0x28×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e2a08 ldr r3, [pc, #0x68]
 *   @0x1e2a0c push {r4, lr}
 *   @0x1e2a10 ldr r3, [pc, r3]
 *   @0x1e2a14 ldr r0, [r3]
 *   @0x1e2a18 cmp r0, #0
 *   @0x1e2a1c beq 0x1e2a64 <_Z25F_VertexFormat_Add_ColourR6RValueP9CInstanceS2_iPS_+0x5c>
 *   @0x1e2a20 ldr r4, [pc, #0x54]
 *   @0x1e2a24 ldr r4, [pc, r4]
 *   @0x1e2a28 ldr r3, [r4]
 *   @0x1e2a2c cmp r3, #0
 *   @0x1e2a30 beq 0x1e2a50 <_Z25F_VertexFormat_Add_ColourR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x1e2a34 mov r1, #5
 *   @0x1e2a38 mov r2, #2
 *   @0x1e2a3c bl 0x1e2440 <_ZN12VertexFormat3AddE12yyVertexType13yyVertexUsagej>
 *   @0x1e2a40 ldr r3, [r4]
 *   @0x1e2a44 lsl r3, r3, #1
 *   @0x1e2a48 str r3, [r4]
 *   @0x1e2a4c pop {r4, pc}
 *   @0x1e2a50 ldr r0, [pc, #0x28]
 *   @0x1e2a54 mov r1, r3
 *   @0x1e2a58 pop {r4, lr}
 *   @0x1e2a5c add r0, pc, r0
 *   @0x1e2a60 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1e2a64 mov r1, r0
 *   @0x1e2a68 ldr r0, [pc, #0x14]
 *   @0x1e2a6c pop {r4, lr}
 *   @0x1e2a70 add r0, pc, r0
 *   @0x1e2a74 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1e2a78 eoreq lr, r0, r0, lsl #7
 *   @0x1e2a7c eoreq lr, r0, r0, ror r3
 *   @0x1e2a80 andseq pc, r6, r8, ror #13
 *   @0x1e2a84 mulseq r6, r8, r6
 *
 * ══ §182/230 F_VertexFormat_Add_TextCoord(RValue&, CInstance*, CInstance*, int, RValue*)  0x1e2a88  size 128  32 条（0x1e2a88..0x1e2b08）
 * @func 0x1e2a88 0x1e2b08  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: VertexFormat::Add(yyVertexType, yyVertexUsage, unsigned int)
 * 字段偏移 top8: 0x68×1 / 0x54×1 / 0x28×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e2a88 ldr r3, [pc, #0x68]
 *   @0x1e2a8c push {r4, lr}
 *   @0x1e2a90 ldr r3, [pc, r3]
 *   @0x1e2a94 ldr r0, [r3]
 *   @0x1e2a98 cmp r0, #0
 *   @0x1e2a9c beq 0x1e2ae4 <_Z28F_VertexFormat_Add_TextCoordR6RValueP9CInstanceS2_iPS_+0x5c>
 *   @0x1e2aa0 ldr r4, [pc, #0x54]
 *   @0x1e2aa4 ldr r4, [pc, r4]
 *   @0x1e2aa8 ldr r3, [r4]
 *   @0x1e2aac cmp r3, #0
 *   @0x1e2ab0 beq 0x1e2ad0 <_Z28F_VertexFormat_Add_TextCoordR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x1e2ab4 mov r1, #2
 *   @0x1e2ab8 mov r2, #4
 *   @0x1e2abc bl 0x1e2440 <_ZN12VertexFormat3AddE12yyVertexType13yyVertexUsagej>
 *   @0x1e2ac0 ldr r3, [r4]
 *   @0x1e2ac4 lsl r3, r3, #1
 *   @0x1e2ac8 str r3, [r4]
 *   @0x1e2acc pop {r4, pc}
 *   @0x1e2ad0 ldr r0, [pc, #0x28]
 *   @0x1e2ad4 mov r1, r3
 *   @0x1e2ad8 pop {r4, lr}
 *   @0x1e2adc add r0, pc, r0
 *   @0x1e2ae0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1e2ae4 mov r1, r0
 *   @0x1e2ae8 ldr r0, [pc, #0x14]
 *   @0x1e2aec pop {r4, lr}
 *   @0x1e2af0 add r0, pc, r0
 *   @0x1e2af4 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1e2af8 eoreq lr, r0, r0, lsl #6
 *   @0x1e2afc .word 0x0020e2f0
 *   @0x1e2b00 ldrsbeq pc, [r6], -r8
 *   @0x1e2b04 andseq pc, r6, r4, lsl #13
 *
 * ══ §183/230 Hash<VertexFormat>::~Hash()  0x1e2c50  size 128  32 条（0x1e2c50..0x1e2cd0）
 * @func 0x1e2c50 0x1e2cd0  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / Hash<VertexFormat>::~Hash()+0x74 / operator delete(void*)
 * 字段偏移 top8: 0x4×2 / 0x8×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e2c50 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x1e2c54 mov r6, r0
 *   @0x1e2c58 ldm r0, {r0, r8}
 *   @0x1e2c5c cmp r8, #0
 *   @0x1e2c60 lslge r7, r8, #3
 *   @0x1e2c64 movge r9, #0
 *   @0x1e2c68 blt 0x1e2cc4 <_ZN4HashI12VertexFormatED2Ev+0x74>
 *   @0x1e2c6c ldr r4, [r0, r7]
 *   @0x1e2c70 add r3, r0, r7
 *   @0x1e2c74 str r9, [r0, r7]
 *   @0x1e2c78 cmp r4, #0
 *   @0x1e2c7c str r9, [r3, #0x4]
 *   @0x1e2c80 beq 0x1e2cb4 <_ZN4HashI12VertexFormatED2Ev+0x64>
 *   @0x1e2c84 ldr r5, [r4, #0x4]
 *   @0x1e2c88 ldr r0, [r4, #0xc]
 *   @0x1e2c8c bl 0x27d1d0 <_ZdlPv>
 *   @0x1e2c90 mov r0, r4
 *   @0x1e2c94 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1e2c98 ldr r3, [r6, #0x8]
 *   @0x1e2c9c cmp r5, #0
 *   @0x1e2ca0 mov r4, r5
 *   @0x1e2ca4 sub r3, r3, #1
 *   @0x1e2ca8 str r3, [r6, #0x8]
 *   @0x1e2cac bne 0x1e2c84 <_ZN4HashI12VertexFormatED2Ev+0x34>
 *   @0x1e2cb0 ldr r0, [r6]
 *   @0x1e2cb4 sub r8, r8, #1
 *   @0x1e2cb8 sub r7, r7, #8
 *   @0x1e2cbc cmn r8, #1
 *   @0x1e2cc0 bne 0x1e2c6c <_ZN4HashI12VertexFormatED2Ev+0x1c>
 *   @0x1e2cc4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1e2cc8 mov r0, r6
 *   @0x1e2ccc pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §184/230 CVariableList::Find(RValue const*)  0x1f529c  size 128  32 条（0x1f529c..0x1f531c）
 * @func 0x1f529c 0x1f531c  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: HASH_RValue(RValue const*) / YYCompareVal(RValue const&, RValue const&, double)
 * 字段偏移 top8: 0x4×1 / 0x28×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f529c push {r4, r5, r6, lr}
 *   @0x1f52a0 mov r4, r0
 *   @0x1f52a4 mov r0, r1
 *   @0x1f52a8 mov r6, r1
 *   @0x1f52ac bl 0xcee94 <_Z11HASH_RValuePK6RValue>
 *   @0x1f52b0 and r3, r0, #3
 *   @0x1f52b4 mov r5, r0
 *   @0x1f52b8 add r4, r4, r3, lsl #2
 *   @0x1f52bc ldr r4, [r4, #0x4]
 *   @0x1f52c0 cmp r4, #0
 *   @0x1f52c4 bne 0x1f52d8 <_ZN13CVariableList4FindEPK6RValue+0x3c>
 *   @0x1f52c8 b 0x1f530c <_ZN13CVariableList4FindEPK6RValue+0x70>
 *   @0x1f52cc ldr r4, [r4]
 *   @0x1f52d0 cmp r4, #0
 *   @0x1f52d4 beq 0x1f530c <_ZN13CVariableList4FindEPK6RValue+0x70>
 *   @0x1f52d8 ldr r3, [r4, #0x28]
 *   @0x1f52dc cmp r3, r5
 *   @0x1f52e0 bne 0x1f52cc <_ZN13CVariableList4FindEPK6RValue+0x30>
 *   @0x1f52e4 ldr r3, [pc, #0x2c]
 *   @0x1f52e8 add r0, r4, #8
 *   @0x1f52ec mov r1, r6
 *   @0x1f52f0 ldr r3, [pc, r3]
 *   @0x1f52f4 ldrd r2, r3, [r3]
 *   @0x1f52f8 bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d>
 *   @0x1f52fc cmp r0, #0
 *   @0x1f5300 bne 0x1f52cc <_ZN13CVariableList4FindEPK6RValue+0x30>
 *   @0x1f5304 mov r0, r4
 *   @0x1f5308 pop {r4, r5, r6, pc}
 *   @0x1f530c mov r4, #0
 *   @0x1f5310 mov r0, r4
 *   @0x1f5314 pop {r4, r5, r6, pc}
 *   @0x1f5318 andseq r8, pc, r8, lsr #20
 *
 * ══ §185/230 SV_ImageSingle(CInstance*, int, RValue*)  0x1fbaac  size 128  32 条（0x1fbaac..0x1fbb2c）
 * @func 0x1fbaac 0x1fbb2c  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: REAL_RValue_Ex(RValue const*)×2
 * 字段偏移 top8: 0xc×2 / 0x94×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fbaac push {r3, r4, r5, lr}
 *   @0x1fbab0 mov r4, r2
 *   @0x1fbab4 ldr r3, [r2, #0xc]
 *   @0x1fbab8 mov r5, r0
 *   @0x1fbabc bic r3, r3, #-16777216
 *   @0x1fbac0 cmp r3, #0
 *   @0x1fbac4 bne 0x1fbb14 <_Z14SV_ImageSingleP9CInstanceiP6RValue+0x68>
 *   @0x1fbac8 ldm r2, {r0, r1}
 *   @0x1fbacc vmov d6, r0, r1
 *   @0x1fbad0 vcmpe.f64 d6, #0
 *   @0x1fbad4 vmrs APSR_nzcv, fpscr
 *   @0x1fbad8 movmi r3, #1065353216
 *   @0x1fbadc strmi r3, [r5, #0x94]
 *   @0x1fbae0 bmi 0x1fbb0c <_Z14SV_ImageSingleP9CInstanceiP6RValue+0x60>
 *   @0x1fbae4 ldr r3, [r4, #0xc]
 *   @0x1fbae8 bic r3, r3, #-16777216
 *   @0x1fbaec cmp r3, #0
 *   @0x1fbaf0 bne 0x1fbb20 <_Z14SV_ImageSingleP9CInstanceiP6RValue+0x74>
 *   @0x1fbaf4 ldm r4, {r0, r1}
 *   @0x1fbaf8 vmov d6, r0, r1
 *   @0x1fbafc mov r3, #0
 *   @0x1fbb00 str r3, [r5, #0x94]
 *   @0x1fbb04 vcvt.f32.f64 s15, d6
 *   @0x1fbb08 vstr s15, [r5, #144]
 *   @0x1fbb0c mov r0, #1
 *   @0x1fbb10 pop {r3, r4, r5, pc}
 *   @0x1fbb14 mov r0, r2
 *   @0x1fbb18 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fbb1c b 0x1fbacc <_Z14SV_ImageSingleP9CInstanceiP6RValue+0x20>
 *   @0x1fbb20 mov r0, r4
 *   @0x1fbb24 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fbb28 b 0x1fbaf8 <_Z14SV_ImageSingleP9CInstanceiP6RValue+0x4c>
 *
 * ══ §186/230 SV_PhysicsBullet(CInstance*, int, RValue*)  0x1febd4  size 128  32 条（0x1febd4..0x1fec54）
 * @func 0x1febd4 0x1fec64  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CheckPhysicsError(CInstance*, bool, bool) / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0x4×2 / 0x84×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1febd4 push {r3, r4, r6, r7, r8, lr}
 *   @0x1febd8 mov r1, #1
 *   @0x1febdc mov r6, r2
 *   @0x1febe0 mov r2, #0
 *   @0x1febe4 mov r4, r0
 *   @0x1febe8 bl 0x1fe500 <_Z17CheckPhysicsErrorP9CInstancebb>
 *   @0x1febec subs r7, r0, #0
 *   @0x1febf0 beq 0x1fec38 <_Z16SV_PhysicsBulletP9CInstanceiP6RValue+0x64>
 *   @0x1febf4 ldr r8, [r4, #0x84]
 *   @0x1febf8 cmp r8, #0
 *   @0x1febfc beq 0x1fec4c <_Z16SV_PhysicsBulletP9CInstanceiP6RValue+0x78>
 *   @0x1fec00 ldr r3, [r6, #0xc]
 *   @0x1fec04 bic r3, r3, #-16777216
 *   @0x1fec08 cmp r3, #0
 *   @0x1fec0c bne 0x1fec40 <_Z16SV_PhysicsBulletP9CInstanceiP6RValue+0x6c>
 *   @0x1fec10 ldm r6, {r0, r1}
 *   @0x1fec14 vmov.f64 d7, #5.000000e-01
 *   @0x1fec18 ldr r3, [r8]
 *   @0x1fec1c vmov d6, r0, r1
 *   @0x1fec20 ldrh r2, [r3, #4]
 *   @0x1fec24 vcmpe.f64 d6, d7
 *   @0x1fec28 vmrs APSR_nzcv, fpscr
 *   @0x1fec2c orrgt r2, r2, #8
 *   @0x1fec30 bicle r2, r2, #8
 *   @0x1fec34 strh r2, [r3, #4]
 *   @0x1fec38 mov r0, r7
 *   @0x1fec3c pop {r3, r4, r6, r7, r8, pc}
 *   @0x1fec40 mov r0, r6
 *   @0x1fec44 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fec48 b 0x1fec14 <_Z16SV_PhysicsBulletP9CInstanceiP6RValue+0x40>
 *   @0x1fec4c mov r7, r8
 *   @0x1fec50 b 0x1fec38 <_Z16SV_PhysicsBulletP9CInstanceiP6RValue+0x64>
 *
 * ══ §187/230 cAudio_Sound::cAudio_Sound()  0x218ea4  size 128  32 条（0x218ea4..0x218f24）
 * @func 0x218ea4 0x218f24  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x-4×1 / 0x18×1 / 0x3c×1 / 0x8×1 / 0x1c×1 / 0xc×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x218ea4 str r4, [sp, #-0x4]!
 *   @0x218ea8 mov r4, #1065353216
 *   @0x218eac mvn r3, #0
 *   @0x218eb0 mov r12, #1
 *   @0x218eb4 str r3, [r0, #0x18]
 *   @0x218eb8 mov r2, #0
 *   @0x218ebc mov r3, #0
 *   @0x218ec0 str r12, [r0, #0x3c]
 *   @0x218ec4 strd r2, r3, [r0, #64]
 *   @0x218ec8 mov r12, #0
 *   @0x218ecc mov r3, #0
 *   @0x218ed0 str r4, [r0, #0x4]
 *   @0x218ed4 str r4, [r0, #0x8]
 *   @0x218ed8 str r12, [r0]
 *   @0x218edc str r3, [r0, #0x1c]
 *   @0x218ee0 str r12, [r0, #0xc]
 *   @0x218ee4 str r3, [r0, #0x34]
 *   @0x218ee8 str r12, [r0, #0x14]
 *   @0x218eec str r3, [r0, #0x48]
 *   @0x218ef0 str r12, [r0, #0x20]
 *   @0x218ef4 strb r12, [r0, #0x24]
 *   @0x218ef8 strb r12, [r0, #0x25]
 *   @0x218efc strb r12, [r0, #0x26]
 *   @0x218f00 strb r12, [r0, #0x27]
 *   @0x218f04 str r12, [r0, #0x28]
 *   @0x218f08 str r12, [r0, #0x2c]
 *   @0x218f0c str r12, [r0, #0x30]
 *   @0x218f10 str r12, [r0, #0x38]
 *   @0x218f14 str r12, [r0, #0x4c]
 *   @0x218f18 strb r12, [r0, #0x5c]
 *   @0x218f1c ldr r4, [sp], #4
 *   @0x218f20 bx lr
 *
 * ══ §188/230 SND_Clear()  0x21eae0  size 128  32 条（0x21eae0..0x21eb60）
 * @func 0x21eae0 0x21eb60  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / SND_Clear()+0x34 / SND_Delete(int)
 * 字段偏移 top8: 0x4×3 / 0x6c×1 / 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21eae0 push {r4, r5, r6, lr}
 *   @0x21eae4 ldr r5, [pc, #0x6c]
 *   @0x21eae8 ldr r5, [pc, r5]
 *   @0x21eaec ldr r3, [r5]
 *   @0x21eaf0 cmp r3, #0
 *   @0x21eaf4 movgt r4, #0
 *   @0x21eaf8 ble 0x21eb14 <_Z9SND_Clearv+0x34>
 *   @0x21eafc mov r0, r4
 *   @0x21eb00 add r4, r4, #1
 *   @0x21eb04 bl 0x21eadc <_Z10SND_Deletei>
 *   @0x21eb08 ldr r3, [r5]
 *   @0x21eb0c cmp r3, r4
 *   @0x21eb10 bgt 0x21eafc <_Z9SND_Clearv+0x1c>
 *   @0x21eb14 ldr r4, [pc, #0x40]
 *   @0x21eb18 ldr r4, [pc, r4]
 *   @0x21eb1c ldr r6, [r4, #0x4]
 *   @0x21eb20 cmp r6, #0
 *   @0x21eb24 beq 0x21eb48 <_Z9SND_Clearv+0x68>
 *   @0x21eb28 mov r0, r6
 *   @0x21eb2c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x21eb30 mov r3, #0
 *   @0x21eb34 str r3, [r4, #0x4]
 *   @0x21eb38 mov r3, #0
 *   @0x21eb3c str r3, [r4]
 *   @0x21eb40 str r3, [r5]
 *   @0x21eb44 pop {r4, r5, r6, pc}
 *   @0x21eb48 mov r0, r6
 *   @0x21eb4c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x21eb50 str r6, [r4, #0x4]
 *   @0x21eb54 b 0x21eb38 <_Z9SND_Clearv+0x58>
 *   @0x21eb58 andseq r2, sp, r12, lsr #18
 *   @0x21eb5c andseq r2, sp, r0, lsl #18
 *
 * ══ §189/230 Sound_Find(char const*)  0x21fc54  size 128  32 条（0x21fc54..0x21fcd4）
 * @func 0x21fc54 0x21fcd4  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Sound_Find(char const*)+0x74 / 0xb6574
 * 字段偏移 top8: 0x74×1 / 0x10×1 / 0x4×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21fc54 ldr r3, [pc, #0x74]
 *   @0x21fc58 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x21fc5c add r3, pc, r3
 *   @0x21fc60 mov r7, r0
 *   @0x21fc64 ldr r6, [r3, #0x10]
 *   @0x21fc68 cmp r6, #0
 *   @0x21fc6c ble 0x21fcc8 <_Z10Sound_FindPKc+0x74>
 *   @0x21fc70 mov r5, #0
 *   @0x21fc74 ldr r8, [r3]
 *   @0x21fc78 ldr r10, [r3, #0x4]
 *   @0x21fc7c mov r4, r5
 *   @0x21fc80 ldr r9, [r3, #0xc]
 *   @0x21fc84 b 0x21fc98 <_Z10Sound_FindPKc+0x44>
 *   @0x21fc88 add r4, r4, #1
 *   @0x21fc8c add r5, r5, #4
 *   @0x21fc90 cmp r4, r6
 *   @0x21fc94 beq 0x21fcc8 <_Z10Sound_FindPKc+0x74>
 *   @0x21fc98 cmp r4, r8
 *   @0x21fc9c mov r1, r7
 *   @0x21fca0 bge 0x21fc88 <_Z10Sound_FindPKc+0x34>
 *   @0x21fca4 ldr r3, [r10, r5]
 *   @0x21fca8 cmp r3, #0
 *   @0x21fcac beq 0x21fc88 <_Z10Sound_FindPKc+0x34>
 *   @0x21fcb0 ldr r0, [r9, r5]
 *   @0x21fcb4 bl 0xb6574 <strcmp@plt>
 *   @0x21fcb8 cmp r0, #0
 *   @0x21fcbc bne 0x21fc88 <_Z10Sound_FindPKc+0x34>
 *   @0x21fcc0 mov r0, r4
 *   @0x21fcc4 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x21fcc8 mvn r0, #0
 *   @0x21fccc pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x21fcd0 ldrsbeq r5, [r3], #-108
 *
 * ══ §190/230 alutCreateBufferWaveform  0x222fa8  size 128  32 条（0x222fa8..0x223028）
 * @func 0x222fa8 0x223028  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _alutSanityCheck / anon_222bd4+0x6c / _alutOutputStreamGetData / _alutOutputStreamGetLength / _alutInputStreamConstructFromMemory / _alutCreateBufferFromInputStream / _alutOutputStreamDestroy
 * 字段偏移 top8: 无
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x222fa8 push {r3, r4, r5, r6, r7, lr}
 *   @0x222fac mov r7, r0
 *   @0x222fb0 mov r6, r1
 *   @0x222fb4 mov r5, r2
 *   @0x222fb8 mov r4, r3
 *   @0x222fbc bl 0x2219a8 <_alutSanityCheck>
 *   @0x222fc0 cmp r0, #0
 *   @0x222fc4 bne 0x222fd0 <alutCreateBufferWaveform+0x28>
 *   @0x222fc8 mov r0, #0
 *   @0x222fcc pop {r3, r4, r5, r6, r7, pc}
 *   @0x222fd0 vmov s2, r4
 *   @0x222fd4 mov r0, r7
 *   @0x222fd8 vmov s0, r6
 *   @0x222fdc vmov s1, r5
 *   @0x222fe0 bl 0x222c40 <alutGetMinorVersion+0x74>
 *   @0x222fe4 subs r4, r0, #0
 *   @0x222fe8 beq 0x222fc8 <alutCreateBufferWaveform+0x20>
 *   @0x222fec bl 0x22291c <_alutOutputStreamGetData>
 *   @0x222ff0 mov r5, r0
 *   @0x222ff4 mov r0, r4
 *   @0x222ff8 bl 0x222924 <_alutOutputStreamGetLength>
 *   @0x222ffc mov r1, r0
 *   @0x223000 mov r0, r5
 *   @0x223004 bl 0x221d94 <_alutInputStreamConstructFromMemory>
 *   @0x223008 subs r5, r0, #0
 *   @0x22300c beq 0x223018 <alutCreateBufferWaveform+0x70>
 *   @0x223010 bl 0x2225cc <_alutCreateBufferFromInputStream>
 *   @0x223014 mov r5, r0
 *   @0x223018 mov r0, r4
 *   @0x22301c bl 0x2228fc <_alutOutputStreamDestroy>
 *   @0x223020 mov r0, r5
 *   @0x223024 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §191/230 _vorbis_block_alloc  0x2270e4  size 128  32 条（0x2270e4..0x227164）
 * @func 0x2270e4 0x227164  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6544×2 / _vorbis_block_alloc+0x78
 * 字段偏移 top8: 0x44×3 / 0x48×2 / 0x4c×2 / 0x54×2 / 0x50×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2270e4 push {r3, r4, r5, r6, r7, lr}
 *   @0x2270e8 add r1, r1, #7
 *   @0x2270ec ldr r6, [r0, #0x48]
 *   @0x2270f0 bic r5, r1, #7
 *   @0x2270f4 ldr r2, [r0, #0x4c]
 *   @0x2270f8 mov r4, r0
 *   @0x2270fc add r3, r6, r5
 *   @0x227100 cmp r3, r2
 *   @0x227104 ble 0x22715c <_vorbis_block_alloc+0x78>
 *   @0x227108 ldr r7, [r0, #0x44]
 *   @0x22710c cmp r7, #0
 *   @0x227110 beq 0x227138 <_vorbis_block_alloc+0x54>
 *   @0x227114 mov r0, #8
 *   @0x227118 bl 0xb6544 <malloc@plt>
 *   @0x22711c ldr r2, [r4, #0x54]
 *   @0x227120 ldr r3, [r4, #0x50]
 *   @0x227124 add r6, r3, r6
 *   @0x227128 str r7, [r0]
 *   @0x22712c str r2, [r0, #0x4]
 *   @0x227130 str r0, [r4, #0x54]
 *   @0x227134 str r6, [r4, #0x50]
 *   @0x227138 str r5, [r4, #0x4c]
 *   @0x22713c mov r0, r5
 *   @0x227140 bl 0xb6544 <malloc@plt>
 *   @0x227144 mov r6, #0
 *   @0x227148 mov r3, r5
 *   @0x22714c str r0, [r4, #0x44]
 *   @0x227150 str r3, [r4, #0x48]
 *   @0x227154 add r0, r0, r6
 *   @0x227158 pop {r3, r4, r5, r6, r7, pc}
 *   @0x22715c ldr r0, [r0, #0x44]
 *   @0x227160 b 0x227150 <_vorbis_block_alloc+0x6c>
 *
 * ══ §192/230 CPhysicsObject::ApplyForce(float, float, float, float)  0x237058  size 128  32 条（0x237058..0x2370d8）
 * @func 0x237058 0x2370d8  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0xa0×1
 * VFP 指令 19 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x237058 ldr r0, [r0]
 *   @0x23705c vmov s15, r3
 *   @0x237060 vmov s14, r1
 *   @0x237064 vmov s13, r2
 *   @0x237068 ldr r3, [r0]
 *   @0x23706c cmp r3, #2
 *   @0x237070 bxne lr
 *   @0x237074 ldrh r3, [r0, #4]
 *   @0x237078 tst r3, #2
 *   @0x23707c beq 0x2370c4 <_ZN14CPhysicsObject10ApplyForceEffff+0x6c>
 *   @0x237080 vldr s12, [r0, #64]
 *   @0x237084 vsub.f32 s13, s13, s12
 *   @0x237088 vldr s9, [r0, #60]
 *   @0x23708c vldr s10, [r0, #92]
 *   @0x237090 vldr s11, [r0, #100]
 *   @0x237094 vldr s12, [r0, #96]
 *   @0x237098 vmul.f32 s13, s15, s13
 *   @0x23709c vsub.f32 s14, s14, s9
 *   @0x2370a0 vldr s9, [sp]
 *   @0x2370a4 vnmls.f32 s13, s9, s14
 *   @0x2370a8 vadd.f32 s15, s10, s15
 *   @0x2370ac vadd.f32 s13, s11, s13
 *   @0x2370b0 vstr s15, [r0, #92]
 *   @0x2370b4 vadd.f32 s15, s12, s9
 *   @0x2370b8 vstr s13, [r0, #100]
 *   @0x2370bc vstr s15, [r0, #96]
 *   @0x2370c0 bx lr
 *   @0x2370c4 orr r3, r3, #2
 *   @0x2370c8 mov r2, #0
 *   @0x2370cc strh r3, [r0, #4]
 *   @0x2370d0 str r2, [r0, #0xa0]
 *   @0x2370d4 b 0x237080 <_ZN14CPhysicsObject10ApplyForceEffff+0x28>
 *
 * ══ §193/230 CPhysicsWorld::DeleteParticleCircleRegion(float, float, float)  0x239f50  size 128  32 条（0x239f50..0x239fd0）
 * @func 0x239f50 0x239fd0  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2World::DestroyParticlesInShape(b2Shape const&, b2Transform const&, bool)
 * 字段偏移 top8: 0x10×2 / 0x-4×1 / 0x5c×1 / 0x18×1 / 0x14×1 / 0x20×1 / 0x24×1 / 0xc×1
 * VFP 指令 10 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x239f50 vmov s12, r3
 *   @0x239f54 vldr s15, [r0, #96]
 *   @0x239f58 str lr, [sp, #-0x4]!
 *   @0x239f5c vmul.f32 s13, s15, s12
 *   @0x239f60 sub sp, sp, #44
 *   @0x239f64 vmov s12, r1
 *   @0x239f68 ldr r12, [pc, #0x5c]
 *   @0x239f6c mov lr, #0
 *   @0x239f70 mov r3, lr
 *   @0x239f74 add r1, sp, #20
 *   @0x239f78 ldr r12, [pc, r12]
 *   @0x239f7c ldr r0, [r0, #0x10]
 *   @0x239f80 add r12, r12, #8
 *   @0x239f84 str lr, [sp, #0x18]
 *   @0x239f88 str r12, [sp, #0x14]
 *   @0x239f8c mov r12, #0
 *   @0x239f90 str r12, [sp, #0x20]
 *   @0x239f94 str r12, [sp, #0x24]
 *   @0x239f98 str r12, [sp, #0xc]
 *   @0x239f9c mov r12, #1065353216
 *   @0x239fa0 str r12, [sp, #0x10]
 *   @0x239fa4 vstr s13, [sp, #28]
 *   @0x239fa8 vmov s13, r2
 *   @0x239fac vmul.f32 s14, s15, s12
 *   @0x239fb0 add r2, sp, #4
 *   @0x239fb4 vmul.f32 s15, s15, s13
 *   @0x239fb8 vstr s14, [sp, #4]
 *   @0x239fbc vstr s15, [sp, #8]
 *   @0x239fc0 bl 0x2cb4d8 <_ZN7b2World23DestroyParticlesInShapeERK7b2ShapeRK11b2Transformb>
 *   @0x239fc4 add sp, sp, #44
 *   @0x239fc8 ldr pc, [sp], #4
 *   @0x239fcc andseq r7, r11, r4, lsr r5
 *
 * ══ §194/230 F_JS_Array_getLength(RValue&, CInstance*, CInstance*, int, RValue*)  0x23ce24  size 128  32 条（0x23ce24..0x23cea4）
 * @func 0x23ce24 0x23cea4  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6574 / YYObjectBase::InternalGetYYVar(int)
 * 字段偏移 top8: 0x4×2 / 0xc×2 / 0x6c×1 / 0x40×1 / 0x24×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23ce24 push {r3, r4, r5, lr}
 *   @0x23ce28 mov r5, r1
 *   @0x23ce2c ldr r1, [pc, #0x6c]
 *   @0x23ce30 mov r3, #0
 *   @0x23ce34 mov r4, r0
 *   @0x23ce38 str r3, [r0]
 *   @0x23ce3c str r3, [r0, #0x4]
 *   @0x23ce40 add r1, pc, r1
 *   @0x23ce44 str r3, [r0, #0xc]
 *   @0x23ce48 ldr r0, [r5, #0x40]
 *   @0x23ce4c bl 0xb6574 <strcmp@plt>
 *   @0x23ce50 cmp r0, #0
 *   @0x23ce54 popne {r3, r4, r5, pc}
 *   @0x23ce58 ldr r0, [r5, #0x4]
 *   @0x23ce5c cmp r0, #0
 *   @0x23ce60 beq 0x23ce90 <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x23ce64 add r0, r0, #16
 *   @0x23ce68 ldr r3, [r0, #0xc]
 *   @0x23ce6c cmp r3, #6
 *   @0x23ce70 popne {r3, r4, r5, pc}
 *   @0x23ce74 ldr r3, [r0]
 *   @0x23ce78 ldr r2, [r3, #0x24]
 *   @0x23ce7c vmov s15, r2
 *   @0x23ce80 vcvt.f64.u32 d7, s15
 *   @0x23ce84 vmov r2, r3, d7
 *   @0x23ce88 stm r4, {r2, r3}
 *   @0x23ce8c pop {r3, r4, r5, pc}
 *   @0x23ce90 mov r0, r5
 *   @0x23ce94 mov r1, #1
 *   @0x23ce98 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x23ce9c b 0x23ce68 <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x23cea0 ldrdeq r7, r8, [pc], -r8
 *
 * ══ §195/230 JS_SetupFunction(void (*)(RValue&, CInstance*, CInstance*, int, RValue*), int, bool)  0x240f7c  size 128  32 条（0x240f7c..0x240ffc）
 * @func 0x240f7c 0x240ffc  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JS_StandardScriptRefConstructor(RValue&, CInstance*, CInstance*, int, RValue*) / YYObjectBase::Add(char const*, int, int)
 * 字段偏移 top8: 0x8×1 / 0x3c×1 / 0x68×1 / 0x90×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x240f7c push {r4, r5, r6, r7, lr}
 *   @0x240f80 sub sp, sp, #28
 *   @0x240f84 mov r3, #0
 *   @0x240f88 mov r6, r0
 *   @0x240f8c mov r7, r2
 *   @0x240f90 str r3, [sp]
 *   @0x240f94 mov r2, r3
 *   @0x240f98 mov r5, r1
 *   @0x240f9c add r0, sp, #8
 *   @0x240fa0 mov r1, r3
 *   @0x240fa4 bl 0x240d20 <_Z31JS_StandardScriptRefConstructorR6RValueP9CInstanceS2_iPS_>
 *   @0x240fa8 ldr r4, [sp, #0x8]
 *   @0x240fac ldr r3, [pc, #0x3c]
 *   @0x240fb0 cmp r7, #0
 *   @0x240fb4 ldr r3, [pc, r3]
 *   @0x240fb8 str r6, [r4, #0x68]
 *   @0x240fbc str r3, [r4, #0x90]
 *   @0x240fc0 ldrne r3, [pc, #0x2c]
 *   @0x240fc4 ldrne r3, [pc, r3]
 *   @0x240fc8 strne r3, [r4, #0x94]
 *   @0x240fcc ldr r1, [pc, #0x24]
 *   @0x240fd0 mov r0, r4
 *   @0x240fd4 mov r2, r5
 *   @0x240fd8 mov r3, #0
 *   @0x240fdc add r1, pc, r1
 *   @0x240fe0 bl 0x199960 <_ZN12YYObjectBase3AddEPKcii>
 *   @0x240fe4 mov r0, r4
 *   @0x240fe8 add sp, sp, #28
 *   @0x240fec pop {r4, r5, r6, r7, pc}
 *   @0x240ff0 andseq r0, r11, r8, ror #10
 *   @0x240ff4 andseq r0, r11, r12, asr r5
 *   @0x240ff8 muleq lr, r0, r8
 *
 * ══ §196/230 JS_Boolean_prototype_valueOf(RValue&, CInstance*, CInstance*, int, RValue*)  0x252c94  size 128  32 条（0x252c94..0x252d14）
 * @func 0x252c94 0x252d14  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6574 / YYObjectBase::FindValue(char const*)
 * 字段偏移 top8: 0x64×1 / 0x40×1 / 0x4c×1 / 0xc×1 / 0x4×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x252c94 push {r4, r5, r6, lr}
 *   @0x252c98 mov r5, r1
 *   @0x252c9c ldr r1, [pc, #0x64]
 *   @0x252ca0 mov r4, r0
 *   @0x252ca4 ldr r0, [r5, #0x40]
 *   @0x252ca8 add r1, pc, r1
 *   @0x252cac bl 0xb6574 <strcmp@plt>
 *   @0x252cb0 subs r6, r0, #0
 *   @0x252cb4 bne 0x252cf8 <_Z28JS_Boolean_prototype_valueOfR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x252cb8 ldr r1, [pc, #0x4c]
 *   @0x252cbc mov r0, r5
 *   @0x252cc0 add r1, pc, r1
 *   @0x252cc4 bl 0x196b84 <_ZN12YYObjectBase9FindValueEPKc>
 *   @0x252cc8 cmp r0, #0
 *   @0x252ccc popeq {r4, r5, r6, pc}
 *   @0x252cd0 mov r3, #13
 *   @0x252cd4 str r3, [r4, #0xc]
 *   @0x252cd8 ldm r0, {r2, r3}
 *   @0x252cdc str r6, [r4]
 *   @0x252ce0 orrs r1, r2, r3
 *   @0x252ce4 movne r3, #0
 *   @0x252ce8 moveq r3, r6
 *   @0x252cec movtne r3, #0x3ff0
 *   @0x252cf0 str r3, [r4, #0x4]
 *   @0x252cf4 pop {r4, r5, r6, pc}
 *   @0x252cf8 ldr r0, [pc, #0x10]
 *   @0x252cfc pop {r4, r5, r6, lr}
 *   @0x252d00 add r0, pc, r0
 *   @0x252d04 b 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x252d08 andseq r2, r0, r0, ror #16
 *   @0x252d0c andseq r2, r0, r0, asr r8
 *   @0x252d10 andseq r3, r0, r4, lsr #17
 *
 * ══ §197/230 json_object_get_boolean  0x27ea78  size 128  32 条（0x27ea78..0x27eaf8）
 * @func 0x27ea78 0x27eaf8  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18×3
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27ea78 cmp r0, #0
 *   @0x27ea7c bxeq lr
 *   @0x27ea80 ldr r3, [r0]
 *   @0x27ea84 sub r3, r3, #1
 *   @0x27ea88 cmp r3, #5
 *   @0x27ea8c addls pc, pc, r3, lsl #2
 *   @0x27ea90 b 0x27eaf0 <json_object_get_boolean+0x78>
 *   @0x27ea94 b 0x27eac0 <json_object_get_boolean+0x48>
 *   @0x27ea98 b 0x27eac8 <json_object_get_boolean+0x50>
 *   @0x27ea9c b 0x27eae0 <json_object_get_boolean+0x68>
 *   @0x27eaa0 b 0x27eaf0 <json_object_get_boolean+0x78>
 *   @0x27eaa4 b 0x27eaf0 <json_object_get_boolean+0x78>
 *   @0x27eaa8 b 0x27eaac <json_object_get_boolean+0x34>
 *   @0x27eaac ldr r3, [r0, #0x18]
 *   @0x27eab0 ldrb r0, [r3]
 *   @0x27eab4 adds r0, r0, #0
 *   @0x27eab8 movne r0, #1
 *   @0x27eabc bx lr
 *   @0x27eac0 ldr r0, [r0, #0x18]
 *   @0x27eac4 bx lr
 *   @0x27eac8 vldr d7, [r0, #24]
 *   @0x27eacc vcmp.f64 d7, #0
 *   @0x27ead0 vmrs APSR_nzcv, fpscr
 *   @0x27ead4 moveq r0, #0
 *   @0x27ead8 movne r0, #1
 *   @0x27eadc bx lr
 *   @0x27eae0 ldr r0, [r0, #0x18]
 *   @0x27eae4 adds r0, r0, #0
 *   @0x27eae8 movne r0, #1
 *   @0x27eaec bx lr
 *   @0x27eaf0 mov r0, #0
 *   @0x27eaf4 bx lr
 *
 * ══ §198/230 _spBaseTimeline_create  0x282a10  size 128  32 条（0x282a10..0x282a90）
 * @func 0x282a10 0x282a90  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _calloc×2 / _spCurveTimeline_init
 * 字段偏移 top8: 0x68×1 / 0x40×1 / 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x282a10 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x282a14 mov r5, r0
 *   @0x282a18 ldr r6, [pc, #0x68]
 *   @0x282a1c sub sp, sp, #12
 *   @0x282a20 mov r9, r1
 *   @0x282a24 mov r7, r2
 *   @0x282a28 add r6, pc, r6
 *   @0x282a2c mov r8, r3
 *   @0x282a30 mov r1, #24
 *   @0x282a34 mov r3, #233
 *   @0x282a38 mov r2, r6
 *   @0x282a3c mov r0, #1
 *   @0x282a40 bl 0x285c4c <_calloc>
 *   @0x282a44 ldr r3, [pc, #0x40]
 *   @0x282a48 mov r1, r9
 *   @0x282a4c mov r2, r5
 *   @0x282a50 str r8, [sp]
 *   @0x282a54 ldr r3, [pc, r3]
 *   @0x282a58 mov r4, r0
 *   @0x282a5c bl 0x2816d8 <_spCurveTimeline_init>
 *   @0x282a60 mul r0, r7, r5
 *   @0x282a64 mov r2, r6
 *   @0x282a68 mov r1, #4
 *   @0x282a6c mov r3, #237
 *   @0x282a70 str r0, [r4, #0xc]
 *   @0x282a74 bl 0x285c4c <_calloc>
 *   @0x282a78 str r0, [r4, #0x10]
 *   @0x282a7c mov r0, r4
 *   @0x282a80 add sp, sp, #12
 *   @0x282a84 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x282a88 andeq r4, sp, r8, lsr #20
 *   @0x282a8c andseq lr, r6, r12, asr #28
 *
 * ══ §199/230 spBoneData_create  0x285a44  size 128  32 条（0x285a44..0x285ac4）
 * @func 0x285a44 0x285ac4  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _calloc / 0xb6538 / _malloc / 0xb65a4
 * 字段偏移 top8: 0x6c×1 / 0x4×1 / 0x8×1 / 0x2c×1 / 0x30×1 / 0x1c×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x285a44 push {r4, r5, r6, r7, r8, lr}
 *   @0x285a48 mov r3, #36
 *   @0x285a4c ldr r6, [pc, #0x6c]
 *   @0x285a50 mov r5, r1
 *   @0x285a54 mov r8, r0
 *   @0x285a58 mov r7, r2
 *   @0x285a5c add r6, pc, r6
 *   @0x285a60 mov r1, #52
 *   @0x285a64 mov r0, #1
 *   @0x285a68 mov r2, r6
 *   @0x285a6c bl 0x285c4c <_calloc>
 *   @0x285a70 mov r4, r0
 *   @0x285a74 str r8, [r0]
 *   @0x285a78 mov r0, r5
 *   @0x285a7c bl 0xb6538 <strlen@plt>
 *   @0x285a80 mov r1, r6
 *   @0x285a84 mov r2, #38
 *   @0x285a88 add r0, r0, #1
 *   @0x285a8c bl 0x285c10 <_malloc>
 *   @0x285a90 mov r1, r5
 *   @0x285a94 str r0, [r4, #0x4]
 *   @0x285a98 bl 0xb65a4 <strcpy@plt>
 *   @0x285a9c mov r1, #1065353216
 *   @0x285aa0 mov r3, #1
 *   @0x285aa4 str r7, [r4, #0x8]
 *   @0x285aa8 mov r0, r4
 *   @0x285aac str r3, [r4, #0x2c]
 *   @0x285ab0 str r3, [r4, #0x30]
 *   @0x285ab4 str r1, [r4, #0x1c]
 *   @0x285ab8 str r1, [r4, #0x20]
 *   @0x285abc pop {r4, r5, r6, r7, r8, pc}
 *   @0x285ac0 andeq r1, sp, r0, asr #25
 *
 * ══ §200/230 spMeshAttachment_setParentMesh  0x287654  size 128  32 条（0x287654..0x2876d4）
 * @func 0x287654 0x2876d4  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x20×2 / 0x14×2 / 0x10×2 / 0x1c×2 / 0x18×2 / 0x58×2 / 0x64×2 / 0x60×2
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x287654 cmp r1, #0
 *   @0x287658 str r1, [r0, #0x7c]
 *   @0x28765c push {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x287660 beq 0x2876cc <spMeshAttachment_setParentMesh+0x78>
 *   @0x287664 ldr r11, [r1, #0x20]
 *   @0x287668 vldr s14, [r1, #140]
 *   @0x28766c ldr r10, [r1, #0x14]
 *   @0x287670 vldr s15, [r1, #144]
 *   @0x287674 ldr r9, [r1, #0x10]
 *   @0x287678 ldr r8, [r1, #0x1c]
 *   @0x28767c ldr r7, [r1, #0x18]
 *   @0x287680 ldr r6, [r1, #0x58]
 *   @0x287684 ldr r5, [r1, #0x64]
 *   @0x287688 ldr r4, [r1, #0x60]
 *   @0x28768c ldr r12, [r1, #0x78]
 *   @0x287690 ldr r2, [r1, #0x88]
 *   @0x287694 ldr r3, [r1, #0x84]
 *   @0x287698 vstr s14, [r0, #140]
 *   @0x28769c str r11, [r0, #0x20]
 *   @0x2876a0 vstr s15, [r0, #144]
 *   @0x2876a4 str r10, [r0, #0x14]
 *   @0x2876a8 str r9, [r0, #0x10]
 *   @0x2876ac str r8, [r0, #0x1c]
 *   @0x2876b0 str r7, [r0, #0x18]
 *   @0x2876b4 str r6, [r0, #0x58]
 *   @0x2876b8 str r5, [r0, #0x64]
 *   @0x2876bc str r4, [r0, #0x60]
 *   @0x2876c0 str r12, [r0, #0x78]
 *   @0x2876c4 str r2, [r0, #0x88]
 *   @0x2876c8 str r3, [r0, #0x84]
 *   @0x2876cc pop {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x2876d0 bx lr
 *
 * ══ §201/230 png_write_tIME  0x2b2490  size 128  32 条（0x2b2490..0x2b2510）
 * @func 0x2b2490 0x2b2510  size 128  32 条
 * 部分覆盖: 本节 32/59 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_write_tIME+0x3e / png_warning / png_save_uint_16
 * 字段偏移 top8: 0x70×1 / 0x6×1 / 0x2×1 / 0x3×1 / 0x5×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b2490 push {r0, r1, r2, r3, r4, r5, r6, lr}
 *   @0x2b2494 ldr r3, [pc, #0x70]
 *   @0x2b2498 add r3, pc
 *   @0x2b249c ldmdbvc r11, {r2, r3, r5, r6, r8, r9, r10, r11}
 *   @0x2b24a0 str r0, [sp]
 *   @0x2b24a4 stmvc r11, {r2, r12, sp}
 *   @0x2b24a8 subs r3, #0x1
 *   @0x2b24ac bhi 0x2b24c2 <png_write_tIME+0x32>
 *   @0x2b24b0 subs r3, #0x1
 *   @0x2b24b4 bhi 0x2b24c2 <png_write_tIME+0x32>
 *   @0x2b24b8 cmp r3, #0x17
 *   @0x2b24bc ldrb r3, [r1, #0x6]
 *   @0x2b24c0 bls 0x2b24ce <png_write_tIME+0x3e>
 *   @0x2b24c4 mov r0, r6
 *   @0x2b24c8 bl 0x2a6474 <png_warning>
 *   @0x2b24cc b 0x2b2502 <png_write_tIME+0x72>
 *   @0x2b24d0 ldrh r1, [r1]
 *   @0x2b24d4 bl 0x2b1138 <png_save_uint_16>
 *   @0x2b24d8 ldrb r3, [r4, #0x2]
 *   @0x2b24dc mov r1, sp
 *   @0x2b24e0 strb.w r3, [sp, #0xa]
 *   @0x2b24e4 ldrb r3, [r4, #0x3]
 *   @0x2b24e8 stmdbvc r3!, {r0, r1, r3, r12, sp}
 *   @0x2b24ec strb.w r3, [sp, #0xc]
 *   @0x2b24f0 ldrb r3, [r4, #0x5]
 *   @0x2b24f4 stmibvc r3!, {r0, r2, r3, r12, sp}
 *   @0x2b24f8 strb.w r3, [sp, #0xe]
 *   @0x2b24fc movs r3, #0x7
 *   @0x2b2500 .word 0xb004fedd
 *   @0x2b2504 pop {r4, r5, r6, pc}
 *   @0x2b2508 bhi 0x2b249c <png_write_tIME+0xc>
 *   @0x2b250c stm r1!, {r0, r2, r3, r5, r6, r7}
 *
 * ══ §202/230 jpeg_open_backing_store  0x2c13ac  size 128  32 条（0x2c13ac..0x2c142c）
 * @func 0x2c13ac 0x2c142c  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6f64 / 0xb6568
 * 字段偏移 top8: 0x4c×3 / 0xc×1 / 0x30×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c13ac push {r3, r4, r5, lr}
 *   @0x2c13b0 mov r4, r1
 *   @0x2c13b4 mov r5, r0
 *   @0x2c13b8 bl 0xb6f64 <tmpfile@plt>
 *   @0x2c13bc cmp r0, #0
 *   @0x2c13c0 str r0, [r4, #0xc]
 *   @0x2c13c4 beq 0x2c13e8 <jpeg_open_backing_store+0x3c>
 *   @0x2c13c8 ldr r1, [pc, #0x4c]
 *   @0x2c13cc ldr r2, [pc, #0x4c]
 *   @0x2c13d0 ldr r3, [pc, #0x4c]
 *   @0x2c13d4 add r1, pc, r1
 *   @0x2c13d8 add r2, pc, r2
 *   @0x2c13dc add r3, pc, r3
 *   @0x2c13e0 stm r4, {r1, r2, r3}
 *   @0x2c13e4 pop {r3, r4, r5, pc}
 *   @0x2c13e8 ldr r3, [r5]
 *   @0x2c13ec mov r12, #63
 *   @0x2c13f0 ldr r1, [pc, #0x30]
 *   @0x2c13f4 mov r2, #80
 *   @0x2c13f8 add r0, r3, #24
 *   @0x2c13fc str r12, [r3, #0x14]
 *   @0x2c1400 add r1, pc, r1
 *   @0x2c1404 bl 0xb6568 <strncpy@plt>
 *   @0x2c1408 ldr r3, [r5]
 *   @0x2c140c mov r0, r5
 *   @0x2c1410 ldr r3, [r3]
 *   @0x2c1414 blx r3
 *   @0x2c1418 b 0x2c13c8 <jpeg_open_backing_store+0x1c>
 *   @0x2c141c .word 0xffffff20
 *   @0x2c1420 .word 0xfffffe9c
 *   @0x2c1424 .word 0xfffffe90
 *   @0x2c1428 andeq sp, r6, r6, lsr r7
 *
 * ══ §203/230 b2EPCollider::ComputeEdgeSeparation()  0x2dd1a4  size 128  32 条（0x2dd1a4..0x2dd224）
 * @func 0x2dd1a4 0x2dd224  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x80×1 / 0xf8×1 / 0x4×1
 * VFP 指令 16 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2dd1a4 ldr r12, [r1, #0x80]
 *   @0x2dd1a8 mov r2, #1
 *   @0x2dd1ac ldrb r3, [r1, #0xf8]
 *   @0x2dd1b0 vldr s14, [pc, #104]
 *   @0x2dd1b4 cmp r12, #0
 *   @0x2dd1b8 str r2, [r0]
 *   @0x2dd1bc eor r3, r3, r2
 *   @0x2dd1c0 vstr s14, [r0, #8]
 *   @0x2dd1c4 str r3, [r0, #0x4]
 *   @0x2dd1c8 bxle lr
 *   @0x2dd1cc mov r3, r1
 *   @0x2dd1d0 mov r2, #0
 *   @0x2dd1d4 vldr s9, [r1, #164]
 *   @0x2dd1d8 vldr s10, [r1, #168]
 *   @0x2dd1dc vldr s11, [r1, #212]
 *   @0x2dd1e0 vldr s12, [r1, #216]
 *   @0x2dd1e4 vldr s15, [r3, #4]
 *   @0x2dd1e8 vsub.f32 s15, s15, s10
 *   @0x2dd1ec vldr s13, [r3]
 *   @0x2dd1f0 add r2, r2, #1
 *   @0x2dd1f4 add r3, r3, #8
 *   @0x2dd1f8 vmul.f32 s15, s15, s12
 *   @0x2dd1fc vsub.f32 s13, s13, s9
 *   @0x2dd200 vmla.f32 s15, s13, s11
 *   @0x2dd204 vcmpe.f32 s15, s14
 *   @0x2dd208 vmrs APSR_nzcv, fpscr
 *   @0x2dd20c vmovmi.f32 s14, s15
 *   @0x2dd210 cmp r2, r12
 *   @0x2dd214 bne 0x2dd1e4 <_ZN12b2EPCollider21ComputeEdgeSeparationEv+0x40>
 *   @0x2dd218 vstr s14, [r0, #8]
 *   @0x2dd21c bx lr
 *   @0x2dd220 svcvc #0x7fffff
 *
 * ══ §204/230 b2DynamicTree::GetMaxBalance() const  0x2df980  size 128  32 条（0x2df980..0x2dfa00）
 * @func 0x2df980 0x2dfa00  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2DynamicTree::GetMaxBalance() const+0x78 / b2DynamicTree::GetMaxBalance() const+0x64
 * 字段偏移 top8: 0x20×3 / 0x4×2 / 0x-4×1 / 0xc×1 / 0x1c×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2df980 str r4, [sp, #-0x4]!
 *   @0x2df984 ldr r4, [r0, #0xc]
 *   @0x2df988 cmp r4, #0
 *   @0x2df98c ble 0x2df9f8 <_ZNK13b2DynamicTree13GetMaxBalanceEv+0x78>
 *   @0x2df990 ldr r12, [r0, #0x4]
 *   @0x2df994 add r4, r4, r4, lsl #3
 *   @0x2df998 mov r0, #0
 *   @0x2df99c add r4, r12, r4, lsl #2
 *   @0x2df9a0 mov r3, r12
 *   @0x2df9a4 ldr r2, [r3, #0x20]
 *   @0x2df9a8 cmp r2, #1
 *   @0x2df9ac ble 0x2df9e4 <_ZNK13b2DynamicTree13GetMaxBalanceEv+0x64>
 *   @0x2df9b0 ldr r1, [r3, #0x1c]
 *   @0x2df9b4 ldr r2, [r3, #0x18]
 *   @0x2df9b8 add r1, r1, r1, lsl #3
 *   @0x2df9bc add r2, r2, r2, lsl #3
 *   @0x2df9c0 add r1, r12, r1, lsl #2
 *   @0x2df9c4 add r2, r12, r2, lsl #2
 *   @0x2df9c8 ldr r1, [r1, #0x20]
 *   @0x2df9cc ldr r2, [r2, #0x20]
 *   @0x2df9d0 rsb r2, r2, r1
 *   @0x2df9d4 cmp r2, #0
 *   @0x2df9d8 rsblt r2, r2, #0
 *   @0x2df9dc cmp r0, r2
 *   @0x2df9e0 movlt r0, r2
 *   @0x2df9e4 add r3, r3, #36
 *   @0x2df9e8 cmp r3, r4
 *   @0x2df9ec bne 0x2df9a4 <_ZNK13b2DynamicTree13GetMaxBalanceEv+0x24>
 *   @0x2df9f0 ldr r4, [sp], #4
 *   @0x2df9f4 bx lr
 *   @0x2df9f8 mov r0, #0
 *   @0x2df9fc b 0x2df9f0 <_ZNK13b2DynamicTree13GetMaxBalanceEv+0x70>
 *
 * ══ §205/230 FT_Get_Glyph_Name  0x2e5af8  size 128  32 条（0x2e5af8..0x2e5b78）
 * @func 0x2e5af8 0x2e5b78  size 128  32 条
 * 部分覆盖: 本节 32/59 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1 / 0x28×1 / 0x60×1 / 0x20×1 / 0x38×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e5af8 push.w {r4, r5, r6, r7, r8, lr}
 *   @0x2e5afc mov r7, r1
 *   @0x2e5b00 mov r8, r3
 *   @0x2e5b04 cmp r0, #0x0
 *   @0x2e5b08 cbnz r2, 0x2e5b10 <FT_Get_Glyph_Name+0x18>
 *   @0x2e5b0c pop.w {r4, r5, r6, r7, r8, pc}
 *   @0x2e5b10 cmp r3, #0x0
 *   @0x2e5b14 movs r3, #0x0
 *   @0x2e5b18 ldr r3, [r0, #0x10]
 *   @0x2e5b1c bge 0x2e5b6c <FT_Get_Glyph_Name+0x74>
 *   @0x2e5b20 lsls r2, r3, #0x16
 *   @0x2e5b24 ldr.w r3, [r0, #0x80]
 *   @0x2e5b28 ldr r0, [r3, #0x28]
 *   @0x2e5b2c beq 0x2e5b0a <FT_Get_Glyph_Name+0x12>
 *   @0x2e5b30 ldr r2, [r4, #0x60]
 *   @0x2e5b34 ldr r3, [r3, #0x20]
 *   @0x2e5b38 ldr r1, [pc, #0x38]
 *   @0x2e5b3c add r1, pc
 *   @0x2e5b40 ldr.w r3, [r4, #0x80]
 *   @0x2e5b44 cmp r0, #0x0
 *   @0x2e5b48 movne r2, r0
 *   @0x2e5b4c addsvs r0, r10, #268435456
 *   @0x2e5b50 beq 0x2e5b0a <FT_Get_Glyph_Name+0x12>
 *   @0x2e5b54 cmp r6, #0x0
 *   @0x2e5b58 mov r0, r4
 *   @0x2e5b5c mov r2, r5
 *   @0x2e5b60 blx r6
 *   @0x2e5b64 .word 0x202381f0
 *   @0x2e5b68 pop.w {r4, r5, r6, r7, r8, pc}
 *   @0x2e5b6c movs r0, #0x10
 *   @0x2e5b70 svclt #0x81f0
 *   @0x2e5b74 ldrh r0, [r6, #0x1c]
 *
 * ══ §206/230 FT_Stream_EnterFrame  0x2e7e22  size 128  32 条（0x2e7e22..0x2e7ea2）
 * @func 0x2e7e22 0x2e7ea2  size 128  32 条
 * 部分覆盖: 本节 32/59 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FT_Stream_EnterFrame+0x20 / ft_mem_qalloc / ft_mem_free / FT_Stream_EnterFrame+0x1a
 * 字段偏移 top8: 0x4×4 / 0x14×1 / 0x8×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e7e22 push.w {r0, r1, r4, r5, r6, r7, r8, lr}
 *   @0x2e7e26 movs r3, #0x0
 *   @0x2e7e2a mov r4, r0
 *   @0x2e7e2e mov r5, r1
 *   @0x2e7e32 cbz r3, 0x2e7e80 <FT_Stream_EnterFrame+0x5e>
 *   @0x2e7e36 ldr.w r8, [r0, #0x1c]
 *   @0x2e7e3a bls 0x2e7e42 <FT_Stream_EnterFrame+0x20>
 *   @0x2e7e3e str r3, [sp, #0x4]
 *   @0x2e7e42 add r2, sp, #0x4
 *   @0x2e7e46 bl 0x2e7100 <ft_mem_qalloc>
 *   @0x2e7e4a ldr r6, [sp, #0x4]
 *   @0x2e7e4e str r0, [r4]
 *   @0x2e7e52 ldr r7, [r4, #0x14]
 *   @0x2e7e56 ldr r1, [r4, #0x8]
 *   @0x2e7e5a blx r7
 *   @0x2e7e5e mov r7, r0
 *   @0x2e7e62 mov r0, r8
 *   @0x2e7e66 bl 0x2e7336 <ft_mem_free>
 *   @0x2e7e6a movs r3, #0x55
 *   @0x2e7e6e str r3, [sp, #0x4]
 *   @0x2e7e72 add r5, r3
 *   @0x2e7e76 str r3, [r4, #0x20]
 *   @0x2e7e7a add r7, r3
 *   @0x2e7e7e b 0x2e7e9a <FT_Stream_EnterFrame+0x78>
 *   @0x2e7e82 cmp r3, r2
 *   @0x2e7e86 subs r2, r2, r3
 *   @0x2e7e8a blo 0x2e7e3c <FT_Stream_EnterFrame+0x1a>
 *   @0x2e7e8e add r5, r3
 *   @0x2e7e92 add r2, r3
 *   @0x2e7e96 add r2, r1
 *   @0x2e7e9a ldr r0, [sp, #0x4]
 *   @0x2e7e9e pop.w {r4, r5, r6, r7, r8, pc}
 *
 * ══ §207/230 png_destroy_write_struct  0x2b0692  size 126  32 条（0x2b0692..0x2b0710）
 * @func 0x2b0692 0x2b0712  size 128  32 条
 * 部分覆盖: 本节 32/57 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_write_destroy
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b0692 push.w {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x2b0696 mov r8, r1
 *   @0x2b069a cbz r0, 0x2b06a8 <png_destroy_write_struct+0x16>
 *   @0x2b069e ldr.w r7, [r4, #0x2f0]
 *   @0x2b06a2 ldr.w r6, [r4, #0x2e8]
 *   @0x2b06a6 b 0x2b06ae <png_destroy_write_struct+0x1c>
 *   @0x2b06aa mov r6, r0
 *   @0x2b06ae cmp.w r8, #0x0
 *   @0x2b06b2 beq 0x2b06f6 <png_destroy_write_struct+0x64>
 *   @0x2b06b6 .word 0xf1b99000
 *   @0x2b06ba andsle r0, r11, r0, lsl #30
 *   @0x2b06be cbz r4, 0x2b06e6 <png_destroy_write_struct+0x54>
 *   @0x2b06c2 qsub8mi r3, r0, pc
 *   @0x2b06c6 mov r1, r9
 *   @0x2b06ca .word 0xf7f572ff
 *   @0x2b06ce .word 0xf8d4fa78
 *   @0x2b06d2 teqlt r11, r12, asr #5
 *   @0x2b06d6 mov r0, r4
 *   @0x2b06da .word 0xf7f612d0
 *   @0x2b06de movwhs pc, #0xb0e
 *   @0x2b06e2 str.w r3, [r4, #0x2cc]
 *   @0x2b06e6 mov r0, r9
 *   @0x2b06ea mov r2, r6
 *   @0x2b06ee movwhs pc, #0xab7
 *   @0x2b06f2 str.w r3, [r8]
 *   @0x2b06f6 cbz r4, 0x2b070c <png_destroy_write_struct+0x7a>
 *   @0x2b06fa bl 0x2b05e8 <png_write_destroy>
 *   @0x2b06fe mov r0, r4
 *   @0x2b0702 mov r2, r6
 *   @0x2b0706 movwhs pc, #0xaab
 *   @0x2b070a str r3, [r5]
 *   @0x2b070e ldrlt r8, [r0, #-0x3f8]
 *
 * ══ §208/230 ft_mem_qrealloc  0x2e8010  size 126  32 条（0x2e8010..0x2e808e）
 * @func 0x2e8010 0x2e8090  size 128  32 条
 * 部分覆盖: 本节 32/55 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ft_mem_free / __divsi3 / ft_mem_alloc
 * 字段偏移 top8: 0x4×2 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e8010 push.w {r0, r1, r4, r5, r6, r7, r8, lr}
 *   @0x2e8014 subs.w r8, r2, #0x0
 *   @0x2e8018 mov r7, r3
 *   @0x2e801c mov.w r3, #0x0
 *   @0x2e8020 mov r5, r1
 *   @0x2e8024 str r3, [sp, #0x4]
 *   @0x2e8028 cmp r7, r3
 *   @0x2e802c cmp r1, r3
 *   @0x2e8030 movs r3, #0x6
 *   @0x2e8034 cbz r7, 0x2e8038 <ft_mem_qrealloc+0x28>
 *   @0x2e8038 mov r1, r4
 *   @0x2e803c bl 0x2e7336 <ft_mem_free>
 *   @0x2e8040 movs r4, #0x0
 *   @0x2e8044 mvn r0, #0x80000000
 *   @0x2e8048 blx 0x318d10 <__divsi3>
 *   @0x2e804c cmp r7, r0
 *   @0x2e8050 movs r3, #0xa
 *   @0x2e8054 mul r2, r5, r7
 *   @0x2e8058 cmp.w r8, #0x0
 *   @0x2e805c bne 0x2e806a <ft_mem_qrealloc+0x5a>
 *   @0x2e8060 mov r0, r6
 *   @0x2e8064 bl 0x2e7126 <ft_mem_alloc>
 *   @0x2e8068 b 0x2e807e <ft_mem_qrealloc+0x6e>
 *   @0x2e806c mov r0, r6
 *   @0x2e8070 strtmi pc, [r3], -r8, lsl #2
 *   @0x2e8074 blx r7
 *   @0x2e8078 movs r3, #0x40
 *   @0x2e807c b 0x2e8080 <ft_mem_qrealloc+0x70>
 *   @0x2e8080 ldr r2, [sp, #0x4]
 *   @0x2e8084 ldr r3, [sp, #0x24]
 *   @0x2e8088 add sp, #0x8
 *   @0x2e808c push {r4, r5, r6, r7, r8, pc}
 *
 * ══ §209/230 FT_CMap_Done  0x2e82f8  size 126  32 条（0x2e82f8..0x2e8376）
 * @func 0x2e82f8 0x2e8378  size 128  32 条
 * 部分覆盖: 本节 32/59 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ft_mem_realloc / 0x574f44 / 0x2e7b5c
 * 字段偏移 top8: 0x24×1 / 0x4×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e82f8 push {r4, r5, r6, r7, lr}
 *   @0x2e82fc sub sp, #0x14
 *   @0x2e8300 beq 0x2e8372 <FT_CMap_Done+0x7a>
 *   @0x2e8304 movs r5, #0x0
 *   @0x2e8308 ldr r2, [r4, #0x24]
 *   @0x2e830c bge 0x2e8372 <FT_CMap_Done+0x7a>
 *   @0x2e8310 ldr.w r1, [r3, r5, lsl #2]
 *   @0x2e8314 cmp r1, r6
 *   @0x2e8318 add.w r1, r2, #0x40000000
 *   @0x2e831c subs r1, #0x1
 *   @0x2e8320 .word 0x21047021
 *   @0x2e8324 str r3, [sp]
 *   @0x2e8328 str r3, [sp, #0x4]
 *   @0x2e832c bl 0x2e808e <ft_mem_realloc>
 *   @0x2e8330 ldr r3, [sp, #0xc]
 *   @0x2e8334 cbnz r3, 0x2e8372 <FT_CMap_Done+0x7a>
 *   @0x2e8338 lsls r5, r5, #0x2
 *   @0x2e833c cmp r3, r2
 *   @0x2e8340 ble 0x574f44 <g_SWFlineaavertbuff+0x21e7c>
 *   @0x2e8344 cmp r3, r2
 *   @0x2e8348 add.w r3, r3, #0x1
 *   @0x2e834c itett ne
 *   @0x2e8350 streq r7, [r2, r5]
 *   @0x2e8354 strne r1, [r2, r5]
 *   @0x2e8358 b 0x2e833a <FT_CMap_Done+0x42>
 *   @0x2e835c mov r0, r6
 *   @0x2e8360 cmp r3, r6
 *   @0x2e8364 moveq r3, #0x0
 *   @0x2e8368 bl 0x2e7b5c <FT_Done_GlyphSlot+0x42>
 *   @0x2e836c b 0x2e8372 <FT_CMap_Done+0x7a>
 *   @0x2e8370 b 0x2e830a <FT_CMap_Done+0x12>
 *   @0x2e8374 pop {r4, r5, r6, r7, pc}
 *
 * ══ §210/230 CSkeletonInstance::GetBoundingBox(float&, float&, float&, float&)  0xbee60  size 124  31 条（0xbee60..0xbeedc）
 * @func 0xbee60 0xbeedc  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CSkeletonInstance::GetBoundingBox(float&, float&, float&, float&)+0x74 / spSkeleton_updateWorldTransform / spSkeletonBounds_update
 * 字段偏移 top8: 0x20×3 / 0x1c×2 / 0x18×2 / 0xc×1 / 0x10×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xbee60 push {r3, r4, r5, r6, r7, lr}
 *   @0xbee64 mov r4, r0
 *   @0xbee68 ldr r0, [r0, #0x20]
 *   @0xbee6c mov r6, r1
 *   @0xbee70 mov r5, r2
 *   @0xbee74 mov r7, r3
 *   @0xbee78 cmp r0, #0
 *   @0xbee7c popeq {r3, r4, r5, r6, r7, pc}
 *   @0xbee80 ldr r0, [r0]
 *   @0xbee84 cmp r0, #0
 *   @0xbee88 ble 0xbeed4 <_ZN17CSkeletonInstance14GetBoundingBoxERfS0_S0_S0_+0x74>
 *   @0xbee8c ldr r0, [r4, #0x1c]
 *   @0xbee90 bl 0x289ee4 <spSkeleton_updateWorldTransform>
 *   @0xbee94 ldr r0, [r4, #0x20]
 *   @0xbee98 ldr r1, [r4, #0x1c]
 *   @0xbee9c mov r2, #1
 *   @0xbeea0 bl 0x28a8b4 <spSkeletonBounds_update>
 *   @0xbeea4 ldr r12, [r4, #0x20]
 *   @0xbeea8 ldr r2, [sp, #0x18]
 *   @0xbeeac mov r0, #1
 *   @0xbeeb0 ldr r3, [r12, #0xc]
 *   @0xbeeb4 str r3, [r6]
 *   @0xbeeb8 ldr r3, [r12, #0x10]
 *   @0xbeebc str r3, [r5]
 *   @0xbeec0 ldr r3, [r12, #0x14]
 *   @0xbeec4 str r3, [r7]
 *   @0xbeec8 ldr r3, [r12, #0x18]
 *   @0xbeecc str r3, [r2]
 *   @0xbeed0 pop {r3, r4, r5, r6, r7, pc}
 *   @0xbeed4 mov r0, #0
 *   @0xbeed8 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §211/230 FINALIZE_Background()  0xc42f4  size 124  31 条（0xc42f4..0xc4370）
 * @func 0xc42f4 0xc4370  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / FINALIZE_Background()+0x58 / Background_FreeTextures()
 * 字段偏移 top8: 0x2×2 / 0x68×1 / 0x58×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc42f4 push {r3, r4, r5, r6, r7, lr}
 *   @0xc42f8 ldr r5, [pc, #0x68]
 *   @0xc42fc ldr r5, [pc, r5]
 *   @0xc4300 ldr r0, [r5]
 *   @0xc4304 cmp r0, #0
 *   @0xc4308 beq 0xc435c <_Z19FINALIZE_Backgroundv+0x68>
 *   @0xc430c ldr r6, [pc, #0x58]
 *   @0xc4310 ldr r6, [pc, r6]
 *   @0xc4314 ldr r3, [r6]
 *   @0xc4318 cmp r3, #0
 *   @0xc431c ble 0xc434c <_Z19FINALIZE_Backgroundv+0x58>
 *   @0xc4320 mov r4, #0
 *   @0xc4324 mov r7, r4
 *   @0xc4328 ldr r0, [r0, r4, lsl #2]
 *   @0xc432c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xc4330 ldr r2, [r5]
 *   @0xc4334 ldr r3, [r6]
 *   @0xc4338 str r7, [r2, r4, lsl #2]
 *   @0xc433c add r4, r4, #1
 *   @0xc4340 cmp r3, r4
 *   @0xc4344 ldr r0, [r5]
 *   @0xc4348 bgt 0xc4328 <_Z19FINALIZE_Backgroundv+0x34>
 *   @0xc434c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xc4350 mov r3, #0
 *   @0xc4354 str r3, [r5]
 *   @0xc4358 str r3, [r6]
 *   @0xc435c bl 0xc35d8 <_Z23Background_FreeTexturesv>
 *   @0xc4360 pop {r3, r4, r5, r6, r7, lr}
 *   @0xc4364 b 0xc34d0 <_Z15Background_Freev>
 *   @0xc4368 eorseq r9, r2, r0, asr r6
 *   @0xc436c eorseq r9, r2, r8, lsr r6
 *
 * ══ §212/230 IBuffer::LoadFromFileInMemory(char*, int, int, int, int)  0xcd8a0  size 124  31 条（0xcd8a0..0xcd91c）
 * @func 0xcd8a0 0xcd91c  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IBuffer::CopyMemoryToBuffer(IBuffer*, unsigned char*, int, int, int, int, bool, bool, bool)
 * 字段偏移 top8: 0x10×2 / 0x18×1 / 0x20×1 / 0xc×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcd8a0 cmp r1, #0
 *   @0xcd8a4 push {r4, lr}
 *   @0xcd8a8 sub sp, sp, #24
 *   @0xcd8ac beq 0xcd910 <_ZN7IBuffer20LoadFromFileInMemoryEPciiii+0x70>
 *   @0xcd8b0 ldr r12, [r0, #0x18]
 *   @0xcd8b4 cmp r12, #1
 *   @0xcd8b8 beq 0xcd908 <_ZN7IBuffer20LoadFromFileInMemoryEPciiii+0x68>
 *   @0xcd8bc ldr lr, [r0, #0x10]
 *   @0xcd8c0 rsbs lr, lr, #1
 *   @0xcd8c4 movlo lr, #0
 *   @0xcd8c8 cmp r12, #2
 *   @0xcd8cc beq 0xcd900 <_ZN7IBuffer20LoadFromFileInMemoryEPciiii+0x60>
 *   @0xcd8d0 mov r12, #0
 *   @0xcd8d4 ldr r4, [sp, #0x20]
 *   @0xcd8d8 str r12, [sp, #0xc]
 *   @0xcd8dc mov r12, #0
 *   @0xcd8e0 str r12, [sp, #0x10]
 *   @0xcd8e4 str r4, [sp]
 *   @0xcd8e8 ldr r4, [sp, #0x24]
 *   @0xcd8ec stmib sp, {r4, lr}
 *   @0xcd8f0 bl 0xccabc <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb>
 *   @0xcd8f4 mov r0, #1
 *   @0xcd8f8 add sp, sp, #24
 *   @0xcd8fc pop {r4, pc}
 *   @0xcd900 mov r12, #1
 *   @0xcd904 b 0xcd8d4 <_ZN7IBuffer20LoadFromFileInMemoryEPciiii+0x34>
 *   @0xcd908 mov lr, r12
 *   @0xcd90c b 0xcd8d0 <_ZN7IBuffer20LoadFromFileInMemoryEPciiii+0x30>
 *   @0xcd910 mov r0, r1
 *   @0xcd914 add sp, sp, #24
 *   @0xcd918 pop {r4, pc}
 *
 * ══ §213/230 Function_GetArguments(int)  0xce0dc  size 124  31 条（0xce0dc..0xce158）
 * @func 0xce0dc 0xce158  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Function_GetArguments(int)+0x64
 * 字段偏移 top8: 0x44×2 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xce0dc movw r3, #0xa11f
 *   @0xce0e0 movt r3, #0x7
 *   @0xce0e4 cmp r0, r3
 *   @0xce0e8 bgt 0xce134 <_Z21Function_GetArgumentsi+0x58>
 *   @0xce0ec movw r3, #0x869f
 *   @0xce0f0 movt r3, #0x1
 *   @0xce0f4 cmp r0, r3
 *   @0xce0f8 bgt 0xce148 <_Z21Function_GetArgumentsi+0x6c>
 *   @0xce0fc cmp r0, #0
 *   @0xce100 blt 0xce140 <_Z21Function_GetArgumentsi+0x64>
 *   @0xce104 ldr r3, [pc, #0x44]
 *   @0xce108 ldr r3, [pc, r3]
 *   @0xce10c ldr r3, [r3]
 *   @0xce110 cmp r0, r3
 *   @0xce114 bge 0xce140 <_Z21Function_GetArgumentsi+0x64>
 *   @0xce118 ldr r3, [pc, #0x34]
 *   @0xce11c add r0, r0, r0, lsl #2
 *   @0xce120 ldr r3, [pc, r3]
 *   @0xce124 ldr r3, [r3]
 *   @0xce128 add r0, r3, r0, lsl #4
 *   @0xce12c ldr r0, [r0, #0x44]
 *   @0xce130 bx lr
 *   @0xce134 sub r0, r0, #499712
 *   @0xce138 sub r0, r0, #288
 *   @0xce13c b 0xf6240 <_Z31Extension_Function_GetArgumentsi>
 *   @0xce140 mvn r0, #99
 *   @0xce144 bx lr
 *   @0xce148 mvn r0, #0
 *   @0xce14c bx lr
 *   @0xce150 eorseq pc, r1, r12, lsl #20
 *   @0xce154 ldrshteq pc, [r1], -r8
 *
 * ══ §214/230 CBucket<32768u, 1048576u, false>::Check()  0xd33a0  size 124  31 条（0xd33a0..0xd341c）
 * @func 0xd33a0 0xd341c  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CBucket<32768u, 1048576u, false>::Check()+0x48
 * 字段偏移 top8: 0x8×1 / 0x60×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd33a0 ldr r12, [r0, #0x8]
 *   @0xd33a4 push {r4, r5, r6}
 *   @0xd33a8 cmp r12, #0
 *   @0xd33ac beq 0xd3410 <_ZN7CBucketILj32768ELj1048576ELb0EE5CheckEv+0x70>
 *   @0xd33b0 ldr r4, [pc, #0x60]
 *   @0xd33b4 mov r6, #0
 *   @0xd33b8 mov r5, #42
 *   @0xd33bc ldr r4, [pc, r4]
 *   @0xd33c0 ldr r3, [r0, #0x4]
 *   @0xd33c4 cmp r3, #0
 *   @0xd33c8 beq 0xd33f4 <_ZN7CBucketILj32768ELj1048576ELb0EE5CheckEv+0x54>
 *   @0xd33cc add r1, r3, #8
 *   @0xd33d0 add r2, r3, #1048576
 *   @0xd33d4 cmp r12, r1
 *   @0xd33d8 add r2, r2, #8
 *   @0xd33dc blo 0xd33e8 <_ZN7CBucketILj32768ELj1048576ELb0EE5CheckEv+0x48>
 *   @0xd33e0 cmp r2, r12
 *   @0xd33e4 bhi 0xd33f8 <_ZN7CBucketILj32768ELj1048576ELb0EE5CheckEv+0x58>
 *   @0xd33e8 ldr r3, [r3]
 *   @0xd33ec cmp r3, #0
 *   @0xd33f0 bne 0xd33cc <_ZN7CBucketILj32768ELj1048576ELb0EE5CheckEv+0x2c>
 *   @0xd33f4 str r5, [r6]
 *   @0xd33f8 ldr r12, [r12]
 *   @0xd33fc ldr r3, [r4]
 *   @0xd3400 cmp r12, #0
 *   @0xd3404 add r3, r3, #1
 *   @0xd3408 str r3, [r4]
 *   @0xd340c bne 0xd33c0 <_ZN7CBucketILj32768ELj1048576ELb0EE5CheckEv+0x20>
 *   @0xd3410 pop {r4, r5, r6}
 *   @0xd3414 bx lr
 *   @0xd3418 eorseq r10, r1, r8, lsl #16
 *
 * ══ §215/230 ResetGC()  0xd66e0  size 124  31 条（0xd66e0..0xd675c）
 * @func 0xd66e0 0xd675c  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0xd66e4→0x47f295, 0xd6700→0x47a1f8, 0xd6708→0x47a1f4, 0xd670c→0x536da8
 * 调用序列: CGCGeneration::Reset()×3
 * 字段偏移 top8: 0x60×2 / 0x44×2 / 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd66e0 ldr r3, [pc, #0x60]
 *   @0xd66e4 ldr r2, [pc, #0x60]
 *   @0xd66e8 add r3, pc, r3
 *   @0xd66ec push {r4, lr}
 *   @0xd66f0 ldr r2, [r3, r2]
 *   @0xd66f4 ldrb r2, [r2]
 *   @0xd66f8 cmp r2, #0
 *   @0xd66fc popeq {r4, pc}
 *   @0xd6700 ldr r12, [pc, #0x48]
 *   @0xd6704 mov r2, #0
 *   @0xd6708 ldr r0, [pc, #0x44]
 *   @0xd670c ldr r1, [pc, #0x44]
 *   @0xd6710 ldr r12, [r3, r12]
 *   @0xd6714 str r2, [r12]
 *   @0xd6718 ldr r0, [r3, r0]
 *   @0xd671c str r2, [r0]
 *   @0xd6720 ldr r4, [r3, r1]
 *   @0xd6724 mov r0, r4
 *   @0xd6728 bl 0x19140c <_ZN13CGCGeneration5ResetEv>
 *   @0xd672c add r0, r4, #88
 *   @0xd6730 bl 0x19140c <_ZN13CGCGeneration5ResetEv>
 *   @0xd6734 add r0, r4, #176
 *   @0xd6738 bl 0x19140c <_ZN13CGCGeneration5ResetEv>
 *   @0xd673c add r0, r4, #264
 *   @0xd6740 pop {r4, lr}
 *   @0xd6744 b 0x19140c <_ZN13CGCGeneration5ResetEv>
 *   @0xd6748 eorseq r11, r1, r8, ror #10
 *   @0xd674c .word 0xffffbf68
 *   @0xd6750 .word 0xffffc044
 *   @0xd6754 .word 0xffffc048
 *   @0xd6758 .word 0xffffc010
 *
 * ══ §216/230 AddChangingInstances(CObjectGM*)  0xd7d00  size 124  31 条（0xd7d00..0xd7d7c）
 * @func 0xd7d00 0xd7d8c  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: AddChangingInstances(CObjectGM*)+0x74 / HandleInstance(CInstance*)
 * 字段偏移 top8: 0x8×3 / 0x6c×1 / 0x18×1 / 0x2×1 / 0x7c×1 / 0x68×1 / 0x69×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd7d00 push {r4, r5, r6, lr}
 *   @0xd7d04 ldr r5, [pc, #0x6c]
 *   @0xd7d08 ldr r6, [r0, #0x18]
 *   @0xd7d0c ldr r5, [pc, r5]
 *   @0xd7d10 ldr r3, [r5, #0x8]
 *   @0xd7d14 cmp r3, #0
 *   @0xd7d18 pople {r4, r5, r6, pc}
 *   @0xd7d1c mov r4, #0
 *   @0xd7d20 b 0xd7d34 <_Z20AddChangingInstancesP9CObjectGM+0x34>
 *   @0xd7d24 ldr r3, [r5, #0x8]
 *   @0xd7d28 add r4, r4, #1
 *   @0xd7d2c cmp r3, r4
 *   @0xd7d30 ble 0xd7d74 <_Z20AddChangingInstancesP9CObjectGM+0x74>
 *   @0xd7d34 ldr r3, [r5]
 *   @0xd7d38 ldr r0, [r3, r4, lsl #2]
 *   @0xd7d3c ldr r3, [r0, #0x7c]
 *   @0xd7d40 cmp r6, r3
 *   @0xd7d44 bne 0xd7d24 <_Z20AddChangingInstancesP9CObjectGM+0x24>
 *   @0xd7d48 ldrb r3, [r0, #0x68]
 *   @0xd7d4c cmp r3, #0
 *   @0xd7d50 bne 0xd7d24 <_Z20AddChangingInstancesP9CObjectGM+0x24>
 *   @0xd7d54 ldrb r3, [r0, #0x69]
 *   @0xd7d58 cmp r3, #0
 *   @0xd7d5c bne 0xd7d24 <_Z20AddChangingInstancesP9CObjectGM+0x24>
 *   @0xd7d60 bl 0xd3fd0 <_Z14HandleInstanceP9CInstance>
 *   @0xd7d64 ldr r3, [r5, #0x8]
 *   @0xd7d68 add r4, r4, #1
 *   @0xd7d6c cmp r3, r4
 *   @0xd7d70 bgt 0xd7d34 <_Z20AddChangingInstancesP9CObjectGM+0x34>
 *   @0xd7d74 pop {r4, r5, r6, pc}
 *   @0xd7d78 eorseq r5, r1, r4, lsr pc
 *
 * ══ §217/230 AddDeactivatingInstances(CObjectGM*)  0xd7d7c  size 124  31 条（0xd7d7c..0xd7df8）
 * @func 0xd7d7c 0xd7df8  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: AddDeactivatingInstances(CObjectGM*)+0x74 / HandleInstance(CInstance*)
 * 字段偏移 top8: 0x8×3 / 0x6c×1 / 0x18×1 / 0x2×1 / 0x7c×1 / 0x68×1 / 0x69×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd7d7c push {r4, r5, r6, lr}
 *   @0xd7d80 ldr r5, [pc, #0x6c]
 *   @0xd7d84 ldr r6, [r0, #0x18]
 *   @0xd7d88 ldr r5, [pc, r5]
 *   @0xd7d8c ldr r3, [r5, #0x8]
 *   @0xd7d90 cmp r3, #0
 *   @0xd7d94 pople {r4, r5, r6, pc}
 *   @0xd7d98 mov r4, #0
 *   @0xd7d9c b 0xd7db0 <_Z24AddDeactivatingInstancesP9CObjectGM+0x34>
 *   @0xd7da0 ldr r3, [r5, #0x8]
 *   @0xd7da4 add r4, r4, #1
 *   @0xd7da8 cmp r3, r4
 *   @0xd7dac ble 0xd7df0 <_Z24AddDeactivatingInstancesP9CObjectGM+0x74>
 *   @0xd7db0 ldr r3, [r5]
 *   @0xd7db4 ldr r0, [r3, r4, lsl #2]
 *   @0xd7db8 ldr r3, [r0, #0x7c]
 *   @0xd7dbc cmp r6, r3
 *   @0xd7dc0 bne 0xd7da0 <_Z24AddDeactivatingInstancesP9CObjectGM+0x24>
 *   @0xd7dc4 ldrb r3, [r0, #0x68]
 *   @0xd7dc8 cmp r3, #0
 *   @0xd7dcc bne 0xd7da0 <_Z24AddDeactivatingInstancesP9CObjectGM+0x24>
 *   @0xd7dd0 ldrb r3, [r0, #0x69]
 *   @0xd7dd4 cmp r3, #0
 *   @0xd7dd8 bne 0xd7da0 <_Z24AddDeactivatingInstancesP9CObjectGM+0x24>
 *   @0xd7ddc bl 0xd3fd0 <_Z14HandleInstanceP9CInstance>
 *   @0xd7de0 ldr r3, [r5, #0x8]
 *   @0xd7de4 add r4, r4, #1
 *   @0xd7de8 cmp r3, r4
 *   @0xd7dec bgt 0xd7db0 <_Z24AddDeactivatingInstancesP9CObjectGM+0x34>
 *   @0xd7df0 pop {r4, r5, r6, pc}
 *   @0xd7df4 eorseq r5, r1, r0, asr #29
 *
 * ══ §218/230 VM::SetBreakpoint(unsigned int*, unsigned int, unsigned char*)  0xd8270  size 124  31 条（0xd8270..0xd82ec）
 * @func 0xd8270 0xd82ec  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×4 / 0x68×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd8270 push {r4, r5}
 *   @0xd8274 mov r3, #0
 *   @0xd8278 ldr r4, [pc, #0x68]
 *   @0xd827c ldr r4, [pc, r4]
 *   @0xd8280 b 0xd828c <_ZN2VM13SetBreakpointEPjjPh+0x1c>
 *   @0xd8284 cmp r3, #4080
 *   @0xd8288 beq 0xd82a8 <_ZN2VM13SetBreakpointEPjjPh+0x38>
 *   @0xd828c add r12, r4, r3
 *   @0xd8290 add r3, r3, #16
 *   @0xd8294 ldr r12, [r12, #0x4]
 *   @0xd8298 cmp r12, r0
 *   @0xd829c bne 0xd8284 <_ZN2VM13SetBreakpointEPjjPh+0x14>
 *   @0xd82a0 pop {r4, r5}
 *   @0xd82a4 bx lr
 *   @0xd82a8 mov r3, #0
 *   @0xd82ac b 0xd82bc <_ZN2VM13SetBreakpointEPjjPh+0x4c>
 *   @0xd82b0 add r3, r3, #1
 *   @0xd82b4 cmp r3, #255
 *   @0xd82b8 beq 0xd82a0 <_ZN2VM13SetBreakpointEPjjPh+0x30>
 *   @0xd82bc add r12, r4, r3, lsl #4
 *   @0xd82c0 ldr r5, [r12, #0x4]
 *   @0xd82c4 cmn r5, #1
 *   @0xd82c8 bne 0xd82b0 <_ZN2VM13SetBreakpointEPjjPh+0x40>
 *   @0xd82cc str r1, [r12, #0x8]
 *   @0xd82d0 ldr r1, [r0]
 *   @0xd82d4 str r0, [r12, #0x4]
 *   @0xd82d8 str r2, [r12, #0xc]
 *   @0xd82dc str r1, [r4, r3, lsl #4]
 *   @0xd82e0 pop {r4, r5}
 *   @0xd82e4 bx lr
 *   @0xd82e8 eorseq r5, r1, r8, ror #20
 *
 * ══ §219/230 DIALOG_REQ_CONTEXT::~DIALOG_REQ_CONTEXT()  0xf1d1c  size 124  31 条（0xf1d1c..0xf1d98）
 * @func 0xf1d1c 0xf1d98  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb655c×3 / HTTP_REQ_CONTEXT::~HTTP_REQ_CONTEXT() / operator delete(void*)
 * 字段偏移 top8: 0x48×2 / 0x4c×2 / 0x50×2 / 0x64×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf1d1c push {r4, lr}
 *   @0xf1d20 mov r4, r0
 *   @0xf1d24 ldr r0, [r0, #0x48]
 *   @0xf1d28 ldr r3, [pc, #0x64]
 *   @0xf1d2c cmp r0, #0
 *   @0xf1d30 ldr r3, [pc, r3]
 *   @0xf1d34 add r3, r3, #8
 *   @0xf1d38 str r3, [r4]
 *   @0xf1d3c beq 0xf1d4c <_ZN18DIALOG_REQ_CONTEXTD0Ev+0x30>
 *   @0xf1d40 bl 0xb655c <free@plt>
 *   @0xf1d44 mov r3, #0
 *   @0xf1d48 str r3, [r4, #0x48]
 *   @0xf1d4c ldr r0, [r4, #0x4c]
 *   @0xf1d50 cmp r0, #0
 *   @0xf1d54 beq 0xf1d64 <_ZN18DIALOG_REQ_CONTEXTD0Ev+0x48>
 *   @0xf1d58 bl 0xb655c <free@plt>
 *   @0xf1d5c mov r3, #0
 *   @0xf1d60 str r3, [r4, #0x4c]
 *   @0xf1d64 ldr r0, [r4, #0x50]
 *   @0xf1d68 cmp r0, #0
 *   @0xf1d6c beq 0xf1d7c <_ZN18DIALOG_REQ_CONTEXTD0Ev+0x60>
 *   @0xf1d70 bl 0xb655c <free@plt>
 *   @0xf1d74 mov r3, #0
 *   @0xf1d78 str r3, [r4, #0x50]
 *   @0xf1d7c mov r0, r4
 *   @0xf1d80 bl 0x18d724 <_ZN16HTTP_REQ_CONTEXTD2Ev>
 *   @0xf1d84 mov r0, r4
 *   @0xf1d88 bl 0x27d1d0 <_ZdlPv>
 *   @0xf1d8c mov r0, r4
 *   @0xf1d90 pop {r4, pc}
 *   @0xf1d94 strhteq r12, [pc], -r0
 *
 * ══ §220/230 inputDialogAsync  0xf29f4  size 124  31 条（0xf29f4..0xf2a70）
 * @func 0xf29f4 0xf2a70  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv×3 / _JNIEnv::CallStaticVoidMethod(_jclass*, _jmethodID*, ...)
 * 字段偏移 top8: 0x29c×2 / 0x24×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf29f4 push {r4, r5, r6, lr}
 *   @0xf29f8 sub sp, sp, #8
 *   @0xf29fc mov r4, r2
 *   @0xf2a00 mov r5, r3
 *   @0xf2a04 mov r6, r1
 *   @0xf2a08 bl 0x290274 <getJNIEnv>
 *   @0xf2a0c mov r1, r6
 *   @0xf2a10 ldr r3, [r0]
 *   @0xf2a14 ldr r3, [r3, #0x29c]
 *   @0xf2a18 blx r3
 *   @0xf2a1c mov r6, r0
 *   @0xf2a20 bl 0x290274 <getJNIEnv>
 *   @0xf2a24 mov r1, r4
 *   @0xf2a28 ldr r3, [r0]
 *   @0xf2a2c ldr r3, [r3, #0x29c]
 *   @0xf2a30 blx r3
 *   @0xf2a34 mov r4, r0
 *   @0xf2a38 bl 0x290274 <getJNIEnv>
 *   @0xf2a3c ldr r1, [pc, #0x24]
 *   @0xf2a40 mov r3, r6
 *   @0xf2a44 ldr r2, [pc, #0x20]
 *   @0xf2a48 ldr r1, [pc, r1]
 *   @0xf2a4c ldr r2, [pc, r2]
 *   @0xf2a50 ldr r1, [r1]
 *   @0xf2a54 ldr r2, [r2]
 *   @0xf2a58 stm sp, {r4, r5}
 *   @0xf2a5c bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0xf2a60 add sp, sp, #8
 *   @0xf2a64 pop {r4, r5, r6, pc}
 *   @0xf2a68 eoreq r10, pc, r12, asr pc
 *   @0xf2a6c .word 0x002fb3b8
 *
 * ══ §221/230 loginDialogAsync  0xf2ad0  size 124  31 条（0xf2ad0..0xf2b4c）
 * @func 0xf2ad0 0xf2b4c  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv×3 / _JNIEnv::CallStaticVoidMethod(_jclass*, _jmethodID*, ...)
 * 字段偏移 top8: 0x29c×2 / 0x24×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2ad0 push {r4, r5, r6, lr}
 *   @0xf2ad4 sub sp, sp, #8
 *   @0xf2ad8 mov r5, r2
 *   @0xf2adc mov r4, r1
 *   @0xf2ae0 mov r6, r0
 *   @0xf2ae4 bl 0x290274 <getJNIEnv>
 *   @0xf2ae8 mov r1, r6
 *   @0xf2aec ldr r3, [r0]
 *   @0xf2af0 ldr r3, [r3, #0x29c]
 *   @0xf2af4 blx r3
 *   @0xf2af8 mov r6, r0
 *   @0xf2afc bl 0x290274 <getJNIEnv>
 *   @0xf2b00 mov r1, r4
 *   @0xf2b04 ldr r3, [r0]
 *   @0xf2b08 ldr r3, [r3, #0x29c]
 *   @0xf2b0c blx r3
 *   @0xf2b10 mov r4, r0
 *   @0xf2b14 bl 0x290274 <getJNIEnv>
 *   @0xf2b18 ldr r1, [pc, #0x24]
 *   @0xf2b1c mov r3, r6
 *   @0xf2b20 ldr r12, [pc, #0x20]
 *   @0xf2b24 ldr r1, [pc, r1]
 *   @0xf2b28 ldr r12, [pc, r12]
 *   @0xf2b2c ldr r1, [r1]
 *   @0xf2b30 ldr r2, [r12]
 *   @0xf2b34 stm sp, {r4, r5}
 *   @0xf2b38 bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0xf2b3c add sp, sp, #8
 *   @0xf2b40 pop {r4, r5, r6, pc}
 *   @0xf2b44 eoreq r10, pc, r0, lsl #29
 *   @0xf2b48 eoreq r11, pc, r4, ror #5
 *
 * ══ §222/230 Extension_Function_GetArguments(int)  0xf6240  size 124  31 条（0xf6240..0xf62bc）
 * @func 0xf6240 0xf62bc  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Extension_Function_GetArguments(int)+0x6c / Extension_Function_GetArguments(int)+0x64 / CExtensionPackage::FunctionFindId(int) / CExtensionFunction::GetArgCount() / Extension_Function_GetArguments(int)+0x30
 * 字段偏移 top8: 0x64×1 / 0x54×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf6240 push {r4, r5, r6, r7, r8, lr}
 *   @0xf6244 mov r6, r0
 *   @0xf6248 ldr r5, [pc, #0x64]
 *   @0xf624c ldr r5, [pc, r5]
 *   @0xf6250 ldr r3, [r5]
 *   @0xf6254 cmp r3, #0
 *   @0xf6258 ble 0xf62ac <_Z31Extension_Function_GetArgumentsi+0x6c>
 *   @0xf625c ldr r7, [pc, #0x54]
 *   @0xf6260 mvn r8, #99
 *   @0xf6264 mov r4, #0
 *   @0xf6268 add r7, pc, r7
 *   @0xf626c b 0xf627c <_Z31Extension_Function_GetArgumentsi+0x3c>
 *   @0xf6270 ldr r3, [r5]
 *   @0xf6274 cmp r3, r4
 *   @0xf6278 ble 0xf62a4 <_Z31Extension_Function_GetArgumentsi+0x64>
 *   @0xf627c ldr r3, [r7, #0x4]
 *   @0xf6280 mov r1, r6
 *   @0xf6284 ldr r0, [r3, r4, lsl #2]
 *   @0xf6288 add r4, r4, #1
 *   @0xf628c bl 0xf54e0 <_ZN17CExtensionPackage14FunctionFindIdEi>
 *   @0xf6290 cmp r0, #0
 *   @0xf6294 beq 0xf6270 <_Z31Extension_Function_GetArgumentsi+0x30>
 *   @0xf6298 bl 0xf4c38 <_ZN18CExtensionFunction11GetArgCountEv>
 *   @0xf629c subs r8, r0, #0
 *   @0xf62a0 blt 0xf6270 <_Z31Extension_Function_GetArgumentsi+0x30>
 *   @0xf62a4 mov r0, r8
 *   @0xf62a8 pop {r4, r5, r6, r7, r8, pc}
 *   @0xf62ac mvn r8, #99
 *   @0xf62b0 b 0xf62a4 <_Z31Extension_Function_GetArgumentsi+0x64>
 *   @0xf62b4 eoreq r7, pc, r8, ror #23
 *   @0xf62b8 eorseq sp, r8, r0, ror #7
 *
 * ══ §223/230 F_StringDelete(RValue&, CInstance*, CInstance*, int, RValue*)  0x111448  size 124  31 条（0x111448..0x1114c4）
 * @func 0x111448 0x1114c4  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / YYGetString(RValue const*, int) / YYStrDup(char const*) / Delete(char const*&, int, int) / YYCreateString(RValue*, char const*) / YYFree(void const*)
 * 字段偏移 top8: 0x4×2 / 0x20×1 / 0x-4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x111448 push {r4, r5, r6, r7, lr}
 *   @0x11144c sub sp, sp, #12
 *   @0x111450 mov r5, r0
 *   @0x111454 mov r1, #0
 *   @0x111458 ldr r4, [sp, #0x20]
 *   @0x11145c mov r0, r4
 *   @0x111460 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x111464 mov r1, #1
 *   @0x111468 mov r7, r0
 *   @0x11146c mov r0, r4
 *   @0x111470 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x111474 mov r1, #2
 *   @0x111478 mov r6, r0
 *   @0x11147c mov r0, r4
 *   @0x111480 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x111484 mov r4, r0
 *   @0x111488 mov r0, r7
 *   @0x11148c bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x111490 add r3, sp, #8
 *   @0x111494 mov r2, r4
 *   @0x111498 mov r1, r6
 *   @0x11149c str r0, [r3, #-0x4]!
 *   @0x1114a0 mov r0, r3
 *   @0x1114a4 bl 0x111378 <_Z6DeleteRPKcii>
 *   @0x1114a8 mov r0, r5
 *   @0x1114ac ldr r1, [sp, #0x4]
 *   @0x1114b0 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x1114b4 ldr r0, [sp, #0x4]
 *   @0x1114b8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1114bc add sp, sp, #12
 *   @0x1114c0 pop {r4, r5, r6, r7, pc}
 *
 * ══ §224/230 F_StringReplace(RValue&, CInstance*, CInstance*, int, RValue*)  0x1118a8  size 124  31 条（0x1118a8..0x111924）
 * @func 0x1118a8 0x111934  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)×3 / StringReplace(char const*&, char const*, char const*, char const*, bool) / YYCreateString(RValue*, char const*) / YYFree(void const*)
 * 字段偏移 top8: 0xc×2 / 0x30×1 / 0x-4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1118a8 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x1118ac sub sp, sp, #20
 *   @0x1118b0 mov r6, #0
 *   @0x1118b4 add r5, sp, #16
 *   @0x1118b8 ldr r4, [sp, #0x30]
 *   @0x1118bc mov r7, r0
 *   @0x1118c0 mov r1, r6
 *   @0x1118c4 str r6, [r5, #-0x4]!
 *   @0x1118c8 mov r0, r4
 *   @0x1118cc bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1118d0 mov r1, #1
 *   @0x1118d4 mov r9, r0
 *   @0x1118d8 mov r0, r4
 *   @0x1118dc bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1118e0 mov r1, #2
 *   @0x1118e4 mov r8, r0
 *   @0x1118e8 mov r0, r4
 *   @0x1118ec bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1118f0 mov r2, r8
 *   @0x1118f4 mov r1, r9
 *   @0x1118f8 str r6, [sp]
 *   @0x1118fc mov r3, r0
 *   @0x111900 mov r0, r5
 *   @0x111904 bl 0x1116a4 <_Z13StringReplaceRPKcS0_S0_S0_b>
 *   @0x111908 mov r0, r7
 *   @0x11190c ldr r1, [sp, #0xc]
 *   @0x111910 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x111914 ldr r0, [sp, #0xc]
 *   @0x111918 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x11191c add sp, sp, #20
 *   @0x111920 pop {r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §225/230 YYGML_draw_text_ext_color(float, float, char const*, int, int, int, int, int, int, float)  0x1225b4  size 124  31 条（0x1225b4..0x122630）
 * @func 0x1225b4 0x122630  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYStrDup(char const*) / GR_Text_Draw_Color(float, float, char const*, int, int, unsigned int, unsigned int, unsigned int, unsigned int, float)
 * 字段偏移 top8: 0x1c×2 / 0x50×1 / 0x54×1 / 0x58×1 / 0x5c×1 / 0x60×1 / 0x4×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1225b4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1225b8 vpush {d8}
 *   @0x1225bc sub sp, sp, #36
 *   @0x1225c0 vldr s16, [sp, #100]
 *   @0x1225c4 mov r7, r0
 *   @0x1225c8 mov r0, r2
 *   @0x1225cc ldr r6, [sp, #0x50]
 *   @0x1225d0 mov r8, r1
 *   @0x1225d4 ldr r5, [sp, #0x54]
 *   @0x1225d8 ldr r11, [sp, #0x58]
 *   @0x1225dc ldr r10, [sp, #0x5c]
 *   @0x1225e0 ldr r9, [sp, #0x60]
 *   @0x1225e4 str r3, [sp, #0x1c]
 *   @0x1225e8 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x1225ec str r6, [sp]
 *   @0x1225f0 vstr s16, [sp, #20]
 *   @0x1225f4 str r5, [sp, #0x4]
 *   @0x1225f8 mov r1, r8
 *   @0x1225fc ldr r3, [sp, #0x1c]
 *   @0x122600 str r11, [sp, #0x8]
 *   @0x122604 str r10, [sp, #0xc]
 *   @0x122608 str r9, [sp, #0x10]
 *   @0x12260c mov r4, r0
 *   @0x122610 mov r0, r7
 *   @0x122614 mov r2, r4
 *   @0x122618 bl 0x173338 <_Z18GR_Text_Draw_ColorffPKciijjjjf>
 *   @0x12261c mov r0, r4
 *   @0x122620 add sp, sp, #36
 *   @0x122624 vpop {d8}
 *   @0x122628 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x12262c b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *
 * ══ §226/230 F_EffectCreateBelow(RValue&, CInstance*, CInstance*, int, RValue*)  0x129e78  size 124  31 条（0x129e78..0x129ef4）
 * @func 0x129e78 0x129f04  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / YYGetFloat(RValue const*, int)×2 / Effect_Create(bool, int, float, float, int, unsigned int)
 * 字段偏移 top8: 0x20×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x129e78 push {r4, r5, r6, r7, r8, lr}
 *   @0x129e7c sub sp, sp, #8
 *   @0x129e80 mov r1, #0
 *   @0x129e84 ldr r4, [sp, #0x20]
 *   @0x129e88 mov r0, r4
 *   @0x129e8c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129e90 mov r1, #1
 *   @0x129e94 mov r7, r0
 *   @0x129e98 mov r0, r4
 *   @0x129e9c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x129ea0 mov r1, #2
 *   @0x129ea4 mov r6, r0
 *   @0x129ea8 mov r0, r4
 *   @0x129eac bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x129eb0 mov r1, #3
 *   @0x129eb4 mov r5, r0
 *   @0x129eb8 mov r0, r4
 *   @0x129ebc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129ec0 mov r1, #4
 *   @0x129ec4 mov r8, r0
 *   @0x129ec8 mov r0, r4
 *   @0x129ecc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129ed0 str r8, [sp]
 *   @0x129ed4 mov r1, r7
 *   @0x129ed8 mov r2, r6
 *   @0x129edc mov r3, r5
 *   @0x129ee0 str r0, [sp, #0x4]
 *   @0x129ee4 mov r0, #1
 *   @0x129ee8 bl 0x1a25d0 <_Z13Effect_Createbiffij>
 *   @0x129eec add sp, sp, #8
 *   @0x129ef0 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §227/230 F_EffectCreateAbove(RValue&, CInstance*, CInstance*, int, RValue*)  0x129ef4  size 124  31 条（0x129ef4..0x129f70）
 * @func 0x129ef4 0x129f70  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / YYGetFloat(RValue const*, int)×2 / Effect_Create(bool, int, float, float, int, unsigned int)
 * 字段偏移 top8: 0x20×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x129ef4 push {r4, r5, r6, r7, r8, lr}
 *   @0x129ef8 sub sp, sp, #8
 *   @0x129efc mov r1, #0
 *   @0x129f00 ldr r4, [sp, #0x20]
 *   @0x129f04 mov r0, r4
 *   @0x129f08 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129f0c mov r1, #1
 *   @0x129f10 mov r7, r0
 *   @0x129f14 mov r0, r4
 *   @0x129f18 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x129f1c mov r1, #2
 *   @0x129f20 mov r6, r0
 *   @0x129f24 mov r0, r4
 *   @0x129f28 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x129f2c mov r1, #3
 *   @0x129f30 mov r5, r0
 *   @0x129f34 mov r0, r4
 *   @0x129f38 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129f3c mov r1, #4
 *   @0x129f40 mov r8, r0
 *   @0x129f44 mov r0, r4
 *   @0x129f48 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129f4c str r8, [sp]
 *   @0x129f50 mov r1, r7
 *   @0x129f54 mov r2, r6
 *   @0x129f58 mov r3, r5
 *   @0x129f5c str r0, [sp, #0x4]
 *   @0x129f60 mov r0, #0
 *   @0x129f64 bl 0x1a25d0 <_Z13Effect_Createbiffij>
 *   @0x129f68 add sp, sp, #8
 *   @0x129f6c pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §228/230 F_ObjectSetSprite(RValue&, CInstance*, CInstance*, int, RValue*)  0x12b088  size 124  31 条（0x12b088..0x12b104）
 * @func 0x12b088 0x12b114  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2
 * 字段偏移 top8: 0x4×3 / 0x10×1 / 0x5c×1 / 0x3×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12b088 push {r3, r4, r5, lr}
 *   @0x12b08c mov r1, #0
 *   @0x12b090 ldr r4, [sp, #0x10]
 *   @0x12b094 mov r0, r4
 *   @0x12b098 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12b09c ldr r3, [pc, #0x5c]
 *   @0x12b0a0 ldr r3, [pc, r3]
 *   @0x12b0a4 ldr r3, [r3]
 *   @0x12b0a8 ldr r2, [r3, #0x4]
 *   @0x12b0ac ldr r3, [r3]
 *   @0x12b0b0 and r2, r0, r2
 *   @0x12b0b4 ldr r3, [r3, r2, lsl #3]
 *   @0x12b0b8 cmp r3, #0
 *   @0x12b0bc bne 0x12b0d0 <_Z17F_ObjectSetSpriteR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x12b0c0 pop {r3, r4, r5, pc}
 *   @0x12b0c4 ldr r3, [r3, #0x4]
 *   @0x12b0c8 cmp r3, #0
 *   @0x12b0cc beq 0x12b0fc <_Z17F_ObjectSetSpriteR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x12b0d0 ldr r2, [r3, #0x8]
 *   @0x12b0d4 cmp r0, r2
 *   @0x12b0d8 bne 0x12b0c4 <_Z17F_ObjectSetSpriteR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x12b0dc ldr r5, [r3, #0xc]
 *   @0x12b0e0 cmp r5, #0
 *   @0x12b0e4 popeq {r3, r4, r5, pc}
 *   @0x12b0e8 mov r0, r4
 *   @0x12b0ec mov r1, #1
 *   @0x12b0f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12b0f4 str r0, [r5, #0x4]
 *   @0x12b0f8 pop {r3, r4, r5, pc}
 *   @0x12b0fc pop {r3, r4, r5, pc}
 *   @0x12b100 mlaeq r12, r12, r11, r2
 *
 * ══ §229/230 F_ObjectSetDepth(RValue&, CInstance*, CInstance*, int, RValue*)  0x12b104  size 124  31 条（0x12b104..0x12b180）
 * @func 0x12b104 0x12b180  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2
 * 字段偏移 top8: 0x4×2 / 0x8×2 / 0x10×1 / 0x5c×1 / 0x3×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12b104 push {r3, r4, r5, lr}
 *   @0x12b108 mov r1, #0
 *   @0x12b10c ldr r4, [sp, #0x10]
 *   @0x12b110 mov r0, r4
 *   @0x12b114 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12b118 ldr r3, [pc, #0x5c]
 *   @0x12b11c ldr r3, [pc, r3]
 *   @0x12b120 ldr r3, [r3]
 *   @0x12b124 ldr r2, [r3, #0x4]
 *   @0x12b128 ldr r3, [r3]
 *   @0x12b12c and r2, r0, r2
 *   @0x12b130 ldr r3, [r3, r2, lsl #3]
 *   @0x12b134 cmp r3, #0
 *   @0x12b138 bne 0x12b14c <_Z16F_ObjectSetDepthR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x12b13c pop {r3, r4, r5, pc}
 *   @0x12b140 ldr r3, [r3, #0x4]
 *   @0x12b144 cmp r3, #0
 *   @0x12b148 beq 0x12b178 <_Z16F_ObjectSetDepthR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x12b14c ldr r2, [r3, #0x8]
 *   @0x12b150 cmp r0, r2
 *   @0x12b154 bne 0x12b140 <_Z16F_ObjectSetDepthR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x12b158 ldr r5, [r3, #0xc]
 *   @0x12b15c cmp r5, #0
 *   @0x12b160 popeq {r3, r4, r5, pc}
 *   @0x12b164 mov r0, r4
 *   @0x12b168 mov r1, #1
 *   @0x12b16c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12b170 str r0, [r5, #0x8]
 *   @0x12b174 pop {r3, r4, r5, pc}
 *   @0x12b178 pop {r3, r4, r5, pc}
 *   @0x12b17c eoreq r2, r12, r0, lsr #22
 *
 * ══ §230/230 CBackground::SetAlphaFromBackground(CBackground*)  0xc1f50  size 100  25 条（0xc1f50..0xc1fb4）
 * @func 0xc1f50 0xc1fb4  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CBitmap32::SetAlphaFromBitmap(CBitmap32*) / CBackground::InitTexture()
 * 字段偏移 top8: 0x10×2 / 0x1c×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc1f50 push {r4, lr}
 *   @0xc1f54 mov r4, r0
 *   @0xc1f58 ldr r0, [r0, #0x10]
 *   @0xc1f5c cmp r0, #0
 *   @0xc1f60 beq 0xc1f88 <_ZN11CBackground22SetAlphaFromBackgroundEPS_+0x38>
 *   @0xc1f64 ldr r1, [r1, #0x10]
 *   @0xc1f68 cmp r1, #0
 *   @0xc1f6c beq 0xc1f88 <_ZN11CBackground22SetAlphaFromBackgroundEPS_+0x38>
 *   @0xc1f70 bl 0x1672d0 <_ZN9CBitmap3218SetAlphaFromBitmapEPS_>
 *   @0xc1f74 mov r0, r4
 *   @0xc1f78 bl 0xc1e60 <_ZN11CBackground11InitTextureEv>
 *   @0xc1f7c mov r0, r4
 *   @0xc1f80 pop {r4, lr}
 *   @0xc1f84 b 0xc1ea0 <_ZN11CBackground12InitLocalTPEEv>
 *   @0xc1f88 ldr r3, [pc, #0x1c]
 *   @0xc1f8c ldr r1, [pc, #0x1c]
 *   @0xc1f90 ldr r3, [pc, r3]
 *   @0xc1f94 add r1, pc, r1
 *   @0xc1f98 ldr r0, [r3]
 *   @0xc1f9c ldr r3, [r0]
 *   @0xc1fa0 ldr r3, [r3, #0xc]
 *   @0xc1fa4 blx r3
 *   @0xc1fa8 pop {r4, pc}
 *   @0xc1fac eorseq r11, r2, r4, lsl #15
 *   @0xc1fb0 .word 0x0026e9f4
 */
