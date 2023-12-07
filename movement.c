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

void	move_forward(t_cubed *cube, char **map, double x, double y)
{
}

void	move_backwards(t_cubed *cube, char **map, double x, double y)
{
}

void	move_left(t_cubed *cube, char **map, double x, double y)
{
}

void	move_right(t_cubed *cube, char **map, double x, double y)
{
}

int	ft_move(int key, t_cubed *cube)
{
	if (key == 65307)
		free_all(cube);
	if (key == 100)
		rotate_right(cube, cube->map, cube->play_x, cube->play_y);
	else if (key == 97)
		rotate_left(cube, cube->map, cube->play_x, cube->play_y);
	if (key == 65363)
		move_right(cube, cube->map, cube->play_x, cube->play_y);
	else if (key == 65361)
		move_left(cube, cube->map, cube->play_x, cube->play_y);
	else if (key == 65364)
		move_down(cube, cube->map, cube->play_x, cube->play_y);
	else if (key == 65362)
		move_up(cube, cube->map, cube->play_x, cube->play_y);
	return (0);
}
