/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:44:43 by jowagner          #+#    #+#             */
/*   Updated: 2025/02/27 17:43:29 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/ft_printf/ft_printf.h"
# include "../libft/get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_data
{
	char	**map;
}			t_data;

typedef struct s_map
{
}			t_map;

typedef struct s_image
{
}			t_image;

//--- The main function ---//

//--- Utils functions ---//
//- Initialization -//
void		free_map(char **map);
void		replace_char(char **map, char old_char, char new_char);
int			get_number_line(char *line);
char		**map_init(int count_line);
//--- --- --- --- ---//

//- Parsing -//
void		map_exist(t_map **map);
//--- --- --- --- ---//

#endif
