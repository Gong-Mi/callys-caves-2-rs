/* clear_swf.c — _ZN7CSprite12ClearSWFDataEv 的静态译文（ARM32，逐指令级编排）
 *
 * 原件：/data/data/com.termux/files/home/callys-caves-2-rs/reconstruction/live-mem/libyoyo_armv7.so
 *       sha256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 *       符号 @ 0x1e68b0，范围 0x1e68b0..0x1e6b4c（0x29c = 668 字节，与 167 个
 *       4 字节索引一致；本函数无 literal pool，尾部 0x1e6b40/0x1e6b48 是 tag==2
 *       的独立小块，不是数据）。
 * 布局：唯一权威头 reconstruction/reverse-v1/c/csprite_clear/src/csprite_clear.h，
 *       本文件只 #include，不复制结构体定义。
 *
 * 语义：按图中偏移与 tag 释放对象和 dictionary，条件清零 0x7c/0x80/0x84。
 *       无显式错误返回；不假定外调或无效内存不会中断。
 *
 * 观察到的对象图（全部来自本函数自身的 ldr 偏移，不是推测）：
 *   0x7c -> 指针数组[0x80]                     每个元素是“SWF 对象”
 *     obj+0x00  tag: 1 = 容器, 2 = 纹理项, 其它 = 裸对象
 *     obj+0x08  容器: 24 字节条目数组            obj+0x1c 条目数
 *     obj+0x08  纹理项: GL 纹理 id（int）        —— tag==2 分支
 *     ent+0x00  -> 84(0x54) 字节记录数组          ent+0x0c 记录数
 *     ent+0x04  -> 4 字节元素指针数组             ent+0x10 元素数
 *     ent+0x08  -> 单个待释放指针
 *     rec+0x00..0x18  7 个指针，逐个 if(!=0) Free
 *     elem+0x00  tag；elem+0x50 指针（if!=0 Free）；elem+0x54 GL 纹理 id
 *   0x84 -> dictionary
 *     dict+0x00 24 字节条目数组；dict+0x18 条目数；每条目只释放 +0x00 一个指针
 *
 * 关键不变量（本函数的“快路径”绝不能优化掉的部分）：每一次外部调用
 * （MemoryManager::Free / GR_Texture_Free）返回后，循环基址与上界都从内存
 * 重读；回调可以改写 self 或图节点，从而改变下一次迭代读取的地址与次数。
 * 译文用 volatile 读显式保留这些重读点（原件就是这样发出的 ldr）。
 *
 * 边界（未闭合，不声称等价）：
 *   - MemoryManager::Free 的 NULL 合同取自 0x27c2d0 入口 `popeq {r4,r5,r6,pc}`；
 *     译文仍保留原件的 if(!=0) 门，因此调用次数与原件一致。
 *   - 内层两个循环用无符号 bhi/bls，而外层与 dictionary 用有符号 ble/bgt。
 *     计数为负时内层会退化成巨量迭代（原件即如此），译文保持同构，但夹具
 *     只用非负计数——这条负计数路径未测试，属已知边界。
 *   - 未验证 SWF 对象图在真实游戏中的来源与生命周期；本译文只对“以这些偏移
 *     构成的图”负责。真实分配器、GL 后端、以及 type 之外的 CSprite 字段
 *     语义不在本函数范围内。
 */
#include "csprite_clear.h"

/* 原件 0x1e6a5c: bl 0x173f84 <_Z15GR_Texture_Freei>（int 参数；内部先查存在性，
 * 不存在即返回）。头文件未声明它，这里只补一个带原 mangled 名的 extern。 */
extern void GR_Texture_Free(int id) __asm__("_Z15GR_Texture_Freei");

