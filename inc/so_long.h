/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:44:43 by jowagner          #+#    #+#             */
/*   Updated: 2025/03/29 20:15:26 by jowagner         ###   ########.fr       */
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

#define SIZE_S 64
//Environment
#define Wall_S_F01 "./textures/Tree-Frame01.xpm"
#define Wall_S_F02 "./textures/Tree-Frame02.xpm"
#define Grass_S_F01 "./textures/Grass-Frame01.xpm"
#define Exit_S_01 "./textures/Well-Frame01.xpm"
#define Collectible_S_F01 "./textures/Pokeball-01-Frame01.xpm"
#define Collectible_S_F02 "./textures/Pokeball-02-Frame01.xpm"
#define Collectible_S_F03 "./textures/Pokeball-03-Frame01.xpm"
//Player
//--- Player bot side
#define Player_S_Bot_F01 "./textures/Sacha-Bot-Frame01.xpm"
#define Player_S_Bot_L_F02 "./textures/Sacha-Bot-L-Frame02.xpm"
#define Player_S_Bot_R_F03 "./textures/Sacha-Bot-R-Frame03.xpm"
//--- Player top side
#define Player_S_Top_F01 "./textures/Sacha-Top-Frame01.xpm"
#define Player_S_Top_L_F02 "./textures/Sacha-Top-L-Frame02.xpm"
#define Player_S_Top_R_F03 "./textures/Sacha-Top-R-Frame03.xpm"
//--- Player left side
#define Player_S_Left_F01 "./textures/Sacha-Left-Frame01.xpm"
#define Player_S_Left_L_F02 "./textures/Sacha-Left-L-Frame02.xpm"
#define Player_S_Left_R_F03 "./textures/Sacha-Left-R-Frame03.xpm"
//--- Player right side
#define Player_S_Right_F01 "./textures/Sacha-Right-Frame01.xpm"
#define Player_S_Right_L_F02 "./textures/Sacha-Right-L-Frame02.xpm"
#define Player_S_Right_R_F03 "./textures/Sacha-Right-R-Frame03.xpm"
//Enemy
#define Enemy_S_F01 "./textures/Lugia-Frame01.xpm"
#define Enemy_S_F02 "./textures/Lugia-Frame02.xpm"
#define Enemy_S_F03 "./textures/Lugia-Frame03.xpm"

typedef struct s_mlx_vars
{
	void				*mlx;
	void				*win;
}						t_mlx_vars;

typedef struct s_data
{
	char				**map;
	int					width_map;
	int					height_map;
}						t_data;

typedef struct s_image
{
	void				*ptr;
	int					width;
	int					height;
}						t_image;

typedef struct s_coordinate
{
	int					x;
	int					y;
}						t_coordinate;

typedef struct s_player
{
	t_coordinate		coords;
	int					mooves;
}						t_player;

typedef struct s_map_requirements
{
	int					nbr_collectible;
	int					nbr_items;
	int					nbr_exit;
	int					nbr_player;
	int					nbr_spawn;
}						t_map_reqhttps://github.com/Akyria13/so_long/commit/1009cc6549ad85fbadfdcdb30b4274f9b4a6d5bbuirements;

typedef struct s_game
{
	t_image				wall_s_01;
	t_image				wall_s_02;
	t_image				grass_s_01;
	t_image				exit_s_01;
	t_image				collectible_s_01;
	t_image				collectible_s_02;
	t_image				collectible_s_03;
	t_image				p_bot_s_01;
	t_image				p_bot_l_02;
	t_image				p_bot_r_03;
	t_image				p_top_s_01;
	t_image				p_top_l_02;
	t_image				p_top_r_03;
	t_image				p_left_s_01;
	t_image				p_left_l_02;
	t_image				p_left_r_03;
	t_image				p_right_s_01;
	t_image				p_right_l_02;
	t_image				p_right_r_03;
	t_image 			enemy_s_01;
	t_image 			enemy_s_02;
	t_image 			enemy_s_03;
}						t_game;

typedef struct s_so_long
{
	t_mlx_vars			mlx_v;
	t_data				data;
	t_game				game;
	t_map_requirements	map_r;
}						t_so_long;


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
void		sprite_init_env(t_so_long *so_long);
void		sprite_init_enemy(t_so_long *so_long);
void		sprite_init_player_top_and_bot(t_so_long *so_long);
void		sprite_init_player_left_and_right(t_so_long *so_long);
void		sprite_init_exit_and_collectibles(t_so_long *so_long);
//--- --- --- --- ---//

//- Parsing -//
bool		check_file_extension(char *filepath, char *extension);
bool		is_map_empty(t_data data);
bool		is_map_have_wall(t_data data);
bool		is_map_rectangular(t_data data);
bool		is_map_valid_format(t_data data);
void		parsing_initialization(t_data *data);
void		remove_newline(t_data data);
//--- --- --- --- ---//

//- Window -//
int			init_so_long(t_so_long *so_long);
void		window_size(t_data *data);
//--- --- --- --- ---//

#endif
