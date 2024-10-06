	.intel_syntax noprefix
	.global main
main:
	push rbp
	mov rbp, rsp
	push r12

	xor r12, r12
read_all:
	call read_int
	cmp rax, 0
	je finish_read

	add r12, rax
	jmp read_all

finish_read:
	mov rdi, r12
	call writei64

	mov rax, 0 // return
	pop r12
	mov rsp, rbp
	pop rbp
	ret

read_int:
	push rbp
	mov rbp, rsp

	sub rsp, 16
	and rsp, -16

	lea rdi, [rip + scanf_str]
	lea rsi, [rip + a]
	call scanf // scanf("%lld", &a)

	mov rax, [rip + a]

	mov rsp, rbp
	pop rbp
	ret

	.data
a: .quad 0

	.text
scanf_str: .asciz "%lld"

