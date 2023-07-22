/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 08:39:47 by mfouadi           #+#    #+#             */
/*   Updated: 2023/07/22 03:37:04 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "colors.h"
// #include "plane.h"

typedef struct s_tmp{
	t_sphere	*sphere;
	t_cylinder	*cylinder;
	t_plane		*plane;
}	t_tmp;

static void	shadow_or_object_color(t_tmp *tmp, t_utils *utils, t_color zb, \
	bool *is_shadow)
{
	while (1)
	{
		if (tmp->sphere)
		{
			if (intersp(utils, tmp->sphere))
			{
				*is_shadow = true;
				utils->T.color = colormix(zb, vecxnum(utils->am->color, \
					utils->am->range));
				break ;
			}
			tmp->sphere = tmp->sphere->next;
		}
		if (tmp->cylinder)
		{
			if (ray_cylinder_intersection(utils, tmp->cylinder))
			{
				*is_shadow = true;
				utils->T.color = colormix(zb, vecxnum(utils->am->color, \
					utils->am->range));
				break ;
			}
			tmp->cylinder = tmp->cylinder->next;
		}
		if (!tmp->sphere && !tmp->cylinder )
			break ;
	}
	return ;
}

static void	specular_light(t_utils *utils, t_solution *T)
{
	t_color	speclight;
	double	specular;
	double	dot2;

	dot2 = dot_prod(normvec(T->Rnorm), \
		normvec(vecsub(utils->ray.origin, T->inter)));
	if (dot2 <= 0)
	{
		speclight = (t_color){0, 0, 0};
	}
	else
	{
		specular = pow(dot2, 60);
		speclight = vecxnum(utils->l->color, specular);
	}
	T->color = coloradd(T->color, speclight);
	return ;
}

static void	calcul_light_value(t_utils *utils)
{
	t_solution	*solution_data;
	t_color		diffuse;
	t_color		ambiant;
	t_color		lights;
	double		dot;

	solution_data = &(utils->T);
	solution_data->lvec = normvec(vecsub(utils->l->pos, solution_data->inter));
	dot = dot_prod(solution_data->norm, solution_data->lvec);
	if (dot > 0)
	{
		solution_data->Rnorm = normvec(\
			vecsub(vecxnum(solution_data->norm, 2 * dot), solution_data->lvec));
		diffuse = vecxnum(utils->l->color, dot * utils->l->range);
		ambiant = vecxnum(utils->am->color, utils->am->range);
		lights = coloradd(diffuse, ambiant);
		solution_data->color = colormix(solution_data->color, lights);
		specular_light(utils, solution_data);
	}
	else
	{
		ambiant = vecxnum(utils->am->color, utils->am->range);
		solution_data->color = colormix(solution_data->color, ambiant);
	}
    return ;
}

void	check_light_for_current_pixel(t_data *data, t_utils *utils)
{
	bool	is_shadow;
	t_ray	tmp_ray;
	t_color	zb;
	t_tmp	tmp;

	zb = utils->T.color;
	tmp_ray = utils->ray;
	is_shadow = false;
	utils->ray.origin = utils->T.inter;
	utils->ray.direction = normvec(vecsub(utils->l->pos, utils->T.inter));
	tmp.sphere = data->sph;
	tmp.cylinder = data->cyl;
	tmp.plane = data->pl;
	shadow_or_object_color(&tmp, utils, zb, &is_shadow);
	utils->ray = tmp_ray;
	if (!is_shadow)
		calcul_light_value(utils);
	return ;
}
