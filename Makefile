SRCS	=	push_swap.c 		\
			ft_parsing.c		\
			pasring_utilites.c	\
			list_utilities.c	\
			stack_moves.c

OBJS	= ${SRCS:.c=.o}

NAME	= push_swap
CC		= gcc
RM		= rm -f
ifeq ($(OS), Windows_NT)
    RM = del /Q > nul 2>&1
	NAME = push_swap.exe
endif
CFLAGS	= -Wall -Werror -Wextra

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
