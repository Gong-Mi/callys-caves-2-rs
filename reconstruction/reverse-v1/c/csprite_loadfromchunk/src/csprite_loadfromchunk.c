/* csprite_loadfromchunk.c — CSprite::LoadFromChunk(YYSprite*, unsigned char*) 的静态 C 译文
 *
 * 原版：libyoyo_armv7.so
 *       sha256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 *       _ZN7CSprite13LoadFromChunkEP8YYSpritePh   0x1e972c   size 1084
 *       268 条指令（0x1e972c..0x1e9b5c）+ 3 个字面量池字
 *
 * 本文件是逐段对照指令写出的译文，每个代码块头部都标了原版地址区间。依赖
 * （Clear / BuildSWFData / CSkeletonSprite 构造 / operator new[] / ceilf / sqrtf /
 * 两个全局）全部保持 extern：没有实现、没有兜底、没有「失败也算成功」。
 *
 * ── r2 修订（回应 REVIEW-r2 的 Loader 项）──────────────────────────────
 *  1. 不再自定义 CSprite：直接包含 clear 线的权威头，
 *     字段名/类型随之统一；0x6c 在权威头里是 float，所以这里用 memcpy 裸搬
 *     32 位，**不能**写成浮点赋值（整数到 float 的数值转换不等于按位搬移，
 *     非规格化/NaN 等位型也必须原样保留）。
 *  2. 指针槽（0x54/0x58/0x68）是 4 B，全部经 yy_slot_set/yy_slot_get 显式换算。
 *  3. 32 位偏移寻址外提成 yy_offset32()：(uint32_t)count << 2。旧注释里
 *     「count < -15 会读到 YY 之前」这类按有符号大小下的断言已删——读点由
 *     **回绕后的 32 位偏移**决定，count=0xC0000001 时是 +4（读到 YY+0x40）。
 *  4. 分配失败/日志的表述按指令更正（见头文件 Alloc 合同）；不再声称
 *     "b 不是 bl ⇒ 没有异常路径"。
 *
 * 未主张：与原版二进制逐位等价。本目录只有静态校验 + 合成测试。
 */
#include "csprite_loadfromchunk.h"

/* 只用 memcpy（WAD 里是裸字节流、ARM 的 ldr 允许非对齐，不能用解引用取 32 位）。
 * freestanding 目标（-ffreestanding -nostdlib）没有 <string.h>，此时自己声明；
 * 宿主/真实工程走标准头。 */
#if defined(__STDC_HOSTED__) && __STDC_HOSTED__
#include <string.h>
#else
void *memcpy(void *d, const void *s, size_t n);
#endif

/* ── WAD 尾部是裸字节流：一律 memcpy 取 32 位（ARM 的 ldr 允许非对齐）──────── */
static inline int32_t rd_s32(const unsigned char *p)
{
    int32_t v;
    memcpy(&v, p, 4);
    return v;
}
static inline uint32_t rd_u32(const unsigned char *p)
{
    uint32_t v;
    memcpy(&v, p, 4);
    return v;
}
/* 对象里那些「4 B 槽但 C 类型不是 uint32_t」的格子（0x68 在权威头里记作 int32_t） */
static inline void st32(int32_t *slot, uint32_t v)
{
    memcpy(slot, &v, 4);
}

/* ── ARM `lsl #2`：32 位模 2^32 左移（0x1e9830 `lsl lr,r5,#2`、0x1e9a84
 *    `lsl r5,r8,#2`、0x1e9840/0x1e9844 的寻址都用它）──────────────────────
 * count=-2 → 0xFFFFFFF8（游标后退 8 B）；count=0xC0000001 → 4（游标前进 4 B）。
 * 读点/游标由这个 32 位结果决定，不能按 count 的有符号大小推断。
 */
uint32_t yy_offset32(int32_t count)
{
    return (uint32_t)count << 2;
}

/* ── 32 位地址加法（`add r6,r6,lr` / `add r1,r1,r2`）─────────────────────
 * 只做模运算，不检查可读性：偏移落在哪、那块内存是否映射，属于调用者状态。
 * 64 位宿主上按「正/负位移」显式拆开，避免实现定义的 int32→指针转换。
 */
