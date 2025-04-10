/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_too_high.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:51:31 by jowagner          #+#    #+#             */
/*   Updated: 2025/04/10 19:15:31 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_map_too_high(t_data data)
{
	size_t	i;

	i = 0;
	while (data.map[i] != NULL)
		i++;
	if (i > 30)
	{
		ft_putstr_fd("Error.\nMap is too high (more than 30 lines).\n", 2);
		return (true);
	}
	i = 0;
	while (data.map[i] != NULL)
	{
		if (ft_strlen(data.map[i]) > 40)
		{
			ft_putstr_fd("Error.\nMap is too long (more than 40 char).\n", 2);
			return (true);
		}
		i++;
	}
	return (false);
}
