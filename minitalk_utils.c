#include "minitalk.h"

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

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*char_dest;
	char		*char_src;

	if (!dest && !src)
		return (NULL);
	i = -1;
	char_dest = (char *)dest;
	char_src = (char *)src;
	while (++i < n)
		char_dest[i] = char_src[i];
	return (dest);
}

char	*ft_strdup(const char *s)
{
	int		s_len;
	char	*dupicate;

	s_len = ft_strlen(s);
	dupicate = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!dupicate)
		return (NULL);
	ft_memcpy(dupicate, s, s_len);
	dupicate[s_len] = '\0';
	return (dupicate);
}
