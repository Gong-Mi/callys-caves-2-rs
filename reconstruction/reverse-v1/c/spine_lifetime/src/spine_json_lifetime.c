/* spine_json_lifetime.c — spine 解析器句柄的创建/销毁（本批唯一指派的两个 public）
 *
 * 原件（只读，不执行）：/data/data/com.termux/files/home/callys-caves-2-rs/
 *   reconstruction/live-mem/libyoyo_armv7.so
 *   sha256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 *
 * .dynsym 复核（与上下文一致）：
 *   spSkeletonJson_create            0x28b734  size 24  6 条指令，无字面量池
 *   spSkeletonJson_dispose           0x28b74c  size 56 14 条指令，无字面量池
 *   spSkeletonJson_createWithLoader  0x28b700  size 52 12 条指令 + 1 个字面量
 *     ↑ 这个也是 GLOBAL，但它是 create 在 28b73c 直接调用的 52 字节 helper，
 *       按「<=256B 直接 helper 可同批」一并恢复；不是本次指派的那两个 public。
 *
 * ── 对象是 28 字节（静态依据，非猜测）──────────────────────────────────
 *   28b704 `mov r1,#28` + 28b718 `mov r0,#1` → 28b71c `bl _calloc`
 *   28b724 `str r4,[r0,#4]`、28b728 `str r2,[r0]`（r2 = #0x3f800000 = 1.0f）
 *   dispose 只碰 +0x0c / +0x04 / +0x18 / +0x08 / self
 *   ⇒ 7 个 32 位槽；32 位目标上指针与 float 都按 4 字节槽处理。
 *
 * ── 两个入口的语义（逐条对齐原件）──────────────────────────────────────
 *   create:
 *     28b734 push {r3,lr}    → 仅为 8 字节对齐保存 r3（死值）
 *     28b738 bl spAtlasAttachmentLoader_create  （r0 = atlas，未改写过）
 *     28b73c bl spSkeletonJson_createWithLoader （r0 = 上一步返回值）
 *     28b740 mov r3,#1 / 28b744 str r3,[r0,#0xc] → +0x0c = 1
 *     28b748 pop {r3,pc}     → 返回 r0（helper 的结果，未做 NULL 检查）
 *   dispose:
 *     28b74c ldr r3,[r0,#0xc]  ← 在 push 之前就读，且**不检查 j==NULL**
 *     28b754 cmp r3,#0 / 28b75c beq 28b768 → owns_loader == 0 时跳过
 *     28b760 ldr r0,[r0,#4] / 28b764 bl spAttachmentLoader_dispose
 *     28b768 ldr r0,[r4,#0x18] / 28b76c bl _free
 *     28b770 ldr r0,[r4,#8]    / 28b774 bl _free
 *     28b778 mov r0,r4 / 28b77c pop {r4,lr} / 28b780 b _free（尾调用）
 *     ⇒ 释放顺序恒为 +0x18 → +0x08 → self；不把字段清零，不读 +0x10/+0x14。
 *
 * 依赖一律 extern（spAtlas/spAttachmentLoader 都不在本 TU 展开）。
 */
#include <stddef.h>
#include <stdint.h>

/* 共享原型/opaque 类型：直接包含主树头，不复制、不修改。构建可用 -D 覆盖。 */
/* 注意：不能叫 YY_SKEL_DEPS_H——那是共享头自己的 include guard，-D 同名会把整个头跳过。 */
#ifndef YY_SKEL_DEPS_HDR
#define YY_SKEL_DEPS_HDR "../../cskeleton_lifetime/src/yy_skel_deps.h"
#endif
#include YY_SKEL_DEPS_HDR

/* ── spSkeletonJson：28 字节 / 7 槽。共享头里是不完整类型，这里补全定义 ── */
struct spSkeletonJson {
    uint32_t scale;        /* +0x00 float 1.0f（28b720/28b728 写 0x3f800000）*/
    uint32_t loader;       /* +0x04 spAttachmentLoader*（28b724）*/
    uint32_t unk_08;       /* +0x08 dispose 28b770 free；用途 unknown */
    uint32_t owns_loader;  /* +0x0c create 28b744 置 1；dispose 28b74c 读门 */
    uint32_t unk_10;       /* +0x10 本批未见读写 */
    uint32_t unk_14;       /* +0x14 本批未见读写 */
    uint32_t unk_18;       /* +0x18 dispose 28b768 free；用途 unknown */
};