const unsigned char *yy_add32(const unsigned char *base, uint32_t off32)
{
    uintptr_t b = (uintptr_t)base;
    if (off32 & 0x80000000u)
        return (const unsigned char *)(b - (uintptr_t)(0u - off32));
    return (const unsigned char *)(b + (uintptr_t)off32);
}

/* ── ARM `mul` 的低 32 位回绕（0x1e9878/80/8c/94 四条 mul）───────────────
 * C 的有符号溢出是 UB，所以显式走无符号再位转；ARM 的 mul 只留低 32 位。
 */
int32_t yy_mul32(int32_t a, int32_t b)
{
    return (int32_t)((uint32_t)a * (uint32_t)b);
}

/* ── ARM VCVT.S32.F32（0x1e9930/34/40/48）在**本函数可达域**上的语义 ──────
 * 可达域：两个平方都是 vcvt.f32.s32(某个 int32)，float32 相加后 |和| ≤ 2^32；
 * 和 < 0 ⇒ sqrtf 给 NaN；和 ≥ 0 ⇒ sqrt ≤ 65536。ceilf 后 v ∈ [0,65536] ∪ {NaN}。
 * ⇒ |v| ≥ 2^31 在本函数不可达；那一段只是本 helper 的显式合同，不是原版证据。
 * 可达域内（ARM ARM：VCVT 浮点→整数，NaN 结果为 0，其余向零截断）。
 */
int32_t yy_vcvt_s32_f32(float v)
{
    if (v != v)
        return 0;                            /* NaN：可达（负的平方和）*/
    if (v >= 2147483648.0f || v < -2147483648.0f)
        return INT32_MIN;                    /* 死分支：合同值 */
    return (int32_t)v;                       /* 向零截断 */
}

/* ── 0x1e9814..0x1e9824 / 0x1e9a80..0x1e9a90：new[](count*4) 的长度闸 ──────
 *   cmp  rX, #0x1FC00000
 *   mvnhi r0, #0            ; (无符号)count > 0x1FC00000 ⇒ 长度 = 0xFFFFFFFF
 *   lsl   r0, r0, #2 / movls r0, r5
 *   bl    _Znaj
 * 不是 libstdc++ 的 bad_array_new_length 检查：_Znaj 尾跳项目自己的
 * MemoryManager::Alloc，长度 0xFFFFFFFF 在 bucketAlloc 的 `cmp #0x4000 /
 * cmpne #0x100 / bhi` 处直接返回 0，兜底再被 `size+16 > 0xFFFFFFFE` 拒绝 ⇒ NULL。
 */
void *yy_new_array_checked(int32_t count)
{
    uint32_t bytes = ((uint32_t)count > 0x1FC00000u) ? 0xFFFFFFFFu : ((uint32_t)count << 2);
    return yy_operator_new_array(bytes);
}

/* ═════════════════════════════════════════════════════════════════════════
 *  CSprite::LoadFromChunk   int f(CSprite* this, YYSprite* yy, uchar* pWAD)
 *
 *  进入前必须成立（否则以下推理不适用）：
 *    · self 指向一个已构造的 CSprite（0x88 B）；
 *    · yy 指向 WAD 内一块至少 0x3c 字节的精灵头，尾部按 textureCount/g_isZeus/kind 布局；
 *    · g_pWADBaseAddress 是承载 yy 的整块 WAD 缓冲区基址。
 *  不变量：没有失败出口（两条出口都是 return 1）；失败表现为崩溃或把错值写进字段。
 * ═════════════════════════════════════════════════════════════════════════ */
