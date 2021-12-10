#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <stdio.h> // REMOVE LATER

int		ft_isspace(int c);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *nstr);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *s);

#endif
