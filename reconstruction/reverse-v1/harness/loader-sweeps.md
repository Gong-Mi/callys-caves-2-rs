# 资源加载链 · 记录解析器的可测性普查（2026-11-01）

工具：`harness/sweep_loader.py <addr> [--dst N] [--max N]`。
做法：目的结构清零 → 跑一次原件记基线 → 把源记录里某一字节置 0x11 再跑 → 看目的结构哪几个字节变。
字段映射因此来自**原件行为**，不是我们的资产文档。下文所有地址都以
`libyoyo_armv7.so`（sha 3bbedd09…）为准。

## 已可测（有干净切片）

| 函数 | 地址 | 可测切片 | 头部切片里的映射 |
| --- | --- | --- | --- |
| `CObjectGM::LoadFromChunk` | 0x19d688 | src+0x00..0x1f | 已做成差分臂 `object_load_diff.py`（104 例 identical），见卡 `CObjectGM_LoadFromChunk.c` |
| `CBackground::LoadFromChunk` | 0xc2c44 | src+0x04..0x12 | 4→dst+8(int32)、8→dst+9(byte)、0xc→dst+0xa(byte)、0x10/0x11→dst+0/1/0x14、0x12→dst+1/4..7/0x16 |
| `CPath::LoadFromChunk` | 0x1a7120 | src+0x04..0x0f | 4..7→dst+0x14、8..0xb→dst+0x18、0xc..0xf→dst+0x1c |

## 还测不了（附具体原因，不是「以后再试」）

| 函数 | 地址 | 卡在哪 |
| --- | --- | --- |
| `CSprite::LoadFromChunk` | 0x1e972c | 开局 `bl CSprite::Clear`；把 Clear 换成空桩后仍从 **pc=0x0** 起跑进 ELF 头区并 UC_ERR_INSN_INVALID —— 它随后要 `operator new[]`（All_30 卡记了两次）等 PLT 调用，GOT 未重定位。即使接线，sprites/mask 数组是堆指针，逐字节比 dst 需要先做指针归一化 |
| `CBackground::LoadFromChunk`（0x13 之后） | 0xc2c44 | src+0x13 起解引用记录里的指针（tiled/data 一类），全零记录下 UC_ERR_READ_UNMAPPED |
| `CPath::LoadFromChunk`（0x10 之后） | 0x1a7120 | src+0x10 起同样走指针（UC_ERR_INSN_INVALID / WRITE_UNMAPPED） |
| `CEvent::LoadFromChunk` | 0xf2d84 | 零记录下返回 1 但一个字节都不写目的结构 —— 需要真实事件记录才知道它写到哪（也可能只写动作表） |

## 2026-11-01 第二次尝试：把 allocator 接上之后

给 `handler_oracle` 加了 `libc=True`：按 `.rel.plt` 解出的 PLT 入口（malloc 0xb6558 / free 0xb6578 /
memset 0xb65e8 / memcpy 0xb65f8 / memmove 0xb6718 / realloc 0xb6e88）在 Python 里应答，
分配走确定性 bump 分配器并把分配列表记进 `Oracle.allocs`（后面做指针归一化要按它来键）。

结果：`CSprite::LoadFromChunk` **仍然跑不起来**，但卡点变了，而且这次是实测定位的：

    0x1e98c4 之后 → 0xb6994（PLT 入口）→ 0xb64e8（PLT0 头）→ pc=0 崩

`0xb6994` 正是 All_30 卡里记的「调用序列 0xb6994×4」那四处的其中一个，`strrchr`/`feof` 一类
字符串与文件层函数。也就是说精灵解析不是缺分配器，是缺**文件/字符串层**：
它要从记录里的偏移取到 WAD 里的字符串（纹理页名、帧名），而我们的 harness 里
既没有映射 `game.droid`、也没设 WAD 基址全局，所以字符串指针全是野的。

⇒ 「把 allocator 接上就能测 CSprite」这个判断被自己的实测推翻了。下一步的前置变成：
把 `game.droid` 原样映射到引擎期望的基址（STATUS 里记的 WAD 地址 0x544c44）并设好基址全局，
让记录里的偏移能真的解出字符串 —— 之后再谈 sprites/mask 的指针归一化。

