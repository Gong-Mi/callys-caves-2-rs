/* cally 逆向卡：Sprite_Data（原版 libyoyo.so，armv7）
 * @func 0x1ef03c 0x1ef07c  size 64  16 条（0x1ef074 / 0x1ef078 两字为 literal pool，真指令 14）
 * 级别: 正文（14 条真指令全部落锚；两级边界、两个全局、表基址偏移、两条出口全证；纯读无副作用）
 * 符号: _Z11Sprite_Datai → CSprite* Sprite_Data(int i)
 * 位置: 精灵号 → CSprite* 的唯一取数口。同族紧邻：Sprite_InitTextures 0x1eedd0、Sprite_FreeTextures 0x1eee30、
 *       Sprite_Number 0x1eee84、Sprite_Exists 0x1eee98、Sprite_Name 0x1eeee0、Sprite_Find 0x1eef64、
 *       Sprite_Assign 0x1ef454；本函数被 130 处 bl 调用（GetImageNumber 0x19357c、
 *       DoSlowDrawRoom 0x1b09d8、Instance_Animate 0x1d31e0 等）
 *
 * ── 语义草案（可编译）────────────────────────────────────────────────
 *   CSprite* Sprite_Data(int i) {
 *     if (i < 0) return 0;                        // 1ef03c..1ef040
 *     if (i >= *(int*)0x7530d8) return 0;          // 精灵总数；1ef044..1ef054
 *     return (*(CSprite***)0x7530d4)[i];           // 表基址 = *(g_SpriteItems + 4)，stride 4
 *   }
 *
 * ── 两个全局（GOT 槽值与重定位类型实测）─────────────────────────────
 *   GOT 0x3f0e18（R_ARM_RELATIVE）→ 0x7530d8  int  精灵总数
 *       同址被 Sprite_Number() 原样返回（其 0x1eee84..0x1eee90 只有 ldr/ldr/ldr/bx lr）
 *       ⇒ 这个 int 就是 sprite_get_number 的返回值，即精灵数量。
 *   GOT 0x3f0e10（R_ARM_RELATIVE）→ 0x7530d0  g_SpriteItems（.dynsym：8 B OBJECT）；
 *       本函数取该对象 +4 的表指针，不先解引用 0x7530d0 的内容再加 4。
 *   g_NumberOfSprites @0x7530d8 是单独的 4 B OBJECT 符号，恰好邻接前者；
 *   符号名与大小可证，源代码中两者为何邻接仍未知。
 *   两个槽都在 .bss，零初始化：加载任何精灵之前 count == 0。
 *
 * ── 已证（逐条指到指令）──────────────────────────────────────────────
 *   1. 负数直接返回 0：cmp r0,#0 / blt 0x1ef06c（1ef03c..1ef040）；不需要无符号下界，因为
 *      cmp 后立刻 blt，后面用的是同一份 r0。
 *   2. 上界取 [0x7530d8]：ldr r3,[pc,#0x28] 取 literal 0x00201dc8 → [pc,r3] 得 0x3f0e18 →
 *      再 ldr 得 count；cmp r0,r3 / bge → 返回 0（1ef044..1ef054）。
 *   3. 表基址 = *(0x7530d0 + 4)：literal 0x00201dac → 0x3f0e10 → ldr 得对象地址 0x7530d0 →
 *      ldr r3,[r3,#0x4] → ldr r0,[r3, r0, lsl #2]（元素 4 字节，CSprite*）（1ef058..1ef068）。
 *   4. 两条出口都是 bx lr：1ef068（命中）与 1ef070（越界/负数），中间 1ef06c 只做 mov r0,#0
 *      （1ef06c..1ef070）。
 *   5. 叶子：无 push/无栈帧/无 bl/无 vpush —— 14 条指令里 3 条 ldr、2 条 cmp、2 条分支、2 条 bx lr、
 *      1 条 mov、1 条 mov r0,#0、3 条地址构造相关；纯读，不改任何全局，可安全重复调用。
 *   6. 越界安全面：count>0 但表指针仍为 0 时会空解引用（本函数不做表指针判空）；
 *      而 count==0 时任何 i（含负数）都返回 0，是全零安全的。
 *
 * ── open ─────────────────────────────────────────────────────────────
 *  1. g_SpriteItems 的源语言具体类型、+0 成员用途，以及初始化与重置的完整生命周期未在本卡逐条审完。
 *  2. g_SpriteItems 与 g_NumberOfSprites 的源码声明关系未知；只证 .dynsym 中二者为相邻独立 OBJECT 符号。
 *
 * ── 逐条锚点 ─────────────────────────────────────────────────────────
 */

/* ── 负数闸：i < 0 → 0（blt 到 1ef06c 的 mov r0,#0）───────────────────────────── */

/* @0x1ef03c cmp r0, #0 */
/* @0x1ef040 blt 0x1ef06c <_Z11Sprite_Datai+0x30> */

/* ── 上界：count = [0x7530d8]（GOT 0x3f0e18，R_ARM_RELATIVE）；i >= count → 0 ─────
 *   1ef044 取 literal 0x00201dc8（在 1ef074），1ef048 [pc,r3] → 0x3f0e18，1ef04c 解引用得 count。
 */

/* @0x1ef044 ldr r3, [pc, #0x28] */
/* @0x1ef048 ldr r3, [pc, r3] */
/* @0x1ef04c ldr r3, [r3] */
/* @0x1ef050 cmp r0, r3 */
/* @0x1ef054 bge 0x1ef06c <_Z11Sprite_Datai+0x30> */

/* ── 取表：*(0x7530d0 + 4)；[base + i*4] 即 CSprite* ────────────────────────
 *   1ef058 取 literal 0x00201dac（在 1ef078），1ef05c [pc,r3] → 0x3f0e10 → 0x7530d0；
 *   1ef060 ldr r3,[r3,#0x4] 是表基址；1ef064 ldr r0,[r3,r0,lsl #2]；1ef068 bx lr 返回。
 */

/* @0x1ef058 ldr r3, [pc, #0x18] */
/* @0x1ef05c ldr r3, [pc, r3] */
/* @0x1ef060 ldr r3, [r3, #0x4] */
/* @0x1ef064 ldr r0, [r3, r0, lsl #2] */
/* @0x1ef068 bx lr */

/* ── 越界/负数出口：r0 = 0，bx lr（唯一的 0 返回值构造点）────────────────────── */

/* @0x1ef06c mov r0, #0 */
/* @0x1ef070 bx lr */

/* ── literal pool 两字（非指令，objdump 译成 eoreq）─────────────────────────────
 *   0x1ef074 = 0x00201dc8：0x1ef04c + 该值 = 0x3f0e18（数量槽）
 *   0x1ef078 = 0x00201dac：0x1ef064 + 该值 = 0x3f0e10（表对象槽）
 */

/* @0x1ef074 eoreq r1, r0, r8, asr #27 */
/* @0x1ef078 eoreq r1, r0, r12, lsr #27 */
