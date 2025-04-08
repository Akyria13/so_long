/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:06:42 by jowagner          #+#    #+#             */
/*   Updated: 2025/04/08 16:43:20 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_wall_and_grass(t_so_long *so_long, int x, int y, char tile)
{
	if (tile == '1')
		mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
			so_long->game.wall_s_01.ptr, x * SIZE_S, y * SIZE_S);
	else if (tile == '0')
		mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
			so_long->game.grass_s_01.ptr, x * SIZE_S, y * SIZE_S);
}

void	render_exit(t_so_long *so_long, int x, int y)
{
	mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
		so_long->game.grass_s_01.ptr, x * SIZE_S, y * SIZE_S);
	if (so_long->map_r.nbr_items == so_long->map_r.nbr_collectible)
		mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
			so_long->game.exit_s_01.ptr, x * SIZE_S, y * SIZE_S);
}

void	render_enemy(t_so_long *so_long, int x, int y)
{
	int	frame;

	frame = so_long->animation.enemy_frame;
	if (frame == 0)
		mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
			so_long->game.enemy_s_01.ptr, x * SIZE_S, y * SIZE_S);
	else if (frame == 1)
		mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
			so_long->game.enemy_s_02.ptr, x * SIZE_S, y * SIZE_S);
	else
		mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
			so_long->game.enemy_s_03.ptr, x * SIZE_S, y * SIZE_S);
}

void	render_collectibles(t_so_long *so_long, int x, int y, char tile)
{
	if (tile == 'C')
		mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
			so_long->game.collectible_s_01.ptr, x * SIZE_S, y * SIZE_S);
	else if (tile == 'c')
		mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
			so_long->game.collectible_s_02.ptr, x * SIZE_S, y * SIZE_S);
	else if (tile == 'M')
		mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
			so_long->game.collectible_s_03.ptr, x * SIZE_S, y * SIZE_S);
}

int	animation_loop(t_so_long *so_long)
{
	so_long->animation.frame_counter++;
	if (so_long->animation.frame_counter >= 2200)
	{
		so_long->animation.frame_counter = 0;
		so_long->animation.enemy_frame = (so_long->animation.enemy_frame + 1)
			% 3;
		put_tiles_env(so_long);
		put_tiles(so_long);
		display_items_count(so_long);
		display_moves_count(so_long);
	}
	return (0);
}
