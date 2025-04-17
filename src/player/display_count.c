/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:26:19 by jowagner          #+#    #+#             */
/*   Updated: 2025/04/17 20:07:13 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_moves_count(t_so_long *so_long)
{
	char	*moves_str;
	char	*display_str;

	moves_str = ft_itoa(so_long->player.moves);
	if (!moves_str)
	{
		ft_putstr_fd("Error.\nSomething wrong with moves count.\n", 2);
		return ;
	}
	display_str = ft_strjoin("Moves : ", moves_str);
	if (!display_str)
	{
		free(moves_str);
		ft_putstr_fd("Error.\nSomething wrong with display string.\n", 2);
		return ;
	}
	mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
		so_long->game.wall_s_01.ptr, 0, 0);
	mlx_string_put(so_long->mlx_v.mlx, so_long->mlx_v.win, 10, 20, 0x000000,
		display_str);
	free(moves_str);
	free(display_str);
}

void	display_items_count(t_so_long *so_long)
{
	char	*items_str;
	char	*display_item_str;

	items_str = ft_itoa(so_long->map_r.nbr_items);
	if (!items_str)
	{
		ft_putstr_fd("Error.\nSomething wrong with items count.\n", 2);
		return ;
	}
	display_item_str = ft_strjoin("| Items : ", items_str);
	if (!display_item_str)
	{
		free(items_str);
		ft_putstr_fd("Error.\nSomething wrong with display item string.\n", 2);
		return ;
	}
	mlx_put_image_to_window(so_long->mlx_v.mlx, so_long->mlx_v.win,
		so_long->game.wall_s_01.ptr, 0, 0);
	mlx_string_put(so_long->mlx_v.mlx, so_long->mlx_v.win, 80, 20, 0x000000,
		display_item_str);
	free(items_str);
	free(display_item_str);
}

void	display_game_info(t_so_long *so_long)
{
	ft_printf(RESET "Move number : %d | Item number : %d\n",
		so_long->player.moves, so_long->map_r.nbr_items);
	put_tiles_env(so_long);
	put_tiles(so_long);
	display_items_count(so_long);
	display_moves_count(so_long);
}
