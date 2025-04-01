/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_initialization.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:03:41 by jowagner          #+#    #+#             */
/*   Updated: 2025/04/01 19:02:43 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parsing_initialization(t_so_long *so_long)
{
	remove_newline(so_long->data);
	if (!is_map_empty(so_long->data))
	{
		ft_putstr_fd("Error.\nMap is empty or invalid characters (tab).\n", 2);
		free_map(so_long->data.map);
		exit(1);
	}
	if (!is_map_have_wall(so_long->data))
	{
		ft_putstr_fd("Error.\nMap have an issue with walls.\n", 2);
		free_map(so_long->data.map);
		exit(1);
	}
	if (!is_map_rectangular(so_long->data))
	{
		ft_putstr_fd("Error.\nMap is not rectangular.\n", 2);
		free_map(so_long->data.map);
		exit(1);
	}
	if (!is_map_valid_format(so_long->data))
	{
		ft_putstr_fd("Error.\nMap is in invalid format (check your map character).\n",
			2);
		free_map(so_long->data.map);
		exit(1);
	}
}
