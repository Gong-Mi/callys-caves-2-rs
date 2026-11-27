/* csprite_loadfromchunk.h — CSprite::LoadFromChunk(YYSprite*, unsigned char*) 的 ABI/依赖合同
 *
 * 原版：libyoyo_armv7.so（sha256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a）
 *       _ZN7CSprite13LoadFromChunkEP8YYSpritePh   0x1e972c   size 1084
 *       268 条指令（0x1e972c..0x1e9b5c）+ 3 个字面量池字
 *
 * ── 布局与指针槽 ─────────────────────────────────────────────────────────
 * 直接包含已接入的 Clear 头，不再复制或自定义 CSprite；两编译单元共用同一布局。
 * 指针字段是 ARM32 的 uint32_t 槽；译文的表回填也必须每槽只写 4 字节。
 * 32 位目标上换算无损；64 位宿主合成测试要求所有被存入槽的对象位于低 4 GiB。
 * 任意宿主指针、跨地址空间回绕、并发和异常路径不在合成夹具的认证域。
 *
 * ── ABI ─────────────────────────────────────────────────────────────────
 *   ARMv7-A AAPCS，softfp（本函数没有浮点形参/返回值；float 只在 VFP 内部流转）
 *   r0 = this(CSprite*)，r1 = YYSprite*，r2 = unsigned char*（WAD 基址）
 *   r2 在本函数体内一次都没被读（首次触碰 0x1e9750 是写）⇒ 死参数。
 *   返回值：两条出口都是 mov r0,#1 ⇒ 恒返回 1。
 */
#ifndef CSPRITE_LOADFROMCHUNK_H
#define CSPRITE_LOADFROMCHUNK_H

#include <stddef.h>
#include <stdint.h>

/* 唯一权威布局定义（clear 线）；本文件不再定义 CSprite。 */
#include "../../csprite_clear/src/csprite_clear.h"

/* ── 依赖绑定：GNU/clang 的 asm label，符号名取自 .dynsym（scripts/sym.py 可复现）── */
#if defined(__GNUC__) || defined(__clang__)
#define YY_DEP(name) __asm__(name)
#else
#define YY_DEP(name)
#endif

/* ── 全局（.bss，.dynsym GLOBAL OBJECT）───────────────────────────────────
 * g_isZeus           0x5428e8  1 B   GOT 槽 0x3ed92c（R_ARM_RELATIVE）
 * g_pWADBaseAddress  0x544c44  4 B   GOT 槽 0x3ed94c（R_ARM_RELATIVE）
 */
extern uint8_t g_isZeus;
extern unsigned char *g_pWADBaseAddress;

/* ── WAD 内精灵块头（15 个 dword；尾部变长，用字节偏移访问）───────────────
 * 与 GameMaker 的 sprite chunk 同序。bool 在 WAD 里也是 4 B 一格，原版用
 * ldr + adds 判非 0，再 movne #1 归一化。
 */
typedef struct YYSprite {
    uint32_t   name;              /* +0x00  WAD 相对偏移槽（本函数未读）*/
    int32_t    width;             /* +0x04  → this+0x1c */
    int32_t    height;            /* +0x08  → this+0x20 */
    int32_t    bboxLeft;          /* +0x0c  → this+0x08（bbox[0]）*/
    int32_t    bboxRight;         /* +0x10  → this+0x10（bbox[2]）*/
    int32_t    bboxBottom;        /* +0x14  → this+0x14（bbox[3]）*/
    int32_t    bboxTop;           /* +0x18  → this+0x0c（bbox[1]）*/
    int32_t    transparent;       /* +0x1c  ≠0 → this+0x32 */
    int32_t    smooth;            /* +0x20  ≠0 → this+0x33 */
    int32_t    preload;           /* +0x24  ≠0 → this+0x34 */
    int32_t    bboxMode;          /* +0x28  → this+0x04 */
    int32_t    sepMasks;          /* +0x2c  ≠0 → this+0x30 */
    int32_t    originX;           /* +0x30  → this+0x24 */
    int32_t    originY;           /* +0x34  → this+0x28 */
    int32_t    textureCount;      /* +0x38  → this+0x18；== -1 走特殊分支（+0x40 = kind）*/
    /* +0x3c 起是变长尾部，布局随 textureCount / g_isZeus / kind 变 */
} YYSprite;

