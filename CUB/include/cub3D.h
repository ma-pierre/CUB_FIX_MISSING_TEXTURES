/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:35:51 by mapierre          #+#    #+#             */
/*   Updated: 2024/04/08 19:59:38 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "get_next_line.h"
# include "libft.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <mlx_int.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "../mlx/mlx.h"
# include "struct.h"

# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17
# define KEYPRESS	2
# define KEYRELEASE 3
# define SCREEN_W 1280
# define SCREEN_H 720
//# define SCREEN_W 640
//# define SCREEN_H 480
/*Errors and success messages*/
# define ERROR_ARGS "Error\nInvalid arguments."
# define INV_FILE_NOT_FOUND "Error\nFile not found."
# define INV_XPM_FILE_NOT_FOUND "Error\nXPM file not found."
# define INV_EXT "Error\nWrong extension's name."
# define INV_EXT_XPM "Error\nWrong extension's name(xpm)."
# define INVALID_POSITION "Error\nProblem with the player's position."
# define INVALID_EXIT "Error\nProblem with the exit."
# define INVALID_TEXT_COL "Error\nProblem with your textures or colors."
# define INV_UNDER_THE_MAP "Error\nSomething letf under the map."
# define MAP_NOT_CLOSED "Error\nMap border not closed here : [%d][%d]. \n"
//#define INV_DIRECTORY "Error: .cub is a directory."
# define ERROR_FILE_EMPTY "Error\nThe file is empty."
# define ERROR_MAP_EMPTY "Error\nThe map is empty."
# define INVALID_CHAR_MSG "Error\nInvalid character : at position [%d][%d]"
# define FAIL_INIT_STRUCT "Error\nInitialisation of the structure failed."

// Enumération pour les caractères de scène
enum		e_scene_characters
{
	FREE_WAY = '0',
	WALL = '1',
	PLAYER_NORTH = 'N',
	PLAYER_SOUTH = 'S',
	PLAYER_EAST = 'E',
	PLAYER_WEST = 'W',
	SPACES = ' '
};

/* Collect the map*/
t_map	*init_the_map_data(char *filename);
int		nb_lines_and_col(t_map *map_data);
char	**read_file_lines(t_map *map_data);
void	retrieve_the_final_map(t_map *map_data, t_config *config);
void	is_valid(int i, int j, t_config *config);
int		map_empty(t_map *map_data, t_config *config);
int		is_map_border_closed(t_map *map_data, t_config *config, char **map);
// Assignation
int		count_and_read(t_map *map_data);
char	*trim_new_line(char *line);
int		is_valid_scene_character(char c, t_map *map_data);
void	actualize_nb_of_col(char *line, int *nb_of_cols);
// Parsing
int		parsing(t_map *map_data, t_config *config);
int		check_if_dotcub(char *filename);
int		check_if_xpm(char *filename);
int		map_empty(t_map *map_data, t_config *config);
int		is_map_valid(t_map *map_data, t_config *config);
int		is_map_border_closed(t_map *map_data, t_config *config, char **map);
int		is_whitespace(char c);
int		check_texture_and_color(char *line, t_config *config);
int		under_the_map(t_config *config);
void	check_first_line(t_map *map_data, t_config *config, char **map);
int		check_player(char c);
void	check_particular_cases(t_config *config, t_map *map_data, char **map);
/*Files*/
int		open_for_the_xpm(char *filename);
int		alloc_and_stock_lines(t_map *map_data);
int		open_for_the_map(t_map *map_data);

void	actualize_nb_of_col(char *line, int *nb_of_cols);
char	*trim_new_line(char *line);
int		ft_putendl_fd_cub(char *str, int fd);
int		is_whitespace(char c);
int		is_valid_scene_character(char c, t_map *map_data);
/*Debugg*/
void	print_the_map(char **map);
int		ft_strslen(char **strs);
/*Textures*/
void	handle_north_texture(char *line, t_config *config);
void	handle_south_texture(char *line, t_config *config);
void	handle_east_texture(char *line, t_config *config);
void	handle_west_texture(char *line, t_config *config);
void	handle_ceiling_color(char *line, t_config *config);
void	handle_floor_color(char *line, t_config *config);
void	init_floor_color(char *line, t_config *config);
void	init_ceiling_color(char *line, t_config *config);
int		retrieve_the_int(char *line, int *i);
int		rgbstr_to_int(char *line);
int		ft_result_color(char *str, int i);
/*Clear*/
void	error_exit(t_config *config, char *message);
void	free_map_data(t_map *map_data);
void	free_config(t_config *config);
void	free_tab(char **tab);
/*utils*/
char	*ft_strdup_cub(const char *s1);
int		ft_strlen_cub(const char *s);
//MOVE_CAMERA.c
void	camera_left(t_data *d);
void	camera_right(t_data *d);
void	init_player_n_s(t_data *data);
void	init_player_direction(t_data *data);
//MOVE.c
void	move_forward(t_data *data);
void	move_back(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);
//HANDLE_KEY_PRESS
void	init_keys(t_data *data);
int		key_press(int keycode, t_data *data);
int		key_release(int keycode, t_data *data);
int		handle_keypress(t_data *data);
//RAYCASTING
void	main_raycast(t_data *data, t_image win_img);
void	raycast_init_var(t_data *data, int x);
void	raycast_init_raydir(t_data *data);
int		raycast_dda(t_data *data);
//
int		do_frame(t_data *data);
int		clean_game(t_data *data);
//////////RAYCAST MAIN/////////////////
void    init_raycast_main(t_data *data);
void    init_raycast_all(t_data *data);
t_texture    *define_texture(t_data *d, int side);
/////////////TEXTURES////////////////
void    init_texture(t_data *data);
void	draw_fc(t_image image, int x, int y1, int y2, int color);
void	draw_wall(t_image image, int x, int y1, int y2, t_texture *tex, int texX);
///img
t_image	image_new(void *mlx, size_t w, size_t h);
void	image_put_px(t_image img, int x, int y, int color);
void	image_delete(void	*mlx, t_image img);
// MINIMAP 
void	display_minimap(t_data *data, t_image win_img);
void	readtab(t_data *data);
void	draw_square(t_image img, int x, int y, int size, int color);

#endif