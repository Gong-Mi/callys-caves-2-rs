/* cally 逆向卡：Room_LoadOrder（原版 libyoyo.so，armv7）
 * @func 0x1b5ba0 0x1b5d08  size 360  90 条（0x1b5cf0..0x1b5d04 为 literal pool，6 字；objdump 当指令译，实为数据）
 * 级别: 正文（七个版本档的取值、三条出口、ReAlloc/Free 与逐字拷贝全部逐条钉住，并与同一全局块的
 *             Room_First 0x1b5d08 / Room_Last 0x1b5d20 / Room_Previous 0x1b5d40 / Room_Next 0x1b5da4、
 *             Room_Load 0x1b4cd8、Header_Load 0x1dd0b0 交叉印证，且用 assets/game.droid 的 GEN8 块实测核对；
 *             未钉：为什么七个档位的字段布局互相重叠、负 count 的运行期后果）
 * 符号: _Z14Room_LoadOrderP8YYHeaderi → bool Room_LoadOrder(YYHeader* pHdr, int unused)
 * ABI : softfp；返回 bool，三条出口全恒 true（0x1b5be4 / 0x1b5c90 / 0x1b5cbc 都是 mov r0,#1）
 * 同层: Header_Load 0x1dd0b0（唯一调用者，r0 = 已解析好的 general-info 头）、Room_Load 0x1b4cd8
 *       （同一个 24 B 全局块的前两组表由它建）、Room_First/Last/Previous/Next（顺序表的四个读者）、
 *       MemoryManager::ReAlloc 0x27cedc / Free 0x27c2d0
 *
 * ── 一句话 ─────────────────────────────────────────────────────
 *   按 general-info 头里的**字节码版本号**（+0x01）挑一组 (count, 数组) 字段，把那个数组里 count 个 int
 *   拷进全局「房间顺序表」。这个表就是 Room_First/Next/Previous/Last 遍历用的房间次序。
 *
 * ── 落点：还是 0x5425d0 那 24 字节，本函数用第三对 ─────────────────
 *   +0x10 (0x5425e0) int   count
 *   +0x14 (0x5425e4) int*  array（ReAlloc 得到，元素 4 B）
 *   同一块里 +0x00/+0x04 是 CRoom*/计数（Room_Load 建）、+0x08/+0x0c 是名字串/计数（Room_Load 建）。
 *   ⇒ 本函数只动最后 8 字节；Room_Load 只动前 16 字节。两者合起来才是完整的房间表。
 *
 * ── 版本档 → 源字段（r0 = YYHeader*；count 与数据**相邻**，数据就地内联）──────
 *   byte[+0x01]      分支地址     count 字段   数据字段（首元素地址）
 *   ---------------  ----------  -----------  ------------------
 *   <= 7             0x1b5bb4    +0x24        +0x28
 *   8, 9             0x1b5c18    +0x64        +0x68
 *   10               0x1b5cc0    +0x68        +0x6c
 *   11               0x1b5cd8    +0x70        +0x74
 *   12               0x1b5ccc    +0x78        +0x7c
 *   13               0x1b5ce4    +0x7c        +0x80
 *   >= 14            0x1b5c10    +0x80        +0x84
 *   ★ 七档的字段是**互相重叠**的（0x68、0x7c、0x80 都既是某一档的 count 又是另一档的数据首址）。
 *     这不矛盾：只有一档会执行，等价于「同一块内存按不同 GMS 版本的 general-info 头布局重新解释」。
 *   ★ 分支顺序是链式的：先 cmp #7（bgt 出去），再 #10/#11/#12/#13 四条 beq，最后用 ldrgt/ldrle
 *     两条条件指令覆盖「>=14」与「8..9」两种情况 —— 所以 8/9 与 >=14 没有独立分支块。
 *
 * ── 实测核对（assets/game.droid 的 GEN8 块）────────────────────────
 *   GEN8 块体在 0x10（"GEN8"+size 之后）：byte[+0x00] = 1（debugger）、byte[+0x01] = 16（bytecode version）。
 *   ⇒ 16 >= 14，走 0x1b5c10 档：count = struct+0x80 = 114，数据在 struct+0x84 起，114 个值 = 0,1,2,…,113。
 *   与 crates/asset（ROOM_ORDER_OFFSET = 128、断言恒等排列）以及 apk/identity.md 的 114 ROOM 三方一致。
 *
 * ── 三条出口 ────────────────────────────────────────────────────
 *   ① count == 0（0x1b5bc4）：旧表非空则 Free，count 与 array 两格都清 0，返回 true。
 *   ② 正常拷完（0x1b5c90）：返回 true。
 *   ③ 0x1b5cbc：Free 后回到 0x1b5c58 继续写入 —— 见下面「不可达块」。
 *
 * ── 不可达块（0x1b5c9c..0x1b5cbc）────────────────────────────────
 *   只有 0x1b5c2c 的 `lsls r1,r4,#2; beq` 会跳进来，而 r4 == 0 的路径早在 0x1b5bc0 就被 0x1b5bc4 截走，
 *   所以这块在本函数里不可达（编译器为 count*4 == 0 留的兜底）。它的存在说明源码里 Free 是写在
 *   「ReAlloc 之前」的一个共用收尾块里。
 *
 * ── 未定（open）──────────────────────────────────────────────────
 *   1. 七个档位的字段为什么这样叠（各 GMS 版本的 general-info 结构体差异），本卡只到「哪档读哪格」。
 *   2. count 为负时：`lsls` 出来的 size 是巨大无符号数，ReAlloc 大概率失败返回 0，但 count 仍写成负数
 *      ⇒ Room_Last 会算 count-1 并按下标读 —— 后果未运行期验证。
 *   3. 第二参（int）在函数体内一次都没读；调用点 0x1dd0b0 传的是 [r8]，语义未定。
 *
 * ── 逐条锚点 ───────────────────────────────────────────────────
 */


