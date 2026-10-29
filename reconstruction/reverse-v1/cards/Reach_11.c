/* cally 逆向卡：Reach_11 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 159 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/159 RenderStateManager::RestoreStates  0x168050  size 228  57 条（0x168050..0x168134）
 * @func 0x168050 0x168134  size 228  57 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RenderStateManager::RestoreStates()+0xb4 / RenderStateManager::SetRenderState(eRenderState, unsigned int) / RenderStateManager::SetSamplerState(int, eSamplerState, unsigned int)
 * 字段偏移 top8: 0x2×2 / 0x20×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x168050 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x168054 movw r4, #0x3db8
 *   @0x168058 ldr r3, [r0, r4]
 *   @0x16805c mov r5, r0
 *   @0x168060 cmp r3, #0
 *   @0x168064 ble 0x168104 <_ZN18RenderStateManager13RestoreStatesEv+0xb4>
 *   @0x168068 sub r3, r3, #1
 *   @0x16806c str r3, [r0, r4]
 *   @0x168070 mov r4, #0
 *   @0x168074 mov r6, #116
 *   @0x168078 movw r7, #0x3db8
 *   @0x16807c b 0x168084 <_ZN18RenderStateManager13RestoreStatesEv+0x34>
 *   @0x168080 ldr r3, [r5, r7]
 *   @0x168084 mla r3, r6, r3, r4
 *   @0x168088 mov r1, r4
 *   @0x16808c mov r0, r5
 *   @0x168090 add r4, r4, #1
 *   @0x168094 add r3, r3, #238
 *   @0x168098 ldr r2, [r5, r3, lsl #2]
 *   @0x16809c bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x1680a0 cmp r4, #36
 *   @0x1680a4 bne 0x168080 <_ZN18RenderStateManager13RestoreStatesEv+0x30>
 *   @0x1680a8 mov r7, #0
 *   @0x1680ac movw r9, #0x3db8
 *   @0x1680b0 mov r6, r7
 *   @0x1680b4 mov r8, #116
 *   @0x1680b8 mov r4, #0
 *   @0x1680bc ldr r3, [r5, r9]
 *   @0x1680c0 mov r2, r4
 *   @0x1680c4 mov r0, r5
 *   @0x1680c8 mov r1, r6
 *   @0x1680cc mla r3, r8, r3, r7
 *   @0x1680d0 add r3, r3, r4
 *   @0x1680d4 add r4, r4, #1
 *   @0x1680d8 add r3, r3, #272
 *   @0x1680dc add r3, r3, #2
 *   @0x1680e0 ldr r3, [r5, r3, lsl #2]
 *   @0x1680e4 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej>
 *   @0x1680e8 cmp r4, #10
 *   @0x1680ec bne 0x1680bc <_ZN18RenderStateManager13RestoreStatesEv+0x6c>
 *   @0x1680f0 add r6, r6, #1
 *   @0x1680f4 add r7, r7, #10
 *   @0x1680f8 cmp r6, #8
 *   @0x1680fc bne 0x1680b8 <_ZN18RenderStateManager13RestoreStatesEv+0x68>
 *   @0x168100 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x168104 ldr r3, [pc, #0x20]
 *   @0x168108 ldr r1, [pc, #0x20]
 *   @0x16810c ldr r3, [pc, r3]
 *   @0x168110 add r1, pc, r1
 *   @0x168114 ldr r0, [r3]
 *   @0x168118 ldr r3, [r0]
 *   @0x16811c ldr r3, [r3, #0xc]
 *   @0x168120 blx r3
 *   @0x168124 ldr r3, [r5, r4]
 *   @0x168128 b 0x168070 <_ZN18RenderStateManager13RestoreStatesEv+0x20>
 *   @0x16812c eoreq r5, r8, r8, lsl #12
 *   @0x168130 andseq r2, lr, r4, ror r6
 *
 * ══ §2/159 anon_299da0  0x299da0  size 228  57 条（0x299da0..0x299e84）
 * @func 0x299da0 0x299e84  size 228  57 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GetIBuffer(int) / RelySendReliable(int, char const*, int, int, int) / yySocket::SendUDPPacket(char*, int, unsigned char*, int, bool)
 * 字段偏移 top8: 0xc×3 / 0x8×3 / 0x4×2 / 0x28×2 / 0x2c×1 / 0xc0×1 / 0x30×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x299da0 push {r4, r5, r6, r7, r8, lr}
 *   @0x299da4 cmp r0, #63
 *   @0x299da8 sub sp, sp, #16
 *   @0x299dac mov r4, r0
 *   @0x299db0 mov r7, r3
 *   @0x299db4 ldrb r6, [sp, #0x2c]
 *   @0x299db8 bhi 0x299ddc <_Z16RelySendReliableiPKciii+0x174>
 *   @0x299dbc ldr r12, [pc, #0xc0]
 *   @0x299dc0 add r5, r0, r0, lsl #1
 *   @0x299dc4 ldr r12, [pc, r12]
 *   @0x299dc8 lsl r5, r5, #2
 *   @0x299dcc add r8, r12, r5
 *   @0x299dd0 ldrb r3, [r12, r5]
 *   @0x299dd4 cmp r3, #0
 *   @0x299dd8 bne 0x299de8 <_Z16RelySendReliableiPKciii+0x180>
 *   @0x299ddc vmov.f64 d0, #-1.000000e+00
 *   @0x299de0 add sp, sp, #16
 *   @0x299de4 pop {r4, r5, r6, r7, r8, pc}
 *   @0x299de8 mov r0, r7
 *   @0x299dec str r1, [sp, #0xc]
 *   @0x299df0 str r2, [sp, #0x8]
 *   @0x299df4 bl 0xc6720 <_Z10GetIBufferi>
 *   @0x299df8 ldr r1, [sp, #0xc]
 *   @0x299dfc ldr r2, [sp, #0x8]
 *   @0x299e00 subs r3, r0, #0
 *   @0x299e04 beq 0x299ddc <_Z16RelySendReliableiPKciii+0x174>
 *   @0x299e08 ldr r0, [r8, #0x4]
 *   @0x299e0c ldr r3, [r3, #0xc]
 *   @0x299e10 cmp r0, #0
 *   @0x299e14 moveq r12, #0
 *   @0x299e18 andne r12, r6, #1
 *   @0x299e1c cmp r12, #0
 *   @0x299e20 beq 0x299e50 <_Z16RelySendReliableiPKciii+0x1e8>
 *   @0x299e24 ldrb r12, [r0, #0x30]
 *   @0x299e28 cmp r12, #0
 *   @0x299e2c beq 0x299e58 <_Z16RelySendReliableiPKciii+0x1f0>
 *   @0x299e30 ldr r3, [sp, #0x28]
 *   @0x299e34 mov r0, r4
 *   @0x299e38 str r3, [sp]
 *   @0x299e3c mov r3, r7
 *   @0x299e40 bl 0x299c68 <_Z16RelySendReliableiPKciii>
 *   @0x299e44 vmov s15, r0
 *   @0x299e48 vcvt.f64.s32 d0, s15
 *   @0x299e4c b 0x299de0 <_Z16RelySendReliableiPKciii+0x178>
 *   @0x299e50 cmp r0, #0
 *   @0x299e54 beq 0x299e78 <_Z16RelySendReliableiPKciii+0x210>
 *   @0x299e58 ldr r12, [sp, #0x28]
 *   @0x299e5c str r6, [sp, #0x4]
 *   @0x299e60 str r12, [sp]
 *   @0x299e64 bl 0x296a38 <_ZN8yySocket13SendUDPPacketEPciPhib>
 *   @0x299e68 vmov s15, r0
 *   @0x299e6c vcvt.f64.s32 d0, s15
 *   @0x299e70 add sp, sp, #16
 *   @0x299e74 pop {r4, r5, r6, r7, r8, pc}
 *   @0x299e78 ldr r0, [r8, #0x8]
 *   @0x299e7c ldr r0, [r0]
 *   @0x299e80 b 0x299e58 <_Z16RelySendReliableiPKciii+0x1f0>
 *
 * ══ §3/159 YYGetInt32  0xce870  size 224  56 条（0xce870..0xce950）
 * @func 0xce870 0xce964  size 244  61 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_JS_ToNumber(RValue&, RValue&) / YYGetInt32(RValue const*, int) / __fixdfdi / KindName(RValue const*) / YYError(char const*, ...)
 * 字段偏移 top8: 0x4×3 / 0xc×1 / 0x30×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xce870 push {r4, r5, r6, lr}
 *   @0xce874 mov r6, r1
 *   @0xce878 add r1, r0, r1, lsl #4
 *   @0xce87c sub sp, sp, #16
 *   @0xce880 ldr r3, [r1, #0xc]
 *   @0xce884 bic r3, r3, #-16777216
 *   @0xce888 cmp r3, #13
 *   @0xce88c addls pc, pc, r3, lsl #2
 *   @0xce890 b 0xce910 <_Z10YYGetInt32PK6RValuei+0xa0>
 *   @0xce894 b 0xce8f4 <_Z10YYGetInt32PK6RValuei+0x84>
 *   @0xce898 b 0xce8d8 <_Z10YYGetInt32PK6RValuei+0x68>
 *   @0xce89c b 0xce910 <_Z10YYGetInt32PK6RValuei+0xa0>
 *   @0xce8a0 b 0xce910 <_Z10YYGetInt32PK6RValuei+0xa0>
 *   @0xce8a4 b 0xce910 <_Z10YYGetInt32PK6RValuei+0xa0>
 *   @0xce8a8 b 0xce910 <_Z10YYGetInt32PK6RValuei+0xa0>
 *   @0xce8ac b 0xce8d8 <_Z10YYGetInt32PK6RValuei+0x68>
 *   @0xce8b0 b 0xce8cc <_Z10YYGetInt32PK6RValuei+0x5c>
 *   @0xce8b4 b 0xce910 <_Z10YYGetInt32PK6RValuei+0xa0>
 *   @0xce8b8 b 0xce910 <_Z10YYGetInt32PK6RValuei+0xa0>
 *   @0xce8bc b 0xce8cc <_Z10YYGetInt32PK6RValuei+0x5c>
 *   @0xce8c0 b 0xce910 <_Z10YYGetInt32PK6RValuei+0xa0>
 *   @0xce8c4 b 0xce910 <_Z10YYGetInt32PK6RValuei+0xa0>
 *   @0xce8c8 b 0xce8f4 <_Z10YYGetInt32PK6RValuei+0x84>
 *   @0xce8cc ldr r0, [r0, r6, lsl #4]
 *   @0xce8d0 add sp, sp, #16
 *   @0xce8d4 pop {r4, r5, r6, pc}
 *   @0xce8d8 mov r0, sp
 *   @0xce8dc bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_>
 *   @0xce8e0 mov r0, sp
 *   @0xce8e4 mov r1, #0
 *   @0xce8e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xce8ec add sp, sp, #16
 *   @0xce8f0 pop {r4, r5, r6, pc}
 *   @0xce8f4 ldr r4, [r0, r6, lsl #4]
 *   @0xce8f8 ldr r5, [r1, #0x4]
 *   @0xce8fc mov r0, r4
 *   @0xce900 mov r1, r5
 *   @0xce904 bl 0x3194a0 <__fixdfdi>
 *   @0xce908 add sp, sp, #16
 *   @0xce90c pop {r4, r5, r6, pc}
 *   @0xce910 ldr r3, [pc, #0x30]
 *   @0xce914 mov r0, r1
 *   @0xce918 ldr r3, [pc, r3]
 *   @0xce91c ldr r4, [r3]
 *   @0xce920 bl 0xce54c <_Z8KindNamePK6RValue>
 *   @0xce924 add r2, r6, #1
 *   @0xce928 mov r1, r4
 *   @0xce92c mov r3, r0
 *   @0xce930 ldr r0, [pc, #0x14]
 *   @0xce934 add r0, pc, r0
 *   @0xce938 bl 0xd547c <_Z7YYErrorPKcz>
 *   @0xce93c mov r0, #0
 *   @0xce940 add sp, sp, #16
 *   @0xce944 pop {r4, r5, r6, pc}
 *   @0xce948 eorseq pc, r1, r8, lsl r2
 *   @0xce94c eoreq r3, r6, r8, lsl #20
 *
 * ══ §4/159 YYGetUint32  0xce950  size 224  56 条（0xce950..0xcea30）
 * @func 0xce950 0xcea30  size 224  56 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_JS_ToNumber(RValue&, RValue&) / YYGetUint32(RValue const*, int) / KindName(RValue const*) / YYError(char const*, ...)
 * 字段偏移 top8: 0x4×3 / 0xc×1 / 0x30×1 / 0x14×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xce950 push {r4, r5, r6, lr}
 *   @0xce954 mov r6, r1
 *   @0xce958 add r1, r0, r1, lsl #4
 *   @0xce95c sub sp, sp, #16
 *   @0xce960 ldr r3, [r1, #0xc]
 *   @0xce964 bic r3, r3, #-16777216
 *   @0xce968 cmp r3, #13
 *   @0xce96c addls pc, pc, r3, lsl #2
 *   @0xce970 b 0xce9f0 <_Z11YYGetUint32PK6RValuei+0xa0>
 *   @0xce974 b 0xce9d4 <_Z11YYGetUint32PK6RValuei+0x84>
 *   @0xce978 b 0xce9b8 <_Z11YYGetUint32PK6RValuei+0x68>
 *   @0xce97c b 0xce9f0 <_Z11YYGetUint32PK6RValuei+0xa0>
 *   @0xce980 b 0xce9f0 <_Z11YYGetUint32PK6RValuei+0xa0>
 *   @0xce984 b 0xce9f0 <_Z11YYGetUint32PK6RValuei+0xa0>
 *   @0xce988 b 0xce9f0 <_Z11YYGetUint32PK6RValuei+0xa0>
 *   @0xce98c b 0xce9b8 <_Z11YYGetUint32PK6RValuei+0x68>
 *   @0xce990 b 0xce9ac <_Z11YYGetUint32PK6RValuei+0x5c>
 *   @0xce994 b 0xce9f0 <_Z11YYGetUint32PK6RValuei+0xa0>
 *   @0xce998 b 0xce9f0 <_Z11YYGetUint32PK6RValuei+0xa0>
 *   @0xce99c b 0xce9ac <_Z11YYGetUint32PK6RValuei+0x5c>
 *   @0xce9a0 b 0xce9f0 <_Z11YYGetUint32PK6RValuei+0xa0>
 *   @0xce9a4 b 0xce9f0 <_Z11YYGetUint32PK6RValuei+0xa0>
 *   @0xce9a8 b 0xce9d4 <_Z11YYGetUint32PK6RValuei+0x84>
 *   @0xce9ac ldr r0, [r0, r6, lsl #4]
 *   @0xce9b0 add sp, sp, #16
 *   @0xce9b4 pop {r4, r5, r6, pc}
 *   @0xce9b8 mov r0, sp
 *   @0xce9bc bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_>
 *   @0xce9c0 mov r0, sp
 *   @0xce9c4 mov r1, #0
 *   @0xce9c8 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0xce9cc add sp, sp, #16
 *   @0xce9d0 pop {r4, r5, r6, pc}
 *   @0xce9d4 ldr r4, [r0, r6, lsl #4]
 *   @0xce9d8 ldr r5, [r1, #0x4]
 *   @0xce9dc vmov d7, r4, r5
 *   @0xce9e0 vcvt.u32.f64 s15, d7
 *   @0xce9e4 vmov r0, s15
 *   @0xce9e8 add sp, sp, #16
 *   @0xce9ec pop {r4, r5, r6, pc}
 *   @0xce9f0 ldr r3, [pc, #0x30]
 *   @0xce9f4 mov r0, r1
 *   @0xce9f8 ldr r3, [pc, r3]
 *   @0xce9fc ldr r4, [r3]
 *   @0xcea00 bl 0xce54c <_Z8KindNamePK6RValue>
 *   @0xcea04 add r2, r6, #1
 *   @0xcea08 mov r1, r4
 *   @0xcea0c mov r3, r0
 *   @0xcea10 ldr r0, [pc, #0x14]
 *   @0xcea14 add r0, pc, r0
 *   @0xcea18 bl 0xd547c <_Z7YYErrorPKcz>
 *   @0xcea1c mov r0, #0
 *   @0xcea20 add sp, sp, #16
 *   @0xcea24 pop {r4, r5, r6, pc}
 *   @0xcea28 eorseq pc, r1, r8, lsr r1
 *   @0xcea2c eoreq r3, r6, r8, ror #18
 *
 * ══ §5/159 YYGetFloat  0xcec84  size 224  56 条（0xcec84..0xced64）
 * @func 0xcec84 0xced64  size 224  56 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __floatdisf / KindName(RValue const*) / YYError(char const*, ...)
 * 字段偏移 top8: 0x4×5 / 0xc×1 / 0x34×1 / 0x18×1
 * VFP 指令 10 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcec84 add r2, r0, r1, lsl #4
 *   @0xcec88 push {r4, r5, r6, lr}
 *   @0xcec8c mov r6, r1
 *   @0xcec90 ldr r3, [r2, #0xc]
 *   @0xcec94 bic r3, r3, #-16777216
 *   @0xcec98 cmp r3, #13
 *   @0xcec9c addls pc, pc, r3, lsl #2
 *   @0xceca0 b 0xced20 <_Z10YYGetFloatPK6RValuei+0x9c>
 *   @0xceca4 b 0xced08 <_Z10YYGetFloatPK6RValuei+0x84>
 *   @0xceca8 b 0xced20 <_Z10YYGetFloatPK6RValuei+0x9c>
 *   @0xcecac b 0xced20 <_Z10YYGetFloatPK6RValuei+0x9c>
 *   @0xcecb0 b 0xced20 <_Z10YYGetFloatPK6RValuei+0x9c>
 *   @0xcecb4 b 0xced20 <_Z10YYGetFloatPK6RValuei+0x9c>
 *   @0xcecb8 b 0xced20 <_Z10YYGetFloatPK6RValuei+0x9c>
 *   @0xcecbc b 0xced20 <_Z10YYGetFloatPK6RValuei+0x9c>
 *   @0xcecc0 b 0xcecf4 <_Z10YYGetFloatPK6RValuei+0x70>
 *   @0xcecc4 b 0xced20 <_Z10YYGetFloatPK6RValuei+0x9c>
 *   @0xcecc8 b 0xced20 <_Z10YYGetFloatPK6RValuei+0x9c>
 *   @0xceccc b 0xcecdc <_Z10YYGetFloatPK6RValuei+0x58>
 *   @0xcecd0 b 0xced20 <_Z10YYGetFloatPK6RValuei+0x9c>
 *   @0xcecd4 b 0xced20 <_Z10YYGetFloatPK6RValuei+0x9c>
 *   @0xcecd8 b 0xced08 <_Z10YYGetFloatPK6RValuei+0x84>
 *   @0xcecdc ldr r0, [r0, r1, lsl #4]
 *   @0xcece0 ldr r1, [r2, #0x4]
 *   @0xcece4 bl 0x319398 <__floatdisf>
 *   @0xcece8 vmov s15, r0
 *   @0xcecec vmov r0, s15
 *   @0xcecf0 pop {r4, r5, r6, pc}
 *   @0xcecf4 ldr r6, [r0, r1, lsl #4]
 *   @0xcecf8 vmov s15, r6
 *   @0xcecfc vcvt.f32.s32 s15, s15
 *   @0xced00 vmov r0, s15
 *   @0xced04 pop {r4, r5, r6, pc}
 *   @0xced08 ldr r4, [r0, r1, lsl #4]
 *   @0xced0c ldr r5, [r2, #0x4]
 *   @0xced10 vmov d6, r4, r5
 *   @0xced14 vcvt.f32.f64 s15, d6
 *   @0xced18 vmov r0, s15
 *   @0xced1c pop {r4, r5, r6, pc}
 *   @0xced20 ldr r3, [pc, #0x34]
 *   @0xced24 mov r0, r2
 *   @0xced28 ldr r3, [pc, r3]
 *   @0xced2c ldr r4, [r3]
 *   @0xced30 bl 0xce54c <_Z8KindNamePK6RValue>
 *   @0xced34 add r2, r6, #1
 *   @0xced38 mov r1, r4
 *   @0xced3c mov r3, r0
 *   @0xced40 ldr r0, [pc, #0x18]
 *   @0xced44 add r0, pc, r0
 *   @0xced48 bl 0xd547c <_Z7YYErrorPKcz>
 *   @0xced4c vldr s15, [pc, #4]
 *   @0xced50 vmov r0, s15
 *   @0xced54 pop {r4, r5, r6, pc}
 *   @0xced58 andeq r0, r0, r0
 *   @0xced5c eorseq lr, r1, r8, lsl #28
 *   @0xced60 eoreq r3, r6, r8, lsr #14
 *
 * ══ §6/159 Code_Variable_Find_Slot_From_Local_Name  0xd1f74  size 224  56 条（0xd1f74..0xd2054）
 * @func 0xd1f74 0xd2054  size 224  56 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: unsigned int CHashMapCalculateHash<char const*>(char const*) / Code_Variable_Find_Slot_From_Local_Name(char const*)+0xb0 / bool CHashMapCompareKeys<char const*>(char const*, char const*)
 * 字段偏移 top8: 0x8×4 / 0x10×3 / 0xd4×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd1f74 ldr r3, [pc, #0xd4]
 *   @0xd1f78 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xd1f7c ldr r3, [pc, r3]
 *   @0xd1f80 mov r9, r0
 *   @0xd1f84 ldr r7, [r3]
 *   @0xd1f88 bl 0x1eeb88 <_Z21CHashMapCalculateHashIPKcEjT_>
 *   @0xd1f8c ldr r3, [r7, #0x8]
 *   @0xd1f90 ldr r2, [r7, #0x10]
 *   @0xd1f94 bic r10, r0, #-2147483648
 *   @0xd1f98 and r4, r10, r3
 *   @0xd1f9c lsl r8, r4, #1
 *   @0xd1fa0 add r1, r8, r4
 *   @0xd1fa4 add r2, r2, r1, lsl #2
 *   @0xd1fa8 ldr r5, [r2, #0x8]
 *   @0xd1fac cmp r5, #0
 *   @0xd1fb0 beq 0xd2024 <_Z39Code_Variable_Find_Slot_From_Local_NamePKc+0xb0>
 *   @0xd1fb4 mov r6, #0
 *   @0xd1fb8 b 0xd2000 <_Z39Code_Variable_Find_Slot_From_Local_NamePKc+0x8c>
 *   @0xd1fbc ldr r2, [r7]
 *   @0xd1fc0 and r5, r5, r3
 *   @0xd1fc4 add r1, r4, #1
 *   @0xd1fc8 add r2, r4, r2
 *   @0xd1fcc and r4, r1, r3
 *   @0xd1fd0 rsb r5, r5, r2
 *   @0xd1fd4 and r5, r5, r3
 *   @0xd1fd8 lsl r8, r4, #1
 *   @0xd1fdc cmp r5, r6
 *   @0xd1fe0 add r2, r8, r4
 *   @0xd1fe4 add r6, r6, #1
 *   @0xd1fe8 blt 0xd2024 <_Z39Code_Variable_Find_Slot_From_Local_NamePKc+0xb0>
 *   @0xd1fec ldr r1, [r7, #0x10]
 *   @0xd1ff0 add r2, r1, r2, lsl #2
 *   @0xd1ff4 ldr r5, [r2, #0x8]
 *   @0xd1ff8 cmp r5, #0
 *   @0xd1ffc beq 0xd2024 <_Z39Code_Variable_Find_Slot_From_Local_NamePKc+0xb0>
 *   @0xd2000 cmp r10, r5
 *   @0xd2004 bne 0xd1fbc <_Z39Code_Variable_Find_Slot_From_Local_NamePKc+0x48>
 *   @0xd2008 ldr r0, [r2]
 *   @0xd200c mov r1, r9
 *   @0xd2010 bl 0x1eeba8 <_Z19CHashMapCompareKeysIPKcEbT_S2_>
 *   @0xd2014 cmp r0, #0
 *   @0xd2018 bne 0xd202c <_Z39Code_Variable_Find_Slot_From_Local_NamePKc+0xb8>
 *   @0xd201c ldr r3, [r7, #0x8]
 *   @0xd2020 b 0xd1fbc <_Z39Code_Variable_Find_Slot_From_Local_NamePKc+0x48>
 *   @0xd2024 mvn r0, #0
 *   @0xd2028 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xd202c cmn r4, #1
 *   @0xd2030 beq 0xd2024 <_Z39Code_Variable_Find_Slot_From_Local_NamePKc+0xb0>
 *   @0xd2034 add r4, r8, r4
 *   @0xd2038 ldr r3, [r7, #0x10]
 *   @0xd203c add r4, r3, r4, lsl #2
 *   @0xd2040 cmn r4, #4
 *   @0xd2044 beq 0xd2024 <_Z39Code_Variable_Find_Slot_From_Local_NamePKc+0xb0>
 *   @0xd2048 ldr r0, [r4, #0x4]
 *   @0xd204c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xd2050 eorseq r11, r1, r8, lsr #24
 *
 * ══ §7/159 FindFreeDsMapIndex  0x100014  size 224  56 条（0x100014..0x1000f4）
 * @func 0x100014 0x1000f4  size 224  56 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x100030→0x4836ac, 0x100038→0x4836b0
 * 调用序列: DS_AutoMutex::DS_AutoMutex() / FindFreeDsMapIndex()+0x68 / DS_AutoMutex::~DS_AutoMutex() / MemoryManager::SetLength(void**, unsigned int, char const*, int)
 * 字段偏移 top8: 0x4×2 / 0xbc×1 / 0xb0×1 / 0xac×1 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x100014 push {r4, r5, r6, r7, r8, lr}
 *   @0x100018 sub sp, sp, #8
 *   @0x10001c add r6, sp, #4
 *   @0x100020 ldr r4, [pc, #0xbc]
 *   @0x100024 mov r0, r6
 *   @0x100028 add r4, pc, r4
 *   @0x10002c bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0x100030 ldr r3, [pc, #0xb0]
 *   @0x100034 ldr r8, [r4, r3]
 *   @0x100038 ldr r3, [pc, #0xac]
 *   @0x10003c ldr r5, [r8]
 *   @0x100040 ldr r7, [r4, r3]
 *   @0x100044 cmp r5, #0
 *   @0x100048 ble 0x10007c <_Z18FindFreeDsMapIndexv+0x68>
 *   @0x10004c ldr r3, [r7, #0x4]
 *   @0x100050 ldr r4, [r3]
 *   @0x100054 cmp r4, #0
 *   @0x100058 beq 0x100098 <_Z18FindFreeDsMapIndexv+0x84>
 *   @0x10005c mov r4, #0
 *   @0x100060 b 0x100070 <_Z18FindFreeDsMapIndexv+0x5c>
 *   @0x100064 ldr r2, [r3, #0x4]!
 *   @0x100068 cmp r2, #0
 *   @0x10006c beq 0x100098 <_Z18FindFreeDsMapIndexv+0x84>
 *   @0x100070 add r4, r4, #1
 *   @0x100074 cmp r4, r5
 *   @0x100078 bne 0x100064 <_Z18FindFreeDsMapIndexv+0x50>
 *   @0x10007c ldr r3, [r7]
 *   @0x100080 cmp r5, r3
 *   @0x100084 movlt r3, r5
 *   @0x100088 bge 0x1000ac <_Z18FindFreeDsMapIndexv+0x98>
 *   @0x10008c mov r4, r5
 *   @0x100090 add r3, r3, #1
 *   @0x100094 str r3, [r8]
 *   @0x100098 mov r0, r6
 *   @0x10009c bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0x1000a0 mov r0, r4
 *   @0x1000a4 add sp, sp, #8
 *   @0x1000a8 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1000ac add r1, r5, #16
 *   @0x1000b0 ldr r2, [pc, #0x38]
 *   @0x1000b4 movw r3, #0x3aa
 *   @0x1000b8 add r0, r7, #4
 *   @0x1000bc add r2, pc, r2
 *   @0x1000c0 lsl r1, r1, #2
 *   @0x1000c4 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1000c8 ldr r3, [r8]
 *   @0x1000cc mov r4, r5
 *   @0x1000d0 add r2, r3, #16
 *   @0x1000d4 add r3, r3, #1
 *   @0x1000d8 str r2, [r7]
 *   @0x1000dc str r3, [r8]
 *   @0x1000e0 b 0x100098 <_Z18FindFreeDsMapIndexv+0x84>
 *   @0x1000e4 eoreq r1, pc, r8, lsr #24
 *   @0x1000e8 .word 0xffffc028
 *   @0x1000ec .word 0xffffbcec
 *   @0x1000f0 eoreq r7, r3, r0, ror #21
 *
 * ══ §8/159 AllocTexture  0x173944  size 224  56 条（0x173944..0x173a24）
 * @func 0x173944 0x173a24  size 224  56 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x17394c→0x48ffe8, 0x173964→0x48ffec, 0x173a04→0x48ffec
 * 调用序列: AllocTexture()+0xb8 / MemoryManager::SetLength(void**, unsigned int, char const*, int) / MemoryManager::Alloc(unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x4×3 / 0x10×3 / 0xc4×2 / 0xb0×1 / 0x74×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x173944 push {r3, r4, r5, r6, r7, lr}
 *   @0x173948 ldr r3, [pc, #0xc4]
 *   @0x17394c ldr r2, [pc, #0xc4]
 *   @0x173950 add r3, pc, r3
 *   @0x173954 ldr r6, [r3, r2]
 *   @0x173958 ldr r0, [r6]
 *   @0x17395c cmp r0, #0
 *   @0x173960 ble 0x1739fc <_Z12AllocTexturev+0xb8>
 *   @0x173964 ldr r2, [pc, #0xb0]
 *   @0x173968 ldr r5, [r3, r2]
 *   @0x17396c ldr r3, [r5, #0x4]
 *   @0x173970 ldr r2, [r3]
 *   @0x173974 ldrb r4, [r2, #0x10]
 *   @0x173978 cmp r4, #0
 *   @0x17397c beq 0x1739f4 <_Z12AllocTexturev+0xb0>
 *   @0x173980 mov r4, #0
 *   @0x173984 b 0x173998 <_Z12AllocTexturev+0x54>
 *   @0x173988 ldr r2, [r3, #0x4]!
 *   @0x17398c ldrb r2, [r2, #0x10]
 *   @0x173990 cmp r2, #0
 *   @0x173994 beq 0x1739f4 <_Z12AllocTexturev+0xb0>
 *   @0x173998 add r4, r4, #1
 *   @0x17399c cmp r4, r0
 *   @0x1739a0 bne 0x173988 <_Z12AllocTexturev+0x44>
 *   @0x1739a4 ldr r7, [pc, #0x74]
 *   @0x1739a8 add r1, r0, #1
 *   @0x1739ac mov r3, #72
 *   @0x1739b0 add r0, r5, #4
 *   @0x1739b4 add r7, pc, r7
 *   @0x1739b8 lsl r1, r1, #2
 *   @0x1739bc mov r2, r7
 *   @0x1739c0 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1739c4 ldr lr, [r6]
 *   @0x1739c8 mov r1, r7
 *   @0x1739cc mov r3, #1
 *   @0x1739d0 mov r0, #20
 *   @0x1739d4 mov r2, #77
 *   @0x1739d8 add r12, lr, r3
 *   @0x1739dc add r7, lr, #1073741824
 *   @0x1739e0 str r12, [r5]
 *   @0x1739e4 str r12, [r6]
 *   @0x1739e8 ldr r5, [r5, #0x4]
 *   @0x1739ec bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1739f0 str r0, [r5, r7, lsl #2]
 *   @0x1739f4 mov r0, r4
 *   @0x1739f8 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1739fc movne r4, #0
 *   @0x173a00 bne 0x1739f4 <_Z12AllocTexturev+0xb0>
 *   @0x173a04 ldr r2, [pc, #0x10]
 *   @0x173a08 mov r4, r0
 *   @0x173a0c ldr r5, [r3, r2]
 *   @0x173a10 b 0x1739a4 <_Z12AllocTexturev+0x60>
 *   @0x173a14 eoreq lr, r7, r0, lsl #6
 *   @0x173a18 .word 0xffffe660
 *   @0x173a1c .word 0xffffbccc
 *   @0x173a20 andseq r7, sp, r0, ror #22
 *
 * ══ §9/159 CLayerManager::GetLayerIDForInstance  0x1b8cb8  size 224  56 条（0x1b8cb8..0x1b8d98）
 * @func 0x1b8cb8 0x1b8d98  size 224  56 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CHashMapCalculateHash(int) / CLayerManager::GetLayerIDForInstance(CRoom*, int)+0xa8
 * 字段偏移 top8: 0x8×2 / 0x118×1 / 0x120×1 / 0x110×1 / 0x4×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b8cb8 push {r4, r5, r6, r7, r8, lr}
 *   @0x1b8cbc subs r5, r0, #0
 *   @0x1b8cc0 beq 0x1b8d60 <_ZN13CLayerManager21GetLayerIDForInstanceEP5CRoomi+0xa8>
 *   @0x1b8cc4 mov r0, r1
 *   @0x1b8cc8 bl 0x1b6e44 <_Z21CHashMapCalculateHashi>
 *   @0x1b8ccc ldr r1, [r5, #0x118]
 *   @0x1b8cd0 ldr r7, [r5, #0x120]
 *   @0x1b8cd4 bic r8, r0, #-2147483648
 *   @0x1b8cd8 and r3, r8, r1
 *   @0x1b8cdc lsl r4, r3, #1
 *   @0x1b8ce0 add r2, r4, r3
 *   @0x1b8ce4 add r2, r7, r2, lsl #2
 *   @0x1b8ce8 ldr r2, [r2, #0x8]
 *   @0x1b8cec cmp r2, #0
 *   @0x1b8cf0 beq 0x1b8d60 <_ZN13CLayerManager21GetLayerIDForInstanceEP5CRoomi+0xa8>
 *   @0x1b8cf4 cmp r8, r2
 *   @0x1b8cf8 beq 0x1b8d70 <_ZN13CLayerManager21GetLayerIDForInstanceEP5CRoomi+0xb8>
 *   @0x1b8cfc ldr r0, [r5, #0x110]
 *   @0x1b8d00 and r2, r1, r2
 *   @0x1b8d04 add r12, r3, r0
 *   @0x1b8d08 rsb r2, r2, r12
 *   @0x1b8d0c tst r2, r1
 *   @0x1b8d10 bmi 0x1b8d60 <_ZN13CLayerManager21GetLayerIDForInstanceEP5CRoomi+0xa8>
 *   @0x1b8d14 mov r12, #0
 *   @0x1b8d18 b 0x1b8d2c <_ZN13CLayerManager21GetLayerIDForInstanceEP5CRoomi+0x74>
 *   @0x1b8d1c cmp r8, r2
 *   @0x1b8d20 beq 0x1b8d68 <_ZN13CLayerManager21GetLayerIDForInstanceEP5CRoomi+0xb0>
 *   @0x1b8d24 cmp r5, r12
 *   @0x1b8d28 blt 0x1b8d60 <_ZN13CLayerManager21GetLayerIDForInstanceEP5CRoomi+0xa8>
 *   @0x1b8d2c add r3, r3, #1
 *   @0x1b8d30 add r12, r12, #1
 *   @0x1b8d34 and r3, r1, r3
 *   @0x1b8d38 add r6, r3, r0
 *   @0x1b8d3c lsl r4, r3, #1
 *   @0x1b8d40 add r2, r4, r3
 *   @0x1b8d44 add r2, r7, r2, lsl #2
 *   @0x1b8d48 ldr r2, [r2, #0x8]
 *   @0x1b8d4c and r5, r1, r2
 *   @0x1b8d50 cmp r2, #0
 *   @0x1b8d54 rsb r5, r5, r6
 *   @0x1b8d58 and r5, r5, r1
 *   @0x1b8d5c bne 0x1b8d1c <_ZN13CLayerManager21GetLayerIDForInstanceEP5CRoomi+0x64>
 *   @0x1b8d60 mvn r0, #0
 *   @0x1b8d64 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1b8d68 cmn r3, #1
 *   @0x1b8d6c beq 0x1b8d60 <_ZN13CLayerManager21GetLayerIDForInstanceEP5CRoomi+0xa8>
 *   @0x1b8d70 add r3, r4, r3
 *   @0x1b8d74 add r7, r7, r3, lsl #2
 *   @0x1b8d78 cmn r7, #4
 *   @0x1b8d7c beq 0x1b8d60 <_ZN13CLayerManager21GetLayerIDForInstanceEP5CRoomi+0xa8>
 *   @0x1b8d80 ldr r3, [r7, #0x4]
 *   @0x1b8d84 ldr r3, [r3, #0x10]
 *   @0x1b8d88 cmp r3, #0
 *   @0x1b8d8c beq 0x1b8d60 <_ZN13CLayerManager21GetLayerIDForInstanceEP5CRoomi+0xa8>
 *   @0x1b8d90 ldr r0, [r3]
 *   @0x1b8d94 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §10/159 ogg_page_checksum_set  0x234354  size 224  56 条（0x234354..0x234434）
 * @func 0x234354 0x234434  size 224  56 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ogg_page_checksum_set+0x74 / ogg_page_checksum_set+0xac
 * 字段偏移 top8: 0x16×2 / 0x17×2 / 0x18×2 / 0x19×2 / 0x1×2 / 0x2×2 / 0x4×1 / 0x88×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x234354 cmp r0, #0
 *   @0x234358 push {r4, r5}
 *   @0x23435c beq 0x234424 <ogg_page_checksum_set+0xd0>
 *   @0x234360 ldr r2, [r0]
 *   @0x234364 mov r3, #0
 *   @0x234368 strb r3, [r2, #0x16]
 *   @0x23436c ldr r2, [r0]
 *   @0x234370 strb r3, [r2, #0x17]
 *   @0x234374 ldr r2, [r0]
 *   @0x234378 strb r3, [r2, #0x18]
 *   @0x23437c ldr r2, [r0]
 *   @0x234380 strb r3, [r2, #0x19]
 *   @0x234384 ldr r12, [r0, #0x4]
 *   @0x234388 cmp r12, r3
 *   @0x23438c movle r2, r3
 *   @0x234390 ldrle r5, [r0]
 *   @0x234394 ble 0x2343c8 <ogg_page_checksum_set+0x74>
 *   @0x234398 ldr r5, [r0]
 *   @0x23439c ldr r4, [pc, #0x88]
 *   @0x2343a0 add r12, r5, r12
 *   @0x2343a4 add r4, pc, r4
 *   @0x2343a8 mov r2, r5
 *   @0x2343ac ldrb r1, [r2], #1
 *   @0x2343b0 eor r1, r1, r3, lsr #24
 *   @0x2343b4 cmp r2, r12
 *   @0x2343b8 ldr r1, [r4, r1, lsl #2]
 *   @0x2343bc eor r3, r1, r3, lsl #8
 *   @0x2343c0 bne 0x2343ac <ogg_page_checksum_set+0x58>
 *   @0x2343c4 lsr r2, r3, #24
 *   @0x2343c8 ldr r12, [r0, #0xc]
 *   @0x2343cc cmp r12, #0
 *   @0x2343d0 ble 0x234400 <ogg_page_checksum_set+0xac>
 *   @0x2343d4 ldr r2, [r0, #0x8]
 *   @0x2343d8 ldr r4, [pc, #0x50]
 *   @0x2343dc add r12, r2, r12
 *   @0x2343e0 add r4, pc, r4
 *   @0x2343e4 ldrb r1, [r2], #1
 *   @0x2343e8 eor r1, r1, r3, lsr #24
 *   @0x2343ec cmp r2, r12
 *   @0x2343f0 ldr r1, [r4, r1, lsl #2]
 *   @0x2343f4 eor r3, r1, r3, lsl #8
 *   @0x2343f8 bne 0x2343e4 <ogg_page_checksum_set+0x90>
 *   @0x2343fc lsr r2, r3, #24
 *   @0x234400 strb r3, [r5, #0x16]
 *   @0x234404 lsr r12, r3, #8
 *   @0x234408 ldr r1, [r0]
 *   @0x23440c lsr r3, r3, #16
 *   @0x234410 strb r12, [r1, #0x17]
 *   @0x234414 ldr r1, [r0]
 *   @0x234418 strb r3, [r1, #0x18]
 *   @0x23441c ldr r3, [r0]
 *   @0x234420 strb r2, [r3, #0x19]
 *   @0x234424 pop {r4, r5}
 *   @0x234428 bx lr
 *   @0x23442c andseq r4, r3, r12, lsr r7
 *   @0x234430 andseq r4, r3, r0, lsl #14
 *
 * ══ §11/159 pow5mult_D2A  0x23d5ec  size 224  56 条（0x23d5ec..0x23d6cc）
 * @func 0x23d5ec 0x23d6cc  size 224  56 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: mult_D2A×2 / Bfree_D2A / multadd_D2A / i2b_D2A
 * 字段偏移 top8: 0x928×2 / 0xb4×1 / 0x38×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23d5ec push {r3, r4, r5, r6, r7, lr}
 *   @0x23d5f0 ands r3, r1, #3
 *   @0x23d5f4 mov r4, r1
 *   @0x23d5f8 mov r6, r0
 *   @0x23d5fc bne 0x23d688 <pow5mult_D2A+0x9c>
 *   @0x23d600 asrs r4, r4, #2
 *   @0x23d604 beq 0x23d668 <pow5mult_D2A+0x7c>
 *   @0x23d608 ldr r7, [pc, #0xb4]
 *   @0x23d60c add r7, pc, r7
 *   @0x23d610 ldr r5, [r7, #0x928]
 *   @0x23d614 cmp r5, #0
 *   @0x23d618 beq 0x23d6a8 <pow5mult_D2A+0xbc>
 *   @0x23d61c mov r7, #0
 *   @0x23d620 b 0x23d63c <pow5mult_D2A+0x50>
 *   @0x23d624 asrs r4, r4, #1
 *   @0x23d628 beq 0x23d668 <pow5mult_D2A+0x7c>
 *   @0x23d62c ldr r0, [r5]
 *   @0x23d630 cmp r0, #0
 *   @0x23d634 beq 0x23d670 <pow5mult_D2A+0x84>
 *   @0x23d638 mov r5, r0
 *   @0x23d63c tst r4, #1
 *   @0x23d640 beq 0x23d624 <pow5mult_D2A+0x38>
 *   @0x23d644 mov r0, r6
 *   @0x23d648 mov r1, r5
 *   @0x23d64c bl 0x23d498 <mult_D2A>
 *   @0x23d650 mov r3, r0
 *   @0x23d654 mov r0, r6
 *   @0x23d658 mov r6, r3
 *   @0x23d65c bl 0x23d2a0 <Bfree_D2A>
 *   @0x23d660 asrs r4, r4, #1
 *   @0x23d664 bne 0x23d62c <pow5mult_D2A+0x40>
 *   @0x23d668 mov r0, r6
 *   @0x23d66c pop {r3, r4, r5, r6, r7, pc}
 *   @0x23d670 mov r0, r5
 *   @0x23d674 mov r1, r5
 *   @0x23d678 bl 0x23d498 <mult_D2A>
 *   @0x23d67c str r0, [r5]
 *   @0x23d680 str r7, [r0]
 *   @0x23d684 b 0x23d638 <pow5mult_D2A+0x4c>
 *   @0x23d688 ldr r1, [pc, #0x38]
 *   @0x23d68c sub r3, r3, #1
 *   @0x23d690 mov r2, #0
 *   @0x23d694 add r1, pc, r1
 *   @0x23d698 ldr r1, [r1, r3, lsl #2]
 *   @0x23d69c bl 0x23d368 <multadd_D2A>
 *   @0x23d6a0 mov r6, r0
 *   @0x23d6a4 b 0x23d600 <pow5mult_D2A+0x14>
 *   @0x23d6a8 movw r0, #0x271
 *   @0x23d6ac bl 0x23d478 <i2b_D2A>
 *   @0x23d6b0 mov r3, #0
 *   @0x23d6b4 mov r5, r0
 *   @0x23d6b8 str r0, [r7, #0x928]
 *   @0x23d6bc str r3, [r0]
 *   @0x23d6c0 b 0x23d61c <pow5mult_D2A+0x30>
 *   @0x23d6c4 .word 0x00518494
 *   @0x23d6c8 andseq r11, r2, r12, asr #17
 *
 * ══ §12/159 sprintbuf  0x280dbc  size 224  56 条（0x280dbc..0x280e9c）
 * @func 0x280dbc 0x280e9c  size 224  56 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: printbuf_memappend×2 / 0xb6610 / 0xb6d24 / 0xb655c / 0xb65d4
 * 字段偏移 top8: 0x4×2 / 0x8c×2 / 0x8×2 / 0xc4×1 / 0xac×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x280dbc push {r1, r2, r3}
 *   @0x280dc0 mov r1, #128
 *   @0x280dc4 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x280dc8 sub sp, sp, #144
 *   @0x280dcc ldr r4, [pc, #0xc4]
 *   @0x280dd0 add r5, sp, #176
 *   @0x280dd4 ldr r8, [sp, #0xac]
 *   @0x280dd8 add r7, sp, #12
 *   @0x280ddc ldr r4, [pc, r4]
 *   @0x280de0 mov r3, r5
 *   @0x280de4 mov r9, r0
 *   @0x280de8 mov r0, r7
 *   @0x280dec ldr r12, [r4]
 *   @0x280df0 mov r2, r8
 *   @0x280df4 str r5, [sp, #0x4]
 *   @0x280df8 str r12, [sp, #0x8c]
 *   @0x280dfc bl 0xb6610 <vsnprintf@plt>
 *   @0x280e00 cmn r0, #1
 *   @0x280e04 mov r6, r0
 *   @0x280e08 movne r3, #0
 *   @0x280e0c moveq r3, #1
 *   @0x280e10 cmp r0, #127
 *   @0x280e14 orrgt r3, r3, #1
 *   @0x280e18 cmp r3, #0
 *   @0x280e1c beq 0x280e60 <sprintbuf+0xa4>
 *   @0x280e20 mov r1, r8
 *   @0x280e24 mov r2, r5
 *   @0x280e28 add r0, sp, #8
 *   @0x280e2c str r5, [sp, #0x4]
 *   @0x280e30 bl 0xb6d24 <vasprintf@plt>
 *   @0x280e34 cmn r0, #1
 *   @0x280e38 mov r6, r0
 *   @0x280e3c beq 0x280e70 <sprintbuf+0xb4>
 *   @0x280e40 ldr r1, [sp, #0x8]
 *   @0x280e44 mov r2, r6
 *   @0x280e48 mov r0, r9
 *   @0x280e4c bl 0x280d20 <printbuf_memappend>
 *   @0x280e50 ldr r0, [sp, #0x8]
 *   @0x280e54 bl 0xb655c <free@plt>
 *   @0x280e58 mov r0, r6
 *   @0x280e5c b 0x280e74 <sprintbuf+0xb8>
 *   @0x280e60 mov r0, r9
 *   @0x280e64 mov r1, r7
 *   @0x280e68 mov r2, r6
 *   @0x280e6c bl 0x280d20 <printbuf_memappend>
 *   @0x280e70 mov r0, r6
 *   @0x280e74 ldr r1, [sp, #0x8c]
 *   @0x280e78 ldr r3, [r4]
 *   @0x280e7c cmp r1, r3
 *   @0x280e80 bne 0x280e94 <sprintbuf+0xd8>
 *   @0x280e84 add sp, sp, #144
 *   @0x280e88 pop {r4, r5, r6, r7, r8, r9, lr}
 *   @0x280e8c add sp, sp, #12
 *   @0x280e90 bx lr
 *   @0x280e94 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x280e98 andseq r12, r6, r4, ror r11
 *
 * ══ §13/159 void std::sort<b2ParticleSystem::Proxy*>  0x2da584  size 224  56 条（0x2da584..0x2da664）
 * @func 0x2da584 0x2da664  size 224  56 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2d49b8+0x1d0 / anon_2d49b8+0x358 / void std::sort<b2ParticleSystem::Proxy*>(b2ParticleSystem::Proxy*, b2ParticleSystem::Proxy*)+0x9c
 * 字段偏移 top8: 0x4×2 / 0x-4×2 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2da584 cmp r0, r1
 *   @0x2da588 push {r4, r5, r6, r7, r8, lr}
 *   @0x2da58c mov r6, r0
 *   @0x2da590 mov r7, r1
 *   @0x2da594 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x2da598 rsb r4, r0, r1
 *   @0x2da59c mov r2, #0
 *   @0x2da5a0 asr r3, r4, #3
 *   @0x2da5a4 cmp r3, #1
 *   @0x2da5a8 beq 0x2da5c0 <_ZSt4sortIPN16b2ParticleSystem5ProxyEEvT_S3_+0x3c>
 *   @0x2da5ac asr r3, r3, #1
 *   @0x2da5b0 add r2, r2, #1
 *   @0x2da5b4 cmp r3, #1
 *   @0x2da5b8 bne 0x2da5ac <_ZSt4sortIPN16b2ParticleSystem5ProxyEEvT_S3_+0x28>
 *   @0x2da5bc lsl r2, r2, #1
 *   @0x2da5c0 mov r0, r6
 *   @0x2da5c4 mov r1, r7
 *   @0x2da5c8 bl 0x2d4b88 <_ZN15b2QueryCallbackD0Ev+0x1f8>
 *   @0x2da5cc cmp r4, #135
 *   @0x2da5d0 bgt 0x2da5e4 <_ZSt4sortIPN16b2ParticleSystem5ProxyEEvT_S3_+0x60>
 *   @0x2da5d4 mov r0, r6
 *   @0x2da5d8 mov r1, r7
 *   @0x2da5dc pop {r4, r5, r6, r7, r8, lr}
 *   @0x2da5e0 b 0x2d4d10 <_ZN15b2QueryCallbackD0Ev+0x380>
 *   @0x2da5e4 add r5, r6, #128
 *   @0x2da5e8 mov r0, r6
 *   @0x2da5ec mov r1, r5
 *   @0x2da5f0 bl 0x2d4d10 <_ZN15b2QueryCallbackD0Ev+0x380>
 *   @0x2da5f4 cmp r7, r5
 *   @0x2da5f8 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x2da5fc add r6, r6, #120
 *   @0x2da600 ldr r4, [r5, #0x4]
 *   @0x2da604 mov r3, r6
 *   @0x2da608 ldr r2, [r5, #-0x4]
 *   @0x2da60c ldr r8, [r6, #0x8]
 *   @0x2da610 cmp r4, r2
 *   @0x2da614 bhs 0x2da65c <_ZSt4sortIPN16b2ParticleSystem5ProxyEEvT_S3_+0xd8>
 *   @0x2da618 mov r2, r5
 *   @0x2da61c b 0x2da624 <_ZSt4sortIPN16b2ParticleSystem5ProxyEEvT_S3_+0xa0>
 *   @0x2da620 mov r3, r12
 *   @0x2da624 ldm r3, {r0, r1}
 *   @0x2da628 sub r12, r3, #8
 *   @0x2da62c stm r2, {r0, r1}
 *   @0x2da630 mov r2, r3
 *   @0x2da634 ldr r0, [r3, #-0x4]
 *   @0x2da638 cmp r4, r0
 *   @0x2da63c blo 0x2da620 <_ZSt4sortIPN16b2ParticleSystem5ProxyEEvT_S3_+0x9c>
 *   @0x2da640 add r5, r5, #8
 *   @0x2da644 str r8, [r3]
 *   @0x2da648 cmp r7, r5
 *   @0x2da64c str r4, [r3, #0x4]
 *   @0x2da650 add r6, r6, #8
 *   @0x2da654 bne 0x2da600 <_ZSt4sortIPN16b2ParticleSystem5ProxyEEvT_S3_+0x7c>
 *   @0x2da658 pop {r4, r5, r6, r7, r8, pc}
 *   @0x2da65c mov r3, r5
 *   @0x2da660 b 0x2da640 <_ZSt4sortIPN16b2ParticleSystem5ProxyEEvT_S3_+0xbc>
 *
 * ══ §14/159 urlEncode  0x1d22c4  size 220  55 条（0x1d22c4..0x1d23a0）
 * @func 0x1d22c4 0x1d23a0  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6538 / urlEncode(char const*)+0xc8 / urlEncode(char const*)+0x88 / YYStrBuilderYY::AddFormat(char const*, ...) / YYStrDup(char const*) / 0xb655c
 * 字段偏移 top8: 0x4×3 / 0xc×2 / 0x9c×2 / 0x8×1 / 0xa0×1 / 0x1×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d22c4 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1d22c8 sub sp, sp, #16
 *   @0x1d22cc mov r4, #0
 *   @0x1d22d0 mov r6, r0
 *   @0x1d22d4 str r4, [sp, #0x4]
 *   @0x1d22d8 str r4, [sp, #0x8]
 *   @0x1d22dc str r4, [sp, #0xc]
 *   @0x1d22e0 bl 0xb6538 <strlen@plt>
 *   @0x1d22e4 subs r7, r0, #0
 *   @0x1d22e8 ble 0x1d238c <_Z9urlEncodePKc+0xc8>
 *   @0x1d22ec ldr r10, [pc, #0xa0]
 *   @0x1d22f0 add r5, sp, #4
 *   @0x1d22f4 ldr r8, [pc, #0x9c]
 *   @0x1d22f8 ldr r9, [pc, #0x9c]
 *   @0x1d22fc ldr r10, [pc, r10]
 *   @0x1d2300 add r8, pc, r8
 *   @0x1d2304 add r9, pc, r9
 *   @0x1d2308 ldrb r3, [r6, r4]
 *   @0x1d230c mov r0, r5
 *   @0x1d2310 ldr r12, [r10]
 *   @0x1d2314 mov r1, r8
 *   @0x1d2318 sub lr, r3, #45
 *   @0x1d231c add r12, r12, r3
 *   @0x1d2320 mov r2, r3
 *   @0x1d2324 ldrb r12, [r12, #0x1]
 *   @0x1d2328 tst r12, #7
 *   @0x1d232c bne 0x1d234c <_Z9urlEncodePKc+0x88>
 *   @0x1d2330 cmp r3, #95
 *   @0x1d2334 cmpne lr, #1
 *   @0x1d2338 bls 0x1d234c <_Z9urlEncodePKc+0x88>
 *   @0x1d233c cmp r3, #126
 *   @0x1d2340 movne r2, r3
 *   @0x1d2344 movne r0, r5
 *   @0x1d2348 movne r1, r9
 *   @0x1d234c add r4, r4, #1
 *   @0x1d2350 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz>
 *   @0x1d2354 cmp r7, r4
 *   @0x1d2358 bne 0x1d2308 <_Z9urlEncodePKc+0x44>
 *   @0x1d235c ldr r0, [sp, #0x4]
 *   @0x1d2360 mov r3, #0
 *   @0x1d2364 str r3, [sp, #0xc]
 *   @0x1d2368 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x1d236c mov r4, r0
 *   @0x1d2370 ldr r0, [sp, #0x4]
 *   @0x1d2374 cmp r0, #0
 *   @0x1d2378 beq 0x1d2380 <_Z9urlEncodePKc+0xbc>
 *   @0x1d237c bl 0xb655c <free@plt>
 *   @0x1d2380 mov r0, r4
 *   @0x1d2384 add sp, sp, #16
 *   @0x1d2388 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1d238c mov r0, r4
 *   @0x1d2390 b 0x1d2360 <_Z9urlEncodePKc+0x9c>
 *   @0x1d2394 eoreq r11, r1, r4, lsl #13
 *   @0x1d2398 ldrsbeq r7, [r6], -r12
 *   @0x1d239c ldrsheq lr, [r7], -r12
 *
 * ══ §15/159 Variable_BuiltIn_Find  0x1f3a5c  size 220  55 条（0x1f3a5c..0x1f3b38）
 * @func 0x1f3a5c 0x1f3b38  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: unsigned int CHashMapCalculateHash<char const*>(char const*) / Variable_BuiltIn_Find(char const*)+0xa8
 * 字段偏移 top8: 0x8×3 / 0xd0×1 / 0x10×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f3a5c ldr r3, [pc, #0xd0]
 *   @0x1f3a60 push {r4, r5, r6, r7, r8, lr}
 *   @0x1f3a64 ldr r3, [pc, r3]
 *   @0x1f3a68 ldr r5, [r3]
 *   @0x1f3a6c bl 0x1eeb88 <_Z21CHashMapCalculateHashIPKcEjT_>
 *   @0x1f3a70 ldr r1, [r5, #0x8]
 *   @0x1f3a74 ldr r7, [r5, #0x10]
 *   @0x1f3a78 bic r0, r0, #-2147483648
 *   @0x1f3a7c and r3, r0, r1
 *   @0x1f3a80 lsl r4, r3, #1
 *   @0x1f3a84 add r2, r4, r3
 *   @0x1f3a88 add r2, r7, r2, lsl #2
 *   @0x1f3a8c ldr r2, [r2, #0x8]
 *   @0x1f3a90 cmp r2, #0
 *   @0x1f3a94 beq 0x1f3b04 <_Z21Variable_BuiltIn_FindPKc+0xa8>
 *   @0x1f3a98 cmp r0, r2
 *   @0x1f3a9c beq 0x1f3b14 <_Z21Variable_BuiltIn_FindPKc+0xb8>
 *   @0x1f3aa0 ldr r8, [r5]
 *   @0x1f3aa4 and r2, r1, r2
 *   @0x1f3aa8 add r12, r3, r8
 *   @0x1f3aac rsb r2, r2, r12
 *   @0x1f3ab0 tst r2, r1
 *   @0x1f3ab4 bmi 0x1f3b04 <_Z21Variable_BuiltIn_FindPKc+0xa8>
 *   @0x1f3ab8 mov r12, #0
 *   @0x1f3abc b 0x1f3ad0 <_Z21Variable_BuiltIn_FindPKc+0x74>
 *   @0x1f3ac0 cmp r0, r2
 *   @0x1f3ac4 beq 0x1f3b0c <_Z21Variable_BuiltIn_FindPKc+0xb0>
 *   @0x1f3ac8 cmp r5, r12
 *   @0x1f3acc blt 0x1f3b04 <_Z21Variable_BuiltIn_FindPKc+0xa8>
 *   @0x1f3ad0 add r3, r3, #1
 *   @0x1f3ad4 add r12, r12, #1
 *   @0x1f3ad8 and r3, r1, r3
 *   @0x1f3adc add r6, r3, r8
 *   @0x1f3ae0 lsl r4, r3, #1
 *   @0x1f3ae4 add r2, r4, r3
 *   @0x1f3ae8 add r2, r7, r2, lsl #2
 *   @0x1f3aec ldr r2, [r2, #0x8]
 *   @0x1f3af0 and r5, r1, r2
 *   @0x1f3af4 cmp r2, #0
 *   @0x1f3af8 rsb r5, r5, r6
 *   @0x1f3afc and r5, r5, r1
 *   @0x1f3b00 bne 0x1f3ac0 <_Z21Variable_BuiltIn_FindPKc+0x64>
 *   @0x1f3b04 mvn r0, #0
 *   @0x1f3b08 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1f3b0c cmn r3, #1
 *   @0x1f3b10 beq 0x1f3b2c <_Z21Variable_BuiltIn_FindPKc+0xd0>
 *   @0x1f3b14 add r3, r4, r3
 *   @0x1f3b18 add r7, r7, r3, lsl #2
 *   @0x1f3b1c cmn r7, #4
 *   @0x1f3b20 beq 0x1f3b04 <_Z21Variable_BuiltIn_FindPKc+0xa8>
 *   @0x1f3b24 ldr r0, [r7, #0x4]
 *   @0x1f3b28 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1f3b2c mov r0, r3
 *   @0x1f3b30 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1f3b34 andseq sp, pc, r8, asr #7
 *
 * ══ §16/159 cAudio_Sound::Prepare  0x219404  size 220  55 条（0x219404..0x2194e0）
 * @func 0x219404 0x2194f4  size 240  60 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: cAudio_Sound::Prepare(int)+0xa8 / alutCreateBufferFromFileImage / alutGetError / 0xb6a54 / COggAudio::DecompressOgg(cAudio_Sound*)
 * 字段偏移 top8: 0x4×2 / 0x4c×2 / 0x18×2 / 0xc0×1 / 0xc×1 / 0xa4×1 / 0x24×1 / 0x26×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x219404 push {r3, r4, r5, lr}
 *   @0x219408 mov r4, r0
 *   @0x21940c ldr r3, [pc, #0xc0]
 *   @0x219410 ldr r3, [pc, r3]
 *   @0x219414 ldrb r2, [r3]
 *   @0x219418 cmp r2, #0
 *   @0x21941c popne {r3, r4, r5, pc}
 *   @0x219420 ldr r0, [r0, #0xc]
 *   @0x219424 cmp r0, #0
 *   @0x219428 popeq {r3, r4, r5, pc}
 *   @0x21942c ldr r3, [pc, #0xa4]
 *   @0x219430 ldr r3, [pc, r3]
 *   @0x219434 ldr r3, [r3, #0x4]
 *   @0x219438 cmp r3, #0
 *   @0x21943c ble 0x2194ac <_ZN12cAudio_Sound7PrepareEi+0xa8>
 *   @0x219440 ldr r3, [r4, #0x4c]
 *   @0x219444 cmp r1, r3
 *   @0x219448 popne {r3, r4, r5, pc}
 *   @0x21944c ldrb r3, [r4, #0x24]
 *   @0x219450 cmp r3, #0
 *   @0x219454 movne r3, #0
 *   @0x219458 strne r3, [r4, #0x30]
 *   @0x21945c popne {r3, r4, r5, pc}
 *   @0x219460 ldrb r3, [r4, #0x26]
 *   @0x219464 ldr r2, [r0], #4
 *   @0x219468 cmp r3, #0
 *   @0x21946c bne 0x2194b4 <_ZN12cAudio_Sound7PrepareEi+0xb0>
 *   @0x219470 ldrb r3, [r4, #0x25]
 *   @0x219474 cmp r3, #0
 *   @0x219478 strne r0, [r4, #0x28]
 *   @0x21947c strne r2, [r4, #0x2c]
 *   @0x219480 popne {r3, r4, r5, pc}
 *   @0x219484 mov r1, r2
 *   @0x219488 bl 0x222638 <alutCreateBufferFromFileImage>
 *   @0x21948c mov r5, r0
 *   @0x219490 bl 0x221714 <alutGetError>
 *   @0x219494 cmp r0, #0
 *   @0x219498 popne {r3, r4, r5, pc}
 *   @0x21949c bl 0xb6a54 <alGetError@plt>
 *   @0x2194a0 cmp r0, #0
 *   @0x2194a4 streq r5, [r4, #0x18]
 *   @0x2194a8 pop {r3, r4, r5, pc}
 *   @0x2194ac str r2, [r4, #0x4c]
 *   @0x2194b0 b 0x21944c <_ZN12cAudio_Sound7PrepareEi+0x48>
 *   @0x2194b4 str r0, [r4, #0x28]
 *   @0x2194b8 mov r1, r4
 *   @0x2194bc ldr r0, [pc, #0x18]
 *   @0x2194c0 str r2, [r4, #0x2c]
 *   @0x2194c4 add r0, pc, r0
 *   @0x2194c8 bl 0x226dec <_ZN9COggAudio13DecompressOggEP12cAudio_Sound>
 *   @0x2194cc str r0, [r4, #0x18]
 *   @0x2194d0 pop {r3, r4, r5, pc}
 *   @0x2194d4 andseq r5, sp, r12, lsr r12
 *   @0x2194d8 andseq r5, sp, r0, lsr #24
 *   @0x2194dc ldrsbeq r11, [r3], #-208
 *
 * ══ §17/159 alutInit  0x221a34  size 220  55 条（0x221a34..0x221b10）
 * @func 0x221a34 0x221b10  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _alutSetError×5 / 0xb6be0×2 / 0xb6bb0 / 0xb6bbc / 0xb6bc8 / 0xb6bd4
 * 字段偏移 top8: 0xcc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x221a34 push {r3, r4, r5, r6, r7, lr}
 *   @0x221a38 ldr r4, [pc, #0xcc]
 *   @0x221a3c add r4, pc, r4
 *   @0x221a40 ldr r6, [r4]
 *   @0x221a44 cmp r6, #0
 *   @0x221a48 bne 0x221ab4 <alutInit+0x80>
 *   @0x221a4c rsbs r5, r1, #1
 *   @0x221a50 movlo r5, #0
 *   @0x221a54 cmp r0, #0
 *   @0x221a58 eoreq r5, r5, #1
 *   @0x221a5c cmp r5, #0
 *   @0x221a60 bne 0x221aa4 <alutInit+0x70>
 *   @0x221a64 mov r0, r5
 *   @0x221a68 bl 0xb6bb0 <alcOpenDevice@plt>
 *   @0x221a6c subs r7, r0, #0
 *   @0x221a70 beq 0x221ae4 <alutInit+0xb0>
 *   @0x221a74 mov r1, r5
 *   @0x221a78 bl 0xb6bbc <alcCreateContext@plt>
 *   @0x221a7c subs r5, r0, #0
 *   @0x221a80 beq 0x221af4 <alutInit+0xc0>
 *   @0x221a84 bl 0xb6bc8 <alcMakeContextCurrent@plt>
 *   @0x221a88 subs r6, r0, #0
 *   @0x221a8c beq 0x221ac4 <alutInit+0x90>
 *   @0x221a90 mov r3, #1
 *   @0x221a94 str r5, [r4, #0x4]
 *   @0x221a98 mov r0, r3
 *   @0x221a9c str r3, [r4]
 *   @0x221aa0 pop {r3, r4, r5, r6, r7, pc}
 *   @0x221aa4 movw r0, #0x202
 *   @0x221aa8 bl 0x221940 <_alutSetError>
 *   @0x221aac mov r0, r6
 *   @0x221ab0 pop {r3, r4, r5, r6, r7, pc}
 *   @0x221ab4 movw r0, #0x203
 *   @0x221ab8 bl 0x221940 <_alutSetError>
 *   @0x221abc mov r0, #0
 *   @0x221ac0 pop {r3, r4, r5, r6, r7, pc}
 *   @0x221ac4 mov r0, r5
 *   @0x221ac8 bl 0xb6bd4 <alcDestroyContext@plt>
 *   @0x221acc mov r0, r7
 *   @0x221ad0 bl 0xb6be0 <alcCloseDevice@plt>
 *   @0x221ad4 movw r0, #0x20a
 *   @0x221ad8 bl 0x221940 <_alutSetError>
 *   @0x221adc mov r0, r6
 *   @0x221ae0 pop {r3, r4, r5, r6, r7, pc}
 *   @0x221ae4 movw r0, #0x207
 *   @0x221ae8 bl 0x221940 <_alutSetError>
 *   @0x221aec mov r0, r7
 *   @0x221af0 pop {r3, r4, r5, r6, r7, pc}
 *   @0x221af4 mov r0, r7
 *   @0x221af8 bl 0xb6be0 <alcCloseDevice@plt>
 *   @0x221afc movw r0, #0x209
 *   @0x221b00 bl 0x221940 <_alutSetError>
 *   @0x221b04 mov r0, r5
 *   @0x221b08 pop {r3, r4, r5, r6, r7, pc}
 *   @0x221b0c subseq r3, r3, r12, lsr #20
 *
 * ══ §18/159 CPhysicsFixture::Finalise  0x236b84  size 220  55 条（0x236b84..0x236c60）
 * @func 0x236b84 0x236c60  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2ChainShape::CreateChain(b2Vec2 const*, int) / 0xb65c8 / Error_Show_Action(char const*, bool) / b2PolygonShape::Set(b2Vec2 const*, int) / b2ChainShape::CreateLoop(b2Vec2 const*, int) / 0xb65d4
 * 字段偏移 top8: 0x14×2 / 0x404×2 / 0xc×2 / 0xc4×1 / 0x20×1 / 0x4×1 / 0x19×1 / 0x80×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x236b84 push {r4, r5, lr}
 *   @0x236b88 sub sp, sp, #1024
 *   @0x236b8c ldr r4, [pc, #0xc4]
 *   @0x236b90 sub sp, sp, #12
 *   @0x236b94 ldr r12, [r0, #0x14]
 *   @0x236b98 mov r3, r0
 *   @0x236b9c ldr r4, [pc, r4]
 *   @0x236ba0 cmp r12, #0
 *   @0x236ba4 ldr r2, [r4]
 *   @0x236ba8 str r2, [sp, #0x404]
 *   @0x236bac beq 0x236bcc <_ZN15CPhysicsFixture8FinaliseEP9CInstance+0x48>
 *   @0x236bb0 ldr r2, [r0, #0x20]
 *   @0x236bb4 ldr r0, [r2]
 *   @0x236bb8 ldr r2, [r0, #0x4]
 *   @0x236bbc cmp r2, #2
 *   @0x236bc0 beq 0x236c04 <_ZN15CPhysicsFixture8FinaliseEP9CInstance+0x80>
 *   @0x236bc4 cmp r2, #3
 *   @0x236bc8 beq 0x236be8 <_ZN15CPhysicsFixture8FinaliseEP9CInstance+0x64>
 *   @0x236bcc ldr r2, [sp, #0x404]
 *   @0x236bd0 ldr r3, [r4]
 *   @0x236bd4 cmp r2, r3
 *   @0x236bd8 bne 0x236c54 <_ZN15CPhysicsFixture8FinaliseEP9CInstance+0xd0>
 *   @0x236bdc add sp, sp, #1024
 *   @0x236be0 add sp, sp, #12
 *   @0x236be4 pop {r4, r5, pc}
 *   @0x236be8 ldrb r2, [r3, #0x19]
 *   @0x236bec mov r1, r12
 *   @0x236bf0 cmp r2, #0
 *   @0x236bf4 ldr r2, [r3, #0xc]
 *   @0x236bf8 bne 0x236c4c <_ZN15CPhysicsFixture8FinaliseEP9CInstance+0xc8>
 *   @0x236bfc bl 0x2c4ae0 <_ZN12b2ChainShape11CreateChainEPK6b2Vec2i>
 *   @0x236c00 b 0x236bcc <_ZN15CPhysicsFixture8FinaliseEP9CInstance+0x48>
 *   @0x236c04 ldr r2, [r3, #0xc]
 *   @0x236c08 cmp r2, #2
 *   @0x236c0c bgt 0x236c40 <_ZN15CPhysicsFixture8FinaliseEP9CInstance+0xbc>
 *   @0x236c10 ldr r3, [r1, #0x80]
 *   @0x236c14 add r5, sp, #4
 *   @0x236c18 ldr r2, [pc, #0x3c]
 *   @0x236c1c mov r1, #1024
 *   @0x236c20 mov r0, r5
 *   @0x236c24 add r2, pc, r2
 *   @0x236c28 ldr r3, [r3, #0x14]
 *   @0x236c2c bl 0xb65c8 <snprintf@plt>
 *   @0x236c30 mov r0, r5
 *   @0x236c34 mov r1, #1
 *   @0x236c38 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x236c3c b 0x236bcc <_ZN15CPhysicsFixture8FinaliseEP9CInstance+0x48>
 *   @0x236c40 mov r1, r12
 *   @0x236c44 bl 0x2c6028 <_ZN14b2PolygonShape3SetEPK6b2Vec2i>
 *   @0x236c48 b 0x236bcc <_ZN15CPhysicsFixture8FinaliseEP9CInstance+0x48>
 *   @0x236c4c bl 0x2c4a68 <_ZN12b2ChainShape10CreateLoopEPK6b2Vec2i>
 *   @0x236c50 b 0x236bcc <_ZN15CPhysicsFixture8FinaliseEP9CInstance+0x48>
 *   @0x236c54 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x236c58 ldrheq r6, [r11], -r4
 *   @0x236c5c andseq lr, r1, r4, lsr #11
 *
 * ══ §19/159 CPhysicsWorld::UpdatePaths  0x237f94  size 220  55 条（0x237f94..0x238070）
 * @func 0x237f94 0x238070  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::Adapt_Path()×2 / Perform_Event(CInstance*, CInstance*, int, int)×2 / CPhysicsObject::SetPosition(float, float) / CPhysicsWorld::UpdatePaths()+0x58
 * 字段偏移 top8: 0xc8×1 / 0x80×1 / 0x128×1 / 0x178×1 / 0x84×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x237f94 push {r3, r4, r5, r6, r7, lr}
 *   @0x237f98 mov r7, r0
 *   @0x237f9c ldr r3, [pc, #0xc8]
 *   @0x237fa0 ldr r3, [pc, r3]
 *   @0x237fa4 ldr r3, [r3]
 *   @0x237fa8 ldr r4, [r3, #0x80]
 *   @0x237fac cmp r4, #0
 *   @0x237fb0 bne 0x237ff8 <_ZN13CPhysicsWorld11UpdatePathsEv+0x64>
 *   @0x237fb4 pop {r3, r4, r5, r6, r7, pc}
 *   @0x237fb8 mov r0, r4
 *   @0x237fbc bl 0x19411c <_ZN9CInstance10Adapt_PathEv>
 *   @0x237fc0 cmp r0, #0
 *   @0x237fc4 bne 0x238054 <_ZN13CPhysicsWorld11UpdatePathsEv+0xc0>
 *   @0x237fc8 vldr s15, [r7, #96]
 *   @0x237fcc vldr s13, [r4, #180]
 *   @0x237fd0 vldr s14, [r4, #184]
 *   @0x237fd4 vmul.f32 s13, s15, s13
 *   @0x237fd8 mov r0, r6
 *   @0x237fdc vmul.f32 s14, s15, s14
 *   @0x237fe0 vmov r1, s13
 *   @0x237fe4 vmov r2, s14
 *   @0x237fe8 bl 0x236e00 <_ZN14CPhysicsObject11SetPositionEff>
 *   @0x237fec cmp r5, #0
 *   @0x237ff0 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x237ff4 mov r4, r5
 *   @0x237ff8 ldr r3, [r4, #0x128]
 *   @0x237ffc ldr r5, [r4, #0x178]
 *   @0x238000 cmp r3, #0
 *   @0x238004 blt 0x237fec <_ZN13CPhysicsWorld11UpdatePathsEv+0x58>
 *   @0x238008 ldr r6, [r4, #0x84]
 *   @0x23800c cmp r6, #0
 *   @0x238010 beq 0x238024 <_ZN13CPhysicsWorld11UpdatePathsEv+0x90>
 *   @0x238014 ldr r3, [r6]
 *   @0x238018 ldr r3, [r3]
 *   @0x23801c cmp r3, #2
 *   @0x238020 bne 0x237fb8 <_ZN13CPhysicsWorld11UpdatePathsEv+0x24>
 *   @0x238024 mov r0, r4
 *   @0x238028 bl 0x19411c <_ZN9CInstance10Adapt_PathEv>
 *   @0x23802c cmp r0, #0
 *   @0x238030 beq 0x237fec <_ZN13CPhysicsWorld11UpdatePathsEv+0x58>
 *   @0x238034 mov r0, r4
 *   @0x238038 mov r2, #7
 *   @0x23803c mov r1, r4
 *   @0x238040 mov r3, #8
 *   @0x238044 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii>
 *   @0x238048 cmp r5, #0
 *   @0x23804c bne 0x237ff4 <_ZN13CPhysicsWorld11UpdatePathsEv+0x60>
 *   @0x238050 pop {r3, r4, r5, r6, r7, pc}
 *   @0x238054 mov r0, r4
 *   @0x238058 mov r1, r4
 *   @0x23805c mov r2, #7
 *   @0x238060 mov r3, #8
 *   @0x238064 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii>
 *   @0x238068 b 0x237fc8 <_ZN13CPhysicsWorld11UpdatePathsEv+0x34>
 *   @0x23806c andseq r5, r11, r8, lsl #19
 *
 * ══ §20/159 CPhysicsWorld::AssignCollisionCategory  0x2384bc  size 220  55 条（0x2384bc..0x238598）
 * @func 0x2384bc 0x238598  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsWorld::GetCollisionCategory(int) / Object_Name(int) / 0xb6550 / Error_Show_Action(char const*, bool) / 0xb65d4
 * 字段偏移 top8: 0x404×2 / 0x68×2 / 0xc4×1 / 0x6c×1 / 0x70×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2384bc push {r4, r5, r6, lr}
 *   @0x2384c0 sub sp, sp, #1024
 *   @0x2384c4 ldr r4, [pc, #0xc4]
 *   @0x2384c8 sub sp, sp, #8
 *   @0x2384cc mov r5, r0
 *   @0x2384d0 mov r6, r1
 *   @0x2384d4 ldr r4, [pc, r4]
 *   @0x2384d8 ldr r3, [r4]
 *   @0x2384dc str r3, [sp, #0x404]
 *   @0x2384e0 bl 0x238488 <_ZN13CPhysicsWorld20GetCollisionCategoryEi>
 *   @0x2384e4 cmn r0, #1
 *   @0x2384e8 beq 0x238508 <_ZN13CPhysicsWorld23AssignCollisionCategoryEi+0x4c>
 *   @0x2384ec ldr r2, [sp, #0x404]
 *   @0x2384f0 ldr r3, [r4]
 *   @0x2384f4 cmp r2, r3
 *   @0x2384f8 bne 0x23858c <_ZN13CPhysicsWorld23AssignCollisionCategoryEi+0xd0>
 *   @0x2384fc add sp, sp, #1024
 *   @0x238500 add sp, sp, #8
 *   @0x238504 pop {r4, r5, r6, pc}
 *   @0x238508 mov r2, r5
 *   @0x23850c mov r3, #0
 *   @0x238510 b 0x238524 <_ZN13CPhysicsWorld23AssignCollisionCategoryEi+0x68>
 *   @0x238514 add r3, r3, #1
 *   @0x238518 add r2, r2, #12
 *   @0x23851c cmp r3, #32
 *   @0x238520 beq 0x238558 <_ZN13CPhysicsWorld23AssignCollisionCategoryEi+0x9c>
 *   @0x238524 ldr r12, [r2, #0x68]
 *   @0x238528 cmn r12, #1
 *   @0x23852c bne 0x238514 <_ZN13CPhysicsWorld23AssignCollisionCategoryEi+0x58>
 *   @0x238530 add r1, r3, r3, lsl #1
 *   @0x238534 mov r2, #1
 *   @0x238538 lsl r2, r2, r3
 *   @0x23853c mov r0, r3
 *   @0x238540 add r5, r5, r1, lsl #2
 *   @0x238544 mov r3, #0
 *   @0x238548 str r6, [r5, #0x68]
 *   @0x23854c str r2, [r5, #0x6c]
 *   @0x238550 str r3, [r5, #0x70]
 *   @0x238554 b 0x2384ec <_ZN13CPhysicsWorld23AssignCollisionCategoryEi+0x30>
 *   @0x238558 mov r0, r6
 *   @0x23855c add r5, sp, #4
 *   @0x238560 bl 0x19ed54 <_Z11Object_Namei>
 *   @0x238564 ldr r1, [pc, #0x28]
 *   @0x238568 add r1, pc, r1
 *   @0x23856c mov r2, r0
 *   @0x238570 mov r0, r5
 *   @0x238574 bl 0xb6550 <sprintf@plt>
 *   @0x238578 mov r0, r5
 *   @0x23857c mov r1, #0
 *   @0x238580 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x238584 mvn r0, #0
 *   @0x238588 b 0x2384ec <_ZN13CPhysicsWorld23AssignCollisionCategoryEi+0x30>
 *   @0x23858c bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x238590 andseq r5, r11, r12, ror r4
 *   @0x238594 ldrsbeq r12, [r1], -r12
 *
 * ══ §21/159 JSArrayPut  0x247c68  size 220  55 条（0x247c68..0x247d44）
 * @func 0x247c68 0x247d44  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6574 / JSArrayPut(RValue*, RValue*, RValue*)+0xa8 / SetArrayEntry(YYObjectBase*, unsigned int, RValue*) / YYObjectBase::Add(char const*, void*, int) / YYObjectBase::InternalGetYYVar(int)
 * 字段偏移 top8: 0xc×2 / 0xa4×1 / 0x40×1 / 0x4×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x247c68 cmp r0, #0
 *   @0x247c6c push {r4, r5, r6, r7, r8, lr}
 *   @0x247c70 mov r6, r1
 *   @0x247c74 mov r8, r2
 *   @0x247c78 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x247c7c ldr r3, [r0, #0xc]
 *   @0x247c80 cmp r3, #6
 *   @0x247c84 beq 0x247c90 <_Z10JSArrayPutP6RValueS0_S0_+0x28>
 *   @0x247c88 mov r0, #0
 *   @0x247c8c pop {r4, r5, r6, r7, r8, pc}
 *   @0x247c90 ldr r7, [r0]
 *   @0x247c94 ldr r1, [pc, #0xa4]
 *   @0x247c98 ldr r0, [r7, #0x40]
 *   @0x247c9c add r1, pc, r1
 *   @0x247ca0 bl 0xb6574 <strcmp@plt>
 *   @0x247ca4 cmp r0, #0
 *   @0x247ca8 bne 0x247d10 <_Z10JSArrayPutP6RValueS0_S0_+0xa8>
 *   @0x247cac ldr r3, [r7, #0x4]
 *   @0x247cb0 cmp r3, #0
 *   @0x247cb4 beq 0x247d30 <_Z10JSArrayPutP6RValueS0_S0_+0xc8>
 *   @0x247cb8 add r0, r3, #16
 *   @0x247cbc ldr r2, [r6, #0xc]
 *   @0x247cc0 ldr r7, [r0]
 *   @0x247cc4 cmp r2, #0
 *   @0x247cc8 bne 0x247d10 <_Z10JSArrayPutP6RValueS0_S0_+0xa8>
 *   @0x247ccc ldm r6, {r4, r5}
 *   @0x247cd0 vmov d5, r4, r5
 *   @0x247cd4 vcvt.s32.f64 s13, d5
 *   @0x247cd8 vcvt.f64.s32 d7, s13
 *   @0x247cdc vcmp.f64 d5, d7
 *   @0x247ce0 vmrs APSR_nzcv, fpscr
 *   @0x247ce4 bne 0x247d10 <_Z10JSArrayPutP6RValueS0_S0_+0xa8>
 *   @0x247ce8 vmov r3, s13
 *   @0x247cec cmp r3, #0
 *   @0x247cf0 blt 0x247d10 <_Z10JSArrayPutP6RValueS0_S0_+0xa8>
 *   @0x247cf4 mov r0, r7
 *   @0x247cf8 vmov r1, s13
 *   @0x247cfc mov r2, r8
 *   @0x247d00 bl 0x247904 <_Z13SetArrayEntryP12YYObjectBasejP6RValue>
 *   @0x247d04 cmp r0, #0
 *   @0x247d08 beq 0x247d10 <_Z10JSArrayPutP6RValueS0_S0_+0xa8>
 *   @0x247d0c pop {r4, r5, r6, r7, r8, pc}
 *   @0x247d10 ldr r1, [r6]
 *   @0x247d14 mov r0, r7
 *   @0x247d18 mov r2, r8
 *   @0x247d1c mov r3, #0
 *   @0x247d20 ldr r1, [r1]
 *   @0x247d24 bl 0x199b20 <_ZN12YYObjectBase3AddEPKcPvi>
 *   @0x247d28 mov r0, #0
 *   @0x247d2c pop {r4, r5, r6, r7, r8, pc}
 *   @0x247d30 mov r0, r7
 *   @0x247d34 mov r1, #1
 *   @0x247d38 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x247d3c b 0x247cbc <_Z10JSArrayPutP6RValueS0_S0_+0x54>
 *   @0x247d40 andeq r12, lr, r12, ror r12
 *
 * ══ §22/159 F_JS_Object_Get  0x249240  size 220  55 条（0x249240..0x24931c）
 * @func 0x249240 0x24931c  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYObjectBase::InternalGetYYVar(int)×2 / JS_GetProperty(YYObjectBase*, RValue*, char const*) / JS_IsDataDescriptor(RValue*) / Call_Accessor_Get(YYObjectBase*, RValue*, RValue*)
 * 字段偏移 top8: 0xc×5 / 0x4×4 / 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x249240 push {r4, r5, lr}
 *   @0x249244 mov r4, r1
 *   @0x249248 sub sp, sp, #20
 *   @0x24924c mov r5, r0
 *   @0x249250 bl 0x2418dc <_Z14JS_GetPropertyP12YYObjectBaseP6RValuePKc>
 *   @0x249254 ldr r3, [r4, #0xc]
 *   @0x249258 mvn r2, #-16777216
 *   @0x24925c cmp r3, #5
 *   @0x249260 cmpne r3, r2
 *   @0x249264 bne 0x249270 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc+0x30>
 *   @0x249268 add sp, sp, #20
 *   @0x24926c pop {r4, r5, pc}
 *   @0x249270 mov r0, r4
 *   @0x249274 bl 0x2407e8 <_Z19JS_IsDataDescriptorP6RValue>
 *   @0x249278 cmp r0, #0
 *   @0x24927c bne 0x249268 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc+0x28>
 *   @0x249280 ldr r0, [r4]
 *   @0x249284 ldr r1, [r0, #0x4]
 *   @0x249288 cmp r1, #0
 *   @0x24928c beq 0x249304 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc+0xc4>
 *   @0x249290 ldr r3, [r1, #0xc]
 *   @0x249294 cmp r3, #5
 *   @0x249298 beq 0x2492e8 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc+0xa8>
 *   @0x24929c ldr r0, [r4]
 *   @0x2492a0 ldr r1, [r0, #0x4]
 *   @0x2492a4 cmp r1, #0
 *   @0x2492a8 beq 0x249310 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc+0xd0>
 *   @0x2492ac ldr r2, [r1, #0xc]
 *   @0x2492b0 mvn r3, #-16777216
 *   @0x2492b4 cmp r2, r3
 *   @0x2492b8 beq 0x2492e8 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc+0xa8>
 *   @0x2492bc mov r0, r5
 *   @0x2492c0 mov r2, r4
 *   @0x2492c4 mov r1, sp
 *   @0x2492c8 bl 0x248fec <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_>
 *   @0x2492cc mov r12, sp
 *   @0x2492d0 ldm r12!, {r0, r1, r2, r3}
 *   @0x2492d4 str r0, [r4]
 *   @0x2492d8 str r1, [r4, #0x4]
 *   @0x2492dc str r2, [r4, #0x8]
 *   @0x2492e0 str r3, [r4, #0xc]
 *   @0x2492e4 b 0x249268 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc+0x28>
 *   @0x2492e8 mov r3, #0
 *   @0x2492ec mov r2, #5
 *   @0x2492f0 str r3, [r4]
 *   @0x2492f4 str r3, [r4, #0x4]
 *   @0x2492f8 str r3, [r4, #0x8]
 *   @0x2492fc str r2, [r4, #0xc]
 *   @0x249300 b 0x249268 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc+0x28>
 *   @0x249304 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x249308 mov r1, r0
 *   @0x24930c b 0x249290 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc+0x50>
 *   @0x249310 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x249314 mov r1, r0
 *   @0x249318 b 0x2492ac <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc+0x6c>
 *
 * ══ §23/159 b2DistanceProxy::Set  0x2c3b74  size 220  55 条（0x2c3b74..0x2c3c50）
 * @func 0x2c3b74 0x2c3c64  size 240  60 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×5 / 0x10×5 / 0x8×4 / 0x14×4 / 0x18×4 / 0x-4×1 / 0xc×1 / 0x94×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c3b74 mov r12, r1
 *   @0x2c3b78 ldr r1, [r1, #0x4]
 *   @0x2c3b7c str r4, [sp, #-0x4]!
 *   @0x2c3b80 mov r3, r0
 *   @0x2c3b84 cmp r1, #3
 *   @0x2c3b88 addls pc, pc, r1, lsl #2
 *   @0x2c3b8c b 0x2c3bb8 <_ZN15b2DistanceProxy3SetEPK7b2Shapei+0x44>
 *   @0x2c3b90 b 0x2c3c30 <_ZN15b2DistanceProxy3SetEPK7b2Shapei+0xbc>
 *   @0x2c3b94 b 0x2c3ba0 <_ZN15b2DistanceProxy3SetEPK7b2Shapei+0x2c>
 *   @0x2c3b98 b 0x2c3c10 <_ZN15b2DistanceProxy3SetEPK7b2Shapei+0x9c>
 *   @0x2c3b9c b 0x2c3bc0 <_ZN15b2DistanceProxy3SetEPK7b2Shapei+0x4c>
 *   @0x2c3ba0 ldr r1, [r12, #0x8]
 *   @0x2c3ba4 add r2, r12, #12
 *   @0x2c3ba8 str r2, [r0, #0x10]
 *   @0x2c3bac mov r2, #2
 *   @0x2c3bb0 str r2, [r0, #0x14]
 *   @0x2c3bb4 str r1, [r0, #0x18]
 *   @0x2c3bb8 ldr r4, [sp], #4
 *   @0x2c3bbc bx lr
 *   @0x2c3bc0 ldr r4, [r12, #0xc]
 *   @0x2c3bc4 add r0, r2, #1
 *   @0x2c3bc8 ldr r1, [r12, #0x10]
 *   @0x2c3bcc add r2, r4, r2, lsl #3
 *   @0x2c3bd0 cmp r0, r1
 *   @0x2c3bd4 ldm r2, {r0, r1}
 *   @0x2c3bd8 addge r2, r3, #8
 *   @0x2c3bdc stm r3, {r0, r1}
 *   @0x2c3be0 addlt r1, r2, #8
 *   @0x2c3be4 ldmge r4, {r0, r1}
 *   @0x2c3be8 addlt r2, r3, #8
 *   @0x2c3bec ldmlt r1, {r0, r1}
 *   @0x2c3bf0 ldr r4, [sp], #4
 *   @0x2c3bf4 stm r2, {r0, r1}
 *   @0x2c3bf8 ldr r2, [r12, #0x8]
 *   @0x2c3bfc str r3, [r3, #0x10]
 *   @0x2c3c00 str r2, [r3, #0x18]
 *   @0x2c3c04 mov r2, #2
 *   @0x2c3c08 str r2, [r3, #0x14]
 *   @0x2c3c0c bx lr
 *   @0x2c3c10 ldr r2, [r12, #0x94]
 *   @0x2c3c14 add r1, r12, #20
 *   @0x2c3c18 ldr r0, [r12, #0x8]
 *   @0x2c3c1c ldr r4, [sp], #4
 *   @0x2c3c20 str r1, [r3, #0x10]
 *   @0x2c3c24 str r0, [r3, #0x18]
 *   @0x2c3c28 str r2, [r3, #0x14]
 *   @0x2c3c2c bx lr
 *   @0x2c3c30 ldr r1, [r12, #0x8]
 *   @0x2c3c34 add r2, r12, #12
 *   @0x2c3c38 ldr r4, [sp], #4
 *   @0x2c3c3c str r2, [r0, #0x10]
 *   @0x2c3c40 mov r2, #1
 *   @0x2c3c44 str r1, [r0, #0x18]
 *   @0x2c3c48 str r2, [r0, #0x14]
 *   @0x2c3c4c bx lr
 *
 * ══ §24/159 b2ContactManager::Destroy  0x2c7894  size 220  55 条（0x2c7894..0x2c7970）
 * @func 0x2c7894 0x2c7970  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Contact::Destroy(b2Contact*, b2BlockAllocator*)
 * 字段偏移 top8: 0x8×3 / 0xc×2 / 0x80×2 / 0x40×2 / 0x48×1 / 0x30×1 / 0x34×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c7894 push {r3, r4, r5, r6, r7, lr}
 *   @0x2c7898 mov r5, r0
 *   @0x2c789c ldr r0, [r0, #0x48]
 *   @0x2c78a0 mov r4, r1
 *   @0x2c78a4 ldr r2, [r1, #0x30]
 *   @0x2c78a8 ldr r3, [r1, #0x34]
 *   @0x2c78ac cmp r0, #0
 *   @0x2c78b0 ldr r7, [r2, #0x8]
 *   @0x2c78b4 ldr r6, [r3, #0x8]
 *   @0x2c78b8 beq 0x2c78d4 <_ZN16b2ContactManager7DestroyEP9b2Contact+0x40>
 *   @0x2c78bc ldr r3, [r1, #0x4]
 *   @0x2c78c0 tst r3, #2
 *   @0x2c78c4 beq 0x2c78d4 <_ZN16b2ContactManager7DestroyEP9b2Contact+0x40>
 *   @0x2c78c8 ldr r3, [r0]
 *   @0x2c78cc ldr r3, [r3, #0xc]
 *   @0x2c78d0 blx r3
 *   @0x2c78d4 ldr r3, [r4, #0x8]
 *   @0x2c78d8 mov r0, r4
 *   @0x2c78dc ldr r1, [r7, #0x80]
 *   @0x2c78e0 cmp r3, #0
 *   @0x2c78e4 ldrne r2, [r4, #0xc]
 *   @0x2c78e8 strne r2, [r3, #0xc]
 *   @0x2c78ec ldr r2, [r4, #0xc]
 *   @0x2c78f0 cmp r2, #0
 *   @0x2c78f4 strne r3, [r2, #0x8]
 *   @0x2c78f8 ldr r3, [r5, #0x3c]
 *   @0x2c78fc cmp r3, r4
 *   @0x2c7900 ldr r3, [r4, #0x18]
 *   @0x2c7904 streq r2, [r5, #0x3c]
 *   @0x2c7908 cmp r3, #0
 *   @0x2c790c ldrne r2, [r4, #0x1c]
 *   @0x2c7910 strne r2, [r3, #0xc]
 *   @0x2c7914 ldr r2, [r4, #0x1c]
 *   @0x2c7918 cmp r2, #0
 *   @0x2c791c strne r3, [r2, #0x8]
 *   @0x2c7920 add r3, r4, #16
 *   @0x2c7924 cmp r1, r3
 *   @0x2c7928 ldr r3, [r4, #0x28]
 *   @0x2c792c streq r2, [r7, #0x80]
 *   @0x2c7930 cmp r3, #0
 *   @0x2c7934 ldr r1, [r6, #0x80]
 *   @0x2c7938 ldrne r2, [r4, #0x2c]
 *   @0x2c793c strne r2, [r3, #0xc]
 *   @0x2c7940 ldr r2, [r4, #0x2c]
 *   @0x2c7944 cmp r2, #0
 *   @0x2c7948 strne r3, [r2, #0x8]
 *   @0x2c794c add r3, r4, #32
 *   @0x2c7950 cmp r1, r3
 *   @0x2c7954 ldr r1, [r5, #0x4c]
 *   @0x2c7958 streq r2, [r6, #0x80]
 *   @0x2c795c bl 0x2cc07c <_ZN9b2Contact7DestroyEPS_P16b2BlockAllocator>
 *   @0x2c7960 ldr r3, [r5, #0x40]
 *   @0x2c7964 sub r3, r3, #1
 *   @0x2c7968 str r3, [r5, #0x40]
 *   @0x2c796c pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §25/159 __divsi3  0x318d10  size 220  55 条（0x318d10..0x318dec）
 * @func 0x318d10 0x318dec  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __divsi3+0xa4
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x318d10 cmp r1, #0
 *   @0x318d14 beq 0x318ddc <__divsi3+0xcc>
 *   @0x318d18 eor r12, r0, r1
 *   @0x318d1c rsbmi r1, r1, #0
 *   @0x318d20 subs r2, r1, #1
 *   @0x318d24 beq 0x318da8 <__divsi3+0x98>
 *   @0x318d28 movs r3, r0
 *   @0x318d2c rsbmi r3, r0, #0
 *   @0x318d30 cmp r3, r1
 *   @0x318d34 bls 0x318db4 <__divsi3+0xa4>
 *   @0x318d38 tst r1, r2
 *   @0x318d3c beq 0x318dc4 <__divsi3+0xb4>
 *   @0x318d40 clz r2, r1
 *   @0x318d44 clz r0, r3
 *   @0x318d48 sub r0, r2, r0
 *   @0x318d4c mov r2, #1
 *   @0x318d50 lsl r1, r1, r0
 *   @0x318d54 lsl r2, r2, r0
 *   @0x318d58 mov r0, #0
 *   @0x318d5c cmp r3, r1
 *   @0x318d60 subhs r3, r3, r1
 *   @0x318d64 orrhs r0, r0, r2
 *   @0x318d68 cmp r3, r1, lsr #1
 *   @0x318d6c subhs r3, r3, r1, lsr #1
 *   @0x318d70 orrhs r0, r0, r2, lsr #1
 *   @0x318d74 cmp r3, r1, lsr #2
 *   @0x318d78 subhs r3, r3, r1, lsr #2
 *   @0x318d7c orrhs r0, r0, r2, lsr #2
 *   @0x318d80 cmp r3, r1, lsr #3
 *   @0x318d84 subhs r3, r3, r1, lsr #3
 *   @0x318d88 orrhs r0, r0, r2, lsr #3
 *   @0x318d8c cmp r3, #0
 *   @0x318d90 lsrsne r2, r2, #4
 *   @0x318d94 lsrne r1, r1, #4
 *   @0x318d98 bne 0x318d5c <__divsi3+0x4c>
 *   @0x318d9c cmp r12, #0
 *   @0x318da0 rsbmi r0, r0, #0
 *   @0x318da4 bx lr
 *   @0x318da8 teq r12, r0
 *   @0x318dac rsbmi r0, r0, #0
 *   @0x318db0 bx lr
 *   @0x318db4 movlo r0, #0
 *   @0x318db8 asreq r0, r12, #31
 *   @0x318dbc orreq r0, r0, #1
 *   @0x318dc0 bx lr
 *   @0x318dc4 clz r2, r1
 *   @0x318dc8 rsb r2, r2, #31
 *   @0x318dcc cmp r12, #0
 *   @0x318dd0 lsr r0, r3, r2
 *   @0x318dd4 rsbmi r0, r0, #0
 *   @0x318dd8 bx lr
 *   @0x318ddc cmp r0, #0
 *   @0x318de0 mvngt r0, #-2147483648
 *   @0x318de4 movlt r0, #-2147483648
 *   @0x318de8 b 0x319458 <__aeabi_ldiv0>
 *
 * ══ §26/159 LoadSave::_GetSaveFileName  0x18f964  size 216  54 条（0x18f964..0x18fa3c）
 * @func 0x18f964 0x18fa50  size 236  59 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65a4×3 / 0xb6538×2 / 0xb6628×2 / GetSavePrePend() / 0xb65e0
 * 字段偏移 top8: 0xac×1 / 0x1×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18f964 push {r4, r5, r6, r7, r8, lr}
 *   @0x18f968 mov r4, r2
 *   @0x18f96c mov r5, r0
 *   @0x18f970 bl 0x28fd6c <_Z14GetSavePrePendv>
 *   @0x18f974 cmp r4, #0
 *   @0x18f978 strbeq r4, [r5]
 *   @0x18f97c mov r8, r0
 *   @0x18f980 beq 0x18f9d8 <_ZN8LoadSave16_GetSaveFileNameEPciPKc+0x74>
 *   @0x18f984 ldr r6, [pc, #0xac]
 *   @0x18f988 ldr r6, [pc, r6]
 *   @0x18f98c ldr r7, [r6]
 *   @0x18f990 mov r0, r7
 *   @0x18f994 bl 0xb6538 <strlen@plt>
 *   @0x18f998 mov r1, r7
 *   @0x18f99c mov r2, r0
 *   @0x18f9a0 mov r0, r4
 *   @0x18f9a4 bl 0xb65e0 <strncmp@plt>
 *   @0x18f9a8 cmp r0, #0
 *   @0x18f9ac beq 0x18fa14 <_ZN8LoadSave16_GetSaveFileNameEPciPKc+0xb0>
 *   @0x18f9b0 ldrb r3, [r4]
 *   @0x18f9b4 cmp r3, #47
 *   @0x18f9b8 cmpne r3, #92
 *   @0x18f9bc beq 0x18fa04 <_ZN8LoadSave16_GetSaveFileNameEPciPKc+0xa0>
 *   @0x18f9c0 mov r1, r8
 *   @0x18f9c4 mov r0, r5
 *   @0x18f9c8 bl 0xb65a4 <strcpy@plt>
 *   @0x18f9cc mov r0, r5
 *   @0x18f9d0 mov r1, r4
 *   @0x18f9d4 bl 0xb6628 <strcat@plt>
 *   @0x18f9d8 ldrb r3, [r5]
 *   @0x18f9dc cmp r3, #0
 *   @0x18f9e0 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x18f9e4 add r0, r5, #1
 *   @0x18f9e8 mov r2, #47
 *   @0x18f9ec cmp r3, #92
 *   @0x18f9f0 strbeq r2, [r0, #-0x1]
 *   @0x18f9f4 ldrb r3, [r0], #1
 *   @0x18f9f8 cmp r3, #0
 *   @0x18f9fc bne 0x18f9ec <_ZN8LoadSave16_GetSaveFileNameEPciPKc+0x88>
 *   @0x18fa00 pop {r4, r5, r6, r7, r8, pc}
 *   @0x18fa04 mov r1, r4
 *   @0x18fa08 mov r0, r5
 *   @0x18fa0c bl 0xb65a4 <strcpy@plt>
 *   @0x18fa10 b 0x18f9d8 <_ZN8LoadSave16_GetSaveFileNameEPciPKc+0x74>
 *   @0x18fa14 mov r1, r8
 *   @0x18fa18 mov r0, r5
 *   @0x18fa1c bl 0xb65a4 <strcpy@plt>
 *   @0x18fa20 ldr r0, [r6]
 *   @0x18fa24 bl 0xb6538 <strlen@plt>
 *   @0x18fa28 add r1, r4, r0
 *   @0x18fa2c mov r0, r5
 *   @0x18fa30 bl 0xb6628 <strcat@plt>
 *   @0x18fa34 b 0x18f9d8 <_ZN8LoadSave16_GetSaveFileNameEPciPKc+0x74>
 *   @0x18fa38 .word 0x00260cd0
 *
 * ══ §27/159 CInstance::~CInstance  0x199320  size 216  54 条（0x199320..0x1993f8）
 * @func 0x199320 0x1993f8  size 216  54 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)×2 / CPhysicsObject::~CPhysicsObject() / CObjectGM::RemoveInstance(CInstance*) / CSkeletonInstance::~CSkeletonInstance() / CollisionRemove(CInstance*) / YYObjectBase::~YYObjectBase()
 * 字段偏移 top8: 0x84×2 / 0x80×2 / 0x88×2 / 0x44×2 / 0x8×2 / 0xbc×1 / 0x50×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x199320 push {r4, r5, r6, lr}
 *   @0x199324 mov r4, r0
 *   @0x199328 ldr r5, [r0, #0x84]
 *   @0x19932c ldr r3, [pc, #0xbc]
 *   @0x199330 cmp r5, #0
 *   @0x199334 ldr r3, [pc, r3]
 *   @0x199338 add r3, r3, #8
 *   @0x19933c str r3, [r0]
 *   @0x199340 beq 0x19935c <_ZN9CInstanceD2Ev+0x3c>
 *   @0x199344 mov r0, r5
 *   @0x199348 bl 0x236c60 <_ZN14CPhysicsObjectD2Ev>
 *   @0x19934c mov r0, r5
 *   @0x199350 bl 0x27d1d0 <_ZdlPv>
 *   @0x199354 mov r3, #0
 *   @0x199358 str r3, [r4, #0x84]
 *   @0x19935c ldr r0, [r4, #0x80]
 *   @0x199360 cmp r0, #0
 *   @0x199364 beq 0x199378 <_ZN9CInstanceD2Ev+0x58>
 *   @0x199368 mov r1, r4
 *   @0x19936c bl 0x19e0fc <_ZN9CObjectGM14RemoveInstanceEP9CInstance>
 *   @0x199370 mov r3, #0
 *   @0x199374 str r3, [r4, #0x80]
 *   @0x199378 ldr r5, [r4, #0x88]
 *   @0x19937c cmp r5, #0
 *   @0x199380 beq 0x19939c <_ZN9CInstanceD2Ev+0x7c>
 *   @0x199384 mov r0, r5
 *   @0x199388 bl 0xbe194 <_ZN17CSkeletonInstanceD2Ev>
 *   @0x19938c mov r0, r5
 *   @0x199390 bl 0x27d1d0 <_ZdlPv>
 *   @0x199394 mov r3, #0
 *   @0x199398 str r3, [r4, #0x88]
 *   @0x19939c ldr r3, [pc, #0x50]
 *   @0x1993a0 mvn lr, #0
 *   @0x1993a4 ldr r2, [r4, #0x44]
 *   @0x1993a8 mov r0, r4
 *   @0x1993ac ldr r3, [pc, r3]
 *   @0x1993b0 mov r6, #0
 *   @0x1993b4 ldr r5, [r3]
 *   @0x1993b8 ldr r12, [r3, #0xc]
 *   @0x1993bc ldr r1, [r3, #0x8]
 *   @0x1993c0 str r6, [r5, r2, lsl #2]
 *   @0x1993c4 str lr, [r4, #0x44]
 *   @0x1993c8 add r1, r1, lr
 *   @0x1993cc cmp r12, r2
 *   @0x1993d0 strle r12, [r3, #0xc]
 *   @0x1993d4 strgt r2, [r3, #0xc]
 *   @0x1993d8 str r1, [r3, #0x8]
 *   @0x1993dc bl 0x1cd9f0 <_Z15CollisionRemoveP9CInstance>
 *   @0x1993e0 mov r0, r4
 *   @0x1993e4 bl 0x199110 <_ZN12YYObjectBaseD2Ev>
 *   @0x1993e8 mov r0, r4
 *   @0x1993ec pop {r4, r5, r6, pc}
 *   @0x1993f0 eoreq r7, r5, r8, asr r3
 *   @0x1993f4 .word 0x002548b8
 *
 * ══ §28/159 ParticleSystem_UpdateAll  0x1a4fbc  size 216  54 条（0x1a4fbc..0x1a5094）
 * @func 0x1a4fbc 0x1a5094  size 216  54 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1a4fc4→0x757e7c, 0x1a4fdc→0x54245c, 0x1a5010→0x542460, 0x1a5058→0x757e80, 0x1a5068→0x757e80
 * 调用序列: ParticleSystem_UpdateAll()+0x90 / ParticleSystem_Exists(int) / ParticleSystem_Update(int) / CProfiler::Push(int, int)
 * 字段偏移 top8: 0xb8×2 / 0xa4×1 / 0x74×1 / 0x4×1 / 0x2×1 / 0x28×1 / 0x30×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a4fbc push {r3, r4, r5, r6, r7, lr}
 *   @0x1a4fc0 ldr r6, [pc, #0xb8]
 *   @0x1a4fc4 ldr r3, [pc, #0xb8]
 *   @0x1a4fc8 add r6, pc, r6
 *   @0x1a4fcc ldr r7, [r6, r3]
 *   @0x1a4fd0 ldrb r3, [r7]
 *   @0x1a4fd4 cmp r3, #0
 *   @0x1a4fd8 bne 0x1a5068 <_Z24ParticleSystem_UpdateAllv+0xac>
 *   @0x1a4fdc ldr r3, [pc, #0xa4]
 *   @0x1a4fe0 ldr r5, [r6, r3]
 *   @0x1a4fe4 ldr r3, [r5]
 *   @0x1a4fe8 cmp r3, #0
 *   @0x1a4fec movgt r4, #0
 *   @0x1a4ff0 bgt 0x1a5008 <_Z24ParticleSystem_UpdateAllv+0x4c>
 *   @0x1a4ff4 b 0x1a504c <_Z24ParticleSystem_UpdateAllv+0x90>
 *   @0x1a4ff8 ldr r3, [r5]
 *   @0x1a4ffc add r4, r4, #1
 *   @0x1a5000 cmp r3, r4
 *   @0x1a5004 ble 0x1a504c <_Z24ParticleSystem_UpdateAllv+0x90>
 *   @0x1a5008 mov r0, r4
 *   @0x1a500c bl 0x1a3770 <_Z21ParticleSystem_Existsi>
 *   @0x1a5010 ldr r3, [pc, #0x74]
 *   @0x1a5014 cmp r0, #0
 *   @0x1a5018 beq 0x1a4ff8 <_Z24ParticleSystem_UpdateAllv+0x3c>
 *   @0x1a501c ldr r3, [r6, r3]
 *   @0x1a5020 ldr r3, [r3, #0x4]
 *   @0x1a5024 ldr r3, [r3, r4, lsl #2]
 *   @0x1a5028 ldrb r3, [r3, #0x28]
 *   @0x1a502c cmp r3, #0
 *   @0x1a5030 beq 0x1a4ff8 <_Z24ParticleSystem_UpdateAllv+0x3c>
 *   @0x1a5034 mov r0, r4
 *   @0x1a5038 add r4, r4, #1
 *   @0x1a503c bl 0x1a4f18 <_Z21ParticleSystem_Updatei>
 *   @0x1a5040 ldr r3, [r5]
 *   @0x1a5044 cmp r3, r4
 *   @0x1a5048 bgt 0x1a5008 <_Z24ParticleSystem_UpdateAllv+0x4c>
 *   @0x1a504c ldrb r3, [r7]
 *   @0x1a5050 cmp r3, #0
 *   @0x1a5054 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1a5058 ldr r3, [pc, #0x30]
 *   @0x1a505c ldr r0, [r6, r3]
 *   @0x1a5060 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1a5064 b 0x2a08ac <_ZN9CProfiler3PopEv>
 *   @0x1a5068 ldr r3, [pc, #0x20]
 *   @0x1a506c mov r1, #6
 *   @0x1a5070 mov r2, #11
 *   @0x1a5074 ldr r0, [r6, r3]
 *   @0x1a5078 bl 0x2a0738 <_ZN9CProfiler4PushEii>
 *   @0x1a507c b 0x1a4fdc <_Z24ParticleSystem_UpdateAllv+0x20>
 *   @0x1a5080 eoreq r12, r4, r8, lsl #25
 *   @0x1a5084 .word 0xffffbf18
 *   @0x1a5088 .word 0xffffeb64
 *   @0x1a508c .word 0xffffeb68
 *   @0x1a5090 .word 0xffffbf1c
 *
 * ══ §29/159 Variable_Global_GetVar  0x1f3984  size 216  54 条（0x1f3984..0x1f3a5c）
 * @func 0x1f3984 0x1f3a70  size 236  59 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GET_RValue(RValue*, RValue*, int) / Code_Variable_Find_Name(char const*, int, int) / Code_Function_Find(char const*, int*) / Code_Function_GET_the_function(int, char const**, void**, int*, int*) / YYSetScriptRef(RValue*) / YYObjectBase::InternalGetYYVar(int)
 * 字段偏移 top8: 0xc×2 / 0xcc×1 / 0x24×1 / 0x4×1 / 0x14×1 / 0x68×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f3984 ldr r3, [pc, #0xcc]
 *   @0x1f3988 push {r4, r5, r6, r7, lr}
 *   @0x1f398c ldr r3, [pc, r3]
 *   @0x1f3990 mov r5, r0
 *   @0x1f3994 sub sp, sp, #36
 *   @0x1f3998 ldr r0, [r3]
 *   @0x1f399c mov r7, r1
 *   @0x1f39a0 mov r4, r2
 *   @0x1f39a4 ldr r12, [r0, #0x24]
 *   @0x1f39a8 cmp r12, #0
 *   @0x1f39ac beq 0x1f39e8 <_Z22Variable_Global_GetVariiP6RValue+0x64>
 *   @0x1f39b0 ldr r12, [r0, #0x4]
 *   @0x1f39b4 sub r1, r5, #99328
 *   @0x1f39b8 sub r1, r1, #672
 *   @0x1f39bc cmp r12, #0
 *   @0x1f39c0 beq 0x1f3a4c <_Z22Variable_Global_GetVariiP6RValue+0xc8>
 *   @0x1f39c4 add r1, r12, r1, lsl #4
 *   @0x1f39c8 mov r2, r7
 *   @0x1f39cc mov r0, r4
 *   @0x1f39d0 bl 0xd13bc <_Z10GET_RValueP6RValueS0_i>
 *   @0x1f39d4 ldr r2, [r4, #0xc]
 *   @0x1f39d8 mvn r3, #-16777216
 *   @0x1f39dc cmp r2, r3
 *   @0x1f39e0 mov r6, r0
 *   @0x1f39e4 beq 0x1f39f4 <_Z22Variable_Global_GetVariiP6RValue+0x70>
 *   @0x1f39e8 mov r0, r6
 *   @0x1f39ec add sp, sp, #36
 *   @0x1f39f0 pop {r4, r5, r6, r7, pc}
 *   @0x1f39f4 mov r2, r5
 *   @0x1f39f8 mvn r1, #4
 *   @0x1f39fc mov r0, #0
 *   @0x1f3a00 bl 0xd25fc <_Z23Code_Variable_Find_NamePKcii>
 *   @0x1f3a04 add r1, sp, #12
 *   @0x1f3a08 bl 0xce158 <_Z18Code_Function_FindPKcPi>
 *   @0x1f3a0c cmp r0, #0
 *   @0x1f3a10 beq 0x1f39e8 <_Z22Variable_Global_GetVariiP6RValue+0x64>
 *   @0x1f3a14 add r2, sp, #20
 *   @0x1f3a18 ldr r0, [sp, #0xc]
 *   @0x1f3a1c add r1, sp, #16
 *   @0x1f3a20 add r3, sp, #28
 *   @0x1f3a24 str r3, [sp]
 *   @0x1f3a28 add r3, sp, #24
 *   @0x1f3a2c bl 0xcdf0c <_Z30Code_Function_GET_the_functioniPPKcPPvPiS4_>
 *   @0x1f3a30 mov r0, r4
 *   @0x1f3a34 bl 0xdc3b0 <_Z14YYSetScriptRefP6RValue>
 *   @0x1f3a38 ldr r3, [r4]
 *   @0x1f3a3c ldr r2, [sp, #0x14]
 *   @0x1f3a40 mov r6, #1
 *   @0x1f3a44 str r2, [r3, #0x68]
 *   @0x1f3a48 b 0x1f39e8 <_Z22Variable_Global_GetVariiP6RValue+0x64>
 *   @0x1f3a4c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x1f3a50 mov r1, r0
 *   @0x1f3a54 b 0x1f39c8 <_Z22Variable_Global_GetVariiP6RValue+0x44>
 *   @0x1f3a58 andseq r10, pc, r8, lsr #4
 *
 * ══ §30/159 DsQueueEnqueuePtr  0x2054a4  size 216  54 条（0x2054a4..0x20557c）
 * @func 0x2054a4 0x20557c  size 216  54 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DsQueueEnqueuePtr(int, int, ...)+0xc8×2 / F_DsQueueEnqueue(RValue&, CInstance*, CInstance*, int, RValue*)
 * 字段偏移 top8: 0x3c×2 / 0xc×2 / 0x64×1 / 0x10×1 / 0x28×1 / 0x38×1 / 0x2c×1 / 0x8×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2054a4 push {r1, r2, r3}
 *   @0x2054a8 cmp r0, #0
 *   @0x2054ac push {r4, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2054b0 sub sp, sp, #68
 *   @0x2054b4 ldr r7, [sp, #0x64]
 *   @0x2054b8 blt 0x20556c <_Z17DsQueueEnqueuePtriiz+0xc8>
 *   @0x2054bc vmov s13, r0
 *   @0x2054c0 cmp r7, #0
 *   @0x2054c4 mov r12, #0
 *   @0x2054c8 mov r2, #0
 *   @0x2054cc vcvt.f64.s32 d7, s13
 *   @0x2054d0 mov r3, #0
 *   @0x2054d4 mvn r1, #-16777216
 *   @0x2054d8 add r6, sp, #104
 *   @0x2054dc str r12, [sp, #0x10]
 *   @0x2054e0 str r12, [sp, #0x28]
 *   @0x2054e4 str r12, [sp, #0x38]
 *   @0x2054e8 str r12, [sp, #0x2c]
 *   @0x2054ec strd r2, r3, [sp, #48]
 *   @0x2054f0 vstr d7, [sp, #32]
 *   @0x2054f4 str r1, [sp, #0x3c]
 *   @0x2054f8 str r6, [sp, #0xc]
 *   @0x2054fc ble 0x20556c <_Z17DsQueueEnqueuePtriiz+0xc8>
 *   @0x205500 add r10, sp, #16
 *   @0x205504 add r9, sp, #32
 *   @0x205508 mov r4, r12
 *   @0x20550c mov r8, r12
 *   @0x205510 mov r11, #3
 *   @0x205514 add r6, r6, #7
 *   @0x205518 mov r1, #0
 *   @0x20551c bic lr, r6, #7
 *   @0x205520 mov r0, r10
 *   @0x205524 mov r2, r1
 *   @0x205528 mov r3, #2
 *   @0x20552c mov r6, lr
 *   @0x205530 ldr lr, [lr, #0x8]
 *   @0x205534 mov r12, r6
 *   @0x205538 add r4, r4, #1
 *   @0x20553c vldr d7, [r12]
 *   @0x205540 str r9, [sp]
 *   @0x205544 cmp lr, r1
 *   @0x205548 str r8, [sp, #0x3c]
 *   @0x20554c vstr d7, [sp, #48]
 *   @0x205550 strne r11, [sp, #0x3c]
 *   @0x205554 strne lr, [sp, #0x30]
 *   @0x205558 add r6, r6, #12
 *   @0x20555c str r6, [sp, #0xc]
 *   @0x205560 bl 0xfc048 <_Z16F_DsQueueEnqueueR6RValueP9CInstanceS2_iPS_>
 *   @0x205564 cmp r4, r7
 *   @0x205568 bne 0x205514 <_Z17DsQueueEnqueuePtriiz+0x70>
 *   @0x20556c add sp, sp, #68
 *   @0x205570 pop {r4, r6, r7, r8, r9, r10, r11, lr}
 *   @0x205574 add sp, sp, #12
 *   @0x205578 bx lr
 *
 * ══ §31/159 Color_MergeRGB  0x20fee0  size 216  54 条（0x20fee0..0x20ffb8）
 * @func 0x20fee0 0x20ffb8  size 216  54 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8×3
 * 字段偏移 top8: 0x4×2 / 0x1×1 / 0x5×1
 * VFP 指令 29 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20fee0 ubfx r3, r1, #0x10, #0x8
 *   @0x20fee4 push {r4, r5, lr}
 *   @0x20fee8 vpush {d8}
 *   @0x20feec vmov s15, r3
 *   @0x20fef0 vmov.f32 s17, #1.000000e+00
 *   @0x20fef4 ubfx r3, r0, #0x10, #0x8
 *   @0x20fef8 vmov s16, r2
 *   @0x20fefc sub sp, sp, #20
 *   @0x20ff00 vmov s14, r3
 *   @0x20ff04 str r0, [sp, #0x4]
 *   @0x20ff08 str r1, [sp]
 *   @0x20ff0c vcvt.f32.s32 s15, s15
 *   @0x20ff10 vmul.f32 s15, s15, s16
 *   @0x20ff14 vsub.f32 s17, s17, s16
 *   @0x20ff18 vcvt.f32.s32 s14, s14
 *   @0x20ff1c vmla.f32 s15, s14, s17
 *   @0x20ff20 vcvt.f64.f32 d6, s15
 *   @0x20ff24 vmov r0, r1, d6
 *   @0x20ff28 bl 0xb66e8 <lrint@plt>
 *   @0x20ff2c ldrb r3, [sp, #0x1]
 *   @0x20ff30 vmov s15, r3
 *   @0x20ff34 ldrb r3, [sp, #0x5]
 *   @0x20ff38 vcvt.f32.s32 s15, s15
 *   @0x20ff3c vmov s14, r3
 *   @0x20ff40 vmul.f32 s15, s15, s16
 *   @0x20ff44 vcvt.f32.s32 s14, s14
 *   @0x20ff48 vmla.f32 s15, s14, s17
 *   @0x20ff4c mov r4, r0
 *   @0x20ff50 uxtb r4, r4
 *   @0x20ff54 vcvt.f64.f32 d6, s15
 *   @0x20ff58 vmov r0, r1, d6
 *   @0x20ff5c bl 0xb66e8 <lrint@plt>
 *   @0x20ff60 ldrb r3, [sp]
 *   @0x20ff64 vmov s14, r3
 *   @0x20ff68 ldrb r3, [sp, #0x4]
 *   @0x20ff6c vcvt.f32.s32 s14, s14
 *   @0x20ff70 vmov s15, r3
 *   @0x20ff74 vmul.f32 s16, s14, s16
 *   @0x20ff78 vcvt.f32.s32 s15, s15
 *   @0x20ff7c vmla.f32 s16, s15, s17
 *   @0x20ff80 mov r5, r0
 *   @0x20ff84 uxtb r5, r5
 *   @0x20ff88 vcvt.f64.f32 d6, s16
 *   @0x20ff8c vmov r0, r1, d6
 *   @0x20ff90 bl 0xb66e8 <lrint@plt>
 *   @0x20ff94 mov r3, #0
 *   @0x20ff98 uxtb r0, r0
 *   @0x20ff9c bfi r3, r0, #0, #8
 *   @0x20ffa0 bfi r3, r5, #8, #8
 *   @0x20ffa4 bfi r3, r4, #16, #8
 *   @0x20ffa8 mov r0, r3
 *   @0x20ffac add sp, sp, #20
 *   @0x20ffb0 vpop {d8}
 *   @0x20ffb4 pop {r4, r5, pc}
 *
 * ══ §32/159 CPhysicsWorld::TransferPhysicalPositions  0x23812c  size 216  54 条（0x23812c..0x238204）
 * @func 0x23812c 0x238204  size 216  54 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsWorld::ApplyVisualOffset(float, b2Vec2 const&, b2Vec2&) / CInstance::SetImageAngle(float) / CollisionMarkDirty(CInstance*)
 * 字段偏移 top8: 0x10×1 / 0xa4×1 / 0x84×1 / 0x48×1 / 0x64×1 / 0x70×1
 * VFP 指令 19 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23812c push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x238130 vpush {d8, d9}
 *   @0x238134 vmov.f32 s16, #1.000000e+00
 *   @0x238138 vldr s15, [r0, #96]
 *   @0x23813c ldr r2, [r0, #0x10]
 *   @0x238140 movw r3, #0x9228
 *   @0x238144 movt r3, #0x1
 *   @0x238148 sub sp, sp, #20
 *   @0x23814c mov r8, r0
 *   @0x238150 ldr r4, [r2, r3]
 *   @0x238154 cmp r4, #0
 *   @0x238158 vdiv.f32 s16, s16, s15
 *   @0x23815c beq 0x2381f0 <_ZN13CPhysicsWorld25TransferPhysicalPositionsEv+0xc4>
 *   @0x238160 add r6, sp, #8
 *   @0x238164 mov r9, #1
 *   @0x238168 vldr s18, [pc, #140]
 *   @0x23816c vldr s17, [pc, #140]
 *   @0x238170 ldr r5, [r4, #0xa4]
 *   @0x238174 mov r2, r6
 *   @0x238178 mov r3, sp
 *   @0x23817c cmp r5, #0
 *   @0x238180 beq 0x2381e4 <_ZN13CPhysicsWorld25TransferPhysicalPositionsEv+0xb8>
 *   @0x238184 ldr r12, [r5, #0x84]
 *   @0x238188 ldr lr, [r4, #0x48]
 *   @0x23818c ldmib r12, {r0, r1}
 *   @0x238190 stm r6, {r0, r1}
 *   @0x238194 mov r1, lr
 *   @0x238198 mov r0, r8
 *   @0x23819c bl 0x2380b4 <_ZN13CPhysicsWorld17ApplyVisualOffsetEfRK6b2Vec2RS0_>
 *   @0x2381a0 vldr s13, [r4, #12]
 *   @0x2381a4 vldr s14, [sp]
 *   @0x2381a8 vldr s15, [sp, #4]
 *   @0x2381ac mov r0, r5
 *   @0x2381b0 vmla.f32 s14, s16, s13
 *   @0x2381b4 vstr s14, [r5, #180]
 *   @0x2381b8 vldr s14, [r4, #16]
 *   @0x2381bc vmla.f32 s15, s16, s14
 *   @0x2381c0 vstr s15, [r5, #184]
 *   @0x2381c4 vldr s15, [r4, #72]
 *   @0x2381c8 vnmul.f32 s15, s15, s18
 *   @0x2381cc vdiv.f32 s15, s15, s17
 *   @0x2381d0 vmov r1, s15
 *   @0x2381d4 bl 0x19303c <_ZN9CInstance13SetImageAngleEf>
 *   @0x2381d8 strb r9, [r5, #0x64]
 *   @0x2381dc mov r0, r5
 *   @0x2381e0 bl 0x1cc1d0 <_Z18CollisionMarkDirtyP9CInstance>
 *   @0x2381e4 ldr r4, [r4, #0x70]
 *   @0x2381e8 cmp r4, #0
 *   @0x2381ec bne 0x238170 <_ZN13CPhysicsWorld25TransferPhysicalPositionsEv+0x44>
 *   @0x2381f0 add sp, sp, #20
 *   @0x2381f4 vpop {d8, d9}
 *   @0x2381f8 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x2381fc teqmi r4, #0
 *   @0x238200 ldrdmi r0, r1, [r9], #-251
 *
 * ══ §33/159 spTransformConstraint_create  0x28f01c  size 216  54 条（0x28f01c..0x28f0f4）
 * @func 0x28f01c 0x28f0f4  size 216  54 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spSkeleton_findBone×2 / _calloc / _malloc / spTransformConstraint_create+0xb4
 * 字段偏移 top8: 0x4×6 / 0x8×3 / 0x10×2 / 0x14×2 / 0x18×2 / 0x1c×2 / 0x2×2 / 0xc×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28f01c push {r3, r4, r5, r6, r7, lr}
 *   @0x28f020 mov r4, r0
 *   @0x28f024 ldr r6, [pc, #0xc4]
 *   @0x28f028 mov r3, #38
 *   @0x28f02c mov r7, r1
 *   @0x28f030 mov r0, #1
 *   @0x28f034 add r6, pc, r6
 *   @0x28f038 mov r1, #32
 *   @0x28f03c mov r2, r6
 *   @0x28f040 bl 0x285c4c <_calloc>
 *   @0x28f044 ldr r2, [r4, #0x10]
 *   @0x28f048 ldr r3, [r4, #0x14]
 *   @0x28f04c mov r1, r6
 *   @0x28f050 mov r5, r0
 *   @0x28f054 ldr r0, [r4, #0x4]
 *   @0x28f058 str r2, [r5, #0x10]
 *   @0x28f05c str r3, [r5, #0x14]
 *   @0x28f060 ldr r2, [r4, #0x18]
 *   @0x28f064 ldr r3, [r4, #0x1c]
 *   @0x28f068 str r4, [r5]
 *   @0x28f06c str r2, [r5, #0x18]
 *   @0x28f070 mov r2, #45
 *   @0x28f074 str r3, [r5, #0x1c]
 *   @0x28f078 str r0, [r5, #0x4]
 *   @0x28f07c lsl r0, r0, #2
 *   @0x28f080 bl 0x285c10 <_malloc>
 *   @0x28f084 ldr r3, [r5, #0x4]
 *   @0x28f088 cmp r3, #0
 *   @0x28f08c str r0, [r5, #0x8]
 *   @0x28f090 ble 0x28f0d0 <spTransformConstraint_create+0xb4>
 *   @0x28f094 mov r6, r0
 *   @0x28f098 mov r4, #0
 *   @0x28f09c b 0x28f0a4 <spTransformConstraint_create+0x88>
 *   @0x28f0a0 ldr r6, [r5, #0x8]
 *   @0x28f0a4 ldr r3, [r5]
 *   @0x28f0a8 mov r0, r7
 *   @0x28f0ac ldr r3, [r3, #0x8]
 *   @0x28f0b0 ldr r3, [r3, r4, lsl #2]
 *   @0x28f0b4 ldr r1, [r3, #0x4]
 *   @0x28f0b8 bl 0x28a0c8 <spSkeleton_findBone>
 *   @0x28f0bc ldr r3, [r5, #0x4]
 *   @0x28f0c0 str r0, [r6, r4, lsl #2]
 *   @0x28f0c4 add r4, r4, #1
 *   @0x28f0c8 cmp r3, r4
 *   @0x28f0cc bgt 0x28f0a0 <spTransformConstraint_create+0x84>
 *   @0x28f0d0 ldr r3, [r5]
 *   @0x28f0d4 mov r0, r7
 *   @0x28f0d8 ldr r3, [r3, #0xc]
 *   @0x28f0dc ldr r1, [r3, #0x4]
 *   @0x28f0e0 bl 0x28a0c8 <spSkeleton_findBone>
 *   @0x28f0e4 str r0, [r5, #0xc]
 *   @0x28f0e8 mov r0, r5
 *   @0x28f0ec pop {r3, r4, r5, r6, r7, pc}
 *   @0x28f0f0 strdeq r8, r9, [r12], -r4
 *
 * ══ §34/159 ProcessNetworking  0x29a764  size 216  54 条（0x29a764..0x29a83c）
 * @func 0x29a764 0x29a83c  size 216  54 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: yyServer::Process() / yySocket::Process() / yySocket::ProcessUDP() / yySocket::ReadAndProcessDataStream(yyServer*)
 * 字段偏移 top8: 0x-4×2 / 0xc8×1 / 0x-8×1 / 0x50×1 / 0x-7×1 / 0x2d×1 / 0x2f×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29a764 push {r3, r4, r5, lr}
 *   @0x29a768 ldr r5, [pc, #0xc8]
 *   @0x29a76c ldr r5, [pc, r5]
 *   @0x29a770 add r4, r5, #8
 *   @0x29a774 add r5, r5, #776
 *   @0x29a778 b 0x29a78c <_Z17ProcessNetworkingv+0x28>
 *   @0x29a77c bl 0x297f98 <_ZN8yyServer7ProcessEv>
 *   @0x29a780 add r4, r4, #12
 *   @0x29a784 cmp r4, r5
 *   @0x29a788 beq 0x29a824 <_Z17ProcessNetworkingv+0xc0>
 *   @0x29a78c ldrb r3, [r4, #-0x8]
 *   @0x29a790 cmp r3, #0
 *   @0x29a794 beq 0x29a780 <_Z17ProcessNetworkingv+0x1c>
 *   @0x29a798 ldr r0, [r4, #-0x4]
 *   @0x29a79c cmp r0, #0
 *   @0x29a7a0 beq 0x29a7a8 <_Z17ProcessNetworkingv+0x44>
 *   @0x29a7a4 bl 0x294d28 <_ZN8yySocket7ProcessEv>
 *   @0x29a7a8 ldr r0, [r4]
 *   @0x29a7ac cmp r0, #0
 *   @0x29a7b0 bne 0x29a77c <_Z17ProcessNetworkingv+0x18>
 *   @0x29a7b4 ldr r0, [r4, #-0x4]
 *   @0x29a7b8 cmp r0, #0
 *   @0x29a7bc beq 0x29a780 <_Z17ProcessNetworkingv+0x1c>
 *   @0x29a7c0 ldr r3, [r0, #0x50]
 *   @0x29a7c4 cmp r3, #0
 *   @0x29a7c8 beq 0x29a780 <_Z17ProcessNetworkingv+0x1c>
 *   @0x29a7cc ldrb r3, [r4, #-0x7]
 *   @0x29a7d0 cmp r3, #0
 *   @0x29a7d4 bne 0x29a780 <_Z17ProcessNetworkingv+0x1c>
 *   @0x29a7d8 ldrb r3, [r0, #0x2d]
 *   @0x29a7dc cmp r3, #0
 *   @0x29a7e0 bne 0x29a780 <_Z17ProcessNetworkingv+0x1c>
 *   @0x29a7e4 ldrb r3, [r0, #0x2f]
 *   @0x29a7e8 cmp r3, #0
 *   @0x29a7ec bne 0x29a780 <_Z17ProcessNetworkingv+0x1c>
 *   @0x29a7f0 ldr r3, [r0, #0x8]
 *   @0x29a7f4 cmp r3, #0
 *   @0x29a7f8 beq 0x29a82c <_Z17ProcessNetworkingv+0xc8>
 *   @0x29a7fc cmp r3, #3
 *   @0x29a800 beq 0x29a82c <_Z17ProcessNetworkingv+0xc8>
 *   @0x29a804 cmp r3, #1
 *   @0x29a808 beq 0x29a814 <_Z17ProcessNetworkingv+0xb0>
 *   @0x29a80c cmp r3, #4
 *   @0x29a810 bne 0x29a780 <_Z17ProcessNetworkingv+0x1c>
 *   @0x29a814 add r4, r4, #12
 *   @0x29a818 bl 0x296cb8 <_ZN8yySocket10ProcessUDPEv>
 *   @0x29a81c cmp r4, r5
 *   @0x29a820 bne 0x29a78c <_Z17ProcessNetworkingv+0x28>
 *   @0x29a824 pop {r3, r4, r5, lr}
 *   @0x29a828 b 0x29a5c8 <_Z8RelyTickv>
 *   @0x29a82c mov r1, #0
 *   @0x29a830 bl 0x296e1c <_ZN8yySocket24ReadAndProcessDataStreamEP8yyServer>
 *   @0x29a834 b 0x29a780 <_Z17ProcessNetworkingv+0x1c>
 *   @0x29a838 andseq r7, r5, r8, lsr r2
 *
 * ══ §35/159 GR_3D_Light_Process  0x17fa9c  size 212  53 条（0x17fa9c..0x17fb70）
 * @func 0x17fa9c 0x17fb70  size 212  53 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x17faa8→0x3f26dc, 0x17fac8→0x479c44, 0x17fae4→0x479bf8, 0x17faf8→0x3f2770, 0x17fafc→0x4a2314, 0x17fb00→0x479be0, 0x17fb38→0x479c48
 * 调用序列: Graphics::GetMatrix(eMatrix, float*)
 * 字段偏移 top8: 0x60×3 / 0xa4×2 / 0x88×1 / 0x70×1 / 0x4×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17fa9c push {r4, r5, r6, r7, r8, lr}
 *   @0x17faa0 sub sp, sp, #64
 *   @0x17faa4 ldr r6, [pc, #0xa4]
 *   @0x17faa8 ldr r3, [pc, #0xa4]
 *   @0x17faac add r6, pc, r6
 *   @0x17fab0 ldr r3, [r6, r3]
 *   @0x17fab4 ldr r4, [r3]
 *   @0x17fab8 cmp r4, #0
 *   @0x17fabc beq 0x17fac8 <_Z19GR_3D_Light_Processv+0x2c>
 *   @0x17fac0 add sp, sp, #64
 *   @0x17fac4 pop {r4, r5, r6, r7, r8, pc}
 *   @0x17fac8 ldr r3, [pc, #0x88]
 *   @0x17facc ldr r3, [r6, r3]
 *   @0x17fad0 ldr r3, [r3]
 *   @0x17fad4 blx r3
 *   @0x17fad8 mov r0, r4
 *   @0x17fadc mov r1, sp
 *   @0x17fae0 bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf>
 *   @0x17fae4 ldr r3, [pc, #0x70]
 *   @0x17fae8 mov r0, sp
 *   @0x17faec ldr r3, [r6, r3]
 *   @0x17faf0 ldr r3, [r3]
 *   @0x17faf4 blx r3
 *   @0x17faf8 ldr r1, [pc, #0x60]
 *   @0x17fafc ldr r2, [pc, #0x60]
 *   @0x17fb00 ldr r3, [pc, #0x60]
 *   @0x17fb04 ldr r7, [r6, r1]
 *   @0x17fb08 ldr r5, [r6, r2]
 *   @0x17fb0c ldr r8, [r6, r3]
 *   @0x17fb10 sub r4, r7, #4
 *   @0x17fb14 add r7, r7, #28
 *   @0x17fb18 ldr r0, [r4, #0x4]!
 *   @0x17fb1c mov r2, r5
 *   @0x17fb20 movw r1, #0x1203
 *   @0x17fb24 ldr r3, [r8]
 *   @0x17fb28 blx r3
 *   @0x17fb2c cmp r4, r7
 *   @0x17fb30 add r5, r5, #16
 *   @0x17fb34 bne 0x17fb18 <_Z19GR_3D_Light_Processv+0x7c>
 *   @0x17fb38 ldr r3, [pc, #0x2c]
 *   @0x17fb3c ldr r3, [r6, r3]
 *   @0x17fb40 ldr r3, [r3]
 *   @0x17fb44 blx r3
 *   @0x17fb48 add sp, sp, #64
 *   @0x17fb4c pop {r4, r5, r6, r7, r8, pc}
 *   @0x17fb50 eoreq r2, r7, r4, lsr #3
 *   @0x17fb54 .word 0xffffe7b8
 *   @0x17fb58 .word 0xffffbc58
 *   @0x17fb5c .word 0xffffbc88
 *   @0x17fb60 .word 0xffffe848
 *   @0x17fb64 .word 0xffffe854
 *   @0x17fb68 .word 0xffffbc94
 *   @0x17fb6c .word 0xffffbc54
 *
 * ══ §36/159 JoinToPreviousStrip  0x185218  size 212  53 条（0x185218..0x1852ec）
 * @func 0x185218 0x1852ec  size 212  53 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x18521c→0x3f2928, 0x185238→0x4a2fa4, 0x18524c→0x4a2fb0, 0x185254→0x4a2fbc
 * 调用序列: 0xb65bc×3
 * 字段偏移 top8: 0xb8×2 / 0xa0×1 / 0x90×1 / 0x8c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x185218 ldr r3, [pc, #0xb8]
 *   @0x18521c ldr r2, [pc, #0xb8]
 *   @0x185220 add r3, pc, r3
 *   @0x185224 push {r4, r5, r6, r7, r8, lr}
 *   @0x185228 ldr r2, [r3, r2]
 *   @0x18522c ldr r2, [r2]
 *   @0x185230 cmp r2, #5
 *   @0x185234 popne {r4, r5, r6, r7, r8, pc}
 *   @0x185238 ldr r2, [pc, #0xa0]
 *   @0x18523c ldr r2, [r3, r2]
 *   @0x185240 ldr r12, [r2]
 *   @0x185244 cmp r12, #0
 *   @0x185248 pople {r4, r5, r6, r7, r8, pc}
 *   @0x18524c ldr r2, [pc, #0x90]
 *   @0x185250 tst r12, #1
 *   @0x185254 ldr r1, [pc, #0x8c]
 *   @0x185258 ldr r2, [r3, r2]
 *   @0x18525c ldr r5, [r3, r1]
 *   @0x185260 ldr r4, [r2]
 *   @0x185264 mul r0, r4, r12
 *   @0x185268 mov r2, r4
 *   @0x18526c rsb r6, r4, r0
 *   @0x185270 add r0, r5, r0
 *   @0x185274 bne 0x18529c <_Z19JoinToPreviousStripv+0x84>
 *   @0x185278 add r1, r5, r6
 *   @0x18527c bl 0xb65bc <memcpy@plt>
 *   @0x185280 add r0, r6, r4, lsl #1
 *   @0x185284 add r1, r0, r4
 *   @0x185288 mov r2, r4
 *   @0x18528c add r0, r5, r0
 *   @0x185290 add r1, r5, r1
 *   @0x185294 pop {r4, r5, r6, r7, r8, lr}
 *   @0x185298 b 0xb65bc <memcpy@plt>
 *   @0x18529c add r8, r6, r4, lsl #2
 *   @0x1852a0 add r1, r5, r6
 *   @0x1852a4 add r7, r8, r5
 *   @0x1852a8 bl 0xb65bc <memcpy@plt>
 *   @0x1852ac add r0, r6, r4, lsl #1
 *   @0x1852b0 mov r2, r4
 *   @0x1852b4 mov r1, r7
 *   @0x1852b8 add r0, r5, r0
 *   @0x1852bc bl 0xb65bc <memcpy@plt>
 *   @0x1852c0 rsb r0, r4, r8
 *   @0x1852c4 mov r1, r7
 *   @0x1852c8 add r0, r5, r0
 *   @0x1852cc mov r2, r4
 *   @0x1852d0 pop {r4, r5, r6, r7, r8, lr}
 *   @0x1852d4 b 0xb65bc <memcpy@plt>
 *   @0x1852d8 eoreq r12, r6, r0, lsr r10
 *   @0x1852dc .word 0xffffe948
 *   @0x1852e0 .word 0xffffe950
 *   @0x1852e4 .word 0xffffe954
 *   @0x1852e8 .word 0xffffe958
 *
 * ══ §37/159 CIAPPurchase::SetFromPurchase  0x18aa6c  size 212  53 条（0x18aa6c..0x18ab40）
 * @func 0x18aa6c 0x18ab40  size 212  53 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYFree(void const*)×5 / YYStrDup(char const*)×5
 * 字段偏移 top8: 0x4×3 / 0x8×3 / 0xc×3 / 0x10×3 / 0x14×1 / 0x18×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18aa6c push {r4, r5, r6, lr}
 *   @0x18aa70 mov r4, r0
 *   @0x18aa74 ldr r0, [r0, #0x4]
 *   @0x18aa78 mov r5, r1
 *   @0x18aa7c ldr r6, [r1, #0x4]
 *   @0x18aa80 cmp r0, #0
 *   @0x18aa84 beq 0x18aa8c <_ZN12CIAPPurchase15SetFromPurchaseERKS_+0x20>
 *   @0x18aa88 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x18aa8c mov r0, r6
 *   @0x18aa90 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x18aa94 ldr r3, [r4]
 *   @0x18aa98 cmp r3, #0
 *   @0x18aa9c str r0, [r4, #0x4]
 *   @0x18aaa0 ldr r6, [r5]
 *   @0x18aaa4 beq 0x18aab0 <_ZN12CIAPPurchase15SetFromPurchaseERKS_+0x44>
 *   @0x18aaa8 mov r0, r3
 *   @0x18aaac bl 0xcef90 <_Z6YYFreePKv>
 *   @0x18aab0 mov r0, r6
 *   @0x18aab4 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x18aab8 ldr r3, [r4, #0x8]
 *   @0x18aabc cmp r3, #0
 *   @0x18aac0 str r0, [r4]
 *   @0x18aac4 ldr r6, [r5, #0x8]
 *   @0x18aac8 beq 0x18aad4 <_ZN12CIAPPurchase15SetFromPurchaseERKS_+0x68>
 *   @0x18aacc mov r0, r3
 *   @0x18aad0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x18aad4 mov r0, r6
 *   @0x18aad8 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x18aadc ldr r3, [r4, #0xc]
 *   @0x18aae0 cmp r3, #0
 *   @0x18aae4 str r0, [r4, #0x8]
 *   @0x18aae8 ldr r6, [r5, #0xc]
 *   @0x18aaec beq 0x18aaf8 <_ZN12CIAPPurchase15SetFromPurchaseERKS_+0x8c>
 *   @0x18aaf0 mov r0, r3
 *   @0x18aaf4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x18aaf8 mov r0, r6
 *   @0x18aafc bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x18ab00 ldr r3, [r4, #0x10]
 *   @0x18ab04 cmp r3, #0
 *   @0x18ab08 str r0, [r4, #0xc]
 *   @0x18ab0c ldr r6, [r5, #0x10]
 *   @0x18ab10 beq 0x18ab1c <_ZN12CIAPPurchase15SetFromPurchaseERKS_+0xb0>
 *   @0x18ab14 mov r0, r3
 *   @0x18ab18 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x18ab1c mov r0, r6
 *   @0x18ab20 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x18ab24 add r1, r5, #20
 *   @0x18ab28 ldm r1, {r1, r2, r3}
 *   @0x18ab2c str r1, [r4, #0x14]
 *   @0x18ab30 str r2, [r4, #0x18]
 *   @0x18ab34 str r3, [r4, #0x1c]
 *   @0x18ab38 str r0, [r4, #0x10]
 *   @0x18ab3c pop {r4, r5, r6, pc}
 *
 * ══ §38/159 CObjectGM::HasEventRecursive  0x19dcdc  size 212  53 条（0x19dcdc..0x19ddb0）
 * @func 0x19dcdc 0x19ddc4  size 232  58 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CObjectGM::HasEventRecursive(int, int)+0x48 / CObjectGM::HasEventRecursive(int, int)+0xc0 / Object_Exists(int)
 * 字段偏移 top8: 0x8×3 / 0xc×3 / 0x4×2 / 0x4c×1 / 0x50×1 / 0x68×1 / 0x3×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19dcdc push {r3, r4, r5, r6, r7, lr}
 *   @0x19dce0 lsl r6, r1, #3
 *   @0x19dce4 lsl r7, r2, #2
 *   @0x19dce8 mov r5, r2
 *   @0x19dcec mov r4, r0
 *   @0x19dcf0 add r3, r4, r6
 *   @0x19dcf4 ldr r2, [r3, #0x4c]
 *   @0x19dcf8 cmp r2, r5
 *   @0x19dcfc ble 0x19dd24 <_ZN9CObjectGM17HasEventRecursiveEii+0x48>
 *   @0x19dd00 ldr r3, [r3, #0x50]
 *   @0x19dd04 cmp r3, #0
 *   @0x19dd08 beq 0x19dd24 <_ZN9CObjectGM17HasEventRecursiveEii+0x48>
 *   @0x19dd0c ldr r3, [r3, r7]
 *   @0x19dd10 cmp r3, #0
 *   @0x19dd14 beq 0x19dd24 <_ZN9CObjectGM17HasEventRecursiveEii+0x48>
 *   @0x19dd18 ldr r3, [r3, #0x8]
 *   @0x19dd1c cmp r3, #0
 *   @0x19dd20 bne 0x19dda4 <_ZN9CObjectGM17HasEventRecursiveEii+0xc8>
 *   @0x19dd24 ldr r0, [r4, #0xc]
 *   @0x19dd28 cmp r0, #0
 *   @0x19dd2c blt 0x19dd9c <_ZN9CObjectGM17HasEventRecursiveEii+0xc0>
 *   @0x19dd30 bl 0x19ecf8 <_Z13Object_Existsi>
 *   @0x19dd34 cmp r0, #0
 *   @0x19dd38 beq 0x19dd9c <_ZN9CObjectGM17HasEventRecursiveEii+0xc0>
 *   @0x19dd3c ldr r3, [pc, #0x68]
 *   @0x19dd40 ldr r12, [r4, #0xc]
 *   @0x19dd44 ldr r3, [pc, r3]
 *   @0x19dd48 ldr r3, [r3]
 *   @0x19dd4c ldr r2, [r3, #0x4]
 *   @0x19dd50 ldr r3, [r3]
 *   @0x19dd54 and r2, r12, r2
 *   @0x19dd58 ldr r3, [r3, r2, lsl #3]
 *   @0x19dd5c cmp r3, #0
 *   @0x19dd60 beq 0x19dd8c <_ZN9CObjectGM17HasEventRecursiveEii+0xb0>
 *   @0x19dd64 ldr r2, [r3, #0x8]
 *   @0x19dd68 cmp r12, r2
 *   @0x19dd6c bne 0x19dd80 <_ZN9CObjectGM17HasEventRecursiveEii+0xa4>
 *   @0x19dd70 b 0x19dd94 <_ZN9CObjectGM17HasEventRecursiveEii+0xb8>
 *   @0x19dd74 ldr r0, [r3, #0x8]
 *   @0x19dd78 cmp r12, r0
 *   @0x19dd7c beq 0x19dd94 <_ZN9CObjectGM17HasEventRecursiveEii+0xb8>
 *   @0x19dd80 ldr r3, [r3, #0x4]
 *   @0x19dd84 cmp r3, #0
 *   @0x19dd88 bne 0x19dd74 <_ZN9CObjectGM17HasEventRecursiveEii+0x98>
 *   @0x19dd8c mov r4, r3
 *   @0x19dd90 b 0x19dcf0 <_ZN9CObjectGM17HasEventRecursiveEii+0x14>
 *   @0x19dd94 ldr r4, [r3, #0xc]
 *   @0x19dd98 b 0x19dcf0 <_ZN9CObjectGM17HasEventRecursiveEii+0x14>
 *   @0x19dd9c mov r0, #0
 *   @0x19dda0 pop {r3, r4, r5, r6, r7, pc}
 *   @0x19dda4 mov r0, #1
 *   @0x19dda8 pop {r3, r4, r5, r6, r7, pc}
 *   @0x19ddac .word 0x0024fef8
 *
 * ══ §39/159 UpdateTree  0x1cc24c  size 212  53 条（0x1cc24c..0x1cc320）
 * @func 0x1cc24c 0x1cc320  size 212  53 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::Compute_BoundingBox(bool)
 * 字段偏移 top8: 0x1a0×2 / 0x4×2 / 0xc4×1 / 0x8×1 / 0x68×1 / 0x69×1 / 0x198×1 / 0x19c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1cc24c push {r3, r4, r5, r6, r7, lr}
 *   @0x1cc250 ldr r6, [pc, #0xc4]
 *   @0x1cc254 ldr r6, [pc, r6]
 *   @0x1cc258 ldr r5, [r6]
 *   @0x1cc25c cmp r5, r6
 *   @0x1cc260 beq 0x1cc2f0 <_Z10UpdateTreev+0xa4>
 *   @0x1cc264 mov r7, #0
 *   @0x1cc268 ldr r4, [r6, #0x8]
 *   @0x1cc26c subs r4, r5, r4
 *   @0x1cc270 beq 0x1cc298 <_Z10UpdateTreev+0x4c>
 *   @0x1cc274 ldrb r3, [r4, #0x68]
 *   @0x1cc278 cmp r3, #0
 *   @0x1cc27c bne 0x1cc298 <_Z10UpdateTreev+0x4c>
 *   @0x1cc280 ldrb r3, [r4, #0x69]
 *   @0x1cc284 cmp r3, #0
 *   @0x1cc288 bne 0x1cc298 <_Z10UpdateTreev+0x4c>
 *   @0x1cc28c mov r0, r4
 *   @0x1cc290 mov r1, #1
 *   @0x1cc294 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb>
 *   @0x1cc298 ldr r2, [r4, #0x1a0]
 *   @0x1cc29c add r3, r4, #408
 *   @0x1cc2a0 ldr r5, [r5]
 *   @0x1cc2a4 cmp r2, r6
 *   @0x1cc2a8 ldreq r1, [r4, #0x19c]
 *   @0x1cc2ac ldreq r2, [r4, #0x198]
 *   @0x1cc2b0 streq r1, [r2, #0x4]
 *   @0x1cc2b4 ldreq r1, [r4, #0x19c]
 *   @0x1cc2b8 streq r2, [r1]
 *   @0x1cc2bc cmp r5, r6
 *   @0x1cc2c0 str r3, [r4, #0x198]
 *   @0x1cc2c4 str r3, [r4, #0x19c]
 *   @0x1cc2c8 str r7, [r4, #0x1a0]
 *   @0x1cc2cc bne 0x1cc268 <_Z10UpdateTreev+0x1c>
 *   @0x1cc2d0 ldr r3, [r6]
 *   @0x1cc2d4 cmp r3, #0
 *   @0x1cc2d8 beq 0x1cc2f0 <_Z10UpdateTreev+0xa4>
 *   @0x1cc2dc cmp r3, r6
 *   @0x1cc2e0 strne r3, [r3]
 *   @0x1cc2e4 strne r3, [r3, #0x4]
 *   @0x1cc2e8 movne r2, #0
 *   @0x1cc2ec strne r2, [r3, #0x8]
 *   @0x1cc2f0 ldr r3, [r6, #0x4]
 *   @0x1cc2f4 cmp r3, #0
 *   @0x1cc2f8 beq 0x1cc310 <_Z10UpdateTreev+0xc4>
 *   @0x1cc2fc cmp r3, r6
 *   @0x1cc300 strne r3, [r3]
 *   @0x1cc304 strne r3, [r3, #0x4]
 *   @0x1cc308 movne r2, #0
 *   @0x1cc30c strne r2, [r3, #0x8]
 *   @0x1cc310 str r6, [r6]
 *   @0x1cc314 str r6, [r6, #0x4]
 *   @0x1cc318 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1cc31c eoreq r4, r2, r8, ror #17
 *
 * ══ §40/159 F_JS_ToUint32  0x24d4f4  size 212  53 条（0x24d4f4..0x24d5c8）
 * @func 0x24d4f4 0x24d5c8  size 212  53 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_JS_ToNumber(RValue&, RValue&) / yyisinf(RValue&) / FREE_RValue__Pre(RValue*) / __fixdfdi / __floatdidf
 * 字段偏移 top8: 0xc×3 / 0x8×1 / 0x4×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x24d4f4 push {r4, r5, r6, lr}
 *   @0x24d4f8 sub sp, sp, #16
 *   @0x24d4fc mov r6, r0
 *   @0x24d500 mov r2, #0
 *   @0x24d504 mov r0, sp
 *   @0x24d508 mov r3, #0
 *   @0x24d50c mov r12, #0
 *   @0x24d510 strd r2, r3, [sp]
 *   @0x24d514 str r12, [sp, #0x8]
 *   @0x24d518 mvn r3, #-16777216
 *   @0x24d51c str r3, [sp, #0xc]
 *   @0x24d520 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_>
 *   @0x24d524 subs r4, r0, #0
 *   @0x24d528 beq 0x24d550 <_Z13F_JS_ToUint32R6RValueS0_+0x5c>
 *   @0x24d52c ldr r3, [sp, #0xc]
 *   @0x24d530 sub r3, r3, #1
 *   @0x24d534 bic r3, r3, #-16777216
 *   @0x24d538 bic r3, r3, #3
 *   @0x24d53c cmp r3, #0
 *   @0x24d540 beq 0x24d59c <_Z13F_JS_ToUint32R6RValueS0_+0xa8>
 *   @0x24d544 mov r0, r4
 *   @0x24d548 add sp, sp, #16
 *   @0x24d54c pop {r4, r5, r6, pc}
 *   @0x24d550 vldr d7, [sp]
 *   @0x24d554 vcmp.f64 d7, d7
 *   @0x24d558 str r4, [r6, #0xc]
 *   @0x24d55c str r4, [r6]
 *   @0x24d560 str r4, [r6, #0x4]
 *   @0x24d564 vmrs APSR_nzcv, fpscr
 *   @0x24d568 bvs 0x24d58c <_Z13F_JS_ToUint32R6RValueS0_+0x98>
 *   @0x24d56c mov r0, sp
 *   @0x24d570 bl 0x240970 <_Z7yyisinfR6RValue>
 *   @0x24d574 subs r4, r0, #0
 *   @0x24d578 bne 0x24d58c <_Z13F_JS_ToUint32R6RValueS0_+0x98>
 *   @0x24d57c vldr d7, [sp]
 *   @0x24d580 vcmp.f64 d7, #0
 *   @0x24d584 vmrs APSR_nzcv, fpscr
 *   @0x24d588 bne 0x24d5b0 <_Z13F_JS_ToUint32R6RValueS0_+0xbc>
 *   @0x24d58c mov r4, #0
 *   @0x24d590 mov r0, r4
 *   @0x24d594 add sp, sp, #16
 *   @0x24d598 pop {r4, r5, r6, pc}
 *   @0x24d59c mov r0, sp
 *   @0x24d5a0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x24d5a4 mov r0, r4
 *   @0x24d5a8 add sp, sp, #16
 *   @0x24d5ac pop {r4, r5, r6, pc}
 *   @0x24d5b0 vmov r0, r1, d7
 *   @0x24d5b4 bl 0x3194a0 <__fixdfdi>
 *   @0x24d5b8 mov r1, #0
 *   @0x24d5bc bl 0x319164 <__floatdidf>
 *   @0x24d5c0 stm r6, {r0, r1}
 *   @0x24d5c4 b 0x24d544 <_Z13F_JS_ToUint32R6RValueS0_+0x50>
 *
 * ══ §41/159 spPolygon_containsPoint  0x28a5d4  size 212  53 条（0x28a5d4..0x28a6a8）
 * @func 0x28a5d4 0x28a6a8  size 212  53 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spPolygon_containsPoint+0xcc / spPolygon_containsPoint+0xc4 / spPolygon_containsPoint+0x6c
 * 字段偏移 top8: 0x4×1
 * VFP 指令 23 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28a5d4 push {r4, r5, r6}
 *   @0x28a5d8 vmov s9, r1
 *   @0x28a5dc ldr r5, [r0, #0x4]
 *   @0x28a5e0 vmov s14, r2
 *   @0x28a5e4 cmp r5, #0
 *   @0x28a5e8 sub r12, r5, #2
 *   @0x28a5ec ble 0x28a6a0 <spPolygon_containsPoint+0xcc>
 *   @0x28a5f0 ldr r6, [r0]
 *   @0x28a5f4 mov r2, #0
 *   @0x28a5f8 mov r0, r2
 *   @0x28a5fc add r1, r6, r5, lsl #2
 *   @0x28a600 add r3, r6, #4
 *   @0x28a604 vldr s13, [r1, #-4]
 *   @0x28a608 b 0x28a650 <spPolygon_containsPoint+0x7c>
 *   @0x28a60c vcmpe.f32 s14, s13
 *   @0x28a610 vmrs APSR_nzcv, fpscr
 *   @0x28a614 bhi 0x28a670 <spPolygon_containsPoint+0x9c>
 *   @0x28a618 vsub.f32 s13, s13, s15
 *   @0x28a61c vldr s12, [r3, #-4]
 *   @0x28a620 vldr s11, [r4]
 *   @0x28a624 vsub.f32 s10, s14, s15
 *   @0x28a628 vdiv.f32 s13, s10, s13
 *   @0x28a62c vsub.f32 s11, s11, s12
 *   @0x28a630 vmla.f32 s12, s13, s11
 *   @0x28a634 vcmpe.f32 s12, s9
 *   @0x28a638 vmrs APSR_nzcv, fpscr
 *   @0x28a63c eormi r0, r0, #1
 *   @0x28a640 cmp r5, r1
 *   @0x28a644 vmov.f32 s13, s15
 *   @0x28a648 add r3, r3, #8
 *   @0x28a64c ble 0x28a698 <spPolygon_containsPoint+0xc4>
 *   @0x28a650 vldr s15, [r3]
 *   @0x28a654 vcmpe.f32 s15, s14
 *   @0x28a658 add r1, r2, #2
 *   @0x28a65c add r4, r6, r12, lsl #2
 *   @0x28a660 mov r12, r2
 *   @0x28a664 mov r2, r1
 *   @0x28a668 vmrs APSR_nzcv, fpscr
 *   @0x28a66c bmi 0x28a60c <spPolygon_containsPoint+0x38>
 *   @0x28a670 vcmpe.f32 s14, s13
 *   @0x28a674 vmrs APSR_nzcv, fpscr
 *   @0x28a678 ble 0x28a640 <spPolygon_containsPoint+0x6c>
 *   @0x28a67c vcmpe.f32 s15, s14
 *   @0x28a680 vmrs APSR_nzcv, fpscr
 *   @0x28a684 bge 0x28a618 <spPolygon_containsPoint+0x44>
 *   @0x28a688 cmp r5, r1
 *   @0x28a68c vmov.f32 s13, s15
 *   @0x28a690 add r3, r3, #8
 *   @0x28a694 bgt 0x28a650 <spPolygon_containsPoint+0x7c>
 *   @0x28a698 pop {r4, r5, r6}
 *   @0x28a69c bx lr
 *   @0x28a6a0 mov r0, #0
 *   @0x28a6a4 b 0x28a698 <spPolygon_containsPoint+0xc4>
 *
 * ══ §42/159 GetSavePrePend  0x28fd6c  size 212  53 条（0x28fd6c..0x28fe40）
 * @func 0x28fd6c 0x28fe40  size 212  53 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x28fd70→0x757760, 0x28fd98→0x757750, 0x28fe1c→0x757750
 * 调用序列: 0xb6538×2 / 0xb65e0 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb6550 / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0xb8×2 / 0x94×1 / 0x5c×1 / 0x44×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28fd6c ldr r3, [pc, #0xb8]
 *   @0x28fd70 ldr r2, [pc, #0xb8]
 *   @0x28fd74 add r3, pc, r3
 *   @0x28fd78 push {r4, r5, r6, r7, r8, lr}
 *   @0x28fd7c ldr r5, [r3, r2]
 *   @0x28fd80 ldr r4, [r5]
 *   @0x28fd84 cmp r4, #0
 *   @0x28fd88 beq 0x28fe1c <_Z14GetSavePrePendv+0xb0>
 *   @0x28fd8c ldrb r2, [r4]
 *   @0x28fd90 cmp r2, #0
 *   @0x28fd94 beq 0x28fe1c <_Z14GetSavePrePendv+0xb0>
 *   @0x28fd98 ldr r2, [pc, #0x94]
 *   @0x28fd9c ldr r7, [r3, r2]
 *   @0x28fda0 ldr r6, [r7]
 *   @0x28fda4 mov r0, r6
 *   @0x28fda8 bl 0xb6538 <strlen@plt>
 *   @0x28fdac mov r1, r6
 *   @0x28fdb0 mov r8, r0
 *   @0x28fdb4 mov r0, r4
 *   @0x28fdb8 mov r2, r8
 *   @0x28fdbc bl 0xb65e0 <strncmp@plt>
 *   @0x28fdc0 cmp r0, #0
 *   @0x28fdc4 mov r0, r4
 *   @0x28fdc8 bne 0x28fdd0 <_Z14GetSavePrePendv+0x64>
 *   @0x28fdcc pop {r4, r5, r6, r7, r8, pc}
 *   @0x28fdd0 bl 0xb6538 <strlen@plt>
 *   @0x28fdd4 ldr r1, [pc, #0x5c]
 *   @0x28fdd8 movw r2, #0x167
 *   @0x28fddc mov r3, #1
 *   @0x28fde0 add r1, pc, r1
 *   @0x28fde4 add r0, r0, r8
 *   @0x28fde8 add r0, r0, #3
 *   @0x28fdec bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x28fdf0 ldr r1, [pc, #0x44]
 *   @0x28fdf4 ldr r2, [r7]
 *   @0x28fdf8 add r1, pc, r1
 *   @0x28fdfc ldr r3, [r5]
 *   @0x28fe00 mov r4, r0
 *   @0x28fe04 bl 0xb6550 <sprintf@plt>
 *   @0x28fe08 ldr r0, [r5]
 *   @0x28fe0c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x28fe10 str r4, [r5]
 *   @0x28fe14 mov r0, r4
 *   @0x28fe18 pop {r4, r5, r6, r7, r8, pc}
 *   @0x28fe1c ldr r2, [pc, #0x10]
 *   @0x28fe20 ldr r3, [r3, r2]
 *   @0x28fe24 ldr r0, [r3]
 *   @0x28fe28 pop {r4, r5, r6, r7, r8, pc}
 *   @0x28fe2c ldrsbeq r1, [r6], -r12
 *   @0x28fe30 .word 0xfffffcc4
 *   @0x28fe34 .word 0xfffffcc8
 *   @0x28fe38 andeq r8, r12, r4, asr r3
 *   @0x28fe3c andeq r8, r12, r12, ror #6
 *
 * ══ §43/159 b2Body::CreateFixture  0x2c6dfc  size 212  53 条（0x2c6dfc..0x2c6ed0）
 * @func 0x2c6dfc 0x2c6ed0  size 212  53 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2BlockAllocator::Allocate(int) / b2Fixture::b2Fixture() / b2Fixture::Create(b2BlockAllocator*, b2Body*, b2FixtureDef const*) / b2Body::CreateFixture(b2FixtureDef const*)+0x90 / b2Body::ResetMassData() / b2Fixture::CreateProxies(b2BroadPhase*, b2Transform const&)
 * 字段偏移 top8: 0x68×3 / 0x4×2 / 0x74×2 / 0x78×2 / 0x8×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c6dfc push {r3, r4, r5, r6, r7, lr}
 *   @0x2c6e00 movw r2, #0x91d4
 *   @0x2c6e04 ldr r6, [r0, #0x68]
 *   @0x2c6e08 movt r2, #0x1
 *   @0x2c6e0c mov r4, r0
 *   @0x2c6e10 mov r7, r1
 *   @0x2c6e14 ldr r2, [r6, r2]
 *   @0x2c6e18 tst r2, #2
 *   @0x2c6e1c bne 0x2c6ec8 <_ZN6b2Body13CreateFixtureEPK12b2FixtureDef+0xcc>
 *   @0x2c6e20 mov r0, r6
 *   @0x2c6e24 mov r1, #52
 *   @0x2c6e28 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi>
 *   @0x2c6e2c subs r5, r0, #0
 *   @0x2c6e30 beq 0x2c6e38 <_ZN6b2Body13CreateFixtureEPK12b2FixtureDef+0x3c>
 *   @0x2c6e34 bl 0x2c84e0 <_ZN9b2FixtureC2Ev>
 *   @0x2c6e38 mov r3, r7
 *   @0x2c6e3c mov r1, r6
 *   @0x2c6e40 mov r0, r5
 *   @0x2c6e44 mov r2, r4
 *   @0x2c6e48 bl 0x2c851c <_ZN9b2Fixture6CreateEP16b2BlockAllocatorP6b2BodyPK12b2FixtureDef>
 *   @0x2c6e4c ldrh r3, [r4, #4]
 *   @0x2c6e50 tst r3, #32
 *   @0x2c6e54 bne 0x2c6eac <_ZN6b2Body13CreateFixtureEPK12b2FixtureDef+0xb0>
 *   @0x2c6e58 vldr s15, [r5]
 *   @0x2c6e5c vcmpe.f32 s15, #0
 *   @0x2c6e60 ldr r2, [r4, #0x74]
 *   @0x2c6e64 ldr r3, [r4, #0x78]
 *   @0x2c6e68 vmrs APSR_nzcv, fpscr
 *   @0x2c6e6c str r2, [r5, #0x4]
 *   @0x2c6e70 add r3, r3, #1
 *   @0x2c6e74 str r5, [r4, #0x74]
 *   @0x2c6e78 str r3, [r4, #0x78]
 *   @0x2c6e7c str r4, [r5, #0x8]
 *   @0x2c6e80 ble 0x2c6e8c <_ZN6b2Body13CreateFixtureEPK12b2FixtureDef+0x90>
 *   @0x2c6e84 mov r0, r4
 *   @0x2c6e88 bl 0x2c6c00 <_ZN6b2Body13ResetMassDataEv>
 *   @0x2c6e8c ldr r2, [r4, #0x68]
 *   @0x2c6e90 movw r3, #0x91d4
 *   @0x2c6e94 movt r3, #0x1
 *   @0x2c6e98 mov r0, r5
 *   @0x2c6e9c ldr r1, [r2, r3]
 *   @0x2c6ea0 orr r1, r1, #1
 *   @0x2c6ea4 str r1, [r2, r3]
 *   @0x2c6ea8 pop {r3, r4, r5, r6, r7, pc}
 *   @0x2c6eac ldr r1, [r4, #0x68]
 *   @0x2c6eb0 mov r0, r5
 *   @0x2c6eb4 add r2, r4, #12
 *   @0x2c6eb8 add r1, r1, #102400
 *   @0x2c6ebc add r1, r1, #472
 *   @0x2c6ec0 bl 0x2c86e4 <_ZN9b2Fixture13CreateProxiesEP12b2BroadPhaseRK11b2Transform>
 *   @0x2c6ec4 b 0x2c6e58 <_ZN6b2Body13CreateFixtureEPK12b2FixtureDef+0x5c>
 *   @0x2c6ec8 mov r0, #0
 *   @0x2c6ecc pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §44/159 b2Fixture::Create  0x2c851c  size 212  53 条（0x2c851c..0x2c85f0）
 * @func 0x2c851c 0x2c85f0  size 212  53 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2BlockAllocator::Allocate(int) / b2Fixture::Create(b2BlockAllocator*, b2Body*, b2FixtureDef const*)+0xc0
 * 字段偏移 top8: 0x8×4 / 0x4×3 / 0x10×3 / 0xc×3 / 0x18×2 / 0x14×2 / 0x30×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c851c push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x2c8520 mov r5, r3
 *   @0x2c8524 mov r4, r0
 *   @0x2c8528 ldr r8, [r3, #0x18]!
 *   @0x2c852c ldr r0, [r5, #0x4]
 *   @0x2c8530 mov r7, #0
 *   @0x2c8534 ldr r12, [r5, #0x8]
 *   @0x2c8538 mov r9, r1
 *   @0x2c853c ldr r6, [r5]
 *   @0x2c8540 str r0, [r4, #0x30]
 *   @0x2c8544 str r12, [r4, #0x10]
 *   @0x2c8548 ldr r0, [r5, #0xc]
 *   @0x2c854c ldr r12, [r3, #0x4]
 *   @0x2c8550 str r2, [r4, #0x8]
 *   @0x2c8554 str r8, [r4, #0x20]
 *   @0x2c8558 ldrb r2, [r5, #0x14]
 *   @0x2c855c str r0, [r4, #0x14]
 *   @0x2c8560 mov r0, r6
 *   @0x2c8564 str r12, [r4, #0x24]
 *   @0x2c8568 ldr r6, [r6]
 *   @0x2c856c ldrh r12, [r3, #8]
 *   @0x2c8570 str r7, [r4, #0x4]
 *   @0x2c8574 ldr r3, [r6, #0x8]
 *   @0x2c8578 strh r12, [r4, #40]
 *   @0x2c857c strb r2, [r4, #0x2c]
 *   @0x2c8580 blx r3
 *   @0x2c8584 ldr r2, [r0]
 *   @0x2c8588 str r0, [r4, #0xc]
 *   @0x2c858c ldr r3, [r2, #0xc]
 *   @0x2c8590 blx r3
 *   @0x2c8594 rsb r8, r0, r0, lsl #3
 *   @0x2c8598 mov r6, r0
 *   @0x2c859c mov r0, r9
 *   @0x2c85a0 lsl r8, r8, #2
 *   @0x2c85a4 mov r1, r8
 *   @0x2c85a8 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi>
 *   @0x2c85ac cmp r6, r7
 *   @0x2c85b0 movgt r12, r7
 *   @0x2c85b4 movgt r2, r0
 *   @0x2c85b8 str r0, [r4, #0x18]
 *   @0x2c85bc addgt r1, r2, r8
 *   @0x2c85c0 mvngt r0, #0
 *   @0x2c85c4 ble 0x2c85dc <_ZN9b2Fixture6CreateEP16b2BlockAllocatorP6b2BodyPK12b2FixtureDef+0xc0>
 *   @0x2c85c8 str r12, [r2, #0x10]
 *   @0x2c85cc add r2, r2, #28
 *   @0x2c85d0 str r0, [r2, #-0x4]
 *   @0x2c85d4 cmp r2, r1
 *   @0x2c85d8 bne 0x2c85c8 <_ZN9b2Fixture6CreateEP16b2BlockAllocatorP6b2BodyPK12b2FixtureDef+0xac>
 *   @0x2c85dc ldr r2, [r5, #0x10]
 *   @0x2c85e0 mov r3, #0
 *   @0x2c85e4 str r3, [r4, #0x1c]
 *   @0x2c85e8 str r2, [r4]
 *   @0x2c85ec pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §45/159 Trim  0xc4728  size 208  52 条（0xc4728..0xc47f8）
 * @func 0xc4728 0xc47f8  size 208  52 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Trim(char const*&, char const*)+0x60×3 / YYStrDup(char const*)×2 / MemoryManager::Free(void const*) / 0xb6538 / Trim(char const*&, char const*)+0x9c
 * 字段偏移 top8: 0x64×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc4728 push {r3, r4, r5, r6, r7, lr}
 *   @0xc472c mov r6, r0
 *   @0xc4730 ldr r0, [r0]
 *   @0xc4734 mov r5, r1
 *   @0xc4738 cmp r0, #0
 *   @0xc473c beq 0xc4744 <_Z4TrimRPKcS0_+0x1c>
 *   @0xc4740 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xc4744 mov r0, r5
 *   @0xc4748 bl 0xb6538 <strlen@plt>
 *   @0xc474c cmp r5, #0
 *   @0xc4750 streq r5, [r6]
 *   @0xc4754 popeq {r3, r4, r5, r6, r7, pc}
 *   @0xc4758 cmp r0, #0
 *   @0xc475c ble 0xc4788 <_Z4TrimRPKcS0_+0x60>
 *   @0xc4760 mov lr, r5
 *   @0xc4764 mov r12, #0
 *   @0xc4768 mov r2, lr
 *   @0xc476c add lr, lr, #1
 *   @0xc4770 ldrb r4, [r2]
 *   @0xc4774 cmp r4, #32
 *   @0xc4778 bhi 0xc479c <_Z4TrimRPKcS0_+0x74>
 *   @0xc477c add r12, r12, #1
 *   @0xc4780 cmp r0, r12
 *   @0xc4784 bne 0xc4768 <_Z4TrimRPKcS0_+0x40>
 *   @0xc4788 ldr r0, [pc, #0x64]
 *   @0xc478c add r0, pc, r0
 *   @0xc4790 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xc4794 str r0, [r6]
 *   @0xc4798 pop {r3, r4, r5, r6, r7, pc}
 *   @0xc479c cmp r0, r12
 *   @0xc47a0 ble 0xc4788 <_Z4TrimRPKcS0_+0x60>
 *   @0xc47a4 sub r3, r0, #1
 *   @0xc47a8 ldrb r1, [r5, r3]
 *   @0xc47ac cmp r1, #32
 *   @0xc47b0 bls 0xc47c4 <_Z4TrimRPKcS0_+0x9c>
 *   @0xc47b4 b 0xc47d0 <_Z4TrimRPKcS0_+0xa8>
 *   @0xc47b8 ldrb r12, [r5, r3]
 *   @0xc47bc cmp r12, #32
 *   @0xc47c0 bhi 0xc47d0 <_Z4TrimRPKcS0_+0xa8>
 *   @0xc47c4 subs r3, r3, #1
 *   @0xc47c8 blo 0xc4788 <_Z4TrimRPKcS0_+0x60>
 *   @0xc47cc b 0xc47b8 <_Z4TrimRPKcS0_+0x90>
 *   @0xc47d0 add r4, r3, #1
 *   @0xc47d4 mov r0, r2
 *   @0xc47d8 mov r3, #0
 *   @0xc47dc ldrb r7, [r5, r4]
 *   @0xc47e0 strb r3, [r5, r4]
 *   @0xc47e4 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xc47e8 str r0, [r6]
 *   @0xc47ec strb r7, [r5, r4]
 *   @0xc47f0 pop {r3, r4, r5, r6, r7, pc}
 *   @0xc47f4 eoreq r7, r9, r8, asr #31
 *
 * ══ §46/159 CObjectGM::AddInstance  0x19e02c  size 208  52 条（0x19e02c..0x19e0fc）
 * @func 0x19e02c 0x19e110  size 228  57 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool)×2
 * 字段偏移 top8: 0xcc×2 / 0x8×2 / 0xd8×2 / 0xb0×1 / 0x90×1 / 0xc8×1 / 0xd4×1 / 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19e02c push {r3, r4, r5, r6, r7, lr}
 *   @0x19e030 mov r5, r1
 *   @0x19e034 ldr r12, [r0, #0xcc]
 *   @0x19e038 mov r4, r0
 *   @0x19e03c ldr r1, [pc, #0xb0]
 *   @0x19e040 mov r2, #143
 *   @0x19e044 add r12, r12, #1
 *   @0x19e048 mov r3, #1
 *   @0x19e04c mov r0, #12
 *   @0x19e050 add r1, pc, r1
 *   @0x19e054 str r12, [r4, #0xcc]
 *   @0x19e058 mov r7, #0
 *   @0x19e05c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x19e060 ldr r6, [pc, #0x90]
 *   @0x19e064 ldr r3, [r4, #0xc8]
 *   @0x19e068 add r6, pc, r6
 *   @0x19e06c cmp r3, #0
 *   @0x19e070 movne r2, #0
 *   @0x19e074 str r5, [r0, #0x8]
 *   @0x19e078 strne r0, [r3]
 *   @0x19e07c streq r0, [r4, #0xc8]
 *   @0x19e080 streq r0, [r4, #0xc4]
 *   @0x19e084 strne r3, [r0, #0x4]
 *   @0x19e088 streq r3, [r0, #0x4]
 *   @0x19e08c strne r0, [r4, #0xc8]
 *   @0x19e090 streq r3, [r0]
 *   @0x19e094 strne r2, [r0]
 *   @0x19e098 ldr r12, [r4, #0xd8]
 *   @0x19e09c mov r3, #1
 *   @0x19e0a0 mov r0, #12
 *   @0x19e0a4 mov r1, r6
 *   @0x19e0a8 add r12, r12, #1
 *   @0x19e0ac mov r2, #143
 *   @0x19e0b0 str r12, [r4, #0xd8]
 *   @0x19e0b4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x19e0b8 ldr r3, [r4, #0xd4]
 *   @0x19e0bc cmp r3, #0
 *   @0x19e0c0 str r5, [r0, #0x8]
 *   @0x19e0c4 streq r0, [r4, #0xd4]
 *   @0x19e0c8 streq r0, [r4, #0xd0]
 *   @0x19e0cc strne r0, [r3]
 *   @0x19e0d0 strne r3, [r0, #0x4]
 *   @0x19e0d4 strne r0, [r4, #0xd4]
 *   @0x19e0d8 ldr r4, [r4, #0x48]
 *   @0x19e0dc streq r3, [r0, #0x4]
 *   @0x19e0e0 streq r3, [r0]
 *   @0x19e0e4 strne r7, [r0]
 *   @0x19e0e8 cmp r4, #0
 *   @0x19e0ec bne 0x19e098 <_ZN9CObjectGM11AddInstanceEP9CInstance+0x6c>
 *   @0x19e0f0 pop {r3, r4, r5, r6, r7, pc}
 *   @0x19e0f4 andseq lr, r10, r0, ror #27
 *   @0x19e0f8 andseq lr, r10, r8, asr #27
 *
 * ══ §47/159 HttpCreateUpdateMap  0x1ce2bc  size 208  52 条（0x1ce2bc..0x1ce38c）
 * @func 0x1ce2bc 0x1ce38c  size 208  52 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CreateDsMap(int, ...)
 * 字段偏移 top8: 0x24×2 / 0x20×2 / 0x90×1 / 0x8c×1 / 0x74×1 / 0x34×1 / 0x6c×1 / 0x68×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1ce2bc vldr s14, [r0, #60]
 *   @0x1ce2c0 vcvt.f64.s32 d7, s14
 *   @0x1ce2c4 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x1ce2c8 vldr s12, [r0, #64]
 *   @0x1ce2cc mov r8, r2
 *   @0x1ce2d0 ldr r2, [r0, #0x24]
 *   @0x1ce2d4 sub sp, sp, #76
 *   @0x1ce2d8 ldr r9, [r0, #0x20]
 *   @0x1ce2dc mov r6, #0
 *   @0x1ce2e0 ldr r1, [pc, #0x90]
 *   @0x1ce2e4 mov r7, #0
 *   @0x1ce2e8 ldr lr, [pc, #0x8c]
 *   @0x1ce2ec mov r3, #0
 *   @0x1ce2f0 vstr d7, [sp, #56]
 *   @0x1ce2f4 vmov s15, r2
 *   @0x1ce2f8 vcvt.f64.s32 d6, s12
 *   @0x1ce2fc strd r6, r7, [sp, #24]
 *   @0x1ce300 add r1, pc, r1
 *   @0x1ce304 ldr r6, [pc, #0x74]
 *   @0x1ce308 str r1, [sp, #0x34]
 *   @0x1ce30c add lr, pc, lr
 *   @0x1ce310 ldr r12, [pc, #0x6c]
 *   @0x1ce314 mov r4, #0
 *   @0x1ce318 ldr r1, [pc, #0x68]
 *   @0x1ce31c add r6, pc, r6
 *   @0x1ce320 add r12, pc, r12
 *   @0x1ce324 str r3, [sp]
 *   @0x1ce328 str r3, [sp, #0x10]
 *   @0x1ce32c add r1, pc, r1
 *   @0x1ce330 vcvt.f64.s32 d7, s15
 *   @0x1ce334 str r3, [sp, #0x30]
 *   @0x1ce338 str r3, [sp, #0x40]
 *   @0x1ce33c vstr d6, [sp, #40]
 *   @0x1ce340 str r9, [sp, #0x20]
 *   @0x1ce344 mov r5, #0
 *   @0x1ce348 str r6, [sp, #0x4]
 *   @0x1ce34c movt r5, #0x3ff0
 *   @0x1ce350 str lr, [sp, #0x14]
 *   @0x1ce354 mov r0, #5
 *   @0x1ce358 strd r4, r5, [sp, #8]
 *   @0x1ce35c str r12, [sp, #0x24]
 *   @0x1ce360 vmov r2, r3, d7
 *   @0x1ce364 bl 0x20bdc0 <_Z11CreateDsMapiz>
 *   @0x1ce368 str r0, [r8]
 *   @0x1ce36c mov r0, #62
 *   @0x1ce370 add sp, sp, #76
 *   @0x1ce374 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x1ce378 ldrsheq r1, [r7], -r4
 *   @0x1ce37c andseq r1, r7, r0, asr #27
 *   @0x1ce380 andseq r2, r6, r4, lsr r7
 *   @0x1ce384 andseq r1, r7, r4, asr #27
 *   @0x1ce388 andseq r2, r6, r4, lsl r7
 *
 * ══ §48/159 CDS_Map::Mark4GC  0x2036e4  size 208  52 条（0x2036e4..0x2037b4）
 * @func 0x2036e4 0x2037c8  size 228  57 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RVALUE_GC(RValue const*, unsigned int*, int)×2
 * 字段偏移 top8: 0x4×3 / 0x3×1 / 0xc×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2036e4 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x2036e8 mov r8, r2
 *   @0x2036ec ldr r9, [r0]
 *   @0x2036f0 mov r7, r1
 *   @0x2036f4 mov r5, #0
 *   @0x2036f8 ldr r2, [r9]
 *   @0x2036fc b 0x203710 <_ZN7CDS_Map7Mark4GCEPji+0x2c>
 *   @0x203700 ldr r3, [r9, #0x4]
 *   @0x203704 add r5, r5, #1
 *   @0x203708 cmp r5, r3
 *   @0x20370c bgt 0x2037a4 <_ZN7CDS_Map7Mark4GCEPji+0xc0>
 *   @0x203710 ldr r4, [r2, r5, lsl #3]
 *   @0x203714 cmp r4, #0
 *   @0x203718 beq 0x203700 <_ZN7CDS_Map7Mark4GCEPji+0x1c>
 *   @0x20371c cmp r4, #0
 *   @0x203720 popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x203724 ldr r6, [r4, #0xc]
 *   @0x203728 cmp r6, #0
 *   @0x20372c beq 0x20379c <_ZN7CDS_Map7Mark4GCEPji+0xb8>
 *   @0x203730 mov r0, r6
 *   @0x203734 mov r1, r7
 *   @0x203738 mov r2, r8
 *   @0x20373c bl 0x191db8 <_Z9RVALUE_GCPK6RValuePji>
 *   @0x203740 add r0, r6, #16
 *   @0x203744 mov r1, r7
 *   @0x203748 mov r2, r8
 *   @0x20374c bl 0x191db8 <_Z9RVALUE_GCPK6RValuePji>
 *   @0x203750 ldr r4, [r4, #0x4]
 *   @0x203754 cmp r4, #0
 *   @0x203758 bne 0x20371c <_ZN7CDS_Map7Mark4GCEPji+0x38>
 *   @0x20375c ldr r12, [r9, #0x4]
 *   @0x203760 add r3, r5, #1
 *   @0x203764 cmp r3, r12
 *   @0x203768 popgt {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x20376c ldr r0, [r9]
 *   @0x203770 add r0, r0, r5, lsl #3
 *   @0x203774 b 0x203780 <_ZN7CDS_Map7Mark4GCEPji+0x9c>
 *   @0x203778 cmp r3, r12
 *   @0x20377c bgt 0x2037a0 <_ZN7CDS_Map7Mark4GCEPji+0xbc>
 *   @0x203780 ldr r4, [r0, #0x8]
 *   @0x203784 mov r5, r3
 *   @0x203788 add r0, r0, #8
 *   @0x20378c add r3, r3, #1
 *   @0x203790 cmp r4, #0
 *   @0x203794 beq 0x203778 <_ZN7CDS_Map7Mark4GCEPji+0x94>
 *   @0x203798 b 0x20371c <_ZN7CDS_Map7Mark4GCEPji+0x38>
 *   @0x20379c pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2037a0 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2037a4 cmp r4, #0
 *   @0x2037a8 mvn r5, #0
 *   @0x2037ac bne 0x203724 <_ZN7CDS_Map7Mark4GCEPji+0x40>
 *   @0x2037b0 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §49/159 yySocket::SendUDPPacket  0x296a38  size 208  52 条（0x296a38..0x296b08）
 * @func 0x296a38 0x296b08  size 208  52 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65bc / yySocket::SendTo(char*, int, unsigned char*, int) / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x58×3 / 0x5c×1 / 0x34×1 / 0x30×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x296a38 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x296a3c sub sp, sp, #12
 *   @0x296a40 mov r11, r3
 *   @0x296a44 ldr r3, [r0, #0x5c]
 *   @0x296a48 ldrb r6, [sp, #0x34]
 *   @0x296a4c mov r4, r0
 *   @0x296a50 ldr r7, [sp, #0x30]
 *   @0x296a54 mov r10, r1
 *   @0x296a58 cmp r6, #0
 *   @0x296a5c mov r9, r2
 *   @0x296a60 movne r8, #12
 *   @0x296a64 moveq r5, r6
 *   @0x296a68 movne r5, r8
 *   @0x296a6c add r5, r5, r7
 *   @0x296a70 moveq r8, r6
 *   @0x296a74 cmp r5, r3
 *   @0x296a78 bgt 0x296ad8 <_ZN8yySocket13SendUDPPacketEPciPhib+0xa0>
 *   @0x296a7c ldr r3, [r0, #0x58]
 *   @0x296a80 mov r2, r7
 *   @0x296a84 add r0, r3, r8
 *   @0x296a88 mov r1, r11
 *   @0x296a8c bl 0xb65bc <memcpy@plt>
 *   @0x296a90 cmp r6, #0
 *   @0x296a94 ldrne r0, [r4, #0x58]
 *   @0x296a98 movwne r2, #0xc0de
 *   @0x296a9c ldreq r3, [r4, #0x58]
 *   @0x296aa0 movne r1, #12
 *   @0x296aa4 movtne r2, #0xdead
 *   @0x296aa8 stmibne r0, {r1, r7}
 *   @0x296aac strne r2, [r0]
 *   @0x296ab0 movne r3, r0
 *   @0x296ab4 str r5, [sp]
 *   @0x296ab8 mov r0, r4
 *   @0x296abc mov r1, r10
 *   @0x296ac0 mov r2, r9
 *   @0x296ac4 bl 0x295f28 <_ZN8yySocket6SendToEPciPhi>
 *   @0x296ac8 cmp r0, #0
 *   @0x296acc movge r0, r5
 *   @0x296ad0 add sp, sp, #12
 *   @0x296ad4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x296ad8 ldr r2, [pc, #0x24]
 *   @0x296adc mov r3, #0
 *   @0x296ae0 ldr r0, [r0, #0x58]
 *   @0x296ae4 mov r1, r5
 *   @0x296ae8 str r3, [sp]
 *   @0x296aec add r2, pc, r2
 *   @0x296af0 mov r3, #74
 *   @0x296af4 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x296af8 mov r3, r0
 *   @0x296afc str r0, [r4, #0x58]
 *   @0x296b00 b 0x296a80 <_ZN8yySocket13SendUDPPacketEPciPhib+0x48>
 *   @0x296b04 andeq r10, r9, r4, asr #10
 *
 * ══ §50/159 LoadSave::WriteFile  0x18fa3c  size 204  51 条（0x18fa3c..0x18fb08）
 * @func 0x18fa3c 0x18fb08  size 204  51 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LoadSave::_GetSaveFileName(char*, int, char const*) / EnsureDirectoryIsCreated(char const*) / 0xb6844 / 0xb68bc / 0xb6850 / 0xb65d4
 * 字段偏移 top8: 0x804×2 / 0xb4×1 / 0x7c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18fa3c push {r4, r5, r6, r7, lr}
 *   @0x18fa40 sub sp, sp, #2048
 *   @0x18fa44 ldr r7, [pc, #0xb4]
 *   @0x18fa48 sub sp, sp, #12
 *   @0x18fa4c add r6, sp, #4
 *   @0x18fa50 mov r12, r0
 *   @0x18fa54 ldr r7, [pc, r7]
 *   @0x18fa58 mov r5, r1
 *   @0x18fa5c mov r0, r6
 *   @0x18fa60 movw r1, #0x7ff
 *   @0x18fa64 ldr r3, [r7]
 *   @0x18fa68 mov r4, r2
 *   @0x18fa6c mov r2, r12
 *   @0x18fa70 str r3, [sp, #0x804]
 *   @0x18fa74 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0x18fa78 mov r0, r6
 *   @0x18fa7c bl 0x13ad20 <_Z24EnsureDirectoryIsCreatedPKc>
 *   @0x18fa80 ldr r1, [pc, #0x7c]
 *   @0x18fa84 mov r0, r6
 *   @0x18fa88 add r1, pc, r1
 *   @0x18fa8c bl 0xb6844 <fopen@plt>
 *   @0x18fa90 subs r6, r0, #0
 *   @0x18fa94 beq 0x18faf4 <_ZN8LoadSave9WriteFileEPKcS1_i+0xb8>
 *   @0x18fa98 cmp r4, #0
 *   @0x18fa9c bne 0x18fab0 <_ZN8LoadSave9WriteFileEPKcS1_i+0x74>
 *   @0x18faa0 b 0x18facc <_ZN8LoadSave9WriteFileEPKcS1_i+0x90>
 *   @0x18faa4 subs r4, r4, r0
 *   @0x18faa8 add r5, r5, r0
 *   @0x18faac beq 0x18facc <_ZN8LoadSave9WriteFileEPKcS1_i+0x90>
 *   @0x18fab0 mov r0, r5
 *   @0x18fab4 mov r1, #1
 *   @0x18fab8 mov r2, r4
 *   @0x18fabc mov r3, r6
 *   @0x18fac0 bl 0xb68bc <fwrite@plt>
 *   @0x18fac4 cmp r0, #0
 *   @0x18fac8 bne 0x18faa4 <_ZN8LoadSave9WriteFileEPKcS1_i+0x68>
 *   @0x18facc mov r0, r6
 *   @0x18fad0 bl 0xb6850 <fclose@plt>
 *   @0x18fad4 mov r0, #1
 *   @0x18fad8 ldr r2, [sp, #0x804]
 *   @0x18fadc ldr r3, [r7]
 *   @0x18fae0 cmp r2, r3
 *   @0x18fae4 bne 0x18fafc <_ZN8LoadSave9WriteFileEPKcS1_i+0xc0>
 *   @0x18fae8 add sp, sp, #2048
 *   @0x18faec add sp, sp, #12
 *   @0x18faf0 pop {r4, r5, r6, r7, pc}
 *   @0x18faf4 mov r0, r6
 *   @0x18faf8 b 0x18fad8 <_ZN8LoadSave9WriteFileEPKcS1_i+0x9c>
 *   @0x18fafc bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x18fb00 .word 0x0025defc
 *   @0x18fb04 ldrheq r0, [r11], -r12
 *
 * ══ §51/159 CObjectGM::RemoveInstance  0x19e0fc  size 204  51 条（0x19e0fc..0x19e1c8）
 * @func 0x19e0fc 0x19e1c8  size 204  51 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2
 * 字段偏移 top8: 0x8×2 / 0xcc×2 / 0xd8×2 / 0xc4×1 / 0xd0×1 / 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19e0fc push {r3, r4, r5, lr}
 *   @0x19e100 mov r5, r0
 *   @0x19e104 ldr r0, [r0, #0xc4]
 *   @0x19e108 mov r4, r1
 *   @0x19e10c cmp r0, #0
 *   @0x19e110 bne 0x19e124 <_ZN9CObjectGM14RemoveInstanceEP9CInstance+0x28>
 *   @0x19e114 b 0x19e160 <_ZN9CObjectGM14RemoveInstanceEP9CInstance+0x64>
 *   @0x19e118 ldr r0, [r0]
 *   @0x19e11c cmp r0, #0
 *   @0x19e120 beq 0x19e160 <_ZN9CObjectGM14RemoveInstanceEP9CInstance+0x64>
 *   @0x19e124 ldr r2, [r0, #0x8]
 *   @0x19e128 cmp r4, r2
 *   @0x19e12c bne 0x19e118 <_ZN9CObjectGM14RemoveInstanceEP9CInstance+0x1c>
 *   @0x19e130 ldm r0, {r1, r2}
 *   @0x19e134 cmp r2, #0
 *   @0x19e138 strne r1, [r2]
 *   @0x19e13c ldrne r1, [r0]
 *   @0x19e140 streq r1, [r5, #0xc4]
 *   @0x19e144 cmp r1, #0
 *   @0x19e148 streq r2, [r5, #0xc8]
 *   @0x19e14c strne r2, [r1, #0x4]
 *   @0x19e150 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x19e154 ldr r3, [r5, #0xcc]
 *   @0x19e158 sub r3, r3, #1
 *   @0x19e15c str r3, [r5, #0xcc]
 *   @0x19e160 ldr r0, [r5, #0xd0]
 *   @0x19e164 cmp r0, #0
 *   @0x19e168 bne 0x19e17c <_ZN9CObjectGM14RemoveInstanceEP9CInstance+0x80>
 *   @0x19e16c b 0x19e1b8 <_ZN9CObjectGM14RemoveInstanceEP9CInstance+0xbc>
 *   @0x19e170 ldr r0, [r0]
 *   @0x19e174 cmp r0, #0
 *   @0x19e178 beq 0x19e1b8 <_ZN9CObjectGM14RemoveInstanceEP9CInstance+0xbc>
 *   @0x19e17c ldr r3, [r0, #0x8]
 *   @0x19e180 cmp r4, r3
 *   @0x19e184 bne 0x19e170 <_ZN9CObjectGM14RemoveInstanceEP9CInstance+0x74>
 *   @0x19e188 ldm r0, {r2, r3}
 *   @0x19e18c cmp r3, #0
 *   @0x19e190 strne r2, [r3]
 *   @0x19e194 ldrne r2, [r0]
 *   @0x19e198 streq r2, [r5, #0xd0]
 *   @0x19e19c cmp r2, #0
 *   @0x19e1a0 streq r3, [r5, #0xd4]
 *   @0x19e1a4 strne r3, [r2, #0x4]
 *   @0x19e1a8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x19e1ac ldr r3, [r5, #0xd8]
 *   @0x19e1b0 sub r3, r3, #1
 *   @0x19e1b4 str r3, [r5, #0xd8]
 *   @0x19e1b8 ldr r5, [r5, #0x48]
 *   @0x19e1bc cmp r5, #0
 *   @0x19e1c0 bne 0x19e160 <_ZN9CObjectGM14RemoveInstanceEP9CInstance+0x64>
 *   @0x19e1c4 pop {r3, r4, r5, pc}
 *
 * ══ §52/159 Audio_CreateSources  0x21625c  size 204  51 条（0x21625c..0x216328）
 * @func 0x21625c 0x216328  size 204  51 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x21626c→0x3f52c8, 0x216278→0x3f52c4, 0x216298→0x75531c, 0x2162c0→0x3eb70c
 * 调用序列: operator new[](unsigned int) / 0xb6a90 / 0xb6a54 / COggAudio::Init(int, int)
 * 字段偏移 top8: 0x50×2 / 0x9c×1 / 0x98×1 / 0x90×1 / 0x74×1 / 0xc×1 / 0x38×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21625c push {r4, r5, r6, lr}
 *   @0x216260 cmp r0, #532676608
 *   @0x216264 ldr r5, [pc, #0x9c]
 *   @0x216268 sub r3, r0, #1
 *   @0x21626c ldr r1, [pc, #0x98]
 *   @0x216270 mov r4, r0
 *   @0x216274 add r5, pc, r5
 *   @0x216278 ldr r2, [pc, #0x90]
 *   @0x21627c ldr r1, [r5, r1]
 *   @0x216280 str r0, [r1]
 *   @0x216284 lslls r0, r0, #2
 *   @0x216288 ldr r6, [r5, r2]
 *   @0x21628c mvnhi r0, #0
 *   @0x216290 str r3, [r6]
 *   @0x216294 bl 0x27d14c <_Znaj>
 *   @0x216298 ldr r2, [pc, #0x74]
 *   @0x21629c ldr r2, [r5, r2]
 *   @0x2162a0 mov r3, r0
 *   @0x2162a4 mov r1, r0
 *   @0x2162a8 mov r0, r4
 *   @0x2162ac str r3, [r2]
 *   @0x2162b0 bl 0xb6a90 <alGenSources@plt>
 *   @0x2162b4 bl 0xb6a54 <alGetError@plt>
 *   @0x2162b8 subs r2, r0, #0
 *   @0x2162bc beq 0x2162e0 <_Z19Audio_CreateSourcesi+0x84>
 *   @0x2162c0 ldr r3, [pc, #0x50]
 *   @0x2162c4 ldr r1, [pc, #0x50]
 *   @0x2162c8 ldr r3, [r5, r3]
 *   @0x2162cc add r1, pc, r1
 *   @0x2162d0 ldr r0, [r3]
 *   @0x2162d4 ldr r3, [r0]
 *   @0x2162d8 ldr r3, [r3, #0xc]
 *   @0x2162dc blx r3
 *   @0x2162e0 ldr r0, [pc, #0x38]
 *   @0x2162e4 mov r2, r4
 *   @0x2162e8 mov r1, #4
 *   @0x2162ec add r0, pc, r0
 *   @0x2162f0 bl 0x225d18 <_ZN9COggAudio4InitEii>
 *   @0x2162f4 ldr r0, [pc, #0x28]
 *   @0x2162f8 str r4, [r6]
 *   @0x2162fc add r0, pc, r0
 *   @0x216300 pop {r4, r5, r6, lr}
 *   @0x216304 b 0x215fd0 <_Z7checkALPKc>
 *   @0x216308 ldrsbeq r11, [sp], -r12
 *   @0x21630c .word 0xfffff780
 *   @0x216310 .word 0xfffff784
 *   @0x216314 .word 0xfffff77c
 *   @0x216318 .word 0xffffbac4
 *   @0x21631c ldrheq sp, [r3], -r8
 *   @0x216320 subseq lr, r3, r8, lsr #31
 *   @0x216324 andseq sp, r3, r12, lsr #17
 *
 * ══ §53/159 JS_ToBoolean  0x2404bc  size 204  51 条（0x2404bc..0x240588）
 * @func 0x2404bc 0x240588  size 204  51 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYError(char const*, ...)
 * 字段偏移 top8: 0xc×1 / 0x70×1
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2404bc ldr r1, [r0, #0xc]
 *   @0x2404c0 push {r3, lr}
 *   @0x2404c4 bic r1, r1, #-16777216
 *   @0x2404c8 cmp r1, #13
 *   @0x2404cc addls pc, pc, r1, lsl #2
 *   @0x2404d0 b 0x24050c <_Z12JS_ToBooleanR6RValue+0x50>
 *   @0x2404d4 b 0x240528 <_Z12JS_ToBooleanR6RValue+0x6c>
 *   @0x2404d8 b 0x24056c <_Z12JS_ToBooleanR6RValue+0xb0>
 *   @0x2404dc b 0x24050c <_Z12JS_ToBooleanR6RValue+0x50>
 *   @0x2404e0 b 0x24050c <_Z12JS_ToBooleanR6RValue+0x50>
 *   @0x2404e4 b 0x24050c <_Z12JS_ToBooleanR6RValue+0x50>
 *   @0x2404e8 b 0x240518 <_Z12JS_ToBooleanR6RValue+0x5c>
 *   @0x2404ec b 0x240520 <_Z12JS_ToBooleanR6RValue+0x64>
 *   @0x2404f0 b 0x240528 <_Z12JS_ToBooleanR6RValue+0x6c>
 *   @0x2404f4 b 0x24050c <_Z12JS_ToBooleanR6RValue+0x50>
 *   @0x2404f8 b 0x24050c <_Z12JS_ToBooleanR6RValue+0x50>
 *   @0x2404fc b 0x240528 <_Z12JS_ToBooleanR6RValue+0x6c>
 *   @0x240500 b 0x24050c <_Z12JS_ToBooleanR6RValue+0x50>
 *   @0x240504 b 0x240518 <_Z12JS_ToBooleanR6RValue+0x5c>
 *   @0x240508 b 0x240550 <_Z12JS_ToBooleanR6RValue+0x94>
 *   @0x24050c ldr r0, [pc, #0x70]
 *   @0x240510 add r0, pc, r0
 *   @0x240514 bl 0xd547c <_Z7YYErrorPKcz>
 *   @0x240518 mov r0, #0
 *   @0x24051c pop {r3, pc}
 *   @0x240520 mov r0, #1
 *   @0x240524 pop {r3, pc}
 *   @0x240528 ldm r0, {r2, r3}
 *   @0x24052c vmov d7, r2, r3
 *   @0x240530 vcmp.f64 d7, #0
 *   @0x240534 vmrs APSR_nzcv, fpscr
 *   @0x240538 beq 0x240518 <_Z12JS_ToBooleanR6RValue+0x5c>
 *   @0x24053c vcmp.f64 d7, d7
 *   @0x240540 vmrs APSR_nzcv, fpscr
 *   @0x240544 movvs r0, #0
 *   @0x240548 movvc r0, #1
 *   @0x24054c pop {r3, pc}
 *   @0x240550 ldm r0, {r2, r3}
 *   @0x240554 vmov d6, r2, r3
 *   @0x240558 vcmp.f64 d6, #0
 *   @0x24055c vmrs APSR_nzcv, fpscr
 *   @0x240560 moveq r0, #0
 *   @0x240564 movne r0, #1
 *   @0x240568 pop {r3, pc}
 *   @0x24056c ldr r3, [r0]
 *   @0x240570 ldr r3, [r3]
 *   @0x240574 ldrb r0, [r3]
 *   @0x240578 adds r0, r0, #0
 *   @0x24057c movne r0, #1
 *   @0x240580 pop {r3, pc}
 *   @0x240584 ldrsbeq r4, [r1], -r0
 *
 * ══ §54/159 AllocBuffer  0xc67b0  size 200  50 条（0xc67b0..0xc6878）
 * @func 0xc67b0 0xc6878  size 200  50 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: AllocBuffer()+0xa4 / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x4×3 / 0xb0×1 / 0x64×1 / 0x54×1 / 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc67b0 ldr r3, [pc, #0xb0]
 *   @0xc67b4 push {r4, lr}
 *   @0xc67b8 add r3, pc, r3
 *   @0xc67bc sub sp, sp, #8
 *   @0xc67c0 ldr r4, [r3]
 *   @0xc67c4 ldr r0, [r3, #0x4]
 *   @0xc67c8 cmp r4, #0
 *   @0xc67cc ble 0xc6854 <_Z11AllocBufferv+0xa4>
 *   @0xc67d0 ldr r3, [r0]
 *   @0xc67d4 cmp r3, #0
 *   @0xc67d8 beq 0xc6844 <_Z11AllocBufferv+0x94>
 *   @0xc67dc mov r2, r0
 *   @0xc67e0 mov r3, #0
 *   @0xc67e4 b 0xc67f4 <_Z11AllocBufferv+0x44>
 *   @0xc67e8 ldr r1, [r2, #0x4]!
 *   @0xc67ec cmp r1, #0
 *   @0xc67f0 beq 0xc6844 <_Z11AllocBufferv+0x94>
 *   @0xc67f4 add r3, r3, #1
 *   @0xc67f8 cmp r3, r4
 *   @0xc67fc bne 0xc67e8 <_Z11AllocBufferv+0x38>
 *   @0xc6800 ldr r3, [pc, #0x64]
 *   @0xc6804 lsl r1, r4, #3
 *   @0xc6808 lsl r2, r4, #1
 *   @0xc680c add r3, pc, r3
 *   @0xc6810 str r2, [r3]
 *   @0xc6814 ldr r2, [pc, #0x54]
 *   @0xc6818 mov r3, #0
 *   @0xc681c str r3, [sp]
 *   @0xc6820 mov r3, #74
 *   @0xc6824 add r2, pc, r2
 *   @0xc6828 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0xc682c ldr r3, [pc, #0x40]
 *   @0xc6830 add r3, pc, r3
 *   @0xc6834 str r0, [r3, #0x4]
 *   @0xc6838 mov r0, r4
 *   @0xc683c add sp, sp, #8
 *   @0xc6840 pop {r4, pc}
 *   @0xc6844 mov r4, r3
 *   @0xc6848 mov r0, r4
 *   @0xc684c add sp, sp, #8
 *   @0xc6850 pop {r4, pc}
 *   @0xc6854 moveq r2, #32
 *   @0xc6858 moveq r1, #128
 *   @0xc685c streq r2, [r3]
 *   @0xc6860 beq 0xc6814 <_Z11AllocBufferv+0x64>
 *   @0xc6864 b 0xc6800 <_Z11AllocBufferv+0x50>
 *   @0xc6868 eorseq r3, r11, r12, asr r9
 *   @0xc686c eorseq r3, r11, r8, lsl #18
 *   @0xc6870 eoreq r10, r6, r12, lsl #16
 *   @0xc6874 eorseq r3, r11, r4, ror #17
 *
 * ══ §55/159 CCamera::Build2DView  0x16db44  size 200  50 条（0x16db44..0x16dc0c）
 * @func 0x16db44 0x16dc0c  size 200  50 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6580 / 0xb658c / yyMatrix::LookAtLH(yyMatrix*, yyVector3*, yyVector3*, yyVector3*) / yyMatrix::OrthoLH(yyMatrix*, float, float, float, float) / CCamera::SetViewMat(yyMatrix&) / CCamera::SetProjMat(yyMatrix&)
 * 字段偏移 top8: 0xc×1 / 0x18×1 / 0x10×1 / 0x1c×1 / 0x14×1 / 0x20×1 / 0x24×1 / 0x2c×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16db44 push {r4, r5, r6, lr}
 *   @0x16db48 vpush {d8}
 *   @0x16db4c vldr s17, [r0, #420]
 *   @0x16db50 vldr s16, [pc, #176]
 *   @0x16db54 vnmul.f32 s15, s17, s16
 *   @0x16db58 sub sp, sp, #176
 *   @0x16db5c mov r4, r0
 *   @0x16db60 mov r5, #0
 *   @0x16db64 str r1, [sp, #0xc]
 *   @0x16db68 mov r3, #0
 *   @0x16db6c str r1, [sp, #0x18]
 *   @0x16db70 movt r3, #0xc67a
 *   @0x16db74 str r2, [sp, #0x10]
 *   @0x16db78 str r2, [sp, #0x1c]
 *   @0x16db7c str r3, [sp, #0x14]
 *   @0x16db80 str r5, [sp, #0x20]
 *   @0x16db84 vmov r0, s15
 *   @0x16db88 bl 0xb6580 <sinf@plt>
 *   @0x16db8c vmul.f32 s16, s17, s16
 *   @0x16db90 mov r6, r0
 *   @0x16db94 vmov r0, s16
 *   @0x16db98 bl 0xb658c <cosf@plt>
 *   @0x16db9c str r6, [sp, #0x24]
 *   @0x16dba0 add r6, sp, #48
 *   @0x16dba4 str r5, [sp, #0x2c]
 *   @0x16dba8 add r5, sp, #112
 *   @0x16dbac add r1, sp, #12
 *   @0x16dbb0 add r2, sp, #24
 *   @0x16dbb4 add r3, sp, #36
 *   @0x16dbb8 str r0, [sp, #0x28]
 *   @0x16dbbc mov r0, r6
 *   @0x16dbc0 bl 0x27acb0 <_ZN8yyMatrix8LookAtLHEPS_P9yyVector3S2_S2_>
 *   @0x16dbc4 ldr r2, [r4, #0x190]
 *   @0x16dbc8 ldr r1, [r4, #0x18c]
 *   @0x16dbcc mov r3, #1065353216
 *   @0x16dbd0 mov r0, r5
 *   @0x16dbd4 mov r12, #0
 *   @0x16dbd8 movt r12, #0x46fa
 *   @0x16dbdc str r12, [sp]
 *   @0x16dbe0 bl 0x27b274 <_ZN8yyMatrix7OrthoLHEPS_ffff>
 *   @0x16dbe4 mov r0, r4
 *   @0x16dbe8 mov r1, r6
 *   @0x16dbec bl 0x16da94 <_ZN7CCamera10SetViewMatER8yyMatrix>
 *   @0x16dbf0 mov r0, r4
 *   @0x16dbf4 mov r1, r5
 *   @0x16dbf8 bl 0x16d9e4 <_ZN7CCamera10SetProjMatER8yyMatrix>
 *   @0x16dbfc add sp, sp, #176
 *   @0x16dc00 vpop {d8}
 *   @0x16dc04 pop {r4, r5, r6, pc}
 *   @0x16dc08 vstmialo lr, {s30, s31}
 *
 * ══ §56/159 ogg_sync_buffer  0x234b8c  size 200  50 条（0x234b8c..0x234c54）
 * @func 0x234b8c 0x234c54  size 200  50 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ogg_sync_check / ogg_sync_buffer+0x48 / 0xb6694 / 0xb6c28 / 0xb6544 / ogg_sync_clear
 * 字段偏移 top8: 0x8×4 / 0xc×2 / 0x4×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x234b8c push {r4, r5, r6, lr}
 *   @0x234b90 mov r5, r1
 *   @0x234b94 mov r4, r0
 *   @0x234b98 bl 0x234b80 <ogg_sync_check>
 *   @0x234b9c cmp r0, #0
 *   @0x234ba0 bne 0x234c2c <ogg_sync_buffer+0xa0>
 *   @0x234ba4 ldr r1, [r4, #0xc]
 *   @0x234ba8 ldr r2, [r4, #0x8]
 *   @0x234bac cmp r1, #0
 *   @0x234bb0 beq 0x234bdc <ogg_sync_buffer+0x50>
 *   @0x234bb4 rsb r2, r1, r2
 *   @0x234bb8 str r2, [r4, #0x8]
 *   @0x234bbc cmp r2, #0
 *   @0x234bc0 ble 0x234bd4 <ogg_sync_buffer+0x48>
 *   @0x234bc4 ldr r0, [r4]
 *   @0x234bc8 add r1, r0, r1
 *   @0x234bcc bl 0xb6694 <memmove@plt>
 *   @0x234bd0 ldr r2, [r4, #0x8]
 *   @0x234bd4 mov r3, #0
 *   @0x234bd8 str r3, [r4, #0xc]
 *   @0x234bdc ldr r3, [r4, #0x4]
 *   @0x234be0 ldr r0, [r4]
 *   @0x234be4 rsb r3, r2, r3
 *   @0x234be8 cmp r3, r5
 *   @0x234bec bge 0x234c24 <ogg_sync_buffer+0x98>
 *   @0x234bf0 cmp r0, #0
 *   @0x234bf4 add r5, r5, r2
 *   @0x234bf8 add r5, r5, #4096
 *   @0x234bfc beq 0x234c34 <ogg_sync_buffer+0xa8>
 *   @0x234c00 mov r1, r5
 *   @0x234c04 bl 0xb6c28 <realloc@plt>
 *   @0x234c08 mov r6, r0
 *   @0x234c0c cmp r6, #0
 *   @0x234c10 beq 0x234c44 <ogg_sync_buffer+0xb8>
 *   @0x234c14 ldr r2, [r4, #0x8]
 *   @0x234c18 mov r0, r6
 *   @0x234c1c str r6, [r4]
 *   @0x234c20 str r5, [r4, #0x4]
 *   @0x234c24 add r0, r0, r2
 *   @0x234c28 pop {r4, r5, r6, pc}
 *   @0x234c2c mov r0, #0
 *   @0x234c30 pop {r4, r5, r6, pc}
 *   @0x234c34 mov r0, r5
 *   @0x234c38 bl 0xb6544 <malloc@plt>
 *   @0x234c3c mov r6, r0
 *   @0x234c40 b 0x234c0c <ogg_sync_buffer+0x80>
 *   @0x234c44 mov r0, r4
 *   @0x234c48 bl 0x234b2c <ogg_sync_clear>
 *   @0x234c4c mov r0, r6
 *   @0x234c50 pop {r4, r5, r6, pc}
 *
 * ══ §57/159 spIkConstraint_create  0x285d64  size 200  50 条（0x285d64..0x285e2c）
 * @func 0x285d64 0x285e2c  size 200  50 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spSkeleton_findBone×2 / _calloc / _malloc / spIkConstraint_create+0xa4
 * 字段偏移 top8: 0x4×6 / 0x8×3 / 0x10×2 / 0x14×2 / 0x2×2 / 0xc×2 / 0xb4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x285d64 push {r3, r4, r5, r6, r7, lr}
 *   @0x285d68 mov r4, r0
 *   @0x285d6c ldr r6, [pc, #0xb4]
 *   @0x285d70 mov r3, #40
 *   @0x285d74 mov r7, r1
 *   @0x285d78 mov r0, #1
 *   @0x285d7c add r6, pc, r6
 *   @0x285d80 mov r1, #28
 *   @0x285d84 mov r2, r6
 *   @0x285d88 bl 0x285c4c <_calloc>
 *   @0x285d8c ldr r3, [r4, #0x10]
 *   @0x285d90 ldr r2, [r4, #0x14]
 *   @0x285d94 mov r1, r6
 *   @0x285d98 mov r5, r0
 *   @0x285d9c ldr r0, [r4, #0x4]
 *   @0x285da0 str r2, [r5, #0x14]
 *   @0x285da4 mov r2, #46
 *   @0x285da8 str r3, [r5, #0x10]
 *   @0x285dac str r0, [r5, #0x4]
 *   @0x285db0 lsl r0, r0, #2
 *   @0x285db4 str r4, [r5]
 *   @0x285db8 bl 0x285c10 <_malloc>
 *   @0x285dbc ldr r3, [r5, #0x4]
 *   @0x285dc0 cmp r3, #0
 *   @0x285dc4 str r0, [r5, #0x8]
 *   @0x285dc8 ble 0x285e08 <spIkConstraint_create+0xa4>
 *   @0x285dcc mov r6, r0
 *   @0x285dd0 mov r4, #0
 *   @0x285dd4 b 0x285ddc <spIkConstraint_create+0x78>
 *   @0x285dd8 ldr r6, [r5, #0x8]
 *   @0x285ddc ldr r3, [r5]
 *   @0x285de0 mov r0, r7
 *   @0x285de4 ldr r3, [r3, #0x8]
 *   @0x285de8 ldr r3, [r3, r4, lsl #2]
 *   @0x285dec ldr r1, [r3, #0x4]
 *   @0x285df0 bl 0x28a0c8 <spSkeleton_findBone>
 *   @0x285df4 ldr r3, [r5, #0x4]
 *   @0x285df8 str r0, [r6, r4, lsl #2]
 *   @0x285dfc add r4, r4, #1
 *   @0x285e00 cmp r3, r4
 *   @0x285e04 bgt 0x285dd8 <spIkConstraint_create+0x74>
 *   @0x285e08 ldr r3, [r5]
 *   @0x285e0c mov r0, r7
 *   @0x285e10 ldr r3, [r3, #0xc]
 *   @0x285e14 ldr r1, [r3, #0x4]
 *   @0x285e18 bl 0x28a0c8 <spSkeleton_findBone>
 *   @0x285e1c str r0, [r5, #0xc]
 *   @0x285e20 mov r0, r5
 *   @0x285e24 pop {r3, r4, r5, r6, r7, pc}
 *   @0x285e28 andeq r1, sp, r0, asr #21
 *
 * ══ §58/159 FreeSocket  0x29955c  size 200  50 条（0x29955c..0x299624）
 * @func 0x29955c 0x299624  size 200  50 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)×2 / yySocket::~yySocket() / yyServer::~yyServer()
 * 字段偏移 top8: 0x4×3 / 0x8×2 / 0xb4×1 / 0x1×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29955c push {r3, r4, r5, r6, r7, lr}
 *   @0x299560 mov r3, #0
 *   @0x299564 ldr r4, [pc, #0xb4]
 *   @0x299568 mov r5, r3
 *   @0x29956c ldr r4, [pc, r4]
 *   @0x299570 b 0x299580 <_Z10FreeSocketP8yySocket+0x24>
 *   @0x299574 cmp r3, #768
 *   @0x299578 add r5, r5, #1
 *   @0x29957c beq 0x299618 <_Z10FreeSocketP8yySocket+0xbc>
 *   @0x299580 ldrb r2, [r4, r3]
 *   @0x299584 add r1, r4, r3
 *   @0x299588 add r3, r3, #12
 *   @0x29958c cmp r2, #0
 *   @0x299590 beq 0x299574 <_Z10FreeSocketP8yySocket+0x18>
 *   @0x299594 ldr r2, [r1, #0x4]
 *   @0x299598 cmp r2, r0
 *   @0x29959c bne 0x299574 <_Z10FreeSocketP8yySocket+0x18>
 *   @0x2995a0 lsl r6, r5, #1
 *   @0x2995a4 mov r2, #0
 *   @0x2995a8 add r1, r6, r5
 *   @0x2995ac lsl r1, r1, #2
 *   @0x2995b0 add r3, r4, r1
 *   @0x2995b4 strb r2, [r4, r1]
 *   @0x2995b8 ldr r7, [r3, #0x4]
 *   @0x2995bc strb r2, [r3, #0x1]
 *   @0x2995c0 cmp r7, r2
 *   @0x2995c4 beq 0x2995d8 <_Z10FreeSocketP8yySocket+0x7c>
 *   @0x2995c8 mov r0, r7
 *   @0x2995cc bl 0x294cbc <_ZN8yySocketD2Ev>
 *   @0x2995d0 mov r0, r7
 *   @0x2995d4 bl 0x27d1d0 <_ZdlPv>
 *   @0x2995d8 add r3, r6, r5
 *   @0x2995dc add r3, r4, r3, lsl #2
 *   @0x2995e0 ldr r7, [r3, #0x8]
 *   @0x2995e4 cmp r7, #0
 *   @0x2995e8 beq 0x2995fc <_Z10FreeSocketP8yySocket+0xa0>
 *   @0x2995ec mov r0, r7
 *   @0x2995f0 bl 0x297184 <_ZN8yyServerD2Ev>
 *   @0x2995f4 mov r0, r7
 *   @0x2995f8 bl 0x27d1d0 <_ZdlPv>
 *   @0x2995fc add r6, r6, r5
 *   @0x299600 mov r3, #0
 *   @0x299604 mov r0, r5
 *   @0x299608 add r4, r4, r6, lsl #2
 *   @0x29960c str r3, [r4, #0x4]
 *   @0x299610 str r3, [r4, #0x8]
 *   @0x299614 pop {r3, r4, r5, r6, r7, pc}
 *   @0x299618 mvn r0, #0
 *   @0x29961c pop {r3, r4, r5, r6, r7, pc}
 *   @0x299620 andseq r8, r5, r8, lsr r4
 *
 * ══ §59/159 YYIAPConsumeEvent  0x15556c  size 196  49 条（0x15556c..0x155630）
 * @func 0x15556c 0x155630  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Mutex::Lock() / json_tokener_parse / YYIAPConsumeEvent(char const*)+0x64 / anon_154a70 / anon_153020+0x1ac
 * 字段偏移 top8: 0x4c×2 / 0xa4×1 / 0x7c×1 / 0x78×1 / 0xc×1 / 0x60×1 / 0x4×1 / 0x10×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15556c ldr r3, [pc, #0xa4]
 *   @0x155570 push {r4, lr}
 *   @0x155574 add r3, pc, r3
 *   @0x155578 sub sp, sp, #24
 *   @0x15557c mov r4, r0
 *   @0x155580 ldr r0, [r3]
 *   @0x155584 bl 0x27e084 <_ZN5Mutex4LockEv>
 *   @0x155588 mov r0, r4
 *   @0x15558c bl 0x28075c <json_tokener_parse>
 *   @0x155590 cmn r0, #4000
 *   @0x155594 bls 0x1555d0 <_Z17YYIAPConsumeEventPKc+0x64>
 *   @0x155598 ldr r3, [pc, #0x7c]
 *   @0x15559c mov r2, r4
 *   @0x1555a0 ldr r1, [pc, #0x78]
 *   @0x1555a4 ldr r3, [pc, r3]
 *   @0x1555a8 add r1, pc, r1
 *   @0x1555ac ldr r0, [r3]
 *   @0x1555b0 ldr r3, [r0]
 *   @0x1555b4 ldr r3, [r3, #0xc]
 *   @0x1555b8 blx r3
 *   @0x1555bc ldr r3, [pc, #0x60]
 *   @0x1555c0 ldr r0, [pc, r3]
 *   @0x1555c4 add sp, sp, #24
 *   @0x1555c8 pop {r4, lr}
 *   @0x1555cc b 0x27e09c <_ZN5Mutex6UnlockEv>
 *   @0x1555d0 vmov s13, r0
 *   @0x1555d4 ldr r2, [pc, #0x4c]
 *   @0x1555d8 ldr r1, [pc, #0x4c]
 *   @0x1555dc mov r3, #0
 *   @0x1555e0 vcvt.f64.s32 d7, s13
 *   @0x1555e4 add r2, pc, r2
 *   @0x1555e8 str r3, [sp]
 *   @0x1555ec add r1, pc, r1
 *   @0x1555f0 str r2, [sp, #0x4]
 *   @0x1555f4 mov r0, #2
 *   @0x1555f8 str r3, [sp, #0x10]
 *   @0x1555fc mov r2, #0
 *   @0x155600 mov r3, #0
 *   @0x155604 movt r3, #0x4008
 *   @0x155608 vstr d7, [sp, #8]
 *   @0x15560c bl 0x154a70 <_Z19YYIAPEventsDispatchv+0xe88>
 *   @0x155610 bl 0x1531cc <_Z16F_IAP_StoreStateR6RValueP9CInstanceS2_iPS_+0x1d8>
 *   @0x155614 b 0x1555bc <_Z17YYIAPConsumeEventPKc+0x50>
 *   @0x155618 eorseq pc, r2, r12, asr #9
 *   @0x15561c mlaeq r9, r12, r3, r8
 *   @0x155620 ldrsbeq r0, [pc], -r12
 *   @0x155624 eorseq pc, r2, r0, lsl #9
 *   @0x155628 andseq r0, pc, r12, lsl r12
 *   @0x15562c andseq r0, pc, r12, lsr r11
 *
 * ══ §60/159 GR_D3D_Set_Texture_Interpolation  0x168710  size 196  49 条（0x168710..0x1687d4）
 * @func 0x168710 0x1687d4  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x16871c→0x3f23c0, 0x168728→0x4859c8, 0x168778→0x4859c8
 * 调用序列: RenderStateManager::SetSamplerState(int, eSamplerState, unsigned int)×4
 * 字段偏移 top8: 0xa8×2 / 0xa0×1 / 0x50×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x168710 push {r3, r4, r5, r6, r7, lr}
 *   @0x168714 cmp r0, #0
 *   @0x168718 ldr r3, [pc, #0xa8]
 *   @0x16871c ldr r1, [pc, #0xa8]
 *   @0x168720 add r3, pc, r3
 *   @0x168724 beq 0x168778 <_Z32GR_D3D_Set_Texture_Interpolationb+0x68>
 *   @0x168728 ldr r2, [pc, #0xa0]
 *   @0x16872c mov r4, #0
 *   @0x168730 ldr r6, [r3, r1]
 *   @0x168734 mov r7, #1
 *   @0x168738 ldr r5, [r3, r2]
 *   @0x16873c mov r1, r4
 *   @0x168740 strb r7, [r6, r4]
 *   @0x168744 mov r0, r5
 *   @0x168748 mov r2, #0
 *   @0x16874c mov r3, #1
 *   @0x168750 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej>
 *   @0x168754 mov r2, #1
 *   @0x168758 mov r1, r4
 *   @0x16875c mov r0, r5
 *   @0x168760 add r4, r4, #1
 *   @0x168764 mov r3, r2
 *   @0x168768 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej>
 *   @0x16876c cmp r4, #8
 *   @0x168770 bne 0x16873c <_Z32GR_D3D_Set_Texture_Interpolationb+0x2c>
 *   @0x168774 pop {r3, r4, r5, r6, r7, pc}
 *   @0x168778 ldr r2, [pc, #0x50]
 *   @0x16877c mov r4, r0
 *   @0x168780 ldr r6, [r3, r1]
 *   @0x168784 mov r7, r0
 *   @0x168788 ldr r5, [r3, r2]
 *   @0x16878c mov r2, #0
 *   @0x168790 mov r1, r4
 *   @0x168794 mov r3, r2
 *   @0x168798 strb r7, [r6, r4]
 *   @0x16879c mov r0, r5
 *   @0x1687a0 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej>
 *   @0x1687a4 mov r1, r4
 *   @0x1687a8 mov r0, r5
 *   @0x1687ac add r4, r4, #1
 *   @0x1687b0 mov r2, #1
 *   @0x1687b4 mov r3, #0
 *   @0x1687b8 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej>
 *   @0x1687bc cmp r4, #8
 *   @0x1687c0 bne 0x16878c <_Z32GR_D3D_Set_Texture_Interpolationb+0x7c>
 *   @0x1687c4 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1687c8 eoreq r9, r8, r0, lsr r5
 *   @0x1687cc .word 0xffffe4b8
 *   @0x1687d0 .word 0xffffc0a8
 *
 * ══ §61/159 GR_Surface_Free  0x171ba0  size 196  49 条（0x171ba0..0x171c64）
 * @func 0x171ba0 0x171c64  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics::Flush() / _FreeSurfaceData(int) / operator delete(void*) / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x8×3 / 0x4×2 / 0xa4×1 / 0x94×1 / 0x3×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x171ba0 cmp r1, #0
 *   @0x171ba4 push {r4, r5, r6, lr}
 *   @0x171ba8 mov r5, r0
 *   @0x171bac bne 0x171bc4 <_Z15GR_Surface_Freeib+0x24>
 *   @0x171bb0 ldr r3, [pc, #0xa4]
 *   @0x171bb4 ldr r3, [pc, r3]
 *   @0x171bb8 ldr r3, [r3]
 *   @0x171bbc cmp r3, r0
 *   @0x171bc0 popeq {r4, r5, r6, pc}
 *   @0x171bc4 ldr r6, [pc, #0x94]
 *   @0x171bc8 bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x171bcc mov r0, r5
 *   @0x171bd0 bl 0x171a90 <_Z16_FreeSurfaceDatai>
 *   @0x171bd4 ldr r6, [pc, r6]
 *   @0x171bd8 ldr r1, [r6, #0x4]
 *   @0x171bdc ldr r2, [r6]
 *   @0x171be0 and r1, r5, r1
 *   @0x171be4 ldr r4, [r2, r1, lsl #3]
 *   @0x171be8 add r12, r2, r1, lsl #3
 *   @0x171bec cmp r4, #0
 *   @0x171bf0 bne 0x171c04 <_Z15GR_Surface_Freeib+0x64>
 *   @0x171bf4 pop {r4, r5, r6, pc}
 *   @0x171bf8 ldr r4, [r4, #0x4]
 *   @0x171bfc cmp r4, #0
 *   @0x171c00 beq 0x171c58 <_Z15GR_Surface_Freeib+0xb8>
 *   @0x171c04 ldr r3, [r4, #0x8]
 *   @0x171c08 cmp r5, r3
 *   @0x171c0c bne 0x171bf8 <_Z15GR_Surface_Freeib+0x58>
 *   @0x171c10 ldr r3, [r4]
 *   @0x171c14 cmp r3, #0
 *   @0x171c18 ldrne r2, [r4, #0x4]
 *   @0x171c1c ldreq r0, [r4, #0x4]
 *   @0x171c20 strne r2, [r3, #0x4]
 *   @0x171c24 ldrne r0, [r4, #0x4]
 *   @0x171c28 streq r0, [r2, r1, lsl #3]
 *   @0x171c2c cmp r0, #0
 *   @0x171c30 streq r3, [r12, #0x4]
 *   @0x171c34 strne r3, [r0]
 *   @0x171c38 ldr r0, [r4, #0xc]
 *   @0x171c3c bl 0x27d1d0 <_ZdlPv>
 *   @0x171c40 mov r0, r4
 *   @0x171c44 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x171c48 ldr r3, [r6, #0x8]
 *   @0x171c4c sub r3, r3, #1
 *   @0x171c50 str r3, [r6, #0x8]
 *   @0x171c54 pop {r4, r5, r6, pc}
 *   @0x171c58 pop {r4, r5, r6, pc}
 *   @0x171c5c eoreq r12, r7, r4, lsr #20
 *   @0x171c60 eoreq r11, r7, r12, lsr pc
 *
 * ══ §62/159 GetRValue  0x190dc0  size 196  49 条（0x190dc0..0x190e84）
 * @func 0x190dc0 0x190e84  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int) / 0xb65b0
 * 字段偏移 top8: 0x10×5 / 0x8×3 / 0xc×2 / 0xb4×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x190dc0 push {r4, r5, r6, r7, r8, lr}
 *   @0x190dc4 ldr r4, [pc, #0xb4]
 *   @0x190dc8 ldr r4, [pc, r4]
 *   @0x190dcc ldr r0, [r4, #0x8]
 *   @0x190dd0 cmp r0, #0
 *   @0x190dd4 beq 0x190dfc <_Z9GetRValuev+0x3c>
 *   @0x190dd8 ldr r3, [r4, #0x10]
 *   @0x190ddc ldr r2, [r0]
 *   @0x190de0 ldr r1, [r4, #0xc]
 *   @0x190de4 sub r3, r3, #1
 *   @0x190de8 str r2, [r4, #0x8]
 *   @0x190dec str r3, [r4, #0x10]
 *   @0x190df0 add r3, r1, #1
 *   @0x190df4 str r3, [r4, #0xc]
 *   @0x190df8 pop {r4, r5, r6, r7, r8, pc}
 *   @0x190dfc mov r0, #24
 *   @0x190e00 movt r0, #0x10
 *   @0x190e04 bl 0x27c524 <_Znwj>
 *   @0x190e08 mov r1, #120
 *   @0x190e0c mov r2, #16
 *   @0x190e10 movt r2, #0x10
 *   @0x190e14 mov r5, r0
 *   @0x190e18 add r0, r0, #8
 *   @0x190e1c bl 0xb65b0 <memset@plt>
 *   @0x190e20 ldmib r4, {r7, r8}
 *   @0x190e24 add r1, r5, #24
 *   @0x190e28 ldr r6, [r4, #0x10]
 *   @0x190e2c bic r1, r1, #15
 *   @0x190e30 add r0, r1, #1044480
 *   @0x190e34 str r7, [r5]
 *   @0x190e38 add r12, r0, #4080
 *   @0x190e3c add r7, r6, #1
 *   @0x190e40 str r5, [r4, #0x4]
 *   @0x190e44 add r3, r1, #16
 *   @0x190e48 str r8, [r1]
 *   @0x190e4c mov r2, r1
 *   @0x190e50 str r1, [r4, #0x8]
 *   @0x190e54 str r7, [r4, #0x10]
 *   @0x190e58 b 0x190e60 <_Z9GetRValuev+0xa0>
 *   @0x190e5c mov r2, r1
 *   @0x190e60 mov r1, r3
 *   @0x190e64 str r2, [r3], #16
 *   @0x190e68 cmp r3, r12
 *   @0x190e6c bne 0x190e5c <_Z9GetRValuev+0x9c>
 *   @0x190e70 add r3, r6, #65280
 *   @0x190e74 add r0, r0, #4064
 *   @0x190e78 add r3, r3, #255
 *   @0x190e7c b 0x190de0 <_Z9GetRValuev+0x20>
 *   @0x190e80 eoreq pc, r5, r8, lsr #17
 *
 * ══ §63/159 HandleKeyboard  0x1d5c3c  size 196  49 条（0x1d5c3c..0x1d5d00）
 * @func 0x1d5c3c 0x1d5d00  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: HandleKey(int)×2 / HandleKeyPress(int)×2 / HandleKeyRelease(int)
 * 字段偏移 top8: 0xa8×1 / 0xa4×1 / 0xa0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d5c3c push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1d5c40 mov r9, #0
 *   @0x1d5c44 ldr r7, [pc, #0xa8]
 *   @0x1d5c48 mov r8, r9
 *   @0x1d5c4c ldr r5, [pc, #0xa4]
 *   @0x1d5c50 mov r10, r9
 *   @0x1d5c54 ldr r6, [pc, #0xa0]
 *   @0x1d5c58 ldr r7, [pc, r7]
 *   @0x1d5c5c ldr r5, [pc, r5]
 *   @0x1d5c60 mov r4, #8
 *   @0x1d5c64 ldr r6, [pc, r6]
 *   @0x1d5c68 b 0x1d5c78 <_Z14HandleKeyboardv+0x3c>
 *   @0x1d5c6c add r4, r4, #1
 *   @0x1d5c70 cmp r4, #256
 *   @0x1d5c74 beq 0x1d5cd8 <_Z14HandleKeyboardv+0x9c>
 *   @0x1d5c78 ldrb r3, [r7, r4]
 *   @0x1d5c7c mov r0, r4
 *   @0x1d5c80 cmp r3, #0
 *   @0x1d5c84 bne 0x1d5c94 <_Z14HandleKeyboardv+0x58>
 *   @0x1d5c88 ldrb r3, [r5, r4]
 *   @0x1d5c8c cmp r3, #0
 *   @0x1d5c90 beq 0x1d5cb4 <_Z14HandleKeyboardv+0x78>
 *   @0x1d5c94 bl 0x1d5804 <_Z9HandleKeyi>
 *   @0x1d5c98 ldrb r3, [r5, r4]
 *   @0x1d5c9c mov r0, r4
 *   @0x1d5ca0 mov r10, #1
 *   @0x1d5ca4 cmp r3, #0
 *   @0x1d5ca8 beq 0x1d5cb4 <_Z14HandleKeyboardv+0x78>
 *   @0x1d5cac mov r8, r10
 *   @0x1d5cb0 bl 0x1d5974 <_Z14HandleKeyPressi>
 *   @0x1d5cb4 ldrb r3, [r6, r4]
 *   @0x1d5cb8 cmp r3, #0
 *   @0x1d5cbc beq 0x1d5c6c <_Z14HandleKeyboardv+0x30>
 *   @0x1d5cc0 mov r0, r4
 *   @0x1d5cc4 add r4, r4, #1
 *   @0x1d5cc8 bl 0x1d5ad8 <_Z16HandleKeyReleasei>
 *   @0x1d5ccc cmp r4, #256
 *   @0x1d5cd0 mov r9, #1
 *   @0x1d5cd4 bne 0x1d5c78 <_Z14HandleKeyboardv+0x3c>
 *   @0x1d5cd8 mov r0, r10
 *   @0x1d5cdc bl 0x1d5804 <_Z9HandleKeyi>
 *   @0x1d5ce0 mov r0, r8
 *   @0x1d5ce4 bl 0x1d5974 <_Z14HandleKeyPressi>
 *   @0x1d5ce8 mov r0, r9
 *   @0x1d5cec pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1d5cf0 b 0x1d5ad8 <_Z16HandleKeyReleasei>
 *   @0x1d5cf4 eoreq r10, r1, r8, lsl #19
 *   @0x1d5cf8 eoreq r10, r1, r12, lsl #19
 *   @0x1d5cfc eoreq r10, r1, r0, lsl #19
 *
 * ══ §64/159 CDS_Map::Add4GC  0x2037b4  size 196  49 条（0x2037b4..0x203878）
 * @func 0x2037b4 0x203878  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RVALUE_GC_ADDROOT(RValue const*, CGCGeneration*)×2
 * 字段偏移 top8: 0x4×3 / 0x3×1 / 0xc×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2037b4 push {r4, r5, r6, r7, r8, lr}
 *   @0x2037b8 mov r7, r1
 *   @0x2037bc ldr r8, [r0]
 *   @0x2037c0 mov r5, #0
 *   @0x2037c4 ldr r2, [r8]
 *   @0x2037c8 b 0x2037dc <_ZN7CDS_Map6Add4GCEP13CGCGeneration+0x28>
 *   @0x2037cc ldr r3, [r8, #0x4]
 *   @0x2037d0 add r5, r5, #1
 *   @0x2037d4 cmp r5, r3
 *   @0x2037d8 bgt 0x203868 <_ZN7CDS_Map6Add4GCEP13CGCGeneration+0xb4>
 *   @0x2037dc ldr r4, [r2, r5, lsl #3]
 *   @0x2037e0 cmp r4, #0
 *   @0x2037e4 beq 0x2037cc <_ZN7CDS_Map6Add4GCEP13CGCGeneration+0x18>
 *   @0x2037e8 cmp r4, #0
 *   @0x2037ec popeq {r4, r5, r6, r7, r8, pc}
 *   @0x2037f0 ldr r6, [r4, #0xc]
 *   @0x2037f4 cmp r6, #0
 *   @0x2037f8 beq 0x203860 <_ZN7CDS_Map6Add4GCEP13CGCGeneration+0xac>
 *   @0x2037fc mov r0, r6
 *   @0x203800 mov r1, r7
 *   @0x203804 bl 0x191bac <_Z17RVALUE_GC_ADDROOTPK6RValueP13CGCGeneration>
 *   @0x203808 add r0, r6, #16
 *   @0x20380c mov r1, r7
 *   @0x203810 bl 0x191bac <_Z17RVALUE_GC_ADDROOTPK6RValueP13CGCGeneration>
 *   @0x203814 ldr r4, [r4, #0x4]
 *   @0x203818 cmp r4, #0
 *   @0x20381c bne 0x2037e8 <_ZN7CDS_Map6Add4GCEP13CGCGeneration+0x34>
 *   @0x203820 ldr r0, [r8, #0x4]
 *   @0x203824 add r3, r5, #1
 *   @0x203828 cmp r3, r0
 *   @0x20382c popgt {r4, r5, r6, r7, r8, pc}
 *   @0x203830 ldr r2, [r8]
 *   @0x203834 add r2, r2, r5, lsl #3
 *   @0x203838 b 0x203844 <_ZN7CDS_Map6Add4GCEP13CGCGeneration+0x90>
 *   @0x20383c cmp r3, r0
 *   @0x203840 bgt 0x203864 <_ZN7CDS_Map6Add4GCEP13CGCGeneration+0xb0>
 *   @0x203844 ldr r4, [r2, #0x8]
 *   @0x203848 mov r5, r3
 *   @0x20384c add r2, r2, #8
 *   @0x203850 add r3, r3, #1
 *   @0x203854 cmp r4, #0
 *   @0x203858 beq 0x20383c <_ZN7CDS_Map6Add4GCEP13CGCGeneration+0x88>
 *   @0x20385c b 0x2037e8 <_ZN7CDS_Map6Add4GCEP13CGCGeneration+0x34>
 *   @0x203860 pop {r4, r5, r6, r7, r8, pc}
 *   @0x203864 pop {r4, r5, r6, r7, r8, pc}
 *   @0x203868 cmp r4, #0
 *   @0x20386c mvn r5, #0
 *   @0x203870 bne 0x2037f0 <_ZN7CDS_Map6Add4GCEP13CGCGeneration+0x3c>
 *   @0x203874 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §65/159 MD5Final  0x2141d0  size 196  49 条（0x2141d0..0x214294）
 * @func 0x2141d0 0x214294  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MD5Update(MD5_CTX*, unsigned char*, unsigned int) / anon_21362c
 * 字段偏移 top8: 0x4×2 / 0x3c×1 / 0x9c×1 / 0x38×1 / 0x1a×1 / 0x17×1 / 0x14×1 / 0x15×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2141d0 ldr r1, [r0, #0x4]
 *   @0x2141d4 push {r4, r5, lr}
 *   @0x2141d8 sub sp, sp, #68
 *   @0x2141dc ldr r3, [r0]
 *   @0x2141e0 mov r5, r0
 *   @0x2141e4 str r1, [sp, #0x3c]
 *   @0x2141e8 ubfx r2, r3, #0x3, #0x6
 *   @0x2141ec ldr r1, [pc, #0x9c]
 *   @0x2141f0 cmp r2, #55
 *   @0x2141f4 str r3, [sp, #0x38]
 *   @0x2141f8 rsble r2, r2, #56
 *   @0x2141fc rsbgt r2, r2, #120
 *   @0x214200 add r1, pc, r1
 *   @0x214204 bl 0x214118 <_Z9MD5UpdateP7MD5_CTXPhj>
 *   @0x214208 sub r2, sp, #4
 *   @0x21420c add r0, sp, #52
 *   @0x214210 mov r3, r5
 *   @0x214214 ldrb r1, [r3, #0x1a]
 *   @0x214218 add r3, r3, #4
 *   @0x21421c ldrb r4, [r3, #0x17]
 *   @0x214220 ldrb lr, [r3, #0x14]
 *   @0x214224 ldrb r12, [r3, #0x15]
 *   @0x214228 lsl r1, r1, #16
 *   @0x21422c orr r1, r1, r4, lsl #24
 *   @0x214230 orr r1, r1, lr
 *   @0x214234 orr r1, r1, r12, lsl #8
 *   @0x214238 str r1, [r2, #0x4]!
 *   @0x21423c cmp r2, r0
 *   @0x214240 bne 0x214214 <_Z8MD5FinalP7MD5_CTX+0x44>
 *   @0x214244 add r0, r5, #8
 *   @0x214248 mov r1, sp
 *   @0x21424c bl 0x21362c <_Z7LoadCSVPc+0x104>
 *   @0x214250 mov r0, r5
 *   @0x214254 mov r2, #0
 *   @0x214258 ldr r3, [r0, #0x8]
 *   @0x21425c add r2, r2, #4
 *   @0x214260 cmp r2, #16
 *   @0x214264 add r0, r0, #4
 *   @0x214268 strb r3, [r0, #0x54]
 *   @0x21426c lsr r12, r3, #8
 *   @0x214270 lsr r1, r3, #16
 *   @0x214274 strb r12, [r0, #0x55]
 *   @0x214278 strb r1, [r0, #0x56]
 *   @0x21427c lsr r3, r3, #24
 *   @0x214280 strb r3, [r0, #0x57]
 *   @0x214284 bne 0x214258 <_Z8MD5FinalP7MD5_CTX+0x88>
 *   @0x214288 add sp, sp, #68
 *   @0x21428c pop {r4, r5, pc}
 *   @0x214290 andseq r1, lr, r0, ror r0
 *
 * ══ §66/159 yySocket::SendTo  0x295f28  size 196  49 条（0x295f28..0x295fec）
 * @func 0x295f28 0x295fec  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: yySocket::Resolve(char*)×2 / 0xb6e74 / yySocket::SendTo(char*, int, unsigned char*, int)+0xb4
 * 字段偏移 top8: 0x20×2 / 0x2×2 / 0xc4×1 / 0x4×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x295f28 push {r4, r5, r6, r7, lr}
 *   @0x295f2c mov r4, r0
 *   @0x295f30 ldrb r12, [r4, #0xc4]
 *   @0x295f34 sub sp, sp, #12
 *   @0x295f38 mov r0, r1
 *   @0x295f3c mov r6, r2
 *   @0x295f40 cmp r12, #0
 *   @0x295f44 mov r7, r3
 *   @0x295f48 ldr r5, [sp, #0x20]
 *   @0x295f4c beq 0x295f6c <_ZN8yySocket6SendToEPciPhi+0x44>
 *   @0x295f50 bl 0x2954a8 <_ZN8yySocket7ResolveEPc>
 *   @0x295f54 subs r12, r0, #0
 *   @0x295f58 beq 0x295fcc <_ZN8yySocket6SendToEPciPhi+0xa4>
 *   @0x295f5c rev16 r6, r6
 *   @0x295f60 mov r3, #28
 *   @0x295f64 strh r6, [r12, #2]
 *   @0x295f68 b 0x295f84 <_ZN8yySocket6SendToEPciPhi+0x5c>
 *   @0x295f6c bl 0x2954a8 <_ZN8yySocket7ResolveEPc>
 *   @0x295f70 subs r12, r0, #0
 *   @0x295f74 beq 0x295fbc <_ZN8yySocket6SendToEPciPhi+0x94>
 *   @0x295f78 rev16 r6, r6
 *   @0x295f7c mov r3, #16
 *   @0x295f80 strh r6, [r12, #2]
 *   @0x295f84 ldr r0, [r4]
 *   @0x295f88 mov r1, r7
 *   @0x295f8c str r3, [sp, #0x4]
 *   @0x295f90 mov r2, r5
 *   @0x295f94 str r12, [sp]
 *   @0x295f98 mov r3, #0
 *   @0x295f9c bl 0xb6e74 <sendto@plt>
 *   @0x295fa0 cmp r0, #0
 *   @0x295fa4 blt 0x295fdc <_ZN8yySocket6SendToEPciPhi+0xb4>
 *   @0x295fa8 cmp r5, r0
 *   @0x295fac movle r0, #0
 *   @0x295fb0 mvngt r0, #2
 *   @0x295fb4 add sp, sp, #12
 *   @0x295fb8 pop {r4, r5, r6, r7, pc}
 *   @0x295fbc ldr r3, [pc, #0x20]
 *   @0x295fc0 ldr r3, [pc, r3]
 *   @0x295fc4 ldr r0, [r3]
 *   @0x295fc8 b 0x295fb4 <_ZN8yySocket6SendToEPciPhi+0x8c>
 *   @0x295fcc ldr r3, [pc, #0x14]
 *   @0x295fd0 ldr r3, [pc, r3]
 *   @0x295fd4 ldr r0, [r3]
 *   @0x295fd8 b 0x295fb4 <_ZN8yySocket6SendToEPciPhi+0x8c>
 *   @0x295fdc mvn r0, #1
 *   @0x295fe0 b 0x295fb4 <_ZN8yySocket6SendToEPciPhi+0x8c>
 *   @0x295fe4 ldrsbeq r11, [r5], -r0
 *   @0x295fe8 andseq r11, r5, r0, asr #19
 *
 * ══ §67/159 b2Simplex::Solve2  0x2c3c50  size 196  49 条（0x2c3c50..0x2c3d14）
 * @func 0x2c3c50 0x2c3d14  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Simplex::Solve2()+0xac / b2Simplex::Solve2()+0x74
 * 字段偏移 top8: 0x4×3 / 0x6c×3 / 0x-4×1 / 0x3c×1 / 0x18×1
 * VFP 指令 22 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c3c50 vldr s15, [r0, #20]
 *   @0x2c3c54 vldr s10, [r0, #56]
 *   @0x2c3c58 vsub.f32 s14, s10, s15
 *   @0x2c3c5c vldr s13, [r0, #16]
 *   @0x2c3c60 vldr s11, [r0, #52]
 *   @0x2c3c64 str r4, [sp, #-0x4]!
 *   @0x2c3c68 vmul.f32 s15, s15, s14
 *   @0x2c3c6c vsub.f32 s12, s11, s13
 *   @0x2c3c70 vmla.f32 s15, s13, s12
 *   @0x2c3c74 vneg.f32 s13, s15
 *   @0x2c3c78 vcmpe.f32 s13, #0
 *   @0x2c3c7c vmrs APSR_nzcv, fpscr
 *   @0x2c3c80 bls 0x2c3cfc <_ZN9b2Simplex6Solve2Ev+0xac>
 *   @0x2c3c84 vmul.f32 s14, s10, s14
 *   @0x2c3c88 vmla.f32 s14, s11, s12
 *   @0x2c3c8c vcmpe.f32 s14, #0
 *   @0x2c3c90 vmrs APSR_nzcv, fpscr
 *   @0x2c3c94 bls 0x2c3cc4 <_ZN9b2Simplex6Solve2Ev+0x74>
 *   @0x2c3c98 vsub.f32 s15, s14, s15
 *   @0x2c3c9c mov r3, #2
 *   @0x2c3ca0 ldr r4, [sp], #4
 *   @0x2c3ca4 str r3, [r0, #0x6c]
 *   @0x2c3ca8 vmov.f32 s12, #1.000000e+00
 *   @0x2c3cac vdiv.f32 s15, s12, s15
 *   @0x2c3cb0 vmul.f32 s14, s15, s14
 *   @0x2c3cb4 vmul.f32 s15, s13, s15
 *   @0x2c3cb8 vstr s14, [r0, #24]
 *   @0x2c3cbc vstr s15, [r0, #60]
 *   @0x2c3cc0 bx lr
 *   @0x2c3cc4 add r4, r0, #36
 *   @0x2c3cc8 mov r2, #1065353216
 *   @0x2c3ccc mov r12, r0
 *   @0x2c3cd0 str r2, [r0, #0x3c]
 *   @0x2c3cd4 mov r3, #1
 *   @0x2c3cd8 str r3, [r0, #0x6c]
 *   @0x2c3cdc ldm r4!, {r0, r1, r2, r3}
 *   @0x2c3ce0 stm r12!, {r0, r1, r2, r3}
 *   @0x2c3ce4 ldm r4!, {r0, r1, r2, r3}
 *   @0x2c3ce8 ldr r4, [r4]
 *   @0x2c3cec stm r12!, {r0, r1, r2, r3}
 *   @0x2c3cf0 str r4, [r12]
 *   @0x2c3cf4 ldr r4, [sp], #4
 *   @0x2c3cf8 bx lr
 *   @0x2c3cfc mov r2, #1065353216
 *   @0x2c3d00 mov r3, #1
 *   @0x2c3d04 str r2, [r0, #0x18]
 *   @0x2c3d08 str r3, [r0, #0x6c]
 *   @0x2c3d0c ldr r4, [sp], #4
 *   @0x2c3d10 bx lr
 *
 * ══ §68/159 F_BUFFER_Create  0xc6bb8  size 192  48 条（0xc6bb8..0xc6c78）
 * @func 0xc6bb8 0xc6c78  size 192  48 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / F_BUFFER_Create(RValue&, CInstance*, CInstance*, int, RValue*)+0xa4 / CreateBuffer(int, eBuffer_Format, int)
 * 字段偏移 top8: 0x18×1 / 0xc×1 / 0x4×1 / 0x20×1 / 0x10×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc6bb8 push {r4, r5, r6, r7, r8, lr}
 *   @0xc6bbc mov r5, #0
 *   @0xc6bc0 ldr r6, [sp, #0x18]
 *   @0xc6bc4 mov r1, r5
 *   @0xc6bc8 str r5, [r0, #0xc]
 *   @0xc6bcc mov r4, r0
 *   @0xc6bd0 str r5, [r0]
 *   @0xc6bd4 mov r3, r5
 *   @0xc6bd8 movt r3, #0xbff0
 *   @0xc6bdc str r3, [r0, #0x4]
 *   @0xc6be0 mov r0, r6
 *   @0xc6be4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc6be8 mov r1, #1
 *   @0xc6bec mov r7, r0
 *   @0xc6bf0 mov r0, r6
 *   @0xc6bf4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc6bf8 mov r1, #2
 *   @0xc6bfc mov r8, r0
 *   @0xc6c00 mov r0, r6
 *   @0xc6c04 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc6c08 cmp r7, r5
 *   @0xc6c0c mov r2, r0
 *   @0xc6c10 ble 0xc6c5c <_Z15F_BUFFER_CreateR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0xc6c14 sub r3, r0, #1
 *   @0xc6c18 cmp r3, #1024
 *   @0xc6c1c bhs 0xc6c48 <_Z15F_BUFFER_CreateR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0xc6c20 mov r1, r8
 *   @0xc6c24 mov r0, r7
 *   @0xc6c28 bl 0xc6ad0 <_Z12CreateBufferi14eBuffer_Formati>
 *   @0xc6c2c vmov s15, r0
 *   @0xc6c30 vcvt.f64.s32 d7, s15
 *   @0xc6c34 vmov r0, r1, d7
 *   @0xc6c38 vmov r2, s14
 *   @0xc6c3c mov r3, r1
 *   @0xc6c40 stm r4, {r2, r3}
 *   @0xc6c44 pop {r4, r5, r6, r7, r8, pc}
 *   @0xc6c48 ldr r0, [pc, #0x20]
 *   @0xc6c4c mov r1, r5
 *   @0xc6c50 pop {r4, r5, r6, r7, r8, lr}
 *   @0xc6c54 add r0, pc, r0
 *   @0xc6c58 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc6c5c ldr r0, [pc, #0x10]
 *   @0xc6c60 mov r1, r5
 *   @0xc6c64 pop {r4, r5, r6, r7, r8, lr}
 *   @0xc6c68 add r0, pc, r0
 *   @0xc6c6c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc6c70 .word 0x0026a4b0
 *   @0xc6c74 eoreq r10, r6, r0, lsl #9
 *
 * ══ §69/159 CIAPProduct::SetFromProduct  0x18b04c  size 192  48 条（0x18b04c..0x18b10c）
 * @func 0x18b04c 0x18b10c  size 192  48 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYFree(void const*)×5 / YYStrDup(char const*)×5
 * 字段偏移 top8: 0x4×3 / 0x8×3 / 0xc×3 / 0x10×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18b04c push {r4, r5, r6, lr}
 *   @0x18b050 mov r4, r0
 *   @0x18b054 ldr r0, [r0]
 *   @0x18b058 mov r5, r1
 *   @0x18b05c ldr r6, [r1]
 *   @0x18b060 cmp r0, #0
 *   @0x18b064 beq 0x18b06c <_ZN11CIAPProduct14SetFromProductERKS_+0x20>
 *   @0x18b068 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x18b06c mov r0, r6
 *   @0x18b070 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x18b074 ldr r3, [r4, #0x4]
 *   @0x18b078 cmp r3, #0
 *   @0x18b07c str r0, [r4]
 *   @0x18b080 ldr r6, [r5, #0x4]
 *   @0x18b084 beq 0x18b090 <_ZN11CIAPProduct14SetFromProductERKS_+0x44>
 *   @0x18b088 mov r0, r3
 *   @0x18b08c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x18b090 mov r0, r6
 *   @0x18b094 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x18b098 ldr r3, [r4, #0x8]
 *   @0x18b09c cmp r3, #0
 *   @0x18b0a0 str r0, [r4, #0x4]
 *   @0x18b0a4 ldr r6, [r5, #0x8]
 *   @0x18b0a8 beq 0x18b0b4 <_ZN11CIAPProduct14SetFromProductERKS_+0x68>
 *   @0x18b0ac mov r0, r3
 *   @0x18b0b0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x18b0b4 mov r0, r6
 *   @0x18b0b8 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x18b0bc ldr r3, [r4, #0xc]
 *   @0x18b0c0 cmp r3, #0
 *   @0x18b0c4 str r0, [r4, #0x8]
 *   @0x18b0c8 ldr r6, [r5, #0xc]
 *   @0x18b0cc beq 0x18b0d8 <_ZN11CIAPProduct14SetFromProductERKS_+0x8c>
 *   @0x18b0d0 mov r0, r3
 *   @0x18b0d4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x18b0d8 mov r0, r6
 *   @0x18b0dc bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x18b0e0 ldr r3, [r4, #0x10]
 *   @0x18b0e4 cmp r3, #0
 *   @0x18b0e8 str r0, [r4, #0xc]
 *   @0x18b0ec ldr r5, [r5, #0x10]
 *   @0x18b0f0 beq 0x18b0fc <_ZN11CIAPProduct14SetFromProductERKS_+0xb0>
 *   @0x18b0f4 mov r0, r3
 *   @0x18b0f8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x18b0fc mov r0, r5
 *   @0x18b100 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x18b104 str r0, [r4, #0x10]
 *   @0x18b108 pop {r4, r5, r6, pc}
 *
 * ══ §70/159 ParticleSystem_RemoveAllFromLayers  0x1a5cd8  size 192  48 条（0x1a5cd8..0x1a5d98）
 * @func 0x1a5cd8 0x1a5d98  size 192  48 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleSystem_RemoveAllFromLayers()+0xb0 / CLayerManager::RemoveElement(CRoom*, int, bool, bool) / ParticleSystem_Destroy(int)
 * 字段偏移 top8: 0x4×2 / 0x2c×2 / 0xa8×1 / 0x98×1 / 0x64×1 / 0x2×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a5cd8 push {r3, r4, r5, r6, r7, lr}
 *   @0x1a5cdc ldr r3, [pc, #0xa8]
 *   @0x1a5ce0 ldr r3, [pc, r3]
 *   @0x1a5ce4 ldrb r3, [r3]
 *   @0x1a5ce8 cmp r3, #0
 *   @0x1a5cec popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1a5cf0 ldr r5, [pc, #0x98]
 *   @0x1a5cf4 ldr r5, [pc, r5]
 *   @0x1a5cf8 ldr r3, [r5]
 *   @0x1a5cfc cmp r3, #0
 *   @0x1a5d00 pople {r3, r4, r5, r6, r7, pc}
 *   @0x1a5d04 mov r4, #0
 *   @0x1a5d08 mvn r6, #0
 *   @0x1a5d0c b 0x1a5d20 <_Z34ParticleSystem_RemoveAllFromLayersv+0x48>
 *   @0x1a5d10 ldr r3, [r5]
 *   @0x1a5d14 add r4, r4, #1
 *   @0x1a5d18 cmp r3, r4
 *   @0x1a5d1c ble 0x1a5d88 <_Z34ParticleSystem_RemoveAllFromLayersv+0xb0>
 *   @0x1a5d20 ldr r1, [r5, #0x4]
 *   @0x1a5d24 mov r3, #0
 *   @0x1a5d28 ldr r12, [pc, #0x64]
 *   @0x1a5d2c mov r2, #1
 *   @0x1a5d30 lsl r7, r4, #2
 *   @0x1a5d34 ldr r0, [r1, r4, lsl #2]
 *   @0x1a5d38 cmp r0, r3
 *   @0x1a5d3c beq 0x1a5d10 <_Z34ParticleSystem_RemoveAllFromLayersv+0x38>
 *   @0x1a5d40 ldr r1, [r0, #0x2c]
 *   @0x1a5d44 cmn r1, #1
 *   @0x1a5d48 beq 0x1a5d64 <_Z34ParticleSystem_RemoveAllFromLayersv+0x8c>
 *   @0x1a5d4c ldr r12, [pc, r12]
 *   @0x1a5d50 ldr r0, [r12]
 *   @0x1a5d54 bl 0x1c013c <_ZN13CLayerManager13RemoveElementEP5CRoomibb>
 *   @0x1a5d58 ldr r3, [r5, #0x4]
 *   @0x1a5d5c ldr r0, [r3, r7]
 *   @0x1a5d60 str r6, [r0, #0x2c]
 *   @0x1a5d64 ldrb r3, [r0, #0x34]
 *   @0x1a5d68 cmp r3, #0
 *   @0x1a5d6c beq 0x1a5d10 <_Z34ParticleSystem_RemoveAllFromLayersv+0x38>
 *   @0x1a5d70 mov r0, r4
 *   @0x1a5d74 add r4, r4, #1
 *   @0x1a5d78 bl 0x1a454c <_Z22ParticleSystem_Destroyi>
 *   @0x1a5d7c ldr r3, [r5]
 *   @0x1a5d80 cmp r3, r4
 *   @0x1a5d84 bgt 0x1a5d20 <_Z34ParticleSystem_RemoveAllFromLayersv+0x48>
 *   @0x1a5d88 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1a5d8c eoreq r7, r4, r4, asr #24
 *   @0x1a5d90 eoreq r10, r4, r4, asr #21
 *   @0x1a5d94 .word 0x00247bdc
 *
 * ══ §71/159 RelySendData  0x299ff8  size 192  48 条（0x299ff8..0x29a0b8）
 * @func 0x299ff8 0x29a0b8  size 192  48 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYSetString(RValue*, char const*) / GetIBuffer(int) / F_NETWORK_Send_UDP_Raw(RValue&, CInstance*, CInstance*, int, RValue*) / YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0xc×2 / 0x8×2 / 0x2c×1 / 0x4c×1 / 0x5c×1 / 0x78×1 / 0x6c×1
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x299ff8 vmov s13, r0
 *   @0x299ffc push {r4, lr}
 *   @0x29a000 vcvt.f64.s32 d5, s13
 *   @0x29a004 sub sp, sp, #112
 *   @0x29a008 mov r4, #0
 *   @0x29a00c add r0, sp, #48
 *   @0x29a010 str r2, [sp, #0xc]
 *   @0x29a014 str r3, [sp, #0x8]
 *   @0x29a018 str r4, [sp, #0x2c]
 *   @0x29a01c vstr d5, [sp, #32]
 *   @0x29a020 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x29a024 ldr r3, [sp, #0x8]
 *   @0x29a028 ldr r2, [sp, #0xc]
 *   @0x29a02c str r4, [sp, #0x4c]
 *   @0x29a030 vmov s11, r3
 *   @0x29a034 mov r0, r3
 *   @0x29a038 vmov s15, r2
 *   @0x29a03c str r4, [sp, #0x5c]
 *   @0x29a040 vcvt.f64.s32 d6, s15
 *   @0x29a044 vcvt.f64.s32 d7, s11
 *   @0x29a048 vstr d6, [sp, #64]
 *   @0x29a04c vstr d7, [sp, #80]
 *   @0x29a050 bl 0xc6720 <_Z10GetIBufferi>
 *   @0x29a054 cmp r0, #0
 *   @0x29a058 beq 0x29a0b0 <_Z12RelySendDataiPKciii+0xb8>
 *   @0x29a05c ldr r3, [sp, #0x78]
 *   @0x29a060 mov r1, #0
 *   @0x29a064 str r4, [sp, #0x6c]
 *   @0x29a068 add r4, sp, #16
 *   @0x29a06c cmn r3, #1
 *   @0x29a070 vldreq s14, [r0, #32]
 *   @0x29a074 vldrne s11, [sp, #120]
 *   @0x29a078 mov r2, r1
 *   @0x29a07c vcvteq.f64.s32 d7, s14
 *   @0x29a080 mov r0, r4
 *   @0x29a084 add r3, sp, #32
 *   @0x29a088 str r3, [sp]
 *   @0x29a08c mov r3, #5
 *   @0x29a090 vcvtne.f64.s32 d7, s11
 *   @0x29a094 vstr d7, [sp, #96]
 *   @0x29a098 bl 0x299f40 <_Z22F_NETWORK_Send_UDP_RawR6RValueP9CInstanceS2_iPS_>
 *   @0x29a09c mov r0, r4
 *   @0x29a0a0 mov r1, #0
 *   @0x29a0a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x29a0a8 add sp, sp, #112
 *   @0x29a0ac pop {r4, pc}
 *   @0x29a0b0 mvn r0, #0
 *   @0x29a0b4 b 0x29a0a8 <_Z12RelySendDataiPKciii+0xb0>
 *
 * ══ §72/159 CLayerManager::SortDeactivatedInstances  0x1b8bfc  size 188  47 条（0x1b8bfc..0x1b8cb8）
 * @func 0x1b8bfc 0x1b8ccc  size 208  52 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x-4×1 / 0x5c×1 / 0x18×1 / 0x20×1 / 0x69×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b8bfc cmp r0, #0
 *   @0x1b8c00 str r4, [sp, #-0x4]!
 *   @0x1b8c04 beq 0x1b8cb0 <_ZN13CLayerManager24SortDeactivatedInstancesEP6CLayer+0xb4>
 *   @0x1b8c08 ldr r3, [r0, #0x5c]
 *   @0x1b8c0c cmp r3, #0
 *   @0x1b8c10 beq 0x1b8cb0 <_ZN13CLayerManager24SortDeactivatedInstancesEP6CLayer+0xb4>
 *   @0x1b8c14 mov r4, #0
 *   @0x1b8c18 b 0x1b8c28 <_ZN13CLayerManager24SortDeactivatedInstancesEP6CLayer+0x2c>
 *   @0x1b8c1c cmp r2, #0
 *   @0x1b8c20 beq 0x1b8cb0 <_ZN13CLayerManager24SortDeactivatedInstancesEP6CLayer+0xb4>
 *   @0x1b8c24 mov r3, r2
 *   @0x1b8c28 ldr r1, [r3]
 *   @0x1b8c2c ldr r2, [r3, #0x18]
 *   @0x1b8c30 cmp r1, #2
 *   @0x1b8c34 bne 0x1b8c1c <_ZN13CLayerManager24SortDeactivatedInstancesEP6CLayer+0x20>
 *   @0x1b8c38 ldr r1, [r3, #0x20]
 *   @0x1b8c3c cmp r1, #0
 *   @0x1b8c40 beq 0x1b8c1c <_ZN13CLayerManager24SortDeactivatedInstancesEP6CLayer+0x20>
 *   @0x1b8c44 ldrb r1, [r1, #0x69]
 *   @0x1b8c48 cmp r1, #0
 *   @0x1b8c4c beq 0x1b8c1c <_ZN13CLayerManager24SortDeactivatedInstancesEP6CLayer+0x20>
 *   @0x1b8c50 cmp r2, #0
 *   @0x1b8c54 ldrne r1, [r3, #0x14]
 *   @0x1b8c58 moveq r1, r2
 *   @0x1b8c5c ldreq r12, [r3, #0x14]
 *   @0x1b8c60 strne r1, [r2, #0x14]
 *   @0x1b8c64 ldrne r12, [r3, #0x14]
 *   @0x1b8c68 ldrne r1, [r3, #0x18]
 *   @0x1b8c6c streq r12, [r0, #0x58]
 *   @0x1b8c70 cmp r12, #0
 *   @0x1b8c74 streq r1, [r0, #0x5c]
 *   @0x1b8c78 strne r1, [r12, #0x18]
 *   @0x1b8c7c ldrne r1, [r0, #0x5c]
 *   @0x1b8c80 cmp r1, #0
 *   @0x1b8c84 streq r3, [r0, #0x5c]
 *   @0x1b8c88 strne r3, [r1, #0x14]
 *   @0x1b8c8c ldrne r1, [r0, #0x5c]
 *   @0x1b8c90 streq r3, [r0, #0x58]
 *   @0x1b8c94 streq r1, [r3, #0x18]
 *   @0x1b8c98 strne r1, [r3, #0x18]
 *   @0x1b8c9c streq r1, [r3, #0x14]
 *   @0x1b8ca0 strne r3, [r0, #0x5c]
 *   @0x1b8ca4 strne r4, [r3, #0x14]
 *   @0x1b8ca8 cmp r2, #0
 *   @0x1b8cac bne 0x1b8c24 <_ZN13CLayerManager24SortDeactivatedInstancesEP6CLayer+0x28>
 *   @0x1b8cb0 ldr r4, [sp], #4
 *   @0x1b8cb4 bx lr
 *
 * ══ §73/159 CPhysicsFixture::AddShapePoint  0x236ac8  size 188  47 条（0x236ac8..0x236b84）
 * @func 0x236ac8 0x236b98  size 208  52 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsFixture::AllocVertices(int)
 * 字段偏移 top8: 0x4×5 / 0xc×5 / 0x14×2 / 0x20×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x236ac8 ldr r3, [r0, #0x20]
 *   @0x236acc push {r4, r5, lr}
 *   @0x236ad0 mov r4, r0
 *   @0x236ad4 ldr r3, [r3]
 *   @0x236ad8 sub sp, sp, #12
 *   @0x236adc mov r5, r1
 *   @0x236ae0 ldr r3, [r3, #0x4]
 *   @0x236ae4 cmp r3, #2
 *   @0x236ae8 beq 0x236b34 <_ZN15CPhysicsFixture13AddShapePointEff+0x6c>
 *   @0x236aec cmp r3, #3
 *   @0x236af0 beq 0x236b00 <_ZN15CPhysicsFixture13AddShapePointEff+0x38>
 *   @0x236af4 mov r0, #0
 *   @0x236af8 add sp, sp, #12
 *   @0x236afc pop {r4, r5, pc}
 *   @0x236b00 ldr r3, [r0, #0xc]
 *   @0x236b04 ldr r1, [r0, #0x10]
 *   @0x236b08 cmp r3, r1
 *   @0x236b0c bge 0x236b64 <_ZN15CPhysicsFixture13AddShapePointEff+0x9c>
 *   @0x236b10 ldr r1, [r4, #0x14]
 *   @0x236b14 add r12, r3, #1
 *   @0x236b18 mov r0, #1
 *   @0x236b1c str r12, [r4, #0xc]
 *   @0x236b20 add r3, r1, r3, lsl #3
 *   @0x236b24 str r5, [r3]
 *   @0x236b28 str r2, [r3, #0x4]
 *   @0x236b2c add sp, sp, #12
 *   @0x236b30 pop {r4, r5, pc}
 *   @0x236b34 ldr r3, [r0, #0xc]
 *   @0x236b38 cmp r3, #7
 *   @0x236b3c bgt 0x236af4 <_ZN15CPhysicsFixture13AddShapePointEff+0x2c>
 *   @0x236b40 ldr r1, [r0, #0x14]
 *   @0x236b44 add r12, r3, #1
 *   @0x236b48 str r12, [r0, #0xc]
 *   @0x236b4c add r3, r1, r3, lsl #3
 *   @0x236b50 str r5, [r3]
 *   @0x236b54 str r2, [r3, #0x4]
 *   @0x236b58 add sp, sp, #12
 *   @0x236b5c pop {r4, r5, lr}
 *   @0x236b60 b 0x2369dc <_ZN15CPhysicsFixture21CheckPolygonIntegrityEv>
 *   @0x236b64 add r3, r3, r3, lsl #1
 *   @0x236b68 str r2, [sp, #0x4]
 *   @0x236b6c add r1, r3, r3, lsr #31
 *   @0x236b70 asr r1, r1, #1
 *   @0x236b74 bl 0x23658c <_ZN15CPhysicsFixture13AllocVerticesEi>
 *   @0x236b78 ldr r3, [r4, #0xc]
 *   @0x236b7c ldr r2, [sp, #0x4]
 *   @0x236b80 b 0x236b10 <_ZN15CPhysicsFixture13AddShapePointEff+0x48>
 *
 * ══ §74/159 CPhysicsObject::GetFixtureIndex  0x237708  size 188  47 条（0x237708..0x2377c4）
 * @func 0x237708 0x2377c4  size 188  47 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x8×3 / 0x18×2 / 0x74×1 / 0x4×1 / 0x1c×1 / 0x64×1 / 0x3×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x237708 ldr r2, [r0]
 *   @0x23770c push {r4, r5, r6, r7, r8, lr}
 *   @0x237710 ldr r4, [r2, #0x74]
 *   @0x237714 ldr r5, [r0, #0x18]
 *   @0x237718 cmp r4, r1
 *   @0x23771c cmpne r4, #0
 *   @0x237720 add r2, r5, #1
 *   @0x237724 str r2, [r0, #0x18]
 *   @0x237728 beq 0x23773c <_ZN14CPhysicsObject15GetFixtureIndexEP9b2Fixture+0x34>
 *   @0x23772c ldr r4, [r4, #0x4]
 *   @0x237730 cmp r1, r4
 *   @0x237734 cmpne r4, #0
 *   @0x237738 bne 0x23772c <_ZN14CPhysicsObject15GetFixtureIndexEP9b2Fixture+0x24>
 *   @0x23773c cmp r4, r1
 *   @0x237740 beq 0x23774c <_ZN14CPhysicsObject15GetFixtureIndexEP9b2Fixture+0x44>
 *   @0x237744 mov r0, r5
 *   @0x237748 pop {r4, r5, r6, r7, r8, pc}
 *   @0x23774c ldr r6, [r0, #0x1c]
 *   @0x237750 movw r2, #0x132
 *   @0x237754 ldr r1, [pc, #0x64]
 *   @0x237758 mov r3, #1
 *   @0x23775c mov r0, #16
 *   @0x237760 add r1, pc, r1
 *   @0x237764 ldm r6, {r7, r8}
 *   @0x237768 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x23776c and r8, r5, r8
 *   @0x237770 ldr r2, [r7, r8, lsl #3]
 *   @0x237774 add r3, r7, r8, lsl #3
 *   @0x237778 cmp r2, #0
 *   @0x23777c ldrne r2, [r3, #0x4]
 *   @0x237780 movne r1, #0
 *   @0x237784 str r5, [r0, #0x8]
 *   @0x237788 str r4, [r0, #0xc]
 *   @0x23778c strne r2, [r0]
 *   @0x237790 streq r0, [r3, #0x4]
 *   @0x237794 strne r0, [r2, #0x4]
 *   @0x237798 strne r0, [r3, #0x4]
 *   @0x23779c ldr r3, [r6, #0x8]
 *   @0x2377a0 streq r0, [r7, r8, lsl #3]
 *   @0x2377a4 strne r1, [r0, #0x4]
 *   @0x2377a8 add r3, r3, #1
 *   @0x2377ac streq r2, [r0, #0x4]
 *   @0x2377b0 streq r2, [r0]
 *   @0x2377b4 mov r0, r5
 *   @0x2377b8 str r3, [r6, #0x8]
 *   @0x2377bc pop {r4, r5, r6, r7, r8, pc}
 *   @0x2377c0 andseq r5, r1, r12, asr #10
 *
 * ══ §75/159 b2d_D2A  0x23d968  size 188  47 条（0x23d968..0x23da24）
 * @func 0x23d968 0x23da24  size 188  47 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: hi0bits_D2A
 * 字段偏移 top8: 0x10×1 / 0x-4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23d968 push {r4, r5, r6, r7, r8, lr}
 *   @0x23d96c add r6, r0, #20
 *   @0x23d970 ldr r4, [r0, #0x10]
 *   @0x23d974 mov r8, r1
 *   @0x23d978 add r4, r6, r4, lsl #2
 *   @0x23d97c sub r7, r4, #4
 *   @0x23d980 ldr r5, [r4, #-0x4]
 *   @0x23d984 mov r0, r5
 *   @0x23d988 bl 0x23d41c <hi0bits_D2A>
 *   @0x23d98c cmp r0, #10
 *   @0x23d990 rsb r3, r0, #32
 *   @0x23d994 str r3, [r8]
 *   @0x23d998 bgt 0x23d9d0 <b2d_D2A+0x68>
 *   @0x23d99c rsb r1, r0, #11
 *   @0x23d9a0 cmp r6, r7
 *   @0x23d9a4 lsr r12, r5, r1
 *   @0x23d9a8 add r0, r0, #21
 *   @0x23d9ac orr r12, r12, #1069547520
 *   @0x23d9b0 movhs r1, #0
 *   @0x23d9b4 orr r3, r12, #3145728
 *   @0x23d9b8 ldrlo r12, [r4, #-0x8]
 *   @0x23d9bc lsrlo r1, r12, r1
 *   @0x23d9c0 orr r2, r1, r5, lsl r0
 *   @0x23d9c4 mov r0, r2
 *   @0x23d9c8 mov r1, r3
 *   @0x23d9cc pop {r4, r5, r6, r7, r8, pc}
 *   @0x23d9d0 cmp r6, r7
 *   @0x23d9d4 sublo r7, r4, #8
 *   @0x23d9d8 ldrlo r1, [r4, #-0x8]
 *   @0x23d9dc movhs r1, #0
 *   @0x23d9e0 subs r12, r0, #11
 *   @0x23d9e4 beq 0x23da14 <b2d_D2A+0xac>
 *   @0x23d9e8 cmp r7, r6
 *   @0x23d9ec lsl r5, r5, r12
 *   @0x23d9f0 orr r5, r5, #1069547520
 *   @0x23d9f4 rsb r0, r0, #43
 *   @0x23d9f8 ldrhi r4, [r7, #-0x4]
 *   @0x23d9fc orr r5, r5, #3145728
 *   @0x23da00 orr r3, r5, r1, lsr r0
 *   @0x23da04 movls r0, #0
 *   @0x23da08 lsrhi r0, r4, r0
 *   @0x23da0c orr r2, r0, r1, lsl r12
 *   @0x23da10 b 0x23d9c4 <b2d_D2A+0x5c>
 *   @0x23da14 orr r5, r5, #1069547520
 *   @0x23da18 mov r2, r1
 *   @0x23da1c orr r3, r5, #3145728
 *   @0x23da20 b 0x23d9c4 <b2d_D2A+0x5c>
 *
 * ══ §76/159 CCodepointIterator_UTF8::GetNext  0x242408  size 188  47 条（0x242408..0x2424c4）
 * @func 0x242408 0x2424c4  size 188  47 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×7 / 0x1×3 / 0x2×2 / 0x-4×1 / 0x3×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x242408 ldr r3, [r0, #0x4]
 *   @0x24240c mov r2, r0
 *   @0x242410 str r4, [sp, #-0x4]!
 *   @0x242414 ldrb r0, [r3]
 *   @0x242418 tst r0, #128
 *   @0x24241c addeq r3, r3, #1
 *   @0x242420 streq r3, [r2, #0x4]
 *   @0x242424 beq 0x242460 <_ZN23CCodepointIterator_UTF87GetNextEv+0x58>
 *   @0x242428 tst r0, #16
 *   @0x24242c bne 0x242468 <_ZN23CCodepointIterator_UTF87GetNextEv+0x60>
 *   @0x242430 tst r0, #32
 *   @0x242434 beq 0x2424a4 <_ZN23CCodepointIterator_UTF87GetNextEv+0x9c>
 *   @0x242438 ldrb r12, [r3, #0x1]
 *   @0x24243c lsl r0, r0, #12
 *   @0x242440 ldrb r1, [r3, #0x2]
 *   @0x242444 add r3, r3, #3
 *   @0x242448 and r12, r12, #63
 *   @0x24244c uxth r0, r0
 *   @0x242450 and r1, r1, #63
 *   @0x242454 str r3, [r2, #0x4]
 *   @0x242458 add r0, r0, r12, lsl #6
 *   @0x24245c add r0, r0, r1
 *   @0x242460 ldr r4, [sp], #4
 *   @0x242464 bx lr
 *   @0x242468 ldrb r12, [r3, #0x1]
 *   @0x24246c and r0, r0, #7
 *   @0x242470 ldrb r1, [r3, #0x2]
 *   @0x242474 add r4, r3, #4
 *   @0x242478 and r12, r12, #63
 *   @0x24247c ldrb r3, [r3, #0x3]
 *   @0x242480 and r1, r1, #63
 *   @0x242484 str r4, [r2, #0x4]
 *   @0x242488 lsl r2, r12, #12
 *   @0x24248c and r3, r3, #63
 *   @0x242490 add r0, r2, r0, lsl #18
 *   @0x242494 ldr r4, [sp], #4
 *   @0x242498 add r0, r0, r1, lsl #6
 *   @0x24249c add r0, r0, r3
 *   @0x2424a0 bx lr
 *   @0x2424a4 ldrb r1, [r3, #0x1]
 *   @0x2424a8 and r0, r0, #31
 *   @0x2424ac add r3, r3, #2
 *   @0x2424b0 str r3, [r2, #0x4]
 *   @0x2424b4 and r3, r1, #63
 *   @0x2424b8 ldr r4, [sp], #4
 *   @0x2424bc add r0, r3, r0, lsl #6
 *   @0x2424c0 bx lr
 *
 * ══ §77/159 b2World::CreateBody  0x2c903c  size 188  47 条（0x2c903c..0x2c90f8）
 * @func 0x2c903c 0x2c90f8  size 188  47 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2BlockAllocator::Allocate(int) / b2Body::b2Body(b2BodyDef const*, b2World*)
 * 字段偏移 top8: 0xa0×1 / 0x90×1 / 0x6c×1 / 0x70×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c903c push {r4, r5, r6, lr}
 *   @0x2c9040 movw r5, #0x91d4
 *   @0x2c9044 movt r5, #0x1
 *   @0x2c9048 ldr r3, [pc, #0xa0]
 *   @0x2c904c mov r4, r0
 *   @0x2c9050 mov r6, r1
 *   @0x2c9054 ldr r0, [r0, r5]
 *   @0x2c9058 ldr r3, [pc, r3]
 *   @0x2c905c ldr r1, [pc, #0x90]
 *   @0x2c9060 eor r0, r0, #2
 *   @0x2c9064 ldr r3, [r3]
 *   @0x2c9068 add r1, pc, r1
 *   @0x2c906c ubfx r0, r0, #0x1, #0x1
 *   @0x2c9070 blx r3
 *   @0x2c9074 ldr r3, [r4, r5]
 *   @0x2c9078 tst r3, #2
 *   @0x2c907c bne 0x2c90e8 <_ZN7b2World10CreateBodyEPK9b2BodyDef+0xac>
 *   @0x2c9080 mov r0, r4
 *   @0x2c9084 mov r1, #168
 *   @0x2c9088 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi>
 *   @0x2c908c subs r5, r0, #0
 *   @0x2c9090 beq 0x2c90a0 <_ZN7b2World10CreateBodyEPK9b2BodyDef+0x64>
 *   @0x2c9094 mov r1, r6
 *   @0x2c9098 mov r2, r4
 *   @0x2c909c bl 0x2c6a80 <_ZN6b2BodyC2EPK9b2BodyDefP7b2World>
 *   @0x2c90a0 movw r3, #0x9228
 *   @0x2c90a4 movt r3, #0x1
 *   @0x2c90a8 mov r2, #0
 *   @0x2c90ac str r2, [r5, #0x6c]
 *   @0x2c90b0 ldr r3, [r4, r3]
 *   @0x2c90b4 mov r0, r5
 *   @0x2c90b8 cmp r3, r2
 *   @0x2c90bc movw r2, #0x9228
 *   @0x2c90c0 str r3, [r5, #0x70]
 *   @0x2c90c4 movt r2, #0x1
 *   @0x2c90c8 strne r5, [r3, #0x6c]
 *   @0x2c90cc movw r3, #0x9230
 *   @0x2c90d0 movt r3, #0x1
 *   @0x2c90d4 ldr r1, [r4, r3]
 *   @0x2c90d8 str r5, [r4, r2]
 *   @0x2c90dc add r2, r1, #1
 *   @0x2c90e0 str r2, [r4, r3]
 *   @0x2c90e4 pop {r4, r5, r6, pc}
 *   @0x2c90e8 mov r0, #0
 *   @0x2c90ec pop {r4, r5, r6, pc}
 *   @0x2c90f0 andseq r8, r2, r0, ror r4
 *   @0x2c90f4 andeq r4, r9, r12, ror #4
 *
 * ══ §78/159 CSkeletonInstance::ComputeBoundingBox  0xbeda8  size 184  46 条（0xbeda8..0xbee60）
 * @func 0xbeda8 0xbee60  size 184  46 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CSkeletonInstance::ComputeBoundingBox(tagYYRECT*, int, float, float, float, float, float)+0xac / CSkeletonInstance::SetAnimationTransform(int, float, float, float, float, float, CInstance*)
 * 字段偏移 top8: 0x20×3 / 0xc×1
 * VFP 指令 23 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xbeda8 ldr r12, [r0, #0x20]
 *   @0xbedac push {r4, r5, lr}
 *   @0xbedb0 cmp r12, #0
 *   @0xbedb4 sub sp, sp, #20
 *   @0xbedb8 mov r5, r0
 *   @0xbedbc mov r4, r1
 *   @0xbedc0 beq 0xbee54 <_ZN17CSkeletonInstance18ComputeBoundingBoxEP9tagYYRECTifffff+0xac>
 *   @0xbedc4 ldr r12, [r12]
 *   @0xbedc8 cmp r12, #0
 *   @0xbedcc ble 0xbee54 <_ZN17CSkeletonInstance18ComputeBoundingBoxEP9tagYYRECTifffff+0xac>
 *   @0xbedd0 vldr s15, [sp, #36]
 *   @0xbedd4 mov r1, r2
 *   @0xbedd8 vstr s15, [sp]
 *   @0xbeddc mov r2, r3
 *   @0xbede0 vldr s15, [sp, #40]
 *   @0xbede4 mov r12, #0
 *   @0xbede8 vstr s15, [sp, #4]
 *   @0xbedec ldr r3, [sp, #0x20]
 *   @0xbedf0 vldr s15, [sp, #44]
 *   @0xbedf4 str r12, [sp, #0xc]
 *   @0xbedf8 vstr s15, [sp, #8]
 *   @0xbedfc bl 0xbe80c <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance>
 *   @0xbee00 vmov.f32 s15, #5.000000e-01
 *   @0xbee04 ldr r3, [r5, #0x20]
 *   @0xbee08 vldr s12, [r3, #12]
 *   @0xbee0c vldr s13, [r3, #20]
 *   @0xbee10 vldr s14, [r3, #16]
 *   @0xbee14 vldr s11, [r3, #24]
 *   @0xbee18 mov r0, #1
 *   @0xbee1c vadd.f32 s12, s12, s15
 *   @0xbee20 vadd.f32 s13, s13, s15
 *   @0xbee24 vadd.f32 s14, s14, s15
 *   @0xbee28 vadd.f32 s15, s11, s15
 *   @0xbee2c vcvt.s32.f32 s12, s12
 *   @0xbee30 vcvt.s32.f32 s13, s13
 *   @0xbee34 vstr s12, [r4]
 *   @0xbee38 vcvt.s32.f32 s14, s14
 *   @0xbee3c vstr s13, [r4, #8]
 *   @0xbee40 vcvt.s32.f32 s15, s15
 *   @0xbee44 vstr s14, [r4, #4]
 *   @0xbee48 vstr s15, [r4, #12]
 *   @0xbee4c add sp, sp, #20
 *   @0xbee50 pop {r4, r5, pc}
 *   @0xbee54 mov r0, #0
 *   @0xbee58 add sp, sp, #20
 *   @0xbee5c pop {r4, r5, pc}
 *
 * ══ §79/159 TErrStreamConsole::Output  0xd3788  size 184  46 条（0xd3788..0xd3840）
 * @func 0xd3788 0xd3840  size 184  46 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6538×2 / 0xb6610 / TErrStreamConsole::Output(char const*, ...)+0x94 / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool) / 0xb6628
 * 字段偏移 top8: 0x8×2 / 0x4×2 / 0x98×1 / 0x24×1 / 0xc×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd3788 push {r1, r2, r3}
 *   @0xd378c mov r1, #16384
 *   @0xd3790 push {r4, r5, r6, r7, lr}
 *   @0xd3794 sub sp, sp, #16
 *   @0xd3798 ldr r4, [pc, #0x98]
 *   @0xd379c add r12, sp, #40
 *   @0xd37a0 ldr r2, [sp, #0x24]
 *   @0xd37a4 mov r5, r0
 *   @0xd37a8 ldr r4, [pc, r4]
 *   @0xd37ac mov r3, r12
 *   @0xd37b0 str r12, [sp, #0xc]
 *   @0xd37b4 mov r0, r4
 *   @0xd37b8 bl 0xb6610 <vsnprintf@plt>
 *   @0xd37bc ldr r6, [r5, #0x8]
 *   @0xd37c0 mov r0, r6
 *   @0xd37c4 bl 0xb6538 <strlen@plt>
 *   @0xd37c8 mov r7, r0
 *   @0xd37cc mov r0, r4
 *   @0xd37d0 bl 0xb6538 <strlen@plt>
 *   @0xd37d4 ldr r2, [r5, #0x4]
 *   @0xd37d8 add r7, r7, r0
 *   @0xd37dc mov r3, r0
 *   @0xd37e0 add r7, r7, #2
 *   @0xd37e4 cmp r7, r2
 *   @0xd37e8 blo 0xd381c <_ZN17TErrStreamConsole6OutputEPKcz+0x94>
 *   @0xd37ec add r2, r2, #1024
 *   @0xd37f0 mov r0, r6
 *   @0xd37f4 add r1, r2, r3
 *   @0xd37f8 mov r2, #0
 *   @0xd37fc str r1, [r5, #0x4]
 *   @0xd3800 movw r3, #0x213
 *   @0xd3804 str r2, [sp]
 *   @0xd3808 ldr r2, [pc, #0x2c]
 *   @0xd380c add r2, pc, r2
 *   @0xd3810 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0xd3814 mov r6, r0
 *   @0xd3818 str r0, [r5, #0x8]
 *   @0xd381c mov r0, r6
 *   @0xd3820 mov r1, r4
 *   @0xd3824 bl 0xb6628 <strcat@plt>
 *   @0xd3828 add sp, sp, #16
 *   @0xd382c pop {r4, r5, r6, r7, lr}
 *   @0xd3830 add sp, sp, #12
 *   @0xd3834 bx lr
 *   @0xd3838 eorseq r10, r1, r4, asr r4
 *   @0xd383c eoreq lr, r5, r0, ror pc
 *
 * ══ §80/159 Achievement_PostHiScore  0x1613fc  size 184  46 条（0x1613fc..0x1614b4）
 * @func 0x1613fc 0x1614b4  size 184  46 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Threaded_UpdateComsState(eComsState)×2 / getJNIEnv×2 / _JNIEnv::CallStaticVoidMethod(_jclass*, _jmethodID*, ...)
 * 字段偏移 top8: 0xa0×1 / 0x84×1 / 0xc×1 / 0x29c×1 / 0x38×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1613fc ldr r3, [pc, #0xa0]
 *   @0x161400 push {r4, r5, r6, lr}
 *   @0x161404 ldr r3, [pc, r3]
 *   @0x161408 mov r4, r0
 *   @0x16140c mov r5, r1
 *   @0x161410 ldr r0, [r3]
 *   @0x161414 mov r6, r2
 *   @0x161418 mov r2, r1
 *   @0x16141c ldr r1, [pc, #0x84]
 *   @0x161420 sub sp, sp, #8
 *   @0x161424 ldr r12, [r0]
 *   @0x161428 add r1, pc, r1
 *   @0x16142c ldr r3, [r12, #0xc]
 *   @0x161430 blx r3
 *   @0x161434 cmp r4, #1
 *   @0x161438 beq 0x161450 <_Z23Achievement_PostHiScore10eCacheTypePKci+0x54>
 *   @0x16143c mov r0, #3
 *   @0x161440 bl 0x159a88 <_Z24Threaded_UpdateComsState10eComsState>
 *   @0x161444 mov r0, #0
 *   @0x161448 add sp, sp, #8
 *   @0x16144c pop {r4, r5, r6, pc}
 *   @0x161450 bl 0x290274 <getJNIEnv>
 *   @0x161454 mov r1, r5
 *   @0x161458 ldr r3, [r0]
 *   @0x16145c ldr r3, [r3, #0x29c]
 *   @0x161460 blx r3
 *   @0x161464 mov r5, r0
 *   @0x161468 bl 0x290274 <getJNIEnv>
 *   @0x16146c ldr r2, [pc, #0x38]
 *   @0x161470 mov r3, r5
 *   @0x161474 ldr r12, [pc, #0x34]
 *   @0x161478 ldr r2, [pc, r2]
 *   @0x16147c ldr r12, [pc, r12]
 *   @0x161480 ldr r1, [r2]
 *   @0x161484 ldr r2, [r12]
 *   @0x161488 str r6, [sp]
 *   @0x16148c bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x161490 mov r0, #2
 *   @0x161494 bl 0x159a88 <_Z24Threaded_UpdateComsState10eComsState>
 *   @0x161498 mov r0, r4
 *   @0x16149c add sp, sp, #8
 *   @0x1614a0 pop {r4, r5, r6, pc}
 *   @0x1614a4 eoreq r12, r8, r0, lsl r3
 *   @0x1614a8 ldrsbeq r8, [lr], -r8
 *   @0x1614ac eoreq r12, r8, r12, lsr #10
 *   @0x1614b0 .word 0x0028ead8
 *
 * ══ §81/159 Shader_Set_Uniform_Matrix  0x18829c  size 184  46 条（0x18829c..0x188354）
 * @func 0x18829c 0x188354  size 184  46 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics::Flush()
 * 字段偏移 top8: 0x64×1 / 0x44×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18829c cmn r0, #1
 *   @0x1882a0 push {r3, r4, r5, r6, r7, lr}
 *   @0x1882a4 mov r4, r0
 *   @0x1882a8 mov r5, r1
 *   @0x1882ac mov r7, r2
 *   @0x1882b0 mov r6, r3
 *   @0x1882b4 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1882b8 cmp r3, #0
 *   @0x1882bc popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1882c0 bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x1882c4 cmp r5, #3
 *   @0x1882c8 beq 0x188300 <_Z25Shader_Set_Uniform_MatrixiiiPf+0x64>
 *   @0x1882cc cmp r5, #4
 *   @0x1882d0 beq 0x188324 <_Z25Shader_Set_Uniform_MatrixiiiPf+0x88>
 *   @0x1882d4 cmp r5, #2
 *   @0x1882d8 popne {r3, r4, r5, r6, r7, pc}
 *   @0x1882dc ldr r12, [pc, #0x64]
 *   @0x1882e0 mov r0, r4
 *   @0x1882e4 mov r1, r7
 *   @0x1882e8 mov r3, r6
 *   @0x1882ec ldr r12, [pc, r12]
 *   @0x1882f0 mov r2, #0
 *   @0x1882f4 ldr r12, [r12]
 *   @0x1882f8 blx r12
 *   @0x1882fc pop {r3, r4, r5, r6, r7, pc}
 *   @0x188300 ldr r12, [pc, #0x44]
 *   @0x188304 mov r0, r4
 *   @0x188308 mov r1, r7
 *   @0x18830c mov r3, r6
 *   @0x188310 ldr r12, [pc, r12]
 *   @0x188314 mov r2, #0
 *   @0x188318 ldr r12, [r12]
 *   @0x18831c blx r12
 *   @0x188320 pop {r3, r4, r5, r6, r7, pc}
 *   @0x188324 ldr r12, [pc, #0x24]
 *   @0x188328 mov r0, r4
 *   @0x18832c mov r1, r7
 *   @0x188330 mov r3, r6
 *   @0x188334 ldr r12, [pc, r12]
 *   @0x188338 mov r2, #0
 *   @0x18833c ldr r12, [r12]
 *   @0x188340 blx r12
 *   @0x188344 pop {r3, r4, r5, r6, r7, pc}
 *   @0x188348 eoreq r5, r6, r8, asr #10
 *   @0x18834c eoreq r5, r6, r8, lsr #10
 *   @0x188350 eoreq r5, r6, r8, lsl #10
 *
 * ══ §82/159 Variable_SetValue_Direct  0x1f3c28  size 184  46 条（0x1f3c28..0x1f3ce0）
 * @func 0x1f3c28 0x1f3ce0  size 184  46 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: SET_RValue(RValue*, RValue*, int) / YYObjectBase::InternalGetYYVar(int)
 * 字段偏移 top8: 0x4×3 / 0x94×1 / 0xc×1 / 0x24×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f3c28 movw r12, #0x270f
 *   @0x1f3c2c cmp r1, r12
 *   @0x1f3c30 push {r4, lr}
 *   @0x1f3c34 mov r12, r0
 *   @0x1f3c38 sub sp, sp, #8
 *   @0x1f3c3c bgt 0x1f3c64 <_Z24Variable_SetValue_DirectP12YYObjectBaseiiP6RValue+0x3c>
 *   @0x1f3c40 ldr r12, [pc, #0x94]
 *   @0x1f3c44 ldr r12, [pc, r12]
 *   @0x1f3c48 add r1, r12, r1, lsl #4
 *   @0x1f3c4c ldrb r12, [r1, #0xc]
 *   @0x1f3c50 cmp r12, #0
 *   @0x1f3c54 bne 0x1f3ca4 <_Z24Variable_SetValue_DirectP12YYObjectBaseiiP6RValue+0x7c>
 *   @0x1f3c58 mov r0, r12
 *   @0x1f3c5c add sp, sp, #8
 *   @0x1f3c60 pop {r4, pc}
 *   @0x1f3c64 ldr r4, [r0, #0x24]
 *   @0x1f3c68 cmp r4, #0
 *   @0x1f3c6c moveq r12, #1
 *   @0x1f3c70 beq 0x1f3c58 <_Z24Variable_SetValue_DirectP12YYObjectBaseiiP6RValue+0x30>
 *   @0x1f3c74 ldr r12, [r12, #0x4]
 *   @0x1f3c78 sub r1, r1, #99328
 *   @0x1f3c7c sub r1, r1, #672
 *   @0x1f3c80 cmp r12, #0
 *   @0x1f3c84 beq 0x1f3cc4 <_Z24Variable_SetValue_DirectP12YYObjectBaseiiP6RValue+0x9c>
 *   @0x1f3c88 add r0, r12, r1, lsl #4
 *   @0x1f3c8c mov r1, r3
 *   @0x1f3c90 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i>
 *   @0x1f3c94 mov r12, #1
 *   @0x1f3c98 mov r0, r12
 *   @0x1f3c9c add sp, sp, #8
 *   @0x1f3ca0 pop {r4, pc}
 *   @0x1f3ca4 ldr r12, [r1, #0x8]
 *   @0x1f3ca8 mov r1, r2
 *   @0x1f3cac mov r2, r3
 *   @0x1f3cb0 blx r12
 *   @0x1f3cb4 mov r12, r0
 *   @0x1f3cb8 mov r0, r12
 *   @0x1f3cbc add sp, sp, #8
 *   @0x1f3cc0 pop {r4, pc}
 *   @0x1f3cc4 str r2, [sp, #0x4]
 *   @0x1f3cc8 str r3, [sp]
 *   @0x1f3ccc bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x1f3cd0 ldr r3, [sp]
 *   @0x1f3cd4 ldr r2, [sp, #0x4]
 *   @0x1f3cd8 b 0x1f3c8c <_Z24Variable_SetValue_DirectP12YYObjectBaseiiP6RValue+0x64>
 *   @0x1f3cdc ldrsheq r9, [pc], -r4
 *
 * ══ §83/159 MD5Update  0x214118  size 184  46 条（0x214118..0x2141d0）
 * @func 0x214118 0x2141e4  size 204  51 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_21362c
 * 字段偏移 top8: 0x4×2 / 0x1×1 / 0x18×1 / 0x1a×1 / 0x17×1 / 0x14×1 / 0x15×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x214118 ldr r3, [r0]
 *   @0x21411c push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x214120 mov r8, r0
 *   @0x214124 add r0, r3, r2, lsl #3
 *   @0x214128 mov r7, r1
 *   @0x21412c cmp r3, r0
 *   @0x214130 ubfx r1, r3, #0x3, #0x6
 *   @0x214134 ldr r3, [r8, #0x4]
 *   @0x214138 sub sp, sp, #68
 *   @0x21413c add r9, r7, r2
 *   @0x214140 add r4, sp, #60
 *   @0x214144 addhi r3, r3, #1
 *   @0x214148 add r6, r8, #8
 *   @0x21414c add r3, r3, r2, lsr #29
 *   @0x214150 stm r8, {r0, r3}
 *   @0x214154 b 0x21415c <_Z9MD5UpdateP7MD5_CTXPhj+0x44>
 *   @0x214158 mov r1, r3
 *   @0x21415c cmp r7, r9
 *   @0x214160 beq 0x2141c8 <_Z9MD5UpdateP7MD5_CTXPhj+0xb0>
 *   @0x214164 add r3, r1, #1
 *   @0x214168 ldrb r2, [r7], #1
 *   @0x21416c add r1, r8, r1
 *   @0x214170 cmp r3, #64
 *   @0x214174 strb r2, [r1, #0x18]
 *   @0x214178 bne 0x214158 <_Z9MD5UpdateP7MD5_CTXPhj+0x40>
 *   @0x21417c sub r2, sp, #4
 *   @0x214180 mov r3, r8
 *   @0x214184 ldrb r12, [r3, #0x1a]
 *   @0x214188 add r3, r3, #4
 *   @0x21418c ldrb r0, [r3, #0x17]
 *   @0x214190 ldrb r1, [r3, #0x14]
 *   @0x214194 ldrb lr, [r3, #0x15]
 *   @0x214198 lsl r12, r12, #16
 *   @0x21419c orr r12, r12, r0, lsl #24
 *   @0x2141a0 orr r12, r12, r1
 *   @0x2141a4 orr r12, r12, lr, lsl #8
 *   @0x2141a8 str r12, [r2, #0x4]!
 *   @0x2141ac cmp r2, r4
 *   @0x2141b0 bne 0x214184 <_Z9MD5UpdateP7MD5_CTXPhj+0x6c>
 *   @0x2141b4 mov r0, r6
 *   @0x2141b8 mov r1, sp
 *   @0x2141bc bl 0x21362c <_Z7LoadCSVPc+0x104>
 *   @0x2141c0 mov r3, #0
 *   @0x2141c4 b 0x214158 <_Z9MD5UpdateP7MD5_CTXPhj+0x40>
 *   @0x2141c8 add sp, sp, #68
 *   @0x2141cc pop {r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §84/159 CPhysicsFixtureFactory::CreateFixture  0x2364d4  size 184  46 条（0x2364d4..0x23658c）
 * @func 0x2364d4 0x23658c  size 184  46 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int) / CPhysicsFixture::CPhysicsFixture(int) / MemoryManager::Alloc(unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x8×3 / 0xa4×1 / 0x98×1 / 0x7c×1 / 0x4×1 / 0x3×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2364d4 ldr r3, [pc, #0xa4]
 *   @0x2364d8 mov r0, #36
 *   @0x2364dc push {r4, r5, r6, r7, r8, lr}
 *   @0x2364e0 ldr r3, [pc, r3]
 *   @0x2364e4 ldr r4, [pc, #0x98]
 *   @0x2364e8 ldr r5, [r3]
 *   @0x2364ec add r5, r5, #1
 *   @0x2364f0 str r5, [r3]
 *   @0x2364f4 bl 0x27c524 <_Znwj>
 *   @0x2364f8 mov r1, r5
 *   @0x2364fc mov r8, r0
 *   @0x236500 bl 0x236454 <_ZN15CPhysicsFixtureC2Ei>
 *   @0x236504 ldr r1, [pc, #0x7c]
 *   @0x236508 ldr r4, [pc, r4]
 *   @0x23650c movw r2, #0x132
 *   @0x236510 mov r3, #1
 *   @0x236514 add r1, pc, r1
 *   @0x236518 mov r0, #16
 *   @0x23651c ldr r6, [r4]
 *   @0x236520 ldr r7, [r4, #0x4]
 *   @0x236524 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x236528 and r7, r5, r7
 *   @0x23652c ldr r1, [r6, r7, lsl #3]
 *   @0x236530 add r2, r6, r7, lsl #3
 *   @0x236534 cmp r1, #0
 *   @0x236538 ldrne r1, [r2, #0x4]
 *   @0x23653c mov r3, r0
 *   @0x236540 str r5, [r0, #0x8]
 *   @0x236544 str r8, [r0, #0xc]
 *   @0x236548 movne r0, #0
 *   @0x23654c strne r1, [r3]
 *   @0x236550 strne r3, [r1, #0x4]
 *   @0x236554 strne r3, [r2, #0x4]
 *   @0x236558 strne r0, [r3, #0x4]
 *   @0x23655c ldr r3, [r4, #0x8]
 *   @0x236560 streq r0, [r2, #0x4]
 *   @0x236564 add r3, r3, #1
 *   @0x236568 streq r0, [r6, r7, lsl #3]
 *   @0x23656c streq r1, [r0, #0x4]
 *   @0x236570 streq r1, [r0]
 *   @0x236574 mov r0, r8
 *   @0x236578 str r3, [r4, #0x8]
 *   @0x23657c pop {r4, r5, r6, r7, r8, pc}
 *   @0x236580 andseq r10, r11, r8, asr #31
 *   @0x236584 mulseq r11, r12, pc
 *   @0x236588 mulseq r1, r8, r7
 *
 * ══ §85/159 CPhysicsJointFactory::DestroyJoint  0x23b3c4  size 184  46 条（0x23b3c4..0x23b47c）
 * @func 0x23b3c4 0x23b490  size 204  51 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsJointFactory::FindJoint(unsigned int) / MemoryManager::Free(void const*) / b2World::DestroyJoint(b2Joint*) / operator delete(void*)
 * 字段偏移 top8: 0x8×4 / 0x4×3 / 0x94×1 / 0x3×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23b3c4 push {r4, r5, r6, lr}
 *   @0x23b3c8 mov r6, r0
 *   @0x23b3cc mov r0, r1
 *   @0x23b3d0 bl 0x23b374 <_ZN20CPhysicsJointFactory9FindJointEj>
 *   @0x23b3d4 subs r5, r0, #0
 *   @0x23b3d8 beq 0x23b470 <_ZN20CPhysicsJointFactory12DestroyJointEP13CPhysicsWorldj+0xac>
 *   @0x23b3dc ldr r4, [pc, #0x94]
 *   @0x23b3e0 ldr r1, [r5, #0x8]
 *   @0x23b3e4 ldr r4, [pc, r4]
 *   @0x23b3e8 ldm r4, {r12, lr}
 *   @0x23b3ec and lr, r1, lr
 *   @0x23b3f0 ldr r3, [r12, lr, lsl #3]
 *   @0x23b3f4 add r0, r12, lr, lsl #3
 *   @0x23b3f8 cmp r3, #0
 *   @0x23b3fc bne 0x23b410 <_ZN20CPhysicsJointFactory12DestroyJointEP13CPhysicsWorldj+0x4c>
 *   @0x23b400 b 0x23b454 <_ZN20CPhysicsJointFactory12DestroyJointEP13CPhysicsWorldj+0x90>
 *   @0x23b404 ldr r3, [r3, #0x4]
 *   @0x23b408 cmp r3, #0
 *   @0x23b40c beq 0x23b454 <_ZN20CPhysicsJointFactory12DestroyJointEP13CPhysicsWorldj+0x90>
 *   @0x23b410 ldr r2, [r3, #0x8]
 *   @0x23b414 cmp r1, r2
 *   @0x23b418 bne 0x23b404 <_ZN20CPhysicsJointFactory12DestroyJointEP13CPhysicsWorldj+0x40>
 *   @0x23b41c ldr r2, [r3]
 *   @0x23b420 ldr r1, [r3, #0x4]
 *   @0x23b424 cmp r2, #0
 *   @0x23b428 strne r1, [r2, #0x4]
 *   @0x23b42c ldrne r1, [r3, #0x4]
 *   @0x23b430 streq r1, [r12, lr, lsl #3]
 *   @0x23b434 cmp r1, #0
 *   @0x23b438 streq r2, [r0, #0x4]
 *   @0x23b43c strne r2, [r1]
 *   @0x23b440 mov r0, r3
 *   @0x23b444 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x23b448 ldr r3, [r4, #0x8]
 *   @0x23b44c sub r3, r3, #1
 *   @0x23b450 str r3, [r4, #0x8]
 *   @0x23b454 ldr r0, [r6, #0x10]
 *   @0x23b458 ldr r1, [r5, #0x4]
 *   @0x23b45c bl 0x2c923c <_ZN7b2World12DestroyJointEP7b2Joint>
 *   @0x23b460 mov r0, r5
 *   @0x23b464 bl 0x27d1d0 <_ZdlPv>
 *   @0x23b468 mov r0, #1
 *   @0x23b46c pop {r4, r5, r6, pc}
 *   @0x23b470 mov r0, r5
 *   @0x23b474 pop {r4, r5, r6, pc}
 *   @0x23b478 andseq r6, r11, r0, lsl #2
 *
 * ══ §86/159 CPhysicsJointFactory::FindJoint  0x23b47c  size 184  46 条（0x23b47c..0x23b534）
 * @func 0x23b47c 0x23b534  size 184  46 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsJointFactory::FindJoint(b2Joint*)+0x9c×2 / CPhysicsJointFactory::FindJoint(b2Joint*)+0xac
 * 字段偏移 top8: 0x4×3 / 0xac×1 / 0x3×1 / 0xc×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23b47c ldr r3, [pc, #0xac]
 *   @0x23b480 mov r2, #0
 *   @0x23b484 push {r4, r5}
 *   @0x23b488 ldr r3, [pc, r3]
 *   @0x23b48c ldr r5, [r3]
 *   @0x23b490 ldr r4, [r3, #0x4]
 *   @0x23b494 b 0x23b4a0 <_ZN20CPhysicsJointFactory9FindJointEP7b2Joint+0x24>
 *   @0x23b498 cmp r4, r2
 *   @0x23b49c blt 0x23b528 <_ZN20CPhysicsJointFactory9FindJointEP7b2Joint+0xac>
 *   @0x23b4a0 mov r12, r2
 *   @0x23b4a4 add r2, r2, #1
 *   @0x23b4a8 ldr r3, [r5, r12, lsl #3]
 *   @0x23b4ac cmp r3, #0
 *   @0x23b4b0 beq 0x23b498 <_ZN20CPhysicsJointFactory9FindJointEP7b2Joint+0x1c>
 *   @0x23b4b4 cmp r3, #0
 *   @0x23b4b8 beq 0x23b518 <_ZN20CPhysicsJointFactory9FindJointEP7b2Joint+0x9c>
 *   @0x23b4bc ldr r2, [r3, #0xc]
 *   @0x23b4c0 cmp r2, #0
 *   @0x23b4c4 beq 0x23b51c <_ZN20CPhysicsJointFactory9FindJointEP7b2Joint+0xa0>
 *   @0x23b4c8 ldr r1, [r2, #0x4]
 *   @0x23b4cc cmp r1, r0
 *   @0x23b4d0 beq 0x23b51c <_ZN20CPhysicsJointFactory9FindJointEP7b2Joint+0xa0>
 *   @0x23b4d4 ldr r3, [r3, #0x4]
 *   @0x23b4d8 cmp r3, #0
 *   @0x23b4dc bne 0x23b4b4 <_ZN20CPhysicsJointFactory9FindJointEP7b2Joint+0x38>
 *   @0x23b4e0 add r2, r12, #1
 *   @0x23b4e4 cmp r4, r2
 *   @0x23b4e8 blt 0x23b518 <_ZN20CPhysicsJointFactory9FindJointEP7b2Joint+0x9c>
 *   @0x23b4ec add r1, r5, r12, lsl #3
 *   @0x23b4f0 b 0x23b4fc <_ZN20CPhysicsJointFactory9FindJointEP7b2Joint+0x80>
 *   @0x23b4f4 cmp r4, r2
 *   @0x23b4f8 blt 0x23b518 <_ZN20CPhysicsJointFactory9FindJointEP7b2Joint+0x9c>
 *   @0x23b4fc ldr r3, [r1, #0x8]
 *   @0x23b500 mov r12, r2
 *   @0x23b504 add r1, r1, #8
 *   @0x23b508 add r2, r2, #1
 *   @0x23b50c cmp r3, #0
 *   @0x23b510 beq 0x23b4f4 <_ZN20CPhysicsJointFactory9FindJointEP7b2Joint+0x78>
 *   @0x23b514 b 0x23b4b4 <_ZN20CPhysicsJointFactory9FindJointEP7b2Joint+0x38>
 *   @0x23b518 mov r2, #0
 *   @0x23b51c mov r0, r2
 *   @0x23b520 pop {r4, r5}
 *   @0x23b524 bx lr
 *   @0x23b528 mvn r12, #0
 *   @0x23b52c b 0x23b4b4 <_ZN20CPhysicsJointFactory9FindJointEP7b2Joint+0x38>
 *   @0x23b530 andseq r6, r11, r12, asr r0
 *
 * ══ §87/159 lh_table_new  0x280834  size 184  46 条（0x280834..0x2808ec）
 * @func 0x280834 0x2808ec  size 184  46 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6c34×2 / lh_abort×2 / lh_table_new+0x88
 * 字段偏移 top8: 0x28×2 / 0x20×1 / 0x1c×1 / 0x4×1 / 0x2c×1 / 0x30×1 / 0x34×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x280834 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x280838 mov r5, r0
 *   @0x28083c mov r9, r1
 *   @0x280840 mov r0, #1
 *   @0x280844 mov r1, #56
 *   @0x280848 mov r8, r2
 *   @0x28084c mov r7, r3
 *   @0x280850 ldr r6, [sp, #0x20]
 *   @0x280854 bl 0xb6c34 <calloc@plt>
 *   @0x280858 subs r4, r0, #0
 *   @0x28085c beq 0x2808c4 <lh_table_new+0x90>
 *   @0x280860 mov r3, #0
 *   @0x280864 str r5, [r4]
 *   @0x280868 str r9, [r4, #0x1c]
 *   @0x28086c mov r0, r5
 *   @0x280870 str r3, [r4, #0x4]
 *   @0x280874 mov r1, #16
 *   @0x280878 bl 0xb6c34 <calloc@plt>
 *   @0x28087c cmp r0, #0
 *   @0x280880 str r0, [r4, #0x28]
 *   @0x280884 beq 0x2808d4 <lh_table_new+0xa0>
 *   @0x280888 cmp r5, #0
 *   @0x28088c str r8, [r4, #0x2c]
 *   @0x280890 str r7, [r4, #0x30]
 *   @0x280894 str r6, [r4, #0x34]
 *   @0x280898 ble 0x2808bc <lh_table_new+0x88>
 *   @0x28089c ldr r12, [r4, #0x28]
 *   @0x2808a0 lsl r1, r5, #4
 *   @0x2808a4 mov r3, #0
 *   @0x2808a8 mvn r2, #0
 *   @0x2808ac str r2, [r12, r3]
 *   @0x2808b0 add r3, r3, #16
 *   @0x2808b4 cmp r3, r1
 *   @0x2808b8 bne 0x2808ac <lh_table_new+0x78>
 *   @0x2808bc mov r0, r4
 *   @0x2808c0 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2808c4 ldr r0, [pc, #0x18]
 *   @0x2808c8 add r0, pc, r0
 *   @0x2808cc bl 0x280810 <lh_abort>
 *   @0x2808d0 b 0x280860 <lh_table_new+0x2c>
 *   @0x2808d4 ldr r0, [pc, #0xc]
 *   @0x2808d8 add r0, pc, r0
 *   @0x2808dc bl 0x280810 <lh_abort>
 *   @0x2808e0 b 0x280888 <lh_table_new+0x54>
 *   @0x2808e4 andeq r6, sp, r8, ror #22
 *   @0x2808e8 andeq r6, sp, r8, asr r11
 *
 * ══ §88/159 F_NETWORK_Send_UDP_Raw  0x299f40  size 184  46 条（0x299f40..0x299ff8）
 * @func 0x299f40 0x29a00c  size 204  51 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×4 / YYGetString(RValue const*, int) / anon_299da0
 * 字段偏移 top8: 0xac×1 / 0xc×1 / 0x4×1 / 0x28×1
 * VFP 指令 2 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x299f40 ldr r3, [pc, #0xac]
 *   @0x299f44 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x299f48 ldr r3, [pc, r3]
 *   @0x299f4c mov r5, #0
 *   @0x299f50 str r5, [r0]
 *   @0x299f54 ldr r3, [r3]
 *   @0x299f58 sub sp, sp, #8
 *   @0x299f5c mov r2, r5
 *   @0x299f60 mov r4, r0
 *   @0x299f64 sub r3, r3, #2
 *   @0x299f68 movt r2, #0xbff0
 *   @0x299f6c cmp r3, #2
 *   @0x299f70 str r5, [r0, #0xc]
 *   @0x299f74 str r2, [r0, #0x4]
 *   @0x299f78 ldr r6, [sp, #0x28]
 *   @0x299f7c bhi 0x299fec <_Z22F_NETWORK_Send_UDP_RawR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0x299f80 mov r1, r5
 *   @0x299f84 mov r0, r6
 *   @0x299f88 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x299f8c mov r1, #1
 *   @0x299f90 mov r7, r0
 *   @0x299f94 mov r0, r6
 *   @0x299f98 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x299f9c mov r1, #2
 *   @0x299fa0 mov r10, r0
 *   @0x299fa4 mov r0, r6
 *   @0x299fa8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x299fac mov r1, #3
 *   @0x299fb0 mov r9, r0
 *   @0x299fb4 mov r0, r6
 *   @0x299fb8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x299fbc mov r1, #4
 *   @0x299fc0 mov r8, r0
 *   @0x299fc4 mov r0, r6
 *   @0x299fc8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x299fcc mov r1, r10
 *   @0x299fd0 mov r2, r9
 *   @0x299fd4 mov r3, r8
 *   @0x299fd8 stm sp, {r0, r5}
 *   @0x299fdc mov r0, r7
 *   @0x299fe0 bl 0x299da0 <_Z16RelySendReliableiPKciii+0x138>
 *   @0x299fe4 vstr s0, [r4]
 *   @0x299fe8 vstr s1, [r4, #4]
 *   @0x299fec add sp, sp, #8
 *   @0x299ff0 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x299ff4 ldrsbeq r6, [r5], -r8
 *
 * ══ §89/159 b2TestOverlap  0x2c3abc  size 184  46 条（0x2c3abc..0x2c3b74）
 * @func 0x2c3abc 0x2c3b88  size 204  51 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2DistanceProxy::Set(b2Shape const*, int)×2 / b2Distance(b2DistanceOutput*, b2SimplexCache*, b2DistanceInput const*)
 * 字段偏移 top8: 0xa0×1 / 0xa4×1 / 0x3c×1 / 0x58×1 / 0x34×1 / 0x38×1 / 0x50×1 / 0x54×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c3abc push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x2c3ac0 sub sp, sp, #132
 *   @0x2c3ac4 add r7, sp, #36
 *   @0x2c3ac8 mov r12, r1
 *   @0x2c3acc ldr r6, [sp, #0xa0]
 *   @0x2c3ad0 mov r9, r3
 *   @0x2c3ad4 mov r1, r0
 *   @0x2c3ad8 mov r8, r2
 *   @0x2c3adc mov r0, r7
 *   @0x2c3ae0 mov r2, r12
 *   @0x2c3ae4 mov r4, #0
 *   @0x2c3ae8 mov r12, #0
 *   @0x2c3aec ldr r5, [sp, #0xa4]
 *   @0x2c3af0 str r12, [sp, #0x3c]
 *   @0x2c3af4 str r12, [sp, #0x58]
 *   @0x2c3af8 str r4, [sp, #0x34]
 *   @0x2c3afc str r4, [sp, #0x38]
 *   @0x2c3b00 str r4, [sp, #0x50]
 *   @0x2c3b04 str r4, [sp, #0x54]
 *   @0x2c3b08 bl 0x2c3b74 <_ZN15b2DistanceProxy3SetEPK7b2Shapei>
 *   @0x2c3b0c mov r1, r8
 *   @0x2c3b10 mov r2, r9
 *   @0x2c3b14 add r0, sp, #64
 *   @0x2c3b18 bl 0x2c3b74 <_ZN15b2DistanceProxy3SetEPK7b2Shapei>
 *   @0x2c3b1c ldm r6, {r0, r1, r2, r3}
 *   @0x2c3b20 mov r12, #1
 *   @0x2c3b24 strb r12, [sp, #0x7c]
 *   @0x2c3b28 add r12, sp, #92
 *   @0x2c3b2c strh r4, [sp, #4]
 *   @0x2c3b30 stm r12, {r0, r1, r2, r3}
 *   @0x2c3b34 add r12, sp, #108
 *   @0x2c3b38 ldm r5, {r0, r1, r2, r3}
 *   @0x2c3b3c stm r12, {r0, r1, r2, r3}
 *   @0x2c3b40 add r0, sp, #12
 *   @0x2c3b44 mov r2, r7
 *   @0x2c3b48 mov r1, sp
 *   @0x2c3b4c bl 0x2c3fa0 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput>
 *   @0x2c3b50 vldr s14, [sp, #28]
 *   @0x2c3b54 vldr s15, [pc, #20]
 *   @0x2c3b58 vcmpe.f32 s14, s15
 *   @0x2c3b5c vmrs APSR_nzcv, fpscr
 *   @0x2c3b60 movpl r0, #0
 *   @0x2c3b64 movmi r0, #1
 *   @0x2c3b68 add sp, sp, #132
 *   @0x2c3b6c pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x2c3b70 strlo r0, [r0, #0x0]!
 *
 * ══ §90/159 b2StackAllocator::Allocate  0x2e0f44  size 184  46 条（0x2e0f44..0x2e0ffc）
 * @func 0x2e0f44 0x2e0ffc  size 184  46 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Alloc(int)
 * 字段偏移 top8: 0x4×3 / 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e0f44 push {r3, r4, r5, r6, r7, lr}
 *   @0x2e0f48 movw r3, #0x918c
 *   @0x2e0f4c movt r3, #0x1
 *   @0x2e0f50 mov r2, #102400
 *   @0x2e0f54 mov r4, r0
 *   @0x2e0f58 mov r6, r1
 *   @0x2e0f5c ldr r5, [r0, r3]
 *   @0x2e0f60 ldr r0, [r0, r2]
 *   @0x2e0f64 add r5, r5, r5, lsl #1
 *   @0x2e0f68 add r3, r0, r1
 *   @0x2e0f6c cmp r3, r2
 *   @0x2e0f70 add r5, r4, r5, lsl #2
 *   @0x2e0f74 add r5, r5, r2
 *   @0x2e0f78 add r5, r5, #8
 *   @0x2e0f7c add r7, r5, #4
 *   @0x2e0f80 str r1, [r7, #0x4]
 *   @0x2e0f84 bgt 0x2e0fe0 <_ZN16b2StackAllocator8AllocateEi+0x9c>
 *   @0x2e0f88 add r0, r4, r0
 *   @0x2e0f8c mov r1, #0
 *   @0x2e0f90 str r0, [r5, #0x4]
 *   @0x2e0f94 strb r1, [r7, #0x8]
 *   @0x2e0f98 str r3, [r4, r2]
 *   @0x2e0f9c movw r2, #0x9008
 *   @0x2e0fa0 movt r2, #0x1
 *   @0x2e0fa4 movw r1, #0x9004
 *   @0x2e0fa8 movw r3, #0x918c
 *   @0x2e0fac movt r1, #0x1
 *   @0x2e0fb0 movt r3, #0x1
 *   @0x2e0fb4 ldr r12, [r4, r2]
 *   @0x2e0fb8 ldr r7, [r4, r1]
 *   @0x2e0fbc ldr r5, [r4, r3]
 *   @0x2e0fc0 add r6, r6, r7
 *   @0x2e0fc4 str r6, [r4, r1]
 *   @0x2e0fc8 add r1, r5, #1
 *   @0x2e0fcc cmp r6, r12
 *   @0x2e0fd0 strge r6, [r4, r2]
 *   @0x2e0fd4 strlt r12, [r4, r2]
 *   @0x2e0fd8 str r1, [r4, r3]
 *   @0x2e0fdc pop {r3, r4, r5, r6, r7, pc}
 *   @0x2e0fe0 mov r0, r1
 *   @0x2e0fe4 bl 0x2c6a6c <_Z7b2Alloci>
 *   @0x2e0fe8 mov r3, r0
 *   @0x2e0fec str r3, [r5, #0x4]
 *   @0x2e0ff0 mov r3, #1
 *   @0x2e0ff4 strb r3, [r7, #0x8]
 *   @0x2e0ff8 b 0x2e0f9c <_ZN16b2StackAllocator8AllocateEi+0x58>
 *
 * ══ §91/159 CBackground::DrawPart  0xc2184  size 180  45 条（0xc2184..0xc2238）
 * @func 0xc2184 0xc224c  size 200  50 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Texture_Draw_Part(YYTPageEntry*, float, float, float, float, float, float, float, float, float, unsigned int, float) / GR_Texture_Draw_Part(int, float, float, float, float, float, float, float, float, float, unsigned int, float)
 * 字段偏移 top8: 0x14×3 / 0x3c×2 / 0x18×2 / 0x4×2 / 0x-4×1 / 0xc×1
 * VFP 指令 24 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc2184 ldr r12, [r0, #0x14]
 *   @0xc2188 str lr, [sp, #-0x4]!
 *   @0xc218c cmp r12, #0
 *   @0xc2190 sub sp, sp, #36
 *   @0xc2194 beq 0xc21e8 <_ZN11CBackground8DrawPartEffffffffjf+0x64>
 *   @0xc2198 ldr r0, [sp, #0x3c]
 *   @0xc219c vldr s15, [sp, #40]
 *   @0xc21a0 vstr s15, [sp]
 *   @0xc21a4 vldr s15, [sp, #44]
 *   @0xc21a8 vstr s15, [sp, #4]
 *   @0xc21ac vldr s15, [sp, #48]
 *   @0xc21b0 str r0, [sp, #0x18]
 *   @0xc21b4 vstr s15, [sp, #8]
 *   @0xc21b8 mov r0, r12
 *   @0xc21bc vldr s15, [sp, #52]
 *   @0xc21c0 mov r12, #0
 *   @0xc21c4 vstr s15, [sp, #12]
 *   @0xc21c8 str r12, [sp, #0x14]
 *   @0xc21cc vldr s15, [sp, #56]
 *   @0xc21d0 vstr s15, [sp, #16]
 *   @0xc21d4 vldr s15, [sp, #64]
 *   @0xc21d8 vstr s15, [sp, #28]
 *   @0xc21dc bl 0x175450 <_Z20GR_Texture_Draw_PartP12YYTPageEntryfffffffffjf>
 *   @0xc21e0 add sp, sp, #36
 *   @0xc21e4 ldr pc, [sp], #4
 *   @0xc21e8 ldr r12, [sp, #0x3c]
 *   @0xc21ec vldr s15, [sp, #40]
 *   @0xc21f0 ldr r0, [r0, #0xc]
 *   @0xc21f4 vstr s15, [sp]
 *   @0xc21f8 vldr s15, [sp, #44]
 *   @0xc21fc vstr s15, [sp, #4]
 *   @0xc2200 str r12, [sp, #0x18]
 *   @0xc2204 vldr s15, [sp, #48]
 *   @0xc2208 mov r12, #0
 *   @0xc220c vstr s15, [sp, #8]
 *   @0xc2210 str r12, [sp, #0x14]
 *   @0xc2214 vldr s15, [sp, #52]
 *   @0xc2218 vstr s15, [sp, #12]
 *   @0xc221c vldr s15, [sp, #56]
 *   @0xc2220 vstr s15, [sp, #16]
 *   @0xc2224 vldr s15, [sp, #64]
 *   @0xc2228 vstr s15, [sp, #28]
 *   @0xc222c bl 0x175208 <_Z20GR_Texture_Draw_Partifffffffffjf>
 *   @0xc2230 add sp, sp, #36
 *   @0xc2234 ldr pc, [sp], #4
 *
 * ══ §92/159 GR_Surface_DrawStretched  0x171e2c  size 180  45 条（0x171e2c..0x171ee0）
 * @func 0x171e2c 0x171ee0  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Surface_DrawStretched(int, float, float, float, float, unsigned int, float)+0xa8×4 / GR_Surface_Get(int) / GR_Texture_Draw(int, float, float, float, float, float, float, float, unsigned int, float)
 * 字段偏移 top8: 0xc×2 / 0x8×1 / 0x4×1 / 0x34×1 / 0x10×1
 * VFP 指令 18 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x171e2c push {r4, r5, r6, lr}
 *   @0x171e30 vpush {d8}
 *   @0x171e34 sub sp, sp, #24
 *   @0x171e38 vldr s17, [sp, #48]
 *   @0x171e3c mov r5, r1
 *   @0x171e40 mov r6, r2
 *   @0x171e44 vmov s16, r3
 *   @0x171e48 bl 0x170f48 <_Z14GR_Surface_Geti>
 *   @0x171e4c cmp r0, #0
 *   @0x171e50 beq 0x171ed4 <_Z24GR_Surface_DrawStretchediffffjf+0xa8>
 *   @0x171e54 vcmpe.f32 s16, #0
 *   @0x171e58 mov r12, #0
 *   @0x171e5c vmrs APSR_nzcv, fpscr
 *   @0x171e60 bls 0x171ed4 <_Z24GR_Surface_DrawStretchediffffjf+0xa8>
 *   @0x171e64 vcmpe.f32 s17, #0
 *   @0x171e68 vmrs APSR_nzcv, fpscr
 *   @0x171e6c bls 0x171ed4 <_Z24GR_Surface_DrawStretchediffffjf+0xa8>
 *   @0x171e70 ldr r4, [r0, #0x8]
 *   @0x171e74 cmp r4, #0
 *   @0x171e78 ble 0x171ed4 <_Z24GR_Surface_DrawStretchediffffjf+0xa8>
 *   @0x171e7c ldr r2, [r0, #0xc]
 *   @0x171e80 cmp r2, #0
 *   @0x171e84 ble 0x171ed4 <_Z24GR_Surface_DrawStretchediffffjf+0xa8>
 *   @0x171e88 vmov s13, r4
 *   @0x171e8c ldr r0, [r0, #0x4]
 *   @0x171e90 ldr r3, [sp, #0x34]
 *   @0x171e94 mov r1, r12
 *   @0x171e98 vcvt.f32.s32 s14, s13
 *   @0x171e9c vldr s13, [sp, #56]
 *   @0x171ea0 vstr s13, [sp, #20]
 *   @0x171ea4 vmov s13, r2
 *   @0x171ea8 str r3, [sp, #0x10]
 *   @0x171eac mov r2, r12
 *   @0x171eb0 str r6, [sp]
 *   @0x171eb4 mov r3, r5
 *   @0x171eb8 str r12, [sp, #0xc]
 *   @0x171ebc vcvt.f32.s32 s15, s13
 *   @0x171ec0 vdiv.f32 s16, s16, s14
 *   @0x171ec4 vdiv.f32 s17, s17, s15
 *   @0x171ec8 vstr s16, [sp, #4]
 *   @0x171ecc vstr s17, [sp, #8]
 *   @0x171ed0 bl 0x174c40 <_Z15GR_Texture_Drawifffffffjf>
 *   @0x171ed4 add sp, sp, #24
 *   @0x171ed8 vpop {d8}
 *   @0x171edc pop {r4, r5, r6, pc}
 *
 * ══ §93/159 CInstance::Adapt_Speed  0x193f2c  size 180  45 条（0x193f2c..0x193fe0）
 * @func 0x193f2c 0x193fe0  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::SetSpeed(float)×2 / CInstance::Adapt_Speed()+0x74 / CInstance::Adapt_Speed()+0xa4
 * 字段偏移 top8: 0xd8×1
 * VFP 指令 23 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x193f2c vldr s15, [r0, #212]
 *   @0x193f30 vcmp.f32 s15, #0
 *   @0x193f34 push {r4, lr}
 *   @0x193f38 mov r4, r0
 *   @0x193f3c vmrs APSR_nzcv, fpscr
 *   @0x193f40 beq 0x193f7c <_ZN9CInstance11Adapt_SpeedEv+0x50>
 *   @0x193f44 vldr s14, [r0, #208]
 *   @0x193f48 vcmpe.f32 s14, #0
 *   @0x193f4c vmrs APSR_nzcv, fpscr
 *   @0x193f50 vsubgt.f32 s15, s14, s15
 *   @0x193f54 ble 0x193fa0 <_ZN9CInstance11Adapt_SpeedEv+0x74>
 *   @0x193f58 vcmpe.f32 s15, #0
 *   @0x193f5c vmrs APSR_nzcv, fpscr
 *   @0x193f60 bmi 0x193fc0 <_ZN9CInstance11Adapt_SpeedEv+0x94>
 *   @0x193f64 vcmpe.f32 s14, #0
 *   @0x193f68 vmrs APSR_nzcv, fpscr
 *   @0x193f6c bmi 0x193fb4 <_ZN9CInstance11Adapt_SpeedEv+0x88>
 *   @0x193f70 vcmp.f32 s14, #0
 *   @0x193f74 vmrs APSR_nzcv, fpscr
 *   @0x193f78 bne 0x193fd0 <_ZN9CInstance11Adapt_SpeedEv+0xa4>
 *   @0x193f7c vldr s15, [r4, #220]
 *   @0x193f80 vcmp.f32 s15, #0
 *   @0x193f84 vmrs APSR_nzcv, fpscr
 *   @0x193f88 popeq {r4, pc}
 *   @0x193f8c mov r0, r4
 *   @0x193f90 ldr r1, [r4, #0xd8]
 *   @0x193f94 vmov r2, s15
 *   @0x193f98 pop {r4, lr}
 *   @0x193f9c b 0x193ec0 <_ZN9CInstance11AddTo_SpeedEff>
 *   @0x193fa0 vadd.f32 s15, s15, s14
 *   @0x193fa4 bgt 0x193f58 <_ZN9CInstance11Adapt_SpeedEv+0x2c>
 *   @0x193fa8 vcmpe.f32 s14, #0
 *   @0x193fac vmrs APSR_nzcv, fpscr
 *   @0x193fb0 bpl 0x193f70 <_ZN9CInstance11Adapt_SpeedEv+0x44>
 *   @0x193fb4 vcmpe.f32 s15, #0
 *   @0x193fb8 vmrs APSR_nzcv, fpscr
 *   @0x193fbc ble 0x193fd0 <_ZN9CInstance11Adapt_SpeedEv+0xa4>
 *   @0x193fc0 mov r0, r4
 *   @0x193fc4 mov r1, #0
 *   @0x193fc8 bl 0x1930d4 <_ZN9CInstance8SetSpeedEf>
 *   @0x193fcc b 0x193f7c <_ZN9CInstance11Adapt_SpeedEv+0x50>
 *   @0x193fd0 mov r0, r4
 *   @0x193fd4 vmov r1, s15
 *   @0x193fd8 bl 0x1930d4 <_ZN9CInstance8SetSpeedEf>
 *   @0x193fdc b 0x193f7c <_ZN9CInstance11Adapt_SpeedEv+0x50>
 *
 * ══ §94/159 Object_ClearAllInstanceInfo  0x19f21c  size 180  45 条（0x19f21c..0x19f2d0）
 * @func 0x19f21c 0x19f2d0  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CObjectGM::ClearInstanceInfo()
 * 字段偏移 top8: 0x4×3 / 0xc×2 / 0xa8×1 / 0x3×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19f21c ldr r3, [pc, #0xa8]
 *   @0x19f220 push {r4, r5, r6, lr}
 *   @0x19f224 ldr r3, [pc, r3]
 *   @0x19f228 mov r5, #0
 *   @0x19f22c ldr r6, [r3]
 *   @0x19f230 ldr r2, [r6]
 *   @0x19f234 b 0x19f248 <_Z27Object_ClearAllInstanceInfov+0x2c>
 *   @0x19f238 ldr r3, [r6, #0x4]
 *   @0x19f23c add r5, r5, #1
 *   @0x19f240 cmp r5, r3
 *   @0x19f244 bgt 0x19f2c8 <_Z27Object_ClearAllInstanceInfov+0xac>
 *   @0x19f248 ldr r4, [r2, r5, lsl #3]
 *   @0x19f24c cmp r4, #0
 *   @0x19f250 beq 0x19f238 <_Z27Object_ClearAllInstanceInfov+0x1c>
 *   @0x19f254 ldr r0, [r4, #0xc]
 *   @0x19f258 cmp r0, #0
 *   @0x19f25c bne 0x19f270 <_Z27Object_ClearAllInstanceInfov+0x54>
 *   @0x19f260 pop {r4, r5, r6, pc}
 *   @0x19f264 ldr r0, [r4, #0xc]
 *   @0x19f268 cmp r0, #0
 *   @0x19f26c beq 0x19f2c4 <_Z27Object_ClearAllInstanceInfov+0xa8>
 *   @0x19f270 bl 0x19d36c <_ZN9CObjectGM17ClearInstanceInfoEv>
 *   @0x19f274 cmp r4, #0
 *   @0x19f278 popeq {r4, r5, r6, pc}
 *   @0x19f27c ldr r4, [r4, #0x4]
 *   @0x19f280 cmp r4, #0
 *   @0x19f284 bne 0x19f264 <_Z27Object_ClearAllInstanceInfov+0x48>
 *   @0x19f288 ldr r1, [r6, #0x4]
 *   @0x19f28c add r3, r5, #1
 *   @0x19f290 cmp r3, r1
 *   @0x19f294 popgt {r4, r5, r6, pc}
 *   @0x19f298 ldr r2, [r6]
 *   @0x19f29c add r2, r2, r5, lsl #3
 *   @0x19f2a0 ldr r4, [r2, #0x8]
 *   @0x19f2a4 mov r5, r3
 *   @0x19f2a8 add r2, r2, #8
 *   @0x19f2ac add r3, r3, #1
 *   @0x19f2b0 cmp r4, #0
 *   @0x19f2b4 bne 0x19f264 <_Z27Object_ClearAllInstanceInfov+0x48>
 *   @0x19f2b8 cmp r1, r3
 *   @0x19f2bc bge 0x19f2a0 <_Z27Object_ClearAllInstanceInfov+0x84>
 *   @0x19f2c0 pop {r4, r5, r6, pc}
 *   @0x19f2c4 pop {r4, r5, r6, pc}
 *   @0x19f2c8 pop {r4, r5, r6, pc}
 *   @0x19f2cc eoreq lr, r4, r8, lsl r10
 *
 * ══ §95/159 CLayerManager::CleanOldTilemapElementRuntimeData  0x1b8e0c  size 180  45 条（0x1b8e0c..0x1b8ec0）
 * @func 0x1b8e0c 0x1b8ec0  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x24×2 / 0x2c×2 / 0x8×2 / 0x708×2 / 0x704×2 / 0x98×1 / 0x4×1 / 0x700×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b8e0c ldr r3, [r0, #0x24]
 *   @0x1b8e10 push {r4, r5, r6, r7, r8}
 *   @0x1b8e14 cmp r3, #0
 *   @0x1b8e18 beq 0x1b8eb4 <_ZN13CLayerManager33CleanOldTilemapElementRuntimeDataEP23CLayerOldTilemapElement+0xa8>
 *   @0x1b8e1c ldr r7, [pc, #0x98]
 *   @0x1b8e20 mov r1, #0
 *   @0x1b8e24 ldr r6, [r0, #0x2c]
 *   @0x1b8e28 ldr r7, [pc, r7]
 *   @0x1b8e2c ldr r4, [r7, #0x8]
 *   @0x1b8e30 ldr r12, [r7]
 *   @0x1b8e34 ldr r8, [r7, #0x4]
 *   @0x1b8e38 add r4, r4, #1
 *   @0x1b8e3c b 0x1b8e48 <_ZN13CLayerManager33CleanOldTilemapElementRuntimeDataEP23CLayerOldTilemapElement+0x3c>
 *   @0x1b8e40 mov r12, r3
 *   @0x1b8e44 mov r3, r2
 *   @0x1b8e48 ldr r2, [r3, #0x708]
 *   @0x1b8e4c sub r6, r6, #1
 *   @0x1b8e50 ldr r5, [r3, #0x704]
 *   @0x1b8e54 cmp r2, #0
 *   @0x1b8e58 strne r5, [r2, #0x704]
 *   @0x1b8e5c ldrne r5, [r3, #0x704]
 *   @0x1b8e60 ldrne r2, [r3, #0x708]
 *   @0x1b8e64 streq r5, [r0, #0x24]
 *   @0x1b8e68 cmp r5, #0
 *   @0x1b8e6c streq r2, [r0, #0x28]
 *   @0x1b8e70 strne r2, [r5, #0x708]
 *   @0x1b8e74 cmp r12, #0
 *   @0x1b8e78 str r1, [r3, #0x704]
 *   @0x1b8e7c mov r5, r4
 *   @0x1b8e80 str r1, [r3, #0x708]
 *   @0x1b8e84 moveq r8, r3
 *   @0x1b8e88 str r1, [r3, #0x700]
 *   @0x1b8e8c add r4, r4, #1
 *   @0x1b8e90 strne r3, [r12, #0x708]
 *   @0x1b8e94 strne r12, [r3, #0x704]
 *   @0x1b8e98 strne r1, [r3, #0x708]
 *   @0x1b8e9c ldr r2, [r0, #0x24]
 *   @0x1b8ea0 cmp r2, #0
 *   @0x1b8ea4 bne 0x1b8e40 <_ZN13CLayerManager33CleanOldTilemapElementRuntimeDataEP23CLayerOldTilemapElement+0x34>
 *   @0x1b8ea8 str r6, [r0, #0x2c]
 *   @0x1b8eac str r5, [r7, #0x8]
 *   @0x1b8eb0 stm r7, {r3, r8}
 *   @0x1b8eb4 pop {r4, r5, r6, r7, r8}
 *   @0x1b8eb8 bx lr
 *   @0x1b8ebc eoreq r7, r3, r4, asr r10
 *
 * ══ §96/159 CPhysicsWorld::DestroyBodies  0x237e94  size 180  45 条（0x237e94..0x237f48）
 * @func 0x237e94 0x237f48  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsObject::~CPhysicsObject() / operator delete(void*)
 * 字段偏移 top8: 0x84×2 / 0x178×2 / 0xa8×1 / 0x80×1 / 0x10×1 / 0x70×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x237e94 ldr r3, [pc, #0xa8]
 *   @0x237e98 movw r2, #0xfeee
 *   @0x237e9c push {r4, r5, r6, r7, r8, lr}
 *   @0x237ea0 ldr r3, [pc, r3]
 *   @0x237ea4 movt r2, #0xfeee
 *   @0x237ea8 mov r7, r0
 *   @0x237eac ldr r3, [r3]
 *   @0x237eb0 ldr r4, [r3, #0x80]
 *   @0x237eb4 cmp r4, r2
 *   @0x237eb8 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x237ebc cmp r4, #0
 *   @0x237ec0 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x237ec4 movw r6, #0x9228
 *   @0x237ec8 movt r6, #0x1
 *   @0x237ecc mov r8, #0
 *   @0x237ed0 ldr r5, [r4, #0x84]
 *   @0x237ed4 cmp r5, #0
 *   @0x237ed8 beq 0x237f10 <_ZN13CPhysicsWorld13DestroyBodiesEv+0x7c>
 *   @0x237edc ldr r3, [r7, #0x10]
 *   @0x237ee0 ldr r3, [r3, r6]
 *   @0x237ee4 cmp r3, #0
 *   @0x237ee8 beq 0x237f10 <_ZN13CPhysicsWorld13DestroyBodiesEv+0x7c>
 *   @0x237eec ldr r2, [r5]
 *   @0x237ef0 cmp r3, r2
 *   @0x237ef4 bne 0x237f04 <_ZN13CPhysicsWorld13DestroyBodiesEv+0x70>
 *   @0x237ef8 b 0x237f20 <_ZN13CPhysicsWorld13DestroyBodiesEv+0x8c>
 *   @0x237efc cmp r3, r2
 *   @0x237f00 beq 0x237f20 <_ZN13CPhysicsWorld13DestroyBodiesEv+0x8c>
 *   @0x237f04 ldr r3, [r3, #0x70]
 *   @0x237f08 cmp r3, #0
 *   @0x237f0c bne 0x237efc <_ZN13CPhysicsWorld13DestroyBodiesEv+0x68>
 *   @0x237f10 ldr r4, [r4, #0x178]
 *   @0x237f14 cmp r4, #0
 *   @0x237f18 bne 0x237ed0 <_ZN13CPhysicsWorld13DestroyBodiesEv+0x3c>
 *   @0x237f1c pop {r4, r5, r6, r7, r8, pc}
 *   @0x237f20 mov r0, r5
 *   @0x237f24 bl 0x236c60 <_ZN14CPhysicsObjectD2Ev>
 *   @0x237f28 mov r0, r5
 *   @0x237f2c bl 0x27d1d0 <_ZdlPv>
 *   @0x237f30 str r8, [r4, #0x84]
 *   @0x237f34 ldr r4, [r4, #0x178]
 *   @0x237f38 cmp r4, #0
 *   @0x237f3c bne 0x237ed0 <_ZN13CPhysicsWorld13DestroyBodiesEv+0x3c>
 *   @0x237f40 b 0x237f1c <_ZN13CPhysicsWorld13DestroyBodiesEv+0x88>
 *   @0x237f44 andseq r5, r11, r8, lsl #21
 *
 * ══ §97/159 multadd_D2A  0x23d368  size 180  45 条（0x23d368..0x23d41c）
 * @func 0x23d368 0x23d41c  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Balloc_D2A / 0xb65bc / Bfree_D2A
 * 字段偏移 top8: 0x10×3 / 0x4×2 / 0x8×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23d368 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x23d36c mov r9, r0
 *   @0x23d370 ldr r8, [r0, #0x10]
 *   @0x23d374 add r0, r0, #20
 *   @0x23d378 mov r6, r2
 *   @0x23d37c asr r7, r2, #31
 *   @0x23d380 asr r3, r1, #31
 *   @0x23d384 mov r2, r1
 *   @0x23d388 mov r1, #0
 *   @0x23d38c ldr r12, [r0]
 *   @0x23d390 add r1, r1, #1
 *   @0x23d394 umull r4, r5, r12, r2
 *   @0x23d398 adds r4, r4, r6
 *   @0x23d39c str r4, [r0], #4
 *   @0x23d3a0 mla r5, r12, r3, r5
 *   @0x23d3a4 adc r5, r5, r7
 *   @0x23d3a8 cmp r8, r1
 *   @0x23d3ac mov r7, #0
 *   @0x23d3b0 mov r6, r5
 *   @0x23d3b4 bgt 0x23d38c <multadd_D2A+0x24>
 *   @0x23d3b8 orrs r3, r6, r7
 *   @0x23d3bc beq 0x23d3dc <multadd_D2A+0x74>
 *   @0x23d3c0 ldr r3, [r9, #0x8]
 *   @0x23d3c4 cmp r8, r3
 *   @0x23d3c8 bge 0x23d3e4 <multadd_D2A+0x7c>
 *   @0x23d3cc add r3, r9, r8, lsl #2
 *   @0x23d3d0 add r8, r8, #1
 *   @0x23d3d4 str r6, [r3, #0x14]
 *   @0x23d3d8 str r8, [r9, #0x10]
 *   @0x23d3dc mov r0, r9
 *   @0x23d3e0 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x23d3e4 ldr r0, [r9, #0x4]
 *   @0x23d3e8 add r0, r0, #1
 *   @0x23d3ec bl 0x23d1f8 <Balloc_D2A>
 *   @0x23d3f0 ldr r2, [r9, #0x10]
 *   @0x23d3f4 add r1, r9, #12
 *   @0x23d3f8 lsl r2, r2, #2
 *   @0x23d3fc add r2, r2, #8
 *   @0x23d400 mov r4, r0
 *   @0x23d404 add r0, r0, #12
 *   @0x23d408 bl 0xb65bc <memcpy@plt>
 *   @0x23d40c mov r0, r9
 *   @0x23d410 bl 0x23d2a0 <Bfree_D2A>
 *   @0x23d414 mov r9, r4
 *   @0x23d418 b 0x23d3cc <multadd_D2A+0x64>
 *
 * ══ §98/159 DebuggerMessageLoop  0x29d634  size 180  45 条（0x29d634..0x29d6e8）
 * @func 0x29d634 0x29d6e8  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x29d644→0x47f297, 0x29d64c→0x542979, 0x29d650→0x757e58, 0x29d658→0x757e4c, 0x29d65c→0x3f2094, 0x29d6b0→0x542978
 * 调用序列: Timing_Time / ProcessMessages() / DbgServer::Process() / DebuggerMessageLoop()+0x48
 * 字段偏移 top8: 0x80×2 / 0x7c×2 / 0x88×1 / 0x84×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29d634 push {r4, r5, r6, r7, r8, lr}
 *   @0x29d638 mov r4, #0
 *   @0x29d63c ldr r7, [pc, #0x88]
 *   @0x29d640 mov r0, #1
 *   @0x29d644 ldr r3, [pc, #0x84]
 *   @0x29d648 add r7, pc, r7
 *   @0x29d64c ldr r12, [pc, #0x80]
 *   @0x29d650 ldr r1, [pc, #0x80]
 *   @0x29d654 ldr lr, [r7, r3]
 *   @0x29d658 ldr r2, [pc, #0x7c]
 *   @0x29d65c ldr r3, [pc, #0x7c]
 *   @0x29d660 strb r4, [lr]
 *   @0x29d664 ldr r4, [r7, r12]
 *   @0x29d668 strb r0, [r4]
 *   @0x29d66c ldr r6, [r7, r1]
 *   @0x29d670 ldr r5, [r7, r2]
 *   @0x29d674 ldr r8, [r7, r3]
 *   @0x29d678 b 0x29d698 <_Z19DebuggerMessageLoopv+0x64>
 *   @0x29d67c ldrb r0, [r4]
 *   @0x29d680 cmp r0, #0
 *   @0x29d684 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x29d688 ldr r3, [r7, r2]
 *   @0x29d68c ldrb r3, [r3]
 *   @0x29d690 cmp r3, #0
 *   @0x29d694 bne 0x29d6c4 <_Z19DebuggerMessageLoopv+0x90>
 *   @0x29d698 bl 0x215148 <Timing_Time>
 *   @0x29d69c strd r0, r1, [r6]
 *   @0x29d6a0 bl 0x28fe64 <_Z15ProcessMessagesv>
 *   @0x29d6a4 ldr r0, [r5]
 *   @0x29d6a8 bl 0x29d62c <_ZN9DbgServer7ProcessEv>
 *   @0x29d6ac ldr r3, [r8]
 *   @0x29d6b0 ldr r2, [pc, #0x2c]
 *   @0x29d6b4 cmp r3, #0
 *   @0x29d6b8 blt 0x29d67c <_Z19DebuggerMessageLoopv+0x48>
 *   @0x29d6bc mov r0, #1
 *   @0x29d6c0 pop {r4, r5, r6, r7, r8, pc}
 *   @0x29d6c4 mov r0, #0
 *   @0x29d6c8 pop {r4, r5, r6, r7, r8, pc}
 *   @0x29d6cc andseq r4, r5, r8, lsl #12
 *   @0x29d6d0 .word 0xffffc0ec
 *   @0x29d6d4 .word 0xffffdfa0
 *   @0x29d6d8 .word 0xfffffdc4
 *   @0x29d6dc .word 0xffffc0a4
 *   @0x29d6e0 .word 0xffffc0e8
 *   @0x29d6e4 .word 0xffffeec0
 *
 * ══ §99/159 CProfiler::Pop  0x2a08ac  size 180  45 条（0x2a08ac..0x2a0960）
 * @func 0x2a08ac 0x2a0960  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Timing_Time / CProfiler::Pop()+0xa8
 * 字段偏移 top8: 0x8×4 / 0x20×2 / 0x70×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a08ac push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x2a08b0 mov r8, r0
 *   @0x2a08b4 bl 0x215148 <Timing_Time>
 *   @0x2a08b8 ldr r4, [r8, #0x8]
 *   @0x2a08bc ldrd r2, r3, [r8]
 *   @0x2a08c0 ldr r6, [r8, #0xc]
 *   @0x2a08c4 ldm r4, {r9, r12}
 *   @0x2a08c8 subs r2, r0, r2
 *   @0x2a08cc sbc r3, r1, r3
 *   @0x2a08d0 cmp r12, #0
 *   @0x2a08d4 subgt r12, r12, #1
 *   @0x2a08d8 strgt r12, [r4, #0x4]
 *   @0x2a08dc movle r0, #0
 *   @0x2a08e0 addgt r0, r12, r12, lsl #1
 *   @0x2a08e4 addgt r0, r9, r0, lsl #3
 *   @0x2a08e8 ldr r1, [r0, #0x8]
 *   @0x2a08ec ldrd r4, r5, [r0, #16]
 *   @0x2a08f0 ldr r0, [r6, #0x8]
 *   @0x2a08f4 add r1, r1, r1, lsl #2
 *   @0x2a08f8 subs r2, r2, r4
 *   @0x2a08fc sbc r3, r3, r5
 *   @0x2a0900 add r3, r0, r1, lsl #3
 *   @0x2a0904 ldrd r6, r7, [r3, #8]
 *   @0x2a0908 ldrd r4, r5, [r3, #16]
 *   @0x2a090c adds r6, r6, #1
 *   @0x2a0910 ldr r1, [r3, #0x20]
 *   @0x2a0914 adc r7, r7, #0
 *   @0x2a0918 adds r4, r4, r2
 *   @0x2a091c adc r5, r5, #0
 *   @0x2a0920 cmp r12, #0
 *   @0x2a0924 add r2, r1, r2
 *   @0x2a0928 strd r6, r7, [r3, #8]
 *   @0x2a092c strd r4, r5, [r3, #16]
 *   @0x2a0930 str r2, [r3, #0x20]
 *   @0x2a0934 ble 0x2a0954 <_ZN9CProfiler3PopEv+0xa8>
 *   @0x2a0938 add r12, r12, r12, lsl #1
 *   @0x2a093c add r9, r9, r12, lsl #3
 *   @0x2a0940 subs r9, r9, #24
 *   @0x2a0944 beq 0x2a0954 <_ZN9CProfiler3PopEv+0xa8>
 *   @0x2a0948 ldr r3, [r9, #0x8]
 *   @0x2a094c str r3, [r8, #0x70]
 *   @0x2a0950 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2a0954 mov r3, #0
 *   @0x2a0958 str r3, [r8, #0x70]
 *   @0x2a095c pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §100/159 anon_ce388  0xce388  size 176  44 条（0xce388..0xce438）
 * @func 0xce388 0xce438  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6538 / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool) / 0xb65a4
 * 字段偏移 top8: 0xc×2 / 0x50×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xce388 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xce38c mov r4, r0
 *   @0xce390 ldr r5, [r0]
 *   @0xce394 sub sp, sp, #20
 *   @0xce398 mov r0, r3
 *   @0xce39c mov r8, r2
 *   @0xce3a0 mov r7, r3
 *   @0xce3a4 ldr r11, [r1]
 *   @0xce3a8 mov r10, r1
 *   @0xce3ac bl 0xb6538 <strlen@plt>
 *   @0xce3b0 rsb r9, r11, r5
 *   @0xce3b4 ldr r3, [r8]
 *   @0xce3b8 add r2, r9, #1
 *   @0xce3bc add r2, r0, r2
 *   @0xce3c0 mov r6, r0
 *   @0xce3c4 cmp r3, r2
 *   @0xce3c8 bge 0xce418 <_ZN5CCodeD0Ev+0xac>
 *   @0xce3cc add r2, r2, #1
 *   @0xce3d0 lsl r3, r3, #1
 *   @0xce3d4 cmp r2, r3
 *   @0xce3d8 movge r12, r2
 *   @0xce3dc movlt r12, r3
 *   @0xce3e0 ldr r2, [pc, #0x50]
 *   @0xce3e4 mov r3, #0
 *   @0xce3e8 mov r0, r11
 *   @0xce3ec mov r1, r12
 *   @0xce3f0 str r3, [sp]
 *   @0xce3f4 add r2, pc, r2
 *   @0xce3f8 movw r3, #0x38b
 *   @0xce3fc str r12, [sp, #0xc]
 *   @0xce400 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0xce404 ldr r12, [sp, #0xc]
 *   @0xce408 str r0, [r10]
 *   @0xce40c add r5, r0, r9
 *   @0xce410 str r5, [r4]
 *   @0xce414 str r12, [r8]
 *   @0xce418 mov r0, r5
 *   @0xce41c mov r1, r7
 *   @0xce420 bl 0xb65a4 <strcpy@plt>
 *   @0xce424 ldr r3, [r4]
 *   @0xce428 add r6, r3, r6
 *   @0xce42c str r6, [r4]
 *   @0xce430 add sp, sp, #20
 *   @0xce434 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §101/159 CCamera::SetProjMat  0x16d9e4  size 176  44 条（0x16d9e4..0x16da94）
 * @func 0x16d9e4 0x16daa8  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: yyMatrix::Invert()×2 / yyMatrix::Multiply(yyMatrix*, yyMatrix*, yyMatrix*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16d9e4 push {r4, r5, r6, r7, r8, lr}
 *   @0x16d9e8 mov r6, r1
 *   @0x16d9ec mov r7, r0
 *   @0x16d9f0 add r5, r7, #4
 *   @0x16d9f4 ldm r6!, {r0, r1, r2, r3}
 *   @0x16d9f8 mov r4, r5
 *   @0x16d9fc add r12, r7, #196
 *   @0x16da00 add r8, r7, #132
 *   @0x16da04 stm r5!, {r0, r1, r2, r3}
 *   @0x16da08 ldm r6!, {r0, r1, r2, r3}
 *   @0x16da0c stm r5!, {r0, r1, r2, r3}
 *   @0x16da10 ldm r6!, {r0, r1, r2, r3}
 *   @0x16da14 stm r5!, {r0, r1, r2, r3}
 *   @0x16da18 ldm r6, {r0, r1, r2, r3}
 *   @0x16da1c stm r5, {r0, r1, r2, r3}
 *   @0x16da20 ldm r4!, {r0, r1, r2, r3}
 *   @0x16da24 stm r12!, {r0, r1, r2, r3}
 *   @0x16da28 ldm r4!, {r0, r1, r2, r3}
 *   @0x16da2c stm r12!, {r0, r1, r2, r3}
 *   @0x16da30 ldm r4!, {r0, r1, r2, r3}
 *   @0x16da34 stm r12!, {r0, r1, r2, r3}
 *   @0x16da38 ldm r4, {r0, r1, r2, r3}
 *   @0x16da3c stm r12, {r0, r1, r2, r3}
 *   @0x16da40 add r0, r7, #196
 *   @0x16da44 bl 0x16c65c <_ZN8yyMatrix6InvertEv>
 *   @0x16da48 mov r0, r8
 *   @0x16da4c add r1, r7, #68
 *   @0x16da50 add r2, r7, #4
 *   @0x16da54 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_>
 *   @0x16da58 mov lr, r8
 *   @0x16da5c ldm lr!, {r0, r1, r2, r3}
 *   @0x16da60 add r12, r7, #324
 *   @0x16da64 stm r12!, {r0, r1, r2, r3}
 *   @0x16da68 ldm lr!, {r0, r1, r2, r3}
 *   @0x16da6c stm r12!, {r0, r1, r2, r3}
 *   @0x16da70 ldm lr!, {r0, r1, r2, r3}
 *   @0x16da74 stm r12!, {r0, r1, r2, r3}
 *   @0x16da78 ldm lr, {r0, r1, r2, r3}
 *   @0x16da7c stm r12, {r0, r1, r2, r3}
 *   @0x16da80 add r0, r7, #324
 *   @0x16da84 bl 0x16c65c <_ZN8yyMatrix6InvertEv>
 *   @0x16da88 mov r0, r7
 *   @0x16da8c pop {r4, r5, r6, r7, r8, lr}
 *   @0x16da90 b 0x16d93c <_ZN7CCamera8Update2DEv>
 *
 * ══ §102/159 CCamera::SetViewMat  0x16da94  size 176  44 条（0x16da94..0x16db44）
 * @func 0x16da94 0x16db58  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: yyMatrix::Invert()×2 / yyMatrix::Multiply(yyMatrix*, yyMatrix*, yyMatrix*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16da94 push {r4, r5, r6, r7, r8, lr}
 *   @0x16da98 mov r6, r1
 *   @0x16da9c mov r7, r0
 *   @0x16daa0 add r5, r7, #68
 *   @0x16daa4 ldm r6!, {r0, r1, r2, r3}
 *   @0x16daa8 mov r4, r5
 *   @0x16daac add r12, r7, #260
 *   @0x16dab0 add r8, r7, #132
 *   @0x16dab4 stm r5!, {r0, r1, r2, r3}
 *   @0x16dab8 ldm r6!, {r0, r1, r2, r3}
 *   @0x16dabc stm r5!, {r0, r1, r2, r3}
 *   @0x16dac0 ldm r6!, {r0, r1, r2, r3}
 *   @0x16dac4 stm r5!, {r0, r1, r2, r3}
 *   @0x16dac8 ldm r6, {r0, r1, r2, r3}
 *   @0x16dacc stm r5, {r0, r1, r2, r3}
 *   @0x16dad0 ldm r4!, {r0, r1, r2, r3}
 *   @0x16dad4 stm r12!, {r0, r1, r2, r3}
 *   @0x16dad8 ldm r4!, {r0, r1, r2, r3}
 *   @0x16dadc stm r12!, {r0, r1, r2, r3}
 *   @0x16dae0 ldm r4!, {r0, r1, r2, r3}
 *   @0x16dae4 stm r12!, {r0, r1, r2, r3}
 *   @0x16dae8 ldm r4, {r0, r1, r2, r3}
 *   @0x16daec stm r12, {r0, r1, r2, r3}
 *   @0x16daf0 add r0, r7, #260
 *   @0x16daf4 bl 0x16c65c <_ZN8yyMatrix6InvertEv>
 *   @0x16daf8 mov r0, r8
 *   @0x16dafc add r1, r7, #68
 *   @0x16db00 add r2, r7, #4
 *   @0x16db04 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_>
 *   @0x16db08 mov lr, r8
 *   @0x16db0c ldm lr!, {r0, r1, r2, r3}
 *   @0x16db10 add r12, r7, #324
 *   @0x16db14 stm r12!, {r0, r1, r2, r3}
 *   @0x16db18 ldm lr!, {r0, r1, r2, r3}
 *   @0x16db1c stm r12!, {r0, r1, r2, r3}
 *   @0x16db20 ldm lr!, {r0, r1, r2, r3}
 *   @0x16db24 stm r12!, {r0, r1, r2, r3}
 *   @0x16db28 ldm lr, {r0, r1, r2, r3}
 *   @0x16db2c stm r12, {r0, r1, r2, r3}
 *   @0x16db30 add r0, r7, #324
 *   @0x16db34 bl 0x16c65c <_ZN8yyMatrix6InvertEv>
 *   @0x16db38 mov r0, r7
 *   @0x16db3c pop {r4, r5, r6, r7, r8, lr}
 *   @0x16db40 b 0x16d93c <_ZN7CCamera8Update2DEv>
 *
 * ══ §103/159 GR_Window_View_Define  0x179bfc  size 176  44 条（0x179bfc..0x179cac）
 * @func 0x179bfc 0x179cac  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x14×2 / 0x28×2 / 0x94×1 / 0x4×1 / 0x1c×1 / 0x24×1 / 0x18×1 / 0x2c×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x179bfc cmp r0, #31
 *   @0x179c00 push {r4, r5, r6}
 *   @0x179c04 bhi 0x179c84 <_Z21GR_Window_View_Defineifffffffffii+0x88>
 *   @0x179c08 ldr r4, [pc, #0x94]
 *   @0x179c0c lsl r12, r0, #1
 *   @0x179c10 add r5, r12, r0
 *   @0x179c14 ldr r4, [pc, r4]
 *   @0x179c18 ldrb r5, [r4, r5, lsl #4]
 *   @0x179c1c cmp r5, #0
 *   @0x179c20 beq 0x179c8c <_Z21GR_Window_View_Defineifffffffffii+0x90>
 *   @0x179c24 add r0, r12, r0
 *   @0x179c28 mov r5, #1
 *   @0x179c2c vldr s15, [sp, #12]
 *   @0x179c30 lsl r0, r0, #4
 *   @0x179c34 add r12, r4, r0
 *   @0x179c38 strb r5, [r4, r0]
 *   @0x179c3c vstr s15, [r12, #32]
 *   @0x179c40 str r3, [r12, #0x1c]
 *   @0x179c44 vldr s15, [sp, #16]
 *   @0x179c48 ldr r3, [sp, #0x24]
 *   @0x179c4c vstr s15, [r12, #4]
 *   @0x179c50 str r1, [r12, #0x14]
 *   @0x179c54 vldr s15, [sp, #20]
 *   @0x179c58 str r2, [r12, #0x18]
 *   @0x179c5c vstr s15, [r12, #8]
 *   @0x179c60 str r3, [r12, #0x28]
 *   @0x179c64 vldr s15, [sp, #24]
 *   @0x179c68 ldr r3, [sp, #0x28]
 *   @0x179c6c vstr s15, [r12, #12]
 *   @0x179c70 vldr s15, [sp, #28]
 *   @0x179c74 vstr s15, [r12, #16]
 *   @0x179c78 vldr s15, [sp, #32]
 *   @0x179c7c vstr s15, [r12, #36]
 *   @0x179c80 str r3, [r12, #0x2c]
 *   @0x179c84 pop {r4, r5, r6}
 *   @0x179c88 bx lr
 *   @0x179c8c ldr r5, [pc, #0x14]
 *   @0x179c90 ldr r5, [pc, r5]
 *   @0x179c94 ldr r6, [r5]
 *   @0x179c98 add r6, r6, #1
 *   @0x179c9c str r6, [r5]
 *   @0x179ca0 b 0x179c24 <_Z21GR_Window_View_Defineifffffffffii+0x28>
 *   @0x179ca4 eoreq r6, r7, r12, ror #13
 *   @0x179ca8 eoreq r6, r7, r4, ror r6
 *
 * ══ §104/159 GraphicsPerf::Push  0x17b8f0  size 176  44 条（0x17b8f0..0x17b9a0）
 * @func 0x17b8f0 0x17b9a0  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x17b900→0x49932c, 0x17b918→0x499334, 0x17b92c→0x499338, 0x17b934→0x499fc8, 0x17b93c→0x49a018
 * 调用序列: Timing_Time / GraphicsPerf::BeginFrame()
 * 字段偏移 top8: 0x2×2 / 0x88×1 / 0x84×1 / 0x70×1 / 0x60×1 / 0x5c×1 / 0x58×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17b8f0 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x17b8f4 mov r7, r0
 *   @0x17b8f8 ldr r4, [pc, #0x88]
 *   @0x17b8fc mov r6, r1
 *   @0x17b900 ldr r3, [pc, #0x84]
 *   @0x17b904 add r4, pc, r4
 *   @0x17b908 ldr r3, [r4, r3]
 *   @0x17b90c ldr r3, [r3]
 *   @0x17b910 cmp r3, #0
 *   @0x17b914 beq 0x17b980 <_ZN12GraphicsPerf4PushEjPKc+0x90>
 *   @0x17b918 ldr r3, [pc, #0x70]
 *   @0x17b91c ldr r2, [r4, r3]
 *   @0x17b920 ldr r3, [r2]
 *   @0x17b924 cmp r3, #1024
 *   @0x17b928 pophs {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x17b92c ldr lr, [pc, #0x60]
 *   @0x17b930 add r12, r3, #1
 *   @0x17b934 ldr r0, [pc, #0x5c]
 *   @0x17b938 lsl r9, r3, #5
 *   @0x17b93c ldr r1, [pc, #0x58]
 *   @0x17b940 ldr r5, [r4, lr]
 *   @0x17b944 str r12, [r2]
 *   @0x17b948 ldr r8, [r4, r0]
 *   @0x17b94c ldr r3, [r5]
 *   @0x17b950 ldr r4, [r4, r1]
 *   @0x17b954 add r2, r9, r4
 *   @0x17b958 str r2, [r8, r3, lsl #2]
 *   @0x17b95c bl 0x215148 <Timing_Time>
 *   @0x17b960 ldr r3, [r5]
 *   @0x17b964 add r2, r3, #1
 *   @0x17b968 str r2, [r5]
 *   @0x17b96c ldr r2, [r8, r3, lsl #2]
 *   @0x17b970 strd r0, r1, [r4, r9]
 *   @0x17b974 str r7, [r2, #0x10]
 *   @0x17b978 str r6, [r2, #0x18]
 *   @0x17b97c pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x17b980 bl 0x17b9a0 <_ZN12GraphicsPerf10BeginFrameEv>
 *   @0x17b984 b 0x17b918 <_ZN12GraphicsPerf4PushEjPKc+0x28>
 *   @0x17b988 eoreq r6, r7, r12, asr #6
 *   @0x17b98c .word 0xffffe6e0
 *   @0x17b990 .word 0xffffe730
 *   @0x17b994 .word 0xffffe6dc
 *   @0x17b998 .word 0xffffe734
 *   @0x17b99c .word 0xffffe738
 *
 * ══ §105/159 YYObjectBase::AllocVars  0x1917dc  size 176  44 条（0x1917dc..0x19188c）
 * @func 0x1917dc 0x19188c  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int) / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb65b0 / YYObjectBase::AllocVars()+0xa0
 * 字段偏移 top8: 0x10×3 / 0x8×2 / 0x5c×1 / 0x8c×1 / 0x4×1 / 0x60×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1917dc push {r4, r5, r6, lr}
 *   @0x1917e0 mov r6, r0
 *   @0x1917e4 mov r5, #0
 *   @0x1917e8 mov r0, #20
 *   @0x1917ec str r5, [r6, #0x5c]
 *   @0x1917f0 bl 0x27c524 <_Znwj>
 *   @0x1917f4 ldr r1, [pc, #0x8c]
 *   @0x1917f8 mov r2, #8
 *   @0x1917fc mov r3, #7
 *   @0x191800 add r1, pc, r1
 *   @0x191804 mov r4, r0
 *   @0x191808 str r2, [r0]
 *   @0x19180c str r3, [r0, #0x8]
 *   @0x191810 mov r2, #70
 *   @0x191814 str r5, [r0, #0x10]
 *   @0x191818 mov r3, #1
 *   @0x19181c mov r0, #96
 *   @0x191820 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x191824 mov r2, #96
 *   @0x191828 mov r1, r5
 *   @0x19182c str r0, [r4, #0x10]
 *   @0x191830 bl 0xb65b0 <memset@plt>
 *   @0x191834 ldr r2, [r4]
 *   @0x191838 vldr s15, [pc, #68]
 *   @0x19183c str r5, [r4, #0x4]
 *   @0x191840 cmp r2, r5
 *   @0x191844 vmov s13, r2
 *   @0x191848 vcvt.f32.s32 s14, s13
 *   @0x19184c vmul.f32 s15, s14, s15
 *   @0x191850 vcvt.s32.f32 s15, s15
 *   @0x191854 vstr s15, [r4, #12]
 *   @0x191858 ble 0x19187c <_ZN12YYObjectBase9AllocVarsEv+0xa0>
 *   @0x19185c add r2, r2, r2, lsl #1
 *   @0x191860 ldr r3, [r4, #0x10]
 *   @0x191864 mov r1, r5
 *   @0x191868 add r2, r3, r2, lsl #2
 *   @0x19186c str r1, [r3, #0x8]
 *   @0x191870 add r3, r3, #12
 *   @0x191874 cmp r3, r2
 *   @0x191878 bne 0x19186c <_ZN12YYObjectBase9AllocVarsEv+0x90>
 *   @0x19187c str r4, [r6, #0x60]
 *   @0x191880 pop {r4, r5, r6, pc}
 *   @0x191884 svclo #0x19999a
 *   @0x191888 andseq pc, r9, r0, lsr r8
 *
 * ══ §106/159 GetJObjectToDouble  0x214968  size 176  44 条（0x214968..0x214a18）
 * @func 0x214968 0x214a18  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv×5
 * 字段偏移 top8: 0x54×2 / 0x90×1 / 0x18×1 / 0x80×1 / 0x84×1 / 0x5c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x214968 push {r4, r5, r6, lr}
 *   @0x21496c mov r5, r0
 *   @0x214970 bl 0x290274 <getJNIEnv>
 *   @0x214974 ldr r1, [pc, #0x90]
 *   @0x214978 add r1, pc, r1
 *   @0x21497c ldr r3, [r0]
 *   @0x214980 ldr r3, [r3, #0x18]
 *   @0x214984 blx r3
 *   @0x214988 subs r4, r0, #0
 *   @0x21498c beq 0x214a00 <_Z18GetJObjectToDoubleP8_jobject+0x98>
 *   @0x214990 bl 0x290274 <getJNIEnv>
 *   @0x214994 mov r1, r5
 *   @0x214998 mov r2, r4
 *   @0x21499c ldr r3, [r0]
 *   @0x2149a0 ldr r3, [r3, #0x80]
 *   @0x2149a4 blx r3
 *   @0x2149a8 cmp r0, #0
 *   @0x2149ac beq 0x214a00 <_Z18GetJObjectToDoubleP8_jobject+0x98>
 *   @0x2149b0 bl 0x290274 <getJNIEnv>
 *   @0x2149b4 ldr r2, [pc, #0x54]
 *   @0x2149b8 ldr r3, [pc, #0x54]
 *   @0x2149bc mov r1, r4
 *   @0x2149c0 add r2, pc, r2
 *   @0x2149c4 add r3, pc, r3
 *   @0x2149c8 ldr r12, [r0]
 *   @0x2149cc ldr r12, [r12, #0x84]
 *   @0x2149d0 blx r12
 *   @0x2149d4 mov r6, r0
 *   @0x2149d8 bl 0x290274 <getJNIEnv>
 *   @0x2149dc mov r1, r4
 *   @0x2149e0 ldr r3, [r0]
 *   @0x2149e4 ldr r3, [r3, #0x5c]
 *   @0x2149e8 blx r3
 *   @0x2149ec bl 0x290274 <getJNIEnv>
 *   @0x2149f0 mov r1, r5
 *   @0x2149f4 mov r2, r6
 *   @0x2149f8 pop {r4, r5, r6, lr}
 *   @0x2149fc b 0x2148c4 <_ZN7_JNIEnv16CallDoubleMethodEP8_jobjectP10_jmethodIDz>
 *   @0x214a00 mov r0, #0
 *   @0x214a04 mov r1, #0
 *   @0x214a08 pop {r4, r5, r6, pc}
 *   @0x214a0c andseq pc, r3, r12, asr #32
 *   @0x214a10 andseq pc, r3, r8, lsl r0
 *   @0x214a14 andseq pc, r3, r0, lsr #32
 *
 * ══ §107/159 Audio_Prepare  0x2194e0  size 176  44 条（0x2194e0..0x219590）
 * @func 0x2194e0 0x219590  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CAudioGroupMan::InitSoundLists(cARRAY_CLASS<cAudio_Sound*>&) / Audio_Prepare()+0x84 / cAudio_Sound::Prepare(int)
 * 字段偏移 top8: 0x6c×2 / 0x20×2 / 0x8c×1 / 0x7c×1 / 0x50×1 / 0x4c×1 / 0x24×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2194e0 push {r3, r4, r5, r6, r7, lr}
 *   @0x2194e4 ldr r3, [pc, #0x8c]
 *   @0x2194e8 ldr r3, [pc, r3]
 *   @0x2194ec ldrb r4, [r3]
 *   @0x2194f0 cmp r4, #0
 *   @0x2194f4 popne {r3, r4, r5, r6, r7, pc}
 *   @0x2194f8 ldr r3, [pc, #0x7c]
 *   @0x2194fc ldr r3, [pc, r3]
 *   @0x219500 ldrb r3, [r3]
 *   @0x219504 cmp r3, #0
 *   @0x219508 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x21950c ldr r5, [pc, #0x6c]
 *   @0x219510 ldr r0, [pc, #0x6c]
 *   @0x219514 add r5, pc, r5
 *   @0x219518 add r1, r5, #32
 *   @0x21951c ldr r0, [pc, r0]
 *   @0x219520 bl 0x21df78 <_ZN14CAudioGroupMan14InitSoundListsER12cARRAY_CLASSIP12cAudio_SoundE>
 *   @0x219524 ldr r5, [r5, #0x20]
 *   @0x219528 cmp r5, #0
 *   @0x21952c pople {r3, r4, r5, r6, r7, pc}
 *   @0x219530 ldr r7, [pc, #0x50]
 *   @0x219534 mov r3, r5
 *   @0x219538 ldr r6, [pc, #0x4c]
 *   @0x21953c add r7, pc, r7
 *   @0x219540 add r6, pc, r6
 *   @0x219544 cmp r3, r4
 *   @0x219548 mov r1, #0
 *   @0x21954c ble 0x219564 <_Z13Audio_Preparev+0x84>
 *   @0x219550 ldr r3, [r7, #0x24]
 *   @0x219554 ldr r0, [r3, r4, lsl #2]
 *   @0x219558 cmp r0, r1
 *   @0x21955c beq 0x219564 <_Z13Audio_Preparev+0x84>
 *   @0x219560 bl 0x219404 <_ZN12cAudio_Sound7PrepareEi>
 *   @0x219564 add r4, r4, #1
 *   @0x219568 cmp r4, r5
 *   @0x21956c popeq {r3, r4, r5, r6, r7, pc}
 *   @0x219570 ldr r3, [r6, #0x20]
 *   @0x219574 b 0x219544 <_Z13Audio_Preparev+0x64>
 *   @0x219578 andseq r5, sp, r4, ror #22
 *   @0x21957c andseq r5, sp, r4, lsr r8
 *   @0x219580 subseq r11, r3, r0, lsl #27
 *   @0x219584 andseq r5, sp, r4, lsr r11
 *   @0x219588 subseq r11, r3, r8, asr sp
 *   @0x21958c subseq r11, r3, r4, asr sp
 *
 * ══ §108/159 InitNetworkEvent  0x29871c  size 176  44 条（0x29871c..0x2987cc）
 * @func 0x29871c 0x2987cc  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: InitNetworkEvent()+0x74 / F_DsMapClear(RValue&, CInstance*, CInstance*, int, RValue*) / F_DsMapCreate(RValue&, CInstance*, CInstance*, int, RValue*)
 * 字段偏移 top8: 0x4×2 / 0x98×1 / 0x94×1 / 0xc×1 / 0x1c×1 / 0x10×1 / 0x14×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29871c push {r4, r5, lr}
 *   @0x298720 mov r3, #0
 *   @0x298724 ldr r5, [pc, #0x98]
 *   @0x298728 sub sp, sp, #28
 *   @0x29872c ldr r12, [pc, #0x94]
 *   @0x298730 ldr r5, [pc, r5]
 *   @0x298734 ldr r12, [pc, r12]
 *   @0x298738 ldr r4, [r5]
 *   @0x29873c str r3, [r12, #0xc]
 *   @0x298740 cmp r4, r3
 *   @0x298744 str r3, [r12]
 *   @0x298748 str r3, [r12, #0x4]
 *   @0x29874c str r3, [r12, #0x1c]
 *   @0x298750 str r3, [r12, #0x10]
 *   @0x298754 str r3, [r12, #0x14]
 *   @0x298758 blt 0x298790 <_Z16InitNetworkEventv+0x74>
 *   @0x29875c vmov s15, r4
 *   @0x298760 mov r1, r3
 *   @0x298764 mov r2, r3
 *   @0x298768 add r0, sp, #8
 *   @0x29876c vcvt.f64.s32 d7, s15
 *   @0x298770 mov r3, #1
 *   @0x298774 vmov r4, r5, d7
 *   @0x298778 mov lr, r5
 *   @0x29877c stm r12, {r4, lr}
 *   @0x298780 str r12, [sp]
 *   @0x298784 bl 0xfed40 <_Z12F_DsMapClearR6RValueP9CInstanceS2_iPS_>
 *   @0x298788 add sp, sp, #28
 *   @0x29878c pop {r4, r5, pc}
 *   @0x298790 mov r1, r3
 *   @0x298794 mov r2, r3
 *   @0x298798 add r0, sp, #8
 *   @0x29879c movt r3, #0x4020
 *   @0x2987a0 str r3, [r12, #0x4]
 *   @0x2987a4 mov r3, #1
 *   @0x2987a8 str r12, [sp]
 *   @0x2987ac bl 0x1000f4 <_Z13F_DsMapCreateR6RValueP9CInstanceS2_iPS_>
 *   @0x2987b0 vldr d7, [sp, #8]
 *   @0x2987b4 vcvt.s32.f64 s14, d7
 *   @0x2987b8 vstr s14, [r5]
 *   @0x2987bc add sp, sp, #28
 *   @0x2987c0 pop {r4, r5, pc}
 *   @0x2987c4 andseq r8, r5, r0, ror r12
 *   @0x2987c8 andseq r9, r5, r4, ror r2
 *
 * ══ §109/159 initRenderBufferStack  0x180650  size 172  43 条（0x180650..0x1806fc）
 * @func 0x180650 0x1806fc  size 172  43 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x3c×2 / 0x84×1 / 0x80×1 / 0x74×1 / 0x70×1 / 0x64×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x180650 ldr r3, [pc, #0x84]
 *   @0x180654 mov r1, #0
 *   @0x180658 ldr r2, [pc, #0x80]
 *   @0x18065c mov r0, #1
 *   @0x180660 push {r4, r5, r6}
 *   @0x180664 add r3, pc, r3
 *   @0x180668 ldr r4, [pc, #0x74]
 *   @0x18066c add r2, pc, r2
 *   @0x180670 ldr r12, [pc, #0x70]
 *   @0x180674 str r1, [r3]
 *   @0x180678 ldr r4, [r2, r4]
 *   @0x18067c ldr r12, [r2, r12]
 *   @0x180680 ldr r6, [pc, #0x64]
 *   @0x180684 ldr r4, [r4]
 *   @0x180688 ldr r12, [r12]
 *   @0x18068c str r1, [r3, #0x4]
 *   @0x180690 str r1, [r3, #0x8]
 *   @0x180694 str r1, [r3, #0xc]
 *   @0x180698 str r1, [r3, #0x10]
 *   @0x18069c str r1, [r3, #0x14]
 *   @0x1806a0 str r4, [r3, #0x18]
 *   @0x1806a4 str r12, [r3, #0x1c]
 *   @0x1806a8 ldr r5, [pc, #0x40]
 *   @0x1806ac ldr r6, [r2, r6]
 *   @0x1806b0 ldr r1, [pc, #0x3c]
 *   @0x1806b4 ldr r3, [pc, #0x3c]
 *   @0x1806b8 str r4, [r6]
 *   @0x1806bc ldr r4, [r2, r5]
 *   @0x1806c0 str r12, [r4]
 *   @0x1806c4 ldr r1, [r2, r1]
 *   @0x1806c8 pop {r4, r5, r6}
 *   @0x1806cc str r0, [r1]
 *   @0x1806d0 ldr r3, [r2, r3]
 *   @0x1806d4 strb r0, [r3]
 *   @0x1806d8 bx lr
 *   @0x1806dc mlaseq r2, r8, sp, r1
 *   @0x1806e0 eoreq r1, r7, r4, ror #11
 *   @0x1806e4 .word 0xffffe24c
 *   @0x1806e8 .word 0xffffe250
 *   @0x1806ec .word 0xffffe834
 *   @0x1806f0 .word 0xffffe838
 *   @0x1806f4 .word 0xffffe8e0
 *   @0x1806f8 .word 0xffffe8e4
 *
 * ══ §110/159 SwitchRoom  0x1d4450  size 172  43 条（0x1d4450..0x1d44fc）
 * @func 0x1d4450 0x1d44fc  size 172  43 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Room_Name(int)×3 / memLogEvent(char const*, ...) / EndRoom(bool) / Debug_AddTag(eTagNameType, char const*, ...)
 * 字段偏移 top8: 0x88×1 / 0x78×1 / 0x5c×1 / 0x3c×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d4450 push {r3, r4, r5, lr}
 *   @0x1d4454 mov r4, r0
 *   @0x1d4458 ldr r3, [pc, #0x88]
 *   @0x1d445c ldr r3, [pc, r3]
 *   @0x1d4460 ldrb r3, [r3]
 *   @0x1d4464 cmp r3, #0
 *   @0x1d4468 beq 0x1d4480 <_Z10SwitchRoomi+0x30>
 *   @0x1d446c ldr r3, [pc, #0x78]
 *   @0x1d4470 ldr r3, [pc, r3]
 *   @0x1d4474 ldr r3, [r3]
 *   @0x1d4478 cmp r3, #0
 *   @0x1d447c beq 0x1d44b0 <_Z10SwitchRoomi+0x60>
 *   @0x1d4480 mov r0, r4
 *   @0x1d4484 bl 0x1b530c <_Z9Room_Namei>
 *   @0x1d4488 mov r1, r0
 *   @0x1d448c ldr r0, [pc, #0x5c]
 *   @0x1d4490 add r0, pc, r0
 *   @0x1d4494 bl 0x27ba28 <_Z11memLogEventPKcz>
 *   @0x1d4498 mov r0, #0
 *   @0x1d449c bl 0x1d1724 <_Z7EndRoomb>
 *   @0x1d44a0 mov r0, r4
 *   @0x1d44a4 mov r1, #0
 *   @0x1d44a8 pop {r3, r4, r5, lr}
 *   @0x1d44ac b 0x1d38e0 <_Z9StartRoomib>
 *   @0x1d44b0 ldr r3, [pc, #0x3c]
 *   @0x1d44b4 ldr r3, [pc, r3]
 *   @0x1d44b8 ldr r0, [r3]
 *   @0x1d44bc bl 0x1b530c <_Z9Room_Namei>
 *   @0x1d44c0 mov r5, r0
 *   @0x1d44c4 mov r0, r4
 *   @0x1d44c8 bl 0x1b530c <_Z9Room_Namei>
 *   @0x1d44cc ldr r1, [pc, #0x24]
 *   @0x1d44d0 mov r2, r5
 *   @0x1d44d4 add r1, pc, r1
 *   @0x1d44d8 mov r3, r0
 *   @0x1d44dc mov r0, #2
 *   @0x1d44e0 bl 0x29c3ec <_Z12Debug_AddTag12eTagNameTypePKcz>
 *   @0x1d44e4 b 0x1d4480 <_Z10SwitchRoomi+0x30>
 *   @0x1d44e8 eoreq r9, r1, r8, asr #9
 *   @0x1d44ec .word 0x00219fb0
 *   @0x1d44f0 andseq r12, r7, r12, lsl #25
 *   @0x1d44f4 eoreq r10, r1, r0, lsr #30
 *   @0x1d44f8 andseq r12, r7, r12, lsr #24
 *
 * ══ §111/159 CPhysicsFixtureFactory::DestroyFixture  0x236648  size 172  43 条（0x236648..0x2366f4）
 * @func 0x236648 0x2366f4  size 172  43 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsFixtureFactory::FindFixture(unsigned int) / MemoryManager::Free(void const*) / CPhysicsFixture::~CPhysicsFixture() / operator delete(void*)
 * 字段偏移 top8: 0x8×3 / 0x4×2 / 0x90×1 / 0x1c×1 / 0x3×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x236648 push {r3, r4, r5, lr}
 *   @0x23664c bl 0x236404 <_ZN22CPhysicsFixtureFactory11FindFixtureEj>
 *   @0x236650 subs r5, r0, #0
 *   @0x236654 beq 0x2366e8 <_ZN22CPhysicsFixtureFactory14DestroyFixtureEj+0xa0>
 *   @0x236658 ldr r4, [pc, #0x90]
 *   @0x23665c ldr r1, [r5, #0x1c]
 *   @0x236660 ldr r4, [pc, r4]
 *   @0x236664 ldm r4, {r0, r12}
 *   @0x236668 and r12, r1, r12
 *   @0x23666c ldr r3, [r0, r12, lsl #3]
 *   @0x236670 add lr, r0, r12, lsl #3
 *   @0x236674 cmp r3, #0
 *   @0x236678 bne 0x23668c <_ZN22CPhysicsFixtureFactory14DestroyFixtureEj+0x44>
 *   @0x23667c b 0x2366d0 <_ZN22CPhysicsFixtureFactory14DestroyFixtureEj+0x88>
 *   @0x236680 ldr r3, [r3, #0x4]
 *   @0x236684 cmp r3, #0
 *   @0x236688 beq 0x2366d0 <_ZN22CPhysicsFixtureFactory14DestroyFixtureEj+0x88>
 *   @0x23668c ldr r2, [r3, #0x8]
 *   @0x236690 cmp r1, r2
 *   @0x236694 bne 0x236680 <_ZN22CPhysicsFixtureFactory14DestroyFixtureEj+0x38>
 *   @0x236698 ldr r2, [r3]
 *   @0x23669c ldr r1, [r3, #0x4]
 *   @0x2366a0 cmp r2, #0
 *   @0x2366a4 strne r1, [r2, #0x4]
 *   @0x2366a8 ldrne r1, [r3, #0x4]
 *   @0x2366ac streq r1, [r0, r12, lsl #3]
 *   @0x2366b0 mov r0, r3
 *   @0x2366b4 cmp r1, #0
 *   @0x2366b8 streq r2, [lr, #0x4]
 *   @0x2366bc strne r2, [r1]
 *   @0x2366c0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x2366c4 ldr r3, [r4, #0x8]
 *   @0x2366c8 sub r3, r3, #1
 *   @0x2366cc str r3, [r4, #0x8]
 *   @0x2366d0 mov r0, r5
 *   @0x2366d4 bl 0x23661c <_ZN15CPhysicsFixtureD2Ev>
 *   @0x2366d8 mov r0, r5
 *   @0x2366dc bl 0x27d1d0 <_ZdlPv>
 *   @0x2366e0 mov r0, #1
 *   @0x2366e4 pop {r3, r4, r5, pc}
 *   @0x2366e8 mov r0, r5
 *   @0x2366ec pop {r3, r4, r5, pc}
 *   @0x2366f0 andseq r10, r11, r4, asr #28
 *
 * ══ §112/159 JS_Number_Constructor  0x24dc90  size 172  43 条（0x24dc90..0x24dd3c）
 * @func 0x24dc90 0x24dd3c  size 172  43 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JS_StandardBuiltInObjectConstructor(RValue&, CInstance*, CInstance*, int, RValue*) / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*) / JS_Number_Constructor(RValue&, CInstance*, CInstance*, int, RValue*)+0x80 / F_JS_ToNumber(RValue&, RValue&) / YYObjectBase::Add(char const*, RValue&, int)
 * 字段偏移 top8: 0x28×3 / 0x7c×1 / 0x74×1 / 0x40×1 / 0x18×1 / 0x10×1 / 0x14×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x24dc90 push {r4, r5, r6, lr}
 *   @0x24dc94 sub sp, sp, #24
 *   @0x24dc98 mov r6, r3
 *   @0x24dc9c mov r4, r0
 *   @0x24dca0 ldr r5, [sp, #0x28]
 *   @0x24dca4 str r5, [sp]
 *   @0x24dca8 bl 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_>
 *   @0x24dcac ldr r2, [pc, #0x7c]
 *   @0x24dcb0 ldr r4, [r4]
 *   @0x24dcb4 ldr r2, [pc, r2]
 *   @0x24dcb8 ldr r3, [pc, #0x74]
 *   @0x24dcbc ldr r1, [r2]
 *   @0x24dcc0 add r3, pc, r3
 *   @0x24dcc4 mov r0, r4
 *   @0x24dcc8 str r3, [r4, #0x40]
 *   @0x24dccc str r1, [r4, #0x18]
 *   @0x24dcd0 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x24dcd4 ldr r1, [r4, #0x28]
 *   @0x24dcd8 cmp r6, #0
 *   @0x24dcdc mov r0, #0
 *   @0x24dce0 mov r2, #0
 *   @0x24dce4 mov r3, #0
 *   @0x24dce8 orr r1, r1, #1
 *   @0x24dcec str r0, [sp, #0x10]
 *   @0x24dcf0 str r0, [sp, #0x14]
 *   @0x24dcf4 add r6, sp, #8
 *   @0x24dcf8 str r1, [r4, #0x28]
 *   @0x24dcfc strd r2, r3, [sp, #8]
 *   @0x24dd00 ble 0x24dd10 <_Z21JS_Number_ConstructorR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x24dd04 mov r1, r5
 *   @0x24dd08 mov r0, r6
 *   @0x24dd0c bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_>
 *   @0x24dd10 ldr r1, [pc, #0x20]
 *   @0x24dd14 mov r0, r4
 *   @0x24dd18 mov r2, r6
 *   @0x24dd1c mov r3, #0
 *   @0x24dd20 add r1, pc, r1
 *   @0x24dd24 bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei>
 *   @0x24dd28 add sp, sp, #24
 *   @0x24dd2c pop {r4, r5, r6, pc}
 *   @0x24dd30 andseq r3, r10, r0, asr r10
 *   @0x24dd34 ldrsbeq r7, [r0], -r0
 *   @0x24dd38 ldrsheq r7, [r0], -r0
 *
 * ══ §113/159 globalPageListFindAddr  0x27be34  size 172  43 条（0x27be34..0x27bee0）
 * @func 0x27be34 0x27bee0  size 172  43 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: globalPageListFindAddr(void const*)+0x78 / globalPageListFindAddr(void const*)+0x28
 * 字段偏移 top8: 0x9c×2 / 0x2×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27be34 ldr r3, [pc, #0x9c]
 *   @0x27be38 ldr r2, [pc, #0x9c]
 *   @0x27be3c ldr r3, [pc, r3]
 *   @0x27be40 ldr r2, [pc, r2]
 *   @0x27be44 push {r4, r5}
 *   @0x27be48 ldr r1, [r2]
 *   @0x27be4c ldr r5, [r3]
 *   @0x27be50 lsl r1, r1, #1
 *   @0x27be54 mov r2, r5
 *   @0x27be58 b 0x27be68 <_Z22globalPageListFindAddrPKv+0x34>
 *   @0x27be5c mvn r3, r3
 *   @0x27be60 add r2, r12, #4
 *   @0x27be64 add r1, r1, r3
 *   @0x27be68 cmp r1, #0
 *   @0x27be6c ble 0x27beac <_Z22globalPageListFindAddrPKv+0x78>
 *   @0x27be70 asr r3, r1, #1
 *   @0x27be74 ldr r4, [r2, r3, lsl #2]
 *   @0x27be78 add r12, r2, r3, lsl #2
 *   @0x27be7c cmp r0, r4
 *   @0x27be80 bhi 0x27be5c <_Z22globalPageListFindAddrPKv+0x28>
 *   @0x27be84 subs r1, r3, #0
 *   @0x27be88 asr r3, r3, #1
 *   @0x27be8c beq 0x27beac <_Z22globalPageListFindAddrPKv+0x78>
 *   @0x27be90 ldr r4, [r2, r3, lsl #2]
 *   @0x27be94 add r12, r2, r3, lsl #2
 *   @0x27be98 cmp r4, r0
 *   @0x27be9c blo 0x27be5c <_Z22globalPageListFindAddrPKv+0x28>
 *   @0x27bea0 subs r1, r3, #0
 *   @0x27bea4 asr r3, r3, #1
 *   @0x27bea8 bne 0x27be90 <_Z22globalPageListFindAddrPKv+0x5c>
 *   @0x27beac rsb r1, r5, r2
 *   @0x27beb0 pop {r4, r5}
 *   @0x27beb4 lsr r3, r1, #31
 *   @0x27beb8 add r1, r3, r1, asr #2
 *   @0x27bebc and r1, r1, #1
 *   @0x27bec0 rsb r3, r3, r1
 *   @0x27bec4 cmp r3, #1
 *   @0x27bec8 ldreq r3, [r2, #-0x4]
 *   @0x27becc movne r0, #0
 *   @0x27bed0 ldreq r0, [r3, #0x4]
 *   @0x27bed4 bx lr
 *   @0x27bed8 ldrsheq r5, [r7], -r4
 *   @0x27bedc andseq r5, r7, r8, ror #19
 *
 * ══ §114/159 b2Body::SynchronizeFixtures  0x2c72cc  size 172  43 条（0x2c72cc..0x2c7378）
 * @func 0x2c72cc 0x2c7378  size 172  43 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6580 / 0xb658c / b2Fixture::Synchronize(b2BroadPhase*, b2Transform const&, b2Transform const&)
 * 字段偏移 top8: 0x44×1 / 0x74×1 / 0x68×1 / 0xc×1 / 0x4×1
 * VFP 指令 17 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c72cc push {r4, r5, r6, r7, lr}
 *   @0x2c72d0 vpush {d8}
 *   @0x2c72d4 mov r7, r0
 *   @0x2c72d8 ldr r4, [r0, #0x44]
 *   @0x2c72dc sub sp, sp, #20
 *   @0x2c72e0 mov r0, r4
 *   @0x2c72e4 bl 0xb6580 <sinf@plt>
 *   @0x2c72e8 vmov s16, r0
 *   @0x2c72ec mov r0, r4
 *   @0x2c72f0 vstr s16, [sp, #8]
 *   @0x2c72f4 bl 0xb658c <cosf@plt>
 *   @0x2c72f8 vldr s15, [r7, #48]
 *   @0x2c72fc vmul.f32 s14, s15, s16
 *   @0x2c7300 vldr s12, [r7, #44]
 *   @0x2c7304 vldr s11, [r7, #56]
 *   @0x2c7308 vldr s10, [r7, #52]
 *   @0x2c730c ldr r4, [r7, #0x74]
 *   @0x2c7310 ldr r5, [r7, #0x68]
 *   @0x2c7314 cmp r4, #0
 *   @0x2c7318 add r5, r5, #102400
 *   @0x2c731c add r5, r5, #472
 *   @0x2c7320 vmov s13, r0
 *   @0x2c7324 str r0, [sp, #0xc]
 *   @0x2c7328 vmul.f32 s15, s15, s13
 *   @0x2c732c vnmls.f32 s14, s12, s13
 *   @0x2c7330 vmla.f32 s15, s12, s16
 *   @0x2c7334 vsub.f32 s14, s10, s14
 *   @0x2c7338 vsub.f32 s15, s11, s15
 *   @0x2c733c vstr s14, [sp]
 *   @0x2c7340 vstr s15, [sp, #4]
 *   @0x2c7344 beq 0x2c736c <_ZN6b2Body19SynchronizeFixturesEv+0xa0>
 *   @0x2c7348 add r7, r7, #12
 *   @0x2c734c mov r0, r4
 *   @0x2c7350 mov r1, r5
 *   @0x2c7354 mov r2, sp
 *   @0x2c7358 mov r3, r7
 *   @0x2c735c bl 0x2c87cc <_ZN9b2Fixture11SynchronizeEP12b2BroadPhaseRK11b2TransformS4_>
 *   @0x2c7360 ldr r4, [r4, #0x4]
 *   @0x2c7364 cmp r4, #0
 *   @0x2c7368 bne 0x2c734c <_ZN6b2Body19SynchronizeFixturesEv+0x80>
 *   @0x2c736c add sp, sp, #20
 *   @0x2c7370 vpop {d8}
 *   @0x2c7374 pop {r4, r5, r6, r7, pc}
 *
 * ══ §115/159 b2ParticleSystem::DestroyParticleGroup  0x2d5874  size 172  43 条（0x2d5874..0x2d5920）
 * @func 0x2d5874 0x2d5920  size 172  43 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2ParticleGroup::~b2ParticleGroup()
 * 字段偏移 top8: 0xd4×2 / 0xa4×2 / 0x10×1 / 0x5c×1 / 0x14×1 / 0x18×1 / 0xa8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d5874 ldr r2, [r0, #0xd4]
 *   @0x2d5878 movw r3, #0x9244
 *   @0x2d587c movt r3, #0x1
 *   @0x2d5880 push {r4, r5, r6, lr}
 *   @0x2d5884 mov r4, r0
 *   @0x2d5888 ldr r0, [r2, r3]
 *   @0x2d588c mov r6, r1
 *   @0x2d5890 cmp r0, #0
 *   @0x2d5894 beq 0x2d58a4 <_ZN16b2ParticleSystem20DestroyParticleGroupEP15b2ParticleGroup+0x30>
 *   @0x2d5898 ldr r3, [r0]
 *   @0x2d589c ldr r3, [r3, #0x10]
 *   @0x2d58a0 blx r3
 *   @0x2d58a4 ldmib r6, {r3, lr}
 *   @0x2d58a8 cmp r3, lr
 *   @0x2d58ac lsllt r2, r3, #2
 *   @0x2d58b0 movlt r5, #0
 *   @0x2d58b4 bge 0x2d58d0 <_ZN16b2ParticleSystem20DestroyParticleGroupEP15b2ParticleGroup+0x5c>
 *   @0x2d58b8 add r3, r3, #1
 *   @0x2d58bc ldr r12, [r4, #0x5c]
 *   @0x2d58c0 cmp r3, lr
 *   @0x2d58c4 str r5, [r12, r2]
 *   @0x2d58c8 add r2, r2, #4
 *   @0x2d58cc bne 0x2d58b8 <_ZN16b2ParticleSystem20DestroyParticleGroupEP15b2ParticleGroup+0x44>
 *   @0x2d58d0 ldr r3, [r6, #0x14]
 *   @0x2d58d4 cmp r3, #0
 *   @0x2d58d8 ldrne r2, [r6, #0x18]
 *   @0x2d58dc strne r2, [r3, #0x18]
 *   @0x2d58e0 ldr r2, [r6, #0x18]
 *   @0x2d58e4 mov r0, r6
 *   @0x2d58e8 cmp r2, #0
 *   @0x2d58ec strne r3, [r2, #0x14]
 *   @0x2d58f0 ldr r3, [r4, #0xa8]
 *   @0x2d58f4 cmp r3, r6
 *   @0x2d58f8 ldr r3, [r4, #0xa4]
 *   @0x2d58fc streq r2, [r4, #0xa8]
 *   @0x2d5900 sub r3, r3, #1
 *   @0x2d5904 str r3, [r4, #0xa4]
 *   @0x2d5908 bl 0x2d45f8 <_ZN15b2ParticleGroupD2Ev>
 *   @0x2d590c ldr r0, [r4, #0xd4]
 *   @0x2d5910 mov r1, r6
 *   @0x2d5914 mov r2, #84
 *   @0x2d5918 pop {r4, r5, r6, lr}
 *   @0x2d591c b 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *
 * ══ §116/159 YYUDID  0x15f574  size 168  42 条（0x15f574..0x15f61c）
 * @func 0x15f574 0x15f61c  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv×4 / _JNIEnv::CallStaticObjectMethod(_jclass*, _jmethodID*, ...) / MemoryManager::Free(void const*) / YYStrDup(char const*)
 * 字段偏移 top8: 0x8c×2 / 0x2a4×1 / 0x2a8×1 / 0x5c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15f574 push {r4, r5, r6, lr}
 *   @0x15f578 mov r4, r0
 *   @0x15f57c bl 0x290274 <getJNIEnv>
 *   @0x15f580 ldr r2, [pc, #0x8c]
 *   @0x15f584 ldr r3, [pc, #0x8c]
 *   @0x15f588 ldr r2, [pc, r2]
 *   @0x15f58c ldr r3, [pc, r3]
 *   @0x15f590 ldr r1, [r2]
 *   @0x15f594 ldr r2, [r3]
 *   @0x15f598 bl 0xf2840 <_ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz>
 *   @0x15f59c mov r5, r0
 *   @0x15f5a0 bl 0x290274 <getJNIEnv>
 *   @0x15f5a4 mov r1, r5
 *   @0x15f5a8 mov r2, #0
 *   @0x15f5ac ldr r3, [r0]
 *   @0x15f5b0 ldr r3, [r3, #0x2a4]
 *   @0x15f5b4 blx r3
 *   @0x15f5b8 mov r6, r0
 *   @0x15f5bc ldr r0, [r4]
 *   @0x15f5c0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x15f5c4 mov r3, #0
 *   @0x15f5c8 mov r0, r6
 *   @0x15f5cc str r3, [r4]
 *   @0x15f5d0 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x15f5d4 cmp r6, #0
 *   @0x15f5d8 cmpne r5, #0
 *   @0x15f5dc str r0, [r4]
 *   @0x15f5e0 popeq {r4, r5, r6, pc}
 *   @0x15f5e4 bl 0x290274 <getJNIEnv>
 *   @0x15f5e8 mov r1, r5
 *   @0x15f5ec mov r2, r6
 *   @0x15f5f0 ldr r3, [r0]
 *   @0x15f5f4 ldr r3, [r3, #0x2a8]
 *   @0x15f5f8 blx r3
 *   @0x15f5fc bl 0x290274 <getJNIEnv>
 *   @0x15f600 mov r1, r5
 *   @0x15f604 ldr r3, [r0]
 *   @0x15f608 ldr r3, [r3, #0x5c]
 *   @0x15f60c blx r3
 *   @0x15f610 pop {r4, r5, r6, pc}
 *   @0x15f614 eoreq lr, r8, r12, lsl r4
 *   @0x15f618 eoreq r0, r9, r12, ror #18
 *
 * ══ §117/159 Create_Object_Lists  0x19e7dc  size 168  42 条（0x19e7dc..0x19e884）
 * @func 0x19e7dc 0x19e884  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CreateList(int, int)×13
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19e7dc mov r0, #0
 *   @0x19e7e0 push {r3, lr}
 *   @0x19e7e4 mov r1, r0
 *   @0x19e7e8 bl 0x19e650 <_Z10CreateListii>
 *   @0x19e7ec mov r0, #1
 *   @0x19e7f0 mov r1, #0
 *   @0x19e7f4 bl 0x19e650 <_Z10CreateListii>
 *   @0x19e7f8 mov r0, #2
 *   @0x19e7fc mov r1, #12
 *   @0x19e800 bl 0x19e650 <_Z10CreateListii>
 *   @0x19e804 mov r0, #3
 *   @0x19e808 mov r1, #16
 *   @0x19e80c bl 0x19e650 <_Z10CreateListii>
 *   @0x19e810 mov r0, #4
 *   @0x19e814 mvn r1, #0
 *   @0x19e818 bl 0x19e650 <_Z10CreateListii>
 *   @0x19e81c mov r0, #5
 *   @0x19e820 mov r1, #128
 *   @0x19e824 bl 0x19e650 <_Z10CreateListii>
 *   @0x19e828 mov r0, #6
 *   @0x19e82c mov r1, #128
 *   @0x19e830 bl 0x19e650 <_Z10CreateListii>
 *   @0x19e834 mov r0, #7
 *   @0x19e838 mov r1, #128
 *   @0x19e83c bl 0x19e650 <_Z10CreateListii>
 *   @0x19e840 mov r0, #8
 *   @0x19e844 mov r1, #0
 *   @0x19e848 bl 0x19e650 <_Z10CreateListii>
 *   @0x19e84c mov r0, #9
 *   @0x19e850 mov r1, #128
 *   @0x19e854 bl 0x19e650 <_Z10CreateListii>
 *   @0x19e858 mov r0, #10
 *   @0x19e85c mov r1, #128
 *   @0x19e860 bl 0x19e650 <_Z10CreateListii>
 *   @0x19e864 mov r0, #13
 *   @0x19e868 mov r1, #128
 *   @0x19e86c bl 0x19e650 <_Z10CreateListii>
 *   @0x19e870 mov r0, #14
 *   @0x19e874 mov r1, #0
 *   @0x19e878 bl 0x19e650 <_Z10CreateListii>
 *   @0x19e87c pop {r3, lr}
 *   @0x19e880 b 0x19e1cc <_Z14CreateColPairsv>
 *
 * ══ §118/159 CPhysicsWorld::Init  0x237bf8  size 168  42 条（0x237bf8..0x237ca0）
 * @func 0x237bf8 0x237ca0  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int)×2 / b2World::SetContactListener(b2ContactListener*) / b2Draw::b2Draw()
 * 字段偏移 top8: 0x10×2 / 0x64×1 / 0xc×1 / 0x48×1 / 0x4c×1 / 0x74×1 / 0x4×1 / 0x54×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x237bf8 push {r3, r4, r5, lr}
 *   @0x237bfc mov r4, r0
 *   @0x237c00 mov r3, #0
 *   @0x237c04 mov r0, #8
 *   @0x237c08 strb r3, [r4, #0x64]
 *   @0x237c0c str r3, [r4, #0xc]
 *   @0x237c10 str r3, [r4, #0x48]
 *   @0x237c14 str r3, [r4, #0x4c]
 *   @0x237c18 bl 0x27c524 <_Znwj>
 *   @0x237c1c ldr r2, [pc, #0x74]
 *   @0x237c20 ldr r2, [pc, r2]
 *   @0x237c24 add r2, r2, #8
 *   @0x237c28 mov r3, r0
 *   @0x237c2c str r4, [r0, #0x4]
 *   @0x237c30 mov r1, r0
 *   @0x237c34 ldr r0, [r4, #0x10]
 *   @0x237c38 str r2, [r3]
 *   @0x237c3c str r3, [r4, #0x54]
 *   @0x237c40 bl 0x2c901c <_ZN7b2World18SetContactListenerEP17b2ContactListener>
 *   @0x237c44 mov r2, r4
 *   @0x237c48 mov r3, #32
 *   @0x237c4c mvn r1, #0
 *   @0x237c50 subs r3, r3, #1
 *   @0x237c54 str r1, [r2, #0x68]
 *   @0x237c58 add r2, r2, #12
 *   @0x237c5c bne 0x237c50 <_ZN13CPhysicsWorld4InitEv+0x58>
 *   @0x237c60 mov r0, #12
 *   @0x237c64 bl 0x27c524 <_Znwj>
 *   @0x237c68 mov r5, r0
 *   @0x237c6c bl 0x2c67b8 <_ZN6b2DrawC2Ev>
 *   @0x237c70 ldr r3, [pc, #0x24]
 *   @0x237c74 mov r1, r5
 *   @0x237c78 str r4, [r5, #0x8]
 *   @0x237c7c ldr r3, [pc, r3]
 *   @0x237c80 ldr r0, [r4, #0x10]
 *   @0x237c84 add r3, r3, #8
 *   @0x237c88 str r3, [r5]
 *   @0x237c8c str r5, [r4, #0x50]
 *   @0x237c90 pop {r3, r4, r5, lr}
 *   @0x237c94 b 0x2c902c <_ZN7b2World12SetDebugDrawEP6b2Draw>
 *   @0x237c98 ldrheq r9, [r11], -r0
 *   @0x237c9c andseq r9, r11, r8, asr r8
 *
 * ══ §119/159 CPhysicsWorld::DispatchContactEvents  0x238208  size 168  42 条（0x238208..0x2382b0）
 * @func 0x238208 0x2382b0  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ContactsStack::Pop()×2 / Perform_Event(CInstance*, CInstance*, int, int)×2
 * 字段偏移 top8: 0x8×3 / 0xc×2 / 0xa4×2 / 0x7c×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x238208 push {r3, r4, r5, r6, r7, lr}
 *   @0x23820c mov r4, r0
 *   @0x238210 bl 0x23c128 <_ZN13ContactsStack3PopEv>
 *   @0x238214 cmp r0, #0
 *   @0x238218 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x23821c mov r6, #0
 *   @0x238220 b 0x238238 <_ZN13CPhysicsWorld21DispatchContactEventsEv+0x30>
 *   @0x238224 str r6, [r4, #0xc]
 *   @0x238228 mov r0, r4
 *   @0x23822c bl 0x23c128 <_ZN13ContactsStack3PopEv>
 *   @0x238230 cmp r0, #0
 *   @0x238234 beq 0x2382ac <_ZN13CPhysicsWorld21DispatchContactEventsEv+0xa4>
 *   @0x238238 ldr r2, [r0, #0x4]
 *   @0x23823c cmp r2, #0
 *   @0x238240 beq 0x238228 <_ZN13CPhysicsWorld21DispatchContactEventsEv+0x20>
 *   @0x238244 ldr r1, [r0, #0x8]
 *   @0x238248 cmp r1, #0
 *   @0x23824c beq 0x238228 <_ZN13CPhysicsWorld21DispatchContactEventsEv+0x20>
 *   @0x238250 ldr r2, [r2, #0x8]
 *   @0x238254 cmp r2, #0
 *   @0x238258 beq 0x238228 <_ZN13CPhysicsWorld21DispatchContactEventsEv+0x20>
 *   @0x23825c ldr r12, [r1, #0x8]
 *   @0x238260 cmp r12, #0
 *   @0x238264 beq 0x238228 <_ZN13CPhysicsWorld21DispatchContactEventsEv+0x20>
 *   @0x238268 ldr r7, [r2, #0xa4]
 *   @0x23826c ldr r5, [r12, #0xa4]
 *   @0x238270 str r0, [r4, #0xc]
 *   @0x238274 cmp r5, #0
 *   @0x238278 cmpne r7, #0
 *   @0x23827c beq 0x238224 <_ZN13CPhysicsWorld21DispatchContactEventsEv+0x1c>
 *   @0x238280 mov r0, r7
 *   @0x238284 mov r1, r5
 *   @0x238288 ldr r3, [r5, #0x7c]
 *   @0x23828c mov r2, #4
 *   @0x238290 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii>
 *   @0x238294 mov r0, r5
 *   @0x238298 mov r1, r7
 *   @0x23829c ldr r3, [r7, #0x7c]
 *   @0x2382a0 mov r2, #4
 *   @0x2382a4 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii>
 *   @0x2382a8 b 0x238224 <_ZN13CPhysicsWorld21DispatchContactEventsEv+0x1c>
 *   @0x2382ac pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §120/159 CPhysicsWorld::UpdateInstantiatedShapesCollisionBits  0x2388a4  size 168  42 条（0x2388a4..0x23894c）
 * @func 0x2388a4 0x23894c  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Fixture::SetFilterData(b2Filter const&)
 * 字段偏移 top8: 0xc×2 / 0x70×2 / 0x10×1 / 0xa4×1 / 0x84×1 / 0x14×1 / 0x74×1 / 0x6c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2388a4 ldr r2, [r0, #0x10]
 *   @0x2388a8 movw r3, #0x9228
 *   @0x2388ac movt r3, #0x1
 *   @0x2388b0 push {r4, r5, r6, r7, r8, lr}
 *   @0x2388b4 mov r7, r0
 *   @0x2388b8 ldr r5, [r2, r3]
 *   @0x2388bc sub sp, sp, #16
 *   @0x2388c0 cmp r5, #0
 *   @0x2388c4 beq 0x238944 <_ZN13CPhysicsWorld37UpdateInstantiatedShapesCollisionBitsEv+0xa0>
 *   @0x2388c8 add r6, sp, #4
 *   @0x2388cc mov r8, #0
 *   @0x2388d0 ldr r3, [r5, #0xa4]
 *   @0x2388d4 cmp r3, #0
 *   @0x2388d8 beq 0x238938 <_ZN13CPhysicsWorld37UpdateInstantiatedShapesCollisionBitsEv+0x94>
 *   @0x2388dc ldr r3, [r3, #0x84]
 *   @0x2388e0 cmp r3, #0
 *   @0x2388e4 beq 0x238938 <_ZN13CPhysicsWorld37UpdateInstantiatedShapesCollisionBitsEv+0x94>
 *   @0x2388e8 ldr r3, [r3, #0x14]
 *   @0x2388ec cmn r3, #1
 *   @0x2388f0 beq 0x238938 <_ZN13CPhysicsWorld37UpdateInstantiatedShapesCollisionBitsEv+0x94>
 *   @0x2388f4 add r3, r3, r3, lsl #1
 *   @0x2388f8 ldr r4, [r5, #0x74]
 *   @0x2388fc strh r8, [sp, #12]
 *   @0x238900 add r3, r7, r3, lsl #2
 *   @0x238904 cmp r4, #0
 *   @0x238908 ldr r2, [r3, #0x6c]
 *   @0x23890c ldr r3, [r3, #0x70]
 *   @0x238910 stmib sp, {r2, r3}
 *   @0x238914 beq 0x238938 <_ZN13CPhysicsWorld37UpdateInstantiatedShapesCollisionBitsEv+0x94>
 *   @0x238918 ldrh r3, [r4, #40]
 *   @0x23891c mov r0, r4
 *   @0x238920 mov r1, r6
 *   @0x238924 strh r3, [sp, #12]
 *   @0x238928 bl 0x2c899c <_ZN9b2Fixture13SetFilterDataERK8b2Filter>
 *   @0x23892c ldr r4, [r4, #0x4]
 *   @0x238930 cmp r4, #0
 *   @0x238934 bne 0x238918 <_ZN13CPhysicsWorld37UpdateInstantiatedShapesCollisionBitsEv+0x74>
 *   @0x238938 ldr r5, [r5, #0x70]
 *   @0x23893c cmp r5, #0
 *   @0x238940 bne 0x2388d0 <_ZN13CPhysicsWorld37UpdateInstantiatedShapesCollisionBitsEv+0x2c>
 *   @0x238944 add sp, sp, #16
 *   @0x238948 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §121/159 Balloc_D2A  0x23d1f8  size 168  42 条（0x23d1f8..0x23d2a0）
 * @func 0x23d1f8 0x23d2a0  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6544 / Balloc_D2A+0x4c
 * 字段偏移 top8: 0x2×2 / 0x88×1 / 0x10×1 / 0xc×1 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23d1f8 cmp r0, #9
 *   @0x23d1fc push {r3, r4, r5, lr}
 *   @0x23d200 mov r4, r0
 *   @0x23d204 bgt 0x23d228 <Balloc_D2A+0x30>
 *   @0x23d208 ldr r3, [pc, #0x88]
 *   @0x23d20c add r3, pc, r3
 *   @0x23d210 ldr r0, [r3, r0, lsl #2]
 *   @0x23d214 cmp r0, #0
 *   @0x23d218 beq 0x23d258 <Balloc_D2A+0x60>
 *   @0x23d21c ldr r2, [r0]
 *   @0x23d220 str r2, [r3, r4, lsl #2]
 *   @0x23d224 b 0x23d248 <Balloc_D2A+0x50>
 *   @0x23d228 mov r5, #1
 *   @0x23d22c lsl r5, r5, r0
 *   @0x23d230 lsl r2, r5, #2
 *   @0x23d234 add r2, r2, #27
 *   @0x23d238 lsr r2, r2, #3
 *   @0x23d23c lsl r0, r2, #3
 *   @0x23d240 bl 0xb6544 <malloc@plt>
 *   @0x23d244 stmib r0, {r4, r5}
 *   @0x23d248 mov r3, #0
 *   @0x23d24c str r3, [r0, #0x10]
 *   @0x23d250 str r3, [r0, #0xc]
 *   @0x23d254 pop {r3, r4, r5, pc}
 *   @0x23d258 ldr r1, [pc, #0x3c]
 *   @0x23d25c mov r5, #1
 *   @0x23d260 lsl r5, r5, r4
 *   @0x23d264 add r3, r3, #40
 *   @0x23d268 add r1, pc, r1
 *   @0x23d26c lsl r2, r5, #2
 *   @0x23d270 ldr r0, [r1]
 *   @0x23d274 add r2, r2, #27
 *   @0x23d278 rsb r3, r3, r0
 *   @0x23d27c lsr r2, r2, #3
 *   @0x23d280 add r3, r2, r3, asr #3
 *   @0x23d284 cmp r3, #288
 *   @0x23d288 addls r2, r0, r2, lsl #3
 *   @0x23d28c strls r2, [r1]
 *   @0x23d290 bls 0x23d244 <Balloc_D2A+0x4c>
 *   @0x23d294 b 0x23d23c <Balloc_D2A+0x44>
 *   @0x23d298 .word 0x00518894
 *   @0x23d29c andseq r10, r11, r0, lsr r2
 *
 * ══ §122/159 b2BlockAllocator::b2BlockAllocator  0x2c64d0  size 168  42 条（0x2c64d0..0x2c6578）
 * @func 0x2c64d0 0x2c6578  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65b0×2 / b2Alloc(int)
 * 字段偏移 top8: 0x8×2 / 0x4×1 / 0x50×1 / 0x40×1 / 0x3c×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c64d0 push {r4, r5, r6, lr}
 *   @0x2c64d4 mov r3, #128
 *   @0x2c64d8 mov r6, r0
 *   @0x2c64dc mov r4, #0
 *   @0x2c64e0 str r3, [r0, #0x8]
 *   @0x2c64e4 str r4, [r0, #0x4]
 *   @0x2c64e8 mov r0, #1024
 *   @0x2c64ec bl 0x2c6a6c <_Z7b2Alloci>
 *   @0x2c64f0 ldr r2, [r6, #0x8]
 *   @0x2c64f4 mov r1, r4
 *   @0x2c64f8 lsl r2, r2, #3
 *   @0x2c64fc str r0, [r6]
 *   @0x2c6500 bl 0xb65b0 <memset@plt>
 *   @0x2c6504 mov r2, #56
 *   @0x2c6508 mov r1, r4
 *   @0x2c650c add r0, r6, #12
 *   @0x2c6510 bl 0xb65b0 <memset@plt>
 *   @0x2c6514 ldr r0, [pc, #0x50]
 *   @0x2c6518 ldr r0, [pc, r0]
 *   @0x2c651c ldrb r2, [r0]
 *   @0x2c6520 cmp r2, r4
 *   @0x2c6524 bne 0x2c6564 <_ZN16b2BlockAllocatorC2Ev+0x94>
 *   @0x2c6528 ldr r4, [pc, #0x40]
 *   @0x2c652c mov r3, #1
 *   @0x2c6530 ldr r12, [pc, #0x3c]
 *   @0x2c6534 movw r5, #0x281
 *   @0x2c6538 ldr r4, [pc, r4]
 *   @0x2c653c ldr r12, [pc, r12]
 *   @0x2c6540 ldr r1, [r4, r2, lsl #2]
 *   @0x2c6544 cmp r1, r3
 *   @0x2c6548 addlt r2, r2, #1
 *   @0x2c654c strb r2, [r12, r3]
 *   @0x2c6550 add r3, r3, #1
 *   @0x2c6554 cmp r3, r5
 *   @0x2c6558 bne 0x2c6540 <_ZN16b2BlockAllocatorC2Ev+0x70>
 *   @0x2c655c mov r3, #1
 *   @0x2c6560 strb r3, [r0]
 *   @0x2c6564 mov r0, r6
 *   @0x2c6568 pop {r4, r5, r6, pc}
 *   @0x2c656c ldrheq r11, [r2], -r12
 *   @0x2c6570 andseq r11, r2, r0, lsr #11
 *   @0x2c6574 andseq r11, r2, r0, lsr #11
 *
 * ══ §123/159 b2Island::b2Island  0x2e1130  size 168  42 条（0x2e1130..0x2e11d8）
 * @func 0x2e1130 0x2e11d8  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2StackAllocator::Allocate(int)×5
 * 字段偏移 top8: 0x28×3 / 0x18×2 / 0x1c×2 / 0x2c×1 / 0x30×1 / 0x24×1 / 0x20×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e1130 push {r3, r4, r5, r6, r7, lr}
 *   @0x2e1134 mov r4, r0
 *   @0x2e1138 ldr lr, [sp, #0x18]
 *   @0x2e113c mov r12, #0
 *   @0x2e1140 ldr r7, [sp, #0x1c]
 *   @0x2e1144 mov r0, r1
 *   @0x2e1148 str r2, [r4, #0x2c]
 *   @0x2e114c lsl r1, r1, #2
 *   @0x2e1150 str r3, [r4, #0x30]
 *   @0x2e1154 mov r5, r2
 *   @0x2e1158 str r12, [r4, #0x1c]
 *   @0x2e115c mov r6, r3
 *   @0x2e1160 str r12, [r4, #0x24]
 *   @0x2e1164 str r12, [r4, #0x20]
 *   @0x2e1168 str lr, [r4]
 *   @0x2e116c str r0, [r4, #0x28]
 *   @0x2e1170 mov r0, lr
 *   @0x2e1174 str r7, [r4, #0x4]
 *   @0x2e1178 bl 0x2e0f44 <_ZN16b2StackAllocator8AllocateEi>
 *   @0x2e117c lsl r1, r5, #2
 *   @0x2e1180 str r0, [r4, #0x8]
 *   @0x2e1184 ldr r0, [r4]
 *   @0x2e1188 bl 0x2e0f44 <_ZN16b2StackAllocator8AllocateEi>
 *   @0x2e118c lsl r1, r6, #2
 *   @0x2e1190 str r0, [r4, #0xc]
 *   @0x2e1194 ldr r0, [r4]
 *   @0x2e1198 bl 0x2e0f44 <_ZN16b2StackAllocator8AllocateEi>
 *   @0x2e119c ldr r1, [r4, #0x28]
 *   @0x2e11a0 add r1, r1, r1, lsl #1
 *   @0x2e11a4 lsl r1, r1, #2
 *   @0x2e11a8 str r0, [r4, #0x10]
 *   @0x2e11ac ldr r0, [r4]
 *   @0x2e11b0 bl 0x2e0f44 <_ZN16b2StackAllocator8AllocateEi>
 *   @0x2e11b4 ldr r1, [r4, #0x28]
 *   @0x2e11b8 add r1, r1, r1, lsl #1
 *   @0x2e11bc lsl r1, r1, #2
 *   @0x2e11c0 str r0, [r4, #0x18]
 *   @0x2e11c4 ldr r0, [r4]
 *   @0x2e11c8 bl 0x2e0f44 <_ZN16b2StackAllocator8AllocateEi>
 *   @0x2e11cc str r0, [r4, #0x14]
 *   @0x2e11d0 mov r0, r4
 *   @0x2e11d4 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §124/159 __udivsi3  0x318c48  size 168  42 条（0x318c48..0x318cf0）
 * @func 0x318c48 0x318cf0  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __udivsi3+0x9c / __udivsi3+0x80
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x318c48 subs r2, r1, #1
 *   @0x318c4c bxeq lr
 *   @0x318c50 blo 0x318ce4 <__udivsi3+0x9c>
 *   @0x318c54 cmp r0, r1
 *   @0x318c58 bls 0x318cc8 <__udivsi3+0x80>
 *   @0x318c5c tst r1, r2
 *   @0x318c60 beq 0x318cd4 <__udivsi3+0x8c>
 *   @0x318c64 clz r3, r1
 *   @0x318c68 clz r2, r0
 *   @0x318c6c sub r2, r3, r2
 *   @0x318c70 mov r3, #1
 *   @0x318c74 lsl r1, r1, r2
 *   @0x318c78 lsl r3, r3, r2
 *   @0x318c7c mov r2, #0
 *   @0x318c80 cmp r0, r1
 *   @0x318c84 subhs r0, r0, r1
 *   @0x318c88 orrhs r2, r2, r3
 *   @0x318c8c cmp r0, r1, lsr #1
 *   @0x318c90 subhs r0, r0, r1, lsr #1
 *   @0x318c94 orrhs r2, r2, r3, lsr #1
 *   @0x318c98 cmp r0, r1, lsr #2
 *   @0x318c9c subhs r0, r0, r1, lsr #2
 *   @0x318ca0 orrhs r2, r2, r3, lsr #2
 *   @0x318ca4 cmp r0, r1, lsr #3
 *   @0x318ca8 subhs r0, r0, r1, lsr #3
 *   @0x318cac orrhs r2, r2, r3, lsr #3
 *   @0x318cb0 cmp r0, #0
 *   @0x318cb4 lsrsne r3, r3, #4
 *   @0x318cb8 lsrne r1, r1, #4
 *   @0x318cbc bne 0x318c80 <__udivsi3+0x38>
 *   @0x318cc0 mov r0, r2
 *   @0x318cc4 bx lr
 *   @0x318cc8 moveq r0, #1
 *   @0x318ccc movne r0, #0
 *   @0x318cd0 bx lr
 *   @0x318cd4 clz r2, r1
 *   @0x318cd8 rsb r2, r2, #31
 *   @0x318cdc lsr r0, r0, r2
 *   @0x318ce0 bx lr
 *   @0x318ce4 cmp r0, #0
 *   @0x318ce8 mvnne r0, #0
 *   @0x318cec b 0x319458 <__aeabi_ldiv0>
 *
 * ══ §125/159 IBuffer::IBuffer  0xcc994  size 164  41 条（0xcc994..0xcca38）
 * @func 0xcc994 0xcca38  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IBuffer::GetPOW2Alignment(int) / MemoryManager::Alloc(unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x94×1 / 0x70×1 / 0x8×1 / 0x18×1 / 0x10×1 / 0x14×1 / 0x20×1 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcc994 ldr r12, [pc, #0x94]
 *   @0xcc998 push {r3, r4, r5, r6, r7, lr}
 *   @0xcc99c ldr r12, [pc, r12]
 *   @0xcc9a0 mov r4, r0
 *   @0xcc9a4 add r12, r12, #8
 *   @0xcc9a8 ubfx r0, r3, #0x0, #0x9
 *   @0xcc9ac str r12, [r4]
 *   @0xcc9b0 mov r6, r1
 *   @0xcc9b4 mov r7, r2
 *   @0xcc9b8 bl 0xcc958 <_ZN7IBuffer16GetPOW2AlignmentEi>
 *   @0xcc9bc ldr r1, [pc, #0x70]
 *   @0xcc9c0 mov r2, #114
 *   @0xcc9c4 mov r3, #1
 *   @0xcc9c8 add r1, pc, r1
 *   @0xcc9cc mov r5, r0
 *   @0xcc9d0 add r0, r6, r0
 *   @0xcc9d4 str r0, [r4, #0x8]
 *   @0xcc9d8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xcc9dc rsb r3, r5, #0
 *   @0xcc9e0 mov r2, #1
 *   @0xcc9e4 str r7, [r4, #0x18]
 *   @0xcc9e8 str r6, [r4, #0x10]
 *   @0xcc9ec str r5, [r4, #0x14]
 *   @0xcc9f0 str r6, [r4, #0x20]
 *   @0xcc9f4 strb r2, [r4, #0x3c]
 *   @0xcc9f8 add r1, r0, r5
 *   @0xcc9fc str r0, [r4, #0x4]
 *   @0xcca00 sub r1, r1, #1
 *   @0xcca04 mov r0, r4
 *   @0xcca08 and r1, r1, r3
 *   @0xcca0c mov r3, #0
 *   @0xcca10 str r1, [r4, #0xc]
 *   @0xcca14 str r3, [r4, #0x1c]
 *   @0xcca18 str r3, [r4, #0x24]
 *   @0xcca1c str r3, [r4, #0x38]
 *   @0xcca20 str r3, [r4, #0x2c]
 *   @0xcca24 str r3, [r4, #0x30]
 *   @0xcca28 str r3, [r4, #0x28]
 *   @0xcca2c pop {r3, r4, r5, r6, r7, pc}
 *   @0xcca30 eorseq r1, r2, r0, ror r1
 *   @0xcca34 eoreq r5, r6, r8, lsr #15
 *
 * ══ §126/159 F_DsQueueEnqueue  0xfc048  size 164  41 条（0xfc048..0xfc0ec）
 * @func 0xfc048 0xfc0ec  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_DsQueueEnqueue(RValue&, CInstance*, CInstance*, int, RValue*)+0x84 / CDS_Queue::Enqueue(RValue*)
 * 字段偏移 top8: 0x4×2 / 0x18×1 / 0x70×1 / 0x60×1 / 0x2×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfc048 push {r4, r5, r6, r7, r8, lr}
 *   @0xfc04c mov r1, #0
 *   @0xfc050 ldr r5, [sp, #0x18]
 *   @0xfc054 mov r7, r3
 *   @0xfc058 mov r0, r5
 *   @0xfc05c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfc060 cmp r0, #0
 *   @0xfc064 blt 0xfc0cc <_Z16F_DsQueueEnqueueR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0xfc068 ldr r3, [pc, #0x70]
 *   @0xfc06c ldr r3, [pc, r3]
 *   @0xfc070 ldr r3, [r3]
 *   @0xfc074 cmp r0, r3
 *   @0xfc078 bge 0xfc0cc <_Z16F_DsQueueEnqueueR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0xfc07c ldr r6, [pc, #0x60]
 *   @0xfc080 lsl r8, r0, #2
 *   @0xfc084 ldr r6, [pc, r6]
 *   @0xfc088 ldr r3, [r6, #0x4]
 *   @0xfc08c ldr r0, [r3, r0, lsl #2]
 *   @0xfc090 cmp r0, #0
 *   @0xfc094 beq 0xfc0cc <_Z16F_DsQueueEnqueueR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0xfc098 cmp r7, #1
 *   @0xfc09c pople {r4, r5, r6, r7, r8, pc}
 *   @0xfc0a0 add r5, r5, #16
 *   @0xfc0a4 mov r4, #1
 *   @0xfc0a8 mov r1, r5
 *   @0xfc0ac add r4, r4, #1
 *   @0xfc0b0 bl 0x20588c <_ZN9CDS_Queue7EnqueueEP6RValue>
 *   @0xfc0b4 cmp r4, r7
 *   @0xfc0b8 add r5, r5, #16
 *   @0xfc0bc popeq {r4, r5, r6, r7, r8, pc}
 *   @0xfc0c0 ldr r2, [r6, #0x4]
 *   @0xfc0c4 ldr r0, [r2, r8]
 *   @0xfc0c8 b 0xfc0a8 <_Z16F_DsQueueEnqueueR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0xfc0cc ldr r0, [pc, #0x14]
 *   @0xfc0d0 mov r1, #0
 *   @0xfc0d4 pop {r4, r5, r6, r7, r8, lr}
 *   @0xfc0d8 add r0, pc, r0
 *   @0xfc0dc b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfc0e0 eoreq r1, pc, r0, lsl #28
 *   @0xfc0e4 eoreq r1, pc, r12, ror #27
 *   @0xfc0e8 eoreq r11, r3, r4, lsr #22
 *
 * ══ §127/159 IAP_AcquireM  0x16189c  size 164  41 条（0x16189c..0x161940）
 * @func 0x16189c 0x161940  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv×5 / _JNIEnv::CallStaticVoidMethod(_jclass*, _jmethodID*, ...)
 * 字段偏移 top8: 0x29c×2 / 0x5c×2 / 0x4c×1 / 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16189c push {r4, r5, r6, lr}
 *   @0x1618a0 sub sp, sp, #8
 *   @0x1618a4 mov r6, r2
 *   @0x1618a8 mov r4, r1
 *   @0x1618ac mov r5, r0
 *   @0x1618b0 bl 0x290274 <getJNIEnv>
 *   @0x1618b4 mov r1, r5
 *   @0x1618b8 ldr r3, [r0]
 *   @0x1618bc ldr r3, [r3, #0x29c]
 *   @0x1618c0 blx r3
 *   @0x1618c4 mov r5, r0
 *   @0x1618c8 bl 0x290274 <getJNIEnv>
 *   @0x1618cc mov r1, r4
 *   @0x1618d0 ldr r3, [r0]
 *   @0x1618d4 ldr r3, [r3, #0x29c]
 *   @0x1618d8 blx r3
 *   @0x1618dc mov r4, r0
 *   @0x1618e0 bl 0x290274 <getJNIEnv>
 *   @0x1618e4 ldr lr, [pc, #0x4c]
 *   @0x1618e8 mov r3, r5
 *   @0x1618ec ldr r12, [pc, #0x48]
 *   @0x1618f0 ldr lr, [pc, lr]
 *   @0x1618f4 ldr r12, [pc, r12]
 *   @0x1618f8 ldr r1, [lr]
 *   @0x1618fc ldr r2, [r12]
 *   @0x161900 stm sp, {r4, r6}
 *   @0x161904 bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x161908 bl 0x290274 <getJNIEnv>
 *   @0x16190c mov r1, r5
 *   @0x161910 ldr r3, [r0]
 *   @0x161914 ldr r3, [r3, #0x5c]
 *   @0x161918 blx r3
 *   @0x16191c bl 0x290274 <getJNIEnv>
 *   @0x161920 mov r1, r4
 *   @0x161924 ldr r3, [r0]
 *   @0x161928 ldr r3, [r3, #0x5c]
 *   @0x16192c blx r3
 *   @0x161930 add sp, sp, #8
 *   @0x161934 pop {r4, r5, r6, pc}
 *   @0x161938 strhteq r12, [r8], -r4
 *   @0x16193c eoreq lr, r8, r4, ror r6
 *
 * ══ §128/159 GR_3D_Set_Depth  0x1631dc  size 164  34 条（0x1631dc..0x163280）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x1631f8 0x163280  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1631e4→0x5428e8, 0x1631fc→0x4859b0, 0x163220→0x4859ac, 0x163254→0x4859ac
 * 调用序列: 无
 * 字段偏移 top8: 0x8c×1 / 0x88×1 / 0x74×1 / 0x54×1 / 0x20×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1631f8 bne 0x163210 <_Z15GR_3D_Set_Depthf+0x34>
 *   @0x1631fc ldr r2, [pc, #0x74]
 *   @0x163200 ldr r2, [r3, r2]
 *   @0x163204 ldrb r2, [r2]
 *   @0x163208 cmp r2, #0
 *   @0x16320c beq 0x163254 <_Z15GR_3D_Set_Depthf+0x78>
 *   @0x163210 vldr s14, [pc, #80]
 *   @0x163214 vcmpe.f32 s15, s14
 *   @0x163218 vmrs APSR_nzcv, fpscr
 *   @0x16321c bpl 0x163230 <_Z15GR_3D_Set_Depthf+0x54>
 *   @0x163220 ldr r2, [pc, #0x54]
 *   @0x163224 ldr r3, [r3, r2]
 *   @0x163228 vstr s14, [r3]
 *   @0x16322c bx lr
 *   @0x163230 vldr s13, [pc, #52]
 *   @0x163234 vcmpe.f32 s15, s13
 *   @0x163238 vmrs APSR_nzcv, fpscr
 *   @0x16323c vmovgt.f32 s14, s13
 *   @0x163240 bgt 0x163220 <_Z15GR_3D_Set_Depthf+0x44>
 *   @0x163244 vcmpe.f32 s15, s14
 *   @0x163248 vmrs APSR_nzcv, fpscr
 *   @0x16324c vmovpl.f32 s14, s15
 *   @0x163250 b 0x163220 <_Z15GR_3D_Set_Depthf+0x44>
 *   @0x163254 ldr r2, [pc, #0x20]
 *   @0x163258 mov r1, #0
 *   @0x16325c ldr r3, [r3, r2]
 *   @0x163260 str r1, [r3]
 *   @0x163264 bx lr
 *   @0x163268 ldrbtgt r0, [r10], -r0
 *   @0x16326c ldrbtmi r0, [r10], -r0
 *   @0x163270 eoreq lr, r8, r8, ror #20
 *   @0x163274 .word 0xffffbcd4
 *   @0x163278 .word 0xffffc0b4
 *   @0x16327c .word 0xffffbcd0
 *
 * ══ §129/159 GR_D3D_Set_View_Port  0x168cd8  size 164  41 条（0x168cd8..0x168d7c）
 * @func 0x168cd8 0x168d7c  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x168ce8→0x4a22b1, 0x168d18→0x3f23b0, 0x168d1c→0x3f23ac, 0x168d24→0x3f23a8, 0x168d34→0x3f23a4
 * 调用序列: Graphics::Flush()
 * 字段偏移 top8: 0x4c×2 / 0x7c×1 / 0x78×1 / 0x48×1 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x168cd8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x168cdc mov r8, r0
 *   @0x168ce0 ldr r4, [pc, #0x7c]
 *   @0x168ce4 sub sp, sp, #4
 *   @0x168ce8 ldr r12, [pc, #0x78]
 *   @0x168cec mov r7, r1
 *   @0x168cf0 add r4, pc, r4
 *   @0x168cf4 mov r6, r2
 *   @0x168cf8 mov r5, r3
 *   @0x168cfc ldr r12, [r4, r12]
 *   @0x168d00 ldrb r12, [r12]
 *   @0x168d04 cmp r12, #0
 *   @0x168d08 bne 0x168d14 <_Z20GR_D3D_Set_View_Portiiii+0x3c>
 *   @0x168d0c add sp, sp, #4
 *   @0x168d10 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x168d14 bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x168d18 ldr r3, [pc, #0x4c]
 *   @0x168d1c ldr r10, [pc, #0x4c]
 *   @0x168d20 mov r0, r8
 *   @0x168d24 ldr r9, [pc, #0x48]
 *   @0x168d28 mov r1, r7
 *   @0x168d2c ldr r11, [r4, r3]
 *   @0x168d30 mov r2, r6
 *   @0x168d34 ldr r12, [pc, #0x3c]
 *   @0x168d38 mov r3, r5
 *   @0x168d3c str r8, [r11]
 *   @0x168d40 ldr r8, [r4, r10]
 *   @0x168d44 str r7, [r8]
 *   @0x168d48 ldr r7, [r4, r9]
 *   @0x168d4c str r6, [r7]
 *   @0x168d50 ldr r12, [r4, r12]
 *   @0x168d54 str r5, [r12]
 *   @0x168d58 add sp, sp, #4
 *   @0x168d5c pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x168d60 b 0x17dfb0 <_ZN8Graphics11SetViewPortEiiii>
 *   @0x168d64 eoreq r8, r8, r0, ror #30
 *   @0x168d68 .word 0xffffe4d0
 *   @0x168d6c .word 0xffffe4ec
 *   @0x168d70 .word 0xffffe4f0
 *   @0x168d74 .word 0xffffe4f4
 *   @0x168d78 .word 0xffffe4f8
 *
 * ══ §130/159 CGCGeneration::AddDynamicRoot  0x19135c  size 164  41 条（0x19135c..0x191400）
 * @func 0x19135c 0x191400  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x8×3 / 0x4×3 / 0x38×2 / 0x10×1 / 0xc×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19135c push {r4, r5, lr}
 *   @0x191360 subs r5, r1, #0
 *   @0x191364 sub sp, sp, #12
 *   @0x191368 mov r4, r0
 *   @0x19136c beq 0x191388 <_ZN13CGCGeneration14AddDynamicRootEP12YYObjectBaseb+0x2c>
 *   @0x191370 cmp r2, #0
 *   @0x191374 bne 0x191390 <_ZN13CGCGeneration14AddDynamicRootEP12YYObjectBaseb+0x34>
 *   @0x191378 ldr r2, [r5, #0x38]
 *   @0x19137c ldr r3, [r0, #0x10]
 *   @0x191380 cmp r2, r3
 *   @0x191384 beq 0x191390 <_ZN13CGCGeneration14AddDynamicRootEP12YYObjectBaseb+0x34>
 *   @0x191388 add sp, sp, #12
 *   @0x19138c pop {r4, r5, pc}
 *   @0x191390 ldr r3, [r4, #0x8]
 *   @0x191394 ldr r1, [r4, #0xc]
 *   @0x191398 cmp r3, r1
 *   @0x19139c bge 0x1913b8 <_ZN13CGCGeneration14AddDynamicRootEP12YYObjectBaseb+0x5c>
 *   @0x1913a0 ldr r1, [r4, #0x4]
 *   @0x1913a4 add r2, r3, #1
 *   @0x1913a8 str r2, [r4, #0x8]
 *   @0x1913ac str r5, [r1, r3, lsl #2]
 *   @0x1913b0 add sp, sp, #12
 *   @0x1913b4 pop {r4, r5, pc}
 *   @0x1913b8 lsls r3, r1, #1
 *   @0x1913bc ldr r2, [pc, #0x38]
 *   @0x1913c0 strne r3, [r4, #0xc]
 *   @0x1913c4 lslne r1, r1, #3
 *   @0x1913c8 moveq r3, #1
 *   @0x1913cc moveq r1, #4
 *   @0x1913d0 streq r3, [r4, #0xc]
 *   @0x1913d4 add r2, pc, r2
 *   @0x1913d8 ldr r0, [r4, #0x4]
 *   @0x1913dc mov r3, #0
 *   @0x1913e0 str r3, [sp]
 *   @0x1913e4 mov r3, #74
 *   @0x1913e8 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x1913ec ldr r3, [r4, #0x8]
 *   @0x1913f0 mov r1, r0
 *   @0x1913f4 str r0, [r4, #0x4]
 *   @0x1913f8 b 0x1913a4 <_ZN13CGCGeneration14AddDynamicRootEP12YYObjectBaseb+0x48>
 *   @0x1913fc andseq pc, r9, r12, asr r12
 *
 * ══ §131/159 ParticleSystem_Update  0x1a4f18  size 164  41 条（0x1a4f18..0x1a4fbc）
 * @func 0x1a4f18 0x1a4fd0  size 184  46 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleSystem_Exists(int) / HandleLife(int) / HandleMotion(int) / HandleShape(int) / ParticleSystem_Update(int)+0x9c / ParticleSystem_Emitter_Burst(int, int, int, int)
 * 字段偏移 top8: 0x4×2 / 0x2×2 / 0x14×2 / 0x6c×1 / 0x10×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a4f18 push {r4, r5, r6, lr}
 *   @0x1a4f1c mov r6, r0
 *   @0x1a4f20 bl 0x1a3770 <_Z21ParticleSystem_Existsi>
 *   @0x1a4f24 cmp r0, #0
 *   @0x1a4f28 popeq {r4, r5, r6, pc}
 *   @0x1a4f2c mov r0, r6
 *   @0x1a4f30 bl 0x1a4938 <_Z10HandleLifei>
 *   @0x1a4f34 mov r0, r6
 *   @0x1a4f38 bl 0x1a4ba4 <_Z12HandleMotioni>
 *   @0x1a4f3c mov r0, r6
 *   @0x1a4f40 bl 0x1a4df4 <_Z11HandleShapei>
 *   @0x1a4f44 ldr r3, [pc, #0x6c]
 *   @0x1a4f48 ldr r3, [pc, r3]
 *   @0x1a4f4c ldr r3, [r3, #0x4]
 *   @0x1a4f50 ldr r5, [r3, r6, lsl #2]
 *   @0x1a4f54 ldr r1, [r5, #0x14]
 *   @0x1a4f58 cmp r1, #0
 *   @0x1a4f5c pople {r4, r5, r6, pc}
 *   @0x1a4f60 mov r4, #0
 *   @0x1a4f64 b 0x1a4f74 <_Z21ParticleSystem_Updatei+0x5c>
 *   @0x1a4f68 add r4, r4, #1
 *   @0x1a4f6c cmp r1, r4
 *   @0x1a4f70 ble 0x1a4fb4 <_Z21ParticleSystem_Updatei+0x9c>
 *   @0x1a4f74 ldr r3, [r5, #0x10]
 *   @0x1a4f78 ldr r2, [r3, r4, lsl #2]
 *   @0x1a4f7c ldrb r3, [r2]
 *   @0x1a4f80 cmp r3, #0
 *   @0x1a4f84 beq 0x1a4f68 <_Z21ParticleSystem_Updatei+0x50>
 *   @0x1a4f88 ldr r3, [r2, #0x4]
 *   @0x1a4f8c cmp r3, #0
 *   @0x1a4f90 beq 0x1a4f68 <_Z21ParticleSystem_Updatei+0x50>
 *   @0x1a4f94 mov r1, r4
 *   @0x1a4f98 ldr r2, [r2, #0x20]
 *   @0x1a4f9c mov r0, r6
 *   @0x1a4fa0 add r4, r4, #1
 *   @0x1a4fa4 bl 0x1a3cf0 <_Z28ParticleSystem_Emitter_Burstiiii>
 *   @0x1a4fa8 ldr r1, [r5, #0x14]
 *   @0x1a4fac cmp r1, r4
 *   @0x1a4fb0 bgt 0x1a4f74 <_Z21ParticleSystem_Updatei+0x5c>
 *   @0x1a4fb4 pop {r4, r5, r6, pc}
 *   @0x1a4fb8 eoreq r11, r4, r0, ror r8
 *
 * ══ §132/159 _vorbis_block_ripcord  0x227164  size 164  41 条（0x227164..0x227208）
 * @func 0x227164 0x227208  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb655c×2 / 0xb6c28
 * 字段偏移 top8: 0x1×7 / 0x50×3 / 0x4c×3 / 0x54×2 / 0x44×2 / 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x227164 push {r3, r4, r5, r6, r7, lr}
 *   @0x227168 mov r7, r0
 *   @0x22716c ldr r5, [r0, #0x54]
 *   @0x227170 cmp r5, #0
 *   @0x227174 movne r4, #0
 *   @0x227178 beq 0x2271c0 <_vorbis_block_ripcord+0x5c>
 *   @0x22717c ldm r5, {r0, r6}
 *   @0x227180 bl 0xb655c <free@plt>
 *   @0x227184 mov r3, r5
 *   @0x227188 strb r4, [r3], #1
 *   @0x22718c add r3, r3, #1
 *   @0x227190 strb r4, [r5, #0x1]
 *   @0x227194 mov r0, r5
 *   @0x227198 strb r4, [r3], #1
 *   @0x22719c mov r5, r6
 *   @0x2271a0 strb r4, [r3], #1
 *   @0x2271a4 strb r4, [r3], #1
 *   @0x2271a8 strb r4, [r3], #1
 *   @0x2271ac strb r4, [r3], #1
 *   @0x2271b0 strb r4, [r3]
 *   @0x2271b4 bl 0xb655c <free@plt>
 *   @0x2271b8 cmp r6, #0
 *   @0x2271bc bne 0x22717c <_vorbis_block_ripcord+0x18>
 *   @0x2271c0 ldr r3, [r7, #0x50]
 *   @0x2271c4 cmp r3, #0
 *   @0x2271c8 beq 0x2271f8 <_vorbis_block_ripcord+0x94>
 *   @0x2271cc ldr r1, [r7, #0x4c]
 *   @0x2271d0 ldr r0, [r7, #0x44]
 *   @0x2271d4 add r1, r3, r1
 *   @0x2271d8 bl 0xb6c28 <realloc@plt>
 *   @0x2271dc ldr r2, [r7, #0x4c]
 *   @0x2271e0 ldr r3, [r7, #0x50]
 *   @0x2271e4 mov r1, #0
 *   @0x2271e8 str r1, [r7, #0x50]
 *   @0x2271ec add r3, r2, r3
 *   @0x2271f0 str r3, [r7, #0x4c]
 *   @0x2271f4 str r0, [r7, #0x44]
 *   @0x2271f8 mov r3, #0
 *   @0x2271fc str r3, [r7, #0x48]
 *   @0x227200 str r3, [r7, #0x54]
 *   @0x227204 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §133/159 ov_open_callbacks  0x231c48  size 164  41 条（0x231c48..0x231cec）
 * @func 0x231c48 0x231cec  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_230fbc / anon_231ac4 / ov_clear
 * 字段偏移 top8: 0x58×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x231c48 push {r4, r5, r6, lr}
 *   @0x231c4c sub sp, sp, #16
 *   @0x231c50 add r6, sp, #28
 *   @0x231c54 mov r5, r0
 *   @0x231c58 mov lr, r2
 *   @0x231c5c mov r12, r3
 *   @0x231c60 mov r4, r1
 *   @0x231c64 ldmib r6, {r0, r1, r2, r3}
 *   @0x231c68 stm sp, {r0, r1, r2, r3}
 *   @0x231c6c mov r0, r5
 *   @0x231c70 mov r2, lr
 *   @0x231c74 mov r3, r12
 *   @0x231c78 mov r1, r4
 *   @0x231c7c bl 0x230fbc <ov_clear+0xf8>
 *   @0x231c80 subs r5, r0, #0
 *   @0x231c84 movne r0, r5
 *   @0x231c88 beq 0x231c94 <ov_open_callbacks+0x4c>
 *   @0x231c8c add sp, sp, #16
 *   @0x231c90 pop {r4, r5, r6, pc}
 *   @0x231c94 ldr r3, [r4, #0x58]
 *   @0x231c98 cmp r3, #1
 *   @0x231c9c bne 0x231ce4 <ov_open_callbacks+0x9c>
 *   @0x231ca0 ldr r0, [r4, #0x4]
 *   @0x231ca4 mov r3, #2
 *   @0x231ca8 str r3, [r4, #0x58]
 *   @0x231cac cmp r0, #0
 *   @0x231cb0 moveq r3, #3
 *   @0x231cb4 streq r3, [r4, #0x58]
 *   @0x231cb8 beq 0x231c8c <ov_open_callbacks+0x44>
 *   @0x231cbc mov r0, r4
 *   @0x231cc0 bl 0x231ac4 <ov_raw_seek+0x4ac>
 *   @0x231cc4 subs r6, r0, #0
 *   @0x231cc8 beq 0x231cd8 <ov_open_callbacks+0x90>
 *   @0x231ccc str r5, [r4]
 *   @0x231cd0 mov r0, r4
 *   @0x231cd4 bl 0x230ec4 <ov_clear>
 *   @0x231cd8 mov r0, r6
 *   @0x231cdc add sp, sp, #16
 *   @0x231ce0 pop {r4, r5, r6, pc}
 *   @0x231ce4 mvn r0, #130
 *   @0x231ce8 b 0x231c8c <ov_open_callbacks+0x44>
 *
 * ══ §134/159 json_object_get_double  0x27ebf0  size 164  39 条（0x27ebf0..0x27ec94）
 * @func 0x27ebf0 0x27ec94  size 164  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb68f8
 * 字段偏移 top8: 0x4×3 / 0x-4×1 / 0x38×1 / 0x18×1
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27ebf0 cmp r0, #0
 *   @0x27ebf4 str lr, [sp, #-0x4]!
 *   @0x27ebf8 sub sp, sp, #12
 *   @0x27ebfc beq 0x27ec40 <json_object_get_double+0x50>
 *   @0x27ec00 ldr r3, [r0]
 *   @0x27ec04 sub r3, r3, #1
 *   @0x27ec08 cmp r3, #5
 *   @0x27ec0c addls pc, pc, r3, lsl #2
 *   @0x27ec10 b 0x27ec40 <json_object_get_double+0x50>
 *   @0x27ec14 b 0x27ec2c <json_object_get_double+0x3c>
 *   @0x27ec18 b 0x27ec74 <json_object_get_double+0x84>
 *   @0x27ec1c b 0x27ec2c <json_object_get_double+0x3c>
 *   @0x27ec20 b 0x27ec40 <json_object_get_double+0x50>
 *   @0x27ec24 b 0x27ec40 <json_object_get_double+0x50>
 *   @0x27ec28 b 0x27ec50 <json_object_get_double+0x60>
 *   @0x27ec2c vldr s14, [r0, #24]
 *   @0x27ec30 vcvt.f64.s32 d7, s14
 *   @0x27ec34 vmov r0, r1, d7
 *   @0x27ec38 add sp, sp, #12
 *   @0x27ec3c ldr pc, [sp], #4
 *   @0x27ec40 vldr d7, [pc, #64]
 *   @0x27ec44 vmov r0, r1, d7
 *   @0x27ec48 add sp, sp, #12
 *   @0x27ec4c ldr pc, [sp], #4
 *   @0x27ec50 ldr r1, [pc, #0x38]
 *   @0x27ec54 mov r2, sp
 *   @0x27ec58 ldr r0, [r0, #0x18]
 *   @0x27ec5c add r1, pc, r1
 *   @0x27ec60 bl 0xb68f8 <sscanf@plt>
 *   @0x27ec64 cmp r0, #1
 *   @0x27ec68 bne 0x27ec40 <json_object_get_double+0x50>
 *   @0x27ec6c vldr d7, [sp]
 *   @0x27ec70 b 0x27ec34 <json_object_get_double+0x44>
 *   @0x27ec74 vldr d7, [r0, #24]
 *   @0x27ec78 vmov r0, r1, d7
 *   @0x27ec7c add sp, sp, #12
 *   @0x27ec80 ldr pc, [sp], #4
 *   @0x27ec84 nop
 *   @0x27ec90 strheq r1, [r12], -r8
 *
 * ══ §135/159 DebuggerSetConnected  0x29cad0  size 164  41 条（0x29cad0..0x29cb74）
 * @func 0x29cad0 0x29cb74  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x29caf0→0x3eb708, 0x29cb14→0x3f5129, 0x29cb18→0x757e80
 * 调用序列: 无
 * 字段偏移 top8: 0xc×2 / 0x4c×2 / 0x78×1 / 0x74×1 / 0x210×1 / 0x68×1 / 0x60×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29cad0 push {r3, r4, r5, lr}
 *   @0x29cad4 cmp r0, #0
 *   @0x29cad8 ldr r3, [pc, #0x78]
 *   @0x29cadc mov r5, r0
 *   @0x29cae0 ldr r4, [pc, #0x74]
 *   @0x29cae4 add r3, pc, r3
 *   @0x29cae8 add r4, pc, r4
 *   @0x29caec strb r0, [r3, #0x210]
 *   @0x29caf0 ldr r3, [pc, #0x68]
 *   @0x29caf4 bne 0x29cb38 <_Z20DebuggerSetConnectedb+0x68>
 *   @0x29caf8 ldr r3, [r4, r3]
 *   @0x29cafc ldr r1, [pc, #0x60]
 *   @0x29cb00 ldr r0, [r3]
 *   @0x29cb04 add r1, pc, r1
 *   @0x29cb08 ldr r3, [r0]
 *   @0x29cb0c ldr r3, [r3, #0xc]
 *   @0x29cb10 blx r3
 *   @0x29cb14 ldr r2, [pc, #0x4c]
 *   @0x29cb18 ldr r3, [pc, #0x4c]
 *   @0x29cb1c mov r0, #1
 *   @0x29cb20 mov r1, r5
 *   @0x29cb24 ldr r2, [r4, r2]
 *   @0x29cb28 strb r0, [r2]
 *   @0x29cb2c ldr r0, [r4, r3]
 *   @0x29cb30 pop {r3, r4, r5, lr}
 *   @0x29cb34 b 0x2a04d8 <_ZN9CProfiler6EnableEb>
 *   @0x29cb38 ldr r3, [r4, r3]
 *   @0x29cb3c ldr r1, [pc, #0x2c]
 *   @0x29cb40 ldr r0, [r3]
 *   @0x29cb44 add r1, pc, r1
 *   @0x29cb48 ldr r3, [r0]
 *   @0x29cb4c ldr r3, [r3, #0xc]
 *   @0x29cb50 blx r3
 *   @0x29cb54 pop {r3, r4, r5, pc}
 *   @0x29cb58 subeq r11, r11, r4, lsr #2
 *   @0x29cb5c andseq r5, r5, r8, ror #2
 *   @0x29cb60 .word 0xffffbcf0
 *   @0x29cb64 andeq r12, r11, r0, lsr #31
 *   @0x29cb68 .word 0xffffef50
 *   @0x29cb6c .word 0xffffbf1c
 *   @0x29cb70 andeq r12, r11, r12, asr #30
 *
 * ══ §136/159 b2Contact::Destroy  0x2cc07c  size 164  41 条（0x2cc07c..0x2cc120）
 * @func 0x2cc07c 0x2cc120  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Contact::Destroy(b2Contact*, b2BlockAllocator*)+0x68
 * 字段偏移 top8: 0x4×5 / 0x2c×2 / 0x8×2 / 0xc×2 / 0x7c×1 / 0x30×1 / 0x34×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cc07c ldr r2, [r0, #0x7c]
 *   @0x2cc080 push {r4, lr}
 *   @0x2cc084 cmp r2, #0
 *   @0x2cc088 ldr r3, [r0, #0x30]
 *   @0x2cc08c ldr r2, [r0, #0x34]
 *   @0x2cc090 ble 0x2cc0e4 <_ZN9b2Contact7DestroyEPS_P16b2BlockAllocator+0x68>
 *   @0x2cc094 ldrb r12, [r3, #0x2c]
 *   @0x2cc098 cmp r12, #0
 *   @0x2cc09c bne 0x2cc0e4 <_ZN9b2Contact7DestroyEPS_P16b2BlockAllocator+0x68>
 *   @0x2cc0a0 ldrb r12, [r2, #0x2c]
 *   @0x2cc0a4 cmp r12, #0
 *   @0x2cc0a8 bne 0x2cc0e4 <_ZN9b2Contact7DestroyEPS_P16b2BlockAllocator+0x68>
 *   @0x2cc0ac ldr r12, [r3, #0x8]
 *   @0x2cc0b0 ldrh lr, [r12, #4]
 *   @0x2cc0b4 tst lr, #2
 *   @0x2cc0b8 orreq lr, lr, #2
 *   @0x2cc0bc moveq r4, #0
 *   @0x2cc0c0 strheq lr, [r12, #4]
 *   @0x2cc0c4 streq r4, [r12, #0xa0]
 *   @0x2cc0c8 ldr r12, [r2, #0x8]
 *   @0x2cc0cc ldrh lr, [r12, #4]
 *   @0x2cc0d0 tst lr, #2
 *   @0x2cc0d4 orreq lr, lr, #2
 *   @0x2cc0d8 strheq lr, [r12, #4]
 *   @0x2cc0dc moveq r4, #0
 *   @0x2cc0e0 streq r4, [r12, #0xa0]
 *   @0x2cc0e4 ldr r12, [r3, #0xc]
 *   @0x2cc0e8 ldr r2, [r2, #0xc]
 *   @0x2cc0ec ldr r3, [pc, #0x28]
 *   @0x2cc0f0 ldr r12, [r12, #0x4]
 *   @0x2cc0f4 ldr r2, [r2, #0x4]
 *   @0x2cc0f8 ldr r3, [pc, r3]
 *   @0x2cc0fc add r12, r12, r12, lsl #1
 *   @0x2cc100 add r2, r2, r2, lsl #1
 *   @0x2cc104 lsl r12, r12, #4
 *   @0x2cc108 add r2, r12, r2, lsl #2
 *   @0x2cc10c add r3, r3, r2
 *   @0x2cc110 ldr r3, [r3, #0x4]
 *   @0x2cc114 blx r3
 *   @0x2cc118 pop {r4, pc}
 *   @0x2cc11c andseq r5, r2, r12, lsl #20
 *
 * ══ §137/159 b2DynamicTree::b2DynamicTree  0x2de900  size 164  41 条（0x2de900..0x2de9a4）
 * @func 0x2de900 0x2de9a4  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Alloc(int) / 0xb65b0 / b2DynamicTree::b2DynamicTree()+0x78
 * 字段偏移 top8: 0xc×3 / 0x4×2 / 0x14×2 / 0x8×1 / 0x20×1 / 0x-10×1 / 0x-4×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2de900 push {r3, r4, r5, r6, r7, lr}
 *   @0x2de904 mov r4, r0
 *   @0x2de908 mov r3, #16
 *   @0x2de90c mov r5, #0
 *   @0x2de910 str r3, [r0, #0xc]
 *   @0x2de914 mvn r6, #0
 *   @0x2de918 str r6, [r0]
 *   @0x2de91c mov r0, #576
 *   @0x2de920 str r5, [r4, #0x8]
 *   @0x2de924 bl 0x2c6a6c <_Z7b2Alloci>
 *   @0x2de928 ldr r3, [r4, #0xc]
 *   @0x2de92c mov r1, r5
 *   @0x2de930 add r2, r3, r3, lsl #3
 *   @0x2de934 lsl r2, r2, #2
 *   @0x2de938 str r0, [r4, #0x4]
 *   @0x2de93c bl 0xb65b0 <memset@plt>
 *   @0x2de940 ldr r12, [r4, #0xc]
 *   @0x2de944 ldr r7, [r4, #0x4]
 *   @0x2de948 cmp r12, #1
 *   @0x2de94c subgt r0, r12, #1
 *   @0x2de950 movgt r1, r5
 *   @0x2de954 movgt r2, r6
 *   @0x2de958 movgt r3, r7
 *   @0x2de95c ble 0x2de978 <_ZN13b2DynamicTreeC2Ev+0x78>
 *   @0x2de960 add r1, r1, #1
 *   @0x2de964 str r2, [r3, #0x20]
 *   @0x2de968 cmp r1, r0
 *   @0x2de96c str r1, [r3, #0x14]
 *   @0x2de970 add r3, r3, #36
 *   @0x2de974 bne 0x2de960 <_ZN13b2DynamicTreeC2Ev+0x60>
 *   @0x2de978 add r12, r12, r12, lsl #3
 *   @0x2de97c mov r3, #0
 *   @0x2de980 mvn r2, #0
 *   @0x2de984 mov r0, r4
 *   @0x2de988 add r12, r7, r12, lsl #2
 *   @0x2de98c str r2, [r12, #-0x10]
 *   @0x2de990 str r2, [r12, #-0x4]
 *   @0x2de994 str r3, [r4, #0x10]
 *   @0x2de998 str r3, [r4, #0x14]
 *   @0x2de99c str r3, [r4, #0x18]
 *   @0x2de9a0 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §138/159 CSkeletonInstance::SetupSkeletonData  0xbe5dc  size 160  40 条（0xbe5dc..0xbe67c）
 * @func 0xbe5dc 0xbe67c  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spSkeleton_create / spAnimationStateData_create / spAnimationState_create / CSkeletonInstance::SetupSkeletonData(spSkeletonData*)+0x84 / CSkeletonInstance::SelectAnimation(char const*) / CSkeletonInstance::SelectSkin(char const*) / spSkeletonBounds_create
 * 字段偏移 top8: 0xc×2 / 0x20×2 / 0x8×2 / 0x34×2 / 0x30×1 / 0x1c×1 / 0x24×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xbe5dc push {r3, r4, r5, lr}
 *   @0xbe5e0 mov r4, r0
 *   @0xbe5e4 str r1, [r4, #0x30]
 *   @0xbe5e8 mov r0, r1
 *   @0xbe5ec mov r5, r1
 *   @0xbe5f0 bl 0x289b40 <spSkeleton_create>
 *   @0xbe5f4 cmp r0, #0
 *   @0xbe5f8 str r0, [r4, #0x1c]
 *   @0xbe5fc popeq {r3, r4, r5, pc}
 *   @0xbe600 ldr r3, [r0, #0xc]
 *   @0xbe604 ldr r0, [r0]
 *   @0xbe608 ldr r2, [r3, #0x20]
 *   @0xbe60c ldr r3, [r3, #0x24]
 *   @0xbe610 str r2, [r4, #0x8]
 *   @0xbe614 str r3, [r4, #0xc]
 *   @0xbe618 bl 0x283b2c <spAnimationStateData_create>
 *   @0xbe61c cmp r0, #0
 *   @0xbe620 str r0, [r4, #0x2c]
 *   @0xbe624 popeq {r3, r4, r5, pc}
 *   @0xbe628 bl 0x283128 <spAnimationState_create>
 *   @0xbe62c cmp r0, #0
 *   @0xbe630 str r0, [r4, #0x28]
 *   @0xbe634 popeq {r3, r4, r5, pc}
 *   @0xbe638 ldr r2, [r5, #0x34]
 *   @0xbe63c ldr r3, [pc, #0x34]
 *   @0xbe640 cmp r2, #0
 *   @0xbe644 str r4, [r0, #0x14]
 *   @0xbe648 ldr r3, [pc, r3]
 *   @0xbe64c str r3, [r0, #0x8]
 *   @0xbe650 ble 0xbe660 <_ZN17CSkeletonInstance17SetupSkeletonDataEP14spSkeletonData+0x84>
 *   @0xbe654 mov r0, r4
 *   @0xbe658 mov r1, #0
 *   @0xbe65c bl 0xbe578 <_ZN17CSkeletonInstance15SelectAnimationEPKc>
 *   @0xbe660 mov r0, r4
 *   @0xbe664 mov r1, #0
 *   @0xbe668 bl 0xbe590 <_ZN17CSkeletonInstance10SelectSkinEPKc>
 *   @0xbe66c bl 0x28a834 <spSkeletonBounds_create>
 *   @0xbe670 str r0, [r4, #0x20]
 *   @0xbe674 pop {r3, r4, r5, pc}
 *   @0xbe678 eorseq pc, r2, r8, ror #5
 *
 * ══ §139/159 CBackground::DrawGeneral  0xc2238  size 160  40 条（0xc2238..0xc22d8）
 * @func 0xc2238 0xc22d8  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x28×2 / 0x2c×2 / 0x30×2 / 0x38×2 / 0x3c×2 / 0x40×2 / 0x44×2 / 0x48×2
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc2238 ldr r12, [r0, #0x14]
 *   @0xc223c vldr s12, [pc, #140]
 *   @0xc2240 push {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0xc2244 cmp r12, #0
 *   @0xc2248 vldr s15, [sp, #52]
 *   @0xc224c vldr s13, [sp, #32]
 *   @0xc2250 vmul.f32 s15, s15, s12
 *   @0xc2254 vldr s14, [sp, #36]
 *   @0xc2258 ldr r11, [sp, #0x28]
 *   @0xc225c ldr r10, [sp, #0x2c]
 *   @0xc2260 vldr s12, [pc, #108]
 *   @0xc2264 ldr r9, [sp, #0x30]
 *   @0xc2268 ldr r7, [sp, #0x38]
 *   @0xc226c ldr r6, [sp, #0x3c]
 *   @0xc2270 ldr r5, [sp, #0x40]
 *   @0xc2274 ldr r4, [sp, #0x44]
 *   @0xc2278 ldr r8, [sp, #0x48]
 *   @0xc227c beq 0xc2294 <_ZN11CBackground11DrawGeneralEfffffffffjjjjf+0x5c>
 *   @0xc2280 mov r0, r12
 *   @0xc2284 vdiv.f32 s15, s15, s12
 *   @0xc2288 vstr s15, [sp, #52]
 *   @0xc228c pop {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0xc2290 b 0x175a90 <_Z26GR_Texture_Draw_Part_ColorP12YYTPageEntryfffffffffjjjjf>
 *   @0xc2294 vdiv.f32 s15, s15, s12
 *   @0xc2298 ldr r0, [r0, #0xc]
 *   @0xc229c vstr s13, [sp, #32]
 *   @0xc22a0 vstr s14, [sp, #36]
 *   @0xc22a4 str r11, [sp, #0x28]
 *   @0xc22a8 str r10, [sp, #0x2c]
 *   @0xc22ac str r9, [sp, #0x30]
 *   @0xc22b0 str r7, [sp, #0x38]
 *   @0xc22b4 str r6, [sp, #0x3c]
 *   @0xc22b8 str r5, [sp, #0x40]
 *   @0xc22bc str r4, [sp, #0x44]
 *   @0xc22c0 str r8, [sp, #0x48]
 *   @0xc22c4 vstr s15, [sp, #52]
 *   @0xc22c8 pop {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0xc22cc b 0x175834 <_Z26GR_Texture_Draw_Part_Colorifffffffffjjjjf>
 *   @0xc22d0 ldrdmi r0, r1, [r9], #-251
 *   @0xc22d4 teqmi r4, #0
 *
 * ══ §140/159 GR_Window_Views_Mouse_Get_XY  0x17acec  size 160  40 条（0x17acec..0x17ad8c）
 * @func 0x17acec 0x17ad8c  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x17ad04→0x54298c, 0x17ad18→0x53468c, 0x17ad20→0x534664, 0x17ad54→0x53468c, 0x17ad58→0x534664
 * 调用序列: 无
 * 字段偏移 top8: 0x2×4 / 0x28×2 / 0x84×1 / 0x74×1 / 0x64×1 / 0x60×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17acec cmp r2, #9
 *   @0x17acf0 ldr r12, [pc, #0x84]
 *   @0x17acf4 push {r4, r5, r6}
 *   @0x17acf8 add r12, pc, r12
 *   @0x17acfc mov r4, r2
 *   @0x17ad00 bhi 0x17ad40 <_Z28GR_Window_Views_Mouse_Get_XYRiS_i+0x54>
 *   @0x17ad04 ldr r3, [pc, #0x74]
 *   @0x17ad08 ldr r3, [r12, r3]
 *   @0x17ad0c ldr r3, [r3]
 *   @0x17ad10 cmp r3, #0
 *   @0x17ad14 beq 0x17ad54 <_Z28GR_Window_Views_Mouse_Get_XYRiS_i+0x68>
 *   @0x17ad18 ldr r6, [pc, #0x64]
 *   @0x17ad1c mov r2, r0
 *   @0x17ad20 ldr r5, [pc, #0x60]
 *   @0x17ad24 mov r3, r1
 *   @0x17ad28 ldr r0, [r12, r6]
 *   @0x17ad2c ldr r1, [r12, r5]
 *   @0x17ad30 ldr r0, [r0, r4, lsl #2]
 *   @0x17ad34 ldr r1, [r1, r4, lsl #2]
 *   @0x17ad38 pop {r4, r5, r6}
 *   @0x17ad3c b 0x17a6a0 <_Z23GR_Window_Views_ConvertiiRiS_>
 *   @0x17ad40 mov r3, #0
 *   @0x17ad44 str r3, [r0]
 *   @0x17ad48 pop {r4, r5, r6}
 *   @0x17ad4c str r3, [r1]
 *   @0x17ad50 bx lr
 *   @0x17ad54 ldr r2, [pc, #0x28]
 *   @0x17ad58 ldr r3, [pc, #0x28]
 *   @0x17ad5c ldr r2, [r12, r2]
 *   @0x17ad60 ldr r2, [r2, r4, lsl #2]
 *   @0x17ad64 str r2, [r0]
 *   @0x17ad68 ldr r3, [r12, r3]
 *   @0x17ad6c ldr r3, [r3, r4, lsl #2]
 *   @0x17ad70 pop {r4, r5, r6}
 *   @0x17ad74 str r3, [r1]
 *   @0x17ad78 bx lr
 *   @0x17ad7c eoreq r6, r7, r8, asr pc
 *   @0x17ad80 .word 0xffffbcd8
 *   @0x17ad84 .word 0xffffdf4c
 *   @0x17ad88 .word 0xffffdf48
 *
 * ══ §141/159 Shader_Set_Uniform_Matrix_N  0x1889fc  size 160  40 条（0x1889fc..0x188a9c）
 * @func 0x1889fc 0x188a9c  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Shader_Set_Uniform_Matrix_N(int, int, float*)+0x24 / Shader_Get(int) / Shader_Set_Uniform_Matrix(int, int, int, float*)
 * 字段偏移 top8: 0x90×1 / 0x60×1 / 0x64×1 / 0x7c×1 / 0x78×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1889fc ldr r12, [pc, #0x90]
 *   @0x188a00 push {r3, r4, r5, r6, r7, lr}
 *   @0x188a04 ldr r12, [pc, r12]
 *   @0x188a08 mov r5, r0
 *   @0x188a0c mov r7, r1
 *   @0x188a10 ldr r4, [r12]
 *   @0x188a14 mov r6, r2
 *   @0x188a18 cmp r4, #1
 *   @0x188a1c beq 0x188a28 <_Z27Shader_Set_Uniform_Matrix_NiiPf+0x2c>
 *   @0x188a20 mov r0, #0
 *   @0x188a24 pop {r3, r4, r5, r6, r7, pc}
 *   @0x188a28 cmp r0, #0
 *   @0x188a2c blt 0x188a20 <_Z27Shader_Set_Uniform_Matrix_NiiPf+0x24>
 *   @0x188a30 ldr r0, [pc, #0x60]
 *   @0x188a34 ldr r0, [pc, r0]
 *   @0x188a38 ldr r3, [r0]
 *   @0x188a3c cmp r3, #0
 *   @0x188a40 beq 0x188a20 <_Z27Shader_Set_Uniform_Matrix_NiiPf+0x24>
 *   @0x188a44 ldr r0, [r3, #0x64]
 *   @0x188a48 bl 0x187e70 <_Z10Shader_Geti>
 *   @0x188a4c cmp r0, #0
 *   @0x188a50 beq 0x188a20 <_Z27Shader_Set_Uniform_Matrix_NiiPf+0x24>
 *   @0x188a54 ldr r3, [r0, #0x7c]
 *   @0x188a58 cmp r5, r3
 *   @0x188a5c bge 0x188a20 <_Z27Shader_Set_Uniform_Matrix_NiiPf+0x24>
 *   @0x188a60 ldr r3, [r0, #0x78]
 *   @0x188a64 rsb r5, r5, r5, lsl #3
 *   @0x188a68 adds r5, r3, r5, lsl #2
 *   @0x188a6c beq 0x188a20 <_Z27Shader_Set_Uniform_Matrix_NiiPf+0x24>
 *   @0x188a70 ldr r1, [r5, #0xc]
 *   @0x188a74 cmp r1, #4
 *   @0x188a78 bne 0x188a20 <_Z27Shader_Set_Uniform_Matrix_NiiPf+0x24>
 *   @0x188a7c ldr r0, [r5, #0x4]
 *   @0x188a80 mov r2, r7
 *   @0x188a84 mov r3, r6
 *   @0x188a88 bl 0x18829c <_Z25Shader_Set_Uniform_MatrixiiiPf>
 *   @0x188a8c mov r0, r4
 *   @0x188a90 pop {r3, r4, r5, r6, r7, pc}
 *   @0x188a94 eoreq r7, r6, r4, lsl #20
 *   @0x188a98 eoreq r7, r6, r4, asr #20
 *
 * ══ §142/159 ParticleSystem_NextDepth  0x1a579c  size 160  40 条（0x1a579c..0x1a583c）
 * @func 0x1a579c 0x1a5850  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleSystem_NextDepth(float)+0x8c / ParticleSystem_Exists(int) / ParticleSystem_NextDepth(float)+0x70
 * 字段偏移 top8: 0x84×1 / 0x64×1 / 0x4×1 / 0x2×1 / 0x29×1
 * VFP 指令 13 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a579c push {r3, r4, r5, lr}
 *   @0x1a57a0 vpush {d8}
 *   @0x1a57a4 vmov s17, r0
 *   @0x1a57a8 ldr r5, [pc, #0x84]
 *   @0x1a57ac ldr r5, [pc, r5]
 *   @0x1a57b0 ldr r3, [r5]
 *   @0x1a57b4 cmp r3, #0
 *   @0x1a57b8 ble 0x1a5828 <_Z24ParticleSystem_NextDepthf+0x8c>
 *   @0x1a57bc mov r4, #0
 *   @0x1a57c0 vldr s16, [pc, #104]
 *   @0x1a57c4 mov r0, r4
 *   @0x1a57c8 bl 0x1a3770 <_Z21ParticleSystem_Existsi>
 *   @0x1a57cc ldr r3, [pc, #0x64]
 *   @0x1a57d0 cmp r0, #0
 *   @0x1a57d4 beq 0x1a580c <_Z24ParticleSystem_NextDepthf+0x70>
 *   @0x1a57d8 ldr r3, [pc, r3]
 *   @0x1a57dc ldr r3, [r3, #0x4]
 *   @0x1a57e0 ldr r3, [r3, r4, lsl #2]
 *   @0x1a57e4 ldrb r2, [r3, #0x29]
 *   @0x1a57e8 cmp r2, #0
 *   @0x1a57ec beq 0x1a580c <_Z24ParticleSystem_NextDepthf+0x70>
 *   @0x1a57f0 vldr s15, [r3, #28]
 *   @0x1a57f4 vcmpe.f32 s15, s16
 *   @0x1a57f8 vmrs APSR_nzcv, fpscr
 *   @0x1a57fc ble 0x1a580c <_Z24ParticleSystem_NextDepthf+0x70>
 *   @0x1a5800 vcmp.f32 s15, s17
 *   @0x1a5804 vmrs APSR_nzcv, fpscr
 *   @0x1a5808 vmovmi.f32 s16, s15
 *   @0x1a580c ldr r3, [r5]
 *   @0x1a5810 add r4, r4, #1
 *   @0x1a5814 cmp r3, r4
 *   @0x1a5818 bgt 0x1a57c4 <_Z24ParticleSystem_NextDepthf+0x28>
 *   @0x1a581c vmov r0, s16
 *   @0x1a5820 vpop {d8}
 *   @0x1a5824 pop {r3, r4, r5, pc}
 *   @0x1a5828 vldr s16, [pc]
 *   @0x1a582c b 0x1a581c <_Z24ParticleSystem_NextDepthf+0x80>
 *   @0x1a5830 vmulgt.f64 d22, d14, d24
 *   @0x1a5834 eoreq r11, r4, r8
 *   @0x1a5838 eoreq r10, r4, r0, ror #31
 *
 * ══ §143/159 CAudioGroupMan::InitSoundLists  0x21df78  size 160  40 条（0x21df78..0x21e018）
 * @func 0x21df78 0x21e018  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CAudioGroupMan::IncSoundCount(int) / CAudioGroupMan::GetGroup(int) / CAudioGroup::AddSound(cAudio_Sound*)
 * 字段偏移 top8: 0x4×3 / 0x2×2 / 0x4c×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21df78 push {r3, r4, r5, r6, r7, lr}
 *   @0x21df7c mov r7, r0
 *   @0x21df80 ldr r3, [r0, #0x4]
 *   @0x21df84 mov r5, r1
 *   @0x21df88 cmp r3, #0
 *   @0x21df8c popeq {r3, r4, r5, r6, r7, pc}
 *   @0x21df90 ldr r3, [r1]
 *   @0x21df94 cmp r3, #0
 *   @0x21df98 pople {r3, r4, r5, r6, r7, pc}
 *   @0x21df9c mov r4, #0
 *   @0x21dfa0 ldr r2, [r5, #0x4]
 *   @0x21dfa4 mov r0, r7
 *   @0x21dfa8 ldr r2, [r2, r4, lsl #2]
 *   @0x21dfac add r4, r4, #1
 *   @0x21dfb0 cmp r2, #0
 *   @0x21dfb4 beq 0x21dfc4 <_ZN14CAudioGroupMan14InitSoundListsER12cARRAY_CLASSIP12cAudio_SoundE+0x4c>
 *   @0x21dfb8 ldr r1, [r2, #0x4c]
 *   @0x21dfbc bl 0x21df5c <_ZN14CAudioGroupMan13IncSoundCountEi>
 *   @0x21dfc0 ldr r3, [r5]
 *   @0x21dfc4 cmp r3, r4
 *   @0x21dfc8 bgt 0x21dfa0 <_ZN14CAudioGroupMan14InitSoundListsER12cARRAY_CLASSIP12cAudio_SoundE+0x28>
 *   @0x21dfcc cmp r3, #0
 *   @0x21dfd0 pople {r3, r4, r5, r6, r7, pc}
 *   @0x21dfd4 mov r4, #0
 *   @0x21dfd8 ldr r2, [r5, #0x4]
 *   @0x21dfdc mov r0, r7
 *   @0x21dfe0 ldr r6, [r2, r4, lsl #2]
 *   @0x21dfe4 cmp r6, #0
 *   @0x21dfe8 beq 0x21e008 <_ZN14CAudioGroupMan14InitSoundListsER12cARRAY_CLASSIP12cAudio_SoundE+0x90>
 *   @0x21dfec ldr r1, [r6, #0x4c]
 *   @0x21dff0 bl 0x21df0c <_ZN14CAudioGroupMan8GetGroupEi>
 *   @0x21dff4 mov r1, r6
 *   @0x21dff8 cmp r0, #0
 *   @0x21dffc beq 0x21e004 <_ZN14CAudioGroupMan14InitSoundListsER12cARRAY_CLASSIP12cAudio_SoundE+0x8c>
 *   @0x21e000 bl 0x21dc20 <_ZN11CAudioGroup8AddSoundEP12cAudio_Sound>
 *   @0x21e004 ldr r3, [r5]
 *   @0x21e008 add r4, r4, #1
 *   @0x21e00c cmp r3, r4
 *   @0x21e010 bgt 0x21dfd8 <_ZN14CAudioGroupMan14InitSoundListsER12cARRAY_CLASSIP12cAudio_SoundE+0x60>
 *   @0x21e014 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §144/159 vorbis_synthesis_idheader  0x22aec4  size 160  40 条（0x22aec4..0x22af64）
 * @func 0x22aec4 0x22af64  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: oggpack_read×2 / oggpack_readinit / 0xb6c40
 * 字段偏移 top8: 0x4×2 / 0x8×1 / 0x1×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x22aec4 push {r4, r5, r6, r7, lr}
 *   @0x22aec8 subs r4, r0, #0
 *   @0x22aecc sub sp, sp, #36
 *   @0x22aed0 beq 0x22aef0 <vorbis_synthesis_idheader+0x2c>
 *   @0x22aed4 add r5, sp, #12
 *   @0x22aed8 ldm r4, {r1, r2}
 *   @0x22aedc mov r0, r5
 *   @0x22aee0 bl 0x23385c <oggpack_readinit>
 *   @0x22aee4 ldr r3, [r4, #0x8]
 *   @0x22aee8 cmp r3, #0
 *   @0x22aeec bne 0x22aefc <vorbis_synthesis_idheader+0x38>
 *   @0x22aef0 mov r0, #0
 *   @0x22aef4 add sp, sp, #36
 *   @0x22aef8 pop {r4, r5, r6, r7, pc}
 *   @0x22aefc mov r0, r5
 *   @0x22af00 mov r1, #8
 *   @0x22af04 bl 0x233b28 <oggpack_read>
 *   @0x22af08 cmp r0, #1
 *   @0x22af0c bne 0x22aef0 <vorbis_synthesis_idheader+0x2c>
 *   @0x22af10 add r7, sp, #4
 *   @0x22af14 add r4, sp, #3
 *   @0x22af18 add r6, sp, #9
 *   @0x22af1c mov r3, #0
 *   @0x22af20 strh r3, [r7, #4]
 *   @0x22af24 str r3, [sp, #0x4]
 *   @0x22af28 mov r0, r5
 *   @0x22af2c mov r1, #8
 *   @0x22af30 bl 0x233b28 <oggpack_read>
 *   @0x22af34 strb r0, [r4, #0x1]!
 *   @0x22af38 cmp r4, r6
 *   @0x22af3c bne 0x22af28 <vorbis_synthesis_idheader+0x64>
 *   @0x22af40 ldr r1, [pc, #0x18]
 *   @0x22af44 mov r0, r7
 *   @0x22af48 mov r2, #6
 *   @0x22af4c add r1, pc, r1
 *   @0x22af50 bl 0xb6c40 <memcmp@plt>
 *   @0x22af54 rsbs r0, r0, #1
 *   @0x22af58 movlo r0, #0
 *   @0x22af5c b 0x22aef4 <vorbis_synthesis_idheader+0x30>
 *   @0x22af60 andseq r10, r2, r8, lsl #3
 *
 * ══ §145/159 b2Island::Report  0x2e1224  size 160  40 条（0x2e1224..0x2e12c4）
 * @func 0x2e1224 0x2e12c4  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Island::Report(b2ContactVelocityConstraint const*)+0x98 / b2Island::Report(b2ContactVelocityConstraint const*)+0x74
 * 字段偏移 top8: 0x4×3 / 0x24×2 / 0xc×2 / 0x14×2 / 0x2×1 / 0x-84×1 / 0x-80×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e1224 push {r4, r5, r6, r7, lr}
 *   @0x2e1228 mov r6, r0
 *   @0x2e122c ldr r0, [r0, #0x4]
 *   @0x2e1230 sub sp, sp, #28
 *   @0x2e1234 cmp r0, #0
 *   @0x2e1238 beq 0x2e12bc <_ZN8b2Island6ReportEPK27b2ContactVelocityConstraint+0x98>
 *   @0x2e123c ldr r3, [r6, #0x24]
 *   @0x2e1240 cmp r3, #0
 *   @0x2e1244 ble 0x2e12bc <_ZN8b2Island6ReportEPK27b2ContactVelocityConstraint+0x98>
 *   @0x2e1248 add r4, r1, #148
 *   @0x2e124c add r7, sp, #4
 *   @0x2e1250 mov r5, #0
 *   @0x2e1254 b 0x2e125c <_ZN8b2Island6ReportEPK27b2ContactVelocityConstraint+0x38>
 *   @0x2e1258 ldr r0, [r6, #0x4]
 *   @0x2e125c ldr r3, [r4]
 *   @0x2e1260 ldr r2, [r6, #0xc]
 *   @0x2e1264 cmp r3, #0
 *   @0x2e1268 ldr r1, [r2, r5, lsl #2]
 *   @0x2e126c str r3, [sp, #0x14]
 *   @0x2e1270 ble 0x2e1298 <_ZN8b2Island6ReportEPK27b2ContactVelocityConstraint+0x74>
 *   @0x2e1274 cmp r3, #1
 *   @0x2e1278 ldr r2, [r4, #-0x84]
 *   @0x2e127c ldr r3, [r4, #-0x80]
 *   @0x2e1280 str r2, [sp, #0x4]
 *   @0x2e1284 str r3, [sp, #0xc]
 *   @0x2e1288 ldrne r2, [r4, #-0x60]
 *   @0x2e128c ldrne r3, [r4, #-0x5c]
 *   @0x2e1290 strne r2, [sp, #0x8]
 *   @0x2e1294 strne r3, [sp, #0x10]
 *   @0x2e1298 ldr r3, [r0]
 *   @0x2e129c mov r2, r7
 *   @0x2e12a0 add r5, r5, #1
 *   @0x2e12a4 add r4, r4, #156
 *   @0x2e12a8 ldr r3, [r3, #0x14]
 *   @0x2e12ac blx r3
 *   @0x2e12b0 ldr r3, [r6, #0x24]
 *   @0x2e12b4 cmp r3, r5
 *   @0x2e12b8 bgt 0x2e1258 <_ZN8b2Island6ReportEPK27b2ContactVelocityConstraint+0x34>
 *   @0x2e12bc add sp, sp, #28
 *   @0x2e12c0 pop {r4, r5, r6, r7, pc}
 *
 * ══ §146/159 YYRandom  0xc44ec  size 156  39 条（0xc44ec..0xc4588）
 * @func 0xc44ec 0xc4588  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f2004
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x2×6 / 0x88×2 / 0x84×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc44ec ldr r1, [pc, #0x88]
 *   @0xc44f0 ldr r3, [pc, #0x88]
 *   @0xc44f4 ldr r1, [pc, r1]
 *   @0xc44f8 ldr r0, [pc, #0x84]
 *   @0xc44fc ldr r3, [pc, r3]
 *   @0xc4500 ldr r2, [r1]
 *   @0xc4504 add r0, pc, r0
 *   @0xc4508 push {r4, r5, r6}
 *   @0xc450c add r4, r2, #13
 *   @0xc4510 add r5, r2, #9
 *   @0xc4514 ldr r6, [r3, r2, lsl #2]
 *   @0xc4518 and r4, r4, #15
 *   @0xc451c and r5, r5, #15
 *   @0xc4520 add r12, r2, #15
 *   @0xc4524 ldr r0, [r0]
 *   @0xc4528 ldr r4, [r3, r4, lsl #2]
 *   @0xc452c eor r6, r6, r6, lsl #16
 *   @0xc4530 ldr r5, [r3, r5, lsl #2]
 *   @0xc4534 and r12, r12, #15
 *   @0xc4538 eor r6, r6, r4
 *   @0xc453c str r12, [r1]
 *   @0xc4540 eor r1, r6, r4, lsl #15
 *   @0xc4544 eor r5, r5, r5, lsr #11
 *   @0xc4548 eor r4, r5, r1
 *   @0xc454c str r4, [r3, r2, lsl #2]
 *   @0xc4550 ldr r2, [r3, r12, lsl #2]
 *   @0xc4554 and r6, r0, r4, lsl #5
 *   @0xc4558 eor r2, r2, r2, lsl #2
 *   @0xc455c eor r0, r2, r1
 *   @0xc4560 eor r0, r0, r4
 *   @0xc4564 eor r0, r0, r1, lsl #18
 *   @0xc4568 eor r0, r0, r5, lsl #28
 *   @0xc456c eor r0, r0, r6
 *   @0xc4570 str r0, [r3, r12, lsl #2]
 *   @0xc4574 pop {r4, r5, r6}
 *   @0xc4578 bx lr
 *   @0xc457c eorseq r9, r2, r8, ror r4
 *   @0xc4580 eorseq r9, r2, r8, ror #8
 *   @0xc4584 ldrshteq sp, [r2], -r8
 *
 * ══ §147/159 DBG_BIND_FRAMEBUFFER  0x1805b4  size 156  39 条（0x1805b4..0x180650）
 * @func 0x1805b4 0x180664  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1805cc→0x3f26dc, 0x1805e0→0x479c04, 0x1805fc→0x479b3c, 0x180604→0x3eb70c, 0x180608→0x4a2f4c
 * 调用序列: 无
 * 字段偏移 top8: 0x38×3 / 0x70×1 / 0x64×1 / 0x54×1 / 0x3c×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1805b4 push {r3, r4, r5, lr}
 *   @0x1805b8 cmn r0, #1
 *   @0x1805bc ldr r4, [pc, #0x70]
 *   @0x1805c0 mov r5, r0
 *   @0x1805c4 add r4, pc, r4
 *   @0x1805c8 beq 0x180604 <_Z20DBG_BIND_FRAMEBUFFERi+0x50>
 *   @0x1805cc ldr r3, [pc, #0x64]
 *   @0x1805d0 ldr r3, [r4, r3]
 *   @0x1805d4 ldr r3, [r3]
 *   @0x1805d8 cmp r3, #1
 *   @0x1805dc beq 0x1805fc <_Z20DBG_BIND_FRAMEBUFFERi+0x48>
 *   @0x1805e0 ldr r3, [pc, #0x54]
 *   @0x1805e4 ldr r3, [r4, r3]
 *   @0x1805e8 mov r1, r5
 *   @0x1805ec movw r0, #0x8d40
 *   @0x1805f0 ldr r3, [r3]
 *   @0x1805f4 blx r3
 *   @0x1805f8 pop {r3, r4, r5, pc}
 *   @0x1805fc ldr r3, [pc, #0x3c]
 *   @0x180600 b 0x1805e4 <_Z20DBG_BIND_FRAMEBUFFERi+0x30>
 *   @0x180604 ldr r2, [pc, #0x38]
 *   @0x180608 ldr r3, [pc, #0x38]
 *   @0x18060c ldr r1, [pc, #0x38]
 *   @0x180610 ldr r2, [r4, r2]
 *   @0x180614 ldr r3, [r4, r3]
 *   @0x180618 add r1, pc, r1
 *   @0x18061c ldr r0, [r2]
 *   @0x180620 ldm r3, {r2, r3}
 *   @0x180624 ldr r12, [r0]
 *   @0x180628 ldr r12, [r12, #0xc]
 *   @0x18062c blx r12
 *   @0x180630 b 0x1805cc <_Z20DBG_BIND_FRAMEBUFFERi+0x18>
 *   @0x180634 eoreq r1, r7, r12, lsl #13
 *   @0x180638 .word 0xffffe7b8
 *   @0x18063c .word 0xffffbc78
 *   @0x180640 .word 0xffffbb74
 *   @0x180644 .word 0xffffbac4
 *   @0x180648 .word 0xffffe81c
 *   @0x18064c andseq r11, r12, r12, lsl #7
 *
 * ══ §148/159 SetAlphaTestUniforms  0x184190  size 156  39 条（0x184190..0x18422c）
 * @func 0x184190 0x18422c  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1841ac→0x479b2c, 0x1841b0→0x4a23a8, 0x1841d4→0x3f27a8, 0x1841dc→0x479ab4
 * 调用序列: 无
 * 字段偏移 top8: 0x68×2 / 0x5c×1 / 0x74×1 / 0x60×1 / 0x48×1 / 0x44×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x184190 push {r3, r4, r5, lr}
 *   @0x184194 mov r5, r0
 *   @0x184198 ldr r0, [r0, #0x5c]
 *   @0x18419c ldr r4, [pc, #0x74]
 *   @0x1841a0 cmn r0, #1
 *   @0x1841a4 add r4, pc, r4
 *   @0x1841a8 beq 0x1841c8 <_Z20SetAlphaTestUniformsP10GLSLShader+0x38>
 *   @0x1841ac ldr r3, [pc, #0x68]
 *   @0x1841b0 ldr r2, [pc, #0x68]
 *   @0x1841b4 ldr r3, [r4, r3]
 *   @0x1841b8 ldr r2, [r4, r2]
 *   @0x1841bc ldr r3, [r3]
 *   @0x1841c0 ldrb r1, [r2]
 *   @0x1841c4 blx r3
 *   @0x1841c8 ldr r0, [r5, #0x60]
 *   @0x1841cc cmn r0, #1
 *   @0x1841d0 popeq {r3, r4, r5, pc}
 *   @0x1841d4 ldr r2, [pc, #0x48]
 *   @0x1841d8 vldr d6, [pc, #48]
 *   @0x1841dc ldr r3, [pc, #0x44]
 *   @0x1841e0 ldr r2, [r4, r2]
 *   @0x1841e4 vldr s14, [r2]
 *   @0x1841e8 vcvt.f32.s32 s14, s14
 *   @0x1841ec ldr r3, [r4, r3]
 *   @0x1841f0 ldr r3, [r3]
 *   @0x1841f4 vcvt.f64.f32 d7, s14
 *   @0x1841f8 vmul.f64 d7, d7, d6
 *   @0x1841fc vcvt.f32.f64 s13, d7
 *   @0x184200 vmov r1, s13
 *   @0x184204 blx r3
 *   @0x184208 pop {r3, r4, r5, pc}
 *   @0x18420c nop
 *   @0x184210 andsne r1, r0, r0, lsl r0
 *   @0x184214 svclo #0x701010
 *   @0x184218 eoreq sp, r6, r12, lsr #21
 *   @0x18421c .word 0xffffbb84
 *   @0x184220 .word 0xffffe89c
 *   @0x184224 .word 0xffffe888
 *   @0x184228 .word 0xffffbbfc
 *
 * ══ §149/159 Shader_Set_Uniform_F  0x188164  size 156  39 条（0x188164..0x188200）
 * @func 0x188164 0x188214  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics::Flush()
 * 字段偏移 top8: 0x78×1 / 0x34×1 / 0x18×1 / 0x14×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x188164 push {r4, r5, r6, r7, r8, lr}
 *   @0x188168 cmn r0, #1
 *   @0x18816c ldr r4, [pc, #0x78]
 *   @0x188170 mov r5, r0
 *   @0x188174 mov r7, r1
 *   @0x188178 mov r8, r2
 *   @0x18817c mov r6, r3
 *   @0x188180 add r4, pc, r4
 *   @0x188184 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x188188 cmp r3, #0
 *   @0x18818c popeq {r4, r5, r6, r7, r8, pc}
 *   @0x188190 bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x188194 sub r3, r7, #1
 *   @0x188198 cmp r3, #3
 *   @0x18819c addls pc, pc, r3, lsl #2
 *   @0x1881a0 b 0x1881d0 <_Z20Shader_Set_Uniform_FiiiPf+0x6c>
 *   @0x1881a4 b 0x1881d4 <_Z20Shader_Set_Uniform_FiiiPf+0x70>
 *   @0x1881a8 b 0x1881dc <_Z20Shader_Set_Uniform_FiiiPf+0x78>
 *   @0x1881ac b 0x1881e4 <_Z20Shader_Set_Uniform_FiiiPf+0x80>
 *   @0x1881b0 b 0x1881b4 <_Z20Shader_Set_Uniform_FiiiPf+0x50>
 *   @0x1881b4 ldr r3, [pc, #0x34]
 *   @0x1881b8 ldr r3, [r4, r3]
 *   @0x1881bc mov r0, r5
 *   @0x1881c0 mov r1, r8
 *   @0x1881c4 mov r2, r6
 *   @0x1881c8 ldr r3, [r3]
 *   @0x1881cc blx r3
 *   @0x1881d0 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1881d4 ldr r3, [pc, #0x18]
 *   @0x1881d8 b 0x1881b8 <_Z20Shader_Set_Uniform_FiiiPf+0x54>
 *   @0x1881dc ldr r3, [pc, #0x14]
 *   @0x1881e0 b 0x1881b8 <_Z20Shader_Set_Uniform_FiiiPf+0x54>
 *   @0x1881e4 ldr r3, [pc, #0x10]
 *   @0x1881e8 b 0x1881b8 <_Z20Shader_Set_Uniform_FiiiPf+0x54>
 *   @0x1881ec .word 0x00269ad0
 *   @0x1881f0 .word 0xffffbbd0
 *   @0x1881f4 .word 0xffffbbc4
 *   @0x1881f8 .word 0xffffbbc8
 *   @0x1881fc .word 0xffffbbcc
 *
 * ══ §150/159 Shader_Set_Uniform_I  0x188200  size 156  39 条（0x188200..0x18829c）
 * @func 0x188200 0x1882b0  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics::Flush()
 * 字段偏移 top8: 0x78×1 / 0x34×1 / 0x18×1 / 0x14×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x188200 push {r4, r5, r6, r7, r8, lr}
 *   @0x188204 cmn r0, #1
 *   @0x188208 ldr r4, [pc, #0x78]
 *   @0x18820c mov r5, r0
 *   @0x188210 mov r7, r1
 *   @0x188214 mov r8, r2
 *   @0x188218 mov r6, r3
 *   @0x18821c add r4, pc, r4
 *   @0x188220 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x188224 cmp r3, #0
 *   @0x188228 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x18822c bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x188230 sub r3, r7, #1
 *   @0x188234 cmp r3, #3
 *   @0x188238 addls pc, pc, r3, lsl #2
 *   @0x18823c b 0x18826c <_Z20Shader_Set_Uniform_IiiiPi+0x6c>
 *   @0x188240 b 0x188270 <_Z20Shader_Set_Uniform_IiiiPi+0x70>
 *   @0x188244 b 0x188278 <_Z20Shader_Set_Uniform_IiiiPi+0x78>
 *   @0x188248 b 0x188280 <_Z20Shader_Set_Uniform_IiiiPi+0x80>
 *   @0x18824c b 0x188250 <_Z20Shader_Set_Uniform_IiiiPi+0x50>
 *   @0x188250 ldr r3, [pc, #0x34]
 *   @0x188254 ldr r3, [r4, r3]
 *   @0x188258 mov r0, r5
 *   @0x18825c mov r1, r8
 *   @0x188260 mov r2, r6
 *   @0x188264 ldr r3, [r3]
 *   @0x188268 blx r3
 *   @0x18826c pop {r4, r5, r6, r7, r8, pc}
 *   @0x188270 ldr r3, [pc, #0x18]
 *   @0x188274 b 0x188254 <_Z20Shader_Set_Uniform_IiiiPi+0x54>
 *   @0x188278 ldr r3, [pc, #0x14]
 *   @0x18827c b 0x188254 <_Z20Shader_Set_Uniform_IiiiPi+0x54>
 *   @0x188280 ldr r3, [pc, #0x10]
 *   @0x188284 b 0x188254 <_Z20Shader_Set_Uniform_IiiiPi+0x54>
 *   @0x188288 eoreq r9, r6, r4, lsr r10
 *   @0x18828c .word 0xffffbbe0
 *   @0x188290 .word 0xffffbbd4
 *   @0x188294 .word 0xffffbbd8
 *   @0x188298 .word 0xffffbbdc
 *
 * ══ §151/159 CObjectGM::IsDecendentOf  0x19ddb0  size 156  39 条（0x19ddb0..0x19de4c）
 * @func 0x19ddb0 0x19de4c  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CObjectGM::IsDecendentOf(int)+0x80 / Object_Exists(int)
 * 字段偏移 top8: 0xc×4 / 0x4×2 / 0x64×1 / 0x3×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19ddb0 push {r3, r4, r5, lr}
 *   @0x19ddb4 mov r4, r0
 *   @0x19ddb8 mov r5, r1
 *   @0x19ddbc ldr r0, [r4, #0xc]
 *   @0x19ddc0 cmp r0, #0
 *   @0x19ddc4 blt 0x19de30 <_ZN9CObjectGM13IsDecendentOfEi+0x80>
 *   @0x19ddc8 cmp r0, r5
 *   @0x19ddcc beq 0x19de40 <_ZN9CObjectGM13IsDecendentOfEi+0x90>
 *   @0x19ddd0 bl 0x19ecf8 <_Z13Object_Existsi>
 *   @0x19ddd4 cmp r0, #0
 *   @0x19ddd8 beq 0x19de30 <_ZN9CObjectGM13IsDecendentOfEi+0x80>
 *   @0x19dddc ldr r3, [pc, #0x64]
 *   @0x19dde0 ldr r2, [r4, #0xc]
 *   @0x19dde4 ldr r3, [pc, r3]
 *   @0x19dde8 ldr r3, [r3]
 *   @0x19ddec ldr r1, [r3, #0x4]
 *   @0x19ddf0 ldr r3, [r3]
 *   @0x19ddf4 and r1, r2, r1
 *   @0x19ddf8 ldr r0, [r3, r1, lsl #3]
 *   @0x19ddfc cmp r0, #0
 *   @0x19de00 bne 0x19de14 <_ZN9CObjectGM13IsDecendentOfEi+0x64>
 *   @0x19de04 b 0x19de38 <_ZN9CObjectGM13IsDecendentOfEi+0x88>
 *   @0x19de08 ldr r0, [r0, #0x4]
 *   @0x19de0c cmp r0, #0
 *   @0x19de10 beq 0x19de38 <_ZN9CObjectGM13IsDecendentOfEi+0x88>
 *   @0x19de14 ldr r3, [r0, #0x8]
 *   @0x19de18 cmp r2, r3
 *   @0x19de1c bne 0x19de08 <_ZN9CObjectGM13IsDecendentOfEi+0x58>
 *   @0x19de20 ldr r4, [r0, #0xc]
 *   @0x19de24 ldr r0, [r4, #0xc]
 *   @0x19de28 cmp r0, #0
 *   @0x19de2c bge 0x19ddc8 <_ZN9CObjectGM13IsDecendentOfEi+0x18>
 *   @0x19de30 mov r0, #0
 *   @0x19de34 pop {r3, r4, r5, pc}
 *   @0x19de38 mov r4, r0
 *   @0x19de3c b 0x19ddbc <_ZN9CObjectGM13IsDecendentOfEi+0xc>
 *   @0x19de40 mov r0, #1
 *   @0x19de44 pop {r3, r4, r5, pc}
 *   @0x19de48 eoreq pc, r4, r8, asr lr
 *
 * ══ §152/159 ParticleSystem_DrawDepth  0x1a583c  size 156  39 条（0x1a583c..0x1a58d8）
 * @func 0x1a583c 0x1a58d8  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleSystem_DrawDepth(float)+0x7c / ParticleSystem_Exists(int) / ParticleSystem_Draw(int)
 * 字段偏移 top8: 0x80×1 / 0x60×1 / 0x4×1 / 0x2×1 / 0x29×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a583c push {r3, r4, r5, lr}
 *   @0x1a5840 vpush {d8}
 *   @0x1a5844 vmov s16, r0
 *   @0x1a5848 ldr r5, [pc, #0x80]
 *   @0x1a584c ldr r5, [pc, r5]
 *   @0x1a5850 ldr r3, [r5]
 *   @0x1a5854 cmp r3, #0
 *   @0x1a5858 ble 0x1a58b8 <_Z24ParticleSystem_DrawDepthf+0x7c>
 *   @0x1a585c mov r4, #0
 *   @0x1a5860 vldr s17, [pc, #100]
 *   @0x1a5864 mov r0, r4
 *   @0x1a5868 bl 0x1a3770 <_Z21ParticleSystem_Existsi>
 *   @0x1a586c ldr r3, [pc, #0x60]
 *   @0x1a5870 cmp r0, #0
 *   @0x1a5874 beq 0x1a58a8 <_Z24ParticleSystem_DrawDepthf+0x6c>
 *   @0x1a5878 ldr r3, [pc, r3]
 *   @0x1a587c ldr r3, [r3, #0x4]
 *   @0x1a5880 ldr r3, [r3, r4, lsl #2]
 *   @0x1a5884 ldrb r2, [r3, #0x29]
 *   @0x1a5888 cmp r2, #0
 *   @0x1a588c beq 0x1a58a8 <_Z24ParticleSystem_DrawDepthf+0x6c>
 *   @0x1a5890 vldr s15, [r3, #28]
 *   @0x1a5894 vsub.f32 s15, s15, s16
 *   @0x1a5898 vabs.f32 s15, s15
 *   @0x1a589c vcmpe.f32 s15, s17
 *   @0x1a58a0 vmrs APSR_nzcv, fpscr
 *   @0x1a58a4 bmi 0x1a58c0 <_Z24ParticleSystem_DrawDepthf+0x84>
 *   @0x1a58a8 ldr r3, [r5]
 *   @0x1a58ac add r4, r4, #1
 *   @0x1a58b0 cmp r3, r4
 *   @0x1a58b4 bgt 0x1a5864 <_Z24ParticleSystem_DrawDepthf+0x28>
 *   @0x1a58b8 vpop {d8}
 *   @0x1a58bc pop {r3, r4, r5, pc}
 *   @0x1a58c0 mov r0, r4
 *   @0x1a58c4 bl 0x1a56ac <_Z19ParticleSystem_Drawi>
 *   @0x1a58c8 b 0x1a58a8 <_Z24ParticleSystem_DrawDepthf+0x6c>
 *   @0x1a58cc stclo p7, c13, [r3], #-40
 *   @0x1a58d0 eoreq r10, r4, r8, ror #30
 *   @0x1a58d4 eoreq r10, r4, r0, asr #30
 *
 * ══ §153/159 Variable_GetValue_Direct  0x1f3b8c  size 156  39 条（0x1f3b8c..0x1f3c28）
 * @func 0x1f3b8c 0x1f3c3c  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Variable_GetValue_Direct(YYObjectBase*, int, int, RValue*)+0x58 / YYObjectBase::InternalGetYYVar(int)
 * 字段偏移 top8: 0x4×4 / 0x24×1 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f3b8c mov r12, r1
 *   @0x1f3b90 movw r1, #0x270f
 *   @0x1f3b94 cmp r12, r1
 *   @0x1f3b98 push {r4, lr}
 *   @0x1f3b9c sub sp, sp, #8
 *   @0x1f3ba0 bls 0x1f3be4 <_Z24Variable_GetValue_DirectP12YYObjectBaseiiP6RValue+0x58>
 *   @0x1f3ba4 ldr r1, [r0, #0x24]
 *   @0x1f3ba8 cmp r1, #0
 *   @0x1f3bac beq 0x1f3bd8 <_Z24Variable_GetValue_DirectP12YYObjectBaseiiP6RValue+0x4c>
 *   @0x1f3bb0 ldr r4, [r0, #0x4]
 *   @0x1f3bb4 sub r12, r12, #99328
 *   @0x1f3bb8 sub r1, r12, #672
 *   @0x1f3bbc cmp r4, #0
 *   @0x1f3bc0 beq 0x1f3c08 <_Z24Variable_GetValue_DirectP12YYObjectBaseiiP6RValue+0x7c>
 *   @0x1f3bc4 add r1, r4, r1, lsl #4
 *   @0x1f3bc8 mov r0, r3
 *   @0x1f3bcc add sp, sp, #8
 *   @0x1f3bd0 pop {r4, lr}
 *   @0x1f3bd4 b 0xd13bc <_Z10GET_RValueP6RValueS0_i>
 *   @0x1f3bd8 mov r0, #0
 *   @0x1f3bdc add sp, sp, #8
 *   @0x1f3be0 pop {r4, pc}
 *   @0x1f3be4 ldr lr, [pc, #0x38]
 *   @0x1f3be8 mov r1, r2
 *   @0x1f3bec mov r2, r3
 *   @0x1f3bf0 ldr lr, [pc, lr]
 *   @0x1f3bf4 add r12, lr, r12, lsl #4
 *   @0x1f3bf8 ldr r3, [r12, #0x4]
 *   @0x1f3bfc blx r3
 *   @0x1f3c00 add sp, sp, #8
 *   @0x1f3c04 pop {r4, pc}
 *   @0x1f3c08 str r2, [sp, #0x4]
 *   @0x1f3c0c str r3, [sp]
 *   @0x1f3c10 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x1f3c14 ldr r3, [sp]
 *   @0x1f3c18 ldr r2, [sp, #0x4]
 *   @0x1f3c1c mov r1, r0
 *   @0x1f3c20 b 0x1f3bc8 <_Z24Variable_GetValue_DirectP12YYObjectBaseiiP6RValue+0x3c>
 *   @0x1f3c24 andseq r10, pc, r8, asr #32
 *
 * ══ §154/159 JS_SetupBuiltinAccessorFunction  0x23ff10  size 156  39 条（0x23ff10..0x23ffac）
 * @func 0x23ff10 0x23ffac  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYSetScriptRef(RValue*) / YYObjectBase::Add(char const*, void*, int) / YYObjectBase::Add(char const*, int, int)
 * 字段偏移 top8: 0x38×2 / 0xc×1 / 0x8×1 / 0x48×1 / 0x34×1 / 0x94×1 / 0x90×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23ff10 push {r4, r5, r6, r7, r8, lr}
 *   @0x23ff14 sub sp, sp, #16
 *   @0x23ff18 mov r8, r0
 *   @0x23ff1c mov r7, r1
 *   @0x23ff20 mov r0, sp
 *   @0x23ff24 mov r6, #0
 *   @0x23ff28 mvn r3, #-16777216
 *   @0x23ff2c mov r4, #0
 *   @0x23ff30 str r3, [sp, #0xc]
 *   @0x23ff34 mov r5, #0
 *   @0x23ff38 str r6, [sp, #0x8]
 *   @0x23ff3c strd r4, r5, [sp]
 *   @0x23ff40 bl 0xdc3b0 <_Z14YYSetScriptRefP6RValue>
 *   @0x23ff44 ldr r4, [sp]
 *   @0x23ff48 mov r2, r8
 *   @0x23ff4c ldr r1, [pc, #0x48]
 *   @0x23ff50 mov r3, r6
 *   @0x23ff54 mov r0, r4
 *   @0x23ff58 add r1, pc, r1
 *   @0x23ff5c bl 0x199b20 <_ZN12YYObjectBase3AddEPKcPvi>
 *   @0x23ff60 ldr r12, [pc, #0x38]
 *   @0x23ff64 ldr r0, [pc, #0x38]
 *   @0x23ff68 mov r2, r7
 *   @0x23ff6c ldr r1, [pc, #0x34]
 *   @0x23ff70 ldr r12, [pc, r12]
 *   @0x23ff74 ldr r0, [pc, r0]
 *   @0x23ff78 mov r3, r6
 *   @0x23ff7c str r0, [r4, #0x94]
 *   @0x23ff80 add r1, pc, r1
 *   @0x23ff84 mov r0, r4
 *   @0x23ff88 str r12, [r4, #0x90]
 *   @0x23ff8c bl 0x199960 <_ZN12YYObjectBase3AddEPKcii>
 *   @0x23ff90 mov r0, r4
 *   @0x23ff94 add sp, sp, #16
 *   @0x23ff98 pop {r4, r5, r6, r7, r8, pc}
 *   @0x23ff9c andseq r5, r1, r0, asr #9
 *   @0x23ffa0 andseq r1, r11, r12, lsr #11
 *   @0x23ffa4 andseq r1, r11, r12, lsr #11
 *   @0x23ffa8 andeq r0, pc, r12, ror #17
 *
 * ══ §155/159 JS_Array_Put  0x24861c  size 156  39 条（0x24861c..0x2486b8）
 * @func 0x24861c 0x2486b8  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66c4 / JSArrayPut(RValue*, RValue*, RValue*) / JS_DefineOwnProperty(YYObjectBase*, char const*, RValue*, bool)
 * 字段偏移 top8: 0x1×2 / 0x90×1 / 0x-10×1 / 0xc×1 / 0x1c×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x24861c ldr r3, [pc, #0x90]
 *   @0x248620 mov r12, r2
 *   @0x248624 push {r4, r5, r6, lr}
 *   @0x248628 ldr r3, [pc, r3]
 *   @0x24862c sub sp, sp, #32
 *   @0x248630 mov r5, r0
 *   @0x248634 ldr lr, [r3]
 *   @0x248638 mov r6, r1
 *   @0x24863c ldrb r4, [r12], #1
 *   @0x248640 cmp r4, #0
 *   @0x248644 add r3, lr, r4
 *   @0x248648 bne 0x24868c <_Z12JS_Array_PutP12YYObjectBaseP6RValuePKc+0x70>
 *   @0x24864c mov r0, r2
 *   @0x248650 bl 0xb66c4 <atol@plt>
 *   @0x248654 add r3, sp, #32
 *   @0x248658 mov r2, r6
 *   @0x24865c mov r1, sp
 *   @0x248660 str r5, [r3, #-0x10]!
 *   @0x248664 mov r12, #6
 *   @0x248668 str r4, [sp, #0xc]
 *   @0x24866c str r12, [sp, #0x1c]
 *   @0x248670 vmov s13, r0
 *   @0x248674 mov r0, r3
 *   @0x248678 vcvt.f64.s32 d7, s13
 *   @0x24867c vstr d7, [sp]
 *   @0x248680 bl 0x247c68 <_Z10JSArrayPutP6RValueS0_S0_>
 *   @0x248684 add sp, sp, #32
 *   @0x248688 pop {r4, r5, r6, pc}
 *   @0x24868c ldrb r3, [r3, #0x1]
 *   @0x248690 and r3, r3, #4
 *   @0x248694 ands r3, r3, #255
 *   @0x248698 bne 0x24863c <_Z12JS_Array_PutP12YYObjectBaseP6RValuePKc+0x20>
 *   @0x24869c mov r1, r2
 *   @0x2486a0 mov r0, r5
 *   @0x2486a4 mov r2, r6
 *   @0x2486a8 bl 0x248394 <_Z20JS_DefineOwnPropertyP12YYObjectBasePKcP6RValueb>
 *   @0x2486ac add sp, sp, #32
 *   @0x2486b0 pop {r4, r5, r6, pc}
 *   @0x2486b4 andseq r5, r10, r8, asr r3
 *
 * ══ §156/159 printbuf_memappend  0x280d20  size 156  39 条（0x280d20..0x280dbc）
 * @func 0x280d20 0x280dd0  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: printbuf_memappend+0x58 / 0xb65bc / 0xb6c28
 * 字段偏移 top8: 0x4×4 / 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x280d20 push {r3, r4, r5, r6, r7, lr}
 *   @0x280d24 mov r5, r2
 *   @0x280d28 ldr r3, [r0, #0x4]
 *   @0x280d2c mov r4, r0
 *   @0x280d30 ldr r2, [r0, #0x8]
 *   @0x280d34 mov r6, r1
 *   @0x280d38 rsb r0, r3, r2
 *   @0x280d3c cmp r0, r5
 *   @0x280d40 ble 0x280d78 <printbuf_memappend+0x58>
 *   @0x280d44 ldr r0, [r4]
 *   @0x280d48 mov r2, r5
 *   @0x280d4c add r0, r0, r3
 *   @0x280d50 mov r1, r6
 *   @0x280d54 bl 0xb65bc <memcpy@plt>
 *   @0x280d58 ldr r2, [r4, #0x4]
 *   @0x280d5c ldr r3, [r4]
 *   @0x280d60 mov r0, r5
 *   @0x280d64 add r5, r5, r2
 *   @0x280d68 mov r2, #0
 *   @0x280d6c str r5, [r4, #0x4]
 *   @0x280d70 strb r2, [r3, r5]
 *   @0x280d74 pop {r3, r4, r5, r6, r7, pc}
 *   @0x280d78 add r7, r3, r5
 *   @0x280d7c lsl r2, r2, #1
 *   @0x280d80 add r7, r7, #8
 *   @0x280d84 ldr r0, [r4]
 *   @0x280d88 cmp r7, r2
 *   @0x280d8c movlt r7, r2
 *   @0x280d90 mov r1, r7
 *   @0x280d94 bl 0xb6c28 <realloc@plt>
 *   @0x280d98 subs r2, r0, #0
 *   @0x280d9c beq 0x280db4 <printbuf_memappend+0x94>
 *   @0x280da0 ldr r3, [r4, #0x4]
 *   @0x280da4 mov r0, r2
 *   @0x280da8 str r7, [r4, #0x8]
 *   @0x280dac str r2, [r4]
 *   @0x280db0 b 0x280d48 <printbuf_memappend+0x28>
 *   @0x280db4 mvn r0, #0
 *   @0x280db8 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §157/159 IBuffer::ReadString  0xcde74  size 152  38 条（0xcde74..0xcdf0c）
 * @func 0xcde74 0xcdf0c  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FREE_RValue__Pre(RValue*) / YYStrDup(char const*)
 * 字段偏移 top8: 0x38×3 / 0x2c×2 / 0xc×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcde74 ldr r3, [r0]
 *   @0xcde78 mov r1, #11
 *   @0xcde7c push {r4, r5, r6, lr}
 *   @0xcde80 add r6, r0, #44
 *   @0xcde84 mov r4, r0
 *   @0xcde88 ldr r3, [r3, #0xc]
 *   @0xcde8c mov r2, r6
 *   @0xcde90 blx r3
 *   @0xcde94 ldr r3, [r4, #0x38]
 *   @0xcde98 bic r2, r3, #-16777216
 *   @0xcde9c cmp r2, #1
 *   @0xcdea0 movne r5, #0
 *   @0xcdea4 beq 0xcdee0 <_ZN7IBuffer10ReadStringEv+0x6c>
 *   @0xcdea8 sub r3, r3, #1
 *   @0xcdeac bic r3, r3, #-16777216
 *   @0xcdeb0 bic r3, r3, #3
 *   @0xcdeb4 cmp r3, #0
 *   @0xcdeb8 bne 0xcdec4 <_ZN7IBuffer10ReadStringEv+0x50>
 *   @0xcdebc mov r0, r6
 *   @0xcdec0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0xcdec4 mov r3, #0
 *   @0xcdec8 mov r2, #5
 *   @0xcdecc mov r0, r5
 *   @0xcded0 str r3, [r4, #0x34]
 *   @0xcded4 str r3, [r4, #0x2c]
 *   @0xcded8 str r2, [r4, #0x38]
 *   @0xcdedc pop {r4, r5, r6, pc}
 *   @0xcdee0 ldr r5, [r4, #0x2c]
 *   @0xcdee4 cmp r5, #0
 *   @0xcdee8 beq 0xcdea8 <_ZN7IBuffer10ReadStringEv+0x34>
 *   @0xcdeec ldr r0, [r5]
 *   @0xcdef0 cmp r0, #0
 *   @0xcdef4 moveq r5, r0
 *   @0xcdef8 beq 0xcdea8 <_ZN7IBuffer10ReadStringEv+0x34>
 *   @0xcdefc bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xcdf00 ldr r3, [r4, #0x38]
 *   @0xcdf04 mov r5, r0
 *   @0xcdf08 b 0xcdea8 <_ZN7IBuffer10ReadStringEv+0x34>
 *
 * ══ §158/159 F_DsMapClear  0xfed40  size 152  38 条（0xfed40..0xfedd8）
 * @func 0xfed40 0xfedd8  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DS_AutoMutex::~DS_AutoMutex()×2 / DS_AutoMutex::DS_AutoMutex() / YYGetInt32(RValue const*, int) / F_DsMapClear(RValue&, CInstance*, CInstance*, int, RValue*)+0x6c / CDS_Map::Clear() / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x18×1 / 0x58×1 / 0x48×1 / 0x4×1 / 0x2×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfed40 push {r4, r5, lr}
 *   @0xfed44 sub sp, sp, #12
 *   @0xfed48 add r4, sp, #4
 *   @0xfed4c ldr r5, [sp, #0x18]
 *   @0xfed50 mov r0, r4
 *   @0xfed54 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0xfed58 mov r1, #0
 *   @0xfed5c mov r0, r5
 *   @0xfed60 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfed64 cmp r0, #0
 *   @0xfed68 blt 0xfedac <_Z12F_DsMapClearR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0xfed6c ldr r3, [pc, #0x58]
 *   @0xfed70 ldr r3, [pc, r3]
 *   @0xfed74 ldr r3, [r3]
 *   @0xfed78 cmp r0, r3
 *   @0xfed7c bge 0xfedac <_Z12F_DsMapClearR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0xfed80 ldr r3, [pc, #0x48]
 *   @0xfed84 ldr r3, [pc, r3]
 *   @0xfed88 ldr r3, [r3, #0x4]
 *   @0xfed8c ldr r0, [r3, r0, lsl #2]
 *   @0xfed90 cmp r0, #0
 *   @0xfed94 beq 0xfedac <_Z12F_DsMapClearR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0xfed98 bl 0x20daf8 <_ZN7CDS_Map5ClearEv>
 *   @0xfed9c mov r0, r4
 *   @0xfeda0 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0xfeda4 add sp, sp, #12
 *   @0xfeda8 pop {r4, r5, pc}
 *   @0xfedac ldr r0, [pc, #0x20]
 *   @0xfedb0 mov r1, #0
 *   @0xfedb4 add r0, pc, r0
 *   @0xfedb8 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfedbc mov r0, r4
 *   @0xfedc0 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0xfedc4 add sp, sp, #12
 *   @0xfedc8 pop {r4, r5, pc}
 *   @0xfedcc eoreq lr, lr, r8, lsl #30
 *   @0xfedd0 .word 0x002eebb8
 *   @0xfedd4 eoreq r8, r3, r8, asr #28
 *
 * ══ §159/159 UnLinkCacheAchievement  0x15978c  size 152  38 条（0x15978c..0x159824）
 * @func 0x15978c 0x159824  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1597b8→0x484a98, 0x1597c0→0x484a9c, 0x1597e0→0x484aa4, 0x159800→0x484aa0
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1 / 0x78×1 / 0x54×1 / 0x50×1 / 0x34×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15978c ldr r2, [r0, #0x4]
 *   @0x159790 ldr r3, [pc, #0x78]
 *   @0x159794 cmp r2, #0
 *   @0x159798 add r3, pc, r3
 *   @0x15979c beq 0x1597e0 <_Z22UnLinkCacheAchievementP16SAchivementCache+0x54>
 *   @0x1597a0 ldr r1, [r0]
 *   @0x1597a4 str r1, [r2]
 *   @0x1597a8 ldr r1, [r0]
 *   @0x1597ac cmp r1, #0
 *   @0x1597b0 strne r2, [r1, #0x4]
 *   @0x1597b4 beq 0x159800 <_Z22UnLinkCacheAchievementP16SAchivementCache+0x74>
 *   @0x1597b8 ldr r2, [pc, #0x54]
 *   @0x1597bc mov r1, #1
 *   @0x1597c0 ldr r0, [pc, #0x50]
 *   @0x1597c4 ldr r2, [r3, r2]
 *   @0x1597c8 ldr r12, [r2]
 *   @0x1597cc sub r12, r12, #1
 *   @0x1597d0 str r12, [r2]
 *   @0x1597d4 ldr r3, [r3, r0]
 *   @0x1597d8 strb r1, [r3]
 *   @0x1597dc bx lr
 *   @0x1597e0 ldr r1, [pc, #0x34]
 *   @0x1597e4 ldr r0, [r0]
 *   @0x1597e8 ldr r12, [r3, r1]
 *   @0x1597ec mov r1, r0
 *   @0x1597f0 cmp r1, #0
 *   @0x1597f4 strne r2, [r1, #0x4]
 *   @0x1597f8 str r0, [r12]
 *   @0x1597fc bne 0x1597b8 <_Z22UnLinkCacheAchievementP16SAchivementCache+0x2c>
 *   @0x159800 ldr r1, [pc, #0x18]
 *   @0x159804 ldr r1, [r3, r1]
 *   @0x159808 str r2, [r1]
 *   @0x15980c b 0x1597b8 <_Z22UnLinkCacheAchievementP16SAchivementCache+0x2c>
 *   @0x159810 .word 0x002984b8
 *   @0x159814 .word 0xffffdf7c
 *   @0x159818 .word 0xffffdf78
 *   @0x15981c .word 0xffffdf74
 *   @0x159820 .word 0xffffdf80
 */
