/* cally 逆向卡：CInstance::SetObjectIndex(int, bool)（原版 libyoyo.so，armv7）
 * @func 0x19324c 0x193368  size 284  71 条（70 条指令 + 末 1 字 0x193364 池字；
 *       下一个符号 CInstance::ChangeObjectIndex 0x193368）
 * 级别: 正文（71/71 逐条落锚。三段外部路径（RemoveInstance / g_ObjectHash 查表 / AddInstance）、
 *       六个字段的复制来源与位序、+0x64 与 CollisionMarkDirty 的尾部契约全部钉死；未钉的是
 *       SetSpriteIndex 的内部副作用，以及「-1 归一化只作用于存储、不作用于查表」的实际后果。
 *       tier = bytecode_anchored）
 * 符号: _ZN9CInstance14SetObjectIndexEib → void CInstance::SetObjectIndex(int objindex, bool addToObject)
 * 位置: CInstance::SetSpriteIndex 0x1931c0 之后、CInstance::ChangeObjectIndex 0x193368 之前
 * 调用点: 全图唯二（按 cond=AL 的 BL 编码扫 .text）：CInstance::CInstance 0x199660、
 *         CInstance::DeSerialise 0x197714
 *
 * ── 一句话 ────────────────────────────────────────────────────────────────
 *   换对象索引：先摘旧对象的实例链，再按对象号在 g_ObjectHash 里查 CObjectGM*，查到就把对象的
 *   sprite / mask / visible / solid / persistent / depth 一次性复制进实例，置 bbox 脏标记并尾调
 *   CollisionMarkDirty；查不到只写 +0x80 = 0，其余字段全保持旧值。
 *
 * ── 语义草案（可编译）────────────────────────────────────────────────────
 *   void CInstance::SetObjectIndex(int objindex, bool addToObject) {
 *     CObjectGM* old = this->obj;                                      // +0x80（0x193254）
 *     this->objindex = objindex;                                       // +0x7c（0x193260，先存原值）
 *     if (old) { old->RemoveInstance(this); this->obj = 0; }           // 0x193264..0x193280
 *     if (objindex == -1) this->objindex = 0;                          // 0x193284..0x19328c（只改存储值）
 *     CObjectGM* o = ObjHashFind(objindex);                            // 用**原始** objindex（0x1932a4）
 *     this->obj = o;                                                   // +0x80（0 也写，0x1932e0/0x1932f0）
 *     if (!o) return;                                                  // 0x1932f4
 *     if (addToObject) ((CObjectGM*)this->obj)->AddInstance(this);     // 0x1932fc/0x193350..0x193358
 *     this->mask_index = o->[0x10];                                    // +0xac（0x19331c）
 *     this->visible    = (o->flags >> 1) & 1;                          // +0x65（bit1）
 *     this->solid      =  o->flags       & 1;                          // +0x66（bit0）
 *     this->persistent = (o->flags >> 2) & 1;                          // +0x67（bit2）
 *     this->depth      = (float)(int)o->[0x08];                        // +0x180（0x193300/0x193304/0x193334）
 *     this->SetSpriteIndex(o->[0x04]);                                 // +0x8c（0x193314/0x193338）
 *     this->[0x64] = 1;                                                // bbox 脏（0x193344）
 *     CollisionMarkDirty(this);                                        // 尾调用 0x1cc1d0（0x19334c）
 *   }
 *
 * ── 字段与全局（本卡读写的全部地址）────────────────────────────────────────
 *   this+0x07c int   objindex（-1 → 0 归一；先写后归一）
 *   this+0x080 ptr   CObjectGM*（查不到写 0）
 *   this+0x064 u8    bbox 脏标记（只在命中路径置 1；未命中保持原值）
 *   this+0x065/0x066/0x067 u8  visible / solid / persistent（= obj flags 的 bit1 / bit0 / bit2）
 *   this+0x08c int   sprite_index（经 SetSpriteIndex 写，不是直接 str）
 *   this+0x0ac int   mask_index（← obj+0x10）
 *   this+0x180 f32   depth（← (float)(int)obj+0x08）
 *   obj+0x00 u32 flags    obj+0x04 int sprite    obj+0x08 int depth    obj+0x10 int mask
 *   0x542374（GOT 0x3edc44，R_ARM_RELATIVE）g_ObjectHash **指针变量** → 表结构 {+0x00 桶数组, +0x04 掩码}；
 *   桶项 8 B、取 +0x00 为链头；节点 {+0x04 next, +0x08 key, +0x0c value}（value = CObjectGM*）
 *
 * ── 已证（指令级）────────────────────────────────────────────────────────
 *  1. 解引用链：0x193290 池字 0x0025a9a8 → 0x193294 ldr [pc,r3] → GOT 0x3edc44 → 0x542374；
 *     0x193298 再解一层得表结构；0x19329c 取掩码、0x1932a0 取桶基址；桶步长 8（0x1932a8 lsl #3）；
 *     节点 next 在 +4（0x1932d0）、key 在 +8（0x1932b4）、value 在 +0xc（0x1932e8）。
 *     （与 Object_Name 卡、Variable_GetValue 卡记录的同一张表同构，节点布局一致。）
 *  2. 查表键是**原始** objindex：0x1932a4 用 r4（第一实参），而 0x19328c 已把 -1 归一成 0 写进 +0x7c。
 *     ⇒ 传 -1 时查的是 -1 & mask，与「传 0」不等价（0 查的是对象 0）。
 *  3. 顺序固定：先摘旧（0x193274 RemoveInstance）、清 +0x80（0x193280）、再查表并写 +0x80（0x1932e0/0x1932f0）。
 *     旧对象为空时 0x193268/0x19326c 直接跳到归一化那一步。
 *  4. 命中但 value == 0：写 +0x80 = 0 后立刻返回（0x1932ec/0x1932f4），六个字段一个都不写。
 *  5. addToObject != 0 → 先 AddInstance 再复制（0x1932fc bne → 0x193350..0x193358 → 0x19335c 重读 +0x80
 *     → 0x193300）。即「先入对象链、后同步字段」是契约，不是两条独立路径。
 *  6. 六个字段的来源与位序：mask ← obj+0x10（0x19331c）；visible ← bit1（0x193318/0x193320）；
 *     solid ← bit0（0x193324/0x19332c）；persistent ← bit2（0x193328/0x193330）；
 *     depth ← (float)(int)obj+0x08（0x193300 vldr + 0x193304 vcvt.f32.s32 + 0x193334 vstr）；
 *     sprite ← SetSpriteIndex(obj+0x04)（0x193314/0x193338）。flags 的 bit3 及以上本函数不碰。
 *  7. 尾部契约：0x19333c/0x193344 置 +0x64 = 1；0x193348 pop 掉 {r4,r5,r6,lr} 后 0x19334c
 *     以 b（不是 bl）尾调 CollisionMarkDirty 0x1cc1d0 —— 所以 CollisionMarkDirty 的返回直接回给调用者。
 *  8. 未命中路径（0x1932dc..0x1932e4）只写 +0x80 = 0：+0x7c 仍是参数值（或归一的 0），
 *     +0x64/+0x65/+0x66/+0x67/+0x8c/+0xac/+0x180 全部保持旧值 ⇒「换对象失败」不洗白实例、也不置脏。
 *     这条与 CInstance_ctor 卡的构造契约互印证：构造期 0x80 已清零，所以本函数的 RemoveInstance 分支在
 *     构造期必不跑（SetObjectIndex 不会去摘一条还不存在的对象链）。
 *
 * ── open ────────────────────────────────────────────────────────────────
 *  1. SetSpriteIndex 0x1931c0 的内部副作用不在本卡锚点内（已知：直接写 +0x8c；Sprite_Exists 失败时
 *     把 image_index(+0x90) 归零；释放 +0x88 的 CSkeletonInstance 后调 SkeletonAnimation；置 +0x64；
 *     尾调 CollisionMarkDirty）。本卡只证「它的入参是 obj+0x04」。
 *  2. 「查找用 -1、存储用 0」这一不对称的实际后果未验证：只有当 g_ObjectHash 里存在 key == -1 的节点时
 *     才会分叉；若不存在，传 -1 等价于解绑对象。
 *  3. 表的桶数/掩码值与对象 flags bit3+ 的语义未定；本卡只证被用到的 bit0/bit1/bit2。
 *  4. obj+0x08 是 int（depth）这一点由「vldr + 单条 vcvt.f32.s32」的写法反推（若是 float 需要两条 vcvt）；
 *     obj 侧写这个字段的函数还没出卡。
 *
 * ── 逐条锚点 ───────────────────────────────────────────────────────────────
 */
