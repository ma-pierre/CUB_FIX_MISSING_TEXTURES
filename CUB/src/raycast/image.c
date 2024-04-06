/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:05:47 by mapierre          #+#    #+#             */
/*   Updated: 2024/04/03 15:35:23 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	image_put_px(t_image img, int x, int y, int color)
{
	if (y < 0 || x < 0 || y > SCREEN_H || x > SCREEN_W)
		return ;
	img.addr += (y * img.line_length + x * (img.bits_per_pixel / 8));
	*(int *)img.addr = color;
}

t_image	image_new(void *mlx, size_t w, size_t h)
{
	t_image	img;

	img.img = mlx_new_image(mlx, w, h);
	if (!img.img)
		return ((t_image){});
	img.addr = mlx_get_data_addr(
			img.img,
			&img.bits_per_pixel,
			&img.line_length,
			&img.endian
			);
	return (img);
}

void	image_delete(void	*mlx, t_image img)
{
	if (img.img)
		mlx_destroy_image(mlx, img.img);
	img = (t_image){0};
}
