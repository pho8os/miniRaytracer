/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 11:55:32 by absaid            #+#    #+#             */
/*   Updated: 2023/07/08 01:20:31 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_render.h"
#include <mlx.h>





void	init_new_size(t_mlx	*mlx, t_data *data)
{
	double angle;
	
	angle = data->cam->FOV * M_PI / 180;
	mlx->n_width = tan(angle / 2);
	mlx->n_height = 800 * mlx->n_width / 900;
	printf("NW->%f, NH->%f\n",mlx->n_width, mlx->n_height);
}

bool intersp(t_ray *ray, t_sphere *sp)
{
	double a, b, c;
	if(!sp)
		exit(-1);
	a = dot_prod(ray->direction, ray->direction);
	b = dot_prod(vecsub(ray->origin, sp->center), ray->direction) * 2;
	c = dot_prod(vecsub(ray->origin, sp->center), vecsub(ray->origin, sp->center)) - (sp->diam / 2) * (sp->diam / 2);
	double delta;
	delta = (b * b) - (4 * a * c);
	if(delta >= 0.000001)
		return (true);
	return(false);
}
void	rt_rendering(t_data *data)
{
	(void)data;
	t_mlx mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 900, 800, "minirt");
	int i , j = -1;
	init_new_size(&mlx, data);
	
	while(++j <= 800)
	{
		i = -1;
		while(++i <= 900)
		{
			t_ray *ray = gc(sizeof(t_ray), 1);
			ray = ft_ray(data->cam, i, j, &mlx, ray);
			// printf("%f ** %f ** %f \n", ray->direction.x, ray->direction.y, ray->direction.z);
			// int color =  ray->red << 16 | ray->green << 8 | 0;
			// printf("color : %x\t", color);
			if(intersp(ray, data->sph) == true)
				mlx_pixel_put(mlx.mlx, mlx.win, i, j, data->sph->color);
			// else
			// 	puts("no");
		}
	}
	// TODO : take the FOV and update the new width and the height * 4;
	// TODO : position of camera to send rays;

	mlx_loop(mlx.mlx);
}