/* ── 1. 入口：帧 + 四个实参落位（r5 = this、r4 = objindex、r6 = addToObject）（0x19324c..0x193260）── */
/* @0x19324c push {r4, r5, r6, lr} —— r5 = this（0x193250）、r4 = objindex（0x193258）、r6 = addToObject（0x19325c） */
/* @0x193250 mov r5, r0 */
/* @0x193254 ldr r0, [r0, #0x80] —— r0 = 旧 CObjectGM*（+0x80） */
/* @0x193258 mov r4, r1 */
/* @0x19325c mov r6, r2 */
/* @0x193260 str r1, [r5, #0x7c] —— +0x7c = objindex（原值） */
/* ── 2. 摘旧对象：+0x80 非空才 RemoveInstance，摘完清 +0x80（0x193264..0x193280）── */
/* @0x193264 cmp r0, #0 —— 旧对象为空 → 跳过摘链 */
/* @0x193268 moveq r3, r1 —— moveq：r3 = objindex */
/* @0x19326c beq 0x193284 <_ZN9CInstance14SetObjectIndexEib+0x38> */
/* @0x193270 mov r1, r5 */
/* @0x193274 bl 0x19e0fc <_ZN9CObjectGM14RemoveInstanceEP9CInstance> —— 旧对象->RemoveInstance(this) */
/* @0x193278 ldr r3, [r5, #0x7c] */
/* @0x19327c mov r2, #0 */
/* @0x193280 str r2, [r5, #0x80] —— +0x80 = 0 */
/* ── 3. -1 归一：只改 +0x7c 的存储值，不影响下面的查表键（0x193284..0x19328c）── */
/* @0x193284 cmn r3, #1 —— cmn r3, #1：objindex == -1 ? */
/* @0x193288 moveq r3, #0 */
/* @0x19328c streq r3, [r5, #0x7c] —— 是 → +0x7c = 0（只改存储值，查表仍用 -1） */
/* ── 4. g_ObjectHash 三层取表：池字 → GOT 0x3edc44 → 0x542374 → {桶, 掩码}（0x193290..0x1932a0）── */
/* @0x193290 ldr r3, [pc, #0xcc] —— 池字 0x0025a9a8 */
/* @0x193294 ldr r3, [pc, r3] —— → GOT 0x3edc44 = 0x542374（g_ObjectHash） */
/* @0x193298 ldr r3, [r3] —— → 表结构 */
/* @0x19329c ldr r1, [r3, #0x4] —— 掩码 */
/* @0x1932a0 ldr r3, [r3] —— 桶基址 */
/* ── 5. 桶定位 + 链查找：idx = objindex & mask，桶项 8 B，节点 {+4 next, +8 key, +0xc value}
 *   （0x1932a4..0x1932d8）── */
