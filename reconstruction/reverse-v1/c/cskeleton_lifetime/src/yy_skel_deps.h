/* yy_skel_deps.h — CSkeletonSprite C2/D2 译文的外部依赖与对象模型
 *
 * 原件：/data/data/com.termux/files/home/callys-caves-2-rs/reconstruction/live-mem/libyoyo_armv7.so
 *       sha256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 *       （本次复算一致）
 * 目标：_ZN15CSkeletonSpriteC2EPcjjjjj  0xbd86c  size 164（C1 同址，.dynsym 两条）
 *       _ZN15CSkeletonSpriteD2Ev        0xbd910  size  92（D1 同址）
 *       地址与 size 均由 .dynsym 复核，与上下文给的一致。
 *
 * 本头**不定义 CSprite**：CSprite 的布局与 Clear/Loader 原型一律取自主树头文件
 * （通过 YY_LOADER_H / YY_CLEAR_H 指向）。这里只放「骨骼对象自己的 12 字节」和
 * 「本译文用到、原件里已有的外部符号」。
 *
 * ── 骨骼对象是 12 字节，三个 32 位槽（静态依据）──────────────────────────
 * Loader 0x1e9a0c `mov r0,#12` → 0x1e9a24 `bl _Znwj` → 0x1e9a44 `bl 0xbd86c`
 * 0x1e9a4c `str r5,[r4,#0x58]`（CSprite.skeleton 槽）
 * ⇒ sizeof(CSkeletonSprite) == 12，且只被 ctor 写 +0/+4/+8 三个槽
 *   （bd898/bd89c/bd8a4 置 0；bd8e8 +0x08、bd8f4 +0x00、bd8fc +0x04 赋值）。
 * 三个槽的类型由「交给谁」定，不靠名字：
 *   +0x00 → spSkeletonJson_create 的返回值；D2 bd928 交给 spSkeletonJson_dispose
 *   +0x04 → spSkeletonJson_readSkeletonData 的返回值；D2 bd918 交给 spSkeletonData_dispose
 *   +0x08 → spAtlas_create 的返回值；D2 bd940 交给 spAtlas_dispose
 *   HasData @0xbd96c 依次 ldr [r0]/[r0,#4]/[r0,#8]、遇到 0 就返回 0
 *   （bd974/bd980 `beq 0xbd994`、bd98c `movne r0,#1`）⇒ 三者全非 0 才是 1。
 */
#ifndef YY_SKEL_DEPS_H
#define YY_SKEL_DEPS_H

#include <stddef.h>
#include <stdint.h>

/* 主树共享头（只读，不复制、不改）。构建时用 -DYY_LOADER_H=... -DYY_CLEAR_H=... 覆盖。 */
#ifndef YY_LOADER_H
#define YY_LOADER_H "../../csprite_loadfromchunk/src/csprite_loadfromchunk.h"
#endif
#ifndef YY_CLEAR_H
#define YY_CLEAR_H "../../csprite_clear/src/csprite_clear.h"
#endif

#if defined(__GNUC__) || defined(__clang__)
#define YY_SYM(name) __asm__(name)
#else
#define YY_SYM(name)
#endif

/* 主树头：CSprite 布局、CSprite_Clear/BuildSWFData 等原型、以及本译文要实现的
 * 两个入口的 C 别名 + mangled 名，全部由它们给出（本仓不复制、不改）。 */
#include YY_LOADER_H
#include YY_CLEAR_H

/* ── spine 侧不透明类型（本 TU 不展开，不递归恢复）─────────────────────── */
typedef struct spAtlas         spAtlas;
typedef struct spSkeletonJson  spSkeletonJson;
typedef struct spSkeletonData  spSkeletonData;

/* ── 骨骼对象：12 字节、三个 32 位槽 ─────────────────────────────────── */
typedef struct yy_skel12 {
    uint32_t slot_00_json;   /* spSkeletonJson*  */
    uint32_t slot_04_data;   /* spSkeletonData*  */
    uint32_t slot_08_atlas;  /* spAtlas*         */
} yy_skel12;

_Static_assert(sizeof(yy_skel12) == 12, "Loader 0x1e9a0c `mov r0,#12`");
_Static_assert(offsetof(yy_skel12, slot_00_json)  == 0x00, "bd8f4 st +0x00");
_Static_assert(offsetof(yy_skel12, slot_04_data)  == 0x04, "bd8fc st +0x04");
_Static_assert(offsetof(yy_skel12, slot_08_atlas) == 0x08, "bd8e8 st +0x08");

