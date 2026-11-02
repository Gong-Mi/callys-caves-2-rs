# Spine 资源生命周期：静态 C 译文候选

原件 `libyoyo_armv7.so`，SHA256
`3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a`。

## 本批实际入口（按原件地址去重）

| 原件符号 | 地址 | 字节 | 译文 |
|---|---|---:|---|
| spSkeletonJson_createWithLoader | 0x28b700 | 52 | src/spine_json_lifetime.c |
| spSkeletonJson_create | 0x28b734 | 24 | src/spine_json_lifetime.c |
| spSkeletonJson_dispose | 0x28b74c | 56 | src/spine_json_lifetime.c |
| spAtlas_dispose | 0x284120 | 84 | src/atlas_dispose.c |
| spAtlasPage_dispose | 0x2840b8 | 32 | src/atlas_dispose.c |
| spAtlasRegion_dispose | 0x2840f4 | 44 | src/atlas_dispose.c |
| _spAtlasPage_disposeTexture | 0xbd814 | 40 | src/atlas_texture.c |

译文主张档位为 `bytecode_anchored`；本批运行的是重建物，夹具证据为
`test_anchored`，不是原版 oracle。对象、指针槽保持 ARM32 的四字节宽度；
host 夹具将完整对象图映射到低地址，ARM32 则使用 freestanding 静态可执行件。

## 已钉合同

- JSON helper 分配 28 字节，保留真实文件元数据字符串及行号 62；
  create 转发 atlas、保存 loader 并设置拥有位。
- JSON dispose 依次释放拥有的 loader、+0x18、+0x08、自身；
  后两字段在各自外调之后才读取，不能提前缓存。
- atlas 先整条 page 链，再整条 region 链，最后自身；每个 next 都在释放节点前读取。
  renderer 槽不在本入口释放。
- page 的纹理回调先执行，然后重新读取 name 并释放 name/page；
  region 保留 name/splits/pads/self 的次序。
- 纹理回调仅在 id 非零且 `g_bFreeingSpineSprite` 字节非零时转交原样 id；
  包括负 id 的位模式。GOT、重定位、flag 宽度及实际图形符号均作静态校验。
- 真实 C 消费链已串联 Loader→骨骼构造/解码→JSON 创建→Clear→骨骼析构→
  JSON/atlas/page/region/纹理回调，未用 JSON/atlas 入口替身冒充接线。

## 验收

在仓库根运行：

    python3 -B reconstruction/reverse-v1/c/spine_lifetime/tools/run_tests.py

用 `--out <尚不存在的目录>` 保留完整日志、源码哈希与结构化回执；默认输出自动清理。
完整累计入口须在 Git 工作树中运行，并依赖仓库级 `scripts/verify_reverse_v1.py` 及其索引/卡片。
给审查者的 55 文件裁剪副本只是只读审查输入，不是可独立重放全仓门的制品；回执记录实际工作树
与所有被执行脚本的输入哈希，父级另外对照冻结候选复算，不把打印 BINDING 当预先批准的 manifest。
所有原件访问仅为读取 ELF；不装载或执行原件，不运行 ART/Unicorn，不启动游戏。

分项入口：

- `tools/test_json.py`：13 个具名断言，host/ARM32 各执行基线、4 个语义变异及 1 个 no-op。
- `tools/test_atlas.py`：两种构建各 8 个具名断言，host/ARM32 各执行
  4 个 boundary 语义变异、3 个 helper 语义变异及 boundary no-op。
  公共事件时钟验证 atlas 的 free 晚于最后一个 region；另外分别变异 page/region 的真实释放顺序。
- `tools/test_chain.py`：纹理回调的四个具名场景、5 个变异与 no-op；
  扩展消费者四个场景、4 个依赖/重读变异与 no-op，均跑 host/ARM32。
  另验证缺失图形 provider 必须链接失败，不能静默空实现。
- `tools/test_gate_contracts.py`：缺 qemu-arm 必须拒绝；`python -O` 不能移除断言后假通过。

消费者场景覆盖有内容资源图、不拥有 loader 的空 atlas、NULL atlas/data，以及空析构；
每个非空场景还复验重复 Clear。合成回调主动改写 JSON 字段、page 的 name/next，
以具名断言拒绝提前缓存/错误释放次序。崩溃或编译失败不计为语义变异命中。

## original_gap

`spAtlas_create`、`spSkeletonJson_readSkeletonData`、attachment-loader 的工厂/析构、
`spSkeletonData_dispose`、`_calloc/_free` 与 `GR_Texture_Free` 的实际实现仍是边界。
调用实参与次序已用具型 provider 检查，不能因此声称这些依赖已恢复、GPU 已释放真实资源，
或全库/游戏玩法等价。分配失败/异常、跨 32 位地址回绕、真实 parser 的全部对象图及
原件同初态差分也未认证。全库锚点通过仅证明索引对应，不构成语义完成率。
