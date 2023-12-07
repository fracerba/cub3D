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

void	move_forward(t_cubed *c, char **map, int x, int y)
{
	if(c->map[x + (int)(c->dir_x * c->m_speed)][y] != '1')
		c->play_x += c->dir_x * c->m_speed;
	if(c->map[x][y + (int)(c->dir_y * c->m_speed)] != '1')
		c->play_y += c->dir_y * c->m_speed;
}

void	move_backwards(t_cubed *c, char **map, int x, int y)
{
	if(c->map[x - (int)(c->dir_x * c->m_speed)][y] != '1')
		c->play_x -= c->dir_x * c->m_speed;
	if(c->map[x][y - (int)(c->dir_y * c->m_speed)] != '1')
		c->play_y -= c->dir_y * c->m_speed;
}

void	move_left(t_cubed *c, char **map, int x, int y)
{
	if(c->map[x - (int)(c->dir_x * c->m_speed)][y] != '1')
		c->play_x -= c->dir_x * c->m_speed;
	if(c->map[x][y + (int)(c->dir_y * c->m_speed)] != '1')
		c->play_y += c->dir_y * c->m_speed;
}

void	move_right(t_cubed *c, char **map, int x, int y)
{
	if(c->map[x + (int)(c->dir_x * c->m_speed)][y] != '1')
		c->play_x += c->dir_x * c->m_speed;
	if(c->map[x][y - (int)(c->dir_y * c->m_speed)] != '1')
		c->play_y -= c->dir_y * c->m_speed;
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
