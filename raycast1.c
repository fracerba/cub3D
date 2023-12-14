/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:17:37 by fracerba          #+#    #+#             */
/*   Updated: 2023/12/07 11:17:39 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_direction(t_cubed *cube)
{
	if (cube->dir_s == 'N')
		cube->dir_x = -1;
	else if (cube->dir_s == 'E' || cube->dir_s == 'W')
		cube->dir_x = 0;
	else if (cube->dir_s == 'S')
		cube->dir_x = 1;
	if (cube->dir_s == 'N' || cube->dir_s == 'S')
		cube->dir_y = 0;
	else if (cube->dir_s == 'E')
		cube->dir_y = 1;
	else if (cube->dir_s == 'W')
		cube->dir_y = -1;
	if (cube->dir_s == 'N' || cube->dir_s == 'S')
		cube->cam_x = 0;
	else if (cube->dir_s == 'E')
		cube->cam_x = 0.6;
	else if (cube->dir_s == 'W')
		cube->cam_x = -0.6;
	if (cube->dir_s == 'N')
		cube->cam_y = 0.6;
	else if (cube->dir_s == 'E' || cube->dir_s == 'W')
		cube->cam_y = 0;
	else if (cube->dir_s == 'S')
		cube->cam_y = -0.6;
}

void	init_cubed(t_cubed *cube)
{
	set_direction(cube);
	cube->frames = 0;
	cube->r_speed = 0.7;
	cube->m_speed = 0.1;
	cube->tngs[0] = sin(cube->r_speed);
	cube->tngs[1] = sin(-(cube->r_speed));
	cube->tngs[2] = cos(cube->r_speed);
	cube->tngs[3] = cos(-(cube->r_speed));
	cube->int_f = rgb_convert(cube->floor);
	cube->int_c = rgb_convert(cube->ceiling);
}

int	frame_render(t_cubed *c)
{
	c->screen.img = mlx_new_image(c->mlx, WIDTH, HEIGHT);
	c->screen.path = mlx_get_data_addr(c->screen.img, &c->screen.bits,
		&c->screen.line, &c->screen.end);
	start_raycast(c);
	//draw_minimap(c);
	mlx_put_image_to_window(c->mlx, c->window, c->screen.img, 0, 0);
	return (0);
}

void	start_rendering(t_cubed *cube)
{
	init_cubed(cube);
	cube->window = mlx_new_window(cube->mlx, WIDTH, HEIGHT, "CUB3D");
	if (!cube->window)
	{
		print_error(32, 1);
		free_all(cube);
	}
	frame_render(cube);
	mlx_hook(cube->window, 3, 1L << 1, ft_move, &cube);
	mlx_hook(cube->window, 17, 0, free_all, &cube);
	mlx_loop(cube->mlx);
}
