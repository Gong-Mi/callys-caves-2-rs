/* libyoyo.so 覆盖卡组 0108
 * 函数 0x16d170..0x16d36c，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x16d170 · CCamera::GetViewMat() · size=60 · insn=15 */
/* @0x16d170 push {r4, r5} */
/* @0x16d174 add r4, r1, #68 */
/* @0x16d178 mov r5, r0 */
/* @0x16d17c mov r12, r0 */
/* @0x16d180 ldm r4!, {r0, r1, r2, r3} */
/* @0x16d184 stm r12!, {r0, r1, r2, r3} */
/* @0x16d188 ldm r4!, {r0, r1, r2, r3} */
/* @0x16d18c stm r12!, {r0, r1, r2, r3} */
/* @0x16d190 ldm r4!, {r0, r1, r2, r3} */
/* @0x16d194 stm r12!, {r0, r1, r2, r3} */
/* @0x16d198 ldm r4, {r0, r1, r2, r3} */
/* @0x16d19c stm r12, {r0, r1, r2, r3} */
/* @0x16d1a0 mov r0, r5 */
/* @0x16d1a4 pop {r4, r5} */
/* @0x16d1a8 bx lr */

/* ── FUNC 0x16d1ac · CCamera::GetViewProjMat() · size=60 · insn=15 */
/* @0x16d1ac push {r4, r5} */
/* @0x16d1b0 add r4, r1, #132 */
/* @0x16d1b4 mov r5, r0 */
/* @0x16d1b8 mov r12, r0 */
/* @0x16d1bc ldm r4!, {r0, r1, r2, r3} */
/* @0x16d1c0 stm r12!, {r0, r1, r2, r3} */
/* @0x16d1c4 ldm r4!, {r0, r1, r2, r3} */
/* @0x16d1c8 stm r12!, {r0, r1, r2, r3} */
/* @0x16d1cc ldm r4!, {r0, r1, r2, r3} */
/* @0x16d1d0 stm r12!, {r0, r1, r2, r3} */
/* @0x16d1d4 ldm r4, {r0, r1, r2, r3} */
/* @0x16d1d8 stm r12, {r0, r1, r2, r3} */
/* @0x16d1dc mov r0, r5 */
/* @0x16d1e0 pop {r4, r5} */
/* @0x16d1e4 bx lr */

/* ── FUNC 0x16d1e8 · CCamera::GetInvProjMat() · size=60 · insn=15 */
/* @0x16d1e8 push {r4, r5} */
/* @0x16d1ec add r4, r1, #196 */
/* @0x16d1f0 mov r5, r0 */
/* @0x16d1f4 mov r12, r0 */
/* @0x16d1f8 ldm r4!, {r0, r1, r2, r3} */
/* @0x16d1fc stm r12!, {r0, r1, r2, r3} */
/* @0x16d200 ldm r4!, {r0, r1, r2, r3} */
/* @0x16d204 stm r12!, {r0, r1, r2, r3} */
/* @0x16d208 ldm r4!, {r0, r1, r2, r3} */
/* @0x16d20c stm r12!, {r0, r1, r2, r3} */
/* @0x16d210 ldm r4, {r0, r1, r2, r3} */
/* @0x16d214 stm r12, {r0, r1, r2, r3} */
/* @0x16d218 mov r0, r5 */
/* @0x16d21c pop {r4, r5} */
/* @0x16d220 bx lr */

/* ── FUNC 0x16d224 · CCamera::GetInvViewMat() · size=60 · insn=15 */
/* @0x16d224 push {r4, r5} */
/* @0x16d228 add r4, r1, #260 */
/* @0x16d22c mov r5, r0 */
/* @0x16d230 mov r12, r0 */
/* @0x16d234 ldm r4!, {r0, r1, r2, r3} */
/* @0x16d238 stm r12!, {r0, r1, r2, r3} */
/* @0x16d23c ldm r4!, {r0, r1, r2, r3} */
/* @0x16d240 stm r12!, {r0, r1, r2, r3} */
/* @0x16d244 ldm r4!, {r0, r1, r2, r3} */
/* @0x16d248 stm r12!, {r0, r1, r2, r3} */
/* @0x16d24c ldm r4, {r0, r1, r2, r3} */
/* @0x16d250 stm r12, {r0, r1, r2, r3} */
/* @0x16d254 mov r0, r5 */
/* @0x16d258 pop {r4, r5} */
/* @0x16d25c bx lr */

/* ── FUNC 0x16d260 · CCamera::GetInvViewProjMat() · size=60 · insn=15 */
/* @0x16d260 push {r4, r5} */
/* @0x16d264 add r4, r1, #324 */
/* @0x16d268 mov r5, r0 */
/* @0x16d26c mov r12, r0 */
/* @0x16d270 ldm r4!, {r0, r1, r2, r3} */
/* @0x16d274 stm r12!, {r0, r1, r2, r3} */
/* @0x16d278 ldm r4!, {r0, r1, r2, r3} */
/* @0x16d27c stm r12!, {r0, r1, r2, r3} */
/* @0x16d280 ldm r4!, {r0, r1, r2, r3} */
/* @0x16d284 stm r12!, {r0, r1, r2, r3} */
/* @0x16d288 ldm r4, {r0, r1, r2, r3} */
/* @0x16d28c stm r12, {r0, r1, r2, r3} */
/* @0x16d290 mov r0, r5 */
/* @0x16d294 pop {r4, r5} */
/* @0x16d298 bx lr */

/* ── FUNC 0x16d29c · CCamera::SetViewX(float) · size=8 · insn=2 */
/* @0x16d29c str r1, [r0, #0x184] */
/* @0x16d2a0 bx lr */

