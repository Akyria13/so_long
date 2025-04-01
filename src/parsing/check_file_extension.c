/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_extension.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:53:05 by jowagner          #+#    #+#             */
/*   Updated: 2025/04/01 19:02:29 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	check_file_extension(char *filepath, char *extension)
{
	int	filename_len;
	int	extension_len;

	filename_len = ft_strlen(filepath);
	extension_len = ft_strlen(extension);
	if (filename_len <= extension_len)
		return (false);
	if (ft_strncmp(&filepath[filename_len - extension_len], extension,
			extension_len) == 0)
		return (true);
	return (false);
}
