# live-oracle 剩余三项登记（TouchEvent 注入通道 / GR_Window_View_Define 矩形 / id&511 冲突策略）

本文件登记音频线收口后剩下的三项 live-oracle 语义。**只读逆向**：全部结论来自
libyoyo（ARMv7，sha256 `3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a`）
反汇编 + 原版 APK（sha256 `d608f455…`，2.1.9）DEX 反编译；不含任何原版 app 运行、
不含输入注入、不含合成内存 oracle 实测（Unicorn 本轮未使用，凡涉运行态的推断已单独标注）。

固定现场：
- libyoyo：`~/callys-caves-2-rs/reconstruction/live-mem/libyoyo_armv7.so`（= 原版 APK `lib/armeabi-v7a/libyoyo.so`）
- 原版 DEX 反编译：`~/cally-work/shell32/apk/jadx-out/sources/`（base.apk 同 sha256）
- 工具：`gobjdump -d -C`（本机无 LLVM ARM backend 时的主通道）、`readelf -r/-A/-S`
- scratch 分析脚本（未入库）：`~/.hermes/cache/scratch/wl5/`
  （`got_flow.py` GOT 字面量数据流、`slot_census.py` 全量 slot 引用普查、`slotname.py`、`findrefs.py`）

ABI 事实（三项共用，先说清）：
`readelf -A` = ARMv7-A / Thumb-2 / **VFPv3-D16**，且 **无 `Tag_ABI_VFP_args`** ⇒ 基准标准
（softfp：浮点按位走 r0-r3→栈）。因此本文件里"浮点字段用 `str` 写"与"实参用 `vcvt.f32.s32` +
`vmov` 传"都是**位拷贝**语义，不是类型错误；判断字段是 float 还是 int 要看**消费者**用什么
读（`vldr`+浮点运算 vs `ldr`+`vcvt.*.s32`）。

---

## 1. TouchEvent 注入通道（Java → runner 内部 → GML）

### 1.1 定位证据

Java 侧（原版 DEX，jadx 反编译；**不是** RunnerActivity，是 GLSurfaceView）：

| 位置 | 事实 |
|---|---|
| `com/vdogames/callyscaves2/DemoGLSurfaceView.java:354` | `onTouchEvent(MotionEvent)` = 触摸总入口 |
| 同文件 `:356-362` | 先让 `RunnerActivity.mExtension[]`（IAP/社交/广告扩展）独占优先（返回 true 即吞掉） |
| `:363-364` | `actionCode = event.getAction() & 255`（裸 action，丢掉 pointer index 高位） |
| `:365-377` | 逐 pointer：`id = event.getPointerId(i2)` |
| `:367-373` | **actionCode==5(POINTER_DOWN)/6(POINTER_UP) 时只有 changed pointer（`(action&0xFF00)>>8 == i2`）收到真实 actionCode，其余指针一律以 action=2(MOVE) 上报** |
| `:375` | 其余情况全部指针都用 actionCode |
| `:370/372/375` | `RunnerJNILib.TouchEvent(actionCode, id, event.getX(i2), event.getY(i2))` |
| `:378-384` | `RunnerActivity.CurrentActivity.vsyncHandler == null` → `Thread.sleep(16)`（无 vsync 时的帧兜底） |
| `com/yoyogames/runner/RunnerJNILib.java:143` | `public static native void TouchEvent(int i, int i2, float f, float f2)` |

Native 入口（dynsym 直出符号，无需猜测）：

- `Java_com_yoyogames_runner_RunnerJNILib_TouchEvent` = **0x291c6c**，size 468，`.text`
- 前序调用：`0x291c84 bl 0x290614 <setJNIEnv>`（每次进入刷新 JNIEnv 缓存）

### 1.2 语义还原（地址级）

实参落位（softfp）：`r0=JNIEnv*`、`r1=jclass`、`r2=action→r5`、`r3=id→r4`、
`[sp+0]=x→s17`、`[sp+4]=y→s16`（`0x291c74/291c78/291c7c`）。

(a) 坐标夹取（先做，与 id 无关）：

```
291c94  r3 = GOT 基址 0x3F1C58（= (pc+8)+0x0015ffbc）
291c98  vcmp.f32 s17, s15        ; s15 = [pc+384] = 0x00000000 = 0.0f
291ca8  vmovmi.f32 s17, s15      ; x < 0 → x = 0
291ca0  r2 = g_DeviceWidth(0x3f26c0)          ; slot 0x3efea4
291cb8  vcmpe.f32 s17, (float)w  ; x >= w → x = w-1
291cc0  subge r2, r2, #1 ; vcvtge.f32.s32 s17, r2
```
y 轴同构，用 `g_DeviceHeight`（slot `0x3efea8` → **0x3f26bc**）。
⇒ 注入坐标的合法域是 **[0, g_DeviceWidth-1] × [0, g_DeviceHeight-1]（窗口像素，不是 448×252 的视图坐标）**。

