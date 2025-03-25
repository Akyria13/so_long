/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:47:07 by jowagner          #+#    #+#             */
/*   Updated: 2025/03/25 18:27:14 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// int	key_hook(int keycode, t_data *data)
// // map[2][5] Check if map[1][5] is a wall for valid input
// {
// 	(void)data;
// 	if (keycode == XK_Escape)
// 	{
// 		printf(" %d, Exit ./so_long. \n", keycode);
// 		exit(EXIT_SUCCESS);
// 	}
// 	else
// 		printf(" %d, Hello from key_hook!\n", keycode);
// 	return (0);
// }

// int	destroy_mlx(void)
// {
// 	printf("Exit ./so_long X. \n");
// 	exit(1);
// }

static t_so_long	init_so_long_data(void)
{
	t_so_long	so_long;

	so_long.data.map = NULL;
	so_long.data.height_map = 0;
	so_long.data.width_map = 0;
	return (so_long);
}

int	main(int ac, char **av)
{
	t_so_long	so_long;

	if (ac != 2)
	{
		ft_putstr_fd("So_long waits the map.ber as argument, coco.\n", 2);
		return (1);
	}
	if (ac == 2)
	{
		so_long = init_so_long_data();
		initialization(av[1], &so_long.data);
		init_so_long(&so_long);
	}
	return (0);
}
