/* csprite_clear.h — CSprite 布局模型（仅覆盖 Clear 及其直接依赖所需字段）
 *
 * 目标：/data/data/com.termux/files/home/callys-caves-2-rs/reconstruction/live-mem/libyoyo_armv7.so
 *       sha256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 * 函数：_ZN7CSprite5ClearEv @ 0x1e6b4c .. 0x1e6cb0（0x164 字节）
 *       .ARM.exidx @0x326bf8：Compact (Inline)、PR index 0、opcode AA/B0/B0；
 *       不是 EXIDX_CANTUNWIND（哨兵值是精确的 1）。
 *
 * 布局证据（全部为静态读数，非猜测）：
 *   - sizeof(CSprite) == 0x88：Sprite_Add @0x1f122c `mov r0,#136` → `bl _Znwj` → ctor。
 *   - 字段偏移来自 Clear 本体、ctor @0x1e761c、以及读/写同一偏移的兄弟函数
 *     （InitLocalTPE @0x1e5854、GenerateBitmapData @0x1e65d8、Assign @0x1e76e8 等）。
 *   - 0x08..0x17 是 tagYYRECT：SetBoundingBox @0x1e32e8 写 0x08/0x0c/0x10/0x14。
 *
 * 指针一律用 uint32_t 承载，使该模型在 64 位主机上也能保持与 ARM32 完全相同的
 * 偏移（便于在 x86_64 上跑 offsetof 断言与编译检查）。访问真实指针时经
 * (void *)(uintptr_t)。
 */
#ifndef CSPRITE_CLEAR_MODEL_H
#define CSPRITE_CLEAR_MODEL_H

#include <stdint.h>
#include <stddef.h>

typedef struct CSprite {
    uint32_t vptr;              /* 0x00 vtable 地址点（ARM32: [0]=D1, [1]=D0） */
    int32_t  bbox_mode;         /* 0x04 SetBoundingBoxMode 0..2；Clear 复位 0 */
    int32_t  bbox[4];           /* 0x08 tagYYRECT {left, top, right, bottom} */
    int32_t  frame_count;       /* 0x18 帧/位图槽数；Clear 置 0 */
    int32_t  width;             /* 0x1c 位图宽；Clear 置 1 */
    int32_t  height;            /* 0x20 位图高；Clear 置 1 */
    int32_t  field_24;          /* 0x24 CreateFromBitmap 的 int 参数；Clear 置 0 */
    int32_t  field_28;          /* 0x28 CreateFromBitmap 的 int 参数；Clear 置 0 */
    int32_t  field_2c;          /* 0x2c Assign 拷贝；Clear 不动 */
    uint8_t  flag_30;           /* 0x30 CreateFromBitmap 的 bool 参数；Clear 置 1 */
    uint8_t  has_mask;          /* 0x31 FreeMask 的门；Clear 经 FreeMask 置 0 */
    uint8_t  flag_32;           /* 0x32 LoadFromAnimation 的 bool 参数；Clear 置 1 */
    uint8_t  flag_33;           /* 0x33 LoadFromAnimation 的 bool 参数；Clear 置 0 */
    uint8_t  flag_34;           /* 0x34 CreateFromBitmap 的 bool 参数；Clear 置 1 */
    uint8_t  flag_35;           /* 0x35 ctor 置 1；Clear 不动 */
    uint8_t  owns_local_tpe;    /* 0x36 1 = 0x54 数组归本对象所有（InitLocalTPE 置 1；
                                 * Clear 只在 0x54!=0 的路径上清 0；不是全库不变量） */
    uint8_t  pad_37;            /* 0x37 对齐填充 */
    int32_t  local_tpe_count;   /* 0x38 InitLocalTPE 写入的条目数；Clear 不动 */
    int32_t  mask_count;        /* 0x3c FreeMask 的循环上界 */
    uint32_t mask_rows;         /* 0x40 mask 行表（元素 8 字节，pPtr 在 +4） */
    int32_t  bitmap_count;      /* 0x44 0x48 数组中有效元素数 */
    uint32_t bitmaps;           /* 0x48 CBitmap32* 数组 */
    int32_t  texture_count;     /* 0x4c 0x50 数组元素数（FreeTexture 用） */
    uint32_t texture_ids;       /* 0x50 GL 纹理 id 数组（int，-1 为无效） */
    uint32_t local_tpe;         /* 0x54 4 字节指针数组，元素指向 22 字节 TPE 条目 */
    uint32_t skeleton;          /* 0x58 CSkeletonSprite*（type==2 时存在） */
    int32_t  field_5c;          /* 0x5c CreateFromBitmap 跨 Clear 保留的 int */
    int32_t  field_60;          /* 0x60 Clear 置 0 */
    int32_t  field_64;          /* 0x64 Clear 不动 */
    int32_t  field_68;          /* 0x68 Clear 不动 */
    float    field_6c;          /* 0x6c ctor 写 30.0f；Clear 不动 */
    int32_t  field_70;          /* 0x70 Clear 不动 */
    int32_t  type;              /* 0x74 0=位图 1=SWF 2=骨架；Clear 按 ==1 分流后置 0 */
    uint8_t  field_78;          /* 0x78 Clear 不动 */
    uint8_t  pad_79[3];         /* 0x79..0x7b */
    uint32_t swf_objects;       /* 0x7c ClearSWFData 释放并置 0（仅 type==1 路径） */
    int32_t  swf_object_count;  /* 0x80 同上 */
    uint32_t swf_dictionary;    /* 0x84 ClearSWFData 释放并置 0 */
} CSprite;                      /* sizeof == 0x88（Sprite_Add 的 `mov r0,#136`） */

