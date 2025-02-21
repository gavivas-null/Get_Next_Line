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

char	*get_next_line(int fd)
{
	static char	*data; // variable estática para almacenar datos restantes despues del BUFFER_SIZE entre cada llamada;
	char		*buff; // buffer para leer datos del archivo
	ssize_t 	count; // bytes leidos -a leer
	char		*endline; // final de cada linea
	char		*newline; //linea guardada
	char		*tmp; //se usa para guardar el resto de los datos despues de extraer una linea  

	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		return (NULL);
	}
	buff = ft_calloc((BUFFER_SIZE + 1), sizeof(char)); //Memoria dinamica para malloc
	if (!buff)
		return (NULL);
	while(1) //buscle infinito para leer datos
	{
		count = read(fd, buff, BUFFER_SIZE); //Leer el txt y lo guarda en buff, count son los bytes leidos.
		if (count < 0) //en caso de error libera buff y retorna null.
		{
			free(buff);
			free(data);
			data = NULL;
			return (NULL);
		}		
		buff[count] = '\0'; // añade al final de la linea el caracter null para el correcto manejo de otras funciones.
		if (!data)
			data = ft_strdup("");
		tmp = ft_strjoin(data, buff);
		free(data);
		data = tmp;
		if (!data)
		{
			free(buff);
			return(NULL);
		}
		endline = ft_strchr(data, '\n'); //busca el final de la linea.
		if(endline) //si hay '\n' extrae la linea hasta el '\n' y guarda el resto.
		{	
			newline = ft_substr(data, 0, (endline - data) + 1); // extrae la linea con los datos de data para comenzar, hasta el '\n' y calcula la longitud para saber el tamaño de la string
			tmp = ft_strdup(endline + 1); //guardamos el resto para usarlo en el siguiente llamado
			free(data);
			data = tmp;
			free(buff);
			if(data && *data == '\0')
			{
				free(data);
				data = NULL;
			}
			return(newline);	
		}
		if (count == 0)
			break;
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

int	main(void)
{
	int		fd;
	char	*file;
	char	*str;

	file = "/Users/gabrielvivas/Desktop/get_next_line/prueba.txt";
	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
	return(0);
}