#include "libasm.h"

# define CCOLOR   "\033[0m"
# define CRED     "\033[1;31m"
# define CGREEN   "\033[1;32m"

// size_t ft_strlen(char *s);

// static void write_test(int fd, char *buf, size_t count, const char *test)
// {
//     int     or;
//     int     ft;
//     int		ft_err;
//     int		or_err;

//     or = write(fd, buf, count);
//     or_err = errno;
//     ft = ft_write(fd, buf, count);
//     ft_err = errno;
//     if (or == ft)
//         printf("%s :" CGREEN "[OK]\n" CCOLOR, test);
//     else
//         printf("%s :" CRED "[KO]\n" CCOLOR, test);
//     if (ft == -1 || or == -1)
//     {
//     	if (ft_err == or_err)
//     		printf("ERRNO [FT:%d]||[OR:%d] : %s" CGREEN "[OK]\n" CCOLOR, ft_err, or_err, test);
//     	else
//     		printf("ERRNO [FT:%d]||[OR:%d] : %s" CGREEN "[KO]\n" CCOLOR, ft_err, or_err, test);
//     }
// }

int main(void) 
{
	/*FT_STRLEN*/
	//CONSTANT
	char s[10] = "ab";
	const char *s1 = "soir";
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

	/*FT_WRITE*/
	printf("write: %ld\n", write(5, "bonjour", 7));
	printf("errno: %d\n", errno);
	printf("ft_write: %ld\n", ft_write(5, "bonjour", 7));
	printf("errno: %d\n", errno);
	printf("\n");
	

	/*FT_READ*/
	
	char buff[1024];
	char *test = NULL;
	bzero(buff, sizeof(buff));
	printf("read: %ld\n", read(0, test, 20));
	printf("buff: %s\n", buff);
	printf("errno: %d\n", errno);
	bzero(buff, sizeof(buff));
	printf("ft_read: %ld\n", ft_read(0, test, 20));
	printf("buff: %s\n", buff);
	printf("errno: %d\n", errno);

	/*STRDUP*/
	char *lol = ft_strdup("cou");
	printf("errno: %d\n", errno);
	__builtin_printf("%s\n", lol);







	// printf("FT_WRITE TESTS \n");
	// int		fd;

	// fd = open("write_tests", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	// if (fd == -1)
	// {
	// 	printf("open() error");
	// 	return 1;
	// }
	// write_test(fd, "Hello_world\n", 12, "basic");
	// write_test(-2, "Hello_world", 11, "bad fd");
	// write_test(fd, NULL, 11, "NULL ptr");
	// write_test(fd, "Hello_world", -2, "bad len");

}
 //errno write : 9 si bad file descriptor (EBADF)
 //EPIPE: broken pipe
 //EFAULT