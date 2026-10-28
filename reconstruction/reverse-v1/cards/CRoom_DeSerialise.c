/* cally 逆向卡：CRoom::DeSerialise（原版 libyoyo.so，armv7）
 * @func 0x1ac33c 0x1ad05c  size 3364  841 条（1ad048..1ad05c 为 literal pool，5 字）
 * 级别: 正文（房间头 / 8 背景 / 8 视野 / tile 表 / layer 表 / 两段实例表的流序与落位全部逐条钉住，
 *             并与 CRoom::Serialise 0x1aa228、CRoom::AddTile 0x1ac240、CRoom::AddInstance 0x1ab654、
 *             CRoom::UpdateActive 0x1abd9c、Draw_Room 0x1b3e98 五处交叉印证；
 *             未钉：背景 13 字段的名字、视野 +0x28..+0x40 七个 int 的名字、房间头三个 int 谁是宽/高、
 *             CRoom+0x44 与 CRoom+0x00 的用途、room_maxtileid 回退带来的重号后果）
 * 符号: _ZN5CRoom11DeSerialiseEP7IBufferb → void CRoom::DeSerialise(IBuffer* buf, bool bRegister)
 * ABI : softfp（float 走核心寄存器）；本函数无返回值。
 * 同层: CRoom::Serialise 0x1aa228（严格互逆）、CRoom::AddTile 0x1ac240（56 B 表的唯一写入口）、
 *       CRoom::AddInstance(CInstance*) 0x1ab654、CRoom::UpdateActive 0x1abd9c、
 *       CRoom::LoadFromStream 0x1ae3f8、CLayerManager::DeSerializeLayer 0x1c74d0、
 *       CLayerManager::AddInstance 0x1c5d18、CInstance::DeSerialise 0x19766c、CInstance::C2 0x1994dc、
 *       IBuffer::ReadString 0xcde74、YYGetInt32 0xce870 / YYGetFloat 0xcec84 / YYGetBool 0xce768 /
 *       YYGetUint32 0xce950、MemoryManager::Alloc 0x27ce78 / ReAlloc 0x27cedc / Free 0x27c2d0
 *
 * ── 一句话 ─────────────────────────────────────────────────────
 *   把一条房间数据流按固定次序铺进 CRoom：一串标量 → 8 个背景记录 → 1 个字节 → 8 个视野记录
 *   → tile 表（n 条 56 B 记录，逐条过 AddTile）→ layer 表（n 条，全部委派 CLayerManager）
 *   → 两段实例表（活动 / 非活动，各自 n 条 CInstance::DeSerialise + 挂链，可选注册）。
 *   全程没有版本号、没有长度前缀，次序即格式；读错一个类型后面全歪。
 *
 * ── 流序总表（本函数读到的顺序，右列是落点）──────────────────────
 *   ReadString()                      → CRoom+0x08   char*
 *   int                               → CRoom+0x10
 *   int                               → CRoom+0x14
 *   int                               → CRoom+0x0c
 *   bool(int)                         → CRoom+0x18   byte
 *   uint32                            → CRoom+0x1c
 *   bool(int)                         → CRoom+0x20   byte
 *   ReadString()                      → CRoom+0x68   char*
 *   8 × 44 B 背景记录                 → *(CRoom+0x24 + i*4)
 *   bool(int)                         → CRoom+0x44   byte
 *   8 × 68 B 视野记录                 → *(CRoom+0x48 + i*4)
 *   int n                             → tile 表：ReAlloc(n*56) 后 n 条 56 B 记录
 *   int n                             → n 次 CLayerManager::DeSerializeLayer(this, buf)
 *   int n                             → 实例表 A：n × (new CInstance + DeSerialise + 挂 +0x84 链)
 *   int n                             → 实例表 B：n × (new CInstance + DeSerialise + 挂 +0x90 链)
 *
 * ── IBuffer 的读协议（全函数 55 个 blx r3 = 55 个读点，与 55 条 YYGet* 一一对应）──
 *   vtable[+0x08] = Write(RValue&, int type)   ← CRoom::Serialise 用
 *   vtable[+0x0c] = Read (RValue&, int type)   ← 本函数用
 *   调用形状固定：r0 = buf，r1 = 类型码，r2 = buf+0x2c，blx [buf->vt+0xc]；
 *                 随后 YYGetXxx(buf+0x2c, 0) 把 RValue 拆成标量。
 *   buf+0x2c 是 IBuffer **内嵌的 16 B RValue 暂存槽**（tag 在 buf+0x38）：全函数复用同一个槽，
 *   所以「读下一条前先把上一条取走」是硬约束 —— 编译器把取数放在下一次读之后，读卡时别错拍。
 *   类型码实见三种：6 = int（bool/普通整数都用它）、5 = uint32、8 = float/real。
 *   字符串不走虚表：直调 IBuffer::ReadString()（两处：0x1ac354、0x1ac468）。
 *
 * ── 关键字段的角色（本卡 + AddTile + UpdateActive 三方定死）──────────
 *   tile 表   +0xb8 = **计数**   +0xbc = **容量**   +0xc0 = 数据基址（元素 56 B）
 *   实例表 A  +0x84 = 头  +0x80 = 尾  +0x88 = 计数   depth **降序**，排序键 +0x184
 *   实例表 B  +0x90 = 头  +0x8c = 尾  +0x94 = 计数   头插（无序）
 *   两条实例链共用 CInstance+0x178(prev) / +0x17c(next)；[inst+0x69] != 0 表示「非活动」，
 *   CRoom::UpdateActive 按它把实例在 A/B 两链之间来回搬 —— 这就是格式里为什么有两段实例表。
 *
 * ── 未定（open）────────────────────────────────────────────
 *   1. 背景记录 13 个字段的名字（偏移/类型/流序已证；名字按 GM 房间背景结构推断）
 *   2. 视野记录 +0x28..+0x40 七个 int 的语义（Draw_Room 未在此读）
 *   3. 房间头 +0x10/+0x14/+0xc 三个 int 谁是宽/高/速度（只证到序与类型）
 *   4. CRoom+0x44（字节，位于背景与视野之间）与 CRoom+0x00（AddTile 写最新 tile 下标）的用途
 *   5. bRegister == 0 时谁负责补建 ID 索引与层注册
 *   6. room_maxtileid 被逐条回退 ⇒ 读档后新 tile 与流里 tile id 重号的实际后果（未运行期验证）
 *
 * ── 逐条锚点 ───────────────────────────────────────────────────
 */

/* ── 装载：IBuffer 读协议、GOT 基址、三个游标 ─────────────────────
 *   帧：push {r4-r11,lr} + sub sp,#100（100 B：tile 记录 56 B 落在 sp+0x28，其余是暂存）
 *   r6 = this(CRoom*)、r4 = buf(IBuffer*)、r11 = 第二参 bool（本卡记 bRegister）
 *   r5 = buf+0x2c（内嵌 RValue 暂存槽）、r9 = this（背景/视野指针数组游标）、r8 = 8（背景循环计数）
 *   r12 = pc 0x1ac374 + 0x002458e4 = 0x3f1c58（GOT 基址），存进 [sp+0x1c] 供后面两次取全局用
 */

/* @0x1ac33c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1ac340 mov r6, r0 */
/* @0x1ac344 sub sp, sp, #100 */
/* @0x1ac348 mov r0, r1 */
/* @0x1ac34c mov r4, r1 */
/* @0x1ac350 mov r11, r2 */
/* ── 第 1 项：房间名（ReadString 直调，不走虚表）→ CRoom+0x08 ────── */

/* @0x1ac354 bl 0xcde74 <_ZN7IBuffer10ReadStringEv> */
/* ── 房间头六连 + 第二串：落位序 = +0x10, +0x14, +0xc, +0x18, +0x1c, +0x20, +0x68 ──
 *   每次读三连：ldr r3,[buf] → ldr r3,[r3,#0xc] → blx（r1=类型码, r2=&buf->rv0），
 *   紧接 YYGetXxx(&rv, 0)；存回 this 的 str 都排在**下一次读之后**，看图别错拍。
 *   与 CRoom::Serialise 0x1aa240-0x1aa330 逐项同序同型（s32 +0x10 / s32 +0x14 / s32 +0xc /
 *   u32(byte) +0x18 / u32 +0x1c / …）⇒ 严格互逆。
 *   ★ 布尔字段也走类型码 6 读成整数再 YYGetBool 归一：流里没有独立 bool 类型。
 */

