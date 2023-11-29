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

void	print_matrix(char **mat)
{
	int	i;

	i = 0;
	if (!mat || !mat[i])
		return ;
	while (mat[i])
	{
		ft_printf("%s", mat[i]);
		i++;
	}
}

void	print_matrix_nl(char **mat)
{
	int	i;

	i = 0;
	if (!mat || !mat[i])
		return ;
	while (mat[i])
	{
		ft_printf("%s\n", mat[i]);
		i++;
	}
}

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
		new[i] = ft_strdup(mat[i]);
	new[i] = 0;
	return (new);
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
