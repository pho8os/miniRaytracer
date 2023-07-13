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



t_color colormix(t_color c1, t_color c2)
{
	t_color c;
	c.x = c1.x * (c2.x / 255);
	c.y = c1.y * (c2.y / 255);
	c.z = c1.z * (c2.z / 255);
	return(c);
}

// t_color ambiant(t_sphere sp, )

void    calcul_sphere_light(t_utils *utils, t_sphere *sp, double t)
{
	(void)sp;
    t_point p = vecadd(utils->ray.origin, vecxnum(utils->ray.direction, t));
	double dot = 0;
	
	dot = dot_prod(normvec(vecsub(p, utils->T.center)) , normvec(vecsub(utils->l->pos, p)));
	if(dot < 0)
		dot = 0;

		t_color diffuse = vecxnum(utils->l->color, dot * utils->l->range);
		t_color ambiant = colormix(utils->T.color, vecxnum(utils->am->color, utils->am->range));
		t_color lights = colormix(utils->T.color, diffuse);
		utils->T.color = coloradd(ambiant, lights);



	// if(dot > 0)
	// 	utils->T.color = coloradd(coefcolor(sp->color, utils->l->color, dot * utils->l->range), coefcolor(sp->color, utils->am->color, utils->am->range)); 
	// else
	// 	utils->T.color = coefcolor(sp->color, utils->am->color, utils->am->range);

	//diffuse bu7du 
	// if(t > EPS && dot < 0)
	// 	utils->T.color = colormix(coefcolor(utils->l->color, dot * utils->l->range), sp->color);
    return ;
}