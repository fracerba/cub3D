/* ************************************************************************** */
/*			                                                                  */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:45:57 by fracerba          #+#    #+#             */
/*   Updated: 2023/11/23 12:45:58 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	skip_spaces(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (!str[i])
		return (-1);
	return (i);
}

int	get_size(char *str)
{
	int		i;
	int		s;
	int		fd;
	char	*tmp;

	fd = open(str, O_RDONLY);
	tmp = trim_nl(get_next_line(fd));
	s = 0;
	i = 0;
	while (tmp)
	{
		if (!s && check_map_start(tmp))
			s = 1;
		if (!s && skip_spaces(tmp) >= 0)
			i++;
		else if (s)
			i++;
		free(tmp);
		tmp = trim_nl(get_next_line(fd));
	}
	close(fd);
	return (i);
}

char	*replace_spaces(char *tmp)
{
	char	*str;
	int		i;

	if (!tmp)
		return (NULL);
	str = ft_strdup(tmp);
	i = -1;
	while (str[++i])
	{
		if (str[i] >= 9 && str[i] <= 13)
			str[i] = ' ';
	}
	return (str);
}

int	free_var(char **mat)
{
	int	i;

	if (!mat)
		return (1);
	i = -1;
	while ((++i) < 7)
		free(mat[i]);
	free(mat);
	return (1);
}

char	*trim_nl(char *str)
{
	int		i;
	int		j;
	char	*new;

	if (!str)
		return (NULL);
	i = ft_strlen(str);
	if (str[i - 1] != '\n')
		return (str);
	new = malloc(i * sizeof(char));
	j = 0;
	while (j < (i - 1))
	{
		new[j] = str[j];
		j++;
	}
	new[j] = 0;
	free(str);
	return (new);
}
