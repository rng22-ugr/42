/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalizio <jgalizio@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:34:58 by jgalizio          #+#    #+#             */
/*   Updated: 2025/03/11 15:47:13 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h> // para open
#include "get_next_line.h"
#include <unistd.h> // para close
#include <stdlib.h> // para free
#include <stdio.h> // para printf
#include "./../Libft/libft.h"	// poner la ruta correcta a la libft
/* #include "get_next_line_bonus.h" // o la ruta relativa al proyecto ("../gnl/get_next_l..."), se entinde jajaj */

void crear_archivo_de_prueba(char *txt, char *contenido)
{
	if (!contenido || !*contenido)
		return;
	int fd = open(txt, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0) {
		return;
	}
	write(fd, contenido, ft_strlen(contenido));
	close(fd);
}
char *tomar_args(int ac, char **av)
{
	int i = 1;
    char *contenido = ft_strdup("");
    char *aux;

    if (!av || !*av)
        return ft_strdup("No args!\n");

    while (i < ac) {
        aux = contenido;
        contenido = ft_strjoin(contenido, *av++);
        free(aux);
        aux = contenido;
        contenido = ft_strjoin(contenido, "\n");
        free(aux);
		i++;
    }
    return contenido;
}

int main(int ac, char **av)
{
	char *args = tomar_args(ac, av);
	crear_archivo_de_prueba("nums.txt", "01\n02\n03\n04\n05\n06\n07\n08\n09\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n");
	crear_archivo_de_prueba("abc.txt", "abcde\nABCDE\nfghij\nFGHIJ\nklmno\nKLMNO\npqrst\nPQRST\nuvwxy\nUVWXY\nz\nZ\n");
	crear_archivo_de_prueba("diario.txt",
			"Primero me levanté medio dormido y me mandé unas tostadas con manteca.\n"
			"Después, pintó el apuro y me olvidé de tomar el jugo de naranja, un clásico.\n"
			"Al toque me puse a laburar y abrí Vim. ¡Qué locura lo bien que anda! No sé cómo vivía sin él.\n"
			"Para el mediodía, me clavé un sánguche rápido mientras chequeaba unos mails.\n"
			"Más tarde, volví a usar Vim para arreglar unos bugs. En serio, es como magia, arreglás todo en un toque.\n"
			"A la tarde me fui a dar una vuelta, porque necesitaba despejar un poco la cabeza.\n"
			"Ya a la noche, cerré el día con un poco más de código (sí, obvio, en Vim... ¡es lo más grande que hay!).\n"
			"Y bueno, al final me fui a dormir pensando en lo copado que está usar cosas que realmente te hacen la vida más fácil, como Vim.\n");
	crear_archivo_de_prueba("args.txt", args);
	free(args);
	int fd[4];
	fd[0] = open("nums.txt", O_RDONLY);
	fd[1] = open("abc.txt", O_RDONLY);
	fd[2] = open("diario.txt", O_RDONLY);
	fd[3] = open("args.txt", O_RDONLY);

	if (fd[0] < 0 || fd[1] < 0 || fd[2] < 0 || fd[3] < 0) {
		perror("Algo pasó mal!");
		return 1;
	}

	char *line[4];
	int i = 0;
	int k = 0;

	printf("\n===========================\n");
	while (1)
	{
		while (i < 4)
		{
			line[i] = get_next_line(fd[i]);
			if (line[i])
				printf("[ %d ] [ linea: %d ]\t%s", i + 1, k, line[i]);
			free(line[i]);
			i++;
		}
		printf("\n\n");
		i = 0;
		k++;
		if (!line[0] && !line[1] && !line[2] && !line[3])
			break;
	}
	printf("\n===========================\n");
	char *stdline;
	while(1)
	{
		write(1, ">>\t", 3);
		stdline = get_next_line(0);
		if (!stdline)
			break;
		if (!ft_strncmp(stdline, "EOF", 3) && stdline[3] == '\n')
			i = -1;
		printf("[ stdin ]\t%s\n", stdline);
		free(stdline);
		stdline = NULL;
		if (i < 0)
			break;
	}
	int j = 4;
	while(j--)
		close(fd[j]);
	
	line[0] = NULL;
	fd[0] = open("nums.txt", O_RDONLY);
	line[0] = get_next_line(fd[0]);
	if (line[0])
		printf("[ %d ] [ linea: %d ]\t%s", i + 1, k, line[0]);
	free(line[0]);
	line[0] = NULL;
	close(fd[0]);

	printf("\n===========================\n");
	return 0;
}
