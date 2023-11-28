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
    int red;
    int green;
    int blue;
}   t_rgb;

typedef struct s_check
{
    char	**map;
	char	**copy;
	char	*var[6];
	int		n_var;
	int		map_start;
    int		valid;
	int		height;
	int		width;
    int		px;
	int		py;
	int		n_start;
}   t_check;

typedef struct s_cubed
{
	void	*mlx;
	void	*window;
	char    **map;
	int		map_height;
	int		map_width;
	t_img   NO_wall;
    t_img	EA_wall;
    t_img	SO_wall;
    t_img	WE_wall;
	t_rgb	floor;
	t_rgb	ceiling;
    double	play_x;
	double	play_y;
	double	dir_x;
	double	dir_y;
	double	cam_x;
	double	cam_y;
	double	tngs[/*un botto fra!*/];
	int		frames;
}	t_cubed;


//cub3d.c
int	ft_check_file(char *argv);
int	main(int argc, char **argv);

//hooks.c

//rgb.c
int rgb_compare(t_rgb a, t_rgb b);

#endif
