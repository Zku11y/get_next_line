#include "get_next_line.h"

char *fd_read(int fd,char *T_line)
{
	char *R_line;
	ssize_t a;

	a = 1;
	if(!T_line)
		T_line = ft_calloc(1, 1);
	R_line = ft_calloc(BUFFER_SIZE, sizeof(char));
	while(a > 0 && !ft_strchr(R_line, '\n'))
	{
		a = read(fd, R_line, BUFFER_SIZE);
		T_line = ft_strjoin(T_line, R_line);
	}
	if(a == -1)
	{
		free(R_line);
		return (NULL);
	}
	free(R_line);
	return (T_line);
}
char *fd_line(char *T_line)
{
	int i;
	int j;
	char *line;
	char *new_T;

	i = 0;
	while(T_line[i] && T_line[i] != '\n')
		i++;
	line = ft_calloc(i, sizeof(char));
	i = 0;
	while(T_line[i] && T_line[i] != '\n')
	{
		line[i] = T_line[i];
		i++;
	}
	line[i] = '\0';
	j = 0;
	while(T_line[i + j])
		j++;
	new_T = ft_calloc(j, sizeof(char));
	j = 0;
	while(T_line[i])
		new_T[j++] = T_line[i++];
	T_line = new_T;
	return(line);
}

char *get_next_line(int fd)
{
	char *line;
	static char *T_line;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	T_line = fd_read(fd, T_line);
	line = fd_line(T_line);
	return (line);
}

