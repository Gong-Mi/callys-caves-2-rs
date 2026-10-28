/* cally 逆向卡：Variable_Misc（Variable_GetName_Scope + Variable_BuiltIn_Add）（原版 libyoyo.so，armv7）
 * @func 0xd2228 0xd24d0  size 684  171 条（158 条指令 + 13 个字面量池字 0xd24a0..0xd24d0）
 * @func 0x1f4da8 0x1f504c  size 680  170 条（164 条指令 + 6 个字面量池字 0x1f5038..0x1f504c）
 * 级别: 正文（341/341 逐条锚定；两节各钉死一件事：
 *             ① 变量 id → 名字 的四张表与两道门（含表布局、边界行为、每个全局的 dynsym 名）；
 *             ② 内建变量 → 名字 的 16 B 表项四字段、固定 500 项的表、以及 name→id 的 hash map 与扩容。
 *             所有 .bss 地址都由文件内 GOT addend 直读，全局名取自 llvm-readelf --dyn-syms（不是猜的）。
 *             open 8 条见文末）
 * 符号: _Z22Variable_GetName_ScopePKcii
 *         → char const* Variable_GetName_Scope(char const* name, int type, int id)
 *       _Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b
 *         → void Variable_BuiltIn_Add(char const* name,
 *                                     bool (*getter)(CInstance*, int, RValue*),
 *                                     bool (*setter)(CInstance*, int, RValue*),
 *                                     bool flag)
 * 来源: libyoyo.so sha256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 *       （4,689,844 B，stripped，ELF32 ARM；.text 0xb6fd0..0x31bb7c，.got 0x3ed718..0x3f2000）
 * 锚表: asm/index-Variable_Misc_all.tsv（341 行 = 171 + 170；两段地址不相邻，中间隔 1,190,104 B）
 * 同层（全部来自 dynsym OBJECT，地址与大小逐字）:
 *       builtin_numb 0x753108(4) / builtin_variables 0x75310c(8000) / g_builtinVarLookup 0x7530fc(4)
 *       g_VarNamesInstance 0x47a18c(16) / g_VarNamesGlobal 0x47a19c(16) / g_VarNamesLocal 0x47a17c(16)
 *       g_instanceVarLookup 0x47a178(4) / g_numFunctionsForLocalVars 0x47a1ac(4)
 *       g_localVariableNamesForFunctions 0x47a1b0(4) / VarNumb 0x47a1b4(4) / VarNames 0x47a1b8(4)
 *       g_subFunctionsOption 0x544b5c(1) / g_fJSGarbageCollection 0x47f295(1)
 *       邻居卡: Code_Variable_Find_Name.c（低区间入口）、Code_Variable_Find_Slot_From_Name.c（Local/Global_Name）、
 *               Variable_GetValue.c（内建表 +4 getter 的读者）、Variable_Global_Init.c（globdecl / 表簇）
 *
 * ── §0 为什么两节放一张卡 ─────────────────────────────────────────────
 *   这两节是**同一条链的两端**，分开写会各缺一半证据：
 *     名字→id：Variable_BuiltIn_Add 把 name 塞进 map（0x7530fc），id 就是表下标；
 *      id→名字：Variable_GetName_Scope 拿 id 回来取字符串，内建域走同一张 16 B 表。
 *   两节共用的常量/全局只有三样：变量 id 基址 100000、16 B 表项、两张 .bss 表簇；把它们放一起才能逐条对齐。
 *
 * ── §1 变量 id 的两个域（本卡第一节只管右半边）────────────────────────
 *   Code_Variable_Find_Name 0xd25fc 是唯一的 id→名字入口，按 id 一刀切：
 *     id < 100000  → 尾跳 Variable_BuiltIn_Find_Name(id)（另一个族，已出卡：越界与负数返回
 *                    0x3527c8 "<unknown built-in variable>"）
 *     id >= 100000 → 尾跳本卡第一节 Variable_GetName_Scope(name, type, id)（0xd2614）
 *   本函数把 id 统一换成 slot：
 *     0xd2268 sub r7,r2,#99328 / 0xd226c subs r7,r7,#672   ⇒ r7 = id - 100000
 *   注意顺序：**先过门 1，再判下界**（0xd2264 在 0xd2270 之前）—— 门 1 关着时连
 *   "id<100000" 的判定都不做，直接进 Variable_GetName(id)（那个函数自己会兜底成 "<unknown variable>"）。
 *
 * ── §2 名字域枚举的两种编码（同一批域，两套数字）──────────────────────
 *   本函数的第 2 参 type 是负数枚举；New_Code_Variable_Find(name, EVariableType) 0xd20c0 用的是 0..3。
 *   两边指向同一批表，所以可以互证：
 *     type = -5  → g_VarNamesGlobal      0x47a19c   ←→ EVariableType 0 = 全局
 *     type = -1  → g_VarNamesInstance    0x47a18c   ←→ EVariableType 1 = 实例（本地）
 *     type = -7  → 函数名键的局部表                 ←→ EVariableType 2 = 函数内局部
 *     type = -12 → 与 -7 同路（同一段代码，0xd227c 的 cmn #12 与 0xd2280 的 cmn #7 汇合）
 *     type ∈ {-9,-11}、以及任何 > 100000 的 type → 归并到实例域（0xd23d4 的 bic/orr 归一化）
 *   New_Code_Variable_Find 的 EVariableType 里还有一个 3：先试实例（(type&~2)==1 把 1、3 都算进来，0xd20e0/0xd20e4），
 *   失败再试全局（0xd20ec 的 cmp r5,#3）。⇒ 3 = “实例优先、再全局”，不是第三张表。
 *   调用点（决定 name 是谁）：
 *     -7  DoPushLocal   0xd4b24  r0=[VMExec+0x34]、r1=~6=-7、r2=id
 *     -5  DoPushGlobal  0xd4cc8  r0=[VMExec+0x34]、r1=~4=-5
 *     -5  Variable_Global_GetVar 0x1f39f8  r0=0
 *     -11 Variable_Scope_DeleteVar 0x1f3548 / Variable_Scope_SetVar 0x1f3664  r0=0
 *     -9  YYObject_PropertyNameIterator::NextInternal 0x240230  r0=字符串常量
 *     -1  F_VariableInstanceGetNames 0x119960 / CInstance::Dump 0x193d54 /
 *         CVariableList::Serialise 0x1f55c0 / OutputVariable 0x1f5a68  r0=0（或常量）
 *     -12 **没有**直接调用点：DoPop 那 11 个 bl 的 r1 是动态寄存器（0xe6780 mov r1,r9），
 *         所以 -12 只能从 VM 层流进来；本卡只证代码里为它留了一条路（open 3）。
 *
 * ── §3 分派树（伪 C，逐条对锚点）────────────────────────────────────
 *   const char* Variable_GetName_Scope(const char* name, int type, int id) {
 *       if (!g_subFunctionsOption) return Variable_GetName(id);        // 门 1，0xd2264
 *       if (id < 100000) return "<unknown variable>";                  // 0xd2270
 *       int slot = id - 100000;
 *       if (type == -5)  return GlobalName(slot);                      // 0xd23a8
 *       if (type == -7 || type == -12) return LocalFnName(name, slot); // 0xd2288
 *       if (type == -1)  return InstanceName(slot);                    // 0xd231c
 *       if ((type & ~2) == -11 || type > 100000) return InstanceName(slot); // 0xd23d4
 *       return "<unknown variable>";
 *   }
 *   两个子程序：
 *     GlobalName(slot)    slot>=count → unknown；slot<size → data[slot]；否则 NULL
 *     InstanceName(slot)  slot<count  → data[slot]（可能是 NULL）；否则在 map 上按 value 反查 key
 *     LocalFnName(name,slot)  strcmp 命中 entry->name → entry->names[slot]（**无边界检查**）；
 *                             未命中且门 2 开 → Script_Find_Parent(name) → snprintf "gml_Script_%s"
 *                             → 用新名字重扫同一张表；再不中 → unknown
 *
 * ── §4 四张名字表（形状 + 边界行为）────────────────────────────────
 *   A 全局：g_VarNamesGlobal 0x47a19c 16 B = { int size@0; int count@4; ?@8; char** data@0xc }
 *       读者：0xd23a8（本卡）、Code_Variable_Find_Slot_From_Name 0xd2054（线性 strcmp，返回下标）
 *       边界：先 count 后 size 两道检查 ⇒ 越界 slot 一定返回 NULL 或 unknown，不会读出去。
 *   B 实例：g_VarNamesInstance 0x47a18c 16 B，同构
 *       slot<count → data[slot]；**slot>=count 不报错**，改去 map 反查（等价“动态加的名字”）
 *   C 实例反查 map：g_instanceVarLookup 0x47a178(4) = CHashMap<const char*,int,7>*
 *       反查方式不是 hash，而是**整表线性扫**：i 从 count-1 递减，取第 i 个“占用项”（hash>0），
 *       比 entry->value==slot ⇒ 返回 entry->key。O(n²) 的写法（0xd2350..0xd2394）。
 *   D 函数名键的局部表：g_numFunctionsForLocalVars 0x47a1ac(count) + g_localVariableNamesForFunctions 0x47a1b0(数组)
 *       元素 12 B = { char* name@0; int count@4; char** names@8 }；本函数只读 +0（0xd22c0 strcmp）
 *       与 +8（0xd22d4/0xd22d8），+4 的 count 由 New_Code_Variable_Find 0xd2168 读
 *       命中判据是 strcmp(entry->name, name)，**key 是脚本/函数名**，不是变量名；
 *       取值 = names[slot]，没人与 entry->count 比 —— 这是本卡唯一的越界读（open 1）。
 *   另有第三套 {count, names} 对 VarNumb 0x47a1b4 / VarNames 0x47a1b8，是门 1 出口
 *   Variable_GetName(id) 的落点（0xd1d18/0xd1d2c 取它俩），写者是 Code_Variable_Init 0xd1d80 一族；
 *   本卡只标这条链的去向，不展开那套表。
 *
 * ── §5 局部名表从哪来（Code_Variable_Read_Local_Names 0xd24d4，紧跟本节之后）──
 *   它读一段自描述的字节流：count=*(u32*)p; p+=4；其后 count 条记录，每条 = { u32 n; u32 name_off; }
 *   再接 n 条子记录 { u32 ?; u32 off; }（每条 8 B，串偏移一律在**第 2 个字**）。
 *   字符串统一按 *(*(0x3ed94c))（串基址：GOT → 指针 → 基址）+ off 取，逐条 YYStrDup 复制（0xd254c/0xd25ac）。
 *   写成：0x47a1b0 = Alloc(count*12)（0xd24f8）、0x47a1ac = count（0xd251c）、
 *         每项 name = YYStrDup(base+off)（0xd255c）、count = n（0xd2564）、names = Alloc(n*4)（0xd2570/0xd2578）。
 *   唯一调用点：FUNC_Load 0x1dced4 ⇒ **局部变量名是随 game.droid 的 FUNC 段一起进来的**，
 *   与 §6 的“内建变量名由引擎自己注册”形成对照。
 *
 * ── §6 16 B 表项四字段（第二节的核心）──────────────────────────────
 *   builtin_variables 0x75310c，项长 16，**固定 500 项 = 8000 B**（dynsym size 就是 8000）：
 *     +0x0  char*  name      —— YYStrDup 的副本，表拥有；释放点是 FINALIZE_Variable_Main 0x1f4d30
 *     +0x4  fn     getter    —— bool (*)(CInstance*, int arrindex, RValue* out)；Variable_GetValue_Direct
 *                               0x1f3bf8 取 +4 后 blx，实参 (obj, arrindex, out) 逐字对齐
 *     +0x8  fn     setter    —— 同型；Variable_SetValue_Direct 0x1f3ca4 取 +8 后 blx
 *     +0xc  uint8  writable  —— **等于 (setter != NULL)**，不是第 4 实参：0x1f4e14 adds / 0x1f4e1c movne
 *                               算出 1 位，0x1f4e3c strb 落到这里；读者是 Variable_SetValue_Direct 0x1f3c4c
 *                               （ldrb +0xc，为 0 直接返回 0，连 setter 都不看）
 *   四个字段的写入序（0x1f4e38 name → 0x1f4e3c writable → 0x1f4e40 getter/setter，stmib 一次写两格）
 *   是**先整项写好、再插 map、最后 count++**，所以任何时刻 map 里的 value 都指向一个已经完整的表项。
 *   调用点共 212 个（210 bl + 2 b）：InitYoYoBuiltInVariables 6（全部 r2=0，无 setter，末条是尾跳）、
 *   InitLocalVariables 86、InitGlobalVariables 120。6+86+120 = 212。
 *   ★ 第 4 实参 flag 是死参数：函数**第一条指令**（0x1f4da8 ldr r3,[pc,#0x28c]）就把 r3 覆盖了，
 *     全函数再没有任何地方读它。212 个调用点里 r2(setter)=0 的站点多数传 r3=0、setter 走 GOT 的多数传 r3=1，
 *     但有 7 处不遵守这个相关性 —— 说明它既不是“由 setter 派生”，也确实没被消费（它写的是 +0xc，而 +0xc 由 setter 算）。
 *
 * ── §7 名字域 hash map：形状与扩容（第二节的“扩容”）────────────────
 *   g_builtinVarLookup 0x7530fc 是**指针变量**，指向 20 B 的 CHashMap<const char*,int,7>：
 *     +0x0 int cap        +0x4 int count      +0x8 int mask(=cap-1)
 *     +0xc int threshold  +0x10 entry* entries（项 12 B = {key@0, value@4, hash@8}）
 *   建立点 INITIALIZE_Variable_BuiltIn 0x1ffbd0：new(20) 0x1ffbd8、cap=128 0x1ffbe4、mask=127 0x1ffbe8、
 *   entries=Alloc(1536)=128*12 0x1ffc0c、count=0 0x1ffc28、threshold=(int)(0.6*128) 0x1ffc40、
 *   回写 g_builtinVarLookup 0x1ffc80；紧接着 memset(builtin_variables,0,8000) 0x1ffc84。
 *   扩容（0x1f4f34 起，条件 map->count > map->threshold）：
 *     cap←2c、mask←2c-1、entries←Alloc(24c)、memset、count←0、threshold←(int)(0.6*2c)、
 *     旧表逐条 CHashMap::Insert 重插（0x1f4fec）、Free 旧块（0x1f5000）、重算 threshold（0x1f501c）、
 *     回到插入（0x1f5020）。0.6f = 0x3f19999a（池 0x1f5038）。
 *   插入本身是 **Robin Hood 开放寻址**（内联在 0x1f4e48..0x1f4f18）：
 *     hash = CHashMapCalculateHash<const char*>(name) & 0x7fffffff（清符号位 ⇒ 0 是空槽哨兵）
 *     比距离（0x1f4ec8..0x1f4ed4 用 idx+cap-home 再 &mask 求环形距离），占用项更“穷”就交换（0x1f4edc）
 *     距离相同比 hash，hash 相同**只比 key 指针**（0x1f4ef4 cmp r6,r5）⇒ 同内容不同指针不算重复键；
 *     真重复时覆盖 value 并把 count 减回来（0x1f4f04）。
 *   注册的 id 就是表下标：0x1f4e24 ldr r7,[count 地址]，map 的 value = r7（0x1f4ea0/0x1f4f00），
 *   count++ 在最后（0x1f4f28）。**表本身不扩容**：count == 500 时打
 *   "INTERNAL ERROR: Adding too many variables"（0x352854）后原样返回（0x1f4dcc cmp #500 用的是**相等**）。
 *
 * ── §8 已证（每条都指到指令）────────────────────────────────────────
 *   1. 两节范围与指令/池字配比：171 = 158 + 13（池 0xd24a0..0xd24d0）、170 = 164 + 6（池 0x1f5038..0x1f504c）。
 *   2. 门 1 = g_subFunctionsOption（0x544b5c）== 0 → 直返 Variable_GetName(id)（0xd2264/0xd239c）；
 *      全库只有 GOT 槽 0x3edb5c 指向 0x544b5c，5 个引用点里唯一的字节写点是 GetResolution 0x1dd828
 *      `strb r9,[r12]`，值 = (头块某字的 bits8..15 > 14)（0x1dd608 ubfx r9,r3,#8,#8 / 0x1dd808 cmp r9,#14；
 *      同一函数里该字节还与 7/9/10/11/12/13 逐个比较 ⇒ 像格式/版本号，未定名）。
 *   3. 门 2 = g_fJSGarbageCollection（0x47f295）≠ 0 才允许 Script_Find_Parent 兜底（0xd22ec/0xd22f0）。
 *   4. 四张域表与三个 CArray 布局：{size@0,count@4,?@8,data@0xc}（0xd23bc/0xd23c0/0xd23c4、0xd232c、0xd23b0）。
 *   5. 实例域的反查是**整表线性扫 value**，不是 hash 查（0xd2350..0xd2394）；命中返回 key（0xd238c）。
 *   6. 局部域按**脚本/函数名**作键，元素 12 B；取值 names[slot] 不做 entry->count 检查（0xd22d4/0xd22d8）。
 *   7. 16 B 表项四字段：name@0 / getter@4 / setter@8 / writable@0xc=(setter!=0)；第 4 实参是死参数（0x1f4da8）。
 *   8. 表固定 500 项（8000 B）；count==500 走 ShowMessage 尾跳，不扩容（0x1f4dcc/0x1f4dd0/0x1f5024..0x1f5034）。
 *   9. name→id 的 map 从 128 桶起、负载因子 0.6、12 B 项、Robin Hood 探测、cap 翻倍（0x1ffbe4..0x1ffc40、0x1f4f34..0x1f5020）。
 *
 * ── §9 open ───────────────────────────────────────────────────────
 *   1. 局部域 names[slot] 没有任何边界检查（0xd22d8）。slot 由调用者给的 id 决定，若 id 属于别的脚本，
 *      就会读到该 entry 的 names 数组之外。可达性未证（正常编译器的 id 与脚本一一对应）。
 *   2. 实例域“slot>=count 就去 map 反查”的**原因**未证：按 Code_Variable_FindAlloc_Slot_From_Name 的写法，
 *      数组与 map 是同步追加的，理论上不会出现 count 落后于 map 的状态；只在“数组被外部改写/名字被释放”时才需要这条路。
 *   3. -12 没有直接调用点（DoPop 的 r1 是寄存器）。它与 -7 走同一段代码，差别只在枚举值本身；哪个 VM 分支产出 -12 未查。
 *   4. -9/-11 为什么归并到实例域：只证 0xd23d4 的 (type & ~2) == -11 判据成立（-9/-11 同为真），语义动机未证。
 *   5. Script_Find_Parent 返回的 CScript+0x14 被当脚本名喂给 "gml_Script_%s"，但 +0x14 是名字字段这件事
 *      只有“用法 + 格式串”两条旁证，没有独立字段卡；snprintf 的截断/返回值也没人检查。
 *   6. 门 2 与 GC 开关是同一个字节 0x47f295（dynsym 名 g_fJSGarbageCollection）：本卡只证它在名字解析里
 *      充当“允许父脚本兜底”，与它同时充当 GC 开关这件事的关系未证。
 *   7. 表项 +0xc 是否**只**等于 (setter!=NULL)：本卡只证注册时这样算、SetValue_Direct 这样读；
 *      运行期是否有别的写点（本卡未扫到）未证。
 *   8. g_VarNamesLocal 0x47a17c(16) 的读者未定位：本函数实例域用的是 g_VarNamesInstance 0x47a18c，
 *      两者 dynsym 名只差 Local/Instance 一个词，分工未证（0x47a17c 只在 dynsym 里被本卡引用，未找到可靠访问点）。
 *
 * ── 逐条锚点（第一节 · Variable_GetName_Scope 0xd2228..0xd24d0）──────
 */

