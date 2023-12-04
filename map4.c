/* ************************************************************************** */
/*                                                                            */
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
    int i;
    int j;

    i = -1;
	free_matrix(check->copy);
    check->copy = malloc(sizeof(char *) * (check->height + 3));
    while((++i) < (check->height + 2))
	{
		check->copy[i] = malloc(sizeof(char) * (check->width + 3));
		j = -1;
		while ((++j) < (check->width + 3))
			check->copy[i][j] = ' ';
		check->copy[i][j] = 0;
	}
	check->copy[i] = NULL;
	i = -1;
	while(check->map[++i])
	{
		j = -1;
		while (check->map[i][++j])
			check->copy[i + 1][j + 1] = check->map[i][j];
	}
	check->px++;
	check->py++;
}

int	check_map_borders(t_check *check)
{
	set_map_copy(check);
	ft_printf("---------------------------------\n");
		print_matrix_nl(check->var);
	ft_printf("---------------------------------\n");
		print_matrix_nl(check->map);
		ft_printf("w=%i h=%i\n", check->width, check->height);
	ft_printf("---------------------------------\n");
		print_matrix_nl(check->copy);
		ft_printf("x=%i y=%i c=%c\n", check->px, check->py, check->copy[check->px][check->py]);
	ft_printf("---------------------------------\n");
	return(0);
}