/* ── 外部函数：原件 .dynsym 里的 C 名（非 mangled），只声明不实现 ──────── */
/* spAtlas_create 0x284174：入口只读 r0/r1/r2/r3（28417c add r5,r0,r1；
 * 284188 mov r0,r2→strlen；284180 mov r4,r3），没有读 [sp+0x90] 之类的第 5 个
 * 栈参数 ⇒ 4 个形参。本函数调用处 r3 = r5 = 0（bd8d8 `mov r3,r5`，r5 在
 * bd890 被置 0）⇒ renderer/createTexture = NULL。 */
spAtlas         *spAtlas_create(const char *data, int dataLen, const char *dir, void *renderer);
void             spAtlas_dispose(spAtlas *a);

spSkeletonJson  *spSkeletonJson_create(spAtlas *atlas);
void             spSkeletonJson_dispose(spSkeletonJson *j);
/* 2 个形参：bd8f0 `mov r1,r6`、r0 = 上一条 spSkeletonJson_create 的返回值 */
spSkeletonData  *spSkeletonJson_readSkeletonData(spSkeletonJson *j, const char *text);
void             spSkeletonData_dispose(spSkeletonData *d);

/* _ZN15CSkeletonSprite12SimpleDecodeEPhi 0xbd840 size 44
 * 这是**非静态成员函数**：mangled 的形参表是 (Ph, i)，隐式 this 走 r0。
 * 函数体里 r0 在 bd848 `add r0,r1,r2` 被覆盖、之前从未被读 ⇒ r0 是死参数；
 * r1 = 缓冲区、r2 = 长度。bd844 `bxle lr` 是 cmp r2,#0 后的 ≤0 提前返回
 * （`d12fff1e`，条件 LE，不是 EQ）。
 * SimpleDecode 译文在同模块独立编译单元中，不再靠依赖替身顶替。 */
void CSkeletonSprite_SimpleDecode(void *self, unsigned char *buf, int len)
        YY_SYM("_ZN15CSkeletonSprite12SimpleDecodeEPhi");

/* ── 外部数据 ──────────────────────────────────────────────────────────── */

/* g_bFreeingSpineSprite 0x479ca8，.dynsym GLOBAL OBJECT，size 1，.bss
 * D2 在 spAtlas_dispose 前后各写一次 strb（bd94c 写 1、bd960 写 0），
 * 两次都**无条件**（bd950 的 beq 目标是 bd958，正好落在写 0 之前）。
 * 值是「强制 1 → 强制 0」，不是保存/恢复旧值。 */
extern volatile uint8_t g_bFreeingSpineSprite;

/* 0x479c98 .. 0x479ca7，16 字节，.bss，.dynsym 里**没有**名字
 * （本 .so 无 .symtab，LOCAL static 已被 strip；同段邻居 0x479ca8 是
 *  g_bFreeingSpineSprite、0x479cac 是 _ZN15CSkeletonSprite15ms_drawInstanceE）。
 * 本构造函数写这 4 个字（bd8ac..bd8b8）：
 *   +0x00 = name + a + b   +0x04 = c   +0x08 = d   +0x0c = e
 * 本批未恢复其完整消费者；用途保留 unknown。 */
typedef struct yy_glob_479c98 {
    uint32_t end;   /* +0x00 */
    uint32_t w04;   /* +0x04 */
    uint32_t w08;   /* +0x08 */
    uint32_t w0c;   /* +0x0c */
} yy_glob_479c98;

_Static_assert(sizeof(yy_glob_479c98) == 16, "0x479c98..0x479ca7 十六字节");

extern yy_glob_479c98 g_yy_479c98;

/* Recovered spine lifetime interfaces. Layouts remain private to their owning
 * translation units; all address-bearing native slots are 32-bit. */
typedef struct spAtlasPage spAtlasPage;
typedef struct spAtlasRegion spAtlasRegion;
void *_calloc(uint32_t nmemb, uint32_t size, const char *tag, uint32_t line);
void _free(void *p);
typedef struct spAttachmentLoader spAttachmentLoader;
spAttachmentLoader *spAtlasAttachmentLoader_create(spAtlas *atlas);
void spAttachmentLoader_dispose(spAttachmentLoader *loader);
spSkeletonJson *spSkeletonJson_createWithLoader(void *loader);
void spAtlasPage_dispose(spAtlasPage *page);
void spAtlasRegion_dispose(spAtlasRegion *region);
void _spAtlasPage_disposeTexture(spAtlasPage *page);
void GR_Texture_Free(int id) YY_SYM("_Z15GR_Texture_Freei");

#endif /* YY_SKEL_DEPS_H */
