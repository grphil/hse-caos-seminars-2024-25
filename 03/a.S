	.intel_syntax noprefix
	.global main
main:
	call readi64 // cin >> rax
	mov r12, rax // r12 = rax

repeat:
	mov rdi, r12
	call writei64 // cout rdi (r12)

	cmp r12, 1
	je fin // if r12 == 1 goto fin

	test r12, 1
	jnz mul3 // if r12 & 1 != 0 goto mul3

	shr r12, 1 // r12 >>= 1
	jmp repeat

mul3:
	imul r12, 3 // r12 *= 3 (same for signed and unsigned)
	inc r12
	jmp repeat

fin:
	call finish
