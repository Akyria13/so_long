/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:47:07 by jowagner          #+#    #+#             */
/*   Updated: 2025/03/06 17:33:33 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// #include <X11/X.h>
// #include <sys/select.h>

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
	int			i;

	// void		*mlx_win;
	// void		*mlx;
	// int			j;
	// int			size;
	i = 0;
	if (ac != 2)
	{
		ft_putstr_fd("So_long waits the map.ber as argument, coco.\n", 2);
		return (1);
	}
	if (ac == 2)
	{
		initialization(av[1], &so_long.data);
		init_so_long_data();
		init_so_long(&so_long);
	}
	/*MLX*/
	// mlx = mlx_init();
	// if (!mlx)
	// 	return (0);
	// mlx_win = mlx_new_window(mlx, so_long.data.width_map * SPRITE_SIZE,
	// 		so_long.data.height_map * SPRITE_SIZE, "PokeLong");
	// if (!mlx_win)
	// 	return (0);
	//////////////////////////////////// <<<<<<<< size = 64;
	// Just a variable to store the size because mlx_xpm_file_to_image requires it
	// background_img = mlx_xpm_file_to_image(mlx,
	//		"./textures/Lugia-Frame01.xpm",
	// 		&size, &size);
	// pacman_img = mlx_xpm_file_to_image(mlx, "./textures/Lugia-Frame01.xpm",
	//		&size, &size);
	// Returns a (void*) to the image
	// while (i < so_long.data.height_map)
	// {
	// 	j = 0;
	// 	// Put the image in the window
	// 	while (j < so_long.data.width_map)
	// 	{
	// 		if (so_long.data.map[i][j] == '1')
	// 			mlx_put_image_to_window(mlx, mlx_win, background_img, j
	// 				* SPRITE_SIZE, i * SPRITE_SIZE);
	// 		else if (so_long.data.map[i][j] == '0')
	// 			mlx_put_image_to_window(mlx, mlx_win, pacman_img, j
	// 				* SPRITE_SIZE, i * SPRITE_SIZE);
	// 		j++;
	// 	}
	// 	i++;
	// }
	// mlx_key_hook(mlx_win, key_hook, NULL); // Hook to handle
	// mlx_hook(mlx_win, DestroyNotify, 1L << 0, destroy_mlx, NULL);
	// mlx_loop(mlx);
	// free_map(so_long.data.map);
	return (0);
}

// i = 0;
// while (data.map[i] != NULL)
// {
// 	printf("%s", data.map[i]);
// 	i++;
// }
// if (data.map == NULL)
// {
// 	printf("Error initializing map.\n");
// 	return (1);
// }
