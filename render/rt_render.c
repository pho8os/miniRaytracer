/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 11:55:32 by absaid            #+#    #+#             */
/*   Updated: 2023/07/10 05:48:14 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_render.h"
#include <mlx.h>


t_color coefcolor(t_color color, double coef)
{
	t_color c;

	c = vecxnum(color, coef);
	(c.x > 255) && (c.x = 255);
	(c.y > 255) && (c.y = 255);
	(c.z > 255) && (c.z = 255);
	return(c);
}

t_color coloradd(t_color c1, t_color c2)
{
	t_color c;

	c = vecadd(c1, c2);
	(c.x > 255) && (c.x = 255);
	(c.y > 255) && (c.y = 255);
	(c.z > 255) && (c.z = 255);
	return(c);
}


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
	(void)l;

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
		((t < T->t || T->t == -1) && t > EPS) && (T->t = t, T->color = sp->color, 0);
	}
	else if(sol.delta == 0)
	{
		t = -sol.b / 2 * sol.a;
		((t < T->t || T->t == -1) && t > EPS) && (T->t = t, T->color = sp->color, 0);
	}
	((t < T->t || T->t == -1) && t > EPS) && (T->t = t, 0);
	t_point p = vecadd(ray->origin, vecxnum(ray->direction, t));
	double dot = 0;
	if(l && t > EPS)
		dot = dot_prod(normvec(vecsub(p, sp->center)) , normvec(vecsub(l->pos, p)));
	// there is a diffuse : diff = dot * light->col * light->ratio
	// so col  = amb * amb->ratio + col->obj + diffuse
	if(dot > 0 && l && am && t > EPS)
		T->color = coloradd(coefcolor(l->color, dot),coloradd(coefcolor(am->color, am->range), sp->color));
		// T->color = dot * l->color * l->range +  am->color * am->range + sp->color
	else if(dot < 0 && am && t > EPS)
		T->color =  sp->color;
	// no diffuse so , col = amb * ratio + obj->col	

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
			T.color = data->amlight->color;
			t_sphere *sphere = data->sph;
			t_plane *pl = data->pl;
			t_ray *ray = gc(sizeof(t_ray), 1);
			ray = ft_ray(data->cam, i, j, &mlx, ray);
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
			int color =  (int)(T.color.x) << 16 |(int)T.color.y << 8 | (int)T.color.z;
			mlx_pixel_put(mlx.mlx, mlx.win, i, j, color);
		}
	}


	mlx_loop(mlx.mlx);
}
