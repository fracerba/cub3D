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
    if(c == '0' || c == '1' || c == ' ')
        return(0);
    else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return(1);
    else
		return(-1);
}

int check_map(t_check *check, int i, int j)
{
	i = -1;
	ft_printf("---------------------------------\n");
    	print_matrix_nl(check->var);
	ft_printf("---------------------------------\n");
    	print_matrix(check->map);
	free_matrix(check->copy);
	while (check->map[++i])
	{
		j = -1;
		while(check->map[i][++j])
		{
			if(check_char(check->map[i][j]) > 0)
			{
				check->px = i;
				check->py = j;
				check->n_start++;
			}
            else if(check_char(check->map[i][j]) < 0)
                return(print_error(100, 1));
		}
	}
	if (check->n_start > 1)
		return (print_error(5, 1));
	else if (check->n_start < 1)
		return (print_error(6, 1));
	return (0);
}

