/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_so_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:09:08 by jowagner          #+#    #+#             */
/*   Updated: 2025/04/19 17:36:33 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_mlx(t_so_long *so_long)
{
	so_long->mlx_v.mlx = mlx_init();
	if (!so_long->mlx_v.mlx)
	{
		ft_putstr_fd("Error.\nSomething wrong with mlx init.\n", 2);
		free_map(so_long->data.map, true);
	}
	so_long->mlx_v.win = mlx_new_window(so_long->mlx_v.mlx,
			so_long->data.width_map * SIZE_S, so_long->data.height_map * SIZE_S,
			"Poke_Long");
	if (!so_long->mlx_v.win)
	{
		ft_putstr_fd("Error.\nSomething wrong with mlx window.\n", 2);
		mlx_destroy_display(so_long->mlx_v.mlx);
		free(so_long->mlx_v.mlx);
		free_map(so_long->data.map, true);
	}
}

static void	init_sprite(t_so_long *so_long)
{
	sprite_init_env(so_long);
	sprite_init_enemy(so_long);
	sprite_init_player_top_and_bot(so_long);
	sprite_init_player_left_and_right(so_long);
	sprite_init_exit_and_collectibles(so_long);
}

int	init_so_long(t_so_long *so_long)
{
	init_mlx(so_long);
	init_sprite(so_long);
	so_long->map_r.player_on_exit = false;
	put_tiles_env(so_long);
	put_tiles(so_long);
	mlx_loop_hook(so_long->mlx_v.mlx, animation_loop, so_long);
	mlx_key_hook(so_long->mlx_v.win, key_hook, so_long);
	mlx_hook(so_long->mlx_v.win, DestroyNotify, StructureNotifyMask,
		close_window, so_long);
	mlx_loop(so_long->mlx_v.mlx);
	return (0);
}
