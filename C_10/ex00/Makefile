NAME	= ft_display_file
SRCS	= ft_display_file.c
OBJS	= ${SRCS:.c=.o}
CC		= gcc
FLAG	= -Wall -Wextra -Werror -c

.c.o:
	${CC} ${FLAG} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	${CC} -o ${NAME} ${OBJS}

all:	${NAME}

clean:
	rm  ${OBJS}

fclean: clean
	rm ${NAME}
