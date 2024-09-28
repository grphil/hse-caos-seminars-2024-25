	.intel_syntax noprefix
	.global main
main:
	call readi64 // cin >> rax
	mov r12, rax // r12 - это размер массива

	call readi64
	mov r13, rax // r13 - циклический сдвиг

	mov rbx, r12 // rbx - сколько осталось считать чисел

read_all:
	call readi64 // cin >> rax
	push rax // добавим число на стек
	// push умеет только в 64 бита
	// push eax - CE

	dec rbx
	jnz read_all // if --rbx > 0 goto read_all

	mov rbx, r13 // rbx - сколько чисел на суффиксе надо вывести

write_suffix:
	dec rbx
	// стек растет влево!
	// rsp указывает на последний элемент в стеке
	mov rdi, [rsp + rbx * 8]
	// адрессация BEGIN + INDEX * STEP + OFFSET
	// BEGIN - регистр
	// INDEX - регистр
	// STEP 2, 4, 8
	// OFFSET - константа
	// можно скипать часть формулы

	// rdi равен элементу на расстоянии rbx от конца массива
	call writei64

	cmp rbx, 0
	jne write_suffix

	// rsp += r13 * 8
	lea rsp, [rsp + r13 * 8] // rsp = rsp + r13 * 8
	// lea вычисляет адрес в памяти и записывает в другой регистр этот адрес

	sub r12, r13 // r12 -= r13  - сколько элементов осталось сдать
write_prefix:
	dec r12
	mov rdi, [rsp + r12 * 8]
	call writei64

	cmp r12, 0
	jne write_prefix

	call finish

