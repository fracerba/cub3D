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

int check_char(char c)
{
    if(c == ' ')
        return(0);
	else if (c == '0' || c == '1')
		return (1);
    else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return(2);
    else
		return(-1);
}

void get_map_info(t_check *check)
{
	int i;
	int	j;
	int	l;

	check->height = mat_len(check->map);
	i = -1;
	l = 0;
	while(check->map[++i])
	{
		j = ft_strlen(check->map[i]);
		if(j > l)
			l = j;
	}
	check->width = l;
}

int check_map(t_check *check, int i, int j)
{
	while (check->map[++i])
	{
		j = -1;
		while(check->map[i][++j])
		{
			if(check_char(check->map[i][j]) == 2)
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

	ft_printf("---------------------------------\n");
    	print_matrix_nl(check->var);
	ft_printf("---------------------------------\n");
    	print_matrix_nl(check->map);
	ft_printf("---------------------------------\n");
	//free_matrix(check->copy);
	ft_printf("w=%i h=%i\n", check->width, check->height);

	return (0);
}