/* @0x1932a4 and r1, r4, r1 —— idx = objindex & mask（用 r4 = 原始实参） */
/* @0x1932a8 ldr r3, [r3, r1, lsl #3] —— 桶项 8 B → 链头 */
/* @0x1932ac cmp r3, #0 */
/* @0x1932b0 beq 0x1932dc <_ZN9CInstance14SetObjectIndexEib+0x90> —— 空桶 → 未命中 */
/* @0x1932b4 ldr r2, [r3, #0x8] —— 节点 key */
/* @0x1932b8 cmp r4, r2 */
/* @0x1932bc bne 0x1932d0 <_ZN9CInstance14SetObjectIndexEib+0x84> */
/* @0x1932c0 b 0x1932e8 <_ZN9CInstance14SetObjectIndexEib+0x9c> —— 首个节点就命中 → 0x1932e8 */
/* @0x1932c4 ldr r12, [r3, #0x8] */
/* @0x1932c8 cmp r4, r12 */
/* @0x1932cc beq 0x1932e8 <_ZN9CInstance14SetObjectIndexEib+0x9c> */
/* @0x1932d0 ldr r3, [r3, #0x4] —— next */
/* @0x1932d4 cmp r3, #0 */
/* @0x1932d8 bne 0x1932c4 <_ZN9CInstance14SetObjectIndexEib+0x78> —— 非空继续 */
/* ── 6. 未命中：+0x80 = 0 后返回（其余字段不动）（0x1932dc..0x1932e4）── */
/* @0x1932dc mov r3, #0 —— r3 = 0 */
/* @0x1932e0 str r3, [r5, #0x80] —— +0x80 = 0（未命中） */
/* @0x1932e4 pop {r4, r5, r6, pc} —— 返回 */
/* ── 7. 命中：+0x80 = node.value；value 为 0 也照样返回（0x1932e8..0x1932f4）── */
/* @0x1932e8 ldr r3, [r3, #0xc] —— value = CObjectGM* */
/* @0x1932ec cmp r3, #0 */
/* @0x1932f0 str r3, [r5, #0x80] —— +0x80 = value */
/* @0x1932f4 popeq {r4, r5, r6, pc} —— value == 0 → 返回（不复制字段） */
/* ── 8. addToObject 闸：非 0 先去 0x193350 入对象链（0x1932f8..0x1932fc）── */
/* @0x1932f8 cmp r6, #0 —— addToObject ? */
/* @0x1932fc bne 0x193350 <_ZN9CInstance14SetObjectIndexEib+0x104> —— 非 0 → 0x193350 */
/* ── 9. 六字段复制块：mask / visible / solid / persistent / depth / sprite（0x193300..0x193338）──
 *   0x193300 vldr + 0x193304 vcvt.f32.s32 = (float)(int)obj+0x08 ⇒ obj 侧 depth 是 int。 */
