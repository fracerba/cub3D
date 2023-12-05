/* ************************************************************************** */
/*	                                                                          */
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

int	better_atoi(char *str)
{
	int	i;

	i = ft_atoi(str);
	if (i)
		return (i);
	else
	{
		if (ft_strlen(str) == 1 && !ft_strncmp(str, "0", 1))
			return (0);
		else
			return (-1);
	}
	return (0);
}

int	rgb_check(char *str, int i)
{
	int		r;
	int		g;
	int		b;
	char	**new;

	new = ft_split(str, ',');
	if (mat_len(new) != 3)
	{
		free_matrix(new);
		return (print_error(6, 1));
	}
	r = better_atoi(new[0]);
	g = better_atoi(new[1]);
	b = better_atoi(new[2]);
	free_matrix(new);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (print_error((29 + i), 1));
	return (0);
}

t_rgb	*rgb_assign(char *str)
{
	t_rgb	*new;
	int		r;
	int		g;
	int		b;
	char	**tmp;

	tmp = ft_split(str, ',');
	r = ft_atoi(tmp[0]);
	g = ft_atoi(tmp[1]);
	b = ft_atoi(tmp[2]);
	free_matrix(tmp);
	new = malloc(sizeof(t_rgb));
	if (!new)
		return (NULL);
	new->red = r;
	new->green = g;
	new->blue = b;
	return (new);
}
