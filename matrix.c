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
		return (NULL);
	i = 0;
	while (mat[i])
		i++;
	return (i);
}

char	**dup_matrix(char **mat)
{
	int		i;
	int		j;
	char	**new;

	if (!mat)
		return (NULL);
	i = mat_len(mat);
	new = malloc((i + 1) * sizeof(char *));
	i = -1;
	while (mat[++i])
		new[i] = ft_strdup(mat[i]);
	new[i] = 0;
	return (new);
}

int	free_matrix(char **mat)
{
	int	i;

	if (!mat)
		return ;
	i = -1;
	while (mat[++i])
		free(mat[i]);
	free(mat);
	return (1);
}
