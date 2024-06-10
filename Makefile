NAME = libasm.a

SRCS =	ft_strlen.s \
		ft_strcpy.s \

FLAGS = -Wall -Werror

OBJS = ${SRCS:%.s=%.o}

all: ${NAME}

%.o: %.s
	nasm -f elf64 $(FLAGS) -o $@ $<

${NAME} : ${OBJS}
	ar rcs ${NAME} ${OBJS} 

clean:
	rm ${OBJS}
	rm a.out

fclean: clean
	rm ${NAME}

re: fclean all

.PHONY: all clean fclean re