/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_rectangular.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:29:17 by jowagner          #+#    #+#             */
/*   Updated: 2025/04/10 22:11:22 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_map_rectangular(t_data data)
{
	size_t	i;
	size_t	line_len;

	line_len = ft_strlen(data.map[0]);
	i = 0;
	while (data.map[i] != NULL)
	{
		if (line_len != ft_strlen(data.map[i]))
			return (false);
		i++;
	}
	return (true);
}
