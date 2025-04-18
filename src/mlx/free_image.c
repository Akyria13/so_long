/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 19:46:53 by jowagner          #+#    #+#             */
/*   Updated: 2025/04/18 19:25:34 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_image_player(t_so_long *so_long)
{
	if (so_long->game.p_left_s_01.ptr)
		mlx_destroy_image(so_long->mlx_v.mlx, so_long->game.p_left_s_01.ptr);
	if (so_long->game.p_left_l_02.ptr)
		mlx_destroy_image(so_long->mlx_v.mlx, so_long->game.p_left_l_02.ptr);
	if (so_long->game.p_left_r_03.ptr)
		mlx_destroy_image(so_long->mlx_v.mlx, so_long->game.p_left_r_03.ptr);
	if (so_long->game.p_right_s_01.ptr)
		mlx_destroy_image(so_long->mlx_v.mlx, so_long->game.p_right_s_01.ptr);
	if (so_long->game.p_right_l_02.ptr)
		mlx_destroy_image(so_long->mlx_v.mlx, so_long->game.p_right_l_02.ptr);
	if (so_long->game.p_right_r_03.ptr)
		mlx_destroy_image(so_long->mlx_v.mlx, so_long->game.p_right_r_03.ptr);
	if (so_long->game.p_bot_s_01.ptr)
		mlx_destroy_image(so_long->mlx_v.mlx, so_long->game.p_bot_s_01.ptr);
	if (so_long->game.p_bot_l_02.ptr)
		mlx_destroy_image(so_long->mlx_v.mlx, so_long->game.p_bot_l_02.ptr);
	if (so_long->game.p_bot_r_03.ptr)
		mlx_destroy_image(so_long->mlx_v.mlx, so_long->game.p_bot_r_03.ptr);
	if (so_long->game.p_top_s_01.ptr)
		mlx_destroy_image(so_long->mlx_v.mlx, so_long->game.p_top_s_01.ptr);
	if (so_long->game.p_top_l_02.ptr)
		mlx_destroy_image(so_long->mlx_v.mlx, so_long->game.p_top_l_02.ptr);
	if (so_long->game.p_top_r_03.ptr)
		mlx_destroy_image(so_long->mlx_v.mlx, so_long->game.p_top_r_03.ptr);
}

void	destroy_image_env(t_so_long *so_long)
{
	if (so_long->game.wall_s_01.ptr)
		mlx_destroy_image(so_long->mlx_v.mlx, so_long->game.wall_s_01.ptr);
	if (so_long->game.grass_s_01.ptr)
		mlx_destroy_image(so_long->mlx_v.mlx, so_long->game.grass_s_01.ptr);
	if (so_long->game.enemy_s_01.ptr)
		mlx_destroy_image(so_long->mlx_v.mlx, so_long->game.enemy_s_01.ptr);
	if (so_long->game.enemy_s_02.ptr)
		mlx_destroy_image(so_long->mlx_v.mlx, so_long->game.enemy_s_02.ptr);
	if (so_long->game.enemy_s_03.ptr)
		mlx_destroy_image(so_long->mlx_v.mlx, so_long->game.enemy_s_03.ptr);
	if (so_long->game.exit_s_01.ptr)
		mlx_destroy_image(so_long->mlx_v.mlx, so_long->game.exit_s_01.ptr);
	if (so_long->game.collec_s_01.ptr)
		mlx_destroy_image(so_long->mlx_v.mlx, so_long->game.collec_s_01.ptr);
	if (so_long->game.collec_s_02.ptr)
		mlx_destroy_image(so_long->mlx_v.mlx, so_long->game.collec_s_02.ptr);
	if (so_long->game.collec_s_03.ptr)
		mlx_destroy_image(so_long->mlx_v.mlx, so_long->game.collec_s_03.ptr);
}

void	free_image(t_so_long *so_long)
{
	destroy_image_player(so_long);
	destroy_image_env(so_long);
	mlx_destroy_window(so_long->mlx_v.mlx, so_long->mlx_v.win);
	mlx_destroy_display(so_long->mlx_v.mlx);
	free(so_long->mlx_v.mlx);
	free(so_long->map_file);
	free_map(so_long->data.map, true);
}
