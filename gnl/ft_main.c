/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 20:01:06 by gavivas-          #+#    #+#             */
/*   Updated: 2025/03/04 22:27:42 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*file;
	char	*str;

	// file = "/home/gavivas-/Desktop/lunes/1char.txt";
	// file = "/home/gavivas-/Desktop/lunes/41_no_nl";
	//file = "/home/gavivas-/Desktop/lunes/41_with_nl";
	// file = "/home/gavivas-/Desktop/lunes/42_no_nl";
	// file = "/home/gavivas-/Desktop/lunes/42_with_nl";
	// file = "/home/gavivas-/Desktop/lunes/43_no_nl";
	// file = "/home/gavivas-/Desktop/lunes/43_with_nl";
	// file = "/home/gavivas-/Desktop/lunes/alternate_line_nl_no_nl";
	// file = "/home/gavivas-/Desktop/lunes/alternate_line_nl_with_nl";
	// file = "/home/gavivas-/Desktop/lunes/big_line_no_nl";
	// file = "/home/gavivas-/Desktop/lunes/big_line_with_nl";
	// file = "/home/gavivas-/Desktop/lunes/empty";
	// file = "/home/gavivas-/Desktop/lunes/empty.txt";
	// file = "/home/gavivas-/Desktop/lunes/giant_line_nl.txt";
	// file = "/home/gavivas-/Desktop/lunes/giant_line.txt";
	// file = "/home/gavivas-/Desktop/lunes/hola.txt";
	// file = "/home/gavivas-/Desktop/lunes/lines_around_10.txt";
	// file = "/home/gavivas-/Desktop/lunes/multiple_line_no_nl";
	// file = "/home/gavivas-/Desktop/lunes/multiple_line_with_nl";
	// file = "/home/gavivas-/Desktop/lunes/multiple_nl.txt";
	// file = "/home/gavivas-/Desktop/lunes/multiple_nlx5";
	// file = "/home/gavivas-/Desktop/lunes/nl";
	// file = "/home/gavivas-/Desktop/lunes/one_line_no_nl.txt";
	// file = "/home/gavivas-/Desktop/lunes/only_nl.txt";
	file = "/home/gavivas-/Desktop/lunes/read_error.txt";
	// file = "/home/gavivas-/Desktop/lunes/variable_nls.txt";

																							
	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		printf("line: %s", str);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
	return (0);
}
