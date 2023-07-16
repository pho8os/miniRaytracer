/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 06:25:47 by mfouadi           #+#    #+#             */
/*   Updated: 2023/07/16 10:29:29 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_render.h"

void	interpl(t_ray *ray, t_plane *pl, t_solution *T)
{
	double t;
	(void)T;
	// D|V * P|V 
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

/*
∗ x,y,z coordinates of the center of the cylinder: 50.0,0.0,20.6
∗ 3d normalized vector of axis of cylinder. In range [-1,1] for each x,y,z axis: 0.0,0.0,1.0
∗ the cylinder diameter: 14.2
∗ the cylinder height: 21.42
∗ R,G,B colors in range [0,255]: 10, 0, 255
*/
bool	ray_cylinder_intersection(t_utils *utils, t_cylinder *cyl)
{
	t_eq2d	sol;
	double	t;
	double	r;
	double m[2];
	// O - C : O:Ray Origin C: Center of the shape
	t_vec	x = vecsub(utils->ray.origin, cyl->center); 
	t_vec	C = vecxnum(cyl->nvec, cyl->height / 2);
	t_vec	L = vecxnum(C, cyl->height);
	t_vec	v = normvec(L);
	
	r = cyl->diam / 2;
	t = 0;

	// a   = D|D - (D|V)^2
	sol.a = dot_prod(utils->ray.direction, utils->ray.direction) - \
		 pow(dot_prod(utils->ray.direction, v), 2);
	// b/2 = D|X - (D|V)*(X|V)
	sol.b = 2 * (dot_prod(utils->ray.direction, x) - (dot_prod(utils->ray.direction, v) * \
		dot_prod(x, v)));
	// c = X|X - (X|V)^2 - r*r
	sol.c = dot_prod(x,x) - pow(dot_prod(x, v), 2) - pow(r, 2);

	sol.delta = (sol.b * sol.b) - (4 * sol.a * sol.c);

	if (sol.delta > 0)
	{
		sol.t1 = (-sol.b - sqrt(sol.delta)) / (2 * sol.a);
		sol.t2 = (-sol.b + sqrt(sol.delta)) / (2 * sol.a);
		//    m = D|V*t + X|V
		m[0] = (dot_prod(utils->ray.direction, v) * sol.t1) + dot_prod(x, v);
		m[1] = (dot_prod(utils->ray.direction, v) * sol.t2) + dot_prod(x, v);
		if ((m[0] > 0 && m[0] < cyl->height) )
			t = sol.t1;
		else if ((m[1] > 0 && m[1] < cyl->height) )
			t = sol.t2;
	}
	if ((t < utils->T.t || utils->T.t == -1) && t > EPS)
	{
		utils->T.t = t;
		utils->T.color = cyl->color;
		utils->T.center = cyl->center;
		return(true);
	}
	return (false);
}
