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
		return (print_error(4, 0));
	while (argv[i - 4 + j])
	{
		if (argv[i - 4 + j] != s[j])
			return (print_error(4, 0));
		j++;
	}
	return (1);
}

int	free_all(t_cubed *cube)
{
	if (cube->map)
		free_matrix(cube->map);
	if (cube->mlx)
	{
		ft_destroy_imgs(cube);
		if (cube->window)
			mlx_destroy_window(cube->mlx, cube->window);
		mlx_destroy_display(cube->mlx);
		free(cube->mlx);
	}
	exit(0);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_cubed	cube;

	if (argc > 2)
		return (print_error(1, 1));
	else if (argc < 2)
		return (print_error(2, 1));
	if (!ft_check_file(argv[1]))
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (print_error(3, 1));
	close(fd);
	cube.map = NULL;
	cube.mlx = NULL;
	cube.window = NULL;
	if (!get_map(&cube, argv[1], 0, 0))
		start_rendering(&cube);
	free_all(&cube);
	return (0);
}
