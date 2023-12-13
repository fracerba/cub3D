/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:27:16 by fracerba          #+#    #+#             */
/*   Updated: 2023/12/13 12:27:18 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_distance(t_ray *r, t_cubed *c)
{
	while (r->hit == 0)
	{
		if(r->dist_x < r->dist_y)
		{
			r->dist_x += r->delta_x;
			r->map_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->dist_y += r->delta_y;
			r->map_y += r->step_y;
			r->side = 1;
		}
		if (c->map[r->map_x][r->map_y] == '1')
			r->hit = 1;
	}
	if(r->side == 0)
		r->wall_dist = r->dist_x - r->delta_x;
	else
		r->wall_dist = r->dist_y - r->delta_y;
}

void	get_texture(t_ray *r, t_cubed *c)
{
	if(r->side == 0)
	{
		if (r->step_x == 1)
			r->img = c->north;
		else
			r->img = c->south;
	}
	else if (r->side == 1)
	{
		if (r->step_y == 1)
			r->img = c->east;
		else
			r->img = c->west;
	}
}

void	render_line(t_ray *r, t_cubed *c)
{
	get_texture(r, c);
	r->line = (int)(HEIGHT / r->wall_dist);
	r->d_start = (-r->line / 2) + (HEIGHT / 2);
	if(r->d_start < 0) 
		r->d_start = 0;
	r->d_end = (r->line / 2) + (HEIGHT / 2);
	if(r->d_end >= HEIGHT) 
		r->d_end = HEIGHT - 1;
	if(r->side)
		r->wall_pos = c->play_x + r->wall_dist * r->ray_x; 
	else          
		r->wall_pos = c->play_y + r->wall_dist * r->ray_y;
	r->wall_pos -= floor((r->wall_pos));
}

void	draw_line(t_ray *r, t_cubed *c, int x)
{
	int	color;
	int	y;

	y = r->d_start - 1;
	r->text_x = (int)(r->wall_pos * (double)r->img.lenght);
	if(r->side == 0 && r->ray_x > 0) 
		r->text_x = r->img.lenght - r->text_x - 1;
	if(r->side == 1 && r->ray_y < 0)
		r->text_x = r->img.lenght - r->text_x - 1;
	r->step = 1.0 * r->img.height / r->line;
	r->text_pos = (r->d_start - HEIGHT / 2 + r->line / 2) * r->step;
	while(++y <= r->d_end)
	{
		r->text_y = (int)r->text_pos & (r->img.height - 1);
		r->text_pos += r->step;
        color = get_color(r, r->text_x, r->text_y);
		put_pixel_on_img(c, x, y, color);
	}
}