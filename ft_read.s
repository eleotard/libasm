	extern __errno_location
	global ft_read
	section .text
ft_read:
	mov		rax, 0
	syscall
	cmp		rax, 0
	jl		error
	jmp		end

error:
	neg		rax
	push 	rax
	call 	__errno_location wrt ..plt
	pop		rcx
	mov		[rax], rcx
	mov		rax, -1
	ret 

end:
	ret