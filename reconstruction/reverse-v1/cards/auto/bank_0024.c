/* libyoyo.so 覆盖卡组 0024
 * 函数 0xf5808..0xf7d98，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0xf5808 · Extension_Init() · size=44 · insn=11 */
/* @0xf5808 ldr r2, [pc, #0x1c] */
/* @0xf580c mov r3, #0 */
/* @0xf5810 ldr r1, [pc, #0x18] */
/* @0xf5814 ldr r2, [pc, r2] */
/* @0xf5818 add r1, pc, r1 */
/* @0xf581c str r3, [r2] */
/* @0xf5820 str r3, [r1, #0x4] */
/* @0xf5824 str r3, [r1] */
/* @0xf5828 bx lr */
/* @0xf582c eoreq r8, pc, r0, lsr #12 */
/* @0xf5830 eorseq sp, r8, r0, lsr lr */

/* ── FUNC 0xf5834 · Extension_Prepare() · size=1668 · insn=417 */
/* @0xf5834 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xf5838 sub sp, sp, #2192 */
/* @0xf583c ldr r9, [pc, #0x62c] */
/* @0xf5840 sub sp, sp, #12 */
/* @0xf5844 ldr r3, [pc, #0x628] */
/* @0xf5848 add r2, sp, #148 */
/* @0xf584c add r9, pc, r9 */
/* @0xf5850 str r2, [sp, #0x24] */
/* @0xf5854 mov r8, #0 */
/* @0xf5858 mov r2, #1024 */
/* @0xf585c ldr r3, [r9, r3] */
/* @0xf5860 add r0, sp, #148 */
/* @0xf5864 mov r1, r8 */
/* @0xf5868 str r8, [sp, #0x50] */
/* @0xf586c str r3, [sp, #0x40] */
/* @0xf5870 ldr r3, [r3] */
/* @0xf5874 str r3, [sp, #0x894] */
/* @0xf5878 bl 0xb65b0 <memset@plt> */
/* @0xf587c ldr r3, [pc, #0x5f4] */
/* @0xf5880 ldr r3, [r9, r3] */
/* @0xf5884 str r3, [sp, #0x3c] */
/* @0xf5888 ldr r3, [r3] */
/* @0xf588c cmp r3, r8 */
/* @0xf5890 ble 0xf5e50 <_Z17Extension_Preparev+0x61c> */
/* @0xf5894 ldr r10, [pc, #0x5e0] */
/* @0xf5898 ldr r2, [pc, #0x5e0] */
/* @0xf589c add r10, pc, r10 */
/* @0xf58a0 add r2, pc, r2 */
/* @0xf58a4 str r2, [sp, #0x14] */
/* @0xf58a8 b 0xf58c8 <_Z17Extension_Preparev+0x94> */
/* @0xf58ac ldr r3, [r10, #0x4] */
/* @0xf58b0 str r0, [r3, r8, lsl #2] */
/* @0xf58b4 ldr r12, [sp, #0x3c] */
/* @0xf58b8 add r8, r8, #1 */
/* @0xf58bc ldr r3, [r12] */
/* @0xf58c0 cmp r3, r8 */
/* @0xf58c4 ble 0xf5960 <_Z17Extension_Preparev+0x12c> */
/* @0xf58c8 ldr r3, [r10, #0x4] */
/* @0xf58cc ldr r7, [r3, r8, lsl #2] */
/* @0xf58d0 mov r0, r7 */
/* @0xf58d4 bl 0xf55fc <_ZN17CExtensionPackage9GetFolderEv> */
/* @0xf58d8 ldr r1, [sp, #0x14] */
/* @0xf58dc bl 0xb6574 <strcmp@plt> */
/* @0xf58e0 cmp r0, #0 */
/* @0xf58e4 movne r6, #0 */
/* @0xf58e8 beq 0xf58ac <_Z17Extension_Preparev+0x78> */
/* @0xf58ec mov r0, r7 */
/* @0xf58f0 bl 0xf5630 <_ZN17CExtensionPackage16GetIncludesCountEv> */
/* @0xf58f4 cmp r6, r0 */
/* @0xf58f8 bge 0xf58b4 <_Z17Extension_Preparev+0x80> */
/* @0xf58fc mov r0, r7 */
/* @0xf5900 mov r1, r6 */
/* @0xf5904 bl 0xf5800 <_ZN17CExtensionPackage15GetIncludesFileEi> */
/* @0xf5908 mov r4, #0 */
/* @0xf590c mov r5, r0 */
/* @0xf5910 b 0xf5948 <_Z17Extension_Preparev+0x114> */
/* @0xf5914 mov r1, r4 */
/* @0xf5918 mov r0, r5 */
/* @0xf591c bl 0xf5390 <_ZN14CExtensionFile16GetConstantsDataEi> */
/* @0xf5920 bl 0xf490c <_ZN18CExtensionConstant7GetNameEv> */
/* @0xf5924 mov r1, r4 */
/* @0xf5928 add r4, r4, #1 */
/* @0xf592c mov r11, r0 */
/* @0xf5930 mov r0, r5 */
/* @0xf5934 bl 0xf5390 <_ZN14CExtensionFile16GetConstantsDataEi> */
/* @0xf5938 bl 0xf4940 <_ZN18CExtensionConstant8GetValueEv> */
/* @0xf593c mov r1, r0 */
/* @0xf5940 mov r0, r11 */
/* @0xf5944 bl 0xf1a10 <_Z17Code_Constant_AddPKcS0_> */
/* @0xf5948 mov r0, r5 */
/* @0xf594c bl 0xf5058 <_ZN14CExtensionFile17GetConstantsCountEv> */
/* @0xf5950 cmp r4, r0 */
/* @0xf5954 blt 0xf5914 <_Z17Extension_Preparev+0xe0> */
/* @0xf5958 add r6, r6, #1 */
/* @0xf595c b 0xf58ec <_Z17Extension_Preparev+0xb8> */
/* @0xf5960 ldr r2, [pc, #0x51c] */
/* @0xf5964 cmp r3, #0 */
/* @0xf5968 mov r10, #0 */
/* @0xf596c ldr r6, [r9, r2] */
/* @0xf5970 str r10, [r6] */
/* @0xf5974 ble 0xf5e68 <_Z17Extension_Preparev+0x634> */
/* @0xf5978 ldr r11, [pc, #0x508] */
/* @0xf597c ldr r2, [pc, #0x508] */
/* @0xf5980 add r11, pc, r11 */
/* @0xf5984 add r2, pc, r2 */
/* @0xf5988 str r2, [sp, #0x14] */
/* @0xf598c b 0xf59a4 <_Z17Extension_Preparev+0x170> */
/* @0xf5990 ldr r12, [sp, #0x3c] */
/* @0xf5994 add r10, r10, #1 */
/* @0xf5998 ldr r3, [r12] */
/* @0xf599c cmp r3, r10 */
/* @0xf59a0 ble 0xf5a48 <_Z17Extension_Preparev+0x214> */
/* @0xf59a4 ldr r3, [r11, #0x4] */
/* @0xf59a8 ldr r8, [r3, r10, lsl #2] */
/* @0xf59ac cmp r8, #0 */
/* @0xf59b0 beq 0xf5990 <_Z17Extension_Preparev+0x15c> */
/* @0xf59b4 mov r0, r8 */
/* @0xf59b8 bl 0xf55fc <_ZN17CExtensionPackage9GetFolderEv> */
/* @0xf59bc ldr r1, [sp, #0x14] */
/* @0xf59c0 bl 0xb6574 <strcmp@plt> */
/* @0xf59c4 cmp r0, #0 */
/* @0xf59c8 movne r7, #0 */
/* @0xf59cc beq 0xf5990 <_Z17Extension_Preparev+0x15c> */
/* @0xf59d0 mov r0, r8 */
/* @0xf59d4 bl 0xf5630 <_ZN17CExtensionPackage16GetIncludesCountEv> */
/* @0xf59d8 cmp r7, r0 */
/* @0xf59dc bge 0xf5990 <_Z17Extension_Preparev+0x15c> */
/* @0xf59e0 mov r0, r8 */
/* @0xf59e4 mov r1, r7 */
/* @0xf59e8 bl 0xf5800 <_ZN17CExtensionPackage15GetIncludesFileEi> */
/* @0xf59ec mov r4, #0 */
/* @0xf59f0 mov r5, r0 */
/* @0xf59f4 b 0xf59fc <_Z17Extension_Preparev+0x1c8> */
/* @0xf59f8 add r4, r4, #1 */
/* @0xf59fc mov r0, r5 */
/* @0xf5a00 bl 0xf5044 <_ZN14CExtensionFile17GetFunctionsCountEv> */
/* @0xf5a04 cmp r4, r0 */
/* @0xf5a08 bge 0xf5a40 <_Z17Extension_Preparev+0x20c> */
/* @0xf5a0c mov r1, r4 */
/* @0xf5a10 mov r0, r5 */
/* @0xf5a14 bl 0xf5050 <_ZN14CExtensionFile16GetFunctionsDataEi> */
/* @0xf5a18 bl 0xf4c28 <_ZN18CExtensionFunction5GetIdEv> */
/* @0xf5a1c ldr r3, [r6] */
/* @0xf5a20 cmp r0, r3 */
/* @0xf5a24 ble 0xf59f8 <_Z17Extension_Preparev+0x1c4> */
/* @0xf5a28 mov r1, r4 */
/* @0xf5a2c mov r0, r5 */
/* @0xf5a30 bl 0xf5050 <_ZN14CExtensionFile16GetFunctionsDataEi> */
/* @0xf5a34 bl 0xf4c28 <_ZN18CExtensionFunction5GetIdEv> */
/* @0xf5a38 str r0, [r6] */
/* @0xf5a3c b 0xf59f8 <_Z17Extension_Preparev+0x1c4> */
/* @0xf5a40 add r7, r7, #1 */
/* @0xf5a44 b 0xf59d0 <_Z17Extension_Preparev+0x19c> */
/* @0xf5a48 ldr r0, [r6] */
/* @0xf5a4c add r0, r0, #1 */
/* @0xf5a50 lsl r0, r0, #2 */
/* @0xf5a54 ldr r4, [pc, #0x434] */
/* @0xf5a58 mov r2, #148 */
/* @0xf5a5c mov r3, #1 */
/* @0xf5a60 add r4, pc, r4 */
/* @0xf5a64 mov r1, r4 */
/* @0xf5a68 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xf5a6c ldr lr, [pc, #0x420] */
/* @0xf5a70 ldr r12, [r6] */
/* @0xf5a74 mov r3, #1 */
/* @0xf5a78 mov r1, r4 */
/* @0xf5a7c mov r2, #149 */
/* @0xf5a80 ldr lr, [r9, lr] */
/* @0xf5a84 add r12, r12, r3 */
/* @0xf5a88 str lr, [sp, #0x20] */
/* @0xf5a8c str r0, [lr] */
/* @0xf5a90 lsl r0, r12, #2 */
/* @0xf5a94 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xf5a98 ldr lr, [pc, #0x3f8] */
/* @0xf5a9c ldr r12, [pc, #0x3f8] */
/* @0xf5aa0 mov r3, #150 */
/* @0xf5aa4 ldr r1, [r6] */
/* @0xf5aa8 mov r2, r4 */
/* @0xf5aac ldr lr, [r9, lr] */
/* @0xf5ab0 add r1, r1, #1 */
/* @0xf5ab4 str lr, [sp, #0x28] */
/* @0xf5ab8 lsl r1, r1, #2 */
/* @0xf5abc str r0, [lr] */
/* @0xf5ac0 ldr r0, [r9, r12] */
/* @0xf5ac4 add r0, r0, #4 */
/* @0xf5ac8 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0xf5acc ldr r2, [r6] */
/* @0xf5ad0 ldr r12, [sp, #0x28] */
/* @0xf5ad4 mvn r1, #0 */
/* @0xf5ad8 add r2, r2, #1 */
/* @0xf5adc ldr r0, [r12] */
/* @0xf5ae0 lsl r2, r2, #2 */
/* @0xf5ae4 bl 0xb65b0 <memset@plt> */
/* @0xf5ae8 ldr r0, [r6] */
/* @0xf5aec mov r1, r4 */
/* @0xf5af0 mov r2, #153 */
/* @0xf5af4 add r0, r0, #1 */
/* @0xf5af8 mov r3, #1 */
/* @0xf5afc lsl r0, r0, #2 */
/* @0xf5b00 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xf5b04 ldr r3, [pc, #0x394] */
/* @0xf5b08 ldr r2, [r6] */
/* @0xf5b0c mvn r1, #0 */
/* @0xf5b10 ldr r3, [r9, r3] */
/* @0xf5b14 add r2, r2, #1 */
/* @0xf5b18 lsl r2, r2, #2 */
/* @0xf5b1c str r3, [sp, #0x2c] */
/* @0xf5b20 str r0, [r3] */
/* @0xf5b24 bl 0xb65b0 <memset@plt> */
/* @0xf5b28 ldr r2, [r6] */
/* @0xf5b2c mvn r1, #0 */
/* @0xf5b30 ldr r12, [sp, #0x20] */
/* @0xf5b34 add r2, r2, #1 */
/* @0xf5b38 ldr r0, [r12] */
/* @0xf5b3c lsl r2, r2, #2 */
/* @0xf5b40 bl 0xb65b0 <memset@plt> */
/* @0xf5b44 ldr r12, [sp, #0x3c] */
/* @0xf5b48 ldr r3, [r12] */
/* @0xf5b4c cmp r3, #0 */
/* @0xf5b50 ble 0xf5e2c <_Z17Extension_Preparev+0x5f8> */
/* @0xf5b54 ldr r12, [pc, #0x348] */
/* @0xf5b58 add r8, sp, #80 */
/* @0xf5b5c add r12, pc, r12 */
/* @0xf5b60 str r12, [sp, #0x44] */
/* @0xf5b64 ldr r12, [pc, #0x33c] */
/* @0xf5b68 add r12, pc, r12 */
/* @0xf5b6c str r12, [sp, #0x48] */
/* @0xf5b70 mov r12, #0 */
/* @0xf5b74 str r12, [sp, #0x38] */
/* @0xf5b78 ldr r12, [pc, #0x32c] */
/* @0xf5b7c add r12, pc, r12 */
/* @0xf5b80 str r12, [sp, #0x4c] */
/* @0xf5b84 ldr r12, [pc, #0x324] */
/* @0xf5b88 add r12, pc, r12 */
/* @0xf5b8c str r12, [sp, #0x30] */
/* @0xf5b90 ldr r12, [pc, #0x31c] */
/* @0xf5b94 add r12, pc, r12 */
/* @0xf5b98 str r12, [sp, #0x34] */
/* @0xf5b9c b 0xf5bbc <_Z17Extension_Preparev+0x388> */
/* @0xf5ba0 ldr r12, [sp, #0x3c] */
/* @0xf5ba4 ldr r3, [r12] */
/* @0xf5ba8 ldr r12, [sp, #0x38] */
/* @0xf5bac add r12, r12, #1 */
/* @0xf5bb0 str r12, [sp, #0x38] */
/* @0xf5bb4 cmp r3, r12 */
/* @0xf5bb8 ble 0xf5e2c <_Z17Extension_Preparev+0x5f8> */
/* @0xf5bbc ldr r12, [sp, #0x44] */
/* @0xf5bc0 ldr r3, [r12, #0x4] */
/* @0xf5bc4 ldr r12, [sp, #0x38] */
/* @0xf5bc8 ldr r7, [r3, r12, lsl #2] */
/* @0xf5bcc cmp r7, #0 */
/* @0xf5bd0 beq 0xf5ba0 <_Z17Extension_Preparev+0x36c> */
/* @0xf5bd4 bl 0x28fd5c <_Z14GetFilePrePendv> */
/* @0xf5bd8 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xf5bdc mov r4, r0 */
/* @0xf5be0 mov r0, r7 */
/* @0xf5be4 bl 0xf55fc <_ZN17CExtensionPackage9GetFolderEv> */
/* @0xf5be8 ldr r1, [sp, #0x48] */
/* @0xf5bec bl 0xb6574 <strcmp@plt> */
/* @0xf5bf0 cmp r0, #0 */
/* @0xf5bf4 beq 0xf5ba0 <_Z17Extension_Preparev+0x36c> */
/* @0xf5bf8 mov r3, r4 */
/* @0xf5bfc mov r1, #1024 */
/* @0xf5c00 ldr r2, [sp, #0x4c] */
/* @0xf5c04 add r0, sp, #148 */
/* @0xf5c08 bl 0xb65c8 <snprintf@plt> */
/* @0xf5c0c mov r0, r4 */
/* @0xf5c10 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xf5c14 mov r12, #0 */
/* @0xf5c18 add r3, sp, #1168 */
/* @0xf5c1c mov r5, r12 */
/* @0xf5c20 add r3, r3, #8 */
/* @0xf5c24 str r12, [sp, #0x1c] */
/* @0xf5c28 sub r3, r3, #4 */
/* @0xf5c2c str r3, [sp, #0x18] */
/* @0xf5c30 mov r0, r7 */
/* @0xf5c34 bl 0xf5630 <_ZN17CExtensionPackage16GetIncludesCountEv> */
/* @0xf5c38 ldr r12, [sp, #0x1c] */
/* @0xf5c3c cmp r12, r0 */
/* @0xf5c40 bge 0xf5ba0 <_Z17Extension_Preparev+0x36c> */
/* @0xf5c44 ldr r1, [sp, #0x1c] */
/* @0xf5c48 mov r0, r7 */
/* @0xf5c4c bl 0xf5800 <_ZN17CExtensionPackage15GetIncludesFileEi> */
/* @0xf5c50 mov r6, #0 */
/* @0xf5c54 str r0, [sp, #0x14] */
/* @0xf5c58 ldr r0, [sp, #0x14] */
/* @0xf5c5c bl 0xf5044 <_ZN14CExtensionFile17GetFunctionsCountEv> */
/* @0xf5c60 cmp r6, r0 */
/* @0xf5c64 bge 0xf5d98 <_Z17Extension_Preparev+0x564> */
/* @0xf5c68 mov r1, r6 */
/* @0xf5c6c ldr r0, [sp, #0x14] */
/* @0xf5c70 bl 0xf5050 <_ZN14CExtensionFile16GetFunctionsDataEi> */
/* @0xf5c74 ldr r12, [sp, #0x2c] */
/* @0xf5c78 mov r10, #0 */
/* @0xf5c7c mov r9, r10 */
/* @0xf5c80 ldr r11, [r12] */
/* @0xf5c84 str r7, [r0, #0x60] */
/* @0xf5c88 mov r4, r0 */
/* @0xf5c8c bl 0xf4c28 <_ZN18CExtensionFunction5GetIdEv> */
/* @0xf5c90 str r4, [r11, r0, lsl #2] */
/* @0xf5c94 mov r1, r9 */
/* @0xf5c98 mov r0, r4 */
/* @0xf5c9c bl 0xf4974 <_ZN18CExtensionFunction10GetArgTypeEi> */
/* @0xf5ca0 add r9, r9, #1 */
/* @0xf5ca4 cmp r0, #1 */
/* @0xf5ca8 movne r0, r5 */
/* @0xf5cac cmp r9, #17 */
/* @0xf5cb0 str r0, [r8, r10] */
/* @0xf5cb4 add r10, r10, #4 */
/* @0xf5cb8 bne 0xf5c94 <_Z17Extension_Preparev+0x460> */
/* @0xf5cbc mov r0, r4 */
/* @0xf5cc0 bl 0xf4c48 <_ZN18CExtensionFunction13GetReturnTypeEv> */
/* @0xf5cc4 subs r3, r0, #1 */
/* @0xf5cc8 mov r0, r4 */
/* @0xf5ccc rsbs r10, r3, #0 */
/* @0xf5cd0 adcs r10, r10, r3 */
/* @0xf5cd4 bl 0xf4c18 <_ZN18CExtensionFunction7GetKindEv> */
/* @0xf5cd8 mov r1, #0 */
/* @0xf5cdc mov r2, #1024 */
/* @0xf5ce0 cmp r0, #12 */
/* @0xf5ce4 ldr r0, [sp, #0x18] */
/* @0xf5ce8 beq 0xf5da8 <_Z17Extension_Preparev+0x574> */
/* @0xf5cec bl 0xb65b0 <memset@plt> */
/* @0xf5cf0 ldr r1, [sp, #0x1c] */
/* @0xf5cf4 mov r0, r7 */
/* @0xf5cf8 bl 0xf5800 <_ZN17CExtensionPackage15GetIncludesFileEi> */
/* @0xf5cfc bl 0xf4fac <_ZN14CExtensionFile11GetFileNameEv> */
/* @0xf5d00 ldr r2, [sp, #0x30] */
/* @0xf5d04 add r3, sp, #148 */
/* @0xf5d08 mov r1, #1024 */
/* @0xf5d0c mov r9, r0 */
/* @0xf5d10 str r0, [sp] */
/* @0xf5d14 ldr r0, [sp, #0x18] */
/* @0xf5d18 bl 0xb65c8 <snprintf@plt> */
/* @0xf5d1c ldr r12, [sp, #0x20] */
/* @0xf5d20 mov r0, r4 */
/* @0xf5d24 ldr r11, [r12] */
/* @0xf5d28 bl 0xf4c28 <_ZN18CExtensionFunction5GetIdEv> */
/* @0xf5d2c mov r12, r0 */
/* @0xf5d30 mov r0, r4 */
/* @0xf5d34 str r12, [sp, #0xc] */
/* @0xf5d38 bl 0xf4be4 <_ZN18CExtensionFunction15GetExternalNameEv> */
/* @0xf5d3c mov r1, r0 */
/* @0xf5d40 mov r0, r4 */
/* @0xf5d44 str r1, [sp, #0x10] */
/* @0xf5d48 bl 0xf4c38 <_ZN18CExtensionFunction11GetArgCountEv> */
/* @0xf5d4c ldr r1, [sp, #0x10] */
/* @0xf5d50 mov r2, #1 */
/* @0xf5d54 stm sp, {r8, r10} */
/* @0xf5d58 mov r3, r0 */
/* @0xf5d5c mov r0, r9 */
/* @0xf5d60 bl 0x2148fc <_Z10DLL_DefinePKcS0_iiPii> */
/* @0xf5d64 ldr r12, [sp, #0xc] */
/* @0xf5d68 str r0, [r11, r12, lsl #2] */
/* @0xf5d6c ldr r12, [sp, #0x28] */
/* @0xf5d70 mov r0, r4 */
/* @0xf5d74 add r6, r6, #1 */
/* @0xf5d78 ldr r4, [r12] */
/* @0xf5d7c bl 0xf4c28 <_ZN18CExtensionFunction5GetIdEv> */
/* @0xf5d80 mov r3, #2 */
/* @0xf5d84 str r3, [r4, r0, lsl #2] */
/* @0xf5d88 ldr r0, [sp, #0x14] */
/* @0xf5d8c bl 0xf5044 <_ZN14CExtensionFile17GetFunctionsCountEv> */
/* @0xf5d90 cmp r6, r0 */
/* @0xf5d94 blt 0xf5c68 <_Z17Extension_Preparev+0x434> */
/* @0xf5d98 ldr r12, [sp, #0x1c] */
/* @0xf5d9c add r12, r12, #1 */
/* @0xf5da0 str r12, [sp, #0x1c] */
/* @0xf5da4 b 0xf5c30 <_Z17Extension_Preparev+0x3fc> */
/* @0xf5da8 bl 0xb65b0 <memset@plt> */
/* @0xf5dac ldr r1, [sp, #0x1c] */
/* @0xf5db0 mov r0, r7 */
/* @0xf5db4 bl 0xf5800 <_ZN17CExtensionPackage15GetIncludesFileEi> */
/* @0xf5db8 bl 0xf4fac <_ZN14CExtensionFile11GetFileNameEv> */
/* @0xf5dbc ldr r2, [sp, #0x34] */
/* @0xf5dc0 add r3, sp, #148 */
/* @0xf5dc4 mov r1, #1024 */
/* @0xf5dc8 mov r9, r0 */
/* @0xf5dcc str r0, [sp] */
/* @0xf5dd0 ldr r0, [sp, #0x18] */
/* @0xf5dd4 bl 0xb65c8 <snprintf@plt> */
/* @0xf5dd8 ldr r12, [sp, #0x20] */
/* @0xf5ddc mov r0, r4 */
/* @0xf5de0 ldr r11, [r12] */
/* @0xf5de4 bl 0xf4c28 <_ZN18CExtensionFunction5GetIdEv> */
/* @0xf5de8 mov r12, r0 */
/* @0xf5dec mov r0, r4 */
/* @0xf5df0 str r12, [sp, #0xc] */
/* @0xf5df4 bl 0xf4be4 <_ZN18CExtensionFunction15GetExternalNameEv> */
/* @0xf5df8 mov r1, r0 */
/* @0xf5dfc mov r0, r4 */
/* @0xf5e00 str r1, [sp, #0x10] */
/* @0xf5e04 bl 0xf4c38 <_ZN18CExtensionFunction11GetArgCountEv> */
/* @0xf5e08 ldr r1, [sp, #0x10] */
/* @0xf5e0c mov r2, #0 */
/* @0xf5e10 stm sp, {r8, r10} */
/* @0xf5e14 mov r3, r0 */
/* @0xf5e18 mov r0, r9 */
/* @0xf5e1c bl 0x2148fc <_Z10DLL_DefinePKcS0_iiPii> */
/* @0xf5e20 ldr r12, [sp, #0xc] */
/* @0xf5e24 str r0, [r11, r12, lsl #2] */
/* @0xf5e28 b 0xf5d6c <_Z17Extension_Preparev+0x538> */
/* @0xf5e2c ldr r12, [sp, #0x40] */
/* @0xf5e30 mov r0, #1 */
/* @0xf5e34 ldr r2, [sp, #0x894] */
/* @0xf5e38 ldr r3, [r12] */
/* @0xf5e3c cmp r2, r3 */
/* @0xf5e40 bne 0xf5e64 <_Z17Extension_Preparev+0x630> */
/* @0xf5e44 add sp, sp, #2192 */
/* @0xf5e48 add sp, sp, #12 */
/* @0xf5e4c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xf5e50 ldr r3, [pc, #0x2c] */
/* @0xf5e54 mov r0, #4 */
/* @0xf5e58 ldr r6, [r9, r3] */
/* @0xf5e5c str r8, [r6] */
/* @0xf5e60 b 0xf5a54 <_Z17Extension_Preparev+0x220> */
/* @0xf5e64 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0xf5e68 mov r0, #4 */
/* @0xf5e6c b 0xf5a54 <_Z17Extension_Preparev+0x220> */
/* @0xf5e70 eoreq r12, pc, r4, lsl #8 */
/* @0xf5e74 .word 0xffffbd00 */
/* @0xf5e78 .word 0xffffc1e4 */
/* @0xf5e7c eorseq sp, r8, r12, lsr #27 */
/* @0xf5e80 strhteq r2, [r4], -r12 */
/* @0xf5e84 .word 0xffffc1e8 */
/* @0xf5e88 eorseq sp, r8, r8, asr #25 */
/* @0xf5e8c .word 0x00241fd8 */
/* @0xf5e90 eoreq r1, r4, r8, lsl #30 */
/* @0xf5e94 .word 0xffffc10c */
/* @0xf5e98 .word 0xffffc108 */
/* @0xf5e9c .word 0xffffc1ec */
/* @0xf5ea0 .word 0xffffc1f0 */
/* @0xf5ea4 eorseq sp, r8, r12, ror #21 */
/* @0xf5ea8 .word 0x00241df4 */
/* @0xf5eac eoreq lr, r3, r12, lsl #31 */
/* @0xf5eb0 eoreq pc, r3, r12, asr #32 */
/* @0xf5eb4 eoreq pc, r3, r0, asr #32 */

