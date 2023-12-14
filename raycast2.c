/* ************************************************************************** */
/*	                                                                          */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:17:49 by fracerba          #+#    #+#             */
/*   Updated: 2023/12/07 11:17:50 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray_aux(t_ray *r, t_cubed *c)
{
	if (r->ray_x < 0)
	{
		r->step_x = -1;
		r->dist_x = (c->play_x - r->map_x) * r->delta_x;
	}
	else
	{
		r->step_x = 1;
		r->dist_x = (r->map_x + 1.0 - c->play_x) * r->delta_x;
	}
	if (r->ray_y < 0)
	{
		r->step_y = -1;
		r->dist_y = (c->play_y - r->map_y) * r->delta_y;
	}
	else
	{
		r->step_y = 1;
		r->dist_y = (r->map_y + 1.0 - c->play_y) * r->delta_y;
	}
}

void	init_ray(t_ray *r, t_cubed *c, int x)
{
	r->camera = 2 * x / (double)WIDTH - 1;
	r->ray_x = c->dir_x + (r->camera * c->cam_x);
	r->ray_y = c->dir_y + (r->camera * c->cam_y);
	r->map_x = (int)c->play_x;
	r->map_y = (int)c->play_y;
	if (r->ray_x)
		r->delta_x = abs(1 / r->ray_x);
	else
		r->delta_x = 1e30;
	if (r->ray_y)
		r->delta_y = abs(1 / r->ray_y);
	else
		r->delta_y = 1e30;
	r->hit = 0;
	init_ray_aux(r, c);
}

void	draw_floor(t_cubed *c)
{
	int	x;
	int	y;

	x = -1;
	while (++x < (HEIGHT / 2))
	{
		y = 0;
		while (y < WIDTH)
		{
			put_pixel_on_img(c, x, y, c->int_f);
			y++;
		}
	}
}

void	draw_ceiling(t_cubed *c)
{
	int	x;
	int	y;

	x = (HEIGHT / 2) - 1;
	while (++x < HEIGHT)
	{
		y = 0;
		while (y < WIDTH)
		{
			put_pixel_on_img(c, x, y, c->int_c);
			y++;
		}
	}
}

void	start_raycast(t_cubed *c)
{
	int		x;
	t_ray	r;

	x = -1;
	draw_floor(c);
	draw_ceiling(c);
	while (++x < WIDTH)
	{
		init_ray(&r, c, x);
		render_distance(&r, c);
		render_line(&r, c);
		draw_line(&r, c, x);
	}
}