/* @0x1ac358 ldr r3, [r4] */
/* @0x1ac35c add r5, r4, #44 */
/* @0x1ac360 ldr r12, [pc, #0xce0] */
/* @0x1ac364 mov r1, #6 */
/* @0x1ac368 mov r9, r6 */
/* @0x1ac36c add r12, pc, r12 */
/* @0x1ac370 mov r2, r5 */
/* @0x1ac374 str r12, [sp, #0x1c] */
/* @0x1ac378 mov r8, #8 */
/* @0x1ac37c str r0, [r6, #0x8] */
/* @0x1ac380 mov r0, r4 */
/* @0x1ac384 ldr r3, [r3, #0xc] */
/* @0x1ac388 blx r3 */
/* @0x1ac38c mov r1, #0 */
/* @0x1ac390 mov r0, r5 */
/* @0x1ac394 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1ac398 ldr r3, [r4] */
/* @0x1ac39c mov r2, r5 */
/* @0x1ac3a0 mov r1, #6 */
/* @0x1ac3a4 ldr r3, [r3, #0xc] */
/* @0x1ac3a8 str r0, [r6, #0x10] */
/* @0x1ac3ac mov r0, r4 */
/* @0x1ac3b0 blx r3 */
/* @0x1ac3b4 mov r1, #0 */
/* @0x1ac3b8 mov r0, r5 */
/* @0x1ac3bc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1ac3c0 ldr r3, [r4] */
/* @0x1ac3c4 mov r2, r5 */
/* @0x1ac3c8 mov r1, #6 */
/* @0x1ac3cc ldr r3, [r3, #0xc] */
/* @0x1ac3d0 str r0, [r6, #0x14] */
/* @0x1ac3d4 mov r0, r4 */
/* @0x1ac3d8 blx r3 */
/* @0x1ac3dc mov r1, #0 */
/* @0x1ac3e0 mov r0, r5 */
/* @0x1ac3e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1ac3e8 ldr r3, [r4] */
/* @0x1ac3ec mov r2, r5 */
/* @0x1ac3f0 mov r1, #6 */
/* @0x1ac3f4 ldr r3, [r3, #0xc] */
/* @0x1ac3f8 str r0, [r6, #0xc] */
/* @0x1ac3fc mov r0, r4 */
/* @0x1ac400 blx r3 */
/* @0x1ac404 mov r1, #0 */
/* @0x1ac408 mov r0, r5 */
/* @0x1ac40c bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1ac410 ldr r3, [r4] */
/* @0x1ac414 mov r2, r5 */
/* @0x1ac418 mov r1, #5 */
/* @0x1ac41c ldr r3, [r3, #0xc] */
/* @0x1ac420 strb r0, [r6, #0x18] */
/* @0x1ac424 mov r0, r4 */
/* @0x1ac428 blx r3 */
/* @0x1ac42c mov r1, #0 */
/* @0x1ac430 mov r0, r5 */
/* @0x1ac434 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x1ac438 ldr r3, [r4] */
/* @0x1ac43c mov r2, r5 */
/* @0x1ac440 mov r1, #6 */
/* @0x1ac444 ldr r3, [r3, #0xc] */
/* @0x1ac448 str r0, [r6, #0x1c] */
/* @0x1ac44c mov r0, r4 */
/* @0x1ac450 blx r3 */
/* @0x1ac454 mov r1, #0 */
/* @0x1ac458 mov r0, r5 */
/* @0x1ac45c bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1ac460 strb r0, [r6, #0x20] */
/* ── 第 8 项：第二串（ReadString 直调）→ CRoom+0x68（char*，房间的 code 串那一格）── */

/* @0x1ac464 mov r0, r4 */
/* @0x1ac468 bl 0xcde74 <_ZN7IBuffer10ReadStringEv> */
/* @0x1ac46c str r0, [r6, #0x68] */
/* ── 8 个房间背景：CRoom+0x24/+0x28/…/+0x40 是 8 个指针，每个指向 44 B 记录 ──
 *   r7 = [r9]、r9 += 4、r8 递减到 0 收尾。记录 13 字段（偏移/类型全实测）：
 *     +0x00 bool  +0x01 bool  +0x04 int   +0x08 float +0x0c float
 *     +0x10 bool  +0x11 bool  +0x14 float +0x18 float +0x1c float
 *     +0x20 float +0x24 int   +0x28 float
 *   按 GM 房间背景结构，这 13 格依次是 visible / foreground / 背景号 / x / y / htiled / vtiled /
 *   xscale / yscale / hspeed / vspeed / blend(int) / alpha(float) —— 名字是推断（open 1）。
 *   ★ 记录里所有 bool 都是 strb 单字节，没有任何对齐填充（0x2c 是精确的 44）。
 */

/* @0x1ac470 ldr r3, [r4] */
/* @0x1ac474 mov r2, r5 */
/* @0x1ac478 mov r1, #6 */
/* @0x1ac47c mov r0, r4 */
/* @0x1ac480 ldr r7, [r9, #0x24] */
/* @0x1ac484 add r9, r9, #4 */
/* @0x1ac488 ldr r3, [r3, #0xc] */
/* @0x1ac48c blx r3 */
/* @0x1ac490 mov r1, #0 */
/* @0x1ac494 mov r0, r5 */
/* @0x1ac498 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1ac49c ldr r3, [r4] */
/* @0x1ac4a0 mov r2, r5 */
/* @0x1ac4a4 mov r1, #6 */
/* @0x1ac4a8 ldr r3, [r3, #0xc] */
/* @0x1ac4ac strb r0, [r7] */
/* @0x1ac4b0 mov r0, r4 */
/* @0x1ac4b4 blx r3 */
/* @0x1ac4b8 mov r1, #0 */
/* @0x1ac4bc mov r0, r5 */
/* @0x1ac4c0 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1ac4c4 ldr r3, [r4] */
/* @0x1ac4c8 mov r2, r5 */
/* @0x1ac4cc mov r1, #6 */
/* @0x1ac4d0 ldr r3, [r3, #0xc] */
/* @0x1ac4d4 strb r0, [r7, #0x1] */
/* @0x1ac4d8 mov r0, r4 */
/* @0x1ac4dc blx r3 */
/* @0x1ac4e0 mov r1, #0 */
/* @0x1ac4e4 mov r0, r5 */
/* @0x1ac4e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1ac4ec ldr r3, [r4] */
/* @0x1ac4f0 mov r2, r5 */
/* @0x1ac4f4 mov r1, #8 */
/* @0x1ac4f8 ldr r3, [r3, #0xc] */
/* @0x1ac4fc str r0, [r7, #0x4] */
/* @0x1ac500 mov r0, r4 */
/* @0x1ac504 blx r3 */
/* @0x1ac508 mov r1, #0 */
/* @0x1ac50c mov r0, r5 */
/* @0x1ac510 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1ac514 ldr r3, [r4] */
/* @0x1ac518 mov r2, r5 */
/* @0x1ac51c mov r1, #8 */
/* @0x1ac520 ldr r3, [r3, #0xc] */
/* @0x1ac524 str r0, [r7, #0x8] */
/* @0x1ac528 mov r0, r4 */
/* @0x1ac52c blx r3 */
/* @0x1ac530 mov r1, #0 */
/* @0x1ac534 mov r0, r5 */
/* @0x1ac538 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1ac53c ldr r3, [r4] */
/* @0x1ac540 mov r2, r5 */
/* @0x1ac544 mov r1, #6 */
/* @0x1ac548 ldr r3, [r3, #0xc] */
/* @0x1ac54c str r0, [r7, #0xc] */
/* @0x1ac550 mov r0, r4 */
/* @0x1ac554 blx r3 */
/* @0x1ac558 mov r1, #0 */
/* @0x1ac55c mov r0, r5 */
/* @0x1ac560 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1ac564 ldr r3, [r4] */
/* @0x1ac568 mov r2, r5 */
/* @0x1ac56c mov r1, #6 */
/* @0x1ac570 ldr r3, [r3, #0xc] */
/* @0x1ac574 strb r0, [r7, #0x10] */
/* @0x1ac578 mov r0, r4 */
/* @0x1ac57c blx r3 */
/* @0x1ac580 mov r1, #0 */
/* @0x1ac584 mov r0, r5 */
/* @0x1ac588 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1ac58c ldr r3, [r4] */
/* @0x1ac590 mov r2, r5 */
/* @0x1ac594 mov r1, #8 */
/* @0x1ac598 ldr r3, [r3, #0xc] */
/* @0x1ac59c strb r0, [r7, #0x11] */
/* @0x1ac5a0 mov r0, r4 */
/* @0x1ac5a4 blx r3 */
/* @0x1ac5a8 mov r1, #0 */
/* @0x1ac5ac mov r0, r5 */
/* @0x1ac5b0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1ac5b4 ldr r3, [r4] */
/* @0x1ac5b8 mov r2, r5 */
/* @0x1ac5bc mov r1, #8 */
/* @0x1ac5c0 ldr r3, [r3, #0xc] */
/* @0x1ac5c4 str r0, [r7, #0x14] */
/* @0x1ac5c8 mov r0, r4 */
/* @0x1ac5cc blx r3 */
/* @0x1ac5d0 mov r1, #0 */
/* @0x1ac5d4 mov r0, r5 */
/* @0x1ac5d8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1ac5dc ldr r3, [r4] */
/* @0x1ac5e0 mov r2, r5 */
/* @0x1ac5e4 mov r1, #8 */
/* @0x1ac5e8 ldr r3, [r3, #0xc] */
/* @0x1ac5ec str r0, [r7, #0x18] */
/* @0x1ac5f0 mov r0, r4 */
/* @0x1ac5f4 blx r3 */
/* @0x1ac5f8 mov r1, #0 */
/* @0x1ac5fc mov r0, r5 */
/* @0x1ac600 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1ac604 ldr r3, [r4] */
/* @0x1ac608 mov r2, r5 */
/* @0x1ac60c mov r1, #8 */
/* @0x1ac610 ldr r3, [r3, #0xc] */
/* @0x1ac614 str r0, [r7, #0x1c] */
/* @0x1ac618 mov r0, r4 */
/* @0x1ac61c blx r3 */
/* @0x1ac620 mov r1, #0 */
/* @0x1ac624 mov r0, r5 */
/* @0x1ac628 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1ac62c ldr r3, [r4] */
/* @0x1ac630 mov r2, r5 */
/* @0x1ac634 mov r1, #6 */
/* @0x1ac638 ldr r3, [r3, #0xc] */
/* @0x1ac63c str r0, [r7, #0x20] */
/* @0x1ac640 mov r0, r4 */
/* @0x1ac644 blx r3 */
/* @0x1ac648 mov r1, #0 */
/* @0x1ac64c mov r0, r5 */
/* @0x1ac650 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1ac654 ldr r3, [r4] */
/* @0x1ac658 mov r1, #8 */
/* @0x1ac65c mov r2, r5 */
/* @0x1ac660 ldr r3, [r3, #0xc] */
/* @0x1ac664 str r0, [r7, #0x24] */
/* @0x1ac668 mov r0, r4 */
/* @0x1ac66c blx r3 */
/* @0x1ac670 mov r0, r5 */
/* @0x1ac674 mov r1, #0 */
/* @0x1ac678 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1ac67c subs r8, r8, #1 */
/* @0x1ac680 str r0, [r7, #0x28] */
/* @0x1ac684 bne 0x1ac470 <_ZN5CRoom11DeSerialiseEP7IBufferb+0x134> */
/* ── 房间级字节 CRoom+0x44（读类型 6 → YYGetBool → strb）────────────
 *   位置在「8 背景之后、8 视野之前」；GM 房间头这一格通常是 enable-views 类开关，本卡不钉其名（open 4）。
 *   同一处顺带 r10 = r8（循环后 r8 恒为 0，这里借它当 0 常量），r9 复位到 this 给视野循环用。
 */

