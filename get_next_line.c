#include "get_next_line.h"

static char	*get_new_line(char *buffer)
{
	char *line;
	int i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

static char	*append_to_buffer(char *buffer, char *new_chunk)
{
	char *tmp;
	int size;
	int i;
	int j;

	i = 0;
	j = 0;
	size = ft_strlen(buffer) + ft_strlen(new_chunk);
	tmp = ft_calloc((size + 1), sizeof(char));
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

static char	*update_buffer(char *buffer, char *line)
{
	int i;
	int j;
	char *tmp;

	j = 0;
	if (!buffer[j])
	{
		free(buffer);
		return (NULL);
	}
	i = ft_strlen(line);
	if (!buffer[i])
		tmp = ft_calloc(1, sizeof(char));
	else
	{
		tmp = ft_calloc((ft_strlen(buffer) - i + 1), (sizeof(char)));
		while (buffer[i])
			tmp[j++] = buffer[i++];
	}
	tmp[j] = '\0';
	free(buffer);
	return (tmp);
}

static char	*read_file(int fd, char *buffer)
{
	int bytes;
	char *chunk_buffer;

	chunk_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!chunk_buffer)
		return (NULL);
	while (1)
	{
		bytes = read(fd, chunk_buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			free(chunk_buffer);
			return (NULL);
		}
		chunk_buffer[bytes] = 0;
		buffer = append_to_buffer(buffer, chunk_buffer);
		if (ft_strchr(buffer, '\n') || bytes == 0)
			break ;
	}
	free(chunk_buffer);
	return (buffer);
}
char	*get_next_line(int fd)
{
	static char *buffer;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = ft_calloc(1, sizeof(char));
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_new_line(buffer);
	buffer = update_buffer(buffer, line);
	return (line);
}