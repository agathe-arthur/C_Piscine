NAME	= do-op
SRCS	= do-op.c ft_fct.c ft_operation.c
OBJS	= ${SRCS:.c=.o}
CC		= gcc
FLAG	= -Wall -Wextra -Werror -c -I.

.c.o:
	${CC} ${FLAG} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	${CC} -o ${NAME} ${OBJS}

all:	${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}
