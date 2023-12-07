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

void	move_forward(t_cubed *cube, char **map, int x, int y)
{
	if(cube->map[x + (int)(cube->dir_x * speed)][y] != '1')
		cube->play_x += cube->dir_x * speed;
	if(cube->map[x][y + (int)(cube->dir_y * speed)] != '1')
		cube->play_y += cube->dir_y * speed;
}

void	move_backwards(t_cubed *cube, char **map, int x, int y)
{
	if(cube->map[x - (int)(cube->dir_x * speed)][y] != '1')
		cube->play_x -= cube->dir_x * speed;
	if(cube->map[x][y - (int)(cube->dir_y * speed)] != '1')
		cube->play_y -= cube->dir_y * speed;
}

void	move_left(t_cubed *cube, char **map, int x, int y)
{
	if(cube->map[x - (int)(cube->dir_x * speed)][y] != '1')
		cube->play_x -= cube->dir_x * speed;
	if(cube->map[x][y + (int)(cube->dir_y * speed)] != '1')
		cube->play_y += cube->dir_y * speed;
}

void	move_right(t_cubed *cube, char **map, int x, int y)
{
	if(cube->map[x + (int)(cube->dir_x * speed)][y] != '1')
		cube->play_x += cube->dir_x * speed;
	if(cube->map[x][y - (int)(cube->dir_y * speed)] != '1')
		cube->play_y -= cube->dir_y * speed;
}

int	ft_move(int key, t_cubed *c)
{
	if (key == 65307)
		free_all(c);
	if (key == 100)
		rotate_right(c, c->map);
	else if (key == 97)
		rotate_left(c, c->map);
	if (key == 65363)
		move_right(c, c->map, (int)c->play_x, (int)c->play_y);
	else if (key == 65361)
		move_left(c, c->map, (int)c->play_x, (int)c->play_y);
	else if (key == 65364)
		move_down(c, c->map, (int)c->play_x, (int)c->play_y);
	else if (key == 65362)
		move_up(c, c->map, (int)c->play_x, (int)c->play_y);
	return (0);
}
