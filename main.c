#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
int	main(int ac, char **av)
{
	int fd;
	char	*line;
	int	reg_1;
	int	c;

	c = 1;
	line = NULL;
	fd =open("test1.txt", O_RDONLY);
	while ((reg_1 = get_next_line(fd, &line)) != 0)
	{
//		printf("%s", line);
		free(line);
	}
	sleep(10);
	return (0);
}	

