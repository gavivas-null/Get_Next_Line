#include "/home/gavivas-/Desktop/gnl/get_next_line/get_next_line.h"

int	main(void)
{
	int		fd;
	char	*file;
	char	*str;

	file = "/home/gavivas-/Desktop/gnl/prueba.txt";
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