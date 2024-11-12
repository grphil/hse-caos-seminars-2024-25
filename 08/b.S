	.intel_syntax noprefix
	.global minsq
minsq:
	push rbp
	mov rbp, rsp

	sub rsp, 8
	movss [rsp], xmm1 // *rsp = y
	fld DWORD PTR [rsp] // stack is [y]
	movss [rsp], xmm0 // *rsp = x
	fld DWORD PTR [rsp] // stack is ->[x, y]

	fcomi st(1) // compare stack[0] and stack[1] (x and y)
	jc less // if (st(0) < st(1)) goto less

	// now x >= y
	fstp st(0) // st[0] = st[0]; stack.pop()
	// now stack is [y]

	fmul st(0) // st[0] *= st[0]
	// now stack is [y^2]

	fld DWORD PTR [rsp] // stack is [x, y^2]
	faddp // st[1] += st[0]; stack.pop()
	// now stack is [x + y^2]
	jmp end

less:
	// now stack is [x, y] and x < y
	fmul st(0) // [x^2, y]
	faddp // [x^2 + y]

end:
	fstp DWORD PTR [rsp] // *rsp = st[0]; st.pop()
	movss xmm0, [rsp] // xmm0 = [rsp]
	mov rsp, rbp
	pop rbp
	ret

