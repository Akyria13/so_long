/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_newline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:09:46 by jowagner          #+#    #+#             */
/*   Updated: 2025/03/24 17:16:43 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	remove_newline(t_data data)
{
	int	i;
	int	j;

	i = 0;
	while (data.map[i])
	{
		j = 0;
		while (data.map[i][j])
		{
			if (data.map[i][j] == '\n')
				data.map[i][j] = '\0';
			j++;
		}
		i++;
	}
}
