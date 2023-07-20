/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 07:56:30 by absaid            #+#    #+#             */
/*   Updated: 2023/07/20 09:20:51 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parser.h"

static void	init_mlx_window(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "minirt");
	mlx->img->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->img->addr = mlx_get_data_addr(mlx->img->img, &mlx->img->bits_per_pixel, \
		&mlx->img->line_length, &mlx->img->endian);
	return ;
}

/* ************************************************************************** */
/*							TODO LIST										  */
/* ************************************************************************** */
/*
	// TODO : There are some maps that have an xpm file for texture
	// TODO :  'tx'...
	// TODO : Handle problem of parsing 255,,,,,255,255
	// TODO: Freeing the 3 double pointers?? parsecy(), parsepl()...
	// TODO: Freeing the pointer in the inner while?? rt_parsing
*/

int main(int ac, char **av)
{
	int		fd;
	t_data	data;
	t_utils	utils;
	t_img	img;
	t_mlx	mlx;

	if (ac != 2)
		ft_error("Invalid Arguments", 1, 0);
	fd = checkfile(av[1]);
	if (fd < 0)
		ft_error("Invalid File", 1, 0);
	initdata(&data);
	rt_parsing(&data, fd);
	check_ranges(&data);
	// printdata(&data);
	mlx.img = &img;
	init_mlx_window(&mlx);
	rt_rendering(&data, &utils, &mlx);
	return (0);
}
