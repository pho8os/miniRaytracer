/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 06:12:31 by mfouadi           #+#    #+#             */
/*   Updated: 2023/07/19 07:07:26 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_render.h"

typedef struct s_tmp{
// typedef struct s_tmp_objects t_tmp;
	t_sphere	*sphere;
	t_cylinder	*cylinder;
	t_plane		*plane;
} t_tmp;

void	put_pixel_on_image(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
	return ;
}

static void	get_closest_intersection_for_current_pixel(t_utils *utils, t_tmp *objects)
{
	while(1)
	{
		if (objects->sphere)
		{
			intersp(utils, objects->sphere);
			objects->sphere = objects->sphere->next;
		}
		if (objects->cylinder)
		{
			ray_cylinder_intersection(utils, objects->cylinder);
			objects->cylinder = objects->cylinder->next;
		}
		if (objects->plane)
		{
			interpl(&utils->ray, objects->plane, &utils->T);
			objects->plane = objects->plane->next;
		}
		if (!objects->sphere && !objects->cylinder && !objects->plane)
			break;
	}
}

void	find_intersections_with_objects(t_data *data, t_utils *utils)
{
	t_tmp	tmp;

	utils->l = data->lights;
	utils->am = data->amlight;

	tmp.sphere = data->sph;
	tmp.cylinder = data->cyl;
	tmp.plane = data->pl;

	get_closest_intersection_for_current_pixel(utils, &tmp);
	if(utils->T.t > EPS)
	{
		// t_ray tmp_ray = utils->ray;
		// t_color zb = utils->T.color;
		// bool isShadow = false;
		
		// utils->ray.origin = utils->T.inter;
		// utils->ray.direction = normvec(vecsub(utils->l->pos, utils->T.inter));
		// tmp.sphere = data->sph;
		// while(tmp.sphere)
		// {
		// 	if(intersp(utils, tmp.sphere))
		// 	{
		// 		isShadow = true;
		// 		utils->T.color = colormix(zb, vecxnum(utils->am->color, utils->am->range));
		// 		break;
		// 	}
		// 	tmp.sphere = tmp.sphere->next;
		// }
		// utils->ray = tmp_ray;
		// // if (!isShadow)
			// calcul_sphere_light(utils, tmp.sphere);
	}
	return ;
}

/********************************************/

/*


t_inter	plane_normal(t_inter hold, t_objs *obj, t_CamRay *ray)
{
	t_inter	inter;

	inter.t = inter_plane(ray, obj);
	if (((hold.t > inter.t || hold.t == -1) && inter.t > EPS))
	{
		inter.col = obj->col;
		inter.hit = add_vec(ray->origin, mult_vec(ray->dir, inter.t));
		inter.norm = obj->dir;
		if (dot_product(ray->dir, inter.norm) > __DBL_EPSILON__)
			inter.norm = get_normalized(mult_vec(obj->dir, -1));
		hold = inter;
	}
	return (hold);
}

t_inter	cylinder_normal(t_inter hold, t_objs *obj, t_CamRay *ray)
{
	t_inter	inter;
	double	m;
	t_vec	oc;

	inter.t = inter_cylinder(ray, obj);
	if (((hold.t > inter.t || hold.t == -1) && inter.t > EPS))
	{
		inter.col = obj->col;
		inter.hit = add_vec(ray->origin, mult_vec(ray->dir, inter.t));
		oc = get_normalized(obj->dir);
		m = dot_product(ray->dir, mult_vec(oc, inter.t))
			+ dot_product(sub_vec(ray->origin, obj->cen), oc);
		inter.norm = get_normalized(sub_vec(sub_vec(inter.hit, obj->cen),
					mult_vec(oc, m)));
		hold = inter;
	}
	return (hold);
}

double	pick_cy_inter(t_cylinder inf, t_CamRay *ray, t_objs *cy)
{
	inf.t1 = (-inf.b + sqrt(inf.delta)) / (2 * inf.a);
	inf.t2 = (-inf.b - sqrt(inf.delta)) / (2 * inf.a);
	if (inf.t1 < EPS)
		return (-1.0);
	if (inf.t1 > inf.t2)
		inf.t = inf.t2;
	else
		inf.t = inf.t1;

	inf.y0 = dot_product(ray->dir, inf.normal) * inf.t2
		+ dot_product(inf.oc, inf.normal);
	inf.y1 = dot_product(ray->dir, inf.normal) * inf.t1
		+ dot_product(inf.oc, inf.normal);
	if (inf.y0 >= EPS && inf.y0 <= cy->p.y)
		return (inf.t2);
	if (inf.y1 >= EPS && inf.y1 <= cy->p.y)
		return (inf.t1);
	return (-1.0);
}

double	inter_cylinder(t_CamRay *r, t_objs *cy)
{
	t_cylinder	inf;
	double		t;

	inf.normal = get_normalized(cy->dir);
	inf.oc = sub_vec(r->origin, cy->cen);
	inf.a = dot_product(r->dir, r->dir) - (dot_product(r->dir, inf.normal)
			* dot_product(r->dir, inf.normal));
	inf.b = 2 * (dot_product(r->dir, inf.oc) - (dot_product(r->dir, inf.normal)
				* dot_product(inf.oc, inf.normal)));
	inf.c = dot_product(inf.oc, inf.oc)
		- (dot_product(inf.oc, inf.normal) * dot_product(inf.oc, inf.normal))
		- (cy->p.x / 2) * (cy->p.x / 2);
	inf.delta = inf.b * inf.b - 4 * inf.a * inf.c;
	if (inf.delta < EPS)
		return (-1.0);
	t = pick_cy_inter(inf, r, cy);
	return (t);
}
*/