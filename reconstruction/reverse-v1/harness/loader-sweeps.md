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

## 下一步的三条路（按代价排）

1. **给 CBackground / CPath 做差分臂**：切片小（15 B / 12 B）但干净，模型短，能立刻把
   「背景记录头 / 路径记录头」钉死。代价低，收益是加载链上多两块地基。
2. **给 PLT 接线**：`malloc/free/operator new[]` 用 harness 堆实现并把调用记录下来，
   再把 dst 里的堆指针按「分配序号」归一化后比较。这样 CSprite（精灵/纹理页）才可能进差分。
   代价中等，收益最大——精灵解析是 asset→纹理页这条链的中心。
3. **拿真实记录喂原件**：从 `assets/game.droid` 切出 OBJT/BGND/PTH 的真实记录，让原件解析并
   dump 字段，与 Rust `callys-asset` 的结果逐对象对账。这是「在原件上解析资源」的直接形态，
   但需要先解决记录定位与变长切分。
