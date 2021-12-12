#include "minitalk.h"

int get_nth_bit(unsigned char c, int n)
{
	unsigned char	comp_c;

	comp_c = 0b10000000;
	return ((c & (comp_c >> (n - 1))) >> (8 - n));
}

int main(int argc, char **argv)
{
	int		i;
	int		j;
	int		server_pid;
	char	*message;

	if (argc != 3)
		printf("Usage: ./client <Server PID> <Message>\n");
	else
	{
		server_pid = ft_atoi(argv[1]);
		message = ft_strjoin(argv[2], "\n");

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
				usleep(100);
				j++;
			}
			i++;
		}
	}

	return (0);
}