/* ═══ 段 1 · 序言 + canary + 门 1（0xd2228..0xd2264）═══
 *   帧 4108 B = 4096（snprintf 缓冲）+ 12；canary 来自 __stack_chk_guard（GOT 0x3ed958，R_ARM_GLOB_DAT）。
 *   门 1 在**所有**判定之前：g_subFunctionsOption 为 0 就整条短路。
 */
/* @0xd2228 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */  —— 序言：9 个寄存器 + lr（本函数有 bl，必须保存 lr；与 Code_Variable_Find_Name 的尾跳形态不同）
/* @0xd222c sub sp, sp, #4096 */  —— 帧下半：4096 B —— snprintf 缓冲用
/* @0xd2230 ldr r8, [pc, #0x268] */  —— 取 GOT 相对偏移字
/* @0xd2234 sub sp, sp, #12 */  —— 帧上半 12 B：缓冲前的 4 B + canary 4 B + 8 B 对齐的补 4 B（合计 4108）
/* @0xd2238 ldr r3, [pc, #0x264] */  —— __stack_chk_guard 槽偏移（池 0xd24a4 = 0xffffbd00 → -0x4300）
/* @0xd223c mov r9, r0 */  —— r9 = name（第一实参；后面 0xd2414 被复用成缓冲基址）
/* @0xd2240 add r8, pc, r8 */  —— ★r8 = 0xd2248 + 0x31fa10 = 0x3f1c58（.got 基址；与 Variable_GetValue 卡同一锚点）
/* @0xd2244 ldr r12, [pc, #0x25c] */  —— g_subFunctionsOption 槽偏移（池 0xd24a8 = 0xffffbf04 → -0x40fc）
/* @0xd2248 add r0, sp, #8192 */  —— 取帧顶（sp+8192）
/* @0xd224c ldr r6, [r8, r3] */  —— r6 = *(0x3ed958) = &__stack_chk_guard（该槽是 R_ARM_GLOB_DAT）
/* @0xd2250 ldr r3, [r6] */  —— r3 = canary 值
/* @0xd2254 str r3, [r0, #-0xffc] */  —— canary 落到 sp+4096+4 = 帧顶 4 B
/* @0xd2258 ldr r3, [r8, r12] */  —— r3 = *(0x3edb5c) = 0x544b5c = g_subFunctionsOption（dynsym 名，1 B）
/* @0xd225c ldrb r3, [r3] */  —— 读门字节
/* @0xd2260 cmp r3, #0 */  —— cmp
/* @0xd2264 beq 0xd239c <_Z22Variable_GetName_ScopePKcii+0x174> */  —— ★门 1：g_subFunctionsOption == 0 → 不碰任何名字表，直接 Variable_GetName(id)

