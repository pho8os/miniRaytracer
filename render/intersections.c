/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 06:25:47 by mfouadi           #+#    #+#             */
/*   Updated: 2023/07/19 05:10:00 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_render.h"

void	interpl(t_ray *ray, t_plane *pl, t_solution *T)
{
	double t;

	t = dot_prod(vecsub(pl->point, ray->origin), pl->nvec) / dot_prod(ray->direction, pl->nvec);
	
	if((t < T->t || T->t == -1) && t > EPS)
	{
		T->t = t;
		T->color = pl->color;
		T->inter = vecadd(ray->origin, vecxnum(ray->direction, t));
		T->norm = pl->nvec;
	}
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
		utils->T.inter = vecadd(utils->ray.origin, vecxnum(utils->ray.direction, t));
		utils->T.norm = normvec(vecsub(utils->T.inter, sp->center));
		return(true);
	}
	return(false);
}

/*
*	C is the start cap point of the cylinder
*	V is a unit length vector that determines cylinder's axis
*	r is the cylinder's radius
*	maxm determines cylinder's end cap point 
	a   = D|D - (D|V)^2
	b/2 = D|X - (D|V)*(X|V)
	c   = X|X - (X|V)^2 - r*r
	x	= O - C : O:Ray Origin C: Center of the shape
	m	= D|V*t + X|V

	P - C = D*t + X
	------------------
	Surface normal is:
	------------------
	m = D|V*t + X|V
	N = nrm( P-C-V*m )

*/
bool	ray_cylinder_intersection(t_utils *utils, t_cylinder *cyl)
{
	t_eq2d	sol;
	double	t = 0.0;
	double	r = cyl->diam / 2;
	double m[2] = {0.0, 0.0};
	t_vec	cyl_axis = normvec(cyl->nvec);
	t_vec	x = vecsub(utils->ray.origin, cyl->center);
// printf("%f |%f |%f \n", utils->ray.origin.x, utils->ray.origin.y, utils->ray.origin.z);

	sol.a = dot_prod(utils->ray.direction, utils->ray.direction) - \
		 pow(dot_prod(utils->ray.direction, cyl_axis), 2);
	sol.b = 2 * (dot_prod(utils->ray.direction, x) - (dot_prod(utils->ray.direction, cyl_axis) * \
		dot_prod(x, cyl_axis)));
	sol.c = dot_prod(x,x) - pow(dot_prod(x, cyl_axis), 2) - pow(r, 2);
	sol.delta = (sol.b * sol.b) - (4 * sol.a * sol.c);
	// x = normvec(vecsub(utils->ray.origin, cyl->center));

	if (sol.delta >= EPS)
	{
		sol.t1 = (-sol.b - sqrt(sol.delta)) / (2 * sol.a);
		sol.t2 = (-sol.b + sqrt(sol.delta)) / (2 * sol.a);
		m[0] = (dot_prod(utils->ray.direction, vecxnum(cyl_axis, sol.t1))) + dot_prod(x, cyl_axis);
		m[1] = (dot_prod(utils->ray.direction, vecxnum(cyl_axis, sol.t2))) + dot_prod(x, cyl_axis);
		if (sol.t2 < EPS)
			return (false);
		// else if (sol.t2 < sol.t1)
		// 	t = 
		if (((m[0] >= EPS) &&( m[0] < cyl->height)) )
			t = sol.t1;
		else if (((m[1] >= EPS ) && (m[1] < cyl->height)) )
			t = sol.t2;
	}
	// else if(sol.delta == 0)
	// 	t = -sol.b / 2 * sol.a;
	if ((t < utils->T.t || utils->T.t == -1) && t > EPS)
	{
		utils->T.t = t;
		utils->T.color = cyl->color;
		utils->T.center = cyl->center;

		m[0] = dot_prod(utils->ray.direction, vecxnum(cyl_axis, t)) + dot_prod(x, cyl_axis);
		/*
			------------------
			Surface normal is:
			P - C = D*t + X
			------------------
			m = D|V*t + X|V
			N = nrm( P-C-V*m )
		*/
		t_vec p = vecadd(vecxnum(utils->ray.direction, t), x);
		utils->T.norm = normvec(vecsub(p, vecxnum(cyl_axis, m[0])));
		return(true);
	}
	return (false);
}

// inter.norm = get_normalized(sub_vec(sub_vec(inter.hit, obj->cen), mult_vec(oc, m)));