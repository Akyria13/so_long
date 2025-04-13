/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_solvable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:04:34 by jowagner          #+#    #+#             */
/*   Updated: 2025/04/13 16:26:54 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**copy_map(char **original)
{
	int		i;
	char	**copy;

	i = 0;
	while (original[i] != NULL)
		i++;
	copy = malloc(sizeof(char *) * (i + 1));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (original[i] != NULL)
	{
		copy[i] = ft_strdup(original[i]);
		if (copy[i] == NULL)
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	flood_fill(char **map, int y, int x, t_flood *flood)
{
	if (y < 0 || x < 0 || !map[y] || !map[y][x] || map[y][x] == '1'
		|| map[y][x] == 'X' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'C' || map[y][x] == 'c' || map[y][x] == 'M')
		flood->collectibles++;
	if (map[y][x] == 'E')
		flood->exit = 1;
	map[y][x] = 'V';
	flood_fill(map, y - 1, x, flood);
	flood_fill(map, y + 1, x, flood);
	flood_fill(map, y, x - 1, flood);
	flood_fill(map, y, x + 1, flood);
}

bool	is_map_solvable(t_so_long *so_long)
{
	char	**map_copy;
	t_flood	flood;

	map_copy = copy_map(so_long->data.map);
	if (!map_copy)
		return (false);
	flood.collectibles = 0;
	flood.exit = 0;
	flood_fill(map_copy, so_long->player.coords.y, so_long->player.coords.x,
		&flood);
	if (flood.collectibles != so_long->occur.collectible_occur)
	{
		free_map(map_copy, false);
		return (false);
	}
	if (flood.exit != 1)
	{
		free_map(map_copy, false);
		return (false);
	}
	free_map(map_copy, false);
	return (true);
}
