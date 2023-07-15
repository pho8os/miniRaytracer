/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 06:25:47 by mfouadi           #+#    #+#             */
/*   Updated: 2023/07/15 02:21:10 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_render.h"

void	interpl(t_ray *ray, t_plane *pl, t_solution *T)
{
	double t;
	(void)T;

	t = 1 / (dot_prod(ray->direction, pl->nvec)) * (dot_prod(pl->point, pl->nvec) \
        - dot_prod(ray->origin, pl->nvec));
	((t < T->t || T->t == -1) && t > EPS) && (T->t = t, T->color = pl->color, 0);
}

bool   intersp(t_utils *utils, t_sphere *sp)
{
	t_eq2d sol;
	double t;
    
	t = 0;
	sol.a = dot_prod(utils->ray.direction, utils->ray.direction);
	sol.b = dot_prod(vecsub(utils->ray.origin, sp->center), utils->ray.direction) * 2;
	sol.c = dot_prod(vecsub(utils->ray.origin, sp->center), \
        vecsub(utils->ray.origin, sp->center)) - (sp->diam / 2) * (sp->diam / 2);
	sol.delta = (sol.b * sol.b) - (4 * sol.a * sol.c);
	if(sol.delta > 0)
	{
		sol.t1 = (-sol.b + sqrt(sol.delta)) / 2 * sol.a;
		sol.t2 = (-sol.b - sqrt(sol.delta)) / 2 * sol.a;
		t = (sol.t2 > sol.t1) * sol.t1 + (sol.t1 > sol.t2) * sol.t2;
	}
	else if(sol.delta == 0)
		t = -sol.b / 2 * sol.a;
	if ((t < utils->T.t || utils->T.t == -1) && t > EPS)  
	{
		utils->T.t = t;
		utils->T.color = sp->color;
		utils->T.center = sp->center;
		return(true);
	}
	return(false);
}