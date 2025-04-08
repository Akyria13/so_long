/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:47:07 by jowagner          #+#    #+#             */
/*   Updated: 2025/04/08 11:06:18 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		ft_bzero(&so_long, sizeof(t_so_long));
		initialization(av[1], &so_long);
		so_long.map_file = ft_strdup(av[1]);
		init_so_long(&so_long);
	}
	return (0);
}
