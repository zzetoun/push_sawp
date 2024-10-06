SRCS	=	push_swap.c 	\
			ft_parsing.c	\
			utilites.c		\
			list_utilites.c

OBJS	= ${SRCS:.c=.o}

NAME	= push_swap
CC		= cc
RM		= rm -f
CFLAGS	= #-Wall -Werror -Wextra

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	${RM} ${OBJS} ${OBJS_BO}

fclean: clean
	${RM} ${NAME}

re: fclean all
