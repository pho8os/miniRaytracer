/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 06:12:31 by mfouadi           #+#    #+#             */
/*   Updated: 2023/07/19 12:10:12 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "image.h"

typedef struct s_tmp{
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
	// if(utils->T.t > EPS)
	// {
	// 	// t_ray tmp_ray = utils->ray;
	// 	// t_color zb = utils->T.color;
	// 	// bool isShadow = false;
		
	// 	// utils->ray.origin = utils->T.inter;
	// 	// utils->ray.direction = normvec(vecsub(utils->l->pos, utils->T.inter));
	// 	// tmp.sphere = data->sph;
	// 	// while(tmp.sphere)
	// 	// {
	// 	// 	if(intersp(utils, tmp.sphere))
	// 	// 	{
	// 	// 		isShadow = true;
	// 	// 		utils->T.color = colormix(zb, vecxnum(utils->am->color, utils->am->range));
	// 	// 		break;
	// 	// 	}
	// 	// 	tmp.sphere = tmp.sphere->next;
	// 	// }
	// 	// utils->ray = tmp_ray;
	// 	// // if (!isShadow)
	// 		// calcul_light_for_current_pixel(utils, tmp.sphere);
	// }
	return ;
}
