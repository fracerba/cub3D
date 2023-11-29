/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:13:45 by fracerba          #+#    #+#             */
/*   Updated: 2023/11/29 15:13:48 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_var(t_check *check)
{
    check->var = malloc(sizeof(char *) * 7);
    check->var[0] = NULL;
    check->var[1] = NULL;
    check->var[2] = NULL;
    check->var[3] = NULL;
    check->var[4] = NULL;
    check->var[5] = NULL;
	check->var[6] = NULL;
}

int	check_map_start(char *str)
{
	int i;

	i = 0;
	while (str[i] && check_char(str[i]) >= 0)
		i++;
	if(!str[i])
		return(1);
	return (0);
}

int assign_var_aux(char *str, t_check *check, int i)
{
    if(!check->var[i])
    {
        check->var[i] = ft_strdup(str);
        check->n_var++;
	}
    else
		return(print_error(i + 7, 1));
    return (0);
}

int assign_var(char **mat, t_check *check)
{
    if (!ft_strncmp(mat[0], "NO", 2) && (ft_strlen(mat[0]) == 2))
        return(assign_var_aux(mat[1], check, 0));
    else if (!ft_strncmp(mat[0], "EA", 2) && (ft_strlen(mat[0]) == 2))
        return(assign_var_aux(mat[1], check, 1));
    else if (!ft_strncmp(mat[0], "SO", 2) && (ft_strlen(mat[0]) == 2))
        return(assign_var_aux(mat[1], check, 2));
    else if (!ft_strncmp(mat[0], "WE", 2) && (ft_strlen(mat[0]) == 2))
        return(assign_var_aux(mat[1], check, 3));       
    else if (!ft_strncmp(mat[0], "F", 2) && (ft_strlen(mat[0]) == 1))
        return(assign_var_aux(mat[1], check, 4));      
    else if (!ft_strncmp(mat[0], "C", 2) && (ft_strlen(mat[0]) == 1))
        return(assign_var_aux(mat[1], check, 5));
    else
        return(print_error(6, 1));
    return (0);
}

int check_var(t_check *check, int i)
{
    char		**mat;
    char		*str;

	init_var(check);
    while(check->copy[i] && !check_map_start(check->copy[i]))
    {
        str = replace_spaces(check->copy[i]);
        mat = ft_split(str, ' ');
		free(str);
        if(mat_len(mat) != 2)
            return (print_error(6, free_matrix(mat)));
        if(assign_var(mat, check))
            return (free_matrix(mat));
		free_matrix(mat);
		i++;
    }
    if(!check->copy[i])
		return (print_error(14, 1));
	if(check->n_var < 6)
		return (print_error(13, 1));
	check->map = dup_matrix(&check->copy[i]);
	return(check_map(check, -1, -1));
}