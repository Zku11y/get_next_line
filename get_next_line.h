/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:18:59 by mdakni            #+#    #+#             */
/*   Updated: 2024/11/21 11:19:00 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct list
{
	char		*str;
	struct list	*next;
}				t_list;

char			*get_next_line(int fd);
char			*ft_strchr(const char *s, char c);
char			*ft_strjoin(char *s1, char *s2);
void			*ft_calloc(size_t count, size_t size);
size_t			ft_strlen(const char *s);
char			*fd_line(char *stash);
char			*updated_t(char *stash);
char			*fd_read(int fd, char *stash);
char			*ft_strdup(const char *s1);

#endif