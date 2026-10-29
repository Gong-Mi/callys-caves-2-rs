/* cally 逆向卡：DoMul —— 乘法处理器（K/tag 跳表 + 分支体）原版 libyoyo.so，armv7
 * @func 0xe5810 0xe61b4  size 2468  617 条
 * 级别: 正文（跳表机制、K/tag 提取、7 个表项与全部段内目标逐条落锚；各臂的数值语义 open）
 * 符号 _Z5DoMuljPhPKhP6VMExec
 * ⚠ 范围取 census 的归属（f field = 0xe5810 的全部指令），**不是** asm/functions.tsv 的 size：
 *   functions.tsv 写 2468 B（0xe5810..0xe5bb4），但跳表目标最远到 0xe61b0，说明该 size 被截断；
 *   本卡按 census 真实归属收全（这是修正，不是扩张）。
 *
 * ── 跳表分发（入口段）─────────────────────────────────────────────
 *   0xe5810 ubfx r2,r0,#0x8,#0x4     ← K 字段 = opcode 字 bit8..11
 *   0xe5818 cmp r2,#1 / 0xe582c beq 0xe5dd0   ← K==1 单独一支
 *   0xe5830 and r2,r5,#15 / 0xe5834 cmp r2,#6
 *   0xe5838 addls pc,pc,r2,lsl #2    ← 7 臂跳表（0..6）
 *   表项: 0xe583c→0xe6168, 0xe5840→0xe5bdc, 0xe5844→0xe585c, 0xe5848→0xe585c, 0xe584c→0xe5bdc, 0xe5850→0xe585c, 0xe5854→0xe5b94
 *
 * ── open ─────────────────────────────────────────────────────────
 *   1 各臂（0xe585c / 0xe5b94 / 0xe5bdc / 0xe5dd0 / 0xe6168 / 0xe6174）的数值语义未逐条读
 *   2 乘法是否保留整型：DoDiv 有 __divsi3/__aeabi_ldivmod，DoSub/DoAdd 只有 v*；DoMul 属哪族待读本体
 *   3 functions.tsv 对 DoMul 的 size 截断要不要回写（会影响 reachability/call_graph 的按名统计）
 */
