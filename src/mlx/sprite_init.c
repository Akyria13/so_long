/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:32:40 by jowagner          #+#    #+#             */
/*   Updated: 2025/03/07 19:39:25 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	sprite_init_env(t_so_long *so_long)
{
	so_long->game.tree_s_01.ptr = mlx_xpm_file_to_image(so_long->mlx_v.mlx,
			Tree_S_F01, &so_long->game.tree_s_01.width,
			&so_long->game.tree_s_01.height);
	so_long->game.tree_s_02.ptr = mlx_xpm_file_to_image(so_long->mlx_v.mlx,
			Tree_S_F02, &so_long->game.tree_s_02.width,
			&so_long->game.tree_s_02.height);
	so_long->game.grass_s_01.ptr = mlx_xpm_file_to_image(so_long->mlx_v.mlx,
			Grass_S_F01, &so_long->game.grass_s_01.width,
			&so_long->game.grass_s_01.height);
	so_long->game.pokeball_s_01.ptr = mlx_xpm_file_to_image(so_long->mlx_v.mlx,
			Pokeball_S_F01, &so_long->game.pokeball_s_01.width,
			&so_long->game.pokeball_s_01.height);
	if (!so_long->game.tree_s_01.ptr || !so_long->game.tree_s_02.ptr
		|| !so_long->game.grass_s_01.ptr || !so_long->game.pokeball_s_01.ptr)
	{
		ft_putstr_fd("Error.\nSomething wrong with images (#Environment).\n",
			2);
		exit(1);
		// Faire ma fonction de close_window où je destroy la mlx, etc...
	}
}

void	sprite_init_player(t_so_long *so_long)
{
	so_long->game.player_bot_s_01.ptr = mlx_xpm_file_to_image(so_long->mlx_v.mlx,
			Player_S_Bot_F01, &so_long->game.player_bot_s_01.width,
			&so_long->game.player_bot_s_01.height);
	so_long->game.player_bot_l_02.ptr = mlx_xpm_file_to_image(so_long->mlx_v.mlx,
			Player_S_Bot_L_F02, &so_long->game.player_bot_l_02.width,
			&so_long->game.player_bot_l_02.height);
	so_long->game.player_bot_r_03.ptr = mlx_xpm_file_to_image(so_long->mlx_v.mlx,
			Player_S_Bot_R_F03, &so_long->game.player_bot_r_03.width,
			&so_long->game.player_bot_r_03.height);
	if (!so_long->game.player_bot_s_01.ptr || !so_long->game.player_bot_l_02.ptr
		|| !so_long->game.player_bot_r_03.ptr)
	{
		ft_putstr_fd("Error.\nSomething wrong with images (#Player).\n", 2);
		exit(1);
		// Faire ma fonction de close_window où je destroy la mlx, etc...
	}
}

void	sprite_init_lugia(t_so_long *so_long)
{
	so_long->game.lugia_s_01.ptr = mlx_xpm_file_to_image(so_long->mlx_v.mlx,
			Lugia_S_F01, &so_long->game.lugia_s_01.width,
			&so_long->game.lugia_s_01.height);
	so_long->game.lugia_s_02.ptr = mlx_xpm_file_to_image(so_long->mlx_v.mlx,
			Lugia_S_F02, &so_long->game.lugia_s_02.width,
			&so_long->game.lugia_s_02.height);
	so_long->game.lugia_s_03.ptr = mlx_xpm_file_to_image(so_long->mlx_v.mlx,
			Lugia_S_F03, &so_long->game.lugia_s_03.width,
			&so_long->game.lugia_s_03.height);
	if (!so_long->game.lugia_s_01.ptr || !so_long->game.lugia_s_02.ptr
		|| !so_long->game.lugia_s_03.ptr)
	{
		ft_putstr_fd("Error.\nSomething wrong with images(#Lugia).\n", 2);
		exit(1);
		// Faire ma fonction de close_window où je destroy la mlx, etc...
	}
}

void	sprite_init_fire(t_so_long *so_long)
{
	so_long->game.fire_s_01.ptr = mlx_xpm_file_to_image(so_long->mlx_v.mlx,
			Fire_S_01, &so_long->game.fire_s_01.width,
			&so_long->game.fire_s_01.height);
	so_long->game.fire_s_02.ptr = mlx_xpm_file_to_image(so_long->mlx_v.mlx,
			Fire_S_02, &so_long->game.fire_s_02.width,
			&so_long->game.fire_s_02.height);
	so_long->game.fire_s_03.ptr = mlx_xpm_file_to_image(so_long->mlx_v.mlx,
			Fire_S_03, &so_long->game.fire_s_03.width,
			&so_long->game.fire_s_03.height);
	if (!so_long->game.fire_s_01.ptr || !so_long->game.fire_s_02.ptr
		|| !so_long->game.fire_s_03.ptr)
	{
		ft_putstr_fd("Error.\nSomething wrong with images(#Fire).\n", 2);
		exit(1);
		// Faire ma fonction de close_window où je destroy la mlx, etc...
	}
}
