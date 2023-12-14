/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:45:55 by fracerba          #+#    #+#             */
/*   Updated: 2023/12/05 12:45:56 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_color(t_ray *r, int x, int y)
{

}

void	put_pixel_on_img(t_cubed *c, int x, int y, int color)
{

}

void	ft_destroy_imgs(t_cubed *cube)
{
	if (cube->north.img)
		mlx_destroy_image(cube->mlx, cube->north.img);
	if (cube->south.img)
		mlx_destroy_image(cube->mlx, cube->south.img);
	if (cube->east.img)
		mlx_destroy_image(cube->mlx, cube->east.img);
	if (cube->west.img)
		mlx_destroy_image(cube->mlx, cube->west.img);
}

void	get_img(t_cubed *c, t_img *img, char *path)
{
	img->img = mlx_xpm_file_to_image(c->mlx, path, &img->lenght, &img->height);
	img->path = mlx_get_data_addr(img->img, &img->bits, &img->line, &img->end);
}
