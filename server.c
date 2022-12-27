/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 23:29:22 by yanab             #+#    #+#             */
/*   Updated: 2022/01/03 14:49:14 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_char	*g_c;

void	assemble_char(unsigned char *n, int bit, int *shift)
{
	*n |= bit;
	if (*shift != 7)
		*n <<= 1;
	*shift += 1;
	if (*shift == 8)
	{
		write(1, n, 1);
		*n = 0b00000000;
		*shift = 0;
	}
}

void	handle_input(int sig, siginfo_t *info, void *context)
{
	pid_t	client_pid;

	(void)context;
	client_pid = info->si_pid;
	assemble_char(&(g_c->chr), sig != SIGUSR1, &(g_c->shift));
	kill(client_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	g_c = malloc(sizeof(t_char));
	ft_printf("The Server's PID is [%d]\n", getpid());
	g_c->shift = 0;
	g_c->chr = 0b00000000;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_input;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		sleep(1);
	return (0);
}
