	.intel_syntax noprefix
	.global mulab
mulab:
	// args are passed xmm0 xmm1 xmm2 xmm3 ...
	// float return in xmm0
	// xmm 128
	// ymm 256
	// zmm 512
	// operand+s+(d/s) (d - double, s - float)
	push rbp
	mov rbp, rsp

	mulsd xmm0, xmm1 // a *= b
	movsd [rdi], xmm0 // *c = a

	mov rsp, rbp
	pop rbp
	ret
