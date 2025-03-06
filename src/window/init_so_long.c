/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_so_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:09:08 by jowagner          #+#    #+#             */
/*   Updated: 2025/03/06 18:46:52 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	key_hook(int keycode, t_data *data)
// map[2][5] Check if map[1][5] is a wall for valid input
{
	(void)data;
	if (keycode == XK_Escape)
	{
		printf(" %d, Exit ./so_long. \n", keycode);
		exit(EXIT_SUCCESS);
	}
	else
		printf(" %d, Hello from key_hook!\n", keycode);
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
			so_long->data.width_map * SPRITE_SIZE, so_long->data.height_map
			* SPRITE_SIZE, "Poke_Long");
	if (!so_long->mlx_v.win)
		return (0);
	sprite_init_lugia(so_long);
	sprite_init_env(so_long);
	i = 0;
	while (i < so_long->data.height_map)
	{
		j = 0;
		while (j < so_long->data.width_map)
		{
			if (so_long->data.map[i][j] == '1')
				mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
					so_long->game.tree_sprite_01.ptr, j * SPRITE_SIZE, i
					* SPRITE_SIZE);
			else if (so_long->data.map[i][j] == '0')
				mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
					so_long->game.grass_sprite_01.ptr, j * SPRITE_SIZE, i
					* SPRITE_SIZE);
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
