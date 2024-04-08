/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 02:05:10 by mapierre          #+#    #+#             */
/*   Updated: 2024/04/08 17:22:12 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_map
{
	char	**map;
	char	*map_name;
	char	*col;
	char	*line;
	char	player_start_dir;
	int		y;
	int		x;
	int		fd;
	int		i_end_of_tc;
	int		j_end_of_tc;
	int		i_begin_the_map;
	int		j_end_of_map;
	int		beg_index;
	int		end_i;
	int		end_j;
	int		flag_pos;
}			t_map;

typedef struct s_config
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		floor_color;
	int		ceiling_color;
	int		flag;
	t_map	*map_data;

}			t_config;

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_length;
	int		endian;
}			t_texture;

typedef struct t_mlx
{
	void	*mlx;
	void	*win;
}				t_mlx;

typedef struct s_key
{
	int	s;
	int	w;
	int	d;
	int	a;
	int	esc;
	int	l_arrow;
	int	r_arrow;
}			t_key;

typedef struct s_raycast
{
	double	cam_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_x;
	double	side_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_disst;
	int		step_x;
	int		step_y;
}				t_raycast;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_data
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		move_speed;
	double		rot_speed;
	char		**game_map;
	int			map_witdh;
	int			map_height;
	char		player_start_dir;
	t_key		keys;
	void		*mlx;
	void		*win;
	t_config	*config;
	t_raycast	raycast_var;
	t_texture	textures_info[4];
}				t_data;

#endif