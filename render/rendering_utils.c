/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 06:12:31 by mfouadi           #+#    #+#             */
/*   Updated: 2023/07/15 09:15:13 by mfouadi          ###   ########.fr       */
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
	// printf("img : %p | addr = %p | ln = %d | en = %d | bpp = %d | x = %d | y = %d\n", \
	// 	img, img->addr, img->line_length, img->endian,img->bits_per_pixel,  x, y);
	*(unsigned int*)dst = color;
	return ;
}

void	find_intersections_with_objects(t_data *data, t_utils *utils)
{
	t_tmp	tmp;

	utils->l = data->lights;
	utils->am = data->amlight;

	tmp.sphere = data->sph;
	tmp.cylinder = data->cyl;
	tmp.plane = data->pl;

	while(1)
	{
		if (tmp.sphere)
		{
			intersp(utils, tmp.sphere);
			tmp.sphere = tmp.sphere->next;
		}
		if (tmp.cylinder)
		{
			ray_cylinder_intersection(utils, tmp.cylinder);
			tmp.cylinder = tmp.cylinder->next;
		}
		if (tmp.plane)
		{
			interpl(&utils->ray, tmp.plane, &utils->T);
			tmp.plane = tmp.plane->next;
		}
		if (!tmp.sphere && !tmp.cylinder && !tmp.plane)
			break;
	}
	if(utils->T.t > EPS)
	{
		t_ray tmp_ray = utils->ray;
		t_point p = vecadd(utils->ray.origin, vecxnum(utils->ray.direction, utils->T.t));
		utils->ray.origin = p;
		utils->ray.direction = normvec(vecsub(utils->l->pos, p));
		t_color zb= utils->T.color;
		bool isShadow = false;
		tmp.sphere = data->sph;
		while(tmp.sphere)
		{
			if(intersp(utils, tmp.sphere))
			{
				isShadow = true;
				utils->T.color = colormix(zb, vecxnum(utils->am->color, utils->am->range));
				break;
			}
			tmp.sphere = tmp.sphere->next;
		}
		utils->ray = tmp_ray;
		if (!isShadow)
			calcul_sphere_light(utils, tmp.sphere, utils->T.t);
	}
	return ;
}

