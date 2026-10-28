/* cally 逆向卡：Code_Execute（原版 libyoyo.so，armv7）
 *
 * @func  0x000cfc60 0x000cfcb4   size 84   21 条指令
 * 级别:  正文
 * 符号:  _Z12Code_ExecuteP9CInstanceS0_P5CCodeP6RValuei
 *        → int Code_Execute(CInstance* self, CInstance* other, CCode* code, RValue* result, int arg)
 * 来源:  libyoyo.so sha256 3bbedd09…（APK d608f455 内 lib/armeabi-v7a/libyoyo.so, 4,689,844 B）
 * 锚表:  reconstruction/reverse-v1/asm/index-Code_Execute.tsv（由 scripts/asm_index.py 从二进制生成）
 *
 * 语义（三条已证）：
 *   1. 纯转发：把第 5 个参数（调用者栈上的 int）原样转给 ExecuteIt，自身不做任何逻辑
 *   2. ExecuteIt 返回 0 = 执行失败 → 调 Error_Show_Action(msg, false)，并把一个全局字节写 0
 *   3. 返回 ExecuteIt 的原始返回值
 *
 * 未钉（open）：
 *   · 0xcfcac/0xcfcb0 两个字是 literal pool（0x… 立即数），不是指令；本卡按数据标注
 *   · 两个全局（错误串指针、错误标志字节）的符号名未知，只能用 pc 相对槽位描述
 *   · Error_Show_Action 的第二个参数在 asm 里是 mov r1, r4（r4==0），语义为 false，未从源码确认
 */

typedef struct CInstance CInstance;
typedef struct CCode CCode;
typedef struct RValue RValue;

#include <stdbool.h>

/* 外部符号（原型取自 .dynsym 反混淆，实现不在本卡范围） */
extern int ExecuteIt(CInstance *self, CInstance *other, CCode *code, RValue *result, int arg);
extern void Error_Show_Action(const char *msg, bool fatal);

/* 两个 pc 相对槽位指向的全局，名字未知，先按用途命名 */
extern const char *g_code_exec_error_msg; /* 未证：仅由 0xcfc8c 的 ldr r0,[r3] 推导 */
extern unsigned char g_code_exec_flag;    /* 未证：仅由 0xcfc9c 的 strb r4,[r3] 推导 */

int Code_Execute(CInstance *self, CInstance *other, CCode *code, RValue *result, int arg) {
    /* @0xcfc60 push {r4, lr} —— 保存帧 */
    /* @0xcfc64 sub sp, sp, #8 —— 预留一个栈槽放第 5 个实参 */
    /* @0xcfc68 ldr r12, [sp, #0x10] —— 取调用者传入的第 5 个参数（arg） */
    /* @0xcfc6c str r12, [sp] —— 作为被调者的第 5 个栈实参压栈 */
    /* @0xcfc70 bl 0xcf914 <_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei> —— 真正的执行入口 */
    int ret = ExecuteIt(self, other, code, result, arg);
    /* @0xcfc74 subs r4, r0, #0 —— 用返回值置标志 */
    /* @0xcfc78 bne 0xcfca0 <_Z12Code_ExecuteP9CInstanceS0_P5CCodeP6RValuei+0x40> —— 非零即成功，直接走返回路径 */
    if (ret == 0) {
        /* @0xcfc7c ldr r3, [pc, #0x28] —— 取全局槽位（错误消息） */
        /* @0xcfc80 mov r1, r4 —— 第二个实参 = 0（false） */
        /* @0xcfc84 ldr r3, [pc, r3] —— GOT 解引用 */
        /* @0xcfc88 ldr r3, [r3] —— 二级解引用 */
        /* @0xcfc8c ldr r0, [r3] —— 取出 char* 实参 */
        /* @0xcfc90 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
        Error_Show_Action(g_code_exec_error_msg, false);
        /* @0xcfc94 ldr r3, [pc, #0x14] —— 取全局槽位（错误标志） */
        /* @0xcfc98 ldr r3, [pc, r3] —— GOT 解引用 */
        /* @0xcfc9c strb r4, [r3] —— 写 0 字节 */
        g_code_exec_flag = 0;
    }
    /* @0xcfca0 mov r0, r4 —— 返回值 = ExecuteIt 的返回值 */
    /* @0xcfca4 add sp, sp, #8 —— 释放栈槽 */
    /* @0xcfca8 pop {r4, pc} —— 返回 */
    return ret;
}

/* @0xcfcac eorseq sp, r1, r12, ror #29 —— objdump 把数据字 0x0031deec 误译成指令（literal pool，非指令） */
/* @0xcfcb0 eorseq sp, r1, r12, asr #29 —— 数据字 0x0031decc（literal pool，非指令） */
