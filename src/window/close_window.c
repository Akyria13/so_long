/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:05:25 by jowagner          #+#    #+#             */
/*   Updated: 2025/03/29 20:13:54 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	close_window(t_so_long *so_long)
{
	mlx_destroy_image(so_long->mlx_v.mlx, so_long->game.wall_s_01.ptr);
	mlx_destroy_image(so_long->mlx_v.mlx, so_long->game.grass_s_01.ptr);
	mlx_destroy_window(so_long->mlx_v.mlx, so_long->mlx_v.win);
	mlx_destroy_display(so_long->mlx_v.mlx);
	free(so_long->mlx_v.mlx);
	free_map(so_long->data.map);
	exit(0);
	return (0);
}
