/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 08:39:47 by mfouadi           #+#    #+#             */
/*   Updated: 2023/07/15 02:23:14 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_render.h"



// t_color ambiant(t_sphere sp, )

void    calcul_sphere_light(t_utils *utils, t_sphere *sp, double t)
{
	(void)sp;
	t_solution *T;

	T = &(utils->T);
	T->inter = vecadd(utils->ray.origin, vecxnum(utils->ray.direction, t));
	T->norm = normvec(vecsub(T->inter, utils->T.center));
	T->lvec = normvec(vecsub(utils->l->pos, T->inter));
	double dot;
	t_color speclight;
	dot = dot_prod(T->norm, T->lvec);
	if(dot > 0)
	{
		T->Rnorm  = normvec(vecsub(vecxnum(T->norm, 2 * dot), T->lvec)) ;
		t_color diffuse = vecxnum(utils->l->color, dot * utils->l->range);
		double dot2 = dot_prod(normvec(T->Rnorm), normvec(vecsub(utils->ray.origin, T->inter)));
		if(dot2 <= 0)
		{
			speclight = (t_color){0,0,0};
		}
		else 
		{
			double specular = pow(dot2, 200);
			speclight = vecxnum(utils->l->color, specular); 
		}
		t_color ambiant = vecxnum(utils->am->color, utils->am->range);
		t_color lights = coloradd(diffuse, ambiant);
		T->color = colormix(T->color, lights);
		T->color = coloradd(T->color, speclight);
	}
	else
	{
		t_color ambiant = vecxnum(utils->am->color, utils->am->range);
		T->color = colormix(T->color, ambiant);
	}	

    return ;
}