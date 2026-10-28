# reverse-v1 — 原版 libyoyo.so 的 C 化逆向

目标不是"再写一个解释器"，而是把**原版 GameMaker runner** 逐函数还原成 C，
每一行都锚到二进制里的某条指令，再用**离线**手段（ART / javam 跑我们自己的实现）做行为差分。

**不做实时操作 app 的差分**：一遍遍驱动原版 app 在速度上不可行，也不可复现。
原版只作为静态字节来源；运行期对照一律在我们自己的 harness 里完成。

## 二进制

    libyoyo.so   ELF32 ARM (armeabi-v7a)，4,689,844 B，stripped
    sha256 3bbedd09ad0cc60f3f3cad86a257275f…（取自 APK 的 lib/armeabi-v7a/libyoyo.so）
    .text  0x000b6fd0..0x0031bb7c，2,509,740 B

## 覆盖账（"逆向完全部"的唯一口径）

    instructions        627,423      .text 里每一条 32 位指令
    attributed          627,423      100.00%，无未归属
    functions           9,623        含 371 个匿名区间（stripped 的静态函数/跳转表）
    有指令的函数        8,722
    零指令符号          562          别名/重叠符号，锚点记在拥有该地址的那一个上
    地址别名            337          同一地址多个符号名，只发一次锚点

    校验 scripts/check_bank_coverage.py → anchors=627,423 / duplicates=0 / missing=0
         / orphan=0 / mnemonic_mismatch=0 / RESULT TOTAL

## 目录

    asm/census.json           总量与归属统计
    asm/functions.tsv         9,623 行：addr / size / demangled / mangled / 首末指令 / 指令数
    asm/instructions.jsonl.xz 全部指令（a/w/m/o/f），45 MB → 3.8 MB
    asm/index-<func>.tsv      单函数索引（核心函数用）
    asm/<func>_0x<va>.asm     llvm-objdump 原始反汇编快照
    cards/<func>.c            人工逆向卡：级别 + 语义 + 逐条锚点
    cards/auto/bank_*.c       301 个自动覆盖卡组，含全部 9,623 个函数的逐条锚点
    claims.jsonl              主张账本：proven / narrowed / refuted / open

## 级别

    正文      逐行锚到指令，语义已从 asm 推出，可编译（Code_Execute）
    骨架      锚点全覆盖，语义只钉了顶部几条（ExecuteIt / VM::Exec / VM::ExecRelease）
    原始覆盖  锚点全覆盖，语义未钉（cards/auto 全部）

## 规矩

1. 锚点不接受手写转录：`asm_index.py` / `libyoyo_census.py` 从二进制生成，
   `check_card_anchors.py`（单卡）与 `check_bank_coverage.py`（全库）逐地址比对。
2. 只有 `RESULT EXACT` / `RESULT TOTAL` 才允许往上加语义。
3. objdump 把 literal pool 数据字译成指令时（如 `0031deec` → `eorseq`），
   卡里保留 objdump 写法，同时在注释里标"非指令"。
4. 主张状态四选一进 claims.jsonl；`narrowed` 必须写 narrowed 到什么程度。
5. 覆盖度 ≠ 语义等价：627,423 个锚点只证明"每条指令都被指到"，不证明"理解对了"。

