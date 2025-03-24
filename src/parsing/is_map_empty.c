/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_empty.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:25:46 by jowagner          #+#    #+#             */
/*   Updated: 2025/03/24 16:21:56 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

bool	is_map_empty(t_data data)
{
	int	i;
	int	j;

	if (data.map == NULL || data.map[0] == NULL)
		return (true);
	i = 0;
	while (data.map[i] != NULL)
	{
		j = 0;
		while (data.map[i][j] != '\0')
		{
			if (data.map[i][j] != ' ' && data.map[i][j] != '\n')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
