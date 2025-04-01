/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:21:55 by jowagner          #+#    #+#             */
/*   Updated: 2025/04/01 18:36:17 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	window_size(t_data *data)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (data->map[j] != NULL)
	{
		i = 0;
		while (data->map[j][i])
		{
			i++;
		}
		j++;
	}
	data->width_map = i;
	data->height_map = j;
}
