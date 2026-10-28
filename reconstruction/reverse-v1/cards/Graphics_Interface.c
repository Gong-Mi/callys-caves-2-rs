/* cally 逆向卡：GL / 文本层接口卡 —— Graphics 的四个状态/矩阵口 + 两个 GR_ 绘制口
 *        （原版 libyoyo.so，ELF32 ARM，stripped）
 *
 * @card  六条入口的**接口面**：实参落位（寄存器/栈）、谁调它/它调谁、读到的全局与字段偏移、
 *        GL 常量、以及三张枚举表（eRenderState / eClearFlags / eBlend+eCmpFunc+eFog+eStencilOp）的原始取值。
 *        范围：
 *          Graphics::SetRenderState(eRenderState, unsigned int)   0x17fd24  1924 B
 *          Graphics::Clear(unsigned int, float, int, eClearFlags) 0x17eec4  1180 B
 *          Graphics::SetTexture(int, void*)                       0x182a28   808 B
 *          Graphics::SetMatrices(float*, float*, float*)          0x17ec90   564 B
 *          GR_Texture_Draw(YYTPageEntry*, 7×float, uint, float)   0x174ee0   808 B
 *          GR_Text_Draw(float, float, P*, int, int)               0x172df8   624 B
 *
 * 级别:  桩（接口级）
 *        · 不贴逐条锚点表（六函数合计 1477 条解码），只对**载重最大的十几条**挂锚点；见文末「锚点」段
 *        · 已钉：入口/大小/帧、每个形参的落位、每一处直接 bl 的目标、每个 `ldr [pc,#imm]`→GOT 槽→
 *          .dynsym 全局名（全部查表得到，不是猜）、每个 `ldrsh/ldrh/ldrb [rX,#imm]` 的位移、
 *          三张跳表的**原始数值**（从 .rodata 0x35db54 直接读出）
 *        · 未钉：全局变量的语义（只证「谁写谁读」与名字）、YYTPageEntry 字段的官方名、eMatrix 的
 *          world/view 归属（见 §四 的推断标注）、ePrimType 的枚举名
 *
 * 身份:  libyoyo.so sha256 = 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 *        4,689,844 B；.text = 0x0b6fd0..0x31bb7c；GOT(DT_PLTGOT) = 0x3f1c58
 *        六函数全是 **ARM**（4 字节对齐、objdump 按 armv7 一次解通，无 Thumb 位）
 *
 * ══ 六函数尺寸表（条数 = scripts/asm_index.py 解码行数，含 literal pool）═════════════
 *   函数                      区间                  size   条数  池字   真指令  池区间
 *   Graphics::SetRenderState  0x17fd24..0x1804a4     1924    481   39      442   0x180228..0x1802c0
 *   Graphics::Clear           0x17eec4..0x17f35c     1180    295   21      274   0x17f30c..0x17f35c
 *   Graphics::SetTexture      0x182a28..0x182d4c      808    202   17      185   0x182d0c..0x182d4c
 *   Graphics::SetMatrices     0x17ec90..0x17eec0      564    141    8      133   0x17eea4..0x17eec0
 *   GR_Texture_Draw           0x174ee0..0x175204      808    202    5      197   0x1751f4..0x175204
 *   GR_Text_Draw              0x172df8..0x173064      624    156    7      149   0x17304c..0x173064
 *
 * ══ 实际读过的地址区间（本卡只对这些地址负责）══════════════════════════════════════
 *   六函数本体：上表六个区间，全函数逐条反汇编一次（asm/index-Graphics_*.tsv 六份）
 *   为定名而读的邻接区间：
 *     0x17fc0c..0x17fd24  ConvertBlend / ConvertComparison / ConvertCull / ConvertFogMode /
 *                         ConvertStencilOp（五张枚举转换器，70 条）
 *     0x17ead0..0x17eb18  Graphics::GetMatrix(eMatrix, float*)（18 条）
 *     0x27aa00..0x27aa44  yyMatrix::Multiply 序言（17 条，只用来看乘积顺序）
 *     0x1631dc..0x16327c  GR_3D_Set_Depth(float)（41 条，用于把 GR_Depth 的来路钉死）
 *   为证调用形而读的调用方片段：
 *     0x1ec720..0x1ec890  CSprite::Draw（取参 + 对 GR_Texture_Draw 的 10 个实参落位）
 *     0x121d70..0x121ddc  F_DrawText（draw_text → GR_Text_Draw 的 5 个实参）
 *     0x121e84..0x121f0c  F_DrawTextExt（draw_text_ext → sep/w 的来历）
 *     0x168c40/0x169840/0x16a060/0x1b3b70  四个 Graphics::Clear 调用点的 flag 实参
 *   数据：
 *     .rodata 0x35db54..0x35dbc0（四张枚举表）、0x34b9a4/0x34b514（"Clear"/"Text"）、
 *     0x34bb30（"Trying to set texture that is also bound as surface - bailing...\n"）
 *     .dynsym 全表（11,167 个具名符号）——本卡所有全局名都来自这里
 *
 * ═══════════════════════════════════════════════════════════════════════════
 * 一、Graphics::SetRenderState 0x17fd24（1924 B / 481 条）
 * ═══════════════════════════════════════════════════════════════════════════
 *
 * ── 形参落位（AAPCS，无栈参）────────────────────────────────────────────
 *   帧 = push {r3,r4,r5,r6,r7,lr} = 24 B，无 sp 调整。
 *     r0 → eRenderState    0x17fd28 `sub r0, r0, #1`（**先减 1**，所以枚举从 1 开始）
 *     r1 → 值（u32）        0x17fd30 `mov r5, r1`；之后全函数只读 r5，不再碰 r1
 *     r4 = GOT 基址（0x17fd34 `add r4, pc, r4`，pc=0x17fd3c，池字 0x00271f1c → 0x3f1c58）
 *
 * ── 分派：32 项跳表，越界即 no-op ────────────────────────────────────────
 *   0x17fd38 `cmp r0, #31` / 0x17fd3c `addls pc, pc, r0, lsl #2`（pc = 0x17fd44）
 *   ⇒ 状态 1..32 走跳表（下标 = 状态-1）；状态 0 与 >32 落到 0x17fd40 的 `b 0x17fdc4` = 直接 pop 返回。
 *   ⇒ 0x17fd40 那一格**不是**表项（表从 0x17fd44 起，到 0x17fdc0 正好 32 项）。
 *
 * ── 状态 → 处理块（左列是枚举值，右列是本函数直接读到的 GL 常量）──────────────
 *   1  0x1802c4  glEnable/glDisable(0x0B71 = GL_DEPTH_TEST)      全局 g_ZEnable（1 B）
 *   2  0x17fdc4  no-op
 *   3  0x1801f4  glShadeModel(0x1D00 = GL_FLAT / 0x1D01 = GL_SMOOTH)；值 1 ⇒ FLAT，其余 ⇒ SMOOTH
 *   4  0x1801d4  glDepthMask(v != 0)
 *   5  0x1801a4  glEnable/glDisable(0x0BC0 = GL_ALPHA_TEST)       全局 g_AlphaTestEnable（1 B）
 *   6  0x180168  glBlendFunc(g_SrcBlend, g_DestBlend)             g_SrcBlend = ConvertBlend(v)
 *   7  0x180128  glBlendFunc(g_SrcBlend, g_DestBlend)             g_DestBlend = ConvertBlend(v)
 *   8  0x1800e0  ConvertCull<0 ⇒ glDisable(0x0B44 = GL_CULL_FACE)；否则 glEnable + glFrontFace(conv)
 *                                                                全局 g_CullMode（u32，原值原样存）
 *   9  0x1800c4  glDepthFunc(ConvertComparison(v))
 *   10 0x180078  glAlphaFunc(0x204 = GL_GREATER, v / 255.0f)      全局 g_AlphaRef（u32，存原值）
 *   11 0x18002c  glAlphaFunc(ConvertComparison(v), g_AlphaRef / 255.0f)
 *   12 0x180024  glEnable/glDisable(0x0BE2 = GL_BLEND)
 *   13 0x17ffc4  glEnable/glDisable(0x0B60 = GL_FOG)；开时再补 glHint(0xC54 = GL_FOG_HINT,
 *                0x1100 = GL_DONT_CARE) + glFogf(0xB62 = GL_FOG_DENSITY, 1.0f)  全局 g_FogState（1 B）
 *   14 0x17fdc4  no-op
 *   15 0x17fec0  glFogfv(0xB66 = GL_FOG_COLOR, float[4])          全局 g_FogCol（16 B）
 *                v 按 u32 拆：R = v&0xff、G = (v>>8)&0xff、B = (v>>16)&0xff，各 ×(1/255)，alpha 恒 1.0f
 *   16 0x17fe88  glFogf(0xB65 = GL_FOG_MODE, ConvertFogMode(v))
 *   17 0x17fe50  glFogf(0xB63 = GL_FOG_START, v)                  全局 g_FogStart（u32，存原值）
 *   18 0x17fe18  glFogf(0xB64 = GL_FOG_END, v)                    全局 g_FogEnd（u32）
 *   19,20        no-op
 *   21 0x17ff3c  glEnable/glDisable(0x0B50 = GL_LIGHTING)         全局 g_LightingEnable（1 B）
 *   22,23        no-op
 *   24 0x17fde8  glColorMask(bit0,bit1,bit2,bit3)                 g_ColourWriteEnable（u32，存原值）
 *                `and r0,r1,#1` / `ubfx r1,r1,#1,#1` / `ubfx r2,r5,#2,#1` / `ubfx r3,r5,#3,#1`
 *   25 0x17fdc8  glEnable/glDisable(0x0B90 = GL_STENCIL_TEST)
 *   26 0x180394  glStencilOp(conv(v), conv(g_StencilZFail), conv(g_StencilPass))  写 g_StencilFail
 *   27 0x180338  同上三参全量重放；写 g_StencilZFail
 *   28 0x1803c8  同上三参全量重放；写 g_StencilPass
 *   29 0x1802f8  glStencilFunc(conv(v), g_StencilRef, g_StencilMask)；写 g_StencilFunc
 *   30 0x180424  glStencilFunc(conv(g_StencilFunc), v, g_StencilMask)；写 g_StencilRef
 *   31 0x17ff6c  glStencilFunc(conv(g_StencilFunc), g_StencilRef, v)；写 g_StencilMask
 *   32 0x17ffac  glStencilMask(v)  ← **不转换，原值直传**
 *   （19/20/22/23/2/14 六格与「状态 0 / >32」一样是空操作；共 6 个死格）
 *
 * ── 每条处理块的公共骨架（三种造型，全部在本函数里能看到）────────────────
 *   (a) 纯 GL：`mov r0,#常量; ldr r3,[r4,#槽]; blx`（state 3/4/9/12/24/25 等）
 *   (b) 先写全局再 GL：`ldr r3,[r4,#槽]; str/strb; ldr r3,[r4,#UsingGL2槽]; ldrb; cmp #0; popeq`
 *       ⇒ **g_UsingGL2 != 0 时跳过 GL 调用，只留全局写**（state 5/10/11/13/15/16/17/18/21）
 *   (c) 先转换再 GL：`bl ConvertBlend|ConvertComparison|ConvertCull|ConvertFogMode|ConvertStencilOp`
 *   ⇒ 所有 GL 调用都是**函数指针**（FuncPtr_glXxx 是 .data 里的 4 B 全局），不是 PLT。
 *
 * ── 它调谁（全函数外部 bl + 函数指针）─────────────────────────────────────
 *   ConvertFogMode         0x17fcc8   ← 0x17feac（state 16）
 *   ConvertComparison      0x17fc3c   ← 0x1800d4（9 深度函数）/0x180050（11 alpha 函数）/
 *                                       0x180314（29 模板函数）/0x180448（30 模板参考值）/
 *                                       0x17ff90（31 模板掩码）
 *   ConvertCull            0x17fc68   ← 0x1800f0（state 8）
 *   ConvertBlend           0x17fc0c   ← 0x180134（6 混合源）/0x180174（7 混合目标）
 *   ConvertStencilOp       0x17fcf8   ← state 26：0x1803b0(v) → b 0x180368(zfail)/0x18037c(pass)
 *                                       state 27：0x18035c(fail)/0x180368(zfail)/0x18037c(pass)
 *                                       state 28：0x1803ec(fail)/0x180400(zfail)/0x18040c(pass)
 *   函数指针（GOT 槽→.data 全局名）：FuncPtr_glEnable 0x3ed730 / glDisable 0x3ed728 / glFogf 0x3ed8f0 /
 *     glFogfv 0x3ed8f4 / glStencilFunc 0x3ed7ac / glStencilMask 0x3ed7b0 / glStencilOp 0x3ed7b4 /
 *     glHint 0x3ed76c / glAlphaFunc 0x3ed874 / glDepthFunc 0x3ed744 / glFrontFace 0x3ed768 /
 *     glBlendFunc 0x3ed720 / glColorMask 0x3ed770 / glDepthMask 0x3ed764 / glShadeModel 0x3ed8bc
 *
 * ── 谁调它（全库 bl 扫描：10 个调用点 / 4 个函数）──────────────────────────
 *   0x1681a8  RenderStateManager::Flush()                        （把攒下的状态全放出去）
 *   0x17ec68  Graphics::SetMatrix(eMatrix, float*)               （同一套路：0x17ec5c mov r0,#8 +
 *                                                                 0x17ec64 ldr r1,[g_CullMode]）
 *   0x17ee30  Graphics::SetMatrices                              （= SetRenderState(8, g_CullMode)）
 *   0x1b2d6c/78/84/90/9c/a8/b4  RenderSurface_AspectAdjusted(...) （7 个连调 = 一次性把视口相关状态全推一遍）
 *   ⇒ GML 层没有任何直连；这条口只有引擎内部 4 个调用者。
 *
 * ═══════════════════════════════════════════════════════════════════════════
 * 二、Graphics::Clear 0x17eec4（1180 B / 295 条）
 * ═══════════════════════════════════════════════════════════════════════════
 *
 * ── 形参落位（4 个，全在寄存器）──────────────────────────────────────────
 *   帧 = push {r4..r11,lr}(36) + sub sp,#268 = 304。
 *     r0 → 颜色（u32 ARGB）      0x17eecc `mov r7, r0`
 *     r1 → 深度（**float**，z）   0x17eee0 `mov r11, r1`
 *     r2 → 模板值（int）          0x17eee4 `mov r8, r2`
 *     r3 → eClearFlags            0x17eec8 `mov r5, r3`
 *   ⇒ mangled `_ZN8Graphics5ClearEjfi11eClearFlags` = Clear(unsigned int, float, int, eClearFlags)，
 *     「float」这一位就是手工清屏时全屏四边形的 z，不是 glClearDepth 的值（见下）。
 *
 * ── 两条完全不同的实现路径，开关是 g_bManualClear（.bss 1 B，GOT 0x3f0488）──
 *   0x17ef14 `ldrb r9,[r3]` / 0x17ef18 `cmp r9,#0` / 0x17ef1c `bne 0x17f064`
 *   g_bManualClear == 0 → **直调路径**（0x17ef20..）；!= 0 → **手绘四边形路径**（0x17f064..0x17f22c）
 *
 * ── 路径 A：直调（g_bManualClear == 0）───────────────────────────────────
 *   1) 0x17ef0c..0x17ef2c：`g_States`（15808 B 的 RenderStateManager 单例）+ SaveStates()
 *   2) 预置五条状态（**这是 RenderStateManager::SetRenderState 0x167e64，不是本卡那条口**）：
 *        (24, 15)  颜色写掩码全开      (12, 0) 关混合      (32, -1) glStencilMask 全 1
 *        (4, 1)    开深度写            (25, 1) 开模板测试
 *   3) 0x17ef80 `ands r9, r5, #1` → bit0：
 *        0x17f284 `uxtb r2, r7` / `ubfx r2, r7, #0x8, #0x8` / `ubfx r2, r7, #0x10, #0x8` /
 *        `lsr r2, r7, #24` → 四个通道各 vcvt.f32 + `vdiv 255.0` → glClearColor(R,G,B,A)
 *        0x17f2bc `str r7, [r2]` 把颜色存进 g_LastColour（.bss 0x4a22b4）
 *        0x17f290 `mov r9, #16384` ⇒ **mask = 0x4000 = GL_COLOR_BUFFER_BIT**
 *   4) 0x17ef88 `tst r5, #2` → bit1：
 *        0x17f258 `mov r0, #1065353216`(=1.0f) → glClearDepthf(1.0f)
 *        0x17f270 `mov r0, r8` → **glClearStencil(arg2)**
 *        0x17f25c `orr r9, r9, #1280` ⇒ **mask |= 0x500 = GL_DEPTH_BUFFER_BIT|GL_STENCIL_BUFFER_BIT**
 *   5) 0x17ef90：RenderStateManager::Flush()；GraphicsPerf::Push(0xFF808080, "Clear")（串 0x34b9a4）
 *   6) 0x17efac..0x17f020：拿 old_view_port_x/y/w/h（.bss 0x4a2148..0x4a2150）与 g_CurrFBOWidth /
 *      g_CurrFBOHeight（.bss 0x3f289c / 0x3f2898）比四对角，选两条出口之一：
 *        一致 → 0x17f024：glDisable(0xC11 = GL_SCISSOR_TEST) → **glClear(mask)** → glEnable(GL_SCISSOR_TEST)
 *        不一致 → 0x17f230：直接 glClear(mask)（不动 scissor）
 *      （比较式：w==FBOW？→ 再比 h==FBOH？/ FBOW==FBOH？/ w==FBOH？，四条分支全在 0x17efec..0x17f020）
 *   7) 0x17f244：GraphicsPerf::Pop()；RenderStateManager::RestoreStates()；0x17f214 收尾把 g_col 计数 +1
 *
 * ── 路径 B：手绘（g_bManualClear != 0）───────────────────────────────────
 *   1) 0x17f064..0x17f090：GetMatrix(2, sp+8) / GetMatrix(0, sp+72) / GetMatrix(1, sp+136) 存三份现场
 *   2) SaveStates()；当前 shader 存到 [sp+4]；Shader_Set(NULL) + FlushShader()
 *   3) 预置七条状态（同样是 RSM 那条）：(1,0) 关深度测试 (12,0) 关混合 (5,0) 关 alpha 测试
 *      (21,0) 关光照 (8,0) 不剔除 (24, bit0 置则 15 否则 0) 颜色掩码 (4, bit1 置则 1 否则 0) 深度写
 *   4) 0x17f13c..0x17f188：在 sp+0xc8 拼**单位 4×4**（12 个 0 + 4 个对角 1.0f，0x3f800000）
 *      0x17f18c `bl SetMatrices(sp+0xc8, sp+0xc8, sp+0xc8)` ⇒ 世界/视图/投影全等
 *   5) 0x17f190..0x17f1a0：`AllocVerts(5, NULL, 16, 4)` —— **ePrimType 5、无纹理、stride 16、4 顶点**
 *   6) 顶点全屏：x/y ∈ {-1.0f, +1.0f}（0xbf800000 / 0x3f800000），顺序 (-1,-1) (-1,+1) (+1,-1) (+1,+1)
 *      z = arg1（浮点原值，四个顶点同一个 z），颜色 = arg0（原值）
 *   7) Flush()；RestoreStates()；SetMatrices(三份现场)；Shader_Set(原 shader) + FlushShader()；g_col++
 *
 * ── 它调谁 / 谁调它 ─────────────────────────────────────────────────────
 *   调：Graphics::Flush 0x1852ec、GraphicsPerf::Push 0x17b8f0 / Pop 0x17bb10、
 *       RenderStateManager::SaveStates 0x167fcc / Flush 0x168134 / RestoreStates 0x168050、
 *       RenderStateManager::SetRenderState 0x167e64（×12）、Graphics::GetMatrix 0x17ead0（×3）、
 *       Graphics::SetMatrices 0x17ec90（×2）、Graphics::AllocVerts 0x185418、Shader_Set 0x1e2024、
 *       FlushShader 0x1e1520；函数指针 glClear/glClearColor/glClearDepthf/glClearStencil/
 *       glEnable/glDisable（四族都在 .data 的 FuncPtr_* 全局里：0x479c90/0x479bf4/0x479bf0/0x479bec/
 *       0x479c74/0x479c80）
 *   谁调（4 个）：GR_D3D_Reset 0x168c50（flag=7）、GR_D3D_Init 0x169854（flag=7）、
 *       GR_Draw_Clear 0x16a070（flag=7）、DrawTheRoom 0x1b3b94（flag=6；若 [rect+0x20] 非 0 则 6|1=7
 *       并把颜色 alpha 字节 or 成 0xFF）
 *   ⇒ 引擎自己只走 6 / 7。**7 = 一位都没少地清，6 = 只清深度+模板、保颜色**（背景已经画过了）。
 *
 * ═══════════════════════════════════════════════════════════════════════════
 * 三、Graphics::SetTexture 0x182a28（808 B / 202 条）
 * ═══════════════════════════════════════════════════════════════════════════
 *
 * ── 形参落位（2 个）────────────────────────────────────────────────────
 *   帧 = push {r4,r5,r6,r7,r8,lr} = 24。
 *     r0 → int stage（纹理单元号）  0x182a2c `mov r7, r0`
 *     r1 → void* texture           0x182a34 `mov r5, r1`（当 Texture* 用，读 +0x14）
 *
 * ── 三级分派：先按 g_UsingGL2 选通道，再按 stage 上限闸 ────────────────────
 *   0x182a48 `cmp r3,#0` / `bne 0x182b18`：
 *     g_UsingGL2 == 0  → **单纹理通道**（0x182a50..0x182b14，恒用下标 0）
 *     g_UsingGL2 == 1  → **多单元通道**（0x182b18..）
 *     g_UsingGL2 其它  → 0x182b1c `popne` 直接返回（两个通道都不要）
 *   多单元通道先过：0x182b20 `cmp r7,#7` / `pop  hi` ⇒ **stage > 7 直接返回**（0..7 共 8 单元）
 *
 * ── 单纹理通道（g_UsingGL2 == 0）────────────────────────────────────────
 *   1) 0x182a50..0x182a60：`_pLastTexture[0]`（32 B 的 8 槽数组，.bss 0x4a2f28）与 texture 相等 ⇒ 0x182c38
 *      （相等时还要再查一次 `texture->+0x14 == -1` 的哨兵：+0x14 == -1 且 g_GraphicsInitialised 非 0
 *       才回落到 0x182a80 重新绑，否则返回）
 *   2) g_GraphicsInitialised == 0 ⇒ 返回（0x182a6c `ldrb` / 0x182a74 `popeq`）
 *   3) texture == NULL ⇒ 0x182c74：**glDisable(0xDE1 = GL_TEXTURE_2D)**；_pLastTexture[0] = NULL
 *   4) 非空：`isTextureBoundAsRenderTarget(texture)`（0x180884）非 0 ⇒
 *        dbg_csol 打印 "Trying to set texture that is also bound as surface - bailing...\n"（0x34bb30）
 *        然后返回（**一个 GL 调用都不发**）
 *   5) `GetSamplerState(stage, 9)`（RSM 0x167fa0，eSamplerState = **9**）→
 *      `_CreateTextureIfInvalid(texture, true, 9 号 sampler 值)`（0x182500）
 *   6) **glEnable(0xDE1 = GL_TEXTURE_2D)**
 *   7) `_pLastActualTexture`（4 B，.bss 0x4a2f24）== texture ⇒ 跳过绑定
 *      否则：写 _pLastActualTexture = texture；`++g_numTextureSwaps`（.bss 0x4a2100）；
 *      **glBindTexture(0xDE1, texture->+0x14)**
 *   8) _pLastTexture[0] = texture；尾调用 `_SetCurrentTextureSettings()`（0x180b28，940 B）
 *
 * ── 多单元通道（g_UsingGL2 == 1）────────────────────────────────────────
 *   1) `g_ForceTextureSet`（1 B，.bss 0x4a2f08）为 0 时，`_pLastTexture[stage] == texture` ⇒ 走哨兵检查后返回
 *   2) g_GraphicsInitialised == 0 ⇒ 返回
 *   3) 0x182b6c：`g_CurrActiveTexture`（u32，.bss 0x4a2f20）!= stage 时：
 *        写 g_CurrActiveTexture = stage
 *        0x182b7c `add r0, r7, #33792` + 0x182b84 `add r0, r0, #192` ⇒ **r0 = 0x84C0 + stage**
 *        → **glActiveTexture(GL_TEXTURE0 + stage)**
 *      （即：单元切换走缓存，同一 stage 连绑不发 glActiveTexture）
 *   4) texture == NULL ⇒ 0x182c94：改绑 `g_pBlankTexture`（.bss 0x4a2f54，Texture**），
 *      `_CreateTextureIfInvalid(*g_pBlankTexture, true, -1)`
 *   5) 非空：同单纹理通道的 render-target 检查 + GetSamplerState(stage, 9) + _CreateTextureIfInvalid
 *   6) `++g_numTextureSwaps`；**glBindTexture(0xDE1, texture->+0x14)**
 *   7) `_pLastTexture[currentStage] = texture`（0x182c08 `str r5,[r3,r2,lsl #2]`，r2 = g_CurrActiveTexture）
 *      尾调用 `_SetCurrentTextureSettings()`
 *
 * ── 绑定的三个数值常量 ─────────────────────────────────────────────────
 *   GL 目标       0x0DE1 = GL_TEXTURE_2D（movw r0,#0xde1 共四处：0x182ab8 / 0x182bd8 / 0x182c78 / 0x182cbc）
 *   单元基址      0x84C0 = GL_TEXTURE0（add 33792 + add 192：0x182b7c / 0x182b84）
 *   采样器槽号    9（GetSamplerState 的第二参：0x182a98 / 0x182bb4）
 *   纹理 ID 字段  Texture + 0x14（u32，glBindTexture 的第二参；-1 = "没有 GL id" 哨兵）
 *
 * ── 谁调它（12 个调用点 / 7 个函数）──────────────────────────────────────
 *   0x168b00 GR_D3D_Settings_Init · 0x17b36c/0x17b400 GraphicsPerf::{Begin,End}DebugDraw ·
 *   0x182d80 ResetCurrentTextures（0x182d50）· 0x185348 Graphics::Flush（0x1852ec）·
 *   0x185780 Graphics::DrawArrayFromVB · 0x185cc4/0x185e6c/0x185ff0/0x186170/0x18630c/0x186338
 *   GraphicsRecorder::Draw（0x185a24，**6 处**，说明录制器按批切换纹理）
 *
 * ═══════════════════════════════════════════════════════════════════════════
 * 四、Graphics::SetMatrices 0x17ec90（564 B / 141 条）
 * ═══════════════════════════════════════════════════════════════════════════
 *
 * ── 形参落位（3 个 float*）──────────────────────────────────────────────
 *   帧 = push {r3..r11,lr} = 40。
 *     r0 → p0  0x17ec94 `mov r9, r0`
 *     r1 → p1  0x17ec9c `mov r7, r1`
 *     r2 → p2  0x17eca4 `mov r5, r2`
 *   三者都允许 NULL（NULL = 该矩阵不动）。
 *
 * ── 落槽顺序是**错位**的（本卡最容易写错的一条）──────────────────────────
 *   0x17ecc0 `ldr r3,[pc,#0x1e4]` → GOT 0x3f047c → **m_CurrentMatrix**（.bss 0x4a2170，320 B）=
 *   **5 个 4×4 float 矩阵**（64 B×5 = 320 B；Graphics::GetMatrix 0x17ead0 用 `base + idx*0x40` 取第 idx 个）
 *     m_CurrentMatrix + 0x00 ← p1        （0x17ecd0..0x17ed04：16 个 float 的 ldm/stm 拷贝）
 *     m_CurrentMatrix + 0x40 ← p2        （0x17ed10..0x17ed40）
 *     m_CurrentMatrix + 0x80 ← p0        （0x17ed4c..0x17ed7c）
 *     m_CurrentMatrix + 0xC0 ← p0 × p1   （0x17ed90 `bl yyMatrix::Multiply(dst=+0xC0, a=+0x80, b=+0x00)`）
 *     m_CurrentMatrix + 0x100 ← (+0xC0) × p2（0x17eda0 `bl yyMatrix::Multiply(dst=+0x100, a=+0xC0, b=+0x40)`）
 *   ⇒ **形参序 (p0,p1,p2) 与槽序 (slot0,slot1,slot2) 是置换**：slot0=p1、slot1=p2、slot2=p0。
 *     yyMatrix::Multiply(dst,A,B) 的方向：0x27aa00 首句取 A[1]、0x27aa08 取 B[4] 后相乘，即行主序 A×B。
 *
 * ── 装到 GL ────────────────────────────────────────────────────────────
 *   1) 0x17ecb0 `ldrb r6,[r3]` = g_GraphicsInitialised；为 0 直接 pop（**初始化前不碰 GL**）
 *   2) 0x17ecbc `bl Graphics::Flush()`（先冲刷当前批）
 *   3) 0x17edac 读 g_UsingGL2（.data 0x3f26dc）：
 *        **== 0** → 立即模式：`mov r0,#5888`(=0x1700 = GL_MODELVIEW) + glLoadMatrixf(+0xC0)；
 *                   p2 != NULL 时再 `movw r0,#0x1701`(=GL_PROJECTION) + glLoadMatrixf(+0x40)
 *        **!= 0** → 跳过上面四步，直接去 0x17ee9c → GR_3D_Light_Process()
 *   4) 0x17ee18：p2 != NULL 时 `mov r0,#8` → **Graphics::SetRenderState(8, g_CullMode)**
 *      （0x17ee24 的 8 就是 §一 的「剔除模式」；换投影会翻绕序，所以重放一次）
 *   5) 0x17ee34：`cmp g_UsingGL2, #1`，只有 == 1 才继续：取 g_ActiveUserShader（.bss 0x544c80），
 *      非空则尾调用 `Shader_Set_Uniform_Matrix_N(*(shader+0x6c), 5, m_CurrentMatrix + 0x00)`
 *      （uniform 号 **5**，传的是 slot0 = p1）
 *
 * ── 槽位语义（p2 = 投影来自指令；world/view 的归属是推断）────────────────
 *   已证：+0xC0 进 GL_MODELVIEW、+0x40（= p2）进 GL_PROJECTION、+0xC0 = p0×p1。
 *   推断（依据是行主序 v·M 下 MODELVIEW 必须是 world×view）：p0 = world、p1 = view、p2 = projection。
 *   连带：eMatrix 0 = slot0 = view、eMatrix 1 = slot1 = projection、eMatrix 2 = slot2 = world。
 *   交叉验证：Clear 的路径 B 存 GetMatrix(2)/GetMatrix(0)/GetMatrix(1) 再按同序 SetMatrices 还原，
 *   在「slot0=p1, slot1=p2, slot2=p0」这条置换下**恰好原样回填**——两种独立证据互相对账。
 *
 * ── 谁调它（6 个调用点 / 4 个函数）──────────────────────────────────────
 *   0x169610/0x1696f8 GR_D3D_Set_View_Area（0x169408，两处 = 换视口时重算投影/视图）
 *   0x16d4e0 CCamera::ApplyMatrices（0x16d3bc）
 *   0x17ea40 Graphics::SurfaceCopy（0x17e850，离屏拷贝时临时换矩阵）
 *   0x17f18c/0x17f204 Graphics::Clear（路径 B 的单位矩阵 / 现场还原）
 *
 * ═══════════════════════════════════════════════════════════════════════════
 * 五、GR_Texture_Draw 0x174ee0（808 B / 202 条）—— 10 形参，6 顶点
 * ═══════════════════════════════════════════════════════════════════════════
 *
 * ── 实参落位（10 个 = 4 寄存器 + 6 栈字）──────────────────────────────────
 *   帧 = push {r3,r4,r5,r6,r7,r8,r9,r10,r11,lr}(40) + vpush {d8,d9,d10}(24) = 64 = 0x40。
 *     r0            → YYTPageEntry* page   0x174ee8 `subs r5, r0, #0`（为 0 直接返回 0）
 *     r1  float     → 原点 x（origin）     0x174eec `vmov s20, r1`
 *     r2  float     → 原点 y               0x174ef0 `vmov s19, r2`
 *     r3  float     → **屏幕 x**           0x174ef4 `vmov s16, r3`（最后 vadd 到四角 x 上）
 *     [sp+0x40] float → **屏幕 y**         0x175044 `vldr s14,[sp,#64]`（vadd 到四角 y 上）
 *     [sp+0x44] float → x 缩放             0x174f44 `vldr s13,[sp,#68]`
 *     [sp+0x48] float → y 缩放             0x174f3c `vldr s14,[sp,#72]`
 *     [sp+0x4c] float → **角度（弧度）**    0x17515c `ldr r0,[sp,#0x4c]` → sinf/cosf
 *     [sp+0x50] u32   → 颜色               0x174f40 `ldr r1,[sp,#0x50]`
 *     [sp+0x54] float → alpha              0x174f10 `vldr s13,[sp,#84]`（×255 → 高字节）
 *   ⇒ mangled `P12YYTPageEntry f f f f f f f j f`：page, (原点x, 原点y, x, y, xs, ys, 角度), 颜色, alpha。
 *     注意**原点在前、位置在后**——这是字节决定的，不是抄头文件。
 *   ⇒ 调用方对照（CSprite::Draw 0x1ec720 的 0x1ec804..0x1ec848）：
 *       r1 = (float)CSprite+0x24（ox）、r2 = (float)CSprite+0x28（oy）、r3 = x、[sp] = y、
 *       [sp+4] = xs、[sp+8] = ys、[sp+12] = 角度、[sp+0x10] = colour、[sp+0x14] = alpha；
 *       角度在这条链上由 `×π`(0x40490fdb) 再 `/180.0`(0x43340000) 换成弧度 ⇒ **第 8 参是弧度**。
 *
 * ── 入口闸（三个）──────────────────────────────────────────────────────
 *   0x174ef8 page == NULL ⇒ 返回 0
 *   0x174efc `ldrsh r0,[r5,#20]` → `GR_Texture_Exists(page->+0x14)`（0x173e2c）；返回 0 ⇒ 返回 0
 *   0x174f08 两个早退都在 0x17514c：`vpop {d8,d9,d10}; mov r7,#0; mov r0,r7; pop`（**返回 0**）
 *
 * ── 组成的六个顶点（stride 24 = x,y,z,colour,u,v；ePrimType 4、6 顶点 = 两个三角形，
 *    枚举名未证见 open）──
 *   0x175020 `bl Graphics::AllocVerts(4, tex, 24, 6)`   ← 类型 4、纹理、24 B/顶点、6 顶点
 *   四角（A = 左，B = 右，T = 上，Bo = 下）：
 *     v0=(A,T) v1=(B,T) v2=(B,Bo) | v3=(B,Bo) v4=(A,Bo) v5=(A,T)
 *     （v2/v3 与 v0/v5 是同坐标的**两份拷贝**：两个独立三角形共用对角 (B,Bo)-(A,T)）
 *   几何（s18 = A，s21 = B，s17 = T，s20 = Bo）：
 *     A  = x + ( −xs·(origx − page[+0x08]) )
 *     B  = A + xs·page[+0x0c]
 *     T  = y + ( −ys·(origy − page[+0x0a]) )
 *     Bo = T + ys·page[+0x0e]
 *     ⇒ page[+0x08]/[+0x0a] 是「原点位移」（int16，签名 `ldrsh`），page[+0x0c]/[+0x0e] 是宽高
 *       （u16，`ldrh`，**为 0 时被就地改写成 1** 再回写：0x174fb4 `moveq r3,#1` / 0x174fbc `strheq r3,[r5,#12]`）
 *   UV：u = page[+0x00]·scaleU、u1 = (page[+0x00]+page[+0x04])·scaleU；v 同理用 [+0x02]/[+0x06]；
 *       scaleU = 运行期纹理对象 +0x08、scaleV = +0x0c（= 1/宽、1/高）
 *   z：**六个顶点全写同一个全局 GR_Depth**（0x4859ac，0x17509c 取槽 → 0x1750b4..0x1750cc 写
 *       +0x68/+0x38/+0x50/+0x20/+0x08/+0x80）——本函数**不读形参、不做深度运算**
 *   colour：高字节 = clamp(int(alpha·255.0), 0, 255)<<24，低 24 位 = arg8 & 0x00FFFFFF
 *       （0x174f0c 的 255.0f 常量、0x174f20 `cmp r6,#255`、0x174f2c/30 的夹取、0x174f50 `bic r2,r1,#-16777216`）
 *
 * ── 顶点标记（g_MarkVerts）：不是颜色，是**顶点打标** ─────────────────────
 *   0x174f48/0x174f58 读 g_MarkVerts（1 B，.bss 0x483678）；非 0 时：
 *     先把基色里 0x00010000 与 0x00000001 两位清掉（`bicne r6,#65536` / `bicne r6,#1`），
 *     再派生 r9 = c|0x00010000、r11 = c|0x1、r10 = c|0x00010001，
 *     逐个顶点写回：v0=c、v1=c|1、v2=c|0x10000、v3=c|0x10000、v4=c|0x10001、v5=c
 *   ⇒ 打标时六个顶点的颜色字段两两不同，**是按「哪个角」编码**；g_MarkVerts == 0 时六顶点同色。
 *
 * ── 旋转分支（真·慢路径）────────────────────────────────────────────────
 *   0x175028..0x17503c：`vabs s14, angle` 与 0.001f（0x3a83126f，池 0x1751f8）比，`bpl 0x17515c`
 *   ⇒ |angle| >= 0.001 才有旋转：0x175160/0x17516c 两次 sinf/cosf（PLT 0xb6580/0xb658c），
 *     把 12 个角坐标整体重算后**跳回 0x175084** 再补 colour/u/v。
 *   ⇒ 轴对齐路径（|angle| < 0.001）完全不碰三角函数。
 *
 * ── YYTPageEntry 字段（本函数直接读到的位移，无一推断位移）──────────────
 *   +0x00 int16 u0      +0x02 int16 v0      +0x04 int16 宽(uv)   +0x06 int16 高(uv)
 *   +0x08 int16 原点 x  +0x0a int16 原点 y   +0x0c uint16 宽     +0x0e uint16 高
 *   +0x14 int16 纹理页号（→ GR_Texture_Exists / tex_textures 表下标）
 *   纹理对象（tex_textures.pages[页号]，tex_textures 在 .bss 0x48ffec，表基在 +0x4）：
 *     +0x00 = GL 纹理句柄（进 AllocVerts 第 2 参）、+0x08 = 1/宽、+0x0c = 1/高
 *
 * ── 谁调它（6 个调用点 / 6 个函数，全部在绘制链上）──────────────────────
 *   0x1ec848 CSprite::Draw(int,float,float,float,float,float,uint,float)   ← 实例/层项主通道
 *   0x1ece98 CSprite::DrawStretched(...)                                  ← draw_sprite_stretched_ext
 *   0xc2030  CBackground::Draw(...)      0xc212c CBackground::DrawStretched(...)
 *   0x17671c GR_Texture_Draw_Tiled（平铺时逐格复用自己的口）
 *   0x1a5188 DrawParticles(RParticleSystem*, int,int,int)                 ← 粒子
 *   ⇒ 与已知的 draw 链（DrawTheRoom / DoSlowDrawRoom / DrawInstancesOnly / ParticlesOnly）对上：
 *     那四条流最后都收敛到 CSprite::Draw / DrawParticles，再由这里出 6 个顶点。
 *
 * ═══════════════════════════════════════════════════════════════════════════
 * 六、GR_Text_Draw 0x172df8（624 B / 156 条）—— 文本层的唯一出口
 * ═══════════════════════════════════════════════════════════════════════════
 *
 * ── 形参落位（5 个）────────────────────────────────────────────────────
 *   帧 = push {r4,r5,r6,r7,r8,lr}(24) + vpush {d8,d9,d10}(24) + sub sp,#24 = 72 = 0x48。
 *     r0 float → x        0x172e18 `vmov s19, r0`
 *     r1 float → y        0x172e04 `vmov s16, r1`
 *     r2 P*    → 文本       0x172e10 `mov r6, r2`（UTF-16 串，后面按 uint16 读）
 *     r3 int   → **行间距 sep**  0x172e28 `mov r4, r3`；`cmp r4,#0; blt` ⇒ 负数走「用字体行高」分支
 *     [sp+0x48] int → **换行宽度 w**  0x172e0c `ldr r5,[sp,#0x48]`（进 Split_TextBlock 第 2 参）
 *   ⇒ 由两个 GML 内建对账（不是猜）：
 *       F_DrawText 0x121dc8：GR_Text_Draw(x, y, str, **-1**, **-1**) —— draw_text 不给 sep/w
 *       F_DrawTextExt 0x121efc：GR_Text_Draw(x, y, str, YYGetInt32(3)=sep, [sp]=YYGetInt32(4)=w)
 *     即 mangled `ffPKcii` 的后两个 int 就是 draw_text_ext 的 sep / w。
 *
 * ── 主流程 ─────────────────────────────────────────────────────────────
 *   1) `GraphicsPerf::Push(0x00FF0000, "Text")`（0x172e3c；串 0x34b514 = "Text"，
 *      r0 = 0x00FF0000 由 0x172e1c/0x172e20 的 movw/movt 拼出）→ 成对 Pop 在 0x172ee8
 *   2) `SetFont()`（0x1724e4，无参）
 *   3) `Split_TextBlock(text, w, &TStringList)`（0x172560）—— **换行在这里做**；
 *      TStringList 在栈上 sp+8（3 个字：0x8/0xc/0x10），行数读 [sp+0x10]
 *   4) sep < 0 ⇒ `CFontGM::TextHeight(font)`（0x173040）作为行距（**每次调用重算**）
 *   5) 垂直对齐：读 Graphics_Text::valign（.bss 0x48ffcc）
 *        == 1 ⇒ y -= (行数·行距)/2      （0x173010 的 mul/asr #1 再 vsub）
 *        == 2 ⇒ y -= 行数·行距           （0x172e80 的 mul 再 vsub）
 *   6) 逐行循环（0x172ea8..0x172ee4）：空行（`ldrh r3,[r5]` == 0）只推 y 不画；
 *      每行 x 偏移看 Graphics_Text::halign（.bss 0x48ffd0）：
 *        == 1 ⇒ x -= TextWidth(line)/2 ；== 2 ⇒ x -= TextWidth(line)；其它 ⇒ 0
 *      （TextWidth 0xf8b04，两处：0x172fd0 / 0x172ffc）
 *   7) 每行落笔：`CFontGM::Draw_String(font, x + 偏移, y, line, GR_Draw_Get_Color(), GR_Draw_Get_Alpha())`
 *        0x172fa8 `bl 0xf7eec`，实参 r0 = thefont、r1 = s18、r2 = s15、r3 = 行指针、
 *        [sp] = 颜色（GR_Draw_Get_Color，0x169ecc）、[sp+4] = alpha（GR_Draw_Get_Alpha，0x169f1c）
 *      ⇒ **文本颜色/透明度不是形参，是每行现取的两个全局**
 *   8) 收尾：Pop()；按链表把 TStringList 的节点逐个 `MemoryManager::Free`（0x27c2d0，两处）
 *
 * ── 它调谁 / 谁调它 ───────────────────────────────────────────────────
 *   调：GraphicsPerf::Push 0x17b8f0 / Pop 0x17bb10、SetFont 0x1724e4、Split_TextBlock 0x172560、
 *       CFontGM::TextHeight 0xf93a4、CFontGM::TextWidth 0xf8b04、CFontGM::Draw_String 0xf7eec、
 *       GR_Draw_Get_Color 0x169ecc、GR_Draw_Get_Alpha 0x169f1c、MemoryManager::Free 0x27c2d0
 *   用到的全局（名字全来自 .dynsym）：
 *       Graphics_Text::thefont (.bss 0x48ffd4)、::halign (0x48ffd0)、::valign (0x48ffcc)
 *   谁调（10 个调用点 / 8 个函数）：F_DrawText、F_DrawTextExt、YYGML_draw_text(0x122414)、
 *       F_DrawHighscore（×2）、F_ActionDrawVariable（×2）、F_ActionDrawText、F_ActionDrawScore、
 *       F_ActionDrawLife ⇒ GML 的 draw_text / draw_text_ext / draw_text_transformed 家族与 DnD 动作
 *       全落到这一个口；**带变换/带颜色的版本另有 GR_Text_Draw_Transformed 0x173068 /
 *       _Color 0x173338 / _Transformed_Color 0x1735a0，不在本卡**。
 *
 * ═══════════════════════════════════════════════════════════════════════════
 * 七、已证事实（六条，都能顺着地址复核）
 * ═══════════════════════════════════════════════════════════════════════════
 *   F1. eRenderState 是 **1..32 的稠密枚举**，六格是空的。
 *       证据：0x17fd28 `sub r0, r0, #1` + 0x17fd38 `cmp r0,#31` + 0x17fd3c `addls pc,pc,r0,lsl #2`
 *       （表 0x17fd44..0x17fdc0 共 32 项）；状态 0 与 >32 落 0x17fd40 直接返回。
 *       空操作状态：2、14、19、20、22、23（6 个）；`pop r3,r4,r5,r6,r7,pc` 是唯一出口。
 *       每个状态的动作 = 「写一个具名全局（可选）」+「调一个 FuncPtr_glXxx（可选）」+「一个转换器（可选）」；
 *       GL 调用一律走 .data 里的函数指针，不走 PLT。
 *
 *   F2. eClearFlags 只有两位有效，而且**深度与模板绑在同一位上**；bit2（值 4）从来没被读过。
 *       bit0(1)：glClearColor(r/255,g/255,b/255,a/255) + g_LastColour = 颜色 + `mov r9,#16384`(0x4000)
 *       bit1(2)：glClearDepthf(**固定 1.0f**) + glClearStencil(第 3 形参) + `orr r9,r9,#1280`(0x500)
 *       两位都不置 ⇒ r9 = 0 ⇒ glClear(0)。
 *       反证：引擎四个调用点传 7（GR_D3D_Init/Reset/GR_Draw_Clear）与 6（DrawTheRoom）——6 里没有 bit0，
 *       所以 DrawTheRoom 默认**只清深度+模板、保留已经画好的背景色**；4 这一位在 7/6 里都出现却无人读。
 *
 *   F3. 纹理绑定的三个常量 + 两级缓存 + 一个上限。
 *       glActiveTexture(**0x84C0 + stage**，0x182b7c/0x182b84) 只在 `g_CurrActiveTexture != stage` 时发；
 *       glBindTexture(**0xDE1**, texture->**+0x14**)；stage **> 7 直接返回**（0x182b20）；
 *       缓存两层：`_pLastTexture[8]`（32 B，每单元一份）+ `_pLastActualTexture`（单槽，只给单纹理通道）；
 *       `g_ForceTextureSet` 可绕过缓存；每次真绑 `++g_numTextureSwaps`；
 *       采样器状态固定查 **第 9 号**（GetSamplerState(stage, 9)）当 eMipEnable 用；
 *       纹理同时被当 render target 时**拒绑并打印** "Trying to set texture that is also bound as surface
 *       - bailing...\n"（0x34bb30），一个 GL 调用都不发。
 *
 *   F4. SetMatrices 的形参序与槽序是置换：slot0=p1、slot1=p2、slot2=p0，然后 slot3=p0×p1、slot4=slot3×p2；
 *       GL_MODELVIEW 装 slot3、GL_PROJECTION 装 p2，GL2 路径把 slot0 传到 uniform 5。
 *       yyMatrix::Multiply(dst,A,B) = 行主序 A×B（0x27aa00 取 A[1]、0x27aa08 取 B[4] 相乘）。
 *       ⇒ **第二个形参是投影矩阵**（指令直证），第一个/第三个是 world/view（推断，见 §四）。
 *       连带：Graphics::GetMatrix(eMatrix idx) 直接 `m_CurrentMatrix + idx*0x40`，所以 eMatrix 0/1/2 =
 *       view/projection/world，且 Clear 的「存 2,0,1 再按同序写回」在该置换下恰好原样还原。
 *
 *   F5. GR_Texture_Draw 的 z **不是形参**，是全局 GR_Depth；而 GR_Depth 的上下限是 ±16000，不是 11000。
 *       0x17509c 取 GOT→GR_Depth（.bss 0x4859ac 附近，与 GR_3DMode 0x4859b0、g_States 0x4859c8 同簇），
 *       0x1750b4..0x1750cc 把同一个值写进六个顶点的 +0x08/+0x20/+0x38/+0x50/+0x68/+0x80。
 *       GR_3D_Set_Depth 0x1631dc：g_isZeus==0 && GR_3DMode==0 ⇒ GR_Depth = 0；否则
 *       clamp(z, −16000.0f(0xc67a0000), +16000.0f(0x467a0000))（0x163210/0x163234/0x16323c/0x16324c）。
 *       ⇒ 已知的 11000 上限在**调用方**（DoSlowDrawRoom / CSprite 的链上），
 *         −12000 / −13000 两个哨兵落在 ±16000 内，**原样穿过**本函数进顶点。
 *
 *   F6. 文本层的「画笔状态」全在全局，颜色/透明度每行现取。
 *       GR_Text_Draw 的 5 个形参只有位置/文本/sep/w；颜色 = GR_Draw_Get_Color()、
 *       alpha = GR_Draw_Get_Alpha()（0x172f7c/0x172f88，在逐行循环**内部**各调一次）；
 *       对齐 = Graphics_Text::halign/valign（1 = 中/中，2 = 右/下，其它 = 左/上）；
 *       换行 = Split_TextBlock(text, w, list)（w < 0 即不换行）；
 *       行距 = sep（< 0 ⇒ CFontGM::TextHeight）。
 *       ⇒ 任何「文本位置算错了」的现场，先查这三个全局 + 字体对象，不要查形参。
 *
 * ═══════════════════════════════════════════════════════════════════════════
 * 八、open（本卡明确不做）
 * ═══════════════════════════════════════════════════════════════════════════
 *   · 全部 32 个 eRenderState 处理块的**内部**控制流（本卡只钉到「哪个全局 + 哪个 GL 常量 + 哪个转换器」）
 *   · RenderStateManager 那条同名口（0x167e64，144 B）：它是 15808 B 的 g_States 的方法，和本卡的
 *     Graphics::SetRenderState 是两条不同的函数；两者的分工（谁在什么时候把 RSM 的缓存放出去）未证
 *   · g_SrcFIX / g_DestFIX 恒被 ConvertBlend 写成 −1（0x17fc18 无条件 `str r3,[r1]`），
 *     而调用方随后又用返回值覆盖；`FIX` 到底给谁用，未证
 *   · eBlend 的 0/1 两值：表只覆盖 2..11（0x17fc14 `cmp r0,#9` 的 `sub r0,r0,#2` 之后），
 *     0/1 与 >11 一律落到 `mov r0,#0`（GL_ZERO）且 *pOut = −1 —— 这两档是不是「未定义」未证
 *   · eFog 的 0 值映射到 **0.0**（GL_ZERO，非法 fog mode），1/2 才是 EXP/EXP2（2048.0/2049.0），
 *     >2 回落到 9729.0（GL_LINEAR）；枚举里 0 到底代表什么，未证
 *   · ConvertCull 用 g_RenderTargetActive（.data 0x3f23b4）翻 CW/CCW —— 翻的物理原因是 Y 翻转还是
 *     离屏 FBO 方向，未证（只证「==1 时翻转」）
 *   · YYTPageEntry 的 +0x08/+0x0a 我按公式叫「原点位移」，官方名未证；+0x00..+0x06 与 +0x0c/+0x0e
 *     的单位（texel vs 归一化）由「×1/宽」这一步反推为 texel，未在加载器侧复核
 *   · ePrimType 的枚举名：本卡只证 4（6 顶点 = 两个独立三角形）与 5（4 顶点，几何上只能按条带/扇铺满四边形）两个取值；
 *     与 GL_TRIANGLES/GL_TRIANGLE_STRIP 的 4/5 同号，但**同号不等于同义**，未证
 *   · GR_Texture_Draw 的顶点数组在 AllocVerts 之后的去向（Flush 里怎么进 VBO、索引怎么发）
 *   · GR_Text_Draw 的 UTF-16 → 字形（CFontGM::Draw_String 内部）与 Split_TextBlock 的断行规则
 *
 * ═══════════════════════════════════════════════════════════════════════════
 * 锚点（只挂载重最大的 14 条；完整逐条表见 asm/index-Graphics_*.tsv 六份）
 * ═══════════════════════════════════════════════════════════════════════════
 */
