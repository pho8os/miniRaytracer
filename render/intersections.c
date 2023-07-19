/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 06:25:47 by mfouadi           #+#    #+#             */
/*   Updated: 2023/07/19 11:55:23 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
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