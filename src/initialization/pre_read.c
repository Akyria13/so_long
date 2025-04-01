/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:50:13 by jowagner          #+#    #+#             */
/*   Updated: 2025/04/01 19:03:02 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	pre_read(int fd)
{
	char	*line;
	int		count_line;

	count_line = 0;
	line = "";
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line)
			count_line++;
		free(line);
	}
	close_file(fd);
	return (count_line);
}
