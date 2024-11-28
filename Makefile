NAME = square5d
CC = cc -g
CFLAGS = -Wall -Wextra -Werror
RM = rm -fr
LIBFT = ./libraries/libft/libft.a
PRINTF = ./libraries/printf/ft_printf.a

PARSE = srcs/main.c srcs/val_colors.c srcs/ft_freedom.c srcs/ft_error_central.c \
		srcs/val_extensions.c srcs/validations.c

SRCS = $(PARSE)

OBJS = ${SRCS:.c=.o}

$(NAME): $(LIBFT) $(PRINTF)  $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

clean:
	${MAKE} --no-print-directory clean -C ./libraries/libft
	rm -fr ${OBJS}

fclean: clean
		${MAKE} fclean --no-print-directory -C ./libraries/libft
		rm -fr libft.a
		rm -fr ${NAME}

all: ${NAME}

re: fclean all

$(LIBFT):
	cd libraries && cd libft && make 
	
$(PRINTF):
	cd libraries && cd printf && make 


.PHONY: all clear fclean re
