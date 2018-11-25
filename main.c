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
/*	fd =open("test.txt", O_RDONLY);
	while ((reg_1 = get_next_line(fd, &line)) != 0)
	{
		printf("%s", line);
		sleep(2);
	}
*/

	//	printf("before while\n");
	while (c < ac)
	{
		fd = open(av[c], O_RDONLY);
		if (fd == -1)
		{
			printf("error\n");
			exit(1);
		}
		else
		{
		//	printf("calling get next line\n");
/*			while ((reg_1 = get_next_line(fd, &line)) != 0)
			{
				if (reg_1 == -1)
				{
					printf("error\n");
					exit(1);
				}
//				printf("%s", line);
//				free(line);
//				line = NULL;
			}
//			printf("finish %d file\n", fd);
*/	

		char **arr;
		arr = (char**)malloc(sizeof(char*) * 3);
		get_next_line(fd, &line);
		printf("%s", line);
		arr[0] = line;
		get_next_line(fd, &line);
		printf("%s", line);
		
		arr[2] = line;
		get_next_line(fd, &line);
		printf("%s", line);
	
		arr[3] = line;


		printf("%s", arr[0]);

		free(arr[0]);

		}
		c++;
//		sleep(2);
	}
//sleep(10);
	return (0);
}	

