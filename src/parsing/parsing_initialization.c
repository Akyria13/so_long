/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_initialization.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:03:41 by jowagner          #+#    #+#             */
/*   Updated: 2025/04/13 16:11:26 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parsing_initialization(t_so_long *so_long)
{
	if (!is_map_empty(so_long->data))
	{
		ft_putstr_fd("Error.\nMap is empty or invalid characters (tab).\n", 2);
		free_map(so_long->data.map, true);
	}
	if (!is_map_have_wall(so_long->data))
	{
		ft_putstr_fd("Error.\nMap have an issue with walls.\n", 2);
		free_map(so_long->data.map, true);
	}
	if (!is_map_rectangular(so_long->data))
	{
		ft_putstr_fd("Error.\nMap is not rectangular.\n", 2);
		free_map(so_long->data.map, true);
	}
	if (!is_map_valid_format(so_long))
	{
		ft_putstr_fd("Map is in invalid format (check your map character).\n\
Only '0', '1', 'P', 'E', 'C', 'c', 'M', 'X' are allowed.\n", 2);
		free_map(so_long->data.map, true);
	}
	if (is_map_too_high(so_long->data))
		free_map(so_long->data.map, true);
}

void	flood_fill_after_parsing(t_so_long *so_long)
{
	parsing_initialization(so_long);
	if (!is_map_solvable(so_long))
	{
		ft_putstr_fd("Error.\nMap is not solvable.\n", 2);
		free_map(so_long->data.map, true);
	}
}
