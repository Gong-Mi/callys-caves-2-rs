/* csprite_clear_cached_tpe_base.c — MUTANT M1a（必须被 fixture 杀掉）
 *
 * 由 src/csprite_clear.c 复制的**故意错误**版本：TPE 循环只缓存表基址（计数仍重读）。
 * 除下面标了 MUTANT 的块以外，与候选源文件（从 #include 起的代码部分）逐字相同。
 * 只用于证明 fixture 有区分力；不是候选实现。
 */
#include "csprite_clear.h"

/* freestanding 编译单元里没有 <string.h>：显式声明原件调用的那个 memset@plt 合同。 */
extern void *memset(void *dst, int c, size_t n);

/* 原件 0x1e6bc4..0x1e6bcc：
 *   ldr r3,[r3]        ; b->vptr（ARM32 地址点）
 *   ldr r3,[r3,#0x4]   ; vtable slot 1
 *   blx r3
 * ARM32 上 vptr 指向地址点：slot 0 = D1（完整对象析构），slot 1 = D0（删除析构）。
 * 实测 _ZTV9CBitmap32 = 0x3eba20（vtable 起点，含 offset-to-top/typeinfo）：
 *   [0x3eba20]=0x00000000  [0x3eba24]=0x003eba18(&_ZTI)
 *   [0x3eba28]=0x0016791c  [0x3eba2c]=0x00167944
 * 对象 vptr = 0x3eba28（地址点），故 [vptr]=0x16791c (D1)、[vptr+4]=0x167944 (D0)。
 */
typedef void (*CSprite_dtor_fn)(void *);

static void cbitmap32_deleting_dtor(uint32_t bmp_addr)
{
    uint32_t vt = *(const uint32_t *)(uintptr_t)bmp_addr;
    CSprite_dtor_fn d0 =
        (CSprite_dtor_fn)(uintptr_t)(*(const uint32_t *)(uintptr_t)(vt + 4));
    d0((void *)(uintptr_t)bmp_addr);
}

