; reside dans la bibliotheque C standard (glibc)
; la variable errno est aussi dans la bibliotheque standard C (<errno.h>)
extern __errno_location		
global ft_write


;PIE (Position Independent Executable)
;Les exécutables PIE peuvent être chargés à n'importe quelle adresse en 
;	mémoire pour des raisons de sécurité (par exemple, l'ASLR). 
;Si le code utilise directement des adresses absolues pour des symboles
;	comme __errno_location, cela pose problème car ces adresses doivent
;	être résolues dynamiquement dans un PIE
;Référencer directement __errno_location entraîne une relocation dans une
;	section en lecture seule(.text), ce qui n'est pas permis pour les PIE.
;call	__errno_location
;Cela indique au linker de résoudre l'adresse de __errno_location lors de
;	l'édition des liens/linkage. Cependant, dans le cas d'un PIE, l'adresse finale
;	de __errno_location ne peut pas être déterminée statiquement lors de 
;	l'édition des liens. Elle doit être résolue dynamiquement lors de
;	l'exécution
;Le linkage se fait a la compilation (on lie les .o, les references)

;PLT (Procedure Linkage Table) 
;Structure utilisée par le système d'exploitation et le linker pour gérer les
;	appels de fonctions dynamiques dans les programmes exécutables
; wrt ..plt: l'appel est redirigé via la PLT pour permettre une résolution
;	dynamique des adresses de fonction au moment de l'exécution
; avec plt, un stub(petit morceau de code) est associe a la ft externe
; qd la ft est appelee, le stub est execute
; le stub ne contient pas l'adresse de la ft mais une routine de
;	resolution qui va trouver l'adresse.
; l'adresse est maj dans la Global Offset Table(GOT)
; l'entrée correspondante dans la GOT contient désormais l'adresse 
;	correcte de la fonction et pr les prochains appels ca sera direct pris ici


;SYSCALL
;Si l'appel à write échoue, le registre RAX contiendra une valeur négative.
;La valeur négative correspond à l'opposé de l'erreur qui a été rencontrée
;(un code d'erreur négatif).

section .text
ft_write:
	mov		rax, 1			; appel systeme pour write
	syscall					; invoke operating system to do the write
	cmp		rax, 0
	jl		error
	ret

error:
	neg		rax
	mov		rcx, rax
	call	__errno_location wrt ..plt 	; renvoie un pt sur la variable errno
	mov		[rax], rcx					; met le code d'erreur dans errno
	mov		rax, -1						; return -1
	ret
