/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 11:55:32 by absaid            #+#    #+#             */
/*   Updated: 2023/07/09 06:18:17 by absaid           ###   ########.fr       */
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

bool intersp(t_ray *ray, t_sphere *sp, t_solution T)
{
	double a, b, c;
	if(!sp)
		exit(-1);
	a = dot_prod(ray->direction, ray->direction);
	b = dot_prod(vecsub(ray->origin, sp->center), ray->direction) * 2;
	c = dot_prod(vecsub(ray->origin, sp->center), vecsub(ray->origin, sp->center)) - (sp->diam / 2) * (sp->diam / 2);
	double delta;
	delta = (b * b) - (4 * a * c);
	if(delta > 0.000001)
	{
		double t1 = (-b + sqrt(delta)) / 2 * a;
		double t2 = (-b - sqrt(delta)) / 2 * a;
		return((t2 > t1) * t1 + (t1 > t2) * t2);
	}
	if(delta >= 0.000001)
		return(true);
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
	t_solution T;
	T.t = -1;
	T.color = data->amlight->color;
	while(++j <= 800)
	{
		i = -1;
		while(++i <= 900)
		{
			t_sphere *sphere = data->sph;
			t_ray *ray = gc(sizeof(t_ray), 1);
			ray = ft_ray(data->cam, i, j, &mlx, ray);
			// int color =  ray->red << 16 | ray->green << 8 | 0;
			while(sphere)
			{
				if(intersp(ray, sphere, T))
					mlx_pixel_put(mlx.mlx, mlx.win, i, j, T.color);
				sphere = sphere->next;
			}
		}
	}
	// TODO : take the FOV and update the new width and the height * 4;
	// TODO : position of camera to send rays;

	mlx_loop(mlx.mlx);
}