/* @0x1ac688 ldr r3, [r4] */
/* @0x1ac68c mov r1, #6 */
/* @0x1ac690 mov r2, r5 */
/* @0x1ac694 mov r0, r4 */
/* @0x1ac698 mov r10, r8 */
/* @0x1ac69c mov r9, r6 */
/* @0x1ac6a0 ldr r3, [r3, #0xc] */
/* @0x1ac6a4 blx r3 */
/* @0x1ac6a8 mov r0, r5 */
/* @0x1ac6ac mov r1, r8 */
/* @0x1ac6b0 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1ac6b4 strb r0, [r6, #0x44] */
/* ── 8 个视野：CRoom+0x48…+0x64 是 8 个指针，每个指向 68 B 记录，17 字段 ──
 *     +0x00 bool
 *     +0x04 float +0x08 float +0x0c float +0x10 float   ← ★流里是 int，vcvt.f32.s32 转 float 后 vstr
 *     +0x14 int   +0x18 int   +0x1c int   +0x20 int
 *     +0x24 float
 *     +0x28 int   +0x2c int   +0x30 int   +0x34 int   +0x38 int   +0x3c int   +0x40 int
 *   ★ 最容易读错的一处：前四个矩形值是「整数入流、浮点使用」。落位点是 0x1ac71c/0x1ac728/0x1ac72c
 *     （vmov s14,r0 → vcvt.f32.s32 → vstr），只看 0x1ac72c 的 vstr 会以为存的是 int。
 *   交叉印证：Draw_Room 0x1b4298-0x1b42b0 把 view+0x04/+0x08/+0x0c/+0x10/+0x24 原样喂
 *     GR_D3D_Set_View_Area(float,float,float,float,float) ⇒ 前四个就是视口矩形 x/y/w/h。
 *   +0x14..+0x20 四个 int 按 GM 序是 xport/yport/wport/hport（推断）；+0x28..+0x40 七个 int 未命名（open 2）。
 */

