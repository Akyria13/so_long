/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:02:28 by jowagner          #+#    #+#             */
/*   Updated: 2025/04/07 19:41:14 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	is_move_valid(t_so_long *so_long, int new_x, int new_y)
{
	if (so_long->data.map[new_y][new_x] == '1')
		return (false);
	if (so_long->data.map[new_y][new_x] == 'C'
		|| so_long->data.map[new_y][new_x] == 'c')
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
		ft_printf("You won in %d mooves.\n", so_long->player.mooves);
		close_window(so_long);
	}
	return (true);
}

void	display_moves_count(t_so_long *so_long)
{
	char	*moves_str;
	char	*display_str;

	moves_str = ft_itoa(so_long->player.mooves);
	display_str = ft_strjoin("Mooves : ", moves_str);
	mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
		so_long->game.wall_s_01.ptr, 0, 0);
	mlx_string_put(so_long->mlx_v.mlx, so_long->mlx_v.win, 10, 20, 0xFFFFFF,
		display_str);
	free(moves_str);
	free(display_str);
}

void	display_items_count(t_so_long *so_long)
{
	char	*items_str;
	char	*display_item_str;

	items_str = ft_itoa(so_long->map_r.nbr_items);
	display_item_str = ft_strjoin("/ Items : ", items_str);
	mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
		so_long->game.wall_s_01.ptr, 0, 0);
	mlx_string_put(so_long->mlx_v.mlx, so_long->mlx_v.win, 80, 20, 0xFFFFFF,
		display_item_str);
	free(items_str);
	free(display_item_str);
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
	if (so_long->data.map[new_y][new_x] == 'E')
	{
		so_long->map_r.player_on_exit = true;
		so_long->exit_coords.x = new_x;
		so_long->exit_coords.y = new_y;
	}
	else
		so_long->map_r.player_on_exit = false;
	if (so_long->data.map[so_long->player.coords.y][so_long->player.coords.x] == 'P')
	{
		old_position_char = '0';
		if (so_long->player.coords.x == so_long->exit_coords.x
			&& so_long->player.coords.y == so_long->exit_coords.y)
			old_position_char = 'E';
		so_long->data.map[so_long->player.coords.y][so_long->player.coords.x] = old_position_char;
	}
	so_long->data.map[new_y][new_x] = 'P';
	so_long->player.coords.x = new_x;
	so_long->player.coords.y = new_y;
	so_long->player.mooves++;
	ft_printf("Moove number : %d\n", so_long->player.mooves);
	ft_printf("Collectible number : %d\n", so_long->map_r.nbr_collectible);
	ft_printf("Items number : %d\n", so_long->map_r.nbr_items);
	put_tiles_env(so_long);
	put_tiles(so_long);
	display_items_count(so_long);
	display_moves_count(so_long);
}

void	init_player_position(t_so_long *so_long)
{
	int	y;
	int	x;

	y = 0;
	while (so_long->data.map[y])
	{
		x = 0;
		while (so_long->data.map[y][x])
		{
			if (so_long->data.map[y][x] == 'P')
			{
				so_long->player.coords.x = x;
				so_long->player.coords.y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	count_map_elements(t_so_long *so_long)
{
	int	y;
	int	x;

	y = 0;
	so_long->map_r.nbr_collectible = 0;
	so_long->map_r.nbr_items = 0;
	while (so_long->data.map[y])
	{
		x = 0;
		while (so_long->data.map[y][x])
		{
			if (so_long->data.map[y][x] == 'C'
				|| so_long->data.map[y][x] == 'c')
				so_long->map_r.nbr_collectible++;
			x++;
		}
		y++;
	}
	ft_printf("Total collectibles to find : %d\n",
		so_long->map_r.nbr_collectible);
}

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
	ft_printf("Game reset!\n");
}

int	key_hook(int keycode, t_so_long *so_long)
{
	if (keycode == XK_Escape)
	{
		ft_printf(" %d - Exit ./so_long. \n", keycode);
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
	else
		ft_printf(" %d - Key_hook !\n", keycode);
	return (0);
}
