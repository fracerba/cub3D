/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:09:10 by fracerba          #+#    #+#             */
/*   Updated: 2023/12/11 12:09:11 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_cubed *c, char **map, int x, int y)
{
	if (c->map[x + (int)(c->dir_x * c->m_speed)][y] != '1')
		c->play_x += c->dir_x * c->m_speed;
	if (c->map[x][y + (int)(c->dir_y * c->m_speed)] != '1')
		c->play_y += c->dir_y * c->m_speed;
}

void	move_backwards(t_cubed *c, char **map, int x, int y)
{
	if (c->map[x - (int)(c->dir_x * c->m_speed)][y] != '1')
		c->play_x -= c->dir_x * c->m_speed;
	if (c->map[x][y - (int)(c->dir_y * c->m_speed)] != '1')
		c->play_y -= c->dir_y * c->m_speed;
}

void	move_left(t_cubed *c, char **map, int x, int y)
{
	if (c->map[x - (int)(c->dir_x * c->m_speed)][y] != '1')
		c->play_x -= c->dir_x * c->m_speed;
	if (c->map[x][y + (int)(c->dir_y * c->m_speed)] != '1')
		c->play_y += c->dir_y * c->m_speed;
}

void	move_right(t_cubed *c, char **map, int x, int y)
{
	if (c->map[x + (int)(c->dir_x * c->m_speed)][y] != '1')
		c->play_x += c->dir_x * c->m_speed;
	if (c->map[x][y - (int)(c->dir_y * c->m_speed)] != '1')
		c->play_y -= c->dir_y * c->m_speed;
}
