CC = cc
NAME = minitalk
FLAGS = -Wall -Wextra -Werror

SRCS =	client.c \
		server.c

all: $(NAME)

$(NAME): s c

s:
	$(CC) $(FLAGS) minitalk_utils.c server.c -o server

c:
	$(CC) $(FLAGS) minitalk_utils.c client.c -o client

clean:
	rm -rf client
	rm -rf server

fclean: clean

re: fclean all
