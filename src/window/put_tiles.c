/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_tiles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:43:17 by jowagner          #+#    #+#             */
/*   Updated: 2025/04/03 19:02:28 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_tiles_env(t_so_long *so_long)
{
	int	i;
	int	j;

	i = 0;
	while (i < so_long->data.height_map)
	{
		j = 0;
		while (j < so_long->data.width_map)
		{
			if (so_long->data.map[i][j] == '1')
				mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
					so_long->game.wall_s_01.ptr, j * SIZE_S, i * SIZE_S);
			else if (so_long->data.map[i][j] == '0')
				mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
					so_long->game.grass_s_01.ptr, j * SIZE_S, i * SIZE_S);
			else if (so_long->data.map[i][j] == 'E')
				mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
					so_long->game.exit_s_01.ptr, j * SIZE_S, i * SIZE_S);
			j++;
		}
		i++;
	}
}

void	put_tiles(t_so_long *so_long)
{
	int	i;
	int	j;

	i = 0;
	while (i < so_long->data.height_map)
	{
		j = 0;
		while (j < so_long->data.width_map)
		{
			if (so_long->data.map[i][j] == 'P')
				mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
					so_long->game.p_bot_s_01.ptr, j * SIZE_S, i * SIZE_S);
			else if (so_long->data.map[i][j] == 'X')
				mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
					so_long->game.enemy_s_01.ptr, j * SIZE_S, i * SIZE_S);
			else if (so_long->data.map[i][j] == 'C')
				mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
					so_long->game.collectible_s_03.ptr, j * SIZE_S, i * SIZE_S);
			else if (so_long->data.map[i][j] == 'c')
				mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
					so_long->game.collectible_s_02.ptr, j * SIZE_S, i * SIZE_S);
			j++;
		}
		i++;
	}
}
