/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 23:29:03 by yanab             #+#    #+#             */
/*   Updated: 2021/12/13 03:01:44 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	get_nth_bit(unsigned char c, int n)
{
	unsigned char	comp_c;

	comp_c = 0b10000000;
	return ((c & (comp_c >> (n - 1))) >> (8 - n));
}

void	send_char(int server_pid, char chr)
{
	int	j;

	j = 1;
	while (j <= 8)
	{
		if (!get_nth_bit(chr, j))
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(100);
		j++;
	}
}

void	confirm_sent(int sig)
{
	(void)sig;
	write(1, "A bit has been sent successfully.\n", 35);
}

int	main(int argc, char **argv)
{
	int		i;
	int		server_pid;
	char	*message;

	if (argc != 3)
		printf("Usage: ./client <Server PID> <Message>\n");
	else
	{
		i = 0;
		server_pid = ft_atoi(argv[1]);
		message = ft_strjoin(argv[2], "\n");
		signal(SIGUSR1, confirm_sent);
		while (message[i])
			send_char(server_pid, message[i++]);
	}
	return (0);
}
