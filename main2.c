#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
    char *str;
int fd = open("test.txt", O_RDWR);
// int a = read(fd, NULL, 4);
// printf("%d\n", a);
str = get_next_line(fd);
printf("result = %s\n", str);
free(str);
str = get_next_line(fd);
printf("result = %s\n", str);
free(str);
str = get_next_line(fd);
printf("result = %s\n", str);
free(str);
str = get_next_line(fd);
printf("result = %s\n", str);
free(str);
str = get_next_line(fd);
printf("result = %s\n", str);
free(str);
str = get_next_line(fd);
printf("result = %s\n", str);
free(str);
close(fd);
}
