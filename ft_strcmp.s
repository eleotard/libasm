		global	ft_strcmp
		section .text
ft_strcmp:
	xor 	rax, rax

while_loop:
	mov		al, byte [rdi]
	cmp		al, byte [rsi]
	jne		end_loop
	cmp		al, 0
	je		end_loop
	inc		rdi
	inc		rsi 
	jmp		while_loop

end_loop:
	sub		al, byte [rsi]
	movsx	rax, al				; move with sign-extension
	ret