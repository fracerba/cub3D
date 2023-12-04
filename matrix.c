/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:55:38 by fracerba          #+#    #+#             */
/*   Updated: 2023/11/27 09:55:40 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mat_len(char **mat)
{
	int	i;

	if (!mat)
		return (0);
	i = 0;
	while (mat[i])
		i++;
	return (i);
}

char	**dup_matrix(char **mat)
{
	int		i;
	char	**new;

	if (!mat)
		return (NULL);
	i = mat_len(mat);
	new = malloc((i + 1) * sizeof(char *));
	i = -1;
	while (mat[++i])
		new[i] = better_strdup(mat[i]);
	new[i] = 0;
	return (new);
}

char	**check_dup_aux(char **mat, int i)
{
	int 	j;
	char	**new;

	j = i;
	while (mat[i])
	{
		if (skip_spaces(mat[i]) >= 0)
		{
			print_error(20, 1);
			return (NULL);
		}
		i++;
	}
	new = malloc((j + 1) * sizeof(char *));
	i = -1;
	while (j > (++i))
		new[i] = better_strdup(mat[i]);
	new[i] = 0;
	return (new);
}

char	**check_dup_matrix(char **mat)
{
	int 	i;

	if(!mat)
		return(NULL);
	i = -1;
	while (mat[++i])
	{
		if(!check_map_start(mat[i]) || skip_spaces(mat[i]) < 0)
			break;
	}
	if(!mat[i])
		return(dup_matrix(mat));
	else if(skip_spaces(mat[i]) < 0)
		return(check_dup_aux(mat, i));
	else if(!check_map_start(mat[i]))
	{
		print_error(15, 1);
		return (NULL);
	}
	return(NULL);
}

int	free_matrix(char **mat)
{
	int	i;

	if (!mat)
		return (1);
	i = -1;
	while (mat[++i])
		free(mat[i]);
	free(mat);
	return (1);
}
