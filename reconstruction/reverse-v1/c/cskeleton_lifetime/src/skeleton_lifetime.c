/* skeleton_lifetime.c — CSkeletonSprite 构造 (C1/C2) 与基对象析构 (D1/D2) 的 C 译文
 *
 * 原件：libyoyo_armv7.so  sha256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 *   C1/C2: [0xbd86c,0xbd910), 39 条指令 + 2 字 literal pool，共164B。
 *   D1/D2: [0xbd910,0xbd96c), 22 条指令 + 1 字 literal pool，共92B。
 *   （C1/D1 与 C2/D2 同址，.dynsym 各两条；size 与地址本次用 readelf -sW 复核一致）
 *   .dynsym 复核：C2 0xbd86c/164、C1 0xbd86c/164、D2 0xbd910/92、D1 0xbd910/92。
 *
 * 调用点（全库 bl 计数）：ctor 只有 1 处（Loader 0x1e9a44），D2 有 2 处
 * （0x1e6b70 = CSprite::Clear、0x1e747c）。两处都用 `bl`，所以 C2/D2 必须是
 * 真实可调用函数，不能靠内联。
 *
 * 原型与 CSprite 布局**全部来自主树头文件**（YY_LOADER_H / YY_CLEAR_H），本文件
 * 不定义 CSprite、不改头。函数名沿用头里的 C 别名，实际导出的是原 mangled 名：
 *   CSkeletonSprite_ctor → _ZN15CSkeletonSpriteC2EPcjjjjj   （Loader 头 133-137 行）
 *   CSkeletonSprite_D2   → _ZN15CSkeletonSpriteD2Ev         （Clear  头 113-114 行）
 *
 * 每条语句后面的 bdXXX 是原件指令锚点；逐条反汇编在 SEMANTICS.md 里。
 */
#include "yy_skel_deps.h"

/* ── C2 @0xbd86c ─────────────────────────────────────────────────────────
 * 入口（AAPCS，softfp）：r0=this  r1=name(char*)  r2=a  r3=b  [sp]=c [sp+4]=d [sp+8]=e
 * 帧：bd86c `push {r3,r4,r5,r6,r7,r8,r9,r10,r11,lr}` = 10 个字 40 B，
 *     所以 3 个栈参数落在 [sp+0x28]/[sp+0x2c]/[sp+0x30]
 *     （bd87c ldr r11 #0x28 = c，bd884 ldr r10 #0x2c = d，bd88c ldr r9 #0x30 = e）。
 * 寄存器搬家：bd870 add r8,r1,r2 → name+a；bd878 mov r4,r0 → this；
 *             bd880 mov r7,r3 → b；bd8a8 mov r6,r1 → name。
 * 返回：bd900 `mov r0,r4` + bd904 `pop {...pc}` ⇒ r0 = this。
 *   共享 C 头已校正为返回 void*，即使当前调用者忽略它，也保留原 AAPCS 返回值。
 */
void *CSkeletonSprite_ctor(void *self, char *name,
                          unsigned a, unsigned b, unsigned c,
                          unsigned d, unsigned e)
{
    yy_skel12 *o = (yy_skel12 *)self;

    /* bd890 mov r5,#0；bd898 str r5,[r0] / bd89c str r5,[r0,#4] / bd8a4 str r5,[r0,#8]
     * 三次清零都在第一次 bl（bd8bc）之前，顺序是 +0x00、+0x04、+0x08 ——
     * 中间被 bd8a0 的地址计算和 bd8ac..bd8b8 的全局写插进来，但都是纯寄存器/全局，
     * 不碰 this。 */
    o->slot_00_json  = 0u;
    o->slot_04_data  = 0u;
    o->slot_08_atlas = 0u;

    /* bd894 add lr,r2,r3 / bd8a0 add lr,r1,lr / bd8ac str lr,[r12]
     *   r12 = pc + 0x3bc408（bd874 ldr r12,[pc,#0x8c]→0xbd908 字面量 0x003bc408，
     *   bd888 add r12,pc,r12，pc=0xbd890）⇒ 0x479c98，.bss 里 16 字节匿名静态。
     * bd8b0/bd8b4/bd8b8：str r11/[r12,#4]、str r10/[r12,#8]、str r9/[r12,#0xc]
     *   ⇒ {name+a+b, c, d, e}
     * 这一段在两次 SimpleDecode 之前，是构造过程中的真实副作用，不能省。 */
    g_yy_479c98.end = (uint32_t)(uintptr_t)(name + (size_t)a + (size_t)b);
    g_yy_479c98.w04 = c;
    g_yy_479c98.w08 = d;
    g_yy_479c98.w0c = e;

    /* bd8bc bl 0xbd840：此时 r0=this（未动过）、r1=name（bd8a8）、r2=a（入口值）
     *   ⇒ SimpleDecode(this, name, a)，解的是 [name, name+a) */
    CSkeletonSprite_SimpleDecode(self, (unsigned char *)name, (int)a);

    /* bd8c0 mov r1,r8 / bd8c4 mov r0,r4 / bd8c8 mov r2,r7
     *   ⇒ SimpleDecode(this, name+a, b)，解的是 [name+a, name+a+b)
     *   两段首尾相接；第一段长度 a、第二段长度 b 都取自入口实参，不是长度前缀。 */
    CSkeletonSprite_SimpleDecode(self, (unsigned char *)(name + a), (int)b);

    /* bd8d0 ldr r2,[pc,#0x34]→0xbd90c 字面量 0x0027125a；bd8dc add r2,pc,r2
     *   pc=0xbd8e4 ⇒ 0x32eb3e = .rodata+0xe，该处字节是 0x00（"libGLESv2.so" 之前
     *   的补齐）⇒ 第 3 个实参是空字符串 ""。
     * bd8d4 mov r1,r7 (len=b)、bd8d8 mov r3,r5 (r5=0 ⇒ NULL)、bd8e0 mov r0,r8 (data=name+a)
     *   ⇒ spAtlas_create(name+a, b, "", NULL)
     * bd8e8 str r0,[r4,#0x8] ⇒ +0x08 = atlas */
    spAtlas *atlas = spAtlas_create((const char *)(name + a), (int)b, "", NULL);
    o->slot_08_atlas = (uint32_t)(uintptr_t)atlas;

    /* bd8ec bl 0x28b734，r0 = 上一条 spAtlas_create 的返回值（原函数直接用 r0，
     * 没有从 [r4,#8] 重新 ldr）
     * bd8f4 str r0,[r4] ⇒ +0x00 = json */
    spSkeletonJson *json = spSkeletonJson_create(atlas);
    o->slot_00_json = (uint32_t)(uintptr_t)json;

    /* bd8f0 mov r1,r6（r6 = name 基址，不是 name+a）+ bd8f8 bl 0x28b84c
     * bd8fc str r0,[r4,#0x4] ⇒ +0x04 = skeletonData
     * text 实参取 name 基址；不根据未经验证的资源格式把它改成 name+a。 */
    spSkeletonData *data;
#if YY_MUTANT == 1
    /* 安全变异 1（只用于测试，默认 0）：把 text 实参改成第二段起点。
     * 应由 ctor_read_data_uses_base_pointer 杀掉。 */
    data = spSkeletonJson_readSkeletonData(json, name + a);
#else
    data = spSkeletonJson_readSkeletonData(json, name);
#endif
    o->slot_04_data = (uint32_t)(uintptr_t)data;

    return self; /* bd900 mov r0,r4 */
}