/* ---- 原件偏移常量（全部有本函数内的 ldr/str 作锚点） ---- */
#define SWF_OBJ_ARRAY     0x08u   /* 0x1e6920: ldr r0,[r9,#0x8] */
#define SWF_OBJ_COUNT     0x1cu   /* 0x1e692c: ldr r3,[r9,#0x1c] */
#define ENT_STRIDE        24u     /* 0x1e6a88: add r8,r8,#24 */
#define ENT_REC_ARRAY     0x00u   /* 0x1e6940: ldr r4,[r0,r8] */
#define ENT_REC_COUNT     0x0cu   /* 0x1e6950: ldr r3,[r5,#0xc] */
#define ENT_ELEM_ARRAY    0x04u   /* 0x1e69f8: ldr r0,[r5,#0x4] */
#define ENT_ELEM_COUNT    0x10u   /* 0x1e6a04: ldr r3,[r5,#0x10] */
#define ENT_SINGLE        0x08u   /* 0x1e6a70: ldr r0,[r5,#0x8] */
#define REC_STRIDE        84u     /* 0x1e69e0: add r6,r6,#84 */
#define REC_NPTR          7       /* 0x1e6964..0x1e69c8: 偏移 0,4,8,0xc,0x10,0x14,0x18 */
#define ELEM_TAG          0x00u   /* 0x1e6a3c: ldr r3,[r6] */
#define ELEM_PTR50        0x50u   /* 0x1e6a48: ldr r0,[r6,#0x50] */
#define ELEM_TEX54        0x54u   /* 0x1e6a58: ldr r0,[r6,#0x54] */
#define DICT_ARRAY        0x00u   /* 0x1e6ac8: ldr r2,[r3] */
#define DICT_COUNT        0x18u   /* 0x1e6ad4: ldr r1,[r3,#0x18] */
#define DICT_STRIDE       24u     /* 0x1e6af0: add r4,r4,#24 */

/* self 的字段访问一律走 volatile：原件在每次外调后重新 ldr，volatile 让译文
 * 也真的发那条 ldr，而不是让编译器把值缓存在寄存器里。这不是新增语义，是把
 * 原件已经存在的重读点固定在 C 源上。 */
#define SP ((volatile CSprite *)self)

/* 图节点在 32 位地址空间内（原件 ARM32）；夹具把整张图放在 4 GiB 以下，
 * 因此 uint32_t 承载地址对 host 构建同样成立。 */
static inline uint32_t ld32(uint32_t addr)
{
    return *(volatile const uint32_t *)(uintptr_t)addr;
}

static inline void mm_free(uint32_t addr)
{
    MemoryManager_Free((const void *)(uintptr_t)addr);
}

/* 0x1e6920..0x1e6a9c：tag==1 容器的三层释放，然后由调用者 Free(obj)。
 * 返回时 r0 无意义；原件此处是 `b 0x1e68e8`。 */
