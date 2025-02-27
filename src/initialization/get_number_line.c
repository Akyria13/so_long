/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number_line                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:50:13 by jowagner          #+#    #+#             */
/*   Updated: 2025/02/27 14:52:01 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	get_number_line(char *line)
{
	int count_line;
	int fd;

	fd = open("map/map01.ber", O_RDONLY);
	// if (fd == -1)
	// 	exit_function();
	count_line = 0;
	line = "";
	while (line != NULL)
	{
		count_line++;
		line = get_next_line(fd);
		free(line);
	}
	close(fd);
	return (count_line);
}