/* ═══ 段 2 · id 下界与 type 首判（0xd2268..0xd2284）═══
 *   r7 = id-100000（两段减：99328 + 672）；先判下界，再按 -5 / -12 / -7 分派。
 */
/* @0xd2268 sub r7, r2, #99328 */  —— r7 = id - 99328
/* @0xd226c subs r7, r7, #672 */  —— r7 = r7 - 672 ⇒ r7 = id-100000（100000 = 变量 id 基址）；subs 置标志
/* @0xd2270 bmi 0xd22f4 <_Z22Variable_GetName_ScopePKcii+0xcc> */  —— ★id < 100000 → 0xd22f4 "<unknown variable>"：内建域不归本函数
/* @0xd2274 cmn r1, #5 */  —— type == -5 ?（cmn #5 ⇔ r1+5==0）
/* @0xd2278 beq 0xd23a8 <_Z22Variable_GetName_ScopePKcii+0x180> */  —— 是 → 全局名表
/* @0xd227c cmn r1, #12 */  —— type == -12 ?
/* @0xd2280 cmnne r1, #7 */  —— 否则 type == -7 ?
/* @0xd2284 bne 0xd231c <_Z22Variable_GetName_ScopePKcii+0xf4> */  —— 都不是 → 0xd231c（-1 与“其它”归并）

/* ═══ 段 3 · 局部域：函数名键表线性扫描（0xd2288..0xd22dc）═══
 *   表 = {count@0x47a1ac, array@0x47a1b0}；元素 12 B {name@0, count@4, names@8}。
 *   命中判据 strcmp(entry->name, name)，name 是脚本/函数名；取值 names[slot]，**不查 entry->count**。
 */
