/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:05:45 by jowagner          #+#    #+#             */
/*   Updated: 2025/04/17 21:18:19 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	initialization(char *filename, t_so_long *so_long)
{
	int	count_line;
	int	fd;

	if (check_file_extension(filename, ".ber") == false)
	{
		ft_putstr_fd("Error.\nFile does not exist or if it does, \
the extension map must be .ber.\n", 2);
		exit(1);
	}
	fd = open_file(filename);
	count_line = pre_read(fd);
	so_long->data.map = map_init(count_line, filename);
	if (!so_long->data.map)
	{
		ft_putstr_fd("Error.\nIn initializing map.\n", 2);
		free_map(so_long->data.map, false);
	}
	init_player_position(so_long);
	count_map_elements(so_long);
	remove_newline(so_long->data);
	flood_fill_after_parsing(so_long);
	window_size(&so_long->data);
	return (0);
}
