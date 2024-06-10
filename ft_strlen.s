		global ft_strlen
		section .text
ft_strlen:
	mov		rcx, 0

while_loop:
	cmp		byte [rdi], 0
	je 		end_loop			; si c'est egal, end_loop
	add		rdi, 1
	inc		rcx
	jmp		while_loop

end_loop:
	mov rax, rcx
	ret
