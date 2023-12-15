/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
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
	while (sizeY < 5)
	{
		sizeX = 0;
		if (y + sizeY > HEIGHT)
			break ;
		while (sizeX < 5)
		{
			if (x + sizeX > WIDTH)
				break ;
			put_pixel_on_img(c, x + sizeX, y + sizeY, color);
			sizeX++;
		}
		sizeY++;
	}
}

void	mini_player(t_cubed *c, double x, double y)
{
	int	sizeX;
	int	sizeY;

	sizeX = (int)(x * 5 - 2);
	sizeY = (int)(y * 5 - 2);
	make_minimap(c, sizeX, sizeY, 65280);
}

void	draw_minimap(t_cubed *c)
{
	int		i;
	int		j;

	i = -1;
	while (c->map[++i])
	{
		j = -1;
		while (c->map[i][++j])
		{
			if (c->map[i][j] == '0')
				make_minimap(c, j * 5, i * 5, 0);
		}
	}
	mini_player(c, c->play_y, c->play_x);
	i = -1;
	while (c->map[++i])
	{
		j = -1;
		while (c->map[i][++j])
		{
			if (c->map[i][j] == '1')
				make_minimap(c, j * 5, i * 5, 16777215);
		}
	}
}
