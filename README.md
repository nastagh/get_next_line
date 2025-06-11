# get_next_line

This project is about programming a function that returns a line read from a file descriptor

Start of program

gcc -Wall -Wextra -Werror test.c && ./a.out

valgrind --leak-check=full ./a.out

gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 test.c && ./a.out