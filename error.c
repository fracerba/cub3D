/* ************************************************************************** */
/*	                                                                          */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:29:50 by fracerba          #+#    #+#             */
/*   Updated: 2023/11/29 11:29:52 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void print_error3(int i)
{
	if(i == 23)
		ft_printf("Error\nThe image for SO isn't a \".xpm\" file!\n");
	else if(i == 24)
		ft_printf("Error\nThe image for WE isn't a \".xpm\" file!\n");
	else if(i == 25)
		ft_printf("Error\nThe file with texture for NO doesn't exist!\n");
	else if(i == 26)
		ft_printf("Error\nThe file with texture for EA doesn't exist!\n");
	else if(i == 27)
		ft_printf("Error\nThe file with texture for SO doesn't exist!\n");
	else if(i == 28)
		ft_printf("Error\nThe file with texture for WE doesn't exist!\n");
	else if(i == 29)
		ft_printf("Error\nThe rgb values for F are invalid!\n");
	else if(i == 30)
		ft_printf("Error\nThe rgb values for C are invalid!\n");
	// else if(i == 31)
	// 	ft_printf("Error\nThe image for isn't a \".xpm\" file!\n");
	// else if(i == 32)
	// 	ft_printf("Error\nThe file isn't a \".cub\" file!\n");
	// else if(i == 33)
	// 	ft_printf("Error\nThe rgb values for F are invalid!\n");
	// else if(i == 34)
	// 	ft_printf("Error\nThe rgb values for C are invalid!\n");
}

void print_error2(int i)
{
	if(i == 12)
		ft_printf("Error\nC is declared twice!!\n");
	else if(i == 13)
		ft_printf("Error\nNot all the elements have been declared before the map!\n");
	else if(i == 14)
		ft_printf("Error\nThe map is absent!\n");
	else if(i == 15)
		ft_printf("Error\nThere are invalid characters in the map!\n");
	else if(i == 16)
		ft_printf("Error\nNo starting points in the map!\n");
	else if(i == 17)
		ft_printf("Error\nMultiple starting points in the map!\n");
	else if(i == 18)
		ft_printf("Error\nThe map isn't closed!\n");
	else if(i == 19)
		ft_printf("Error\nThe map isn't surrounded by walls!\n");
	else if(i == 20)
		ft_printf("Error\nThere are informations after the map!\n");
	else if(i == 21)
		ft_printf("Error\nThe image for NO isn't a \".xpm\" file!\n");
	else if(i == 22)
		ft_printf("Error\nThe image for EA isn't a \".xpm\" file!\n");
	else if(i >= 23)
		print_error3(i);
}

int print_error(int i, int e)
{
	if(i == 1)
		ft_printf("Error!\nToo many arguments!\n");
	else if(i == 2)
		ft_printf("Error!\nNot enough arguments!\n");
	else if(i == 3)
		ft_printf("Error!\nThe file doesn't exist!\n");
	else if(i == 4)
		ft_printf("Error\nThe file isn't a \".cub\" file!\n");
	else if(i == 5)
		ft_printf("Error\nThe file is empty!\n");
	else if(i == 6)
		ft_printf("Error\nThere is an invalid declaration!\n");
	else if(i == 7)
		ft_printf("Error\nNO is declared twice!\n");
	else if(i == 8)
		ft_printf("Error\nEA is declared twice!\n");
	else if(i == 9)
		ft_printf("Error\nSO is declared twice!\n");
	else if(i == 10)
		ft_printf("Error\nWE is declared twice!\n");
	else if(i == 11)
		ft_printf("Error\nF is declared twice!\n");
	else if(i >= 12)
		print_error2(i);
	return (e);
}
