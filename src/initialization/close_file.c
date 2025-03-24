/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:02:24 by jowagner          #+#    #+#             */
/*   Updated: 2025/03/24 14:45:02 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

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
