#include "minitalk.h"

t_char *g_c;

void assemble_char(unsigned char *n, int bit, int *shift)
{
	*n |= bit;
	if (*shift != 7)
		(*n) <<= 1;
	*shift += 1;
	if(*shift == 8)
	{
		write(1, n, 1);
		*n = 0b00000000;
		*shift = 0;
	}
}

void handle_input(int sig)
{
	assemble_char(&(g_c->chr), sig != SIGUSR1, &(g_c->shift));
}

int main(void)
{
	g_c = (t_char *)malloc(sizeof(t_char));
	g_c->shift = 0;
	g_c->chr = 0b00000000;

	printf("The Server's PID is [%d]\n", getpid());
	signal(SIGUSR1, handle_input);
	signal(SIGUSR2, handle_input);

	while (1)
		sleep(1);

	return (0);
}