/* ── 入口与 <=7 档（0x1b5ba0..0x1b5bc0）──────────────────────────
 *   帧：push {r4,r5,r6,lr} + sub sp,#8；r3 = ldrb [r0+1] = 版本字节；r0 = YYHeader*。
 *   r4 = count、r5 = 数据首址（r0 + 偏移）。r6 在清场分支里才被赋成全局块基址 0x5425d0。
 */

/* @0x1b5ba0 ldrb r3, [r0, #0x1] */
/* @0x1b5ba4 push {r4, r5, r6, lr} */
/* @0x1b5ba8 cmp r3, #7 */
/* @0x1b5bac sub sp, sp, #8 */
/* @0x1b5bb0 bgt 0x1b5bf0 <_Z14Room_LoadOrderP8YYHeaderi+0x50> */
/* @0x1b5bb4 ldr r4, [r0, #0x24] */
/* @0x1b5bb8 add r5, r0, #40 */
/* @0x1b5bbc cmp r4, #0 */
/* @0x1b5bc0 bne 0x1b5c28 <_Z14Room_LoadOrderP8YYHeaderi+0x88> */

/* ── count == 0：释放旧顺序表并把两格清 0（0x1b5bc4..0x1b5be4）────
 *   0x1b5bcc 读旧 array；非 0 → Free；0x1b5bdc/0x1b5be0 把 +0x14(0x5425e4) 与 +0x10(0x5425e0) 都写 0。
 *   ★ 只动最后 8 字节：房间表(+0x00/+0x04)与名字表(+0x08/+0x0c)不受影响。
 */

/* @0x1b5bc4 ldr r6, [pc, #0x124] */
/* @0x1b5bc8 add r6, pc, r6 */
/* @0x1b5bcc ldr r0, [r6, #0x14] */
/* @0x1b5bd0 cmp r0, #0 */
/* @0x1b5bd4 beq 0x1b5ca8 <_Z14Room_LoadOrderP8YYHeaderi+0x108> */
/* @0x1b5bd8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b5bdc str r4, [r6, #0x14] */
/* @0x1b5be0 str r4, [r6, #0x10] */
/* @0x1b5be4 mov r0, #1 */
/* @0x1b5be8 add sp, sp, #8 */
/* @0x1b5bec pop {r4, r5, r6, pc} */

/* ── 其余版本档（0x1b5bf0..0x1b5c24）──────────────────────────────
 *   0x1b5bf0 cmp #10 → 0x1b5cc0；0x1b5bf8 #11 → 0x1b5cd8；0x1b5c00 #12 → 0x1b5ccc；0x1b5c08 #13 → 0x1b5ce4。
 *   0x1b5c10 ldrgt r4,[r0,#0x80] / addgt r5,r0,#132：>= 14 档（本资产 16 走这条）。
 *   0x1b5c18 ldrle r4,[r0,#0x64] / addle r5,r0,#104：8..9 档（<=7 已在 0x1b5bb0 排掉）。
 *   0x1b5c20 统一 cmp r4,#0：为 0 走清场，否则 0x1b5c28 拷贝。
 */