/* ── FUNC 0x16d2a4 · CCamera::GetViewX() · size=8 · insn=2 */
/* @0x16d2a4 ldr r0, [r0, #0x184] */
/* @0x16d2a8 bx lr */

/* ── FUNC 0x16d2ac · CCamera::SetViewY(float) · size=8 · insn=2 */
/* @0x16d2ac str r1, [r0, #0x188] */
/* @0x16d2b0 bx lr */

/* ── FUNC 0x16d2b4 · CCamera::GetViewY() · size=8 · insn=2 */
/* @0x16d2b4 ldr r0, [r0, #0x188] */
/* @0x16d2b8 bx lr */

/* ── FUNC 0x16d2bc · CCamera::SetViewWidth(float) · size=8 · insn=2 */
/* @0x16d2bc str r1, [r0, #0x18c] */
/* @0x16d2c0 bx lr */

/* ── FUNC 0x16d2c4 · CCamera::GetViewWidth() · size=8 · insn=2 */
/* @0x16d2c4 ldr r0, [r0, #0x18c] */
/* @0x16d2c8 bx lr */

/* ── FUNC 0x16d2cc · CCamera::SetViewHeight(float) · size=8 · insn=2 */
/* @0x16d2cc str r1, [r0, #0x190] */
/* @0x16d2d0 bx lr */

/* ── FUNC 0x16d2d4 · CCamera::GetViewHeight() · size=8 · insn=2 */
/* @0x16d2d4 ldr r0, [r0, #0x190] */
/* @0x16d2d8 bx lr */

/* ── FUNC 0x16d2dc · CCamera::SetViewSpeedX(float) · size=8 · insn=2 */
/* @0x16d2dc str r1, [r0, #0x194] */
/* @0x16d2e0 bx lr */

/* ── FUNC 0x16d2e4 · CCamera::GetViewSpeedX() · size=8 · insn=2 */
/* @0x16d2e4 ldr r0, [r0, #0x194] */
/* @0x16d2e8 bx lr */

/* ── FUNC 0x16d2ec · CCamera::SetViewSpeedY(float) · size=8 · insn=2 */
/* @0x16d2ec str r1, [r0, #0x198] */
/* @0x16d2f0 bx lr */

/* ── FUNC 0x16d2f4 · CCamera::GetViewSpeedY() · size=8 · insn=2 */
/* @0x16d2f4 ldr r0, [r0, #0x198] */
/* @0x16d2f8 bx lr */

/* ── FUNC 0x16d2fc · CCamera::SetViewBorderX(float) · size=8 · insn=2 */
/* @0x16d2fc str r1, [r0, #0x19c] */
/* @0x16d300 bx lr */

/* ── FUNC 0x16d304 · CCamera::GetViewBorderX() · size=8 · insn=2 */
/* @0x16d304 ldr r0, [r0, #0x19c] */
/* @0x16d308 bx lr */

/* ── FUNC 0x16d30c · CCamera::SetViewBorderY(float) · size=8 · insn=2 */
/* @0x16d30c str r1, [r0, #0x1a0] */
/* @0x16d310 bx lr */

/* ── FUNC 0x16d314 · CCamera::GetViewBorderY() · size=8 · insn=2 */
/* @0x16d314 ldr r0, [r0, #0x1a0] */
/* @0x16d318 bx lr */

/* ── FUNC 0x16d31c · CCamera::SetViewAngle(float) · size=8 · insn=2 */
/* @0x16d31c str r1, [r0, #0x1a4] */
/* @0x16d320 bx lr */

/* ── FUNC 0x16d324 · CCamera::GetViewAngle() · size=8 · insn=2 */
/* @0x16d324 ldr r0, [r0, #0x1a4] */
/* @0x16d328 bx lr */

/* ── FUNC 0x16d32c · CCamera::SetTargetInstance(int) · size=8 · insn=2 */
/* @0x16d32c str r1, [r0, #0x1a8] */
/* @0x16d330 bx lr */

/* ── FUNC 0x16d334 · CCamera::GetTargetInstance() · size=8 · insn=2 */
/* @0x16d334 ldr r0, [r0, #0x1a8] */
/* @0x16d338 bx lr */

/* ── FUNC 0x16d33c · CCamera::SetBeginScript(int) · size=8 · insn=2 */
/* @0x16d33c str r1, [r0, #0x1ac] */
/* @0x16d340 bx lr */

/* ── FUNC 0x16d344 · CCamera::GetBeginScript() · size=8 · insn=2 */
/* @0x16d344 ldr r0, [r0, #0x1ac] */
/* @0x16d348 bx lr */

/* ── FUNC 0x16d34c · CCamera::SetEndScript(int) · size=8 · insn=2 */
/* @0x16d34c str r1, [r0, #0x1b0] */
/* @0x16d350 bx lr */

/* ── FUNC 0x16d354 · CCamera::GetEndScript() · size=8 · insn=2 */
/* @0x16d354 ldr r0, [r0, #0x1b0] */
/* @0x16d358 bx lr */

/* ── FUNC 0x16d35c · CCamera::SetUpdateScript(int) · size=8 · insn=2 */
/* @0x16d35c str r1, [r0, #0x1b4] */
/* @0x16d360 bx lr */

/* ── FUNC 0x16d364 · CCamera::GetUpdateScript() · size=8 · insn=2 */
/* @0x16d364 ldr r0, [r0, #0x1b4] */
/* @0x16d368 bx lr */

/* ── FUNC 0x16d36c · CCamera::SetViewDirty() · size=12 · insn=3 */
/* @0x16d36c mov r3, #1 */
/* @0x16d370 strb r3, [r0, #0x1b9] */
/* @0x16d374 bx lr */
