NAME = libasm.a

SRCS =	ft_strlen.s \
		ft_strcpy.s \
		ft_strcmp.s \
		ft_write.s	\
		ft_read.s	\
		ft_strdup.s	\

FLAGS = -Wall -Werror

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address

OBJS = ${SRCS:%.s=%.o}

LIBASM_PATH = -L. -lasm

all: ${NAME}
	gcc ${CFLAGS} maintest.c ${LIBASM_PATH}

%.o: %.s
	nasm -f elf64 $(FLAGS) -o $@ $<

${NAME} : ${OBJS}
	ar rcs ${NAME} ${OBJS} 

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re