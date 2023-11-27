/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:44:51 by fracerba          #+#    #+#             */
/*   Updated: 2023/11/27 09:44:53 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int rgb_compare(t_rgb a, t_rgb b)
{
    if(a.red == b.red)
        if(a.green == b.green)
            if(a.blue == b.blue)
                return(1);
    return(0);
}

t_rgb *rgb_assign(int r, int g, int b)
{
	t_rgb *new;

	if(r < 0 || r > 255)
	{
		ft_printf("Error\nThe rgb values are invalid!\n");
		return(NULL);
	}
	if(g < 0 || g > 255)
	{
		ft_printf("Error\nThe rgb values are invalid!\n");
		return(NULL);
	}
	if(b < 0 || b > 255)
	{
		ft_printf("Error\nThe rgb values are invalid!\n");
		return(NULL);
	}
	new = malloc(sizeof(t_rgb));
	if(!new)
		return(NULL);
	new->red = r;
	new->green = g;
	new->blue = b;
	return(new);
}

