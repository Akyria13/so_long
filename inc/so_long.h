/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:44:43 by jowagner          #+#    #+#             */
/*   Updated: 2025/02/26 20:10:46 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx_int.h"
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include "../libft/get_next_line/get_next_line.h"
# include <math.h>

//-- The main functions --//

//-- Utils function --//
//--- --- --- --- ---//
int			get_number_line(char *line);
void		free_map(char **map);
char**		map_init(int count_line);
void		replace_char(char **map, char old_char, char new_char);
//--- --- --- --- ---//

#endif
