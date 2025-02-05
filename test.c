#include "get_next_line.c"
#include "get_next_line_utils.c"
#include <fcntl.h>
#include <stdio.h>


int	main(void)
{
	char *file_name = "file.txt";
	int fd = open(file_name, O_RDONLY);
	char *line;
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	while (line)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}

	close(fd);
	return (0);
}

// gcc -Wall -Wextra -Werror test.c && ./a.out
// valgrind --leak-check=full ./a.out
// gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 test.c && ./a.out