(b) id 分叉（**注入的第一个坑**）：

```
291d04  cmp r4, #9 ; 291d0c bls 291d7c   ; id<=9 走"逐指针"路径
291d18  r2 = g_localInputEvents(0x756d48, size 2560)   ; slot 0x3f194c
291d1c  r0 = id*5 ; lsl #2 → id*20
291d2c  stmib r1, {r6, ip}   ; [id*20+4] = (int)x ; [id*20+8] = (int)y
291d30  str r4, [r1, #16]    ; [id*20+16] = id
```
```
291d7c  cmp r4, #0 ; 291d80 beq 291df4   ; ← id==0 唯一走"鼠标态"的路径
291d94  r1 = g_MousePosX(0x53468c, size 40) ; slot 0x3efba4
291d98  str r6, [r1, r4, lsl #2]        ; g_MousePosX[id] = (int)x
291da0  str ip, [r2, r4, lsl #2]        ; g_MousePosY[id] = (int)y   (g_MousePosY=0x534664, slot 0x3efba0)
291df4  vcvt.s32.f32 s16, s16           ; id==0 追加：
291e00  r0 = g_MouseX(0x5346b8,  4)     ; slot 0x3f0378
291e04  vstr s17, [r0]                  ; g_MouseX = f32(x)（唯一以 float 存的位置）
291e08  r1 = g_MouseY(0x5346b4,  4)     ; slot 0x3f037c
291e10  vstr s16, [r1]                  ; g_MouseY = f32(y)
```
⇒ **id==0 才写 g_MouseX/g_MouseY（GML `mouse_x` 族的原始来源之一）；id>0 只写 per-pointer 数组。**

(c) action 分派（`0x291d38 addls pc, pc, r5, lsl #2`，跳表在 0x291d40..0x291d58；r5>6 直接返回）：

| action | 目标 | `g_localInputEvents[id*20+0]` | `g_DoMouseButton[id]` |
|---|---|---|---|
| 0 (DOWN) | 0x291dd0 | `0x80000003` | 1 |
| 1 (UP) | 0x291d5c | `0` | 0 |
| 2 (MOVE) | 0x291da8 | `0x80000002` | 1 |
| 3 (CANCEL) | 0x291d74 | — 返回（无副作用） | — |
| 4 (OUTSIDE) | 0x291d74 | — 返回 | — |
| 5 (POINTER_DOWN) | 0x291dd0 | `0x80000003` | 1 |
| 6 (POINTER_UP) | 0x291d5c | `0` | 0 |

`g_DoMouseButton` 写点：`0x291dc4 / 0x291dec`（=1，slot 0x3f0634 → **0x535700, 40B = 10×i32**）、
`0x291d70`（=0，写入 0x535700+id*4）；且 **只有 id<=9 才写**（`291d68 tst/cmp r4,#9` 后的 `ldrls/strls`）。
`0x80000002` 落点是 `g_localInputEvents`（0x756d48，128 槽 × 20B），**不是** g_DoMouseButton。

(d) 消费侧（每 step 一次，帧边界已定位）：

```
DoAStep()                     @0x1d32c0
  └ 0x1d3340 bl 0x18d37c IO_Start_Step()
        └ 0x18d458 bl 0x18d288 IO_Update()
              ├ 0x18d2b4  读 g_DoMouseButton(0x535700)      ← slot 0x3f0634
              │   0x18d29c 门: g_fDoubleClickAsMbRight(0x3f5030, 1B；slot 0x3eea64)
              │   0x18d2f8 bl 0x215148 Timing_Time()（64bit）
              │   0x18d34c 阈值 g_doubleClickThreshold(0x3f5038, 8B；slot 0x3f0638)
              │   0x18d35c 命中双击 → g_DoMouseButton[i] = 0x80000002（bit0 清、bit1 置）
              ├ 0x18d328 bl 0x18f094 IO_UpdateM()
              │   0x18f39c 读 g_DoMouseButton(0x535700) / 0x18f3a4 读 g_DoMouseButton_Last(0x5356d8)
              │   18f3ec 循环 i=0..9：cur=g_DoMouseButton[i], prev=Last[i]
              │     bit0=左键、bit1=右键 → 写 _IO_ButtonDown(0x534b30)
              │                              _IO_ButtonPressed(0x534af0)
              │                              _IO_ButtonReleased(0x534b10)   （各 30B = 10×3 按钮）
              │   18f388 memcpy(…, 256) 把 cur 拷进 Last（含相邻输入区）
              ├ 0x18d32c bl 0x190ac0 GamepadUpdateM()
              └ 0x18d334 b  0x18cfa4 ProcessVirtualKeys()
```
GML 侧读取（builtin → 表）：

