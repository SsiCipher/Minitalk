CC = cc
NAME = minitalk
FLAGS = -Wall -Wextra -Werror

SRCS =	client.c \
		server.c

all: $(NAME)

$(NAME): ft_printf s c

ft_printf:
	make -C ft_printf
	make -C ft_printf clean

s:
	$(CC) $(FLAGS) minitalk_utils.c ft_printf/libftprintf.a server.c -o server

c:
	$(CC) $(FLAGS) minitalk_utils.c ft_printf/libftprintf.a client.c -o client

clean:
	rm -rf client
	rm -rf server
	make -C ft_printf clean

fclean: clean
	make -C ft_printf fclean

re: fclean all

.PHONY: ft_printf
