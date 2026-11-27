/* atlas_dispose.c — spAtlas_dispose 0x284120 size 84 的静态译文
 *
 * 原件 libyoyo_armv7.so sha256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 * 本 TU 只恢复：spAtlas_dispose（本入口）+ 两个直接小 helper
 *   spAtlasPage_dispose  0x2840b8 32B
 *   spAtlasRegion_dispose 0x2840f4 44B
 * _free（0x285c80）仍为外部边界；纹理回调（0xbd814）由 atlas_texture.c 独立译文提供。
 *
 * 逐条对应（21 条指令，84 字节，无字面量池）：
 *   284120 push {r3,r4,r5,lr}
 *   284124 mov  r5, r0                 ; self 存 r5，后面 regions 从 r5 取
 *   284128 ldr  r0, [r0]               ; atlas->pages
 *   28412c cmp  r0, #0
 *   284130 beq  284148                 ; 空链表 → 直接进 regions
 *   284134 ldr  r4, [r0, #0x28]        ; ★ next 在外调【前】读
 *   284138 bl   2840b8                 ; spAtlasPage_dispose(node)
 *   28413c cmp  r4, #0
 *   284140 mov  r0, r4                 ; 无条件把 next 传入下一次
 *   284144 bne  284134
 *   284148 ldr  r0, [r5, #0x4]         ; ★ regions 从 self 取，不是从 page
 *   28414c cmp  r0, #0
 *   284150 beq  284168
 *   284154 ldr  r4, [r0, #0x4c]        ; ★ next 在外调【前】读
 *   284158 bl   2840f4                 ; spAtlasRegion_dispose(node)
 *   28415c cmp  r4, #0
 *   284160 mov  r0, r4
 *   284164 bne  284154
 *   284168 mov  r0, r5
 *   28416c pop  {r3,r4,r5,lr}
 *   284170 b    285c80                 ; 尾调用 _free(atlas)
 *
 * 语义要点（不可"优化"掉）：
 * 1) next 必须在 dispose 之前读出：dispose 会释放该节点（page 释放 name+自身，
 *    region 释放 name/splits/pads+自身）。写成 `for (p=h; p; p=p->next)` 把 next
 *    的读取挪到释放之后，属 use-after-free 顺序，错误但常常"看起来能跑"。
 * 2) 两条链各自的 NULL 头要跳过；终结符 NULL 不得交给 dispose（原件在 28412c/
 *    28414c 先 cmp/beq）。
 * 3) 顺序固定：先整条 page 链，再整条 region 链，最后 free(atlas)。atlas+8 的
 *    rendererObject 不释放（无任何调用/存储到该槽）。
 * 4) atlas 自身没有 NULL 检查（284124 mov r5,r0 后 284128 立即 ldr [r0]），
 *    spAtlas_dispose(NULL) 属未定义，夹具不测，也不替它加检查。
 */
#include "yy_skel_deps.h"      /* 主树只读：spAtlas 与 spAtlas_dispose 原型 */
#include "atlas_dispose.h"

#ifndef YY_MUTANT
#define YY_MUTANT 0
#endif

_Static_assert(SPATPAGE_NEXT + 4u == SPATPAGE_SIZE, "page next 是 44 字节块的尾字");
_Static_assert(SPATREGION_NEXT + 4u == SPATREGION_SIZE, "region next 是 80 字节块的尾字");
_Static_assert(SPATLAS_RENDERER + 4u == SPATLAS_SIZE, "atlas 12 字节：renderer 是尾字");

/* 32 位槽读写：宽度固定 4 字节，绝不用 host 的 void*（8 字节）。 */
typedef uint32_t yy_alias_u32 __attribute__((may_alias));
static inline uint32_t yy_ld32(const void *base, size_t off)
{
    return *(const volatile yy_alias_u32 *)((const uint8_t *)base + off);
}

/* 槽里的值是 ARM32 地址（原件里就是指针宽度 4）；host 上靠夹具把图放在 4GiB 以下。 */
static inline void *yy_at(uint32_t addr)
{
    return (void *)(uintptr_t)addr;
}

