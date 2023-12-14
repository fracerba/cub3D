/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaiazzo <scaiazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:00:10 by fracerba          #+#    #+#             */
/*   Updated: 2023/12/14 17:26:34 by scaiazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	make_minimap(t_cubed *c, int x, int y, int color)
{
	int	sizeX;
	int	sizeY;

	sizeY = 0;
	while (sizeY < 4)
	{
		sizeX = 0;
		while (sizeX < 4)
		{
			put_pixel_on_img(c, x * 4 + sizeX, y * 4 + sizeY, color);
			sizeX++;
		}
		sizeY++;
	}
}

void	draw_minimap(t_cubed *c)
{
	int		i;
	int		j;

	i = 0;
	while (i < c->map_height)
	{
		j = 0;
		while (j < c->map_width)
		{
			if (c->map[i][j] == '1')
				make_minimap(c, j, i, 0x00FFFFFF);
			else
				make_minimap(c, j, i, 0x00000000);
			j++;
		}
		i++;
	}
	//posizione del player errata
	ft_printf("x: %d y: %d\n", (int)c->play_x, (int)c->play_y);
	make_minimap(c, (int)c->play_x, (int)c->play_y, 0x00FF00FF);
}
