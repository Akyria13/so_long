/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_position.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:39:32 by jowagner          #+#    #+#             */
/*   Updated: 2025/04/08 16:46:01 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_player_direction(t_so_long *so_long, int dx, int dy)
{
	if (dx == 0 && dy == -1)
		so_long->animation.direction = 1;
	else if (dx == 0 && dy == 1)
		so_long->animation.direction = 0;
	else if (dx == -1 && dy == 0)
		so_long->animation.direction = 2;
	else if (dx == 1 && dy == 0)
		so_long->animation.direction = 3;
}

char	get_old_position_char(t_so_long *so_long)
{
	if (so_long->data.map[so_long->player.coords.y][so_long->player.coords.x] != 'P')
		return (so_long->data.map[so_long->player.coords.y][so_long->player.coords.x]);
	if (so_long->player.coords.x == so_long->exit_coords.x
		&& so_long->player.coords.y == so_long->exit_coords.y)
		return ('E');
	return ('0');
}

void	check_exit_position(t_so_long *so_long, int new_x, int new_y)
{
	if (so_long->data.map[new_y][new_x] == 'E')
	{
		so_long->map_r.player_on_exit = true;
		so_long->exit_coords.x = new_x;
		so_long->exit_coords.y = new_y;
	}
	else
		so_long->map_r.player_on_exit = false;
}

void	update_map_and_position(t_so_long *so_long, int new_x, int new_y,
		char old_position_char)
{
	so_long->data.map[so_long->player.coords.y][so_long->player.coords.x] = old_position_char;
	so_long->data.map[new_y][new_x] = 'P';
	so_long->player.coords.x = new_x;
	so_long->player.coords.y = new_y;
	so_long->player.mooves++;
}