/* @0xe5810 ubfx r2, r0, #0x8, #0x4 */
/* @0xe5814 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xe5818 cmp r2, #1 */
/* @0xe581c lsr r7, r0, #16 */
/* @0xe5820 sub sp, sp, #72 */
/* @0xe5824 mov r8, r1 */
/* @0xe5828 uxtb r5, r7 */
/* @0xe582c beq 0xe5dd0 <_Z5DoMuljPhPKhP6VMExec+0x5c0> */
/* @0xe5830 and r2, r5, #15 */
/* @0xe5834 cmp r2, #6 */
/* @0xe5838 addls pc, pc, r2, lsl #2 */
/* @0xe583c b 0xe6168 <_Z5DoMuljPhPKhP6VMExec+0x958> */
/* @0xe5840 b 0xe5bdc <_Z5DoMuljPhPKhP6VMExec+0x3cc> */
/* @0xe5844 b 0xe585c <_Z5DoMuljPhPKhP6VMExec+0x4c> */
/* @0xe5848 b 0xe585c <_Z5DoMuljPhPKhP6VMExec+0x4c> */
/* @0xe584c b 0xe5bdc <_Z5DoMuljPhPKhP6VMExec+0x3cc> */
/* @0xe5850 b 0xe585c <_Z5DoMuljPhPKhP6VMExec+0x4c> */
/* @0xe5854 b 0xe5b94 <_Z5DoMuljPhPKhP6VMExec+0x384> */
/* @0xe5858 b 0xe585c <_Z5DoMuljPhPKhP6VMExec+0x4c> */
/* @0xe585c add r9, r1, #4 */
/* @0xe5860 mov r7, r5 */
/* @0xe5864 asr r2, r7, #4 */
/* @0xe5868 cmp r2, #6 */
/* @0xe586c addls pc, pc, r2, lsl #2 */
/* @0xe5870 b 0xe6174 <_Z5DoMuljPhPKhP6VMExec+0x964> */
/* @0xe5874 b 0xe5b8c <_Z5DoMuljPhPKhP6VMExec+0x37c> */
/* @0xe5878 b 0xe5890 <_Z5DoMuljPhPKhP6VMExec+0x80> */
/* @0xe587c b 0xe5890 <_Z5DoMuljPhPKhP6VMExec+0x80> */
/* @0xe5880 b 0xe5b8c <_Z5DoMuljPhPKhP6VMExec+0x37c> */
/* @0xe5884 b 0xe5890 <_Z5DoMuljPhPKhP6VMExec+0x80> */
/* @0xe5888 b 0xe5b44 <_Z5DoMuljPhPKhP6VMExec+0x334> */
/* @0xe588c b 0xe5890 <_Z5DoMuljPhPKhP6VMExec+0x80> */
/* @0xe5890 add r4, r9, #4 */
/* @0xe5894 cmp r5, #102 */
/* @0xe5898 addls pc, pc, r5, lsl #2 */
/* @0xe589c b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe58a0 b 0xe5b34 <_Z5DoMuljPhPKhP6VMExec+0x324> */
/* @0xe58a4 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe58a8 b 0xe5b34 <_Z5DoMuljPhPKhP6VMExec+0x324> */
/* @0xe58ac b 0xe5b34 <_Z5DoMuljPhPKhP6VMExec+0x324> */
/* @0xe58b0 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe58b4 b 0xe5b24 <_Z5DoMuljPhPKhP6VMExec+0x314> */
/* @0xe58b8 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe58bc b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe58c0 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe58c4 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe58c8 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe58cc b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe58d0 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe58d4 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe58d8 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe58dc b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe58e0 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe58e4 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe58e8 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe58ec b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe58f0 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe58f4 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe58f8 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe58fc b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5900 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5904 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5908 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe590c b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5910 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5914 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5918 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe591c b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5920 b 0xe5b34 <_Z5DoMuljPhPKhP6VMExec+0x324> */
/* @0xe5924 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5928 b 0xe5a3c <_Z5DoMuljPhPKhP6VMExec+0x22c> */
/* @0xe592c b 0xe5b34 <_Z5DoMuljPhPKhP6VMExec+0x324> */
/* @0xe5930 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5934 b 0xe5b24 <_Z5DoMuljPhPKhP6VMExec+0x314> */
/* @0xe5938 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe593c b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5940 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5944 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5948 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe594c b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5950 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5954 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5958 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe595c b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5960 b 0xe5b34 <_Z5DoMuljPhPKhP6VMExec+0x324> */
/* @0xe5964 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5968 b 0xe5b34 <_Z5DoMuljPhPKhP6VMExec+0x324> */
/* @0xe596c b 0xe5b34 <_Z5DoMuljPhPKhP6VMExec+0x324> */
/* @0xe5970 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5974 b 0xe5b24 <_Z5DoMuljPhPKhP6VMExec+0x314> */
/* @0xe5978 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe597c b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5980 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5984 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5988 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe598c b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5990 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5994 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5998 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe599c b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe59a0 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe59a4 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe59a8 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe59ac b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe59b0 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe59b4 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe59b8 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe59bc b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe59c0 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe59c4 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe59c8 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe59cc b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe59d0 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe59d4 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe59d8 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe59dc b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe59e0 b 0xe5b24 <_Z5DoMuljPhPKhP6VMExec+0x314> */
/* @0xe59e4 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe59e8 b 0xe5b24 <_Z5DoMuljPhPKhP6VMExec+0x314> */
/* @0xe59ec b 0xe5b24 <_Z5DoMuljPhPKhP6VMExec+0x314> */
/* @0xe59f0 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe59f4 b 0xe5b24 <_Z5DoMuljPhPKhP6VMExec+0x314> */
/* @0xe59f8 b 0xe5b24 <_Z5DoMuljPhPKhP6VMExec+0x314> */
/* @0xe59fc b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5a00 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5a04 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5a08 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5a0c b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5a10 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5a14 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5a18 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5a1c b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5a20 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5a24 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5a28 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5a2c b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5a30 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0xe5a34 b 0xe5b24 <_Z5DoMuljPhPKhP6VMExec+0x314> */
/* @0xe5a38 b 0xe5a3c <_Z5DoMuljPhPKhP6VMExec+0x22c> */
/* @0xe5a3c sub r4, r4, #4 */
/* @0xe5a40 mov r6, #0 */
/* @0xe5a44 mov r5, r4 */
/* @0xe5a48 cmp r7, #51 */
/* @0xe5a4c addls pc, pc, r7, lsl #2 */
/* @0xe5a50 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5a54 b 0xe5ca8 <_Z5DoMuljPhPKhP6VMExec+0x498> */
/* @0xe5a58 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5a5c b 0xe5c8c <_Z5DoMuljPhPKhP6VMExec+0x47c> */
/* @0xe5a60 b 0xe5d98 <_Z5DoMuljPhPKhP6VMExec+0x588> */
/* @0xe5a64 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5a68 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5a6c b 0xe5cf4 <_Z5DoMuljPhPKhP6VMExec+0x4e4> */
/* @0xe5a70 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5a74 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5a78 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5a7c b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5a80 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5a84 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5a88 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5a8c b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5a90 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5a94 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5a98 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5a9c b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5aa0 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5aa4 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5aa8 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5aac b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5ab0 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5ab4 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5ab8 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5abc b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5ac0 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5ac4 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5ac8 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5acc b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5ad0 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5ad4 b 0xe5cd8 <_Z5DoMuljPhPKhP6VMExec+0x4c8> */
/* @0xe5ad8 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5adc b 0xe5cc0 <_Z5DoMuljPhPKhP6VMExec+0x4b0> */
/* @0xe5ae0 b 0xe5c64 <_Z5DoMuljPhPKhP6VMExec+0x454> */
/* @0xe5ae4 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5ae8 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5aec b 0xe5cf4 <_Z5DoMuljPhPKhP6VMExec+0x4e4> */
/* @0xe5af0 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5af4 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5af8 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5afc b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5b00 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5b04 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5b08 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5b0c b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5b10 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5b14 b 0xe5c44 <_Z5DoMuljPhPKhP6VMExec+0x434> */
/* @0xe5b18 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0xe5b1c b 0xe5c30 <_Z5DoMuljPhPKhP6VMExec+0x420> */
/* @0xe5b20 b 0xe5bf4 <_Z5DoMuljPhPKhP6VMExec+0x3e4> */
/* @0xe5b24 sub r6, r4, #16 */
/* @0xe5b28 mov r5, r6 */
/* @0xe5b2c mov r4, r6 */
/* @0xe5b30 b 0xe5a48 <_Z5DoMuljPhPKhP6VMExec+0x238> */
/* @0xe5b34 sub r4, r4, #8 */
/* @0xe5b38 mov r6, #0 */
/* @0xe5b3c mov r5, r4 */
/* @0xe5b40 b 0xe5a48 <_Z5DoMuljPhPKhP6VMExec+0x238> */
/* @0xe5b44 ldr r2, [r9, #0xc] */
/* @0xe5b48 cmp r2, #13 */
/* @0xe5b4c addls pc, pc, r2, lsl #2 */
/* @0xe5b50 b 0xe6070 <_Z5DoMuljPhPKhP6VMExec+0x860> */
/* @0xe5b54 b 0xe5eec <_Z5DoMuljPhPKhP6VMExec+0x6dc> */
/* @0xe5b58 b 0xe5ee0 <_Z5DoMuljPhPKhP6VMExec+0x6d0> */
/* @0xe5b5c b 0xe6070 <_Z5DoMuljPhPKhP6VMExec+0x860> */
/* @0xe5b60 b 0xe5ec4 <_Z5DoMuljPhPKhP6VMExec+0x6b4> */
/* @0xe5b64 b 0xe6070 <_Z5DoMuljPhPKhP6VMExec+0x860> */
/* @0xe5b68 b 0xe5ea8 <_Z5DoMuljPhPKhP6VMExec+0x698> */
/* @0xe5b6c b 0xe6070 <_Z5DoMuljPhPKhP6VMExec+0x860> */
/* @0xe5b70 b 0xe5e9c <_Z5DoMuljPhPKhP6VMExec+0x68c> */
/* @0xe5b74 b 0xe6070 <_Z5DoMuljPhPKhP6VMExec+0x860> */
/* @0xe5b78 b 0xe6070 <_Z5DoMuljPhPKhP6VMExec+0x860> */
/* @0xe5b7c b 0xe5e8c <_Z5DoMuljPhPKhP6VMExec+0x67c> */
/* @0xe5b80 b 0xe6070 <_Z5DoMuljPhPKhP6VMExec+0x860> */
/* @0xe5b84 b 0xe6070 <_Z5DoMuljPhPKhP6VMExec+0x860> */
/* @0xe5b88 b 0xe5eec <_Z5DoMuljPhPKhP6VMExec+0x6dc> */
/* @0xe5b8c add r4, r9, #8 */
/* @0xe5b90 b 0xe5894 <_Z5DoMuljPhPKhP6VMExec+0x84> */
/* @0xe5b94 ldr r2, [r1, #0xc] */
/* @0xe5b98 cmp r2, #13 */
/* @0xe5b9c addls pc, pc, r2, lsl #2 */
/* @0xe5ba0 b 0xe608c <_Z5DoMuljPhPKhP6VMExec+0x87c> */
/* @0xe5ba4 b 0xe6028 <_Z5DoMuljPhPKhP6VMExec+0x818> */
/* @0xe5ba8 b 0xe601c <_Z5DoMuljPhPKhP6VMExec+0x80c> */
/* @0xe5bac b 0xe5ffc <_Z5DoMuljPhPKhP6VMExec+0x7ec> */
/* @0xe5bb0 b 0xe6050 <_Z5DoMuljPhPKhP6VMExec+0x840> */
/* @0xe5bb4 b 0xe608c <_Z5DoMuljPhPKhP6VMExec+0x87c> */
/* @0xe5bb8 b 0xe6030 <_Z5DoMuljPhPKhP6VMExec+0x820> */
/* @0xe5bbc b 0xe608c <_Z5DoMuljPhPKhP6VMExec+0x87c> */
/* @0xe5bc0 b 0xe5ff0 <_Z5DoMuljPhPKhP6VMExec+0x7e0> */
/* @0xe5bc4 b 0xe608c <_Z5DoMuljPhPKhP6VMExec+0x87c> */
/* @0xe5bc8 b 0xe608c <_Z5DoMuljPhPKhP6VMExec+0x87c> */
/* @0xe5bcc b 0xe5fe0 <_Z5DoMuljPhPKhP6VMExec+0x7d0> */
/* @0xe5bd0 b 0xe608c <_Z5DoMuljPhPKhP6VMExec+0x87c> */
/* @0xe5bd4 b 0xe608c <_Z5DoMuljPhPKhP6VMExec+0x87c> */
/* @0xe5bd8 b 0xe6028 <_Z5DoMuljPhPKhP6VMExec+0x818> */
/* @0xe5bdc add r9, r1, #8 */
/* @0xe5be0 mov r7, r5 */
/* @0xe5be4 b 0xe5864 <_Z5DoMuljPhPKhP6VMExec+0x54> */
/* @0xe5be8 mov r5, #0 */
/* @0xe5bec mov r6, r5 */
/* @0xe5bf0 b 0xe5a48 <_Z5DoMuljPhPKhP6VMExec+0x238> */
/* @0xe5bf4 ldr r1, [r8, #0x4] */
/* @0xe5bf8 mov r12, #10 */
/* @0xe5bfc ldr r2, [r9] */
/* @0xe5c00 ldr r3, [r8] */
/* @0xe5c04 ldr r0, [r9, #0x4] */
/* @0xe5c08 mul r1, r2, r1 */
/* @0xe5c0c mla r1, r3, r0, r1 */
/* @0xe5c10 umull r2, r3, r2, r3 */
/* @0xe5c14 add r3, r1, r3 */
/* @0xe5c18 strd r2, r3, [r5] */
/* @0xe5c1c cmp r6, #0 */
/* @0xe5c20 strne r12, [r6, #0xc] */
/* @0xe5c24 mov r0, r4 */
/* @0xe5c28 add sp, sp, #72 */
/* @0xe5c2c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xe5c30 ldr r3, [r8] */
/* @0xe5c34 mov r12, #10 */
/* @0xe5c38 ldr r2, [r9] */
/* @0xe5c3c asr r1, r3, #31 */
/* @0xe5c40 b 0xe5c04 <_Z5DoMuljPhPKhP6VMExec+0x3f4> */
/* @0xe5c44 ldrd r0, r1, [r9] */
/* @0xe5c48 bl 0x319164 <__floatdidf> */
/* @0xe5c4c vldr d7, [r8] */
/* @0xe5c50 mov r12, #0 */
/* @0xe5c54 vmov d6, r0, r1 */
/* @0xe5c58 vmul.f64 d7, d6, d7 */
/* @0xe5c5c vstr d7, [r5] */
/* @0xe5c60 b 0xe5c1c <_Z5DoMuljPhPKhP6VMExec+0x40c> */
/* @0xe5c64 ldr r3, [r9] */
/* @0xe5c68 mov r12, #10 */
/* @0xe5c6c ldm r8, {r2, r7} */
/* @0xe5c70 asr r1, r3, #31 */
/* @0xe5c74 mul r0, r3, r7 */
/* @0xe5c78 mla r1, r2, r1, r0 */
/* @0xe5c7c umull r2, r3, r2, r3 */
/* @0xe5c80 add r3, r1, r3 */
/* @0xe5c84 strd r2, r3, [r5] */
/* @0xe5c88 b 0xe5c1c <_Z5DoMuljPhPKhP6VMExec+0x40c> */
/* @0xe5c8c vldr s14, [r8] */
/* @0xe5c90 vcvt.f64.s32 d7, s14 */
/* @0xe5c94 vldr d6, [r9] */
/* @0xe5c98 mov r12, #0 */
/* @0xe5c9c vmul.f64 d7, d6, d7 */
/* @0xe5ca0 vstr d7, [r5] */
/* @0xe5ca4 b 0xe5c1c <_Z5DoMuljPhPKhP6VMExec+0x40c> */
/* @0xe5ca8 vldr d6, [r9] */
/* @0xe5cac vldr d7, [r8] */
/* @0xe5cb0 vmul.f64 d7, d6, d7 */
/* @0xe5cb4 mov r12, #0 */
/* @0xe5cb8 vstr d7, [r5] */
/* @0xe5cbc b 0xe5c1c <_Z5DoMuljPhPKhP6VMExec+0x40c> */
/* @0xe5cc0 ldr r3, [r9] */
/* @0xe5cc4 mov r12, #7 */
/* @0xe5cc8 ldr r2, [r8] */
/* @0xe5ccc mul r3, r2, r3 */
/* @0xe5cd0 str r3, [r5] */
/* @0xe5cd4 b 0xe5c1c <_Z5DoMuljPhPKhP6VMExec+0x40c> */
/* @0xe5cd8 vldr s14, [r9] */
/* @0xe5cdc vcvt.f64.s32 d7, s14 */
/* @0xe5ce0 vldr d6, [r8] */
/* @0xe5ce4 mov r12, #0 */
/* @0xe5ce8 vmul.f64 d7, d7, d6 */
/* @0xe5cec vstr d7, [r5] */
/* @0xe5cf0 b 0xe5c1c <_Z5DoMuljPhPKhP6VMExec+0x40c> */
/* @0xe5cf4 ldr r10, [r8] */
/* @0xe5cf8 cmp r10, #0 */
/* @0xe5cfc ldrne r8, [r10] */
/* @0xe5d00 moveq r8, r10 */
/* @0xe5d04 asrs r7, r7, #4 */
/* @0xe5d08 beq 0xe60c0 <_Z5DoMuljPhPKhP6VMExec+0x8b0> */
/* @0xe5d0c cmp r7, #2 */
/* @0xe5d10 beq 0xe5ef4 <_Z5DoMuljPhPKhP6VMExec+0x6e4> */
/* @0xe5d14 ldr r1, [pc, #0x460] */
/* @0xe5d18 mov r0, #1 */
/* @0xe5d1c mov r3, r0 */
/* @0xe5d20 movw r2, #0xb54 */
/* @0xe5d24 add r1, pc, r1 */
/* @0xe5d28 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xe5d2c mov r3, #0 */
/* @0xe5d30 mov r9, r0 */
/* @0xe5d34 strb r3, [r0] */
/* @0xe5d38 mov r0, #12 */
/* @0xe5d3c mov r8, #1 */
/* @0xe5d40 bl 0x27c524 <_Znwj> */
/* @0xe5d44 mov r7, r0 */
/* @0xe5d48 mov r0, r9 */
/* @0xe5d4c bl 0xb6538 <strlen@plt> */
/* @0xe5d50 str r0, [r7, #0x8] */
/* @0xe5d54 mov r0, r9 */
/* @0xe5d58 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xe5d5c stm r7, {r0, r8} */
/* @0xe5d60 mov r0, r9 */
/* @0xe5d64 str r7, [r5] */
/* @0xe5d68 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xe5d6c cmp r10, #0 */
/* @0xe5d70 beq 0xe5d90 <_Z5DoMuljPhPKhP6VMExec+0x580> */
/* @0xe5d74 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xe5d78 ldr r5, [r10, #0x4] */
/* @0xe5d7c sub r5, r5, #1 */
/* @0xe5d80 str r5, [r10, #0x4] */
/* @0xe5d84 cmp r5, #0 */
/* @0xe5d88 beq 0xe60d0 <_Z5DoMuljPhPKhP6VMExec+0x8c0> */
/* @0xe5d8c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xe5d90 mov r12, #1 */
/* @0xe5d94 b 0xe5c1c <_Z5DoMuljPhPKhP6VMExec+0x40c> */
/* @0xe5d98 ldrd r0, r1, [r8] */
/* @0xe5d9c bl 0x319164 <__floatdidf> */
/* @0xe5da0 vldr d7, [r9] */
/* @0xe5da4 mov r12, #0 */
/* @0xe5da8 vmov d5, r0, r1 */
/* @0xe5dac vmul.f64 d7, d7, d5 */
/* @0xe5db0 vstr d7, [r5] */
/* @0xe5db4 b 0xe5c1c <_Z5DoMuljPhPKhP6VMExec+0x40c> */
/* @0xe5db8 ldr r1, [pc, #0x3c0] */
/* @0xe5dbc mov r0, r3 */
/* @0xe5dc0 add r1, pc, r1 */
/* @0xe5dc4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe5dc8 mov r12, #0 */
/* @0xe5dcc b 0xe5c1c <_Z5DoMuljPhPKhP6VMExec+0x40c> */
/* @0xe5dd0 add r6, sp, #24 */
/* @0xe5dd4 mov r2, r1 */
/* @0xe5dd8 and r1, r5, #15 */
/* @0xe5ddc add r7, sp, #8 */
/* @0xe5de0 mov r0, r6 */
/* @0xe5de4 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xe5de8 lsr r1, r5, #4 */
/* @0xe5dec mov r2, r0 */
/* @0xe5df0 mov r0, r7 */
/* @0xe5df4 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xe5df8 ldr r3, [sp, #0x14] */
/* @0xe5dfc mvn r12, #-16777216 */
/* @0xe5e00 and r3, r3, r12 */
/* @0xe5e04 cmp r3, r12 */
/* @0xe5e08 mov r4, r0 */
/* @0xe5e0c beq 0xe6128 <_Z5DoMuljPhPKhP6VMExec+0x918> */
/* @0xe5e10 ldr r3, [sp, #0x24] */
/* @0xe5e14 bic r3, r3, #-16777216 */
/* @0xe5e18 cmp r3, r12 */
/* @0xe5e1c beq 0xe60ac <_Z5DoMuljPhPKhP6VMExec+0x89c> */
/* @0xe5e20 add r5, sp, #40 */
/* @0xe5e24 mov r1, r7 */
/* @0xe5e28 mov r2, #0 */
/* @0xe5e2c mov r3, #0 */
/* @0xe5e30 mov r0, r5 */
/* @0xe5e34 str r12, [sp, #0x34] */
/* @0xe5e38 str r12, [sp, #0x44] */
/* @0xe5e3c mov r12, #0 */
/* @0xe5e40 strd r2, r3, [sp, #40] */
/* @0xe5e44 strd r2, r3, [sp, #56] */
/* @0xe5e48 str r12, [sp, #0x30] */
/* @0xe5e4c str r12, [sp, #0x40] */
/* @0xe5e50 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0xe5e54 cmp r0, #1 */
/* @0xe5e58 beq 0xe613c <_Z5DoMuljPhPKhP6VMExec+0x92c> */
/* @0xe5e5c cmp r0, #0 */
/* @0xe5e60 beq 0xe5f48 <_Z5DoMuljPhPKhP6VMExec+0x738> */
/* @0xe5e64 ldr r3, [sp, #0x34] */
/* @0xe5e68 sub r3, r3, #1 */
/* @0xe5e6c bic r3, r3, #-16777216 */
/* @0xe5e70 bic r3, r3, #3 */
/* @0xe5e74 cmp r3, #0 */
/* @0xe5e78 bne 0xe5c24 <_Z5DoMuljPhPKhP6VMExec+0x414> */
/* @0xe5e7c mov r0, r5 */
/* @0xe5e80 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe5e84 mov r0, r4 */
/* @0xe5e88 b 0xe5c28 <_Z5DoMuljPhPKhP6VMExec+0x418> */
/* @0xe5e8c and r7, r7, #15 */
/* @0xe5e90 orr r7, r7, #48 */
/* @0xe5e94 add r4, r9, #16 */
/* @0xe5e98 b 0xe5894 <_Z5DoMuljPhPKhP6VMExec+0x84> */
/* @0xe5e9c and r7, r7, #15 */
/* @0xe5ea0 orr r7, r7, #32 */
/* @0xe5ea4 b 0xe5e94 <_Z5DoMuljPhPKhP6VMExec+0x684> */
/* @0xe5ea8 ldr r1, [pc, #0x2d4] */
/* @0xe5eac mov r0, r3 */
/* @0xe5eb0 str r3, [sp, #0x4] */
/* @0xe5eb4 add r1, pc, r1 */
/* @0xe5eb8 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe5ebc ldr r3, [sp, #0x4] */
/* @0xe5ec0 b 0xe5e94 <_Z5DoMuljPhPKhP6VMExec+0x684> */
/* @0xe5ec4 ldr r1, [pc, #0x2bc] */
/* @0xe5ec8 mov r0, r3 */
/* @0xe5ecc str r3, [sp, #0x4] */
/* @0xe5ed0 add r1, pc, r1 */
/* @0xe5ed4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe5ed8 ldr r3, [sp, #0x4] */
/* @0xe5edc b 0xe5e94 <_Z5DoMuljPhPKhP6VMExec+0x684> */
/* @0xe5ee0 and r7, r7, #15 */
/* @0xe5ee4 orr r7, r7, #96 */
/* @0xe5ee8 b 0xe5e94 <_Z5DoMuljPhPKhP6VMExec+0x684> */
/* @0xe5eec and r7, r7, #15 */
/* @0xe5ef0 b 0xe5e94 <_Z5DoMuljPhPKhP6VMExec+0x684> */
/* @0xe5ef4 ldr r7, [r9] */
/* @0xe5ef8 mov r0, r8 */
/* @0xe5efc bl 0xb6538 <strlen@plt> */
/* @0xe5f00 ldr r1, [pc, #0x284] */
/* @0xe5f04 mov r3, #1 */
/* @0xe5f08 movw r2, #0xb54 */
/* @0xe5f0c add r1, pc, r1 */
/* @0xe5f10 mul r0, r7, r0 */
/* @0xe5f14 add r0, r0, r3 */
/* @0xe5f18 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xe5f1c cmp r7, #0 */
/* @0xe5f20 mov r3, #0 */
/* @0xe5f24 mov r9, r0 */
/* @0xe5f28 strb r3, [r0] */
/* @0xe5f2c ble 0xe5d38 <_Z5DoMuljPhPKhP6VMExec+0x528> */
/* @0xe5f30 mov r0, r9 */
/* @0xe5f34 mov r1, r8 */
/* @0xe5f38 bl 0xb6628 <strcat@plt> */
/* @0xe5f3c subs r7, r7, #1 */
/* @0xe5f40 bne 0xe5f30 <_Z5DoMuljPhPKhP6VMExec+0x720> */
/* @0xe5f44 b 0xe5d38 <_Z5DoMuljPhPKhP6VMExec+0x528> */
/* @0xe5f48 add r7, sp, #56 */
/* @0xe5f4c mov r1, r6 */
/* @0xe5f50 mov r0, r7 */
/* @0xe5f54 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0xe5f58 cmp r0, #1 */
/* @0xe5f5c beq 0xe6158 <_Z5DoMuljPhPKhP6VMExec+0x948> */
/* @0xe5f60 cmp r0, #0 */
/* @0xe5f64 bne 0xe5e64 <_Z5DoMuljPhPKhP6VMExec+0x654> */
/* @0xe5f68 str r0, [r4, #-0x4] */
/* @0xe5f6c sub r6, r4, #16 */
/* @0xe5f70 vldr d6, [sp, #40] */
/* @0xe5f74 vldr d7, [sp, #56] */
/* @0xe5f78 vmul.f64 d5, d6, d7 */
/* @0xe5f7c ldr r1, [sp, #0x34] */
/* @0xe5f80 sub r1, r1, #1 */
/* @0xe5f84 bic r1, r1, #-16777216 */
/* @0xe5f88 bic r1, r1, #3 */
/* @0xe5f8c cmp r1, #0 */
/* @0xe5f90 vmov r2, r3, d5 */
/* @0xe5f94 vstr s10, [r4, #-16] */
/* @0xe5f98 str r3, [r4, #-0xc] */
/* @0xe5f9c beq 0xe614c <_Z5DoMuljPhPKhP6VMExec+0x93c> */
/* @0xe5fa0 ldr r1, [sp, #0x44] */
/* @0xe5fa4 mov r3, #0 */
/* @0xe5fa8 str r3, [sp, #0x30] */
/* @0xe5fac mov r2, #5 */
/* @0xe5fb0 sub r1, r1, #1 */
/* @0xe5fb4 str r3, [sp, #0x28] */
/* @0xe5fb8 bic r3, r1, #-16777216 */
/* @0xe5fbc str r2, [sp, #0x34] */
/* @0xe5fc0 bic r3, r3, #3 */
/* @0xe5fc4 cmp r3, #0 */
/* @0xe5fc8 movne r0, r6 */
/* @0xe5fcc bne 0xe5c28 <_Z5DoMuljPhPKhP6VMExec+0x418> */
/* @0xe5fd0 mov r0, r7 */
/* @0xe5fd4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe5fd8 mov r0, r6 */
/* @0xe5fdc b 0xe5c28 <_Z5DoMuljPhPKhP6VMExec+0x418> */
/* @0xe5fe0 and r7, r7, #240 */
/* @0xe5fe4 orr r7, r7, #3 */
/* @0xe5fe8 add r9, r8, #16 */
/* @0xe5fec b 0xe5864 <_Z5DoMuljPhPKhP6VMExec+0x54> */
/* @0xe5ff0 and r7, r7, #240 */
/* @0xe5ff4 orr r7, r7, #2 */
/* @0xe5ff8 b 0xe5fe8 <_Z5DoMuljPhPKhP6VMExec+0x7d8> */
/* @0xe5ffc ldr r1, [pc, #0x18c] */
/* @0xe6000 mov r0, r3 */
/* @0xe6004 str r3, [sp, #0x4] */
/* @0xe6008 mov r7, r5 */
/* @0xe600c add r1, pc, r1 */
/* @0xe6010 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe6014 ldr r3, [sp, #0x4] */
/* @0xe6018 b 0xe5fe8 <_Z5DoMuljPhPKhP6VMExec+0x7d8> */
/* @0xe601c and r7, r7, #240 */
/* @0xe6020 orr r7, r7, #6 */
/* @0xe6024 b 0xe5fe8 <_Z5DoMuljPhPKhP6VMExec+0x7d8> */
/* @0xe6028 and r7, r5, #240 */
/* @0xe602c b 0xe5fe8 <_Z5DoMuljPhPKhP6VMExec+0x7d8> */
/* @0xe6030 ldr r1, [pc, #0x15c] */
/* @0xe6034 mov r0, r3 */
/* @0xe6038 str r3, [sp, #0x4] */
/* @0xe603c mov r7, r5 */
/* @0xe6040 add r1, pc, r1 */
/* @0xe6044 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe6048 ldr r3, [sp, #0x4] */
/* @0xe604c b 0xe5fe8 <_Z5DoMuljPhPKhP6VMExec+0x7d8> */
/* @0xe6050 ldr r1, [pc, #0x140] */
/* @0xe6054 mov r0, r3 */
/* @0xe6058 str r3, [sp, #0x4] */
/* @0xe605c mov r7, r5 */
/* @0xe6060 add r1, pc, r1 */
/* @0xe6064 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe6068 ldr r3, [sp, #0x4] */
/* @0xe606c b 0xe5fe8 <_Z5DoMuljPhPKhP6VMExec+0x7d8> */
/* @0xe6070 ldr r1, [pc, #0x124] */
/* @0xe6074 mov r0, r3 */
/* @0xe6078 str r3, [sp, #0x4] */
/* @0xe607c add r1, pc, r1 */
/* @0xe6080 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe6084 ldr r3, [sp, #0x4] */
/* @0xe6088 b 0xe5e94 <_Z5DoMuljPhPKhP6VMExec+0x684> */
/* @0xe608c ldr r1, [pc, #0x10c] */
/* @0xe6090 mov r0, r3 */
/* @0xe6094 str r3, [sp, #0x4] */
/* @0xe6098 mov r7, r5 */
/* @0xe609c add r1, pc, r1 */
/* @0xe60a0 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe60a4 ldr r3, [sp, #0x4] */
/* @0xe60a8 b 0xe5fe8 <_Z5DoMuljPhPKhP6VMExec+0x7d8> */
/* @0xe60ac ldr r0, [pc, #0xf0] */
/* @0xe60b0 add r0, pc, r0 */
/* @0xe60b4 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xe60b8 mov r0, r4 */
/* @0xe60bc b 0xe5c28 <_Z5DoMuljPhPKhP6VMExec+0x418> */
/* @0xe60c0 vldr d7, [r9] */
/* @0xe60c4 vcvt.s32.f64 s11, d7 */
/* @0xe60c8 vmov r7, s11 */
/* @0xe60cc b 0xe5ef8 <_Z5DoMuljPhPKhP6VMExec+0x6e8> */
/* @0xe60d0 ldr r0, [r10] */
/* @0xe60d4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xe60d8 str r5, [r10] */
/* @0xe60dc str r5, [r10, #0x8] */
/* @0xe60e0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xe60e4 ldr r5, [r10, #0x4] */
/* @0xe60e8 sub r5, r5, #1 */
/* @0xe60ec str r5, [r10, #0x4] */
/* @0xe60f0 cmp r5, #0 */
/* @0xe60f4 bne 0xe6118 <_Z5DoMuljPhPKhP6VMExec+0x908> */
/* @0xe60f8 ldr r0, [r10] */
/* @0xe60fc bl 0xcef90 <_Z6YYFreePKv> */
/* @0xe6100 mov r0, r10 */
/* @0xe6104 str r5, [r10] */
/* @0xe6108 str r5, [r10, #0x8] */
/* @0xe610c bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0xe6110 mov r0, r10 */
/* @0xe6114 bl 0x27d1d0 <_ZdlPv> */
/* @0xe6118 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xe611c mov r0, r10 */
/* @0xe6120 bl 0x27d1d0 <_ZdlPv> */
/* @0xe6124 b 0xe5d8c <_Z5DoMuljPhPKhP6VMExec+0x57c> */
/* @0xe6128 ldr r0, [pc, #0x78] */
/* @0xe612c add r0, pc, r0 */
/* @0xe6130 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xe6134 mov r0, r4 */
/* @0xe6138 b 0xe5c28 <_Z5DoMuljPhPKhP6VMExec+0x418> */
/* @0xe613c ldr r0, [pc, #0x68] */
/* @0xe6140 add r0, pc, r0 */
/* @0xe6144 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xe6148 b 0xe5e64 <_Z5DoMuljPhPKhP6VMExec+0x654> */
/* @0xe614c mov r0, r5 */
/* @0xe6150 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe6154 b 0xe5fa0 <_Z5DoMuljPhPKhP6VMExec+0x790> */
/* @0xe6158 ldr r0, [pc, #0x50] */
/* @0xe615c add r0, pc, r0 */
/* @0xe6160 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xe6164 b 0xe5e64 <_Z5DoMuljPhPKhP6VMExec+0x654> */
/* @0xe6168 mov r7, r5 */
/* @0xe616c mov r9, r1 */
/* @0xe6170 b 0xe5864 <_Z5DoMuljPhPKhP6VMExec+0x54> */
/* @0xe6174 mov r4, r9 */
/* @0xe6178 b 0xe5894 <_Z5DoMuljPhPKhP6VMExec+0x84> */
/* @0xe617c eoreq r12, r4, r8, asr r10 */
/* @0xe6180 eoreq lr, r4, r0, asr #15 */
/* @0xe6184 mlaeq r4, r0, r6, lr */
/* @0xe6188 eoreq lr, r4, r0, ror #12 */
/* @0xe618c eoreq r12, r4, r0, ror r8 */
/* @0xe6190 eoreq lr, r4, r8, asr #10 */
/* @0xe6194 eoreq lr, r4, r4, lsl #10 */
/* @0xe6198 .word 0x0024e4d0 */
/* @0xe619c eoreq lr, r4, r12, ror #9 */
/* @0xe61a0 eoreq lr, r4, r12, asr #9 */
/* @0xe61a4 eoreq lr, r4, r8, asr r4 */
/* @0xe61a8 .word 0x0024e3dc */
/* @0xe61ac .word 0x0024d0d4 */
/* @0xe61b0 .word 0x0024d0f8 */
