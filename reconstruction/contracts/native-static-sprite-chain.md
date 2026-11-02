# 原生静态精灵链施工记录

- 已接入：Sprite_Data、Sprite_Number、Sprite_Exists、CSprite::Clear、CSprite::LoadFromChunk 的静态 C 候选。
- 本批：Loader 共用 Clear 布局并导出原 mangled 入口；修复 host 两处8B宽写，T27/T28 先失败后通过；候选及依赖边界见 `../reverse-v1/c/csprite_loadfromchunk/README.md`。
- 证据档位维持 bytecode_anchored；合成夹具仅 test_anchored，不升级为原版行为等价。
- 后续批已接入：FreeMask、FreeTexture、ClearSWFData，并在同一 ARM32/host 合成消费者中与真实 Loader/Clear 译文串联；修复两处条件码误译与零记录数漏释放。
- 后续批已接入：骨骼构造/析构及 SimpleDecode；保留正常返回 this 与 C1/C2、D1/D2 同址别名，匿名上下文存储强制由宿主绑定。host/ARM32 实际跑通 Loader→构造→解码→spine合成边界→Clear→析构。
- 本批接入：spine JSON 的 createWithLoader/create/dispose、atlas/page/region 的 dispose，以及 page 纹理回调，共七个按地址去重的原件入口。新增消费者直接链接这批译文并从 Loader→构造/解码→Clear→析构跑通，保留字段重读、两链释放和图形旗标窗口；分项静态合同、具名负控与边界见 `../reverse-v1/c/spine_lifetime/README.md`。
- 当前批继续接入：allocation 六入口、attachment-loader 四入口、skeletonData 创建/完整释放及直接依赖十三入口，保留原件字节/ABI/字段序的逐函数记录；`c/check-native-spine.sh` 直接构建四个ARM32重建物检查，不是原件oracle。真实C累积链已消除旧JSON与loader的void*/struct*声明冲突，allocator默认单参libc符号以明确AAPCS边界转发，不用不兼容C函数指针调用。
- 待接：atlas/JSON 的实际解析、具体attachment/timeline回调、SWF构建及库外图形实现；全库函数与匿名区域仍按METHOD第0节继续，不以这批本体数量报完工。
- 用户阶段门不变：先静态语义/译文，不运行原件、ART 或 Unicorn。
