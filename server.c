#include "minitalk.h"

int shift = 0;
unsigned char chr = 0b00000000;

void assemble_char(unsigned char *n, int bit, int *shift)
{
	if(*shift == 8)
	{
		write(1, n, 1);
		*n = 0b00000000;
		*shift = 0;
	}
	*n |= bit;
	if (*shift != 7)
		(*n) <<= 1;
	*shift += 1;
}

void handle_input(int sig)
{
	if (sig == SIGUSR1)
		assemble_char(&chr, 0, &shift);
	else
		assemble_char(&chr, 1, &shift);
}

int main(void)
{
	printf("The Server's PID is [%d]\n", getpid());
	signal(SIGUSR1, handle_input);
	signal(SIGUSR2, handle_input);

	while (1)
		sleep(1);

	return (0);
}
