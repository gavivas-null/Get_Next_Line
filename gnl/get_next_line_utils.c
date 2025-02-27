/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:47:34 by gavivas-          #+#    #+#             */
/*   Updated: 2025/02/27 22:02:29 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;
	size_t	totalsize;
	size_t	i;

	i = 0;
	totalsize = count * size;
	if ((SIZE_MAX / size) < count && size != 0)
		return (NULL);
	arr = (void *)malloc(totalsize);
	if (arr == NULL)
		return (NULL);
	while (i < totalsize)
	{
		((char *)arr)[i] = 0;
		i++;
	}
	return (arr);
}

size_t	ft_strlen(const char *s)
{
	int	a;

	a = 0;
	if(!s)
		return(0);
	while (s[a] != '\0')
	{
		a++;
	}
	return (a);
}


char	*ft_strchr(const char *s, int c)
{
	int				a;
	unsigned char	l;

	l = c;
	a = 0;
	while (s[a] != '\0' && s[a] != l)
	{
		a++;
	}
	if (s[a] == l)
		return ((char *)&s[a]);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(const char *s1)
{
	size_t	size;
	size_t	i;
	char	*cpy;

	i = 0;
	size = ft_strlen(s1) + 1;
	cpy = malloc(sizeof(char) * size);
	if (cpy == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		size_s1;
	int		size_s2;
	char	*str;
	int		i;
	int		j;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (size_s1 + size_s2 + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < size_s1)
		str[i++] = s1[j++];
	j = 0;
	while (j < size_s2)
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}