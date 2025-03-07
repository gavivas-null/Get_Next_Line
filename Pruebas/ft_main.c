/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 20:01:06 by gavivas-          #+#    #+#             */
/*   Updated: 2025/03/07 20:26:11 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*file;
	char	*str;

	//	file = "pruebas/1char.txt";
	//	file = "pruebas/41_no_nl";
	//	file = "pruebas/41_with_nl";
	//	file = "pruebas/42_no_nl";
	//	file = "pruebas/42_with_nl";
	//	file = "pruebas/43_no_nl";
	//	file = "pruebas/43_with_nl";
	//	file = "pruebas/alternate_line_nl_no_nl";
	//	file = "pruebas/alternate_line_nl_with_nl";
	//	file = "pruebas/big_line_no_nl";
	//	file = "pruebas/big_line_with_nl";
	//	file = "pruebas/empty";
	//	file = "pruebas/empty.txt";
	//	file = "pruebas/giant_line_nl.txt";
	//	file = "pruebas/giant_line.txt";
	//	file = "pruebas/hola.txt";
	//	file = "pruebas/limits.txt";
	//	file = "pruebas/lines_around_10.txt";
	//	file = "pruebas/multiple_line_no_nl";
	//	file = "pruebas/multiple_line_with_nl";
	//	file = "pruebas/multiple_nl.txt";
	//	file = "pruebas/multiple_nlx5";
	//	file = "pruebas/nl";
	//	file = "pruebas/one_line_no_nl.txt";
	//	file = "pruebas/only_nl.txt";
	//	file = "pruebas/read_error.txt";
	//	file = "pruebas/variable_nls.txt";
	//	file = "libros/Alejando Pérez Visa - La saga de Darren Shan 01 - El Tenebroso Cirque du Freak.txt";
	//	file = "libros/Alejando Pérez Visa - La saga de Darren Shan 02 - El Asistente del Vampiro.txt";
	//	file = "libros/Alejando Pérez Visa - La saga de Darren Shan 03 - Túneles de Sangre.txt";
	//	file = "libros/Alejando Pérez Visa - La saga de Darren Shan 04 - La Montaña de los Vampiros.txt";
	//	file = "libros/Alejando Pérez Visa - La saga de Darren Shan 05 - La Ordalía de la Muerte.txt";
	//	file = "libros/Alejando Pérez Visa - La saga de Darren Shan 06 - El Príncipe Vampiro.txt";
	//	file = "libros/Alejando Pérez Visa - La saga de Darren Shan 07 - Cazadores del Crepúsculo.txt";
	//	file = "libros/Alejando Pérez Visa - La saga de Darren Shan 08 - Aliados de la Noche.txt";
	//	file = "libros/Alejando Pérez Visa - La saga de Darren Shan 09 - Asesinos del Alba.txt";
	//	file = "libros/Alejando Pérez Visa - La saga de Darren Shan 10 - El Lago de las Almas.txt";
	//	file = "libros/Alejando Pérez Visa - La saga de Darren Shan 11 - El Señor de las Sombras.txt";
	//	file = "libros/Alejando Pérez Visa - La saga de Darren Shan 12 - Hijos del Destino.txt";
	//	file = "libros/Arthur Conan Doyle - El signo de los cuatro.txt";
	//	file = "libros/Arthur Conan Doyle - Estudio en Escarlata.txt";
	//	file = "libros/C. S. Lewis - Las Crónicas de Narnia 1 - El León, la Bruja y el Ropero.txt";
	//	file = "libros/C. S. Lewis - Las Crónicas de Narnia 2 - El Principe Caspian.txt";
	//	file = "libros/C. S. Lewis - Las Crónicas de Narnia 3 - La Travesia del Explorador del Amanecer.txt";
	//	file = "libros/C. S. Lewis - Las Crónicas de Narnia 4 - La Silla de Plata.txt";
	//	file = "libros/C. S. Lewis - Las Crónicas de Narnia 5 - El Caballo y su Niño.txt";
	//	file = "libros/C. S. Lewis - Las Crónicas de Narnia 6 - El Sobrino del Mago.txt";
	//	file = "libros/C. S. Lewis - Las Crónicas de Narnia 7 - La Última Batalla.txt";
	//	file = "libros/Christopher Paolini - El Legado 1 - Eragon.txt";
	//	file = "libros/Christopher Paolini - El Legado 2 - Eldest.txt";
	//	file = "libros/Christopher Paolini - El Legado 3 - Brisingr.txt";
	//	file = "libros/Dan Brown - Ángeles y Demonios.txt";
	//	file = "libros/Dan Brown - El Código Da Vinci.txt";
	//	file = "libros/Dan Brown - El Símbolo Perdido.txt";
	//	file = "libros/Dan Brown - La Conspiración.txt";
	//	file = "libros/Dan Brown - La Fortaleza Digital.txt";
	//	file = "libros/David Bischoff - Juegos de Guerra.txt";
	//	file = "libros/Gabriel García Márquez - Vivir para contarla.txt";
	//	file = "libros/George Norman Lippert - James Potter 1 - La Encrucijada de los Mayores.txt";
	//	file = "libros/George Norman Lippert - James Potter 2 - La Maldición del Guardián.txt";
	//	file = "libros/George R. R. Martin - Canción de Hielo y Fuego 1 - Juego de Tronos.txt";
	//	file = "libros/George R. R. Martin - Canción de Hielo y Fuego 2 - Choque de Reyes.txt";
	//	file = "libros/George R. R. Martin - Canción de Hielo y Fuego 3 - Tormenta de espadas I.txt";
	//	file = "libros/George R. R. Martin - Canción de Hielo y Fuego 3 - Tormenta de espadas II.txt";
	//	file = "libros/Isaac Asimov - Las Amenazas de Nuestro Mundo.txt";
	//	file = "libros/J.K. Rowling - Harry Potter 1 - La Piedra Filosofal.txt";
	//	file = "libros/J.K. Rowling - Harry Potter 2 - La Cámara Secreta.txt";
	//	file = "libros/J.K. Rowling - Harry Potter 3 - El Prisionero de Azkaban.txt";
	//	file = "libros/J.K. Rowling - Harry Potter 4 - El Cáliz de Fuego.txt";
	//	file = "libros/J.K. Rowling - Harry Potter 5 - La Orden del Fenix.txt";
	//	file = "libros/J.K. Rowling - Harry Potter 6 - El Misterio del Príncipe.txt";
	//	file = "libros/J.K. Rowling - Harry Potter 7 - Las Reliquias de la Muerte.txt";
	//	file = "libros/J.M. Barrie - Peter Pan.txt";
	//	file = "libros/Julio Verne - Viaje al Centro de la Tierra.txt";
	//	file = "libros/Justin Somper - Vampiratas 1 - Demonios del Oceano.txt";
	//	file = "libros/Justin Somper - Vampiratas 2 - Una ola de Terror.txt";
	//	file = "libros/Justin Somper - Vampiratas 3 - Emboscada en el Océano.txt";
	//	file = "libros/Justin Somper - Vampiratas 4 - Sangre de Capitan.txt";
	//	file = "libros/Katherine Neville - El Ocho.txt";
	//	file = "libros/La Santa Biblia Antiguo y Nuevo Testamento.txt";
	//	file = "libros/Laura Gallego García - Finis Mundi.txt";
	//	file = "libros/Laura Gallego García - La emperatriz de los Etéreos.txt";
	//	file = "libros/Lisa Jane Smith - Serie Diarios Vampiricos 1 - Despertar - Awakening.txt";
	//	file = "libros/Lisa Jane Smith - Serie Diarios Vampiricos 2 - Conflicto - The Struggle.txt";
	//	file = "libros/Lisa Jane Smith - Serie Diarios Vampiricos 3 - Furia - The Fury.txt";
	//	file = "libros/Lisa Jane Smith - Serie Diarios Vampiricos 4 - Invocación - Dark Reunion.txt";
	//	file = "libros/Lisa Jane Smith - Serie Diarios Vampiricos 5 - El regreso - Anochecer.txt";
	//	file = "libros/Manel Loureiro - Apocalipsis Z.txt";
	//	file = "libros/Max Brooks - Guerra Mundial Z.txt";
	//	file = "libros/Michael Ende - La Historia Interminable.txt";
	//	file = "libros/Neil Gaiman - Stardust.txt";
	//	file = "libros/Patrick Süskind - El Perfume.txt";
	//	file = "libros/Paulo Coelho - El Alquimista.txt";
	//	file = "libros/R.A. Salvatore - 1. El Elfo Oscuro 1 - La Morada.txt";
	//	file = "libros/R.A. Salvatore - 1. El Elfo Oscuro 2 - El Exilio.txt";
	//	file = "libros/R.A. Salvatore - 1. El Elfo Oscuro 3 - El Refugio.txt";
	//	file = "libros/R.A. Salvatore - 2. El valle del viento helado 1 - La Piedra de Cristal.txt";
	//	file = "libros/R.A. Salvatore - 2. El valle del viento helado 2 - Ríos de Plata.txt";
	//	file = "libros/R.A. Salvatore - 2. El valle del viento helado 3 - La Gema del Halfling.txt";
	//	file = "libros/R.A. Salvatore - 3. El legado del drow 1 -  El Legado.txt";
	//	file = "libros/R.A. Salvatore - 3. El legado del drow 2 - Noche sin Estrellas.txt";
	//	file = "libros/R.A. Salvatore - 3. El legado del drow 3 - Cerco de Oscuridad.txt";
	//	file = "libros/R.A. Salvatore - 3. El legado del drow 4 - Luz en las Tinieblas.txt";
	//	file = "libros/R.A. Salvatore - 4. Sendas de tinieblas 1 - El estigma de Errtu.txt";
	//	file = "libros/R.A. Salvatore - 4. Sendas de tinieblas 2 - La columna del mundo.txt";
	//	file = "libros/R.A. Salvatore - 4. Sendas de tinieblas 3 - El Siervo de La Piedra.txt";
	//	file = "libros/R.A. Salvatore - 4. Sendas de tinieblas 4 - El mar de las espadas.txt";
	//	file = "libros/R.A. Salvatore - 5. Las espadas del cazador 2 - Los Senderos de la Muerte.txt";
	//	file = "libros/R.A. Salvatore - 5. Las espadas del cazador 3 - Las dos espadas.txt";
	//	file = "libros/Rick Riordan - Percy Jackson y Los Olímpicos 1 - El ladrón del rayo.txt";
	//	file = "libros/Rick Riordan - Percy Jackson y Los Olímpicos 2 - El mar de los monstruos.txt";
	//	file = "libros/Rick Riordan - Percy Jackson y Los Olímpicos 3 - La maldicion del Titan.txt";
	//	file = "libros/Rick Riordan - Percy Jackson y Los Olímpicos 4 - La batalla del laberinto.txt";
	//	file = "libros/Robert E. Howard - Conan 01 - Conan.txt";
	//	file = "libros/Robert Ludlum - El caso Bourne.txt";
	//	file = "libros/S.D. Perry - Resident Evil 0 - Hora Cero.txt";
	//	file = "libros/S.D. Perry - Resident Evil 1 - La conspiración Umbrella.txt";
	//	file = "libros/Scott Fitzgerald - El extraño caso de Benjamin Button.txt";
	//	file = "libros/Stephanie Meyer - Crepúsculo 0 - Sol de Medianoche.txt";
	//	file = "libros/Stephanie Meyer - Crepúsculo 1 - Crepúsculo.txt";
	//	file = "libros/Stephanie Meyer - Crepúsculo 2 - Luna Nueva.txt";
	//	file = "libros/Stephanie Meyer - Crepúsculo 3 - Eclipse.txt";
	//	file = "libros/Stephanie Meyer - Crepúsculo 4 - Amanecer.txt";
	//	file = "libros/Stephen King - Cell.txt";
	//	file = "libros/Stephen King - Historias fantásticas.txt";
	//	file = "libros/Stephen King - La Expedición.txt";
	//	file = "libros/Stephen King - La torre Oscura I.txt";
	//	file = "libros/Stephen King - The Dead Zone.txt";
	//	file = "libros/Umberto Eco - El Nombre de la Rosa.txt";
	//	file = "pruebas/test_gnl.txt";

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error al abrir el archivo");
		return (1);
	}
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