
#include "get_next_line_bonus.h"
#include <stdio.h>
int	main(void)
{
	int	fd1;
	int	fd2;
	char *line;
	int		i;

	i = 14;
	fd1 = open("txt", O_RDONLY);
	// fd1 = open("txt1", O_RDONLY);
	// line = get_next_line(fd2);
	// printf("fd2 : %s", line);
	// free(line);
	// line = get_next_line(fd2);
	// printf("fd2 : %s", line);
	line = get_next_line(fd1);
	printf("fd1 : %s", line);
	free(line);
	line = get_next_line(fd1);
	printf("fd1 : %s", line);
	free(line);

	// line = get_next_line(fd1);
	// printf("fd1 : %s", line);
	// free(line);
	// line = get_next_line(fd1);
	// printf("fd1 : %s", line);
	// free(line);
	// line = get_next_line(fd2);
	// printf("fd2 : %s", line);
	// free(line);
	// line = get_next_line(fd1);
	// printf("fd1 : %s", line);
	// free(line);
	// line = get_next_line(fd2);
	// printf("fd2 : %s", line);
	// free(line);
	// line = get_next_line(fd1);
	// printf("fd1 : %s", line);
	// free(line);
	// line = get_next_line(fd2);
	// printf("fd2 : %s", line);
	// free(line);
	// line = get_next_line(fd1);
	// printf("fd1 : %s", line);
	// free(line);
	// line = get_next_line(fd2);
	// printf("fd2 : %s", line);
	close (fd1);

}
