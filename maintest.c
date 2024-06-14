#include "libasm.h"

# define CCOLOR   "\033[0m"
# define CRED     "\033[1;31m"
# define CGREEN   "\033[1;32m"
# define CTRUC   "\033[1;33m"

void	ft_strlen_tests(const char *s)
{
	size_t res_1;
	size_t res_2;

	res_1 = strlen(s);
	printf("strlen(\"%s\"): %s%ld%s\n", s, CGREEN, res_1, CCOLOR);
	res_2 = ft_strlen(s);
	if (res_1 == res_2)
		printf("ft_strlen(\"%s\"): %s%ld%s\n", s, CGREEN, res_2, CCOLOR);
	else
		printf("ft_strlen(\"%s\"): %s%ld%s\n", s, CRED, res_2, CCOLOR);
	printf("\n");
}

void	ft_strcpy_tests(char *dest, const char *src)
{
	char	*res_1;
	char	*res_2;
	char	inital_dest_str[100000];

	strcpy(inital_dest_str, dest);
	res_1 = strcpy(dest, src);
	printf("strcpy(\"%s\", \"%s\"): %s%s%s\n", inital_dest_str, src, CGREEN, res_1, CCOLOR);
	res_2 = ft_strcpy(dest, src);
	if (!strcmp(res_1, res_2))
		printf("ft_strcpy(\"%s\", \"%s\"): %s%s%s\n", inital_dest_str, src, CGREEN, res_2, CCOLOR);
	else
		printf("ft_strcpy(\"%s\", \"%s\"): %s%s%s\n", inital_dest_str, src, CRED, res_2, CCOLOR);
	printf("\n");
}

void	ft_strcmp_tests(const char *s1, const char *s2)
{
	size_t res_1;
	size_t res_2;

	res_1 = strcmp(s1, s2);
	printf("strcmp(\"%s\", \"%s\"): %s%ld%s\n", s1, s2, CGREEN, res_1, CCOLOR);
	res_2 = ft_strcmp(s1, s2);
	if (res_1 == res_2)
		printf("ft_strcmp(\"%s\", \"%s\"): %s%ld%s\n", s1, s2, CGREEN, res_2, CCOLOR);
	else
		printf("ft_strcmp(\"%s\", \"%s\"): %s%ld%s\n", s1, s2, CRED, res_2, CCOLOR);
	printf("\n");
}

// void	ft_write_tests()
// {
// 	printf("write: %ld\n", write(5, "bonjour", 7));
// 	printf("errno: %d\n", errno);
// 	printf("ft_write: %ld\n", ft_write(5, "bonjour", 7));
// 	printf("errno: %d\n", errno);
// 	printf("\n");
// }

// void	ft_read_tests()
// {
// 	char buff[1024];
// 	char *test = NULL;
// 	bzero(buff, sizeof(buff));
// 	printf("read: %ld\n", read(0, test, 20));
// 	printf("buff: %s\n", buff);
// 	printf("errno: %d\n", errno);
// 	bzero(buff, sizeof(buff));
// 	printf("ft_read: %ld\n", ft_read(0, test, 20));
// 	printf("buff: %s\n", buff);
// 	printf("errno: %d\n", errno);
// }

// void	ft_strdup_tests()
// {
// 	char *lol = ft_strdup("cou");
// 	printf("errno: %d\n", errno);
// 	__builtin_printf("%s\n", lol);
// }

int main(void) 
{
	printf(CTRUC "------------------------STRLEN TESTS------------------------\n" CCOLOR);
	ft_strlen_tests("test");
	ft_strlen_tests("");
	ft_strlen_tests("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");

	printf(CTRUC "------------------------STRCPY TESTS------------------------\n" CCOLOR);
	char dest[100];
	ft_strcpy_tests(dest, "gougou");
	ft_strcpy_tests(dest, "gagag");

	printf(CTRUC "------------------------STRCMP TESTS------------------------\n" CCOLOR);
	ft_strcmp_tests("bonjour", "bonjour");
	ft_strcmp_tests("", "oui");
	ft_strcmp_tests("oui", "");
	ft_strcmp_tests("", "");

	printf(CTRUC "-------------------------WRITE TESTS------------------------\n" CCOLOR);
	

	


	// ft_read_tests();
	// ft_strdup_tests();

}
