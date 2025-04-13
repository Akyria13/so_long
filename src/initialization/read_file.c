/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 21:35:42 by jowagner          #+#    #+#             */
/*   Updated: 2025/04/13 15:39:01 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error in open_file ");
		exit(1);
		return (1);
	}
	else
		return (fd);
}

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

char	**map_init(int count_line, char *filename)
{
	t_data	data;
	int		i;
	int		fd;

	fd = open_file(filename);
	data.map = malloc(sizeof(char *) * (count_line + 1));
	if (data.map == NULL)
		return (NULL);
	data.map[count_line] = NULL;
	i = 0;
	while (i < count_line)
		data.map[i++] = get_next_line(fd);
	get_next_line(fd);
	close_file(fd);
	return (data.map);
}

int	close_file(int fd)
{
	int	result;

	result = close(fd);
	if (result == -1)
	{
		perror("Error in close_file : ");
		exit(1);
		return (result);
	}
	else
		return (result);
}
