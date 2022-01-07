/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 23:29:03 by yanab             #+#    #+#             */
/*   Updated: 2022/01/03 14:30:26 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	get_nth_bit(unsigned char c, int n)
{
	unsigned char	comp_c;

	comp_c = 0b10000000;
	return (c & (comp_c >> n));
}

void	send_msg(int server_pid, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (j < 8)
		{
			if (!get_nth_bit(str[i], j))
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			usleep(100);
			j++;
		}
		i++;
	}
}

void	confirm_sent(int sig)
{
	(void)sig;
	ft_printf("A bit has been sent successfully.\n");
}

int	main(int argc, char **argv)
{
	int		server_pid;
	char	*message;

	if (argc != 3)
		ft_printf("Usage: ./client <Server PID> <Message>\n");
	else
	{
		server_pid = ft_atoi(argv[1]);
		if (server_pid <= 0)
		{
			ft_printf("Error: PID [%d] is invalid\n", server_pid);
			exit(0);
		}
		message = ft_strjoin(argv[2], "\n");
		signal(SIGUSR1, confirm_sent);
		send_msg(server_pid, message);
	}
	return (0);
}
