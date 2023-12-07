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

t_check	*init_check(char *arg)
{
	t_check	*check;
	int		i;

	i = get_size(arg);
	if (!i)
	{
		print_error(5, 0);
		return (NULL);
	}
	check = malloc(sizeof(t_check));
	check->map = NULL;
	check->var = NULL;
	check->copy = malloc(sizeof(char *) * (i + 1));
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

int	free_check(t_check *check)
{
	if (!check)
		return (1);
	if (check->copy)
		free_matrix(check->copy);
	if (check->map)
		free_matrix(check->map);
	if (check->var)
		free_var(check->var);
	free(check);
	return (1);
}

void	set_direction(t_cubed *cube)
{
	if (cube->dir_s == 'N')
		cube->dir_x = -1;
	else if (cube->dir_s == 'E' || cube->dir_s == 'W')
		cube->dir_x = 0;
	else if (cube->dir_s == 'S')
		cube->dir_x = 1;
	if (cube->dir_s == 'N' || cube->dir_s == 'S')
		cube->dir_y = 0;
	else if (cube->dir_s == 'E')
		cube->dir_y = 1;
	else if (cube->dir_s == 'W')
		cube->dir_y = -1;
	if (cube->dir_s == 'N' || cube->dir_s == 'S')
		cube->cam_x = 0;
	else if (cube->dir_s == 'E')
		cube->cam_x = 0.6;
	else if (cube->dir_s == 'W')
		cube->cam_x = -0.6;
	if (cube->dir_s == 'N')
		cube->cam_y = 0.6;
	else if (cube->dir_s == 'E' || cube->dir_s == 'W')
		cube->cam_y = 0;
	else if (cube->dir_s == 'S')
		cube->cam_y = -0.6;
}

int	set_cubed(t_cubed *cube, t_check *check)
{
	cube->map = dup_matrix(check->map);
	cube->map_height = check->height;
	cube->map_width = check->width;
	cube->mlx = mlx_init();
	if (!cube->mlx)
	{
		free_check(check);
		return(print_error(31, 1));
	}
	get_img(cube, &cube->north, check->var[0]);
	get_img(cube, &cube->east, check->var[1]);
	get_img(cube, &cube->south, check->var[2]);
	get_img(cube, &cube->west, check->var[3]);
	cube->play_x = (double)(check->px) - 0.5;
	cube->play_y = (double)(check->py) - 0.5;
	cube->floor = rgb_assign(check->var[4]);
	cube->ceiling = rgb_assign(check->var[5]);
	cube->dir_s = check->map[check->px - 1][check->py - 1];
	set_direction(cube);
	cube->frames = 0;
	free_check(check);
	return (0);
}

int	get_map(t_cubed *cube, char *arg, int i, int fd)
{
	t_check	*check;
	char	*tmp;

	check = init_check(arg);
	if (!check)
		return (1);
	fd = open(arg, O_RDONLY);
	tmp = trim_nl(get_next_line(fd));
	while (tmp)
	{
		if (!check->map_start && check_map_start(tmp))
			check->map_start = 1;
		if (!check->map_start && skip_spaces(tmp) >= 0)
			check->copy[i++] = better_strdup(tmp);
		else if (check->map_start)
			check->copy[i++] = better_strdup(tmp);
		free(tmp);
		tmp = trim_nl(get_next_line(fd));
	}
	check->copy[i] = NULL;
	close(fd);
	if (check_var(check, 0))
		return (free_check(check));
	return (set_cubed(cube, check));
}
