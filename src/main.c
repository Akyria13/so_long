/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:47:07 by jowagner          #+#    #+#             */
/*   Updated: 2025/02/26 20:17:56 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include <unistd.h>

int	main(int argc, char *argv[])
{
	char	**map;
	char	*line;
	int		count_line;
	int		i;

	if (argc != 4)
	{
		printf("Usage : %s map_file / old_char / new_char\n", argv[0]);
		return (1);
	}
	line = NULL;
	count_line = get_number_line(line);
	map = map_init(count_line);
	if (map == NULL)
	{
		printf("Error initializing map\n");
		return (1);
	}
	printf("Carte avant modification :\n");
	i = 0;
	while (map[i] != NULL)
	{
		printf("%s", map[i]);
		i++;
	}
	printf("\n---\n");
	replace_char(map, argv[2][0], argv[3][0]);
	i = 0;
	printf("Carte apres modification :\n");
	while (map[i] != NULL)
	{
		printf("%s", map[i]);
		i++;
	}
	free_map(map);
	return (0);
}
