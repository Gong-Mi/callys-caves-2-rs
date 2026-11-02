/* atlas_dispose.h — 本工作线本地声明（新声明，待父级折进 yy_skel_deps.h）
 *
 * 原件：libyoyo_armv7.so sha256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 * 目标：spAtlas_dispose 0x284120 size 84（.dynsym GLOBAL FUNC，无 mangled 别名）
 *
 * 槽偏移全部由机器码钉住，不靠 spine 上游版本猜：
 *  spAtlas 12 字节（spAtlas_create 0x2841d0 `mov r1, #12` → calloc(1,12,..)）
 *    +0x00 pages      0x2846ec `streq r11, [r12]`（首个 page 落 atlas+0）
 *    +0x04 regions    0x284294 `streq r0, [r3, #4]`（首个 region 落 atlas+4）
 *    +0x08 renderer   0x284230 `str r4, [r0, #8]`；dispose 全程不读不释放
 *  spAtlasPage 44 字节（spAtlasPage_create 0x28406c `mov r1, #44` → calloc(1,44)）
 *    +0x00 atlas 0x284084 `str r7,[r0]`；+0x04 name 0x2840a4 `str r0,[r4,#4]`
 *    +0x28 next  0x2846e4 `strne r11,[r3,#0x28]`；0x28+4 == 44 ⇒ 确实是尾字
 *  spAtlasRegion 80 字节（spAtlasRegion_create 0x2840e0 `mov r1, #80`）
 *    +0x00 name / +0x40 splits / +0x44 pads（0x2844ec、0x2845a8 由 _malloc 写）
 *    +0x48 page 0x284298；+0x4c next 0x28428c；0x4c+4 == 80 ⇒ 尾字
 *
 * 指针一律 4 字节槽：任何 host 的 void*（8 字节）宽写都会越界改到相邻字段。
 */
#ifndef YY_ATLAS_DISPOSE_H
#define YY_ATLAS_DISPOSE_H

#include <stddef.h>
#include <stdint.h>

#define SPATLAS_PAGES     0x00u
#define SPATLAS_REGIONS   0x04u
#define SPATLAS_RENDERER  0x08u
#define SPATLAS_SIZE      12u

#define SPATPAGE_ATLAS    0x00u
#define SPATPAGE_NAME     0x04u
#define SPATPAGE_NEXT     0x28u
#define SPATPAGE_SIZE     44u

#define SPATREGION_NAME   0x00u
#define SPATREGION_SPLITS 0x40u
#define SPATREGION_PADS   0x44u
#define SPATREGION_PAGE   0x48u
#define SPATREGION_NEXT   0x4Cu
#define SPATREGION_SIZE   80u

/* spine 侧不透明类型（本 TU 不展开，不递归恢复 spine） */
typedef struct spAtlasPage   spAtlasPage;
typedef struct spAtlasRegion spAtlasRegion;

/* 本入口原型（与 yy_skel_deps.h 的声明同型；夹具不必拉主树 CSprite 头） */
typedef struct spAtlas spAtlas;
void spAtlas_dispose(spAtlas *atlas);                 /* 0x284120 84B */

/* 直接小 helper（0x2840b8 / 0x2840f4，32B / 44B）与外部边界 */
void spAtlasPage_dispose(spAtlasPage *page);          /* 0x2840b8 */
void spAtlasRegion_dispose(spAtlasRegion *region);    /* 0x2840f4 */
void _spAtlasPage_disposeTexture(spAtlasPage *page);  /* 0xbd814 40B，留边界 */
void _free(void *p);                                  /* 0x285c80 28B */

#endif /* YY_ATLAS_DISPOSE_H */
