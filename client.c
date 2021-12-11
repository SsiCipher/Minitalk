#include "minitalk.h"

int get_nth_bit(unsigned char c, int n)
{
	unsigned char	comp_c;

	comp_c = 0b10000000;
	if (n > 8)
		return (-1);
	else
		return ((c & (comp_c >> (n - 1))) >> (8 - n));
}

int main(int argc, char **argv)
{
	int		server_pid;
	char	*message;
	int		i;
	int		j;

	if (argc != 3)
		printf("Usage: ./client <Server PID> <Message>\n");
	else
	{
		server_pid = ft_atoi(argv[1]);
		message = ft_strdup(argv[2]);

		printf("Send to server pid [%d] message [%s]\n", server_pid, message);
		i = 0;
		while (message[i])
		{
			j = 1;
			while (j <= 8)
			{
				if (!get_nth_bit(message[i], j))
					kill(server_pid, SIGUSR1);
				else
					kill(server_pid, SIGUSR2);
				pause();
				j++;
			}
			i++;
		}
	}

	return (0);
}