/* @0x1ac6b8 ldr r3, [r4] */
/* @0x1ac6bc mov r2, r5 */
/* @0x1ac6c0 mov r1, #6 */
/* @0x1ac6c4 mov r0, r4 */
/* @0x1ac6c8 ldr r7, [r9, #0x48] */
/* @0x1ac6cc add r10, r10, #1 */
/* @0x1ac6d0 ldr r3, [r3, #0xc] */
/* @0x1ac6d4 add r9, r9, #4 */
/* @0x1ac6d8 blx r3 */
/* @0x1ac6dc mov r1, #0 */
/* @0x1ac6e0 mov r0, r5 */
/* @0x1ac6e4 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1ac6e8 ldr r3, [r4] */
/* @0x1ac6ec mov r2, r5 */
/* @0x1ac6f0 mov r1, #6 */
/* @0x1ac6f4 ldr r3, [r3, #0xc] */
/* @0x1ac6f8 strb r0, [r7] */
/* @0x1ac6fc mov r0, r4 */
/* @0x1ac700 blx r3 */
/* @0x1ac704 mov r1, #0 */
/* @0x1ac708 mov r0, r5 */
/* @0x1ac70c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1ac710 ldr r3, [r4] */
/* @0x1ac714 mov r2, r5 */
/* @0x1ac718 mov r1, #6 */
/* @0x1ac71c ldr r3, [r3, #0xc] */
/* @0x1ac720 vmov s14, r0 */
/* @0x1ac724 mov r0, r4 */
/* @0x1ac728 vcvt.f32.s32 s15, s14 */
/* @0x1ac72c vstr s15, [r7, #4] */
/* @0x1ac730 blx r3 */
/* @0x1ac734 mov r1, #0 */
/* @0x1ac738 mov r0, r5 */
/* @0x1ac73c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1ac740 ldr r3, [r4] */
/* @0x1ac744 mov r2, r5 */
/* @0x1ac748 mov r1, #6 */
/* @0x1ac74c ldr r3, [r3, #0xc] */
/* @0x1ac750 vmov s14, r0 */
/* @0x1ac754 mov r0, r4 */
/* @0x1ac758 vcvt.f32.s32 s15, s14 */
/* @0x1ac75c vstr s15, [r7, #8] */
/* @0x1ac760 blx r3 */
/* @0x1ac764 mov r1, #0 */
/* @0x1ac768 mov r0, r5 */
/* @0x1ac76c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1ac770 ldr r3, [r4] */
/* @0x1ac774 mov r2, r5 */
/* @0x1ac778 mov r1, #6 */
/* @0x1ac77c ldr r3, [r3, #0xc] */
/* @0x1ac780 vmov s14, r0 */
/* @0x1ac784 mov r0, r4 */
/* @0x1ac788 vcvt.f32.s32 s15, s14 */
/* @0x1ac78c vstr s15, [r7, #12] */
/* @0x1ac790 blx r3 */
/* @0x1ac794 mov r1, #0 */
/* @0x1ac798 mov r0, r5 */
/* @0x1ac79c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1ac7a0 ldr r3, [r4] */
/* @0x1ac7a4 mov r2, r5 */
/* @0x1ac7a8 mov r1, #6 */
/* @0x1ac7ac ldr r3, [r3, #0xc] */
/* @0x1ac7b0 vmov s14, r0 */
/* @0x1ac7b4 mov r0, r4 */
/* @0x1ac7b8 vcvt.f32.s32 s15, s14 */
/* @0x1ac7bc vstr s15, [r7, #16] */
/* @0x1ac7c0 blx r3 */
/* @0x1ac7c4 mov r1, #0 */
/* @0x1ac7c8 mov r0, r5 */
/* @0x1ac7cc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1ac7d0 ldr r3, [r4] */
/* @0x1ac7d4 mov r2, r5 */
/* @0x1ac7d8 mov r1, #6 */
/* @0x1ac7dc ldr r3, [r3, #0xc] */
/* @0x1ac7e0 str r0, [r7, #0x14] */
/* @0x1ac7e4 mov r0, r4 */
/* @0x1ac7e8 blx r3 */
/* @0x1ac7ec mov r1, #0 */
/* @0x1ac7f0 mov r0, r5 */
/* @0x1ac7f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1ac7f8 ldr r3, [r4] */
/* @0x1ac7fc mov r2, r5 */
/* @0x1ac800 mov r1, #6 */
/* @0x1ac804 ldr r3, [r3, #0xc] */
/* @0x1ac808 str r0, [r7, #0x18] */
/* @0x1ac80c mov r0, r4 */
/* @0x1ac810 blx r3 */
/* @0x1ac814 mov r1, #0 */
/* @0x1ac818 mov r0, r5 */
/* @0x1ac81c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1ac820 ldr r3, [r4] */
/* @0x1ac824 mov r2, r5 */
/* @0x1ac828 mov r1, #6 */
/* @0x1ac82c ldr r3, [r3, #0xc] */
/* @0x1ac830 str r0, [r7, #0x1c] */
/* @0x1ac834 mov r0, r4 */
/* @0x1ac838 blx r3 */
/* @0x1ac83c mov r1, #0 */
/* @0x1ac840 mov r0, r5 */
/* @0x1ac844 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1ac848 ldr r3, [r4] */
/* @0x1ac84c mov r2, r5 */
/* @0x1ac850 mov r1, #8 */
/* @0x1ac854 ldr r3, [r3, #0xc] */
/* @0x1ac858 str r0, [r7, #0x20] */
/* @0x1ac85c mov r0, r4 */
/* @0x1ac860 blx r3 */
/* @0x1ac864 mov r1, #0 */
/* @0x1ac868 mov r0, r5 */
/* @0x1ac86c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1ac870 ldr r3, [r4] */
/* @0x1ac874 mov r2, r5 */
/* @0x1ac878 mov r1, #6 */
/* @0x1ac87c ldr r3, [r3, #0xc] */
/* @0x1ac880 str r0, [r7, #0x24] */
/* @0x1ac884 mov r0, r4 */
/* @0x1ac888 blx r3 */
/* @0x1ac88c mov r1, #0 */
/* @0x1ac890 mov r0, r5 */
/* @0x1ac894 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1ac898 ldr r3, [r4] */
/* @0x1ac89c mov r2, r5 */
/* @0x1ac8a0 mov r1, #6 */
/* @0x1ac8a4 ldr r3, [r3, #0xc] */
/* @0x1ac8a8 str r0, [r7, #0x28] */
/* @0x1ac8ac mov r0, r4 */
/* @0x1ac8b0 blx r3 */
/* @0x1ac8b4 mov r1, #0 */
/* @0x1ac8b8 mov r0, r5 */
/* @0x1ac8bc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1ac8c0 ldr r3, [r4] */
/* @0x1ac8c4 mov r2, r5 */
/* @0x1ac8c8 mov r1, #6 */
/* @0x1ac8cc ldr r3, [r3, #0xc] */
/* @0x1ac8d0 str r0, [r7, #0x2c] */
/* @0x1ac8d4 mov r0, r4 */
/* @0x1ac8d8 blx r3 */
/* @0x1ac8dc mov r1, #0 */
/* @0x1ac8e0 mov r0, r5 */
/* @0x1ac8e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1ac8e8 ldr r3, [r4] */
/* @0x1ac8ec mov r2, r5 */
/* @0x1ac8f0 mov r1, #6 */
/* @0x1ac8f4 ldr r3, [r3, #0xc] */
/* @0x1ac8f8 str r0, [r7, #0x30] */
/* @0x1ac8fc mov r0, r4 */
/* @0x1ac900 blx r3 */
/* @0x1ac904 mov r1, #0 */
/* @0x1ac908 mov r0, r5 */
/* @0x1ac90c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1ac910 ldr r3, [r4] */
/* @0x1ac914 mov r2, r5 */
/* @0x1ac918 mov r1, #6 */
/* @0x1ac91c ldr r3, [r3, #0xc] */
/* @0x1ac920 str r0, [r7, #0x34] */
/* @0x1ac924 mov r0, r4 */
/* @0x1ac928 blx r3 */
/* @0x1ac92c mov r1, #0 */
/* @0x1ac930 mov r0, r5 */
/* @0x1ac934 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1ac938 ldr r3, [r4] */
/* @0x1ac93c mov r2, r5 */
/* @0x1ac940 mov r1, #6 */
/* @0x1ac944 ldr r3, [r3, #0xc] */
/* @0x1ac948 str r0, [r7, #0x38] */
/* @0x1ac94c mov r0, r4 */
/* @0x1ac950 blx r3 */
/* @0x1ac954 mov r1, #0 */
/* @0x1ac958 mov r0, r5 */
/* @0x1ac95c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1ac960 ldr r3, [r4] */
/* @0x1ac964 mov r1, #6 */
/* @0x1ac968 mov r2, r5 */
/* @0x1ac96c ldr r3, [r3, #0xc] */
/* @0x1ac970 str r0, [r7, #0x3c] */
/* @0x1ac974 mov r0, r4 */
/* @0x1ac978 blx r3 */
/* @0x1ac97c mov r0, r5 */
/* @0x1ac980 mov r1, #0 */
/* @0x1ac984 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1ac988 cmp r10, #8 */
/* @0x1ac98c str r0, [r7, #0x40] */
/* @0x1ac990 bne 0x1ac6b8 <_ZN5CRoom11DeSerialiseEP7IBufferb+0x37c> */
/* ── tile 表：int n → 预分配 n*56 → 逐条 AddTile ───────────────────
 *   n = YYGetInt32(&rv,0) → r8。n == 0 → 1ac9c0（有旧数组就 Free，然后 +0xc0/+0xbc 清零）。
 *   否则 ReAlloc([+0xc0], n*56, "../jni/yoyo/../../../Files/Platform/cARRAY_STRUCTURE.h", 106, false)
 *     —— 步长算式 rsb r3,r8,r8,lsl#3（=n*7）再 lsl #3（=n*56），与 DoSlowDrawRoom 的 i*56 同源。
 *   → [+0xc0] = 新基址；[+0xbc] = n。
 *   ★ 三个字段的角色在 CRoom::AddTile 0x1ac240 里才彻底分明（它是唯一的写入口）：
 *       +0xb8 = 计数（AddTile 里 cmp count,cap、末尾 add #1 写回；DoSlowDrawRoom 拿它当循环上界）
 *       +0xbc = 容量（AddTile 的 cmp 对手；本函数预置成 n，于是正常路径永远不会触发扩容）
 *       +0xc0 = 数据基址
 *     旧卡记「+0xb8 条数、+0xc0 基址」正确；+0xbc 不是条数而是容量，两值只在 AddTile 扩容
 *     （cap < count 时 +10）之后才分叉。
 *   ★ 本函数**不清零 +0xb8**：依赖「新房间 +0xb8 == 0」。对已有 tile 的房间重入本函数会从旧
 *     count 继续追加，而容量只被置成 n ⇒ 越界写（open，未运行期验证）。
 */

/* @0x1ac994 ldr r3, [r4] */
/* @0x1ac998 mov r1, #6 */
/* @0x1ac99c mov r2, r5 */
/* @0x1ac9a0 mov r0, r4 */
/* @0x1ac9a4 ldr r3, [r3, #0xc] */
/* @0x1ac9a8 blx r3 */
/* @0x1ac9ac mov r0, r5 */
/* @0x1ac9b0 mov r1, #0 */
/* @0x1ac9b4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1ac9b8 subs r8, r0, #0 */
/* @0x1ac9bc bne 0x1ac9dc <_ZN5CRoom11DeSerialiseEP7IBufferb+0x6a0> */
/* ── n == 0 的出口：旧数组非空就先 Free，再 +0xc0 = 0、+0xbc = 0 ──────
 *   1acf40 是另一条同义出口（ReAlloc 尺寸算成 0 时），两者都跳回 1aca08 写 +0xbc。
 */

