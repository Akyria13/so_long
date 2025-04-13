/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:21:55 by jowagner          #+#    #+#             */
/*   Updated: 2025/04/13 16:11:14 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	window_size(t_data *data)
{
	size_t	i;
	size_t	j;

	if (data->map == NULL)
		return ;
	i = ft_strlen(data->map[0]);
	j = 0;
	while (data->map[j] != NULL)
		j++;
	data->width_map = i;
	data->height_map = j;
}
