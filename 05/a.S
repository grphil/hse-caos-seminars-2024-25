	.intel_syntax noprefix
	.global calculate_rec_depth
calculate_rec_depth:
	push rbp
	mov rbp, rsp
	push rbx

	xor rax, rax // rax stores recursion depth
	mov rbx, rbp // rbx points to rbp position in stack of last processed function

repeat:
	mov r8, [rbx + 8] // r8 store addres of call
	mov r9, r8

	lea rsi, [rip + main] // rsi = absolute addres of main
	sub r8, rsi // r8 = addres of call - addres of main

	lea rsi, [rip + rec] // rsi = absolute addres of rec
	sub r9, rsi // r9 = addres of call - addres of rec

	cmp r8, r9 
	jb rec_end 

	inc rax
	mov rbx, [rbx] // rbx not points to rbp in previous call
	jmp repeat

rec_end:
	pop rbx
	pop rbp
	ret
