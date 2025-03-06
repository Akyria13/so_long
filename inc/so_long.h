/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:44:43 by jowagner          #+#    #+#             */
/*   Updated: 2025/03/06 18:44:43 by jowagner         ###   ########.fr       */
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
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

#define SPRITE_SIZE 64
#define Lugia_S_F01 "./textures/Lugia-Frame01.xpm"
#define Lugia_S_F02 "./textures/Lugia-Frame02.xpm"
#define Lugia_S_F03 "./textures/Lugia-Frame03.xpm"
#define Tree_S_F01 "./textures/Tree.xpm"
#define Grass_S_F01 "./textures/Grass.xpm"

typedef struct s_mlx_vars
{
	void				*mlx;
	void				*win;
}			t_mlx_vars;

typedef struct s_data
{
	char				**map;
	int					width_map;
	int					height_map;
}			t_data;

typedef struct s_image
{
	void				*ptr;
	int					width;
	int					height;
}			t_image;

typedef struct s_game
{
	t_image 				lugia_sprite_01;
	t_image 				lugia_sprite_02;
	t_image 				lugia_sprite_03;
	t_image					tree_sprite_01;
	t_image					grass_sprite_01;
}			t_game;

typedef struct s_so_long
{
	t_mlx_vars			mlx_v;
	t_data				data;
	t_game				game;
}			t_so_long;

// typedef struct s_map_requirements
// {
// 	int		nbr_collectible;
// 	int		nbr_exit;
// 	int		nbr_player;
// 	bool is_recta
// }			t_map_requirements;

//--- The main function ---//

//--- Utils functions ---//
//- Initialization -//
int			close_file(int fd);
void		free_map(char **map);
void		initialization(char *filename, t_data *data);
char		**map_init(int count_line, char *filename);
int			open_file(char *filename);
int			pre_read(int fd);
//--- --- --- --- ---//

//- MLX -//
void		sprite_init_lugia(t_so_long *so_long);
void		sprite_init_env(t_so_long *so_long);
//--- --- --- --- ---//

//- Parsing -//
bool		check_file_extension(char *filepath, char *extension);
//--- --- --- --- ---//

//- Window -//
int			init_so_long(t_so_long *so_long);
void		window_size(t_data *data);
//void	put_tiles(t_data data);
//--- --- --- --- ---//

#endif