| GML | builtin | 落到 |
|---|---|---|
| `mouse_check_button_pressed(b)` | `F_CheckMouseButtonPressed` @0x160e08 → `…_Common` @0x160c0c | `IO_Button_Pressed(b, 0)` @0x18c0f0 → `_IO_ButtonPressed[0*3+b-1]` |
| `mouse_check_button(b)` / `_released` | 同族 @0x160dcc / 0x160e44 | `IO_Button_Down` @0x18c0b4 / `IO_Button_Released` @0x18c12c |
| `device_mouse_check_button_*(b,i)` | `F_YoYo_MouseCheckButton*` @0x15e690/0x15e6dc/0x15e728（两实参都读） | 同上，`idx=i` |
| `mouse_x` / `mouse_y` | `F_YoYo_MouseX/Y` @0x15e774/0x15e7b0 | `GR_Window_Views_Mouse_Get_X/Y(0)` @0x17ad8c/0x17adb0 → `g_MousePosX/Y[0]` → 视图换算 |
| `mouse_x_raw` / `device_mouse_x(i)` | `GetRawMouseX/Y(i)` @0x159e8c/0x159eec（`i<=10` 才有效） | `g_MousePosX/Y[i]` **直读，不做视图换算** |

### 1.3 关键语义（下游直接可用）

1. **两个"坑"的机制已解释清**（此前只登记了现象）：
   - `id` 必须 0：只有 id==0 才写 `g_MouseX/Y` 并走鼠标态分支；id>0 只进 per-pointer 数组，
     GML 的 `mouse_check_button_*()`（idx 固定 0）永远看不到。
   - DOWN 与 UP **必须落在不同 step**：`g_DoMouseButton[i]` 是**电平**，而
     `_IO_ButtonPressed/_IO_ButtonReleased` 是 `IO_UpdateM` 每 step 用 `cur ^ prev` **跳变**派生的。
     同一 step 内先 DOWN 后 UP ⇒ step 时只见到 UP，无跳变 ⇒ `mouse_check_button_pressed()` 恒 0。
2. `g_DoMouseButton[i]` 是位掩码：bit0=左键按住、bit1=右键；`0x80000002` 是"本次按下被并进双击"
   的标记（由 `IO_Update` 用 `Timing_Time()` 与 `g_doubleClickThreshold` 判定）。
3. 触摸注入的**报点空间是窗口像素**（`g_DeviceWidth/Height`），窗口→视图的换算发生在消费侧
   （第 2 项登记）。
4. 有输入录制/回放通道：`IO_Record` @0x18bc94 / `IO_Playback_Update` @0x18ba90 读写
   `g_MouseX/g_MouseY`（0x5346b8/0x5346b4）；`g_IOFrameCount` @0x5346bc。

### 1.4 下游用途

- **壳内输入注入线**（`reconstruction/live-mem/shell32/`）：`work/cmd.txt` 的 `touch <action> <id> <x> <y>`
  必须遵守上面 1.3 的两条（id=0 + DOWN/UP 分帧），否则永远推不动剧情。
- **重建侧帧边界**：`android-build/src/com/gongmi/callyscaves2/PointerReleaseQueue.java` + core
  `ir_scene.rs::end_frame`（"帧输入边界"契约）与这里的 `IO_Start_Step→IO_Update→IO_UpdateM→GML`
  是同一语义的两种实现——重建侧必须在 end_frame 之后才 retire `pressed/released`，否则同样丢跳变。
- **差分测试**：未来"注入→逐帧状态比对"的输入记录格式可对齐 `g_localInputEvents`（20B/槽：
  marker,x,y,id）。

### 1.5 置信度

**高**（Java 反编译 `file:line` + native `addr` 双向对齐；跳表 7 分支逐条读）。
唯一推断项：`0x80000002/0x80000003` 的**业务含义**（"双击并入"/"按下"）由 IO_Update/IO_UpdateM
的用法反推，属**推断**（消费侧行为确定，命名未证实）。

