/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:05:45 by jowagner          #+#    #+#             */
/*   Updated: 2025/04/01 19:02:12 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialization(char *filename, t_so_long *so_long)
{
	int	count_line;
	int	fd;

	if (check_file_extension(filename, ".ber") == false)
	{
		ft_putstr_fd("Error.\nThe extension map must be .ber\n", 2);
		exit(1);
	}
	fd = open_file(filename);
	count_line = pre_read(fd);
	so_long->data.map = map_init(count_line, filename);
	if (!so_long->data.map)
		ft_putstr_fd("Error initializing map.\n", 2);
	window_size(&so_long->data);
	parsing_initialization(so_long);
}