_Static_assert(sizeof(YYSprite) == 0x3c, "YYSprite 头必须是 15 个 dword");
_Static_assert(offsetof(YYSprite, textureCount) == 0x38, "YYSprite.textureCount");

/* ── 本译文依赖的 CSprite 格子：类型 + 偏移双重复述 ──────────────────────
 * 权威头已断言偏移；这里再断言一次「本文件用到的这些格子确实是我以为的类型」，
 * 尤其是 0x6c：clear 线记作 float，原版是 `ldr/str` 的裸 32 位搬移。类型在这里
 * 定死，译文就必须用 memcpy 搬位，而不能写成浮点赋值（那会改变数值）。
 */
#define YY_OFF(f) ((size_t)offsetof(CSprite, f))
_Static_assert(YY_OFF(bbox_mode) == 0x04, "0x04 bbox_mode");
_Static_assert(YY_OFF(bbox) == 0x08 && sizeof(((CSprite *)0)->bbox) == 16, "0x08 bbox[4]");
_Static_assert(YY_OFF(frame_count) == 0x18, "0x18 frame_count");
_Static_assert(YY_OFF(width) == 0x1c, "0x1c width");
_Static_assert(YY_OFF(height) == 0x20, "0x20 height");
_Static_assert(YY_OFF(field_24) == 0x24, "0x24 field_24");
_Static_assert(YY_OFF(field_28) == 0x28, "0x28 field_28");
_Static_assert(YY_OFF(field_2c) == 0x2c, "0x2c field_2c");
_Static_assert(YY_OFF(flag_30) == 0x30, "0x30 flag_30");
_Static_assert(YY_OFF(flag_32) == 0x32, "0x32 flag_32");
_Static_assert(YY_OFF(flag_33) == 0x33, "0x33 flag_33");
_Static_assert(YY_OFF(flag_34) == 0x34, "0x34 flag_34");
_Static_assert(YY_OFF(flag_35) == 0x35, "0x35 flag_35");
_Static_assert(YY_OFF(local_tpe) == 0x54, "0x54 local_tpe");
_Static_assert(YY_OFF(skeleton) == 0x58, "0x58 skeleton");
_Static_assert(YY_OFF(field_64) == 0x64, "0x64 field_64");
_Static_assert(YY_OFF(field_68) == 0x68, "0x68 field_68");
_Static_assert(YY_OFF(field_6c) == 0x6c, "0x6c field_6c");
_Static_assert(YY_OFF(field_70) == 0x70, "0x70 field_70");
_Static_assert(YY_OFF(type) == 0x74, "0x74 type");
_Static_assert(YY_OFF(field_78) == 0x78, "0x78 field_78");
_Static_assert(sizeof(CSprite) == 0x88, "sizeof CSprite == 136");
/* 指针槽是 4 B（ARM32）：这正是「不能把 void* 塞进去」的原因，也是 64 位宿主必须
 * 把对象放在低 4 GiB 的原因。 */
_Static_assert(sizeof(((CSprite *)0)->local_tpe) == 4, "0x54 是指针槽（4 B）");
_Static_assert(sizeof(((CSprite *)0)->bitmaps) == 4, "0x48 是指针槽（4 B）");
/* 0x6c 的类型：clear 线记作 float。译文必须按位搬，不能按数值转换。 */
_Static_assert(_Generic(((CSprite *)0)->field_6c, float: 1, default: 0),
               "0x6c 在权威头里是 float；译文按 32 位裸搬移");
#undef YY_OFF

/* ── 4 B 指针槽的显式换算 ───────────────────────────────────────────────
 * ARM32 上 uintptr_t 就是 32 位，换算无损；64 位宿主上会截断，所以 64 位构建
 * 只允许跑「所有对象都在低 4 GiB」的测试（driver 的 arena 会检查并 FATAL）。
 */
static inline void yy_slot_set(uint32_t *slot, const void *p)
{
    *slot = (uint32_t)(uintptr_t)p;
}
static inline void *yy_slot_get(uint32_t slot)
{
    return (void *)(uintptr_t)slot;
}

/* ── 依赖（全部 extern：本仓库不实现，也不假装实现）────────────────────── */

