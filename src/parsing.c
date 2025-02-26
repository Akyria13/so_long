/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 00:08:13 by jowagner          #+#    #+#             */
/*   Updated: 2025/02/26 01:52:07 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include <stdio.h>
#include <string.h>

// void	exit_function(char *string )
// {
// 	perror(string);
// 	free_map(map);
// 	exit();
// }

int	get_number_line(char *line)
{
	int	count_line;
	int	fd;

	fd = open("map/map01.ber", O_RDONLY);
	// if (fd == -1)
	// 	exit_function();
	count_line = 0;
	line = "";
	while (line != NULL)
	{
		count_line++;
		line = get_next_line(fd);
		free(line);
	}
	close(fd);
	return (count_line);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		free(map[i++]);
	free(map);
}

char	**map_init(int count_line)
{
	int		i;
	int		fd;
	char	**map;

	i = 0;
	fd = open("map/map01.ber", O_RDONLY);
	map = malloc(sizeof(char *) * (count_line + 1));
	if (map == NULL)
		return (NULL);
	map[count_line] = NULL;
	i = 0;
	while (i < count_line)
		map[i++] = get_next_line(fd);
	close(fd);
	return (map);
}

// char	*line;
// int		fd;
// int		i;
// int		count_line;
// void *mlx;
// mlx = mlx_init();
// fd = open("map/map01.ber", O_RDONLY);
// count_line = 0;
// line = "";
// while (line != NULL)
// {
// 	count_line++;
// 	line = get_next_line(fd);
// 	free(line);
// }
// close(fd);
// fd = open("map/map01.ber", O_RDONLY);
// map = malloc(sizeof(char *) * (count_line + 1));
// if (map == NULL)
// 	return (1);
// map[count_line] = NULL;
// i = 0;
// while (i < count_line)
// 	map[i++] = get_next_line(fd);
// close(fd);
// free_map(map);
// return (0);
