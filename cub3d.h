/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:06:17 by fracerba          #+#    #+#             */
/*   Updated: 2023/11/20 10:06:19 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"

typedef struct s_img
{
	void	*img;
	char	*path;
	int		line;
	int		end;
	int		height;
	int		lenght;
	int		bits;
}	t_img;

typedef struct s_rgb
{
	int		red;
	int		green;
	int		blue;
}	t_rgb;

typedef struct s_check
{
	char	**map;
	char	**copy;
	char	**var;
	int		n_var;
	int		map_start;
	int		valid;
	int		height;
	int		width;
	int		px;
	int		py;
	int		n_start;
}	t_check;

typedef struct s_cubed
{
	void	*mlx;
	void	*window;
	char	**map;
	int		map_height;
	int		map_width;
	t_img	north;
	t_img	east;
	t_img	south;
	t_img	west;
	t_rgb	floor;
	t_rgb	ceiling;
	double	play_x;
	double	play_y;
	double	dir_x;
	double	dir_y;
	double	cam_x;
	double	cam_y;
	//double	tngs[/*un botto fra!*/];
	int		frames;
}	t_cubed;

//cub3d.c
int		ft_check_file(char *argv);
void	free_all(t_cubed *cube);
int		main(int argc, char **argv);

//error.c
void	print_error3(int i);
void	print_error2(int i);
int		print_error(int i, int e);

//hooks.c


//map.c
t_check	*init_check(char *arg);
int		free_check(t_check *check);
void	set_cubed(t_cubed **cube, t_check *check);
int		get_map(t_cubed **cube, char *arg, int i, int fd);

//map2.c
void	init_var(t_check *check);
int		check_map_start(char *str);
int		assign_var_aux(char *str, t_check *check, int i);
int		assign_var(char **mat, t_check *check);
int		check_var(t_check *check, int i);

//map3.c
int		check_char(char c);
void	get_map_info(t_check *check);
int		check_var_xpm(char *var, int n);
int		check_var_values(t_check *check);
int		check_map(t_check *check, int i, int j);

//map4.c
void	set_map_copy(t_check *check);
int		check_map_borders(t_check *check);

//matrix.c
int		mat_len(char **mat);
char	**dup_matrix(char **mat);
char	**check_dup_aux(char **mat, int i);
char	**check_dup_matrix(char **mat);
int		free_matrix(char **mat);

//rgb.c
int		better_atoi(char *str);
int		rgb_check(char *str, int i);
t_rgb	*rgb_assign(char *str);

//utils.c
int		skip_spaces(char *str);
int		get_size(char *str);
char	*replace_spaces(char *tmp);
int		free_var(char **mat);
char	*trim_nl(char *str);

//utils2.c
void	print_matrix(char **mat);
void	print_matrix_nl(char **mat);
char	*better_strdup(char *str);

#endif
