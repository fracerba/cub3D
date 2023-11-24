/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:06:10 by fracerba          #+#    #+#             */
/*   Updated: 2023/11/20 10:06:13 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_file(char *argv)
{
	char	*s;
	int		i;
	int		j;

	i = ft_strlen(argv);
	j = 0;
	s = ".cub";
	if (i < 4)
	{
		ft_printf("Error\nIl file passato non e' un file \".cub\"");
		return (0);
	}
	while (argv[i - 4 + j])
	{
		if (argv[i - 4 + j] != s[j])
		{
			ft_printf("Error\nIl file passato non e' un file \".cub\"");
			return (0);
		}
		j++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	fd;
	t_cubed *cube;

	if (argc != 2)
	{
		if (argc > 2)
			ft_printf("Error!\nToo many arguments!\n");
		else
			ft_printf("Error!\nNot enough arguments!\n");
		return (1);
	}
	if (!ft_check_file(argv[1]))
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error!\nThe file doesn't exist!\n");
		return (1);
	}
	get_map(fd, &cube);
	start_raycast(cube);
	return (0);
}
