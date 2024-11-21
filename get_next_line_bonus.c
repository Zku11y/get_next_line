/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:18:24 by mdakni            #+#    #+#             */
/*   Updated: 2024/11/21 11:18:25 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*fd_read(int fd, char *stash)
{
	ssize_t	a;
	char	*tmp;

	a = 1;
	if (!stash)
		stash = ft_strdup("");
	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (free(stash), stash = NULL, NULL);
	a = 1;
	while (a > 0)
	{
		a = read(fd, tmp, BUFFER_SIZE);
		if (a == -1)
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

char	*updated_t(char *stash)
{
	char	*new_stash;
	int		i;
	int		j;

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
	new_stash[j] = '\0';
	free(stash);
	stash = NULL;
	return (new_stash);
}

char	*fd_line(char *stash)
{
	int		i;
	char	*line;

	if (!stash || !stash[0])
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = ft_calloc(i + 1, 1);
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i])
		line[i++] = '\n';
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash[256];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (free(stash[fd]), stash[fd] = NULL, NULL);
	stash[fd] = fd_read(fd, stash[fd]);
	if (stash[fd] == NULL)
		return (free(stash[fd]), stash[fd] = NULL, NULL);
	line = fd_line(stash[fd]);
	if (!line)
		return (free(stash[fd]), stash[fd] = NULL, NULL);
	stash[fd] = updated_t(stash[fd]);
	return (line);
}
