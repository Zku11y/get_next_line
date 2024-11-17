#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
char *str;
int fd = open("test.txt", O_RDWR);

str = malloc(50);
read(fd, str, 3);
printf("%s\n", str);
read(fd, str, 3);
printf("%s\n", str);
read(fd, str, 3);
printf("%s\n", str);
close(fd);
}
