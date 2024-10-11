	.intel_syntax noprefix
	.global pipe
pipe:
	push rbp
	mov rbp, rsp

	push rbx
	mov rbx, rsi // rbx = a

	push r12
	mov r12, rdi // r12 = n

	push r13 // counter

	push r9
	push r8
	push rcx
	push rdx

	xor r13, r13 // r13 = 0 (index)
loop1:
	cmp r13, r12 // if i == n: finish
	je finish_funcs

	cmp r13, 4 // if i == 4: finish current cycle
	je finish_loop1

	mov r8, [rsp + r13 * 8] // r8 = funcs[i]
	mov rdi, rbx // first argument of call = rbx (value of a)
	call r8 // call funcs[i](a)
	mov rbx, rax // rbx = return of call

	inc r13
	jmp loop1

finish_loop1:
	sub r12, 4 // n -= 4
	xor r13, r13 // r13 = 0 (i = 0)

loop2:
	cmp r13, r12 
	je finish_funcs // if (i == n): goto finish_funcs

	mov r8, [rbp + 16 + 8 * r13] // r8 = funcs[i]
	mov rdi, rbx // first argument of call = rbx (value of a)
	call r8 // call funcs[i](a)
	mov rbx, rax // rbx = return of call

	inc r13
	jmp loop2

finish_funcs:
	mov rax, rbx
	lea rsp, [rbp - 3 * 8]

	pop r13
	pop r12
	pop rbx
	pop rbp
	ret