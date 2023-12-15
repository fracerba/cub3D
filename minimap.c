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
	int	size_x;
	int	size_y;

	size_y = 0;
	while (size_y < 5)
	{
		size_x = 0;
		if (y + size_y > HEIGHT)
			break ;
		while (size_x < 5)
		{
			if (x + size_x > WIDTH)
				break ;
			put_pixel_on_img(c, x + size_x, y + size_y, color);
			size_x++;
		}
		size_y++;
	}
}

void	mini_player(t_cubed *c, double x, double y)
{
	int	size_x;
	int	size_y;

	size_x = (int)(x * 5 - 2);
	size_y = (int)(y * 5 - 2);
	make_minimap(c, size_x, size_y, 65280);
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
