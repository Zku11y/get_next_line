#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
char *str;
int fd = open("test.txt", O_RDWR);
printf("%s\n", get_next_line(fd));
read(fd, get_next_line(fd), 3);
printf("%s\n", get_next_line(fd));
read(fd, get_next_line(fd), 3);
printf("%s\n", get_next_line(fd));
close(fd);
}