/* ── FUNC 0xf5eb8 · Extension_Load(unsigned char*, unsigned int, unsigned char*) · size=776 · insn=194 */
/* @0xf5eb8 ldr r1, [r0] */
/* @0xf5ebc mov r3, #246 */
/* @0xf5ec0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xf5ec4 sub sp, sp, #44 */
/* @0xf5ec8 mov r4, r0 */
/* @0xf5ecc ldr r0, [pc, #0x2d8] */
/* @0xf5ed0 str r1, [sp, #0x1c] */
/* @0xf5ed4 lsl r1, r1, #2 */
/* @0xf5ed8 ldr lr, [sp, #0x1c] */
/* @0xf5edc add r0, pc, r0 */
/* @0xf5ee0 ldr r12, [pc, #0x2c8] */
/* @0xf5ee4 ldr r2, [pc, #0x2c8] */
/* @0xf5ee8 ldr r12, [pc, r12] */
/* @0xf5eec str lr, [r0], #4 */
/* @0xf5ef0 add r2, pc, r2 */
/* @0xf5ef4 str lr, [r12] */
/* @0xf5ef8 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0xf5efc ldr r12, [sp, #0x1c] */
/* @0xf5f00 cmp r12, #0 */
/* @0xf5f04 beq 0xf61a0 <_Z14Extension_LoadPhjS_+0x2e8> */
/* @0xf5f08 ldr r3, [pc, #0x2a8] */
/* @0xf5f0c mov r12, #0 */
/* @0xf5f10 str r4, [sp, #0x20] */
/* @0xf5f14 add r3, pc, r3 */
/* @0xf5f18 str r12, [sp, #0x18] */
/* @0xf5f1c str r3, [sp, #0x24] */
/* @0xf5f20 ldr r3, [sp, #0x20] */
/* @0xf5f24 ldr r5, [r3, #0x4]! */
/* @0xf5f28 cmp r5, #0 */
/* @0xf5f2c str r3, [sp, #0x20] */
/* @0xf5f30 beq 0xf6188 <_Z14Extension_LoadPhjS_+0x2d0> */
/* @0xf5f34 ldr r9, [pc, #0x280] */
/* @0xf5f38 ldr r9, [pc, r9] */
/* @0xf5f3c ldr r6, [r9] */
/* @0xf5f40 adds r4, r6, r5 */
/* @0xf5f44 beq 0xf6188 <_Z14Extension_LoadPhjS_+0x2d0> */
/* @0xf5f48 mov r0, #28 */
/* @0xf5f4c bl 0x27c524 <_Znwj> */
/* @0xf5f50 mov r7, r0 */
/* @0xf5f54 bl 0xf56c8 <_ZN17CExtensionPackageC2Ev> */
/* @0xf5f58 ldr r3, [sp, #0x24] */
/* @0xf5f5c ldr r12, [sp, #0x18] */
/* @0xf5f60 ldr r2, [r3, #0x4] */
/* @0xf5f64 ldr r3, [r6, r5] */
/* @0xf5f68 str r7, [r2, r12, lsl #2] */
/* @0xf5f6c cmp r3, #0 */
/* @0xf5f70 ldr r12, [sp, #0x24] */
/* @0xf5f74 moveq r1, r3 */
/* @0xf5f78 ldr r2, [r12, #0x4] */
/* @0xf5f7c ldr r12, [sp, #0x18] */
/* @0xf5f80 ldr r2, [r2, r12, lsl #2] */
/* @0xf5f84 str r2, [sp, #0x14] */
/* @0xf5f88 ldrne r2, [r9] */
/* @0xf5f8c ldr r0, [sp, #0x14] */
/* @0xf5f90 addne r1, r2, r3 */
/* @0xf5f94 bl 0xf5604 <_ZN17CExtensionPackage9SetFolderEPKc> */
/* @0xf5f98 ldr r3, [r4, #0x4] */
/* @0xf5f9c ldr r0, [sp, #0x14] */
/* @0xf5fa0 cmp r3, #0 */
/* @0xf5fa4 ldrne r2, [r9] */
/* @0xf5fa8 moveq r1, r3 */
/* @0xf5fac addne r1, r2, r3 */
/* @0xf5fb0 bl 0xf559c <_ZN17CExtensionPackage7SetNameEPKc> */
/* @0xf5fb4 ldr r3, [r4, #0x8] */
/* @0xf5fb8 ldr r0, [sp, #0x14] */
/* @0xf5fbc cmp r3, #0 */
/* @0xf5fc0 ldrne r2, [r9] */
/* @0xf5fc4 moveq r1, r3 */
/* @0xf5fc8 addne r1, r2, r3 */
/* @0xf5fcc bl 0xf55d0 <_ZN17CExtensionPackage12SetClassNameEPKc> */
/* @0xf5fd0 ldr r3, [r4, #0xc] */
/* @0xf5fd4 ldr r0, [sp, #0x14] */
/* @0xf5fd8 mov r1, r3 */
/* @0xf5fdc str r3, [sp, #0x10] */
/* @0xf5fe0 bl 0xf5638 <_ZN17CExtensionPackage16SetIncludesCountEi> */
/* @0xf5fe4 ldr r12, [sp, #0x10] */
/* @0xf5fe8 cmp r12, #0 */
/* @0xf5fec ble 0xf6188 <_Z14Extension_LoadPhjS_+0x2d0> */
/* @0xf5ff0 add r4, r4, #12 */
/* @0xf5ff4 mov r3, #0 */
/* @0xf5ff8 str r4, [sp, #0xc] */
/* @0xf5ffc str r3, [sp, #0x8] */
/* @0xf6000 ldr r12, [sp, #0xc] */
/* @0xf6004 ldr r4, [r12, #0x4]! */
/* @0xf6008 cmp r4, #0 */
/* @0xf600c str r12, [sp, #0xc] */
/* @0xf6010 beq 0xf6170 <_Z14Extension_LoadPhjS_+0x2b8> */
/* @0xf6014 ldr r5, [r9] */
/* @0xf6018 adds r7, r5, r4 */
/* @0xf601c beq 0xf6170 <_Z14Extension_LoadPhjS_+0x2b8> */
/* @0xf6020 ldr r1, [sp, #0x8] */
/* @0xf6024 ldr r0, [sp, #0x14] */
/* @0xf6028 bl 0xf5800 <_ZN17CExtensionPackage15GetIncludesFileEi> */
/* @0xf602c ldr r1, [r5, r4] */
/* @0xf6030 cmp r1, #0 */
/* @0xf6034 ldrne r3, [r9] */
/* @0xf6038 addne r1, r3, r1 */
/* @0xf603c mov r10, r0 */
/* @0xf6040 bl 0xf4fb4 <_ZN14CExtensionFile11SetFileNameEPKc> */
/* @0xf6044 ldr r1, [r7, #0x4] */
/* @0xf6048 mov r0, r10 */
/* @0xf604c cmp r1, #0 */
/* @0xf6050 ldrne r3, [r9] */
/* @0xf6054 addne r1, r3, r1 */
/* @0xf6058 bl 0xf5018 <_ZN14CExtensionFile17SetFunction_FinalEPKc> */
/* @0xf605c ldr r1, [r7, #0x8] */
/* @0xf6060 mov r0, r10 */
/* @0xf6064 cmp r1, #0 */
/* @0xf6068 ldrne r3, [r9] */
/* @0xf606c addne r1, r3, r1 */
/* @0xf6070 bl 0xf4ff8 <_ZN14CExtensionFile16SetFunction_InitEPKc> */
/* @0xf6074 mov r0, r10 */
/* @0xf6078 ldr r1, [r7, #0xc] */
/* @0xf607c bl 0xf4fe8 <_ZN14CExtensionFile7SetKindEi> */
/* @0xf6080 ldr r3, [r7, #0x10] */
/* @0xf6084 mov r0, r10 */
/* @0xf6088 mov r1, r3 */
/* @0xf608c str r3, [sp, #0x4] */
/* @0xf6090 bl 0xf504c <_ZN14CExtensionFile17SetFunctionsCountEi> */
/* @0xf6094 ldr r12, [sp, #0x4] */
/* @0xf6098 cmp r12, #0 */
/* @0xf609c ble 0xf6170 <_Z14Extension_LoadPhjS_+0x2b8> */
/* @0xf60a0 add r7, r7, #16 */
/* @0xf60a4 mov r6, #0 */
/* @0xf60a8 mov r1, r6 */
/* @0xf60ac mov r0, r10 */
/* @0xf60b0 bl 0xf5050 <_ZN14CExtensionFile16GetFunctionsDataEi> */
/* @0xf60b4 ldr r5, [r7, #0x4]! */
/* @0xf60b8 cmp r5, #0 */
/* @0xf60bc ldrne r3, [r9] */
/* @0xf60c0 moveq r4, #24 */
/* @0xf60c4 addne r5, r3, r5 */
/* @0xf60c8 mov r8, r0 */
/* @0xf60cc addne r4, r5, #24 */
/* @0xf60d0 ldr r1, [r5] */
/* @0xf60d4 cmp r1, #0 */
/* @0xf60d8 ldrne r3, [r9] */
/* @0xf60dc addne r1, r3, r1 */
/* @0xf60e0 bl 0xf4bb8 <_ZN18CExtensionFunction7SetNameEPKc> */
/* @0xf60e4 mov r0, r8 */
/* @0xf60e8 ldr r1, [r5, #0x4] */
/* @0xf60ec bl 0xf4c30 <_ZN18CExtensionFunction5SetIdEi> */
/* @0xf60f0 mov r0, r8 */
/* @0xf60f4 ldr r1, [r5, #0x8] */
/* @0xf60f8 bl 0xf4c20 <_ZN18CExtensionFunction7SetKindEi> */
/* @0xf60fc mov r0, r8 */
/* @0xf6100 ldr r1, [r5, #0xc] */
/* @0xf6104 bl 0xf4c50 <_ZN18CExtensionFunction13SetReturnTypeEi> */
/* @0xf6108 ldr r1, [r5, #0x10] */
/* @0xf610c mov r0, r8 */
/* @0xf6110 cmp r1, #0 */
/* @0xf6114 ldrne r3, [r9] */
/* @0xf6118 addne r1, r3, r1 */
/* @0xf611c bl 0xf4bec <_ZN18CExtensionFunction15SetExternalNameEPKc> */
/* @0xf6120 mov r0, r8 */
/* @0xf6124 ldr r1, [r5, #0x14] */
/* @0xf6128 bl 0xf4c40 <_ZN18CExtensionFunction11SetArgCountEi> */
/* @0xf612c ldr r3, [r5, #0x14] */
/* @0xf6130 cmp r3, #0 */
/* @0xf6134 subgt r11, r4, #4 */
/* @0xf6138 movgt r4, #0 */
/* @0xf613c ble 0xf6160 <_Z14Extension_LoadPhjS_+0x2a8> */
/* @0xf6140 mov r1, r4 */
/* @0xf6144 mov r0, r8 */
/* @0xf6148 ldr r2, [r11, #0x4]! */
/* @0xf614c add r4, r4, #1 */
/* @0xf6150 bl 0xf4988 <_ZN18CExtensionFunction10SetArgTypeEii> */
/* @0xf6154 ldr r3, [r5, #0x14] */
/* @0xf6158 cmp r3, r4 */
/* @0xf615c bgt 0xf6140 <_Z14Extension_LoadPhjS_+0x288> */
/* @0xf6160 ldr r3, [sp, #0x4] */
/* @0xf6164 add r6, r6, #1 */
/* @0xf6168 cmp r3, r6 */
/* @0xf616c bne 0xf60a8 <_Z14Extension_LoadPhjS_+0x1f0> */
/* @0xf6170 ldr r3, [sp, #0x8] */
/* @0xf6174 ldr r12, [sp, #0x10] */
/* @0xf6178 add r3, r3, #1 */
/* @0xf617c str r3, [sp, #0x8] */
/* @0xf6180 cmp r12, r3 */
/* @0xf6184 bne 0xf6000 <_Z14Extension_LoadPhjS_+0x148> */
/* @0xf6188 ldr r12, [sp, #0x18] */
/* @0xf618c ldr r1, [sp, #0x1c] */
/* @0xf6190 add r12, r12, #1 */
/* @0xf6194 str r12, [sp, #0x18] */
/* @0xf6198 cmp r12, r1 */
/* @0xf619c bne 0xf5f20 <_Z14Extension_LoadPhjS_+0x68> */
/* @0xf61a0 mov r0, #0 */
/* @0xf61a4 add sp, sp, #44 */
/* @0xf61a8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xf61ac eorseq sp, r8, r12, ror #14 */
/* @0xf61b0 eoreq r7, pc, r12, asr #30 */
/* @0xf61b4 eoreq r1, r4, r8, ror r10 */
/* @0xf61b8 eorseq sp, r8, r4, lsr r7 */
/* @0xf61bc eoreq r7, pc, r12, lsl #20 */