static void swf_free_container(uint32_t obj)
{
    uint32_t arr = ld32(obj + SWF_OBJ_ARRAY);          /* 0x1e6920 */
    if (arr == 0)                                      /* 0x1e6924 beq */
        return;

    int32_t count = (int32_t)ld32(obj + SWF_OBJ_COUNT);/* 0x1e692c */
    if (count == 0) {                                  /* 0x1e693c beq: zero only */
        mm_free(arr);
        return;
    }

    for (uint32_t i = 0;;) {                           /* r10; unsigned inner loop */
        uint32_t at  = arr + (uint32_t)i * ENT_STRIDE; /* r5 = r0 + r8 */
        uint32_t ent = ld32(at);                       /* 0x1e6940 r4 = [r0,r8] */

        if (ent != 0) {                                /* 0x1e6948 beq */
            int32_t n1 = (int32_t)ld32(at + ENT_REC_COUNT);  /* 0x1e6950 */
            uint32_t rec = ent;                        /* r4 remains ent when n1==0 */
            if (n1 != 0) {                            /* 0x1e6958 beq skips loop, not Free */
                for (uint32_t j = 0;;) {                /* r7 */
                    uint32_t r = rec + (uint32_t)j * REC_STRIDE; /* 0x1e6968 add r4,r4,r6 */
                    for (int k = 0; k < REC_NPTR; ++k) {     /* 0x1e6964..0x1e69d4 */
                        uint32_t p = ld32(r + (uint32_t)k * 4u);
                        if (p != 0)
                            mm_free(p);
                    }
                    n1  = (int32_t)ld32(at + ENT_REC_COUNT); /* 0x1e69d8 外调后重读 */
                    ++j;                                     /* 0x1e69dc */
                    rec = ld32(at);                          /* 0x1e69e4 重读条目基址 */
                    if (!((uint32_t)n1 > (uint32_t)j))       /* 0x1e69e8 bhi（无符号）*/
                        break;
                }
            }
            /* 0x1e69f0/0x1e69f4: zero count also frees the nonnull record base. */
            mm_free(rec);
        }
        /* 0x1e69f8: 元素指针数组（4 字节步长） */
        uint32_t sub2 = ld32(at + ENT_ELEM_ARRAY);
        if (sub2 != 0) {                                /* 0x1e69fc beq */
            int32_t n2 = (int32_t)ld32(at + ENT_ELEM_COUNT); /* 0x1e6a04 */
            if (n2 != 0) {                              /* 0x1e6a08 beq（只判零）*/
                for (uint32_t j = 0;;) {                 /* r4 */
                    uint32_t slot = (uint32_t)j * 4u;   /* 0x1e6a34 r7 = r4<<2 */
                    uint32_t elem = ld32(sub2 + slot);  /* 0x1e6a30 */
                    ++j;                                /* 0x1e6a38 */
                    if (ld32(elem + ELEM_TAG) == 2) {   /* 0x1e6a3c/0x1e6a40 */
                        uint32_t q = ld32(elem + ELEM_PTR50);   /* 0x1e6a48 */
                        if (q != 0)                             /* 0x1e6a4c beq */
                            mm_free(q);                         /* 0x1e6a54 */
                        GR_Texture_Free((int)ld32(elem + ELEM_TEX54)); /* 0x1e6a5c */
                        sub2 = ld32(at + ENT_ELEM_ARRAY);  /* 0x1e6a60 重读数组基址 */
                        elem = ld32(sub2 + slot);          /* 0x1e6a64 重读同一槽 */
                    }
                    /* 0x1e6a18 */
                    mm_free(elem);
                    n2   = (int32_t)ld32(at + ENT_ELEM_COUNT); /* 0x1e6a20 重读 */
                    sub2 = ld32(at + ENT_ELEM_ARRAY);          /* 0x1e6a24 重读 */
                    if (!((uint32_t)n2 > (uint32_t)j))         /* 0x1e6a28 bls */
                        break;
                }
            }
            mm_free(sub2);                              /* 0x1e6a6c */
        }
        uint32_t one = ld32(at + ENT_SINGLE);           /* 0x1e6a70 */
        if (one != 0)                                   /* 0x1e6a74 beq */
            mm_free(one);                               /* 0x1e6a7c */

        count = (int32_t)ld32(obj + SWF_OBJ_COUNT);     /* 0x1e6a80 外调后重读 */
        ++i;                                            /* 0x1e6a84 */
#if CLEAR_SWF_MUTANT == 2
        /* M2（语义变异，安全）：把容器条目数组基址提到循环外。
         * 回调改写 obj+0x08 后仍用旧基址/旧上界。 */
#else
        arr = ld32(obj + SWF_OBJ_ARRAY);                /* 0x1e6a8c 重读基址 */
#endif
        if (!((uint32_t)count > (uint32_t)i))           /* 0x1e6a90 bhi */
            break;
    }
    mm_free(arr);                                       /* 0x1e6a98 */
}

