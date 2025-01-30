#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	if (!s)
		return ;
	while (n)
	{
		((char *)s)[n] = 0;
		n--;
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tmp;

	tmp = (void *) malloc(nmemb * size);
	if (!tmp)
		return (NULL);
	ft_bzero(tmp, nmemb * size);
	return (tmp);
}

char	*ft_strchr(const char *s, int c)
{
	char	*tmp;

	tmp = (char *)s;
	while (*tmp)
	{
		if (*tmp == (char)c)
			return (tmp);
		tmp++;
	}
	if (*tmp == (char)c)
		return (tmp);
	return (NULL);
}