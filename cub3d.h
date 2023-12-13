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

# define WIDTH 1920
# define HEIGHT 1080

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
	// int		valid;
	int		height;
	int		width;
	int		px;
	int		py;
	int		n_start;
}	t_check;

typedef struct s_ray
{
	double	camera;
	double	ray_x;
	double	ray_y;
	int		map_x;
	int		map_y;
	double	dist_x;
	double	dist_y;
	double	delta_x;
	double	delta_y;
	double	wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line;
	int		d_start;
	int		d_end;
	double	wall_pos;
	// int		text_n;
	int		text_x;
	int		text_y;
	double	step;
	double	text_pos;
	t_img	img;
}	t_ray;

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
	int		int_f;
	int		int_c;
	double	play_x;
	double	play_y;
	char	dir_s;
	double	dir_x;
	double	dir_y;
	double	cam_x;
	double	cam_y;
	double	m_speed;
	double	r_speed;
	double	tngs[4];
	int		frames;
	t_img	screen;
}	t_cubed;

//cub3d.c
int		ft_check_file(char *argv);
int		free_all(t_cubed *cube);
int		main(int argc, char **argv);

//error.c
void	print_error3(int i);
void	print_error2(int i);
int		print_error(int i, int e);

//hooks.c

//img.c
void	ft_destroy_imgs(t_cubed *cube);
void	get_img(t_cubed *c, t_img *img, char *path);

//map.c
t_check	*init_check(char *arg);
int		free_check(t_check *check);
int		set_cubed(t_cubed *cube, t_check *check);
int		get_map(t_cubed *cube, char *arg, int i, int fd);

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
int		check_map_block(t_check *check, int i, int j, int *t);
int		check_map_borders_aux(t_check *check, int i, int j, int *t);
int		check_map_borders(t_check *check);

//map5.c
int		check_outer_block(t_check *check, int i, int j, int *t);
int		check_map_outer_aux(t_check *check, int i, int j, int *t);
int		find_first_space(int *x, int *y, char **copy);
int		check_map_outer_borders(t_check *check, int x, int y, int t);

//matrix.c
int		mat_len(char **mat);
char	**dup_matrix(char **mat);
char	**check_dup_aux(char **mat, int i);
char	**check_dup_matrix(char **mat);
int		free_matrix(char **mat);

//movement.c
void	rotate_right(t_cubed *c);
void	rotate_left(t_cubed *c);
int		check_keys(int key);
int		ft_move(int key, t_cubed *c);

//movement2.c
void	move_forward(t_cubed *cube, char **map, int x, int y);
void	move_backwards(t_cubed *cube, char **map, int x, int y);
void	move_left(t_cubed *cube, char **map, int x, int y);
void	move_right(t_cubed *cube, char **map, int x, int y);

//raycast1.c
void	set_direction(t_cubed *cube);
void	init_cubed(t_cubed *cube);
int		frame_render(t_cubed *cube);
void	start_rendering(t_cubed *cube);

//raycast2.c
void	init_ray_aux(t_ray *r, t_cubed *c);
void	init_ray(t_ray *r, t_cubed *c, int x);
void	draw_floor(t_cubed *c);
void	draw_ceiling(t_cubed *c);
void	start_raycast(t_cubed *c);

//raycast3.c
void	render_distance(t_ray *r, t_cubed *c);
void	get_texture(t_ray *r, t_cubed *c);
void	render_line(t_ray *r, t_cubed *c);
void	draw_line(t_ray *r, t_cubed *c, int x);

//rgb.c
int		better_atoi(char *str);
int		rgb_check(char *str, int i);
t_rgb	rgb_assign(char *str);
int		rgb_convert(t_rgb r);

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
