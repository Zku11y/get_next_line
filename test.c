#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	char *str;
	int fd = open("test.txt", O_RDONLY);
	if(fd == -1)
		return (0);
	str = get_next_line(fd);
	while(str != NULL)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (0);
}