/* @0x1ac9c0 ldr r0, [r6, #0xc0] */
/* @0x1ac9c4 cmp r0, #0 */
/* @0x1ac9c8 beq 0x1acf40 <_ZN5CRoom11DeSerialiseEP7IBufferb+0xc04> */
/* @0x1ac9cc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1ac9d0 str r8, [r6, #0xc0] */
/* @0x1ac9d4 str r8, [r6, #0xbc] */
/* @0x1ac9d8 b 0x1acc98 <_ZN5CRoom11DeSerialiseEP7IBufferb+0x95c> */
/* @0x1ac9dc rsb r3, r8, r8, lsl #3 */
/* @0x1ac9e0 ldr r0, [r6, #0xc0] */
/* @0x1ac9e4 lsls r1, r3, #3 */
/* @0x1ac9e8 beq 0x1acf40 <_ZN5CRoom11DeSerialiseEP7IBufferb+0xc04> */
/* @0x1ac9ec ldr r2, [pc, #0x658] */
/* @0x1ac9f0 mov r3, #0 */
/* @0x1ac9f4 str r3, [sp] */
/* @0x1ac9f8 mov r3, #106 */
/* @0x1ac9fc add r2, pc, r2 */
/* @0x1aca00 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1aca04 str r0, [r6, #0xc0] */
/* @0x1aca08 cmp r8, #0 */
/* @0x1aca0c str r8, [r6, #0xbc] */
/* @0x1aca10 ble 0x1acc98 <_ZN5CRoom11DeSerialiseEP7IBufferb+0x95c> */
/* ── tile 循环：56 B 记录先建在栈上（r9 = sp+0x28），再整块交给 AddTile ──
 *   14 字段的读序与类型（与 CRoom::Serialise 0x1aa994-0x1aab00 的写出序**完全互逆**）：
 *     rec+0x00 float  rec+0x04 float  rec+0x08 int    rec+0x0c int   rec+0x10 int
 *     rec+0x14 int    rec+0x18 int    rec+0x1c float  rec+0x20 int   rec+0x24 float
 *     rec+0x28 float  rec+0x2c int    rec+0x30 float  rec+0x34 bool
 *   与 DoSlowDrawRoom 的读集对齐：0x00/0x04 = x/y，0x08 = 背景号（喂 Background_Exists/Data），
 *   0x0c..0x18 = 源矩形四边，0x1c = depth(float)，0x24/0x28 = tile 宽/高，0x2c/0x30 = DrawPart 末两参。
 *   ★ 订正一处旧说法：DoSlowDrawRoom 卡把 +0x2c/+0x30 都记作 float；序列化端 +0x2c 用类型码 6
 *     （int），+0x30 才是类型码 8（float）。绘制端两者都走 ldr —— softfp 下 float 也走核心寄存器，
 *     所以 ldr 不能反证类型，按序列化类型定：+0x2c = int，+0x30 = float。
 *   ★ r10 = *(GOT 0x3f0818) = &room_maxtileid（.bss 0x542558），每轮 **减 1**（见 1acc70 段）。
 */

/* @0x1aca14 ldr r3, [pc, #0x634] */
/* @0x1aca18 add r9, sp, #40 */
/* @0x1aca1c ldr r12, [sp, #0x1c] */
/* @0x1aca20 mov r7, #0 */
/* @0x1aca24 ldr r10, [r12, r3] */
/* @0x1aca28 str r11, [sp, #0x14] */
/* @0x1aca2c ldr r3, [r4] */
/* @0x1aca30 mov r2, r5 */
/* @0x1aca34 mov r1, #8 */
/* @0x1aca38 mov r0, r4 */
/* @0x1aca3c add r7, r7, #1 */
/* @0x1aca40 ldr r3, [r3, #0xc] */
/* @0x1aca44 blx r3 */
/* @0x1aca48 mov r1, #0 */
/* @0x1aca4c mov r0, r5 */
/* @0x1aca50 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1aca54 ldr r3, [r4] */
/* @0x1aca58 mov r2, r5 */
/* @0x1aca5c mov r1, #8 */
/* @0x1aca60 ldr r3, [r3, #0xc] */
/* @0x1aca64 str r0, [sp, #0x28] */
/* @0x1aca68 mov r0, r4 */
/* @0x1aca6c blx r3 */
/* @0x1aca70 mov r1, #0 */
/* @0x1aca74 mov r0, r5 */
/* @0x1aca78 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1aca7c ldr r3, [r4] */
/* @0x1aca80 mov r2, r5 */
/* @0x1aca84 mov r1, #6 */
/* @0x1aca88 ldr r3, [r3, #0xc] */
/* @0x1aca8c str r0, [sp, #0x2c] */
/* @0x1aca90 mov r0, r4 */
/* @0x1aca94 blx r3 */
/* @0x1aca98 mov r1, #0 */
/* @0x1aca9c mov r0, r5 */
/* @0x1acaa0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1acaa4 ldr r3, [r4] */
/* @0x1acaa8 mov r2, r5 */
/* @0x1acaac mov r1, #6 */
/* @0x1acab0 ldr r3, [r3, #0xc] */
/* @0x1acab4 str r0, [sp, #0x30] */
/* @0x1acab8 mov r0, r4 */
/* @0x1acabc blx r3 */
/* @0x1acac0 mov r1, #0 */
/* @0x1acac4 mov r0, r5 */
/* @0x1acac8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1acacc ldr r3, [r4] */
/* @0x1acad0 mov r2, r5 */
/* @0x1acad4 mov r1, #6 */
/* @0x1acad8 ldr r3, [r3, #0xc] */
/* @0x1acadc str r0, [sp, #0x34] */
/* @0x1acae0 mov r0, r4 */
/* @0x1acae4 blx r3 */
/* @0x1acae8 mov r1, #0 */
/* @0x1acaec mov r0, r5 */
/* @0x1acaf0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1acaf4 ldr r3, [r4] */
/* @0x1acaf8 mov r2, r5 */
/* @0x1acafc mov r1, #6 */
/* @0x1acb00 ldr r3, [r3, #0xc] */
/* @0x1acb04 str r0, [sp, #0x38] */
/* @0x1acb08 mov r0, r4 */
/* @0x1acb0c blx r3 */
/* @0x1acb10 mov r1, #0 */
/* @0x1acb14 mov r0, r5 */
/* @0x1acb18 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1acb1c ldr r3, [r4] */
/* @0x1acb20 mov r2, r5 */
/* @0x1acb24 mov r1, #6 */
/* @0x1acb28 ldr r3, [r3, #0xc] */
/* @0x1acb2c str r0, [sp, #0x3c] */
/* @0x1acb30 mov r0, r4 */
/* @0x1acb34 blx r3 */
/* @0x1acb38 mov r1, #0 */
/* @0x1acb3c mov r0, r5 */
/* @0x1acb40 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1acb44 ldr r3, [r4] */
/* @0x1acb48 mov r2, r5 */
/* @0x1acb4c mov r1, #8 */
/* @0x1acb50 ldr r3, [r3, #0xc] */
/* @0x1acb54 str r0, [sp, #0x40] */
/* @0x1acb58 mov r0, r4 */
/* @0x1acb5c blx r3 */
/* @0x1acb60 mov r1, #0 */
/* @0x1acb64 mov r0, r5 */
/* @0x1acb68 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1acb6c ldr r3, [r4] */
/* @0x1acb70 mov r2, r5 */
/* @0x1acb74 mov r1, #6 */
/* @0x1acb78 ldr r3, [r3, #0xc] */
/* @0x1acb7c str r0, [sp, #0x44] */
/* @0x1acb80 mov r0, r4 */
/* @0x1acb84 blx r3 */
/* @0x1acb88 mov r1, #0 */
/* @0x1acb8c mov r0, r5 */
/* @0x1acb90 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1acb94 ldr r3, [r4] */
/* @0x1acb98 mov r2, r5 */
/* @0x1acb9c mov r1, #8 */
/* @0x1acba0 ldr r3, [r3, #0xc] */
/* @0x1acba4 str r0, [sp, #0x48] */
/* @0x1acba8 mov r0, r4 */
/* @0x1acbac blx r3 */
/* @0x1acbb0 mov r1, #0 */
/* @0x1acbb4 mov r0, r5 */
/* @0x1acbb8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1acbbc ldr r3, [r4] */
/* @0x1acbc0 mov r2, r5 */
/* @0x1acbc4 mov r1, #8 */
/* @0x1acbc8 ldr r3, [r3, #0xc] */
/* @0x1acbcc str r0, [sp, #0x4c] */
/* @0x1acbd0 mov r0, r4 */
/* @0x1acbd4 blx r3 */
/* @0x1acbd8 mov r1, #0 */
/* @0x1acbdc mov r0, r5 */
/* @0x1acbe0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1acbe4 ldr r3, [r4] */
/* @0x1acbe8 mov r2, r5 */
/* @0x1acbec mov r1, #6 */
/* @0x1acbf0 ldr r3, [r3, #0xc] */
/* @0x1acbf4 str r0, [sp, #0x50] */
/* @0x1acbf8 mov r0, r4 */
/* @0x1acbfc blx r3 */
/* @0x1acc00 mov r1, #0 */
/* @0x1acc04 mov r0, r5 */
/* @0x1acc08 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1acc0c ldr r3, [r4] */
/* @0x1acc10 mov r2, r5 */
/* @0x1acc14 mov r1, #8 */
/* @0x1acc18 ldr r3, [r3, #0xc] */
/* @0x1acc1c str r0, [sp, #0x54] */
/* @0x1acc20 mov r0, r4 */
/* @0x1acc24 blx r3 */
/* @0x1acc28 mov r1, #0 */
/* @0x1acc2c mov r0, r5 */
/* @0x1acc30 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1acc34 ldr r3, [r4] */
/* @0x1acc38 mov r2, r5 */
/* @0x1acc3c mov r1, #6 */
/* @0x1acc40 ldr r3, [r3, #0xc] */
/* @0x1acc44 str r0, [sp, #0x58] */
/* @0x1acc48 mov r0, r4 */
/* @0x1acc4c blx r3 */
/* @0x1acc50 mov r1, #0 */
/* @0x1acc54 mov r0, r5 */
/* @0x1acc58 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1acc5c mov r1, r9 */
/* @0x1acc60 ldr r11, [sp, #0x48] */
/* @0x1acc64 strb r0, [sp, #0x5c] */
/* @0x1acc68 mov r0, r6 */
/* @0x1acc6c bl 0x1ac240 <_ZN5CRoom7AddTileEP5RTile> */
/* ── AddTile 返回下标后两件事：回填 id、把 room_maxtileid 退回去 ──────
 *   r0 = AddTile(&rec) = 新 tile 下标；r2 = [+0xc0] + idx*56（rsb r0,r0,r0,lsl#3 → idx*7 → lsl #3）
 *   [r2+0x20] = rec+0x20   用流里的值覆盖 AddTile 刚写进去的 id
 *   [r10]     = [r10] - 1  把 AddTile 刚做的 room_maxtileid++ 撤回
 *   ⇒ AddTile 的 0x1ac28c-0x1ac2b0 是「++room_maxtileid 并写进 tile+0x20」；本函数立刻反向抵消。
 *     净效果：tile+0x20 取流里的值，全局计数器回到进入本函数前的值。
 *   ★ 后果（open 6）：room_maxtileid 不会抬到流里 tile id 的最大值，读档后新建的 tile 会与流里
 *     已存在的 id 重号。AddTile 的另一副作用 CRoom+0x00 = 最新 tile 下标（0x1ac2b4）本函数不读。
 */

