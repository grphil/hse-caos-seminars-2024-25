#include "context.h"

void Context::SwitchContext() {
    intptr_t* rspp = &rsp;
    intptr_t* ripp = &rip;

    asm volatile (
            ".intel_syntax noprefix\n"
            "push rbp\n"

            "mov rax, [rcx]\n"
            "mov [rcx], rsp\n"
            "mov rsp, rax\n"

            "push [rdx]\n"
            "lea rax, [rip + jump_to_finish]\n"
            "mov [rdx], rax\n"
            "ret\n"
        "jump_to_finish:\n"
            "pop rbp\n"
            ".att_syntax prefix\n"
            : "+c"(rspp), "+d"(ripp)
            :
            : "memory", "rax", "rbx", "rsi", "rdi", "r8", "r9", "r10", "r11", "r12", "r13", "r14", "r15"
    );
}