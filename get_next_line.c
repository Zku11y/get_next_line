#include "get_next_line.h"
#include <stdio.h>
#include <limits.h>

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	str = malloc(ft_strlen(s1) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char *fd_read(int fd,char *T_line)
{
	char *R_line;
	ssize_t a;
	char *tmp;

	a = 1;
	R_line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while(a > 0 && !ft_strchr(R_line, '\n'))
	{
		tmp = T_line;
		a = read(fd, R_line, BUFFER_SIZE);
		R_line[a] = '\0';
		T_line = ft_strjoin(T_line, R_line);
		free(tmp);
	}
	if(a == -1)
	{
		free(R_line);
		free(T_line);
		return (NULL);
	}
	free(R_line);
	return (T_line);
}
char *updated_T(char *T_line)
{
	char *new_T;
	int j;
	int i;

	i = 0;
	j = 0;
	new_T = NULL;
	while(T_line[i] && T_line[i] != '\n')
		i++;
	if(!T_line[i])
	{
		free(T_line);
		return (new_T);
	}
	i++;
	while(T_line[i + j])
		j++;
	new_T = ft_calloc(j + 1, sizeof(char));
	j = 0;
	while(T_line[i])
		new_T[j++] = T_line[i++];
	new_T[j] = '\0';
	free(T_line);
	return(new_T);
}

char *fd_line(char *T_line)
{
	int i;
	char *line;

	if(!T_line[0])
	{
		return (NULL);
	}
	i = 0;
	while(T_line[i] && T_line[i] != '\n')
		i++;
	line = ft_calloc(i + 1, sizeof(char));
	i = 0;
	while(T_line[i] && T_line[i] != '\n')
	{
		line[i] = T_line[i];
		i++;
	}
	line[i] = '\0';
	return(line);
}

char *get_next_line(int fd)
{
	char *line;
	static char *T_line;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	T_line = fd_read(fd, T_line);
	if(T_line == NULL)
	{
		return (NULL);
	}
	line = fd_line(T_line);
	T_line = updated_T(T_line);
	return (line);
}

