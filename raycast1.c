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
