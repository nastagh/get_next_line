#include "get_next_line.h"

static char	*read_file(int fd)
{
	int		bytes;
	char	*buffer;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes <= 0)
		return (free(buffer),NULL);
	return (buffer);

}

char	*get_next_line(int fd)
{
	char	*buffer;

	buffer = read_file(fd);
	return (buffer);
}
