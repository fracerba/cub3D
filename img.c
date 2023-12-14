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
	int		color;
	char	*path;

	if (x < 0 || x >= r->img.lenght)
		return (0);
	else if (y < 0 || y >= r->img.lenght)
		return (0);
	y *= r->img.line;
	x *= (r->img.bits / 8);
	path = &r->img.path[y + x];
	color = *(unsigned int *)path;
	return (color);
}

void	put_pixel_on_img(t_cubed *c, int x, int y, int color)
{
	char	*i;

	y *= c->screen.line;
	x *= (c->screen.bits / 8);
	i = &c->screen.path[y + x];
	*(unsigned int *)i = color;
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
