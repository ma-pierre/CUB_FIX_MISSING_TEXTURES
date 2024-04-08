#include "cub3D.h"
/*
void    init_texture(t_data *data)
{
    t_texture   t_n;
    t_texture   t_s;
    t_texture   t_e;
    t_texture   t_w;

    t_n.img = mlx_xpm_file_to_image(data->mlx, data->config->north_texture, &t_n.width, &t_n.height);
    t_n.addr = mlx_get_data_addr(t_n.img, t_n.bpp, &t_n.line_length, &t_n.endian);
    t_s.img = mlx_xpm_file_to_image(data->mlx, data->config->south_texture, &t_s.width, &t_s.height);
    t_s.addr = mlx_get_data_addr(t_s.img, &t_s.bpp, &t_s.line_length, &t_s.endian);
    t_e.img = mlx_xpm_file_to_image(data->mlx, data->config->east_texture, &t_e.width, &t_e.height);
   t_e.addr = mlx_get_data_addr(t_e.img, &t_e.bpp, &t_e.line_length, &t_e.endian);
  t_w.img = mlx_xpm_file_to_image(data->mlx, data->config->west_texture, &t_w.width, &t_w.height);
  t_w.addr = mlx_get_data_addr(t_n.img, &t_w.bpp, &t_w.line_length, &t_w.endian);

  data->textures_info[0] = t_n;
  data->textures_info[1] = t_s;
  data->textures_info[2] = t_e;
  data->textures_info[3] = t_w;
}*/

void    init_texture(t_data *data)
{

data->textures_info[0].img = mlx_xpm_file_to_image(data->mlx, data->config->north_texture, &data->textures_info[0].width, &data->textures_info[0].height);
data->textures_info[0].addr = mlx_get_data_addr(data->textures_info[0].img, &data->textures_info[0].bpp, &data->textures_info[0].line_length, &data->textures_info[0].endian);
data->textures_info[1].img = mlx_xpm_file_to_image(data->mlx, data->config->south_texture, &data->textures_info[1].width, &data->textures_info[1].height);
data->textures_info[1].addr = mlx_get_data_addr(data->textures_info[1].img, &data->textures_info[1].bpp, &data->textures_info[1].line_length, &data->textures_info[1].endian);
data->textures_info[2].img = mlx_xpm_file_to_image(data->mlx, data->config->east_texture, &data->textures_info[2].width, &data->textures_info[2].height);
data->textures_info[2].addr = mlx_get_data_addr(data->textures_info[2].img, &data->textures_info[2].bpp, &data->textures_info[2].line_length, &data->textures_info[2].endian);
data->textures_info[3].img = mlx_xpm_file_to_image(data->mlx, data->config->west_texture, &data->textures_info[3].width, &data->textures_info[3].height);
data->textures_info[3].addr = mlx_get_data_addr(data->textures_info[3].img, &data->textures_info[3].bpp, &data->textures_info[3].line_length, &data->textures_info[3].endian);
}