void CSprite_Clear(CSprite *self)
{
    /* 0x1e6b4c: ldr r3,[r0,#0x74]；0x1e6b54: cmp r3,#1；0x1e6b5c: beq
     * 只有 type 恰为 1 才清 SWF 数据；type==2（骨架）走 0x58 分支，不清 0x7c/0x84。
     * 原件在此处不判 this==NULL（NULL 即 UB），译文保持同一前置条件。 */
    if (self->type == 1) {
        CSprite_ClearSWFData(self);                 /* 0x1e6ca8 */
    }

    /* 0x1e6b60..0x1e6b80：骨架对象（type==2 的 CSkeletonSprite @0x58）。
     * 原件顺序固定：先 D2 基对象析构，再 operator delete，最后置空。 */
    if (self->skeleton != 0) {
        void *skel = (void *)(uintptr_t)self->skeleton;
        CSkeletonSprite_D2(skel);                   /* 0x1e6b70 */
        Sprite_operator_delete(skel);               /* 0x1e6b78 */
        self->skeleton = 0;                         /* 0x1e6b80 */
    }

    /* 0x1e6b84..0x1e6ba4 / 0x1e6c6c..0x1e6ca4：TPE 指针表（0x54）。
     * 0x54 指向 **4 字节指针数组**（InitLocalTPE 用 Alloc(4*0x44) 分配表，
     * 再对每条 Alloc(22) 分配一个 22 字节条目；参见 docs/03-object-layout.md §2/§3），
     * 所以这里按 4 字节步长取指针，不是按 22 字节步长遍历条目。
     *
     * 门是 owns_local_tpe(0x36)：为 0 时原件不释放数组、直接掉到 0x1e6b9c；
     * 0x54 仍会在 0x1e6c40 被置 0。
     *
     * 循环上界用 bitmap_count(0x44)，不是 local_tpe_count(0x38)。
     *
     * 关键次序（0x1e6c7c..0x1e6c94）：每轮
     *   ldr r0,[r0, r5, lsl #2]   取条目（基址来自上一次重读）
     *   add r5,r5,#1
     *   bl  MemoryManager::Free
     *   ldr r3,[r4,#0x44]         外调后重读计数
     *   ldr r0,[r4,#0x54]         外调后重读基址
     *   cmp r3,r5 / bgt           用重读后的计数决定是否继续
     * 即外调（可能经别名/重入改写本对象）能改变循环的基址与上界。
     * 译文按此重读；把表/上界提到循环外是**错误**的（变异体见 tools/mutants/）。
     * 0x1e6c98 的 Free 使用 r0 的最后一次载入值（0x1e6b84 或 0x1e6c8c），
     * 不再额外 ldr；译文用 tpe_base 承载同一个值。 */
    {
        uint32_t tpe_base = self->local_tpe;         /* 0x1e6b84 */
        if (tpe_base != 0 && self->owns_local_tpe != 0) {   /* 0x1e6b88..0x1e6b98 */
            /* MUTANT M1a：只缓存表基址；计数仍按原件每次重读。 */
            const uint32_t *tpe = (const uint32_t *)(uintptr_t)tpe_base;
            for (int32_t i = 0; i < self->bitmap_count; ++i) {
                uint32_t entry = tpe[i];                            /* 0x1e6c7c */
                MemoryManager_Free((const void *)(uintptr_t)entry); /* 0x1e6c84 */
            }
            tpe_base = self->local_tpe;
            MemoryManager_Free((const void *)(uintptr_t)tpe_base);  /* 0x1e6c98 */
            self->owns_local_tpe = 0;                               /* 0x1e6ca0 */
        }
    }
    /* 0x1e6ca4: b 0x1e6b9c —— 借用路径（0x54==0 或 0x36==0）直接落到位图循环。 */

    /* 0x1e6b9c..0x1e6be4：位图对象数组（0x48 / 0x44）。
     * 逐个走虚表 slot 1（D0 删除析构），成功后把槽位置 0；空槽跳过（连 0 都不写）。
     * 原件：进入时读一次 0x44（0x1e6b9c），此后**只在 D0 返回后**重读 0x44（0x1e6bd4）
     * 与 0x48（0x1e6bd0），零写用重读后的基址；跳过路径复用旧计数。
     * 译文保持同一数据流：n 只在 D0 之后刷新，基址每次取元素/零写时各重读一次。 */
    {
        int32_t n = self->bitmap_count;              /* 0x1e6b9c */
        if (n > 0) {                                 /* 0x1e6ba0..0x1e6bac */
            int32_t i = 0;
            for (;;) {
                uint32_t b =
                    ((const uint32_t *)(uintptr_t)self->bitmaps)[i]; /* 0x1e6bb0 */
                if (b != 0) {                                       /* 0x1e6bb8 */
                    cbitmap32_deleting_dtor(b);                     /* 0x1e6bcc */
                    n = self->bitmap_count;                         /* 0x1e6bd4 */
                    ((uint32_t *)(uintptr_t)self->bitmaps)[i] = 0;  /* 0x1e6bd8 */
                }
                ++i;                                                /* 0x1e6bdc */
                if (!(n > i)) {                                     /* 0x1e6be0/be4 */
                    break;
                }
            }
        }
    }

    /* 0x1e6be8：FreeTexture() —— 用 0x4c 作上界、0x50 作 id 数组，逐 id 调
     * GR_Texture_Free（id<0 跳过），把每个槽写成 -1；不重置 0x4c/0x50。 */
    CSprite_FreeTexture(self);

    /* 0x1e6bf4..0x1e6c08：先释放位图指针数组，外调返回后读取 +0x50，
     * 然后清 0x48/0x44/0x18，最后 Free 捕获的 +0x50；不得把读取移到外调之前。 */
    {
        MemoryManager_Free((const void *)(uintptr_t)self->bitmaps); /* 0x1e6bf8 */
        uint32_t tex_ids = self->texture_ids;        /* 0x1e6bfc: ldr r0,[r4,#0x50] */
        self->bitmaps = 0;                           /* 0x1e6c00 */
        self->bitmap_count = 0;                      /* 0x1e6c04 */
        self->frame_count = 0;                       /* 0x1e6c08 */
        MemoryManager_Free((const void *)(uintptr_t)tex_ids);       /* 0x1e6c0c */
        self->texture_ids = 0;                       /* 0x1e6c18 */
        self->texture_count = 0;                     /* 0x1e6c1c */
    }

    /* 0x1e6c20: add r0,r4,#8; mov r1,#0; mov r2,#16; bl memset@plt
     * 即 memset(this+0x08, 0, 16) —— 只清 tagYYRECT 包围盒，不动 0x04。 */
    memset(&self->bbox[0], 0, 16);

    /* 0x1e6c2c..0x1e6c54：默认值写回（顺序与原件一致）。 */
    self->flag_33 = 0;                              /* 0x1e6c2c */
    self->bbox_mode = 0;                            /* 0x1e6c34 */
    self->field_24 = 0;                             /* 0x1e6c38 */
    self->field_28 = 0;                             /* 0x1e6c3c */
    self->local_tpe = 0;                            /* 0x1e6c40（借用路径也在这里丢弃） */
    self->width = 1;                                /* 0x1e6c44 */
    self->height = 1;                               /* 0x1e6c48 */
    self->flag_32 = 1;                              /* 0x1e6c4c */
    self->flag_34 = 1;                              /* 0x1e6c50 */
    self->flag_30 = 1;                              /* 0x1e6c54 */

    /* 0x1e6c58：FreeMask() —— 0x31 为门；释放 0x40 行表与各行 +4 指针；
     * 收尾写 0x40=0, 0x3c=0, 0x31=0。 */
    CSprite_FreeMask(self);

    /* 0x1e6c5c..0x1e6c64：尾部三写，然后 0x1e6c68 pop {r4,r5,r6,pc} 返回。 */
    self->field_5c = 0;                             /* 0x1e6c5c */
    self->field_60 = 0;                             /* 0x1e6c60 */
    self->type = 0;                                 /* 0x1e6c64 */
}
