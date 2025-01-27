#include "get_next_line.h"

static char *read_file(int fd, char *buffer)
{
	int bytes;
	char *buffer;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
		
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes <= 0)
		return (free(buffer), NULL);
	return (buffer);
}

char *get_next_line(int fd)
{
	static char *buffer;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!buffer)
		buffer = ft_calloc(1, sizeof(char));
	if (!ft_strchr(buffer, '\n'))
		buffer = read_file(fd, buffer);
	if (!buffer)
		return (free(buffer), NULL);
	line = get_line(buffer);
	buffer = update_buffer(buffer);
	return (line);
}