/* @0x17fd28 sub r0, r0, #1 —— 状态号先减 1，枚举从 1 起 */
/* @0x17fd3c addls pc, pc, r0, lsl #2 —— 32 项跳表 */
/* @0x180024 movw r0, #0xbe2 —— state 12 = GL_BLEND */
/* @0x17fdc8 mov r0, #2960 —— state 25 = 0xB90 GL_STENCIL_TEST */
/* @0x17f290 mov r9, #16384 —— bit0 ⇒ mask = 0x4000 GL_COLOR_BUFFER_BIT */
/* @0x17f25c orr r9, r9, #1280 —— bit1 ⇒ mask |= 0x500 GL_DEPTH|GL_STENCIL_BUFFER_BIT */
/* @0x182b7c add r0, r7, #33792 —— glActiveTexture 基址 0x8400 */
/* @0x182b84 add r0, r0, #192 —— +0xC0 ⇒ GL_TEXTURE0 + stage = 0x84C0 + stage */
/* @0x17ed90 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> —— slot3 = p0 × p1 */
/* @0x17edec movw r0, #0x1701 —— p2 装进 GL_PROJECTION */
/* @0x174efc ldrsh r0, [r5, #20] —— page->+0x14 = 纹理页号，进 GR_Texture_Exists */
/* @0x1750b4 str r3, [r4, #0x68] —— 六个顶点的 z 全写 GR_Depth */
/* @0x17515c ldr r0, [sp, #0x4c] —— 第 8 形参（栈 0x4c）= 角度，喂 sinf */
/* @0x172e50 bl 0x172560 <_Z15Split_TextBlockPKciP11TStringList> —— 第 5 形参 w 就是换行宽度 */
