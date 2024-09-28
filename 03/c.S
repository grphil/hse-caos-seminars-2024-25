	.intel_syntax noprefix
	.global A
	.global inc_a
inc_a:
// регистры rbx, rsp, rbp, r12, r13 .. r15 не должны меняться
	push rbx

	// теперь rbx можно менять, в конце достанем его со стека

	mov ebx, [rip + A]
	inc ebx
	mov [rip + A], ebx

	pop rbx 
	ret