void CSprite_ClearSWFData(CSprite *self)
{
    uint32_t base  = SP->swf_objects;          /* 0x1e68bc ldr r0,[r0,#0x7c] */
    int32_t  count = 0;

    if (base != 0) {                           /* 0x1e68c0/0x1e68c4 beq 0x1e6ab4 */
        count = (int32_t)SP->swf_object_count; /* 0x1e68cc */
        if (count > 0) {                       /* 0x1e68d0 ble 0x1e6aa0 */
            for (int32_t i = 0;;) {            /* r11 */
                uint32_t obj = ld32(base + (uint32_t)i * 4u); /* 0x1e6908 */

                if (obj != 0) {                /* 0x1e690c beq -> 0x1e68fc（不重读）*/
                    uint32_t tag = ld32(obj);  /* 0x1e6914 */
                    if (tag == 1) {
                        swf_free_container(obj);        /* 0x1e6920..0x1e6a9c */
                    } else if (tag == 2) {
                        /* 0x1e68e0/0x1e68e4 -> 0x1e6b40: 纹理 id 在 obj+0x08，
                         * 无 NULL 门，GR_Texture_Free 自己容错。 */
                        GR_Texture_Free((int)ld32(obj + 0x08));
                    }
                    /* 0x1e68e8: mov r0,r9 ; bl Free —— 三条分支的汇合点 */
                    mm_free(obj);
                    /* 0x1e68f0/0x1e68f4/0x1e68f8: 外调后重读基址与计数 */
                    base  = SP->swf_objects;
                    count = (int32_t)SP->swf_object_count;
                }
                ++i;                            /* 0x1e68fc */
                if (!(count > i))               /* 0x1e6900 ble 0x1e6aa0 */
                    break;
            }
        }
        /* 0x1e6aa0: r0 为最后一次载入的数组基址 */
        mm_free(base);
#if CLEAR_SWF_MUTANT == 3
        /* M3（no-op 变异）：两个互不依赖的零写交换顺序，可观察行为不变。
         * 任何断言都不应因此失败——用来证明测试不是照抄实现顺序。 */
        SP->swf_object_count = 0;              /* 0x1e6ab0 */
        SP->swf_objects      = 0;              /* 0x1e6aac */
#else
        SP->swf_objects      = 0;              /* 0x1e6aac */
        SP->swf_object_count = 0;              /* 0x1e6ab0 */
#endif
    }

    /* 0x1e6ab4: dictionary（0x84）。base==0 时从这里直接进入。 */
    {
        uint32_t dict = SP->swf_dictionary;        /* 0x1e6ab8 */
        if (dict != 0) {                           /* 0x1e6abc/0x1e6ac4 beq 返回 */
            uint32_t darr = ld32(dict + DICT_ARRAY);   /* 0x1e6ac8 */
            if (darr == 0) {                       /* 0x1e6ad0 beq 0x1e6b28 */
                mm_free(dict);                     /* 0x1e6b28（r0 仍是 dict）*/
            } else {
                int32_t dn = (int32_t)ld32(dict + DICT_COUNT); /* 0x1e6ad4 */
                if (dn > 0) {                      /* 0x1e6ad8 ble 0x1e6b18 */
                    for (uint32_t j = 0;;) {
                        uint32_t p = ld32(darr + (uint32_t)j * DICT_STRIDE); /* 0x1e6ae8 */
                        ++j;                                            /* 0x1e6aec r5 */
                        if (p != 0) {                  /* 0x1e6af4 beq */
                            mm_free(p);                /* 0x1e6afc */
                            dict = SP->swf_dictionary; /* 0x1e6b00/0x1e6b04 重读 */
                        }
#if CLEAR_SWF_MUTANT == 1
                        /* M1（语义变异，安全）：把 dict 的数组/计数提到循环外。 */
                        if (!(dn > (int32_t)j)) break;          /* 0x1e6b0c bgt（用旧值）*/
#else
                        dn   = (int32_t)ld32(dict + DICT_COUNT); /* 0x1e6b08 重读 */
                        darr = ld32(dict + DICT_ARRAY);          /* 0x1e6b10 重读 */
                        if (!(dn > (int32_t)j))                           /* 0x1e6b14 bgt */
                            break;
#endif
                    }
                }
                mm_free(darr);                     /* 0x1e6b18 */
                dict = SP->swf_dictionary;         /* 0x1e6b20/0x1e6b24 重读 */
                mm_free(dict);                     /* 0x1e6b28 */
            }
            SP->swf_dictionary = 0;                /* 0x1e6b2c/0x1e6b34 */
        }
    }
    /* 0x1e6b38: add sp,sp,#12 ; pop {...,pc} */
}