/* @0x1b5bf0 cmp r3, #10 */
/* @0x1b5bf4 beq 0x1b5cc0 <_Z14Room_LoadOrderP8YYHeaderi+0x120> */
/* @0x1b5bf8 cmp r3, #11 */
/* @0x1b5bfc beq 0x1b5cd8 <_Z14Room_LoadOrderP8YYHeaderi+0x138> */
/* @0x1b5c00 cmp r3, #12 */
/* @0x1b5c04 beq 0x1b5ccc <_Z14Room_LoadOrderP8YYHeaderi+0x12c> */
/* @0x1b5c08 cmp r3, #13 */
/* @0x1b5c0c beq 0x1b5ce4 <_Z14Room_LoadOrderP8YYHeaderi+0x144> */
/* @0x1b5c10 ldrgt r4, [r0, #0x80] */
/* @0x1b5c14 addgt r5, r0, #132 */
/* @0x1b5c18 ldrle r4, [r0, #0x64] */
/* @0x1b5c1c addle r5, r0, #104 */
/* @0x1b5c20 cmp r4, #0 */
/* @0x1b5c24 beq 0x1b5bc4 <_Z14Room_LoadOrderP8YYHeaderi+0x24> */

/* ── ReAlloc + 写计数 + 逐字拷贝（0x1b5c28..0x1b5c98）──────────────
 *   0x1b5c28 lsls r1,r4,#2：size = count*4；0x1b5c4c 取旧表；
 *   0x1b5c50 ReAlloc(旧表, count*4, ".../Platform/cARRAY_STRUCTURE.h", 106, true)；0x1b5c54 写回 +0x14。
 *   0x1b5c58..0x1b5c64：r0 = 0x5425d0（literal 0x1b5cfc，pc 0x1b5c68），count 写进 +0x10。
 *   0x1b5c68 `ble`：count <= 0 直接返回 true（此时 count 已经是负/0）。
 *   0x1b5c74..0x1b5c8c：r12 = 源字 [r5+r3]，r1 = 目标表，str [r1+r3]，r3 += 4，共 count 次。
 */

/* @0x1b5c28 lsls r1, r4, #2 */
/* @0x1b5c2c beq 0x1b5c9c <_Z14Room_LoadOrderP8YYHeaderi+0xfc> */
/* @0x1b5c30 ldr r6, [pc, #0xbc] */
/* @0x1b5c34 mov r3, #0 */
/* @0x1b5c38 ldr r2, [pc, #0xb8] */
/* @0x1b5c3c add r6, pc, r6 */
/* @0x1b5c40 str r3, [sp] */
/* @0x1b5c44 add r2, pc, r2 */
/* @0x1b5c48 mov r3, #106 */
/* @0x1b5c4c ldr r0, [r6, #0x14] */
/* @0x1b5c50 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1b5c54 str r0, [r6, #0x14] */
/* @0x1b5c58 ldr r0, [pc, #0x9c] */
/* @0x1b5c5c cmp r4, #0 */
/* @0x1b5c60 add r0, pc, r0 */
/* @0x1b5c64 str r4, [r0, #0x10] */
/* @0x1b5c68 ble 0x1b5be4 <_Z14Room_LoadOrderP8YYHeaderi+0x44> */
/* @0x1b5c6c mov r3, #0 */
/* @0x1b5c70 mov r2, r3 */
/* @0x1b5c74 ldr r12, [r5, r3] */
/* @0x1b5c78 add r2, r2, #1 */
/* @0x1b5c7c ldr r1, [r0, #0x14] */
/* @0x1b5c80 cmp r2, r4 */
/* @0x1b5c84 str r12, [r1, r3] */
/* @0x1b5c88 add r3, r3, #4 */
/* @0x1b5c8c bne 0x1b5c74 <_Z14Room_LoadOrderP8YYHeaderi+0xd4> */
/* @0x1b5c90 mov r0, #1 */
/* @0x1b5c94 add sp, sp, #8 */
/* @0x1b5c98 pop {r4, r5, r6, pc} */

