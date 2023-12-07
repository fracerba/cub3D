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

void init_cubed(t_cubed *cube)
{
	set_direction(cube);
	cube->frames = 0;
	cube->r_speed = 0;
	cube->m_speed = 0;
}

int	frame_render(t_cubed *cube)
{
	
}

void	start_raycast(t_cubed *cube)
{
	print_matrix_nl(cube->map);
	printf("h = %i w = %i\n", cube->map_height, cube->map_width);
	printf("x = %f y = %f d = %c\n", cube->play_x, cube->play_y, cube->dir_s);
	cube->window = mlx_new_window(cube->mlx, WIDTH, HEIGHT, "CUB3D");
	if (!cube->window)
	{
		print_error(32, 1);
		free_all(cube);
	}
	mlx_hook(cube->window, 3, 1L << 1, ft_move, &cube);
	mlx_hook(cube->window, 17, 0, free_all, &cube);
	mlx_loop_hook(cube->mlx, frame_render, &cube);
	mlx_loop(cube->mlx);
}
