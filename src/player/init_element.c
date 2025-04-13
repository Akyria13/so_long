/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:33:30 by jowagner          #+#    #+#             */
/*   Updated: 2025/04/13 15:59:53 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_player_position(t_so_long *so_long)
{
	int	y;
	int	x;

	y = 0;
	while (so_long->data.map[y])
	{
		x = 0;
		while (so_long->data.map[y][x])
		{
			if (so_long->data.map[y][x] == 'P')
			{
				so_long->player.coords.x = x;
				so_long->player.coords.y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	count_map_elements(t_so_long *so_long)
{
	int	y;
	int	x;

	y = 0;
	so_long->map_r.nbr_collectible = 0;
	so_long->map_r.nbr_items = 0;
	while (so_long->data.map[y])
	{
		x = 0;
		while (so_long->data.map[y][x])
		{
			if (so_long->data.map[y][x] == 'C' || so_long->data.map[y][x] == 'c'
				|| so_long->data.map[y][x] == 'M')
				so_long->map_r.nbr_collectible++;
			x++;
		}
		y++;
	}
}
