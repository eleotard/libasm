		global ft_strlen
		section .text
ft_strlen:
	xor		rax, rax
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


;la section .text d'un programme se situe dans le fichier executable
;elle est chargee en memoire avec seulement les droits d'ex et de lecture

;global : sert a declarer une etiquette/symbole (comme une ft ou une variable)
	;comme etant accessible en dehors du fichier

;labels | instructions | operands
