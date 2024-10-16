SRCS	=	push_swap.c 		\
			arg_parsing.c		\
			pasring_utilites.c	\
			list_utilities.c	\
			swap_moves.c		\
			push_moves.c		\
			rotate_moves.c		\
			rrotate_moves.c		\
			sort_utilites.c		\
			sort_operations.c	\
			cal_ab_utilites.c	\
			cal_ba_utilites.c	\
			go_rotate_push.c		

OBJS	= ${SRCS:.c=.o}

NAME	= push_swap
CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Werror -Wextra -g3

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	${RM} ${OBJS} 

fclean: clean
	${RM} ${NAME}

re: fclean all
