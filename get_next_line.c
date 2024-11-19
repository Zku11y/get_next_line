#include "get_next_line.h"
#include <stdio.h>
#include <limits.h>

char *fd_read(int fd,char *stash)
{
	ssize_t a;
	char *tmp;

	a = 1;
	if(!stash)
		stash = ft_strdup("");
	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (free(stash), stash = NULL, NULL);
	a = 1;
	while(a > 0)
	{
		a = read(fd, tmp, BUFFER_SIZE);
		if(a == -1)
			return (free(tmp), tmp = NULL, free(stash), stash = NULL, NULL);
		tmp[a] = '\0';
		stash = ft_strjoin(stash, tmp);
		if (!stash)
			return (free(tmp), tmp = NULL, NULL);
		if (ft_strchr(tmp, '\n'))
			break ;
	}
	free(tmp);
	tmp = NULL;
	return (stash);
}

char *updated_T(char *stash)
{
	char *new_stash;
	int i, j;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), stash = NULL, NULL);
	i++;
	new_stash = malloc(ft_strlen(stash) - i + 1);
	if (!new_stash)
		return (free(stash), stash = NULL, NULL);
	j = 0;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = 0;
	free(stash);
	stash = NULL;
	return(new_stash);
}

char *fd_line(char *stash)
{
	int i;
	char *line;

	if(!stash || !stash[0])
		return (NULL);
	i = 0;
	while(stash[i] && stash[i] != '\n')
		i++;
	if(stash[i] == '\n')
		i++;
	line = ft_calloc(i + 1, 1);
	if(!line)
		return (NULL);
	i = 0;
	while(stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if(stash[i])
		line[i++] = '\n';
	return(line);
}

char *get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if(fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (free(stash), stash= NULL, NULL);

	stash = fd_read(fd, stash);
	if(stash == NULL)
		return (free(stash), stash = NULL, NULL);

	line = fd_line(stash);
	if (!line)
		return (free(stash), stash = NULL, NULL);

	stash = updated_T(stash);
	return (line);
}

