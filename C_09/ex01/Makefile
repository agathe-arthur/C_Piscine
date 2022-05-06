NAME	= libft.a
OBJS	= srcs/ft_putchar.o srcs/ft_putstr.o srcs/ft_strcmp.o srcs/ft_strlen.o srcs/ft_swap.o
CC		= gcc
FLAG	= -Wall -Wextra -Werror
INC		= ./includes/

all: ${NAME}

${NAME}: ${OBJS}
	ar -crs ${NAME} $^

${OBJS}: %.o: %.c
	${CC} -I${INC} ${FLAG} -c $< -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all