---

## 2. GR_Window_View_Define 的矩形参数语义

### 2.1 定位证据

- 符号：`_Z21GR_Window_View_Defineifffffffffii` @ **0x179bfc**，size 176（gobjdump 已能 -C 解出参数表）
- 唯一调用者：`UpdateViews()` @0x1b02ec（全量 slot 普查：`_views` 只有 9 个引用者，见下）
- 目标结构：`_views` @ **0x498cd8**（BSS，size 1584 = 33×48B），stride **0x30**，索引 0..31
  （`179bfc cmp r0,#31; bhi`）；计数 `_views_count` @ **0x498cd4**
  （GOT 槽 `0x3f0308`/`0x3f030c` 的 addend 直接解析得到，非猜测）

### 2.2 签名（由调用点实参落位反推，非仅凭 mangled 名）

mangled 类型串 = `i` + **9×f** + `ii`（共 12 参数）。`UpdateViews` 的准备序列
（0x1b0248..0x1b02ec）显示实参就是（**注意端口是 int 字段被 `vcvt.f32.s32` 转成 float 后传入**）：

```c
void GR_Window_View_Define(
    int view,                       // r0
    float xport, float yport, float wport, float hport,   // r1,r2,r3,[sp+0]（来自 GML 视图 +0x14/+0x18/+0x1c/+0x20）
    float xview, float yview, float wview, float hview,   // [sp+4..+16]（来自 GML 视图 +4/+8/+0xc/+0x10，raw 位）
    float angle,                                          // [sp+20]（来自 +0x24）
    int   surface_id,                                     // [sp+24]（来自 +0x3c）
    int   camera_id);                                     // [sp+28]（来自 +0x40）
```

### 2.3 语义还原（地址级）

`GR_Window_View_Define` 把 12 个实参逐字写进 `_views + view*48`（softfp ⇒ 浮点字段用 `str` 存位）：

| `_views[i]` 偏移 | 字段 | 写入指令 | 来源实参 |
|---|---|---|---|
| +0x00 (byte) | visible | `179c38 strb r5(=1)` | **无条件置 1**（不是参数） |
| +0x04 | xview (f32) | `179c4c vstr` | [sp+16] |
| +0x08 | yview (f32) | `179c5c vstr` | [sp+20] |
| +0x0c | wview (f32) | `179c6c vstr` | [sp+24] |
| +0x10 | hview (f32) | `179c74 vstr` | [sp+28] |
| +0x14 | xport (f32) | `179c50 str r1` | r1 |
| +0x18 | yport (f32) | `179c58 str r2` | r2 |
| +0x1c | wport (f32) | `179c40 str r3` | r3 |
| +0x20 | hport (f32) | `179c3c vstr` | [sp+12] |
| +0x24 | angle (f32) | `179c7c vstr` | [sp+32] |
| +0x28 | surface_id | `179c60 str` | [sp+36] |
| +0x2c | camera_id | `179c80 str` | [sp+40] |

计数语义：`179c18 ldrb [..+0]` 为 0（原来不可见）时才 `179c94..179c9c count++`；
`GR_Window_View_UnDefine(i)` @0x179cac 反向 `count--` 且 `visible=0`；
`GR_View_Undefine_All()` @0x179d00 清 32×48B 并把 count 归零。
**注意循环上界**：`UpdateViews` 只对 view **0..7** 调 Define/UnDefine（`1b01f8 cmp r9,#8`），
但 `_views` API 本身支持 0..31——GML 侧视图数组（`Run_Room+0x48+4*i`）是 8 槽对象指针。

`_views` 的**全部** 9 个引用者（完整普查，无遗漏）：

```
0x179c14 GR_Window_View_Define     0x179cc0 GR_Window_View_UnDefine
0x179d0c GR_View_Undefine_All      0x179d98 GR_Window_View_Convert
0x17a164 GR_Window_View_Convert_World   0x17a404 GR_Window_Views_Get_ID
0x17a6f8 GR_Window_Views_Convert   0x17ab00 GR_Window_View_Mouse_Set
0x17acac GR_Window_Views_Mouse_Set
```

**矩形→屏幕的换算公式**（由消费侧三条路径给出，逐指令可核）：

