/* cally 逆向卡：All_64 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 373 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/373 CPhysicsWorld::InvalidateFixture(b2Fixture*)  0x2383e0  size 88  22 条（0x2383e0..0x238438）
 * @func 0x2383e0 0x23844c  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsWorld::InvalidateFixture(b2Fixture*)+0x50 / CPhysicsWorld::InvalidateFixture(b2Fixture*)+0x1c
 * 字段偏移 top8: 0x4×3 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2383e0 ldr r3, [r0, #0x4]
 *   @0x2383e4 push {r4, r5}
 *   @0x2383e8 cmp r3, #0
 *   @0x2383ec ble 0x238430 <_ZN13CPhysicsWorld17InvalidateFixtureEP9b2Fixture+0x50>
 *   @0x2383f0 mov r2, #0
 *   @0x2383f4 mov r12, r2
 *   @0x2383f8 mov r5, r2
 *   @0x2383fc ldr r3, [r0]
 *   @0x238400 add r12, r12, #1
 *   @0x238404 add r3, r3, r2
 *   @0x238408 add r2, r2, #716
 *   @0x23840c ldr r4, [r3, #0x4]
 *   @0x238410 cmp r4, r1
 *   @0x238414 ldr r4, [r3, #0x8]
 *   @0x238418 streq r5, [r3, #0x4]
 *   @0x23841c cmp r4, r1
 *   @0x238420 streq r5, [r3, #0x8]
 *   @0x238424 ldr r3, [r0, #0x4]
 *   @0x238428 cmp r12, r3
 *   @0x23842c blt 0x2383fc <_ZN13CPhysicsWorld17InvalidateFixtureEP9b2Fixture+0x1c>
 *   @0x238430 pop {r4, r5}
 *   @0x238434 bx lr
 *
 * ══ §2/373 CPhysicsWorld::GetParticleDataGroup(int, IBuffer*, unsigned int)  0x23a5f0  size 88  22 条（0x23a5f0..0x23a648）
 * @func 0x23a5f0 0x23a648  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsWorld::GetParticleGroup(int) / b2ParticleGroup::GetBufferIndex() const / CPhysicsWorld::GetParticleData(IBuffer*, unsigned int, int, int)
 * 字段偏移 top8: 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23a5f0 push {r4, r5, r6, r7, r8, lr}
 *   @0x23a5f4 sub sp, sp, #8
 *   @0x23a5f8 mov r6, r2
 *   @0x23a5fc mov r5, r3
 *   @0x23a600 mov r7, r0
 *   @0x23a604 bl 0x239dc0 <_ZN13CPhysicsWorld16GetParticleGroupEi>
 *   @0x23a608 subs r4, r0, #0
 *   @0x23a60c beq 0x23a640 <_ZN13CPhysicsWorld20GetParticleDataGroupEiP7IBufferj+0x50>
 *   @0x23a610 bl 0x2d45fc <_ZNK15b2ParticleGroup14GetBufferIndexEv>
 *   @0x23a614 ldr r8, [r4, #0x8]
 *   @0x23a618 ldr lr, [r4, #0x4]
 *   @0x23a61c mov r1, r6
 *   @0x23a620 mov r2, r5
 *   @0x23a624 rsb lr, lr, r8
 *   @0x23a628 mov r12, r0
 *   @0x23a62c mov r0, r7
 *   @0x23a630 mov r3, r12
 *   @0x23a634 add r12, r12, lr
 *   @0x23a638 str r12, [sp]
 *   @0x23a63c bl 0x23a248 <_ZN13CPhysicsWorld15GetParticleDataEP7IBufferjii>
 *   @0x23a640 add sp, sp, #8
 *   @0x23a644 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §3/373 JS_isWhitespace(int)  0x2425ac  size 88  22 条（0x2425ac..0x242604）
 * @func 0x2425ac 0x242604  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JS_isWhitespace(int)+0x3c / JS_isWhitespace(int)+0x34
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2425ac cmp r0, #13
 *   @0x2425b0 ble 0x2425e8 <_Z15JS_isWhitespacei+0x3c>
 *   @0x2425b4 cmp r0, #160
 *   @0x2425b8 beq 0x2425e0 <_Z15JS_isWhitespacei+0x34>
 *   @0x2425bc bgt 0x2425d0 <_Z15JS_isWhitespacei+0x24>
 *   @0x2425c0 cmp r0, #32
 *   @0x2425c4 beq 0x2425e0 <_Z15JS_isWhitespacei+0x34>
 *   @0x2425c8 mov r0, #0
 *   @0x2425cc bx lr
 *   @0x2425d0 sub r0, r0, #8192
 *   @0x2425d4 sub r0, r0, #40
 *   @0x2425d8 cmp r0, #1
 *   @0x2425dc bhi 0x2425c8 <_Z15JS_isWhitespacei+0x1c>
 *   @0x2425e0 mov r0, #1
 *   @0x2425e4 bx lr
 *   @0x2425e8 cmp r0, #12
 *   @0x2425ec bge 0x2425e0 <_Z15JS_isWhitespacei+0x34>
 *   @0x2425f0 sub r0, r0, #9
 *   @0x2425f4 cmp r0, #1
 *   @0x2425f8 bls 0x2425e0 <_Z15JS_isWhitespacei+0x34>
 *   @0x2425fc mov r0, #0
 *   @0x242600 bx lr
 *
 * ══ §4/373 YearFromTime(double)  0x244b90  size 88  22 条（0x244b90..0x244be8）
 * @func 0x244b90 0x244be8  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: TimeFromYear(double)
 * 字段偏移 top8: 无
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x244b90 push {r3, r4, r5, lr}
 *   @0x244b94 vpush {d8, d9, d10}
 *   @0x244b98 vldr d8, [pc, #64]
 *   @0x244b9c vmov d9, r0, r1
 *   @0x244ba0 vmov r4, r5, d8
 *   @0x244ba4 vmov.f64 d10, #1.000000e+00
 *   @0x244ba8 b 0x244bb4 <_Z12YearFromTimed+0x24>
 *   @0x244bac vmov r4, r5, d8
 *   @0x244bb0 vadd.f64 d8, d8, d10
 *   @0x244bb4 vmov r0, r1, d8
 *   @0x244bb8 bl 0x244b68 <_Z12TimeFromYeard>
 *   @0x244bbc vmov d7, r0, r1
 *   @0x244bc0 vcmpe.f64 d7, d9
 *   @0x244bc4 vmrs APSR_nzcv, fpscr
 *   @0x244bc8 bgt 0x244bac <_Z12YearFromTimed+0x1c>
 *   @0x244bcc vpop {d8, d9, d10}
 *   @0x244bd0 mov r0, r4
 *   @0x244bd4 mov r1, r5
 *   @0x244bd8 pop {r3, r4, r5, pc}
 *   @0x244bdc nop
 *   @0x244be0 andeq r0, r0, r0
 *   @0x244be4 addsmi r12, lr, r0, lsl #16
 *
 * ══ §5/373 SMemoryArray::Quit()  0x27dd14  size 88  22 条（0x27dd14..0x27dd6c）
 * @func 0x27dd14 0x27dd6c  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb655c
 * 字段偏移 top8: 0x8×1 / 0x1c×1 / 0x34×1 / 0x18×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27dd14 push {r3, r4, r5, lr}
 *   @0x27dd18 mov r4, r0
 *   @0x27dd1c ldr r0, [r0, #0x8]
 *   @0x27dd20 bl 0xb655c <free@plt>
 *   @0x27dd24 ldr r1, [r4, #0x1c]
 *   @0x27dd28 ldr r3, [pc, #0x34]
 *   @0x27dd2c ldr r4, [r4, #0x18]
 *   @0x27dd30 ldr r3, [pc, r3]
 *   @0x27dd34 rsb r0, r1, r1, lsl #31
 *   @0x27dd38 ldr r2, [pc, #0x28]
 *   @0x27dd3c ldr r5, [r3]
 *   @0x27dd40 lsl r0, r0, #1
 *   @0x27dd44 ldr r2, [pc, r2]
 *   @0x27dd48 add r5, r0, r5
 *   @0x27dd4c ldr r12, [r2]
 *   @0x27dd50 mls r1, r4, r1, r5
 *   @0x27dd54 add r0, r0, r12
 *   @0x27dd58 str r0, [r2]
 *   @0x27dd5c str r1, [r3]
 *   @0x27dd60 pop {r3, r4, r5, pc}
 *   @0x27dd64 andseq r2, r7, r8, lsr #13
 *   @0x27dd68 andseq r2, r7, r0, lsr #13
 *
 * ══ §6/373 spEventData_create  0x285b94  size 88  22 条（0x285b94..0x285bec）
 * @func 0x285b94 0x285bec  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _calloc / 0xb6538 / _malloc / 0xb65a4
 * 字段偏移 top8: 0x44×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x285b94 push {r4, r5, r6, lr}
 *   @0x285b98 mov r3, #36
 *   @0x285b9c ldr r6, [pc, #0x44]
 *   @0x285ba0 mov r5, r0
 *   @0x285ba4 mov r1, #16
 *   @0x285ba8 mov r0, #1
 *   @0x285bac add r6, pc, r6
 *   @0x285bb0 mov r2, r6
 *   @0x285bb4 bl 0x285c4c <_calloc>
 *   @0x285bb8 mov r4, r0
 *   @0x285bbc mov r0, r5
 *   @0x285bc0 bl 0xb6538 <strlen@plt>
 *   @0x285bc4 mov r1, r6
 *   @0x285bc8 mov r2, #37
 *   @0x285bcc add r0, r0, #1
 *   @0x285bd0 bl 0x285c10 <_malloc>
 *   @0x285bd4 mov r1, r5
 *   @0x285bd8 str r0, [r4]
 *   @0x285bdc bl 0xb65a4 <strcpy@plt>
 *   @0x285be0 mov r0, r4
 *   @0x285be4 pop {r4, r5, r6, pc}
 *   @0x285be8 andeq r1, sp, r0, lsr #24
 *
 * ══ §7/373 Json_dispose  0x2872c8  size 88  22 条（0x2872c8..0x287320）
 * @func 0x2872c8 0x287320  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _free×3 / Json_dispose
 * 字段偏移 top8: 0x4×1 / 0x10×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2872c8 push {r3, r4, r5, lr}
 *   @0x2872cc subs r4, r0, #0
 *   @0x2872d0 popeq {r3, r4, r5, pc}
 *   @0x2872d4 ldr r0, [r4, #0x4]
 *   @0x2872d8 ldr r5, [r4]
 *   @0x2872dc cmp r0, #0
 *   @0x2872e0 beq 0x2872e8 <Json_dispose+0x20>
 *   @0x2872e4 bl 0x2872c8 <Json_dispose>
 *   @0x2872e8 ldr r0, [r4, #0x10]
 *   @0x2872ec cmp r0, #0
 *   @0x2872f0 beq 0x2872f8 <Json_dispose+0x30>
 *   @0x2872f4 bl 0x285c80 <_free>
 *   @0x2872f8 ldr r0, [r4, #0x1c]
 *   @0x2872fc cmp r0, #0
 *   @0x287300 beq 0x287308 <Json_dispose+0x40>
 *   @0x287304 bl 0x285c80 <_free>
 *   @0x287308 mov r0, r4
 *   @0x28730c mov r4, r5
 *   @0x287310 bl 0x285c80 <_free>
 *   @0x287314 cmp r5, #0
 *   @0x287318 bne 0x2872d4 <Json_dispose+0xc>
 *   @0x28731c pop {r3, r4, r5, pc}
 *
 * ══ §8/373 spPathConstraintData_create  0x288edc  size 88  22 条（0x288edc..0x288f34）
 * @func 0x288edc 0x288f34  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _calloc / 0xb6538 / _malloc / 0xb65a4
 * 字段偏移 top8: 0x44×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x288edc push {r4, r5, r6, lr}
 *   @0x288ee0 mov r3, #36
 *   @0x288ee4 ldr r6, [pc, #0x44]
 *   @0x288ee8 mov r5, r0
 *   @0x288eec mov r1, #48
 *   @0x288ef0 mov r0, #1
 *   @0x288ef4 add r6, pc, r6
 *   @0x288ef8 mov r2, r6
 *   @0x288efc bl 0x285c4c <_calloc>
 *   @0x288f00 mov r4, r0
 *   @0x288f04 mov r0, r5
 *   @0x288f08 bl 0xb6538 <strlen@plt>
 *   @0x288f0c mov r1, r6
 *   @0x288f10 mov r2, #37
 *   @0x288f14 add r0, r0, #1
 *   @0x288f18 bl 0x285c10 <_malloc>
 *   @0x288f1c mov r1, r5
 *   @0x288f20 str r0, [r4]
 *   @0x288f24 bl 0xb65a4 <strcpy@plt>
 *   @0x288f28 mov r0, r4
 *   @0x288f2c pop {r4, r5, r6, pc}
 *   @0x288f30 andeq lr, r12, r0, asr #21
 *
 * ══ §9/373 spSkeletonBounds_aabbContainsPoint  0x28aaa0  size 88  22 条（0x28aaa0..0x28aaf8）
 * @func 0x28aaa0 0x28aaf8  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28aaa0 vmov s15, r1
 *   @0x28aaa4 vldr s14, [r0, #12]
 *   @0x28aaa8 vmov s13, r2
 *   @0x28aaac vcmpe.f32 s14, s15
 *   @0x28aab0 vmrs APSR_nzcv, fpscr
 *   @0x28aab4 bhi 0x28aaf0 <spSkeletonBounds_aabbContainsPoint+0x50>
 *   @0x28aab8 vldr s14, [r0, #20]
 *   @0x28aabc vcmpe.f32 s15, s14
 *   @0x28aac0 vmrs APSR_nzcv, fpscr
 *   @0x28aac4 bhi 0x28aaf0 <spSkeletonBounds_aabbContainsPoint+0x50>
 *   @0x28aac8 vldr s15, [r0, #16]
 *   @0x28aacc vcmpe.f32 s15, s13
 *   @0x28aad0 vmrs APSR_nzcv, fpscr
 *   @0x28aad4 bhi 0x28aaf0 <spSkeletonBounds_aabbContainsPoint+0x50>
 *   @0x28aad8 vldr s15, [r0, #24]
 *   @0x28aadc vcmpe.f32 s13, s15
 *   @0x28aae0 vmrs APSR_nzcv, fpscr
 *   @0x28aae4 movhi r0, #0
 *   @0x28aae8 movls r0, #1
 *   @0x28aaec bx lr
 *   @0x28aaf0 mov r0, #0
 *   @0x28aaf4 bx lr
 *
 * ══ §10/373 spSkeletonData_findBoneIndex  0x28b018  size 88  22 条（0x28b018..0x28b070）
 * @func 0x28b018 0x28b070  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spSkeletonData_findBoneIndex+0x50 / 0xb6574
 * 字段偏移 top8: 0x4×2 / 0x10×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28b018 push {r3, r4, r5, r6, r7, lr}
 *   @0x28b01c mov r7, r1
 *   @0x28b020 ldr r6, [r0, #0x10]
 *   @0x28b024 cmp r6, #0
 *   @0x28b028 ble 0x28b068 <spSkeletonData_findBoneIndex+0x50>
 *   @0x28b02c ldr r5, [r0, #0x14]
 *   @0x28b030 mov r4, #0
 *   @0x28b034 sub r5, r5, #4
 *   @0x28b038 b 0x28b048 <spSkeletonData_findBoneIndex+0x30>
 *   @0x28b03c add r4, r4, #1
 *   @0x28b040 cmp r4, r6
 *   @0x28b044 beq 0x28b068 <spSkeletonData_findBoneIndex+0x50>
 *   @0x28b048 ldr r3, [r5, #0x4]!
 *   @0x28b04c mov r1, r7
 *   @0x28b050 ldr r0, [r3, #0x4]
 *   @0x28b054 bl 0xb6574 <strcmp@plt>
 *   @0x28b058 cmp r0, #0
 *   @0x28b05c bne 0x28b03c <spSkeletonData_findBoneIndex+0x24>
 *   @0x28b060 mov r0, r4
 *   @0x28b064 pop {r3, r4, r5, r6, r7, pc}
 *   @0x28b068 mvn r0, #0
 *   @0x28b06c pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §11/373 spSkeletonData_findSlotIndex  0x28b0cc  size 88  22 条（0x28b0cc..0x28b124）
 * @func 0x28b0cc 0x28b124  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spSkeletonData_findSlotIndex+0x50 / 0xb6574
 * 字段偏移 top8: 0x4×2 / 0x18×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28b0cc push {r3, r4, r5, r6, r7, lr}
 *   @0x28b0d0 mov r7, r1
 *   @0x28b0d4 ldr r6, [r0, #0x18]
 *   @0x28b0d8 cmp r6, #0
 *   @0x28b0dc ble 0x28b11c <spSkeletonData_findSlotIndex+0x50>
 *   @0x28b0e0 ldr r5, [r0, #0x1c]
 *   @0x28b0e4 mov r4, #0
 *   @0x28b0e8 sub r5, r5, #4
 *   @0x28b0ec b 0x28b0fc <spSkeletonData_findSlotIndex+0x30>
 *   @0x28b0f0 add r4, r4, #1
 *   @0x28b0f4 cmp r4, r6
 *   @0x28b0f8 beq 0x28b11c <spSkeletonData_findSlotIndex+0x50>
 *   @0x28b0fc ldr r3, [r5, #0x4]!
 *   @0x28b100 mov r1, r7
 *   @0x28b104 ldr r0, [r3, #0x4]
 *   @0x28b108 bl 0xb6574 <strcmp@plt>
 *   @0x28b10c cmp r0, #0
 *   @0x28b110 bne 0x28b0f0 <spSkeletonData_findSlotIndex+0x24>
 *   @0x28b114 mov r0, r4
 *   @0x28b118 pop {r3, r4, r5, r6, r7, pc}
 *   @0x28b11c mvn r0, #0
 *   @0x28b120 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §12/373 spSkin_create  0x28ec44  size 88  22 条（0x28ec44..0x28ec9c）
 * @func 0x28ec44 0x28ec9c  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _calloc / 0xb6538 / _malloc / 0xb65a4
 * 字段偏移 top8: 0x44×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28ec44 push {r4, r5, r6, lr}
 *   @0x28ec48 mov r3, #52
 *   @0x28ec4c ldr r6, [pc, #0x44]
 *   @0x28ec50 mov r5, r0
 *   @0x28ec54 mov r1, #8
 *   @0x28ec58 mov r0, #1
 *   @0x28ec5c add r6, pc, r6
 *   @0x28ec60 mov r2, r6
 *   @0x28ec64 bl 0x285c4c <_calloc>
 *   @0x28ec68 mov r4, r0
 *   @0x28ec6c mov r0, r5
 *   @0x28ec70 bl 0xb6538 <strlen@plt>
 *   @0x28ec74 mov r1, r6
 *   @0x28ec78 mov r2, #53
 *   @0x28ec7c add r0, r0, #1
 *   @0x28ec80 bl 0x285c10 <_malloc>
 *   @0x28ec84 mov r1, r5
 *   @0x28ec88 str r0, [r4]
 *   @0x28ec8c bl 0xb65a4 <strcpy@plt>
 *   @0x28ec90 mov r0, r4
 *   @0x28ec94 pop {r4, r5, r6, pc}
 *   @0x28ec98 andeq r9, r12, r12, lsr #6
 *
 * ══ §13/373 spTransformConstraintData_create  0x28f5b0  size 88  22 条（0x28f5b0..0x28f608）
 * @func 0x28f5b0 0x28f608  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _calloc / 0xb6538 / _malloc / 0xb65a4
 * 字段偏移 top8: 0x44×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28f5b0 push {r4, r5, r6, lr}
 *   @0x28f5b4 mov r3, #36
 *   @0x28f5b8 ldr r6, [pc, #0x44]
 *   @0x28f5bc mov r5, r0
 *   @0x28f5c0 mov r1, #56
 *   @0x28f5c4 mov r0, #1
 *   @0x28f5c8 add r6, pc, r6
 *   @0x28f5cc mov r2, r6
 *   @0x28f5d0 bl 0x285c4c <_calloc>
 *   @0x28f5d4 mov r4, r0
 *   @0x28f5d8 mov r0, r5
 *   @0x28f5dc bl 0xb6538 <strlen@plt>
 *   @0x28f5e0 mov r1, r6
 *   @0x28f5e4 mov r2, #37
 *   @0x28f5e8 add r0, r0, #1
 *   @0x28f5ec bl 0x285c10 <_malloc>
 *   @0x28f5f0 mov r1, r5
 *   @0x28f5f4 str r0, [r4]
 *   @0x28f5f8 bl 0xb65a4 <strcpy@plt>
 *   @0x28f5fc mov r0, r4
 *   @0x28f600 pop {r4, r5, r6, pc}
 *   @0x28f604 andeq r8, r12, r4, lsr #21
 *
 * ══ §14/373 Java_com_yoyogames_runner_RunnerJNILib_IAPProductDetailsReceived  0x294ad8  size 88  22 条（0x294ad8..0x294b30）
 * @func 0x294ad8 0x294b44  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: setJNIEnv / YYIAPProductDetailsReceived(char const*)
 * 字段偏移 top8: 0x2a4×1 / 0x2a8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x294ad8 push {r4, r5, r6, lr}
 *   @0x294adc mov r4, r0
 *   @0x294ae0 mov r5, r2
 *   @0x294ae4 bl 0x290614 <setJNIEnv>
 *   @0x294ae8 ldr r3, [r4]
 *   @0x294aec mov r1, r5
 *   @0x294af0 mov r2, #0
 *   @0x294af4 mov r0, r4
 *   @0x294af8 ldr r3, [r3, #0x2a4]
 *   @0x294afc blx r3
 *   @0x294b00 mov r6, r0
 *   @0x294b04 bl 0x1553e8 <_Z27YYIAPProductDetailsReceivedPKc>
 *   @0x294b08 cmp r6, #0
 *   @0x294b0c cmpne r5, #0
 *   @0x294b10 popeq {r4, r5, r6, pc}
 *   @0x294b14 ldr r3, [r4]
 *   @0x294b18 mov r1, r5
 *   @0x294b1c mov r2, r6
 *   @0x294b20 mov r0, r4
 *   @0x294b24 ldr r3, [r3, #0x2a8]
 *   @0x294b28 blx r3
 *   @0x294b2c pop {r4, r5, r6, pc}
 *
 * ══ §15/373 Java_com_yoyogames_runner_RunnerJNILib_IAPProductPurchaseEvent  0x294b30  size 88  22 条（0x294b30..0x294b88）
 * @func 0x294b30 0x294b9c  size 108  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: setJNIEnv / YYIAPPurchaseEvent(char const*)
 * 字段偏移 top8: 0x2a4×1 / 0x2a8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x294b30 push {r4, r5, r6, lr}
 *   @0x294b34 mov r4, r0
 *   @0x294b38 mov r5, r2
 *   @0x294b3c bl 0x290614 <setJNIEnv>
 *   @0x294b40 ldr r3, [r4]
 *   @0x294b44 mov r1, r5
 *   @0x294b48 mov r2, #0
 *   @0x294b4c mov r0, r4
 *   @0x294b50 ldr r3, [r3, #0x2a4]
 *   @0x294b54 blx r3
 *   @0x294b58 mov r6, r0
 *   @0x294b5c bl 0x1554ac <_Z18YYIAPPurchaseEventPKc>
 *   @0x294b60 cmp r6, #0
 *   @0x294b64 cmpne r5, #0
 *   @0x294b68 popeq {r4, r5, r6, pc}
 *   @0x294b6c ldr r3, [r4]
 *   @0x294b70 mov r1, r5
 *   @0x294b74 mov r2, r6
 *   @0x294b78 mov r0, r4
 *   @0x294b7c ldr r3, [r3, #0x2a8]
 *   @0x294b80 blx r3
 *   @0x294b84 pop {r4, r5, r6, pc}
 *
 * ══ §16/373 Java_com_yoyogames_runner_RunnerJNILib_IAPConsumeEvent  0x294b88  size 88  22 条（0x294b88..0x294be0）
 * @func 0x294b88 0x294be0  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: setJNIEnv / YYIAPConsumeEvent(char const*)
 * 字段偏移 top8: 0x2a4×1 / 0x2a8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x294b88 push {r4, r5, r6, lr}
 *   @0x294b8c mov r4, r0
 *   @0x294b90 mov r5, r2
 *   @0x294b94 bl 0x290614 <setJNIEnv>
 *   @0x294b98 ldr r3, [r4]
 *   @0x294b9c mov r1, r5
 *   @0x294ba0 mov r2, #0
 *   @0x294ba4 mov r0, r4
 *   @0x294ba8 ldr r3, [r3, #0x2a4]
 *   @0x294bac blx r3
 *   @0x294bb0 mov r6, r0
 *   @0x294bb4 bl 0x15556c <_Z17YYIAPConsumeEventPKc>
 *   @0x294bb8 cmp r6, #0
 *   @0x294bbc cmpne r5, #0
 *   @0x294bc0 popeq {r4, r5, r6, pc}
 *   @0x294bc4 ldr r3, [r4]
 *   @0x294bc8 mov r1, r5
 *   @0x294bcc mov r2, r6
 *   @0x294bd0 mov r0, r4
 *   @0x294bd4 ldr r3, [r3, #0x2a8]
 *   @0x294bd8 blx r3
 *   @0x294bdc pop {r4, r5, r6, pc}
 *
 * ══ §17/373 yySocket::CreateSocket()  0x295fec  size 88  22 条（0x295fec..0x296044）
 * @func 0x295fec 0x296044  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6da8×2
 * 字段偏移 top8: 0x8×1 / 0xc4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x295fec ldr r3, [r0, #0x8]
 *   @0x295ff0 push {r4, lr}
 *   @0x295ff4 cmp r3, #1
 *   @0x295ff8 mov r4, r0
 *   @0x295ffc ldrb r0, [r0, #0xc4]
 *   @0x296000 beq 0x296024 <_ZN8yySocket12CreateSocketEv+0x38>
 *   @0x296004 cmp r0, #0
 *   @0x296008 mov r1, #1
 *   @0x29600c mov r2, #6
 *   @0x296010 moveq r0, #2
 *   @0x296014 movne r0, #10
 *   @0x296018 bl 0xb6da8 <socket@plt>
 *   @0x29601c str r0, [r4]
 *   @0x296020 pop {r4, pc}
 *   @0x296024 cmp r0, #0
 *   @0x296028 mov r1, #2
 *   @0x29602c mov r2, #17
 *   @0x296030 moveq r0, r1
 *   @0x296034 movne r0, #10
 *   @0x296038 bl 0xb6da8 <socket@plt>
 *   @0x29603c str r0, [r4]
 *   @0x296040 pop {r4, pc}
 *
 * ══ §18/373 png_warning  0x2a6474  size 88  22 条（0x2a6474..0x2a64cc）
 * @func 0x2a6474 0x2a64cc  size 88  22 条
 * 部分覆盖: 本节 22/41 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb68a4
 * 字段偏移 top8: 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6474 push {r4, lr}
 *   @0x2a6478 cbz r0, 0x2a6490 <png_warning+0x1c>
 *   @0x2a647c cmp r3, #0x23
 *   @0x2a6480 movs r3, #0x1
 *   @0x2a6484 cmp r1, #0x20
 *   @0x2a6488 adds r3, #0x1
 *   @0x2a648c bne 0x2a6482 <png_warning+0xe>
 *   @0x2a6490 mov r3, r0
 *   @0x2a6494 add r2, r3
 *   @0x2a6498 ldr r1, [r1]
 *   @0x2a649c stmdbmi r10, {r3, r5, r7, r10}
 *   @0x2a64a0 mov r0, r4
 *   @0x2a64a4 blx 0xb68a4 <fprintf@plt>
 *   @0x2a64a8 mov r1, r4
 *   @0x2a64ac pop.w {r4, lr}
 *   @0x2a64b0 b.w 0x31baec <__udivdi3+0x454>
 *   @0x2a64b4 movs r3, #0x0
 *   @0x2a64b8 .word 0x2c004108
 *   @0x2a64bc beq 0x2a6492 <png_warning+0x1e>
 *   @0x2a64c0 blx r4
 *   @0x2a64c4 add r7, sp, #0x2c8
 *   @0x2a64c8 str r0, [r7, #0x20]
 *
 * ══ §19/373 png_set_gamma  0x2a8738  size 88  22 条（0x2a8738..0x2a8790）
 * @func 0x2a8738 0x2a8790  size 88  22 条
 * 部分覆盖: 本节 22/34 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x268×1 / 0x264×1
 * VFP 指令 11 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a8738 vmov d6, r2, r3
 *   @0x2a873c vldr d5, [sp]
 *   @0x2a8740 cbz r0, 0x2a8784 <png_set_gamma+0x4c>
 *   @0x2a8744 vldr d7, [pc]
 *   @0x2a8748 vmov.32 r4, d6[0]
 *   @0x2a874c vmov.f64 d7, #2.625000e+00
 *   @0x2a8750 vcmpe.f64 d7, d7
 *   @0x2a8754 vsqrt.f64 d23, d4
 *   @0x2a8758 .word 0xdc05fa10
 *   @0x2a875c ldrb.w r3, [r0, #0x1ea]
 *   @0x2a8760 lsls r2, r3, #0x1d
 *   @0x2a8764 cmp r3, #0x3
 *   @0x2a8768 ldr.w r3, [r0, #0x134]
 *   @0x2a876c orr r3, r3, #0x2000
 *   @0x2a8770 str.w r3, [r0, #0x134]
 *   @0x2a8774 vcvt.f32.f64 s10, d5
 *   @0x2a8778 vcvt.f32.f64 s12, d6
 *   @0x2a877c vstr s10, [r0, #544]
 *   @0x2a8780 vstr s12, [r0, #548]
 *   @0x2a8784 bx lr
 *   @0x2a8788 ldr r1, [sp, #0x268]
 *   @0x2a878c ldr r1, [sp, #0x264]
 *
 * ══ §20/373 png_set_write_fn  0x2afc18  size 88  22 条（0x2afc18..0x2afc70）
 * @func 0x2afc18 0x2afc70  size 88  22 条
 * 部分覆盖: 本节 22/43 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_warning
 * 字段偏移 top8: 0x38×1 / 0x30×1 / 0x24×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2afc18 push {r4, lr}
 *   @0x2afc1c cbz r0, 0x2afc5e <png_set_write_fn+0x46>
 *   @0x2afc20 ldmdblt r2, {r3, r4, r8, r12}
 *   @0x2afc24 ldr r2, [pc, #0x38]
 *   @0x2afc28 ldr r2, [r2]
 *   @0x2afc2c ldmdblt r3, {r4, r8, sp}
 *   @0x2afc30 ldr r3, [pc, #0x30]
 *   @0x2afc34 ldr r3, [r3]
 *   @0x2afc38 .word 0xf8d43210
 *   @0x2afc3c cmnlt r3, r4, lsl r1
 *   @0x2afc40 ldr r1, [pc, #0x24]
 *   @0x2afc44 movs r3, #0x0
 *   @0x2afc48 ldrbtmi r3, [r9], #-276
 *   @0x2afc4c bl 0x2a6474 <png_warning>
 *   @0x2afc50 ldr r1, [pc, #0x18]
 *   @0x2afc54 add r1, pc
 *   @0x2afc58 .word 0xf7f64010
 *   @0x2afc5c ldclt p12, c11, [r0, #-44]
 *   @0x2afc60 subs r6, r7, #0x1
 *   @0x2afc64 subs r6, r6, #0x1
 *   @0x2afc68 b 0x2b00c0 <png_write_end+0x94>
 *   @0x2afc6c b 0x2b0120 <png_write_end+0xf4>
 *
 * ══ §21/373 b2CircleShape::ComputeAABB(b2AABB*, b2Transform const&, int) const  0x2c4da4  size 88  22 条（0x2c4da4..0x2c4dfc）
 * @func 0x2c4da4 0x2c4dfc  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 21 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c4da4 vldr s11, [r2, #12]
 *   @0x2c4da8 vldr s9, [r0, #16]
 *   @0x2c4dac vldr s10, [r2, #8]
 *   @0x2c4db0 vmul.f32 s13, s11, s9
 *   @0x2c4db4 vldr s12, [r0, #12]
 *   @0x2c4db8 vldr s8, [r2]
 *   @0x2c4dbc vldr s7, [r2, #4]
 *   @0x2c4dc0 vldr s15, [r0, #8]
 *   @0x2c4dc4 vmul.f32 s14, s10, s9
 *   @0x2c4dc8 vmla.f32 s13, s12, s10
 *   @0x2c4dcc vnmls.f32 s14, s11, s12
 *   @0x2c4dd0 vadd.f32 s13, s13, s7
 *   @0x2c4dd4 vadd.f32 s14, s14, s8
 *   @0x2c4dd8 vsub.f32 s11, s13, s15
 *   @0x2c4ddc vsub.f32 s12, s14, s15
 *   @0x2c4de0 vstr s11, [r1, #4]
 *   @0x2c4de4 vadd.f32 s14, s15, s14
 *   @0x2c4de8 vstr s12, [r1]
 *   @0x2c4dec vadd.f32 s13, s15, s13
 *   @0x2c4df0 vstr s14, [r1, #8]
 *   @0x2c4df4 vstr s13, [r1, #12]
 *   @0x2c4df8 bx lr
 *
 * ══ §22/373 b2Mat33::Solve22(b2Vec2 const&) const  0x2c68e8  size 88  22 条（0x2c68e8..0x2c6940）
 * @func 0x2c68e8 0x2c6940  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 20 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c68e8 vldr s14, [r1, #12]
 *   @0x2c68ec vldr s13, [r1, #4]
 *   @0x2c68f0 vmul.f32 s15, s14, s13
 *   @0x2c68f4 vldr s9, [r1]
 *   @0x2c68f8 vldr s12, [r1, #16]
 *   @0x2c68fc vldr s10, [r2, #4]
 *   @0x2c6900 mov r3, r0
 *   @0x2c6904 vnmls.f32 s15, s9, s12
 *   @0x2c6908 vcmp.f32 s15, #0
 *   @0x2c690c vmrs APSR_nzcv, fpscr
 *   @0x2c6910 vmovne.f32 s11, #1.000000e+00
 *   @0x2c6914 vdivne.f32 s15, s11, s15
 *   @0x2c6918 vldr s11, [r2]
 *   @0x2c691c vmul.f32 s14, s10, s14
 *   @0x2c6920 vmul.f32 s13, s13, s11
 *   @0x2c6924 vnmls.f32 s14, s11, s12
 *   @0x2c6928 vnmls.f32 s13, s9, s10
 *   @0x2c692c vmul.f32 s13, s13, s15
 *   @0x2c6930 vmul.f32 s15, s14, s15
 *   @0x2c6934 vstr s13, [r3, #4]
 *   @0x2c6938 vstr s15, [r3]
 *   @0x2c693c bx lr
 *
 * ══ §23/373 FT_DivFix  0x2e4eb6  size 88  22 条（0x2e4eb6..0x2e4f0e）
 * @func 0x2e4eb6 0x2e4f0e  size 88  22 条
 * 部分覆盖: 本节 22/42 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __udivsi3
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e4eb6 subs r3, r0, #0x0
 *   @0x2e4eba push {r4, lr}
 *   @0x2e4ebe rsblt r3, r3, #0
 *   @0x2e4ec2 strhs r3, [r1], #-1279
 *   @0x2e4ec6 cmp r1, #0x0
 *   @0x2e4eca rsblt r2, r1, #0
 *   @0x2e4ece cbz r2, 0x2e4f02 <FT_DivFix+0x4c>
 *   @0x2e4ed2 lsls r0, r3, #0x10
 *   @0x2e4ed6 mvnslo r4, pc, ror r1
 *   @0x2e4eda cmp r1, r3
 *   @0x2e4ede movwle r0, #0x4152
 *   @0x2e4ee2 add r0, r1
 *   @0x2e4ee6 blx 0x318c48 <__udivsi3>
 *   @0x2e4eea b 0x2e4f06 <FT_DivFix+0x50>
 *   @0x2e4eee ite lo
 *   @0x2e4ef2 movhs r0, #0x1
 *   @0x2e4ef6 addsmi r4, r0, #19
 *   @0x2e4efa bhs 0x2e4f02 <FT_DivFix+0x4c>
 *   @0x2e4efe mul r1, pc, lr
 *   @0x2e4f02 mvn r0, #0x80000000
 *   @0x2e4f06 adds r4, #0x1
 *   @0x2e4f0a rsbeq r0, r0, #0
 *
 * ══ §24/373 FT_Get_Name_Index  0x2e5aa0  size 88  22 条（0x2e5aa0..0x2e5af8）
 * @func 0x2e5aa0 0x2e5af8  size 88  22 条
 * 部分覆盖: 本节 22/43 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2e9c78+0x4064
 * 字段偏移 top8: 0x8×1 / 0x28×1 / 0x4×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e5aa0 push {r3, r4, r5, lr}
 *   @0x2e5aa4 mov r4, r0
 *   @0x2e5aa8 movs r0, #0x0
 *   @0x2e5aac ldr r3, [r0, #0x8]
 *   @0x2e5ab0 bpl 0x2e5aa8 <FT_Get_Name_Index+0x8>
 *   @0x2e5ab4 beq 0x2e5aa8 <FT_Get_Name_Index+0x8>
 *   @0x2e5ab8 bvs 0xfe9b1cc0 <b2_toiTime+0xfffffffffe25881c>
 *   @0x2e5abc adds r2, r3, #0x2
 *   @0x2e5ac0 cbnz r3, 0x2e5ae4 <FT_Get_Name_Index+0x44>
 *   @0x2e5ac4 ldr r2, [r0]
 *   @0x2e5ac8 cbz r2, 0x2e5ad2 <FT_Get_Name_Index+0x32>
 *   @0x2e5acc add r1, pc
 *   @0x2e5ad0 mov r3, r0
 *   @0x2e5ad4 blhs 0x2edcdc <FT_Done_Memory+0x4068>
 *   @0x2e5ad8 ite ne
 *   @0x2e5adc mvneq r1, #0x1
 *   @0x2e5ae0 str r1, [r2, #0x28]
 *   @0x2e5ae4 ldr r3, [r3, #0x4]
 *   @0x2e5ae8 beq 0x2e5aa8 <FT_Get_Name_Index+0x8>
 *   @0x2e5aec mov r1, r5
 *   @0x2e5af0 pop {r3, r4, r5, pc}
 *   @0x2e5af4 ldrh r0, [r4, #0x20]
 *
 * ══ §25/373 FT_Outline_Get_CBox  0x2e63cc  size 88  22 条（0x2e63cc..0x2e6424）
 * @func 0x2e63cc 0x2e6424  size 88  22 条
 * 部分覆盖: 本节 22/42 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x3e7804 / FT_Outline_Get_CBox+0x50
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e63cc push {r4, r5, r6, r7, lr}
 *   @0x2e63d0 cbz r1, 0x2e6422 <FT_Outline_Get_CBox+0x56>
 *   @0x2e63d4 cbz r3, 0x2e6416 <FT_Outline_Get_CBox+0x4a>
 *   @0x2e63d8 sxth r3, r3
 *   @0x2e63dc bl 0x3e7804 <error_g0017+0x404a8>
 *   @0x2e63e0 ldm r4, {r0, r1, r6, r7, r8, r9, r10}
 *   @0x2e63e4 ldrmi r0, [r3], -r5
 *   @0x2e63e8 mov r4, r0
 *   @0x2e63ec add.w r6, r5, #0x8
 *   @0x2e63f0 bls 0x2e641c <FT_Outline_Get_CBox+0x50>
 *   @0x2e63f4 adcmi r5, r8, #8, #24
 *   @0x2e63f8 it ge
 *   @0x2e63fc cmp r4, r5
 *   @0x2e6400 movlt r4, r5
 *   @0x2e6404 adcmi r5, r10, #4, #24
 *   @0x2e6408 it ge
 *   @0x2e640c cmp r3, r5
 *   @0x2e6410 movlt r3, r5
 *   @0x2e6414 b 0x2e63ea <FT_Outline_Get_CBox+0x1e>
 *   @0x2e6418 mov r2, r3
 *   @0x2e641c stm.w r1, {r0, r2, r4}
 *   @0x2e6420 str r3, [r1, #0xc]
 *
 * ══ §26/373 FT_Stream_ReadULong  0x2e6dc4  size 88  22 条（0x2e6dc4..0x2e6e1c）
 * @func 0x2e6dc4 0x2e6e1c  size 88  22 条
 * 部分覆盖: 本节 22/43 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×2 / 0x4×1 / 0x14×1 / 0x1×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e6dc4 push {r0, r1, r2, r4, r5, r6, r7, lr}
 *   @0x2e6dc8 str r3, [r1]
 *   @0x2e6dcc ldr r3, [r0, #0x8]
 *   @0x2e6dd0 ldr r2, [r0, #0x4]
 *   @0x2e6dd4 cmp r1, r2
 *   @0x2e6dd8 ldr r7, [r0, #0x14]
 *   @0x2e6ddc add r6, sp, #0x4
 *   @0x2e6de0 movs r3, #0x4
 *   @0x2e6de4 blx r7
 *   @0x2e6de8 bne 0x2e6e12 <FT_Stream_ReadULong+0x4e>
 *   @0x2e6dec b 0x2e6df4 <FT_Stream_ReadULong+0x30>
 *   @0x2e6df0 adds r2, r2, r3
 *   @0x2e6df4 ldrb r0, [r2, #0x1]
 *   @0x2e6df8 lsls r0, r0, #0x10
 *   @0x2e6dfc ldmvc r3, {r0, r1, sp, lr} ^
 *   @0x2e6e00 ldrb r2, [r2, #0x2]
 *   @0x2e6e04 orr.w r2, r0, r2, lsl #8
 *   @0x2e6e08 ldr r3, [r4, #0x8]
 *   @0x2e6e0c adds r3, #0x4
 *   @0x2e6e10 b 0x2e6e18 <FT_Stream_ReadULong+0x54>
 *   @0x2e6e14 movs r3, #0x55
 *   @0x2e6e18 add sp, #0xc
 *
 * ══ §27/373 FT_Stream_ReadULongLE  0x2e6ee8  size 88  22 条（0x2e6ee8..0x2e6f40）
 * @func 0x2e6ee8 0x2e6f40  size 88  22 条
 * 部分覆盖: 本节 22/43 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×2 / 0x4×1 / 0x14×1 / 0x2×1 / 0x1×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e6ee8 push {r0, r1, r2, r4, r5, r6, r7, lr}
 *   @0x2e6eec str r3, [r1]
 *   @0x2e6ef0 ldr r3, [r0, #0x8]
 *   @0x2e6ef4 ldr r2, [r0, #0x4]
 *   @0x2e6ef8 cmp r1, r2
 *   @0x2e6efc ldr r7, [r0, #0x14]
 *   @0x2e6f00 add r6, sp, #0x4
 *   @0x2e6f04 movs r3, #0x4
 *   @0x2e6f08 blx r7
 *   @0x2e6f0c bne 0x2e6f36 <FT_Stream_ReadULongLE+0x4e>
 *   @0x2e6f10 b 0x2e6f18 <FT_Stream_ReadULongLE+0x30>
 *   @0x2e6f14 adds r2, r2, r3
 *   @0x2e6f18 ldrb r0, [r2, #0x2]
 *   @0x2e6f1c lsls r0, r0, #0x10
 *   @0x2e6f20 ldmdavc r3, {r0, r1, sp, lr}
 *   @0x2e6f24 ldrb r2, [r2, #0x1]
 *   @0x2e6f28 orr.w r2, r0, r2, lsl #8
 *   @0x2e6f2c ldr r3, [r4, #0x8]
 *   @0x2e6f30 adds r3, #0x4
 *   @0x2e6f34 b 0x2e6f3c <FT_Stream_ReadULongLE+0x54>
 *   @0x2e6f38 movs r3, #0x55
 *   @0x2e6f3c add sp, #0xc
 *
 * ══ §28/373 anon_2e9b7a  0x2e9b7a  size 88  22 条（0x2e9b7a..0x2e9bd2）
 * @func 0x2e9b7a 0x2e9bd2  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e9b7a .word 0x4604b510
 *   @0x2e9b7e .word 0xf5cc68c0
 *   @0x2e9b82 movwhs lr, #0xe66
 *   @0x2e9b86 rsbvs r6, r3, r3, ror #1
 *   @0x2e9b8a ldclt p0, c6, [r0, #-140]
 *   @0x2e9b8e ldrmi r11, [r7], -r0, ror #11
 *   @0x2e9b92 ldmdblt r3, {r1, r2, r3, r4, r9, r10, lr}
 *   @0x2e9b96 addsmi r6, r9, #4390912
 *   @0x2e9b9a stmvs r3, {r0, r1, r2, r3, r11, r12, lr, pc}
 *   @0x2e9b9e addmi r6, r11, #12910592
 *   @0x2e9ba2 strtmi sp, [r8], -r3
 *   @0x2e9ba6 .word 0xf5cc2200
 *   @0x2e9baa shadd8mi lr, r8, r4
 *   @0x2e9bae qasxmi r4, r11, r2
 *   @0x2e9bb2 pop {r0, r8, sp}
 *   @0x2e9bb6 .word 0xf03140e0
 *   @0x2e9bba strhhs r11, [r1], -r8
 *   @0x2e9bbe strmi r11, [r8], -r0, ror #27
 *   @0x2e9bc2 svclt #0x9bf031
 *   @0x2e9bc6 .word 0xf0314608
 *   @0x2e9bca ssub16mi r11, r8, r8
 *   @0x2e9bce .word 0xf0314611
 *
 * ══ §29/373 _zip_get_name(zip*, int, int, zip_error*)  0x2a491a  size 86  22 条（0x2a491a..0x2a4970）
 * @func 0x2a491a 0x2a4972  size 88  22 条
 * 部分覆盖: 本节 22/42 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _zip_get_name(zip*, int, int, zip_error*)+0x10 / _zip_error_set(zip_error*, int, int)
 * 字段偏移 top8: 0x34×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a491a cmp r1, #0x0
 *   @0x2a491e mov r4, r0
 *   @0x2a4922 blt 0x2a492a <_Z13_zip_get_nameP3zipiiP9zip_error+0x10>
 *   @0x2a4926 cmp r1, r3
 *   @0x2a492a movs r1, #0x12
 *   @0x2a492e bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii>
 *   @0x2a4932 movs r0, #0x0
 *   @0x2a4936 ands r5, r2, #0x8
 *   @0x2a493a bne 0x2a4954 <_Z13_zip_get_nameP3zipiiP9zip_error+0x3a>
 *   @0x2a493e ldr r2, [r4, #0x34]
 *   @0x2a4942 adds r6, r2, r3
 *   @0x2a4946 cmp r3, #0x1
 *   @0x2a494a movs r1, #0x17
 *   @0x2a494e b 0x2a492e <_Z13_zip_get_nameP3zipiiP9zip_error+0x14>
 *   @0x2a4952 cbnz r3, 0x2a496c <_Z13_zip_get_nameP3zipiiP9zip_error+0x52>
 *   @0x2a4956 cmp r2, #0x0
 *   @0x2a495a ldr r3, [r2, #0x4]
 *   @0x2a495e bge 0x2a492a <_Z13_zip_get_nameP3zipiiP9zip_error+0x10>
 *   @0x2a4962 movs r2, #0x3c
 *   @0x2a4966 stmibvs r8, {r0, r8, r12, sp}
 *   @0x2a496a pop {r4, r5, r6, pc}
 *   @0x2a496e pop {r4, r5, r6, pc}
 *
 * ══ §30/373 Background_FreeTextures()  0xc35d8  size 84  21 条（0xc35d8..0xc362c）
 * @func 0xc35d8 0xc362c  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CBackground::FreeTexture()
 * 字段偏移 top8: 0x40×1 / 0x30×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc35d8 push {r4, r5, r6, lr}
 *   @0xc35dc ldr r5, [pc, #0x40]
 *   @0xc35e0 ldr r5, [pc, r5]
 *   @0xc35e4 ldr r3, [r5]
 *   @0xc35e8 cmp r3, #0
 *   @0xc35ec pople {r4, r5, r6, pc}
 *   @0xc35f0 ldr r6, [pc, #0x30]
 *   @0xc35f4 mov r4, #0
 *   @0xc35f8 add r6, pc, r6
 *   @0xc35fc ldr r3, [r6, #0x4]
 *   @0xc3600 ldr r0, [r3, r4, lsl #2]
 *   @0xc3604 add r4, r4, #1
 *   @0xc3608 cmp r0, #0
 *   @0xc360c beq 0xc3614 <_Z23Background_FreeTexturesv+0x3c>
 *   @0xc3610 bl 0xc1e3c <_ZN11CBackground11FreeTextureEv>
 *   @0xc3614 ldr r3, [r5]
 *   @0xc3618 cmp r3, r4
 *   @0xc361c bgt 0xc35fc <_Z23Background_FreeTexturesv+0x24>
 *   @0xc3620 pop {r4, r5, r6, pc}
 *   @0xc3624 eorseq r10, r2, r8, ror #6
 *   @0xc3628 ldrhteq r6, [r11], -r0
 *
 * ══ §31/373 F_Vertex_Float2_debug(RValue&, CInstance*, CInstance*, int, RValue*)  0xc9558  size 84  21 条（0xc9558..0xc95ac）
 * @func 0xc9558 0xc95ac  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / Init_Vertex_Write(RValue&, int, RValue*, int) / Buffer_Vertex::FindNextType(yyVertexType)
 * 字段偏移 top8: 0x10×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc9558 push {r3, r4, r5, lr}
 *   @0xc955c mov r1, r3
 *   @0xc9560 ldr r4, [sp, #0x10]
 *   @0xc9564 mov r3, #3
 *   @0xc9568 mov r2, r4
 *   @0xc956c bl 0xc9188 <_Z17Init_Vertex_WriteR6RValueiPS_i>
 *   @0xc9570 cmp r0, #0
 *   @0xc9574 popeq {r3, r4, r5, pc}
 *   @0xc9578 mov r1, #2
 *   @0xc957c bl 0xc875c <_ZN13Buffer_Vertex12FindNextTypeE12yyVertexType>
 *   @0xc9580 subs r5, r0, #0
 *   @0xc9584 popeq {r3, r4, r5, pc}
 *   @0xc9588 mov r1, #1
 *   @0xc958c mov r0, r4
 *   @0xc9590 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0xc9594 mov r1, #2
 *   @0xc9598 str r0, [r5]
 *   @0xc959c mov r0, r4
 *   @0xc95a0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0xc95a4 str r0, [r5, #0x4]
 *   @0xc95a8 pop {r3, r4, r5, pc}
 *
 * ══ §32/373 CExtensionConstant::~CExtensionConstant()  0xf46fc  size 84  21 条（0xf46fc..0xf4750）
 * @func 0xf46fc 0xf4750  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2
 * 字段偏移 top8: 0x4×2 / 0x8×2 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf46fc push {r4, lr}
 *   @0xf4700 mov r4, r0
 *   @0xf4704 ldr r0, [r0, #0x4]
 *   @0xf4708 ldr r3, [pc, #0x3c]
 *   @0xf470c cmp r0, #0
 *   @0xf4710 ldr r3, [pc, r3]
 *   @0xf4714 add r3, r3, #8
 *   @0xf4718 str r3, [r4]
 *   @0xf471c beq 0xf472c <_ZN18CExtensionConstantD2Ev+0x30>
 *   @0xf4720 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xf4724 mov r3, #0
 *   @0xf4728 str r3, [r4, #0x4]
 *   @0xf472c ldr r0, [r4, #0x8]
 *   @0xf4730 cmp r0, #0
 *   @0xf4734 beq 0xf4744 <_ZN18CExtensionConstantD2Ev+0x48>
 *   @0xf4738 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xf473c mov r3, #0
 *   @0xf4740 str r3, [r4, #0x8]
 *   @0xf4744 mov r0, r4
 *   @0xf4748 pop {r4, pc}
 *   @0xf474c eoreq r9, pc, r4, lsl r7
 *
 * ══ §33/373 CExtensionFile::FunctionFindId(int)  0xf4ee0  size 84  21 条（0xf4ee0..0xf4f34）
 * @func 0xf4ee0 0xf4f34  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CExtensionFile::FunctionFindId(int)+0x48
 * 字段偏移 top8: 0x10×2 / 0x4×2 / 0x-4×1 / 0x1c×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf4ee0 str r4, [sp, #-0x4]!
 *   @0xf4ee4 ldr r4, [r0, #0x1c]
 *   @0xf4ee8 cmp r4, #0
 *   @0xf4eec ble 0xf4f28 <_ZN14CExtensionFile14FunctionFindIdEi+0x48>
 *   @0xf4ef0 ldr r2, [r0, #0x18]
 *   @0xf4ef4 ldr r0, [r2]
 *   @0xf4ef8 ldr r3, [r0, #0x10]
 *   @0xf4efc cmp r3, r1
 *   @0xf4f00 beq 0xf4f2c <_ZN14CExtensionFile14FunctionFindIdEi+0x4c>
 *   @0xf4f04 mov r3, #0
 *   @0xf4f08 b 0xf4f1c <_ZN14CExtensionFile14FunctionFindIdEi+0x3c>
 *   @0xf4f0c ldr r0, [r2, #0x4]!
 *   @0xf4f10 ldr r12, [r0, #0x10]
 *   @0xf4f14 cmp r12, r1
 *   @0xf4f18 beq 0xf4f2c <_ZN14CExtensionFile14FunctionFindIdEi+0x4c>
 *   @0xf4f1c add r3, r3, #1
 *   @0xf4f20 cmp r3, r4
 *   @0xf4f24 bne 0xf4f0c <_ZN14CExtensionFile14FunctionFindIdEi+0x2c>
 *   @0xf4f28 mov r0, #0
 *   @0xf4f2c ldr r4, [sp], #4
 *   @0xf4f30 bx lr
 *
 * ══ §34/373 CExtensionPackage::~CExtensionPackage()  0xf5700  size 84  21 条（0xf5700..0xf5754）
 * @func 0xf5700 0xf5754  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×3 / CExtensionPackage::Clear()
 * 字段偏移 top8: 0x4×2 / 0x8×2 / 0xc×2 / 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf5700 push {r3, r4, r5, lr}
 *   @0xf5704 mov r4, r0
 *   @0xf5708 ldr r3, [pc, #0x40]
 *   @0xf570c mov r5, #0
 *   @0xf5710 ldr r0, [r0, #0x4]
 *   @0xf5714 ldr r3, [pc, r3]
 *   @0xf5718 add r3, r3, #8
 *   @0xf571c str r3, [r4]
 *   @0xf5720 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xf5724 ldr r0, [r4, #0x8]
 *   @0xf5728 str r5, [r4, #0x4]
 *   @0xf572c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xf5730 ldr r0, [r4, #0xc]
 *   @0xf5734 str r5, [r4, #0x8]
 *   @0xf5738 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xf573c mov r0, r4
 *   @0xf5740 str r5, [r4, #0xc]
 *   @0xf5744 bl 0xf563c <_ZN17CExtensionPackage5ClearEv>
 *   @0xf5748 mov r0, r4
 *   @0xf574c pop {r3, r4, r5, pc}
 *   @0xf5750 eoreq r8, pc, r12, lsl r7
 *
 * ══ §35/373 CFontGM::TextWidth(unsigned short*)  0xf8b04  size 84  21 条（0xf8b04..0xf8b58）
 * @func 0xf8b04 0xf8b58  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CFontGM::GetShift(int)
 * 字段偏移 top8: 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf8b04 push {r4, r5, r6, lr}
 *   @0xf8b08 subs r5, r1, #0
 *   @0xf8b0c mov r6, r0
 *   @0xf8b10 beq 0xf8b44 <_ZN7CFontGM9TextWidthEPt+0x40>
 *   @0xf8b14 ldrh r1, [r5]
 *   @0xf8b18 cmp r1, #0
 *   @0xf8b1c beq 0xf8b50 <_ZN7CFontGM9TextWidthEPt+0x4c>
 *   @0xf8b20 mov r4, #0
 *   @0xf8b24 mov r0, r6
 *   @0xf8b28 bl 0xf6e78 <_ZN7CFontGM8GetShiftEi>
 *   @0xf8b2c ldrh r1, [r5, #2]!
 *   @0xf8b30 cmp r1, #0
 *   @0xf8b34 add r4, r4, r0
 *   @0xf8b38 bne 0xf8b24 <_ZN7CFontGM9TextWidthEPt+0x20>
 *   @0xf8b3c mov r0, r4
 *   @0xf8b40 pop {r4, r5, r6, pc}
 *   @0xf8b44 mov r4, r5
 *   @0xf8b48 mov r0, r4
 *   @0xf8b4c pop {r4, r5, r6, pc}
 *   @0xf8b50 mov r4, r1
 *   @0xf8b54 b 0xf8b3c <_ZN7CFontGM9TextWidthEPt+0x38>
 *
 * ══ §36/373 Font_InitTextures()  0xfac40  size 84  21 条（0xfac40..0xfac94）
 * @func 0xfac40 0xfaca8  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CFontGM::InitTexture()
 * 字段偏移 top8: 0x40×1 / 0x30×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfac40 push {r4, r5, r6, lr}
 *   @0xfac44 ldr r5, [pc, #0x40]
 *   @0xfac48 ldr r5, [pc, r5]
 *   @0xfac4c ldr r3, [r5]
 *   @0xfac50 cmp r3, #0
 *   @0xfac54 pople {r4, r5, r6, pc}
 *   @0xfac58 ldr r6, [pc, #0x30]
 *   @0xfac5c mov r4, #0
 *   @0xfac60 ldr r6, [pc, r6]
 *   @0xfac64 ldr r3, [r6, #0x4]
 *   @0xfac68 ldr r0, [r3, r4, lsl #2]
 *   @0xfac6c add r4, r4, #1
 *   @0xfac70 cmp r0, #0
 *   @0xfac74 beq 0xfac7c <_Z17Font_InitTexturesv+0x3c>
 *   @0xfac78 bl 0xf7db4 <_ZN7CFontGM11InitTextureEv>
 *   @0xfac7c ldr r3, [r5]
 *   @0xfac80 cmp r3, r4
 *   @0xfac84 bgt 0xfac64 <_Z17Font_InitTexturesv+0x24>
 *   @0xfac88 pop {r4, r5, r6, pc}
 *   @0xfac8c eoreq r3, pc, r8, lsl r2
 *   @0xfac90 .word 0x002f31fc
 *
 * ══ §37/373 Font_FreeTextures()  0xfac94  size 84  21 条（0xfac94..0xface8）
 * @func 0xfac94 0xface8  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CFontGM::FreeTexture()
 * 字段偏移 top8: 0x40×1 / 0x30×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfac94 push {r4, r5, r6, lr}
 *   @0xfac98 ldr r5, [pc, #0x40]
 *   @0xfac9c ldr r5, [pc, r5]
 *   @0xfaca0 ldr r3, [r5]
 *   @0xfaca4 cmp r3, #0
 *   @0xfaca8 pople {r4, r5, r6, pc}
 *   @0xfacac ldr r6, [pc, #0x30]
 *   @0xfacb0 mov r4, #0
 *   @0xfacb4 ldr r6, [pc, r6]
 *   @0xfacb8 ldr r3, [r6, #0x4]
 *   @0xfacbc ldr r0, [r3, r4, lsl #2]
 *   @0xfacc0 add r4, r4, #1
 *   @0xfacc4 cmp r0, #0
 *   @0xfacc8 beq 0xfacd0 <_Z17Font_FreeTexturesv+0x3c>
 *   @0xfaccc bl 0xf707c <_ZN7CFontGM11FreeTextureEv>
 *   @0xfacd0 ldr r3, [r5]
 *   @0xfacd4 cmp r3, r4
 *   @0xfacd8 bgt 0xfacb8 <_Z17Font_FreeTexturesv+0x24>
 *   @0xfacdc pop {r4, r5, r6, pc}
 *   @0xface0 eoreq r3, pc, r4, asr #3
 *   @0xface4 eoreq r3, pc, r8, lsr #3
 *
 * ══ §38/373 F_DsGridCreate(RValue&, CInstance*, CInstance*, int, RValue*)  0x100394  size 84  21 条（0x100394..0x1003e8）
 * @func 0x100394 0x1003e8  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / YYGML_ds_grid_create(int, int)
 * 字段偏移 top8: 0x10×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x100394 push {r4, r5, r6, lr}
 *   @0x100398 mov r1, #0
 *   @0x10039c ldr r5, [sp, #0x10]
 *   @0x1003a0 mov r4, r0
 *   @0x1003a4 str r1, [r0, #0xc]
 *   @0x1003a8 mov r0, r5
 *   @0x1003ac bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1003b0 mov r1, #1
 *   @0x1003b4 mov r6, r0
 *   @0x1003b8 mov r0, r5
 *   @0x1003bc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1003c0 mov r1, r0
 *   @0x1003c4 mov r0, r6
 *   @0x1003c8 bl 0x100294 <_Z20YYGML_ds_grid_createii>
 *   @0x1003cc vmov s15, r0
 *   @0x1003d0 vcvt.f64.s32 d7, s15
 *   @0x1003d4 vmov r0, r1, d7
 *   @0x1003d8 vmov r2, s14
 *   @0x1003dc mov r3, r1
 *   @0x1003e0 stm r4, {r2, r3}
 *   @0x1003e4 pop {r4, r5, r6, pc}
 *
 * ══ §39/373 dsListAddDouble  0x101ccc  size 84  21 条（0x101ccc..0x101d20）
 * @func 0x101ccc 0x101d20  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_DsListAdd(RValue&, CInstance*, CInstance*, int, RValue*)
 * 字段偏移 top8: 0x-4×1 / 0x8×1 / 0x20×1 / 0x30×1 / 0x24×1 / 0x34×1 / 0x4×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x101ccc vmov s13, r0
 *   @0x101cd0 mov r12, #0
 *   @0x101cd4 str lr, [sp, #-0x4]!
 *   @0x101cd8 vcvt.f64.s32 d7, s13
 *   @0x101cdc sub sp, sp, #60
 *   @0x101ce0 mov r1, r12
 *   @0x101ce4 add r0, sp, #8
 *   @0x101ce8 strd r2, r3, [sp, #40]
 *   @0x101cec add r3, sp, #24
 *   @0x101cf0 mov r2, r12
 *   @0x101cf4 str r3, [sp]
 *   @0x101cf8 mov r3, #2
 *   @0x101cfc str r12, [sp, #0x8]
 *   @0x101d00 str r12, [sp, #0x20]
 *   @0x101d04 str r12, [sp, #0x30]
 *   @0x101d08 vstr d7, [sp, #24]
 *   @0x101d0c str r12, [sp, #0x24]
 *   @0x101d10 str r12, [sp, #0x34]
 *   @0x101d14 bl 0xfc474 <_Z11F_DsListAddR6RValueP9CInstanceS2_iPS_>
 *   @0x101d18 add sp, sp, #60
 *   @0x101d1c ldr pc, [sp], #4
 *
 * ══ §40/373 F_MoveContact(RValue&, CInstance*, CInstance*, int, RValue*)  0x1084cc  size 84  21 条（0x1084cc..0x108520）
 * @func 0x1084cc 0x108520  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int) / Command_IsFree(CInstance*, float, float)
 * 字段偏移 top8: 0x10×1 / 0xb4×1 / 0xb8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1084cc push {r4, r5, r6, lr}
 *   @0x1084d0 mov r4, r1
 *   @0x1084d4 ldr r0, [sp, #0x10]
 *   @0x1084d8 mov r1, #0
 *   @0x1084dc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1084e0 ldr r1, [r4, #0xb4]
 *   @0x1084e4 ldr r2, [r4, #0xb8]
 *   @0x1084e8 mov r5, r0
 *   @0x1084ec mov r0, r4
 *   @0x1084f0 bl 0x1cab94 <_Z14Command_IsFreeP9CInstanceff>
 *   @0x1084f4 mov r2, #0
 *   @0x1084f8 mov r1, r5
 *   @0x1084fc movt r2, #0xbf80
 *   @0x108500 subs r3, r0, #0
 *   @0x108504 mov r0, r4
 *   @0x108508 bne 0x108514 <_Z13F_MoveContactR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x10850c pop {r4, r5, r6, lr}
 *   @0x108510 b 0x1cae64 <_Z19Command_MoveOutsideP9CInstanceffb>
 *   @0x108514 mov r3, #0
 *   @0x108518 pop {r4, r5, r6, lr}
 *   @0x10851c b 0x1cad28 <_Z19Command_MoveContactP9CInstanceffb>
 *
 * ══ §41/373 F_StringByteLength(RValue&, CInstance*, CInstance*, int, RValue*)  0x10ee60  size 84  21 条（0x10ee60..0x10eeb4）
 * @func 0x10ee60 0x10eeb4  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int) / 0xb6538
 * 字段偏移 top8: 0x8×1 / 0x4×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10ee60 push {r4, lr}
 *   @0x10ee64 mov r1, #0
 *   @0x10ee68 mov r4, r0
 *   @0x10ee6c ldr r0, [sp, #0x8]
 *   @0x10ee70 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x10ee74 cmp r0, #0
 *   @0x10ee78 beq 0x10eea8 <_Z18F_StringByteLengthR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x10ee7c bl 0xb6538 <strlen@plt>
 *   @0x10ee80 vmov s15, r0
 *   @0x10ee84 vcvt.f64.u32 d7, s15
 *   @0x10ee88 vmov r2, r3, d7
 *   @0x10ee8c mov r1, r2
 *   @0x10ee90 mov r2, r3
 *   @0x10ee94 str r1, [r4]
 *   @0x10ee98 mov r3, #0
 *   @0x10ee9c str r2, [r4, #0x4]
 *   @0x10eea0 str r3, [r4, #0xc]
 *   @0x10eea4 pop {r4, pc}
 *   @0x10eea8 mov r2, #0
 *   @0x10eeac mov r3, #0
 *   @0x10eeb0 b 0x10ee8c <_Z18F_StringByteLengthR6RValueP9CInstanceS2_iPS_+0x2c>
 *
 * ══ §42/373 utf8_get_char  0x10fae4  size 84  21 条（0x10fae4..0x10fb38）
 * @func 0x10fae4 0x10fb38  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1×2 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10fae4 ldrb r3, [r0]
 *   @0x10fae8 tst r3, #128
 *   @0x10faec beq 0x10fb30 <utf8_get_char+0x4c>
 *   @0x10faf0 tst r3, #32
 *   @0x10faf4 bne 0x10fb0c <utf8_get_char+0x28>
 *   @0x10faf8 ldrb r0, [r0, #0x1]
 *   @0x10fafc and r3, r3, #31
 *   @0x10fb00 and r0, r0, #63
 *   @0x10fb04 add r0, r0, r3, lsl #6
 *   @0x10fb08 bx lr
 *   @0x10fb0c ldrb r2, [r0, #0x1]
 *   @0x10fb10 ldrb r0, [r0, #0x2]
 *   @0x10fb14 and r2, r2, #63
 *   @0x10fb18 and r0, r0, #63
 *   @0x10fb1c lsl r2, r2, #6
 *   @0x10fb20 add r3, r2, r3, lsl #12
 *   @0x10fb24 add r0, r0, r3
 *   @0x10fb28 uxth r0, r0
 *   @0x10fb2c bx lr
 *   @0x10fb30 mov r0, r3
 *   @0x10fb34 bx lr
 *
 * ══ §43/373 F_StringLength(RValue&, CInstance*, CInstance*, int, RValue*)  0x110690  size 84  21 条（0x110690..0x1106e4）
 * @func 0x110690 0x1106e4  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int) / utf8_strlen
 * 字段偏移 top8: 0x8×1 / 0x4×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x110690 push {r4, lr}
 *   @0x110694 mov r1, #0
 *   @0x110698 mov r4, r0
 *   @0x11069c ldr r0, [sp, #0x8]
 *   @0x1106a0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1106a4 cmp r0, #0
 *   @0x1106a8 beq 0x1106d8 <_Z14F_StringLengthR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x1106ac bl 0x110648 <utf8_strlen>
 *   @0x1106b0 vmov s15, r0
 *   @0x1106b4 vcvt.f64.s32 d7, s15
 *   @0x1106b8 vmov r2, r3, d7
 *   @0x1106bc mov r1, r2
 *   @0x1106c0 mov r2, r3
 *   @0x1106c4 str r1, [r4]
 *   @0x1106c8 mov r3, #0
 *   @0x1106cc str r2, [r4, #0x4]
 *   @0x1106d0 str r3, [r4, #0xc]
 *   @0x1106d4 pop {r4, pc}
 *   @0x1106d8 mov r2, #0
 *   @0x1106dc mov r3, #0
 *   @0x1106e0 b 0x1106bc <_Z14F_StringLengthR6RValueP9CInstanceS2_iPS_+0x2c>
 *
 * ══ §44/373 F_IRandom(RValue&, CInstance*, CInstance*, int, RValue*)  0x110d98  size 84  21 条（0x110d98..0x110dec）
 * @func 0x110d98 0x110dec  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt64(RValue const*, int) / iScript_Random(long long) / __floatdidf
 * 字段偏移 top8: 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x110d98 push {r6, lr}
 *   @0x110d9c mov r1, #0
 *   @0x110da0 mov r6, r0
 *   @0x110da4 ldr r0, [sp, #0x8]
 *   @0x110da8 bl 0xcea30 <_Z10YYGetInt64PK6RValuei>
 *   @0x110dac mov r2, r0
 *   @0x110db0 mov r3, r1
 *   @0x110db4 cmp r2, #0
 *   @0x110db8 sbcs r1, r3, #0
 *   @0x110dbc mov r1, #0
 *   @0x110dc0 str r1, [r6, #0xc]
 *   @0x110dc4 mvnlt r0, #0
 *   @0x110dc8 mvnlt r1, #0
 *   @0x110dcc movge r1, #0
 *   @0x110dd0 movge r0, #1
 *   @0x110dd4 adds r0, r0, r2
 *   @0x110dd8 adc r1, r1, r3
 *   @0x110ddc bl 0x110d18 <_Z14iScript_Randomx>
 *   @0x110de0 bl 0x319164 <__floatdidf>
 *   @0x110de4 stm r6, {r0, r1}
 *   @0x110de8 pop {r6, pc}
 *
 * ══ §45/373 F_LengthDirX(RValue&, CInstance*, CInstance*, int, RValue*)  0x111b40  size 84  21 条（0x111b40..0x111b94）
 * @func 0x111b40 0x111b94  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / YYGML_lengthdir_x(float, float)
 * 字段偏移 top8: 0x10×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x111b40 push {r4, r5, r6, lr}
 *   @0x111b44 mov r1, #0
 *   @0x111b48 ldr r5, [sp, #0x10]
 *   @0x111b4c mov r4, r0
 *   @0x111b50 str r1, [r0, #0xc]
 *   @0x111b54 mov r0, r5
 *   @0x111b58 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x111b5c mov r1, #1
 *   @0x111b60 mov r6, r0
 *   @0x111b64 mov r0, r5
 *   @0x111b68 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x111b6c mov r1, r0
 *   @0x111b70 mov r0, r6
 *   @0x111b74 bl 0x111acc <_Z17YYGML_lengthdir_xff>
 *   @0x111b78 vmov s15, r0
 *   @0x111b7c vcvt.f64.f32 d7, s15
 *   @0x111b80 vmov r0, r1, d7
 *   @0x111b84 vmov r2, s14
 *   @0x111b88 mov r3, r1
 *   @0x111b8c stm r4, {r2, r3}
 *   @0x111b90 pop {r4, r5, r6, pc}
 *
 * ══ §46/373 F_LengthDirY(RValue&, CInstance*, CInstance*, int, RValue*)  0x111c08  size 84  21 条（0x111c08..0x111c5c）
 * @func 0x111c08 0x111c5c  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / YYGML_lengthdir_y(float, float)
 * 字段偏移 top8: 0x10×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x111c08 push {r4, r5, r6, lr}
 *   @0x111c0c mov r1, #0
 *   @0x111c10 ldr r5, [sp, #0x10]
 *   @0x111c14 mov r4, r0
 *   @0x111c18 str r1, [r0, #0xc]
 *   @0x111c1c mov r0, r5
 *   @0x111c20 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x111c24 mov r1, #1
 *   @0x111c28 mov r6, r0
 *   @0x111c2c mov r0, r5
 *   @0x111c30 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x111c34 mov r1, r0
 *   @0x111c38 mov r0, r6
 *   @0x111c3c bl 0x111b94 <_Z17YYGML_lengthdir_yff>
 *   @0x111c40 vmov s15, r0
 *   @0x111c44 vcvt.f64.f32 d7, s15
 *   @0x111c48 vmov r0, r1, d7
 *   @0x111c4c vmov r2, s14
 *   @0x111c50 mov r3, r1
 *   @0x111c54 stm r4, {r2, r3}
 *   @0x111c58 pop {r4, r5, r6, pc}
 *
 * ══ §47/373 is_leap_year(int)  0x117a5c  size 84  21 条（0x117a5c..0x117ab0）
 * @func 0x117a5c 0x117ab0  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x117a5c tst r0, #3
 *   @0x117a60 bne 0x117aa8 <_Z12is_leap_yeari+0x4c>
 *   @0x117a64 movw r3, #0x851f
 *   @0x117a68 movt r3, #0x51eb
 *   @0x117a6c asr r2, r0, #31
 *   @0x117a70 mov r12, #400
 *   @0x117a74 smull r1, r3, r3, r0
 *   @0x117a78 rsb r1, r2, r3, asr #7
 *   @0x117a7c mls r1, r12, r1, r0
 *   @0x117a80 cmp r1, #0
 *   @0x117a84 beq 0x117aa0 <_Z12is_leap_yeari+0x44>
 *   @0x117a88 rsb r3, r2, r3, asr #5
 *   @0x117a8c mov r2, #100
 *   @0x117a90 mls r0, r2, r3, r0
 *   @0x117a94 adds r0, r0, #0
 *   @0x117a98 movne r0, #1
 *   @0x117a9c bx lr
 *   @0x117aa0 mov r0, #1
 *   @0x117aa4 bx lr
 *   @0x117aa8 mov r0, #0
 *   @0x117aac bx lr
 *
 * ══ §48/373 F_MakeColorRGB(RValue&, CInstance*, CInstance*, int, RValue*)  0x119d24  size 84  21 条（0x119d24..0x119d78）
 * @func 0x119d24 0x119d78  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3
 * 字段偏移 top8: 0x10×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x119d24 push {r4, r5, r6, lr}
 *   @0x119d28 mov r1, #0
 *   @0x119d2c ldr r4, [sp, #0x10]
 *   @0x119d30 mov r5, r0
 *   @0x119d34 str r1, [r0, #0xc]
 *   @0x119d38 mov r0, r4
 *   @0x119d3c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x119d40 mov r1, #1
 *   @0x119d44 mov r6, r0
 *   @0x119d48 mov r0, r4
 *   @0x119d4c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x119d50 mov r1, #2
 *   @0x119d54 add r6, r6, r0, lsl #8
 *   @0x119d58 mov r0, r4
 *   @0x119d5c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x119d60 add r0, r6, r0, lsl #16
 *   @0x119d64 vmov s15, r0
 *   @0x119d68 vcvt.f64.s32 d7, s15
 *   @0x119d6c vmov r2, r3, d7
 *   @0x119d70 stm r5, {r2, r3}
 *   @0x119d74 pop {r4, r5, r6, pc}
 *
 * ══ §49/373 F_ColorGetBlue(RValue&, CInstance*, CInstance*, int, RValue*)  0x119e0c  size 84  21 条（0x119e0c..0x119e60）
 * @func 0x119e0c 0x119e60  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x119e0c push {r4, lr}
 *   @0x119e10 mov r3, #0
 *   @0x119e14 mov r1, r3
 *   @0x119e18 str r3, [r0, #0xc]
 *   @0x119e1c mov r4, r0
 *   @0x119e20 ldr r0, [sp, #0x8]
 *   @0x119e24 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x119e28 add r3, r0, #65280
 *   @0x119e2c cmp r0, #0
 *   @0x119e30 add r3, r3, #255
 *   @0x119e34 movlt r0, r3
 *   @0x119e38 asr r1, r0, #31
 *   @0x119e3c lsr r1, r1, #24
 *   @0x119e40 add r0, r1, r0, asr #16
 *   @0x119e44 uxtb r2, r0
 *   @0x119e48 rsb r2, r1, r2
 *   @0x119e4c vmov s15, r2
 *   @0x119e50 vcvt.f64.s32 d7, s15
 *   @0x119e54 vmov r2, r3, d7
 *   @0x119e58 stm r4, {r2, r3}
 *   @0x119e5c pop {r4, pc}
 *
 * ══ §50/373 F_DisplaySetUIVisibility(RValue&, CInstance*, CInstance*, int, RValue*)  0x11a260  size 84  21 条（0x11a260..0x11a2b4）
 * @func 0x11a260 0x11a2c8  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0xc×2 / 0x3c×1 / 0x4×1 / 0x10×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11a260 push {r3, r4, r5, lr}
 *   @0x11a264 mov r4, #0
 *   @0x11a268 ldr r3, [pc, #0x3c]
 *   @0x11a26c str r4, [r0]
 *   @0x11a270 ldr r3, [pc, r3]
 *   @0x11a274 str r4, [r0, #0x4]
 *   @0x11a278 str r4, [r0, #0xc]
 *   @0x11a27c ldr r0, [r3]
 *   @0x11a280 ldr r5, [sp, #0x10]
 *   @0x11a284 ldr r1, [pc, #0x24]
 *   @0x11a288 ldr r2, [r0]
 *   @0x11a28c add r1, pc, r1
 *   @0x11a290 ldr r3, [r2, #0xc]
 *   @0x11a294 blx r3
 *   @0x11a298 mov r0, r5
 *   @0x11a29c mov r1, r4
 *   @0x11a2a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11a2a4 pop {r3, r4, r5, lr}
 *   @0x11a2a8 b 0x15e2b8 <_Z22DisplaySetUIVisibilityi>
 *   @0x11a2ac eoreq r3, sp, r4, lsr #9
 *   @0x11a2b0 eoreq pc, r1, r4, lsr #25
 *
 * ══ §51/373 F_SurfaceSetTargetExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x11ca24  size 84  21 条（0x11ca24..0x11ca78）
 * @func 0x11ca24 0x11ca78  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / YYGML_surface_set_target_ext(int, int)
 * 字段偏移 top8: 0x10×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11ca24 push {r4, r5, r6, lr}
 *   @0x11ca28 mov r1, #0
 *   @0x11ca2c ldr r5, [sp, #0x10]
 *   @0x11ca30 mov r4, r0
 *   @0x11ca34 str r1, [r0, #0xc]
 *   @0x11ca38 mov r0, r5
 *   @0x11ca3c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11ca40 mov r1, #1
 *   @0x11ca44 mov r6, r0
 *   @0x11ca48 mov r0, r5
 *   @0x11ca4c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11ca50 mov r1, r0
 *   @0x11ca54 mov r0, r6
 *   @0x11ca58 bl 0x171574 <_Z28YYGML_surface_set_target_extii>
 *   @0x11ca5c vmov s15, r0
 *   @0x11ca60 vcvt.f64.u32 d7, s15
 *   @0x11ca64 vmov r0, r1, d7
 *   @0x11ca68 vmov r2, s14
 *   @0x11ca6c mov r3, r1
 *   @0x11ca70 stm r4, {r2, r3}
 *   @0x11ca74 pop {r4, r5, r6, pc}
 *
 * ══ §52/373 F_SkeletonSetDrawCollision(RValue&, CInstance*, CInstance*, int, RValue*)  0x11caa8  size 84  21 条（0x11caa8..0x11cafc）
 * @func 0x11caa8 0x11cafc  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::SkeletonAnimation() / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x4×3 / 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11caa8 push {r4, r5, r6, lr}
 *   @0x11caac mov r4, r0
 *   @0x11cab0 mov r5, #0
 *   @0x11cab4 mov r3, #0
 *   @0x11cab8 mov r0, r1
 *   @0x11cabc movt r3, #0xbff0
 *   @0x11cac0 str r5, [r4, #0xc]
 *   @0x11cac4 str r3, [r4, #0x4]
 *   @0x11cac8 str r5, [r4]
 *   @0x11cacc bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv>
 *   @0x11cad0 subs r6, r0, #0
 *   @0x11cad4 popeq {r4, r5, r6, pc}
 *   @0x11cad8 ldr r0, [sp, #0x10]
 *   @0x11cadc mov r1, r5
 *   @0x11cae0 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x11cae4 mov r3, r5
 *   @0x11cae8 movt r3, #0x3ff0
 *   @0x11caec strb r0, [r6, #0x4]
 *   @0x11caf0 str r5, [r4]
 *   @0x11caf4 str r3, [r4, #0x4]
 *   @0x11caf8 pop {r4, r5, r6, pc}
 *
 * ══ §53/373 F_SkeletonGetAttachment(RValue&, CInstance*, CInstance*, int, RValue*)  0x11d144  size 84  21 条（0x11d144..0x11d198）
 * @func 0x11d144 0x11d198  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::SkeletonAnimation() / YYGetString(RValue const*, int) / CSkeletonInstance::GetAttachment(char*) const
 * 字段偏移 top8: 0xc×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11d144 push {r3, r4, r5, r6, r7, lr}
 *   @0x11d148 mov r4, r0
 *   @0x11d14c mov r3, #1
 *   @0x11d150 mov r0, r1
 *   @0x11d154 str r3, [r4, #0xc]
 *   @0x11d158 mov r5, #0
 *   @0x11d15c str r5, [r4]
 *   @0x11d160 ldr r6, [sp, #0x18]
 *   @0x11d164 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv>
 *   @0x11d168 subs r7, r0, #0
 *   @0x11d16c popeq {r3, r4, r5, r6, r7, pc}
 *   @0x11d170 mov r1, r5
 *   @0x11d174 mov r0, r6
 *   @0x11d178 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x11d17c mov r1, r0
 *   @0x11d180 mov r0, r7
 *   @0x11d184 bl 0xc07c8 <_ZNK17CSkeletonInstance13GetAttachmentEPc>
 *   @0x11d188 mov r1, r0
 *   @0x11d18c mov r0, r4
 *   @0x11d190 pop {r3, r4, r5, r6, r7, lr}
 *   @0x11d194 b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *
 * ══ §54/373 F_BackgroundGetTexture(RValue&, CInstance*, CInstance*, int, RValue*)  0x11da68  size 84  21 条（0x11da68..0x11dabc）
 * @func 0x11da68 0x11dad0  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Background_Exists(int) / Background_Data(int) / CBackground::GetTexture()
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11da68 push {r3, r4, r5, lr}
 *   @0x11da6c mov r1, #0
 *   @0x11da70 mov r4, r0
 *   @0x11da74 ldr r0, [sp, #0x10]
 *   @0x11da78 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11da7c mov r5, r0
 *   @0x11da80 bl 0xc3640 <_Z17Background_Existsi>
 *   @0x11da84 subs r1, r0, #0
 *   @0x11da88 beq 0x11daa8 <_Z22F_BackgroundGetTextureR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x11da8c mov r3, #3
 *   @0x11da90 mov r0, r5
 *   @0x11da94 str r3, [r4, #0xc]
 *   @0x11da98 bl 0xc3794 <_Z15Background_Datai>
 *   @0x11da9c bl 0xc1e8c <_ZN11CBackground10GetTextureEv>
 *   @0x11daa0 str r0, [r4]
 *   @0x11daa4 pop {r3, r4, r5, pc}
 *   @0x11daa8 ldr r0, [pc, #0x8]
 *   @0x11daac pop {r3, r4, r5, lr}
 *   @0x11dab0 add r0, pc, r0
 *   @0x11dab4 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x11dab8 eoreq r12, r1, r0, asr #13
 *
 * ══ §55/373 F_FontGetTexture(RValue&, CInstance*, CInstance*, int, RValue*)  0x11dabc  size 84  21 条（0x11dabc..0x11db10）
 * @func 0x11dabc 0x11db10  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Font_Exists(int) / Font_Data(int) / CFontGM::GetTexture()
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11dabc push {r3, r4, r5, lr}
 *   @0x11dac0 mov r1, #0
 *   @0x11dac4 mov r4, r0
 *   @0x11dac8 ldr r0, [sp, #0x10]
 *   @0x11dacc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11dad0 mov r5, r0
 *   @0x11dad4 bl 0xfa2a8 <_Z11Font_Existsi>
 *   @0x11dad8 subs r1, r0, #0
 *   @0x11dadc beq 0x11dafc <_Z16F_FontGetTextureR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x11dae0 mov r3, #3
 *   @0x11dae4 mov r0, r5
 *   @0x11dae8 str r3, [r4, #0xc]
 *   @0x11daec bl 0xfa3fc <_Z9Font_Datai>
 *   @0x11daf0 bl 0xf94e4 <_ZN7CFontGM10GetTextureEv>
 *   @0x11daf4 str r0, [r4]
 *   @0x11daf8 pop {r3, r4, r5, pc}
 *   @0x11dafc ldr r0, [pc, #0x8]
 *   @0x11db00 pop {r3, r4, r5, lr}
 *   @0x11db04 add r0, pc, r0
 *   @0x11db08 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x11db0c eoreq r12, r1, r0, lsr #13
 *
 * ══ §56/373 SetImageALPHA(unsigned char*, int, int)  0x120c3c  size 84  21 条（0x120c3c..0x120c90）
 * @func 0x120c3c 0x120c90  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: SetImageALPHA(unsigned char*, int, int)+0x4c / SetImageALPHA(unsigned char*, int, int)+0x40
 * 字段偏移 top8: 0x3×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x120c3c cmp r2, #0
 *   @0x120c40 push {r4, r5, r6}
 *   @0x120c44 ble 0x120c88 <_Z13SetImageALPHAPhii+0x4c>
 *   @0x120c48 lsl r6, r1, #2
 *   @0x120c4c mov r5, #0
 *   @0x120c50 mvn r4, #0
 *   @0x120c54 cmp r1, #0
 *   @0x120c58 ble 0x120c7c <_Z13SetImageALPHAPhii+0x40>
 *   @0x120c5c mov r12, r0
 *   @0x120c60 mov r3, #0
 *   @0x120c64 add r3, r3, #1
 *   @0x120c68 strb r4, [r12, #0x3]
 *   @0x120c6c cmp r3, r1
 *   @0x120c70 add r12, r12, #4
 *   @0x120c74 bne 0x120c64 <_Z13SetImageALPHAPhii+0x28>
 *   @0x120c78 add r0, r0, r6
 *   @0x120c7c add r5, r5, #1
 *   @0x120c80 cmp r5, r2
 *   @0x120c84 bne 0x120c54 <_Z13SetImageALPHAPhii+0x18>
 *   @0x120c88 pop {r4, r5, r6}
 *   @0x120c8c bx lr
 *
 * ══ §57/373 F_PartEmitterExists(RValue&, CInstance*, CInstance*, int, RValue*)  0x129c84  size 84  21 条（0x129c84..0x129cd8）
 * @func 0x129c84 0x129cd8  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / ParticleSystem_Emitter_Exists(int, int)
 * 字段偏移 top8: 0x10×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x129c84 push {r4, r5, r6, lr}
 *   @0x129c88 mov r1, #0
 *   @0x129c8c ldr r5, [sp, #0x10]
 *   @0x129c90 mov r4, r0
 *   @0x129c94 str r1, [r0, #0xc]
 *   @0x129c98 mov r0, r5
 *   @0x129c9c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129ca0 mov r1, #1
 *   @0x129ca4 mov r6, r0
 *   @0x129ca8 mov r0, r5
 *   @0x129cac bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129cb0 mov r1, r0
 *   @0x129cb4 mov r0, r6
 *   @0x129cb8 bl 0x1a3854 <_Z29ParticleSystem_Emitter_Existsii>
 *   @0x129cbc vmov s15, r0
 *   @0x129cc0 vcvt.f64.u32 d7, s15
 *   @0x129cc4 vmov r0, r1, d7
 *   @0x129cc8 vmov r2, s14
 *   @0x129ccc mov r3, r1
 *   @0x129cd0 stm r4, {r2, r3}
 *   @0x129cd4 pop {r4, r5, r6, pc}
 *
 * ══ §58/373 F_BackgroundAddAlpha(RValue&, CInstance*, CInstance*, int, RValue*)  0x12c8b8  size 84  21 条（0x12c8b8..0x12c90c）
 * @func 0x12c8b8 0x12c90c  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int) / YYGetBool(RValue const*, int) / Background_Add_Alpha(char const*, bool)
 * 字段偏移 top8: 0x10×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12c8b8 push {r4, r5, r6, lr}
 *   @0x12c8bc mov r1, #0
 *   @0x12c8c0 ldr r5, [sp, #0x10]
 *   @0x12c8c4 mov r4, r0
 *   @0x12c8c8 str r1, [r0, #0xc]
 *   @0x12c8cc mov r0, r5
 *   @0x12c8d0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x12c8d4 mov r1, #1
 *   @0x12c8d8 mov r6, r0
 *   @0x12c8dc mov r0, r5
 *   @0x12c8e0 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x12c8e4 mov r1, r0
 *   @0x12c8e8 mov r0, r6
 *   @0x12c8ec bl 0xc3ccc <_Z20Background_Add_AlphaPKcb>
 *   @0x12c8f0 vmov s15, r0
 *   @0x12c8f4 vcvt.f64.s32 d7, s15
 *   @0x12c8f8 vmov r0, r1, d7
 *   @0x12c8fc vmov r2, s14
 *   @0x12c900 mov r3, r1
 *   @0x12c904 stm r4, {r2, r3}
 *   @0x12c908 pop {r4, r5, r6, pc}
 *
 * ══ §59/373 F_SoundGetName(RValue&, CInstance*, CInstance*, int, RValue*)  0x12cbfc  size 84  21 条（0x12cbfc..0x12cc50）
 * @func 0x12cbfc 0x12cc50  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Sound_Name(int) / Audio_GetName(int)
 * 字段偏移 top8: 0x8×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12cbfc push {r4, lr}
 *   @0x12cc00 mov r1, #0
 *   @0x12cc04 mov r4, r0
 *   @0x12cc08 ldr r0, [sp, #0x8]
 *   @0x12cc0c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12cc10 ldr r3, [pc, #0x34]
 *   @0x12cc14 ldr r3, [pc, r3]
 *   @0x12cc18 ldrb r3, [r3]
 *   @0x12cc1c cmp r3, #0
 *   @0x12cc20 bne 0x12cc38 <_Z14F_SoundGetNameR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x12cc24 bl 0x21fc18 <_Z10Sound_Namei>
 *   @0x12cc28 mov r1, r0
 *   @0x12cc2c mov r0, r4
 *   @0x12cc30 pop {r4, lr}
 *   @0x12cc34 b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x12cc38 bl 0x218348 <_Z13Audio_GetNamei>
 *   @0x12cc3c mov r1, r0
 *   @0x12cc40 mov r0, r4
 *   @0x12cc44 pop {r4, lr}
 *   @0x12cc48 b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x12cc4c eoreq r2, r12, r12, lsl r1
 *
 * ══ §60/373 F_AudioExists(RValue&, CInstance*, CInstance*, int, RValue*)  0x134e30  size 84  21 条（0x134e30..0x134e84）
 * @func 0x134e30 0x134e84  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Audio_Exists(int)
 * 字段偏移 top8: 0x40×1 / 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x134e30 push {r3, r4, r5, lr}
 *   @0x134e34 mov r5, r0
 *   @0x134e38 ldr r3, [pc, #0x40]
 *   @0x134e3c ldr r3, [pc, r3]
 *   @0x134e40 ldrb r4, [r3]
 *   @0x134e44 cmp r4, #0
 *   @0x134e48 popne {r3, r4, r5, pc}
 *   @0x134e4c str r4, [r0, #0xc]
 *   @0x134e50 mov r1, r4
 *   @0x134e54 ldr r0, [sp, #0x10]
 *   @0x134e58 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x134e5c bl 0x217260 <_Z12Audio_Existsi>
 *   @0x134e60 cmp r0, #0
 *   @0x134e64 strne r4, [r5]
 *   @0x134e68 streq r0, [r5]
 *   @0x134e6c movne r3, #0
 *   @0x134e70 streq r0, [r5, #0x4]
 *   @0x134e74 movtne r3, #0x3ff0
 *   @0x134e78 strne r3, [r5, #0x4]
 *   @0x134e7c pop {r3, r4, r5, pc}
 *   @0x134e80 eoreq r10, r11, r0, lsl r2
 *
 * ══ §61/373 F_AudioIsPaused(RValue&, CInstance*, CInstance*, int, RValue*)  0x134ed0  size 84  21 条（0x134ed0..0x134f24）
 * @func 0x134ed0 0x134f38  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Audio_SoundIsPaused(int)
 * 字段偏移 top8: 0x40×1 / 0xc×1 / 0x10×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x134ed0 push {r3, r4, r5, lr}
 *   @0x134ed4 mov r5, r0
 *   @0x134ed8 ldr r3, [pc, #0x40]
 *   @0x134edc ldr r3, [pc, r3]
 *   @0x134ee0 ldrb r4, [r3]
 *   @0x134ee4 cmp r4, #0
 *   @0x134ee8 popne {r3, r4, r5, pc}
 *   @0x134eec str r4, [r0, #0xc]
 *   @0x134ef0 mov r1, r4
 *   @0x134ef4 ldr r0, [sp, #0x10]
 *   @0x134ef8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x134efc bl 0x217098 <_Z19Audio_SoundIsPausedi>
 *   @0x134f00 cmp r0, #0
 *   @0x134f04 moveq r4, r0
 *   @0x134f08 movne r3, #0
 *   @0x134f0c moveq r3, r4
 *   @0x134f10 movtne r3, #0x3ff0
 *   @0x134f14 str r4, [r5]
 *   @0x134f18 str r3, [r5, #0x4]
 *   @0x134f1c pop {r3, r4, r5, pc}
 *   @0x134f20 eoreq r10, r11, r0, ror r1
 *
 * ══ §62/373 F_PhysicsFixtureSetChainShape(RValue&, CInstance*, CInstance*, int, RValue*)  0x14bb2c  size 84  21 条（0x14bb2c..0x14bb80）
 * @func 0x14bb2c 0x14bb94  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CPhysicsFixtureFactory::FindFixture(unsigned int) / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x10×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14bb2c push {r3, r4, r5, lr}
 *   @0x14bb30 mov r1, #0
 *   @0x14bb34 ldr r4, [sp, #0x10]
 *   @0x14bb38 mov r0, r4
 *   @0x14bb3c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14bb40 bl 0x236404 <_ZN22CPhysicsFixtureFactory11FindFixtureEj>
 *   @0x14bb44 subs r5, r0, #0
 *   @0x14bb48 beq 0x14bb68 <_Z29F_PhysicsFixtureSetChainShapeR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x14bb4c mov r0, r4
 *   @0x14bb50 mov r1, #1
 *   @0x14bb54 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x14bb58 mov r1, r0
 *   @0x14bb5c mov r0, r5
 *   @0x14bb60 pop {r3, r4, r5, lr}
 *   @0x14bb64 b 0x236964 <_ZN15CPhysicsFixture13SetChainShapeEb>
 *   @0x14bb68 ldr r0, [pc, #0xc]
 *   @0x14bb6c mov r1, r5
 *   @0x14bb70 pop {r3, r4, r5, lr}
 *   @0x14bb74 add r0, pc, r0
 *   @0x14bb78 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14bb7c andseq r8, pc, r4, lsr r2
 *
 * ══ §63/373 F_PhysicsJointEnableMotor(RValue&, CInstance*, CInstance*, int, RValue*)  0x14bb80  size 84  21 条（0x14bb80..0x14bbd4）
 * @func 0x14bb80 0x14bbd4  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CPhysicsJointFactory::FindJoint(unsigned int) / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x10×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14bb80 push {r3, r4, r5, lr}
 *   @0x14bb84 mov r1, #0
 *   @0x14bb88 ldr r4, [sp, #0x10]
 *   @0x14bb8c mov r0, r4
 *   @0x14bb90 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14bb94 bl 0x23b374 <_ZN20CPhysicsJointFactory9FindJointEj>
 *   @0x14bb98 subs r5, r0, #0
 *   @0x14bb9c beq 0x14bbbc <_Z25F_PhysicsJointEnableMotorR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x14bba0 mov r0, r4
 *   @0x14bba4 mov r1, #1
 *   @0x14bba8 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x14bbac mov r1, r0
 *   @0x14bbb0 mov r0, r5
 *   @0x14bbb4 pop {r3, r4, r5, lr}
 *   @0x14bbb8 b 0x23b534 <_ZN13CPhysicsJoint11EnableMotorEb>
 *   @0x14bbbc ldr r0, [pc, #0xc]
 *   @0x14bbc0 mov r1, r5
 *   @0x14bbc4 pop {r3, r4, r5, lr}
 *   @0x14bbc8 add r0, pc, r0
 *   @0x14bbcc b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14bbd0 andseq r8, pc, r4, lsl #4
 *
 * ══ §64/373 F_PhysicsDeleteJoint(RValue&, CInstance*, CInstance*, int, RValue*)  0x14d098  size 84  21 条（0x14d098..0x14d0ec）
 * @func 0x14d098 0x14d0ec  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x44×1 / 0x8×1 / 0xb4×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14d098 ldr r3, [pc, #0x44]
 *   @0x14d09c push {r4, lr}
 *   @0x14d0a0 ldr r3, [pc, r3]
 *   @0x14d0a4 ldr r0, [sp, #0x8]
 *   @0x14d0a8 ldr r3, [r3]
 *   @0x14d0ac ldr r4, [r3, #0xb4]
 *   @0x14d0b0 cmp r4, #0
 *   @0x14d0b4 beq 0x14d0d0 <_Z20F_PhysicsDeleteJointR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x14d0b8 mov r1, #0
 *   @0x14d0bc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14d0c0 mov r1, r0
 *   @0x14d0c4 mov r0, r4
 *   @0x14d0c8 pop {r4, lr}
 *   @0x14d0cc b 0x237f90 <_ZN13CPhysicsWorld11DeleteJointEi>
 *   @0x14d0d0 ldr r0, [pc, #0x10]
 *   @0x14d0d4 mov r1, r4
 *   @0x14d0d8 pop {r4, lr}
 *   @0x14d0dc add r0, pc, r0
 *   @0x14d0e0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14d0e4 eoreq r0, r10, r8, lsl #17
 *   @0x14d0e8 andseq r6, pc, r8, asr #26
 *
 * ══ §65/373 F_YoYo_FacebookLogin(RValue&, CInstance*, CInstance*, int, RValue*)  0x15723c  size 84  21 条（0x15723c..0x157290）
 * @func 0x15723c 0x157290  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / FacebookLoginM(int, int)
 * 字段偏移 top8: 0x10×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15723c push {r4, r5, r6, lr}
 *   @0x157240 mov r1, #0
 *   @0x157244 ldr r5, [sp, #0x10]
 *   @0x157248 mov r4, r0
 *   @0x15724c str r1, [r0, #0xc]
 *   @0x157250 mov r0, r5
 *   @0x157254 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x157258 mov r1, #1
 *   @0x15725c mov r6, r0
 *   @0x157260 mov r0, r5
 *   @0x157264 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x157268 mov r1, r0
 *   @0x15726c mov r0, r6
 *   @0x157270 bl 0x15f67c <_Z14FacebookLoginMii>
 *   @0x157274 vmov s15, r0
 *   @0x157278 vcvt.f64.s32 d7, s15
 *   @0x15727c vmov r0, r1, d7
 *   @0x157280 vmov r2, s14
 *   @0x157284 mov r3, r1
 *   @0x157288 stm r4, {r2, r3}
 *   @0x15728c pop {r4, r5, r6, pc}
 *
 * ══ §66/373 GR_3D_Transform_Stack_Pop()  0x163b7c  size 84  21 条（0x163b7c..0x163bd0）
 * @func 0x163b7c 0x163bd0  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_3D_Transform_Stack_Pop()+0x44 / Graphics::SetMatrix(eMatrix, float*) / DirtyRoomExtents()
 * 字段偏移 top8: 0x40×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x163b7c push {r4, lr}
 *   @0x163b80 ldr r4, [pc, #0x40]
 *   @0x163b84 ldr r4, [pc, r4]
 *   @0x163b88 ldr r3, [r4]
 *   @0x163b8c cmp r3, #0
 *   @0x163b90 blt 0x163bc0 <_Z25GR_3D_Transform_Stack_Popv+0x44>
 *   @0x163b94 ldr r1, [pc, #0x30]
 *   @0x163b98 mov r0, #2
 *   @0x163b9c ldr r1, [pc, r1]
 *   @0x163ba0 add r1, r1, r3, lsl #6
 *   @0x163ba4 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf>
 *   @0x163ba8 bl 0x168d7c <_Z16DirtyRoomExtentsv>
 *   @0x163bac ldr r3, [r4]
 *   @0x163bb0 mov r0, #1
 *   @0x163bb4 sub r3, r3, #1
 *   @0x163bb8 str r3, [r4]
 *   @0x163bbc pop {r4, pc}
 *   @0x163bc0 mov r0, #0
 *   @0x163bc4 pop {r4, pc}
 *   @0x163bc8 eoreq r12, r8, r0, ror #10
 *   @0x163bcc eoreq r12, r8, r12, asr #10
 *
 * ══ §67/373 SerializeMatrix(yyMatrix*, IBuffer*)  0x16e45c  size 84  21 条（0x16e45c..0x16e4b0）
 * @func 0x16e45c 0x16e4b0  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x38×1 / 0x30×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16e45c push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x16e460 add r10, r1, #44
 *   @0x16e464 mov r6, r1
 *   @0x16e468 mov r8, r0
 *   @0x16e46c mov r7, #16
 *   @0x16e470 mov r9, #0
 *   @0x16e474 vldmia r8!, {s15}
 *   @0x16e478 vcvt.f64.f32 d6, s15
 *   @0x16e47c ldr r3, [r6]
 *   @0x16e480 mov r0, r6
 *   @0x16e484 str r9, [r6, #0x38]
 *   @0x16e488 mov r1, #8
 *   @0x16e48c mov r2, r10
 *   @0x16e490 vmov r4, r5, d6
 *   @0x16e494 vstr s12, [r6, #44]
 *   @0x16e498 str r5, [r6, #0x30]
 *   @0x16e49c ldr r3, [r3, #0x8]
 *   @0x16e4a0 blx r3
 *   @0x16e4a4 subs r7, r7, #1
 *   @0x16e4a8 bne 0x16e474 <_Z15SerializeMatrixP8yyMatrixP7IBuffer+0x18>
 *   @0x16e4ac pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *
 * ══ §68/373 InvalidateOGLResources()  0x17daa8  size 84  21 条（0x17daa8..0x17dafc）
 * @func 0x17daa8 0x17dafc  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FreeVertexBuilderResources() / FreeTextureResources() / Graphics::TextureFlush(bool) / FreeShaderManagerResources()
 * 字段偏移 top8: 0x3c×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17daa8 push {r4, lr}
 *   @0x17daac bl 0x183d30 <_Z26FreeVertexBuilderResourcesv>
 *   @0x17dab0 ldr r3, [pc, #0x3c]
 *   @0x17dab4 ldr r3, [pc, r3]
 *   @0x17dab8 ldr r3, [r3]
 *   @0x17dabc cmp r3, #1
 *   @0x17dac0 beq 0x17daec <_Z22InvalidateOGLResourcesv+0x44>
 *   @0x17dac4 ldr r4, [pc, #0x2c]
 *   @0x17dac8 bl 0x181190 <_Z20FreeTextureResourcesv>
 *   @0x17dacc mov r3, #1
 *   @0x17dad0 ldr r4, [pc, r4]
 *   @0x17dad4 mov r0, r3
 *   @0x17dad8 strb r3, [r4]
 *   @0x17dadc bl 0x1767d0 <_ZN8Graphics12TextureFlushEb>
 *   @0x17dae0 mov r3, #0
 *   @0x17dae4 strb r3, [r4]
 *   @0x17dae8 pop {r4, pc}
 *   @0x17daec bl 0x187fa8 <_Z26FreeShaderManagerResourcesv>
 *   @0x17daf0 b 0x17dac4 <_Z22InvalidateOGLResourcesv+0x1c>
 *   @0x17daf4 eoreq r2, r7, r4, asr r9
 *   @0x17daf8 eoreq r2, r7, r12, ror #18
 *
 * ══ §69/373 GLError(char*)  0x17df5c  size 84  21 条（0x17df5c..0x17dfb0）
 * @func 0x17df5c 0x17dfb0  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x40×1 / 0x24×1 / 0x20×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17df5c ldr r3, [pc, #0x40]
 *   @0x17df60 push {r4, lr}
 *   @0x17df64 ldr r3, [pc, r3]
 *   @0x17df68 mov r4, r0
 *   @0x17df6c ldr r3, [r3]
 *   @0x17df70 blx r3
 *   @0x17df74 subs r3, r0, #0
 *   @0x17df78 popeq {r4, pc}
 *   @0x17df7c ldr r12, [pc, #0x24]
 *   @0x17df80 mov r2, r4
 *   @0x17df84 ldr r1, [pc, #0x20]
 *   @0x17df88 ldr r12, [pc, r12]
 *   @0x17df8c add r1, pc, r1
 *   @0x17df90 ldr r0, [r12]
 *   @0x17df94 ldr r12, [r0]
 *   @0x17df98 ldr r12, [r12, #0xc]
 *   @0x17df9c blx r12
 *   @0x17dfa0 pop {r4, pc}
 *   @0x17dfa4 eoreq pc, r6, r8, asr #15
 *   @0x17dfa8 eoreq pc, r6, r12, lsl #15
 *   @0x17dfac mulseq r12, r12, r9
 *
 * ══ §70/373 Graphics::SetTextureBlending(bool)  0x1836d8  size 84  21 条（0x1836d8..0x18372c）
 * @func 0x1836d8 0x18372c  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1836e0→0x3f26dc, 0x1836f8→0x479ba4
 * 调用序列: 无
 * 字段偏移 top8: 0x3c×2 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1836d8 push {r3, lr}
 *   @0x1836dc ldr r3, [pc, #0x3c]
 *   @0x1836e0 ldr r2, [pc, #0x3c]
 *   @0x1836e4 add r3, pc, r3
 *   @0x1836e8 ldr r2, [r3, r2]
 *   @0x1836ec ldr r2, [r2]
 *   @0x1836f0 cmp r2, #0
 *   @0x1836f4 popne {r3, pc}
 *   @0x1836f8 ldr r12, [pc, #0x28]
 *   @0x1836fc cmp r0, #0
 *   @0x183700 mov r1, #8704
 *   @0x183704 mov r0, #8960
 *   @0x183708 movne r2, #8448
 *   @0x18370c movweq r2, #0x1e01
 *   @0x183710 ldr r3, [r3, r12]
 *   @0x183714 ldr r3, [r3]
 *   @0x183718 blx r3
 *   @0x18371c pop {r3, pc}
 *   @0x183720 eoreq lr, r6, r12, ror #10
 *   @0x183724 .word 0xffffe7b8
 *   @0x183728 .word 0xffffbca0
 *
 * ══ §71/373 DeleteVertexBuilderResources()  0x183d34  size 84  21 条（0x183d34..0x183d88）
 * @func 0x183d34 0x183d88  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f28b0
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65b0×3
 * 字段偏移 top8: 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x183d34 push {r4, lr}
 *   @0x183d38 mvn r1, #0
 *   @0x183d3c ldr r4, [pc, #0x40]
 *   @0x183d40 mov r2, #16
 *   @0x183d44 add r4, pc, r4
 *   @0x183d48 mov r0, r4
 *   @0x183d4c bl 0xb65b0 <memset@plt>
 *   @0x183d50 add r0, r4, #16
 *   @0x183d54 mvn r1, #0
 *   @0x183d58 mov r2, #16
 *   @0x183d5c bl 0xb65b0 <memset@plt>
 *   @0x183d60 add r0, r4, #32
 *   @0x183d64 mvn r1, #0
 *   @0x183d68 mov r2, #64
 *   @0x183d6c bl 0xb65b0 <memset@plt>
 *   @0x183d70 add r0, r4, #96
 *   @0x183d74 mvn r1, #0
 *   @0x183d78 mov r2, #16
 *   @0x183d7c pop {r4, lr}
 *   @0x183d80 b 0xb65b0 <memset@plt>
 *   @0x183d84 eoreq lr, r6, r4, ror #22
 *
 * ══ §72/373 ValueToButton(char const*)  0x18c53c  size 84  21 条（0x18c53c..0x18c590）
 * @func 0x18c53c 0x18c590  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Code_Constant_Find_IgnoreCase(char const*)
 * 字段偏移 top8: 0x1×1 / 0x2×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18c53c push {r3, lr}
 *   @0x18c540 ldrb r2, [r0]
 *   @0x18c544 cmp r2, #77
 *   @0x18c548 beq 0x18c554 <_Z13ValueToButtonPKc+0x18>
 *   @0x18c54c mov r0, #0
 *   @0x18c550 pop {r3, pc}
 *   @0x18c554 ldrb r2, [r0, #0x1]
 *   @0x18c558 cmp r2, #66
 *   @0x18c55c bne 0x18c54c <_Z13ValueToButtonPKc+0x10>
 *   @0x18c560 ldrb r3, [r0, #0x2]
 *   @0x18c564 cmp r3, #95
 *   @0x18c568 bne 0x18c54c <_Z13ValueToButtonPKc+0x10>
 *   @0x18c56c bl 0xedc8c <_Z29Code_Constant_Find_IgnoreCasePKc>
 *   @0x18c570 cmp r0, #0
 *   @0x18c574 beq 0x18c54c <_Z13ValueToButtonPKc+0x10>
 *   @0x18c578 ldm r0, {r2, r3}
 *   @0x18c57c vmov d7, r2, r3
 *   @0x18c580 vcvt.u32.f64 s15, d7
 *   @0x18c584 vmov r2, s15
 *   @0x18c588 uxtb r0, r2
 *   @0x18c58c pop {r3, pc}
 *
 * ══ §73/373 ParticleType_Orientation(int, float, float, float, float, bool)  0x1a3400  size 84  21 条（0x1a3400..0x1a3454）
 * @func 0x1a3400 0x1a3454  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleType_Exists(int)
 * 字段偏移 top8: 0x1c×1 / 0x24×1 / 0x4×1 / 0x2×1 / 0x64×1 / 0x68×1 / 0x6c×1 / 0x74×1
 * VFP 指令 2 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a3400 push {r4, r5, r6, r7, r8, lr}
 *   @0x1a3404 mov r8, r1
 *   @0x1a3408 mov r7, r2
 *   @0x1a340c mov r5, r0
 *   @0x1a3410 mov r6, r3
 *   @0x1a3414 ldrb r4, [sp, #0x1c]
 *   @0x1a3418 bl 0x1a2e14 <_Z19ParticleType_Existsi>
 *   @0x1a341c cmp r0, #0
 *   @0x1a3420 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x1a3424 ldr r12, [pc, #0x24]
 *   @0x1a3428 vldr s15, [sp, #24]
 *   @0x1a342c ldr r12, [pc, r12]
 *   @0x1a3430 ldr r3, [r12, #0x4]
 *   @0x1a3434 ldr r0, [r3, r5, lsl #2]
 *   @0x1a3438 vstr s15, [r0, #112]
 *   @0x1a343c str r8, [r0, #0x64]
 *   @0x1a3440 str r7, [r0, #0x68]
 *   @0x1a3444 str r6, [r0, #0x6c]
 *   @0x1a3448 strb r4, [r0, #0x74]
 *   @0x1a344c pop {r4, r5, r6, r7, r8, pc}
 *   @0x1a3450 eoreq sp, r4, r0, lsl #7
 *
 * ══ §74/373 ParticleType_Alpha2(int, float, float)  0x1a36a4  size 84  21 条（0x1a36a4..0x1a36f8）
 * @func 0x1a36a4 0x1a36f8  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleType_Exists(int)
 * 字段偏移 top8: 0x24×1 / 0x4×1 / 0x2×1
 * VFP 指令 10 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a36a4 push {r4, lr}
 *   @0x1a36a8 vpush {d8}
 *   @0x1a36ac mov r4, r0
 *   @0x1a36b0 vmov s17, r1
 *   @0x1a36b4 vmov s16, r2
 *   @0x1a36b8 bl 0x1a2e14 <_Z19ParticleType_Existsi>
 *   @0x1a36bc cmp r0, #0
 *   @0x1a36c0 beq 0x1a36ec <_Z19ParticleType_Alpha2iff+0x48>
 *   @0x1a36c4 vadd.f32 s14, s17, s16
 *   @0x1a36c8 ldr r3, [pc, #0x24]
 *   @0x1a36cc ldr r3, [pc, r3]
 *   @0x1a36d0 ldr r3, [r3, #0x4]
 *   @0x1a36d4 ldr r3, [r3, r4, lsl #2]
 *   @0x1a36d8 vstr s17, [r3, #148]
 *   @0x1a36dc vstr s16, [r3, #156]
 *   @0x1a36e0 vmov.f32 s15, #5.000000e-01
 *   @0x1a36e4 vmul.f32 s15, s14, s15
 *   @0x1a36e8 vstr s15, [r3, #152]
 *   @0x1a36ec vpop {d8}
 *   @0x1a36f0 pop {r4, pc}
 *   @0x1a36f4 eoreq sp, r4, r0, ror #1
 *
 * ══ §75/373 PatchArray(unsigned char*, unsigned char*)  0x1ddc80  size 84  21 条（0x1ddc80..0x1ddcd4）
 * @func 0x1ddc80 0x1ddcd4  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYPATCH(void*, void*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1ddc80 push {r3, r4, r5, r6, r7, lr}
 *   @0x1ddc84 mov r7, r1
 *   @0x1ddc88 ldr r6, [r0]
 *   @0x1ddc8c cmp r6, #0
 *   @0x1ddc90 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1ddc94 add r5, r0, #4
 *   @0x1ddc98 mov r4, #0
 *   @0x1ddc9c b 0x1ddca8 <_Z10PatchArrayPhS_+0x28>
 *   @0x1ddca0 cmp r4, r6
 *   @0x1ddca4 beq 0x1ddcd0 <_Z10PatchArrayPhS_+0x50>
 *   @0x1ddca8 ldr r3, [r5]
 *   @0x1ddcac mov r0, r5
 *   @0x1ddcb0 add r4, r4, #1
 *   @0x1ddcb4 add r5, r5, #4
 *   @0x1ddcb8 cmp r3, #0
 *   @0x1ddcbc beq 0x1ddca0 <_Z10PatchArrayPhS_+0x20>
 *   @0x1ddcc0 mov r1, r7
 *   @0x1ddcc4 bl 0x1ddc6c <_Z7YYPATCHPvS_>
 *   @0x1ddcc8 cmp r4, r6
 *   @0x1ddccc bne 0x1ddca8 <_Z10PatchArrayPhS_+0x28>
 *   @0x1ddcd0 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §76/373 CScript::Clear()  0x1dfbb0  size 84  21 条（0x1dfbb0..0x1dfc04）
 * @func 0x1dfbb0 0x1dfc04  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::~CStream() / operator delete(void*)
 * 字段偏移 top8: 0x4×3 / 0x8×2 / 0x10×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dfbb0 push {r3, r4, r5, lr}
 *   @0x1dfbb4 mov r4, r0
 *   @0x1dfbb8 ldr r5, [r0, #0x4]
 *   @0x1dfbbc cmp r5, #0
 *   @0x1dfbc0 beq 0x1dfbd4 <_ZN7CScript5ClearEv+0x24>
 *   @0x1dfbc4 mov r0, r5
 *   @0x1dfbc8 bl 0x201328 <_ZN7CStreamD2Ev>
 *   @0x1dfbcc mov r0, r5
 *   @0x1dfbd0 bl 0x27d1d0 <_ZdlPv>
 *   @0x1dfbd4 ldr r0, [r4, #0x8]
 *   @0x1dfbd8 cmp r0, #0
 *   @0x1dfbdc beq 0x1dfbec <_ZN7CScript5ClearEv+0x3c>
 *   @0x1dfbe0 ldr r3, [r0]
 *   @0x1dfbe4 ldr r3, [r3, #0x4]
 *   @0x1dfbe8 blx r3
 *   @0x1dfbec mov r3, #0
 *   @0x1dfbf0 str r3, [r4, #0x8]
 *   @0x1dfbf4 str r3, [r4, #0x4]
 *   @0x1dfbf8 str r3, [r4, #0x10]
 *   @0x1dfbfc str r3, [r4, #0x18]
 *   @0x1dfc00 pop {r3, r4, r5, pc}
 *
 * ══ §77/373 Variable_BuiltIn_Find_Name(int)  0x1f3b38  size 84  21 条（0x1f3b38..0x1f3b8c）
 * @func 0x1f3b38 0x1f3b8c  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Variable_BuiltIn_Find_Name(int)+0x38
 * 字段偏移 top8: 0x34×1 / 0x24×1 / 0x4×1 / 0x18×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f3b38 cmp r0, #0
 *   @0x1f3b3c blt 0x1f3b70 <_Z26Variable_BuiltIn_Find_Namei+0x38>
 *   @0x1f3b40 ldr r3, [pc, #0x34]
 *   @0x1f3b44 ldr r3, [pc, r3]
 *   @0x1f3b48 ldr r3, [r3]
 *   @0x1f3b4c cmp r0, r3
 *   @0x1f3b50 bge 0x1f3b64 <_Z26Variable_BuiltIn_Find_Namei+0x2c>
 *   @0x1f3b54 ldr r3, [pc, #0x24]
 *   @0x1f3b58 ldr r3, [pc, r3]
 *   @0x1f3b5c ldr r0, [r3, r0, lsl #4]
 *   @0x1f3b60 bx lr
 *   @0x1f3b64 ldr r0, [pc, #0x18]
 *   @0x1f3b68 add r0, pc, r0
 *   @0x1f3b6c bx lr
 *   @0x1f3b70 ldr r0, [pc, #0x10]
 *   @0x1f3b74 add r0, pc, r0
 *   @0x1f3b78 bx lr
 *   @0x1f3b7c ldrsheq r10, [pc], -r0
 *   @0x1f3b80 andseq r10, pc, r0, ror #1
 *   @0x1f3b84 andseq lr, r5, r8, asr r12
 *   @0x1f3b88 andseq lr, r5, r12, asr #24
 *
 * ══ §78/373 CVariableList::const_iterator::operator++()  0x1f5050  size 84  21 条（0x1f5050..0x1f50a4）
 * @func 0x1f5050 0x1f50a4  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×3 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f5050 ldr r3, [r0]
 *   @0x1f5054 cmp r3, #0
 *   @0x1f5058 ldrne r3, [r3]
 *   @0x1f505c strne r3, [r0]
 *   @0x1f5060 cmp r3, #0
 *   @0x1f5064 bxne lr
 *   @0x1f5068 ldr r1, [r0, #0x8]
 *   @0x1f506c b 0x1f507c <_ZN13CVariableList14const_iteratorppEv+0x2c>
 *   @0x1f5070 cmp r1, r2
 *   @0x1f5074 str r2, [r0, #0x4]
 *   @0x1f5078 bne 0x1f5090 <_ZN13CVariableList14const_iteratorppEv+0x40>
 *   @0x1f507c ldr r3, [r0, #0x4]
 *   @0x1f5080 cmp r3, r1
 *   @0x1f5084 add r2, r3, #4
 *   @0x1f5088 bne 0x1f5070 <_ZN13CVariableList14const_iteratorppEv+0x20>
 *   @0x1f508c bx lr
 *   @0x1f5090 ldr r3, [r3, #0x4]
 *   @0x1f5094 cmp r3, #0
 *   @0x1f5098 str r3, [r0]
 *   @0x1f509c beq 0x1f5068 <_ZN13CVariableList14const_iteratorppEv+0x18>
 *   @0x1f50a0 bx lr
 *
 * ══ §79/373 GV_BackgroundVisible(CInstance*, int, RValue*)  0x1f7d08  size 84  21 条（0x1f7d08..0x1f7d5c）
 * @func 0x1f7d08 0x1f7d70  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x48×1 / 0xc×1 / 0x24×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f7d08 ldr r3, [pc, #0x48]
 *   @0x1f7d0c cmp r1, #7
 *   @0x1f7d10 push {r4, r5}
 *   @0x1f7d14 ldr r3, [pc, r3]
 *   @0x1f7d18 movhi r1, #0
 *   @0x1f7d1c mov r0, #0
 *   @0x1f7d20 ldr r3, [r3]
 *   @0x1f7d24 str r0, [r2, #0xc]
 *   @0x1f7d28 mov r0, #1
 *   @0x1f7d2c add r1, r3, r1, lsl #2
 *   @0x1f7d30 ldr r3, [r1, #0x24]
 *   @0x1f7d34 ldrb r4, [r3]
 *   @0x1f7d38 vmov s15, r4
 *   @0x1f7d3c vcvt.f64.u32 d7, s15
 *   @0x1f7d40 vmov r4, r5, d7
 *   @0x1f7d44 vmov r1, s14
 *   @0x1f7d48 mov r3, r5
 *   @0x1f7d4c pop {r4, r5}
 *   @0x1f7d50 stm r2, {r1, r3}
 *   @0x1f7d54 bx lr
 *   @0x1f7d58 andseq r5, pc, r4, lsl r12
 *
 * ══ §80/373 GV_BackgroundForeground(CInstance*, int, RValue*)  0x1f7d5c  size 84  21 条（0x1f7d5c..0x1f7db0）
 * @func 0x1f7d5c 0x1f7dc4  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x48×1 / 0xc×1 / 0x24×1 / 0x1×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f7d5c ldr r3, [pc, #0x48]
 *   @0x1f7d60 cmp r1, #7
 *   @0x1f7d64 push {r4, r5}
 *   @0x1f7d68 ldr r3, [pc, r3]
 *   @0x1f7d6c movhi r1, #0
 *   @0x1f7d70 mov r0, #0
 *   @0x1f7d74 ldr r3, [r3]
 *   @0x1f7d78 str r0, [r2, #0xc]
 *   @0x1f7d7c mov r0, #1
 *   @0x1f7d80 add r1, r3, r1, lsl #2
 *   @0x1f7d84 ldr r3, [r1, #0x24]
 *   @0x1f7d88 ldrb r4, [r3, #0x1]
 *   @0x1f7d8c vmov s15, r4
 *   @0x1f7d90 vcvt.f64.u32 d7, s15
 *   @0x1f7d94 vmov r4, r5, d7
 *   @0x1f7d98 vmov r1, s14
 *   @0x1f7d9c mov r3, r5
 *   @0x1f7da0 pop {r4, r5}
 *   @0x1f7da4 stm r2, {r1, r3}
 *   @0x1f7da8 bx lr
 *   @0x1f7dac andseq r5, pc, r0, asr #23
 *
 * ══ §81/373 GV_BackgroundIndex(CInstance*, int, RValue*)  0x1f7db0  size 84  21 条（0x1f7db0..0x1f7e04）
 * @func 0x1f7db0 0x1f7e18  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x48×1 / 0xc×1 / 0x24×1 / 0x4×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f7db0 ldr r3, [pc, #0x48]
 *   @0x1f7db4 cmp r1, #7
 *   @0x1f7db8 push {r4, r5}
 *   @0x1f7dbc ldr r3, [pc, r3]
 *   @0x1f7dc0 movhi r1, #0
 *   @0x1f7dc4 mov r0, #0
 *   @0x1f7dc8 ldr r3, [r3]
 *   @0x1f7dcc str r0, [r2, #0xc]
 *   @0x1f7dd0 mov r0, #1
 *   @0x1f7dd4 add r1, r3, r1, lsl #2
 *   @0x1f7dd8 ldr r3, [r1, #0x24]
 *   @0x1f7ddc ldr r4, [r3, #0x4]
 *   @0x1f7de0 vmov s15, r4
 *   @0x1f7de4 vcvt.f64.s32 d7, s15
 *   @0x1f7de8 vmov r4, r5, d7
 *   @0x1f7dec vmov r1, s14
 *   @0x1f7df0 mov r3, r5
 *   @0x1f7df4 pop {r4, r5}
 *   @0x1f7df8 stm r2, {r1, r3}
 *   @0x1f7dfc bx lr
 *   @0x1f7e00 andseq r5, pc, r12, ror #22
 *
 * ══ §82/373 GV_BackgroundHTiled(CInstance*, int, RValue*)  0x1f7ea4  size 84  21 条（0x1f7ea4..0x1f7ef8）
 * @func 0x1f7ea4 0x1f7f0c  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x48×1 / 0xc×1 / 0x24×1 / 0x10×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f7ea4 ldr r3, [pc, #0x48]
 *   @0x1f7ea8 cmp r1, #7
 *   @0x1f7eac push {r4, r5}
 *   @0x1f7eb0 ldr r3, [pc, r3]
 *   @0x1f7eb4 movhi r1, #0
 *   @0x1f7eb8 mov r0, #0
 *   @0x1f7ebc ldr r3, [r3]
 *   @0x1f7ec0 str r0, [r2, #0xc]
 *   @0x1f7ec4 mov r0, #1
 *   @0x1f7ec8 add r1, r3, r1, lsl #2
 *   @0x1f7ecc ldr r3, [r1, #0x24]
 *   @0x1f7ed0 ldrb r4, [r3, #0x10]
 *   @0x1f7ed4 vmov s15, r4
 *   @0x1f7ed8 vcvt.f64.u32 d7, s15
 *   @0x1f7edc vmov r4, r5, d7
 *   @0x1f7ee0 vmov r1, s14
 *   @0x1f7ee4 mov r3, r5
 *   @0x1f7ee8 pop {r4, r5}
 *   @0x1f7eec stm r2, {r1, r3}
 *   @0x1f7ef0 bx lr
 *   @0x1f7ef4 andseq r5, pc, r8, ror r10
 *
 * ══ §83/373 GV_BackgroundVTiled(CInstance*, int, RValue*)  0x1f7ef8  size 84  21 条（0x1f7ef8..0x1f7f4c）
 * @func 0x1f7ef8 0x1f7f60  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x48×1 / 0xc×1 / 0x24×1 / 0x11×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f7ef8 ldr r3, [pc, #0x48]
 *   @0x1f7efc cmp r1, #7
 *   @0x1f7f00 push {r4, r5}
 *   @0x1f7f04 ldr r3, [pc, r3]
 *   @0x1f7f08 movhi r1, #0
 *   @0x1f7f0c mov r0, #0
 *   @0x1f7f10 ldr r3, [r3]
 *   @0x1f7f14 str r0, [r2, #0xc]
 *   @0x1f7f18 mov r0, #1
 *   @0x1f7f1c add r1, r3, r1, lsl #2
 *   @0x1f7f20 ldr r3, [r1, #0x24]
 *   @0x1f7f24 ldrb r4, [r3, #0x11]
 *   @0x1f7f28 vmov s15, r4
 *   @0x1f7f2c vcvt.f64.u32 d7, s15
 *   @0x1f7f30 vmov r4, r5, d7
 *   @0x1f7f34 vmov r1, s14
 *   @0x1f7f38 mov r3, r5
 *   @0x1f7f3c pop {r4, r5}
 *   @0x1f7f40 stm r2, {r1, r3}
 *   @0x1f7f44 bx lr
 *   @0x1f7f48 andseq r5, pc, r4, lsr #20
 *
 * ══ §84/373 GV_BackgroundBlend(CInstance*, int, RValue*)  0x1f808c  size 84  21 条（0x1f808c..0x1f80e0）
 * @func 0x1f808c 0x1f80f4  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x24×2 / 0x48×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f808c ldr r3, [pc, #0x48]
 *   @0x1f8090 cmp r1, #7
 *   @0x1f8094 push {r4, r5}
 *   @0x1f8098 ldr r3, [pc, r3]
 *   @0x1f809c movhi r1, #0
 *   @0x1f80a0 mov r0, #0
 *   @0x1f80a4 ldr r3, [r3]
 *   @0x1f80a8 str r0, [r2, #0xc]
 *   @0x1f80ac mov r0, #1
 *   @0x1f80b0 add r1, r3, r1, lsl #2
 *   @0x1f80b4 ldr r3, [r1, #0x24]
 *   @0x1f80b8 ldr r4, [r3, #0x24]
 *   @0x1f80bc vmov s15, r4
 *   @0x1f80c0 vcvt.f64.s32 d7, s15
 *   @0x1f80c4 vmov r4, r5, d7
 *   @0x1f80c8 vmov r1, s14
 *   @0x1f80cc mov r3, r5
 *   @0x1f80d0 pop {r4, r5}
 *   @0x1f80d4 stm r2, {r1, r3}
 *   @0x1f80d8 bx lr
 *   @0x1f80dc mulseq pc, r0, r8
 *
 * ══ §85/373 GV_ViewVisible(CInstance*, int, RValue*)  0x1f81b4  size 84  21 条（0x1f81b4..0x1f8208）
 * @func 0x1f81b4 0x1f821c  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x48×1 / 0xc×1 / 0x2×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f81b4 ldr r3, [pc, #0x48]
 *   @0x1f81b8 cmp r1, #7
 *   @0x1f81bc push {r4, r5}
 *   @0x1f81c0 ldr r3, [pc, r3]
 *   @0x1f81c4 movhi r1, #0
 *   @0x1f81c8 add r1, r1, #18
 *   @0x1f81cc ldr r3, [r3]
 *   @0x1f81d0 mov r12, #0
 *   @0x1f81d4 mov r0, #1
 *   @0x1f81d8 str r12, [r2, #0xc]
 *   @0x1f81dc ldr r3, [r3, r1, lsl #2]
 *   @0x1f81e0 ldrb r4, [r3]
 *   @0x1f81e4 vmov s15, r4
 *   @0x1f81e8 vcvt.f64.u32 d7, s15
 *   @0x1f81ec vmov r4, r5, d7
 *   @0x1f81f0 vmov r1, s14
 *   @0x1f81f4 mov r3, r5
 *   @0x1f81f8 pop {r4, r5}
 *   @0x1f81fc stm r2, {r1, r3}
 *   @0x1f8200 bx lr
 *   @0x1f8204 andseq r5, pc, r8, ror #14
 *
 * ══ §86/373 GV_ViewXport(CInstance*, int, RValue*)  0x1f8348  size 84  21 条（0x1f8348..0x1f839c）
 * @func 0x1f8348 0x1f83b0  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x48×1 / 0xc×1 / 0x2×1 / 0x14×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f8348 ldr r3, [pc, #0x48]
 *   @0x1f834c cmp r1, #7
 *   @0x1f8350 push {r4, r5}
 *   @0x1f8354 ldr r3, [pc, r3]
 *   @0x1f8358 movhi r1, #0
 *   @0x1f835c add r1, r1, #18
 *   @0x1f8360 ldr r3, [r3]
 *   @0x1f8364 mov r12, #0
 *   @0x1f8368 mov r0, #1
 *   @0x1f836c str r12, [r2, #0xc]
 *   @0x1f8370 ldr r3, [r3, r1, lsl #2]
 *   @0x1f8374 ldr r4, [r3, #0x14]
 *   @0x1f8378 vmov s15, r4
 *   @0x1f837c vcvt.f64.s32 d7, s15
 *   @0x1f8380 vmov r4, r5, d7
 *   @0x1f8384 vmov r1, s14
 *   @0x1f8388 mov r3, r5
 *   @0x1f838c pop {r4, r5}
 *   @0x1f8390 stm r2, {r1, r3}
 *   @0x1f8394 bx lr
 *   @0x1f8398 ldrsbeq r5, [pc], -r4
 *
 * ══ §87/373 GV_ViewYport(CInstance*, int, RValue*)  0x1f839c  size 84  21 条（0x1f839c..0x1f83f0）
 * @func 0x1f839c 0x1f8404  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x48×1 / 0xc×1 / 0x2×1 / 0x18×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f839c ldr r3, [pc, #0x48]
 *   @0x1f83a0 cmp r1, #7
 *   @0x1f83a4 push {r4, r5}
 *   @0x1f83a8 ldr r3, [pc, r3]
 *   @0x1f83ac movhi r1, #0
 *   @0x1f83b0 add r1, r1, #18
 *   @0x1f83b4 ldr r3, [r3]
 *   @0x1f83b8 mov r12, #0
 *   @0x1f83bc mov r0, #1
 *   @0x1f83c0 str r12, [r2, #0xc]
 *   @0x1f83c4 ldr r3, [r3, r1, lsl #2]
 *   @0x1f83c8 ldr r4, [r3, #0x18]
 *   @0x1f83cc vmov s15, r4
 *   @0x1f83d0 vcvt.f64.s32 d7, s15
 *   @0x1f83d4 vmov r4, r5, d7
 *   @0x1f83d8 vmov r1, s14
 *   @0x1f83dc mov r3, r5
 *   @0x1f83e0 pop {r4, r5}
 *   @0x1f83e4 stm r2, {r1, r3}
 *   @0x1f83e8 bx lr
 *   @0x1f83ec andseq r5, pc, r0, lsl #11
 *
 * ══ §88/373 GV_ViewWport(CInstance*, int, RValue*)  0x1f83f0  size 84  21 条（0x1f83f0..0x1f8444）
 * @func 0x1f83f0 0x1f8458  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x48×1 / 0xc×1 / 0x2×1 / 0x1c×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f83f0 ldr r3, [pc, #0x48]
 *   @0x1f83f4 cmp r1, #7
 *   @0x1f83f8 push {r4, r5}
 *   @0x1f83fc ldr r3, [pc, r3]
 *   @0x1f8400 movhi r1, #0
 *   @0x1f8404 add r1, r1, #18
 *   @0x1f8408 ldr r3, [r3]
 *   @0x1f840c mov r12, #0
 *   @0x1f8410 mov r0, #1
 *   @0x1f8414 str r12, [r2, #0xc]
 *   @0x1f8418 ldr r3, [r3, r1, lsl #2]
 *   @0x1f841c ldr r4, [r3, #0x1c]
 *   @0x1f8420 vmov s15, r4
 *   @0x1f8424 vcvt.f64.s32 d7, s15
 *   @0x1f8428 vmov r4, r5, d7
 *   @0x1f842c vmov r1, s14
 *   @0x1f8430 mov r3, r5
 *   @0x1f8434 pop {r4, r5}
 *   @0x1f8438 stm r2, {r1, r3}
 *   @0x1f843c bx lr
 *   @0x1f8440 andseq r5, pc, r12, lsr #10
 *
 * ══ §89/373 GV_ViewHport(CInstance*, int, RValue*)  0x1f8444  size 84  21 条（0x1f8444..0x1f8498）
 * @func 0x1f8444 0x1f84ac  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x48×1 / 0xc×1 / 0x2×1 / 0x20×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f8444 ldr r3, [pc, #0x48]
 *   @0x1f8448 cmp r1, #7
 *   @0x1f844c push {r4, r5}
 *   @0x1f8450 ldr r3, [pc, r3]
 *   @0x1f8454 movhi r1, #0
 *   @0x1f8458 add r1, r1, #18
 *   @0x1f845c ldr r3, [r3]
 *   @0x1f8460 mov r12, #0
 *   @0x1f8464 mov r0, #1
 *   @0x1f8468 str r12, [r2, #0xc]
 *   @0x1f846c ldr r3, [r3, r1, lsl #2]
 *   @0x1f8470 ldr r4, [r3, #0x20]
 *   @0x1f8474 vmov s15, r4
 *   @0x1f8478 vcvt.f64.s32 d7, s15
 *   @0x1f847c vmov r4, r5, d7
 *   @0x1f8480 vmov r1, s14
 *   @0x1f8484 mov r3, r5
 *   @0x1f8488 pop {r4, r5}
 *   @0x1f848c stm r2, {r1, r3}
 *   @0x1f8490 bx lr
 *   @0x1f8494 ldrsbeq r5, [pc], -r8
 *
 * ══ §90/373 GV_ViewHBorder(CInstance*, int, RValue*)  0x1f84e8  size 84  21 条（0x1f84e8..0x1f853c）
 * @func 0x1f84e8 0x1f8550  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x48×1 / 0xc×1 / 0x2×1 / 0x28×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f84e8 ldr r3, [pc, #0x48]
 *   @0x1f84ec cmp r1, #7
 *   @0x1f84f0 push {r4, r5}
 *   @0x1f84f4 ldr r3, [pc, r3]
 *   @0x1f84f8 movhi r1, #0
 *   @0x1f84fc add r1, r1, #18
 *   @0x1f8500 ldr r3, [r3]
 *   @0x1f8504 mov r12, #0
 *   @0x1f8508 mov r0, #1
 *   @0x1f850c str r12, [r2, #0xc]
 *   @0x1f8510 ldr r3, [r3, r1, lsl #2]
 *   @0x1f8514 ldr r4, [r3, #0x28]
 *   @0x1f8518 vmov s15, r4
 *   @0x1f851c vcvt.f64.s32 d7, s15
 *   @0x1f8520 vmov r4, r5, d7
 *   @0x1f8524 vmov r1, s14
 *   @0x1f8528 mov r3, r5
 *   @0x1f852c pop {r4, r5}
 *   @0x1f8530 stm r2, {r1, r3}
 *   @0x1f8534 bx lr
 *   @0x1f8538 andseq r5, pc, r4, lsr r4
 *
 * ══ §91/373 GV_ViewVBorder(CInstance*, int, RValue*)  0x1f853c  size 84  21 条（0x1f853c..0x1f8590）
 * @func 0x1f853c 0x1f85a4  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x48×1 / 0xc×1 / 0x2×1 / 0x2c×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f853c ldr r3, [pc, #0x48]
 *   @0x1f8540 cmp r1, #7
 *   @0x1f8544 push {r4, r5}
 *   @0x1f8548 ldr r3, [pc, r3]
 *   @0x1f854c movhi r1, #0
 *   @0x1f8550 add r1, r1, #18
 *   @0x1f8554 ldr r3, [r3]
 *   @0x1f8558 mov r12, #0
 *   @0x1f855c mov r0, #1
 *   @0x1f8560 str r12, [r2, #0xc]
 *   @0x1f8564 ldr r3, [r3, r1, lsl #2]
 *   @0x1f8568 ldr r4, [r3, #0x2c]
 *   @0x1f856c vmov s15, r4
 *   @0x1f8570 vcvt.f64.s32 d7, s15
 *   @0x1f8574 vmov r4, r5, d7
 *   @0x1f8578 vmov r1, s14
 *   @0x1f857c mov r3, r5
 *   @0x1f8580 pop {r4, r5}
 *   @0x1f8584 stm r2, {r1, r3}
 *   @0x1f8588 bx lr
 *   @0x1f858c andseq r5, pc, r0, ror #7
 *
 * ══ §92/373 GV_ViewHSpeed(CInstance*, int, RValue*)  0x1f8590  size 84  21 条（0x1f8590..0x1f85e4）
 * @func 0x1f8590 0x1f85f8  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x48×1 / 0xc×1 / 0x2×1 / 0x30×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f8590 ldr r3, [pc, #0x48]
 *   @0x1f8594 cmp r1, #7
 *   @0x1f8598 push {r4, r5}
 *   @0x1f859c ldr r3, [pc, r3]
 *   @0x1f85a0 movhi r1, #0
 *   @0x1f85a4 add r1, r1, #18
 *   @0x1f85a8 ldr r3, [r3]
 *   @0x1f85ac mov r12, #0
 *   @0x1f85b0 mov r0, #1
 *   @0x1f85b4 str r12, [r2, #0xc]
 *   @0x1f85b8 ldr r3, [r3, r1, lsl #2]
 *   @0x1f85bc ldr r4, [r3, #0x30]
 *   @0x1f85c0 vmov s15, r4
 *   @0x1f85c4 vcvt.f64.s32 d7, s15
 *   @0x1f85c8 vmov r4, r5, d7
 *   @0x1f85cc vmov r1, s14
 *   @0x1f85d0 mov r3, r5
 *   @0x1f85d4 pop {r4, r5}
 *   @0x1f85d8 stm r2, {r1, r3}
 *   @0x1f85dc bx lr
 *   @0x1f85e0 andseq r5, pc, r12, lsl #7
 *
 * ══ §93/373 GV_ViewVspeed(CInstance*, int, RValue*)  0x1f85e4  size 84  21 条（0x1f85e4..0x1f8638）
 * @func 0x1f85e4 0x1f864c  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x48×1 / 0xc×1 / 0x2×1 / 0x34×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f85e4 ldr r3, [pc, #0x48]
 *   @0x1f85e8 cmp r1, #7
 *   @0x1f85ec push {r4, r5}
 *   @0x1f85f0 ldr r3, [pc, r3]
 *   @0x1f85f4 movhi r1, #0
 *   @0x1f85f8 add r1, r1, #18
 *   @0x1f85fc ldr r3, [r3]
 *   @0x1f8600 mov r12, #0
 *   @0x1f8604 mov r0, #1
 *   @0x1f8608 str r12, [r2, #0xc]
 *   @0x1f860c ldr r3, [r3, r1, lsl #2]
 *   @0x1f8610 ldr r4, [r3, #0x34]
 *   @0x1f8614 vmov s15, r4
 *   @0x1f8618 vcvt.f64.s32 d7, s15
 *   @0x1f861c vmov r4, r5, d7
 *   @0x1f8620 vmov r1, s14
 *   @0x1f8624 mov r3, r5
 *   @0x1f8628 pop {r4, r5}
 *   @0x1f862c stm r2, {r1, r3}
 *   @0x1f8630 bx lr
 *   @0x1f8634 andseq r5, pc, r8, lsr r3
 *
 * ══ §94/373 GV_ViewObject(CInstance*, int, RValue*)  0x1f8638  size 84  21 条（0x1f8638..0x1f868c）
 * @func 0x1f8638 0x1f868c  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x48×1 / 0xc×1 / 0x2×1 / 0x38×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f8638 ldr r3, [pc, #0x48]
 *   @0x1f863c cmp r1, #7
 *   @0x1f8640 push {r4, r5}
 *   @0x1f8644 ldr r3, [pc, r3]
 *   @0x1f8648 movhi r1, #0
 *   @0x1f864c add r1, r1, #18
 *   @0x1f8650 ldr r3, [r3]
 *   @0x1f8654 mov r12, #0
 *   @0x1f8658 mov r0, #1
 *   @0x1f865c str r12, [r2, #0xc]
 *   @0x1f8660 ldr r3, [r3, r1, lsl #2]
 *   @0x1f8664 ldr r4, [r3, #0x38]
 *   @0x1f8668 vmov s15, r4
 *   @0x1f866c vcvt.f64.s32 d7, s15
 *   @0x1f8670 vmov r4, r5, d7
 *   @0x1f8674 vmov r1, s14
 *   @0x1f8678 mov r3, r5
 *   @0x1f867c pop {r4, r5}
 *   @0x1f8680 stm r2, {r1, r3}
 *   @0x1f8684 bx lr
 *   @0x1f8688 andseq r5, pc, r4, ror #5
 *
 * ══ §95/373 GV_ViewSurfaceID(CInstance*, int, RValue*)  0x1f8b18  size 84  21 条（0x1f8b18..0x1f8b6c）
 * @func 0x1f8b18 0x1f8b80  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x48×1 / 0xc×1 / 0x2×1 / 0x3c×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f8b18 ldr r3, [pc, #0x48]
 *   @0x1f8b1c cmp r1, #7
 *   @0x1f8b20 push {r4, r5}
 *   @0x1f8b24 ldr r3, [pc, r3]
 *   @0x1f8b28 movhi r1, #0
 *   @0x1f8b2c add r1, r1, #18
 *   @0x1f8b30 ldr r3, [r3]
 *   @0x1f8b34 mov r12, #0
 *   @0x1f8b38 mov r0, #1
 *   @0x1f8b3c str r12, [r2, #0xc]
 *   @0x1f8b40 ldr r3, [r3, r1, lsl #2]
 *   @0x1f8b44 ldr r4, [r3, #0x3c]
 *   @0x1f8b48 vmov s15, r4
 *   @0x1f8b4c vcvt.f64.s32 d7, s15
 *   @0x1f8b50 vmov r4, r5, d7
 *   @0x1f8b54 vmov r1, s14
 *   @0x1f8b58 mov r3, r5
 *   @0x1f8b5c pop {r4, r5}
 *   @0x1f8b60 stm r2, {r1, r3}
 *   @0x1f8b64 bx lr
 *   @0x1f8b68 andseq r4, pc, r4, lsl #28
 *
 * ══ §96/373 GV_ViewCamera(CInstance*, int, RValue*)  0x1f8b6c  size 84  21 条（0x1f8b6c..0x1f8bc0）
 * @func 0x1f8b6c 0x1f8bc0  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x48×1 / 0xc×1 / 0x2×1 / 0x40×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f8b6c ldr r3, [pc, #0x48]
 *   @0x1f8b70 cmp r1, #7
 *   @0x1f8b74 push {r4, r5}
 *   @0x1f8b78 ldr r3, [pc, r3]
 *   @0x1f8b7c movhi r1, #0
 *   @0x1f8b80 add r1, r1, #18
 *   @0x1f8b84 ldr r3, [r3]
 *   @0x1f8b88 mov r12, #0
 *   @0x1f8b8c mov r0, #1
 *   @0x1f8b90 str r12, [r2, #0xc]
 *   @0x1f8b94 ldr r3, [r3, r1, lsl #2]
 *   @0x1f8b98 ldr r4, [r3, #0x40]
 *   @0x1f8b9c vmov s15, r4
 *   @0x1f8ba0 vcvt.f64.s32 d7, s15
 *   @0x1f8ba4 vmov r4, r5, d7
 *   @0x1f8ba8 vmov r1, s14
 *   @0x1f8bac mov r3, r5
 *   @0x1f8bb0 pop {r4, r5}
 *   @0x1f8bb4 stm r2, {r1, r3}
 *   @0x1f8bb8 bx lr
 *   @0x1f8bbc ldrheq r4, [pc], -r0
 *
 * ══ §97/373 SV_Score(CInstance*, int, RValue*)  0x1fb26c  size 84  21 条（0x1fb26c..0x1fb2c0）
 * @func 0x1fb26c 0x1fb2c0  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8 / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fb26c push {r3, lr}
 *   @0x1fb270 ldr r3, [r2, #0xc]
 *   @0x1fb274 bic r3, r3, #-16777216
 *   @0x1fb278 cmp r3, #0
 *   @0x1fb27c bne 0x1fb2a8 <_Z8SV_ScoreP9CInstanceiP6RValue+0x3c>
 *   @0x1fb280 ldr r12, [r2]
 *   @0x1fb284 ldr r3, [r2, #0x4]
 *   @0x1fb288 mov r1, r3
 *   @0x1fb28c mov r0, r12
 *   @0x1fb290 bl 0xb66e8 <lrint@plt>
 *   @0x1fb294 ldr r3, [pc, #0x20]
 *   @0x1fb298 ldr r3, [pc, r3]
 *   @0x1fb29c str r0, [r3]
 *   @0x1fb2a0 mov r0, #1
 *   @0x1fb2a4 pop {r3, pc}
 *   @0x1fb2a8 mov r0, r2
 *   @0x1fb2ac bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fb2b0 mov r12, r0
 *   @0x1fb2b4 mov r3, r1
 *   @0x1fb2b8 b 0x1fb288 <_Z8SV_ScoreP9CInstanceiP6RValue+0x1c>
 *   @0x1fb2bc andseq r3, pc, r12, ror #15
 *
 * ══ §98/373 SV_CursorSprite(CInstance*, int, RValue*)  0x1fb644  size 84  21 条（0x1fb644..0x1fb698）
 * @func 0x1fb644 0x1fb698  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8 / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fb644 push {r3, lr}
 *   @0x1fb648 ldr r3, [r2, #0xc]
 *   @0x1fb64c bic r3, r3, #-16777216
 *   @0x1fb650 cmp r3, #0
 *   @0x1fb654 bne 0x1fb680 <_Z15SV_CursorSpriteP9CInstanceiP6RValue+0x3c>
 *   @0x1fb658 ldr r12, [r2]
 *   @0x1fb65c ldr r3, [r2, #0x4]
 *   @0x1fb660 mov r1, r3
 *   @0x1fb664 mov r0, r12
 *   @0x1fb668 bl 0xb66e8 <lrint@plt>
 *   @0x1fb66c ldr r3, [pc, #0x20]
 *   @0x1fb670 ldr r3, [pc, r3]
 *   @0x1fb674 str r0, [r3]
 *   @0x1fb678 mov r0, #1
 *   @0x1fb67c pop {r3, pc}
 *   @0x1fb680 mov r0, r2
 *   @0x1fb684 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fb688 mov r12, r0
 *   @0x1fb68c mov r3, r1
 *   @0x1fb690 b 0x1fb660 <_Z15SV_CursorSpriteP9CInstanceiP6RValue+0x1c>
 *   @0x1fb694 andseq r3, pc, r8, ror sp
 *
 * ══ §99/373 SV_Y(CInstance*, int, RValue*)  0x1fbba4  size 84  21 条（0x1fbba4..0x1fbbf8）
 * @func 0x1fbba4 0x1fbc0c  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::SetPosition(float, float) / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×1 / 0xb4×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fbba4 push {r3, r4, r5, r6, r7, lr}
 *   @0x1fbba8 mov r6, r0
 *   @0x1fbbac ldr r3, [r2, #0xc]
 *   @0x1fbbb0 ldr r7, [r0, #0xb4]
 *   @0x1fbbb4 bic r3, r3, #-16777216
 *   @0x1fbbb8 cmp r3, #0
 *   @0x1fbbbc bne 0x1fbbe4 <_Z4SV_YP9CInstanceiP6RValue+0x40>
 *   @0x1fbbc0 ldm r2, {r4, r5}
 *   @0x1fbbc4 vmov d7, r4, r5
 *   @0x1fbbc8 mov r0, r6
 *   @0x1fbbcc mov r1, r7
 *   @0x1fbbd0 vcvt.f32.f64 s15, d7
 *   @0x1fbbd4 vmov r2, s15
 *   @0x1fbbd8 bl 0x193e7c <_ZN9CInstance11SetPositionEff>
 *   @0x1fbbdc mov r0, #1
 *   @0x1fbbe0 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1fbbe4 mov r0, r2
 *   @0x1fbbe8 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fbbec mov r4, r0
 *   @0x1fbbf0 mov r5, r1
 *   @0x1fbbf4 b 0x1fbbc4 <_Z4SV_YP9CInstanceiP6RValue+0x20>
 *
 * ══ §100/373 SV_TimelineRunning(CInstance*, int, RValue*)  0x1fc05c  size 84  21 条（0x1fc05c..0x1fc0b0）
 * @func 0x1fc05c 0x1fc0c4  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8 / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×1 / 0x15c×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fc05c ldr r3, [r2, #0xc]
 *   @0x1fc060 push {r4, lr}
 *   @0x1fc064 bic r3, r3, #-16777216
 *   @0x1fc068 cmp r3, #0
 *   @0x1fc06c mov r4, r0
 *   @0x1fc070 bne 0x1fc0a4 <_Z18SV_TimelineRunningP9CInstanceiP6RValue+0x48>
 *   @0x1fc074 ldm r2, {r0, r1}
 *   @0x1fc078 bl 0xb66e8 <lrint@plt>
 *   @0x1fc07c vmov.f64 d7, #5.000000e-01
 *   @0x1fc080 vmov s11, r0
 *   @0x1fc084 mov r0, #1
 *   @0x1fc088 vcvt.f64.s32 d6, s11
 *   @0x1fc08c vcmpe.f64 d6, d7
 *   @0x1fc090 vmrs APSR_nzcv, fpscr
 *   @0x1fc094 movle r3, #0
 *   @0x1fc098 movgt r3, #1
 *   @0x1fc09c strb r3, [r4, #0x15c]
 *   @0x1fc0a0 pop {r4, pc}
 *   @0x1fc0a4 mov r0, r2
 *   @0x1fc0a8 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fc0ac b 0x1fc078 <_Z18SV_TimelineRunningP9CInstanceiP6RValue+0x1c>
 *
 * ══ §101/373 SV_TimelineLoop(CInstance*, int, RValue*)  0x1fc0b0  size 84  21 条（0x1fc0b0..0x1fc104）
 * @func 0x1fc0b0 0x1fc104  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8 / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×1 / 0x15d×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fc0b0 ldr r3, [r2, #0xc]
 *   @0x1fc0b4 push {r4, lr}
 *   @0x1fc0b8 bic r3, r3, #-16777216
 *   @0x1fc0bc cmp r3, #0
 *   @0x1fc0c0 mov r4, r0
 *   @0x1fc0c4 bne 0x1fc0f8 <_Z15SV_TimelineLoopP9CInstanceiP6RValue+0x48>
 *   @0x1fc0c8 ldm r2, {r0, r1}
 *   @0x1fc0cc bl 0xb66e8 <lrint@plt>
 *   @0x1fc0d0 vmov.f64 d7, #5.000000e-01
 *   @0x1fc0d4 vmov s11, r0
 *   @0x1fc0d8 mov r0, #1
 *   @0x1fc0dc vcvt.f64.s32 d6, s11
 *   @0x1fc0e0 vcmpe.f64 d6, d7
 *   @0x1fc0e4 vmrs APSR_nzcv, fpscr
 *   @0x1fc0e8 movle r3, #0
 *   @0x1fc0ec movgt r3, #1
 *   @0x1fc0f0 strb r3, [r4, #0x15d]
 *   @0x1fc0f4 pop {r4, pc}
 *   @0x1fc0f8 mov r0, r2
 *   @0x1fc0fc bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fc100 b 0x1fc0cc <_Z15SV_TimelineLoopP9CInstanceiP6RValue+0x1c>
 *
 * ══ §102/373 CStream::ReadInteger()  0x201730  size 84  21 条（0x201730..0x201784）
 * @func 0x201730 0x201784  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::ReadInteger()+0x4c
 * 字段偏移 top8: 0x8×1 / 0x18×1 / 0x2×1 / 0x1×1 / 0x3×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x201730 ldrd r2, r3, [r0, #16]
 *   @0x201734 ldr r1, [r0, #0x8]
 *   @0x201738 ldr r12, [r0, #0x18]
 *   @0x20173c cmp r1, r2
 *   @0x201740 push {r4, r5}
 *   @0x201744 movle r0, #0
 *   @0x201748 ble 0x20177c <_ZN7CStream11ReadIntegerEv+0x4c>
 *   @0x20174c add r1, r12, r2
 *   @0x201750 ldrb r12, [r12, r2]
 *   @0x201754 adds r2, r2, #4
 *   @0x201758 ldrb r4, [r1, #0x2]
 *   @0x20175c adc r3, r3, #0
 *   @0x201760 ldrb r5, [r1, #0x1]
 *   @0x201764 ldrb r1, [r1, #0x3]
 *   @0x201768 lsl r4, r4, #16
 *   @0x20176c strd r2, r3, [r0, #16]
 *   @0x201770 orr r0, r4, r5, lsl #8
 *   @0x201774 orr r0, r0, r12
 *   @0x201778 orr r0, r0, r1, lsl #24
 *   @0x20177c pop {r4, r5}
 *   @0x201780 bx lr
 *
 * ══ §103/373 SHA1Reset(SHA1Context*)  0x214294  size 84  21 条（0x214294..0x2142e8）
 * @func 0x214294 0x2142e8  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1 / 0xc×1 / 0x14×1 / 0x10×1 / 0x18×1 / 0x5c×1 / 0x60×1 / 0x64×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x214294 movw r2, #0x2301
 *   @0x214298 movw r3, #0xab89
 *   @0x21429c movt r2, #0x6745
 *   @0x2142a0 movt r3, #0xefcd
 *   @0x2142a4 stm r0, {r2, r3}
 *   @0x2142a8 movw r2, #0xdcfe
 *   @0x2142ac movw r3, #0x5476
 *   @0x2142b0 movt r2, #0x98ba
 *   @0x2142b4 movt r3, #0x1032
 *   @0x2142b8 str r2, [r0, #0x8]
 *   @0x2142bc str r3, [r0, #0xc]
 *   @0x2142c0 movw r2, #0xe1f0
 *   @0x2142c4 mov r3, #0
 *   @0x2142c8 movt r2, #0xc3d2
 *   @0x2142cc str r3, [r0, #0x14]
 *   @0x2142d0 str r2, [r0, #0x10]
 *   @0x2142d4 str r3, [r0, #0x18]
 *   @0x2142d8 str r3, [r0, #0x5c]
 *   @0x2142dc str r3, [r0, #0x60]
 *   @0x2142e0 str r3, [r0, #0x64]
 *   @0x2142e4 bx lr
 *
 * ══ §104/373 CEmitter::Reset()  0x215774  size 84  21 条（0x215774..0x2157c8）
 * @func 0x215774 0x2157c8  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65b0
 * 字段偏移 top8: 0x34×1 / 0x1c×1 / 0x24×1 / 0x20×1 / 0x30×1 / 0x28×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x215774 push {r4, lr}
 *   @0x215778 mov r1, #0
 *   @0x21577c mov r2, #60
 *   @0x215780 mov r4, r0
 *   @0x215784 bl 0xb65b0 <memset@plt>
 *   @0x215788 ldr r3, [pc, #0x34]
 *   @0x21578c mov r2, #1065353216
 *   @0x215790 mov r0, #0
 *   @0x215794 ldr r3, [pc, r3]
 *   @0x215798 movt r0, #0x42c8
 *   @0x21579c mov r1, #20480
 *   @0x2157a0 str r0, [r4, #0x1c]
 *   @0x2157a4 ldr r3, [r3]
 *   @0x2157a8 movt r1, #0x47c3
 *   @0x2157ac str r2, [r4, #0x24]
 *   @0x2157b0 str r1, [r4, #0x20]
 *   @0x2157b4 str r3, [r4, #0x30]
 *   @0x2157b8 str r2, [r4, #0x28]
 *   @0x2157bc str r2, [r4, #0x2c]
 *   @0x2157c0 pop {r4, pc}
 *   @0x2157c4 andseq r11, sp, r4, lsr r12
 *
 * ══ §105/373 CAudioGroup::SetLoadState(CAudioGroup::eLoadState)  0x21dd48  size 84  21 条（0x21dd48..0x21dd9c）
 * @func 0x21dd48 0x21dd9c  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x30×2 / 0x4×1 / 0x2×1 / 0x18×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21dd48 push {r3, lr}
 *   @0x21dd4c ldr r3, [r0]
 *   @0x21dd50 cmp r3, r1
 *   @0x21dd54 popeq {r3, pc}
 *   @0x21dd58 ldr r3, [pc, #0x30]
 *   @0x21dd5c ldr r12, [pc, #0x30]
 *   @0x21dd60 ldr r3, [pc, r3]
 *   @0x21dd64 str r1, [r0]
 *   @0x21dd68 ldr r2, [r0, #0x4]
 *   @0x21dd6c add r12, pc, r12
 *   @0x21dd70 ldr r0, [r3]
 *   @0x21dd74 ldr r3, [r12, r1, lsl #2]
 *   @0x21dd78 ldr r1, [pc, #0x18]
 *   @0x21dd7c ldr r12, [r0]
 *   @0x21dd80 add r1, pc, r1
 *   @0x21dd84 ldr r12, [r12, #0xc]
 *   @0x21dd88 blx r12
 *   @0x21dd8c pop {r3, pc}
 *   @0x21dd90 ldrheq pc, [r12], -r4
 *   @0x21dd94 andseq r9, r8, r12, ror #11
 *   @0x21dd98 ldrsheq r6, [r3], -r8
 *
 * ══ §106/373 _alutInputStreamSkip  0x221ec8  size 84  21 条（0x221ec8..0x221f1c）
 * @func 0x221ec8 0x221f1c  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _alutMalloc / anon_221c48 / 0xb655c
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x221ec8 push {r4, r5, r6, lr}
 *   @0x221ecc subs r4, r1, #0
 *   @0x221ed0 mov r5, r0
 *   @0x221ed4 bne 0x221ee0 <_alutInputStreamSkip+0x18>
 *   @0x221ed8 mov r0, #1
 *   @0x221edc pop {r4, r5, r6, pc}
 *   @0x221ee0 mov r0, r4
 *   @0x221ee4 bl 0x222a98 <_alutMalloc>
 *   @0x221ee8 subs r6, r0, #0
 *   @0x221eec beq 0x221f14 <_alutInputStreamSkip+0x4c>
 *   @0x221ef0 mov r2, r4
 *   @0x221ef4 mov r1, r6
 *   @0x221ef8 mov r0, r5
 *   @0x221efc bl 0x221c48 <alutExit+0xd0>
 *   @0x221f00 mov r4, r0
 *   @0x221f04 mov r0, r6
 *   @0x221f08 bl 0xb655c <free@plt>
 *   @0x221f0c mov r0, r4
 *   @0x221f10 pop {r4, r5, r6, pc}
 *   @0x221f14 mov r0, r6
 *   @0x221f18 pop {r4, r5, r6, pc}
 *
 * ══ §107/373 anon_222930  0x222930  size 84  21 条（0x222930..0x222984）
 * @func 0x222930 0x222984  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _alutOutputStreamGetLength / anon_222930+0x48 / 0xb65bc / _alutSetError
 * 字段偏移 top8: 0x4×3 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x222930 push {r3, r4, r5, r6, r7, lr}
 *   @0x222934 mov r5, r2
 *   @0x222938 ldr r6, [r0, #0x8]
 *   @0x22293c mov r4, r0
 *   @0x222940 mov r7, r1
 *   @0x222944 bl 0x222924 <_alutOutputStreamGetLength>
 *   @0x222948 rsb r0, r0, r6
 *   @0x22294c cmp r0, r5
 *   @0x222950 blo 0x222978 <_alutOutputStreamGetLength+0x54>
 *   @0x222954 mov r2, r5
 *   @0x222958 mov r1, r7
 *   @0x22295c ldr r0, [r4, #0x4]
 *   @0x222960 bl 0xb65bc <memcpy@plt>
 *   @0x222964 ldr r3, [r4, #0x4]
 *   @0x222968 mov r0, #1
 *   @0x22296c add r5, r3, r5
 *   @0x222970 str r5, [r4, #0x4]
 *   @0x222974 pop {r3, r4, r5, r6, r7, pc}
 *   @0x222978 movw r0, #0x20e
 *   @0x22297c bl 0x221940 <_alutSetError>
 *   @0x222980 mov r0, #0
 *
 * ══ §108/373 oggpackB_writetrunc  0x23331c  size 84  21 条（0x23331c..0x233370）
 * @func 0x23331c 0x233370  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×2 / 0x4×2 / 0x3×2 / 0x-4×1 / 0x34×1 / 0x8×1 / 0x84×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23331c ldr r2, [r0, #0xc]
 *   @0x233320 asr r3, r1, #3
 *   @0x233324 str r4, [sp, #-0x4]!
 *   @0x233328 cmp r2, #0
 *   @0x23332c beq 0x233364 <oggpackB_writetrunc+0x48>
 *   @0x233330 ldr r4, [pc, #0x34]
 *   @0x233334 sub r12, r1, r3, lsl #3
 *   @0x233338 ldr r2, [r0, #0x8]
 *   @0x23333c add r4, pc, r4
 *   @0x233340 str r3, [r0]
 *   @0x233344 add r4, r4, r12, lsl #2
 *   @0x233348 str r12, [r0, #0x4]
 *   @0x23334c add r3, r2, r3
 *   @0x233350 str r3, [r0, #0xc]
 *   @0x233354 ldr r0, [r4, #0x84]
 *   @0x233358 ldrb r3, [r2, r1, asr #3]
 *   @0x23335c and r3, r0, r3
 *   @0x233360 strb r3, [r2, r1, asr #3]
 *   @0x233364 ldr r4, [sp], #4
 *   @0x233368 bx lr
 *   @0x23336c ldrsheq r5, [r3], -r12
 *
 * ══ §109/373 CPhysicsObject::SetRotation(float)  0x236e48  size 84  21 条（0x236e48..0x236e9c）
 * @func 0x236e48 0x236e9c  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Body::SetTransform(b2Vec2 const&, float)
 * 字段偏移 top8: 0x4×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x236e48 vmov s15, r1
 *   @0x236e4c vldr s14, [pc, #64]
 *   @0x236e50 push {r4, lr}
 *   @0x236e54 vmul.f32 s14, s15, s14
 *   @0x236e58 vldr s15, [pc, #56]
 *   @0x236e5c mov r4, r0
 *   @0x236e60 ldr r0, [r0]
 *   @0x236e64 add r1, r0, #12
 *   @0x236e68 vdiv.f32 s15, s14, s15
 *   @0x236e6c vmov r2, s15
 *   @0x236e70 bl 0x2c71c4 <_ZN6b2Body12SetTransformERK6b2Vec2f>
 *   @0x236e74 ldr r3, [r4]
 *   @0x236e78 ldrh r2, [r3, #4]
 *   @0x236e7c tst r2, #2
 *   @0x236e80 orreq r2, r2, #2
 *   @0x236e84 strheq r2, [r3, #4]
 *   @0x236e88 moveq r1, #0
 *   @0x236e8c streq r1, [r3, #0xa0]
 *   @0x236e90 pop {r4, pc}
 *   @0x236e94 ldrdmi r0, r1, [r9], #-251
 *   @0x236e98 teqmi r4, #0
 *
 * ══ §110/373 CPhysicsObject::GetFriction(int)  0x2378d0  size 84  21 条（0x2378d0..0x237924）
 * @func 0x2378d0 0x237938  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x1c×1 / 0x3×1 / 0x8×1 / 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2378d0 ldr r3, [r0, #0x1c]
 *   @0x2378d4 ldr r2, [r3, #0x4]
 *   @0x2378d8 ldr r3, [r3]
 *   @0x2378dc and r2, r1, r2
 *   @0x2378e0 ldr r3, [r3, r2, lsl #3]
 *   @0x2378e4 cmp r3, #0
 *   @0x2378e8 bne 0x2378fc <_ZN14CPhysicsObject11GetFrictionEi+0x2c>
 *   @0x2378ec b 0x23791c <_ZN14CPhysicsObject11GetFrictionEi+0x4c>
 *   @0x2378f0 ldr r3, [r3, #0x4]
 *   @0x2378f4 cmp r3, #0
 *   @0x2378f8 beq 0x23791c <_ZN14CPhysicsObject11GetFrictionEi+0x4c>
 *   @0x2378fc ldr r2, [r3, #0x8]
 *   @0x237900 cmp r1, r2
 *   @0x237904 bne 0x2378f0 <_ZN14CPhysicsObject11GetFrictionEi+0x20>
 *   @0x237908 ldr r3, [r3, #0xc]
 *   @0x23790c cmp r3, #0
 *   @0x237910 beq 0x23791c <_ZN14CPhysicsObject11GetFrictionEi+0x4c>
 *   @0x237914 ldr r0, [r3, #0x10]
 *   @0x237918 bx lr
 *   @0x23791c mov r0, #0
 *   @0x237920 bx lr
 *
 * ══ §111/373 CPhysicsObject::GetDensity(int)  0x237924  size 84  21 条（0x237924..0x237978）
 * @func 0x237924 0x23798c  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x1c×1 / 0x3×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x237924 ldr r3, [r0, #0x1c]
 *   @0x237928 ldr r2, [r3, #0x4]
 *   @0x23792c ldr r3, [r3]
 *   @0x237930 and r2, r1, r2
 *   @0x237934 ldr r3, [r3, r2, lsl #3]
 *   @0x237938 cmp r3, #0
 *   @0x23793c bne 0x237950 <_ZN14CPhysicsObject10GetDensityEi+0x2c>
 *   @0x237940 b 0x237970 <_ZN14CPhysicsObject10GetDensityEi+0x4c>
 *   @0x237944 ldr r3, [r3, #0x4]
 *   @0x237948 cmp r3, #0
 *   @0x23794c beq 0x237970 <_ZN14CPhysicsObject10GetDensityEi+0x4c>
 *   @0x237950 ldr r2, [r3, #0x8]
 *   @0x237954 cmp r1, r2
 *   @0x237958 bne 0x237944 <_ZN14CPhysicsObject10GetDensityEi+0x20>
 *   @0x23795c ldr r3, [r3, #0xc]
 *   @0x237960 cmp r3, #0
 *   @0x237964 beq 0x237970 <_ZN14CPhysicsObject10GetDensityEi+0x4c>
 *   @0x237968 ldr r0, [r3]
 *   @0x23796c bx lr
 *   @0x237970 mov r0, #0
 *   @0x237974 bx lr
 *
 * ══ §112/373 CPhysicsObject::GetRestitution(int)  0x237978  size 84  21 条（0x237978..0x2379cc）
 * @func 0x237978 0x2379cc  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x1c×1 / 0x3×1 / 0x8×1 / 0xc×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x237978 ldr r3, [r0, #0x1c]
 *   @0x23797c ldr r2, [r3, #0x4]
 *   @0x237980 ldr r3, [r3]
 *   @0x237984 and r2, r1, r2
 *   @0x237988 ldr r3, [r3, r2, lsl #3]
 *   @0x23798c cmp r3, #0
 *   @0x237990 bne 0x2379a4 <_ZN14CPhysicsObject14GetRestitutionEi+0x2c>
 *   @0x237994 b 0x2379c4 <_ZN14CPhysicsObject14GetRestitutionEi+0x4c>
 *   @0x237998 ldr r3, [r3, #0x4]
 *   @0x23799c cmp r3, #0
 *   @0x2379a0 beq 0x2379c4 <_ZN14CPhysicsObject14GetRestitutionEi+0x4c>
 *   @0x2379a4 ldr r2, [r3, #0x8]
 *   @0x2379a8 cmp r1, r2
 *   @0x2379ac bne 0x237998 <_ZN14CPhysicsObject14GetRestitutionEi+0x20>
 *   @0x2379b0 ldr r3, [r3, #0xc]
 *   @0x2379b4 cmp r3, #0
 *   @0x2379b8 beq 0x2379c4 <_ZN14CPhysicsObject14GetRestitutionEi+0x4c>
 *   @0x2379bc ldr r0, [r3, #0x14]
 *   @0x2379c0 bx lr
 *   @0x2379c4 mov r0, #0
 *   @0x2379c8 bx lr
 *
 * ══ §113/373 CPhysicsWorld::ParticleGroupAddPoint(float, float)  0x239c08  size 84  21 条（0x239c08..0x239c5c）
 * @func 0x239c08 0x239c5c  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x94×2 / 0x3c×1 / 0x4×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x239c08 ldr r3, [r0, #0x3c]
 *   @0x239c0c vmov s14, r1
 *   @0x239c10 vmov s15, r2
 *   @0x239c14 cmp r3, #0
 *   @0x239c18 bxeq lr
 *   @0x239c1c ldr r2, [r3, #0x4]
 *   @0x239c20 cmp r2, #2
 *   @0x239c24 bxne lr
 *   @0x239c28 ldr r2, [r3, #0x94]
 *   @0x239c2c cmp r2, #7
 *   @0x239c30 bxgt lr
 *   @0x239c34 vldr s13, [r0, #96]
 *   @0x239c38 vmul.f32 s14, s13, s14
 *   @0x239c3c add r1, r2, #2
 *   @0x239c40 add r2, r2, #1
 *   @0x239c44 str r2, [r3, #0x94]
 *   @0x239c48 add r3, r3, r1, lsl #3
 *   @0x239c4c vmul.f32 s15, s13, s15
 *   @0x239c50 vstr s14, [r3, #4]
 *   @0x239c54 vstr s15, [r3, #8]
 *   @0x239c58 bx lr
 *
 * ══ §114/373 F_JSBooleanCall(RValue&, CInstance*, CInstance*, int, RValue*)  0x240588  size 84  21 条（0x240588..0x2405dc）
 * @func 0x240588 0x2405dc  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_JSBooleanCall(RValue&, CInstance*, CInstance*, int, RValue*)+0x3c / JS_ToBoolean(RValue&)
 * 字段偏移 top8: 0xc×2 / 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x240588 cmp r3, #0
 *   @0x24058c push {r4, lr}
 *   @0x240590 mov r4, r0
 *   @0x240594 ble 0x2405c4 <_Z15F_JSBooleanCallR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x240598 ldr r0, [sp, #0x8]
 *   @0x24059c bl 0x2404bc <_Z12JS_ToBooleanR6RValue>
 *   @0x2405a0 mov r3, #13
 *   @0x2405a4 str r3, [r4, #0xc]
 *   @0x2405a8 cmp r0, #0
 *   @0x2405ac movne r3, #0
 *   @0x2405b0 moveq r3, r0
 *   @0x2405b4 movne r0, r3
 *   @0x2405b8 movtne r3, #0x3ff0
 *   @0x2405bc stm r4, {r0, r3}
 *   @0x2405c0 pop {r4, pc}
 *   @0x2405c4 mov r3, #0
 *   @0x2405c8 mov r2, #13
 *   @0x2405cc str r3, [r0]
 *   @0x2405d0 str r2, [r0, #0xc]
 *   @0x2405d4 str r3, [r0, #0x4]
 *   @0x2405d8 pop {r4, pc}
 *
 * ══ §115/373 F_JSForInIteratorGetNext(RValue&, CInstance*, CInstance*, int, RValue*)  0x24a438  size 84  21 条（0x24a438..0x24a48c）
 * @func 0x24a438 0x24a48c  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYError(char const*, ...) / YYObject_PropertyNameIterator::Next(RValue*)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x24a438 push {r3, r4, r5, lr}
 *   @0x24a43c mov r4, r0
 *   @0x24a440 ldr r5, [sp, #0x10]
 *   @0x24a444 ldr r3, [r5, #0xc]
 *   @0x24a448 bic r3, r3, #-16777216
 *   @0x24a44c cmp r3, #14
 *   @0x24a450 beq 0x24a460 <_Z24F_JSForInIteratorGetNextR6RValueP9CInstanceS2_iPS_+0x28>
 *   @0x24a454 ldr r0, [pc, #0x2c]
 *   @0x24a458 add r0, pc, r0
 *   @0x24a45c bl 0xd547c <_Z7YYErrorPKcz>
 *   @0x24a460 ldr r0, [r5]
 *   @0x24a464 mov r1, r4
 *   @0x24a468 bl 0x24a1fc <_ZN29YYObject_PropertyNameIterator4NextEP6RValue>
 *   @0x24a46c cmp r0, #0
 *   @0x24a470 streq r0, [r4]
 *   @0x24a474 streq r0, [r4, #0x4]
 *   @0x24a478 moveq r3, #5
 *   @0x24a47c streq r0, [r4, #0x8]
 *   @0x24a480 streq r3, [r4, #0xc]
 *   @0x24a484 pop {r3, r4, r5, pc}
 *   @0x24a488 ldrsheq r10, [r0], -r12
 *
 * ══ §116/373 MemoryManager::GetSize(void const*)  0x27d1e0  size 84  21 条（0x27d1e0..0x27d234）
 * @func 0x27d1e0 0x27d234  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Mutex::Lock() / Mutex::Unlock() / anon_27b918
 * 字段偏移 top8: 0x38×1 / 0x-10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27d1e0 push {r3, r4, r5, lr}
 *   @0x27d1e4 subs r5, r0, #0
 *   @0x27d1e8 moveq r4, r5
 *   @0x27d1ec beq 0x27d21c <_ZN13MemoryManager7GetSizeEPKv+0x3c>
 *   @0x27d1f0 ldr r4, [pc, #0x38]
 *   @0x27d1f4 ldr r4, [pc, r4]
 *   @0x27d1f8 ldr r3, [r4]
 *   @0x27d1fc cmp r3, #0
 *   @0x27d200 movne r0, r3
 *   @0x27d204 beq 0x27d224 <_ZN13MemoryManager7GetSizeEPKv+0x44>
 *   @0x27d208 bl 0x27e084 <_ZN5Mutex4LockEv>
 *   @0x27d20c ldr r3, [r5, #-0x10]
 *   @0x27d210 ldr r0, [r4]
 *   @0x27d214 bic r4, r3, #-2147483648
 *   @0x27d218 bl 0x27e09c <_ZN5Mutex6UnlockEv>
 *   @0x27d21c mov r0, r4
 *   @0x27d220 pop {r3, r4, r5, pc}
 *   @0x27d224 bl 0x27b918 <_ZN7CBucketILj8ELj131072ELb1EE4FreeEPKv+0x38>
 *   @0x27d228 ldr r0, [r4]
 *   @0x27d22c b 0x27d208 <_ZN13MemoryManager7GetSizeEPKv+0x28>
 *   @0x27d230 andseq r4, r7, r8, lsr #12
 *
 * ══ §117/373 _spAttachmentTimeline_dispose  0x28136c  size 84  21 条（0x28136c..0x2813c0）
 * @func 0x28136c 0x2813d4  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _free×3 / _spTimeline_deinit / _spAttachmentTimeline_dispose+0x38
 * 字段偏移 top8: 0x8×2 / 0x14×2 / 0x2×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28136c push {r3, r4, r5, lr}
 *   @0x281370 mov r5, r0
 *   @0x281374 bl 0x281364 <_spTimeline_deinit>
 *   @0x281378 ldr r3, [r5, #0x8]
 *   @0x28137c cmp r3, #0
 *   @0x281380 movgt r4, #0
 *   @0x281384 ble 0x2813a4 <_spAttachmentTimeline_dispose+0x38>
 *   @0x281388 ldr r3, [r5, #0x14]
 *   @0x28138c ldr r0, [r3, r4, lsl #2]
 *   @0x281390 add r4, r4, #1
 *   @0x281394 bl 0x285c80 <_free>
 *   @0x281398 ldr r3, [r5, #0x8]
 *   @0x28139c cmp r3, r4
 *   @0x2813a0 bgt 0x281388 <_spAttachmentTimeline_dispose+0x1c>
 *   @0x2813a4 ldr r0, [r5, #0x14]
 *   @0x2813a8 bl 0x285c80 <_free>
 *   @0x2813ac ldr r0, [r5, #0xc]
 *   @0x2813b0 bl 0x285c80 <_free>
 *   @0x2813b4 mov r0, r5
 *   @0x2813b8 pop {r3, r4, r5, lr}
 *   @0x2813bc b 0x285c80 <_free>
 *
 * ══ §118/373 _spEventTimeline_dispose  0x2813c0  size 84  21 条（0x2813c0..0x281414）
 * @func 0x2813c0 0x281428  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _free×2 / _spTimeline_deinit / _spEventTimeline_dispose+0x38 / spEvent_dispose
 * 字段偏移 top8: 0x8×2 / 0x10×2 / 0x2×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2813c0 push {r3, r4, r5, lr}
 *   @0x2813c4 mov r5, r0
 *   @0x2813c8 bl 0x281364 <_spTimeline_deinit>
 *   @0x2813cc ldr r3, [r5, #0x8]
 *   @0x2813d0 cmp r3, #0
 *   @0x2813d4 movgt r4, #0
 *   @0x2813d8 ble 0x2813f8 <_spEventTimeline_dispose+0x38>
 *   @0x2813dc ldr r3, [r5, #0x10]
 *   @0x2813e0 ldr r0, [r3, r4, lsl #2]
 *   @0x2813e4 add r4, r4, #1
 *   @0x2813e8 bl 0x285b78 <spEvent_dispose>
 *   @0x2813ec ldr r3, [r5, #0x8]
 *   @0x2813f0 cmp r3, r4
 *   @0x2813f4 bgt 0x2813dc <_spEventTimeline_dispose+0x1c>
 *   @0x2813f8 ldr r0, [r5, #0x10]
 *   @0x2813fc bl 0x285c80 <_free>
 *   @0x281400 ldr r0, [r5, #0xc]
 *   @0x281404 bl 0x285c80 <_free>
 *   @0x281408 mov r0, r5
 *   @0x28140c pop {r3, r4, r5, lr}
 *   @0x281410 b 0x285c80 <_free>
 *
 * ══ §119/373 _spDrawOrderTimeline_dispose  0x281414  size 84  21 条（0x281414..0x281468）
 * @func 0x281414 0x281468  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _free×3 / _spTimeline_deinit / _spDrawOrderTimeline_dispose+0x38
 * 字段偏移 top8: 0x8×2 / 0x10×2 / 0x2×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x281414 push {r3, r4, r5, lr}
 *   @0x281418 mov r5, r0
 *   @0x28141c bl 0x281364 <_spTimeline_deinit>
 *   @0x281420 ldr r3, [r5, #0x8]
 *   @0x281424 cmp r3, #0
 *   @0x281428 movgt r4, #0
 *   @0x28142c ble 0x28144c <_spDrawOrderTimeline_dispose+0x38>
 *   @0x281430 ldr r3, [r5, #0x10]
 *   @0x281434 ldr r0, [r3, r4, lsl #2]
 *   @0x281438 add r4, r4, #1
 *   @0x28143c bl 0x285c80 <_free>
 *   @0x281440 ldr r3, [r5, #0x8]
 *   @0x281444 cmp r3, r4
 *   @0x281448 bgt 0x281430 <_spDrawOrderTimeline_dispose+0x1c>
 *   @0x28144c ldr r0, [r5, #0x10]
 *   @0x281450 bl 0x285c80 <_free>
 *   @0x281454 ldr r0, [r5, #0xc]
 *   @0x281458 bl 0x285c80 <_free>
 *   @0x28145c mov r0, r5
 *   @0x281460 pop {r3, r4, r5, lr}
 *   @0x281464 b 0x285c80 <_free>
 *
 * ══ §120/373 _spDeformTimeline_dispose  0x281754  size 84  21 条（0x281754..0x2817a8）
 * @func 0x281754 0x2817a8  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _free×3 / _spCurveTimeline_deinit / _spDeformTimeline_dispose+0x38
 * 字段偏移 top8: 0xc×2 / 0x18×2 / 0x2×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x281754 push {r3, r4, r5, lr}
 *   @0x281758 mov r5, r0
 *   @0x28175c bl 0x28171c <_spCurveTimeline_deinit>
 *   @0x281760 ldr r3, [r5, #0xc]
 *   @0x281764 cmp r3, #0
 *   @0x281768 movgt r4, #0
 *   @0x28176c ble 0x28178c <_spDeformTimeline_dispose+0x38>
 *   @0x281770 ldr r3, [r5, #0x18]
 *   @0x281774 ldr r0, [r3, r4, lsl #2]
 *   @0x281778 add r4, r4, #1
 *   @0x28177c bl 0x285c80 <_free>
 *   @0x281780 ldr r3, [r5, #0xc]
 *   @0x281784 cmp r3, r4
 *   @0x281788 bgt 0x281770 <_spDeformTimeline_dispose+0x1c>
 *   @0x28178c ldr r0, [r5, #0x18]
 *   @0x281790 bl 0x285c80 <_free>
 *   @0x281794 ldr r0, [r5, #0x10]
 *   @0x281798 bl 0x285c80 <_free>
 *   @0x28179c mov r0, r5
 *   @0x2817a0 pop {r3, r4, r5, lr}
 *   @0x2817a4 b 0x285c80 <_free>
 *
 * ══ §121/373 png_create_struct_2  0x2a6c02  size 84  21 条（0x2a6c02..0x2a6c56）
 * @func 0x2a6c02 0x2a6c56  size 84  21 条
 * 部分覆盖: 本节 21/38 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65b0×2 / 0xb6544
 * 字段偏移 top8: 0x2e8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6c02 cmp r0, #0x2
 *   @0x2a6c06 mov r5, r1
 *   @0x2a6c0a andle r7, r4, lr, asr #26
 *   @0x2a6c0e cmp r0, #0x1
 *   @0x2a6c12 mov.w r4, #0x338
 *   @0x2a6c16 b 0x2a6c1c <png_create_struct_2+0x1a>
 *   @0x2a6c1a .word 0xb1557490
 *   @0x2a6c1e str r2, [sp, #0x2e8]
 *   @0x2a6c22 mov r1, r4
 *   @0x2a6c26 mov r5, r0
 *   @0x2a6c2a movs r1, #0x0
 *   @0x2a6c2e blx 0xb65b0 <memset@plt>
 *   @0x2a6c32 b 0x2a6c4e <png_create_struct_2+0x4c>
 *   @0x2a6c36 blx 0xb6544 <malloc@plt>
 *   @0x2a6c3a mov r6, r0
 *   @0x2a6c3e mov r1, r5
 *   @0x2a6c42 blx 0xb65b0 <memset@plt>
 *   @0x2a6c46 mov r0, r6
 *   @0x2a6c4a movs r0, #0x0
 *   @0x2a6c4e mov r0, r5
 *   @0x2a6c52 ldcllt p13, c7, [r0, #-312]!
 *
 * ══ §122/373 png_write_gAMA  0x2b17c0  size 84  21 条（0x2b17c0..0x2b1814）
 * @func 0x2b17c0 0x2b1814  size 84  21 条
 * 部分覆盖: 本节 21/39 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x40×1 / 0x4×1 / 0x20×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b17c0 vmov.f64 d7, #5.000000e-01
 *   @0x2b17c4 vldr d6, [pc, #64]
 *   @0x2b17c8 vmov d5, r2, r3
 *   @0x2b17cc ldr r1, [pc, #0x40]
 *   @0x2b17d0 add r1, pc
 *   @0x2b17d4 sub sp, #0x14
 *   @0x2b17d8 .word 0xac010f1c
 *   @0x2b17dc ldrb r1, [r1, #0x4]
 *   @0x2b17e0 mov r0, r4
 *   @0x2b17e4 .word 0xf88d7b06
 *   @0x2b17e8 cdp p0, #0xf, c1, c12, c12, #0x0
 *   @0x2b17ec vnmla.f64 d5, d21, d7
 *   @0x2b17f0 .word 0xf7ff1a90
 *   @0x2b17f4 qadd8mi pc, r8, r7
 *   @0x2b17f8 add r1, sp, #0x8
 *   @0x2b17fc movs r3, #0x4
 *   @0x2b1800 andlt pc, r5, sp, asr sp
 *   @0x2b1804 pop {r4, r5, pc}
 *   @0x2b1808 movs r0, r0
 *   @0x2b180c ldr r0, [r0, #0x20]
 *   @0x2b1810 b 0x2b1334 <png_write_IHDR+0x50>
 *
 * ══ §123/373 DGifExtensionToGCB(unsigned int, unsigned char const*, GraphicsControlBlock*)  0x2c23f8  size 84  21 条（0x2c23f8..0x2c244c）
 * @func 0x2c23f8 0x2c244c  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1 / 0x2×1 / 0x1×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c23f8 cmp r0, #4
 *   @0x2c23fc beq 0x2c2408 <_Z18DGifExtensionToGCBjPKhP20GraphicsControlBlock+0x10>
 *   @0x2c2400 mov r0, #0
 *   @0x2c2404 bx lr
 *   @0x2c2408 ldrb r3, [r1]
 *   @0x2c240c ubfx r3, r3, #0x2, #0x3
 *   @0x2c2410 str r3, [r2]
 *   @0x2c2414 ldrb r3, [r1]
 *   @0x2c2418 ubfx r3, r3, #0x1, #0x1
 *   @0x2c241c strb r3, [r2, #0x4]
 *   @0x2c2420 ldrb r0, [r1, #0x2]
 *   @0x2c2424 ldrb r3, [r1, #0x1]
 *   @0x2c2428 orr r3, r3, r0, lsl #8
 *   @0x2c242c str r3, [r2, #0x8]
 *   @0x2c2430 ldrb r3, [r1]
 *   @0x2c2434 mov r0, #1
 *   @0x2c2438 tst r3, #1
 *   @0x2c243c ldrbne r3, [r1, #0x3]
 *   @0x2c2440 mvneq r3, #0
 *   @0x2c2444 str r3, [r2, #0xc]
 *   @0x2c2448 bx lr
 *
 * ══ §124/373 b2Body::CreateFixture(b2Shape const*, float)  0x2c6ed0  size 84  21 条（0x2c6ed0..0x2c6f24）
 * @func 0x2c6ed0 0x2c6f24  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Body::CreateFixture(b2FixtureDef const*)
 * 字段偏移 top8: 0x4×2 / 0x-4×1 / 0x14×1 / 0x20×1 / 0x1c×1 / 0x24×1 / 0x8×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c6ed0 str lr, [sp, #-0x4]!
 *   @0x2c6ed4 sub sp, sp, #44
 *   @0x2c6ed8 movw r3, #0xffff
 *   @0x2c6edc movw r12, #0xcccd
 *   @0x2c6ee0 str r1, [sp, #0x4]
 *   @0x2c6ee4 add r1, sp, #4
 *   @0x2c6ee8 str r2, [sp, #0x14]
 *   @0x2c6eec movt r12, #0x3e4c
 *   @0x2c6ef0 str r3, [sp, #0x20]
 *   @0x2c6ef4 mov r2, #1
 *   @0x2c6ef8 mov r3, #0
 *   @0x2c6efc str r2, [sp, #0x1c]
 *   @0x2c6f00 strh r3, [sp, #36]
 *   @0x2c6f04 mov r2, #0
 *   @0x2c6f08 str r3, [sp, #0x8]
 *   @0x2c6f0c strb r3, [sp, #0x18]
 *   @0x2c6f10 str r12, [sp, #0xc]
 *   @0x2c6f14 str r2, [sp, #0x10]
 *   @0x2c6f18 bl 0x2c6dfc <_ZN6b2Body13CreateFixtureEPK12b2FixtureDef>
 *   @0x2c6f1c add sp, sp, #44
 *   @0x2c6f20 ldr pc, [sp], #4
 *
 * ══ §125/373 b2ContactFilter::ShouldCollide(b2Fixture*, b2Fixture*)  0x2cbdb8  size 84  21 条（0x2cbdb8..0x2cbe0c）
 * @func 0x2cbdb8 0x2cbe0c  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x20×2 / 0x24×2 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cbdb8 ldrh r12, [r1, #40]
 *   @0x2cbdbc ldrsh r0, [r2, #40]
 *   @0x2cbdc0 sxth r3, r12
 *   @0x2cbdc4 cmp r0, r3
 *   @0x2cbdc8 beq 0x2cbdf4 <_ZN15b2ContactFilter13ShouldCollideEP9b2FixtureS1_+0x3c>
 *   @0x2cbdcc ldr r0, [r2, #0x20]
 *   @0x2cbdd0 ldr r3, [r1, #0x24]
 *   @0x2cbdd4 ands r0, r0, r3
 *   @0x2cbdd8 bxeq lr
 *   @0x2cbddc ldr r2, [r2, #0x24]
 *   @0x2cbde0 ldr r3, [r1, #0x20]
 *   @0x2cbde4 tst r2, r3
 *   @0x2cbde8 moveq r0, #0
 *   @0x2cbdec movne r0, #1
 *   @0x2cbdf0 bx lr
 *   @0x2cbdf4 cmp r12, #0
 *   @0x2cbdf8 beq 0x2cbdcc <_ZN15b2ContactFilter13ShouldCollideEP9b2FixtureS1_+0x14>
 *   @0x2cbdfc cmp r0, #0
 *   @0x2cbe00 movle r0, #0
 *   @0x2cbe04 movgt r0, #1
 *   @0x2cbe08 bx lr
 *
 * ══ §126/373 b2MotorJointDef::Initialize(b2Body*, b2Body*)  0x2ce670  size 84  21 条（0x2ce670..0x2ce6c4）
 * @func 0x2ce670 0x2ce6c4  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1 / 0xc×1
 * VFP 指令 18 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ce670 vldr s14, [r2, #16]
 *   @0x2ce674 vldr s15, [r1, #16]
 *   @0x2ce678 vsub.f32 s15, s14, s15
 *   @0x2ce67c vldr s12, [r1, #20]
 *   @0x2ce680 vldr s8, [r2, #12]
 *   @0x2ce684 vldr s13, [r1, #12]
 *   @0x2ce688 vldr s11, [r1, #24]
 *   @0x2ce68c vldr s9, [r2, #72]
 *   @0x2ce690 vldr s10, [r1, #72]
 *   @0x2ce694 str r1, [r0, #0x8]
 *   @0x2ce698 str r2, [r0, #0xc]
 *   @0x2ce69c vmul.f32 s14, s15, s12
 *   @0x2ce6a0 vsub.f32 s13, s8, s13
 *   @0x2ce6a4 vmul.f32 s15, s15, s11
 *   @0x2ce6a8 vmla.f32 s14, s13, s11
 *   @0x2ce6ac vmls.f32 s15, s12, s13
 *   @0x2ce6b0 vstr s14, [r0, #20]
 *   @0x2ce6b4 vsub.f32 s14, s9, s10
 *   @0x2ce6b8 vstr s15, [r0, #24]
 *   @0x2ce6bc vstr s14, [r0, #28]
 *   @0x2ce6c0 bx lr
 *
 * ══ §127/373 b2MotorJoint::SetAngularOffset(float)  0x2ce8ec  size 84  21 条（0x2ce8ec..0x2ce940）
 * @func 0x2ce8ec 0x2ce940  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x30×1 / 0x34×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ce8ec vmov s15, r1
 *   @0x2ce8f0 vldr s14, [r0, #76]
 *   @0x2ce8f4 vcmp.f32 s14, s15
 *   @0x2ce8f8 vmrs APSR_nzcv, fpscr
 *   @0x2ce8fc bxeq lr
 *   @0x2ce900 ldr r3, [r0, #0x30]
 *   @0x2ce904 ldrh r2, [r3, #4]
 *   @0x2ce908 tst r2, #2
 *   @0x2ce90c orreq r2, r2, #2
 *   @0x2ce910 strheq r2, [r3, #4]
 *   @0x2ce914 moveq r1, #0
 *   @0x2ce918 streq r1, [r3, #0xa0]
 *   @0x2ce91c ldr r3, [r0, #0x34]
 *   @0x2ce920 ldrh r2, [r3, #4]
 *   @0x2ce924 tst r2, #2
 *   @0x2ce928 orreq r2, r2, #2
 *   @0x2ce92c strheq r2, [r3, #4]
 *   @0x2ce930 moveq r1, #0
 *   @0x2ce934 streq r1, [r3, #0xa0]
 *   @0x2ce938 vstr s15, [r0, #76]
 *   @0x2ce93c bx lr
 *
 * ══ §128/373 b2PrismaticJoint::EnableLimit(bool)  0x2d031c  size 84  21 条（0x2d031c..0x2d0370）
 * @func 0x2d031c 0x2d0370  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x88×2 / 0x4×2 / 0x30×1 / 0x34×1 / 0x70×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d031c ldrb r3, [r0, #0x88]
 *   @0x2d0320 cmp r3, r1
 *   @0x2d0324 bxeq lr
 *   @0x2d0328 ldr r3, [r0, #0x30]
 *   @0x2d032c ldrh r2, [r3, #4]
 *   @0x2d0330 tst r2, #2
 *   @0x2d0334 orreq r2, r2, #2
 *   @0x2d0338 strheq r2, [r3, #4]
 *   @0x2d033c moveq r12, #0
 *   @0x2d0340 streq r12, [r3, #0xa0]
 *   @0x2d0344 ldr r3, [r0, #0x34]
 *   @0x2d0348 ldrh r2, [r3, #4]
 *   @0x2d034c tst r2, #2
 *   @0x2d0350 orreq r2, r2, #2
 *   @0x2d0354 strheq r2, [r3, #4]
 *   @0x2d0358 moveq r12, #0
 *   @0x2d035c streq r12, [r3, #0xa0]
 *   @0x2d0360 mov r3, #0
 *   @0x2d0364 strb r1, [r0, #0x88]
 *   @0x2d0368 str r3, [r0, #0x70]
 *   @0x2d036c bx lr
 *
 * ══ §129/373 b2RevoluteJoint::EnableLimit(bool)  0x2d2228  size 84  21 条（0x2d2228..0x2d227c）
 * @func 0x2d2228 0x2d227c  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x70×2 / 0x4×2 / 0x30×1 / 0x34×1 / 0x5c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d2228 ldrb r3, [r0, #0x70]
 *   @0x2d222c cmp r3, r1
 *   @0x2d2230 bxeq lr
 *   @0x2d2234 ldr r3, [r0, #0x30]
 *   @0x2d2238 ldrh r2, [r3, #4]
 *   @0x2d223c tst r2, #2
 *   @0x2d2240 orreq r2, r2, #2
 *   @0x2d2244 strheq r2, [r3, #4]
 *   @0x2d2248 moveq r12, #0
 *   @0x2d224c streq r12, [r3, #0xa0]
 *   @0x2d2250 ldr r3, [r0, #0x34]
 *   @0x2d2254 ldrh r2, [r3, #4]
 *   @0x2d2258 tst r2, #2
 *   @0x2d225c orreq r2, r2, #2
 *   @0x2d2260 strheq r2, [r3, #4]
 *   @0x2d2264 moveq r12, #0
 *   @0x2d2268 streq r12, [r3, #0xa0]
 *   @0x2d226c mov r3, #0
 *   @0x2d2270 strb r1, [r0, #0x70]
 *   @0x2d2274 str r3, [r0, #0x5c]
 *   @0x2d2278 bx lr
 *
 * ══ §130/373 anon_2d51e4  0x2d51e4  size 84  21 条（0x2d51e4..0x2d5238）
 * @func 0x2d51e4 0x2d5238  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2ParticleSystem::DestroyParticle(int, bool)
 * 字段偏移 top8: 0x4×2 / 0x20×2 / 0x8×1 / 0x38×1 / 0x10×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d51e4 push {r3, r4, r5, lr}
 *   @0x2d51e8 mov r4, r0
 *   @0x2d51ec ldr r0, [r0, #0x8]
 *   @0x2d51f0 mov r5, r1
 *   @0x2d51f4 ldr r2, [r4, #0x4]
 *   @0x2d51f8 add r1, r4, #12
 *   @0x2d51fc ldr r3, [r0]
 *   @0x2d5200 ldr r2, [r2, #0x38]
 *   @0x2d5204 ldr r3, [r3, #0x10]
 *   @0x2d5208 add r2, r2, r5, lsl #3
 *   @0x2d520c blx r3
 *   @0x2d5210 cmp r0, #0
 *   @0x2d5214 beq 0x2d5234 <_ZN16b2ParticleSystem15DestroyParticleEib+0x74>
 *   @0x2d5218 mov r1, r5
 *   @0x2d521c ldr r0, [r4, #0x4]
 *   @0x2d5220 ldrb r2, [r4, #0x1c]
 *   @0x2d5224 bl 0x2d51c0 <_ZN16b2ParticleSystem15DestroyParticleEib>
 *   @0x2d5228 ldr r3, [r4, #0x20]
 *   @0x2d522c add r3, r3, #1
 *   @0x2d5230 str r3, [r4, #0x20]
 *   @0x2d5234 mov r0, #1
 *
 * ══ §131/373 FT_Outline_Render  0x2e64c8  size 84  21 条（0x2e64c8..0x2e651c）
 * @func 0x2e64c8 0x2e651c  size 84  21 条
 * 部分覆盖: 本节 21/39 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FT_Lookup_Renderer
 * 字段偏移 top8: 0x4×1 / 0x38×1 / 0x34×1 / 0x18×1 / 0x11×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e64c8 push {r0, r1, r2, r4, r5, r6, r7, lr}
 *   @0x2e64cc mov r5, r0
 *   @0x2e64d0 cbz r1, 0x2e650a <FT_Outline_Render+0x42>
 *   @0x2e64d4 ldr.w r3, [r5, #0x94]
 *   @0x2e64d8 add r7, sp, #0x8
 *   @0x2e64dc ldr.w r0, [r0, #0x9c]
 *   @0x2e64e0 str r1, [r2, #0x4]
 *   @0x2e64e4 lsllt r3, r4, #26
 *   @0x2e64e8 ldr r3, [r0, #0x38]
 *   @0x2e64ec ldr r0, [r0, #0x34]
 *   @0x2e64f0 mov r4, r0
 *   @0x2e64f4 uxtb r3, r0
 *   @0x2e64f8 bne 0x2e6512 <FT_Outline_Render+0x4a>
 *   @0x2e64fc ldr r1, [pc, #0x18]
 *   @0x2e6500 bl 0x2e5e36 <FT_Lookup_Renderer>
 *   @0x2e6504 b 0x2e64e6 <FT_Outline_Render+0x1e>
 *   @0x2e6508 b 0x2e6514 <FT_Outline_Render+0x4c>
 *   @0x2e650c b 0x2e6514 <FT_Outline_Render+0x4c>
 *   @0x2e6510 b 0x2e6514 <FT_Outline_Render+0x4c>
 *   @0x2e6514 add sp, #0xc
 *   @0x2e6518 strb r4, [r5, #0x11]
 *
 * ══ §132/373 FT_Stream_ReadUOffset  0x2e6d70  size 84  21 条（0x2e6d70..0x2e6dc4）
 * @func 0x2e6d70 0x2e6dd8  size 104  26 条
 * 部分覆盖: 本节 26/51 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 25/49 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 24/47 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 23/45 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 22/43 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×2 / 0x4×1 / 0x14×1 / 0x1×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e6d70 push {r0, r1, r2, r4, r5, r6, r7, lr}
 *   @0x2e6d74 str r3, [r1]
 *   @0x2e6d78 ldr r3, [r0, #0x8]
 *   @0x2e6d7c ldr r2, [r0, #0x4]
 *   @0x2e6d80 cmp r1, r2
 *   @0x2e6d84 ldr r7, [r0, #0x14]
 *   @0x2e6d88 add r6, sp, #0x4
 *   @0x2e6d8c movs r3, #0x3
 *   @0x2e6d90 blx r7
 *   @0x2e6d94 bne 0x2e6dba <FT_Stream_ReadUOffset+0x4a>
 *   @0x2e6d98 b 0x2e6da0 <FT_Stream_ReadUOffset+0x30>
 *   @0x2e6d9c adds r2, r2, r3
 *   @0x2e6da0 ldrb r0, [r2, #0x1]
 *   @0x2e6da4 lsls r0, r0, #0x8
 *   @0x2e6da8 ldmvc r3, {r0, r1, lr}
 *   @0x2e6dac orr.w r2, r0, r3
 *   @0x2e6db0 ldr r3, [r4, #0x8]
 *   @0x2e6db4 adds r3, #0x3
 *   @0x2e6db8 b 0x2e6dc0 <FT_Stream_ReadUOffset+0x50>
 *   @0x2e6dbc movs r3, #0x55
 *   @0x2e6dc0 add sp, #0xc
 *
 * ══ §133/373 FT_Matrix_Invert  0x2e4f7c  size 82  21 条（0x2e4f7c..0x2e4fce）
 * @func 0x2e4f7c 0x2e4fd0  size 84  21 条
 * 部分覆盖: 本节 21/38 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FT_DivFix×3 / FT_MulFix
 * 字段偏移 top8: 0xc×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e4f7c push {r4, r5, r6, lr}
 *   @0x2e4f80 cbnz r0, 0x2e4f86 <FT_Matrix_Invert+0xa>
 *   @0x2e4f84 pop {r4, r5, r6, pc}
 *   @0x2e4f88 ldr r0, [r0]
 *   @0x2e4f8c stmvs r1!, {r0, r1, r2, r3, r4, r6, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2e4f90 mov r5, r0
 *   @0x2e4f94 bl 0x2e4e4c <FT_MulFix>
 *   @0x2e4f98 subs r5, r5, r0
 *   @0x2e4f9c mov r1, r5
 *   @0x2e4fa0 bl 0x2e4eb6 <FT_DivFix>
 *   @0x2e4fa4 mov r1, r5
 *   @0x2e4fa8 str r0, [r4, #0x4]
 *   @0x2e4fac bl 0x2e4eb6 <FT_DivFix>
 *   @0x2e4fb0 mov r1, r5
 *   @0x2e4fb4 rsbs r0, r0, #0
 *   @0x2e4fb8 ldr r0, [r4, #0xc]
 *   @0x2e4fbc qsub16mi pc, r9, r12
 *   @0x2e4fc0 str r0, [r4]
 *   @0x2e4fc4 bl 0x2e4eb6 <FT_DivFix>
 *   @0x2e4fc8 str r0, [r4, #0xc]
 *   @0x2e4fcc pop {r4, r5, r6, pc}
 *
 * ══ §134/373 FT_Vector_Length  0x2e7028  size 82  21 条（0x2e7028..0x2e707a）
 * @func 0x2e7028 0x2e707c  size 84  21 条
 * 部分覆盖: 本节 21/40 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xfeb033d8 / anon_2e490c+0x15e
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e7028 push {r0, r1, r2, r4, r5, lr}
 *   @0x2e702c ldm r0, {r0, r1}
 *   @0x2e7030 strmi r0, [r3], -r3
 *   @0x2e7034 mov r0, r1
 *   @0x2e7038 cmp r0, #0x0
 *   @0x2e703c rsblt r0, r0, #0
 *   @0x2e7040 cbnz r1, 0x2e704c <FT_Vector_Length+0x24>
 *   @0x2e7044 bl 0xfeb033d8 <b2_toiTime+0xfffffffffe3a9f34>
 *   @0x2e7048 ands r7, r4, r3, ror #1
 *   @0x2e704c mov r0, sp
 *   @0x2e7050 strmi pc, [r5], -r5, asr #27
 *   @0x2e7054 mov r0, sp
 *   @0x2e7058 stmdals r0, {r0, r1, r2, r3, r5, r6, r8, r10, r11, r12, sp, lr, pc}
 *   @0x2e705c bl 0x2e4a6a <_ZNK11b2GearJoint8GetRatioEv+0x166>
 *   @0x2e7060 cmp r5, #0x0
 *   @0x2e7064 subs r3, r5, #0x1
 *   @0x2e7068 lsl.w r3, r2, r3
 *   @0x2e706c add r0, r3
 *   @0x2e7070 b 0x2e7076 <FT_Vector_Length+0x4e>
 *   @0x2e7074 lsls r0, r5
 *   @0x2e7078 pop {r4, r5, pc}
 *
 * ══ §135/373 VMWriteBuffer::VMWriteBuffer(int)  0xec5b4  size 80  20 条（0xec5b4..0xec604）
 * @func 0xec5b4 0xec604  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new[](unsigned int)
 * 字段偏移 top8: 0x10×2 / 0x3c×1 / 0x14×1 / 0x18×1 / 0x4×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xec5b4 push {r3, r4, r5, lr}
 *   @0xec5b8 mov r4, r0
 *   @0xec5bc ldr r3, [pc, #0x3c]
 *   @0xec5c0 mov r2, #0
 *   @0xec5c4 str r2, [r0, #0x10]
 *   @0xec5c8 mov r5, r1
 *   @0xec5cc ldr r3, [pc, r3]
 *   @0xec5d0 str r2, [r0, #0x14]
 *   @0xec5d4 add r3, r3, #8
 *   @0xec5d8 str r3, [r0]
 *   @0xec5dc mov r0, r1
 *   @0xec5e0 str r2, [r4, #0x18]
 *   @0xec5e4 bl 0x27d14c <_Znaj>
 *   @0xec5e8 str r5, [r4, #0x4]
 *   @0xec5ec mov r3, r0
 *   @0xec5f0 mov r0, r4
 *   @0xec5f4 str r3, [r4, #0x10]
 *   @0xec5f8 str r3, [r4, #0x1c]
 *   @0xec5fc pop {r3, r4, r5, pc}
 *   @0xec600 eorseq r1, r0, r4, lsr #15
 *
 * ══ §136/373 InputQuery::Question(char const*, char const*)  0xf29a4  size 80  20 条（0xf29a4..0xf29f4）
 * @func 0xf29a4 0xf29f4  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv×2
 * 字段偏移 top8: 0x29c×1 / 0x1c×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf29a4 push {r4, lr}
 *   @0xf29a8 mov r4, r1
 *   @0xf29ac bl 0x290274 <getJNIEnv>
 *   @0xf29b0 mov r1, r4
 *   @0xf29b4 ldr r3, [r0]
 *   @0xf29b8 ldr r3, [r3, #0x29c]
 *   @0xf29bc blx r3
 *   @0xf29c0 mov r4, r0
 *   @0xf29c4 bl 0x290274 <getJNIEnv>
 *   @0xf29c8 ldr r1, [pc, #0x1c]
 *   @0xf29cc mov r3, r4
 *   @0xf29d0 ldr r2, [pc, #0x18]
 *   @0xf29d4 ldr r1, [pc, r1]
 *   @0xf29d8 ldr r2, [pc, r2]
 *   @0xf29dc ldr r1, [r1]
 *   @0xf29e0 ldr r2, [r2]
 *   @0xf29e4 pop {r4, lr}
 *   @0xf29e8 b 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz>
 *   @0xf29ec .word 0x002fafd0
 *   @0xf29f0 eoreq r11, pc, r8, lsr #8
 *
 * ══ §137/373 F_DsListCreate(RValue&, CInstance*, CInstance*, int, RValue*)  0xfffc4  size 80  20 条（0xfffc4..0x100014）
 * @func 0xfffc4 0x100014  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FindFreeDsListIndex() / operator new(unsigned int) / CDS_List::CDS_List()
 * 字段偏移 top8: 0x20×1 / 0x4×1 / 0x2×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfffc4 push {r4, r5, r6, lr}
 *   @0xfffc8 mov r4, r0
 *   @0xfffcc bl 0xfff10 <_Z19FindFreeDsListIndexv>
 *   @0xfffd0 mov r5, r0
 *   @0xfffd4 mov r0, #16
 *   @0xfffd8 bl 0x27c524 <_Znwj>
 *   @0xfffdc mov r6, r0
 *   @0xfffe0 bl 0x202ff8 <_ZN8CDS_ListC2Ev>
 *   @0xfffe4 vmov s15, r5
 *   @0xfffe8 ldr r1, [pc, #0x20]
 *   @0xfffec mov r0, #0
 *   @0xffff0 vcvt.f64.s32 d7, s15
 *   @0xffff4 ldr r1, [pc, r1]
 *   @0xffff8 ldr r1, [r1, #0x4]
 *   @0xffffc str r6, [r1, r5, lsl #2]
 *   @0x100000 str r0, [r4, #0xc]
 *   @0x100004 vmov r2, r3, d7
 *   @0x100008 stm r4, {r2, r3}
 *   @0x10000c pop {r4, r5, r6, pc}
 *   @0x100010 eoreq sp, lr, r12, lsl #25
 *
 * ══ §138/373 F_DegToRad(RValue&, CInstance*, CInstance*, int, RValue*)  0x10df08  size 80  20 条（0x10df08..0x10df58）
 * @func 0x10df08 0x10df6c  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10df08 push {r4, lr}
 *   @0x10df0c mov r3, #0
 *   @0x10df10 mov r4, r0
 *   @0x10df14 str r3, [r0, #0xc]
 *   @0x10df18 mov r1, r3
 *   @0x10df1c ldr r0, [sp, #0x8]
 *   @0x10df20 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x10df24 vldr d6, [pc, #28]
 *   @0x10df28 vldr d7, [pc, #32]
 *   @0x10df2c vmov d5, r0, r1
 *   @0x10df30 vmul.f64 d6, d5, d6
 *   @0x10df34 vdiv.f64 d5, d6, d7
 *   @0x10df38 vmov r2, r3, d5
 *   @0x10df3c stm r4, {r2, r3}
 *   @0x10df40 pop {r4, pc}
 *   @0x10df44 nop
 *   @0x10df48 andvs r0, r0, r0
 *   @0x10df4c strdmi r2, r3, [r9], -r11
 *   @0x10df50 andeq r0, r0, r0
 *   @0x10df54 rsbmi r8, r6, r0
 *
 * ══ §139/373 F_RadToDeg(RValue&, CInstance*, CInstance*, int, RValue*)  0x10df58  size 80  20 条（0x10df58..0x10dfa8）
 * @func 0x10df58 0x10dfa8  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10df58 push {r4, lr}
 *   @0x10df5c mov r3, #0
 *   @0x10df60 mov r4, r0
 *   @0x10df64 str r3, [r0, #0xc]
 *   @0x10df68 mov r1, r3
 *   @0x10df6c ldr r0, [sp, #0x8]
 *   @0x10df70 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x10df74 vldr d6, [pc, #28]
 *   @0x10df78 vldr d7, [pc, #32]
 *   @0x10df7c vmov d5, r0, r1
 *   @0x10df80 vmul.f64 d6, d5, d6
 *   @0x10df84 vdiv.f64 d5, d6, d7
 *   @0x10df88 vmov r2, r3, d5
 *   @0x10df8c stm r4, {r2, r3}
 *   @0x10df90 pop {r4, pc}
 *   @0x10df94 nop
 *   @0x10df98 andeq r0, r0, r0
 *   @0x10df9c rsbmi r8, r6, r0
 *   @0x10dfa0 andvs r0, r0, r0
 *   @0x10dfa4 strdmi r2, r3, [r9], -r11
 *
 * ══ §140/373 F_Sin(RValue&, CInstance*, CInstance*, int, RValue*)  0x10e4c4  size 80  20 条（0x10e4c4..0x10e514）
 * @func 0x10e4c4 0x10e514  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int) / 0xb6580
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10e4c4 mov r3, #0
 *   @0x10e4c8 push {r4, lr}
 *   @0x10e4cc mov r1, r3
 *   @0x10e4d0 str r3, [r0, #0xc]
 *   @0x10e4d4 mov r4, r0
 *   @0x10e4d8 ldr r0, [sp, #0x8]
 *   @0x10e4dc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10e4e0 bl 0xb6580 <sinf@plt>
 *   @0x10e4e4 vldr s14, [pc, #36]
 *   @0x10e4e8 vmov s15, r0
 *   @0x10e4ec vabs.f32 s13, s15
 *   @0x10e4f0 vcmpe.f32 s13, s14
 *   @0x10e4f4 vmrs APSR_nzcv, fpscr
 *   @0x10e4f8 vcvtpl.f64.f32 d6, s15
 *   @0x10e4fc movmi r2, #0
 *   @0x10e500 movmi r3, #0
 *   @0x10e504 vmovpl r2, r3, d6
 *   @0x10e508 stm r4, {r2, r3}
 *   @0x10e50c pop {r4, pc}
 *   @0x10e510 strlo r12, [r7, -r12, lsr #11]!
 *
 * ══ §141/373 F_Cos(RValue&, CInstance*, CInstance*, int, RValue*)  0x10e584  size 80  20 条（0x10e584..0x10e5d4）
 * @func 0x10e584 0x10e5d4  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int) / 0xb658c
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10e584 mov r3, #0
 *   @0x10e588 push {r4, lr}
 *   @0x10e58c mov r1, r3
 *   @0x10e590 str r3, [r0, #0xc]
 *   @0x10e594 mov r4, r0
 *   @0x10e598 ldr r0, [sp, #0x8]
 *   @0x10e59c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10e5a0 bl 0xb658c <cosf@plt>
 *   @0x10e5a4 vldr s14, [pc, #36]
 *   @0x10e5a8 vmov s15, r0
 *   @0x10e5ac vabs.f32 s13, s15
 *   @0x10e5b0 vcmpe.f32 s13, s14
 *   @0x10e5b4 vmrs APSR_nzcv, fpscr
 *   @0x10e5b8 vcvtpl.f64.f32 d6, s15
 *   @0x10e5bc movmi r2, #0
 *   @0x10e5c0 movmi r3, #0
 *   @0x10e5c4 vmovpl r2, r3, d6
 *   @0x10e5c8 stm r4, {r2, r3}
 *   @0x10e5cc pop {r4, pc}
 *   @0x10e5d0 strlo r12, [r7, -r12, lsr #11]!
 *
 * ══ §142/373 F_Tan(RValue&, CInstance*, CInstance*, int, RValue*)  0x10e644  size 80  20 条（0x10e644..0x10e694）
 * @func 0x10e644 0x10e694  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int) / 0xb6748
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10e644 mov r3, #0
 *   @0x10e648 push {r4, lr}
 *   @0x10e64c mov r1, r3
 *   @0x10e650 str r3, [r0, #0xc]
 *   @0x10e654 mov r4, r0
 *   @0x10e658 ldr r0, [sp, #0x8]
 *   @0x10e65c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10e660 bl 0xb6748 <tanf@plt>
 *   @0x10e664 vldr s14, [pc, #36]
 *   @0x10e668 vmov s15, r0
 *   @0x10e66c vabs.f32 s13, s15
 *   @0x10e670 vcmpe.f32 s13, s14
 *   @0x10e674 vmrs APSR_nzcv, fpscr
 *   @0x10e678 vcvtpl.f64.f32 d6, s15
 *   @0x10e67c movmi r2, #0
 *   @0x10e680 movmi r3, #0
 *   @0x10e684 vmovpl r2, r3, d6
 *   @0x10e688 stm r4, {r2, r3}
 *   @0x10e68c pop {r4, pc}
 *   @0x10e690 strlo r12, [r7, -r12, lsr #11]!
 *
 * ══ §143/373 F_ArcTan(RValue&, CInstance*, CInstance*, int, RValue*)  0x10e97c  size 80  20 条（0x10e97c..0x10e9cc）
 * @func 0x10e97c 0x10e9cc  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int) / 0xb676c
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10e97c mov r3, #0
 *   @0x10e980 push {r4, lr}
 *   @0x10e984 mov r1, r3
 *   @0x10e988 str r3, [r0, #0xc]
 *   @0x10e98c mov r4, r0
 *   @0x10e990 ldr r0, [sp, #0x8]
 *   @0x10e994 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10e998 bl 0xb676c <atanf@plt>
 *   @0x10e99c vldr s14, [pc, #36]
 *   @0x10e9a0 vmov s15, r0
 *   @0x10e9a4 vabs.f32 s13, s15
 *   @0x10e9a8 vcmpe.f32 s13, s14
 *   @0x10e9ac vmrs APSR_nzcv, fpscr
 *   @0x10e9b0 vcvtpl.f64.f32 d6, s15
 *   @0x10e9b4 movmi r2, #0
 *   @0x10e9b8 movmi r3, #0
 *   @0x10e9bc vmovpl r2, r3, d6
 *   @0x10e9c0 stm r4, {r2, r3}
 *   @0x10e9c4 pop {r4, pc}
 *   @0x10e9c8 strlo r12, [r7, -r12, lsr #11]!
 *
 * ══ §144/373 F_ShowDebugOverlay(RValue&, CInstance*, CInstance*, int, RValue*)  0x116708  size 80  20 条（0x116708..0x116758）
 * @func 0x116708 0x116758  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x8×1 / 0x28×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x116708 push {r3, lr}
 *   @0x11670c mov r1, #0
 *   @0x116710 ldr r0, [sp, #0x8]
 *   @0x116714 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x116718 cmp r0, #0
 *   @0x11671c bne 0x116738 <_Z18F_ShowDebugOverlayR6RValueP9CInstanceS2_iPS_+0x30>
 *   @0x116720 ldr r3, [pc, #0x28]
 *   @0x116724 ldr r3, [pc, r3]
 *   @0x116728 ldr r2, [r3]
 *   @0x11672c bic r2, r2, #2
 *   @0x116730 str r2, [r3]
 *   @0x116734 pop {r3, pc}
 *   @0x116738 ldr r3, [pc, #0x14]
 *   @0x11673c ldr r3, [pc, r3]
 *   @0x116740 ldr r2, [r3]
 *   @0x116744 orr r2, r2, #2
 *   @0x116748 str r2, [r3]
 *   @0x11674c pop {r3, pc}
 *   @0x116750 eoreq r7, sp, r8, lsl #26
 *   @0x116754 .word 0x002d7cf0
 *
 * ══ §145/373 F_ColorGetGreen(RValue&, CInstance*, CInstance*, int, RValue*)  0x119dbc  size 80  20 条（0x119dbc..0x119e0c）
 * @func 0x119dbc 0x119e20  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x119dbc push {r4, lr}
 *   @0x119dc0 mov r3, #0
 *   @0x119dc4 mov r4, r0
 *   @0x119dc8 str r3, [r0, #0xc]
 *   @0x119dcc mov r1, r3
 *   @0x119dd0 ldr r0, [sp, #0x8]
 *   @0x119dd4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x119dd8 add r3, r0, #255
 *   @0x119ddc cmp r0, #0
 *   @0x119de0 movlt r0, r3
 *   @0x119de4 asr r3, r0, #31
 *   @0x119de8 lsr r3, r3, #24
 *   @0x119dec add r0, r3, r0, asr #8
 *   @0x119df0 uxtb r2, r0
 *   @0x119df4 rsb r2, r3, r2
 *   @0x119df8 vmov s15, r2
 *   @0x119dfc vcvt.f64.s32 d7, s15
 *   @0x119e00 vmov r2, r3, d7
 *   @0x119e04 stm r4, {r2, r3}
 *   @0x119e08 pop {r4, pc}
 *
 * ══ §146/373 F_DrawSetSWFAAlevel(RValue&, CInstance*, CInstance*, int, RValue*)  0x11a2b4  size 80  20 条（0x11a2b4..0x11a304）
 * @func 0x11a2b4 0x11a304  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x8×1 / 0x14×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11a2b4 push {r3, lr}
 *   @0x11a2b8 mov r1, #0
 *   @0x11a2bc ldr r0, [sp, #0x8]
 *   @0x11a2c0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11a2c4 vmov s15, r0
 *   @0x11a2c8 vcmpe.f32 s15, #0
 *   @0x11a2cc vmrs APSR_nzcv, fpscr
 *   @0x11a2d0 bmi 0x11a2f4 <_Z19F_DrawSetSWFAAlevelR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x11a2d4 vmov.f32 s14, #1.000000e+00
 *   @0x11a2d8 vcmp.f32 s15, s14
 *   @0x11a2dc vmrs APSR_nzcv, fpscr
 *   @0x11a2e0 vmovgt.f32 s15, s14
 *   @0x11a2e4 ldr r3, [pc, #0x14]
 *   @0x11a2e8 ldr r3, [pc, r3]
 *   @0x11a2ec vstr s15, [r3]
 *   @0x11a2f0 pop {r3, pc}
 *   @0x11a2f4 vldr s15, [pc]
 *   @0x11a2f8 b 0x11a2e4 <_Z19F_DrawSetSWFAAlevelR6RValueP9CInstanceS2_iPS_+0x30>
 *   @0x11a2fc andeq r0, r0, r0
 *   @0x11a300 .word 0x002d42d0
 *
 * ══ §147/373 F_TileExists(RValue&, CInstance*, CInstance*, int, RValue*)  0x11c2ac  size 80  20 条（0x11c2ac..0x11c2fc）
 * @func 0x11c2ac 0x11c2fc  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CRoom::FindTile(int)
 * 字段偏移 top8: 0x3c×1 / 0x10×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11c2ac push {r3, r4, r5, lr}
 *   @0x11c2b0 mov r1, #0
 *   @0x11c2b4 ldr r3, [pc, #0x3c]
 *   @0x11c2b8 mov r4, r0
 *   @0x11c2bc ldr r0, [sp, #0x10]
 *   @0x11c2c0 ldr r3, [pc, r3]
 *   @0x11c2c4 ldr r5, [r3]
 *   @0x11c2c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11c2cc mov r1, r0
 *   @0x11c2d0 mov r0, r5
 *   @0x11c2d4 bl 0x1af2bc <_ZN5CRoom8FindTileEi>
 *   @0x11c2d8 mov r3, #0
 *   @0x11c2dc mov r2, r3
 *   @0x11c2e0 str r3, [r4, #0xc]
 *   @0x11c2e4 str r3, [r4]
 *   @0x11c2e8 cmp r0, r3
 *   @0x11c2ec movtge r2, #0x3ff0
 *   @0x11c2f0 str r2, [r4, #0x4]
 *   @0x11c2f4 pop {r3, r4, r5, pc}
 *   @0x11c2f8 eoreq r1, sp, r8, ror #12
 *
 * ══ §148/373 F_SurfaceGetPixel(RValue&, CInstance*, CInstance*, int, RValue*)  0x11f1a8  size 80  20 条（0x11f1a8..0x11f1f8）
 * @func 0x11f1a8 0x11f1f8  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_SurfaceGetPixelExt(RValue&, CInstance*, CInstance*, int, RValue*)
 * 字段偏移 top8: 0x10×1 / 0x4×1 / 0xc×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11f1a8 push {r4, lr}
 *   @0x11f1ac sub sp, sp, #8
 *   @0x11f1b0 mov r4, r0
 *   @0x11f1b4 ldr r12, [sp, #0x10]
 *   @0x11f1b8 str r12, [sp]
 *   @0x11f1bc bl 0x11f0d0 <_Z20F_SurfaceGetPixelExtR6RValueP9CInstanceS2_iPS_>
 *   @0x11f1c0 ldr r2, [r4]
 *   @0x11f1c4 ldr r3, [r4, #0x4]
 *   @0x11f1c8 mov r1, #0
 *   @0x11f1cc str r1, [r4, #0xc]
 *   @0x11f1d0 vmov d7, r2, r3
 *   @0x11f1d4 vcvt.u32.f64 s15, d7
 *   @0x11f1d8 vmov r2, s15
 *   @0x11f1dc bic r2, r2, #-16777216
 *   @0x11f1e0 vmov s15, r2
 *   @0x11f1e4 vcvt.f64.s32 d7, s15
 *   @0x11f1e8 vmov r2, r3, d7
 *   @0x11f1ec stm r4, {r2, r3}
 *   @0x11f1f0 add sp, sp, #8
 *   @0x11f1f4 pop {r4, pc}
 *
 * ══ §149/373 F_SplashShowVideo(RValue&, CInstance*, CInstance*, int, RValue*)  0x126248  size 80  20 条（0x126248..0x126298）
 * @func 0x126248 0x126298  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int) / YYGetBool(RValue const*, int) / Splash_Show_Movie(char const*, bool) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x10×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x126248 push {r3, r4, r5, lr}
 *   @0x12624c mov r1, #0
 *   @0x126250 ldr r4, [sp, #0x10]
 *   @0x126254 mov r0, r4
 *   @0x126258 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x12625c mov r1, #1
 *   @0x126260 mov r5, r0
 *   @0x126264 mov r0, r4
 *   @0x126268 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x12626c mov r1, r0
 *   @0x126270 mov r0, r5
 *   @0x126274 bl 0x1dc774 <_Z17Splash_Show_MoviePKcb>
 *   @0x126278 subs r1, r0, #0
 *   @0x12627c bne 0x12628c <_Z17F_SplashShowVideoR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x126280 ldr r0, [pc, #0xc]
 *   @0x126284 add r0, pc, r0
 *   @0x126288 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x12628c pop {r3, r4, r5, lr}
 *   @0x126290 b 0x18c2c8 <_Z8IO_Clearv>
 *   @0x126294 eoreq r5, r1, r8, ror lr
 *
 * ══ §150/373 F_ShowMessageExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x126350  size 80  20 条（0x126350..0x1263a0）
 * @func 0x126350 0x1263a0  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×2 / 0x40×1 / 0x34×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x126350 ldr r3, [pc, #0x40]
 *   @0x126354 push {r4, lr}
 *   @0x126358 ldr r3, [pc, r3]
 *   @0x12635c mov r4, r0
 *   @0x126360 ldr r1, [pc, #0x34]
 *   @0x126364 ldr r0, [r3]
 *   @0x126368 add r1, pc, r1
 *   @0x12636c ldr r3, [r0]
 *   @0x126370 ldr r3, [r3, #0xc]
 *   @0x126374 blx r3
 *   @0x126378 mov r2, #0
 *   @0x12637c mov r3, r2
 *   @0x126380 movt r2, #0x3ff0
 *   @0x126384 str r3, [r4, #0xc]
 *   @0x126388 str r2, [r4, #0x4]
 *   @0x12638c str r3, [r4]
 *   @0x126390 pop {r4, lr}
 *   @0x126394 b 0x18c2c8 <_Z8IO_Clearv>
 *   @0x126398 .word 0x002c73bc
 *   @0x12639c eoreq r5, r1, r0, ror #27
 *
 * ══ §151/373 F_SplashShowImage(RValue&, CInstance*, CInstance*, int, RValue*)  0x126478  size 80  20 条（0x126478..0x1264c8）
 * @func 0x126478 0x1264c8  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int) / YYGetInt32(RValue const*, int) / Splash_Show_Image(char const*, int) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x10×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x126478 push {r3, r4, r5, lr}
 *   @0x12647c mov r1, #0
 *   @0x126480 ldr r4, [sp, #0x10]
 *   @0x126484 mov r0, r4
 *   @0x126488 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x12648c mov r1, #1
 *   @0x126490 mov r5, r0
 *   @0x126494 mov r0, r4
 *   @0x126498 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12649c mov r1, r0
 *   @0x1264a0 mov r0, r5
 *   @0x1264a4 bl 0x1dc77c <_Z17Splash_Show_ImagePKci>
 *   @0x1264a8 subs r1, r0, #0
 *   @0x1264ac bne 0x1264bc <_Z17F_SplashShowImageR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x1264b0 ldr r0, [pc, #0xc]
 *   @0x1264b4 add r0, pc, r0
 *   @0x1264b8 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1264bc pop {r3, r4, r5, lr}
 *   @0x1264c0 b 0x18c2c8 <_Z8IO_Clearv>
 *   @0x1264c4 eoreq r5, r1, r0, asr sp
 *
 * ══ §152/373 F_SplashShowText(RValue&, CInstance*, CInstance*, int, RValue*)  0x12654c  size 80  20 条（0x12654c..0x12659c）
 * @func 0x12654c 0x12659c  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int) / YYGetInt32(RValue const*, int) / Splash_Show_Text(char const*, int) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x10×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12654c push {r3, r4, r5, lr}
 *   @0x126550 mov r1, #0
 *   @0x126554 ldr r4, [sp, #0x10]
 *   @0x126558 mov r0, r4
 *   @0x12655c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x126560 mov r1, #1
 *   @0x126564 mov r5, r0
 *   @0x126568 mov r0, r4
 *   @0x12656c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x126570 mov r1, r0
 *   @0x126574 mov r0, r5
 *   @0x126578 bl 0x1dc784 <_Z16Splash_Show_TextPKci>
 *   @0x12657c subs r1, r0, #0
 *   @0x126580 bne 0x126590 <_Z16F_SplashShowTextR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x126584 ldr r0, [pc, #0xc]
 *   @0x126588 add r0, pc, r0
 *   @0x12658c bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x126590 pop {r3, r4, r5, lr}
 *   @0x126594 b 0x18c2c8 <_Z8IO_Clearv>
 *   @0x126598 mlaeq r1, r4, r12, r5
 *
 * ══ §153/373 F_BackgroundGetWidth(RValue&, CInstance*, CInstance*, int, RValue*)  0x12c208  size 80  20 条（0x12c208..0x12c258）
 * @func 0x12c208 0x12c26c  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Background_Data(int) / CBackground::GetWidth()
 * 字段偏移 top8: 0x8×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12c208 push {r4, lr}
 *   @0x12c20c mov r1, #0
 *   @0x12c210 mov r4, r0
 *   @0x12c214 ldr r0, [sp, #0x8]
 *   @0x12c218 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12c21c bl 0xc3794 <_Z15Background_Datai>
 *   @0x12c220 cmp r0, #0
 *   @0x12c224 beq 0x12c248 <_Z20F_BackgroundGetWidthR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x12c228 bl 0xc2d78 <_ZN11CBackground8GetWidthEv>
 *   @0x12c22c vmov s15, r0
 *   @0x12c230 vcvt.f64.s32 d7, s15
 *   @0x12c234 vmov r2, r3, d7
 *   @0x12c238 mov r1, #0
 *   @0x12c23c stm r4, {r2, r3}
 *   @0x12c240 str r1, [r4, #0xc]
 *   @0x12c244 pop {r4, pc}
 *   @0x12c248 mov r3, #0
 *   @0x12c24c mov r2, #0
 *   @0x12c250 movt r3, #0xbff0
 *   @0x12c254 b 0x12c238 <_Z20F_BackgroundGetWidthR6RValueP9CInstanceS2_iPS_+0x30>
 *
 * ══ §154/373 F_BackgroundGetHeight(RValue&, CInstance*, CInstance*, int, RValue*)  0x12c258  size 80  20 条（0x12c258..0x12c2a8）
 * @func 0x12c258 0x12c2bc  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Background_Data(int) / CBackground::GetHeight()
 * 字段偏移 top8: 0x8×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12c258 push {r4, lr}
 *   @0x12c25c mov r1, #0
 *   @0x12c260 mov r4, r0
 *   @0x12c264 ldr r0, [sp, #0x8]
 *   @0x12c268 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12c26c bl 0xc3794 <_Z15Background_Datai>
 *   @0x12c270 cmp r0, #0
 *   @0x12c274 beq 0x12c298 <_Z21F_BackgroundGetHeightR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x12c278 bl 0xc2d80 <_ZN11CBackground9GetHeightEv>
 *   @0x12c27c vmov s15, r0
 *   @0x12c280 vcvt.f64.s32 d7, s15
 *   @0x12c284 vmov r2, r3, d7
 *   @0x12c288 mov r1, #0
 *   @0x12c28c stm r4, {r2, r3}
 *   @0x12c290 str r1, [r4, #0xc]
 *   @0x12c294 pop {r4, pc}
 *   @0x12c298 mov r3, #0
 *   @0x12c29c mov r2, #0
 *   @0x12c2a0 movt r3, #0xbff0
 *   @0x12c2a4 b 0x12c288 <_Z21F_BackgroundGetHeightR6RValueP9CInstanceS2_iPS_+0x30>
 *
 * ══ §155/373 F_BackgroundGetTransparent(RValue&, CInstance*, CInstance*, int, RValue*)  0x12c2a8  size 80  20 条（0x12c2a8..0x12c2f8）
 * @func 0x12c2a8 0x12c30c  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Background_Data(int) / CBackground::GetTransparent()
 * 字段偏移 top8: 0x8×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12c2a8 push {r4, lr}
 *   @0x12c2ac mov r1, #0
 *   @0x12c2b0 mov r4, r0
 *   @0x12c2b4 ldr r0, [sp, #0x8]
 *   @0x12c2b8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12c2bc bl 0xc3794 <_Z15Background_Datai>
 *   @0x12c2c0 cmp r0, #0
 *   @0x12c2c4 beq 0x12c2e8 <_Z26F_BackgroundGetTransparentR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x12c2c8 bl 0xc2d88 <_ZN11CBackground14GetTransparentEv>
 *   @0x12c2cc vmov s15, r0
 *   @0x12c2d0 vcvt.f64.s32 d7, s15
 *   @0x12c2d4 vmov r2, r3, d7
 *   @0x12c2d8 mov r1, #0
 *   @0x12c2dc stm r4, {r2, r3}
 *   @0x12c2e0 str r1, [r4, #0xc]
 *   @0x12c2e4 pop {r4, pc}
 *   @0x12c2e8 mov r3, #0
 *   @0x12c2ec mov r2, #0
 *   @0x12c2f0 movt r3, #0xbff0
 *   @0x12c2f4 b 0x12c2d8 <_Z26F_BackgroundGetTransparentR6RValueP9CInstanceS2_iPS_+0x30>
 *
 * ══ §156/373 F_BackgroundGetSmooth(RValue&, CInstance*, CInstance*, int, RValue*)  0x12c2f8  size 80  20 条（0x12c2f8..0x12c348）
 * @func 0x12c2f8 0x12c35c  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Background_Data(int) / CBackground::Smooth()
 * 字段偏移 top8: 0x8×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12c2f8 push {r4, lr}
 *   @0x12c2fc mov r1, #0
 *   @0x12c300 mov r4, r0
 *   @0x12c304 ldr r0, [sp, #0x8]
 *   @0x12c308 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12c30c bl 0xc3794 <_Z15Background_Datai>
 *   @0x12c310 cmp r0, #0
 *   @0x12c314 beq 0x12c338 <_Z21F_BackgroundGetSmoothR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x12c318 bl 0xc2d90 <_ZN11CBackground6SmoothEv>
 *   @0x12c31c vmov s15, r0
 *   @0x12c320 vcvt.f64.s32 d7, s15
 *   @0x12c324 vmov r2, r3, d7
 *   @0x12c328 mov r1, #0
 *   @0x12c32c stm r4, {r2, r3}
 *   @0x12c330 str r1, [r4, #0xc]
 *   @0x12c334 pop {r4, pc}
 *   @0x12c338 mov r3, #0
 *   @0x12c33c mov r2, #0
 *   @0x12c340 movt r3, #0xbff0
 *   @0x12c344 b 0x12c328 <_Z21F_BackgroundGetSmoothR6RValueP9CInstanceS2_iPS_+0x30>
 *
 * ══ §157/373 F_BackgroundGetPreload(RValue&, CInstance*, CInstance*, int, RValue*)  0x12c348  size 80  20 条（0x12c348..0x12c398）
 * @func 0x12c348 0x12c398  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Background_Data(int) / CBackground::GetPreload()
 * 字段偏移 top8: 0x8×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12c348 push {r4, lr}
 *   @0x12c34c mov r1, #0
 *   @0x12c350 mov r4, r0
 *   @0x12c354 ldr r0, [sp, #0x8]
 *   @0x12c358 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12c35c bl 0xc3794 <_Z15Background_Datai>
 *   @0x12c360 cmp r0, #0
 *   @0x12c364 beq 0x12c388 <_Z22F_BackgroundGetPreloadR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x12c368 bl 0xc2d98 <_ZN11CBackground10GetPreloadEv>
 *   @0x12c36c vmov s15, r0
 *   @0x12c370 vcvt.f64.s32 d7, s15
 *   @0x12c374 vmov r2, r3, d7
 *   @0x12c378 mov r1, #0
 *   @0x12c37c stm r4, {r2, r3}
 *   @0x12c380 str r1, [r4, #0xc]
 *   @0x12c384 pop {r4, pc}
 *   @0x12c388 mov r3, #0
 *   @0x12c38c mov r2, #0
 *   @0x12c390 movt r3, #0xbff0
 *   @0x12c394 b 0x12c378 <_Z22F_BackgroundGetPreloadR6RValueP9CInstanceS2_iPS_+0x30>
 *
 * ══ §158/373 F_FontGetFirst(RValue&, CInstance*, CInstance*, int, RValue*)  0x12ce88  size 80  20 条（0x12ce88..0x12ced8）
 * @func 0x12ce88 0x12ceec  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Font_Data(int) / CFontGM::GetFirst()
 * 字段偏移 top8: 0x8×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12ce88 push {r4, lr}
 *   @0x12ce8c mov r1, #0
 *   @0x12ce90 mov r4, r0
 *   @0x12ce94 ldr r0, [sp, #0x8]
 *   @0x12ce98 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12ce9c bl 0xfa3fc <_Z9Font_Datai>
 *   @0x12cea0 cmp r0, #0
 *   @0x12cea4 beq 0x12cec8 <_Z14F_FontGetFirstR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x12cea8 bl 0xf93e8 <_ZN7CFontGM8GetFirstEv>
 *   @0x12ceac vmov s15, r0
 *   @0x12ceb0 vcvt.f64.s32 d7, s15
 *   @0x12ceb4 vmov r2, r3, d7
 *   @0x12ceb8 mov r1, #0
 *   @0x12cebc stm r4, {r2, r3}
 *   @0x12cec0 str r1, [r4, #0xc]
 *   @0x12cec4 pop {r4, pc}
 *   @0x12cec8 mov r3, #0
 *   @0x12cecc mov r2, #0
 *   @0x12ced0 movt r3, #0xbff0
 *   @0x12ced4 b 0x12ceb8 <_Z14F_FontGetFirstR6RValueP9CInstanceS2_iPS_+0x30>
 *
 * ══ §159/373 F_FontGetLast(RValue&, CInstance*, CInstance*, int, RValue*)  0x12ced8  size 80  20 条（0x12ced8..0x12cf28）
 * @func 0x12ced8 0x12cf28  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Font_Data(int) / CFontGM::GetLast()
 * 字段偏移 top8: 0x8×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12ced8 push {r4, lr}
 *   @0x12cedc mov r1, #0
 *   @0x12cee0 mov r4, r0
 *   @0x12cee4 ldr r0, [sp, #0x8]
 *   @0x12cee8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12ceec bl 0xfa3fc <_Z9Font_Datai>
 *   @0x12cef0 cmp r0, #0
 *   @0x12cef4 beq 0x12cf18 <_Z13F_FontGetLastR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x12cef8 bl 0xf93f0 <_ZN7CFontGM7GetLastEv>
 *   @0x12cefc vmov s15, r0
 *   @0x12cf00 vcvt.f64.s32 d7, s15
 *   @0x12cf04 vmov r2, r3, d7
 *   @0x12cf08 mov r1, #0
 *   @0x12cf0c stm r4, {r2, r3}
 *   @0x12cf10 str r1, [r4, #0xc]
 *   @0x12cf14 pop {r4, pc}
 *   @0x12cf18 mov r3, #0
 *   @0x12cf1c mov r2, #0
 *   @0x12cf20 movt r3, #0xbff0
 *   @0x12cf24 b 0x12cf08 <_Z13F_FontGetLastR6RValueP9CInstanceS2_iPS_+0x30>
 *
 * ══ §160/373 F_PathGetLength(RValue&, CInstance*, CInstance*, int, RValue*)  0x12d3f8  size 80  20 条（0x12d3f8..0x12d448）
 * @func 0x12d3f8 0x12d448  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Path_Data(int) / CPath::GetPathLength()
 * 字段偏移 top8: 0x8×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12d3f8 push {r4, lr}
 *   @0x12d3fc mov r1, #0
 *   @0x12d400 mov r4, r0
 *   @0x12d404 ldr r0, [sp, #0x8]
 *   @0x12d408 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12d40c bl 0x1a815c <_Z9Path_Datai>
 *   @0x12d410 cmp r0, #0
 *   @0x12d414 beq 0x12d438 <_Z15F_PathGetLengthR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x12d418 bl 0x1a7ab8 <_ZN5CPath13GetPathLengthEv>
 *   @0x12d41c vmov s15, r0
 *   @0x12d420 vcvt.f64.f32 d7, s15
 *   @0x12d424 vmov r2, r3, d7
 *   @0x12d428 mov r1, #0
 *   @0x12d42c stm r4, {r2, r3}
 *   @0x12d430 str r1, [r4, #0xc]
 *   @0x12d434 pop {r4, pc}
 *   @0x12d438 mov r3, #0
 *   @0x12d43c mov r2, #0
 *   @0x12d440 movt r3, #0xbff0
 *   @0x12d444 b 0x12d428 <_Z15F_PathGetLengthR6RValueP9CInstanceS2_iPS_+0x30>
 *
 * ══ §161/373 F_PathGetKind(RValue&, CInstance*, CInstance*, int, RValue*)  0x12d53c  size 80  20 条（0x12d53c..0x12d58c）
 * @func 0x12d53c 0x12d58c  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Path_Data(int) / CPath::GetKind()
 * 字段偏移 top8: 0x8×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12d53c push {r4, lr}
 *   @0x12d540 mov r1, #0
 *   @0x12d544 mov r4, r0
 *   @0x12d548 ldr r0, [sp, #0x8]
 *   @0x12d54c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12d550 bl 0x1a815c <_Z9Path_Datai>
 *   @0x12d554 cmp r0, #0
 *   @0x12d558 beq 0x12d57c <_Z13F_PathGetKindR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x12d55c bl 0x1a7bd0 <_ZN5CPath7GetKindEv>
 *   @0x12d560 vmov s15, r0
 *   @0x12d564 vcvt.f64.s32 d7, s15
 *   @0x12d568 vmov r2, r3, d7
 *   @0x12d56c mov r1, #0
 *   @0x12d570 stm r4, {r2, r3}
 *   @0x12d574 str r1, [r4, #0xc]
 *   @0x12d578 pop {r4, pc}
 *   @0x12d57c mov r3, #0
 *   @0x12d580 mov r2, #0
 *   @0x12d584 movt r3, #0xbff0
 *   @0x12d588 b 0x12d56c <_Z13F_PathGetKindR6RValueP9CInstanceS2_iPS_+0x30>
 *
 * ══ §162/373 F_PathGetPrecision(RValue&, CInstance*, CInstance*, int, RValue*)  0x12d5e4  size 80  20 条（0x12d5e4..0x12d634）
 * @func 0x12d5e4 0x12d648  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Path_Data(int) / CPath::GetPrecision()
 * 字段偏移 top8: 0x8×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12d5e4 push {r4, lr}
 *   @0x12d5e8 mov r1, #0
 *   @0x12d5ec mov r4, r0
 *   @0x12d5f0 ldr r0, [sp, #0x8]
 *   @0x12d5f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12d5f8 bl 0x1a815c <_Z9Path_Datai>
 *   @0x12d5fc cmp r0, #0
 *   @0x12d600 beq 0x12d624 <_Z18F_PathGetPrecisionR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x12d604 bl 0x1a7be0 <_ZN5CPath12GetPrecisionEv>
 *   @0x12d608 vmov s15, r0
 *   @0x12d60c vcvt.f64.s32 d7, s15
 *   @0x12d610 vmov r2, r3, d7
 *   @0x12d614 mov r1, #0
 *   @0x12d618 stm r4, {r2, r3}
 *   @0x12d61c str r1, [r4, #0xc]
 *   @0x12d620 pop {r4, pc}
 *   @0x12d624 mov r3, #0
 *   @0x12d628 mov r2, #0
 *   @0x12d62c movt r3, #0xbff0
 *   @0x12d630 b 0x12d614 <_Z18F_PathGetPrecisionR6RValueP9CInstanceS2_iPS_+0x30>
 *
 * ══ §163/373 F_PathGetNumber(RValue&, CInstance*, CInstance*, int, RValue*)  0x12d634  size 80  20 条（0x12d634..0x12d684）
 * @func 0x12d634 0x12d684  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Path_Data(int) / CPath::GetCount()
 * 字段偏移 top8: 0x8×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12d634 push {r4, lr}
 *   @0x12d638 mov r1, #0
 *   @0x12d63c mov r4, r0
 *   @0x12d640 ldr r0, [sp, #0x8]
 *   @0x12d644 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12d648 bl 0x1a815c <_Z9Path_Datai>
 *   @0x12d64c cmp r0, #0
 *   @0x12d650 beq 0x12d674 <_Z15F_PathGetNumberR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x12d654 bl 0x1a7bc8 <_ZN5CPath8GetCountEv>
 *   @0x12d658 vmov s15, r0
 *   @0x12d65c vcvt.f64.s32 d7, s15
 *   @0x12d660 vmov r2, r3, d7
 *   @0x12d664 mov r1, #0
 *   @0x12d668 stm r4, {r2, r3}
 *   @0x12d66c str r1, [r4, #0xc]
 *   @0x12d670 pop {r4, pc}
 *   @0x12d674 mov r3, #0
 *   @0x12d678 mov r2, #0
 *   @0x12d67c movt r3, #0xbff0
 *   @0x12d680 b 0x12d664 <_Z15F_PathGetNumberR6RValueP9CInstanceS2_iPS_+0x30>
 *
 * ══ §164/373 F_PathReScale(RValue&, CInstance*, CInstance*, int, RValue*)  0x12dd0c  size 80  20 条（0x12dd0c..0x12dd5c）
 * @func 0x12dd0c 0x12dd70  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / YYGetInt32(RValue const*, int) / Path_Data(int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12dd0c push {r4, r5, r6, lr}
 *   @0x12dd10 mov r1, #0
 *   @0x12dd14 ldr r4, [sp, #0x10]
 *   @0x12dd18 mov r0, r4
 *   @0x12dd1c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12dd20 bl 0x1a815c <_Z9Path_Datai>
 *   @0x12dd24 subs r5, r0, #0
 *   @0x12dd28 popeq {r4, r5, r6, pc}
 *   @0x12dd2c mov r0, r4
 *   @0x12dd30 mov r1, #1
 *   @0x12dd34 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x12dd38 mov r1, #2
 *   @0x12dd3c mov r6, r0
 *   @0x12dd40 mov r0, r4
 *   @0x12dd44 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x12dd48 mov r1, r6
 *   @0x12dd4c mov r2, r0
 *   @0x12dd50 mov r0, r5
 *   @0x12dd54 pop {r4, r5, r6, lr}
 *   @0x12dd58 b 0x1a794c <_ZN5CPath5ScaleEff>
 *
 * ══ §165/373 F_PathShift(RValue&, CInstance*, CInstance*, int, RValue*)  0x12dd5c  size 80  20 条（0x12dd5c..0x12ddac）
 * @func 0x12dd5c 0x12ddac  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / YYGetInt32(RValue const*, int) / Path_Data(int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12dd5c push {r4, r5, r6, lr}
 *   @0x12dd60 mov r1, #0
 *   @0x12dd64 ldr r4, [sp, #0x10]
 *   @0x12dd68 mov r0, r4
 *   @0x12dd6c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12dd70 bl 0x1a815c <_Z9Path_Datai>
 *   @0x12dd74 subs r5, r0, #0
 *   @0x12dd78 popeq {r4, r5, r6, pc}
 *   @0x12dd7c mov r0, r4
 *   @0x12dd80 mov r1, #1
 *   @0x12dd84 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x12dd88 mov r1, #2
 *   @0x12dd8c mov r6, r0
 *   @0x12dd90 mov r0, r4
 *   @0x12dd94 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x12dd98 mov r1, r6
 *   @0x12dd9c mov r2, r0
 *   @0x12dda0 mov r0, r5
 *   @0x12dda4 pop {r4, r5, r6, lr}
 *   @0x12dda8 b 0x1a7734 <_ZN5CPath5ShiftEff>
 *
 * ══ §166/373 F_TimeLineSize(RValue&, CInstance*, CInstance*, int, RValue*)  0x12dfb0  size 80  20 条（0x12dfb0..0x12e000）
 * @func 0x12dfb0 0x12e000  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / TimeLine_Data(int) / CTimeLine::GetCount()
 * 字段偏移 top8: 0x8×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12dfb0 push {r4, lr}
 *   @0x12dfb4 mov r1, #0
 *   @0x12dfb8 mov r4, r0
 *   @0x12dfbc ldr r0, [sp, #0x8]
 *   @0x12dfc0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12dfc4 bl 0x1f2c48 <_Z13TimeLine_Datai>
 *   @0x12dfc8 cmp r0, #0
 *   @0x12dfcc beq 0x12dff0 <_Z14F_TimeLineSizeR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x12dfd0 bl 0x1f1760 <_ZN9CTimeLine8GetCountEv>
 *   @0x12dfd4 vmov s15, r0
 *   @0x12dfd8 vcvt.f64.s32 d7, s15
 *   @0x12dfdc vmov r2, r3, d7
 *   @0x12dfe0 mov r1, #0
 *   @0x12dfe4 stm r4, {r2, r3}
 *   @0x12dfe8 str r1, [r4, #0xc]
 *   @0x12dfec pop {r4, pc}
 *   @0x12dff0 mov r3, #0
 *   @0x12dff4 mov r2, #0
 *   @0x12dff8 movt r3, #0xbff0
 *   @0x12dffc b 0x12dfe0 <_Z14F_TimeLineSizeR6RValueP9CInstanceS2_iPS_+0x30>
 *
 * ══ §167/373 F_RoomSetCaption(RValue&, CInstance*, CInstance*, int, RValue*)  0x12fd70  size 80  20 条（0x12fd70..0x12fdc0）
 * @func 0x12fd70 0x12fdd4  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Room_Data(int) / YYGetString(RValue const*, int) / YYFree(void const*) / YYStrDup(char const*)
 * 字段偏移 top8: 0x8×2 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12fd70 push {r3, r4, r5, lr}
 *   @0x12fd74 mov r1, #0
 *   @0x12fd78 ldr r4, [sp, #0x10]
 *   @0x12fd7c mov r0, r4
 *   @0x12fd80 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12fd84 bl 0x1b52c4 <_Z9Room_Datai>
 *   @0x12fd88 subs r5, r0, #0
 *   @0x12fd8c popeq {r3, r4, r5, pc}
 *   @0x12fd90 mov r0, r4
 *   @0x12fd94 mov r1, #1
 *   @0x12fd98 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x12fd9c mov r4, r0
 *   @0x12fda0 ldr r0, [r5, #0x8]
 *   @0x12fda4 cmp r0, #0
 *   @0x12fda8 beq 0x12fdb0 <_Z16F_RoomSetCaptionR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x12fdac bl 0xcef90 <_Z6YYFreePKv>
 *   @0x12fdb0 mov r0, r4
 *   @0x12fdb4 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x12fdb8 str r0, [r5, #0x8]
 *   @0x12fdbc pop {r3, r4, r5, pc}
 *
 * ══ §168/373 F_RoomSetCode(RValue&, CInstance*, CInstance*, int, RValue*)  0x12fdc0  size 80  20 条（0x12fdc0..0x12fe10）
 * @func 0x12fdc0 0x12fe10  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Room_Data(int) / YYGetString(RValue const*, int) / YYFree(void const*) / YYStrDup(char const*)
 * 字段偏移 top8: 0x68×2 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12fdc0 push {r3, r4, r5, lr}
 *   @0x12fdc4 mov r1, #0
 *   @0x12fdc8 ldr r4, [sp, #0x10]
 *   @0x12fdcc mov r0, r4
 *   @0x12fdd0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12fdd4 bl 0x1b52c4 <_Z9Room_Datai>
 *   @0x12fdd8 subs r5, r0, #0
 *   @0x12fddc popeq {r3, r4, r5, pc}
 *   @0x12fde0 mov r0, r4
 *   @0x12fde4 mov r1, #1
 *   @0x12fde8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x12fdec mov r4, r0
 *   @0x12fdf0 ldr r0, [r5, #0x68]
 *   @0x12fdf4 cmp r0, #0
 *   @0x12fdf8 beq 0x12fe00 <_Z13F_RoomSetCodeR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x12fdfc bl 0xcef90 <_Z6YYFreePKv>
 *   @0x12fe00 mov r0, r4
 *   @0x12fe04 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x12fe08 str r0, [r5, #0x68]
 *   @0x12fe0c pop {r3, r4, r5, pc}
 *
 * ══ §169/373 F_SpriteSetOffset(RValue&, CInstance*, CInstance*, int, RValue*)  0x130d54  size 80  20 条（0x130d54..0x130da4）
 * @func 0x130d54 0x130da4  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / Sprite_Data(int)
 * 字段偏移 top8: 0x10×1 / 0x24×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x130d54 push {r4, r5, r6, lr}
 *   @0x130d58 mov r1, #0
 *   @0x130d5c ldr r4, [sp, #0x10]
 *   @0x130d60 mov r0, r4
 *   @0x130d64 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x130d68 mov r6, r0
 *   @0x130d6c bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x130d70 subs r5, r0, #0
 *   @0x130d74 popeq {r4, r5, r6, pc}
 *   @0x130d78 mov r0, r4
 *   @0x130d7c mov r1, #1
 *   @0x130d80 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x130d84 mov r1, #2
 *   @0x130d88 str r0, [r5, #0x24]
 *   @0x130d8c mov r0, r4
 *   @0x130d90 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x130d94 str r0, [r5, #0x28]
 *   @0x130d98 mov r0, r6
 *   @0x130d9c pop {r4, r5, r6, lr}
 *   @0x130da0 b 0x130cac <_Z20MarkInstancesAsDirtyi>
 *
 * ══ §170/373 yyFindData::Reset()  0x13aac0  size 80  20 条（0x13aac0..0x13ab10）
 * @func 0x13aac0 0x13ab10  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb655c×2 / yyFindData::Reset()+0x34
 * 字段偏移 top8: 0x4×3 / 0x8×3 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13aac0 push {r3, r4, r5, lr}
 *   @0x13aac4 mov r5, r0
 *   @0x13aac8 ldr r3, [r0, #0x4]
 *   @0x13aacc cmp r3, #0
 *   @0x13aad0 movgt r4, #0
 *   @0x13aad4 ble 0x13aaf4 <_ZN10yyFindData5ResetEv+0x34>
 *   @0x13aad8 ldr r3, [r5, #0x8]
 *   @0x13aadc ldr r0, [r3, r4, lsl #2]
 *   @0x13aae0 add r4, r4, #1
 *   @0x13aae4 bl 0xb655c <free@plt>
 *   @0x13aae8 ldr r3, [r5, #0x4]
 *   @0x13aaec cmp r3, r4
 *   @0x13aaf0 bgt 0x13aad8 <_ZN10yyFindData5ResetEv+0x18>
 *   @0x13aaf4 ldr r0, [r5, #0x8]
 *   @0x13aaf8 bl 0xb655c <free@plt>
 *   @0x13aafc mov r3, #0
 *   @0x13ab00 str r3, [r5, #0x8]
 *   @0x13ab04 str r3, [r5]
 *   @0x13ab08 str r3, [r5, #0x4]
 *   @0x13ab0c pop {r3, r4, r5, pc}
 *
 * ══ §171/373 EncodeDSList(CDS_List*)  0x13c0e0  size 80  20 条（0x13c0e0..0x13c130）
 * @func 0x13c0e0 0x13c130  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: json_object_new_array / EncodeDSList(CDS_List*)+0x48 / EncodeValue(RValue*) / json_object_array_add
 * 字段偏移 top8: 0x4×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13c0e0 push {r4, r5, r6, lr}
 *   @0x13c0e4 mov r5, r0
 *   @0x13c0e8 bl 0x27ed80 <json_object_new_array>
 *   @0x13c0ec ldr r3, [r5, #0x4]
 *   @0x13c0f0 cmp r3, #0
 *   @0x13c0f4 mov r6, r0
 *   @0x13c0f8 ble 0x13c128 <_Z12EncodeDSListP8CDS_List+0x48>
 *   @0x13c0fc mov r4, #0
 *   @0x13c100 ldr r0, [r5, #0xc]
 *   @0x13c104 add r0, r0, r4, lsl #4
 *   @0x13c108 add r4, r4, #1
 *   @0x13c10c bl 0x13be2c <_Z11EncodeValueP6RValue>
 *   @0x13c110 mov r1, r0
 *   @0x13c114 mov r0, r6
 *   @0x13c118 bl 0x27edf0 <json_object_array_add>
 *   @0x13c11c ldr r3, [r5, #0x4]
 *   @0x13c120 cmp r3, r4
 *   @0x13c124 bgt 0x13c100 <_Z12EncodeDSListP8CDS_List+0x20>
 *   @0x13c128 mov r0, r6
 *   @0x13c12c pop {r4, r5, r6, pc}
 *
 * ══ §172/373 ParamStr(char const*&, int)  0x13c3f0  size 80  20 条（0x13c3f0..0x13c440）
 * @func 0x13c3f0 0x13c440  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParamStr(char const*&, int)+0x24 / ParamStr(char const*&, int)+0x30 / YYStrDup(char const*)
 * 字段偏移 top8: 0x30×1 / 0x14×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13c3f0 cmp r1, #0
 *   @0x13c3f4 push {r4, lr}
 *   @0x13c3f8 mov r4, r0
 *   @0x13c3fc blt 0x13c414 <_Z8ParamStrRPKci+0x24>
 *   @0x13c400 ldr r3, [pc, #0x30]
 *   @0x13c404 ldr r3, [pc, r3]
 *   @0x13c408 ldr r3, [r3]
 *   @0x13c40c cmp r1, r3
 *   @0x13c410 blt 0x13c420 <_Z8ParamStrRPKci+0x30>
 *   @0x13c414 mov r3, #0
 *   @0x13c418 str r3, [r4]
 *   @0x13c41c pop {r4, pc}
 *   @0x13c420 ldr r3, [pc, #0x14]
 *   @0x13c424 ldr r3, [pc, r3]
 *   @0x13c428 ldr r0, [r3, r1, lsl #2]
 *   @0x13c42c bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x13c430 str r0, [r4]
 *   @0x13c434 pop {r4, pc}
 *   @0x13c438 mlaeq r11, r12, lr, r2
 *   @0x13c43c eoreq r2, r11, r0, lsl #29
 *
 * ══ §173/373 F_ActionMoveContact(RValue&, CInstance*, CInstance*, int, RValue*)  0x13df9c  size 80  20 条（0x13df9c..0x13dfec）
 * @func 0x13df9c 0x13dfec  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13df9c push {r4, r5, r6, r7, r8, lr}
 *   @0x13dfa0 mov r7, r1
 *   @0x13dfa4 ldr r4, [sp, #0x18]
 *   @0x13dfa8 mov r1, #0
 *   @0x13dfac mov r0, r4
 *   @0x13dfb0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13dfb4 mov r1, #1
 *   @0x13dfb8 mov r6, r0
 *   @0x13dfbc mov r0, r4
 *   @0x13dfc0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13dfc4 mov r1, #2
 *   @0x13dfc8 mov r5, r0
 *   @0x13dfcc mov r0, r4
 *   @0x13dfd0 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x13dfd4 mov r1, r6
 *   @0x13dfd8 mov r2, r5
 *   @0x13dfdc mov r3, r0
 *   @0x13dfe0 mov r0, r7
 *   @0x13dfe4 pop {r4, r5, r6, r7, r8, lr}
 *   @0x13dfe8 b 0x1cad28 <_Z19Command_MoveContactP9CInstanceffb>
 *
 * ══ §174/373 F_ActionMovePoint(RValue&, CInstance*, CInstance*, int, RValue*)  0x141634  size 80  20 条（0x141634..0x141684）
 * @func 0x141634 0x141684  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×3
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x141634 push {r4, r5, r6, r7, r8, lr}
 *   @0x141638 mov r7, r1
 *   @0x14163c ldr r4, [sp, #0x18]
 *   @0x141640 mov r1, #0
 *   @0x141644 mov r0, r4
 *   @0x141648 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14164c mov r1, #1
 *   @0x141650 mov r6, r0
 *   @0x141654 mov r0, r4
 *   @0x141658 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14165c mov r1, #2
 *   @0x141660 mov r5, r0
 *   @0x141664 mov r0, r4
 *   @0x141668 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14166c mov r1, r6
 *   @0x141670 mov r2, r5
 *   @0x141674 mov r3, r0
 *   @0x141678 mov r0, r7
 *   @0x14167c pop {r4, r5, r6, r7, r8, lr}
 *   @0x141680 b 0x1415e8 <_Z23YYGML_action_move_pointP9CInstancefff>
 *
 * ══ §175/373 F_ActionCreateObject(RValue&, CInstance*, CInstance*, int, RValue*)  0x14186c  size 80  20 条（0x14186c..0x1418bc）
 * @func 0x14186c 0x1418bc  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14186c push {r4, r5, r6, r7, r8, lr}
 *   @0x141870 mov r7, r1
 *   @0x141874 ldr r4, [sp, #0x18]
 *   @0x141878 mov r1, #0
 *   @0x14187c mov r0, r4
 *   @0x141880 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x141884 mov r1, #1
 *   @0x141888 mov r6, r0
 *   @0x14188c mov r0, r4
 *   @0x141890 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x141894 mov r1, #2
 *   @0x141898 mov r5, r0
 *   @0x14189c mov r0, r4
 *   @0x1418a0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1418a4 mov r1, r6
 *   @0x1418a8 mov r2, r5
 *   @0x1418ac mov r3, r0
 *   @0x1418b0 mov r0, r7
 *   @0x1418b4 pop {r4, r5, r6, r7, r8, lr}
 *   @0x1418b8 b 0x14172c <_Z26YYGML_action_create_objectP9CInstanceiff>
 *
 * ══ §176/373 F_PhysicsFixtureSetCollisionGroup(RValue&, CInstance*, CInstance*, int, RValue*)  0x14bcb0  size 80  20 条（0x14bcb0..0x14bd00）
 * @func 0x14bcb0 0x14bd14  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / CPhysicsFixtureFactory::FindFixture(unsigned int)
 * 字段偏移 top8: 0x20×2 / 0x10×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14bcb0 push {r3, r4, r5, lr}
 *   @0x14bcb4 mov r1, #0
 *   @0x14bcb8 ldr r4, [sp, #0x10]
 *   @0x14bcbc mov r0, r4
 *   @0x14bcc0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14bcc4 bl 0x236404 <_ZN22CPhysicsFixtureFactory11FindFixtureEj>
 *   @0x14bcc8 subs r5, r0, #0
 *   @0x14bccc beq 0x14bce8 <_Z33F_PhysicsFixtureSetCollisionGroupR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x14bcd0 mov r0, r4
 *   @0x14bcd4 mov r1, #1
 *   @0x14bcd8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14bcdc ldr r3, [r5, #0x20]
 *   @0x14bce0 strh r0, [r3, #32]
 *   @0x14bce4 pop {r3, r4, r5, pc}
 *   @0x14bce8 ldr r0, [pc, #0xc]
 *   @0x14bcec mov r1, r5
 *   @0x14bcf0 pop {r3, r4, r5, lr}
 *   @0x14bcf4 add r0, pc, r0
 *   @0x14bcf8 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14bcfc ldrheq r8, [pc], -r4
 *
 * ══ §177/373 F_PhysicsFixtureSetFriction(RValue&, CInstance*, CInstance*, int, RValue*)  0x14bd00  size 80  20 条（0x14bd00..0x14bd50）
 * @func 0x14bd00 0x14bd64  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CPhysicsFixtureFactory::FindFixture(unsigned int) / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x10×1 / 0x20×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14bd00 push {r3, r4, r5, lr}
 *   @0x14bd04 mov r1, #0
 *   @0x14bd08 ldr r4, [sp, #0x10]
 *   @0x14bd0c mov r0, r4
 *   @0x14bd10 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14bd14 bl 0x236404 <_ZN22CPhysicsFixtureFactory11FindFixtureEj>
 *   @0x14bd18 subs r5, r0, #0
 *   @0x14bd1c beq 0x14bd38 <_Z27F_PhysicsFixtureSetFrictionR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x14bd20 mov r0, r4
 *   @0x14bd24 mov r1, #1
 *   @0x14bd28 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14bd2c ldr r3, [r5, #0x20]
 *   @0x14bd30 str r0, [r3, #0x8]
 *   @0x14bd34 pop {r3, r4, r5, pc}
 *   @0x14bd38 ldr r0, [pc, #0xc]
 *   @0x14bd3c mov r1, r5
 *   @0x14bd40 pop {r3, r4, r5, lr}
 *   @0x14bd44 add r0, pc, r0
 *   @0x14bd48 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14bd4c andseq r8, pc, r4, rrx
 *
 * ══ §178/373 F_PhysicsFixtureSetRestitution(RValue&, CInstance*, CInstance*, int, RValue*)  0x14bd50  size 80  20 条（0x14bd50..0x14bda0）
 * @func 0x14bd50 0x14bdb4  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CPhysicsFixtureFactory::FindFixture(unsigned int) / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0xc×2 / 0x10×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14bd50 push {r3, r4, r5, lr}
 *   @0x14bd54 mov r1, #0
 *   @0x14bd58 ldr r4, [sp, #0x10]
 *   @0x14bd5c mov r0, r4
 *   @0x14bd60 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14bd64 bl 0x236404 <_ZN22CPhysicsFixtureFactory11FindFixtureEj>
 *   @0x14bd68 subs r5, r0, #0
 *   @0x14bd6c beq 0x14bd88 <_Z30F_PhysicsFixtureSetRestitutionR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x14bd70 mov r0, r4
 *   @0x14bd74 mov r1, #1
 *   @0x14bd78 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14bd7c ldr r3, [r5, #0x20]
 *   @0x14bd80 str r0, [r3, #0xc]
 *   @0x14bd84 pop {r3, r4, r5, pc}
 *   @0x14bd88 ldr r0, [pc, #0xc]
 *   @0x14bd8c mov r1, r5
 *   @0x14bd90 pop {r3, r4, r5, lr}
 *   @0x14bd94 add r0, pc, r0
 *   @0x14bd98 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14bd9c andseq r8, pc, r4, lsl r0
 *
 * ══ §179/373 F_PhysicsFixtureSetDensity(RValue&, CInstance*, CInstance*, int, RValue*)  0x14bda0  size 80  20 条（0x14bda0..0x14bdf0）
 * @func 0x14bda0 0x14be04  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CPhysicsFixtureFactory::FindFixture(unsigned int) / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x10×2 / 0x20×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14bda0 push {r3, r4, r5, lr}
 *   @0x14bda4 mov r1, #0
 *   @0x14bda8 ldr r4, [sp, #0x10]
 *   @0x14bdac mov r0, r4
 *   @0x14bdb0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14bdb4 bl 0x236404 <_ZN22CPhysicsFixtureFactory11FindFixtureEj>
 *   @0x14bdb8 subs r5, r0, #0
 *   @0x14bdbc beq 0x14bdd8 <_Z26F_PhysicsFixtureSetDensityR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x14bdc0 mov r0, r4
 *   @0x14bdc4 mov r1, #1
 *   @0x14bdc8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14bdcc ldr r3, [r5, #0x20]
 *   @0x14bdd0 str r0, [r3, #0x10]
 *   @0x14bdd4 pop {r3, r4, r5, pc}
 *   @0x14bdd8 ldr r0, [pc, #0xc]
 *   @0x14bddc mov r1, r5
 *   @0x14bde0 pop {r3, r4, r5, lr}
 *   @0x14bde4 add r0, pc, r0
 *   @0x14bde8 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14bdec andseq r7, pc, r4, asr #31
 *
 * ══ §180/373 F_PhysicsFixtureSetSensor(RValue&, CInstance*, CInstance*, int, RValue*)  0x14bdf0  size 80  20 条（0x14bdf0..0x14be40）
 * @func 0x14bdf0 0x14be54  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CPhysicsFixtureFactory::FindFixture(unsigned int) / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x10×1 / 0x20×1 / 0x14×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14bdf0 push {r3, r4, r5, lr}
 *   @0x14bdf4 mov r1, #0
 *   @0x14bdf8 ldr r4, [sp, #0x10]
 *   @0x14bdfc mov r0, r4
 *   @0x14be00 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14be04 bl 0x236404 <_ZN22CPhysicsFixtureFactory11FindFixtureEj>
 *   @0x14be08 subs r5, r0, #0
 *   @0x14be0c beq 0x14be28 <_Z25F_PhysicsFixtureSetSensorR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x14be10 mov r0, r4
 *   @0x14be14 mov r1, #1
 *   @0x14be18 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x14be1c ldr r3, [r5, #0x20]
 *   @0x14be20 strb r0, [r3, #0x14]
 *   @0x14be24 pop {r3, r4, r5, pc}
 *   @0x14be28 ldr r0, [pc, #0xc]
 *   @0x14be2c mov r1, r5
 *   @0x14be30 pop {r3, r4, r5, lr}
 *   @0x14be34 add r0, pc, r0
 *   @0x14be38 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14be3c andseq r7, pc, r4, ror pc
 *
 * ══ §181/373 F_GamepadAddMappingFromString(RValue&, CInstance*, CInstance*, int, RValue*)  0x152990  size 80  20 条（0x152990..0x1529e0）
 * @func 0x152990 0x1529e0  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int) / SGamepadMapping::CreateFromString(char const*)
 * 字段偏移 top8: 0x8×1 / 0x20×1 / 0x1c×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x152990 push {r4, lr}
 *   @0x152994 mov r1, #0
 *   @0x152998 ldr r0, [sp, #0x8]
 *   @0x15299c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1529a0 mov r4, r0
 *   @0x1529a4 bl 0x152790 <_ZN15SGamepadMapping16CreateFromStringEPKc>
 *   @0x1529a8 cmp r0, #0
 *   @0x1529ac popne {r4, pc}
 *   @0x1529b0 ldr r3, [pc, #0x20]
 *   @0x1529b4 mov r2, r4
 *   @0x1529b8 ldr r1, [pc, #0x1c]
 *   @0x1529bc ldr r3, [pc, r3]
 *   @0x1529c0 add r1, pc, r1
 *   @0x1529c4 ldr r0, [r3]
 *   @0x1529c8 ldr r3, [r0]
 *   @0x1529cc ldr r3, [r3, #0xc]
 *   @0x1529d0 blx r3
 *   @0x1529d4 pop {r4, pc}
 *   @0x1529d8 eoreq r10, r9, r4, lsl #31
 *   @0x1529dc mulseq pc, r0, r2
 *
 * ══ §182/373 F_IO_DeleteVirtualKey(RValue&, CInstance*, CInstance*, int, RValue*)  0x156564  size 80  20 条（0x156564..0x1565b4）
 * @func 0x156564 0x1565b4  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_IO_DeleteVirtualKey(RValue&, CInstance*, CInstance*, int, RValue*)+0x3c / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x8×1 / 0x28×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x156564 push {r4, lr}
 *   @0x156568 mov r1, #0
 *   @0x15656c ldr r0, [sp, #0x8]
 *   @0x156570 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x156574 subs r4, r0, #1
 *   @0x156578 bmi 0x156590 <_Z21F_IO_DeleteVirtualKeyR6RValueP9CInstanceS2_iPS_+0x2c>
 *   @0x15657c ldr r3, [pc, #0x28]
 *   @0x156580 ldr r3, [pc, r3]
 *   @0x156584 ldr r3, [r3]
 *   @0x156588 cmp r4, r3
 *   @0x15658c blt 0x1565a0 <_Z21F_IO_DeleteVirtualKeyR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x156590 ldr r0, [pc, #0x18]
 *   @0x156594 mov r1, #0
 *   @0x156598 add r0, pc, r0
 *   @0x15659c bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1565a0 mov r0, r4
 *   @0x1565a4 pop {r4, lr}
 *   @0x1565a8 b 0x18c608 <_Z14FreeVirtualKeyi>
 *   @0x1565ac .word 0x002995d0
 *   @0x1565b0 ldrheq pc, [lr], -r0
 *
 * ══ §183/373 F_YoYo_GetGUIWidth(RValue&, CInstance*, CInstance*, int, RValue*)  0x157908  size 80  20 条（0x157908..0x157958）
 * @func 0x157908 0x157958  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GetBrowserWidthM()
 * 字段偏移 top8: 0x44×1 / 0xc×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x157908 ldr r3, [pc, #0x44]
 *   @0x15790c push {r4, lr}
 *   @0x157910 ldr r3, [pc, r3]
 *   @0x157914 mov r4, r0
 *   @0x157918 ldr r0, [r3]
 *   @0x15791c vmov s15, r0
 *   @0x157920 vcvt.f64.s32 d7, s15
 *   @0x157924 vcmpe.f64 d7, #0
 *   @0x157928 vmov r0, r1, d7
 *   @0x15792c vmrs APSR_nzcv, fpscr
 *   @0x157930 bmi 0x15794c <_Z18F_YoYo_GetGUIWidthR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x157934 mov r3, #0
 *   @0x157938 mov r2, r0
 *   @0x15793c str r3, [r4, #0xc]
 *   @0x157940 mov r3, r1
 *   @0x157944 stm r4, {r2, r3}
 *   @0x157948 pop {r4, pc}
 *   @0x15794c bl 0x15e60c <_Z16GetBrowserWidthMv>
 *   @0x157950 b 0x157934 <_Z18F_YoYo_GetGUIWidthR6RValueP9CInstanceS2_iPS_+0x2c>
 *   @0x157954 eoreq r8, r9, r8, asr r2
 *
 * ══ §184/373 F_YoYo_GetGUIHeight(RValue&, CInstance*, CInstance*, int, RValue*)  0x15797c  size 80  20 条（0x15797c..0x1579cc）
 * @func 0x15797c 0x1579cc  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GetBrowserHeightM()
 * 字段偏移 top8: 0x44×1 / 0xc×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15797c ldr r3, [pc, #0x44]
 *   @0x157980 push {r4, lr}
 *   @0x157984 ldr r3, [pc, r3]
 *   @0x157988 mov r4, r0
 *   @0x15798c ldr r0, [r3]
 *   @0x157990 vmov s15, r0
 *   @0x157994 vcvt.f64.s32 d7, s15
 *   @0x157998 vcmpe.f64 d7, #0
 *   @0x15799c vmov r0, r1, d7
 *   @0x1579a0 vmrs APSR_nzcv, fpscr
 *   @0x1579a4 bmi 0x1579c0 <_Z19F_YoYo_GetGUIHeightR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x1579a8 mov r3, #0
 *   @0x1579ac mov r2, r0
 *   @0x1579b0 str r3, [r4, #0xc]
 *   @0x1579b4 mov r3, r1
 *   @0x1579b8 stm r4, {r2, r3}
 *   @0x1579bc pop {r4, pc}
 *   @0x1579c0 bl 0x15e62c <_Z17GetBrowserHeightMv>
 *   @0x1579c4 b 0x1579a8 <_Z19F_YoYo_GetGUIHeightR6RValueP9CInstanceS2_iPS_+0x2c>
 *   @0x1579c8 .word 0x002981f0
 *
 * ══ §185/373 ConvertRawToGUI(float, float, float&, float&)  0x159f4c  size 80  20 条（0x159f4c..0x159f9c）
 * @func 0x159f4c 0x159f9c  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x40×1
 * VFP 指令 16 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x159f4c vmov s15, r1
 *   @0x159f50 ldr r12, [pc, #0x40]
 *   @0x159f54 vmov s13, r0
 *   @0x159f58 ldr r12, [pc, r12]
 *   @0x159f5c vldr s14, [r12, #16]
 *   @0x159f60 vmul.f32 s14, s15, s14
 *   @0x159f64 vldr s11, [r12]
 *   @0x159f68 vldr s12, [r12, #48]
 *   @0x159f6c vmla.f32 s14, s13, s11
 *   @0x159f70 vadd.f32 s14, s14, s12
 *   @0x159f74 vstr s14, [r2]
 *   @0x159f78 vldr s14, [r12, #20]
 *   @0x159f7c vmul.f32 s15, s15, s14
 *   @0x159f80 vldr s12, [r12, #4]
 *   @0x159f84 vldr s14, [r12, #52]
 *   @0x159f88 vmla.f32 s15, s13, s12
 *   @0x159f8c vadd.f32 s15, s15, s14
 *   @0x159f90 vstr s15, [r3]
 *   @0x159f94 bx lr
 *   @0x159f98 eoreq r5, r9, r8, asr #24
 *
 * ══ §186/373 AdsSetup(char*)  0x15e2f0  size 80  20 条（0x15e2f0..0x15e340）
 * @func 0x15e2f0 0x15e354  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv×2
 * 字段偏移 top8: 0x29c×1 / 0x1c×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15e2f0 push {r4, lr}
 *   @0x15e2f4 mov r4, r0
 *   @0x15e2f8 bl 0x290274 <getJNIEnv>
 *   @0x15e2fc mov r1, r4
 *   @0x15e300 ldr r3, [r0]
 *   @0x15e304 ldr r3, [r3, #0x29c]
 *   @0x15e308 blx r3
 *   @0x15e30c mov r4, r0
 *   @0x15e310 bl 0x290274 <getJNIEnv>
 *   @0x15e314 ldr r1, [pc, #0x1c]
 *   @0x15e318 mov r3, r4
 *   @0x15e31c ldr r2, [pc, #0x18]
 *   @0x15e320 ldr r1, [pc, r1]
 *   @0x15e324 ldr r2, [pc, r2]
 *   @0x15e328 ldr r1, [r1]
 *   @0x15e32c ldr r2, [r2]
 *   @0x15e330 pop {r4, lr}
 *   @0x15e334 b 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x15e338 eoreq pc, r8, r4, lsl #13
 *   @0x15e33c eoreq r1, r9, r0, asr r11
 *
 * ══ §187/373 MoveAd(int, int, int)  0x15e340  size 80  20 条（0x15e340..0x15e390）
 * @func 0x15e340 0x15e390  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv / _JNIEnv::CallStaticVoidMethod(_jclass*, _jmethodID*, ...)
 * 字段偏移 top8: 0x28×1 / 0x24×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15e340 push {r4, r5, r6, lr}
 *   @0x15e344 sub sp, sp, #8
 *   @0x15e348 mov r5, r1
 *   @0x15e34c mov r4, r2
 *   @0x15e350 mov r6, r0
 *   @0x15e354 bl 0x290274 <getJNIEnv>
 *   @0x15e358 ldr lr, [pc, #0x28]
 *   @0x15e35c mov r3, r6
 *   @0x15e360 ldr r12, [pc, #0x24]
 *   @0x15e364 ldr lr, [pc, lr]
 *   @0x15e368 ldr r12, [pc, r12]
 *   @0x15e36c ldr r1, [lr]
 *   @0x15e370 ldr r2, [r12]
 *   @0x15e374 str r5, [sp]
 *   @0x15e378 str r4, [sp, #0x4]
 *   @0x15e37c bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x15e380 add sp, sp, #8
 *   @0x15e384 pop {r4, r5, r6, pc}
 *   @0x15e388 eoreq pc, r8, r0, asr #12
 *   @0x15e38c eoreq r1, r9, r0, lsl r11
 *
 * ══ §188/373 AdsEvent(char*)  0x15e428  size 80  20 条（0x15e428..0x15e478）
 * @func 0x15e428 0x15e48c  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv×2
 * 字段偏移 top8: 0x29c×1 / 0x1c×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15e428 push {r4, lr}
 *   @0x15e42c mov r4, r0
 *   @0x15e430 bl 0x290274 <getJNIEnv>
 *   @0x15e434 mov r1, r4
 *   @0x15e438 ldr r3, [r0]
 *   @0x15e43c ldr r3, [r3, #0x29c]
 *   @0x15e440 blx r3
 *   @0x15e444 mov r4, r0
 *   @0x15e448 bl 0x290274 <getJNIEnv>
 *   @0x15e44c ldr r1, [pc, #0x1c]
 *   @0x15e450 mov r3, r4
 *   @0x15e454 ldr r2, [pc, #0x18]
 *   @0x15e458 ldr r1, [pc, r1]
 *   @0x15e45c ldr r2, [pc, r2]
 *   @0x15e460 ldr r1, [r1]
 *   @0x15e464 ldr r2, [r2]
 *   @0x15e468 pop {r4, lr}
 *   @0x15e46c b 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x15e470 eoreq pc, r8, r12, asr #10
 *   @0x15e474 eoreq r1, r9, r8, lsr #20
 *
 * ══ §189/373 AdsPreload(char*)  0x15e478  size 80  20 条（0x15e478..0x15e4c8）
 * @func 0x15e478 0x15e4c8  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv×2
 * 字段偏移 top8: 0x29c×1 / 0x1c×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15e478 push {r4, lr}
 *   @0x15e47c mov r4, r0
 *   @0x15e480 bl 0x290274 <getJNIEnv>
 *   @0x15e484 mov r1, r4
 *   @0x15e488 ldr r3, [r0]
 *   @0x15e48c ldr r3, [r3, #0x29c]
 *   @0x15e490 blx r3
 *   @0x15e494 mov r4, r0
 *   @0x15e498 bl 0x290274 <getJNIEnv>
 *   @0x15e49c ldr r1, [pc, #0x1c]
 *   @0x15e4a0 mov r3, r4
 *   @0x15e4a4 ldr r2, [pc, #0x18]
 *   @0x15e4a8 ldr r1, [pc, r1]
 *   @0x15e4ac ldr r2, [pc, r2]
 *   @0x15e4b0 ldr r1, [r1]
 *   @0x15e4b4 ldr r2, [r2]
 *   @0x15e4b8 pop {r4, lr}
 *   @0x15e4bc b 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x15e4c0 .word 0x0028f4fc
 *   @0x15e4c4 .word 0x002919dc
 *
 * ══ §190/373 YYCheckPermission(char const*)  0x15f2dc  size 80  20 条（0x15f2dc..0x15f32c）
 * @func 0x15f2dc 0x15f340  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv×2
 * 字段偏移 top8: 0x29c×1 / 0x1c×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15f2dc push {r4, lr}
 *   @0x15f2e0 mov r4, r0
 *   @0x15f2e4 bl 0x290274 <getJNIEnv>
 *   @0x15f2e8 mov r1, r4
 *   @0x15f2ec ldr r3, [r0]
 *   @0x15f2f0 ldr r3, [r3, #0x29c]
 *   @0x15f2f4 blx r3
 *   @0x15f2f8 mov r4, r0
 *   @0x15f2fc bl 0x290274 <getJNIEnv>
 *   @0x15f300 ldr r1, [pc, #0x1c]
 *   @0x15f304 mov r3, r4
 *   @0x15f308 ldr r2, [pc, #0x18]
 *   @0x15f30c ldr r1, [pc, r1]
 *   @0x15f310 ldr r2, [pc, r2]
 *   @0x15f314 ldr r1, [r1]
 *   @0x15f318 ldr r2, [r2]
 *   @0x15f31c pop {r4, lr}
 *   @0x15f320 b 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz>
 *   @0x15f324 mlaeq r8, r8, r6, lr
 *   @0x15f328 .word 0x00290bd8
 *
 * ══ §191/373 YYRequestPermission(char const*)  0x15f32c  size 80  20 条（0x15f32c..0x15f37c）
 * @func 0x15f32c 0x15f37c  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv×2
 * 字段偏移 top8: 0x29c×1 / 0x1c×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15f32c push {r4, lr}
 *   @0x15f330 mov r4, r0
 *   @0x15f334 bl 0x290274 <getJNIEnv>
 *   @0x15f338 mov r1, r4
 *   @0x15f33c ldr r3, [r0]
 *   @0x15f340 ldr r3, [r3, #0x29c]
 *   @0x15f344 blx r3
 *   @0x15f348 mov r4, r0
 *   @0x15f34c bl 0x290274 <getJNIEnv>
 *   @0x15f350 ldr r1, [pc, #0x1c]
 *   @0x15f354 mov r3, r4
 *   @0x15f358 ldr r2, [pc, #0x18]
 *   @0x15f35c ldr r1, [pc, r1]
 *   @0x15f360 ldr r2, [pc, r2]
 *   @0x15f364 ldr r1, [r1]
 *   @0x15f368 ldr r2, [r2]
 *   @0x15f36c pop {r4, lr}
 *   @0x15f370 b 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x15f374 eoreq lr, r8, r8, asr #12
 *   @0x15f378 eoreq r0, r9, r12, lsl #23
 *
 * ══ §192/373 YYAnalyticsEvent(char const*)  0x15f380  size 80  20 条（0x15f380..0x15f3d0）
 * @func 0x15f380 0x15f3d0  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv×2
 * 字段偏移 top8: 0x29c×1 / 0x1c×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15f380 push {r4, lr}
 *   @0x15f384 mov r4, r0
 *   @0x15f388 bl 0x290274 <getJNIEnv>
 *   @0x15f38c mov r1, r4
 *   @0x15f390 ldr r3, [r0]
 *   @0x15f394 ldr r3, [r3, #0x29c]
 *   @0x15f398 blx r3
 *   @0x15f39c mov r4, r0
 *   @0x15f3a0 bl 0x290274 <getJNIEnv>
 *   @0x15f3a4 ldr r1, [pc, #0x1c]
 *   @0x15f3a8 mov r3, r4
 *   @0x15f3ac ldr r2, [pc, #0x18]
 *   @0x15f3b0 ldr r1, [pc, r1]
 *   @0x15f3b4 ldr r2, [pc, r2]
 *   @0x15f3b8 ldr r1, [r1]
 *   @0x15f3bc ldr r2, [r2]
 *   @0x15f3c0 pop {r4, lr}
 *   @0x15f3c4 b 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x15f3c8 .word 0x0028e5f4
 *   @0x15f3cc eoreq r0, r9, r12, lsr r11
 *
 * ══ §193/373 Achievement_Get_Info(char*)  0x1610e8  size 80  20 条（0x1610e8..0x161138）
 * @func 0x1610e8 0x161138  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv×2
 * 字段偏移 top8: 0x29c×1 / 0x1c×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1610e8 push {r4, lr}
 *   @0x1610ec mov r4, r0
 *   @0x1610f0 bl 0x290274 <getJNIEnv>
 *   @0x1610f4 mov r1, r4
 *   @0x1610f8 ldr r3, [r0]
 *   @0x1610fc ldr r3, [r3, #0x29c]
 *   @0x161100 blx r3
 *   @0x161104 mov r4, r0
 *   @0x161108 bl 0x290274 <getJNIEnv>
 *   @0x16110c ldr r1, [pc, #0x1c]
 *   @0x161110 mov r3, r4
 *   @0x161114 ldr r2, [pc, #0x18]
 *   @0x161118 ldr r1, [pc, r1]
 *   @0x16111c ldr r2, [pc, r2]
 *   @0x161120 ldr r1, [r1]
 *   @0x161124 ldr r2, [r2]
 *   @0x161128 pop {r4, lr}
 *   @0x16112c b 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x161130 eoreq r12, r8, r12, lsl #17
 *   @0x161134 eoreq lr, r8, r12, lsl lr
 *
 * ══ §194/373 Achievement_Load_Pic(char*)  0x161168  size 80  20 条（0x161168..0x1611b8）
 * @func 0x161168 0x1611cc  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv×2
 * 字段偏移 top8: 0x29c×1 / 0x1c×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161168 push {r4, lr}
 *   @0x16116c mov r4, r0
 *   @0x161170 bl 0x290274 <getJNIEnv>
 *   @0x161174 mov r1, r4
 *   @0x161178 ldr r3, [r0]
 *   @0x16117c ldr r3, [r3, #0x29c]
 *   @0x161180 blx r3
 *   @0x161184 mov r4, r0
 *   @0x161188 bl 0x290274 <getJNIEnv>
 *   @0x16118c ldr r1, [pc, #0x1c]
 *   @0x161190 mov r3, r4
 *   @0x161194 ldr r2, [pc, #0x18]
 *   @0x161198 ldr r1, [pc, r1]
 *   @0x16119c ldr r2, [pc, r2]
 *   @0x1611a0 ldr r1, [r1]
 *   @0x1611a4 ldr r2, [r2]
 *   @0x1611a8 pop {r4, lr}
 *   @0x1611ac b 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x1611b0 eoreq r12, r8, r12, lsl #16
 *   @0x1611b4 eoreq lr, r8, r4, lsr #27
 *
 * ══ §195/373 Achievement_Event(char*)  0x1611b8  size 80  20 条（0x1611b8..0x161208）
 * @func 0x1611b8 0x161208  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv×2
 * 字段偏移 top8: 0x29c×1 / 0x1c×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1611b8 push {r4, lr}
 *   @0x1611bc mov r4, r0
 *   @0x1611c0 bl 0x290274 <getJNIEnv>
 *   @0x1611c4 mov r1, r4
 *   @0x1611c8 ldr r3, [r0]
 *   @0x1611cc ldr r3, [r3, #0x29c]
 *   @0x1611d0 blx r3
 *   @0x1611d4 mov r4, r0
 *   @0x1611d8 bl 0x290274 <getJNIEnv>
 *   @0x1611dc ldr r1, [pc, #0x1c]
 *   @0x1611e0 mov r3, r4
 *   @0x1611e4 ldr r2, [pc, #0x18]
 *   @0x1611e8 ldr r1, [pc, r1]
 *   @0x1611ec ldr r2, [pc, r2]
 *   @0x1611f0 ldr r1, [r1]
 *   @0x1611f4 ldr r2, [r2]
 *   @0x1611f8 pop {r4, lr}
 *   @0x1611fc b 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x161200 .word 0x0028c7bc
 *   @0x161204 eoreq lr, r8, r8, asr sp
 *
 * ══ §196/373 GR_3D_Transform_Add_Rotation_X(float)  0x1639ac  size 80  20 条（0x1639ac..0x1639fc）
 * @func 0x1639ac 0x163a10  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: yyMatrix::SetXRotation(yyMatrix*, float) / Graphics::GetMatrix(eMatrix, float*) / yyMatrix::Multiply(yyMatrix*, yyMatrix*, yyMatrix*) / Graphics::SetMatrix(eMatrix, float*) / DirtyRoomExtents()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1639ac push {r4, r5, lr}
 *   @0x1639b0 sub sp, sp, #196
 *   @0x1639b4 add r4, sp, #64
 *   @0x1639b8 mov r1, r0
 *   @0x1639bc mov r0, r4
 *   @0x1639c0 bl 0x27afe4 <_ZN8yyMatrix12SetXRotationEPS_f>
 *   @0x1639c4 mov r1, sp
 *   @0x1639c8 mov r0, #2
 *   @0x1639cc bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf>
 *   @0x1639d0 mov r2, r4
 *   @0x1639d4 add r4, sp, #128
 *   @0x1639d8 mov r1, sp
 *   @0x1639dc mov r0, r4
 *   @0x1639e0 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_>
 *   @0x1639e4 mov r1, r4
 *   @0x1639e8 mov r0, #2
 *   @0x1639ec bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf>
 *   @0x1639f0 bl 0x168d7c <_Z16DirtyRoomExtentsv>
 *   @0x1639f4 add sp, sp, #196
 *   @0x1639f8 pop {r4, r5, pc}
 *
 * ══ §197/373 GR_3D_Transform_Add_Rotation_Y(float)  0x1639fc  size 80  20 条（0x1639fc..0x163a4c）
 * @func 0x1639fc 0x163a60  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: yyMatrix::SetYRotation(yyMatrix*, float) / Graphics::GetMatrix(eMatrix, float*) / yyMatrix::Multiply(yyMatrix*, yyMatrix*, yyMatrix*) / Graphics::SetMatrix(eMatrix, float*) / DirtyRoomExtents()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1639fc push {r4, r5, lr}
 *   @0x163a00 sub sp, sp, #196
 *   @0x163a04 add r4, sp, #64
 *   @0x163a08 mov r1, r0
 *   @0x163a0c mov r0, r4
 *   @0x163a10 bl 0x27af60 <_ZN8yyMatrix12SetYRotationEPS_f>
 *   @0x163a14 mov r1, sp
 *   @0x163a18 mov r0, #2
 *   @0x163a1c bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf>
 *   @0x163a20 mov r2, r4
 *   @0x163a24 add r4, sp, #128
 *   @0x163a28 mov r1, sp
 *   @0x163a2c mov r0, r4
 *   @0x163a30 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_>
 *   @0x163a34 mov r1, r4
 *   @0x163a38 mov r0, #2
 *   @0x163a3c bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf>
 *   @0x163a40 bl 0x168d7c <_Z16DirtyRoomExtentsv>
 *   @0x163a44 add sp, sp, #196
 *   @0x163a48 pop {r4, r5, pc}
 *
 * ══ §198/373 GR_3D_Transform_Add_Rotation_Z(float)  0x163a4c  size 80  20 条（0x163a4c..0x163a9c）
 * @func 0x163a4c 0x163a9c  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: yyMatrix::SetZRotation(yyMatrix*, float) / Graphics::GetMatrix(eMatrix, float*) / yyMatrix::Multiply(yyMatrix*, yyMatrix*, yyMatrix*) / Graphics::SetMatrix(eMatrix, float*) / DirtyRoomExtents()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x163a4c push {r4, r5, lr}
 *   @0x163a50 sub sp, sp, #196
 *   @0x163a54 add r4, sp, #64
 *   @0x163a58 mov r1, r0
 *   @0x163a5c mov r0, r4
 *   @0x163a60 bl 0x27aedc <_ZN8yyMatrix12SetZRotationEPS_f>
 *   @0x163a64 mov r1, sp
 *   @0x163a68 mov r0, #2
 *   @0x163a6c bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf>
 *   @0x163a70 mov r2, r4
 *   @0x163a74 add r4, sp, #128
 *   @0x163a78 mov r1, sp
 *   @0x163a7c mov r0, r4
 *   @0x163a80 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_>
 *   @0x163a84 mov r1, r4
 *   @0x163a88 mov r0, #2
 *   @0x163a8c bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf>
 *   @0x163a90 bl 0x168d7c <_Z16DirtyRoomExtentsv>
 *   @0x163a94 add sp, sp, #196
 *   @0x163a98 pop {r4, r5, pc}
 *
 * ══ §199/373 GR_3DM_Draw(int, float, float, float, int)  0x165370  size 80  20 条（0x165370..0x1653c0）
 * @func 0x165370 0x1653c0  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_3DM_Draw(int, float, float, float, int)+0x40
 * 字段偏移 top8: 0x4×3 / 0x-4×1 / 0x34×1 / 0x24×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x165370 cmp r0, #0
 *   @0x165374 str r4, [sp, #-0x4]!
 *   @0x165378 blt 0x1653b0 <_Z11GR_3DM_Drawifffi+0x40>
 *   @0x16537c ldr r12, [pc, #0x34]
 *   @0x165380 ldr r12, [pc, r12]
 *   @0x165384 ldr r12, [r12]
 *   @0x165388 cmp r0, r12
 *   @0x16538c bge 0x1653b0 <_Z11GR_3DM_Drawifffi+0x40>
 *   @0x165390 ldr r12, [pc, #0x24]
 *   @0x165394 ldr r12, [pc, r12]
 *   @0x165398 ldr r12, [r12, #0x4]
 *   @0x16539c ldr r0, [r12, r0, lsl #2]
 *   @0x1653a0 cmp r0, #0
 *   @0x1653a4 beq 0x1653b0 <_Z11GR_3DM_Drawifffi+0x40>
 *   @0x1653a8 ldr r4, [sp], #4
 *   @0x1653ac b 0x1649ac <_ZN9C3D_Model4DrawEfffi>
 *   @0x1653b0 ldr r4, [sp], #4
 *   @0x1653b4 bx lr
 *   @0x1653b8 eoreq r10, r8, r0, ror sp
 *   @0x1653bc eoreq r10, r8, r0, ror #26
 *
 * ══ §200/373 F_ViewSetVisible(RValue&, CInstance*, CInstance*, int, RValue*)  0x16c42c  size 80  20 条（0x16c42c..0x16c47c）
 * @func 0x16c42c 0x16c490  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int) / YYGetInt32(RValue const*, int) / SV_ViewVisible(CInstance*, int, RValue*)
 * 字段偏移 top8: 0x28×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16c42c push {r4, r5, r6, r7, lr}
 *   @0x16c430 sub sp, sp, #20
 *   @0x16c434 mov r7, r1
 *   @0x16c438 mov r1, #1
 *   @0x16c43c ldr r5, [sp, #0x28]
 *   @0x16c440 mov r6, #0
 *   @0x16c444 str r6, [sp, #0xc]
 *   @0x16c448 add r4, sp, #16
 *   @0x16c44c mov r0, r5
 *   @0x16c450 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x16c454 strd r0, r1, [r4, #-16]!
 *   @0x16c458 mov r1, r6
 *   @0x16c45c mov r0, r5
 *   @0x16c460 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x16c464 mov r2, sp
 *   @0x16c468 mov r1, r0
 *   @0x16c46c mov r0, r7
 *   @0x16c470 bl 0x1fc1f4 <_Z14SV_ViewVisibleP9CInstanceiP6RValue>
 *   @0x16c474 add sp, sp, #20
 *   @0x16c478 pop {r4, r5, r6, r7, pc}
 *
 * ══ §201/373 F_ViewSetXport(RValue&, CInstance*, CInstance*, int, RValue*)  0x16c47c  size 80  20 条（0x16c47c..0x16c4cc）
 * @func 0x16c47c 0x16c4e0  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int) / YYGetInt32(RValue const*, int) / SV_ViewXport(CInstance*, int, RValue*)
 * 字段偏移 top8: 0x28×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16c47c push {r4, r5, r6, r7, lr}
 *   @0x16c480 sub sp, sp, #20
 *   @0x16c484 mov r7, r1
 *   @0x16c488 mov r1, #1
 *   @0x16c48c ldr r5, [sp, #0x28]
 *   @0x16c490 mov r6, #0
 *   @0x16c494 str r6, [sp, #0xc]
 *   @0x16c498 add r4, sp, #16
 *   @0x16c49c mov r0, r5
 *   @0x16c4a0 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x16c4a4 strd r0, r1, [r4, #-16]!
 *   @0x16c4a8 mov r1, r6
 *   @0x16c4ac mov r0, r5
 *   @0x16c4b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x16c4b4 mov r2, sp
 *   @0x16c4b8 mov r1, r0
 *   @0x16c4bc mov r0, r7
 *   @0x16c4c0 bl 0x1fc3d8 <_Z12SV_ViewXportP9CInstanceiP6RValue>
 *   @0x16c4c4 add sp, sp, #20
 *   @0x16c4c8 pop {r4, r5, r6, r7, pc}
 *
 * ══ §202/373 F_ViewSetYport(RValue&, CInstance*, CInstance*, int, RValue*)  0x16c4cc  size 80  20 条（0x16c4cc..0x16c51c）
 * @func 0x16c4cc 0x16c530  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int) / YYGetInt32(RValue const*, int) / SV_ViewYport(CInstance*, int, RValue*)
 * 字段偏移 top8: 0x28×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16c4cc push {r4, r5, r6, r7, lr}
 *   @0x16c4d0 sub sp, sp, #20
 *   @0x16c4d4 mov r7, r1
 *   @0x16c4d8 mov r1, #1
 *   @0x16c4dc ldr r5, [sp, #0x28]
 *   @0x16c4e0 mov r6, #0
 *   @0x16c4e4 str r6, [sp, #0xc]
 *   @0x16c4e8 add r4, sp, #16
 *   @0x16c4ec mov r0, r5
 *   @0x16c4f0 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x16c4f4 strd r0, r1, [r4, #-16]!
 *   @0x16c4f8 mov r1, r6
 *   @0x16c4fc mov r0, r5
 *   @0x16c500 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x16c504 mov r2, sp
 *   @0x16c508 mov r1, r0
 *   @0x16c50c mov r0, r7
 *   @0x16c510 bl 0x1fc440 <_Z12SV_ViewYportP9CInstanceiP6RValue>
 *   @0x16c514 add sp, sp, #20
 *   @0x16c518 pop {r4, r5, r6, r7, pc}
 *
 * ══ §203/373 F_ViewSetWport(RValue&, CInstance*, CInstance*, int, RValue*)  0x16c51c  size 80  20 条（0x16c51c..0x16c56c）
 * @func 0x16c51c 0x16c580  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int) / YYGetInt32(RValue const*, int) / SV_ViewWport(CInstance*, int, RValue*)
 * 字段偏移 top8: 0x28×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16c51c push {r4, r5, r6, r7, lr}
 *   @0x16c520 sub sp, sp, #20
 *   @0x16c524 mov r7, r1
 *   @0x16c528 mov r1, #1
 *   @0x16c52c ldr r5, [sp, #0x28]
 *   @0x16c530 mov r6, #0
 *   @0x16c534 str r6, [sp, #0xc]
 *   @0x16c538 add r4, sp, #16
 *   @0x16c53c mov r0, r5
 *   @0x16c540 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x16c544 strd r0, r1, [r4, #-16]!
 *   @0x16c548 mov r1, r6
 *   @0x16c54c mov r0, r5
 *   @0x16c550 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x16c554 mov r2, sp
 *   @0x16c558 mov r1, r0
 *   @0x16c55c mov r0, r7
 *   @0x16c560 bl 0x1fc4a8 <_Z12SV_ViewWportP9CInstanceiP6RValue>
 *   @0x16c564 add sp, sp, #20
 *   @0x16c568 pop {r4, r5, r6, r7, pc}
 *
 * ══ §204/373 F_ViewSetHport(RValue&, CInstance*, CInstance*, int, RValue*)  0x16c56c  size 80  20 条（0x16c56c..0x16c5bc）
 * @func 0x16c56c 0x16c5d0  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int) / YYGetInt32(RValue const*, int) / SV_ViewHport(CInstance*, int, RValue*)
 * 字段偏移 top8: 0x28×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16c56c push {r4, r5, r6, r7, lr}
 *   @0x16c570 sub sp, sp, #20
 *   @0x16c574 mov r7, r1
 *   @0x16c578 mov r1, #1
 *   @0x16c57c ldr r5, [sp, #0x28]
 *   @0x16c580 mov r6, #0
 *   @0x16c584 str r6, [sp, #0xc]
 *   @0x16c588 add r4, sp, #16
 *   @0x16c58c mov r0, r5
 *   @0x16c590 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x16c594 strd r0, r1, [r4, #-16]!
 *   @0x16c598 mov r1, r6
 *   @0x16c59c mov r0, r5
 *   @0x16c5a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x16c5a4 mov r2, sp
 *   @0x16c5a8 mov r1, r0
 *   @0x16c5ac mov r0, r7
 *   @0x16c5b0 bl 0x1fc510 <_Z12SV_ViewHportP9CInstanceiP6RValue>
 *   @0x16c5b4 add sp, sp, #20
 *   @0x16c5b8 pop {r4, r5, r6, r7, pc}
 *
 * ══ §205/373 F_ViewSetSurfaceId(RValue&, CInstance*, CInstance*, int, RValue*)  0x16c5bc  size 80  20 条（0x16c5bc..0x16c60c）
 * @func 0x16c5bc 0x16c620  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int) / YYGetInt32(RValue const*, int) / SV_ViewSurfaceID(CInstance*, int, RValue*)
 * 字段偏移 top8: 0x28×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16c5bc push {r4, r5, r6, r7, lr}
 *   @0x16c5c0 sub sp, sp, #20
 *   @0x16c5c4 mov r7, r1
 *   @0x16c5c8 mov r1, #1
 *   @0x16c5cc ldr r5, [sp, #0x28]
 *   @0x16c5d0 mov r6, #0
 *   @0x16c5d4 str r6, [sp, #0xc]
 *   @0x16c5d8 add r4, sp, #16
 *   @0x16c5dc mov r0, r5
 *   @0x16c5e0 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x16c5e4 strd r0, r1, [r4, #-16]!
 *   @0x16c5e8 mov r1, r6
 *   @0x16c5ec mov r0, r5
 *   @0x16c5f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x16c5f4 mov r2, sp
 *   @0x16c5f8 mov r1, r0
 *   @0x16c5fc mov r0, r7
 *   @0x16c600 bl 0x1fc7d8 <_Z16SV_ViewSurfaceIDP9CInstanceiP6RValue>
 *   @0x16c604 add sp, sp, #20
 *   @0x16c608 pop {r4, r5, r6, r7, pc}
 *
 * ══ §206/373 F_ViewSetCamera(RValue&, CInstance*, CInstance*, int, RValue*)  0x16c60c  size 80  20 条（0x16c60c..0x16c65c）
 * @func 0x16c60c 0x16c65c  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int) / YYGetInt32(RValue const*, int) / SV_ViewCamera(CInstance*, int, RValue*)
 * 字段偏移 top8: 0x28×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16c60c push {r4, r5, r6, r7, lr}
 *   @0x16c610 sub sp, sp, #20
 *   @0x16c614 mov r7, r1
 *   @0x16c618 mov r1, #1
 *   @0x16c61c ldr r5, [sp, #0x28]
 *   @0x16c620 mov r6, #0
 *   @0x16c624 str r6, [sp, #0xc]
 *   @0x16c628 add r4, sp, #16
 *   @0x16c62c mov r0, r5
 *   @0x16c630 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x16c634 strd r0, r1, [r4, #-16]!
 *   @0x16c638 mov r1, r6
 *   @0x16c63c mov r0, r5
 *   @0x16c640 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x16c644 mov r2, sp
 *   @0x16c648 mov r1, r0
 *   @0x16c64c mov r0, r7
 *   @0x16c650 bl 0x1fc840 <_Z13SV_ViewCameraP9CInstanceiP6RValue>
 *   @0x16c654 add sp, sp, #20
 *   @0x16c658 pop {r4, r5, r6, r7, pc}
 *
 * ══ §207/373 CCameraManager::CCameraManager()  0x16dce4  size 80  20 条（0x16dce4..0x16dd34）
 * @func 0x16dce4 0x16dd34  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x44×1 / 0x4×1 / 0x8×1 / 0x14×1 / 0x18×1 / 0x10×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16dce4 ldr r1, [pc, #0x44]
 *   @0x16dce8 mov r2, #1072
 *   @0x16dcec push {r3, r4, r5, lr}
 *   @0x16dcf0 mov r4, r0
 *   @0x16dcf4 mov r5, #0
 *   @0x16dcf8 mov r3, #1
 *   @0x16dcfc str r5, [r4]
 *   @0x16dd00 add r1, pc, r1
 *   @0x16dd04 str r5, [r4, #0x4]
 *   @0x16dd08 mov r0, #4
 *   @0x16dd0c str r5, [r4, #0x8]
 *   @0x16dd10 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x16dd14 mov r3, #1
 *   @0x16dd18 str r5, [r4, #0x14]
 *   @0x16dd1c str r5, [r4, #0x18]
 *   @0x16dd20 str r3, [r4, #0x10]
 *   @0x16dd24 str r0, [r4, #0xc]
 *   @0x16dd28 mov r0, r4
 *   @0x16dd2c pop {r3, r4, r5, pc}
 *   @0x16dd30 andseq r12, sp, r8, asr r11
 *
 * ══ §208/373 ResetCurrentTextures()  0x182d50  size 80  20 条（0x182d50..0x182da0）
 * @func 0x182d50 0x182da0  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics::SetTexture(int, void*)
 * 字段偏移 top8: 0x38×1 / 0x34×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x182d50 push {r4, r5, r6, lr}
 *   @0x182d54 mov r4, #0
 *   @0x182d58 ldr r5, [pc, #0x38]
 *   @0x182d5c mov r3, #1
 *   @0x182d60 ldr r6, [pc, #0x34]
 *   @0x182d64 ldr r5, [pc, r5]
 *   @0x182d68 ldr r6, [pc, r6]
 *   @0x182d6c sub r5, r5, #4
 *   @0x182d70 strb r3, [r6]
 *   @0x182d74 mov r0, r4
 *   @0x182d78 ldr r1, [r5, #0x4]!
 *   @0x182d7c add r4, r4, #1
 *   @0x182d80 bl 0x182a28 <_ZN8Graphics10SetTextureEiPv>
 *   @0x182d84 cmp r4, #8
 *   @0x182d88 bne 0x182d74 <_Z20ResetCurrentTexturesv+0x24>
 *   @0x182d8c mov r3, #0
 *   @0x182d90 strb r3, [r6]
 *   @0x182d94 pop {r4, r5, r6, pc}
 *   @0x182d98 .word 0x0026d7d4
 *   @0x182d9c eoreq sp, r6, r12, ror #15
 *
 * ══ §209/373 VertexBuffer::IsValid()  0x183958  size 80  20 条（0x183958..0x1839a8）
 * @func 0x183958 0x1839a8  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x40×1 / 0xc×1 / 0x24×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x183958 ldr r3, [pc, #0x40]
 *   @0x18395c ldr r3, [pc, r3]
 *   @0x183960 ldrb r3, [r3]
 *   @0x183964 cmp r3, #0
 *   @0x183968 beq 0x183998 <_ZN12VertexBuffer7IsValidEv+0x40>
 *   @0x18396c ldr r0, [r0, #0xc]
 *   @0x183970 cmp r0, #0
 *   @0x183974 bxeq lr
 *   @0x183978 ldr r2, [pc, #0x24]
 *   @0x18397c ldr r0, [r0, #0x4]
 *   @0x183980 ldr r2, [pc, r2]
 *   @0x183984 ldr r3, [r2]
 *   @0x183988 subs r3, r0, r3
 *   @0x18398c rsbs r0, r3, #0
 *   @0x183990 adcs r0, r0, r3
 *   @0x183994 bx lr
 *   @0x183998 mov r0, r3
 *   @0x18399c bx lr
 *   @0x1839a0 .word 0x0026cad4
 *   @0x1839a4 .word 0x0026cbdc
 *
 * ══ §210/373 EndShaderBlock()  0x1847f8  size 80  20 条（0x1847f8..0x184848）
 * @func 0x1847f8 0x184848  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: EndShaderBlock()+0x28
 * 字段偏移 top8: 0x3c×1 / 0x2c×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1847f8 push {r3, r4, r5, r6, r7, lr}
 *   @0x1847fc ldr r5, [pc, #0x3c]
 *   @0x184800 add r5, pc, r5
 *   @0x184804 ldr r3, [r5]
 *   @0x184808 cmp r3, #0
 *   @0x18480c popeq {r3, r4, r5, r6, r7, pc}
 *   @0x184810 ldr r6, [pc, #0x2c]
 *   @0x184814 mov r7, r5
 *   @0x184818 mov r4, #0
 *   @0x18481c ldr r6, [pc, r6]
 *   @0x184820 ldr r3, [r6]
 *   @0x184824 add r4, r4, #1
 *   @0x184828 ldr r0, [r5, #0x4]!
 *   @0x18482c blx r3
 *   @0x184830 ldr r3, [r7]
 *   @0x184834 cmp r4, r3
 *   @0x184838 blo 0x184820 <_Z14EndShaderBlockv+0x28>
 *   @0x18483c pop {r3, r4, r5, r6, r7, pc}
 *   @0x184840 eorseq lr, r1, r0, asr r7
 *   @0x184844 eoreq r8, r6, r0, asr #31
 *
 * ══ §211/373 GMGamePad::~GMGamePad()  0x18e64c  size 80  20 条（0x18e64c..0x18e69c）
 * @func 0x18e64c 0x18e69c  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×4
 * 字段偏移 top8: 0xc×1 / 0x10×1 / 0x14×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18e64c push {r4, lr}
 *   @0x18e650 mov r4, r0
 *   @0x18e654 ldr r0, [r0, #0xc]
 *   @0x18e658 cmp r0, #0
 *   @0x18e65c beq 0x18e664 <_ZN9GMGamePadD2Ev+0x18>
 *   @0x18e660 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x18e664 ldr r0, [r4, #0x10]
 *   @0x18e668 cmp r0, #0
 *   @0x18e66c beq 0x18e674 <_ZN9GMGamePadD2Ev+0x28>
 *   @0x18e670 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x18e674 ldr r0, [r4, #0x14]
 *   @0x18e678 cmp r0, #0
 *   @0x18e67c beq 0x18e684 <_ZN9GMGamePadD2Ev+0x38>
 *   @0x18e680 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x18e684 ldr r0, [r4, #0x18]
 *   @0x18e688 cmp r0, #0
 *   @0x18e68c beq 0x18e694 <_ZN9GMGamePadD2Ev+0x48>
 *   @0x18e690 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x18e694 mov r0, r4
 *   @0x18e698 pop {r4, pc}
 *
 * ══ §212/373 CGCGeneration::~CGCGeneration()  0x191064  size 80  20 条（0x191064..0x1910b4）
 * @func 0x191064 0x1910b4  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / operator delete(void*)
 * 字段偏移 top8: 0x10×2 / 0x4×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x191064 push {r3, r4, r5, lr}
 *   @0x191068 mov r4, r0
 *   @0x19106c ldr r5, [r0]
 *   @0x191070 cmp r5, #0
 *   @0x191074 beq 0x191098 <_ZN13CGCGenerationD2Ev+0x34>
 *   @0x191078 ldr r0, [r5, #0x10]
 *   @0x19107c cmp r0, #0
 *   @0x191080 beq 0x191090 <_ZN13CGCGenerationD2Ev+0x2c>
 *   @0x191084 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x191088 mov r3, #0
 *   @0x19108c str r3, [r5, #0x10]
 *   @0x191090 mov r0, r5
 *   @0x191094 bl 0x27d1d0 <_ZdlPv>
 *   @0x191098 mov r5, #0
 *   @0x19109c ldr r0, [r4, #0x4]
 *   @0x1910a0 str r5, [r4]
 *   @0x1910a4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1910a8 str r5, [r4, #0x4]
 *   @0x1910ac mov r0, r4
 *   @0x1910b0 pop {r3, r4, r5, pc}
 *
 * ══ §213/373 YYObjectBase::MarkThisOnly4GC(unsigned int*, int)  0x191f0c  size 80  20 条（0x191f0c..0x191f5c）
 * @func 0x191f0c 0x191f5c  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x44×2 / 0x34×2 / 0x2×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x191f0c ldr r3, [pc, #0x44]
 *   @0x191f10 ldr r12, [r0, #0x34]
 *   @0x191f14 ldr r3, [pc, r3]
 *   @0x191f18 ldr r3, [r3]
 *   @0x191f1c cmp r12, r3
 *   @0x191f20 bxhs lr
 *   @0x191f24 ldr r12, [r0, #0x44]
 *   @0x191f28 str r3, [r0, #0x34]
 *   @0x191f2c cmp r12, #0
 *   @0x191f30 bxlt lr
 *   @0x191f34 cmp r12, r2
 *   @0x191f38 bxge lr
 *   @0x191f3c asr r3, r12, #5
 *   @0x191f40 mov r0, #1
 *   @0x191f44 and r12, r12, #31
 *   @0x191f48 ldr r2, [r1, r3, lsl #2]
 *   @0x191f4c orr r12, r2, r0, lsl r12
 *   @0x191f50 str r12, [r1, r3, lsl #2]
 *   @0x191f54 bx lr
 *   @0x191f58 eoreq r11, r5, r8, lsr sp
 *
 * ══ §214/373 CPath::Clear()  0x1a6f98  size 80  20 条（0x1a6f98..0x1a6fe8）
 * @func 0x1a6f98 0x1a6fe8  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2
 * 字段偏移 top8: 0x4×2 / 0xc×2 / 0x10×1 / 0x20×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a6f98 push {r4, lr}
 *   @0x1a6f9c mov r4, r0
 *   @0x1a6fa0 ldr r0, [r0, #0x4]
 *   @0x1a6fa4 cmp r0, #0
 *   @0x1a6fa8 beq 0x1a6fb0 <_ZN5CPath5ClearEv+0x18>
 *   @0x1a6fac bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1a6fb0 ldr r0, [r4, #0xc]
 *   @0x1a6fb4 cmp r0, #0
 *   @0x1a6fb8 beq 0x1a6fc0 <_ZN5CPath5ClearEv+0x28>
 *   @0x1a6fbc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1a6fc0 mov r3, #0
 *   @0x1a6fc4 mov r0, r4
 *   @0x1a6fc8 str r3, [r4, #0x4]
 *   @0x1a6fcc str r3, [r4, #0xc]
 *   @0x1a6fd0 str r3, [r4, #0x10]
 *   @0x1a6fd4 str r3, [r4]
 *   @0x1a6fd8 str r3, [r4, #0x20]
 *   @0x1a6fdc str r3, [r4, #0x8]
 *   @0x1a6fe0 pop {r4, lr}
 *   @0x1a6fe4 b 0x1a6e30 <_ZN5CPath15ComputeInternalEv>
 *
 * ══ §215/373 RomDisk::Init(unsigned char*)  0x1a86ac  size 80  20 条（0x1a86ac..0x1a86fc）
 * @func 0x1a86ac 0x1a86fc  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x40×1 / 0x3c×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a86ac ldr r1, [pc, #0x40]
 *   @0x1a86b0 mov r3, #0
 *   @0x1a86b4 ldr r2, [pc, #0x3c]
 *   @0x1a86b8 ldr r1, [pc, r1]
 *   @0x1a86bc ldr r2, [pc, r2]
 *   @0x1a86c0 str r3, [r1]
 *   @0x1a86c4 ldr r12, [r0]
 *   @0x1a86c8 str r0, [r2]
 *   @0x1a86cc cmp r12, r3
 *   @0x1a86d0 bxle lr
 *   @0x1a86d4 add r12, r0, r12, lsl #3
 *   @0x1a86d8 ldr r2, [r0, #0x4]
 *   @0x1a86dc add r0, r0, #8
 *   @0x1a86e0 cmp r0, r12
 *   @0x1a86e4 add r3, r3, r2
 *   @0x1a86e8 str r3, [r1]
 *   @0x1a86ec bne 0x1a86d8 <_ZN7RomDisk4InitEPh+0x2c>
 *   @0x1a86f0 bx lr
 *   @0x1a86f4 eoreq r8, r4, r4, lsr #2
 *   @0x1a86f8 eoreq r8, r4, r4, lsr #2
 *
 * ══ §216/373 F_TilemapSetGlobalMask(RValue&, CInstance*, CInstance*, int, RValue*)  0x1b6814  size 80  20 条（0x1b6814..0x1b6864）
 * @func 0x1b6814 0x1b6864  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetUint32(RValue const*, int)
 * 字段偏移 top8: 0xc×2 / 0x8×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b6814 cmp r3, #1
 *   @0x1b6818 push {r3, lr}
 *   @0x1b681c mov r3, #0
 *   @0x1b6820 mov r1, r3
 *   @0x1b6824 movt r3, #0xbff0
 *   @0x1b6828 str r1, [r0, #0xc]
 *   @0x1b682c stm r0, {r1, r3}
 *   @0x1b6830 ldr r0, [sp, #0x8]
 *   @0x1b6834 beq 0x1b6848 <_Z22F_TilemapSetGlobalMaskR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x1b6838 ldr r0, [pc, #0x1c]
 *   @0x1b683c pop {r3, lr}
 *   @0x1b6840 add r0, pc, r0
 *   @0x1b6844 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1b6848 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x1b684c ldr r3, [pc, #0xc]
 *   @0x1b6850 ldr r3, [pc, r3]
 *   @0x1b6854 str r0, [r3]
 *   @0x1b6858 pop {r3, pc}
 *   @0x1b685c andseq r6, r9, r0, ror #26
 *   @0x1b6860 eoreq r9, r3, r8, asr #31
 *
 * ══ §217/373 CLayerManager::GetLayerFromName(CRoom*, char const*)  0x1b897c  size 80  20 条（0x1b897c..0x1b89cc）
 * @func 0x1b897c 0x1b89cc  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66d0
 * 字段偏移 top8: 0xd4×1 / 0x1c×1 / 0x68×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b897c push {r3, r4, r5, lr}
 *   @0x1b8980 subs r5, r1, #0
 *   @0x1b8984 beq 0x1b89c4 <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc+0x48>
 *   @0x1b8988 ldr r4, [r0, #0xd4]
 *   @0x1b898c cmp r4, #0
 *   @0x1b8990 beq 0x1b89bc <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc+0x40>
 *   @0x1b8994 ldr r1, [r4, #0x1c]
 *   @0x1b8998 mov r0, r5
 *   @0x1b899c cmp r1, #0
 *   @0x1b89a0 beq 0x1b89b0 <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc+0x34>
 *   @0x1b89a4 bl 0xb66d0 <strcasecmp@plt>
 *   @0x1b89a8 cmp r0, #0
 *   @0x1b89ac beq 0x1b89bc <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc+0x40>
 *   @0x1b89b0 ldr r4, [r4, #0x68]
 *   @0x1b89b4 cmp r4, #0
 *   @0x1b89b8 bne 0x1b8994 <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc+0x18>
 *   @0x1b89bc mov r0, r4
 *   @0x1b89c0 pop {r3, r4, r5, pc}
 *   @0x1b89c4 mov r0, r5
 *   @0x1b89c8 pop {r3, r4, r5, pc}
 *
 * ══ §218/373 CLayerManager::GetNthLayerInRoom(CRoom*, int)  0x1b89d8  size 80  20 条（0x1b89d8..0x1b8a28）
 * @func 0x1b89d8 0x1b8a28  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetNthLayerInRoom(CRoom*, int)+0x48×2
 * 字段偏移 top8: 0xd4×1 / 0x68×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b89d8 cmp r0, #0
 *   @0x1b89dc bxeq lr
 *   @0x1b89e0 ldr r0, [r0, #0xd4]
 *   @0x1b89e4 cmp r0, #0
 *   @0x1b89e8 bxeq lr
 *   @0x1b89ec cmp r1, #0
 *   @0x1b89f0 blt 0x1b8a20 <_ZN13CLayerManager17GetNthLayerInRoomEP5CRoomi+0x48>
 *   @0x1b89f4 bxeq lr
 *   @0x1b89f8 mov r3, #1
 *   @0x1b89fc ldr r0, [r0, #0x68]
 *   @0x1b8a00 cmp r0, #0
 *   @0x1b8a04 bxeq lr
 *   @0x1b8a08 cmp r1, r3
 *   @0x1b8a0c blt 0x1b8a20 <_ZN13CLayerManager17GetNthLayerInRoomEP5CRoomi+0x48>
 *   @0x1b8a10 cmp r3, r1
 *   @0x1b8a14 add r3, r3, #1
 *   @0x1b8a18 bne 0x1b89fc <_ZN13CLayerManager17GetNthLayerInRoomEP5CRoomi+0x24>
 *   @0x1b8a1c bx lr
 *   @0x1b8a20 mov r0, #0
 *   @0x1b8a24 bx lr
 *
 * ══ §219/373 GetTouchActionFromUID(int)  0x1d75f4  size 80  20 条（0x1d75f4..0x1d7644）
 * @func 0x1d75f4 0x1d7644  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x44×1 / 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d75f4 ldr r3, [pc, #0x44]
 *   @0x1d75f8 mov r1, r0
 *   @0x1d75fc ldr r3, [pc, r3]
 *   @0x1d7600 ldr r3, [r3]
 *   @0x1d7604 cmp r3, #0
 *   @0x1d7608 beq 0x1d7630 <_Z21GetTouchActionFromUIDi+0x3c>
 *   @0x1d760c ldr r0, [r3, #0x8]
 *   @0x1d7610 cmp r0, #0
 *   @0x1d7614 beq 0x1d763c <_Z21GetTouchActionFromUIDi+0x48>
 *   @0x1d7618 ldr r2, [r0, #0x4]
 *   @0x1d761c cmp r2, r1
 *   @0x1d7620 beq 0x1d7638 <_Z21GetTouchActionFromUIDi+0x44>
 *   @0x1d7624 ldr r3, [r3]
 *   @0x1d7628 cmp r3, #0
 *   @0x1d762c bne 0x1d760c <_Z21GetTouchActionFromUIDi+0x18>
 *   @0x1d7630 mov r0, r3
 *   @0x1d7634 bx lr
 *   @0x1d7638 bx lr
 *   @0x1d763c bx lr
 *   @0x1d7640 eoreq r9, r1, r8, lsl #12
 *
 * ══ §220/373 GV_BackgroundX(CInstance*, int, RValue*)  0x1f7e04  size 80  20 条（0x1f7e04..0x1f7e54）
 * @func 0x1f7e04 0x1f7e68  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x44×1 / 0xc×1 / 0x24×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f7e04 ldr r3, [pc, #0x44]
 *   @0x1f7e08 cmp r1, #7
 *   @0x1f7e0c push {r4, r5}
 *   @0x1f7e10 ldr r3, [pc, r3]
 *   @0x1f7e14 movhi r1, #0
 *   @0x1f7e18 mov r0, #0
 *   @0x1f7e1c ldr r3, [r3]
 *   @0x1f7e20 str r0, [r2, #0xc]
 *   @0x1f7e24 mov r0, #1
 *   @0x1f7e28 add r1, r3, r1, lsl #2
 *   @0x1f7e2c ldr r3, [r1, #0x24]
 *   @0x1f7e30 vldr s15, [r3, #8]
 *   @0x1f7e34 vcvt.f64.f32 d6, s15
 *   @0x1f7e38 vmov r4, r5, d6
 *   @0x1f7e3c vmov r1, s12
 *   @0x1f7e40 mov r3, r5
 *   @0x1f7e44 pop {r4, r5}
 *   @0x1f7e48 stm r2, {r1, r3}
 *   @0x1f7e4c bx lr
 *   @0x1f7e50 andseq r5, pc, r8, lsl r11
 *
 * ══ §221/373 GV_BackgroundY(CInstance*, int, RValue*)  0x1f7e54  size 80  20 条（0x1f7e54..0x1f7ea4）
 * @func 0x1f7e54 0x1f7eb8  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x44×1 / 0xc×1 / 0x24×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f7e54 ldr r3, [pc, #0x44]
 *   @0x1f7e58 cmp r1, #7
 *   @0x1f7e5c push {r4, r5}
 *   @0x1f7e60 ldr r3, [pc, r3]
 *   @0x1f7e64 movhi r1, #0
 *   @0x1f7e68 mov r0, #0
 *   @0x1f7e6c ldr r3, [r3]
 *   @0x1f7e70 str r0, [r2, #0xc]
 *   @0x1f7e74 mov r0, #1
 *   @0x1f7e78 add r1, r3, r1, lsl #2
 *   @0x1f7e7c ldr r3, [r1, #0x24]
 *   @0x1f7e80 vldr s15, [r3, #12]
 *   @0x1f7e84 vcvt.f64.f32 d6, s15
 *   @0x1f7e88 vmov r4, r5, d6
 *   @0x1f7e8c vmov r1, s12
 *   @0x1f7e90 mov r3, r5
 *   @0x1f7e94 pop {r4, r5}
 *   @0x1f7e98 stm r2, {r1, r3}
 *   @0x1f7e9c bx lr
 *   @0x1f7ea0 andseq r5, pc, r8, asr #21
 *
 * ══ §222/373 GV_BackgroundXScale(CInstance*, int, RValue*)  0x1f7f4c  size 80  20 条（0x1f7f4c..0x1f7f9c）
 * @func 0x1f7f4c 0x1f7fb0  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x44×1 / 0xc×1 / 0x24×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f7f4c ldr r3, [pc, #0x44]
 *   @0x1f7f50 cmp r1, #7
 *   @0x1f7f54 push {r4, r5}
 *   @0x1f7f58 ldr r3, [pc, r3]
 *   @0x1f7f5c movhi r1, #0
 *   @0x1f7f60 mov r0, #0
 *   @0x1f7f64 ldr r3, [r3]
 *   @0x1f7f68 str r0, [r2, #0xc]
 *   @0x1f7f6c mov r0, #1
 *   @0x1f7f70 add r1, r3, r1, lsl #2
 *   @0x1f7f74 ldr r3, [r1, #0x24]
 *   @0x1f7f78 vldr s15, [r3, #28]
 *   @0x1f7f7c vcvt.f64.f32 d6, s15
 *   @0x1f7f80 vmov r4, r5, d6
 *   @0x1f7f84 vmov r1, s12
 *   @0x1f7f88 mov r3, r5
 *   @0x1f7f8c pop {r4, r5}
 *   @0x1f7f90 stm r2, {r1, r3}
 *   @0x1f7f94 bx lr
 *   @0x1f7f98 ldrsbeq r5, [pc], -r0
 *
 * ══ §223/373 GV_BackgroundYScale(CInstance*, int, RValue*)  0x1f7f9c  size 80  20 条（0x1f7f9c..0x1f7fec）
 * @func 0x1f7f9c 0x1f8000  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x44×1 / 0xc×1 / 0x24×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f7f9c ldr r3, [pc, #0x44]
 *   @0x1f7fa0 cmp r1, #7
 *   @0x1f7fa4 push {r4, r5}
 *   @0x1f7fa8 ldr r3, [pc, r3]
 *   @0x1f7fac movhi r1, #0
 *   @0x1f7fb0 mov r0, #0
 *   @0x1f7fb4 ldr r3, [r3]
 *   @0x1f7fb8 str r0, [r2, #0xc]
 *   @0x1f7fbc mov r0, #1
 *   @0x1f7fc0 add r1, r3, r1, lsl #2
 *   @0x1f7fc4 ldr r3, [r1, #0x24]
 *   @0x1f7fc8 vldr s15, [r3, #32]
 *   @0x1f7fcc vcvt.f64.f32 d6, s15
 *   @0x1f7fd0 vmov r4, r5, d6
 *   @0x1f7fd4 vmov r1, s12
 *   @0x1f7fd8 mov r3, r5
 *   @0x1f7fdc pop {r4, r5}
 *   @0x1f7fe0 stm r2, {r1, r3}
 *   @0x1f7fe4 bx lr
 *   @0x1f7fe8 andseq r5, pc, r0, lsl #19
 *
 * ══ §224/373 GV_BackgroundHSpeed(CInstance*, int, RValue*)  0x1f7fec  size 80  20 条（0x1f7fec..0x1f803c）
 * @func 0x1f7fec 0x1f8050  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x44×1 / 0xc×1 / 0x24×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f7fec ldr r3, [pc, #0x44]
 *   @0x1f7ff0 cmp r1, #7
 *   @0x1f7ff4 push {r4, r5}
 *   @0x1f7ff8 ldr r3, [pc, r3]
 *   @0x1f7ffc movhi r1, #0
 *   @0x1f8000 mov r0, #0
 *   @0x1f8004 ldr r3, [r3]
 *   @0x1f8008 str r0, [r2, #0xc]
 *   @0x1f800c mov r0, #1
 *   @0x1f8010 add r1, r3, r1, lsl #2
 *   @0x1f8014 ldr r3, [r1, #0x24]
 *   @0x1f8018 vldr s15, [r3, #20]
 *   @0x1f801c vcvt.f64.f32 d6, s15
 *   @0x1f8020 vmov r4, r5, d6
 *   @0x1f8024 vmov r1, s12
 *   @0x1f8028 mov r3, r5
 *   @0x1f802c pop {r4, r5}
 *   @0x1f8030 stm r2, {r1, r3}
 *   @0x1f8034 bx lr
 *   @0x1f8038 andseq r5, pc, r0, lsr r9
 *
 * ══ §225/373 GV_BackgroundVSpeed(CInstance*, int, RValue*)  0x1f803c  size 80  20 条（0x1f803c..0x1f808c）
 * @func 0x1f803c 0x1f80a0  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x44×1 / 0xc×1 / 0x24×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f803c ldr r3, [pc, #0x44]
 *   @0x1f8040 cmp r1, #7
 *   @0x1f8044 push {r4, r5}
 *   @0x1f8048 ldr r3, [pc, r3]
 *   @0x1f804c movhi r1, #0
 *   @0x1f8050 mov r0, #0
 *   @0x1f8054 ldr r3, [r3]
 *   @0x1f8058 str r0, [r2, #0xc]
 *   @0x1f805c mov r0, #1
 *   @0x1f8060 add r1, r3, r1, lsl #2
 *   @0x1f8064 ldr r3, [r1, #0x24]
 *   @0x1f8068 vldr s15, [r3, #24]
 *   @0x1f806c vcvt.f64.f32 d6, s15
 *   @0x1f8070 vmov r4, r5, d6
 *   @0x1f8074 vmov r1, s12
 *   @0x1f8078 mov r3, r5
 *   @0x1f807c pop {r4, r5}
 *   @0x1f8080 stm r2, {r1, r3}
 *   @0x1f8084 bx lr
 *   @0x1f8088 andseq r5, pc, r0, ror #17
 *
 * ══ §226/373 GV_BackgroundAlpha(CInstance*, int, RValue*)  0x1f80e0  size 80  20 条（0x1f80e0..0x1f8130）
 * @func 0x1f80e0 0x1f8130  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x44×1 / 0xc×1 / 0x24×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f80e0 ldr r3, [pc, #0x44]
 *   @0x1f80e4 cmp r1, #7
 *   @0x1f80e8 push {r4, r5}
 *   @0x1f80ec ldr r3, [pc, r3]
 *   @0x1f80f0 movhi r1, #0
 *   @0x1f80f4 mov r0, #0
 *   @0x1f80f8 ldr r3, [r3]
 *   @0x1f80fc str r0, [r2, #0xc]
 *   @0x1f8100 mov r0, #1
 *   @0x1f8104 add r1, r3, r1, lsl #2
 *   @0x1f8108 ldr r3, [r1, #0x24]
 *   @0x1f810c vldr s15, [r3, #40]
 *   @0x1f8110 vcvt.f64.f32 d6, s15
 *   @0x1f8114 vmov r4, r5, d6
 *   @0x1f8118 vmov r1, s12
 *   @0x1f811c mov r3, r5
 *   @0x1f8120 pop {r4, r5}
 *   @0x1f8124 stm r2, {r1, r3}
 *   @0x1f8128 bx lr
 *   @0x1f812c andseq r5, pc, r12, lsr r8
 *
 * ══ §227/373 GV_ViewXview(CInstance*, int, RValue*)  0x1f8208  size 80  20 条（0x1f8208..0x1f8258）
 * @func 0x1f8208 0x1f826c  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x44×1 / 0xc×1 / 0x2×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f8208 ldr r3, [pc, #0x44]
 *   @0x1f820c cmp r1, #7
 *   @0x1f8210 push {r4, r5}
 *   @0x1f8214 ldr r3, [pc, r3]
 *   @0x1f8218 movhi r1, #0
 *   @0x1f821c add r1, r1, #18
 *   @0x1f8220 ldr r3, [r3]
 *   @0x1f8224 mov r12, #0
 *   @0x1f8228 mov r0, #1
 *   @0x1f822c str r12, [r2, #0xc]
 *   @0x1f8230 ldr r3, [r3, r1, lsl #2]
 *   @0x1f8234 vldr s15, [r3, #4]
 *   @0x1f8238 vcvt.f64.f32 d6, s15
 *   @0x1f823c vmov r4, r5, d6
 *   @0x1f8240 vmov r1, s12
 *   @0x1f8244 mov r3, r5
 *   @0x1f8248 pop {r4, r5}
 *   @0x1f824c stm r2, {r1, r3}
 *   @0x1f8250 bx lr
 *   @0x1f8254 andseq r5, pc, r4, lsl r7
 *
 * ══ §228/373 GV_ViewYview(CInstance*, int, RValue*)  0x1f8258  size 80  20 条（0x1f8258..0x1f82a8）
 * @func 0x1f8258 0x1f82bc  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x44×1 / 0xc×1 / 0x2×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f8258 ldr r3, [pc, #0x44]
 *   @0x1f825c cmp r1, #7
 *   @0x1f8260 push {r4, r5}
 *   @0x1f8264 ldr r3, [pc, r3]
 *   @0x1f8268 movhi r1, #0
 *   @0x1f826c add r1, r1, #18
 *   @0x1f8270 ldr r3, [r3]
 *   @0x1f8274 mov r12, #0
 *   @0x1f8278 mov r0, #1
 *   @0x1f827c str r12, [r2, #0xc]
 *   @0x1f8280 ldr r3, [r3, r1, lsl #2]
 *   @0x1f8284 vldr s15, [r3, #8]
 *   @0x1f8288 vcvt.f64.f32 d6, s15
 *   @0x1f828c vmov r4, r5, d6
 *   @0x1f8290 vmov r1, s12
 *   @0x1f8294 mov r3, r5
 *   @0x1f8298 pop {r4, r5}
 *   @0x1f829c stm r2, {r1, r3}
 *   @0x1f82a0 bx lr
 *   @0x1f82a4 andseq r5, pc, r4, asr #13
 *
 * ══ §229/373 GV_ViewWview(CInstance*, int, RValue*)  0x1f82a8  size 80  20 条（0x1f82a8..0x1f82f8）
 * @func 0x1f82a8 0x1f830c  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x44×1 / 0xc×1 / 0x2×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f82a8 ldr r3, [pc, #0x44]
 *   @0x1f82ac cmp r1, #7
 *   @0x1f82b0 push {r4, r5}
 *   @0x1f82b4 ldr r3, [pc, r3]
 *   @0x1f82b8 movhi r1, #0
 *   @0x1f82bc add r1, r1, #18
 *   @0x1f82c0 ldr r3, [r3]
 *   @0x1f82c4 mov r12, #0
 *   @0x1f82c8 mov r0, #1
 *   @0x1f82cc str r12, [r2, #0xc]
 *   @0x1f82d0 ldr r3, [r3, r1, lsl #2]
 *   @0x1f82d4 vldr s15, [r3, #12]
 *   @0x1f82d8 vcvt.f64.f32 d6, s15
 *   @0x1f82dc vmov r4, r5, d6
 *   @0x1f82e0 vmov r1, s12
 *   @0x1f82e4 mov r3, r5
 *   @0x1f82e8 pop {r4, r5}
 *   @0x1f82ec stm r2, {r1, r3}
 *   @0x1f82f0 bx lr
 *   @0x1f82f4 andseq r5, pc, r4, ror r6
 *
 * ══ §230/373 GV_ViewHview(CInstance*, int, RValue*)  0x1f82f8  size 80  20 条（0x1f82f8..0x1f8348）
 * @func 0x1f82f8 0x1f835c  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x44×1 / 0xc×1 / 0x2×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f82f8 ldr r3, [pc, #0x44]
 *   @0x1f82fc cmp r1, #7
 *   @0x1f8300 push {r4, r5}
 *   @0x1f8304 ldr r3, [pc, r3]
 *   @0x1f8308 movhi r1, #0
 *   @0x1f830c add r1, r1, #18
 *   @0x1f8310 ldr r3, [r3]
 *   @0x1f8314 mov r12, #0
 *   @0x1f8318 mov r0, #1
 *   @0x1f831c str r12, [r2, #0xc]
 *   @0x1f8320 ldr r3, [r3, r1, lsl #2]
 *   @0x1f8324 vldr s15, [r3, #16]
 *   @0x1f8328 vcvt.f64.f32 d6, s15
 *   @0x1f832c vmov r4, r5, d6
 *   @0x1f8330 vmov r1, s12
 *   @0x1f8334 mov r3, r5
 *   @0x1f8338 pop {r4, r5}
 *   @0x1f833c stm r2, {r1, r3}
 *   @0x1f8340 bx lr
 *   @0x1f8344 andseq r5, pc, r4, lsr #12
 *
 * ══ §231/373 GV_ViewAngle(CInstance*, int, RValue*)  0x1f8498  size 80  20 条（0x1f8498..0x1f84e8）
 * @func 0x1f8498 0x1f84fc  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x44×1 / 0xc×1 / 0x2×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f8498 ldr r3, [pc, #0x44]
 *   @0x1f849c cmp r1, #7
 *   @0x1f84a0 push {r4, r5}
 *   @0x1f84a4 ldr r3, [pc, r3]
 *   @0x1f84a8 movhi r1, #0
 *   @0x1f84ac add r1, r1, #18
 *   @0x1f84b0 ldr r3, [r3]
 *   @0x1f84b4 mov r12, #0
 *   @0x1f84b8 mov r0, #1
 *   @0x1f84bc str r12, [r2, #0xc]
 *   @0x1f84c0 ldr r3, [r3, r1, lsl #2]
 *   @0x1f84c4 vldr s15, [r3, #36]
 *   @0x1f84c8 vcvt.f64.f32 d6, s15
 *   @0x1f84cc vmov r4, r5, d6
 *   @0x1f84d0 vmov r1, s12
 *   @0x1f84d4 mov r3, r5
 *   @0x1f84d8 pop {r4, r5}
 *   @0x1f84dc stm r2, {r1, r3}
 *   @0x1f84e0 bx lr
 *   @0x1f84e4 andseq r5, pc, r4, lsl #9
 *
 * ══ §232/373 GV_PhysicsBodyDynamic(CInstance*, int, RValue*)  0x1f9894  size 80  20 条（0x1f9894..0x1f98e4）
 * @func 0x1f9894 0x1f98f8  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x84×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f9894 ldr r0, [r0, #0x84]
 *   @0x1f9898 push {r4, r5}
 *   @0x1f989c cmp r0, #0
 *   @0x1f98a0 beq 0x1f98dc <_Z21GV_PhysicsBodyDynamicP9CInstanceiP6RValue+0x48>
 *   @0x1f98a4 ldr r3, [r0]
 *   @0x1f98a8 mov r1, #0
 *   @0x1f98ac str r1, [r2, #0xc]
 *   @0x1f98b0 mov r0, #1
 *   @0x1f98b4 ldr r4, [r3]
 *   @0x1f98b8 subs r3, r4, #2
 *   @0x1f98bc rsbs r4, r3, #0
 *   @0x1f98c0 adcs r4, r4, r3
 *   @0x1f98c4 vmov s15, r4
 *   @0x1f98c8 vcvt.f64.u32 d7, s15
 *   @0x1f98cc vmov r4, r5, d7
 *   @0x1f98d0 vmov r1, s14
 *   @0x1f98d4 mov r3, r5
 *   @0x1f98d8 stm r2, {r1, r3}
 *   @0x1f98dc pop {r4, r5}
 *   @0x1f98e0 bx lr
 *
 * ══ §233/373 GV_PhysicsBodyKinematic(CInstance*, int, RValue*)  0x1f98e4  size 80  20 条（0x1f98e4..0x1f9934）
 * @func 0x1f98e4 0x1f9934  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x84×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f98e4 ldr r0, [r0, #0x84]
 *   @0x1f98e8 push {r4, r5}
 *   @0x1f98ec cmp r0, #0
 *   @0x1f98f0 beq 0x1f992c <_Z23GV_PhysicsBodyKinematicP9CInstanceiP6RValue+0x48>
 *   @0x1f98f4 ldr r3, [r0]
 *   @0x1f98f8 mov r0, #1
 *   @0x1f98fc mov r1, #0
 *   @0x1f9900 str r1, [r2, #0xc]
 *   @0x1f9904 ldr r4, [r3]
 *   @0x1f9908 subs r3, r4, r0
 *   @0x1f990c rsbs r4, r3, #0
 *   @0x1f9910 adcs r4, r4, r3
 *   @0x1f9914 vmov s15, r4
 *   @0x1f9918 vcvt.f64.u32 d7, s15
 *   @0x1f991c vmov r4, r5, d7
 *   @0x1f9920 vmov r1, s14
 *   @0x1f9924 mov r3, r5
 *   @0x1f9928 stm r2, {r1, r3}
 *   @0x1f992c pop {r4, r5}
 *   @0x1f9930 bx lr
 *
 * ══ §234/373 SV_MaskIndex(CInstance*, int, RValue*)  0x1fb93c  size 80  20 条（0x1fb93c..0x1fb98c）
 * @func 0x1fb93c 0x1fb98c  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8 / CInstance::Set_MaskIndex(int) / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fb93c ldr r3, [r2, #0xc]
 *   @0x1fb940 push {r4, lr}
 *   @0x1fb944 bic r3, r3, #-16777216
 *   @0x1fb948 cmp r3, #0
 *   @0x1fb94c mov r4, r0
 *   @0x1fb950 bne 0x1fb980 <_Z12SV_MaskIndexP9CInstanceiP6RValue+0x44>
 *   @0x1fb954 ldm r2, {r0, r1}
 *   @0x1fb958 vmov d6, r0, r1
 *   @0x1fb95c vcvt.f32.f64 s15, d6
 *   @0x1fb960 vcvt.f64.f32 d6, s15
 *   @0x1fb964 vmov r0, r1, d6
 *   @0x1fb968 bl 0xb66e8 <lrint@plt>
 *   @0x1fb96c mov r1, r0
 *   @0x1fb970 mov r0, r4
 *   @0x1fb974 bl 0x192ba8 <_ZN9CInstance13Set_MaskIndexEi>
 *   @0x1fb978 mov r0, #1
 *   @0x1fb97c pop {r4, pc}
 *   @0x1fb980 mov r0, r2
 *   @0x1fb984 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fb988 b 0x1fb958 <_Z12SV_MaskIndexP9CInstanceiP6RValue+0x1c>
 *
 * ══ §235/373 SV_X(CInstance*, int, RValue*)  0x1fbbf8  size 80  20 条（0x1fbbf8..0x1fbc48）
 * @func 0x1fbbf8 0x1fbc48  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::SetPosition(float, float) / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×1 / 0xb8×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fbbf8 ldr r3, [r2, #0xc]
 *   @0x1fbbfc push {r4, r5, r6, lr}
 *   @0x1fbc00 bic r3, r3, #-16777216
 *   @0x1fbc04 cmp r3, #0
 *   @0x1fbc08 mov r6, r0
 *   @0x1fbc0c bne 0x1fbc34 <_Z4SV_XP9CInstanceiP6RValue+0x3c>
 *   @0x1fbc10 ldm r2, {r4, r5}
 *   @0x1fbc14 vmov d7, r4, r5
 *   @0x1fbc18 mov r0, r6
 *   @0x1fbc1c ldr r2, [r6, #0xb8]
 *   @0x1fbc20 vcvt.f32.f64 s15, d7
 *   @0x1fbc24 vmov r1, s15
 *   @0x1fbc28 bl 0x193e7c <_ZN9CInstance11SetPositionEff>
 *   @0x1fbc2c mov r0, #1
 *   @0x1fbc30 pop {r4, r5, r6, pc}
 *   @0x1fbc34 mov r0, r2
 *   @0x1fbc38 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fbc3c mov r4, r0
 *   @0x1fbc40 mov r5, r1
 *   @0x1fbc44 b 0x1fbc14 <_Z4SV_XP9CInstanceiP6RValue+0x1c>
 *
 * ══ §236/373 SV_Visible(CInstance*, int, RValue*)  0x1fbdec  size 80  20 条（0x1fbdec..0x1fbe3c）
 * @func 0x1fbdec 0x1fbe50  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8 / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×1 / 0x65×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fbdec ldr r3, [r2, #0xc]
 *   @0x1fbdf0 push {r4, lr}
 *   @0x1fbdf4 bic r3, r3, #-16777216
 *   @0x1fbdf8 cmp r3, #0
 *   @0x1fbdfc mov r4, r0
 *   @0x1fbe00 bne 0x1fbe30 <_Z10SV_VisibleP9CInstanceiP6RValue+0x44>
 *   @0x1fbe04 ldm r2, {r0, r1}
 *   @0x1fbe08 vmov d6, r0, r1
 *   @0x1fbe0c vcvt.f32.f64 s15, d6
 *   @0x1fbe10 vcvt.f64.f32 d6, s15
 *   @0x1fbe14 vmov r0, r1, d6
 *   @0x1fbe18 bl 0xb66e8 <lrint@plt>
 *   @0x1fbe1c adds r3, r0, #0
 *   @0x1fbe20 mov r0, #1
 *   @0x1fbe24 movne r3, #1
 *   @0x1fbe28 strb r3, [r4, #0x65]
 *   @0x1fbe2c pop {r4, pc}
 *   @0x1fbe30 mov r0, r2
 *   @0x1fbe34 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fbe38 b 0x1fbe08 <_Z10SV_VisibleP9CInstanceiP6RValue+0x1c>
 *
 * ══ §237/373 SV_Solid(CInstance*, int, RValue*)  0x1fbe3c  size 80  20 条（0x1fbe3c..0x1fbe8c）
 * @func 0x1fbe3c 0x1fbea0  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8 / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×1 / 0x66×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fbe3c ldr r3, [r2, #0xc]
 *   @0x1fbe40 push {r4, lr}
 *   @0x1fbe44 bic r3, r3, #-16777216
 *   @0x1fbe48 cmp r3, #0
 *   @0x1fbe4c mov r4, r0
 *   @0x1fbe50 bne 0x1fbe80 <_Z8SV_SolidP9CInstanceiP6RValue+0x44>
 *   @0x1fbe54 ldm r2, {r0, r1}
 *   @0x1fbe58 vmov d6, r0, r1
 *   @0x1fbe5c vcvt.f32.f64 s15, d6
 *   @0x1fbe60 vcvt.f64.f32 d6, s15
 *   @0x1fbe64 vmov r0, r1, d6
 *   @0x1fbe68 bl 0xb66e8 <lrint@plt>
 *   @0x1fbe6c adds r3, r0, #0
 *   @0x1fbe70 mov r0, #1
 *   @0x1fbe74 movne r3, #1
 *   @0x1fbe78 strb r3, [r4, #0x66]
 *   @0x1fbe7c pop {r4, pc}
 *   @0x1fbe80 mov r0, r2
 *   @0x1fbe84 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fbe88 b 0x1fbe58 <_Z8SV_SolidP9CInstanceiP6RValue+0x1c>
 *
 * ══ §238/373 SV_Persistent(CInstance*, int, RValue*)  0x1fbe8c  size 80  20 条（0x1fbe8c..0x1fbedc）
 * @func 0x1fbe8c 0x1fbedc  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8 / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×1 / 0x67×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fbe8c ldr r3, [r2, #0xc]
 *   @0x1fbe90 push {r4, lr}
 *   @0x1fbe94 bic r3, r3, #-16777216
 *   @0x1fbe98 cmp r3, #0
 *   @0x1fbe9c mov r4, r0
 *   @0x1fbea0 bne 0x1fbed0 <_Z13SV_PersistentP9CInstanceiP6RValue+0x44>
 *   @0x1fbea4 ldm r2, {r0, r1}
 *   @0x1fbea8 vmov d6, r0, r1
 *   @0x1fbeac vcvt.f32.f64 s15, d6
 *   @0x1fbeb0 vcvt.f64.f32 d6, s15
 *   @0x1fbeb4 vmov r0, r1, d6
 *   @0x1fbeb8 bl 0xb66e8 <lrint@plt>
 *   @0x1fbebc adds r3, r0, #0
 *   @0x1fbec0 mov r0, #1
 *   @0x1fbec4 movne r3, #1
 *   @0x1fbec8 strb r3, [r4, #0x67]
 *   @0x1fbecc pop {r4, pc}
 *   @0x1fbed0 mov r0, r2
 *   @0x1fbed4 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fbed8 b 0x1fbea8 <_Z13SV_PersistentP9CInstanceiP6RValue+0x1c>
 *
 * ══ §239/373 CStream::SaveToFile(char const*)  0x201194  size 80  20 条（0x201194..0x2011e4）
 * @func 0x201194 0x2011e4  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6844 / 0xb68bc
 * 字段偏移 top8: 0x18×2 / 0x2c×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x201194 push {r3, r4, r5, lr}
 *   @0x201198 mov r4, r0
 *   @0x20119c ldr r3, [r0, #0x18]
 *   @0x2011a0 cmp r3, #0
 *   @0x2011a4 popeq {r3, r4, r5, pc}
 *   @0x2011a8 mov r0, r1
 *   @0x2011ac ldr r1, [pc, #0x2c]
 *   @0x2011b0 add r1, pc, r1
 *   @0x2011b4 bl 0xb6844 <fopen@plt>
 *   @0x2011b8 subs r5, r0, #0
 *   @0x2011bc popeq {r3, r4, r5, pc}
 *   @0x2011c0 ldr r0, [r4, #0x18]
 *   @0x2011c4 mov r3, r5
 *   @0x2011c8 ldr r1, [r4, #0x10]
 *   @0x2011cc mov r2, #1
 *   @0x2011d0 bl 0xb68bc <fwrite@plt>
 *   @0x2011d4 mov r0, r5
 *   @0x2011d8 pop {r3, r4, r5, lr}
 *   @0x2011dc b 0xb6850 <fclose@plt>
 *   @0x2011e0 mulseq r3, r4, r1
 *
 * ══ §240/373 COggAudio::~COggAudio()  0x215c3c  size 80  20 条（0x215c3c..0x215c8c）
 * @func 0x215c3c 0x215c8c  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2
 * 字段偏移 top8: 0x10×3 / 0x4×2 / 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x215c3c push {r3, r4, r5, lr}
 *   @0x215c40 mov r4, r0
 *   @0x215c44 ldr r3, [r0, #0x4]
 *   @0x215c48 cmp r3, #0
 *   @0x215c4c beq 0x215c74 <_ZN9COggAudioD2Ev+0x38>
 *   @0x215c50 ldr r5, [r0, #0x10]
 *   @0x215c54 subs r0, r5, #0
 *   @0x215c58 beq 0x215c7c <_ZN9COggAudioD2Ev+0x40>
 *   @0x215c5c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x215c60 mov r3, #0
 *   @0x215c64 str r3, [r4, #0x10]
 *   @0x215c68 str r3, [r4, #0x8]
 *   @0x215c6c mov r3, #0
 *   @0x215c70 str r3, [r4, #0x4]
 *   @0x215c74 mov r0, r4
 *   @0x215c78 pop {r3, r4, r5, pc}
 *   @0x215c7c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x215c80 str r5, [r4, #0x10]
 *   @0x215c84 str r5, [r4, #0x8]
 *   @0x215c88 b 0x215c6c <_ZN9COggAudioD2Ev+0x30>
 *
 * ══ §241/373 Audio_NoiseIsPlayingOgg(CNoise*)  0x217388  size 80  20 条（0x217388..0x2173d8）
 * @func 0x217388 0x2173d8  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Audio_GetSound(int)
 * 字段偏移 top8: 0x40×1 / 0x18×1 / 0x24×1 / 0x25×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x217388 push {r3, lr}
 *   @0x21738c ldr r3, [pc, #0x40]
 *   @0x217390 ldr r3, [pc, r3]
 *   @0x217394 ldrb r3, [r3]
 *   @0x217398 cmp r3, #0
 *   @0x21739c beq 0x2173a8 <_Z23Audio_NoiseIsPlayingOggP6CNoise+0x20>
 *   @0x2173a0 mov r0, #0
 *   @0x2173a4 pop {r3, pc}
 *   @0x2173a8 ldr r0, [r0, #0x18]
 *   @0x2173ac bl 0x21632c <_Z14Audio_GetSoundi>
 *   @0x2173b0 subs r3, r0, #0
 *   @0x2173b4 beq 0x2173a0 <_Z23Audio_NoiseIsPlayingOggP6CNoise+0x18>
 *   @0x2173b8 ldrb r0, [r3, #0x24]
 *   @0x2173bc cmp r0, #0
 *   @0x2173c0 popne {r3, pc}
 *   @0x2173c4 ldrb r0, [r3, #0x25]
 *   @0x2173c8 cmp r0, #0
 *   @0x2173cc beq 0x2173a0 <_Z23Audio_NoiseIsPlayingOggP6CNoise+0x18>
 *   @0x2173d0 pop {r3, pc}
 *   @0x2173d4 ldrheq r7, [sp], -r12
 *
 * ══ §242/373 _alutInputStreamEOF  0x221e28  size 80  20 条（0x221e28..0x221e78）
 * @func 0x221e28 0x221e8c  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6880 / 0xb6bec
 * 字段偏移 top8: 0xc×2 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x221e28 push {r3, r4, r5, lr}
 *   @0x221e2c mov r4, r0
 *   @0x221e30 ldrb r3, [r0]
 *   @0x221e34 cmp r3, #0
 *   @0x221e38 bne 0x221e4c <_alutInputStreamEOF+0x24>
 *   @0x221e3c ldr r0, [r0, #0x8]
 *   @0x221e40 rsbs r0, r0, #1
 *   @0x221e44 movlo r0, #0
 *   @0x221e48 pop {r3, r4, r5, pc}
 *   @0x221e4c ldr r0, [r0, #0xc]
 *   @0x221e50 bl 0xb6880 <fgetc@plt>
 *   @0x221e54 cmn r0, #1
 *   @0x221e58 mov r5, r0
 *   @0x221e5c beq 0x221e68 <_alutInputStreamEOF+0x40>
 *   @0x221e60 ldr r1, [r4, #0xc]
 *   @0x221e64 bl 0xb6bec <ungetc@plt>
 *   @0x221e68 cmn r5, #1
 *   @0x221e6c movne r0, #0
 *   @0x221e70 moveq r0, #1
 *   @0x221e74 pop {r3, r4, r5, pc}
 *
 * ══ §243/373 _alutInputStreamRead  0x221e78  size 80  20 条（0x221e78..0x221ec8）
 * @func 0x221e78 0x221edc  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _alutMalloc / anon_221c48 / 0xb655c
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x221e78 push {r4, r5, r6, lr}
 *   @0x221e7c mov r6, r0
 *   @0x221e80 mov r0, r1
 *   @0x221e84 mov r4, r1
 *   @0x221e88 bl 0x222a98 <_alutMalloc>
 *   @0x221e8c subs r5, r0, #0
 *   @0x221e90 beq 0x221eb4 <_alutInputStreamRead+0x3c>
 *   @0x221e94 mov r2, r4
 *   @0x221e98 mov r0, r6
 *   @0x221e9c mov r1, r5
 *   @0x221ea0 bl 0x221c48 <alutExit+0xd0>
 *   @0x221ea4 subs r4, r0, #0
 *   @0x221ea8 mov r0, r5
 *   @0x221eac beq 0x221ebc <_alutInputStreamRead+0x44>
 *   @0x221eb0 pop {r4, r5, r6, pc}
 *   @0x221eb4 mov r0, r5
 *   @0x221eb8 pop {r4, r5, r6, pc}
 *   @0x221ebc bl 0xb655c <free@plt>
 *   @0x221ec0 mov r0, r4
 *   @0x221ec4 pop {r4, r5, r6, pc}
 *
 * ══ §244/373 _alutInputStreamReadInt32BE  0x221f54  size 80  20 条（0x221f54..0x221fa4）
 * @func 0x221f54 0x221fb8  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_221c48
 * 字段偏移 top8: 0x5×1 / 0x4×1 / 0x7×1 / 0x6×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x221f54 push {r4, lr}
 *   @0x221f58 sub sp, sp, #8
 *   @0x221f5c mov r2, #4
 *   @0x221f60 mov r4, r1
 *   @0x221f64 add r1, sp, r2
 *   @0x221f68 bl 0x221c48 <alutExit+0xd0>
 *   @0x221f6c cmp r0, #0
 *   @0x221f70 beq 0x221f9c <_alutInputStreamReadInt32BE+0x48>
 *   @0x221f74 ldrb r3, [sp, #0x5]
 *   @0x221f78 mov r0, #1
 *   @0x221f7c ldrb r12, [sp, #0x4]
 *   @0x221f80 ldrb r1, [sp, #0x7]
 *   @0x221f84 lsl r3, r3, #16
 *   @0x221f88 ldrb r2, [sp, #0x6]
 *   @0x221f8c orr r3, r3, r12, lsl #24
 *   @0x221f90 orr r3, r3, r1
 *   @0x221f94 orr r3, r3, r2, lsl #8
 *   @0x221f98 str r3, [r4]
 *   @0x221f9c add sp, sp, #8
 *   @0x221fa0 pop {r4, pc}
 *
 * ══ §245/373 _alutInputStreamReadUInt32LE  0x221fa4  size 80  20 条（0x221fa4..0x221ff4）
 * @func 0x221fa4 0x221ff4  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_221c48
 * 字段偏移 top8: 0x6×1 / 0x7×1 / 0x4×1 / 0x5×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x221fa4 push {r4, lr}
 *   @0x221fa8 sub sp, sp, #8
 *   @0x221fac mov r2, #4
 *   @0x221fb0 mov r4, r1
 *   @0x221fb4 add r1, sp, r2
 *   @0x221fb8 bl 0x221c48 <alutExit+0xd0>
 *   @0x221fbc cmp r0, #0
 *   @0x221fc0 beq 0x221fec <_alutInputStreamReadUInt32LE+0x48>
 *   @0x221fc4 ldrb r3, [sp, #0x6]
 *   @0x221fc8 mov r0, #1
 *   @0x221fcc ldrb r12, [sp, #0x7]
 *   @0x221fd0 ldrb r1, [sp, #0x4]
 *   @0x221fd4 lsl r3, r3, #16
 *   @0x221fd8 ldrb r2, [sp, #0x5]
 *   @0x221fdc orr r3, r3, r12, lsl #24
 *   @0x221fe0 orr r3, r3, r1
 *   @0x221fe4 orr r3, r3, r2, lsl #8
 *   @0x221fe8 str r3, [r4]
 *   @0x221fec add sp, sp, #8
 *   @0x221ff0 pop {r4, pc}
 *
 * ══ §246/373 COggThread::ShowError()  0x224770  size 80  20 条（0x224770..0x2247c0）
 * @func 0x224770 0x2247c0  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: COggThread::Lock()
 * 字段偏移 top8: 0x800×2 / 0x2c×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x224770 push {r4, lr}
 *   @0x224774 mov r4, r0
 *   @0x224778 bl 0x223a9c <_ZN10COggThread4LockEv>
 *   @0x22477c ldrb r3, [r4, #0x800]
 *   @0x224780 cmp r3, #0
 *   @0x224784 beq 0x2247b0 <_ZN10COggThread9ShowErrorEv+0x40>
 *   @0x224788 ldr r3, [pc, #0x2c]
 *   @0x22478c mov r1, r4
 *   @0x224790 ldr r3, [pc, r3]
 *   @0x224794 ldr r0, [r3]
 *   @0x224798 ldr r3, [r0]
 *   @0x22479c ldr r3, [r3, #0xc]
 *   @0x2247a0 blx r3
 *   @0x2247a4 mov r3, #0
 *   @0x2247a8 strb r3, [r4]
 *   @0x2247ac strb r3, [r4, #0x800]
 *   @0x2247b0 mov r0, r4
 *   @0x2247b4 pop {r4, lr}
 *   @0x2247b8 b 0x223aa4 <_ZN10COggThread6UnlockEv>
 *   @0x2247bc andseq r8, r12, r4, lsl #31
 *
 * ══ §247/373 COggSyncThread::ShowError()  0x225078  size 80  20 条（0x225078..0x2250c8）
 * @func 0x225078 0x2250c8  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: COggSyncThread::Lock()
 * 字段偏移 top8: 0x800×2 / 0x2c×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x225078 push {r4, lr}
 *   @0x22507c mov r4, r0
 *   @0x225080 bl 0x224c24 <_ZN14COggSyncThread4LockEv>
 *   @0x225084 ldrb r3, [r4, #0x800]
 *   @0x225088 cmp r3, #0
 *   @0x22508c beq 0x2250b8 <_ZN14COggSyncThread9ShowErrorEv+0x40>
 *   @0x225090 ldr r3, [pc, #0x2c]
 *   @0x225094 mov r1, r4
 *   @0x225098 ldr r3, [pc, r3]
 *   @0x22509c ldr r0, [r3]
 *   @0x2250a0 ldr r3, [r0]
 *   @0x2250a4 ldr r3, [r3, #0xc]
 *   @0x2250a8 blx r3
 *   @0x2250ac mov r3, #0
 *   @0x2250b0 strb r3, [r4]
 *   @0x2250b4 strb r3, [r4, #0x800]
 *   @0x2250b8 mov r0, r4
 *   @0x2250bc pop {r4, lr}
 *   @0x2250c0 b 0x224c2c <_ZN14COggSyncThread6UnlockEv>
 *   @0x2250c4 andseq r8, r12, r12, ror r6
 *
 * ══ §248/373 ov_test  0x2311b4  size 80  20 条（0x2311b4..0x231204）
 * @func 0x2311b4 0x231204  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ov_test_callbacks
 * 字段偏移 top8: 0x44×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2311b4 ldr r12, [pc, #0x44]
 *   @0x2311b8 push {r4, r5, r6, lr}
 *   @0x2311bc add r12, pc, r12
 *   @0x2311c0 mov lr, r3
 *   @0x2311c4 mov r6, r0
 *   @0x2311c8 mov r5, r1
 *   @0x2311cc mov r4, r2
 *   @0x2311d0 ldm r12, {r0, r1, r2, r3}
 *   @0x2311d4 sub sp, sp, #32
 *   @0x2311d8 add r12, sp, #16
 *   @0x2311dc stm r12, {r0, r1, r2, r3}
 *   @0x2311e0 stm sp, {r0, r1, r2, r3}
 *   @0x2311e4 mov r0, r6
 *   @0x2311e8 mov r1, r5
 *   @0x2311ec mov r2, r4
 *   @0x2311f0 mov r3, lr
 *   @0x2311f4 bl 0x231188 <ov_test_callbacks>
 *   @0x2311f8 add sp, sp, #32
 *   @0x2311fc pop {r4, r5, r6, pc}
 *   @0x231200 ldrsbeq r6, [r12], -r0
 *
 * ══ §249/373 ov_open  0x231cec  size 80  20 条（0x231cec..0x231d3c）
 * @func 0x231cec 0x231d3c  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ov_open_callbacks
 * 字段偏移 top8: 0x44×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x231cec ldr r12, [pc, #0x44]
 *   @0x231cf0 push {r4, r5, r6, lr}
 *   @0x231cf4 add r12, pc, r12
 *   @0x231cf8 mov lr, r3
 *   @0x231cfc mov r6, r0
 *   @0x231d00 mov r5, r1
 *   @0x231d04 mov r4, r2
 *   @0x231d08 ldm r12, {r0, r1, r2, r3}
 *   @0x231d0c sub sp, sp, #32
 *   @0x231d10 add r12, sp, #16
 *   @0x231d14 stm r12, {r0, r1, r2, r3}
 *   @0x231d18 stm sp, {r0, r1, r2, r3}
 *   @0x231d1c mov r0, r6
 *   @0x231d20 mov r1, r5
 *   @0x231d24 mov r2, r4
 *   @0x231d28 mov r3, lr
 *   @0x231d2c bl 0x231c48 <ov_open_callbacks>
 *   @0x231d30 add sp, sp, #32
 *   @0x231d34 pop {r4, r5, r6, pc}
 *   @0x231d38 mulseq r12, r8, r6
 *
 * ══ §250/373 ov_comment  0x232e78  size 80  20 条（0x232e78..0x232ec8）
 * @func 0x232e78 0x232ec8  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ov_comment+0x34 / ov_comment+0x2c
 * 字段偏移 top8: 0x4c×2 / 0x4×1 / 0x34×1 / 0x58×1 / 0x60×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x232e78 ldr r3, [r0, #0x4]
 *   @0x232e7c cmp r3, #0
 *   @0x232e80 beq 0x232ea4 <ov_comment+0x2c>
 *   @0x232e84 cmp r1, #0
 *   @0x232e88 blt 0x232eac <ov_comment+0x34>
 *   @0x232e8c ldr r3, [r0, #0x34]
 *   @0x232e90 cmp r1, r3
 *   @0x232e94 ldrlt r0, [r0, #0x4c]
 *   @0x232e98 addlt r0, r0, r1, lsl #4
 *   @0x232e9c movge r0, #0
 *   @0x232ea0 bx lr
 *   @0x232ea4 ldr r0, [r0, #0x4c]
 *   @0x232ea8 bx lr
 *   @0x232eac ldr r3, [r0, #0x58]
 *   @0x232eb0 cmp r3, #2
 *   @0x232eb4 ble 0x232ea4 <ov_comment+0x2c>
 *   @0x232eb8 ldr r1, [r0, #0x60]
 *   @0x232ebc ldr r3, [r0, #0x4c]
 *   @0x232ec0 add r0, r3, r1, lsl #4
 *   @0x232ec4 bx lr
 *
 * ══ §251/373 oggpack_writetrunc  0x2332cc  size 80  20 条（0x2332cc..0x23331c）
 * @func 0x2332cc 0x233330  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×2 / 0x4×2 / 0x3×2 / 0x-4×1 / 0x30×1 / 0x8×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2332cc ldr r2, [r0, #0xc]
 *   @0x2332d0 asr r3, r1, #3
 *   @0x2332d4 str r4, [sp, #-0x4]!
 *   @0x2332d8 cmp r2, #0
 *   @0x2332dc beq 0x233310 <oggpack_writetrunc+0x44>
 *   @0x2332e0 ldr r4, [pc, #0x30]
 *   @0x2332e4 sub r12, r1, r3, lsl #3
 *   @0x2332e8 ldr r2, [r0, #0x8]
 *   @0x2332ec add r4, pc, r4
 *   @0x2332f0 str r3, [r0]
 *   @0x2332f4 str r12, [r0, #0x4]
 *   @0x2332f8 add r3, r2, r3
 *   @0x2332fc str r3, [r0, #0xc]
 *   @0x233300 ldr r0, [r4, r12, lsl #2]
 *   @0x233304 ldrb r3, [r2, r1, asr #3]
 *   @0x233308 and r3, r0, r3
 *   @0x23330c strb r3, [r2, r1, asr #3]
 *   @0x233310 ldr r4, [sp], #4
 *   @0x233314 bx lr
 *   @0x233318 andseq r5, r3, r12, asr #14
 *
 * ══ §252/373 CPhysicsObject::SetDensity(int, float)  0x237a18  size 80  20 条（0x237a18..0x237a68）
 * @func 0x237a18 0x237a68  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×1 / 0x3×1 / 0x4×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x237a18 ldr r3, [r0, #0x1c]
 *   @0x237a1c ldm r3, {r3, r12}
 *   @0x237a20 and r12, r1, r12
 *   @0x237a24 ldr r3, [r3, r12, lsl #3]
 *   @0x237a28 cmp r3, #0
 *   @0x237a2c bne 0x237a40 <_ZN14CPhysicsObject10SetDensityEif+0x28>
 *   @0x237a30 bx lr
 *   @0x237a34 ldr r3, [r3, #0x4]
 *   @0x237a38 cmp r3, #0
 *   @0x237a3c beq 0x237a64 <_ZN14CPhysicsObject10SetDensityEif+0x4c>
 *   @0x237a40 ldr r12, [r3, #0x8]
 *   @0x237a44 cmp r1, r12
 *   @0x237a48 bne 0x237a34 <_ZN14CPhysicsObject10SetDensityEif+0x1c>
 *   @0x237a4c ldr r3, [r3, #0xc]
 *   @0x237a50 cmp r3, #0
 *   @0x237a54 bxeq lr
 *   @0x237a58 str r2, [r3]
 *   @0x237a5c ldr r0, [r0]
 *   @0x237a60 b 0x2c6c00 <_ZN6b2Body13ResetMassDataEv>
 *   @0x237a64 bx lr
 *
 * ══ §253/373 CPhysicsWorld::DebugRender(unsigned int)  0x238438  size 80  20 条（0x238438..0x238488）
 * @func 0x238438 0x238488  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Draw::SetFlags(unsigned int) / b2World::DrawDebugData()
 * 字段偏移 top8: 0x50×2 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x238438 and r3, r1, #1
 *   @0x23843c tst r1, #2
 *   @0x238440 orrne r3, r3, #2
 *   @0x238444 tst r1, #4
 *   @0x238448 orrne r3, r3, #16
 *   @0x23844c tst r1, #8
 *   @0x238450 orrne r3, r3, #4
 *   @0x238454 tst r1, #64
 *   @0x238458 orrne r3, r3, #8
 *   @0x23845c push {r4, lr}
 *   @0x238460 mov r1, r3
 *   @0x238464 mov r4, r0
 *   @0x238468 ldr r0, [r0, #0x50]
 *   @0x23846c bl 0x2c67d8 <_ZN6b2Draw8SetFlagsEj>
 *   @0x238470 ldr r0, [r4, #0x10]
 *   @0x238474 bl 0x2cad9c <_ZN7b2World13DrawDebugDataEv>
 *   @0x238478 ldr r0, [r4, #0x50]
 *   @0x23847c mov r1, #0
 *   @0x238480 pop {r4, lr}
 *   @0x238484 b 0x2c67d8 <_ZN6b2Draw8SetFlagsEj>
 *
 * ══ §254/373 C_UTF16String::~C_UTF16String()  0x23c790  size 80  20 条（0x23c790..0x23c7e0）
 * @func 0x23c790 0x23c7e0  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*) / operator delete(void*)
 * 字段偏移 top8: 0x4×1 / 0x34×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23c790 push {r4, lr}
 *   @0x23c794 mov r4, r0
 *   @0x23c798 ldr r0, [r0, #0x4]
 *   @0x23c79c ldr r3, [pc, #0x34]
 *   @0x23c7a0 cmp r0, #0
 *   @0x23c7a4 ldr r3, [pc, r3]
 *   @0x23c7a8 add r3, r3, #8
 *   @0x23c7ac str r3, [r4]
 *   @0x23c7b0 beq 0x23c7b8 <_ZN13C_UTF16StringD0Ev+0x28>
 *   @0x23c7b4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x23c7b8 ldr r3, [pc, #0x1c]
 *   @0x23c7bc mov r0, r4
 *   @0x23c7c0 ldr r3, [pc, r3]
 *   @0x23c7c4 add r3, r3, #8
 *   @0x23c7c8 str r3, [r4]
 *   @0x23c7cc bl 0x27d1d0 <_ZdlPv>
 *   @0x23c7d0 mov r0, r4
 *   @0x23c7d4 pop {r4, pc}
 *   @0x23c7d8 andseq r4, r11, r4, asr sp
 *   @0x23c7dc andseq r4, r11, r0, lsr sp
 *
 * ══ §255/373 F_JSErrorCall(RValue&, CInstance*, CInstance*, int, RValue*)  0x243fa4  size 80  20 条（0x243fa4..0x243ff4）
 * @func 0x243fa4 0x244008  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: NativeErrorCall(char const*, YYObjectBase*, RValue&, CInstance*, CInstance*, int, RValue*)
 * 字段偏移 top8: 0x38×1 / 0x20×1 / 0x28×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x243fa4 push {r4, r5, lr}
 *   @0x243fa8 sub sp, sp, #20
 *   @0x243fac ldr r12, [pc, #0x38]
 *   @0x243fb0 mov r4, r0
 *   @0x243fb4 ldr lr, [sp, #0x20]
 *   @0x243fb8 mov r5, r1
 *   @0x243fbc ldr r12, [pc, r12]
 *   @0x243fc0 ldr r0, [pc, #0x28]
 *   @0x243fc4 ldr r1, [r12]
 *   @0x243fc8 add r0, pc, r0
 *   @0x243fcc str r2, [sp]
 *   @0x243fd0 mov r2, r4
 *   @0x243fd4 str r3, [sp, #0x4]
 *   @0x243fd8 mov r3, r5
 *   @0x243fdc str lr, [sp, #0x8]
 *   @0x243fe0 bl 0x243de0 <_Z15NativeErrorCallPKcP12YYObjectBaseR6RValueP9CInstanceS6_iPS3_>
 *   @0x243fe4 add sp, sp, #20
 *   @0x243fe8 pop {r4, r5, pc}
 *   @0x243fec andseq sp, r10, r12, lsl #14
 *   @0x243ff0 andseq r1, r1, r12, asr r9
 *
 * ══ §256/373 F_JSEvalErrorCall(RValue&, CInstance*, CInstance*, int, RValue*)  0x243ff4  size 80  20 条（0x243ff4..0x244044）
 * @func 0x243ff4 0x244058  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: NativeErrorCall(char const*, YYObjectBase*, RValue&, CInstance*, CInstance*, int, RValue*)
 * 字段偏移 top8: 0x38×1 / 0x20×1 / 0x28×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x243ff4 push {r4, r5, lr}
 *   @0x243ff8 sub sp, sp, #20
 *   @0x243ffc ldr r12, [pc, #0x38]
 *   @0x244000 mov r4, r0
 *   @0x244004 ldr lr, [sp, #0x20]
 *   @0x244008 mov r5, r1
 *   @0x24400c ldr r12, [pc, r12]
 *   @0x244010 ldr r0, [pc, #0x28]
 *   @0x244014 ldr r1, [r12]
 *   @0x244018 add r0, pc, r0
 *   @0x24401c str r2, [sp]
 *   @0x244020 mov r2, r4
 *   @0x244024 str r3, [sp, #0x4]
 *   @0x244028 mov r3, r5
 *   @0x24402c str lr, [sp, #0x8]
 *   @0x244030 bl 0x243de0 <_Z15NativeErrorCallPKcP12YYObjectBaseR6RValueP9CInstanceS6_iPS3_>
 *   @0x244034 add sp, sp, #20
 *   @0x244038 pop {r4, r5, pc}
 *   @0x24403c andseq sp, r10, r0, asr #13
 *   @0x244040 andseq r1, r1, r0, lsr #18
 *
 * ══ §257/373 F_JSRangeErrorCall(RValue&, CInstance*, CInstance*, int, RValue*)  0x244044  size 80  20 条（0x244044..0x244094）
 * @func 0x244044 0x244094  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: NativeErrorCall(char const*, YYObjectBase*, RValue&, CInstance*, CInstance*, int, RValue*)
 * 字段偏移 top8: 0x38×1 / 0x20×1 / 0x28×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x244044 push {r4, r5, lr}
 *   @0x244048 sub sp, sp, #20
 *   @0x24404c ldr r12, [pc, #0x38]
 *   @0x244050 mov r4, r0
 *   @0x244054 ldr lr, [sp, #0x20]
 *   @0x244058 mov r5, r1
 *   @0x24405c ldr r12, [pc, r12]
 *   @0x244060 ldr r0, [pc, #0x28]
 *   @0x244064 ldr r1, [r12]
 *   @0x244068 add r0, pc, r0
 *   @0x24406c str r2, [sp]
 *   @0x244070 mov r2, r4
 *   @0x244074 str r3, [sp, #0x4]
 *   @0x244078 mov r3, r5
 *   @0x24407c str lr, [sp, #0x8]
 *   @0x244080 bl 0x243de0 <_Z15NativeErrorCallPKcP12YYObjectBaseR6RValueP9CInstanceS6_iPS3_>
 *   @0x244084 add sp, sp, #20
 *   @0x244088 pop {r4, r5, pc}
 *   @0x24408c andseq sp, r10, r4, ror r6
 *   @0x244090 ldrsbeq r1, [r1], -r12
 *
 * ══ §258/373 F_JSSyntaxErrorCall(RValue&, CInstance*, CInstance*, int, RValue*)  0x2440e4  size 80  20 条（0x2440e4..0x244134）
 * @func 0x2440e4 0x244134  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: NativeErrorCall(char const*, YYObjectBase*, RValue&, CInstance*, CInstance*, int, RValue*)
 * 字段偏移 top8: 0x38×1 / 0x20×1 / 0x28×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2440e4 push {r4, r5, lr}
 *   @0x2440e8 sub sp, sp, #20
 *   @0x2440ec ldr r12, [pc, #0x38]
 *   @0x2440f0 mov r4, r0
 *   @0x2440f4 ldr lr, [sp, #0x20]
 *   @0x2440f8 mov r5, r1
 *   @0x2440fc ldr r12, [pc, r12]
 *   @0x244100 ldr r0, [pc, #0x28]
 *   @0x244104 ldr r1, [r12]
 *   @0x244108 add r0, pc, r0
 *   @0x24410c str r2, [sp]
 *   @0x244110 mov r2, r4
 *   @0x244114 str r3, [sp, #0x4]
 *   @0x244118 mov r3, r5
 *   @0x24411c str lr, [sp, #0x8]
 *   @0x244120 bl 0x243de0 <_Z15NativeErrorCallPKcP12YYObjectBaseR6RValueP9CInstanceS6_iPS3_>
 *   @0x244124 add sp, sp, #20
 *   @0x244128 pop {r4, r5, pc}
 *   @0x24412c ldrsbeq sp, [r10], -r12
 *   @0x244130 andseq r1, r1, r8, asr r8
 *
 * ══ §259/373 F_JSURIErrorCall(RValue&, CInstance*, CInstance*, int, RValue*)  0x244184  size 80  20 条（0x244184..0x2441d4）
 * @func 0x244184 0x2441d4  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: NativeErrorCall(char const*, YYObjectBase*, RValue&, CInstance*, CInstance*, int, RValue*)
 * 字段偏移 top8: 0x38×1 / 0x20×1 / 0x28×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x244184 push {r4, r5, lr}
 *   @0x244188 sub sp, sp, #20
 *   @0x24418c ldr r12, [pc, #0x38]
 *   @0x244190 mov r4, r0
 *   @0x244194 ldr lr, [sp, #0x20]
 *   @0x244198 mov r5, r1
 *   @0x24419c ldr r12, [pc, r12]
 *   @0x2441a0 ldr r0, [pc, #0x28]
 *   @0x2441a4 ldr r1, [r12]
 *   @0x2441a8 add r0, pc, r0
 *   @0x2441ac str r2, [sp]
 *   @0x2441b0 mov r2, r4
 *   @0x2441b4 str r3, [sp, #0x4]
 *   @0x2441b8 mov r3, r5
 *   @0x2441bc str lr, [sp, #0x8]
 *   @0x2441c0 bl 0x243de0 <_Z15NativeErrorCallPKcP12YYObjectBaseR6RValueP9CInstanceS6_iPS3_>
 *   @0x2441c4 add sp, sp, #20
 *   @0x2441c8 pop {r4, r5, pc}
 *   @0x2441cc andseq sp, r10, r4, asr #10
 *   @0x2441d0 ldrsbeq r1, [r1], -r0
 *
 * ══ §260/373 json_object_new_string_len  0x27ed08  size 80  20 条（0x27ed08..0x27ed58）
 * @func 0x27ed08 0x27ed58  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_27e408+0x31c / 0xb6d0c
 * 字段偏移 top8: 0x24×1 / 0x20×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27ed08 push {r4, r5, r6, lr}
 *   @0x27ed0c mov r5, r0
 *   @0x27ed10 mov r0, #6
 *   @0x27ed14 mov r6, r1
 *   @0x27ed18 bl 0x27e724 <mc_info+0x35c>
 *   @0x27ed1c subs r4, r0, #0
 *   @0x27ed20 beq 0x27ed48 <json_object_new_string_len+0x40>
 *   @0x27ed24 ldr r2, [pc, #0x24]
 *   @0x27ed28 mov r0, r5
 *   @0x27ed2c ldr r3, [pc, #0x20]
 *   @0x27ed30 mov r1, r6
 *   @0x27ed34 add r2, pc, r2
 *   @0x27ed38 add r3, pc, r3
 *   @0x27ed3c stmib r4, {r2, r3}
 *   @0x27ed40 bl 0xb6d0c <strndup@plt>
 *   @0x27ed44 str r0, [r4, #0x18]
 *   @0x27ed48 mov r0, r4
 *   @0x27ed4c pop {r4, r5, r6, pc}
 *   @0x27ed50 .word 0xfffff9c4
 *   @0x27ed54 .word 0xfffff93c
 *
 * ══ §261/373 spAnimation_dispose  0x28147c  size 80  20 条（0x28147c..0x2814cc）
 * @func 0x28147c 0x2814cc  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _free×2 / spAnimation_dispose+0x34 / spTimeline_dispose
 * 字段偏移 top8: 0x8×2 / 0xc×2 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28147c push {r3, r4, r5, lr}
 *   @0x281480 mov r5, r0
 *   @0x281484 ldr r3, [r0, #0x8]
 *   @0x281488 cmp r3, #0
 *   @0x28148c movgt r4, #0
 *   @0x281490 ble 0x2814b0 <spAnimation_dispose+0x34>
 *   @0x281494 ldr r3, [r5, #0xc]
 *   @0x281498 ldr r0, [r3, r4, lsl #2]
 *   @0x28149c add r4, r4, #1
 *   @0x2814a0 bl 0x281468 <spTimeline_dispose>
 *   @0x2814a4 ldr r3, [r5, #0x8]
 *   @0x2814a8 cmp r3, r4
 *   @0x2814ac bgt 0x281494 <spAnimation_dispose+0x18>
 *   @0x2814b0 ldr r0, [r5, #0xc]
 *   @0x2814b4 bl 0x285c80 <_free>
 *   @0x2814b8 ldr r0, [r5]
 *   @0x2814bc bl 0x285c80 <_free>
 *   @0x2814c0 mov r0, r5
 *   @0x2814c4 pop {r3, r4, r5, lr}
 *   @0x2814c8 b 0x285c80 <_free>
 *
 * ══ §262/373 spBone_getWorldScaleX  0x285488  size 80  20 条（0x285488..0x2854d8）
 * @func 0x285488 0x2854ec  size 100  25 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66f4
 * 字段偏移 top8: 无
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x285488 vldr s12, [r0, #56]
 *   @0x28548c vmul.f32 s12, s12, s12
 *   @0x285490 vldr s15, [r0, #52]
 *   @0x285494 push {r4, lr}
 *   @0x285498 mov r4, r0
 *   @0x28549c vmla.f32 s12, s15, s15
 *   @0x2854a0 vcvt.f64.f32 d6, s12
 *   @0x2854a4 vsqrt.f64 d7, d6
 *   @0x2854a8 vcmp.f64 d7, d7
 *   @0x2854ac vmrs APSR_nzcv, fpscr
 *   @0x2854b0 bne 0x2854c8 <spBone_getWorldScaleX+0x40>
 *   @0x2854b4 vcvt.f32.f64 s14, d7
 *   @0x2854b8 vldr s15, [r4, #76]
 *   @0x2854bc vmul.f32 s15, s14, s15
 *   @0x2854c0 vmov r0, s15
 *   @0x2854c4 pop {r4, pc}
 *   @0x2854c8 vmov r0, r1, d6
 *   @0x2854cc bl 0xb66f4 <sqrt@plt>
 *   @0x2854d0 vmov d7, r0, r1
 *   @0x2854d4 b 0x2854b4 <spBone_getWorldScaleX+0x2c>
 *
 * ══ §263/373 spBone_getWorldScaleY  0x2854d8  size 80  20 条（0x2854d8..0x285528）
 * @func 0x2854d8 0x285528  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66f4
 * 字段偏移 top8: 无
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2854d8 vldr s12, [r0, #68]
 *   @0x2854dc vmul.f32 s12, s12, s12
 *   @0x2854e0 vldr s15, [r0, #64]
 *   @0x2854e4 push {r4, lr}
 *   @0x2854e8 mov r4, r0
 *   @0x2854ec vmla.f32 s12, s15, s15
 *   @0x2854f0 vcvt.f64.f32 d6, s12
 *   @0x2854f4 vsqrt.f64 d7, d6
 *   @0x2854f8 vcmp.f64 d7, d7
 *   @0x2854fc vmrs APSR_nzcv, fpscr
 *   @0x285500 bne 0x285518 <spBone_getWorldScaleY+0x40>
 *   @0x285504 vcvt.f32.f64 s14, d7
 *   @0x285508 vldr s15, [r4, #80]
 *   @0x28550c vmul.f32 s15, s14, s15
 *   @0x285510 vmov r0, s15
 *   @0x285514 pop {r4, pc}
 *   @0x285518 vmov r0, r1, d6
 *   @0x28551c bl 0xb66f4 <sqrt@plt>
 *   @0x285520 vmov d7, r0, r1
 *   @0x285524 b 0x285504 <spBone_getWorldScaleY+0x2c>
 *
 * ══ §264/373 spSlotData_setAttachmentName  0x28efcc  size 80  20 条（0x28efcc..0x28f01c）
 * @func 0x28efcc 0x28f01c  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _free / 0xb6538 / _malloc
 * 字段偏移 top8: 0xc×2 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28efcc push {r3, r4, r5, lr}
 *   @0x28efd0 mov r5, r0
 *   @0x28efd4 ldr r0, [r0, #0xc]
 *   @0x28efd8 mov r4, r1
 *   @0x28efdc bl 0x285c80 <_free>
 *   @0x28efe0 cmp r4, #0
 *   @0x28efe4 streq r4, [r5, #0xc]
 *   @0x28efe8 popeq {r3, r4, r5, pc}
 *   @0x28efec mov r0, r4
 *   @0x28eff0 bl 0xb6538 <strlen@plt>
 *   @0x28eff4 ldr r1, [pc, #0x1c]
 *   @0x28eff8 mov r2, #56
 *   @0x28effc add r1, pc, r1
 *   @0x28f000 add r0, r0, #1
 *   @0x28f004 bl 0x285c10 <_malloc>
 *   @0x28f008 mov r1, r4
 *   @0x28f00c str r0, [r5, #0xc]
 *   @0x28f010 pop {r3, r4, r5, lr}
 *   @0x28f014 b 0xb65a4 <strcpy@plt>
 *   @0x28f018 strdeq r8, r9, [r12], -r4
 *
 * ══ §265/373 yySocket::Accept()  0x29528c  size 80  20 条（0x29528c..0x2952dc）
 * @func 0x29528c 0x2952dc  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6de4 / yySocket::DumpError()
 * 字段偏移 top8: 0x4×4 / 0xc4×1 / 0x-4×1 / 0x10×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29528c ldrb r3, [r0, #0xc4]
 *   @0x295290 mov r1, r0
 *   @0x295294 str lr, [sp, #-0x4]!
 *   @0x295298 cmp r3, #0
 *   @0x29529c add r2, r0, #16
 *   @0x2952a0 sub sp, sp, #12
 *   @0x2952a4 movne r3, #28
 *   @0x2952a8 moveq r3, #16
 *   @0x2952ac str r3, [r0, #0x10]
 *   @0x2952b0 ldr r0, [r1], #24
 *   @0x2952b4 bl 0xb6de4 <accept@plt>
 *   @0x2952b8 cmn r0, #1
 *   @0x2952bc beq 0x2952c8 <_ZN8yySocket6AcceptEv+0x3c>
 *   @0x2952c0 add sp, sp, #12
 *   @0x2952c4 ldr pc, [sp], #4
 *   @0x2952c8 str r0, [sp, #0x4]
 *   @0x2952cc bl 0x294d24 <_ZN8yySocket9DumpErrorEv>
 *   @0x2952d0 ldr r0, [sp, #0x4]
 *   @0x2952d4 add sp, sp, #12
 *   @0x2952d8 ldr pc, [sp], #4
 *
 * ══ §266/373 F_NETWORK_Resolve(RValue&, CInstance*, CInstance*, int, RValue*)  0x29807c  size 80  20 条（0x29807c..0x2980cc）
 * @func 0x29807c 0x2980cc  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: yySocket::Startup() / YYGetString(RValue const*, int) / yySocket::ResolveToString(char*)
 * 字段偏移 top8: 0x3c×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29807c push {r4, r5, r6, lr}
 *   @0x298080 mov r5, r0
 *   @0x298084 ldr r4, [pc, #0x3c]
 *   @0x298088 ldr r6, [sp, #0x10]
 *   @0x29808c ldr r4, [pc, r4]
 *   @0x298090 ldrb r3, [r4]
 *   @0x298094 cmp r3, #0
 *   @0x298098 bne 0x2980a8 <_Z17F_NETWORK_ResolveR6RValueP9CInstanceS2_iPS_+0x2c>
 *   @0x29809c bl 0x294d18 <_ZN8yySocket7StartupEv>
 *   @0x2980a0 mov r3, #1
 *   @0x2980a4 strb r3, [r4]
 *   @0x2980a8 mov r1, #0
 *   @0x2980ac mov r0, r6
 *   @0x2980b0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x2980b4 bl 0x2957c0 <_ZN8yySocket15ResolveToStringEPc>
 *   @0x2980b8 mov r1, r0
 *   @0x2980bc mov r0, r5
 *   @0x2980c0 pop {r4, r5, r6, lr}
 *   @0x2980c4 b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x2980c8 andseq r9, r5, r0, lsl r9
 *
 * ══ §267/373 png_check_chunk_name  0x2adb74  size 80  20 条（0x2adb74..0x2adbc4）
 * @func 0x2adb74 0x2adbc4  size 80  20 条
 * 部分覆盖: 本节 20/38 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1×1 / 0x2×1 / 0x3×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2adb74 ldrb r3, [r1]
 *   @0x2adb78 bhs 0x10ee484 <b2_toiTime+0x994fe0>
 *   @0x2adb7c bhi 0x2adbb4 <png_check_chunk_name+0x40>
 *   @0x2adb80 cmp r3, #0x5
 *   @0x2adb84 ldrb r3, [r1, #0x1]
 *   @0x2adb88 bhs 0x10ee494 <b2_toiTime+0x994ff0>
 *   @0x2adb8c bhi 0x2adbb4 <png_check_chunk_name+0x40>
 *   @0x2adb90 cmp r3, #0x5
 *   @0x2adb94 ldrb r3, [r1, #0x2]
 *   @0x2adb98 bhs 0x10ee4a4 <b2_toiTime+0x995000>
 *   @0x2adb9c bhi 0x2adbb4 <png_check_chunk_name+0x40>
 *   @0x2adba0 cmp r3, #0x5
 *   @0x2adba4 ldrb r3, [r1, #0x3]
 *   @0x2adba8 bhs 0x10ee4b4 <b2_toiTime+0x995010>
 *   @0x2adbac bhi 0x2adbb4 <png_check_chunk_name+0x40>
 *   @0x2adbb0 cmp r3, #0x5
 *   @0x2adbb4 ldr r1, [pc, #0x8]
 *   @0x2adbb8 b.w 0x2a64cc <png_chunk_error>
 *   @0x2adbbc bx lr
 *   @0x2adbc0 cdp2 p0, #0x3, c0, c3, c13, #0x0
 *
 * ══ §268/373 b2ParticleColor::b2ParticleColor(b2Color const&)  0x2d4478  size 80  20 条（0x2d4478..0x2d44c8）
 * @func 0x2d4478 0x2d44c8  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1×1 / 0x3×1 / 0x2×1
 * VFP 指令 13 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d4478 vldr s14, [r1]
 *   @0x2d447c vldr s15, [pc, #64]
 *   @0x2d4480 vmul.f32 s14, s14, s15
 *   @0x2d4484 mvn r2, #0
 *   @0x2d4488 vcvt.s32.f32 s14, s14
 *   @0x2d448c vmov r12, s14
 *   @0x2d4490 strb r12, [r0]
 *   @0x2d4494 vldr s14, [r1, #4]
 *   @0x2d4498 vmul.f32 s14, s14, s15
 *   @0x2d449c vcvt.s32.f32 s14, s14
 *   @0x2d44a0 vmov r12, s14
 *   @0x2d44a4 strb r12, [r0, #0x1]
 *   @0x2d44a8 vldr s14, [r1, #8]
 *   @0x2d44ac vmul.f32 s15, s14, s15
 *   @0x2d44b0 strb r2, [r0, #0x3]
 *   @0x2d44b4 vcvt.s32.f32 s15, s15
 *   @0x2d44b8 vmov r2, s15
 *   @0x2d44bc strb r2, [r0, #0x2]
 *   @0x2d44c0 bx lr
 *   @0x2d44c4 cmnmi pc, #0
 *
 * ══ §269/373 b2ParticleColor::Set(b2Color const&)  0x2d4510  size 80  20 条（0x2d4510..0x2d4560）
 * @func 0x2d4510 0x2d4560  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1×1 / 0x3×1 / 0x2×1
 * VFP 指令 13 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d4510 vldr s14, [r1]
 *   @0x2d4514 vldr s15, [pc, #64]
 *   @0x2d4518 vmul.f32 s14, s14, s15
 *   @0x2d451c mvn r3, #0
 *   @0x2d4520 vcvt.s32.f32 s14, s14
 *   @0x2d4524 vmov r2, s14
 *   @0x2d4528 strb r2, [r0]
 *   @0x2d452c vldr s14, [r1, #4]
 *   @0x2d4530 vmul.f32 s14, s14, s15
 *   @0x2d4534 vcvt.s32.f32 s14, s14
 *   @0x2d4538 vmov r2, s14
 *   @0x2d453c strb r2, [r0, #0x1]
 *   @0x2d4540 vldr s14, [r1, #8]
 *   @0x2d4544 vmul.f32 s15, s14, s15
 *   @0x2d4548 strb r3, [r0, #0x3]
 *   @0x2d454c vcvt.s32.f32 s15, s15
 *   @0x2d4550 vmov r3, s15
 *   @0x2d4554 strb r3, [r0, #0x2]
 *   @0x2d4558 bx lr
 *   @0x2d455c cmnmi pc, #0
 *
 * ══ §270/373 __cxa_begin_cleanup  0x318628  size 80  20 条（0x318628..0x318678）
 * @func 0x318628 0x318678  size 80  20 条
 * 部分覆盖: 本节 20/34 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_317210+0x2d0 / 0x3676c0
 * 字段偏移 top8: 0x-18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x318628 push {r4, r5, r6, lr}
 *   @0x31862c bl 0x3174e0 <ft_lzwstate_io+0x52c>
 *   @0x318630 ldrd r4, r5, [r6]
 *   @0x318634 sub.w r1, r6, #0x38
 *   @0x318638 adr r3, #52 <__cxa_begin_cleanup+0x21>
 *   @0x31863c rsbmi r2, r2, r0, lsl #6
 *   @0x318640 eors r3, r5
 *   @0x318644 svclt #0x180403
 *   @0x318648 strne r1, [r0, #0x8]
 *   @0x31864c movs r0, #0x1
 *   @0x318650 ldr r3, [r6, #-24]
 *   @0x318654 adds r3, #0x1
 *   @0x318658 blhs 0x3676c0 <_ZTS12CDS_Priority+0x9718>
 *   @0x31865c ittt eq
 *   @0x318660 streq r3, [r6, #-28]
 *   @0x318664 streq r1, [r0, #0x8]
 *   @0x318668 pop {r4, r5, r6, pc}
 *   @0x31866c nop.w
 *   @0x318670 cmp r3, #0x0
 *   @0x318674 strb r3, [r0, r5]
 *
 * ══ §271/373 _zip_cdir_new(int, zip_error*)  0x2a3b88  size 78  20 条（0x2a3b88..0x2a3bd6）
 * @func 0x2a3b88 0x2a3bd8  size 80  20 条
 * 部分覆盖: 本节 20/37 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6544×2 / _zip_error_set(zip_error*, int, int)
 * 字段偏移 top8: 0x4×1 / 0x8×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a3b88 push {r3, r4, r5, r6, r7, lr}
 *   @0x2a3b8c movs r0, #0x18
 *   @0x2a3b90 blx 0xb6544 <malloc@plt>
 *   @0x2a3b94 mov r4, r0
 *   @0x2a3b98 mov r0, r7
 *   @0x2a3b9c mov r2, r4
 *   @0x2a3ba0 ldrsb pc, [r6], -r11
 *   @0x2a3ba4 movs r0, #0x3c
 *   @0x2a3ba8 blx 0xb6544 <malloc@plt>
 *   @0x2a3bac mov r5, r0
 *   @0x2a3bb0 cbnz r0, 0x2a3bc6 <_Z13_zip_cdir_newiP9zip_error+0x3e>
 *   @0x2a3bb4 movs r1, #0xe
 *   @0x2a3bb8 bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii>
 *   @0x2a3bbc mov r0, r4
 *   @0x2a3bc0 strtmi lr, [r8], -lr, asr #25
 *   @0x2a3bc4 pop {r3, r4, r5, r6, r7, pc}
 *   @0x2a3bc8 str r6, [r4, #0x4]
 *   @0x2a3bcc str r3, [r4, #0x8]
 *   @0x2a3bd0 strh r3, [r4, #0x14]
 *   @0x2a3bd4 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §272/373 png_get_tRNS  0x2a6b56  size 78  20 条（0x2a6b56..0x2a6ba4）
 * @func 0x2a6b56 0x2a6ba6  size 80  20 条
 * 部分覆盖: 本节 20/39 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1 / 0x19×1 / 0x4c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6b56 push {r4, lr}
 *   @0x2a6b5a cbz r0, 0x2a6ba2 <png_get_tRNS+0x4c>
 *   @0x2a6b5e ldr r0, [r1, #0x8]
 *   @0x2a6b62 andsle r0, sp, r0, lsl r0
 *   @0x2a6b66 ldrb r0, [r1, #0x19]
 *   @0x2a6b6a bne 0x2a6b82 <png_get_tRNS+0x2c>
 *   @0x2a6b6e ldr r0, [r1, #0x4c]
 *   @0x2a6b72 movs r0, #0x10
 *   @0x2a6b76 mov r0, r2
 *   @0x2a6b7a add.w r2, r1, #0x50
 *   @0x2a6b7e str r2, [r4]
 *   @0x2a6b82 cbz r4, 0x2a6b8e <png_get_tRNS+0x38>
 *   @0x2a6b86 eorvs r0, r0, r0, asr r0
 *   @0x2a6b8a movs r0, #0x10
 *   @0x2a6b8e mov r0, r4
 *   @0x2a6b92 movs r4, #0x0
 *   @0x2a6b96 cbz r3, 0x2a6ba2 <png_get_tRNS+0x4c>
 *   @0x2a6b9a movs r0, #0x10
 *   @0x2a6b9e pop {r4, pc}
 *   @0x2a6ba2 pop {r4, pc}
 *
 * ══ §273/373 FT_Outline_Check  0x2e631e  size 78  20 条（0x2e631e..0x2e636c）
 * @func 0x2e631e 0x2e636e  size 80  20 条
 * 部分覆盖: 本节 20/36 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e631e push {r4, r5, lr}
 *   @0x2e6322 ldrsh.w r1, [r0, #0x2]
 *   @0x2e6326 ldrsh.w r4, [r0]
 *   @0x2e632a cmp r1, #0x0
 *   @0x2e632e cmp r4, #0x0
 *   @0x2e6332 movne r0, #0x6
 *   @0x2e6336 pop {r4, r5, pc}
 *   @0x2e633a cmp r4, #0x0
 *   @0x2e633e ldr r5, [r0, #0xc]
 *   @0x2e6342 mov.w r0, #0xffffffff
 *   @0x2e6346 ldrsh.w r3, [r5, r2, lsl #1]
 *   @0x2e634a cmp r3, r0
 *   @0x2e634e cmp r3, r1
 *   @0x2e6352 adds r2, #0x1
 *   @0x2e6356 bge 0x2e635c <FT_Outline_Check+0x3e>
 *   @0x2e635a b 0x2e6346 <FT_Outline_Check+0x28>
 *   @0x2e635e cmp r3, r0
 *   @0x2e6362 movne r0, #0x6
 *   @0x2e6366 pop {r4, r5, pc}
 *   @0x2e636a pop {r4, r5, pc}
 *
 * ══ §274/373 Buffer_Fast::Peek(int, eBuffer_Type, RValue*)  0xc4c7c  size 76  19 条（0xc4c7c..0xc4cc8）
 * @func 0xc4c7c 0xc4cc8  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×2 / 0x4×1 / 0x10×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc4c7c cmp r2, #1
 *   @0xc4c80 mov r12, r3
 *   @0xc4c84 mov r3, #0
 *   @0xc4c88 str r3, [r12, #0xc]
 *   @0xc4c8c str r3, [r12]
 *   @0xc4c90 str r3, [r12, #0x4]
 *   @0xc4c94 bxne lr
 *   @0xc4c98 cmp r1, r3
 *   @0xc4c9c bxlt lr
 *   @0xc4ca0 ldr r3, [r0, #0x10]
 *   @0xc4ca4 cmp r1, r3
 *   @0xc4ca8 bxge lr
 *   @0xc4cac ldr r3, [r0, #0xc]
 *   @0xc4cb0 ldrb r2, [r3, r1]
 *   @0xc4cb4 vmov s15, r2
 *   @0xc4cb8 vcvt.f64.u32 d7, s15
 *   @0xc4cbc vmov r2, r3, d7
 *   @0xc4cc0 stm r12, {r2, r3}
 *   @0xc4cc4 bx lr
 *
 * ══ §275/373 CExtensionConstant::Assign(CExtensionConstant*)  0xf482c  size 76  19 条（0xf482c..0xf4878）
 * @func 0xf482c 0xf4878  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYFree(void const*)×2 / YYStrDup(char const*)×2
 * 字段偏移 top8: 0x4×3 / 0x8×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf482c push {r3, r4, r5, lr}
 *   @0xf4830 mov r4, r0
 *   @0xf4834 ldr r0, [r0, #0x4]
 *   @0xf4838 mov r5, r1
 *   @0xf483c cmp r0, #0
 *   @0xf4840 beq 0xf4848 <_ZN18CExtensionConstant6AssignEPS_+0x1c>
 *   @0xf4844 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xf4848 ldr r0, [r5, #0x4]
 *   @0xf484c bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xf4850 ldr r3, [r4, #0x8]
 *   @0xf4854 cmp r3, #0
 *   @0xf4858 str r0, [r4, #0x4]
 *   @0xf485c beq 0xf4868 <_ZN18CExtensionConstant6AssignEPS_+0x3c>
 *   @0xf4860 mov r0, r3
 *   @0xf4864 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xf4868 ldr r0, [r5, #0x8]
 *   @0xf486c bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xf4870 str r0, [r4, #0x8]
 *   @0xf4874 pop {r3, r4, r5, pc}
 *
 * ══ §276/373 CExtensionFunction::Clear()  0xf4998  size 76  19 条（0xf4998..0xf49e4）
 * @func 0xf4998 0xf49e4  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x-4×1 / 0x14×1 / 0x8×1 / 0xc×1 / 0x18×1 / 0x58×1 / 0x5c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf4998 mov r3, #16
 *   @0xf499c mov r2, r0
 *   @0xf49a0 mov r12, #2
 *   @0xf49a4 mov r1, #0
 *   @0xf49a8 str r4, [sp, #-0x4]!
 *   @0xf49ac mvn r4, #0
 *   @0xf49b0 str r1, [r0, #0x4]
 *   @0xf49b4 str r4, [r0, #0x14]
 *   @0xf49b8 str r1, [r0, #0x8]
 *   @0xf49bc str r1, [r0, #0xc]
 *   @0xf49c0 subs r3, r3, #1
 *   @0xf49c4 str r12, [r2, #0x18]
 *   @0xf49c8 mov r1, #2
 *   @0xf49cc add r2, r2, #4
 *   @0xf49d0 bne 0xf49c0 <_ZN18CExtensionFunction5ClearEv+0x28>
 *   @0xf49d4 str r1, [r0, #0x58]
 *   @0xf49d8 str r3, [r0, #0x5c]
 *   @0xf49dc ldr r4, [sp], #4
 *   @0xf49e0 bx lr
 *
 * ══ §277/373 CExtensionFile::CExtensionFile()  0xf5098  size 76  19 条（0xf5098..0xf50e4）
 * @func 0xf5098 0xf50e4  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CExtensionFile::Clear()
 * 字段偏移 top8: 0x40×1 / 0x18×1 / 0x14×1 / 0x1c×1 / 0x24×1 / 0x20×1 / 0x28×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf5098 ldr r2, [pc, #0x40]
 *   @0xf509c mov r3, #0
 *   @0xf50a0 push {r4, lr}
 *   @0xf50a4 ldr r2, [pc, r2]
 *   @0xf50a8 mov r4, r0
 *   @0xf50ac str r3, [r0, #0x18]
 *   @0xf50b0 str r3, [r0, #0x14]
 *   @0xf50b4 add r2, r2, #8
 *   @0xf50b8 str r3, [r0, #0x1c]
 *   @0xf50bc str r2, [r0]
 *   @0xf50c0 str r3, [r0, #0x24]
 *   @0xf50c4 str r3, [r0, #0x20]
 *   @0xf50c8 str r3, [r0, #0x28]
 *   @0xf50cc str r3, [r0, #0x10]
 *   @0xf50d0 str r3, [r0, #0xc]
 *   @0xf50d4 bl 0xf5064 <_ZN14CExtensionFile5ClearEv>
 *   @0xf50d8 mov r0, r4
 *   @0xf50dc pop {r4, pc}
 *   @0xf50e0 eoreq r8, pc, r8, lsl #27
 *
 * ══ §278/373 CExtensionPackage::FunctionFindId(int)  0xf54e0  size 76  19 条（0xf54e0..0xf552c）
 * @func 0xf54e0 0xf5540  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CExtensionPackage::FunctionFindId(int)+0x44 / CExtensionFile::FunctionFindId(int)
 * 字段偏移 top8: 0x18×2 / 0x14×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf54e0 ldr r3, [r0, #0x18]
 *   @0xf54e4 push {r4, r5, r6, lr}
 *   @0xf54e8 cmp r3, #0
 *   @0xf54ec mov r5, r0
 *   @0xf54f0 mov r6, r1
 *   @0xf54f4 movgt r4, #0
 *   @0xf54f8 ble 0xf5524 <_ZN17CExtensionPackage14FunctionFindIdEi+0x44>
 *   @0xf54fc ldr r3, [r5, #0x14]
 *   @0xf5500 mov r1, r6
 *   @0xf5504 ldr r0, [r3, r4, lsl #2]
 *   @0xf5508 add r4, r4, #1
 *   @0xf550c bl 0xf4ee0 <_ZN14CExtensionFile14FunctionFindIdEi>
 *   @0xf5510 cmp r0, #0
 *   @0xf5514 popne {r4, r5, r6, pc}
 *   @0xf5518 ldr r3, [r5, #0x18]
 *   @0xf551c cmp r3, r4
 *   @0xf5520 bgt 0xf54fc <_ZN17CExtensionPackage14FunctionFindIdEi+0x1c>
 *   @0xf5524 mov r0, #0
 *   @0xf5528 pop {r4, r5, r6, pc}
 *
 * ══ §279/373 CExtensionPackage::ConstantFindName(char const*)  0xf552c  size 76  19 条（0xf552c..0xf5578）
 * @func 0xf552c 0xf5578  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CExtensionPackage::ConstantFindName(char const*)+0x44 / CExtensionFile::ConstantFindName(char const*)
 * 字段偏移 top8: 0x18×2 / 0x14×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf552c ldr r3, [r0, #0x18]
 *   @0xf5530 push {r4, r5, r6, lr}
 *   @0xf5534 cmp r3, #0
 *   @0xf5538 mov r5, r0
 *   @0xf553c mov r6, r1
 *   @0xf5540 movgt r4, #0
 *   @0xf5544 ble 0xf5570 <_ZN17CExtensionPackage16ConstantFindNameEPKc+0x44>
 *   @0xf5548 ldr r3, [r5, #0x14]
 *   @0xf554c mov r1, r6
 *   @0xf5550 ldr r0, [r3, r4, lsl #2]
 *   @0xf5554 add r4, r4, #1
 *   @0xf5558 bl 0xf4f34 <_ZN14CExtensionFile16ConstantFindNameEPKc>
 *   @0xf555c cmp r0, #0
 *   @0xf5560 popne {r4, r5, r6, pc}
 *   @0xf5564 ldr r3, [r5, #0x18]
 *   @0xf5568 cmp r3, r4
 *   @0xf556c bgt 0xf5548 <_ZN17CExtensionPackage16ConstantFindNameEPKc+0x1c>
 *   @0xf5570 mov r0, #0
 *   @0xf5574 pop {r4, r5, r6, pc}
 *
 * ══ §280/373 F_Power(RValue&, CInstance*, CInstance*, int, RValue*)  0x10eb1c  size 76  19 条（0x10eb1c..0x10eb68）
 * @func 0x10eb1c 0x10eb68  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×2 / 0xb6784
 * 字段偏移 top8: 0x18×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10eb1c push {r3, r4, r5, r6, r7, lr}
 *   @0x10eb20 mov r1, #0
 *   @0x10eb24 ldr r7, [sp, #0x18]
 *   @0x10eb28 mov r6, r0
 *   @0x10eb2c str r1, [r0, #0xc]
 *   @0x10eb30 mov r0, r7
 *   @0x10eb34 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x10eb38 mov r4, r0
 *   @0x10eb3c mov r5, r1
 *   @0x10eb40 mov r0, r7
 *   @0x10eb44 mov r1, #1
 *   @0x10eb48 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x10eb4c mov r2, r0
 *   @0x10eb50 mov r3, r1
 *   @0x10eb54 mov r0, r4
 *   @0x10eb58 mov r1, r5
 *   @0x10eb5c bl 0xb6784 <pow@plt>
 *   @0x10eb60 stm r6, {r0, r1}
 *   @0x10eb64 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §281/373 YYGML_random_range(double, double)  0x110eb0  size 76  19 条（0x110eb0..0x110efc）
 * @func 0x110eb0 0x110efc  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: fYYRandom(double)
 * 字段偏移 top8: 无
 * VFP 指令 13 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x110eb0 vmov d7, r2, r3
 *   @0x110eb4 push {r3, lr}
 *   @0x110eb8 vpush {d8, d9}
 *   @0x110ebc vmov d8, r0, r1
 *   @0x110ec0 mov r0, #0
 *   @0x110ec4 mov r1, #0
 *   @0x110ec8 vcmpe.f64 d8, d7
 *   @0x110ecc movt r1, #0x3ff0
 *   @0x110ed0 vmrs APSR_nzcv, fpscr
 *   @0x110ed4 vsubpl.f64 d9, d8, d7
 *   @0x110ed8 vsubmi.f64 d9, d7, d8
 *   @0x110edc vmovpl.f64 d8, d7
 *   @0x110ee0 bl 0xc4598 <_Z9fYYRandomd>
 *   @0x110ee4 vmov.f64 d6, d8
 *   @0x110ee8 vmov d7, r0, r1
 *   @0x110eec vmla.f64 d6, d7, d9
 *   @0x110ef0 vpop {d8, d9}
 *   @0x110ef4 vmov r0, r1, d6
 *   @0x110ef8 pop {r3, pc}
 *
 * ══ §282/373 F_StringByteAt(RValue&, CInstance*, CInstance*, int, RValue*)  0x11132c  size 76  19 条（0x11132c..0x111378）
 * @func 0x11132c 0x111378  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int) / YYGetInt32(RValue const*, int) / YYGML_StringByteAt(char const*, int)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11132c push {r4, r5, r6, lr}
 *   @0x111330 mov r1, #0
 *   @0x111334 ldr r5, [sp, #0x10]
 *   @0x111338 mov r4, r0
 *   @0x11133c mov r0, r5
 *   @0x111340 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x111344 mov r1, #1
 *   @0x111348 mov r6, r0
 *   @0x11134c mov r0, r5
 *   @0x111350 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x111354 mov r3, #0
 *   @0x111358 str r3, [r4, #0xc]
 *   @0x11135c str r3, [r4]
 *   @0x111360 str r3, [r4, #0x4]
 *   @0x111364 mov r1, r0
 *   @0x111368 mov r0, r6
 *   @0x11136c bl 0x1112fc <_Z18YYGML_StringByteAtPKci>
 *   @0x111370 stm r4, {r0, r1}
 *   @0x111374 pop {r4, r5, r6, pc}
 *
 * ══ §283/373 CurrentTimeToTM()  0x117a10  size 76  19 条（0x117a10..0x117a5c）
 * @func 0x117a10 0x117a70  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f2140
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb67fc / 0xb6820 / 0xb682c
 * 字段偏移 top8: 0x4×2 / 0x-4×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x117a10 str lr, [sp, #-0x4]!
 *   @0x117a14 mov r0, #0
 *   @0x117a18 sub sp, sp, #12
 *   @0x117a1c bl 0xb67fc <time@plt>
 *   @0x117a20 ldr r3, [pc, #0x30]
 *   @0x117a24 add r3, pc, r3
 *   @0x117a28 ldrb r3, [r3]
 *   @0x117a2c cmp r3, #0
 *   @0x117a30 asr r1, r0, #31
 *   @0x117a34 strd r0, r1, [sp]
 *   @0x117a38 mov r0, sp
 *   @0x117a3c bne 0x117a4c <_Z15CurrentTimeToTMv+0x3c>
 *   @0x117a40 bl 0xb6820 <gmtime64@plt>
 *   @0x117a44 add sp, sp, #12
 *   @0x117a48 ldr pc, [sp], #4
 *   @0x117a4c bl 0xb682c <localtime64@plt>
 *   @0x117a50 add sp, sp, #12
 *   @0x117a54 ldr pc, [sp], #4
 *   @0x117a58 eoreq r10, sp, r4, lsl r7
 *
 * ══ §284/373 F_DisplaySetTimingMethod(RValue&, CInstance*, CInstance*, int, RValue*)  0x119cb4  size 76  19 条（0x119cb4..0x119d00）
 * @func 0x119cb4 0x119d00  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x119cb4 push {r3, lr}
 *   @0x119cb8 mov r1, #0
 *   @0x119cbc ldr r0, [sp, #0x8]
 *   @0x119cc0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x119cc4 cmp r0, #0
 *   @0x119cc8 beq 0x119ce4 <_Z24F_DisplaySetTimingMethodR6RValueP9CInstanceS2_iPS_+0x30>
 *   @0x119ccc cmp r0, #1
 *   @0x119cd0 ldreq r3, [pc, #0x20]
 *   @0x119cd4 moveq r2, #0
 *   @0x119cd8 ldreq r3, [pc, r3]
 *   @0x119cdc strbeq r2, [r3]
 *   @0x119ce0 pop {r3, pc}
 *   @0x119ce4 ldr r3, [pc, #0x10]
 *   @0x119ce8 mov r2, #1
 *   @0x119cec ldr r3, [pc, r3]
 *   @0x119cf0 strb r2, [r3]
 *   @0x119cf4 pop {r3, pc}
 *   @0x119cf8 .word 0x002d48d8
 *   @0x119cfc eoreq r4, sp, r4, asr #17
 *
 * ══ §285/373 F_StringWidth(RValue&, CInstance*, CInstance*, int, RValue*)  0x11bda0  size 76  19 条（0x11bda0..0x11bdec）
 * @func 0x11bda0 0x11be00  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int) / YYStrDup(char const*) / GR_Text_Width(char const*, int, int)
 * 字段偏移 top8: 0x10×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11bda0 push {r3, r4, r5, lr}
 *   @0x11bda4 mov r1, #0
 *   @0x11bda8 ldr r3, [sp, #0x10]
 *   @0x11bdac mov r4, r0
 *   @0x11bdb0 str r1, [r0, #0xc]
 *   @0x11bdb4 mov r0, r3
 *   @0x11bdb8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x11bdbc bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x11bdc0 mvn r1, #0
 *   @0x11bdc4 mov r2, r1
 *   @0x11bdc8 mov r5, r0
 *   @0x11bdcc bl 0x172bc8 <_Z13GR_Text_WidthPKcii>
 *   @0x11bdd0 vmov s15, r0
 *   @0x11bdd4 mov r0, r5
 *   @0x11bdd8 vcvt.f64.s32 d7, s15
 *   @0x11bddc vmov r2, r3, d7
 *   @0x11bde0 stm r4, {r2, r3}
 *   @0x11bde4 pop {r3, r4, r5, lr}
 *   @0x11bde8 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *
 * ══ §286/373 F_StringHeight(RValue&, CInstance*, CInstance*, int, RValue*)  0x11bdec  size 76  19 条（0x11bdec..0x11be38）
 * @func 0x11bdec 0x11be38  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int) / YYStrDup(char const*) / GR_Text_Height(char const*, int, int)
 * 字段偏移 top8: 0x10×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11bdec push {r3, r4, r5, lr}
 *   @0x11bdf0 mov r1, #0
 *   @0x11bdf4 ldr r3, [sp, #0x10]
 *   @0x11bdf8 mov r4, r0
 *   @0x11bdfc str r1, [r0, #0xc]
 *   @0x11be00 mov r0, r3
 *   @0x11be04 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x11be08 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x11be0c mvn r1, #0
 *   @0x11be10 mov r2, r1
 *   @0x11be14 mov r5, r0
 *   @0x11be18 bl 0x172d08 <_Z14GR_Text_HeightPKcii>
 *   @0x11be1c vmov s15, r0
 *   @0x11be20 mov r0, r5
 *   @0x11be24 vcvt.f64.s32 d7, s15
 *   @0x11be28 vmov r2, r3, d7
 *   @0x11be2c stm r4, {r2, r3}
 *   @0x11be30 pop {r3, r4, r5, lr}
 *   @0x11be34 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *
 * ══ §287/373 F_TextureGlobalScale(RValue&, CInstance*, CInstance*, int, RValue*)  0x11c67c  size 76  19 条（0x11c67c..0x11c6c8）
 * @func 0x11c67c 0x11c6c8  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_TextureGlobalScale(RValue&, CInstance*, CInstance*, int, RValue*)+0x28 / YYError(char const*, ...)
 * 字段偏移 top8: 0x8×1 / 0x24×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11c67c push {r4, lr}
 *   @0x11c680 mov r1, #0
 *   @0x11c684 ldr r0, [sp, #0x8]
 *   @0x11c688 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11c68c subs r4, r0, #0
 *   @0x11c690 ble 0x11c6a4 <_Z20F_TextureGlobalScaleR6RValueP9CInstanceS2_iPS_+0x28>
 *   @0x11c694 ldr r3, [pc, #0x24]
 *   @0x11c698 ldr r3, [pc, r3]
 *   @0x11c69c str r4, [r3]
 *   @0x11c6a0 pop {r4, pc}
 *   @0x11c6a4 sub r3, r4, #1
 *   @0x11c6a8 tst r3, r4
 *   @0x11c6ac beq 0x11c694 <_Z20F_TextureGlobalScaleR6RValueP9CInstanceS2_iPS_+0x18>
 *   @0x11c6b0 ldr r0, [pc, #0xc]
 *   @0x11c6b4 add r0, pc, r0
 *   @0x11c6b8 bl 0xd547c <_Z7YYErrorPKcz>
 *   @0x11c6bc b 0x11c694 <_Z20F_TextureGlobalScaleR6RValueP9CInstanceS2_iPS_+0x18>
 *   @0x11c6c0 eoreq r1, sp, r12, lsr pc
 *   @0x11c6c4 eoreq sp, r1, r0, asr #18
 *
 * ══ §288/373 F_GetDirectory(RValue&, CInstance*, CInstance*, int, RValue*)  0x126964  size 76  19 条（0x126964..0x1269b0）
 * @func 0x126964 0x1269c4  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYCreateString(RValue*, char const*)
 * 字段偏移 top8: 0x38×1 / 0x2c×1 / 0xc×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x126964 ldr r3, [pc, #0x38]
 *   @0x126968 push {r4, lr}
 *   @0x12696c ldr r3, [pc, r3]
 *   @0x126970 mov r4, r0
 *   @0x126974 ldr r1, [pc, #0x2c]
 *   @0x126978 ldr r0, [r3]
 *   @0x12697c add r1, pc, r1
 *   @0x126980 ldr r2, [r0]
 *   @0x126984 ldr r3, [r2, #0xc]
 *   @0x126988 blx r3
 *   @0x12698c ldr r1, [pc, #0x18]
 *   @0x126990 mov r0, r4
 *   @0x126994 add r1, pc, r1
 *   @0x126998 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x12699c pop {r4, lr}
 *   @0x1269a0 b 0x18c2c8 <_Z8IO_Clearv>
 *   @0x1269a4 eoreq r6, r12, r8, lsr #27
 *   @0x1269a8 eoreq r5, r1, r8, lsl r9
 *   @0x1269ac eoreq r8, r0, r2, lsr #3
 *
 * ══ §289/373 F_GetDirectoryAlt(RValue&, CInstance*, CInstance*, int, RValue*)  0x1269b0  size 76  19 条（0x1269b0..0x1269fc）
 * @func 0x1269b0 0x1269fc  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYCreateString(RValue*, char const*)
 * 字段偏移 top8: 0x38×1 / 0x2c×1 / 0xc×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1269b0 ldr r3, [pc, #0x38]
 *   @0x1269b4 push {r4, lr}
 *   @0x1269b8 ldr r3, [pc, r3]
 *   @0x1269bc mov r4, r0
 *   @0x1269c0 ldr r1, [pc, #0x2c]
 *   @0x1269c4 ldr r0, [r3]
 *   @0x1269c8 add r1, pc, r1
 *   @0x1269cc ldr r2, [r0]
 *   @0x1269d0 ldr r3, [r2, #0xc]
 *   @0x1269d4 blx r3
 *   @0x1269d8 ldr r1, [pc, #0x18]
 *   @0x1269dc mov r0, r4
 *   @0x1269e0 add r1, pc, r1
 *   @0x1269e4 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x1269e8 pop {r4, lr}
 *   @0x1269ec b 0x18c2c8 <_Z8IO_Clearv>
 *   @0x1269f0 eoreq r6, r12, r12, asr sp
 *   @0x1269f4 .word 0x002158f4
 *   @0x1269f8 eoreq r8, r0, r6, asr r1
 *
 * ══ §290/373 F_SpriteAddSprite(RValue&, CInstance*, CInstance*, int, RValue*)  0x12a870  size 76  19 条（0x12a870..0x12a8bc）
 * @func 0x12a870 0x12a8d0  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×2 / 0x34×1 / 0x4×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12a870 push {r3, lr}
 *   @0x12a874 mov r12, #0
 *   @0x12a878 ldr r3, [pc, #0x34]
 *   @0x12a87c mov r2, r0
 *   @0x12a880 mov r1, r12
 *   @0x12a884 str r1, [r0]
 *   @0x12a888 ldr r3, [pc, r3]
 *   @0x12a88c movt r12, #0xbff0
 *   @0x12a890 str r12, [r2, #0x4]
 *   @0x12a894 ldr r0, [r3]
 *   @0x12a898 str r1, [r2, #0xc]
 *   @0x12a89c ldr r1, [pc, #0x14]
 *   @0x12a8a0 ldr r3, [r0]
 *   @0x12a8a4 add r1, pc, r1
 *   @0x12a8a8 ldr r3, [r3, #0xc]
 *   @0x12a8ac blx r3
 *   @0x12a8b0 pop {r3, pc}
 *   @0x12a8b4 eoreq r2, r12, r12, lsl #29
 *   @0x12a8b8 eoreq r2, r1, r12, lsl #23
 *
 * ══ §291/373 F_SpriteReplaceSprite(RValue&, CInstance*, CInstance*, int, RValue*)  0x12a8bc  size 76  19 条（0x12a8bc..0x12a908）
 * @func 0x12a8bc 0x12a91c  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×2 / 0x34×1 / 0x4×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12a8bc push {r3, lr}
 *   @0x12a8c0 mov r12, #0
 *   @0x12a8c4 ldr r3, [pc, #0x34]
 *   @0x12a8c8 mov r2, r0
 *   @0x12a8cc mov r1, r12
 *   @0x12a8d0 str r1, [r0]
 *   @0x12a8d4 ldr r3, [pc, r3]
 *   @0x12a8d8 movt r12, #0xbff0
 *   @0x12a8dc str r12, [r2, #0x4]
 *   @0x12a8e0 ldr r0, [r3]
 *   @0x12a8e4 str r1, [r2, #0xc]
 *   @0x12a8e8 ldr r1, [pc, #0x14]
 *   @0x12a8ec ldr r3, [r0]
 *   @0x12a8f0 add r1, pc, r1
 *   @0x12a8f4 ldr r3, [r3, #0xc]
 *   @0x12a8f8 blx r3
 *   @0x12a8fc pop {r3, pc}
 *   @0x12a900 eoreq r2, r12, r0, asr #28
 *   @0x12a904 eoreq r2, r1, r0, asr #22
 *
 * ══ §292/373 F_BackgroundAddBackground(RValue&, CInstance*, CInstance*, int, RValue*)  0x12a908  size 76  19 条（0x12a908..0x12a954）
 * @func 0x12a908 0x12a968  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×2 / 0x34×1 / 0x4×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12a908 push {r3, lr}
 *   @0x12a90c mov r12, #0
 *   @0x12a910 ldr r3, [pc, #0x34]
 *   @0x12a914 mov r2, r0
 *   @0x12a918 mov r1, r12
 *   @0x12a91c str r1, [r0]
 *   @0x12a920 ldr r3, [pc, r3]
 *   @0x12a924 movt r12, #0xbff0
 *   @0x12a928 str r12, [r2, #0x4]
 *   @0x12a92c ldr r0, [r3]
 *   @0x12a930 str r1, [r2, #0xc]
 *   @0x12a934 ldr r1, [pc, #0x14]
 *   @0x12a938 ldr r3, [r0]
 *   @0x12a93c add r1, pc, r1
 *   @0x12a940 ldr r3, [r3, #0xc]
 *   @0x12a944 blx r3
 *   @0x12a948 pop {r3, pc}
 *   @0x12a94c .word 0x002c2df4
 *   @0x12a950 .word 0x00212af4
 *
 * ══ §293/373 F_BackgroundReplaceBackground(RValue&, CInstance*, CInstance*, int, RValue*)  0x12a954  size 76  19 条（0x12a954..0x12a9a0）
 * @func 0x12a954 0x12a9a0  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×2 / 0x34×1 / 0x4×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12a954 push {r3, lr}
 *   @0x12a958 mov r12, #0
 *   @0x12a95c ldr r3, [pc, #0x34]
 *   @0x12a960 mov r2, r0
 *   @0x12a964 mov r1, r12
 *   @0x12a968 str r1, [r0]
 *   @0x12a96c ldr r3, [pc, r3]
 *   @0x12a970 movt r12, #0xbff0
 *   @0x12a974 str r12, [r2, #0x4]
 *   @0x12a978 ldr r0, [r3]
 *   @0x12a97c str r1, [r2, #0xc]
 *   @0x12a980 ldr r1, [pc, #0x14]
 *   @0x12a984 ldr r3, [r0]
 *   @0x12a988 add r1, pc, r1
 *   @0x12a98c ldr r3, [r3, #0xc]
 *   @0x12a990 blx r3
 *   @0x12a994 pop {r3, pc}
 *   @0x12a998 eoreq r2, r12, r8, lsr #27
 *   @0x12a99c eoreq r2, r1, r8, lsr #21
 *
 * ══ §294/373 F_FontGetSize(RValue&, CInstance*, CInstance*, int, RValue*)  0x12cd8c  size 76  19 条（0x12cd8c..0x12cdd8）
 * @func 0x12cd8c 0x12cdd8  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Font_Data(int) / CFontGM::GetSize()
 * 字段偏移 top8: 0x8×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12cd8c push {r4, lr}
 *   @0x12cd90 mov r1, #0
 *   @0x12cd94 mov r4, r0
 *   @0x12cd98 ldr r0, [sp, #0x8]
 *   @0x12cd9c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12cda0 bl 0xfa3fc <_Z9Font_Datai>
 *   @0x12cda4 cmp r0, #0
 *   @0x12cda8 beq 0x12cdcc <_Z13F_FontGetSizeR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x12cdac bl 0xf93d0 <_ZN7CFontGM7GetSizeEv>
 *   @0x12cdb0 vmov s15, r0
 *   @0x12cdb4 vcvt.f64.s32 d7, s15
 *   @0x12cdb8 vmov r2, r3, d7
 *   @0x12cdbc mov r1, #0
 *   @0x12cdc0 stm r4, {r2, r3}
 *   @0x12cdc4 str r1, [r4, #0xc]
 *   @0x12cdc8 pop {r4, pc}
 *   @0x12cdcc mov r2, #0
 *   @0x12cdd0 mov r3, #0
 *   @0x12cdd4 b 0x12cdbc <_Z13F_FontGetSizeR6RValueP9CInstanceS2_iPS_+0x30>
 *
 * ══ §295/373 F_BackgroundAssign(RValue&, CInstance*, CInstance*, int, RValue*)  0x12f670  size 76  19 条（0x12f670..0x12f6bc）
 * @func 0x12f670 0x12f6bc  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / Background_Assign(int, int)
 * 字段偏移 top8: 0x10×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12f670 push {r3, r4, r5, lr}
 *   @0x12f674 mov r1, #0
 *   @0x12f678 ldr r4, [sp, #0x10]
 *   @0x12f67c mov r0, r4
 *   @0x12f680 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12f684 mov r1, #1
 *   @0x12f688 mov r5, r0
 *   @0x12f68c mov r0, r4
 *   @0x12f690 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12f694 mov r1, r0
 *   @0x12f698 mov r0, r5
 *   @0x12f69c bl 0xc4148 <_Z17Background_Assignii>
 *   @0x12f6a0 subs r1, r0, #0
 *   @0x12f6a4 popne {r3, r4, r5, pc}
 *   @0x12f6a8 ldr r0, [pc, #0x8]
 *   @0x12f6ac pop {r3, r4, r5, lr}
 *   @0x12f6b0 add r0, pc, r0
 *   @0x12f6b4 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x12f6b8 eoreq lr, r0, r0, ror r2
 *
 * ══ §296/373 F_PathAssign(RValue&, CInstance*, CInstance*, int, RValue*)  0x12f8e0  size 76  19 条（0x12f8e0..0x12f92c）
 * @func 0x12f8e0 0x12f92c  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / Path_Assign(int, int)
 * 字段偏移 top8: 0x10×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12f8e0 push {r3, r4, r5, lr}
 *   @0x12f8e4 mov r1, #0
 *   @0x12f8e8 ldr r4, [sp, #0x10]
 *   @0x12f8ec mov r0, r4
 *   @0x12f8f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12f8f4 mov r1, #1
 *   @0x12f8f8 mov r5, r0
 *   @0x12f8fc mov r0, r4
 *   @0x12f900 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12f904 mov r1, r0
 *   @0x12f908 mov r0, r5
 *   @0x12f90c bl 0x1a8460 <_Z11Path_Assignii>
 *   @0x12f910 subs r1, r0, #0
 *   @0x12f914 popne {r3, r4, r5, pc}
 *   @0x12f918 ldr r0, [pc, #0x8]
 *   @0x12f91c pop {r3, r4, r5, lr}
 *   @0x12f920 add r0, pc, r0
 *   @0x12f924 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x12f928 eoreq lr, r0, r8, asr #32
 *
 * ══ §297/373 F_RoomAssign(RValue&, CInstance*, CInstance*, int, RValue*)  0x12f9ac  size 76  19 条（0x12f9ac..0x12f9f8）
 * @func 0x12f9ac 0x12f9f8  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / Room_Assign(int, int)
 * 字段偏移 top8: 0x10×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12f9ac push {r3, r4, r5, lr}
 *   @0x12f9b0 mov r1, #0
 *   @0x12f9b4 ldr r4, [sp, #0x10]
 *   @0x12f9b8 mov r0, r4
 *   @0x12f9bc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12f9c0 mov r1, #1
 *   @0x12f9c4 mov r5, r0
 *   @0x12f9c8 mov r0, r4
 *   @0x12f9cc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12f9d0 mov r1, r0
 *   @0x12f9d4 mov r0, r5
 *   @0x12f9d8 bl 0x1b5af4 <_Z11Room_Assignii>
 *   @0x12f9dc subs r1, r0, #0
 *   @0x12f9e0 popne {r3, r4, r5, pc}
 *   @0x12f9e4 ldr r0, [pc, #0x8]
 *   @0x12f9e8 pop {r3, r4, r5, lr}
 *   @0x12f9ec add r0, pc, r0
 *   @0x12f9f0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x12f9f4 .word 0x0020dfd4
 *
 * ══ §298/373 F_AudioGetType(RValue&, CInstance*, CInstance*, int, RValue*)  0x134f24  size 76  19 条（0x134f24..0x134f70）
 * @func 0x134f24 0x134f84  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Audio_GetSoundType(int)
 * 字段偏移 top8: 0x40×1 / 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x134f24 ldr r3, [pc, #0x40]
 *   @0x134f28 push {r4, lr}
 *   @0x134f2c ldr r3, [pc, r3]
 *   @0x134f30 mov r4, r0
 *   @0x134f34 ldrb r1, [r3]
 *   @0x134f38 cmp r1, #0
 *   @0x134f3c popne {r4, pc}
 *   @0x134f40 str r1, [r0, #0xc]
 *   @0x134f44 ldr r0, [sp, #0x8]
 *   @0x134f48 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x134f4c bl 0x217028 <_Z18Audio_GetSoundTypei>
 *   @0x134f50 vmov s15, r0
 *   @0x134f54 vcvt.f64.s32 d7, s15
 *   @0x134f58 vmov r0, r1, d7
 *   @0x134f5c vmov r2, s14
 *   @0x134f60 mov r3, r1
 *   @0x134f64 stm r4, {r2, r3}
 *   @0x134f68 pop {r4, pc}
 *   @0x134f6c eoreq r10, r11, r0, lsr #2
 *
 * ══ §299/373 F_AudioEmitterExists(RValue&, CInstance*, CInstance*, int, RValue*)  0x134f70  size 76  19 条（0x134f70..0x134fbc）
 * @func 0x134f70 0x134fbc  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Audio_EmitterExists(int)
 * 字段偏移 top8: 0x40×1 / 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x134f70 ldr r3, [pc, #0x40]
 *   @0x134f74 push {r4, lr}
 *   @0x134f78 ldr r3, [pc, r3]
 *   @0x134f7c mov r4, r0
 *   @0x134f80 ldrb r1, [r3]
 *   @0x134f84 cmp r1, #0
 *   @0x134f88 popne {r4, pc}
 *   @0x134f8c str r1, [r0, #0xc]
 *   @0x134f90 ldr r0, [sp, #0x8]
 *   @0x134f94 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x134f98 bl 0x217324 <_Z19Audio_EmitterExistsi>
 *   @0x134f9c vmov s15, r0
 *   @0x134fa0 vcvt.f64.u32 d7, s15
 *   @0x134fa4 vmov r0, r1, d7
 *   @0x134fa8 vmov r2, s14
 *   @0x134fac mov r3, r1
 *   @0x134fb0 stm r4, {r2, r3}
 *   @0x134fb4 pop {r4, pc}
 *   @0x134fb8 .word 0x002ba0d4
 *
 * ══ §300/373 F_AudioSetMasterGainN(RValue&, CInstance*, CInstance*, int, RValue*)  0x135024  size 76  19 条（0x135024..0x135070）
 * @func 0x135024 0x135084  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGetReal(RValue const*, int)
 * 字段偏移 top8: 0x40×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x135024 ldr r3, [pc, #0x40]
 *   @0x135028 push {r4, r5, r6, lr}
 *   @0x13502c ldr r3, [pc, r3]
 *   @0x135030 ldr r4, [sp, #0x10]
 *   @0x135034 ldrb r1, [r3]
 *   @0x135038 cmp r1, #0
 *   @0x13503c popne {r4, r5, r6, pc}
 *   @0x135040 mov r0, r4
 *   @0x135044 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x135048 mov r1, #1
 *   @0x13504c mov r5, r0
 *   @0x135050 mov r0, r4
 *   @0x135054 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x135058 mov r2, r0
 *   @0x13505c mov r3, r1
 *   @0x135060 mov r0, r5
 *   @0x135064 pop {r4, r5, r6, lr}
 *   @0x135068 b 0x218118 <_Z19Audio_SetMasterGainid>
 *   @0x13506c eoreq r10, r11, r0, lsr #32
 *
 * ══ §301/373 F_AudioSetEmitterGain(RValue&, CInstance*, CInstance*, int, RValue*)  0x135070  size 76  19 条（0x135070..0x1350bc）
 * @func 0x135070 0x1350d0  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGetReal(RValue const*, int)
 * 字段偏移 top8: 0x40×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x135070 ldr r3, [pc, #0x40]
 *   @0x135074 push {r4, r5, r6, lr}
 *   @0x135078 ldr r3, [pc, r3]
 *   @0x13507c ldr r4, [sp, #0x10]
 *   @0x135080 ldrb r1, [r3]
 *   @0x135084 cmp r1, #0
 *   @0x135088 popne {r4, r5, r6, pc}
 *   @0x13508c mov r0, r4
 *   @0x135090 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x135094 mov r1, #1
 *   @0x135098 mov r5, r0
 *   @0x13509c mov r0, r4
 *   @0x1350a0 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x1350a4 mov r2, r0
 *   @0x1350a8 mov r3, r1
 *   @0x1350ac mov r0, r5
 *   @0x1350b0 pop {r4, r5, r6, lr}
 *   @0x1350b4 b 0x21803c <_Z20Audio_SetEmitterGainid>
 *   @0x1350b8 .word 0x002b9fd4
 *
 * ══ §302/373 F_AudioSetEmitterPitch(RValue&, CInstance*, CInstance*, int, RValue*)  0x1350bc  size 76  19 条（0x1350bc..0x135108）
 * @func 0x1350bc 0x135108  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGetReal(RValue const*, int)
 * 字段偏移 top8: 0x40×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1350bc ldr r3, [pc, #0x40]
 *   @0x1350c0 push {r4, r5, r6, lr}
 *   @0x1350c4 ldr r3, [pc, r3]
 *   @0x1350c8 ldr r4, [sp, #0x10]
 *   @0x1350cc ldrb r1, [r3]
 *   @0x1350d0 cmp r1, #0
 *   @0x1350d4 popne {r4, r5, r6, pc}
 *   @0x1350d8 mov r0, r4
 *   @0x1350dc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1350e0 mov r1, #1
 *   @0x1350e4 mov r5, r0
 *   @0x1350e8 mov r0, r4
 *   @0x1350ec bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x1350f0 mov r2, r0
 *   @0x1350f4 mov r3, r1
 *   @0x1350f8 mov r0, r5
 *   @0x1350fc pop {r4, r5, r6, lr}
 *   @0x135100 b 0x2181bc <_Z21Audio_SetEmitterPitchid>
 *   @0x135104 eoreq r9, r11, r8, lsl #31
 *
 * ══ §303/373 F_AudioSoundLength(RValue&, CInstance*, CInstance*, int, RValue*)  0x13525c  size 76  19 条（0x13525c..0x1352a8）
 * @func 0x13525c 0x1352bc  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Audio_SoundLength(int)
 * 字段偏移 top8: 0x40×1 / 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13525c ldr r3, [pc, #0x40]
 *   @0x135260 push {r4, lr}
 *   @0x135264 ldr r3, [pc, r3]
 *   @0x135268 mov r4, r0
 *   @0x13526c ldrb r1, [r3]
 *   @0x135270 cmp r1, #0
 *   @0x135274 popne {r4, pc}
 *   @0x135278 str r1, [r0, #0xc]
 *   @0x13527c ldr r0, [sp, #0x8]
 *   @0x135280 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x135284 bl 0x218640 <_Z17Audio_SoundLengthi>
 *   @0x135288 vmov s15, r0
 *   @0x13528c vcvt.f64.f32 d7, s15
 *   @0x135290 vmov r0, r1, d7
 *   @0x135294 vmov r2, s14
 *   @0x135298 mov r3, r1
 *   @0x13529c stm r4, {r2, r3}
 *   @0x1352a0 pop {r4, pc}
 *   @0x1352a4 eoreq r9, r11, r8, ror #27
 *
 * ══ §304/373 F_AudioGetEmitterGain(RValue&, CInstance*, CInstance*, int, RValue*)  0x1352a8  size 76  19 条（0x1352a8..0x1352f4）
 * @func 0x1352a8 0x135308  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Audio_GetEmitterGain(int)
 * 字段偏移 top8: 0x40×1 / 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1352a8 ldr r3, [pc, #0x40]
 *   @0x1352ac push {r4, lr}
 *   @0x1352b0 ldr r3, [pc, r3]
 *   @0x1352b4 mov r4, r0
 *   @0x1352b8 ldrb r1, [r3]
 *   @0x1352bc cmp r1, #0
 *   @0x1352c0 popne {r4, pc}
 *   @0x1352c4 str r1, [r0, #0xc]
 *   @0x1352c8 ldr r0, [sp, #0x8]
 *   @0x1352cc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1352d0 bl 0x2180ac <_Z20Audio_GetEmitterGaini>
 *   @0x1352d4 vmov s15, r0
 *   @0x1352d8 vcvt.f64.f32 d7, s15
 *   @0x1352dc vmov r0, r1, d7
 *   @0x1352e0 vmov r2, s14
 *   @0x1352e4 mov r3, r1
 *   @0x1352e8 stm r4, {r2, r3}
 *   @0x1352ec pop {r4, pc}
 *   @0x1352f0 mlaeq r11, r12, sp, r9
 *
 * ══ §305/373 F_AudioGetEmitterPitch(RValue&, CInstance*, CInstance*, int, RValue*)  0x1352f4  size 76  19 条（0x1352f4..0x135340）
 * @func 0x1352f4 0x135340  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Audio_GetEmitterPitch(int)
 * 字段偏移 top8: 0x40×1 / 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1352f4 ldr r3, [pc, #0x40]
 *   @0x1352f8 push {r4, lr}
 *   @0x1352fc ldr r3, [pc, r3]
 *   @0x135300 mov r4, r0
 *   @0x135304 ldrb r1, [r3]
 *   @0x135308 cmp r1, #0
 *   @0x13530c popne {r4, pc}
 *   @0x135310 str r1, [r0, #0xc]
 *   @0x135314 ldr r0, [sp, #0x8]
 *   @0x135318 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13531c bl 0x2182e0 <_Z21Audio_GetEmitterPitchi>
 *   @0x135320 vmov s15, r0
 *   @0x135324 vcvt.f64.f32 d7, s15
 *   @0x135328 vmov r0, r1, d7
 *   @0x13532c vmov r2, s14
 *   @0x135330 mov r3, r1
 *   @0x135334 stm r4, {r2, r3}
 *   @0x135338 pop {r4, pc}
 *   @0x13533c eoreq r9, r11, r0, asr sp
 *
 * ══ §306/373 F_AudioGetListenerData(RValue&, CInstance*, CInstance*, int, RValue*)  0x135568  size 76  19 条（0x135568..0x1355b4）
 * @func 0x135568 0x1355c8  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Audio_GetListenerData(int)
 * 字段偏移 top8: 0x40×1 / 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x135568 ldr r3, [pc, #0x40]
 *   @0x13556c push {r4, lr}
 *   @0x135570 ldr r3, [pc, r3]
 *   @0x135574 mov r4, r0
 *   @0x135578 ldrb r1, [r3]
 *   @0x13557c cmp r1, #0
 *   @0x135580 popne {r4, pc}
 *   @0x135584 str r1, [r0, #0xc]
 *   @0x135588 ldr r0, [sp, #0x8]
 *   @0x13558c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x135590 bl 0x2167dc <_Z21Audio_GetListenerDatai>
 *   @0x135594 vmov s15, r0
 *   @0x135598 vcvt.f64.s32 d7, s15
 *   @0x13559c vmov r0, r1, d7
 *   @0x1355a0 vmov r2, s14
 *   @0x1355a4 mov r3, r1
 *   @0x1355a8 stm r4, {r2, r3}
 *   @0x1355ac pop {r4, pc}
 *   @0x1355b0 .word 0x002b9adc
 *
 * ══ §307/373 F_AudioGetMasterGainN(RValue&, CInstance*, CInstance*, int, RValue*)  0x1355b4  size 76  19 条（0x1355b4..0x135600）
 * @func 0x1355b4 0x135614  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Audio_GetMasterGain(int)
 * 字段偏移 top8: 0x40×1 / 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1355b4 ldr r3, [pc, #0x40]
 *   @0x1355b8 push {r4, lr}
 *   @0x1355bc ldr r3, [pc, r3]
 *   @0x1355c0 mov r4, r0
 *   @0x1355c4 ldrb r1, [r3]
 *   @0x1355c8 cmp r1, #0
 *   @0x1355cc popne {r4, pc}
 *   @0x1355d0 str r1, [r0, #0xc]
 *   @0x1355d4 ldr r0, [sp, #0x8]
 *   @0x1355d8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1355dc bl 0x218190 <_Z19Audio_GetMasterGaini>
 *   @0x1355e0 vmov s15, r0
 *   @0x1355e4 vcvt.f64.f32 d7, s15
 *   @0x1355e8 vmov r0, r1, d7
 *   @0x1355ec vmov r2, s14
 *   @0x1355f0 mov r3, r1
 *   @0x1355f4 stm r4, {r2, r3}
 *   @0x1355f8 pop {r4, pc}
 *   @0x1355fc mlaeq r11, r0, r10, r9
 *
 * ══ §308/373 F_AudioGetSoundGain(RValue&, CInstance*, CInstance*, int, RValue*)  0x135600  size 76  19 条（0x135600..0x13564c）
 * @func 0x135600 0x135660  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Audio_GetSoundGain(int)
 * 字段偏移 top8: 0x40×1 / 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x135600 ldr r3, [pc, #0x40]
 *   @0x135604 push {r4, lr}
 *   @0x135608 ldr r3, [pc, r3]
 *   @0x13560c mov r4, r0
 *   @0x135610 ldrb r1, [r3]
 *   @0x135614 cmp r1, #0
 *   @0x135618 popne {r4, pc}
 *   @0x13561c str r1, [r0, #0xc]
 *   @0x135620 ldr r0, [sp, #0x8]
 *   @0x135624 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x135628 bl 0x21788c <_Z18Audio_GetSoundGaini>
 *   @0x13562c vmov s15, r0
 *   @0x135630 vcvt.f64.f32 d7, s15
 *   @0x135634 vmov r0, r1, d7
 *   @0x135638 vmov r2, s14
 *   @0x13563c mov r3, r1
 *   @0x135640 stm r4, {r2, r3}
 *   @0x135644 pop {r4, pc}
 *   @0x135648 eoreq r9, r11, r4, asr #20
 *
 * ══ §309/373 F_AudioGetSoundPitch(RValue&, CInstance*, CInstance*, int, RValue*)  0x13564c  size 76  19 条（0x13564c..0x135698）
 * @func 0x13564c 0x135698  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Audio_GetSoundPitch(int)
 * 字段偏移 top8: 0x40×1 / 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13564c ldr r3, [pc, #0x40]
 *   @0x135650 push {r4, lr}
 *   @0x135654 ldr r3, [pc, r3]
 *   @0x135658 mov r4, r0
 *   @0x13565c ldrb r1, [r3]
 *   @0x135660 cmp r1, #0
 *   @0x135664 popne {r4, pc}
 *   @0x135668 str r1, [r0, #0xc]
 *   @0x13566c ldr r0, [sp, #0x8]
 *   @0x135670 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x135674 bl 0x2173fc <_Z19Audio_GetSoundPitchi>
 *   @0x135678 vmov s15, r0
 *   @0x13567c vcvt.f64.f32 d7, s15
 *   @0x135680 vmov r0, r1, d7
 *   @0x135684 vmov r2, s14
 *   @0x135688 mov r3, r1
 *   @0x13568c stm r4, {r2, r3}
 *   @0x135690 pop {r4, pc}
 *   @0x135694 .word 0x002b99f8
 *
 * ══ §310/373 F_AudioGetTrackPos(RValue&, CInstance*, CInstance*, int, RValue*)  0x13571c  size 76  19 条（0x13571c..0x135768）
 * @func 0x13571c 0x135768  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Audio_GetTrackPos(int)
 * 字段偏移 top8: 0x40×1 / 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13571c ldr r3, [pc, #0x40]
 *   @0x135720 push {r4, lr}
 *   @0x135724 ldr r3, [pc, r3]
 *   @0x135728 mov r4, r0
 *   @0x13572c ldrb r1, [r3]
 *   @0x135730 cmp r1, #0
 *   @0x135734 popne {r4, pc}
 *   @0x135738 str r1, [r0, #0xc]
 *   @0x13573c ldr r0, [sp, #0x8]
 *   @0x135740 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x135744 bl 0x218908 <_Z17Audio_GetTrackPosi>
 *   @0x135748 vmov s15, r0
 *   @0x13574c vcvt.f64.f32 d7, s15
 *   @0x135750 vmov r0, r1, d7
 *   @0x135754 vmov r2, s14
 *   @0x135758 mov r3, r1
 *   @0x13575c stm r4, {r2, r3}
 *   @0x135760 pop {r4, pc}
 *   @0x135764 eoreq r9, r11, r8, lsr #18
 *
 * ══ §311/373 F_Audio_GroupName(RValue&, CInstance*, CInstance*, int, RValue*)  0x1358dc  size 76  19 条（0x1358dc..0x135928）
 * @func 0x1358dc 0x135928  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CAudioGroupMan::GetGroupName(int)
 * 字段偏移 top8: 0x3c×1 / 0x8×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1358dc ldr r3, [pc, #0x3c]
 *   @0x1358e0 push {r4, lr}
 *   @0x1358e4 ldr r3, [pc, r3]
 *   @0x1358e8 mov r4, r0
 *   @0x1358ec ldr r0, [sp, #0x8]
 *   @0x1358f0 ldrb r1, [r3]
 *   @0x1358f4 cmp r1, #0
 *   @0x1358f8 popne {r4, pc}
 *   @0x1358fc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x135900 ldr r3, [pc, #0x1c]
 *   @0x135904 mov r1, r0
 *   @0x135908 ldr r0, [pc, r3]
 *   @0x13590c bl 0x21df34 <_ZN14CAudioGroupMan12GetGroupNameEi>
 *   @0x135910 mov r1, r0
 *   @0x135914 mov r0, r4
 *   @0x135918 pop {r4, lr}
 *   @0x13591c b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x135920 eoreq r9, r11, r8, ror #14
 *   @0x135924 eoreq r9, r11, r8, asr #14
 *
 * ══ §312/373 F_Audio_FreeBufferSound(RValue&, CInstance*, CInstance*, int, RValue*)  0x135a74  size 76  19 条（0x135a74..0x135ac0）
 * @func 0x135a74 0x135ad4  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Audio_FreeBufferSound(int)
 * 字段偏移 top8: 0x40×1 / 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x135a74 ldr r3, [pc, #0x40]
 *   @0x135a78 push {r4, lr}
 *   @0x135a7c ldr r3, [pc, r3]
 *   @0x135a80 mov r4, r0
 *   @0x135a84 ldrb r1, [r3]
 *   @0x135a88 cmp r1, #0
 *   @0x135a8c popne {r4, pc}
 *   @0x135a90 str r1, [r0, #0xc]
 *   @0x135a94 ldr r0, [sp, #0x8]
 *   @0x135a98 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x135a9c bl 0x219d70 <_Z21Audio_FreeBufferSoundi>
 *   @0x135aa0 vmov s15, r0
 *   @0x135aa4 vcvt.f64.s32 d7, s15
 *   @0x135aa8 vmov r0, r1, d7
 *   @0x135aac vmov r2, s14
 *   @0x135ab0 mov r3, r1
 *   @0x135ab4 stm r4, {r2, r3}
 *   @0x135ab8 pop {r4, pc}
 *   @0x135abc .word 0x002b95d0
 *
 * ══ §313/373 F_Audio_StartRecording(RValue&, CInstance*, CInstance*, int, RValue*)  0x135ac0  size 76  19 条（0x135ac0..0x135b0c）
 * @func 0x135ac0 0x135b0c  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Audio_StartRecording(int)
 * 字段偏移 top8: 0x40×1 / 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x135ac0 ldr r3, [pc, #0x40]
 *   @0x135ac4 push {r4, lr}
 *   @0x135ac8 ldr r3, [pc, r3]
 *   @0x135acc mov r4, r0
 *   @0x135ad0 ldrb r1, [r3]
 *   @0x135ad4 cmp r1, #0
 *   @0x135ad8 popne {r4, pc}
 *   @0x135adc str r1, [r0, #0xc]
 *   @0x135ae0 ldr r0, [sp, #0x8]
 *   @0x135ae4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x135ae8 bl 0x21c700 <_Z20Audio_StartRecordingi>
 *   @0x135aec vmov s15, r0
 *   @0x135af0 vcvt.f64.s32 d7, s15
 *   @0x135af4 vmov r0, r1, d7
 *   @0x135af8 vmov r2, s14
 *   @0x135afc mov r3, r1
 *   @0x135b00 stm r4, {r2, r3}
 *   @0x135b04 pop {r4, pc}
 *   @0x135b08 eoreq r9, r11, r4, lsl #11
 *
 * ══ §314/373 F_Audio_GetRecorderInfo(RValue&, CInstance*, CInstance*, int, RValue*)  0x135b50  size 76  19 条（0x135b50..0x135b9c）
 * @func 0x135b50 0x135b9c  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Audio_GetRecorderInfo(int)
 * 字段偏移 top8: 0x40×1 / 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x135b50 ldr r3, [pc, #0x40]
 *   @0x135b54 push {r4, lr}
 *   @0x135b58 ldr r3, [pc, r3]
 *   @0x135b5c mov r4, r0
 *   @0x135b60 ldrb r1, [r3]
 *   @0x135b64 cmp r1, #0
 *   @0x135b68 popne {r4, pc}
 *   @0x135b6c str r1, [r0, #0xc]
 *   @0x135b70 ldr r0, [sp, #0x8]
 *   @0x135b74 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x135b78 bl 0x21c5bc <_Z21Audio_GetRecorderInfoi>
 *   @0x135b7c vmov s15, r0
 *   @0x135b80 vcvt.f64.s32 d7, s15
 *   @0x135b84 vmov r0, r1, d7
 *   @0x135b88 vmov r2, s14
 *   @0x135b8c mov r3, r1
 *   @0x135b90 stm r4, {r2, r3}
 *   @0x135b94 pop {r4, pc}
 *   @0x135b98 .word 0x002b94f4
 *
 * ══ §315/373 F_Audio_FreePlayQueue(RValue&, CInstance*, CInstance*, int, RValue*)  0x135c18  size 76  19 条（0x135c18..0x135c64）
 * @func 0x135c18 0x135c64  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Audio_FreePlayQueue(int)
 * 字段偏移 top8: 0x40×1 / 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x135c18 ldr r3, [pc, #0x40]
 *   @0x135c1c push {r4, lr}
 *   @0x135c20 ldr r3, [pc, r3]
 *   @0x135c24 mov r4, r0
 *   @0x135c28 ldrb r1, [r3]
 *   @0x135c2c cmp r1, #0
 *   @0x135c30 popne {r4, pc}
 *   @0x135c34 str r1, [r0, #0xc]
 *   @0x135c38 ldr r0, [sp, #0x8]
 *   @0x135c3c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x135c40 bl 0x21ce90 <_Z19Audio_FreePlayQueuei>
 *   @0x135c44 vmov s15, r0
 *   @0x135c48 vcvt.f64.s32 d7, s15
 *   @0x135c4c vmov r0, r1, d7
 *   @0x135c50 vmov r2, s14
 *   @0x135c54 mov r3, r1
 *   @0x135c58 stm r4, {r2, r3}
 *   @0x135c5c pop {r4, pc}
 *   @0x135c60 eoreq r9, r11, r12, lsr #8
 *
 * ══ §316/373 F_AudioSoundGetListenerMask(RValue&, CInstance*, CInstance*, int, RValue*)  0x135cf4  size 76  19 条（0x135cf4..0x135d40）
 * @func 0x135cf4 0x135d40  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Audio_SoundGetListenerMask(int)
 * 字段偏移 top8: 0x40×1 / 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x135cf4 ldr r3, [pc, #0x40]
 *   @0x135cf8 push {r4, lr}
 *   @0x135cfc ldr r3, [pc, r3]
 *   @0x135d00 mov r4, r0
 *   @0x135d04 ldrb r1, [r3]
 *   @0x135d08 cmp r1, #0
 *   @0x135d0c popne {r4, pc}
 *   @0x135d10 str r1, [r0, #0xc]
 *   @0x135d14 ldr r0, [sp, #0x8]
 *   @0x135d18 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x135d1c bl 0x2183dc <_Z26Audio_SoundGetListenerMaski>
 *   @0x135d20 vmov s15, r0
 *   @0x135d24 vcvt.f64.u32 d7, s15
 *   @0x135d28 vmov r0, r1, d7
 *   @0x135d2c vmov r2, s14
 *   @0x135d30 mov r3, r1
 *   @0x135d34 stm r4, {r2, r3}
 *   @0x135d38 pop {r4, pc}
 *   @0x135d3c eoreq r9, r11, r0, asr r3
 *
 * ══ §317/373 F_AudioEmitterGetListenerMask(RValue&, CInstance*, CInstance*, int, RValue*)  0x135d88  size 76  19 条（0x135d88..0x135dd4）
 * @func 0x135d88 0x135dd4  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Audio_EmitterGetListenerMask(int)
 * 字段偏移 top8: 0x40×1 / 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x135d88 ldr r3, [pc, #0x40]
 *   @0x135d8c push {r4, lr}
 *   @0x135d90 ldr r3, [pc, r3]
 *   @0x135d94 mov r4, r0
 *   @0x135d98 ldrb r1, [r3]
 *   @0x135d9c cmp r1, #0
 *   @0x135da0 popne {r4, pc}
 *   @0x135da4 str r1, [r0, #0xc]
 *   @0x135da8 ldr r0, [sp, #0x8]
 *   @0x135dac bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x135db0 bl 0x2184b8 <_Z28Audio_EmitterGetListenerMaski>
 *   @0x135db4 vmov s15, r0
 *   @0x135db8 vcvt.f64.u32 d7, s15
 *   @0x135dbc vmov r0, r1, d7
 *   @0x135dc0 vmov r2, s14
 *   @0x135dc4 mov r3, r1
 *   @0x135dc8 stm r4, {r2, r3}
 *   @0x135dcc pop {r4, pc}
 *   @0x135dd0 .word 0x002b92bc
 *
 * ══ §318/373 F_AudioGetListenerInfo(RValue&, CInstance*, CInstance*, int, RValue*)  0x135e8c  size 76  19 条（0x135e8c..0x135ed8）
 * @func 0x135e8c 0x135ed8  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Audio_GetListenerInfo(int)
 * 字段偏移 top8: 0x40×1 / 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x135e8c ldr r3, [pc, #0x40]
 *   @0x135e90 push {r4, lr}
 *   @0x135e94 ldr r3, [pc, r3]
 *   @0x135e98 mov r4, r0
 *   @0x135e9c ldrb r1, [r3]
 *   @0x135ea0 cmp r1, #0
 *   @0x135ea4 popne {r4, pc}
 *   @0x135ea8 str r1, [r0, #0xc]
 *   @0x135eac ldr r0, [sp, #0x8]
 *   @0x135eb0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x135eb4 bl 0x2185a4 <_Z21Audio_GetListenerInfoi>
 *   @0x135eb8 vmov s15, r0
 *   @0x135ebc vcvt.f64.s32 d7, s15
 *   @0x135ec0 vmov r0, r1, d7
 *   @0x135ec4 vmov r2, s14
 *   @0x135ec8 mov r3, r1
 *   @0x135ecc stm r4, {r2, r3}
 *   @0x135ed0 pop {r4, pc}
 *   @0x135ed4 .word 0x002b91b8
 *
 * ══ §319/373 F_AudioSyncGroupGetTrackPos(RValue&, CInstance*, CInstance*, int, RValue*)  0x1360dc  size 76  19 条（0x1360dc..0x136128）
 * @func 0x1360dc 0x136128  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Audio_SyncGroupGetTrackPos(int)
 * 字段偏移 top8: 0x40×1 / 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1360dc ldr r3, [pc, #0x40]
 *   @0x1360e0 push {r4, lr}
 *   @0x1360e4 ldr r3, [pc, r3]
 *   @0x1360e8 mov r4, r0
 *   @0x1360ec ldrb r1, [r3]
 *   @0x1360f0 cmp r1, #0
 *   @0x1360f4 popne {r4, pc}
 *   @0x1360f8 str r1, [r0, #0xc]
 *   @0x1360fc ldr r0, [sp, #0x8]
 *   @0x136100 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x136104 bl 0x21d62c <_Z26Audio_SyncGroupGetTrackPosi>
 *   @0x136108 vmov s15, r0
 *   @0x13610c vcvt.f64.f32 d7, s15
 *   @0x136110 vmov r0, r1, d7
 *   @0x136114 vmov r2, s14
 *   @0x136118 mov r3, r1
 *   @0x13611c stm r4, {r2, r3}
 *   @0x136120 pop {r4, pc}
 *   @0x136124 eoreq r8, r11, r8, ror #30
 *
 * ══ §320/373 F_AudioSyncGroupIsPlaying(RValue&, CInstance*, CInstance*, int, RValue*)  0x13615c  size 76  19 条（0x13615c..0x1361a8）
 * @func 0x13615c 0x1361a8  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Audio_SyncGroupIsPlaying(int)
 * 字段偏移 top8: 0x40×1 / 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13615c ldr r3, [pc, #0x40]
 *   @0x136160 push {r4, lr}
 *   @0x136164 ldr r3, [pc, r3]
 *   @0x136168 mov r4, r0
 *   @0x13616c ldrb r1, [r3]
 *   @0x136170 cmp r1, #0
 *   @0x136174 popne {r4, pc}
 *   @0x136178 str r1, [r0, #0xc]
 *   @0x13617c ldr r0, [sp, #0x8]
 *   @0x136180 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x136184 bl 0x21d640 <_Z24Audio_SyncGroupIsPlayingi>
 *   @0x136188 vmov s15, r0
 *   @0x13618c vcvt.f64.u32 d7, s15
 *   @0x136190 vmov r0, r1, d7
 *   @0x136194 vmov r2, s14
 *   @0x136198 mov r3, r1
 *   @0x13619c stm r4, {r2, r3}
 *   @0x1361a0 pop {r4, pc}
 *   @0x1361a4 eoreq r8, r11, r8, ror #29
 *
 * ══ §321/373 F_AudioCreateStream(RValue&, CInstance*, CInstance*, int, RValue*)  0x13643c  size 76  19 条（0x13643c..0x136488）
 * @func 0x13643c 0x13649c  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int) / Audio_CreateStream(char const*)
 * 字段偏移 top8: 0x40×1 / 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13643c ldr r3, [pc, #0x40]
 *   @0x136440 push {r4, lr}
 *   @0x136444 ldr r3, [pc, r3]
 *   @0x136448 mov r4, r0
 *   @0x13644c ldrb r1, [r3]
 *   @0x136450 cmp r1, #0
 *   @0x136454 popne {r4, pc}
 *   @0x136458 str r1, [r0, #0xc]
 *   @0x13645c ldr r0, [sp, #0x8]
 *   @0x136460 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x136464 bl 0x21d6dc <_Z18Audio_CreateStreamPKc>
 *   @0x136468 vmov s15, r0
 *   @0x13646c vcvt.f64.s32 d7, s15
 *   @0x136470 vmov r0, r1, d7
 *   @0x136474 vmov r2, s14
 *   @0x136478 mov r3, r1
 *   @0x13647c stm r4, {r2, r3}
 *   @0x136480 pop {r4, pc}
 *   @0x136484 eoreq r8, r11, r8, lsl #24
 *
 * ══ §322/373 F_AudioDestroyStream(RValue&, CInstance*, CInstance*, int, RValue*)  0x136488  size 76  19 条（0x136488..0x1364d4）
 * @func 0x136488 0x1364d4  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Audio_DestroyStream(int)
 * 字段偏移 top8: 0x40×1 / 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x136488 ldr r3, [pc, #0x40]
 *   @0x13648c push {r4, lr}
 *   @0x136490 ldr r3, [pc, r3]
 *   @0x136494 mov r4, r0
 *   @0x136498 ldrb r1, [r3]
 *   @0x13649c cmp r1, #0
 *   @0x1364a0 popne {r4, pc}
 *   @0x1364a4 str r1, [r0, #0xc]
 *   @0x1364a8 ldr r0, [sp, #0x8]
 *   @0x1364ac bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1364b0 bl 0x21d9a8 <_Z19Audio_DestroyStreami>
 *   @0x1364b4 vmov s15, r0
 *   @0x1364b8 vcvt.f64.s32 d7, s15
 *   @0x1364bc vmov r0, r1, d7
 *   @0x1364c0 vmov r2, s14
 *   @0x1364c4 mov r3, r1
 *   @0x1364c8 stm r4, {r2, r3}
 *   @0x1364cc pop {r4, pc}
 *   @0x1364d0 .word 0x002b8bbc
 *
 * ══ §323/373 F_FilenameName(RValue&, CInstance*, CInstance*, int, RValue*)  0x1387e8  size 76  19 条（0x1387e8..0x138834）
 * @func 0x1387e8 0x138848  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int) / ExtractFileName(char const*) / YYCreateString(RValue*, char const*)
 * 字段偏移 top8: 0x10×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1387e8 push {r3, r4, r5, lr}
 *   @0x1387ec mov r1, #0
 *   @0x1387f0 mov r4, r0
 *   @0x1387f4 ldr r0, [sp, #0x10]
 *   @0x1387f8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1387fc mov r3, #0
 *   @0x138800 mov r2, #1
 *   @0x138804 str r3, [r4]
 *   @0x138808 str r2, [r4, #0xc]
 *   @0x13880c cmp r0, r3
 *   @0x138810 popeq {r3, r4, r5, pc}
 *   @0x138814 bl 0x214fe0 <_Z15ExtractFileNamePKc>
 *   @0x138818 mov r5, r0
 *   @0x13881c mov r0, r4
 *   @0x138820 mov r1, r5
 *   @0x138824 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x138828 mov r0, r5
 *   @0x13882c pop {r3, r4, r5, lr}
 *   @0x138830 b 0xcef90 <_Z6YYFreePKv>
 *
 * ══ §324/373 F_FilenameDrive(RValue&, CInstance*, CInstance*, int, RValue*)  0x138834  size 76  19 条（0x138834..0x138880）
 * @func 0x138834 0x138894  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int) / ExtractFileDrive(char const*) / YYCreateString(RValue*, char const*)
 * 字段偏移 top8: 0x10×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x138834 push {r3, r4, r5, lr}
 *   @0x138838 mov r1, #0
 *   @0x13883c mov r4, r0
 *   @0x138840 ldr r0, [sp, #0x10]
 *   @0x138844 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x138848 mov r3, #0
 *   @0x13884c mov r2, #1
 *   @0x138850 str r3, [r4]
 *   @0x138854 str r2, [r4, #0xc]
 *   @0x138858 cmp r0, r3
 *   @0x13885c popeq {r3, r4, r5, pc}
 *   @0x138860 bl 0x214fdc <_Z16ExtractFileDrivePKc>
 *   @0x138864 mov r5, r0
 *   @0x138868 mov r0, r4
 *   @0x13886c mov r1, r5
 *   @0x138870 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x138874 mov r0, r5
 *   @0x138878 pop {r3, r4, r5, lr}
 *   @0x13887c b 0xcef90 <_Z6YYFreePKv>
 *
 * ══ §325/373 F_FilenameExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x138880  size 76  19 条（0x138880..0x1388cc）
 * @func 0x138880 0x1388cc  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int) / ExtractFileExt(char const*) / YYCreateString(RValue*, char const*)
 * 字段偏移 top8: 0x10×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x138880 push {r3, r4, r5, lr}
 *   @0x138884 mov r1, #0
 *   @0x138888 mov r4, r0
 *   @0x13888c ldr r0, [sp, #0x10]
 *   @0x138890 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x138894 mov r3, #0
 *   @0x138898 mov r2, #1
 *   @0x13889c str r3, [r4]
 *   @0x1388a0 str r2, [r4, #0xc]
 *   @0x1388a4 cmp r0, r3
 *   @0x1388a8 popeq {r3, r4, r5, pc}
 *   @0x1388ac bl 0x215008 <_Z14ExtractFileExtPKc>
 *   @0x1388b0 mov r5, r0
 *   @0x1388b4 mov r0, r4
 *   @0x1388b8 mov r1, r5
 *   @0x1388bc bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x1388c0 mov r0, r5
 *   @0x1388c4 pop {r3, r4, r5, lr}
 *   @0x1388c8 b 0xcef90 <_Z6YYFreePKv>
 *
 * ══ §326/373 F_EnvironmentGetVariable(RValue&, CInstance*, CInstance*, int, RValue*)  0x138b54  size 76  19 条（0x138b54..0x138ba0）
 * @func 0x138b54 0x138ba0  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int) / EnvironmentGetVariable(char*) / YYCreateString(RValue*, char const*)
 * 字段偏移 top8: 0x10×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x138b54 push {r3, r4, r5, lr}
 *   @0x138b58 mov r1, #0
 *   @0x138b5c ldr r3, [sp, #0x10]
 *   @0x138b60 mov r2, #1
 *   @0x138b64 str r1, [r0]
 *   @0x138b68 mov r4, r0
 *   @0x138b6c str r2, [r0, #0xc]
 *   @0x138b70 mov r0, r3
 *   @0x138b74 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x138b78 cmp r0, #0
 *   @0x138b7c popeq {r3, r4, r5, pc}
 *   @0x138b80 bl 0x215284 <_Z22EnvironmentGetVariablePc>
 *   @0x138b84 mov r5, r0
 *   @0x138b88 mov r0, r4
 *   @0x138b8c mov r1, r5
 *   @0x138b90 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x138b94 mov r0, r5
 *   @0x138b98 pop {r3, r4, r5, lr}
 *   @0x138b9c b 0xcef90 <_Z6YYFreePKv>
 *
 * ══ §327/373 F_FileClose(RValue&, CInstance*, CInstance*, int, RValue*)  0x139858  size 76  19 条（0x139858..0x1398a4）
 * @func 0x139858 0x1398a4  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6850 / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x8×2 / 0x38×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x139858 push {r4, r5, r6, lr}
 *   @0x13985c ldr r4, [pc, #0x38]
 *   @0x139860 ldr r4, [pc, r4]
 *   @0x139864 ldr r3, [r4]
 *   @0x139868 cmp r3, #0
 *   @0x13986c popeq {r4, r5, r6, pc}
 *   @0x139870 ldr r5, [pc, #0x28]
 *   @0x139874 mov r6, #0
 *   @0x139878 ldr r5, [pc, r5]
 *   @0x13987c ldr r0, [r5, #0x8]
 *   @0x139880 bl 0xb6850 <fclose@plt>
 *   @0x139884 str r6, [r5, #0x8]
 *   @0x139888 ldr r0, [r5]
 *   @0x13988c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x139890 str r6, [r5]
 *   @0x139894 str r6, [r4]
 *   @0x139898 pop {r4, r5, r6, pc}
 *   @0x13989c eoreq r5, r11, r0, lsl r10
 *   @0x1398a0 .word 0x002b59fc
 *
 * ══ §328/373 F_IniSectionDelete(RValue&, CInstance*, CInstance*, int, RValue*)  0x13a320  size 76  19 条（0x13a320..0x13a36c）
 * @func 0x13a320 0x13a36c  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)
 * 字段偏移 top8: 0x8×1 / 0x2c×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13a320 push {r3, lr}
 *   @0x13a324 mov r1, #0
 *   @0x13a328 ldr r0, [sp, #0x8]
 *   @0x13a32c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x13a330 ldr r3, [pc, #0x2c]
 *   @0x13a334 ldr r3, [pc, r3]
 *   @0x13a338 mov r1, r0
 *   @0x13a33c ldr r0, [r3]
 *   @0x13a340 cmp r0, #0
 *   @0x13a344 beq 0x13a350 <_Z18F_IniSectionDeleteR6RValueP9CInstanceS2_iPS_+0x30>
 *   @0x13a348 pop {r3, lr}
 *   @0x13a34c b 0x235c2c <_ZN7IniFile13DeleteSectionEPKc>
 *   @0x13a350 mov r1, r0
 *   @0x13a354 ldr r0, [pc, #0xc]
 *   @0x13a358 pop {r3, lr}
 *   @0x13a35c add r0, pc, r0
 *   @0x13a360 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x13a364 eoreq r4, r11, r0, ror #30
 *   @0x13a368 eoreq r5, r0, r4, lsr pc
 *
 * ══ §329/373 F_ActionSetScore(RValue&, CInstance*, CInstance*, int, RValue*)  0x13d660  size 76  19 条（0x13d660..0x13d6ac）
 * @func 0x13d660 0x13d6ac  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x13d674→0x47a174, 0x13d688→0x54294c
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x28×2 / 0x8×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13d660 push {r3, lr}
 *   @0x13d664 mov r1, #0
 *   @0x13d668 ldr r0, [sp, #0x8]
 *   @0x13d66c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13d670 ldr r3, [pc, #0x28]
 *   @0x13d674 ldr r2, [pc, #0x28]
 *   @0x13d678 add r3, pc, r3
 *   @0x13d67c ldr r2, [r3, r2]
 *   @0x13d680 ldrb r2, [r2]
 *   @0x13d684 cmp r2, #0
 *   @0x13d688 ldr r2, [pc, #0x18]
 *   @0x13d68c ldr r3, [r3, r2]
 *   @0x13d690 ldrne r2, [r3]
 *   @0x13d694 addne r0, r0, r2
 *   @0x13d698 str r0, [r3]
 *   @0x13d69c pop {r3, pc}
 *   @0x13d6a0 .word 0x002b45d8
 *   @0x13d6a4 .word 0xffffbeec
 *   @0x13d6a8 .word 0xffffce34
 *
 * ══ §330/373 YYGML_action_move_point(CInstance*, float, float, float)  0x1415e8  size 76  19 条（0x1415e8..0x141634）
 * @func 0x1415e8 0x141648  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x40×1 / 0x-4×1
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1415e8 ldr r12, [pc, #0x40]
 *   @0x1415ec vmov s14, r1
 *   @0x1415f0 str r4, [sp, #-0x4]!
 *   @0x1415f4 ldr r12, [pc, r12]
 *   @0x1415f8 vmov s15, r2
 *   @0x1415fc ldrb r12, [r12]
 *   @0x141600 cmp r12, #0
 *   @0x141604 bne 0x141610 <_Z23YYGML_action_move_pointP9CInstancefff+0x28>
 *   @0x141608 ldr r4, [sp], #4
 *   @0x14160c b 0x1c97ec <_Z19Command_MoveTowardsP9CInstancefff>
 *   @0x141610 vldr s12, [r0, #180]
 *   @0x141614 vldr s13, [r0, #184]
 *   @0x141618 vadd.f32 s12, s14, s12
 *   @0x14161c ldr r4, [sp], #4
 *   @0x141620 vadd.f32 s13, s15, s13
 *   @0x141624 vmov r1, s12
 *   @0x141628 vmov r2, s13
 *   @0x14162c b 0x1c97ec <_Z19Command_MoveTowardsP9CInstancefff>
 *   @0x141630 eoreq r12, r10, r8, asr #10
 *
 * ══ §331/373 F_ActionIfVariable(RValue&, CInstance*, CInstance*, int, RValue*)  0x141d90  size 76  19 条（0x141d90..0x141ddc）
 * @func 0x141d90 0x141ddc  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGML_action_if_variable(RValue const&, RValue const&, int)
 * 字段偏移 top8: 0x10×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x141d90 push {r3, r4, r5, lr}
 *   @0x141d94 mov r1, #2
 *   @0x141d98 ldr r5, [sp, #0x10]
 *   @0x141d9c mov r3, #0
 *   @0x141da0 mov r4, r0
 *   @0x141da4 str r3, [r0, #0xc]
 *   @0x141da8 mov r0, r5
 *   @0x141dac bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x141db0 add r1, r5, #16
 *   @0x141db4 mov r2, r0
 *   @0x141db8 mov r0, r5
 *   @0x141dbc bl 0x141d1c <_Z24YYGML_action_if_variableRK6RValueS1_i>
 *   @0x141dc0 vmov s15, r0
 *   @0x141dc4 vcvt.f64.u32 d7, s15
 *   @0x141dc8 vmov r0, r1, d7
 *   @0x141dcc vmov r2, s14
 *   @0x141dd0 mov r3, r1
 *   @0x141dd4 stm r4, {r2, r3}
 *   @0x141dd8 pop {r3, r4, r5, pc}
 *
 * ══ §332/373 F_PhysicsFixtureLinearDamping(RValue&, CInstance*, CInstance*, int, RValue*)  0x14be40  size 76  19 条（0x14be40..0x14be8c）
 * @func 0x14be40 0x14bea0  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CPhysicsFixtureFactory::FindFixture(unsigned int) / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x10×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14be40 push {r3, r4, r5, lr}
 *   @0x14be44 mov r1, #0
 *   @0x14be48 ldr r4, [sp, #0x10]
 *   @0x14be4c mov r0, r4
 *   @0x14be50 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14be54 bl 0x236404 <_ZN22CPhysicsFixtureFactory11FindFixtureEj>
 *   @0x14be58 subs r5, r0, #0
 *   @0x14be5c beq 0x14be74 <_Z29F_PhysicsFixtureLinearDampingR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x14be60 mov r0, r4
 *   @0x14be64 mov r1, #1
 *   @0x14be68 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14be6c str r0, [r5]
 *   @0x14be70 pop {r3, r4, r5, pc}
 *   @0x14be74 ldr r0, [pc, #0xc]
 *   @0x14be78 mov r1, r5
 *   @0x14be7c pop {r3, r4, r5, lr}
 *   @0x14be80 add r0, pc, r0
 *   @0x14be84 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14be88 andseq r7, pc, r8, lsr #30
 *
 * ══ §333/373 F_PhysicsFixtureAngularDamping(RValue&, CInstance*, CInstance*, int, RValue*)  0x14be8c  size 76  19 条（0x14be8c..0x14bed8）
 * @func 0x14be8c 0x14bed8  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CPhysicsFixtureFactory::FindFixture(unsigned int) / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x10×1 / 0x4×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14be8c push {r3, r4, r5, lr}
 *   @0x14be90 mov r1, #0
 *   @0x14be94 ldr r4, [sp, #0x10]
 *   @0x14be98 mov r0, r4
 *   @0x14be9c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14bea0 bl 0x236404 <_ZN22CPhysicsFixtureFactory11FindFixtureEj>
 *   @0x14bea4 subs r5, r0, #0
 *   @0x14bea8 beq 0x14bec0 <_Z30F_PhysicsFixtureAngularDampingR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x14beac mov r0, r4
 *   @0x14beb0 mov r1, #1
 *   @0x14beb4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14beb8 str r0, [r5, #0x4]
 *   @0x14bebc pop {r3, r4, r5, pc}
 *   @0x14bec0 ldr r0, [pc, #0xc]
 *   @0x14bec4 mov r1, r5
 *   @0x14bec8 pop {r3, r4, r5, lr}
 *   @0x14becc add r0, pc, r0
 *   @0x14bed0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14bed4 ldrsbeq r7, [pc], -r12
 *
 * ══ §334/373 F_PhysicsFixtureSetAwake(RValue&, CInstance*, CInstance*, int, RValue*)  0x14bf14  size 76  19 条（0x14bf14..0x14bf60）
 * @func 0x14bf14 0x14bf60  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CPhysicsFixtureFactory::FindFixture(unsigned int) / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x10×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14bf14 push {r3, r4, r5, lr}
 *   @0x14bf18 mov r1, #0
 *   @0x14bf1c ldr r4, [sp, #0x10]
 *   @0x14bf20 mov r0, r4
 *   @0x14bf24 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14bf28 bl 0x236404 <_ZN22CPhysicsFixtureFactory11FindFixtureEj>
 *   @0x14bf2c subs r5, r0, #0
 *   @0x14bf30 beq 0x14bf48 <_Z24F_PhysicsFixtureSetAwakeR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x14bf34 mov r0, r4
 *   @0x14bf38 mov r1, #1
 *   @0x14bf3c bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x14bf40 strb r0, [r5, #0x8]
 *   @0x14bf44 pop {r3, r4, r5, pc}
 *   @0x14bf48 ldr r0, [pc, #0xc]
 *   @0x14bf4c mov r1, r5
 *   @0x14bf50 pop {r3, r4, r5, lr}
 *   @0x14bf54 add r0, pc, r0
 *   @0x14bf58 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14bf5c andseq r7, pc, r4, asr lr
 *
 * ══ §335/373 F_YoYo_CloudSynchronise(RValue&, CInstance*, CInstance*, int, RValue*)  0x156b04  size 76  19 条（0x156b04..0x156b50）
 * @func 0x156b04 0x156b50  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Cloud_Synchronise(int (*)(HTTP_REQ_CONTEXT*, void*, int*))
 * 字段偏移 top8: 0x3c×1 / 0x2c×1 / 0xc×1 / 0x4×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x156b04 ldr r2, [pc, #0x3c]
 *   @0x156b08 push {r3, r4, r5, lr}
 *   @0x156b0c ldr r2, [pc, r2]
 *   @0x156b10 mov r4, r0
 *   @0x156b14 mov r3, #0
 *   @0x156b18 ldr r0, [pc, #0x2c]
 *   @0x156b1c str r3, [r4]
 *   @0x156b20 ldr r5, [r2]
 *   @0x156b24 ldr r0, [pc, r0]
 *   @0x156b28 str r3, [r4, #0xc]
 *   @0x156b2c str r3, [r4, #0x4]
 *   @0x156b30 bl 0x161390 <_Z17Cloud_SynchronisePFiP16HTTP_REQ_CONTEXTPvPiE>
 *   @0x156b34 vmov s15, r5
 *   @0x156b38 vcvt.f64.s32 d7, s15
 *   @0x156b3c vmov r2, r3, d7
 *   @0x156b40 stm r4, {r2, r3}
 *   @0x156b44 pop {r3, r4, r5, pc}
 *   @0x156b48 eoreq r8, r9, r12, ror #14
 *   @0x156b4c eoreq r9, r9, r4, lsr r0
 *
 * ══ §336/373 F_YoYo_MouseCheckButton(RValue&, CInstance*, CInstance*, int, RValue*)  0x15e690  size 76  19 条（0x15e690..0x15e6dc）
 * @func 0x15e690 0x15e6f0  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2
 * 字段偏移 top8: 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15e690 push {r4, r5, r6, r7, r8, lr}
 *   @0x15e694 mov r5, r0
 *   @0x15e698 ldr r4, [sp, #0x18]
 *   @0x15e69c mov r7, r1
 *   @0x15e6a0 mov r1, #1
 *   @0x15e6a4 mov r8, r2
 *   @0x15e6a8 mov r0, r4
 *   @0x15e6ac bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x15e6b0 mov r1, #0
 *   @0x15e6b4 mov r6, r0
 *   @0x15e6b8 mov r0, r4
 *   @0x15e6bc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x15e6c0 mov r1, r7
 *   @0x15e6c4 mov r2, r8
 *   @0x15e6c8 mov r3, r6
 *   @0x15e6cc str r0, [sp, #0x18]
 *   @0x15e6d0 mov r0, r5
 *   @0x15e6d4 pop {r4, r5, r6, r7, r8, lr}
 *   @0x15e6d8 b 0x160b2c <_Z25F_CheckMouseButton_CommonR6RValueP9CInstanceS2_ii>
 *
 * ══ §337/373 F_YoYo_MouseCheckButtonPressed(RValue&, CInstance*, CInstance*, int, RValue*)  0x15e6dc  size 76  19 条（0x15e6dc..0x15e728）
 * @func 0x15e6dc 0x15e73c  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2
 * 字段偏移 top8: 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15e6dc push {r4, r5, r6, r7, r8, lr}
 *   @0x15e6e0 mov r5, r0
 *   @0x15e6e4 ldr r4, [sp, #0x18]
 *   @0x15e6e8 mov r7, r1
 *   @0x15e6ec mov r1, #1
 *   @0x15e6f0 mov r8, r2
 *   @0x15e6f4 mov r0, r4
 *   @0x15e6f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x15e6fc mov r1, #0
 *   @0x15e700 mov r6, r0
 *   @0x15e704 mov r0, r4
 *   @0x15e708 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x15e70c mov r1, r7
 *   @0x15e710 mov r2, r8
 *   @0x15e714 mov r3, r6
 *   @0x15e718 str r0, [sp, #0x18]
 *   @0x15e71c mov r0, r5
 *   @0x15e720 pop {r4, r5, r6, r7, r8, lr}
 *   @0x15e724 b 0x160c0c <_Z32F_CheckMouseButtonPressed_CommonR6RValueP9CInstanceS2_ii>
 *
 * ══ §338/373 F_YoYo_MouseCheckButtonReleased(RValue&, CInstance*, CInstance*, int, RValue*)  0x15e728  size 76  19 条（0x15e728..0x15e774）
 * @func 0x15e728 0x15e774  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2
 * 字段偏移 top8: 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15e728 push {r4, r5, r6, r7, r8, lr}
 *   @0x15e72c mov r5, r0
 *   @0x15e730 ldr r4, [sp, #0x18]
 *   @0x15e734 mov r7, r1
 *   @0x15e738 mov r1, #1
 *   @0x15e73c mov r8, r2
 *   @0x15e740 mov r0, r4
 *   @0x15e744 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x15e748 mov r1, #0
 *   @0x15e74c mov r6, r0
 *   @0x15e750 mov r0, r4
 *   @0x15e754 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x15e758 mov r1, r7
 *   @0x15e75c mov r2, r8
 *   @0x15e760 mov r3, r6
 *   @0x15e764 str r0, [sp, #0x18]
 *   @0x15e768 mov r0, r5
 *   @0x15e76c pop {r4, r5, r6, r7, r8, lr}
 *   @0x15e770 b 0x160cec <_Z33F_CheckMouseButtonReleased_CommonR6RValueP9CInstanceS2_ii>
 *
 * ══ §339/373 YoYo_IncrementAchievement(char const*, unsigned int*)  0x1615f0  size 76  19 条（0x1615f0..0x16163c）
 * @func 0x1615f0 0x161650  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1 / 0x2c×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1615f0 push {r3, r4, r5, lr}
 *   @0x1615f4 mov r2, r0
 *   @0x1615f8 ldr r3, [pc, #0x34]
 *   @0x1615fc mov r4, r0
 *   @0x161600 mov r5, r1
 *   @0x161604 ldr r1, [pc, #0x2c]
 *   @0x161608 ldr r3, [pc, r3]
 *   @0x16160c add r1, pc, r1
 *   @0x161610 ldr r0, [r3]
 *   @0x161614 ldr r3, [r0]
 *   @0x161618 ldr r3, [r3, #0xc]
 *   @0x16161c blx r3
 *   @0x161620 mov r1, r4
 *   @0x161624 mov r2, r5
 *   @0x161628 mov r0, #3
 *   @0x16162c pop {r3, r4, r5, lr}
 *   @0x161630 b 0x159cc0 <_Z16CacheAchievement10eCacheTypePKcPj>
 *   @0x161634 eoreq r12, r8, r12, lsl #2
 *   @0x161638 andseq r8, lr, r0, lsr #10
 *
 * ══ §340/373 YoYo_CacheAchievement(char const*, unsigned int*)  0x16163c  size 76  19 条（0x16163c..0x161688）
 * @func 0x16163c 0x16169c  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1 / 0x2c×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16163c push {r3, r4, r5, lr}
 *   @0x161640 mov r2, r0
 *   @0x161644 ldr r3, [pc, #0x34]
 *   @0x161648 mov r4, r0
 *   @0x16164c mov r5, r1
 *   @0x161650 ldr r1, [pc, #0x2c]
 *   @0x161654 ldr r3, [pc, r3]
 *   @0x161658 add r1, pc, r1
 *   @0x16165c ldr r0, [r3]
 *   @0x161660 ldr r3, [r0]
 *   @0x161664 ldr r3, [r3, #0xc]
 *   @0x161668 blx r3
 *   @0x16166c mov r1, r4
 *   @0x161670 mov r2, r5
 *   @0x161674 mov r0, #2
 *   @0x161678 pop {r3, r4, r5, lr}
 *   @0x16167c b 0x159cc0 <_Z16CacheAchievement10eCacheTypePKcPj>
 *   @0x161680 eoreq r12, r8, r0, asr #1
 *   @0x161684 ldrsheq r8, [lr], -r4
 *
 * ══ §341/373 YoYo_ScoreAchievement(char const*, unsigned int*)  0x161688  size 76  19 条（0x161688..0x1616d4）
 * @func 0x161688 0x1616d4  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1 / 0x2c×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161688 push {r3, r4, r5, lr}
 *   @0x16168c mov r2, r0
 *   @0x161690 ldr r3, [pc, #0x34]
 *   @0x161694 mov r4, r0
 *   @0x161698 mov r5, r1
 *   @0x16169c ldr r1, [pc, #0x2c]
 *   @0x1616a0 ldr r3, [pc, r3]
 *   @0x1616a4 add r1, pc, r1
 *   @0x1616a8 ldr r0, [r3]
 *   @0x1616ac ldr r3, [r0]
 *   @0x1616b0 ldr r3, [r3, #0xc]
 *   @0x1616b4 blx r3
 *   @0x1616b8 mov r1, r4
 *   @0x1616bc mov r2, r5
 *   @0x1616c0 mov r0, #1
 *   @0x1616c4 pop {r3, r4, r5, lr}
 *   @0x1616c8 b 0x159cc0 <_Z16CacheAchievement10eCacheTypePKcPj>
 *   @0x1616cc eoreq r12, r8, r4, ror r0
 *   @0x1616d0 andseq r8, lr, r0, asr #9
 *
 * ══ §342/373 GR_3D_Transform_Stack_Push()  0x163b30  size 76  19 条（0x163b30..0x163b7c）
 * @func 0x163b30 0x163b90  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_3D_Transform_Stack_Push()+0x20 / Graphics::GetMatrix(eMatrix, float*)
 * 字段偏移 top8: 0x38×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x163b30 push {r3, lr}
 *   @0x163b34 ldr r3, [pc, #0x38]
 *   @0x163b38 ldr r3, [pc, r3]
 *   @0x163b3c ldr r2, [r3]
 *   @0x163b40 cmp r2, #49
 *   @0x163b44 ble 0x163b50 <_Z26GR_3D_Transform_Stack_Pushv+0x20>
 *   @0x163b48 mov r0, #0
 *   @0x163b4c pop {r3, pc}
 *   @0x163b50 ldr r1, [pc, #0x20]
 *   @0x163b54 add r2, r2, #1
 *   @0x163b58 mov r0, #2
 *   @0x163b5c str r2, [r3]
 *   @0x163b60 ldr r1, [pc, r1]
 *   @0x163b64 add r1, r1, r2, lsl #6
 *   @0x163b68 bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf>
 *   @0x163b6c mov r0, #1
 *   @0x163b70 pop {r3, pc}
 *   @0x163b74 eoreq r12, r8, r12, lsr #11
 *   @0x163b78 eoreq r12, r8, r8, lsl #11
 *
 * ══ §343/373 _SetFogDistances()  0x1684d4  size 76  19 条（0x1684d4..0x168520）
 * @func 0x1684d4 0x168520  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RenderStateManager::SetRenderState(eRenderState, unsigned int)
 * 字段偏移 top8: 0x30×2 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1684d4 push {r4, lr}
 *   @0x1684d8 mov r1, #17
 *   @0x1684dc ldr r4, [pc, #0x30]
 *   @0x1684e0 ldr r3, [pc, #0x30]
 *   @0x1684e4 ldr r4, [pc, r4]
 *   @0x1684e8 ldr r3, [pc, r3]
 *   @0x1684ec mov r0, r4
 *   @0x1684f0 ldr r2, [r3]
 *   @0x1684f4 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x1684f8 ldr r3, [pc, #0x1c]
 *   @0x1684fc mov r0, r4
 *   @0x168500 mov r1, #18
 *   @0x168504 ldr r3, [pc, r3]
 *   @0x168508 pop {r4, lr}
 *   @0x16850c ldr r2, [r3]
 *   @0x168510 b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x168514 eoreq r5, r8, r4, lsl r8
 *   @0x168518 eoreq r7, r8, r0, lsr r12
 *   @0x16851c eoreq r7, r8, r8, lsl r12
 *
 * ══ §344/373 GR_Text_Set_HAlign(int)  0x172b30  size 76  19 条（0x172b30..0x172b7c）
 * @func 0x172b30 0x172b90  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x172b50→0x48ffd0, 0x172b64→0x48ffd0
 * 调用序列: 无
 * 字段偏移 top8: 0x38×1 / 0x20×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x172b30 cmp r0, #1
 *   @0x172b34 ldr r3, [pc, #0x38]
 *   @0x172b38 add r3, pc, r3
 *   @0x172b3c beq 0x172b64 <_Z18GR_Text_Set_HAligni+0x34>
 *   @0x172b40 cmp r0, #2
 *   @0x172b44 beq 0x172b64 <_Z18GR_Text_Set_HAligni+0x34>
 *   @0x172b48 cmp r0, #0
 *   @0x172b4c beq 0x172b64 <_Z18GR_Text_Set_HAligni+0x34>
 *   @0x172b50 ldr r1, [pc, #0x20]
 *   @0x172b54 mov r2, #0
 *   @0x172b58 ldr r3, [r3, r1]
 *   @0x172b5c str r2, [r3]
 *   @0x172b60 bx lr
 *   @0x172b64 ldr r2, [pc, #0xc]
 *   @0x172b68 ldr r3, [r3, r2]
 *   @0x172b6c str r0, [r3]
 *   @0x172b70 bx lr
 *   @0x172b74 eoreq pc, r7, r8, lsl r1
 *   @0x172b78 .word 0xffffe658
 *
 * ══ §345/373 GR_Text_Set_VAlign(int)  0x172b7c  size 76  19 条（0x172b7c..0x172bc8）
 * @func 0x172b7c 0x172bc8  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x172b9c→0x48ffcc, 0x172bb0→0x48ffcc
 * 调用序列: 无
 * 字段偏移 top8: 0x38×1 / 0x20×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x172b7c cmp r0, #1
 *   @0x172b80 ldr r3, [pc, #0x38]
 *   @0x172b84 add r3, pc, r3
 *   @0x172b88 beq 0x172bb0 <_Z18GR_Text_Set_VAligni+0x34>
 *   @0x172b8c cmp r0, #2
 *   @0x172b90 beq 0x172bb0 <_Z18GR_Text_Set_VAligni+0x34>
 *   @0x172b94 cmp r0, #0
 *   @0x172b98 beq 0x172bb0 <_Z18GR_Text_Set_VAligni+0x34>
 *   @0x172b9c ldr r1, [pc, #0x20]
 *   @0x172ba0 mov r2, #0
 *   @0x172ba4 ldr r3, [r3, r1]
 *   @0x172ba8 str r2, [r3]
 *   @0x172bac bx lr
 *   @0x172bb0 ldr r2, [pc, #0xc]
 *   @0x172bb4 ldr r3, [r3, r2]
 *   @0x172bb8 str r0, [r3]
 *   @0x172bbc bx lr
 *   @0x172bc0 eoreq pc, r7, r12, asr #1
 *   @0x172bc4 .word 0xffffe65c
 *
 * ══ §346/373 CheckGLVersion(int, int)  0x17d238  size 76  19 条（0x17d238..0x17d284）
 * @func 0x17d238 0x17d284  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x3c×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17d238 ldr r3, [pc, #0x3c]
 *   @0x17d23c ldr r3, [pc, r3]
 *   @0x17d240 ldr r3, [r3]
 *   @0x17d244 cmp r3, r0
 *   @0x17d248 bgt 0x17d258 <_Z14CheckGLVersionii+0x20>
 *   @0x17d24c beq 0x17d260 <_Z14CheckGLVersionii+0x28>
 *   @0x17d250 mov r0, #0
 *   @0x17d254 bx lr
 *   @0x17d258 mov r0, #1
 *   @0x17d25c bx lr
 *   @0x17d260 ldr r3, [pc, #0x18]
 *   @0x17d264 ldr r3, [pc, r3]
 *   @0x17d268 ldr r0, [r3]
 *   @0x17d26c cmp r0, r1
 *   @0x17d270 movlt r0, #0
 *   @0x17d274 movge r0, #1
 *   @0x17d278 bx lr
 *   @0x17d27c eoreq r3, r7, r4, asr #3
 *   @0x17d280 eoreq r3, r7, r0, lsr #3
 *
 * ══ §347/373 isSurfaceBoundAsTexture(int)  0x180a84  size 76  19 条（0x180a84..0x180ad0）
 * @func 0x180a84 0x180ad0  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x40×1 / 0x4×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x180a84 ldr r1, [pc, #0x40]
 *   @0x180a88 ldr r1, [pc, r1]
 *   @0x180a8c sub r3, r1, #4
 *   @0x180a90 add r1, r1, #28
 *   @0x180a94 ldr r2, [r3, #0x4]!
 *   @0x180a98 cmp r2, #0
 *   @0x180a9c beq 0x180ab4 <_Z23isSurfaceBoundAsTexturei+0x30>
 *   @0x180aa0 ldr r2, [r2, #0x18]
 *   @0x180aa4 cmp r2, #0
 *   @0x180aa8 beq 0x180ab4 <_Z23isSurfaceBoundAsTexturei+0x30>
 *   @0x180aac cmp r2, r0
 *   @0x180ab0 beq 0x180ac4 <_Z23isSurfaceBoundAsTexturei+0x40>
 *   @0x180ab4 cmp r3, r1
 *   @0x180ab8 bne 0x180a94 <_Z23isSurfaceBoundAsTexturei+0x10>
 *   @0x180abc mov r0, #0
 *   @0x180ac0 bx lr
 *   @0x180ac4 mov r0, #1
 *   @0x180ac8 bx lr
 *   @0x180acc .word 0x0026fab0
 *
 * ══ §348/373 LoadFile(char*, int&)  0x187bf8  size 76  19 条（0x187bf8..0x187c44）
 * @func 0x187bf8 0x187c44  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LoadSave::SaveFileExists(char const*) / LoadSave::BundleFileExists(char const*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x187bf8 push {r3, r4, r5, lr}
 *   @0x187bfc mov r3, #0
 *   @0x187c00 str r3, [r1]
 *   @0x187c04 mov r5, r0
 *   @0x187c08 mov r4, r1
 *   @0x187c0c bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc>
 *   @0x187c10 cmp r0, #0
 *   @0x187c14 mov r0, r5
 *   @0x187c18 bne 0x187c38 <_Z8LoadFilePcRi+0x40>
 *   @0x187c1c bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc>
 *   @0x187c20 cmp r0, #0
 *   @0x187c24 popeq {r3, r4, r5, pc}
 *   @0x187c28 mov r0, r5
 *   @0x187c2c mov r1, r4
 *   @0x187c30 pop {r3, r4, r5, lr}
 *   @0x187c34 b 0x18f848 <_ZN8LoadSave14ReadBundleFileEPKcPi>
 *   @0x187c38 mov r1, r4
 *   @0x187c3c pop {r3, r4, r5, lr}
 *   @0x187c40 b 0x18fb08 <_ZN8LoadSave12ReadSaveFileEPKcPi>
 *
 * ══ §349/373 IO_Quit()  0x18b8a0  size 76  19 条（0x18b8a0..0x18b8ec）
 * @func 0x18b8a0 0x18b8ec  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GamepadQuitM() / 0xb6850 / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x34×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18b8a0 push {r4, lr}
 *   @0x18b8a4 bl 0x1909f8 <_Z12GamepadQuitMv>
 *   @0x18b8a8 ldr r3, [pc, #0x34]
 *   @0x18b8ac ldr r3, [pc, r3]
 *   @0x18b8b0 ldr r0, [r3]
 *   @0x18b8b4 cmp r0, #0
 *   @0x18b8b8 beq 0x18b8c0 <_Z7IO_Quitv+0x20>
 *   @0x18b8bc bl 0xb6850 <fclose@plt>
 *   @0x18b8c0 ldr r4, [pc, #0x20]
 *   @0x18b8c4 ldr r4, [pc, r4]
 *   @0x18b8c8 ldr r0, [r4]
 *   @0x18b8cc cmp r0, #0
 *   @0x18b8d0 popeq {r4, pc}
 *   @0x18b8d4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x18b8d8 mov r3, #0
 *   @0x18b8dc str r3, [r4]
 *   @0x18b8e0 pop {r4, pc}
 *   @0x18b8e4 eoreq r4, r6, r0, lsr #26
 *   @0x18b8e8 mlaeq r6, r0, r2, r4
 *
 * ══ §350/373 CreateCompletedHTTPRequest(void*, void*)  0x18d9b8  size 76  19 条（0x18d9b8..0x18da04）
 * @func 0x18d9b8 0x18da04  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int) / HTTP_REQ_CONTEXT::HTTP_REQ_CONTEXT(char const*, int, int (*)(HTTP_REQ_CONTEXT*, void*, int*), void (*)(HTTP_REQ_CONTEXT*), void*, bool)
 * 字段偏移 top8: 0x4×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18d9b8 push {r4, r5, r6, lr}
 *   @0x18d9bc mov r5, r0
 *   @0x18d9c0 sub sp, sp, #16
 *   @0x18d9c4 mov r0, #68
 *   @0x18d9c8 mov r6, r1
 *   @0x18d9cc bl 0x27c524 <_Znwj>
 *   @0x18d9d0 mov r12, #0
 *   @0x18d9d4 mov r3, r5
 *   @0x18d9d8 str r6, [sp, #0x4]
 *   @0x18d9dc mov r1, r12
 *   @0x18d9e0 str r12, [sp]
 *   @0x18d9e4 mov r2, r12
 *   @0x18d9e8 str r12, [sp, #0x8]
 *   @0x18d9ec mov r4, r0
 *   @0x18d9f0 bl 0x18d834 <_ZN16HTTP_REQ_CONTEXTC2EPKciPFiPS_PvPiEPFvS2_ES3_b>
 *   @0x18d9f4 mov r3, #7
 *   @0x18d9f8 str r3, [r4, #0xc]
 *   @0x18d9fc add sp, sp, #16
 *   @0x18da00 pop {r4, r5, r6, pc}
 *
 * ══ §351/373 LoadSave::fseek(_YYFILE*, long, int)  0x18de30  size 76  19 条（0x18de30..0x18de7c）
 * @func 0x18de30 0x18de7c  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18de30 cmp r2, #1
 *   @0x18de34 mov r3, r1
 *   @0x18de38 push {r4, lr}
 *   @0x18de3c mov r4, r0
 *   @0x18de40 beq 0x18de60 <_ZN8LoadSave5fseekEP7_YYFILEli+0x30>
 *   @0x18de44 cmp r2, #2
 *   @0x18de48 beq 0x18de60 <_ZN8LoadSave5fseekEP7_YYFILEli+0x30>
 *   @0x18de4c cmp r2, #0
 *   @0x18de50 beq 0x18de60 <_ZN8LoadSave5fseekEP7_YYFILEli+0x30>
 *   @0x18de54 ldr r3, [r4]
 *   @0x18de58 ldr r0, [r3, #0x1c]
 *   @0x18de5c pop {r4, pc}
 *   @0x18de60 ldr r0, [r4]
 *   @0x18de64 mov r1, r2
 *   @0x18de68 mov r2, r3
 *   @0x18de6c ldr r3, [r0]
 *   @0x18de70 ldr r3, [r3, #0x10]
 *   @0x18de74 blx r3
 *   @0x18de78 b 0x18de54 <_ZN8LoadSave5fseekEP7_YYFILEli+0x24>
 *
 * ══ §352/373 InitLLVM(SLLVMVars*)  0x199e5c  size 76  19 条（0x199e5c..0x199ea8）
 * @func 0x199e5c 0x199ea8  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×2 / 0x38×1 / 0x14×1 / 0x18×1 / 0x1c×1 / 0x4×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x199e5c ldr r2, [pc, #0x38]
 *   @0x199e60 mov r3, #0
 *   @0x199e64 ldr r12, [pc, #0x34]
 *   @0x199e68 ldr r1, [pc, #0x34]
 *   @0x199e6c ldr r2, [pc, r2]
 *   @0x199e70 ldr r12, [pc, r12]
 *   @0x199e74 str r2, [r0, #0x14]
 *   @0x199e78 ldr r1, [pc, r1]
 *   @0x199e7c str r12, [r0, #0x18]
 *   @0x199e80 str r3, [r0]
 *   @0x199e84 str r1, [r0, #0x1c]
 *   @0x199e88 str r3, [r0, #0x4]
 *   @0x199e8c str r3, [r0, #0x8]
 *   @0x199e90 str r3, [r0, #0xc]
 *   @0x199e94 str r3, [r0, #0x10]
 *   @0x199e98 bx lr
 *   @0x199e9c eoreq r6, r5, r0, lsr r8
 *   @0x199ea0 eoreq r6, r5, r0, lsr r8
 *   @0x199ea4 eoreq r6, r5, r12, lsr #16
 *
 * ══ §353/373 TestFree(CInstance*, float, float, int, bool)  0x19c6f4  size 76  19 条（0x19c6f4..0x19c740）
 * @func 0x19c6f4 0x19c740  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Command_IsMeeting(CInstance*, int, float, float)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19c6f4 cmn r3, #3
 *   @0x19c6f8 mov r12, r2
 *   @0x19c6fc push {r3, r4, r5, lr}
 *   @0x19c700 mov r4, r1
 *   @0x19c704 ldrb r5, [sp, #0x10]
 *   @0x19c708 beq 0x19c728 <_Z8TestFreeP9CInstanceffib+0x34>
 *   @0x19c70c mov r1, r3
 *   @0x19c710 mov r2, r4
 *   @0x19c714 mov r3, r12
 *   @0x19c718 bl 0x1ca9f8 <_Z17Command_IsMeetingP9CInstanceiff>
 *   @0x19c71c eor r0, r0, #1
 *   @0x19c720 uxtb r0, r0
 *   @0x19c724 pop {r3, r4, r5, pc}
 *   @0x19c728 cmp r5, #0
 *   @0x19c72c beq 0x19c738 <_Z8TestFreeP9CInstanceffib+0x44>
 *   @0x19c730 pop {r3, r4, r5, lr}
 *   @0x19c734 b 0x1caa1c <_Z15Command_IsEmptyP9CInstanceff>
 *   @0x19c738 pop {r3, r4, r5, lr}
 *   @0x19c73c b 0x1cab94 <_Z14Command_IsFreeP9CInstanceff>
 *
 * ══ §354/373 Eff_Create_Types()  0x1a24a8  size 76  19 条（0x1a24a8..0x1a24f4）
 * @func 0x1a24a8 0x1a24f4  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Eff_Create00() / Eff_Create01() / Eff_Create02() / Eff_Create03() / Eff_Create04() / Eff_Create05() / Eff_Create06() / Eff_Create07()
 * 字段偏移 top8: 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a24a8 push {r3, lr}
 *   @0x1a24ac mov r2, #1
 *   @0x1a24b0 ldr r3, [pc, #0x38]
 *   @0x1a24b4 ldr r3, [pc, r3]
 *   @0x1a24b8 strb r2, [r3]
 *   @0x1a24bc bl 0x1a0030 <_Z12Eff_Create00v>
 *   @0x1a24c0 bl 0x1a05e8 <_Z12Eff_Create01v>
 *   @0x1a24c4 bl 0x1a081c <_Z12Eff_Create02v>
 *   @0x1a24c8 bl 0x1a0a84 <_Z12Eff_Create03v>
 *   @0x1a24cc bl 0x1a0e38 <_Z12Eff_Create04v>
 *   @0x1a24d0 bl 0x1a1168 <_Z12Eff_Create05v>
 *   @0x1a24d4 bl 0x1a1564 <_Z12Eff_Create06v>
 *   @0x1a24d8 bl 0x1a17c0 <_Z12Eff_Create07v>
 *   @0x1a24dc bl 0x1a1a18 <_Z12Eff_Create08v>
 *   @0x1a24e0 bl 0x1a1c70 <_Z12Eff_Create09v>
 *   @0x1a24e4 bl 0x1a1eb0 <_Z12Eff_Create10v>
 *   @0x1a24e8 pop {r3, lr}
 *   @0x1a24ec b 0x1a2198 <_Z12Eff_Create11v>
 *   @0x1a24f0 eoreq lr, r4, r12, ror #5
 *
 * ══ §355/373 ParticleType_Sprite(int, int, bool, bool, bool)  0x1a31e0  size 76  19 条（0x1a31e0..0x1a322c）
 * @func 0x1a31e0 0x1a3240  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleType_Exists(int)
 * 字段偏移 top8: 0x4×2 / 0x18×1 / 0x1c×1 / 0x2×1 / 0x5×1 / 0x6×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a31e0 push {r4, r5, r6, r7, r8, lr}
 *   @0x1a31e4 mov r8, r1
 *   @0x1a31e8 mov r7, r2
 *   @0x1a31ec mov r6, r3
 *   @0x1a31f0 mov r5, r0
 *   @0x1a31f4 ldrb r4, [sp, #0x18]
 *   @0x1a31f8 bl 0x1a2e14 <_Z19ParticleType_Existsi>
 *   @0x1a31fc cmp r0, #0
 *   @0x1a3200 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x1a3204 ldr r12, [pc, #0x1c]
 *   @0x1a3208 ldr r12, [pc, r12]
 *   @0x1a320c ldr r3, [r12, #0x4]
 *   @0x1a3210 ldr r0, [r3, r5, lsl #2]
 *   @0x1a3214 str r8, [r0]
 *   @0x1a3218 strb r7, [r0, #0x4]
 *   @0x1a321c strb r6, [r0, #0x5]
 *   @0x1a3220 strb r4, [r0, #0x6]
 *   @0x1a3224 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1a3228 eoreq sp, r4, r4, lsr #11
 *
 * ══ §356/373 ParticleType_Size(int, float, float, float, float)  0x1a322c  size 76  19 条（0x1a322c..0x1a3278）
 * @func 0x1a322c 0x1a3278  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleType_Exists(int)
 * 字段偏移 top8: 0x20×1 / 0x4×1 / 0x2×1 / 0xc×1 / 0x10×1 / 0x14×1
 * VFP 指令 2 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a322c push {r3, r4, r5, r6, r7, lr}
 *   @0x1a3230 mov r7, r1
 *   @0x1a3234 mov r6, r2
 *   @0x1a3238 mov r4, r0
 *   @0x1a323c mov r5, r3
 *   @0x1a3240 bl 0x1a2e14 <_Z19ParticleType_Existsi>
 *   @0x1a3244 cmp r0, #0
 *   @0x1a3248 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1a324c ldr r12, [pc, #0x20]
 *   @0x1a3250 vldr s15, [sp, #24]
 *   @0x1a3254 ldr r12, [pc, r12]
 *   @0x1a3258 ldr r3, [r12, #0x4]
 *   @0x1a325c ldr r0, [r3, r4, lsl #2]
 *   @0x1a3260 vstr s15, [r0, #24]
 *   @0x1a3264 str r7, [r0, #0xc]
 *   @0x1a3268 str r6, [r0, #0x10]
 *   @0x1a326c str r5, [r0, #0x14]
 *   @0x1a3270 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1a3274 eoreq sp, r4, r8, asr r5
 *
 * ══ §357/373 ParticleType_Speed(int, float, float, float, float)  0x1a3368  size 76  19 条（0x1a3368..0x1a33b4）
 * @func 0x1a3368 0x1a33c8  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleType_Exists(int)
 * 字段偏移 top8: 0x20×1 / 0x4×1 / 0x2×1 / 0x3c×1 / 0x40×1 / 0x44×1
 * VFP 指令 2 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a3368 push {r3, r4, r5, r6, r7, lr}
 *   @0x1a336c mov r7, r1
 *   @0x1a3370 mov r6, r2
 *   @0x1a3374 mov r4, r0
 *   @0x1a3378 mov r5, r3
 *   @0x1a337c bl 0x1a2e14 <_Z19ParticleType_Existsi>
 *   @0x1a3380 cmp r0, #0
 *   @0x1a3384 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1a3388 ldr r12, [pc, #0x20]
 *   @0x1a338c vldr s15, [sp, #24]
 *   @0x1a3390 ldr r12, [pc, r12]
 *   @0x1a3394 ldr r3, [r12, #0x4]
 *   @0x1a3398 ldr r0, [r3, r4, lsl #2]
 *   @0x1a339c vstr s15, [r0, #72]
 *   @0x1a33a0 str r7, [r0, #0x3c]
 *   @0x1a33a4 str r6, [r0, #0x40]
 *   @0x1a33a8 str r5, [r0, #0x44]
 *   @0x1a33ac pop {r3, r4, r5, r6, r7, pc}
 *   @0x1a33b0 eoreq sp, r4, r12, lsl r4
 *
 * ══ §358/373 ParticleType_Direction(int, float, float, float, float)  0x1a33b4  size 76  19 条（0x1a33b4..0x1a3400）
 * @func 0x1a33b4 0x1a3414  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleType_Exists(int)
 * 字段偏移 top8: 0x20×1 / 0x4×1 / 0x2×1 / 0x4c×1 / 0x50×1 / 0x54×1
 * VFP 指令 2 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a33b4 push {r3, r4, r5, r6, r7, lr}
 *   @0x1a33b8 mov r7, r1
 *   @0x1a33bc mov r6, r2
 *   @0x1a33c0 mov r4, r0
 *   @0x1a33c4 mov r5, r3
 *   @0x1a33c8 bl 0x1a2e14 <_Z19ParticleType_Existsi>
 *   @0x1a33cc cmp r0, #0
 *   @0x1a33d0 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1a33d4 ldr r12, [pc, #0x20]
 *   @0x1a33d8 vldr s15, [sp, #24]
 *   @0x1a33dc ldr r12, [pc, r12]
 *   @0x1a33e0 ldr r3, [r12, #0x4]
 *   @0x1a33e4 ldr r0, [r3, r4, lsl #2]
 *   @0x1a33e8 vstr s15, [r0, #88]
 *   @0x1a33ec str r7, [r0, #0x4c]
 *   @0x1a33f0 str r6, [r0, #0x50]
 *   @0x1a33f4 str r5, [r0, #0x54]
 *   @0x1a33f8 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1a33fc .word 0x0024d3d0
 *
 * ══ §359/373 ParticleType_Color3(int, unsigned int, unsigned int, unsigned int)  0x1a361c  size 76  19 条（0x1a361c..0x1a3668）
 * @func 0x1a361c 0x1a3668  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleType_Exists(int)
 * 字段偏移 top8: 0x20×1 / 0x4×1 / 0x2×1 / 0x7c×1 / 0x80×1 / 0x84×1 / 0x78×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a361c push {r3, r4, r5, r6, r7, lr}
 *   @0x1a3620 mov r7, r1
 *   @0x1a3624 mov r6, r2
 *   @0x1a3628 mov r5, r3
 *   @0x1a362c mov r4, r0
 *   @0x1a3630 bl 0x1a2e14 <_Z19ParticleType_Existsi>
 *   @0x1a3634 cmp r0, #0
 *   @0x1a3638 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1a363c ldr r12, [pc, #0x20]
 *   @0x1a3640 mov r3, #2
 *   @0x1a3644 ldr r12, [pc, r12]
 *   @0x1a3648 ldr r2, [r12, #0x4]
 *   @0x1a364c ldr r0, [r2, r4, lsl #2]
 *   @0x1a3650 str r7, [r0, #0x7c]
 *   @0x1a3654 str r6, [r0, #0x80]
 *   @0x1a3658 str r5, [r0, #0x84]
 *   @0x1a365c str r3, [r0, #0x78]
 *   @0x1a3660 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1a3664 eoreq sp, r4, r8, ror #2
 *
 * ══ §360/373 Run_Stop()  0x1d3740  size 76  19 条（0x1d3740..0x1d378c）
 * @func 0x1d3740 0x1d378c  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Run_EndGame()
 * 字段偏移 top8: 0x2c×2 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d3740 ldr r1, [pc, #0x38]
 *   @0x1d3744 mov r0, #0
 *   @0x1d3748 push {r3, lr}
 *   @0x1d374c ldr r1, [pc, r1]
 *   @0x1d3750 ldr r2, [pc, #0x2c]
 *   @0x1d3754 ldr r3, [pc, #0x2c]
 *   @0x1d3758 ldrb r1, [r1]
 *   @0x1d375c ldr r2, [pc, r2]
 *   @0x1d3760 ldr r3, [pc, r3]
 *   @0x1d3764 cmp r1, r0
 *   @0x1d3768 strb r0, [r2]
 *   @0x1d376c strb r0, [r3]
 *   @0x1d3770 popne {r3, pc}
 *   @0x1d3774 bl 0x1d1b38 <_Z11Run_EndGamev>
 *   @0x1d3778 pop {r3, lr}
 *   @0x1d377c b 0x28fe4c <_Z9Terminatev>
 *   @0x1d3780 eoreq sp, r1, r8, lsr r4
 *   @0x1d3784 .word 0x0021d3b0
 *   @0x1d3788 mlaeq r1, r0, r4, r12
 *
 * ══ §361/373 F_GestureGetDragTime(RValue&, CInstance*, CInstance*, int, RValue*)  0x1d5068  size 76  19 条（0x1d5068..0x1d50b4）
 * @func 0x1d5068 0x1d50b4  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __floatdidf
 * 字段偏移 top8: 0x40×1 / 0xc×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d5068 ldr r3, [pc, #0x40]
 *   @0x1d506c mov r2, #0
 *   @0x1d5070 push {r4, lr}
 *   @0x1d5074 ldr r3, [pc, r3]
 *   @0x1d5078 str r2, [r0, #0xc]
 *   @0x1d507c mov r4, r0
 *   @0x1d5080 ldrd r0, r1, [r3]
 *   @0x1d5084 bl 0x319164 <__floatdidf>
 *   @0x1d5088 vldr d7, [pc, #24]
 *   @0x1d508c vmov d6, r0, r1
 *   @0x1d5090 vdiv.f64 d6, d6, d7
 *   @0x1d5094 vmov r0, r1, d6
 *   @0x1d5098 vmov r2, s12
 *   @0x1d509c mov r3, r1
 *   @0x1d50a0 stm r4, {r2, r3}
 *   @0x1d50a4 pop {r4, pc}
 *   @0x1d50a8 andeq r0, r0, r0
 *   @0x1d50ac smlawbmi lr, r0, r4, r8
 *   @0x1d50b0 eoreq r11, r1, r0, asr r11
 *
 * ══ §362/373 F_GestureGetDoubleTapTime(RValue&, CInstance*, CInstance*, int, RValue*)  0x1d5108  size 76  19 条（0x1d5108..0x1d5154）
 * @func 0x1d5108 0x1d5154  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __floatdidf
 * 字段偏移 top8: 0x40×1 / 0xc×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d5108 ldr r3, [pc, #0x40]
 *   @0x1d510c mov r2, #0
 *   @0x1d5110 push {r4, lr}
 *   @0x1d5114 ldr r3, [pc, r3]
 *   @0x1d5118 str r2, [r0, #0xc]
 *   @0x1d511c mov r4, r0
 *   @0x1d5120 ldrd r0, r1, [r3]
 *   @0x1d5124 bl 0x319164 <__floatdidf>
 *   @0x1d5128 vldr d7, [pc, #24]
 *   @0x1d512c vmov d6, r0, r1
 *   @0x1d5130 vdiv.f64 d6, d6, d7
 *   @0x1d5134 vmov r0, r1, d6
 *   @0x1d5138 vmov r2, s12
 *   @0x1d513c mov r3, r1
 *   @0x1d5140 stm r4, {r2, r3}
 *   @0x1d5144 pop {r4, pc}
 *   @0x1d5148 andeq r0, r0, r0
 *   @0x1d514c smlawbmi lr, r0, r4, r8
 *   @0x1d5150 .word 0x0021babc
 *
 * ══ §363/373 F_GestureGetRotateTime(RValue&, CInstance*, CInstance*, int, RValue*)  0x1d51f8  size 76  19 条（0x1d51f8..0x1d5244）
 * @func 0x1d51f8 0x1d5244  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __floatdidf
 * 字段偏移 top8: 0x40×1 / 0xc×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d51f8 ldr r3, [pc, #0x40]
 *   @0x1d51fc mov r2, #0
 *   @0x1d5200 push {r4, lr}
 *   @0x1d5204 ldr r3, [pc, r3]
 *   @0x1d5208 str r2, [r0, #0xc]
 *   @0x1d520c mov r4, r0
 *   @0x1d5210 ldrd r0, r1, [r3]
 *   @0x1d5214 bl 0x319164 <__floatdidf>
 *   @0x1d5218 vldr d7, [pc, #24]
 *   @0x1d521c vmov d6, r0, r1
 *   @0x1d5220 vdiv.f64 d6, d6, d7
 *   @0x1d5224 vmov r0, r1, d6
 *   @0x1d5228 vmov r2, s12
 *   @0x1d522c mov r3, r1
 *   @0x1d5230 stm r4, {r2, r3}
 *   @0x1d5234 pop {r4, pc}
 *   @0x1d5238 andeq r0, r0, r0
 *   @0x1d523c smlawbmi lr, r0, r4, r8
 *   @0x1d5240 eoreq r11, r1, r0, ror #19
 *
 * ══ §364/373 SLinkedList<CTouchAction>::~SLinkedList()  0x1d5758  size 76  19 条（0x1d5758..0x1d57a4）
 * @func 0x1d5758 0x1d57a4  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*) / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x8×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d5758 push {r4, r5, r6, lr}
 *   @0x1d575c mov r6, r0
 *   @0x1d5760 ldr r4, [r0]
 *   @0x1d5764 cmp r4, #0
 *   @0x1d5768 beq 0x1d578c <_ZN11SLinkedListI12CTouchActionED2Ev+0x34>
 *   @0x1d576c ldr r5, [r4]
 *   @0x1d5770 ldr r0, [r4, #0x8]
 *   @0x1d5774 bl 0x27d1d0 <_ZdlPv>
 *   @0x1d5778 mov r0, r4
 *   @0x1d577c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1d5780 cmp r5, #0
 *   @0x1d5784 mov r4, r5
 *   @0x1d5788 bne 0x1d576c <_ZN11SLinkedListI12CTouchActionED2Ev+0x14>
 *   @0x1d578c mov r3, #0
 *   @0x1d5790 mov r0, r6
 *   @0x1d5794 str r3, [r6, #0x8]
 *   @0x1d5798 str r3, [r6, #0x4]
 *   @0x1d579c str r3, [r6]
 *   @0x1d57a0 pop {r4, r5, r6, pc}
 *
 * ══ §365/373 CSprite::FreeTexture()  0x1e56fc  size 76  19 条（0x1e56fc..0x1e5748）
 * @func 0x1e56fc 0x1e5748  size 76  19 条
 * 级别: 骨架（静态语义/C译文已补；真实依赖与原版等价未验收）
 * 静态译文: c/csprite_resources/src/free_resources.c；0x1e570c 是 pople，count<=0 早退；正数循环跳过负 id，调用后重读 +0x50/+0x4c，再写槽 -1。
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CSprite::FreeTexture()+0x3c / GR_Texture_Free(int)
 * 字段偏移 top8: 0x4c×2 / 0x50×2 / 0x2×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e56fc ldr r2, [r0, #0x4c]
 *   @0x1e5700 push {r4, r5, r6, lr}
 *   @0x1e5704 cmp r2, #0
 *   @0x1e5708 mov r5, r0
 *   @0x1e570c pople {r4, r5, r6, pc}
 *   @0x1e5710 ldr r3, [r0, #0x50]
 *   @0x1e5714 mov r4, #0
 *   @0x1e5718 mvn r6, #0
 *   @0x1e571c ldr r0, [r3, r4, lsl #2]
 *   @0x1e5720 cmp r0, #0
 *   @0x1e5724 blt 0x1e5738 <_ZN7CSprite11FreeTextureEv+0x3c>
 *   @0x1e5728 bl 0x173f84 <_Z15GR_Texture_Freei>
 *   @0x1e572c ldr r3, [r5, #0x50]
 *   @0x1e5730 str r6, [r3, r4, lsl #2]
 *   @0x1e5734 ldr r2, [r5, #0x4c]
 *   @0x1e5738 add r4, r4, #1
 *   @0x1e573c cmp r2, r4
 *   @0x1e5740 bgt 0x1e571c <_ZN7CSprite11FreeTextureEv+0x20>
 *   @0x1e5744 pop {r4, r5, r6, pc}
 *
 * ══ §366/373 GV_PhysicsBodySleeping(CInstance*, int, RValue*)  0x1f997c  size 76  19 条（0x1f997c..0x1f99c8）
 * @func 0x1f997c 0x1f99c8  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x84×1 / 0xc×1 / 0x4×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f997c ldr r0, [r0, #0x84]
 *   @0x1f9980 push {r4, r5}
 *   @0x1f9984 cmp r0, #0
 *   @0x1f9988 beq 0x1f99c0 <_Z22GV_PhysicsBodySleepingP9CInstanceiP6RValue+0x44>
 *   @0x1f998c ldr r3, [r0]
 *   @0x1f9990 mov r1, #0
 *   @0x1f9994 str r1, [r2, #0xc]
 *   @0x1f9998 mov r0, #1
 *   @0x1f999c ldrh r4, [r3, #4]
 *   @0x1f99a0 eor r4, r4, #2
 *   @0x1f99a4 ubfx r4, r4, #0x1, #0x1
 *   @0x1f99a8 vmov s15, r4
 *   @0x1f99ac vcvt.f64.u32 d7, s15
 *   @0x1f99b0 vmov r4, r5, d7
 *   @0x1f99b4 vmov r1, s14
 *   @0x1f99b8 mov r3, r5
 *   @0x1f99bc stm r2, {r1, r3}
 *   @0x1f99c0 pop {r4, r5}
 *   @0x1f99c4 bx lr
 *
 * ══ §367/373 GV_ProgramDirectory(CInstance*, int, RValue*)  0x1f9cc0  size 76  19 条（0x1f9cc0..0x1f9d0c）
 * @func 0x1f9cc0 0x1f9d0c  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GetExeName / ExtractFilePath(char const*) / 0xb6538 / YYCreateString(RValue*, char const*) / MemoryManager::Free(void const*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f9cc0 push {r3, r4, r5, lr}
 *   @0x1f9cc4 mov r5, r2
 *   @0x1f9cc8 bl 0x28fe50 <GetExeName>
 *   @0x1f9ccc bl 0x214f5c <_Z15ExtractFilePathPKc>
 *   @0x1f9cd0 mov r4, r0
 *   @0x1f9cd4 bl 0xb6538 <strlen@plt>
 *   @0x1f9cd8 mov r1, r4
 *   @0x1f9cdc sub r0, r0, #1
 *   @0x1f9ce0 ldrb r3, [r4, r0]
 *   @0x1f9ce4 cmp r3, #92
 *   @0x1f9ce8 cmpne r3, #47
 *   @0x1f9cec moveq r3, #0
 *   @0x1f9cf0 strbeq r3, [r4, r0]
 *   @0x1f9cf4 mov r0, r5
 *   @0x1f9cf8 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x1f9cfc mov r0, r4
 *   @0x1f9d00 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f9d04 mov r0, #1
 *   @0x1f9d08 pop {r3, r4, r5, pc}
 *
 * ══ §368/373 GV_KeyboardLastChar(CInstance*, int, RValue*)  0x1fa158  size 76  19 条（0x1fa158..0x1fa1a4）
 * @func 0x1fa158 0x1fa1a4  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: utf8_add_char×2 / IO_Char_Last_Get() / YYCreateString(RValue*, char const*)
 * 字段偏移 top8: 0x-c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fa158 push {r4, r5, r6, lr}
 *   @0x1fa15c sub sp, sp, #16
 *   @0x1fa160 add r4, sp, #16
 *   @0x1fa164 mov r6, r2
 *   @0x1fa168 add r5, sp, #8
 *   @0x1fa16c str r5, [r4, #-0xc]!
 *   @0x1fa170 bl 0x18bd0c <_Z16IO_Char_Last_Getv>
 *   @0x1fa174 mov r1, r0
 *   @0x1fa178 mov r0, r4
 *   @0x1fa17c bl 0x10fe28 <utf8_add_char>
 *   @0x1fa180 mov r0, r4
 *   @0x1fa184 mov r1, #0
 *   @0x1fa188 bl 0x10fe28 <utf8_add_char>
 *   @0x1fa18c mov r0, r6
 *   @0x1fa190 mov r1, r5
 *   @0x1fa194 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x1fa198 mov r0, #1
 *   @0x1fa19c add sp, sp, #16
 *   @0x1fa1a0 pop {r4, r5, r6, pc}
 *
 * ══ §369/373 GV_Bbl(CInstance*, int, RValue*)  0x1fa8ac  size 76  19 条（0x1fa8ac..0x1fa8f8）
 * @func 0x1fa8ac 0x1fa90c  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::Compute_BoundingBox(bool)
 * 字段偏移 top8: 0x64×1 / 0xc×1 / 0xe8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fa8ac ldrb r3, [r0, #0x64]
 *   @0x1fa8b0 push {r4, r5, r6, lr}
 *   @0x1fa8b4 mov r6, r2
 *   @0x1fa8b8 mov r2, #0
 *   @0x1fa8bc cmp r3, r2
 *   @0x1fa8c0 mov r4, r0
 *   @0x1fa8c4 str r2, [r6, #0xc]
 *   @0x1fa8c8 beq 0x1fa8d4 <_Z6GV_BblP9CInstanceiP6RValue+0x28>
 *   @0x1fa8cc mov r1, #1
 *   @0x1fa8d0 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb>
 *   @0x1fa8d4 ldr r4, [r4, #0xe8]
 *   @0x1fa8d8 mov r0, #1
 *   @0x1fa8dc vmov s15, r4
 *   @0x1fa8e0 vcvt.f64.s32 d7, s15
 *   @0x1fa8e4 vmov r4, r5, d7
 *   @0x1fa8e8 vmov r2, s14
 *   @0x1fa8ec mov r3, r5
 *   @0x1fa8f0 stm r6, {r2, r3}
 *   @0x1fa8f4 pop {r4, r5, r6, pc}
 *
 * ══ §370/373 GV_Bbr(CInstance*, int, RValue*)  0x1fa8f8  size 76  19 条（0x1fa8f8..0x1fa944）
 * @func 0x1fa8f8 0x1fa958  size 96  24 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::Compute_BoundingBox(bool)
 * 字段偏移 top8: 0x64×1 / 0xc×1 / 0xf0×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fa8f8 ldrb r3, [r0, #0x64]
 *   @0x1fa8fc push {r4, r5, r6, lr}
 *   @0x1fa900 mov r6, r2
 *   @0x1fa904 mov r2, #0
 *   @0x1fa908 cmp r3, r2
 *   @0x1fa90c mov r4, r0
 *   @0x1fa910 str r2, [r6, #0xc]
 *   @0x1fa914 beq 0x1fa920 <_Z6GV_BbrP9CInstanceiP6RValue+0x28>
 *   @0x1fa918 mov r1, #1
 *   @0x1fa91c bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb>
 *   @0x1fa920 ldr r4, [r4, #0xf0]
 *   @0x1fa924 mov r0, #1
 *   @0x1fa928 vmov s15, r4
 *   @0x1fa92c vcvt.f64.s32 d7, s15
 *   @0x1fa930 vmov r4, r5, d7
 *   @0x1fa934 vmov r2, s14
 *   @0x1fa938 mov r3, r5
 *   @0x1fa93c stm r6, {r2, r3}
 *   @0x1fa940 pop {r4, r5, r6, pc}
 *
 * ══ §371/373 GV_Bbb(CInstance*, int, RValue*)  0x1fa944  size 76  19 条（0x1fa944..0x1fa990）
 * @func 0x1fa944 0x1fa990  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::Compute_BoundingBox(bool)
 * 字段偏移 top8: 0x64×1 / 0xc×1 / 0xf4×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fa944 ldrb r3, [r0, #0x64]
 *   @0x1fa948 push {r4, r5, r6, lr}
 *   @0x1fa94c mov r6, r2
 *   @0x1fa950 mov r2, #0
 *   @0x1fa954 cmp r3, r2
 *   @0x1fa958 mov r4, r0
 *   @0x1fa95c str r2, [r6, #0xc]
 *   @0x1fa960 beq 0x1fa96c <_Z6GV_BbbP9CInstanceiP6RValue+0x28>
 *   @0x1fa964 mov r1, #1
 *   @0x1fa968 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb>
 *   @0x1fa96c ldr r4, [r4, #0xf4]
 *   @0x1fa970 mov r0, #1
 *   @0x1fa974 vmov s15, r4
 *   @0x1fa978 vcvt.f64.s32 d7, s15
 *   @0x1fa97c vmov r4, r5, d7
 *   @0x1fa980 vmov r2, s14
 *   @0x1fa984 mov r3, r5
 *   @0x1fa988 stm r6, {r2, r3}
 *   @0x1fa98c pop {r4, r5, r6, pc}
 *
 * ══ §372/373 YYGML_cos(double)  0x111030  size 64  14 条（0x111030..0x111070）
 * @func 0x111030 0x111068  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb67e4
 * 字段偏移 top8: 无
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x111030 push {r3, lr}
 *   @0x111034 bl 0xb67e4 <cos@plt>
 *   @0x111038 vldr d5, [pc, #32]
 *   @0x11103c vldr d6, [pc, #36]
 *   @0x111040 vmov d7, r0, r1
 *   @0x111044 vabs.f64 d4, d7
 *   @0x111048 vcmpe.f64 d4, d5
 *   @0x11104c vmrs APSR_nzcv, fpscr
 *   @0x111050 vmovpl r0, r1, d7
 *   @0x111054 vmovmi r0, r1, d6
 *   @0x111058 pop {r3, pc}
 *   @0x11105c nop
 *   @0x111060 andhi r0, r0, r0
 *   @0x111064 mcrlo p8, #0x7, pc, c4, c5, #0x5
 *
 * ══ §373/373 VM::Quit()  0xd826c  size 4  1 条（0xd826c..0xd8270）
 * @func 0xd826c 0xd8270  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd826c bx lr
 */
