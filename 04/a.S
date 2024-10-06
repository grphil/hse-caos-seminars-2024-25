	.intel_syntax noprefix
	.global main
main:
	lea rax, [rip + fun0] // rax = absolute address of fun0
	mov [rip + func_arr], rax // func_arr[0] = rax
	
	lea rax, [rip + fun1] // rax = absolute address of fun1
	mov [rip + func_arr + 8], rax // func_arr[1] = rax

	lea rax, [rip + fun2]
	mov [rip + func_arr + 16], rax

	call readi64 // cin >> rax
	lea rdx, [rip + func_arr] // rdx = absolute address of func_arr
	mov rbx, [rdx + rax * 8] // rbx = func_arr[rax]

	jmp rbx

fun0:
	mov rdi, 0
	call writei64
	call finish

fun1:
	mov rdi, 1
	call writei64
	call finish

fun2:
	mov rdi, 3
	call writei64
	call finish

	.bss
func_arr: .space 3 * 8




