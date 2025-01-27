#include <fcntl.h>
#include <stdio.h>
#include "get_next_line_utils.c"
#include "get_next_line.c"

int	main(void)
{
	char *file_name = "file.txt";
	int fd = open(file_name, O_RDONLY);
	if(fd == -1){
        printf("\nError Opening File!!\n");
		return (1);
    }
	char *line;
	line = get_next_line(fd);
	printf("%s", line);

	free(line);
	line = NULL;
	
	close(fd);
	return (0);
}