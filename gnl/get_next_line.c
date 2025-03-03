/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:47:45 by gavivas-          #+#    #+#             */
/*   Updated: 2025/03/03 21:44:44 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*data = NULL;
	char		*buff;
	char		*endline;
	char		*newline;
	char		*tmp;
	ssize_t		count;

	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		return (NULL);
	}
	buff = ft_calloc((BUFFER_SIZE + 1), sizeof(char)); /* calloc */
	if (!buff) //calloc 
		return (NULL); //calloc
	while (1)
	{
		count = read(fd, buff, BUFFER_SIZE); //lee el archivo
		if (count <= 0)
		{
			free(buff);
			if (count < 0 || !data) // si hay error
			{
				free(data);
				data = NULL;
				return (NULL);
			}
			break ;
		}
		buff[count] = '\0'; //null al final de la linea leida
		tmp = ft_strjoin(data, buff); //une en una funcion temporal lo que tiene data (lo restante) con lo que se lee en el segundo llamado.
		if (!tmp)
		{
			free(buff);
			free(data);
			data = NULL;
			return (NULL);
		}
		data = tmp; //almacena la nueva linea con todo.
		endline = ft_strchr(data, '\n'); //busca el final de cada linea.
		if (endline) //si el final de la linea existe
		{
			newline = ft_substr(data, 0, (endline - data) + 1); //extrae la linea completa desde lo que tiene data hasta endline dejando un espacio para el null.
			tmp = ft_substr(data, (endline - data) + 1, ft_strlen(endline + 1)); //guarda el resto para el siguiente llamado.
			free(data); //libera data.
			data = tmp; //data guarda la linea duplicada.
			free(buff);
			return (newline); //retorna la nueva linea hasta el salto de linea.
		}
	}
	if (data && *data) //si tada todavia tiene algo guardado
	{
		newline = ft_substr(data, 0, ft_strlen(data)); //si es el fin de el archivo retorna hasta el null
		free(data);
		data = NULL;
		return (newline);
	}
	free(data);
	data = NULL;
	return (NULL);
}
