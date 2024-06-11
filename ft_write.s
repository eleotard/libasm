extern __errno_location
global ft_write

section .text
ft_write:
	mov		rax, 1			; sys_write
	syscall
	cmp		rax, 0
	jl		error

		
error:
	neg		rax
	mov		rdi, rax
	call	__errno_location
	mov		[rax], rdi			;set the avalue
	mov		rax, -1
	ret