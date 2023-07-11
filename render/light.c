/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 08:39:47 by mfouadi           #+#    #+#             */
/*   Updated: 2023/07/11 08:54:36 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_render.h"

void    calcul_sphere_light(t_utils *utils, t_sphere *sp, double t)
{
    t_point p = vecadd(utils->ray->origin, vecxnum(utils->ray->direction, t));
	double dot = 0;
	if(utils->l && t > EPS)
		dot = dot_prod(normvec(vecsub(p, sp->center)) , normvec(vecsub(utils->l->pos, p)));

	if(dot > 0 && utils->l && utils->am && t > EPS)
		utils->T.color = coloradd(coefcolor(utils->l->color, dot * utils->l->range), \
            coloradd(coefcolor(utils->am->color, utils->am->range), sp->color));
	else if(dot < 0 && utils->am && t > EPS)
		utils->T.color =  sp->color;
    return ;
}