/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:48:51 by jowagner          #+#    #+#             */
/*   Updated: 2025/04/08 16:24:49 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_player_bottom(t_so_long *so_long, int x, int y)
{
	int	frame;

	frame = so_long->animation.current_frame;
	if (frame == 0)
		mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
			so_long->game.p_bot_s_01.ptr, x * SIZE_S, y * SIZE_S);
	else if (frame == 1)
		mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
			so_long->game.p_bot_l_02.ptr, x * SIZE_S, y * SIZE_S);
	else
		mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
			so_long->game.p_bot_r_03.ptr, x * SIZE_S, y * SIZE_S);
}

void	render_player_top(t_so_long *so_long, int x, int y)
{
	int	frame;

	frame = so_long->animation.current_frame;
	if (frame == 0)
		mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
			so_long->game.p_top_s_01.ptr, x * SIZE_S, y * SIZE_S);
	else if (frame == 1)
		mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
			so_long->game.p_top_l_02.ptr, x * SIZE_S, y * SIZE_S);
	else
		mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
			so_long->game.p_top_r_03.ptr, x * SIZE_S, y * SIZE_S);
}

void	render_player_left(t_so_long *so_long, int x, int y)
{
	int	frame;

	frame = so_long->animation.current_frame;
	if (frame == 0)
		mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
			so_long->game.p_left_s_01.ptr, x * SIZE_S, y * SIZE_S);
	else if (frame == 1)
		mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
			so_long->game.p_left_l_02.ptr, x * SIZE_S, y * SIZE_S);
	else
		mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
			so_long->game.p_left_r_03.ptr, x * SIZE_S, y * SIZE_S);
}

void	render_player_right(t_so_long *so_long, int x, int y)
{
	int	frame;

	frame = so_long->animation.current_frame;
	if (frame == 0)
		mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
			so_long->game.p_right_s_01.ptr, x * SIZE_S, y * SIZE_S);
	else if (frame == 1)
		mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
			so_long->game.p_right_l_02.ptr, x * SIZE_S, y * SIZE_S);
	else
		mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
			so_long->game.p_right_r_03.ptr, x * SIZE_S, y * SIZE_S);
}

void	render_player(t_so_long *so_long, int x, int y)
{
	int	direction;

	direction = so_long->animation.direction;
	if (direction == 0)
		render_player_bottom(so_long, x, y);
	else if (direction == 1)
		render_player_top(so_long, x, y);
	else if (direction == 2)
		render_player_left(so_long, x, y);
	else if (direction == 3)
		render_player_right(so_long, x, y);
}
