/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:36:24 by skully            #+#    #+#             */
/*   Updated: 2024/11/20 14:49:40 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h> // why did you use these 2 libraries?

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