/* @0xd2288 ldr r3, [pc, #0x21c] */  —— g_numFunctionsForLocalVars 槽（池 0xd24ac = 0xffffbf5c → -0x40a4）
/* @0xd228c ldr r11, [r8, r3] */  —— r11 = 0x47a1ac（**count 的地址**，不是数组）
/* @0xd2290 ldr r10, [r11] */  —— count
/* @0xd2294 cmp r10, #0 */  —— cmp
/* @0xd2298 ble 0xd22e0 <_Z22Variable_GetName_ScopePKcii+0xb8> */  —— 表空 → 门 2
/* @0xd229c ldr r3, [pc, #0x20c] */  —— g_localVariableNamesForFunctions 槽（池 0xd24b0 = 0xffffbf60 → -0x40a0）
/* @0xd22a0 mov r5, #0 */  —— i = 0
/* @0xd22a4 ldr r3, [r8, r3] */  —— r3 = 0x47a1b0（**数组指针的地址**）
/* @0xd22a8 ldr r4, [r3] */  —— r4 = 数组基址
/* @0xd22ac b 0xd22c0 <_Z22Variable_GetName_ScopePKcii+0x98> */  —— 进循环头（先判空再比）
/* @0xd22b0 add r5, r5, #1 */  —— ++i
/* @0xd22b4 add r4, r4, #12 */  —— 下一项：元素步长 **12 B**
/* @0xd22b8 cmp r5, r10 */  —— cmp
/* @0xd22bc beq 0xd22e0 <_Z22Variable_GetName_ScopePKcii+0xb8> */  —— 扫完未命中 → 门 2
/* @0xd22c0 ldr r0, [r4] */  —— entry->name（+0）
/* @0xd22c4 mov r1, r9 */  —— strcmp 的第 2 参 = 第一实参 name（脚本/作用域名）
/* @0xd22c8 bl 0xb6574 <strcmp@plt> */  —— strcmp@plt
/* @0xd22cc cmp r0, #0 */  —— cmp
/* @0xd22d0 bne 0xd22b0 <_Z22Variable_GetName_ScopePKcii+0x88> */  —— 不等 → 下一项
/* @0xd22d4 ldr r3, [r4, #0x8] */  —— entry->names（+8，char**）
/* @0xd22d8 ldr r0, [r3, r7, lsl #2] */  —— ★names[slot]（slot = id-100000）；**没有与 entry->count 比较** —— 越界读口子
/* @0xd22dc b 0xd22fc <_Z22Variable_GetName_ScopePKcii+0xd4> */  —— → 统一出口 0xd22fc

/* ═══ 段 4 · 门 2 与 unknown 兜底（0xd22e0..0xd22f8）═══
 *   门 2 = g_fJSGarbageCollection（0x47f295）；为 0 就到此为止。
 *   "<unknown variable>" = 0x332760（与内置域的 "<unknown built-in variable>" 0x3527c8 不是同一个串）。
 */
/* @0xd22e0 ldr r3, [pc, #0x1cc] */  —— 门 2 槽：g_fJSGarbageCollection（池 0xd24b4 = 0xffffbf68 → -0x4098 → 0x47f295）
/* @0xd22e4 ldr r3, [r8, r3] */  —— 取 0x47f295 的地址
/* @0xd22e8 ldrb r3, [r3] */  —— 读字节
/* @0xd22ec cmp r3, #0 */  —— cmp
/* @0xd22f0 bne 0xd2404 <_Z22Variable_GetName_ScopePKcii+0x1dc> */  —— ★门 2：≠0 才允许走 Script_Find_Parent 兜底；==0 直接 unknown
/* @0xd22f4 ldr r0, [pc, #0x1bc] */  —— 池 0xd24b8 = 0x00260460
/* @0xd22f8 add r0, pc, r0 */  —— r0 = 0xd2300 + 0x260460 = 0x332760 "<unknown variable>"

/* ═══ 段 5 · 唯一出口（canary 校验）（0xd22fc..0xd2318）═══
 *   6 条 b/beq（0xd22dc、0xd238c、0xd23a4、0xd23d0、0xd2480、0xd248c）+ 0xd22f8 的直落共 7 条来路
 *   全汇到这里：先比 canary，再拆帧 pop（唯一 pop）。失败侧的 6 条都先去 0xd22f4 取 unknown 串。
 */
/* @0xd22fc add r3, sp, #8192 */  —— 统一出口：取 canary 槽
/* @0xd2300 ldr r2, [r3, #-0xffc] */  —— canary 现值
/* @0xd2304 ldr r3, [r6] */  —— r3 = *(&__stack_chk_guard)
/* @0xd2308 cmp r2, r3 */  —— cmp
/* @0xd230c bne 0xd2490 <_Z22Variable_GetName_ScopePKcii+0x268> */  —— 不符 → __stack_chk_fail
/* @0xd2310 add sp, sp, #4096 */  —— 拆帧（下）
/* @0xd2314 add sp, sp, #12 */  —— 拆帧（上）
/* @0xd2318 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */  —— ★全函数唯一 pop：7 条来路（5 条 b/beq：0xd22dc、0xd238c、0xd23a4、0xd23d0、0xd2480、0xd248c 里的 b 与 beq 各一，加 0xd22f8 的直落）

/* ═══ 段 6 · 实例域：数组直取 + map 反查（0xd231c..0xd2398）═══
 *   slot<count → data[slot]；否则在 g_instanceVarLookup 上**线性反查** value==slot。
 *   内层 0xd2368 的“只挪指针不加 j”是“跳过空槽”，等价于取第 i 个占用项。
 */
/* @0xd231c cmn r1, #1 */  —— type == -1 ?（cmn #1）
/* @0xd2320 bne 0xd23d4 <_Z22Variable_GetName_ScopePKcii+0x1ac> */  —— 不是 → 0xd23d4 归一化
/* @0xd2324 ldr r3, [pc, #0x190] */  —— g_VarNamesInstance 槽（池 0xd24bc = 0xffffbf50 → -0x40b0）
/* @0xd2328 ldr r3, [r8, r3] */  —— r3 = 0x47a18c（16 B CArray 本体）
/* @0xd232c ldr r2, [r3, #0x4] */  —— count（+4）
/* @0xd2330 cmp r7, r2 */  —— slot vs count
/* @0xd2334 blt 0xd23bc <_Z22Variable_GetName_ScopePKcii+0x194> */  —— slot < count → 0xd23bc 直取 data[slot]
/* @0xd2338 ldr r3, [pc, #0x180] */  —— g_instanceVarLookup 槽（池 0xd24c0 = 0xffffbf54 → -0x40ac）
/* @0xd233c ldr r3, [r8, r3] */  —— r3 = 0x47a178（**map 指针变量**）
/* @0xd2340 ldr r5, [r3] */  —— r5 = map 对象
/* @0xd2344 ldr r4, [r5, #0x4] */  —— r4 = map->count（+4）
/* @0xd2348 subs r12, r4, #1 */  —— r12 = count-1（反查上界）
/* @0xd234c bmi 0xd22f4 <_Z22Variable_GetName_ScopePKcii+0xcc> */  —— count == 0 → unknown
/* @0xd2350 cmp r4, r12 */  —— cmp count, count-1
/* @0xd2354 blt 0xd2494 <_Z22Variable_GetName_ScopePKcii+0x26c> */  —— count < count-1 只在 count==INT_MIN 成立 ⇒ 实质不可达；落点 0xd2494 会把 r3 置 0 再去 ldr（见下）
/* @0xd2358 ldr r3, [r5, #0x10] */  —— map->entries（+0x10）
/* @0xd235c mov r2, #0 */  —— j = 0
/* @0xd2360 b 0xd236c <_Z22Variable_GetName_ScopePKcii+0x144> */  —— 进“找第 i 个占用项”的循环
/* @0xd2364 add r2, r2, #1 */  —— ++j（只在占用项上推进）
/* @0xd2368 add r3, r3, #12 */  —— 指针 +12（跳过空槽时只挪指针、不加 j）
/* @0xd236c ldr r1, [r3, #0x8] */  —— entry->hash（+8）；0 = 空槽
/* @0xd2370 cmp r1, #0 */  —— cmp
/* @0xd2374 ble 0xd2368 <_Z22Variable_GetName_ScopePKcii+0x140> */  —— 空槽 → 只挪指针
/* @0xd2378 cmp r12, r2 */  —— 已到第 i 个占用项？
/* @0xd237c bne 0xd2364 <_Z22Variable_GetName_ScopePKcii+0x13c> */  —— 没到 → ++j 继续
/* @0xd2380 ldr r0, [r3], #4 */  —— r0 = entry->key（+0）；r3 自动 +4
/* @0xd2384 ldr r3, [r3] */  —— r3 = entry->value（+4）= 该名字的 slot
/* @0xd2388 cmp r3, r7 */  —— value == slot ?
/* @0xd238c beq 0xd22fc <_Z22Variable_GetName_ScopePKcii+0xd4> */  —— ★命中 → 返回 key（**反查**：slot → 名字）
/* @0xd2390 subs r12, r12, #1 */  —— --i
/* @0xd2394 bhs 0xd2350 <_Z22Variable_GetName_ScopePKcii+0x128> */  —— 无符号比较 ⇒ i>=0 继续（bhs）
/* @0xd2398 b 0xd22f4 <_Z22Variable_GetName_ScopePKcii+0xcc> */  —— 扫完 → unknown

