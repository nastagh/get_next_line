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

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tmp;

	tmp = (void *) malloc(nmemb * size);
	if (!tmp)
		return (NULL);
	ft_bzero(tmp, nmemb * size);
	return (tmp);
}