## 已钉的语义

    汇总：40 张卡、15,784 条锚点全部 EXACT（verify_reverse_v1.py），跨卡共享地址 0
          正文 8 张 / 骨架 32 张；claims 195 条（proven 161 / narrowed 15 / open 19）

    入口链
      Code_Execute    0x0cfc60   21 条  正文   纯转发 ExecuteIt；返回 0 → Error_Show_Action + 全局字节 0
      ExecuteIt       0x0cf914  211 条  骨架   code->type([+8])：<1/>3 返回 1；1..2 调 [code+0x64]+4；==3 才执行
      VM::Exec        0x0e7fd0  366 条  骨架   按 debug 全局二选一 → ExecDebug(992 B) / ExecRelease(648 B)
      VM::ExecRelease 0x0e4540  162 条  骨架   线程化派发：[VMExec+0x58][pc] → blx；+0x48 是 pc
      PerformReturn   0xe42d8   127 条  骨架   exec+0x28 帧指针、exec+0x4c 帧深度（返回自减）

    栈与变量
      DoPushImmediate 0xd3244     4 条  正文   sxth 后 str [sp,#-4]!（立即数入栈）
      DoPushBuiltin   0xd4d74    34 条  正文   索引=base&0x0FFFFFFF；表项 16B、fn 在 +4；越界 VMError
      DoPushLocal     0xd4a34   105 条  骨架   槽 = id-100000，步长 16；栈顶 tag 0x00FFFFFF
      DoPushGlobal    0xd4bd8   103 条  骨架   与局部同构，基址换成 GOT 单例 +4
      DoPushEnv       0xd4dfc   416 条  骨架   with 压栈：位域 w0∈[-7,-1] 六类标记；>99999 走 ms_ID2Instance
      DoPopEnv        0xd3840    74 条  骨架   码指针回填 (exec+0x44-4)+arg*4，再 exec+0x5c[code/4] → +0x48
      DoPopLocalVariable 0xe1f5c 46 条  正文   dst=self+4+idx*16；写回的是空结果 {0,0,tag5}
      DoPop           0xe65e4  1530 条  骨架   只收 kind 2/5/15；[15:0] count、[19:16] kind、位30 带 base
      DoPopNull       0xe61b4   108 条  骨架   kind5 才填 null；0xFF 前缀转 DoBreak
      DoDup           0xd5560   182 条  正文   dup / swap 双模式；16B 拷贝按 tag 分引用计数

    取值与运算
      DoPush          0xe9e88  1372 条  骨架   kind 0..15；8/4/16 三档载荷；**负 id 是第二级 opcode**（-1..-14）
      DoRet           0xe3fe8   188 条  正文   sub=(arg>>16)&0xFF 定 memcpy 0/4/8/16；返回值进 frame+0x2c+n*16
      DoExit          0xe44d4    27 条  正文   depth≤0 复位取指；depth>0 走 PerformReturn 后压 16B tag0
      DoConv          0xeb3f8   832 条  正文   src/dst 类型码 + 103 项预解析表 → 44 个叶子
      DoAdd           0xdc524  1015 条  骨架   mode=(arg>>8)&0xF；type 字节高位=左、低位=右；tag0 double/7 int32/10 int64/1 string
      DoSub/DoDiv/DoXor/DoAnd/DoShl/DoRem/DoMul/DoMod/DoShr/DoOr  各 460–637 条，全部 骨架
                                             统一：消费表定结果槽 → 算术表（9~12 条内核）→ 压回
      DoNeg/DoNot     0xe096c/0xd7908    骨架   mode1/mode2 两条语义（DoNot 的 ! 与 ~ 栈效应不同）

    调用与比较
      DoCall          0xe8b48   786 条  骨架   id 四分流：<100000 内建 / +100000 脚本 / 499999 间接 / >500000 扩展
      DoCallGML       0xe8b00    18 条  正文   DoCall 路径 A 的特化
      DoCallLibrary   0xe3e58   100 条  正文   desc=table+idx*0x50、fn=desc[0x40]、5 参协议
      DoSet           0xe2014  1863 条  骨架   **不是赋值，是比较算子**：K=(arg>>8)&0xF，实数比较带 1e-05 容差

## 结构结论

**opcode 表已定位**（`asm/handler_table.tsv`，由 `scripts/find_handler_table.py` 从 .data 指针扫描得出）：
.data 0x3f20b4 起 32 项、每项 4 字节，就是 `VM::ExecRelease` 里 `[VMExec+0x58][pc]` 的落点：

    0 Push   1 PushLocal   2 PushGlobal  3 PushBuiltin  4 PushImmediate
    5 Pop    6 Dup         7 Conv
    8 Mul    9 Div        10 Rem        11 Mod         12 Add   13 Sub
   14 And   15 Or         16 Xor       17 Neg         18 Not   19 Shl   20 Shr
   21 Set  22 Branch     23 BranchTrue 24 BranchFalse
   25 Call 26 PushEnv    27 PopEnv     28 Ret         29 Exit  30 PopNull  31 PopNull(重复)

DoSet 落在 21（Shr 与 Branch 之间），与「它是比较算子而非赋值」互相印证；
slot 31 与 30 同值、DoBreak 不在表内，仍是 open（OPCODE-002）。

原版没有 opcode 比较链：`VMExec+0x58` 是一张**预解析的处理器指针表**，主循环取表项后 `blx`。
语义全在 48 个 `DoXxx(uint32 arg, uchar* sp, const uchar* base, VMExec*)` 里（返回新的值栈顶），
合计 70,532 B ≈ 17,633 条指令。

三条贯穿全库的事实（都已锚到指令）：

    RValue      栈上 16 字节，类型 tag 在 +12 的高字节，取值 0..14
                0/13 real、1 string、2 array、3 pointer、5 undefined、7 int32、10 int64
                0x00FFFFFF 是「尚未解析的变量引用」占位
    id 分区     基址 100000：脚本 id、局部槽、全局槽都用 id-100000；槽步长 16 字节
    opcode 参数 位域：[15:0] 有符号 count（sxth）、[19:16] 子种类（ubfx #0x10,#4）、
                位 30 = 附带变量基址（ands #0x40000000），位 29 = id 内嵌于 arg

两条方法学教训（写进库里，避免再犯）：

    · ARM `add pc,pc,rX,lsl #2` 的基址是**该指令地址 + 8**，紧跟其后的 `b` 是越界 default 而非 case 0。
      早先 DoPushGlobal 的 tag 落点表整表错一位，已按此修正并作废（claims RVALUE-003）。
    · 函数名不可信：`DoSet` 名字像赋值，实际是比较算子；`DoRem` 写回的是**商**；
      DoDiv/DoAnd/DoShl 的错误串分别写成 `'*' operator`/`DoAdd`/`DoOr`（原版复制粘贴错位）。

## 下一步

    · 32 张骨架里挑「调用链主干」升级正文：DoPush（负 id 二级 opcode 的 14 条）、DoCall、DoPop
    · 补齐尚未出卡的 Do* 剩余函数（见 functions.tsv 里 _Z*Do* 且签名不同的那批）
    · 在 javam/ART harness 里跑同一段 GML 字节码，比对"我们的 VM 状态轨迹"与"按 C 卡实现的轨迹"
      ——两边都在我们手里，不碰原版 app