/* ═══ 段 7 · 门 1 出口（0xd239c..0xd23a4）═══
 *   name/type 全部作废：只把 id 交给 Variable_GetName（那套表是 VarNumb/VarNames 0x47a1b4/0x47a1b8）。
 */
/* @0xd239c mov r0, r2 */  —— 门 1 出口：id 顶到首参（name/type 全部作废）
/* @0xd23a0 bl 0xd1d04 <_Z16Variable_GetNamei> */  —— Variable_GetName(int)（0xd1d04）
/* @0xd23a4 b 0xd22fc <_Z22Variable_GetName_ScopePKcii+0xd4> */  —— → 统一出口（把它的返回值原样带出）

/* ═══ 段 8 · 全局域（0xd23a8..0xd23d0）═══
 *   g_VarNamesGlobal 0x47a19c；两道门（count 然后 size），越界给 NULL 而不是越界读。
 */
/* @0xd23a8 ldr r3, [pc, #0x114] */  —— g_VarNamesGlobal 槽（池 0xd24c4 = 0xffffbf4c → -0x40b4）
/* @0xd23ac ldr r3, [r8, r3] */  —— r3 = 0x47a19c（16 B CArray 本体）
/* @0xd23b0 ldr r2, [r3, #0x4] */  —— count（+4）
/* @0xd23b4 cmp r7, r2 */  —— slot vs count
/* @0xd23b8 bge 0xd22f4 <_Z22Variable_GetName_ScopePKcii+0xcc> */  —— slot >= count → unknown（全局域**没有** map 兜底）
/* @0xd23bc ldr r2, [r3] */  —— +0 = size（容量）—— 与 -1 路共用的取值块
/* @0xd23c0 cmp r7, r2 */  —— slot vs size
/* @0xd23c4 ldrlt r3, [r3, #0xc] */  —— slot < size → 取 data 指针（+0xc）
/* @0xd23c8 movge r0, #0 */  —— slot >= size → 返回 0（不越界，但也不是 unknown 串）
/* @0xd23cc ldrlt r0, [r3, r7, lsl #2] */  —— data[slot]（4 B 步长）
/* @0xd23d0 b 0xd22fc <_Z22Variable_GetName_ScopePKcii+0xd4> */  —— → 统一出口

/* ═══ 段 9 · 其它 type 的归一化（0xd23d4..0xd2400）═══
 *   (type&~2)==-11 ⇒ type∈{-9,-11}；type>100000 ⇒ 恒真。两者都归到实例域。
 */
/* @0xd23d4 bic r2, r1, #2 */  —— 归一化：r2 = type & ~2
/* @0xd23d8 movw r3, #0x86a0 */  —— movw r3, #0x86a0
/* @0xd23dc cmn r2, #11 */  —— cmp r2, #11 ⇔ (type&~2) == -11 ⇔ type ∈ {-9,-11}
/* @0xd23e0 movt r3, #0x1 */  —— movt r3, #0x1 ⇒ r3 = 100000
/* @0xd23e4 movne r2, #0 */  —— 不等 → 0
/* @0xd23e8 moveq r2, #1 */  —— 相等 → 1
/* @0xd23ec cmp r1, r3 */  —— type vs 100000
/* @0xd23f0 movle r3, r2 */  —— type <= 100000：必须落在 {-9,-11}
/* @0xd23f4 orrgt r3, r2, #1 */  —— type > 100000：恒真（**任何**大于 100000 的 type 都走实例域）
/* @0xd23f8 cmp r3, #0 */  —— cmp
/* @0xd23fc beq 0xd22f4 <_Z22Variable_GetName_ScopePKcii+0xcc> */  —— 其余 → unknown
/* @0xd2400 b 0xd2324 <_Z22Variable_GetName_ScopePKcii+0xfc> */  —— → 0xd2324（实例域：数组 + map 反查）

/* ═══ 段 10 · Script_Find_Parent 兜底 + 换名重扫（0xd2404..0xd248c）═══
 *   把 name 拼成 "gml_Script_%s"（CScript+0x14），再扫同一张局部表；snprintf 的返回值不看。
 */
/* @0xd2404 mov r0, r9 */  —— Script_Find_Parent 的第 1 参 = name
/* @0xd2408 bl 0x1e06dc <_Z18Script_Find_ParentPKc> */  —— Script_Find_Parent@0x1e06dc
/* @0xd240c cmp r0, #0 */  —— cmp
/* @0xd2410 beq 0xd22f4 <_Z22Variable_GetName_ScopePKcii+0xcc> */  —— 找不到父脚本 → unknown
/* @0xd2414 add r9, sp, #4 */  —— r9 = sp+4（4096 B 缓冲起点）
/* @0xd2418 ldr r2, [pc, #0xa8] */  —— 格式串偏移（池 0xd24c8 = 0x00260348）
/* @0xd241c ldr r3, [r0, #0x14] */  —— CScript+0x14（用作 %s：脚本名）
/* @0xd2420 mov r1, #4096 */  —— snprintf 上限 4096
/* @0xd2424 add r2, pc, r2 */  —— ★r2 = 0xd242c + 0x260348 = 0x332774 "gml_Script_%s"
/* @0xd2428 mov r0, r9 */  —— r0 = 缓冲
/* @0xd242c bl 0xb65c8 <snprintf@plt> */  —— snprintf@plt（返回值不看、截断不判）
/* @0xd2430 ldr r10, [r11] */  —— 重扫同一张表：count（r11 仍指 0x47a1ac）
/* @0xd2434 cmp r10, #0 */  —— cmp
/* @0xd2438 ble 0xd2484 <_Z22Variable_GetName_ScopePKcii+0x25c> */  —— 空 → unknown
/* @0xd243c ldr r3, [pc, #0x6c] */  —— g_localVariableNamesForFunctions 槽（池 0xd2? —— -0x40a0）
/* @0xd2440 mov r5, #0 */  —— i = 0
/* @0xd2444 ldr r3, [r8, r3] */  —— r3 = 0x47a1b0
/* @0xd2448 ldr r4, [r3] */  —— r4 = 数组基址
/* @0xd244c b 0xd2460 <_Z22Variable_GetName_ScopePKcii+0x238> */  —— 循环头
/* @0xd2450 add r5, r5, #1 */  —— ++i
/* @0xd2454 add r4, r4, #12 */  —— +12
/* @0xd2458 cmp r5, r10 */  —— cmp
/* @0xd245c beq 0xd2478 <_Z22Variable_GetName_ScopePKcii+0x250> */  —— 扫完 → unknown
/* @0xd2460 ldr r0, [r4] */  —— entry->name
/* @0xd2464 mov r1, r9 */  —— 第 2 参 = 缓冲（"gml_Script_<父脚本名>"）
/* @0xd2468 bl 0xb6574 <strcmp@plt> */  —— strcmp@plt
/* @0xd246c cmp r0, #0 */  —— cmp
/* @0xd2470 bne 0xd2450 <_Z22Variable_GetName_ScopePKcii+0x228> */  —— 不等 → 下一项
/* @0xd2474 b 0xd22d4 <_Z22Variable_GetName_ScopePKcii+0xac> */  —— ★命中 → 复用 0xd22d4 的取值块（names[slot]）
/* @0xd2478 ldr r0, [pc, #0x4c] */  —— unknown 串（池 0xd24cc = 0x002602dc）
/* @0xd247c add r0, pc, r0 */  —— r0 = 0x332760
/* @0xd2480 b 0xd22fc <_Z22Variable_GetName_ScopePKcii+0xd4> */  —— → 出口
/* @0xd2484 ldr r0, [pc, #0x44] */  —— unknown 串（池 0xd24d0 = 0x002602d0）
/* @0xd2488 add r0, pc, r0 */  —— r0 = 0x332760
/* @0xd248c b 0xd22fc <_Z22Variable_GetName_ScopePKcii+0xd4> */  —— → 出口

