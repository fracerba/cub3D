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

typedef struct s_cubed
{
	void	*mlx;
	void	*window;
	char    **map;
	t_img   NO_wall;
    t_img	EA_wall;
    t_img	SO_wall;
    t_img	WE_wall;
	t_rgb	floor;
	t_rgb	ceiling;
    float   px;
    float   py;
    float   direction;
    float   tangenti[/*un botto fra!*/];
}	t_cubed;


//cub3d.c
int	ft_check_file(char *argv);
int	main(int argc, char **argv);

//hooks.c

//utils.c
int rgb_compare(t_rgb a, t_rgb b);

#endif
