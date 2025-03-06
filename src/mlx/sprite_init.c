/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:32:40 by jowagner          #+#    #+#             */
/*   Updated: 2025/03/06 18:47:02 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"
#include <unistd.h>

void	sprite_init_lugia(t_so_long *so_long)
{
	so_long->game.lugia_sprite_01.ptr = mlx_xpm_file_to_image(so_long->mlx_v.mlx,
			Lugia_S_F01, &so_long->game.lugia_sprite_01.width,
			&so_long->game.lugia_sprite_01.height);
	so_long->game.lugia_sprite_02.ptr = mlx_xpm_file_to_image(so_long->mlx_v.mlx,
			Lugia_S_F02, &so_long->game.lugia_sprite_02.width,
			&so_long->game.lugia_sprite_02.height);
	so_long->game.lugia_sprite_03.ptr = mlx_xpm_file_to_image(so_long->mlx_v.mlx,
			Lugia_S_F03, &so_long->game.lugia_sprite_03.width,
			&so_long->game.lugia_sprite_03.height);
	// if (!so_long->game.lugia_sprite_01.ptr
	//	|| !so_long->game.lugia_sprite_02.ptr
	// 	|| !so_long->game.lugia_sprite_03.ptr)
	// {
	// 	ft_putstr_fd("Error.\nSomething wrong with images(#Lugia).\n", 2);
	// 	// faire ma fonction de close window ou je destroy sa maman
	// }
}

void	sprite_init_env(t_so_long *so_long)
{
	so_long->game.tree_sprite_01.ptr = mlx_xpm_file_to_image(so_long->mlx_v.mlx,
			Tree_S_F01, &so_long->game.tree_sprite_01.width,
			&so_long->game.tree_sprite_01.height);
	so_long->game.grass_sprite_01.ptr = mlx_xpm_file_to_image(so_long->mlx_v.mlx,
			Grass_S_F01, &so_long->game.tree_sprite_01.width,
			&so_long->game.grass_sprite_01.height);
	if (!so_long->game.tree_sprite_01.ptr || !so_long->game.grass_sprite_01.ptr)
	{
		ft_putstr_fd("Error.\nSomething wrong with images (#Tree).\n", 2);
		exit(1); // faire ma fonction de close window ou je destroy sa maman
	}
}

// void	sprite_init_player(t_so_long *so_long)
// {
// }
