#include "minitalk.h"

int shift = 0;
unsigned char chr = 0b00000000;

void handl(unsigned char *n, int bit, int *shift)
{
	*n |= bit;
	if (*shift != 7)
		*n = *n << 1;
	*shift += 1;
	if(*shift == 8)
	{
		write(1, n, 1);
		*n = 0b00000000;
		*shift = 0;
	}
}

void quit_server(int sig)
{
	printf("Server Terminated successfully !!!\n");
	exit(1);
}

// SIGUSR1 -> 0
// SIGUSR2 -> 1

void handle_input(int sig)
{
	if (sig == SIGUSR1)
		handl(&chr, 0, &shift);
	else
		handl(&chr, 1, &shift);
}

int main(void)
{
	printf("The Server's PID is [%d]\n", getpid());
	signal(SIGINT, quit_server);

	while (1)
	{
		signal(SIGUSR1, handle_input);
		signal(SIGUSR2, handle_input);
	}

	return (0);
}
