/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_empty.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:25:46 by jowagner          #+#    #+#             */
/*   Updated: 2025/04/18 19:19:38 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_map_empty(t_data data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (data.map[i] != NULL)
	{
		j = 0;
		while (data.map[i][j] != '\0')
		{
			if (data.map[i][j] != ' ' && data.map[i][j] != '\n')
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}