#if defined(__cplusplus)
#define CSPRITE_STATIC_ASSERT(c, m) static_assert(c, m)
#else
#define CSPRITE_STATIC_ASSERT(c, m) _Static_assert(c, m)
#endif

CSPRITE_STATIC_ASSERT(offsetof(CSprite, vptr)            == 0x00, "vptr");
CSPRITE_STATIC_ASSERT(offsetof(CSprite, bbox_mode)       == 0x04, "bbox_mode");
CSPRITE_STATIC_ASSERT(offsetof(CSprite, bbox)            == 0x08, "bbox");
CSPRITE_STATIC_ASSERT(offsetof(CSprite, frame_count)     == 0x18, "frame_count");
CSPRITE_STATIC_ASSERT(offsetof(CSprite, width)           == 0x1c, "width");
CSPRITE_STATIC_ASSERT(offsetof(CSprite, height)          == 0x20, "height");
CSPRITE_STATIC_ASSERT(offsetof(CSprite, field_24)        == 0x24, "field_24");
CSPRITE_STATIC_ASSERT(offsetof(CSprite, field_28)        == 0x28, "field_28");
CSPRITE_STATIC_ASSERT(offsetof(CSprite, field_2c)        == 0x2c, "field_2c");
CSPRITE_STATIC_ASSERT(offsetof(CSprite, flag_30)         == 0x30, "flag_30");
CSPRITE_STATIC_ASSERT(offsetof(CSprite, has_mask)        == 0x31, "has_mask");
CSPRITE_STATIC_ASSERT(offsetof(CSprite, flag_32)         == 0x32, "flag_32");
CSPRITE_STATIC_ASSERT(offsetof(CSprite, flag_33)         == 0x33, "flag_33");
CSPRITE_STATIC_ASSERT(offsetof(CSprite, flag_34)         == 0x34, "flag_34");
CSPRITE_STATIC_ASSERT(offsetof(CSprite, flag_35)         == 0x35, "flag_35");
CSPRITE_STATIC_ASSERT(offsetof(CSprite, owns_local_tpe)  == 0x36, "owns_local_tpe");
CSPRITE_STATIC_ASSERT(offsetof(CSprite, local_tpe_count) == 0x38, "local_tpe_count");
CSPRITE_STATIC_ASSERT(offsetof(CSprite, mask_count)      == 0x3c, "mask_count");
CSPRITE_STATIC_ASSERT(offsetof(CSprite, mask_rows)       == 0x40, "mask_rows");
CSPRITE_STATIC_ASSERT(offsetof(CSprite, bitmap_count)    == 0x44, "bitmap_count");
CSPRITE_STATIC_ASSERT(offsetof(CSprite, bitmaps)         == 0x48, "bitmaps");
CSPRITE_STATIC_ASSERT(offsetof(CSprite, texture_count)   == 0x4c, "texture_count");
CSPRITE_STATIC_ASSERT(offsetof(CSprite, texture_ids)     == 0x50, "texture_ids");
CSPRITE_STATIC_ASSERT(offsetof(CSprite, local_tpe)       == 0x54, "local_tpe");
CSPRITE_STATIC_ASSERT(offsetof(CSprite, skeleton)        == 0x58, "skeleton");
CSPRITE_STATIC_ASSERT(offsetof(CSprite, field_5c)        == 0x5c, "field_5c");
CSPRITE_STATIC_ASSERT(offsetof(CSprite, field_60)        == 0x60, "field_60");
CSPRITE_STATIC_ASSERT(offsetof(CSprite, field_64)        == 0x64, "field_64");
CSPRITE_STATIC_ASSERT(offsetof(CSprite, field_68)        == 0x68, "field_68");
CSPRITE_STATIC_ASSERT(offsetof(CSprite, field_6c)        == 0x6c, "field_6c");
CSPRITE_STATIC_ASSERT(offsetof(CSprite, field_70)        == 0x70, "field_70");
CSPRITE_STATIC_ASSERT(offsetof(CSprite, type)            == 0x74, "type");
CSPRITE_STATIC_ASSERT(offsetof(CSprite, field_78)        == 0x78, "field_78");
CSPRITE_STATIC_ASSERT(offsetof(CSprite, swf_objects)     == 0x7c, "swf_objects");
CSPRITE_STATIC_ASSERT(offsetof(CSprite, swf_object_count)== 0x80, "swf_object_count");
CSPRITE_STATIC_ASSERT(offsetof(CSprite, swf_dictionary)  == 0x84, "swf_dictionary");
CSPRITE_STATIC_ASSERT(sizeof(CSprite)                    == 0x88, "sizeof CSprite");

