# 原生静态精灵链施工记录

- 已接入：Sprite_Data、Sprite_Number、Sprite_Exists、CSprite::Clear、CSprite::LoadFromChunk 的静态 C 候选。
- 本批：Loader 共用 Clear 布局并导出原 mangled 入口；修复 host 两处8B宽写，T27/T28 先失败后通过；候选及依赖边界见 `../reverse-v1/c/csprite_loadfromchunk/README.md`。
- 证据档位维持 bytecode_anchored；合成夹具仅 test_anchored，不升级为原版行为等价。
- 后续批已接入：FreeMask、FreeTexture、ClearSWFData，并在同一 ARM32/host 合成消费者中与真实 Loader/Clear 译文串联；修复两处条件码误译与零记录数漏释放。
- 后续批已接入：骨骼构造/析构及 SimpleDecode；保留正常返回 this 与 C1/C2、D1/D2 同址别名，匿名上下文存储强制由宿主绑定。host/ARM32 实际跑通 Loader→构造→解码→spine合成边界→Clear→析构。
- 本批接入：spine JSON 的 createWithLoader/create/dispose、atlas/page/region 的 dispose，以及 page 纹理回调，共七个按地址去重的原件入口。新增消费者直接链接这批译文并从 Loader→构造/解码→Clear→析构跑通，保留字段重读、两链释放和图形旗标窗口；分项静态合同、具名负控与边界见 `../reverse-v1/c/spine_lifetime/README.md`。
- 当前批继续接入：allocation 六入口、attachment-loader 四入口、skeletonData 创建/完整释放及直接依赖十三入口，保留原件字节/ABI/字段序的逐函数记录；`c/check-native-spine.sh` 直接构建四个ARM32重建物检查，不是原件oracle。真实C累积链已消除旧JSON与loader的void*/struct*声明冲突，allocator默认单参libc符号以明确AAPCS边界转发，不用不兼容C函数指针调用。
- 当前批候选：attachment工厂/分派/具体销毁十九入口，Atlas三个公开入口+六个去符号helper；统一12/44/80B共享布局、mesh真实vertex基类和旧raw-word读的alias合同。新atlas_parse_chain直接消费解析出的region，不使用合成atlas创建结果；主构建入口现跑八个ARM32程序。独立审查及F1窄修缮已核销，但不能将候选数量当全库完成。
- 本轮定死的细节：CMP后非S的MOV/LDRB/ADD不改NZCV；delimiter末字节会比较，失败会额外读end，EOF零Str会故障；indexOf只有两参且固定八项。保留未初始化tuple字、abort的path泄漏和原VFP舍入/累计标志/高度写入顺序，不安全化。
- 待接：库内_spAtlasPage_createTexture@0xbd6e4/304B、JSON实际解析、owner字段生产者、其余attachment/timeline、SWF构建与图形依赖；全库函数与匿名区域仍按METHOD第0节继续，不以这批本体数量报完工。
- 用户阶段门不变：先静态语义/译文，不运行原件、ART 或 Unicorn。

当前局部依赖图（候选与验收分账，不是全库人口图）：

    SimpleDecode / CSkeletonSprite已恢复
        ├─ Atlas create三入口+六helper候选 → 工厂十九入口候选 → 真实附件销毁
        │      └─ _spAtlasPage_createTexture 304B：独占子线恢复中，尚未验收
        ├─ JSON create/dispose已恢复 → JSON readSkeletonData：未恢复
        └─ data/atlas完整释放已恢复 → 其余timeline/顶点消费者：未恢复

工厂与解析候选的独立字节审查已核销，新消费者与调用帧门已运行；原件等价和全库闭合仍未认证。
