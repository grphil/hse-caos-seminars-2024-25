	.intel_syntax noprefix
	.global ab4
ab4:
	push rbp
	mov rbp, rsp

	sal esi, 2
	mov eax, esi
	add eax, edi

	mov rsp, rbp
	pop rbp
	ret