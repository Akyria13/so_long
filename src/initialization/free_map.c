/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:52:56 by jowagner          #+#    #+#             */
/*   Updated: 2025/04/10 18:37:26 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map, bool shouldExit)
{
	int	i;

	if (map == NULL)
		return ;
	i = 0;
	while (map[i] != NULL)
		free(map[i++]);
	free(map);
	if (shouldExit)
		exit(1);
}
