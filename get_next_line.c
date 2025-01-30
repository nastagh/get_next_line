#include "get_next_line.h"

char *get_line(char *buffer)
{
	char *line;
	int i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		i++;
	}
	line = ft_calloc(i, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\n';
	return (line);
}

char *append_buffer(char *buffer, char *new_chunk)
{
	char *tmp;
	int size;
	int i;
	int j;

	i = 0;
	j = 0;
	size = ft_strlen(buffer) + ft_strlen(new_chunk);
	tmp = (char *)malloc((size + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	while (buffer[i])
	{
		tmp[i] = buffer[i];
		i++;
	}
	while (new_chunk[j])
	{
		tmp[i] = new_chunk[j];
		i++;
		j++;
	}
	free(buffer);
	return (tmp);
}

char *read_file(int fd, char *buffer)
{
	int bytes;
	char *chunk_buffer;

	chunk_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!chunk_buffer)
		return (NULL);
	while (1)
	{
		bytes = read(fd, chunk_buffer, BUFFER_SIZE);
		if (bytes <= 0)
			return (free(chunk_buffer), NULL);
		buffer = append_buffer(buffer, chunk_buffer);
		if (ft_strchr(buffer, '\n'))
			break;
	}
	free(chunk_buffer);
	return (buffer);
}

char *get_next_line(int fd)
{
	static char *buffer;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = ft_calloc(1, sizeof(char));
	// if (!ft_strchr(buffer, '\n'))
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (free(buffer), NULL);
	line = get_line(buffer);
	// buffer = update_buffer(buffer);
	return (line);
}
