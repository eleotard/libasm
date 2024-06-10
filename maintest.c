#include <stdio.h>
#include <string.h>
#include "libasm.h"

// size_t ft_strlen(char *s);

int main(void) 
{
	/*FT_STRLEN*/
	//CONSTANT
	char s[50] = "";
	const char *s1 = "bjr";

	printf("strlen: %ld\n", strlen("ouiouioui"));
	printf("ft_strlen: %ld\n", ft_strlen("ouiouioui"));
	printf("strlen: %ld\n", strlen(s));
	printf("ft_strlen: %ld\n", ft_strlen(s));
	printf("\n");

	/*FT_STRCPY*/
	printf("strcpy: [%s]\n", strcpy(s, s1));
	printf("ft_strcpy: [%s]\n", ft_strcpy(s, s1));

}