/* @0x1acc70 ldr r2, [r6, #0xc0] */
/* @0x1acc74 ldr r1, [r10] */
/* @0x1acc78 cmp r7, r8 */
/* @0x1acc7c sub r1, r1, #1 */
/* @0x1acc80 str r1, [r10] */
/* @0x1acc84 rsb r0, r0, r0, lsl #3 */
/* @0x1acc88 add r2, r2, r0, lsl #3 */
/* @0x1acc8c str r11, [r2, #0x20] */
/* @0x1acc90 bne 0x1aca2c <_ZN5CRoom11DeSerialiseEP7IBufferb+0x6f0> */
/* ── layer 表：int n → n 次 CLayerManager::DeSerializeLayer(CRoom*, IBuffer*) ──
 *   循环体只有一条 bl（0x1accd0），层对象的一切解析在被调方 0x1c74d0；本函数只管次数。
 *   与 CRoom::Serialise 对读：那边是 [room+0xdc] 计数 + CLayer+0x68 链逐个 CLayer::Serialize
 *   ⇒ 房间的层集合在 **+0xdc 链**上，不在 +0xb8/+0xc0 的 56 B 数组里（那是 tile 表）。
 *   进循环前把 bRegister 存回 [sp+0x14]（r11 被 tile 循环借去当暂存了），循环后 0x1acc94 取回。
 */

/* @0x1acc94 ldr r11, [sp, #0x14] */
/* @0x1acc98 ldr r3, [r4] */
/* @0x1acc9c mov r1, #6 */
/* @0x1acca0 mov r2, r5 */
/* @0x1acca4 mov r0, r4 */
/* @0x1acca8 ldr r3, [r3, #0xc] */
/* @0x1accac blx r3 */
/* @0x1accb0 mov r0, r5 */
/* @0x1accb4 mov r1, #0 */
/* @0x1accb8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1accbc subs r8, r0, #0 */
/* @0x1accc0 movgt r7, #0 */
/* @0x1accc4 ble 0x1acce0 <_ZN5CRoom11DeSerialiseEP7IBufferb+0x9a4> */
/* @0x1accc8 add r7, r7, #1 */
/* @0x1acccc mov r0, r6 */
/* @0x1accd0 mov r1, r4 */
/* @0x1accd4 bl 0x1c74d0 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer> */
/* @0x1accd8 cmp r7, r8 */
/* @0x1accdc bne 0x1accc8 <_ZN5CRoom11DeSerialiseEP7IBufferb+0x98c> */
/* ── 实例表 A（活动实例）：int n → n × (new(432) + CInstance + DeSerialise + 挂深度降序链) ──
 *   每轮：new(432) → CInstance(0.0f, 0.0f, 0, 0, false)（softfp：五个 0 走 r1/r2/r3 + [sp]/[sp+4]）
 *        → CInstance::DeSerialise(buf, bRegister)
 *        → 挂 CRoom+0x84(头) / +0x80(尾) 的双向链；链域 +0x178(prev)/+0x17c(next)；
 *          计数 +0x88；排序键 +0x184（插入时从 +0x180 拷一份 depth 快照）
 *   ★ 本段与 CRoom::AddInstance(CInstance*) 0x1ab654 **逐指令同构**（同 head/tail/计数/排序键、
 *     同空表分支）⇒ 这是 AddInstance 的内联展开，不是第三套链表。
 *   ★ 循环体里 r5/r4 都被征用（r5 = 新实例、r4 = 仍是 buf），所以进出都靠 [sp,#0x24] 存 buf 指针。
 */

/* @0x1acce0 ldr r3, [r4] */
/* @0x1acce4 mov r1, #6 */
/* @0x1acce8 mov r2, r5 */
/* @0x1accec mov r0, r4 */
/* @0x1accf0 ldr r3, [r3, #0xc] */
/* @0x1accf4 blx r3 */
/* @0x1accf8 mov r0, r5 */
/* @0x1accfc mov r1, #0 */
/* @0x1acd00 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1acd04 subs r9, r0, #0 */
/* @0x1acd08 ble 0x1acdc0 <_ZN5CRoom11DeSerialiseEP7IBufferb+0xa84> */
/* @0x1acd0c ldr r12, [pc, #0x340] */
/* @0x1acd10 mov r8, #0 */
/* @0x1acd14 mov r10, r8 */
/* @0x1acd18 str r5, [sp, #0x24] */
/* @0x1acd1c add r12, pc, r12 */
/* @0x1acd20 str r12, [sp, #0x20] */
/* @0x1acd24 mov r0, #432 */
/* @0x1acd28 bl 0x27c524 <_Znwj> */
/* @0x1acd2c mov r1, #0 */
/* @0x1acd30 mov r3, #0 */
/* @0x1acd34 mov r2, r1 */
/* @0x1acd38 str r10, [sp] */
/* @0x1acd3c str r10, [sp, #0x4] */
/* @0x1acd40 mov r5, r0 */
/* @0x1acd44 bl 0x1994dc <_ZN9CInstanceC2Effiib> */
/* @0x1acd48 mov r2, r11 */
/* @0x1acd4c mov r0, r5 */
/* @0x1acd50 mov r1, r4 */
/* @0x1acd54 bl 0x19766c <_ZN9CInstance11DeSerialiseEP7IBufferb> */
/* ── 深度降序插入：从 head 起 while (cur->[0x184] > new) 前进，停在第一个 cur <= new 处前插 ──
 *   0x1acd78 vcmpe s14,s15 + bge → 大于等于就停（不是小于），所以链是 **depth 降序**、head = 最深。
 *   与绘制侧自洽：DoSlowDrawRoom 前进式输出（深度大的先画 = 画家算法由远到近）。
 *   走到链尾（next == 0）则尾插：tail->next = inst、inst->prev = tail、+0x80 = inst、inst->next = 0。
 */

