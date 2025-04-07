/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_tiles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:43:17 by jowagner          #+#    #+#             */
/*   Updated: 2025/04/07 17:33:29 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_tiles_env(t_so_long *so_long)
{
	int	y;
	int	x;

	y = 0;
	while (so_long->data.map[y])
	{
		x = 0;
		while (so_long->data.map[y][x])
		{
			if (so_long->data.map[y][x] == '1')
				mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
					so_long->game.wall_s_01.ptr, x * SIZE_S, y * SIZE_S);
			else if (so_long->data.map[y][x] == '0')
				mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
					so_long->game.grass_s_01.ptr, x * SIZE_S, y * SIZE_S);
			else if (so_long->data.map[y][x] == 'E')
			{
				mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
					so_long->game.grass_s_01.ptr, x * SIZE_S, y * SIZE_S);
				if (so_long->map_r.nbr_items == so_long->map_r.nbr_collectible)
					mlx_put_image_to_window(so_long->mlx_v.mlx,
						so_long->mlx_v.win, so_long->game.exit_s_01.ptr, x
						* SIZE_S, y * SIZE_S);
			}
			x++;
		}
		y++;
	}
}

void	put_tiles(t_so_long *so_long)
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
				mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
					so_long->game.p_bot_s_01.ptr, x * SIZE_S, y * SIZE_S);
			else if (so_long->data.map[y][x] == 'X')
				mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
					so_long->game.enemy_s_01.ptr, x * SIZE_S, y * SIZE_S);
			else if (so_long->data.map[y][x] == 'C')
				mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
					so_long->game.collectible_s_03.ptr, x * SIZE_S, y * SIZE_S);
			else if (so_long->data.map[y][x] == 'c')
				mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
					so_long->game.collectible_s_02.ptr, x * SIZE_S, y * SIZE_S);
			x++;
		}
		y++;
	}
}