/* ═══ 段 11 · stack_chk_fail 与不可达的 0xd2494（0xd2490..0xd249c）═══
 *   0xd2494 是 0xd2354 的落点（count<count-1，只有 count==INT_MIN 成立）；它把 r3 置 0 后回到 0xd2384 的 ldr，必然 NULL 解引用。
 */
/* @0xd2490 bl 0xb65d4 <__stack_chk_fail@plt> */  —— canary 不符的唯一落点
/* @0xd2494 mov r0, #0 */  —— 0xd2354 的落点：key = 0
/* @0xd2498 mov r3, r0 */  —— r3 = 0
/* @0xd249c b 0xd2384 <_Z22Variable_GetName_ScopePKcii+0x15c> */  —— → 0xd2384 会 ldr [0]（NULL 解引用）⇒ 该路不可达，只作取证

/* ═══ 段 12 · 字面量池（13 字）（0xd24a0..0xd24d0）═══
 *   全部由文件内 addend 直读；0xd24a0/0xd24b8 等被反汇编器译成指令，按规矩保留原写法。
 */
/* @0xd24a0 eorseq pc, r1, r0, lsl r10 */  —— 池：GOT 基址偏移 0x0031fa10（0xd2240 消费 ⇒ 0x3f1c58）
/* @0xd24a4 .word 0xffffbd00 */  —— 池：-0x4300 → 槽 0x3ed958 __stack_chk_guard
/* @0xd24a8 .word 0xffffbf04 */  —— 池：-0x40fc → 槽 0x3edb5c g_subFunctionsOption
/* @0xd24ac .word 0xffffbf5c */  —— 池：-0x40a4 → 槽 0x3edbb4 g_numFunctionsForLocalVars
/* @0xd24b0 .word 0xffffbf60 */  —— 池：-0x40a0 → 槽 0x3edbb8 g_localVariableNamesForFunctions
/* @0xd24b4 .word 0xffffbf68 */  —— 池：-0x4098 → 槽 0x3edbc0 g_fJSGarbageCollection
/* @0xd24b8 eoreq r0, r6, r0, ror #8 */  —— 池：0x00260460 → 0x332760 "<unknown variable>"
/* @0xd24bc .word 0xffffbf50 */  —— 池：-0x40b0 → 槽 0x3edba8 g_VarNamesInstance
/* @0xd24c0 .word 0xffffbf54 */  —— 池：-0x40ac → 槽 0x3edbac g_instanceVarLookup
/* @0xd24c4 .word 0xffffbf4c */  —— 池：-0x40b4 → 槽 0x3edba4 g_VarNamesGlobal
/* @0xd24c8 eoreq r0, r6, r8, asr #6 */  —— 池：0x00260348 → 0x332774 "gml_Script_%s"
/* @0xd24cc .word 0x002602dc */  —— 池：0x002602dc → 0x332760 "<unknown variable>"
/* @0xd24d0 .word 0x002602d0 */  —— 池：0x002602d0 → 0x332760 "<unknown variable>"

/* ── 逐条锚点（第二节 · Variable_BuiltIn_Add 0x1f4da8..0x1f504c）──── */

/* ═══ 段 A · 入口 + 500 上限（0x1f4da8..0x1f4dd0）═══
 *   第一条 ldr 在 push 之前：既取 GOT 偏移，也顺手把第 4 实参 r3 覆盖掉（flag 从此不可达）。
 *   builtin_numb 是**计数**（不是容量），容量硬编码 500。
 */
/* @0x1f4da8 ldr r3, [pc, #0x28c] */  —— ★在 push **之前**执行：池 0x1f503c = 0x001f8e84（GOT 偏移）；★第 4 实参 r3(flag) 在这里就被覆盖 —— 全函数再没读过它
/* @0x1f4dac push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */  —— 序言：9 寄存器 + lr（有 5 个 bl）
/* @0x1f4db0 ldr r3, [pc, r3] */  —— ★r3 = 0x1f4db8 + 0x1f8e84 = 0x3edc3c → builtin_numb（**count 的地址**）
/* @0x1f4db4 sub sp, sp, #12 */  —— 帧 12 B：只为对齐 + [sp+4] 存 count 地址
/* @0x1f4db8 mov r6, r0 */  —— r6 = name（第 1 实参）
/* @0x1f4dbc mov r5, r1 */  —— r5 = getter（第 2 实参）
/* @0x1f4dc0 mov r9, r2 */  —— r9 = setter（第 3 实参）
/* @0x1f4dc4 str r3, [sp, #0x4] */  —— [sp+4] = &builtin_numb
/* @0x1f4dc8 ldr r3, [r3] */  —— r3 = count
/* @0x1f4dcc cmp r3, #500 */  —— ★表容量硬编码 500（= 8000 B / 16 B）
/* @0x1f4dd0 beq 0x1f5024 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b+0x27c> */  —— count == 500 → 0x1f5024（**相等**比较，不是 >=）

/* ═══ 段 B · 选槽（追加在 count）（0x1f4dd4..0x1f4e04）═══
 *   slot 永远是 count（追加），不复用旧槽；table[count].name 非空时先 Free —— 这是给“count 被回退过”留的防御。
 */
/* @0x1f4dd4 ldr r4, [pc, #0x264] */  —— 池 0x1f5040 = 0x001f8e60
/* @0x1f4dd8 ldr r4, [pc, r4] */  —— r4 = 0x1f4de0 + 0x1f8e60 = 0x3edc40 → builtin_variables（表基址）
/* @0x1f4ddc ldr r0, [r4, r3, lsl #4] */  —— entry = table + count*16；r0 = entry->name（+0）
/* @0x1f4de0 cmp r0, #0 */  —— cmp
/* @0x1f4de4 moveq r10, r3 */  —— 空槽 → slot = count
/* @0x1f4de8 beq 0x1f4e04 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b+0x5c> */  —— → 0x1f4e04
/* @0x1f4dec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */  —— 非空 → 先释放旧名（count 被回退过才可能出现的残留）
/* @0x1f4df0 ldr r3, [sp, #0x4] */  —— 取 count 地址
/* @0x1f4df4 ldr r2, [r3] */  —— r2 = count（重新读，Free 可能改过它？本函数不改）
/* @0x1f4df8 mov r3, #0 */  —— 0
/* @0x1f4dfc mov r10, r2 */  —— slot = count
/* @0x1f4e00 str r3, [r4, r2, lsl #4] */  —— table[count].name = NULL
/* @0x1f4e04 mov r0, r6 */  —— r0 = name

/* ═══ 段 C · 写表项四字段（0x1f4e08..0x1f4e44）═══
 *   ★+0 name（YYStrDup 副本）、+4 getter、+8 setter、+0xc writable=(setter!=0)。
 *   writable 是**算出来的**，不是第 4 实参；写序 fixed：name → writable → getter/setter。
 *   写完表项才去插 map；扩容判定在写表之后（count > threshold 时跳到 0x1f4f34，回来再插）。
 */
/* @0x1f4e08 bl 0xdb8c8 <_Z8YYStrDupPKc> */  —— r0 = YYStrDup(name)：**表拥有**的副本（map 的 key 另用原指针）
/* @0x1f4e0c ldr r3, [pc, #0x230] */  —— 池 0x1f5044 = 0x001fc014
/* @0x1f4e10 ldr r2, [sp, #0x4] */  —— 取 count 地址
/* @0x1f4e14 adds r1, r9, #0 */  —— adds：置标志 —— r9(setter) 是否为 0
/* @0x1f4e18 ldr r3, [pc, r3] */  —— r3 = 0x1f4e20 + 0x1fc014 = 0x3f0e34 → g_builtinVarLookup（**map 指针变量**）
/* @0x1f4e1c movne r1, #1 */  —— r1 = (setter != 0) ? 1 : 0
/* @0x1f4e20 ldr r8, [r3] */  —— r8 = map 对象
/* @0x1f4e24 ldr r7, [r2] */  —— r7 = count（= 本次 slot）
/* @0x1f4e28 ldr r12, [r8, #0xc] */  —— map->threshold（+0xc）
/* @0x1f4e2c ldr r2, [r8, #0x4] */  —— map->count（+4）
/* @0x1f4e30 add r3, r4, r7, lsl #4 */  —— &table[slot]
/* @0x1f4e34 cmp r2, r12 */  —— map->count vs threshold
/* @0x1f4e38 str r0, [r4, r10, lsl #4] */  —— ★字段 1：entry->name = dup（+0）
/* @0x1f4e3c strb r1, [r3, #0xc] */  —— ★字段 4：entry->writable = (setter!=0)（+0xc）—— 由 setter 算，不由第 4 实参
/* @0x1f4e40 stmib r3, {r5, r9} */  —— ★字段 2/3：entry->getter = r5（+4）、entry->setter = r9（+8）；stmib 从 +4 起写两个寄存器
/* @0x1f4e44 bgt 0x1f4f34 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b+0x18c> */  —— count > threshold → 0x1f4f34 扩容（插完再插）

