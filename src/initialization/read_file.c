/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 21:35:42 by jowagner          #+#    #+#             */
/*   Updated: 2025/04/18 16:56:22 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error.\nIn open_file ");
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

	if (fd < 0)
		return (-1);
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

static void	gnl_clear(int fd)
{
	char	*tmp;

	tmp = get_next_line(fd);
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
	}
}

char	**map_init(int count_line, char *filename)
{
	t_data	data;
	char	**tmp;
	int		fd;

	fd = open_file(filename);
	data.map = malloc(sizeof(char *) * (count_line + 1));
	if (!data.map)
		return (NULL);
	tmp = data.map;
	while (count_line--)
	{
		*tmp = get_next_line(fd);
		if (!*tmp)
		{
			free_map(data.map, false);
			return (NULL);
		}
		tmp++;
	}
	*tmp = NULL;
	free(get_next_line(fd));
	gnl_clear(fd);
	close_file(fd);
	return (data.map);
}

int	close_file(int fd)
{
	int	result;

	result = close(fd);
	if (result == -1)
	{
		perror("Error.\nIn close_file ");
		exit(1);
		return (result);
	}
	else
		return (result);
}
