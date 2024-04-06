#include "cub3D.h"

void    readtab(t_data *data)
{
    int i;
    int j;
    
    i = 0;
    while(data->game_map[i])
    {
        j = 0;
        while(data->game_map[i][j])
        {
            j++;
        }
        if (j > data->map_witdh)
            data->map_witdh = j;
        i++; 
    }
    data->map_height = i;
}

void display_minimap(t_data *data, t_image win_img)
{


    int mapWidth = (SCREEN_W * 0.2);
    int mapHeight = (SCREEN_H * 0.2);
    int x, y;
    float scale_x = mapWidth/ (float)data->map_witdh / 64;
    float scale_y = mapHeight/ (float)data->map_height / 64;
    int draw_size = ceil(64 * scale_x); // Utilisez ceil pour arrondir au nombre entier le plus proche et couvrir les espaces
// Calculez une taille appropriée pour le joueur sur la minimap

    
    for (y = 0; y < data->map_height; y++) {
        for (x = 0; x < data->map_witdh; x++) {
       if (data->game_map[y][x] == '0') {
                draw_square(win_img, x * draw_size, y * draw_size, draw_size, 0x5c5364);
            } else {
                draw_square(win_img, x * draw_size, y * draw_size, draw_size, 0xe1b9e1);
            }
    }
    draw_square(win_img, data->pos_y * 64 * scale_x, data->pos_x * 64 * scale_y, 64 * scale_x, 0x23afc6);

}
}
void draw_square(t_image img, int x, int y, int size, int color)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		
		while (j < size)
		{
			image_put_px(img, x + i, y + j, color);
			j++;
		}
		i++;
	}
}