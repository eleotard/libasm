	global ft_strcpy
	section .text
ft_strcpy:
	xor 	cl, cl					; rcx mais que les 8 premiers bits
	xor		rax, rax
	push	rdi

while_loop:
	cmp		byte [rsi], 0
	je		end_loop
	mov		cl, byte [rsi]
	mov		byte [rdi], cl
	xor		cl, cl
	inc		rsi
	inc		rdi
	jmp 	while_loop

end_loop:
	mov 	byte [rdi], 0
	pop		rax
	ret
	