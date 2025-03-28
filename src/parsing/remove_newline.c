/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_newline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:09:46 by jowagner          #+#    #+#             */
/*   Updated: 2025/03/29 17:52:21 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	remove_newline(t_data data)
{
	size_t	i;
	size_t	len;

	if (data.map == NULL)
		return ;
	i = 0;
	while (data.map[i])
	{
		len = ft_strlen(data.map[i]);
		if (len > 0 && data.map[i][len - 1] == '\n')
			data.map[i][len - 1] = '\0';
		i++;
	}
}
