/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:17:34 by jowagner          #+#    #+#             */
/*   Updated: 2025/04/01 19:02:41 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_map_valid_format(t_data data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (data.map[i] != NULL)
	{
		j = 0;
		while (data.map[i][j] != '\0')
		{
			if (data.map[i][j] != '1' && data.map[i][j] != '0'
				&& data.map[i][j] != 'X' && data.map[i][j] != 'E'
				&& data.map[i][j] != 'P' && data.map[i][j] != 'C'
				&& data.map[i][j] != 'c')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
