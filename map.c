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

    check = malloc(sizeof(t_check));
    check->map = NULL;
    check->var = NULL;
    check->copy = malloc(sizeof(char *) * (get_size(arg) + 1));
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

int	check_map_start(char *str)
{
	int i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '1' || str[i] == '0'))
		i++;
	if(!str[i])
		return(1);
	return (0);
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
    check->n_var++;
    return (0);
}

int check_var(t_check **check, int i, int j)
{
    char		**mat;
    char		*str;

	check->var = malloc(sizeof(char *) * 7);
	check->var[6] = NULL;
    while(check_map_start(check->copy[i]) && check->n_var < 6)
    {
        str = replace_spaces(check->copy[i]);
        mat = ft_split(str, ' ');
		free(str);
        if(mat_len(mat) != 2 || assign_var(mat, check));
            return (free_matrix(mat));
		free_matrix(mat);
		i++;
    }
	if(check->n_var != 6)
		return (1);
	j = mat_len(&check->copy[i])
	check->map = malloc(sizeof(char *) * (j + 1));
	j = 0;
	while(check->copy[i])
		check->map[j++] = ft_strdup(check->copy[i++]);
	check->map[j] = NULL;
	return(check_map(check));
}

int get_map(int fd, t_cubed **cube, char *arg)
{
    t_check *check;
    char    *tmp;
    int     i;
	int		j;

    check = init_check(arg);
    tmp = get_next_line(fd);
	i = 0;
    while (tmp)
    {
		j = skip_spaces(tmp);
        if(j > 0)
        	check->copy[i++] = ft_strdup(tmp);
        free(tmp);
        tmp = get_next_line(fd);
    }
    if(check_var(&check, 0, 0))
	{
		free_check(cube, check);
    	return (1);
	}
    free_check(cube, check);
    return (0);
}