_Static_assert(sizeof(struct spSkeletonJson) == 28, "28b704 mov r1,#28 + 28b718 mov r0,#1");
_Static_assert(offsetof(struct spSkeletonJson, scale)       == 0x00, "28b728 str r2,[r0]");
_Static_assert(offsetof(struct spSkeletonJson, loader)      == 0x04, "28b724 str r4,[r0,#4]");
_Static_assert(offsetof(struct spSkeletonJson, unk_08)      == 0x08, "28b770 ldr r0,[r4,#8]");
_Static_assert(offsetof(struct spSkeletonJson, owns_loader) == 0x0c, "28b744 str r3,[r0,#0xc]");
_Static_assert(offsetof(struct spSkeletonJson, unk_18)      == 0x18, "28b768 ldr r0,[r4,#0x18]");

/* ── 本 TU 局部依赖声明（提议给父级并入共享头；本批不改共享头）─────────
 * _calloc 0x285c4c：入口 `mul r4,r1,r0` → `mov r1,r2; mov r2,r3` → _malloc，
 *   返回后 memset(块,0,nmemb*size) ⇒ 4 形参 (nmemb,size,tag,line)，tag/line 只透传。
 * _free 0x285c80：单参，dispose 末尾 28b780 尾调用。
 * spAtlasAttachmentLoader_create 0x284bb4：单参（只读 r0，存 r5）。
 * spAttachmentLoader_dispose    0x284d38：单参，走 [loader+8]->+0xc vtable 再 _free(loader)。
 */
void *_calloc(uint32_t nmemb, uint32_t size, const char *tag, uint32_t line);
void  _free(void *p);
spAttachmentLoader *spAtlasAttachmentLoader_create(spAtlas *atlas);
void spAttachmentLoader_dispose(spAttachmentLoader *loader);

spSkeletonJson *spSkeletonJson_createWithLoader(void *loader);

/* Literal at 28b730 resolves to original NUL-terminated bytes at 0x357b08.
 * Keep the actual metadata, not a weak-unbound NULL substitute. */
static const char yy_alloc_tag_357b08[] =
    "jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonJson.c";

/* ── 译文 ───────────────────────────────────────────────────────────── */

spSkeletonJson *spSkeletonJson_createWithLoader(void *loader)
{
    /* 28b704..28b71c：_calloc(1, 28, tag, 62)；返回值不判空（原件直接往下写）*/
    spSkeletonJson *j = (spSkeletonJson *)_calloc(1u, 28u, yy_alloc_tag_357b08, 62u);
    j->loader = (uint32_t)(uintptr_t)loader;   /* 28b724 str r4,[r0,#4] */
    j->scale  = 0x3f800000u;                   /* 28b728 str r2,[r0]  = 1.0f */
    return j;                                  /* 28b72c pop {r4,pc} */
}

spSkeletonJson *spSkeletonJson_create(spAtlas *atlas)
{
    spAttachmentLoader *loader = spAtlasAttachmentLoader_create(atlas);        /* 28b738 */
    spSkeletonJson *j = spSkeletonJson_createWithLoader(loader); /* 28b73c */
    j->owns_loader = 1u;                                         /* 28b744 str r3,[r0,#0xc] */
    return j;                                                    /* 28b748 pop {r3,pc} */
}

void spSkeletonJson_dispose(spSkeletonJson *j)
{
    if (j->owns_loader) {   /* 28b74c ldr r3,[r0,#0xc] / 28b754 cmp / 28b75c beq */
        spAttachmentLoader_dispose((spAttachmentLoader *)(uintptr_t)j->loader); /* 28b760 / 28b764 */
    }
    _free((void *)(uintptr_t)j->unk_18);   /* 28b768 ldr r0,[r4,#0x18]; 28b76c bl _free */
    _free((void *)(uintptr_t)j->unk_08);   /* 28b770 ldr r0,[r4,#8];    28b774 bl _free */
    _free(j);                              /* 28b780 b _free（尾调用）*/
}
