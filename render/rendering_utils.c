/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 06:12:31 by mfouadi           #+#    #+#             */
/*   Updated: 2023/07/15 04:31:31 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_render.h"

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
	t_sphere    *sphere;

	utils->l = data->lights;
	utils->am = data->amlight;
	sphere = data->sph;

	while(sphere)
	{
		intersp(utils, sphere);
		sphere = sphere->next;
	}
	sphere = data->sph;
	if(utils->T.t > EPS)
	{
		t_ray tmp = utils->ray;
		t_point p = vecadd(utils->ray.origin, vecxnum(utils->ray.direction, utils->T.t));
		utils->ray.origin = p;
		utils->ray.direction = normvec(vecsub(utils->l->pos, p));
		t_color zb= utils->T.color;
		bool isShadow = false;
		while(sphere)
		{
			if(intersp(utils, sphere))
			{
				isShadow = true;
				utils->T.color = colormix(zb, vecxnum(utils->am->color, utils->am->range));
				break;
			}
			sphere = sphere->next;
		}
		utils->ray = tmp;
		if (!isShadow)
			calcul_sphere_light(utils, sphere, utils->T.t);
	}
	return ;
}

