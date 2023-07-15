/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 11:55:32 by absaid            #+#    #+#             */
/*   Updated: 2023/07/15 04:33:30 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_render.h"

static void	camera_orientation(t_data *data)
{
	data->cam->forvec = normvec(data->cam->forvec);
	data->cam->sidevec = cross_prod((t_vec){0, 1, 0}, data->cam->forvec);
	if(!data->cam->sidevec.x && !data->cam->sidevec.y && !data->cam->sidevec.z)
		data->cam->sidevec = cross_prod((t_vec){1, 0, 0},  data->cam->forvec);
	data->cam->sidevec = normvec(data->cam->sidevec);
	data->cam->upvec = cross_prod(data->cam->sidevec, data->cam->forvec);
	data->cam->upvec = normvec(data->cam->upvec);
	return ;
}

static void	init_new_size(t_mlx	*mlx, t_data *data)
{
	double angle;
	
	camera_orientation(data);
	angle = data->cam->FOV * M_PI / 180;
	mlx->n_width = tan(angle / 2);
	mlx->n_height = HEIGHT * mlx->n_width / WIDTH;
	// printf("NW->%f, NH->%f\n",mlx->n_width, mlx->n_height);
}

void	rt_rendering(t_data *data, t_utils *utils)
{
	int		i;
	int		j;

	j = -1;
	init_new_size(&utils->mlx, data);
	while(++j < HEIGHT)
	{
		i = -1;
		while(++i < WIDTH)
		{
			utils->T.t = -1;
			utils->T.color = data->amlight->color;
			ft_ray(data->cam, i, j, &utils->mlx, &utils->ray);
			find_intersections_with_objects(data, utils);
			int color =  (int)(utils->T.color.x) << 16 |(int)utils->T.color.y << 8 | (int)utils->T.color.z;
			put_pixel_on_image(utils->mlx.img, i, j, color);
		}
	}
	mlx_put_image_to_window(utils->mlx.mlx, utils->mlx.win, \
		utils->mlx.img->img, 0, 0);
	mlx_loop(utils->mlx.mlx);
}

/*
	// there is a diffuse : diff = dot * light->col * light->ratio
	// so col  = amb * amb->ratio + col->obj + diffuse
	// T->color = dot * l->color * l->range +  am->color * am->range + sp->color
	// no diffuse so , col = amb * ratio + obj->col	
*/