- 轴对齐（|angle| < 0.01，`GR_Window_View_Mouse_Set` 0x17ab94 分支 / `Convert_World` 0x17a360）：
  ```
  u = xport + wport * (x - xview) / wview
  v = yport + hport * (y - yview) / hview
  ```
  指令（`GR_Window_View_Mouse_Set`）：`17ab7c/17ab80 vmul`（+0x1c/+0x20 作乘子）、
  `17ab8c/17ab94 vdiv`（+0x0c/+0x10 作分母）、`17ac20/17ac24 vadd`（+0x14/+0x18 加偏置，轴对齐分支）；
  `wview/hview == 0.0` 时**整个换算被跳过**（`17ab14/17ab24 vcmp #0.0` → `beq 17ac0c` 直接返回）。
- 旋转路径（`vcvt.f64.f32; vcmpe.f64` 与常量 `0x3f847ae147ae147b` = 0.01 比较，`bmi` 分流）：
  `rad = angle*pi/180`（常量 0x40490fdb=π、0x43340000=180.0），绕**端口中心**
  `(xport+wport/2, yport+hport/2)` 旋转后取整（`cosf/sinf` PLT 调用）。
- 相机反投影（`camera_id != -1` 时）：`GR_Window_View_Convert` 0x17a034 起走
  `CCameraManager::GetCamera(camera_id)` → `CCamera::GetInvViewProjMat()`，把 NDC 反算回屏幕；
  `Convert_World` 反向用 `CCamera::GetViewProjMat()`。相机为空或透视时直接放弃（返回不改值）。
- `GR_Window_Views_*` 系列先在 8 槽里挑**可见且包含该点**的 view（`GR_Window_Views_Get_ID`
  @0x17a3b8：命中测试用视图对象的 **view 矩形** `+0x04/+0x08/+0x0c/+0x10`，
  见 `17a508 vldr s14,[r5,#-28]`(=xview) 与 `17a518 [#-20]`(=wview)），再调 `View_Convert`。

### 2.4 与投影/裁剪的关系（关键区分：软件视图表 vs GL 侧）

- **`_views` 是输入/换算侧**：鼠标、GUI、世界↔屏幕换算、点命中测试全部读它。
- **GL 视口与投影在绘制侧，另行取数**（同一份矩形语义，但取自 **GML 视图对象**
  `Run_Room+0x48+4*i`，即 `visible/xview/yview/wview/hview @+0..+0x10`、
  `xport/yport/wport/hport @+0x14..+0x20` 为 **i32**、`angle @+0x24`、`surface @+0x3c`、`camera @+0x40`）：
  ```
  Draw_Room()   @0x1b3e98
    1b41ec fp = Run_Room->view[i]（i+18 索引 = +0x48+4i）
    1b41f4 可见性门；1b4200 surface_id
    1b4238..1b4264 (float)xport*wScale, (float)yport*hScale, wport*wScale, hport*hScale
    1b4288 bl GR_D3D_Set_View_Port(w,h,…)  @0x168cd8 → g_ViewPortW/H + Graphics::SetViewPort @0x17dfb0(glViewport)
    1b42b0 bl GR_D3D_Set_View_Area(x,y,w,h,angle) @0x169408 → g_ViewAreaX/Y/W/H(0x3f23a0/39c/398/394) + 正交投影
  ```
  即 **port 矩形 × 逐轴缩放 = 裁剪视口**，**view 矩形 + angle = 投影**。
  （缩放因子取自局部缓存 `1b4210 vldr s16,[sl]` / `1b4218 vldr s17,[ip]` → `s14/s15`；
  其身份指向 `UpdateViews` 写出的 `g_DisplayScaleX/Y`，**这一对应属推断**，
  但"port 四元组按 (s14,s15) 逐轴相乘后进 glViewport"是事实，见 `1b4258..1b4264`。）
- `UpdateViews` 尾部（0x1b02f8..0x1b034c）是两侧的耦合点：把所有可见 view 的 port 矩形取并集
  ```
  g_DisplayScaleX(0x3f50d8) = g_ApplicationWidth(0x3f510c)  / (maxX-minX)
  g_DisplayScaleY(0x3f50d4) = g_ApplicationHeight(0x3f5108) / (maxY-minY)
  ```
  ——这就是"多视图共用一个窗口"的缩放口径，也是 v1 §2 "g_ViewPort=0,0 1952×1220 逐轴填充"
  的成因。`g_ProjIsOrtho` @0x3f237c、`projection` @0x3f2628(64B)。
