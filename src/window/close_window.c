/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:05:25 by jowagner          #+#    #+#             */
/*   Updated: 2025/04/19 17:36:31 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	close_window_image(t_so_long *so_long)
{
	mlx_destroy_image(so_long->mlx_v.mlx, so_long->game.wall_s_01.ptr);
	mlx_destroy_image(so_long->mlx_v.mlx, so_long->game.grass_s_01.ptr);
	mlx_destroy_image(so_long->mlx_v.mlx, so_long->game.enemy_s_01.ptr);
	mlx_destroy_image(so_long->mlx_v.mlx, so_long->game.enemy_s_02.ptr);
	mlx_destroy_image(so_long->mlx_v.mlx, so_long->game.enemy_s_03.ptr);
	mlx_destroy_image(so_long->mlx_v.mlx, so_long->game.p_bot_s_01.ptr);
	mlx_destroy_image(so_long->mlx_v.mlx, so_long->game.p_bot_l_02.ptr);
	mlx_destroy_image(so_long->mlx_v.mlx, so_long->game.p_bot_r_03.ptr);
	mlx_destroy_image(so_long->mlx_v.mlx, so_long->game.p_top_s_01.ptr);
	mlx_destroy_image(so_long->mlx_v.mlx, so_long->game.p_top_l_02.ptr);
	mlx_destroy_image(so_long->mlx_v.mlx, so_long->game.p_top_r_03.ptr);
	mlx_destroy_image(so_long->mlx_v.mlx, so_long->game.p_left_s_01.ptr);
	mlx_destroy_image(so_long->mlx_v.mlx, so_long->game.p_left_l_02.ptr);
	mlx_destroy_image(so_long->mlx_v.mlx, so_long->game.p_left_r_03.ptr);
	mlx_destroy_image(so_long->mlx_v.mlx, so_long->game.p_right_s_01.ptr);
	mlx_destroy_image(so_long->mlx_v.mlx, so_long->game.p_right_l_02.ptr);
	mlx_destroy_image(so_long->mlx_v.mlx, so_long->game.p_right_r_03.ptr);
	mlx_destroy_image(so_long->mlx_v.mlx, so_long->game.exit_s_01.ptr);
	mlx_destroy_image(so_long->mlx_v.mlx, so_long->game.collec_s_01.ptr);
	mlx_destroy_image(so_long->mlx_v.mlx, so_long->game.collec_s_02.ptr);
	mlx_destroy_image(so_long->mlx_v.mlx, so_long->game.collec_s_03.ptr);
	return (0);
}

int	close_window(t_so_long *so_long)
{
	close_window_image(so_long);
	mlx_destroy_window(so_long->mlx_v.mlx, so_long->mlx_v.win);
	mlx_destroy_display(so_long->mlx_v.mlx);
	free(so_long->mlx_v.mlx);
	free_map(so_long->data.map, false);
	exit(0);
	return (0);
}
