/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cylinder_intersection.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:48:38 by mfouadi           #+#    #+#             */
/*   Updated: 2023/07/22 17:25:06 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"
#include "render.h"
#include "intersection_utils.h"

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
	double	t;
	double	m[2];
	t_vec	cyl_axis;
	t_vec	x;

	t = 0.0;
	cyl_axis = normvec(cyl->nvec);
	x = vecsub(utils->ray.origin, cyl->center);
	sol.a = dot_prod(utils->ray.direction, utils->ray.direction) - \
		pow(dot_prod(utils->ray.direction, cyl_axis), 2);
	sol.b = 2 * (dot_prod(utils->ray.direction, x) \
		- (dot_prod(utils->ray.direction, cyl_axis) * dot_prod(x, cyl_axis)));
	sol.c = dot_prod(x, x) - pow(dot_prod(x, cyl_axis), 2) \
		- pow(cyl->diam / 2, 2);
	sol.delta = (sol.b * sol.b) - (4 * sol.a * sol.c);
	if (sol.delta >= EPS)
	{
		sol.t1 = (-sol.b - sqrt(sol.delta)) / (2 * sol.a);
		sol.t2 = (-sol.b + sqrt(sol.delta)) / (2 * sol.a);
		m[0] = (dot_prod(utils->ray.direction, vecxnum(cyl_axis, sol.t1))) \
			+ dot_prod(x, cyl_axis);
		m[1] = (dot_prod(utils->ray.direction, vecxnum(cyl_axis, sol.t2))) \
			+ dot_prod(x, cyl_axis);
		if (sol.t2 < EPS)
			return (false);
		if (((m[0] >= EPS) && (m[0] < cyl->height)))
			t = sol.t1;
		else if (((m[1] >= EPS) && (m[1] < cyl->height)))
			t = sol.t2;
	}
	if ((t < utils->t.t || utils->t.t == -1) && t > EPS)
	{
		utils->t.t = t;
		utils->t.color = cyl->color;
		utils->t.center = cyl->center;
		m[0] = dot_prod(utils->ray.direction, \
			vecxnum(cyl_axis, t)) + dot_prod(x, cyl_axis);
		utils->t.inter = vecadd(utils->ray.origin, \
			vecxnum(utils->ray.direction, t));
		utils->t.norm = normvec(vecsub(vecadd(\
			vecxnum(utils->ray.direction, t), x), vecxnum(cyl_axis, m[0])));
		return (true);
	}
	return (false);
}