/* ── FUNC 0xf61c0 · Extension_Function_GetId(char const*) · size=128 · insn=32 */
/* @0xf61c0 push {r4, r5, r6, r7, r8, lr} */
/* @0xf61c4 mov r6, r0 */
/* @0xf61c8 ldr r5, [pc, #0x68] */
/* @0xf61cc ldr r5, [pc, r5] */
/* @0xf61d0 ldr r3, [r5] */
/* @0xf61d4 cmp r3, #0 */
/* @0xf61d8 ble 0xf6230 <_Z24Extension_Function_GetIdPKc+0x70> */
/* @0xf61dc ldr r7, [pc, #0x58] */
/* @0xf61e0 mvn r8, #0 */
/* @0xf61e4 mov r4, #0 */
/* @0xf61e8 add r7, pc, r7 */
/* @0xf61ec ldr r3, [r7, #0x4] */
/* @0xf61f0 mov r1, r6 */
/* @0xf61f4 ldr r0, [r3, r4, lsl #2] */
/* @0xf61f8 add r4, r4, #1 */
/* @0xf61fc cmp r0, #0 */
/* @0xf6200 beq 0xf621c <_Z24Extension_Function_GetIdPKc+0x5c> */
/* @0xf6204 bl 0xf5494 <_ZN17CExtensionPackage16FunctionFindNameEPKc> */
/* @0xf6208 cmp r0, #0 */
/* @0xf620c beq 0xf621c <_Z24Extension_Function_GetIdPKc+0x5c> */
/* @0xf6210 bl 0xf4c28 <_ZN18CExtensionFunction5GetIdEv> */
/* @0xf6214 subs r8, r0, #0 */
/* @0xf6218 bge 0xf6228 <_Z24Extension_Function_GetIdPKc+0x68> */
/* @0xf621c ldr r3, [r5] */
/* @0xf6220 cmp r3, r4 */
/* @0xf6224 bgt 0xf61ec <_Z24Extension_Function_GetIdPKc+0x2c> */
/* @0xf6228 mov r0, r8 */
/* @0xf622c pop {r4, r5, r6, r7, r8, pc} */
/* @0xf6230 mvn r8, #0 */
/* @0xf6234 b 0xf6228 <_Z24Extension_Function_GetIdPKc+0x68> */
/* @0xf6238 eoreq r7, pc, r8, ror #24 */
/* @0xf623c eorseq sp, r8, r0, ror #8 */

/* ── FUNC 0xf6240 · Extension_Function_GetArguments(int) · size=124 · insn=31 */
/* @0xf6240 push {r4, r5, r6, r7, r8, lr} */
/* @0xf6244 mov r6, r0 */
/* @0xf6248 ldr r5, [pc, #0x64] */
/* @0xf624c ldr r5, [pc, r5] */
/* @0xf6250 ldr r3, [r5] */
/* @0xf6254 cmp r3, #0 */
/* @0xf6258 ble 0xf62ac <_Z31Extension_Function_GetArgumentsi+0x6c> */
/* @0xf625c ldr r7, [pc, #0x54] */
/* @0xf6260 mvn r8, #99 */
/* @0xf6264 mov r4, #0 */
/* @0xf6268 add r7, pc, r7 */
/* @0xf626c b 0xf627c <_Z31Extension_Function_GetArgumentsi+0x3c> */
/* @0xf6270 ldr r3, [r5] */
/* @0xf6274 cmp r3, r4 */
/* @0xf6278 ble 0xf62a4 <_Z31Extension_Function_GetArgumentsi+0x64> */
/* @0xf627c ldr r3, [r7, #0x4] */
/* @0xf6280 mov r1, r6 */
/* @0xf6284 ldr r0, [r3, r4, lsl #2] */
/* @0xf6288 add r4, r4, #1 */
/* @0xf628c bl 0xf54e0 <_ZN17CExtensionPackage14FunctionFindIdEi> */
/* @0xf6290 cmp r0, #0 */
/* @0xf6294 beq 0xf6270 <_Z31Extension_Function_GetArgumentsi+0x30> */
/* @0xf6298 bl 0xf4c38 <_ZN18CExtensionFunction11GetArgCountEv> */
/* @0xf629c subs r8, r0, #0 */
/* @0xf62a0 blt 0xf6270 <_Z31Extension_Function_GetArgumentsi+0x30> */
/* @0xf62a4 mov r0, r8 */
/* @0xf62a8 pop {r4, r5, r6, r7, r8, pc} */
/* @0xf62ac mvn r8, #99 */
/* @0xf62b0 b 0xf62a4 <_Z31Extension_Function_GetArgumentsi+0x64> */
/* @0xf62b4 eoreq r7, pc, r8, ror #23 */
/* @0xf62b8 eorseq sp, r8, r0, ror #7 */

/* ── FUNC 0xf62bc · Extension_Function_GetName(int) · size=136 · insn=34 */
/* @0xf62bc push {r4, r5, r6, r7, r8, lr} */
/* @0xf62c0 mov r7, r0 */
/* @0xf62c4 ldr r6, [pc, #0x70] */
/* @0xf62c8 ldr r6, [pc, r6] */
/* @0xf62cc ldr r3, [r6] */
/* @0xf62d0 cmp r3, #0 */
/* @0xf62d4 ble 0xf6334 <_Z26Extension_Function_GetNamei+0x78> */
/* @0xf62d8 ldr r8, [pc, #0x60] */
/* @0xf62dc mov r5, #0 */
/* @0xf62e0 mov r4, r5 */
/* @0xf62e4 add r8, pc, r8 */
/* @0xf62e8 ldr r3, [r8, #0x4] */
/* @0xf62ec mov r1, r7 */
/* @0xf62f0 ldr r0, [r3, r4, lsl #2] */
/* @0xf62f4 add r4, r4, #1 */
/* @0xf62f8 bl 0xf54e0 <_ZN17CExtensionPackage14FunctionFindIdEi> */
/* @0xf62fc cmp r0, #0 */
/* @0xf6300 beq 0xf630c <_Z26Extension_Function_GetNamei+0x50> */
/* @0xf6304 bl 0xf4bb0 <_ZN18CExtensionFunction7GetNameEv> */
/* @0xf6308 mov r5, r0 */
/* @0xf630c cmp r5, #0 */
/* @0xf6310 beq 0xf6320 <_Z26Extension_Function_GetNamei+0x64> */
/* @0xf6314 ldrb r3, [r5] */
/* @0xf6318 cmp r3, #0 */
/* @0xf631c bne 0xf632c <_Z26Extension_Function_GetNamei+0x70> */
/* @0xf6320 ldr r3, [r6] */
/* @0xf6324 cmp r3, r4 */
/* @0xf6328 bgt 0xf62e8 <_Z26Extension_Function_GetNamei+0x2c> */
/* @0xf632c mov r0, r5 */
/* @0xf6330 pop {r4, r5, r6, r7, r8, pc} */
/* @0xf6334 mov r5, #0 */
/* @0xf6338 b 0xf632c <_Z26Extension_Function_GetNamei+0x70> */
/* @0xf633c eoreq r7, pc, r12, ror #22 */
/* @0xf6340 eorseq sp, r8, r4, ror #6 */

/* ── FUNC 0xf6344 · Extension_Call_DLL_Function(int, int, RValue*, RValue*) · size=124 · insn=31 */
/* @0xf6344 push {r4, lr} */
/* @0xf6348 subs r4, r0, #0 */
/* @0xf634c blt 0xf6384 <_Z27Extension_Call_DLL_FunctioniiP6RValueS0_+0x40> */
/* @0xf6350 ldr r12, [pc, #0x5c] */
/* @0xf6354 ldr r12, [pc, r12] */
/* @0xf6358 ldr r12, [r12] */
/* @0xf635c cmp r4, r12 */
/* @0xf6360 bgt 0xf6384 <_Z27Extension_Call_DLL_FunctioniiP6RValueS0_+0x40> */
/* @0xf6364 ldr r12, [pc, #0x4c] */
/* @0xf6368 ldr r12, [pc, r12] */
/* @0xf636c ldr r12, [r12] */
/* @0xf6370 ldr r12, [r12, r4, lsl #2] */
/* @0xf6374 cmp r12, #0 */
/* @0xf6378 beq 0xf638c <_Z27Extension_Call_DLL_FunctioniiP6RValueS0_+0x48> */
/* @0xf637c cmp r12, #2 */
/* @0xf6380 beq 0xf63a8 <_Z27Extension_Call_DLL_FunctioniiP6RValueS0_+0x64> */
/* @0xf6384 mov r0, #0 */
/* @0xf6388 pop {r4, pc} */
/* @0xf638c ldr r0, [pc, #0x28] */
/* @0xf6390 ldr r0, [pc, r0] */
/* @0xf6394 ldr r0, [r0] */
/* @0xf6398 ldr r0, [r0, r4, lsl #2] */
/* @0xf639c bl 0x212b10 <_Z8DLL_CalliiP6RValueS0_> */
/* @0xf63a0 mov r0, #1 */
/* @0xf63a4 pop {r4, pc} */
/* @0xf63a8 bl 0x214a18 <_Z8Ext_CalliiP6RValueS0_> */
/* @0xf63ac mov r0, #1 */
/* @0xf63b0 pop {r4, pc} */
/* @0xf63b4 eoreq r7, pc, r4, ror #21 */
/* @0xf63b8 .word 0x002f79f0 */
/* @0xf63bc eoreq r7, pc, r12, asr #19 */

/* ── FUNC 0xf63c0 · Extension_Function_GetKind(int) · size=24 · insn=6 */
/* @0xf63c0 ldr r3, [pc, #0xc] */
/* @0xf63c4 ldr r3, [pc, r3] */
/* @0xf63c8 ldr r3, [r3] */
/* @0xf63cc ldr r0, [r3, r0, lsl #2] */
/* @0xf63d0 bx lr */
/* @0xf63d4 mlaeq pc, r4, r9, r7 */

/* ── FUNC 0xf63d8 · Extension_Function_GetCode(int) · size=24 · insn=6 */
/* @0xf63d8 ldr r3, [pc, #0xc] */
/* @0xf63dc ldr r3, [pc, r3] */
/* @0xf63e0 ldr r3, [r3, #0x4] */
/* @0xf63e4 ldr r0, [r3, r0, lsl #2] */
/* @0xf63e8 bx lr */
/* @0xf63ec eoreq r7, pc, r0, ror #20 */

/* ── FUNC 0xf63f0 · Extension_Initialize() · size=544 · insn=136 */
/* @0xf63f0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xf63f4 sub sp, sp, #1760 */
/* @0xf63f8 ldr r12, [pc, #0x1fc] */
/* @0xf63fc sub sp, sp, #12 */
/* @0xf6400 add r8, sp, #48 */
/* @0xf6404 mov r1, #0 */
/* @0xf6408 mov r2, #256 */
/* @0xf640c mov r10, #0 */
/* @0xf6410 str r12, [sp, #0x14] */
/* @0xf6414 mov r0, r8 */
/* @0xf6418 ldr r12, [pc, #0x1e0] */
/* @0xf641c str r12, [sp, #0xc] */
/* @0xf6420 ldr r12, [sp, #0x14] */
/* @0xf6424 ldr r12, [pc, r12] */
/* @0xf6428 str r12, [sp, #0x14] */
/* @0xf642c ldr r3, [r12] */
/* @0xf6430 str r3, [sp, #0x6e4] */
/* @0xf6434 bl 0xb65b0 <memset@plt> */
/* @0xf6438 ldr r12, [sp, #0xc] */
/* @0xf643c str r10, [sp, #0x20] */
/* @0xf6440 ldr r12, [pc, r12] */
/* @0xf6444 str r10, [sp, #0x24] */
/* @0xf6448 str r12, [sp, #0xc] */
/* @0xf644c ldr r3, [r12] */
/* @0xf6450 str r10, [sp, #0x28] */
/* @0xf6454 cmp r3, r10 */
/* @0xf6458 str r10, [sp, #0x2c] */
/* @0xf645c ble 0xf6574 <_Z20Extension_Initializev+0x184> */
/* @0xf6460 ldr r12, [pc, #0x19c] */
/* @0xf6464 add r6, sp, #304 */
/* @0xf6468 add r9, sp, #32 */
/* @0xf646c add r12, pc, r12 */
/* @0xf6470 str r12, [sp, #0x10] */
/* @0xf6474 ldr r12, [sp, #0x10] */
/* @0xf6478 ldr r3, [r12, #0x4] */
/* @0xf647c ldr r5, [r3, r10, lsl #2] */
/* @0xf6480 cmp r5, #0 */
/* @0xf6484 movne r4, #0 */
/* @0xf6488 movne r7, r4 */
/* @0xf648c bne 0xf6498 <_Z20Extension_Initializev+0xa8> */
/* @0xf6490 b 0xf6560 <_Z20Extension_Initializev+0x170> */
/* @0xf6494 add r4, r4, #1 */
/* @0xf6498 mov r0, r5 */
/* @0xf649c bl 0xf5630 <_ZN17CExtensionPackage16GetIncludesCountEv> */
/* @0xf64a0 cmp r4, r0 */
/* @0xf64a4 bge 0xf6560 <_Z20Extension_Initializev+0x170> */
/* @0xf64a8 mov r1, r4 */
/* @0xf64ac mov r0, r5 */
/* @0xf64b0 bl 0xf5800 <_ZN17CExtensionPackage15GetIncludesFileEi> */
/* @0xf64b4 bl 0xf4ff0 <_ZN14CExtensionFile16GetFunction_InitEv> */
/* @0xf64b8 subs r11, r0, #0 */
/* @0xf64bc beq 0xf6494 <_Z20Extension_Initializev+0xa4> */
/* @0xf64c0 ldrb r3, [r11] */
/* @0xf64c4 cmp r3, #0 */
/* @0xf64c8 beq 0xf6494 <_Z20Extension_Initializev+0xa4> */
/* @0xf64cc mov r1, #0 */
/* @0xf64d0 mov r3, #0 */
/* @0xf64d4 mov r2, r1 */
/* @0xf64d8 mov r0, r6 */
/* @0xf64dc str r7, [sp] */
/* @0xf64e0 mov r12, #16 */
/* @0xf64e4 str r7, [sp, #0x4] */
/* @0xf64e8 str r12, [sp, #0x18] */
/* @0xf64ec str r8, [sp, #0x1c] */
/* @0xf64f0 bl 0x1994dc <_ZN9CInstanceC2Effiib> */
/* @0xf64f4 mov r0, r11 */
/* @0xf64f8 bl 0x1e0610 <_Z11Script_FindPKc> */
/* @0xf64fc cmp r0, #0 */
/* @0xf6500 blt 0xf6534 <_Z20Extension_Initializev+0x144> */
/* @0xf6504 add r3, sp, #24 */
/* @0xf6508 str r9, [sp] */
/* @0xf650c str r3, [sp, #0x4] */
/* @0xf6510 mov r1, r6 */
/* @0xf6514 mov r2, r6 */
/* @0xf6518 mov r3, #0 */
/* @0xf651c bl 0x1e0774 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue> */
/* @0xf6520 cmp r0, #0 */
/* @0xf6524 beq 0xf657c <_Z20Extension_Initializev+0x18c> */
/* @0xf6528 mov r0, r6 */
/* @0xf652c bl 0x199320 <_ZN9CInstanceD2Ev> */
/* @0xf6530 b 0xf6494 <_Z20Extension_Initializev+0xa4> */
/* @0xf6534 mov r1, r11 */
/* @0xf6538 mov r0, r5 */
/* @0xf653c bl 0xf5494 <_ZN17CExtensionPackage16FunctionFindNameEPKc> */
/* @0xf6540 subs r1, r0, #0 */
/* @0xf6544 beq 0xf65c0 <_Z20Extension_Initializev+0x1d0> */
/* @0xf6548 bl 0xf4c28 <_ZN18CExtensionFunction5GetIdEv> */
/* @0xf654c mov r1, #0 */
/* @0xf6550 ldr r2, [sp, #0x1c] */
/* @0xf6554 mov r3, r9 */
/* @0xf6558 bl 0xf6344 <_Z27Extension_Call_DLL_FunctioniiP6RValueS0_> */
/* @0xf655c b 0xf6528 <_Z20Extension_Initializev+0x138> */
/* @0xf6560 ldr r12, [sp, #0xc] */
/* @0xf6564 add r10, r10, #1 */
/* @0xf6568 ldr r3, [r12] */
/* @0xf656c cmp r3, r10 */
/* @0xf6570 bgt 0xf6474 <_Z20Extension_Initializev+0x84> */
/* @0xf6574 mov r0, #1 */
/* @0xf6578 b 0xf65a0 <_Z20Extension_Initializev+0x1b0> */
/* @0xf657c ldr r3, [pc, #0x84] */
/* @0xf6580 mov r1, #1 */
/* @0xf6584 ldr r3, [pc, r3] */
/* @0xf6588 ldr r3, [r3] */
/* @0xf658c ldr r0, [r3] */
/* @0xf6590 bl 0xecd7c <_Z10Error_ShowPKcb> */
/* @0xf6594 mov r0, r6 */
/* @0xf6598 bl 0x199320 <_ZN9CInstanceD2Ev> */
/* @0xf659c mov r0, #0 */
/* @0xf65a0 ldr r12, [sp, #0x14] */
/* @0xf65a4 ldr r2, [sp, #0x6e4] */
/* @0xf65a8 ldr r3, [r12] */
/* @0xf65ac cmp r2, r3 */
/* @0xf65b0 bne 0xf65f8 <_Z20Extension_Initializev+0x208> */
/* @0xf65b4 add sp, sp, #1760 */
/* @0xf65b8 add sp, sp, #12 */
/* @0xf65bc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xf65c0 add r4, sp, #740 */
/* @0xf65c4 mov r2, #1024 */
/* @0xf65c8 mov r0, r4 */
/* @0xf65cc bl 0xb65b0 <memset@plt> */
/* @0xf65d0 ldr r2, [pc, #0x34] */
/* @0xf65d4 mov r0, r4 */
/* @0xf65d8 mov r3, r11 */
/* @0xf65dc mov r1, #1024 */
/* @0xf65e0 add r2, pc, r2 */
/* @0xf65e4 bl 0xb65c8 <snprintf@plt> */
/* @0xf65e8 mov r0, r4 */
/* @0xf65ec mov r1, #1 */
/* @0xf65f0 bl 0xecd7c <_Z10Error_ShowPKcb> */
/* @0xf65f4 b 0xf6594 <_Z20Extension_Initializev+0x1a4> */
/* @0xf65f8 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0xf65fc eoreq r7, pc, r12, lsr #10 */
/* @0xf6600 .word 0x002f79f4 */
/* @0xf6604 ldrsbteq sp, [r8], -r12 */
/* @0xf6608 eoreq r7, pc, r12, ror #11 */
/* @0xf660c eoreq r1, r4, r4, asr #7 */

