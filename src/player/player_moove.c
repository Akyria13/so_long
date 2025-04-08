/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:02:28 by jowagner          #+#    #+#             */
/*   Updated: 2025/04/08 17:06:42 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	reset_game(t_so_long *so_long)
{
	char	*map_path;

	if (!so_long->map_file)
	{
		ft_printf("Error: map_file is not initialized\n");
		return ;
	}
	map_path = ft_strdup(so_long->map_file);
	free_map(so_long->data.map);
	so_long->data.map = map_init(pre_read(open_file(map_path)), map_path);
	free(map_path);
	so_long->player.mooves = 0;
	so_long->map_r.nbr_items = 0;
	so_long->map_r.player_on_exit = false;
	count_map_elements(so_long);
	init_player_position(so_long);
	put_tiles_env(so_long);
	put_tiles(so_long);
	ft_printf("Game reset !\n");
}

static bool	is_move_valid(t_so_long *so_long, int new_x, int new_y)
{
	if (so_long->data.map[new_y][new_x] == '1')
		return (false);
	if (so_long->data.map[new_y][new_x] == 'C'
		|| so_long->data.map[new_y][new_x] == 'c'
		|| so_long->data.map[new_y][new_x] == 'M')
	{
		so_long->data.map[new_y][new_x] = '0';
		so_long->map_r.nbr_items++;
		return (true);
	}
	if (so_long->data.map[new_y][new_x] == 'X')
	{
		ft_printf("You loose, you died from enemy Lugia.");
		close_window(so_long);
	}
	if (so_long->map_r.nbr_items == so_long->map_r.nbr_collectible)
		put_tiles_env(so_long);
	if (so_long->data.map[new_y][new_x] == 'E'
		&& so_long->map_r.nbr_items == so_long->map_r.nbr_collectible)
	{
		so_long->player.mooves++;
		ft_printf("You won in %d mooves.\n", so_long->player.mooves);
		close_window(so_long);
	}
	return (true);
}

void	move_player(t_so_long *so_long, int dx, int dy)
{
	int		new_x;
	int		new_y;
	char	old_position_char;

	new_x = so_long->player.coords.x + dx;
	new_y = so_long->player.coords.y + dy;
	if (!is_move_valid(so_long, new_x, new_y))
		return ;
	update_player_direction(so_long, dx, dy);
	so_long->animation.current_frame = (so_long->animation.current_frame + 1)
		% 3;
	check_exit_position(so_long, new_x, new_y);
	old_position_char = get_old_position_char(so_long);
	update_map_and_position(so_long, new_x, new_y, old_position_char);
	display_game_info(so_long);
}

int	key_hook(int keycode, t_so_long *so_long)
{
	if (keycode == XK_Escape)
	{
		ft_printf("Exit ./so_long. \n");
		close_window(so_long);
	}
	else if (keycode == XK_r)
		reset_game(so_long);
	else if (keycode == XK_z || keycode == XK_w || keycode == XK_Up)
		move_player(so_long, 0, -1);
	else if (keycode == XK_s || keycode == XK_Down)
		move_player(so_long, 0, 1);
	else if (keycode == XK_q || keycode == XK_a || keycode == XK_Left)
		move_player(so_long, -1, 0);
	else if (keycode == XK_d || keycode == XK_Right)
		move_player(so_long, 1, 0);
	return (0);
}