/* @0x193300 vldr s14, [r3, #8] —— obj+0x08（int depth） */
/* @0x193304 vcvt.f32.s32 s15, s14 —— (float)(int)depth */
/* @0x193308 ldr r12, [r3, #0x10] —— obj+0x10 = mask */
/* @0x19330c mov r0, r5 */
/* @0x193310 ldr r2, [r3] —— obj flags */
/* @0x193314 ldr r1, [r3, #0x4] —— obj+0x04 = sprite */
/* @0x193318 ubfx r3, r2, #0x1, #0x1 —— bit1 → visible */
/* @0x19331c str r12, [r5, #0xac] —— +0xac = mask_index */
/* @0x193320 strb r3, [r5, #0x65] —— +0x65 = visible */
/* @0x193324 and r12, r2, #1 —— bit0 → solid */
/* @0x193328 ubfx r2, r2, #0x2, #0x1 —— bit2 → persistent */
/* @0x19332c strb r12, [r5, #0x66] —— +0x66 = solid */
/* @0x193330 strb r2, [r5, #0x67] —— +0x67 = persistent */
/* @0x193334 vstr s15, [r5, #384] —— +0x180 = depth */
/* @0x193338 bl 0x1931c0 <_ZN9CInstance14SetSpriteIndexEi> —— SetSpriteIndex(obj+0x04) */
/* ── 10. 尾部：置 bbox 脏 + 尾调 CollisionMarkDirty（0x19333c..0x19334c）── */
/* @0x19333c mov r3, #1 */
/* @0x193340 mov r0, r5 —— r0 = this（CollisionMarkDirty 的实参） */
/* @0x193344 strb r3, [r5, #0x64] —— +0x64 = 1 */
/* @0x193348 pop {r4, r5, r6, lr} —— pop {r4,r5,r6,lr} */
/* @0x19334c b 0x1cc1d0 <_Z18CollisionMarkDirtyP9CInstance> —— 尾调 CollisionMarkDirty 0x1cc1d0 */
/* ── 11. addToObject 路径：CObjectGM::AddInstance(obj, this)，然后重读 +0x80 回复制块（0x193350..0x193360）── */
/* @0x193350 mov r0, r3 —— r0 = obj */
/* @0x193354 mov r1, r5 */
/* @0x193358 bl 0x19e02c <_ZN9CObjectGM11AddInstanceEP9CInstance> —— CObjectGM::AddInstance(obj, this) */
/* @0x19335c ldr r3, [r5, #0x80] —— 重读 +0x80（AddInstance 后可能变化） */
/* @0x193360 b 0x193300 <_ZN9CInstance14SetObjectIndexEib+0xb4> —— 回复制块 */
/* ── 12. literal pool 1 字（非指令）：0x0025a9a8 = GOT 0x3edc44 的 pc 相对偏移（0x193364）── */
/* @0x193364 eoreq r10, r5, r8, lsr #19 —— 非指令：0x0025a9a8（GOT 偏移） */