/* ── D2 @0xbd910 ─────────────────────────────────────────────────────────
 * 入口：r0=this。帧：bd910 `push {r3,r4,r5,lr}` = 16 B（没有栈参数）。
 * 释放顺序是 **da+4 → json+0 → (旗标 1) → atlas+8**，不是构造顺序的逆序
 * （构造是 atlas→json→data），也不是常见的"先 json 后 data"。
 * 每个 dispose 前都有 ldr/cmp/beq 的 NULL 闸（bd91c、bd92c、bd948），
 * 三个 `beq` 全部跳到"跳过 bl"的下一格，条件码都是 EQ（0a000000）。
 * 三个槽释放后**不清零**（0xbd910..0xbd96b 里对 [r5]/[r5,#4]/[r5,#8] 只有 ldr）。
 * r0 = this（bd95c mov r0,r5）返回。
 */
void *CSkeletonSprite_D2(void *self)
{
    yy_skel12 *o = (yy_skel12 *)self;

    /* bd918 ldr r0,[r0,#0x4] / bd91c cmp r0,#0 / bd920 beq 0xbd928 / bd924 bl spSkeletonData_dispose */
    if (o->slot_04_data) {
        spSkeletonData_dispose((spSkeletonData *)(uintptr_t)o->slot_04_data);
    }

    /* bd928 ldr r0,[r5] / bd92c cmp / bd930 beq 0xbd938 / bd934 bl spSkeletonJson_dispose */
    if (o->slot_00_json) {
        spSkeletonJson_dispose((spSkeletonJson *)(uintptr_t)o->slot_00_json);
    }

    /* bd938 ldr r4,[pc,#0x28]→0xbd968 字面量 0x0032ffd4；bd944 ldr r4,[pc,r4]
     *   pc=0xbd94c ⇒ 0x3ed920，.got 槽（R_ARM_RELATIVE，原地 addend = 0x479ca8）
     *   ⇒ r4 = &g_bFreeingSpineSprite（.dynsym GLOBAL OBJECT 1 B）。
     * bd93c mov r3,#1；bd94c strb r3,[r4] 无条件写 1 ——
     *   它在 bd948 `cmp r0,#0` 之后、bd950 `beq 0xbd958` 之前执行，
     *   而 0xbd958 正是写 0 的那一格 ⇒ **atlas 为 NULL 时也照样 1→0**。
     * bd958 mov r3,#0 / bd960 strb r3,[r4] 无条件写 0 ⇒ 不保存旧值、不嵌套、
     *   也不恢复成 1。 */
#if YY_MUTANT == 2
    /* 安全变异 2（只用于测试，默认 0）：把旗标窗口塞进 atlas 的 NULL 闸里。
     * 应由 dtor_clears_flag_when_atlas_is_null 杀掉。 */
    if (o->slot_08_atlas) {
        g_bFreeingSpineSprite = 1;
        spAtlas_dispose((spAtlas *)(uintptr_t)o->slot_08_atlas);
        g_bFreeingSpineSprite = 0;
    }
#else
    g_bFreeingSpineSprite = 1;
    if (o->slot_08_atlas) {
        spAtlas_dispose((spAtlas *)(uintptr_t)o->slot_08_atlas);
    }
    g_bFreeingSpineSprite = 0;
#endif

    return self; /* bd95c mov r0,r5 */
}

/* The original dynsym C1/C2 and D1/D2 are same-address aliases. */
extern __typeof__(CSkeletonSprite_ctor) CSkeletonSprite_ctor_C1
    __asm__("_ZN15CSkeletonSpriteC1EPcjjjjj")
    __attribute__((alias("_ZN15CSkeletonSpriteC2EPcjjjjj")));
extern __typeof__(CSkeletonSprite_D2) CSkeletonSprite_D1
    __asm__("_ZN15CSkeletonSpriteD1Ev")
    __attribute__((alias("_ZN15CSkeletonSpriteD2Ev")));
