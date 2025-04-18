/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:47:07 by jowagner          #+#    #+#             */
/*   Updated: 2025/04/18 17:18:07 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_so_long	so_long;

	if (ac != 2)
	{
		ft_putstr_fd("Error.\nSo_long waits only the map.ber as argument.\n",
			2);
		return (1);
	}
	if (ac == 2)
	{
		ft_bzero(&so_long, sizeof(t_so_long));
		initialization(av[1], &so_long);
		init_so_long(&so_long);
		if (!init_so_long(&so_long))
		{
			ft_putstr_fd("Error.\nSomething wrong with initialisation.\n",
				2);
			free(so_long.map_file);
			return (1);
		}
	}
	return (0);
}