/* _ZN7CSprite5ClearEv  0x1e6b4c  size 356
 * 合同（本函数依赖的部分，见 clear 线候选与卡）：入口先释放/清场，写 +0x18=0、
 * +0x1c=1、+0x20=1、+0x30/+0x32/+0x34=1、+0x04=0、+0x08..+0x17=0、+0x24/+0x28=0、
 * +0x5c/+0x60=0、+0x74=0；**不写 +0x35**。
 * 声明来自 csprite_clear.h（与 clear 线同一份原型与 mangled 名）。 */
/* void CSprite_Clear(CSprite *self) 已由 csprite_clear.h 声明 */

/* _ZN7CSprite12BuildSWFDataEPcii  0x1e838c  size 5024
 * data == 0 返回 0；本函数传入的 data 恒为 WAD 内指针（非 0）。 */
int   CSprite_BuildSWFData(CSprite *self, char *data, int w, int h)
          YY_DEP("_ZN7CSprite12BuildSWFDataEPcii");

/* _ZN15CSkeletonSpriteC2EPcjjjjj  0xbd86c  size 164（C1/C2 同址）
 * 7 个 AAPCS 实参槽（含 this）：this/name/a/b 占 r0..r3，c/d/e 走栈。 */
void *CSkeletonSprite_ctor(void *self, char *name,
                           unsigned a, unsigned b, unsigned c,
                           unsigned d, unsigned e)
          YY_DEP("_ZN15CSkeletonSpriteC2EPcjjjjj");

/* ── 分配器：_Znwj/_Znaj 不是 libstdc++，是项目自带的 MemoryManager ─────────
 * _Znwj 0x27c524 → b 0x27ce78 (Alloc(size, "…", 0x525, true))
 * _Znaj 0x27d14c → b 0x27ce78 (Alloc(size, "…", 0x52b, true))
 *
 * ★ r2 更正（REVIEW-r2）：旧文档写「失败才调 logLocation」。逐条读指令是：
 *
 *   27ce7c  subs r6,r0,#0      ; size
 *   27ce84  beq  0x27cec4      ; size == 0            → 返回 NULL（不记账）
 *   27ce88  bl   _Alloc
 *   27ce8c  adds r1,r0,#0      ; Z = (ptr == 0)
 *   27ce94  movne r1,#1        ; r1 = (ptr != 0)
 *   27ce98  tst  r1,r5         ; r5 = zero 标志
 *   27ce9c  bne  0x27cecc      ; ptr != 0 && zero     → memset 后返回 ptr（**不记账**）
 *   27cea0  cmp  r1,#0
 *   27cea4  beq  0x27cec4      ; ptr == 0             → 返回 NULL（**不记账**）
 *   27cea8..27ceb4             ; 只有 ptr != 0 && zero == 0 才走到这里
 *   27ceb8  bl   logLocation
 *   27cebc  mov  r0,r4 / pop   ; 返回 ptr
 *
 *   ⇒ logLocation 只在「**分配成功**且 zero==false」这一条路上被调用（大概是
 *     "给了你一块没清零的内存" 之类的诊断）。失败路径（size==0 或 _Alloc 返回 0）
 *     直接跳 0x27cec4 返回 NULL，**不调用 logLocation**。
 *   ⇒ `_Znaj`/`_Znwj` 都传 zero=true（0x27d154/0x27c52c 的 `mov r3,#1`），
 *     所以对这两个入口来说 0x27ceb8 这条分支**根本不可达**。
 *
 * MemoryManager::_Alloc 0x27cd54
 *   27cd88 bl bucketAlloc：`cmp r5,#0x4000 / cmpne r5,#0x100 / bhi 0x27c6e8`
 *          ⇒ size > 16384 且 != 256 ⇒ 0x27c6e8 `mov r0,#0`（**不经过任何间接调用**）
 *   27cda8 adds/adc：size+16 用 64 位和；27cdbc..27cdc4 与 0xFFFFFFFE 比较
 *          ⇒ 不满足 ⇒ r4=0 ⇒ 返回 NULL（size ≥ 0xFFFFFFEF）
 *   27cdd4：malloc 失败也返回 NULL
 *
 * 由此可证（静态指令事实，不涉及异常）：
 *   · 长度 0xFFFFFFFF ⇒ bucketAlloc 直接 0（>16384 且 !=256）⇒ 兜底 0x10000000F >
 *     0xFFFFFFFE 被拒 ⇒ **NULL**。这条路上 **没有** 0x27c9a8 的 `blx ip`。
 *   · 长度 0 ⇒ Alloc 入口 beq ⇒ **NULL**（"分配"根本没发生）。
 *   · 返回非 NULL ⇒ 27ced0 memset 清零（zero==true）。
 *
 * ★ 关于「会不会抛异常」（REVIEW-r2 点 2）：
 *   `_Znaj` 用 `b` 而不是 `bl`，只能说明**它自己**不建栈帧、不捕获；**不能**据此
 *   断定被调方不抛——`b` 之后照样是别人的代码。本仓库改用可检查的合取条件
 *   （scripts/alloc_closure.py，输出 notes/alloc-closure.txt）：
 *     V1 全 .so 的 .dynsym 里没有 __cxa_throw/__cxa_rethrow（既无定义也无导入）
 *        ⇒ 只证未发现这两个动态符号，不排除间接、静态或其他异常来源；
 *     V2 闭包内无间接调用 —— **不成立**：bucketAlloc 0x27c9a8 `blx ip`、
 *        bucketFree 0x27c22c `blx r3` 是经全局对象 vtable 槽 +0xC 的虚调用，
 *        静态无法定目标；
 *     V3 闭包内无 abort/longjmp/exit/throw 调用点 —— 成立。
 *   ⇒ 结论只能写成：**静态可见路径上没有抛出点，但闭包里有 2 处目标不可定的间接
 *     调用，因此本仓库不主张「不会以异常中断」**。对本函数而言，这个不确定性不影响
 *     NULL 结论：我们只送 0 与 0xFFFFFFFF 两种极端尺寸，它们在到达 0x27c9a8 之前
 *     就已经返回 NULL（见上）。
 */
