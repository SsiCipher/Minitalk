CC		=	cc
NAME	=	minitalk
FLAGS	=	-Wall -Wextra -Werror

CLIENT	=	client
SERVER	=	server

all:	ft_printf $(NAME)

$(NAME):	$(SERVER) $(CLIENT)

ft_printf:
	@make -C ft_printf

$(SERVER): server.c minitalk_utils.c minitalk.h
	$(CC) $(FLAGS) minitalk_utils.c ft_printf/libftprintf.a server.c -o server

$(CLIENT): client.c minitalk_utils.c minitalk.h
	$(CC) $(FLAGS) minitalk_utils.c ft_printf/libftprintf.a client.c -o client

clean:
	@make -C ft_printf clean

fclean:
	rm -rf $(SERVER) $(CLIENT)
	@make -C ft_printf fclean

re: fclean all

.PHONY: ft_printf
