


NAME = square5d
CC = cc -g
CFLAGS = -Wall -Wextra -Werror
RM = rm -fr
LIBFT = ./libraries/libft/libft.a
PRINTF = ./libraries/printf/ft_printf.a

PARSE = srcs/main.c srcs/ft_error.c srcs/val_extensions.c  srcs/ft_getters.c\
		srcs/ft_freedoom.c srcs/val_color.c srcs/ft_assets.c srcs/val_colo_utils.c \
		srcs/val_map.c srcs/flood_map.c

SRCS = $(PARSE)

OBJS = ${SRCS:.c=.o}

$(NAME): $(LIBFT) $(PRINTF) $(LIBX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

clean:
	${MAKE} --no-print-directory clean -C ./libraries/libft
	${MAKE} --no-print-directory clean -C ./libraries/printf
	rm -fr ${OBJS}

fclean: clean
		${MAKE} fclean --no-print-directory -C ./libraries/libft
		${MAKE} fclean --no-print-directory -C ./libraries/printf
		rm -fr libft.a
		rm -fr ${NAME}

all: ${NAME}

re: fclean all

$(LIBFT):
	cd libraries && cd libft && make

$(PRINTF):
	cd libraries && cd printf && make


.PHONY: all clear fclean re
