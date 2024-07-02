		extern ft_strlen
		extern ft_strcpy
		extern malloc
		global ft_strdup
		section .text
; params: const char str (rdi)

ft_strdup:
	xor 	rax, rax				
	push	rdi						; on save le pt sur la string
	call	ft_strlen		
	mov		rdi, rax
	inc		rdi						; ajoute 1 pour le \0
	call	malloc wrt ..plt		; call malloc avec len str + 1
	or 		rax, rax				; check erreur malloc
	je 		malloc_error
	mov		rdi, rax				; arg1 ft_strcpy(dest)
	pop		rsi						; arg2 ft_strcpy(src)
	call	ft_strcpy
	ret

malloc_error:
	pop rdi
	xor rax, rax
	ret
