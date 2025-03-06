/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:53:13 by jowagner          #+#    #+#             */
/*   Updated: 2025/03/05 15:13:14 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

char	**map_init(int count_line, char *filename)
{
	char	**map;
	int		i;
	int		fd;

	fd = open_file(filename);
	map = malloc(sizeof(char *) * (count_line + 1));
	if (map == NULL)
		return (NULL);
	map[count_line] = NULL;
	i = 0;
	while (i < count_line)
		map[i++] = get_next_line(fd);
	close_file(fd);
	return (map);
}
