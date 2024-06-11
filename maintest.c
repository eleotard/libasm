#include <stdio.h>
#include <string.h>
#include "libasm.h"
#include <unistd.h>

// size_t ft_strlen(char *s);

int main(void) 
{
	/*FT_STRLEN*/
	//CONSTANT
	char s[10] = "ab";
	const char *s1 = "caca";
	const char *s2 = "aba";

	printf("strlen: %ld\n", strlen("ouiouioui"));
	printf("ft_strlen: %ld\n", ft_strlen("ouiouioui"));
	printf("strlen: %ld\n", strlen(s));
	printf("ft_strlen: %ld\n", ft_strlen(s));
	printf("\n");

	/*FT_STRCPY*/
	printf("strcpy: [%s]\n", strcpy(s, s1)); //stack smash si dest trop courte
	printf("ft_strcpy: [%s]\n", ft_strcpy(s, s1));
	printf("\n");

	/*FT_STRCMP*/
	printf("strcmp: [%d]\n", strcmp(s1, s2));
	printf("ft_strcmp: [%d]\n", ft_strcmp(s1, s2));
	printf("\n");

}

//um compteur 
//une variable pour stocker le resultat
//res = byte 1ere chaine - byte 2eme chaine