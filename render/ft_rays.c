/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rays.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 01:33:54 by absaid            #+#    #+#             */
/*   Updated: 2023/07/08 21:39:42 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_render.h"

// void map(t_ray *ray, int windowWidth, int windowHeight, int startx, int starty) 
// {


//     ray->red = (((x - startx) * 255)) / ((windowWidth) - startx);
//     ray->green = ((ray.y - starty) * 255) / ((windowHeight) - starty);
    
//     return color;
// }

t_ray *ft_ray(t_cam *cam, int x, int y, t_mlx *mlx, t_ray *ray)
{
	double		x_map;
	double		y_map;
	t_vec up;
	t_vec side;
	double ar; 
	ar = mlx->n_height / mlx->n_width;
	ray->origin = cam->center;
	x_map = (double)(2 * (x + 0.5)) / (double)900 - 1;
	y_map = (double)(2 * (y + 0.5)) / (double)800 - 1;

	up = (vecxnum(cam->upvec, mlx->n_height * y_map));

	side = (vecxnum(cam->sidevec, mlx->n_width * x_map));
	ray->direction = normvec(vecadd(cam->forvec, vecadd(up, side)));

	ray->red = (x_map + 1  ) * 255 / 2;
	ray->green = (y_map + 1  ) * 255 / 2;
	return(ray);
}