/* ── FUNC 0xf6610 · Extension_Finalize() · size=648 · insn=162 */
/* @0xf6610 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xf6614 sub sp, sp, #1760 */
/* @0xf6618 ldr r11, [pc, #0x264] */
/* @0xf661c sub sp, sp, #4 */
/* @0xf6620 ldr r1, [pc, #0x260] */
/* @0xf6624 mov r10, #0 */
/* @0xf6628 ldr r11, [pc, r11] */
/* @0xf662c str r10, [sp, #0x18] */
/* @0xf6630 ldr r1, [pc, r1] */
/* @0xf6634 str r10, [sp, #0x1c] */
/* @0xf6638 ldr r2, [r11] */
/* @0xf663c ldr r3, [r1] */
/* @0xf6640 cmp r2, r10 */
/* @0xf6644 str r1, [sp, #0xc] */
/* @0xf6648 str r10, [sp, #0x20] */
/* @0xf664c str r10, [sp, #0x24] */
/* @0xf6650 str r3, [sp, #0x6dc] */
/* @0xf6654 ble 0xf67b4 <_Z18Extension_Finalizev+0x1a4> */
/* @0xf6658 ldr r2, [pc, #0x22c] */
/* @0xf665c add r8, sp, #296 */
/* @0xf6660 add r9, sp, #40 */
/* @0xf6664 add r2, pc, r2 */
/* @0xf6668 str r2, [sp, #0x8] */
/* @0xf666c ldr r1, [sp, #0x8] */
/* @0xf6670 ldr r3, [r1, #0x4] */
/* @0xf6674 ldr r6, [r3, r10, lsl #2] */
/* @0xf6678 cmp r6, #0 */
/* @0xf667c movne r4, #0 */
/* @0xf6680 movne r5, r4 */
/* @0xf6684 bne 0xf66ec <_Z18Extension_Finalizev+0xdc> */
/* @0xf6688 b 0xf678c <_Z18Extension_Finalizev+0x17c> */
/* @0xf668c mov r3, #5 */
/* @0xf6690 str r5, [sp, #0x20] */
/* @0xf6694 str r5, [sp, #0x18] */
/* @0xf6698 str r3, [sp, #0x24] */
/* @0xf669c ldrb r3, [r7] */
/* @0xf66a0 cmp r3, #0 */
/* @0xf66a4 beq 0xf66e0 <_Z18Extension_Finalizev+0xd0> */
/* @0xf66a8 mov r0, r7 */
/* @0xf66ac bl 0x1e0610 <_Z11Script_FindPKc> */
/* @0xf66b0 cmp r0, #0 */
/* @0xf66b4 blt 0xf6760 <_Z18Extension_Finalizev+0x150> */
/* @0xf66b8 add r3, sp, #16 */
/* @0xf66bc add r7, sp, #24 */
/* @0xf66c0 str r3, [sp, #0x4] */
/* @0xf66c4 mov r1, r8 */
/* @0xf66c8 str r7, [sp] */
/* @0xf66cc mov r2, r8 */
/* @0xf66d0 mov r3, #0 */
/* @0xf66d4 bl 0x1e0774 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue> */
/* @0xf66d8 cmp r0, #0 */
/* @0xf66dc beq 0xf67bc <_Z18Extension_Finalizev+0x1ac> */
/* @0xf66e0 mov r0, r8 */
/* @0xf66e4 bl 0x199320 <_ZN9CInstanceD2Ev> */
/* @0xf66e8 add r4, r4, #1 */
/* @0xf66ec mov r0, r6 */
/* @0xf66f0 bl 0xf5630 <_ZN17CExtensionPackage16GetIncludesCountEv> */
/* @0xf66f4 cmp r4, r0 */
/* @0xf66f8 bge 0xf678c <_Z18Extension_Finalizev+0x17c> */
/* @0xf66fc mov r1, r4 */
/* @0xf6700 mov r0, r6 */
/* @0xf6704 bl 0xf5800 <_ZN17CExtensionPackage15GetIncludesFileEi> */
/* @0xf6708 bl 0xf5010 <_ZN14CExtensionFile17GetFunction_FinalEv> */
/* @0xf670c subs r7, r0, #0 */
/* @0xf6710 beq 0xf66e8 <_Z18Extension_Finalizev+0xd8> */
/* @0xf6714 mov r1, #0 */
/* @0xf6718 mov r3, #0 */
/* @0xf671c mov r2, r1 */
/* @0xf6720 mov r0, r8 */
/* @0xf6724 str r5, [sp] */
/* @0xf6728 str r5, [sp, #0x4] */
/* @0xf672c bl 0x1994dc <_ZN9CInstanceC2Effiib> */
/* @0xf6730 ldr r3, [sp, #0x24] */
/* @0xf6734 mov r2, #16 */
/* @0xf6738 str r9, [sp, #0x14] */
/* @0xf673c sub r3, r3, #1 */
/* @0xf6740 str r2, [sp, #0x10] */
/* @0xf6744 bic r3, r3, #-16777216 */
/* @0xf6748 bic r3, r3, #3 */
/* @0xf674c cmp r3, #0 */
/* @0xf6750 bne 0xf668c <_Z18Extension_Finalizev+0x7c> */
/* @0xf6754 add r0, sp, #24 */
/* @0xf6758 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xf675c b 0xf668c <_Z18Extension_Finalizev+0x7c> */
/* @0xf6760 mov r1, r7 */
/* @0xf6764 mov r0, r6 */
/* @0xf6768 bl 0xf5494 <_ZN17CExtensionPackage16FunctionFindNameEPKc> */
/* @0xf676c subs r1, r0, #0 */
/* @0xf6770 beq 0xf682c <_Z18Extension_Finalizev+0x21c> */
/* @0xf6774 bl 0xf4c28 <_ZN18CExtensionFunction5GetIdEv> */
/* @0xf6778 add r3, sp, #24 */
/* @0xf677c mov r1, #0 */
/* @0xf6780 ldr r2, [sp, #0x14] */
/* @0xf6784 bl 0xf6344 <_Z27Extension_Call_DLL_FunctioniiP6RValueS0_> */
/* @0xf6788 b 0xf66e0 <_Z18Extension_Finalizev+0xd0> */
/* @0xf678c ldr r3, [r11] */
/* @0xf6790 add r10, r10, #1 */
/* @0xf6794 cmp r3, r10 */
/* @0xf6798 bgt 0xf666c <_Z18Extension_Finalizev+0x5c> */
/* @0xf679c ldr r3, [sp, #0x24] */
/* @0xf67a0 sub r3, r3, #1 */
/* @0xf67a4 bic r3, r3, #-16777216 */
/* @0xf67a8 bic r3, r3, #3 */
/* @0xf67ac cmp r3, #0 */
/* @0xf67b0 beq 0xf6870 <_Z18Extension_Finalizev+0x260> */
/* @0xf67b4 mov r0, #1 */
/* @0xf67b8 b 0xf680c <_Z18Extension_Finalizev+0x1fc> */
/* @0xf67bc ldr r3, [pc, #0xcc] */
/* @0xf67c0 mov r1, #1 */
/* @0xf67c4 ldr r3, [pc, r3] */
/* @0xf67c8 ldr r3, [r3] */
/* @0xf67cc ldr r0, [r3] */
/* @0xf67d0 bl 0xecd7c <_Z10Error_ShowPKcb> */
/* @0xf67d4 ldr r3, [sp, #0x24] */
/* @0xf67d8 sub r3, r3, #1 */
/* @0xf67dc bic r3, r3, #-16777216 */
/* @0xf67e0 bic r3, r3, #3 */
/* @0xf67e4 cmp r3, #0 */
/* @0xf67e8 beq 0xf6864 <_Z18Extension_Finalizev+0x254> */
/* @0xf67ec mov r3, #0 */
/* @0xf67f0 mov r2, #5 */
/* @0xf67f4 str r3, [sp, #0x20] */
/* @0xf67f8 str r3, [sp, #0x18] */
/* @0xf67fc str r2, [sp, #0x24] */
/* @0xf6800 mov r0, r8 */
/* @0xf6804 bl 0x199320 <_ZN9CInstanceD2Ev> */
/* @0xf6808 mov r0, #0 */
/* @0xf680c ldr r1, [sp, #0xc] */
/* @0xf6810 ldr r2, [sp, #0x6dc] */
/* @0xf6814 ldr r3, [r1] */
/* @0xf6818 cmp r2, r3 */
/* @0xf681c bne 0xf6880 <_Z18Extension_Finalizev+0x270> */
/* @0xf6820 add sp, sp, #1760 */
/* @0xf6824 add sp, sp, #4 */
/* @0xf6828 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xf682c add r4, sp, #732 */
/* @0xf6830 mov r2, #1024 */
/* @0xf6834 mov r0, r4 */
/* @0xf6838 bl 0xb65b0 <memset@plt> */
/* @0xf683c ldr r2, [pc, #0x50] */
/* @0xf6840 mov r0, r4 */
/* @0xf6844 mov r3, r7 */
/* @0xf6848 mov r1, #1024 */
/* @0xf684c add r2, pc, r2 */
/* @0xf6850 bl 0xb65c8 <snprintf@plt> */
/* @0xf6854 mov r0, r4 */
/* @0xf6858 mov r1, #1 */
/* @0xf685c bl 0xecd7c <_Z10Error_ShowPKcb> */
/* @0xf6860 b 0xf6800 <_Z18Extension_Finalizev+0x1f0> */
/* @0xf6864 mov r0, r7 */
/* @0xf6868 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xf686c b 0xf67ec <_Z18Extension_Finalizev+0x1dc> */
/* @0xf6870 add r0, sp, #24 */
/* @0xf6874 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xf6878 mov r0, #1 */
/* @0xf687c b 0xf680c <_Z18Extension_Finalizev+0x1fc> */
/* @0xf6880 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0xf6884 eoreq r7, pc, r12, lsl #16 */
/* @0xf6888 eoreq r7, pc, r0, lsr #6 */
/* @0xf688c eorseq r12, r8, r4, ror #31 */
/* @0xf6890 eoreq r7, pc, r12, lsr #7 */
/* @0xf6894 eoreq r1, r4, r4, lsl #3 */

/* ── FUNC 0xf6898 · anon_f6898 · size=44 · insn=12 */
/* @0xf6898 ldr r3, [r0] */
/* @0xf689c ldr r2, [r1] */
/* @0xf68a0 ldrh r0, [r3] */
/* @0xf68a4 ldrh r3, [r2] */
/* @0xf68a8 rsb r0, r3, r0 */
/* @0xf68ac bx lr */
/* @0xf68b0 ldr r3, [r0] */
/* @0xf68b4 ldr r2, [r1] */
/* @0xf68b8 ldrh r0, [r3] */
/* @0xf68bc ldrh r3, [r2] */
/* @0xf68c0 rsb r0, r3, r0 */
/* @0xf68c4 bx lr */