/* @0x1acd58 ldr r3, [r6, #0x84] */
/* @0x1acd5c ldr r2, [r6, #0x88] */
/* @0x1acd60 cmp r3, #0 */
/* @0x1acd64 vldrne s14, [r5, #384] */
/* @0x1acd68 add r2, r2, #1 */
/* @0x1acd6c str r2, [r6, #0x88] */
/* @0x1acd70 beq 0x1ad02c <_ZN5CRoom11DeSerialiseEP7IBufferb+0xcf0> */
/* @0x1acd74 vldr s15, [r3, #388] */
/* @0x1acd78 vcmpe.f32 s14, s15 */
/* @0x1acd7c vmrs APSR_nzcv, fpscr */
/* @0x1acd80 bge 0x1acf50 <_ZN5CRoom11DeSerialiseEP7IBufferb+0xc14> */
/* @0x1acd84 ldr r3, [r3, #0x17c] */
/* @0x1acd88 cmp r3, #0 */
/* @0x1acd8c bne 0x1acd74 <_ZN5CRoom11DeSerialiseEP7IBufferb+0xa38> */
/* @0x1acd90 ldr r2, [r6, #0x80] */
/* @0x1acd94 vstr s14, [r5, #388] */
/* @0x1acd98 str r5, [r2, #0x17c] */
/* @0x1acd9c str r2, [r5, #0x178] */
/* @0x1acda0 str r5, [r6, #0x80] */
/* @0x1acda4 str r3, [r5, #0x17c] */
/* ── bRegister 分叉：非 0 才做「注册」两件事（ID 哈希表 + CLayerManager::AddInstance）──
 *   0 → 直接回循环；非 0 → 1acf88。
 */

/* @0x1acda8 cmp r11, #0 */
/* @0x1acdac bne 0x1acf88 <_ZN5CRoom11DeSerialiseEP7IBufferb+0xc4c> */
/* @0x1acdb0 add r8, r8, #1 */
/* @0x1acdb4 cmp r8, r9 */
/* @0x1acdb8 bne 0x1acd24 <_ZN5CRoom11DeSerialiseEP7IBufferb+0x9e8> */
/* @0x1acdbc ldr r5, [sp, #0x24] */
/* ── 实例表 B（非活动实例）：int n → 同构造，但挂另一条链 ─────────────
 *   +0x90 头 / +0x8c 尾 / +0x94 计数，链域仍是 +0x178/+0x17c，**头插**（无序）。
 *   ★ 两链共用同一对链域 ⇒ 一个实例同一时刻只能在其中一条上 —— 这正是 CRoom::UpdateActive
 *     0x1abd9c 的职责：按 [inst+0x69] 在 A/B 之间搬（0x69 != 0 = 非活动）。
 *     所以流里的两段不是重复，而是「活动实例」「已 deactivate 实例」两份清单。
 *   ★ +0x8c 只在「表由空变非空」时写一次（1ace6c），此后头插不再更新它 ⇒ 它是**尾**，
 *     且 B 段只头插不尾插，首插的那个实例永远留在尾部。CRoom::Serialise 正是从 [+0x8c]
 *     沿 +0x178(prev) 反向走完整链（0x1aacdc-0x1aad28）—— 这同时反证 +0x178 = prev。
 */

/* @0x1acdc0 ldr r3, [r4] */
/* @0x1acdc4 mov r1, #6 */
/* @0x1acdc8 mov r2, r5 */
/* @0x1acdcc mov r0, r4 */
/* @0x1acdd0 ldr r3, [r3, #0xc] */
/* @0x1acdd4 blx r3 */
/* @0x1acdd8 mov r0, r5 */
/* @0x1acddc mov r1, #0 */
/* @0x1acde0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1acde4 subs r10, r0, #0 */
/* @0x1acde8 ble 0x1acf38 <_ZN5CRoom11DeSerialiseEP7IBufferb+0xbfc> */
/* @0x1acdec ldr r12, [pc, #0x264] */
/* @0x1acdf0 mov r8, #0 */
/* @0x1acdf4 mov r9, r10 */
/* @0x1acdf8 mov r7, r8 */
/* @0x1acdfc add r12, pc, r12 */
/* @0x1ace00 mov r10, r4 */
/* @0x1ace04 str r12, [sp, #0x20] */
/* @0x1ace08 b 0x1ace18 <_ZN5CRoom11DeSerialiseEP7IBufferb+0xadc> */
/* @0x1ace0c add r8, r8, #1 */
/* @0x1ace10 cmp r8, r9 */
/* @0x1ace14 beq 0x1acf38 <_ZN5CRoom11DeSerialiseEP7IBufferb+0xbfc> */
/* @0x1ace18 mov r0, #432 */
/* @0x1ace1c bl 0x27c524 <_Znwj> */
/* @0x1ace20 mov r1, #0 */
/* @0x1ace24 mov r3, #0 */
/* @0x1ace28 mov r2, r1 */
/* @0x1ace2c str r7, [sp] */
/* @0x1ace30 str r7, [sp, #0x4] */
/* @0x1ace34 mov r4, r0 */
/* @0x1ace38 bl 0x1994dc <_ZN9CInstanceC2Effiib> */
/* @0x1ace3c mov r2, r11 */
/* @0x1ace40 mov r0, r4 */
/* @0x1ace44 mov r1, r10 */
/* @0x1ace48 bl 0x19766c <_ZN9CInstance11DeSerialiseEP7IBufferb> */
/* ── B 段头插：靠 streq/strne 成对做完（Z 来自 1ace54 的 cmp r3,#0）──────
 *   old_head == 0: [+0x90] = inst、[+0x8c] = inst、inst->next = 0、inst->prev = 0
 *   old_head != 0: inst->next = old_head、old_head->prev = inst、[+0x90] = inst、inst->prev = 0
 *   两条链都不带哨兵元素：head/tail 直接是首/末实例，空链用 0 表示。
 */

/* @0x1ace4c ldr r3, [r6, #0x90] */
/* @0x1ace50 ldr r2, [r6, #0x94] */
/* @0x1ace54 cmp r3, #0 */
/* @0x1ace58 streq r4, [r6, #0x90] */
/* @0x1ace5c add r2, r2, #1 */
/* @0x1ace60 str r2, [r6, #0x94] */
/* @0x1ace64 strne r4, [r3, #0x178] */
/* @0x1ace68 ldrne r3, [r6, #0x90] */
/* @0x1ace6c streq r4, [r6, #0x8c] */
/* @0x1ace70 streq r3, [r4, #0x17c] */
/* @0x1ace74 strne r3, [r4, #0x17c] */
/* @0x1ace78 streq r3, [r4, #0x178] */
/* @0x1ace7c strne r4, [r6, #0x90] */
/* @0x1ace80 strne r7, [r4, #0x178] */
/* @0x1ace84 cmp r11, #0 */
/* @0x1ace88 beq 0x1ace0c <_ZN5CRoom11DeSerialiseEP7IBufferb+0xad0> */
/* ── 注册①：插入 ms_ID2InstanceE，再注册②：CLayerManager::AddInstance ─────────
 *   ID 表：GOT 0x3edc4c → .bss 0x536f28 = CInstance::ms_ID2InstanceE
 *           { +0x00 桶数组, +0x04 mask, +0x08 count }；桶 8 B { head@0, tail@+4 }
 *           节点 16 B { next@0, prev@4, key@8 (= inst+0x78), inst@0xc }；槽 = key & mask
 *           Alloc(16, "jni/../jni/yoyo/../../../Platform/Hash.h", 306, true)  ← movw r2,#0x132 即 306
 *   然后 1acf2c 调 CLayerManager::AddInstance(this, inst)。
 *   ★ 顺序不可换：先入 ID 表再入层管理器；A 段与 B 段两份代码完全对称（只有寄存器分配不同）。
 *   ★ 只在 bRegister != 0 时执行 ⇒ 读档路径（bool=1）会重建 ID 索引；bool=0 时实例只进链、
 *     不进哈希表（谁补索引 = open 5）。
 */

