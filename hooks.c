/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:51:26 by fracerba          #+#    #+#             */
/*   Updated: 2023/11/23 12:51:27 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mouse_fast_right(t_cubed *c)
{
	double	old_dir;
	double	old_plane;

	old_dir = c->dir_x;
	old_plane = c->cam_x;
	c->dir_x = c->dir_x * c->f_tngs[2] - c->dir_y * c->f_tngs[0];
	c->dir_y = old_dir * c->f_tngs[0] + c->dir_y * c->f_tngs[2];
	c->cam_x = c->cam_x * c->f_tngs[2] - c->cam_y * c->f_tngs[0];
	c->cam_y = old_plane * c->f_tngs[0] + c->cam_y * c->f_tngs[2];
}

void	mouse_fast_left(t_cubed *c)
{
	double	old_dir;
	double	old_plane;

	old_dir = c->dir_x;
	old_plane = c->cam_x;
	c->dir_x = c->dir_x * c->f_tngs[3] - c->dir_y * c->f_tngs[1];
	c->dir_y = old_dir * c->f_tngs[1] + c->dir_y * c->f_tngs[3];
	c->cam_x = c->cam_x * c->f_tngs[3] - c->cam_y * c->f_tngs[1];
	c->cam_y = old_plane * c->f_tngs[1] + c->cam_y * c->f_tngs[3];
}

void	mouse_slow_right(t_cubed *c)
{
	double	old_dir;
	double	old_plane;

	old_dir = c->dir_x;
	old_plane = c->cam_x;
	c->dir_x = c->dir_x * c->m_tngs[2] - c->dir_y * c->m_tngs[0];
	c->dir_y = old_dir * c->m_tngs[0] + c->dir_y * c->m_tngs[2];
	c->cam_x = c->cam_x * c->m_tngs[2] - c->cam_y * c->m_tngs[0];
	c->cam_y = old_plane * c->m_tngs[0] + c->cam_y * c->m_tngs[2];
}

void	mouse_slow_left(t_cubed *c)
{
	double	old_dir;
	double	old_plane;

	old_dir = c->dir_x;
	old_plane = c->cam_x;
	c->dir_x = c->dir_x * c->m_tngs[3] - c->dir_y * c->m_tngs[1];
	c->dir_y = old_dir * c->m_tngs[1] + c->dir_y * c->m_tngs[3];
	c->cam_x = c->cam_x * c->m_tngs[3] - c->cam_y * c->m_tngs[1];
	c->cam_y = old_plane * c->m_tngs[1] + c->cam_y * c->m_tngs[3];
}

int	mouse_move(int x, int y, t_cubed *c)
{
	int	prt;

	prt = WIDTH / 9;
	(void) y;
	mlx_destroy_image(c->mlx, c->screen.img);
	if (x < prt * 3 && x <= c->old_mouse)
	{
		if (x < prt)
			mouse_fast_right(c);
		else
			mouse_slow_right(c);
	}
	else if (x > prt * 6 && x >= c->old_mouse)
	{
		if (x > prt * 8)
			mouse_fast_left(c);
		else
			mouse_slow_left(c);
	}
	frame_render(c);
	c->old_mouse = x;
	return (0);
}
