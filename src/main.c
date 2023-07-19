/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 07:56:30 by absaid            #+#    #+#             */
/*   Updated: 2023/07/19 08:33:12 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int checkfile(char *file)
{
	int len;

	len = ft_strlen(file) - 3;
	if (ft_strncmp(file + len, ".rt", 3))
		return (-1);
	return (open(file, O_RDONLY));
}

// Initilizes mlx params;
void	initdata(t_data *data)
{
	data->amlight = NULL;
	data->cam = NULL;
	data->cyl = NULL;
	data->pl = NULL;
	data->sph = NULL;
	data->lights = NULL;
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
void	init_mlx_window(t_utils *utils)
{
	utils->mlx.mlx = mlx_init();
	utils->mlx.win = mlx_new_window(utils->mlx.mlx, WIDTH, HEIGHT, "minirt");
	utils->mlx.img->img = mlx_new_image(utils->mlx.mlx, WIDTH, HEIGHT);
	utils->mlx.img->addr = mlx_get_data_addr(utils->mlx.img->img, &utils->mlx.img->bits_per_pixel, \
		&utils->mlx.img->line_length, &utils->mlx.img->endian);
}

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	int		fd;
	t_data	data;
	t_utils	utils;
	t_img	img;

	if (ac != 2)
		ft_error("Invalid Arguments", 1, 0);
	fd = checkfile(av[1]);
	if (fd < 0)
		ft_error("Invalid File", 1, 0);
	initdata(&data);
	rt_parsing(&data, fd);
	check_ranges(&data);
	// printdata(&data);
	utils.mlx.img = &img;
	init_mlx_window(&utils);
	rt_rendering(&data, &utils);
}
