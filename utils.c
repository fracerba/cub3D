/* ************************************************************************** */
/*	                                                                          */
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

int skip_spaces(char *str)
{
	int i;

	i = 0;
	if(!str)
		return (0);
	while (str[i] && str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if(!str[i])
		return (-1);
	return (i);
}

int get_size(char *str)
{
	int		i;
	int		fd;
	char	*tmp;

	fd = open(str, O_RDONLY);
	tmp = get_next_line(fd);
	i = 0;
    while (tmp)
    {
        if(skip_spaces(tmp) > 0)
        	i++;
        free(tmp);
        tmp = get_next_line(fd);
	}
	return (i);	
}

char	*replace_spaces(char *tmp)
{
	char *str;
	int i;

	if(!tmp)
		return (NULL);
	str = ft_strdup(tmp);
	i = -1;
	while (str[++i])
	{
		if(str[i] >= 9 && str[i] <= 13)
			str[i] = ' ';
	}
	return (str);
}