/* ═══ 段 D · 内联插入：hash / 探测 / Robin Hood（0x1f4e48..0x1f4ec4）═══
 *   map->count 先自增（重复键时再减）；hash 清符号位 ⇒ 0 是空槽哨兵；项 12 B。
 *   探测距离用 (idx+cap-home)&mask 的环形差算。
 */
/* @0x1f4e48 add r2, r2, #1 */  —— map->count + 1
/* @0x1f4e4c mov r0, r6 */  —— r0 = name（hash 用**原指针**的字符串内容）
/* @0x1f4e50 str r2, [r8, #0x4] */  —— ★先自增（重复键时 0x1f4f04 再减回来）
/* @0x1f4e54 bl 0x1eeb88 <_Z21CHashMapCalculateHashIPKcEjT_> */  —— CHashMapCalculateHash<char const*>(name)
/* @0x1f4e58 ldr r4, [r8, #0x8] */  —— mask（+8）
/* @0x1f4e5c ldr r10, [r8, #0x10] */  —— entries（+0x10）
/* @0x1f4e60 bic r0, r0, #-2147483648 */  —— 清符号位 ⇒ hash 恒正（0 留给空槽）
/* @0x1f4e64 and r3, r0, r4 */  —— idx = hash & mask
/* @0x1f4e68 add r2, r3, r3, lsl #1 */  —— idx*3
/* @0x1f4e6c add r2, r10, r2, lsl #2 */  —— entry = entries + idx*12（**12 B 项**）
/* @0x1f4e70 ldr r1, [r2, #0x8] */  —— entry->hash（+8）
/* @0x1f4e74 cmp r1, #0 */  —— cmp
/* @0x1f4e78 ldrne r11, [r8] */  —— 占用 → r11 = capacity（+0，距离计算用）
/* @0x1f4e7c movne r5, #0 */  —— 待插项的距离 d=0
/* @0x1f4e80 bne 0x1f4ec8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b+0x120> */  —— → 比较块
/* @0x1f4e84 b 0x1f4f14 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b+0x16c> */  —— 空槽 → 直接落位
/* @0x1f4e88 ldr r9, [r2] */  —— ★交换（Robin Hood）：保存被逐出项的 key
/* @0x1f4e8c ldr r5, [r2, #0x4] */  —— 被逐出项的 value
/* @0x1f4e90 str r0, [r2, #0x8] */  —— entry->hash = 新 hash
/* @0x1f4e94 mov r0, r1 */  —— “当前 hash” ← 被逐出项 hash
/* @0x1f4e98 str r6, [r2] */  —— entry->key = 新 key
/* @0x1f4e9c mov r6, r9 */  —— “当前 key” ← 被逐出项 key
/* @0x1f4ea0 str r7, [r2, #0x4] */  —— entry->value = 新 slot
/* @0x1f4ea4 mov r7, r5 */  —— “当前 value” ← 被逐出项 value
/* @0x1f4ea8 add r3, r3, #1 */  —— idx++
/* @0x1f4eac add r5, r12, #1 */  —— 被逐出项的探测距离 = 占用项距离 + 1
/* @0x1f4eb0 and r3, r3, r4 */  —— idx &= mask（环形）
/* @0x1f4eb4 add r2, r3, r3, lsl #1 */  —— idx*3
/* @0x1f4eb8 add r2, r10, r2, lsl #2 */  —— entry = entries + idx*12
/* @0x1f4ebc ldr r1, [r2, #0x8] */  —— entry->hash
/* @0x1f4ec0 cmp r1, #0 */  —— cmp
/* @0x1f4ec4 beq 0x1f4f14 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b+0x16c> */  —— 空 → 落位

/* ═══ 段 E · 距离比较、交换、重复键（0x1f4ec8..0x1f4f18）═══
 *   占用项距离 < 待插距离 → 交换（Robin Hood）；距离相等比 hash；hash 相等**只比 key 指针**。
 *   真重复（同指针）→ 覆盖 value + count--。
 */
/* @0x1f4ec8 add r12, r3, r11 */  —— idx + capacity
/* @0x1f4ecc and r9, r1, r4 */  —— 占用项的 home = hash & mask
/* @0x1f4ed0 rsb r12, r9, r12 */  —— (idx+cap) - home
/* @0x1f4ed4 and r12, r12, r4 */  —— & mask ⇒ 占用项的当前距离
/* @0x1f4ed8 cmp r12, r5 */  —— 占用项距离 vs 待插距离
/* @0x1f4edc blt 0x1f4e88 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b+0xe0> */  —— ★占用项更“穷” → 交换（Robin Hood 判据）
/* @0x1f4ee0 movne r12, r5 */  —— 否则 r12 = 待插距离
/* @0x1f4ee4 bne 0x1f4ea8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b+0x100> */  —— → 继续探测（0x1f4ea8 里距离 +1）
/* @0x1f4ee8 cmp r1, r0 */  —— 距离相等 → 比 hash
/* @0x1f4eec bne 0x1f4ea8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b+0x100> */  —— hash 不同 → 继续
/* @0x1f4ef0 ldr r5, [r2] */  —— entry->key
/* @0x1f4ef4 cmp r6, r5 */  —— ★只比**指针**（同内容不同指针不算重复）
/* @0x1f4ef8 bne 0x1f4ea8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b+0x100> */  —— 不同 → 继续
/* @0x1f4efc ldr r3, [r8, #0x4] */  —— map->count
/* @0x1f4f00 stm r2, {r6, r7} */  —— 重复键：覆盖 key/value
/* @0x1f4f04 sub r3, r3, #1 */  —— 撤销 0x1f4e50 的自增
/* @0x1f4f08 str r1, [r2, #0x8] */  —— hash 不变
/* @0x1f4f0c str r3, [r8, #0x4] */  —— 写回 count
/* @0x1f4f10 b 0x1f4f1c <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b+0x174> */  —— → 0x1f4f1c
/* @0x1f4f14 stm r2, {r6, r7} */  —— 落位：key/value
/* @0x1f4f18 str r0, [r2, #0x8] */  —— hash

/* ═══ 段 F · 计数与返回（0x1f4f1c..0x1f4f30）═══
 *   ★count++ 是最后一步 ⇒ 表项与 map 都写好之后表才“对外可见”。void，无返回值。
 */
/* @0x1f4f1c ldr r2, [sp, #0x4] */  —— 取 count 地址
/* @0x1f4f20 ldr r3, [r2] */  —— builtin_numb
/* @0x1f4f24 add r3, r3, #1 */  —— +1
/* @0x1f4f28 str r3, [r2] */  —— ★count++ —— 表项在 0x1f4e38..0x1f4e40 已经写好；**先写表、后插 map、最后计数**
/* @0x1f4f2c add sp, sp, #12 */  —— 拆帧
/* @0x1f4f30 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */  —— 正常出口（无返回值：void）

/* ═══ 段 G · 扩容：翻倍 + 重算阈值（0x1f4f34..0x1f4fc0）═══
 *   cap←2c、mask←2c-1、entries←Alloc(24c)、count←0、threshold←(int)(0.6*2c)。
 *   0.6f = 0x3f19999a；Alloc 走 MemoryManager::Alloc(bytes, "…/Platform/MemoryManager.h", 70, true)。
 */
