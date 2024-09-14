	.intel_syntax noprefix
	.global main
main:
	call readi64 // cin >> rax
	// когда вызываем simpleio то не трогаются регистры rbx r12 r13 r14 r15
	mov r12, rax // r12 = rax

	call readi64 // cin >> rax
	mov r13, rax // r13 = rax

	sub r12, 2 // r12 -= 2

	inc r12 // r12++
	dec r12 // r12--

	mov rax, r12 // rax = r12
	mul r13 // (rdx, rax) = rax * r13 (rax хранит младшие 64 бита, а rdx - старшие)
	// mul r12b, r13b
	// imul r13 // знаковое умножение

	mov r14, rdx // r14 = rdx

	mov rdi, rax // rdi = rax
	call writei64 // cout << rdi

	mov rdi, r14
	call writei64

	mov rax, 0 // чуть хуже
	xor rax, rax // лучше

	call finish
	