- 另有一条**跟随对象**路径：`UpdateViews` 0x1b0374 起用 `view+0x38`（实例 id）经
  `ms_ID2InstanceE` 查实例（见第 3 项），命中后把实例 `+0xb4/+0xb8` 经 border(+0x28/+0x2c/+0x30/+0x34)
  夹取，**回写视图对象 `+0x04/+0x08`（xview/yview）**（`1b0580 vstr s14,[r4,#4]`）。
  ⇒ 视图矩形不是常量：跟随相机会在 step 内改 GML 视图对象，下一 step 才由 Define 复制进 `_views`。

### 2.5 下游用途

- 重建侧 `crates/client/tests/view_projection_consumption.rs`（视口/投影消费断言）与
  `reconstruction/contracts/live-oracle.md §2 视图/相机` 的字段语义——本登记补上
  "端口为 float（GR_Window 侧）/ int（GML 侧）两份 + 换算公式 + 显示缩放来源"。
- 地图/相机回归（`full-playthrough.md`、`map-system.md`）的视口真实性判据。
- 未来活体观测：`_views` 也可作为"GML 视图对象 → 渲染输入"的**跨帧快照点**（比逐帧读 8 个对象便宜）。

### 2.6 置信度

**高**（符号名 + 调用点实参 + 结构偏移三方一致；`_views` 引用者全量列举）。
推断边界两处，均已标注：
(a) 端口字段在 `_views` 里是 f32 不是我推断的 i32 —— 已由消费者 `vldr`+浮点运算
（`17ab14/17ab24/17abe4`）与 `GR_Window_Views_Get_ID` 的 `vldr` 命中测试反证；
(b) `GR_D3D_Set_View_Port` 的**形参序**（名字里 w 与 x 的对应）只从寄存器落位读出，
符号本身无参数名——`g_ViewPortW←arg0, g_ViewPortH←arg1, g_roomExtents←arg2, g_transRoomExtents←arg3`
是事实，但"哪一个是 x"属**推断**（Draw_Room 侧调用处按 (wScale 缩放后的 port 四元组) 传，
与 `_views[+0x14..+0x20]` 同序，故实际使用不受影响）。

---

## 3. id & 511 冲突策略（实例 id 分配的位语义）

### 3.1 定位证据

| 项 | 地址 | 说明 |
|---|---|---|
| 表 | `CInstance::ms_ID2InstanceE` **0x536f28**（12B） | GOT 槽 **0x3edc4c**（唯一读地址） |
| id 分配源 | `room_maxid` **0x54255c**（4B） | GOT 槽 0x3f0814；引用者 8 处（见 3.3） |
| 插入/替换 | `CInstance::SetID(int, bool)` **0x1958cc**（296B） | 独立函数**无直接调用者** ⇒ 在所有调用点**内联** |
| 构造 | `CInstance::CInstance(float,float,int,int,bool)` **0x1994dc** | 只把 id 写进 `this+0x78`，**不登记表** |
| 查找 | `UpdateViews` 0x1b0380..0x1b03d0 等 36 处 | 全量普查见下 |

`ms_ID2InstanceE` 的全部 36 个引用者（普查输出，含用途）：

```
F_InstanceActivateObject 0x10bfb4 · F_VariableInstanceGet/Set 0x1169dc/0x116ae4 ·
F_VariableInstanceGetNames 0x1198a8 · F_SkeletonDrawInstance 0x11d6f0 ·
Object_GetInstance 0x14ecb8 · CCamera::CameraUpdate 0x170dec · CInstance::SetID 0x1958ec ·
FINALIZE_Instance_Class 0x195a00 · WithObjIterator::WithObjIterator 0x19d134 ·
CRoom::AddInstance ×4 0x1ab204/0x1ab3b4/0x1ab568/0x1ab6c0 · CRoom::ClearInstances 0x1ab7c4 ·
CRoom::ClearDeactiveInstances 0x1ab9e0 · CRoom::RemoveMarked 0x1abc0c · UpdateViews 0x1b062c ·
CLayerManager::Build/CleanInstanceElementRuntimeData 0x1b805c/0x1b8dac ·
F_LayerHasInstance 0x1bad20 · F_LayerRemoveInstance 0x1c1430 · CLayerManager::BuildRoomLayerRuntimeData 0x1c5e2c ·
F_LayerAddInstance 0x1c6e08 · Command_Collision{Point,Ellipse,Rectangle} 0x1c8aa8/0x1c8cdc/0x1ca468 ·
Command_InstancePosition 0x1c9200 · Command_InstancePlace 0x1ca958 · Check_LoadGameState 0x1d0f90 ·
EndRoom 0x1d1950 · StartRoom 0x1d397c · Variable_GetValue 0x1f3d20 · Variable_GetObjectName 0x1f3fb4 ·
YYGML_Variable_GetValue 0x1f4100 · Debug_GetInstances 0x29ac74
```

