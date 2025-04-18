/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_have_wall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:11:11 by jowagner          #+#    #+#             */
/*   Updated: 2025/04/18 19:22:33 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	is_vertical_walls_valid(t_data data)
{
	size_t	i;
	size_t	last_col;

	last_col = ft_strlen(data.map[0]);
	i = 0;
	while (data.map[i] != NULL)
	{
		if (ft_strlen(data.map[i]) < last_col)
			return (false);
		if (data.map[i][0] != '1' || data.map[i][last_col - 1] != '1')
			return (false);
		i++;
	}
	return (true);
}

static bool	is_horizontal_walls_valid(t_data data)
{
	size_t	i;
	size_t	last_row;

	last_row = 0;
	while (data.map[last_row] != NULL)
		last_row++;
	last_row--;
	i = 0;
	while (data.map[0][i] != '\0')
	{
		if (data.map[0][i] != '1' || data.map[last_row][i] != '1')
			return (false);
		i++;
	}
	return (true);
}

bool	is_map_have_wall(t_data data)
{
	if (is_vertical_walls_valid(data) && is_horizontal_walls_valid(data))
		return (true);
	return (false);
}
