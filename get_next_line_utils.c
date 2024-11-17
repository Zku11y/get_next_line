#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	size_t		i;
	const char	*ptr;

	i = 0;
	ptr = NULL;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		ptr = &s[i];
	return ((char *)ptr);
}
void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;

	if (count == 0 || size == 0)
	{
		ptr = malloc(0);
		return (ptr);
	}
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, size * count);
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = NULL;
	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	str = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i])
		str[j++] = (char)s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = (char)s2[i++];
	str[j] = '\0';
	return (str);
}
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