/* ── FUNC 0xf68c8 · YYFTGlyphCache::GetLRUSlot(YYGlyph2*, int, bool) · size=944 · insn=236 */
/* @0xf68c8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xf68cc mov r4, r0 */
/* @0xf68d0 ldm r0, {r0, r5} */
/* @0xf68d4 mov r7, r3 */
/* @0xf68d8 mov r12, #0 */
/* @0xf68dc sub sp, sp, #20 */
/* @0xf68e0 ldr r3, [r5, #0x8] */
/* @0xf68e4 ldr lr, [r5, #0x4] */
/* @0xf68e8 cmp r3, r12 */
/* @0xf68ec str lr, [r4, #0x4] */
/* @0xf68f0 str r12, [lr] */
/* @0xf68f4 stm r5, {r0, r12} */
/* @0xf68f8 str r5, [r0, #0x4] */
/* @0xf68fc str r5, [r4] */
/* @0xf6900 beq 0xf691c <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x54> */
/* @0xf6904 ldr r0, [r5, #0x14] */
/* @0xf6908 cmp r0, r2 */
/* @0xf690c beq 0xf6c60 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x398> */
/* @0xf6910 mvn r2, #0 */
/* @0xf6914 strh r2, [r3, #2] */
/* @0xf6918 strh r2, [r3, #4] */
/* @0xf691c ldr r3, [r4, #0x8] */
/* @0xf6920 ldr r2, [r5, #0xc] */
/* @0xf6924 ldr r0, [r5, #0x10] */
/* @0xf6928 ldr r12, [r3] */
/* @0xf692c str r1, [r5, #0x8] */
/* @0xf6930 sub r12, r12, #6 */
/* @0xf6934 strh r2, [r1, #2] */
/* @0xf6938 cmp r12, #5 */
/* @0xf693c strh r0, [r1, #4] */
/* @0xf6940 movhi lr, #1 */
/* @0xf6944 ldrls lr, [pc, #0x328] */
/* @0xf6948 addls lr, pc, lr */
/* @0xf694c ldrls lr, [lr, r12, lsl #2] */
/* @0xf6950 ldr r6, [r3, #0x4] */
/* @0xf6954 lsl r12, r2, #2 */
/* @0xf6958 ldr r2, [r4, #0x1c] */
/* @0xf695c ldr r9, [r3, #0x28] */
/* @0xf6960 mul r6, r6, lr */
/* @0xf6964 cmp r2, #0 */
/* @0xf6968 mla r0, r6, r0, r12 */
/* @0xf696c add r10, r9, r0 */
/* @0xf6970 ble 0xf69cc <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x104> */
/* @0xf6974 ldr r3, [r4, #0x18] */
/* @0xf6978 mov r8, #0 */
/* @0xf697c mov lr, r8 */
/* @0xf6980 mvn r12, #0 */
/* @0xf6984 cmp r3, #0 */
/* @0xf6988 ble 0xf69bc <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0xf4> */
/* @0xf698c mov r2, r10 */
/* @0xf6990 mov r0, #0 */
/* @0xf6994 strb r12, [r2] */
/* @0xf6998 add r0, r0, #1 */
/* @0xf699c strb r12, [r2, #0x1] */
/* @0xf69a0 add r2, r2, #4 */
/* @0xf69a4 strb r12, [r2, #-0x2] */
/* @0xf69a8 strb lr, [r2, #-0x1] */
/* @0xf69ac ldr r3, [r4, #0x18] */
/* @0xf69b0 cmp r3, r0 */
/* @0xf69b4 bgt 0xf6994 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0xcc> */
/* @0xf69b8 ldr r2, [r4, #0x1c] */
/* @0xf69bc add r8, r8, #1 */
/* @0xf69c0 add r10, r10, r6 */
/* @0xf69c4 cmp r2, r8 */
/* @0xf69c8 bgt 0xf6984 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0xbc> */
/* @0xf69cc ldrh r1, [r1] */
/* @0xf69d0 ldr r0, [r4, #0x14] */
/* @0xf69d4 blx 0x2e5960 <FT_Get_Char_Index> */
/* @0xf69d8 mov r2, #0 */
/* @0xf69dc mov r1, r0 */
/* @0xf69e0 ldr r0, [r4, #0x14] */
/* @0xf69e4 blx 0x2e7564 <FT_Load_Glyph> */
/* @0xf69e8 cmp r0, #0 */
/* @0xf69ec bne 0xf6b10 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x248> */
/* @0xf69f0 ldr r3, [r4, #0x14] */
/* @0xf69f4 cmp r7, #0 */
/* @0xf69f8 moveq r1, #2 */
/* @0xf69fc movne r1, #0 */
/* @0xf6a00 ldr r0, [r3, #0x54] */
/* @0xf6a04 blx 0x2e5ed8 <FT_Render_Glyph> */
/* @0xf6a08 subs r8, r0, #0 */
/* @0xf6a0c bne 0xf6b10 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x248> */
/* @0xf6a10 ldr r3, [r4, #0x14] */
/* @0xf6a14 ldr r1, [r5, #0xc] */
/* @0xf6a18 ldr r2, [r5, #0x10] */
/* @0xf6a1c ldr r12, [r3, #0x54] */
/* @0xf6a20 ldr lr, [r3, #0x58] */
/* @0xf6a24 lsl r3, r1, #2 */
/* @0xf6a28 ldr r0, [r12, #0x24] */
/* @0xf6a2c ldr r7, [lr, #0x18] */
/* @0xf6a30 ldr lr, [r12, #0x4c] */
/* @0xf6a34 rsb r0, r0, r7 */
/* @0xf6a38 ldr r10, [r12, #0x54] */
/* @0xf6a3c add r0, r0, #63 */
/* @0xf6a40 cmp lr, #0 */
/* @0xf6a44 ldr r7, [r12, #0x58] */
/* @0xf6a48 add r0, r2, r0, asr #6 */
/* @0xf6a4c mla r3, r6, r0, r3 */
/* @0xf6a50 add r9, r9, r3 */
/* @0xf6a54 beq 0xf6b18 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x250> */
/* @0xf6a58 str r5, [sp, #0xc] */
/* @0xf6a5c mvn r3, #0 */
/* @0xf6a60 mov r5, r10 */
/* @0xf6a64 ldrb r2, [r12, #0x5e] */
/* @0xf6a68 sub r2, r2, #1 */
/* @0xf6a6c cmp r2, #5 */
/* @0xf6a70 addls pc, pc, r2, lsl #2 */
/* @0xf6a74 b 0xf6af8 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x230> */
/* @0xf6a78 b 0xf6a90 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x1c8> */
/* @0xf6a7c b 0xf6c20 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x358> */
/* @0xf6a80 b 0xf6bac <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x2e4> */
/* @0xf6a84 b 0xf6b38 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x270> */
/* @0xf6a88 b 0xf6c20 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x358> */
/* @0xf6a8c b 0xf6c20 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x358> */
/* @0xf6a90 ldr r2, [r12, #0x50] */
/* @0xf6a94 cmp r2, #0 */
/* @0xf6a98 beq 0xf6af8 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x230> */
/* @0xf6a9c mov r2, r9 */
/* @0xf6aa0 mov lr, r7 */
/* @0xf6aa4 mov r0, #0 */
/* @0xf6aa8 mov r1, #128 */
/* @0xf6aac b 0xf6abc <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x1f4> */
/* @0xf6ab0 cmp r1, #0 */
/* @0xf6ab4 addeq lr, lr, #1 */
/* @0xf6ab8 moveq r1, #128 */
/* @0xf6abc ldrb r10, [lr] */
/* @0xf6ac0 add r0, r0, #1 */
/* @0xf6ac4 strb r3, [r2] */
/* @0xf6ac8 add r2, r2, #4 */
/* @0xf6acc tst r10, r1 */
/* @0xf6ad0 strb r3, [r2, #-0x3] */
/* @0xf6ad4 strb r3, [r2, #-0x2] */
/* @0xf6ad8 lsr r1, r1, #1 */
/* @0xf6adc moveq r10, #0 */
/* @0xf6ae0 mvnne r10, #0 */
/* @0xf6ae4 strb r10, [r2, #-0x1] */
/* @0xf6ae8 ldr r10, [r12, #0x50] */
/* @0xf6aec cmp r10, r0 */
/* @0xf6af0 bhi 0xf6ab0 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x1e8> */
/* @0xf6af4 ldr lr, [r12, #0x4c] */
/* @0xf6af8 add r8, r8, #1 */
/* @0xf6afc add r9, r9, r6 */
/* @0xf6b00 cmp lr, r8 */
/* @0xf6b04 add r7, r7, r5 */
/* @0xf6b08 bhi 0xf6a64 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x19c> */
/* @0xf6b0c ldr r5, [sp, #0xc] */
/* @0xf6b10 ldr r1, [r5, #0xc] */
/* @0xf6b14 ldr r2, [r5, #0x10] */
/* @0xf6b18 ldr r12, [r4, #0x1c] */
/* @0xf6b1c ldr r0, [r4, #0x8] */
/* @0xf6b20 ldr r3, [r4, #0x18] */
/* @0xf6b24 str r12, [sp] */
/* @0xf6b28 bl 0x183240 <_ZN8Graphics12UpdateRegionEPviiii> */
/* @0xf6b2c mov r0, r5 */
/* @0xf6b30 add sp, sp, #20 */
/* @0xf6b34 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xf6b38 ldr r2, [r12, #0x50] */
/* @0xf6b3c cmp r2, #0 */
/* @0xf6b40 beq 0xf6af8 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x230> */
/* @0xf6b44 mov r2, r9 */
/* @0xf6b48 mov lr, r7 */
/* @0xf6b4c mov r0, #0 */
/* @0xf6b50 mov r1, #240 */
/* @0xf6b54 b 0xf6b64 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x29c> */
/* @0xf6b58 cmp r1, #0 */
/* @0xf6b5c addeq lr, lr, #1 */
/* @0xf6b60 moveq r1, #240 */
/* @0xf6b64 ldrb r10, [lr] */
/* @0xf6b68 tst r0, #1 */
/* @0xf6b6c strb r3, [r2] */
/* @0xf6b70 add r0, r0, #1 */
/* @0xf6b74 and r10, r10, r1 */
/* @0xf6b78 movne r11, #0 */
/* @0xf6b7c moveq r11, #4 */
/* @0xf6b80 strb r3, [r2, #0x1] */
/* @0xf6b84 lsr r1, r1, #4 */
/* @0xf6b88 asr r10, r10, r11 */
/* @0xf6b8c strb r3, [r2, #0x2] */
/* @0xf6b90 add r2, r2, #4 */
/* @0xf6b94 rsb r10, r10, r10, lsl #3 */
/* @0xf6b98 strb r10, [r2, #-0x1] */
/* @0xf6b9c ldr r10, [r12, #0x50] */
/* @0xf6ba0 cmp r10, r0 */
/* @0xf6ba4 bhi 0xf6b58 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x290> */
/* @0xf6ba8 b 0xf6af4 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x22c> */
/* @0xf6bac ldr r2, [r12, #0x50] */
/* @0xf6bb0 cmp r2, #0 */
/* @0xf6bb4 beq 0xf6af8 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x230> */
/* @0xf6bb8 mov r2, r9 */
/* @0xf6bbc mov lr, r7 */
/* @0xf6bc0 mov r0, #0 */
/* @0xf6bc4 mov r1, #192 */
/* @0xf6bc8 b 0xf6bd8 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x310> */
/* @0xf6bcc cmp r1, #0 */
/* @0xf6bd0 addeq lr, lr, #1 */
/* @0xf6bd4 moveq r1, #192 */
/* @0xf6bd8 ldrb r11, [lr] */
/* @0xf6bdc mvn r10, r0 */
/* @0xf6be0 and r10, r10, #3 */
/* @0xf6be4 strb r3, [r2] */
/* @0xf6be8 and r11, r11, r1 */
/* @0xf6bec strb r3, [r2, #0x1] */
/* @0xf6bf0 lsl r10, r10, #1 */
/* @0xf6bf4 strb r3, [r2, #0x2] */
/* @0xf6bf8 asr r10, r11, r10 */
/* @0xf6bfc add r0, r0, #1 */
/* @0xf6c00 lsr r1, r1, #2 */
/* @0xf6c04 add r2, r2, #4 */
/* @0xf6c08 rsb r10, r10, r10, lsl #6 */
/* @0xf6c0c strb r10, [r2, #-0x1] */
/* @0xf6c10 ldr r10, [r12, #0x50] */
/* @0xf6c14 cmp r10, r0 */
/* @0xf6c18 bhi 0xf6bcc <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x304> */
/* @0xf6c1c b 0xf6af4 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x22c> */
/* @0xf6c20 ldr r2, [r12, #0x50] */
/* @0xf6c24 cmp r2, #0 */
/* @0xf6c28 movne r1, r7 */
/* @0xf6c2c movne r2, r9 */
/* @0xf6c30 beq 0xf6af8 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x230> */
/* @0xf6c34 ldrb lr, [r1], #1 */
/* @0xf6c38 add r2, r2, #4 */
/* @0xf6c3c strb r3, [r2, #-0x4] */
/* @0xf6c40 strb r3, [r2, #-0x3] */
/* @0xf6c44 rsb r0, r7, r1 */
/* @0xf6c48 strb lr, [r2, #-0x1] */
/* @0xf6c4c strb r3, [r2, #-0x2] */
/* @0xf6c50 ldr lr, [r12, #0x50] */
/* @0xf6c54 cmp lr, r0 */
/* @0xf6c58 bhi 0xf6c34 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x36c> */
/* @0xf6c5c b 0xf6af4 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x22c> */
/* @0xf6c60 str r1, [sp, #0x8] */
/* @0xf6c64 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0xf6c68 ldr r3, [r5, #0x8] */
/* @0xf6c6c ldr r1, [sp, #0x8] */
/* @0xf6c70 b 0xf6910 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib+0x48> */
/* @0xf6c74 .word 0x00265fd0 */

/* ── FUNC 0xf6c78 · yywcslen(unsigned short const*) · size=40 · insn=10 */
/* @0xf6c78 mov r2, r0 */
/* @0xf6c7c b 0xf6c84 <_Z8yywcslenPKt+0xc> */
/* @0xf6c80 mov r2, r3 */
/* @0xf6c84 mov r3, r2 */
/* @0xf6c88 ldrh r1, [r3], #2 */
/* @0xf6c8c cmp r1, #0 */
/* @0xf6c90 bne 0xf6c80 <_Z8yywcslenPKt+0x8> */
/* @0xf6c94 rsb r0, r0, r2 */
/* @0xf6c98 asr r0, r0, #1 */
/* @0xf6c9c bx lr */

/* ── FUNC 0xf6ca0 · CFontGM::GetFont() · size=192 · insn=48 */
/* @0xf6ca0 push {r4, r5, r6, lr} */
/* @0xf6ca4 mov r5, r0 */
/* @0xf6ca8 mov r6, #0 */
/* @0xf6cac mov r0, #24 */
/* @0xf6cb0 str r6, [r5, #0x2c] */
/* @0xf6cb4 bl 0x27c524 <_Znwj> */
/* @0xf6cb8 mov r4, r0 */
/* @0xf6cbc bl 0x1a867c <_ZN5TFontC2Ev> */
/* @0xf6cc0 ldr r3, [r4] */
/* @0xf6cc4 mov r0, r4 */
/* @0xf6cc8 ldr r1, [r5, #0x4] */
/* @0xf6ccc ldr r3, [r3, #0x14] */
/* @0xf6cd0 blx r3 */
/* @0xf6cd4 ldr r3, [r4] */
/* @0xf6cd8 mov r0, r4 */
/* @0xf6cdc ldr r1, [r5, #0x8] */
/* @0xf6ce0 ldr r3, [r3, #0x1c] */
/* @0xf6ce4 blx r3 */
/* @0xf6ce8 ldr r3, [r4] */
/* @0xf6cec mov r1, r6 */
/* @0xf6cf0 mov r0, r4 */
/* @0xf6cf4 ldr r3, [r3, #0x20] */
/* @0xf6cf8 blx r3 */
/* @0xf6cfc ldrb r3, [r5, #0xc] */
/* @0xf6d00 cmp r3, r6 */
/* @0xf6d04 bne 0xf6d3c <_ZN7CFontGM7GetFontEv+0x9c> */
/* @0xf6d08 ldrb r3, [r5, #0xd] */
/* @0xf6d0c cmp r3, #0 */
/* @0xf6d10 beq 0xf6d34 <_ZN7CFontGM7GetFontEv+0x94> */
/* @0xf6d14 ldr r3, [r4] */
/* @0xf6d18 mov r0, r4 */
/* @0xf6d1c ldr r2, [r3, #0x24] */
/* @0xf6d20 ldr r5, [r3, #0x20] */
/* @0xf6d24 blx r2 */
/* @0xf6d28 orr r1, r0, #2 */
/* @0xf6d2c mov r0, r4 */
/* @0xf6d30 blx r5 */
/* @0xf6d34 mov r0, r4 */
/* @0xf6d38 pop {r4, r5, r6, pc} */
/* @0xf6d3c ldr r3, [r4] */
/* @0xf6d40 mov r0, r4 */
/* @0xf6d44 ldr r2, [r3, #0x24] */
/* @0xf6d48 ldr r6, [r3, #0x20] */
/* @0xf6d4c blx r2 */
/* @0xf6d50 orr r1, r0, #1 */
/* @0xf6d54 mov r0, r4 */
/* @0xf6d58 blx r6 */
/* @0xf6d5c b 0xf6d08 <_ZN7CFontGM7GetFontEv+0x68> */

/* ── FUNC 0xf6d60 · CFontGM::GetGlyph(int) · size=280 · insn=70 */
/* @0xf6d60 ldr r12, [r0, #0x40] */
/* @0xf6d64 push {r4, r5, r6, r7, r8, lr} */
/* @0xf6d68 subs r12, r12, #1 */
/* @0xf6d6c mov r6, r0 */
/* @0xf6d70 bmi 0xf6e68 <_ZN7CFontGM8GetGlyphEi+0x108> */
/* @0xf6d74 ldr r0, [r0, #0x44] */
/* @0xf6d78 asr r4, r12, #1 */
/* @0xf6d7c ldr r5, [r0, r4, lsl #2] */
/* @0xf6d80 ldrh r2, [r5] */
/* @0xf6d84 cmp r2, r1 */
/* @0xf6d88 beq 0xf6de4 <_ZN7CFontGM8GetGlyphEi+0x84> */
/* @0xf6d8c mov r3, #0 */
/* @0xf6d90 b 0xf6da8 <_ZN7CFontGM8GetGlyphEi+0x48> */
/* @0xf6d94 add r4, r3, r2, asr #1 */
/* @0xf6d98 ldr r5, [r0, r4, lsl #2] */
/* @0xf6d9c ldrh r2, [r5] */
/* @0xf6da0 cmp r2, r1 */
/* @0xf6da4 beq 0xf6de4 <_ZN7CFontGM8GetGlyphEi+0x84> */
/* @0xf6da8 cmp r1, r2 */
/* @0xf6dac sublt r12, r4, #1 */
/* @0xf6db0 addge r3, r4, #1 */
/* @0xf6db4 rsb r2, r3, r12 */
/* @0xf6db8 cmp r3, r12 */
/* @0xf6dbc add r2, r2, r2, lsr #31 */
/* @0xf6dc0 ble 0xf6d94 <_ZN7CFontGM8GetGlyphEi+0x34> */
/* @0xf6dc4 movw r3, #0x25af */
/* @0xf6dc8 cmp r1, r3 */
/* @0xf6dcc moveq r5, #0 */
/* @0xf6dd0 beq 0xf6e20 <_ZN7CFontGM8GetGlyphEi+0xc0> */
/* @0xf6dd4 mov r1, r3 */
/* @0xf6dd8 mov r0, r6 */
/* @0xf6ddc bl 0xf6d60 <_ZN7CFontGM8GetGlyphEi> */
/* @0xf6de0 mov r5, r0 */
/* @0xf6de4 cmp r5, #0 */
/* @0xf6de8 beq 0xf6e20 <_ZN7CFontGM8GetGlyphEi+0xc0> */
/* @0xf6dec ldr r7, [r6, #0x8c] */
/* @0xf6df0 cmp r7, #0 */
/* @0xf6df4 beq 0xf6e20 <_ZN7CFontGM8GetGlyphEi+0xc0> */
/* @0xf6df8 ldrsh r3, [r5, #2] */
/* @0xf6dfc cmn r3, #1 */
/* @0xf6e00 beq 0xf6e28 <_ZN7CFontGM8GetGlyphEi+0xc8> */
/* @0xf6e04 lsl r8, r4, #2 */
/* @0xf6e08 ldr r2, [r7, r8] */
/* @0xf6e0c cmp r2, #0 */
/* @0xf6e10 ldrne r3, [pc, #0x58] */
/* @0xf6e14 ldrne r3, [pc, r3] */
/* @0xf6e18 ldrne r3, [r3] */
/* @0xf6e1c strne r3, [r2, #0x14] */
/* @0xf6e20 mov r0, r5 */
/* @0xf6e24 pop {r4, r5, r6, r7, r8, pc} */
/* @0xf6e28 ldrsh r3, [r5, #4] */
/* @0xf6e2c cmn r3, #1 */
/* @0xf6e30 bne 0xf6e04 <_ZN7CFontGM8GetGlyphEi+0xa4> */
/* @0xf6e34 ldr r3, [r6, #0x14] */
/* @0xf6e38 add r0, r6, #92 */
/* @0xf6e3c ldr r2, [pc, #0x30] */
/* @0xf6e40 mov r1, r5 */
/* @0xf6e44 adds r3, r3, #0 */
/* @0xf6e48 lsl r8, r4, #2 */
/* @0xf6e4c ldr r2, [pc, r2] */
/* @0xf6e50 movne r3, #1 */
/* @0xf6e54 ldr r2, [r2] */
/* @0xf6e58 bl 0xf68c8 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib> */
/* @0xf6e5c str r0, [r7, r4, lsl #2] */
/* @0xf6e60 ldr r7, [r6, #0x8c] */
/* @0xf6e64 b 0xf6e08 <_ZN7CFontGM8GetGlyphEi+0xa8> */
/* @0xf6e68 mov r4, #0 */
/* @0xf6e6c b 0xf6dc4 <_ZN7CFontGM8GetGlyphEi+0x64> */
/* @0xf6e70 eoreq r7, pc, r0, lsr r0 */
/* @0xf6e74 .word 0x002f6ff8 */

/* ── FUNC 0xf6e78 · CFontGM::GetShift(int) · size=20 · insn=5 */
/* @0xf6e78 push {r3, lr} */
/* @0xf6e7c bl 0xf6d60 <_ZN7CFontGM8GetGlyphEi> */
/* @0xf6e80 cmp r0, #0 */
/* @0xf6e84 ldrshne r0, [r0, #10] */
/* @0xf6e88 pop {r3, pc} */

