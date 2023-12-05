/* ************************************************************************** */
/*		                                                                      */
/*                                                        :::      ::::::::   */
/*   map4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:59:01 by fracerba          #+#    #+#             */
/*   Updated: 2023/12/04 11:59:03 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_map_copy(t_check *check)
{
	int	i;
	int	j;

	i = -1;
	free_matrix(check->copy);
	check->copy = malloc(sizeof(char *) * (check->height + 3));
	while ((++i) < (check->height + 2))
	{
		check->copy[i] = malloc(sizeof(char) * (check->width + 3));
		j = -1;
		while ((++j) < (check->width + 2))
			check->copy[i][j] = ' ';
		check->copy[i][j] = 0;
	}
	check->copy[i] = NULL;
	i = -1;
	while (check->map[++i])
	{
		j = -1;
		while (check->map[i][++j])
			check->copy[i + 1][j + 1] = check->map[i][j];
	}
	check->px++;
	check->py++;
}

int	check_map_block(t_check *check, int i, int j, int *t)
{
	if (check->copy[i][j] == ' ')
		return (print_error(18, 1));
	else if (check->copy[i][j] == '0')
	{
		check->copy[i][j] = '3';
		(*t)++;
	}
	else if (check->copy[i][j] != '1' && check->copy[i][j] != '2')
	{
		if (check->copy[i][j] != '3')
			return (print_error(15, 1));
	}
	return (0);
}

int	check_map_borders_aux(t_check *check, int i, int j, int *t)
{
	if (check_map_block(check, i, j + 1, t))
		return (1);
	else if (check_map_block(check, i, j - 1, t))
		return (1);
	else if (check_map_block(check, i + 1, j, t))
		return (1);
	else if (check_map_block(check, i - 1, j, t))
		return (1);
	check->copy[i][j] = '2';
	(*t)--;
	return (0);
}

int	check_map_borders(t_check *check)
{
	int	i;
	int	j;
	int	t;

	set_map_copy(check);
	check->copy[check->px][check->py] = '3';
	t = 1;
	if (check_map_borders_aux(check, check->px, check->py, &t))
		return (1);
	while (t > 0)
	{
		i = 0;
		while ((++i) < (check->height + 2))
		{
			j = 0;
			while ((++j) < (check->width + 2))
			{
				if (check->copy[i][j] == '3')
					if (check_map_borders_aux(check, i, j, &t))
						return (1);
			}
		}
	}
	return (check_map_outer_borders(check, 0, 0, 0));
}
