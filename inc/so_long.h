/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:44:43 by jowagner          #+#    #+#             */
/*   Updated: 2025/04/10 21:35:07 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/ft_printf/ft_printf.h"
# include "../libft/get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define SIZE_S 64
# define RESET "\033[H\033[J"
// Environment
# define Wall_S_F01 "./textures/Tree-Frame01.xpm"
# define Grass_S_F01 "./textures/Grass-Frame01.xpm"
# define Exit_S_01 "./textures/Well-Frame01.xpm"
# define Player_on_Exit_S_01 "./textures/Player-on-Well-Frame01.xpm"
# define Collectible_S_F01 "./textures/Pokeball-01-Frame01.xpm"
# define Collectible_S_F02 "./textures/Pokeball-02-Frame01.xpm"
# define Collectible_S_F03 "./textures/Pokeball-03-Frame01.xpm"
// Player
//--- Player bot side
# define Player_S_Bot_F01 "./textures/Sacha-Bot-Frame01.xpm"
# define Player_S_Bot_L_F02 "./textures/Sacha-Bot-L-Frame02.xpm"
# define Player_S_Bot_R_F03 "./textures/Sacha-Bot-R-Frame03.xpm"
//--- Player top side
# define Player_S_Top_F01 "./textures/Sacha-Top-Frame01.xpm"
# define Player_S_Top_L_F02 "./textures/Sacha-Top-L-Frame02.xpm"
# define Player_S_Top_R_F03 "./textures/Sacha-Top-R-Frame03.xpm"
//--- Player left side
# define Player_S_Left_F01 "./textures/Sacha-Left-Frame01.xpm"
# define Player_S_Left_L_F02 "./textures/Sacha-Left-L-Frame02.xpm"
# define Player_S_Left_R_F03 "./textures/Sacha-Left-R-Frame03.xpm"
//--- Player right side
# define Player_S_Right_F01 "./textures/Sacha-Right-Frame01.xpm"
# define Player_S_Right_L_F02 "./textures/Sacha-Right-L-Frame02.xpm"
# define Player_S_Right_R_F03 "./textures/Sacha-Right-R-Frame03.xpm"
// Enemy
# define Enemy_S_F01 "./textures/Lugia-Frame01.xpm"
# define Enemy_S_F02 "./textures/Lugia-Frame02.xpm"
# define Enemy_S_F03 "./textures/Lugia-Frame03.xpm"

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

typedef struct s_occur
{
	int					player_occur;
	int					exit_occur;
	int					collectible_occur;
}						t_occur;

typedef struct s_player
{
	t_coordinate		coords;
	int					mooves;
}						t_player;

typedef struct s_map_requirements
{
	int					nbr_collectible;
	int					nbr_items;
	int					nbr_player;
	bool				player_on_exit;
}						t_map_requirements;

typedef struct s_game
{
	t_image				wall_s_01;
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
	t_image				p_on_exit_s_01;
	t_image				enemy_s_01;
	t_image				enemy_s_02;
	t_image				enemy_s_03;
}						t_game;

typedef struct s_animation
{
	int					frame_counter;
	int					current_frame;
	int					enemy_frame;
	int					direction;
}						t_animation;

typedef struct s_so_long
{
	t_mlx_vars			mlx_v;
	t_data				data;
	t_game				game;
	t_map_requirements	map_r;
	t_player			player;
	t_coordinate		exit_coords;
	t_occur				occur;
	char				*map_file;
	t_animation			animation;
}						t_so_long;

//--- The main function ---//

//--- Utils functions ---//
//- Initialization -//
int						close_file(int fd);
void					free_map(char **map, bool shouldExit);
void					initialization(char *filename, t_so_long *so_long);
char					**map_init(int count_line, char *filename);
int						open_file(char *filename);
int						pre_read(int fd);
//--- --- --- --- ---//

//- MLX -//
void					sprite_init_env(t_so_long *so_long);
void					sprite_init_enemy(t_so_long *so_long);
void					sprite_init_player_top_and_bot(t_so_long *so_long);
void					sprite_init_player_left_and_right(t_so_long *so_long);
void					sprite_init_exit_and_collectibles(t_so_long *so_long);
//--- --- --- --- ---//

//- Parsing -//
bool					check_file_extension(char *filepath, char *extension);
bool					is_map_empty(t_data data);
bool					is_map_have_wall(t_data data);
bool					is_map_rectangular(t_data data);
bool					is_map_too_high(t_data data);
bool					is_map_valid_format(t_so_long *so_long);
void					parsing_initialization(t_so_long *so_long);
void					remove_newline(t_data data);
//--- --- --- --- ---//

//- Player -//
//- Player -> Display information -//
void					display_moves_count(t_so_long *so_long);
void					display_items_count(t_so_long *so_long);
void					display_game_info(t_so_long *so_long);
//- Player -> Element position -//
void					update_player_direction(t_so_long *so_long, int dx,
							int dy);
char					get_old_position_char(t_so_long *so_long);
void					check_exit_position(t_so_long *so_long, int dx, int dy);
void					update_map_and_position(t_so_long *so_long, int new_x,
							int new_y, char old_position_char);
//- Player -> Initalization -//
void					init_player_position(t_so_long *so_long);
void					count_map_elements(t_so_long *so_long);
//- Player -> Rendering environment -//
void					render_wall_and_grass(t_so_long *so_long, int x, int y,
							char tile);
void					render_exit(t_so_long *so_long, int x, int y);
void					render_enemy(t_so_long *so_long, int x, int y);
void					render_collectibles(t_so_long *so_long, int x, int y,
							char tile);
int						animation_loop(t_so_long *so_long);
//- Player -> Rendering player-//
void					render_player_bottom(t_so_long *so_long, int x, int y);
void					render_player_top(t_so_long *so_long, int x, int y);
void					render_player_left(t_so_long *so_long, int x, int y);
void					render_player_right(t_so_long *so_long, int x, int y);
void					render_player(t_so_long *so_long, int x, int y);
//- Player -> Player mooves -//
void					reset_game(t_so_long *so_long);
void					move_player(t_so_long *so_long, int dx, int dy);
int						key_hook(int keycode, t_so_long *so_long);
// Tiles
//--- --- --- --- ---//

//- Window -//
int						close_window(t_so_long *so_long);
int						init_so_long(t_so_long *so_long);
void					put_tiles_env(t_so_long *so_long);
void					put_tiles(t_so_long *so_long);
void					window_size(t_data *data);
//--- --- --- --- ---//

#endif