/* ── FUNC 0xf6e8c · CFontGM::CFontGM(unsigned char*, int, int, int) · size=496 · insn=124 */
/* @0xf6e8c ldr r12, [pc, #0x1dc] */
/* @0xf6e90 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0xf6e94 ldr r12, [pc, r12] */
/* @0xf6e98 mov r4, r0 */
/* @0xf6e9c mov r5, #0 */
/* @0xf6ea0 add r12, r12, #8 */
/* @0xf6ea4 str r5, [r0, #0x4] */
/* @0xf6ea8 str r12, [r0] */
/* @0xf6eac mov lr, #1056964608 */
/* @0xf6eb0 str r5, [r0, #0x8] */
/* @0xf6eb4 mvn r0, #0 */
/* @0xf6eb8 str r0, [r4, #0x20] */
/* @0xf6ebc mov r9, r3 */
/* @0xf6ec0 str r0, [r4, #0x38] */
/* @0xf6ec4 mov r3, #1065353216 */
/* @0xf6ec8 ldr r0, [pc, #0x1a4] */
/* @0xf6ecc mov r7, r2 */
/* @0xf6ed0 str lr, [r4, #0x50] */
/* @0xf6ed4 mov r8, r1 */
/* @0xf6ed8 str r3, [r4, #0x48] */
/* @0xf6edc add r0, pc, r0 */
/* @0xf6ee0 str r3, [r4, #0x4c] */
/* @0xf6ee4 strb r5, [r4, #0xc] */
/* @0xf6ee8 strb r5, [r4, #0xd] */
/* @0xf6eec str r5, [r4, #0x18] */
/* @0xf6ef0 str r5, [r4, #0x1c] */
/* @0xf6ef4 str r5, [r4, #0x24] */
/* @0xf6ef8 str r5, [r4, #0x28] */
/* @0xf6efc str r5, [r4, #0x2c] */
/* @0xf6f00 str r5, [r4, #0x40] */
/* @0xf6f04 str r5, [r4, #0x44] */
/* @0xf6f08 str r5, [r4, #0x5c] */
/* @0xf6f0c str r5, [r4, #0x60] */
/* @0xf6f10 str r5, [r4, #0x64] */
/* @0xf6f14 str r5, [r4, #0x6c] */
/* @0xf6f18 str r5, [r4, #0x70] */
/* @0xf6f1c str r5, [r4, #0x74] */
/* @0xf6f20 str r5, [r4, #0x78] */
/* @0xf6f24 str r5, [r4, #0x7c] */
/* @0xf6f28 str r5, [r4, #0x80] */
/* @0xf6f2c str r5, [r4, #0x84] */
/* @0xf6f30 str r5, [r4, #0x88] */
/* @0xf6f34 str r5, [r4, #0x3c] */
/* @0xf6f38 str r5, [r4, #0x34] */
/* @0xf6f3c str r5, [r4, #0x30] */
/* @0xf6f40 ldr r6, [sp, #0x20] */
/* @0xf6f44 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xf6f48 add r1, r9, #1 */
/* @0xf6f4c str r7, [r4, #0x18] */
/* @0xf6f50 rsb r1, r7, r1 */
/* @0xf6f54 str r1, [r4, #0x40] */
/* @0xf6f58 mov lr, #10 */
/* @0xf6f5c mov r2, #243 */
/* @0xf6f60 add r12, r1, r1, lsl #2 */
/* @0xf6f64 mov r1, #3 */
/* @0xf6f68 str r1, [r4, #0x14] */
/* @0xf6f6c mov r3, #1 */
/* @0xf6f70 ldr r1, [pc, #0x100] */
/* @0xf6f74 strb r5, [r4, #0xc] */
/* @0xf6f78 strb r5, [r4, #0xd] */
/* @0xf6f7c add r1, pc, r1 */
/* @0xf6f80 str r9, [r4, #0x1c] */
/* @0xf6f84 str r5, [r4, #0x10] */
/* @0xf6f88 str r5, [r4, #0x54] */
/* @0xf6f8c str r5, [r4, #0x8c] */
/* @0xf6f90 str lr, [r4, #0x8] */
/* @0xf6f94 str r0, [r4, #0x4] */
/* @0xf6f98 lsl r0, r12, #2 */
/* @0xf6f9c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xf6fa0 ldr r2, [r4, #0x18] */
/* @0xf6fa4 ldr r7, [r4, #0x1c] */
/* @0xf6fa8 ldr r3, [r4, #0x40] */
/* @0xf6fac cmp r2, r7 */
/* @0xf6fb0 str r0, [r4, #0x44] */
/* @0xf6fb4 add r3, r0, r3, lsl #2 */
/* @0xf6fb8 bgt 0xf7024 <_ZN7CFontGMC2EPhiii+0x198> */
/* @0xf6fbc add r3, r3, #16 */
/* @0xf6fc0 sub r0, r0, #4 */
/* @0xf6fc4 add r7, r7, #1 */
/* @0xf6fc8 mov r1, r8 */
/* @0xf6fcc sub r12, r3, #16 */
/* @0xf6fd0 str r12, [r0, #0x4]! */
/* @0xf6fd4 strh r2, [r3, #-16] */
/* @0xf6fd8 add r2, r2, #1 */
/* @0xf6fdc ldrb r12, [r1] */
/* @0xf6fe0 add r3, r3, #16 */
/* @0xf6fe4 ldr lr, [r4, #0x2c] */
/* @0xf6fe8 add r1, r1, #4 */
/* @0xf6fec strh r12, [r3, #-30] */
/* @0xf6ff0 ldrb r12, [r1, #-0x3] */
/* @0xf6ff4 strh r12, [r3, #-28] */
/* @0xf6ff8 ldrb r12, [r1, #-0x2] */
/* @0xf6ffc strh r12, [r3, #-26] */
/* @0xf7000 ldrb r12, [r1, #-0x1] */
/* @0xf7004 cmp r12, lr */
/* @0xf7008 strh r12, [r3, #-24] */
/* @0xf700c ldrb lr, [r1, #-0x2] */
/* @0xf7010 strh r5, [r3, #-20] */
/* @0xf7014 strh lr, [r3, #-22] */
/* @0xf7018 strgt r12, [r4, #0x2c] */
/* @0xf701c cmp r2, r7 */
/* @0xf7020 bne 0xf6fcc <_ZN7CFontGMC2EPhiii+0x140> */
/* @0xf7024 mov r0, #22 */
/* @0xf7028 bl 0xb6544 <malloc@plt> */
/* @0xf702c mov r3, #0 */
/* @0xf7030 mov r1, #256 */
/* @0xf7034 mov r2, #128 */
/* @0xf7038 strh r6, [r0, #20] */
/* @0xf703c str r0, [r4, #0x3c] */
/* @0xf7040 strh r3, [r0] */
/* @0xf7044 strh r3, [r0, #2] */
/* @0xf7048 strh r3, [r0, #8] */
/* @0xf704c strh r3, [r0, #10] */
/* @0xf7050 strh r1, [r0, #4] */
/* @0xf7054 strh r1, [r0, #12] */
/* @0xf7058 strh r1, [r0, #16] */
/* @0xf705c strh r2, [r0, #6] */
/* @0xf7060 strh r2, [r0, #14] */
/* @0xf7064 strh r2, [r0, #18] */
/* @0xf7068 mov r0, r4 */
/* @0xf706c pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0xf7070 .word 0x002f6fb4 */
/* @0xf7074 eoreq r0, r4, r0, lsr #22 */
/* @0xf7078 eoreq r0, r4, r8, lsl #21 */

/* ── FUNC 0xf6e8c · CFontGM::CFontGM(unsigned char*, int, int, int) · alias of the symbol above · insn=0 */

/* ── FUNC 0xf707c · CFontGM::FreeTexture() · size=36 · insn=9 */
/* @0xf707c push {r4, lr} */
/* @0xf7080 mov r4, r0 */
/* @0xf7084 ldr r0, [r0, #0x38] */
/* @0xf7088 cmp r0, #0 */
/* @0xf708c blt 0xf7094 <_ZN7CFontGM11FreeTextureEv+0x18> */
/* @0xf7090 bl 0x173f84 <_Z15GR_Texture_Freei> */
/* @0xf7094 mvn r3, #0 */
/* @0xf7098 str r3, [r4, #0x38] */
/* @0xf709c pop {r4, pc} */

/* ── FUNC 0xf70a0 · CFontGM::Clear() · size=296 · insn=74 */
/* @0xf70a0 push {r4, r5, r6, lr} */
/* @0xf70a4 mov r4, r0 */
/* @0xf70a8 ldr r0, [r0, #0x4] */
/* @0xf70ac cmp r0, #0 */
/* @0xf70b0 beq 0xf70c0 <_ZN7CFontGM5ClearEv+0x20> */
/* @0xf70b4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xf70b8 mov r3, #0 */
/* @0xf70bc str r3, [r4, #0x4] */
/* @0xf70c0 ldr r0, [r4, #0x54] */
/* @0xf70c4 mov r5, #0 */
/* @0xf70c8 mov r3, #1065353216 */
/* @0xf70cc mov r2, #12 */
/* @0xf70d0 cmp r0, r5 */
/* @0xf70d4 mov r1, #32 */
/* @0xf70d8 str r2, [r4, #0x8] */
/* @0xf70dc mov r2, #128 */
/* @0xf70e0 str r1, [r4, #0x18] */
/* @0xf70e4 mov r1, #0 */
/* @0xf70e8 str r2, [r4, #0x1c] */
/* @0xf70ec mvn r2, #0 */
/* @0xf70f0 strb r5, [r4, #0xc] */
/* @0xf70f4 strb r5, [r4, #0xd] */
/* @0xf70f8 str r1, [r4, #0x50] */
/* @0xf70fc str r2, [r4, #0x20] */
/* @0xf7100 str r3, [r4, #0x48] */
/* @0xf7104 str r3, [r4, #0x4c] */
/* @0xf7108 beq 0xf7114 <_ZN7CFontGM5ClearEv+0x74> */
/* @0xf710c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xf7110 str r5, [r4, #0x54] */
/* @0xf7114 ldr r0, [r4, #0x70] */
/* @0xf7118 cmp r0, #0 */
/* @0xf711c beq 0xf7164 <_ZN7CFontGM5ClearEv+0xc4> */
/* @0xf7120 blx 0x2e8bdc <FT_Done_Face> */
/* @0xf7124 ldr r3, [r4, #0x40] */
/* @0xf7128 cmp r3, #0 */
/* @0xf712c movgt r5, #0 */
/* @0xf7130 movgt r6, r5 */
/* @0xf7134 ble 0xf715c <_ZN7CFontGM5ClearEv+0xbc> */
/* @0xf7138 ldr r3, [r4, #0x44] */
/* @0xf713c ldr r0, [r3, r5, lsl #2] */
/* @0xf7140 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xf7144 ldr r2, [r4, #0x44] */
/* @0xf7148 ldr r3, [r4, #0x40] */
/* @0xf714c str r6, [r2, r5, lsl #2] */
/* @0xf7150 add r5, r5, #1 */
/* @0xf7154 cmp r3, r5 */
/* @0xf7158 bgt 0xf7138 <_ZN7CFontGM5ClearEv+0x98> */
/* @0xf715c mov r3, #0 */
/* @0xf7160 str r3, [r4, #0x70] */
/* @0xf7164 ldr r0, [r4, #0x44] */
/* @0xf7168 cmp r0, #0 */
/* @0xf716c beq 0xf717c <_ZN7CFontGM5ClearEv+0xdc> */
/* @0xf7170 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xf7174 mov r3, #0 */
/* @0xf7178 str r3, [r4, #0x44] */
/* @0xf717c ldr r0, [r4, #0x8c] */
/* @0xf7180 cmp r0, #0 */
/* @0xf7184 beq 0xf7194 <_ZN7CFontGM5ClearEv+0xf4> */
/* @0xf7188 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xf718c mov r3, #0 */
/* @0xf7190 str r3, [r4, #0x8c] */
/* @0xf7194 mov r0, r4 */
/* @0xf7198 bl 0xf707c <_ZN7CFontGM11FreeTextureEv> */
/* @0xf719c ldr r0, [r4, #0x34] */
/* @0xf71a0 cmp r0, #0 */
/* @0xf71a4 beq 0xf71ac <_ZN7CFontGM5ClearEv+0x10c> */
/* @0xf71a8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xf71ac mov r3, #0 */
/* @0xf71b0 mvn r2, #0 */
/* @0xf71b4 str r3, [r4, #0x34] */
/* @0xf71b8 str r3, [r4, #0x30] */
/* @0xf71bc str r3, [r4, #0x2c] */
/* @0xf71c0 str r2, [r4, #0x38] */
/* @0xf71c4 pop {r4, r5, r6, pc} */

/* ── FUNC 0xf71c8 · CFontGM::CFontGM() · size=168 · insn=42 */
/* @0xf71c8 ldr r3, [pc, #0x9c] */
/* @0xf71cc mov r1, #1056964608 */
/* @0xf71d0 push {r4, lr} */
/* @0xf71d4 ldr r3, [pc, r3] */
/* @0xf71d8 mov r4, r0 */
/* @0xf71dc str r1, [r0, #0x50] */
/* @0xf71e0 mvn r2, #0 */
/* @0xf71e4 str r2, [r0, #0x38] */
/* @0xf71e8 add r2, r3, #8 */
/* @0xf71ec mov r3, #0 */
/* @0xf71f0 stm r0, {r2, r3} */
/* @0xf71f4 str r3, [r0, #0x8] */
/* @0xf71f8 strb r3, [r0, #0xc] */
/* @0xf71fc strb r3, [r0, #0xd] */
/* @0xf7200 str r3, [r0, #0x18] */
/* @0xf7204 str r3, [r0, #0x1c] */
/* @0xf7208 str r3, [r0, #0x20] */
/* @0xf720c str r3, [r0, #0x24] */
/* @0xf7210 str r3, [r0, #0x28] */
/* @0xf7214 str r3, [r0, #0x2c] */
/* @0xf7218 str r3, [r0, #0x40] */
/* @0xf721c str r3, [r0, #0x44] */
/* @0xf7220 str r3, [r0, #0x5c] */
/* @0xf7224 str r3, [r0, #0x60] */
/* @0xf7228 str r3, [r0, #0x64] */
/* @0xf722c str r3, [r0, #0x6c] */
/* @0xf7230 str r3, [r0, #0x70] */
/* @0xf7234 str r3, [r0, #0x74] */
/* @0xf7238 str r3, [r0, #0x78] */
/* @0xf723c str r3, [r0, #0x7c] */
/* @0xf7240 str r3, [r0, #0x80] */
/* @0xf7244 str r3, [r0, #0x84] */
/* @0xf7248 str r3, [r0, #0x88] */
/* @0xf724c str r3, [r0, #0x3c] */
/* @0xf7250 str r3, [r0, #0x34] */
/* @0xf7254 str r3, [r0, #0x30] */
/* @0xf7258 str r3, [r0, #0x54] */
/* @0xf725c str r3, [r0, #0x8c] */
/* @0xf7260 bl 0xf70a0 <_ZN7CFontGM5ClearEv> */
/* @0xf7264 mov r0, r4 */
/* @0xf7268 pop {r4, pc} */
/* @0xf726c eoreq r6, pc, r4, ror r12 */

/* ── FUNC 0xf71c8 · CFontGM::CFontGM() · alias of the symbol above · insn=0 */

