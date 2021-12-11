CC = cc
NAME = minitalk
FLAGS = -Wall -Wextra -Werror

SRCS =	client.c \
		server.c


s:
	@$(CC) $(FLAGS) minitalk_utils.c server.c -o server
	@./server

c:
	@$(CC) $(FLAGS) minitalk_utils.c client.c -o client

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
