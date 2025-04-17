/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_tiles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:43:17 by jowagner          #+#    #+#             */
/*   Updated: 2025/04/17 20:08:11 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_tiles_env(t_so_long *so_long)
{
	int		y;
	int		x;
	char	tile;

	y = 0;
	while (y < so_long->data.height_map)
	{
		x = 0;
		while (x < so_long->data.width_map)
		{
			tile = so_long->data.map[y][x];
			if (tile == '1' || tile == '0')
				render_wall_and_grass(so_long, x, y, tile);
			else if (tile == 'E')
				render_exit(so_long, x, y);
			else
				mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
					so_long->game.wall_s_01.ptr, x * SIZE_S, y * SIZE_S);
			x++;
		}
		y++;
	}
}

void	put_tiles(t_so_long *so_long)
{
	int		y;
	int		x;
	char	tile;

	y = 0;
	while (y < so_long->data.height_map)
	{
		x = 0;
		while (x < so_long->data.width_map)
		{
			tile = so_long->data.map[y][x];
			if (tile == 'P')
				render_player(so_long, x, y);
			else if (tile == 'X')
				render_enemy(so_long, x, y);
			else if (tile == 'C' || tile == 'c' || tile == 'M')
				render_collectibles(so_long, x, y, tile);
			x++;
		}
		y++;
	}
}
