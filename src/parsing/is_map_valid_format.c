/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:17:34 by jowagner          #+#    #+#             */
/*   Updated: 2025/04/18 19:23:47 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	is_map_valid_occur(t_so_long *so_long)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (so_long->data.map[i] != NULL)
	{
		j = 0;
		while (so_long->data.map[i][j] != '\0')
		{
			if (so_long->data.map[i][j] == 'P')
				so_long->occur.player_occur++;
			if (so_long->data.map[i][j] == 'E')
				so_long->occur.exit_occur++;
			if (so_long->data.map[i][j] == 'C' || so_long->data.map[i][j] == 'c'
				|| so_long->data.map[i][j] == 'M')
				so_long->occur.collectible_occur++;
			j++;
		}
		i++;
	}
}

static bool	is_map_valid_element(t_so_long *so_long)
{
	is_map_valid_occur(so_long);
	if (so_long->occur.player_occur != 1)
	{
		ft_putstr_fd("Error.\nExactly 1 player (P) is required.\n", 2);
		return (false);
	}
	if (so_long->occur.exit_occur != 1)
	{
		ft_putstr_fd("Error.\nExactly 1 exit (E) is required.\n", 2);
		return (false);
	}
	if (so_long->occur.collectible_occur < 1)
	{
		ft_putstr_fd("Error.\nAt least 1 collectible (C, c, M) is required.\n",
			2);
		return (false);
	}
	return (true);
}

bool	is_map_valid_format(t_so_long *so_long)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (so_long->data.map[i] != NULL)
	{
		j = 0;
		while (so_long->data.map[i][j] != '\0')
		{
			if (so_long->data.map[i][j] != '1' && so_long->data.map[i][j] != '0'
				&& so_long->data.map[i][j] != 'X'
				&& so_long->data.map[i][j] != 'E'
				&& so_long->data.map[i][j] != 'P'
				&& so_long->data.map[i][j] != 'C'
				&& so_long->data.map[i][j] != 'c'
				&& so_long->data.map[i][j] != 'M')
				return (false);
			j++;
		}
		i++;
	}
	return (is_map_valid_element(so_long));
}
