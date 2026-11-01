/* free_resources.c — CSprite::FreeMask / CSprite::FreeTexture 的静态译文
 *
 * 原件：/data/data/com.termux/files/home/callys-caves-2-rs/reconstruction/live-mem/libyoyo_armv7.so
 *       sha256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 *   _ZN7CSprite8FreeMaskEv    @ 0x1e3b58 .. 0x1e3bcc（0x74 = 116 字节）
 *   _ZN7CSprite11FreeTextureEv@ 0x1e56fc .. 0x1e5748（0x4c = 76 字节）
 *
 * 只做这两个直接依赖。布局与外部符号全部来自共享头 csprite_clear.h；
 * 本文件不另定义 CSprite，也不实现任何外部依赖。
 *
 * 忠实度边界（读成“等价”之前先读这里）：
 *   - 每行尾的地址是原件指令地址；语句按原件数据流书写。
 *   - 外调（MemoryManager::Free / GR_Texture_Free）之后的字段读取必须保持
 *     “重读”，不得提升到调用之前：
 *       FreeMask    : 每轮 Free 之后重读 self+0x40 与 self+0x3c（0x1e3b94/98）
 *       FreeTexture : 每轮 GR_Texture_Free 之后重读 self+0x50 与 self+0x4c
 *                     （0x1e572c/34）
 *     这决定回调改写表指针/计数时的行为。
 *   - 写序也是语义：FreeMask 先把每行两个 4 字节字清零，再在循环外释放行表，
 *     最后才清 0x40/0x3c/0x31；FreeTexture 先 GR_Texture_Free 再写 0x50[i]=-1。
 *   - this==NULL 原件不判（会解引用），译文保持同一前置条件：
 *       非空 this；has_mask/texture_count 非零时，对应数组指针必须可读。
 *   - 只做语义翻译；不声明与原件指令级写序/寄存器分配一致。
 */
#include "csprite_clear.h"

/* 依赖不在共享头里（Clear 不调用它），按原 mangled 名做链接级绑定。
 * 原件 0x173f84；这里只恢复调用编排，不假定真实纹理分配器的容错或幂等。 */
extern void GR_Texture_Free(int id) __asm__("_Z15GR_Texture_Freei");

void CSprite_FreeMask(CSprite *self)
{
    /* 0x1e3b60..0x1e3b68: ldrb r3,[r0,#0x31]; cmp r3,#0; popeq
     * 门关闭时一个字节都不写，连计数/表指针都不动。 */
    if (self->has_mask == 0) {
        return;
    }

    /* 0x1e3b6c: ldr r3,[r0,#0x3c]；0x1e3b70: ldr r0,[r0,#0x40]
     * 即使 count<=0 也先取出行表，循环外无条件 Free(rows)。 */
    uint32_t rows = self->mask_rows;
    int32_t count = self->mask_count;

    /* 0x1e3b74..0x1e3b80: cmp r3,#0; movgt r4,#0; movgt r7,#0; ble +0x5c
     * 只有 count>0 进入行循环；负计数不进循环，但仍会走到循环外的 Free(rows)。 */
    if (count > 0) {
        for (int32_t i = 0; i < count; i++) {
            /* 0x1e3b84..0x1e3b8c: r5=i<<3; r3=rows+r5; ldr r0,[r3,#4] */
            uint32_t *row = (uint32_t *)(uintptr_t)(rows + ((uint32_t)i << 3));
            MemoryManager_Free((const void *)(uintptr_t)row[1]);  /* 0x1e3b90 */

            /* 0x1e3b94: ldr r0,[r6,#0x40]；0x1e3b98: ldr r2,[r6,#0x3c]
             * 必须在外调之后重读：回调可能改写表指针或计数。 */
            rows  = self->mask_rows;
            count = self->mask_count;

            /* 0x1e3b9c: r5 = 新基址 + (i<<3) */
            row = (uint32_t *)(uintptr_t)(rows + ((uint32_t)i << 3));
            row[1] = 0;                                       /* 0x1e3ba0 */
            row[0] = 0;                                       /* 0x1e3ba4 */

            /* 0x1e3ba8..0x1e3bb0: i++; cmp i,count; blt 回循环头 */
        }
    }

    /* 0x1e3bb4: bl MemoryManager::Free —— r0 是最后一次重读的 rows。
     * 0x1e3bb8..0x1e3bc4: 0x40=0，然后 0x3c=0，然后 0x31=0（此序为语义）。 */
    MemoryManager_Free((const void *)(uintptr_t)rows);
    self->mask_rows = 0;
    self->mask_count = 0;
    self->has_mask = 0;
}

void CSprite_FreeTexture(CSprite *self)
{
    int32_t count = self->texture_count;   /* 0x1e56fc */
    if (count <= 0) {                      /* 0x1e5704 cmp / 0x1e570c pople: signed <=0 */
        return;
    }

    uint32_t ids = self->texture_ids;      /* 0x1e5710 */
    int32_t i = 0;                         /* 0x1e5714: r4=0 */
    do {
        /* 0x1e571c: ldr r0,[r3,r4,lsl #2] */
        int32_t id = ((const int32_t *)(uintptr_t)ids)[i];

        /* 0x1e5720..0x1e5724: cmp r0,#0; blt 跳过槽（无效/已释放 id 不回调） */
        if (id >= 0) {
            GR_Texture_Free(id);           /* 0x1e5728 */

            /* 0x1e572c: ldr r3,[r5,#0x50] —— 外调后重读 id 数组基址 */
            ids = self->texture_ids;
            ((int32_t *)(uintptr_t)ids)[i] = -1;  /* 0x1e5730: r6=-1 */

            /* 0x1e5734: ldr r2,[r5,#0x4c] —— 外调后重读计数 */
            count = self->texture_count;
        }

        i++;                               /* 0x1e5738 */
        /* 0x1e573c..0x1e5740: cmp r2,r4; bgt 回循环头（签名比较，count>i 才继续）。
         * 正计数入环；初始负计数已由 pople 早退。 */
    } while (count > i);

    /* 0x1e5744: pop —— 表指针与计数保持原值，仅被释放的槽写成 -1。 */
}
