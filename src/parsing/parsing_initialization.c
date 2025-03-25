/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_initialization.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:03:41 by jowagner          #+#    #+#             */
/*   Updated: 2025/03/25 18:42:35 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	parsing_initialization(t_data *data)
{
	remove_newline(*data);
	if (!is_map_empty(*data))
	{
		ft_putstr_fd("Error.\nMap is empty or invalid characters (tab).\n", 2);
		exit(1); // Ma fonction de close_window où je destroy la mlx, etc...
	}
	if (!is_map_valid_format(*data))
	{
		ft_putstr_fd("Error.\nMap is in invalid format (there is space in your map ?).\n",
			2);
		exit(1); // Ma fonction de close_window où je destroy la mlx, etc...
	}
	if (!is_map_rectangular(*data))
	{
		ft_putstr_fd("Error.\nMap is not rectangular.\n", 2);
		exit(1); // Ma fonction de close_window où je destroy la mlx, etc...
	}
}