/* ---- 外部依赖：只声明，不实现；用原始 mangled 名做链接级 ABI 绑定 ---- */

/* _ZN15CSkeletonSpriteD2Ev @0xbd910：基对象析构（不是 D0）。Clear 之后立即 operator delete。 */
extern void CSkeletonSprite_D2(void *self) __asm__("_ZN15CSkeletonSpriteD2Ev");

/* _ZdlPv @0x27d1d0：一条 b 到 MemoryManager::Free。 */
extern void Sprite_operator_delete(void *p) __asm__("_ZdlPv");

/* _ZN13MemoryManager4FreeEPKv @0x27c2d0：NULL 安全（入口 subs/popeq），Clear 依赖此合同。 */
extern void MemoryManager_Free(const void *p) __asm__("_ZN13MemoryManager4FreeEPKv");

extern void CSprite_ClearSWFData(CSprite *self) __asm__("_ZN7CSprite12ClearSWFDataEv");
extern void CSprite_FreeTexture(CSprite *self)  __asm__("_ZN7CSprite11FreeTextureEv");
extern void CSprite_FreeMask(CSprite *self)     __asm__("_ZN7CSprite8FreeMaskEv");

/* 译文入口：直接导出原件的 mangled 名，这样原 .so 里 `bl 0x1e6b4c` 的调用点
 * 可以按符号名与本目标文件对接（C 名只是本编译单元内的别名）。
 * ARM32 AAPCS 下 this 走 r0，与原件一致。 */
void CSprite_Clear(CSprite *self) __asm__("_ZN7CSprite5ClearEv");

#endif /* CSPRITE_CLEAR_MODEL_H */
