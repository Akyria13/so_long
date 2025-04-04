/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_so_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:09:08 by jowagner          #+#    #+#             */
/*   Updated: 2025/04/04 21:22:03 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_so_long(t_so_long *so_long)
{
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
	// draw_map(so_long);
	so_long->map_r.player_on_exit = false;
	init_player_position(so_long);
	count_map_elements(so_long);
	put_tiles_env(so_long);
	put_tiles(so_long);
	mlx_key_hook(so_long->mlx_v.win, key_hook, so_long);
	// Hook to handle.
	mlx_hook(so_long->mlx_v.win, DestroyNotify, StructureNotifyMask,
		close_window, so_long);
	mlx_loop(so_long->mlx_v.mlx);
	free_map(so_long->data.map);
	return (0);
}