### 3.2 容器结构（二进制定标）

```
ms_ID2InstanceE (0x536f28, 12B)
  +0x00 table   : bucket 数组指针
  +0x04 mask    : 511        （= 容量-1，不是容量）
  +0x08 count   : 节点总数

bucket[i] (8B, i = id & 511, 512 个)
  +0x00 head : 节点*
  +0x04 tail : 节点*

node (16B)
  +0x00 prev ; +0x04 next ; +0x08 id(i32) ; +0x0c CInstance*
```
证据：`SetID` 0x1958f0 (`ldr r1,[r4,#4]` = mask) / 0x1958f4 (`ldr r7,[r4]` = table) /
0x1958fc (`ldr r3,[r7,r2,lsl#3]`，r2 = id&mask) / 0x195988 (`ldr r3,[r4,#8]; add #1; str` = count++)；
节点字段：0x195960 `str r6,[r0,#8]`(id) / 0x195964 `str r5,[r0,#12]`(instance) / 0x195974 `str r3,[r0]`(prev) /
0x195980 `str r1,[r0,#4]`(next)；bucket 头尾：0x1959d8 `str r0,[r2,#4]` + 0x1959dc `str r0,[r7,r8,lsl#3]`。

### 3.3 冲突策略（结论：**同桶链化，不跳过、不重试**）

(a) **id 分配**——`CRoom::AddInstance` 的 4 个变体全部是同一段（`room_maxid` 是**全局**计数器，
名字里的 "room" 有误导）：

```
0x1ab14c/0x1ab2ec/0x1ab4b8/0x1aaed8 处：
  ip → &room_maxid
  r6 = *ip ; r6 += 1 ; *ip = r6        ; id = ++room_maxid   （无循环、无冲突检查）
1ab178/1ab320  mov r3, r6               ; 第 4 个构造实参 = 新 id
1ab194/1ab338  bl CInstance::CInstance(x, y, objindex, id, true)
```
`CInstance::CInstance` 里 `1996b4 str sl,[r6,#0x78]` 只落 `id` 字段（另有 `0x199578..0x199584`
把 `ms_CurrentCreateCounter`(0x536f20, **8B**) 的 {lo,hi} 拷进 `this+0x70/+0x74` —— 是创建序/时间戳
快照，**与 id 分配无关**，勿混用）。

(b) **登记**（`SetID` 内联版，0x1ab1f4..0x1ab26c；独立版 0x1958cc）：

```
r9 = inst->id (+0x78) ; r7 = table ; r8 = mask
r8 = r9 & 511                       ; 桶号
node = MemoryManager::Alloc(16, "…", line 306)   ; 0x1ab218 / 0x195950
node->id = r9 ; node->instance = inst
if (bucket[r8].head == 0) { bucket[r8].head = node; node->prev = 0; node->next = 0; }
else { tail = bucket[r8].tail; node->prev = tail; tail->next = node; bucket[r8].tail = node; node->next = 0; }
count++
```
⇒ **不同 id 落在同一桶是正常情况，直接尾插成链**；不存在"跳过占位 id"的逻辑。

(c) **同 id 重登**（`SetID(id, add)` 的 `add==true` 路径，0x1958e8..0x1959d4）：先用
**旧 id**（`ldr ip,[r0,#0x78]`）定位桶，链上按 `node->id == id` 逐个比较（0x19590c/0x19591c），
命中则解链 + `MemoryManager::Free` + `count--`（0x195994..0x1959d0），随后按新 id 重新插入。
`add==false`（0x1958dc）只写 `+0x78` 字段、**完全不碰表** —— 这是"改 id 但不进表"的开关。

(d) **查找**（消费者口径）：`UpdateViews` 0x1b0384..0x1b03c0

```
r1 = ms_ID2InstanceE[4] (mask) ; r3 = ms_ID2InstanceE[0] (table)
idx = id & r1 ; node = table[idx*8]
while (node) { if (node->id == id) → 命中，返回 [node+0xc]（CInstance*）
               node = node->next }        ; 0x1b03a8/0x1b03b8
未命中 → 视为不存在（走 fallback）
```
⇒ **桶号只是索引，唯一性判据是节点里的完整 32-bit id**，所以 `id & 511` 的碰撞**不会**产生误命中。

(e) **持久与恢复**：`room_maxid` 参与存档：

