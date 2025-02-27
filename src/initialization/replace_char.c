/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:53:44 by jowagner          #+#    #+#             */
/*   Updated: 2025/02/27 14:55:42 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	replace_char(char **map, char old_char, char new_char)
{
	int i;
	int j;

	if (map == NULL)
		return ;
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == old_char)
				map[i][j] = new_char;
			j++;
		}
		i++;
	}
}