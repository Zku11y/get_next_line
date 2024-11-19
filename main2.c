#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
    char *str;
int fd = open("test.txt", O_RDWR);
str = malloc(BUFFER_SIZE + 1);
if (!str)
    return NULL;
// int a = read(fd, NULL, 4);
// printf("%d\n", a);
// str = get_nexstash(fd);
// printf("result = %s\n", str);
// free(str);
// str = get_nexstash(fd);
// printf("result = %s\n", str);
// free(str);
// str = get_nexstash(fd);
// printf("result = %s\n", str);
// free(str);
// str = get_nexstash(fd);
// printf("result = %s\n", str);
// free(str);
// str = get_nexstash(fd);
// printf("result = %s\n", str);
// free(str);
// str = get_nexstash(fd);
// printf("result = %s\n", str);
// free(str);
    while ((str = get_next_line(fd)))
    {
        printf("%s\n", str);
        free(str);
    }
	close(fd);
	return (0);
}
