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
	check->map_start = 0;
    check->valid = 0;
	check->height = 0;
	check->width = 0;
    check->px = 0;
	check->py = 0;
	check->n_start = 0;
    return (check);
}

int assign_var(char **mat, t_check **check)
{
    if (!ft_strncmp(mat[0], "NO", 2) && (ft_strlen(mat[0]) == 2))
        check->var[0] = ft_strdup(mat[1]);
    else if (!ft_strncmp(mat[0], "EA", 2) && (ft_strlen(mat[0]) == 2))
        check->var[1] = ft_strdup(mat[1]);
    else if (!ft_strncmp(mat[0], "SO", 2) && (ft_strlen(mat[0]) == 2))
        check->var[2] = ft_strdup(mat[1]);
    else if (!ft_strncmp(mat[0], "WE", 2) && (ft_strlen(mat[0]) == 2))
        check->var[3] = ft_strdup(mat[1]);        
    else if (!ft_strncmp(mat[0], "F", 2) && (ft_strlen(mat[0]) == 1))
        check->var[4] = ft_strdup(mat[1]);       
    else if (!ft_strncmp(mat[0], "C", 2) && (ft_strlen(mat[0]) == 1))
        check->var[5] = ft_strdup(mat[1]);
    else
        return(1);
    check->var++;
    return (0);
}

int check_var(chat *tmp, t_check **check, int fd, char *arg)
{
    char		**mat;
    char		*str;
    int         i;
	int			j;

    if(check_map_start(tmp, **check))
    {
        str = replace_spaces(tmp);
        mat = ft_split(str, ' ');
        if(mat_len(mat) != 2)
            return(1);
        if(assign_var(mat, check));
            return (1);
    }
    else
    {
        i = get_map_size(arg, check->map_start);
		check->map = malloc(sizeof(char *) * (i + 1));
		j = 0;
        while(i > j)
        {
			check->map[j++] = ft_strdup(tmp);
			free(tmp);
			tmp = get_next_line(fd);
        }
		free(tmp)
    }
	return(0);
}

int get_map(int fd, t_cubed **cube, char *arg)
{
    t_check *check;
    char    *tmp;
    int     i;

    check = init_check();
    tmp = get_next_line(fd);
    while (tmp)
    {
        if(skip_spaces(tmp) > 0)
            if(check_var(tmp, &check, fd, arg))
                break ;
        else
            free(tmp);
        tmp = get_next_line(fd);
    }
    free(tmp);
    i = check->valid;
    free_check(cube, check, fd);
    return (i);
}