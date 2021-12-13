/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 23:29:07 by yanab             #+#    #+#             */
/*   Updated: 2021/12/13 03:14:43 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_isspace(int c)
{
	return (
		c == ' '
		|| c == '\f'
		|| c == '\n'
		|| c == '\r'
		|| c == '\t'
		|| c == '\v'
	);
}

int	ft_atoi(const char *nstr)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	while (ft_isspace(nstr[i]))
		i++;
	sign = 1;
	if (nstr[i] == '-' || nstr[i] == '+')
		if (nstr[i++] == '-')
			sign *= -1;
	num = 0;
	while (nstr[i] >= '0' && nstr[i] <= '9')
		num = num * 10 + (nstr[i++] - '0');
	return (num * sign);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		s_len;
	char	*dupicate;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	dupicate = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!dupicate)
		return (NULL);
	i = -1;
	while (s[++i])
		dupicate[i] = s[i];
	dupicate[i] = '\0';
	return (dupicate);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		s1_len;
	int		s2_len;
	char	*joined_str;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	joined_str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!joined_str)
		return (NULL);
	i = -1;
	while (s1[++i])
		joined_str[i] = s1[i];
	i = -1;
	while (s2[++i])
		joined_str[s1_len + i] = s2[i];
	joined_str[s1_len + i] = '\0';
	return (joined_str);
}