/* ── 不可达的兜底块（0x1b5c9c..0x1b5cbc）──────────────────────────
 *   0x1b5c9c..0x1b5ca8 Free 旧表 → 0x1b5cb8 把 +0x14 清 0 → 回 0x1b5c58 写 count 并返回。
 *   唯一入口是 0x1b5c2c 的 beq（count*4 == 0），而 count == 0 早在 0x1b5bc0 就被 0x1b5bc4 截走 ⇒ 不可达。
 *   它的存在说明源码里 Free 写在一个「ReAlloc 之前」的共用收尾块里，编译器把它排到了函数尾部。
 */

/* @0x1b5c9c ldr r3, [pc, #0x5c] */
/* @0x1b5ca0 add r3, pc, r3 */
/* @0x1b5ca4 ldr r0, [r3, #0x14] */
/* @0x1b5ca8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b5cac ldr r3, [pc, #0x50] */
/* @0x1b5cb0 mov r2, #0 */
/* @0x1b5cb4 add r3, pc, r3 */
/* @0x1b5cb8 str r2, [r3, #0x14] */
/* @0x1b5cbc b 0x1b5c58 <_Z14Room_LoadOrderP8YYHeaderi+0xb8> */

/* ── 各版本档的取值指令（0x1b5cc0..0x1b5cec）────────────────────
 *   10 → [r0+0x68] / r0+0x6c；11 → [r0+0x70] / r0+0x74；12 → [r0+0x78] / r0+0x7c；13 → [r0+0x7c] / r0+0x80。
 *   四条都是 `ldr r4,[r0,#count]` + `add r5,r0,#data`：**数据就地内联在结构体里**，不是指针。
 *   本资产版本 16 不走这四条，它们只用于兼容旧版 general-info 头。
 */

/* @0x1b5cc0 ldr r4, [r0, #0x68] */
/* @0x1b5cc4 add r5, r0, #108 */
/* @0x1b5cc8 b 0x1b5bbc <_Z14Room_LoadOrderP8YYHeaderi+0x1c> */
/* @0x1b5ccc ldr r4, [r0, #0x78] */
/* @0x1b5cd0 add r5, r0, #124 */
/* @0x1b5cd4 b 0x1b5bbc <_Z14Room_LoadOrderP8YYHeaderi+0x1c> */
/* @0x1b5cd8 ldr r4, [r0, #0x70] */
/* @0x1b5cdc add r5, r0, #116 */
/* @0x1b5ce0 b 0x1b5bbc <_Z14Room_LoadOrderP8YYHeaderi+0x1c> */
/* @0x1b5ce4 ldr r4, [r0, #0x7c] */
/* @0x1b5ce8 add r5, r0, #128 */
/* @0x1b5cec b 0x1b5bbc <_Z14Room_LoadOrderP8YYHeaderi+0x1c> */

/* ── literal pool（0x1b5cf0..0x1b5d04，6 字；非指令）─────────────
 *   0x1b5cf0 0x0038ca00 + pc 0x1b5bd0 = 0x5425d0  全局块基址（r6，清场分支）
 *   0x1b5cf4 0x0038c98c + pc 0x1b5c44 = 0x5425d0  （ReAlloc 前取旧表指针）
 *   0x1b5cf8 0x001975f0 + pc 0x1b5c4c = 0x34d23c  ".../Platform/cARRAY_STRUCTURE.h"
 *   0x1b5cfc 0x0038c968 + pc 0x1b5c68 = 0x5425d0  （写 count 的基址）
 *   0x1b5d00 0x0038c928 + pc 0x1b5ca8 = 0x5425d0  （不可达块里清 array 格）
 *   0x1b5d04 0x0038c914 + pc 0x1b5cbc = 0x5425d0  （不可达块回跳前的基址）
 */

/* @0x1b5cf0 eorseq r12, r8, r0, lsl #20 */
/* @0x1b5cf4 eorseq r12, r8, r12, lsl #19 */
/* @0x1b5cf8 ldrsheq r7, [r9], -r0 */
/* @0x1b5cfc eorseq r12, r8, r8, ror #18 */
/* @0x1b5d00 eorseq r12, r8, r8, lsr #18 */
/* @0x1b5d04 eorseq r12, r8, r4, lsl r9 */
