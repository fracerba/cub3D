/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:16:38 by fracerba          #+#    #+#             */
/*   Updated: 2023/11/29 15:16:40 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_char(char c)
{
	if (c == ' ')
		return (0);
	else if (c == '0' || c == '1')
		return (1);
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (2);
	else
		return (-1);
}

void	get_map_info(t_check *check)
{
	int	i;
	int	j;
	int	l;

	check->height = mat_len(check->map);
	i = -1;
	l = 0;
	while (check->map[++i])
	{
		j = ft_strlen(check->map[i]);
		if (j > l)
			l = j;
	}
	check->width = l;
}

int	check_var_xpm(char *var, int n)
{
	char	*s;
	int		i;
	int		j;

	i = ft_strlen(var);
	s = ".xpm";
	j = -1;
	if (i < 4)
		return (print_error((21 + n), 1));
	while (var[i - 4 + (++j)])
	{
		if (var[i - 4 + j] != s[j])
			return (print_error((21 + n), 1));
	}
	j = open(var, O_RDONLY);
	if (j < 0)
		return (print_error((25 + n), 1));
	close(j);
	return (0);
}

int	check_var_values(t_check *c)
{
	int	i;

	i = -1;
	while ((++i) < 4)
	{
		if (check_var_xpm(c->var[i], i))
			return (1);
	}
	if (rgb_check(c->var[i], 0) || rgb_check(c->var[i + 1], 1))
		return (1);
	return (0);
}

int	check_map(t_check *check, int i, int j)
{
	while (check->map[++i])
	{
		j = -1;
		while (check->map[i][++j])
		{
			if (check_char(check->map[i][j]) == 2)
			{
				check->px = i;
				check->py = j;
				check->n_start++;
			}
		}
	}
	if (check->n_start > 1)
		return (print_error(17, 1));
	else if (check->n_start < 1)
		return (print_error(16, 1));
	get_map_info(check);
	if (check_var_values(check))
		return (1);
	if (check_map_borders(check))
		return (1);
	return (0);
}
