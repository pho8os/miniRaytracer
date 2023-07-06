/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 11:55:32 by absaid            #+#    #+#             */
/*   Updated: 2023/07/06 16:51:21 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_render.h"
#include <mlx.h>





void	init_new_size(t_mlx	*mlx, t_data *data)
{
	double angle;
	
	angle = data->cam->FOV * M_PI / 180;
	mlx->n_width = tan(angle / 2);
	mlx->n_height = 400 * mlx->n_width / 450;
	printf("NW->%f, NH->%f\n",mlx->n_width, mlx->n_height);
}
void	rt_rendering(t_data *data)
{
	(void)data;
	t_mlx mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 900, 800, "minirt");
	int i , j = -1;
	
	while(++j <= 800)
	{
		i = -1;
		while(++i <= 900)
		{
			t_ray ray;
			ray = ft_ray(data->cam, i, j, &mlx);
			int color =  ray.red << 16 | ray.green << 8 | 0;
			// printf("color %x\n", color);
			mlx_pixel_put(mlx.mlx, mlx.win, i, j, color);
		}
	}
	// TODO : take the FOV and update the new width and the height * 4;
	// TODO : position of camera to send rays;
	init_new_size(&mlx, data);

	mlx_loop(mlx.mlx);
}
