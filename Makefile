NAME = minitalk
FLAGS = -Wall -Wextra -Werror

SRCS =	client.c \
		server.c

all:

s:
	gcc $(FLAGS) minitalk_utils.c server.c -o server
	./server

c:
	gcc $(FLAGS) minitalk_utils.c client.c -o client
	# ./client 1000 "sdfsfsf"

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all