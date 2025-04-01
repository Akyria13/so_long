/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_so_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:09:08 by jowagner          #+#    #+#             */
/*   Updated: 2025/04/01 18:38:26 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_so_long *so_long)
// map[2][5] Check if map[1][5] is a wall for valid input
{
	(void)so_long->data;
	if (keycode == XK_Escape)
	{
		printf(" %d - Exit ./so_long. \n", keycode);
		close_window(so_long);
	}
	else
		printf(" %d - Key_hook !\n", keycode);
	return (0);
}

int	init_so_long(t_so_long *so_long)
{
	int	i;
	int	j;

	so_long->mlx_v.mlx = mlx_init();
	if (!so_long->mlx_v.mlx)
		return (0);
	so_long->mlx_v.win = mlx_new_window(so_long->mlx_v.mlx,
			so_long->data.width_map * SIZE_S, so_long->data.height_map * SIZE_S,
			"Poke_Long");
	if (!so_long->mlx_v.win)
		return (0);
	sprite_init_env(so_long);
	sprite_init_player_top_and_bot(so_long);
	sprite_init_player_left_and_right(so_long);
	sprite_init_enemy(so_long);
	sprite_init_exit_and_collectibles(so_long);
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
			else if (so_long->data.map[i][j] == 'C')
				mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
					so_long->game.collectible_s_03.ptr, j * SIZE_S, i * SIZE_S);
			else if (so_long->data.map[i][j] == 'c')
				mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
					so_long->game.collectible_s_02.ptr, j * SIZE_S, i * SIZE_S);
			else if (so_long->data.map[i][j] == 'P')
				mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
					so_long->game.p_bot_s_01.ptr, j * SIZE_S, i * SIZE_S);
			else if (so_long->data.map[i][j] == 'E')
				mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
					so_long->game.exit_s_01.ptr, j * SIZE_S, i * SIZE_S);
			else if (so_long->data.map[i][j] == 'X')
				mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
					so_long->game.enemy_s_01.ptr, j * SIZE_S, i * SIZE_S);
			j++;
		}
		i++;
	}
	// put_tiles();
	mlx_key_hook(so_long->mlx_v.win, key_hook, so_long); // Hook to handle
	mlx_hook(so_long->mlx_v.win, DestroyNotify, StructureNotifyMask,
		close_window, so_long);
	mlx_loop(so_long->mlx_v.mlx);
	free_map(so_long->data.map);
	return (0);
}
