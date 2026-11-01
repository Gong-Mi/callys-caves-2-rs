# 原生静态精灵链施工记录

- 已接入：Sprite_Data、Sprite_Number、Sprite_Exists、CSprite::Clear、CSprite::LoadFromChunk 的静态 C 候选。
- 本批：Loader 共用 Clear 布局并导出原 mangled 入口；修复 host 两处8B宽写，T27/T28 先失败后通过；候选及依赖边界见 `../reverse-v1/c/csprite_loadfromchunk/README.md`。
- 证据档位维持 bytecode_anchored；合成夹具仅 test_anchored，不升级为原版行为等价。
- 后续批已接入：FreeMask、FreeTexture、ClearSWFData，并在同一 ARM32/host 合成消费者中与真实 Loader/Clear 译文串联；修复两处条件码误译与零记录数漏释放。
- 待接：骨骼构造/析构；未闭合的 SWF 构建、真实分配器与图形依赖仍单列。
- 用户阶段门不变：先静态语义/译文，不运行原件、ART 或 Unicorn。
