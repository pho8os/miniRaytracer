/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 11:55:32 by absaid            #+#    #+#             */
/*   Updated: 2023/07/10 01:52:46 by absaid           ###   ########.fr       */
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

void interpl(t_ray *ray, t_plane *pl, t_solution *T)
{
	double t;
	(void)T;

	t = 1 / (dot_prod(ray->direction, pl->nvec)) * (dot_prod(pl->point, pl->nvec) - dot_prod(ray->origin, pl->nvec));
	// ((t < T->t || T->t == -1) && t > EPS) && (T->t = t, T->color = pl->color);
}

void intersp(t_ray *ray, t_sphere *sp, t_solution *T, t_light *l, t_light *am)
{
	t_eq2d sol;
	double t;
	(void)T;
	(void)am;

	t = 0;
	sol.a = dot_prod(ray->direction, ray->direction);
	sol.b = dot_prod(vecsub(ray->origin, sp->center), ray->direction) * 2;
	sol.c = dot_prod(vecsub(ray->origin, sp->center), vecsub(ray->origin, sp->center)) - (sp->diam / 2) * (sp->diam / 2);
	sol.delta = (sol.b * sol.b) - (4 * sol.a * sol.c);
	if(sol.delta > 0)
	{
		sol.t1 = (-sol.b + sqrt(sol.delta)) / 2 * sol.a;
		sol.t2 = (-sol.b - sqrt(sol.delta)) / 2 * sol.a;
		t = (sol.t2 > sol.t1) * sol.t1 + (sol.t1 > sol.t2) * sol.t2;
	}
	else if(sol.delta == 0)
	{
		t = -sol.b / 2 * sol.a;
	}
	t_point p = vecadd(ray->origin, vecxnum(ray->direction, t));
	double dot = dot_prod(normvec(vecsub(p, sp->center)) , normvec(vecsub(l->pos, p)));
	// there is a diffuse : diff = dot * light->col * light->ratio
	// so col  = amb * amb->ratio + col->obj + diffuse
	if(dot > 0)
	{
		// T->color = dot * l->color * l->range +  am->color * am->range + sp->color;
	}
	else{
	// no diffuse so , col = amb * ratio + obj->col	
	}
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
	while(++j <= 800)
	{
		i = -1;
		while(++i <= 900)
		{
			T.t = -1;
			T.color = 0x010101;
			t_sphere *sphere = data->sph;
			t_plane *pl = data->pl;
			t_ray *ray = gc(sizeof(t_ray), 1);
			ray = ft_ray(data->cam, i, j, &mlx, ray);
			// int color =  ray->red << 16 | ray->green << 8 | 0;
			while(sphere)
			{
				intersp(ray, sphere, &T, data->lights, data->amlight);
				sphere = sphere->next;
			}
			while(pl)
			{
				interpl(ray, pl, &T);
				pl = pl->next;
			}
			mlx_pixel_put(mlx.mlx, mlx.win, i, j, T.color);
		}
	}
	// TODO : take the FOV and update the new width and the height * 4;
	// TODO : position of camera to send rays;

	mlx_loop(mlx.mlx);
}
