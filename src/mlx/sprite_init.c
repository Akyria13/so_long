/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:32:40 by jowagner          #+#    #+#             */
/*   Updated: 2025/04/17 19:57:57 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sprite_init_env(t_so_long *so_long)
{
	so_long->game.wall_s_01.ptr = mlx_xpm_file_to_image(so_long->mlx_v.mlx,
			WALL_S_F01, &so_long->game.wall_s_01.width,
			&so_long->game.wall_s_01.height);
	so_long->game.grass_s_01.ptr = mlx_xpm_file_to_image(so_long->mlx_v.mlx,
			GRASS_S_F01, &so_long->game.grass_s_01.width,
			&so_long->game.grass_s_01.height);
	if (!so_long->game.wall_s_01.ptr || !so_long->game.grass_s_01.ptr)
	{
		ft_putstr_fd("Error.\nSomething wrong with images (#Environment).\n",
			2);
		free_image(so_long);
	}
}

void	sprite_init_enemy(t_so_long *so_long)
{
	so_long->game.enemy_s_01.ptr = mlx_xpm_file_to_image(so_long->mlx_v.mlx,
			ENEMY_S_F01, &so_long->game.enemy_s_01.width,
			&so_long->game.enemy_s_01.height);
	so_long->game.enemy_s_02.ptr = mlx_xpm_file_to_image(so_long->mlx_v.mlx,
			ENEMY_S_F02, &so_long->game.enemy_s_02.width,
			&so_long->game.enemy_s_02.height);
	so_long->game.enemy_s_03.ptr = mlx_xpm_file_to_image(so_long->mlx_v.mlx,
			ENEMY_S_F03, &so_long->game.enemy_s_03.width,
			&so_long->game.enemy_s_03.height);
	if (!so_long->game.enemy_s_01.ptr || !so_long->game.enemy_s_02.ptr
		|| !so_long->game.enemy_s_03.ptr)
	{
		ft_putstr_fd("Error.\nSomething wrong with images (#Enemy).\n", 2);
		free_image(so_long);
	}
}

void	sprite_init_player_top_and_bot(t_so_long *so_long)
{
	so_long->game.p_bot_s_01.ptr = mlx_xpm_file_to_image(so_long->mlx_v.mlx,
			PLAYER_S_BOT_F01, &so_long->game.p_bot_s_01.width,
			&so_long->game.p_bot_s_01.height);
	so_long->game.p_bot_l_02.ptr = mlx_xpm_file_to_image(so_long->mlx_v.mlx,
			PLAYER_S_BOT_L_F02, &so_long->game.p_bot_l_02.width,
			&so_long->game.p_bot_l_02.height);
	so_long->game.p_bot_r_03.ptr = mlx_xpm_file_to_image(so_long->mlx_v.mlx,
			PLAYER_S_BOT_R_F03, &so_long->game.p_bot_r_03.width,
			&so_long->game.p_bot_r_03.height);
	so_long->game.p_top_s_01.ptr = mlx_xpm_file_to_image(so_long->mlx_v.mlx,
			PLAYER_S_TOP_F01, &so_long->game.p_top_s_01.width,
			&so_long->game.p_top_s_01.height);
	so_long->game.p_top_l_02.ptr = mlx_xpm_file_to_image(so_long->mlx_v.mlx,
			PLAYER_S_TOP_L_F02, &so_long->game.p_top_l_02.width,
			&so_long->game.p_top_l_02.height);
	so_long->game.p_top_r_03.ptr = mlx_xpm_file_to_image(so_long->mlx_v.mlx,
			PLAYER_S_TOP_R_F03, &so_long->game.p_top_r_03.width,
			&so_long->game.p_top_r_03.height);
	if (!so_long->game.p_bot_s_01.ptr || !so_long->game.p_bot_l_02.ptr
		|| !so_long->game.p_bot_r_03.ptr || !so_long->game.p_top_s_01.ptr
		|| !so_long->game.p_top_l_02.ptr || !so_long->game.p_top_r_03.ptr)
	{
		ft_putstr_fd("Error.\nSomething wrong with images (#Player T&B).\n", 2);
		free_image(so_long);
	}
}

void	sprite_init_player_left_and_right(t_so_long *so_long)
{
	so_long->game.p_left_s_01.ptr = mlx_xpm_file_to_image(so_long->mlx_v.mlx,
			PLAYER_S_LEFT_F01, &so_long->game.p_left_s_01.width,
			&so_long->game.p_left_s_01.height);
	so_long->game.p_left_l_02.ptr = mlx_xpm_file_to_image(so_long->mlx_v.mlx,
			PLAYER_S_LEFT_L_F02, &so_long->game.p_left_l_02.width,
			&so_long->game.p_left_l_02.height);
	so_long->game.p_left_r_03.ptr = mlx_xpm_file_to_image(so_long->mlx_v.mlx,
			PLAYER_S_LEFT_R_F03, &so_long->game.p_left_r_03.width,
			&so_long->game.p_left_r_03.height);
	so_long->game.p_right_s_01.ptr = mlx_xpm_file_to_image(so_long->mlx_v.mlx,
			PLAYER_S_RIGHT_F01, &so_long->game.p_right_s_01.width,
			&so_long->game.p_right_s_01.height);
	so_long->game.p_right_l_02.ptr = mlx_xpm_file_to_image(so_long->mlx_v.mlx,
			PLAYER_S_RIGHT_L_F02, &so_long->game.p_right_l_02.width,
			&so_long->game.p_right_l_02.height);
	so_long->game.p_right_r_03.ptr = mlx_xpm_file_to_image(so_long->mlx_v.mlx,
			PLAYER_S_RIGHT_R_F03, &so_long->game.p_right_r_03.width,
			&so_long->game.p_right_r_03.height);
	if (!so_long->game.p_left_s_01.ptr || !so_long->game.p_left_l_02.ptr
		|| !so_long->game.p_left_r_03.ptr || !so_long->game.p_right_s_01.ptr
		|| !so_long->game.p_right_l_02.ptr || !so_long->game.p_right_r_03.ptr)
	{
		ft_putstr_fd("Error.\nSomething wrong with images (#Player L&R).\n", 2);
		free_image(so_long);
	}
}

void	sprite_init_exit_and_collectibles(t_so_long *so_long)
{
	so_long->game.exit_s_01.ptr = mlx_xpm_file_to_image(so_long->mlx_v.mlx,
			EXIT_S_01, &so_long->game.exit_s_01.width,
			&so_long->game.exit_s_01.height);
	so_long->game.collec_s_01.ptr = mlx_xpm_file_to_image(so_long->mlx_v.mlx,
			COLLECTIBLE_S_F01, &so_long->game.collec_s_01.width,
			&so_long->game.collec_s_01.height);
	so_long->game.collec_s_02.ptr = mlx_xpm_file_to_image(so_long->mlx_v.mlx,
			COLLECTIBLE_S_F02, &so_long->game.collec_s_02.width,
			&so_long->game.collec_s_02.height);
	so_long->game.collec_s_03.ptr = mlx_xpm_file_to_image(so_long->mlx_v.mlx,
			COLLECTIBLE_S_F03, &so_long->game.collec_s_03.width,
			&so_long->game.collec_s_03.height);
	if (!so_long->game.exit_s_01.ptr || !so_long->game.collec_s_01.ptr
		|| !so_long->game.collec_s_02.ptr || !so_long->game.collec_s_03.ptr)
	{
		ft_putstr_fd("Error.\nSomething wrong with images \
(#Exit or collectibles).\n", 2);
		free_image(so_long);
	}
}