void  *yy_operator_new(uint32_t size)       YY_DEP("_Znwj");
void  *yy_operator_new_array(uint32_t size) YY_DEP("_Znaj");

/* libm：地址与名字取自 .dynsym / .plt */
float  sqrtf(float);            /* 0xb6700 —— 只在 vsqrt 结果为 NaN 时被调（errno 慢路径）*/
float  ceilf(float);            /* 0xb6994 —— 四条角各一次，无条件 */

/* ── 译文入口 ───────────────────────────────────────────────────────────── */
int CSprite_LoadFromChunk(CSprite *self, const YYSprite *yy, const unsigned char *pWAD)
    YY_DEP("_ZN7CSprite13LoadFromChunkEP8YYSpritePh");

/* ── 供测试/自检使用的纯函数（原函数体内联片段的一对一外提）────────────── */

/* ARM `mul`：低 32 位回绕。0x1e9878/80/8c/94 四条。 */
int32_t yy_mul32(int32_t a, int32_t b);

/* ARM `lsl #2` 的 32 位偏移：0x1e9840 `ldr r3,[r6,r5,lsl #2]` 与 0x1e9adc/e0
 * 的 `add r1,r6,r5`。返回 (uint32_t)count << 2（模 2^32），**不是** count*4 的
 * 64 位有符号值。count=-2 → 0xFFFFFFF8；count=0xC0000001 → 4。 */
uint32_t yy_offset32(int32_t count);

/* 32 位地址加法：base + off32（模 2^32）。宿主上用 uintptr_t 做模运算；
 * 越界是否可读属于调用者状态，本 helper 不检查、也不宣称可读。 */
const unsigned char *yy_add32(const unsigned char *base, uint32_t off32);

/* ARM `VCVT.S32.F32`（0x1e9930/34/40/48）在本函数**可达域**上的语义：
 *   NaN → 0；[-2^31,2^31) → 向零截断；|v| ≥ 2^31 → 不可达（显式合同，非实测）。 */
int32_t yy_vcvt_s32_f32(float v);

/* 0x1e9814..0x1e9824 / 0x1e9a80..0x1e9a90 的长度闸 + _Znaj：
 *   bytes = ((uint32_t)count > 0x1FC00000u) ? 0xFFFFFFFFu : (uint32_t)count * 4u
 * 返回值可能是 NULL（Alloc 合同），调用方不得假设成功。 */
void  *yy_new_array_checked(int32_t count);

#endif /* CSPRITE_LOADFROMCHUNK_H */