/* @0x1ace8c ldr r12, [r4, #0x78] */
/* @0x1ace90 movw r2, #0x132 */
/* @0x1ace94 ldr lr, [pc, #0x1c0] */
/* @0x1ace98 mov r3, #1 */
/* @0x1ace9c ldr r1, [sp, #0x20] */
/* @0x1acea0 mov r0, #16 */
/* @0x1acea4 str r12, [sp, #0x18] */
/* @0x1acea8 add r8, r8, #1 */
/* @0x1aceac ldr r12, [sp, #0x1c] */
/* @0x1aceb0 ldr r5, [r12, lr] */
/* @0x1aceb4 ldr r12, [r5] */
/* @0x1aceb8 ldr lr, [r5, #0x4] */
/* @0x1acebc str r12, [sp, #0x24] */
/* @0x1acec0 ldr r12, [sp, #0x18] */
/* @0x1acec4 and r12, r12, lr */
/* @0x1acec8 str r12, [sp, #0x14] */
/* @0x1acecc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1aced0 ldr r12, [sp, #0x14] */
/* @0x1aced4 ldr lr, [sp, #0x24] */
/* @0x1aced8 mov r1, r4 */
/* @0x1acedc add r3, lr, r12, lsl #3 */
/* @0x1acee0 ldr r2, [lr, r12, lsl #3] */
/* @0x1acee4 ldr r12, [sp, #0x18] */
/* @0x1acee8 cmp r2, #0 */
/* @0x1aceec ldrne r2, [r3, #0x4] */
/* @0x1acef0 str r12, [r0, #0x8] */
/* @0x1acef4 ldreq r12, [sp, #0x14] */
/* @0x1acef8 str r4, [r0, #0xc] */
/* @0x1acefc strne r2, [r0] */
/* @0x1acf00 streq r0, [r3, #0x4] */
/* @0x1acf04 strne r0, [r2, #0x4] */
/* @0x1acf08 strne r0, [r3, #0x4] */
/* @0x1acf0c ldr r3, [r5, #0x8] */
/* @0x1acf10 streq r0, [lr, r12, lsl #3] */
/* @0x1acf14 strne r7, [r0, #0x4] */
/* @0x1acf18 add r3, r3, #1 */
/* @0x1acf1c streq r2, [r0, #0x4] */
/* @0x1acf20 streq r2, [r0] */
/* @0x1acf24 mov r0, r6 */
/* @0x1acf28 str r3, [r5, #0x8] */
/* @0x1acf2c bl 0x1c5d18 <_ZN13CLayerManager11AddInstanceEP5CRoomP9CInstance> */
/* @0x1acf30 cmp r8, r9 */
/* @0x1acf34 bne 0x1ace18 <_ZN5CRoom11DeSerialiseEP7IBufferb+0xadc> */
/* ── 正常收尾：add sp,#100 / pop {r4-r11,pc}（无返回值）─────────────
 *   1acf40 是另一条出口：Free([+0xc0]) 后清 +0xc0，跳回 1aca08 写 +0xbc = 0。
 */

/* @0x1acf38 add sp, sp, #100 */
/* @0x1acf3c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1acf40 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1acf44 mov r3, #0 */
/* @0x1acf48 str r3, [r6, #0xc0] */
/* @0x1acf4c b 0x1aca08 <_ZN5CRoom11DeSerialiseEP7IBufferb+0x6cc> */
/* ── 深度降序链的「前插」（插在中间或成为新 head）─────────────────
 *   cur->prev == 0 → 成为新 head（[+0x84] = inst、inst->prev = 0、cur->prev = inst）
 *   否则插到 prev 与 cur 之间（inst->prev = prev、prev->next = inst、inst->next = cur、cur->prev = inst）
 *   两路最后都 vstr depth → inst+0x184；与 AddInstance 0x1ab740-0x1ab76c 逐条同构。
 */

/* @0x1acf50 ldr r2, [r3, #0x178] */
/* @0x1acf54 cmp r2, #0 */
/* @0x1acf58 streq r3, [r5, #0x17c] */
/* @0x1acf5c strne r2, [r5, #0x178] */
/* @0x1acf60 ldrne r2, [r3, #0x178] */
/* @0x1acf64 streq r5, [r3, #0x178] */
/* @0x1acf68 strne r3, [r5, #0x17c] */
/* @0x1acf6c streq r5, [r6, #0x84] */
/* @0x1acf70 strne r5, [r2, #0x17c] */
/* @0x1acf74 streq r2, [r5, #0x178] */
/* @0x1acf78 strne r5, [r3, #0x178] */
/* @0x1acf7c cmp r11, #0 */
/* @0x1acf80 vstr s14, [r5, #388] */
/* @0x1acf84 beq 0x1acdb0 <_ZN5CRoom11DeSerialiseEP7IBufferb+0xa74> */
/* @0x1acf88 ldr r12, [r5, #0x78] */
/* @0x1acf8c movw r2, #0x132 */
/* @0x1acf90 ldr lr, [pc, #0xc4] */
/* @0x1acf94 mov r3, #1 */
/* @0x1acf98 ldr r1, [sp, #0x20] */
/* @0x1acf9c mov r0, #16 */
/* @0x1acfa0 str r12, [sp, #0x18] */
/* @0x1acfa4 ldr r12, [sp, #0x1c] */
/* @0x1acfa8 ldr r7, [r12, lr] */
/* @0x1acfac ldr r12, [r7] */
/* @0x1acfb0 ldr lr, [r7, #0x4] */
/* @0x1acfb4 str r12, [sp, #0xc] */
/* @0x1acfb8 ldr r12, [sp, #0x18] */
/* @0x1acfbc and r12, r12, lr */
/* @0x1acfc0 str r12, [sp, #0x14] */
/* @0x1acfc4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1acfc8 ldr r12, [sp, #0x14] */
/* @0x1acfcc ldr lr, [sp, #0xc] */
/* @0x1acfd0 mov r1, r5 */
/* @0x1acfd4 add r3, lr, r12, lsl #3 */
/* @0x1acfd8 ldr r2, [lr, r12, lsl #3] */
/* @0x1acfdc ldr r12, [sp, #0x18] */
/* @0x1acfe0 cmp r2, #0 */
/* @0x1acfe4 ldrne r2, [r3, #0x4] */
/* @0x1acfe8 str r12, [r0, #0x8] */
/* @0x1acfec ldreq r12, [sp, #0x14] */
/* @0x1acff0 str r5, [r0, #0xc] */
/* @0x1acff4 strne r2, [r0] */
/* @0x1acff8 streq r0, [r3, #0x4] */
/* @0x1acffc strne r0, [r2, #0x4] */
/* @0x1ad000 strne r0, [r3, #0x4] */
/* @0x1ad004 ldr r3, [r7, #0x8] */
/* @0x1ad008 streq r0, [lr, r12, lsl #3] */
/* @0x1ad00c strne r10, [r0, #0x4] */
/* @0x1ad010 add r3, r3, #1 */
/* @0x1ad014 streq r2, [r0, #0x4] */
/* @0x1ad018 streq r2, [r0] */
/* @0x1ad01c mov r0, r6 */
/* @0x1ad020 str r3, [r7, #0x8] */
/* @0x1ad024 bl 0x1c5d18 <_ZN13CLayerManager11AddInstanceEP5CRoomP9CInstance> */
/* @0x1ad028 b 0x1acdb0 <_ZN5CRoom11DeSerialiseEP7IBufferb+0xa74> */
/* ── 空链首插：head = tail = inst，+0x184 = +0x180（depth 快照），两链域清零 ──
 *   与 AddInstance 0x1ab774-0x1ab788 同构。
 */

/* @0x1ad02c ldr r2, [r5, #0x180] */
/* @0x1ad030 str r5, [r6, #0x84] */
/* @0x1ad034 str r5, [r6, #0x80] */
/* @0x1ad038 str r2, [r5, #0x184] */
/* @0x1ad03c str r3, [r5, #0x17c] */
/* @0x1ad040 str r3, [r5, #0x178] */
/* @0x1ad044 b 0x1acda8 <_ZN5CRoom11DeSerialiseEP7IBufferb+0xa6c> */
/* ── literal pool（1ad048..1ad05c，5 字；objdump 把前四个译成指令，非指令）──
 *   1ad048 = 0x002458e4  加数：pc 0x1ac374 + 0x2458e4 = 0x3f1c58（GOT 基址）
 *   1ad04c = 0x001a0838  加数：pc 0x1aca08 + 0x1a0838 = 0x34d240 = "../jni/yoyo/../../../Files/Platform/cARRAY_STRUCTURE.h"
 *   1ad050 = 0xffffebc0  GOT 偏移 -0x1440 → 槽 0x3f0818 → .bss 0x542558 = room_maxtileid
 *   1ad054 = 0x0019ff90  加数：pc 0x1acd24 + 0x19ff90 = 0x34ccb4 = "jni/../jni/yoyo/../../../Platform/Hash.h"
 *   1ad058 = 0x0019feb0  加数：pc 0x1ace04 + 0x19feb0 = 0x34ccb4（同一个 Hash.h 串）
 *   1ad05c = 0xffffbff4  GOT 偏移 -0x400c → 槽 0x3edc4c → .bss 0x536f28 = ms_ID2InstanceE
 */

/* @0x1ad048 eoreq r5, r4, r4, ror #17 */
/* @0x1ad04c andseq r0, r10, r8, lsr r8 */
/* @0x1ad050 .word 0xffffebc0 */
/* @0x1ad054 mulseq r9, r0, pc */
/* @0x1ad058 ldrheq pc, [r9], -r0 */
/* @0x1ad05c .word 0xffffbff4 */