/* @0x1f4f34 ldr r10, [r8] */  —— 扩容：r10 = 旧 cap
/* @0x1f4f38 mov r3, #1 */  —— r3 = 1（Alloc 的 zero 实参）
/* @0x1f4f3c ldr r1, [pc, #0x104] */  —— 池 0x1f5048 = 0x0013c0e4
/* @0x1f4f40 mov r2, #70 */  —— 行号 70
/* @0x1f4f44 ldr r9, [r8, #0x10] */  —— r9 = 旧 entries
/* @0x1f4f48 lsl r0, r10, r3 */  —— cap << 1
/* @0x1f4f4c add r1, pc, r1 */  —— r1 = 0x1f4f54 + 0x13c0e4 = 0x331038 "…/Platform/MemoryManager.h"
/* @0x1f4f50 add r4, r0, r10, lsl #2 */  —— 2c + 4c = 6c
/* @0x1f4f54 str r0, [r8] */  —— map->cap = 2c
/* @0x1f4f58 sub r0, r0, #1 */  —— 2c-1
/* @0x1f4f5c str r0, [r8, #0x8] */  —— map->mask = 2c-1
/* @0x1f4f60 lsl r4, r4, #2 */  —— 6c*4 = 24c = (2c)*12 字节
/* @0x1f4f64 mov r0, r4 */  —— r0 = 字节数
/* @0x1f4f68 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */  —— MemoryManager::Alloc(24c, "…MemoryManager.h", 70, true)
/* @0x1f4f6c mov r2, r4 */  —— r2 = 字节数
/* @0x1f4f70 mov r1, #0 */  —— r1 = 0
/* @0x1f4f74 str r0, [r8, #0x10] */  —— map->entries = 新块
/* @0x1f4f78 bl 0xb65b0 <memset@plt> */  —— memset(新块, 0, 24c)
/* @0x1f4f7c ldr r2, [r8] */  —— r2 = 新 cap
/* @0x1f4f80 vldr s15, [pc, #176] */  —— 0.6f（池 0x1f5038）
/* @0x1f4f84 mov r1, #0 */  —— 0
/* @0x1f4f88 cmp r2, r1 */  —— cmp
/* @0x1f4f8c str r1, [r8, #0x4] */  —— map->count = 0
/* @0x1f4f90 vmov s13, r2 */  —— vmov（int → float）
/* @0x1f4f94 vcvt.f32.s32 s14, s13 */  —— vcvt.f32.s32
/* @0x1f4f98 vmul.f32 s15, s14, s15 */  —— 0.6 * cap
/* @0x1f4f9c vcvt.s32.f32 s15, s15 */  —— vcvt.s32.f32
/* @0x1f4fa0 vstr s15, [r8, #12] */  —— map->threshold = (int)(0.6*cap)
/* @0x1f4fa4 ble 0x1f4fc4 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b+0x21c> */  —— cap <= 0 → 跳过清零循环
/* @0x1f4fa8 add r2, r2, r2, lsl #1 */  —— cap*3
/* @0x1f4fac ldr r3, [r8, #0x10] */  —— entries
/* @0x1f4fb0 add r2, r3, r2, lsl #2 */  —— end = entries + cap*12
/* @0x1f4fb4 str r1, [r3, #0x8] */  —— 循环体：entry->hash = 0
/* @0x1f4fb8 add r3, r3, #12 */  —— +12
/* @0x1f4fbc cmp r3, r2 */  —— cmp
/* @0x1f4fc0 bne 0x1f4fb4 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b+0x20c> */  —— bne（memset 已经清过，这里再清 hash 一遍）

/* ═══ 段 H · 旧表逐条重插 + 释放（0x1f4fc4..0x1f5000）═══
 *   跳 hash<=0 的空槽，其余 ldm {key,value} 后调非内联的 CHashMap::Insert。
 */
/* @0x1f4fc4 cmp r10, #0 */  —— 旧 cap
/* @0x1f4fc8 movgt r4, r9 */  —— r4 = 旧 entries
/* @0x1f4fcc movgt r5, #0 */  —— i = 0
/* @0x1f4fd0 ble 0x1f4ffc <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b+0x254> */  —— 旧表为空 → 直接释放
/* @0x1f4fd4 ldr r3, [r4, #0x8] */  —— 旧 entry->hash
/* @0x1f4fd8 mov r0, r8 */  —— this = map
/* @0x1f4fdc add r5, r5, #1 */  —— ++i
/* @0x1f4fe0 cmp r3, #0 */  —— cmp
/* @0x1f4fe4 ble 0x1f4ff0 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b+0x248> */  —— 空槽 → 跳过
/* @0x1f4fe8 ldm r4, {r1, r2} */  —— key, value
/* @0x1f4fec bl 0xd261c <_ZN8CHashMapIPKciLi7EE6InsertES1_i> */  —— ★旧项逐条重插（走非内联的 CHashMap::Insert）
/* @0x1f4ff0 cmp r5, r10 */  —— cmp i, 旧 cap
/* @0x1f4ff4 add r4, r4, #12 */  —— +12
/* @0x1f4ff8 bne 0x1f4fd4 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b+0x22c> */  —— bne
/* @0x1f4ffc mov r0, r9 */  —— r0 = 旧块
/* @0x1f5000 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */  —— MemoryManager::Free(旧块)

/* ═══ 段 I · 重算阈值并回到插入（0x1f5004..0x1f5020）═══
 *   重插后 count 变了，所以 threshold 再算一次，然后 0x1f5020 回到 0x1f4e48 重跑插入。
 */
/* @0x1f5004 vldr s13, [r8] */  —— cap
/* @0x1f5008 vcvt.f32.s32 s14, s13 */  —— int → float
/* @0x1f500c vldr s15, [pc, #36] */  —— 0.6f（同一池字 0x1f5038）
/* @0x1f5010 ldr r2, [r8, #0x4] */  —— count
/* @0x1f5014 vmul.f32 s15, s14, s15 */  —— 0.6*cap
/* @0x1f5018 vcvt.s32.f32 s15, s15 */  —— vcvt
/* @0x1f501c vstr s15, [r8, #12] */  —— 重算 threshold（重插后 count 变了）
/* @0x1f5020 b 0x1f4e48 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b+0xa0> */  —— ★回到插入（扩容后重跑一次 hash/探测）

/* ═══ 段 J · 500 上限错误出口（0x1f5024..0x1f5034）═══
 *   "INTERNAL ERROR: Adding too many variables"（0x352854）；先拆帧再尾跳 ShowMessage —— 不返回、不动 count。
 */
/* @0x1f5024 ldr r0, [pc, #0x20] */  —— 池 0x1f504c = 0x0015d824
/* @0x1f5028 add r0, pc, r0 */  —— ★r0 = 0x1f5030 + 0x15d824 = 0x352854 "INTERNAL ERROR: Adding too many variables"
/* @0x1f502c add sp, sp, #12 */  —— 拆帧（下）
/* @0x1f5030 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */  —— 拆帧（上）——★pop 里是 lr，不是 pc
/* @0x1f5034 b 0xc4b0c <_Z11ShowMessagePKc> */  —— ★尾跳 ShowMessage：不返回，也不写 count

/* ═══ 段 K · 字面量池（6 字）（0x1f5038..0x1f504c）═══
 *   0x1f5038 = 0.6f；其余 5 字 = 3 个 .got 槽的 pc 相对偏移（0x1f503c/40/44）+ 2 个 .rodata 串偏移（0x1f5048/4c）。
 */
/* @0x1f5038 svclo #0x19999a */  —— 池：float 0x3f19999a = 0.6f（0x1f4f80 / 0x1f500c 两处 vldr）
/* @0x1f503c andseq r8, pc, r4, lsl #29 */  —— 池：GOT 偏移 0x001f8e84（0x1f4db0 消费 ⇒ 0x3edc3c）
/* @0x1f5040 andseq r8, pc, r0, ror #28 */  —— 池：GOT 偏移 0x001f8e60（0x1f4dd8 消费 ⇒ 0x3edc40）
/* @0x1f5044 andseq r12, pc, r4, lsl r0 */  —— 池：GOT 偏移 0x001fc014（0x1f4e18 消费 ⇒ 0x3f0e34）
/* @0x1f5048 andseq r12, r3, r4, ror #1 */  —— 池：0x0013c0e4 → 0x331038 "…/Platform/MemoryManager.h"
/* @0x1f504c andseq sp, r5, r4, lsr #16 */  —— 池：0x0015d824 → 0x352854 "INTERNAL ERROR: Adding too many variables"
