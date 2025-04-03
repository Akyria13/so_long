/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:02:28 by jowagner          #+#    #+#             */
/*   Updated: 2025/04/03 20:05:27 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static bool	is_move_valid(t_so_long *so_long, int new_x, int new_y)
// {
// 	if (so_long->data.map[new_x][new_y] == '1')
// 		return (false);
// 	if (so_long->data.map[new_y][new_x] == 'E'
// 		&& so_long->map_r.nbr_items != so_long->map_r.nbr_collectible)
// 		return (false);
// 	return (true);
// }

void	move_player(t_so_long *so_long, int dx, int dy)
{
	// int	new_x;
	// int	new_y;
	// new_x = so_long->player.coords.x + dx;
	// new_y = so_long->player.coords.y + dy;
	// if (!is_move_valid(so_long, new_x, new_y))
	// 	return ;
	// so_long->player.coords.x = new_x;
	// so_long->player.coords.y = new_y;
	so_long->player.mooves++;
	// ft_printf("Mooves : %d", so_long->player.mooves);
	ft_printf("Tentative de mooves dx = %d && dy = %d\n", dx, dy);
	ft_printf("Moove number : %d\n", so_long->player.mooves);
}

int	key_hook(int keycode, t_so_long *so_long)
{
	if (keycode == XK_Escape)
	{
		ft_printf(" %d - Exit ./so_long. \n", keycode);
		close_window(so_long);
	}
	else if (keycode == XK_z || keycode == XK_w || keycode == XK_Up)
	{
		ft_printf(" %d\n", keycode);
		move_player(so_long, 0, -1);
	}
	else if (keycode == XK_s || keycode == XK_Down)
	{
		ft_printf(" %d\n", keycode);
		move_player(so_long, 0, 1);
	}
	else if (keycode == XK_q || keycode == XK_a || keycode == XK_Left)
	{
		ft_printf(" %d\n", keycode);
		move_player(so_long, -1, 0);
	}
	else if (keycode == XK_d || keycode == XK_Right)
	{
		ft_printf(" %d\n", keycode);
		move_player(so_long, 1, 0);
	}
	else
		ft_printf(" %d - Key_hook !\n", keycode);
	return (0);
}
