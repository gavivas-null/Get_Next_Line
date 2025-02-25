/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:47:45 by gavivas-          #+#    #+#             */
/*   Updated: 2025/02/25 19:55:51 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*data;
	char		*buff;
	char		*endline;
	char		*newline;
	char		*tmp;
	ssize_t		count;

	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		return (NULL);
	}
	buff = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buff)
		return (NULL);
	while (1)
	{
		count = read(fd, buff, BUFFER_SIZE);
		if (count < 0)
		{
			free(buff);
			free(data);
			data = NULL;
			return (NULL);
		}
		buff[count] = '\0';
		if (!data)
			data = ft_strdup("");
		tmp = ft_strjoin(data, buff);
		free(data);
		data = tmp;
		if (!data)
		{
			free(buff);
			return (NULL);
		}
		endline = ft_strchr(data, '\n');
		if (endline)
		{
			newline = ft_substr(data, 0, (endline - data) + 1);
			tmp = ft_strdup(endline + 1);
			free(data);
			data = tmp;
			free(buff);
			if (data && *data == '\0')
			{
				free(data);
				data = NULL;
			}
			return (newline);
		}
		if (count == 0)
			break ;
	}
	free(buff);
	if (data && *data)
	{
		if (!ft_strchr(data, '\n'))
			newline = ft_strjoin(data, "\n");
		else
			newline = ft_strdup(data);
		free(data);
		data = NULL;
		return (newline);
	}
	return (NULL);
}
