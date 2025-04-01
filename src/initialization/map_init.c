/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:53:13 by jowagner          #+#    #+#             */
/*   Updated: 2025/04/01 19:02:15 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_init(int count_line, char *filename)
{
	t_data	data;
	int		i;
	int		fd;

	fd = open_file(filename);
	data.map = malloc(sizeof(char *) * (count_line + 1));
	if (data.map == NULL)
		return (NULL);
	data.map[count_line] = NULL;
	i = 0;
	while (i < count_line)
		data.map[i++] = get_next_line(fd);
	get_next_line(fd);
	close_file(fd);
	return (data.map);
}
