/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:08:24 by fracerba          #+#    #+#             */
/*   Updated: 2023/12/05 11:08:26 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_outer_block(t_check *check, int i, int j, int *t)
{
	if (check->copy[i][j] == '0' || check->copy[i][j] == '2')
		return (print_error(19, 1));
	else if (check->copy[i][j] == ' ')
	{
		check->copy[i][j] = '3';
		(*t)++;
	}
	else if (check->copy[i][j] != '1' && check->copy[i][j] != '3')
	{
		if (check->copy[i][j] != '4')
			return (print_error(15, 1));
	}
	return (0);
}

int	check_map_outer_aux(t_check *check, int i, int j, int *t)
{
	if (j != (check->width + 1) && check_outer_block(check, i, j + 1, t))
		return (1);
	else if (j != 0 && check_outer_block(check, i, j - 1, t))
		return (1);
	else if (i != (check->height + 1) && check_outer_block(check, i + 1, j, t))
		return (1);
	else if (i != 0 && check_outer_block(check, i - 1, j, t))
		return (1);
	check->copy[i][j] = '4';
	(*t)--;
	return (0);
}

int	find_first_space(int *x, int *y, char **copy)
{
	int	i;
	int	j;

	i = -1;
	while (copy[++i])
	{
		j = -1;
		while (copy[i][++j])
		{
			if (copy[i][j] == ' ')
			{
				*x = i;
				*y = j;
				return (1);
			}
		}
	}
	return (0);
}

int	check_map_outer_borders(t_check *check, int x, int y, int t)
{
	int	i;
	int	j;

	while (find_first_space(&x, &y, check->copy))
	{
		check->copy[x][y] = '3';
		t = 1;
		if (check_map_outer_aux(check, x, y, &t))
			return (1);
		while (t > 0)
		{
			i = -1;
			while ((++i) < (check->height + 2))
			{
				j = -1;
				while ((++j) < (check->width + 2))
				{
					if (check->copy[i][j] == '3')
						if (check_map_outer_aux(check, i, j, &t))
							return (1);
				}
			}
		}
	}
	return (0);
}
