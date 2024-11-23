NAME = square5d
CC = cc -g
CFLAGS = -Wall -Wextra -Werror
RM = rm -fr

PARSE = srcs/main.c \

SRCS = $(PARSE)

OBJS = ${SRCS:.c=.o}

${NAME}: ${OBJS}
		${MAKE} --no-print-directory -C ./libraries/libft
		cp ./libraries/libft/libft.a .
		${CC} ${CFLAGS} ${OBJS} libft.a -o ${NAME} -lreadline

clean:
	${MAKE} --no-print-directory clean -C ./libraries/libft
	rm -fr ${OBJS}

fclean: clean
		${MAKE} fclean --no-print-directory -C ./libraries/libft
		rm -fr libft.a
		rm -fr ${NAME}

all: ${NAME}

re: fclean all

.PHONY: all clear fclean re