```
Command_SaveGame(int)      0x1d0c14  写 room_maxid(+其 8B 邻居 room_maxtileid 0x542558)
Check_LoadGameState()      0x1d1070  读回并写 room_maxid（0x1d1078 str r0,[ip]）
Room_Get_maxid/Room_Set_maxid  0x1b5e08/0x1b5e1c
```
⇒ 读档后新实例沿用**存档里的计数器**继续自增；v2 观察到的"跨房间 carry-in"实例
（如 intro 期的 171015）正是 id 空间稀疏、且持久对象不回收的直接后果。

### 3.4 对既有登记的订正（重要）

`live-findings-v2.md §4`：
- C2 "项 = id&511，**直接映射、无链**" ⇒ **只对该快照成立**。真实结构是"512 桶 × {head,tail} +
  16B 节点链"，无冲突快照下每个桶恰有一个节点，于是 `head == tail` 正好表现为
  C2 记录的 "8B 两项同值"。**"无链"是观测假象，不是结构事实。**
- C3 "未决: id&511 冲突策略（疑为创建计数器跳过占位的 id）" ⇒ **订正**：
  计数器 `room_maxid` **无条件自增**（`++` 后即用），冲突由**同桶链化**消化；不存在跳过逻辑。
- C2 其余（count = 存活实例数、node+0x08 = id）与本次静态读取**一致**；
  C4 的 "node+0x0c → 作用域记录" 与本登记 `node+0x0c = CInstance*` 相符（实例自身即 YYObjectBase 作用域）。

### 3.5 下游用途

- 重建侧实例 id 语义：`spawn_seq` tie-break（v2 §7 的 carry-in 反转例外）必须按
  "id 单调自增、持久对象保 id、桶仅作索引"来实现，**不能**把 "id&511 当身份"。
- 存档往返（`ir_save.md`、`restore_snapshot_cross_room`）：`room_maxid` 属于必须存档的
  runner 全局（否则读档后新实例 id 与旧实例撞桶 → 链变长，行为上看不出，但差分比对会漂）。
- 活体观测工具：`verify_id2inst.py` 的容器假设需补两条 —— (i) 桶是 {head,tail} 不是"双词同值"；
  (ii) 节点是 16B {prev,next,id,inst}，链上取 `next` 在 +0x04。

### 3.6 置信度

**高**（分配/插入/解链/查找四处都有指令级证据，且与 v2 的 6/6 活体观测互证；
本轮为**静态**结论，未起原版 app 复核）。

---

## 汇总表

| # | 项 | 关键地址 | 结论要点 | 证据类型 | 置信度 |
|---|---|---|---|---|---|
| 1 | TouchEvent 注入通道 | JNI 0x291c6c；DemoGLSurfaceView.java:354-386；IO_Update 0x18d288；IO_UpdateM 0x18f094；表 0x534af0/b10/b30 | id==0 才进鼠标态并写 g_MouseX/Y；pressed/released 由每 step 电平跳变派生 ⇒ DOWN/UP 必须分帧；报点空间 = 窗口像素 | JVM 反编译 + ARM 反汇编（静态） | 高 |
| 2 | GR_Window_View_Define 矩形 | Define 0x179bfc；`_views` 0x498cd8/stride 48/32 槽；count 0x498cd4；唯一调用者 UpdateViews 0x1b0164 | 12 参 = 1i+9f+2i，逐字写入 `_views[view]`；port 矩形 × 逐轴缩放 → glViewport（裁剪），view 矩形 + angle → 正交投影；端口在 `_views` 里是 f32 | ARM 反汇编 + GOT addend 解析（静态） | 高（推断项：GL 侧形参 (w,x) 对应、缩放因子 = g_DisplayScaleX/Y） |
| 3 | id & 511 冲突策略 | id 源 `room_maxid` 0x54255c；表 0x536f28；SetID 0x1958cc；AddInstance 0x1ab144/0x1ab2e4 | id = ++room_maxid（全局、无跳过）；512 桶 {head,tail}，不同 id 撞桶 → **同桶尾插成链**；同 id 重登先解链再插；查找按完整 32-bit id 比对 | ARM 反汇编（静态）+ 与 v2 活体 6/6 互证 | 高 |

证据分层说明：三项**均为静态**结论（反汇编/反编译/GOT 解析）；本文件不含原设备实测、
不含合成内存 oracle 结论。凡涉"运行时具体数值/时序"的推断，已在 1.5 / 2.6 / 3.6 单独标注。
未使用 Unicorn（本轮三项都不需要合成内存 oracle 即可定论）。
