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

t_check *init_check()
{
    t_check *check;

    check = malloc(sizeof(t_check));
    check->map = NULL;
    check->copy = NULL;
    check->var = malloc(sizeof(char *) * 6);
    check->n_var = 0;
	check->map = 0;
    check->valid = 0;
	check->height = 0;
	check->width = 0;
    check->px = 0;
	check->py = 0;
	check->n_start = 0;
    return (check);
}


int get_map(int fd, t_cubed **cube)
{
    t_check *check;
    char *tmp;
    int i;

    check = init_check();
    tmp = getnextline(fd);
    while (tmp)
    {
        if(skip_spaces(tmp) > 0)
        {
            check_var(tmp);
        }
        else
            free(tmp);
        tmp = getnextline(fd);
    }
    i = check->valid;
    free_check(cube, check, fd);
    return (i);
}