/* cally 逆向卡：F_InstanceDestroy（原版 libyoyo.so，armv7）
 * @func 0x10b190 0x10b1ec  size 96  24 条（无字面量池；push 6 字 → pop 6 字 → 尾跳，不留帧）
 * 级别: 正文（三个 argc 分支、YYGet* 的取值槽、尾跳实参映射、注册形态全部落锚；open 2 条见文末）
 * 符号: _Z17F_InstanceDestroyR6RValueP9CInstanceS2_iPS_
 *       → void F_InstanceDestroy(RValue& ret, CInstance* self, CInstance* other, int argc, RValue* args)
 *
 * ── 这是什么 ─────────────────────────────────────────────────────────
 *   GML 内建 instance_destroy 的包装器：把「可选的 (id, execute_event)」摊成
 *   DoInstanceDestroy(CInstance* self, CInstance* other, int id, bool hard) 的四个位置参数。
 *   GML 侧语义：instance_destroy([id/对象], [execute_event])。
 *
 * ── 语义草案（逐条落在锚点）──────────────────────────────────────────
 *   void F_InstanceDestroy(RValue& ret, CInstance* self, CInstance* other, int argc, RValue* args) {
 *     if (argc > 1)       DoInstanceDestroy(self, other, YYGetInt32(args,0), YYGetBool(args,1));
 *     else if (argc == 1) DoInstanceDestroy(self, other, YYGetInt32(args,0), true);
 *     else                DoInstanceDestroy(self, other, -1, true);       // argc <= 0（含负数）
 *     // ret 从头到尾既没被读、也没被写
 *   }
 *
 * ── 已证（每条指到指令）───────────────────────────────────────────────
 *   1. 形参落位：0x10b190 cmp r3,#1 说明 argc 在 r3；0x10b194 push {r4,r5,r6,r7,r8,lr}（24 B）；
 *      0x10b1a0 ldr r4,[sp,#0x18] ⇒ 第 5 个形参 args 在 [sp+0x18]，即 this-call 约定
 *      (ret, self, other, argc, args) 的 args。
 *   2. self/other 立刻落到 r5/r6（0x10b198 / 0x10b19c），此后不再从栈上取。
 *   3. argc > 1（0x10b1a4 ble 的另一侧）：0x10b1a8 mov r0,r4 + 0x10b1ac mov r1,#1 + 0x10b1b0 bl YYGetBool
 *      ⇒ hard = YYGetBool(args,1)；0x10b1b8 / 0x10b1bc / 0x10b1c0 bl YYGetInt32 ⇒ id = YYGetInt32(args,0)。
 *      注意取值顺序：先 bool 后 int（源码里 bool 先算），与最终实参顺序无关。
 *   4. argc 恰为 1：0x10b1a4 的 ble 落到 0x10b1dc 时 Z=1 ⇒ movne/mvnne 都不执行，
 *      0x10b1e8 mov r7,r3 把 argc（=1）当 hard=true（省掉 YYGetBool），再尾跳到 0x10b1b8 取 id。
 *   5. argc 为 0 或负：0x10b1dc movne r7,#1（hard=true）、0x10b1e0 mvnne r2,#0（id=-1）、
 *      0x10b1e4 bne 0x10b1c8 直接尾跳 ⇒ 连 YYGetInt32 都不调用。
 *   6. 尾跳：0x10b1d4 pop {r4,r5,r6,r7,r8,lr} + 0x10b1d8 b 0x10b12c ⇒ 本函数不留帧、不做返回处理；
 *      被包装体 DoInstanceDestroy（0x10b12c，size 100）自己建 WithObjIterator 并跑 do/while 销毁循环。
 *   7. id = -1 的含义就是 self：WithObjIterator ctor（0x19d060）里 id==-1 → +0x10=self、状态 -1（只处理 self），
 *      与本仓库 DoInstanceDestroy 卡 §5 一致 ⇒ 缺省形式的 instance_destroy() 就是「销毁当前实例」。
 *   8. 没有 bl 调用者：值 0x10b190 在文件里只出现在 .got 槽 0x3ee1bc（R_ARM_RELATIVE，addend=0x10b190）
 *      与 .dynsym ⇒ 它是通过函数指针表（内建函数注册表）被间接调用的，VM 不直接 bl。
 *      同族包装 YYGML_instance_destroy 在 0x10b1f0（见 DoInstanceDestroy 卡 §8），二者只差取值方式。
 *   9. 两个静态细节：r8 只被 push/pop、从未使用（0x10b194 / 0x10b1d4）；
 *      ret 指针（入口 r0）在 0x10b1a8 就被 mov r0,r4 覆盖 ⇒ 包装器不写返回值，返回 RValue 由调用方（VM 派发层）预置。
 *
 * ── open ────────────────────────────────────────────────────────────
 *   1. 「argc==0 → id=-1」在运行期的观测未做（需要 GML instance_destroy() 实测）；静态只证 -1 会走到
 *      WithObjIterator 的 self 单实例分支。
 *   2. 第 2 参 hard（execute_event）为 false 时 DoDestroy 是否跳过 Destroy 事件，本卡不展开
 *      （属 DoDestroy / DoInstanceDestroy 面）。
 */

/* ---- 取 args、保存 self/other ---- */
/* @0x10b190 cmp r3, #1 */
/* @0x10b194 push {r4, r5, r6, r7, r8, lr} */
/* @0x10b198 mov r5, r1 */
/* @0x10b19c mov r6, r2 */
/* @0x10b1a0 ldr r4, [sp, #0x18] */
/* ---- argc<=1 走缺省档；argc>1 走取值档 ---- */
/* @0x10b1a4 ble 0x10b1dc <_Z17F_InstanceDestroyR6RValueP9CInstanceS2_iPS_+0x4c> */
/* ---- argc>1：hard=YYGetBool(args,1) ---- */
/* @0x10b1a8 mov r0, r4 */
/* @0x10b1ac mov r1, #1 */
/* @0x10b1b0 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x10b1b4 mov r7, r0 */
/* ---- id=YYGetInt32(args,0) ---- */
/* @0x10b1b8 mov r0, r4 */
/* @0x10b1bc mov r1, #0 */
/* @0x10b1c0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x10b1c4 mov r2, r0 */
/* ---- 尾跳 DoInstanceDestroy(self,other,id,hard) ---- */
/* @0x10b1c8 mov r0, r5 */
/* @0x10b1cc mov r1, r6 */
/* @0x10b1d0 mov r3, r7 */
/* @0x10b1d4 pop {r4, r5, r6, r7, r8, lr} */
/* @0x10b1d8 b 0x10b12c <_Z17DoInstanceDestroyP9CInstanceS0_ib> */
/* ---- argc<=1 的缺省：id=-1、hard=true ---- */
/* @0x10b1dc movne r7, #1 */
/* @0x10b1e0 mvnne r2, #0 */
/* @0x10b1e4 bne 0x10b1c8 <_Z17F_InstanceDestroyR6RValueP9CInstanceS2_iPS_+0x38> */
/* ---- argc==1：hard=argc(1)，跳到取 id ---- */
/* @0x10b1e8 mov r7, r3 */
/* @0x10b1ec b 0x10b1b8 <_Z17F_InstanceDestroyR6RValueP9CInstanceS2_iPS_+0x28> */
