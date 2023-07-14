/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 08:39:47 by mfouadi           #+#    #+#             */
/*   Updated: 2023/07/14 09:58:19 by absaid           ###   ########.fr       */
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
	
	dot = dot_prod(T->norm, T->lvec);
	(dot < 0) && (dot = 0);
	T->Rnorm  = normvec(vecsub(vecxnum(T->norm, 2 * dot), T->lvec)) ;
	t_color diffuse = vecxnum(utils->l->color, dot * utils->l->range);
	double specular = pow(dot_prod(normvec(T->Rnorm), normvec(vecsub(utils->ray.origin, T->inter))), 90);
	t_color speclight = vecxnum(utils->l->color, specular ); 
	t_color ambiant = vecxnum(utils->am->color, utils->am->range);
	t_color lights = coloradd(coloradd(speclight, diffuse), ambiant);
	T->color = coloradd(speclight,T->color);
	T->color = colormix(T->color, lights);
    return ;
}