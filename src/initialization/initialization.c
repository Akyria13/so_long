/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:05:45 by jowagner          #+#    #+#             */
/*   Updated: 2025/03/24 16:05:55 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	initialization(char *filename, t_data *data)
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
	data->map = map_init(count_line, filename);
	if (!data->map)
		ft_putstr_fd("Error initializing map.\n", 2);
	window_size(data);
	parsing_initialization(data);
}
