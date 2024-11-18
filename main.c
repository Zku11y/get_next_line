#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
char *str;
int fd = open("test.txt", O_RDWR);

str = malloc(50);
read(1, str, 10);
printf("%s\n", str);
read(1, str, 10);
printf("%s\n", str);
read(1, str, 10);
printf("%s\n", str);
close(fd);
}
