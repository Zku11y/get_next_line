#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1000
#endif

typedef struct list {
	char *str;
	struct list *next;
}	t_list;

#include <stdlib.h>
#include <unistd.h>

char *get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
char *fd_line(char *T_line);
char *updated_T(char *T_line);
char *fd_read(int fd,char *T_line);
char	*ft_strdup(const char *s1);
void	ft_bzero(void *s, size_t n);

#endif