int CSprite_LoadFromChunk(CSprite *self, const YYSprite *yy, const unsigned char *pWAD)
{
    const unsigned char *cur = NULL;      /* r6：WAD 尾部游标 */
    int32_t count = 0;                    /* r5/r0：子图数 */
    uint32_t loop_end;                    /* lr：count*4（32 位回绕）*/

    (void)pWAD;                           /* 0x1e972c..0x1e9b58 内没有一次读 r2 */

    /* ── 0x1e972c 序言 + 0x1e9740 bl CSprite::Clear() ─────────────────────
     * push {r4-r11,lr} + vpush {d8,d9,d10} + sub sp,#20：帧 80 B，无栈形参。
     * 第一件事是 Clear()：不做增量修补，先清场。
     */
    CSprite_Clear(self);

    /* ── 0x1e9744..0x1e97dc：头 14 个 dword 落位 ─────────────────────────
     * 三个 bool 用 `adds rX,rX,#0` + `movne rX,#1` 算 (x != 0)。
     * 四边是交叉的：YY(left,right,bottom,top) → this(0x08,0x10,0x14,0x0c)。
     * 存储顺序对语义无影响（无重叠、无别名读写），这里按字段自然序写。
     */
    self->flag_32     = (uint8_t)(yy->transparent != 0);   /* ldr +0x1c → strb +0x32 */
    self->flag_33     = (uint8_t)(yy->smooth != 0);        /* ldr +0x20 → strb +0x33 */
    self->flag_34     = (uint8_t)(yy->preload != 0);       /* ldr +0x24 → strb +0x34 */
    self->flag_30     = (uint8_t)(yy->sepMasks != 0);      /* ldr +0x2c → strb +0x30 */
    self->frame_count = yy->textureCount;                  /* ldr +0x38 → str    +0x18 */
    self->width       = yy->width;                         /* ldr +0x04 → str    +0x1c */
    self->height      = yy->height;                        /* ldr +0x08 → str    +0x20 */
    self->bbox[0]     = yy->bboxLeft;                      /* ldr +0x0c → str    +0x08 */
    self->bbox[2]     = yy->bboxRight;                     /* ldr +0x10 → str    +0x10 */
    self->bbox[3]     = yy->bboxBottom;                    /* ldr +0x14 → str    +0x14 */
    self->bbox[1]     = yy->bboxTop;                        /* ldr +0x18 → str    +0x0c */
    self->bbox_mode   = yy->bboxMode;                      /* ldr +0x28 → str    +0x04 */
    self->field_24    = yy->originX;                       /* ldr +0x30 → str    +0x24 */
    self->field_28    = yy->originY;                       /* ldr +0x34 → str    +0x28 */

    /* ── 0x1e9798 cmn r0,#1 / 0x1e97e0 beq 0x1e99b8：textureCount == -1 ⇒ 特殊后端 ── */
    if (yy->textureCount == -1)
        goto special;

    /* ── 0x1e97ec..0x1e9810 主路径（纹理工）──────────────────────────────
     *   str #0        → this+0x74        （type = 0：纹理）
     *   r6 = yy + 0x3c
     *   if (*g_isZeus != 0 && count == 0) { count = *cur++; this+0x18 = count; }
     * ★ 只有「Zeus 格式 且 头里 textureCount==0」才多读一个 dword（0x1e97fc 先判
     *   g_isZeus，0x1e9804 再判 count）。
     */
    self->type = 0;
    cur = (const unsigned char *)yy + 0x3c;
    count = yy->textureCount;
    if (g_isZeus != 0 && count == 0) {
        count = rd_s32(cur);                               /* ldr r0,[r6],#4 */
        cur += 4;
        self->frame_count = count;                         /* str r0,[r4,#0x18] */
    }

    /* ── 0x1e9814..0x1e9838 分配并落 this+0x54 ────────────────────────────
     * 0x1e9814 的 cmp 是**无符号**（mvnhi）：负数 count（除 -1 外）被当成巨大长度，
     * 极端尺寸在静态已追路径返回 NULL（见头文件 Alloc 合同）；不主张一般分配闭包无异常。
     * 0x1e9828 会把 count 从 this+0x18 重新 ldr 回来（r5）——译文照抄这次重读，
     * 因为分配器是本项目自己的（可能改写对象），不能假设它没副作用。
     */
alloc:
    yy_slot_set(&self->local_tpe, yy_new_array_checked(count));  /* bl _Znaj / str r0,[r4,#0x54] */
    count = self->frame_count;                              /* ldr r5,[r4,#0x18] */
    loop_end = yy_offset32(count);                          /* lsl lr,r5,#2 */

    /* ── 0x1e983c bgt 0x1e9984：只有 count > 0 才进回填循环 ────────────────
     * 循环体每轮 `ldr r0,[r4,#0x54]` 重载表基址（0x1e9980），第一轮从 0x1e9984
     * 进入、跳过这次重载，用的是 bl 的 r0——上面已把返回值存进 +0x54 再读回。
     * 槽位是 4 B：源偏移与目的偏移都是 i*4（`ldr r2,[r6,r3]` / `add r0,r0,r3`）。
     * count > 0 而分配返回 NULL 时，第一次 str 落在表基址（0）——原版同样崩。
     * 本条路径默认测试不执行（那是一次无效写），见 README §不可证路径。
     */
    if (count > 0) {
        uint32_t off = 0, base;
        for (;;) {                                          /* do-while：先体后判 */
            int32_t v = rd_s32(yy_add32(cur, off));          /* ldr r2,[r6,r3] */
            base = self->local_tpe;                          /* ldr r0,[r4,#0x54] */
            *(uint32_t *)(uintptr_t)(uint32_t)(base + off) = /* ARM32 str: always four bytes */
                v ? (uint32_t)(uintptr_t)g_pWADBaseAddress + (uint32_t)v : 0u;
            off += 4u;                                       /* add r3,r3,#4 */
            if (off == loop_end) break;                      /* cmp r3,lr / bne */
        }
    }

    /* ── 0x1e9840..0x1e9868 掩码块（主路径必经）───────────────────────────
     *   r3 = *(int32*)(cur + (count << 2))   ← 掩码块条数（在 count 个指针之后）
     *   cur = cur + (count << 2)             （0x1e9844）
     *   this+0x64 = r3                       总是写
     *   if (r3 > 0) {                         ← 0x1e9850 ble（有符号）
     *       cur += 4 ; this+0x68 = cur        ← 0x1e9858/0x1e9860
     *       this+0x35 = (r3 == count)         ← subs/rsbs/adcs
     *   } else {
     *       this+0x68 = 0                     ← 0x1e9a58
     *       ★ +0x35 **一个字节都不写**（保留 CSprite::CSprite() 给的 1；Clear 不写这格）
     *   }
     */
    {
        uint32_t mask_off = yy_offset32(count);              /* lr，同一个 32 位值 */
        const unsigned char *mask_at = yy_add32(cur, mask_off);
        int32_t mask_count = rd_s32(mask_at);                /* ldr r3,[r6,r5,lsl#2] */
        cur = mask_at;                                       /* add r6,r6,lr */
        self->field_64 = mask_count;                         /* str r3,[r4,#0x64] */
        if (mask_count > 0) {
            cur += 4;                                        /* add r6,r6,#4 */
            yy_slot_set((uint32_t *)&self->field_68, cur);   /* str r6,[r4,#0x68] */
            self->flag_35 = (uint8_t)(mask_count == count);  /* strb r5,[r4,#0x35] */
        } else {
            st32(&self->field_68, 0);                        /* 0x1e9a58 mov r3,#0 */
        }
    }

    /* ── 0x1e986c..0x1e996c 包围半径（四角到原点）─────────────────────────
     * 全部 32 位整数平方（mul，低 32 位回绕）→ vcvt.f32.s32 → float32 相加 →
     * vsqrt.f32 → ceilf → vcvt.s32.f32，取四者最大落 this+0x2c。
     *   角 1: sqrt(ox² + oy²)  0x1e98a8 vadd s14,s18,s19
     *   角 2: sqrt(dw² + oy²)  0x1e98d0 vadd s19,s17,s19
     *   角 3: sqrt(ox² + dh²)  0x1e98e8 vadd s18,s18,s16
     *   角 4: sqrt(dw² + dh²)  0x1e9908 vadd s16,s17,s16
     * ★ 不是 hypot、不是 double、不是整数开方：先把平方**截成 int32**，再转 float32。
     * ★ 每条 vsqrt 后紧跟 vcmp sN,sN + vmrs + bne 到 sqrtf@plt：clang 给 sqrtf 保留
     *   errno 的慢路径，**NaN 时进入**，而 NaN 可达（46341² 的低字是负的）。
     *   慢路径把 **vadd 的和** 传给 sqrtf，不是 vsqrt 的结果。
     * ★ 目标构建必须带 -fmath-errno：Android 目标默认 -fno-math-errno，此时 clang 只留
     *   `vsqrt`、把 4 条库调用整个删掉（V16 实测 4→0）。注意 freestanding 测试构建
     *   （-ffreestanding 关掉内置识别）两种开关下都是直接 `bl sqrtf`——那是编译器策略，
     *   返回值语义相同；本仓库的 ARM32 测试因此走的是替身 sqrtf。
     */
    {
        int32_t ox = self->field_24;
        int32_t oy = self->field_28;
        int32_t dw = (int32_t)((uint32_t)self->width - (uint32_t)ox);   /* rsb r3,r3,r1 */
        int32_t dh = (int32_t)((uint32_t)self->height - (uint32_t)oy);  /* rsb r2,r2,r0 */

        float ox2 = (float)yy_mul32(ox, ox);      /* vcvt.f32.s32 s18 */
        float oy2 = (float)yy_mul32(oy, oy);      /* vcvt.f32.s32 s19 */
        float dw2 = (float)yy_mul32(dw, dw);      /* vcvt.f32.s32 s17 */
        float dh2 = (float)yy_mul32(dh, dh);      /* vcvt.f32.s32 s16 */

        float c0 = ceilf(sqrtf(ox2 + oy2));       /* s14 → s15 → ceilf ⇒ s20 */
        float c1 = ceilf(sqrtf(dw2 + oy2));       /* s19 = s17+s19 ⇒ ceilf ⇒ s19 */
        float c2 = ceilf(sqrtf(ox2 + dh2));       /* s18 = s18+s16 ⇒ ceilf ⇒ s18 */
        float c3 = ceilf(sqrtf(dw2 + dh2));       /* s16 = s17+s16 ⇒ ceilf ⇒ s13 */

        int32_t i0 = yy_vcvt_s32_f32(c0);         /* 0x1e9930 vcvt.s32.f32 s20 */
        int32_t i1 = yy_vcvt_s32_f32(c1);         /* 0x1e9934 s19 */
        int32_t i2 = yy_vcvt_s32_f32(c2);         /* 0x1e9938 s18 */
        int32_t i3 = yy_vcvt_s32_f32(c3);         /* 0x1e9948 s13 */

        int32_t m = i2;                           /* vmov r3,s18 */
        if (m < i1) m = i1;                       /* cmp+movlt */
        if (m < i3) m = i3;                       /* cmp+movlt */
        self->field_2c = (i0 >= m) ? i0 : m;      /* cmp / strge / strlt */
    }

    /* ── 0x1e9970 mov r0,#1 → 收尾：恒返回 1 ───────────────────────────── */
    return 1;

special:
    /* ── 0x1e99b8..0x1e99f4：type = YY+0x40，尾部起点随 g_isZeus 变 ──────
     *   0x1e99c0 str r1,[r4,#0x74]       this+0x74 = type
     *   0x1e99d0 addne r6,r5,#0x4c       zeus：cur = YY+0x4c
     *   0x1e99dc/0x1e99e8                zeus：this+0x6c = YY+0x44，this+0x70 = YY+0x48
     *   0x1e99d4 addeq r6,r5,#0x44       非 zeus：cur = YY+0x44
     *   0x1e99f0 str r12,[r4,#0x18]      无条件把子图数清 0
     */
    {
        int32_t kind = rd_s32((const unsigned char *)yy + 0x40);
        self->type = kind;
        if (g_isZeus != 0) {
            cur = (const unsigned char *)yy + 0x4c;
            /* 0x6c 是 float 格子，但原版是 `ldr/str` 的裸 32 位搬移 ⇒ 用 memcpy，
             * 不能做浮点赋值（那会重新取整/规范 NaN）。 */
            {
                uint32_t v44 = rd_u32((const unsigned char *)yy + 0x44);
                uint32_t v48 = rd_u32((const unsigned char *)yy + 0x48);
                memcpy(&self->field_6c, &v44, 4);
                memcpy(&self->field_70, &v48, 4);
            }
        } else {
            cur = (const unsigned char *)yy + 0x44;
        }
        self->frame_count = 0;

        if (kind == 0) {
            /* ── 0x1e9b08..0x1e9b18 kind==0：没有后端数据 ─────────────────
             *   zeus：count = *cur++ → 走 0x1e9810 → 落到 0x1e9814，**长度闸照样生效**；
             *   非 zeus：count = 0（moveq r0,r1）→ beq 0x1e9820，跳过闸，new[](0)。
             */
            if (g_isZeus != 0) {
                count = rd_s32(cur);
                cur += 4;
                self->frame_count = count;
            } else {
                count = 0;
            }
            goto alloc;
        }

        if (kind == 1) {
            /* ── 0x1e9a64..0x1e9ad8 kind==1：SWF ─────────────────────────
             *   v = *cur; this+0x54 = 0;
             *   if (v <= 7)  data = cur + 4;                    （addle，有符号）
             *   else         n = cur[1]; cur += 8;
             *                this+0x54 = new[](n) 并回填 n 个 WAD 指针
             *                data = cur + (n << 2)（32 位）      （0x1e9ae0）
             * 然后 0x1e9ae8/af0: this+0x78 = 1；BuildSWFData(this, data,
             *   this+0x24, this+0x28)；返回 1。
             * ★ v<=7 那条路没有重载形参——用的是 0x1e97a0/a8 留下的
             *   this+0x24/this+0x28，也就是原点。两路实参相同。
             * ★ n 为负时长度闸给 0xFFFFFFFF ⇒ NULL，循环被 bgt 跳过；
             *   data 由 cur + (n<<2) 的 32 位回绕决定，不一定落在游标之前。
             */
            const unsigned char *data;
            int32_t v = rd_s32(cur);
            yy_slot_set(&self->local_tpe, NULL);            /* 0x1e9a68 */
            if (v <= 7) {
                data = cur + 4;
            } else {
                int32_t n = rd_s32(cur + 4);
                uint32_t off;
                cur += 8;
                yy_slot_set(&self->local_tpe, yy_new_array_checked(n)); /* 0x1e9a90 */
                if (n > 0) {
                    uint32_t end = yy_offset32(n);
                    off = 0;
                    for (;;) {                          /* 0x1e9aac..0x1e9ad8 */
                        int32_t voff = rd_s32(yy_add32(cur, off));
                        uint32_t base = self->local_tpe;   /* 0x1e9aa8 每轮重载 */
                        *(uint32_t *)(uintptr_t)(uint32_t)(base + off) =
                            voff ? (uint32_t)(uintptr_t)g_pWADBaseAddress + (uint32_t)voff : 0u;
                        off += 4u;                          /* add r3,r3,#4 */
                        if (off == end) break;              /* cmp r3,r5 / bne */
                    }
                }
                data = yy_add32(cur, yy_offset32(n));       /* add r1,r6,r5 */
            }
            self->field_78 = 1;                             /* 0x1e9af0 strb */
            (void)CSprite_BuildSWFData(self, (char *)data, self->field_24, self->field_28);
            return 1;                                       /* 0x1e9af8 mov r0,#1 */
        }

        if (kind == 2) {
            /* ── 0x1e9a08..0x1e9a54 kind==2：骨骼 ────────────────────────
             *   new(12) → CSkeletonSprite(name = cur+24, cur[1..5])
             *   this+0x54 = 0；this+0x58 = 对象；this+0x18 = 0x7FFFFFFF。
             * ★ 构造调用在 +0x58 落盘**之前**（0x1e9a44 bl / 0x1e9a4c str），
             *   如果构造抛异常，+0x58 仍是 Clear 给的值——本仓库不主张那条路径。
             */
            void *sk;
            yy_slot_set(&self->local_tpe, NULL);            /* 0x1e9a20 */
            sk = yy_operator_new(12);                       /* 0x1e9a24 bl _Znwj */
            CSkeletonSprite_ctor(sk, (char *)(cur + 24),
                                 rd_u32(cur + 4), rd_u32(cur + 8), rd_u32(cur + 12),
                                 rd_u32(cur + 16), rd_u32(cur + 20));
            yy_slot_set(&self->skeleton, sk);               /* 0x1e9a4c */
            self->frame_count = 0x7FFFFFFF;                 /* 0x1e9a48 mvn */
            return 1;
        }

        /* ── 0x1e9a00/0x1e9a04 kind ∉ {0,1,2}：什么都不建，直接返回 1 ────
         *   this+0x18 已清 0、this+0x74 = kind、+0x54/+0x58 保持 Clear() 的值。
         */
        return 1;
    }
}
