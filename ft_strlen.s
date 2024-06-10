		global ft_strlen
		section .text
ft_strlen:
	mov		ecx, 0

while_loop:
	cmp		[rdi], 0
	je 		end_loop
	add		rdi, 1

end