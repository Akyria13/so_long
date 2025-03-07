/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_so_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:09:08 by jowagner          #+#    #+#             */
/*   Updated: 2025/03/07 19:28:54 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	key_hook(int keycode, t_data *data)
// map[2][5] Check if map[1][5] is a wall for valid input
{
	(void)data;
	if (keycode == XK_Escape)
	{
		printf(" %d - Exit ./so_long. \n", keycode);
		exit(EXIT_SUCCESS);
	}
	else
		printf(" %d - Key_hook!\n", keycode);
	return (0);
}

int	destroy_mlx(void)
{
	printf("Exit ./so_long X. \n");
	exit(1);
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
	sprite_init_player(so_long);
	sprite_init_lugia(so_long);
	sprite_init_fire(so_long);
	i = 0;
	while (i < so_long->data.height_map)
	{
		j = 0;
		while (j < so_long->data.width_map)
		{
			if (so_long->data.map[i][j] == '1')
				mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
					so_long->game.tree_s_02.ptr, j * SIZE_S, i * SIZE_S);
			else if (so_long->data.map[i][j] == '0')
				mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
					so_long->game.grass_s_01.ptr, j * SIZE_S, i * SIZE_S);
			else if (so_long->data.map[i][j] == 'C')
				mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
					so_long->game.pokeball_s_01.ptr, j * SIZE_S, i * SIZE_S);
			else if (so_long->data.map[i][j] == 'P')
				mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
					so_long->game.player_bot_s_01.ptr, j * SIZE_S, i * SIZE_S);
			else if (so_long->data.map[i][j] == 'E')
				mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
					so_long->game.lugia_s_01.ptr, j * SIZE_S, i * SIZE_S);
			else if (so_long->data.map[i][j] == 'X')
				mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
					so_long->game.fire_s_01.ptr, j * SIZE_S, i * SIZE_S);
			j++;
		}
		i++;
	}
	mlx_key_hook(so_long->mlx_v.win, key_hook, NULL); // Hook to handle
	mlx_hook(so_long->mlx_v.win, DestroyNotify, 1L << 0, destroy_mlx, NULL);
	mlx_loop(so_long->mlx_v.mlx);
	free_map(so_long->data.map);
	// put_tiles();
	return (0);
}
