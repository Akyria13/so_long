/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:17:34 by jowagner          #+#    #+#             */
/*   Updated: 2025/03/24 17:38:09 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

bool	is_map_valid_format(t_data data)
{
	int	i;
	int	j;

	if (data.map == NULL || data.map[0] == NULL)
		return (false);
	i = 0;
	while (data.map[i] != NULL)
	{
		j = 0;
		while (data.map[i][j] != '\0')
		{
			if (data.map[i][j] == ' ')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