/* ── FUNC 0xf7270 · CFontGM::CFontGM(int, char const*, bool, int) · size=1052 · insn=263 */
/* @0xf7270 ldr r12, [pc, #0x404] */
/* @0xf7274 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xf7278 add r11, sp, #32 */
/* @0xf727c sub sp, sp, #68 */
/* @0xf7280 mov r5, #0 */
/* @0xf7284 str r12, [r11, #-0x4c] */
/* @0xf7288 ldr lr, [r11, #-0x4c] */
/* @0xf728c mov r7, r1 */
/* @0xf7290 ldr r12, [pc, #0x3e8] */
/* @0xf7294 mvn r1, #0 */
/* @0xf7298 ldr lr, [pc, lr] */
/* @0xf729c str lr, [r11, #-0x4c] */
/* @0xf72a0 ldr r12, [pc, r12] */
/* @0xf72a4 str r1, [r0, #0x20] */
/* @0xf72a8 ldr lr, [lr] */
/* @0xf72ac add r12, r12, #8 */
/* @0xf72b0 str r1, [r0, #0x38] */
/* @0xf72b4 mov r8, #1056964608 */
/* @0xf72b8 str r12, [r0] */
/* @0xf72bc mov r6, r2 */
/* @0xf72c0 str lr, [r11, #-0x28] */
/* @0xf72c4 mov r4, r0 */
/* @0xf72c8 str r3, [r11, #-0x58] */
/* @0xf72cc mov r3, #1065353216 */
/* @0xf72d0 str r5, [r0, #0x4] */
/* @0xf72d4 str r3, [r0, #0x48] */
/* @0xf72d8 str r3, [r0, #0x4c] */
/* @0xf72dc str r8, [r0, #0x50] */
/* @0xf72e0 str r5, [r0, #0x8] */
/* @0xf72e4 strb r5, [r0, #0xc] */
/* @0xf72e8 strb r5, [r0, #0xd] */
/* @0xf72ec str r5, [r0, #0x18] */
/* @0xf72f0 str r5, [r0, #0x1c] */
/* @0xf72f4 str r5, [r0, #0x24] */
/* @0xf72f8 str r5, [r0, #0x28] */
/* @0xf72fc str r5, [r0, #0x40] */
/* @0xf7300 str r5, [r0, #0x44] */
/* @0xf7304 str r5, [r0, #0x5c] */
/* @0xf7308 str r5, [r0, #0x60] */
/* @0xf730c str r5, [r0, #0x64] */
/* @0xf7310 str r5, [r0, #0x6c] */
/* @0xf7314 str r5, [r0, #0x70] */
/* @0xf7318 str r5, [r0, #0x74] */
/* @0xf731c str r5, [r0, #0x78] */
/* @0xf7320 str r5, [r0, #0x7c] */
/* @0xf7324 str r5, [r0, #0x80] */
/* @0xf7328 str r5, [r0, #0x84] */
/* @0xf732c str r5, [r0, #0x88] */
/* @0xf7330 str r5, [r0, #0x3c] */
/* @0xf7334 str r5, [r0, #0x34] */
/* @0xf7338 str r5, [r0, #0x30] */
/* @0xf733c str r5, [r0, #0x54] */
/* @0xf7340 str r5, [r0, #0x8c] */
/* @0xf7344 bl 0xf70a0 <_ZN7CFontGM5ClearEv> */
/* @0xf7348 mov r0, r7 */
/* @0xf734c bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0xf7350 cmp r0, r5 */
/* @0xf7354 bne 0xf7378 <_ZN7CFontGMC2EiPKcbi+0x108> */
/* @0xf7358 ldr r12, [r11, #-0x4c] */
/* @0xf735c mov r0, r4 */
/* @0xf7360 ldr r2, [r11, #-0x28] */
/* @0xf7364 ldr r3, [r12] */
/* @0xf7368 cmp r2, r3 */
/* @0xf736c bne 0xf7678 <_ZN7CFontGMC2EiPKcbi+0x408> */
/* @0xf7370 sub sp, r11, #32 */
/* @0xf7374 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xf7378 mov r0, r7 */
/* @0xf737c bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0xf7380 str r7, [r4, #0x20] */
/* @0xf7384 mov r8, r0 */
/* @0xf7388 mov r0, r6 */
/* @0xf738c bl 0x110648 <utf8_strlen> */
/* @0xf7390 str r6, [r11, #-0x3c] */
/* @0xf7394 lsl r3, r0, #2 */
/* @0xf7398 cmp r0, r5 */
/* @0xf739c add r3, r3, #22 */
/* @0xf73a0 mov r7, r0 */
/* @0xf73a4 bic r3, r3, #7 */
/* @0xf73a8 sub sp, sp, r3 */
/* @0xf73ac str sp, [r11, #-0x48] */
/* @0xf73b0 ble 0xf7648 <_ZN7CFontGMC2EiPKcbi+0x3d8> */
/* @0xf73b4 sub r6, sp, #4 */
/* @0xf73b8 sub r9, r11, #60 */
/* @0xf73bc mov r10, r5 */
/* @0xf73c0 mov r0, r9 */
/* @0xf73c4 add r10, r10, #1 */
/* @0xf73c8 bl 0x10fb38 <utf8_extract_char> */
/* @0xf73cc cmp r0, #32 */
/* @0xf73d0 str r0, [r6, #0x4]! */
/* @0xf73d4 moveq r5, #1 */
/* @0xf73d8 cmp r10, r7 */
/* @0xf73dc bne 0xf73c0 <_ZN7CFontGMC2EiPKcbi+0x150> */
/* @0xf73e0 ldr r3, [r8, #0x18] */
/* @0xf73e4 cmp r3, r10 */
/* @0xf73e8 movge r3, r10 */
/* @0xf73ec cmp r5, #0 */
/* @0xf73f0 str r3, [r11, #-0x50] */
/* @0xf73f4 movne r12, #0 */
/* @0xf73f8 strne r12, [r11, #-0x60] */
/* @0xf73fc beq 0xf7654 <_ZN7CFontGMC2EiPKcbi+0x3e4> */
/* @0xf7400 ldr r12, [r11, #-0x50] */
/* @0xf7404 movw r2, #0x16d */
/* @0xf7408 ldr r1, [pc, #0x274] */
/* @0xf740c mov r3, #1 */
/* @0xf7410 add r0, r12, r12, lsl #2 */
/* @0xf7414 str r12, [r4, #0x40] */
/* @0xf7418 add r1, pc, r1 */
/* @0xf741c lsl r0, r0, #2 */
/* @0xf7420 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xf7424 ldr r12, [r11, #-0x50] */
/* @0xf7428 ldr r1, [r4, #0x40] */
/* @0xf742c cmp r12, #0 */
/* @0xf7430 str r0, [r4, #0x44] */
/* @0xf7434 add r5, r0, r1, lsl #2 */
/* @0xf7438 ble 0xf7604 <_ZN7CFontGMC2EiPKcbi+0x394> */
/* @0xf743c ldr lr, [r11, #-0x48] */
/* @0xf7440 mov r6, #0 */
/* @0xf7444 ldr r2, [r11, #0x4] */
/* @0xf7448 sub r0, r0, #4 */
/* @0xf744c sub r12, lr, #4 */
/* @0xf7450 movw r1, #0xfc19 */
/* @0xf7454 sub r3, r11, #56 */
/* @0xf7458 movt r1, #0xffff */
/* @0xf745c uxth r2, r2 */
/* @0xf7460 str r4, [r11, #-0x40] */
/* @0xf7464 add r5, r5, #16 */
/* @0xf7468 str r0, [r11, #-0x44] */
/* @0xf746c str r2, [r11, #-0x54] */
/* @0xf7470 mov r10, r6 */
/* @0xf7474 str r1, [r11, #-0x48] */
/* @0xf7478 mov r9, r6 */
/* @0xf747c str r3, [r11, #-0x5c] */
/* @0xf7480 mov r4, r12 */
/* @0xf7484 b 0xf7588 <_ZN7CFontGMC2EiPKcbi+0x318> */
/* @0xf7488 ldr r12, [r11, #-0x58] */
/* @0xf748c cmp r12, #0 */
/* @0xf7490 beq 0xf75b4 <_ZN7CFontGMC2EiPKcbi+0x344> */
/* @0xf7494 ldr r3, [r8, #0x54] */
/* @0xf7498 cmp r3, #0 */
/* @0xf749c beq 0xf7634 <_ZN7CFontGMC2EiPKcbi+0x3c4> */
/* @0xf74a0 mov r0, #16 */
/* @0xf74a4 str r2, [r11, #-0x64] */
/* @0xf74a8 bl 0x27c524 <_Znwj> */
/* @0xf74ac ldr r2, [r11, #-0x64] */
/* @0xf74b0 ldr r3, [r8, #0x54] */
/* @0xf74b4 ldr r3, [r3, r2] */
/* @0xf74b8 ldrsh r1, [r3, #8] */
/* @0xf74bc ldrsh r2, [r3, #10] */
/* @0xf74c0 mov r12, r0 */
/* @0xf74c4 ldrsh r0, [r3, #12] */
/* @0xf74c8 ldrsh r3, [r3, #14] */
/* @0xf74cc str r1, [r12] */
/* @0xf74d0 add r1, r1, r0 */
/* @0xf74d4 add r3, r2, r3 */
/* @0xf74d8 str r1, [r12, #0x8] */
/* @0xf74dc str r3, [r12, #0xc] */
/* @0xf74e0 str r2, [r12, #0x4] */
/* @0xf74e4 ldr r0, [r12] */
/* @0xf74e8 sub lr, r11, #56 */
/* @0xf74ec ldr r1, [r12, #0x4] */
/* @0xf74f0 ldr r2, [r12, #0x8] */
/* @0xf74f4 ldr r3, [r12, #0xc] */
/* @0xf74f8 stm lr!, {r0, r1, r2, r3} */
/* @0xf74fc mov r0, r12 */
/* @0xf7500 bl 0x27d1d0 <_ZdlPv> */
/* @0xf7504 ldrh r1, [r11, #-56] */
/* @0xf7508 ldr r3, [r8, #0x20] */
/* @0xf750c rsb r2, r1, #0 */
/* @0xf7510 ldr r0, [r11, #-0x30] */
/* @0xf7514 uxth r2, r2 */
/* @0xf7518 ldr lr, [r11, #-0x40] */
/* @0xf751c uxth r3, r3 */
/* @0xf7520 rsb r1, r1, r0 */
/* @0xf7524 ldr r12, [lr, #0x2c] */
/* @0xf7528 strh r3, [r5, #-8] */
/* @0xf752c sxth r3, r3 */
/* @0xf7530 cmp r3, r12 */
/* @0xf7534 ldr r12, [r11, #-0x54] */
/* @0xf7538 strh r7, [r5, #-16] */
/* @0xf753c strh r6, [r5, #-10] */
/* @0xf7540 add r1, r12, r1 */
/* @0xf7544 strgt r3, [lr, #0x2c] */
/* @0xf7548 cmp r7, #32 */
/* @0xf754c uxth r1, r1 */
/* @0xf7550 strh r2, [r5, #-4] */
/* @0xf7554 strh r9, [r5, #-2] */
/* @0xf7558 strh r1, [r5, #-6] */
/* @0xf755c beq 0xf7574 <_ZN7CFontGMC2EiPKcbi+0x304> */
/* @0xf7560 ldr r12, [r11, #-0x48] */
/* @0xf7564 sxth r1, r1 */
/* @0xf7568 cmp r12, r1 */
/* @0xf756c movlt r12, r1 */
/* @0xf7570 str r12, [r11, #-0x48] */
/* @0xf7574 ldr r12, [r11, #-0x50] */
/* @0xf7578 add r6, r6, #1 */
/* @0xf757c add r5, r5, #16 */
/* @0xf7580 cmp r6, r12 */
/* @0xf7584 beq 0xf75dc <_ZN7CFontGMC2EiPKcbi+0x36c> */
/* @0xf7588 ldr r7, [r4, #0x4]! */
/* @0xf758c sub r3, r5, #16 */
/* @0xf7590 ldr r12, [r11, #-0x44] */
/* @0xf7594 lsl r2, r6, #2 */
/* @0xf7598 cmp r7, #32 */
/* @0xf759c str r3, [r12, #0x4]! */
/* @0xf75a0 moveq r10, r3 */
/* @0xf75a4 ldr r3, [r8, #0x18] */
/* @0xf75a8 str r12, [r11, #-0x44] */
/* @0xf75ac cmp r3, r6 */
/* @0xf75b0 bgt 0xf7488 <_ZN7CFontGMC2EiPKcbi+0x218> */
/* @0xf75b4 ldr r12, [r8, #0x1c] */
/* @0xf75b8 mov r2, #0 */
/* @0xf75bc ldr r3, [r8, #0x20] */
/* @0xf75c0 mov r1, r2 */
/* @0xf75c4 str r9, [r11, #-0x38] */
/* @0xf75c8 str r9, [r11, #-0x34] */
/* @0xf75cc mov r0, r12 */
/* @0xf75d0 str r12, [r11, #-0x30] */
/* @0xf75d4 str r3, [r11, #-0x2c] */
/* @0xf75d8 b 0xf7518 <_ZN7CFontGMC2EiPKcbi+0x2a8> */
/* @0xf75dc ldr r3, [r11, #-0x60] */
/* @0xf75e0 ldr r4, [r11, #-0x40] */
/* @0xf75e4 cmp r10, #0 */
/* @0xf75e8 moveq r3, #0 */
/* @0xf75ec andne r3, r3, #1 */
/* @0xf75f0 cmp r3, #0 */
/* @0xf75f4 ldr r0, [r4, #0x44] */
/* @0xf75f8 ldrne r12, [r11, #-0x48] */
/* @0xf75fc ldr r1, [r4, #0x40] */
/* @0xf7600 strhne r12, [r10, #10] */
/* @0xf7604 ldr r3, [pc, #0x7c] */
/* @0xf7608 mov r2, #4 */
/* @0xf760c add r3, pc, r3 */
/* @0xf7610 bl 0xb66dc <qsort@plt> */
/* @0xf7614 ldr r3, [r4, #0x44] */
/* @0xf7618 ldr r2, [r4, #0x40] */
/* @0xf761c ldr r3, [r3] */
/* @0xf7620 ldrh r3, [r3] */
/* @0xf7624 add r2, r3, r2 */
/* @0xf7628 str r2, [r4, #0x1c] */
/* @0xf762c str r3, [r4, #0x18] */
/* @0xf7630 b 0xf7358 <_ZN7CFontGMC2EiPKcbi+0xe8> */
/* @0xf7634 mov r0, r8 */
/* @0xf7638 mov r1, r6 */
/* @0xf763c bl 0x1e63d4 <_ZN7CSprite17GetBoundingBoxImgEi> */
/* @0xf7640 mov r12, r0 */
/* @0xf7644 b 0xf74e4 <_ZN7CFontGMC2EiPKcbi+0x274> */
/* @0xf7648 ldr r3, [r8, #0x18] */
/* @0xf764c and r3, r3, r3, asr #31 */
/* @0xf7650 str r3, [r11, #-0x50] */
/* @0xf7654 mov r12, #1 */
/* @0xf7658 ldr lr, [r11, #-0x48] */
/* @0xf765c str r12, [r11, #-0x60] */
/* @0xf7660 mov r3, #32 */
/* @0xf7664 ldr r12, [r11, #-0x50] */
/* @0xf7668 str r3, [lr, r12, lsl #2] */
/* @0xf766c add r12, r12, #1 */
/* @0xf7670 str r12, [r11, #-0x50] */
/* @0xf7674 b 0xf7400 <_ZN7CFontGMC2EiPKcbi+0x190> */
/* @0xf7678 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0xf767c .word 0x002f66b8 */
/* @0xf7680 eoreq r6, pc, r8, lsr #23 */
/* @0xf7684 eoreq r0, r4, r12, ror #11 */
/* @0xf7688 .word 0xfffff284 */

/* ── FUNC 0xf7270 · CFontGM::CFontGM(int, char const*, bool, int) · alias of the symbol above · insn=0 */

/* ── FUNC 0xf768c · CFontGM::CFontGM(YYEmbeddedFont*) · size=788 · insn=197 */
/* @0xf768c ldr r3, [pc, #0x2fc] */
/* @0xf7690 mov r12, #1056964608 */
/* @0xf7694 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xf7698 ldr r3, [pc, r3] */
/* @0xf769c mov r5, #0 */
/* @0xf76a0 str r12, [r0, #0x50] */
/* @0xf76a4 sub sp, sp, #12 */
/* @0xf76a8 mvn r2, #0 */
/* @0xf76ac str r5, [r0, #0x4] */
/* @0xf76b0 add r3, r3, #8 */
/* @0xf76b4 str r2, [r0, #0x20] */
/* @0xf76b8 mov r4, r0 */
/* @0xf76bc str r3, [r0] */
/* @0xf76c0 mov r3, #1065353216 */
/* @0xf76c4 str r2, [r0, #0x38] */
/* @0xf76c8 mov r6, r1 */
/* @0xf76cc str r5, [r0, #0x8] */
/* @0xf76d0 strb r5, [r0, #0xc] */
/* @0xf76d4 strb r5, [r0, #0xd] */
/* @0xf76d8 str r5, [r0, #0x18] */
/* @0xf76dc str r5, [r0, #0x1c] */
/* @0xf76e0 str r5, [r0, #0x24] */
/* @0xf76e4 str r5, [r0, #0x28] */
/* @0xf76e8 str r5, [r0, #0x2c] */
/* @0xf76ec str r5, [r0, #0x40] */
/* @0xf76f0 str r5, [r0, #0x44] */
/* @0xf76f4 str r5, [r0, #0x5c] */
/* @0xf76f8 str r5, [r0, #0x60] */
/* @0xf76fc str r3, [r0, #0x48] */
/* @0xf7700 str r3, [r0, #0x4c] */
/* @0xf7704 str r5, [r0, #0x64] */
/* @0xf7708 str r5, [r0, #0x6c] */
/* @0xf770c str r5, [r0, #0x70] */
/* @0xf7710 str r5, [r0, #0x74] */
/* @0xf7714 str r5, [r0, #0x78] */
/* @0xf7718 str r5, [r0, #0x7c] */
/* @0xf771c str r5, [r0, #0x80] */
/* @0xf7720 str r5, [r0, #0x84] */
/* @0xf7724 str r5, [r0, #0x88] */
/* @0xf7728 str r5, [r0, #0x3c] */
/* @0xf772c str r5, [r0, #0x34] */
/* @0xf7730 str r5, [r0, #0x30] */
/* @0xf7734 str r5, [r0, #0x54] */
/* @0xf7738 str r5, [r0, #0x8c] */
/* @0xf773c bl 0xf70a0 <_ZN7CFontGM5ClearEv> */
/* @0xf7740 ldr r1, [pc, #0x24c] */
/* @0xf7744 mov r3, #1 */
/* @0xf7748 mov r2, #70 */
/* @0xf774c add r1, pc, r1 */
/* @0xf7750 ldr r0, [r6, #0x30] */
/* @0xf7754 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xf7758 ldr r2, [r6, #0x30] */
/* @0xf775c ldr r1, [r6, #0x34] */
/* @0xf7760 bl 0xb65bc <memcpy@plt> */
/* @0xf7764 ldr r1, [r6, #0x30] */
/* @0xf7768 bl 0x173b20 <_Z27GR_Texture_Create_From_FilePhj> */
/* @0xf776c ldr r3, [pc, #0x224] */
/* @0xf7770 ldr r3, [pc, r3] */
/* @0xf7774 ldr r3, [r3, #0x4] */
/* @0xf7778 mov r7, r0 */
/* @0xf777c mov r0, #22 */
/* @0xf7780 ldr r8, [r3, r7, lsl #2] */
/* @0xf7784 bl 0xb6544 <malloc@plt> */
/* @0xf7788 ldr r9, [r6, #0xc] */
/* @0xf778c ldr lr, [r6, #0x10] */
/* @0xf7790 subs r9, r9, r5 */
/* @0xf7794 ldr r2, [r6, #0x14] */
/* @0xf7798 ldrh r12, [r8, #4] */
/* @0xf779c ldrh r1, [r8, #6] */
/* @0xf77a0 movne r9, #1 */
/* @0xf77a4 subs lr, lr, r5 */
/* @0xf77a8 ldr r8, [r6, #0x8] */
/* @0xf77ac movne lr, #1 */
/* @0xf77b0 mov r3, r0 */
/* @0xf77b4 str r0, [r4, #0x3c] */
/* @0xf77b8 ubfx r0, r2, #0x10, #0x8 */
/* @0xf77bc strh r5, [r3] */
/* @0xf77c0 strh r5, [r3, #2] */
/* @0xf77c4 cmp r0, r5 */
/* @0xf77c8 strh r12, [r3, #4] */
/* @0xf77cc strh r1, [r3, #6] */
/* @0xf77d0 strh r12, [r3, #12] */
/* @0xf77d4 strh r1, [r3, #14] */
/* @0xf77d8 strh r12, [r3, #16] */
/* @0xf77dc sxth r12, r12 */
/* @0xf77e0 strh r1, [r3, #18] */
/* @0xf77e4 sxth r1, r1 */
/* @0xf77e8 strh r5, [r3, #8] */
/* @0xf77ec strh r5, [r3, #10] */
/* @0xf77f0 uxth r5, r2 */
/* @0xf77f4 strh r7, [r3, #20] */
/* @0xf77f8 strne r0, [r4, #0x10] */
/* @0xf77fc lsrs r3, r2, #24 */
/* @0xf7800 subne r3, r3, #1 */
/* @0xf7804 strne r3, [r4, #0x14] */
/* @0xf7808 ldr r3, [r6, #0x24] */
/* @0xf780c ldr r0, [r6, #0x2c] */
/* @0xf7810 str r2, [r4, #0x18] */
/* @0xf7814 add r2, r3, r3, lsl #2 */
/* @0xf7818 strb lr, [r4, #0xd] */
/* @0xf781c ldr lr, [r6, #0x18] */
/* @0xf7820 lsl r2, r2, #2 */
/* @0xf7824 str r12, [r4, #0x24] */
/* @0xf7828 add r0, r2, r0, lsl #2 */
/* @0xf782c ldr r12, [r6, #0x1c] */
/* @0xf7830 ldr r2, [r6, #0x20] */
/* @0xf7834 str r1, [r4, #0x28] */
/* @0xf7838 ldr r1, [pc, #0x15c] */
/* @0xf783c str r5, [r4, #0x18] */
/* @0xf7840 mov r5, #0 */
/* @0xf7844 str lr, [r4, #0x1c] */
/* @0xf7848 add r1, pc, r1 */
/* @0xf784c str r12, [r4, #0x48] */
/* @0xf7850 str r8, [r4, #0x8] */
/* @0xf7854 strb r9, [r4, #0xc] */
/* @0xf7858 str r3, [r4, #0x40] */
/* @0xf785c mov r3, #1 */
/* @0xf7860 str r2, [r4, #0x4c] */
/* @0xf7864 mov r2, #70 */
/* @0xf7868 str r5, [r4, #0x2c] */
/* @0xf786c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xf7870 ldr r2, [r6, #0x24] */
/* @0xf7874 cmp r2, r5 */
/* @0xf7878 str r0, [r4, #0x44] */
/* @0xf787c add r3, r0, r2, lsl #2 */
/* @0xf7880 ble 0xf7940 <_ZN7CFontGMC2EP14YYEmbeddedFont+0x2b4> */
/* @0xf7884 sub r1, r0, #4 */
/* @0xf7888 mov r12, r5 */
/* @0xf788c mov r0, r5 */
/* @0xf7890 mov r11, r2 */
/* @0xf7894 str r4, [sp, #0x4] */
/* @0xf7898 str r3, [r1, #0x4]! */
/* @0xf789c add r10, r3, #16 */
/* @0xf78a0 ldr lr, [r6, #0x28] */
/* @0xf78a4 add r2, lr, r12 */
/* @0xf78a8 ldrh r8, [lr, r12] */
/* @0xf78ac ldrh r7, [r2, #2] */
/* @0xf78b0 ldrh lr, [r2, #14] */
/* @0xf78b4 ldrh r5, [r2, #4] */
/* @0xf78b8 ldrh r9, [r2, #6] */
/* @0xf78bc sxth r4, lr */
/* @0xf78c0 strh r8, [r3] */
/* @0xf78c4 ldrh r8, [r2, #8] */
/* @0xf78c8 cmp r4, #0 */
/* @0xf78cc strh r7, [r3, #2] */
/* @0xf78d0 ldrh r7, [r2, #10] */
/* @0xf78d4 strh r5, [r3, #4] */
/* @0xf78d8 ldrh r5, [r2, #12] */
/* @0xf78dc strh r9, [r3, #6] */
/* @0xf78e0 strh r8, [r3, #8] */
/* @0xf78e4 strh r7, [r3, #10] */
/* @0xf78e8 strh lr, [r3, #14] */
/* @0xf78ec strh r5, [r3, #12] */
/* @0xf78f0 ble 0xf7988 <_ZN7CFontGMC2EP14YYEmbeddedFont+0x2fc> */
/* @0xf78f4 ldr r5, [r2, #0x10] */
/* @0xf78f8 add r3, r3, #20 */
/* @0xf78fc lsl r4, r4, #2 */
/* @0xf7900 mov lr, #0 */
/* @0xf7904 mov r2, r5 */
/* @0xf7908 add r3, r3, #4 */
/* @0xf790c ldrh r7, [r2, lr]! */
/* @0xf7910 add lr, lr, #4 */
/* @0xf7914 cmp lr, r4 */
/* @0xf7918 strh r7, [r3, #-8] */
/* @0xf791c ldrh r2, [r2, #2] */
/* @0xf7920 strh r2, [r3, #-6] */
/* @0xf7924 bne 0xf7904 <_ZN7CFontGMC2EP14YYEmbeddedFont+0x278> */
/* @0xf7928 add r3, r10, lr */
/* @0xf792c add r0, r0, #1 */
/* @0xf7930 add r12, r12, #20 */
/* @0xf7934 cmp r0, r11 */
/* @0xf7938 bne 0xf7898 <_ZN7CFontGMC2EP14YYEmbeddedFont+0x20c> */
/* @0xf793c ldr r4, [sp, #0x4] */
/* @0xf7940 ldr r0, [r6, #0x4] */
/* @0xf7944 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xf7948 ldr r2, [r6, #0x24] */
/* @0xf794c cmp r2, #0 */
/* @0xf7950 ldrgt r3, [r4, #0x44] */
/* @0xf7954 str r0, [r4, #0x4] */
/* @0xf7958 addgt r0, r3, r2, lsl #2 */
/* @0xf795c ble 0xf797c <_ZN7CFontGMC2EP14YYEmbeddedFont+0x2f0> */
/* @0xf7960 ldr r2, [r3], #4 */
/* @0xf7964 ldr r1, [r4, #0x2c] */
/* @0xf7968 ldrsh r2, [r2, #8] */
/* @0xf796c cmp r1, r2 */
/* @0xf7970 strlt r2, [r4, #0x2c] */
/* @0xf7974 cmp r3, r0 */
/* @0xf7978 bne 0xf7960 <_ZN7CFontGMC2EP14YYEmbeddedFont+0x2d4> */
/* @0xf797c mov r0, r4 */
/* @0xf7980 add sp, sp, #12 */
/* @0xf7984 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xf7988 mov r3, r10 */
/* @0xf798c b 0xf792c <_ZN7CFontGMC2EP14YYEmbeddedFont+0x2a0> */
/* @0xf7990 .word 0x002f67b0 */
/* @0xf7994 eoreq r9, r3, r4, ror #17 */
/* @0xf7998 eoreq r6, pc, r12, lsr #3 */
/* @0xf799c eoreq r9, r3, r8, ror #15 */

