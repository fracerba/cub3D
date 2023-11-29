/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:28:52 by fracerba          #+#    #+#             */
/*   Updated: 2023/11/27 10:28:54 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_check *init_check(char *arg)
{
    t_check *check;
	int i;

	i = get_size(arg);
	if(!i)
	{
		print_error(5, 0);
		return(NULL);
	}	
    check = malloc(sizeof(t_check));
    check->map = NULL;
    check->var = NULL;
    check->copy = malloc(sizeof(char *) * (i + 1));
    check->n_var = 0;
	check->map_start = 0;
    check->valid = 0;
	check->height = 0;
	check->width = 0;
    check->px = 0;
	check->py = 0;
	check->n_start = 0;
    return (check);
}

int free_check(t_check *check)
{
	if(!check)
    	return(1);
	if(check->copy)
		free_matrix(check->copy);
	if(check->map)
		free_matrix(check->map);
	if(check->var)
		free_var(check->var);
	free(check);
	return (1);
}

void set_cubed(t_cubed **cube, t_check *check)
{
	free(cube);
	free_check(check);
}

int get_map(t_cubed **cube, char *arg, int i, int fd)
{
    t_check	*check;
    char	*tmp;

    check = init_check(arg);
	if(!check)
		return (1);
    fd = open(arg, O_RDONLY);
    tmp = get_next_line(fd);
    while (tmp)
    {
		if(check_map_start(tmp) && !check->map_start)
			check->map_start = i;
		if(!check->map_start)
		{
			if(skip_spaces(tmp) >= 0)
				check->copy[i++] = ft_strdup(tmp);
		}
		else
			check->copy[i++] = ft_strdup(tmp);
        free(tmp);
        tmp = get_next_line(fd);
    }
    close(fd);
    if(check_var(check, 0))
		return (free_check(check));
	set_cubed(cube, check);
    return (0);
}