## 2026-11-01 第三次：PLT 地址表搞错了一次，已更正

真相先说：**上一节把 `0xb6994` 说成 `strrchr`/`feof` 一类是错的**。错因是 PLT 步长。
这个库的 `.plt` 是「16 字节 PLT0 + 12 字节/项」，不是 16 字节/项；按 16 字节算出来的
「入口地址」会整体错位，于是 hook 到的其实是**邻居函数**——上一轮那句「把 strlen 接上就好了」
其实是把不知名的第 5 项当成 strlen 接了，所以下一跳照样崩。

更正后的地址表（`plt_symbols()` 从 .rel.plt 按 12 字节步长推，231 项全对）：
`0xb6994` 落在第 98 项的 +4 处（`add ip,ip,#..` 那条），该项符号是 **expf**，不是字符串函数。
`CSprite::LoadFromChunk` 在开局 `Clear` 之后第一个外部调用是 expf（动画曲线求值一类的浮点）。

更正后又试了一轮：把 WAD 原样映射到 0x80000000、把基址全局 0x544c44 写成 0x80000000、
并接上 malloc/free/mem*/str*/atoi/expf/ceilf/floorf/sqrtf/sinf/cosf/fmodf/powf/atan2f，
`CSprite::LoadFromChunk` **仍然在 Clear 之后立刻 pc=0 崩，且一个外部调用都没发生**。
所以卡点既不是分配器也不是那批 libc 导入，而是**目的对象自己的间接调用**：
dst 是被清零的，若解析器在入口后立刻走 `ldr r3,[dst]; blx r3`（vtable 槽）或某个函数指针表，
拿到的是 0。下一步得先构造/调用 CSprite 的构造器，或给该槽装壳。

装置层面这一轮也留了两条教训：
1. **PLT/导入表的地址必须从段头推，不能手抄**——手抄错了会静默 hook 邻居，行为看着"改了"其实没生效；
2. 接线要打印「实际 hook 了哪些符号、地址是多少」（现在 `Oracle.libc_hooked` 会列出来）。

## 下一步的三条路（按代价排）

1. **给 CBackground / CPath 做差分臂**：切片小（15 B / 12 B）但干净，模型短，能立刻把
   「背景记录头 / 路径记录头」钉死。代价低，收益是加载链上多两块地基。
2. ~~**给 PLT 接线**~~（已做，见上）：allocator 不是卡点；真正的卡点是文件/字符串层 +
   WAD 基址。这条要改写为「映射 game.droid 到引擎期望基址 + 设基址全局」。
3. **拿真实记录喂原件**：从 `assets/game.droid` 切出 OBJT/BGND/PTH 的真实记录，让原件解析并
   dump 字段，与 Rust `callys-asset` 的结果逐对象对账。这是「在原件上解析资源」的直接形态，
   但需要先解决记录定位与变长切分。

## 2026-11-01 补记：精灵记录里的指针修正指的是 WAD 基址，不是「未重定位的镜像基址」

`CSprite::LoadFromChunk` 在 0x1e9980 起的循环里把记录中的 u32 逐个搬进 `dst[0x54]` 指向的 new[] 数组，
并对非零值做一次修正（0x1e998c `ldr r12,[pc,#..]` / 0x1e999c `ldrne r1,[r7,r12]` / 0x1e99a0 `ldrne r1,[r1]` /
0x1e99a4 `addne r1,r1,r2`），也就是「二级间接取到全局，再加记录里的偏移」。

实测（WAD 映到 0x80000000、基址全局 0x544c44 写成 0x80000000）：record 0 的数组首元素 = **0x8038be3a**
= WAD 基址 + 0x38be3a（TPAG 区）。所以它是**真正的绝对指针**，不是"记录内偏移"。
先前记录里说的"加的是未重定位的镜像基址（=0）"只在**基址全局没设**的情况下成立——
那是装置配置差异，不是函数语义。

对后续对账的含义：这些字是 WAD 指针而不是堆指针。`ptrnorm.normalize` 只把落在分配区里的字换成
分配序号，WAD 指针保持原字节；因为我们的 WAD 基址是固定的 0x80000000，两侧对账时它们可比。
