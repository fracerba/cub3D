/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:12:55 by fracerba          #+#    #+#             */
/*   Updated: 2023/12/07 12:12:58 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_right(t_cubed *c)
{
	double	old_dir;
	double	old_plane;

	old_dir = c->dir_x;
	old_plane = c->cam_x;
	c->dir_x = c->dir_x * c->tngs[2] - c->dir_y * c->tngs[0];
	c->dir_y = old_dir * c->tngs[0] + c->dir_y * c->tngs[2];
	c->cam_x = c->cam_x * c->tngs[2] - c->cam_y * c->tngs[0];
	c->cam_y = old_plane * c->tngs[0] + c->cam_y * c->tngs[2];
}

void	rotate_left(t_cubed *c)
{
	double	old_dir;
	double	old_plane;

	old_dir = c->dir_x;
	old_plane = c->cam_x;
	c->dir_x = c->dir_x * c->tngs[3] - c->dir_y * c->tngs[1];
	c->dir_y = old_dir * c->tngs[1] + c->dir_y * c->tngs[3];
	c->cam_x = c->cam_x * c->tngs[3] - c->cam_y * c->tngs[1];
	c->cam_y = old_plane * c->tngs[1] + c->cam_y * c->tngs[3];
}

int	check_keys(int key)
{
	if (key == 65363 || key == 65361)
		return (1);
	if (key == 97 || key == 100 || key == 115 || key == 119)
		return (1);
	return (0);
}

int	ft_move(int key, t_cubed *c)
{
	if (key == 65307)
		free_all(c);
	if (!check_keys(key))
		return (0);
	else
		mlx_destroy_image(c->mlx, c->screen.img);
	if (key == 65363)
		rotate_right(c);
	else if (key == 65361)
		rotate_left(c);
	if (key == 100)
		move_right(c, c->map, (int)c->play_x, (int)c->play_y);
	else if (key == 97)
		move_left(c, c->map, (int)c->play_x, (int)c->play_y);
	else if (key == 115)
		move_backwards(c, c->map, (int)c->play_x, (int)c->play_y);
	else if (key == 119)
		move_forward(c, c->map, (int)c->play_x, (int)c->play_y);
	frame_render(c);
	return (0);
}
