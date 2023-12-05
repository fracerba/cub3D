/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:01:22 by fracerba          #+#    #+#             */
/*   Updated: 2023/12/04 12:01:24 by fracerba         ###   ########.fr       */
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

char	*better_strdup(char *str)
{
	char	*tmp;

	if (!str)
		return (NULL);
	if (!ft_strlen(str))
	{
		tmp = malloc(sizeof(char) * 1);
		tmp[0] = 0;
		return (tmp);
	}
	else
		return (ft_strdup(str));
}