/* ── FUNC 0xf768c · CFontGM::CFontGM(YYEmbeddedFont*) · alias of the symbol above · insn=0 */

/* ── FUNC 0xf79a0 · CFontGM::LoadFromStream(CStream*) · size=548 · insn=137 */
/* @0xf79a0 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0xf79a4 mov r5, r1 */
/* @0xf79a8 mov r9, r0 */
/* @0xf79ac bl 0xf70a0 <_ZN7CFontGM5ClearEv> */
/* @0xf79b0 mov r0, r5 */
/* @0xf79b4 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0xf79b8 cmp r0, #800 */
/* @0xf79bc cmpne r0, #540 */
/* @0xf79c0 mov r8, r0 */
/* @0xf79c4 moveq r4, #0 */
/* @0xf79c8 movne r4, #1 */
/* @0xf79cc bne 0xf7b70 <_ZN7CFontGM14LoadFromStreamEP7CStream+0x1d0> */
/* @0xf79d0 ldr r0, [r9, #0x4] */
/* @0xf79d4 cmp r0, #0 */
/* @0xf79d8 beq 0xf79e4 <_ZN7CFontGM14LoadFromStreamEP7CStream+0x44> */
/* @0xf79dc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xf79e0 str r4, [r9, #0x4] */
/* @0xf79e4 add r1, r9, #4 */
/* @0xf79e8 mov r0, r5 */
/* @0xf79ec bl 0x2018e8 <_ZN7CStream10ReadStringERPKc> */
/* @0xf79f0 mov r0, r5 */
/* @0xf79f4 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0xf79f8 mov r6, #0 */
/* @0xf79fc str r0, [r9, #0x8] */
/* @0xf7a00 mov r0, r5 */
/* @0xf7a04 bl 0x2019b0 <_ZN7CStream11ReadBooleanEv> */
/* @0xf7a08 strb r0, [r9, #0xc] */
/* @0xf7a0c mov r0, r5 */
/* @0xf7a10 bl 0x2019b0 <_ZN7CStream11ReadBooleanEv> */
/* @0xf7a14 strb r0, [r9, #0xd] */
/* @0xf7a18 mov r0, r5 */
/* @0xf7a1c bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0xf7a20 str r6, [r9, #0x2c] */
/* @0xf7a24 ubfx r3, r0, #0x10, #0x8 */
/* @0xf7a28 str r0, [r9, #0x18] */
/* @0xf7a2c cmp r3, #0 */
/* @0xf7a30 strne r3, [r9, #0x10] */
/* @0xf7a34 lsrs r3, r0, #24 */
/* @0xf7a38 uxth r0, r0 */
/* @0xf7a3c subne r3, r3, #1 */
/* @0xf7a40 str r0, [r9, #0x18] */
/* @0xf7a44 strne r3, [r9, #0x14] */
/* @0xf7a48 mov r0, r5 */
/* @0xf7a4c bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0xf7a50 ldr r1, [pc, #0x164] */
/* @0xf7a54 mov r3, #256 */
/* @0xf7a58 movw r2, #0x29d */
/* @0xf7a5c str r3, [r9, #0x40] */
/* @0xf7a60 add r1, pc, r1 */
/* @0xf7a64 mov r3, #1 */
/* @0xf7a68 str r0, [r9, #0x1c] */
/* @0xf7a6c mov r0, #5120 */
/* @0xf7a70 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xf7a74 ldr r3, [r9, #0x40] */
/* @0xf7a78 sub r7, r0, #4 */
/* @0xf7a7c str r0, [r9, #0x44] */
/* @0xf7a80 add r0, r0, r3, lsl #2 */
/* @0xf7a84 add r4, r0, #16 */
/* @0xf7a88 sub r3, r4, #16 */
/* @0xf7a8c mov r0, r5 */
/* @0xf7a90 str r3, [r7, #0x4]! */
/* @0xf7a94 add r4, r4, #16 */
/* @0xf7a98 strh r6, [r4, #-32] */
/* @0xf7a9c add r6, r6, #1 */
/* @0xf7aa0 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0xf7aa4 strh r0, [r4, #-30] */
/* @0xf7aa8 mov r0, r5 */
/* @0xf7aac bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0xf7ab0 strh r0, [r4, #-28] */
/* @0xf7ab4 mov r0, r5 */
/* @0xf7ab8 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0xf7abc strh r0, [r4, #-26] */
/* @0xf7ac0 mov r0, r5 */
/* @0xf7ac4 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0xf7ac8 strh r0, [r4, #-24] */
/* @0xf7acc mov r0, r5 */
/* @0xf7ad0 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0xf7ad4 strh r0, [r4, #-22] */
/* @0xf7ad8 mov r0, r5 */
/* @0xf7adc bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0xf7ae0 ldrsh r3, [r4, #-24] */
/* @0xf7ae4 ldr r2, [r9, #0x2c] */
/* @0xf7ae8 cmp r2, r3 */
/* @0xf7aec strh r0, [r4, #-20] */
/* @0xf7af0 strlt r3, [r9, #0x2c] */
/* @0xf7af4 cmp r6, #256 */
/* @0xf7af8 bne 0xf7a88 <_ZN7CFontGM14LoadFromStreamEP7CStream+0xe8> */
/* @0xf7afc mov r0, r5 */
/* @0xf7b00 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0xf7b04 str r0, [r9, #0x24] */
/* @0xf7b08 mov r0, r5 */
/* @0xf7b0c bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0xf7b10 ldr r12, [r9, #0x24] */
/* @0xf7b14 ldr r2, [pc, #0xa4] */
/* @0xf7b18 mov r3, #688 */
/* @0xf7b1c add r2, pc, r2 */
/* @0xf7b20 mov r1, r0 */
/* @0xf7b24 add r0, r9, #52 */
/* @0xf7b28 str r1, [r9, #0x28] */
/* @0xf7b2c mul r1, r12, r1 */
/* @0xf7b30 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0xf7b34 ldr r3, [r9, #0x24] */
/* @0xf7b38 ldr r2, [r9, #0x28] */
/* @0xf7b3c cmp r8, #540 */
/* @0xf7b40 mov r0, r5 */
/* @0xf7b44 mul r3, r2, r3 */
/* @0xf7b48 str r3, [r9, #0x30] */
/* @0xf7b4c beq 0xf7b78 <_ZN7CFontGM14LoadFromStreamEP7CStream+0x1d8> */
/* @0xf7b50 bl 0x2019c4 <_ZN7CStream10ReadStreamEv> */
/* @0xf7b54 ldr r3, [r9, #0x24] */
/* @0xf7b58 ldr r2, [r9, #0x28] */
/* @0xf7b5c ldr r1, [r9, #0x34] */
/* @0xf7b60 mul r2, r2, r3 */
/* @0xf7b64 bl 0x2011e4 <_ZN7CStream10ReadBufferEPvi> */
/* @0xf7b68 mov r0, #1 */
/* @0xf7b6c pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0xf7b70 mov r0, #0 */
/* @0xf7b74 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0xf7b78 bl 0x201db0 <_ZN7CStream20ReadCompressedStreamEv> */
/* @0xf7b7c ldr r3, [r9, #0x24] */
/* @0xf7b80 ldr r2, [r9, #0x28] */
/* @0xf7b84 ldr r1, [r9, #0x34] */
/* @0xf7b88 mul r2, r2, r3 */
/* @0xf7b8c mov r4, r0 */
/* @0xf7b90 bl 0x2011e4 <_ZN7CStream10ReadBufferEPvi> */
/* @0xf7b94 cmp r4, #0 */
/* @0xf7b98 beq 0xf7bb4 <_ZN7CFontGM14LoadFromStreamEP7CStream+0x214> */
/* @0xf7b9c mov r0, r4 */
/* @0xf7ba0 bl 0x201328 <_ZN7CStreamD2Ev> */
/* @0xf7ba4 mov r0, r4 */
/* @0xf7ba8 bl 0x27d1d0 <_ZdlPv> */
/* @0xf7bac mov r0, #1 */
/* @0xf7bb0 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0xf7bb4 mov r0, #1 */
/* @0xf7bb8 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0xf7bbc eoreq pc, r3, r4, lsr #31 */
/* @0xf7bc0 eoreq pc, r3, r8, ror #29 */

/* ── FUNC 0xf7bc4 · CFontGM::LoadFromChunk(YYFont*, unsigned char*) · size=368 · insn=92 */
/* @0xf7bc4 push {r4, r5, r6, r7, r8, lr} */
/* @0xf7bc8 mov r6, r1 */
/* @0xf7bcc mov r4, r0 */
/* @0xf7bd0 bl 0xf70a0 <_ZN7CFontGM5ClearEv> */
/* @0xf7bd4 ldr r2, [r6, #0x1c] */
/* @0xf7bd8 ldr r7, [pc, #0x14c] */
/* @0xf7bdc cmp r2, #0 */
/* @0xf7be0 add r7, pc, r7 */
/* @0xf7be4 ldrne r3, [pc, #0x144] */
/* @0xf7be8 ldrne r3, [r7, r3] */
/* @0xf7bec ldrne r3, [r3] */
/* @0xf7bf0 addne r2, r3, r2 */
/* @0xf7bf4 ldr lr, [r6, #0xc] */
/* @0xf7bf8 ldr r12, [r6, #0x10] */
/* @0xf7bfc adds lr, lr, #0 */
/* @0xf7c00 ldr r3, [r6, #0x14] */
/* @0xf7c04 ldr r0, [r6, #0x8] */
/* @0xf7c08 movne lr, #1 */
/* @0xf7c0c adds r12, r12, #0 */
/* @0xf7c10 ubfx r1, r3, #0x10, #0x8 */
/* @0xf7c14 str r2, [r4, #0x3c] */
/* @0xf7c18 movne r12, #1 */
/* @0xf7c1c cmp r1, #0 */
/* @0xf7c20 strne r1, [r4, #0x10] */
/* @0xf7c24 lsrs r1, r3, #24 */
/* @0xf7c28 subne r1, r1, #1 */
/* @0xf7c2c strne r1, [r4, #0x14] */
/* @0xf7c30 cmp r2, #0 */
/* @0xf7c34 ldr r1, [r6, #0x18] */
/* @0xf7c38 str r3, [r4, #0x18] */
/* @0xf7c3c uxth r3, r3 */
/* @0xf7c40 str r3, [r4, #0x18] */
/* @0xf7c44 ldrshne r3, [r2, #4] */
/* @0xf7c48 ldrshne r2, [r2, #6] */
/* @0xf7c4c str r0, [r4, #0x8] */
/* @0xf7c50 ldr r0, [r6, #0x28] */
/* @0xf7c54 streq r2, [r4, #0x24] */
/* @0xf7c58 strne r3, [r4, #0x24] */
/* @0xf7c5c cmp r0, #532676608 */
/* @0xf7c60 ldr r3, [r6, #0x20] */
/* @0xf7c64 str r2, [r4, #0x28] */
/* @0xf7c68 ldr r2, [r6, #0x24] */
/* @0xf7c6c str r3, [r4, #0x48] */
/* @0xf7c70 mov r3, #0 */
/* @0xf7c74 str r0, [r4, #0x40] */
/* @0xf7c78 lslls r0, r0, #2 */
/* @0xf7c7c str r3, [r4, #0x2c] */
/* @0xf7c80 mvnhi r0, #0 */
/* @0xf7c84 strb lr, [r4, #0xc] */
/* @0xf7c88 strb r12, [r4, #0xd] */
/* @0xf7c8c str r1, [r4, #0x1c] */
/* @0xf7c90 str r2, [r4, #0x4c] */
/* @0xf7c94 bl 0x27d14c <_Znaj> */
/* @0xf7c98 ldr r3, [r6, #0x4] */
/* @0xf7c9c cmp r3, #0 */
/* @0xf7ca0 str r0, [r4, #0x44] */
/* @0xf7ca4 moveq r0, r3 */
/* @0xf7ca8 ldrne r2, [pc, #0x80] */
/* @0xf7cac ldrne r2, [r7, r2] */
/* @0xf7cb0 ldrne r0, [r2] */
/* @0xf7cb4 addne r0, r0, r3 */
/* @0xf7cb8 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xf7cbc ldr r8, [r6, #0x28] */
/* @0xf7cc0 cmp r8, #0 */
/* @0xf7cc4 str r0, [r4, #0x4] */
/* @0xf7cc8 ble 0xf7d24 <_ZN7CFontGM13LoadFromChunkEP6YYFontPh+0x160> */
/* @0xf7ccc ldr r0, [r4, #0x44] */
/* @0xf7cd0 add r8, r6, r8, lsl #2 */
/* @0xf7cd4 mov r3, r6 */
/* @0xf7cd8 ldr r2, [r3, #0x2c] */
/* @0xf7cdc rsb r12, r6, r3 */
/* @0xf7ce0 ldr r1, [pc, #0x48] */
/* @0xf7ce4 add r0, r0, r12 */
/* @0xf7ce8 cmp r2, #0 */
/* @0xf7cec add r3, r3, #4 */
/* @0xf7cf0 mov r5, r2 */
/* @0xf7cf4 ldrne r1, [r7, r1] */
/* @0xf7cf8 ldrne r5, [r1] */
/* @0xf7cfc ldr r1, [r4, #0x2c] */
/* @0xf7d00 addne r5, r5, r2 */
/* @0xf7d04 str r5, [r0] */
/* @0xf7d08 ldr r0, [r4, #0x44] */
/* @0xf7d0c ldr r2, [r0, r12] */
/* @0xf7d10 ldrsh r2, [r2, #8] */
/* @0xf7d14 cmp r1, r2 */
/* @0xf7d18 strlt r2, [r4, #0x2c] */
/* @0xf7d1c cmp r3, r8 */
/* @0xf7d20 bne 0xf7cd8 <_ZN7CFontGM13LoadFromChunkEP6YYFontPh+0x114> */
/* @0xf7d24 mov r0, #1 */
/* @0xf7d28 pop {r4, r5, r6, r7, r8, pc} */
/* @0xf7d2c eoreq r10, pc, r0, ror r0 */
/* @0xf7d30 .word 0xffffbcf4 */

/* ── FUNC 0xf7d34 · CFontGM::~CFontGM() · size=100 · insn=25 */
/* @0xf7d34 push {r3, r4, r5, lr} */
/* @0xf7d38 mov r5, r0 */
/* @0xf7d3c ldr r3, [pc, #0x50] */
/* @0xf7d40 ldr r3, [pc, r3] */
/* @0xf7d44 add r3, r3, #8 */
/* @0xf7d48 str r3, [r0] */
/* @0xf7d4c bl 0xf70a0 <_ZN7CFontGM5ClearEv> */
/* @0xf7d50 ldr r0, [r5, #0x5c] */
/* @0xf7d54 mov r2, #0 */
/* @0xf7d58 mvn r3, #0 */
/* @0xf7d5c cmp r0, r2 */
/* @0xf7d60 str r2, [r5, #0x64] */
/* @0xf7d64 str r3, [r5, #0x68] */
/* @0xf7d68 beq 0xf7d80 <_ZN7CFontGMD2Ev+0x4c> */
/* @0xf7d6c ldr r4, [r0] */
/* @0xf7d70 bl 0x27d1d0 <_ZdlPv> */
/* @0xf7d74 cmp r4, #0 */
/* @0xf7d78 mov r0, r4 */
/* @0xf7d7c bne 0xf7d6c <_ZN7CFontGMD2Ev+0x38> */
/* @0xf7d80 mov r3, #0 */
/* @0xf7d84 mov r0, r5 */
/* @0xf7d88 str r3, [r5, #0x5c] */
/* @0xf7d8c str r3, [r5, #0x60] */
/* @0xf7d90 pop {r3, r4, r5, pc} */
/* @0xf7d94 eoreq r6, pc, r8, lsl #2 */

/* ── FUNC 0xf7d34 · CFontGM::~CFontGM() · alias of the symbol above · insn=0 */

/* ── FUNC 0xf7d98 · CFontGM::~CFontGM() · size=28 · insn=7 */
/* @0xf7d98 push {r4, lr} */
/* @0xf7d9c mov r4, r0 */
/* @0xf7da0 bl 0xf7d34 <_ZN7CFontGMD2Ev> */
/* @0xf7da4 mov r0, r4 */
/* @0xf7da8 bl 0x27d1d0 <_ZdlPv> */
/* @0xf7dac mov r0, r4 */
/* @0xf7db0 pop {r4, pc} */
