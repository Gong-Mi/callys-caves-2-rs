/* test_doubles.h — 测试替身/低地址 arena 的接口（见 test_doubles.c 顶部声明）*/
#ifndef TEST_DOUBLES_H
#define TEST_DOUBLES_H

#include <stdint.h>

#include "csprite_loadfromchunk.h"

typedef struct td_log_t {
    int      clear_calls;

    int      build_calls;
    CSprite *build_self;
    char    *build_data;
    int      build_w;
    int      build_h;

    int      skel_calls;
    void    *skel_self;
    char    *skel_name;
    unsigned skel_a, skel_b, skel_c, skel_d, skel_e;

    int      new_scalar_calls;
    uint32_t new_scalar_size;
    uint32_t new_scalar_ptr32;

    int      new_array_calls;
    uint32_t new_array_size;     /* 原版实参（count*4 或 0xFFFFFFFF），不记宿主放大后的尺寸 */
    uint32_t new_array_ptr32;
    int      new_array_null;     /* 1 = 这次分配返回了 NULL */

    int      alloc_hook_calls;
} td_log_t;

extern td_log_t td;
void td_reset(void);

/* ── 低地址 arena ─────────────────────────────────────────────────────────
 * CSprite 的指针槽是 4 B；64 位宿主上必须把**所有**对象放进低 4 GiB，否则
 * yy_slot_set 会截断。arena 在 host 上用 mmap 固定映射（0x20000000 起试），
 * 在 ARM32 上是静态数组；td_fixture_alloc 超出 4 GiB 直接 FATAL。
 */
void *td_fixture_alloc(uint32_t n);      /* 夹具用：不随 td_reset 回收 */
void  td_fixture_reset(void);            /* 只重置夹具游标（每个用例重来）*/

/* ── 分配器替身钩子 ───────────────────────────────────────────────────────
 * yy_operator_new_array 返回前调用（连同失败），用来验证译文在分配之后
 * **重读 this+0x18**：钩子可以改写对象字段，后续循环上界必须跟着变。
 */
extern void (*td_alloc_hook)(void);

/* ── freestanding 运行时（只给 ARM32 静态链接用）──────────────────────── */
#if defined(HARNESS_FREESTANDING)
float sqrtf(float x);
float ceilf(float x);
void *memcpy(void *d, const void *s, size_t n);
void *memset(void *d, int c, size_t n);
void *memmove(void *d, const void *s, size_t n);
int   memcmp(const void *a, const void *b, size_t n);
#endif

#endif /* TEST_DOUBLES_H */