void spAtlas_dispose(spAtlas *self)
{
    uint32_t node;
#if YY_MUTANT == 2
    /* 负控 2：删掉 28412c/284130 的 NULL 预检，终结符也被送进 dispose。
     * （读 next 时对 NULL 取 0 只是夹具安全化，避免用崩溃代替断言。） */
    node = yy_ld32(self, SPATLAS_PAGES);
    do {
        uint32_t next = (node != 0u) ? yy_ld32(yy_at(node), SPATPAGE_NEXT) : 0u;
        spAtlasPage_dispose(yy_at(node));
        node = next;
    } while (node != 0u);
#elif YY_MUTANT == 1
    /* 负控 1：`for (p = head; p; p = p->next)` 形态——next 在 dispose 之后才读。 */
    for (node = yy_ld32(self, SPATLAS_PAGES); node != 0u;
         node = yy_ld32(yy_at(node), SPATPAGE_NEXT))
        spAtlasPage_dispose(yy_at(node));
#elif YY_MUTANT == 4
    /* no-op 变体：判定结构改成 if+do-while，语义必须与基线逐字节同输出 */
    node = yy_ld32(self, SPATLAS_PAGES);
    if (node != 0u) {
        do {
            uint32_t next = yy_ld32(yy_at(node), SPATPAGE_NEXT);
            spAtlasPage_dispose(yy_at(node));
            node = next;
        } while (node != 0u);
    }
#else
    node = yy_ld32(self, SPATLAS_PAGES);                    /* 284128 */
    while (node != 0u) {                                    /* 28412c / 284130 */
        uint32_t next = yy_ld32(yy_at(node), SPATPAGE_NEXT);/* 284134：外调前 */
        spAtlasPage_dispose(yy_at(node));                   /* 284138 */
        node = next;                                        /* 28413c..284144 */
    }
#endif

#if YY_MUTANT == 3
    /* 负控 3：先释放容器再排空链表（free 顺序违规，且 regions 头随之丢失） */
    _free(self);
    node = yy_ld32(self, SPATLAS_REGIONS);
#elif YY_MUTANT == 5
    /* Safe falsifier: retain region reachability while freeing atlas too early. */
    node = yy_ld32(self, SPATLAS_REGIONS);
    _free(self);
#else
    node = yy_ld32(self, SPATLAS_REGIONS);                  /* 284148：从 self */
#endif
    while (node != 0u) {                                    /* 28414c / 284150 */
        uint32_t next = yy_ld32(yy_at(node), SPATREGION_NEXT);/* 284154：外调前 */
        spAtlasRegion_dispose(yy_at(node));                 /* 284158 */
        node = next;                                        /* 28415c..284164 */
    }

#if YY_MUTANT != 3 && YY_MUTANT != 5
    _free(self);                                            /* 284168..284170 */
#endif
}

#ifndef YY_ATLAS_HELPERS_EXTERN
/* ── spAtlasPage_dispose 0x2840b8 size 32 ─────────────────────────────────
 *   2840b8 push {r4,lr}; 2840bc mov r4,r0
 *   2840c0 bl   _spAtlasPage_disposeTexture(page)   ; 边界，未恢复
 *   2840c4 ldr  r0,[r4,#0x4] ; 2840c8 bl _free      ; name
 *   2840cc mov  r0,r4 ; 2840d0 pop ; 2840d4 b _free ; page 自身
 */
void spAtlasPage_dispose(spAtlasPage *page)
{
    _spAtlasPage_disposeTexture(page);
    _free(yy_at(yy_ld32(page, SPATPAGE_NAME)));
    _free(page);
}

/* ── spAtlasRegion_dispose 0x2840f4 size 44 ───────────────────────────────
 *   2840f8 mov r4,r0
 *   2840fc ldr r0,[r0]        ; 284100 bl _free   ; +0x00 name
 *   284104 ldr r0,[r4,#0x40]  ; 284108 bl _free   ; +0x40 splits
 *   28410c ldr r0,[r4,#0x44]  ; 284110 bl _free   ; +0x44 pads
 *   284114 mov r0,r4 ; 284118 pop ; 28411c b _free ; region 自身
 */
void spAtlasRegion_dispose(spAtlasRegion *region)
{
    _free(yy_at(yy_ld32(region, SPATREGION_NAME)));
    _free(yy_at(yy_ld32(region, SPATREGION_SPLITS)));
    _free(yy_at(yy_ld32(region, SPATREGION_PADS)));
    _free(region);
}
#endif /* !YY_ATLAS_HELPERS_EXTERN */
