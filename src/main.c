/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:47:07 by jowagner          #+#    #+#             */
/*   Updated: 2025/02/26 01:54:12 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include <unistd.h>

// int	main(int argc, char *argv[])

int	main(void)
{
	char	**map;
	char	*line;
	int		count_line;

	line = NULL;
	count_line = get_number_line(line);
	map = map_init(count_line);
	free_map(map);
	// char	*line;
	// int		fd;
	// int		i;
	// int		count_line;
	// // void *mlx;
	// // mlx = mlx_init();
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
}
