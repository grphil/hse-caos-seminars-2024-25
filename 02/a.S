	.intel_syntax noprefix
	.global main
main:
	call readi64 // cin >> rax
	// когда вызываем simpleio то не трогаются регистры rbx rsp rbp r12 r13 r14 r15
	mov r12, rax // r12 = rax

	call readi64 // cin >> rax
	add r12, rax // r12 += rax

	mov rdi, r12 // rdi = r12
	call writei64 // cout << rdi
	call finish // return 0